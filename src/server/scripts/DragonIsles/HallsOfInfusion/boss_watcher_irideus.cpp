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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "halls_of_infusion.h"

namespace Scripts::DragonIsles::HallsOfInfusion::WatcherIrideus
{
namespace Spells
{
    static constexpr uint32 PowerOverload           = 389179;
    static constexpr uint32 PowerFieldAreaTrigger   = 389180;
    static constexpr uint32 PowerFieldDamage        = 389181;
    static constexpr uint32 TitanicFist             = 384524;
    static constexpr uint32 StaticSurge             = 384014;
    static constexpr uint32 ReactiveSparkPlayers    = 383955;
    static constexpr uint32 ReactiveSparkRandom     = 383952;
    static constexpr uint32 SparkVolleyMissile      = 383917;
    static constexpr uint32 SparkVolley             = 384351;
    static constexpr uint32 AblativeBarrier         = 383840;
    static constexpr uint32 SiphonPower             = 389056;
    static constexpr uint32 SiphonPowerDamageMythic = 389490;
    static constexpr uint32 SiphonPowerDamage       = 389486;
}

namespace Texts
{
    static constexpr uint8 Aggro                = 0;
    static constexpr uint8 PowerOverload        = 1;
    static constexpr uint8 PowerOverloadWarning = 2;
    static constexpr uint8 Barrier              = 3;
    static constexpr uint8 BarrierWarning       = 4;
    static constexpr uint8 SiphonPower          = 5;
    static constexpr uint8 BarrierRemoved       = 6;
    static constexpr uint8 Wipe                 = 7;
    static constexpr uint8 Slay                 = 8;
    static constexpr uint8 Death                = 9;
}

namespace Events
{
    static constexpr uint8 PowerOverload = 1;
    static constexpr uint8 TitanicFist   = 2;
    static constexpr uint8 StaticSurge   = 3;
    static constexpr uint8 SparkVolley   = 4;
    static constexpr uint8 Barrier       = 5;
    static constexpr uint8 SiphonPower   = 6;
}

namespace Phases
{
    static constexpr uint8 PhaseCombat = 1;
}

namespace Misc
{
    static constexpr uint8 SummonGroupDevices = 0;
    static constexpr uint32 NpcDevice = 196712;
}

namespace Positions
{
    static constexpr Position AblativeBarrier = { 0.598958f, -208.403f, -35.54027f };
    static constexpr uint8 PointBarrier = 0;
}

// 189719 - Watcher Irideus
struct boss_watcher_irideus : public BossAI
{
    boss_watcher_irideus(Creature* creature) : BossAI(creature, DATA_WATCHER_IRIDEUS), _healthTriggered(false) { }

    void DespawnDevices() const
    {
        std::list<Creature*> nullificationDevices;
        GetCreatureListWithEntryInGrid(nullificationDevices, me, Misc::NpcDevice, 100.0f);

        for (Creature* nullificationDevice : nullificationDevices)
            nullificationDevice->DespawnOrUnsummon();
    }

    void JustAppeared() override
    {
        me->SetHealth(me->CountPctFromMaxHealth(30));
        me->SetPower(me->GetPowerType(), 0);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(Texts::Death);
        _JustDied();
        me->RemoveAllAreaTriggers();
        DespawnDevices();
    }

    void Reset() override
    {
        _Reset();
        _healthTriggered = false;
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_healthTriggered && me->HealthBelowPctDamaged(15, damage))
        {
            _healthTriggered = true;
            events.CancelEventGroup(Phases::PhaseCombat);
            me->SetReactState(REACT_PASSIVE);
            me->InterruptNonMeleeSpells(false);
            me->AttackStop();
            Talk(Texts::Barrier);
            me->GetMotionMaster()->MovePoint(Positions::PointBarrier, Positions::AblativeBarrier);
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == Positions::PointBarrier)
        {
            me->SummonCreatureGroup(Misc::SummonGroupDevices);
            me->SetFacingTo(0.017453f);
            events.ScheduleEvent(Events::Barrier, 2s);
        }
    }

    void OnAuraRemoved(AuraApplication const* aurApp) override
    {
        if (aurApp->GetBase()->GetId() != Spells::AblativeBarrier)
            return;

        if (aurApp->GetRemoveMode() != AURA_REMOVE_BY_DEFAULT)
            return;

        if (IsMythic() || IsMythicPlus())
        {
            for (uint8 i = 0; i < 60; ++i)
                DoCast(Spells::ReactiveSparkRandom);
        }

        Talk(Texts::BarrierRemoved);
        me->SetReactState(REACT_AGGRESSIVE);

        events.Reset();
        events.ScheduleEvent(Events::TitanicFist, 6100ms, Phases::PhaseCombat);
        events.ScheduleEvent(Events::StaticSurge, 10600ms, Phases::PhaseCombat);
        events.ScheduleEvent(Events::PowerOverload, 25500ms, Phases::PhaseCombat);
        events.ScheduleEvent(Events::SparkVolley, 29200ms, Phases::PhaseCombat);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(Texts::Wipe);
        _EnterEvadeMode();
        _DespawnAtEvade();
        me->RemoveAllAreaTriggers();
        DespawnDevices();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(Texts::Slay);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(Texts::Aggro);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(Events::TitanicFist, 6100ms, Phases::PhaseCombat);
        events.ScheduleEvent(Events::StaticSurge, 10600ms, Phases::PhaseCombat);
        events.ScheduleEvent(Events::PowerOverload, 25500ms, Phases::PhaseCombat);
        events.ScheduleEvent(Events::SparkVolley, 29200ms, Phases::PhaseCombat);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::PowerOverload)
        {
            Talk(Texts::PowerOverload);
            Talk(Texts::PowerOverloadWarning, target);
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::AblativeBarrier)
            Talk(Texts::BarrierWarning);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == Spells::SiphonPower)
            Talk(Texts::SiphonPower);
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
                case Events::PowerOverload:
                {
                    DoCastSelf(Spells::PowerOverload);
                    events.Repeat(27700s);
                    break;
                }
                case Events::TitanicFist:
                {
                    DoCastVictim(Spells::TitanicFist);
                    events.Repeat(17s);
                    break;
                }
                case Events::StaticSurge:
                {
                    DoCastSelf(Spells::StaticSurge);
                    events.Repeat(27900ms);
                    break;
                }
                case Events::SparkVolley:
                {
                    DoCastSelf(Spells::SparkVolley);
                    events.Repeat(31500ms);
                    break;
                }
                case Events::Barrier:
                {
                    DoCastSelf(Spells::AblativeBarrier, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_AURA_STACK, 3));
                    events.ScheduleEvent(Events::SiphonPower, 1100ms);
                    break;
                }
                case Events::SiphonPower:
                {
                    DoCastSelf(Spells::SiphonPower);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    bool _healthTriggered;
};

// 389179 - Power Overload
class spell_watcher_irideus_power_overload : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::PowerFieldAreaTrigger });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget()->GetPosition(), Spells::PowerFieldAreaTrigger, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_watcher_irideus_power_overload::OnRemove, EFFECT_2, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 383955 - Reactive Spark
class spell_watcher_irideus_reactive_spark_players : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SparkVolleyMissile });
    }

    void HandleOnHit() const
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), Spells::SparkVolleyMissile, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_watcher_irideus_reactive_spark_players::HandleOnHit);
    }
};

// 383952 - Reactive Spark
class spell_watcher_irideus_reactive_spark_random : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SparkVolleyMissile });
    }

    void HandleOnHit() const
    {
        GetCaster()->CastSpell(*GetHitDest(), Spells::SparkVolleyMissile, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_watcher_irideus_reactive_spark_random::HandleOnHit);
    }
};

// 389056 - Siphon Power
class spell_watcher_irideus_siphon_power : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SiphonPowerDamage, Spells::SiphonPowerDamageMythic });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/) const
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetMap()->IsMythic() || caster->GetMap()->IsMythicPlus())
                caster->CastSpell(caster, Spells::SiphonPowerDamageMythic, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            else
                caster->CastSpell(caster, Spells::SiphonPowerDamage, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_watcher_irideus_siphon_power::PeriodicTick, EFFECT_0, SPELL_AURA_OBS_MOD_POWER);
    }
};

// 389446 - Nullifying Pulse
class spell_watcher_irideus_nullifying_pulse : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::AblativeBarrier });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        if (Aura* barrier = GetHitUnit()->GetAura(Spells::AblativeBarrier))
            barrier->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_watcher_irideus_nullifying_pulse::HandleHit, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 384351 - Spark Volley
class spell_watcher_irideus_spark_volley : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::ReactiveSparkPlayers });
    }

    static void CalcPeriodic(AuraScript const&, AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = 500;
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, Spells::ReactiveSparkPlayers, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_watcher_irideus_spark_volley::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_watcher_irideus_spark_volley::PeriodicTick, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 389180 - Power Field
struct at_watcher_irideus_power_field : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    static constexpr float startScale = 1.0f;
    static constexpr float baseScale = 16.0f;
    static constexpr uint32 defaultTimeToTargetScale = 4000;
    static constexpr uint32 resizeTime = 1000;
    static constexpr uint32 intervalCheck = 250;

    float  _pctPerStack  = 0.0f;
    float  _currentScale = baseScale;
    uint32 _checkTimer   = 0;

    uint32 GetCasterStacks() const
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return 0;

        Aura const* aura = caster->GetAura(Spells::SiphonPowerDamageMythic);
        return aura ? aura->GetStackAmount() : 0;
    }

    float CalcScale(uint32 stacks) const
    {
        return baseScale * (1.0f + _pctPerStack * stacks);
    }

    void OnInitialize() override
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(Spells::SiphonPowerDamageMythic, DIFFICULTY_NONE);
        int32 value = spellInfo->GetEffect(EFFECT_1).CalcValue(at->GetCaster());
        _pctPerStack = value / 100.0f;

        _currentScale = CalcScale(GetCasterStacks());

        std::array<DBCPosition2D, 2> points =
        { {
            { 0.0f, startScale },
            { 1.0f, _currentScale }
        } };

        at->SetTimeToTargetScale(defaultTimeToTargetScale);
        at->SetOverrideScaleCurve(points, 2);
    }

    void OnUpdate(uint32 diff) override
    {
        if (at->GetTimeSinceCreated() < defaultTimeToTargetScale)
            return;

        if (_checkTimer > diff)
        {
            _checkTimer -= diff;
            return;
        }
        _checkTimer = intervalCheck;

        UpdateRadiusByStacks();
    }

    void UpdateRadiusByStacks()
    {
        uint32 stacks = GetCasterStacks();
        float targetScale = CalcScale(stacks);
        if (targetScale == _currentScale)
            return;

        std::array<DBCPosition2D, 2> points =
        { {
            { 0.0f, _currentScale },
            { 1.0f, targetScale }
        } };

        at->SetTimeToTargetScale(resizeTime);
        at->SetOverrideScaleCurve(points, 2);

        _currentScale = targetScale;
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, Spells::PowerFieldDamage, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(Spells::PowerFieldDamage);
    }
};
}

void AddSC_boss_watcher_irideus()
{
    using namespace Scripts::DragonIsles::HallsOfInfusion::WatcherIrideus;

    RegisterHallsOfInfusionCreatureAI(boss_watcher_irideus);

    RegisterSpellScript(spell_watcher_irideus_power_overload);
    RegisterSpellScript(spell_watcher_irideus_reactive_spark_players);
    RegisterSpellScript(spell_watcher_irideus_reactive_spark_random);
    RegisterSpellScript(spell_watcher_irideus_siphon_power);
    RegisterSpellScript(spell_watcher_irideus_nullifying_pulse);
    RegisterSpellScript(spell_watcher_irideus_spark_volley);

    RegisterAreaTriggerAI(at_watcher_irideus_power_field);
}
