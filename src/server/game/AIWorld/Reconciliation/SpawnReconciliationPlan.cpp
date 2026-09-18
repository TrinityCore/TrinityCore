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

#include "SpawnReconciliationPlan.h"
#include <unordered_map>

SpawnReconciliationPlan BuildReconciliationPlan(
    std::vector<CreatureSpawnIdentity> const& census,
    std::unordered_set<uint64> const& allKnownSpawnIds,
    std::vector<AgentSpawnBinding> const& physicalBindings,
    WorldFactionCatalog const& worldFactionCatalog,
    AgentTypeCatalog const& agentTypeCatalog)
{
    SpawnReconciliationPlan plan;

    std::unordered_map<uint64, CreatureSpawnIdentity const*> eligibleBySpawnId;
    eligibleBySpawnId.reserve(census.size());
    for (CreatureSpawnIdentity const& identity : census)
        eligibleBySpawnId.emplace(identity.SpawnId, &identity);

    // Every SpawnId with ANY physical ai_agents row - valid, orphaned,
    // conflicted, out-of-scope, or already quarantined by LoadAgents() -
    // must be excluded from Missing below, so reconciliation never tries
    // to INSERT a (map_id, spawn_id) that already exists.
    std::unordered_set<uint64> physicalSpawnIds;
    physicalSpawnIds.reserve(physicalBindings.size());

    // Milestone 2.12F4B P2 fix (STATIC review): every agent_id currently
    // occupied by ANY physical row, regardless of that row's own SpawnId.
    // A quarantined row (agent_id != its own spawn_id) can still occupy an
    // agent_id that collides with a completely unrelated, currently-real
    // spawn's intended new identity - the (map_id, spawn_id) UNIQUE key
    // alone does not protect against that, since agent_id is ai_agents'
    // own PRIMARY KEY.
    std::unordered_set<uint64> physicalAgentIds;
    physicalAgentIds.reserve(physicalBindings.size());

    for (AgentSpawnBinding const& binding : physicalBindings)
    {
        physicalSpawnIds.insert(binding.SpawnId);
        physicalAgentIds.insert(binding.Id.Value);

        // 2.12F4A2's own invariant - AgentPersistence::LoadAgents() itself
        // already quarantined this row (never added it to AgentRegistry).
        // Nothing for this plan to remove; just don't treat its SpawnId as
        // Missing (handled above) or its AgentId as free (handled below).
        if (binding.Id.Value != binding.SpawnId)
        {
            ++plan.QuarantinedCount;
            continue;
        }

        auto it = eligibleBySpawnId.find(binding.SpawnId);
        if (it == eligibleBySpawnId.end())
        {
            // Milestone 2.12F4B P2 fix (STATIC review): not eligible does
            // NOT mean gone - it may simply be out of 2.12F4 scope (e.g.
            // an instance/raid spawn), which must never be treated as
            // Orphaned. Only a SpawnId absent from allKnownSpawnIds too
            // names a world.creature spawn that has actually been removed.
            if (allKnownSpawnIds.find(binding.SpawnId) != allKnownSpawnIds.end())
                ++plan.OutOfScopeCount;
            else
                plan.Orphaned.push_back(binding.Id);
            continue;
        }

        // Eligible spawn exists, AgentId == SpawnId, but the row's own
        // stored MapId disagrees with what world.creature actually says -
        // a data inconsistency, never silently counted as VALID.
        if (binding.MapId != it->second->MapId)
        {
            plan.Conflicted.push_back(binding.Id);
            continue;
        }

        ++plan.ValidCount;
    }

    for (CreatureSpawnIdentity const& identity : census)
    {
        if (physicalSpawnIds.find(identity.SpawnId) != physicalSpawnIds.end())
            continue;

        // Milestone 2.12F4B P2 fix (STATIC review): this spawn has no
        // physical ai_agents row of its own, but its intended new AgentId
        // (== SpawnId) is already some OTHER row's agent_id - inserting it
        // would collide with ai_agents' own PRIMARY KEY. Block, don't
        // insert.
        if (physicalAgentIds.find(identity.SpawnId) != physicalAgentIds.end())
        {
            plan.AgentIdCollisions.push_back(identity);
            continue;
        }

        PendingCreatureAgent pending;
        pending.Type = agentTypeCatalog.Resolve(identity.Entry);
        pending.MapId = identity.MapId;
        pending.SpawnId = identity.SpawnId;
        pending.WorldFaction = worldFactionCatalog.Resolve(identity.Entry);
        plan.Missing.push_back(pending);
    }

    return plan;
}
