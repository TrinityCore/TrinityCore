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
#include "DB2Stores.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "StringConvert.h"
#include "Util.h"
#include "World.h"
#include "WorldStatePackets.h"

namespace
{
constexpr int32 WORLDSTATE_ANY_MAP = -1;
std::unordered_map<int32, WorldStateTemplate> _worldStateTemplates;
WorldStateValueContainer _realmWorldStateValues;
std::unordered_map<int32, WorldStateValueContainer> _worldStatesByMap;
}

void WorldStateMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    //                                               0   1             2       3        4
    QueryResult result = WorldDatabase.Query("SELECT ID, DefaultValue, MapIDs, AreaIDs, ScriptName FROM world_state");
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        int32 id = fields[0].GetInt32();
        WorldStateTemplate& worldState = _worldStateTemplates[id];
        worldState.Id = id;
        worldState.DefaultValue = fields[1].GetInt32();

        std::string_view mapIds = fields[2].GetStringView();
        for (std::string_view mapIdToken : Trinity::Tokenize(mapIds, ',', false))
        {
            Optional<int32> mapId = Trinity::StringTo<int32>(mapIdToken);
            if (!mapId)
            {
                TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with non-integer MapID (" STRING_VIEW_FMT "), map ignored",
                    id, STRING_VIEW_FMT_ARG(mapIdToken));
                continue;
            }

            if (!sMapStore.LookupEntry(*mapId) && mapId != WORLDSTATE_ANY_MAP)
            {
                TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with invalid MapID (%d), map ignored",
                    id, *mapId);
                continue;
            }

            worldState.MapIds.insert(*mapId);
        }

        if (!mapIds.empty() && worldState.MapIds.empty())
        {
            TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with nonempty MapIDs (" STRING_VIEW_FMT ") but no valid map id was found, ignored",
                id, STRING_VIEW_FMT_ARG(mapIds));
            continue;
        }

        std::string_view areaIds = fields[3].GetStringView();
        if (!worldState.MapIds.empty())
        {
            for (std::string_view areaIdToken : Trinity::Tokenize(areaIds, ',', false))
            {
                Optional<uint32> areaId = Trinity::StringTo<uint32>(areaIdToken);
                if (!areaId)
                {
                    TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %u with non-integer AreaID (" STRING_VIEW_FMT "), area ignored",
                        id, STRING_VIEW_FMT_ARG(areaIdToken));
                    continue;
                }

                AreaTableEntry const* areaTableEntry = sAreaTableStore.LookupEntry(*areaId);
                if (!areaTableEntry)
                {
                    TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with invalid AreaID (%u), area ignored",
                        id, *areaId);
                    continue;
                }

                if (worldState.MapIds.find(areaTableEntry->ContinentID) == worldState.MapIds.end())
                {
                    TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with AreaID (%u) not on any of required maps, area ignored",
                        id, *areaId);
                    continue;
                }

                worldState.AreaIds.insert(*areaId);
            }

            if (!areaIds.empty() && worldState.AreaIds.empty())
            {
                TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with nonempty AreaIDs (" STRING_VIEW_FMT ") but no valid area id was found, ignored",
                    id, STRING_VIEW_FMT_ARG(areaIds));
                continue;
            }
        }
        else if (!areaIds.empty())
        {
            TC_LOG_ERROR("sql.sql", "Table `world_state` contains a world state %d with nonempty AreaIDs (" STRING_VIEW_FMT ") but is a realm wide world state, area requirement ignored",
                id, STRING_VIEW_FMT_ARG(areaIds));
        }

        worldState.ScriptId = sObjectMgr->GetScriptId(fields[4].GetString());

        if (!worldState.MapIds.empty())
        {
            for (int32 mapId : worldState.MapIds)
                _worldStatesByMap[mapId][id] = worldState.DefaultValue;
        }
        else
            _realmWorldStateValues[id] = worldState.DefaultValue;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " world state templates %u ms", _worldStateTemplates.size(), GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();

    result = CharacterDatabase.Query("SELECT Id, Value FROM world_state_value");
    uint32 savedValueCount = 0;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            int32 worldStateId = fields[0].GetInt32();
            WorldStateTemplate* worldState = Trinity::Containers::MapGetValuePtr(_worldStateTemplates, worldStateId);
            if (!worldState)
            {
                TC_LOG_ERROR("sql.sql", "Table `world_state_value` contains a value for unknown world state %d, ignored", worldStateId);
                continue;
            }

            int32 value = fields[1].GetInt32();

            if (!worldState->MapIds.empty())
            {
                for (int32 mapId : worldState->MapIds)
                    _worldStatesByMap[mapId][worldStateId] = value;
            }
            else
                _realmWorldStateValues[worldStateId] = value;

            ++savedValueCount;
        }
        while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Loaded %u saved world state values %u ms", savedValueCount, GetMSTimeDiffToNow(oldMSTime));
}

WorldStateTemplate const* WorldStateMgr::GetWorldStateTemplate(int32 worldStateId) const
{
    return Trinity::Containers::MapGetValuePtr(_worldStateTemplates, worldStateId);
}

int32 WorldStateMgr::GetValue(int32 worldStateId, Map const* map) const
{
    WorldStateTemplate const* worldStateTemplate = GetWorldStateTemplate(worldStateId);
    if (!worldStateTemplate || worldStateTemplate->MapIds.empty())
    {
        if (int32 const* value = Trinity::Containers::MapGetValuePtr(_realmWorldStateValues, worldStateId))
            return *value;

        return 0;
    }

    if (!map || (!worldStateTemplate->MapIds.count(map->GetId()) && !worldStateTemplate->MapIds.count(WORLDSTATE_ANY_MAP)))
        return 0;

    return map->GetWorldStateValue(worldStateId);
}

void WorldStateMgr::SetValue(int32 worldStateId, int32 value, bool hidden, Map* map)
{
    WorldStateTemplate const* worldStateTemplate = GetWorldStateTemplate(worldStateId);
    if (!worldStateTemplate || worldStateTemplate->MapIds.empty())
    {
        auto [itr, inserted] = _realmWorldStateValues.try_emplace(worldStateId, 0);
        int32 oldValue = itr->second;
        if (oldValue == value && !inserted)
            return;

        itr->second = value;

        if (worldStateTemplate)
            sScriptMgr->OnWorldStateValueChange(worldStateTemplate, oldValue, value, nullptr);

        // Broadcast update to all players on the server
        WorldPackets::WorldState::UpdateWorldState updateWorldState;
        updateWorldState.VariableID = worldStateId;
        updateWorldState.Value = value;
        updateWorldState.Hidden = hidden;
        sWorld->SendGlobalMessage(updateWorldState.Write());
        return;
    }

    if (!map || (!worldStateTemplate->MapIds.count(map->GetId()) && !worldStateTemplate->MapIds.count(WORLDSTATE_ANY_MAP)))
        return;

    map->SetWorldStateValue(worldStateId, value, hidden);
}

void WorldStateMgr::SaveValueInDb(int32 worldStateId, int32 value)
{
    if (!GetWorldStateTemplate(worldStateId))
        return;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_WORLD_STATE);
    stmt->setInt32(0, worldStateId);
    stmt->setInt32(1, value);
    CharacterDatabase.Execute(stmt);
}

void WorldStateMgr::SetValueAndSaveInDb(int32 worldStateId, int32 value, bool hidden, Map* map)
{
    SetValue(worldStateId, value, hidden, map);
    SaveValueInDb(worldStateId, value);
}

WorldStateValueContainer WorldStateMgr::GetInitialWorldStatesForMap(Map const* map) const
{
    WorldStateValueContainer initialValues;
    if (WorldStateValueContainer const* valuesTemplate = Trinity::Containers::MapGetValuePtr(_worldStatesByMap, map->GetId()))
        initialValues.insert(valuesTemplate->begin(), valuesTemplate->end());

    if (WorldStateValueContainer const* valuesTemplate = Trinity::Containers::MapGetValuePtr(_worldStatesByMap, WORLDSTATE_ANY_MAP))
        initialValues.insert(valuesTemplate->begin(), valuesTemplate->end());

    return initialValues;
}

void WorldStateMgr::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& initWorldStates, Map const* map, uint32 playerAreaId) const
{
    for (auto const& [worldStateId, value] : _realmWorldStateValues)
        initWorldStates.Worldstates.emplace_back(worldStateId, value);

    for (auto const& [worldStateId, value] : map->GetWorldStateValues())
    {
        WorldStateTemplate const* worldStateTemplate = GetWorldStateTemplate(worldStateId);
        if (worldStateTemplate && !worldStateTemplate->AreaIds.empty())
        {
            bool isInAllowedArea = std::any_of(worldStateTemplate->AreaIds.begin(), worldStateTemplate->AreaIds.end(),
                [=](uint32 requiredAreaId) { return DB2Manager::IsInArea(playerAreaId, requiredAreaId); });
            if (!isInAllowedArea)
                continue;
        }

        initWorldStates.Worldstates.emplace_back(worldStateId, value);
    }
}

WorldStateMgr* WorldStateMgr::instance()
{
    static WorldStateMgr instance;
    return &instance;
}
