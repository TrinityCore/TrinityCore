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
#include "Containers.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "DynamicObject.h"
#include "Creature.h"
#include "TemporarySummon.h"

enum DruidSpells
{
    SPELL_DRUID_ASTRAL_ALIGNMENT            = 90164,
    SPELL_DRUID_BLOOD_IN_THE_WATER_SCRIPT   = 80863,
    SPELL_DRUID_BLOOM                       = 90159,
    SPELL_DRUID_BRUTAL_IMPACT_R1            = 16940,
    SPELL_DRUID_WRATH                       = 5176,
    SPELL_DRUID_STARFIRE                    = 2912,
    SPELL_DRUID_STARSURGE                   = 78674,
    SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE    = 89265,
    SPELL_DRUID_STARSURGE_ENERGIZE          = 86605,
    SPELL_DRUID_LUNAR_ECLIPSE_MARKER        = 67484, // Will make the yellow arrow on eclipse bar point to the blue side (lunar)
    SPELL_DRUID_SOLAR_ECLIPSE_MARKER        = 67483, // Will make the yellow arrow on eclipse bar point to the yellow side (solar)
    SPELL_DRUID_SOLAR_ECLIPSE               = 48517,
    SPELL_DRUID_LUNAR_ECLIPSE               = 48518,
    SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE       = 94338,
    SPELL_DRUID_HARMONY                     = 100977,
    SPELL_DRUID_EFFLORESCENCE_AOE           = 81262,
    SPELL_DRUID_EFFLORESCENCE_HEAL          = 81269,
    SPELL_DRUID_ENRAGE_MOD_DAMAGE           = 51185,
    SPELL_DRUID_ENRAGED_DEFENSE             = 70725,
    SPELL_DRUID_EUPHORIA                    = 81061,
    SPELL_DRUID_EUPHORIA_MANA_ENERGIZE      = 81070,
    SPELL_DRUID_EUPHORIA_ENERGIZE           = 81069,
    SPELL_DRUID_FERAL_CHARGE_BEAR           = 16979,
    SPELL_DRUID_FERAL_CHARGE_CAT            = 49376,
    SPELL_DRUID_FERAL_SWIFTNESS             = 17002,
    SPELL_DRUID_FERAL_SWIFTNESS_CLEAR_ROAR  = 97993,
    SPELL_DRUID_FERAL_SWIFTNESS_CLEAR_CAT   = 97985,
    SPELL_DRUID_FUNGAL_GROWTH_R1            = 78788,
    SPELL_DRUID_FUNGAL_GROWTH_R2            = 78789,
    SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R1     = 81291,
    SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R2     = 81283,
    SPELL_DRUID_FRENZIED_REGENERATION_HEAL  = 22845,
    SPELL_DRUID_EMPOWERED_TOUCH_SCRIPT      = 88433,
    SPELL_DRUID_FURY_OF_STORMRAGE           = 81093,
    SPELL_DRUID_GLYPH_OF_INNERVATE          = 54833,
    SPELL_DRUID_GLYPH_OF_STARFIRE           = 54846,
    SPELL_DRUID_GLYPH_OF_TYPHOON            = 62135,
    SPELL_DRUID_GLYPH_OF_FEROCIOUS_BITE     = 101024,
    SPELL_DRUID_IDOL_OF_FERAL_SHADOWS       = 34241,
    SPELL_DRUID_IDOL_OF_WORSHIP             = 60774,
    SPELL_DRUID_INCREASED_MOONFIRE_DURATION = 38414,
    SPELL_DRUID_INNERVATE_TRIGGERED         = 54833,
    SPELL_DRUID_ITEM_T8_BALANCE_RELIC       = 64950,
    SPELL_DRUID_ITEM_T10_FERAL_4P_BONUS     = 70726,
    SPELL_DRUID_ITEM_T11_BALANCE_4P_BONUS   = 90163,
    SPELL_DRUID_KING_OF_THE_JUNGLE          = 48492,
    SPELL_DRUID_LACERATE                    = 33745,
    SPELL_DRUID_LEADER_OF_THE_PACK_HEAL     = 34299,
    SPELL_DRUID_LEADER_OF_THE_PACK_ENERGIZE = 68285,
    SPELL_DRUID_LIFEBLOOM                   = 33763,
    SPELL_DRUID_LIFEBLOOM_ENERGIZE          = 64372,
    SPELL_DRUID_LIFEBLOOM_FINAL_HEAL        = 33778,
    SPELL_DRUID_LIVING_SEED_HEAL            = 48503,
    SPELL_DRUID_LIVING_SEED_PROC            = 48504,
    SPELL_DRUID_LUNAR_SHOWER                = 33603,
    SPELL_DRUID_MOONFIRE                    = 8921,
    SPELL_DRUID_NATURES_BOUNTY              = 96206,
    SPELL_DRUID_NATURES_GRACE               = 16880,
    SPELL_DRUID_PULVERIZE_TRIGGERED         = 80951,
    SPELL_DRUID_RIP                         = 1079,
    SPELL_DRUID_SURVIVAL_INSTINCTS          = 50322,
    SPELL_DRUID_SAVAGE_ROAR                 = 62071,
    SPELL_DRUID_SKULL_BASH_CHARGE           = 93983,
    SPELL_DRUID_SKULL_BASH_INTERRUPT        = 93985,
    SPELL_DRUID_SKULL_BASH_COST_INCREASE_R1 = 82364,
    SPELL_DRUID_SKULL_BASH_COST_INCREASE_R2 = 82365,
    SPELL_DRUID_STAMPEDE_BAER_RANK_1        = 81016,
    SPELL_DRUID_STAMPEDE_CAT_RANK_1         = 81021,
    SPELL_DRUID_STAMPEDE_CAT_STATE          = 109881,
    SPELL_DRUID_SOLAR_BEAM_SILENCE          = 81261,
    SPELL_DRUID_STRENGTH_OF_THE_PANTHER     = 90166,
    SPELL_DRUID_SUNFIRE                     = 93402,
    SPELL_DRUID_REJUVENATION_DIRECT_HEAL    = 64801,
    SPELL_DRUID_TIGER_S_FURY_ENERGIZE       = 51178,
    SPELL_DRUID_TREE_OF_LIFE                = 33891,
    SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1      = 5420,
    SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2      = 81097,
    SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3      = 81098,
    SPELL_DRUID_T13_FERAL_2P_BONUS          = 105725,
    SPELL_DRUID_WILD_MUSHROOM               = 88747,
    SPELL_DRUID_WILD_MUSHROOM_DAMAGE        = 78777,
    SPELL_DRUID_WILD_MUSHROOM_SUICIDE       = 92853,
    SPELL_DRUID_WILD_MUSHROOM_VISUAL        = 92701
};

enum DruidSpellIconIds
{
    SPELL_ICON_ID_NATURES_BOUNTY                    = 197,
    SPELL_ICON_ID_DREAMSTATE                        = 2255,
    SPELL_ICON_ID_GLYPH_OF_INNERVATE                = 62,
    SPELL_ICON_ID_EUPHORIA                          = 4431,
    SPELL_ICON_ID_SAVAGE_DEFENDER                   = 146,
    SPELL_ICON_ID_SUNFIRE                           = 3262,
    SPELL_ICON_ID_GLYPH_OF_FEROCIOUS_BITE           = 1680,
    SPELL_ICON_ID_GLYPH_OF_FRENZIED_REGENERATION    = 50,
    SPELL_ICON_ID_GIFT_OF_THE_EARTHMOTHER           = 3186
};

enum MiscSpells
{
    SPELL_CATEGORY_MANGLE_BEAR              = 971
};

// 50334 - Berserk
class spell_dru_berserk : public AuraScript
{
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
        AfterEffectApply.Register(&spell_dru_berserk::HandleEffectApply, EFFECT_1, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1850 - Dash
class spell_dru_dash : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_FERAL_SWIFTNESS,
                SPELL_DRUID_FERAL_SWIFTNESS_CLEAR_CAT
            });
    }

    void HandleFeralSwiftness(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (Aura* swiftness = target->GetAuraOfRankedSpell(SPELL_DRUID_FERAL_SWIFTNESS, target->GetGUID()))
            if (roll_chance_i(swiftness->GetSpellInfo()->Effects[EFFECT_1].BasePoints))
                target->CastSpell(target, SPELL_DRUID_FERAL_SWIFTNESS_CLEAR_CAT, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_dash::HandleFeralSwiftness, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_dru_dash_AuraScript : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        // do not set speed if not in cat form
        if (GetUnitOwner()->GetShapeshiftForm() != FORM_CAT)
            amount = 0;
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dru_dash_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_INCREASE_SPEED);
    }
};

// 48517 - Eclipse (Solar)
class spell_dru_eclipse : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_SOLAR_ECLIPSE,
                SPELL_DRUID_SUNFIRE,
                SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE
            });
    }

    void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        // Handle Sunfire talent
        if (GetSpellInfo()->Id == SPELL_DRUID_SOLAR_ECLIPSE && target->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_SUNFIRE, EFFECT_0))
            if (!target->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE))
                target->CastSpell(target, SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE, CastSpellExtraArgs(true).AddSpellBP0(SPELL_DRUID_SUNFIRE));
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (GetSpellInfo()->Id == SPELL_DRUID_SOLAR_ECLIPSE && target->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE))
            target->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_dru_eclipse::ApplyEffect, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_dru_eclipse::RemoveEffect, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 79577 - Eclipse Mastery Passive Driver
class spell_dru_eclipse_mastery_driver_passive : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_LUNAR_ECLIPSE,
                SPELL_DRUID_LUNAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE,
                SPELL_DRUID_SOLAR_ECLIPSE_MARKER,
                SPELL_DRUID_EUPHORIA_ENERGIZE,
                SPELL_DRUID_EUPHORIA_MANA_ENERGIZE,
                SPELL_DRUID_STARSURGE_ENERGIZE,
                SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE,
                SPELL_DRUID_NATURES_GRACE,
                SPELL_DRUID_ITEM_T11_BALANCE_4P_BONUS
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetSpellInfo();
    }

    bool CheckSolarEclipseProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        _eclipseMarker = GetTarget()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x100000, GetTarget()->GetGUID());
        if (_eclipseMarker && _eclipseMarker->GetSpellInfo()->Id != SPELL_DRUID_SOLAR_ECLIPSE_MARKER)
            return false;

        _energyAmount = GetEnergyGainFromSpellInfo(eventInfo.GetSpellInfo());
        return _energyAmount > 0;
    }

    bool CheckLunarEclipseProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        _eclipseMarker = GetTarget()->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_DRUID, 0x0, 0x0, 0x100000, GetTarget()->GetGUID());
        if (_eclipseMarker && _eclipseMarker->GetSpellInfo()->Id != SPELL_DRUID_LUNAR_ECLIPSE_MARKER)
            return false;

        _energyAmount = GetEnergyGainFromSpellInfo(eventInfo.GetSpellInfo());
        return _energyAmount < 0;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* target = GetTarget();

        // Apply eclipse Marker if not present
        if (!_eclipseMarker)
            target->CastSpell(target, aurEff->GetEffIndex() == EFFECT_0 ? SPELL_DRUID_SOLAR_ECLIPSE_MARKER : SPELL_DRUID_LUNAR_ECLIPSE_MARKER, false);

        // Cast Energy Gain
        uint32 energizeSpell = (eventInfo.GetSpellInfo()->SpellFamilyFlags[2] & 0x2000000) != 0 ? SPELL_DRUID_STARSURGE_ENERGIZE : SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE;
        target->CastSpell(target, energizeSpell, CastSpellExtraArgs().AddSpellBP0(_energyAmount));

        // Cast Euphoria Bonus
        if (_euphoriaEnergyAmount)
            target->CastSpell(target, SPELL_DRUID_EUPHORIA_ENERGIZE, CastSpellExtraArgs().AddSpellBP0(_euphoriaEnergyAmount));
    }

    void HandleEclipseProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        uint32 newMarkerSpellId = 0;

        AuraEffect* eclipse = target->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_DRUID, 0x0, 0x0, 0x4000);
        if (eclipse)
        {
            if (_eclipseMarker)
            {
                if (eclipse->GetId() == SPELL_DRUID_LUNAR_ECLIPSE && _eclipseMarker->GetId() == SPELL_DRUID_LUNAR_ECLIPSE_MARKER)
                    newMarkerSpellId = SPELL_DRUID_SOLAR_ECLIPSE_MARKER;
                else if (eclipse->GetId() == SPELL_DRUID_SOLAR_ECLIPSE && _eclipseMarker->GetId() == SPELL_DRUID_SOLAR_ECLIPSE_MARKER)
                    newMarkerSpellId = SPELL_DRUID_LUNAR_ECLIPSE_MARKER;
            }

            if ((eclipse->GetId() == SPELL_DRUID_LUNAR_ECLIPSE && target->GetPower(POWER_ECLIPSE) >= 0) ||
                ((eclipse->GetId() == SPELL_DRUID_SOLAR_ECLIPSE && target->GetPower(POWER_ECLIPSE) <= 0)))
                if (Aura* aura = eclipse->GetBase())
                    aura->Remove();
        }

        if (!newMarkerSpellId)
            return;
        if (_eclipseMarker)
            if (Aura* aura = _eclipseMarker->GetBase())
                aura->Remove();

        target->CastSpell(target, newMarkerSpellId, false);

        // Reset Nature's Grace proc cooldown
        if (Aura* aura = target->GetAuraOfRankedSpell(SPELL_DRUID_NATURES_GRACE))
            aura->ResetProcCooldown();

        // Euphoria Mana Bonus
        if (AuraEffect const* euphoria = target->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_EUPHORIA, EFFECT_2))
            target->CastSpell(target, SPELL_DRUID_EUPHORIA_MANA_ENERGIZE, CastSpellExtraArgs().AddSpellBP0(euphoria->GetAmount()));

        // T11 Bonus
        if (AuraEffect const* t11Bonus = target->GetAuraEffect(SPELL_DRUID_ITEM_T11_BALANCE_4P_BONUS, EFFECT_0))
            target->CastSpell(target, SPELL_DRUID_ASTRAL_ALIGNMENT, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_AURA_STACK, 3));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dru_eclipse_mastery_driver_passive::CheckProc);
        DoCheckEffectProc.Register(&spell_dru_eclipse_mastery_driver_passive::CheckSolarEclipseProc, EFFECT_0, SPELL_AURA_PROC_ON_POWER_AMOUNT);
        DoCheckEffectProc.Register(&spell_dru_eclipse_mastery_driver_passive::CheckLunarEclipseProc, EFFECT_1, SPELL_AURA_PROC_ON_POWER_AMOUNT);
        OnEffectProc.Register(&spell_dru_eclipse_mastery_driver_passive::HandleProc, EFFECT_0, SPELL_AURA_PROC_ON_POWER_AMOUNT);
        OnEffectProc.Register(&spell_dru_eclipse_mastery_driver_passive::HandleProc, EFFECT_1, SPELL_AURA_PROC_ON_POWER_AMOUNT);
        AfterEffectProc.Register(&spell_dru_eclipse_mastery_driver_passive::HandleEclipseProc, EFFECT_0, SPELL_AURA_PROC_ON_POWER_AMOUNT);
        AfterEffectProc.Register(&spell_dru_eclipse_mastery_driver_passive::HandleEclipseProc, EFFECT_1, SPELL_AURA_PROC_ON_POWER_AMOUNT);
    }
private:
    int32 GetEnergyGainFromSpellInfo(SpellInfo const* spell)
    {
        Unit* target = GetTarget();
        int32 energyAmount = 0;
        int32 bonusEnergyAmount = 0;

        // Wrath and Starfire energy amount
        if ((spell->SpellFamilyFlags[0] & 0x1) != 0)
            energyAmount = -spell->Effects[EFFECT_1].CalcValue(target);
        else if ((spell->SpellFamilyFlags[0] & 0x4) != 0)
            energyAmount = spell->Effects[EFFECT_1].CalcValue(target);

        // Euphoria Talent Bonus
        if (energyAmount != 0 && !target->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_DRUID, 0x0, 0x0, 0x4000))
            if (AuraEffect const* euphoria = target->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_EUPHORIA, EFFECT_0))
                if (roll_chance_i(euphoria->GetAmount()))
                    bonusEnergyAmount = energyAmount;

        // Starsurge energy amount
        if ((spell->SpellFamilyFlags[2] & 0x2000000) != 0)
        {
            int32 bp = spell->Effects[EFFECT_1].CalcValue(target);
            if (_eclipseMarker)
                energyAmount += _eclipseMarker->GetSpellInfo()->Id == SPELL_DRUID_LUNAR_ECLIPSE_MARKER ? -bp : bp;
            else
                energyAmount -= bp;
        }

        // Lunar Shower Bonus for Starfire and Sunfire
        if ((spell->SpellFamilyFlags[0] & 0x2) != 0)
        {
            if (Aura const* lunarShower = target->GetAuraOfRankedSpell(SPELL_DRUID_LUNAR_SHOWER, target->GetGUID()))
            {
                if (target->HasAura(lunarShower->GetSpellInfo()->Effects[EFFECT_0].TriggerSpell))
                {
                    int32 bp = sSpellMgr->AssertSpellInfo(SPELL_DRUID_LUNAR_SHOWER)->Effects[EFFECT_2].CalcValue(target);
                    if (_eclipseMarker)
                        energyAmount += _eclipseMarker->GetSpellInfo()->Id == SPELL_DRUID_LUNAR_ECLIPSE_MARKER ? -bp : bp;
                    else
                        energyAmount -= bp;
                }
            }
        }

        _euphoriaEnergyAmount = bonusEnergyAmount;
        return energyAmount;
    }

    AuraEffect* _eclipseMarker = nullptr;
    int32 _energyAmount = 0;
    int32 _euphoriaEnergyAmount = 0;
};

// 5229 - Enrage
class spell_dru_enrage : public AuraScript
{
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
            target->CastSpell(target, SPELL_DRUID_ENRAGE_MOD_DAMAGE, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));

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
        AfterEffectApply.Register(&spell_dru_enrage::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_dru_enrage::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 54846 - Glyph of Starfire
class spell_dru_glyph_of_starfire : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_INCREASED_MOONFIRE_DURATION });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            if (AuraEffect const* aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x2, 0, 0, caster->GetGUID()))
            {
                Aura* aura = aurEff->GetBase();

                uint32 countMin = aura->GetMaxDuration();
                uint32 countMax = aura->GetSpellInfo()->GetMaxDuration() + 9000;
                if (caster->HasAura(SPELL_DRUID_INCREASED_MOONFIRE_DURATION))
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
        OnEffectHitTarget.Register(&spell_dru_glyph_of_starfire::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 54845 - Glyph of Starfire
class spell_dru_glyph_of_starfire_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_STARFIRE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & 0x00000002)
        {
            _lastMoonFireTargetGuid = eventInfo.GetProcTarget()->GetGUID();
            return false;
        }
        else if (_lastMoonFireTargetGuid != eventInfo.GetProcTarget()->GetGUID())
            return false;

        return true;
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_STARFIRE, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dru_glyph_of_starfire_proc::CheckProc);
        OnEffectProc.Register(&spell_dru_glyph_of_starfire_proc::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
private:
    ObjectGuid _lastMoonFireTargetGuid;
};

// 34246 - Idol of the Emerald Queen
// 60779 - Idol of Lush Moss
class spell_dru_idol_lifebloom : public AuraScript
{
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
        DoEffectCalcSpellMod.Register(&spell_dru_idol_lifebloom::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 29166 - Innervate
class spell_dru_innervate : public AuraScript
{
    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        Unit* target = GetUnitOwner();
        if (!target)
            return;

        uint32 mana = target->GetMaxPower(POWER_MANA);
        if (!mana)
            return;

        // Regenerate 5% of maximum mana
        uint8 percentage = 5;

        // If casted on self regenerate 15% additional mana
        if (Unit* caster = GetCaster())
        {
            if (target == caster)
            {
                percentage += 15;

                // Dreamstate increases the amount by additional 15%
                if (AuraEffect* dreamState = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_DREAMSTATE, EFFECT_0))
                    percentage += dreamState->GetAmount();
            }
            else
            {
                // Glyph of Innervate
                if (caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_GLYPH_OF_INNERVATE, EFFECT_0))
                    caster->CastSpell(caster, SPELL_DRUID_INNERVATE_TRIGGERED, true);
            }
        }

        amount = CalculatePct(mana, percentage) / aurEff->GetTotalTicks();
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dru_innervate::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

// 5570 - Insect Swarm
class spell_dru_insect_swarm : public AuraScript
{
    void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect const* relicAurEff = caster->GetAuraEffect(SPELL_DRUID_ITEM_T8_BALANCE_RELIC, EFFECT_0))
                amount += relicAurEff->GetAmount() / aurEff->GetTotalTicks();
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dru_insect_swarm::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 33763 - Lifebloom
// 94447 - Lifebloom
class spell_dru_lifebloom : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_LIFEBLOOM_FINAL_HEAL,
                SPELL_DRUID_LIFEBLOOM_ENERGIZE
            });
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // Final heal only on duration end
        if (!GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::Expired))
            return;

        // final heal
        int32 stack = GetStackAmount();
        int32 healAmount = aurEff->GetAmount();
        if (Unit* caster = GetCaster())
        {
            healAmount = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), healAmount, HEAL, stack);
            healAmount = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, stack);

            GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(healAmount).SetOriginalCaster(GetCasterGUID()));

            // restore mana
            int32 returnMana = CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * stack / 2;
            caster->CastSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, CastSpellExtraArgs(aurEff).AddSpellBP0(returnMana).SetOriginalCaster(GetCasterGUID()));
            return;
        }

        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(healAmount).SetOriginalCaster(GetCasterGUID()));
    }

    void HandleDispel(DispelInfo* dispelInfo)
    {
        if (Unit* target = GetUnitOwner())
        {
            if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
            {
                // final heal
                int32 healAmount = aurEff->GetAmount();
                if (Unit* caster = GetCaster())
                {
                    healAmount = caster->SpellHealingBonusDone(target, GetSpellInfo(), healAmount, HEAL, dispelInfo->GetRemovedCharges());
                    healAmount = target->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, dispelInfo->GetRemovedCharges());
                    target->CastSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, CastSpellExtraArgs(GetCasterGUID()).AddSpellBP0(healAmount));

                    // restore mana
                    int32 returnMana = CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * dispelInfo->GetRemovedCharges() / 2;
                    caster->CastSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, CastSpellExtraArgs(GetCasterGUID()).AddSpellBP0(returnMana));
                    return;
                }

                target->CastSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, CastSpellExtraArgs(GetCasterGUID()).AddSpellBP0(healAmount));
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_dru_lifebloom::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterDispel.Register(&spell_dru_lifebloom::HandleDispel);
    }
};

// -48496 - Living Seed
class spell_dru_living_seed : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_LIVING_SEED_PROC });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 amount = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_LIVING_SEED_PROC, CastSpellExtraArgs(aurEff).AddSpellBP0(amount));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_living_seed::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 48504 - Living Seed (Proc)
class spell_dru_living_seed_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_LIVING_SEED_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_LIVING_SEED_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_living_seed_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 1079 - Rip
// Updated 4.3.4
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
            // Formular: bp + 0.0207 * ap
            uint8 cp = caster->ToPlayer()->GetComboPoints();
            float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.0207f;

            float bonus = ap * cp;

            // Idol of Feral Shadows. Can't be handled as SpellMod due its dependency from CPs
            if (AuraEffect const* auraEffIdolOfFeralShadows = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_FERAL_SHADOWS, EFFECT_0))
                amount += cp * auraEffIdolOfFeralShadows->GetAmount();
            // Idol of Worship. Can't be handled as SpellMod due its dependency from CPs
            else if (AuraEffect const* auraEffIdolOfWorship = caster->GetAuraEffect(SPELL_DRUID_IDOL_OF_WORSHIP, EFFECT_0))
                amount += cp * auraEffIdolOfWorship->GetAmount();

            amount += int32(bonus);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dru_rip::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 62606 - Savage Defense
class spell_dru_savage_defense : public AuraScript
{
    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();

        uint32 absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(target);
        if (AuraEffect* masteryAurEff = target->GetDummyAuraEffect(SPELLFAMILY_HUNTER, SPELL_ICON_ID_SAVAGE_DEFENDER, EFFECT_0)) // no idea why hunter...
            absorbPct += masteryAurEff->GetAmount();

        int32 amount = uint32(CalculatePct(GetTarget()->GetTotalAttackPowerValue(BASE_ATTACK), absorbPct));
        target->CastSpell(target, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, CastSpellExtraArgs(true).AddSpellBP0(amount));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_savage_defense::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 52610 - Savage Roar
class spell_dru_savage_roar : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->GetShapeshiftForm() != FORM_CAT)
            return SPELL_FAILED_ONLY_SHAPESHIFT;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dru_savage_roar::CheckCast);
    }
};

class spell_dru_savage_roar_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
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
        AfterEffectApply.Register(&spell_dru_savage_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_dru_savage_roar_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
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
        OnObjectAreaTargetSelect.Register(&spell_dru_starfall_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_dru_starfall_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -78892 - Stampede
class spell_dru_stampede : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_STAMPEDE_BAER_RANK_1,
                SPELL_DRUID_STAMPEDE_CAT_RANK_1,
                SPELL_DRUID_STAMPEDE_CAT_STATE,
                SPELL_DRUID_FERAL_CHARGE_CAT,
                SPELL_DRUID_FERAL_CHARGE_BEAR
            });
    }

    void HandleEffectCatProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (GetTarget()->GetShapeshiftForm() != FORM_CAT || eventInfo.GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_CAT)
            return;

        GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_CAT_RANK_1, GetSpellInfo()->GetRank()), aurEff);
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_STAMPEDE_CAT_STATE, aurEff);
    }

    void HandleEffectBearProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (GetTarget()->GetShapeshiftForm() != FORM_BEAR || eventInfo.GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_BEAR)
            return;

        GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_BAER_RANK_1, GetSpellInfo()->GetRank()), aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_stampede::HandleEffectCatProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc.Register(&spell_dru_stampede::HandleEffectBearProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 61336 - Survival Instincts
class spell_dru_survival_instincts : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (!caster->IsInFeralForm())
            return SPELL_FAILED_ONLY_SHAPESHIFT;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dru_survival_instincts::CheckCast);
    }
};

class spell_dru_survival_instincts_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SURVIVAL_INSTINCTS });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_SURVIVAL_INSTINCTS, aurEff);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_dru_survival_instincts_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        AfterEffectRemove.Register(&spell_dru_survival_instincts_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
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
        DoEffectCalcAmount.Register(&spell_dru_swift_flight_passive::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED);
    }
};

// 33943 - Flight Form (Shapeshift)
class spell_dru_flight_form : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->IsInDisallowedMountForm())
            return SPELL_FAILED_NOT_SHAPESHIFT;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dru_flight_form::CheckCast);
    }
};

// 40120 - Swift Flight Form (Shapeshift)
class spell_dru_swift_flight_form : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            // the following values are sniffed but it is not clear how these values are actually being calculated since shapeshift auras usually don't do that.
            if (caster->GetSkillValue(SKILL_RIDING) >= 375)
                amount = 240;
            else
                amount = 239;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dru_swift_flight_form::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT);
    }
};

// 5217 - Tiger's Fury
class spell_dru_tiger_s_fury : public SpellScript
{
    void OnHit()
    {
        if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_1))
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DRUID_TIGER_S_FURY_ENERGIZE, CastSpellExtraArgs(true).AddSpellBP0(aurEff->GetAmount()));
    }

    void Register() override
    {
        AfterHit.Register(&spell_dru_tiger_s_fury::OnHit);
    }
};

// 61391 - Typhoon
class spell_dru_typhoon : public SpellScript
{
    void HandleKnockBack(SpellEffIndex effIndex)
    {
        // Glyph of Typhoon
        if (GetCaster()->HasAura(SPELL_DRUID_GLYPH_OF_TYPHOON))
            PreventHitDefaultEffect(effIndex);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_typhoon::HandleKnockBack, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
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
        OnObjectAreaTargetSelect.Register(&spell_dru_t10_restoration_4p_bonus::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
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

// 48438 - Wild Growth
class spell_dru_wild_growth : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_TREE_OF_LIFE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaidCheck(GetCaster()));

        uint8 maxTargets = GetSpellInfo()->Effects[EFFECT_2].BasePoints;

        // Tree of Life bonus
        if (GetCaster()->HasAura(SPELL_DRUID_TREE_OF_LIFE))
            maxTargets += 2;

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
        OnObjectAreaTargetSelect.Register(&spell_dru_wild_growth::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnObjectAreaTargetSelect.Register(&spell_dru_wild_growth::SetTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }

private:
    std::list<WorldObject*> _targets;
};

// 78675 - Solar Beam
class spell_dru_solar_beam : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SOLAR_BEAM_SILENCE });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell({ dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ() }, SPELL_DRUID_SOLAR_BEAM_SILENCE, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dru_solar_beam::HandleEffectPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -34151 - Efflorescence (Proc Aura)
class spell_dru_effloresence : public AuraScript
{
    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 healAmount = 0;

        if (HealInfo* heal = eventInfo.GetHealInfo())
        {
            healAmount = CalculatePct(heal->GetHeal(), GetSpellInfo()->Effects[EFFECT_0].BasePoints);
            if (healAmount)
                GetTarget()->CastSpell(heal->GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_BASE_POINT1, healAmount));
        }
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_effloresence::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 81262 - Efflorescence (Area Effect)
class spell_dru_effloresence_aoe : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_EFFLORESCENCE_HEAL });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            if (DynamicObject* dyn = caster->GetDynObject(aurEff->GetId()))
                caster->CastSpell({ dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ() }, SPELL_DRUID_EFFLORESCENCE_HEAL, { aurEff, caster->GetGUID() });
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dru_effloresence_aoe::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//  81269 - Efflorescence (Heal)
class spell_dru_effloresence_heal : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_EFFLORESCENCE_AOE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() > 3)
        {
            targets.sort(Trinity::HealthPctOrderPred(true));
            targets.resize(3);
        }
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Aura const* aura = caster->GetAura(SPELL_DRUID_EFFLORESCENCE_AOE, caster->GetGUID()))
                if (AuraEffect* aurEff = aura->GetEffect(EFFECT_1))
                    if (int32 heal = aurEff->GetAmount())
                        SetHitHeal(heal);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_dru_effloresence_heal::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_dru_effloresence_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 774 - Rejuvenation
class spell_dru_rejuvenation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_NATURES_BOUNTY,
                SPELL_DRUID_REJUVENATION_DIRECT_HEAL
            });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect* naturesBountyAurEff = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_DRUID, SPELL_ICON_ID_NATURES_BOUNTY, EFFECT_0))
            {
                // a bit cheaty here but as long as we don't have a unit internal aura count...
                naturesBountyAurEff->SetBonusAmount(naturesBountyAurEff->GetBonusAmount() + 1);
                if (naturesBountyAurEff->GetBonusAmount() >= 3)
                {
                    int32 bp0 = -naturesBountyAurEff->GetSpellInfo()->Effects[EFFECT_1].BasePoints;
                    caster->CastSpell(caster, SPELL_DRUID_NATURES_BOUNTY, CastSpellExtraArgs(true).AddSpellBP0(bp0));
                }
            }
        }
    }

    void HandleGiftOfTheEarthmother(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect const* giftEffect = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_GIFT_OF_THE_EARTHMOTHER, EFFECT_1))
            {
                int32 bp = CalculatePct(aurEff->GetAmount() * aurEff->GetTotalTicks(), giftEffect->GetAmount());
                caster->CastSpell(GetTarget(), SPELL_DRUID_REJUVENATION_DIRECT_HEAL, CastSpellExtraArgs(true).AddSpellBP0(bp));
            }
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect* naturesBountyAurEff = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_DRUID, SPELL_ICON_ID_NATURES_BOUNTY, EFFECT_0))
            {
                naturesBountyAurEff->SetBonusAmount(naturesBountyAurEff->GetBonusAmount() > 0 ? naturesBountyAurEff->GetBonusAmount() - 1 : 0);
                if (naturesBountyAurEff->GetBonusAmount() < 3 && caster->HasAura(SPELL_DRUID_NATURES_BOUNTY))
                    caster->RemoveAurasDueToSpell(SPELL_DRUID_NATURES_BOUNTY);
            }
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_dru_rejuvenation::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply.Register(&spell_dru_rejuvenation::HandleGiftOfTheEarthmother, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove.Register(&spell_dru_rejuvenation::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 33891 - Tree of Life
class spell_dru_tree_of_life : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1,
                SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2,
                SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3
            });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->CastSpell(target, SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1, aurEff);
            target->CastSpell(target, SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2, aurEff);
            target->CastSpell(target, SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3, aurEff);

        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->RemoveAurasDueToSpell(SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1);
            target->RemoveAurasDueToSpell(SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2);
            target->RemoveAurasDueToSpell(SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3);
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_dru_tree_of_life::AfterApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_dru_tree_of_life::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 77495 - Harmony
class spell_dru_harmony : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_HARMONY });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        int32 amount = aurEff->GetAmount();
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_HARMONY, CastSpellExtraArgs(aurEff).AddSpellBP0(amount));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_harmony::HandleProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
    }
};

// 17007 - Leader of the Pack
class spell_dru_leader_of_the_pack : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_LEADER_OF_THE_PACK_HEAL,
                SPELL_DRUID_LEADER_OF_THE_PACK_ENERGIZE
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return (GetTarget()->GetShapeshiftForm() == FORM_CAT || GetTarget()->GetShapeshiftForm() == FORM_BEAR);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();

        int32 heal = 0;
        if (SpellInfo const* healSpell = sSpellMgr->GetSpellInfo(SPELL_DRUID_LEADER_OF_THE_PACK_HEAL))
            if (int32 bp = healSpell->Effects[EFFECT_0].BasePoints)
                heal = CalculatePct(target->GetMaxHealth(), bp);

        int32 mana = 0;
        if (SpellInfo const* energizeSpell = sSpellMgr->GetSpellInfo(SPELL_DRUID_LEADER_OF_THE_PACK_ENERGIZE))
            if (int32 bp = energizeSpell->Effects[EFFECT_0].BasePoints)
                mana = CalculatePct(target->GetMaxPower(POWER_MANA), bp);

        if (heal)
            target->CastSpell(target, SPELL_DRUID_LEADER_OF_THE_PACK_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(heal));

        if (mana)
            target->CastSpell(target, SPELL_DRUID_LEADER_OF_THE_PACK_ENERGIZE, CastSpellExtraArgs(aurEff).AddSpellBP0(mana));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dru_leader_of_the_pack::CheckProc);
        OnEffectProc.Register(&spell_dru_leader_of_the_pack::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dru_wild_mushroom : public SpellScript
{
    void HandleSummon()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Creature*> mushrooms;
        caster->GetAllMinionsByEntry(mushrooms, GetSpellInfo()->Effects[EFFECT_0].MiscValue);
        if (mushrooms.empty())
            return;

        TempSummon* oldestMushroom = nullptr;

        if (mushrooms.size() > uint32(GetSpellInfo()->Effects[EFFECT_0].BasePoints))
        {
            for (auto itr : mushrooms)
            {
                if (TempSummon* mushroomToCheck = itr->ToTempSummon())
                {
                    if (!oldestMushroom)
                        oldestMushroom = mushroomToCheck;
                    else
                    {
                        if (mushroomToCheck->GetTimer() < oldestMushroom->GetTimer())
                            oldestMushroom = mushroomToCheck;
                    }
                }
            }
            if (oldestMushroom)
                oldestMushroom->UnSummon();
        }
    }

    void Register() override
    {
        AfterCast.Register(&spell_dru_wild_mushroom::HandleSummon);
    }
};

class spell_dru_wild_mushroom_detonate : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_WILD_MUSHROOM,
                SPELL_DRUID_WILD_MUSHROOM_DAMAGE,
                SPELL_DRUID_WILD_MUSHROOM_SUICIDE,
                SPELL_DRUID_WILD_MUSHROOM_VISUAL,
                SPELL_DRUID_FUNGAL_GROWTH_R1,
                SPELL_DRUID_FUNGAL_GROWTH_R2,
                SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R1,
                SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R2
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_DRUID_WILD_MUSHROOM);
        if (!spell)
            return;

        std::list<Creature*> mushrooms;
        caster->GetAllMinionsByEntry(mushrooms, spell->Effects[EFFECT_0].MiscValue);
        if (mushrooms.empty())
            return;

        for (auto itr : mushrooms)
        {
            if (TempSummon* mushroom = itr->ToTempSummon())
            {
                if (caster->HasAura(SPELL_DRUID_FUNGAL_GROWTH_R1))
                    caster->CastSpell(mushroom, SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R1, true);
                else if (caster->HasAura(SPELL_DRUID_FUNGAL_GROWTH_R2))
                    caster->CastSpell(mushroom, SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R2, true);

                caster->CastSpell(mushroom, SPELL_DRUID_WILD_MUSHROOM_DAMAGE, true);
                mushroom->CastSpell(mushroom, SPELL_DRUID_WILD_MUSHROOM_VISUAL, true);
                mushroom->CastSpell(mushroom, SPELL_DRUID_WILD_MUSHROOM_SUICIDE, true);
                mushroom->UnSummon(1500);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_wild_mushroom_detonate::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 16913 - Moonfire (Passive)
class spell_dru_moonfire : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_LUNAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE,
                SPELL_DRUID_LUNAR_ECLIPSE,
                SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE
            });
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE);
        caster->RemoveAurasDueToSpell(SPELL_DRUID_LUNAR_ECLIPSE_MARKER);
        caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE_MARKER);
        caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE);
        caster->RemoveAurasDueToSpell(SPELL_DRUID_LUNAR_ECLIPSE);
        caster->SetPower(POWER_ECLIPSE, 0);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_dru_moonfire::RemoveEffect, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 22568 - Ferocious Bite
class spell_dru_ferocious_bite : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_FEROCIOUS_BITE });
    }

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_DRUID)
            return false;

        return true;
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Player* player = caster->ToPlayer())
        {
            int32 damage = GetHitDamage();
            damage += int32(player->GetComboPoints() * (player->GetTotalAttackPowerValue(BASE_ATTACK) * 0.109f));

            // converts each extra point of energy (up to 35 energy) into additional damage
            int32 energy = -(caster->ModifyPower(POWER_ENERGY, -35));
            AddPct(damage, energy * float(100.0f / 35));
            SetHitDamage(damage);

            // Glyph of Ferocious Bite
            if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_GLYPH_OF_FEROCIOUS_BITE, EFFECT_0))
            {
                int32 totalEnergySpentMultiplier = std::floor((GetSpell()->GetPowerCost() + energy) / 10);
                int32 bp = aurEff->GetAmount() * totalEnergySpentMultiplier;
                caster->CastSpell(caster, SPELL_DRUID_GLYPH_OF_FEROCIOUS_BITE, CastSpellExtraArgs(true).AddSpellBP0(bp));
            }

        }
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_dru_ferocious_bite::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// -33879 - Empowered Touch
class spell_dru_empowered_touch : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_EMPOWERED_TOUCH_SCRIPT });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(GetEffect(EFFECT_1)->GetAmount());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        target->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_EMPOWERED_TOUCH_SCRIPT, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dru_empowered_touch::CheckProc);
        OnEffectProc.Register(&spell_dru_empowered_touch::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 88433 - Empowered Touch
class spell_dru_empowered_touch_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_LIFEBLOOM });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Aura* aura = GetHitUnit()->GetAura(SPELL_DRUID_LIFEBLOOM, caster->GetGUID()))
                aura->RefreshDuration();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_empowered_touch_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 93400 - Shooting Stars
class spell_dru_shooting_stars : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_STARSURGE });
    }

    void HandleCooldownReset(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->GetSpellHistory()->ResetCooldown(SPELL_DRUID_STARSURGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_shooting_stars::HandleCooldownReset, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 80313 - Pulverize
class spell_dru_pulverize : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_PULVERIZE_TRIGGERED,
                SPELL_DRUID_LACERATE
            });
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        // Formular: $m3 * $m1 / 100
        int32 bp = CalculatePct(GetEffectValue() * GetSpellInfo()->Effects[EFFECT_0].CalcValue(caster), 1);

        if (Aura* aura = target->GetAura(SPELL_DRUID_LACERATE, caster->GetGUID()))
        {
            uint8 stacks = aura->GetStackAmount();
            bp *= stacks;
            SetEffectValue(bp);

            uint32 critPerStack = sSpellMgr->GetSpellInfo(SPELL_DRUID_PULVERIZE_TRIGGERED)->Effects[EFFECT_0].BasePoints;
            caster->CastSpell(caster, SPELL_DRUID_PULVERIZE_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(int32(critPerStack * stacks)));
            aura->Remove();
        }
        else
            SetEffectValue(0);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_dru_pulverize::ChangeDamage, EFFECT_2, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
    }
};

// 22842 - Frenzied Regeneration
class spell_dru_frenzied_regeneration : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_FRENZIED_REGENERATION_HEAL });
    }

    void HandleHealthAfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        int32 pct = GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue();

        if (target->GetHealthPct() < pct)
            target->SetHealth(CalculatePct(target->GetMaxHealth(), pct));
    }

    void HandleRegeneration(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        // Glyph of Frenzied Regeneration - block heal
        if (target->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_DRUID, SPELL_ICON_ID_GLYPH_OF_FRENZIED_REGENERATION, EFFECT_0))
            return;

        float healthPct = CalculatePct<float>(aurEff->GetAmount(), 1);
        uint32 rage = target->GetPower(POWER_RAGE) > 100 ? 100 : target->GetPower(POWER_RAGE);
        int32 heal = CalculatePct(target->GetMaxHealth(), healthPct) * CalculatePct(rage, 10);

        target->ModifyPower(POWER_RAGE, int32(rage * -1));
        target->CastSpell(target, SPELL_DRUID_FRENZIED_REGENERATION_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(heal));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dru_frenzied_regeneration::HandleRegeneration, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectApply.Register(&spell_dru_frenzied_regeneration::HandleHealthAfterApply, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH_2, AURA_EFFECT_HANDLE_REAL);

    }
};

class spell_dru_stampeding_roar : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_FERAL_SWIFTNESS,
                SPELL_DRUID_FERAL_SWIFTNESS_CLEAR_ROAR
            });
    }

    void HandleFeralSwiftness(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (GetCaster() != target)
            return;

        if (Aura* swiftness = target->GetAuraOfRankedSpell(SPELL_DRUID_FERAL_SWIFTNESS, target->GetGUID()))
            if (roll_chance_i(swiftness->GetSpellInfo()->Effects[EFFECT_1].BasePoints))
                target->CastSpell(target, SPELL_DRUID_FERAL_SWIFTNESS_CLEAR_ROAR, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_stampeding_roar::HandleFeralSwiftness, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_dru_feral_swiftness_clear : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAppliedAuras([](AuraApplication const* aurApp)->bool
        {
            SpellInfo const* auraSpellInfo = aurApp->GetBase()->GetSpellInfo();
            uint32 mechanicMask = auraSpellInfo->GetSpellMechanicMaskByEffectMask(EFFECT_ALL);
            return (mechanicMask & (1 << MECHANIC_ROOT)) || (mechanicMask & (1 << MECHANIC_SNARE));
        });
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_feral_swiftness_clear::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// -80318 - Blood in the Water
class spell_dru_blood_in_the_water : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_BLOOD_IN_THE_WATER_SCRIPT,
                SPELL_DRUID_T13_FERAL_2P_BONUS
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetDamageInfo() || !eventInfo.GetDamageInfo()->GetVictim())
            return false;

        float healthPct = 25.f;

        // T13 Bonus
        if (GetTarget()->HasAura(SPELL_DRUID_T13_FERAL_2P_BONUS))
            healthPct = sSpellMgr->AssertSpellInfo(SPELL_DRUID_T13_FERAL_2P_BONUS)->Effects[EFFECT_1].BasePoints;

        return eventInfo.GetDamageInfo()->GetVictim()->GetHealthPct() <= healthPct && roll_chance_i(50 * GetSpellInfo()->GetRank());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_BLOOD_IN_THE_WATER_SCRIPT, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dru_blood_in_the_water::CheckProc);
        OnEffectProc.Register(&spell_dru_blood_in_the_water::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 80863 - Blood in the Water
class spell_dru_blood_in_the_water_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_RIP });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Aura* aura = GetHitUnit()->GetAura(SPELL_DRUID_RIP, caster->GetGUID()))
                aura->RefreshDuration();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_blood_in_the_water_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 90164 - Astral Alignment
class spell_dru_astral_alignment : public AuraScript
{
    void HandleProc(AuraEffect const*  /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetAura()->ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_astral_alignment::HandleProc, EFFECT_0, SPELL_AURA_MOD_SPELL_CRIT_CHANCE);
    }
};

// 100977 - Harmony
class spell_dru_harmony_triggered : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_BLOOM });
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_BLOOM);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_dru_harmony_triggered::RemoveEffect, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 90165 - Item - Druid T11 Feral 4P Bonus
class spell_dru_item_t11_feral_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_STRENGTH_OF_THE_PANTHER });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_STRENGTH_OF_THE_PANTHER, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dru_item_t11_feral_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
    }
};

// 80964 - Skull Bash (Bear Form)
// 80965 - Skull Bash (Cat Form)
class spell_dru_skull_bash : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_SKULL_BASH_CHARGE,
                SPELL_DRUID_SKULL_BASH_INTERRUPT,
                SPELL_DRUID_SKULL_BASH_COST_INCREASE_R1,
                SPELL_DRUID_SKULL_BASH_COST_INCREASE_R2,
                SPELL_DRUID_BRUTAL_IMPACT_R1
            });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        caster->CastSpell(target, SPELL_DRUID_SKULL_BASH_CHARGE);
        caster->CastSpell(target, SPELL_DRUID_SKULL_BASH_INTERRUPT);
        if (Aura const* aura = caster->GetAuraOfRankedSpell(SPELL_DRUID_BRUTAL_IMPACT_R1, caster->GetGUID()))
            caster->CastSpell(target, aura->GetSpellInfo()->GetRank() == 1 ? SPELL_DRUID_SKULL_BASH_COST_INCREASE_R1 : SPELL_DRUID_SKULL_BASH_COST_INCREASE_R2);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_skull_bash::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 50464 - Nourish
class spell_dru_nourish : public SpellScript
{
    // Nourish heals for an additional 20% if Rejuvenation, Regrowth, Wild Growth or Lifebloom is on the target
    void HandleHealBonus(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        auto periodicHealEffects = GetHitUnit()->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
        if (std::any_of(periodicHealEffects.begin(), periodicHealEffects.end(), [caster](AuraEffect const* aurEff)
        {
            return (aurEff->GetCasterGUID() == caster->GetGUID()
                && aurEff->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_DRUID
                && !aurEff->GetSpellInfo()->SpellFamilyFlags.HasFlag(0x10 | 0x40, 0x10 | 0x4000000, 0));
        }))
            SetHitHeal(GetHitHeal() * 1.2f);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dru_nourish::HandleHealBonus, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

void AddSC_druid_spell_scripts()
{
    RegisterSpellScript(spell_dru_astral_alignment);
    RegisterSpellScript(spell_dru_berserk);
    RegisterSpellScript(spell_dru_blood_in_the_water);
    RegisterSpellScript(spell_dru_blood_in_the_water_script);
    RegisterSpellAndAuraScriptPair(spell_dru_dash, spell_dru_dash_AuraScript);
    RegisterSpellScript(spell_dru_eclipse);
    RegisterSpellScript(spell_dru_eclipse_mastery_driver_passive);
    RegisterSpellScript(spell_dru_effloresence);
    RegisterSpellScript(spell_dru_effloresence_aoe);
    RegisterSpellScript(spell_dru_effloresence_heal);
    RegisterSpellScript(spell_dru_empowered_touch);
    RegisterSpellScript(spell_dru_empowered_touch_script);
    RegisterSpellScript(spell_dru_enrage);
    RegisterSpellScript(spell_dru_ferocious_bite);
    RegisterSpellScript(spell_dru_frenzied_regeneration);
    RegisterSpellScript(spell_dru_glyph_of_starfire);
    RegisterSpellScript(spell_dru_glyph_of_starfire_proc);
    RegisterSpellScript(spell_dru_harmony);
    RegisterSpellScript(spell_dru_harmony_triggered);
    RegisterSpellScript(spell_dru_idol_lifebloom);
    RegisterSpellScript(spell_dru_innervate);
    RegisterSpellScript(spell_dru_insect_swarm);
    RegisterSpellScript(spell_dru_leader_of_the_pack);
    RegisterSpellScript(spell_dru_lifebloom);
    RegisterSpellScript(spell_dru_living_seed);
    RegisterSpellScript(spell_dru_living_seed_proc);
    RegisterSpellScript(spell_dru_moonfire);
    RegisterSpellScript(spell_dru_nourish);
    RegisterSpellScript(spell_dru_pulverize);
    RegisterSpellScript(spell_dru_rejuvenation);
    RegisterSpellScript(spell_dru_rip);
    RegisterSpellScript(spell_dru_savage_defense);
    RegisterSpellAndAuraScriptPair(spell_dru_savage_roar, spell_dru_savage_roar_AuraScript);
    RegisterSpellScript(spell_dru_shooting_stars);
    RegisterSpellScript(spell_dru_skull_bash);
    RegisterSpellScript(spell_dru_starfall_dummy);
    RegisterSpellScript(spell_dru_stampede);
    RegisterSpellScript(spell_dru_solar_beam);
    RegisterSpellAndAuraScriptPair(spell_dru_survival_instincts, spell_dru_survival_instincts_AuraScript);
    RegisterSpellScript(spell_dru_swift_flight_passive);
    RegisterSpellScript(spell_dru_swift_flight_form);
    RegisterSpellScript(spell_dru_flight_form);
    RegisterSpellScript(spell_dru_tiger_s_fury);
    RegisterSpellScript(spell_dru_tree_of_life);
    RegisterSpellScript(spell_dru_typhoon);
    RegisterSpellScript(spell_dru_t10_restoration_4p_bonus);
    RegisterSpellScript(spell_dru_item_t11_feral_4p_bonus);
    RegisterSpellScript(spell_dru_wild_growth);
    RegisterSpellScript(spell_dru_wild_mushroom);
    RegisterSpellScript(spell_dru_wild_mushroom_detonate);
    RegisterSpellScript(spell_dru_stampeding_roar);
    RegisterSpellScript(spell_dru_feral_swiftness_clear);
}
