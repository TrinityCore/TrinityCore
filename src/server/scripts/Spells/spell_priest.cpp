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

enum PriestSpells
{
    SPELL_PRIEST_ABSOLUTION                         = 33167,
    SPELL_PRIEST_ARCHANGEL_DUMMY                    = 94709,
    SPELL_PRIEST_ARCHANGEL_TRIGGERED                = 81700,
    SPELL_PRIEST_ARCHANGEL_ENERGIZE                 = 87152,
    SPELL_PRIEST_BODY_AND_SOUL_DISPEL               = 64136,
    SPELL_PRIEST_BODY_AND_SOUL_SPEED                = 65081,
    SPELL_PRIEST_CHAKRA_SERENITY                    = 81208,
    SPELL_PRIEST_CHAKRA_SANCTUARY                   = 81206,
    SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED            = 81207,
    SPELL_PRIEST_CHAKRA_CHASTISE                    = 81209,
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
    SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL    = 56161,
    SPELL_PRIEST_GLYPH_OF_SHADOW                    = 107906,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_HOLY_WORD_CHASTISE                 = 88625,
    SPELL_PRIEST_HOLY_WORD_SANCTUARY                = 88686,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_LEAP_OF_FAITH                      = 73325,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT               = 92832,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT_TRIGGER       = 92833,
    SPELL_PRIEST_LEAP_OF_FAITH_TRIGGERED            = 92572,
    SPELL_PRIEST_MANA_LEECH_PROC                    = 34650,
    SPELL_PRIEST_MIND_FLAY                          = 15407,
    SPELL_PRIEST_PENANCE_R1                         = 47540,
    SPELL_PRIEST_PENANCE_R1_DAMAGE                  = 47758,
    SPELL_PRIEST_PENANCE_R1_HEAL                    = 47757,
    SPELL_PRIEST_REFLECTIVE_SHIELD_R1               = 33201,
    SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED        = 33619,
    SPELL_PRIEST_RENEW                              = 139,
    SPELL_PRIEST_REVELATIONS                        = 88627,
    SPELL_PRIEST_SHADOW_ORB_MARKER                  = 93683,
    SPELL_PRIEST_SHADOW_ORB_POWER                   = 77486,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH    = 107903,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH       = 107904,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409,
    SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1            = 47586,
    SPELL_PRIEST_T9_HEALING_2P                      = 67201,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 64085
};

enum PriestSpellIcons
{
    PRIEST_ICON_ID_BORROWED_TIME                    = 2899,
    PRIEST_ICON_ID_DIVINE_TOUCH_TALENT              = 3021,
    PRIEST_ICON_ID_PAIN_AND_SUFFERING               = 2874,
    PRIEST_ICON_ID_SHIELD_DISCIPLINE                = 566,
    PRIEST_ICON_ID_GLYPH_OF_POWER_WORD_BARRIER      = 3837
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
                return target->getPowerType() != _power;

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
    PrepareAuraScript(spell_pri_body_and_soul);

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

        GetTarget()->CastCustomSpell(SPELL_PRIEST_BODY_AND_SOUL_SPEED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), eventInfo.GetProcTarget(), true, nullptr, aurEff);
    }

    void HandleEffectDispelProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        // Proc only with Cure Disease
        if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PRIEST_CURE_DISEASE || eventInfo.GetProcTarget() != GetTarget())
            return;

        if (roll_chance_i(aurEff->GetAmount()))
            GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_BODY_AND_SOUL_DISPEL, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul::HandleEffectSpeedProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul::HandleEffectDispelProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 34861 - Circle of Healing
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

// 527 - Dispel magic
class spell_pri_dispel_magic : public SpellScript
{
    PrepareSpellScript(spell_pri_dispel_magic);

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
                GetCaster()->CastCustomSpell(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL, SPELLVALUE_BASE_POINT0, heal, GetHitUnit());
            }
        }
        else
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_HOSTILE, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pri_dispel_magic::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_pri_dispel_magic::AfterEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
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

        int32 absorb = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

        // Multiple effects stack, so let's try to find this aura.
        if (AuraEffect const* aegis = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_PRIEST_DIVINE_AEGIS, EFFECT_0))
            absorb += aegis->GetAmount();

        if (AuraEffect const* shieldDiscipline = GetTarget()->GetDummyAuraEffect(SPELLFAMILY_HUNTER, PRIEST_ICON_ID_SHIELD_DISCIPLINE, EFFECT_0))
            AddPct(absorb, shieldDiscipline->GetAmount());

        absorb = std::min(absorb, int32(CalculatePct(eventInfo.GetProcTarget()->GetMaxHealth(), 40)));

        GetTarget()->CastCustomSpell(SPELL_PRIEST_DIVINE_AEGIS, SPELLVALUE_BASE_POINT0, absorb, eventInfo.GetProcTarget(), true, nullptr, aurEff);
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

        SpellInfo const* triggeredSpellInfo = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL);
        int32 heal = int32(CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount()) / triggeredSpellInfo->GetMaxTicks());
        GetTarget()->CastCustomSpell(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL, SPELLVALUE_BASE_POINT0, heal, eventInfo.GetProcTarget(), true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_glyph_of_prayer_of_healing::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_pri_improved_power_word_shield : public AuraScript
{
    PrepareAuraScript(spell_pri_improved_power_word_shield);

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
        DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pri_improved_power_word_shield::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 37594 - Greater Heal Refund
class spell_pri_item_greater_heal_refund : public AuraScript
{
    PrepareAuraScript(spell_pri_item_greater_heal_refund);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_ITEM_EFFICIENCY });
    }

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_item_greater_heal_refund::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public AuraScript
{
    PrepareAuraScript(spell_pri_guardian_spirit);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL });
    }

    bool Load() override
    {
        healPct = GetSpellInfo()->Effects[EFFECT_1].BasePoints;
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
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

        target->CastCustomSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, &healAmount, nullptr, nullptr, true);
        absorbAmount = dmgInfo.GetDamage();
        Remove();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_guardian_spirit::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_guardian_spirit::Absorb, EFFECT_1);
    }

private:
    uint32 healPct;
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

// 92833 - Leap of Faith
class spell_pri_leap_of_faith_effect_trigger : public SpellScript
{
    PrepareSpellScript(spell_pri_leap_of_faith_effect_trigger);

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
        GetHitUnit()->CastSpell(targets, sSpellMgr->GetSpellInfo(GetEffectValue()), nullptr);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_leap_of_faith_effect_trigger::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 7001 - Lightwell Renew
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

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_lightwell_renew::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
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
        GetTarget()->CastSpell(_procTarget, SPELL_PRIEST_MANA_LEECH_PROC, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_mana_leech::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_mana_leech::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    Unit* _procTarget = nullptr;
};

// 49821 - Mind Sear
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
                aur->SetBonusAmount(caster->SpellDamageBonusDone(target, aur->GetSpellInfo(), 0, DOT, aur->GetEffIndex()));
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

// 47540 - Penance
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
        OnEffectHitTarget += SpellEffectFn(spell_pri_penance::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_pri_penance::CheckCast);
    }
};

// -47569 - Phantasm
class spell_pri_phantasm : public AuraScript
{
    PrepareAuraScript(spell_pri_phantasm);

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
        DoCheckProc += AuraCheckProcFn(spell_pri_phantasm::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_phantasm::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 17 - Power Word: Shield
class spell_pri_power_word_shield : public AuraScript
{
    PrepareAuraScript(spell_pri_power_word_shield);

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
            target->CastCustomSpell(dmgInfo.GetAttacker(), SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED, &bp, nullptr, nullptr, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_power_word_shield::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_pri_power_word_shield::ReflectDamage, EFFECT_0);
    }
};

// 33110 - Prayer of Mending Heal
class spell_pri_prayer_of_mending_heal : public SpellScript
{
    PrepareSpellScript(spell_pri_prayer_of_mending_heal);

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
        OnEffectHitTarget += SpellEffectFn(spell_pri_prayer_of_mending_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 139 - Renew
class spell_pri_renew : public AuraScript
{
    PrepareAuraScript(spell_pri_renew);

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
                caster->CastCustomSpell(GetTarget(), SPELL_PRIEST_DIVINE_TOUCH, &basepoints0, nullptr, nullptr, true, nullptr, aurEff);
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_pri_renew::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 32379 - Shadow Word Death
class spell_pri_shadow_word_death : public SpellScript
{
    PrepareSpellScript(spell_pri_shadow_word_death);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_SHADOW_WORD_DEATH });
    }

    void HandleDamage()
    {
        int32 damage = GetHitDamage();

        // Pain and Suffering reduces damage
        if (AuraEffect* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_PAIN_AND_SUFFERING, EFFECT_1))
            AddPct(damage, aurEff->GetAmount());

        GetCaster()->CastCustomSpell(GetCaster(), SPELL_PRIEST_SHADOW_WORD_DEATH, &damage, nullptr, nullptr, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_pri_shadow_word_death::HandleDamage);
    }
};

// 15473 - Shadowform
class spell_pri_shadowform : public AuraScript
{
    PrepareAuraScript(spell_pri_shadowform);

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
        AfterEffectApply += AuraEffectApplyFn(spell_pri_shadowform::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_shadowform::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
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

        GetTarget()->CastCustomSpell((Unit*)nullptr, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, &team, &self, nullptr, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_embrace::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_embrace::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 15290 - Vampiric Embrace (heal)
class spell_pri_vampiric_embrace_target : public SpellScript
{
    PrepareSpellScript(spell_pri_vampiric_embrace_target);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_vampiric_embrace_target::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 34914 - Vampiric Touch
class spell_pri_vampiric_touch : public AuraScript
{
    PrepareAuraScript(spell_pri_vampiric_touch);

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
                    caster->CastCustomSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, &damage, nullptr, nullptr, true, nullptr, aurEff);
                }
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget() == GetCaster();
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        eventInfo.GetProcTarget()->CastSpell((Unit*)nullptr, SPELL_GEN_REPLENISHMENT, true, nullptr, aurEff);
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_pri_vampiric_touch::HandleDispel);
        DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_touch::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_touch::HandleEffectProc, EFFECT_2, SPELL_AURA_DUMMY);
    }
};

class spell_pri_echo_of_light : public AuraScript
{
    PrepareAuraScript(spell_pri_echo_of_light);

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
                    caster->CastCustomSpell(SPELL_PRIEST_ECHO_OF_LIGHT, SPELLVALUE_BASE_POINT0, healAmount / tickNumber, target, true, nullptr, aurEff);
            }
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_echo_of_light::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_echo_of_light::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 95740 - Shadow Orbs (Passive)
class spell_pri_shadow_orbs : public AuraScript
{
    PrepareAuraScript(spell_pri_shadow_orbs);

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
        // Do not proc when the target has Shadow Orb Power mastery active
        if (GetTarget()->HasAura(SPELL_PRIEST_SHADOW_ORB_POWER))
            return false;

        return true;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pri_shadow_orbs::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pri_shadow_orbs::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77486 - Shadow Orb Power (Passive)
class spell_pri_shadow_orb_power : public AuraScript
{
    PrepareAuraScript(spell_pri_shadow_orb_power);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        int32 amount = GetEffect(EFFECT_0)->GetAmount();

        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell))
            amount += spell->Effects[EFFECT_0].BasePoints;

        GetTarget()->CastCustomSpell(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, SPELLVALUE_BASE_POINT0, amount, GetTarget(), true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_shadow_orb_power::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 77487 - Shadow Orb
class spell_pri_shadow_orb : public AuraScript
{
    PrepareAuraScript(spell_pri_shadow_orb);

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
        target->CastCustomSpell(target, SPELL_PRIEST_EMPOWERED_SHADOW, &bp, &bp, 0, true, nullptr, aurEff);
        target->RemoveAurasDueToSpell(SPELL_PRIEST_SHADOW_ORB_MARKER);
        Remove();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_pri_shadow_orb::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_shadow_orb::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectProc += AuraEffectProcFn(spell_pri_shadow_orb::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 14751 - Chakra
class spell_pri_chakra : public AuraScript
{
    PrepareAuraScript(spell_pri_chakra);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PRIEST_CHAKRA_SERENITY,
                SPELL_PRIEST_CHAKRA_SANCTUARY,
                SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED,
                SPELL_PRIEST_CHAKRA_CHASTISE,
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

        uint32 spellId = 0;
        if (SpellInfo const* spell = eventInfo.GetSpellInfo())
        {
            // Chakra: Serenity
            if (spell->SpellFamilyFlags.HasFlag(0x00000400) || spell->SpellFamilyFlags.HasFlag(0x00001000)
                || spell->SpellFamilyFlags.HasFlag(0x00000800) || spell->SpellFamilyFlags.HasFlag(0, 0x00000004))
            {
                SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_CHAKRA_SERENITY);
                int32 bp = caster->HasAura(SPELL_PRIEST_REVELATIONS) ? spell->Effects[EFFECT_2].BasePoints : SPELL_PRIEST_HOLY_WORD_CHASTISE;

                caster->CastCustomSpell(SPELL_PRIEST_CHAKRA_SERENITY, SPELLVALUE_BASE_POINT2, bp, caster, true, nullptr, aurEff);
            }

            // Chakra: Sanctuary
            if (spell->SpellFamilyFlags.HasFlag(0x00000200) || spell->SpellFamilyFlags.HasFlag(0, 0x00000020))
            {
                SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_CHAKRA_SANCTUARY);
                int32 bp = caster->HasAura(SPELL_PRIEST_REVELATIONS) ? spell->Effects[EFFECT_2].BasePoints : SPELL_PRIEST_HOLY_WORD_CHASTISE;

                caster->CastCustomSpell(SPELL_PRIEST_CHAKRA_SANCTUARY, SPELLVALUE_BASE_POINT2, bp, caster, true, nullptr, aurEff);
                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED, true, nullptr, aurEff);
            }

            // Chakra: Chastise
            if (spell->SpellFamilyFlags.HasFlag(0x00000080) || spell->SpellFamilyFlags.HasFlag(0, 0x00010000))
                caster->CastSpell(caster, SPELL_PRIEST_CHAKRA_CHASTISE, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_pri_chakra::HandleEffectApply, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        OnEffectProc += AuraEffectProcFn(spell_pri_chakra::HandleProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
    }
};

// 81206 - Chakra: Sanctuary
class spell_pri_chakra_sanctuary : public AuraScript
{
    PrepareAuraScript(spell_pri_chakra_sanctuary);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED });
    }

    void HandleEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_PRIEST_CHAKRA_SANCTUARY_LINKED);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_chakra_sanctuary::HandleEffectRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 81585 - Chakra: Serenity
class spell_pri_chakra_serenity_script : public SpellScript
{
    PrepareSpellScript(spell_pri_chakra_serenity_script);

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
        OnEffectHitTarget += SpellEffectFn(spell_pri_chakra_serenity_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 88685 - Holy Word: Sanctuary
class spell_pri_holy_word_sanctuary : public AuraScript
{
    PrepareAuraScript(spell_pri_holy_word_sanctuary);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PRIEST_HOLY_WORD_SANCTUARY });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        if (DynamicObject* dyn = GetTarget()->GetDynObject(aurEff->GetId()))
            GetTarget()->CastSpell(dyn->GetPositionX(), dyn->GetPositionY(), dyn->GetPositionZ(), SPELL_PRIEST_HOLY_WORD_SANCTUARY, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_DISALLOW_PROC_EVENTS), nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pri_holy_word_sanctuary::HandleDummyTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 88686 - Holy Word: Sanctuary
class spell_pri_holy_word_sanctuary_triggered : public SpellScript
{
    PrepareSpellScript(spell_pri_holy_word_sanctuary_triggered);

    bool Load()
    {
        _targets = 0;
        return true;
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (GetHitHeal() && _targets > 6)
            SetHitHeal(GetHitHeal() / _targets);
    }

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        _targets = unitList.size();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_holy_word_sanctuary_triggered::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnEffectHitTarget += SpellEffectFn(spell_pri_holy_word_sanctuary_triggered::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
    }

private:
    uint32 _targets;
};

// -81659 - Evangelism
class spell_pri_evangelism : public AuraScript
{
    PrepareAuraScript(spell_pri_evangelism);

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

        target->CastSpell(target, spellId, true, nullptr, aurEff);
        target->CastSpell(target, SPELL_PRIEST_EVANGELISM_ARCHANGEL_DUMMY, true, nullptr, aurEff);

        if (Aura* aura = target->GetAura(spellId))
            if (aura->GetStackAmount() == aura->GetSpellInfo()->StackAmount)
                target->CastSpell(target, SPELL_PRIEST_ARCHANGEL_DUMMY, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pri_evangelism::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 81660, 81661 - Evangelism (Triggered Effect) / 87117, 87118 - Dark Evangelism (Triggered Effect)
class spell_pri_evangelism_triggered : public AuraScript
{
    PrepareAuraScript(spell_pri_evangelism_triggered);

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
        AfterEffectRemove += AuraEffectRemoveFn(spell_pri_evangelism_triggered::AfterRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 87151 - Archangel
class spell_pri_archangel : public SpellScript
{
    PrepareSpellScript(spell_pri_archangel);

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
            caster->CastCustomSpell(SPELL_PRIEST_ARCHANGEL_TRIGGERED, SPELLVALUE_BASE_POINT0, bp, caster, true);
            caster->CastCustomSpell(SPELL_PRIEST_ARCHANGEL_ENERGIZE, SPELLVALUE_BASE_POINT0, stacks, caster, true);
        }
        else
        {
            SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED);
            int32 bp0 = spell->Effects[EFFECT_0].BasePoints * stacks;
            int32 bp1 = spell->Effects[EFFECT_1].BasePoints * stacks;
            int32 energize = spell->Effects[EFFECT_2].BasePoints * stacks;
            caster->CastCustomSpell(caster, SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED, &bp0, &bp1, nullptr, true);
            caster->CastCustomSpell(SPELL_PRIEST_ARCHANGEL_ENERGIZE, SPELLVALUE_BASE_POINT0, energize, caster, true);
        }

        caster->RemoveAurasDueToSpell(spellId);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pri_archangel::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_power_word_barrier : public AuraScript
{
    PrepareAuraScript(spell_power_word_barrier);

    bool Load()
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
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_power_word_barrier::HandleGlyph, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }

private:
    bool _glyphEnabled;
};

void AddSC_priest_spell_scripts()
{
    RegisterSpellScript(spell_pri_archangel);
    RegisterAuraScript(spell_pri_body_and_soul);
    RegisterAuraScript(spell_pri_chakra);
    RegisterAuraScript(spell_pri_chakra_sanctuary);
    RegisterSpellScript(spell_pri_chakra_serenity_script);
    RegisterSpellScript(spell_pri_circle_of_healing);
    RegisterSpellScript(spell_pri_dispel_magic);
    RegisterAuraScript(spell_pri_divine_aegis);
    RegisterSpellScript(spell_pri_divine_hymn);
    RegisterAuraScript(spell_pri_echo_of_light);
    RegisterAuraScript(spell_pri_evangelism);
    RegisterAuraScript(spell_pri_evangelism_triggered);
    RegisterAuraScript(spell_pri_glyph_of_prayer_of_healing);
    RegisterSpellScript(spell_pri_hymn_of_hope);
    RegisterAuraScript(spell_pri_improved_power_word_shield);
    RegisterAuraScript(spell_pri_item_greater_heal_refund);
    RegisterAuraScript(spell_pri_guardian_spirit);
    RegisterAuraScript(spell_pri_holy_word_sanctuary);
    RegisterSpellScript(spell_pri_holy_word_sanctuary_triggered);
    RegisterSpellScript(spell_pri_leap_of_faith_effect_trigger);
    RegisterAuraScript(spell_pri_lightwell_renew);
    RegisterAuraScript(spell_pri_mana_leech);
    RegisterSpellScript(spell_pri_mind_sear);
    RegisterSpellScript(spell_pri_pain_and_suffering_proc);
    RegisterSpellScript(spell_pri_penance);
    RegisterAuraScript(spell_pri_phantasm);
    RegisterAuraScript(spell_power_word_barrier);
    RegisterAuraScript(spell_pri_power_word_shield);
    RegisterSpellScript(spell_pri_prayer_of_mending_heal);
    RegisterAuraScript(spell_pri_shadow_orb);
    RegisterAuraScript(spell_pri_shadow_orbs);
    RegisterAuraScript(spell_pri_shadow_orb_power);
    RegisterAuraScript(spell_pri_renew);
    RegisterSpellScript(spell_pri_shadow_word_death);
    RegisterAuraScript(spell_pri_shadowform);
    RegisterAuraScript(spell_pri_vampiric_embrace);
    RegisterSpellScript(spell_pri_vampiric_embrace_target);
    RegisterAuraScript(spell_pri_vampiric_touch);
}
