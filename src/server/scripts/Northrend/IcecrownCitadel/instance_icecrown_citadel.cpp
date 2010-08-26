/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

class instance_icecrown_citadel : public InstanceMapScript
{
    public:
        instance_icecrown_citadel() : InstanceMapScript("instance_icecrown_citadel", 631) { }

        struct instance_icecrown_citadel_InstanceMapScript : public InstanceScript
        {
            instance_icecrown_citadel_InstanceMapScript(InstanceMap* pMap) : InstanceScript(pMap)
            {
                memset(uiEncounterState, 0, MAX_ENCOUNTER*sizeof(uint32));
                memset(uiIcewall, 0, 2*sizeof(uint32));
                uiMarrowgarEntrance = 0;
                uiLadyDeathwisperElevator = 0;
                uiOratoryDoor = 0;
                uiDeathbringerSaurfang = 0;
                uiSaurfangDoor = 0;
                uiSaurfangEventNPC = 0;
                uiDeathbringersCache = 0;
                uiSaurfangTeleport = 0;
                isBonedEligible = false;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (uiEncounterState[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature, bool add)
            {
                Map::PlayerList const &players = instance->GetPlayers();
                uint32 TeamInInstance = 0;

                if (!players.isEmpty())
                {
                    if (Player* pPlayer = players.begin()->getSource())
                        TeamInInstance = pPlayer->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_DEATHBRINGER_SAURFANG:
                        uiDeathbringerSaurfang = creature->GetGUID();
                        break;
                    case NPC_SE_HIGH_OVERLORD_SAURFANG:
                        if (TeamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SE_MURADIN_BRONZEBEARD, ALLIANCE);
                    case NPC_SE_MURADIN_BRONZEBEARD:
                        uiSaurfangEventNPC = creature->GetGUID();
                        creature->LastUsedScriptID = creature->GetScriptId();
                        break;
                    case NPC_SE_KOR_KRON_REAVER:
                        if (TeamInInstance == ALLIANCE)
                            creature->UpdateEntry(NPC_SE_SKYBREAKER_MARINE, ALLIANCE);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* pGo, bool add)
            {
                switch (pGo->GetEntry())
                {
                    case DOODAD_ICECROWN_ICEWALL02:
                        uiIcewall[0] = pGo->GetGUID();
                        if (GetData(DATA_LORD_MARROWGAR) == DONE)
                            HandleGameObject(uiIcewall[0], true, pGo);
                        break;
                    case ICEWALL:
                        uiIcewall[1] = pGo->GetGUID();
                        if (GetData(DATA_LORD_MARROWGAR) == DONE)
                            HandleGameObject(uiIcewall[1], true, pGo);
                        break;
                    case LORD_MARROWGAR_S_ENTRANCE:
                        uiMarrowgarEntrance = pGo->GetGUID();
                        if (GetData(DATA_LORD_MARROWGAR) == DONE)
                            HandleGameObject(uiMarrowgarEntrance, true, pGo);
                        break;
                    case ORATORY_OF_THE_DAMNED_ENTRANCE:
                        uiOratoryDoor = pGo->GetGUID();
                        if (GetData(DATA_LADY_DEATHWHISPER) == DONE)
                            HandleGameObject(uiOratoryDoor, true, pGo);
                        break;
                    case LADY_DEATHWHISPER_ELEVATOR:
                        uiLadyDeathwisperElevator = pGo->GetGUID();
                        if (GetData(DATA_LADY_DEATHWHISPER) == DONE)
                        {
                            pGo->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            pGo->SetGoState(GO_STATE_READY);
                        }
                        break;
                    case SAURFANG_S_DOOR:
                        uiSaurfangDoor = pGo->GetGUID();
                        break;
                    case DEATHBRINGER_S_CACHE_10N:
                    case DEATHBRINGER_S_CACHE_25N:
                    case DEATHBRINGER_S_CACHE_10H:
                    case DEATHBRINGER_S_CACHE_25H:
                        uiDeathbringersCache = pGo->GetGUID();
                        break;
                    case SCOURGE_TRANSPORTER_SAURFANG:
                        uiSaurfangTeleport = pGo->GetGUID();
                        if (GetData(DATA_DEATHBRINGER_SAURFANG) == DONE)
                        {
                            HandleGameObject(uiSaurfangTeleport, true, pGo);
                            pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                        }
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_LORD_MARROWGAR:
                    case DATA_LADY_DEATHWHISPER:
                    case DATA_GUNSHIP_EVENT:
                    case DATA_DEATHBRINGER_SAURFANG:
                    case DATA_FESTERGUT:
                    case DATA_ROTFACE:
                    case DATA_PROFESSOR_PUTRICIDE:
                    case DATA_BLOOD_PRINCE_COUNCIL:
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                    case DATA_VALITHRIA_DREAMWALKER:
                    case DATA_SINDRAGOSA:
                    case DATA_THE_LICH_KING:
                        return uiEncounterState[type];
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case DATA_DEATHBRINGER_SAURFANG:
                        return uiDeathbringerSaurfang;
                    case DATA_SAURFANG_EVENT_NPC:
                        return uiSaurfangEventNPC;
                    case DATA_SAURFANG_DOOR:
                        return uiSaurfangDoor;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case DATA_LORD_MARROWGAR:
                        uiEncounterState[type] = data;
                        switch (data)
                        {
                            case DONE:
                                HandleGameObject(uiIcewall[0], true);
                                HandleGameObject(uiIcewall[1], true);
                                HandleGameObject(uiMarrowgarEntrance, true);
                                break;
                            case NOT_STARTED:
                                HandleGameObject(uiIcewall[0], false);
                                HandleGameObject(uiIcewall[1], false);
                                HandleGameObject(uiMarrowgarEntrance, true);
                                break;
                            case IN_PROGRESS:
                                HandleGameObject(uiMarrowgarEntrance, false);
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_LADY_DEATHWHISPER:
                        uiEncounterState[type] = data;
                        switch (data)
                        {
                            case DONE:
                                // TEMPORARY, UNCOMMMENT IF YOU WANT TO DO SAURFANG AND SKIP GUNSHIP
                                //uiEncounterState[DATA_GUNSHIP_EVENT] = DONE;
                                HandleGameObject(uiOratoryDoor, true);
                                if (GameObject* elevator = instance->GetGameObject(uiLadyDeathwisperElevator))
                                {
                                    elevator->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                                    elevator->SetGoState(GO_STATE_READY);
                                }
                                break;
                            case IN_PROGRESS:
                                HandleGameObject(uiOratoryDoor, false);
                                break;
                            case NOT_STARTED:
                                HandleGameObject(uiOratoryDoor, true);
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_GUNSHIP_EVENT:
                        uiEncounterState[type] = data;
                        break;
                    case DATA_DEATHBRINGER_SAURFANG:
                        uiEncounterState[type] = data;
                        switch (data)
                        {
                            case DONE:
                                if (GameObject* lootCache = instance->GetGameObject(uiDeathbringersCache))
                                    if (!lootCache->isSpawned())
                                        lootCache->SetRespawnTime(7*DAY);
                            case NOT_STARTED:
                                if (GameObject* teleporter = instance->GetGameObject(uiSaurfangTeleport))
                                {
                                    HandleGameObject(uiSaurfangTeleport, true, teleporter);
                                    teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                }
                                break;
                            case IN_PROGRESS:
                                if (GameObject* teleporter = instance->GetGameObject(uiSaurfangTeleport))
                                {
                                    HandleGameObject(uiSaurfangTeleport, false, teleporter);
                                    teleporter->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_FESTERGUT:
                    case DATA_ROTFACE:
                    case DATA_PROFESSOR_PUTRICIDE:
                    case DATA_BLOOD_PRINCE_COUNCIL:
                    case DATA_BLOOD_QUEEN_LANA_THEL:
                    case DATA_VALITHRIA_DREAMWALKER:
                    case DATA_SINDRAGOSA:
                    case DATA_THE_LICH_KING:
                        uiEncounterState[type] = data;
                        break;

                    case COMMAND_FAIL_BONED:
                        isBonedEligible = data ? true : false;
                        break;
                    default:
                        break;
                }

                if (data == DONE && type < MAX_ENCOUNTER)
                    SaveToDB();
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
            {
                switch (criteria_id)
                {
                    case CRITERIA_BONED_10N:
                    case CRITERIA_BONED_25N:
                    case CRITERIA_BONED_10H:
                    case CRITERIA_BONED_25H:
                        return isBonedEligible;
                    default:
                        break;
                }

                return false;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "I C ";
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    saveStream << uiEncounterState[i] << " ";

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'I' && dataHead2 == 'C')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS)
                            tmpState = NOT_STARTED;
                        uiEncounterState[i] = tmpState;
                    }
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint32 uiEncounterState[MAX_ENCOUNTER];
            uint64 uiIcewall[2];
            uint64 uiMarrowgarEntrance;
            uint64 uiLadyDeathwisperElevator;
            uint64 uiOratoryDoor;
            uint64 uiDeathbringerSaurfang;
            uint64 uiSaurfangDoor;
            uint64 uiSaurfangEventNPC;  // Muradin Bronzebeard or High Overlord Saurfang
            uint64 uiDeathbringersCache;
            uint64 uiSaurfangTeleport;
            bool isBonedEligible;
        };

        InstanceScript* GetInstanceScript(InstanceMap* pMap) const
        {
            return new instance_icecrown_citadel_InstanceMapScript(pMap);
        }
};

void AddSC_instance_icecrown_citadel()
{
    new instance_icecrown_citadel();
}
