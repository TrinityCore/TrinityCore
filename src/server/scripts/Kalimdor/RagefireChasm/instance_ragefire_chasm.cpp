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
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ragefire_chasm.h"

BossBoundaryData const boundaries =
{
    { BOSS_SLAGMAW, new RectangleBoundary(-298.2f, -257.1f, 94.4f, 172.4f) }
};

ObjectData const creatureData[] =
{
    { NPC_ADAROGG,               BOSS_ADAROGG               },
    { NPC_DARK_SHAMAN_KORANTHAL, BOSS_DARK_SHAMAN_KORANTHAL },
    { NPC_SLAGMAW,               BOSS_SLAGMAW               },
    { NPC_LAVA_GUARD_GORDOTH,    BOSS_LAVA_GUARD_GORDOTH    },
    { 0,                         0                          }  // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_ADAROGG,               {{ 1443 }}  },
    { BOSS_DARK_SHAMAN_KORANTHAL, {{ 1444 }}  },
    { BOSS_SLAGMAW,               {{ 1445 }}  },
    { BOSS_LAVA_GUARD_GORDOTH,    {{ 1446 }}  }
};

class instance_ragefire_chasm : public InstanceMapScript
{
public:
    instance_ragefire_chasm() : InstanceMapScript("instance_ragefire_chasm", 389) { }

    struct instance_ragefire_chasm_InstanceMapScript : public InstanceScript
    {
        instance_ragefire_chasm_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_ragefire_chasm_InstanceMapScript(map);
    }
};

void AddSC_instance_ragefire_chasm()
{
    new instance_ragefire_chasm();
}
