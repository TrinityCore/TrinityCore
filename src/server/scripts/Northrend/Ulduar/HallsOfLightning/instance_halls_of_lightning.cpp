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
#include "CreatureAI.h"
#include "GameObject.h"
#include "halls_of_lightning.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_VOLKHAN_DOOR, DATA_VOLKHAN, DOOR_TYPE_PASSAGE },
    { GO_IONAR_DOOR,   DATA_IONAR,   DOOR_TYPE_PASSAGE },
    { GO_LOKEN_DOOR,   DATA_LOKEN,   DOOR_TYPE_PASSAGE },
    { 0,               0,            DOOR_TYPE_ROOM    } // END
};

ObjectData const creatureData[] =
{
    { NPC_VOLKHAN,          DATA_VOLKHAN        },
    { NPC_VOLKHANS_ANVIL,   DATA_VOLKHANS_ANVIL },
    { 0,                    0                   } // END
};

ObjectData const gameObjectData[] =
{
    { GO_VOLKHAN_TEMPER_VISUAL, DATA_VOLKHAN_TEMPER_VISUAL },
    { 0,                        0                          } // END
};

class instance_halls_of_lightning : public InstanceMapScript
{
    public:
        instance_halls_of_lightning() : InstanceMapScript(HoLScriptName, 602) { }

        struct instance_halls_of_lightning_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_lightning_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_BJARNGRIM:
                        GeneralBjarngrimGUID = creature->GetGUID();
                        break;
                    case NPC_IONAR:
                        IonarGUID = creature->GetGUID();
                        break;
                    case NPC_LOKEN:
                        LokenGUID = creature->GetGUID();
                        break;
                    case NPC_MOLTEN_GOLEM:
                        if (GetBossState(DATA_VOLKHAN) == IN_PROGRESS)
                        {
                            if (Creature* volkhan = GetCreature(DATA_VOLKHAN))
                                if (CreatureAI* ai = volkhan->AI())
                                    ai->JustSummoned(creature);
                        }
                        else // These golems are summoned via trigger missile so we have to clean them up if they spawned during a wipe/completion
                            creature->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_LOKEN_THRONE:
                        LokenGlobeGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_LOKEN:
                        if (state == DONE)
                            if (GameObject* globe = instance->GetGameObject(LokenGlobeGUID))
                                globe->SendCustomAnim(0);
                        break;
                    default:
                        break;
                }

                return true;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BJARNGRIM:
                        return GeneralBjarngrimGUID;
                    case DATA_IONAR:
                        return IonarGUID;
                    case DATA_LOKEN:
                        return LokenGUID;
                    default:
                        break;
                }
                return InstanceScript::GetGuidData(type);
            }

        protected:
            ObjectGuid GeneralBjarngrimGUID;
            ObjectGuid IonarGUID;
            ObjectGuid LokenGUID;

            ObjectGuid LokenGlobeGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_lightning_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_lightning()
{
    new instance_halls_of_lightning();
}
