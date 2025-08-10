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
SDName: The_Barrens
SD%Complete: 90
SDComment: Quest support: 863
SDCategory: Barrens
EndScriptData */

/* ContentData
npc_wizzlecrank_shredder
EndContentData */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

/*######
## npc_taskmaster_fizzule
######*/

enum TaskmasterFizzule
{
    SPELL_FLARE         = 10113,
    SPELL_FOLLY         = 10137,
};

class npc_taskmaster_fizzule : public CreatureScript
{
public:
    npc_taskmaster_fizzule() : CreatureScript("npc_taskmaster_fizzule") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_taskmaster_fizzuleAI(creature);
    }

    struct npc_taskmaster_fizzuleAI : public ScriptedAI
    {
        npc_taskmaster_fizzuleAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            factionNorm = creature->GetFaction();
        }

        void Initialize()
        {
            IsFriend = false;
            ResetTimer = 120000;
            FlareCount = 0;
        }

        uint32 factionNorm;
        bool IsFriend;
        uint32 ResetTimer;
        uint8 FlareCount;

        void Reset() override
        {
            Initialize();
            me->SetFaction(factionNorm);
        }

        void DoFriend()
        {
            me->RemoveAllAuras();
            me->CombatStop(true);
            me->StopMoving();

            EngagementOver();

            me->GetMotionMaster()->MoveIdle();
            me->SetFaction(FACTION_FRIENDLY);
            me->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_FLARE || spellInfo->Id == SPELL_FOLLY)
            {
                ++FlareCount;

                if (FlareCount >= 2)
                    IsFriend = true;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (IsFriend)
            {
                if (ResetTimer <= diff)
                {
                    EnterEvadeMode();
                    return;
                } else ResetTimer -= diff;
            }

            if (!UpdateVictim())
                return;
        }

        void ReceiveEmote(Player* /*player*/, uint32 emote) override
        {
            if (emote == TEXT_EMOTE_SALUTE)
            {
                if (FlareCount >= 2)
                {
                    if (me->GetFaction() == FACTION_FRIENDLY)
                        return;

                    DoFriend();
                }
            }
        }
    };

};

/*#####
## npc_twiggy_flathead
#####*/

enum TwiggyFlathead
{
    NPC_BIG_WILL                = 6238,
    NPC_AFFRAY_CHALLENGER       = 6240,

    SAY_BIG_WILL_READY          = 0,
    SAY_TWIGGY_FLATHEAD_BEGIN   = 0,
    SAY_TWIGGY_FLATHEAD_FRAY    = 1,
    SAY_TWIGGY_FLATHEAD_DOWN    = 2,
    SAY_TWIGGY_FLATHEAD_OVER    = 3
};

Position const AffrayChallengerLoc[6] =
{
    {-1683.0f, -4326.0f, 2.79f, 0.0f},
    {-1682.0f, -4329.0f, 2.79f, 0.0f},
    {-1683.0f, -4330.0f, 2.79f, 0.0f},
    {-1680.0f, -4334.0f, 2.79f, 1.49f},
    {-1674.0f, -4326.0f, 2.79f, 3.49f},
    {-1677.0f, -4334.0f, 2.79f, 1.66f}
};

class npc_twiggy_flathead : public CreatureScript
{
public:
    npc_twiggy_flathead() : CreatureScript("npc_twiggy_flathead") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_twiggy_flatheadAI(creature);
    }

    struct npc_twiggy_flatheadAI : public ScriptedAI
    {
        npc_twiggy_flatheadAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            EventInProgress = false;
            EventGrate = false;
            EventBigWill = false;
            WaveTimer = 600000;
            ChallengerChecker = 0;
            Wave = 0;
            PlayerGUID.Clear();

            for (uint8 i = 0; i < 6; ++i)
            {
                AffrayChallenger[i].Clear();
                ChallengerDown[i] = false;
            }
            BigWill.Clear();
        }

        bool EventInProgress;
        bool EventGrate;
        bool EventBigWill;
        bool ChallengerDown[6];
        uint8 Wave;
        uint32 WaveTimer;
        uint32 ChallengerChecker;
        ObjectGuid PlayerGUID;
        ObjectGuid AffrayChallenger[6];
        ObjectGuid BigWill;

        void Reset() override
        {
            Initialize();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsAlive() || EventInProgress)
                return;

            if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f))
                if (Player* player = who->ToPlayer())
                    if (player->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE)
                    {
                        PlayerGUID = who->GetGUID();
                        EventInProgress = true;
                    }
        }

        void UpdateAI(uint32 diff) override
        {
            if (EventInProgress)
            {
                Player* warrior = nullptr;

                if (!PlayerGUID.IsEmpty())
                    warrior = ObjectAccessor::GetPlayer(*me, PlayerGUID);

                if (!warrior)
                    return;

                if (!warrior->IsAlive() && warrior->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE)
                {
                    Talk(SAY_TWIGGY_FLATHEAD_DOWN);
                    warrior->FailQuest(1719);

                    for (uint8 i = 0; i < 6; ++i) // unsummon challengers
                    {
                        if (!AffrayChallenger[i].IsEmpty())
                        {
                            Creature* creature = ObjectAccessor::GetCreature((*me), AffrayChallenger[i]);
                            if (creature && creature->IsAlive())
                                creature->DisappearAndDie();
                        }
                    }

                    if (!BigWill.IsEmpty()) // unsummon bigWill
                    {
                        Creature* creature = ObjectAccessor::GetCreature((*me), BigWill);
                        if (creature && creature->IsAlive())
                            creature->DisappearAndDie();
                    }
                    Reset();
                }

                if (!EventGrate && EventInProgress)
                {
                    float x, y, z;
                    warrior->GetPosition(x, y, z);

                    if (x >= -1684 && x <= -1674 && y >= -4334 && y <= -4324)
                    {
                        warrior->AreaExploredOrEventHappens(1719);
                        Talk(SAY_TWIGGY_FLATHEAD_BEGIN, warrior);

                        for (uint8 i = 0; i < 6; ++i)
                        {
                            Creature* creature = me->SummonCreature(NPC_AFFRAY_CHALLENGER, AffrayChallengerLoc[i], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10min);
                            if (!creature)
                                continue;
                            creature->SetFaction(35);
                            creature->SetUninteractible(true);
                            creature->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                            creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            AffrayChallenger[i] = creature->GetGUID();
                        }
                        WaveTimer = 5000;
                        ChallengerChecker = 1000;
                        EventGrate = true;
                    }
                }
                else if (EventInProgress)
                {
                    if (ChallengerChecker <= diff)
                    {
                        for (uint8 i = 0; i < 6; ++i)
                        {
                            if (!AffrayChallenger[i].IsEmpty())
                            {
                                Creature* creature = ObjectAccessor::GetCreature((*me), AffrayChallenger[i]);
                                if ((!creature || (!creature->IsAlive())) && !ChallengerDown[i])
                                {
                                    Talk(SAY_TWIGGY_FLATHEAD_DOWN);
                                    ChallengerDown[i] = true;
                                }
                            }
                        }
                        ChallengerChecker = 1000;
                    } else ChallengerChecker -= diff;

                    if (WaveTimer <= diff)
                    {
                        if (Wave < 6 && !AffrayChallenger[Wave].IsEmpty() && !EventBigWill)
                        {
                            Talk(SAY_TWIGGY_FLATHEAD_FRAY);
                            Creature* creature = ObjectAccessor::GetCreature(*me, AffrayChallenger[Wave]);
                            if (creature && (creature->IsAlive()))
                            {
                                creature->SetUninteractible(false);
                                creature->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                                creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                creature->SetFaction(14);
                                creature->AI()->AttackStart(warrior);
                                ++Wave;
                                WaveTimer = 20000;
                            }
                        }
                        else if (Wave >= 6 && !EventBigWill)
                        {
                            if (Creature* creature = me->SummonCreature(NPC_BIG_WILL, -1722, -4341, 6.12f, 6.26f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 8min))
                            {
                                BigWill = creature->GetGUID();
                                //creature->GetMotionMaster()->MovePoint(0, -1693, -4343, 4.32f);
                                //creature->GetMotionMaster()->MovePoint(1, -1684, -4333, 2.78f);
                                creature->GetMotionMaster()->MovePoint(2, -1682, -4329, 2.79f);
                                creature->HandleEmoteCommand(EMOTE_STATE_READY_UNARMED);
                                EventBigWill = true;
                                WaveTimer = 1000;
                            }
                        }
                        else if (Wave >= 6 && EventBigWill && !BigWill.IsEmpty())
                        {
                            Creature* creature = ObjectAccessor::GetCreature(*me, BigWill);
                            if (!creature || !creature->IsAlive())
                            {
                                Talk(SAY_TWIGGY_FLATHEAD_OVER);
                                Reset();
                            }
                            else // Makes BIG WILL attackable.
                            {
                                creature->SetUninteractible(false);
                                creature->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                                creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                                creature->SetFaction(14);
                                creature->AI()->AttackStart(warrior);
                            }
                        }
                    } else WaveTimer -= diff;
                }
            }
        }
    };

};

/*#####
## npc_wizzlecrank_shredder
#####*/

enum Wizzlecrank
{
    SAY_MERCENARY       = 0,
    SAY_START           = 0,
    SAY_STARTUP1        = 1,
    SAY_STARTUP2        = 2,
    SAY_PROGRESS_1      = 3,
    SAY_PROGRESS_2      = 4,
    SAY_PROGRESS_3      = 5,
    SAY_END             = 6,

    QUEST_ESCAPE        = 863,
    NPC_PILOT_WIZZ      = 3451,
    NPC_MERCENARY       = 3282,

    PATH_ESCORT_WIZZLECRANK = 27514,
};

class npc_wizzlecrank_shredder : public CreatureScript
{
public:
    npc_wizzlecrank_shredder() : CreatureScript("npc_wizzlecrank_shredder") { }

    struct npc_wizzlecrank_shredderAI : public EscortAI
    {
        npc_wizzlecrank_shredderAI(Creature* creature) : EscortAI(creature)
        {
            IsPostEvent = false;
            PostEventTimer = 1000;
            PostEventCount = 0;
            me->SetReactState(REACT_DEFENSIVE);
        }

        bool IsPostEvent;
        uint32 PostEventTimer;
        uint32 PostEventCount;

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 0:
                    Talk(SAY_STARTUP1);
                    break;
                case 17:
                    if (Creature* temp = me->SummonCreature(NPC_MERCENARY, 1128.489f, -3037.611f, 92.701f, 1.472f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 2min))
                    {
                        temp->AI()->Talk(SAY_MERCENARY);
                        me->SummonCreature(NPC_MERCENARY, 1160.172f, -2980.168f, 97.313f, 3.690f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 2min);
                    }
                    break;
                case 24:
                    IsPostEvent = true;
                    break;
            }
        }

        void WaypointStarted(uint32 PointId, uint32 /*pathId*/) override
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (PointId)
            {
                case 9:
                    Talk(SAY_STARTUP2, player);
                    break;
                case 18:
                    Talk(SAY_PROGRESS_1, player);
                    break;
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == NPC_PILOT_WIZZ)
                me->SetStandState(UNIT_STAND_STATE_DEAD);

            if (summoned->GetEntry() == NPC_MERCENARY)
                summoned->AI()->AttackStart(me);
        }

        void UpdateEscortAI(uint32 Diff) override
        {
            if (UpdateVictim())
                return;

            if (!IsPostEvent)
                return;

            if (PostEventTimer > Diff)
            {
                PostEventTimer -= Diff;
                return;
            }

            switch (PostEventCount)
            {
                case 0:
                    Talk(SAY_PROGRESS_2);
                    break;
                case 1:
                    Talk(SAY_PROGRESS_3);
                    break;
                case 2:
                    Talk(SAY_END);
                    break;
                case 3:
                    if (Player* player = GetPlayerForEscort())
                    {
                        player->GroupEventHappens(QUEST_ESCAPE, me);
                        me->DespawnOrUnsummon(5min);
                        me->SummonCreature(NPC_PILOT_WIZZ, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 3min);
                    }
                    break;
            }

            ++PostEventCount;
            PostEventTimer = 5000;
        }

        void OnQuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_ESCAPE)
            {
                me->SetFaction(FACTION_RATCHET);
                Talk(SAY_START);
                SetDespawnAtEnd(false);
                LoadPath(PATH_ESCORT_WIZZLECRANK),
                Start(true, player->GetGUID());
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_wizzlecrank_shredderAI(creature);
    }

};

void AddSC_the_barrens()
{
    new npc_wizzlecrank_shredder();
}
