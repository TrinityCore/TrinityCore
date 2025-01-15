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
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by demon hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum DemonHunterSpells
{
    AREATRIGGER_DH_SHATTERED_SOULS_HAVOC           = 8352,
    AREATRIGGER_DH_SHATTERED_SOULS_HAVOC_DEMON     = 11231,
    AREATRIGGER_DH_SHATTERED_SOULS_VENGEANCE       = 11266,
    AREATRIGGER_DH_SHATTERED_SOULS_VENGEANCE_DEMON = 10693,
    AREATRIGGER_DH_SOUL_FRAGMENT_HAVOC             = 12929,
    AREATRIGGER_DH_SOUL_FRAGMENT_VENGEANCE         = 10665,

    SPELL_DH_ABYSSAL_STRIKE                        = 207550,
    SPELL_DH_ANNIHILATION                          = 201427,
    SPELL_DH_ANNIHILATION_MH                       = 227518,
    SPELL_DH_ANNIHILATION_OH                       = 201428,
    SPELL_DH_AWAKEN_THE_DEMON_WITHIN_CD            = 207128,
    SPELL_DH_BLUR                                  = 212800,
    SPELL_DH_BLUR_TRIGGER                          = 198589,
    SPELL_DH_BURNING_ALIVE                         = 207739,
    SPELL_DH_BURNING_ALIVE_TARGET_SELECTOR         = 207760,
    SPELL_DH_CALCIFIED_SPIKES_TALENT               = 389720,
    SPELL_DH_CALCIFIED_SPIKES_MOD_DAMAGE           = 391171,
    SPELL_DH_CHAOS_NOVA                            = 179057,
    SPELL_DH_CHAOS_STRIKE                          = 162794,
    SPELL_DH_CHAOS_STRIKE_ENERGIZE                 = 193840,
    SPELL_DH_CHAOS_STRIKE_MH                       = 222031,
    SPELL_DH_CHAOS_STRIKE_OH                       = 199547,
    SPELL_DH_CHAOTIC_TRANSFORMATION                = 388112,
    SPELL_DH_CHARRED_WARBLADES_HEAL                = 213011,
    SPELL_DH_COLLECTIVE_ANGUISH                    = 390152,
    SPELL_DH_COLLECTIVE_ANGUISH_EYE_BEAM           = 391057,
    SPELL_DH_COLLECTIVE_ANGUISH_EYE_BEAM_DAMAGE    = 391058,
    SPELL_DH_COLLECTIVE_ANGUISH_FEL_DEVASTATION    = 393831,
    SPELL_DH_CONSUME_SOUL_HAVOC                    = 228542,
    SPELL_DH_CONSUME_SOUL_HAVOC_DEMON              = 228556,
    SPELL_DH_CONSUME_SOUL_HAVOC_SHATTERED          = 228540,
    SPELL_DH_CONSUME_SOUL_HEAL                     = 203794,
    SPELL_DH_CONSUME_SOUL_VENGEANCE                = 208014,
    SPELL_DH_CONSUME_SOUL_VENGEANCE_DEMON          = 210050,
    SPELL_DH_CONSUME_SOUL_VENGEANCE_SHATTERED      = 210047,
    SPELL_DH_CYCLE_OF_HATRED                       = 258887,
    SPELL_DH_DARKGLARE_BOON                        = 389708,
    SPELL_DH_DARKGLARE_BOON_ENERGIZE               = 391345,
    SPELL_DH_DARKNESS_ABSORB                       = 209426,
    SPELL_DH_DEFLECTING_SPIKES                     = 321028,
    SPELL_DH_DEMON_BLADES_DMG                      = 203796,
    SPELL_DH_DEMON_SPIKES                          = 203819,
    SPELL_DH_DEMON_SPIKES_TRIGGER                  = 203720,
    SPELL_DH_DEMONIC                               = 213410,
    SPELL_DH_DEMONIC_ORIGINS                       = 235893,
    SPELL_DH_DEMONIC_ORIGINS_BUFF                  = 235894,
    SPELL_DH_DEMONIC_TRAMPLE_DMG                   = 208645,
    SPELL_DH_DEMONIC_TRAMPLE_STUN                  = 213491,
    SPELL_DH_DEMONS_BITE                           = 162243,
    SPELL_DH_ESSENCE_BREAK_DEBUFF                  = 320338,
    SPELL_DH_EYE_BEAM                              = 198013,
    SPELL_DH_EYE_BEAM_DAMAGE                       = 198030,
    SPELL_DH_EYE_OF_LEOTHERAS_DMG                  = 206650,
    SPELL_DH_FEAST_OF_SOULS                        = 207697,
    SPELL_DH_FEAST_OF_SOULS_PERIODIC_HEAL          = 207693,
    SPELL_DH_FEED_THE_DEMON                        = 218612,
    SPELL_DH_FEL_BARRAGE                           = 211053,
    SPELL_DH_FEL_BARRAGE_DMG                       = 211052,
    SPELL_DH_FEL_BARRAGE_PROC                      = 222703,
    SPELL_DH_FEL_DEVASTATION                       = 212084,
    SPELL_DH_FEL_DEVASTATION_DMG                   = 212105,
    SPELL_DH_FEL_DEVASTATION_HEAL                  = 212106,
    SPELL_DH_FEL_FLAME_FORTIFICATION_TALENT        = 389705,
    SPELL_DH_FEL_FLAME_FORTIFICATION_MOD_DAMAGE    = 393009,
    SPELL_DH_FEL_RUSH                              = 195072,
    SPELL_DH_FEL_RUSH_DMG                          = 192611,
    SPELL_DH_FEL_RUSH_GROUND                       = 197922,
    SPELL_DH_FEL_RUSH_WATER_AIR                    = 197923,
    SPELL_DH_FELBLADE                              = 232893,
    SPELL_DH_FELBLADE_CHARGE                       = 213241,
    SPELL_DH_FELBLADE_COOLDOWN_RESET_PROC_HAVOC    = 236167,
    SPELL_DH_FELBLADE_COOLDOWN_RESET_PROC_VENGEANCE= 203557,
    SPELL_DH_FELBLADE_COOLDOWN_RESET_PROC_VISUAL   = 204497,
    SPELL_DH_FELBLADE_DAMAGE                       = 213243,
    SPELL_DH_FIERY_BRAND                           = 204021,
    SPELL_DH_FIERY_BRAND_RANK_2                    = 320962,
    SPELL_DH_FIERY_BRAND_DEBUFF_RANK_1             = 207744,
    SPELL_DH_FIERY_BRAND_DEBUFF_RANK_2             = 207771,
    SPELL_DH_FIRST_BLOOD                           = 206416,
    SPELL_DH_FLAME_CRASH                           = 227322,
    SPELL_DH_FRAILTY                               = 224509,
    SPELL_DH_FURIOUS_GAZE                          = 343311,
    SPELL_DH_FURIOUS_GAZE_BUFF                     = 343312,
    SPELL_DH_FURIOUS_THROWS                        = 393029,
    SPELL_DH_GLIDE                                 = 131347,
    SPELL_DH_GLIDE_DURATION                        = 197154,
    SPELL_DH_GLIDE_KNOCKBACK                       = 196353,
    SPELL_DH_HAVOC_MASTERY                         = 185164,
    SPELL_DH_ILLIDANS_GRASP                        = 205630,
    SPELL_DH_ILLIDANS_GRASP_DAMAGE                 = 208618,
    SPELL_DH_ILLIDANS_GRASP_JUMP_DEST              = 208175,
    SPELL_DH_INNER_DEMON_BUFF                      = 390145,
    SPELL_DH_INNER_DEMON_DAMAGE                    = 390137,
    SPELL_DH_INNER_DEMON_TALENT                    = 389693,
    SPELL_DH_INFERNAL_STRIKE_CAST                  = 189110,
    SPELL_DH_INFERNAL_STRIKE_IMPACT_DAMAGE         = 189112,
    SPELL_DH_INFERNAL_STRIKE_JUMP                  = 189111,
    SPELL_DH_JAGGED_SPIKES                         = 205627,
    SPELL_DH_JAGGED_SPIKES_DMG                     = 208790,
    SPELL_DH_JAGGED_SPIKES_PROC                    = 208796,
    SPELL_DH_MANA_RIFT_DMG_POWER_BURN              = 235904,
    SPELL_DH_METAMORPHOSIS                         = 191428,
    SPELL_DH_METAMORPHOSIS_DUMMY                   = 191427,
    SPELL_DH_METAMORPHOSIS_IMPACT_DAMAGE           = 200166,
    SPELL_DH_METAMORPHOSIS_RESET                   = 320645,
    SPELL_DH_METAMORPHOSIS_TRANSFORM               = 162264,
    SPELL_DH_METAMORPHOSIS_VENGEANCE_TRANSFORM     = 187827,
    SPELL_DH_MOMENTUM                              = 208628,
    SPELL_DH_NEMESIS_ABERRATIONS                   = 208607,
    SPELL_DH_NEMESIS_BEASTS                        = 208608,
    SPELL_DH_NEMESIS_CRITTERS                      = 208609,
    SPELL_DH_NEMESIS_DEMONS                        = 208608,
    SPELL_DH_NEMESIS_DRAGONKIN                     = 208610,
    SPELL_DH_NEMESIS_ELEMENTALS                    = 208611,
    SPELL_DH_NEMESIS_GIANTS                        = 208612,
    SPELL_DH_NEMESIS_HUMANOIDS                     = 208605,
    SPELL_DH_NEMESIS_MECHANICALS                   = 208613,
    SPELL_DH_NEMESIS_UNDEAD                        = 208614,
    SPELL_DH_RAIN_FROM_ABOVE                       = 206803,
    SPELL_DH_RAIN_OF_CHAOS                         = 205628,
    SPELL_DH_RAIN_OF_CHAOS_IMPACT                  = 232538,
    SPELL_DH_RAZOR_SPIKES                          = 210003,
    SPELL_DH_RESTLESS_HUNTER_TALENT                = 390142,
    SPELL_DH_RESTLESS_HUNTER_BUFF                  = 390212,
    SPELL_DH_SEVER                                 = 235964,
    SPELL_DH_SHATTER_SOUL                          = 209980,
    SPELL_DH_SHATTER_SOUL_1                        = 209981,
    SPELL_DH_SHATTER_SOUL_2                        = 210038,
    SPELL_DH_SHATTERED_SOUL                        = 226258,
    SPELL_DH_SHATTERED_SOUL_LESSER_SOUL_FRAGMENT_1 = 228533,
    SPELL_DH_SHATTERED_SOUL_LESSER_SOUL_FRAGMENT_2 = 237867,
    SPELL_DH_SHEAR                                 = 203782,
    SPELL_DH_SIGIL_OF_CHAINS_AREA_SELECTOR         = 204834,
    SPELL_DH_SIGIL_OF_CHAINS_GRIP                  = 208674,
    SPELL_DH_SIGIL_OF_CHAINS_JUMP                  = 208674,
    SPELL_DH_SIGIL_OF_CHAINS_SLOW                  = 204843,
    SPELL_DH_SIGIL_OF_CHAINS_SNARE                 = 204843,
    SPELL_DH_SIGIL_OF_CHAINS_TARGET_SELECT         = 204834,
    SPELL_DH_SIGIL_OF_CHAINS_VISUAL                = 208673,
    SPELL_DH_SIGIL_OF_FLAME_AOE                    = 204598,
    SPELL_DH_SIGIL_OF_FLAME_FLAME_CRASH            = 228973,
    SPELL_DH_SIGIL_OF_FLAME_VISUAL                 = 208710,
    SPELL_DH_SIGIL_OF_MISERY                       = 207685,
    SPELL_DH_SIGIL_OF_MISERY_AOE                   = 207685,
    SPELL_DH_SIGIL_OF_SILENCE                      = 204490,
    SPELL_DH_SIGIL_OF_SILENCE_AOE                  = 204490,
    SPELL_DH_SOUL_BARRIER                          = 227225,
    SPELL_DH_SOUL_CLEAVE                           = 228477,
    SPELL_DH_SOUL_CLEAVE_DMG                       = 228478,
    SPELL_DH_SOUL_FRAGMENT_COUNTER                 = 203981,
    SPELL_DH_SOUL_FURNACE_DAMAGE_BUFF              = 391172,
    SPELL_DH_SOUL_RENDING                          = 204909,
    SPELL_DH_SPIRIT_BOMB_DAMAGE                    = 218677,
    SPELL_DH_SPIRIT_BOMB_HEAL                      = 227255,
    SPELL_DH_SPIRIT_BOMB_VISUAL                    = 218678,
    SPELL_DH_STUDENT_OF_SUFFERING_TALENT           = 452412,
    SPELL_DH_STUDENT_OF_SUFFERING_AURA             = 453239,
    SPELL_DH_TACTICAL_RETREAT_ENERGIZE             = 389890,
    SPELL_DH_TACTICAL_RETREAT_TALENT               = 389688,
    SPELL_DH_THROW_GLAIVE                          = 185123,
    SPELL_DH_UNCONTAINED_FEL                       = 209261,
    SPELL_DH_VENGEFUL_BONDS                        = 320635,
    SPELL_DH_VENGEFUL_RETREAT                      = 198813,
    SPELL_DH_VENGEFUL_RETREAT_TRIGGER              = 198793,
};

enum DemonHunterSpellCategories
{
    SPELL_CATEGORY_DH_EYE_BEAM      = 1582,
    SPELL_CATEGORY_DH_BLADE_DANCE   = 1640
};

// Called by 203819 - Demon Spikes
class spell_dh_calcified_spikes : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CALCIFIED_SPIKES_TALENT, SPELL_DH_CALCIFIED_SPIKES_MOD_DAMAGE });
    }

    bool Load() override
    {
        return GetUnitOwner()->HasAura(SPELL_DH_CALCIFIED_SPIKES_TALENT);
    }

    void HandleAfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DH_CALCIFIED_SPIKES_MOD_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_calcified_spikes::HandleAfterRemove, EFFECT_1, SPELL_AURA_MOD_ARMOR_PCT_FROM_STAT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 391171 - Calcified Spikes
class spell_dh_calcified_spikes_periodic : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        if (AuraEffect* damagePctTaken = GetEffect(EFFECT_0))
            damagePctTaken->ChangeAmount(damagePctTaken->GetAmount() + 1);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_calcified_spikes_periodic::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 197125 - Chaos Strike
class spell_dh_chaos_strike : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CHAOS_STRIKE_ENERGIZE });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
        args.SetTriggeringAura(aurEff);
        GetTarget()->CastSpell(GetTarget(), SPELL_DH_CHAOS_STRIKE_ENERGIZE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dh_chaos_strike::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// Called by 191427 - Metamorphosis
class spell_dh_chaotic_transformation : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CHAOTIC_TRANSFORMATION })
            && sSpellCategoryStore.LookupEntry(SPELL_CATEGORY_DH_EYE_BEAM)
            && sSpellCategoryStore.LookupEntry(SPELL_CATEGORY_DH_BLADE_DANCE);
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_DH_CHAOTIC_TRANSFORMATION);
    }

    void HandleCooldown() const
    {
        GetCaster()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr)
        {
            uint32 category = sSpellMgr->AssertSpellInfo(itr->first, DIFFICULTY_NONE)->CategoryId;
            return category == SPELL_CATEGORY_DH_EYE_BEAM || category == SPELL_CATEGORY_DH_BLADE_DANCE;
        }, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dh_chaotic_transformation::HandleCooldown);
    }
};

// 213010 - Charred Warblades
class spell_dh_charred_warblades : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CHARRED_WARBLADES_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo() && eventInfo.GetDamageInfo()->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE;
    }

    void HandleAfterProc(ProcEventInfo& eventInfo)
    {
        _healAmount += CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), GetEffect(EFFECT_0)->GetAmount());
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (_healAmount == 0)
            return;

        GetTarget()->CastSpell(GetTarget(), SPELL_DH_CHARRED_WARBLADES_HEAL,
            CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
            .SetTriggeringAura(aurEff)
            .AddSpellBP0(_healAmount));

        _healAmount = 0;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dh_charred_warblades::CheckProc);
        AfterProc += AuraProcFn(spell_dh_charred_warblades::HandleAfterProc);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_charred_warblades::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint32 _healAmount = 0;
};

// Called by 212084 - Fel Devastation and 198013 - Eye Beam
class spell_dh_collective_anguish : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_COLLECTIVE_ANGUISH, SPELL_DH_FEL_DEVASTATION, SPELL_DH_COLLECTIVE_ANGUISH_EYE_BEAM, SPELL_DH_COLLECTIVE_ANGUISH_FEL_DEVASTATION });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_DH_COLLECTIVE_ANGUISH);
    }

    void HandleEyeBeam() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DH_COLLECTIVE_ANGUISH_EYE_BEAM, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleFelDevastation() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DH_COLLECTIVE_ANGUISH_FEL_DEVASTATION, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        if (m_scriptSpellId == SPELL_DH_FEL_DEVASTATION)
            AfterCast += SpellCastFn(spell_dh_collective_anguish::HandleEyeBeam);
        else
            AfterCast += SpellCastFn(spell_dh_collective_anguish::HandleFelDevastation);
    }
};

// 391057 - Eye Beam
class spell_dh_collective_anguish_eye_beam : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_COLLECTIVE_ANGUISH_EYE_BEAM_DAMAGE });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(nullptr, SPELL_DH_COLLECTIVE_ANGUISH_EYE_BEAM_DAMAGE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_collective_anguish_eye_beam::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// Called by 188499 - Blade Dance, 162794 - Chaos Strike, 185123 - Throw Glaive and 342817 - Glaive Tempest
class spell_dh_cycle_of_hatred : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CYCLE_OF_HATRED });
    }

    bool Load() override
    {
        if (!GetCaster()->HasAura(SPELL_DH_CYCLE_OF_HATRED))
            return false;

        if (GetSpellInfo()->Id != SPELL_DH_THROW_GLAIVE)
            return true;

        // Throw Glaive triggers this talent only with Furious Throws
        return GetCaster()->HasAura(SPELL_DH_FURIOUS_THROWS);
    }

    void ReduceEyeBeamCooldown() const
    {
        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_DH_CYCLE_OF_HATRED, EFFECT_0))
            GetCaster()->GetSpellHistory()->ModifyCooldown(SPELL_DH_EYE_BEAM, Milliseconds(-aurEff->GetAmount()));
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dh_cycle_of_hatred::ReduceEyeBeamCooldown);
    }
};

// Called by 212084 - Fel Devastation
class spell_dh_darkglare_boon : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        if (!ValidateSpellInfo({ SPELL_DH_DARKGLARE_BOON_ENERGIZE, SPELL_DH_FEL_DEVASTATION })
            || !ValidateSpellEffect({ { SPELL_DH_DARKGLARE_BOON, EFFECT_3 } }))
            return false;

        SpellInfo const* darkglareBoon = sSpellMgr->GetSpellInfo(SPELL_DH_DARKGLARE_BOON, DIFFICULTY_NONE);
        return darkglareBoon->GetEffect(EFFECT_0).CalcValue() < darkglareBoon->GetEffect(EFFECT_1).CalcValue()
            && darkglareBoon->GetEffect(EFFECT_2).CalcValue() < darkglareBoon->GetEffect(EFFECT_3).CalcValue();
    }

    bool Load() override
    {
        return GetUnitOwner()->HasAura(SPELL_DH_DARKGLARE_BOON);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        // Tooltip mentions "fully channelled" being a requirement but ingame it always reduces cooldown and energizes, even when manually cancelled
        //if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
        //    return;

        Unit* target = GetTarget();
        Aura const* darkglareBoon = target->GetAura(SPELL_DH_DARKGLARE_BOON);

        SpellHistory::Duration cooldown, categoryCooldown;
        SpellHistory::GetCooldownDurations(GetSpellInfo(), 0, &cooldown, nullptr, &categoryCooldown);
        int32 reductionPct = irand(darkglareBoon->GetEffect(EFFECT_0)->GetAmount(), darkglareBoon->GetEffect(EFFECT_1)->GetAmount());
        SpellHistory::Duration cooldownReduction(CalculatePct(std::max(cooldown, categoryCooldown).count(), reductionPct));

        int32 energizeValue = irand(darkglareBoon->GetEffect(EFFECT_2)->GetAmount(), darkglareBoon->GetEffect(EFFECT_3)->GetAmount());

        target->GetSpellHistory()->ModifyCooldown(SPELL_DH_FEL_DEVASTATION, -cooldownReduction);

        target->CastSpell(target, SPELL_DH_DARKGLARE_BOON_ENERGIZE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .SpellValueOverrides = { { SPELLVALUE_BASE_POINT0, energizeValue } }
        });
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_dh_darkglare_boon::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 209426 - Darkness
class spell_dh_darkness : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        // Set absorbtion amount to unlimited
        amount = -1;
    }

    void Absorb(AuraEffect const* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount) const
    {
        if (AuraEffect const* chanceEffect = GetEffect(EFFECT_1))
            if (roll_chance_i(chanceEffect->GetAmount()))
                absorbAmount = dmgInfo.GetDamage();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dh_darkness::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dh_darkness::Absorb, EFFECT_0);
    }
};

// 196718 - Darkness
// Id: 6615
struct areatrigger_dh_darkness : AreaTriggerAI
{
    areatrigger_dh_darkness(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger),
        _absorbAuraInfo(sSpellMgr->GetSpellInfo(SPELL_DH_DARKNESS_ABSORB, DIFFICULTY_NONE)) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !caster->IsValidAssistTarget(unit, _absorbAuraInfo))
            return;

        caster->CastSpell(unit, SPELL_DH_DARKNESS_ABSORB, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .SpellValueOverrides = { { SPELLVALUE_DURATION, at->GetDuration() } }
        });
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAura(SPELL_DH_DARKNESS_ABSORB, at->GetCasterGuid());
    }

private:
    SpellInfo const* _absorbAuraInfo;
};

// 203819 - Demon Spikes
class spell_dh_deflecting_spikes : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_DH_DEFLECTING_SPIKES })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } })
            && spellInfo->GetEffect(EFFECT_0).IsAura(SPELL_AURA_MOD_PARRY_PERCENT);
    }

    void HandleParryChance(WorldObject*& target) const
    {
        if (!GetCaster()->HasAura(SPELL_DH_DEFLECTING_SPIKES))
            target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dh_deflecting_spikes::HandleParryChance, EFFECT_0, TARGET_UNIT_CASTER);
    }
};

// 203720 - Demon Spikes
class spell_dh_demon_spikes : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_DEMON_SPIKES });
    }

    void HandleArmor(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DH_DEMON_SPIKES, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_demon_spikes::HandleArmor, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 258860 - Essence Break
class spell_dh_essence_break : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_ESSENCE_BREAK_DEBUFF });
    }

    void HandleDebuff(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();

        // debuff application is slightly delayed on official servers (after animation fully finishes playing)
        caster->m_Events.AddEventAtOffset([caster, targets = CastSpellTargetArg(GetHitUnit())]() mutable
        {
            if (!targets.Targets)
                return;

            targets.Targets->Update(caster);

            caster->CastSpell(targets, SPELL_DH_ESSENCE_BREAK_DEBUFF, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }, 300ms);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_essence_break::HandleDebuff, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 198013 - Eye Beam
class spell_dh_eye_beam : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_EYE_BEAM_DAMAGE });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(nullptr, SPELL_DH_EYE_BEAM_DAMAGE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_eye_beam::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 212084 - Fel Devastation
class spell_dh_fel_devastation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FEL_DEVASTATION_HEAL });
    }

    void HandlePeriodicEffect(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_DH_FEL_DEVASTATION_HEAL, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dh_fel_devastation::HandlePeriodicEffect, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// Called by 258920 - Immolation Aura
class spell_dh_fel_flame_fortification : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FEL_FLAME_FORTIFICATION_TALENT, SPELL_DH_FEL_FLAME_FORTIFICATION_MOD_DAMAGE });
    }

    bool Load() override
    {
        return GetUnitOwner()->HasAura(SPELL_DH_FEL_FLAME_FORTIFICATION_TALENT);
    }

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DH_FEL_FLAME_FORTIFICATION_MOD_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff,
            .OriginalCastId = aurEff->GetBase()->GetCastId()
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_DH_FEL_FLAME_FORTIFICATION_MOD_DAMAGE);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dh_fel_flame_fortification::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_fel_flame_fortification::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 232893 - Felblade
class spell_dh_felblade : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FELBLADE_CHARGE });
    }

    void HandleCharge(SpellEffIndex /*effIndex*/) const
    {
        uint32 spellToCast = GetCaster()->IsWithinMeleeRange(GetHitUnit()) ? SPELL_DH_FELBLADE_DAMAGE : SPELL_DH_FELBLADE_CHARGE;
        GetCaster()->CastSpell(GetHitUnit(), spellToCast, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_felblade::HandleCharge, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 213241 - Felblade Charge
class spell_dh_felblade_charge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FELBLADE_DAMAGE });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DH_FELBLADE_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_felblade_charge::HandleDamage, EFFECT_0, SPELL_EFFECT_CHARGE);
    }
};

// 203557 - Felblade (Vengeance cooldow reset proc aura)
// 236167 - Felblade (Havoc cooldow reset proc aura)
class spell_dh_felblade_cooldown_reset_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FELBLADE });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*eventInfo*/) const
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_DH_FELBLADE, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dh_felblade_cooldown_reset_proc::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 204021 - Fiery Brand
class spell_dh_fiery_brand : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIERY_BRAND_DEBUFF_RANK_1, SPELL_DH_FIERY_BRAND_DEBUFF_RANK_2, SPELL_DH_FIERY_BRAND_RANK_2 });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), GetCaster()->HasAura(SPELL_DH_FIERY_BRAND_RANK_2) ? SPELL_DH_FIERY_BRAND_DEBUFF_RANK_2 : SPELL_DH_FIERY_BRAND_DEBUFF_RANK_1,
            CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_fiery_brand::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 206416 - First Blood
class spell_dh_first_blood : public AuraScript
{
public:
    ObjectGuid const& GetFirstTarget() const { return _firstTargetGUID; }
    void SetFirstTarget(ObjectGuid const& targetGuid) { _firstTargetGUID = targetGuid; }

private:
    void Register() override
    {
    }

private:
    ObjectGuid _firstTargetGUID;
};

// Called by 198013 - Eye Beam
class spell_dh_furious_gaze : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FURIOUS_GAZE, SPELL_DH_FURIOUS_GAZE_BUFF });
    }

    bool Load() override
    {
        return GetUnitOwner()->HasAura(SPELL_DH_FURIOUS_GAZE);
    }

    void HandleAfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DH_FURIOUS_GAZE_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_furious_gaze::HandleAfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// Called by 162264 - Metamorphosis
class spell_dh_inner_demon : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_INNER_DEMON_TALENT, SPELL_DH_INNER_DEMON_BUFF });
    }

    bool Load() override
    {
        return GetUnitOwner()->HasAura(SPELL_DH_INNER_DEMON_TALENT); // This spell has a proc, but is just a copypaste from spell 390145 (also don't have a 5s cooldown)
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DH_INNER_DEMON_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
        });
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dh_inner_demon::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 390139 - Inner Demon
// ID - 26749
struct at_dh_inner_demon : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(at->GetSpellId(), DIFFICULTY_NONE);
        if (!spellInfo)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position destPos = at->GetFirstCollisionPosition(spellInfo->GetEffect(EFFECT_0).CalcValue(caster) + at->GetMaxSearchRadius(), at->GetRelativeAngle(caster));
        PathGenerator path(at);

        path.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);

        at->InitSplines(path.GetPath());
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
            caster->CastSpell(caster->GetPosition(), SPELL_DH_INNER_DEMON_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 209258 - Last Resort
class spell_dh_last_resort : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_DH_UNCONTAINED_FEL, SPELL_DH_METAMORPHOSIS_VENGEANCE_TRANSFORM })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void HandleAbsorb(AuraEffect const* /*aurEff*/, DamageInfo const& /*dmgInfo*/, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DH_UNCONTAINED_FEL))
        {
            absorbAmount = 0;
            return;
        }

        PreventDefaultAction();

        CastSpellExtraArgs castArgs = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR | TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD;

        target->CastSpell(target, SPELL_DH_METAMORPHOSIS_VENGEANCE_TRANSFORM, castArgs);
        target->CastSpell(target, SPELL_DH_UNCONTAINED_FEL, castArgs);

        target->SetHealth(target->CountPctFromMaxHealth(GetEffectInfo(EFFECT_1).CalcValue(target)));
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbOverkillFn(spell_dh_last_resort::HandleAbsorb, EFFECT_0);
    }
};

// 188499 - Blade Dance
// 210152 - Death Sweep
class spell_dh_blade_dance : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIRST_BLOOD });
    }

    void DecideFirstTarget(std::list<WorldObject*>& targetList)
    {
        if (targetList.empty())
            return;

        Aura* aura = GetCaster()->GetAura(SPELL_DH_FIRST_BLOOD);
        if (!aura)
            return;

        ObjectGuid firstTargetGUID = ObjectGuid::Empty;
        ObjectGuid selectedTarget = GetCaster()->GetTarget();

        // Prefer the selected target if he is one of the enemies
        if (targetList.size() > 1 && !selectedTarget.IsEmpty())
        {
            auto it = std::find_if(targetList.begin(), targetList.end(), [selectedTarget](WorldObject* object)
            {
                return object->GetGUID() == selectedTarget;
            });
            if (it != targetList.end())
                firstTargetGUID = (*it)->GetGUID();
        }

        if (firstTargetGUID.IsEmpty())
            firstTargetGUID = targetList.front()->GetGUID();

        if (spell_dh_first_blood* script = aura->GetScript<spell_dh_first_blood>())
            script->SetFirstTarget(firstTargetGUID);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_blade_dance::DecideFirstTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 199552 - Blade Dance
// 200685 - Blade Dance
// 210153 - Death Sweep
// 210155 - Death Sweep
class spell_dh_blade_dance_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIRST_BLOOD });
    }

    void HandleHitTarget()
    {
        int32 damage = GetHitDamage();

        if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(SPELL_DH_FIRST_BLOOD, EFFECT_0))
            if (spell_dh_first_blood* script = aurEff->GetBase()->GetScript<spell_dh_first_blood>())
                if (GetHitUnit()->GetGUID() == script->GetFirstTarget())
                    AddPct(damage, aurEff->GetAmount());

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_dh_blade_dance_damage::HandleHitTarget);
    }
};

// 131347 - Glide
class spell_dh_glide : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_GLIDE_KNOCKBACK, SPELL_DH_GLIDE_DURATION, SPELL_DH_VENGEFUL_RETREAT_TRIGGER, SPELL_DH_FEL_RUSH });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (caster->IsMounted() || caster->GetVehicleBase())
            return SPELL_FAILED_DONT_REPORT;

        if (!caster->IsFalling())
            return SPELL_FAILED_NOT_ON_GROUND;

        return SPELL_CAST_OK;
    }

    void HandleCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_DH_GLIDE_KNOCKBACK, true);
        caster->CastSpell(caster, SPELL_DH_GLIDE_DURATION, true);

        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_DH_VENGEFUL_RETREAT_TRIGGER, GetCastDifficulty()), 0, nullptr, false, 250ms);
        caster->GetSpellHistory()->StartCooldown(sSpellMgr->AssertSpellInfo(SPELL_DH_FEL_RUSH, GetCastDifficulty()), 0, nullptr, false, 250ms);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dh_glide::CheckCast);
        BeforeCast += SpellCastFn(spell_dh_glide::HandleCast);
    }
};

// 131347 - Glide
class spell_dh_glide_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_GLIDE_DURATION });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DH_GLIDE_DURATION);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_glide_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_FEATHER_FALL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 197154 - Glide
class spell_dh_glide_timer : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_GLIDE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DH_GLIDE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_glide_timer::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Called by 162264 - Metamorphosis
class spell_dh_restless_hunter : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_RESTLESS_HUNTER_TALENT, SPELL_DH_RESTLESS_HUNTER_BUFF, SPELL_DH_FEL_RUSH })
            && sSpellCategoryStore.HasRecord(sSpellMgr->AssertSpellInfo(SPELL_DH_FEL_RUSH, DIFFICULTY_NONE)->ChargeCategoryId);
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_DH_RESTLESS_HUNTER_TALENT);
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();

        target->CastSpell(target, SPELL_DH_RESTLESS_HUNTER_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });

        target->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_DH_FEL_RUSH, GetCastDifficulty())->ChargeCategoryId);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dh_restless_hunter::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 388116 - Shattered Destiny
class spell_dh_shattered_destiny : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_DH_METAMORPHOSIS_TRANSFORM })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && spellInfo->GetEffect(EFFECT_0).IsAura()
            && spellInfo->GetEffect(EFFECT_1).IsAura();
    }

    bool CheckFurySpent(ProcEventInfo const& eventInfo)
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        if (!procSpell)
            return false;

        if (!eventInfo.GetActor()->HasAura(SPELL_DH_METAMORPHOSIS_TRANSFORM))
            return false;

        _furySpent += procSpell->GetPowerTypeCostAmount(POWER_FURY).value_or(0);
        return _furySpent >= GetEffect(EFFECT_1)->GetAmount();
    }

    void HandleProc(ProcEventInfo const& /*eventInfo*/)
    {
        Aura* metamorphosis = GetTarget()->GetAura(SPELL_DH_METAMORPHOSIS_TRANSFORM);
        if (!metamorphosis)
            return;

        int32 requiredFuryAmount = GetEffect(EFFECT_1)->GetAmount();
        metamorphosis->SetDuration(metamorphosis->GetDuration() + _furySpent / requiredFuryAmount * GetEffect(EFFECT_0)->GetAmount());
        _furySpent %= requiredFuryAmount;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dh_shattered_destiny::CheckFurySpent);
        OnProc += AuraProcFn(spell_dh_shattered_destiny::HandleProc);
    }

private:
    int32 _furySpent = 0;
};

// 391166 - Soul Furnace
class spell_dh_soul_furnace : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_SOUL_FURNACE_DAMAGE_BUFF });
    }

    void CalculateSpellMod(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == GetAura()->CalcMaxStackAmount())
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_DH_SOUL_FURNACE_DAMAGE_BUFF, true);
            Remove();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dh_soul_furnace::CalculateSpellMod, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 339424 - Soul Furnace
class spell_dh_soul_furnace_conduit : public AuraScript
{
    void CalculateSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
    {
        if (aurEff->GetAmount() == 10)
        {
            if (!spellMod)
            {
                spellMod = new SpellModifierByClassMask(GetAura());
                spellMod->op = SpellModOp::HealingAndDamage;
                spellMod->type = SPELLMOD_PCT;
                spellMod->spellId = GetId();
                static_cast<SpellModifierByClassMask*>(spellMod)->mask = flag128(0x80000000);
                static_cast<SpellModifierByClassMask*>(spellMod)->value = GetEffect(EFFECT_1)->GetAmount() + 1;
            }
        }
    }

    void Register() override
    {
        DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_dh_soul_furnace_conduit::CalculateSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 202138 - Sigil of Chains
// 204596 - Sigil of Flame
// 207684 - Sigil of Misery
// 202137 - Sigil of Silence
template<uint32 TriggerSpellId, uint32 TriggerSpellId2 = 0>
struct areatrigger_dh_generic_sigil : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->CastSpell(at->GetPosition(), TriggerSpellId);
            if constexpr (TriggerSpellId2 != 0)
                caster->CastSpell(at->GetPosition(), TriggerSpellId2);
        }
    }
};

// 208673 - Sigil of Chains
class spell_dh_sigil_of_chains : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_SIGIL_OF_CHAINS_SLOW, SPELL_DH_SIGIL_OF_CHAINS_GRIP });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation const* loc = GetExplTargetDest())
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DH_SIGIL_OF_CHAINS_SLOW, true);
            GetHitUnit()->CastSpell(loc->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_GRIP, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_sigil_of_chains::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Called by 204598 - Sigil of Flame
class spell_dh_student_of_suffering : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_STUDENT_OF_SUFFERING_TALENT, SPELL_DH_STUDENT_OF_SUFFERING_AURA });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_DH_STUDENT_OF_SUFFERING_TALENT);
    }

    void HandleStudentOfSuffering() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DH_STUDENT_OF_SUFFERING_AURA, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dh_student_of_suffering::HandleStudentOfSuffering);
    }
};

// Called by 198793 - Vengeful Retreat
class spell_dh_tactical_retreat : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_TACTICAL_RETREAT_TALENT, SPELL_DH_TACTICAL_RETREAT_ENERGIZE });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_DH_TACTICAL_RETREAT_TALENT);
    }

    void Energize() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_DH_TACTICAL_RETREAT_ENERGIZE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_dh_tactical_retreat::Energize);
    }
};

// 198813 - Vengeful Retreat
class spell_dh_vengeful_retreat_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_VENGEFUL_BONDS });
    }

    void HandleVengefulBonds(std::list<WorldObject*>& targets)
    {
        if (!GetCaster()->HasAura(SPELL_DH_VENGEFUL_BONDS))
            targets.clear();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_vengeful_retreat_damage::HandleVengefulBonds, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_demon_hunter_spell_scripts()
{
    RegisterSpellScript(spell_dh_calcified_spikes);
    RegisterSpellScript(spell_dh_calcified_spikes_periodic);
    RegisterSpellScript(spell_dh_chaos_strike);
    RegisterSpellScript(spell_dh_chaotic_transformation);
    RegisterSpellScript(spell_dh_charred_warblades);
    RegisterSpellScript(spell_dh_collective_anguish);
    RegisterSpellScript(spell_dh_collective_anguish_eye_beam);
    RegisterSpellScript(spell_dh_cycle_of_hatred);
    RegisterSpellScript(spell_dh_darkglare_boon);
    RegisterSpellScript(spell_dh_darkness);
    RegisterSpellScript(spell_dh_deflecting_spikes);
    RegisterSpellScript(spell_dh_demon_spikes);
    RegisterSpellScript(spell_dh_essence_break);
    RegisterSpellScript(spell_dh_eye_beam);
    RegisterSpellScript(spell_dh_fel_devastation);
    RegisterSpellScript(spell_dh_fel_flame_fortification);
    RegisterSpellScript(spell_dh_felblade);
    RegisterSpellScript(spell_dh_felblade_charge);
    RegisterSpellScript(spell_dh_felblade_cooldown_reset_proc);
    RegisterSpellScript(spell_dh_fiery_brand);
    RegisterSpellScript(spell_dh_furious_gaze);
    RegisterSpellScript(spell_dh_inner_demon);
    RegisterAreaTriggerAI(at_dh_inner_demon);
    RegisterSpellScript(spell_dh_last_resort);
    RegisterSpellScript(spell_dh_restless_hunter);
    RegisterSpellScript(spell_dh_shattered_destiny);
    RegisterSpellScript(spell_dh_sigil_of_chains);
    RegisterSpellScript(spell_dh_student_of_suffering);
    RegisterSpellScript(spell_dh_tactical_retreat);
    RegisterSpellScript(spell_dh_vengeful_retreat_damage);

    RegisterAreaTriggerAI(areatrigger_dh_darkness);
    new GenericAreaTriggerEntityScript<areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_CHAINS_TARGET_SELECT, SPELL_DH_SIGIL_OF_CHAINS_VISUAL>>("areatrigger_dh_sigil_of_chains");
    new GenericAreaTriggerEntityScript<areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_FLAME_AOE, SPELL_DH_SIGIL_OF_FLAME_VISUAL>>("areatrigger_dh_sigil_of_flame");
    new GenericAreaTriggerEntityScript<areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_SILENCE_AOE>>("areatrigger_dh_sigil_of_silence");
    new GenericAreaTriggerEntityScript<areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_MISERY_AOE>>("areatrigger_dh_sigil_of_misery");

    // Havoc

    /* Spells & Auras */

    /* Auras */

    RegisterSpellScript(spell_dh_first_blood);

    /* AreaTrigger */

    /* Spells */

    RegisterSpellScript(spell_dh_blade_dance);
    RegisterSpellScript(spell_dh_blade_dance_damage);

    // Vengeance
    RegisterSpellScript(spell_dh_soul_furnace);

    // Vengeance & Havoc

    RegisterSpellAndAuraScriptPair(spell_dh_glide, spell_dh_glide_AuraScript);
    RegisterSpellScript(spell_dh_glide_timer);

    // Soulbind conduits
    RegisterSpellScript(spell_dh_soul_furnace_conduit);
}
