/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "AgentGroupLifecycleSystem.h"
#include "AgentGroupMembership.h"
#include "AgentGroupRecord.h"
#include "AgentGroupRegistry.h"
#include "AgentRegistry.h"
#include "CoalitionFormationProfileKind.h"
#include "Log.h"
#include "Persistence/AgentGroupPersistence.h"
#include <algorithm>

void AgentGroupLifecycleSystem::RequestCreateGroup(AgentGroupKind kind, uint32 territoryMapId,
    float territoryX, float territoryY, float territoryZ, float resources, CoalitionFormationProfileId profileId,
    AgentGroupRegistry& groupRegistry, AgentGroupPersistence& persistence, TransactionCallbackProcessor& pending,
    std::function<void(std::optional<GroupId>)> onComplete)
{
    // Milestone 2.12E4C2 P3 hardening (STATIC review): the authoritative
    // mutation boundary for AgentGroupRecord::ProfileId - Invalid is
    // always allowed (a manual/admin-authorized create names no automatic
    // profile at all), but a non-Invalid profileId must both be a
    // recognized value AND be compatible with kind (see
    // GetCoalitionProfileKind()) - refusing here, before persistence is
    // ever touched, is what stops a caller from persisting a nonsensical
    // combination like CoalitionFormationProfileId::WolfLoose on an
    // AgentGroupKind::Stable group.
    if (profileId != CoalitionFormationProfileId::Invalid)
    {
        std::optional<AgentGroupKind> expectedKind = GetCoalitionProfileKind(profileId);
        if (!expectedKind || *expectedKind != kind)
        {
            TC_LOG_ERROR("ai.world", "AgentGroupLifecycleSystem::RequestCreateGroup: profile={} is not compatible with kind={}, refusing to create",
                ToString(profileId), ToString(kind));
            onComplete(std::nullopt);
            return;
        }
    }

    std::optional<TransactionCallback> callback = persistence.CreateGroupAsync(kind, territoryMapId, territoryX, territoryY, territoryZ, resources, profileId,
        [&groupRegistry, kind, territoryMapId, territoryX, territoryY, territoryZ, resources, profileId, onComplete](bool success, GroupId newId)
        {
            if (!success)
            {
                onComplete(std::nullopt);
                return;
            }

            AgentGroupRecord record;
            record.Id = newId;
            record.Kind = kind;
            record.ProfileId = profileId;
            record.TerritoryMapId = territoryMapId;
            record.TerritoryX = territoryX;
            record.TerritoryY = territoryY;
            record.TerritoryZ = territoryZ;
            record.Resources = resources;
            record.Version = 0;

            if (!groupRegistry.Add(record))
            {
                // Should be unreachable - persistence just minted newId
                // fresh from its own counter, which only ever increases,
                // so a collision here would mean that counter and
                // groupRegistry have drifted out of sync with each other.
                // Defense in depth, not the primary guarantee - logged
                // loudly because it would indicate a real bug elsewhere.
                TC_LOG_ERROR("ai.world", "AgentGroupLifecycleSystem::RequestCreateGroup: freshly-created group id={} was already registered in groupRegistry - this should be unreachable",
                    newId.Value);
                onComplete(std::nullopt);
                return;
            }

            TC_LOG_INFO("ai.world", "AI agent group created id={} kind={} profile={} territoryMap={} resources={:.4f}",
                newId.Value, ToString(kind), ToString(profileId), territoryMapId, resources);

            onComplete(newId);
        });

    // std::nullopt means persistence already rejected this synchronously
    // and already invoked the wrapped callback above (with success=false)
    // - nothing left to enqueue.
    if (callback)
        pending.AddCallback(std::move(*callback));
}

void AgentGroupLifecycleSystem::RequestJoinGroup(GroupId groupId, AgentId memberId, uint64 joinedAtMs,
    AgentGroupRegistry& groupRegistry, AgentRegistry const& agentRegistry, AgentGroupPersistence& persistence,
    TransactionCallbackProcessor& pending, std::function<void(bool)> onComplete)
{
    AgentGroupRecord* group = groupRegistry.Find(groupId);
    if (!group)
    {
        TC_LOG_ERROR("ai.world", "AgentGroupLifecycleSystem::RequestJoinGroup: group id={} does not exist, refusing to join member id={}",
            groupId.Value, memberId.Value);
        onComplete(false);
        return;
    }

    // 2.12E2 P2 fix (STATIC review): rejects synchronously, before ever
    // touching the DB, if a Join/Leave/Dissolve is already in flight for
    // this GroupId - see this class's own header comment for the
    // DissolveGroup-then-JoinGroup orphan-membership race this closes.
    if (_pendingGroupOperations.contains(groupId.Value))
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestJoinGroup: group id={} already has a lifecycle operation in flight, refusing to join member id={}",
            groupId.Value, memberId.Value);
        onComplete(false);
        return;
    }

    // Read-only - RequestJoinGroup() never mutates an individual
    // AgentRecord, only confirms one already exists.
    AgentRecord const* joiningMember = agentRegistry.Find(memberId);
    if (!joiningMember)
    {
        TC_LOG_ERROR("ai.world", "AgentGroupLifecycleSystem::RequestJoinGroup: agent id={} does not exist, refusing to add it to group id={}",
            memberId.Value, groupId.Value);
        onComplete(false);
        return;
    }

    bool alreadyMember = std::any_of(group->Members.begin(), group->Members.end(),
        [memberId](AgentGroupMembership const& membership) { return membership.Member == memberId; });

    if (alreadyMember)
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestJoinGroup: agent id={} is already a member of group id={}, ignoring duplicate join",
            memberId.Value, groupId.Value);
        onComplete(false);
        return;
    }

    // AI WorldFactionId invariant (data/elwynn/factions/README.md): a group
    // has no WorldFaction field of its own (see AgentGroupRecord.h) -
    // deliberately derived from its own current Members instead, the same
    // "no separate, potentially-drifting source of truth" reasoning that
    // struct's own comment already applies to Hunger/member count. An empty
    // group has nothing to compare against yet, so its first joiner
    // implicitly sets the group's own affiliation; every joiner after that
    // must match whichever WorldFaction any existing member already
    // carries (they are all guaranteed consistent, since every past join
    // already passed this same check) - a cross-faction join is refused
    // synchronously here, before any DB write, the same "validate before
    // touching the DB" discipline this method already applies to every
    // other precondition above.
    for (AgentGroupMembership const& membership : group->Members)
    {
        AgentRecord const* existingMember = agentRegistry.Find(membership.Member);
        if (!existingMember)
            continue;

        if (existingMember->WorldFaction != joiningMember->WorldFaction)
        {
            TC_LOG_ERROR("ai.world", "AgentGroupLifecycleSystem::RequestJoinGroup: agent id={} worldFactionId={} cannot join group id={} - conflicts with existing member id={} worldFactionId={}",
                memberId.Value, joiningMember->WorldFaction.Value, groupId.Value, existingMember->Id.Value, existingMember->WorldFaction.Value);
            onComplete(false);
            return;
        }

        break;
    }

    _pendingGroupOperations.insert(groupId.Value);

    TransactionCallback callback = persistence.AddGroupMemberAsync(groupId, memberId, joinedAtMs,
        [this, &groupRegistry, groupId, memberId, joinedAtMs, onComplete](bool success)
        {
            _pendingGroupOperations.erase(groupId.Value);

            if (!success)
            {
                onComplete(false);
                return;
            }

            // 2.12F2 P3 fix (STATIC review): AddMember() re-resolves
            // groupId internally and returns false if it no longer exists -
            // still checked explicitly here (rather than trusting a bare
            // true/false to distinguish "no longer exists" from some other
            // failure) so the log line below can say which one happened.
            // The pending-operation guard above means the group cannot have
            // been dissolved by another Request* call while this join was
            // in flight, but this is kept as defense in depth regardless -
            // see this class's own header comment on why a completion
            // never trusts request-time validity.
            AgentGroupMembership membership;
            membership.Member = memberId;
            membership.JoinedAtMs = joinedAtMs;

            if (!groupRegistry.AddMember(groupId, membership))
            {
                TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestJoinGroup: group id={} no longer exists by the time the async join for member id={} completed",
                    groupId.Value, memberId.Value);
                onComplete(false);
                return;
            }

            TC_LOG_INFO("ai.world", "AI agent group join group={} member={} joinedAtMs={}", groupId.Value, memberId.Value, joinedAtMs);
            onComplete(true);
        });

    pending.AddCallback(std::move(callback));
}

void AgentGroupLifecycleSystem::RequestLeaveGroup(GroupId groupId, AgentId memberId,
    AgentGroupRegistry& groupRegistry, AgentGroupPersistence& persistence,
    TransactionCallbackProcessor& pending, std::function<void(bool)> onComplete)
{
    AgentGroupRecord* group = groupRegistry.Find(groupId);
    if (!group)
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestLeaveGroup: group id={} does not exist, nothing to do for member id={}",
            groupId.Value, memberId.Value);
        onComplete(false);
        return;
    }

    // 2.12E2 P2 fix (STATIC review): see RequestJoinGroup()'s own comment.
    if (_pendingGroupOperations.contains(groupId.Value))
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestLeaveGroup: group id={} already has a lifecycle operation in flight, nothing to do for member id={}",
            groupId.Value, memberId.Value);
        onComplete(false);
        return;
    }

    auto it = std::find_if(group->Members.begin(), group->Members.end(),
        [memberId](AgentGroupMembership const& membership) { return membership.Member == memberId; });

    if (it == group->Members.end())
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestLeaveGroup: agent id={} is not a member of group id={}, nothing to do",
            memberId.Value, groupId.Value);
        onComplete(false);
        return;
    }

    _pendingGroupOperations.insert(groupId.Value);

    TransactionCallback callback = persistence.RemoveGroupMemberAsync(groupId, memberId,
        [this, &groupRegistry, groupId, memberId, onComplete](bool success)
        {
            _pendingGroupOperations.erase(groupId.Value);

            if (!success)
            {
                onComplete(false);
                return;
            }

            // 2.12F2 P3 fix (STATIC review): RemoveMember() re-resolves
            // groupId internally and re-finds memberId within its own
            // current Members - the pending-operation guard above means
            // the group cannot have been dissolved by another Request*
            // call while this leave was in flight, but this is kept as
            // defense in depth regardless, and even a still-live
            // AgentGroupRecord::Members has moved on since the request-time
            // find_if() ran. Its own false return covers BOTH "group no
            // longer exists" and "memberId already not a member" - either
            // way the post-condition this call promises ("not a member")
            // already holds, so this is still a success, just nothing left
            // to erase; not distinguished further, the same as before.
            if (!groupRegistry.RemoveMember(groupId, memberId))
                TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestLeaveGroup: group id={} no longer exists or member id={} was already not a member by the time the async leave completed",
                    groupId.Value, memberId.Value);
            else
                TC_LOG_INFO("ai.world", "AI agent group leave group={} member={}", groupId.Value, memberId.Value);

            onComplete(true);
        });

    pending.AddCallback(std::move(callback));
}

void AgentGroupLifecycleSystem::RequestDissolveGroup(GroupId groupId,
    AgentGroupRegistry& groupRegistry, AgentGroupPersistence& persistence,
    TransactionCallbackProcessor& pending, std::function<void(bool)> onComplete)
{
    AgentGroupRecord* group = groupRegistry.Find(groupId);
    if (!group)
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestDissolveGroup: group id={} does not exist, nothing to do", groupId.Value);
        onComplete(false);
        return;
    }

    // 2.12E2 P2 fix (STATIC review): see RequestJoinGroup()'s own comment.
    // This is the specific check that closes the original race the review
    // found: a Join/Leave submitted for a group whose dissolve is already
    // in flight is now rejected synchronously by that side's own check
    // above, instead of racing the dissolve's DELETE to commit second.
    if (_pendingGroupOperations.contains(groupId.Value))
    {
        TC_LOG_WARN("ai.world", "AgentGroupLifecycleSystem::RequestDissolveGroup: group id={} already has a lifecycle operation in flight, nothing to do", groupId.Value);
        onComplete(false);
        return;
    }

    uint32 formerMemberCount = uint32(group->Members.size());

    _pendingGroupOperations.insert(groupId.Value);

    TransactionCallback callback = persistence.DeleteGroupAsync(groupId,
        [this, &groupRegistry, groupId, formerMemberCount, onComplete](bool success)
        {
            _pendingGroupOperations.erase(groupId.Value);

            if (!success)
            {
                onComplete(false);
                return;
            }

            // Remove() is already safe/idempotent against groupId no
            // longer being present (returns false, harmless) - no
            // re-resolution needed the way Join/Leave's completions do.
            groupRegistry.Remove(groupId);

            TC_LOG_INFO("ai.world", "AI agent group dissolved group={} formerMemberCount={}", groupId.Value, formerMemberCount);
            onComplete(true);
        });

    pending.AddCallback(std::move(callback));
}

bool AgentGroupLifecycleSystem::HasPendingOperation(GroupId groupId) const
{
    return _pendingGroupOperations.contains(groupId.Value);
}
