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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"

static constexpr ObjectData const creatureData[] =
{
    { NPC_GENERAL_HUSAM,        BOSS_GENERAL_HUSAM       },
    { NPC_LOCKMAW,              DATA_LOCKMAW             },
    { NPC_AUGH,                 DATA_AUGH                },
    { NPC_HIGH_PROPHET_BARIM,   BOSS_HIGH_PROPHET_BARIM  },
    { NPC_SIAMAT,               BOSS_SIAMAT              },
    { 0,                        0                        } // End
};

static constexpr DungeonEncounterData const encounters[] =
{
    { BOSS_GENERAL_HUSAM,       {{ 1052 }} },
    { BOSS_LOCKMAW_AND_AUGH,    {{ 1054 }} },
    { BOSS_HIGH_PROPHET_BARIM,  {{ 1053 }} },
    { BOSS_SIAMAT,              {{ 1055 }} }
};

class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
public:
    instance_lost_city_of_the_tolvir() : InstanceMapScript(LCTScriptName, 755) { }

    struct instance_lost_city_of_the_tolvir_InstanceMapScript : public InstanceScript
    {
        instance_lost_city_of_the_tolvir_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDungeonEncounterData(encounters);
            LoadObjectData(creatureData, nullptr);
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
