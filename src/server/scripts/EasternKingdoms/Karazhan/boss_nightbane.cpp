/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "karazhan.h"

enum NightbaneSpells
{
    SPELL_BELLOWING_ROAR        = 36922,
    SPELL_CHARRED_EARTH         = 30129,
    SPELL_CLEAVE                = 30131,
    SPELL_DISTRACTING_ASH       = 30130,
    SPELL_SMOLDERING_BREATH     = 30210,
    SPELL_TAIL_SWEEP            = 25653,
    SPELL_RAIN_OF_BONES         = 37098,
    SPELL_SMOKING_BLAST         = 30128,
    SPELL_SMOKING_BLAST_T       = 37057,
    SPELL_FIREBALL_BARRAGE      = 30282,
    SPELL_SUMMON_SKELETON       = 30170
};

enum Says
{
    EMOTE_SUMMON                = 0,
    YELL_AGGRO                  = 1,
    YELL_FLY_PHASE              = 2,
    YELL_LAND_PHASE             = 3,
    EMOTE_BREATH                = 4
};

enum NightbaneEvents
{
    EVENT_BELLOWING_ROAR = 1,
    EVENT_CHARRED_EARTH,
    EVENT_DISTRACTING_ASH,
    EVENT_SMOLDERING_BREATH,
    EVENT_TAIL_SWEEP,
    EVENT_CLEAVE,
    EVENT_EMOTE_BREATH,
    EVENT_RAIN_OF_BONES,
    EVENT_SMOKING_BLAST,
    EVENT_SMOKING_BLAST_T,
    EVENT_PRE_LAND,
    EVENT_LAND,
    EVENT_LANDED,
    EVENT_START_INTRO_PATH,
    EVENT_END_INTRO,
    EVENT_INTRO_LANDING,
    EVENT_END_PHASE_TWO,
    EVENT_FACE_TARGET
};

enum NightbanePhases
{
    PHASE_INTRO = 0,
    PHASE_GROUND,
    PHASE_FLY
};

enum NightbaneGroups
{
    GROUP_GROUND = 1,
    GROUP_FLY
};

enum NightbanePoints
{
    POINT_INTRO_START       = 0,
    POINT_INTRO_END         = 1,
    POINT_INTRO_LANDING     = 2,
    POINT_PHASE_TWO_FLY     = 3,
    POINT_PHASE_TWO_END     = 6,
    POINT_PHASE_TWO_LANDING = 5,
};

enum NightbaneMisc
{
    ACTION_SUMMON  = 0,
    PATH_PHASE_TWO = 13547500
};

Position const FlyPosition = { -11160.13f, -1870.683f, 97.73876f, 0.0f };

class boss_nightbane : public CreatureScript
{
public:
    boss_nightbane() : CreatureScript("boss_nightbane") { }

    struct boss_nightbaneAI : public BossAI
    {
        boss_nightbaneAI(Creature* creature) : BossAI(creature, DATA_NIGHTBANE), _flyCount(0) { }

        void Reset() override
        {
            _Reset();
            _flyCount = 0;
            HandleTerraceDoors(true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            HandleTerraceDoors(true);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_SUMMON)
            {
                Talk(EMOTE_SUMMON);
                events.SetPhase(PHASE_INTRO);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_INTRO_START, 1, false);
                HandleTerraceDoors(false);
            }
        }

        void SetupGroundPhase()
        {
            events.SetPhase(PHASE_GROUND);
            events.ScheduleEvent(EVENT_CLEAVE, Seconds(6), Seconds(20), GROUP_GROUND);
            events.ScheduleEvent(EVENT_TAIL_SWEEP, Seconds(18), Seconds(30), GROUP_GROUND);
            events.ScheduleEvent(EVENT_BELLOWING_ROAR, Seconds(46), Minutes(1), GROUP_GROUND);
            events.ScheduleEvent(EVENT_CHARRED_EARTH, Seconds(18), Seconds(47), GROUP_GROUND);
            events.ScheduleEvent(EVENT_SMOLDERING_BREATH, Seconds(28), Seconds(35), GROUP_GROUND);
            events.ScheduleEvent(EVENT_DISTRACTING_ASH, Minutes(1), Minutes(2), GROUP_GROUND);
        }

        void HandleTerraceDoors(bool open)
        {
            instance->HandleGameObject(instance->GetGuidData(DATA_MASTERS_TERRACE_DOOR_1), open);
            instance->HandleGameObject(instance->GetGuidData(DATA_MASTERS_TERRACE_DOOR_2), open);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(YELL_AGGRO);
            SetupGroundPhase();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (events.IsInPhase(PHASE_FLY))
            {
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() -1;
                return;
            }

            if (_flyCount == 0 && HealthBelowPct(75) || _flyCount == 1 && HealthBelowPct(50) || _flyCount == 2 && HealthBelowPct(25))
            {
                events.SetPhase(PHASE_FLY);
                StartPhaseFly();
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type == SPLINE_CHAIN_MOTION_TYPE)
            {
                switch (pointId)
                {
                    case POINT_INTRO_START:
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        events.ScheduleEvent(EVENT_START_INTRO_PATH, Seconds(0));
                        break;
                    case POINT_INTRO_END:
                        events.ScheduleEvent(EVENT_END_INTRO, Seconds(2));
                        break;
                    case POINT_INTRO_LANDING:
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                        events.ScheduleEvent(EVENT_INTRO_LANDING, Seconds(3));
                        break;
                    case POINT_PHASE_TWO_LANDING:
                        events.SetPhase(PHASE_GROUND);
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                        events.ScheduleEvent(EVENT_LANDED, Seconds(3));
                        break;
                    default:
                        break;
                }
            }
            else if (type == POINT_MOTION_TYPE && pointId == POINT_PHASE_TWO_FLY)
            {
                events.ScheduleEvent(EVENT_FACE_TARGET, Seconds(1), GROUP_FLY);
                events.ScheduleEvent(EVENT_PRE_LAND, Seconds(33), GROUP_FLY);
                events.ScheduleEvent(EVENT_EMOTE_BREATH, Seconds(2), GROUP_FLY);
                events.ScheduleEvent(EVENT_SMOKING_BLAST_T, Seconds(17), GROUP_FLY);
                events.ScheduleEvent(EVENT_SMOKING_BLAST, Seconds(18), GROUP_FLY);
            }
            else if (type == WAYPOINT_MOTION_TYPE && pointId == POINT_PHASE_TWO_END)
                events.ScheduleEvent(EVENT_END_PHASE_TWO, Seconds(0));
        }

        void StartPhaseFly()
        {
            ++_flyCount;
            Talk(YELL_FLY_PHASE);
            events.CancelEventGroup(GROUP_GROUND);
            me->InterruptNonMeleeSpells(false);
            me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            me->GetMotionMaster()->MovePoint(POINT_PHASE_TWO_FLY, FlyPosition, false);
         }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_START_INTRO_PATH:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_INTRO_END, 2, false);
                    break;
                case EVENT_END_INTRO:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_INTRO_LANDING, 3, false);
                    break;
                case EVENT_END_PHASE_TWO:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_PHASE_TWO_LANDING, 5, false);
                    break;
                case EVENT_INTRO_LANDING:
                    me->SetHomePosition(me->GetPosition());
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    me->SetInCombatWithZone();
                    break;
                case EVENT_PRE_LAND:
                    events.CancelEventGroup(GROUP_FLY);
                    events.ScheduleEvent(EVENT_LAND, Seconds(2), GROUP_GROUND);
                    break;
                case EVENT_LAND:
                    Talk(YELL_LAND_PHASE);
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->GetMotionMaster()->MovePath(PATH_PHASE_TWO, false);
                    break;
                case EVENT_LANDED:
                    SetupGroundPhase();
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_FACE_TARGET:
                    me->SetFacingToObject(me->GetVictim(), true);
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(Seconds(6), Seconds(20));
                    break;
                case EVENT_BELLOWING_ROAR:
                    DoCastAOE(SPELL_BELLOWING_ROAR);
                    events.Repeat(Seconds(46), Minutes(1));
                    break;
                case EVENT_CHARRED_EARTH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                        DoCast(target, SPELL_CHARRED_EARTH);
                    events.Repeat(Seconds(18), Seconds(47));
                    break;
                case EVENT_DISTRACTING_ASH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_DISTRACTING_ASH);
                    break;
                case EVENT_SMOLDERING_BREATH:
                    DoCastVictim(SPELL_SMOLDERING_BREATH);
                    events.Repeat(Seconds(28), Seconds(35));
                    break;
                case EVENT_TAIL_SWEEP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        if (!me->HasInArc(float(M_PI), target))
                            DoCast(target, SPELL_TAIL_SWEEP);
                    events.Repeat(Seconds(18), Seconds(30));
                    break;
                case EVENT_EMOTE_BREATH:
                    Talk(EMOTE_BREATH);
                    events.ScheduleEvent(EVENT_RAIN_OF_BONES, Seconds(3), GROUP_FLY);
                    break;
                case EVENT_RAIN_OF_BONES:
                    DoResetThreat();
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_RAIN_OF_BONES);
                    break;
                case EVENT_SMOKING_BLAST_T:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_SMOKING_BLAST_T);
                    events.Repeat(Seconds(6));
                    break;
                case EVENT_SMOKING_BLAST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_SMOKING_BLAST);
                    events.Repeat(Milliseconds(1200));
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                ExecuteEvent(eventId);
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

        private:
            uint8 _flyCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_nightbaneAI>(creature);
    }
};

// 37098 - Rain of Bones
class spell_rain_of_bones : public SpellScriptLoader
{
    public:
        spell_rain_of_bones() : SpellScriptLoader("spell_rain_of_bones") { }

        class spell_rain_of_bones_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rain_of_bones_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_SKELETON))
                    return false;
                return true;
            }

            void OnTrigger(AuraEffect const* aurEff)
            {
                if (aurEff->GetTickNumber() % 5 == 0)
                    GetTarget()->CastSpell(GetTarget(), SPELL_SUMMON_SKELETON, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rain_of_bones_AuraScript::OnTrigger, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rain_of_bones_AuraScript();
        }
};

class go_blackened_urn : public GameObjectScript
{
public:
    go_blackened_urn() : GameObjectScript("go_blackened_urn") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE))
            return true;

        InstanceScript* instance = go->GetInstanceScript();
        if (!instance || instance->GetBossState(DATA_NIGHTBANE) == DONE || instance->GetBossState(DATA_NIGHTBANE) == IN_PROGRESS)
            return false;

        if (Creature* nightbane = ObjectAccessor::GetCreature(*go, instance->GetGuidData(DATA_NIGHTBANE)))
        {
            nightbane->AI()->DoAction(ACTION_SUMMON);
            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        }
        return true;
    }
};

void AddSC_boss_nightbane()
{
    new boss_nightbane();
    new spell_rain_of_bones();
    new go_blackened_urn();
}
