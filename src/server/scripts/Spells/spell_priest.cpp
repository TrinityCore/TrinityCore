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
#include "GridNotifiers.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum PriestSpells
{
    SPELL_PRIEST_ABSOLUTION                         = 33167,
    SPELL_PRIEST_ARCHANGEL_DUMMY                    = 94709,
    SPELL_PRIEST_ARCHANGEL_TRIGGERED                = 81700,
    SPELL_PRIEST_ARCHANGEL_ENERGIZE                 = 87152,
    SPELL_PRIEST_ATONEMENT_TRIGGERED_LARGE          = 81751,
    SPELL_PRIEST_ATONEMENT_TRIGGERED_DEFAULT        = 94472,
    SPELL_PRIEST_BODY_AND_SOUL_DISPEL               = 64136,
    SPELL_PRIEST_BODY_AND_SOUL_SPEED                = 65081,
    SPELL_PRIEST_CHAKRA_SERENITY                    = 81208,
    SPELL_PRIEST_CHAKRA_SANCTUARY                   = 81206,
    SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED            = 81207,
    SPELL_PRIEST_CHAKRA_CHASTISE                    = 81209,
    SPELL_PRIEST_CHAKRA_FLOW                        = 89912,
    SPELL_PRIEST_CURE_DISEASE                       = 528,
    SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED           = 87153,
    SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_1        = 87117,
    SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_2        = 87118,
    SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY              = 97690,
    SPELL_PRIEST_DISPEL_MAGIC_HOSTILE               = 97691,
    SPELL_PRIEST_DIVINE_AEGIS                       = 47753,
    SPELL_PRIEST_DIVINE_TOUCH                       = 63544,
    SPELL_PRIEST_ECHO_OF_LIGHT                      = 77489,
    SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY         = 87154,
    SPELL_PRIEST_EVANGELISM_R1                      = 81659,
    SPELL_PRIEST_EVANGELISM_TRIGGERED_1             = 81660,
    SPELL_PRIEST_EVANGELISM_TRIGGERED_2             = 81661,
    SPELL_PRIEST_EMPOWERED_SHADOW                   = 95799,
    SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING         = 55675,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC              = 55677,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL         = 56131,
    SPELL_PRIEST_GLYPH_OF_LIGHTWELL                 = 55673,
    SPELL_PRIEST_GLYPH_OF_POWER_WORD_SHIELD         = 55672,
    SPELL_PRIEST_GLYPH_OF_POWER_WORD_SHIELD_HEAL    = 56160,
    SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL    = 56161,
    SPELL_PRIEST_GLYPH_OF_SHADOW                    = 107906,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_HOLY_WORD_CHASTISE                 = 88625,
    SPELL_PRIEST_HOLY_WORD_SANCTUARY                = 88686,
    SPELL_PRIEST_INDULGENCE_OF_THE_PENITENT         = 89913,
    SPELL_PRIEST_INNER_FOCUS                        = 89485,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_ITEM_T11_HEALER_4P_BONUS           = 89911,
    SPELL_PRIEST_LEAP_OF_FAITH                      = 73325,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT               = 92832,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT_TRIGGER       = 92833,
    SPELL_PRIEST_LEAP_OF_FAITH_TRIGGERED            = 92572,
    SPELL_PRIEST_MANA_LEECH_PROC                    = 34650,
    SPELL_PRIEST_MIND_FLAY                          = 15407,
    SPELL_PRIEST_MIND_TRAUMA                        = 48301,
    SPELL_PRIEST_PENANCE_DAMAGE                     = 47758,
    SPELL_PRIEST_PENANCE_HEAL                       = 47757,
    SPELL_PRIEST_REFLECTIVE_SHIELD_R1               = 33201,
    SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED        = 33619,
    SPELL_PRIEST_RENEW                              = 139,
    SPELL_PRIEST_REVELATIONS                        = 88627,
    SPELL_PRIEST_SHADOW_ORB_MARKER                  = 93683,
    SPELL_PRIEST_SHADOW_ORB_POWER                   = 77486,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH    = 107903,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH       = 107904,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409,
    SPELL_PRIEST_SPIRIT_OF_REDEMPTION_TRIGGERED     = 27827,
    SPELL_PRIEST_STRENGTH_OF_SOUL_R1                = 89488,
    SPELL_PRIEST_STRENGTH_OF_SOUL_TRIGGERED_R1      = 96266,
    SPELL_PRIEST_STRENGTH_OF_SOUL_TRIGGERED_R2      = 96267,
    SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1            = 47586,
    SPELL_PRIEST_T9_HEALING_2P                      = 67201,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 64085,
    SPELL_PRIEST_WEAKENED_SOUL                      = 6788
};

enum PriestSpellIcons
{
    PRIEST_ICON_ID_BORROWED_TIME                    = 2899,
    PRIEST_ICON_ID_DIVINE_TOUCH_TALENT              = 3021,
    PRIEST_ICON_ID_PAIN_AND_SUFFERING               = 2874,
    PRIEST_ICON_ID_SHIELD_DISCIPLINE                = 566,
    PRIEST_ICON_ID_GLYPH_OF_POWER_WORD_BARRIER      = 3837,
    PRIEST_ICON_ID_GLYPH_OF_POWER_WORD_SHIELD       = 566,
    PRIEST_ICON_ID_HARNESSED_SHADOWS                = 554,
    PRIEST_ICON_ID_IMPROVED_MIND_BLAST              = 95,
    PRIEST_ICON_ID_MIND_MELT                        = 3139,
    PRIEST_ICON_ID_SHADOW_ORB                       = 4941
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669
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

class spell_pri_body_and_soul : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_CURE_DISEASE,
                SPELL_PRIEST_BODY_AND_SOUL_DISPEL
            });
    }

    void HandleEffectSpeedProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        // Proc only with Power Word: Shield or Leap of Faith
        if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[0] & 0x1 || eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[2] & 0x80000))
            return;

        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_BODY_AND_SOUL_SPEED, CastSpellExtraArgs(aurEff).AddSpellBP0(aurEff->GetAmount()));
    }

    void HandleEffectDispelProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        // Proc only with Cure Disease
        if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PRIEST_CURE_DISEASE || eventInfo.GetProcTarget() != GetTarget())
            return;

        if (roll_chance_i(aurEff->GetAmount()))
            GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_BODY_AND_SOUL_DISPEL, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_body_and_soul::HandleEffectSpeedProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc.Register(&spell_pri_body_and_soul::HandleEffectDispelProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 34861 - Circle of Healing
class spell_pri_circle_of_healing : public SpellScript
{
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
        OnObjectAreaTargetSelect.Register(&spell_pri_circle_of_healing::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// 527 - Dispel magic
class spell_pri_dispel_magic : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_ABSOLUTION,
                SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL,
                SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC
            });
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        Unit* target = GetExplTargetUnit();

        if (!target || (!caster->HasAura(SPELL_PRIEST_ABSOLUTION) && caster != target && target->IsFriendlyTo(caster)))
            return SPELL_FAILED_BAD_TARGETS;
        return SPELL_CAST_OK;
    }

    void AfterEffectHit(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->IsFriendlyTo(GetCaster()))
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY, true);
            if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC, EFFECT_0))
            {
                int32 heal = GetHitUnit()->CountPctFromMaxHealth(aurEff->GetAmount());
                GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL, CastSpellExtraArgs().AddSpellBP0(heal));
            }
        }
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_HOSTILE, true);
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_pri_dispel_magic::CheckCast);
        OnEffectHitTarget.Register(&spell_pri_dispel_magic::AfterEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -47509 - Divine Aegis
class spell_pri_divine_aegis : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_DIVINE_AEGIS });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (!eventInfo.GetProcTarget() || !eventInfo.GetSpellInfo())
            return false;

        // Prayer of Healing always triggers Divine Aegis
        if (eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & 0x200)
            return true;

        return (eventInfo.GetHitMask() & PROC_HIT_CRITICAL);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        int32 absorb = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

        // Multiple effects stack, so let's try to find this aura.
        if (AuraEffect const* aegis = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_PRIEST_DIVINE_AEGIS, EFFECT_0))
            absorb += aegis->GetAmount();

        if (AuraEffect const* shieldDiscipline = GetTarget()->GetDummyAuraEffect(SPELLFAMILY_HUNTER, PRIEST_ICON_ID_SHIELD_DISCIPLINE, EFFECT_0))
            AddPct(absorb, shieldDiscipline->GetAmount());

        absorb = std::min(absorb, int32(CalculatePct(eventInfo.GetProcTarget()->GetMaxHealth(), 40)));

        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_DIVINE_AEGIS, CastSpellExtraArgs(aurEff).AddSpellBP0(absorb));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_pri_divine_aegis::CheckProc);
        OnEffectProc.Register(&spell_pri_divine_aegis::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 64844 - Divine Hymn
class spell_pri_divine_hymn : public SpellScript
{
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
        OnObjectAreaTargetSelect.Register(&spell_pri_divine_hymn::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 55680 - Glyph of Prayer of Healing
class spell_pri_glyph_of_prayer_of_healing : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        SpellInfo const* triggeredSpellInfo = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL);
        int32 heal = int32(CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount()) / triggeredSpellInfo->GetMaxTicks());
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(heal));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_glyph_of_prayer_of_healing::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_pri_improved_power_word_shield : public AuraScript
{
    void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
    {
        if (!spellMod)
        {
            spellMod = new SpellModifier(GetAura());
            spellMod->op = SpellModOp(aurEff->GetMiscValue());
            spellMod->type = SPELLMOD_PCT;
            spellMod->spellId = GetId();
            spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
        }

        spellMod->value = aurEff->GetAmount();
    }

    void Register() override
    {
        DoEffectCalcSpellMod.Register(&spell_pri_improved_power_word_shield::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 37594 - Greater Heal Refund
class spell_pri_item_greater_heal_refund : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ITEM_EFFICIENCY });
    }

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_item_greater_heal_refund::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL });
    }

    bool Load() override
    {
        healPct = GetSpellInfo()->Effects[EFFECT_1].BasePoints;
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetDamage() < target->GetHealth())
            return;

        int32 healAmount = target->CountPctFromMaxHealth(healPct);
        // Negate the heal bonus. We don't want it for our following heal
        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
            aurEff->SetAmount(0);

        target->CastSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, CastSpellExtraArgs(true).AddSpellBP0(healAmount));
        absorbAmount = dmgInfo.GetDamage();
        Remove();
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_pri_guardian_spirit::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb.Register(&spell_pri_guardian_spirit::Absorb, EFFECT_1);
    }

private:
    uint32 healPct;
};

// 64904 - Hymn of Hope
class spell_pri_hymn_of_hope : public SpellScript
{
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
        OnObjectAreaTargetSelect.Register(&spell_pri_hymn_of_hope::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 92833 - Leap of Faith
class spell_pri_leap_of_faith_effect_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_LEAP_OF_FAITH_EFFECT });
    }

    void HandleEffectDummy(SpellEffIndex /*effIndex*/)
    {
        Position destPos = GetHitDest()->GetPosition();

        SpellCastTargets targets;
        targets.SetDst(destPos);
        targets.SetUnitTarget(GetCaster());
        GetHitUnit()->CastSpell(targets, GetEffectValue());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_leap_of_faith_effect_trigger::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 7001 - Lightwell Renew
class spell_pri_lightwell_renew : public AuraScript
{
    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
        {
            // Bonus from Glyph of Lightwell
            if (AuraEffect* modHealing = caster->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_LIGHTWELL, EFFECT_0))
                AddPct(amount, modHealing->GetAmount());
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_pri_lightwell_renew::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

// 28305 - Mana Leech (Passive) (Priest Pet Aura)
class spell_pri_mana_leech : public AuraScript
{
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
        DoCheckProc.Register(&spell_pri_mana_leech::CheckProc);
        OnEffectProc.Register(&spell_pri_mana_leech::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    Unit* _procTarget = nullptr;
};

// 49821 - Mind Sear
class spell_pri_mind_sear : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove_if(Trinity::ObjectGUIDCheck(GetCaster()->GetChannelObjectGuid()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_pri_mind_sear::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// 47948 - Pain and Suffering (Proc)
class spell_pri_pain_and_suffering_proc : public SpellScript
{
    void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Refresh Shadow Word: Pain duration on target
        if (AuraEffect* aur = GetHitUnit()->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, caster->GetGUID()))
            aur->GetBase()->RefreshDuration();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_pain_and_suffering_proc::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 47540 - Penance
class spell_pri_penance : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_PENANCE_DAMAGE,
                SPELL_PRIEST_PENANCE_HEAL,
                SPELL_PRIEST_ITEM_T11_HEALER_4P_BONUS,
                SPELL_PRIEST_INDULGENCE_OF_THE_PENITENT
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            if (!unitTarget->IsAlive())
                return;

            if (caster->IsFriendlyTo(unitTarget))
            {
                caster->CastSpell(unitTarget, SPELL_PRIEST_PENANCE_HEAL, TRIGGERED_DISALLOW_PROC_EVENTS);

                // T11 Bonus
                if (caster->GetAuraEffect(SPELL_PRIEST_ITEM_T11_HEALER_4P_BONUS, EFFECT_0))
                    caster->CastSpell(caster, SPELL_PRIEST_INDULGENCE_OF_THE_PENITENT, true);
            }
            else
                caster->CastSpell(unitTarget, SPELL_PRIEST_PENANCE_DAMAGE, TRIGGERED_DISALLOW_PROC_EVENTS);
        }
    }

    SpellCastResult CheckCast()
    {
        Player* caster = GetCaster()->ToPlayer();
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
        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_penance::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast.Register(&spell_pri_penance::CheckCast);
    }
};

// -47569 - Phantasm
class spell_pri_phantasm : public AuraScript
{
    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->RemoveMovementImpairingAuras();
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_pri_phantasm::CheckProc);
        OnEffectProc.Register(&spell_pri_phantasm::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 17 - Power Word: Shield
class spell_pri_power_word_shield : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_WEAKENED_SOUL });
    }

    void HandleWeakenedSoul(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_PRIEST_WEAKENED_SOUL, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_power_word_shield::HandleWeakenedSoul, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_pri_power_word_shield_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED,
                SPELL_PRIEST_REFLECTIVE_SHIELD_R1,
                SPELL_PRIEST_GLYPH_OF_POWER_WORD_SHIELD,
                SPELL_PRIEST_GLYPH_OF_POWER_WORD_SHIELD_HEAL
            });
    }

    void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            // +87% from sp bonus
            float bonus = 0.87f;

            // Borrowed Time
            if (AuraEffect const* borrowedTime = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_BORROWED_TIME, EFFECT_1))
                bonus += CalculatePct(1.0f, borrowedTime->GetAmount());

            bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());

            // Improved PW: Shield: its weird having a SPELLMOD_ALL_EFFECTS here but its blizzards doing :)
            // Improved PW: Shield is only applied at the spell healing bonus because it was already applied to the base value in CalculateSpellDamage
            bonus = caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), bonus);

            amount += int32(bonus);

            // Twin Disciplines
            if (AuraEffect const* twinDisciplines = caster->GetAuraEffectOfRankedSpell(SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1, EFFECT_1))
                AddPct(amount, twinDisciplines->GetAmount());

            // Focused Power
            amount *= caster->GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_DONE_PERCENT);

            // Mastery: Shield Discipline
            if (AuraEffect const* shieldDiscipline = caster->GetDummyAuraEffect(SPELLFAMILY_HUNTER, PRIEST_ICON_ID_SHIELD_DISCIPLINE, EFFECT_0))
                AddPct(amount, shieldDiscipline->GetAmount());

            // Glyph of Power Word: Shield
            if (Unit* target = GetUnitOwner())
            {
                if (AuraEffect const* glyphEff = caster->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_POWER_WORD_SHIELD, EFFECT_0))
                {
                    int32 bp = CalculatePct(amount, glyphEff->GetAmount());
                    caster->CastSpell(target, SPELL_PRIEST_GLYPH_OF_POWER_WORD_SHIELD_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
                }
            }
        }
    }

    void ReflectDamage(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetAttacker() == target)
            return;

        if (AuraEffect const* talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_PRIEST_REFLECTIVE_SHIELD_R1, EFFECT_0))
        {
            int32 bp = CalculatePct(absorbAmount, talentAurEff->GetAmount());
            target->CastSpell(dmgInfo.GetAttacker(), SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_pri_power_word_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        AfterEffectAbsorb.Register(&spell_pri_power_word_shield_AuraScript::ReflectDamage, EFFECT_0);
    }
};

// 33110 - Prayer of Mending Heal
class spell_pri_prayer_of_mending_heal : public SpellScript
{
    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetOriginalCaster())
        {
            if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_PRIEST_T9_HEALING_2P, EFFECT_0))
            {
                int32 heal = GetHitHeal();
                AddPct(heal, aurEff->GetAmount());
                SetHitHeal(heal);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_prayer_of_mending_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 139 - Renew
class spell_pri_renew : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_DIVINE_TOUCH });
    }

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleApplyEffect(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            // Divine Touch
            if (AuraEffect const* empoweredRenewAurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_DIVINE_TOUCH_TALENT, EFFECT_0))
            {
                uint32 heal = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), aurEff->GetAmount(), DOT, aurEff->GetEffIndex());
                heal = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), heal, DOT);
                int32 basepoints0 = CalculatePct(int32(heal) * aurEff->GetTotalTicks(), empoweredRenewAurEff->GetAmount());
                caster->CastSpell(GetTarget(), SPELL_PRIEST_DIVINE_TOUCH, CastSpellExtraArgs(aurEff).AddSpellBP0(basepoints0));
            }
        }
    }

    void Register() override
    {
        OnEffectApply.Register(&spell_pri_renew::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 32379 - Shadow Word: Death
class spell_pri_shadow_word_death : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SHADOW_WORD_DEATH });
    }

    void HandleDamageBonus(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 damage = GetEffectValue();
        if (Unit* target = GetHitUnit())
        {
            // Shadow Word: Death deals three times the damage when hitting a target below 25% health
            if (target->GetHealthPct() < 25.f)
            {
                damage *= 3;

                // Mind Melt talent bonus
                if (AuraEffect const* effect = target->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_MIND_MELT, EFFECT_0))
                    AddPct(damage, effect->GetAmount());
            }
        }

        SetEffectValue(damage);
    }

    void HandleSelfDamagingEffect(SpellEffIndex /*effIndex*/)
    {
        int32 damage = GetHitDamage();

        // Pain and Suffering reduces damage
        if (AuraEffect* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_PAIN_AND_SUFFERING, EFFECT_1))
            AddPct(damage, aurEff->GetAmount());

        GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_SHADOW_WORD_DEATH, CastSpellExtraArgs(true).AddSpellBP0(damage));
    }

    void Register() override
    {
        OnEffectLaunchTarget.Register(&spell_pri_shadow_word_death::HandleDamageBonus, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget.Register(&spell_pri_shadow_word_death::HandleSelfDamagingEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 15473 - Shadowform
class spell_pri_shadowform : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH,
                SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH
            });
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH, true);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH);
        GetTarget()->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_pri_shadowform::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove.Register(&spell_pri_shadowform::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 15286 - Vampiric Embrace
class spell_pri_vampiric_embrace : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Not proc from Mind Sear
        return !(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x80000);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 self = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
        int32 team = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount() / 2));

        GetTarget()->CastSpell(nullptr, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, CastSpellExtraArgs(aurEff).AddSpellBP0(team).AddSpellMod(SPELLVALUE_BASE_POINT1, self));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_pri_vampiric_embrace::CheckProc);
        OnEffectProc.Register(&spell_pri_vampiric_embrace::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 15290 - Vampiric Embrace (heal)
class spell_pri_vampiric_embrace_target : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_pri_vampiric_embrace_target::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 34914 - Vampiric Touch
class spell_pri_vampiric_touch : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL,
                SPELL_GEN_REPLENISHMENT
            });
    }

    void HandleDispel(DispelInfo* /*dispelInfo*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = GetUnitOwner())
                if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                {
                    int32 damage = aurEff->GetAmount() * 8;
                    // backfire damage
                    caster->CastSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, CastSpellExtraArgs(aurEff).AddSpellBP0(damage));
                }
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget() == GetCaster();
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        eventInfo.GetProcTarget()->CastSpell(nullptr, SPELL_GEN_REPLENISHMENT, aurEff);
    }

    void Register() override
    {
        AfterDispel.Register(&spell_pri_vampiric_touch::HandleDispel);
        DoCheckProc.Register(&spell_pri_vampiric_touch::CheckProc);
        OnEffectProc.Register(&spell_pri_vampiric_touch::HandleEffectProc, EFFECT_2, SPELL_AURA_DUMMY);
    }
};

class spell_pri_echo_of_light : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_ECHO_OF_LIGHT,
                SPELL_PRIEST_HOLY_WORD_SANCTUARY
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id != SPELL_PRIEST_HOLY_WORD_SANCTUARY);
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (Unit* caster = GetCaster())
        {
            if (Unit* target = eventInfo.GetProcTarget())
            {
                uint32 healAmount = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
                uint8 tickNumber = sSpellMgr->GetSpellInfo(SPELL_PRIEST_ECHO_OF_LIGHT)->GetMaxTicks();
                if (healAmount && tickNumber)
                    caster->CastSpell(target, SPELL_PRIEST_ECHO_OF_LIGHT, CastSpellExtraArgs(aurEff).AddSpellBP0(int32(healAmount / tickNumber)));
            }
        }
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_pri_echo_of_light::CheckProc);
        OnEffectProc.Register(&spell_pri_echo_of_light::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 95740 - Shadow Orbs (Passive)
class spell_pri_shadow_orbs : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_SHADOW_ORB_POWER,
                spellInfo->Effects[EFFECT_0].TriggerSpell
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        // Do not proc when the target has Shadow Orb Power mastery active
        if (target->HasAura(SPELL_PRIEST_SHADOW_ORB_POWER, target->GetGUID()))
            return false;

        int32 procChance = 10;
        if (AuraEffect const* effect = target->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_PRIEST, PRIEST_ICON_ID_HARNESSED_SHADOWS, EFFECT_0))
            procChance += effect->GetAmount();

        return roll_chance_i(procChance);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        int32 basePoints = 10;
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, CastSpellExtraArgs(aurEff).AddSpellBP0(basePoints));
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_pri_shadow_orbs::CheckProc);
        OnEffectProc.Register(&spell_pri_shadow_orbs::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77486 - Shadow Orb Power (Passive)
class spell_pri_shadow_orb_power : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        int32 amount = 10 + aurEff->GetAmount();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, CastSpellExtraArgs(aurEff).AddSpellBP0(amount));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_shadow_orb_power::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 77487 - Shadow Orb
class spell_pri_shadow_orb : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_SHADOW_ORB_MARKER,
                SPELL_PRIEST_EMPOWERED_SHADOW
            });
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == GetSpellInfo()->StackAmount)
            GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_SHADOW_ORB_MARKER, true);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOW_ORB_MARKER);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        int32 bp = aurEff->GetAmount();
        target->CastSpell(target, SPELL_PRIEST_EMPOWERED_SHADOW, CastSpellExtraArgs(aurEff).AddSpellBP0(bp).AddSpellMod(SPELLVALUE_BASE_POINT1, bp));
        target->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOW_ORB_MARKER);
        Remove();
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_pri_shadow_orb::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove.Register(&spell_pri_shadow_orb::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectProc.Register(&spell_pri_shadow_orb::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 14751 - Chakra
class spell_pri_chakra : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_CHAKRA_SERENITY,
                SPELL_PRIEST_CHAKRA_SANCTUARY,
                SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED,
                SPELL_PRIEST_CHAKRA_CHASTISE,
                SPELL_PRIEST_CHAKRA_FLOW,
                SPELL_PRIEST_REVELATIONS,
                SPELL_PRIEST_HOLY_WORD_CHASTISE
            });
    }

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
        {
            target->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_SERENITY);
            target->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_SANCTUARY);
            target->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_CHASTISE);
        }
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActor();

        if (SpellInfo const* spell = eventInfo.GetSpellInfo())
        {
            // Chakra: Serenity
            if (spell->SpellFamilyFlags.HasFlag(0x00000400) || spell->SpellFamilyFlags.HasFlag(0x00001000)
                || spell->SpellFamilyFlags.HasFlag(0x00000800) || spell->SpellFamilyFlags.HasFlag(0, 0x00000004))
            {
                SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_CHAKRA_SERENITY);
                int32 bp = caster->HasAura(SPELL_PRIEST_REVELATIONS) ? spell->Effects[EFFECT_2].BasePoints : SPELL_PRIEST_HOLY_WORD_CHASTISE;

                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_SERENITY, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_BASE_POINT2, bp));
            }

            // Chakra: Sanctuary
            if (spell->SpellFamilyFlags.HasFlag(0x00000200) || spell->SpellFamilyFlags.HasFlag(0, 0x00000020))
            {
                SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_CHAKRA_SANCTUARY);
                int32 bp = caster->HasAura(SPELL_PRIEST_REVELATIONS) ? spell->Effects[EFFECT_2].BasePoints : SPELL_PRIEST_HOLY_WORD_CHASTISE;

                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_SANCTUARY, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_BASE_POINT2, bp));
                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED, aurEff);
            }

            // Chakra: Chastise
            if (spell->SpellFamilyFlags.HasFlag(0x00000080) || spell->SpellFamilyFlags.HasFlag(0, 0x00010000))
                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_CHASTISE, aurEff);

            // T11 Bonus
            if (caster->GetAuraEffect(SPELL_PRIEST_ITEM_T11_HEALER_4P_BONUS, EFFECT_0))
                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_FLOW);
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_pri_chakra::HandleEffectApply, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectProc.Register(&spell_pri_chakra::HandleProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
    }
};

// 81206 - Chakra: Sanctuary
class spell_pri_chakra_sanctuary : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED,
                SPELL_PRIEST_CHAKRA_FLOW
            });
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED);
        target->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_FLOW);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_pri_chakra_sanctuary::HandleEffectRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 81208 - Chakra: Serenety
// 81209 - Chakra: Chastise
class spell_pri_chakra_flow_removal: public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_CHAKRA_CHASTISE,
                SPELL_PRIEST_CHAKRA_SERENITY,
                SPELL_PRIEST_CHAKRA_FLOW
            });
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_FLOW);
    }

    void Register() override
    {
        if (m_scriptSpellId == SPELL_PRIEST_CHAKRA_SERENITY)
            AfterEffectRemove.Register(&spell_pri_chakra_flow_removal::HandleEffectRemove, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        else if (m_scriptSpellId == SPELL_PRIEST_CHAKRA_CHASTISE)
            AfterEffectRemove.Register(&spell_pri_chakra_flow_removal::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 81585 - Chakra: Serenity
class spell_pri_chakra_serenity_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_RENEW });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aura = GetHitUnit()->GetAura(SPELL_PRIEST_RENEW))
            aura->RefreshDuration();
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_chakra_serenity_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 88685 - Holy Word: Sanctuary
class spell_pri_holy_word_sanctuary : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_HOLY_WORD_SANCTUARY });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell({ dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ() }, SPELL_PRIEST_HOLY_WORD_SANCTUARY, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_DISALLOW_PROC_EVENTS)).SetTriggeringAura(aurEff));
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_pri_holy_word_sanctuary::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 88686 - Holy Word: Sanctuary
class spell_pri_holy_word_sanctuary_triggered : public SpellScript
{
    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (GetHitHeal() && _targets > 6)
            SetHitHeal((GetHitHeal() * 6) / _targets);
    }

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        _targets = unitList.size();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_pri_holy_word_sanctuary_triggered::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_pri_holy_word_sanctuary_triggered::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }

private:
    uint32 _targets = 0;
};

// -81659 - Evangelism
class spell_pri_evangelism : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_EVANGELISM_R1,
                SPELL_PRIEST_EVANGELISM_TRIGGERED_1,
                SPELL_PRIEST_EVANGELISM_TRIGGERED_2,
                SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_1,
                SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_2,
                SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY,
                SPELL_PRIEST_ARCHANGEL_DUMMY
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();

        uint32 spellId = SPELL_PRIEST_EVANGELISM_TRIGGERED_1;
        if (GetSpellInfo()->Id != SPELL_PRIEST_EVANGELISM_R1)
            spellId = SPELL_PRIEST_EVANGELISM_TRIGGERED_2;

        if (eventInfo.GetSpellInfo()->Id == SPELL_PRIEST_MIND_FLAY)
            spellId = spellId == SPELL_PRIEST_EVANGELISM_TRIGGERED_1 ?
            SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_1 : SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_2;

        target->CastSpell(target, spellId, aurEff);
        target->CastSpell(target, SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY, aurEff);

        if (Aura* aura = target->GetAura(spellId))
            if (aura->GetStackAmount() == aura->GetSpellInfo()->StackAmount)
                target->CastSpell(target, SPELL_PRIEST_ARCHANGEL_DUMMY, aurEff);
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_evangelism::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 81660, 81661 - Evangelism (Triggered Effect) / 87117, 87118 - Dark Evangelism (Triggered Effect)
class spell_pri_evangelism_triggered : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY,
                SPELL_PRIEST_ARCHANGEL_DUMMY
            });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->RemoveAurasDueToSpell(SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY);
        target->RemoveAurasDueToSpell(SPELL_PRIEST_ARCHANGEL_DUMMY);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_pri_evangelism_triggered::AfterRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 87151 - Archangel
class spell_pri_archangel : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_ARCHANGEL_TRIGGERED,
                SPELL_PRIEST_ARCHANGEL_ENERGIZE,
                SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED,
                SPELL_PRIEST_EVANGELISM_TRIGGERED_1,
                SPELL_PRIEST_EVANGELISM_TRIGGERED_2,
                SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_1,
                SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_2,
                SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY,
                SPELL_PRIEST_ARCHANGEL_DUMMY
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint32 spellId = 0;
        if (caster->HasAura(SPELL_PRIEST_EVANGELISM_TRIGGERED_1))
            spellId = SPELL_PRIEST_EVANGELISM_TRIGGERED_1;
        else if (caster->HasAura(SPELL_PRIEST_EVANGELISM_TRIGGERED_2))
            spellId = SPELL_PRIEST_EVANGELISM_TRIGGERED_2;
        else if (caster->HasAura(SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_1))
            spellId = SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_1;
        else if (caster->HasAura(SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_2))
            spellId = SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_2;

        Aura const* aura = caster->GetAura(spellId);
        if (!aura)
            return;

        uint8 stacks = aura->GetStackAmount();
        if (spellId == SPELL_PRIEST_EVANGELISM_TRIGGERED_1 || spellId == SPELL_PRIEST_EVANGELISM_TRIGGERED_2)
        {
            int32 bp = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_ARCHANGEL_TRIGGERED)->Effects[EFFECT_0].BasePoints * stacks;
            caster->CastSpell(caster, SPELL_PRIEST_ARCHANGEL_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(bp));
            caster->CastSpell(caster, SPELL_PRIEST_ARCHANGEL_ENERGIZE, CastSpellExtraArgs(true).AddSpellBP0(stacks));
        }
        else
        {
            SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED);
            int32 bp0 = spell->Effects[EFFECT_0].BasePoints * stacks;
            int32 bp1 = spell->Effects[EFFECT_1].BasePoints * stacks;
            int32 energize = spell->Effects[EFFECT_2].BasePoints * stacks;
            caster->CastSpell(caster, SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED, CastSpellExtraArgs(true).AddSpellBP0(bp0).AddSpellMod(SPELLVALUE_BASE_POINT1, bp1));
            caster->CastSpell(caster, SPELL_PRIEST_ARCHANGEL_ENERGIZE, CastSpellExtraArgs(true).AddSpellBP0(energize));
        }

        caster->RemoveAurasDueToSpell(spellId);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_archangel::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_power_word_barrier : public AuraScript
{
    bool Load() override
    {
        TempSummon* summon = GetCaster()->ToTempSummon();
        if (!summon)
            return false;

        Unit* summoner = summon->GetSummoner();
        if (!summoner)
            return false;

        _glyphEnabled = summoner->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_GLYPH_OF_POWER_WORD_BARRIER, EFFECT_0) != nullptr;

        return true;
    }

    void HandleGlyph(AuraEffect const* /*aurEff*/)
    {
        if (!_glyphEnabled)
            PreventDefaultAction();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_power_word_barrier::HandleGlyph, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }

private:
    bool _glyphEnabled = false;
};

// -89488 - Strength of Soul
class spell_pri_strength_of_soul : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_INNER_FOCUS,
                SPELL_PRIEST_STRENGTH_OF_SOUL_R1,
                SPELL_PRIEST_STRENGTH_OF_SOUL_TRIGGERED_R1,
                SPELL_PRIEST_STRENGTH_OF_SOUL_TRIGGERED_R2
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();

        if (eventInfo.GetSpellInfo()->Id == SPELL_PRIEST_INNER_FOCUS)
        {
            if (aurEff->GetId() == SPELL_PRIEST_STRENGTH_OF_SOUL_R1)
                target->CastSpell(target, SPELL_PRIEST_STRENGTH_OF_SOUL_TRIGGERED_R1, aurEff);
            else
                target->CastSpell(target, SPELL_PRIEST_STRENGTH_OF_SOUL_TRIGGERED_R2, aurEff);
        }
        else
        {
            uint32 spellId = GetSpellInfo()->Effects[EFFECT_0].TriggerSpell;
            int32 bp = aurEff->GetAmount() * IN_MILLISECONDS;
            target->CastSpell(eventInfo.GetProcTarget(), spellId, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
        }
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_strength_of_soul::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_pri_strength_of_soul_script : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_WEAKENED_SOUL });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Aura* aura = GetHitUnit()->GetAura(SPELL_PRIEST_WEAKENED_SOUL))
            aura->SetDuration(std::max(0, aura->GetDuration() - GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_strength_of_soul_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// -14523 - Atonement
class spell_pri_atonement : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_ATONEMENT_TRIGGERED_LARGE,
                SPELL_PRIEST_ATONEMENT_TRIGGERED_DEFAULT
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = GetTarget();
        DamageInfo* damage = eventInfo.GetDamageInfo();
        if (!damage)
            return;

        Unit* target = damage->GetVictim();
        int32 bp = CalculatePct(damage->GetDamage(), aurEff->GetAmount());

        if (target->GetCombatReach() >= 15.0f)
            caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_TRIGGERED_LARGE, CastSpellExtraArgs(aurEff).AddSpellBP0(bp).AddSpellMod(SPELLVALUE_RADIUS_MOD, int32(target->GetCombatReach() + 15.0f) * 100));
        else
            caster->CastSpell(target, SPELL_PRIEST_ATONEMENT_TRIGGERED_DEFAULT, CastSpellExtraArgs(aurEff).AddSpellBP0(SPELLVALUE_BASE_POINT0));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_atonement::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// Atonement (Healing)
class spell_pri_atonement_heal : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaidCheck(GetCaster()));

        if (targets.size() > 1)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(1);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_pri_atonement_heal::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

class spell_pri_spirit_of_redemption : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SPIRIT_OF_REDEMPTION_TRIGGERED });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        uint32 damage = dmgInfo.GetDamage();

        if (damage >= target->GetHealth() && target->GetAuraEffectsByType(SPELL_AURA_SPIRIT_OF_REDEMPTION).empty())
        {
            absorbAmount = damage;
            target->CastSpell(target, SPELL_PRIEST_SPIRIT_OF_REDEMPTION_TRIGGERED, aurEff);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_pri_spirit_of_redemption::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb.Register(&spell_pri_spirit_of_redemption::Absorb, EFFECT_0);
    }
};

// 8092 - Mind Blast
class spell_pri_mind_blast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_MIND_TRAUMA,
                SPELL_PRIEST_EMPOWERED_SHADOW
            });
    }

    void HandleDamageBonus(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (AuraEffect const* effect = caster->GetDummyAuraEffect(SPELLFAMILY_GENERIC, PRIEST_ICON_ID_SHADOW_ORB, EFFECT_0))
        {
            int32 damage = GetHitDamage();
            int32 bp = effect->GetAmount();
            AddPct(damage, bp);
            SetHitDamage(damage);
        }
    }

    void HandleImprovedMindBlast(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || caster->GetShapeshiftForm() != FORM_SHADOW)
            return;

        if (AuraEffect* effect = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_PRIEST, PRIEST_ICON_ID_IMPROVED_MIND_BLAST, EFFECT_0))
            if (roll_chance_i(effect->GetSpellInfo()->Effects[EFFECT_1].CalcValue(caster)))
                caster->CastSpell(GetHitUnit(), SPELL_PRIEST_MIND_TRAUMA, effect);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_mind_blast::HandleDamageBonus, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget.Register(&spell_pri_mind_blast::HandleImprovedMindBlast, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 73510 - Mind Spike
class spell_pri_mind_spike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_EMPOWERED_SHADOW });
    }

    void HandleDamageBonus(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (AuraEffect const* effect = caster->GetDummyAuraEffect(SPELLFAMILY_GENERIC, PRIEST_ICON_ID_SHADOW_ORB, EFFECT_0))
        {
            int32 damage = GetHitDamage();
            int32 bp = effect->GetAmount();
            AddPct(damage, bp);
            SetHitDamage(damage);
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pri_mind_spike::HandleDamageBonus, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// -88994 - Masochism
class spell_pri_masochism : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SHADOW_WORD_DEATH });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        DamageInfo const* damage = eventInfo.GetDamageInfo();
        if (!damage)
            return false;

        // Damaging yourself with Shadow Word: Death
        if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->Id == SPELL_PRIEST_SHADOW_WORD_DEATH && eventInfo.GetActor() == GetTarget())
            return true;

        // Taking damage >= 10% of your total health
        if (damage->GetDamage() >= CalculatePct(GetTarget()->GetMaxHealth(), GetSpellInfo()->Effects[EFFECT_1].CalcValue()))
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc.Register(&spell_pri_masochism::CheckProc);
    }
};

class spell_pri_harnessed_shadows : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_1].TriggerSpell });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();
        PreventDefaultAction();
        int32 basePoints = 10;
        if (AuraEffect const* effect = target->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_PRIEST, 0, 0, 0x00100000))
            basePoints += effect->GetAmount();

        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_1].TriggerSpell, CastSpellExtraArgs(aurEff).AddSpellBP0(basePoints));
    }

    void Register() override
    {
        OnEffectProc.Register(&spell_pri_harnessed_shadows::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_priest_spell_scripts()
{
    RegisterSpellScript(spell_pri_archangel);
    RegisterSpellScript(spell_pri_atonement);
    RegisterSpellScript(spell_pri_atonement_heal);
    RegisterSpellScript(spell_pri_body_and_soul);
    RegisterSpellScript(spell_pri_chakra);
    RegisterSpellScript(spell_pri_chakra_sanctuary);
    RegisterSpellScript(spell_pri_chakra_serenity_script);
    RegisterSpellScript(spell_pri_chakra_flow_removal);
    RegisterSpellScript(spell_pri_circle_of_healing);
    RegisterSpellScript(spell_pri_dispel_magic);
    RegisterSpellScript(spell_pri_divine_aegis);
    RegisterSpellScript(spell_pri_divine_hymn);
    RegisterSpellScript(spell_pri_echo_of_light);
    RegisterSpellScript(spell_pri_evangelism);
    RegisterSpellScript(spell_pri_evangelism_triggered);
    RegisterSpellScript(spell_pri_glyph_of_prayer_of_healing);
    RegisterSpellScript(spell_pri_harnessed_shadows);
    RegisterSpellScript(spell_pri_hymn_of_hope);
    RegisterSpellScript(spell_pri_improved_power_word_shield);
    RegisterSpellScript(spell_pri_item_greater_heal_refund);
    RegisterSpellScript(spell_pri_guardian_spirit);
    RegisterSpellScript(spell_pri_holy_word_sanctuary);
    RegisterSpellScript(spell_pri_holy_word_sanctuary_triggered);
    RegisterSpellScript(spell_pri_leap_of_faith_effect_trigger);
    RegisterSpellScript(spell_pri_lightwell_renew);
    RegisterSpellScript(spell_pri_mana_leech);
    RegisterSpellScript(spell_pri_masochism);
    RegisterSpellScript(spell_pri_mind_blast);
    RegisterSpellScript(spell_pri_mind_sear);
    RegisterSpellScript(spell_pri_mind_spike);
    RegisterSpellScript(spell_pri_pain_and_suffering_proc);
    RegisterSpellScript(spell_pri_penance);
    RegisterSpellScript(spell_pri_phantasm);
    RegisterSpellScript(spell_power_word_barrier);
    RegisterSpellAndAuraScriptPair(spell_pri_power_word_shield, spell_pri_power_word_shield_AuraScript);
    RegisterSpellScript(spell_pri_prayer_of_mending_heal);
    RegisterSpellScript(spell_pri_shadow_orb);
    RegisterSpellScript(spell_pri_shadow_orbs);
    RegisterSpellScript(spell_pri_shadow_orb_power);
    RegisterSpellScript(spell_pri_strength_of_soul);
    RegisterSpellScript(spell_pri_strength_of_soul_script);
    RegisterSpellScript(spell_pri_spirit_of_redemption);
    RegisterSpellScript(spell_pri_renew);
    RegisterSpellScript(spell_pri_shadow_word_death);
    RegisterSpellScript(spell_pri_shadowform);
    RegisterSpellScript(spell_pri_vampiric_embrace);
    RegisterSpellScript(spell_pri_vampiric_embrace_target);
    RegisterSpellScript(spell_pri_vampiric_touch);
}
