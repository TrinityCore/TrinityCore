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

/* Script Data Start
SDName: Gnomeregan
SDAuthor: Manuel
SD%Complete: 90%
SDComment: Some visual effects are not implemented.
Script Data End */

#include "ScriptedPch.h"
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
    {-557.630,-114.514,-152.209,0.641},
    {-555.263,-113.802,-152.737,0.311},
    {-552.154,-112.476,-153.349,0.621},
    {-548.692,-111.089,-154.090,0.621},
    {-546.905,-108.340,-154.877,0.729},
    {-547.736,-105.154,-155.176,0.372},
    {-547.274,-114.109,-153.952,0.735},
    {-552.534,-110.012,-153.577,0.747},
    {-550.708,-116.436,-153.103,0.679},
    {-554.030,-115.983,-152.635,0.695},
    {-494.595,-87.516,149.116,3.344},
    {-493.349,-90.845,-148.882,3.717},
    {-491.995,-87.619,-148.197,3.230},
    {-490.732,-90.739,-148.091,3.230},
    {-490.554,-89.114,-148.055,3.230},
    {-495.240,-90.808,-149.493,3.238},
    {-494.195,-89.553,-149.131,3.254}
};

struct npc_blastmaster_emi_shortfuseAI : public npc_escortAI
{
    npc_blastmaster_emi_shortfuseAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
        pCreature->RestoreFaction();
        Reset();
    }

    ScriptedInstance* pInstance;

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

        for(std::list<uint64>::iterator itr = GoSummonList.begin(); itr != GoSummonList.end(); ++itr)
        {
           if (GameObject* pGo = GameObject::GetGameObject(*m_creature, *itr))
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
                    //pGo->CastSpell(m_creature,12158); makes all die?!
                }
           }
        }

       if (bBool)
       {
            if (pInstance)
                if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                    pInstance->HandleGameObject(NULL,false,pGo);
       }else
            if (pInstance)
                if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                    pInstance->HandleGameObject(NULL,false,pGo);
    }

    void SetInFace(bool bBool)
    {
        if (!pInstance)
            return;

        if (bBool)
        {
            if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                m_creature->SetFacingToObject(pGo);
        }else
            if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                m_creature->SetFacingToObject(pGo);
    }

    void RestoreAll()
    {
        if (!pInstance)
            return;

        if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
            pInstance->HandleGameObject(NULL,false,pGo);

        if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
            pInstance->HandleGameObject(NULL,false,pGo);

        if (!GoSummonList.empty())
            for(std::list<uint64>::iterator itr = GoSummonList.begin(); itr != GoSummonList.end(); ++itr)
            {
                if (GameObject* pGo = GameObject::GetGameObject(*m_creature, *itr))
                    pGo->RemoveFromWorld();
            }

        if (!SummonList.empty())
            for(std::list<uint64>::iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
            {
                if (Creature* pSummon = Unit::GetCreature(*m_creature, *itr))
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
            if (m_creature->getFaction() != GetPlayerForEscort()->getFaction())
                m_creature->setFaction(GetPlayerForEscort()->getFaction());

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
                DoScriptText(SAY_BLASTMASTER_26,m_creature);
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
                DoScriptText(SAY_BLASTMASTER_0,m_creature);
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
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[4], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[5], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[6], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[8], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[9], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                break;
            case 2:
                if (GameObject* pGo = m_creature->SummonGameObject(183410, -533.140,-105.322,-156.016, 0, 0, 0, 0, 0, 1000))
                {
                    GoSummonList.push_back(pGo->GetGUID());
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1); //We can't use it!
                }
                Summon(3);
                break;
            case 3:
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[3], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                DoScriptText(SAY_BLASTMASTER_19,m_creature);
                break;
            case 4:
                if (GameObject* pGo = m_creature->SummonGameObject(183410, -542.199,-96.854,-155.790, 0, 0, 0, 0, 0, 1000))
                {
                    GoSummonList.push_back(pGo->GetGUID());
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                }
                break;
            case 5:
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[1], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                DoScriptText(SAY_BLASTMASTER_15,m_creature);
                break;
            case 6:
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[10], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[11], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[12], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[13], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                m_creature->SummonCreature(NPC_CAVERNDEEP_AMBUSHER, SpawnPosition[14], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
                break;
            case 7:
                if (GameObject* pGo = m_creature->SummonGameObject(183410, -507.820,-103.333,-151.353, 0, 0, 0, 0, 0, 1000))
                {
                    GoSummonList.push_back(pGo->GetGUID());
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1); //We can't use it!
                    Summon(6);
                }
                break;
            case 8:
                if (GameObject* pGo = m_creature->SummonGameObject(183410, -511.829,-86.249,-151.431, 0, 0, 0, 0, 0, 1000))
                {
                    GoSummonList.push_back(pGo->GetGUID());
                    pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1); //We can't use it!
                }
                break;
            case 9:
                if (Creature* pGrubbis = m_creature->SummonCreature(NPC_GRUBBIS, SpawnPosition[15], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000))
                    DoScriptText(SAY_GRUBBIS,pGrubbis);
                m_creature->SummonCreature(NPC_CHOMPER, SpawnPosition[16], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1800000);
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
                        DoScriptText(SAY_BLASTMASTER_1,m_creature);
                        NextStep(1500,true);
                        break;
                    case 2:
                        SetEscortPaused(false);
                        NextStep(0,false,0);
                        break;
                    case 3:
                        DoScriptText(SAY_BLASTMASTER_2,m_creature);
                        SetEscortPaused(false);
                        NextStep(0,false,0);
                        break;
                    case 4:
                        DoScriptText(SAY_BLASTMASTER_3,m_creature);
                        NextStep(3000,true);
                        break;
                    case 5:
                        DoScriptText(SAY_BLASTMASTER_4,m_creature);
                        NextStep(3000,true);
                        break;
                    case 6:
                        SetInFace(true);
                        DoScriptText(SAY_BLASTMASTER_5,m_creature);
                        Summon(1);
                        if (pInstance)
                            if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_RIGHT)))
                                pInstance->HandleGameObject(NULL,true,pGo);
                        NextStep(3000,true);
                        break;
                    case 7:
                        DoScriptText(SAY_BLASTMASTER_6,m_creature);
                        SetEscortPaused(false);
                        NextStep(0,false,0);
                        break;
                    case 8:
                        m_creature->HandleEmoteCommand(EMOTE_STATE_WORK);
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
                        DoScriptText(SAY_BLASTMASTER_17,m_creature);
                        NextStep(5000,true);
                        break;
                    case 12:
                        DoScriptText(SAY_BLASTMASTER_18,m_creature);
                        NextStep(5000,true);
                        break;
                    case 13:
                        DoScriptText(SAY_BLASTMASTER_20,m_creature);
                        CaveDestruction(true);
                        NextStep(8000,true);
                        break;
                    case 14:
                        DoScriptText(SAY_BLASTMASTER_21,m_creature);
                        NextStep(8500,true);
                        break;
                    case 15:
                        DoScriptText(SAY_BLASTMASTER_22,m_creature);
                        NextStep(2000,true);
                        break;
                    case 16:
                        DoScriptText(SAY_BLASTMASTER_23,m_creature);
                        SetInFace(false);
                        if (pInstance)
                            if (GameObject* pGo = GameObject::GetGameObject((*m_creature),pInstance->GetData64(DATA_GO_CAVE_IN_LEFT)))
                                pInstance->HandleGameObject(NULL,true,pGo);
                        NextStep(2000,true);
                        break;
                    case 17:
                        SetEscortPaused(false);
                        DoScriptText(SAY_BLASTMASTER_24,m_creature);
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
                        DoScriptText(SAY_BLASTMASTER_25,m_creature);
                        NextStep(0,false);
                        break;
                    case 20:
                        DoScriptText(SAY_BLASTMASTER_27,m_creature);
                        NextStep(2000,true);
                        break;
                    case 21:
                        Summon(9);
                        NextStep(0,false);
                        break;
                    case 22:
                        CaveDestruction(false);
                        DoScriptText(SAY_BLASTMASTER_20,m_creature);
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

CreatureAI* GetAI_npc_blastmaster_emi_shortfuse(Creature* pCreature)
{
    return new npc_blastmaster_emi_shortfuseAI(pCreature);
}

bool GossipHello_npc_blastmaster_emi_shortfuse(Player* pPlayer, Creature* pCreature)
{
    ScriptedInstance* pInstance = pCreature->GetInstanceData();

    if (pInstance && pInstance->GetData(TYPE_EVENT) == NOT_STARTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXT_EMI, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_blastmaster_emi_shortfuse(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        if (npc_escortAI* pEscortAI = CAST_AI(npc_blastmaster_emi_shortfuseAI, pCreature->AI()))
            pEscortAI->Start(true, false,pPlayer->GetGUID());

        pCreature->setFaction(pPlayer->getFaction());
        pCreature->AI()->SetData(1,0);

        pPlayer->CLOSE_GOSSIP_MENU();
    }
    return true;
}

struct boss_grubbisAI : public ScriptedAI
{
    boss_grubbisAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        SetDataSummoner();
    }

    void SetDataSummoner()
    {
        if (!m_creature->isSummon())
            return;

        if (Unit* pSummon = CAST_SUM(m_creature)->GetSummoner())
            CAST_CRE(pSummon)->AI()->SetData(2,1);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (!m_creature->isSummon())
            return;

        if (Unit* pSummon = CAST_SUM(m_creature)->GetSummoner())
            CAST_CRE(pSummon)->AI()->SetData(2,2);
    }
};

CreatureAI* GetAI_boss_grubbis(Creature* pCreature)
{
    return new boss_grubbisAI(pCreature);
}

void AddSC_gnomeregan()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_blastmaster_emi_shortfuse";
    newscript->pGossipHello =  &GossipHello_npc_blastmaster_emi_shortfuse;
    newscript->pGossipSelect = &GossipSelect_npc_blastmaster_emi_shortfuse;
    newscript->GetAI = &GetAI_npc_blastmaster_emi_shortfuse;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_grubbis";
    newscript->GetAI = &GetAI_boss_grubbis;
    newscript->RegisterSelf();
}
