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
 * Scripts for spells with SPELLFAMILY_WARRIOR and SPELLFAMILY_GENERIC spells used by warrior players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warr_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "GridNotifiersImpl.h"

enum WarriorSpells
{
    SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND     = 50622,
    SPELL_WARRIOR_BLOODTHIRST                       = 23885,
    SPELL_WARRIOR_BLOODTHIRST_DAMAGE                = 23881,
    SPELL_WARRIOR_BLOODSURGE                        = 46916,
    SPELL_WARRIOR_BLOODSURGE_R1                     = 46913,
    SPELL_WARRIOR_CHARGE_ENERGIZE                   = 34846,
    SPELL_WARRIOR_CHARGE_STUN                       = 7922,
    SPELL_WARRIOR_COLOSSUS_SMASH                    = 86346,
    SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC              = 12721,
    SPELL_WARRIOR_EXECUTE                           = 20647,
    SPELL_WARRIOR_GLYPH_OF_EXECUTION                = 58367,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF        = 65156,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT      = 64976,
    SPELL_WARRIOR_LAST_STAND_TRIGGERED              = 12976,
    SPELL_WARRIOR_MORTAL_STRIKE                     = 12294,
    SPELL_WARRIOR_OPPORTUNITY_STRIKE                = 76858,
    SPELL_WARRIOR_RALLYING_CRY                      = 97463,
    SPELL_WARRIOR_REND                              = 94009,
    SPELL_WARRIOR_RETALIATION_DAMAGE                = 22858,
    SPELL_WARRIOR_SECOND_WIND_PROC_RANK_1           = 29834,
    SPELL_WARRIOR_SECOND_WIND_PROC_RANK_2           = 29838,
    SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_1        = 29841,
    SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_2        = 29842,
    SPELL_WARRIOR_SHIELD_SLAM                       = 23922,
    SPELL_WARRIOR_SLAM_MAIN_HAND                    = 50782,
    SPELL_WARRIOR_SLAM_OFF_HAND                     = 97992,
    SPELL_WARRIOR_SUNDER_ARMOR                      = 58567,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1   = 12723,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2   = 26654,
    SPELL_WARRIOR_TAUNT                             = 355,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_1        = 46859,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_2        = 46860,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_1     = 64849,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_2     = 64850,
    SPELL_WARRIOR_VICTORIOUS                        = 32216,
    SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY      = 82368,
    SPELL_WARRIOR_VIGILANCE_PROC                    = 50725,
    SPELL_WARRIOR_VENGEANCE                         = 76691
};

enum WarriorSpellIcons
{
    WARRIOR_ICON_ID_GLYPH_OF_COLOSSUS_SMASH         = 5288,
    WARRIOR_ICON_ID_SUDDEN_DEATH                    = 1989,
    WARRIOR_ICON_ID_BLOOD_AND_THUNDER               = 5057,
    WARRIOR_ICON_ID_SINGLE_MINDED_FURY              = 4975
};


enum MiscSpells
{
    SPELL_PALADIN_BLESSING_OF_SANCTUARY             = 20911,
    SPELL_PALADIN_GREATER_BLESSING_OF_SANCTUARY     = 25899,
    SPELL_PRIEST_RENEWED_HOPE                       = 63944
};

/// Updated 4.3.4
// 23881 - Bloodthirst
class spell_warr_bloodthirst : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_BLOODTHIRST });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            SetEffectValue(CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK) * GetEffectValue(), 1));
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetEffectValue();
        GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_BLOODTHIRST, { SPELLVALUE_BASE_POINT0, damage });
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_bloodthirst::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHit.Register(&spell_warr_bloodthirst::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

/// Updated 4.3.4
// 23880 - Bloodthirst
class spell_warr_bloodthirst_heal : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_BLOODTHIRST_DAMAGE });
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_BLOODTHIRST_DAMAGE);
        SetHitHeal(GetCaster()->CountPctFromMaxHealth(spellInfo->Effects[EFFECT_1].CalcValue(GetCaster())) / 100);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_bloodthirst_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

/// Updated 4.3.4
class spell_warr_charge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT,
                SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF,
                SPELL_WARRIOR_CHARGE_ENERGIZE,
                SPELL_WARRIOR_CHARGE_STUN
            });
    }

    void HandleStun(SpellEffIndex /*effIdex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_WARRIOR_CHARGE_STUN, true);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_WARRIOR_CHARGE_ENERGIZE, { SPELLVALUE_BASE_POINT0, GetEffectValue() });

        // Juggernaut crit bonus
        if (caster->HasAura(SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT))
            caster->CastSpell(caster, SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_charge::HandleStun, EFFECT_0, SPELL_EFFECT_CHARGE);
        OnEffectHitTarget.Register(&spell_warr_charge::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

/// Updated 4.3.4
class spell_warr_concussion_blow : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        SetEffectValue(CalculatePct(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetSpellInfo()->Effects[EFFECT_2].CalcValue()));
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_concussion_blow::HandleDummy, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 86346 - Colossus Smash
class spell_warr_colossus_smash : public SpellScript
{
    void HandleGlyphEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_WARRIOR, WARRIOR_ICON_ID_GLYPH_OF_COLOSSUS_SMASH, EFFECT_0))
                caster->CastSpell(GetHitUnit(), SPELL_WARRIOR_SUNDER_ARMOR, aurEff);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_colossus_smash::HandleGlyphEffect, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
    }
};

// Updated 4.3.4
// -12834 - Deep Wounds
class spell_warr_deep_wounds : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (Player* player = GetTarget()->ToPlayer())
        {
            int32 damage = player->CalculateDamage(BASE_ATTACK, true, false);
            damage = CalculatePct(damage, 16 * GetSpellInfo()->GetRank());

            if (damage)
                if (SpellInfo const* periodicSpell = sSpellMgr->GetSpellInfo(SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC))
                    if (uint32 ticks = periodicSpell->GetMaxTicks())
                        damage = damage / ticks;

            if (Unit* target = eventInfo.GetProcTarget())
                player->CastSpell(target, SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC, CastSpellExtraArgs(aurEff).AddSpellBP0(damage));
        }
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_warr_deep_wounds::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

/// Updated 4.3.4
class spell_warr_execute : public SpellScript
{
    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (GetHitUnit())
        {
            SpellInfo const* spellInfo = GetSpellInfo();
            int32 rageUsed = std::min<int32>(200 - spellInfo->CalcPowerCost(caster, SpellSchoolMask(spellInfo->SchoolMask)), caster->GetPower(POWER_RAGE));
            int32 newRage = std::max<int32>(0, caster->GetPower(POWER_RAGE) - rageUsed);

            // Sudden Death rage save
            if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_GENERIC, WARRIOR_ICON_ID_SUDDEN_DEATH, EFFECT_0))
            {
                int32 ragesave = aurEff->GetSpellInfo()->Effects[EFFECT_0].CalcValue() * 10;
                newRage = std::max(newRage, ragesave);
            }

            caster->SetPower(POWER_RAGE, uint32(newRage));

            /// Formula taken from the DBC: "${10+$AP*0.437*$m1/100}"
            int32 baseDamage = int32(10 + caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.437f * GetEffectValue() / 100.0f);
            /// Formula taken from the DBC: "${$ap*0.874*$m1/100-1} = 20 rage"
            int32 moreDamage = int32(rageUsed * (caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.874f * GetEffectValue() / 100.0f - 1) / 200);
            SetEffectValue(baseDamage + moreDamage);
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_execute::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 58387 - Glyph of Sunder Armor
class spell_warr_glyph_of_sunder_armor : public AuraScript
{
    void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
    {
        if (!spellMod)
        {
            spellMod = new SpellModifier(aurEff->GetBase());
            spellMod->op = SpellModOp(aurEff->GetMiscValue());
            spellMod->type = SPELLMOD_FLAT;
            spellMod->spellId = GetId();
            spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
        }

        spellMod->value = aurEff->GetAmount();
    }

    void Register() override
    {
        DoEffectCalcSpellMod.Register(&spell_warr_glyph_of_sunder_armor::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 5246 - Intimidating Shout
class spell_warr_intimidating_shout : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove(GetExplTargetWorldObject());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_warr_intimidating_shout::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_warr_intimidating_shout::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// -84583 Lambs to the Slaughter
class spell_warr_lambs_to_the_slaughter : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_MORTAL_STRIKE, SPELL_WARRIOR_REND });
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (Aura* aur = eventInfo.GetProcTarget()->GetAura(SPELL_WARRIOR_REND, GetTarget()->GetGUID()))
            aur->SetDuration(aur->GetSpellInfo()->GetMaxDuration(), true);

    }

    void Register() override
    {
        OnEffectProc.Register(&spell_warr_lambs_to_the_slaughter::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

/// Updated 4.3.4
// 12975 - Last Stand
class spell_warr_last_stand : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_LAST_STAND_TRIGGERED });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        int32 healthModSpellBasePoints0 = int32(caster->CountPctFromMaxHealth(GetEffectValue()));
        caster->CastSpell(caster, SPELL_WARRIOR_LAST_STAND_TRIGGERED, { SPELLVALUE_BASE_POINT0, healthModSpellBasePoints0 });
    }

    void Register() override
    {
        // add dummy effect spell handler to Last Stand
        OnEffectHit.Register(&spell_warr_last_stand::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 7384 - Overpower
class spell_warr_overpower : public SpellScript
{
    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        uint32 spellId = 0;
        if (GetCaster()->HasAura(SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_1))
            spellId = SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_1;
        else if (GetCaster()->HasAura(SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_2))
            spellId = SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_2;

        if (!spellId)
            return;

        if (Player* target = GetHitPlayer())
            if (target->IsNonMeleeSpellCast(false, false, true)) // UNIT_STATE_CASTING should not be used here, it's present during a tick for instant casts
                target->CastSpell(target, spellId, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_overpower::HandleEffect, EFFECT_0, SPELL_EFFECT_ANY);
    }
};

// 97462 - Rallying Cry
class spell_warr_rallying_cry : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_RALLYING_CRY });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        int32 basePoints0 = int32(GetHitUnit()->CountPctFromMaxHealth(GetEffectValue()));
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_RALLYING_CRY, { SPELLVALUE_BASE_POINT0, basePoints0 });
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_rallying_cry::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 94009 - Rend
class spell_warr_rend : public AuraScript
{
    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        if (Unit* caster = GetCaster())
        {
            canBeRecalculated = false;

            // $0.25 * (($MWB + $mwb) / 2 + $AP / 14 * $MWS) bonus per tick
            float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
            int32 mws = caster->GetAttackTime(BASE_ATTACK);
            float mwbMin = caster->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE);
            float mwbMax = caster->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE);
            float mwb = ((mwbMin + mwbMax) / 2 + ap * mws / 14000) * 0.25f;
            amount += int32(caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), mwb));
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_warr_rend::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 20230 - Retaliation
class spell_warr_retaliation : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_RETALIATION_DAMAGE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // check attack comes not from behind and warrior is not stunned
        return GetTarget()->isInFront(eventInfo.GetActor(), float(M_PI)) && !GetTarget()->HasUnitState(UNIT_STATE_STUNNED);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARRIOR_RETALIATION_DAMAGE, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_warr_retaliation::CheckProc);
        OnEffectProc.Register(&spell_warr_retaliation::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 64380, 65941 - Shattering Throw
class spell_warr_shattering_throw : public SpellScript
{
    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        // remove shields, will still display immune to damage part
        if (Unit* target = GetHitUnit())
            target->RemoveAurasWithMechanic(1 << MECHANIC_IMMUNE_SHIELD, AuraRemoveFlags::ByEnemySpell);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_shattering_throw::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/// Updated 4.3.4
class spell_warr_slam : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARRIOR_SLAM_MAIN_HAND,
                SPELL_WARRIOR_SLAM_OFF_HAND,
                SPELL_WARRIOR_BLOODSURGE,
                SPELL_WARRIOR_BLOODSURGE_R1
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        caster->CastSpell(target, SPELL_WARRIOR_SLAM_MAIN_HAND, true);

        if (caster->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_WARRIOR, WARRIOR_ICON_ID_SINGLE_MINDED_FURY, EFFECT_0))
            caster->CastSpell(target, SPELL_WARRIOR_SLAM_OFF_HAND, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_slam::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_warr_slam_triggered : public SpellScript
{
    bool Load() override
    {
        _bloodsurgeBonusActive = GetCaster()->HasAura(SPELL_WARRIOR_BLOODSURGE, GetCaster()->GetGUID());
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARRIOR_BLOODSURGE,
                SPELL_WARRIOR_BLOODSURGE_R1
            });
    }

    void HandleBonusDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 basePoints = GetEffectValue();
        if (_bloodsurgeBonusActive)
            if (Aura const* aura = caster->GetAuraOfRankedSpell(SPELL_WARRIOR_BLOODSURGE_R1))
                if (AuraEffect const* effect = aura->GetEffect(EFFECT_0))
                    AddPct(basePoints, effect->GetAmount());

        SetEffectValue(basePoints);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_slam_triggered::HandleBonusDamage, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
private:
    bool _bloodsurgeBonusActive = false;
};

class spell_warr_second_wind_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARRIOR_SECOND_WIND_PROC_RANK_1,
                SPELL_WARRIOR_SECOND_WIND_PROC_RANK_2,
                SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_1,
                SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_2
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetProcTarget() == GetTarget())
            return false;
        if (!eventInfo.GetDamageInfo()->GetSpellInfo() || !(eventInfo.GetDamageInfo()->GetSpellInfo()->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_STUN))))
            return false;
        return true;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        uint32 spellId = 0;

        if (GetSpellInfo()->Id == SPELL_WARRIOR_SECOND_WIND_PROC_RANK_1)
            spellId = SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_1;
        else if (GetSpellInfo()->Id == SPELL_WARRIOR_SECOND_WIND_PROC_RANK_2)
            spellId = SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_2;
        if (!spellId)
            return;

        GetTarget()->CastSpell(GetTarget(), spellId, aurEff);

    }

    void Register() override
    {
        DoCheckProc.Register(&spell_warr_second_wind_proc::CheckProc);
        OnEffectProc.Register(&spell_warr_second_wind_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_warr_second_wind_trigger : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = int32(GetUnitOwner()->CountPctFromMaxHealth(amount));
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_warr_second_wind_trigger::CalculateAmount, EFFECT_1, SPELL_AURA_PERIODIC_HEAL);
    }
};

// 52437 - Sudden Death
class spell_warr_sudden_death : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_COLOSSUS_SMASH });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Remove cooldown on Colossus Smash
        if (Player* player = GetTarget()->ToPlayer())
            player->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_COLOSSUS_SMASH, true);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_warr_sudden_death::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 12328, 18765, 35429 - Sweeping Strikes
class spell_warr_sweeping_strikes : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1,
                SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        _procTarget = eventInfo.GetActor()->SelectNearbyTarget(eventInfo.GetProcTarget());
        return _procTarget != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (eventInfo.GetDamageInfo())
        {
            SpellInfo const* spellInfo = eventInfo.GetDamageInfo()->GetSpellInfo();
            if (spellInfo && (spellInfo->Id == SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND || (spellInfo->Id == SPELL_WARRIOR_EXECUTE && !_procTarget->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))))
            {
                // If triggered by Execute (while target is not under 20% hp) or Bladestorm deals normalized weapon damage
                GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2, aurEff);
            }
            else
            {
                int32 damage = eventInfo.GetDamageInfo()->GetDamage();
                GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1, CastSpellExtraArgs(aurEff).AddSpellBP0(damage));
            }
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_warr_sweeping_strikes::CheckProc);
        OnEffectProc.Register(&spell_warr_sweeping_strikes::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
private:
    Unit* _procTarget = nullptr;
};

// -46951 - Sword and Board
class spell_warr_sword_and_board : public AuraScript
{private:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_SLAM });
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        // Remove cooldown on Shield Slam
        if (Player* player = GetTarget()->ToPlayer())
            player->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_SHIELD_SLAM, true);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_warr_sword_and_board::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 34428 - Victory Rush
class spell_warr_victory_rush : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARRIOR_VICTORIOUS,
                SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY
            });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        SetEffectValue(CalculatePct(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetSpellInfo()->Effects[EFFECT_0].CalcValue()));
    }

    void HandleImpendingVictoryHeal(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
        {
            // Impending Victory also allows players to cast Victory Rush but with 5% healing effect only
            if (caster->HasAura(SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY))
            {
                int32 damage = 5;

                // Glyph: Victory Rush
                if (Player* modOwner = caster->GetSpellModOwner())
                    modOwner->ApplySpellMod(m_scriptSpellId, SPELLMOD_EFFECT3, damage);

                SetEffectValue(damage);
            }
            else
                SetEffectValue(GetSpellInfo()->Effects[effIndex].CalcValue());

            caster->RemoveAurasDueToSpell(SPELL_WARRIOR_VICTORIOUS);
            caster->RemoveAurasDueToSpell(SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY);
        }
    }


    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_victory_rush::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget.Register(&spell_warr_victory_rush::HandleImpendingVictoryHeal, EFFECT_2, SPELL_EFFECT_HEAL_PCT);
    }
};

// 50720 - Vigilance
class spell_warr_vigilance : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_VENGEANCE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        _procTarget = GetCaster();
        return _procTarget && eventInfo.GetDamageInfo();
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 damage = std::min(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue()), CalculatePct(_procTarget->GetMaxHealth(), 10));

        GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_VIGILANCE_PROC, aurEff);
        _procTarget->CastSpell(_procTarget, SPELL_WARRIOR_VENGEANCE, CastSpellExtraArgs(aurEff).AddSpellBP0(damage).AddSpellMod(SPELLVALUE_BASE_POINT1, damage).AddSpellMod(SPELLVALUE_BASE_POINT2, damage));
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->HasAura(SPELL_WARRIOR_VENGEANCE))
                caster->RemoveAurasDueToSpell(SPELL_WARRIOR_VENGEANCE);
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_warr_vigilance::CheckProc);
        OnEffectProc.Register(&spell_warr_vigilance::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        OnEffectRemove.Register(&spell_warr_vigilance::HandleRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
private:
    Unit* _procTarget = nullptr;
};

// 50725 Vigilance
class spell_warr_vigilance_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_TAUNT });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        // Remove Taunt cooldown
        if (Player* target = GetHitPlayer())
            target->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_TAUNT, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_vigilance_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 76838 - Strikes of Opportunity
class spell_warr_strikes_of_opportunity : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_OPPORTUNITY_STRIKE });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (Unit* caster = GetCaster())
            if (Unit* target = eventInfo.GetActionTarget())
                caster->CastSpell(target, SPELL_WARRIOR_OPPORTUNITY_STRIKE, aurEff);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_warr_strikes_of_opportunity::CheckProc);
        OnEffectProc.Register(&spell_warr_strikes_of_opportunity::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_warr_thunder_clap : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_REND });
    }

    bool Load() override
    {
        _allowRendSpread = false;
        if (AuraEffect* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_WARRIOR, WARRIOR_ICON_ID_BLOOD_AND_THUNDER, EFFECT_0))
            return roll_chance_i(aurEff->GetAmount());

        return false;
    }

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        for (std::list<WorldObject*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            if (Unit* target = (*itr)->ToUnit())
                if (target->HasAura(SPELL_WARRIOR_REND))
                    _allowRendSpread = true;
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (_allowRendSpread)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_REND, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_warr_thunder_clap::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_warr_thunder_clap::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }

private:
    bool _allowRendSpread;
};

class spell_warr_shield_specialization : public AuraScript
{
    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetHitMask() & PROC_HIT_REFLECT)
        {
            PreventDefaultAction();
            Unit* target = GetTarget();
            if (SpellInfo const* spell = sSpellMgr->GetSpellInfo((GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell)))
            {
                int32 bp = spell->Effects[EFFECT_0].CalcValue() * 4;
                target->CastSpell(nullptr, spell->Id, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
            }
        }
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_warr_shield_specialization::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_warr_blood_craze : public AuraScript
{
    void HandleCalcAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
    {
        int32 bp = GetSpellInfo()->Effects[EFFECT_0].BasePoints / 2;
        uint8 totalTicks = aurEff->GetTotalTicks();
        amount = CalculatePct(GetUnitOwner()->GetMaxHealth(), (float)bp / totalTicks);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_warr_blood_craze::HandleCalcAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

// 46968 - Shockwave
class spell_warr_shockwave : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        SetEffectValue(CalculatePct(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetSpellInfo()->Effects[EFFECT_2].CalcValue()));
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_shockwave::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_warr_devastate : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SUNDER_ARMOR });
    }

    void HandleDamageBonus(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (Aura* sunder = GetHitUnit()->GetAura(SPELL_WARRIOR_SUNDER_ARMOR, caster->GetGUID()))
                SetEffectValue(GetEffectValue() + GetEffectValue() * sunder->GetStackAmount());
    }

    void HandleSunderArmor(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_WARRIOR_SUNDER_ARMOR, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_warr_devastate::HandleDamageBonus, EFFECT_1, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        OnEffectHitTarget.Register(&spell_warr_devastate::HandleSunderArmor, EFFECT_1, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
    }
};

class spell_warr_whirlwind : public SpellScript
{
    void CountTargets(SpellEffIndex /*effIndex*/)
    {
        _hitTargets++;
    }

    void HandleCooldownReduction()
    {
        Unit* caster = GetCaster();
        if (!caster || _hitTargets < 4)
            return;

        caster->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, ((GetSpellInfo()->Effects[EFFECT_2].CalcValue(caster) * IN_MILLISECONDS) * -1));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_warr_whirlwind::CountTargets, EFFECT_0, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        AfterCast.Register(&spell_warr_whirlwind::HandleCooldownReduction);
    }
private:
    uint8 _hitTargets = 0;
};

class spell_warr_heroic_leap : public SpellScript
{
    SpellCastResult CheckLocation()
    {
        // The client shows an area as unreachable once the target destination is 4 yards above your position
        if (!GetExplTargetDest() || GetExplTargetDest()->GetPositionZ() - GetCaster()->GetPositionZ() > 4.f)
            return SPELL_FAILED_NOPATH;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_warr_heroic_leap::CheckLocation);
    }
};

void AddSC_warrior_spell_scripts()
{
    RegisterSpellScript(spell_warr_blood_craze);
    RegisterSpellScript(spell_warr_bloodthirst);
    RegisterSpellScript(spell_warr_bloodthirst_heal);
    RegisterSpellScript(spell_warr_charge);
    RegisterSpellScript(spell_warr_colossus_smash);
    RegisterSpellScript(spell_warr_concussion_blow);
    RegisterSpellScript(spell_warr_deep_wounds);
    RegisterSpellScript(spell_warr_devastate);
    RegisterSpellScript(spell_warr_execute);
    RegisterSpellScript(spell_warr_glyph_of_sunder_armor);
    RegisterSpellScript(spell_warr_heroic_leap);
    RegisterSpellScript(spell_warr_intimidating_shout);
    RegisterSpellScript(spell_warr_lambs_to_the_slaughter);
    RegisterSpellScript(spell_warr_last_stand);
    RegisterSpellScript(spell_warr_overpower);
    RegisterSpellScript(spell_warr_rallying_cry);
    RegisterSpellScript(spell_warr_rend);
    RegisterSpellScript(spell_warr_retaliation);
    RegisterSpellScript(spell_warr_second_wind_proc);
    RegisterSpellScript(spell_warr_second_wind_trigger);
    RegisterSpellScript(spell_warr_shattering_throw);
    RegisterSpellScript(spell_warr_shield_specialization);
    RegisterSpellScript(spell_warr_shockwave);
    RegisterSpellScript(spell_warr_slam);
    RegisterSpellScript(spell_warr_slam_triggered);
    RegisterSpellScript(spell_warr_strikes_of_opportunity);
    RegisterSpellScript(spell_warr_sudden_death);
    RegisterSpellScript(spell_warr_sweeping_strikes);
    RegisterSpellScript(spell_warr_sword_and_board);
    RegisterSpellScript(spell_warr_thunder_clap);
    RegisterSpellScript(spell_warr_victory_rush);
    RegisterSpellScript(spell_warr_vigilance);
    RegisterSpellScript(spell_warr_vigilance_trigger);
    RegisterSpellScript(spell_warr_whirlwind);
}
