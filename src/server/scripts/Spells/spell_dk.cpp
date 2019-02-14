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
    SPELL_DK_BLACK_ICE_R1                       = 49140,
    SPELL_DK_BLOOD_BOIL_TRIGGERED               = 65658,
    SPELL_DK_BLOOD_GORGED_HEAL                  = 50454,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_BLOOD_PRESENCE                     = 48263,
    SPELL_DK_BLOOD_PRESENCE_TRIGGERED           = 61261,
    SPELL_DK_BLOOD_SHIELD_MASTERY               = 77513,
    SPELL_DK_BLOOD_SHIELD_ABSORB                = 77535,
    SPELL_DK_BLOOD_STRIKE                       = 45902,
    SPELL_DK_BLOOD_STRIKE_OFFHAND               = 66215,
    SPELL_DK_BUTCHERY                           = 50163,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_DARK_TRANSFORMATION_DUMMY          = 93426,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_COIL                         = 47541,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633,
    SPELL_DK_DEATH_GRIP                         = 49560,
    SPELL_DK_DEATH_GRIP_INITIAL                 = 49576,
    SPELL_DK_DEATH_STRIKE                       = 49998,
    SPELL_DK_DEATH_STRIKE_OFFHAND               = 66188,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_DEATH_STRIKE_ENABLER               = 89832,
    SPELL_DK_ENERGIZE_BLOOD_RUNE                = 81166,
    SPELL_DK_ENERGIZE_FROST_RUNE                = 81168,
    SPELL_DK_ENERGIZE_UNHOLY_RUNE               = 81169,
    SPELL_DK_FREEZING_FOG                       = 59052,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_FROST_PRESENCE                     = 48266,
    SPELL_DK_FROST_STRIKE                       = 49143,
    SPELL_DK_FROST_STRIKE_OFFHAND               = 66196,
    SPELL_DK_GHOUL_EXPLODE                      = 47496,
    SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE        = 58625,
    SPELL_DK_HOWLING_BLAST                      = 49184,
    SPELL_DK_ICY_TOUCH                          = 45477,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1         = 50365,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED  = 63611,
    SPELL_DK_IMPROVED_DEATH_STRIKE              = 62905,
    SPELL_DK_IMPROVED_FROST_PRESENCE_R1         = 50384,
    SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED  = 63621,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1        = 50391,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED = 63622,
    SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART          = 64962,
    SPELL_DK_ITEM_T8_MELEE_4P_BONUS             = 64736,
    SPELL_DK_MASTER_OF_GHOULS                   = 52143,
    SPELL_DK_OBLITERATE                         = 49020,
    SPELL_DK_OBLITERATE_OFFHAND                 = 66198,
    SPELL_DK_PLAGUE_STRIKE                      = 45462,
    SPELL_DK_PLAGUE_STRIKE_OFFHAND              = 66216,
    SPELL_DK_RESILIENT_INFECTION                = 90721,
    SPELL_DK_RUNIC_POWER_ENERGIZE               = 49088,
    SPELL_DK_RUNIC_CORRUPTION_TRIGGERED         = 51460,
    SPELL_DK_RUNE_STRIKE                        = 56815,
    SPELL_DK_RUNE_STRIKE_OFFHAND                = 66217,
    SPELL_DK_RUNE_TAP                           = 48982,
    SPELL_DK_SCENT_OF_BLOOD                     = 50422,
    SPELL_DK_SCOURGE_STRIKE_TRIGGERED           = 70890,
    SPELL_DK_SHADOW_INFUSION                    = 91342,
    SPELL_DK_UNHOLY_PRESENCE                    = 48265,
    SPELL_DK_PESTILENCE_REDUCED_DOTS            = 76243,
    SPELL_DK_PESTILENCE_VISUAL                  = 91939,
    SPELL_DK_WILL_OF_THE_NECROPOLIS             = 96171
};

enum DKSpellIcons
{
    DK_ICON_ID_RUNIC_CORRUPTION                 = 4068,
    DK_ICON_ID_RESILIENT_INFECTION              = 1910
};

// 50462 - Anti-Magic Shell (on raid member)
class spell_dk_anti_magic_shell_raid : public AuraScript
{
    PrepareAuraScript(spell_dk_anti_magic_shell_raid);

    bool Load() override
    {
        absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        /// @todo this should absorb limited amount of damage, but no info on calculation formula
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_raid::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_raid::Absorb, EFFECT_0);
    }
private:
    uint32 absorbPct;
};

// 48707 - Anti-Magic Shell (on self)
class spell_dk_anti_magic_shell_self : public AuraScript
{
    PrepareAuraScript(spell_dk_anti_magic_shell_self);

    bool Load() override
    {
        absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
        hpPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_RUNIC_POWER_ENERGIZE });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        amount = GetCaster()->CountPctFromMaxHealth(hpPct);
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        absorbAmount = std::min(CalculatePct(dmgInfo.GetDamage(), absorbPct), GetTarget()->CountPctFromMaxHealth(hpPct));
    }

    void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
    {
        // damage absorbed by Anti-Magic Shell energizes the DK with additional runic power.
        // This, if I'm not mistaken, shows that we get back ~20% of the absorbed damage as runic power.
        int32 bp = CalculatePct(absorbAmount, 20);
        GetTarget()->CastCustomSpell(SPELL_DK_RUNIC_POWER_ENERGIZE, SPELLVALUE_BASE_POINT0, bp, GetTarget(), true, nullptr, aurEff);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_self::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self::Absorb, EFFECT_0);
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self::Trigger, EFFECT_0);
    }
private:
    uint32 absorbPct;
    uint32 hpPct;
};

// 50461 - Anti-Magic Zone
class spell_dk_anti_magic_zone : public AuraScript
{
    PrepareAuraScript(spell_dk_anti_magic_zone);

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
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_zone::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_zone::Absorb, EFFECT_0);
    }
private:
    uint32 absorbPct = 0;
};

// 48721 - Blood Boil
class spell_dk_blood_boil : public SpellScript
{
    PrepareSpellScript(spell_dk_blood_boil);

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
        AfterHit += SpellHitFn(spell_dk_blood_boil::HandleAfterHit);
    }

private:
    bool _executed;
};


// 50453 - Bloodworms Health Leech
class spell_dk_blood_gorged : public AuraScript
{
    PrepareAuraScript(spell_dk_blood_gorged);

    bool Load() override
    {
        _procTarget = nullptr;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BLOOD_GORGED_HEAL });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        _procTarget = GetTarget()->GetOwner();
        return _procTarget != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        int32 heal = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), 150));
        GetTarget()->CastCustomSpell(SPELL_DK_BLOOD_GORGED_HEAL, SPELLVALUE_BASE_POINT0, heal, _procTarget, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_blood_gorged::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_blood_gorged::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }

private:
    Unit * _procTarget;
};

// -48979 - Butchery
class spell_dk_butchery : public AuraScript
{
    PrepareAuraScript(spell_dk_butchery);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BUTCHERY });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastCustomSpell(SPELL_DK_BUTCHERY, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_butchery::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dk_death_and_decay : public AuraScript
{
    PrepareAuraScript(spell_dk_death_and_decay);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_AND_DECAY_DAMAGE });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), SPELL_DK_DEATH_AND_DECAY_DAMAGE, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_death_and_decay::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_dk_death_coil : public SpellScript
{
    PrepareSpellScript(spell_dk_death_coil);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_DAMAGE, SPELL_DK_DEATH_COIL_HEAL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetEffectValue();
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            if (caster->IsFriendlyTo(target))
            {
                int32 bp = int32(damage * 1.5f);
                caster->CastCustomSpell(target, SPELL_DK_DEATH_COIL_HEAL, &bp, nullptr, nullptr, true);
            }
            else
            {
                if (AuraEffect const* auraEffect = caster->GetAuraEffect(SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART, EFFECT_1))
                    damage += auraEffect->GetBaseAmount();
                caster->CastCustomSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, &damage, nullptr, nullptr, true);
            }
        }
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetExplTargetUnit())
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

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_coil::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 52751 - Death Gate
class spell_dk_death_gate : public SpellScript
{
    PrepareSpellScript(spell_dk_death_gate);

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
        OnCheckCast += SpellCheckCastFn(spell_dk_death_gate::CheckClass);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_gate::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 49560 - Death Grip
class spell_dk_death_grip : public SpellScript
{
    PrepareSpellScript(spell_dk_death_grip);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetEffectValue();
        Position const* pos = GetExplTargetDest();
        if (Unit* target = GetHitUnit())
        {
            if (!target->HasAuraType(SPELL_AURA_DEFLECT_SPELLS)) // Deterrence
                target->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), damage, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

};

// 48743 - Death Pact
class spell_dk_death_pact : public SpellScript
{
    PrepareSpellScript(spell_dk_death_pact);

    SpellCastResult CheckCast()
    {
        // Check if we have valid targets, otherwise skip spell casting here
        if (Player* player = GetCaster()->ToPlayer())
            for (Unit::ControlList::const_iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                if (Creature* undeadPet = (*itr)->ToCreature())
                    if (undeadPet->IsAlive() &&
                        undeadPet->GetOwnerGUID() == player->GetGUID() &&
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
                if (unit->GetOwnerGUID() == GetCaster()->GetGUID() && unit->GetCreatureType() == CREATURE_TYPE_UNDEAD)
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
        OnCheckCast += SpellCheckCastFn(spell_dk_death_pact::CheckCast);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_death_pact::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 49998 - Death Strike
class spell_dk_death_strike : public SpellScript
{
    PrepareSpellScript(spell_dk_death_strike);

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
            GetCaster()->CastCustomSpell(SPELL_DK_DEATH_STRIKE_HEAL, SPELLVALUE_BASE_POINT0, heal, GetCaster(), true);
        }

        if (!GetCaster()->HasAura(SPELL_DK_BLOOD_PRESENCE))
            return;

        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_DK_BLOOD_SHIELD_MASTERY, EFFECT_0))
            GetCaster()->CastCustomSpell(SPELL_DK_BLOOD_SHIELD_ABSORB, SPELLVALUE_BASE_POINT0, CalculatePct(heal, aurEff->GetAmount()), GetCaster(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_strike::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 89832 - Death Strike (Save damage taken in last 5 sec)
class spell_dk_death_strike_enabler : public AuraScript
{
    PrepareAuraScript(spell_dk_death_strike_enabler);

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
        DoCheckProc += AuraCheckProcFn(spell_dk_death_strike_enabler::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_death_strike_enabler::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_dk_death_strike_enabler::CalcPeriodic, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_dk_death_strike_enabler::Update, EFFECT_0, SPELL_AURA_DUMMY);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_death_strike_enabler::HandleCalcAmount, EFFECT_0, SPELL_AURA_DUMMY);
    }
private:
    uint32 _damagePerSecond[5];
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScript
{
    PrepareSpellScript(spell_dk_ghoul_explode);

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
        OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 48792 - Icebound Fortitude
class spell_dk_icebound_fortitude : public AuraScript
{
    PrepareAuraScript(spell_dk_icebound_fortitude);

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
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_icebound_fortitude::CalculateAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
};

// -50365 - Improved Blood Presence
class spell_dk_improved_blood_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_blood_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_BLOOD_PRESENCE,
                SPELL_DK_FROST_PRESENCE,
                SPELL_DK_UNHOLY_PRESENCE,
                SPELL_DK_BLOOD_PRESENCE_TRIGGERED
            });
    }

    void HandleModDamagePctTaken(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if ((target->HasAura(SPELL_DK_FROST_PRESENCE) || target->HasAura(SPELL_DK_UNHOLY_PRESENCE)) && !target->HasAura(SPELL_DK_BLOOD_PRESENCE_TRIGGERED))
            target->CastCustomSpell(SPELL_DK_BLOOD_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, -aurEff->GetAmount(), target, true, nullptr, aurEff);
    }

    void HandleModAttackerMeleeCritChance(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DK_BLOOD_PRESENCE))
            if (AuraEffect* triggeredEff = target->GetAuraEffect(SPELL_DK_BLOOD_PRESENCE_TRIGGERED, EFFECT_1))
                triggeredEff->SetAmount(aurEff->GetAmount());
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (target->HasAura(SPELL_DK_BLOOD_PRESENCE))
        {
            if (AuraEffect* triggeredEff = target->GetAuraEffect(SPELL_DK_BLOOD_PRESENCE_TRIGGERED, EFFECT_1))
                triggeredEff->SetAmount(0);
        }
        else
            target->RemoveAura(SPELL_DK_BLOOD_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_blood_presence::HandleModDamagePctTaken, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_blood_presence::HandleModAttackerMeleeCritChance, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_blood_presence::HandleEffectRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// -50384 - Improved Frost Presence
class spell_dk_improved_frost_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_frost_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_BLOOD_PRESENCE,
                SPELL_DK_UNHOLY_PRESENCE,
                SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED
            });
    }

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if ((target->HasAura(SPELL_DK_BLOOD_PRESENCE) || target->HasAura(SPELL_DK_UNHOLY_PRESENCE))
            && !target->HasAura(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED))
        {
            CustomSpellValues val;
            val.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
            val.AddSpellMod(SPELLVALUE_BASE_POINT1, aurEff->GetAmount());
            target->CastCustomSpell(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED, val, target, TRIGGERED_FULL_MASK, nullptr, aurEff);
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_frost_presence::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_frost_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// -50391 - Improved Unholy Presence
class spell_dk_improved_unholy_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_unholy_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_BLOOD_PRESENCE,
                SPELL_DK_FROST_PRESENCE,
                SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED
            });
    }

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if ((target->HasAura(SPELL_DK_BLOOD_PRESENCE) || target->HasAura(SPELL_DK_FROST_PRESENCE)) && !target->HasAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED))
            target->CastCustomSpell(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true, nullptr, aurEff);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_unholy_presence::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_unholy_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 73975 - Necrotic Strike
class spell_dk_necrotic_strike : public AuraScript
{
    PrepareAuraScript(spell_dk_necrotic_strike);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
            amount = int32(caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.7f);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_necrotic_strike::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
    }
};

// ID - 50842 Pestilence
class spell_dk_pestilence : public SpellScript
{
    PrepareSpellScript(spell_dk_pestilence);

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
                    float critChance = aurEffOld->GetCritChance();

                    caster->CastSpell(hitUnit, SPELL_DK_BLOOD_PLAGUE, true); // Spread the disease to hitUnit.

                    if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on hitUnit.
                    {
                        if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                        {
                            aurEffNew->SetCritChance(critChance); // Blood Plague can crit if caster has T9.
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
        BeforeCast += SpellCastFn(spell_dk_pestilence::HandleAuraApply);
        OnEffectHitTarget += SpellEffectFn(spell_dk_pestilence::OnHit, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
        AfterCast += SpellCastFn(spell_dk_pestilence::HandleAuraRemoval);
    }

private:
    Unit * _prevTarget;
};

// 48266 - Frost Presence
// 48263 - Blood Presence
// 48265 - Unholy Presence
class spell_dk_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_BLOOD_PRESENCE,
                SPELL_DK_FROST_PRESENCE,
                SPELL_DK_UNHOLY_PRESENCE,
                SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1,
                SPELL_DK_IMPROVED_FROST_PRESENCE_R1,
                SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1,
                SPELL_DK_BLOOD_PRESENCE_TRIGGERED,
                SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED,
                SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED,
                SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED
            });
    }

    void HandleRunicPowerLoss(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetPower(POWER_RUNIC_POWER, 0);
    }

    void HandleImprovedBloodPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        // Improved Blood Presence Rune Regeneration Bonus
        if (GetSpellInfo()->Id == SPELL_DK_BLOOD_PRESENCE)
        {
            if (Aura const* aura = target->GetAuraOfRankedSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1))
                if (AuraEffect const* impAurEff = aura->GetEffect(EFFECT_2))
                    if (!target->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED))
                    {
                        CustomSpellValues val;
                        val.AddSpellMod(SPELLVALUE_BASE_POINT0, impAurEff->GetAmount());
                        val.AddSpellMod(SPELLVALUE_BASE_POINT1, impAurEff->GetAmount());
                        target->CastCustomSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, val, target, TRIGGERED_FULL_MASK, nullptr, aurEff);
                    }
        }

        if (Aura const* aura = target->GetAuraOfRankedSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1))
        {
            CustomSpellValues val;
            if (GetSpellInfo()->Id == SPELL_DK_BLOOD_PRESENCE)
            {
                if (AuraEffect const* impAurEff = aura->GetEffect(EFFECT_1))
                    val.AddSpellMod(SPELLVALUE_BASE_POINT1, impAurEff->GetAmount());
            }
            else
            {
                if (AuraEffect const* impAurEff = aura->GetEffect(EFFECT_0))
                    val.AddSpellMod(SPELLVALUE_BASE_POINT0, -impAurEff->GetAmount());
            }

            if (!target->HasAura(SPELL_DK_BLOOD_PRESENCE_TRIGGERED))
                target->CastCustomSpell(SPELL_DK_BLOOD_PRESENCE_TRIGGERED, val, target, TRIGGERED_FULL_MASK, nullptr, aurEff);

        }
        else if (GetSpellInfo()->Id == SPELL_DK_BLOOD_PRESENCE)
            target->CastSpell(target, SPELL_DK_BLOOD_PRESENCE_TRIGGERED, true, nullptr, aurEff);
    }

    void HandleImprovedFrostPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetSpellInfo()->Id != SPELL_DK_BLOOD_PRESENCE && GetSpellInfo()->Id != SPELL_DK_UNHOLY_PRESENCE)
            return;

        Unit* target = GetTarget();
        if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_FROST_PRESENCE_R1, EFFECT_0))
            if (!target->HasAura(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED))
            {
                CustomSpellValues val;
                val.AddSpellMod(SPELLVALUE_BASE_POINT0, impAurEff->GetAmount());
                val.AddSpellMod(SPELLVALUE_BASE_POINT1, impAurEff->GetAmount());
                target->CastCustomSpell(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED, val, target, TRIGGERED_FULL_MASK, nullptr, aurEff);
            }
    }

    void HandleImprovedUnholyPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetSpellInfo()->Id != SPELL_DK_BLOOD_PRESENCE && GetSpellInfo()->Id != SPELL_DK_FROST_PRESENCE)
            return;

        Unit* target = GetTarget();
        if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1, EFFECT_0))
            if (!target->HasAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED))
                target->CastCustomSpell(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, impAurEff->GetAmount(), target, true, nullptr, aurEff);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAura(SPELL_DK_BLOOD_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleRunicPowerLoss, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleImprovedBloodPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleImprovedFrostPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleImprovedUnholyPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 46584 - Raise Dead
class spell_dk_raise_dead : public SpellScript
{
    PrepareSpellScript(spell_dk_raise_dead);

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
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(GetGhoulSpellId());
        GetCaster()->CastSpell((Unit*)nullptr, spellInfo, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_dk_raise_dead::HandleRaiseDead);
    }
};

// 59754 Rune Tap - Party
class spell_dk_rune_tap_party : public SpellScript
{
    PrepareSpellScript(spell_dk_rune_tap_party);

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_rune_tap_party::CheckTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 50421 - Scent of Blood
class spell_dk_scent_of_blood : public AuraScript
{
    PrepareAuraScript(spell_dk_scent_of_blood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SCENT_OF_BLOOD });
    }

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_SCENT_OF_BLOOD, true, nullptr, aurEff);
        GetTarget()->RemoveAuraFromStack(GetId());
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_scent_of_blood::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 55090 - Scourge Strike (55265, 55270, 55271)
class spell_dk_scourge_strike : public SpellScript
{
    PrepareSpellScript(spell_dk_scourge_strike);

    bool Load() override
    {
        multiplier = 1.0f;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SCOURGE_STRIKE_TRIGGERED });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            multiplier = (GetEffectValue() * unitTarget->GetDiseasesByCaster(caster->GetGUID()) / 100.f);
            // Death Knight T8 Melee 4P Bonus
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_ITEM_T8_MELEE_4P_BONUS, EFFECT_0))
                AddPct(multiplier, aurEff->GetAmount());
        }
    }

    void HandleAfterHit()
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            int32 bp = GetHitDamage() * multiplier;

            if (AuraEffect* aurEff = caster->GetAuraEffectOfRankedSpell(SPELL_DK_BLACK_ICE_R1, EFFECT_0))
                AddPct(bp, aurEff->GetAmount());

            caster->CastCustomSpell(unitTarget, SPELL_DK_SCOURGE_STRIKE_TRIGGERED, &bp, nullptr, nullptr, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_scourge_strike::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
        AfterHit += SpellHitFn(spell_dk_scourge_strike::HandleAfterHit);
    }
private:
    float multiplier;
};

// 55233 - Vampiric Blood
class spell_dk_vampiric_blood : public AuraScript
{
    PrepareAuraScript(spell_dk_vampiric_blood);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = GetUnitOwner()->CountPctFromMaxHealth(amount);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH);
    }
};

// -52284 - Will of the Necropolis
class spell_dk_will_of_the_necropolis : public AuraScript
{
    PrepareAuraScript(spell_dk_will_of_the_necropolis);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_WILL_OF_THE_NECROPOLIS });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        //! HACK due to currenct proc system implementation
        if (Player* player = GetTarget()->ToPlayer())
            if (player->GetSpellHistory()->HasCooldown(GetId()))
                return false;

        return GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_WILL_OF_THE_NECROPOLIS, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_will_of_the_necropolis::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_will_of_the_necropolis::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE);
    }
};

// 49576 - Death Grip Initial
class spell_dk_death_grip_initial : public SpellScript
{
    PrepareSpellScript(spell_dk_death_grip_initial);

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        // Death Grip should not be castable while jumping/falling
        if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
            return SPELL_FAILED_MOVING;

        // Patch 3.3.3 (2010-03-23): Minimum range has been changed to 8 yards in PvP.
        Unit* target = GetExplTargetUnit();
        if (target && target->GetTypeId() == TYPEID_PLAYER)
            if (caster->GetDistance(target) < 8.f)
                return SPELL_FAILED_TOO_CLOSE;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_grip_initial::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_initial::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -48965 - Shadow Infusion
class spell_dk_shadow_infusion : public AuraScript
{
    PrepareAuraScript(spell_dk_shadow_infusion);

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
        return eventInfo.GetProcSpell()->GetSpellInfo()->Id == SPELL_DK_DEATH_COIL;
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (Unit* caster = GetCaster())
            if (Player* petOwner = caster->ToPlayer())
                if (Pet* pet = petOwner->GetPet())
                    if (Aura* aura = pet->GetAura(SPELL_DK_SHADOW_INFUSION))
                        if (aura->GetStackAmount() == 4)
                            caster->CastSpell(caster, SPELL_DK_DARK_TRANSFORMATION_DUMMY, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_shadow_infusion::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_shadow_infusion::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 63560 - Dark Transformation
class spell_dk_dark_transformation : public SpellScript
{
    PrepareSpellScript(spell_dk_dark_transformation);

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
        OnEffectLaunchTarget += SpellEffectFn(spell_dk_dark_transformation::HandleLaunch, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 93426 - Dark Transformation
class spell_dk_dark_transformation_aura : public AuraScript
{
    PrepareAuraScript(spell_dk_dark_transformation_aura);

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
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_dark_transformation_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 81229 - Runic Empowerment
// -51459 - Runic Corruption
class spell_dk_runic_empowerment : public AuraScript
{
    PrepareAuraScript(spell_dk_runic_empowerment);

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

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
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
                    player->CastCustomSpell(player, SPELL_DK_RUNIC_CORRUPTION_TRIGGERED, &bp0, 0, 0, true, nullptr, aurEff);
                }
                else
                {
                    uint8 randomRune = Trinity::Containers::SelectRandomContainerElement(cooldownRuneIndex);
                    RuneType rune = player->GetCurrentRune(randomRune);
                    switch (rune)
                    {
                        case RUNE_BLOOD:
                        case RUNE_DEATH:
                            player->CastSpell(player, SPELL_DK_ENERGIZE_BLOOD_RUNE, true, nullptr, aurEff);
                            break;
                        case RUNE_FROST:
                            player->CastSpell(player, SPELL_DK_ENERGIZE_FROST_RUNE, true, nullptr, aurEff);
                            break;
                        case RUNE_UNHOLY:
                            player->CastSpell(player, SPELL_DK_ENERGIZE_UNHOLY_RUNE, true, nullptr, aurEff);
                            break;
                    }
                }
            }
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_runic_empowerment::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_runic_empowerment::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 49184 - Howling Blast
class spell_dk_howling_blast : public SpellScript
{
    PrepareSpellScript(spell_dk_howling_blast);

    void HandleBeforeCast()
    {
        if (Unit* target = GetExplTargetUnit())
            guid = target->GetGUID();
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->GetGUID() != guid)
            SetHitDamage(CalculatePct(GetHitDamage(), GetSpellInfo()->Effects[EFFECT_2].BasePoints));
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_dk_howling_blast::HandleBeforeCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_howling_blast::HandleHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }

private:
    ObjectGuid guid;
};

// -49149 - Chill of the Grave
class spell_dk_chill_of_the_grave : public AuraScript
{
    PrepareAuraScript(spell_dk_chill_of_the_grave);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_FREEZING_FOG,
                SPELL_DK_ICY_TOUCH,
                SPELL_DK_HOWLING_BLAST
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (Spell const* spell = eventInfo.GetProcSpell())
        {
            if (SpellInfo const* spellInfo = spell->GetSpellInfo())
                if (GetTarget()->HasAura(SPELL_DK_FREEZING_FOG))
                    if (spellInfo->Id == SPELL_DK_ICY_TOUCH || spellInfo->Id == SPELL_DK_HOWLING_BLAST)
                        return false;

            if (Unit* spellTarget = spell->m_targets.GetUnitTarget())
                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                    if (Unit* procTarget = eventInfo.GetDamageInfo()->GetVictim())
                        if (spellTarget == procTarget)
                            return true;
        }

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_chill_of_the_grave::CheckProc);
    }
};

class spell_dk_threat_of_thassarian : public AuraScript
{
    PrepareAuraScript(spell_dk_threat_of_thassarian);

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
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), offhandSpellId, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_threat_of_thassarian::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_dk_reaping : public AuraScript
{
    PrepareAuraScript(spell_dk_reaping);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Player* player = GetTarget()->ToPlayer();
        if (!player)
            return;

        uint8 runeMask = player->GetLastUsedRuneMask();

        for (uint8 i = 0; i < MAX_RUNES; i++)
        {
            if (runeMask & (1 << i) && player->GetCurrentRune(i) == RUNE_BLOOD)
                player->AddRuneByAuraEffect(i, RUNE_DEATH, aurEff, SPELL_AURA_PERIODIC_DUMMY, GetSpellInfo());
        }

        GetEffect(EFFECT_0)->ResetPeriodic(true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_reaping::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_dk_blood_rites : public AuraScript
{
    PrepareAuraScript(spell_dk_blood_rites);

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
        OnEffectProc += AuraEffectProcFn(spell_dk_blood_rites::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_dk_crimson_scourge : public AuraScript
{
    PrepareAuraScript(spell_dk_crimson_scourge);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        if (DamageInfo* damage = eventInfo.GetDamageInfo())
            if (Unit* target = damage->GetVictim())
                if (target->GetDiseasesByCaster(GetTarget()->GetGUID(), false))
                    return;

        PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_crimson_scourge::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_dk_army_of_the_dead : public AuraScript
{
    PrepareAuraScript(spell_dk_army_of_the_dead);

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
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_army_of_the_dead::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
private:
    uint32 absorbPct;
};

// -49588 Unholy Command
class spell_dk_unholy_command : public AuraScript
{
    PrepareAuraScript(spell_dk_unholy_command);

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
        OnEffectProc += AuraEffectProcFn(spell_dk_unholy_command::HandleProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
    }
};

// 55078 - Blood Plague
// 55095 - Frost Fever
class spell_dk_disease : public AuraScript
{
    PrepareAuraScript(spell_dk_disease);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_DK_RESILIENT_INFECTION,
                SPELL_DK_BLOOD_PLAGUE,
                SPELL_DK_FROST_FEVER
            });
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
                caster->CastCustomSpell(caster, SPELL_DK_RESILIENT_INFECTION, &bp0, &bp1, nullptr, true);
            }
        }
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_dk_disease::HandleResilientInfection);
    }
};

// -55666 - Desecration
class spell_dk_desecration : public AuraScript
{
    PrepareAuraScript(spell_dk_desecration);

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
        DoCheckProc += AuraCheckProcFn(spell_dk_desecration::CheckProc);
    }
};

void AddSC_deathknight_spell_scripts()
{
    RegisterAuraScript(spell_dk_anti_magic_shell_raid);
    RegisterAuraScript(spell_dk_anti_magic_shell_self);
    RegisterAuraScript(spell_dk_anti_magic_zone);
    RegisterAuraScript(spell_dk_army_of_the_dead);
    RegisterSpellScript(spell_dk_blood_boil);
    RegisterAuraScript(spell_dk_blood_gorged);
    RegisterAuraScript(spell_dk_blood_rites);
    RegisterAuraScript(spell_dk_butchery);
    RegisterAuraScript(spell_dk_chill_of_the_grave);
    RegisterAuraScript(spell_dk_crimson_scourge);
    RegisterSpellScript(spell_dk_dark_transformation);
    RegisterAuraScript(spell_dk_dark_transformation_aura);
    RegisterAuraScript(spell_dk_death_and_decay);
    RegisterSpellScript(spell_dk_death_coil);
    RegisterSpellScript(spell_dk_death_gate);
    RegisterSpellScript(spell_dk_death_grip);
    RegisterSpellScript(spell_dk_death_grip_initial);
    RegisterSpellScript(spell_dk_death_pact);
    RegisterSpellScript(spell_dk_death_strike);
    RegisterAuraScript(spell_dk_death_strike_enabler);
    RegisterAuraScript(spell_dk_desecration);
    RegisterAuraScript(spell_dk_disease);
    RegisterSpellScript(spell_dk_ghoul_explode);
    RegisterSpellScript(spell_dk_howling_blast);
    RegisterAuraScript(spell_dk_icebound_fortitude);
    RegisterAuraScript(spell_dk_improved_blood_presence);
    RegisterAuraScript(spell_dk_improved_frost_presence);
    RegisterAuraScript(spell_dk_improved_unholy_presence);
    RegisterAuraScript(spell_dk_necrotic_strike);
    RegisterSpellScript(spell_dk_pestilence);
    RegisterAuraScript(spell_dk_presence);
    RegisterSpellScript(spell_dk_raise_dead);
    RegisterAuraScript(spell_dk_reaping);
    RegisterSpellScript(spell_dk_rune_tap_party);
    RegisterAuraScript(spell_dk_runic_empowerment);
    RegisterAuraScript(spell_dk_scent_of_blood);
    RegisterAuraScript(spell_dk_shadow_infusion);
    RegisterSpellScript(spell_dk_scourge_strike);
    RegisterAuraScript(spell_dk_threat_of_thassarian);
    RegisterAuraScript(spell_dk_unholy_command);
    RegisterAuraScript(spell_dk_vampiric_blood);
    RegisterAuraScript(spell_dk_will_of_the_necropolis);
}
