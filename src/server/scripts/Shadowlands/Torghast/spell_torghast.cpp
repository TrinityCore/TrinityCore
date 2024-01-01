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
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

// 297721 - Subjugator's Manacles
class spell_torghast_subjugators_manacles : public AuraScript
{
    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        if (_triggeredTargets.contains(procInfo.GetProcTarget()->GetGUID()))
            return false;

        _triggeredTargets.insert(procInfo.GetProcTarget()->GetGUID());
        return true;
    }

    void ResetMarkedTargets(bool isNowInCombat)
    {
        if (!isNowInCombat)
            _triggeredTargets.clear();
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_torghast_subjugators_manacles::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        OnEnterLeaveCombat += AuraEnterLeaveCombatFn(spell_torghast_subjugators_manacles::ResetMarkedTargets);
    }

    std::unordered_set<ObjectGuid> _triggeredTargets;
};

// 300771 - Blade of the Lifetaker
class spell_torghast_blade_of_the_lifetaker : public AuraScript
{
    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        PreventDefaultAction();

        procInfo.GetActor()->CastSpell(procInfo.GetProcTarget(), aurEff->GetSpellEffectInfo().TriggerSpell, CastSpellExtraArgs(aurEff)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount()))
            .SetTriggeringSpell(procInfo.GetProcSpell()));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_torghast_blade_of_the_lifetaker::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 300796 - Touch of the Unseen
class spell_torghast_touch_of_the_unseen : public AuraScript
{
    static constexpr uint32 SPELL_DOOR_OF_SHADOWS = 300728;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DOOR_OF_SHADOWS });
    }

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->Id == SPELL_DOOR_OF_SHADOWS;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        PreventDefaultAction();

        procInfo.GetActor()->CastSpell(procInfo.GetProcTarget(), aurEff->GetSpellEffectInfo().TriggerSpell, CastSpellExtraArgs(aurEff)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount()))
            .SetTriggeringSpell(procInfo.GetProcSpell()));
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_torghast_touch_of_the_unseen::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_torghast_touch_of_the_unseen::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 305060 - Yel'Shir's Powerglove
class spell_torghast_yelshirs_powerglove : public SpellScript
{
    void CalculateDamage(Unit const* /*victim*/, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        if (SpellInfo const* triggeringSpell = GetTriggeringSpell())
            if (Aura const* triggerAura = GetCaster()->GetAura(triggeringSpell->Id))
                pctMod *= triggerAura->GetStackAmount();
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_torghast_yelshirs_powerglove::CalculateDamage);
    }
};

// 321706 - Dimensional Blade
class spell_torghast_dimensional_blade : public SpellScript
{
    static constexpr uint32 SPELL_MAGE_BLINK = 1953;
    static constexpr uint32 SPELL_MAGE_SHIMMER = 212653;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLINK, SPELL_MAGE_SHIMMER });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!targets.empty())
        {
            GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_MAGE_BLINK, DIFFICULTY_NONE)->ChargeCategoryId);
            GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_MAGE_SHIMMER, DIFFICULTY_NONE)->ChargeCategoryId);
        }

        // filter targets by entry here and not with conditions table because we need to know if any enemy was hit for charge restoration, not just mawrats
        targets.remove_if([](WorldObject const* target)
        {
            switch (target->GetEntry())
            {
                case 151353: // Mawrat
                case 179458: // Protective Mawrat
                case 154030: // Oddly Large Mawrat
                case 169871: // Hungry Mawrat
                    return false;
                default:
                    break;
            }
            return true;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_torghast_dimensional_blade::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 341324 - Uncontrolled Darkness
class spell_torghast_uncontrolled_darkness : public AuraScript
{
    void Register() override
    {
        // just a value holder, no hooks
    }

public:
    int32 KillCounter = 0;
};

// 343174 - Uncontrolled Darkness
class spell_torghast_uncontrolled_darkness_proc : public AuraScript
{
    static constexpr uint32 SPELL_UNCONTROLLED_DARKNESS = 341324;
    static constexpr uint32 SPELL_UNCONTROLLED_DARKNESS_BUFF = 341375;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_UNCONTROLLED_DARKNESS, EFFECT_1 } })
            && ValidateSpellInfo({ SPELL_UNCONTROLLED_DARKNESS_BUFF });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*procInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Aura* uncontrolledDarkness = caster->GetAura(SPELL_UNCONTROLLED_DARKNESS, caster->GetGUID());
        if (!uncontrolledDarkness)
            return;

        spell_torghast_uncontrolled_darkness* script = uncontrolledDarkness->GetScript<spell_torghast_uncontrolled_darkness>();
        if (!script)
            return;

        if (caster->HasAura(SPELL_UNCONTROLLED_DARKNESS_BUFF))
        {
            if (++script->KillCounter >= uncontrolledDarkness->GetSpellInfo()->GetEffect(EFFECT_1).CalcValue())
            {
                caster->RemoveAura(SPELL_UNCONTROLLED_DARKNESS_BUFF);
                script->KillCounter = 0;
            }
        }
        else
        {
            if (++script->KillCounter >= uncontrolledDarkness->GetSpellInfo()->GetEffect(EFFECT_0).CalcValue())
            {
                caster->CastSpell(caster, SPELL_UNCONTROLLED_DARKNESS_BUFF, true);
                script->KillCounter = 0;
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_torghast_uncontrolled_darkness_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 342632 - Malevolent Stitching
class spell_torghast_fleshcraft_shield_proc : public AuraScript
{
    static constexpr uint32 SPELL_LABEL_FLESHCRAFT_BUFF = 1103;

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_FLESHCRAFT_BUFF);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_torghast_fleshcraft_shield_proc::CheckProc);
    }
};

// 342779 - Crystallized Dreams
class spell_torghast_soulshape_proc : public AuraScript
{
    static constexpr uint32 SPELL_LABEL_SOULSHAPE = 1100;

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_SOULSHAPE);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_torghast_soulshape_proc::CheckProc);
    }
};

// 342793 - Murmuring Shawl
// 342799 - Gnarled Key
class spell_torghast_door_of_shadows_proc : public AuraScript
{
    static constexpr uint32 SPELL_LABEL_DOOR_OF_SHADOWS = 726;

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_DOOR_OF_SHADOWS);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_torghast_door_of_shadows_proc::CheckProc);
    }
};

// 348908 - Ethereal Wildseed
class spell_torghast_flicker_proc : public AuraScript
{
    static constexpr uint32 SPELL_LABEL_FLICKER = 1105;

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_FLICKER);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_torghast_flicker_proc::CheckProc);
    }
};

// 354569 - Potent Potion
class spell_torghast_potent_potion_proc : public AuraScript
{
    static constexpr uint32 SPELL_LABEL_REJUVENATING_SIPHONED_ESSENCE = 1290;

    bool CheckProc(ProcEventInfo& procInfo)
    {
        return procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_REJUVENATING_SIPHONED_ESSENCE);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_torghast_potent_potion_proc::CheckProc);
    }
};

// 354706 - Spiritual Rejuvenation Potion
class spell_torghast_potent_potion_calc : public SpellScript
{
    static constexpr uint32 SPELL_LABEL_SPIRITUAL_REJUVENATION_POTION = 354568;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_LABEL_SPIRITUAL_REJUVENATION_POTION, EFFECT_1 } });
    }

    void SetValue(SpellEffIndex effIndex)
    {
        SetEffectValue(sSpellMgr->AssertSpellInfo(SPELL_LABEL_SPIRITUAL_REJUVENATION_POTION, GetCastDifficulty())->GetEffect(effIndex)
            .CalcValue(GetCaster(), nullptr, GetHitUnit()));
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_torghast_potent_potion_calc::SetValue, EFFECT_0, SPELL_EFFECT_HEAL);
        OnEffectHitTarget += SpellEffectFn(spell_torghast_potent_potion_calc::SetValue, EFFECT_1, SPELL_EFFECT_ENERGIZE);
    }
};

// 373761 - Poisonous Spores
class spell_torghast_poisonous_spores : public AuraScript
{
    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        PreventDefaultAction();

        Spell const* procSpell = procInfo.GetProcSpell();
        procInfo.GetActor()->CastSpell(*procSpell->m_targets.GetDst(), aurEff->GetSpellEffectInfo().TriggerSpell,
            CastSpellExtraArgs(aurEff).SetTriggeringSpell(procSpell));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_torghast_poisonous_spores::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_torghast_spell_scripts()
{
    RegisterSpellScript(spell_torghast_subjugators_manacles);
    RegisterSpellScript(spell_torghast_blade_of_the_lifetaker);
    RegisterSpellScript(spell_torghast_touch_of_the_unseen);
    RegisterSpellScript(spell_torghast_yelshirs_powerglove);
    RegisterSpellScript(spell_torghast_dimensional_blade);
    RegisterSpellScript(spell_torghast_uncontrolled_darkness);
    RegisterSpellScript(spell_torghast_uncontrolled_darkness_proc);
    RegisterSpellScript(spell_torghast_fleshcraft_shield_proc);
    RegisterSpellScript(spell_torghast_soulshape_proc);
    RegisterSpellScript(spell_torghast_door_of_shadows_proc);
    RegisterSpellScript(spell_torghast_flicker_proc);
    RegisterSpellScript(spell_torghast_potent_potion_proc);
    RegisterSpellScript(spell_torghast_potent_potion_calc);
    RegisterSpellScript(spell_torghast_poisonous_spores);
}
