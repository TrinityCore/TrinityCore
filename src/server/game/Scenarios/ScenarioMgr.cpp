/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "ScenarioMgr.h"
#include "DB2Stores.h"
#include "Timer.h"
#include "Map.h"
#include "ChatTextBuilder.h"
#include "Language.h"
#include "Player.h"
#include "InstanceScenario.h"

ScenarioMgr* ScenarioMgr::Instance()
{
    static ScenarioMgr instance;
    return &instance;
}

InstanceScenario* ScenarioMgr::CreateInstanceScenario(Map* map, TeamId team)
{
    ScenarioDBData const* scenarioData = nullptr;
    for (ScenarioDBData const* data : _scenarioDBData)
    {
        if (map->GetId() != data->MapID || map->GetDifficultyID() != Difficulty(data->DifficultyID))
            continue;

        scenarioData = data;
    }

    // No scenario registered for this map and difficulty in the database
    if (!scenarioData)
        return nullptr;

    uint32 scenarioID = 0;
    switch (team)
    {
        case TEAM_ALLIANCE:
            scenarioID = scenarioData->Scenario_A;
            break;
        case TEAM_HORDE:
            scenarioID = scenarioData->Scenario_H;
            break;
        default:
            break;
    }

    ScenarioDataContainer::iterator itr = _scenarioData.find(scenarioID);
    if (itr == _scenarioData.end())
    {
        TC_LOG_ERROR("scenario", "Table `scenarios` contained data linking scenario (Id: %u) to map (Id: %u), difficulty (Id: %u) but no scenario data was found related to that scenario Id.");
        return nullptr;
    }

    return new InstanceScenario(map, itr->second);
}

void ScenarioMgr::LoadDBData()
{
    _scenarioDBData.clear();

    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT map, difficulty, scenario_A, scenario_H FROM scenarios");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 scenarios. DB table `scenarios` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 mapId = fields[0].GetUInt32();
        uint8 difficulty = fields[1].GetUInt8();

        uint32 scenarioAllianceId = fields[2].GetUInt32();
        ScenarioDataContainer::iterator itr = _scenarioData.find(scenarioAllianceId);
        if (scenarioAllianceId > 0 && itr == _scenarioData.end())
        {
            TC_LOG_ERROR("sql.sql", "ScenarioMgr::LoadDBData: DB Table `scenarios`, column scenario_A contained an invalid scenario (Id: %u)!", scenarioAllianceId);
            continue;
        }

        uint32 scenarioHordeId = fields[3].GetUInt32();
        itr = _scenarioData.find(scenarioHordeId);
        if (scenarioHordeId > 0 && itr == _scenarioData.end())
        {
            TC_LOG_ERROR("sql.sql", "ScenarioMgr::LoadDBData: DB Table `scenarios`, column scenario_H contained an invalid scenario (Id: %u)!", scenarioHordeId);
            continue;
        }

        if (scenarioHordeId == 0)
            scenarioHordeId = scenarioAllianceId;

        ScenarioDBData* data = new ScenarioDBData();
        data->MapID = mapId;
        data->DifficultyID = difficulty;
        data->Scenario_A = scenarioAllianceId;
        data->Scenario_H = scenarioHordeId;

        _scenarioDBData.push_back(data);
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u instance scenario entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void ScenarioMgr::LoadDBCData()
{
    _scenarioData.clear();

    for (uint32 i = 0; i < sScenarioStore.GetNumRows(); ++i)
    {
        ScenarioEntry const* scenario = sScenarioStore.LookupEntry(i);
        if (!scenario)
            continue;

        ScenarioData* data = new ScenarioData();
        data->Entry = scenario;

        for (uint32 i = 0; i < sScenarioStepStore.GetNumRows(); ++i)
        {
            ScenarioStepEntry const* step = sScenarioStepStore.LookupEntry(i);
            if (!step || step->ScenarioID != scenario->ID)
                continue;

            data->Steps[step->Step] = step;
        }

        _scenarioData[data->Entry->ID] = data;
    }
}