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
 * Scripts for spells with SPELLFAMILY_EVOKER and SPELLFAMILY_GENERIC spells used by evoker players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_evo_".
 */

#include "Containers.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum EvokerSpells
{
    SPELL_EVOKER_BLAST_FURNACE                  = 375510,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_DK      = 381732,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_DH      = 381741,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_DRUID   = 381746,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_EVOKER  = 381748,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_HUNTER  = 381749,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_MAGE    = 381750,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_MONK    = 381751,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_PALADIN = 381752,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_PRIEST  = 381753,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_ROGUE   = 381754,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_SHAMAN  = 381756,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_WARLOCK = 381757,
    SPELL_EVOKER_BLESSING_OF_THE_BRONZE_WARRIOR = 381758,
    SPELL_EVOKER_ENERGIZING_FLAME               = 400006,
    SPELL_EVOKER_FIRE_BREATH_DAMAGE             = 357209,
    SPELL_EVOKER_GLIDE_KNOCKBACK                = 358736,
    SPELL_EVOKER_HOVER                          = 358267,
    SPELL_EVOKER_LIVING_FLAME                   = 361469,
    SPELL_EVOKER_LIVING_FLAME_DAMAGE            = 361500,
    SPELL_EVOKER_LIVING_FLAME_HEAL              = 361509,
    SPELL_EVOKER_PERMEATING_CHILL_TALENT        = 370897,
    SPELL_EVOKER_PYRE_DAMAGE                    = 357212,
    SPELL_EVOKER_SCOURING_FLAME                 = 378438,
    SPELL_EVOKER_SOAR_RACIAL                    = 369536
};

enum EvokerSpellLabels
{
    SPELL_LABEL_EVOKER_BLUE                 = 1465,
};

// 362969 - Azure Strike (blue)
class spell_evo_azure_strike : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetExplTargetUnit());
        Trinity::Containers::RandomResize(targets, GetEffectInfo(EFFECT_0).CalcValue(GetCaster()) - 1);
        targets.push_back(GetExplTargetUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_evo_azure_strike::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 381732 - Blessing of the Bronze (Bronze)
// 381741 - Blessing of the Bronze (Bronze)
// 381746 - Blessing of the Bronze (Bronze)
// 381748 - Blessing of the Bronze (Bronze)
// 381749 - Blessing of the Bronze (Bronze)
// 381750 - Blessing of the Bronze (Bronze)
// 381751 - Blessing of the Bronze (Bronze)
// 381752 - Blessing of the Bronze (Bronze)
// 381753 - Blessing of the Bronze (Bronze)
// 381754 - Blessing of the Bronze (Bronze)
// 381756 - Blessing of the Bronze (Bronze)
// 381757 - Blessing of the Bronze (Bronze)
// 381758 - Blessing of the Bronze (Bronze)
class spell_evo_blessing_of_the_bronze : public SpellScript
{
    void RemoveInvalidTargets(std::list<WorldObject*>& targets) const
    {
        targets.remove_if([&](WorldObject const* target)
        {
            Unit const* unitTarget = target->ToUnit();
            if (!unitTarget)
                return true;

            switch (GetSpellInfo()->Id)
            {
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_DK: return unitTarget->GetClass() != CLASS_DEATH_KNIGHT;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_DH: return unitTarget->GetClass() != CLASS_DEMON_HUNTER;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_DRUID: return unitTarget->GetClass() != CLASS_DRUID;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_EVOKER: return unitTarget->GetClass() != CLASS_EVOKER;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_HUNTER: return unitTarget->GetClass() != CLASS_HUNTER;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_MAGE: return unitTarget->GetClass() != CLASS_MAGE;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_MONK: return unitTarget->GetClass() != CLASS_MONK;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_PALADIN: return unitTarget->GetClass() != CLASS_PALADIN;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_PRIEST: return unitTarget->GetClass() != CLASS_PRIEST;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_ROGUE: return unitTarget->GetClass() != CLASS_ROGUE;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_SHAMAN: return unitTarget->GetClass() != CLASS_SHAMAN;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_WARLOCK: return unitTarget->GetClass() != CLASS_WARLOCK;
                case SPELL_EVOKER_BLESSING_OF_THE_BRONZE_WARRIOR: return unitTarget->GetClass() != CLASS_WARRIOR;
                default:
                    break;
            }
            return true;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_evo_blessing_of_the_bronze::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
    }
};

// 370455 - Charged Blast
class spell_evo_charged_blast : public AuraScript
{
    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_EVOKER_BLUE);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_evo_charged_blast::CheckProc);
    }
};

// 357208 Fire Breath (Red)
// 382266 Fire Breath (Red)
class spell_evo_fire_breath : public SpellScript
{
public:
    struct data
    {
        int32 EmpowerLevel;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVOKER_FIRE_BREATH_DAMAGE, SPELL_EVOKER_BLAST_FURNACE });
    }

    void OnComplete(int32 completedStageCount) const
    {
        int32 dotTicks = 10 - (completedStageCount - 1) * 3;
        if (AuraEffect const* blastFurnace = GetCaster()->GetAuraEffect(SPELL_EVOKER_BLAST_FURNACE, EFFECT_0))
            dotTicks += blastFurnace->GetAmount() / 2;

        GetCaster()->CastSpell(GetCaster(), SPELL_EVOKER_FIRE_BREATH_DAMAGE, CastSpellExtraArgs()
            .SetTriggeringSpell(GetSpell())
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .AddSpellMod(SPELLVALUE_DURATION_PCT, 100 * dotTicks)
            .SetCustomArg(data{ .EmpowerLevel = completedStageCount }));
    }

    void Register() override
    {
        OnEmpowerCompleted += SpellOnEmpowerStageCompletedFn(spell_evo_fire_breath::OnComplete);
    }
};

// 357209 Fire Breath (Red)
class spell_evo_fire_breath_damage : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } })
            && spellInfo->GetEffect(EFFECT_2).IsAura(SPELL_AURA_MOD_SILENCE); // validate we are removing the correct effect
    }

    void AddBonusUpfrontDamage(Unit const* victim, int32& /*damage*/, int32& flatMod, float& /*pctMod*/) const
    {
        spell_evo_fire_breath::data const* params = std::any_cast<spell_evo_fire_breath::data>(&GetSpell()->m_customArg);
        if (!params)
            return;

        // damage is done after aura is applied, grab periodic amount
        if (AuraEffect const* fireBreath = victim->GetAuraEffect(GetSpellInfo()->Id, EFFECT_1, GetCaster()->GetGUID()))
            flatMod += fireBreath->GetEstimatedAmount().value_or(fireBreath->GetAmount()) * (params->EmpowerLevel - 1) * 3;
    }

    void RemoveUnusedEffect(std::list<WorldObject*>& targets) const
    {
        targets.clear();
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_evo_fire_breath_damage::AddBonusUpfrontDamage);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_evo_fire_breath_damage::RemoveUnusedEffect, EFFECT_2, TARGET_UNIT_CONE_CASTER_TO_DEST_ENEMY);
    }
};

// 358733 - Glide (Racial)
class spell_evo_glide : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVOKER_GLIDE_KNOCKBACK, SPELL_EVOKER_HOVER, SPELL_EVOKER_SOAR_RACIAL });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();

        if (!caster->IsFalling())
            return SPELL_FAILED_NOT_ON_GROUND;

        return SPELL_CAST_OK;
    }

    void HandleCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_EVOKER_GLIDE_KNOCKBACK, true);

        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_EVOKER_HOVER, GetCastDifficulty()), 0, nullptr, false, 250ms);
        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_EVOKER_SOAR_RACIAL, GetCastDifficulty()), 0, nullptr, false, 250ms);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_evo_glide::CheckCast);
        OnCast += SpellCastFn(spell_evo_glide::HandleCast);
    }
};

// 361469 - Living Flame (Red)
class spell_evo_living_flame : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_EVOKER_LIVING_FLAME_DAMAGE, SPELL_EVOKER_LIVING_FLAME_HEAL, SPELL_EVOKER_ENERGIZING_FLAME });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();
        if (caster->IsFriendlyTo(hitUnit))
            caster->CastSpell(hitUnit, SPELL_EVOKER_LIVING_FLAME_HEAL, true);
        else
            caster->CastSpell(hitUnit, SPELL_EVOKER_LIVING_FLAME_DAMAGE, true);
    }

    void HandleLaunchTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->IsFriendlyTo(GetHitUnit()))
            return;

        if (AuraEffect* auraEffect = caster->GetAuraEffect(SPELL_EVOKER_ENERGIZING_FLAME, EFFECT_0))
        {
            int32 manaCost = GetSpell()->GetPowerTypeCostAmount(POWER_MANA).value_or(0);
            if (manaCost != 0)
                GetCaster()->ModifyPower(POWER_MANA, CalculatePct(manaCost, auraEffect->GetAmount()));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_evo_living_flame::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectLaunchTarget += SpellEffectFn(spell_evo_living_flame::HandleLaunchTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 381773 - Permeating Chill
class spell_evo_permeating_chill : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVOKER_PERMEATING_CHILL_TALENT });
    }

    bool CheckProc(ProcEventInfo& procInfo)
    {
        SpellInfo const* spellInfo = procInfo.GetSpellInfo();
        if (!spellInfo)
            return false;

        if (!spellInfo->HasLabel(SPELL_LABEL_EVOKER_BLUE))
            return false;

        if (!procInfo.GetActor()->HasAura(SPELL_EVOKER_PERMEATING_CHILL_TALENT))
            if (!spellInfo->IsAffected(SPELLFAMILY_EVOKER, { 0x40, 0, 0, 0 })) // disintegrate
                return false;

        return true;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_evo_permeating_chill::CheckProc);
    }
};

// 393568 - Pyre
class spell_evo_pyre : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_EVOKER_PYRE_DAMAGE });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), SPELL_EVOKER_PYRE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_evo_pyre::HandleDamage, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357209 Fire Breath (Red)
class spell_evo_scouring_flame : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EVOKER_SCOURING_FLAME });
    }

    void HandleScouringFlame(std::list<WorldObject*>& targets) const
    {
        if (!GetCaster()->HasAura(SPELL_EVOKER_SCOURING_FLAME))
            targets.clear();
    }

    void CalcDispelCount(SpellEffIndex /*effIndex*/)
    {
        if (spell_evo_fire_breath::data const* params = std::any_cast<spell_evo_fire_breath::data>(&GetSpell()->m_customArg))
            SetEffectValue(params->EmpowerLevel);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_evo_scouring_flame::HandleScouringFlame, EFFECT_3, TARGET_UNIT_CONE_CASTER_TO_DEST_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_evo_scouring_flame::CalcDispelCount, EFFECT_3, SPELL_EFFECT_DISPEL);
    }
};

void AddSC_evoker_spell_scripts()
{
    RegisterSpellScript(spell_evo_azure_strike);
    RegisterSpellScript(spell_evo_blessing_of_the_bronze);
    RegisterSpellScript(spell_evo_charged_blast);
    RegisterSpellScript(spell_evo_fire_breath);
    RegisterSpellScript(spell_evo_fire_breath_damage);
    RegisterSpellScript(spell_evo_glide);
    RegisterSpellScript(spell_evo_living_flame);
    RegisterSpellScript(spell_evo_permeating_chill);
    RegisterSpellScript(spell_evo_pyre);
    RegisterSpellScript(spell_evo_scouring_flame);
}
