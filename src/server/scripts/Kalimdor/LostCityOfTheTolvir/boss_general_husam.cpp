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
#include "G3DPosition.hpp"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "lost_city_of_the_tolvir.h"

enum Spells
{
    // General Husam
    SPELL_HAMMER_FIST                       = 83654,
    SPELL_SHOCKWAVE                         = 83445,
    SPELL_SHOCKWAVE_VISUAL                  = 83130,
    SPELL_SUMMON_SHOCKWAVE_TARGET_N         = 83131,
    SPELL_SUMMON_SHOCKWAVE_TARGET_S         = 83132,
    SPELL_SUMMON_SHOCKWAVE_TARGET_E         = 83133,
    SPELL_SUMMON_SHOCKWAVE_TARGET_W         = 83134,
    SPELL_MYSTIC_TRAP                       = 83644,
    SPELL_THROW_LAND_MINES                  = 83122,
    SPELL_DETONE_TRAPS                      = 91263,
    SPELL_BAD_INTENTIONS                    = 83113,
    SPELL_HURL                              = 83236,
    SPELL_THROW_VISUAL                      = 83371,

    // Shockwave Stalker
    SPELL_SHOCKWAVE_SUMMON_EFFECT           = 83128,

    // Shockwave Visual
    SPELL_SHOCKWAVE_DAMAGE                  = 83454,

    // Tol'Vir Land Mine
    SPELL_TOLVIR_LAND_MINE_VISUAL           = 83110,
    SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER   = 83111,
    SPELL_LAND_MINE_PLAYER_SEARCH_EFFECT    = 83112,
    SPELL_LAND_MINE_PERIODIC                = 85523,
    SPELL_MYSTIC_TRAP_DAMAGE                = 83171,


    // Bad Intentions Target
    SPELL_HARD_IMPACT                       = 83339,
    SPELL_EJECT_ALL_PASSENGERS              = 50630
};

enum Events
{
    // General Husam
    EVENT_HAMMER_FIST = 1,
    EVENT_MYSTIC_TRAP,
    EVENT_BAD_INTENTIONS,
    EVENT_THROW_PLAYER,
    EVENT_SHOCKWAVE,
    EVENT_DETONATE_TRAPS,

    // Tol'Vir Land Mine
    EVENT_READY_MINE,
    EVENT_START_COUNTDOWN,
    EVENT_CLEAR_AURAS
};

enum Actions
{
    // Tol'vir Land Mine
    ACTION_INITIATE_COUNTDOWN   = 1,
    ACTION_DETONATE             = 2
};

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_SHOCKWAVE           = 2,
    SAY_ANNOUNCE_SHOCKWAVE  = 3,
    SAY_DETONATE_MINES      = 4,
    SAY_DEATH               = 5
};

enum Misc
{
    SEAT_PLAYER     = 0,
    POINT_ID_NONE   = 0
};

struct boss_general_husam : public BossAI
{
    boss_general_husam(Creature* creature) : BossAI(creature, DATA_GENERAL_HUSAM), _shockwaveStalkerCount(0) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_HAMMER_FIST, 7s, 10s);
        events.ScheduleEvent(EVENT_MYSTIC_TRAP, 7s, 10s);
        events.ScheduleEvent(EVENT_BAD_INTENTIONS, 12s, 13s);
        events.ScheduleEvent(EVENT_SHOCKWAVE, IsHeroic() ? 15s : 18s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_DETONATE_TRAPS, 22s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_SHOCKWAVE_STALKER:
            {
                summons.Summon(summon);
                _shockwaveStalkerCount++;
                float orientation = summon->GetAngle(me) + float(M_PI);
                Position dest = summon->GetPosition();
                dest.m_positionX += std::cos(orientation) * 40.f;
                dest.m_positionY += std::sin(orientation) * 40.f;

                Movement::MoveSplineInit init(summon);
                init.MoveTo(PositionToVector3(dest), true, true);
                init.SetVelocity(8.f);
                init.Launch();

                if (_shockwaveStalkerCount == 4)
                {
                    DoCastSelf(SPELL_SHOCKWAVE);
                    _shockwaveStalkerCount = 0;
                }
                break;
            }
            case NPC_TOLVIR_LAND_MINE:
                DoCast(summon, SPELL_THROW_LAND_MINES);
                summon->DespawnOrUnsummon(6s);
                break;
            default:
                summons.Summon(summon);
                break;
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (spell->Id == SPELL_DETONE_TRAPS && reason == SPELL_FINISHED_SUCCESSFUL_CAST)
            Talk(SAY_DETONATE_MINES);
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (apply)
            events.ScheduleEvent(EVENT_THROW_PLAYER, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HAMMER_FIST:
                    DoCastSelf(SPELL_HAMMER_FIST);
                    events.Repeat(21s);
                    break;
                case EVENT_MYSTIC_TRAP:
                    DoCastAOE(SPELL_MYSTIC_TRAP);
                    events.Repeat(11s, 12s);
                    break;
                case EVENT_BAD_INTENTIONS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_BAD_INTENTIONS);
                    break;
                case EVENT_SHOCKWAVE:
                    Talk(SAY_ANNOUNCE_SHOCKWAVE);
                    Talk(SAY_SHOCKWAVE);
                    DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_N);
                    DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_S);
                    DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_E);
                    DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_W);

                    events.RescheduleEvent(EVENT_MYSTIC_TRAP, 8s, 10s);
                    events.RescheduleEvent(EVENT_HAMMER_FIST, 10s, 12s);
                    events.RescheduleEvent(EVENT_BAD_INTENTIONS, 17s);
                    events.Repeat(39s);
                    break;
                case EVENT_DETONATE_TRAPS:
                    DoCastSelf(SPELL_DETONE_TRAPS);
                    events.DelayEvents(2s);
                    events.Repeat(32s);
                    break;
                case EVENT_THROW_PLAYER:
                    DoCastSelf(SPELL_HURL);
                    DoCastSelf(SPELL_THROW_VISUAL);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    uint8 _shockwaveStalkerCount;
};

struct npc_husam_tolvir_land_mine : public NullCreatureAI
{
    npc_husam_tolvir_land_mine(Creature* creature) : NullCreatureAI(creature)
    {
        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
    }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_READY_MINE, 2s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_INITIATE_COUNTDOWN:
                _events.RescheduleEvent(EVENT_START_COUNTDOWN, 1ms);
                break;
            case ACTION_DETONATE:
                _events.Reset();
                DoCastSelf(SPELL_MYSTIC_TRAP_DAMAGE);
                me->RemoveAurasDueToSpell(SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER);
                me->RemoveAurasDueToSpell(SPELL_TOLVIR_LAND_MINE_VISUAL);
                me->RemoveAurasDueToSpell(SPELL_LAND_MINE_PERIODIC);
                me->DespawnOrUnsummon(6s);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_READY_MINE:
                    DoCastSelf(SPELL_TOLVIR_LAND_MINE_VISUAL);
                    DoCastSelf(SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER);
                    _events.ScheduleEvent(EVENT_START_COUNTDOWN, 20s);
                    break;
                case EVENT_START_COUNTDOWN:
                    DoCastSelf(SPELL_LAND_MINE_PERIODIC);
                    _events.ScheduleEvent(EVENT_CLEAR_AURAS, 5s);
                    break;
                case EVENT_CLEAR_AURAS:
                    me->RemoveAurasDueToSpell(SPELL_TOLVIR_LAND_MINE_VISUAL);
                    me->RemoveAurasDueToSpell(SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER);
                    me->DespawnOrUnsummon(6s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_husam_bad_intentions_target : public NullCreatureAI
{
    npc_husam_bad_intentions_target(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            me->m_Events.AddEventAtOffset([this, passenger]()
            {
                if (passenger)
                {
                    DoCast(passenger, SPELL_HARD_IMPACT);
                    DoCastSelf(SPELL_EJECT_ALL_PASSENGERS);
                }
            }, 400ms);
        }
    }
};

struct npc_husam_shockwave_visual : public NullCreatureAI
{
    npc_husam_shockwave_visual(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        me->m_Events.AddEventAtOffset([this]() { DoCastSelf(SPELL_SHOCKWAVE_DAMAGE); }, 4s + 600ms);
        me->m_Events.AddEventAtOffset([this]() { me->RemoveAllAuras(); }, 7s);
        me->DespawnOrUnsummon(12s);
    }
};

class spell_husam_hammer_fist : public AuraScript
{
    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            if (caster->GetVictim())
                caster->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_husam_hammer_fist::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_husam_shockwave : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHOCKWAVE_VISUAL });
    }

    void EffectScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHOCKWAVE_VISUAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_husam_shockwave::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_shockwave_summon_search : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHOCKWAVE_SUMMON_EFFECT });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            GetCaster()->CastSpell(GetCaster(), SPELL_SHOCKWAVE_SUMMON_EFFECT, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_husam_shockwave_summon_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_husam_mystic_trap : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() < 3)
            return;

        Trinity::Containers::RandomResize(targets, 3);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_husam_mystic_trap::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_husam_detonate_traps : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            if (target->IsAIEnabled)
                target->AI()->DoAction(ACTION_INITIATE_COUNTDOWN);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_husam_detonate_traps::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_bad_intentions : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetHitUnit();
            target->CastStop();
            target->CastSpell(caster, GetSpellInfo()->Effects[EFFECT_1].BasePoints, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_husam_bad_intentions::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_hurl : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Vehicle* vehicle = GetCaster()->GetVehicleKit())
        {
            if (Unit* passenger = vehicle->GetPassenger(SEAT_PLAYER))
            {
                if (Creature* intentionsTarget = GetCaster()->FindNearestCreature(NPC_BAD_INTENTIONS_TARGET, 100.0f))
                    passenger->CastSpell(intentionsTarget, GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
                else
                    passenger->ExitVehicle(); // Safety case to avoid players getting stuck in Husam's hand
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_husam_hurl::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_land_mine_player_search_effect : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled)
                    creature->AI()->DoAction(ACTION_DETONATE);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_husam_land_mine_player_search_effect::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_general_husam()
{
    RegisterLostCityOfTheTolvirAI(boss_general_husam);
    RegisterLostCityOfTheTolvirAI(npc_husam_tolvir_land_mine);
    RegisterLostCityOfTheTolvirAI(npc_husam_bad_intentions_target);
    RegisterLostCityOfTheTolvirAI(npc_husam_shockwave_visual);
    RegisterSpellScript(spell_husam_hammer_fist);
    RegisterSpellScript(spell_husam_shockwave);
    RegisterSpellScript(spell_husam_shockwave_summon_search);
    RegisterSpellScript(spell_husam_mystic_trap);
    RegisterSpellScript(spell_husam_detonate_traps);
    RegisterSpellScript(spell_husam_bad_intentions);
    RegisterSpellScript(spell_husam_hurl);
    RegisterSpellScript(spell_husam_land_mine_player_search_effect);
}
