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
    SPELL_EVOKER_SOAR_RACIAL               = 369536
};

// 358733 - Glide (Racial)
class spell_evo_glide : public SpellScript
{
    PrepareSpellScript(spell_evo_glide);

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
    PrepareSpellScript(spell_evo_living_flame);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_EVOKER_LIVING_FLAME_DAMAGE, SPELL_EVOKER_LIVING_FLAME_HEAL });
    }

    void HandleTarget(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->IsFriendlyTo(GetHitUnit()))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_EVOKER_LIVING_FLAME_HEAL, true);
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_EVOKER_LIVING_FLAME_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_evo_living_flame::HandleTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 361500 - Living Flame (damage)
class spell_evo_living_flame_damage : public SpellScript
{
    PrepareSpellScript(spell_evo_living_flame_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_EVOKER_ENERGIZING_FLAME, SPELL_EVOKER_LIVING_FLAME });
    }

    void HandleManaRestored(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect* auraEffect = GetCaster()->GetAuraEffect(SPELL_EVOKER_ENERGIZING_FLAME, EFFECT_0))
        {
            SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_EVOKER_LIVING_FLAME, GetCastDifficulty());

            Optional<SpellPowerCost> cost = spellInfo->CalcPowerCost(POWER_MANA, false, GetCaster(), GetSpellInfo()->GetSchoolMask(), nullptr);
            if (!cost)
                return;

            int32 manaRestored = CalculatePct(cost->Amount, auraEffect->GetAmount());
            GetCaster()->ModifyPower(POWER_MANA, manaRestored);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_evo_living_flame_damage::HandleManaRestored, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_evoker_spell_scripts()
{
    RegisterSpellScript(spell_evo_glide);
    RegisterSpellScript(spell_evo_living_flame);
    RegisterSpellScript(spell_evo_living_flame_damage);
}
