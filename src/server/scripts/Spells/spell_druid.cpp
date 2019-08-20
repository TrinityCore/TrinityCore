/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Containers.h"
#include "GameTime.h"
#include "Optional.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DruidSpells
{
    SPELL_DRUID_BEAR_FORM_PASSIVE           = 1178,
    SPELL_DRUID_DIRE_BEAR_FORM_PASSIVE      = 9635,
    SPELL_DRUID_ECLIPSE_LUNAR_PROC          = 48518,
    SPELL_DRUID_ECLIPSE_SOLAR_PROC          = 48517,
    SPELL_DRUID_FORMS_TRINKET_BEAR          = 37340,
    SPELL_DRUID_FORMS_TRINKET_CAT           = 37341,
    SPELL_DRUID_FORMS_TRINKET_MOONKIN       = 37343,
    SPELL_DRUID_FORMS_TRINKET_NONE          = 37344,
    SPELL_DRUID_FORMS_TRINKET_TREE          = 37342,
    SPELL_DRUID_ENRAGE                      = 5229,
    SPELL_DRUID_ENRAGE_MOD_DAMAGE           = 51185,
    SPELL_DRUID_ENRAGED_DEFENSE             = 70725,
    SPELL_DRUID_GLYPH_OF_TYPHOON            = 62135,
    SPELL_DRUID_IDOL_OF_FERAL_SHADOWS       = 34241,
    SPELL_DRUID_IDOL_OF_WORSHIP             = 60774,
    SPELL_DRUID_INCREASED_MOONFIRE_DURATION = 38414,
    SPELL_DRUID_ITEM_T8_BALANCE_RELIC       = 64950,
    SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS     = 70726,
    SPELL_DRUID_KING_OF_THE_JUNGLE          = 48492,
    SPELL_DRUID_LIFEBLOOM_ENERGIZE          = 64372,
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL        = 33778,
    SPELL_DRUID_LIVING_SEED_HEAL            = 48503,
    SPELL_DRUID_LIVING_SEED_PROC            = 48504,
    SPELL_DRUID_NATURES_SPLENDOR            = 57865,
    SPELL_DRUID_SURVIVAL_INSTINCTS          = 50322,
    SPELL_DRUID_SAVAGE_ROAR                 = 62071,
    SPELL_DRUID_T9_FERAL_RELIC_BEAR         = 67354,
    SPELL_DRUID_T9_FERAL_RELIC_CAT          = 67355,
    SPELL_DRUID_TIGER_S_FURY_ENERGIZE       = 51178,
    SPELL_DRUID_T3_PROC_ENERGIZE_MANA       = 28722,
    SPELL_DRUID_T3_PROC_ENERGIZE_RAGE       = 28723,
    SPELL_DRUID_T3_PROC_ENERGIZE_ENERGY     = 28724,
    SPELL_DRUID_BLESSING_OF_THE_CLAW        = 28750,
    SPELL_DRUID_REVITALIZE_ENERGIZE_MANA    = 48542,
    SPELL_DRUID_REVITALIZE_ENERGIZE_RAGE    = 48541,
    SPELL_DRUID_REVITALIZE_ENERGIZE_ENERGY  = 48540,
    SPELL_DRUID_REVITALIZE_ENERGIZE_RP      = 48543,
    SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN    = 54833,
    SPELL_DRUID_GLYPH_OF_STARFIRE_SCRIPT    = 54846,
    SPELL_DRUID_GLYPH_OF_RIP                = 54818,
    SPELL_DRUID_RIP_DURATION_LACERATE_DMG   = 60141,
    SPELL_DRUID_GLYPH_OF_RAKE_TRIGGERED     = 54820,
    SPELL_DRUID_IMP_LEADER_OF_THE_PACK_R1   = 34297,
    SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL = 34299,
    SPELL_DRUID_IMP_LEADER_OF_THE_PACK_MANA = 68285,
    SPELL_DRUID_EXHILARATE                  = 28742,
    SPELL_DRUID_GLYPH_OF_REJUVENATION_HEAL  = 54755,
    SPELL_DRUID_INFUSION                    = 37238,
    SPELL_DRUID_BLESSING_OF_REMULOS         = 40445,
    SPELL_DRUID_BLESSING_OF_ELUNE           = 40446,
    SPELL_DRUID_BLESSING_OF_CENARIUS        = 40452,
    SPELL_DRUID_LANGUISH                    = 71023,
    SPELL_DRUID_REJUVENATION_T10_PROC       = 70691,
    SPELL_DRUID_BALANCE_T10_BONUS           = 70718,
    SPELL_DRUID_BALANCE_T10_BONUS_PROC      = 70721,
    SPELL_DRUID_BARKSKIN_01                 = 63058,
    SPELL_DRUID_RESTORATION_T10_2P_BONUS    = 70658,
    SPELL_DRUID_FRENZIED_REGENERATION_HEAL  = 22845
};

enum MiscSpells
{
    SPELL_CATEGORY_MANGLE_BEAR              = 971
};

// 22812 - Barkskin
class spell_dru_barkskin : public AuraScript
{
    PrepareAuraScript(spell_dru_barkskin);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BARKSKIN_01 });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_BARKSKIN_01);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_barkskin::OnRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1178 - Bear Form (Passive)
// 9635 - Dire Bear Form (Passive)
class spell_dru_bear_form_passive : public AuraScript
{
    PrepareAuraScript(spell_dru_bear_form_passive);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
                {
                    SPELL_DRUID_ENRAGE,
                    SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS
                });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (!GetUnitOwner()->HasAura(SPELL_DRUID_ENRAGE) || GetUnitOwner()->HasAura(SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS))
            return;

        int32 mod = 0;
        switch (GetId())
        {
            case SPELL_DRUID_BEAR_FORM_PASSIVE:
                mod = -27;
                break;
            case SPELL_DRUID_DIRE_BEAR_FORM_PASSIVE:
                mod = -16;
                break;
            default:
                return;
        }
        amount += mod;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_bear_form_passive::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_BASE_RESISTANCE_PCT);
    }
};

// 50334 - Berserk
class spell_dru_berserk : public AuraScript
{
    PrepareAuraScript(spell_dru_berserk);

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Remove cooldown on Mangle (bear)
        GetTarget()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
            return spellInfo && spellInfo->GetCategory() == SPELL_CATEGORY_MANGLE_BEAR;
        }, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_berserk::HandleEffectApply, EFFECT_1, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// -1850 - Dash
class spell_dru_dash : public AuraScript
{
    PrepareAuraScript(spell_dru_dash);

    void CalculateAmount(AuraEffect const*  /*aurEff*/, int32 &amount, bool & /*canBeRecalculated*/)
    {
        // do not set speed if not in cat form
        if (GetUnitOwner()->GetShapeshiftForm() != FORM_CAT)
            amount = 0;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_dash::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
    }
};

// -48516 - Eclipse
class spell_dru_eclipse : public AuraScript 
{
    PrepareAuraScript(spell_dru_eclipse);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
                {
                        SPELL_DRUID_ECLIPSE_LUNAR_PROC,
                        SPELL_DRUID_ECLIPSE_SOLAR_PROC
                });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetActor()->HasAura(SPELL_DRUID_ECLIPSE_LUNAR_PROC) || eventInfo.GetActor()->HasAura(SPELL_DRUID_ECLIPSE_SOLAR_PROC))
            return false;

        return true;
    }

    bool CheckSolar(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || !(spellInfo->SpellFamilyFlags[0] & 4)) // Starfire
            return false;

        return _solarProcCooldownEnd <= GameTime::GetGameTimeSteadyPoint();
    }

    bool CheckLunar(AuraEffect const*  /*aurEff*/, ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || !(spellInfo->SpellFamilyFlags[0] & 1)) // Wrath
            return false;

        // Reduced lunar proc chance (60% of normal)
        if (!roll_chance_i(60))
            return false;

        return _lunarProcCooldownEnd <= GameTime::GetGameTimeSteadyPoint();
    }

    void ProcSolar(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        _solarProcCooldownEnd = GameTime::GetGameTimeSteadyPoint() + Seconds(30);
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_DRUID_ECLIPSE_SOLAR_PROC, aurEff);
    }

    void ProcLunar(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        _lunarProcCooldownEnd = GameTime::GetGameTimeSteadyPoint() + Seconds(30);
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_DRUID_ECLIPSE_LUNAR_PROC, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_eclipse::CheckProc);

        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_eclipse::CheckSolar, EFFECT_0, SPELL_AURA_DUMMY);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_dru_eclipse::CheckLunar, EFFECT_1, SPELL_AURA_DUMMY);

        OnEffectProc += AuraEffectProcFn(spell_dru_eclipse::ProcSolar, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_eclipse::ProcLunar, EFFECT_1, SPELL_AURA_DUMMY);
    }

    std::chrono::steady_clock::time_point _lunarProcCooldownEnd = std::chrono::steady_clock::time_point::min();
    std::chrono::steady_clock::time_point _solarProcCooldownEnd = std::chrono::steady_clock::time_point::min();
};

// 5229 - Enrage
class spell_dru_enrage : public AuraScript
{
    PrepareAuraScript(spell_dru_enrage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
                {
                        SPELL_DRUID_KING_OF_THE_JUNGLE,
                        SPELL_DRUID_ENRAGE_MOD_DAMAGE,
                        SPELL_DRUID_ENRAGED_DEFENSE,
                        SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS
                });
    }

    void RecalculateBaseArmor()
    {
        // Recalculate modifies the list while we're iterating through it, so let's copy it instead
        Unit::AuraEffectList const& auras = GetTarget()->GetAuraEffectsByType(SPELL_AURA_MOD_BASE_RESISTANCE_PCT);
        std::vector<AuraEffect*> aurEffs(auras.begin(), auras.end());

        for (AuraEffect* aurEff : aurEffs)
        {
            SpellInfo const* spellInfo = aurEff->GetSpellInfo();
            // Dire- / Bear Form (Passive)
            if (spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && spellInfo->SpellFamilyFlags.HasFlag(0x0, 0x0, 0x2))
                aurEff->RecalculateAmount();
        }
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (AuraEffect const* aurEff = target->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_0))
        {
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellBP0(aurEff->GetAmount());
            target->CastSpell(target, SPELL_DRUID_ENRAGE_MOD_DAMAGE, args);
        }

        // Item - Druid T10 Feral 4P Bonus
        if (target->HasAura(SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS))
            target->CastSpell(target, SPELL_DRUID_ENRAGED_DEFENSE, true);

        RecalculateBaseArmor();
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ENRAGE_MOD_DAMAGE);
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ENRAGED_DEFENSE);

        RecalculateBaseArmor();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_enrage::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_enrage::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 37336 - Druid Forms Trinket
class spell_dru_forms_trinket : public AuraScript
{
    PrepareAuraScript(spell_dru_forms_trinket);

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
            case FORM_BEAR:
            case FORM_DIREBEAR:
            case FORM_CAT:
            case FORM_MOONKIN:
            case FORM_NONE:
            case FORM_TREE:
                return true;
            default:
                break;
        }

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = eventInfo.GetActor();
        uint32 triggerspell = 0;

        switch (target->GetShapeshiftForm())
        {
            case FORM_BEAR:
            case FORM_DIREBEAR:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_BEAR;
                break;
            case FORM_CAT:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_CAT;
                break;
            case FORM_MOONKIN:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_MOONKIN;
                break;
            case FORM_NONE:
                triggerspell = SPELL_DRUID_FORMS_TRINKET_NONE;
                break;
            case FORM_TREE:
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

// -33943 - Flight Form
class spell_dru_flight_form : public SpellScript
{
    PrepareSpellScript(spell_dru_flight_form);

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->IsInDisallowedMountForm())
            return SPELL_FAILED_NOT_SHAPESHIFT;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dru_flight_form::CheckCast);
    }
};

// 22842 - Frenzied Regeneration
class spell_dru_frenzied_regeneration : public AuraScript
{
    PrepareAuraScript(spell_dru_frenzied_regeneration);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_FRENZIED_REGENERATION_HEAL });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        // Converts up to 10 rage per second into health for $d.  Each point of rage is converted into ${$m2/10}.1% of max health.
        if (GetTarget()->GetPowerType() != POWER_RAGE)
            return;

        uint32 rage = GetTarget()->GetPower(POWER_RAGE);
        // Nothing to do
        if (!rage)
            return;

        int32 const mod = std::min(static_cast<int32>(rage), 100);
        int32 const regen = CalculatePct(GetTarget()->GetMaxHealth(), GetTarget()->CalculateSpellDamage(GetSpellInfo(), EFFECT_1) * mod / 100.f);
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(regen);
        GetTarget()->CastSpell(nullptr, SPELL_DRUID_FRENZIED_REGENERATION_HEAL, args);
        GetTarget()->SetPower(POWER_RAGE, rage - mod);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_frenzied_regeneration::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 63057 - Glyph of Barkskin
class spell_dru_glyph_of_barkskin : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_barkskin);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BARKSKIN_01 });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_DRUID_BARKSKIN_01, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_barkskin::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 54832 - Glyph of Innervate
class spell_dru_glyph_of_innervate : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_innervate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN);
        int32 amount = CalculatePct(static_cast<int32>(caster->GetCreatePowerValue(POWER_MANA)), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(nullptr, SPELL_DRUID_GLYPH_OF_INNERVATE_REGEN, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_innervate::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 54821 - Glyph of Rake
class spell_dru_glyph_of_rake : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_rake);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_RAKE_TRIGGERED });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_RAKE_TRIGGERED, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_glyph_of_rake::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_rake::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 54754 - Glyph of Rejuvenation
class spell_dru_glyph_of_rejuvenation : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_rejuvenation);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_REJUVENATION_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget()->HealthBelowPct(50);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(healInfo->GetHeal(), aurEff->GetAmount()));
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_REJUVENATION_HEAL, args);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_glyph_of_rejuvenation::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_rejuvenation::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 54815 - Glyph of Shred
class spell_dru_glyph_of_shred : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_shred);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
                {
                        SPELL_DRUID_GLYPH_OF_RIP,
                        SPELL_DRUID_RIP_DURATION_LACERATE_DMG
                });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        // try to find spell Rip on the target
        if (AuraEffect const* rip = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00800000, 0x0, 0x0, caster->GetGUID()))
        {
            // Rip's max duration, note: spells which modifies Rip's duration also counted like Glyph of Rip
            uint32 countMin = rip->GetBase()->GetMaxDuration();

            // just Rip's max duration without other spells
            uint32 countMax = rip->GetSpellInfo()->GetMaxDuration();

            // add possible auras' and Glyph of Shred's max duration
            countMax += 3 * aurEff->GetAmount() * IN_MILLISECONDS;                                          // Glyph of Shred               -> +6 seconds
            countMax += caster->HasAura(SPELL_DRUID_GLYPH_OF_RIP) ? 4 * IN_MILLISECONDS : 0;                // Glyph of Rip                 -> +4 seconds
            countMax += caster->HasAura(SPELL_DRUID_RIP_DURATION_LACERATE_DMG) ? 4 * IN_MILLISECONDS : 0;   // T7 set bonus                 -> +4 seconds

            // if min < max -> that means caster didn't cast 3 shred yet
            // so set Rip's duration and max duration
            if (countMin < countMax)
            {
                rip->GetBase()->SetDuration(rip->GetBase()->GetDuration() + aurEff->GetAmount() * IN_MILLISECONDS);
                rip->GetBase()->SetMaxDuration(countMin + aurEff->GetAmount() * IN_MILLISECONDS);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_shred::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 54846 - Glyph of Starfire
class spell_dru_glyph_of_starfire : public SpellScript
{
    PrepareSpellScript(spell_dru_glyph_of_starfire);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_INCREASED_MOONFIRE_DURATION, SPELL_DRUID_NATURES_SPLENDOR });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            if (AuraEffect const* aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00000002, 0, 0, caster->GetGUID()))
            {
                Aura* aura = aurEff->GetBase();

                uint32 countMin = aura->GetMaxDuration();
                uint32 countMax = aura->GetSpellInfo()->GetMaxDuration() + 9000;
                if (caster->HasAura(SPELL_DRUID_INCREASED_MOONFIRE_DURATION))
                    countMax += 3000;
                if (caster->HasAura(SPELL_DRUID_NATURES_SPLENDOR))
                    countMax += 3000;

                if (countMin < countMax)
                {
                    aura->SetDuration(uint32(aura->GetDuration() + 3000));
                    aura->SetMaxDuration(countMin + 3000);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_glyph_of_starfire::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 54845 - Glyph of Starfire
class spell_dru_glyph_of_starfire_dummy : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_starfire_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_STARFIRE_SCRIPT });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_STARFIRE_SCRIPT, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_starfire_dummy::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 34246 - Idol of the Emerald Queen
// 60779 - Idol of Lush Moss
class spell_dru_idol_lifebloom : public AuraScript
{
    PrepareAuraScript(spell_dru_idol_lifebloom);

    void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
    {
        if (!spellMod)
        {
            spellMod = new SpellModifier(GetAura());
            spellMod->op = SPELLMOD_DOT;
            spellMod->type = SPELLMOD_FLAT;
            spellMod->spellId = GetId();
            spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
        }
        spellMod->value = aurEff->GetAmount() / 7;
    }

    void Register() override
    {
        DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_dru_idol_lifebloom::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 29166 - Innervate
class spell_dru_innervate : public AuraScript
{
    PrepareAuraScript(spell_dru_innervate);

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (!aurEff->GetTotalTicks())
        {
            amount = 0;
            return;
        }

        if (Unit* caster = GetCaster())
            amount = int32(CalculatePct(caster->GetCreatePowerValue(POWER_MANA), amount) / aurEff->GetTotalTicks());
        else
            amount = 0;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_innervate::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

// -5570 - Insect Swarm
class spell_dru_insect_swarm : public AuraScript
{
    PrepareAuraScript(spell_dru_insect_swarm);

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (!aurEff->GetTotalTicks())
            return;

        if (Unit* caster = GetCaster())
            if (AuraEffect const* relicAurEff = caster->GetAuraEffect(SPELL_DRUID_ITEM_T8_BALANCE_RELIC, EFFECT_0))
                amount += relicAurEff->GetAmount() / aurEff->GetTotalTicks();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_insect_swarm::CalculateAmount, EFFECT_0,SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 24932 - Leader of the Pack
class spell_dru_leader_of_the_pack : public AuraScript
{
    PrepareAuraScript(spell_dru_leader_of_the_pack);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
                {
                        SPELL_DRUID_IMP_LEADER_OF_THE_PACK_R1,
                        SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL,
                        SPELL_DRUID_IMP_LEADER_OF_THE_PACK_MANA
                });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (!aurEff->GetAmount())
            return;

        Unit* caster = eventInfo.GetActor();
        if (caster->GetSpellHistory()->HasCooldown(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL))
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(caster->CountPctFromMaxHealth(aurEff->GetAmount()));
        caster->CastSpell(nullptr, SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL, args);

        // Because of how proc system works, we can't store proc cd on db, it would be applied to entire aura
        // so aura could only proc once per 6 seconds, independently of caster
        caster->GetSpellHistory()->AddCooldown(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_HEAL, 0, Seconds(6));

        // only proc on self
        if (aurEff->GetCasterGUID() != caster->GetGUID())
            return;

        AuraEffect const* impLotpMana = caster->GetAuraEffectOfRankedSpell(SPELL_DRUID_IMP_LEADER_OF_THE_PACK_R1, EFFECT_0, aurEff->GetCasterGUID());
                ASSERT(impLotpMana);

        CastSpellExtraArgs args2(aurEff);
        args2.AddSpellBP0(CalculatePct(caster->GetMaxPower(POWER_MANA), impLotpMana->GetSpellInfo()->Effects[EFFECT_1].CalcValue()));
        caster->CastSpell(nullptr, SPELL_DRUID_IMP_LEADER_OF_THE_PACK_MANA, args2);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_leader_of_the_pack::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// -33763 - Lifebloom
class spell_dru_lifebloom : public AuraScript
{
    PrepareAuraScript(spell_dru_lifebloom);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
                {
                        SPELL_DRUID_LIFEBLOOM_FINAL_HEAL,
                        SPELL_DRUID_LIFEBLOOM_ENERGIZE
                });
    }

    void OnRemoveEffect(Unit* target, AuraEffect const* aurEff, uint32 stack)
    {
        int32 healAmount = aurEff->GetAmount();
        if (Unit* caster = GetCaster())
        {
            // restore mana
            CastSpellExtraArgs args(aurEff);
            args.OriginalCaster = GetCasterGUID();
            args.AddSpellBP0(CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * stack / 2);
            caster->CastSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, args);
        }

        CastSpellExtraArgs args(aurEff);
        args.OriginalCaster = GetCasterGUID();
        args.AddSpellBP0(healAmount);
        target->CastSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, args);
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // Final heal only on duration end
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        // final heal
        OnRemoveEffect(GetUnitOwner(), aurEff, GetStackAmount());
    }

    void HandleDispel(DispelInfo* dispelInfo)
    {
        if (Unit* target = GetUnitOwner())
            if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                OnRemoveEffect(target, aurEff, dispelInfo->GetRemovedCharges()); // final heal
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_lifebloom::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterDispel += AuraDispelFn(spell_dru_lifebloom::HandleDispel);
    }
};

// -48496 - Living Seed
class spell_dru_living_seed : public AuraScript
{
    PrepareAuraScript(spell_dru_living_seed);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({SPELL_DRUID_LIVING_SEED_PROC});
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(healInfo->GetHeal(), aurEff->GetAmount()));
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_LIVING_SEED_PROC, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_living_seed::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 48504 - Living Seed (Proc)
class spell_dru_living_seed_proc : public AuraScript
{
    PrepareAuraScript(spell_dru_living_seed_proc);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({SPELL_DRUID_LIVING_SEED_HEAL});
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(aurEff->GetAmount());
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_LIVING_SEED_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 69366 - Moonkin Form passive
class spell_dru_moonkin_form_passive : public AuraScript
{
    PrepareAuraScript(spell_dru_moonkin_form_passive);

public:
    spell_dru_moonkin_form_passive()
    {
        absorbPct = 0;
    }

private:
    uint32 absorbPct;

    bool Load() override
    {
        absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        // Set absorbtion amount to unlimited
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        // reduces all damage taken while Stunned in Moonkin Form
        if (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_STUNNED) &&
            GetTarget()->HasAuraWithMechanic(1 << MECHANIC_STUN))
            absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_moonkin_form_passive::CalculateAmount, EFFECT_0,
                                                     SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_moonkin_form_passive::Absorb, EFFECT_0);
    }
};

// 16864 - Omen of Clarity
class spell_dru_omen_of_clarity : public AuraScript
{
    PrepareAuraScript(spell_dru_omen_of_clarity);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
                {
                        SPELL_DRUID_BALANCE_T10_BONUS,
                        SPELL_DRUID_BALANCE_T10_BONUS_PROC
                });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DRUID_BALANCE_T10_BONUS))
            target->CastSpell(nullptr, SPELL_DRUID_BALANCE_T10_BONUS_PROC, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_omen_of_clarity::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 48391 - Owlkin Frenzy
class spell_dru_owlkin_frenzy : public SpellScriptLoader
{
    public:
        spell_dru_owlkin_frenzy() : SpellScriptLoader("spell_dru_owlkin_frenzy") { }

        class spell_dru_owlkin_frenzy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_owlkin_frenzy_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = CalculatePct(GetUnitOwner()->GetCreatePowerValue(POWER_MANA), amount);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_owlkin_frenzy_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_PERIODIC_ENERGIZE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_owlkin_frenzy_AuraScript();
        }
};

// -16972 - Predatory Strikes
class spell_dru_predatory_strikes : public SpellScriptLoader
{
    public:
        spell_dru_predatory_strikes() : SpellScriptLoader("spell_dru_predatory_strikes") { }

        class spell_dru_predatory_strikes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_predatory_strikes_AuraScript);

            void UpdateAmount(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* target = GetTarget()->ToPlayer())
                    target->UpdateAttackPowerAndDamage();
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dru_predatory_strikes_AuraScript::UpdateAmount, EFFECT_ALL, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_predatory_strikes_AuraScript();
        }
};

// 33851 - Primal Tenacity
class spell_dru_primal_tenacity : public SpellScriptLoader
{
    public:
        spell_dru_primal_tenacity() : SpellScriptLoader("spell_dru_primal_tenacity") { }

        class spell_dru_primal_tenacity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_primal_tenacity_AuraScript);

        public:
            spell_dru_primal_tenacity_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                // reduces all damage taken while Stunned in Cat Form
                if (GetTarget()->GetShapeshiftForm() == FORM_CAT && GetTarget()->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED) && GetTarget()->HasAuraWithMechanic(1<<MECHANIC_STUN))
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_primal_tenacity_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dru_primal_tenacity_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_primal_tenacity_AuraScript();
        }
};

// -48539 - Revitalize
class spell_dru_revitalize : public SpellScriptLoader
{
    public:
        spell_dru_revitalize() : SpellScriptLoader("spell_dru_revitalize") { }

        class spell_dru_revitalize_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_revitalize_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_DRUID_REVITALIZE_ENERGIZE_MANA,
                    SPELL_DRUID_REVITALIZE_ENERGIZE_RAGE,
                    SPELL_DRUID_REVITALIZE_ENERGIZE_ENERGY,
                    SPELL_DRUID_REVITALIZE_ENERGIZE_RP
                });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (!roll_chance_i(aurEff->GetAmount()))
                    return;

                Unit* target = eventInfo.GetProcTarget();
                uint32 spellId;

                switch (target->GetPowerType())
                {
                    case POWER_MANA:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_MANA;
                        break;
                    case POWER_RAGE:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_RAGE;
                        break;
                    case POWER_ENERGY:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_ENERGY;
                        break;
                    case POWER_RUNIC_POWER:
                        spellId = SPELL_DRUID_REVITALIZE_ENERGIZE_RP;
                        break;
                    default:
                        return;
                }

                eventInfo.GetActor()->CastSpell(target, spellId, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_revitalize_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_revitalize_AuraScript();
        }
};

// -1079 - Rip
class spell_dru_rip : public SpellScriptLoader
{
    public:
        spell_dru_rip() : SpellScriptLoader("spell_dru_rip") { }

        class spell_dru_rip_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_rip_AuraScript);

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
                    uint8 cp = caster->ToPlayer()->GetComboPoints();

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
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_rip_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_rip_AuraScript();
        }
};

// 62600 - Savage Defense
class spell_dru_savage_defense : public SpellScriptLoader
{
    public:
        spell_dru_savage_defense() : SpellScriptLoader("spell_dru_savage_defense") { }

        class spell_dru_savage_defense_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_savage_defense_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), aurEff->GetAmount()));
                caster->CastSpell(nullptr, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, args);
            }

            void Register() override
            {
                 OnEffectProc += AuraEffectProcFn(spell_dru_savage_defense_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_savage_defense_AuraScript();
        }
};

// 52610 - Savage Roar
class spell_dru_savage_roar : public SpellScript
{
    PrepareSpellScript(spell_dru_savage_roar);

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->GetShapeshiftForm() != FORM_CAT)
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
    PrepareAuraScript(spell_dru_savage_roar_aura);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SAVAGE_ROAR });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DRUID_SAVAGE_ROAR, { aurEff, GetCasterGUID() });
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

// -50294 - Starfall (AOE)
class spell_dru_starfall_aoe : public SpellScriptLoader
{
    public:
        spell_dru_starfall_aoe() : SpellScriptLoader("spell_dru_starfall_aoe") { }

        class spell_dru_starfall_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_starfall_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetUnit());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_starfall_aoe_SpellScript();
        }
};

// -50286 - Starfall (Dummy)
class spell_dru_starfall_dummy : public SpellScriptLoader
{
    public:
        spell_dru_starfall_dummy() : SpellScriptLoader("spell_dru_starfall_dummy") { }

        class spell_dru_starfall_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_starfall_dummy_SpellScript);

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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_dummy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_dru_starfall_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_starfall_dummy_SpellScript();
        }
};

// 61336 - Survival Instincts
class spell_dru_survival_instincts : public SpellScript
{
    PrepareSpellScript(spell_dru_survival_instincts);

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (!caster->IsInFeralForm())
            return SPELL_FAILED_ONLY_SHAPESHIFT;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dru_survival_instincts::CheckCast);
    }
};

class spell_dru_survival_instincts_aura : public AuraScript
{
    PrepareAuraScript(spell_dru_survival_instincts_aura);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SURVIVAL_INSTINCTS });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(target->CountPctFromMaxHealth(aurEff->GetAmount()));
        target->CastSpell(target, SPELL_DRUID_SURVIVAL_INSTINCTS, args);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts_aura::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_survival_instincts_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
    }
};

// 40121 - Swift Flight Form (Passive)
class spell_dru_swift_flight_passive : public SpellScriptLoader
{
    public:
        spell_dru_swift_flight_passive() : SpellScriptLoader("spell_dru_swift_flight_passive") { }

        class spell_dru_swift_flight_passive_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_swift_flight_passive_AuraScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
            {
                if (Player* caster = GetCaster()->ToPlayer())
                    if (caster->Has310Flyer(false))
                        amount = 310;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_swift_flight_passive_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_swift_flight_passive_AuraScript();
        }
};

// -5217 - Tiger's Fury
class spell_dru_tiger_s_fury : public SpellScriptLoader
{
    public:
        spell_dru_tiger_s_fury() : SpellScriptLoader("spell_dru_tiger_s_fury") { }

        class spell_dru_tiger_s_fury_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_tiger_s_fury_SpellScript);

            void OnHit()
            {
                if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_1))
                {
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellBP0(aurEff->GetAmount());
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DRUID_TIGER_S_FURY_ENERGIZE, args);
                }
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_dru_tiger_s_fury_SpellScript::OnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_tiger_s_fury_SpellScript();
        }
};

// -61391 - Typhoon
class spell_dru_typhoon : public SpellScriptLoader
{
    public:
        spell_dru_typhoon() : SpellScriptLoader("spell_dru_typhoon") { }

        class spell_dru_typhoon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_typhoon_SpellScript);

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                // Glyph of Typhoon
                if (GetCaster()->HasAura(SPELL_DRUID_GLYPH_OF_TYPHOON))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dru_typhoon_SpellScript::HandleKnockBack, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_typhoon_SpellScript();
        }
};

// 28716 - Rejuvenation
class spell_dru_t3_2p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t3_2p_bonus() : SpellScriptLoader("spell_dru_t3_2p_bonus") { }

        class spell_dru_t3_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_DRUID_T3_PROC_ENERGIZE_MANA,
                    SPELL_DRUID_T3_PROC_ENERGIZE_RAGE,
                    SPELL_DRUID_T3_PROC_ENERGIZE_ENERGY
                });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                if (!roll_chance_i(50))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* target = eventInfo.GetProcTarget();
                uint32 spellId;

                switch (target->GetPowerType())
                {
                    case POWER_MANA:
                        spellId = SPELL_DRUID_T3_PROC_ENERGIZE_MANA;
                        break;
                    case POWER_RAGE:
                        spellId = SPELL_DRUID_T3_PROC_ENERGIZE_RAGE;
                        break;
                    case POWER_ENERGY:
                        spellId = SPELL_DRUID_T3_PROC_ENERGIZE_ENERGY;
                        break;
                    default:
                        return;
                }

                eventInfo.GetActor()->CastSpell(target, spellId, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_t3_2p_bonus_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_2p_bonus_AuraScript();
        }
};

// 28744 - Regrowth
class spell_dru_t3_6p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t3_6p_bonus() : SpellScriptLoader("spell_dru_t3_6p_bonus") { }

        class spell_dru_t3_6p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_6p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_BLESSING_OF_THE_CLAW });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_BLESSING_OF_THE_CLAW, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_6p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_6p_bonus_AuraScript();
        }
};

// 28719 - Healing Touch
class spell_dru_t3_8p_bonus : public SpellScriptLoader
{
        public:
            spell_dru_t3_8p_bonus() : SpellScriptLoader("spell_dru_t3_8p_bonus") { }

        class spell_dru_t3_8p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t3_8p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_EXHILARATE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                Unit* caster = eventInfo.GetActor();
                int32 amount = CalculatePct(spellInfo->CalcPowerCost(caster, spellInfo->GetSchoolMask()), aurEff->GetAmount());
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(amount);
                caster->CastSpell(nullptr, SPELL_DRUID_EXHILARATE, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t3_8p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t3_8p_bonus_AuraScript();
        }
};

// 37288 - Mana Restore
// 37295 - Mana Restore
class spell_dru_t4_2p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t4_2p_bonus() : SpellScriptLoader("spell_dru_t4_2p_bonus") { }

        class spell_dru_t4_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t4_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_INFUSION });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(nullptr, SPELL_DRUID_INFUSION, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t4_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t4_2p_bonus_AuraScript();
        }
};

// 40442 - Druid Tier 6 Trinket
class spell_dru_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_dru_item_t6_trinket() : SpellScriptLoader("spell_dru_item_t6_trinket") { }

        class spell_dru_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({
                    SPELL_DRUID_BLESSING_OF_REMULOS,
                    SPELL_DRUID_BLESSING_OF_ELUNE,
                    SPELL_DRUID_BLESSING_OF_CENARIUS
                });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
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
                OnEffectProc += AuraEffectProcFn(spell_dru_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_item_t6_trinket_AuraScript();
        }
};

// 67353 - T9 Feral Relic (Idol of Mutilation)
class spell_dru_t9_feral_relic : public SpellScriptLoader
{
public:
    spell_dru_t9_feral_relic() : SpellScriptLoader("spell_dru_t9_feral_relic") { }

    class spell_dru_t9_feral_relic_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dru_t9_feral_relic_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_DRUID_T9_FERAL_RELIC_BEAR,
                SPELL_DRUID_T9_FERAL_RELIC_CAT
            });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActor();

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                case FORM_CAT:
                    return true;
                default:
                    break;
            }

            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            uint32 triggerspell = 0;

            Unit* target = eventInfo.GetActor();

            switch (target->GetShapeshiftForm())
            {
                case FORM_BEAR:
                case FORM_DIREBEAR:
                    triggerspell = SPELL_DRUID_T9_FERAL_RELIC_BEAR;
                    break;
                case FORM_CAT:
                    triggerspell = SPELL_DRUID_T9_FERAL_RELIC_CAT;
                    break;
                default:
                    return;
            }

            target->CastSpell(target, triggerspell, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dru_t9_feral_relic_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_dru_t9_feral_relic_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dru_t9_feral_relic_AuraScript();
    }
};

// 70723 - Item - Druid T10 Balance 4P Bonus
class spell_dru_t10_balance_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t10_balance_4p_bonus() : SpellScriptLoader("spell_dru_t10_balance_4p_bonus") { }

        class spell_dru_t10_balance_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t10_balance_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DRUID_LANGUISH });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DRUID_LANGUISH);
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());

                ASSERT(spellInfo->GetMaxTicks() > 0);
                amount /= spellInfo->GetMaxTicks();

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(amount);
                caster->CastSpell(target, SPELL_DRUID_LANGUISH, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dru_t10_balance_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t10_balance_4p_bonus_AuraScript();
        }
};

// 70691 - Item T10 Restoration 4P Bonus
class spell_dru_t10_restoration_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dru_t10_restoration_4p_bonus() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus") { }

        class spell_dru_t10_restoration_4p_bonus_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dru_t10_restoration_4p_bonus_SpellScript);

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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_t10_restoration_4p_bonus_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dru_t10_restoration_4p_bonus_SpellScript();
        }
};

// 70664 - Druid T10 Restoration 4P Bonus (Rejuvenation)
class spell_dru_t10_restoration_4p_bonus_dummy : public SpellScriptLoader
{
    public:
        spell_dru_t10_restoration_4p_bonus_dummy() : SpellScriptLoader("spell_dru_t10_restoration_4p_bonus_dummy") { }

        class spell_dru_t10_restoration_4p_bonus_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript);

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

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(eventInfo.GetHealInfo()->GetHeal());
                eventInfo.GetActor()->CastSpell(nullptr, SPELL_DRUID_REJUVENATION_T10_PROC, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dru_t10_restoration_4p_bonus_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dru_t10_restoration_4p_bonus_dummy_AuraScript();
        }
};

class RaidCheck
{
    public:
        explicit RaidCheck(Unit const* caster) : _caster(caster) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
                return !_caster->IsInRaidWith(target);

            return true;
        }

    private:
        Unit const* _caster;
};

// -48438 - Wild Growth
class spell_dru_wild_growth : public SpellScript
{
    PrepareSpellScript(spell_dru_wild_growth);

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Effects[EFFECT_2].IsEffect() || spellInfo->Effects[EFFECT_2].CalcValue() <= 0)
            return false;
        return true;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaidCheck(GetCaster()));

        uint32 const maxTargets = uint32(GetSpellInfo()->Effects[EFFECT_2].CalcValue(GetCaster()));

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(maxTargets);
        }

        _targets = targets;
    }

    void SetTargets(std::list<WorldObject*>& targets)
    {
        targets = _targets;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth::SetTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }

    std::list<WorldObject*> _targets;
};

class spell_dru_wild_growth_aura : public AuraScript
{
    PrepareAuraScript(spell_dru_wild_growth_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_RESTORATION_T10_2P_BONUS });
    }

    void SetTickHeal(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        // includes caster bonuses already
        _baseTick = amount;
        if (Unit* caster = GetCaster())
            if (AuraEffect const* bonus = caster->GetAuraEffect(SPELL_DRUID_RESTORATION_T10_2P_BONUS, EFFECT_0))
                AddPct(_baseReduction, -bonus->GetAmount());
    }

    void HandleTickUpdate(AuraEffect* aurEff)
    {
        // Wild Growth = first tick gains a 6% bonus, reduced by 2% each tick
        float reduction = _baseReduction;
        reduction *= (aurEff->GetTickNumber() - 1);

        float const bonus = 6.f - reduction;
        int32 const amount = int32(_baseTick + CalculatePct(_baseTick, bonus));
        aurEff->SetAmount(amount);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_wild_growth_aura::SetTickHeal, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_dru_wild_growth_aura::HandleTickUpdate, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }

    float _baseTick = 0.f;
    float _baseReduction = 2.f;
};

void AddSC_druid_spell_scripts()
{
    RegisterAuraScript(spell_dru_barkskin);
    RegisterAuraScript(spell_dru_bear_form_passive);
    RegisterAuraScript(spell_dru_berserk);
    RegisterAuraScript(spell_dru_dash);
    RegisterAuraScript(spell_dru_eclipse);
    RegisterAuraScript(spell_dru_enrage);
    RegisterAuraScript(spell_dru_forms_trinket);
    RegisterSpellScript(spell_dru_flight_form);
    RegisterAuraScript(spell_dru_frenzied_regeneration);
    RegisterAuraScript(spell_dru_glyph_of_barkskin);
    RegisterAuraScript(spell_dru_glyph_of_innervate);
    RegisterAuraScript(spell_dru_glyph_of_rake);
    RegisterAuraScript(spell_dru_glyph_of_rejuvenation);
    RegisterAuraScript(spell_dru_glyph_of_shred);
    RegisterSpellScript(spell_dru_glyph_of_starfire);
    RegisterAuraScript(spell_dru_glyph_of_starfire_dummy);
    RegisterAuraScript(spell_dru_idol_lifebloom);
    RegisterAuraScript(spell_dru_innervate);
    RegisterAuraScript(spell_dru_insect_swarm);
    RegisterAuraScript(spell_dru_leader_of_the_pack);
    RegisterAuraScript(spell_dru_lifebloom);
    RegisterAuraScript(spell_dru_living_seed);
    RegisterAuraScript(spell_dru_living_seed_proc);
    RegisterAuraScript(spell_dru_moonkin_form_passive);
    RegisterAuraScript(spell_dru_omen_of_clarity);
    new spell_dru_owlkin_frenzy();
    new spell_dru_predatory_strikes();
    new spell_dru_primal_tenacity();
    new spell_dru_revitalize();
    new spell_dru_rip();
    new spell_dru_savage_defense();
    RegisterSpellAndAuraScriptPair(spell_dru_savage_roar, spell_dru_savage_roar_aura);
    new spell_dru_starfall_aoe();
    new spell_dru_starfall_dummy();
    RegisterSpellAndAuraScriptPair(spell_dru_survival_instincts, spell_dru_survival_instincts_aura);
    new spell_dru_swift_flight_passive();
    new spell_dru_tiger_s_fury();
    new spell_dru_typhoon();
    new spell_dru_t3_2p_bonus();
    new spell_dru_t3_6p_bonus();
    new spell_dru_t3_8p_bonus();
    new spell_dru_t4_2p_bonus();
    new spell_dru_item_t6_trinket();
    new spell_dru_t9_feral_relic();
    new spell_dru_t10_balance_4p_bonus();
    new spell_dru_t10_restoration_4p_bonus();
    new spell_dru_t10_restoration_4p_bonus_dummy();
    RegisterSpellAndAuraScriptPair(spell_dru_wild_growth, spell_dru_wild_growth_aura);
}
