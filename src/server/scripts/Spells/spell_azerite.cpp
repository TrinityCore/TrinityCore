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
#include "AzeritePackets.h"
#include "Containers.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"

class spell_azerite_gen_aura_calc_from_2nd_effect_triggered_spell : public AuraScript
{
    PrepareAuraScript(spell_azerite_gen_aura_calc_from_2nd_effect_triggered_spell);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return spellInfo->GetEffects().size() > EFFECT_1 && ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect const* trait = caster->GetAuraEffect(GetEffectInfo(EFFECT_1).TriggerSpell, EFFECT_0))
            {
                amount = trait->GetAmount();
                canBeRecalculated = false;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_azerite_gen_aura_calc_from_2nd_effect_triggered_spell::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_RATING);
    }
};

// 270658 - Azerite Fortification
class spell_item_azerite_fortification : public AuraScript
{
    PrepareAuraScript(spell_item_azerite_fortification);

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        if (!procSpell)
            return false;

        return procSpell->GetSpellInfo()->HasAura(SPELL_AURA_MOD_STUN)
            || procSpell->GetSpellInfo()->HasAura(SPELL_AURA_MOD_ROOT)
            || procSpell->GetSpellInfo()->HasAura(SPELL_AURA_MOD_ROOT_2)
            || procSpell->GetSpellInfo()->HasEffect(SPELL_EFFECT_KNOCK_BACK);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_azerite_fortification::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

enum StrengthInNumbers
{
    SPELL_STRENGTH_IN_NUMBERS_TRAIT = 271546,
    SPELL_STRENGTH_IN_NUMBERS_BUFF = 271550
};

// 271548 - Strength in Numbers
class spell_item_strength_in_numbers : public SpellScript
{
    PrepareSpellScript(spell_item_strength_in_numbers);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STRENGTH_IN_NUMBERS_TRAIT, SPELL_STRENGTH_IN_NUMBERS_BUFF });
    }

    void TriggerHealthBuff()
    {
        if (AuraEffect const* trait = GetCaster()->GetAuraEffect(SPELL_STRENGTH_IN_NUMBERS_TRAIT, EFFECT_0, GetCaster()->GetGUID()))
            if (int64 enemies = GetUnitTargetCountForEffect(EFFECT_0))
                GetCaster()->CastSpell(GetCaster(), SPELL_STRENGTH_IN_NUMBERS_BUFF, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                    .AddSpellMod(SPELLVALUE_BASE_POINT0, trait->GetAmount())
                    .AddSpellMod(SPELLVALUE_AURA_STACK, enemies));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_item_strength_in_numbers::TriggerHealthBuff);
    }
};

enum BlessedPortents
{
    SPELL_BLESSED_PORTENTS_TRAIT = 267889,
    SPELL_BLESSED_PORTENTS_HEAL = 280052,
};

// 271843 - Blessed Portents
class spell_item_blessed_portents : public AuraScript
{
    PrepareAuraScript(spell_item_blessed_portents);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLESSED_PORTENTS_TRAIT, SPELL_BLESSED_PORTENTS_HEAL });
    }

    void CheckProc(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        if (GetTarget()->HealthBelowPctDamaged(50, dmgInfo.GetDamage()))
        {
            if (Unit* caster = GetCaster())
                if (AuraEffect const* trait = caster->GetAuraEffect(SPELL_BLESSED_PORTENTS_TRAIT, EFFECT_0, caster->GetGUID()))
                    caster->CastSpell(GetTarget(), SPELL_BLESSED_PORTENTS_HEAL, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                        .AddSpellMod(SPELLVALUE_BASE_POINT0, trait->GetAmount()));
        }
        else
            PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_item_blessed_portents::CheckProc, EFFECT_0);
    }
};

enum ConcentratedMending
{
    SPELL_CONCENTRATED_MENDING_TRAIT = 267882,
};

// 272260 - Concentrated Mending
class spell_item_concentrated_mending : public AuraScript
{
    PrepareAuraScript(spell_item_concentrated_mending);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CONCENTRATED_MENDING_TRAIT });
    }

    void RecalculateHealAmount(AuraEffect* aurEff)
    {
        if (Unit const* caster = GetCaster())
            if (AuraEffect const* trait = caster->GetAuraEffect(SPELL_CONCENTRATED_MENDING_TRAIT, EFFECT_0, caster->GetGUID()))
                aurEff->ChangeAmount(trait->GetAmount() * aurEff->GetTickNumber());
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_item_concentrated_mending::RecalculateHealAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

enum BracingChill
{
    SPELL_BRACING_CHILL_TRAIT               = 267884,
    SPELL_BRACING_CHILL                     = 272276,
    SPELL_BRACING_CHILL_HEAL                = 272428,
    SPELL_BRACING_CHILL_SEARCH_JUMP_TARGET  = 272436,
};

// 272276 - Bracing Chill
class spell_item_bracing_chill_proc : public AuraScript
{
    PrepareAuraScript(spell_item_bracing_chill_proc);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BRACING_CHILL_TRAIT, SPELL_BRACING_CHILL_HEAL, SPELL_BRACING_CHILL_SEARCH_JUMP_TARGET });
    }

    bool CheckHealCaster(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return GetCasterGUID() == eventInfo.GetActor()->GetGUID();
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
    {
        Unit* caster = procInfo.GetActor();
        if (!caster)
            return;

        if (AuraEffect const* trait = caster->GetAuraEffect(SPELL_BRACING_CHILL_TRAIT, EFFECT_0, caster->GetGUID()))
            caster->CastSpell(procInfo.GetProcTarget(), SPELL_BRACING_CHILL_HEAL,
                CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, trait->GetAmount()));

        if (GetStackAmount() > 1)
            caster->CastSpell(nullptr, SPELL_BRACING_CHILL_SEARCH_JUMP_TARGET,
                CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_AURA_STACK, GetStackAmount() - 1));

        Remove();
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_bracing_chill_proc::CheckHealCaster, EFFECT_0, SPELL_AURA_DUMMY);
        AfterEffectProc += AuraEffectProcFn(spell_item_bracing_chill_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 272436 - Bracing Chill
class spell_item_bracing_chill_search_jump_target : public SpellScript
{
    PrepareSpellScript(spell_item_bracing_chill_search_jump_target);

    void FilterTarget(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        std::list<WorldObject*> copy = targets;
        Trinity::Containers::RandomResize(copy, [&](WorldObject* target)
        {
            return target->IsUnit() && !target->ToUnit()->HasAura(SPELL_BRACING_CHILL, GetCaster()->GetGUID());
        }, 1);

        if (!copy.empty())
        {
            // found a preferred target, use that
            targets.swap(copy);
            return;
        }

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void MoveAura(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_BRACING_CHILL,
            CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_AURA_STACK, GetSpellValue()->AuraStackAmount));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_item_bracing_chill_search_jump_target::FilterTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_item_bracing_chill_search_jump_target::MoveAura, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 272837 - Trample the Weak
class spell_item_trample_the_weak : public AuraScript
{
    PrepareAuraScript(spell_item_trample_the_weak);

    bool CheckHealthPct(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActor()->GetHealthPct() > eventInfo.GetActionTarget()->GetHealthPct();
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_trample_the_weak::CheckHealthPct, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

enum OrbitalPrecision
{
    SPELL_MAGE_FROZEN_ORB   = 84714
};

// 275514 - Orbital Precision
class spell_item_orbital_precision : public AuraScript
{
    PrepareAuraScript(spell_item_orbital_precision);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FROZEN_ORB });
    }

    bool CheckFrozenOrbActive(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActor()->GetAreaTrigger(SPELL_MAGE_FROZEN_ORB) != nullptr;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_orbital_precision::CheckFrozenOrbActive, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

enum BlurOfTalons
{
    SPELL_HUNTER_COORDINATED_ASSAULT = 266779
};

// 277966 - Blur of Talons
class spell_item_blur_of_talons : public AuraScript
{
    PrepareAuraScript(spell_item_blur_of_talons);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HUNTER_COORDINATED_ASSAULT });
    }

    bool CheckCoordinatedAssaultActive(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetActor()->HasAura(SPELL_HUNTER_COORDINATED_ASSAULT, eventInfo.GetActor()->GetGUID());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_blur_of_talons::CheckCoordinatedAssaultActive, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 278519 - Divine Right
class spell_item_divine_right : public AuraScript
{
    PrepareAuraScript(spell_item_divine_right);

    bool CheckHealthPct(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget()->HasAuraState(AURA_STATE_WOUNDED_20_PERCENT, eventInfo.GetSpellInfo(), eventInfo.GetActor());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_divine_right::CheckHealthPct, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 280409 - Blood Rite
class spell_item_blood_rite : public AuraScript
{
    PrepareAuraScript(spell_item_blood_rite);

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*procInfo*/)
    {
        RefreshDuration();
    }

    void Register() override
    {
        AfterEffectProc += AuraEffectProcFn(spell_item_blood_rite::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 281843 - Tradewinds
class spell_item_tradewinds : public AuraScript
{
    PrepareAuraScript(spell_item_tradewinds);

    enum
    {
        SPELL_TRADEWINDS_ALLY_BUFF = 281844
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRADEWINDS_ALLY_BUFF });
    }

    void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (AuraEffect const* trait = GetTarget()->GetAuraEffect(GetEffectInfo(EFFECT_1).TriggerSpell, EFFECT_1))
            GetTarget()->CastSpell(nullptr, SPELL_TRADEWINDS_ALLY_BUFF,
                CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_BASE_POINT0, trait->GetAmount()));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_item_tradewinds::HandleRemove, EFFECT_0, SPELL_AURA_MOD_RATING, AURA_EFFECT_HANDLE_REAL);
    }
};

// 287379 - Bastion of Might
class spell_item_bastion_of_might : public SpellScript
{
    PrepareSpellScript(spell_item_bastion_of_might);

    enum
    {
        SPELL_WARRIOR_IGNORE_PAIN = 190456
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_IGNORE_PAIN });
    }

    void TriggerIgnorePain()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_IGNORE_PAIN, GetSpell());
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_item_bastion_of_might::TriggerIgnorePain);
    }
};

// 287650 - Echoing Blades
class spell_item_echoing_blades : public AuraScript
{
    PrepareAuraScript(spell_item_echoing_blades);

    void PrepareProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetProcSpell())
        {
            if (eventInfo.GetProcSpell()->m_castId != _lastFanOfKnives)
                GetEffect(EFFECT_0)->RecalculateAmount();

            _lastFanOfKnives = eventInfo.GetProcSpell()->m_castId;
        }
    }

    bool CheckFanOfKnivesCounter(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        return aurEff->GetAmount() > 0;
    }

    void ReduceCounter(AuraEffect* aurEff, ProcEventInfo& /*procInfo*/)
    {
        aurEff->SetAmount(aurEff->GetAmount() - 1);
    }

    void Register() override
    {
        DoPrepareProc += AuraProcFn(spell_item_echoing_blades::PrepareProc);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_item_echoing_blades::CheckFanOfKnivesCounter, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        AfterEffectProc += AuraEffectProcFn(spell_item_echoing_blades::ReduceCounter, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }

    ObjectGuid _lastFanOfKnives;
};

// 287653 - Echoing Blades
class spell_item_echoing_blades_damage : public SpellScript
{
    PrepareSpellScript(spell_item_echoing_blades_damage);

    enum
    {
        SPELL_ECHOING_BLADES_TRAIT = 287649
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ECHOING_BLADES_TRAIT })
            && sSpellMgr->AssertSpellInfo(SPELL_ECHOING_BLADES_TRAIT, DIFFICULTY_NONE)->GetEffects().size() > EFFECT_2;
    }

    void CalculateDamage(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* trait = GetCaster()->GetAuraEffect(SPELL_ECHOING_BLADES_TRAIT, EFFECT_2))
            SetHitDamage(trait->GetAmount() * 2);
    }

    void ForceCritical(Unit const* /*victim*/, float& critChance)
    {
        critChance = 100.0f;
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_item_echoing_blades_damage::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnCalcCritChance += SpellOnCalcCritChanceFn(spell_item_echoing_blades_damage::ForceCritical);
    }
};

// 277253 - Heart of Azeroth
class spell_item_heart_of_azeroth : public AuraScript
{
    PrepareAuraScript(spell_item_heart_of_azeroth);

    void SetEquippedFlag(AuraEffect const* /*effect*/, AuraEffectHandleModes /*mode*/)
    {
        SetState(true);
    }

    void ClearEquippedFlag(AuraEffect const* /*effect*/, AuraEffectHandleModes /*mode*/)
    {
        SetState(false);
    }

    void SetState(bool equipped) const
    {
        if (Player* target = GetTarget()->ToPlayer())
        {
            target->ApplyAllAzeriteEmpoweredItemMods(equipped);

            WorldPackets::Azerite::PlayerAzeriteItemEquippedStatusChanged statusChanged;
            statusChanged.IsHeartEquipped = equipped;
            target->SendDirectMessage(statusChanged.Write());
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_item_heart_of_azeroth::SetEquippedFlag, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_item_heart_of_azeroth::ClearEquippedFlag, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_azerite_item_spell_scripts()
{
    RegisterSpellScript(spell_azerite_gen_aura_calc_from_2nd_effect_triggered_spell);
    RegisterSpellScript(spell_item_azerite_fortification);
    RegisterSpellScript(spell_item_strength_in_numbers);
    RegisterSpellScript(spell_item_blessed_portents);
    RegisterSpellScript(spell_item_concentrated_mending);
    RegisterSpellScript(spell_item_bracing_chill_proc);
    RegisterSpellScript(spell_item_bracing_chill_search_jump_target);
    RegisterSpellScript(spell_item_trample_the_weak);
    RegisterSpellScript(spell_item_orbital_precision);
    RegisterSpellScript(spell_item_blur_of_talons);
    RegisterSpellScript(spell_item_divine_right);
    RegisterSpellScript(spell_item_blood_rite);
    RegisterSpellScript(spell_item_tradewinds);
    RegisterSpellScript(spell_item_bastion_of_might);
    RegisterSpellScript(spell_item_echoing_blades);
    RegisterSpellScript(spell_item_echoing_blades_damage);

    RegisterSpellScript(spell_item_heart_of_azeroth);
}
