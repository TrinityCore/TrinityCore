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
#include "Containers.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "MoveSplineInit.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum HusamSpells
{
    // General Husam
    SPELL_HAMMER_FIST                               = 83654,
    SPELL_SHOCKWAVE                                 = 83445,
    SPELL_SHOCKWAVE_VISUAL                          = 83130,
    SPELL_SUMMON_SHOCKWAVE_TARGET_N                 = 83131,
    SPELL_SUMMON_SHOCKWAVE_TARGET_S                 = 83132,
    SPELL_SUMMON_SHOCKWAVE_TARGET_E                 = 83133,
    SPELL_SUMMON_SHOCKWAVE_TARGET_W                 = 83134,
    SPELL_MYSTIC_TRAP                               = 83644,
    SPELL_THROW_LAND_MINES                          = 83122,
    SPELL_DETONATE_TRAPS                            = 91263,
    SPELL_BAD_INTENTIONS                            = 83113,
    SPELL_HURL                                      = 83236,
    SPELL_THROW_VISUAL                              = 83371,

    // Shockwave Stalker
    SPELL_SHOCKWAVE_SUMMON_EFFECT                   = 83128,
    SPELL_SHOCKWAVE_VISUAL_PERIODIC_SUMMON_TRIGGER  = 83129,

    // Shockwave Visual
    SPELL_SHOCKWAVE_DAMAGE                          = 83454,

    // Tol'Vir Land Mine
    SPELL_TOLVIR_LAND_MINE_VISUAL                   = 83110,
    SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER           = 83111,
    SPELL_LAND_MINE_PLAYER_SEARCH_EFFECT            = 83112,
    SPELL_LAND_MINE_PERIODIC                        = 85523,
    SPELL_MYSTIC_TRAP_DAMAGE                        = 83171,

    // Bad Intentions Target
    SPELL_HARD_IMPACT                               = 83339,
    SPELL_EJECT_ALL_PASSENGERS                      = 50630
};

enum HusamEvents
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

enum HusamActions
{
    // General Husam
    ACTION_SAY_DETONATE_TRAPS   = 0,

    // Tol'vir Land Mine
    ACTION_INITIATE_COUNTDOWN   = 0,
    ACTION_DETONATE             = 1
};

enum HusamTexts
{
    // General Husam
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_SHOCKWAVE           = 2,
    SAY_ANNOUNCE_SHOCKWAVE  = 3,
    SAY_DETONATE_MINES      = 4,
    SAY_DEATH               = 5
};

enum HusamMisc
{
    SEAT_PLAYER = 0
};

struct boss_general_husam : public BossAI
{
    boss_general_husam(Creature* creature) : BossAI(creature, BOSS_GENERAL_HUSAM), _shockwaveStalkerCount(0) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_HAMMER_FIST, 7s, 10s);
        events.ScheduleEvent(EVENT_MYSTIC_TRAP, 7s, 10s);
        events.ScheduleEvent(EVENT_BAD_INTENTIONS, 12s, 13s);
        events.ScheduleEvent(EVENT_SHOCKWAVE, IsHeroic() ? 15s : 18s);
        if (IsHeroic() || IsTimewalking())
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
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SHOCKWAVE_STALKER:
            {
                ++_shockwaveStalkerCount;
                float orientation = summon->GetAbsoluteAngle(me) + float(M_PI);
                Position dest = summon->GetPosition();
                dest.m_positionX += std::cos(orientation) * 40.f;
                dest.m_positionY += std::sin(orientation) * 40.f;

                std::function<void(Movement::MoveSplineInit&)> initializer = [dest](Movement::MoveSplineInit& init)
                {
                    init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), false);
                    init.SetVelocity(8.f);
                };
                summon->GetMotionMaster()->LaunchMoveSpline(std::move(initializer));
                summon->CastSpell(nullptr, SPELL_SHOCKWAVE_VISUAL_PERIODIC_SUMMON_TRIGGER);

                if (_shockwaveStalkerCount == 4)
                {
                    DoCastSelf(SPELL_SHOCKWAVE);
                    _shockwaveStalkerCount = 0;
                }
                break;
            }
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        if (apply)
            events.ScheduleEvent(EVENT_THROW_PLAYER, 1s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SAY_DETONATE_TRAPS)
            Talk(SAY_DETONATE_MINES);
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
                    DoCastAOE(SPELL_MYSTIC_TRAP, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 3));
                    events.Repeat(11s, 12s);
                    break;
                case EVENT_BAD_INTENTIONS:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
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
                    DoCastSelf(SPELL_DETONATE_TRAPS);
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
    }

private:
    uint8 _shockwaveStalkerCount;
};

struct npc_husam_tolvir_land_mine : public NullCreatureAI
{
    npc_husam_tolvir_land_mine(Creature* creature) : NullCreatureAI(creature), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        if (!_instance)
            return;

        switch (me->GetEntry())
        {
            case NPC_TOLVIR_LAND_MINE_TARGET:
                if (Creature* husam = _instance->GetCreature(BOSS_GENERAL_HUSAM))
                    husam->CastSpell(me, SPELL_THROW_LAND_MINES);
                me->DespawnOrUnsummon(6s);
                break;
            case NPC_TOLVIR_LAND_MINE_VEHICLE:
                if (Creature* husam = _instance->GetCreature(BOSS_GENERAL_HUSAM))
                {
                    if (CreatureAI* ai = husam->AI())
                    {
                        ai->JustSummoned(me);
                        if (Creature* landMine = DoSummon(NPC_TOLVIR_LAND_MINE_CASTER, me->GetPosition(), 0s, TEMPSUMMON_MANUAL_DESPAWN))
                            ai->JustSummoned(landMine);
                    }
                }
                break;
            case NPC_TOLVIR_LAND_MINE_CASTER:
                if (me->IsSummon())
                    if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
                        me->EnterVehicle(summoner);
                _events.ScheduleEvent(EVENT_READY_MINE, 2s);
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool apply) override
    {
        // If our casting land mine has despawned, we also despawn alongside it.
        if (me->GetEntry() == NPC_TOLVIR_LAND_MINE_VEHICLE && !apply)
            me->DespawnOrUnsummon();
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
    InstanceScript* _instance;
};

struct npc_husam_bad_intentions_target : public NullCreatureAI
{
    npc_husam_bad_intentions_target(Creature* creature) : NullCreatureAI(creature) { }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (apply)
        {
            me->m_Events.AddEventAtOffset([&, passenger]()
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
        me->m_Events.AddEventAtOffset([&]() { DoCastSelf(SPELL_SHOCKWAVE_DAMAGE); }, 4s + 600ms);
        me->m_Events.AddEventAtOffset([&]() { me->RemoveAllAuras(); }, 7s);
        me->DespawnOrUnsummon(12s);
    }
};

class spell_husam_hammer_fist : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->GetEffect(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_husam_hammer_fist::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
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
        OnEffectHitTarget += SpellEffectFn(spell_husam_shockwave::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_husam_shockwave_summon_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_husam_detonate_traps : public SpellScript
{
    void HandlePostCastText()
    {
        if (Creature* caster = GetCaster()->ToCreature())
            if (CreatureAI* ai = caster->AI())
                ai->DoAction(ACTION_SAY_DETONATE_TRAPS);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            if (CreatureAI* ai = target->AI())
                ai->DoAction(ACTION_INITIATE_COUNTDOWN);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_husam_detonate_traps::HandlePostCastText);
        OnEffectHitTarget += SpellEffectFn(spell_husam_detonate_traps::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_bad_intentions : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } }) && ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_1).BasePoints) });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetHitUnit();
            target->CastStop();
            target->CastSpell(caster, static_cast<uint32>(GetSpellInfo()->GetEffect(EFFECT_1).BasePoints), true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_husam_bad_intentions::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_hurl : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).BasePoints) });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Vehicle* vehicle = GetCaster()->GetVehicleKit())
        {
            if (Unit* passenger = vehicle->GetPassenger(SEAT_PLAYER))
            {
                if (Creature* intentionsTarget = GetCaster()->FindNearestCreature(NPC_BAD_INTENTIONS_TARGET, 100.0f))
                    passenger->CastSpell(intentionsTarget, static_cast<uint32>(GetSpellInfo()->GetEffect(EFFECT_0).BasePoints), true);
                else
                    passenger->ExitVehicle(); // Safety case to avoid players getting stuck in Husam's hand
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_husam_hurl::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_husam_land_mine_player_search_effect : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* creature = caster->ToCreature())
                if (creature->IsAIEnabled())
                    creature->AI()->DoAction(ACTION_DETONATE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_husam_land_mine_player_search_effect::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
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
    RegisterSpellScript(spell_husam_detonate_traps);
    RegisterSpellScript(spell_husam_bad_intentions);
    RegisterSpellScript(spell_husam_hurl);
    RegisterSpellScript(spell_husam_land_mine_player_search_effect);
}
