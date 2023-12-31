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
#include "trial_of_valor.h"

BossBoundaryData const boundaries =
{
    { DATA_GUARM, new RectangleBoundary(443.320f, 492.354f, 430.713f, 561.020f) }
};

ObjectData const creatureData[] =
{
    { BOSS_ODYN,                DATA_ODYN               },
    { BOSS_GUARM,               DATA_GUARM              },
    { BOSS_HELYA,               DATA_HELYA              },
    { 0,                        0                       }  // END
};

DoorData const doorData[] =
{
    { GO_GUARM_BOSS_DOOR_ENTRANCE,              DATA_GUARM,     EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_GUARM_BOSS_DOOR_EXIT,                  DATA_GUARM,     EncounterDoorBehavior::OpenWhenDone },
    { 0,                                        0,              EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_ODYN,    {{ 1958 }} },
    { DATA_GUARM,   {{ 1962 }} },
    { DATA_HELYA,   {{ 2008 }} },
};

class instance_trial_of_valor : public InstanceMapScript
{
    public:
        instance_trial_of_valor() : InstanceMapScript(TOVScriptName, 1648) { }

        struct instance_trial_of_valor_InstanceMapScript: public InstanceScript
        {
            instance_trial_of_valor_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
            return new instance_trial_of_valor_InstanceMapScript(map);
        }
};

void AddSC_instance_trial_of_valor()
{
    new instance_trial_of_valor();
}
