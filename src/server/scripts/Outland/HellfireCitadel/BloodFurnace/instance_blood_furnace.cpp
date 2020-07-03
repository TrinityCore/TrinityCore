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
#include "blood_furnace.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"

DoorData const doorData[] =
{
    { GO_PRISON_DOOR_01, DATA_KELIDAN_THE_BREAKER, DOOR_TYPE_PASSAGE },
    { GO_PRISON_DOOR_02, DATA_THE_MAKER,           DOOR_TYPE_ROOM },
    { GO_PRISON_DOOR_03, DATA_THE_MAKER,           DOOR_TYPE_PASSAGE },
    { GO_PRISON_DOOR_04, DATA_BROGGOK,             DOOR_TYPE_PASSAGE },
    { GO_PRISON_DOOR_05, DATA_BROGGOK,             DOOR_TYPE_ROOM },
    { GO_SUMMON_DOOR,    DATA_KELIDAN_THE_BREAKER, DOOR_TYPE_PASSAGE },
    { 0,                 0,                        DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_BROGGOK,             DATA_BROGGOK             },
    { 0,                       0                        } // END
};

ObjectData const gameObjectData[] =
{
    { GO_BROGGOK_LEVER,      DATA_BROGGOK_LEVER },
    { 0,                     0                  } //END
};

class instance_blood_furnace : public InstanceMapScript
{
    public:
        instance_blood_furnace() : InstanceMapScript(BFScriptName, 542) { }

        struct instance_blood_furnace_InstanceMapScript : public InstanceScript
        {
            instance_blood_furnace_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                PrisonerCounter5        = 0;
                PrisonerCounter6        = 0;
                PrisonerCounter7        = 0;
                PrisonerCounter8        = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_THE_MAKER:
                        TheMakerGUID = creature->GetGUID();
                        break;
                    case NPC_BROGGOK:
                        BroggokGUID = creature->GetGUID();
                        break;
                    case NPC_KELIDAN_THE_BREAKER:
                        KelidanTheBreakerGUID = creature->GetGUID();
                        break;
                    case NPC_PRISONER1:
                    case NPC_PRISONER2:
                        StorePrisoner(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetTypeId() == TYPEID_UNIT && (unit->GetEntry() == NPC_PRISONER1 || unit->GetEntry() == NPC_PRISONER2))
                {
                    if (Creature* prisoner = unit->ToCreature())
                    {
                        PrisonerDied(prisoner->GetSpawnId());
                    }
                }                    
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_PRISON_DOOR_04:
                        PrisonDoor4GUID = go->GetGUID();
                        break;
                    case GO_BROGGOK_LEVER:
                        BroggokLeverGUID = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_1:
                        PrisonCellGUIDs[DATA_PRISON_CELL1 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_2:
                        PrisonCellGUIDs[DATA_PRISON_CELL2 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_3:
                        PrisonCellGUIDs[DATA_PRISON_CELL3 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_4:
                        PrisonCellGUIDs[DATA_PRISON_CELL4 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_5:
                        PrisonCellGUIDs[DATA_PRISON_CELL5 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_6:
                        PrisonCellGUIDs[DATA_PRISON_CELL6 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_7:
                        PrisonCellGUIDs[DATA_PRISON_CELL7 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    case GO_PRISON_CELL_DOOR_8:
                        PrisonCellGUIDs[DATA_PRISON_CELL8 - DATA_PRISON_CELL1] = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_THE_MAKER:
                        return TheMakerGUID;
                    case DATA_BROGGOK:
                        return BroggokGUID;
                    case DATA_KELIDAN_THE_BREAKER:
                        return KelidanTheBreakerGUID;
                    case DATA_BROGGOK_LEVER:
                        return BroggokLeverGUID;
                }

                return ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_BROGGOK:
                        switch (state)
                        {
                            case IN_PROGRESS:
                                ActivateCell(DATA_PRISON_CELL5);
                                break;
                            case NOT_STARTED:
                                ResetPrisons();
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            void ResetPrisons()
            {
                PrisonerCounter5 = prisonersCellSpawnIDSet5.size();
                PrisonerCounter6 = prisonersCellSpawnIDSet6.size();
                PrisonerCounter7 = prisonersCellSpawnIDSet7.size();
                PrisonerCounter8 = prisonersCellSpawnIDSet8.size();

                ResetPrisoners(prisonersCellSpawnIDSet5);
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL5 - DATA_PRISON_CELL1], false);

                ResetPrisoners(prisonersCellSpawnIDSet6);                
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL6 - DATA_PRISON_CELL1], false);

                ResetPrisoners(prisonersCellSpawnIDSet7);                
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL7 - DATA_PRISON_CELL1], false);

                ResetPrisoners(prisonersCellSpawnIDSet8);                
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL8 - DATA_PRISON_CELL1], false);
            }

            void ResetPrisoners(std::unordered_set<uint32> pmPrisonersSpawnIDSet)
            {
                for (std::unordered_set<uint32>::iterator pIT = pmPrisonersSpawnIDSet.begin(); pIT != pmPrisonersSpawnIDSet.end(); pIT++)
                {
                    if (uint32 eachSpawnID = *pIT)
                    {
                        instance->Respawn(SpawnObjectType::SPAWN_TYPE_CREATURE, eachSpawnID);                        
                    }
                }
            }

            void StorePrisoner(Creature* creature)
            {
                float posX = creature->GetPositionX();
                float posY = creature->GetPositionY();
                float posZ = creature->GetPositionZ();

                if (posX >= 405.0f && posX <= 423.0f && posZ <= 17)
                {
                    if (posY >= 106.0f && posY <= 123.0f && posZ <= 17)
                    {
                        uint32 checkSpawnID = creature->GetSpawnId();
                        if (prisonersCellSpawnIDSet5.find(checkSpawnID) == prisonersCellSpawnIDSet5.end())
                        {
                            prisonersCellSpawnIDSet5.insert(checkSpawnID);
                        }
                        PrisonerCounter5 = prisonersCellSpawnIDSet5.size();                        
                    }
                    else if (posY >= 76.0f && posY <= 91.0f && posZ <= 17)
                    {
                        uint32 checkSpawnID = creature->GetSpawnId();
                        if (prisonersCellSpawnIDSet6.find(checkSpawnID) == prisonersCellSpawnIDSet6.end())
                        {
                            prisonersCellSpawnIDSet6.insert(checkSpawnID);
                        }
                        PrisonerCounter6 = prisonersCellSpawnIDSet6.size();                        
                    }
                    else return;
                }
                else if (posX >= 490.0f && posX <= 506.0f && posZ <= 17)
                {
                    if (posY >= 106.0f && posY <= 123.0f && posZ <= 17)
                    {
                        uint32 checkSpawnID = creature->GetSpawnId();
                        if (prisonersCellSpawnIDSet7.find(checkSpawnID) == prisonersCellSpawnIDSet7.end())
                        {
                            prisonersCellSpawnIDSet7.insert(checkSpawnID);
                        }
                        PrisonerCounter7 = prisonersCellSpawnIDSet7.size();                        
                    }
                    else if (posY >= 76.0f && posY <= 91.0f && posZ <= 17)
                    {
                        uint32 checkSpawnID = creature->GetSpawnId();
                        if (prisonersCellSpawnIDSet8.find(checkSpawnID) == prisonersCellSpawnIDSet8.end())
                        {
                            prisonersCellSpawnIDSet8.insert(checkSpawnID);
                        }
                        PrisonerCounter8 = prisonersCellSpawnIDSet8.size();
                    }
                    else
                        return;
                }
                else
                    return;

                if (!creature->IsAlive())
                {
                    creature->Respawn(true);
                }
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                creature->SetImmuneToAll(true);
                if (creature->IsAIEnabled())
                {
                    creature->AI()->EnterEvadeMode();
                }
            }

            void PrisonerDied(uint32 pmPrisonerSpawnID)
            {
                if (prisonersCellSpawnIDSet5.find(pmPrisonerSpawnID) != prisonersCellSpawnIDSet5.end() && --PrisonerCounter5 <= 0)
                    ActivateCell(DATA_PRISON_CELL6);
                else if (prisonersCellSpawnIDSet6.find(pmPrisonerSpawnID) != prisonersCellSpawnIDSet6.end() && --PrisonerCounter6 <= 0)
                    ActivateCell(DATA_PRISON_CELL7);
                else if (prisonersCellSpawnIDSet7.find(pmPrisonerSpawnID) != prisonersCellSpawnIDSet7.end() && --PrisonerCounter7 <= 0)
                    ActivateCell(DATA_PRISON_CELL8);
                else if (prisonersCellSpawnIDSet8.find(pmPrisonerSpawnID) != prisonersCellSpawnIDSet8.end() && --PrisonerCounter8 <= 0)
                    ActivateCell(DATA_DOOR_4);
            }

            void ActivateCell(uint8 id)
            {
                switch (id)
                {
                    case DATA_PRISON_CELL5:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(prisonersCellSpawnIDSet5);
                        break;
                    case DATA_PRISON_CELL6:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(prisonersCellSpawnIDSet6);
                        break;
                    case DATA_PRISON_CELL7:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(prisonersCellSpawnIDSet7);
                        break;
                    case DATA_PRISON_CELL8:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(prisonersCellSpawnIDSet8);
                        break;
                    case DATA_DOOR_4:
                        HandleGameObject(PrisonDoor4GUID, true);
                        if (Creature* broggok = instance->GetCreature(BroggokGUID))
                            broggok->AI()->DoAction(ACTION_ACTIVATE_BROGGOK);
                        break;
                }
            }

            void ActivatePrisoners(std::unordered_set<uint32> pmPrisonersSpawnIDSet)
            {
                for (std::unordered_set<uint32>::iterator pIT = pmPrisonersSpawnIDSet.begin(); pIT != pmPrisonersSpawnIDSet.end(); pIT++)
                {
                    if (uint32 eachSpawnID = *pIT)
                    {
                        if (Creature* prisoner = instance->GetCreatureBySpawnId(eachSpawnID))
                        {
                            if (prisoner->IsAlive())
                            {
                                prisoner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                prisoner->SetImmuneToAll(false);
                                prisoner->AI()->DoZoneInCombat();
                            }
                        }
                    }
                }
            }

        protected:
            ObjectGuid TheMakerGUID;
            ObjectGuid BroggokGUID;
            ObjectGuid KelidanTheBreakerGUID;

            ObjectGuid BroggokLeverGUID;
            ObjectGuid PrisonDoor4GUID;

            ObjectGuid PrisonCellGUIDs[8];

            //GuidSet PrisonersCell5;
            //GuidSet PrisonersCell6;
            //GuidSet PrisonersCell7;
            //GuidSet PrisonersCell8;

            // EJ spawn id instead of guid, corpse will despawn
            std::unordered_set<uint32> prisonersCellSpawnIDSet5;
            std::unordered_set<uint32> prisonersCellSpawnIDSet6;
            std::unordered_set<uint32> prisonersCellSpawnIDSet7;
            std::unordered_set<uint32> prisonersCellSpawnIDSet8;

            uint8 PrisonerCounter5;
            uint8 PrisonerCounter6;
            uint8 PrisonerCounter7;
            uint8 PrisonerCounter8;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_blood_furnace_InstanceMapScript(map);
        }
};

void AddSC_instance_blood_furnace()
{
    new instance_blood_furnace();
}
