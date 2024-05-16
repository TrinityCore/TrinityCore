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
#include "maw_of_souls.h"

BossBoundaryData const boundaries =
{
    { DATA_YMIRON, new CircleBoundary({ 7382.8168f, 7300.5527f }, 55.0f)}
};

ObjectData const creatureData[] =
{
    { BOSS_YMIRON,                              DATA_YMIRON             },
    { BOSS_HARBARON,                            DATA_HARBARON           },
    { BOSS_HELYA,                               DATA_HELYA              },
    { 0,                                        0                       }  // END
};

DoorData const doorData[] =
{
    { 0,                                        0,              EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_YMIRON,      {{ 1822 }} },
    { DATA_HARBARON,    {{ 1823 }} },
    { DATA_HELYA,       {{ 1824 }} },
};

class instance_maw_of_souls : public InstanceMapScript
{
public:
    instance_maw_of_souls() : InstanceMapScript(MOSScriptName, 1492) { }

    struct AddSC_instance_maw_of_souls_InstanceMapScript : public InstanceScript
    {
        AddSC_instance_maw_of_souls_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new AddSC_instance_maw_of_souls_InstanceMapScript(map);
    }
};

void AddSC_instance_maw_of_souls()
{
    new instance_maw_of_souls();
}
