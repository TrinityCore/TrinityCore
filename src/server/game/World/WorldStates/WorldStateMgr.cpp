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

#include "WorldStateMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldStatePackets.h"

namespace
{
std::unordered_map<int32, WorldStateTemplate> _worldStateTemplates;
WorldStateValueContainer _realmWorldStateValues;
std::unordered_map<uint32, WorldStateValueContainer> _worldStatesByMap;
}

void WorldStateMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    //                                               0   1             2      3
    QueryResult result = WorldDatabase.Query("SELECT ID, DefaultValue, MapID, ScriptName FROM world_state");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        int32 id = fields[0].GetInt32();
        WorldStateTemplate& worldState = _worldStateTemplates[id];
        worldState.Id = id;
        worldState.DefaultValue = fields[1].GetInt32();
        if (!fields[2].IsNull())
            worldState.MapId = fields[2].GetUInt32();

        worldState.ScriptId = sObjectMgr->GetScriptId(fields[3].GetString());

        if (worldState.MapId)
            _worldStatesByMap[*worldState.MapId][id] = worldState.DefaultValue;
        else
            _realmWorldStateValues[id] = worldState.DefaultValue;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " world state templates %u ms", _worldStateTemplates.size(), GetMSTimeDiffToNow(oldMSTime));
}

WorldStateTemplate const* WorldStateMgr::GetWorldStateTemplate(int32 worldStateId) const
{
    return Trinity::Containers::MapGetValuePtr(_worldStateTemplates, worldStateId);
}

int32 WorldStateMgr::GetValue(int32 worldStateId, Map const* map) const
{
    WorldStateTemplate const* worldStateTemplate = GetWorldStateTemplate(worldStateId);
    if (!worldStateTemplate || !worldStateTemplate->MapId)
    {
        if (int32 const* value = Trinity::Containers::MapGetValuePtr(_realmWorldStateValues, worldStateId))
            return *value;

        return 0;
    }

    if (map->GetId() != worldStateTemplate->MapId)
        return 0;

    return map->GetWorldStateValue(worldStateId);
}

void WorldStateMgr::SetValue(int32 worldStateId, int32 value, Map* map)
{
    WorldStateTemplate const* worldStateTemplate = GetWorldStateTemplate(worldStateId);
    if (!worldStateTemplate || !worldStateTemplate->MapId)
    {
        auto itr = _realmWorldStateValues.try_emplace(worldStateId, 0).first;
        int32 oldValue = itr->second;
        itr->second = value;

        if (worldStateTemplate)
            sScriptMgr->OnWorldStateValueChange(worldStateTemplate, oldValue, value, nullptr);

        // Broadcast update to all players on the server
        WorldPackets::WorldState::UpdateWorldState updateWorldState;
        updateWorldState.VariableID = worldStateId;
        updateWorldState.Value = value;
        sWorld->SendGlobalMessage(updateWorldState.Write());
        return;
    }

    if (map->GetId() != worldStateTemplate->MapId)
        return;

    map->SetWorldStateValue(worldStateId, value);
}

WorldStateValueContainer WorldStateMgr::GetInitialWorldStatesForMap(Map const* map) const
{
    WorldStateValueContainer initialValues;
    if (WorldStateValueContainer const* valuesTemplate = Trinity::Containers::MapGetValuePtr(_worldStatesByMap, map->GetId()))
        initialValues = *valuesTemplate;

    return initialValues;
}

void WorldStateMgr::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& initWorldStates, Map const* map) const
{
    for (auto const& [worldStateId, value] : _realmWorldStateValues)
        initWorldStates.Worldstates.emplace_back(worldStateId, value);

    for (auto const& [worldStateId, value] : map->GetWorldStateValues())
        initWorldStates.Worldstates.emplace_back(worldStateId, value);
}

WorldStateMgr* WorldStateMgr::instance()
{
    static WorldStateMgr instance;
    return &instance;
}
