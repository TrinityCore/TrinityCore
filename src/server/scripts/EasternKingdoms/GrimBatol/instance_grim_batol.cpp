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
#include "grim_batol.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_GENERAL_UMBRISS,      BOSS_GENERAL_UMBRISS        },
    { NPC_FORGEMASTER_THRONGUS, BOSS_FORGEMASTER_THRONGUS   },
    { NPC_DRAHGA_SHADOWBURNER,  BOSS_DRAHGA_SHADOWBURNER    },
    { NPC_ERUDAX,               BOSS_ERUDAX                 },
    { 0,                        0                           } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_GENERAL_UMBRISS,         {{ 1051 }}  },
    { BOSS_FORGEMASTER_THRONGUS,    {{ 1050 }}  },
    { BOSS_DRAHGA_SHADOWBURNER,     {{ 1048 }}  },
    { BOSS_ERUDAX,                  {{ 1049 }}  }
};

class instance_grim_batol : public InstanceMapScript
{
public:
    instance_grim_batol() : InstanceMapScript(GBTScriptName, 670) { }

    struct instance_grim_batol_InstanceMapScript : public InstanceScript
    {
        instance_grim_batol_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_grim_batol_InstanceMapScript(map);
    }
};

void AddSC_instance_grim_batol()
{
    new instance_grim_batol();
}
