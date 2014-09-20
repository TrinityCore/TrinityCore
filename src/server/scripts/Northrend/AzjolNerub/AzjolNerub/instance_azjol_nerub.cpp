/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "azjol_nerub.h"

DoorData const doorData[] =
{
    { GO_KRIKTHIR_DOOR,     DATA_KRIKTHIR_THE_GATEWATCHER,  DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_ANUBARAK_DOOR_1,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_ANUBARAK_DOOR_2,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_ANUBARAK_DOOR_3,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { 0,                    0,                              DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

ObjectData const creatureData[] =
{
    { NPC_KRIKTHIR,        DATA_KRIKTHIR_THE_GATEWATCHER },
    { NPC_WATCHER_NARJIL,  DATA_WATCHER_GASHRA           },
    { NPC_WATCHER_GASHRA,  DATA_WATCHER_SILTHIK          },
    { NPC_WATCHER_SILTHIK, DATA_WATCHER_NARJIL           },
    { 0,                   0                             } // END
};

class instance_azjol_nerub : public InstanceMapScript
{
    public:
        instance_azjol_nerub() : InstanceMapScript(AzjolNerubScriptName, 601) { }

        struct instance_azjol_nerub_InstanceScript : public InstanceScript
        {
            instance_azjol_nerub_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, nullptr);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_azjol_nerub_InstanceScript(map);
        }
};

void AddSC_instance_azjol_nerub()
{
   new instance_azjol_nerub();
}
