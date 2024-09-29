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
 * Scripts for spells with SPELLFAMILY_DRUID and SPELLFAMILY_GENERIC spells used by druid players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dru_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "GridNotifiersImpl.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DruidSpells
{
    SPELL_DRUID_ABUNDANCE                      = 207383,
    SPELL_DRUID_ABUNDANCE_EFFECT               = 207640,
    SPELL_DRUID_ASTRAL_COMMUNION_ENERGIZE      = 450599,
    SPELL_DRUID_ASTRAL_COMMUNION_TALENT        = 450598,
    SPELL_DRUID_ASTRAL_SMOLDER_DAMAGE          = 394061,
    SPELL_DRUID_BALANCE_T10_BONUS              = 70718,
    SPELL_DRUID_BALANCE_T10_BONUS_PROC         = 70721,
    SPELL_DRUID_BEAR_FORM                      = 5487,
    SPELL_DRUID_BLESSING_OF_CENARIUS           = 40452,
    SPELL_DRUID_BLESSING_OF_ELUNE              = 40446,
    SPELL_DRUID_BLESSING_OF_REMULOS            = 40445,
    SPELL_DRUID_BLESSING_OF_THE_CLAW           = 28750,
    SPELL_DRUID_BLOOD_FRENZY_AURA              = 203962,
    SPELL_DRUID_BLOOD_FRENZY_RAGE_GAIN         = 203961,
    SPELL_DRUID_BRAMBLES_DAMAGE_AURA           = 213709,
    SPELL_DRUID_BRAMBLES_PASSIVE               = 203953,
    SPELL_DRUID_BRAMBLES_REFLECT               = 203958,
    SPELL_DRUID_BRISTLING_FUR_GAIN_RAGE        = 204031,
    SPELL_DRUID_CAT_FORM                       = 768,
    SPELL_DRUID_CULTIVATION                    = 200390,
    SPELL_DRUID_CULTIVATION_HEAL               = 200389,
    SPELL_DRUID_CURIOUS_BRAMBLEPATCH           = 330670,
    SPELL_DRUID_DREAMSTATE                     = 450346,
    SPELL_DRUID_EARTHWARDEN_AURA               = 203975,
    SPELL_DRUID_ECLIPSE_DUMMY                  = 79577,
    SPELL_DRUID_ECLIPSE_LUNAR_AURA             = 48518,
    SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT        = 326055,
    SPELL_DRUID_ECLIPSE_OOC                    = 329910,
    SPELL_DRUID_ECLIPSE_SOLAR_AURA             = 48517,
    SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT        = 326053,
    SPELL_DRUID_ECLIPSE_VISUAL_LUNAR           = 93431,
    SPELL_DRUID_ECLIPSE_VISUAL_SOLAR           = 93430,
    SPELL_DRUID_EFFLORESCENCE_AURA             = 81262,
    SPELL_DRUID_EFFLORESCENCE_HEAL             = 81269,
    SPELL_DRUID_EMBRACE_OF_THE_DREAM_EFFECT    = 392146,
    SPELL_DRUID_EMBRACE_OF_THE_DREAM_HEAL      = 392147,
    SPELL_DRUID_ENTANGLING_ROOTS               = 339,
    SPELL_DRUID_EXHILARATE                     = 28742,
    SPELL_DRUID_FORM_AQUATIC_PASSIVE           = 276012,
    SPELL_DRUID_FORM_AQUATIC                   = 1066,
    SPELL_DRUID_FORM_FLIGHT                    = 33943,
    SPELL_DRUID_FORM_STAG                      = 165961,
    SPELL_DRUID_FORM_SWIFT_FLIGHT              = 40120,
    SPELL_DRUID_FORMS_TRINKET_BEAR             = 37340,
    SPELL_DRUID_FORMS_TRINKET_CAT              = 37341,
    SPELL_DRUID_FORMS_TRINKET_MOONKIN          = 37343,
    SPELL_DRUID_FORMS_TRINKET_NONE             = 37344,
    SPELL_DRUID_FORMS_TRINKET_TREE             = 37342,
    SPELL_DRUID_FULL_MOON                      = 274283,
    SPELL_DRUID_GALACTIC_GUARDIAN_AURA         = 213708,
    SPELL_DRUID_GERMINATION                    = 155675,
    SPELL_DRUID_GLYPH_OF_STARS                 = 114301,
    SPELL_DRUID_GLYPH_OF_STARS_VISUAL          = 114302,
    SPELL_DRUID_GORE_PROC                      = 93622,
    SPELL_DRUID_GROWL                          = 6795,
    SPELL_DRUID_HALF_MOON                      = 274282,
    SPELL_DRUID_HALF_MOON_OVERRIDE             = 274297,
    SPELL_DRUID_IDOL_OF_FERAL_SHADOWS          = 34241,
    SPELL_DRUID_IDOL_OF_WORSHIP                = 60774,
    SPELL_DRUID_INCARNATION                    = 117679,
    SPELL_DRUID_INCARNATION_KING_OF_THE_JUNGLE = 102543,
    SPELL_DRUID_INCARNATION_TREE_OF_LIFE       = 33891,
    SPELL_DRUID_INNER_PEACE                    = 197073,
    SPELL_DRUID_INNERVATE                      = 29166,
    SPELL_DRUID_INNERVATE_RANK_2               = 326228,
    SPELL_DRUID_INFUSION                       = 37238,
    SPELL_DRUID_LANGUISH                       = 71023,
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL           = 33778,
    SPELL_DRUID_LUNAR_INSPIRATION_OVERRIDE     = 155627,
    SPELL_DRUID_MANGLE                         = 33917,
    SPELL_DRUID_MASS_ENTANGLEMENT              = 102359,
    SPELL_DRUID_MOONFIRE_DAMAGE                = 164812,
    SPELL_DRUID_NATURES_GRACE_TALENT           = 450347,
    SPELL_DRUID_NEW_MOON                       = 274281,
    SPELL_DRUID_NEW_MOON_OVERRIDE              = 274295,
    SPELL_DRUID_POWER_OF_THE_ARCHDRUID         = 392302,
    SPELL_DRUID_PROWL                          = 5215,
    SPELL_DRUID_REGROWTH                       = 8936,
    SPELL_DRUID_REJUVENATION                   = 774,
    SPELL_DRUID_REJUVENATION_GERMINATION       = 155777,
    SPELL_DRUID_REJUVENATION_T10_PROC          = 70691,
    SPELL_DRUID_RESTORATION_T10_2P_BONUS       = 70658,
    SPELL_DRUID_SAVAGE_ROAR                    = 62071,
    SPELL_DRUID_SHOOTING_STARS                 = 202342,
    SPELL_DRUID_SHOOTING_STARS_DAMAGE          = 202497,
    SPELL_DRUID_SKULL_BASH_CHARGE              = 221514,
    SPELL_DRUID_SKULL_BASH_INTERRUPT           = 93985,
    SPELL_DRUID_SPRING_BLOSSOMS                = 207385,
    SPELL_DRUID_SPRING_BLOSSOMS_HEAL           = 207386,
    SPELL_DRUID_STAR_BURST                     = 356474,
    SPELL_DRUID_SUNFIRE_DAMAGE                 = 164815,
    SPELL_DRUID_SURVIVAL_INSTINCTS             = 50322,
    SPELL_DRUID_TRAVEL_FORM                    = 783,
    SPELL_DRUID_TREE_OF_LIFE                   = 33891,
    SPELL_DRUID_THRASH_BEAR                    = 77758,
    SPELL_DRUID_THRASH_BEAR_AURA               = 192090,
    SPELL_DRUID_THRASH_CAT                     = 106830,
    SPELL_DRUID_YSERAS_GIFT_HEAL_PARTY         = 145110,
    SPELL_DRUID_YSERAS_GIFT_HEAL_SELF          = 145109
};

// 774 - Rejuvenation
// 155777 - Rejuvenation (Germination)
class spell_dru_abundance : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_ABUNDANCE, SPELL_DRUID_ABUNDANCE_EFFECT });
    }

    void HandleOnApplyOrReapply(AuraEffect const* aurEff, AuraEffectHandleModes mode) const
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->HasAura(SPELL_DRUID_ABUNDANCE))
            return;

        // Note: caster only casts Abundance when first applied on the target, otherwise that given stack is refreshed.
        if (mode & AURA_EFFECT_HANDLE_REAL)
            caster->CastSpell(caster, SPELL_DRUID_ABUNDANCE_EFFECT, CastSpellExtraArgs().SetTriggeringAura(aurEff));
        else if (Aura* abundanceAura = caster->GetAura(SPELL_DRUID_ABUNDANCE_EFFECT))
            abundanceAura->RefreshDuration();
    }

    void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* abundanceEffect = caster->GetAura(SPELL_DRUID_ABUNDANCE_EFFECT))
            abundanceEffect->ModStackAmount(-1);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_abundance::HandleOnApplyOrReapply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_abundance::HandleOnRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 102560 - Incarnation: Chosen of Elune
// 194223 - Celestial Alignment
// 383410 - Celestial Alignment
// 390414 - Incarnation: Chosen of Elune
class spell_dru_astral_communion_celestial_alignment : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_ASTRAL_COMMUNION_TALENT, SPELL_DRUID_ASTRAL_COMMUNION_ENERGIZE });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_DRUID_ASTRAL_COMMUNION_TALENT);
    }

    void Energize() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DRUID_ASTRAL_COMMUNION_ENERGIZE, CastSpellExtraArgs()
            .SetTriggeringSpell(GetSpell())
            .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR));
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dru_astral_communion_celestial_alignment::Energize);
    }
};

// 394058 - Astral Smolder
class spell_dru_astral_smolder : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_DRUID_ASTRAL_SMOLDER_DAMAGE, EFFECT_0 } })
            && sSpellMgr->AssertSpellInfo(SPELL_DRUID_ASTRAL_SMOLDER_DAMAGE, DIFFICULTY_NONE)->GetMaxTicks();
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        return eventInfo.GetProcTarget() != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();

        SpellInfo const* astralSmolderDmg = sSpellMgr->AssertSpellInfo(SPELL_DRUID_ASTRAL_SMOLDER_DAMAGE, GetCastDifficulty());
        int32 pct = aurEff->GetAmount();

        int32 amount = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), pct) / astralSmolderDmg->GetMaxTicks());

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, amount);
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_ASTRAL_SMOLDER_DAMAGE, args);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_astral_smolder::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_astral_smolder::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dru_base_transformer : public SpellScript
{
protected:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ GetShapeshiftFormSpell() });
    }

    void HandleOnCast()
    {
        // Change into cat form
        if (GetCaster()->GetShapeshiftForm() != GetShapeshiftForm())
            GetCaster()->CastSpell(GetCaster(), GetShapeshiftFormSpell(), true);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_dru_base_transformer::HandleOnCast);
    }

    virtual bool ToCatForm() const = 0;

    ShapeshiftForm GetShapeshiftForm() const { return ToCatForm() ? FORM_CAT_FORM : FORM_BEAR_FORM; }
    uint32 GetShapeshiftFormSpell() const { return ToCatForm() ? SPELL_DRUID_CAT_FORM : SPELL_DRUID_BEAR_FORM; }
};

// 22812 - Barkskin
class spell_dru_barkskin : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BRAMBLES_PASSIVE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DRUID_BRAMBLES_PASSIVE))
            target->CastSpell(target, SPELL_DRUID_BRAMBLES_DAMAGE_AURA, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_barkskin::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 50334 - Berserk
class spell_dru_berserk : public spell_dru_base_transformer
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!spell_dru_base_transformer::Validate(spellInfo))
            return false;

        return ValidateSpellInfo({ SPELL_DRUID_MANGLE, SPELL_DRUID_THRASH_BEAR, SPELL_DRUID_GROWL });
    }

    void ResetCooldowns()
    {
        GetCaster()->GetSpellHistory()->ResetCooldown(SPELL_DRUID_MANGLE);
        GetCaster()->GetSpellHistory()->ResetCooldown(SPELL_DRUID_THRASH_BEAR);
        GetCaster()->GetSpellHistory()->ResetCooldown(SPELL_DRUID_GROWL);
    }

    void Register() override
    {
        spell_dru_base_transformer::Register();
        AfterCast += SpellCastFn(spell_dru_berserk::ResetCooldowns);
    }

protected:
    bool ToCatForm() const override { return false; }
};

// 203953 - Brambles - SPELL_DRUID_BRAMBLES_PASSIVE
class spell_dru_brambles : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BRAMBLES_REFLECT, SPELL_DRUID_BRAMBLES_DAMAGE_AURA });
    }

    void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& /*dmgInfo*/, uint32& /*absorbAmount*/)
    {
        // Prevent Removal
        PreventDefaultAction();
    }

    void HandleAfterAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        // reflect back damage to the attacker
        Unit* target = GetTarget();
        if (Unit* attacker = dmgInfo.GetAttacker())
            target->CastSpell(attacker, SPELL_DRUID_BRAMBLES_REFLECT, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, absorbAmount));
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_brambles::HandleAbsorb, EFFECT_0);
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dru_brambles::HandleAfterAbsorb, EFFECT_0);
    }
};

// 155835 - Bristling Fur
class spell_dru_bristling_fur : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BRISTLING_FUR_GAIN_RAGE });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        // BristlingFurRage = 100 * Damage / MaxHealth.
        if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
        {
            Unit* target = GetTarget();
            uint32 rage = target->GetMaxPower(POWER_RAGE) * (float)damageInfo->GetDamage() / (float)target->GetMaxHealth();
            if (rage > 0)
                target->CastSpell(target, SPELL_DRUID_BRISTLING_FUR_GAIN_RAGE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, rage));
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_bristling_fur::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 768 - CatForm - SPELL_DRUID_CAT_FORM
class spell_dru_cat_form : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_PROWL });
    }

    void HandleAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveOwnedAura(SPELL_DRUID_PROWL);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_cat_form::HandleAfterRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 102560 - Incarnation: Chosen of Elune
// 194223 - Celestial Alignment
// 383410 - Celestial Alignment
// 390414 - Incarnation: Chosen of Elune
class spell_dru_celestial_alignment : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DRUID_ECLIPSE_SOLAR_AURA,
            SPELL_DRUID_ECLIPSE_LUNAR_AURA,
            SPELL_DRUID_ECLIPSE_VISUAL_SOLAR,
            SPELL_DRUID_ECLIPSE_VISUAL_LUNAR,
        });
    }

    void TriggerEclipses() const
    {
        Unit* caster = GetCaster();
        CastSpellExtraArgs args;
        args.SetTriggeringSpell(GetSpell());
        args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        caster->CastSpell(caster, SPELL_DRUID_ECLIPSE_SOLAR_AURA, args);
        caster->CastSpell(caster, SPELL_DRUID_ECLIPSE_LUNAR_AURA, args);
        caster->CastSpell(caster, SPELL_DRUID_ECLIPSE_VISUAL_SOLAR, args);
        caster->CastSpell(caster, SPELL_DRUID_ECLIPSE_VISUAL_LUNAR, args);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dru_celestial_alignment::TriggerEclipses);
    }
};

// 774 - Rejuvenation
// 155777 - Rejuventation (Germination)
class spell_dru_cultivation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_CULTIVATION_HEAL })
            && ValidateSpellEffect({ { SPELL_DRUID_CULTIVATION, EFFECT_0 } });
    }

    void HandleOnTick(AuraEffect const* aurEff) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetTarget();
        if (AuraEffect const* cultivationEffect = caster->GetAuraEffect(SPELL_DRUID_CULTIVATION, EFFECT_0))
            if (target->HealthBelowPct(cultivationEffect->GetAmount()))
                caster->CastSpell(target, SPELL_DRUID_CULTIVATION_HEAL, CastSpellExtraArgs().SetTriggeringAura(aurEff));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_cultivation::HandleOnTick, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

// 1850 - Dash
class spell_dru_dash : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        // do not set speed if not in cat form
        if (GetUnitOwner()->GetShapeshiftForm() != FORM_CAT_FORM)
            amount = 0;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_dash::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
    }
};

// 203974 - Earthwarden
class spell_dru_earthwarden : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_THRASH_CAT, SPELL_DRUID_THRASH_BEAR, SPELL_DRUID_EARTHWARDEN_AURA });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DRUID_EARTHWARDEN_AURA, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_earthwarden::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dru_eclipse_common
{
public:
    static void SetSpellCount(Unit* unitOwner, uint32 spellId, uint32 amount)
    {
        Aura* aura = unitOwner->GetAura(spellId);
        if (!aura)
            unitOwner->CastSpell(unitOwner, spellId, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_AURA_STACK, amount));
        else
            aura->SetStackAmount(amount);
    }
};

// 48517 Eclipse (Solar) + 48518 Eclipse (Lunar)
class spell_dru_eclipse_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_DUMMY });
    }

    void HandleRemoved(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        AuraEffect const* auraEffDummy = GetTarget()->GetAuraEffect(SPELL_DRUID_ECLIPSE_DUMMY, EFFECT_0);
        if (!auraEffDummy)
            return;

        uint32 spellId = GetSpellInfo()->Id == SPELL_DRUID_ECLIPSE_SOLAR_AURA ? SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT : SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT;
        spell_dru_eclipse_common::SetSpellCount(GetTarget(), spellId, auraEffDummy->GetAmount());
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_eclipse_aura::HandleRemoved, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 79577 - Eclipse - SPELL_DRUID_ECLIPSE_DUMMY
class spell_dru_eclipse_dummy : public AuraScript
{
    class InitializeEclipseCountersEvent : public BasicEvent
    {
    public:
        InitializeEclipseCountersEvent(Unit* owner, uint32 count) : BasicEvent(), _owner(owner), _count(count) { }

        bool Execute(uint64, uint32) override
        {
            spell_dru_eclipse_common::SetSpellCount(_owner, SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT, _count);
            spell_dru_eclipse_common::SetSpellCount(_owner, SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT, _count);
            return true;
        }

    private:
        Unit* _owner;
        uint32 _count;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT,
            SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT,
            SPELL_DRUID_ECLIPSE_SOLAR_AURA,
            SPELL_DRUID_ECLIPSE_LUNAR_AURA,
            SPELL_DRUID_ASTRAL_COMMUNION_TALENT,
            SPELL_DRUID_ASTRAL_COMMUNION_ENERGIZE
        });
    }

    void HandleProc(ProcEventInfo& eventInfo)
    {
        if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
        {
            if (spellInfo->SpellFamilyFlags & flag128(0x4, 0x0, 0x0, 0x0)) // Starfire
                OnSpellCast(SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_SOLAR_AURA);
            else if (spellInfo->SpellFamilyFlags & flag128(0x1, 0x0, 0x0, 0x0)) // Wrath
                OnSpellCast(SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_LUNAR_AURA);
        }
    }

    void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // counters are applied with a delay
        GetTarget()->m_Events.AddEventAtOffset(new InitializeEclipseCountersEvent(GetTarget(), aurEff->GetAmount()), 1s);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT);
        GetTarget()->RemoveAura(SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT);
    }

    void OnOwnerOutOfCombat(bool isNowInCombat)
    {
        if (!isNowInCombat)
            GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_ECLIPSE_OOC, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_eclipse_dummy::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_dru_eclipse_dummy::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnProc += AuraProcFn(spell_dru_eclipse_dummy::HandleProc);
        OnEnterLeaveCombat += AuraEnterLeaveCombatFn(spell_dru_eclipse_dummy::OnOwnerOutOfCombat);
    }

private:
    void OnSpellCast(uint32 cntSpellId, uint32 otherCntSpellId, uint32 eclipseAuraSpellId)
    {
        Unit* target = GetTarget();
        if (Aura* aura = target->GetAura(cntSpellId))
        {
            uint32 remaining = aura->GetStackAmount();
            if (remaining == 0)
                return;

            if (remaining > 1)
                aura->SetStackAmount(remaining - 1);
            else
            {
                // cast eclipse
                target->CastSpell(target, eclipseAuraSpellId, TRIGGERED_FULL_MASK);

                if (target->HasAura(SPELL_DRUID_ASTRAL_COMMUNION_TALENT))
                    target->CastSpell(target, SPELL_DRUID_ASTRAL_COMMUNION_ENERGIZE, true);

                // Remove stacks from other one as well
                // reset remaining power on other spellId
                target->RemoveAura(cntSpellId);
                target->RemoveAura(otherCntSpellId);
            }
        }
    }
};

// 329910 - Eclipse out of combat - SPELL_DRUID_ECLIPSE_OOC
class spell_dru_eclipse_ooc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_ECLIPSE_DUMMY, SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT, SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT });
    }

    void Tick(AuraEffect const* /*aurEff*/)
    {
        Unit* owner = GetTarget();
        AuraEffect const* auraEffDummy = owner->GetAuraEffect(SPELL_DRUID_ECLIPSE_DUMMY, EFFECT_0);
        if (!auraEffDummy)
            return;

        if (!owner->IsInCombat() && (!owner->HasAura(SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT) || !owner->HasAura(SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT)))
        {
            // Restore 2 stacks to each spell when out of combat
            spell_dru_eclipse_common::SetSpellCount(owner, SPELL_DRUID_ECLIPSE_SOLAR_SPELL_CNT, auraEffDummy->GetAmount());
            spell_dru_eclipse_common::SetSpellCount(owner, SPELL_DRUID_ECLIPSE_LUNAR_SPELL_CNT, auraEffDummy->GetAmount());
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_eclipse_ooc::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 145205 - Efflorescence
class spell_dru_efflorescence : public SpellScript
{
    void RemoveOldAreaTrigger(SpellEffIndex /*effIndex*/) const
    {
        // if caster has any Efflorescence areatrigger, we remove it.
        GetCaster()->RemoveAreaTrigger(GetSpellInfo()->Id);
    }

    void InitSummon()
    {
        for (SpellLogEffectGenericVictimParams const& summonedObject : GetSpell()->GetExecuteLogEffectTargets(SPELL_EFFECT_SUMMON, &SpellLogEffect::GenericVictimTargets))
            if (Unit* summon = ObjectAccessor::GetCreature(*GetCaster(), summonedObject.Victim))
                summon->CastSpell(summon, SPELL_DRUID_EFFLORESCENCE_AURA,
                    CastSpellExtraArgs().SetTriggeringSpell(GetSpell()));
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_dru_efflorescence::RemoveOldAreaTrigger, EFFECT_2, SPELL_EFFECT_CREATE_AREATRIGGER);
        AfterCast += SpellCastFn(spell_dru_efflorescence::InitSummon);
    }
};

// 81262 - Efflorescence (Dummy)
class spell_dru_efflorescence_dummy : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_EFFLORESCENCE_HEAL });
    }

    void HandlePeriodicDummy(AuraEffect const* /*aurEff*/) const
    {
        Unit* target = GetTarget();
        Unit* summoner = target->GetOwner();
        if (!summoner)
            return;

        summoner->CastSpell(target, SPELL_DRUID_EFFLORESCENCE_HEAL, TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_efflorescence_dummy::HandlePeriodicDummy, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 81269 - Efflorescence (Heal)
class spell_dru_efflorescence_heal : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        // Efflorescence became a smart heal which prioritizes players and their pets in their group before any unit outside their group.
        Trinity::SelectRandomInjuredTargets(targets, 3, true, GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_efflorescence_heal::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 392124 - Embrace of the Dream
class spell_dru_embrace_of_the_dream : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo ({ SPELL_DRUID_EMBRACE_OF_THE_DREAM_EFFECT })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*eventInfo*/) const
    {
        return roll_chance_i(GetEffectInfo(EFFECT_2).CalcValue(GetCaster()));
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_EMBRACE_OF_THE_DREAM_EFFECT,
            CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringAura(aurEff)
            .SetTriggeringSpell(eventInfo.GetProcSpell()));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_embrace_of_the_dream::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_embrace_of_the_dream::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 392146 - Embrace of the Dream (Selector)
class spell_dru_embrace_of_the_dream_effect : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_DRUID_EMBRACE_OF_THE_DREAM_HEAL,
            SPELL_DRUID_REGROWTH,
            SPELL_DRUID_REJUVENATION,
            SPELL_DRUID_REJUVENATION_GERMINATION
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        targets.remove_if([&](WorldObject const* target)
        {
            Unit const* unitTarget = target->ToUnit();
            return !unitTarget || !unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, flag128(0x50, 0, 0, 0), GetCaster()->GetGUID());
        });
    }

    void HandleEffect(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_EMBRACE_OF_THE_DREAM_HEAL,
            CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringSpell(GetSpell()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_embrace_of_the_dream_effect::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_dru_embrace_of_the_dream_effect::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 339 - Entangling Roots
// 102359 - Mass Entanglement
class spell_dru_entangling_roots : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_CURIOUS_BRAMBLEPATCH });
    }

    void HandleCuriousBramblepatch(WorldObject*& target)
    {
        if (!GetCaster()->HasAura(SPELL_DRUID_CURIOUS_BRAMBLEPATCH))
            target = nullptr;
    }

    void HandleCuriousBramblepatchAOE(std::list<WorldObject*>& targets)
    {
        if (!GetCaster()->HasAura(SPELL_DRUID_CURIOUS_BRAMBLEPATCH))
            targets.clear();
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dru_entangling_roots::HandleCuriousBramblepatch, EFFECT_1, TARGET_UNIT_TARGET_ENEMY);
        if (m_scriptSpellId == SPELL_DRUID_MASS_ENTANGLEMENT)
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_entangling_roots::HandleCuriousBramblepatchAOE, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

class spell_dru_entangling_roots_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_ENTANGLING_ROOTS, SPELL_DRUID_MASS_ENTANGLEMENT });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
        {
            // dont subtract dmg caused by roots from dmg required to break root
            if (spellInfo->Id == SPELL_DRUID_ENTANGLING_ROOTS || spellInfo->Id == SPELL_DRUID_MASS_ENTANGLEMENT)
                return false;
        }
        return true;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_entangling_roots_aura::CheckProc);
    }
};

// 22568 - Ferocious Bite
class spell_dru_ferocious_bite : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_DRUID_INCARNATION_KING_OF_THE_JUNGLE, EFFECT_1 } });
    }

    void HandleHitTargetBurn(SpellEffIndex /*effIndex*/)
    {
        int32 newValue = int32(float(GetEffectValue()) * _damageMultiplier);
        SetEffectValue(newValue);
    }

    void HandleHitTargetDmg(SpellEffIndex /*effIndex*/)
    {
        int32 newValue = int32(float(GetHitDamage()) * (1.0f + _damageMultiplier));
        SetHitDamage(newValue);
    }

    void HandleLaunchTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        int32 maxExtraConsumedPower = GetEffectValue();

        if (AuraEffect* auraEffect = caster->GetAuraEffect(SPELL_DRUID_INCARNATION_KING_OF_THE_JUNGLE, EFFECT_1))
        {
            float multiplier = 1.0f + float(auraEffect->GetAmount()) / 100.0f;
            maxExtraConsumedPower = int32(float(maxExtraConsumedPower) * multiplier);
            SetEffectValue(maxExtraConsumedPower);
        }

        _damageMultiplier = std::min<float>(caster->GetPower(POWER_ENERGY), maxExtraConsumedPower) / maxExtraConsumedPower;
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_dru_ferocious_bite::HandleLaunchTarget, EFFECT_1, SPELL_EFFECT_POWER_BURN);
        OnEffectHitTarget += SpellEffectFn(spell_dru_ferocious_bite::HandleHitTargetBurn, EFFECT_1, SPELL_EFFECT_POWER_BURN);
        OnEffectHitTarget += SpellEffectFn(spell_dru_ferocious_bite::HandleHitTargetDmg, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }

private:
    float _damageMultiplier = 0.0f;
};

// 37336 - Druid Forms Trinket
class spell_dru_forms_trinket : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DRUID_FORMS_TRINKET_BEAR,
            SPELL_DRUID_FORMS_TRINKET_CAT,
            SPELL_DRUID_FORMS_TRINKET_MOONKIN,
            SPELL_DRUID_FORMS_TRINKET_NONE,
            SPELL_DRUID_FORMS_TRINKET_TREE
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Unit* target = eventInfo.GetActor();

        switch (target->GetShapeshiftForm())
        {
            case FORM_BEAR_FORM:
            case FORM_DIRE_BEAR_FORM:
            case FORM_CAT_FORM:
            case FORM_MOONKIN_FORM:
            case FORM_NONE:
            case FORM_TREE_OF_LIFE:
                return true;
            default:
                break;
        }

        return false;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = eventInfo.GetActor();
        uint32 triggerspell = 0;

        switch (target->GetShapeshiftForm())
        {
            case FORM_BEAR_FORM:
            case FORM_DIRE_BEAR_FORM:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_BEAR;
                break;
            case FORM_CAT_FORM:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_CAT;
                break;
            case FORM_MOONKIN_FORM:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_MOONKIN;
                break;
            case FORM_NONE:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_NONE;
                break;
            case FORM_TREE_OF_LIFE:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_TREE;
                break;
            default:
                return;
        }

        target->CastSpell(target, triggerspell, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_forms_trinket::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_forms_trinket::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 203964 - Galactic Guardian
class spell_dru_galactic_guardian : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GALACTIC_GUARDIAN_AURA });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
        {
            Unit* target = GetTarget();

            // free automatic moonfire on target
            target->CastSpell(damageInfo->GetVictim(), SPELL_DRUID_MOONFIRE_DAMAGE, true);

            // Cast aura
            target->CastSpell(damageInfo->GetVictim(), SPELL_DRUID_GALACTIC_GUARDIAN_AURA, true);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_galactic_guardian::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 774 - Rejuvenation
class spell_dru_germination : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_REJUVENATION, SPELL_DRUID_GERMINATION, SPELL_DRUID_REJUVENATION_GERMINATION });
    }

    void PickRejuvenationVariant(WorldObject*& target) const
    {
        Unit* caster = GetCaster();

        // Germination talent.
        if (caster->HasAura(SPELL_DRUID_GERMINATION))
        {
            Unit* unitTarget = target->ToUnit();
            Aura* rejuvenationAura = unitTarget->GetAura(SPELL_DRUID_REJUVENATION, caster->GetGUID());
            Aura* germinationAura = unitTarget->GetAura(SPELL_DRUID_REJUVENATION_GERMINATION, caster->GetGUID());

            // if target doesn't have Rejuventation, cast passes through.
            if (!rejuvenationAura)
                return;

            // if target has Rejuvenation, but not Germination, or Germination has lower remaining duration than Rejuvenation, then cast Germination
            if (germinationAura && germinationAura->GetDuration() >= rejuvenationAura->GetDuration())
                return;

            caster->CastSpell(target, SPELL_DRUID_REJUVENATION_GERMINATION,
                CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
                .SetTriggeringSpell(GetSpell()));

            // prevent aura refresh (but cast must still happen to consume mana)
            target = nullptr;
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dru_germination::PickRejuvenationVariant, EFFECT_0, TARGET_UNIT_TARGET_ALLY);
    }
};

// 24858 - Moonkin Form
class spell_dru_glyph_of_stars : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_STARS, SPELL_DRUID_GLYPH_OF_STARS_VISUAL });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DRUID_GLYPH_OF_STARS))
            target->CastSpell(target, SPELL_DRUID_GLYPH_OF_STARS_VISUAL, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_GLYPH_OF_STARS_VISUAL);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_dru_glyph_of_stars::OnApply, EFFECT_1, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_dru_glyph_of_stars::OnRemove, EFFECT_1, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 210706 - Gore
class spell_dru_gore : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GORE_PROC, SPELL_DRUID_MANGLE });
    }

    bool CheckEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*procInfo*/)
    {
        Unit* owner = GetTarget();
        owner->CastSpell(owner, SPELL_DRUID_GORE_PROC);
        owner->GetSpellHistory()->ResetCooldown(SPELL_DRUID_MANGLE, true);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_gore::CheckEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_gore::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 99 - Incapacitating Roar
class spell_dru_incapacitating_roar : public spell_dru_base_transformer
{
protected:
    bool ToCatForm() const override { return false; }
};

// 29166 - Innervate
class spell_dru_innervate : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Player* target = Object::ToPlayer(GetExplTargetUnit());
        if (!target)
            return SPELL_FAILED_BAD_TARGETS;

        ChrSpecializationEntry const* spec = target->GetPrimarySpecializationEntry();
        if (!spec || spec->GetRole() != ChrSpecializationRole::Healer)
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleRank2()
    {
        Unit* caster = GetCaster();
        if (caster != GetHitUnit())
            if (AuraEffect const* innervateR2 = caster->GetAuraEffect(SPELL_DRUID_INNERVATE_RANK_2, EFFECT_0))
                caster->CastSpell(caster, SPELL_DRUID_INNERVATE,
                    CastSpellExtraArgs(TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)
                    .SetTriggeringSpell(GetSpell())
                    .AddSpellMod(SPELLVALUE_BASE_POINT0, -innervateR2->GetAmount()));

    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dru_innervate::CheckCast);
        OnHit += SpellHitFn(spell_dru_innervate::HandleRank2);
    }
};

// 117679 - Incarnation (Passive)
class spell_dru_incarnation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_INCARNATION_TREE_OF_LIFE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_INCARNATION_TREE_OF_LIFE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_incarnation::OnRemove, EFFECT_0, SPELL_AURA_IGNORE_SPELL_COOLDOWN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 33891 - Incarnation: Tree of Life (Talent, Shapeshift)
class spell_dru_incarnation_tree_of_life : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_INCARNATION });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (!GetTarget()->HasAura(SPELL_DRUID_INCARNATION))
            GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_INCARNATION, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_incarnation_tree_of_life::AfterApply, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 740 - Tranquility
class spell_dru_inner_peace : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_INNER_PEACE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_4 } })
            && spellInfo->GetEffect(EFFECT_3).IsAura(SPELL_AURA_MECHANIC_IMMUNITY_MASK)
            && spellInfo->GetEffect(EFFECT_4).IsAura(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }

    void PreventEffect(WorldObject*& target) const
    {
        // Note: Inner Peace talent.
        if (!GetCaster()->HasAura(SPELL_DRUID_INNER_PEACE))
            target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dru_inner_peace::PreventEffect, EFFECT_3, TARGET_UNIT_CASTER);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dru_inner_peace::PreventEffect, EFFECT_4, TARGET_UNIT_CASTER);
    }
};

// 40442 - Druid Tier 6 Trinket
class spell_dru_item_t6_trinket : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DRUID_BLESSING_OF_REMULOS,
            SPELL_DRUID_BLESSING_OF_ELUNE,
            SPELL_DRUID_BLESSING_OF_CENARIUS
        });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return;

        uint32 spellId;
        int32 chance;

        // Starfire
        if (spellInfo->SpellFamilyFlags[0] & 0x00000004)
        {
            spellId = SPELL_DRUID_BLESSING_OF_REMULOS;
            chance = 25;
        }
        // Rejuvenation
        else if (spellInfo->SpellFamilyFlags[0] & 0x00000010)
        {
            spellId = SPELL_DRUID_BLESSING_OF_ELUNE;
            chance = 25;
        }
        // Mangle (Bear) and Mangle (Cat)
        else if (spellInfo->SpellFamilyFlags[1] & 0x00000440)
        {
            spellId = SPELL_DRUID_BLESSING_OF_CENARIUS;
            chance = 40;
        }
        else
            return;

        if (roll_chance_i(chance))
            eventInfo.GetActor()->CastSpell(nullptr, spellId, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_item_t6_trinket::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 33763 - Lifebloom
class spell_dru_lifebloom : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_LIFEBLOOM_FINAL_HEAL });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Final heal only on duration end
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE || GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            GetCaster()->CastSpell(GetUnitOwner(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lifebloom::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 155580 - Lunar Inspiration
class spell_dru_lunar_inspiration : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_LUNAR_INSPIRATION_OVERRIDE });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_LUNAR_INSPIRATION_OVERRIDE, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_LUNAR_INSPIRATION_OVERRIDE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_lunar_inspiration::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lunar_inspiration::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 392315 - Luxuriant Soil
class spell_dru_luxuriant_soil : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_REJUVENATION });
    }

    static bool CheckProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo) const
    {
        Unit* rejuvCaster = GetTarget();

        // let's use the ProcSpell's max. range.
        float spellRange = eventInfo.GetSpellInfo()->GetMaxRange();

        std::vector<Unit*> targetList;
        Trinity::WorldObjectSpellAreaTargetCheck check(spellRange, rejuvCaster, rejuvCaster, rejuvCaster, eventInfo.GetSpellInfo(), TARGET_CHECK_ALLY, nullptr, TARGET_OBJECT_TYPE_UNIT);
        Trinity::UnitListSearcher searcher(rejuvCaster, targetList, check);
        Cell::VisitAllObjects(rejuvCaster, searcher, spellRange);

        if (targetList.empty())
            return;

        rejuvCaster->CastSpell(Trinity::Containers::SelectRandomContainerElement(targetList), SPELL_DRUID_REJUVENATION, TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_POWER_AND_REAGENT_COST | TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_luxuriant_soil::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_luxuriant_soil::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

//  8921 - Moonfire
class spell_dru_moonfire : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_MOONFIRE_DAMAGE });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_MOONFIRE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_moonfire::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 450347 - Nature's Grace
class spell_dru_natures_grace : public AuraScript
{
public:
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_NATURES_GRACE_TALENT, SPELL_DRUID_DREAMSTATE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } });
    }

    static void Trigger(Unit* caster, AuraEffect const* naturesGraceEffect)
    {
        caster->CastSpell(caster, SPELL_DRUID_DREAMSTATE, CastSpellExtraArgsInit{
            .SpellValueOverrides = { { SPELLVALUE_AURA_STACK, naturesGraceEffect->GetAmount() } }
        });

    }

    void OnOwnerInCombat(bool isNowInCombat) const
    {
        if (isNowInCombat)
            Trigger(GetTarget(), GetEffect(EFFECT_2));
    }

    void Register() override
    {
        OnEnterLeaveCombat += AuraEnterLeaveCombatFn(spell_dru_natures_grace::OnOwnerInCombat);
    }
};

// 48517 Eclipse (Solar) + 48518 Eclipse (Lunar)
class spell_dru_natures_grace_eclipse : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_DREAMSTATE })
            && ValidateSpellEffect({ { SPELL_DRUID_NATURES_GRACE_TALENT, EFFECT_2 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAuraEffect(SPELL_DRUID_NATURES_GRACE_TALENT, EFFECT_2);
    }

    void HandleRemoved(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        spell_dru_natures_grace::Trigger(GetTarget(), GetTarget()->GetAuraEffect(SPELL_DRUID_NATURES_GRACE_TALENT, EFFECT_2));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_natures_grace_eclipse::HandleRemoved, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 274283 - Full Moon
// 274282 - Half Moon
// 274281 - New Moon
class spell_dru_new_moon : public SpellScript
{
public:
    explicit spell_dru_new_moon(Optional<uint32> newOverrideSpell, Optional<uint32> removeOverrideSpell)
        : _newOverrideSpell(newOverrideSpell), _removeOverrideSpell(removeOverrideSpell) { }

private:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return (!_newOverrideSpell || ValidateSpellInfo({ *_newOverrideSpell }))
            && (!_removeOverrideSpell || ValidateSpellInfo({ *_removeOverrideSpell }));
    }

    void OverrideMoon() const
    {
        Unit* caster = GetCaster();
        if (_newOverrideSpell)
            caster->CastSpell(caster, *_newOverrideSpell, CastSpellExtraArgs()
                .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
                .SetTriggeringSpell(GetSpell()));

        if (_removeOverrideSpell)
            caster->RemoveAurasDueToSpell(*_removeOverrideSpell);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dru_new_moon::OverrideMoon);
    }

    Optional<uint32> _newOverrideSpell;
    Optional<uint32> _removeOverrideSpell;
};

// 16864 - Omen of Clarity
class spell_dru_omen_of_clarity : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BALANCE_T10_BONUS, SPELL_DRUID_BALANCE_T10_BONUS_PROC });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DRUID_BALANCE_T10_BONUS))
            target->CastSpell(nullptr, SPELL_DRUID_BALANCE_T10_BONUS_PROC, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_omen_of_clarity::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 113043 - Omen of Clarity
class spell_dru_omen_of_clarity_restoration : public AuraScript
{
    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo const& /*eventInfo*/) const
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_omen_of_clarity_restoration::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 392303 - Power of the Archdruid
class spell_dru_power_of_the_archdruid : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_DRUID_POWER_OF_THE_ARCHDRUID, EFFECT_0 } });
    }

    static bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        return eventInfo.GetActor()->HasAuraEffect(SPELL_DRUID_POWER_OF_THE_ARCHDRUID, EFFECT_0);
    }

    static void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        Unit* druid = eventInfo.GetActor();
        Unit const* procTarget = eventInfo.GetActionTarget();

        // range is EFFECT_0's BasePoints.
        float spellRange = aurEff->GetAmount();

        std::vector<Unit*> targetList;
        Trinity::WorldObjectSpellAreaTargetCheck checker(spellRange, procTarget, druid, druid, eventInfo.GetSpellInfo(), TARGET_CHECK_ALLY, nullptr, TARGET_OBJECT_TYPE_UNIT);
        Trinity::UnitListSearcher searcher(procTarget, targetList, checker);
        Cell::VisitAllObjects(procTarget, searcher, spellRange);
        std::erase(targetList, procTarget);

        if (targetList.empty())
            return;

        AuraEffect const* powerOfTheArchdruidEffect = druid->GetAuraEffect(SPELL_DRUID_POWER_OF_THE_ARCHDRUID, EFFECT_0);

        // max. targets is SPELL_DRUID_POWER_OF_THE_ARCHDRUID's EFFECT_0 BasePoints.
        int32 maxTargets = powerOfTheArchdruidEffect->GetAmount();

        Trinity::Containers::RandomResize(targetList, maxTargets);

        for (Unit* chosenTarget : targetList)
            druid->CastSpell(chosenTarget, eventInfo.GetProcSpell()->GetSpellInfo()->Id, aurEff);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_power_of_the_archdruid::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_power_of_the_archdruid::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 5215 - Prowl
class spell_dru_prowl : public spell_dru_base_transformer
{
protected:
    bool ToCatForm() const override { return true; }
};

// 1079 - Rip
class spell_dru_rip : public AuraScript
{
    bool Load() override
    {
        Unit* caster = GetCaster();
        return caster && caster->GetTypeId() == TYPEID_PLAYER;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;

        if (Unit* caster = GetCaster())
        {
            // 0.01 * $AP * cp
            int32 cp = caster->GetPower(POWER_COMBO_POINTS);

            // Idol of Feral Shadows. Can't be handled as SpellMod due its dependency from CPs
            if (AuraEffect const* auraEffIdolOfFeralShadows = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_FERAL_SHADOWS, EFFECT_0))
                amount += cp * auraEffIdolOfFeralShadows->GetAmount();
            // Idol of Worship. Can't be handled as SpellMod due its dependency from CPs
            else if (AuraEffect const* auraEffIdolOfWorship = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_WORSHIP, EFFECT_0))
                amount += cp * auraEffIdolOfWorship->GetAmount();

            amount += int32(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), cp));
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_rip::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 52610 - Savage Roar
class spell_dru_savage_roar : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->GetShapeshiftForm() != FORM_CAT_FORM)
            return SPELL_FAILED_ONLY_SHAPESHIFT;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dru_savage_roar::CheckCast);
    }
};

class spell_dru_savage_roar_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SAVAGE_ROAR });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DRUID_SAVAGE_ROAR, CastSpellExtraArgs(aurEff)
            .SetOriginalCaster(GetCasterGUID()));
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SAVAGE_ROAR);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_savage_roar_aura::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_savage_roar_aura::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 164815 - Sunfire
// 164812 - Moonfire
class spell_dru_shooting_stars : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SHOOTING_STARS, SPELL_DRUID_SHOOTING_STARS_DAMAGE });
    }

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect const* shootingStars = caster->GetAuraEffect(SPELL_DRUID_SHOOTING_STARS, EFFECT_0))
                if (roll_chance_i(shootingStars->GetAmount()))
                    caster->CastSpell(GetTarget(), SPELL_DRUID_SHOOTING_STARS_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_shooting_stars::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 106839 - Skull Bash
class spell_dru_skull_bash : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SKULL_BASH_CHARGE, SPELL_DRUID_SKULL_BASH_INTERRUPT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_SKULL_BASH_CHARGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_SKULL_BASH_INTERRUPT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_skull_bash::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 81269 - Efflorescence (Heal)
class spell_dru_spring_blossoms : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SPRING_BLOSSOMS, SPELL_DRUID_SPRING_BLOSSOMS_HEAL });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/) const
    {
        if (GetCaster()->HasAura(SPELL_DRUID_SPRING_BLOSSOMS))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_SPRING_BLOSSOMS_HEAL, TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_spring_blossoms::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 106898 - Stampeding Roar
class spell_dru_stampeding_roar : public spell_dru_base_transformer
{
protected:
    bool ToCatForm() const override { return false; }
};

// 50286 - Starfall (Dummy)
class spell_dru_starfall_dummy : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 2);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        // Shapeshifting into an animal form or mounting cancels the effect
        if (caster->GetCreatureType() == CREATURE_TYPE_BEAST || caster->IsMounted())
        {
            if (SpellInfo const* spellInfo = GetTriggeringSpell())
                caster->RemoveAurasDueToSpell(spellInfo->Id);
            return;
        }

        // Any effect which causes you to lose control of your character will supress the starfall effect.
        if (caster->HasUnitState(UNIT_STATE_CONTROLLED))
            return;

        caster->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_dru_starfall_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 202347 - Stellar Flare
class spell_dru_stellar_flare : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_STAR_BURST });
    }

    void HandleDispel(DispelInfo* dispelInfo)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(dispelInfo->GetDispeller(), SPELL_DRUID_STAR_BURST, true);
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_dru_stellar_flare::HandleDispel);
    }
};

// 340694 - Sudden Ambush
// 384667 - Sudden Ambush
class spell_dru_sudden_ambush : public AuraScript
{
    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& procInfo)
    {
        Spell const* procSpell = procInfo.GetProcSpell();
        if (!procSpell)
            return false;

        Optional<int32> comboPoints = procSpell->GetPowerTypeCostAmount(POWER_COMBO_POINTS);
        if (!comboPoints)
            return false;

        return roll_chance_i(*comboPoints * aurEff->GetAmount());
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_sudden_ambush::CheckProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

//  93402 - Sunfire
class spell_dru_sunfire : public SpellScript
{
    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DRUID_SUNFIRE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_sunfire::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 61336 - Survival Instincts
class spell_dru_survival_instincts : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SURVIVAL_INSTINCTS });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_SURVIVAL_INSTINCTS, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_survival_instincts::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 40121 - Swift Flight Form (Passive)
class spell_dru_swift_flight_passive : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            if (caster->GetSkillValue(SKILL_RIDING) >= 375)
                amount = 310;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
    }
};

// 28744 - Regrowth
class spell_dru_t3_6p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BLESSING_OF_THE_CLAW });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_BLESSING_OF_THE_CLAW, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_t3_6p_bonus::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
    }
};

// 28719 - Healing Touch
class spell_dru_t3_8p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_EXHILARATE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Spell const* spell = eventInfo.GetProcSpell();
        if (!spell)
            return;

        Unit* caster = eventInfo.GetActor();
        std::vector<SpellPowerCost> const& costs = spell->GetPowerCost();
        auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
        if (m == costs.end())
            return;

        int32 amount = CalculatePct(m->Amount, aurEff->GetAmount());
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(nullptr, SPELL_DRUID_EXHILARATE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_t3_8p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 37288 - Mana Restore
// 37295 - Mana Restore
class spell_dru_t4_2p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_INFUSION });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_DRUID_INFUSION, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_t4_2p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 70723 - Item - Druid T10 Balance 4P Bonus
class spell_dru_t10_balance_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_LANGUISH });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DRUID_LANGUISH, GetCastDifficulty());
        int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, amount);
        caster->CastSpell(target, SPELL_DRUID_LANGUISH, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_t10_balance_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 70691 - Item T10 Restoration 4P Bonus
class spell_dru_t10_restoration_4p_bonus : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetCaster()->ToPlayer()->GetGroup())
        {
            targets.clear();
            targets.push_back(GetCaster());
        }
        else
        {
            targets.remove(GetExplTargetUnit());
            std::list<Unit*> tempTargets;
            for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                if ((*itr)->GetTypeId() == TYPEID_PLAYER && GetCaster()->IsInRaidWith((*itr)->ToUnit()))
                    tempTargets.push_back((*itr)->ToUnit());

            if (tempTargets.empty())
            {
                targets.clear();
                FinishCast(SPELL_FAILED_DONT_REPORT);
                return;
            }

            Unit* target = Trinity::Containers::SelectRandomContainerElement(tempTargets);
            targets.clear();
            targets.push_back(target);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_t10_restoration_4p_bonus::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 70664 - Druid T10 Restoration 4P Bonus (Rejuvenation)
class spell_dru_t10_restoration_4p_bonus_dummy : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_REJUVENATION_T10_PROC });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || spellInfo->Id == SPELL_DRUID_REJUVENATION_T10_PROC)
            return false;

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return false;

        Player* caster = eventInfo.GetActor()->ToPlayer();
        if (!caster)
            return false;

        return caster->GetGroup() || caster != eventInfo.GetProcTarget();
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, eventInfo.GetHealInfo()->GetHeal());
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_DRUID_REJUVENATION_T10_PROC, args);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_t10_restoration_4p_bonus_dummy::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_t10_restoration_4p_bonus_dummy::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77758 - Thrash
class spell_dru_thrash : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_THRASH_BEAR_AURA });
    }

    void HandleOnHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
        {
            Unit* caster = GetCaster();

            caster->CastSpell(hitUnit, SPELL_DRUID_THRASH_BEAR_AURA, TRIGGERED_FULL_MASK);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_thrash::HandleOnHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 192090 - Thrash (Aura) - SPELL_DRUID_THRASH_BEAR_AURA
class spell_dru_thrash_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BLOOD_FRENZY_AURA, SPELL_DRUID_BLOOD_FRENZY_RAGE_GAIN });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (caster->HasAura(SPELL_DRUID_BLOOD_FRENZY_AURA))
                caster->CastSpell(caster, SPELL_DRUID_BLOOD_FRENZY_RAGE_GAIN, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_thrash_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 1066 - Aquatic Form
// 33943 - Flight Form
// 40120 - Swift Flight Form
// 165961 - Stag Form
class spell_dru_travel_form : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_FORM_STAG, SPELL_DRUID_FORM_AQUATIC_PASSIVE, SPELL_DRUID_FORM_AQUATIC, SPELL_DRUID_FORM_FLIGHT, SPELL_DRUID_FORM_SWIFT_FLIGHT });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // If it stays 0, it removes Travel Form dummy in AfterRemove.
        triggeredSpellId = 0;

        // We should only handle aura interrupts.
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_INTERRUPT)
            return;

        // Check what form is appropriate
        triggeredSpellId = GetFormSpellId(GetTarget()->ToPlayer(), GetCastDifficulty(), true);

        // If chosen form is current aura, just don't remove it.
        if (triggeredSpellId == m_scriptSpellId)
            PreventDefaultAction();
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (triggeredSpellId == m_scriptSpellId)
            return;

        Player* player = GetTarget()->ToPlayer();

        if (triggeredSpellId) // Apply new form
            player->CastSpell(player, triggeredSpellId, aurEff);
        else // If not set, simply remove Travel Form dummy
            player->RemoveAura(SPELL_DRUID_TRAVEL_FORM);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form::OnRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
    }

public:
    static uint32 GetFormSpellId(Player const* player, Difficulty difficulty, bool requiresOutdoor)
    {
        // Check what form is appropriate
        if (player->HasSpell(SPELL_DRUID_FORM_AQUATIC_PASSIVE) && player->IsInWater()) // Aquatic form
            return SPELL_DRUID_FORM_AQUATIC;

        if (!player->IsInCombat() && player->GetSkillValue(SKILL_RIDING) >= 225 && CheckLocationForForm(player, difficulty, requiresOutdoor, SPELL_DRUID_FORM_FLIGHT) == SPELL_CAST_OK) // Flight form
            return player->GetSkillValue(SKILL_RIDING) >= 300 ? SPELL_DRUID_FORM_SWIFT_FLIGHT : SPELL_DRUID_FORM_FLIGHT;

        if (!player->IsInWater() && CheckLocationForForm(player, difficulty, requiresOutdoor, SPELL_DRUID_FORM_STAG) == SPELL_CAST_OK) // Stag form
            return SPELL_DRUID_FORM_STAG;

        return 0;
    }

private:
    static SpellCastResult CheckLocationForForm(Player const* targetPlayer, Difficulty difficulty, bool requireOutdoors, uint32 spell_id)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id, difficulty);

        if (requireOutdoors && !targetPlayer->IsOutdoors())
            return SPELL_FAILED_ONLY_OUTDOORS;

        return spellInfo->CheckLocation(targetPlayer->GetMapId(), targetPlayer->GetZoneId(), targetPlayer->GetAreaId(), targetPlayer);
    }

    uint32 triggeredSpellId = 0;
};

// 783 - Travel Form (dummy)
class spell_dru_travel_form_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_FORM_AQUATIC_PASSIVE, SPELL_DRUID_FORM_AQUATIC, SPELL_DRUID_FORM_STAG });
    }

    SpellCastResult CheckCast()
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return SPELL_FAILED_CUSTOM_ERROR;

        uint32 spellId = (player->HasSpell(SPELL_DRUID_FORM_AQUATIC_PASSIVE) && player->IsInWater()) ? SPELL_DRUID_FORM_AQUATIC : SPELL_DRUID_FORM_STAG;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, GetCastDifficulty());
        return spellInfo->CheckLocation(player->GetMapId(), player->GetZoneId(), player->GetAreaId(), player);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dru_travel_form_dummy::CheckCast);
    }
};

class spell_dru_travel_form_dummy_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_FORM_STAG, SPELL_DRUID_FORM_AQUATIC, SPELL_DRUID_FORM_FLIGHT, SPELL_DRUID_FORM_SWIFT_FLIGHT });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Player* player = GetTarget()->ToPlayer();

        // Outdoor check already passed - Travel Form (dummy) has SPELL_ATTR0_OUTDOORS_ONLY attribute.
        uint32 triggeredSpellId = spell_dru_travel_form::GetFormSpellId(player, GetCastDifficulty(), false);

        player->CastSpell(player, triggeredSpellId, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // No need to check remove mode, it's safe for auras to remove each other in AfterRemove hook.
        GetTarget()->RemoveAura(SPELL_DRUID_FORM_STAG);
        GetTarget()->RemoveAura(SPELL_DRUID_FORM_AQUATIC);
        GetTarget()->RemoveAura(SPELL_DRUID_FORM_FLIGHT);
        GetTarget()->RemoveAura(SPELL_DRUID_FORM_SWIFT_FLIGHT);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_dru_travel_form_dummy_aura::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_travel_form_dummy_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 252216 - Tiger Dash
class spell_dru_tiger_dash : public spell_dru_base_transformer
{
protected:
    bool ToCatForm() const override { return true; }
};

// 252216 - Tiger Dash (Aura)
class spell_dru_tiger_dash_aura : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (AuraEffect* effRunSpeed = GetEffect(EFFECT_0))
        {
            int32 reduction = aurEff->GetAmount();
            effRunSpeed->ChangeAmount(effRunSpeed->GetAmount() - reduction);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_tiger_dash_aura::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 48438 - Wild Growth
class spell_dru_wild_growth : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 }, { SPELL_DRUID_TREE_OF_LIFE, EFFECT_2 } });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        Unit* caster = GetCaster();
        int32 maxTargets = GetEffectInfo(EFFECT_1).CalcValue(caster);

        if (AuraEffect const* treeOfLife = caster->GetAuraEffect(SPELL_DRUID_TREE_OF_LIFE, EFFECT_2))
            maxTargets += treeOfLife->GetAmount();

        // Note: Wild Growth became a smart heal which prioritizes players and their pets in their group before any unit outside their group.
        Trinity::SelectRandomInjuredTargets(targets, maxTargets, true, caster);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

class spell_dru_wild_growth_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_RESTORATION_T10_2P_BONUS });
    }

    void HandleTickUpdate(AuraEffect* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // calculate from base damage, not from aurEff->GetAmount() (already modified)
        float damage = caster->CalculateSpellDamage(GetUnitOwner(), aurEff->GetSpellEffectInfo());

        // Wild Growth = first tick gains a 6% bonus, reduced by 2% each tick
        float reduction = 2.f;
        if (AuraEffect* bonus = caster->GetAuraEffect(SPELL_DRUID_RESTORATION_T10_2P_BONUS, EFFECT_0))
            reduction -= CalculatePct(reduction, bonus->GetAmount());
        reduction *= (aurEff->GetTickNumber() - 1);

        AddPct(damage, 6.f - reduction);
        aurEff->SetAmount(int32(damage));
    }

    void Register() override
    {
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_dru_wild_growth_aura::HandleTickUpdate, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

// 145108 - Ysera's Gift
class spell_dru_yseras_gift : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_DRUID_YSERAS_GIFT_HEAL_SELF,
            SPELL_DRUID_YSERAS_GIFT_HEAL_PARTY
        });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        int32 healAmount = int32(GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount()));

        if (!GetTarget()->IsFullHealth())
            GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_YSERAS_GIFT_HEAL_SELF, CastSpellExtraArgs(aurEff).AddSpellBP0(healAmount));
        else
            GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_YSERAS_GIFT_HEAL_PARTY, CastSpellExtraArgs(aurEff).AddSpellBP0(healAmount));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_yseras_gift::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 145110 - Ysera's Gift (heal)
class spell_dru_yseras_gift_group_heal : public SpellScript
{
    void SelectTargets(std::list<WorldObject*>& targets)
    {
        Trinity::SelectRandomInjuredTargets(targets, 1, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_yseras_gift_group_heal::SelectTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
    }
};

void AddSC_druid_spell_scripts()
{
    RegisterSpellScript(spell_dru_abundance);
    RegisterSpellScript(spell_dru_astral_communion_celestial_alignment);
    RegisterSpellScript(spell_dru_astral_smolder);
    RegisterSpellScript(spell_dru_barkskin);
    RegisterSpellScript(spell_dru_berserk);
    RegisterSpellScript(spell_dru_brambles);
    RegisterSpellScript(spell_dru_bristling_fur);
    RegisterSpellScript(spell_dru_cat_form);
    RegisterSpellScript(spell_dru_celestial_alignment);
    RegisterSpellScript(spell_dru_cultivation);
    RegisterSpellScript(spell_dru_dash);
    RegisterSpellScript(spell_dru_earthwarden);
    RegisterSpellScript(spell_dru_eclipse_aura);
    RegisterSpellScript(spell_dru_eclipse_dummy);
    RegisterSpellScript(spell_dru_eclipse_ooc);
    RegisterSpellScript(spell_dru_efflorescence);
    RegisterSpellScript(spell_dru_efflorescence_dummy);
    RegisterSpellScript(spell_dru_efflorescence_heal);
    RegisterSpellScript(spell_dru_embrace_of_the_dream);
    RegisterSpellScript(spell_dru_embrace_of_the_dream_effect);
    RegisterSpellAndAuraScriptPair(spell_dru_entangling_roots, spell_dru_entangling_roots_aura);
    RegisterSpellScript(spell_dru_ferocious_bite);
    RegisterSpellScript(spell_dru_forms_trinket);
    RegisterSpellScript(spell_dru_galactic_guardian);
    RegisterSpellScript(spell_dru_germination);
    RegisterSpellScript(spell_dru_glyph_of_stars);
    RegisterSpellScript(spell_dru_gore);
    RegisterSpellScript(spell_dru_incapacitating_roar);
    RegisterSpellScript(spell_dru_incarnation);
    RegisterSpellScript(spell_dru_incarnation_tree_of_life);
    RegisterSpellScript(spell_dru_inner_peace);
    RegisterSpellScript(spell_dru_innervate);
    RegisterSpellScript(spell_dru_item_t6_trinket);
    RegisterSpellScript(spell_dru_lifebloom);
    RegisterSpellScript(spell_dru_lunar_inspiration);
    RegisterSpellScript(spell_dru_luxuriant_soil);
    RegisterSpellScript(spell_dru_moonfire);
    RegisterSpellScript(spell_dru_natures_grace);
    RegisterSpellScript(spell_dru_natures_grace_eclipse);
    RegisterSpellScriptWithArgs(spell_dru_new_moon, "spell_dru_full_moon", Optional<DruidSpells>(), Optional<DruidSpells>(SPELL_DRUID_HALF_MOON_OVERRIDE));
    RegisterSpellScriptWithArgs(spell_dru_new_moon, "spell_dru_half_moon", Optional<DruidSpells>(SPELL_DRUID_HALF_MOON_OVERRIDE), Optional<DruidSpells>(SPELL_DRUID_NEW_MOON_OVERRIDE));
    RegisterSpellScriptWithArgs(spell_dru_new_moon, "spell_dru_new_moon", Optional<DruidSpells>(SPELL_DRUID_NEW_MOON_OVERRIDE), Optional<DruidSpells>());
    RegisterSpellScript(spell_dru_omen_of_clarity);
    RegisterSpellScript(spell_dru_omen_of_clarity_restoration);
    RegisterSpellScript(spell_dru_power_of_the_archdruid);
    RegisterSpellScript(spell_dru_prowl);
    RegisterSpellScript(spell_dru_rip);
    RegisterSpellAndAuraScriptPair(spell_dru_savage_roar, spell_dru_savage_roar_aura);
    RegisterSpellScript(spell_dru_shooting_stars);
    RegisterSpellScript(spell_dru_skull_bash);
    RegisterSpellScript(spell_dru_spring_blossoms);
    RegisterSpellScript(spell_dru_stampeding_roar);
    RegisterSpellScript(spell_dru_starfall_dummy);
    RegisterSpellScript(spell_dru_stellar_flare);
    RegisterSpellScript(spell_dru_sudden_ambush);
    RegisterSpellScript(spell_dru_sunfire);
    RegisterSpellScript(spell_dru_survival_instincts);
    RegisterSpellScript(spell_dru_swift_flight_passive);
    RegisterSpellScript(spell_dru_t3_6p_bonus);
    RegisterSpellScript(spell_dru_t3_8p_bonus);
    RegisterSpellScript(spell_dru_t4_2p_bonus);
    RegisterSpellScript(spell_dru_t10_balance_4p_bonus);
    RegisterSpellScript(spell_dru_t10_restoration_4p_bonus);
    RegisterSpellScript(spell_dru_t10_restoration_4p_bonus_dummy);
    RegisterSpellScript(spell_dru_thrash);
    RegisterSpellScript(spell_dru_thrash_aura);
    RegisterSpellScript(spell_dru_travel_form);
    RegisterSpellAndAuraScriptPair(spell_dru_travel_form_dummy, spell_dru_travel_form_dummy_aura);
    RegisterSpellAndAuraScriptPair(spell_dru_tiger_dash, spell_dru_tiger_dash_aura);
    RegisterSpellAndAuraScriptPair(spell_dru_wild_growth, spell_dru_wild_growth_aura);
    RegisterSpellScript(spell_dru_yseras_gift);
    RegisterSpellScript(spell_dru_yseras_gift_group_heal);
}
