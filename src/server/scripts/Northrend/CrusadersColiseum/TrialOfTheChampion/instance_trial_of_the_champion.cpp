/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
            uiMovementDone = 0;
            uiGrandChampionsDeaths = 0;
            uiArgentSoldierDeaths = 0;

            bDone = false;

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint16 uiMovementDone;
        uint16 uiGrandChampionsDeaths;
        uint8 uiArgentSoldierDeaths;

        ObjectGuid uiAnnouncerGUID;
        ObjectGuid uiMainGateGUID;
        ObjectGuid uiGrandChampionVehicle1GUID;
        ObjectGuid uiGrandChampionVehicle2GUID;
        ObjectGuid uiGrandChampionVehicle3GUID;
        ObjectGuid uiGrandChampion1GUID;
        ObjectGuid uiGrandChampion2GUID;
        ObjectGuid uiGrandChampion3GUID;
        ObjectGuid uiChampionLootGUID;
        ObjectGuid uiArgentChampionGUID;

        GuidList VehicleList;

        std::string str_data;

        bool bDone;

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
            uint32 TeamInInstance = 0;

            if (!players.isEmpty())
            {
                if (Player* player = players.begin()->GetSource())
                    TeamInInstance = player->GetTeam();
            }

            switch (creature->GetEntry())
            {
                // Champions
                case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT);
                    break;
                case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_AMBROSE_BOLTSPARK_MOUNT);
                    break;
                case VEHICLE_RUNOK_WILDMANE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_COLOSOS_MOUNT);
                    break;
                case VEHICLE_ZUL_TORE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EVENSONG_MOUNT);
                    break;
                case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_LANA_STOUTHAMMER_MOUNT);
                    break;
                // Coliseum Announcer || Just NPC_JAEREN must be spawned.
                case NPC_JAEREN:
                    uiAnnouncerGUID = creature->GetGUID();
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS);
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

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_MAIN_GATE:
                    uiMainGateGUID = go->GetGUID();
                    break;
                case GO_CHAMPIONS_LOOT:
                case GO_CHAMPIONS_LOOT_H:
                    uiChampionLootGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData) override
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
                        for (GuidList::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                            if (Creature* summon = instance->GetCreature(*itr))
                                summon->RemoveFromWorld();
                    }else if (uiData == DONE)
                    {
                        ++uiGrandChampionsDeaths;
                        if (uiGrandChampionsDeaths == 3)
                        {
                            if (Creature* pAnnouncer =  instance->GetCreature(uiAnnouncerGUID))
                            {
                                pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                                pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_CHAMPIONS_LOOT_H : GO_CHAMPIONS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000);
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
                        }
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_E:
                    m_auiEncounter[1] = uiData;
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                        pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_EADRIC_LOOT_H : GO_EADRIC_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000);
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_P:
                    m_auiEncounter[2] = uiData;
                    if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                    {
                        pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                        pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_PALETRESS_LOOT_H : GO_PALETRESS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000);
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
                case BOSS_GRAND_CHAMPIONS:  return m_auiEncounter[0];
                case BOSS_ARGENT_CHALLENGE_E: return m_auiEncounter[1];
                case BOSS_ARGENT_CHALLENGE_P: return m_auiEncounter[2];
                case BOSS_BLACK_KNIGHT: return m_auiEncounter[3];

                case DATA_MOVEMENT_DONE: return uiMovementDone;
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
            }

            return ObjectGuid::Empty;
        }

        void SetGuidData(uint32 uiType, ObjectGuid uiData) override
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

        std::string GetSaveData() override
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "T C " << m_auiEncounter[0]
                << ' ' << m_auiEncounter[1]
                << ' ' << m_auiEncounter[2]
                << ' ' << m_auiEncounter[3]
                << ' ' << uiGrandChampionsDeaths
                << ' ' << uiMovementDone;

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

                uiGrandChampionsDeaths = data4;
                uiMovementDone = data5;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_trial_of_the_champion()
{
    new instance_trial_of_the_champion();
}
