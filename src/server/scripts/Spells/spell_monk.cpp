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
 * Scripts for spells with SPELLFAMILY_MONK and SPELLFAMILY_GENERIC spells used by monk players.
 * Scriptnames of files in this file should be prefixed with "spell_monk_".
 */

#include "ScriptMgr.h"
#include "DB2Stores.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum MonkSpells
{
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL         = 117952,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC        = 123333,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK       = 117962,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD    = 117953,
    SPELL_MONK_PROVOKE_SINGLE_TARGET                    = 116189,
    SPELL_MONK_PROVOKE_AOE                              = 118635,
    SPELL_MONK_SOOTHING_MIST                            = 115175,
    SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE             = 154436,
    SPELL_MONK_STAGGER_DAMAGE_AURA                      = 124255,
    SPELL_MONK_STAGGER_HEAVY                            = 124273,
    SPELL_MONK_STAGGER_LIGHT                            = 124275,
    SPELL_MONK_STAGGER_MODERATE                         = 124274,
    SPELL_MONK_SURGING_MIST_HEAL                        = 116995,
};

// 117952 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning : public AuraScript
{
    PrepareAuraScript(spell_monk_crackling_jade_lightning);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE,
            SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC
        });
    }

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE))
                caster->CastSpell(caster, SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 117959 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning_knockback_proc_aura : public AuraScript
{
    PrepareAuraScript(spell_monk_crackling_jade_lightning_knockback_proc_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK,
            SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (GetTarget()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
            return false;

        if (eventInfo.GetActor()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL, GetTarget()->GetGUID()))
            return false;

        Spell* currentChanneledSpell = GetTarget()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
        if (!currentChanneledSpell || currentChanneledSpell->GetSpellInfo()->Id != SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL)
            return false;

        return true;
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK, TRIGGERED_FULL_MASK);
        GetTarget()->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_monk_crackling_jade_lightning_knockback_proc_aura::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_knockback_proc_aura::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 115546 - Provoke
class spell_monk_provoke : public SpellScript
{
    PrepareSpellScript(spell_monk_provoke);

    static uint32 const BlackOxStatusEntry = 61146;

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!(spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT_MASK)) // ensure GetExplTargetUnit() will return something meaningful during CheckCast
            return false;
        return ValidateSpellInfo(
        {
            SPELL_MONK_PROVOKE_SINGLE_TARGET,
            SPELL_MONK_PROVOKE_AOE
        });
    }

    SpellCastResult CheckExplicitTarget()
    {
        if (GetExplTargetUnit()->GetEntry() != BlackOxStatusEntry)
        {
            SpellInfo const* singleTarget = sSpellMgr->AssertSpellInfo(SPELL_MONK_PROVOKE_SINGLE_TARGET, GetCastDifficulty());
            SpellCastResult singleTargetExplicitResult = singleTarget->CheckExplicitTarget(GetCaster(), GetExplTargetUnit());
            if (singleTargetExplicitResult != SPELL_CAST_OK)
                return singleTargetExplicitResult;
        }
        else if (GetExplTargetUnit()->GetOwnerGUID() != GetCaster()->GetGUID())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (GetHitUnit()->GetEntry() != BlackOxStatusEntry)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_PROVOKE_SINGLE_TARGET, true);
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MONK_PROVOKE_AOE, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_monk_provoke::CheckExplicitTarget);
        OnEffectHitTarget += SpellEffectFn(spell_monk_provoke::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Utility for stagger scripts
Aura* FindExistingStaggerEffect(Unit* unit)
{
    if (Aura* auraLight = unit->GetAura(SPELL_MONK_STAGGER_LIGHT))
        return auraLight;

    if (Aura* auraModerate = unit->GetAura(SPELL_MONK_STAGGER_MODERATE))
        return auraModerate;

    if (Aura* auraHeavy = unit->GetAura(SPELL_MONK_STAGGER_HEAVY))
        return auraHeavy;

    return nullptr;
}

static constexpr SpellEffIndex AuraStaggerEffectTick = EFFECT_0;
static constexpr SpellEffIndex AuraStaggerEffectTotal = EFFECT_1;

// 115069 - Stagger
class spell_monk_stagger : public AuraScript
{
    PrepareAuraScript(spell_monk_stagger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MONK_STAGGER_LIGHT, SPELL_MONK_STAGGER_MODERATE, SPELL_MONK_STAGGER_HEAVY });
    }

    void AbsorbNormal(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        Absorb(dmgInfo, 1.0f);
    }

    void AbsorbMagic(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        AuraEffect const* effect = GetEffect(EFFECT_4);
        if (!effect)
            return;

        Absorb(dmgInfo, float(effect->GetAmount()) / 100.0f);
    }

    void Absorb(DamageInfo& dmgInfo, float multiplier)
    {
        // Prevent default action (which would remove the aura)
        PreventDefaultAction();

        // make sure damage doesn't come from stagger damage spell SPELL_MONK_STAGGER_DAMAGE_AURA
        if (SpellInfo const* dmgSpellInfo = dmgInfo.GetSpellInfo())
            if (dmgSpellInfo->Id == SPELL_MONK_STAGGER_DAMAGE_AURA)
                return;

        AuraEffect const* effect = GetEffect(AuraStaggerEffectTick);
        if (!effect)
            return;

        Unit* target = GetTarget();
        float agility = target->GetStat(STAT_AGILITY);
        float base = CalculatePct(agility, float(effect->GetAmount()));
        float K = sDB2Manager.EvaluateExpectedStat(ExpectedStatType::ArmorConstant, target->getLevel(), -2, 0, Classes(target->getClass()));

        float newAmount = (base / (base + K));
        newAmount *= multiplier;

        // Absorb X percentage of the damage
        float absorbAmount = float(dmgInfo.GetDamage()) * newAmount;
        if (absorbAmount > 0)
        {
            dmgInfo.AbsorbDamage(absorbAmount);

            // Cast stagger and make it tick on each tick
            AddAndRefreshStagger(absorbAmount);
        }
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_monk_stagger::AbsorbNormal, EFFECT_1);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_monk_stagger::AbsorbMagic, EFFECT_2);
    }

private:
    void AddAndRefreshStagger(float amount)
    {
        Unit* target = GetTarget();
        if (Aura* auraStagger = FindExistingStaggerEffect(target))
        {
            AuraEffect* effStaggerRemaining = auraStagger->GetEffect(AuraStaggerEffectTotal);
            if (!effStaggerRemaining)
                return;

            float newAmount = effStaggerRemaining->GetAmount() + amount;
            uint32 spellId = GetStaggerSpellId(target, newAmount);
            if (spellId == effStaggerRemaining->GetSpellInfo()->Id)
            {
                auraStagger->RefreshDuration();
                effStaggerRemaining->ChangeAmount(newAmount, false, true /* reapply */);
            }
            else
            {
                // amount changed the stagger type so we need to change the stagger amount (e.g. from medium to light)
                GetTarget()->RemoveAura(auraStagger);
                AddNewStagger(target, spellId, newAmount);
            }
        }
        else
            AddNewStagger(target, GetStaggerSpellId(target, amount), amount);
    }

    uint32 GetStaggerSpellId(Unit* unit, float amount)
    {
        const float StaggerHeavy = 0.6f;
        const float StaggerModerate = 0.3f;

        float staggerPct = amount / float(unit->GetMaxHealth());
        return (staggerPct >= StaggerHeavy) ? SPELL_MONK_STAGGER_HEAVY :
            (staggerPct >= StaggerModerate) ? SPELL_MONK_STAGGER_MODERATE :
            SPELL_MONK_STAGGER_LIGHT;
    }

    void AddNewStagger(Unit* unit, uint32 staggerSpellId, float staggerAmount)
    {
        // We only set the total stagger amount. The amount per tick will be set by the stagger spell script
        unit->CastSpell(unit, staggerSpellId, CastSpellExtraArgs(SPELLVALUE_BASE_POINT1, staggerAmount).SetTriggerFlags(TRIGGERED_FULL_MASK));
    }
};

// 124255 - Stagger - SPELL_MONK_STAGGER_DAMAGE_AURA
class spell_monk_stagger_damage_aura : public AuraScript
{
    PrepareAuraScript(spell_monk_stagger_damage_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MONK_STAGGER_LIGHT, SPELL_MONK_STAGGER_MODERATE, SPELL_MONK_STAGGER_HEAVY });
    }

    void OnPeriodicDamage(AuraEffect const* aurEff)
    {
        // Update our light/medium/heavy stagger with the correct stagger amount left
        if (Aura* auraStagger = FindExistingStaggerEffect(GetTarget()))
        {
            if (AuraEffect* auraEff = auraStagger->GetEffect(AuraStaggerEffectTotal))
            {
                float total = float(auraEff->GetAmount());
                float tickDamage = float(aurEff->GetAmount());
                auraEff->ChangeAmount(total - tickDamage);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_stagger_damage_aura::OnPeriodicDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 124273, 124274, 124275 - Light/Moderate/Heavy Stagger - SPELL_MONK_STAGGER_LIGHT / SPELL_MONK_STAGGER_MODERATE / SPELL_MONK_STAGGER_HEAVY
class spell_monk_stagger_debuff_aura : public AuraScript
{
    PrepareAuraScript(spell_monk_stagger_debuff_aura);

    bool Load() override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_MONK_STAGGER_DAMAGE_AURA, GetCastDifficulty());
        SpellEffectInfo const* effInfo = !spellInfo ? nullptr : spellInfo->GetEffect(EFFECT_0);
        if (!effInfo)
            return false;

        _period = float(effInfo->ApplyAuraPeriod);
        return true;
    }

    void OnReapply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // Calculate damage per tick
        float total = float(aurEff->GetAmount());
        float perTick = total * _period / float(GetDuration()); // should be same as GetMaxDuration() TODO: verify

        // Set amount on effect for tooltip
        AuraEffect* effInfo = GetAura()->GetEffect(AuraStaggerEffectTick);
        if (effInfo)
            effInfo->ChangeAmount(perTick);

        // Set amount on damage aura (or cast it if needed)
        CastOrChangeTickDamage(perTick);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
    {
        if (mode != AURA_EFFECT_HANDLE_REAL)
            return;

        // Remove damage aura
        GetTarget()->RemoveAura(SPELL_MONK_STAGGER_DAMAGE_AURA);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_monk_stagger_debuff_aura::OnReapply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_monk_stagger_debuff_aura::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    float _period = 0.0f;

    void CastOrChangeTickDamage(float tickDamage)
    {
        Unit* unit = GetTarget();
        Aura* auraDamage = unit->GetAura(SPELL_MONK_STAGGER_DAMAGE_AURA);
        if (!auraDamage)
        {
            unit->CastSpell(unit, SPELL_MONK_STAGGER_DAMAGE_AURA, true);
            auraDamage = unit->GetAura(SPELL_MONK_STAGGER_DAMAGE_AURA);
        }

        if (auraDamage)
            if (AuraEffect* eff = auraDamage->GetEffect(AuraStaggerEffectTick))
                eff->ChangeAmount(tickDamage);
    }
};

void AddSC_monk_spell_scripts()
{
    RegisterAuraScript(spell_monk_crackling_jade_lightning);
    RegisterAuraScript(spell_monk_crackling_jade_lightning_knockback_proc_aura);
    RegisterSpellScript(spell_monk_provoke);
    RegisterAuraScript(spell_monk_stagger);
    RegisterAuraScript(spell_monk_stagger_damage_aura);
    RegisterAuraScript(spell_monk_stagger_debuff_aura);
}
