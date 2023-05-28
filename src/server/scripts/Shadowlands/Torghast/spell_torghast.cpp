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
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

// 300771 - Blade of the Lifetaker
class spell_torghast_blade_of_the_lifetaker : public AuraScript
{
    PrepareAuraScript(spell_torghast_blade_of_the_lifetaker);

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
    PrepareAuraScript(spell_torghast_touch_of_the_unseen);

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
    PrepareSpellScript(spell_torghast_yelshirs_powerglove);

    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (SpellInfo const* triggeringSpell = GetTriggeringSpell())
            if (Aura const* triggerAura = GetCaster()->GetAura(triggeringSpell->Id))
                SetEffectValue(GetEffectValue() * triggerAura->GetStackAmount());
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_torghast_yelshirs_powerglove::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 321706 - Dimensional Blade
class spell_torghast_dimensional_blade : public SpellScript
{
    PrepareSpellScript(spell_torghast_dimensional_blade);

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

void AddSC_torghast_spell_scripts()
{
    RegisterSpellScript(spell_torghast_blade_of_the_lifetaker);
    RegisterSpellScript(spell_torghast_touch_of_the_unseen);
    RegisterSpellScript(spell_torghast_yelshirs_powerglove);
    RegisterSpellScript(spell_torghast_dimensional_blade);
}
