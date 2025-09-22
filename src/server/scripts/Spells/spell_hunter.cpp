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

/*
 * Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_hun_".
 */

#include "ScriptMgr.h"
#include "AreaTriggerAI.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"

enum HunterSpells
{
    SPELL_HUNTER_A_MURDER_OF_CROWS_DAMAGE           = 131900,
    SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_1         = 131637,
    SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_2         = 131951,
    SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_3         = 131952,
    SPELL_HUNTER_AIMED_SHOT                         = 19434,
    SPELL_HUNTER_ASPECT_CHEETAH_SLOW                = 186258,
    SPELL_HUNTER_ASPECT_OF_THE_FOX                  = 1219162,
    SPELL_HUNTER_ASPECT_OF_THE_TURTLE_PACIFY_AURA   = 205769,
    SPELL_HUNTER_BINDING_SHOT                       = 109248,
    SPELL_HUNTER_BINDING_SHOT_IMMUNE                = 117553,
    SPELL_HUNTER_BINDING_SHOT_MARKER                = 117405,
    SPELL_HUNTER_BINDING_SHOT_STUN                  = 117526,
    SPELL_HUNTER_BINDING_SHOT_VISUAL                = 117614,
    SPELL_HUNTER_BINDING_SHOT_VISUAL_ARROW          = 118306,
    SPELL_HUNTER_CONCUSSIVE_SHOT                    = 5116,
    SPELL_HUNTER_EMERGENCY_SALVE_TALENT             = 459517,
    SPELL_HUNTER_EMERGENCY_SALVE_DISPEL             = 459521,
    SPELL_HUNTER_ENTRAPMENT_TALENT                  = 393344,
    SPELL_HUNTER_ENTRAPMENT_ROOT                    = 393456,
    SPELL_HUNTER_EXHILARATION                       = 109304,
    SPELL_HUNTER_EXHILARATION_PET                   = 128594,
    SPELL_HUNTER_EXHILARATION_R2                    = 231546,
    SPELL_HUNTER_EXPLOSIVE_SHOT_DAMAGE              = 212680,
    SPELL_HUNTER_GREVIOUS_INJURY                    = 1217789,
    SPELL_HUNTER_HIGH_EXPLOSIVE_TRAP                = 236775,
    SPELL_HUNTER_HIGH_EXPLOSIVE_TRAP_DAMAGE         = 236777,
    SPELL_HUNTER_IMPLOSIVE_TRAP                     = 462032,
    SPELL_HUNTER_IMPLOSIVE_TRAP_DAMAGE              = 462033,
    SPELL_HUNTER_INTIMIDATION                       = 19577,
    SPELL_HUNTER_INTIMIDATION_MARKSMANSHIP          = 474421,
    SPELL_HUNTER_LATENT_POISON_STACK                = 378015,
    SPELL_HUNTER_LATENT_POISON_DAMAGE               = 378016,
    SPELL_HUNTER_LATENT_POISON_INJECTORS_STACK      = 336903,
    SPELL_HUNTER_LATENT_POISON_INJECTORS_DAMAGE     = 336904,
    SPELL_HUNTER_LOCK_AND_LOAD                      = 194594,
    SPELL_HUNTER_LONE_WOLF                          = 155228,
    SPELL_HUNTER_MARKSMANSHIP_HUNTER_AURA           = 137016,
    SPELL_HUNTER_MASTER_MARKSMAN                    = 269576,
    SPELL_HUNTER_MASTERS_CALL_TRIGGERED             = 62305,
    SPELL_HUNTER_MISDIRECTION                       = 34477,
    SPELL_HUNTER_MISDIRECTION_PROC                  = 35079,
    SPELL_HUNTER_MULTI_SHOT_FOCUS                   = 213363,
    SPELL_HUNTER_PET_LAST_STAND_TRIGGERED           = 53479,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED = 54114,
    SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF    = 55711,
    SPELL_HUNTER_POSTHASTE_INCREASE_SPEED           = 118922,
    SPELL_HUNTER_POSTHASTE_TALENT                   = 109215,
    SPELL_HUNTER_PRECISE_SHOTS                      = 260242,
    SPELL_HUNTER_RAPID_FIRE                         = 257044,
    SPELL_HUNTER_RAPID_FIRE_DAMAGE                  = 257045,
    SPELL_HUNTER_RAPID_FIRE_ENERGIZE                = 263585,
    SPELL_HUNTER_REJUVENATING_WIND_HEAL             = 385540,
    SPELL_HUNTER_SCOUTS_INSTINCTS                   = 459455,
    SPELL_HUNTER_SHRAPNEL_SHOT_TALENT               = 473520,
    SPELL_HUNTER_SHRAPNEL_SHOT_DEBUFF               = 474310,
    SPELL_HUNTER_STEADY_SHOT                        = 56641,
    SPELL_HUNTER_STEADY_SHOT_FOCUS                  = 77443,
    SPELL_HUNTER_STREAMLINE_TALENT                  = 260367,
    SPELL_HUNTER_STREAMLINE_BUFF                    = 342076,
    SPELL_HUNTER_T9_4P_GREATNESS                    = 68130,
    SPELL_HUNTER_T29_2P_MARKSMANSHIP_DAMAGE         = 394371,
    SPELL_HUNTER_TAR_TRAP                           = 187699,
    SPELL_HUNTER_TAR_TRAP_AREATRIGGER               = 187700,
    SPELL_HUNTER_TAR_TRAP_SLOW                      = 135299,
    SPELL_HUNTER_WILDERNESS_MEDICINE_TALENT         = 343242,
    SPELL_HUNTER_WILDERNESS_MEDICINE_DISPEL         = 384784,
    SPELL_ROAR_OF_SACRIFICE_TRIGGERED               = 67481
};

enum MiscSpells
{
    SPELL_DRAENEI_GIFT_OF_THE_NAARU                 = 59543,
};

// 131894 - A Murder of Crows
class spell_hun_a_murder_of_crows : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_HUNTER_A_MURDER_OF_CROWS_DAMAGE,
            SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_1,
            SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_2,
            SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_3
        });
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();

        if (Unit* caster = GetCaster())
            caster->CastSpell(target, SPELL_HUNTER_A_MURDER_OF_CROWS_DAMAGE, true);

        target->CastSpell(target, SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_1, true);
        target->CastSpell(target, SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_2, true);
        target->CastSpell(target, SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_3, true);
        target->CastSpell(target, SPELL_HUNTER_A_MURDER_OF_CROWS_VISUAL_3, true); // not a mistake, it is intended to cast twice
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
            if (Unit* caster = GetCaster())
                caster->GetSpellHistory()->ResetCooldown(GetId(), true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_a_murder_of_crows::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_hun_a_murder_of_crows::RemoveEffect, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 186257 - Aspect of the Cheetah
class spell_hun_aspect_cheetah : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_HUNTER_ASPECT_CHEETAH_SLOW
        });
    }

    void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_ASPECT_CHEETAH_SLOW, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_aspect_cheetah::HandleOnRemove, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1219162 - Aspect of the Fox (attached to 186257 - Aspect of the Cheetah)
class spell_hun_aspect_of_the_fox : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_ASPECT_OF_THE_FOX })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } })
            && spellInfo->GetEffect(EFFECT_2).IsAura(SPELL_AURA_CAST_WHILE_WALKING);
    }

    bool Load() override
    {
        return !GetCaster()->HasAura(SPELL_HUNTER_ASPECT_OF_THE_FOX);
    }

    static void HandleCastWhileWalking(SpellScript const&, WorldObject*& target)
    {
        target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_hun_aspect_of_the_fox::HandleCastWhileWalking, EFFECT_2, TARGET_UNIT_CASTER);
    }
};

// 186265 - Aspect of the Turtle
class spell_hun_aspect_of_the_turtle : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_ASPECT_OF_THE_TURTLE_PACIFY_AURA });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_ASPECT_OF_THE_TURTLE_PACIFY_AURA, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HUNTER_ASPECT_OF_THE_TURTLE_PACIFY_AURA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_hun_aspect_of_the_turtle::OnApply, EFFECT_0, SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_aspect_of_the_turtle::OnRemove, EFFECT_0, SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 109248 - Binding Shot
class spell_hun_binding_shot : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_BINDING_SHOT_VISUAL_ARROW });
    }

    void HandleCast()
    {
        GetCaster()->CastSpell(GetExplTargetDest()->GetPosition(), SPELL_HUNTER_BINDING_SHOT_VISUAL_ARROW, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_hun_binding_shot::HandleCast);
    }
};

// 109248 - Binding Shot
// Id - 1524
struct at_hun_binding_shot : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
            for (AreaTrigger* other : caster->GetAreaTriggers(SPELL_HUNTER_BINDING_SHOT))
                other->SetDuration(0);
    }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            for (ObjectGuid const& guid : at->GetInsideUnits())
            {
                Unit* unit = ObjectAccessor::GetUnit(*at, guid);
                if (!unit->HasAura(SPELL_HUNTER_BINDING_SHOT_MARKER))
                    continue;

                unit->CastSpell(at->GetPosition(), SPELL_HUNTER_BINDING_SHOT_VISUAL, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            }

            task.Repeat(1s);
        });
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAttackTarget(unit) && !unit->HasAura(SPELL_HUNTER_BINDING_SHOT_IMMUNE, caster->GetGUID()))
            {
                caster->CastSpell(unit, SPELL_HUNTER_BINDING_SHOT_MARKER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                unit->CastSpell(at->GetPosition(), SPELL_HUNTER_BINDING_SHOT_VISUAL, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            }
        }
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_HUNTER_BINDING_SHOT_MARKER, at->GetCasterGuid());

        if (at->IsRemoved())
            return;

        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAttackTarget(unit) && !unit->HasAura(SPELL_HUNTER_BINDING_SHOT_IMMUNE, caster->GetGUID()))
            {
                caster->CastSpell(unit, SPELL_HUNTER_BINDING_SHOT_STUN, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                caster->CastSpell(unit, SPELL_HUNTER_BINDING_SHOT_IMMUNE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            }
        }
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 204089 - Bullseye
class spell_hun_bullseye : public AuraScript
{
    static bool CheckEffectProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        return eventInfo.GetActionTarget()->HealthBelowPct(aurEff->GetAmount());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_bullseye::CheckEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 378750 - Cobra Sting
class spell_hun_cobra_sting : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    bool RollProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*procInfo*/)
    {
        return roll_chance_i(GetEffect(EFFECT_1)->GetAmount());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_cobra_sting::RollProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 5116 - Concussive Shot (attached to 193455 - Cobra Shot and 56641 - Steady Shot)
class spell_hun_concussive_shot : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_HUNTER_CONCUSSIVE_SHOT,  })
            && ValidateSpellEffect({ { SPELL_HUNTER_STEADY_SHOT, EFFECT_2 } });
    }

    void HandleDuration(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();

        if (Aura* concussiveShot = GetHitUnit()->GetAura(SPELL_HUNTER_CONCUSSIVE_SHOT, caster->GetGUID()))
        {
            SpellInfo const* steadyShot = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_STEADY_SHOT, GetCastDifficulty());
            Milliseconds extraDuration = Seconds(steadyShot->GetEffect(EFFECT_2).CalcValue(caster) / 10);
            Milliseconds newDuration = Milliseconds(concussiveShot->GetDuration()) + extraDuration;
            concussiveShot->SetDuration(newDuration.count());
            concussiveShot->SetMaxDuration(newDuration.count());
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hun_concussive_shot::HandleDuration, EFFECT_FIRST_FOUND, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 459517 - Concussive Shot (attached to 186265 - Aspect of the Turtle and 5384 - Feign Death)
class spell_hun_emergency_salve : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_EMERGENCY_SALVE_TALENT, SPELL_HUNTER_EMERGENCY_SALVE_DISPEL });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_HUNTER_EMERGENCY_SALVE_TALENT);
    }

    void HandleAfterCast() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_EMERGENCY_SALVE_DISPEL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_hun_emergency_salve::HandleAfterCast);
    }
};

// 109304 - Exhilaration
class spell_hun_exhilaration : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_EXHILARATION_R2, SPELL_HUNTER_LONE_WOLF });
    }

    void HandleOnHit()
    {
        if (GetCaster()->HasAura(SPELL_HUNTER_EXHILARATION_R2) && !GetCaster()->HasAura(SPELL_HUNTER_LONE_WOLF))
            GetCaster()->CastSpell(nullptr, SPELL_HUNTER_EXHILARATION_PET, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_hun_exhilaration::HandleOnHit);
    }
};

// 212431 - Explosive Shot
class spell_hun_explosive_shot : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_EXPLOSIVE_SHOT_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_HUNTER_EXPLOSIVE_SHOT_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_explosive_shot::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 236775 - High Explosive Trap
// 9810 - AreatriggerId
struct areatrigger_hun_high_explosive_trap : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
            for (AreaTrigger* other : caster->GetAreaTriggers(SPELL_HUNTER_HIGH_EXPLOSIVE_TRAP))
                other->SetDuration(0);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAttackTarget(unit))
            {
                caster->CastSpell(at->GetPosition(), SPELL_HUNTER_HIGH_EXPLOSIVE_TRAP_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                at->Remove();
            }
        }
    }
};

// 212658 - Hunting Party
class spell_hun_hunting_party : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_HUNTER_EXHILARATION,
            SPELL_HUNTER_EXHILARATION_PET
        });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_EXHILARATION, -Seconds(aurEff->GetAmount()));
        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_EXHILARATION_PET, -Seconds(aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_hun_hunting_party::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 462032 - Implosive Trap
// 34378 - AreatriggerId
struct areatrigger_hun_implosive_trap : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
            for (AreaTrigger* other : caster->GetAreaTriggers(SPELL_HUNTER_IMPLOSIVE_TRAP))
                other->SetDuration(0);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAttackTarget(unit))
            {
                caster->CastSpell(at->GetPosition(), SPELL_HUNTER_IMPLOSIVE_TRAP_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                at->Remove();
            }
        }
    }
};

// 53478 - Last Stand Pet
class spell_hun_last_stand_pet : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_PET_LAST_STAND_TRIGGERED });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(caster->CountPctFromMaxHealth(30));
        caster->CastSpell(caster, SPELL_HUNTER_PET_LAST_STAND_TRIGGERED, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hun_last_stand_pet::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 378016 - Latent Poison
class spell_hun_latent_poison_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_LATENT_POISON_STACK });
    }

    void CalculateDamage()
    {
        if (Aura* stack = GetHitUnit()->GetAura(SPELL_HUNTER_LATENT_POISON_STACK, GetCaster()->GetGUID()))
        {
            SetHitDamage(GetHitDamage() * stack->GetStackAmount());
            stack->Remove();
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_hun_latent_poison_damage::CalculateDamage);
    }
};

// 19434 - Aimed Shot
// 186270 - Raptor Strike
// 217200 - Barbed Shot
// 259387 - Mongoose Bite
class spell_hun_latent_poison_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_LATENT_POISON_STACK, SPELL_HUNTER_LATENT_POISON_DAMAGE });
    }

    void TriggerDamage()
    {
        if (GetHitUnit()->HasAura(SPELL_HUNTER_LATENT_POISON_STACK, GetCaster()->GetGUID()))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_HUNTER_LATENT_POISON_DAMAGE, GetSpell());
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_hun_latent_poison_trigger::TriggerDamage);
    }
};

// 336904 - Latent Poison Injectors
class spell_hun_latent_poison_injectors_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_LATENT_POISON_INJECTORS_STACK });
    }

    void CalculateDamage()
    {
        if (Aura* stack = GetHitUnit()->GetAura(SPELL_HUNTER_LATENT_POISON_INJECTORS_STACK, GetCaster()->GetGUID()))
        {
            SetHitDamage(GetHitDamage() * stack->GetStackAmount());
            stack->Remove();
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_hun_latent_poison_injectors_damage::CalculateDamage);
    }
};

// 186270 - Raptor Strike
// 259387 - Mongoose Bite
class spell_hun_latent_poison_injectors_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_LATENT_POISON_INJECTORS_STACK, SPELL_HUNTER_LATENT_POISON_INJECTORS_DAMAGE });
    }

    void TriggerDamage()
    {
        if (GetHitUnit()->HasAura(SPELL_HUNTER_LATENT_POISON_INJECTORS_STACK, GetCaster()->GetGUID()))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_HUNTER_LATENT_POISON_INJECTORS_DAMAGE, GetSpell());
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_hun_latent_poison_injectors_trigger::TriggerDamage);
    }
};

// 194595 - Lock and Load
class spell_hun_lock_and_load : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_LOCK_AND_LOAD });
    }

    static bool CheckProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    static void HandleProc(AuraScript const&, AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        Unit* caster = eventInfo.GetActor();
        caster->CastSpell(caster, SPELL_HUNTER_LOCK_AND_LOAD, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_lock_and_load::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_hun_lock_and_load::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 1217788 - Manhunter
class spell_hun_manhunter : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_GREVIOUS_INJURY });
    }

    static bool CheckProc(AuraScript const&, ProcEventInfo const& eventInfo)
    {
        return eventInfo.GetProcTarget()->IsPlayer();
    }

    static void HandleEffectProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_HUNTER_GREVIOUS_INJURY, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_hun_manhunter::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_hun_manhunter::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 260309 - Master Marksman
class spell_hun_master_marksman : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MASTER_MARKSMAN });
    }

    static void HandleProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        uint32 ticks = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_MASTER_MARKSMAN, DIFFICULTY_NONE)->GetMaxTicks();
        if (!ticks)
            return;

        int32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()) / ticks;

        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_HUNTER_MASTER_MARKSMAN, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, damage } }
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_hun_master_marksman::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 53271 - Masters Call
class spell_hun_masters_call : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } })
            && ValidateSpellInfo({ SPELL_HUNTER_MASTERS_CALL_TRIGGERED, uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    SpellCastResult DoCheckCast()
    {
        Guardian* pet = GetCaster()->ToPlayer()->GetGuardianPet();
        ASSERT(pet); // checked in Spell::CheckCast

        if (!pet->IsPet() || !pet->IsAlive())
            return SPELL_FAILED_NO_PET;

        // Do a mini Spell::CheckCasterAuras on the pet, no other way of doing this
        SpellCastResult result = SPELL_CAST_OK;
        uint32 const unitflag = pet->m_unitData->Flags;
        if (!pet->GetCharmerGUID().IsEmpty())
            result = SPELL_FAILED_CHARMED;
        else if (unitflag & UNIT_FLAG_STUNNED)
            result = SPELL_FAILED_STUNNED;
        else if (unitflag & UNIT_FLAG_FLEEING)
            result = SPELL_FAILED_FLEEING;
        else if (unitflag & UNIT_FLAG_CONFUSED)
            result = SPELL_FAILED_CONFUSED;

        if (result != SPELL_CAST_OK)
            return result;

        Unit* target = GetExplTargetUnit();
        if (!target)
            return SPELL_FAILED_BAD_TARGETS;

        if (!pet->IsWithinLOSInMap(target))
            return SPELL_FAILED_LINE_OF_SIGHT;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->ToPlayer()->GetPet()->CastSpell(GetHitUnit(), GetEffectValue(), true);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(nullptr, SPELL_HUNTER_MASTERS_CALL_TRIGGERED, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_hun_masters_call::DoCheckCast);

        OnEffectHitTarget += SpellEffectFn(spell_hun_masters_call::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_hun_masters_call::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 34477 - Misdirection
class spell_hun_misdirection : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MISDIRECTION_PROC });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEFAULT || GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_INTERRUPT)
            return;

        if (!GetTarget()->HasAura(SPELL_HUNTER_MISDIRECTION_PROC))
            GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_HUNTER_MISDIRECTION);
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_HUNTER_MISDIRECTION_PROC, aurEff);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectProc += AuraEffectProcFn(spell_hun_misdirection::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 35079 - Misdirection (Proc)
class spell_hun_misdirection_proc : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_HUNTER_MISDIRECTION);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_hun_misdirection_proc::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 2643 - Multi-Shot
class spell_hun_multi_shot : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_MULTI_SHOT_FOCUS });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleOnHit()
    {
        // We need to check hunter's spec because it doesn't generate focus on other specs than MM
        if (GetCaster()->ToPlayer()->GetPrimarySpecialization() == ChrSpecialization::HunterMarksmanship)
            GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_MULTI_SHOT_FOCUS, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_hun_multi_shot::HandleOnHit);
    }
};

// 459783 - Penetrating Shots
class spell_hun_penetrating_shots : public AuraScript
{
    void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool const& /*canBeRecalculated*/) const
    {
        if (AuraEffect const* amountHolder = GetEffect(EFFECT_1))
        {
            float critChanceDone = GetUnitOwner()->GetUnitCriticalChanceDone(BASE_ATTACK);
            amount = CalculatePct(critChanceDone, amountHolder->GetAmount());
        }
    }

    void UpdatePeriodic(AuraEffect const* aurEff) const
    {
        if (AuraEffect* bonus = GetEffect(EFFECT_0))
            bonus->RecalculateAmount(aurEff);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hun_penetrating_shots::CalcAmount, EFFECT_0, SPELL_AURA_MOD_CRIT_DAMAGE_BONUS);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_penetrating_shots::UpdatePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 55709 - Pet Heart of the Phoenix
class spell_hun_pet_heart_of_the_phoenix : public SpellScript
{
    bool Load() override
    {
        if (!GetCaster()->IsPet())
            return false;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* owner = caster->GetOwner())
        {
            if (!caster->HasAura(SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(100);
                owner->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, args);
                caster->CastSpell(caster, SPELL_HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hun_pet_heart_of_the_phoenix::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 781 - Disengage
class spell_hun_posthaste : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_POSTHASTE_TALENT, SPELL_HUNTER_POSTHASTE_INCREASE_SPEED });
    }

    void HandleAfterCast()
    {
        if (GetCaster()->HasAura(SPELL_HUNTER_POSTHASTE_TALENT))
        {
            GetCaster()->RemoveMovementImpairingAuras(true);
            GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_POSTHASTE_INCREASE_SPEED, GetSpell());
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_hun_posthaste::HandleAfterCast);
    }
};

// 260240 - Precise Shots
class spell_hun_precise_shots : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_PRECISE_SHOTS });
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_HUNTER_PRECISE_SHOTS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = eventInfo.GetProcSpell()
        });
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_hun_precise_shots::HandleProc);
    }
};

// 257044 - Rapid Fire
class spell_hun_rapid_fire : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_RAPID_FIRE_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_HUNTER_RAPID_FIRE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_rapid_fire::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 257045 - Rapid Fire Damage
class spell_hun_rapid_fire_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_RAPID_FIRE_ENERGIZE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_HUNTER_RAPID_FIRE_ENERGIZE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hun_rapid_fire_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 385539 - Rejuvenating Wind
class spell_hun_rejuvenating_wind : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_REJUVENATING_WIND_HEAL })
            && sSpellMgr->AssertSpellInfo(SPELL_HUNTER_REJUVENATING_WIND_HEAL, DIFFICULTY_NONE)->GetMaxTicks() > 0;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& /*procEvent*/)
    {
        PreventDefaultAction();

        Unit* caster = GetTarget();

        uint32 ticks = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_REJUVENATING_WIND_HEAL, DIFFICULTY_NONE)->GetMaxTicks();
        int32 heal = CalculatePct(caster->GetMaxHealth(), aurEff->GetAmount()) / ticks;

        caster->CastSpell(caster, SPELL_HUNTER_REJUVENATING_WIND_HEAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, heal } }
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_hun_rejuvenating_wind::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 53480 - Roar of Sacrifice
class spell_hun_roar_of_sacrifice : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROAR_OF_SACRIFICE_TRIGGERED });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !(damageInfo->GetSchoolMask() & aurEff->GetMiscValue()))
            return false;

        if (!GetCaster())
            return false;

        return true;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
        eventInfo.GetActor()->CastSpell(GetCaster(), SPELL_ROAR_OF_SACRIFICE_TRIGGERED, args);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_roar_of_sacrifice::CheckProc, EFFECT_1, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_hun_roar_of_sacrifice::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 37506 - Scatter Shot
class spell_hun_scatter_shot : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Player* caster = GetCaster()->ToPlayer();
        // break Auto Shot and autohit
        caster->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        caster->AttackStop();
        caster->SendAttackSwingCancelAttack();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hun_scatter_shot::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 459455 - Scout's Instincts (attached to 186257 - Aspect of the Cheetah)
class spell_hun_scouts_instincts : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_SCOUTS_INSTINCTS })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && spellInfo->GetEffect(EFFECT_1).IsAura(SPELL_AURA_MOD_MINIMUM_SPEED);
    }

    bool Load() override
    {
        return !GetCaster()->HasAura(SPELL_HUNTER_SCOUTS_INSTINCTS);
    }

    static void HandleMinSpeed(SpellScript const&, WorldObject*& target)
    {
        target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_hun_scouts_instincts::HandleMinSpeed, EFFECT_1, TARGET_UNIT_CASTER);
    }
};

// 459533 - Scrappy
class spell_hun_scrappy : public AuraScript
{
    static constexpr std::array<uint32, 3> AffectedSpellIds = { SPELL_HUNTER_BINDING_SHOT, SPELL_HUNTER_INTIMIDATION, SPELL_HUNTER_INTIMIDATION_MARKSMANSHIP };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(AffectedSpellIds);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/) const
    {
        for (uint32 spellId : AffectedSpellIds)
            GetTarget()->GetSpellHistory()->ModifyCooldown(spellId, -Milliseconds(aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_hun_scrappy::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 473520 - Shrapnel Shot
class spell_hun_shrapnel_shot : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_LOCK_AND_LOAD });
    }

    void HandleProc(ProcEventInfo const& /*eventInfo*/) const
    {
        if (!roll_chance_i(GetEffect(EFFECT_0)->GetAmount()))
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_LOCK_AND_LOAD, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_hun_shrapnel_shot::HandleProc);
    }
};

// 56641 - Steady Shot
class spell_hun_steady_shot : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_STEADY_SHOT_FOCUS, SPELL_HUNTER_AIMED_SHOT, SPELL_HUNTER_MARKSMANSHIP_HUNTER_AURA });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleOnHit() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_STEADY_SHOT_FOCUS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });

        if (GetCaster()->HasAura(SPELL_HUNTER_MARKSMANSHIP_HUNTER_AURA))
            GetCaster()->GetSpellHistory()->ModifyCooldown(SPELL_HUNTER_AIMED_SHOT, Milliseconds(-GetEffectInfo(EFFECT_1).CalcValue()));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_hun_steady_shot::HandleOnHit);
    }
};

// 260367 - Streamline (attached to 257044 - Rapid Fire)
class spell_hun_streamline : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_STREAMLINE_TALENT, SPELL_HUNTER_STREAMLINE_BUFF });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_HUNTER_STREAMLINE_TALENT);
    }

    void HandleAfterCast() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_HUNTER_STREAMLINE_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_hun_streamline::HandleAfterCast);
    }
};

// 391559 - Surging Shots
class spell_hun_surging_shots : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_RAPID_FIRE });
    }

    void HandleProc(ProcEventInfo const& /*eventInfo*/) const
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_HUNTER_RAPID_FIRE, true);
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_hun_surging_shots::HandleProc);
    }
};

// 1515 - Tame Beast
class spell_hun_tame_beast : public SpellScript
{
    static constexpr uint32 CallPetSpellIds[MAX_ACTIVE_PETS] =
    {
        883,
        83242,
        83243,
        83244,
        83245,
    };

    SpellCastResult CheckCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return SPELL_FAILED_DONT_REPORT;

        if (!GetExplTargetUnit())
            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

        if (Creature* target = GetExplTargetUnit()->ToCreature())
        {
            if (target->GetLevelForTarget(caster) > caster->GetLevel())
                return SPELL_FAILED_HIGHLEVEL;

            // use SMSG_PET_TAME_FAILURE?
            if (!target->GetCreatureTemplate()->IsTameable(caster->CanTameExoticPets(), target->GetCreatureDifficulty()))
                return SPELL_FAILED_BAD_TARGETS;

            if (PetStable const* petStable = caster->GetPetStable())
            {
                if (petStable->CurrentPetIndex)
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                auto freeSlotItr = std::find_if(petStable->ActivePets.begin(), petStable->ActivePets.end(), [](Optional<PetStable::PetInfo> const& petInfo)
                {
                    return !petInfo.has_value();
                });

                if (freeSlotItr == petStable->ActivePets.end())
                {
                    caster->SendTameFailure(PetTameResult::TooMany);
                    return SPELL_FAILED_DONT_REPORT;
                }

                // Check for known Call Pet X spells
                std::size_t freeSlotIndex = std::distance(petStable->ActivePets.begin(), freeSlotItr);
                if (!caster->HasSpell(CallPetSpellIds[freeSlotIndex]))
                {
                    caster->SendTameFailure(PetTameResult::TooMany);
                    return SPELL_FAILED_DONT_REPORT;
                }
            }

            if (!caster->GetCharmedGUID().IsEmpty())
                return SPELL_FAILED_ALREADY_HAVE_CHARM;

            if (!target->GetOwnerGUID().IsEmpty())
            {
                caster->SendTameFailure(PetTameResult::CreatureAlreadyOwned);
                return SPELL_FAILED_DONT_REPORT;
            }
        }
        else
            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_hun_tame_beast::CheckCast);
    }
};

// 187700 - Tar Trap
// 4436 - AreatriggerId
struct areatrigger_hun_tar_trap : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->HasAura(SPELL_HUNTER_ENTRAPMENT_TALENT))
                caster->CastSpell(at->GetPosition(), SPELL_HUNTER_ENTRAPMENT_ROOT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_HUNTER_TAR_TRAP_SLOW, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_HUNTER_TAR_TRAP_SLOW, at->GetCasterGuid());
    }
};

// 187699 - Tar Trap
// 4435 - AreatriggerId
struct areatrigger_hun_tar_trap_activate : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
            for (AreaTrigger* other : caster->GetAreaTriggers(SPELL_HUNTER_TAR_TRAP))
                other->SetDuration(0);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (caster->IsValidAttackTarget(unit))
            {
                caster->CastSpell(at->GetPosition(), SPELL_HUNTER_TAR_TRAP_AREATRIGGER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                at->Remove();
            }
        }
    }
};

// 67151 - Item - Hunter T9 4P Bonus (Steady Shot)
class spell_hun_t9_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_T9_4P_GREATNESS });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetActor()->GetTypeId() == TYPEID_PLAYER && eventInfo.GetActor()->ToPlayer()->GetPet())
            return true;
        return false;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActor();

        caster->CastSpell(caster->ToPlayer()->GetPet(), SPELL_HUNTER_T9_4P_GREATNESS, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_hun_t9_4p_bonus::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_hun_t9_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 394366 - Find The Mark
class spell_hun_t29_2p_marksmanship_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_HUNTER_T29_2P_MARKSMANSHIP_DAMAGE, EFFECT_0 } })
            && sSpellMgr->AssertSpellInfo(SPELL_HUNTER_T29_2P_MARKSMANSHIP_DAMAGE, DIFFICULTY_NONE)->GetMaxTicks();
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        uint32 ticks = sSpellMgr->AssertSpellInfo(SPELL_HUNTER_T29_2P_MARKSMANSHIP_DAMAGE, DIFFICULTY_NONE)->GetMaxTicks();
        uint32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetOriginalDamage(), aurEff->GetAmount()) / ticks;

        caster->CastSpell(eventInfo.GetActionTarget(), SPELL_HUNTER_T29_2P_MARKSMANSHIP_DAMAGE, CastSpellExtraArgs(aurEff)
            .SetTriggeringSpell(eventInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, damage));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_hun_t29_2p_marksmanship_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// Called by 136 - Mend Pet
class spell_hun_wilderness_medicine : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_WILDERNESS_MEDICINE_TALENT, SPELL_HUNTER_WILDERNESS_MEDICINE_DISPEL });
    }

    bool Load() override
    {
        Unit const* caster = GetCaster();
        if (!caster)
            return false;

        AuraEffect const* wildernessMedicine = GetCaster()->GetAuraEffect(SPELL_HUNTER_WILDERNESS_MEDICINE_TALENT, EFFECT_1);
        if (!wildernessMedicine)
            return false;

        _dispelChance = wildernessMedicine->GetAmount();
        return true;
    }

    void OnPeriodic(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
            if (roll_chance_i(_dispelChance))
                caster->CastSpell(GetTarget(), SPELL_HUNTER_WILDERNESS_MEDICINE_DISPEL, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                    .TriggeringAura = aurEff
                });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_wilderness_medicine::OnPeriodic, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
    }

    int32 _dispelChance = 0;
};

void AddSC_hunter_spell_scripts()
{
    RegisterSpellScript(spell_hun_a_murder_of_crows);
    RegisterSpellScript(spell_hun_aspect_cheetah);
    RegisterSpellScript(spell_hun_aspect_of_the_fox);
    RegisterSpellScript(spell_hun_aspect_of_the_turtle);
    RegisterSpellScript(spell_hun_binding_shot);
    RegisterAreaTriggerAI(at_hun_binding_shot);
    RegisterSpellScript(spell_hun_bullseye);
    RegisterSpellScript(spell_hun_cobra_sting);
    RegisterSpellScript(spell_hun_concussive_shot);
    RegisterSpellScript(spell_hun_emergency_salve);
    RegisterSpellScript(spell_hun_exhilaration);
    RegisterSpellScript(spell_hun_explosive_shot);
    RegisterAreaTriggerAI(areatrigger_hun_high_explosive_trap);
    RegisterSpellScript(spell_hun_hunting_party);
    RegisterAreaTriggerAI(areatrigger_hun_implosive_trap);
    RegisterSpellScript(spell_hun_last_stand_pet);
    RegisterSpellScript(spell_hun_latent_poison_damage);
    RegisterSpellScript(spell_hun_latent_poison_trigger);
    RegisterSpellScript(spell_hun_latent_poison_injectors_damage);
    RegisterSpellScript(spell_hun_latent_poison_injectors_trigger);
    RegisterSpellScript(spell_hun_lock_and_load);
    RegisterSpellScript(spell_hun_manhunter);
    RegisterSpellScript(spell_hun_master_marksman);
    RegisterSpellScript(spell_hun_masters_call);
    RegisterSpellScript(spell_hun_misdirection);
    RegisterSpellScript(spell_hun_misdirection_proc);
    RegisterSpellScript(spell_hun_multi_shot);
    RegisterSpellScript(spell_hun_penetrating_shots);
    RegisterSpellScript(spell_hun_pet_heart_of_the_phoenix);
    RegisterSpellScript(spell_hun_posthaste);
    RegisterSpellScript(spell_hun_precise_shots);
    RegisterSpellScript(spell_hun_rapid_fire);
    RegisterSpellScript(spell_hun_rapid_fire_damage);
    RegisterSpellScript(spell_hun_rejuvenating_wind);
    RegisterSpellScript(spell_hun_roar_of_sacrifice);
    RegisterSpellScript(spell_hun_scatter_shot);
    RegisterSpellScript(spell_hun_scouts_instincts);
    RegisterSpellScript(spell_hun_scrappy);
    RegisterSpellScript(spell_hun_shrapnel_shot);
    RegisterSpellScript(spell_hun_steady_shot);
    RegisterSpellScript(spell_hun_streamline);
    RegisterSpellScript(spell_hun_surging_shots);
    RegisterSpellScript(spell_hun_tame_beast);
    RegisterAreaTriggerAI(areatrigger_hun_tar_trap);
    RegisterAreaTriggerAI(areatrigger_hun_tar_trap_activate);
    RegisterSpellScript(spell_hun_t9_4p_bonus);
    RegisterSpellScript(spell_hun_t29_2p_marksmanship_bonus);
    RegisterSpellScript(spell_hun_wilderness_medicine);
}
