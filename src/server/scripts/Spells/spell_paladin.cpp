/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
* Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
* Ordered alphabetically using scriptname.
* Scriptnames of files in this file should be prefixed with "spell_pal_".
*/

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "Group.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptHelper.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"

enum PaladinSpells
{
    SPELL_PALADIN_ARCING_LIGHT_DAMAGE           = 114919,
    SPELL_PALADIN_ARCING_LIGHT_HEAL             = 119952,
    SPELL_PALADIN_ARDENT_DEFENDER               = 31850,
    SPELL_PALADIN_ARDENT_DEFENDER_HEAL          = 66235,
    SPELL_PALADIN_AVENGERS_SHIELD               = 31935,
    SPELL_PALADIN_AVENGING_WRATH                = 31884,
    SPELL_PALADIN_AURA_OF_SACRIFICE             = 183416,
    SPELL_PALADIN_AURA_OF_SACRIFICE_ALLY        = 210372,
    SPELL_PALADIN_AURA_OF_SACRIFICE_DAMAGE      = 210380,
    SPELL_PALADIN_AURA_OF_SACRIFICE_HEAL        = 210383,
    SPELL_PALADIN_BEACON_OF_FAITH               = 156910,
    SPELL_PALADIN_BEACON_OF_FAITH_PROC_AURA     = 177173,
    SPELL_PALADIN_BEACON_OF_LIGHT               = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL          = 53652,
    SPELL_PALADIN_BEACON_OF_LIGHT_PROC_AURA     = 53651,
    SPELL_PALADIN_BEACON_OF_VIRTUE              = 200025,
    SPELL_PALADIN_BLADE_OF_JUSTICE              = 184575,
    SPELL_PALADIN_BLINDING_LIGHT_CONFUSE        = 105421,
    SPELL_PALADIN_CONSECRATED_GROUND            = 204054,
    SPELL_PALADIN_CONSECRATION                  = 26573,
    SPELL_PALADIN_CONSECRATION_DAMAGE           = 81297,
    SPELL_PALADIN_CONSECRATION_HEAL             = 204241,
    SPELL_PALADIN_CONSECRATION_INCREASE_SPEED   = 204242, // Need impentation
    SPELL_PALADIN_CRUSADERS_JUDGMENT            = 204023,
    SPELL_PALADIN_CRUSADERS_MIGHT               = 196926,
    SPELL_PALADIN_CRUSADER_STRIKE               = 35395,
    SPELL_PALADIN_DIVINE_HAMMER                 = 198034,
    SPELL_PALADIN_DIVINE_INTERVENTION_HEAL      = 184250,
    SPELL_PALADIN_DIVINE_PURPOSE_HOLY           = 197646,
    SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1    = 216411,
    SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2    = 216413,
    SPELL_PALADIN_DIVINE_PURPOSE_RET            = 223817,
    SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA       = 223819,
    SPELL_PALADIN_DIVINE_SHIELD                 = 642,
    SPELL_PALADIN_DIVINE_STEED_BLOODELF         = 221886,
    SPELL_PALADIN_DIVINE_STEED_DRAENEI          = 221887,
    SPELL_PALADIN_DIVINE_STEED_HUMAN            = 221883,
    SPELL_PALADIN_DIVINE_STEED_SPEED            = 220509,
    SPELL_PALADIN_DIVINE_STEED_TAUREN           = 221885,
    SPELL_PALADIN_DIVINE_STORM                  = 53385,
    SPELL_PALADIN_DIVINE_STORM_DAMAGE           = 224239,
    SPELL_PALADIN_EXECUTE_SENTENCE              = 213757,
    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE         = 205202,
    SPELL_PALADIN_FERVENT_MARTYR_BUFF           = 223316,
    SPELL_PALADIN_FINAL_STAND                   = 204077,
    SPELL_PALADIN_FINAL_STAND_TAUNT             = 204079,
    SPELL_PALADIN_FIRST_AVENGER                 = 203776,
    SPELL_PALADIN_FIST_OF_JUSTICE               = 198054,
    SPELL_PALADIN_FIST_OF_JUSTICE_RETRI         = 234299,
    SPELL_PALADIN_FORBEARANCE                   = 25771,
    SPELL_PALADIN_GRAND_CRUSADER_PROC           = 85416,
    SPELL_PALADIN_GREATER_BLESSING_OF_KINGS     = 203538,
    SPELL_PALADIN_HAMMER_OF_JUSTICE             = 853,
    SPELL_HAMMER_OF_RIGHTEOUS                   = 53595,
    SPELL_HAMMER_OF_RIGHTEOUS_LIGHT_WAVE        = 88263,
    SPELL_PALADIN_HAND_OF_SACRIFICE             = 6940,
    SPELL_PALADIN_HAND_OF_THE_PROTECTOR         = 213652,
    SPELL_PALADIN_HOLY_LIGHT                    = 82326,
    SPELL_PALADIN_HOLY_PRISM_ALLIES             = 114871,
    SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL      = 114862,
    SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2    = 114870,
    SPELL_PALADIN_HOLY_PRISM_ENNEMIES           = 114852,
    SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL        = 121551,
    SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2      = 121552,
    SPELL_PALADIN_HOLY_SHOCK_DAMAGE             = 25912,
    SPELL_PALADIN_HOLY_SHOCK_GENERIC            = 20473,
    SPELL_PALADIN_HOLY_SHOCK_HEAL               = 25914,
    SPELL_PALADIN_INFUSION_OF_LIGHT_AURA        = 54149,
    SPELL_PALADIN_JUDGMENT                      = 20271,
    SPELL_PALADIN_JUDGMENT_HOLY_DEBUFF          = 214222,
    SPELL_PALADIN_JUDGMENT_OF_LIGHT_HEAL        = 183811,
    SPELL_PALADIN_JUDGMENT_RETRI_DEBUFF         = 197277,
    SPELL_PALADIN_JUSTICARS_VENGEANCE           = 215661,
    SPELL_PALADIN_LIGHTS_HAMMER_TICK            = 114918,
    SPELL_PALADIN_LIGHT_HAMMER_COSMETIC         = 122257,
    SPELL_PALADIN_LIGHT_OF_DAWN                 = 85222,
    SPELL_PALADIN_LIGHT_OF_DAWN_TRIGGER         = 185984,
    SPELL_PALADIN_LIGHT_OF_THE_MARTYR           = 183998,
    SPELL_PALADIN_LIGHT_OF_THE_MARTYR_DAMAGE    = 196917,
    SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR        = 184092,
    SPELL_PALADIN_RETRIBUTION_AURA_DAMAGE       = 204011,
    SPELL_PALADIN_RIGHTEOUS_PROTECTOR           = 204074,
    SPELL_PALADIN_SEAL_OF_LIGHT                 = 213757,
    SPELL_PALADIN_SERAPHIM                      = 152262,
    SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS       = 53600,
    SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC  = 132403,
    SPELL_PALADIN_SHIELD_OF_VENGEANCE_DAMAGE    = 184689,
    SPELL_PALADIN_TEMPLARS_VERDICT              = 85256,
    SPELL_PALADIN_TEMPLARS_VERDICT_DAMAGE       = 224266,
    SPELL_PALADIN_THE_FIRES_OF_JUSTICE          = 209785,
    SPELL_PALADIN_WORD_OF_GLORY                 = 210191,
    SPELL_PALADIN_WORD_OF_GLORY_HEAL            = 214894,
    SPELL_PALADIN_BLESSED_HAMMER                = 204019,
};

enum PaladinNPCs
{
    NPC_PALADIN_LIGHTS_HAMMER = 59738
};

enum PaladinSpellVisualKit
{
    PALADIN_VISUAL_KIT_DIVINE_STORM = 73892
};

//7.3.2.25549
// Beacon of Virtue - 200025
class spell_pal_beacon_of_virtue : public SpellScript
{
    PrepareSpellScript(spell_pal_beacon_of_virtue);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint8 maxTargets = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints + 1;
        if (!maxTargets)
            return;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_beacon_of_virtue::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_beacon_of_virtue::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_beacon_of_virtue::FilterTargets, EFFECT_2, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// Beacon of Faith - 156910
class spell_pal_beacon_of_faith : public SpellScript
{
    PrepareSpellScript(spell_pal_beacon_of_faith);

    SpellCastResult CheckCast()
    {
        Unit* target = GetExplTargetUnit();

        if (!target)
            return SPELL_FAILED_DONT_REPORT;

        if (target->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT))
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void Register()
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_beacon_of_faith::CheckCast);
    }
};

// 53563 - Beacon of Light
class spell_pal_beacon_of_light : public SpellScript
{
    PrepareSpellScript(spell_pal_beacon_of_light);

    SpellCastResult CheckCast()
    {
        Unit* target = GetExplTargetUnit();

        if (!target)
            return SPELL_FAILED_DONT_REPORT;

        if (target->HasAura(SPELL_PALADIN_BEACON_OF_FAITH))
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void Register()
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_beacon_of_light::CheckCast);
    }
};

// 53563 - Beacon of Light / Beacon of Faith - 156910 / Beacon of Virtue 200025
class spell_pal_beacon_of_light_aura : public AuraScript
{
    PrepareAuraScript(spell_pal_beacon_of_light_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();

        if (!caster)
            return;

        if (GetSpellInfo()->Id == SPELL_PALADIN_BEACON_OF_LIGHT || GetSpellInfo()->Id == SPELL_PALADIN_BEACON_OF_VIRTUE)
            caster->CastSpell(target, SPELL_PALADIN_BEACON_OF_LIGHT_PROC_AURA, true);
        else
            caster->CastSpell(target, SPELL_PALADIN_BEACON_OF_FAITH_PROC_AURA, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();

        if (!caster)
            return;

        if (GetSpellInfo()->Id == SPELL_PALADIN_BEACON_OF_LIGHT || GetSpellInfo()->Id == SPELL_PALADIN_BEACON_OF_VIRTUE)
            caster->RemoveAura(SPELL_PALADIN_BEACON_OF_LIGHT_PROC_AURA);
        else
            caster->RemoveAura(SPELL_PALADIN_BEACON_OF_FAITH_PROC_AURA);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_pal_beacon_of_light_aura::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_pal_beacon_of_light_aura::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 53651 - Beacon of Light Proc / Beacon of Faith (proc aura) - 177173
class spell_pal_beacon_of_light_proc : public AuraScript
{
    PrepareAuraScript(spell_pal_beacon_of_light_proc);

    int32 GetPctBySpell(uint32 spellID) const
    {
        int32 pct = 0;

        switch (spellID)
        {
            case SPELL_PALADIN_ARCING_LIGHT_HEAL: // Light's Hammer
            case SPELL_PALADIN_HOLY_PRISM_ALLIES: // Holy Prism
            case SPELL_PALADIN_LIGHT_OF_DAWN: // Light of Dawn
                pct = 15; // 15% heal from these spells
                break;
            default:
                pct = 40; // 40% heal from all other heals
                break;
        }

        return pct;
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Unit* ownerOfBeacon = GetTarget();
        Unit* targetOfBeacon = GetCaster();
        Unit* targetOfHeal = eventInfo.GetActionTarget();

        if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id != SPELL_PALADIN_BEACON_OF_LIGHT_HEAL && eventInfo.GetSpellInfo()->Id != SPELL_PALADIN_LIGHT_OF_THE_MARTYR && targetOfBeacon->IsWithinLOSInMap(ownerOfBeacon) && targetOfHeal->GetGUID() != targetOfBeacon->GetGUID())
            return true;

        return false;
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        bool auraCheck;
        Unit* ownerOfBeacon = GetTarget();
        Unit* targetOfBeacon = GetCaster();

        if (!targetOfBeacon)
            return;

        HealInfo* healInfo = eventInfo.GetHealInfo();

        if (!healInfo)
            return;

        int32 bp = CalculatePct(healInfo->GetHeal(), GetPctBySpell(GetSpellInfo()->Id));

        if (GetSpellInfo()->Id == SPELL_PALADIN_BEACON_OF_LIGHT_PROC_AURA && (targetOfBeacon->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT) || targetOfBeacon->HasAura(SPELL_PALADIN_BEACON_OF_VIRTUE)))
        {
            ownerOfBeacon->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, bp, targetOfBeacon, true);
            auraCheck = true;
        }
            
        if ((GetSpellInfo()->Id == SPELL_PALADIN_BEACON_OF_FAITH_PROC_AURA && targetOfBeacon->HasAura(SPELL_PALADIN_BEACON_OF_FAITH)))
        {
            bp /= 2;
            ownerOfBeacon->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, bp, targetOfBeacon, true);
            auraCheck = true;
        }

        if (!auraCheck)
        ownerOfBeacon->RemoveAura(GetSpellInfo()->Id);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_beacon_of_light_proc::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_beacon_of_light_proc::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// Judgment of Light - 183778
class spell_pal_judgment_of_light : public AuraScript
{
    PrepareAuraScript(spell_pal_judgment_of_light);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_JUDGMENT)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_judgment_of_light::CheckProc);
    }
};

// Judgment of Light Proc - 196941
class spell_pal_judgment_of_light_proc : public AuraScript
{
    PrepareAuraScript(spell_pal_judgment_of_light_proc);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (!GetCaster())
            return;

        Unit* attacker = eventInfo.GetActor();
        if (!attacker)
            return;

        if (eventInfo.GetActor()->GetGUID() != GetCaster()->GetGUID())
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(attacker, SPELL_PALADIN_JUDGMENT_OF_LIGHT_HEAL, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_judgment_of_light_proc::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// Infusion of Light - 53576
class spell_pal_infusion_of_light : public AuraScript
{
    PrepareAuraScript(spell_pal_infusion_of_light);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_HOLY_SHOCK_DAMAGE || eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_HOLY_SHOCK_HEAL);

        if (_spellCanProc)
            return true;

        return false;
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* caster = GetCaster();

        caster->CastSpell(caster, SPELL_PALADIN_INFUSION_OF_LIGHT_AURA, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_infusion_of_light::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_infusion_of_light::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// Holy Shock - 20473
class spell_pal_holy_shock : public SpellScript
{
    PrepareSpellScript(spell_pal_holy_shock);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_HOLY_SHOCK_HEAL,
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
        if (Player* caster = GetCaster()->ToPlayer())
        {
            if (Unit* unitTarget = GetHitUnit())
            {
                if (caster->IsFriendlyTo(unitTarget))
                    caster->CastSpell(unitTarget, SPELL_PALADIN_HOLY_SHOCK_HEAL, true);
                else
                    caster->CastSpell(unitTarget, SPELL_PALADIN_HOLY_SHOCK_DAMAGE, true);
            }

            if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1))
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Flash of Light - 19750
class spell_pal_flash_of_light : public SpellScript
{
    PrepareSpellScript(spell_pal_flash_of_light);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAurasDueToSpell(SPELL_PALADIN_INFUSION_OF_LIGHT_AURA);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_flash_of_light::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// Crusader Strike - 35395
class spell_pal_crusader_strike : public SpellScript
{
    PrepareSpellScript(spell_pal_crusader_strike);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (caster->HasAura(SPELL_PALADIN_CRUSADERS_MIGHT))
        {
            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC, -1.5 * IN_MILLISECONDS);

            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_LIGHT_OF_DAWN))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_LIGHT_OF_DAWN, -1.5 * IN_MILLISECONDS);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_crusader_strike::HandleOnHit, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
    }
};

// Light of the Protector - 184092 and Hand of the Protector - 213652
class spell_pal_light_of_the_protector : public SpellScript
{
    PrepareSpellScript(spell_pal_light_of_the_protector);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        uint32 dmg;

        if (GetSpellInfo()->Id == SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR)
        {
            int32 effvalue = sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR)->GetEffect(1)->BasePoints;
            int32 healthMissing = caster->GetMaxHealth() - caster->GetHealth();

            dmg = ApplyPct(healthMissing, effvalue) + GetHitHeal();

            if (caster->FindNearestCreature(43499, 8) && caster->HasAura(SPELL_PALADIN_CONSECRATION)) // if you are standing in your consecration, the heal is increased by 20%
                AddPct(dmg, 20);
        }

        if (GetSpellInfo()->Id == SPELL_PALADIN_HAND_OF_THE_PROTECTOR)
        {
            int32 effvalue = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HAND_OF_THE_PROTECTOR)->GetEffect(1)->BasePoints;

            Unit* target = GetHitUnit();
            int32 healthMissing = target->GetMaxHealth() - target->GetHealth();

            dmg = ApplyPct(healthMissing, effvalue) + GetHitHeal();
        }

        dmg = std::max(dmg, (uint32)0);

        SetHitHeal(dmg);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_the_protector::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// Shield of the Righteous - 53600
class spell_pal_shield_of_the_righteous : public SpellScript
{
    PrepareSpellScript(spell_pal_shield_of_the_righteous);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            if (GetHitUnit())
            {
                if (player->FindNearestCreature(43499, 8) && player->HasAura(SPELL_PALADIN_CONSECRATION)) //if player is standing in his consecration all effects are increased by 20%
                {
                    int32 previousDuration = 0;

                    if (Aura* aur = player->GetAura(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC))
                        previousDuration = aur->GetDuration();

                    uint32 dmg = GetHitDamage();
                    dmg += dmg / 5;
                    SetHitDamage(dmg); //damage is increased by 20%

                    float mastery = player->GetFloatValue(PLAYER_MASTERY);

                    int32 reduction = int32(((-25 - int32(mastery / 2.0f)) * 120.0f) / 100.0f); //damage reduction is increased by 20%
                    player->CastCustomSpell(player, SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC, &reduction, NULL, NULL, true);

                    if (Aura* aur = player->GetAura(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC))
                        aur->SetDuration(aur->GetDuration() + previousDuration);
                }
                else
                {
                    int32 previousDuration = 0;

                    if (Aura* aur = player->GetAura(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC))
                        previousDuration = aur->GetDuration();

                    player->CastSpell(player, SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC, true);

                    if (Aura* aur = player->GetAura(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS_PROC))
                        aur->SetDuration(aur->GetDuration() + previousDuration);
                }

                if (Aura* aura = player->GetAura(SPELL_PALADIN_RIGHTEOUS_PROTECTOR)) //reduce the CD of Light of the Protector and Avenging Wrath by 3
                {
                    uint32 cooldownReduction = aura->GetEffect(EFFECT_0)->GetBaseAmount() * IN_MILLISECONDS;

                    if (player->HasSpell(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR))
                        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_THE_PROTECTOR))
                            player->GetSpellHistory()->ReduceChargeCooldown(spellInfo->ChargeCategoryId, cooldownReduction);

                    if (player->HasSpell(SPELL_PALADIN_HAND_OF_THE_PROTECTOR))
                        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HAND_OF_THE_PROTECTOR))
                            player->GetSpellHistory()->ReduceChargeCooldown(spellInfo->ChargeCategoryId, cooldownReduction);

                    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_AVENGING_WRATH))
                        player->GetSpellHistory()->ReduceChargeCooldown(spellInfo->ChargeCategoryId, cooldownReduction);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_shield_of_the_righteous::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Grand Crusader - 85416
// 204019 - Blessed Hammer / Hammer of the Righteous - 53595
class spell_pal_grand_crusader : public SpellScript
{
    PrepareSpellScript(spell_pal_grand_crusader);

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        //if caster is standing in his consecration create a "wave of light"
        if (GetSpellInfo()->Id == SPELL_HAMMER_OF_RIGHTEOUS)
            if (caster->FindNearestCreature(43499, 8) && caster->HasAura(SPELL_PALADIN_CONSECRATION))
                caster->CastSpell(caster, SPELL_HAMMER_OF_RIGHTEOUS_LIGHT_WAVE, true);

        int32 grandCrusaderProcChance = 15;

        if (caster->HasAura(SPELL_PALADIN_FIRST_AVENGER))
            grandCrusaderProcChance += 10;

        if (roll_chance_i(grandCrusaderProcChance))
        {
            caster->CastSpell(caster, SPELL_PALADIN_GRAND_CRUSADER_PROC, true);
            caster->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);

            if (caster->HasAura(SPELL_PALADIN_CRUSADERS_JUDGMENT))
                caster->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_PALADIN_JUDGMENT)->ChargeCategoryId);
        }    
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pal_grand_crusader::HandleAfterCast);
    }
};

// 31935 - Avenger's Shield
class spell_pal_avengers_shield : public SpellScript
{
    PrepareSpellScript(spell_pal_avengers_shield);

    void HandleOnHit(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        if (caster->HasAura(SPELL_PALADIN_GRAND_CRUSADER_PROC))
            caster->RemoveAurasDueToSpell(SPELL_PALADIN_GRAND_CRUSADER_PROC);

        int32 damage = GetHitDamage();

        if (caster->HasAura(SPELL_PALADIN_FIRST_AVENGER))
            AddPct(damage, 50);

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_avengers_shield::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 205191 - Eye for an Eye
class spell_pal_eye_for_an_eye : public AuraScript
{
    PrepareAuraScript(spell_pal_eye_for_an_eye);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE });
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 210220 - Holy Wrath
class spell_pal_holy_wrath : public SpellScript
{
    PrepareSpellScript(spell_pal_holy_wrath);

    void HandleOnHit(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        int32 dmg = 0;
        int32 maxHealthDamage = caster->GetMaxHealth();
        int32 healthMissing = maxHealthDamage - caster->GetHealth();

        AddPct(maxHealthDamage, 20);
        dmg = healthMissing * 2;

        if (dmg > maxHealthDamage)
            dmg = maxHealthDamage;

        if (target->IsPlayer())
            ApplyPct(dmg, 35);

        SetHitDamage(dmg);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_wrath::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//231832 - Blade of Wrath! (proc)
class spell_pal_blade_of_wrath_proc : public AuraScript
{
    PrepareAuraScript(spell_pal_blade_of_wrath_proc);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_BLADE_OF_JUSTICE, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_blade_of_wrath_proc::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 184662 - Shield of Vengeance
class spell_pal_shield_of_vengeance : public AuraScript
{
    PrepareAuraScript(spell_pal_shield_of_vengeance);

    int32 absorb;
    int32 currentAbsorb;

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        if (Unit* caster = GetCaster())
        {
            canBeRecalculated = false;

            float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
            absorb = (ap * 20);
            amount += absorb;
        }
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        currentAbsorb += dmgInfo.GetDamage();
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (currentAbsorb < absorb)
            return;

        std::list<Unit*> targets;
        caster->GetAttackableUnitListInRange(targets, 8.0f);
        
		if (uint32 targetSize = targets.size())
           absorb /= targetSize;

        caster->CastCustomSpell(SPELL_PALADIN_SHIELD_OF_VENGEANCE_DAMAGE, SPELLVALUE_BASE_POINT0, absorb, caster, true);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_shield_of_vengeance::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectRemove += AuraEffectRemoveFn(spell_pal_shield_of_vengeance::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_shield_of_vengeance::Absorb, EFFECT_0);
    }
};

// 53385 - Divine Storm
class spell_pal_divine_storm : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_storm);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_STORM_DAMAGE });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();
        caster->SendPlaySpellVisualKit(PALADIN_VISUAL_KIT_DIVINE_STORM, 0, 0);

        if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE_RETRI))
        {
            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -7.5 * IN_MILLISECONDS);
        }

        if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetHitUnit())
                caster->CastSpell(target, SPELL_PALADIN_DIVINE_STORM_DAMAGE, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_pal_divine_storm::HandleOnCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_divine_storm::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 85256 - Templar's Verdict
class spell_pal_templar_s_verdict : public SpellScript
{
    PrepareSpellScript(spell_pal_templar_s_verdict);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_TEMPLARS_VERDICT_DAMAGE });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (Unit* target = GetExplTargetUnit())
            caster->CastSpell(target, SPELL_PALADIN_TEMPLARS_VERDICT_DAMAGE, true);

        if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE_RETRI))
        {
            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -7.5 * IN_MILLISECONDS);
        }

        if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 190784 - Divine Steed
class spell_pal_divine_steed : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_steed);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_PALADIN_DIVINE_STEED_SPEED,
            SPELL_PALADIN_DIVINE_STEED_HUMAN,
            SPELL_PALADIN_DIVINE_STEED_DRAENEI,
            SPELL_PALADIN_DIVINE_STEED_BLOODELF,
            SPELL_PALADIN_DIVINE_STEED_TAUREN
        });
    }

    void HandleOnHit()
    {
        if (Player* target = GetHitPlayer())
        {
            uint32 spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
            switch (target->getRace())
            {
            case RACE_HUMAN:
                spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                break;
            case RACE_DWARF:
                spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                break;
            case RACE_DRAENEI:
            case RACE_LIGHTFORGED_DRAENEI:
                spellId = SPELL_PALADIN_DIVINE_STEED_DRAENEI;
                break;
            case RACE_BLOODELF:
                spellId = SPELL_PALADIN_DIVINE_STEED_BLOODELF;
                break;
            case RACE_TAUREN:
                spellId = SPELL_PALADIN_DIVINE_STEED_TAUREN;
                break;
            default:
                break;
            }
            target->CastSpell(target, spellId, true);
            target->CastSpell(target, SPELL_PALADIN_DIVINE_STEED_SPEED, false);
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_pal_divine_steed::HandleOnHit);
    }
};

// Activate Forbearance
// Called by Blessing of Protection - 1022, Lay on Hands - 633, Blessing of Spellwarding - 204018
class spell_pal_activate_forbearance : public SpellScript
{
    PrepareSpellScript(spell_pal_activate_forbearance);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_FORBEARANCE });
    }

    SpellCastResult CheckForbearance()
    {
        if (Unit* target = GetExplTargetUnit())
        {
            if (target->HasAura(SPELL_PALADIN_FORBEARANCE))
            {
                return SPELL_FAILED_TARGET_AURASTATE;
            }
        }
        return SPELL_CAST_OK;
    }

    void HandleOnHit()
    {
        if (Player* player = GetCaster()->ToPlayer())
            if (Unit* target = GetHitUnit())
                player->CastSpell(target, SPELL_PALADIN_FORBEARANCE, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_activate_forbearance::CheckForbearance);
        OnHit += SpellHitFn(spell_pal_activate_forbearance::HandleOnHit);
    }
};

// Divine Shield - 642
class spell_pal_divine_shield : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_shield);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_FORBEARANCE });
    }

    SpellCastResult CheckForbearance()
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->HasAura(SPELL_PALADIN_FORBEARANCE))
                return SPELL_FAILED_TARGET_AURASTATE;
        }
        return SPELL_CAST_OK;
    }

    void HandleOnCast()
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            player->CastSpell(player, SPELL_PALADIN_FORBEARANCE, true);

            if (player->HasSpell(SPELL_PALADIN_FINAL_STAND))
                player->CastSpell(player, SPELL_PALADIN_FINAL_STAND_TAUNT, true);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_divine_shield::CheckForbearance);
        OnCast += SpellCastFn(spell_pal_divine_shield::HandleOnCast);
    }
};

// Justicar's Vengeance - 215661
class spell_pal_justicars_vengeance : public SpellScript
{
    PrepareSpellScript(spell_pal_justicars_vengeance);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        if (target->HasAuraType(SPELL_AURA_MOD_STUN) || target->HasAuraWithMechanic(1 << MECHANIC_STUN))
        {
            int32 damage = GetHitDamage();
            AddPct(damage, GetEffectInfo(EFFECT_1)->BasePoints);

            SetHitDamage(damage);
            SetEffectValue(damage);
        }

        if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);

        if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE_RETRI))
            if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -10 * IN_MILLISECONDS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_justicars_vengeance::HandleHit, EFFECT_0, SPELL_EFFECT_HEALTH_LEECH);
    }
};

// 213757 - Execution Sentence
class spell_pal_execute_sentence : public SpellScript
{
    PrepareSpellScript(spell_pal_execute_sentence);

    void HandleOnHit()
    {
        if (Unit* caster = GetCaster())
        {
            bool noHpCost = false;
            uint8 hp = caster->GetPower(POWER_HOLY_POWER);
            uint8 hpCost = 3;

            if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
                noHpCost = true;
            }

            if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE) && !noHpCost)
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                hpCost -= 1;
            }

            if (!noHpCost)
            {
                hp -= hpCost;
                caster->SetPower(POWER_HOLY_POWER, hp);
            }

            if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE_RETRI))
            {
                if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                    caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -7.5 * IN_MILLISECONDS);
            }
        }
    }
    void Register() override
    {
        OnCast += SpellCastFn(spell_pal_execute_sentence::HandleOnHit);
    }
};

// The fires of Justice - 203316
class spell_pal_the_fire_of_justice : public AuraScript
{
    PrepareAuraScript(spell_pal_the_fire_of_justice);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_CRUSADER_STRIKE)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_the_fire_of_justice::CheckProc);
    }
};

//198034 - Divine Hammer
class spell_pal_divine_hammer : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_hammer);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_HAMMER });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        uint8 hp = GetCaster()->GetPower(POWER_HOLY_POWER);
        GetCaster()->SetPower(POWER_HOLY_POWER, hp + 2);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_divine_hammer::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 210191 - Word of Glory
class spell_pal_word_of_glory : public SpellScript
{
    PrepareSpellScript(spell_pal_word_of_glory);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 const maxTargets = uint32(GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue(GetCaster()));

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

    void HandleOnCast()
    {
        if (Unit* caster = GetCaster())
        {
            bool noHpCost = false;
            // Personnal Heal
            caster->CastSpell(caster, SPELL_PALADIN_WORD_OF_GLORY_HEAL, true);

            uint8 hp = caster->GetPower(POWER_HOLY_POWER);
            uint8 hpCost = 3;

            if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA))
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
                noHpCost = true;
            }

            if (caster->HasAura(SPELL_PALADIN_THE_FIRES_OF_JUSTICE) && !noHpCost)
            {
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_THE_FIRES_OF_JUSTICE);
                hpCost -= 1;
            }

            if (!noHpCost)
            {
                hp -= hpCost;
                caster->SetPower(POWER_HOLY_POWER, hp);
            }

            if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE_RETRI))
            {
                if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                    caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -7.5 * IN_MILLISECONDS);
            }
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_pal_word_of_glory::HandleOnCast);
    }

private:
    std::list<WorldObject*> _targets;
};

// 152262 - Seraphim
class spell_pal_seraphim : public SpellScript
{
    PrepareSpellScript(spell_pal_seraphim);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_SERAPHIM, SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS });
    }

    SpellCastResult CheckCast()
    {
        uint32 ChargeCategoryId = sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId;
        if (!GetCaster()->GetSpellHistory()->HasCharge(ChargeCategoryId))
            return SPELL_FAILED_NO_POWER;

        return SPELL_FAILED_SUCCESS;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        uint32 ChargeCategoryId = sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId;
        SpellHistory* spellHistory = GetCaster()->GetSpellHistory();

        int32 useCharges = std::min(GetSpellInfo()->GetEffect(effIndex)->BasePoints, spellHistory->GetChargeCount(ChargeCategoryId));

        for (uint8 i = 0; i < useCharges; ++i)
            spellHistory->ConsumeCharge(ChargeCategoryId);

        if (Aura* seraphimAura = GetCaster()->GetAura(SPELL_PALADIN_SERAPHIM))
            seraphimAura->SetDuration(GetSpellInfo()->GetMaxDuration() * useCharges);

        spellHistory->ForceSendSpellCharge(sSpellCategoryStore.LookupEntry(ChargeCategoryId));
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_seraphim::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_seraphim::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 20271 - Judgement
class spell_pal_judgment : public SpellScript
{
    PrepareSpellScript(spell_pal_judgment);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();
        uint32 spec = caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID);
        switch (spec)
        {
            case TALENT_SPEC_PALADIN_RETRIBUTION:
            {
                caster->CastSpell(target, SPELL_PALADIN_JUDGMENT_RETRI_DEBUFF);
                break;
            }
            case TALENT_SPEC_PALADIN_HOLY:
            {
                caster->CastSpell(target, SPELL_PALADIN_JUDGMENT_HOLY_DEBUFF);

                if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE))
                {
                    if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                        caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -10 * IN_MILLISECONDS);
                }
                break;
            }
            case TALENT_SPEC_PALADIN_PROTECTION:
            {
                caster->ToPlayer()->GetSpellHistory()->ReduceChargeCooldown(sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId, 1000);

                if (caster->HasAura(SPELL_PALADIN_FIST_OF_JUSTICE))
                {
                    if (caster->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE))
                        caster->GetSpellHistory()->ModifyCooldown(SPELL_PALADIN_HAMMER_OF_JUSTICE, -10 * IN_MILLISECONDS);
                }
                break;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_judgment::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Divine Purpose Proc
// Called by Seal of Light - 202273, Justicar's Vengeance - 215661, Word of Glory - 210191, Execution Sentence - 213757, Divine Storm - 53385, Templar's Verdict - 85256
// Called by Holy Shock - 20473, Light of Dawn - 85222
class spell_pal_divine_purpose_proc : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_purpose_proc);

    void HandleAfterCast()
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            if (player->HasSpell(SPELL_PALADIN_DIVINE_PURPOSE_RET) || player->HasSpell(SPELL_PALADIN_DIVINE_PURPOSE_HOLY))
            {
                uint32 spec = player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID);
                uint32 activateSpell = GetSpellInfo()->Id;

                switch (spec)
                {
                    case TALENT_SPEC_PALADIN_RETRIBUTION:
                    {
                        if (roll_chance_i(20))
                        {
                            if (activateSpell == SPELL_PALADIN_SEAL_OF_LIGHT || activateSpell == SPELL_PALADIN_JUSTICARS_VENGEANCE || activateSpell == SPELL_PALADIN_WORD_OF_GLORY || activateSpell == SPELL_PALADIN_EXECUTE_SENTENCE || activateSpell == SPELL_PALADIN_DIVINE_STORM || activateSpell == SPELL_PALADIN_TEMPLARS_VERDICT)
                                player->CastSpell(player, SPELL_PALADIN_DIVINE_PURPOSE_RET_AURA);
                        }
                        break;
                    } 
                    case TALENT_SPEC_PALADIN_HOLY:
                    {
                        if (roll_chance_i(15))
                        {
                            if (activateSpell == SPELL_PALADIN_HOLY_SHOCK_GENERIC)
                            {
                                player->CastSpell(player, SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_1);

                                if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC))
                                    player->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_HOLY_SHOCK_GENERIC, true);
                            }

                            if (activateSpell == SPELL_PALADIN_LIGHT_OF_DAWN)
                            {
                                player->CastSpell(player, SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2);

                                if (player->GetSpellHistory()->HasCooldown(SPELL_PALADIN_LIGHT_OF_DAWN))
                                    player->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_LIGHT_OF_DAWN, true);
                            }
                        }
                        break;
                    }  
                }
            }
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pal_divine_purpose_proc::HandleAfterCast);
    }
};

//7.3.2.25549 END

// 216860 - Judgement of the Pure
class spell_pal_judgement_of_the_pure : public SpellScriptLoader
{
public:
    spell_pal_judgement_of_the_pure() : SpellScriptLoader("spell_pal_judgement_of_the_pure") {}

    class spell_pal_judgement_of_the_pure_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_judgement_of_the_pure_AuraScript);

        bool HandleProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_PALADIN_JUDGMENT)
                return true;
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_judgement_of_the_pure_AuraScript::HandleProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_judgement_of_the_pure_AuraScript();
    }
};

// 6940 - Hand of Sacrifice
class spell_pal_hand_of_sacrifice : public SpellScriptLoader
{
public:
    spell_pal_hand_of_sacrifice() : SpellScriptLoader("spell_pal_hand_of_sacrifice") { }

    class spell_pal_hand_of_sacrifice_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_hand_of_sacrifice_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HAND_OF_SACRIFICE))
                return false;
            return true;
        }

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
            OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice_AuraScript::Split, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_hand_of_sacrifice_AuraScript();
    }
};

// Holy Prism - 114165
class spell_pal_holy_prism : public SpellScriptLoader
{
public:
    spell_pal_holy_prism() : SpellScriptLoader("spell_pal_holy_prism") { }

    class spell_pal_holy_prism_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_prism_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (player->IsValidAttackTarget(target))
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2, true);
                    }
                    else
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_holy_prism_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_prism_SpellScript();
    }
};

// Holy Prism (damage) - 114852 or Holy Prism (heal) - 114871
// Called by Holy Prism (visual damage) - 114862 or Holy Prism (visual heal) - 121551
class spell_pal_holy_prism_effect : public SpellScriptLoader
{
public:
    spell_pal_holy_prism_effect() : SpellScriptLoader("spell_pal_holy_prism_effect") { }

    class spell_pal_holy_prism_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_prism_effect_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    // damage
                    if (GetSpellInfo()->Id == 114862)
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_ENNEMIES, true);
                    // heal
                    else if (GetSpellInfo()->Id == 121551)
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_ALLIES, true);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_holy_prism_effect_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_prism_effect_SpellScript();
    }
};

// Called by Holy Prism (heal) - 114852 or Holy Prism (damage) - 114871
class spell_pal_holy_prism_visual : public SpellScriptLoader
{
public:
    spell_pal_holy_prism_visual() : SpellScriptLoader("spell_pal_holy_prism_visual") { }

    class spell_pal_holy_prism_visual_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_holy_prism_visual_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (player->IsValidAttackTarget(target))
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_DAMAGE_VISUAL_2, true);
                    }
                    else
                    {
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2, true);
                        player->CastSpell(target, SPELL_PALADIN_HOLY_PRISM_HEAL_VISUAL_2, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_holy_prism_visual_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_holy_prism_visual_SpellScript();
    }
};

// Zeal - 217020
class spell_pal_zeal : public SpellScriptLoader
{
public:
    spell_pal_zeal() : SpellScriptLoader("spell_pal_zeal") {}

    class spell_pal_zeal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_zeal_SpellScript);

    public:
        spell_pal_zeal_SpellScript()
        {
            targetIdx = 0;
        }

    private:

        uint8 targetIdx;

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            int32 dmg = GetHitDamage();
            for (int i = 0; i < targetIdx; ++i) //damage is reduced by 40% with each jump
            {
                ApplyPct(dmg, 60);
            }
            SetHitDamage(dmg);
            targetIdx++;
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_zeal_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_zeal_SpellScript();
    }
};

// Light of the Martyr - 183998
class spell_pal_light_of_the_martyr : public SpellScriptLoader
{
public:
    spell_pal_light_of_the_martyr() : SpellScriptLoader("spell_pal_light_of_the_martyr") {}

    class spell_pal_light_of_the_martyr_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_the_martyr_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_THE_MARTYR_DAMAGE))
                return false;
            return true;
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            int32 dmg = (GetHitHeal() * 50.0f) / 100.0f;
            caster->CastCustomSpell(caster, SPELL_PALADIN_LIGHT_OF_THE_MARTYR_DAMAGE, &dmg, NULL, NULL, true);

            if (caster->HasAura(SPELL_PALADIN_FERVENT_MARTYR_BUFF))
                caster->RemoveAurasDueToSpell(SPELL_PALADIN_FERVENT_MARTYR_BUFF);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_the_martyr_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_the_martyr_SpellScript();
    }
};

// Bastion of Light - 204035
class spell_pal_bastion_of_light : public SpellScriptLoader
{
public:
    spell_pal_bastion_of_light() : SpellScriptLoader("spell_pal_bastion_of_light") {}

    class spell_pal_bastion_of_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_bastion_of_light_SpellScript);

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            caster->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHIELD_OF_THE_RIGHTEOUS)->ChargeCategoryId);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pal_bastion_of_light_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_bastion_of_light_SpellScript();
    }
};

// Light of Dawn - 85222
class spell_pal_light_of_dawn : public SpellScriptLoader
{
public:
    spell_pal_light_of_dawn() : SpellScriptLoader("spell_pal_light_of_dawn") {}

    class spell_pal_light_of_dawn_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_dawn_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_LIGHT_OF_DAWN_TRIGGER))
                return false;
            return true;
        }

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_PALADIN_LIGHT_OF_DAWN_TRIGGER, true);

                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2))
                    caster->RemoveAurasDueToSpell(SPELL_PALADIN_DIVINE_PURPOSE_HOLY_AURA_2);
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_pal_light_of_dawn_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_dawn_SpellScript();
    }
};

//203538 - Greater Blessing of Kings
class spell_pal_greater_blessing_of_kings : public SpellScriptLoader
{
public:
    spell_pal_greater_blessing_of_kings() : SpellScriptLoader("spell_pal_greater_blessing_of_kings") { }

    class spell_pal_greater_blessing_of_kings_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_greater_blessing_of_kings_AuraScript);

    public:
        spell_pal_greater_blessing_of_kings_AuraScript() : leftAbsorbAmount(0), maxAbsorbAmount(0) { }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_PALADIN_GREATER_BLESSING_OF_KINGS });
        }

        bool Load() override
        {
            maxAbsorbAmount = 2.7f * GetCaster()->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_ALL, true);
            leftAbsorbAmount = maxAbsorbAmount;
            return GetUnitOwner()->IsPlayer();
        }

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            leftAbsorbAmount = maxAbsorbAmount;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = std::min(dmgInfo.GetDamage(), leftAbsorbAmount);
            leftAbsorbAmount -= absorbAmount;
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_greater_blessing_of_kings_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_greater_blessing_of_kings_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_greater_blessing_of_kings_AuraScript::Absorb, EFFECT_1);
        }

    private:
        uint32 leftAbsorbAmount;
        uint32 maxAbsorbAmount;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_greater_blessing_of_kings_AuraScript();
    }
};

// 185984 - Light of Dawn aoe heal
class spell_pal_light_of_dawn_trigger : public SpellScriptLoader
{
public:
    spell_pal_light_of_dawn_trigger() : SpellScriptLoader("spell_pal_light_of_dawn_trigger") {}

    class spell_pal_light_of_dawn_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_light_of_dawn_trigger_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            uint8 limit = 5;

            targets.remove_if([caster](WorldObject* target)
            {
                Position pos = target->GetPosition();
                return !(caster->IsWithinDist2d(&pos, 15.0f) && caster->isInFront(target, float(M_PI / 3))); //must be in a cone in 15 yards
            });

            Trinity::Containers::RandomResize(targets, limit); //max 5 targets.
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            int32 dmg = GetHitHeal();

            dmg += GetCaster()->GetUInt32Value(UNIT_FIELD_ATTACK_POWER) * 1.8f;

            SetHitHeal(dmg);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_light_of_dawn_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_dawn_trigger_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_HEAL);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_light_of_dawn_trigger_SpellScript();
    }
};

// Divine Intervention - 213313
class spell_pal_divine_intervention : public SpellScriptLoader
{
public:
    spell_pal_divine_intervention() : SpellScriptLoader("spell_pal_divine_intervention") { }

    class spell_pal_divine_intervention_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_divine_intervention_AuraScript);

    public:
        spell_pal_divine_intervention_AuraScript()
        {
            healPct = 0;
        }

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_INTERVENTION_HEAL))
                return false;
            return true;
        }

        bool Load() override
        {
            healPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
            return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
        {
            Unit* target = GetTarget();

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));

            if (!target->HasAura(SPELL_PALADIN_FORBEARANCE) && !target->GetSpellHistory()->HasCooldown(SPELL_PALADIN_DIVINE_SHIELD))
            {
                target->CastSpell(target, SPELL_PALADIN_DIVINE_SHIELD, true);
                target->CastCustomSpell(target, SPELL_PALADIN_DIVINE_INTERVENTION_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff);
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_divine_intervention_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_divine_intervention_AuraScript::Absorb, EFFECT_0);
        }

    private:
        uint32 healPct;

    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_divine_intervention_AuraScript();
    }
};

// Blinding Light - 115750
class spell_pal_blinding_light : public SpellScriptLoader
{
public:
    spell_pal_blinding_light() : SpellScriptLoader("spell_pal_blinding_light") { }

    class spell_pal_blinding_light_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_blinding_light_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                if (Unit* target = GetHitUnit())
                {
                    player->CastSpell(target, SPELL_PALADIN_BLINDING_LIGHT_CONFUSE, true);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_pal_blinding_light_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_blinding_light_SpellScript();
    }
};

// Cleanse - 4987 and Cleanse Toxins - 213644
class spell_pal_cleanse : public SpellScriptLoader
{
public:
    spell_pal_cleanse() : SpellScriptLoader("spell_pal_cleanse") { }

    class spell_pal_cleanse_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_cleanse_SpellScript);

        SpellCastResult CheckCleansing()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetExplTargetUnit())
                {
                    DispelChargesList dispelList[MAX_SPELL_EFFECTS];

                    // Create dispel mask by dispel type
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        uint32 dispel_type = GetSpellInfo()->GetEffect(i)->MiscValue;
                        uint32 dispelMask = GetSpellInfo()->GetDispelMask(DispelType(dispel_type));

                        // Cleanse can dispell all Magic, Disease and Poison
                        if (GetSpellInfo()->Id == 4987)
                            dispelMask = ((1 << DISPEL_MAGIC) | (1 << DISPEL_DISEASE) | (1 << DISPEL_POISON));

                        // Cleanse Toxins can dispell all Disease and Poison
                        if (GetSpellInfo()->Id == 213644)
                            dispelMask = ((1 << DISPEL_DISEASE) | (1 << DISPEL_POISON));

                        target->GetDispellableAuraList(caster, dispelMask, dispelList[i]);
                    }

                    bool empty = true;
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        if (dispelList[i].empty())
                            continue;

                        empty = false;
                        break;
                    }

                    if (empty)
                        return SPELL_FAILED_NOTHING_TO_DISPEL;

                    return SPELL_CAST_OK;
                }
            }
            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_pal_cleanse_SpellScript::CheckCleansing);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_cleanse_SpellScript();
    }
};

// Holy Shield - 152261
class spell_pal_holy_shield : public SpellScriptLoader
{
public:
    spell_pal_holy_shield() : SpellScriptLoader("spell_pal_holy_shield") { }

    class spell_pal_holy_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_holy_shield_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHitMask() & PROC_HIT_BLOCK)
                return true;

            return false;
        }

        void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            // Disable absorb (shitty blizzard)
            amount = 0;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_pal_holy_shield_AuraScript::CheckProc);
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_holy_shield_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_SCHOOL_ABSORB);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_holy_shield_AuraScript();
    }
};

// Light's Hammer - 122773
class spell_pal_lights_hammer : public SpellScriptLoader
{
public:
    spell_pal_lights_hammer() : SpellScriptLoader("spell_pal_lights_hammer") { }

    class spell_pal_lights_hammer_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_lights_hammer_SpellScript);

        void HandleAfterCast()
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Creature*> tempList;
                std::list<Creature*> LightsHammerlist;

                caster->GetCreatureListWithEntryInGrid(LightsHammerlist, NPC_PALADIN_LIGHTS_HAMMER, 200.0f);

                tempList = LightsHammerlist;

                for (std::list<Creature*>::iterator i = tempList.begin(); i != tempList.end(); ++i)
                {
                    Unit* owner = (*i)->GetOwner();
                    if (owner != nullptr && owner->GetGUID() == caster->GetGUID() && (*i)->IsSummon())
                        continue;

                    LightsHammerlist.remove((*i));
                }

                for (std::list<Creature*>::iterator itr = LightsHammerlist.begin(); itr != LightsHammerlist.end(); ++itr)
                    (*itr)->CastSpell((*itr), SPELL_PALADIN_LIGHTS_HAMMER_TICK, true);
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_pal_lights_hammer_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pal_lights_hammer_SpellScript();
    }
};

// Light's Hammer (Periodic Dummy) - 114918
class spell_pal_lights_hammer_tick : public SpellScriptLoader
{
public:
    spell_pal_lights_hammer_tick() : SpellScriptLoader("spell_pal_lights_hammer_tick") { }

    class spell_pal_lights_hammer_tick_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_lights_hammer_tick_AuraScript);

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->GetOwner())
                {
                    caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_PALADIN_ARCING_LIGHT_HEAL, true, 0, nullptr, caster->GetOwner()->GetGUID());
                    caster->CastSpell(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), SPELL_PALADIN_ARCING_LIGHT_DAMAGE, true, 0, nullptr, caster->GetOwner()->GetGUID());
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_lights_hammer_tick_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_lights_hammer_tick_AuraScript();
    }
};

// 31850 - ardent defender
class spell_pal_ardent_defender : public AuraScript
{
    PrepareAuraScript(spell_pal_ardent_defender);

public:
    spell_pal_ardent_defender()
    {
        absorbPct   = 0;
        healPct     = 0;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ARDENT_DEFENDER });
    }

    bool Load() override
    {
        absorbPct   = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
        healPct     = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
        return GetUnitOwner()->IsPlayer();
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);

        Unit* target = GetTarget();
        if (dmgInfo.GetDamage() < target->GetHealth())
            return;

        int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));
        target->CastCustomSpell(target, SPELL_PALADIN_ARDENT_DEFENDER_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff);
        aurEff->GetBase()->Remove();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_ardent_defender::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_ardent_defender::Absorb, EFFECT_0);
    }

private:
    uint32 absorbPct;
    uint32 healPct;
};

// 231895
class spell_pal_crusade : public AuraScript
{
    PrepareAuraScript(spell_pal_crusade);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount /= 10;
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        auto powerCosts = eventInfo.GetSpellInfo()->CalcPowerCost(eventInfo.GetActor(), SPELL_SCHOOL_MASK_HOLY);

        for (auto powerCost : powerCosts)
            if (powerCost.Power == POWER_HOLY_POWER)
                GetAura()->ModStackAmount(powerCost.Amount, AURA_REMOVE_BY_DEFAULT, false, false);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_crusade::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_crusade::CalculateAmount, EFFECT_2, SPELL_AURA_MELEE_SLOW);
        OnEffectProc += AuraEffectProcFn(spell_pal_crusade::OnProc, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
    }
};

// Light's Hammer
// NPC Id - 59738
class npc_pal_lights_hammer : public ScriptedAI
{
public:

    npc_pal_lights_hammer(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->CastSpell(me, SPELL_PALADIN_LIGHT_HAMMER_COSMETIC, true);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_REMOVE_CLIENT_CONTROL);
    }
};

// Consecration - 26573 (retribution)
// Consecration - 205228 (protection)
class spell_pal_consecration : public AuraScript
{
    PrepareAuraScript(spell_pal_consecration);

    void OnTick(AuraEffect const* /*auraEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            std::vector<AreaTrigger*> ATList = caster->GetAreaTriggers(GetSpellInfo()->Id);
            for (AreaTrigger* at : ATList)
            {
                caster->CastSpell(at->GetPosition(), SPELL_PALADIN_CONSECRATION_DAMAGE, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_consecration::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Aura of Sacrifice - 183416
// AreaTriggerID - 100102 (custom)
struct at_pal_aura_of_sacrifice : AreaTriggerAI
{
    at_pal_aura_of_sacrifice(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    {
        at->SetPeriodicProcTimer(1000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (unit->IsPlayer() && caster->IsPlayer() && caster != unit)
                if (caster->ToPlayer()->IsInSameRaidWith(unit->ToPlayer()))
                    caster->CastSpell(unit, SPELL_PALADIN_AURA_OF_SACRIFICE_ALLY, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_PALADIN_AURA_OF_SACRIFICE_ALLY);
    }
};

// 210372
class spell_pal_aura_of_sacrifice_ally : public AuraScript
{
    PrepareAuraScript(spell_pal_aura_of_sacrifice_ally);

    bool Load() override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_AURA_OF_SACRIFICE });
    }

    void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void OnAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* caster = GetCaster();
        SpellInfo const* auraOfSacrificeInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_AURA_OF_SACRIFICE);

        if (!caster || !caster->IsValidAssistTarget(GetTarget()) ||
            caster->GetHealthPct() < auraOfSacrificeInfo->GetEffect(EFFECT_2)->BasePoints)
        {
            absorbAmount = 0;
            return;
        }

        absorbAmount = CalculatePct(dmgInfo.GetDamage(), auraOfSacrificeInfo->GetEffect(EFFECT_0)->BasePoints);

        // Deal damages to the paladin
        GetTarget()->CastCustomSpell(SPELL_PALADIN_AURA_OF_SACRIFICE_DAMAGE, SPELLVALUE_BASE_POINT0, absorbAmount, caster, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_aura_of_sacrifice_ally::CalcAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_aura_of_sacrifice_ally::OnAbsorb, EFFECT_0);
    }
};

void AddSC_paladin_spell_scripts()
{
    new spell_pal_bastion_of_light();
    new spell_pal_blinding_light();
    //new spell_pal_cleanse();
    new spell_pal_divine_intervention();
    new spell_pal_hand_of_sacrifice();
    new spell_pal_holy_prism();
    new spell_pal_holy_prism_effect();
    new spell_pal_holy_prism_visual();
    new spell_pal_holy_shield();
    new spell_pal_judgement_of_the_pure();
    new spell_pal_lights_hammer();
    new spell_pal_lights_hammer_tick();
    new spell_pal_light_of_dawn();
    new spell_pal_light_of_dawn_trigger();
    new spell_pal_light_of_the_martyr();
    new spell_pal_greater_blessing_of_kings();
    new spell_pal_zeal();
    
    //7.3.2.25549
    RegisterSpellScript(spell_pal_holy_shock);
    RegisterSpellScript(spell_pal_divine_hammer);
    RegisterSpellScript(spell_pal_execute_sentence);
    RegisterSpellScript(spell_pal_templar_s_verdict);
    RegisterSpellScript(spell_pal_seraphim);
    RegisterSpellScript(spell_pal_divine_storm);
    RegisterSpellScript(spell_pal_divine_steed);
    RegisterSpellScript(spell_pal_divine_shield);
    RegisterSpellScript(spell_pal_activate_forbearance);
    RegisterSpellScript(spell_pal_word_of_glory);
    RegisterSpellScript(spell_pal_justicars_vengeance);
    RegisterSpellScript(spell_pal_judgment);
    RegisterSpellScript(spell_pal_divine_purpose_proc);
    RegisterSpellScript(spell_pal_holy_wrath);
    RegisterSpellScript(spell_pal_grand_crusader);
    RegisterSpellScript(spell_pal_avengers_shield);
    RegisterSpellScript(spell_pal_shield_of_the_righteous);
    RegisterSpellScript(spell_pal_light_of_the_protector);
    RegisterSpellScript(spell_pal_flash_of_light);
    RegisterSpellScript(spell_pal_crusader_strike);
    RegisterSpellScript(spell_pal_beacon_of_faith);
    RegisterSpellScript(spell_pal_beacon_of_light);
    RegisterSpellScript(spell_pal_beacon_of_virtue);
    
    RegisterAuraScript(spell_pal_beacon_of_light_aura);
    RegisterAuraScript(spell_pal_beacon_of_light_proc);
    RegisterAuraScript(spell_pal_judgment_of_light);
    RegisterAuraScript(spell_pal_judgment_of_light_proc);
    RegisterAuraScript(spell_pal_infusion_of_light);
    RegisterAuraScript(spell_pal_eye_for_an_eye);
    RegisterAuraScript(spell_pal_shield_of_vengeance);
    RegisterAuraScript(spell_pal_blade_of_wrath_proc);
    RegisterAuraScript(spell_pal_the_fire_of_justice);
    RegisterAuraScript(spell_pal_ardent_defender);
    RegisterCastSpellOnProcAuraScript("spell_pal_fervent_martyr", EFFECT_0, SPELL_AURA_DUMMY, SPELL_PALADIN_FERVENT_MARTYR_BUFF); // 196923
    RegisterAuraScript(spell_pal_crusade);
    RegisterAuraScript(spell_pal_consecration);
    RegisterAuraScript(spell_pal_aura_of_sacrifice_ally);

    // NPC Scripts
    RegisterCreatureAI(npc_pal_lights_hammer);

    // Area Trigger scripts
    RegisterAreaTriggerAI(at_pal_aura_of_sacrifice);
}
