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

static const DoorData doorData[8] =
{
    {GO_LORD_MARROWGAR_S_ENTRANCE,        DATA_LORD_MARROWGAR,        DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {GO_ICEWALL,                          DATA_LORD_MARROWGAR,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_DOODAD_ICECROWN_ICEWALL02,        DATA_LORD_MARROWGAR,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE},
    {GO_ORATORY_OF_THE_DAMNED_ENTRANCE,   DATA_LADY_DEATHWHISPER,     DOOR_TYPE_ROOM,    BOUNDARY_N   },
    {0,                                   0,                          DOOR_TYPE_ROOM,    BOUNDARY_NONE} // END
};

class instance_icecrown_citadel : public InstanceMapScript
{
    public:
        instance_icecrown_citadel() : InstanceMapScript("instance_icecrown_citadel", 631) { }

        struct instance_icecrown_citadel_InstanceMapScript : public InstanceScript
        {
            instance_icecrown_citadel_InstanceMapScript(InstanceMap* pMap) : InstanceScript(pMap)
            {
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);
                uiLadyDeathwisperElevator = 0;
                uiDeathbringerSaurfang = 0;
                uiSaurfangDoor = 0;
                uiSaurfangEventNPC = 0;
                uiDeathbringersCache = 0;
                uiSaurfangTeleport = 0;
                isBonedEligible = false;
            }

            void OnCreatureCreate(Creature* creature, bool /*add*/)
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
                    case GO_DOODAD_ICECROWN_ICEWALL02:
                    case GO_ICEWALL:
                    case GO_LORD_MARROWGAR_S_ENTRANCE:
                    case GO_ORATORY_OF_THE_DAMNED_ENTRANCE:
                        AddDoor(pGo, add);
                        break;
                    case GO_LADY_DEATHWHISPER_ELEVATOR:
                        uiLadyDeathwisperElevator = pGo->GetGUID();
                        if (GetBossState(DATA_LADY_DEATHWHISPER) == DONE)
                        {
                            pGo->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            pGo->SetGoState(GO_STATE_READY);
                        }
                        break;
                    case GO_SAURFANG_S_DOOR:
                        uiSaurfangDoor = pGo->GetGUID();
                        break;
                    case GO_DEATHBRINGER_S_CACHE_10N:
                    case GO_DEATHBRINGER_S_CACHE_25N:
                    case GO_DEATHBRINGER_S_CACHE_10H:
                    case GO_DEATHBRINGER_S_CACHE_25H:
                        uiDeathbringersCache = pGo->GetGUID();
                        break;
                    case GO_SCOURGE_TRANSPORTER_SAURFANG:
                        uiSaurfangTeleport = pGo->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case DATA_DEATHBRINGER_SAURFANG:
                        return uiDeathbringerSaurfang;
                    case DATA_SAURFANG_EVENT_NPC:
                        return uiSaurfangEventNPC;
                    case GO_SAURFANG_S_DOOR:
                        return uiSaurfangDoor;
                    case GO_SCOURGE_TRANSPORTER_SAURFANG:
                        return uiSaurfangTeleport;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_LADY_DEATHWHISPER:
                        SetBossState(DATA_GUNSHIP_EVENT, state);    // TEMP HACK UNTIL GUNSHIP SCRIPTED
                        if (state == DONE)
                            if (GameObject* elevator = instance->GetGameObject(uiLadyDeathwisperElevator))
                            {
                                elevator->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                                elevator->SetGoState(GO_STATE_READY);
                            }
                        break;
                    case DATA_DEATHBRINGER_SAURFANG:
                        switch (state)
                        {
                            case DONE:
                                DoRespawnGameObject(uiDeathbringersCache, 7*DAY);
                            case NOT_STARTED:
                                if (GameObject* teleporter = instance->GetGameObject(uiSaurfangTeleport))
                                {
                                    HandleGameObject(uiSaurfangTeleport, true, teleporter);
                                    teleporter->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
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
                        break;
                 }

                 return true;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case COMMAND_FAIL_BONED:
                        isBonedEligible = data ? true : false;
                        break;
                    default:
                        break;
                }
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
                saveStream << "I C " << GetBossSaveData();

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
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 uiLadyDeathwisperElevator;
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
