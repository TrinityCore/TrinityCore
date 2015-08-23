/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Instance Trial of the Champion
SDComment:
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "trial_of_the_champion.h"
#include "Player.h"
#include "Vehicle.h"

#define MAX_ENCOUNTER  4

class instance_trial_of_the_champion : public InstanceMapScript
{
public:
    instance_trial_of_the_champion() : InstanceMapScript("instance_trial_of_the_champion", 650) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_trial_of_the_champion_InstanceMapScript(map);
    }

    struct instance_trial_of_the_champion_InstanceMapScript : public InstanceScript
    {
        instance_trial_of_the_champion_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            m_playersTeam = 0;
            uiArgentSoldierDeaths = 0;

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        uint32 m_playersTeam;
        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint8 uiArgentSoldierDeaths;

        ObjectGuid uiAnnouncerGUID;
        ObjectGuid uiMainGateGUID;
        ObjectGuid uiGrandChampionVehicle1GUID;
        ObjectGuid uiGrandChampionVehicle2GUID;
        ObjectGuid uiGrandChampionVehicle3GUID;
        ObjectGuid uiGrandChampion1GUID;
        ObjectGuid uiGrandChampion2GUID;
        ObjectGuid uiGrandChampion3GUID;
        ObjectGuid uiGrandChampionLootGUID;
        ObjectGuid uiArgentChampionGUID;
        ObjectGuid uiEadricLootGUID;
        ObjectGuid uiPaletressLootGUID;
        ObjectGuid uiTirionGUID;
        ObjectGuid uiVarianGUID;
        ObjectGuid uiJainaGUID;
        ObjectGuid uiGarroshGUID;
        ObjectGuid uiThrallGUID;

        GuidList VehicleList;

        std::string str_data;

        bool IsEncounterInProgress() const override
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
            {
                if (Player* player = players.begin()->GetSource())
                {
                    if (GetData(DATA_PLAYERS_TEAM) == 0)
                        SetData(DATA_PLAYERS_TEAM, player->GetTeam());
                }
                
            }

            switch (creature->GetEntry())
            {
                case NPC_MOKRA:
                case NPC_ERESSEA:
                case NPC_RUNOK:
                case NPC_ZULTORE:
                case NPC_VISCERI:
                case NPC_JACOB:
                case NPC_AMBROSE:
                case NPC_COLOSOS:
                case NPC_JAELYNE:
                case NPC_LANA:
                    SetGrandChampionData(creature);
                    break;
                // Coliseum Announcer || Just NPC_JAEREN must be spawned.
                case NPC_JAEREN:
                    uiAnnouncerGUID = creature->GetGUID();
                    if (GetData(DATA_PLAYERS_TEAM) == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS);
                    break;
                case VEHICLE_ARGENT_WARHORSE_COSMETIC:
                    if (GetData(DATA_PLAYERS_TEAM) == ALLIANCE)
                        creature->UpdateEntry(VEHICLE_ARGENT_WARHORSE_A);
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_ARGENT_BATTLEWORG_H:
                    if (GetData(DATA_PLAYERS_TEAM) == ALLIANCE)
                        creature->UpdateEntry(VEHICLE_ARGENT_BATTLEWORG_COSMETIC);
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case NPC_EADRIC:
                case NPC_PALETRESS:
                    uiArgentChampionGUID = creature->GetGUID();
                    break;
                case NPC_TIRION:
                    uiTirionGUID = creature->GetGUID();
                    break;
                case NPC_VARIAN:
                    uiVarianGUID = creature->GetGUID();
                    break;
                case NPC_JAINA:
                    uiJainaGUID = creature->GetGUID();
                    break;
                case NPC_GARROSH:
                    uiGarroshGUID = creature->GetGUID();
                    break;
                case NPC_THRALL:
                    uiThrallGUID = creature->GetGUID();
                    break;
                // Setting passive and unattackable flags to Lesser Champions and Grand Champions' vehicles
                case VEHICLE_DARNASSUS_CHAMPION:
                case VEHICLE_EXODAR_CHAMPION:
                case VEHICLE_STORMWIND_CHAMPION:
                case VEHICLE_GNOMEREGAN_CHAMPION:
                case VEHICLE_IRONFORGE_CHAMPION:
                case VEHICLE_UNDERCITY_CHAMPION:
                case VEHICLE_THUNDER_BLUFF_CHAMPION:
                case VEHICLE_ORGRIMMAR_CHAMPION:
                case VEHICLE_SILVERMOON_CHAMPION:
                case VEHICLE_SENJIN_CHAMPION:
                case VEHICLE_AMBROSE_BOLTSPARK_MOUNT:
                case VEHICLE_COLOSOS_MOUNT:
                case VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT:
                case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
                case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                case VEHICLE_RUNOK_WILDMANE_MOUNT:
                case VEHICLE_ZUL_TORE_MOUNT:
                case VEHICLE_EVENSONG_MOUNT:
                case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                case VEHICLE_LANA_STOUTHAMMER_MOUNT:
                    creature->SetReactState(REACT_PASSIVE);
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_MAIN_GATE:
                    uiMainGateGUID = go->GetGUID();
                    break;
                case GO_CHAMPIONS_LOOT:
                case GO_CHAMPIONS_LOOT_H:
                    uiGrandChampionLootGUID = go->GetGUID();
                    break;
                case GO_EADRIC_LOOT:
                case GO_EADRIC_LOOT_H:
                    uiEadricLootGUID = go->GetGUID();
                    break;
                case GO_PALETRESS_LOOT:
                case GO_PALETRESS_LOOT_H:
                    uiPaletressLootGUID = go->GetGUID();
                    break;
            }
        }

        void SetGrandChampionData(Creature* cr)
        {
            if (!uiGrandChampion1GUID)
                uiGrandChampion1GUID = cr->GetGUID();
            else if (!uiGrandChampion2GUID)
                uiGrandChampion2GUID = cr->GetGUID();
            else if (!uiGrandChampion3GUID)
                uiGrandChampion3GUID = cr->GetGUID();
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_PLAYERS_TEAM:
                    m_playersTeam = uiData;
                    break;
                case DATA_REMOVE_VEHICLES:
                    for (GuidList::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                    {
                        if (Creature* summon = instance->GetCreature(*itr))
                            summon->RemoveFromWorld();
                        // We must remove defense spells from players
                        Map::PlayerList const &players = instance->GetPlayers();
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player *plr = itr->GetSource();
                            if (plr && plr->IsAlive() && !plr->IsGameMaster())
                            {
                                plr->RemoveAura(62552); // Actual defense spell
                                plr->RemoveAura(63130); // Shield Level 1 (visual only)
                                plr->RemoveAura(63131); // Shield Level 2 (visual only)
                                plr->RemoveAura(63132); // Shield Level 3 (visual only)
                            }
                        }
                    }
                    break;
                case BOSS_GRAND_CHAMPIONS:
                    if (uiData == IN_PROGRESS)
                        SetData(DATA_REMOVE_VEHICLES, 0);
                    else if (uiData == DONE && GetData(BOSS_GRAND_CHAMPIONS) != DONE)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            // On heroic mode we must bind players to the instance
                            if (instance->IsHeroic())
                            {
                                Map::PlayerList const &players = instance->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                {
                                    Player *plr = itr->GetSource();
                                    if (plr && !plr->IsGameMaster())
                                    {
                                        if (instance->ToInstanceMap())
                                            instance->ToInstanceMap()->PermBindAllPlayers(plr);
                                        break;
                                    }
                                }
                            }
                            pAnnouncer->GetMotionMaster()->MovePoint(3, announcerWaitPos);
                            DoRespawnGameObject(uiGrandChampionLootGUID, 1 * DAY);
                            if (GameObject* cache = instance->GetGameObject(uiGrandChampionLootGUID))
                                cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                    }
                    m_auiEncounter[0] = uiData;
                    break;
                case DATA_ARGENT_SOLDIER_DEFEATED:
                    uiArgentSoldierDeaths = uiData;
                    if (uiArgentSoldierDeaths == 9)
                    {
                        if (Creature* pBoss =  instance->GetCreature(uiArgentChampionGUID))
                        {
                            pBoss->GetMotionMaster()->MovePoint(0, 746.88f, 618.74f, 411.06f);
                            pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pBoss->SetReactState(REACT_AGGRESSIVE);
                        }
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_E:
                    m_auiEncounter[1] = uiData;
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        pAnnouncer->GetMotionMaster()->MovePoint(3, announcerWaitPos);
                        DoRespawnGameObject(uiEadricLootGUID, 1 * DAY);
                        if (GameObject* cache = instance->GetGameObject(uiEadricLootGUID))
                            cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_P:
                    m_auiEncounter[2] = uiData;
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        pAnnouncer->GetMotionMaster()->MovePoint(3, announcerWaitPos);
                        DoRespawnGameObject(uiPaletressLootGUID, 1 * DAY);
                        if (GameObject* cache = instance->GetGameObject(uiPaletressLootGUID))
                            cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                    break;
            }

            if (uiData == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_PLAYERS_TEAM: return m_playersTeam;
                case BOSS_GRAND_CHAMPIONS:  return m_auiEncounter[0];
                case BOSS_ARGENT_CHALLENGE_E: return m_auiEncounter[1];
                case BOSS_ARGENT_CHALLENGE_P: return m_auiEncounter[2];
                case BOSS_BLACK_KNIGHT: return m_auiEncounter[3];

                case DATA_ARGENT_SOLDIER_DEFEATED: return uiArgentSoldierDeaths;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_ANNOUNCER: return uiAnnouncerGUID;
                case DATA_MAIN_GATE: return uiMainGateGUID;

                case DATA_GRAND_CHAMPION_1: return uiGrandChampion1GUID;
                case DATA_GRAND_CHAMPION_2: return uiGrandChampion2GUID;
                case DATA_GRAND_CHAMPION_3: return uiGrandChampion3GUID;

                case DATA_GRAND_CHAMPION_VEHICLE_1: return uiGrandChampionVehicle1GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_2: return uiGrandChampionVehicle2GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_3: return uiGrandChampionVehicle3GUID;

                case DATA_TIRION: return uiTirionGUID;
                case DATA_VARIAN: return uiVarianGUID;
                case DATA_JAINA: return uiJainaGUID;
                case DATA_GARROSH: return uiGarroshGUID;
                case DATA_THRALL: return uiThrallGUID;
            }

            return ObjectGuid::Empty;
        }

        void SetGuidData(uint32 uiType, ObjectGuid uiData) override
        {
            switch (uiType)
            {
                case DATA_GRAND_CHAMPION_VEHICLE_1:
                    uiGrandChampionVehicle1GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_2:
                    uiGrandChampionVehicle2GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_3:
                    uiGrandChampionVehicle3GUID = uiData;
                    break;
            }
        }

        std::string GetSaveData() override
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "T C " << m_auiEncounter[0]
                << ' ' << m_auiEncounter[1]
                << ' ' << m_auiEncounter[2]
                << ' ' << m_auiEncounter[3];

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in) override
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3, data4, data5;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5;

            if (dataHead1 == 'T' && dataHead2 == 'C')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_trial_of_the_champion()
{
    new instance_trial_of_the_champion();
}
