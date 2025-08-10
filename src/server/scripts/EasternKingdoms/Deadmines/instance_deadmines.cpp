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
#include "deadmines.h"
#include "InstanceScript.h"

ObjectData const creatureData[] =
{
    { NPC_GLUBTOK,              BOSS_GLUBTOK            },
    { NPC_HELIX_GEARBREAKER,    BOSS_HELIX_GEARBREAKER  },
    { NPC_FOE_REAPER_5000,      BOSS_FOE_REAPER_5000    },
    { NPC_ADMIRAL_RIPSNARL,     BOSS_ADMIRAL_RIPSNARL   },
    { NPC_CAPTAIN_COOKIE,       BOSS_CAPTAIN_COOKIE     },
    { NPC_VANESSA_VAN_CLEEF,    BOSS_VANESSA_VANCLEEF   },
    { 0,                        0                       } // END
};

DoorData const doorData[] =
{
    { GO_FACTORY_DOOR,      BOSS_GLUBTOK,           EncounterDoorBehavior::OpenWhenDone             },
    { GO_MAST_ROOM_DOOR,    BOSS_HELIX_GEARBREAKER, EncounterDoorBehavior::OpenWhenDone             },
    { GO_HEAVY_DOOR,        BOSS_HELIX_GEARBREAKER, EncounterDoorBehavior::OpenWhenNotInProgress    },
    { GO_FOUNDRY_DOOR,      BOSS_FOE_REAPER_5000,   EncounterDoorBehavior::OpenWhenDone             },
    { 0,                    0,                      EncounterDoorBehavior::OpenWhenDone             } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_GLUBTOK,             {{ 1064 }}  },
    { BOSS_HELIX_GEARBREAKER,   {{ 1065 }}  },
    { BOSS_FOE_REAPER_5000,     {{ 1063 }}  },
    { BOSS_ADMIRAL_RIPSNARL,    {{ 1062 }}  },
    { BOSS_CAPTAIN_COOKIE,      {{ 1060 }}  },
    { BOSS_VANESSA_VANCLEEF,    {{ 1081 }}  }
};

class instance_deadmines : public InstanceMapScript
{
public:
    instance_deadmines() : InstanceMapScript(DMScriptName, 36) {  }

    struct instance_deadmines_InstanceMapScript : public InstanceScript
    {
        instance_deadmines_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
        return new instance_deadmines_InstanceMapScript(map);
    }
};

void AddSC_instance_deadmines()
{
    new instance_deadmines();
}
