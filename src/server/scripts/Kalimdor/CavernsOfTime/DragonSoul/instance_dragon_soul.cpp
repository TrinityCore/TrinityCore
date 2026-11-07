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
#include "dragon_soul.h"
#include "InstanceScript.h"

DungeonEncounterData const encounters[] =
{
    { BOSS_MORCHOK,                 {{ 1292 }}  },
    { BOSS_WARLORD_ZONOZZ,          {{ 1294 }}  },
    { BOSS_YORSAHJ_THE_UNSLEEPING,  {{ 1295 }}  },
    { BOSS_HAGARA_THE_STORMBINDER,  {{ 1296 }}  },
    { BOSS_ULTRAXION,               {{ 1297 }}  },
    { BOSS_WARMASTER_BLACKHORN,     {{ 1298 }}  },
    { BOSS_SPINE_OF_DEATHWING,      {{ 1291 }}  },
    { BOSS_MADNESS_OF_DEATHWING,    {{ 1299 }}  }
};

class instance_dragon_soul : public InstanceMapScript
{
public:
    instance_dragon_soul() : InstanceMapScript(DSScriptName, 967) { }

    struct instance_dragon_soul_InstanceMapScript : public InstanceScript
    {
        instance_dragon_soul_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dragon_soul_InstanceMapScript(map);
    }
};

void AddSC_instance_dragon_soul()
{
    new instance_dragon_soul();
}
