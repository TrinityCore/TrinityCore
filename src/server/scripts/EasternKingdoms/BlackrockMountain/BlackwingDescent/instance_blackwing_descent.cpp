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
#include "blackwing_descent.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_MAGMAW,       BOSS_MAGMAW         },
    { NPC_CHIMAERON,    BOSS_CHIMAERON      },
    { NPC_ATRAMEDES,    BOSS_ATRAMEDES      },
    { NPC_MALORIAK,     BOSS_MAGMAW         },
    { NPC_NEFARIAN,     BOSS_NEFARIANS_END  },
    { 0,                0                   } // END
};

DoorData const doorData[] =
{
    { GO_INNER_CHAMBER_DOOR,    BOSS_MAGMAW,                    EncounterDoorBehavior::OpenWhenDone             },
    { GO_INNER_CHAMBER_DOOR,    BOSS_OMNOTRON_DEFENSE_SYSTEM,   EncounterDoorBehavior::OpenWhenDone             },
    { GO_ATHENAEUM_DOOR,        BOSS_ATRAMEDES,                 EncounterDoorBehavior::OpenWhenInProgress       },
    { 0,                        0,                              EncounterDoorBehavior::OpenWhenNotInProgress    }  // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_MAGMAW,                  {{ 1024 }}  },
    { BOSS_OMNOTRON_DEFENSE_SYSTEM, {{ 1027 }}  },
    { BOSS_CHIMAERON,               {{ 1023 }}  },
    { BOSS_ATRAMEDES,               {{ 1022 }}  },
    { BOSS_MALORIAK,                {{ 1025 }}  },
    { BOSS_NEFARIANS_END,           {{ 1026 }}  }
};

class instance_blackwing_descent : public InstanceMapScript
{
public:
    instance_blackwing_descent() : InstanceMapScript(BWDScriptName, 669) { }

    struct instance_blackwing_descent_InstanceMapScript : public InstanceScript
    {
        instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
        return new instance_blackwing_descent_InstanceMapScript(map);
    }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}
