/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"

ObjectData const creatureData[] =
{
    { BOSS_GENERAL_HUSAM,           DATA_GENERAL_HUSAM          },
    { BOSS_LOCKMAW,                 DATA_LOCKMAW                },
    { BOSS_AUGH,                    DATA_AUGH                   },
    { BOSS_HIGH_PROPHET_BARIM,      DATA_HIGH_PROPHET_BARIM     },
    { BOSS_SIAMAT,                  DATA_SIAMAT                 },
    { NPC_BLAZE_OF_THE_HEAVENS,     DATA_BLAZE_OF_THE_HEAVENS   },
    { NPC_HARBINGER_OF_DARKNESS,    DATA_HARBINGER_OF_DARKNESS  },
    { 0,                        0                               } // End
};

ObjectData const gameObjectData[] =
{
    { GO_SIAMAT_PLATFORM,       DATA_SIAMAT_PLATFORM   },
    { 0,                        0                      } // End
};

class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
public:
    instance_lost_city_of_the_tolvir() : InstanceMapScript(LCTScriptName, 755) { }

    struct instance_lost_city_of_the_tolvir_InstanceMapScript : public InstanceScript
    {
        instance_lost_city_of_the_tolvir_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, gameObjectData);
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            return true;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_lost_city_of_the_tolvir_InstanceMapScript(map);
    }
};

void AddSC_instance_lost_city_of_the_tolvir()
{
    new instance_lost_city_of_the_tolvir();
}
