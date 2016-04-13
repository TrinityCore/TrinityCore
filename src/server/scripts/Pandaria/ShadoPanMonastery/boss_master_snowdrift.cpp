/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shadopan_monastery.h"
#include "Vehicle.h"

enum eSpells
{
    // Snowdrift

    SPELL_CHASE_DOWN            = 118961,
    SPELL_FIST_OF_FURY          = 106853,
    SPELL_PARRY_STANCE          = 106454,
    SPELL_QUIVERING_PALM        = 106422,
    SPELL_TORNADO_KICK          = 106434,

    SPELL_SMOKE_BOMB            = 110444,

    // Novices
    SPELL_FIRE_FLOWER           = 106547,
    SPELL_HUNDRED_HAND_STRIKE   = 106428,
    SPELL_PALM_STRIKE           = 106421,
    SPELL_PARRY_STANCE_NOVICES  = 106447,

    // Flagrant Lotus
    SPELL_BALL_OF_FIRE          = 113760,
    SPELL_BALL_OF_FIRE_DAMAGE   = 106470,
    SPELL_FLYING_KICK           = 106439,

    SPELL_CALL_STAFF            = 106681,
    SPELL_RELEASE_STAFF         = 106680,

    // Flying Snow
    SPELL_WHIRLING_STEEL_FOCUS  = 106699,
    SPELL_WHIRLING_STEEL_DAMAGE = 106646,

    // Both
    SPELL_FLARE                 = 132951,
};

enum eEvents
{
    // Snowdrift
    EVENT_FIRST_EVENT           = 1,
    EVENT_NOVICE_DEFEATED       = 2,
    EVENT_CHECK_WIPE            = 3,

    EVENT_CHASE_DOWN            = 4,
    EVENT_FIST_OF_FURY          = 5,
    EVENT_PARRY_STANCE          = 6,
    EVENT_QUIVERING_PALM        = 7,
    EVENT_TORNADO_KICK          = 8,
    EVENT_FIREBALL              = 9,
    EVENT_PHASE_3               = 10,

    EVENT_DISAPPEAR             = 11,
    EVENT_DISAPPEAR_TWO         = 12,

    // Novices
    EVENT_FIRE_FLOWER           = 13,
    EVENT_HUNDRED_HAND_STRIKE   = 14,
    EVENT_PALM_STRIKE           = 15,
    EVENT_PARRY_STANCE_NOVICES  = 16,

    // Miniboss
    EVENT_BALL_OF_FIRE          = 17,
    EVENT_FLYING_KICK           = 18,
    EVENT_CALL_STAFF            = 19,
    EVENT_RELEASE_STAFF         = 20,
    
    EVENT_WHIRLING_STEEL_FOCUS  = 21,
    EVENT_WHIRLING_STEEL_CHANGE = 22,
    EVENT_WHIRLING_STEEL_STOP   = 23
};

enum ePhases
{
    PHASE_FIRST_EVENT   = 1,
    PHASE_FIGHT_1       = 2,
    PHASE_FIGHT_2       = 3,
    PHASE_FIGHT_3       = 4
};

enum ePoints
{
    POINT_BEGIN_EVENT               = 1,
    POINT_PHASE_FIGHT               = 2,

    POINT_NOVICE_JUMP               = 3,
    POINT_NOVICE_DEFEATED           = 4,
    POINT_NOVICE_DEFEATED_SECOND    = 5,

    POINT_MINIBOSS_JUMP             = 6,
    POINT_MINIBOSS_DEFEATED         = 7
};

Position SnowdriftPos[2] =
{
    {3680.56f, 3045.27f, 816.20f},
    {3713.60f, 3091.87f, 817.31f}
};

Position InitiateSpawnPos[5] =
{
    {3708.56f, 3039.60f, 816.28f},
    {3699.19f, 3049.62f, 816.28f},
    {3688.03f, 3055.68f, 816.28f},
    {3675.10f, 3066.98f, 816.28f},
    {3668.95f, 3070.81f, 816.28f}
};

Position MinibossSpawnPos[2] =
{
    {3683.72f, 3053.94f, 816.28f},
    {3687.77f, 3051.30f, 816.28f}
};

Position ClonePos[3] =
{
    {3683.37f, 3087.65f, 815.70f, 0.0f},
    {3719.41f, 3062.31f, 815.70f, 1.88f},
    {3718.04f, 3097.97f, 817.40f, 4.06f}
};

Position minibossPositions[2] =
{
    { 3671.85f, 3006.39f, 804.679f },
    { 3646.40f, 3024.52f, 804.679f }
};
Position firstDefeatedNovicePositions[24] =
{
    { 3642.07f, 3007.95f, 804.301f },
    { 3643.07f, 3005.34f, 804.301f },
    { 3668.02f, 2998.53f, 804.301f },
    { 3665.42f, 2997.93f, 804.301f },
    { 3662.65f, 2997.63f, 804.301f },
    { 3659.94f, 2997.27f, 804.301f },
    { 3657.04f, 2996.85f, 804.301f },
    { 3654.17f, 2997.31f, 804.301f },
    { 3677.56f, 3011.37f, 804.301f },
    { 3677.13f, 3014.33f, 804.301f },
    { 3641.46f, 3010.64f, 804.301f },
    { 3640.81f, 3013.26f, 804.301f },
    { 3640.56f, 3016.13f, 804.301f },
    { 3676.65f, 3017.30f, 804.301f },
    { 3640.44f, 3018.64f, 804.301f },
    { 3676.13f, 3020.28f, 804.301f },
    { 3675.41f, 3023.17f, 804.301f },
    { 3674.15f, 3026.05f, 804.301f },
    { 3648.46f, 3031.57f, 804.301f },
    { 3651.47f, 3032.63f, 804.301f },
    { 3654.27f, 3033.10f, 804.301f },
    { 3663.77f, 3033.46f, 804.301f },
    { 3657.50f, 3033.46f, 804.301f },
    { 3660.63f, 3033.71f, 804.301f }
};


Position secondDefeatedNovicePositions[24] =
{
    { 3659.72f, 3037.73f, 804.301f },
    { 3657.27f, 3039.43f, 804.301f },
    { 3648.35f, 3037.33f, 804.301f },
    { 3664.35f, 3034.39f, 804.301f },
    { 3646.22f, 3034.40f, 804.301f },
    { 3662.04f, 3036.03f, 804.301f },
    { 3635.09f, 3009.65f, 804.301f },
    { 3675.18f, 3026.89f, 804.301f },
    { 3677.58f, 3025.08f, 804.301f },
    { 3682.78f, 3021.06f, 804.301f },
    { 3636.71f, 3021.36f, 804.301f },
    { 3680.15f, 3023.08f, 804.301f },
    { 3634.97f, 3018.46f, 804.301f },
    { 3637.71f, 3007.63f, 804.301f },
    { 3640.56f, 3005.48f, 804.301f },
    { 3643.01f, 3003.74f, 804.301f },
    { 3653.33f, 2996.27f, 804.301f },
    { 3655.87f, 2994.63f, 804.301f },
    { 3658.03f, 2993.08f, 804.301f },
    { 3660.58f, 2991.60f, 804.301f },
    { 3669.29f, 2994.17f, 804.301f },
    { 3671.50f, 2996.79f, 804.301f },
    { 3681.22f, 3010.18f, 804.301f },
    { 3683.09f, 3012.87f, 804.301f }
};

enum eTalks
{
    TALK_INTRO_1            = 0,
    TALK_INTRO_2            = 1,
    TALK_INITIATE_BEGIN     = 2,
    TALK_INITIATE_DEATH_1   = 3,
    TALK_INITIATE_DEATH_2   = 4,
    TALK_INITIATE_END       = 5,
    TALK_MINIBOSS_BEGIN     = 6,
    TALK_MINIBOSS_END_1     = 7,
    TALK_MINIBOSS_END_2     = 8,
    TALK_MINIBOSS_END_3     = 9,
    TALK_AGGRO              = 10,
    TALK_PHASE_1            = 11,
    TALK_PHASE_2            = 12,
    TALK_PHASE_3            = 13,
    TALK_DEATH              = 14,
    TALK_SLAY               = 15,
};

#define defaultrand urand(1000, 10000)

class boss_master_snowdrift : public CreatureScript
{
    public:
        boss_master_snowdrift() : CreatureScript("boss_master_snowdrift") {}

        struct boss_master_snowdriftAI : public BossAI
        {
            boss_master_snowdriftAI(Creature* creature) : BossAI(creature, DATA_MASTER_SNOWDRIFT)
            {
                defeated = false;
            }

            bool introStarted;
            bool defeated;

            uint8 phase;
            uint8 eventPhase;

            void Reset()
            {
                if (!instance)
                    return;

                if (defeated)
                    return;

                _Reset();

                introStarted = false;
                phase = PHASE_FIRST_EVENT;
                eventPhase = 0;

                Position pos;
                pos = SnowdriftPos[POINT_BEGIN_EVENT - 1].GetPosition();
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(POINT_BEGIN_EVENT, pos);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
               //SetCanSeeEvenInPassiveMode(true);
                me->setRegeneratingHealth(true);

                for (uint8 i = 0; i < 2; ++i)
                {
                    if (Creature* minibossPosCreature = me->SummonCreature(NPC_SNOWDRIFT_POSITION, minibossPositions[i]))
                        instance->SetData64(DATA_ADD_MINIBOSS_POS, (int)minibossPosCreature->GetGUID());
                }

                for (uint8 i = 0; i < 24; ++i)
                {
                    if (Creature* firstPosCreature = me->SummonCreature(NPC_SNOWDRIFT_POSITION, firstDefeatedNovicePositions[i]))
                        instance->SetData64(DATA_ADD_FIRST_POS, (int)firstPosCreature->GetGUID());

                    if (Creature* secondPosCreature = me->SummonCreature(NPC_SNOWDRIFT_POSITION, secondDefeatedNovicePositions[i]))
                        instance->SetData64(DATA_ADD_SECOND_POS, (int)secondPosCreature->GetGUID());
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                initDefaultEventsForPhase();
            }

            void KilledUnit(Unit* u)
            {
                if (!urand(0, 1))
                    Talk(TALK_SLAY);
            }

            void initDefaultEventsForPhase()
            {
                events.CancelEventGroup(PHASE_FIGHT_1);
                events.CancelEventGroup(PHASE_FIGHT_2);
                events.CancelEventGroup(PHASE_FIGHT_3);

                switch (phase)
                {
                    case PHASE_FIGHT_1:
                        Talk(TALK_PHASE_1);
                        events.ScheduleEvent(EVENT_TORNADO_KICK, urand(7500, 12500), PHASE_FIGHT_1);
                        events.ScheduleEvent(EVENT_FIST_OF_FURY, urand(5000, 10000), PHASE_FIGHT_1);
                        events.ScheduleEvent(EVENT_CHASE_DOWN, defaultrand, PHASE_FIGHT_1);
                        break;
                    case PHASE_FIGHT_2:
                        Talk(TALK_PHASE_2);
                        events.ScheduleEvent(EVENT_FIREBALL, urand(2500, 5000), PHASE_FIGHT_2);
                        events.ScheduleEvent(EVENT_PHASE_3, urand(10000, 15000), PHASE_FIGHT_2);
                        break;
                    case PHASE_FIGHT_3:
                        Talk(TALK_PHASE_3);
                        events.ScheduleEvent(EVENT_PARRY_STANCE, urand(10000, 15000), PHASE_FIGHT_3);
                        events.ScheduleEvent(EVENT_QUIVERING_PALM, urand(5000, 10000), PHASE_FIGHT_3);
                        break;
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->ToPlayer())
                {
                    if (who->ToPlayer()->IsGameMaster())
                        return;

                    if (me->GetDistance(who) < 55.0f && !introStarted)
                    {
                        introStarted = true;
                        instance->SetBossState(DATA_MASTER_SNOWDRIFT, SPECIAL);
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 1000);
                        events.ScheduleEvent(EVENT_CHECK_WIPE, 1000);
                    }
                }
            }

            void JustReachedHome()
            {
                Position pos;
                pos = SnowdriftPos[POINT_BEGIN_EVENT - 1].GetPosition();
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(POINT_BEGIN_EVENT, pos);

                instance->SetBossState(DATA_MASTER_SNOWDRIFT, FAIL);
                summons.DespawnAll();
            }

            void DoAction(int32 action)
            {
                if (action == ACTION_NOVICE_DONE)
                {
                    events.ScheduleEvent(EVENT_NOVICE_DEFEATED, 2000);
                }
                else if (action == ACTION_MINIBOSS_DONE)
                {
                    ++eventPhase;
                    events.ScheduleEvent(EVENT_FIRST_EVENT, urand(1000, 2000));
                }
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_PHASE_FIGHT:
                        me->setFaction(14);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        // No Break
                    case POINT_BEGIN_EVENT:
                        me->SetFacingTo(me->GetAngle(3659.08f, 3015.38f));
                        break;
                    default:
                        break;
                }
            }

            void DoEvent()
            {
                switch (eventPhase)
                {
                    case 0:
                        Talk(TALK_INTRO_1);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 6500);
                        break;
                    case 1:
                        Talk(TALK_INTRO_2);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 8500);
                        break;
                    case 2:
                        Talk(TALK_INITIATE_BEGIN);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 1000);
                        break;
                    // There is five novices waves
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    {
                        // Last wave have 4 initiates (for a total of 24)
                        uint8 maxInitiateByWave = eventPhase == 7 ? 4: 5;

                        for (uint8 i = 0; i < maxInitiateByWave; ++i)
                            me->SummonCreature(NPC_NOVICE, InitiateSpawnPos[i].GetPositionX(), InitiateSpawnPos[i].GetPositionY(), InitiateSpawnPos[i].GetPositionZ());

                        // When last wave, we wait for all initiate to be defeated
                        if (eventPhase != 7)
                        {
                            if (eventPhase == 4)
                                Talk(TALK_INITIATE_DEATH_2);
                            else if (eventPhase == 6)
                                Talk(TALK_INITIATE_DEATH_1);
                            ++eventPhase;
                            events.ScheduleEvent(EVENT_FIRST_EVENT, urand(12500, 17500));
                        }
                        break;
                    }
                    case 8: // All initiates have been defeated
                    {
                        Talk(TALK_INITIATE_END);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 5500);
                        break;
                    }
                    case 9:
                    {
                        Talk(TALK_MINIBOSS_BEGIN);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 4000);
                        break;
                    }
                    case 10:
                    {
                        me->SummonCreature(NPC_FLAGRANT_LOTUS, MinibossSpawnPos[0].GetPositionX(), MinibossSpawnPos[0].GetPositionY(), MinibossSpawnPos[0].GetPositionZ());
                        me->SummonCreature(NPC_FLYING_SNOW,    MinibossSpawnPos[1].GetPositionX(), MinibossSpawnPos[1].GetPositionY(), MinibossSpawnPos[1].GetPositionZ());
                        break;
                    }
                    case 11: // Miniboss have been defeated
                    {
                        Talk(TALK_MINIBOSS_END_1);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 5500);
                        break;
                    }
                    case 12: // Miniboss have been defeated
                    {
                        Talk(TALK_MINIBOSS_END_2);
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 5500);
                        break;
                    }
                    case 13:
                    {
                        Talk(TALK_MINIBOSS_END_3);
                        if (instance)
                            instance->SetData(DATA_OPEN_DOORS, 1);
                        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                        me->GetMotionMaster()->MovePoint(POINT_PHASE_FIGHT, SnowdriftPos[POINT_PHASE_FIGHT - 1].GetPositionX(), SnowdriftPos[POINT_PHASE_FIGHT - 1].GetPositionY(), SnowdriftPos[POINT_PHASE_FIGHT - 1].GetPositionZ());
                        phase = PHASE_FIGHT_1;
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (phase == PHASE_FIGHT_1)
                {
                    if (me->HealthBelowPctDamaged(70, damage))
                    {
                        me->CombatStop();
                        me->SetReactState(REACT_PASSIVE);

                        me->CastSpell(me, SPELL_SMOKE_BOMB, true);
                        me->SetVisible(false); // We set this for two seconds, time to let client erase players' focus from the boss
                        me->setRegeneratingHealth(false);

                        phase = PHASE_FIGHT_2;
                        events.Reset();
                        events.ScheduleEvent(EVENT_DISAPPEAR, 2000);
                    }
                }

                if (damage >= me->GetHealth())
                {
                    defeated = true;
                    Talk(TALK_DEATH);
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->setFaction(35);
                    me->AttackStop();
                    me->CombatStop();
                    events.Reset();
                    if (instance)
                        instance->SetBossState(DATA_MASTER_SNOWDRIFT, DONE);

                    me->GetMotionMaster()->MovePoint(POINT_PHASE_FIGHT, SnowdriftPos[POINT_PHASE_FIGHT - 1].GetPositionX(), SnowdriftPos[POINT_PHASE_FIGHT - 1].GetPositionY(), SnowdriftPos[POINT_PHASE_FIGHT - 1].GetPositionZ());
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch(uint32 eventId = events.ExecuteEvent())
                {
                    // Event Script
                    case EVENT_FIRST_EVENT:
                        DoEvent();
                        break;
                    case EVENT_NOVICE_DEFEATED:
                    {
                        std::list<Creature*> noviceList;
                        GetCreatureListWithEntryInGrid(noviceList, me, NPC_NOVICE, 100.0f);

                        for (auto novice : noviceList)
                        {
                            if (uint64 guid = instance->GetData64(DATA_RANDOM_SECOND_POS))
                            {
                                if (Creature* position = instance->instance->GetCreature(instance->GetObjectGuid(guid)))
                                {
                                    instance->SetData64(DATA_DELETE_SECOND_POS, guid);
                                    novice->GetMotionMaster()->MoveJump(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), 20.0f, 30.0f, POINT_NOVICE_DEFEATED_SECOND);
                                }
                            }
                        }

                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, urand(1000, 2000));
                        break;
                    }
                    case EVENT_CHECK_WIPE:
                        // There may be no players attacking but this doesn't mean there is nobody inside the instance
                        if (me->getThreatManager().isThreatListEmpty()) 
                            Reset();
                        events.ScheduleEvent(EVENT_CHECK_WIPE, 1000);
                        break;
                    // Combat Script
                    /// Phase 1
                    case EVENT_TORNADO_KICK:
                        me->CastSpell(me, SPELL_TORNADO_KICK, false);
                        events.ScheduleEvent(EVENT_TORNADO_KICK, urand(7500, 12500));
                        break;
                    case EVENT_FIST_OF_FURY:
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_FIST_OF_FURY, false);

                        events.ScheduleEvent(EVENT_FIST_OF_FURY, urand(5000, 10000));
                        break;
                    case EVENT_CHASE_DOWN:
                        // Todo
                        events.ScheduleEvent(eventId, defaultrand);
                        break;
                    /// Phase 2
                    case EVENT_DISAPPEAR:
                    {
                        std::vector<uint8> randomIndex;
                        for (int i = 0; i < 3; ++i) randomIndex.push_back(i); // 0 1 2
                        std::random_shuffle(randomIndex.begin(), randomIndex.end());

                        bool isBoss = true;

                        for (auto index : randomIndex)
                        {
                            // The first random pos is for the boss, the two others are for his clones
                            if (isBoss)
                            {
                                me->NearTeleportTo(ClonePos[index].GetPositionX(), ClonePos[index].GetPositionY(), ClonePos[index].GetPositionZ(), ClonePos[index].GetOrientation());
                                me->SetVisible(true);
                                me->CastSpell(me, SPELL_SMOKE_BOMB, true);
                                isBoss = false;
                            }
                            else
                                if (Creature* clone = me->SummonCreature(NPC_SNOWDRIFT_CLONE, ClonePos[index].GetPositionX(), ClonePos[index].GetPositionY(), ClonePos[index].GetPositionZ(), ClonePos[index].GetOrientation()))
                                    clone->CastSpell(clone, SPELL_SMOKE_BOMB, true);
                        }

                        initDefaultEventsForPhase();
                        break;
                    }
                    case EVENT_FIREBALL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_BALL_OF_FIRE, false);

                        events.ScheduleEvent(EVENT_FIREBALL, urand(1000, 2500));
                        break;
                    /// Phase 3
                    case EVENT_PHASE_3:
                        me->SetReactState(REACT_AGGRESSIVE);
                        phase = PHASE_FIGHT_3;
                        initDefaultEventsForPhase();
                        break;
                    case EVENT_PARRY_STANCE:
                        me->CastSpell(me, SPELL_PARRY_STANCE, false);
                        events.ScheduleEvent(EVENT_PARRY_STANCE, urand(10000, 15000));
                        break;
                    case EVENT_QUIVERING_PALM:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_QUIVERING_PALM, false);

                        events.ScheduleEvent(EVENT_QUIVERING_PALM, urand(5000, 10000));
                        break;
                    default:
                        break;
                }

                if (phase == PHASE_FIGHT_1 || phase == PHASE_FIGHT_3)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_master_snowdriftAI(creature);
        }
};

class npc_snowdrift_novice : public CreatureScript
{
    public:
        npc_snowdrift_novice() :  CreatureScript("npc_snowdrift_novice") { }

        struct npc_snowdrift_noviceAI : public ScriptedAI
        {
            npc_snowdrift_noviceAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                jumpDone = false;
                stillInFight = true;
            }

            InstanceScript* pInstance;
            EventMap events;
            bool jumpDone;
            bool stillInFight;

            void Reset()
            {
                events.Reset();
                if (!jumpDone)
                {
                    float x, y;
                    //GetPositionWithDistInOrientation(me, 40.0f, 4.0f, x, y);
                    me->GetMotionMaster()->MoveJump(x, y, me->GetMap()->GetHeight(x, y, me->GetPositionZ()), 20, 10, POINT_NOVICE_JUMP);
                    jumpDone = true;
                }
                
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                events.ScheduleEvent(EVENT_FIRE_FLOWER,             urand(4000, 40000));
                events.ScheduleEvent(EVENT_FLYING_KICK,             urand(4000, 40000));
                events.ScheduleEvent(EVENT_HUNDRED_HAND_STRIKE,     urand(4000, 40000));
                events.ScheduleEvent(EVENT_PALM_STRIKE,             urand(4000, 40000));
                events.ScheduleEvent(EVENT_PARRY_STANCE_NOVICES,    urand(4000, 40000));
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_NOVICE_JUMP:
                        if (!stillInFight)
                            break;

                        if (Player* target = me->SelectNearestPlayer(100.0f))
                            AttackStart(target);
                        break;
                    case POINT_NOVICE_DEFEATED:
                    case POINT_NOVICE_DEFEATED_SECOND:
                        me->SetFacingTo(me->GetAngle(3659.08f, 3015.38f));
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!stillInFight)
                    return;

                if (!pInstance)
                    return;

                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->setFaction(35);
                    me->AttackStop();
                    me->CombatStop();
                    stillInFight = false;
                    events.Reset();
                    pInstance->SetData(DATA_DEFEATED_NOVICE, 1);

                    if (uint64 guid = pInstance->GetData64(DATA_RANDOM_FIRST_POS))
                    {
                        if (Creature* position = pInstance->instance->GetCreature(pInstance->GetObjectGuid(guid)))
                        {
                            pInstance->SetData64(DATA_DELETE_FIRST_POS, guid);
                            me->GetMotionMaster()->MoveJump(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), 20.0f, 10.0f, POINT_NOVICE_DEFEATED);
                            me->SetHomePosition(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), position->GetOrientation());
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                switch(uint32 eventId = events.ExecuteEvent())
                {
                    case EVENT_FIRE_FLOWER:
                    {
                        me->CastSpell(me, SPELL_FIRE_FLOWER, false);
                        events.ScheduleEvent(EVENT_FIRE_FLOWER,         urand(4000, 40000));
                        break;
                    }
                    case EVENT_FLYING_KICK:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_FLYING_KICK, false);
                        events.ScheduleEvent(EVENT_FLYING_KICK,         urand(4000, 40000));
                        break;
                    }
                    case EVENT_HUNDRED_HAND_STRIKE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_HUNDRED_HAND_STRIKE, false);
                        events.ScheduleEvent(EVENT_HUNDRED_HAND_STRIKE, urand(4000, 40000));
                        break;
                    }
                    case EVENT_PALM_STRIKE:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            me->CastSpell(target, SPELL_PALM_STRIKE, false);
                        events.ScheduleEvent(EVENT_PALM_STRIKE,         urand(4000, 40000));
                        break;
                    }
                    case EVENT_PARRY_STANCE_NOVICES:
                    {
                        me->CastSpell(me, SPELL_PARRY_STANCE_NOVICES, false);
                        events.ScheduleEvent(EVENT_PARRY_STANCE_NOVICES,        urand(4000, 40000));
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_noviceAI(creature);
        }
};

class npc_snowdrift_miniboss : public CreatureScript
{
    public:
        npc_snowdrift_miniboss() :  CreatureScript("npc_snowdrift_miniboss") { }

        struct npc_snowdrift_minibossAI : public ScriptedAI
        {
            npc_snowdrift_minibossAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                jumpDone = false;
                stillInFight = true;
            }

            InstanceScript* pInstance;
            EventMap events;
            bool jumpDone;
            bool stillInFight;
            uint8 whirlwindProgress;

            void Reset()
            {
                events.Reset();
                whirlwindProgress = 0;
                
                me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                if (!jumpDone)
                {
                    float x, y;
                    //GetPositionWithDistInOrientation(me, 30.0f, 4.23f, x, y);
                    me->GetMotionMaster()->MoveJump(x, y, me->GetMap()->GetHeight(x, y, me->GetPositionZ()), 20, 10, POINT_MINIBOSS_JUMP);
                    jumpDone = true;

                    if (me->GetEntry() == NPC_FLAGRANT_LOTUS)
                    {
                        events.ScheduleEvent(EVENT_BALL_OF_FIRE,    1000);
                        events.ScheduleEvent(EVENT_FLYING_KICK,     1000);
                        events.ScheduleEvent(EVENT_CALL_STAFF,      1000);
                        events.ScheduleEvent(EVENT_RELEASE_STAFF,   1000);
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_WHIRLING_STEEL_FOCUS,  1000);
                    }
                }
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_MINIBOSS_DEFEATED:
                        me->SetFacingTo(me->GetAngle(3659.08f, 3015.38f));
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!stillInFight)
                    return;

                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->setFaction(35);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->CombatStop();
                    events.Reset();
                    stillInFight = false;

                    if (uint64 guid = pInstance->GetData64(DATA_RANDOM_MINIBOSS_POS))
                    {
                        if (Creature* position = pInstance->instance->GetCreature(pInstance->GetObjectGuid(guid)))
                        {
                            pInstance->SetData64(DATA_DELETE_MINIBOSS_POS, guid);
                            me->GetMotionMaster()->MovePoint(POINT_MINIBOSS_DEFEATED, position->GetPositionX(), position->GetPositionY(), position->GetPositionZ());
                            me->SetHomePosition(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), position->GetOrientation());
                        }
                    }

                    if (pInstance)
                        pInstance->SetData(DATA_DEFEATED_MINIBOSS, 1);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!stillInFight)
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    case EVENT_BALL_OF_FIRE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_BALL_OF_FIRE, false);

                        events.ScheduleEvent(EVENT_BALL_OF_FIRE, 10000);
                        break;
                    case EVENT_FLYING_KICK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_FLYING_KICK, false);

                        events.ScheduleEvent(EVENT_FLYING_KICK, 10000);
                        break;
                    case EVENT_CALL_STAFF:
                        //me->CastSpell(me, SPELL_CALL_STAFF, false);
                        events.ScheduleEvent(EVENT_CALL_STAFF, 10000);
                        break;
                    case EVENT_RELEASE_STAFF:
                        if (me->GetVehicleKit())
                            if (me->GetVehicleKit()->GetPassenger(0))
                                me->GetVehicleKit()->GetPassenger(0)->ExitVehicle();
                        events.ScheduleEvent(EVENT_CALL_STAFF, 10000);
                        break;
                    case EVENT_WHIRLING_STEEL_FOCUS:
                        me->AddAura(SPELL_WHIRLING_STEEL_DAMAGE, me);
                        me->SetReactState(REACT_PASSIVE);
                        // no break
                    case EVENT_WHIRLING_STEEL_CHANGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->AddAura(SPELL_WHIRLING_STEEL_FOCUS, target);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(target);
                        }
                        if (++whirlwindProgress >= 5)
                            events.ScheduleEvent(EVENT_WHIRLING_STEEL_CHANGE, 2000);
                        else
                            events.ScheduleEvent(EVENT_WHIRLING_STEEL_STOP, 2000);
                        break;
                    case EVENT_WHIRLING_STEEL_STOP:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->GetMotionMaster()->Clear();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            AttackStart(target);
                        events.ScheduleEvent(EVENT_WHIRLING_STEEL_FOCUS, 10000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_minibossAI(creature);
        }
};

class npc_snowdrift_clone : public CreatureScript
{
    public:
        npc_snowdrift_clone() :  CreatureScript("npc_snowdrift_clone") { }

        struct npc_snowdrift_cloneAI : public ScriptedAI
        {
            npc_snowdrift_cloneAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 fireBallTimer;

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->setFaction(14);
                DoZoneInCombat();

                fireBallTimer = 500;
            }

            void UpdateAI(uint32 diff)
            {
                if (fireBallTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                    {
                        me->SetFacingTo(me->GetAngle(target));
                        me->SetOrientation(me->GetAngle(target));
                        me->CastSpell(target, SPELL_BALL_OF_FIRE, true);
                    }

                    fireBallTimer = urand(1000, 2500);
                }
                else fireBallTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_cloneAI(creature);
        }
};

class npc_snowdrift_fireball : public CreatureScript
{
    public:
        npc_snowdrift_fireball() :  CreatureScript("npc_snowdrift_fireball") { }

        struct npc_snowdrift_fireballAI : public ScriptedAI
        {
            npc_snowdrift_fireballAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 damageTimer;

            void Reset()
            {
                float x, y;
                //GetPositionWithDistInOrientation(me, 100.0f, me->GetOrientation(), x, y);
                me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());

                me->SetReactState(REACT_PASSIVE);
                me->setFaction(14);
                me->AddAura(106534, me); // Visual Aura

                damageTimer = 500;
            }

            void UpdateAI(uint32 diff)
            {
                if (damageTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget())
                        if (me->GetDistance(target) <= 1.0f)
                            me->CastSpell(target, SPELL_BALL_OF_FIRE_DAMAGE, true);

                    damageTimer = 500;
                }
                else damageTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_fireballAI(creature);
        }
};

void AddSC_boss_master_snowdrift()
{
    new boss_master_snowdrift();
    new npc_snowdrift_novice();
    new npc_snowdrift_miniboss();
    new npc_snowdrift_clone();
    new npc_snowdrift_fireball();
}
