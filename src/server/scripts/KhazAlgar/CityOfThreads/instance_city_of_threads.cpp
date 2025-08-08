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
#include "city_of_threads.h"

static constexpr ObjectData creatureData[] =
{
    { BOSS_ORATOR_KRIX_VIZK,      DATA_ORATOR_KRIX_VIZK      },
    { BOSS_NX,                    DATA_FANGS_OF_THE_QUEEN    },
    { BOSS_VX,                    DATA_FANGS_OF_THE_QUEEN    },
    { BOSS_THE_COAGLAMATION,      DATA_THE_COAGLAMATION      },
    { BOSS_IZO_THE_GRAND_SPLICER, DATA_IZO_THE_GRAND_SPLICER },
    { NPC_ORATOR_KRIX_VIZK_CONVO, DATA_ORATOR_CONVO          },
    { 0,                          0                          }  // END
};

static constexpr DungeonEncounterData const encounters[] =
{
    { DATA_ORATOR_KRIX_VIZK,      {{ 2907 }} },
    { DATA_FANGS_OF_THE_QUEEN,    {{ 2908 }} },
    { DATA_THE_COAGLAMATION,      {{ 2905 }} },
    { DATA_IZO_THE_GRAND_SPLICER, {{ 2909 }} }
};

class instance_city_of_threads : public InstanceMapScript
{
public:
    instance_city_of_threads() : InstanceMapScript(COTScriptName, 2669) { }

    struct instance_city_of_threads_InstanceMapScript: public InstanceScript
    {
        instance_city_of_threads_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_city_of_threads_InstanceMapScript(map);
    }
};

void AddSC_instance_city_of_threads()
{
    new instance_city_of_threads();
}
