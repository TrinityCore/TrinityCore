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

#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ruby_life_pools.h"

ObjectData const creatureData[] =
{
    { BOSS_MELIDRUSSA_CHILLWORN,    DATA_MELIDRUSSA_CHILLWORN          },
    { BOSS_KOKIA_BLAZEHOOF,         DATA_KOKIA_BLAZEHOOF               },
    { BOSS_KYRAKKA,                 DATA_KYRAKKA_AND_ERKHART_STORMVEIN },
    { 0,                            0                                  }  // END
};

DoorData const doorData[] =
{
    { GO_FIRE_WALL,    DATA_KOKIA_BLAZEHOOF,  EncounterDoorBehavior::OpenWhenDone },
    { 0,               0,                     EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_MELIDRUSSA_CHILLWORN, {{ 2609 }} },
    { DATA_KOKIA_BLAZEHOOF, {{ 2606 }} },
    { DATA_KYRAKKA_AND_ERKHART_STORMVEIN, {{ 2623 }} }
};

class instance_ruby_life_pools : public InstanceMapScript
{
    public:
        instance_ruby_life_pools() : InstanceMapScript(RLPScriptName, 2521) { }

        struct instance_ruby_life_pools_InstanceMapScript: public InstanceScript
        {
            instance_ruby_life_pools_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ruby_life_pools_InstanceMapScript(map);
        }
};

void AddSC_instance_ruby_life_pools()
{
    new instance_ruby_life_pools();
}
