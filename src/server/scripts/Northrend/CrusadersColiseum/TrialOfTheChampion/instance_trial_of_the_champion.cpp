/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"
#include "Player.h"

#define MAX_ENCOUNTER  4

class instance_trial_of_the_champion : public InstanceMapScript
{
public:
    instance_trial_of_the_champion() : InstanceMapScript("instance_trial_of_the_champion", 650) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_trial_of_the_champion_InstanceMapScript(pMap);
    }

    struct instance_trial_of_the_champion_InstanceMapScript : public InstanceScript
    {
        instance_trial_of_the_champion_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 TeamInInstance;

        uint16 uiMovementDone;
        uint16 uiGrandChampionsDeaths;
        uint8 uiArgentSoldierDeaths;
        uint8 uiAgroDone;
        uint8 uiAggroDone;

        uint64 uiAnnouncerGUID;
        uint64 uiHighlordGUID;
        uint64 uiMainGateGUID;
        uint64 uiMainGate1GUID;
        uint64 uiGrandChampionVehicle1GUID;
        uint64 uiGrandChampionVehicle2GUID;
        uint64 uiGrandChampionVehicle3GUID;
        uint64 uiGrandChampion1GUID;
        uint64 uiGrandChampion2GUID;
        uint64 uiGrandChampion3GUID;
        uint64 uiChampionLootGUID;
        uint64 uiArgentChampionGUID;

        std::list<uint64> VehicleList;

        std::string str_data;

        bool bDone;

        void Initialize()
        {
            uiMovementDone = 0;
            uiGrandChampionsDeaths = 0;
            uiArgentSoldierDeaths = 0;
            TeamInInstance = 0;

            uiAnnouncerGUID        = 0;
            uiHighlordGUID         = 0;
            uiMainGateGUID         = 0;
            uiMainGate1GUID        = 0;
            uiGrandChampionVehicle1GUID   = 0;
            uiGrandChampionVehicle2GUID   = 0;
            uiGrandChampionVehicle3GUID   = 0;
            uiGrandChampion1GUID          = 0;
            uiGrandChampion2GUID          = 0;
            uiGrandChampion3GUID          = 0;
            uiChampionLootGUID            = 0;
            uiArgentChampionGUID          = 0;

            bDone = false;

            VehicleList.clear();

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            Map::PlayerList const &players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                if (Player* player = players.begin()->getSource())
                    TeamInInstance = player->GetTeam();
            }

            switch (creature->GetEntry())
            {
                // Gran Champions
                case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT, ALLIANCE);
                    break;
                case NPC_MOKRA:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_JACOB, ALLIANCE);
                    break;
                case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_AMBROSE_BOLTSPARK_MOUNT, ALLIANCE);
                    break;
                case NPC_ERESSEA:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_AMBROSE, ALLIANCE);
                    break;
                case VEHICLE_RUNOK_WILDMANE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_COLOSOS_MOUNT, ALLIANCE);
                    break;
                case NPC_RUNOK:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_COLOSOS, ALLIANCE);
                    break;
                case VEHICLE_ZUL_TORE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EVENSONG_MOUNT, ALLIANCE);
                    break;
                case NPC_ZULTORE:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_JAELYNE, ALLIANCE);
                    break;
                case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_LANA_STOUTHAMMER_MOUNT, ALLIANCE);
                    break;
                case NPC_VISCERI:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_LANA, ALLIANCE);
                    break;
                // Faction champions vehicles
                case VEHICLE_FORSAKE_WARHORSE:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_IRONFORGE_RAM, ALLIANCE);
                    break;
                case VEHICLE_THUNDER_BLUFF_KODO:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EXODAR_ELEKK, ALLIANCE);
                    break;
                case VEHICLE_ORGRIMMAR_WOLF:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_STORMWIND_STEED, ALLIANCE);
                    break;
                case VEHICLE_SILVERMOON_HAWKSTRIDER:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_GNOMEREGAN_MECHANOSTRIDER, ALLIANCE);
                    break;
                case VEHICLE_DARKSPEAR_RAPTOR:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_DARNASSIA_NIGHTSABER, ALLIANCE);
                    break;
                // Faction champios
                case NPC_ORGRIMAR_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_STORMWIND_CHAMPION, ALLIANCE);
                    break;
                case NPC_SILVERMOON_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_GNOMERAGN_CHAMPION, ALLIANCE);
                    break;
                case NPC_THUNDER_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_EXODAR_CHAMPION, ALLIANCE);
                    break;
                case NPC_TROLL_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_DRNASSUS_CHAMPION, ALLIANCE);
                    break;
                case NPC_UNDERCITY_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_IRONFORGE_CHAMPION, ALLIANCE);
                    break;

                // Coliseum Announcer || Just NPC_JAEREN must be spawned.
                case NPC_HIGHLORD:
                    uiHighlordGUID = creature->GetGUID();
                    break;
                case NPC_JAEREN:
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS, ALLIANCE);
                    uiAnnouncerGUID = creature->GetGUID();
                    break;
                case NPC_JAEREN_AN:
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS_AN, ALLIANCE);
                    break;
                case VEHICLE_ARGENT_WARHORSE:
                case VEHICLE_ARGENT_BATTLEWORG:
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case NPC_EADRIC:
                case NPC_PALETRESS:
                    uiArgentChampionGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_MAIN_GATE:
                    uiMainGateGUID = go->GetGUID();
                    break;
                case GO_MAIN_GATE1:
                    uiMainGate1GUID = go->GetGUID();
                    break;
                case GO_CHAMPIONS_LOOT:
                case GO_CHAMPIONS_LOOT_H:
                    uiChampionLootGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch (uiType)
            {
                case DATA_MOVEMENT_DONE:
                    uiMovementDone = uiData;
                    if (uiMovementDone == 3)
                    {
                        if (Creature* pAnnouncer =  instance->GetCreature(uiAnnouncerGUID))
                            pAnnouncer->AI()->SetData(DATA_IN_POSITION, 0);
                    }
                    break;
                case BOSS_GRAND_CHAMPIONS:
                    m_auiEncounter[0] = uiData;
                    if (uiData == IN_PROGRESS)
                    {
                        for (std::list<uint64>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                            if (Creature* summon = instance->GetCreature(*itr))
                                summon->RemoveFromWorld();
                    } else if (uiData == DONE)
                    {
                        ++uiGrandChampionsDeaths;
                        if (uiGrandChampionsDeaths >= 3)
                        {
                            if (Creature* pAnnouncer =  instance->GetCreature(uiAnnouncerGUID))
                            {
                                pAnnouncer->AI()->SetData(DATA_RESET, 0);
                                m_auiEncounter[0] = uiData;
                                pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                                pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_CHAMPIONS_LOOT_H : GO_CHAMPIONS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);
                            }
                        }
                    }
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
                            pBoss->setFaction(16);
                        }
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_E:
                    m_auiEncounter[1] = uiData;
                    if (uiData == IN_PROGRESS)
                    {
                    for(std::list<uint64>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                        if (Creature* pSummon = instance->GetCreature(*itr))
                            pSummon->RemoveFromWorld();
                    } else if (uiData == DONE)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                            pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_EADRIC_LOOT_H : GO_EADRIC_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);
                        }
                    }
                    break;
                case DATA_AGGRO_DONE:
                    uiAgroDone = uiData;
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        pAnnouncer->SetVisible(false);
                    }
                    break;
                case DATA_AGRO_DONE:
                    uiAggroDone = uiData;
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {  
                        pAnnouncer->SetVisible(false);
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_P:
                    m_auiEncounter[2] = uiData;
                    if (uiData == IN_PROGRESS)
                    {
                        for(std::list<uint64>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                            if (Creature* pSummon = instance->GetCreature(*itr))
                                pSummon->RemoveFromWorld();
                    } else if (uiData == DONE)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                            pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_PALETRESS_LOOT_H : GO_PALETRESS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);
                        }
                    }
                    break;
            }

            if (uiData == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 uiData) const
        {
            switch (uiData)
            {
                case BOSS_GRAND_CHAMPIONS:  return m_auiEncounter[0];
                case BOSS_ARGENT_CHALLENGE_E: return m_auiEncounter[1];
                case BOSS_ARGENT_CHALLENGE_P: return m_auiEncounter[2];
                case BOSS_BLACK_KNIGHT: return m_auiEncounter[3];

                case DATA_MOVEMENT_DONE: return uiMovementDone;
                case DATA_ARGENT_SOLDIER_DEFEATED: return uiArgentSoldierDeaths;
                case DATA_TEAM_IN_INSTANCE: return TeamInInstance;
            }

            return 0;
        }

        uint64 GetData64(uint32 uiData) const
        {
            switch (uiData)
            {
                case DATA_ANNOUNCER: return uiAnnouncerGUID;
                case DATA_HIGHLORD:  return uiHighlordGUID;
                case DATA_MAIN_GATE: return uiMainGateGUID;
                case DATA_MAIN_GATE1: return uiMainGate1GUID;

                case DATA_GRAND_CHAMPION_1: return uiGrandChampion1GUID;
                case DATA_GRAND_CHAMPION_2: return uiGrandChampion2GUID;
                case DATA_GRAND_CHAMPION_3: return uiGrandChampion3GUID;
            }

            return 0;
        }

        void SetData64(uint32 uiType, uint64 uiData)
        {
            switch (uiType)
            {
                case DATA_GRAND_CHAMPION_1:
                    uiGrandChampion1GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_2:
                    uiGrandChampion2GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_3:
                    uiGrandChampion3GUID = uiData;
                    break;
            }
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "T C " << m_auiEncounter[0]
                       << " " << m_auiEncounter[1]
                       << " " << m_auiEncounter[2]
                       << " " << m_auiEncounter[3]
                       << " " << uiGrandChampionsDeaths
                       << " " << uiMovementDone;

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
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

                uiGrandChampionsDeaths = data4;
                uiMovementDone = data5;
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void HandleSpellOnPlayersInInstanceToC5(Unit* caller, uint32 spellId)
{
    if (spellId <= 0 || !caller)
        return;

    Map* map = caller->GetMap();
    if (map && map->IsDungeon())
    {
        Map::PlayerList const &PlayerList = map->GetPlayers();

        if (PlayerList.isEmpty())
            return;

        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
             if (i->getSource() && i->getSource()->isAlive() && !i->getSource()->isGameMaster())
                 caller->CastSpell(i->getSource(), spellId);
    }
}

void AddSC_instance_trial_of_the_champion()
{
    new instance_trial_of_the_champion();
}
