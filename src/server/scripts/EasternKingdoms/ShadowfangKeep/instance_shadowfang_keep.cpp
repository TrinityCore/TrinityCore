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
#include "shadowfang_keep.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_BARON_ASHBURY,        BOSS_BARON_ASHBURY          },
    { NPC_BARON_SILVERLAINE,    BOSS_BARON_SILVERLAINE      },
    { NPC_COMMANDER_SPRINGVALE, BOSS_COMMANDER_SPRINGVALE   },
    { NPC_LORD_WALDEN,          BOSS_LORD_WALDEN            },
    { NPC_LORD_GODFREY,         BOSS_LORD_GODFREY           },
    { 0,                        0                           } // END
};

ObjectData const gameobjectData[] =
{
    { GO_COURTYARD_DOOR,    DATA_COURTYARD_DOOR },
    { GO_SORCERERS_DOOR,    DATA_SORCERER_GATE  },
    { GO_ARUGALS_LAIR,      DATA_ARUGAL_DOOR    },
    { 0,                    0                   } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_BARON_ASHBURY,           {{ 1069 }}  },
    { BOSS_BARON_SILVERLAINE,       {{ 1070 }}  },
    { BOSS_COMMANDER_SPRINGVALE,    {{ 1071 }}  },
    { BOSS_LORD_WALDEN,             {{ 1073 }}  },
    { BOSS_LORD_GODFREY,            {{ 1072 }}  },
    { BOSS_APOTHECARY_HUMMEL,       {{ 2879 }}  }
};

class instance_shadowfang_keep : public InstanceMapScript
{
public:
    instance_shadowfang_keep() : InstanceMapScript(SFKScriptName, 33) { }

    struct instance_shadowfang_keep_InstanceMapScript : public InstanceScript
    {
        instance_shadowfang_keep_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, gameobjectData);
            LoadDungeonEncounterData(encounters);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadowfang_keep_InstanceMapScript(map);
    }
};

void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}
