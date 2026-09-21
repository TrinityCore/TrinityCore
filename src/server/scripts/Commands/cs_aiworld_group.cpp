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

/* ScriptData
Name: aiworld_group_commandscript
%Complete: 100
Comment: .aiworld group status/join/leave - GM/debug interface for the 3.4
    runtime coalition gate (AIWorld_Current_Roadmap.md, "Coalition pravidla
    uvnitr frakci"). Every subcommand acts on the GM's own CURRENT TARGET
    (a live Creature, via handler->getSelectedCreature()) - there is no
    self/target-player variant, since a coalition member is always a
    Creature-bound AgentRecord, never the GM's own character. Resolves the
    target to its AgentId via AIWorldMgr::FindAgentIdForCreature()
    (AgentRegistry::FindBySpawn() under the hood) - fails closed (reports,
    returns) if the target has no registered AgentRecord at all, rather
    than guessing.

    join/leave are the first EXTERNAL callers of AIWorldMgr::
    RequestManualJoinGroup()/RequestManualLeaveGroup()
    (AgentGroupOperationSource::Manual, baked in - see that method's own
    comment), themselves thin wrappers around the already-existing,
    policy-gated RequestJoinGroupWithPolicy()/RequestLeaveGroupWithPolicy().
    Nothing here bypasses AgentGroupPolicySystem::CanJoin()/CanLeave() or
    the WorldFaction gate AgentGroupLifecycleSystem::RequestJoinGroup()
    itself enforces (see that method's own comment) - this command exists
    PRECISELY to let an operator drive both of those deliberately and
    observe the result, since nothing else in this codebase can trigger a
    cross-faction join attempt on demand (automatic
    CoalitionFormationSystem::Propose() pre-filters candidates by
    WorldFaction before ever proposing one, so a rejection there is never
    an observable event).

    join/leave genuinely cross an async gap (AIWorldMgr's own internal
    _groupLifecyclePending/AgentGroupPersistence write, resolved on a later
    AIWorldMgr::Update() tick - unlike cs_aiworld_faction.cpp's own async
    calls, this is NOT queued through the command issuer's own WorldSession::
    GetQueryProcessor(), so nothing ties its lifetime to that session
    surviving). The completion lambda therefore captures only the issuer's
    accountId (a plain uint32) and re-resolves the session via
    sWorld->FindSession() at callback time, exactly like
    PlayerWorldFactionReactionBridge's own SyncLivePlayer() re-fetches
    session->GetPlayer() rather than capturing a raw pointer across a gap -
    the GM may have logged out by the time this fires; FindSession() then
    simply returns null and the notification is skipped (still visible in
    the ai.world log either way). Never captures ChatHandler* or
    WorldSession* directly. HandleAIWorldGroupStatusCommand has no such gap -
    every lookup it uses (FindAgentIdForCreature/GetAgentWorldFaction/
    GetGroupsOfAgent/DescribeGroup) is a synchronous, in-memory read, so it
    replies via the handler directly, within its own call frame.
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AIWorldMgr.h"
#include "Agent/AgentGroupPolicyDecision.h"
#include "Agent/AgentId.h"
#include "Agent/GroupId.h"
#include "Chat.h"
#include "Creature.h"
#include "Faction/WorldFactionId.h"
#include "StringFormat.h"
#include "World.h"
#include "WorldSession.h"
#include <string>

using namespace Trinity::ChatCommands;

namespace
{
    // Mirrors cs_aiworld_faction.cpp's own WorldFactionDisplayName() - kept
    // as its own small copy rather than a shared header, the same
    // "deliberately narrow, just enough for this command's own feedback"
    // scope that one documents for itself.
    std::string WorldFactionDisplayName(WorldFactionId faction)
    {
        if (!faction)
            return "Unaffiliated";
        if (faction == WorldFactions::StormwindAlliance)
            return "Stormwind Alliance";
        if (faction == WorldFactions::DefiasBrotherhood)
            return "Defias Brotherhood";
        if (faction == WorldFactions::RiverpawGnolls)
            return "Riverpaw Gnolls";
        if (faction == WorldFactions::ElwynnKobolds)
            return "Elwynn Kobolds";
        if (faction == WorldFactions::ElwynnMurlocs)
            return "Elwynn Murlocs";
        if (faction == WorldFactions::ElwynnWolves)
            return "Elwynn Wolves";
        return "UNKNOWN(" + std::to_string(faction.Value) + ")";
    }

    // Shared by every subcommand below - fails closed (reports via
    // handler, returns AgentId{}) if the GM has no creature currently
    // targeted, or that creature has no registered AgentRecord at all.
    // Always called synchronously at the top of its caller's own handler
    // function, before any async gap - safe to use handler directly.
    AgentId ResolveTargetAgent(ChatHandler* handler)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
        {
            handler->SendSysMessage("AIWorld group: select a creature target first.");
            return AgentId{};
        }

        AgentId agentId = sAIWorldMgr->FindAgentIdForCreature(*target);
        if (!agentId)
            handler->SendSysMessage(Trinity::StringFormat("AIWorld group: target (map={}, spawnId={}) has no registered AgentRecord.",
                target->GetMapId(), target->GetSpawnId()));

        return agentId;
    }
}

class aiworld_group_commandscript : public CommandScript
{
public:
    aiworld_group_commandscript() : CommandScript("aiworld_group_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable groupTable =
        {
            { "status", HandleAIWorldGroupStatusCommand, rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "join",   HandleAIWorldGroupJoinCommand,   rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "leave",  HandleAIWorldGroupLeaveCommand,  rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
        };
        static ChatCommandTable aiworldTable =
        {
            { "group", groupTable },
        };
        static ChatCommandTable commandTable =
        {
            { "aiworld", aiworldTable },
        };
        return commandTable;
    }

    static bool HandleAIWorldGroupStatusCommand(ChatHandler* handler)
    {
        AgentId agentId = ResolveTargetAgent(handler);
        if (!agentId)
            return true;

        WorldFactionId faction = sAIWorldMgr->GetAgentWorldFaction(agentId);
        handler->SendSysMessage(Trinity::StringFormat("AIWorld group: agent id={} worldFaction={}", agentId.Value, WorldFactionDisplayName(faction)));

        Creature const* target = handler->getSelectedCreature();
        if (target)
        {
            handler->SendSysMessage(Trinity::StringFormat("AIWorld group: target={} entry={} spawnId={} health={:.1f}%",
                target->GetName(), target->GetEntry(), target->GetSpawnId(), target->GetHealthPct()));
            if (std::optional<AIWorldMgr::WolfFormationDebugInfo> wolf = sAIWorldMgr->DescribeWolfFormation(*target))
            {
                handler->SendSysMessage(Trinity::StringFormat("AIWorld wolf: control={} livingEnabled={} hunger={:.2f} goal={} action={}",
                    ToString(wolf->ControlMode), wolf->LivingEnabled, wolf->Hunger, wolf->Goal, wolf->Action));
                handler->SendSysMessage(Trinity::StringFormat("AIWorld wolf: formation={} expectedEntry={} radius={:.1f} minMembers={}",
                    wolf->FormationState, wolf->ExpectedEntry, wolf->FormationRadius, wolf->MinMembers));
                if (wolf->NearbyEligibleIncludingSelf)
                    handler->SendSysMessage(Trinity::StringFormat("AIWorld wolf: nearby free eligible agents (including self)={}; formation is a current snapshot, not a completed join.",
                        *wolf->NearbyEligibleIncludingSelf));
            }
        }

        std::vector<GroupId> groups = sAIWorldMgr->GetGroupsOfAgent(agentId);
        if (groups.empty())
        {
            handler->SendSysMessage("AIWorld group: not currently a member of any group.");
            return true;
        }

        for (GroupId groupId : groups)
        {
            std::optional<AIWorldMgr::GroupDebugInfo> info = sAIWorldMgr->DescribeGroup(groupId);
            if (!info)
            {
                handler->SendSysMessage(Trinity::StringFormat("AIWorld group: member of group id={} (no longer resolves in the registry - stale?)", groupId.Value));
                continue;
            }

            std::string requiredFaction = info->RequiredWorldFaction ? WorldFactionDisplayName(*info->RequiredWorldFaction) : "(none - manual/admin group)";
            handler->SendSysMessage(Trinity::StringFormat("AIWorld group: member of group id={} kind={} profile={} requiredWorldFaction={} members={}",
                groupId.Value, ToString(info->Kind), ToString(info->ProfileId), requiredFaction, uint32(info->MemberCount)));
        }

        return true;
    }

    static bool HandleAIWorldGroupJoinCommand(ChatHandler* handler, uint32 groupId)
    {
        AgentId agentId = ResolveTargetAgent(handler);
        if (!agentId)
            return true;

        uint32 accountId = handler->GetSession()->GetAccountId();

        sAIWorldMgr->RequestManualJoinGroup(GroupId{ uint64(groupId) }, agentId,
            [accountId, agentId, groupId](bool success, AgentGroupPolicyDecision decision)
        {
            WorldSession* session = sWorld->FindSession(accountId);
            if (!session)
                return;

            if (success)
            {
                session->SendNotification("AIWorld group: JOIN PASSED - agent id=%u is now a member of group id=%u.", uint32(agentId.Value), groupId);
                return;
            }

            if (decision != AgentGroupPolicyDecision::Allowed)
                session->SendNotification("AIWorld group: JOIN REJECTED - policy reason=%s (agent id=%u, group id=%u).",
                    ToString(decision), uint32(agentId.Value), groupId);
            else
                session->SendNotification("AIWorld group: JOIN REJECTED - lifecycle refused the request (likely a WorldFaction mismatch - "
                    "see the worldserver ai.world log for the exact reason; agent id=%u, group id=%u).", uint32(agentId.Value), groupId);
        });

        return true;
    }

    static bool HandleAIWorldGroupLeaveCommand(ChatHandler* handler, uint32 groupId)
    {
        AgentId agentId = ResolveTargetAgent(handler);
        if (!agentId)
            return true;

        uint32 accountId = handler->GetSession()->GetAccountId();

        sAIWorldMgr->RequestManualLeaveGroup(GroupId{ uint64(groupId) }, agentId,
            [accountId, agentId, groupId](bool success, AgentGroupPolicyDecision decision)
        {
            WorldSession* session = sWorld->FindSession(accountId);
            if (!session)
                return;

            if (success)
                session->SendNotification("AIWorld group: LEAVE PASSED - agent id=%u is no longer a member of group id=%u.", uint32(agentId.Value), groupId);
            else
                session->SendNotification("AIWorld group: LEAVE REJECTED - reason=%s (agent id=%u, group id=%u).",
                    ToString(decision), uint32(agentId.Value), groupId);
        });

        return true;
    }
};

void AddSC_aiworld_group_commandscript()
{
    new aiworld_group_commandscript();
}
