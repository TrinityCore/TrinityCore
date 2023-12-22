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
#include "vortex_pinnacle.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_GRAND_VIZIER_ERTAN,   BOSS_GRAND_VIZIER_ERTAN },
    { NPC_ALTAIRUS,             BOSS_ALTAIRUS           },
    { NPC_ASAAD,                BOSS_ASAAD              },
    { 0,                        0                       } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_GRAND_VIZIER_ERTAN,  {{ 1043 }}  },
    { BOSS_ALTAIRUS,            {{ 1041 }}  },
    { BOSS_ASAAD,               {{ 1042 }}  }
};

class instance_vortex_pinnacle : public InstanceMapScript
{
public:
    instance_vortex_pinnacle() : InstanceMapScript(VPScriptName, 657) { }

    struct instance_vortex_pinnacle_InstanceMapScript : public InstanceScript
    {
        instance_vortex_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_vortex_pinnacle_InstanceMapScript(map);
    }
};

void AddSC_instance_vortex_pinnacle()
{
    new instance_vortex_pinnacle();
}
