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
  * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
  * Ordered alphabetically using scriptname.
  * Scriptnames of files in this file should be prefixed with "spell_dk_".
  */

#include "ScriptMgr.h"
#include "Containers.h"
#include "Creature.h"
#include "GridNotifiers.h"
#include "Pet.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DeathKnightSpells
{
    SPELL_DK_ANTI_MAGIC_SHELL_TALENT            = 51052,
    SPELL_DK_BLOOD_BOIL_TRIGGERED               = 65658,
    SPELL_DK_BLOOD_BURST                        = 81280,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_BLOOD_PRESENCE                     = 48263,
    SPELL_DK_BLOOD_PRESENCE_TRIGGERED           = 61261,
    SPELL_DK_BLOOD_SHIELD_MASTERY               = 77513,
    SPELL_DK_BLOOD_SHIELD_ABSORB                = 77535,
    SPELL_DK_BLOOD_STRIKE                       = 45902,
    SPELL_DK_BLOOD_STRIKE_OFFHAND               = 66215,
    SPELL_DK_BLOOD_TAP                          = 45529,
    SPELL_DK_BUTCHERY                           = 50163,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_DARK_TRANSFORMATION                = 63560,
    SPELL_DK_DARK_TRANSFORMATION_DUMMY          = 93426,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_COIL                         = 47541,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633,
    SPELL_DK_DEATH_EATER                        = 90507,
    SPELL_DK_DEATH_GRIP                         = 49560,
    SPELL_DK_DEATH_GRIP_INITIAL                 = 49576,
    SPELL_DK_DEATH_STRIKE                       = 49998,
    SPELL_DK_DEATH_STRIKE_OFFHAND               = 66188,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_DEATH_STRIKE_ENABLER               = 89832,
    SPELL_DK_EBON_PLAGUE                        = 65142,
    SPELL_DK_ENERGIZE_BLOOD_RUNE                = 81166,
    SPELL_DK_ENERGIZE_FROST_RUNE                = 81168,
    SPELL_DK_ENERGIZE_UNHOLY_RUNE               = 81169,
    SPELL_DK_FLAMING_TORRENT                    = 99000,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_FROST_PRESENCE                     = 48266,
    SPELL_DK_FROST_STRIKE                       = 49143,
    SPELL_DK_FROST_STRIKE_OFFHAND               = 66196,
    SPELL_DK_GHOUL_EXPLODE                      = 47496,
    SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE        = 58625,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1         = 50365,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE            = 63611,
    SPELL_DK_IMPROVED_DEATH_STRIKE              = 62905,
    SPELL_DK_IMPROVED_FROST_PRESENCE            = 63621,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE           = 63622,
    SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART          = 64962,
    SPELL_DK_ITEM_T8_MELEE_4P_BONUS             = 64736,
    SPELL_DK_ITEM_T11_DPS_4P_BONUS              = 90459,
    SPELL_DK_MASTER_OF_GHOULS                   = 52143,
    SPELL_DK_OBLITERATE                         = 49020,
    SPELL_DK_OBLITERATE_OFFHAND                 = 66198,
    SPELL_DK_PLAGUE_STRIKE                      = 45462,
    SPELL_DK_PLAGUE_STRIKE_OFFHAND              = 66216,
    SPELL_DK_RESILIENT_INFECTION                = 90721,
    SPELL_DK_RUNIC_CORRUPTION_TRIGGERED         = 51460,
    SPELL_DK_RUNE_STRIKE                        = 56815,
    SPELL_DK_RUNE_STRIKE_OFFHAND                = 66217,
    SPELL_DK_RUNE_TAP                           = 48982,
    SPELL_DK_SCENT_OF_BLOOD                     = 50422,
    SPELL_DK_SCOURGE_STRIKE_TRIGGERED           = 70890,
    SPELL_DK_SHADOW_INFUSION                    = 91342,
    SPELL_DK_SMOLDERING_RUNE_ENERGIZE           = 99055,
    SPELL_DK_UNHOLY_BLIGHT_PERIODIC             = 50536,
    SPELL_DK_UNHOLY_PRESENCE                    = 48265,
    SPELL_DK_PESTILENCE_REDUCED_DOTS            = 76243,
    SPELL_DK_PESTILENCE_VISUAL                  = 91939,
    SPELL_DK_WILL_OF_THE_NECROPOLIS             = 96171
};

enum DKSpellIcons
{
    DK_ICON_ID_RUNIC_CORRUPTION                 = 4068,
    DK_ICON_ID_RESILIENT_INFECTION              = 1910,
    DK_ICON_ID_IMPROVED_UNHOLY_PRESENCE         = 2633,
    DK_ICON_ID_IMPROVED_FROST_PRESENCE          = 2632
};

// 48707 - Anti-Magic Shell (on self)
class spell_dk_anti_magic_shell : public AuraScript
{
    bool Load() override
    {
        absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
        healthPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        amount = GetCaster()->CountPctFromMaxHealth(healthPct);
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        absorbAmount = std::min(CalculatePct(dmgInfo.GetDamage(), absorbPct), GetTarget()->CountPctFromMaxHealth(healthPct));
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_anti_magic_shell::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb.Register(&spell_dk_anti_magic_shell::Absorb, EFFECT_0);
    }
private:
    int32 absorbPct;
    int32 healthPct;
};

// 50461 - Anti-Magic Zone
class spell_dk_anti_magic_zone : public AuraScript
{
    bool Load() override
    {
        absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_ANTI_MAGIC_SHELL_TALENT });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        SpellInfo const* talentSpell = sSpellMgr->AssertSpellInfo(SPELL_DK_ANTI_MAGIC_SHELL_TALENT);
        amount = talentSpell->Effects[EFFECT_0].CalcValue(GetCaster());
        if (Player* player = GetCaster()->ToPlayer())
            amount += int32(2 * player->GetTotalAttackPowerValue(BASE_ATTACK));
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_anti_magic_zone::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb.Register(&spell_dk_anti_magic_zone::Absorb, EFFECT_0);
    }
private:
    uint32 absorbPct = 0;
};

// 48721 - Blood Boil
class spell_dk_blood_boil : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BLOOD_BOIL_TRIGGERED });
    }

    bool Load() override
    {
        _executed = false;
        return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCaster()->getClass() == CLASS_DEATH_KNIGHT;
    }

    void HandleAfterHit()
    {
        if (_executed || !GetHitUnit())
            return;

        _executed = true;
        GetCaster()->CastSpell(GetCaster(), SPELL_DK_BLOOD_BOIL_TRIGGERED, true);
    }

    void Register() override
    {
        AfterHit.Register(&spell_dk_blood_boil::HandleAfterHit);
    }

private:
    bool _executed;
};

// 81277 - Blood Gorged
class spell_dk_blood_gorged : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BLOOD_BURST });
    }

    void HandleBloodBurst(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if ((GetStackAmount() > 5 && roll_chance_i(34)) || GetStackAmount() == 10)
        {
            Unit* target = GetTarget();
            // The tooltip states that it is 10% per stack but sniffs say 5% instead
            int32 bp = CalculatePct(target->GetMaxHealth(), 5 * GetStackAmount());
            target->CastSpell(target, SPELL_DK_BLOOD_BURST, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_dk_blood_gorged::HandleBloodBurst, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
    }
};

// -48979 - Butchery
class spell_dk_butchery : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BUTCHERY });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_BUTCHERY, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_butchery::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dk_death_and_decay : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_AND_DECAY_DAMAGE });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell({ dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ() }, SPELL_DK_DEATH_AND_DECAY_DAMAGE, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dk_death_and_decay::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 47541 - Death Coil
class spell_dk_death_coil : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_DEATH_COIL_DAMAGE,
                SPELL_DK_DEATH_COIL_HEAL
            });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (Unit * target = GetExplTargetUnit())
        {
            if (!caster->IsFriendlyTo(target) && !caster->isInFront(target))
                return SPELL_FAILED_UNIT_NOT_INFRONT;

            if (target->IsFriendlyTo(caster) && target->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                return SPELL_FAILED_BAD_TARGETS;
        }
        else
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* target = GetHitUnit();
        int32 bp = GetSpellInfo()->Effects[EFFECT_0].CalcValue(caster, nullptr, GetHitUnit());
        bp += CalculatePct(caster->GetTotalAttackPowerValue(BASE_ATTACK), 23);

        if (caster->IsFriendlyTo(target))
        {
            bp *= 3.5f;
            caster->CastSpell(target, SPELL_DK_DEATH_COIL_HEAL, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
        else
        {
            if (AuraEffect const* auraEffect = caster->GetAuraEffect(SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART, EFFECT_1))
                bp += auraEffect->GetBaseAmount();

            caster->CastSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dk_death_coil::CheckCast);
        OnEffectHitTarget.Register(&spell_dk_death_coil::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 52751 - Death Gate
class spell_dk_death_gate : public SpellScript
{
    SpellCastResult CheckClass()
    {
        if (GetCaster()->getClass() != CLASS_DEATH_KNIGHT)
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        return SPELL_CAST_OK;
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, GetEffectValue(), false);
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dk_death_gate::CheckClass);
        OnEffectHitTarget.Register(&spell_dk_death_gate::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 49560 - Death Grip
class spell_dk_death_grip : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetEffectValue();
        Position const* pos = GetExplTargetDest();
        if (Unit* target = GetHitUnit())
        {
            if (!target->HasAuraType(SPELL_AURA_DEFLECT_SPELLS)) // Deterrence
                target->CastSpell({ pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ() }, damage, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_death_grip::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

};

// 48743 - Death Pact
class spell_dk_death_pact : public SpellScript
{
    SpellCastResult CheckCast()
    {
        // Check if we have valid targets, otherwise skip spell casting here
        if (Player* player = GetCaster()->ToPlayer())
            for (Unit::ControlList::const_iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                if (Creature* undeadPet = (*itr)->ToCreature())
                    if (undeadPet->IsAlive() &&
                        undeadPet->GetOwnerOrCreatorGUID() == player->GetGUID() &&
                        undeadPet->GetCreatureType() == CREATURE_TYPE_UNDEAD &&
                        undeadPet->IsWithinDist(player, 100.0f, false))
                        return SPELL_CAST_OK;

        return SPELL_FAILED_NO_PET;
    }

    void FilterTargets(std::list<WorldObject*>& targetList)
    {
        Unit* target = nullptr;
        for (std::list<WorldObject*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
        {
            if (Unit* unit = (*itr)->ToUnit())
            {
                if (unit->GetOwnerOrCreatorGUID() == GetCaster()->GetGUID() && unit->GetCreatureType() == CREATURE_TYPE_UNDEAD)
                {
                    target = unit;
                    break;
                }
            }
        }

        targetList.clear();
        if (target)
            targetList.push_back(target);
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dk_death_pact::CheckCast);
        OnObjectAreaTargetSelect.Register(&spell_dk_death_pact::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 49998 - Death Strike
class spell_dk_death_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_DEATH_STRIKE_ENABLER,
                SPELL_DK_DEATH_STRIKE_HEAL,
                SPELL_DK_BLOOD_SHIELD_MASTERY,
                SPELL_DK_BLOOD_SHIELD_ABSORB
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 heal = 0;

        if (AuraEffect* enabler = GetCaster()->GetAuraEffect(SPELL_DK_DEATH_STRIKE_ENABLER, EFFECT_0, GetCaster()->GetGUID()))
        {
            // Call CalculateAmount() to constantly fire the AuraEffect's HandleCalcAmount method
            heal = CalculatePct(enabler->CalculateAmount(GetCaster()), GetSpellInfo()->Effects[EFFECT_0].DamageMultiplier);

            if (AuraEffect const* aurEff = GetCaster()->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_DEATH_STRIKE, EFFECT_2))
                heal = AddPct(heal, aurEff->GetAmount());

            heal = std::max(heal, int32(GetCaster()->CountPctFromMaxHealth(GetEffectValue())));
            GetCaster()->CastSpell(GetCaster(), SPELL_DK_DEATH_STRIKE_HEAL, CastSpellExtraArgs(true).AddSpellBP0(heal));
        }

        if (!GetCaster()->HasAura(SPELL_DK_BLOOD_PRESENCE))
            return;

        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_DK_BLOOD_SHIELD_MASTERY, EFFECT_0))
        {
            int32 bp = CalculatePct(heal, aurEff->GetAmount());

            if (AuraEffect const* bloodShieldEffect = GetCaster()->GetAuraEffect(SPELL_DK_BLOOD_SHIELD_ABSORB, EFFECT_0))
                bp += std::min(bp + bloodShieldEffect->GetAmount(), int32(GetCaster()->GetMaxHealth()));

            GetCaster()->CastSpell(GetCaster(), SPELL_DK_BLOOD_SHIELD_ABSORB, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_death_strike::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 89832 - Death Strike (Save damage taken in last 5 sec)
class spell_dk_death_strike_enabler : public AuraScript
{
    bool Load() override
    {
        for (uint8 i = 0; i < 5; ++i)
            _damagePerSecond[i] = 0;
        return true;
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo() != nullptr;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (!GetUnitOwner()->HasAura(SPELL_DK_BLOOD_PRESENCE))
        {
            for (uint8 i = 0; i < 5; ++i)
                _damagePerSecond[i] = 0;
        }
        else
            _damagePerSecond[0] += eventInfo.GetDamageInfo()->GetDamage();
    }

    // Cheap hack to have update calls
    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude)
    {
        isPeriodic = true;
        amplitude = 1000;
    }

    void Update(AuraEffect* /*aurEff*/)
    {
        // Move backwards all datas by one
        for (uint8 i = 4; i > 0; --i)
            _damagePerSecond[i] = _damagePerSecond[i - 1];
        _damagePerSecond[0] = 0;
    }

    void HandleCalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = true;
        amount = 0;
        for (uint8 i = 0; i < 5; ++i)
            amount += int32(_damagePerSecond[i]);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_death_strike_enabler::CheckProc);
        OnEffectProc.Register(&spell_dk_death_strike_enabler::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        DoEffectCalcPeriodic.Register(&spell_dk_death_strike_enabler::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectUpdatePeriodic.Register(&spell_dk_death_strike_enabler::Update, EFFECT_0, SPELL_AURA_DUMMY);
        DoEffectCalcAmount.Register(&spell_dk_death_strike_enabler::HandleCalcAmount, EFFECT_0, SPELL_AURA_DUMMY);
    }
private:
    uint32 _damagePerSecond[5];
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_CORPSE_EXPLOSION_TRIGGERED });
    }

    void Suicide(SpellEffIndex /*effIndex*/)
    {
        if (Unit* unitTarget = GetHitUnit())
        {
            // Corpse Explosion (Suicide)
            unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_ghoul_explode::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 48792 - Icebound Fortitude
class spell_dk_icebound_fortitude : public AuraScript
{
    bool Load() override
    {
        Unit* caster = GetCaster();
        return caster && caster->GetTypeId() == TYPEID_PLAYER;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
        {
            int32 value = amount;
            uint32 defValue = uint32(caster->ToPlayer()->GetSkillValue(SKILL_DEFENSE) + caster->ToPlayer()->GetRatingBonusValue(CR_DEFENSE_SKILL));

            if (defValue > 400)
                value -= int32((defValue - 400) * 0.15);

            // Glyph of Icebound Fortitude
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE, EFFECT_0))
            {
                int32 valMax = -aurEff->GetAmount();
                if (value > valMax)
                    value = valMax;
            }
            amount = value;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_icebound_fortitude::CalculateAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
};

// 73975 - Necrotic Strike
class spell_dk_necrotic_strike : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
            amount = int32(caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.7f);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_necrotic_strike::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
    }
};

// ID - 50842 Pestilence
class spell_dk_pestilence : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_PESTILENCE_REDUCED_DOTS,
                SPELL_DK_PESTILENCE_VISUAL,
                SPELL_DK_BLOOD_PLAGUE,
                SPELL_DK_FROST_FEVER
            });
    }

    bool Load() override
    {
        _prevTarget = nullptr;
        return true;
    }

    void OnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();
        Unit* victim = GetExplTargetUnit();

        if (!victim)
            return;

        if (_prevTarget)
            _prevTarget->CastSpell(hitUnit, SPELL_DK_PESTILENCE_VISUAL, true);

        _prevTarget = hitUnit;

        if (victim != hitUnit)
        {
            if (Aura* aurOld = victim->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on victim.
            {
                if (AuraEffect* aurEffOld = aurOld->GetEffect(EFFECT_0))
                {
                    float donePct = aurEffOld->GetDonePct();

                    caster->CastSpell(hitUnit, SPELL_DK_BLOOD_PLAGUE, true); // Spread the disease to hitUnit.

                    if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on hitUnit.
                    {
                        if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                        {
                            aurEffNew->SetDonePct(donePct);
                            aurEffNew->SetBonusAmount(caster->SpellDamageBonusDone(hitUnit, aurEffNew->GetSpellInfo(), 0, DOT, aurEffNew->GetEffIndex()));
                        }
                    }
                }
            }

            if (Aura* aurOld = victim->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID())) // Check Frost Fever application on victim.
            {
                if (AuraEffect* aurEffOld = aurOld->GetEffect(EFFECT_0))
                {
                    float donePct = aurEffOld->GetDonePct();

                    caster->CastSpell(hitUnit, SPELL_DK_FROST_FEVER, true); // Spread the disease to hitUnit.

                    if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID())) // Check Frost Fever application on hitUnit.
                    {
                        if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                        {
                            aurEffNew->SetDonePct(donePct);
                            aurEffNew->SetBonusAmount(caster->SpellDamageBonusDone(hitUnit, aurEffNew->GetSpellInfo(), 0, DOT, aurEffNew->GetEffIndex()));
                        }
                    }
                }
            }
        }
    }

    void HandleAuraApply()
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_DK_PESTILENCE_REDUCED_DOTS, true);
    }

    void HandleAuraRemoval()
    {
        GetCaster()->RemoveAura(SPELL_DK_PESTILENCE_REDUCED_DOTS);
    }

    void Register() override
    {
        BeforeCast.Register(&spell_dk_pestilence::HandleAuraApply);
        OnEffectHitTarget.Register(&spell_dk_pestilence::OnHit, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
        AfterCast.Register(&spell_dk_pestilence::HandleAuraRemoval);
    }

private:
    Unit * _prevTarget;
};

// 48266 - Frost Presence
// 48263 - Blood Presence
// 48265 - Unholy Presence
class spell_dk_presence : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_UNHOLY_PRESENCE,
                SPELL_DK_FROST_PRESENCE,
                SPELL_DK_BLOOD_PRESENCE,
                SPELL_DK_BLOOD_PRESENCE_TRIGGERED,
                SPELL_DK_IMPROVED_UNHOLY_PRESENCE,
                SPELL_DK_IMPROVED_FROST_PRESENCE,
                SPELL_DK_IMPROVED_BLOOD_PRESENCE,
                SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1
            });
    }

    void HandlePresenceEffects(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        uint32 spellId = GetSpellInfo()->Id;

        target->SetPower(POWER_RUNIC_POWER, 0);

        // Improved Unholy Presence
        if (spellId == SPELL_DK_UNHOLY_PRESENCE || spellId == SPELL_DK_FROST_PRESENCE)
            if (AuraEffect const* eff = target->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, DK_ICON_ID_IMPROVED_UNHOLY_PRESENCE, EFFECT_0))
                target->CastSpell(target, SPELL_DK_IMPROVED_UNHOLY_PRESENCE, CastSpellExtraArgs(aurEff).AddSpellBP0(eff->GetAmount()));

        // Improved Frost Presence
        if (spellId == SPELL_DK_UNHOLY_PRESENCE || spellId == SPELL_DK_BLOOD_PRESENCE)
            if (AuraEffect const* eff = target->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, DK_ICON_ID_IMPROVED_FROST_PRESENCE, EFFECT_0))
                target->CastSpell(target, SPELL_DK_IMPROVED_FROST_PRESENCE, CastSpellExtraArgs(aurEff).AddSpellBP0(eff->GetAmount()));

        // Improved Blood Presence and Blood Presence triggered effect
        if (spellId == SPELL_DK_BLOOD_PRESENCE)
        {
            // Apply defense state to permanently enable Rune Strike
            target->ModifyAuraState(AURA_STATE_DEFENSE, true);

            if (Aura const* improvedBloodPresenceAura = target->GetAuraOfRankedSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1, target->GetGUID()))
            {
                // Rune Regeneration bonus effect
                if (AuraEffect const* eff2 = improvedBloodPresenceAura->GetEffect(EFFECT_2))
                    target->CastSpell(target, SPELL_DK_IMPROVED_BLOOD_PRESENCE, CastSpellExtraArgs(aurEff).AddSpellBP0(eff2->GetAmount()));

                // Crit Hit Chance reduction bonus effect
                if (AuraEffect const* eff1 = improvedBloodPresenceAura->GetEffect(EFFECT_1))
                    target->CastSpell(target, SPELL_DK_BLOOD_PRESENCE_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_BASE_POINT1, eff1->GetAmount()));
            }
            else
                target->CastSpell(target, SPELL_DK_BLOOD_PRESENCE_TRIGGERED, aurEff);
        }
        else
        {
            // Damage Reduction bonus effect for the other presences
            if (Aura const* improvedBloodPresenceAura = target->GetAuraOfRankedSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1, target->GetGUID()))
                if (AuraEffect const* eff0 = improvedBloodPresenceAura->GetEffect(EFFECT_0))
                    target->CastSpell(target, SPELL_DK_BLOOD_PRESENCE_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellBP0(-eff0->GetAmount()));
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAura(SPELL_DK_BLOOD_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_IMPROVED_FROST_PRESENCE);
        target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE);
        target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE);

        if (GetId() == SPELL_DK_BLOOD_PRESENCE)
            target->ModifyAuraState(AURA_STATE_DEFENSE, false);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_dk_presence::HandlePresenceEffects, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_dk_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

// -50365 - Improved Blood Presence
// -50384 - Improved Frost Presence
// -50391 - Improved Unholy Presence
class spell_dk_improved_presence : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_BLOOD_PRESENCE,
                SPELL_DK_BLOOD_PRESENCE_TRIGGERED,
                SPELL_DK_IMPROVED_UNHOLY_PRESENCE,
                SPELL_DK_IMPROVED_FROST_PRESENCE,
                SPELL_DK_IMPROVED_BLOOD_PRESENCE
            });
    }
    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAura(SPELL_DK_BLOOD_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_IMPROVED_FROST_PRESENCE);
        target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE);
        target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE);

        if (target->HasAura(SPELL_DK_BLOOD_PRESENCE))
            target->CastSpell(target, SPELL_DK_BLOOD_PRESENCE_TRIGGERED, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_dk_improved_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46584 - Raise Dead
class spell_dk_raise_dead : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
            {
                uint32(spellInfo->Effects[EFFECT_0].CalcValue()),
                uint32(spellInfo->Effects[EFFECT_1].CalcValue()),
                SPELL_DK_MASTER_OF_GHOULS
            });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    uint32 GetGhoulSpellId()
    {
        // Do we have talent Master of Ghouls?
        if (GetCaster()->HasAura(SPELL_DK_MASTER_OF_GHOULS))
            // summon as pet
            return GetSpellInfo()->Effects[EFFECT_1].CalcValue();

        // or guardian
        return GetSpellInfo()->Effects[EFFECT_0].CalcValue();
    }

    void HandleRaiseDead()
    {
        GetCaster()->CastSpell(nullptr, GetGhoulSpellId(), true);
    }

    void Register() override
    {
        OnCast.Register(&spell_dk_raise_dead::HandleRaiseDead);
    }
};

// 59754 Rune Tap - Party
class spell_dk_rune_tap_party : public SpellScript
{
    void CheckTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_dk_rune_tap_party::CheckTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 50421 - Scent of Blood
class spell_dk_scent_of_blood : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SCENT_OF_BLOOD });
    }

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_SCENT_OF_BLOOD, aurEff);
        GetTarget()->RemoveAuraFromStack(GetId());
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_scent_of_blood::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 55090 - Scourge Strike
class spell_dk_scourge_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_SCOURGE_STRIKE_TRIGGERED,
                SPELL_DK_ITEM_T8_MELEE_4P_BONUS
            });
    }

    void HandleAfterHit()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Unit* unitTarget = GetHitUnit())
        {
            multiplier = GetSpellInfo()->Effects[EFFECT_2].CalcValue();
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_ITEM_T8_MELEE_4P_BONUS, EFFECT_0))
                AddPct(multiplier, aurEff->GetAmount());

            int32 bp = CalculatePct(GetHitDamage(), multiplier) * unitTarget->GetDiseasesByCaster(caster->GetGUID());
            caster->CastSpell(unitTarget, SPELL_DK_SCOURGE_STRIKE_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        AfterHit.Register(&spell_dk_scourge_strike::HandleAfterHit);
    }
private:
    float multiplier = 1.0f;
};

// 55233 - Vampiric Blood
class spell_dk_vampiric_blood : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = GetUnitOwner()->CountPctFromMaxHealth(amount);
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_vampiric_blood::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH);
    }
};

// Updated 4.3.4
// -52284 - Will of the Necropolis
class spell_dk_will_of_the_necropolis : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_WILL_OF_THE_NECROPOLIS,
                SPELL_DK_BLOOD_TAP
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo() && GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        int32 bp = aurEff->GetAmount();
        target->CastSpell(target, SPELL_DK_WILL_OF_THE_NECROPOLIS, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
        target->GetSpellHistory()->ResetCooldown(SPELL_DK_BLOOD_TAP, true);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_will_of_the_necropolis::CheckProc);
        OnEffectProc.Register(&spell_dk_will_of_the_necropolis::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE);
    }
};

// 49576 - Death Grip Initial
class spell_dk_death_grip_initial : public SpellScript
{
    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        // Death Grip should not be castable while jumping/falling
        if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
            return SPELL_FAILED_MOVING;

        // Patch 3.3.3 (2010-03-23): Minimum range has been changed to 8 yards in PvP.
        Unit* target = GetExplTargetUnit();
        if (target && target->GetTypeId() == TYPEID_PLAYER)
            if (caster->GetExactDist(target) < 8.f)
                return SPELL_FAILED_TOO_CLOSE;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP, true);
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_dk_death_grip_initial::CheckCast);
        OnEffectHitTarget.Register(&spell_dk_death_grip_initial::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -48965 - Shadow Infusion
class spell_dk_shadow_infusion : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_SHADOW_INFUSION,
                SPELL_DK_DARK_TRANSFORMATION_DUMMY,
                SPELL_DK_DEATH_COIL
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo()->Id != SPELL_DK_DEATH_COIL)
            return false;

        Player* petOwner = GetTarget()->ToPlayer();
        if (!petOwner)
            return false;

        if (Pet* pet = petOwner->GetPet())
            if (pet->HasAura(SPELL_DK_DARK_TRANSFORMATION))
                return false;

        return true;
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Player* petOwner = GetTarget()->ToPlayer();
        if (Pet* pet = petOwner->GetPet())
            if (Aura* aura = pet->GetAura(SPELL_DK_SHADOW_INFUSION))
                if (aura->GetStackAmount() >= 4)
                    petOwner->CastSpell(petOwner, SPELL_DK_DARK_TRANSFORMATION_DUMMY, true);
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_shadow_infusion::CheckProc);
        OnEffectProc.Register(&spell_dk_shadow_infusion::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 63560 - Dark Transformation
class spell_dk_dark_transformation : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_SHADOW_INFUSION,
                SPELL_DK_DARK_TRANSFORMATION_DUMMY
            });
    }

    void HandleLaunch(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->RemoveAurasDueToSpell(SPELL_DK_DARK_TRANSFORMATION_DUMMY);
            if (Player* petOwner = caster->ToPlayer())
                if (Pet* pet = petOwner->GetPet())
                    pet->RemoveAurasDueToSpell(SPELL_DK_SHADOW_INFUSION);
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_dk_dark_transformation::HandleLaunch, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 93426 - Dark Transformation
class spell_dk_dark_transformation_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SHADOW_INFUSION });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            if (Player* player = caster->ToPlayer())
                if (Pet* pet = player->GetPet())
                    if (!pet->HasAura(SPELL_DK_SHADOW_INFUSION))
                        aurEff->GetBase()->Remove();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dk_dark_transformation_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 81229 - Runic Empowerment
// -51459 - Runic Corruption
class spell_dk_runic_empowerment : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_DEATH_COIL_DAMAGE,
                SPELL_DK_FROST_STRIKE,
                SPELL_DK_RUNE_STRIKE,
                SPELL_DK_ENERGIZE_BLOOD_RUNE,
                SPELL_DK_ENERGIZE_FROST_RUNE,
                SPELL_DK_ENERGIZE_UNHOLY_RUNE,
                SPELL_DK_RUNIC_CORRUPTION_TRIGGERED
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        uint32 spellId = eventInfo.GetSpellInfo()->Id;
        if (spellId == SPELL_DK_DEATH_COIL_DAMAGE || spellId == SPELL_DK_FROST_STRIKE || spellId == SPELL_DK_RUNE_STRIKE)
            return true;

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        if (Player* player = GetUnitOwner()->ToPlayer())
        {
            std::list<uint8> cooldownRuneIndex;

            for (uint8 i = 0; i < MAX_RUNES; i++)
            {
                if (player->GetRuneCooldown(i))
                    cooldownRuneIndex.push_back(i);
            }

            if (!cooldownRuneIndex.empty())
            {
                // Runic Corruption
                if (AuraEffect* corruptionEff = player->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_DEATHKNIGHT, DK_ICON_ID_RUNIC_CORRUPTION, EFFECT_0))
                {
                    int32 bp0 = corruptionEff->GetAmount();
                    player->CastSpell(player, SPELL_DK_RUNIC_CORRUPTION_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellBP0(bp0));
                }
                else
                {
                    uint8 randomRune = Trinity::Containers::SelectRandomContainerElement(cooldownRuneIndex);
                    RuneType rune = player->GetCurrentRune(randomRune);
                    switch (rune)
                    {
                        case RUNE_BLOOD:
                        case RUNE_DEATH:
                            player->CastSpell(player, SPELL_DK_ENERGIZE_BLOOD_RUNE,aurEff);
                            break;
                        case RUNE_FROST:
                            player->CastSpell(player, SPELL_DK_ENERGIZE_FROST_RUNE, aurEff);
                            break;
                        case RUNE_UNHOLY:
                            player->CastSpell(player, SPELL_DK_ENERGIZE_UNHOLY_RUNE, aurEff);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_runic_empowerment::CheckProc);
        OnEffectProc.Register(&spell_dk_runic_empowerment::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 49184 - Howling Blast
class spell_dk_howling_blast : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (GetExplTargetUnit() && GetHitUnit())
            if (GetExplTargetUnit() != GetHitUnit())
                SetHitDamage(CalculatePct(GetHitDamage(), GetSpellInfo()->Effects[EFFECT_2].BasePoints));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_howling_blast::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

class spell_dk_threat_of_thassarian : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_OBLITERATE,
                SPELL_DK_OBLITERATE_OFFHAND,
                SPELL_DK_FROST_STRIKE,
                SPELL_DK_FROST_STRIKE_OFFHAND,
                SPELL_DK_PLAGUE_STRIKE,
                SPELL_DK_PLAGUE_STRIKE_OFFHAND,
                SPELL_DK_DEATH_STRIKE,
                SPELL_DK_DEATH_STRIKE_OFFHAND,
                SPELL_DK_RUNE_STRIKE,
                SPELL_DK_RUNE_STRIKE_OFFHAND,
                SPELL_DK_BLOOD_STRIKE,
                SPELL_DK_BLOOD_STRIKE_OFFHAND
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (!GetTarget()->haveOffhandWeapon())
            return;

        if (!roll_chance_i(aurEff->GetAmount()))
            return;

        if (SpellInfo const* spell = eventInfo.GetSpellInfo())
        {
            uint32 offhandSpellId = 0;
            switch (spell->Id)
            {
                case SPELL_DK_OBLITERATE:
                    offhandSpellId = SPELL_DK_OBLITERATE_OFFHAND;
                    break;
                case SPELL_DK_FROST_STRIKE:
                    offhandSpellId = SPELL_DK_FROST_STRIKE_OFFHAND;
                    break;
                case SPELL_DK_PLAGUE_STRIKE:
                    offhandSpellId = SPELL_DK_PLAGUE_STRIKE_OFFHAND;
                    break;
                case SPELL_DK_DEATH_STRIKE:
                    offhandSpellId = SPELL_DK_DEATH_STRIKE_OFFHAND;
                    break;
                case SPELL_DK_RUNE_STRIKE:
                    offhandSpellId = SPELL_DK_RUNE_STRIKE_OFFHAND;
                    break;
                case SPELL_DK_BLOOD_STRIKE:
                    offhandSpellId = SPELL_DK_BLOOD_STRIKE_OFFHAND;
                    break;
                default:
                    break;
            }

            if (offhandSpellId && eventInfo.GetProcTarget())
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), offhandSpellId, aurEff);
        }
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_threat_of_thassarian::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 56835 - Reaping (Passive)
class spell_dk_reaping : public AuraScript
{
    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_ITEM_T11_DPS_4P_BONUS,
                SPELL_DK_DEATH_EATER
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Player* player = GetTarget()->ToPlayer();
        uint8 runeMask = player->GetLastUsedRuneMask();

        for (uint8 i = 0; i < MAX_RUNES; i++)
        {
            if (runeMask & (1 << i) && player->GetCurrentRune(i) == RUNE_BLOOD)
                player->AddRuneByAuraEffect(i, RUNE_DEATH, aurEff, SPELL_AURA_PERIODIC_DUMMY, GetSpellInfo());
        }

        GetEffect(EFFECT_0)->ResetPeriodic(true);

        // T11 set bonus effect
        if (AuraEffect const* aurEff = player->GetAuraEffect(SPELL_DK_ITEM_T11_DPS_4P_BONUS, EFFECT_0))
            player->CastSpell(player, SPELL_DK_DEATH_EATER, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_reaping::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_dk_blood_rites : public AuraScript
{
    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return;

        uint8 runeMask = player->GetLastUsedRuneMask();

        for (uint8 i = 0; i < MAX_RUNES; i++)
        {
            if (runeMask & (1 << i) && player->GetCurrentRune(i) != RUNE_DEATH)
                player->AddRuneByAuraEffect(i, RUNE_DEATH, aurEff, SPELL_AURA_PERIODIC_DUMMY, GetSpellInfo());
        }

        GetEffect(EFFECT_0)->ResetPeriodic(true);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_blood_rites::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_dk_crimson_scourge : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BLOOD_PLAGUE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (DamageInfo* damage = eventInfo.GetDamageInfo())
            if (Unit* target = damage->GetVictim())
                return target->HasAura(SPELL_DK_BLOOD_PLAGUE, GetTarget()->GetGUID());

        return false;
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_crimson_scourge::CheckProc);
    }
};

class spell_dk_army_of_the_dead : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        amount = 0;
        if (Player* player = GetUnitOwner()->ToPlayer())
        {
            float dodgeChance = player->GetFloatValue(PLAYER_DODGE_PERCENTAGE);
            float parryChance = player->GetFloatValue(PLAYER_PARRY_PERCENTAGE);
            amount -= int32(dodgeChance + parryChance);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_army_of_the_dead::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
};

// -49588 Unholy Command
class spell_dk_unholy_command : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_GRIP_INITIAL });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_DK_DEATH_GRIP_INITIAL, true);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_unholy_command::HandleProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
    }
};

// 55078 - Blood Plague
// 55095 - Frost Fever
class spell_dk_disease : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_RESILIENT_INFECTION,
                SPELL_DK_BLOOD_PLAGUE,
                SPELL_DK_FROST_FEVER
            });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 &amount, bool & /*canBeRecalculated*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetUnitOwner();
        if (!caster || !target)
            return;

        // Formular: ${$m1 * 1.15 + $AP * 0.055 * 1.15}
        AddPct(amount, 15);
        int32 bonus = caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.055f * 1.15f;

        bonus = caster->SpellDamageBonusDone(target, GetSpellInfo(), bonus, DOT, EFFECT_0);
        amount += bonus;
    }

    void HandleResilientInfection(DispelInfo* /*dispelInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_GENERIC, DK_ICON_ID_RESILIENT_INFECTION, EFFECT_0))
        {
            if (roll_chance_i(aurEff->GetAmount()))
            {
                int32 bp0 = GetId() == SPELL_DK_FROST_FEVER ? 1 : 0;
                int32 bp1 = GetId() == SPELL_DK_BLOOD_PLAGUE ? 1 : 0;
                caster->CastSpell(caster, SPELL_DK_RESILIENT_INFECTION, CastSpellExtraArgs(true).AddSpellBP0(bp0).AddSpellMod(SPELLVALUE_BASE_POINT1, bp1));
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_dk_disease::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        AfterDispel.Register(&spell_dk_disease::HandleResilientInfection);
    }
};

// -55666 - Desecration
class spell_dk_desecration : public AuraScript
{
    bool CheckProc(ProcEventInfo& eventInfo)
    {
        SpellInfo const* triggerSpell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell);
        if (!triggerSpell)
            return false;

        if (Unit* target = eventInfo.GetActionTarget())
            return !target->IsImmunedToSpell(triggerSpell, GetTarget());

        return false;
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_desecration::CheckProc);
    }
};

// -96269 - Death's Advance
class spell_dk_deaths_advance : public AuraScript
{
    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return false;

        uint8 unholyRunesOnCooldownCount = 0;
        for (uint8 i = 0; i < MAX_RUNES; ++i)
        {
            if (player->GetCurrentRune(i) == RUNE_UNHOLY && player->GetRuneCooldown(i))
                unholyRunesOnCooldownCount++;
        }

        if (unholyRunesOnCooldownCount >= 2)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_deaths_advance::CheckProc);
    }
};

class spell_dk_deaths_advance_aura : public AuraScript
{
    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return;

        uint8 unholyRunesOnCooldownCount = 0;

        for (uint8 i = 0; i < MAX_RUNES; ++i)
        {
            if (player->GetCurrentRune(i) == RUNE_UNHOLY && player->GetRuneCooldown(i))
                unholyRunesOnCooldownCount++;
        }

        if (unholyRunesOnCooldownCount >= 2)
            RefreshDuration();
        else
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dk_deaths_advance_aura::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -51099 - Ebon Plaguebringer
class spell_dk_ebon_plaguebringer : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_EBON_PLAGUE });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Spell const* spell = eventInfo.GetProcSpell();
        if (!spell)
            return;

        int32 bp = aurEff->GetAmount();
        if (Unit* target = spell->m_targets.GetUnitTarget())
            GetTarget()->CastSpell(target, SPELL_DK_EBON_PLAGUE, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_ebon_plaguebringer::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dk_ghoul_taunt : public SpellScript
{
    void HandleTaunt(SpellEffIndex /*effIndex*/)
    {
        if (GetHitCreature() && (GetHitCreature()->IsDungeonBoss() || GetHitCreature()->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_BOSS_MOB))
        {
            PreventHitDefaultEffect(EFFECT_0);
            PreventHitDefaultEffect(EFFECT_1);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_ghoul_taunt::HandleTaunt, EFFECT_0, SPELL_EFFECT_ATTACK_ME);
    }
};

// 49194 - Unholy Blight
class spell_dk_unoly_blight : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_UNHOLY_BLIGHT_PERIODIC });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), 1);
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_UNHOLY_BLIGHT_PERIODIC, CastSpellExtraArgs(aurEff).AddSpellBP0(damage));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_dk_unoly_blight::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 85948 - Festering Strike
class spell_dk_festering_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_FROST_FEVER,
                SPELL_DK_BLOOD_PLAGUE
            });
    }

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint32 durationBonus = GetSpellInfo()->Effects[effIndex].CalcValue(caster) * IN_MILLISECONDS;
        for (AuraEffect* disease : GetHitUnit()->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE))
        {
            if ((disease->GetSpellInfo()->Id == SPELL_DK_FROST_FEVER || disease->GetSpellInfo()->Id == SPELL_DK_BLOOD_PLAGUE)
                && disease->GetCasterGUID() == caster->GetGUID())
            {
                uint32 maxDuration = disease->GetBase()->GetMaxDuration();
                disease->GetBase()->SetDuration(std::min<uint32>(maxDuration, disease->GetBase()->GetDuration() + durationBonus));
            }
        }

        for (AuraEffect* snare : GetHitUnit()->GetAuraEffectsByType(SPELL_AURA_MOD_DECREASE_SPEED))
        {
            SpellInfo const* spellInfo = snare->GetSpellInfo();
            if (spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && spellInfo->SpellFamilyFlags[0] == 0x00000004 &&  snare->GetCasterGUID() == caster->GetGUID())
            {
                uint32 maxDuration = snare->GetBase()->GetMaxDuration();
                snare->GetBase()->SetDuration(std::min<uint32>(maxDuration, snare->GetBase()->GetDuration() + durationBonus));
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_festering_strike::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 51124 - Killing Machine
class spell_dk_killing_machine : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_ITEM_T11_DPS_4P_BONUS,
                SPELL_DK_DEATH_EATER
            });
    }

    void HandleT11Bonus(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_DK_ITEM_T11_DPS_4P_BONUS, EFFECT_0))
            target->CastSpell(target, SPELL_DK_DEATH_EATER, aurEff);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_dk_killing_machine::HandleT11Bonus, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 98996 - Item - Death Knight T12 DPS 4P Bonus
class spell_dk_item_death_knight_t12_dps_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_FLAMING_TORRENT });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo();
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 damage = CalculatePct(aurEff->GetAmount(), eventInfo.GetDamageInfo()->GetDamage());
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_FLAMING_TORRENT, CastSpellExtraArgs(aurEff).AddSpellBP0(damage));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_dk_item_death_knight_t12_dps_4p_bonus::CheckProc);
        OnEffectProc.Register(&spell_dk_item_death_knight_t12_dps_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 98971 - Smoldering Rune
class spell_dk_smoldering_rune : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SMOLDERING_RUNE_ENERGIZE });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_SMOLDERING_RUNE_ENERGIZE, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_dk_smoldering_rune::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_deathknight_spell_scripts()
{
    RegisterSpellScript(spell_dk_anti_magic_shell);
    RegisterSpellScript(spell_dk_anti_magic_zone);
    RegisterSpellScript(spell_dk_army_of_the_dead);
    RegisterSpellScript(spell_dk_blood_boil);
    RegisterSpellScript(spell_dk_blood_gorged);
    RegisterSpellScript(spell_dk_blood_rites);
    RegisterSpellScript(spell_dk_butchery);
    RegisterSpellScript(spell_dk_crimson_scourge);
    RegisterSpellScript(spell_dk_dark_transformation);
    RegisterSpellScript(spell_dk_dark_transformation_aura);
    RegisterSpellScript(spell_dk_death_and_decay);
    RegisterSpellScript(spell_dk_death_coil);
    RegisterSpellScript(spell_dk_death_gate);
    RegisterSpellScript(spell_dk_death_grip);
    RegisterSpellScript(spell_dk_death_grip_initial);
    RegisterSpellScript(spell_dk_item_death_knight_t12_dps_4p_bonus);
    RegisterSpellScript(spell_dk_death_pact);
    RegisterSpellScript(spell_dk_death_strike);
    RegisterSpellScript(spell_dk_death_strike_enabler);
    RegisterSpellScript(spell_dk_deaths_advance);
    RegisterSpellScript(spell_dk_deaths_advance_aura);
    RegisterSpellScript(spell_dk_desecration);
    RegisterSpellScript(spell_dk_disease);
    RegisterSpellScript(spell_dk_ebon_plaguebringer);
    RegisterSpellScript(spell_dk_festering_strike);
    RegisterSpellScript(spell_dk_ghoul_explode);
    RegisterSpellScript(spell_dk_ghoul_taunt);
    RegisterSpellScript(spell_dk_howling_blast);
    RegisterSpellScript(spell_dk_icebound_fortitude);
    RegisterSpellScript(spell_dk_improved_presence);
    RegisterSpellScript(spell_dk_killing_machine);
    RegisterSpellScript(spell_dk_necrotic_strike);
    RegisterSpellScript(spell_dk_pestilence);
    RegisterSpellScript(spell_dk_presence);
    RegisterSpellScript(spell_dk_raise_dead);
    RegisterSpellScript(spell_dk_reaping);
    RegisterSpellScript(spell_dk_rune_tap_party);
    RegisterSpellScript(spell_dk_runic_empowerment);
    RegisterSpellScript(spell_dk_scent_of_blood);
    RegisterSpellScript(spell_dk_shadow_infusion);
    RegisterSpellScript(spell_dk_scourge_strike);
    RegisterSpellScript(spell_dk_smoldering_rune);
    RegisterSpellScript(spell_dk_threat_of_thassarian);
    RegisterSpellScript(spell_dk_unoly_blight);
    RegisterSpellScript(spell_dk_unholy_command);
    RegisterSpellScript(spell_dk_vampiric_blood);
    RegisterSpellScript(spell_dk_will_of_the_necropolis);
}
