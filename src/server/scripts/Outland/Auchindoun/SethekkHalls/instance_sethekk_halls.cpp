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
#include "sethekk_halls.h"

DoorData const doorData[] =
{
    { GO_IKISS_DOOR,    DATA_TALON_KING_IKISS,  DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { 0,                0,                      DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

class instance_sethekk_halls : public InstanceMapScript
{
    public:
        instance_sethekk_halls() : InstanceMapScript(SHScriptName, 556) { }

        struct instance_sethekk_halls_InstanceMapScript : public InstanceScript
        {
            instance_sethekk_halls_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (creature->GetEntry() == NPC_ANZU)
                {
                    if (GetBossState(DATA_ANZU) == DONE)
                        creature->DisappearAndDie();
                    else
                        SetBossState(DATA_ANZU, IN_PROGRESS);
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                 if (go->GetEntry() == GO_IKISS_DOOR)
                     AddDoor(go, true);
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                 if (go->GetEntry() == GO_IKISS_DOOR)
                     AddDoor(go, false);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_sethekk_halls_InstanceMapScript(map);
        }
};

void AddSC_instance_sethekk_halls()
{
    new instance_sethekk_halls();
}
