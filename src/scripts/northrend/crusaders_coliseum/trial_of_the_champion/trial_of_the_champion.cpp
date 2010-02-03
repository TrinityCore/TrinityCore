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
SDName: Trial Of the Champion
SD%Complete:
SDComment:
SDCategory: trial_of_the_champion
EndScriptData */

/* ContentData
npc_announcer_toc5
EndContentData */

#include "ScriptedPch.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"

#define GOSSIP_START_EVENT1     "I'm ready to start challenge."
#define GOSSIP_START_EVENT2     "I'm ready for the next challenge."

#define ORIENTATION             4.714

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition = {746.261,657.401,411.681,4.65};

struct TRINITY_DLL_DECL npc_announcer_toc5AI : public ScriptedAI
{
    npc_announcer_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();

        uiSummonTimes = 0;
        uiPosition = 0;
        uiLesserChampions = 0;

        uiFirstBoss = 0;
        uiSecondBoss = 0;
        uiThirdBoss = 0;

        uiArgentChampion = 0;

        uiPhase = 0;
        uiTimer = 0;

        uiVehicle1GUID = 0;
        uiVehicle2GUID = 0;
        uiVehicle3GUID = 0;

        Champion1List.clear();
        Champion2List.clear();
        Champion3List.clear();

        m_creature->SetReactState(REACT_PASSIVE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

        SetGrandChampionsForEncounter();
        SetArgentChampion();
    }

    ScriptedInstance* pInstance;

    uint8 uiSummonTimes;
    uint8 uiPosition;
    uint8 uiLesserChampions;

    uint32 uiArgentChampion;

    uint32 uiFirstBoss;
    uint32 uiSecondBoss;
    uint32 uiThirdBoss;

    uint32 uiPhase;
    uint32 uiTimer;

    uint64 uiVehicle1GUID;
    uint64 uiVehicle2GUID;
    uint64 uiVehicle3GUID;

    uint64 uiGrandChampionBoss1;

    std::list<uint64> Champion1List;
    std::list<uint64> Champion2List;
    std::list<uint64> Champion3List;

    void NextStep(uint32 uiTimerStep,bool bNextStep = true,uint8 uiPhaseStep = 0)
    {
        uiTimer = uiTimerStep;
        if (bNextStep)
            ++uiPhase;
        else
            uiPhase = uiPhaseStep;
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch (uiType)
        {
            case DATA_START:
                DoSummonGrandChampion(uiFirstBoss);
                NextStep(10000,false,1);
                break;
            case DATA_IN_POSITION: //movement done.
                m_creature->GetMotionMaster()->MovePoint(1,735.81,661.92,412.39);
                if (GameObject* pGO = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_MAIN_GATE)))
                    pInstance->HandleGameObject(pGO->GetGUID(),false);
                NextStep(10000,false,3);
                break;
            case DATA_LESSER_CHAMPIONS_DEFEATED:
            {
                ++uiLesserChampions;
                std::list<uint64> TempList;
                if (uiLesserChampions == 3 || uiLesserChampions == 6)
                {
                    switch(uiLesserChampions)
                    {
                        case 3:
                            TempList = Champion2List;
                            break;
                        case 6:
                            TempList = Champion3List;
                            break;
                    }

                    for(std::list<uint64>::iterator itr = TempList.begin(); itr != TempList.end(); ++itr)
                        if (Creature* pSummon = Unit::GetCreature(*m_creature, *itr))
                            AggroAllPlayers(pSummon);
                }else if (uiLesserChampions == 9)
                    StartGrandChampionsAttack();

                break;
            }
        }
    }

    void StartGrandChampionsAttack()
    {
        Creature* pGrandChampion1 = Unit::GetCreature(*m_creature, uiVehicle1GUID);
        Creature* pGrandChampion2 = Unit::GetCreature(*m_creature, uiVehicle2GUID);
        Creature* pGrandChampion3 = Unit::GetCreature(*m_creature, uiVehicle3GUID);

        if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
        {
            AggroAllPlayers(pGrandChampion1);
            AggroAllPlayers(pGrandChampion2);
            AggroAllPlayers(pGrandChampion3);
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == 1)
        {
            m_creature->SetOrientation(ORIENTATION);
            m_creature->SendMovementFlagUpdate();
        }
    }

    void DoSummonGrandChampion(uint32 uiBoss)
    {
        ++uiSummonTimes;
        uint32 VEHICLE_TO_SUMMON1 = 0;
        uint32 VEHICLE_TO_SUMMON2 = 0;
        switch(uiBoss)
        {
            case 0:
                VEHICLE_TO_SUMMON1 = VEHICLE_MOKRA_SKILLCRUSHER_MOUNT;
                VEHICLE_TO_SUMMON2 = VEHICLE_ORGRIMMAR_WOLF;
                break;
            case 1:
                VEHICLE_TO_SUMMON1 = VEHICLE_ERESSEA_DAWNSINGER_MOUNT;
                VEHICLE_TO_SUMMON2 = VEHICLE_SILVERMOON_HAWKSTRIDER;
                break;
            case 2:
                VEHICLE_TO_SUMMON1 = VEHICLE_RUNOK_WILDMANE_MOUNT;
                VEHICLE_TO_SUMMON2 = VEHICLE_THUNDER_BLUFF_KODO;
                break;
            case 3:
                VEHICLE_TO_SUMMON1 = VEHICLE_ZUL_TORE_MOUNT;
                VEHICLE_TO_SUMMON2 = VEHICLE_DARKSPEAR_RAPTOR;
                break;
            case 4:
                VEHICLE_TO_SUMMON1 = VEHICLE_DEATHSTALKER_VESCERI_MOUNT;
                VEHICLE_TO_SUMMON2 = VEHICLE_FORSAKE_WARHORSE;
                break;
            default:
                return;
        }

        if (Creature* pBoss = m_creature->SummonCreature(VEHICLE_TO_SUMMON1,SpawnPosition))
        {
            switch(uiSummonTimes)
            {
                case 1:
                {
                    uiVehicle1GUID = pBoss->GetGUID();
                    uint64 uiGrandChampionBoss1 = 0;
                    if (Creature* pBoss = Unit::GetCreature(*m_creature, uiVehicle1GUID))
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* pUnit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss1 = pUnit->GetGUID();
                    if (pInstance)
                    {
                        pInstance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_1,uiVehicle1GUID);
                        pInstance->SetData64(DATA_GRAND_CHAMPION_1,uiGrandChampionBoss1);
                    }
                    pBoss->AI()->SetData(1,0);
                    break;
                }
                case 2:
                {
                    uiVehicle2GUID = pBoss->GetGUID();
                    uint64 uiGrandChampionBoss2 = 0;
                    if (Creature* pBoss = Unit::GetCreature(*m_creature, uiVehicle2GUID))
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* pUnit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss2 = pUnit->GetGUID();
                    if (pInstance)
                    {
                        pInstance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_2,uiVehicle2GUID);
                        pInstance->SetData64(DATA_GRAND_CHAMPION_2,uiGrandChampionBoss2);
                    }
                    pBoss->AI()->SetData(2,0);
                    break;
                }
                case 3:
                {
                    uiVehicle3GUID = pBoss->GetGUID();
                    uint64 uiGrandChampionBoss3 = 0;
                    if (Creature* pBoss = Unit::GetCreature(*m_creature, uiVehicle3GUID))
                        if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                            if (Unit* pUnit = pVehicle->GetPassenger(0))
                                uiGrandChampionBoss3 = pUnit->GetGUID();
                    if (pInstance)
                    {
                        pInstance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_3,uiVehicle3GUID);
                        pInstance->SetData64(DATA_GRAND_CHAMPION_3,uiGrandChampionBoss3);
                    }
                    pBoss->AI()->SetData(3,0);
                    break;
                }
                default:
                    return;
            }

            for (uint8 i = 0; i < 3; ++i)
            {
                if (Creature* pAdd = m_creature->SummonCreature(VEHICLE_TO_SUMMON2,SpawnPosition,TEMPSUMMON_CORPSE_DESPAWN))
                {
                    switch(uiSummonTimes)
                    {
                        case 1:
                            Champion1List.push_back(pAdd->GetGUID());
                            break;
                        case 2:
                            Champion2List.push_back(pAdd->GetGUID());
                            break;
                        case 3:
                            Champion3List.push_back(pAdd->GetGUID());
                            break;
                    }

                    switch(i)
                    {
                        case 0:
                            pAdd->GetMotionMaster()->MoveFollow(pBoss,2.0f,M_PI);
                            break;
                        case 1:
                            pAdd->GetMotionMaster()->MoveFollow(pBoss,2.0f,M_PI / 2);
                            break;
                        case 2:
                            pAdd->GetMotionMaster()->MoveFollow(pBoss,2.0f,M_PI / 2 + M_PI);
                            break;
                    }
                }

            }
        }
    }

    void DoStartArgentChampionEncounter()
    {
        m_creature->GetMotionMaster()->MovePoint(1,735.81,661.92,412.39);

        if (Creature* pBoss = m_creature->SummonCreature(uiArgentChampion,SpawnPosition))
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                if (Creature* pTrash = m_creature->SummonCreature(NPC_ARGENT_LIGHWIELDER,SpawnPosition))
                    pTrash->AI()->SetData(i,0);
                if (Creature* pTrash = m_creature->SummonCreature(NPC_ARGENT_MONK,SpawnPosition))
                    pTrash->AI()->SetData(i,0);
                if (Creature* pTrash = m_creature->SummonCreature(NPC_PRIESTESS,SpawnPosition))
                    pTrash->AI()->SetData(i,0);
            }
        }
    }

    void SetGrandChampionsForEncounter()
    {
        uiFirstBoss = urand(0,4);

        while(uiSecondBoss == uiFirstBoss || uiThirdBoss == uiFirstBoss || uiThirdBoss == uiSecondBoss)
        {
            uiSecondBoss = urand(0,4);
            uiThirdBoss = urand(0,4);
        }
    }

    void SetArgentChampion()
    {
       uint8 uiTempBoss = urand(0,1);

       switch(uiTempBoss)
       {
            case 0:
                uiArgentChampion = NPC_EADRIC;
                break;
            case 1:
                uiArgentChampion = NPC_PALETRESS;
                break;
       }
    }

    void StartEncounter()
    {
        if (!pInstance)
            return;

        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

        if (pInstance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
        {
            if (pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
            {
                if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
                    m_creature->AI()->SetData(DATA_START,0);

                if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE)
                    DoStartArgentChampionEncounter();
            }

           if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
               pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE ||
               pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE)
                m_creature->SummonCreature(VEHICLE_BLACK_KNIGHT,769.834,651.915,447.035,0);
        }
    }

    void AggroAllPlayers(Creature* pTemp)
    {
        Map::PlayerList const &PlList = m_creature->GetMap()->GetPlayers();

        if(PlList.isEmpty())
            return;

        for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
        {
            if(Player* pPlayer = i->getSource())
            {
                if(pPlayer->isGameMaster())
                    continue;

                if(pPlayer->isAlive())
                {
                    pTemp->SetHomePosition(m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(),m_creature->GetOrientation());
                    pTemp->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                    pTemp->SetReactState(REACT_AGGRESSIVE);
                    pTemp->SetInCombatWith(pPlayer);
                    pPlayer->SetInCombatWith(pTemp);
                    pTemp->AddThreat(pPlayer, 0.0f);
                }
            }
        }
    }


   void UpdateAI(const uint32 uiDiff)
    {
        ScriptedAI::UpdateAI(uiDiff);

        if (uiTimer <= uiDiff)
        {
            switch(uiPhase)
            {
                case 1:
                    DoSummonGrandChampion(uiSecondBoss);
                    NextStep(10000,true);
                    break;
                case 2:
                    DoSummonGrandChampion(uiThirdBoss);
                    NextStep(0,false);
                    break;
                case 3:
                    if (!Champion1List.empty())
                    {
                        for(std::list<uint64>::iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                            if (Creature* pSummon = Unit::GetCreature(*m_creature, *itr))
                                AggroAllPlayers(pSummon);
                        NextStep(0,false);
                    }
                    break;
            }
        } else uiTimer -= uiDiff;

        if (!UpdateVictim())
            return;
    }

    void JustSummoned(Creature* pSummon)
    {
        if (pInstance && pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
        {
            pSummon->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
            pSummon->SetReactState(REACT_PASSIVE);
        }
    }

    void SummonedCreatureDespawn(Creature* pSummon)
    {
        switch(pSummon->GetEntry())
        {
            case VEHICLE_DARNASSIA_NIGHTSABER:
            case VEHICLE_EXODAR_ELEKK:
            case VEHICLE_STORMWIND_STEED:
            case VEHICLE_GNOMEREGAN_MECHANOSTRIDER:
            case VEHICLE_IRONFORGE_RAM:
            case VEHICLE_FORSAKE_WARHORSE:
            case VEHICLE_THUNDER_BLUFF_KODO:
            case VEHICLE_ORGRIMMAR_WOLF:
            case VEHICLE_SILVERMOON_HAWKSTRIDER:
            case VEHICLE_DARKSPEAR_RAPTOR:
                m_creature->AI()->SetData(DATA_LESSER_CHAMPIONS_DEFEATED,0);
                break;
        }
    }
};

CreatureAI* GetAI_npc_announcer_toc5(Creature* pCreature)
{
    return new npc_announcer_toc5AI(pCreature);
}

bool GossipHello_npc_announcer_toc5(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();

    if (pInstance &&
        pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
        pInstance->GetData(BOSS_BLACK_KNIGHT) == DONE &&
        pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE ||
        pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE)
        return false;

    if (pInstance &&
        pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED &&
        pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED &&
        pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED &&
        pInstance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    else if (pInstance)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_announcer_toc5(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        CAST_AI(npc_announcer_toc5AI, pCreature->AI())->StartEncounter();
    }

    return true;
}

void AddSC_trial_of_the_champion()
{
    Script* NewScript;

    NewScript = new Script;
    NewScript->Name = "npc_announcer_toc5";
    NewScript->GetAI = &GetAI_npc_announcer_toc5;
    NewScript->pGossipHello = &GossipHello_npc_announcer_toc5;
    NewScript->pGossipSelect = &GossipSelect_npc_announcer_toc5;
    NewScript->RegisterSelf();
}
