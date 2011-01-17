/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/
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
#include "trial_of_the_champion.h"
#include "Vehicle.h"

#define GOSSIP_START_EVENT1     "Я готов к старту испытания."
#define GOSSIP_START_EVENT2     "Я готов к следующему испытанию."

#define ORIENTATION             4.714f

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition = {746.843f, 695.68f, 412.339f, 4.70776f};

enum eEnums
{
    SAY_START             = -1999926,
    SAY_START2            = -1999950,
    SAY_START3            = -1999940,
    SAY_START5            = -1999936,
    SAY_START11           = -1999953,
    AN_1                  = -1999942,
    AN_2                  = -1999943,
    AN_3                  = -1999944,
    AN_4                  = -1999945,
    AN_5                  = -1999946,
    AN_6                  = -1999947,
    AN_7                  = -1999948,
    AN_8                  = -1999949
};

enum IntroPhase
{
    IDLE,
    INTRO,
    FINISHED
};

enum Creatures
{
    CREATURE_TRALL                        = 34994,
    CREATURE_GARROSH                      = 34995,
    CREATURE_KING                         = 34990,
    CREATURE_LADY                         = 34992,
    CREATURE_HIGHLORD                     = 34996,
    CREATURE_ANNOUNCER                    = 35004
};


class npc_anstart : public CreatureScript
{
public:
    npc_anstart() : CreatureScript("npc_anstart") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_anstartAI (pCreature);
    }

    struct npc_anstartAI : public ScriptedAI
    {
        npc_anstartAI(Creature *pCreature) : ScriptedAI(pCreature)

        {
        pInstance = (InstanceScript*)pCreature->GetInstanceScript();
        }

        uint32 uiIntroTimer;

        uint8 uiIntroPhase;

        IntroPhase Phase;

        Creature* pTrall;
        Creature* pGarrosh;
        Creature* pKing;
        Creature* pLady;
        Creature* pHighlord;

        InstanceScript* pInstance;



        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
            Phase = IDLE;
            uiIntroTimer = 0;
            uiIntroPhase = 0;
            pTrall = NULL;
            pGarrosh = NULL;
            pKing = NULL;
            pLady = NULL;
            pHighlord = NULL;
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (!pWho)
                return;
            if (Phase == IDLE && pWho->isTargetableForAttack() && me->IsHostileTo(pWho) && me->IsWithinDistInMap(pWho, 20))
            {
                Phase = INTRO;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (pTrall = me->SummonCreature(CREATURE_TRALL, 685.569f, 615.103f, 435.396f, 6.23544f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pTrall->SetReactState(REACT_PASSIVE);
                    pTrall->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pGarrosh = me->SummonCreature(CREATURE_GARROSH, 685.7f, 621.134f, 435.396f, 6.259f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pGarrosh->SetReactState(REACT_PASSIVE);
                    pGarrosh->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pKing = me->SummonCreature(CREATURE_KING, 807.724f, 617.9f, 435.396f, 3.18416f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pKing->SetReactState(REACT_PASSIVE);
                    pKing->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pLady = me->SummonCreature(CREATURE_LADY, 807.401f, 613.667f, 435.397f, 3.0585f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pLady->SetReactState(REACT_PASSIVE);
                    pLady->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pHighlord = me->SummonCreature(CREATURE_HIGHLORD, 746.482f, 556.857f, 435.396f, 1.5898f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pHighlord->SetReactState(REACT_PASSIVE);
                    pHighlord->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void AttackStart(Unit* who) {}

        void UpdateAI(const uint32 diff)
        {

            if (Phase != INTRO)
                return;

            if (uiIntroTimer <= diff)
            {
                if(!pTrall)
                    return;
                if(!pGarrosh)
                    return;
                if(!pKing)
                    return;
                if(!pLady)
                    return;
                if(!pHighlord)
                    return;

                switch (uiIntroPhase)
                {
                    case 0:
                        ++uiIntroPhase;
                        uiIntroTimer = 4000;
                        break;
                    case 1:
                        DoScriptText(AN_1, me);
                        ++uiIntroPhase;
                        uiIntroTimer = 10000;
                        break;
                    case 2:
                        DoScriptText(AN_2, me);
                        ++uiIntroPhase;
                        uiIntroTimer = 13000;
                        break;
                    case 3:
                        DoScriptText(AN_3, pTrall);
                        ++uiIntroPhase;
                        uiIntroTimer = 8000;
                        break;
                    case 4:
                        DoScriptText(AN_4, pGarrosh);
                        ++uiIntroPhase;
                        uiIntroTimer = 6000;
                        break;
                    case 5:
                        DoScriptText(AN_5, pKing);
                        ++uiIntroPhase;
                        uiIntroTimer = 8000;
                        break;
                    case 6:
                        DoScriptText(AN_6, pLady);
                        ++uiIntroPhase;
                        uiIntroTimer = 8000;
                        break;
                    case 7:
                        DoScriptText(AN_7, pHighlord);
                        ++uiIntroPhase;
                        uiIntroTimer = 3000;
                        break;
                    case 8:
                        DoScriptText(AN_8, me);
                        ++uiIntroPhase;
                        uiIntroTimer = 4000;
                        break;
                    case 9:
                        if (Creature* pAnnouncertoc5 = me->SummonCreature(CREATURE_ANNOUNCER, 746.626f, 618.54f, 411.09f, 4.63158f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000))
                        {
                            me->DisappearAndDie();
                               pAnnouncertoc5->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pAnnouncertoc5->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncertoc5->SetReactState(REACT_PASSIVE);

                            Phase = FINISHED;
                        }
                        else Reset();
                        return;
                }
            } else uiIntroTimer -= diff;
        }
    };
};

class npc_announcer_toc5 : public CreatureScript
{
public:
    npc_announcer_toc5() : CreatureScript("npc_announcer_toc5") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_announcer_toc5AI(pCreature);
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_announcer_toc5AI, pCreature->AI())->StartEncounter();
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* pInstance = (InstanceScript*)pCreature->GetInstanceScript();

        if (pInstance &&
            pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
            pInstance->GetData(BOSS_BLACK_KNIGHT) == DONE &&
            (pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE ||
            pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE))

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

    struct npc_announcer_toc5AI : public ScriptedAI
    {
        npc_announcer_toc5AI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = (InstanceScript*)pCreature->GetInstanceScript();

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

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            SetGrandChampionsForEncounter();
            SetArgentChampion();
        }

        InstanceScript* pInstance;

        uint8 uiSummonTimes;
        uint8 uiPosition;
        uint8 uiLesserChampions;

        uint32 uiArgentChampion;

        uint32 uiFirstBoss;
        uint32 uiSecondBoss;
        uint32 uiThirdBoss;

        uint32 uiPhase;
        uint32 uiTimer;

        uint64 uiBlackKnightGUID;
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
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),true);
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                        pInstance->HandleGameObject(pGO->GetGUID(),false);
                    DoScriptText(SAY_START, me);
                    DoSummonGrandChampion(uiFirstBoss);
                    NextStep(10000,false,1);
                    break;
                case DATA_IN_POSITION: //movement done.
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MovePoint(1,735.898f, 651.961f, 411.93f);
                    DoScriptText(SAY_START2, me);
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(),false);
                    NextStep(20000,false,3);
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

                        for (std::list<uint64>::const_iterator itr = TempList.begin(); itr != TempList.end(); ++itr)
                            if (Creature* pSummon = Unit::GetCreature(*me, *itr))
                                AggroAllPlayers(pSummon);
                    }else if (uiLesserChampions == 9)
                        StartGrandChampionsAttack();

                    break;
                }
            }
        }

        void StartGrandChampionsAttack()
        {
            Creature* pGrandChampion1 = Unit::GetCreature(*me, uiVehicle1GUID);
            Creature* pGrandChampion2 = Unit::GetCreature(*me, uiVehicle2GUID);
            Creature* pGrandChampion3 = Unit::GetCreature(*me, uiVehicle3GUID);

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
                me->SetOrientation(ORIENTATION);
                me->SendMovementFlagUpdate();
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

            if (Creature* pBoss = me->SummonCreature(VEHICLE_TO_SUMMON1,SpawnPosition))
            {
                switch(uiSummonTimes)
                {
                    case 1:
                    {
                        uiVehicle1GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss1 = 0;
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle1GUID))
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
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle2GUID))
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
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle3GUID))
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
                    if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2,SpawnPosition,TEMPSUMMON_CORPSE_DESPAWN))
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
            DoScriptText(SAY_START3, me);
            if (Creature* pBoss = me->SummonCreature(uiArgentChampion,SpawnPosition))
            {

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_LIGHWIELDER,SpawnPosition))
                        pTrash->AI()->SetData(i,0);
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_MONK,SpawnPosition))
                        pTrash->AI()->SetData(i,0);
                    if (Creature* pTrash = me->SummonCreature(NPC_PRIESTESS,SpawnPosition))
                        pTrash->AI()->SetData(i,0);
                }
            }
        }

        void EnterCombat(Unit* pWho)
        {

        }

        void SetGrandChampionsForEncounter()
        {
            uiFirstBoss = urand(0,4);

            while (uiSecondBoss == uiFirstBoss || uiThirdBoss == uiFirstBoss || uiThirdBoss == uiSecondBoss)
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

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                        pInstance->HandleGameObject(pGO->GetGUID(),false);

            if (pInstance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            {
                if (pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
                {
                    if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
                        me->AI()->SetData(DATA_START,0);

                    if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE)
                        DoStartArgentChampionEncounter();
                }

               if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
                   pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE ||
                   pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE)
                {
                   if (Unit* pBlackKnight = me->SummonCreature(VEHICLE_BLACK_KNIGHT,801.369507f, 640.574280f, 469.314362f, 3.97124f,TEMPSUMMON_DEAD_DESPAWN,180000))
                    {
                                uiBlackKnightGUID = pBlackKnight->GetGUID();
                                pBlackKnight->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                pBlackKnight->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                                me->SetUInt64Value(UNIT_FIELD_TARGET, uiBlackKnightGUID);
                                if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                                                pInstance->HandleGameObject(pGO->GetGUID(),false);
                    }
                    me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoScriptText(SAY_START5, me);
                }

            }
        }

        void Reset()
        {
            uiBlackKnightGUID = 0;
        }

        void AggroAllPlayers(Creature* pTemp)
        {
            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                if (Player* pPlayer = i->getSource())
                {
                    if (pPlayer->isGameMaster())
                        continue;

                    if (pPlayer->isAlive())
                    {
                        pTemp->SetHomePosition(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation());
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
                            for (std::list<uint64>::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                                if (Creature* pSummon = Unit::GetCreature(*me, *itr))
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
                    me->AI()->SetData(DATA_LESSER_CHAMPIONS_DEFEATED,0);
                    break;
            }
        }
    };

};

void AddSC_trial_of_the_champion()
{
    new npc_anstart();
    new npc_announcer_toc5();
}