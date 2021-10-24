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
 * Scripts for spells with SPELLFAMILY_PRIEST and SPELLFAMILY_GENERIC spells used by priest players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pri_".
 */

#include "ScriptMgr.h"
#include "Creature.h"
#include "Errors.h"
#include "GridNotifiers.h"
#include "Player.h"
#include "Random.h"
#include "SharedDefines.h"
#include "SpellAuraEffects.h"
#include "SpellDefines.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum PriestSpells
{
    SPELL_PRIEST_BLESSED_RECOVERY_R1                = 27813,
    SPELL_PRIEST_DIVINE_AEGIS                       = 47753,
    SPELL_PRIEST_EMPOWERED_RENEW                    = 63544,
    SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING         = 55675,
    SPELL_PRIEST_GLYPH_OF_LIGHTWELL                 = 55673,
    SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL    = 56161,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_LIGHTWELL_CHARGES                  = 59907,
    SPELL_PRIEST_MANA_LEECH_PROC                    = 34650,
    SPELL_PRIEST_PENANCE_R1                         = 47540,
    SPELL_PRIEST_PENANCE_R1_DAMAGE                  = 47758,
    SPELL_PRIEST_PENANCE_R1_HEAL                    = 47757,
    SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED        = 33619,
    SPELL_PRIEST_REFLECTIVE_SHIELD_R1               = 33201,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409,
    SPELL_PRIEST_T9_HEALING_2P                      = 67201,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 64085,
    SPELL_PRIEST_GLYPH_OF_SHADOWFIEND_MANA          = 58227,
    SPELL_REPLENISHMENT                             = 57669,
    SPELL_PRIEST_BODY_AND_SOUL_POISON_TRIGGER       = 64136,
    SPELL_PRIEST_ABOLISH_DISEASE                    = 552,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_DIVINE_BLESSING                    = 40440,
    SPELL_PRIEST_DIVINE_WRATH                       = 40441,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL         = 56131,
    SPELL_PRIEST_ORACULAR_HEAL                      = 26170,
    SPELL_PRIEST_ARMOR_OF_FAITH                     = 28810,
    SPELL_PRIEST_BLESSED_HEALING                    = 70772,
    SPELL_PRIEST_MIND_BLAST_R1                      = 8092,
    SPELL_PRIEST_SHADOW_WORD_DEATH_R1               = 32379,
    SPELL_PRIEST_MIND_FLAY_DAMAGE                   = 58381,
    SPELL_PRIEST_LIGHTWELL_RENEW_R1                 = 7001,
    SPELL_PRIEST_LIGHTWELL_RENEW_R2                 = 27873,
    SPELL_PRIEST_LIGHTWELL_RENEW_R3                 = 27874,
    SPELL_PRIEST_LIGHTWELL_RENEW_R4                 = 28276,
    SPELL_PRIEST_LIGHTWELL_RENEW_R5                 = 48084,
    SPELL_PRIEST_LIGHTWELL_RENEW_R6                 = 48085,
    SPELL_PRIEST_TWIN_DISCIPLINE_R1                 = 47586,
    SPELL_PRIEST_SPIRITUAL_HEALING_R1               = 14898,
    SPELL_PRIEST_DIVINE_PROVIDENCE_R1               = 47562
};

enum PriestSpellIcons
{
    PRIEST_ICON_ID_FOCUSED_POWER                    = 2210,
    PRIEST_ICON_ID_BORROWED_TIME                    = 2899,
    PRIEST_ICON_ID_EMPOWERED_RENEW_TALENT           = 3021,
    PRIEST_ICON_ID_PAIN_AND_SUFFERING               = 2874,
};

enum PriestMisc
{
    PRIEST_LIGHTWELL_NPC_1                          = 31897,
    PRIEST_LIGHTWELL_NPC_2                          = 31896,
    PRIEST_LIGHTWELL_NPC_3                          = 31895,
    PRIEST_LIGHTWELL_NPC_4                          = 31894,
    PRIEST_LIGHTWELL_NPC_5                          = 31893,
    PRIEST_LIGHTWELL_NPC_6                          = 31883
};

enum MiscSpells
{
    SPELL_MAGE_ARCANE_POWER                         = 12042,
    SPELL_GENERIC_ARENA_DAMPENING                   = 74410,
    SPELL_GENERIC_BATTLEGROUND_DAMPENING            = 74411
};

enum MiscSpellIcons
{
    SPELL_ICON_ID_STRENGTH_OF_WRYNN                 = 1704,
    SPELL_ICON_ID_HELLSCREAM_WARSONG                = 937
};

class PowerCheck
{
    public:
        explicit PowerCheck(Powers const power) : _power(power) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
                return target->GetPowerType() != _power;

            return true;
        }

    private:
        Powers const _power;
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

// 26169 - Oracle Healing Bonus
class spell_pri_aq_3p_bonus : public AuraScript
{
    PrepareAuraScript(spell_pri_aq_3p_bonus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ORACULAR_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActor();
        if (caster == eventInfo.GetProcTarget())
            return;

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(healInfo->GetHeal(), 10));
        caster->CastSpell(caster, SPELL_PRIEST_ORACULAR_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_aq_3p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -27811 - Blessed Recovery
class spell_pri_blessed_recovery : public AuraScript
{
    PrepareAuraScript(spell_pri_blessed_recovery);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_BLESSED_RECOVERY_R1 });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* dmgInfo = eventInfo.GetDamageInfo();
        if (!dmgInfo || !dmgInfo->GetDamage())
            return;

        Unit* target = eventInfo.GetActionTarget();
        uint32 triggerSpell = sSpellMgr->GetSpellWithRank(SPELL_PRIEST_BLESSED_RECOVERY_R1, aurEff->GetSpellInfo()->GetRank());
        SpellInfo const* triggerInfo = sSpellMgr->AssertSpellInfo(triggerSpell);

        int32 bp = CalculatePct(static_cast<int32>(dmgInfo->GetDamage()), aurEff->GetAmount());

        ASSERT(triggerInfo->GetMaxTicks() > 0);
        bp /= triggerInfo->GetMaxTicks();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(bp);
        target->CastSpell(target, triggerSpell, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_blessed_recovery::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// -64127 - Body and Soul
class spell_pri_body_and_soul : public AuraScript
{
    PrepareAuraScript(spell_pri_body_and_soul);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PRIEST_BODY_AND_SOUL_POISON_TRIGGER,
            SPELL_PRIEST_ABOLISH_DISEASE
        });
    }

    void HandleProcTriggerSpell(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        // Proc only on Power Word: Shield
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || !(spellInfo->SpellFamilyFlags[0] & 0x00000001))
        {
            PreventDefaultAction();
            return;
        }
    }

    void HandleProcDummy(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        // Proc only on self casted abolish disease
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return;

        Unit* caster = eventInfo.GetActor();
        if (spellInfo->Id != SPELL_PRIEST_ABOLISH_DISEASE || caster != eventInfo.GetProcTarget())
            return;

        if (roll_chance_i(aurEff->GetAmount()))
            caster->CastSpell(caster, SPELL_PRIEST_BODY_AND_SOUL_POISON_TRIGGER, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul::HandleProcTriggerSpell, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul::HandleProcDummy, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// -34861 - Circle of Healing
class spell_pri_circle_of_healing : public SpellScript
{
    PrepareSpellScript(spell_pri_circle_of_healing);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaidCheck(GetCaster()));

        uint32 const maxTargets = GetCaster()->HasAura(SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING) ? 6 : 5; // Glyph of Circle of Healing

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_circle_of_healing::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// -47509 - Divine Aegis
class spell_pri_divine_aegis : public AuraScript
{
    PrepareAuraScript(spell_pri_divine_aegis);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_DIVINE_AEGIS });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget() != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        int32 absorb = CalculatePct(healInfo->GetHeal(), aurEff->GetAmount());

        // Multiple effects stack, so let's try to find this aura.
        if (AuraEffect const* aegis = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_PRIEST_DIVINE_AEGIS, EFFECT_0))
            absorb += aegis->GetAmount();

        absorb = std::min(absorb, eventInfo.GetProcTarget()->GetLevel() * 125);

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(absorb);
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_DIVINE_AEGIS, args);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_divine_aegis::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_divine_aegis::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 64844 - Divine Hymn
class spell_pri_divine_hymn : public SpellScript
{
    PrepareSpellScript(spell_pri_divine_hymn);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaidCheck(GetCaster()));

        uint32 const maxTargets = 3;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_divine_hymn::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 55677 - Glyph of Dispel Magic
class spell_pri_glyph_of_dispel_magic : public AuraScript
{
    PrepareAuraScript(spell_pri_glyph_of_dispel_magic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        // Dispel Magic shares spellfamilyflag with abolish disease
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || spellInfo->SpellIconID != 74)
            return;

        Unit* target = eventInfo.GetProcTarget();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(target->CountPctFromMaxHealth(aurEff->GetAmount()));
        eventInfo.GetActor()->CastSpell(target, SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_glyph_of_dispel_magic::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 55680 - Glyph of Prayer of Healing
class spell_pri_glyph_of_prayer_of_healing : public AuraScript
{
    PrepareAuraScript(spell_pri_glyph_of_prayer_of_healing);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        SpellInfo const* triggeredSpellInfo = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL);

        ASSERT(triggeredSpellInfo->GetMaxTicks() > 0);
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(healInfo->GetHeal(), aurEff->GetAmount()) / triggeredSpellInfo->GetMaxTicks());
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_glyph_of_prayer_of_healing::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public AuraScript
{
    PrepareAuraScript(spell_pri_guardian_spirit);

    uint32 healPct = 0;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL });
    }

    bool Load() override
    {
        healPct = GetEffectInfo(EFFECT_1).CalcValue();
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        // Set absorbtion amount to unlimited
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetDamage() < target->GetHealth())
            return;

        int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));
        // remove the aura now, we don't want 40% healing bonus
        Remove(AURA_REMOVE_BY_ENEMY_SPELL);
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(healAmount);
        target->CastSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, args);
        absorbAmount = dmgInfo.GetDamage();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_guardian_spirit::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_guardian_spirit::Absorb, EFFECT_1);
    }
};

// 64904 - Hymn of Hope
class spell_pri_hymn_of_hope : public SpellScript
{
    PrepareSpellScript(spell_pri_hymn_of_hope);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(PowerCheck(POWER_MANA));
        targets.remove_if(RaidCheck(GetCaster()));

        uint32 const maxTargets = 3;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::PowerPctOrderPred(POWER_MANA));
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_hymn_of_hope::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// -47569 - Improved Shadowform
class spell_pri_imp_shadowform : public AuraScript
{
    PrepareAuraScript(spell_pri_imp_shadowform);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (roll_chance_i(aurEff->GetAmount()))
            eventInfo.GetActor()->RemoveMovementImpairingAuras(true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_imp_shadowform::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -15337 - Improved Spirit Tap
class spell_pri_improved_spirit_tap : public AuraScript
{
    PrepareAuraScript(spell_pri_improved_spirit_tap);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PRIEST_SHADOW_WORD_DEATH_R1,
            SPELL_PRIEST_MIND_BLAST_R1
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
        {
            if (spellInfo->IsRankOf(sSpellMgr->AssertSpellInfo(SPELL_PRIEST_SHADOW_WORD_DEATH_R1)) ||
                spellInfo->IsRankOf(sSpellMgr->AssertSpellInfo(SPELL_PRIEST_MIND_BLAST_R1)))
                return true;
            else if (spellInfo->Id == SPELL_PRIEST_MIND_FLAY_DAMAGE)
                return roll_chance_i(50);
        }

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_improved_spirit_tap::CheckProc);
    }
};

// 40438 - Priest Tier 6 Trinket
class spell_pri_item_t6_trinket : public AuraScript
{
    PrepareAuraScript(spell_pri_item_t6_trinket);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PRIEST_DIVINE_BLESSING,
            SPELL_PRIEST_DIVINE_WRATH
        });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActor();
        if (eventInfo.GetSpellTypeMask() & PROC_SPELL_TYPE_HEAL)
            caster->CastSpell(nullptr, SPELL_PRIEST_DIVINE_BLESSING, aurEff);

        if (eventInfo.GetSpellTypeMask() & PROC_SPELL_TYPE_DAMAGE)
            caster->CastSpell(nullptr, SPELL_PRIEST_DIVINE_WRATH, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_item_t6_trinket::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 60123 - Lightwell
class spell_pri_lightwell : public SpellScript
{
    PrepareSpellScript(spell_pri_lightwell);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_LIGHTWELL_RENEW_R1,
                SPELL_PRIEST_LIGHTWELL_RENEW_R2,
                SPELL_PRIEST_LIGHTWELL_RENEW_R3,
                SPELL_PRIEST_LIGHTWELL_RENEW_R4,
                SPELL_PRIEST_LIGHTWELL_RENEW_R5,
                SPELL_PRIEST_LIGHTWELL_RENEW_R6
            });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsSummon())
            return;

        uint32 lightwellRenew = 0;
        switch (caster->GetEntry())
        {
            case PRIEST_LIGHTWELL_NPC_1:
                lightwellRenew = SPELL_PRIEST_LIGHTWELL_RENEW_R1;
                break;
            case PRIEST_LIGHTWELL_NPC_2:
                lightwellRenew = SPELL_PRIEST_LIGHTWELL_RENEW_R2;
                break;
            case PRIEST_LIGHTWELL_NPC_3:
                lightwellRenew = SPELL_PRIEST_LIGHTWELL_RENEW_R3;
                break;
            case PRIEST_LIGHTWELL_NPC_4:
                lightwellRenew = SPELL_PRIEST_LIGHTWELL_RENEW_R4;
                break;
            case PRIEST_LIGHTWELL_NPC_5:
                lightwellRenew = SPELL_PRIEST_LIGHTWELL_RENEW_R5;
                break;
            case PRIEST_LIGHTWELL_NPC_6:
                lightwellRenew = SPELL_PRIEST_LIGHTWELL_RENEW_R6;
                break;
            default:
                return;
        }

        // proc a spellcast
        if (Aura* chargesAura = caster->GetAura(SPELL_PRIEST_LIGHTWELL_CHARGES))
        {
            caster->CastSpell(GetHitUnit(), lightwellRenew, caster->ToTempSummon()->GetSummonerGUID());
            if (chargesAura->ModCharges(-1))
                caster->ToTempSummon()->UnSummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_lightwell::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// -7001 - Lightwell Renew
class spell_pri_lightwell_renew : public AuraScript
{
    PrepareAuraScript(spell_pri_lightwell_renew);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
        {
            // Bonus from Glyph of Lightwell
            if (AuraEffect* modHealing = caster->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_LIGHTWELL, EFFECT_0))
                AddPct(amount, modHealing->GetAmount());
        }
    }

    void InitializeAmount(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // Attacks done to you equal to 30% of your total health will cancel the effect
        _remainingAmount = GetTarget()->CountPctFromMaxHealth(30);
    }

    void CheckDropCharge(ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo)
            return;

        uint32 damage = damageInfo->GetDamage();
        if (_remainingAmount <= damage)
            return;

        _remainingAmount -= damage;
        // prevent drop charge
        PreventDefaultAction();
    }

    void Register() override
    {
        DoPrepareProc += AuraProcFn(spell_pri_lightwell_renew::CheckDropCharge);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_lightwell_renew::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);

        AfterEffectApply += AuraEffectApplyFn(spell_pri_lightwell_renew::InitializeAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }

    uint32 _remainingAmount = 0;
};

// 28305 - Mana Leech (Passive) (Priest Pet Aura)
class spell_pri_mana_leech : public AuraScript
{
    PrepareAuraScript(spell_pri_mana_leech);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_MANA_LEECH_PROC });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        _procTarget = GetTarget()->GetOwner();
        return _procTarget != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(_procTarget, SPELL_PRIEST_MANA_LEECH_PROC, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_mana_leech::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_mana_leech::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    Unit* _procTarget = nullptr;
};

// -49821 - Mind Sear
class spell_pri_mind_sear : public SpellScript
{
    PrepareSpellScript(spell_pri_mind_sear);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if(Trinity::ObjectGUIDCheck(GetCaster()->GetChannelObjectGuid()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_mind_sear::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// -47580 - Pain and Suffering (dummy aura)
class spell_pri_pain_and_suffering_dummy : public AuraScript
{
    PrepareAuraScript(spell_pri_pain_and_suffering_dummy);

    bool CheckDummy(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        return false;
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pri_pain_and_suffering_dummy::CheckDummy, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 47948 - Pain and Suffering (Proc)
class spell_pri_pain_and_suffering_proc : public SpellScript
{
    PrepareSpellScript(spell_pri_pain_and_suffering_proc);

    void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        // Refresh Shadow Word: Pain on target
        if (Unit* target = GetHitUnit())
        {
            if (AuraEffect* aur = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, caster->GetGUID()))
            {
                aur->ChangeAmount(aur->CalculateAmount(aur->GetCaster()), false);
                aur->CalculatePeriodic(caster, false, false);
                aur->GetBase()->RefreshDuration();
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_pain_and_suffering_proc::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// -47540 - Penance
class spell_pri_penance : public SpellScript
{
    PrepareSpellScript(spell_pri_penance);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PRIEST_PENANCE_R1);
        if (!firstRankSpellInfo)
            return false;

        // can't use other spell than this penance due to spell_ranks dependency
        if (!spellInfo->IsRankOf(firstRankSpellInfo))
            return false;

        uint8 rank = spellInfo->GetRank();
        if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank, true))
            return false;
        if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank, true))
            return false;

        return true;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            if (!unitTarget->IsAlive())
                return;

            uint8 rank = GetSpellInfo()->GetRank();

            if (caster->IsFriendlyTo(unitTarget))
                caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank), TRIGGERED_DISALLOW_PROC_EVENTS);
            else
                caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank), TRIGGERED_DISALLOW_PROC_EVENTS);
        }
    }

    SpellCastResult CheckCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (Unit* target = GetExplTargetUnit())
            if (!caster->IsFriendlyTo(target))
            {
                if (!caster->IsValidAttackTarget(target))
                    return SPELL_FAILED_BAD_TARGETS;
                if (!caster->isInFront(target))
                    return SPELL_FAILED_UNIT_NOT_INFRONT;
            }
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_penance::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_pri_penance::CheckCast);
    }
};

// -17 - Power Word: Shield
class spell_pri_power_word_shield : public SpellScript
{
    PrepareSpellScript(spell_pri_power_word_shield);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->ExcludeTargetAuraSpell });
    }

    void WeakenSoul()
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, GetSpellInfo()->ExcludeTargetAuraSpell, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_pri_power_word_shield::WeakenSoul);
    }
};

class spell_pri_power_word_shield_aura : public AuraScript
{
    PrepareAuraScript(spell_pri_power_word_shield_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED,
            SPELL_PRIEST_REFLECTIVE_SHIELD_R1
        });
    }

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            // +80.68% from sp bonus
            float bonus = 0.8068f;

            // Borrowed Time
            if (AuraEffect const* borrowedTime = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_BORROWED_TIME, EFFECT_1))
                bonus += CalculatePct(1.0f, borrowedTime->GetAmount());

            bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());

            // Improved PW: Shield: its weird having a SPELLMOD_ALL_EFFECTS here but its blizzards doing :)
            // Improved PW: Shield is only applied at the spell healing bonus because it was already applied to the base value in CalculateSpellDamage
            bonus = caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), bonus);
            bonus *= caster->CalculateSpellpowerCoefficientLevelPenalty(GetSpellInfo());

            amount += int32(bonus);

            // Twin Disciplines
            if (AuraEffect const* twinDisciplines = caster->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_PRIEST, 0x400000, 0, 0, GetCasterGUID()))
                AddPct(amount, twinDisciplines->GetAmount());

            // Focused Power
            if (AuraEffect const* focusedPower = caster->GetAuraEffect(SPELL_AURA_MOD_HEALING_DONE_PERCENT, SPELLFAMILY_PRIEST, PRIEST_ICON_ID_FOCUSED_POWER, EFFECT_2))
                AddPct(amount, focusedPower->GetAmount());

            // Arena - Dampening
            if (AuraEffect const* auraEffArenaDampening = caster->GetAuraEffect(SPELL_GENERIC_ARENA_DAMPENING, EFFECT_0))
                AddPct(amount, auraEffArenaDampening->GetAmount());
            // Battleground - Dampening
            else if (AuraEffect const* auraEffBattlegroudDampening = caster->GetAuraEffect(SPELL_GENERIC_BATTLEGROUND_DAMPENING, EFFECT_0))
                AddPct(amount, auraEffBattlegroudDampening->GetAmount());

            // ICC buff
            if (AuraEffect const* auraStrengthOfWrynn = caster->GetAuraEffect(SPELL_AURA_MOD_HEALING_DONE_PERCENT, SPELLFAMILY_GENERIC, SPELL_ICON_ID_STRENGTH_OF_WRYNN, EFFECT_2))
                AddPct(amount, auraStrengthOfWrynn->GetAmount());
            else if (AuraEffect const* auraHellscreamsWarsong = caster->GetAuraEffect(SPELL_AURA_MOD_HEALING_DONE_PERCENT, SPELLFAMILY_GENERIC, SPELL_ICON_ID_HELLSCREAM_WARSONG, EFFECT_2))
                AddPct(amount, auraHellscreamsWarsong->GetAmount());
        }
    }

    void ReflectDamage(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetAttacker() == target)
            return;

        // Don't try to reflect the reflect spell
        if (dmgInfo.GetSpellInfo() && dmgInfo.GetSpellInfo()->Id == SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED)
            return;

        if (AuraEffect* talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_PRIEST_REFLECTIVE_SHIELD_R1, EFFECT_0))
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(CalculatePct(absorbAmount, talentAurEff->GetAmount()));
            target->CastSpell(dmgInfo.GetAttacker(), SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED, args);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_power_word_shield_aura::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_pri_power_word_shield_aura::ReflectDamage, EFFECT_0);
    }
};

// 33110 - Prayer of Mending Heal
class spell_pri_prayer_of_mending_heal : public SpellScript
{
    PrepareSpellScript(spell_pri_prayer_of_mending_heal);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_T9_HEALING_2P,
                SPELL_PRIEST_TWIN_DISCIPLINE_R1,
                SPELL_PRIEST_SPIRITUAL_HEALING_R1,
                SPELL_PRIEST_DIVINE_PROVIDENCE_R1
            });
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetOriginalCaster())
        {
            int32 heal = GetEffectValue();
            if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_PRIEST_T9_HEALING_2P, EFFECT_0))
                AddPct(heal, aurEff->GetAmount());

            if (AuraEffect* aurEff = caster->GetAuraEffectOfRankedSpell(SPELL_PRIEST_TWIN_DISCIPLINE_R1, EFFECT_0))
                AddPct(heal, aurEff->GetAmount());

            if (AuraEffect* aurEff = caster->GetAuraEffectOfRankedSpell(SPELL_PRIEST_SPIRITUAL_HEALING_R1, EFFECT_0))
                AddPct(heal, aurEff->GetAmount());

            if (AuraEffect* aurEff = caster->GetAuraEffectOfRankedSpell(SPELL_PRIEST_DIVINE_PROVIDENCE_R1, EFFECT_0))
                AddPct(heal, aurEff->GetAmount());

            SetEffectValue(heal);
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_pri_prayer_of_mending_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// -139 - Renew
class spell_pri_renew : public AuraScript
{
    PrepareAuraScript(spell_pri_renew);

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_EMPOWERED_RENEW });
    }

    void HandleApplyEffect(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Empowered Renew
        if (AuraEffect const* empoweredRenewAurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_EMPOWERED_RENEW_TALENT, EFFECT_1))
        {
            int32 heal = aurEff->GetAmount();
            heal *= aurEff->GetTotalTicks();

            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(CalculatePct(heal, empoweredRenewAurEff->GetAmount()));
            caster->CastSpell(GetTarget(), SPELL_PRIEST_EMPOWERED_RENEW, args);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_pri_renew::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 57989 - Shadowfiend Death
class spell_pri_shadowfiend_death : public AuraScript
{
    PrepareAuraScript(spell_pri_shadowfiend_death);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GLYPH_OF_SHADOWFIEND_MANA });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return false;

        Unit* shadowfiend = eventInfo.GetActionTarget();
        if (!shadowfiend->GetOwner())
            return false;

        return shadowfiend->HealthBelowPctDamaged(1, damageInfo->GetDamage());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActionTarget()->GetOwner();
        caster->CastSpell(caster, SPELL_PRIEST_GLYPH_OF_SHADOWFIEND_MANA, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_shadowfiend_death::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_shadowfiend_death::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -32379 - Shadow Word Death
class spell_pri_shadow_word_death : public SpellScript
{
    PrepareSpellScript(spell_pri_shadow_word_death);

    void HandleDamage()
    {
        int32 damage = GetHitDamage();

        // Pain and Suffering reduces damage
        if (AuraEffect* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_PAIN_AND_SUFFERING, EFFECT_1))
            AddPct(damage, aurEff->GetAmount());

        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(damage);
        GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_SHADOW_WORD_DEATH, args);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_pri_shadow_word_death::HandleDamage);
    }
};

// 15286 - Vampiric Embrace
class spell_pri_vampiric_embrace : public AuraScript
{
    PrepareAuraScript(spell_pri_vampiric_embrace);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        int32 selfHeal = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
        int32 partyHeal = selfHeal / 5;
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(partyHeal);
        args.AddSpellMod(SPELLVALUE_BASE_POINT1, selfHeal);
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_embrace::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -34914 - Vampiric Touch
class spell_pri_vampiric_touch : public AuraScript
{
    PrepareAuraScript(spell_pri_vampiric_touch);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL,
            SPELL_REPLENISHMENT
        });
    }

    bool CheckDummy(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        return false;
    }

    void HandleDispel(DispelInfo* /*dispelInfo*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetUnitOwner())
            {
                if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                {
                    // backfire damage
                    int32 bp = aurEff->GetAmount();
                    bp = target->SpellDamageBonusTaken(caster, aurEff->GetSpellInfo(), bp, DOT);
                    bp *= 8;

                    CastSpellExtraArgs args(aurEff);
                    args.AddSpellBP0(bp);
                    caster->CastSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, args);
                }
            }
        }
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_REPLENISHMENT, aurEff);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_pri_vampiric_touch::CheckDummy, EFFECT_0, SPELL_AURA_DUMMY);

        AfterDispel += AuraDispelFn(spell_pri_vampiric_touch::HandleDispel);
        OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_touch::HandleProc, EFFECT_2, SPELL_AURA_DUMMY);
    }
};

// 28809 - Greater Heal
class spell_pri_t3_4p_bonus : public AuraScript
{
    PrepareAuraScript(spell_pri_t3_4p_bonus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ARMOR_OF_FAITH });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_ARMOR_OF_FAITH, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_t3_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 37594 - Greater Heal Refund
class spell_pri_t5_heal_2p_bonus : public AuraScript
{
    PrepareAuraScript(spell_pri_t5_heal_2p_bonus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ITEM_EFFICIENCY });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (HealInfo* healInfo = eventInfo.GetHealInfo())
            if (Unit* healTarget = healInfo->GetTarget())
                if (healInfo->GetEffectiveHeal())
                    if (healTarget->GetHealth() >= healTarget->GetMaxHealth())
                        return true;

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_t5_heal_2p_bonus::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_t5_heal_2p_bonus::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 70770 - Item - Priest T10 Healer 2P Bonus
class spell_pri_t10_heal_2p_bonus : public AuraScript
{
    PrepareAuraScript(spell_pri_t10_heal_2p_bonus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_BLESSED_HEALING });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        HealInfo* healInfo = eventInfo.GetHealInfo();
        if (!healInfo || !healInfo->GetHeal())
            return;

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_BLESSED_HEALING);
        int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_PRIEST_BLESSED_HEALING, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_t10_heal_2p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 10060 - Power Infusion
class spell_pri_power_infusion : public SpellScript
{
    PrepareSpellScript(spell_pri_power_infusion);

    SpellCastResult CheckCast()
    {
        if (Unit* target = GetExplTargetUnit())
            if (target->HasAura(SPELL_MAGE_ARCANE_POWER))
                return SPELL_FAILED_AURA_BOUNCED;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pri_power_infusion::CheckCast);
    }
};

void AddSC_priest_spell_scripts()
{
    RegisterSpellScript(spell_pri_aq_3p_bonus);
    RegisterSpellScript(spell_pri_blessed_recovery);
    RegisterSpellScript(spell_pri_body_and_soul);
    RegisterSpellScript(spell_pri_circle_of_healing);
    RegisterSpellScript(spell_pri_divine_aegis);
    RegisterSpellScript(spell_pri_divine_hymn);
    RegisterSpellScript(spell_pri_glyph_of_dispel_magic);
    RegisterSpellScript(spell_pri_glyph_of_prayer_of_healing);
    RegisterSpellScript(spell_pri_guardian_spirit);
    RegisterSpellScript(spell_pri_hymn_of_hope);
    RegisterSpellScript(spell_pri_imp_shadowform);
    RegisterSpellScript(spell_pri_improved_spirit_tap);
    RegisterSpellScript(spell_pri_item_t6_trinket);
    RegisterSpellScript(spell_pri_lightwell);
    RegisterSpellScript(spell_pri_lightwell_renew);
    RegisterSpellScript(spell_pri_mana_leech);
    RegisterSpellScript(spell_pri_mind_sear);
    RegisterSpellScript(spell_pri_pain_and_suffering_dummy);
    RegisterSpellScript(spell_pri_pain_and_suffering_proc);
    RegisterSpellScript(spell_pri_penance);
    RegisterSpellAndAuraScriptPair(spell_pri_power_word_shield, spell_pri_power_word_shield_aura);
    RegisterSpellScript(spell_pri_prayer_of_mending_heal);
    RegisterSpellScript(spell_pri_renew);
    RegisterSpellScript(spell_pri_shadowfiend_death);
    RegisterSpellScript(spell_pri_shadow_word_death);
    RegisterSpellScript(spell_pri_vampiric_embrace);
    RegisterSpellScript(spell_pri_vampiric_touch);
    RegisterSpellScript(spell_pri_t3_4p_bonus);
    RegisterSpellScript(spell_pri_t5_heal_2p_bonus);
    RegisterSpellScript(spell_pri_t10_heal_2p_bonus);
    RegisterSpellScript(spell_pri_power_infusion);
}
