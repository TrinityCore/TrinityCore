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

#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "shrine_of_the_storm.h"

static BossBoundaryData const boundaries =
{
    { DATA_AQUSIRR, new ZRangeBoundary(119.89f, 132.9f) }
};

ObjectData const creatureData[] =
{
    { BOSS_AQUSIRR,               DATA_AQUSIRR               },
    { BOSS_BROTHER_IRONHULL,      DATA_BROTHER_IRONHULL      },
    { BOSS_GALECALLER_FAYE,       DATA_GALECALLER_FAYE       },
    { BOSS_LORD_STORMSONG,        DATA_LORD_STORMSONG        },
    { BOSS_VOLZITH_THE_WHISPERER, DATA_VOLZITH_THE_WHISPERER },
    { 0,                          0                          }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_AQUSIRR,               {{ 2130 }} },
    { DATA_TIDESAGE_COUNCIL,      {{ 2131 }} },
    { DATA_LORD_STORMSONG,        {{ 2132 }} },
    { DATA_VOLZITH_THE_WHISPERER, {{ 2133 }} }
};

class instance_shrine_of_the_storm : public InstanceMapScript
{
public:
    instance_shrine_of_the_storm() : InstanceMapScript("instance_shrine_of_the_storm", 1864) { }

    struct instance_shrine_of_the_storm_InstanceMapScript : public InstanceScript
    {
        instance_shrine_of_the_storm_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadBossBoundaries(boundaries);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shrine_of_the_storm_InstanceMapScript(map);
    }
};

void AddSC_instance_shrine_of_the_storm()
{
    new instance_shrine_of_the_storm();
}
