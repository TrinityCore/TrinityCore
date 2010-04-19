/*
 * Copyright (C) 2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


/* ScriptData
SDName: Instance Trial of the Champion
SDComment:
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptedPch.h"
#include "trial_of_the_champion.h"

#define MAX_ENCOUNTER  4

struct instance_trial_of_the_champion : public ScriptedInstance
{
    instance_trial_of_the_champion(Map* pMap) : ScriptedInstance(pMap) {Initialize();}

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    uint8 uiMovementDone;
    uint8 uiGrandChampionsDeaths;
    uint8 uiArgentSoldierDeaths;

    uint64 uiAnnouncerGUID;
    uint64 uiMainGateGUID;
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

        uiAnnouncerGUID        = 0;
        uiMainGateGUID         = 0;
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

    void OnCreatureCreate(Creature* pCreature, bool /*bAdd*/)
    {
        Map::PlayerList const &players = instance->GetPlayers();
        uint32 TeamInInstance = 0;

        if (!players.isEmpty())
        {
            if (Player* pPlayer = players.begin()->getSource())
                TeamInInstance = pPlayer->GetTeam();
        }

        switch(pCreature->GetEntry())
        {
            // Champions
            case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT, ALLIANCE);
                break;
            case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(VEHICLE_AMBROSE_BOLTSPARK_MOUNT, ALLIANCE);
                break;
            case VEHICLE_RUNOK_WILDMANE_MOUNT:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(VEHICLE_COLOSOS_MOUNT, ALLIANCE);
                break;
            case VEHICLE_ZUL_TORE_MOUNT:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(VEHICLE_EVENSONG_MOUNT, ALLIANCE);
                break;
            case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(VEHICLE_LANA_STOUTHAMMER_MOUNT, ALLIANCE);
                break;
            // Coliseum Announcer || Just NPC_JAEREN must be spawned.
            case NPC_JAEREN:
                uiAnnouncerGUID = pCreature->GetGUID();
                if (TeamInInstance == ALLIANCE)
                    pCreature->UpdateEntry(NPC_ARELAS,ALLIANCE);
                break;
            case VEHICLE_ARGENT_WARHORSE:
            case VEHICLE_ARGENT_BATTLEWORG:
                VehicleList.push_back(pCreature->GetGUID());
                break;
            case NPC_EADRIC:
            case NPC_PALETRESS:
                uiArgentChampionGUID = pCreature->GetGUID();
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGO, bool /*bAdd*/)
    {
        switch(pGO->GetEntry())
        {
            case GO_MAIN_GATE:
                uiMainGateGUID = pGO->GetGUID();
                break;
            case GO_CHAMPIONS_LOOT:
            case GO_CHAMPIONS_LOOT_H:
                uiChampionLootGUID = pGO->GetGUID();
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case DATA_MOVEMENT_DONE:
                uiMovementDone = uiData;
                if (uiMovementDone == 3)
                {
                    if (Creature* pAnnouncer =  instance->GetCreature(uiAnnouncerGUID))
                        pAnnouncer->AI()->SetData(DATA_IN_POSITION,0);
                }
                break;
            case BOSS_GRAND_CHAMPIONS:
                m_auiEncounter[0] = uiData;
                if (uiData == IN_PROGRESS)
                {
                    for (std::list<uint64>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                        if (Creature* pSummon = instance->GetCreature(*itr))
                            pSummon->RemoveFromWorld();
                }else if (uiData == DONE)
                {
                    ++uiGrandChampionsDeaths;
                    if (uiGrandChampionsDeaths == 3)
                    {
                        if (Creature* pAnnouncer =  instance->GetCreature(uiAnnouncerGUID))
                        {
                            pAnnouncer->GetMotionMaster()->MovePoint(0,748.309,619.487,411.171);
                            pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_CHAMPIONS_LOOT_H : GO_CHAMPIONS_LOOT,746.59,618.49,411.09,1.42,0, 0, 0, 0,90000000);
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
                        pBoss->GetMotionMaster()->MovePoint(0,746.88,618.74,411.06);
                        pBoss->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                        pBoss->SetReactState(REACT_AGGRESSIVE);
                    }
                }
                break;
            case BOSS_ARGENT_CHALLENGE_E:
                m_auiEncounter[1] = uiData;
                if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                {
                    pAnnouncer->GetMotionMaster()->MovePoint(0,748.309,619.487,411.171);
                    pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_EADRIC_LOOT_H : GO_EADRIC_LOOT,746.59,618.49,411.09,1.42,0, 0, 0, 0,90000000);
                }
                break;
            case BOSS_ARGENT_CHALLENGE_P:
                m_auiEncounter[2] = uiData;
                if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                {
                    pAnnouncer->GetMotionMaster()->MovePoint(0,748.309,619.487,411.171);
                    pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_PALETRESS_LOOT_H : GO_PALETRESS_LOOT,746.59,618.49,411.09,1.42,0, 0, 0, 0,90000000);
                }
                break;
        }

        if (uiData == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 uiData)
    {
        switch(uiData)
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

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
            case DATA_ANNOUNCER: return uiAnnouncerGUID;
            case DATA_MAIN_GATE: return uiMainGateGUID;

            case DATA_GRAND_CHAMPION_1: return uiGrandChampion1GUID;
            case DATA_GRAND_CHAMPION_2: return uiGrandChampion2GUID;
            case DATA_GRAND_CHAMPION_3: return uiGrandChampion3GUID;
        }

        return 0;
    }

    void SetData64(uint32 uiType, uint64 uiData)
    {
        switch(uiType)
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
        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_trial_of_the_champion(Map* pMap)
{
    return new instance_trial_of_the_champion(pMap);
}

void AddSC_instance_trial_of_the_champion()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_trial_of_the_champion";
    newscript->GetInstanceData = &GetInstanceData_instance_trial_of_the_champion;
    newscript->RegisterSelf();
}
