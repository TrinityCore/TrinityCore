/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "sethekk_halls.h"

DoorData const doorData[] =
{
    {GO_IKISS_DOOR, DATA_TALON_KING_IKISS,  DOOR_TYPE_PASSAGE,  BOUNDARY_S     },
    {0,             0,                      DOOR_TYPE_ROOM,     BOUNDARY_NONE  },
};

class instance_sethekk_halls : public InstanceMapScript
{
    public:
        instance_sethekk_halls() : InstanceMapScript(SHScriptName, 556) { }

        struct instance_sethekk_halls_InstanceMapScript : public InstanceScript
        {
            instance_sethekk_halls_InstanceMapScript(Map* map) : InstanceScript(map) 
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                AnzuEncounterState = NOT_STARTED;
                TallonKingsCofferGUID = 0;
            }

            void OnCreatureCreate(Creature* creature)
            {
                if (creature->GetEntry() == NPC_ANZU)
                {
                    if (AnzuEncounterState >= IN_PROGRESS)
                        creature->DisappearAndDie();
                    else
                        AnzuEncounterState = IN_PROGRESS;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_IKISS_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_TALON_KINGS_COFFER:
                        TallonKingsCofferGUID = go->GetGUID();
                        break;
                    default:
                        break;   
                }
            }
            
            void OnGameObjectRemove(GameObject* go)
            {
                if (go->GetEntry() == GO_IKISS_DOOR)
                    AddDoor(go, false);
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (type == DATA_TALON_KING_IKISS)
                    if (state == DONE)
                        if (GameObject* go = instance->GetGameObject(TallonKingsCofferGUID))
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN);

                
                return true;
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_ANZU)
                    AnzuEncounterState = data;
            }

        protected:
            uint32 AnzuEncounterState;
            uint64 TallonKingsCofferGUID;
        };
        
        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_sethekk_halls_InstanceMapScript(map);
        }
};

void AddSC_instance_sethekk_halls()
{
    new instance_sethekk_halls();
}
