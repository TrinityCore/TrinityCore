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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellDefines.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum DeathKnightSpells
{
    SPELL_DK_DARK_SIMULACRUM_BUFF               = 77616,
    SPELL_DK_DARK_SIMULACRUM_SPELLPOWER_BUFF    = 94984,
    SPELL_DK_ENERGIZE_BLOOD_RUNE                = 81166,
    SPELL_DK_ENERGIZE_FROST_RUNE                = 81168,
    SPELL_DK_ENERGIZE_UNHOLY_RUNE               = 81169,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633
};

// 77606 - Dark Simulacrum
class spell_dk_dark_simulacrum : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DARK_SIMULACRUM_BUFF, SPELL_DK_DARK_SIMULACRUM_SPELLPOWER_BUFF });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        if (!procSpell)
            return false;

        if (!GetTarget()->IsPlayer())
            return procSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR9_ALLOW_DARK_SIMULACRUM);

        if (!procSpell->HasPowerTypeCost(POWER_MANA))
            return false;

        // filter out spells not castable by mind controlled players (teleports, summons, item creations (healthstones))
        if (procSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR1_NO_AUTOCAST_AI))
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_DK_DARK_SIMULACRUM_BUFF, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringSpell(eventInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, eventInfo.GetSpellInfo()->Id));

        caster->CastSpell(caster, SPELL_DK_DARK_SIMULACRUM_SPELLPOWER_BUFF, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringSpell(eventInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, GetTarget()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC))
            .AddSpellMod(SPELLVALUE_BASE_POINT1, GetTarget()->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC)));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dk_dark_simulacrum::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dk_dark_simulacrum::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77616 - Dark Simulacrum
class spell_dk_dark_simulacrum_buff : public AuraScript
{
    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        return uint32(aurEff->GetAmount()) == eventInfo.GetSpellInfo()->Id;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dk_dark_simulacrum_buff::CheckProc, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED);
    }
};

// 81229 - Runic Empowerment
class spell_dk_runic_empowerment : public AuraScript
{
    bool Load() override
    {
        if (!GetCaster()->IsPlayer() || GetCaster()->ToPlayer()->GetClass() != CLASS_DEATH_KNIGHT)
            return false;

        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_ENERGIZE_BLOOD_RUNE, SPELL_DK_ENERGIZE_UNHOLY_RUNE, SPELL_DK_ENERGIZE_FROST_RUNE });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/) const
    {
        std::vector<uint32> energizeSpells;
        Player* player = GetTarget()->ToPlayer();

        for (RuneType runeType : { RuneType::Blood, RuneType::Unholy, RuneType::Frost })
        {
            if (player->HasFullyDepletedRune(runeType))
            {
                switch (runeType)
                {
                    case RuneType::Blood:
                        energizeSpells.push_back(SPELL_DK_ENERGIZE_BLOOD_RUNE);
                        break;
                    case RuneType::Frost:
                        energizeSpells.push_back(SPELL_DK_ENERGIZE_FROST_RUNE);
                        break;
                    case RuneType::Unholy:
                        energizeSpells.push_back(SPELL_DK_ENERGIZE_UNHOLY_RUNE);
                        break;
                    default:
                        break;
                }
            }
        }

        if (energizeSpells.empty())
            return;

        uint32 spellId = Trinity::Containers::SelectRandomContainerElement(energizeSpells);
        player->CastSpell(nullptr, spellId, CastSpellExtraArgs(aurEff));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_runic_empowerment::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 47541 - Death Coil
class spell_dk_death_coil : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_DAMAGE, SPELL_DK_DEATH_COIL_HEAL });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();
        if (!target)
            return SPELL_FAILED_BAD_TARGETS;

        if (caster->IsValidAttackTarget(target, sSpellMgr->AssertSpellInfo(SPELL_DK_DEATH_COIL_DAMAGE, DIFFICULTY_NONE)))
        {
            if (!caster->isInFront(target))
                return SPELL_FAILED_UNIT_NOT_INFRONT;

            return SPELL_CAST_OK;
        }

        if (caster->IsValidAssistTarget(target, sSpellMgr->AssertSpellInfo(SPELL_DK_DEATH_COIL_HEAL, DIFFICULTY_NONE)))
        {
            if (target->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                return SPELL_FAILED_BAD_TARGETS;

            _healTarget = true;

            return SPELL_CAST_OK;
        }

        return SPELL_FAILED_BAD_TARGETS;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        // According to tooltip: ($m1+0.23*$AP)
        int32 damage = GetEffectValue() + 0.23f * GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK);
        if (_healTarget)
            damage *= 3.5f;

        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (_healTarget)
        {
            caster->CastSpell(target, SPELL_DK_DEATH_COIL_HEAL, CastSpellExtraArgsInit{
                .TriggeringSpell = GetSpell(),
                .SpellValueOverrides = { {SPELLVALUE_BASE_POINT0, damage} },
            });
        }
        else
        {
            caster->CastSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, CastSpellExtraArgsInit{
                .TriggeringSpell = GetSpell(),
                .SpellValueOverrides = { {SPELLVALUE_BASE_POINT0, damage} },
            });
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_coil::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    bool _healTarget = false;
};

// 45477 - Icy Touch
class spell_dk_icy_touch : public SpellScript
{
    void CalculateDamage(SpellEffectInfo const& /*spellEffectInfo*/, Unit* /*victim*/, int32& damage, int32& /*flatMod*/, float& /*pctMod*/)
    {
        damage += GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.2f;
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_dk_icy_touch::CalculateDamage);
    }
};

// 55095 - Frost Fever
class spell_dk_frost_fever : public AuraScript
{
    // According to tooltip: ($m1*1.15+$AP*0.055*1.15)
    void CalculateDamage(AuraEffect const* /*aurEff*/, Unit* /*victim*/, int32& damage, int32& /*flatMod*/, float& /*pctMod*/)
    {
        damage = damage * 1.15f + GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.055f * 1.15f;
    }

    void Register() override
    {
        DoEffectCalcDamageAndHealing += AuraEffectCalcDamageFn(spell_dk_frost_fever::CalculateDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 55078 - Blood Plague
class spell_dk_blood_plague: public AuraScript
{
    // According to tooltip: ($m1*1.15+$AP*0.055*1.15)
    void CalculateDamage(AuraEffect const* /*aurEff*/, Unit* /*victim*/, int32& damage, int32& /*flatMod*/, float& /*pctMod*/)
    {
        damage = damage * 1.15f + GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.055f * 1.15f;
    }

    void Register() override
    {
        DoEffectCalcDamageAndHealing += AuraEffectCalcDamageFn(spell_dk_blood_plague::CalculateDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_deathknight_spell_scripts()
{
    RegisterSpellScript(spell_dk_blood_plague);
    RegisterSpellScript(spell_dk_dark_simulacrum);
    RegisterSpellScript(spell_dk_dark_simulacrum_buff);
    RegisterSpellScript(spell_dk_death_coil);
    RegisterSpellScript(spell_dk_frost_fever);
    RegisterSpellScript(spell_dk_icy_touch);
    RegisterSpellScript(spell_dk_runic_empowerment);
}
