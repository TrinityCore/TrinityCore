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

#include "ScriptMgr.h"
#include "halls_of_origination.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Map.h"

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

    // Blazing Inferno
    SPELL_BLAZING_INFERNO       = 76195
};

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_BLESSING_OF_THE_SUN = 1,
    SAY_SLAY                = 2,
    SAY_DEATH               = 3
};

enum Events
{
    // Rajh
    EVENT_SOLAR_WINDS = 1,
    EVENT_SUMMON_SOLAR_WINDS,
    EVENT_SUMMON_SUN_ORB,
    EVENT_SUN_STRIKE,
    EVENT_INFERNO_LEAP,
    EVENT_INFERNO_LEAP_CAST,
    EVENT_MOVE_TO_MIDDLE,
    EVENT_BLESSING_OF_THE_SUN,
    EVENT_TALK_BLESSING,
    EVENT_REENGAGE,

    // Solar Winds
    EVENT_GROW,
    EVENT_START_MOVING,
    EVENT_MOVE_ARROUND,

    // Orb of the Sun
    EVENT_SUMMON_BLAZING_INFERNO,
    EVENT_RIDE_VEHICLE,
    EVENT_BLAZING_INFERNO
};

enum MovePoints
{
    POINT_NONE,
    POINT_RAJH_CENTER
};

enum AchievementData
{
    DATA_SUN_OF_A = 1
};

Position const RajhMiddlePos = { -318.5936f, 192.8621f, 343.9443f };

struct boss_rajh : public BossAI
{
    boss_rajh(Creature* creature) : BossAI(creature, DATA_RAJH)
    {
        Initialize();
    }

    void Initialize()
    {
        _energized = true;
        _achievementEnabled = true;
        _randomTimerCase = 0;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->MakeInterruptable(false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->SetReactState(REACT_AGGRESSIVE);
        _randomTimerCase = RAND(0, 1);
        events.ScheduleEvent(EVENT_SOLAR_WINDS, 5s);
        events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, _randomTimerCase == 0 ? 10s : 25s);
        events.ScheduleEvent(EVENT_SUN_STRIKE, _randomTimerCase == 0 ? 20s : 8s);
        events.ScheduleEvent(EVENT_INFERNO_LEAP, 14s);
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
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
    {
        if (spell->Id == SPELL_SUMMON_SUN_ORB || spell->Id == SPELL_INFERNO_LEAP_VEHICLE)
            me->MakeInterruptable(false);
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_SUN_OF_A)
            return _achievementEnabled;

        return 0;
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_RAJH_CENTER)
            events.ScheduleEvent(EVENT_BLESSING_OF_THE_SUN, 1ms);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_INFERNO_LEAP)
            events.ScheduleEvent(EVENT_INFERNO_LEAP_CAST, 1ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->GetPower(POWER_ENERGY) <= 10 && _energized)
        {
            me->SetReactState(REACT_PASSIVE);
            me->AttackStop();
            events.CancelEvent(EVENT_SOLAR_WINDS);
            events.CancelEvent(EVENT_SUMMON_SUN_ORB);
            events.CancelEvent(EVENT_SUN_STRIKE);
            events.CancelEvent(EVENT_INFERNO_LEAP);
            events.ScheduleEvent(EVENT_MOVE_TO_MIDDLE, Seconds(2));
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
                        me->StopMoving();
                        DoCast(target, SPELL_SOLAR_WINDS_DUMMY);
                        events.Repeat(15s, 23s);
                        events.ScheduleEvent(EVENT_SUMMON_SOLAR_WINDS, 1s);
                    }
                    break;
                case EVENT_SUMMON_SOLAR_WINDS:
                    DoCastSelf(SPELL_SOLAR_WINDS_SUMMON);
                    break;
                case EVENT_SUMMON_SUN_ORB:
                    me->StopMoving();
                    me->MakeInterruptable(true);
                    DoCastSelf(SPELL_SUMMON_SUN_ORB);
                    if (_randomTimerCase == 0)
                        events.Repeat(35s, 36s);
                    else
                        events.Repeat(31s, 37s);
                    break;
                case EVENT_SUN_STRIKE:
                    if (Unit* target = me->GetVictim())
                        me->CastSpell(target, SPELL_SUN_STRIKE, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
                    events.Repeat(_randomTimerCase == 0 ? 35s : 27s);
                    break;
                case EVENT_MOVE_TO_MIDDLE:
                    if (me->GetVehicle())
                        events.Repeat(1s);
                    else
                        me->GetMotionMaster()->MovePoint(POINT_RAJH_CENTER, RajhMiddlePos, true);
                    break;
                case EVENT_BLESSING_OF_THE_SUN:
                    DoCastSelf(SPELL_BLESSING_OF_THE_SUN);
                    events.ScheduleEvent(EVENT_TALK_BLESSING, 1s + 500ms);
                    events.ScheduleEvent(EVENT_REENGAGE, 21s);
                    me->SetFacingTo(3.124139f);
                    break;
                case EVENT_TALK_BLESSING:
                    Talk(SAY_BLESSING_OF_THE_SUN);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY_SPELL_OMNI);
                    break;
                case EVENT_REENGAGE:
                    _achievementEnabled = false;
                    _energized = true;
                    _randomTimerCase = RAND(0, 1);
                    events.ScheduleEvent(EVENT_SOLAR_WINDS, 5s);
                    events.ScheduleEvent(EVENT_SUMMON_SUN_ORB, _randomTimerCase == 0 ? 10s : 25s);
                    events.ScheduleEvent(EVENT_SUN_STRIKE, _randomTimerCase == 0 ? 20s : 8s);
                    events.ScheduleEvent(EVENT_INFERNO_LEAP, 14s);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_INFERNO_LEAP:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, SPELL_INFERNO_LEAP_DUMMY, true);
                    events.Repeat(59s, 1min);
                    break;
                case EVENT_INFERNO_LEAP_CAST:
                    me->MakeInterruptable(true);
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

struct npc_rajh_solar_winds : public ScriptedAI
{
    npc_rajh_solar_winds(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

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
                    float o = frand(0.0f, float(M_PI * 2));
                    Position pos = RajhMiddlePos;
                    pos.m_positionZ += 5.0f;
                    me->MovePositionToFirstCollision(pos, 60.0f, o);
                    me->GetMotionMaster()->MovePoint(POINT_NONE, pos, true);
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

struct npc_rajh_orb_of_the_sun : public ScriptedAI
{
    npc_rajh_orb_of_the_sun(Creature* creature) : ScriptedAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_GROW, Seconds(1));
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_RIDE_VEHICLE)
            _events.ScheduleEvent(EVENT_BLAZING_INFERNO, 500ms);
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
                    if (Creature* inferno = me->FindNearestCreature(NPC_BLAZING_INFERNO, 200.0f, true))
                        DoCast(inferno, SPELL_RIDE_VEHICLE, true);
                    break;
                case EVENT_BLAZING_INFERNO:
                    if (Creature* inferno = me->GetVehicleCreatureBase())
                        inferno->CastSpell(me, SPELL_BLAZING_INFERNO);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

class spell_rajh_summon_meteor : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_rajh_summon_meteor::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_rajh_summon_sun_orb : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 15.0f, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_rajh_summon_sun_orb::SetDest, EFFECT_0, TARGET_DEST_CASTER_FRONT_RIGHT);
    }
};

class spell_rajh_summon_sun_orb_power_cost : public AuraScript
{
    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_rajh_summon_sun_orb_power_cost::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
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
    RegisterHallsOfOriginationCreatureAI(boss_rajh);
    RegisterHallsOfOriginationCreatureAI(npc_rajh_solar_winds);
    RegisterHallsOfOriginationCreatureAI(npc_rajh_orb_of_the_sun);
    RegisterSpellScript(spell_rajh_summon_meteor);
    RegisterSpellScript(spell_rajh_summon_sun_orb);
    RegisterSpellScript(spell_rajh_summon_sun_orb_power_cost);
    new achievement_sun_of_a();
}
