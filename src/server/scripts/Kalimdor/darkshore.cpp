/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Darkshore
SD%Complete: 100
SDComment: Quest support: 731, 2078, 5321
SDCategory: Darkshore
EndScriptData */

/* ContentData
npc_kerlonian
npc_prospector_remtravel
npc_threshwackonator
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"

/*####
# npc_kerlonian
####*/

enum eKerlonian
{
    SAY_KER_START               = -1000434,

    EMOTE_KER_SLEEP_1           = -1000435,
    EMOTE_KER_SLEEP_2           = -1000436,
    EMOTE_KER_SLEEP_3           = -1000437,

    SAY_KER_SLEEP_1             = -1000438,
    SAY_KER_SLEEP_2             = -1000439,
    SAY_KER_SLEEP_3             = -1000440,
    SAY_KER_SLEEP_4             = -1000441,

    EMOTE_KER_AWAKEN            = -1000445,

    SAY_KER_ALERT_1             = -1000442,
    SAY_KER_ALERT_2             = -1000443,

    SAY_KER_END                 = -1000444,

    SPELL_SLEEP_VISUAL          = 25148,
    SPELL_AWAKEN                = 17536,
    QUEST_SLEEPER_AWAKENED      = 5321,
    NPC_LILADRIS                = 11219,                    //attackers entries unknown
    FACTION_KER_ESCORTEE        = 113
};

//TODO: make concept similar as "ringo" -escort. Find a way to run the scripted attacks, _if_ player are choosing road.
class npc_kerlonian : public CreatureScript
{
public:
    npc_kerlonian() : CreatureScript("npc_kerlonian") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_SLEEPER_AWAKENED)
        {
            if (npc_kerlonianAI* pKerlonianAI = CAST_AI(npc_kerlonian::npc_kerlonianAI, pCreature->AI()))
            {
                pCreature->SetStandState(UNIT_STAND_STATE_STAND);
                DoScriptText(SAY_KER_START, pCreature, pPlayer);
                pKerlonianAI->StartFollow(pPlayer, FACTION_KER_ESCORTEE, pQuest);
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_kerlonianAI(pCreature);
    }

    struct npc_kerlonianAI : public FollowerAI
    {
        npc_kerlonianAI(Creature* pCreature) : FollowerAI(pCreature) { }

        uint32 m_uiFallAsleepTimer;

        void Reset()
        {
            m_uiFallAsleepTimer = urand(10000, 45000);
        }

        void MoveInLineOfSight(Unit *pWho)
        {
            FollowerAI::MoveInLineOfSight(pWho);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && pWho->GetEntry() == NPC_LILADRIS)
            {
                if (me->IsWithinDistInMap(pWho, INTERACTION_DISTANCE*5))
                {
                    if (Player* pPlayer = GetLeaderForFollower())
                    {
                        if (pPlayer->GetQuestStatus(QUEST_SLEEPER_AWAKENED) == QUEST_STATUS_INCOMPLETE)
                            pPlayer->GroupEventHappens(QUEST_SLEEPER_AWAKENED, me);

                        DoScriptText(SAY_KER_END, me);
                    }

                    SetFollowComplete();
                }
            }
        }

        void SpellHit(Unit* /*pCaster*/, const SpellEntry* pSpell)
        {
            if (HasFollowState(STATE_FOLLOW_INPROGRESS | STATE_FOLLOW_PAUSED) && pSpell->Id == SPELL_AWAKEN)
                ClearSleeping();
        }

        void SetSleeping()
        {
            SetFollowPaused(true);

            DoScriptText(RAND(EMOTE_KER_SLEEP_1,EMOTE_KER_SLEEP_2,EMOTE_KER_SLEEP_3), me);

            DoScriptText(RAND(SAY_KER_SLEEP_1,SAY_KER_SLEEP_2,SAY_KER_SLEEP_3,SAY_KER_SLEEP_4), me);

            me->SetStandState(UNIT_STAND_STATE_SLEEP);
            DoCast(me, SPELL_SLEEP_VISUAL, false);
        }

        void ClearSleeping()
        {
            me->RemoveAurasDueToSpell(SPELL_SLEEP_VISUAL);
            me->SetStandState(UNIT_STAND_STATE_STAND);

            DoScriptText(EMOTE_KER_AWAKEN, me);

            SetFollowPaused(false);
        }

        void UpdateFollowerAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            {
                if (!HasFollowState(STATE_FOLLOW_INPROGRESS))
                    return;

                if (!HasFollowState(STATE_FOLLOW_PAUSED))
                {
                    if (m_uiFallAsleepTimer <= uiDiff)
                    {
                        SetSleeping();
                        m_uiFallAsleepTimer = urand(25000, 90000);
                    }
                    else
                        m_uiFallAsleepTimer -= uiDiff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }
    };

};



/*####
# npc_prospector_remtravel
####*/

enum eRemtravel
{
    SAY_REM_START               = -1000327,
    SAY_REM_AGGRO               = -1000328,
    SAY_REM_RAMP1_1             = -1000329,
    SAY_REM_RAMP1_2             = -1000330,
    SAY_REM_BOOK                = -1000331,
    SAY_REM_TENT1_1             = -1000332,
    SAY_REM_TENT1_2             = -1000333,
    SAY_REM_MOSS                = -1000334,
    EMOTE_REM_MOSS              = -1000335,
    SAY_REM_MOSS_PROGRESS       = -1000336,
    SAY_REM_PROGRESS            = -1000337,
    SAY_REM_REMEMBER            = -1000338,
    EMOTE_REM_END               = -1000339,

    FACTION_ESCORTEE            = 10,
    QUEST_ABSENT_MINDED_PT2     = 731,
    NPC_GRAVEL_SCOUT            = 2158,
    NPC_GRAVEL_BONE             = 2159,
    NPC_GRAVEL_GEO              = 2160
};

class npc_prospector_remtravel : public CreatureScript
{
public:
    npc_prospector_remtravel() : CreatureScript("npc_prospector_remtravel") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_ABSENT_MINDED_PT2)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_prospector_remtravel::npc_prospector_remtravelAI, pCreature->AI()))
                pEscortAI->Start(false, false, pPlayer->GetGUID());

            pCreature->setFaction(FACTION_ESCORTEE);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_prospector_remtravelAI(pCreature);
    }

    struct npc_prospector_remtravelAI : public npc_escortAI
    {
        npc_prospector_remtravelAI(Creature* pCreature) : npc_escortAI(pCreature) {}

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch(i)
            {
                case 0:
                    DoScriptText(SAY_REM_START, me, pPlayer);
                    break;
                case 5:
                    DoScriptText(SAY_REM_RAMP1_1, me, pPlayer);
                    break;
                case 6:
                    DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 9:
                    DoScriptText(SAY_REM_RAMP1_2, me, pPlayer);
                    break;
                case 14:
                    //depend quest rewarded?
                    DoScriptText(SAY_REM_BOOK, me, pPlayer);
                    break;
                case 15:
                    DoScriptText(SAY_REM_TENT1_1, me, pPlayer);
                    break;
                case 16:
                    DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 17:
                    DoScriptText(SAY_REM_TENT1_2, me, pPlayer);
                    break;
                case 26:
                    DoScriptText(SAY_REM_MOSS, me, pPlayer);
                    break;
                case 27:
                    DoScriptText(EMOTE_REM_MOSS, me, pPlayer);
                    break;
                case 28:
                    DoScriptText(SAY_REM_MOSS_PROGRESS, me, pPlayer);
                    break;
                case 29:
                    DoSpawnCreature(NPC_GRAVEL_SCOUT, -15.0f, 3.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    DoSpawnCreature(NPC_GRAVEL_BONE, -15.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    DoSpawnCreature(NPC_GRAVEL_GEO, -15.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 31:
                    DoScriptText(SAY_REM_PROGRESS, me, pPlayer);
                    break;
                case 41:
                    DoScriptText(SAY_REM_REMEMBER, me, pPlayer);
                    break;
                case 42:
                    DoScriptText(EMOTE_REM_END, me, pPlayer);
                    pPlayer->GroupEventHappens(QUEST_ABSENT_MINDED_PT2, me);
                    break;
            }
        }

        void Reset() {}

        void EnterCombat(Unit* who)
        {
            if (rand()%2)
                DoScriptText(SAY_REM_AGGRO, me, who);
        }

        void JustSummoned(Creature* /*pSummoned*/)
        {
            //unsure if it should be any
            //pSummoned->AI()->AttackStart(me);
        }
    };

};



/*####
# npc_threshwackonator
####*/

enum eThreshwackonator
{
    EMOTE_START             = -1000413, //signed for 4966
    SAY_AT_CLOSE            = -1000414, //signed for 4966
    QUEST_GYROMAST_REV      = 2078,
    NPC_GELKAK              = 6667,
    FACTION_HOSTILE         = 14
};

#define GOSSIP_ITEM_INSERT_KEY  "[PH] Insert key"

class npc_threshwackonator : public CreatureScript
{
public:
    npc_threshwackonator() : CreatureScript("npc_threshwackonator") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();

            if (npc_threshwackonatorAI* pThreshAI = CAST_AI(npc_threshwackonator::npc_threshwackonatorAI, pCreature->AI()))
            {
                DoScriptText(EMOTE_START, pCreature);
                pThreshAI->StartFollow(pPlayer);
            }
        }

        return true;
    }


    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_GYROMAST_REV) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_INSERT_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_threshwackonatorAI(pCreature);
    }

    struct npc_threshwackonatorAI : public FollowerAI
    {
        npc_threshwackonatorAI(Creature* pCreature) : FollowerAI(pCreature) { }

        void Reset() { }

        void MoveInLineOfSight(Unit* pWho)
        {
            FollowerAI::MoveInLineOfSight(pWho);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && pWho->GetEntry() == NPC_GELKAK)
            {
                if (me->IsWithinDistInMap(pWho, 10.0f))
                {
                    DoScriptText(SAY_AT_CLOSE, pWho);
                    DoAtEnd();
                }
            }
        }

        void DoAtEnd()
        {
            me->setFaction(FACTION_HOSTILE);

            if (Player* pHolder = GetLeaderForFollower())
                me->AI()->AttackStart(pHolder);

            SetFollowComplete();
        }
    };

};




void AddSC_darkshore()
{
    new npc_kerlonian();
    new npc_prospector_remtravel();
    new npc_threshwackonator();
}
