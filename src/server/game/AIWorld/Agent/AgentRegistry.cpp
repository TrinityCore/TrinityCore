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

#include "AgentRegistry.h"
#include "Creature.h"
#include "Log.h"
#include <utility>

bool AgentRegistry::Add(AgentRecord record)
{
    if (!record.Id)
    {
        TC_LOG_ERROR("ai.world", "AgentRegistry::Add: refusing to add an agent with AgentId=0");
        return false;
    }

    if (!record.SpawnId)
    {
        TC_LOG_ERROR("ai.world", "AgentRegistry::Add: refusing to add agent id={} with SpawnId=0", record.Id.Value);
        return false;
    }

    if (Find(record.Id))
    {
        TC_LOG_ERROR("ai.world", "AgentRegistry::Add: agent id={} is already registered, ignoring duplicate", record.Id.Value);
        return false;
    }

    if (AgentRecord* existing = FindBySpawn(record.MapId, record.SpawnId))
    {
        TC_LOG_ERROR("ai.world", "AgentRegistry::Add: map={} spawn={} is already registered as agent id={}, ignoring duplicate binding",
            record.MapId, record.SpawnId, existing->Id.Value);
        return false;
    }

    uint64 idValue = record.Id.Value;
    _agents.emplace(idValue, std::move(record));
    return true;
}

bool AgentRegistry::Remove(AgentId id)
{
    return _agents.erase(id.Value) > 0;
}

AgentRecord* AgentRegistry::Find(AgentId id)
{
    auto it = _agents.find(id.Value);
    return it != _agents.end() ? &it->second : nullptr;
}

AgentRecord const* AgentRegistry::Find(AgentId id) const
{
    auto it = _agents.find(id.Value);
    return it != _agents.end() ? &it->second : nullptr;
}

AgentRecord* AgentRegistry::FindBySpawn(uint32 mapId, uint64 spawnId)
{
    for (auto& entry : _agents)
    {
        if (entry.second.MapId == mapId && entry.second.SpawnId == spawnId)
            return &entry.second;
    }
    return nullptr;
}

AgentRecord const* AgentRegistry::FindBySpawn(uint32 mapId, uint64 spawnId) const
{
    for (auto const& entry : _agents)
    {
        if (entry.second.MapId == mapId && entry.second.SpawnId == spawnId)
            return &entry.second;
    }
    return nullptr;
}

// Idempotent - safe (and expected) to call every tick a Creature is found
// for this agent, not just on the Abstract -> Materialized transition. A
// SpawnId identifies a TrinityCore spawn, not a runtime object: if the old
// Creature despawns and a new one for the same spawn appears between two
// polls, WorldState never passes through Abstract, so a plain
// "was it Abstract" check would leave RuntimeGuid pointing at a Creature
// that no longer exists. Comparing GUIDs on every call catches that.
void AgentRegistry::BindCreature(AgentId id, Creature const& creature)
{
    AgentRecord* record = Find(id);
    if (!record)
        return;

    ObjectGuid newGuid = creature.GetGUID();

    if (record->WorldState == AgentWorldState::Materialized && record->RuntimeGuid == newGuid)
        return; // already correctly bound

    if (record->WorldState == AgentWorldState::Materialized)
        TC_LOG_INFO("ai.world", "AI agent id={} rebound spawn={} oldGuid={} newGuid={}",
            id.Value, record->SpawnId, record->RuntimeGuid.ToString(), newGuid.ToString());
    else
        TC_LOG_INFO("ai.world", "AI agent id={} materialized spawn={} guid={}",
            id.Value, record->SpawnId, newGuid.ToString());

    // A wildlife action belongs to one materialized incarnation only.
    if (!record->WolfActionRuntimeGuid.IsEmpty() && record->WolfActionRuntimeGuid != newGuid)
    {
        record->ActiveActionState.reset();
        record->ActiveGoalState.reset();
        record->WolfActionRuntimeGuid.Clear();
    }
    record->WolfMealTarget.Clear();
    record->RuntimeGuid = newGuid;
    record->WorldState = AgentWorldState::Materialized;
}

void AgentRegistry::UnbindCreature(AgentId id)
{
    AgentRecord* record = Find(id);
    if (!record)
        return;

    TC_LOG_INFO("ai.world", "AI agent id={} dematerialized spawn={}", id.Value, record->SpawnId);

    if (!record->WolfActionRuntimeGuid.IsEmpty())
    {
        record->ActiveActionState.reset();
        record->ActiveGoalState.reset();
        record->WolfActionRuntimeGuid.Clear();
    }
    record->WolfMealTarget.Clear();
    record->RuntimeGuid = ObjectGuid::Empty;
    record->WorldState = AgentWorldState::Abstract;
}

std::vector<AgentId> AgentRegistry::GetAgents() const
{
    std::vector<AgentId> ids;
    ids.reserve(_agents.size());
    for (auto const& entry : _agents)
        ids.push_back(entry.second.Id);
    return ids;
}
