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
#include "GridNotifiers.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "halls_of_origination.h"

enum Spells
{
    // Rajh
    SPELL_SOLAR_WINDS_DUMMY     = 74104,
    SPELL_SOLAR_WINDS_SUMMON    = 74106,
    SPELL_SUMMON_SUN_ORB        = 80352,
    SPELL_SUN_STRIKE            = 73872,
    SPELL_BLESSING_OF_THE_SUN   = 76352,
    SPELL_INFERNO_LEAP_DUMMY    = 87650,
    SPELL_INFERNO_LEAP_VEHICLE  = 87653,

    // Solar Winds
    SPELL_SOLAR_WINDS_PERIODIC  = 74107,

    // Orb of the Sun
    SPELL_SUMMON_METEOR         = 76375,
    SPELL_RIDE_VEHICLE          = 43671,
};

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_BLESSING_OF_THE_SUN = 1,
    SAY_SLAY                = 2,
    SAY_DEATH               = 3,
};

enum Events
{
    // Rajh
    EVENT_SOLAR_WINDS = 1,
    EVENT_SUMMON_SOLAR_WINDS,
    EVENT_SUMMON_SUN_ORB,
    EVENT_SUN_STRIKE,
    EVENT_SUMMON_INFERNO_LEAP,
    EVENT_INFERNO_LEAP,
    EVENT_APPLY_IMMUNITY,
    EVENT_MOVE_TO_MIDDLE,
    EVENT_BLESSING_OF_THE_SUN,
    EVENT_TALK_BLESSING,
    EVENT_ATTACK,

    // Solar Winds
    EVENT_GROW,
    EVENT_START_MOVING,
    EVENT_MOVE_ARROUND,

    // Orb of the Sun
    EVENT_SUMMON_BLAZING_INFERNO,
    EVENT_RIDE_VEHICLE,
};

enum Points
{
    POINT_RAJH_CENTER = 1,
};

enum AchievementData
{
    DATA_SUN_OF_A = 1,
};

Position const RajhMiddlePos = { -318.5936f, 192.8621f, 343.9443f };

class boss_rajh : public CreatureScript
{
public:
    boss_rajh() : CreatureScript("boss_rajh") { }

    struct boss_rajhAI : public BossAI
    {
        boss_rajhAI(Creature* creature) : BossAI(creature, DATA_RAJH) { }

        void Reset() override
        {
            _Reset();
            _energized = true;
            _achievementEnabled = true;
            me->SetReactState(REACT_PASSIVE);
            me->SetPower(POWER_ENERGY, 100);
            MakeInterruptable(false);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            me->SetReactState(REACT_AGGRESSIVE);
            _randomTimerCase = RAND(0, 1);
            events.ScheduleEvent(EVENT_SOLAR_WINDS, Seconds(5));
            events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, _randomTimerCase == 0 ? Seconds(10) : Seconds(25));
            events.ScheduleEvent(EVENT_SUN_STRIKE, _randomTimerCase == 0 ? Seconds(20) : Seconds(8));
            events.ScheduleEvent(EVENT_SUMMON_INFERNO_LEAP, Seconds(14));
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_INFERNO_LEAP)
            {
                MakeInterruptable(true);
                events.ScheduleEvent(EVENT_INFERNO_LEAP, 1);
                events.ScheduleEvent(EVENT_APPLY_IMMUNITY, Seconds(1) + Milliseconds(500));
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            summons.DespawnAll();
            MakeInterruptable(false);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _DespawnAtEvade();
        }
        void OnSpellCastInterrupt(SpellInfo const* /*spell*/) override
        {
            MakeInterruptable(false);
            events.CancelEvent(EVENT_APPLY_IMMUNITY);
        }

        void MakeInterruptable(bool apply)
        {
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, !apply);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, !apply);
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SUN_OF_A:
                    return _achievementEnabled;
                default:
                    break;
            }
            return 0;
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case POINT_RAJH_CENTER:
                    events.ScheduleEvent(EVENT_BLESSING_OF_THE_SUN, 1);
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->GetPower(POWER_ENERGY) <= 10 && _energized)
            {
                events.ScheduleEvent(EVENT_MOVE_TO_MIDDLE, Seconds(1));
                _energized = false;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SOLAR_WINDS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        {
                            DoCast(target, SPELL_SOLAR_WINDS_DUMMY);
                            events.Repeat(Seconds(15), Seconds(23));
                            events.ScheduleEvent(EVENT_SUMMON_SOLAR_WINDS, Seconds(1));
                        }
                        break;
                    case EVENT_SUMMON_SOLAR_WINDS:
                        DoCastSelf(SPELL_SOLAR_WINDS_SUMMON);
                        break;
                    case EVENT_SUMMON_SUN_ORB:
                        MakeInterruptable(true);
                        me->StopMoving();
                        DoCastSelf(SPELL_SUMMON_SUN_ORB);
                        events.Repeat(_randomTimerCase == 0 ? Seconds(35), Seconds(36) : Seconds(31), Seconds(37));
                        events.ScheduleEvent(EVENT_APPLY_IMMUNITY, Seconds(3));
                        break;
                    case EVENT_SUN_STRIKE:
                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_SUN_STRIKE, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
                        events.Repeat(_randomTimerCase == 0 ? Seconds(35) : Seconds(27));
                        break;
                    case EVENT_APPLY_IMMUNITY:
                        MakeInterruptable(false);
                        break;
                    case EVENT_MOVE_TO_MIDDLE:
                        events.Reset();
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->ExitVehicle();
                        me->GetMotionMaster()->MovePoint(POINT_RAJH_CENTER, RajhMiddlePos, true);
                        break;
                    case EVENT_BLESSING_OF_THE_SUN:
                        DoCastSelf(SPELL_BLESSING_OF_THE_SUN);
                        events.ScheduleEvent(EVENT_TALK_BLESSING, Seconds(1) + Milliseconds(500));
                        events.ScheduleEvent(EVENT_ATTACK, Seconds(20));
                        me->SetFacingTo(3.124139f);
                        break;
                    case EVENT_TALK_BLESSING:
                        Talk(SAY_BLESSING_OF_THE_SUN);
                        me->HandleEmoteCommand(EMOTE_STATE_READY_SPELL_OMNI);
                        break;
                    case EVENT_ATTACK:
                        _achievementEnabled = false;
                        _energized = true;
                        _randomTimerCase = RAND(0, 1);
                        events.ScheduleEvent(EVENT_SOLAR_WINDS, Seconds(5));
                        events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, _randomTimerCase == 0 ? Seconds(10) : Seconds(25));
                        events.ScheduleEvent(EVENT_SUN_STRIKE, _randomTimerCase == 0 ? Seconds(20) : Seconds(8));
                        events.ScheduleEvent(EVENT_SUMMON_INFERNO_LEAP, Seconds(14));
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_SUMMON_INFERNO_LEAP:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_INFERNO_LEAP_DUMMY, true);
                        events.Repeat(Seconds(59), Seconds(60));
                        break;
                    case EVENT_INFERNO_LEAP:
                        DoCastAOE(SPELL_INFERNO_LEAP_VEHICLE);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            bool _energized;
            bool _achievementEnabled;
            uint8 _randomTimerCase;
    };
    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetHallsOfOriginationAI<boss_rajhAI>(creature);
    }
};

class npc_solar_winds : public CreatureScript
{
public:
    npc_solar_winds() : CreatureScript("npc_solar_winds") { }

    struct npc_solar_windsAI : public ScriptedAI
    {
        npc_solar_windsAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetWalk(true);
            _events.ScheduleEvent(EVENT_GROW, Seconds(1));
        }

        void JustSummoned(Creature* summon) override
        {
            if (Creature* rajh = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_RAJH)))
                rajh->AI()->JustSummoned(summon);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GROW:
                        me->SetObjectScale(1.0f);
                        _events.ScheduleEvent(EVENT_START_MOVING, Seconds(2));
                        break;
                    case EVENT_START_MOVING:
                        DoCastSelf(SPELL_SOLAR_WINDS_PERIODIC, true);
                        _events.ScheduleEvent(EVENT_MOVE_ARROUND, 1);
                        break;
                    case EVENT_MOVE_ARROUND:
                    {
                        float o = me->GetOrientation() + frand(0.0f, float(M_PI * 2));
                        float x = me->GetPositionX() + cos(o) * 20.0f;
                        float y = me->GetPositionY() + sin(o) * 20.0f;
                        float z = me->GetPositionZ();
                        me->GetMotionMaster()->MovePoint(0, x, y, z, true);
                        _events.Repeat(Seconds(7));
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_solar_windsAI>(creature);
    }
};

class npc_orb_of_the_sun : public CreatureScript
{
public:
    npc_orb_of_the_sun() : CreatureScript("npc_orb_of_the_sun") { }

    struct npc_orb_of_the_sunAI : public ScriptedAI
    {
        npc_orb_of_the_sunAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            _events.ScheduleEvent(EVENT_GROW, Seconds(1));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GROW:
                        me->SetObjectScale(1.0f);
                        _events.ScheduleEvent(EVENT_SUMMON_BLAZING_INFERNO, Seconds(1));
                        break;
                    case EVENT_SUMMON_BLAZING_INFERNO:
                        DoCastSelf(SPELL_SUMMON_METEOR);
                        _events.ScheduleEvent(EVENT_RIDE_VEHICLE, Seconds(2));
                        break;
                    case EVENT_RIDE_VEHICLE:
                        if (Creature* inferno = me->FindNearestCreature(NPC_BLAZING_INFERNO, 100.0f, true))
                            DoCast(inferno, SPELL_RIDE_VEHICLE, true);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_orb_of_the_sunAI>(creature);
    }
};

class spell_rajh_summon_meteor : public SpellScriptLoader
{
public:
    spell_rajh_summon_meteor() : SpellScriptLoader("spell_rajh_summon_meteor") { }

    class spell_rajh_summon_meteor_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rajh_summon_meteor_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rajh_summon_meteor_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rajh_summon_meteor_SpellScript();
    }
};

class spell_rajh_summon_sun_orb : public SpellScriptLoader
{
public:
    spell_rajh_summon_sun_orb() : SpellScriptLoader("spell_rajh_summon_sun_orb") { }

    class spell_rajh_summon_sun_orb_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rajh_summon_sun_orb_SpellScript);

        void SetDestPosition(SpellEffIndex /*effIndex*/)
        {
            float x = GetExplTargetDest()->GetPositionX();
            float y = GetExplTargetDest()->GetPositionY();
            float z = 358.0276f;

            const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(x, y, z);
            GetHitDest()->Relocate(x, y, z);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(spell_rajh_summon_sun_orb_SpellScript::SetDestPosition, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_rajh_summon_sun_orb_SpellScript();
    }
};

class spell_rajh_summon_sun_orb_power_cost : public SpellScriptLoader
{
public:
    spell_rajh_summon_sun_orb_power_cost() : SpellScriptLoader("spell_rajh_summon_sun_orb_power_cost") { }

    class spell_rajh_summon_sun_orb_power_cost_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rajh_summon_sun_orb_power_cost_AuraScript);

        void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_rajh_summon_sun_orb_power_cost_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rajh_summon_sun_orb_power_cost_AuraScript();
    }
};

class achievement_sun_of_a : public AchievementCriteriaScript
{
public:
    achievement_sun_of_a() : AchievementCriteriaScript("achievement_sun_of_a") { }

    bool OnCheck(Player* /*source*/, Unit* target)
    {
        if (!target)
            return false;

        if (target->GetMap()->IsHeroic())
            return target->GetAI()->GetData(DATA_SUN_OF_A);

        return false;
    }
};

void AddSC_boss_rajh()
{
    new boss_rajh();
    new npc_solar_winds();
    new npc_orb_of_the_sun();
    new spell_rajh_summon_meteor();
    new spell_rajh_summon_sun_orb();
    new spell_rajh_summon_sun_orb_power_cost();
    new achievement_sun_of_a();
}
