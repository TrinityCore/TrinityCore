/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "MoveSplineInit.h"
#include "Player.h"
#include "grim_batol.h"

enum Spells
{
    // Drahga
   SPELL_BURNING_SHADOWBOLT         = 75245,
   SPELL_BURNING_SHADOWBOLT_DUMMY   = 75246,
   SPELL_INVOCATION_OF_FLAME_SUMMON = 75218,
   SPELL_TWILIGHT_PROTECTION        = 76303,
   SPELL_RIDE_VEHICLE               = 43671,

   // Invoked Flaming Spirit
   SPELL_FLAMING_FIXATE             = 82850,
   SPELL_QUIETE_SUICIDE             = 3617,

   // Valiona
   SPELL_TWILIGHT_SHIFT             = 75328,
   SPELL_SHREDDING_SWIPE            = 75271,
   SPELL_DEVOURING_FLAMES_AOE       = 90945,
   SPELL_DEVOURING_FLAMES           = 90950,
   SPELL_VALIONAS_FLAME             = 75321,

    // Battered Dragon
    SPELL_ENGULFING_FLAMES          = 74040,
    SPELL_ENGULFING_FLAMES_HC       = 90904,
};

enum Texts
{
    // Drahga
    SAY_INTRO                           = 0,
    SAY_AGGRO                           = 1,
    SAY_ANNOUNCE_INVOCATION_OF_FLAME    = 2,
    SAY_INVOCATION_OF_FLAME             = 3,
    SAY_VALIONA_INTRO                   = 4,
    SAY_SLAY                            = 5,
    SAY_DEATH                           = 6,

    // Valiona
    SAY_VALIONA_AGGRO                   = 0,
    SAY_ANNOUNCE_DEVOURING_FLAMES       = 1,
    SAY_VALIONA_FLEE                    = 2,
};

enum Events
{
    // Drahga
    EVENT_BURNING_SHADOWBOLT = 1,
    EVENT_INVOCATION_OF_FLAME,

    // Valiona
    EVENT_MOVE_INTRO,
    EVENT_SHREDDING_SWIPE,
    EVENT_DEVOURING_FLAMES,
    EVENT_DEVOURING_FLAMES_CAST,
    EVENT_VALIONAS_FLAME,
    EVENT_MAKE_AGGRESSIVE,

    // Invoked Flaming Spirit
    EVENT_CHASE_PLAYER,
    EVENT_REPEAT_MOVEMENT,
};

enum Phases
{
    PHASE_1 = 1,
    PHASE_2,
};

enum Actions
{
    ACTION_SCHEDULE_EVENTS = 1,
    ACTION_DESPAWN
};

enum Points
{
    POINT_DRAHGA_BORDER = 1,
    POINT_INTRO_1,
    POINT_INTRO_2,
    POINT_LAND,
    POINT_TAKEOFF,
    POINT_FLEE,
};

Position const DrahgaPos = { -402.139f, -668.642f, 266.1214f };
Position const ValionaSummonPos = { -377.974f, -668.2292f, 195.078f, 0.3316126f };
Position const ValionaPos1 = { -376.5573f, -662.6962f, 263.1957f };
Position const ValionaPos2 = { -438.9549f, -697.1077f, 284.6884f };
Position const LandingPos = { -434.099f, -702.906f, 268.767f };
Position const FleePos = { -364.273f, -646.503f, 286.193f };


class boss_drahga_shadowburner : public CreatureScript
{
    public:
        boss_drahga_shadowburner() : CreatureScript("boss_drahga_shadowburner") { }

        struct boss_drahga_shadowburnerAI : public BossAI
        {
            boss_drahga_shadowburnerAI(Creature* creature) : BossAI(creature, DATA_DRAHGA_SHADOWBURNER)
            {
                Initialize();
            }

            void Initialize()
            {
                _introDone = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                me->GetMotionMaster()->MovePath(me->GetEntry() * 10, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, !IsHeroic() ? SPELL_ENGULFING_FLAMES : SPELL_ENGULFING_FLAMES_HC, true);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.SetPhase(PHASE_1);
                events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT, Seconds(3));
                events.ScheduleEvent(EVENT_INVOCATION_OF_FLAME, Seconds(9) + Milliseconds(500));
            }

            void JustDied(Unit* /*victim*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
                events.Reset();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                    valiona->AI()->DoAction(ACTION_DESPAWN);

                _DespawnAtEvade();
            }
             
            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() != NPC_VALIONA)
                    summons.Summon(summon);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(30, damage) && events.IsInPhase(PHASE_1))
                {
                    events.Reset();
                    events.SetPhase(PHASE_2);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveAllAuras();
                    me->AttackStop();
                    me->CastStop();
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(POINT_DRAHGA_BORDER, DrahgaPos);
                    if (Creature* valiona = me->SummonCreature(NPC_VALIONA, ValionaSummonPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        valiona->SetHover(true);
                        valiona->SetDisableGravity(true);
                    }
                }
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_DRAHGA_BORDER:
                        Talk(SAY_VALIONA_INTRO);
                        if (Creature* valiona = instance->GetCreature(DATA_VALIONA))
                            DoCast(valiona, SPELL_RIDE_VEHICLE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch(action)
                {
                    case ACTION_SCHEDULE_EVENTS:
                        events.ScheduleEvent(EVENT_BURNING_SHADOWBOLT, Milliseconds(1));
                        events.ScheduleEvent(EVENT_INVOCATION_OF_FLAME, Milliseconds(1));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BURNING_SHADOWBOLT:
                            DoCast(SPELL_BURNING_SHADOWBOLT);
                            events.Repeat(Seconds(2) + Milliseconds(500));
                            break;
                        case EVENT_INVOCATION_OF_FLAME:
                            Talk(SAY_ANNOUNCE_INVOCATION_OF_FLAME);
                            Talk(SAY_INVOCATION_OF_FLAME);
                            DoCast(SPELL_INVOCATION_OF_FLAME_SUMMON);
                            events.Repeat(Seconds(29));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            bool _introDone;
        };
        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGrimBatolAI<boss_drahga_shadowburnerAI>(creature);
        }
};

class npc_drahga_valiona : public CreatureScript
{
    public:
        npc_drahga_valiona() : CreatureScript("npc_drahga_valiona") { }

        struct npc_drahga_valionaAI : public ScriptedAI
        {
            npc_drahga_valionaAI(Creature* creature) : ScriptedAI(creature), _summons(me), _instance(me->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _finished = false;
            }

            void IsSummonedBy(Unit* /*summon*/) override
            {
                me->SetDisableGravity(true);
                me->SetHover(true);
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                me->SetSpeed(MOVE_FLIGHT, 4.5f);
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
            {
                if (apply)
                    _events.ScheduleEvent(EVENT_MOVE_INTRO, Seconds(5));
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_INTRO_1:
                        DoZoneInCombat();
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        me->GetMotionMaster()->MovePoint(POINT_INTRO_2, ValionaPos2);
                        break;
                    case POINT_INTRO_2:
                        me->GetMotionMaster()->MoveLand(POINT_LAND, LandingPos);
                        break;
                    case POINT_LAND:
                        me->SendMovementSetSplineAnim(Movement::AnimType::ToGround);
                        me->SetDisableGravity(false);
                        me->SetHover(false);
                        me->SendMovementSetSplineAnim(Movement::AnimType::ToGround);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetReactState(REACT_AGGRESSIVE);

                        if (Unit* nearTarget = me->SelectNearestTarget(100.0f))
                            AttackStart(nearTarget);

                        if (Creature* drahga = _instance->GetCreature(DATA_DRAHGA_SHADOWBURNER))
                            drahga->AI()->DoAction(ACTION_SCHEDULE_EVENTS);

                        _events.ScheduleEvent(EVENT_SHREDDING_SWIPE, Seconds(1));
                        _events.ScheduleEvent(EVENT_DEVOURING_FLAMES, Seconds(15) + Milliseconds(500));
                        break;
                    case POINT_TAKEOFF:
                        me->GetMotionMaster()->MovePoint(POINT_FLEE, FleePos);
                        break;
                    case POINT_FLEE:
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                        me->DespawnOrUnsummon(Milliseconds(100));
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(20, damage)  && !_finished)
                {
                    Talk(SAY_VALIONA_FLEE);
                    DoCast(SPELL_TWILIGHT_SHIFT);
                    me->AttackStop();
                    me->CastStop();
                    me->SetReactState(REACT_PASSIVE);
                    _events.Reset();
                    me->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);
                    me->SetDisableGravity(true);
                    me->SetHover(true);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);

                    Position pos;
                    pos.Relocate(me);
                    pos.m_positionZ += 12.0f;
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveTakeoff(POINT_TAKEOFF, pos);

                    if (Creature* drahga = _instance->GetCreature(DATA_DRAHGA_SHADOWBURNER))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, drahga);
                        drahga->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        drahga->SetReactState(REACT_AGGRESSIVE);
                    }
                    _finished = true;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_DESPAWN:
                        _summons.DespawnAll();
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                        me->DespawnOrUnsummon(100);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_INTRO:
                            Talk(SAY_VALIONA_AGGRO);
                            me->GetMotionMaster()->MovePoint(POINT_INTRO_1, ValionaPos1);
                            break;
                        case EVENT_SHREDDING_SWIPE:
                            DoCastVictim(SPELL_SHREDDING_SWIPE);
                            _events.Repeat(Seconds(25));
                            break;
                        case EVENT_DEVOURING_FLAMES:
                            if (IsHeroic())
                            {
                                DoCast(SPELL_DEVOURING_FLAMES_AOE);
                                _events.ScheduleEvent(EVENT_DEVOURING_FLAMES_CAST, Milliseconds(400));
                            }
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                                DoCast(target, SPELL_VALIONAS_FLAME);

                            _events.Repeat(Seconds(25));
                            break;
                        case EVENT_DEVOURING_FLAMES_CAST:
                            if (Creature* dummy = me->FindNearestCreature(NPC_DEVOURING_FLAMES, 200.0f, true))
                            {
                                Talk(SAY_ANNOUNCE_DEVOURING_FLAMES);
                                me->StopMoving();
                                me->SetFacingToObject(dummy);
                                DoCast(dummy, SPELL_DEVOURING_FLAMES);
                                _events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(7) + Milliseconds(500));
                            }
                            break;
                        case EVENT_MAKE_AGGRESSIVE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        private:
            InstanceScript* _instance;
            EventMap _events;
            SummonList _summons;
            bool _finished;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGrimBatolAI<npc_drahga_valionaAI>(creature);
        }
};

class npc_drahga_invoked_flaming_spirit : public CreatureScript
{
    public:
        npc_drahga_invoked_flaming_spirit() : CreatureScript("npc_drahga_invoked_flaming_spirit") { }

        struct npc_drahga_invoked_flaming_spiritAI : public ScriptedAI
        {
            npc_drahga_invoked_flaming_spiritAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetWalk(true);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_CHASE_PLAYER, Seconds(2));
            }

            void JustDied(Unit* /*killer*/)
            {
                me->DespawnOrUnsummon(Seconds(3));
            }

            void DamageDealt(Unit* /*target*/, uint32 &/*damage*/, DamageEffectType damagetype) override
            {
                if (damagetype == SPELL_DIRECT_DAMAGE)
                    DoCastSelf(SPELL_QUIETE_SUICIDE, true);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHASE_PLAYER:
                            me->SetReactState(REACT_AGGRESSIVE);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, 0))
                            {
                                DoCast(target, SPELL_FLAMING_FIXATE, true);
                                AttackStart(target);
                                me->AddThreat(target, 1500500.0f);
                                me->ClearUnitState(UNIT_STATE_CASTING);
                                me->GetMotionMaster()->MovePoint(0, target->GetPosition(), true);
                                _events.ScheduleEvent(EVENT_REPEAT_MOVEMENT, Seconds(1));
                            }
                            break;
                        case EVENT_REPEAT_MOVEMENT:
                            if (Unit* target = me->GetVictim())
                                me->GetMotionMaster()->MovePoint(0, target->GetPosition(), true);
                            _events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetGrimBatolAI<npc_drahga_invoked_flaming_spiritAI>(creature);
    }
};

class spell_drahga_burning_shadowbolt : public SpellScript
{
    PrepareSpellScript(spell_drahga_burning_shadowbolt);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BURNING_SHADOWBOLT_DUMMY });
    }

    void CastDummySpell(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_BURNING_SHADOWBOLT_DUMMY, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_drahga_burning_shadowbolt::CastDummySpell, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_drahga_devouring_flames : public SpellScript
{
    PrepareSpellScript(spell_drahga_devouring_flames);

    void ChangeDamage()
    {
        if (Unit* caster = GetCaster())
        {
            float distance = GetHitUnit()->GetDistance(caster) * 3.0f;

            uint32 damageReduction = CalculatePct(GetHitDamage(), distance);
            SetHitDamage(GetHitDamage() - damageReduction);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_drahga_devouring_flames::ChangeDamage);
    }
};

void AddSC_boss_drahga_shadowburner()
{
    new boss_drahga_shadowburner();
    new npc_drahga_valiona();
    new npc_drahga_invoked_flaming_spirit();
    RegisterSpellScript(spell_drahga_burning_shadowbolt);
    RegisterSpellScript(spell_drahga_devouring_flames);
}
