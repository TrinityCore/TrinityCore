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

#include "ScriptPCH.h"
#include "TW_trial_of_the_champion.h"
#include "Player.h"

#define MAX_ENCOUNTER  4

enum Events
{
    EVENT_OUTRO_1               = 1,
    EVENT_OUTRO_2               = 2,
    EVENT_OUTRO_3               = 3
};

enum Texts
{
    SAY_OUTRO_1_TIRION                      = 57,
    SAY_OUTRO_2_TIRION                      = 58,
    SAY_OUTRO_3_ALLY                        = 53,
    SAY_OUTRO_3_HORDE                       = 1
};

class TW_instance_trial_of_the_champion : public InstanceMapScript
{
public:
    TW_instance_trial_of_the_champion() : InstanceMapScript("TW_instance_trial_of_the_champion", 650) { }

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
        uint8 uiAggroDone;

        ObjectGuid uiAnnouncerGUID;
        ObjectGuid blackknightGUID;
        ObjectGuid uiThrallGUID;
        ObjectGuid uiVarianGUID;
        ObjectGuid uiHighlordGUID;
        ObjectGuid uiMainGateGUID;
        ObjectGuid uiMainGate1GUID;
        ObjectGuid uiGrandChampionVehicle1GUID;
        ObjectGuid uiGrandChampionVehicle2GUID;
        ObjectGuid uiGrandChampionVehicle3GUID;
        ObjectGuid uiGrandChampion1GUID;
        ObjectGuid uiGrandChampion2GUID;
        ObjectGuid uiGrandChampion3GUID;
        ObjectGuid uiChampionLootGUID;
        ObjectGuid uiArgentChampionGUID;

        std::list<ObjectGuid> VehicleList;
        std::list<ObjectGuid> GrandChampionList;

        std::string str_data;

        EventMap events;

        bool bDone;
        bool HasChestSpawned;

        void Initialize() override
        {
            uiMovementDone                = 0;
            uiGrandChampionsDeaths        = 0;
            uiArgentSoldierDeaths         = 0;
            TeamInInstance                = 0;

            uiAnnouncerGUID.Clear();
            blackknightGUID.Clear();
            uiHighlordGUID.Clear();
            uiMainGateGUID.Clear();
            uiMainGate1GUID.Clear();
            uiVarianGUID.Clear();
            uiThrallGUID.Clear();
            uiGrandChampionVehicle1GUID.Clear();
            uiGrandChampionVehicle2GUID.Clear();
            uiGrandChampionVehicle3GUID.Clear();
            uiGrandChampion1GUID.Clear();
            uiGrandChampion2GUID.Clear();
            uiGrandChampion3GUID.Clear();
            uiChampionLootGUID.Clear();
            uiArgentChampionGUID.Clear();

            bDone = false;
            HasChestSpawned = false;

            VehicleList.clear();
            GrandChampionList.clear();

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        bool IsEncounterInProgress() const
        {
            for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* creature)  override
        {
            Map::PlayerList const &players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                if (Player* player = players.begin()->GetSource())
                    TeamInInstance = player->GetTeam();
            }

            switch(creature->GetEntry())
            {
                // Gran Champions
                case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_MOKRA:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_JACOB);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_AMBROSE_BOLTSPARK_MOUNT);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_ERESSEA:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_AMBROSE);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_RUNOK_WILDMANE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_COLOSOS_MOUNT);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_RUNOK:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_COLOSOS);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_ZUL_TORE_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EVENSONG_MOUNT);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_ZULTORE:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_JAELYNE);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_LANA_STOUTHAMMER_MOUNT);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_VISCERI:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_LANA);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                // Faction champions vehicles
                case VEHICLE_FORSAKE_WARHORSE:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_IRONFORGE_RAM);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_THUNDER_BLUFF_KODO:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_EXODAR_ELEKK);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;                
                case VEHICLE_ORGRIMMAR_WOLF:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_STORMWIND_STEED);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;                
                case VEHICLE_SILVERMOON_HAWKSTRIDER:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_GNOMEREGAN_MECHANOSTRIDER);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case VEHICLE_DARKSPEAR_RAPTOR:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(VEHICLE_DARNASSIA_NIGHTSABER);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                // Faction champios
                case NPC_ORGRIMAR_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_STORMWIND_CHAMPION);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_SILVERMOON_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_GNOMERAGN_CHAMPION);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_THUNDER_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_EXODAR_CHAMPION);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_TROLL_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_DRNASSUS_CHAMPION);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                case NPC_UNDERCITY_CHAMPION:
                    if (TeamInInstance == HORDE)
                        creature->UpdateEntry(NPC_IRONFORGE_CHAMPION);
                    GrandChampionList.push_back(creature->GetGUID());
                    break;
                // Coliseum Announcer || Just NPC_JAEREN must be spawned.
                case NPC_HIGHLORD:
                    uiHighlordGUID = creature->GetGUID();
                    break;
                case NPC_JAEREN:
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS);
                    uiAnnouncerGUID = creature->GetGUID();
                    break;
                case VEHICLE_ARGENT_WARHORSE:
                case VEHICLE_ARGENT_BATTLEWORG:
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case NPC_EADRIC:
                case NPC_PALETRESS:
                    uiArgentChampionGUID = creature->GetGUID();
                    break;
                case NPC_BLACK_KNIGHT:
                    blackknightGUID = creature->GetGUID();
                    break;
                case NPC_THRALL:
                    uiThrallGUID = creature->GetGUID();
                    break;
                case NPC_VARIAN:
                    uiVarianGUID = creature->GetGUID();
                    break;
            }
        }

        bool CheckAchievementCriteriaMeet(uint32 criteriaId, Player const*, Unit const* /* = NULL */, uint32 /* = 0 */) override
        {
            switch (criteriaId)
            {
                case CRITERIA_IVE_HAD_WORSE:
                    if (Creature* knight = instance->GetCreature(blackknightGUID))
                        return knight->AI()->GetData(DATA_IVE_HAD_WORSE) == 1;
                    break;
                default:
                    break;
            }

            return false;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch(go->GetEntry())
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

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_MOVEMENT_DONE:
                    uiMovementDone = uiData;
                    if (uiMovementDone == 3)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                            pAnnouncer->AI()->DoAction(ACTION_SET_HERALD_IN_POSITION);
                    }
                    break;
                case BOSS_GRAND_CHAMPIONS:
                    m_auiEncounter[0] = uiData;
                    switch (uiData)
                    {   
                        case IN_PROGRESS:
                            for (std::list<ObjectGuid>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                                if (Creature* summon = instance->GetCreature(*itr))
                                    summon->RemoveFromWorld();
                            break;
                        case DONE:
                            ++uiGrandChampionsDeaths;
                            if (uiGrandChampionsDeaths >= 3 && !HasChestSpawned)
                            {
                                if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                                {
                                    HasChestSpawned = true;
                                    pAnnouncer->AI()->SetData(DATA_RESET, 0);
                                    m_auiEncounter[0] = uiData;
                                    pAnnouncer->GetMotionMaster()->MovePoint(0, 748.309f, 619.487f, 411.171f);
                                    pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                    pAnnouncer->SummonGameObject(instance->IsHeroic() ? GO_CHAMPIONS_LOOT_H : GO_CHAMPIONS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);

                                    for (std::list<ObjectGuid>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                                        if (Creature* unit = instance->GetCreature(*itr))
                                            if (unit->GetEntry() == NPC_ARGENT_WARHORSE || unit->GetEntry() == NPC_ARGENT_BATTLEWORG)
                                                unit->DespawnOrUnsummon();
                                }
                            }
                            break;
                        case NOT_STARTED:
                            uiGrandChampionsDeaths = 0;
                            for (std::list<ObjectGuid>::const_iterator itr = GrandChampionList.begin(); itr != GrandChampionList.end(); ++itr)
                                if (Creature* champion = instance->GetCreature(*itr))
                                    champion->DespawnOrUnsummon();
                            break;
                        default:
                            break;
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
                        for (std::list<ObjectGuid>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                        if (Creature* pSummon = instance->GetCreature(*itr))
                            pSummon->RemoveFromWorld();
                    } else if (uiData == DONE)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            pAnnouncer->GetMotionMaster()->MovePoint(0,748.309f, 619.487f, 411.171f);
                            pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_EADRIC_LOOT_H : GO_EADRIC_LOOT,746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0,90000000);
                        }
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
                        for (std::list<ObjectGuid>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                            if (Creature* pSummon = instance->GetCreature(*itr))
                                pSummon->RemoveFromWorld();
                    } else if (uiData == DONE)
                    {
                        if (Creature* pAnnouncer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            pAnnouncer->GetMotionMaster()->MovePoint(0,748.309f, 619.487f, 411.171f);
                            pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncer->SummonGameObject(instance->IsHeroic()? GO_PALETRESS_LOOT_H : GO_PALETRESS_LOOT,746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0,90000000);
                        }
                    }
                    break;
                case BOSS_BLACK_KNIGHT:
                    if (uiData == DONE)
                        events.ScheduleEvent(EVENT_OUTRO_1, 4000);
                    break;
            }

            if (uiData == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 uiData) const
        {
            switch(uiData)
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
            switch(uiData)
            {
                case DATA_ANNOUNCER: return uiAnnouncerGUID;
                case DATA_ARGENT_CHAMPION: return uiArgentChampionGUID;
                case DATA_BLACK_KNIGHT: return blackknightGUID;
                case DATA_HIGHLORD:  return uiHighlordGUID;
                case DATA_MAIN_GATE: return uiMainGateGUID;
                case DATA_MAIN_GATE1: return uiMainGate1GUID;

                case DATA_GRAND_CHAMPION_1: return uiGrandChampion1GUID;
                case DATA_GRAND_CHAMPION_2: return uiGrandChampion2GUID;
                case DATA_GRAND_CHAMPION_3: return uiGrandChampion3GUID;
            }

            return 0;
        }

        void SetGuidData(uint32 uiType, ObjectGuid uiData) override
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

                for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

                uiGrandChampionsDeaths = data4;
                uiMovementDone = data5;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void Update(uint32 uiDiff) override
        {
            events.Update(uiDiff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OUTRO_1:
                        if (Creature* tirion = instance->GetCreature(uiHighlordGUID))
                            tirion->AI()->Talk(SAY_OUTRO_1_TIRION);
                        events.ScheduleEvent(EVENT_OUTRO_2, 5000);
                        break;
                    case EVENT_OUTRO_2:
                        if (Creature* tirion = instance->GetCreature(uiHighlordGUID))
                            tirion->AI()->Talk(SAY_OUTRO_2_TIRION);
                        events.ScheduleEvent(EVENT_OUTRO_3, 5000);
                        break;
                    case EVENT_OUTRO_3:
                        if (GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            if (Creature* thrall = instance->GetCreature(uiThrallGUID))
                                thrall->AI()->Talk(SAY_OUTRO_3_HORDE);
                        }
                        else
                            if (Creature* varian = instance->GetCreature(uiVarianGUID))
                                varian->AI()->Talk(SAY_OUTRO_3_ALLY);
                        break;
                }
            }
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
            if (i->GetSource() && i->GetSource()->IsAlive() && !i->GetSource()->IsGameMaster())
                caller->CastSpell(i->GetSource(), spellId);
    }
}

void AddSC_TW_instance_trial_of_the_champion()
{
    new TW_instance_trial_of_the_champion();
}
