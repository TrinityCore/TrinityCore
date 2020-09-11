/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDComment: Quest support: 731, 5321
SDCategory: Darkshore
EndScriptData */

/* ContentData
npc_kerlonian
npc_prospector_remtravel
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
    NPC_LILADRIS                = 11219                    //attackers entries unknown
};

/// @todo make concept similar as "ringo" -escort. Find a way to run the scripted attacks, _if_ player are choosing road.
class npc_kerlonian : public CreatureScript
{
public:
    npc_kerlonian() : CreatureScript("npc_kerlonian") { }

    struct npc_kerlonianAI : public FollowerAI
    {
        npc_kerlonianAI(Creature* creature) : FollowerAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            FallAsleepTimer = urand(10000, 45000);
        }

        uint32 FallAsleepTimer;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override

        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_LILADRIS)
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

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (HasFollowState(STATE_FOLLOW_INPROGRESS | STATE_FOLLOW_PAUSED) && spellInfo->Id == SPELL_AWAKEN)
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

        void UpdateFollowerAI(uint32 diff) override
        {
            if (!UpdateVictim())
            {
                if (!HasFollowState(STATE_FOLLOW_INPROGRESS))
                    return;

                if (!HasFollowState(STATE_FOLLOW_PAUSED))
                {
                    if (FallAsleepTimer <= diff)
                    {
                        SetSleeping();
                        FallAsleepTimer = urand(25000, 90000);
                    }
                    else
                        FallAsleepTimer -= diff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_SLEEPER_AWAKENED)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                Talk(SAY_KER_START, player);
                StartFollow(player, FACTION_ESCORTEE_N_NEUTRAL_PASSIVE, QUEST_SLEEPER_AWAKENED);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_kerlonianAI(creature);
    }
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

    QUEST_ABSENT_MINDED_PT2     = 731,
    NPC_GRAVEL_SCOUT            = 2158,
    NPC_GRAVEL_BONE             = 2159,
    NPC_GRAVEL_GEO              = 2160
};

class npc_prospector_remtravel : public CreatureScript
{
public:
    npc_prospector_remtravel() : CreatureScript("npc_prospector_remtravel") { }

    struct npc_prospector_remtravelAI : public EscortAI
    {
        npc_prospector_remtravelAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override { }

        void JustEngagedWith(Unit* who) override
        {
            if (urand(0, 1))
                Talk(SAY_REM_AGGRO, who);
        }

        void JustSummoned(Creature* /*pSummoned*/) override
        {
            //unsure if it should be any
            //pSummoned->AI()->AttackStart(me);
        }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 0:
                        Talk(SAY_REM_START, player);
                        break;
                    case 5:
                        Talk(SAY_REM_RAMP1_1, player);
                        break;
                    case 6:
                        DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        break;
                    case 9:
                        Talk(SAY_REM_RAMP1_2, player);
                        break;
                    case 14:
                        //depend quest rewarded?
                        Talk(SAY_REM_BOOK, player);
                        break;
                    case 15:
                        Talk(SAY_REM_TENT1_1, player);
                        break;
                    case 16:
                        DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        break;
                    case 17:
                        Talk(SAY_REM_TENT1_2, player);
                        break;
                    case 26:
                        Talk(SAY_REM_MOSS, player);
                        break;
                    case 27:
                        Talk(EMOTE_REM_MOSS, player);
                        break;
                    case 28:
                        Talk(SAY_REM_MOSS_PROGRESS, player);
                        break;
                    case 29:
                        DoSpawnCreature(NPC_GRAVEL_SCOUT, -15.0f, 3.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        DoSpawnCreature(NPC_GRAVEL_BONE, -15.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        DoSpawnCreature(NPC_GRAVEL_GEO, -15.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30s);
                        break;
                    case 31:
                        Talk(SAY_REM_PROGRESS, player);
                        break;
                    case 41:
                        Talk(SAY_REM_REMEMBER, player);
                        break;
                    case 42:
                        Talk(EMOTE_REM_END, player);
                        player->GroupEventHappens(QUEST_ABSENT_MINDED_PT2, me);
                        break;
                }
            }
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ABSENT_MINDED_PT2)
            {
                Start(false, false, player->GetGUID());
                me->SetFaction(FACTION_ESCORTEE_A_NEUTRAL_PASSIVE);
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_ABSENT_MINDED_PT2);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prospector_remtravelAI(creature);
    }
};

void AddSC_darkshore()
{
    new npc_kerlonian();
    new npc_prospector_remtravel();
}
