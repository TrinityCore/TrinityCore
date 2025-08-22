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
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "the_stonevault.h"

enum SkarmorakSpells
{
    SPELL_CRYSTALLINE_SMASH_DAMAGE              = 422233,
    SPELL_CRYSTAL_SHARDS_DUMMY                  = 422294,
    SPELL_CRYSTAL_SHARDS_1                      = 422250,
    SPELL_CRYSTAL_SHARDS_2                      = 422272,
    SPELL_CRYSTAL_SHARDS_3                      = 422273,
    SPELL_CRYSTALLINE_ERUPTION                  = 443494,
    SPELL_ENERGY_CONTROLLER                     = 439749,
    SPELL_FORTIFIED_SHELL_ENERGIZE              = 429976,
    SPELL_FORTIFIED_SHELL                       = 423200,
    SPELL_FORTIFIED_SHELL_VISUAL                = 426215,
    SPELL_FORTIFIED_SHELL_CRYSTAL_VISUAL        = 452837,
    SPELL_FORTIFIED_SHELL_INDICATOR             = 445409,
    SPELL_FORTIFIED_SHELL_SELECTOR              = 426181,
    SPELL_FORTIFIED_SHELL_PERIODIC_ABSORB_STACK = 439600,
    SPELL_FORTIFIED_SHELL_ABSORB                = 423228,
    SPELL_SHATTERED_SHELL                       = 423246,
    SPELL_UNSTABLE_CRASH                        = 423538,
    SPELL_UNSTABLE_CRASH_FRAGMENT_SELECTOR      = 443838,
    SPELL_UNSTABLE_ENERGY_AREA                  = 423572,
    SPELL_UNSTABLE_ENERGY                       = 435813,
    SPELL_UNSTABLE_FRAGMENTS                    = 423557,
    SPELL_UNSTABLE_FRAGMENT_DAMAGE              = 464980,
    SPELL_UNSTABLE_FRAGMENT_MOD_DAMAGE          = 438583,
    SPELL_VOID_DISCHARGE                        = 423324,
    SPELL_VOID_DISCHARGE_STACKS                 = 423327
};

enum SkarmorakEvents
{
    EVENT_CRYSTALLINE_SMASH   = 1,
    EVENT_UNSTABLE_CRASH,
    EVENT_CHECK_ENERGY,
    EVENT_VOID_DISCHARGE
};

enum SkarmorakTexts
{
    SAY_AGGRO           = 0,
    SAY_SLAY            = 1,
    SAY_FORTIFIED_SHELL = 2,
    SAY_VOID_DISCHARGE  = 3,
    SAY_WIPE            = 4,
    SAY_DEATH           = 5
};

enum SkarmorakActions
{
    ACTION_FORTIFIED_SHELL = 1
};

// 210156 - Skarmorak
struct boss_skarmorak : public BossAI
{
    boss_skarmorak(Creature* creature) : BossAI(creature, DATA_SKARMORAK) { }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_WIPE);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void HandleFortifiedShellEnded()
    {
        me->RemoveAurasDueToSpell(SPELL_FORTIFIED_SHELL_INDICATOR);
        me->RemoveAurasDueToSpell(SPELL_VOID_DISCHARGE);
        me->RemoveAurasDueToSpell(SPELL_VOID_DISCHARGE_STACKS);

        events.ScheduleEvent(EVENT_CRYSTALLINE_SMASH, 10s);
        events.ScheduleEvent(EVENT_UNSTABLE_CRASH, 16100ms);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_FORTIFIED_SHELL)
            return;

        DoCastSelf(SPELL_SHATTERED_SHELL, TRIGGERED_FULL_MASK);

        HandleFortifiedShellEnded();
    }

    void OnChannelFinished(SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_VOID_DISCHARGE)
            return;

        me->RemoveAurasDueToSpell(SPELL_FORTIFIED_SHELL_ABSORB);
        HandleFortifiedShellEnded();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_ENERGY_CONTROLLER);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_CRYSTALLINE_SMASH, 4600ms);
        events.ScheduleEvent(EVENT_UNSTABLE_CRASH, 10500ms);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_CRYSTALLINE_SMASH:
            {
                DoCastVictim(SPELL_CRYSTALLINE_SMASH_DAMAGE);
                events.Repeat(17s);
                break;
            }
            case EVENT_UNSTABLE_CRASH:
            {
                DoCastSelf(SPELL_UNSTABLE_CRASH);
                events.Repeat(19400ms);
                break;
            }
            case EVENT_CHECK_ENERGY:
            {
                if (me->GetPower(POWER_ENERGY) <= 0)
                {
                    Talk(SAY_FORTIFIED_SHELL);
                    DoCastSelf(SPELL_FORTIFIED_SHELL_ENERGIZE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    DoCastSelf(SPELL_FORTIFIED_SHELL, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    DoCastSelf(SPELL_FORTIFIED_SHELL_SELECTOR, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    events.CancelEvent(EVENT_CRYSTALLINE_SMASH);
                    events.CancelEvent(EVENT_UNSTABLE_CRASH);
                    events.CancelEvent(EVENT_CHECK_ENERGY);

                    events.ScheduleEvent(EVENT_VOID_DISCHARGE, 3s);
                }
                events.Repeat(5s);
                break;
            }
            case EVENT_VOID_DISCHARGE:
            {
                Talk(SAY_VOID_DISCHARGE);
                DoCastSelf(SPELL_VOID_DISCHARGE);
                break;
            }
            default:
                break;
        }
    }
};

// 423228 - Fortified Shell
class spell_skarmorak_fortified_shell_absorb : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        if (!instance)
            return;

        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        Creature* skarmorak = instance->GetCreature(DATA_SKARMORAK);
        if (!skarmorak)
            return;

        skarmorak->AI()->DoAction(ACTION_FORTIFIED_SHELL);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_skarmorak_fortified_shell_absorb::AfterRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 429976 - Fortified Shell
class spell_skarmorak_fortified_shell_energize : public AuraScript
{
    static constexpr std::array<uint8, 3> SkarmorakEnergizeCycle = { 16, 17, 17 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        uint8 cycleIdx = aurEff->GetTickNumber() % SkarmorakEnergizeCycle.size();
        GetTarget()->ModifyPower(POWER_ENERGY, SkarmorakEnergizeCycle[cycleIdx]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_skarmorak_fortified_shell_energize::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 426181 - Fortified Shell
class spell_skarmorak_fortified_shell_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FORTIFIED_SHELL_VISUAL, SPELL_FORTIFIED_SHELL_CRYSTAL_VISUAL, SPELL_FORTIFIED_SHELL_PERIODIC_ABSORB_STACK });
    }

    void HandleDummyVisual(SpellEffIndex /*effIndex*/) const
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_FORTIFIED_SHELL_VISUAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleCrystalVisual(SpellEffIndex /*effIndex*/) const
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_FORTIFIED_SHELL_CRYSTAL_VISUAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });

        GetHitUnit()->CastSpell(GetCaster(), SPELL_FORTIFIED_SHELL_PERIODIC_ABSORB_STACK, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_fortified_shell_selector::HandleDummyVisual, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_fortified_shell_selector::HandleCrystalVisual, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 439600 - Fortified Shell
class spell_skarmorak_fortified_shell_periodic_absorb : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FORTIFIED_SHELL_ABSORB });
    }

    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_FORTIFIED_SHELL_ABSORB, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_skarmorak_fortified_shell_periodic_absorb::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 422233 - Crystalline Smash
class spell_skarmorak_crystalline_smash : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTAL_SHARDS_DUMMY });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_CRYSTAL_SHARDS_DUMMY, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_crystalline_smash::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 422294 - Crystal Shards
class spell_skarmorak_crystal_shards : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTAL_SHARDS_1, SPELL_CRYSTAL_SHARDS_2, SPELL_CRYSTAL_SHARDS_3 });
    }

    void HandleShard1(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_CRYSTAL_SHARDS_1, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleShard2(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_CRYSTAL_SHARDS_2, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleShard3(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_CRYSTAL_SHARDS_3, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_crystal_shards::HandleShard1, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_crystal_shards::HandleShard2, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_crystal_shards::HandleShard3, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 423538 - Unstable Crash
class spell_skarmorak_unstable_crash : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_CRASH_FRAGMENT_SELECTOR });
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_UNSTABLE_CRASH_FRAGMENT_SELECTOR, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_skarmorak_unstable_crash::HandleAfterCast);
    }
};

// 443838 - Unstable Crash
class spell_skarmorak_unstable_crash_fragment_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_FRAGMENTS });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), SPELL_UNSTABLE_FRAGMENTS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_unstable_crash_fragment_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 423572 - Unstable Energy
class spell_skarmorak_unstable_energy_area : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_FRAGMENT_MOD_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_UNSTABLE_ENERGY, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_unstable_energy_area::HandleHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 435813 - Unstable Energy
class spell_skarmorak_unstable_energy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_FRAGMENT_MOD_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_UNSTABLE_FRAGMENT_MOD_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skarmorak_unstable_energy::HandleHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

class spell_skarmorak_unstable_energy_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_FRAGMENT_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        Unit* target = GetTarget();

        if (Unit* caster = GetCaster())
            caster->CastSpell(target, SPELL_UNSTABLE_FRAGMENT_DAMAGE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_skarmorak_unstable_energy_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 443405 - Unstable Fragments
struct at_skarmorak_unstable_fragments : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_UNSTABLE_ENERGY_AREA, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        at->Remove();
    }
};

void AddSC_boss_skarmorak()
{
    RegisterTheStonevaultCreatureAI(boss_skarmorak);

    RegisterSpellScript(spell_skarmorak_fortified_shell_absorb);
    RegisterSpellScript(spell_skarmorak_fortified_shell_energize);
    RegisterSpellScript(spell_skarmorak_fortified_shell_selector);
    RegisterSpellScript(spell_skarmorak_fortified_shell_periodic_absorb);
    RegisterSpellScript(spell_skarmorak_crystalline_smash);
    RegisterSpellScript(spell_skarmorak_crystal_shards);
    RegisterSpellScript(spell_skarmorak_unstable_crash);
    RegisterSpellScript(spell_skarmorak_unstable_crash_fragment_selector);
    RegisterSpellScript(spell_skarmorak_unstable_energy_area);
    RegisterSpellAndAuraScriptPair(spell_skarmorak_unstable_energy, spell_skarmorak_unstable_energy_aura);
    RegisterAreaTriggerAI(at_skarmorak_unstable_fragments);
}
