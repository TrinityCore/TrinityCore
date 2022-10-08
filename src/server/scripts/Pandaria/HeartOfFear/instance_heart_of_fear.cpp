/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "VMapFactory.h"
#include "heart_of_fear.h"

DoorData const doorData[] =
{
    {GOB_ANTECHAMBER_DOOR_ENTRANCE, 0,              DOOR_TYPE_ROOM      },
    {GOB_ANTECHAMBER_DOOR_EXIT,     0,              DOOR_TYPE_ROOM      },
    {GOB_ORATIUM_DOOR_ENTRANCE,     DATA_ZORLOK,    DOOR_TYPE_ROOM      },
    {GOB_QUARTERS_DOOR_ENTRANCE,    DATA_ZORLOK,    DOOR_TYPE_PASSAGE   },
    {GOB_QUARTERS_DOOR_EXIT,        DATA_TAYAK,     DOOR_TYPE_PASSAGE   },
    {GOB_STAIRWAYS_DOOR_EXIT,       0,              DOOR_TYPE_ROOM      },
    {GOB_BALCONY_DOOR_EXIT,         DATA_MELJARAK,  DOOR_TYPE_PASSAGE   },
    {GOB_ATRIUM_DOOR_ENTRANCE,      0,              DOOR_TYPE_ROOM      },
    {GOB_ATRIUM_DOOR_EXIT,          0,              DOOR_TYPE_ROOM      },
    {GOB_SANCTUM_DOOR_ENTRANCE,     0,              DOOR_TYPE_ROOM      },
    {GOB_HEARTOFFEAR_DOOR_ENTRANCE, DATA_UNSOK,     DOOR_TYPE_PASSAGE   }
};

class instance_heart_of_fear : public InstanceMapScript
{
    public:
        instance_heart_of_fear() : InstanceMapScript("instance_heart_of_fear", 1009) { }

        enum eMisc
        {
            HeartOfFearSecondPart = 530
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_heart_of_fear_InstanceMapScript(map);
        }

        struct instance_heart_of_fear_InstanceMapScript : public InstanceScript
        {
            instance_heart_of_fear_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

            // Boss GUIDs
            ObjectGuid zorlokGuid;
            ObjectGuid tayakGuid;
            ObjectGuid garalonGuid;
            ObjectGuid meljarakGuid;
            ObjectGuid unsokGuid;
            ObjectGuid shekzeerGuid;

            // Special Doors GUIDs
            ObjectGuid zorlokEntranceDoorGuid;
            ObjectGuid tayakEntranceDoorGuid;
            ObjectGuid tayakExitDoorGuid;
            ObjectGuid garalonEntranceDoorGuid;
            ObjectGuid meljarakExitDoorGuid;
            ObjectGuid unsokEntranceDoorGuid;
            ObjectGuid shekzeerEntranceDoorGuid;

            // Shek'zeer Gameobjects
            ObjectGuid empressChamberGuid;
            ObjectGuid mandidQueenCeilGuid;

            bool m_SecondPartInitialized;

            void Initialize() override
            {
                SetBossNumber(DATA_MAX_BOSS_DATA);
                LoadDoorData(doorData);

                m_SecondPartInitialized = false;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_ZORLOK:
                        zorlokGuid = creature->GetGUID();
                        break;
                    case NPC_TAYAK:
                        tayakGuid = creature->GetGUID();
                        break;
                    case NPC_GARALON:
                        garalonGuid = creature->GetGUID();
                        break;
                    case NPC_MELJARAK:
                        meljarakGuid = creature->GetGUID();
                        break;
                    case NPC_UNSOK:
                        unsokGuid = creature->GetGUID();
                        break;
                    case NPC_SHEKZEER:
                        shekzeerGuid = creature->GetGUID();
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
                    // Generic doors
                    case GOB_ANTECHAMBER_DOOR_ENTRANCE:
                    case GOB_ANTECHAMBER_DOOR_EXIT:
                    case GOB_ATRIUM_DOOR_ENTRANCE:
                    case GOB_ATRIUM_DOOR_EXIT:
                        AddDoor(go, true);
                        break;
                    // Specific doors
                    case GOB_ORATIUM_DOOR_ENTRANCE:
                        AddDoor(go, true);
                        zorlokEntranceDoorGuid = go->GetGUID();
                        break;
                    case GOB_QUARTERS_DOOR_ENTRANCE:
                        AddDoor(go, true);
                        tayakEntranceDoorGuid = go->GetGUID();
                        break;
                    case GOB_QUARTERS_DOOR_EXIT:
                        AddDoor(go, true);
                        tayakExitDoorGuid = go->GetGUID();
                        break;
                    case GOB_STAIRWAYS_DOOR_EXIT:
                        AddDoor(go, true);
                        go->SetGoState(GO_STATE_READY);
                        garalonEntranceDoorGuid = go->GetGUID();
                        break;
                    case GOB_BALCONY_DOOR_EXIT:
                        AddDoor(go, true);
                        go->SetGoState(GO_STATE_READY);
                        meljarakExitDoorGuid = go->GetGUID();
                        break;
                    case GOB_SANCTUM_DOOR_ENTRANCE:
                        AddDoor(go, true);
                        go->SetGoState(GO_STATE_READY);
                        unsokEntranceDoorGuid = go->GetGUID();
                        break;
                    case GOB_HEARTOFFEAR_DOOR_ENTRANCE:
                        AddDoor(go, true);
                        go->SetGoState(GO_STATE_READY);
                        shekzeerEntranceDoorGuid = go->GetGUID();
                        break;
                    case GOB_EMPRESS_CHAMBER:
                        empressChamberGuid = go->GetGUID();
                        break;
                    case GOB_MANTID_QUEEN_CEIL:
                        mandidQueenCeilGuid = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                InstanceScript::OnGameObjectRemove(go);

                switch (go->GetEntry())
                {
                    // Generic doors
                    case GOB_ANTECHAMBER_DOOR_ENTRANCE:
                    case GOB_ANTECHAMBER_DOOR_EXIT:
                    case GOB_ATRIUM_DOOR_ENTRANCE:
                    case GOB_ATRIUM_DOOR_EXIT:
                    case GOB_ORATIUM_DOOR_ENTRANCE:
                    case GOB_QUARTERS_DOOR_ENTRANCE:
                    case GOB_QUARTERS_DOOR_EXIT:
                    case GOB_STAIRWAYS_DOOR_EXIT:
                    case GOB_BALCONY_DOOR_EXIT:
                    case GOB_SANCTUM_DOOR_ENTRANCE:
                    case GOB_HEARTOFFEAR_DOOR_ENTRANCE:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                return true;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    // --- Creatures ---
                    case NPC_ZORLOK:
                        return zorlokGuid;
                    case NPC_TAYAK:
                        return tayakGuid;
                    case NPC_GARALON:
                        return garalonGuid;
                    case NPC_MELJARAK:
                        return meljarakGuid;
                    case NPC_UNSOK:
                        return unsokGuid;
                    case NPC_SHEKZEER:
                        return shekzeerGuid;
                    // --- GameObjects ---
                    case GOB_ORATIUM_DOOR_ENTRANCE:
                        return zorlokEntranceDoorGuid;
                    case GOB_QUARTERS_DOOR_ENTRANCE:
                        return tayakEntranceDoorGuid;
                    case GOB_QUARTERS_DOOR_EXIT:
                        return tayakExitDoorGuid;
                    case GOB_STAIRWAYS_DOOR_EXIT:
                        return garalonEntranceDoorGuid;
                    case GOB_BALCONY_DOOR_EXIT:
                        return meljarakExitDoorGuid;
                    case GOB_SANCTUM_DOOR_ENTRANCE:
                        return unsokEntranceDoorGuid;
                    case GOB_HEARTOFFEAR_DOOR_ENTRANCE:
                        return shekzeerEntranceDoorGuid;
                    case GOB_EMPRESS_CHAMBER:
                        return empressChamberGuid;
                    case GOB_MANTID_QUEEN_CEIL:
                        return mandidQueenCeilGuid;
                    default:
                        break;
                }

                return InstanceScript::GetGuidData(type);
            }

            /*bool IsWipe() const override
            {
                Map::PlayerList const& PlayerList = instance->GetPlayers();

                if (PlayerList.isEmpty())
                    return true;

                std::list<Player*> servantList;
                servantList.clear();

                for (Map::PlayerList::const_iterator Itr = PlayerList.begin(); Itr != PlayerList.end(); ++Itr)
                {
                    Player* player = Itr->GetSource();

                    if (!player)
                        continue;

                    if (player->IsAlive() && !player->IsGameMaster() && !player->HasAura(SPELL_CONVERT_SERVANT))
                        return false;
                    else if (player->HasAura(SPELL_CONVERT_SERVANT))
                        servantList.push_back(player);
                }

                // Killing the servant players
                if (!servantList.empty())
                    if (Creature* shekzeer = instance->GetCreature(GetData64(NPC_SHEKZEER)))
                        for (Player* servant : servantList)
                            shekzeer->Kill(servant);

                return true;
            }*/

            bool CheckRequiredBosses(uint32 bossId, Player const* player = NULL) const override
            {
                if (!InstanceScript::CheckRequiredBosses(bossId, player))
                    return false;

                switch (bossId)
                {
                    case DATA_TAYAK:
                    case DATA_GARALON:
                    case DATA_MELJARAK:
                    case DATA_UNSOK:
                    case DATA_SHEKZEER:
                        if (GetBossState(bossId - 1) != DONE)
                            return false;
                    default:
                        break;
                }

                return true;
            }

            void OnPlayerEnter(Player* player) override
            {
                InstanceScript::OnPlayerEnter(player);

                if (!m_SecondPartInitialized && instance->IsLFR())
                {
                    /*uint32 l_DungeonID = player->GetGroup() ? sLFGMgr->GetDungeon(player->GetGroup()->GetGUID()) : 0;
                    if (l_DungeonID == eMisc::HeartOfFearSecondPart)
                    {
                        m_SecondPartInitialized = true;

                        if (Creature* l_Garalon = ObjectAccessor::GetCreature(*player, garalonGuid))
                        {
                            std::list<Unit*> l_TrashMobs;

                            Trinity::AnyFriendlyUnitInObjectRangeCheck l_Check(l_Garalon, l_Garalon, 50.0f);
                            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> l_Searcher(l_Garalon, l_TrashMobs, l_Check);
                            l_Garalon->VisitNearbyObject(50.0f, l_Searcher);

                            for (Unit* l_Unit : l_TrashMobs)
                            {
                                if (l_Unit->ToCreature() == nullptr)
                                    continue;

                                /// Basic settings
                                l_Unit->SetVisible(false);
                                l_Unit->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                                l_Unit->ToCreature()->SetReactState(REACT_PASSIVE);
                            }

                            std::list<GameObject*> l_DoorList;
                            GetGameObjectListWithEntryInGrid(l_DoorList, l_Garalon, GOB_DOOR_TO_MELJARAK, 200.0f);

                            for (GameObject* l_Door : l_DoorList)
                                l_Door->SetGoState(GO_STATE_ACTIVE);
                        }
                    }*/
                }
            }

            void OnPlayerExit(Player* player) override
            {
                InstanceScript::OnPlayerExit(player);

                if (player->HasAura(SPELL_RESHAPE_LIFE))
                    player->RemoveAura(SPELL_RESHAPE_LIFE);
            }
        };
};

void AddSC_instance_heart_of_fear()
{
    new instance_heart_of_fear();
}
