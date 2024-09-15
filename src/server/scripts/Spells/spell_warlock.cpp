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
 * Scripts for spells with SPELLFAMILY_WARLOCK and SPELLFAMILY_GENERIC spells used by warlock players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warl_".
 */

#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "Containers.h"
#include "Creature.h"
#include "GameObject.h"
#include "GridNotifiers.h"
#include "ObjectAccessor.h"
#include "Pet.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum WarlockSpells
{
    SPELL_WARLOCK_ABSOLUTE_CORRUPTION               = 196103,
    SPELL_WARLOCK_AGONY                             = 980,
    SPELL_WARLOCK_BACKDRAFT                         = 196406,
    SPELL_WARLOCK_BACKDRAFT_PROC                    = 117828,
    SPELL_WARLOCK_CONFLAGRATE_DEBUFF                = 265931,
    SPELL_WARLOCK_CONFLAGRATE_ENERGIZE              = 245330,
    SPELL_WARLOCK_CORRUPTION_DAMAGE                 = 146739,
    SPELL_WARLOCK_CREATE_HEALTHSTONE                = 23517,
    SPELL_WARLOCK_CURSE_OF_EXHAUSTION               = 334275,
    SPELL_WARLOCK_DEATHS_EMBRACE                    = 453189,
    SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST         = 62388,
    SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON             = 48018,
    SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT           = 48020,
    SPELL_WARLOCK_DEVOUR_MAGIC_HEAL                 = 19658,
    SPELL_WARLOCK_DOOM_ENERGIZE                     = 193318,
    SPELL_WARLOCK_DRAIN_SOUL_ENERGIZE               = 205292,
    SPELL_WARLOCK_FLAMESHADOW                       = 37379,
    SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING           = 56249,
    SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP                = 56226,
    SPELL_WARLOCK_GLYPH_OF_SUCCUBUS                 = 56250,
    SPELL_WARLOCK_IMMOLATE_PERIODIC                 = 157736,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1    = 60955,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2    = 60956,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R1         = 18703,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R2         = 18704,
    SPELL_WARLOCK_INCUBUS_PACT                      = 365355,
    SPELL_WARLOCK_PERPETUAL_UNSTABILITY_DAMAGE      = 459461,
    SPELL_WARLOCK_PERPETUAL_UNSTABILITY_TALENT      = 459376,
    SPELL_WARLOCK_PYROGENICS_DEBUFF                 = 387096,
    SPELL_WARLOCK_PYROGENICS_TALENT                 = 387095,
    SPELL_WARLOCK_RAIN_OF_FIRE                      = 5740,
    SPELL_WARLOCK_RAIN_OF_FIRE_DAMAGE               = 42223,
    SPELL_WARLOCK_ROARING_BLAZE                     = 205184,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE         = 27285,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC        = 32865,
    SPELL_WARLOCK_SHADOW_BOLT_ENERGIZE              = 194192,
    SPELL_WARLOCK_SHADOWFLAME                       = 37378,
    SPELL_WARLOCK_SIPHON_LIFE_HEAL                  = 453000,
    SPELL_WARLOCK_SOUL_SWAP_CD_MARKER               = 94229,
    SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER              = 92795,
    SPELL_WARLOCK_SOUL_SWAP_MOD_COST                = 92794,
    SPELL_WARLOCK_SOUL_SWAP_OVERRIDE                = 86211,
    SPELL_WARLOCK_SOULSHATTER_EFFECT                = 32835,
    SPELL_WARLOCK_STRENGTHEN_PACT_INCUBUS           = 366325,
    SPELL_WARLOCK_STRENGTHEN_PACT_SUCCUBUS          = 366323,
    SPELL_WARLOCK_SUCCUBUS_PACT                     = 365360,
    SPELL_WARLOCK_SUMMON_INCUBUS                    = 365349,
    SPELL_WARLOCK_SUMMON_SUCCUBUS                   = 712,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE        = 196364,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_ENERGIZE      = 31117,
    SPELL_WARLOCK_VILE_TAINT_DAMAGE                 = 386931,
    SPELL_WARLOCK_VOLATILE_AGONY_DAMAGE             = 453035,
    SPELL_WARLOCK_VOLATILE_AGONY_TALENT             = 453034
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409
};

// 146739 - Corruption
// 445474 - Wither
class spell_warl_absolute_corruption : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARLOCK_ABSOLUTE_CORRUPTION, EFFECT_0 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARLOCK_ABSOLUTE_CORRUPTION);
    }

    void HandleApply(SpellEffIndex /*effIndex*/) const
    {
        if (Aura const* absoluteCorruption = GetCaster()->GetAura(SPELL_WARLOCK_ABSOLUTE_CORRUPTION))
        {
            Milliseconds duration = GetHitUnit()->IsPvP()
                ? Seconds(absoluteCorruption->GetSpellInfo()->GetEffect(EFFECT_0).CalcValue())
                : Milliseconds(-1);

            GetHitAura()->SetMaxDuration(duration.count());
            GetHitAura()->SetDuration(duration.count());
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_absolute_corruption::HandleApply, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// Called by 17962 - Conflagrate
class spell_warl_backdraft : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_WARLOCK_BACKDRAFT, SPELL_WARLOCK_BACKDRAFT_PROC });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARLOCK_BACKDRAFT);
    }

    void HandleAfterCast() const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_WARLOCK_BACKDRAFT_PROC, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_warl_backdraft::HandleAfterCast);
    }
};

// 710 - Banish
class spell_warl_banish : public SpellScript
{
public:
    spell_warl_banish() {}

private:
    void HandleBanish(SpellMissInfo missInfo)
    {
        if (missInfo != SPELL_MISS_IMMUNE)
            return;

        if (Unit* target = GetHitUnit())
        {
            // Casting Banish on a banished target will remove applied aura
            if (Aura * banishAura = target->GetAura(GetSpellInfo()->Id, GetCaster()->GetGUID()))
                banishAura->Remove();
        }
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_warl_banish::HandleBanish);
    }
};

// 111400 - Burning Rush
class spell_warl_burning_rush : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    SpellCastResult CheckApplyAura()
    {
        Unit* caster = GetCaster();

        if (caster->GetHealthPct() <= float(GetEffectInfo(EFFECT_1).CalcValue(caster)))
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_YOU_DONT_HAVE_ENOUGH_HEALTH);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_warl_burning_rush::CheckApplyAura);
    }
};

// 111400 - Burning Rush
class spell_warl_burning_rush_aura : public AuraScript
{
    void PeriodicTick(AuraEffect const* aurEff)
    {
        if (GetTarget()->GetHealthPct() <= float(aurEff->GetAmount()))
        {
            PreventDefaultAction();
            Remove();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_burning_rush_aura::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
    }
};

// 152108 - Cataclysm
class spell_warl_cataclysm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_IMMOLATE_PERIODIC });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARLOCK_IMMOLATE_PERIODIC, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_cataclysm::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 116858 - Chaos Bolt
class spell_warl_chaos_bolt : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        SetHitDamage(GetHitDamage() + CalculatePct(GetHitDamage(), GetCaster()->ToPlayer()->m_activePlayerData->SpellCritPercentage));
    }

    void CalcCritChance(Unit const* /*victim*/, float& critChance)
    {
        critChance = 100.0f;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_chaos_bolt::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnCalcCritChance += SpellOnCalcCritChanceFn(spell_warl_chaos_bolt::CalcCritChance);
    }
};

// 77220 - Mastery: Chaotic Energies
class spell_warl_chaotic_energies : public AuraScript
{
    void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        AuraEffect const* effect1 = GetEffect(EFFECT_1);
        if (!effect1 || !GetTargetApplication()->HasEffect(EFFECT_1))
        {
            PreventDefaultAction();
            return;
        }

        // You take ${$s2/3}% reduced damage
        float damageReductionPct = float(effect1->GetAmount()) / 3;
        // plus a random amount of up to ${$s2/3}% additional reduced damage
        damageReductionPct += frand(0.0f, damageReductionPct);

        absorbAmount = CalculatePct(dmgInfo.GetDamage(), damageReductionPct);
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_warl_chaotic_energies::HandleAbsorb, EFFECT_2);
    }
};

// 17962 - Conflagrate
class spell_warl_conflagrate : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_WARLOCK_CONFLAGRATE_ENERGIZE });
    }

    void HandleAfterCast(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_CONFLAGRATE_ENERGIZE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_conflagrate::HandleAfterCast, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 6201 - Create Healthstone
class spell_warl_create_healthstone : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_CREATE_HEALTHSTONE });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_CREATE_HEALTHSTONE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_create_healthstone::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 108416 - Dark Pact
class spell_warl_dark_pact : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 }, { spellInfo->Id, EFFECT_2 } });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            float extraAmount = caster->SpellBaseDamageBonusDone(GetSpellInfo()->GetSchoolMask()) * 2.5f;
            int32 absorb = caster->CountPctFromCurHealth(GetEffectInfo(EFFECT_1).CalcValue(caster));
            caster->SetHealth(caster->GetHealth() - absorb);
            amount = CalculatePct(absorb, GetEffectInfo(EFFECT_2).CalcValue(caster)) + extraAmount;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_dark_pact::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

struct spell_warl_deaths_embrace_impl
{
    static void HandleDamageOrHealingCalculation(Unit const* caster, Unit const* target, float& pctMod, SpellEffIndex inreaseEffect, SpellEffIndex healthLimitEffect)
    {
        Aura const* deathsEmbrace = caster->GetAura(SPELL_WARLOCK_DEATHS_EMBRACE, ObjectGuid::Empty, ObjectGuid::Empty, 1 << inreaseEffect | 1 << healthLimitEffect);
        if (!deathsEmbrace)
            return;

        if (!target->HealthBelowPct(deathsEmbrace->GetEffect(healthLimitEffect)->GetAmount()))
            return;

        AddPct(pctMod, deathsEmbrace->GetEffect(inreaseEffect)->GetAmount());
    }
};

// Called by 324540 - Malefic Rapture
class spell_warl_deaths_embrace : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARLOCK_DEATHS_EMBRACE, EFFECT_3 } });
    }

    void HandleDamageCalculation(Unit const* victim, int32 const& /*damage*/, int32 const& /*flatMod*/, float& pctMod) const
    {
        spell_warl_deaths_embrace_impl::HandleDamageOrHealingCalculation(GetCaster(), victim, pctMod, EFFECT_2, EFFECT_3);
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_warl_deaths_embrace::HandleDamageCalculation);
    }
};

// Called by 980 - Agony, 146739 - Corruption and 316099 - Unstable Affliction
class spell_warl_deaths_embrace_dots : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARLOCK_DEATHS_EMBRACE, EFFECT_3 } });
    }

    void CalculateDamage(AuraEffect const* /*aurEff*/, Unit const* victim, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        if (Unit const* caster = GetCaster())
            spell_warl_deaths_embrace_impl::HandleDamageOrHealingCalculation(caster, victim, pctMod, EFFECT_2, EFFECT_3);
    }

    void Register() override
    {
        DoEffectCalcDamageAndHealing += AuraEffectCalcDamageFn(spell_warl_deaths_embrace_dots::CalculateDamage, EFFECT_ALL, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 234153 - Drain Life
class spell_warl_deaths_embrace_drain_life : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARLOCK_DEATHS_EMBRACE, EFFECT_1 } });
    }

    void CalculateHeal(AuraEffect const* /*aurEff*/, Unit const* victim, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        Unit const* caster = GetCaster();
        if (!caster)
            return;

        if (caster != victim)   // check who is being targeted, this hook is called for both damage and healing of PERIODIC_LEECH
            return;

        spell_warl_deaths_embrace_impl::HandleDamageOrHealingCalculation(caster, caster, pctMod, EFFECT_0, EFFECT_1);
    }

    void Register() override
    {
        DoEffectCalcDamageAndHealing += AuraEffectCalcHealingFn(spell_warl_deaths_embrace_drain_life::CalculateHeal, EFFECT_0, SPELL_AURA_PERIODIC_LEECH);
    }
};

// 48018 - Demonic Circle: Summon
class spell_warl_demonic_circle_summon : public AuraScript
{
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
    {
        // If effect is removed by expire remove the summoned demonic circle too.
        if (!(mode & AURA_EFFECT_HANDLE_REAPPLY))
            GetTarget()->RemoveGameObject(GetId(), true);

        GetTarget()->RemoveAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST);
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        if (GameObject* circle = GetTarget()->GetGameObject(GetId()))
        {
            // Here we check if player is in demonic circle teleport range, if so add
            // WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST; allowing him to cast the WARLOCK_DEMONIC_CIRCLE_TELEPORT.
            // If not in range remove the WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST.

            SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT, GetCastDifficulty());

            if (GetTarget()->IsWithinDist(circle, spellInfo->GetMaxRange(true)))
            {
                if (!GetTarget()->HasAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST))
                    GetTarget()->CastSpell(GetTarget(), SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST, true);
            }
            else
                GetTarget()->RemoveAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_warl_demonic_circle_summon::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_demonic_circle_summon::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 48020 - Demonic Circle: Teleport
class spell_warl_demonic_circle_teleport : public AuraScript
{
    void HandleTeleport(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Player* player = GetTarget()->ToPlayer())
        {
            if (GameObject* circle = player->GetGameObject(SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON))
            {
                player->NearTeleportTo(circle->GetPositionX(), circle->GetPositionY(), circle->GetPositionZ(), circle->GetOrientation());
                player->RemoveMovementImpairingAuras(false);
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_warl_demonic_circle_teleport::HandleTeleport, EFFECT_0, SPELL_AURA_MECHANIC_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 67518, 19505 - Devour Magic
class spell_warl_devour_magic : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void OnSuccessfulDispel(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_FULL_MASK;
        args.AddSpellBP0(GetEffectInfo(EFFECT_1).CalcValue(caster));

        caster->CastSpell(caster, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL, args);

        // Glyph of Felhunter
        if (Unit* owner = caster->GetOwner())
            if (owner->GetAura(SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING))
                owner->CastSpell(owner, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL, args);
    }

    void Register() override
    {
        OnEffectSuccessfulDispel += SpellEffectFn(spell_warl_devour_magic::OnSuccessfulDispel, EFFECT_0, SPELL_EFFECT_DISPEL);
    }
};

// 603 - Doom
class spell_warl_doom : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_WARLOCK_DOOM_ENERGIZE });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_WARLOCK_DOOM_ENERGIZE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_doom::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 198590 - Drain Soul
class spell_warl_drain_soul : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo ({ SPELL_WARLOCK_DRAIN_SOUL_ENERGIZE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } });
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_WARLOCK_DRAIN_SOUL_ENERGIZE, true);
    }

    void CalculateDamage(AuraEffect const* /*aurEff*/, Unit const* victim, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        if (victim->HealthBelowPct(GetEffectInfo(EFFECT_2).CalcValue(GetCaster())))
            AddPct(pctMod, GetEffectInfo(EFFECT_1).CalcValue(GetCaster()));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectApplyFn(spell_warl_drain_soul::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        DoEffectCalcDamageAndHealing += AuraEffectCalcDamageFn(spell_warl_drain_soul::CalculateDamage, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 48181 - Haunt
class spell_warl_haunt : public AuraScript
{
    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
            if (Unit* caster = GetCaster())
                caster->GetSpellHistory()->ResetCooldown(GetId(), true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_warl_haunt::HandleRemove, EFFECT_1, SPELL_AURA_MOD_SCHOOL_MASK_DAMAGE_FROM_CASTER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 755 - Health Funnel
class spell_warl_health_funnel : public AuraScript
{
    void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetTarget();
        if (caster->HasAura(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R2))
            target->CastSpell(target, SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2, true);
        else if (caster->HasAura(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R1))
            target->CastSpell(target, SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1, true);
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1);
        target->RemoveAurasDueToSpell(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        //! HACK for self damage, is not blizz :/
        uint32 damage = caster->CountPctFromMaxHealth(aurEff->GetBaseAmount());

        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::PowerCost0, damage);

        SpellNonMeleeDamage damageInfo(caster, caster, GetSpellInfo(), GetAura()->GetSpellVisual(), GetSpellInfo()->SchoolMask, GetAura()->GetCastId());
        damageInfo.periodicLog = true;
        damageInfo.damage = damage;
        caster->DealSpellDamage(&damageInfo, false);
        caster->SendSpellNonMeleeDamageLog(&damageInfo);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_warl_health_funnel::ApplyEffect, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_warl_health_funnel::RemoveEffect, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_health_funnel::OnPeriodic, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
    }
};

// 6262 - Healthstone
class spell_warl_healthstone_heal : public SpellScript
{
    void HandleOnHit()
    {
        int32 heal = int32(CalculatePct(GetCaster()->GetCreateHealth(), GetHitHeal()));
        SetHitHeal(heal);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warl_healthstone_heal::HandleOnHit);
    }
};

// 348 - Immolate
class spell_warl_immolate : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_IMMOLATE_PERIODIC});
    }

    void HandleOnEffectHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARLOCK_IMMOLATE_PERIODIC, GetSpell());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_immolate::HandleOnEffectHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Called by 316099 - Unstable Affliction
// 459376 - Perpetual Unstability
class spell_warl_perpetual_unstability : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_PERPETUAL_UNSTABILITY_TALENT, SPELL_WARLOCK_PERPETUAL_UNSTABILITY_DAMAGE });
    }

    void TriggerExplosion() const
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (AuraEffect const* perpetualUnstability = caster->GetAuraEffect(SPELL_WARLOCK_PERPETUAL_UNSTABILITY_TALENT, EFFECT_0))
        {
            if (Aura const* unstableAfflictionAura = target->GetAura(GetSpellInfo()->Id, caster->GetGUID()))
            {
                Milliseconds maxUnstableAfflictionDuration = Seconds(perpetualUnstability->GetAmount());
                if (Milliseconds(unstableAfflictionAura->GetDuration()) <= maxUnstableAfflictionDuration)
                    caster->CastSpell(target, SPELL_WARLOCK_PERPETUAL_UNSTABILITY_DAMAGE, CastSpellExtraArgs()
                        .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
                        .SetTriggeringSpell(GetSpell()));
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warl_perpetual_unstability::TriggerExplosion);
    }
};

// 387095 - Pyrogenics
class spell_warl_pyrogenics : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_PYROGENICS_DEBUFF });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& procInfo) const
    {
        GetTarget()->CastSpell(procInfo.GetActionTarget(), SPELL_WARLOCK_PYROGENICS_DEBUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warl_pyrogenics::HandleProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER_BY_SPELL_LABEL);
    }
};

// 5740 - Rain of Fire
/// Updated 11.0.2
class spell_warl_rain_of_fire : public AuraScript
{
    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        std::vector<AreaTrigger*> rainOfFireAreaTriggers = GetTarget()->GetAreaTriggers(SPELL_WARLOCK_RAIN_OF_FIRE);
        GuidUnorderedSet targetsInRainOfFire;

        for (AreaTrigger* rainOfFireAreaTrigger : rainOfFireAreaTriggers)
        {
            GuidUnorderedSet const& insideTargets = rainOfFireAreaTrigger->GetInsideUnits();
            targetsInRainOfFire.insert(insideTargets.begin(), insideTargets.end());
        }

        for (ObjectGuid insideTargetGuid : targetsInRainOfFire)
            if (Unit* insideTarget = ObjectAccessor::GetUnit(*GetTarget(), insideTargetGuid))
                if (!GetTarget()->IsFriendlyTo(insideTarget))
                    GetTarget()->CastSpell(insideTarget, SPELL_WARLOCK_RAIN_OF_FIRE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_rain_of_fire::HandleDummyTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 366330 - Random Sayaad
class spell_warl_random_sayaad : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_WARLOCK_SUCCUBUS_PACT,
            SPELL_WARLOCK_INCUBUS_PACT
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        caster->RemoveAurasDueToSpell(SPELL_WARLOCK_SUCCUBUS_PACT);
        caster->RemoveAurasDueToSpell(SPELL_WARLOCK_INCUBUS_PACT);

        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        if (Pet* pet = player->GetPet())
        {
            if (pet->IsPetSayaad())
                pet->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_warl_random_sayaad::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Called by 17962 - Conflagrate
class spell_warl_roaring_blaze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_WARLOCK_ROARING_BLAZE, SPELL_WARLOCK_CONFLAGRATE_DEBUFF });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARLOCK_ROARING_BLAZE);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARLOCK_CONFLAGRATE_DEBUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_roaring_blaze::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 366323 - Strengthen Pact - Succubus
// 366325 - Strengthen Pact - Incubus
// 366222 - Summon Sayaad
class spell_warl_sayaad_precast_disorientation : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ PET_SUMMONING_DISORIENTATION });
    }

    // Note: this is a special case in which the warlock's minion pet must also cast Summon Disorientation at the beginning since this is only handled by SPELL_EFFECT_SUMMON_PET in Spell::CheckCast.
    void OnPrecast() override
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        if (Pet* pet = player->GetPet())
            pet->CastSpell(pet, PET_SUMMONING_DISORIENTATION, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(pet->GetGUID())
                .SetTriggeringSpell(GetSpell()));
    }

    void Register() override
    {
    }
};

// 6358 - Seduction (Special Ability)
class spell_warl_seduction : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_GLYPH_OF_SUCCUBUS, SPELL_PRIEST_SHADOW_WORD_DEATH });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            if (caster->GetOwner() && caster->GetOwner()->HasAura(SPELL_WARLOCK_GLYPH_OF_SUCCUBUS))
            {
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE, ObjectGuid::Empty, target->GetAura(SPELL_PRIEST_SHADOW_WORD_DEATH)); // SW:D shall not be removed.
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_seduction::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 27285 - Seed of Corruption (damage)
class spell_warl_seed_of_corruption : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_CORRUPTION_DAMAGE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARLOCK_CORRUPTION_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_seed_of_corruption::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_warl_seed_of_corruption_dummy : public SpellScript
{
    void RemoveVisualMissile(WorldObject*& target) const
    {
        target = nullptr;
    }

    void SelectTarget(std::list<WorldObject*>& targets) const
    {
        if (targets.size() < 2)
            return;

        if (!GetExplTargetUnit()->HasAura(GetSpellInfo()->Id, GetCaster()->GetGUID()))
        {
            // primary target doesn't have seed, keep it
            targets.clear();
            targets.push_back(GetExplTargetUnit());
        }
        else
        {
            // primary target has seed, select random other target with no seed
            targets.remove_if(Trinity::UnitAuraCheck(true, GetSpellInfo()->Id, GetCaster()->GetGUID()));
            if (!targets.empty())
                Trinity::Containers::RandomResize(targets, 1);
            else
                targets.push_back(GetExplTargetUnit());
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_warl_seed_of_corruption_dummy::RemoveVisualMissile, EFFECT_0, TARGET_UNIT_TARGET_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_seed_of_corruption_dummy::SelectTarget, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_seed_of_corruption_dummy::SelectTarget, EFFECT_2, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 27243 - Seed of Corruption
class spell_warl_seed_of_corruption_dummy_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE, aurEff);
    }

    void CalculateBuffer(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        amount = caster->SpellBaseDamageBonusDone(GetSpellInfo()->GetSchoolMask()) * GetEffectInfo(EFFECT_0).CalcValue(caster) / 100;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();

        DamageInfo const* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (!damageInfo->GetAttacker() || damageInfo->GetAttacker() != caster)
            return;

        // other seed explosions detonate this instantly, no matter what damage amount is
        if (!damageInfo->GetSpellInfo() || damageInfo->GetSpellInfo()->Id != SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE)
        {
            int32 amount = aurEff->GetAmount() - damageInfo->GetDamage();
            if (amount > 0)
            {
                aurEff->SetAmount(amount);
                if (!GetTarget()->HealthBelowPctDamaged(1, damageInfo->GetDamage()))
                    return;
            }
        }

        Remove();

        caster->CastSpell(eventInfo.GetActionTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_seed_of_corruption_dummy_aura::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_seed_of_corruption_dummy_aura::CalculateBuffer, EFFECT_2, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_warl_seed_of_corruption_dummy_aura::HandleProc, EFFECT_2, SPELL_AURA_DUMMY);
    }
};

// 32863 - Seed of Corruption
// 36123 - Seed of Corruption
// 38252 - Seed of Corruption
// 39367 - Seed of Corruption
// 44141 - Seed of Corruption
// 70388 - Seed of Corruption
// Monster spells, triggered only on amount drop (not on death)
class spell_warl_seed_of_corruption_generic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        int32 amount = aurEff->GetAmount() - damageInfo->GetDamage();
        if (amount > 0)
        {
            const_cast<AuraEffect*>(aurEff)->SetAmount(amount);
            return;
        }

        Remove();

        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(eventInfo.GetActionTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warl_seed_of_corruption_generic::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 686 - Shadow Bolt
class spell_warl_shadow_bolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_WARLOCK_SHADOW_BOLT_ENERGIZE });
    }

    void HandleAfterCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SHADOW_BOLT_ENERGIZE, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_warl_shadow_bolt::HandleAfterCast);
    }
};

// 452999 - Siphon Life
class spell_warl_siphon_life : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SIPHON_LIFE_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        DamageInfo const* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        Unit* caster = GetTarget();
        caster->CastSpell(caster, SPELL_WARLOCK_SIPHON_LIFE_HEAL, CastSpellExtraArgs(aurEff)
            .AddSpellMod(SPELLVALUE_BASE_POINT0, CalculatePct(damageInfo->GetDamage(), aurEff->GetAmount())));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warl_siphon_life::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 86121 - Soul Swap
class spell_warl_soul_swap : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP,
            SPELL_WARLOCK_SOUL_SWAP_CD_MARKER,
            SPELL_WARLOCK_SOUL_SWAP_OVERRIDE
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_OVERRIDE, true);
        GetHitUnit()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 86211 - Soul Swap Override - Also acts as a dot container
class spell_warl_soul_swap_override : public AuraScript
{
    //! Forced to, pure virtual functions must have a body when linking
    void Register() override { }

public:
    void AddDot(uint32 id)                          { _dotList.push_back(id); }
    std::list<uint32> const GetDotList() const      { return _dotList; }
    Unit* GetOriginalSwapSource() const             { return _swapCaster; }
    void SetOriginalSwapSource(Unit* victim)        { _swapCaster = victim; }

private:
    std::list<uint32> _dotList;
    Unit* _swapCaster = nullptr;
};

//! Soul Swap Copy Spells - 92795 - Simply copies spell IDs.
class spell_warl_soul_swap_dot_marker : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* swapVictim = GetCaster();
        Unit* warlock    = GetHitUnit();
        if (!warlock || !swapVictim)
            return;

        Unit::AuraApplicationMap const& appliedAuras = swapVictim->GetAppliedAuras();
        spell_warl_soul_swap_override* swapSpellScript = nullptr;
        if (Aura* swapOverrideAura = warlock->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
            swapSpellScript = swapOverrideAura->GetScript<spell_warl_soul_swap_override>();

        if (!swapSpellScript)
            return;

        flag128 classMask = GetEffectInfo().SpellClassMask;

        for (Unit::AuraApplicationMap::const_iterator itr = appliedAuras.begin(); itr != appliedAuras.end(); ++itr)
        {
            SpellInfo const* spellProto = itr->second->GetBase()->GetSpellInfo();
            if (itr->second->GetBase()->GetCaster() == warlock)
                if (spellProto->SpellFamilyName == SPELLFAMILY_WARLOCK && (spellProto->SpellFamilyFlags & classMask))
                    swapSpellScript->AddDot(itr->first);
        }

        swapSpellScript->SetOriginalSwapSource(swapVictim);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_dot_marker::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 86213 - Soul Swap Exhale
class spell_warl_soul_swap_exhale : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SOUL_SWAP_MOD_COST, SPELL_WARLOCK_SOUL_SWAP_OVERRIDE });
    }

    SpellCastResult CheckCast()
    {
        Unit* currentTarget = GetExplTargetUnit();
        Unit* swapTarget = nullptr;
        if (Aura const* swapOverride = GetCaster()->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
            if (spell_warl_soul_swap_override* swapScript = swapOverride->GetScript<spell_warl_soul_swap_override>())
                swapTarget = swapScript->GetOriginalSwapSource();

        // Soul Swap Exhale can't be cast on the same target than Soul Swap
        if (swapTarget && currentTarget && swapTarget == currentTarget)
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void OnEffectHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_MOD_COST, true);
        bool hasGlyph = GetCaster()->HasAura(SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP);

        std::list<uint32> dotList;
        Unit* swapSource = nullptr;
        if (Aura const* swapOverride = GetCaster()->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
        {
            spell_warl_soul_swap_override* swapScript = swapOverride->GetScript<spell_warl_soul_swap_override>();
            if (!swapScript)
                return;
            dotList = swapScript->GetDotList();
            swapSource = swapScript->GetOriginalSwapSource();
        }

        if (dotList.empty())
            return;

        for (std::list<uint32>::const_iterator itr = dotList.begin(); itr != dotList.end(); ++itr)
        {
            GetCaster()->AddAura(*itr, GetHitUnit());
            if (!hasGlyph && swapSource)
                swapSource->RemoveAurasDueToSpell(*itr);
        }

        // Remove Soul Swap Exhale buff
        GetCaster()->RemoveAurasDueToSpell(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE);

        if (hasGlyph) // Add a cooldown on Soul Swap if caster has the glyph
            GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_CD_MARKER, false);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_warl_soul_swap_exhale::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_exhale::OnEffectHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 29858 - Soulshatter
class spell_warl_soulshatter : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SOULSHATTER_EFFECT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
            if (target->GetThreatManager().IsThreatenedBy(caster, true))
                caster->CastSpell(target, SPELL_WARLOCK_SOULSHATTER_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_soulshatter::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366323 - Strengthen Pact - Succubus
class spell_warl_strengthen_pact_succubus : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_WARLOCK_SUCCUBUS_PACT,
            SPELL_WARLOCK_SUMMON_SUCCUBUS
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        caster->CastSpell(nullptr, SPELL_WARLOCK_SUCCUBUS_PACT, TRIGGERED_FULL_MASK);
        caster->CastSpell(nullptr, SPELL_WARLOCK_SUMMON_SUCCUBUS, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_warl_strengthen_pact_succubus::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366325 - Strengthen Pact - Incubus
class spell_warl_strengthen_pact_incubus : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_WARLOCK_INCUBUS_PACT,
            SPELL_WARLOCK_SUMMON_INCUBUS
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        caster->CastSpell(nullptr, SPELL_WARLOCK_INCUBUS_PACT, TRIGGERED_FULL_MASK);
        caster->CastSpell(nullptr, SPELL_WARLOCK_SUMMON_INCUBUS, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_warl_strengthen_pact_incubus::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 366222 - Summon Sayaad
class spell_warl_summon_sayaad : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_WARLOCK_SUMMON_SUCCUBUS,
            SPELL_WARLOCK_SUMMON_INCUBUS
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, roll_chance_i(50) ? SPELL_WARLOCK_SUMMON_SUCCUBUS : SPELL_WARLOCK_SUMMON_INCUBUS, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_warl_summon_sayaad::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 37377 - Shadowflame
// 39437 - Shadowflame Hellfire and RoF
template <uint32 Trigger>
class spell_warl_t4_2p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Trigger });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActor();
        caster->CastSpell(caster, Trigger, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warl_t4_2p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 316099 - Unstable Affliction
class spell_warl_unstable_affliction : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE, SPELL_WARLOCK_UNSTABLE_AFFLICTION_ENERGIZE });
    }

    void HandleDispel(DispelInfo const* dispelInfo) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        AuraEffect const* removedEffect = GetEffect(EFFECT_1);
        if (!removedEffect)
            return;

        int32 damage = GetEffectInfo(EFFECT_0).CalcValue(caster, nullptr, GetUnitOwner()) / 100.0f * *removedEffect->CalculateEstimatedAmount(caster, removedEffect->GetAmount());
        caster->CastSpell(dispelInfo->GetDispeller(), SPELL_WARLOCK_UNSTABLE_AFFLICTION_DAMAGE, CastSpellExtraArgs()
            .AddSpellMod(SPELLVALUE_BASE_POINT0, damage)
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR));
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_UNSTABLE_AFFLICTION_ENERGIZE, true);
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_warl_unstable_affliction::HandleDispel);
        OnEffectRemove += AuraEffectRemoveFn(spell_warl_unstable_affliction::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 278350 - Vile Taint
class spell_warl_vile_taint : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_AGONY, SPELL_WARLOCK_CURSE_OF_EXHAUSTION, SPELL_WARLOCK_VILE_TAINT_DAMAGE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        CastSpellTargetArg target = GetHitUnit();

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_POWER_AND_REAGENT_COST
            | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        args.SetTriggeringSpell(GetSpell());

        caster->CastSpell(target, SPELL_WARLOCK_AGONY, args);
        caster->CastSpell(target, SPELL_WARLOCK_CURSE_OF_EXHAUSTION, args);
        caster->CastSpell(target, SPELL_WARLOCK_VILE_TAINT_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_vile_taint::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Called by 980 - Agony
// 453034 - Volatile Agony
class spell_warl_volatile_agony : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_VOLATILE_AGONY_TALENT, SPELL_WARLOCK_VOLATILE_AGONY_DAMAGE });
    }

    void TriggerExplosion() const
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (AuraEffect const* volatileAgony = caster->GetAuraEffect(SPELL_WARLOCK_VOLATILE_AGONY_TALENT, EFFECT_0))
        {
            if (Aura const* agonyAura = target->GetAura(GetSpellInfo()->Id, caster->GetGUID()))
            {
                Milliseconds maxAgonyDuration = Seconds(volatileAgony->GetAmount());
                if (Milliseconds(agonyAura->GetDuration()) <= maxAgonyDuration)
                    caster->CastSpell(target, SPELL_WARLOCK_VOLATILE_AGONY_DAMAGE, CastSpellExtraArgs()
                        .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
                        .SetTriggeringSpell(GetSpell()));
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warl_volatile_agony::TriggerExplosion);
    }
};

void AddSC_warlock_spell_scripts()
{
    RegisterSpellScript(spell_warl_absolute_corruption);
    RegisterSpellScript(spell_warl_backdraft);
    RegisterSpellScript(spell_warl_banish);
    RegisterSpellAndAuraScriptPair(spell_warl_burning_rush, spell_warl_burning_rush_aura);
    RegisterSpellScript(spell_warl_cataclysm);
    RegisterSpellScript(spell_warl_chaos_bolt);
    RegisterSpellScript(spell_warl_chaotic_energies);
    RegisterSpellScript(spell_warl_conflagrate);
    RegisterSpellScript(spell_warl_create_healthstone);
    RegisterSpellScript(spell_warl_dark_pact);
    RegisterSpellScript(spell_warl_deaths_embrace);
    RegisterSpellScript(spell_warl_deaths_embrace_dots);
    RegisterSpellScript(spell_warl_deaths_embrace_drain_life);
    RegisterSpellScript(spell_warl_demonic_circle_summon);
    RegisterSpellScript(spell_warl_demonic_circle_teleport);
    RegisterSpellScript(spell_warl_devour_magic);
    RegisterSpellScript(spell_warl_doom);
    RegisterSpellScript(spell_warl_drain_soul);
    RegisterSpellScript(spell_warl_haunt);
    RegisterSpellScript(spell_warl_health_funnel);
    RegisterSpellScript(spell_warl_healthstone_heal);
    RegisterSpellScript(spell_warl_immolate);
    RegisterSpellScript(spell_warl_perpetual_unstability);
    RegisterSpellScript(spell_warl_pyrogenics);
    RegisterSpellScript(spell_warl_rain_of_fire);
    RegisterSpellScript(spell_warl_random_sayaad);
    RegisterSpellScript(spell_warl_roaring_blaze);
    RegisterSpellScript(spell_warl_sayaad_precast_disorientation);
    RegisterSpellScript(spell_warl_seduction);
    RegisterSpellScript(spell_warl_seed_of_corruption);
    RegisterSpellAndAuraScriptPair(spell_warl_seed_of_corruption_dummy, spell_warl_seed_of_corruption_dummy_aura);
    RegisterSpellScript(spell_warl_seed_of_corruption_generic);
    RegisterSpellScript(spell_warl_shadow_bolt);
    RegisterSpellScript(spell_warl_siphon_life);
    RegisterSpellScript(spell_warl_soul_swap);
    RegisterSpellScript(spell_warl_soul_swap_dot_marker);
    RegisterSpellScript(spell_warl_soul_swap_exhale);
    RegisterSpellScript(spell_warl_soul_swap_override);
    RegisterSpellScript(spell_warl_soulshatter);
    RegisterSpellScript(spell_warl_strengthen_pact_incubus);
    RegisterSpellScript(spell_warl_strengthen_pact_succubus);
    RegisterSpellScript(spell_warl_summon_sayaad);
    RegisterSpellScriptWithArgs(spell_warl_t4_2p_bonus<SPELL_WARLOCK_FLAMESHADOW>, "spell_warl_t4_2p_bonus_shadow");
    RegisterSpellScriptWithArgs(spell_warl_t4_2p_bonus<SPELL_WARLOCK_SHADOWFLAME>, "spell_warl_t4_2p_bonus_fire");
    RegisterSpellScript(spell_warl_unstable_affliction);
    RegisterSpellScript(spell_warl_vile_taint);
    RegisterSpellScript(spell_warl_volatile_agony);
}
