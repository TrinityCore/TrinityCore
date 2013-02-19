/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "Player.h"
#include "SpellInfo.h"

/*####
# npc_kerlonian
####*/

enum Kerlonian
{
    SAY_KER_START               = 0,
    EMOTE_KER_SLEEP             = 1,
    SAY_KER_SLEEP               = 2,
    SAY_KER_ALERT_1             = 3,
    SAY_KER_END                 = 4,
    EMOTE_KER_AWAKEN            = 5,

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

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest)
    {
        if (quest->GetQuestId() == QUEST_SLEEPER_AWAKENED)
        {
            if (npc_kerlonianAI* pKerlonianAI = CAST_AI(npc_kerlonian::npc_kerlonianAI, creature->AI()))
            {
                creature->SetStandState(UNIT_STAND_STATE_STAND);
                creature->AI()->Talk(SAY_KER_START, player->GetGUID());
                pKerlonianAI->StartFollow(player, FACTION_KER_ESCORTEE, quest);
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_kerlonianAI(creature);
    }

    struct npc_kerlonianAI : public FollowerAI
    {
        npc_kerlonianAI(Creature* creature) : FollowerAI(creature) { }

        uint32 FallAsleepTimer;

        void Reset()
        {
            FallAsleepTimer = urand(10000, 45000);
        }

        void MoveInLineOfSight(Unit* who)
        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_LILADRIS)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE*5))
                {
                    if (Player* player = GetLeaderForFollower())
                    {
                        if (player->GetQuestStatus(QUEST_SLEEPER_AWAKENED) == QUEST_STATUS_INCOMPLETE)
                            player->GroupEventHappens(QUEST_SLEEPER_AWAKENED, me);

                        Talk(SAY_KER_END);
                    }

                    SetFollowComplete();
                }
            }
        }

        void SpellHit(Unit* /*pCaster*/, const SpellInfo* pSpell)
        {
            if (HasFollowState(STATE_FOLLOW_INPROGRESS | STATE_FOLLOW_PAUSED) && pSpell->Id == SPELL_AWAKEN)
                ClearSleeping();
        }

        void SetSleeping()
        {
            SetFollowPaused(true);

            Talk(EMOTE_KER_SLEEP);

            Talk(SAY_KER_SLEEP);

            me->SetStandState(UNIT_STAND_STATE_SLEEP);
            DoCast(me, SPELL_SLEEP_VISUAL, false);
        }

        void ClearSleeping()
        {
            me->RemoveAurasDueToSpell(SPELL_SLEEP_VISUAL);
            me->SetStandState(UNIT_STAND_STATE_STAND);

            Talk(EMOTE_KER_AWAKEN);

            SetFollowPaused(false);
        }

        void UpdateFollowerAI(const uint32 Diff)
        {
            if (!UpdateVictim())
            {
                if (!HasFollowState(STATE_FOLLOW_INPROGRESS))
                    return;

                if (!HasFollowState(STATE_FOLLOW_PAUSED))
                {
                    if (FallAsleepTimer <= Diff)
                    {
                        SetSleeping();
                        FallAsleepTimer = urand(25000, 90000);
                    }
                    else
                        FallAsleepTimer -= Diff;
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

enum Remtravel
{
    SAY_REM_START               = 0,
    SAY_REM_AGGRO               = 1,
    SAY_REM_RAMP1_1             = 2,
    SAY_REM_RAMP1_2             = 3,
    SAY_REM_BOOK                = 4,
    SAY_REM_TENT1_1             = 5,
    SAY_REM_TENT1_2             = 6,
    SAY_REM_MOSS                = 7,
    EMOTE_REM_MOSS              = 8,
    SAY_REM_MOSS_PROGRESS       = 9,
    SAY_REM_PROGRESS            = 10,
    SAY_REM_REMEMBER            = 11,
    EMOTE_REM_END               = 12,

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

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest)
    {
        if (quest->GetQuestId() == QUEST_ABSENT_MINDED_PT2)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_prospector_remtravel::npc_prospector_remtravelAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID());

            creature->setFaction(FACTION_ESCORTEE);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_prospector_remtravelAI(creature);
    }

    struct npc_prospector_remtravelAI : public npc_escortAI
    {
        npc_prospector_remtravelAI(Creature* creature) : npc_escortAI(creature) {}

        void WaypointReached(uint32 waypointId)
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 0:
                        Talk(SAY_REM_START, player->GetGUID());
                        break;
                    case 5:
                        Talk(SAY_REM_RAMP1_1, player->GetGUID());
                        break;
                    case 6:
                        DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        break;
                    case 9:
                        Talk(SAY_REM_RAMP1_2, player->GetGUID());
                        break;
                    case 14:
                        //depend quest rewarded?
                        Talk(SAY_REM_BOOK, player->GetGUID());
                        break;
                    case 15:
                        Talk(SAY_REM_TENT1_1, player->GetGUID());
                        break;
                    case 16:
                        DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        break;
                    case 17:
                        Talk(SAY_REM_TENT1_2, player->GetGUID());
                        break;
                    case 26:
                        Talk(SAY_REM_MOSS, player->GetGUID());
                        break;
                    case 27:
                        Talk(EMOTE_REM_MOSS, player->GetGUID());
                        break;
                    case 28:
                        Talk(SAY_REM_MOSS_PROGRESS, player->GetGUID());
                        break;
                    case 29:
                        DoSpawnCreature(NPC_GRAVEL_SCOUT, -15.0f, 3.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        DoSpawnCreature(NPC_GRAVEL_BONE, -15.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        DoSpawnCreature(NPC_GRAVEL_GEO, -15.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                        break;
                    case 31:
                        Talk(SAY_REM_PROGRESS, player->GetGUID());
                        break;
                    case 41:
                        Talk(SAY_REM_REMEMBER, player->GetGUID());
                        break;
                    case 42:
                        Talk(EMOTE_REM_END, player->GetGUID());
                        player->GroupEventHappens(QUEST_ABSENT_MINDED_PT2, me);
                        break;
                }
            }
        }

        void Reset() {}

        void EnterCombat(Unit* who)
        {
            if (urand(0, 1))
                Talk(SAY_REM_AGGRO, who->GetGUID());
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

enum Threshwackonator
{
    EMOTE_START             = 0,
    SAY_AT_CLOSE            = 1,
    QUEST_GYROMAST_REV      = 2078,
    NPC_GELKAK              = 6667,
    FACTION_HOSTILE         = 14
};

#define GOSSIP_ITEM_INSERT_KEY  "[PH] Insert key"

class npc_threshwackonator : public CreatureScript
{
public:
    npc_threshwackonator() : CreatureScript("npc_threshwackonator") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();

            if (npc_threshwackonatorAI* pThreshAI = CAST_AI(npc_threshwackonator::npc_threshwackonatorAI, creature->AI()))
            {
                creature->AI()->Talk(EMOTE_START);
                pThreshAI->StartFollow(player);
            }
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_GYROMAST_REV) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_INSERT_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_threshwackonatorAI(creature);
    }

    struct npc_threshwackonatorAI : public FollowerAI
    {
        npc_threshwackonatorAI(Creature* creature) : FollowerAI(creature) { }

        void Reset() { }

        void MoveInLineOfSight(Unit* who)
        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_GELKAK)
            {
                if (me->IsWithinDistInMap(who, 10.0f))
                {
                    Talk(SAY_AT_CLOSE, who->GetGUID());
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
