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
#include "Creature.h"
#include "InstanceScript.h"
#include "the_eye.h"

/* The Eye encounters:
0 - Al'ar
1 - Void Reaver
2 - Solarian
3 - Kael'thas
*/

DoorData const doorData[] =
{
    { GO_ARCANE_DOOR_LEFT,  DATA_KAELTHAS, DOOR_TYPE_ROOM/*, BOUNDARY_SW  */ },
    { GO_ARCANE_DOOR_RIGHT, DATA_KAELTHAS, DOOR_TYPE_ROOM/*, BOUNDARY_SE  */ },
    {                    0,             0, DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_ALAR,        DATA_ALAR        },
    { NPC_VOID_REAVER, DATA_VOID_REAVER },
    { NPC_SOLARIAN,    DATA_SOLARIAN    },
    { NPC_KAELTHAS,    DATA_KAELTHAS    },
    { NPC_CAPERNIAN,   DATA_CAPERNIAN   },
    { NPC_SANGUINAR,   DATA_SANGUINAR   },
    { NPC_TELONICUS,   DATA_TELONICUS   },
    { NPC_THALADRED,   DATA_THALADRED   },
    { 0,               0                } // END
};

ObjectData const gameObjectData[] =
{
    { GO_KAEL_STATUE_RIGHT,      DATA_KAEL_STATUE_RIGHT     },
    { GO_KAEL_STATUE_LEFT,       DATA_KAEL_STATUE_LEFT      },
    { GO_TEMPEST_BRIDDGE_WINDOW, DATA_TEMPEST_BRIDGE_WINDOW },
    {                         0, 0                          } // END
};

class instance_the_eye : public InstanceMapScript
{
    public:
        instance_the_eye() : InstanceMapScript(TheEyeScriptName, 550) { }

        struct instance_the_eye_InstanceMapScript : public InstanceScript
        {
            instance_the_eye_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_the_eye_InstanceMapScript(map);
        }
};

void AddSC_instance_the_eye()
{
    new instance_the_eye;
}
