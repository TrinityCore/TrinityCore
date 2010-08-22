/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: instance_trial_of_the_crusader
SD%Complete: 80%
SDComment: by /dev/rsa
SDCategory: Trial of the Crusader
EndScriptData */

#include "ScriptPCH.h"
#include "trial_of_the_crusader.h"
class instance_trial_of_the_crusader : public InstanceMapScript
{
public:
    instance_trial_of_the_crusader() : InstanceMapScript("instance_trial_of_the_crusader", 649) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_trial_of_the_crusader_InstanceMapScript(pMap);
    }

    struct instance_trial_of_the_crusader_InstanceMapScript : public InstanceScript
    {
        instance_trial_of_the_crusader_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint32 m_auiEncounter[MAX_ENCOUNTERS];
        uint32 m_uiTrialCounter;
        uint32 m_uiEvent;
        uint32 m_uiEventTimer;
        uint32 m_uiEventNPCId;
        uint32 m_uiNorthrendBeasts;
        std::string m_strInstData;
        bool   m_bNeedSave;

        uint32 m_uiDataDamageTwin;
        uint32 m_uiFjolaCasting;
        uint32 m_uiEydisCasting;

        uint64 m_uiBarrentGUID;
        uint64 m_uiTirionGUID;
        uint64 m_uiFizzlebangGUID;
        uint64 m_uiGarroshGUID;
        uint64 m_uiVarianGUID;

        uint64 m_uiGormokGUID;
        uint64 m_uiAcidmawGUID;
        uint64 m_uiDreadscaleGUID;
        uint64 m_uiIcehowlGUID;
        uint64 m_uiJaraxxusGUID;
        uint64 m_uiChampionsControllerGUID;
        uint64 m_uiDarkbaneGUID;
        uint64 m_uiLightbaneGUID;
        uint64 m_uiAnubarakGUID;

        uint64 m_uiCrusadersCacheGUID;
        uint64 m_uiFloorGUID;

        uint64 m_uiTributeChestGUID;

        uint64 m_uiMainGateDoorGUID;
        uint64 m_uiEastPortcullisGUID;
        uint64 m_uiWebDoorGUID;

        // Achievement stuff
        uint32 m_uiNotOneButTwoJormungarsTimer;
        uint32 m_uiResilienceWillFixItTimer;
        uint8  m_uiSnoboldCount;
        uint8  m_uiMistressOfPainCount;
        bool   m_bTributeToImmortalityElegible;
        std::list<uint32> m_vScarabTimeOfDeath;

        void Initialize()
        {
            for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                m_auiEncounter[i] = NOT_STARTED;

            m_uiTrialCounter = 50;
            m_uiEvent = 0;

            m_uiTributeChestGUID = 0;
            m_uiDataDamageTwin = 0;

            m_uiMainGateDoorGUID = 0;
            m_uiEastPortcullisGUID = 0;
            m_uiWebDoorGUID = 0;
        
            m_uiNorthrendBeasts = NOT_STARTED;

            m_uiEventTimer = 1000;

            m_uiNotOneButTwoJormungarsTimer = 0;
            m_uiResilienceWillFixItTimer = 0;
            m_uiSnoboldCount = 0;
            m_uiMistressOfPainCount = 0;
            m_bTributeToImmortalityElegible = true;

            m_bNeedSave = false;
        }

        bool IsEncounterInProgress() const
        {
            for(uint8 i = 0; i < MAX_ENCOUNTERS ; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;
            return false;
        }

        void OnPlayerEnter(Player *m_player)
        {
            if (instance->IsHeroic())
            {
                m_player->SendUpdateWorldState(UPDATE_STATE_UI_SHOW,1);
                m_player->SendUpdateWorldState(UPDATE_STATE_UI_COUNT, GetData(TYPE_COUNTER));
            }
        }

        bool IsRaidWiped()
        {
            Map::PlayerList const &players = instance->GetPlayers();

            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            {
                if(Player* pPlayer = i->getSource())
                {
                    if(pPlayer->isAlive())
                        return false;
                }
            }
            return true;
        }

        void OpenDoor(uint64 guid)
        {
            if(!guid) return;
            GameObject* pGo = instance->GetGameObject(guid);
            if(pGo) pGo->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
        }

        void CloseDoor(uint64 guid)
        {
            if(!guid) return;
            GameObject* pGo = instance->GetGameObject(guid);
            if(pGo) pGo->SetGoState(GO_STATE_READY);
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            switch(pCreature->GetEntry())
            {
                case NPC_BARRENT:     m_uiBarrentGUID = pCreature->GetGUID(); break;
                case NPC_TIRION:      m_uiTirionGUID = pCreature->GetGUID(); break;
                case NPC_FIZZLEBANG:  m_uiFizzlebangGUID = pCreature->GetGUID(); break;
                case NPC_GARROSH:     m_uiGarroshGUID = pCreature->GetGUID(); break;
                case NPC_VARIAN:      m_uiVarianGUID = pCreature->GetGUID(); break;

                case NPC_GORMOK:      m_uiGormokGUID = pCreature->GetGUID(); break;
                case NPC_ACIDMAW:     m_uiAcidmawGUID = pCreature->GetGUID(); break;
                case NPC_DREADSCALE:  m_uiDreadscaleGUID = pCreature->GetGUID(); break;
                case NPC_ICEHOWL:     m_uiIcehowlGUID = pCreature->GetGUID(); break;
                case NPC_JARAXXUS:    m_uiJaraxxusGUID = pCreature->GetGUID(); break;
                case NPC_CHAMPIONS_CONTROLLER:  m_uiChampionsControllerGUID = pCreature->GetGUID(); break;
                case NPC_DARKBANE:    m_uiDarkbaneGUID = pCreature->GetGUID(); break;
                case NPC_LIGHTBANE:   m_uiLightbaneGUID = pCreature->GetGUID(); break;
                case NPC_ANUBARAK:    m_uiAnubarakGUID = pCreature->GetGUID(); break;
            }
        }

        void OnGameObjectCreate(GameObject* pGO, bool bAdd)
        {
            switch(pGO->GetEntry())
            {
                case GO_CRUSADERS_CACHE_10:
                    if(instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_NORMAL)
                        m_uiCrusadersCacheGUID = pGO->GetGUID(); 
                    break;
                case GO_CRUSADERS_CACHE_25:
                    if(instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_NORMAL)
                        m_uiCrusadersCacheGUID = pGO->GetGUID(); 
                    break;
                case GO_CRUSADERS_CACHE_10_H:
                    if(instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_HEROIC)
                        m_uiCrusadersCacheGUID = pGO->GetGUID(); 
                    break;
                case GO_CRUSADERS_CACHE_25_H:
                    if(instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_HEROIC)
                        m_uiCrusadersCacheGUID = pGO->GetGUID(); 
                    break;
                case GO_ARGENT_COLISEUM_FLOOR: m_uiFloorGUID = pGO->GetGUID(); break;
                case GO_MAIN_GATE_DOOR:   m_uiMainGateDoorGUID = pGO->GetGUID(); break;
                case GO_EAST_PORTCULLIS:  m_uiEastPortcullisGUID = pGO->GetGUID(); break;
                case GO_WEB_DOOR:         m_uiWebDoorGUID = pGO->GetGUID(); break;

                case GO_TRIBUTE_CHEST_10H_25:
                case GO_TRIBUTE_CHEST_10H_45:
                case GO_TRIBUTE_CHEST_10H_50:
                case GO_TRIBUTE_CHEST_10H_99:
                case GO_TRIBUTE_CHEST_25H_25:
                case GO_TRIBUTE_CHEST_25H_45:
                case GO_TRIBUTE_CHEST_25H_50:
                case GO_TRIBUTE_CHEST_25H_99:
                    m_uiTributeChestGUID = pGO->GetGUID(); break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch(uiType)
            {
                case TYPE_JARAXXUS:
                    if (uiData == DONE) m_uiEvent = 2000;
                    break;
                case TYPE_CRUSADERS: 
                    switch (uiData)
                    {
                        case IN_PROGRESS: m_uiResilienceWillFixItTimer = 0; break;
                        case SPECIAL: //Means the first blood
                            m_uiResilienceWillFixItTimer = 60*IN_MILLISECONDS;
                            uiData = IN_PROGRESS;
                            break;
                        case DONE:
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_DEFEAT_FACTION_CHAMPIONS);
                            if (m_uiResilienceWillFixItTimer > 0)
                                DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CHAMPIONS_KILLED_IN_MINUTE);
                            if (GameObject* pChest = instance->GetGameObject(m_uiCrusadersCacheGUID))
                                if (pChest && !pChest->isSpawned())
                                    pChest->SetRespawnTime(7*DAY);
                            m_uiEvent = 3100;
                            break;
                    }
                    break;
                case TYPE_VALKIRIES: 
                    switch (uiData)
                    {
                        case FAIL:
                            if (m_auiEncounter[TYPE_VALKIRIES] == NOT_STARTED) uiData = NOT_STARTED;
                            break;
                        case SPECIAL:
                            if (m_auiEncounter[TYPE_VALKIRIES] == SPECIAL) uiData = DONE;
                            break;
                        case DONE:
                            if (instance->GetPlayers().getFirst()->getSource()->GetTeam() == ALLIANCE)
                                m_uiEvent = 4020;
                            else
                                m_uiEvent = 4030;
                            break;
                    }
                    break;
                case TYPE_ANUBARAK:
                    switch (uiData)
                    {
                        case DONE:
                            m_uiEvent = 6000;
                            break;
                        case SPECIAL:
                            uint32 tributeChest = 0;
                            if (instance->GetSpawnMode() == RAID_DIFFICULTY_10MAN_HEROIC)
                            {
                                if (m_uiTrialCounter >= 50)
                                    tributeChest = GO_TRIBUTE_CHEST_10H_99;
                                else
                                    if (m_uiTrialCounter >= 45)
                                        tributeChest = GO_TRIBUTE_CHEST_10H_50;
                                    else
                                        if (m_uiTrialCounter >= 25)
                                            tributeChest = GO_TRIBUTE_CHEST_10H_45;
                                        else
                                            tributeChest = GO_TRIBUTE_CHEST_10H_25;
                            }
                            else if (instance->GetSpawnMode() == RAID_DIFFICULTY_25MAN_HEROIC)
                            {
                                if (m_uiTrialCounter >= 50)
                                    tributeChest = GO_TRIBUTE_CHEST_25H_99;
                                else
                                    if (m_uiTrialCounter >= 45)
                                        tributeChest = GO_TRIBUTE_CHEST_25H_50;
                                    else
                                        if (m_uiTrialCounter >= 25)
                                            tributeChest = GO_TRIBUTE_CHEST_25H_45;
                                        else
                                            tributeChest = GO_TRIBUTE_CHEST_25H_25;
                            }
                            if (tributeChest)
                                if (Creature* pTirion =  instance->GetCreature(m_uiTirionGUID))
                                    if (GameObject* pChest = pTirion->SummonGameObject(tributeChest,805.62f,134.87f,142.16f,3.27f,0,0,0,0,90000000))
                                        pChest->SetRespawnTime(pChest->GetRespawnDelay());
                            break;
                    }
                    break;
                case TYPE_COUNTER:   m_uiTrialCounter = uiData; uiData = DONE; break;
                case TYPE_EVENT:     m_uiEvent = uiData; uiData = NOT_STARTED; break;
                case TYPE_EVENT_TIMER:      m_uiEventTimer = uiData; uiData = NOT_STARTED; break;
                case TYPE_NORTHREND_BEASTS: 
                    m_uiNorthrendBeasts = uiData; 
                    switch (uiData)
                    {
                        case GORMOK_DONE:
                            m_uiEvent = 200;
                            SetData(TYPE_NORTHREND_BEASTS,IN_PROGRESS);
                            SetData(TYPE_BEASTS,IN_PROGRESS);
                            break;
                        case SNAKES_IN_PROGRESS: m_uiNotOneButTwoJormungarsTimer = 0; break;
                        case SNAKES_SPECIAL: m_uiNotOneButTwoJormungarsTimer = 10*IN_MILLISECONDS; break;
                        case SNAKES_DONE: 
                            if (m_uiNotOneButTwoJormungarsTimer > 0)
                                DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_WORMS_KILLED_IN_10_SECONDS);
                            m_uiEvent = 300;
                            SetData(TYPE_NORTHREND_BEASTS,IN_PROGRESS);
                            SetData(TYPE_BEASTS,IN_PROGRESS);
                            break;
                        case ICEHOWL_DONE:
                            m_uiEvent = 400;
                            SetData(TYPE_NORTHREND_BEASTS,DONE);
                            SetData(TYPE_BEASTS,DONE);
                            break;
                        case FAIL:
                            SetData(TYPE_BEASTS,FAIL);
                            break;
                    }
                    break;
                case DATA_HEALTH_TWIN_SHARED:     m_uiDataDamageTwin = uiData; uiData = NOT_STARTED; break;

                //Achievements
                case DATA_SNOBOLD_COUNT:
                    if (uiData == INCREASE)
                        ++m_uiSnoboldCount;
                    else if (uiData == DECREASE)
                        --m_uiSnoboldCount;
                    break;
                case DATA_MISTRESS_OF_PAIN_COUNT:
                    if (uiData == INCREASE)
                        ++m_uiMistressOfPainCount;
                    else if (uiData == DECREASE)
                        --m_uiMistressOfPainCount;
                    break;
                case DATA_TRIBUTE_TO_IMMORTALITY_ELEGIBLE:
                    m_bTributeToImmortalityElegible = false;
                    break;
            }
            if (IsEncounterInProgress())
            {
                CloseDoor(GetData64(GO_EAST_PORTCULLIS));
                CloseDoor(GetData64(GO_WEB_DOOR));
            } else {
                OpenDoor(GetData64(GO_EAST_PORTCULLIS));
                OpenDoor(GetData64(GO_WEB_DOOR));
            }

            if (uiType < MAX_ENCOUNTERS)
            {
                sLog.outBasic("[ToCr] m_auiEncounter[uiType %u] %u = uiData %u;",uiType,m_auiEncounter[uiType],uiData);
                if (uiData == FAIL)
                { 
                    if (IsRaidWiped()) 
                    { 
                        --m_uiTrialCounter;
                        m_bNeedSave = true;
                        m_uiEvent = (uiType == TYPE_BEASTS? 666 : 0);
                    }
                    uiData = NOT_STARTED;
                }
                m_auiEncounter[uiType] = uiData;

                if (uiData == DONE || m_bNeedSave == true)
                {
                    if (Unit* pAnnouncer = instance->GetCreature(GetData64(NPC_BARRENT)))
                        pAnnouncer->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    Save();
                }
            }
        }

        uint64 GetData64(uint32 uiData)
        {
            switch(uiData)
            {
                case NPC_BARRENT:  return m_uiBarrentGUID;
                case NPC_TIRION:   return m_uiTirionGUID;
                case NPC_FIZZLEBANG: return m_uiFizzlebangGUID;
                case NPC_GARROSH:  return m_uiGarroshGUID;
                case NPC_VARIAN:     return m_uiVarianGUID;

                case NPC_GORMOK: return m_uiGormokGUID;
                case NPC_ACIDMAW: return m_uiAcidmawGUID;
                case NPC_DREADSCALE: return m_uiDreadscaleGUID;
                case NPC_ICEHOWL: return m_uiIcehowlGUID;
                case NPC_JARAXXUS: return m_uiJaraxxusGUID;
                case NPC_CHAMPIONS_CONTROLLER: return m_uiChampionsControllerGUID;
                case NPC_DARKBANE: return m_uiDarkbaneGUID;
                case NPC_LIGHTBANE: return m_uiLightbaneGUID;
                case NPC_ANUBARAK: return m_uiAnubarakGUID;

                case GO_ARGENT_COLISEUM_FLOOR:  return m_uiFloorGUID;
                case GO_MAIN_GATE_DOOR:         return m_uiMainGateDoorGUID;
                case GO_EAST_PORTCULLIS:        return m_uiEastPortcullisGUID;
                case GO_WEB_DOOR:               return m_uiWebDoorGUID;
            }
            return 0;
        }

        uint32 GetData(uint32 uiType)
        {
            switch(uiType)
            {
                case TYPE_BEASTS:    return m_auiEncounter[TYPE_BEASTS];
                case TYPE_JARAXXUS:  return m_auiEncounter[TYPE_JARAXXUS];
                case TYPE_CRUSADERS: return m_auiEncounter[TYPE_CRUSADERS];
                case TYPE_VALKIRIES: return m_auiEncounter[TYPE_VALKIRIES];
                case TYPE_LICH_KING: return m_auiEncounter[TYPE_LICH_KING];
                case TYPE_ANUBARAK:  return m_auiEncounter[TYPE_ANUBARAK];
                case TYPE_COUNTER:   return m_uiTrialCounter;
                case TYPE_EVENT:     return m_uiEvent;
                case TYPE_NORTHREND_BEASTS:    return m_uiNorthrendBeasts;
                case TYPE_EVENT_TIMER:  return m_uiEventTimer;
                case TYPE_EVENT_NPC: 
                    switch (m_uiEvent) 
                    {
                        case 110:
                        case 140:
                        case 150:
                        case 155:
                        case 200:
                        case 205:
                        case 210:
                        case 220:
                        case 300:
                        case 305:
                        case 310:
                        case 315:
                        case 400:
                        case 666:
                        case 1010:
                        case 1180:
                        case 2000:
                        case 2030:
                        case 3000:
                        case 3001:
                        case 3060:
                        case 3061:
                        case 3090:
                        case 3091:
                        case 3092:
                        case 3100:
                        case 3110:
                        case 4000:
                        case 4010:
                        case 4015:
                        case 4016:
                        case 4040:
                        case 4050:
                        case 5000:
                        case 5005:
                        case 5020:
                        case 6000:
                        case 6005:
                        case 6010:
                            m_uiEventNPCId = NPC_TIRION;
                            break;
                        case 5010:
                        case 5030:
                        case 5040:
                        case 5050:
                        case 5060:
                        case 5070:
                        case 5080:
                            m_uiEventNPCId = NPC_LICH_KING_1;
                            break;
                        case 120:
                        case 122:
                        case 2020:
                        case 3080:
                        case 3051:
                        case 3071:
                        case 4020:
                            m_uiEventNPCId = NPC_VARIAN;
                            break;
                        case 130:
                        case 132:
                        case 2010:
                        case 3050:
                        case 3070:
                        case 3081:
                        case 4030:
                            m_uiEventNPCId = NPC_GARROSH;
                            break;
                        case 1110:
                        case 1120:
                        case 1130:
                        case 1132:
                        case 1134:
                        case 1135:
                        case 1140:
                        case 1142:
                        case 1144:
                        case 1150:
                            m_uiEventNPCId = NPC_FIZZLEBANG;
                            break;
                        default:
                            m_uiEventNPCId = NPC_TIRION;
                            break;
                    };
                    return m_uiEventNPCId;
                case DATA_HEALTH_TWIN_SHARED: return m_uiDataDamageTwin;
            }
            return 0;
        }

        void Update(uint32 uiDiff)
        {
            if (GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL)
            {
                if (m_uiNotOneButTwoJormungarsTimer)
                    if (m_uiNotOneButTwoJormungarsTimer <= uiDiff)
                        m_uiNotOneButTwoJormungarsTimer = 0;
                    else m_uiNotOneButTwoJormungarsTimer -= uiDiff;
            }

            if (GetData(TYPE_CRUSADERS) == IN_PROGRESS)
            {
                if (m_uiResilienceWillFixItTimer)
                    if (m_uiResilienceWillFixItTimer <= uiDiff)
                        m_uiResilienceWillFixItTimer = 0;
                    else m_uiResilienceWillFixItTimer -= uiDiff;
            }
        }

        void Save()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                saveStream << m_auiEncounter[i] << " ";

            saveStream << m_uiTrialCounter;
            m_strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
            m_bNeedSave = false;
        }

        std::string GetSaveData()
        {
            return m_strInstData;
        }

        void Load(const char* strIn)
        {
            if (!strIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(strIn);

            std::istringstream loadStream(strIn);

            for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
            {
                loadStream >> m_auiEncounter[i];

                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
            }
            loadStream >> m_uiTrialCounter;
            m_uiEvent = 0;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/)
        {
            switch (criteria_id)
            {
                case UPPER_BACK_PAIN_10_PLAYER:
                case UPPER_BACK_PAIN_10_PLAYER_HEROIC:
                    return m_uiSnoboldCount >= 2;
                case UPPER_BACK_PAIN_25_PLAYER:
                case UPPER_BACK_PAIN_25_PLAYER_HEROIC:
                    return m_uiSnoboldCount >= 4;
                case THREE_SIXTY_PAIN_SPIKE_10_PLAYER:
                case THREE_SIXTY_PAIN_SPIKE_10_PLAYER_HEROIC:
                case THREE_SIXTY_PAIN_SPIKE_25_PLAYER:
                case THREE_SIXTY_PAIN_SPIKE_25_PLAYER_HEROIC:
                    return m_uiMistressOfPainCount >= 2;
                case A_TRIBUTE_TO_SKILL_10_PLAYER:
                case A_TRIBUTE_TO_SKILL_25_PLAYER:
                    return m_uiTrialCounter >= 25;
                case A_TRIBUTE_TO_MAD_SKILL_10_PLAYER:
                case A_TRIBUTE_TO_MAD_SKILL_25_PLAYER:
                    return m_uiTrialCounter >= 45;
                case A_TRIBUTE_TO_INSANITY_10_PLAYER:
                case A_TRIBUTE_TO_INSANITY_25_PLAYER:
                case REALM_FIRST_GRAND_CRUSADER:
                    return m_uiTrialCounter == 50;
                case A_TRIBUTE_TO_IMMORTALITY_HORDE:
                case A_TRIBUTE_TO_IMMORTALITY_ALLIANCE:
                    return m_uiTrialCounter == 50 && m_bTributeToImmortalityElegible;
                case A_TRIBUTE_TO_DEDICATED_INSANITY:
                    return false/*uiGrandCrusaderAttemptsLeft == 50 && !bHasAtAnyStagePlayerEquippedTooGoodItem*/;
            }

            return false;
        }
    };

};


void AddSC_instance_trial_of_the_crusader()
{
    new instance_trial_of_the_crusader();
}
