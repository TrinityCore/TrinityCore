/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

enum DruidSpells
{
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
    SPELL_DRUID_FUNGAL_GROWTH_R1            = 78788,
    SPELL_DRUID_FUNGAL_GROWTH_R2            = 78789,
    SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R1     = 81291,
    SPELL_DRUID_FUNGAL_GROWTH_SUMMON_R2     = 81283,
    SPELL_DRUID_FUROR_ENERGIZE_RAGE         = 17057,
    SPELL_DRUID_FUROR_ENERGIZE_ENERGY       = 17099,
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
    SPELL_DRUID_KING_OF_THE_JUNGLE          = 48492,
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
    SPELL_DRUID_SURVIVAL_INSTINCTS          = 50322,
    SPELL_DRUID_SAVAGE_ROAR                 = 62071,
    SPELL_DRUID_SHOOTING_STARS              = 93400,
    SPELL_DRUID_STAMPEDE_BAER_RANK_1        = 81016,
    SPELL_DRUID_STAMPEDE_CAT_RANK_1         = 81021,
    SPELL_DRUID_STAMPEDE_CAT_STATE          = 109881,
    SPELL_DRUID_SOLAR_BEAM_SILENCE          = 81261,
    SPELL_DRUID_SUNFIRE                     = 93402,
    SPELL_DRUID_SUNFIRE_TALENT              = 93401,
    SPELL_DRUID_TIGER_S_FURY_ENERGIZE       = 51178,
    SPELL_DRUID_TREE_OF_LIFE                = 33891,
    SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1      = 5420,
    SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2      = 81097,
    SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3      = 81098,
    SPELL_DRUID_WILD_MUSHROOM               = 88747,
    SPELL_DRUID_WILD_MUSHROOM_DAMAGE        = 78777,
    SPELL_DRUID_WILD_MUSHROOM_SUICIDE       = 92853,
    SPELL_DRUID_WILD_MUSHROOM_VISUAL        = 92701
};

enum DruidSpellIconIds
{
    SPELL_ICON_ID_NATURES_BOUNTY            = 197,
    SPELL_ICON_ID_DREAMSTATE                = 2255,
    SPELL_ICON_ID_GLYPH_OF_INNERVATE        = 62,
    SPELL_ICON_ID_EUPHORIA                  = 4431,
    SPELL_ICON_ID_SAVAGE_DEFENDER           = 146,
    SPELL_ICON_ID_GLYPH_OF_FEROCIOUS_BITE   = 1680
};

enum MiscSpells
{
    SPELL_CATEGORY_MANGLE_BEAR              = 971
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
        AfterEffectApply += AuraEffectApplyFn(spell_dru_berserk::HandleEffectApply, EFFECT_1, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 1850 - Dash
class spell_dru_dash : public AuraScript
{
    PrepareAuraScript(spell_dru_dash);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
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

// 48517 - Eclipse (Solar)
// 48518 - Eclipse (Lunar)
class spell_dru_eclipse : public AuraScript
{
    PrepareAuraScript(spell_dru_eclipse);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_NATURES_GRACE,
                SPELL_DRUID_LUNAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE,
                SPELL_DRUID_LUNAR_ECLIPSE,
                SPELL_DRUID_EUPHORIA_MANA_ENERGIZE,
                SPELL_DRUID_SUNFIRE,
                SPELL_DRUID_SUNFIRE_TALENT,
                SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE
            });
    }

    void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Reset Nature's Grace proc cooldown
        if (Aura* aura = caster->GetAuraOfRankedSpell(SPELL_DRUID_NATURES_GRACE))
            aura->ResetProcCooldown();

        // Handle Euphoria talent
        if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_EUPHORIA, EFFECT_2))
            if (int32 amount = aurEff->GetAmount())
                caster->CastCustomSpell(caster, SPELL_DRUID_EUPHORIA_MANA_ENERGIZE, &amount, 0, 0, true, nullptr, aurEff);

        // Handle Sunfire talent
        if (GetSpellInfo()->Id == SPELL_DRUID_SOLAR_ECLIPSE && caster->HasAura(SPELL_DRUID_SUNFIRE_TALENT))
            if (!caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE))
                caster->CastCustomSpell(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE, SPELLVALUE_BASE_POINT0, SPELL_DRUID_SUNFIRE, caster, true);

        // Update Eclipse Marker
        if (GetSpellInfo()->Id == SPELL_DRUID_SOLAR_ECLIPSE && caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER))
        {
            caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE_MARKER);
            caster->CastSpell(caster, SPELL_DRUID_LUNAR_ECLIPSE_MARKER, true);
        }
        else if (GetSpellInfo()->Id == SPELL_DRUID_LUNAR_ECLIPSE && caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER))
        {
            caster->RemoveAurasDueToSpell(SPELL_DRUID_LUNAR_ECLIPSE_MARKER);
            caster->CastSpell(caster, SPELL_DRUID_SOLAR_ECLIPSE_MARKER, true);
        }
    }

    void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (GetSpellInfo()->Id == SPELL_DRUID_SOLAR_ECLIPSE && caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE))
            caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE_SUNFIRE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_eclipse::ApplyEffect, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_eclipse::RemoveEffect, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 2912, 5176, 78674 - Starfire, Wrath, and Starsurge
class spell_dru_eclipse_energize : public SpellScript
{
    PrepareSpellScript(spell_dru_eclipse_energize);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_LUNAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE_MARKER,
                SPELL_DRUID_SOLAR_ECLIPSE,
                SPELL_DRUID_LUNAR_ECLIPSE,
                SPELL_DRUID_WRATH,
                SPELL_DRUID_STARFIRE,
                SPELL_DRUID_STARSURGE,
                SPELL_DRUID_MOONFIRE,
                SPELL_DRUID_SUNFIRE,
                SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE,
                SPELL_DRUID_EUPHORIA_ENERGIZE,
                SPELL_DRUID_LUNAR_SHOWER,
            });
    }

    bool Load() override
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return false;

        // Only druids may trigger the following script
        if (player->getClass() != CLASS_DRUID)
            return false;

        // Check if the currently active specialization is 'Balance'
        if (player->GetPrimaryTalentTree(player->GetActiveSpec()) != TALENT_TREE_DRUID_BALANCE)
            return false;

        return true;
    }

    void HandleEnergize(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 amount = 0;
        bool firstCast = (!caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER) && !caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER));
        bool negativeAmount = caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER);

        // Setting the energize amount
        switch (GetSpellInfo()->Id)
        {
            case SPELL_DRUID_WRATH:
                amount -= GetSpellInfo()->Effects[EFFECT_1].BasePoints;
                break;
            case SPELL_DRUID_STARFIRE:
                amount += GetSpellInfo()->Effects[EFFECT_1].BasePoints;
                break;
            case SPELL_DRUID_STARSURGE:
            {
                int32 bp = GetSpellInfo()->Effects[EFFECT_1].BasePoints;
                amount += negativeAmount ? -bp : bp;
                break;
            }
            case SPELL_DRUID_SUNFIRE:
                if (Aura* aura = caster->GetAuraOfRankedSpell(SPELL_DRUID_LUNAR_SHOWER))
                    if (caster->HasAura(aura->GetSpellInfo()->Effects[EFFECT_0].TriggerSpell))
                        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_DRUID_LUNAR_SHOWER))
                            amount -= spell->Effects[EFFECT_2].BasePoints;
                break;
            case SPELL_DRUID_MOONFIRE:
                if (Aura* aura = caster->GetAuraOfRankedSpell(SPELL_DRUID_LUNAR_SHOWER))
                    if (caster->HasAura(aura->GetSpellInfo()->Effects[EFFECT_0].TriggerSpell))
                        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(SPELL_DRUID_LUNAR_SHOWER))
                            amount += spell->Effects[EFFECT_2].BasePoints;
                break;
            default:
                break;
        }

        // Check if we are allowed to get the energize amount
        if (!firstCast)
        {
            if (negativeAmount && amount >= 0)
                return;
            else if (!negativeAmount && amount <= 0)
                return;
        }

        // Casting Eclipse marker if necessary
        if (amount < 0 && !caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE_MARKER))
            caster->CastSpell(caster, SPELL_DRUID_LUNAR_ECLIPSE_MARKER, true);
        else if (amount > 0 && !caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE_MARKER))
           caster->CastSpell(caster, SPELL_DRUID_SOLAR_ECLIPSE_MARKER, true);

        // Casting energize amount
        caster->CastCustomSpell(caster, SPELL_DRUID_ECLIPSE_GENERAL_ENERGIZE, &amount, 0, 0, true);

        // Handle Euphoria talent
        if (!caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE) && !caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE))
            if (GetSpellInfo()->Id == SPELL_DRUID_STARFIRE || GetSpellInfo()->Id == SPELL_DRUID_WRATH)
                if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_EUPHORIA, EFFECT_0))
                    if (roll_chance_i(aurEff->GetAmount()))
                        caster->CastCustomSpell(caster, SPELL_DRUID_EUPHORIA_ENERGIZE, &amount, 0, 0, true, nullptr, aurEff);

        // Remove Eclipse states if we passed the 0 Lunar Power point
        int8 power = caster->GetPower(POWER_ECLIPSE);
        if (caster->HasAura(SPELL_DRUID_SOLAR_ECLIPSE) && power <= 0)
            caster->RemoveAurasDueToSpell(SPELL_DRUID_SOLAR_ECLIPSE);
        else if (caster->HasAura(SPELL_DRUID_LUNAR_ECLIPSE) && power >= 0)
            caster->RemoveAurasDueToSpell(SPELL_DRUID_LUNAR_ECLIPSE);
    }

    void Register() override
    {
        if (m_scriptSpellId == SPELL_DRUID_MOONFIRE || m_scriptSpellId == SPELL_DRUID_SUNFIRE)
            OnEffectLaunch += SpellEffectFn(spell_dru_eclipse_energize::HandleEnergize, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        else
            OnEffectLaunch += SpellEffectFn(spell_dru_eclipse_energize::HandleEnergize, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 79577 - Eclipse Mastery Passive Driver
class spell_dru_eclipse_mastery_driver_passive : public AuraScript
{
    PrepareAuraScript(spell_dru_eclipse_mastery_driver_passive);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_LUNAR_ECLIPSE,
                SPELL_DRUID_SOLAR_ECLIPSE,
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return (!GetTarget()->HasAura(SPELL_DRUID_LUNAR_ECLIPSE) && !GetTarget()->HasAura(SPELL_DRUID_SOLAR_ECLIPSE));
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_eclipse_mastery_driver_passive::CheckProc);
    }
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
            target->CastCustomSpell(SPELL_DRUID_ENRAGE_MOD_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true);

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

// 54846 - Glyph of Starfire
class spell_dru_glyph_of_starfire : public SpellScript
{
    PrepareSpellScript(spell_dru_glyph_of_starfire);

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
        OnEffectHitTarget += SpellEffectFn(spell_dru_glyph_of_starfire::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 54845 - Glyph of Starfire
class spell_dru_glyph_of_starfire_proc : public AuraScript
{
    PrepareAuraScript(spell_dru_glyph_of_starfire_proc);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_GLYPH_OF_STARFIRE });
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_GLYPH_OF_STARFIRE, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_glyph_of_starfire_proc::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
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
        Unit* target = GetUnitOwner();
        if (!target)
            return;

        uint32 mana = target->GetMaxPower(POWER_MANA);
        if (!mana)
            return;

        uint8 ticks = aurEff->GetTotalTicks();

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
                if (AuraEffect* glyph = caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, SPELL_ICON_ID_GLYPH_OF_INNERVATE, EFFECT_0))
                    caster->CastSpell(caster, SPELL_DRUID_INNERVATE_TRIGGERED, true);
            }
        }

        amount = CalculatePct(mana, percentage) / aurEff->GetTotalTicks();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_innervate::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
    }
};

// 5570 - Insect Swarm
class spell_dru_insect_swarm : public AuraScript
{
    PrepareAuraScript(spell_dru_insect_swarm);

    void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect const* relicAurEff = caster->GetAuraEffect(SPELL_DRUID_ITEM_T8_BALANCE_RELIC, EFFECT_0))
                amount += relicAurEff->GetAmount() / aurEff->GetTotalTicks();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_insect_swarm::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 33763 - Lifebloom
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

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        // Final heal only on duration end
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        // final heal
        int32 stack = GetStackAmount();
        int32 healAmount = aurEff->GetAmount();
        if (Unit* caster = GetCaster())
        {
            healAmount = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), healAmount, HEAL, stack);
            healAmount = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), healAmount, HEAL, stack);

            GetTarget()->CastCustomSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());

            // restore mana
            int32 returnMana = CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * stack / 2;
            caster->CastCustomSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, &returnMana, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());
            return;
        }

        GetTarget()->CastCustomSpell(GetTarget(), SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());
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
                    target->CastCustomSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, nullptr, GetCasterGUID());

                    // restore mana
                    int32 returnMana = CalculatePct(caster->GetCreateMana(), GetSpellInfo()->ManaCostPercentage) * dispelInfo->GetRemovedCharges() / 2;
                    caster->CastCustomSpell(caster, SPELL_DRUID_LIFEBLOOM_ENERGIZE, &returnMana, nullptr, nullptr, true, nullptr, nullptr, GetCasterGUID());
                    return;
                }

                target->CastCustomSpell(target, SPELL_DRUID_LIFEBLOOM_FINAL_HEAL, &healAmount, nullptr, nullptr, true, nullptr, nullptr, GetCasterGUID());
            }
        }
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
        return ValidateSpellInfo({ SPELL_DRUID_LIVING_SEED_PROC });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 amount = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
        GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_PROC, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true, nullptr, aurEff);
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
        return ValidateSpellInfo({ SPELL_DRUID_LIVING_SEED_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastCustomSpell(SPELL_DRUID_LIVING_SEED_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_living_seed_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 1079 - Rip
// Updated 4.3.4
class spell_dru_rip : public AuraScript
{
    PrepareAuraScript(spell_dru_rip);

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
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dru_rip::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 62606 - Savage Defense
class spell_dru_savage_defense : public AuraScript
{
    PrepareAuraScript(spell_dru_savage_defense);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();

        uint32 absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(target);
        if (AuraEffect* masteryAurEff = target->GetDummyAuraEffect(SPELLFAMILY_HUNTER, SPELL_ICON_ID_SAVAGE_DEFENDER, EFFECT_0)) // no idea why hunter...
            absorbPct += masteryAurEff->GetAmount();

        int32 amount = uint32(CalculatePct(GetTarget()->GetTotalAttackPowerValue(BASE_ATTACK), absorbPct));
        target->CastCustomSpell(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, SPELLVALUE_BASE_POINT0, amount, target, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_savage_defense::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
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

class spell_dru_savage_roar_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_dru_savage_roar_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SAVAGE_ROAR });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DRUID_SAVAGE_ROAR, true, nullptr, aurEff, GetCasterGUID());
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SAVAGE_ROAR);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_savage_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_savage_roar_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 50286 - Starfall (Dummy)
class spell_dru_starfall_dummy : public SpellScript
{
    PrepareSpellScript(spell_dru_starfall_dummy);

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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_starfall_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_dru_starfall_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -78892 - Stampede
class spell_dru_stampede : public AuraScript
{
    PrepareAuraScript(spell_dru_stampede);

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
        if (GetTarget()->GetShapeshiftForm() != FORM_CAT || eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_CAT)
            return;

        GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_CAT_RANK_1, GetSpellInfo()->GetRank()), true, nullptr, aurEff);
        GetTarget()->CastSpell(GetTarget(), SPELL_DRUID_STAMPEDE_CAT_STATE, true, nullptr, aurEff);
    }

    void HandleEffectBearProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (GetTarget()->GetShapeshiftForm() != FORM_BEAR || eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_DRUID_FERAL_CHARGE_BEAR)
            return;

        GetTarget()->CastSpell(GetTarget(), sSpellMgr->GetSpellWithRank(SPELL_DRUID_STAMPEDE_BAER_RANK_1, GetSpellInfo()->GetRank()), true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_stampede::HandleEffectCatProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_dru_stampede::HandleEffectBearProc, EFFECT_1, SPELL_AURA_DUMMY);
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

class spell_dru_survival_instincts_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_dru_survival_instincts_AuraScript);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SURVIVAL_INSTINCTS });
    }

    void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        int32 bp0 = target->CountPctFromMaxHealth(aurEff->GetAmount());
        target->CastCustomSpell(target, SPELL_DRUID_SURVIVAL_INSTINCTS, &bp0, nullptr, nullptr, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_SURVIVAL_INSTINCTS);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_survival_instincts_AuraScript::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_survival_instincts_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
    }
};

// 40121 - Swift Flight Form (Passive)
class spell_dru_swift_flight_passive : public AuraScript
{
    PrepareAuraScript(spell_dru_swift_flight_passive);

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

// 33943 - Flight Form (Shapeshift)
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

// 5217 - Tiger's Fury
class spell_dru_tiger_s_fury : public SpellScript
{
    PrepareSpellScript(spell_dru_tiger_s_fury);

    void OnHit()
    {
        if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffectOfRankedSpell(SPELL_DRUID_KING_OF_THE_JUNGLE, EFFECT_1))
            GetHitUnit()->CastCustomSpell(SPELL_DRUID_TIGER_S_FURY_ENERGIZE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetHitUnit(), true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_dru_tiger_s_fury::OnHit);
    }
};

// 61391 - Typhoon
class spell_dru_typhoon : public SpellScript
{
    PrepareSpellScript(spell_dru_typhoon);

    void HandleKnockBack(SpellEffIndex effIndex)
    {
        // Glyph of Typhoon
        if (GetCaster()->HasAura(SPELL_DRUID_GLYPH_OF_TYPHOON))
            PreventHitDefaultEffect(effIndex);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dru_typhoon::HandleKnockBack, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
    }
};

// 70691 - Item T10 Restoration 4P Bonus
class spell_dru_t10_restoration_4p_bonus : public SpellScript
{
    PrepareSpellScript(spell_dru_t10_restoration_4p_bonus);

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
    PrepareSpellScript(spell_dru_wild_growth);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_TREE_OF_LIFE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaidCheck(GetCaster()));

        uint8 maxTargets = GetSpellInfo()->Effects[EFFECT_0].BasePoints;

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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_wild_growth::SetTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }

private:
    std::list<WorldObject*> _targets;
};

// 78675 - Solar Beam
class spell_dru_solar_beam : public AuraScript
{
    PrepareAuraScript(spell_dru_solar_beam);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_SOLAR_BEAM_SILENCE });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), SPELL_DRUID_SOLAR_BEAM_SILENCE, true);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_solar_beam::HandleEffectPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -34151 - Efflorescence (Proc Aura)
class spell_dru_effloresence : public AuraScript
{
    PrepareAuraScript(spell_dru_effloresence);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 healAmount = 0;

        if (HealInfo* heal = eventInfo.GetHealInfo())
        {
            healAmount = CalculatePct(heal->GetHeal(), GetSpellInfo()->Effects[EFFECT_0].BasePoints);
            if (healAmount)
                GetTarget()->CastCustomSpell(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, SPELLVALUE_BASE_POINT1, healAmount, heal->GetTarget(), true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_effloresence::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 81262 - Efflorescence (Area Effect)
class spell_dru_effloresence_aoe : public AuraScript
{
    PrepareAuraScript(spell_dru_effloresence_aoe);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_EFFLORESCENCE_HEAL });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            if (DynamicObject* dyn = caster->GetDynObject(aurEff->GetId()))
                caster->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), SPELL_DRUID_EFFLORESCENCE_HEAL, true, nullptr, aurEff, caster->GetGUID());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dru_effloresence_aoe::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//  81269 - Efflorescence (Heal)
class spell_dru_effloresence_heal : public SpellScript
{
    PrepareSpellScript(spell_dru_effloresence_heal);

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
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dru_effloresence_heal::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_dru_effloresence_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 774 - Rejuvenation
class spell_dru_rejuvenation : public AuraScript
{
    PrepareAuraScript(spell_dru_rejuvenation);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_NATURES_BOUNTY });
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
                    caster->CastCustomSpell(caster, SPELL_DRUID_NATURES_BOUNTY, &bp0, 0, 0, true);
                }
            }
        }
    }


    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
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

    void Register()
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_rejuvenation::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_rejuvenation::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 33891 - Tree of Life
class spell_dru_tree_of_life : public AuraScript
{
    PrepareAuraScript(spell_dru_tree_of_life);

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
            target->CastSpell(target, SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1, true, nullptr, aurEff);
            target->CastSpell(target, SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2, true, nullptr, aurEff);
            target->CastSpell(target, SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3, true, nullptr, aurEff);

        }
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->RemoveAurasDueToSpell(SPELL_DRUID_TREE_OF_LIFE_PASSIVE_1);
            target->RemoveAurasDueToSpell(SPELL_DRUID_TREE_OF_LIFE_PASSIVE_2);
            target->RemoveAurasDueToSpell(SPELL_DRUID_TREE_OF_LIFE_PASSIVE_3);
        }
    }

    void Register()
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dru_tree_of_life::AfterApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_tree_of_life::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 77495 - Harmony
class spell_dru_harmony : public AuraScript
{
    PrepareAuraScript(spell_dru_harmony);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUID_HARMONY });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        int32 amount = aurEff->GetAmount();
        GetTarget()->CastCustomSpell(SPELL_DRUID_HARMONY, SPELLVALUE_BASE_POINT0, amount, GetTarget(), true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dru_harmony::HandleProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
    }
};

// 17007 - Leader of the Pack
class spell_dru_leader_of_the_pack : public AuraScript
{
    PrepareAuraScript(spell_dru_leader_of_the_pack);

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
            target->CastCustomSpell(SPELL_DRUID_LEADER_OF_THE_PACK_HEAL, SPELLVALUE_BASE_POINT0, heal, target, true, nullptr, aurEff);

        if (mana)
            target->CastCustomSpell(SPELL_DRUID_LEADER_OF_THE_PACK_ENERGIZE, SPELLVALUE_BASE_POINT0, mana, target, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_leader_of_the_pack::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_leader_of_the_pack::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dru_wild_mushroom : public SpellScript
{
    PrepareSpellScript(spell_dru_wild_mushroom);

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

    void Register()
    {
        AfterCast += SpellCastFn(spell_dru_wild_mushroom::HandleSummon);
    }
};

class spell_dru_wild_mushroom_detonate : public SpellScript
{
    PrepareSpellScript(spell_dru_wild_mushroom_detonate);

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
        OnEffectHitTarget += SpellEffectFn(spell_dru_wild_mushroom_detonate::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 16913 - Moonfire (Passive)
class spell_dru_moonfire : public AuraScript
{
    PrepareAuraScript(spell_dru_moonfire);

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
        AfterEffectRemove += AuraEffectRemoveFn(spell_dru_moonfire::RemoveEffect, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_dru_furor : public AuraScript
{
    PrepareAuraScript(spell_dru_furor);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DRUID_FUROR_ENERGIZE_ENERGY,
                SPELL_DRUID_FUROR_ENERGIZE_RAGE
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();

        if (target->GetShapeshiftForm() == FORM_BEAR)
            target->CastSpell(target, SPELL_DRUID_FUROR_ENERGIZE_RAGE, true, nullptr, aurEff);
        else if (target->GetShapeshiftForm() == FORM_CAT)
        {
            int32 amount = CalculatePct(100, aurEff->GetAmount());
            target->CastCustomSpell(SPELL_DRUID_FUROR_ENERGIZE_ENERGY, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_furor::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_furor::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 22568 - Ferocious Bite
class spell_dru_ferocious_bite : public SpellScript
{
    PrepareSpellScript(spell_dru_ferocious_bite);

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
                caster->CastCustomSpell(SPELL_DRUID_GLYPH_OF_FEROCIOUS_BITE, SPELLVALUE_BASE_POINT0, bp, caster, true);
            }

        }
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_dru_ferocious_bite::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// -33879 - Empowered Touch
class spell_dru_empowered_touch : public AuraScript
{
    PrepareAuraScript(spell_dru_empowered_touch);

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
        target->CastSpell(eventInfo.GetProcTarget(), SPELL_DRUID_EMPOWERED_TOUCH_SCRIPT, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dru_empowered_touch::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dru_empowered_touch::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 88433 - Empowered Touch
class spell_dru_empowered_touch_script : public SpellScript
{
    PrepareSpellScript(spell_dru_empowered_touch_script);

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
        OnEffectHitTarget += SpellEffectFn(spell_dru_empowered_touch_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_druid_spell_scripts()
{
    RegisterAuraScript(spell_dru_berserk);
    RegisterAuraScript(spell_dru_dash);
    RegisterAuraScript(spell_dru_eclipse);
    RegisterSpellScript(spell_dru_eclipse_energize);
    RegisterAuraScript(spell_dru_eclipse_mastery_driver_passive);
    RegisterAuraScript(spell_dru_effloresence);
    RegisterAuraScript(spell_dru_effloresence_aoe);
    RegisterSpellScript(spell_dru_effloresence_heal);
    RegisterAuraScript(spell_dru_empowered_touch);
    RegisterSpellScript(spell_dru_empowered_touch_script);
    RegisterAuraScript(spell_dru_enrage);
    RegisterSpellScript(spell_dru_ferocious_bite);
    RegisterAuraScript(spell_dru_furor);
    RegisterSpellScript(spell_dru_glyph_of_starfire);
    RegisterAuraScript(spell_dru_glyph_of_starfire_proc);
    RegisterAuraScript(spell_dru_harmony);
    RegisterAuraScript(spell_dru_idol_lifebloom);
    RegisterAuraScript(spell_dru_innervate);
    RegisterAuraScript(spell_dru_insect_swarm);
    RegisterAuraScript(spell_dru_leader_of_the_pack);
    RegisterAuraScript(spell_dru_lifebloom);
    RegisterAuraScript(spell_dru_living_seed);
    RegisterAuraScript(spell_dru_living_seed_proc);
    RegisterAuraScript(spell_dru_moonfire);
    RegisterAuraScript(spell_dru_rejuvenation);
    RegisterAuraScript(spell_dru_rip);
    RegisterAuraScript(spell_dru_savage_defense);
    RegisterSpellAndAuraScriptPair(spell_dru_savage_roar, spell_dru_savage_roar_AuraScript);
    RegisterSpellScript(spell_dru_starfall_dummy);
    RegisterAuraScript(spell_dru_stampede);
    RegisterAuraScript(spell_dru_solar_beam);
    RegisterSpellAndAuraScriptPair(spell_dru_survival_instincts, spell_dru_survival_instincts_AuraScript);
    RegisterAuraScript(spell_dru_swift_flight_passive);
    RegisterSpellScript(spell_dru_flight_form);
    RegisterSpellScript(spell_dru_tiger_s_fury);
    RegisterAuraScript(spell_dru_tree_of_life);
    RegisterSpellScript(spell_dru_typhoon);
    RegisterSpellScript(spell_dru_t10_restoration_4p_bonus);
    RegisterSpellScript(spell_dru_wild_growth);
    RegisterSpellScript(spell_dru_wild_mushroom);
    RegisterSpellScript(spell_dru_wild_mushroom_detonate);
}
