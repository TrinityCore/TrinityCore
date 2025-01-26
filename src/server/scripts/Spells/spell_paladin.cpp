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
 * Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pal_".
 */

#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellDefines.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::Spells::Paladin
{
    enum PaladinSpells
    {
        SPELL_PAL_CENSURE                       = 31803,
        SPELL_PAL_JUDGEMENT_DAMAGE              = 54158,
        SPELL_PAL_SEAL_OF_RIGHTEOUSNESS_DAMAGE  = 25742,
        SPELL_PAL_SEAL_OF_TRUTH_DAMAGE          = 42463
    };

    // 20154 - Seal of Righteousness
    class spell_pal_seal_of_righteousness : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PAL_SEAL_OF_RIGHTEOUSNESS_DAMAGE });
        }

        bool CheckMeleeProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetActionTarget() || !eventInfo.GetDamageInfo())
                return false;

            Unit* caster = eventInfo.GetActor();
            WeaponAttackType attType = eventInfo.GetDamageInfo()->GetAttackType();

            // Damage formula according to tooltip: ${$MWS*(0.011*$AP+0.022*$SPH)
            _procBasePoints = std::round(static_cast<float>(caster->GetBaseAttackTime(attType)) / 1000.0f * (0.011f * caster->GetTotalAttackPowerValue(attType) + 0.022f * caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY, true)));

            return _procBasePoints > 0;
        }

        void HandleMeleeProc(AuraEffect* aurEff, ProcEventInfo& eventInfo) const
        {
            eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_PAL_SEAL_OF_RIGHTEOUSNESS_DAMAGE, CastSpellExtraArgs(aurEff).AddSpellBP0(_procBasePoints));
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_seal_of_righteousness::CheckMeleeProc, EFFECT_0, SPELL_AURA_DUMMY);
            AfterEffectProc += AuraEffectProcFn(spell_pal_seal_of_righteousness::HandleMeleeProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    private:
        int32 _procBasePoints = 0;
    };

    // 20271 - Judgement
    class spell_pal_judgement : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PAL_JUDGEMENT_DAMAGE });
        }

        void HandleJudgementEffect(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), getJudgementDamageSpellId(GetCaster()), CastSpellExtraArgsInit{ .TriggeringSpell = GetSpell()});
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_judgement::HandleJudgementEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

    private:
        // Some of the Seals store their triggered Judgement spell within a dummy aura effect. We will identify them with this method
        uint32 getJudgementDamageSpellId(Unit* caster)
        {
            // Some of the Seals store their triggered Judgement spell within their dummy aura effects at EffIndex EFFECT_2. Try to find them.
            for (AuraEffect const* aurEff : caster->GetAuraEffectsByType(SPELL_AURA_DUMMY))
            {
                if (aurEff->GetSpellInfo()->SpellFamilyName != SPELLFAMILY_PALADIN || aurEff->GetSpellInfo()->GetSpellSpecific() != SPELL_SPECIFIC_SEAL)
                    continue;

                // Seal of Righteousness and Seal of Truth store their Judgement damage spell in EFFECT_2
                if (aurEff->GetEffIndex() != EFFECT_2 || !aurEff->GetSpellInfo()->SpellFamilyFlags.HasFlag(0, 0x800 | 0x20000000))
                    continue;

                if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(aurEff->GetAmount(), DIFFICULTY_NONE))
                    return spellInfo->Id;
            }

            // For the other seals, we just fall back to the default damage spell
            return SPELL_PAL_JUDGEMENT_DAMAGE;
        }
    };

    // 20187 - Judgement of Righteousness
    class spell_pal_judgement_of_righteousness : public SpellScript
    {
        void CalculateDamage(SpellEffectInfo const& /*spellEffectInfo*/, Unit* /*victim*/, int32& damage, int32& /*flatMod*/, float& /*pctMod*/)
        {
            damage += GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.2f;
        }

        void Register() override
        {
            CalcDamage += SpellCalcDamageFn(spell_pal_judgement_of_righteousness::CalculateDamage);
        }
    };

    // 20164  - Seal of Justice
    class spell_pal_seal_of_justice: public AuraScript
    {
        bool Validate(SpellInfo const* spellInfo) override
        {
            return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
        }

        bool CheckMeleeProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetActionTarget() || !eventInfo.GetDamageInfo())
                return false;

            // Only single target spells are allowed to trigger the proc
            if (eventInfo.GetSpellInfo() && (eventInfo.GetSpellInfo()->IsAffectingArea() || eventInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT)))
                return false;

            Unit* caster = eventInfo.GetActor();
            WeaponAttackType attType = eventInfo.GetDamageInfo()->GetAttackType();

            // Damage formula according to tooltip: ${$MWS*(0.005*$AP+0.01*$SPH)
            _procBasePoints = std::round(static_cast<float>(caster->GetBaseAttackTime(attType)) / 1000.0f * (0.005f * caster->GetTotalAttackPowerValue(attType) + 0.01f * caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY, true)));

            return _procBasePoints > 0;
        }

        void HandleMeleeProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), GetEffectInfo(aurEff->GetEffIndex()).TriggerSpell, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_BASE_POINT1, _procBasePoints));
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_seal_of_justice::CheckMeleeProc, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_justice::HandleMeleeProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    private:
        int32 _procBasePoints = 0;
    };

    // 31801 - Seal of Truth
    class spell_pal_seal_of_truth: public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PAL_CENSURE, SPELL_PAL_SEAL_OF_TRUTH_DAMAGE });
        }

        bool CheckMeleeProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetActionTarget())
                return false;

            // Only single target spells are allowed to trigger the proc
            if (eventInfo.GetSpellInfo() && (eventInfo.GetSpellInfo()->IsAffectingArea() || eventInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT)))
                return false;

            return true;
        }

        void HandleMeleeProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor();

            // When Censure has reached its max stack amount, trigger an additional spell which will deal extra weapon damage
            if (AuraEffect const* censureEffect = eventInfo.GetActionTarget()->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PALADIN, flag128(0x20000000), caster->GetGUID()))
                if (censureEffect->GetBase()->GetStackAmount() >= censureEffect->GetBase()->CalcMaxStackAmount())
                    caster->CastSpell(eventInfo.GetActionTarget(), SPELL_PAL_SEAL_OF_TRUTH_DAMAGE, aurEff);

            caster->CastSpell(eventInfo.GetActionTarget(), SPELL_PAL_CENSURE, aurEff);
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_seal_of_truth::CheckMeleeProc, EFFECT_0, SPELL_AURA_DUMMY);
            AfterEffectProc += AuraEffectProcFn(spell_pal_seal_of_truth::HandleMeleeProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    // 31804 - Judgement of Truth
    class spell_pal_judgement_of_truth : public SpellScript
    {
        void CalculateDamage(SpellEffectInfo const& /*spellEffectInfo*/, Unit* victim, int32& /*damage*/, int32& flatMod, float& /*pctMod*/)
        {
            // Censure increases the damage of Judgement of Truth by 20% per stack
            if (AuraEffect const* censureEffect = victim->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PALADIN, flag128(0x20000000), GetCaster()->GetGUID()))
                AddPct(flatMod, 20.f * censureEffect->GetBase()->GetStackAmount());
        }

        void Register() override
        {
            CalcDamage += SpellCalcDamageFn(spell_pal_judgement_of_truth::CalculateDamage);
        }
    };
}

void AddSC_paladin_spell_scripts()
{
    using namespace Scripts::Spells::Paladin;
    RegisterSpellScript(spell_pal_judgement);
    RegisterSpellScript(spell_pal_judgement_of_righteousness);
    RegisterSpellScript(spell_pal_judgement_of_truth);
    RegisterSpellScript(spell_pal_seal_of_justice);
    RegisterSpellScript(spell_pal_seal_of_righteousness);
    RegisterSpellScript(spell_pal_seal_of_truth);
}
