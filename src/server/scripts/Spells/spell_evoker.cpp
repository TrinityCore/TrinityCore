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
    SPELL_EVOKER_ENERGIZING_FLAME          = 400006,
    SPELL_EVOKER_GLIDE_KNOCKBACK           = 358736,
    SPELL_EVOKER_HOVER                     = 358267,
    SPELL_EVOKER_LIVING_FLAME              = 361469,
    SPELL_EVOKER_LIVING_FLAME_DAMAGE       = 361500,
    SPELL_EVOKER_LIVING_FLAME_HEAL         = 361509,
    SPELL_EVOKER_PERMEATING_CHILL_TALENT   = 370897,
    SPELL_EVOKER_PYRE_DAMAGE               = 357212,
    SPELL_EVOKER_SOAR_RACIAL               = 369536
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

void AddSC_evoker_spell_scripts()
{
    RegisterSpellScript(spell_evo_azure_strike);
    RegisterSpellScript(spell_evo_charged_blast);
    RegisterSpellScript(spell_evo_glide);
    RegisterSpellScript(spell_evo_living_flame);
    RegisterSpellScript(spell_evo_permeating_chill);
    RegisterSpellScript(spell_evo_pyre);
}
