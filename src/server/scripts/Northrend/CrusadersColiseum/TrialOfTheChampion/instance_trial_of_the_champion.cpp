/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDCategory: Trial Of the Champion
EndScriptData */

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"

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
        uint32 grandChampionEntry[3];
        uint32 memoryEntry;

        uint64 uiAnnouncerGUID;
        uint64 uiTirionGUID;
        uint64 uiThrallGUID;
        uint64 uiGarroshGUID;
        uint64 uiVarianGUID;
        uint64 uiJainaGUID;
        uint64 grandChampionGUID[3];
        uint64 uiBlackKnightGUID;
        uint64 uiBlackKnightGryphonGUID;
        uint64 uiMainGateGUID;
        uint64 uiPortcullisGUID;
        uint64 uiChampionLootGUID;

        std::list<uint64> VehicleList;
        uint32 TeamInInstance;

        bool achievementHadWorse;

        void Initialize()
        {
            uiAnnouncerGUID        = 0;
            uiTirionGUID           = 0;
            uiThrallGUID           = 0;
            uiGarroshGUID          = 0;
            uiJainaGUID            = 0;
            uiMainGateGUID         = 0;
            uiPortcullisGUID       = 0;
            uiChampionLootGUID     = 0;
            memoryEntry            = 0;
            uiBlackKnightGUID      = 0;

            achievementHadWorse = true;

            VehicleList.clear();
            TeamInInstance = 0;
            memset(&grandChampionEntry, 0, sizeof(grandChampionEntry));
            memset(&grandChampionEntry, 0, sizeof(grandChampionGUID));
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

        void OnPlayerEnter(Player* player)
        {
            if (!TeamInInstance)
                TeamInInstance = player->GetTeam();
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                // Coliseum Announcer || Only NPC_JAEREN must be spawned.
                case NPC_JAEREN:
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS);
                    uiAnnouncerGUID = creature->GetGUID();
                    break;
                case NPC_TIRION:
                    uiTirionGUID = creature->GetGUID();
                    break;
                case NPC_THRALL:
                    uiThrallGUID = creature->GetGUID();
                    break;
                case NPC_GARROSH:
                    uiGarroshGUID = creature->GetGUID();
                    break;
                case NPC_VARIAN:
                    uiVarianGUID = creature->GetGUID();
                    break;
                case NPC_JAINA:
                    uiJainaGUID = creature->GetGUID();
                    break;
                case VEHICLE_ARGENT_WARHORSE:
                case VEHICLE_ARGENT_BATTLEWORG:
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case NPC_BLACK_KNIGHT:
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    creature->SetReactState(REACT_PASSIVE);
                    uiBlackKnightGUID = creature->GetGUID();
                    break;
                case VEHICLE_BLACK_KNIGHT:
                    uiBlackKnightGryphonGUID = creature->GetGUID();
                    creature->SetPhaseMask(2, true);
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_MAIN_GATE:
                    uiMainGateGUID = go->GetGUID();
                    break;
                case GO_PORTCULLIS:
                    uiPortcullisGUID = go->GetGUID();
                    break;
                case GO_CHAMPIONS_LOOT:
                case GO_CHAMPIONS_LOOT_H:
                case GO_EADRIC_LOOT:
                case GO_EADRIC_LOOT_H:
                case GO_PALETRESS_LOOT:
                case GO_PALETRESS_LOOT_H:
                    uiChampionLootGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case BOSS_GRAND_CHAMPIONS:
                    m_auiEncounter[0] = data;
                    if (data == SPECIAL)
                    {
                        for (std::list<uint64>::const_iterator itr = VehicleList.begin(); itr != VehicleList.end(); ++itr)
                            if (Creature* summon = instance->GetCreature(*itr))
                                summon->RemoveFromWorld();
                    } else if (data == IN_PROGRESS)
                    {
                        for (uint8 i=0; i<3; i++)
                            if (Creature* boss = instance->GetCreature(grandChampionGUID[i]))
                                AggroAllPlayers(boss);
                    } else if (data == DONE)
                    {
                        DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_CHAMPIONS);
                        if (Creature* announcer =  instance->GetCreature(uiAnnouncerGUID))
                        {
                            announcer->GetMotionMaster()->MovePoint(0, 742.742f, 630.207f, 411.172f);
                            announcer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            announcer->SummonGameObject(instance->IsHeroic()? GO_CHAMPIONS_LOOT_H : GO_CHAMPIONS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);
                        }
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_E:
                    m_auiEncounter[1] = data;
                    if (data == DONE)
                    {
                        if (Creature* announcer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_EADRIC);
                            announcer->GetMotionMaster()->MovePoint(0, 742.742f, 630.207f, 411.172f);
                            announcer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            announcer->SummonGameObject(instance->IsHeroic()? GO_EADRIC_LOOT_H : GO_EADRIC_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);
                        }
                    }
                    break;
                case BOSS_ARGENT_CHALLENGE_P:
                    m_auiEncounter[2] = data;
                    if (data == DONE)
                    {
                        if (Creature* announcer = instance->GetCreature(uiAnnouncerGUID))
                        {
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_PALETRESS);
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_MEMORIES);
                            announcer->GetMotionMaster()->MovePoint(0, 742.742f, 630.207f, 411.172f);
                            announcer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            announcer->SummonGameObject(instance->IsHeroic()? GO_PALETRESS_LOOT_H : GO_PALETRESS_LOOT, 746.59f, 618.49f, 411.09f, 1.42f, 0, 0, 0, 0, 90000000);
                        }
                    }
                    break;
                case BOSS_BLACK_KNIGHT:
                    m_auiEncounter[3] = data;
                    if (data == DONE)
                        DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_BLACK_KNIGHT);
                    break;
                case DATA_GRAND_CHAMPION_ENTRY:
                    for (uint8 i=0; i<3; i++)
                    {
                        if (grandChampionEntry[i] == 0)
                        {
                            grandChampionEntry[i] = data;
                            return;
                        }
                    }
                    break;
                case DATA_MEMORY_ENTRY:
                    memoryEntry = data;
                    break;
                case DATA_I_VE_HAD_WORSE:
                    achievementHadWorse = (bool)data;
                    break;
            }

            if (type != DATA_I_VE_HAD_WORSE)
            {
                if (data == DONE || data == FAIL)
                    HandleGameObject(GetData64(DATA_PORTCULLIS), true);
                else if (data == IN_PROGRESS)
                    HandleGameObject(GetData64(DATA_PORTCULLIS), false);

                if (data == DONE)
                    SaveToDB();
            }
        }

        uint32 GetData(uint32 data)
        {
            switch(data)
            {
                case BOSS_GRAND_CHAMPIONS:  return m_auiEncounter[0];
                case BOSS_ARGENT_CHALLENGE_E: return m_auiEncounter[1];
                case BOSS_ARGENT_CHALLENGE_P: return m_auiEncounter[2];
                case BOSS_BLACK_KNIGHT: return m_auiEncounter[3];

                case DATA_TEAM: return TeamInInstance;
            }

            return 0;
        }

        void SetData64(uint32 type, uint64 data)
        {
            switch (type)
            {
                case DATA_GRAND_CHAMPION_GUID:
                    for (uint8 i=0; i<3; i++)
                    {
                        if (grandChampionGUID[i] == 0)
                        {
                            grandChampionGUID[i] = data;
                            return;
                        }
                    }
                    break;
            }
        }

        uint64 GetData64(uint32 data)
        {
            switch(data)
            {
                case DATA_ANNOUNCER: return uiAnnouncerGUID;
                case DATA_TIRION: return uiTirionGUID;
                case DATA_THRALL: return uiThrallGUID;
                case DATA_GARROSH: return uiGarroshGUID;
                case DATA_VARIAN: return uiVarianGUID;
                case DATA_JAINA: return uiJainaGUID;
                case DATA_MAIN_GATE: return uiMainGateGUID;
                case DATA_PORTCULLIS: return uiPortcullisGUID;
                case DATA_CHEST: return uiChampionLootGUID;
                case DATA_BLACK_KNIGHT: return uiBlackKnightGUID;
                case DATA_BLACK_KNIGHT_GRYPHON: return uiBlackKnightGryphonGUID;
            }

            return 0;
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
        {
            switch(criteria_id)
            {
                case CRITERIA_CHAMPION_JACOB:
                case CRITERIA_CHAMPION_LANA:
                case CRITERIA_CHAMPION_COLOSOS:
                case CRITERIA_CHAMPION_AMBROSE:
                case CRITERIA_CHAMPION_JAELYNE:
                case CRITERIA_CHAMPION_MOKRA:
                case CRITERIA_CHAMPION_VISCERI:
                case CRITERIA_CHAMPION_RUNOK:
                case CRITERIA_CHAMPION_ERESSEA:
                case CRITERIA_CHAMPION_ZULTORE:
                case CRITERIA_CHAMPION_JACOB_H:
                case CRITERIA_CHAMPION_LANA_H:
                case CRITERIA_CHAMPION_COLOSOS_H:
                case CRITERIA_CHAMPION_AMBROSE_H:
                case CRITERIA_CHAMPION_JAELYNE_H:
                case CRITERIA_CHAMPION_MOKRA_H:
                case CRITERIA_CHAMPION_VISCERI_H:
                case CRITERIA_CHAMPION_RUNOK_H:
                case CRITERIA_CHAMPION_ERESSEA_H:
                case CRITERIA_CHAMPION_ZULTORE_H:
                    for(uint8 i = 0; i<3; i++)
                        if(grandChampionEntry[i] == GetRelatedCreatureEntry(criteria_id))
                            return true;
                    return false;
                case CRITERIA_MEMORY_HOGGER:
                case CRITERIA_MEMORY_VANCLEEF:
                case CRITERIA_MEMORY_MUTANUS:
                case CRITERIA_MEMORY_HEROD:
                case CRITERIA_MEMORY_LUCIFROM:
                case CRITERIA_MEMORY_THUNDERAAN:
                case CRITERIA_MEMORY_CHROMAGGUS:
                case CRITERIA_MEMORY_HAKKAR:
                case CRITERIA_MEMORY_VEKNILASH:
                case CRITERIA_MEMORY_KALITHRESH:
                case CRITERIA_MEMORY_MALCHEZAAR:
                case CRITERIA_MEMORY_GRUUL:
                case CRITERIA_MEMORY_VASHJ:
                case CRITERIA_MEMORY_ARCHIMONDE:
                case CRITERIA_MEMORY_ILLIDAN:
                case CRITERIA_MEMORY_DELRISSA:
                case CRITERIA_MEMORY_MURU:
                case CRITERIA_MEMORY_INGVAR:
                case CRITERIA_MEMORY_CYANIGOSA:
                case CRITERIA_MEMORY_ECK:
                case CRITERIA_MEMORY_ONYXIA:
                case CRITERIA_MEMORY_HEIGAN:
                case CRITERIA_MEMORY_IGNIS:
                case CRITERIA_MEMORY_VEZAX:
                case CRITERIA_MEMORY_ALGALON:
                    return (memoryEntry == GetRelatedCreatureEntry(criteria_id));
                case CRITERIA_I_VE_HAD_WORSE:
                    return achievementHadWorse;
            }

            return false;
        }
        uint32 GetRelatedCreatureEntry(uint32 criteria_id)
        {
            switch(criteria_id)
            {
                case CRITERIA_CHAMPION_JACOB:
                case CRITERIA_CHAMPION_JACOB_H:
                    return NPC_JACOB;
                case CRITERIA_CHAMPION_LANA:
                case CRITERIA_CHAMPION_LANA_H:
                    return NPC_LANA;
                case CRITERIA_CHAMPION_COLOSOS:
                case CRITERIA_CHAMPION_COLOSOS_H:
                    return NPC_COLOSOS;
                case CRITERIA_CHAMPION_AMBROSE:
                case CRITERIA_CHAMPION_AMBROSE_H:
                    return NPC_AMBROSE;
                case CRITERIA_CHAMPION_JAELYNE:
                case CRITERIA_CHAMPION_JAELYNE_H:
                    return NPC_JAELYNE;
                case CRITERIA_CHAMPION_MOKRA:
                case CRITERIA_CHAMPION_MOKRA_H:
                    return NPC_MOKRA;
                case CRITERIA_CHAMPION_VISCERI:
                case CRITERIA_CHAMPION_VISCERI_H:
                    return NPC_VISCERI;
                case CRITERIA_CHAMPION_RUNOK:
                case CRITERIA_CHAMPION_RUNOK_H:
                    return NPC_RUNOK;
                case CRITERIA_CHAMPION_ERESSEA:
                case CRITERIA_CHAMPION_ERESSEA_H:
                    return NPC_ERESSEA;
                case CRITERIA_CHAMPION_ZULTORE:
                case CRITERIA_CHAMPION_ZULTORE_H:
                    return NPC_ZULTORE;

                case CRITERIA_MEMORY_HOGGER:     return NPC_MEMORY_HOGGER;
                case CRITERIA_MEMORY_VANCLEEF:   return NPC_MEMORY_VANCLEEF;
                case CRITERIA_MEMORY_MUTANUS:    return NPC_MEMORY_MUTANUS;
                case CRITERIA_MEMORY_HEROD:      return NPC_MEMORY_HEROD;
                case CRITERIA_MEMORY_LUCIFROM:   return NPC_MEMORY_LUCIFROM;
                case CRITERIA_MEMORY_THUNDERAAN: return NPC_MEMORY_THUNDERAAN;
                case CRITERIA_MEMORY_CHROMAGGUS: return NPC_MEMORY_CHROMAGGUS;
                case CRITERIA_MEMORY_HAKKAR:     return NPC_MEMORY_HAKKAR;
                case CRITERIA_MEMORY_VEKNILASH:  return NPC_MEMORY_VEKNILASH;
                case CRITERIA_MEMORY_KALITHRESH: return NPC_MEMORY_KALITHRESH;
                case CRITERIA_MEMORY_MALCHEZAAR: return NPC_MEMORY_MALCHEZAAR;
                case CRITERIA_MEMORY_GRUUL:      return NPC_MEMORY_GRUUL;
                case CRITERIA_MEMORY_VASHJ:      return NPC_MEMORY_VASHJ;
                case CRITERIA_MEMORY_ARCHIMONDE: return NPC_MEMORY_ARCHIMONDE;
                case CRITERIA_MEMORY_ILLIDAN:    return NPC_MEMORY_ILLIDAN;
                case CRITERIA_MEMORY_DELRISSA:   return NPC_MEMORY_DELRISSA;
                case CRITERIA_MEMORY_MURU:       return NPC_MEMORY_MURU;
                case CRITERIA_MEMORY_INGVAR:     return NPC_MEMORY_INGVAR;
                case CRITERIA_MEMORY_CYANIGOSA:  return NPC_MEMORY_CYANIGOSA;
                case CRITERIA_MEMORY_ECK:        return NPC_MEMORY_ECK;
                case CRITERIA_MEMORY_ONYXIA:     return NPC_MEMORY_ONYXIA;
                case CRITERIA_MEMORY_HEIGAN:     return NPC_MEMORY_HEIGAN;
                case CRITERIA_MEMORY_IGNIS:      return NPC_MEMORY_IGNIS;
                case CRITERIA_MEMORY_VEZAX:      return NPC_MEMORY_VEZAX;
                case CRITERIA_MEMORY_ALGALON:    return NPC_MEMORY_ALGALON;
            }
            return 0;
        }
        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "T C " << m_auiEncounter[0]
                << ' ' << m_auiEncounter[1]
                << ' ' << m_auiEncounter[2]
                << ' ' << m_auiEncounter[3];

            OUT_SAVE_INST_DATA_COMPLETE;
            return  saveStream.str();
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
            uint16 data0, data1, data2, data3;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

            if (dataHead1 == 'T' && dataHead2 == 'C')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

                if (m_auiEncounter[1] != DONE && (m_auiEncounter[1] == DONE || m_auiEncounter[2] == DONE))
                {
                    // TODO: Respawn announcer OR Spawn Black Knight on the arena
                }

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_trial_of_the_champion()
{
    new instance_trial_of_the_champion();
}
