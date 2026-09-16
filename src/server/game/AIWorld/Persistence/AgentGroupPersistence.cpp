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

#include "AgentGroupPersistence.h"
#include "Agent/AgentGroupRegistry.h"
#include "Agent/AgentRegistry.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include <limits>

void AgentGroupPersistence::LoadGroupIdSequence()
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_GROUP_ID_SEQUENCE);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        // Milestone 2.12E1 P2 fix (STATIC review, round 3): fail-closed -
        // _groupIdAllocatorValid stays false, so CreateGroup() refuses to
        // mint anything rather than guessing at _nextGroupId's
        // untrustworthy class-default.
        TC_LOG_ERROR("ai.world", "AgentGroupPersistence: ai_agent_group_id_sequence has no row (expected exactly one, id=1) - "
            "did the 2.12E1 P2 migration run? GroupId allocator left invalid; CreateGroup() will refuse to mint until this is fixed.");
        return;
    }

    uint64 nextGroupId = result->Fetch()[0].GetUInt64();

    // Milestone 2.12E1 P2 fix (STATIC review, round 4): a nonzero row alone
    // is not enough to trust - it must also exceed the highest group_id
    // actually present in ai_agent_groups right now, including a row
    // LoadGroups() itself would later reject (e.g. for an invalid kind) -
    // this query applies no such filter, so it sees exactly what physically
    // exists. Without this check, a sequence value that was never advanced
    // past an existing group's own id would let CreateGroup() mint a
    // "fresh" GroupId that collides with (and, via its own read-back,
    // could be misread as confirming) a real, unrelated existing group.
    CharacterDatabasePreparedStatement* maxStmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_GROUP_MAX_ID);
    PreparedQueryResult maxResult = CharacterDatabase.Query(maxStmt);
    uint64 maxExistingGroupId = maxResult ? maxResult->Fetch()[0].GetUInt64() : 0;

    if (nextGroupId == 0 || nextGroupId <= maxExistingGroupId)
    {
        TC_LOG_ERROR("ai.world", "AgentGroupPersistence: ai_agent_group_id_sequence.next_group_id={} is not a trustworthy high-water mark "
            "(must be nonzero and greater than MAX(ai_agent_groups.group_id)={}) - GroupId allocator left invalid; CreateGroup() will refuse to mint until this is fixed.",
            nextGroupId, maxExistingGroupId);
        return;
    }

    _nextGroupId = nextGroupId;
    _groupIdAllocatorValid = true;

    TC_LOG_INFO("ai.world", "AI persistence loaded group id sequence, next group id={}", _nextGroupId);
}

uint32 AgentGroupPersistence::LoadGroups(AgentGroupRegistry& registry)
{
    uint32 loaded = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_GROUPS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI persistence loaded 0 agent groups");
        return 0;
    }

    do
    {
        Field* fields = result->Fetch();

        AgentGroupRecord record;
        record.Id = GroupId{ fields[0].GetUInt64() };

        // Hardening (STATIC review P3 fix): kind used to be a blind cast -
        // AgentGroupKind(fields[1].GetUInt8()) would silently accept any
        // uint8 the column happened to hold, including values with no
        // named enumerator, and ToString() would just print "UNKNOWN"
        // forever after. Fail-closed instead, the same discipline
        // AgentPersistence::LoadAgents() already holds ai_agents to: an
        // explicit switch over only the values AgentGroupKind actually
        // declares, everything else rejected (logged, skipped) rather than
        // silently reinterpreted or degraded.
        uint8 rawKind = fields[1].GetUInt8();
        switch (rawKind)
        {
            case uint8(AgentGroupKind::Loose):
                record.Kind = AgentGroupKind::Loose;
                break;
            case uint8(AgentGroupKind::Stable):
                record.Kind = AgentGroupKind::Stable;
                break;
            default:
                TC_LOG_ERROR("ai.world",
                    "AgentGroupPersistence: refusing to load group id={} with invalid kind={} (not LOOSE(0)/STABLE(1)), skipping",
                    record.Id.Value, rawKind);
                continue;
        }

        record.TerritoryMapId = fields[2].GetUInt32();
        record.TerritoryX = fields[3].GetFloat();
        record.TerritoryY = fields[4].GetFloat();
        record.TerritoryZ = fields[5].GetFloat();
        record.Resources = fields[6].GetFloat();
        record.Version = fields[7].GetUInt64();

        // Milestone 2.12E4C2 P2 fix (STATIC review): same fail-closed
        // discipline as kind above, not a blind cast - an unrecognized
        // profile_id is refused (logged, skipped) rather than silently
        // reinterpreted. Every row from before this column existed reads
        // back 0 (Invalid) via its own DEFAULT - the correct, fail-closed
        // reading for "no automatic formation profile is known to have
        // created this group" (see AgentGroupRecord::ProfileId).
        uint8 rawProfileId = fields[8].GetUInt8();
        switch (rawProfileId)
        {
            case uint8(CoalitionFormationProfileId::Invalid):
                record.ProfileId = CoalitionFormationProfileId::Invalid;
                break;
            case uint8(CoalitionFormationProfileId::WolfLoose):
                record.ProfileId = CoalitionFormationProfileId::WolfLoose;
                break;
            // Milestone 2.12G1: the second real profile - without this
            // case, every DefiasLoose group would be silently refused/
            // skipped here on the very next restart (a real correctness
            // landmine flagged during this milestone's own research, not
            // a hypothetical).
            case uint8(CoalitionFormationProfileId::DefiasLoose):
                record.ProfileId = CoalitionFormationProfileId::DefiasLoose;
                break;
            default:
                TC_LOG_ERROR("ai.world",
                    "AgentGroupPersistence: refusing to load group id={} with invalid profile_id={} (not INVALID(0)/WOLF_LOOSE(1)/DEFIAS_LOOSE(2)), skipping",
                    record.Id.Value, rawProfileId);
                continue;
        }

        if (!registry.Add(record))
            continue;

        TC_LOG_INFO("ai.world", "AI agent group loaded id={} kind={} profile={} territoryMap={} resources={:.4f} version={}",
            record.Id.Value, ToString(record.Kind), ToString(record.ProfileId), record.TerritoryMapId, record.Resources, record.Version);

        ++loaded;
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI persistence loaded {} agent groups", loaded);
    return loaded;
}

uint32 AgentGroupPersistence::LoadGroupMembers(AgentGroupRegistry& groupRegistry, AgentRegistry const& agentRegistry)
{
    uint32 loaded = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_GROUP_MEMBERS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI persistence loaded 0 agent group members");
        return 0;
    }

    do
    {
        Field* fields = result->Fetch();

        GroupId groupId{ fields[0].GetUInt64() };
        AgentId memberId{ fields[1].GetUInt64() };
        uint64 joinedAtMs = fields[2].GetUInt64();

        // No FK to ai_agent_groups - an orphaned group_id is logged and
        // skipped, the same tolerance ai_long_term_memories' own orphan
        // handling already has. Never fatal to the rest of this load.
        AgentGroupRecord* group = groupRegistry.Find(groupId);
        if (!group)
        {
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: ai_agent_group_members row for group_id={} member_agent_id={} references an unregistered group, skipping",
                groupId.Value, memberId.Value);
            continue;
        }

        // Milestone 2.12D P2 fix (STATIC review): unlike the superseded
        // CreatureGroup model, a member is never a legitimate forward
        // reference here - it must already be a real, independent
        // AgentRecord by the time its group's membership loads (create/
        // register the individual agent first, then the membership edge
        // that names it, never the other way around).
        AgentRecord const* member = agentRegistry.Find(memberId);
        if (!member)
        {
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: ai_agent_group_members row for group_id={} member_agent_id={} references an unregistered agent, skipping",
                groupId.Value, memberId.Value);
            continue;
        }

        // AI WorldFactionId invariant (data/elwynn/factions/README.md):
        // fail-closed against a corrupted/stale DB, the same "never trust
        // a persisted row to still describe a valid coalition" discipline
        // AgentPersistence::LoadAgents()' own AgentId == SpawnId check
        // already applies. group->ProfileId names a fixed, non-configurable
        // WorldFaction requirement (RequiredWorldFactionFor(),
        // CoalitionFormationProfileId.h) - a row whose own member's
        // AgentRecord::WorldFaction disagrees with it (e.g. a stale row
        // left over from before AIWorld.WolfGroupCreatureEntry was
        // corrected, or hand-edited DB content) never re-enters the
        // runtime as if it were still a valid coalition. A manual/admin
        // group (ProfileId == Invalid) has no such requirement -
        // RequiredWorldFactionFor() returns nullopt for it, and every
        // membership loads unconditionally, same as before this check
        // existed.
        std::optional<WorldFactionId> requiredWorldFaction = RequiredWorldFactionFor(group->ProfileId);
        if (requiredWorldFaction && member->WorldFaction != *requiredWorldFaction)
        {
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: ai_agent_group_members row for group_id={} member_agent_id={} worldFactionId={} violates its group's profile={} (requires worldFactionId={}), skipping - not re-added to the runtime coalition",
                groupId.Value, memberId.Value, member->WorldFaction.Value, ToString(group->ProfileId), requiredWorldFaction->Value);
            continue;
        }

        // 2.12F2 P3 fix (STATIC review): through AddMember() now, not
        // pushed onto group->Members directly - see that method's own
        // comment for why this is the one place a member is ever added, so
        // AgentGroupRegistry's own reverse membership index never drifts
        // out of sync with the forward Members list it mirrors. Known to
        // succeed here (group was already confirmed to exist just above,
        // and this load is single-threaded, so nothing else can have
        // removed it in between).
        AgentGroupMembership membership;
        membership.Member = memberId;
        membership.JoinedAtMs = joinedAtMs;
        groupRegistry.AddMember(groupId, membership);

        TC_LOG_INFO("ai.world", "AI agent group member loaded group={} member={} joinedAtMs={}", groupId.Value, memberId.Value, joinedAtMs);

        ++loaded;
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI persistence loaded {} agent group members", loaded);
    return loaded;
}

void AgentGroupPersistence::SaveGroupState(GroupId id, AgentGroupRecord& record)
{
    // Same reasoning as AgentPersistence::SaveEconomyState()'s own P3 fix:
    // unconditional, first thing, regardless of what the caller already
    // did.
    ++record.Version;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AI_AGENT_GROUP);
    stmt->setUInt8(0, uint8(record.Kind));
    stmt->setUInt32(1, record.TerritoryMapId);
    stmt->setFloat(2, record.TerritoryX);
    stmt->setFloat(3, record.TerritoryY);
    stmt->setFloat(4, record.TerritoryZ);
    stmt->setFloat(5, record.Resources);
    stmt->setUInt64(6, record.Version);
    stmt->setUInt8(7, uint8(record.ProfileId));
    stmt->setUInt64(8, id.Value);

    // Bound again for the statement's own "AND version < ?" guard - see
    // AgentGroupRecord::Version and CHAR_UPD_AI_AGENT_GROUP's own comment
    // for why.
    stmt->setUInt64(9, record.Version);

    // Fire-and-forget by design - see the class comment. The world update
    // thread must never wait on this.
    CharacterDatabase.Execute(stmt);
}

std::optional<TransactionCallback> AgentGroupPersistence::CreateGroupAsync(AgentGroupKind kind, uint32 territoryMapId,
    float territoryX, float territoryY, float territoryZ, float resources, CoalitionFormationProfileId profileId,
    std::function<void(bool, GroupId)> onComplete)
{
    // Fail-closed - never mint against an allocator LoadGroupIdSequence()
    // could not confirm.
    if (!_groupIdAllocatorValid)
    {
        TC_LOG_ERROR("ai.world", "AgentGroupPersistence::CreateGroupAsync: refusing to mint a GroupId - the allocator is not valid "
            "(LoadGroupIdSequence() never confirmed ai_agent_group_id_sequence), group was not created");
        onComplete(false, GroupId{});
        return std::nullopt;
    }

    // 2.12E2 hardening: refuse outright rather than silently wrapping to 0
    // (a value LoadGroupIdSequence() would itself reject as untrustworthy
    // on the next restart anyway).
    if (_nextGroupId == std::numeric_limits<uint64>::max())
    {
        TC_LOG_ERROR("ai.world", "AgentGroupPersistence::CreateGroupAsync: refusing to mint a GroupId - the allocator has reached "
            "UINT64_MAX, group was not created");
        onComplete(false, GroupId{});
        return std::nullopt;
    }

    // Advanced synchronously, immediately, before the transaction below is
    // even submitted - see this method's own header comment for why that
    // (rather than advancing only after a confirmed commit) is what keeps
    // two CreateGroupAsync() calls in flight at once from ever computing
    // the same id.
    GroupId newId{ _nextGroupId };
    uint64 reservedNext = _nextGroupId + 1;
    _nextGroupId = reservedNext;

    // One transaction, both statements - the sequence reservation and the
    // group row INSERT either both land or neither does.
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    // 2.12E2 P2 fix (STATIC review): CHAR_UPD_AI_AGENT_GROUP_ID_SEQUENCE
    // itself is GREATEST(next_group_id, ?), not a plain SET - see its own
    // PrepareStatement() comment for why a plain SET is not safe with more
    // than one CharacterDatabase async worker.
    CharacterDatabasePreparedStatement* seqStmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AI_AGENT_GROUP_ID_SEQUENCE);
    seqStmt->setUInt64(0, reservedNext);
    trans->Append(seqStmt);

    CharacterDatabasePreparedStatement* insertStmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AI_AGENT_GROUP);
    insertStmt->setUInt64(0, newId.Value);
    insertStmt->setUInt8(1, uint8(kind));
    insertStmt->setUInt32(2, territoryMapId);
    insertStmt->setFloat(3, territoryX);
    insertStmt->setFloat(4, territoryY);
    insertStmt->setFloat(5, territoryZ);
    insertStmt->setFloat(6, resources);
    insertStmt->setUInt8(7, uint8(profileId));
    trans->Append(insertStmt);

    TransactionCallback callback = CharacterDatabase.AsyncCommitTransaction(trans);
    callback.AfterComplete([newId, onComplete = std::move(onComplete)](bool success)
    {
        if (!success)
            // 2.12E2 P3 fix (STATIC review): "not minted again this
            // process" only, not "never reused" - see CreateGroupAsync()'s
            // own header comment for why a restart before some later
            // successful create can still re-mint this exact id, safely.
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: async CreateGroup transaction for group id={} failed and was rolled back "
                "(not minted again this process, but may be re-minted after a restart - see CreateGroupAsync()'s own comment)", newId.Value);

        onComplete(success, success ? newId : GroupId{});
    });

    return callback;
}

TransactionCallback AgentGroupPersistence::AddGroupMemberAsync(GroupId groupId, AgentId memberId, uint64 joinedAtMs, std::function<void(bool)> onComplete)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AI_AGENT_GROUP_MEMBER);
    stmt->setUInt64(0, groupId.Value);
    stmt->setUInt64(1, memberId.Value);
    stmt->setUInt64(2, joinedAtMs);
    trans->Append(stmt);

    TransactionCallback callback = CharacterDatabase.AsyncCommitTransaction(trans);
    callback.AfterComplete([groupId, memberId, onComplete = std::move(onComplete)](bool success)
    {
        if (!success)
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: async AddGroupMember transaction for group_id={} member_agent_id={} failed",
                groupId.Value, memberId.Value);

        onComplete(success);
    });

    return callback;
}

TransactionCallback AgentGroupPersistence::RemoveGroupMemberAsync(GroupId groupId, AgentId memberId, std::function<void(bool)> onComplete)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AI_AGENT_GROUP_MEMBER);
    stmt->setUInt64(0, groupId.Value);
    stmt->setUInt64(1, memberId.Value);
    trans->Append(stmt);

    TransactionCallback callback = CharacterDatabase.AsyncCommitTransaction(trans);
    callback.AfterComplete([groupId, memberId, onComplete = std::move(onComplete)](bool success)
    {
        if (!success)
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: async RemoveGroupMember transaction for group_id={} member_agent_id={} failed",
                groupId.Value, memberId.Value);

        onComplete(success);
    });

    return callback;
}

TransactionCallback AgentGroupPersistence::DeleteGroupAsync(GroupId groupId, std::function<void(bool)> onComplete)
{
    // Membership rows first, group row second - readability only (the
    // transaction already makes both atomic regardless of statement
    // order).
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* membersStmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AI_AGENT_GROUP_MEMBERS_BY_GROUP);
    membersStmt->setUInt64(0, groupId.Value);
    trans->Append(membersStmt);

    CharacterDatabasePreparedStatement* groupStmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AI_AGENT_GROUP);
    groupStmt->setUInt64(0, groupId.Value);
    trans->Append(groupStmt);

    TransactionCallback callback = CharacterDatabase.AsyncCommitTransaction(trans);
    callback.AfterComplete([groupId, onComplete = std::move(onComplete)](bool success)
    {
        if (!success)
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: async DeleteGroup transaction for group id={} failed", groupId.Value);

        onComplete(success);
    });

    return callback;
}

TransactionCallback AgentGroupPersistence::AdoptGroupProfileAsync(GroupId groupId, CoalitionFormationProfileId profileId, std::function<void(bool)> onComplete)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AI_AGENT_GROUP_PROFILE_ID);
    stmt->setUInt8(0, uint8(profileId));
    stmt->setUInt64(1, groupId.Value);
    trans->Append(stmt);

    TransactionCallback callback = CharacterDatabase.AsyncCommitTransaction(trans);
    callback.AfterComplete([groupId, profileId, onComplete = std::move(onComplete)](bool success)
    {
        if (!success)
            TC_LOG_ERROR("ai.world", "AgentGroupPersistence: async AdoptGroupProfile transaction for group_id={} profile_id={} failed",
                groupId.Value, uint8(profileId));

        onComplete(success);
    });

    return callback;
}
