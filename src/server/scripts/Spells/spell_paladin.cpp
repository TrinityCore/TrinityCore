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
 * Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pal_".
 */

#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CommonPredicates.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum PaladinSpells
{
    SPELL_PALADIN_ARDENT_DEFENDER_HEAL           = 66235,
    SPELL_PALADIN_ART_OF_WAR_TRIGGERED           = 231843,
    SPELL_PALADIN_AVENGERS_SHIELD                = 31935,
    SPELL_PALADIN_AVENGING_WRATH                 = 31884,
    SPELL_PALADIN_BEACON_OF_LIGHT                = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL           = 53652,
    SPELL_PALADIN_BLADE_OF_JUSTICE               = 184575,
    SPELL_PALADIN_BLINDING_LIGHT_EFFECT          = 105421,
    SPELL_PALADIN_CONCENTRACTION_AURA            = 19746,
    SPELL_PALADIN_CONSECRATED_GROUND_PASSIVE     = 204054,
    SPELL_PALADIN_CONSECRATED_GROUND_SLOW        = 204242,
    SPELL_PALADIN_CONSECRATION                   = 26573,
    SPELL_PALADIN_CONSECRATION_DAMAGE            = 81297,
    SPELL_PALADIN_CONSECRATION_PROTECTION_AURA   = 188370,
    SPELL_PALADIN_CRUSADING_STRIKES_ENERGIZE     = 406834,
    SPELL_PALADIN_DIVINE_PURPOSE_TRIGGERED       = 223819,
    SPELL_PALADIN_DIVINE_STEED_HUMAN             = 221883,
    SPELL_PALADIN_DIVINE_STEED_DWARF             = 276111,
    SPELL_PALADIN_DIVINE_STEED_DRAENEI           = 221887,
    SPELL_PALADIN_DIVINE_STEED_DARK_IRON_DWARF   = 276112,
    SPELL_PALADIN_DIVINE_STEED_BLOODELF          = 221886,
    SPELL_PALADIN_DIVINE_STEED_TAUREN            = 221885,
    SPELL_PALADIN_DIVINE_STEED_ZANDALARI_TROLL   = 294133,
    SPELL_PALADIN_DIVINE_STEED_LF_DRAENEI        = 363608,
    SPELL_PALADIN_DIVINE_STORM_DAMAGE            = 224239,
    SPELL_PALADIN_ENDURING_LIGHT                 = 40471,
    SPELL_PALADIN_ENDURING_JUDGEMENT             = 40472,
    SPELL_PALADIN_EYE_FOR_AN_EYE_TRIGGERED       = 205202,
    SPELL_PALADIN_FINAL_STAND                    = 204077,
    SPELL_PALADIN_FINAL_STAND_EFFECT             = 204079,
    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS      = 86659,
    SPELL_PALADIN_HAMMER_OF_JUSTICE              = 853,
    SPELL_PALADIN_HAMMER_OF_THE_RIGHTEOUS_AOE    = 88263,
    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_HOLY_MENDING                   = 64891,
    SPELL_PALADIN_HOLY_POWER_ARMOR               = 28790,
    SPELL_PALADIN_HOLY_POWER_ATTACK_POWER        = 28791,
    SPELL_PALADIN_HOLY_POWER_SPELL_POWER         = 28793,
    SPELL_PALADIN_HOLY_POWER_MP5                 = 28795,
    SPELL_PALADIN_HOLY_PRISM_AREA_BEAM_VISUAL    = 121551,
    SPELL_PALADIN_HOLY_PRISM_TARGET_ALLY         = 114871,
    SPELL_PALADIN_HOLY_PRISM_TARGET_ENEMY        = 114852,
    SPELL_PALADIN_HOLY_PRISM_TARGET_BEAM_VISUAL  = 114862,
    SPELL_PALADIN_HOLY_SHOCK                     = 20473,
    SPELL_PALADIN_HOLY_SHOCK_DAMAGE              = 25912,
    SPELL_PALADIN_HOLY_SHOCK_HEALING             = 25914,
    SPELL_PALADIN_HOLY_LIGHT                     = 82326,
    SPELL_PALADIN_INFUSION_OF_LIGHT_ENERGIZE     = 356717,
    SPELL_PALADIN_IMMUNE_SHIELD_MARKER           = 61988,
    SPELL_PALADIN_ITEM_HEALING_TRANCE            = 37706,
    SPELL_PALADIN_JUDGMENT_GAIN_HOLY_POWER       = 220637,
    SPELL_PALADIN_JUDGMENT_HOLY_R3               = 231644,
    SPELL_PALADIN_JUDGMENT_HOLY_R3_DEBUFF        = 214222,
    SPELL_PALADIN_JUDGMENT_PROT_RET_R3           = 315867,
    SPELL_PALADIN_LIGHT_HAMMER_COSMETIC          = 122257,
    SPELL_PALADIN_LIGHT_HAMMER_DAMAGE            = 114919,
    SPELL_PALADIN_LIGHT_HAMMER_HEALING           = 119952,
    SPELL_PALADIN_LIGHT_HAMMER_PERIODIC          = 114918,
    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT        = 31790,
    SPELL_PALADIN_RIGHTEOUS_VERDICT_AURA         = 267611,
    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS          = 25742,
    SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_ARMOR  = 132403,
    SPELL_PALADIN_SHIELD_OF_VENGEANCE_DAMAGE     = 184689,
    SPELL_PALADIN_TEMPLAR_VERDICT_DAMAGE         = 224266,
    SPELL_PALADIN_T30_2P_HEARTFIRE_DAMAGE        = 408399,
    SPELL_PALADIN_T30_2P_HEARTFIRE_HEAL          = 408400,
    SPELL_PALADIN_ZEAL_AURA                      = 269571
};

enum PaladinCovenantSpells
{
    SPELL_PALADIN_ASHEN_HALLOW                   = 316958,
    SPELL_PALADIN_ASHEN_HALLOW_DAMAGE            = 317221,
    SPELL_PALADIN_ASHEN_HALLOW_HEAL              = 317223,
    SPELL_PALADIN_ASHEN_HALLOW_ALLOW_HAMMER      = 330382
};

enum PaladinSpellVisualKit
{
    PALADIN_VISUAL_KIT_DIVINE_STORM              = 73892
};

enum PaladinSpellVisual
{
    PALADIN_VISUAL_SPELL_HOLY_SHOCK_DAMAGE       = 83731,
    PALADIN_VISUAL_SPELL_HOLY_SHOCK_DAMAGE_CRIT  = 83881,
    PALADIN_VISUAL_SPELL_HOLY_SHOCK_HEAL         = 83732,
    PALADIN_VISUAL_SPELL_HOLY_SHOCK_HEAL_CRIT    = 83880
};

enum PaladinSpellLabel
{
    SPELL_LABEL_PALADIN_T30_2P_HEARTFIRE         = 2598
};

// 31850 - Ardent Defender
class spell_pal_ardent_defender : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ARDENT_DEFENDER_HEAL })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void HandleAbsorb(AuraEffect const* aurEff, DamageInfo const& dmgInfo, uint32& absorbAmount)
    {
        PreventDefaultAction();

        int32 targetHealthPercent = GetEffectInfo(EFFECT_1).CalcValue(GetTarget());
        uint64 targetHealth = int32(GetTarget()->CountPctFromMaxHealth(targetHealthPercent));
        if (GetTarget()->HealthBelowPct(targetHealthPercent))
        {
            // we are currently below desired health
            // absorb everything and heal up
            GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ARDENT_DEFENDER_HEAL,
                CastSpellExtraArgs(aurEff)
                .AddSpellMod(SPELLVALUE_BASE_POINT0, int32(targetHealth - GetTarget()->GetHealth())));
        }
        else
        {
            // we are currently above desired health
            // just absorb enough to reach that percentage
            absorbAmount = dmgInfo.GetDamage() - int32(GetTarget()->GetHealth() - targetHealth);
        }

        Remove();
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbOverkillFn(spell_pal_ardent_defender::HandleAbsorb, EFFECT_2);
    }
};

// 267344 - Art of War
class spell_pal_art_of_war : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ART_OF_WAR_TRIGGERED, SPELL_PALADIN_BLADE_OF_JUSTICE });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_BLADE_OF_JUSTICE, true);
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ART_OF_WAR_TRIGGERED, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_art_of_war::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_art_of_war::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 19042 - Ashen Hallow
struct areatrigger_pal_ashen_hallow : AreaTriggerAI
{
    areatrigger_pal_ashen_hallow(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void RefreshPeriod()
    {
        if (Unit* caster = at->GetCaster())
        {
            if (AuraEffect const* ashen = caster->GetAuraEffect(SPELL_PALADIN_ASHEN_HALLOW, EFFECT_1))
                _period = Milliseconds(ashen->GetPeriod());
        }
    }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        RefreshPeriod();
        _refreshTimer = _period;
    }

    void OnUpdate(uint32 diff) override
    {
        _refreshTimer -= Milliseconds(diff);

        while (_refreshTimer <= 0s)
        {
            if (Unit* caster = at->GetCaster())
            {
                caster->CastSpell(at->GetPosition(), SPELL_PALADIN_ASHEN_HALLOW_HEAL);
                caster->CastSpell(at->GetPosition(), SPELL_PALADIN_ASHEN_HALLOW_DAMAGE);
            }

            RefreshPeriod();

            _refreshTimer += _period;
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetGUID() == at->GetCasterGuid())
            unit->CastSpell(unit, SPELL_PALADIN_ASHEN_HALLOW_ALLOW_HAMMER, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->GetGUID() == at->GetCasterGuid())
            unit->RemoveAura(SPELL_PALADIN_ASHEN_HALLOW_ALLOW_HAMMER);
    }

private:
    Milliseconds _refreshTimer;
    Milliseconds _period;
};

// 248033 - Awakening
class spell_pal_awakening : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_AVENGING_WRATH })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        Milliseconds extraDuration = 0ms;
        if (AuraEffect const* durationEffect = GetEffect(EFFECT_1))
            extraDuration = Seconds(durationEffect->GetAmount());

        if (Aura* avengingWrath = GetTarget()->GetAura(SPELL_PALADIN_AVENGING_WRATH))
        {
            avengingWrath->SetDuration(avengingWrath->GetDuration() + extraDuration.count());
            avengingWrath->SetMaxDuration(avengingWrath->GetMaxDuration() + extraDuration.count());
        }
        else
            GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_AVENGING_WRATH,
                CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD)
                    .SetTriggeringSpell(eventInfo.GetProcSpell())
                    .AddSpellMod(SPELLVALUE_DURATION, extraDuration.count()));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_awakening::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_awakening::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 1022 - Blessing of Protection
// 204018 - Blessing of Spellwarding
class spell_pal_blessing_of_protection : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_FORBEARANCE,
            // uncomment when we have serverside only spells
            //SPELL_PALADIN_IMMUNE_SHIELD_MARKER
        }) && spellInfo->ExcludeTargetAuraSpell == SPELL_PALADIN_IMMUNE_SHIELD_MARKER;
    }

    SpellCastResult CheckForbearance()
    {
        Unit* target = GetExplTargetUnit();
        if (!target || target->HasAura(SPELL_PALADIN_FORBEARANCE))
            return SPELL_FAILED_TARGET_AURASTATE;

        return SPELL_CAST_OK;
    }

    void TriggerForbearance()
    {
        if (Unit* target = GetHitUnit())
        {
            GetCaster()->CastSpell(target, SPELL_PALADIN_FORBEARANCE, true);
            GetCaster()->CastSpell(target, SPELL_PALADIN_IMMUNE_SHIELD_MARKER, true);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_blessing_of_protection::CheckForbearance);
        AfterHit += SpellHitFn(spell_pal_blessing_of_protection::TriggerForbearance);
    }
};

// 115750 - Blinding Light
class spell_pal_blinding_light : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_BLINDING_LIGHT_EFFECT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_PALADIN_BLINDING_LIGHT_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_blinding_light::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 26573 - Consecration
class spell_pal_consecration : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_CONSECRATION_DAMAGE,
            // validate for areatrigger_pal_consecration
            SPELL_PALADIN_CONSECRATION_PROTECTION_AURA,
            SPELL_PALADIN_CONSECRATED_GROUND_PASSIVE,
            SPELL_PALADIN_CONSECRATED_GROUND_SLOW
        });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (AreaTrigger* at = GetTarget()->GetAreaTrigger(SPELL_PALADIN_CONSECRATION))
            GetTarget()->CastSpell(at->GetPosition(), SPELL_PALADIN_CONSECRATION_DAMAGE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_consecration::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 26573 - Consecration
//  9228 - AreaTriggerId
struct areatrigger_pal_consecration : AreaTriggerAI
{
    areatrigger_pal_consecration(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            // 243597 is also being cast as protection, but CreateObject is not sent, either serverside areatrigger for this aura or unused - also no visual is seen
            if (unit == caster && caster->IsPlayer() && caster->ToPlayer()->GetPrimarySpecialization() == ChrSpecialization::PaladinProtection)
                caster->CastSpell(caster, SPELL_PALADIN_CONSECRATION_PROTECTION_AURA);

            if (caster->IsValidAttackTarget(unit))
                if (caster->HasAura(SPELL_PALADIN_CONSECRATED_GROUND_PASSIVE))
                    caster->CastSpell(unit, SPELL_PALADIN_CONSECRATED_GROUND_SLOW);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (at->GetCasterGuid() == unit->GetGUID())
            unit->RemoveAurasDueToSpell(SPELL_PALADIN_CONSECRATION_PROTECTION_AURA, at->GetCasterGuid());

        unit->RemoveAurasDueToSpell(SPELL_PALADIN_CONSECRATED_GROUND_SLOW, at->GetCasterGuid());
    }
};

// 196926 - Crusader Might
class spell_pal_crusader_might : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_HOLY_SHOCK });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HOLY_SHOCK, Seconds(aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_crusader_might::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 406833 - Crusading Strikes
class spell_pal_crusading_strikes : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_CRUSADING_STRIKES_ENERGIZE });
    }

    void HandleEffectProc(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == 2)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_CRUSADING_STRIKES_ENERGIZE, aurEff);

            // this spell has weird proc order dependency set up in db2 data so we do removal manually
            Remove();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_pal_crusading_strikes::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 223817 - Divine Purpose
class spell_pal_divine_purpose : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_PURPOSE_TRIGGERED });
    }

    bool CheckProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Spell const* procSpell = eventInfo.GetProcSpell();
        if (!procSpell)
            return false;

        if (!procSpell->HasPowerTypeCost(POWER_HOLY_POWER))
            return false;

        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_PALADIN_DIVINE_PURPOSE_TRIGGERED,
            CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetTriggeringSpell(eventInfo.GetProcSpell()));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_divine_purpose::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_divine_purpose::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 642 - Divine Shield
class spell_pal_divine_shield : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_FINAL_STAND,
            SPELL_PALADIN_FINAL_STAND_EFFECT,
            SPELL_PALADIN_FORBEARANCE,
            // uncomment when we have serverside only spells
            //SPELL_PALADIN_IMMUNE_SHIELD_MARKER
        }) && spellInfo->ExcludeCasterAuraSpell == SPELL_PALADIN_IMMUNE_SHIELD_MARKER;
    }

    SpellCastResult CheckForbearance()
    {
        if (GetCaster()->HasAura(SPELL_PALADIN_FORBEARANCE))
            return SPELL_FAILED_TARGET_AURASTATE;

        return SPELL_CAST_OK;
    }

    void HandleFinalStand()
    {
        if (GetCaster()->HasAura(SPELL_PALADIN_FINAL_STAND))
            GetCaster()->CastSpell(nullptr, SPELL_PALADIN_FINAL_STAND_EFFECT, true);
    }

    void TriggerForbearance()
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_PALADIN_FORBEARANCE, true);
        caster->CastSpell(caster, SPELL_PALADIN_IMMUNE_SHIELD_MARKER, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_divine_shield::CheckForbearance);
        AfterCast += SpellCastFn(spell_pal_divine_shield::HandleFinalStand);
        AfterCast += SpellCastFn(spell_pal_divine_shield::TriggerForbearance);
    }
};

// 190784 - Divine Steed
class spell_pal_divine_steed : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_DIVINE_STEED_HUMAN,
            SPELL_PALADIN_DIVINE_STEED_DWARF,
            SPELL_PALADIN_DIVINE_STEED_DRAENEI,
            SPELL_PALADIN_DIVINE_STEED_DARK_IRON_DWARF,
            SPELL_PALADIN_DIVINE_STEED_BLOODELF,
            SPELL_PALADIN_DIVINE_STEED_TAUREN,
            SPELL_PALADIN_DIVINE_STEED_ZANDALARI_TROLL,
            SPELL_PALADIN_DIVINE_STEED_LF_DRAENEI
        });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();

        uint32 spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
        switch (caster->GetRace())
        {
            case RACE_HUMAN:
                spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                break;
            case RACE_DWARF:
                spellId = SPELL_PALADIN_DIVINE_STEED_DWARF;
                break;
            case RACE_DRAENEI:
                spellId = SPELL_PALADIN_DIVINE_STEED_DRAENEI;
                break;
            case RACE_LIGHTFORGED_DRAENEI:
                spellId = SPELL_PALADIN_DIVINE_STEED_LF_DRAENEI;
                break;
            case RACE_DARK_IRON_DWARF:
                spellId = SPELL_PALADIN_DIVINE_STEED_DARK_IRON_DWARF;
                break;
            case RACE_BLOODELF:
                spellId = SPELL_PALADIN_DIVINE_STEED_BLOODELF;
                break;
            case RACE_TAUREN:
                spellId = SPELL_PALADIN_DIVINE_STEED_TAUREN;
                break;
            case RACE_ZANDALARI_TROLL:
                spellId = SPELL_PALADIN_DIVINE_STEED_ZANDALARI_TROLL;
                break;
            default:
                break;
        }

        caster->CastSpell(caster, spellId, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_pal_divine_steed::HandleOnCast);
    }
};

// 53385 - Divine Storm
class spell_pal_divine_storm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return sSpellVisualKitStore.HasRecord(PALADIN_VISUAL_KIT_DIVINE_STORM);
    }

    void HandleOnCast()
    {
        GetCaster()->SendPlaySpellVisualKit(PALADIN_VISUAL_KIT_DIVINE_STORM, 0, 0);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_pal_divine_storm::HandleOnCast);
    }
};

// 205191 - Eye for an Eye
class spell_pal_eye_for_an_eye : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_EYE_FOR_AN_EYE_TRIGGERED });
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_PALADIN_EYE_FOR_AN_EYE_TRIGGERED, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 234299 - Fist of Justice
class spell_pal_fist_of_justice : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_HAMMER_OF_JUSTICE });
    }

    bool CheckEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (Spell const* procSpell = eventInfo.GetProcSpell())
            return procSpell->HasPowerTypeCost(POWER_HOLY_POWER);

        return false;
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*procInfo*/)
    {
        int32 value = aurEff->GetAmount() / 10;

        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, Seconds(-value));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_fist_of_justice::CheckEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_fist_of_justice::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -85043 - Grand Crusader
class spell_pal_grand_crusader : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_AVENGERS_SHIELD });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return GetTarget()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_grand_crusader::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_grand_crusader::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 54968 - Glyph of Holy Light
class spell_pal_glyph_of_holy_light : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 const maxTargets = GetSpellInfo()->MaxAffectedTargets;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::Predicates::HealthPctOrderPred());
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_glyph_of_holy_light::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 53595 - Hammer of the Righteous
struct spell_pal_hammer_of_the_righteous : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_CONSECRATION_PROTECTION_AURA,
            SPELL_PALADIN_HAMMER_OF_THE_RIGHTEOUS_AOE
        });
    }

    void HandleAoEHit(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->HasAura(SPELL_PALADIN_CONSECRATION_PROTECTION_AURA))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PALADIN_HAMMER_OF_THE_RIGHTEOUS_AOE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_hammer_of_the_righteous::HandleAoEHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 6940 - Hand of Sacrifice
class spell_pal_hand_of_sacrifice : public AuraScript
{
public:
    spell_pal_hand_of_sacrifice()
    {
        remainingAmount = 0;
    }

private:
    int32 remainingAmount;

    bool Load() override
    {
        if (Unit* caster = GetCaster())
        {
            remainingAmount = caster->GetMaxHealth();
            return true;
        }
        return false;
    }

    void Split(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & splitAmount)
    {
        remainingAmount -= splitAmount;

        if (remainingAmount <= 0)
        {
            GetTarget()->RemoveAura(SPELL_PALADIN_HAND_OF_SACRIFICE);
        }
    }

    void Register() override
    {
        OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice::Split, EFFECT_0);
    }
};

// 54149 - Infusion of Light
class spell_pal_infusion_of_light : public AuraScript
{
    static constexpr flag128 HolyLightSpellClassMask = { 0, 0, 0x400 };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_INFUSION_OF_LIGHT_ENERGIZE });
    }

    bool CheckFlashOfLightProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcSpell() && eventInfo.GetProcSpell()->m_appliedMods.find(GetAura()) != eventInfo.GetProcSpell()->m_appliedMods.end();
    }

    bool CheckHolyLightProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->IsAffected(SPELLFAMILY_PALADIN, HolyLightSpellClassMask);
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_PALADIN_INFUSION_OF_LIGHT_ENERGIZE,
            CastSpellExtraArgs(TRIGGERED_FULL_MASK).SetTriggeringSpell(eventInfo.GetProcSpell()));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_infusion_of_light::CheckFlashOfLightProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_infusion_of_light::CheckFlashOfLightProc, EFFECT_2, SPELL_AURA_ADD_FLAT_MODIFIER);

        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_infusion_of_light::CheckHolyLightProc, EFFECT_1, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_infusion_of_light::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 327193 - Moment of Glory
class spell_pal_moment_of_glory : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_AVENGERS_SHIELD });
    }

    void HandleOnHit()
    {
        GetCaster()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_pal_moment_of_glory::HandleOnHit);
    }
};

// 20271/275779/275773 - Judgement (Retribution/Protection/Holy)
class spell_pal_judgment : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_JUDGMENT_PROT_RET_R3,
            SPELL_PALADIN_JUDGMENT_GAIN_HOLY_POWER,
            SPELL_PALADIN_JUDGMENT_HOLY_R3,
            SPELL_PALADIN_JUDGMENT_HOLY_R3_DEBUFF
        });
    }

    void HandleOnHit()
    {
        Unit* caster = GetCaster();

        if (caster->HasSpell(SPELL_PALADIN_JUDGMENT_PROT_RET_R3))
            caster->CastSpell(caster, SPELL_PALADIN_JUDGMENT_GAIN_HOLY_POWER, GetSpell());

        if (caster->HasSpell(SPELL_PALADIN_JUDGMENT_HOLY_R3))
            caster->CastSpell(GetHitUnit(), SPELL_PALADIN_JUDGMENT_HOLY_R3_DEBUFF, GetSpell());
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_pal_judgment::HandleOnHit);
    }
};

// 114165 - Holy Prism
class spell_pal_holy_prism : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_PALADIN_HOLY_PRISM_TARGET_ALLY, SPELL_PALADIN_HOLY_PRISM_TARGET_ENEMY, SPELL_PALADIN_HOLY_PRISM_TARGET_BEAM_VISUAL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->IsFriendlyTo(GetHitUnit()))
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PALADIN_HOLY_PRISM_TARGET_ALLY, true);
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PALADIN_HOLY_PRISM_TARGET_ENEMY , true);

        GetCaster()->CastSpell(GetHitUnit(), SPELL_PALADIN_HOLY_PRISM_TARGET_BEAM_VISUAL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_prism::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 114852 - Holy Prism (Damage)
// 114871 - Holy Prism (Heal)
class spell_pal_holy_prism_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_PALADIN_HOLY_PRISM_TARGET_ALLY, SPELL_PALADIN_HOLY_PRISM_AREA_BEAM_VISUAL });
    }

    void SaveTargetGuid(SpellEffIndex /*effIndex*/)
    {
        _targetGUID = GetHitUnit()->GetGUID();
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint8 const maxTargets = 5;

        if (targets.size() > maxTargets)
        {
            if (GetSpellInfo()->Id == SPELL_PALADIN_HOLY_PRISM_TARGET_ALLY)
            {
                targets.sort(Trinity::Predicates::HealthPctOrderPred());
                targets.resize(maxTargets);
            }
            else
                Trinity::Containers::RandomResize(targets, maxTargets);
        }

        _sharedTargets = targets;
    }

    void ShareTargets(std::list<WorldObject*>& targets)
    {
        targets = _sharedTargets;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* initialTarget = ObjectAccessor::GetUnit(*GetCaster(), _targetGUID))
            initialTarget->CastSpell(GetHitUnit(), SPELL_PALADIN_HOLY_PRISM_AREA_BEAM_VISUAL, true);
    }

    void Register() override
    {
        if (m_scriptSpellId == SPELL_PALADIN_HOLY_PRISM_TARGET_ENEMY)
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_holy_prism_selector::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
        else if (m_scriptSpellId == SPELL_PALADIN_HOLY_PRISM_TARGET_ALLY)
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_holy_prism_selector::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);

        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_holy_prism_selector::ShareTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ENTRY);

        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_prism_selector::SaveTargetGuid, EFFECT_0, SPELL_EFFECT_ANY);
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_prism_selector::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }

private:
    std::list<WorldObject*> _sharedTargets;
    ObjectGuid _targetGUID;
};

// 20473 - Holy Shock
class spell_pal_holy_shock : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_HOLY_SHOCK,
            SPELL_PALADIN_HOLY_SHOCK_HEALING,
            SPELL_PALADIN_HOLY_SHOCK_DAMAGE
        });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();

        if (Unit* target = GetExplTargetUnit())
        {
            if (!caster->IsFriendlyTo(target))
            {
                if (!caster->IsValidAttackTarget(target))
                    return SPELL_FAILED_BAD_TARGETS;

                if (!caster->isInFront(target))
                    return SPELL_FAILED_UNIT_NOT_INFRONT;
            }
        }
        else
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (Unit* unitTarget = GetHitUnit())
        {
            if (caster->IsFriendlyTo(unitTarget))
                caster->CastSpell(unitTarget, SPELL_PALADIN_HOLY_SHOCK_HEALING, GetSpell());
            else
                caster->CastSpell(unitTarget, SPELL_PALADIN_HOLY_SHOCK_DAMAGE, GetSpell());
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 25912 - Holy Shock
class spell_pal_holy_shock_damage_visual : public SpellScript
{
    bool Validate(SpellInfo const*) override
    {
        return sSpellVisualStore.HasRecord(PALADIN_VISUAL_SPELL_HOLY_SHOCK_DAMAGE)
            && sSpellVisualStore.HasRecord(PALADIN_VISUAL_SPELL_HOLY_SHOCK_DAMAGE_CRIT);
    }

    void PlayVisual()
    {
        GetCaster()->SendPlaySpellVisual(GetHitUnit(), IsHitCrit() ? PALADIN_VISUAL_SPELL_HOLY_SHOCK_DAMAGE_CRIT : PALADIN_VISUAL_SPELL_HOLY_SHOCK_DAMAGE, 0, 0, 0.0f, false);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_pal_holy_shock_damage_visual::PlayVisual);
    }
};

// 25914 - Holy Shock
class spell_pal_holy_shock_heal_visual : public SpellScript
{
    bool Validate(SpellInfo const*) override
    {
        return sSpellVisualStore.HasRecord(PALADIN_VISUAL_SPELL_HOLY_SHOCK_HEAL)
            && sSpellVisualStore.HasRecord(PALADIN_VISUAL_SPELL_HOLY_SHOCK_HEAL_CRIT);
    }

    void PlayVisual()
    {
        GetCaster()->SendPlaySpellVisual(GetHitUnit(), IsHitCrit() ? PALADIN_VISUAL_SPELL_HOLY_SHOCK_HEAL_CRIT : PALADIN_VISUAL_SPELL_HOLY_SHOCK_HEAL, 0, 0, 0.0f, false);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_pal_holy_shock_heal_visual::PlayVisual);
    }
};

// 37705 - Healing Discount
class spell_pal_item_healing_discount : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ITEM_HEALING_TRANCE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ITEM_HEALING_TRANCE, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_item_healing_discount::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 40470 - Paladin Tier 6 Trinket
class spell_pal_item_t6_trinket : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_ENDURING_LIGHT,
            SPELL_PALADIN_ENDURING_JUDGEMENT
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

        // Holy Light & Flash of Light
        if (spellInfo->SpellFamilyFlags[0] & 0xC0000000)
        {
            spellId = SPELL_PALADIN_ENDURING_LIGHT;
            chance = 15;
        }
        // Judgements
        else if (spellInfo->SpellFamilyFlags[0] & 0x00800000)
        {
            spellId = SPELL_PALADIN_ENDURING_JUDGEMENT;
            chance = 50;
        }
        else
            return;

        if (roll_chance_i(chance))
            eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_item_t6_trinket::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 633 - Lay on Hands
class spell_pal_lay_on_hands : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_FORBEARANCE,
            // uncomment when we have serverside only spells
            //SPELL_PALADIN_IMMUNE_SHIELD_MARKER
        }) && spellInfo->ExcludeTargetAuraSpell == SPELL_PALADIN_IMMUNE_SHIELD_MARKER;
    }

    SpellCastResult CheckForbearance()
    {
        Unit* target = GetExplTargetUnit();
        if (!target || target->HasAura(SPELL_PALADIN_FORBEARANCE))
            return SPELL_FAILED_TARGET_AURASTATE;

        return SPELL_CAST_OK;
    }

    void TriggerForbearance()
    {
        if (Unit* target = GetHitUnit())
        {
            GetCaster()->CastSpell(target, SPELL_PALADIN_FORBEARANCE, true);
            GetCaster()->CastSpell(target, SPELL_PALADIN_IMMUNE_SHIELD_MARKER, true);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_lay_on_hands::CheckForbearance);
        AfterHit += SpellHitFn(spell_pal_lay_on_hands::TriggerForbearance);
    }
};

// 53651 - Light's Beacon - Beacon of Light
class spell_pal_light_s_beacon : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_BEACON_OF_LIGHT, SPELL_PALADIN_BEACON_OF_LIGHT_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetActionTarget())
            return false;
        if (eventInfo.GetActionTarget()->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT, eventInfo.GetActor()->GetGUID()))
            return false;
        return true;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        uint32 heal = CalculatePct(healInfo->GetHeal(), aurEff->GetAmount());

        Unit::AuraList const& auras = GetCaster()->GetSingleCastAuras();
        for (Unit::AuraList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
        {
            if ((*itr)->GetId() == SPELL_PALADIN_BEACON_OF_LIGHT)
            {
                std::vector<AuraApplication*> applications;
                (*itr)->GetApplicationVector(applications);
                if (!applications.empty())
                {
                    CastSpellExtraArgs args(aurEff);
                    args.AddSpellMod(SPELLVALUE_BASE_POINT0, heal);
                    eventInfo.GetActor()->CastSpell(applications.front()->GetTarget(), SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, args);
                }
                return;
            }
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_light_s_beacon::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_light_s_beacon::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 122773 - Light's Hammer
class spell_pal_light_hammer_init_summon : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_LIGHT_HAMMER_COSMETIC,
            SPELL_PALADIN_LIGHT_HAMMER_PERIODIC
        });
    }

    void InitSummon()
    {
         for (SpellLogEffectGenericVictimParams const& summonedObject : GetSpell()->GetExecuteLogEffectTargets(SPELL_EFFECT_SUMMON, &SpellLogEffect::GenericVictimTargets))
         {
             if (Unit* hammer = ObjectAccessor::GetUnit(*GetCaster(), summonedObject.Victim))
             {
                 hammer->CastSpell(hammer, SPELL_PALADIN_LIGHT_HAMMER_COSMETIC,
                     CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetTriggeringSpell(GetSpell()));
                 hammer->CastSpell(hammer, SPELL_PALADIN_LIGHT_HAMMER_PERIODIC,
                     CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetTriggeringSpell(GetSpell()));
             }
         }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pal_light_hammer_init_summon::InitSummon);
    }
};

// 114918 - Light's Hammer (Periodic)
class spell_pal_light_hammer_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_LIGHT_HAMMER_HEALING,
            SPELL_PALADIN_LIGHT_HAMMER_DAMAGE
        });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* lightHammer = GetTarget();
        if (Unit* originalCaster = lightHammer->GetOwner())
        {
            originalCaster->CastSpell(lightHammer->GetPosition(), SPELL_PALADIN_LIGHT_HAMMER_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
            originalCaster->CastSpell(lightHammer->GetPosition(), SPELL_PALADIN_LIGHT_HAMMER_HEALING, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_light_hammer_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 204074 - Righteous Protector
class spell_pal_righteous_protector : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_AVENGING_WRATH, SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS });
    }

    bool CheckEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (SpellInfo const* procSpell = eventInfo.GetSpellInfo())
            _baseHolyPowerCost = procSpell->CalcPowerCost(POWER_HOLY_POWER, false, eventInfo.GetActor(), eventInfo.GetSchoolMask());
        else
            _baseHolyPowerCost.reset();

        return _baseHolyPowerCost.has_value();
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        int32 value = aurEff->GetAmount() * 100 * _baseHolyPowerCost->Amount;

        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_AVENGING_WRATH, Milliseconds(-value));
        GetTarget()->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS, Milliseconds(-value));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_righteous_protector::CheckEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_righteous_protector::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    Optional<SpellPowerCost> _baseHolyPowerCost;
};

// 267610 - Righteous Verdict
class spell_pal_righteous_verdict : public AuraScript
{
    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_RIGHTEOUS_VERDICT_AURA });
    }

    void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
    {
        procInfo.GetActor()->CastSpell(procInfo.GetActor(), SPELL_PALADIN_RIGHTEOUS_VERDICT_AURA, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_righteous_verdict::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 85804 - Selfless Healer
class spell_pal_selfless_healer : public AuraScript
{
    bool CheckEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (Spell const* procSpell = eventInfo.GetProcSpell())
            return procSpell->HasPowerTypeCost(POWER_HOLY_POWER);

        return false;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_selfless_healer::CheckEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 53600 - Shield of the Righteous
class spell_pal_shield_of_the_righteous : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_ARMOR });
    }

    void HandleArmor()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_ARMOR, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pal_shield_of_the_righteous::HandleArmor);
    }
};

// 184662 - Shield of Vengeance
class spell_pal_shield_of_vengeance : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_SHIELD_OF_VENGEANCE_DAMAGE }) && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = CalculatePct(GetUnitOwner()->GetMaxHealth(), GetEffectInfo(EFFECT_1).CalcValue());
        if (Player const* player = GetUnitOwner()->ToPlayer())
            AddPct(amount, player->GetRatingBonusValue(CR_VERSATILITY_DAMAGE_DONE) + player->GetTotalAuraModifier(SPELL_AURA_MOD_VERSATILITY));

        _initialAmount = amount;
    }

    void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_SHIELD_OF_VENGEANCE_DAMAGE,
            CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, _initialAmount - aurEff->GetAmount()));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_shield_of_vengeance::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectRemove += AuraEffectApplyFn(spell_pal_shield_of_vengeance::HandleRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }

    int32 _initialAmount = 0;
};

// 85256 - Templar's Verdict
class spell_pal_templar_s_verdict : public SpellScript
{
    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_TEMPLAR_VERDICT_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_PALADIN_TEMPLAR_VERDICT_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 28789 - Holy Power
class spell_pal_t3_6p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_HOLY_POWER_ARMOR,
            SPELL_PALADIN_HOLY_POWER_ATTACK_POWER,
            SPELL_PALADIN_HOLY_POWER_SPELL_POWER,
            SPELL_PALADIN_HOLY_POWER_MP5
        });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        uint32 spellId;
        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        switch (target->GetClass())
        {
            case CLASS_PALADIN:
            case CLASS_PRIEST:
            case CLASS_SHAMAN:
            case CLASS_DRUID:
                spellId = SPELL_PALADIN_HOLY_POWER_MP5;
                break;
            case CLASS_MAGE:
            case CLASS_WARLOCK:
                spellId = SPELL_PALADIN_HOLY_POWER_SPELL_POWER;
                break;
            case CLASS_HUNTER:
            case CLASS_ROGUE:
                spellId = SPELL_PALADIN_HOLY_POWER_ATTACK_POWER;
                break;
            case CLASS_WARRIOR:
                spellId = SPELL_PALADIN_HOLY_POWER_ARMOR;
                break;
            default:
                return;
        }

        caster->CastSpell(target, spellId, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_t3_6p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 64890 - Item - Paladin T8 Holy 2P Bonus
class spell_pal_t8_2p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_HOLY_MENDING });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_PALADIN_HOLY_MENDING, GetCastDifficulty());
        int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_PALADIN_HOLY_MENDING, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_t8_2p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 405547 - Paladin Protection 10.1 Class Set 2pc
class spell_pal_t30_2p_protection_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_T30_2P_HEARTFIRE_DAMAGE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        PreventDefaultAction();

        Unit* caster = procInfo.GetActor();
        uint32 ticks = sSpellMgr->AssertSpellInfo(SPELL_PALADIN_T30_2P_HEARTFIRE_DAMAGE, DIFFICULTY_NONE)->GetMaxTicks();
        uint32 damage = CalculatePct(procInfo.GetDamageInfo()->GetOriginalDamage(), aurEff->GetAmount()) / ticks;

        caster->CastSpell(procInfo.GetActionTarget(), SPELL_PALADIN_T30_2P_HEARTFIRE_DAMAGE, CastSpellExtraArgs(aurEff)
            .SetTriggeringSpell(procInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, damage));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_t30_2p_protection_bonus::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 408461 - Heartfire
class spell_pal_t30_2p_protection_bonus_heal : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_T30_2P_HEARTFIRE_HEAL });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        return procInfo.GetDamageInfo() && procInfo.GetSpellInfo() && procInfo.GetSpellInfo()->HasLabel(SPELL_LABEL_PALADIN_T30_2P_HEARTFIRE);
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_T30_2P_HEARTFIRE_HEAL, CastSpellExtraArgs(aurEff)
            .SetTriggeringSpell(procInfo.GetProcSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, procInfo.GetDamageInfo()->GetOriginalDamage()));
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pal_t30_2p_protection_bonus_heal::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pal_t30_2p_protection_bonus_heal::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 269569 - Zeal
class spell_pal_zeal : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ZEAL_AURA });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*procInfo*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_PALADIN_ZEAL_AURA, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_AURA_STACK, aurEff->GetAmount()));

        PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_zeal::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_paladin_spell_scripts()
{
    RegisterSpellScript(spell_pal_ardent_defender);
    RegisterSpellScript(spell_pal_art_of_war);
    RegisterAreaTriggerAI(areatrigger_pal_ashen_hallow);
    RegisterSpellScript(spell_pal_awakening);
    RegisterSpellScript(spell_pal_blessing_of_protection);
    RegisterSpellScript(spell_pal_blinding_light);
    RegisterSpellScript(spell_pal_crusader_might);
    RegisterSpellScript(spell_pal_crusading_strikes);
    RegisterSpellScript(spell_pal_consecration);
    RegisterAreaTriggerAI(areatrigger_pal_consecration);
    RegisterSpellScript(spell_pal_divine_purpose);
    RegisterSpellScript(spell_pal_divine_shield);
    RegisterSpellScript(spell_pal_divine_steed);
    RegisterSpellScript(spell_pal_divine_storm);
    RegisterSpellScript(spell_pal_eye_for_an_eye);
    RegisterSpellScript(spell_pal_fist_of_justice);
    RegisterSpellScript(spell_pal_glyph_of_holy_light);
    RegisterSpellScript(spell_pal_grand_crusader);
    RegisterSpellScript(spell_pal_hammer_of_the_righteous);
    RegisterSpellScript(spell_pal_hand_of_sacrifice);
    RegisterSpellScript(spell_pal_infusion_of_light);
    RegisterSpellScript(spell_pal_moment_of_glory);
    RegisterSpellScript(spell_pal_judgment);
    RegisterSpellScript(spell_pal_holy_prism);
    RegisterSpellScript(spell_pal_holy_prism_selector);
    RegisterSpellScript(spell_pal_holy_shock);
    RegisterSpellScript(spell_pal_holy_shock_damage_visual);
    RegisterSpellScript(spell_pal_holy_shock_heal_visual);
    RegisterSpellScript(spell_pal_item_healing_discount);
    RegisterSpellScript(spell_pal_item_t6_trinket);
    RegisterSpellScript(spell_pal_lay_on_hands);
    RegisterSpellScript(spell_pal_light_s_beacon);
    RegisterSpellScript(spell_pal_light_hammer_init_summon);
    RegisterSpellScript(spell_pal_light_hammer_periodic);
    RegisterSpellScript(spell_pal_righteous_protector);
    RegisterSpellScript(spell_pal_righteous_verdict);
    RegisterSpellScript(spell_pal_selfless_healer);
    RegisterSpellScript(spell_pal_shield_of_the_righteous);
    RegisterSpellScript(spell_pal_shield_of_vengeance);
    RegisterSpellScript(spell_pal_templar_s_verdict);
    RegisterSpellScript(spell_pal_t3_6p_bonus);
    RegisterSpellScript(spell_pal_t8_2p_bonus);
    RegisterSpellScript(spell_pal_t30_2p_protection_bonus);
    RegisterSpellScript(spell_pal_t30_2p_protection_bonus_heal);
    RegisterSpellScript(spell_pal_zeal);
}
