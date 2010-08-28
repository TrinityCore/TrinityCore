/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Gnomeregan
SDAuthor: Manuel
SD%Complete: 90%
SDComment: Some visual effects are not implemented.
Script Data End */

#include "ScriptPCH.h"
#include "gnomeregan.h"
#include "ScriptedEscortAI.h"

#define GOSSIP_START_EVENT "I am ready to being"

enum eBlastmasterEmiShortfuse
{
    GOSSIP_TEXT_EMI     = 1693,

    SAY_BLASTMASTER_0   = -1090000,
    SAY_BLASTMASTER_1   = -1090001,
    SAY_BLASTMASTER_2   = -1090002,
    SAY_BLASTMASTER_3   = -1090003,
    SAY_BLASTMASTER_4   = -1090004,
    SAY_BLASTMASTER_5   = -1090005,
    SAY_BLASTMASTER_6   = -1090006,
    SAY_BLASTMASTER_7   = -1090007,
    SAY_BLASTMASTER_8   = -1090008,
    SAY_BLASTMASTER_9   = -1090009,
    SAY_BLASTMASTER_10  = -1090010,
    SAY_BLASTMASTER_11  = -1090011,
    SAY_BLASTMASTER_12  = -1090012,
    SAY_BLASTMASTER_13  = -1090013,
    SAY_BLASTMASTER_14  = -1090014,
    SAY_BLASTMASTER_15  = -1090015,
    SAY_BLASTMASTER_16  = -1090016,
    SAY_BLASTMASTER_17  = -1090017,
    SAY_BLASTMASTER_18  = -1090018,
    SAY_BLASTMASTER_19  = -1090019,
    SAY_BLASTMASTER_20  = -1090020,
    SAY_BLASTMASTER_21  = -1090021,
    SAY_BLASTMASTER_22  = -1090022,
    SAY_BLASTMASTER_23  = -1090023,
    SAY_BLASTMASTER_24  = -1090024,
    SAY_BLASTMASTER_25  = -1090025,
    SAY_BLASTMASTER_26  = -1090026,
    SAY_BLASTMASTER_27  = -1090027,

    SAY_GRUBBIS         = -1090028
};

const Position SpawnPosition[] =
{
    {-557.630f,-114.514f,-152.209f,0.641f},
    {-555.263f,-113.802f,-152.737f,0.311f},
    {-552.154f,-112.476f,-153.349f,0.621f},
    {-548.692f,-111.089f,-154.090f,0.621f},
    {-546.905f,-108.340f,-154.877f,0.729f},
    {-547.736f,-105.154f,-155.176f,0.372f},
    {-547.274f,-114.109f,-153.952f,0.735f},
    {-552.534f,-110.012f,-153.577f,0.747f},
    {-550.708f,-116.436f,-153.103f,0.679f},
    {-554.030f,-115.983f,-152.635f,0.695f},
    {-494.595f,-87.516f,149.116f,3.344f},
    {-493.349f,-90.845f,-148.882f,3.717f},
    {-491.995f,-87.619f,-148.197f,3.230f},
    {-490.732f,-90.739f,-148.091f,3.230f},
    {-490.554f,-89.114f,-148.055f,3.230f},
    {-495.240f,-90.808f,-149.493f,3.238f},
    {-494.195f,-89.553f,-149.131f,3.254f}
};

class npc_blastmaster_emi_shortfuse : public CreatureScript
{
public:
    npc_blastmaster_emi_shortfuse() : CreatureScript("npc_blastmaster_emi_shortfuse") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_blastmaster_emi_shortfuseAI(pCreature);
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_blastmaster_emi_shortfuse::npc_blastmaster_emi_shortfuseAI, pCreature->AI()))
                pEscortAI->Start(true, false,pPlayer->GetGUID());

            pCreature->setFaction(pPlayer->getFaction());
            pCreature->AI()->SetData(1,0);

            pPlayer->CLOSE_GOSSIP_MENU();
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();

        if (pInstance && pInstance->GetData(TYPE_EVENT) == NOT_STARTED)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_EMI, pCreature->GetGUID());

        return true;
    }

    struct npc_blastmaster_emi_shortfuseAI : public npc_escortAI
    {
        npc_blastmaster_emi_shortfuseAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            pCreature->RestoreFaction();
            Reset();
        }

        InstanceScript* pInstance;

        uint8 uiPhase;
        uint32 uiTimer;

        std::list<uint64> SummonList;
        std::list<uint64> GoSummonList;

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                uiTimer = 0;
                uiPhase = 0;

                RestoreAll();

                SummonList.clear();
                GoSummonList.clear();
            }
        }

        void NextStep(uint32 uiTimerStep,bool bNextStep = true,uint8 uiPhaseStep = 0)
        {
            uiTimer = uiTimerStep;
            if (bNextStep)
                ++uiPhase;
            else
                uiPhase = uiPhaseStep;
        }

        void CaveDestruction(bool bBool)
        {
            if (GoSummonList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = GoSummonList.begin(); itr != GoSummonList.end(); ++itr)
            {
               if (GameObject* pGo = GameObject::GetGameObject(*me, *itr))
               {
                    if (pGo)
                    {
                        if (Creature *trigger = pGo->SummonTrigger(pGo->GetPositionX(), pGo->GetPositionY(),pGo->GetPositionZ(), 0, 1))
                        {
                            //visual effects are not working! ¬¬
                            trigger->CastSpell(trigger,11542,true);
                            trigger->CastSpell(trigger,35470,true);
                        }
                        pGo->RemoveFromWorld();
                        //pGo->CastSpell(me,12158); makes all die?!
                    }
               }
            }

           if (bBool)
           {
                if (pInstance)
                    if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                        pInstance->HandleGameObject(NULL,false,pGo);
           }else
                if (pInstance)
                    if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                        pInstance->HandleGameObject(NULL,false,pGo);
        }

        void SetInFace(bool bBool)
        {
            if (!pInstance)
                return;

            if (bBool)
            {
                if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                    me->SetFacingToObject(pGo);
            }else
                if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                    me->SetFacingToObject(pGo);
        }

        void RestoreAll()
        {
            if (!pInstance)
                return;

            if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                pInstance->HandleGameObject(NULL,false,pGo);

            if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                pInstance->HandleGameObject(NULL,false,pGo);

            if (!GoSummonList.empty())
                for (std::list<uint64>::const_iterator itr = GoSummonList.begin(); itr != GoSummonList.end(); ++itr)
                {
                    if (GameObject* pGo = GameObject::GetGameObject(*me, *itr))
                        pGo->RemoveFromWorld();
                }

            if (!SummonList.empty())
                for (std::list<uint64>::const_iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
                {
                    if (Creature* pSummon = Unit::GetCreature(*me, *itr))
                    {
                        if (pSummon->isAlive())
                            pSummon->DisappearAndDie();
                        else
                            pSummon->RemoveCorpse();
                    }
                }
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
                        pTemp->SetInCombatWith(pPlayer);
                        pPlayer->SetInCombatWith(pTemp);
                        pTemp->AddThreat(pPlayer, 0.0f);
                    }
                }
            }
        }

        void WaypointReached(uint32 uiPoint)
        {
            //just in case
            if (GetPlayerForEscort())
                if (me->getFaction() != GetPlayerForEscort()->getFaction())
                    me->setFaction(GetPlayerForEscort()->getFaction());

            switch(uiPoint)
            {
                case 3:
                    SetEscortPaused(true);
                    NextStep(2000,false,3);
                    break;
                case 7:
                    SetEscortPaused(true);
                    NextStep(2000,false,4);
                    break;
                case 9:
                    NextStep(1000,false,8);
                    break;
                case 10:
                    NextStep(25000,false,10);
                    break;
                case 11:
                    SetEscortPaused(true);
                    SetInFace(true);
                    NextStep(1000,false,11);
                    break;
                case 12:
                    NextStep(25000,false,18);
                    break;
                case 13:
                    Summon(7);
                    NextStep(25000,false,19);
                    break;
                case 14:
                    SetInFace(false);
                    DoScriptText(SAY_BLASTMASTER_26,me);
                    SetEscortPaused(true);
                    NextStep(5000,false,20);
                    break;
            }
        }

        void SetData(uint32 uiI,uint32 uiValue)
        {
            switch(uiI)
            {
                case 1:
                    SetEscortPaused(true);
                    DoScriptText(SAY_BLASTMASTER_0,me);
                    NextStep(1500,true);
                    break;
                case 2:
                    if (!pInstance)
                        return;

                    switch(uiValue)
                    {
                        case 1:
                            pInstance->SetData(TYPE_EVENT, IN_PROGRESS);
                            break;
                        case 2:
                            pInstance->SetData(TYPE_EVENT, DONE);
                            NextStep(5000,false,22);
                            break;
                    }
                    break;
            }
        }

        void Summon(uint8 uiCase)
        {
            switch(uiCase)
            {
                case 1:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[5], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[6], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[8], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    break;
                case 2:
                    if (GameObject* pGo = me->SummonGameObject(183410, -533.140f,-105.322f,-156.016f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(pGo->GetGUID());
                        pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1); //We can't use it!
                    }
                    Summon(3);
                    break;
                case 3:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    DoScriptText(SAY_BLASTMASTER_19,me);
                    break;
                case 4:
                    if (GameObject* pGo = me->SummonGameObject(183410, -542.199f,-96.854f,-155.790f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(pGo->GetGUID());
                        pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    }
                    break;
                case 5:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    DoScriptText(SAY_BLASTMASTER_15,me);
                    break;
                case 6:
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[10], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[11], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[12], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[13], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    me->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[14], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    break;
                case 7:
                    if (GameObject* pGo = me->SummonGameObject(183410, -507.820f,-103.333f,-151.353f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(pGo->GetGUID());
                        pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1); //We can't use it!
                        Summon(6);
                    }
                    break;
                case 8:
                    if (GameObject* pGo = me->SummonGameObject(183410, -511.829f,-86.249f,-151.431f, 0, 0, 0, 0, 0, 1000))
                    {
                        GoSummonList.push_back(pGo->GetGUID());
                        pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1); //We can't use it!
                    }
                    break;
                case 9:
                    if (Creature* pGrubbis = me->SummonCreature(NPC_GRUBBIS, SpawnPosition[15], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000))
                        DoScriptText(SAY_GRUBBIS,pGrubbis);
                    me->SummonCreature(NPC_CHOMPER, SpawnPosition[16], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                    break;
            }
        }

        void UpdateEscortAI(const uint32 uiDiff)
        {
            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch(uiPhase)
                    {
                        case 1:
                            DoScriptText(SAY_BLASTMASTER_1,me);
                            NextStep(1500,true);
                            break;
                        case 2:
                            SetEscortPaused(false);
                            NextStep(0,false,0);
                            break;
                        case 3:
                            DoScriptText(SAY_BLASTMASTER_2,me);
                            SetEscortPaused(false);
                            NextStep(0,false,0);
                            break;
                        case 4:
                            DoScriptText(SAY_BLASTMASTER_3,me);
                            NextStep(3000,true);
                            break;
                        case 5:
                            DoScriptText(SAY_BLASTMASTER_4,me);
                            NextStep(3000,true);
                            break;
                        case 6:
                            SetInFace(true);
                            DoScriptText(SAY_BLASTMASTER_5,me);
                            Summon(1);
                            if (pInstance)
                                if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                                    pInstance->HandleGameObject(NULL,true,pGo);
                            NextStep(3000,true);
                            break;
                        case 7:
                            DoScriptText(SAY_BLASTMASTER_6,me);
                            SetEscortPaused(false);
                            NextStep(0,false,0);
                            break;
                        case 8:
                            me->HandleEmoteCommand(EMOTE_STATE_WORK);
                            NextStep(25000,true);
                            break;
                        case 9:
                            Summon(2);
                            NextStep(0,false);
                            break;
                        case 10:
                            Summon(4);
                            NextStep(0,false);
                            break;
                        case 11:
                            DoScriptText(SAY_BLASTMASTER_17,me);
                            NextStep(5000,true);
                            break;
                        case 12:
                            DoScriptText(SAY_BLASTMASTER_18,me);
                            NextStep(5000,true);
                            break;
                        case 13:
                            DoScriptText(SAY_BLASTMASTER_20,me);
                            CaveDestruction(true);
                            NextStep(8000,true);
                            break;
                        case 14:
                            DoScriptText(SAY_BLASTMASTER_21,me);
                            NextStep(8500,true);
                            break;
                        case 15:
                            DoScriptText(SAY_BLASTMASTER_22,me);
                            NextStep(2000,true);
                            break;
                        case 16:
                            DoScriptText(SAY_BLASTMASTER_23,me);
                            SetInFace(false);
                            if (pInstance)
                                if (GameObject* pGo = GameObject::GetGameObject((*me),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                                    pInstance->HandleGameObject(NULL,true,pGo);
                            NextStep(2000,true);
                            break;
                        case 17:
                            SetEscortPaused(false);
                            DoScriptText(SAY_BLASTMASTER_24,me);
                            Summon(6);
                            NextStep(0,false);
                            break;
                        case 18:
                            Summon(7);
                            NextStep(0,false);
                            break;
                        case 19:
                            SetInFace(false);
                            Summon(8);
                            DoScriptText(SAY_BLASTMASTER_25,me);
                            NextStep(0,false);
                            break;
                        case 20:
                            DoScriptText(SAY_BLASTMASTER_27,me);
                            NextStep(2000,true);
                            break;
                        case 21:
                            Summon(9);
                            NextStep(0,false);
                            break;
                        case 22:
                            CaveDestruction(false);
                            DoScriptText(SAY_BLASTMASTER_20,me);
                            NextStep(0,false);
                            break;
                    }
                } else uiTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* pSummon)
        {
            SummonList.push_back(pSummon->GetGUID());
            AggroAllPlayers(pSummon);
        }
    };

};




class boss_grubbis : public CreatureScript
{
public:
    boss_grubbis() : CreatureScript("boss_grubbis") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_grubbisAI(pCreature);
    }

    struct boss_grubbisAI : public ScriptedAI
    {
        boss_grubbisAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            SetDataSummoner();
        }

        void SetDataSummoner()
        {
            if (!me->isSummon())
                return;

            if (Unit* pSummon = CAST_SUM(me)->GetSummoner())
                CAST_CRE(pSummon)->AI()->SetData(2,1);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (!me->isSummon())
                return;

            if (Unit* pSummon = CAST_SUM(me)->GetSummoner())
                CAST_CRE(pSummon)->AI()->SetData(2,2);
        }
    };

};


void AddSC_gnomeregan()
{
    new npc_blastmaster_emi_shortfuse();
    new boss_grubbis();
}
