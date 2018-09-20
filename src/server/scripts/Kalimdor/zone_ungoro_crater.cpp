/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
SDName: Ungoro Crater
SD%Complete: 100
SDComment: Support for Quest: 4245, 4491
SDCategory: Ungoro Crater
EndScriptData */

/* ContentData
npc_a-me
npc_ringo
EndContentData */

#include "ScriptMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "SpellInfo.h"

enum AmeData
{
    SAY_READY               = 0,
    SAY_AGGRO1              = 1,
    SAY_SEARCH              = 2,
    SAY_AGGRO2              = 3,
    SAY_AGGRO3              = 4,
    SAY_FINISH              = 5,

    SPELL_DEMORALIZINGSHOUT = 13730,

    QUEST_CHASING_AME       = 4245,
    ENTRY_TARLORD           = 6519,
    ENTRY_TARLORD1          = 6519,
    ENTRY_STOMPER           = 6513,
};

class npc_ame : public CreatureScript
{
public:
    npc_ame() : CreatureScript("npc_ame") { }

    struct npc_ameAI : public EscortAI
    {
        npc_ameAI(Creature* creature) : EscortAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DemoralizingShoutTimer = 5000;
        }

        uint32 DemoralizingShoutTimer;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            if (Player* player = GetPlayerForEscort())
            {
                switch (waypointId)
                {
                    case 19:
                        me->SummonCreature(ENTRY_STOMPER, -6391.69f, -1730.49f, -272.83f, 4.96f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_AGGRO1, player);
                        break;
                    case 28:
                        Talk(SAY_SEARCH, player);
                        break;
                    case 38:
                        me->SummonCreature(ENTRY_TARLORD, -6370.75f, -1382.84f, -270.51f, 6.06f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_AGGRO2, player);
                        break;
                    case 49:
                        me->SummonCreature(ENTRY_TARLORD1, -6324.44f, -1181.05f, -270.17f, 4.34f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                        Talk(SAY_AGGRO3, player);
                        break;
                    case 55:
                        Talk(SAY_FINISH, player);
                        player->GroupEventHappens(QUEST_CHASING_AME, me);
                        break;
                }
            }
        }

        void Reset() override
        {
            Initialize();
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Player* player = GetPlayerForEscort())
                player->FailQuest(QUEST_CHASING_AME);
        }

        void UpdateAI(uint32 diff) override
        {
            EscortAI::UpdateAI(diff);
            if (!UpdateVictim())
                return;

            if (DemoralizingShoutTimer <= diff)
            {
                DoCastVictim(SPELL_DEMORALIZINGSHOUT);
                DemoralizingShoutTimer = 70000;
            } else DemoralizingShoutTimer -= diff;
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_CHASING_AME)
            {
                Start(false, false, player->GetGUID());
                Talk(SAY_READY, player);
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                // Change faction so mobs attack
                me->SetFaction(FACTION_ESCORTEE_N_NEUTRAL_PASSIVE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ameAI(creature);
    }
};

/*####
# npc_ringo
####*/

enum Ringo
{
    SAY_RIN_START               = 0,

    SAY_FAINT                   = 1,

    SAY_WAKE                    = 2,

    SAY_RIN_END_1               = 3,
    SAY_SPR_END_2               = 0,
    SAY_RIN_END_3               = 4,
    EMOTE_RIN_END_4             = 5,
    EMOTE_RIN_END_5             = 6,
    SAY_RIN_END_6               = 7,
    SAY_SPR_END_7               = 1,
    EMOTE_RIN_END_8             = 8,

    SPELL_REVIVE_RINGO          = 15591,
    QUEST_A_LITTLE_HELP         = 4491,
    NPC_SPRAGGLE                = 9997,
    FACTION_ESCORTEE            = 113
};

class npc_ringo : public CreatureScript
{
public:
    npc_ringo() : CreatureScript("npc_ringo") { }

    struct npc_ringoAI : public FollowerAI
    {
        npc_ringoAI(Creature* creature) : FollowerAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            FaintTimer = urand(30000, 60000);
            EndEventProgress = 0;
            EndEventTimer = 1000;
            SpraggleGUID.Clear();
        }

        uint32 FaintTimer;
        uint32 EndEventProgress;
        uint32 EndEventTimer;

        ObjectGuid SpraggleGUID;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override

        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_SPRAGGLE)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
                {
                    if (Player* player = GetLeaderForFollower())
                    {
                        if (player->GetQuestStatus(QUEST_A_LITTLE_HELP) == QUEST_STATUS_INCOMPLETE)
                            player->GroupEventHappens(QUEST_A_LITTLE_HELP, me);
                    }

                    SpraggleGUID = who->GetGUID();
                    SetFollowComplete(true);
                }
            }
        }

        void SpellHit(Unit* /*pCaster*/, SpellInfo const* pSpell) override
        {
            if (HasFollowState(STATE_FOLLOW_INPROGRESS | STATE_FOLLOW_PAUSED) && pSpell->Id == SPELL_REVIVE_RINGO)
                ClearFaint();
        }

        void SetFaint()
        {
            if (!HasFollowState(STATE_FOLLOW_POSTEVENT))
            {
                SetFollowPaused(true);

                Talk(SAY_FAINT);
            }

            //what does actually happen here? Emote? Aura?
            me->SetStandState(UNIT_STAND_STATE_SLEEP);
        }

        void ClearFaint()
        {
            me->SetStandState(UNIT_STAND_STATE_STAND);

            if (HasFollowState(STATE_FOLLOW_POSTEVENT))
                return;

            Talk(SAY_WAKE);

            SetFollowPaused(false);
        }

        void UpdateFollowerAI(uint32 Diff) override
        {
            if (!UpdateVictim())
            {
                if (HasFollowState(STATE_FOLLOW_POSTEVENT))
                {
                    if (EndEventTimer <= Diff)
                    {
                        Creature* spraggle = ObjectAccessor::GetCreature(*me, SpraggleGUID);
                        if (!spraggle || !spraggle->IsAlive())
                        {
                            SetFollowComplete();
                            return;
                        }

                        switch (EndEventProgress)
                        {
                            case 1:
                                Talk(SAY_RIN_END_1);
                                EndEventTimer = 3000;
                                break;
                            case 2:
                                spraggle->AI()->Talk(SAY_SPR_END_2);
                                EndEventTimer = 5000;
                                break;
                            case 3:
                                Talk(SAY_RIN_END_3);
                                EndEventTimer = 1000;
                                break;
                            case 4:
                                Talk(EMOTE_RIN_END_4);
                                SetFaint();
                                EndEventTimer = 9000;
                                break;
                            case 5:
                                Talk(EMOTE_RIN_END_5);
                                ClearFaint();
                                EndEventTimer = 1000;
                                break;
                            case 6:
                                Talk(SAY_RIN_END_6);
                                EndEventTimer = 3000;
                                break;
                            case 7:
                                spraggle->AI()->Talk(SAY_SPR_END_7);
                                EndEventTimer = 10000;
                                break;
                            case 8:
                                Talk(EMOTE_RIN_END_8);
                                EndEventTimer = 5000;
                                break;
                            case 9:
                                SetFollowComplete();
                                break;
                        }

                        ++EndEventProgress;
                    }
                    else
                        EndEventTimer -= Diff;
                }
                else if (HasFollowState(STATE_FOLLOW_INPROGRESS) && !HasFollowState(STATE_FOLLOW_PAUSED))
                {
                    if (FaintTimer <= Diff)
                    {
                        SetFaint();
                        FaintTimer = urand(60000, 120000);
                    }
                    else
                        FaintTimer -= Diff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_A_LITTLE_HELP)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                StartFollow(player, FACTION_ESCORTEE, quest);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ringoAI(creature);
    }
};

void AddSC_ungoro_crater()
{
    new npc_ame();
    new npc_ringo();
}
