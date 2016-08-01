/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __SCENARIOMGR_H
#define __SCENARIOMGR_H

#include "InstanceScenario.h"

class InstanceScenario;
struct ScenarioData;

/*
    Scenario data should be loaded on demand.
    The server will get data from the database which scenario ids is linked with which map id/difficulty/player team.
    The first time a scenario is loaded, the map loads and stores the scenario data for future scenario instance launches.
*/

struct ScenarioDBData
{
    uint32 MapID;
    uint8 DifficultyID;
    uint32 Scenario_A;
    uint32 Scenario_H;
};

typedef std::list<ScenarioDBData const*> ScenarioDBDataContainer;
typedef std::map<uint32, ScenarioData const*> ScenarioDataContainer;

enum ScenarioType
{
    SCENARIO_TYPE_SCENARIO          = 0,
    SCENARIO_TYPE_CHALLENGE_MODE    = 1,
    SCENARIO_TYPE_SOLO              = 2,
    SCENARIO_TYPE_DUNGEON           = 10,
};

class TC_GAME_API ScenarioMgr
{
private:
    ScenarioMgr() { }
    ~ScenarioMgr() { }

public:
    static ScenarioMgr* Instance();

    void LoadDBData();
    void LoadDBCData();

    InstanceScenario* CreateInstanceScenario(Map* map, TeamId team);

private:
    ScenarioDataContainer _scenarioData;
    ScenarioDBDataContainer _scenarioDBData;
};

#define sScenarioMgr ScenarioMgr::Instance()

#endif // __SCENARIOMGR_H
