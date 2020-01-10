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
                    PrisonerDied(unit->GetGUID());
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
                ResetPrisoners(PrisonersCell5);
                PrisonerCounter5 = PrisonersCell5.size();
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL5 - DATA_PRISON_CELL1], false);

                ResetPrisoners(PrisonersCell6);
                PrisonerCounter6 = PrisonersCell6.size();
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL6 - DATA_PRISON_CELL1], false);

                ResetPrisoners(PrisonersCell7);
                PrisonerCounter7 = PrisonersCell7.size();
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL7 - DATA_PRISON_CELL1], false);

                ResetPrisoners(PrisonersCell8);
                PrisonerCounter8 = PrisonersCell8.size();
                HandleGameObject(PrisonCellGUIDs[DATA_PRISON_CELL8 - DATA_PRISON_CELL1], false);
            }

            void ResetPrisoners(GuidSet& prisoners)
            {
                for (GuidSet::const_iterator i = prisoners.begin(); i != prisoners.end();)
                {
                    if (Creature * prisoner = instance->GetCreature(*i))
                    {
                        if (!prisoner->IsAlive())
                            i = prisoners.erase(i);
                        else
                            ++i;

                        ResetPrisoner(prisoner);
                    }
                    else
                        ++i;
                }
            }

            void ResetPrisoner(Creature* prisoner)
            {
                if (!prisoner->IsAlive())
                    prisoner->Respawn(true);
                prisoner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                prisoner->SetImmuneToAll(true);
                if (prisoner->IsAIEnabled())
                    prisoner->AI()->EnterEvadeMode();
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
                        PrisonersCell5.insert(creature->GetGUID());
                        ++PrisonerCounter5;
                    }
                    else if (posY >= 76.0f && posY <= 91.0f && posZ <= 17)
                    {
                        PrisonersCell6.insert(creature->GetGUID());
                        ++PrisonerCounter6;
                    }
                    else return;
                }
                else if (posX >= 490.0f && posX <= 506.0f && posZ <= 17)
                {
                    if (posY >= 106.0f && posY <= 123.0f && posZ <= 17)
                    {
                        PrisonersCell7.insert(creature->GetGUID());
                        ++PrisonerCounter7;
                    }
                    else if (posY >= 76.0f && posY <= 91.0f && posZ <= 17)
                    {
                        PrisonersCell8.insert(creature->GetGUID());
                        ++PrisonerCounter8;
                    }
                    else
                        return;
                }
                else
                    return;

                ResetPrisoner(creature);
            }

            void PrisonerDied(ObjectGuid guid)
            {
                if (PrisonersCell5.find(guid) != PrisonersCell5.end() && --PrisonerCounter5 <= 0)
                    ActivateCell(DATA_PRISON_CELL6);
                else if (PrisonersCell6.find(guid) != PrisonersCell6.end() && --PrisonerCounter6 <= 0)
                    ActivateCell(DATA_PRISON_CELL7);
                else if (PrisonersCell7.find(guid) != PrisonersCell7.end() && --PrisonerCounter7 <= 0)
                    ActivateCell(DATA_PRISON_CELL8);
                else if (PrisonersCell8.find(guid) != PrisonersCell8.end() && --PrisonerCounter8 <= 0)
                    ActivateCell(DATA_DOOR_4);
            }

            void ActivateCell(uint8 id)
            {
                switch (id)
                {
                    case DATA_PRISON_CELL5:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(PrisonersCell5);
                        break;
                    case DATA_PRISON_CELL6:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(PrisonersCell6);
                        break;
                    case DATA_PRISON_CELL7:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(PrisonersCell7);
                        break;
                    case DATA_PRISON_CELL8:
                        HandleGameObject(PrisonCellGUIDs[id - DATA_PRISON_CELL1], true);
                        ActivatePrisoners(PrisonersCell8);
                        break;
                    case DATA_DOOR_4:
                        HandleGameObject(PrisonDoor4GUID, true);
                        if (Creature* broggok = instance->GetCreature(BroggokGUID))
                            broggok->AI()->DoAction(ACTION_ACTIVATE_BROGGOK);
                        break;
                }
            }

            void ActivatePrisoners(GuidSet const& prisoners)
            {
                for (GuidSet::const_iterator i = prisoners.begin(); i != prisoners.end(); ++i)
                    if (Creature* prisoner = instance->GetCreature(*i))
                    {
                        prisoner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        prisoner->SetImmuneToAll(false);
                        prisoner->AI()->DoZoneInCombat();
                    }
            }

        protected:
            ObjectGuid TheMakerGUID;
            ObjectGuid BroggokGUID;
            ObjectGuid KelidanTheBreakerGUID;

            ObjectGuid BroggokLeverGUID;
            ObjectGuid PrisonDoor4GUID;

            ObjectGuid PrisonCellGUIDs[8];

            GuidSet PrisonersCell5;
            GuidSet PrisonersCell6;
            GuidSet PrisonersCell7;
            GuidSet PrisonersCell8;

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
