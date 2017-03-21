/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"

enum PriestSpells
{
    SPELL_PRIEST_ABSOLUTION                         = 33167,
    SPELL_PRIEST_ANGELIC_FEATHER_TRIGGER            = 121536,
    SPELL_PRIEST_ANGELIC_FEATHER_AURA               = 121557,
    SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER        = 158624,
    SPELL_PRIEST_BODY_AND_SOUL                      = 64129,
    SPELL_PRIEST_BODY_AND_SOUL_DISPEL               = 64136,
    SPELL_PRIEST_BODY_AND_SOUL_SPEED                = 65081,
    SPELL_PRIEST_CURE_DISEASE                       = 528,
    SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY              = 97690,
    SPELL_PRIEST_DISPEL_MAGIC_HOSTILE               = 97691,
    SPELL_PRIEST_DIVINE_AEGIS                       = 47753,
    SPELL_PRIEST_DIVINE_TOUCH                       = 63544,
    SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING         = 55675,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC              = 55677,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL         = 56131,
    SPELL_PRIEST_GLYPH_OF_LIGHTWELL                 = 55673,
    SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL    = 56161,
    SPELL_PRIEST_GLYPH_OF_SHADOW                    = 107906,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_LEAP_OF_FAITH                      = 73325,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT               = 92832,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT_TRIGGER       = 92833,
    SPELL_PRIEST_LEAP_OF_FAITH_TRIGGERED            = 92572,
    SPELL_PRIEST_LEVITATE_EFFECT                    = 111759,
    SPELL_PRIEST_MANA_LEECH_PROC                    = 34650,
    SPELL_PRIEST_PENANCE_R1                         = 47540,
    SPELL_PRIEST_PENANCE_R1_DAMAGE                  = 47758,
    SPELL_PRIEST_PENANCE_R1_HEAL                    = 47757,
    SPELL_PRIEST_REFLECTIVE_SHIELD_R1               = 33201,
    SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED        = 33619,
    SPELL_PRIEST_RENEWED_HOPE                       = 197469,
    SPELL_PRIEST_RENEWED_HOPE_EFFECT                = 197470,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH    = 107903,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH       = 107904,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409,
    SPELL_PRIEST_SHIELD_DISCIPLINE_PASSIVE          = 197045,
    SPELL_PRIEST_SHIELD_DISCIPLINE_ENERGIZE         = 47755,
    SPELL_PRIEST_STRENGTH_OF_SOUL                   = 197535,
    SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT            = 197548,
    SPELL_PRIEST_THE_PENITENT_AURA                  = 200347,
    SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1            = 47586,
    SPELL_PRIEST_T9_HEALING_2P                      = 67201,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 64085,
    SPELL_PRIEST_VOID_SHIELD                        = 199144,
    SPELL_PRIEST_VOID_SHIELD_EFFECT                 = 199145
};

enum PriestSpellIcons
{
    PRIEST_ICON_ID_BORROWED_TIME                    = 2899,
    PRIEST_ICON_ID_DIVINE_TOUCH_TALENT              = 3021,
    PRIEST_ICON_ID_PAIN_AND_SUFFERING               = 2874
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

class spell_pri_body_and_soul : public SpellScriptLoader
{
    public:
        spell_pri_body_and_soul() : SpellScriptLoader("spell_pri_body_and_soul") { }

        class spell_pri_body_and_soul_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_body_and_soul_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_CURE_DISEASE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PRIEST_BODY_AND_SOUL_DISPEL))
                    return false;
                return true;
            }

            void HandleEffectSpeedProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                // Proc only with Power Word: Shield or Leap of Faith
                if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[0] & 0x1 || eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[2] & 0x80000))
                    return;

                GetTarget()->CastCustomSpell(SPELL_PRIEST_BODY_AND_SOUL_SPEED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void HandleEffectDispelProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                // Proc only with Cure Disease
                if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PRIEST_CURE_DISEASE || eventInfo.GetProcTarget() != GetTarget())
                    return;

                if (roll_chance_i(aurEff->GetAmount()))
                    GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_BODY_AND_SOUL_DISPEL, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul_AuraScript::HandleEffectSpeedProc, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul_AuraScript::HandleEffectDispelProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_body_and_soul_AuraScript();
        }
};

// 34861 - Circle of Healing
class spell_pri_circle_of_healing : public SpellScriptLoader
{
    public:
        spell_pri_circle_of_healing() : SpellScriptLoader("spell_pri_circle_of_healing") { }

        class spell_pri_circle_of_healing_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_circle_of_healing_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_CIRCLE_OF_HEALING))
                    return false;
                return true;
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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_circle_of_healing_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_circle_of_healing_SpellScript();
        }
};

// 527 - Dispel magic
class spell_pri_dispel_magic : public SpellScriptLoader
{
public:
    spell_pri_dispel_magic() : SpellScriptLoader("spell_pri_dispel_magic") { }

    class spell_pri_dispel_magic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_dispel_magic_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ABSOLUTION))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC))
                return false;
            return true;
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
            OnCheckCast += SpellCheckCastFn(spell_pri_dispel_magic_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_pri_dispel_magic_SpellScript::AfterEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pri_dispel_magic_SpellScript();
    }
};

// -47509 - Divine Aegis
class spell_pri_divine_aegis : public SpellScriptLoader
{
    public:
        spell_pri_divine_aegis() : SpellScriptLoader("spell_pri_divine_aegis") { }

        class spell_pri_divine_aegis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_divine_aegis_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_DIVINE_AEGIS))
                    return false;
                return true;
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

                absorb = std::min(absorb, eventInfo.GetProcTarget()->getLevel() * 125);

                GetTarget()->CastCustomSpell(SPELL_PRIEST_DIVINE_AEGIS, SPELLVALUE_BASE_POINT0, absorb, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_divine_aegis_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_divine_aegis_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_divine_aegis_AuraScript();
        }
};

// 64844 - Divine Hymn
class spell_pri_divine_hymn : public SpellScriptLoader
{
    public:
        spell_pri_divine_hymn() : SpellScriptLoader("spell_pri_divine_hymn") { }

        class spell_pri_divine_hymn_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_divine_hymn_SpellScript);

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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_divine_hymn_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_divine_hymn_SpellScript();
        }
};

// 55680 - Glyph of Prayer of Healing
class spell_pri_glyph_of_prayer_of_healing : public SpellScriptLoader
{
    public:
        spell_pri_glyph_of_prayer_of_healing() : SpellScriptLoader("spell_pri_glyph_of_prayer_of_healing") { }

        class spell_pri_glyph_of_prayer_of_healing_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_glyph_of_prayer_of_healing_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                SpellInfo const* triggeredSpellInfo = sSpellMgr->AssertSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL);
                int32 heal = int32(CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount()) / triggeredSpellInfo->GetMaxTicks(DIFFICULTY_NONE));
                GetTarget()->CastCustomSpell(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL, SPELLVALUE_BASE_POINT0, heal, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_glyph_of_prayer_of_healing_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_glyph_of_prayer_of_healing_AuraScript();
        }
};

// 24191 - Improved Power Word Shield
class spell_pri_improved_power_word_shield : public SpellScriptLoader
{
    public:
        spell_pri_improved_power_word_shield() : SpellScriptLoader("spell_pri_improved_power_word_shield") { }

        class spell_pri_improved_power_word_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_improved_power_word_shield_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SpellModOp(aurEff->GetMiscValue());
                    spellMod->type = SPELLMOD_PCT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->SpellClassMask;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() override
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pri_improved_power_word_shield_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_improved_power_word_shield_AuraScript();
        }
};

// 37594 - Greater Heal Refund
class spell_pri_item_greater_heal_refund : public SpellScriptLoader
{
    public:
        spell_pri_item_greater_heal_refund() : SpellScriptLoader("spell_pri_item_greater_heal_refund") { }

        class spell_pri_item_greater_heal_refund_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_item_greater_heal_refund_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ITEM_EFFICIENCY))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_item_greater_heal_refund_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_item_greater_heal_refund_AuraScript();
        }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public SpellScriptLoader
{
    public:
        spell_pri_guardian_spirit() : SpellScriptLoader("spell_pri_guardian_spirit") { }

        class spell_pri_guardian_spirit_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_guardian_spirit_AuraScript);

        public:
            spell_pri_guardian_spirit_AuraScript()
            {
                healPct = 0;
            }

        private:
            uint32 healPct;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL))
                    return false;
                return true;
            }

            bool Load() override
            {
                healPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
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
                target->CastCustomSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, &healAmount, NULL, NULL, true);
                absorbAmount = dmgInfo.GetDamage();
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_guardian_spirit_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_guardian_spirit_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_guardian_spirit_AuraScript();
        }
};

// 64904 - Hymn of Hope
class spell_pri_hymn_of_hope : public SpellScriptLoader
{
    public:
        spell_pri_hymn_of_hope() : SpellScriptLoader("spell_pri_hymn_of_hope") { }

        class spell_pri_hymn_of_hope_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_hymn_of_hope_SpellScript);

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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_hymn_of_hope_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_hymn_of_hope_SpellScript();
        }
};

// 92833 - Leap of Faith
class spell_pri_leap_of_faith_effect_trigger : public SpellScriptLoader
{
    public:
        spell_pri_leap_of_faith_effect_trigger() : SpellScriptLoader("spell_pri_leap_of_faith_effect_trigger") { }

        class spell_pri_leap_of_faith_effect_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_leap_of_faith_effect_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEAP_OF_FAITH_EFFECT))
                    return false;
                return true;
            }

            void HandleEffectDummy(SpellEffIndex /*effIndex*/)
            {
                Position destPos = GetHitDest()->GetPosition();

                SpellCastTargets targets;
                targets.SetDst(destPos);
                targets.SetUnitTarget(GetCaster());
                GetHitUnit()->CastSpell(targets, sSpellMgr->GetSpellInfo(GetEffectValue()), NULL);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_leap_of_faith_effect_trigger_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_leap_of_faith_effect_trigger_SpellScript();
        }
};

// 1706 - Levitate
class spell_pri_levitate : public SpellScriptLoader
{
public:
    spell_pri_levitate() : SpellScriptLoader("spell_pri_levitate") { }

    class spell_pri_levitate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_levitate_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEVITATE_EFFECT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_LEVITATE_EFFECT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_pri_levitate_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_pri_levitate_SpellScript;
    }
};

// 7001 - Lightwell Renew
class spell_pri_lightwell_renew : public SpellScriptLoader
{
    public:
        spell_pri_lightwell_renew() : SpellScriptLoader("spell_pri_lightwell_renew") { }

        class spell_pri_lightwell_renew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_lightwell_renew_AuraScript);

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
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_lightwell_renew_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_lightwell_renew_AuraScript();
        }
};

// 8129 - Mana Burn
class spell_pri_mana_burn : public SpellScriptLoader
{
    public:
        spell_pri_mana_burn() : SpellScriptLoader("spell_pri_mana_burn") { }

        class spell_pri_mana_burn_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_mana_burn_SpellScript);

            void HandleAfterHit()
            {
                if (Unit* unitTarget = GetHitUnit())
                    unitTarget->RemoveAurasWithMechanic((1 << MECHANIC_FEAR) | (1 << MECHANIC_POLYMORPH));
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_pri_mana_burn_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_mana_burn_SpellScript;
        }
};

// 28305 - Mana Leech (Passive) (Priest Pet Aura)
class spell_pri_mana_leech : public SpellScriptLoader
{
    public:
        spell_pri_mana_leech() : SpellScriptLoader("spell_pri_mana_leech") { }

        class spell_pri_mana_leech_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_mana_leech_AuraScript);

        public:
            spell_pri_mana_leech_AuraScript()
            {
                _procTarget = nullptr;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_MANA_LEECH_PROC))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _procTarget = GetTarget()->GetOwner();
                return _procTarget != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(_procTarget, SPELL_PRIEST_MANA_LEECH_PROC, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_mana_leech_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_mana_leech_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        private:
            Unit* _procTarget;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_mana_leech_AuraScript();
        }
};

// 49821 - Mind Sear
class spell_pri_mind_sear : public SpellScriptLoader
{
    public:
        spell_pri_mind_sear() : SpellScriptLoader("spell_pri_mind_sear") { }

        class spell_pri_mind_sear_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_mind_sear_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(Trinity::ObjectGUIDCheck(GetCaster()->GetChannelObjectGuid()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_mind_sear_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_mind_sear_SpellScript();
        }
};

// 47948 - Pain and Suffering (Proc)
class spell_pri_pain_and_suffering_proc : public SpellScriptLoader
{
    public:
        spell_pri_pain_and_suffering_proc() : SpellScriptLoader("spell_pri_pain_and_suffering_proc") { }

        class spell_pri_pain_and_suffering_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_pain_and_suffering_proc_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                // Refresh Shadow Word: Pain on target
                if (Unit* target = GetHitUnit())
                    if (AuraEffect* aur = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, flag128(0x8000, 0, 0), caster->GetGUID()))
                    {
                        uint32 damage = std::max(aur->GetAmount(), 0);
                        sScriptMgr->ModifyPeriodicDamageAurasTick(target, caster, damage);
                        aur->SetDamage(caster->SpellDamageBonusDone(target, aur->GetSpellInfo(), damage, DOT, aur->GetSpellEffectInfo()) * aur->GetDonePct());
                        aur->CalculatePeriodic(caster, false, false);
                        aur->GetBase()->RefreshDuration();
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_pain_and_suffering_proc_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_pain_and_suffering_proc_SpellScript;
        }
};

// 47540 - Penance
class spell_pri_penance : public SpellScriptLoader
{
    public:
        spell_pri_penance() : SpellScriptLoader("spell_pri_penance") { }

        class spell_pri_penance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_penance_SpellScript);

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
                if (Unit* target = GetHitUnit())
                {
                    if (!target->IsAlive())
                        return;

                    uint8 rank = GetSpellInfo()->GetRank();

                    if (caster->IsFriendlyTo(target))
                        caster->CastSpell(target, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank), false);
                    else
                        caster->CastSpell(target, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank), false);
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
                    else
                    {
                        //Support for modifications of this spell in Legion with The Penitent talent (7.1.5)
                        if(!caster->HasAura(SPELL_PRIEST_THE_PENITENT_AURA))
                            return SPELL_FAILED_BAD_TARGETS;

                        if (!caster->isInFront(target))
                            return SPELL_FAILED_UNIT_NOT_INFRONT;
                    }
                }

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_penance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_pri_penance_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_penance_SpellScript;
        }
};

// -47569 - Phantasm
class spell_pri_phantasm : public SpellScriptLoader
{
    public:
        spell_pri_phantasm() : SpellScriptLoader("spell_pri_phantasm") { }

        class spell_pri_phantasm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_phantasm_AuraScript);

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
                DoCheckProc += AuraCheckProcFn(spell_pri_phantasm_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_phantasm_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_phantasm_AuraScript();
        }
};

// 17 - Power Word: Shield
class spell_pri_power_word_shield : public SpellScriptLoader
{
public:
    spell_pri_power_word_shield() : SpellScriptLoader("spell_pri_power_word_shield") { }

    class spell_pri_power_word_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pri_power_word_shield_AuraScript);

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;

            if (Player* player = GetCaster()->ToPlayer())
            {
                int32 playerMastery = player->GetRatingBonusValue(CR_MASTERY);
                int32 playerSpellPower = player->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
                int32 playerVersatileDamage = player->GetRatingBonusValue(CR_VERSATILITY_DAMAGE_DONE);

                //Formula taken from SpellWork
                amount = (int32)((playerSpellPower * 5.5f) + playerMastery) * (1 + playerVersatileDamage);
            }
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_PRIEST_BODY_AND_SOUL))
                caster->CastSpell(target, SPELL_PRIEST_BODY_AND_SOUL_SPEED, true);
            if (caster->HasAura(SPELL_PRIEST_STRENGTH_OF_SOUL))
                caster->CastSpell(target, SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT, true);
            if (caster->HasAura(SPELL_PRIEST_RENEWED_HOPE))
                caster->CastSpell(target, SPELL_PRIEST_RENEWED_HOPE_EFFECT, true);
            if (caster->HasAura(SPELL_PRIEST_VOID_SHIELD) && caster == target)
                caster->CastSpell(target, SPELL_PRIEST_VOID_SHIELD_EFFECT, true);
        }

        void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAura(SPELL_PRIEST_STRENGTH_OF_SOUL_EFFECT);
            if (Unit* caster = GetCaster())
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL && caster->HasAura(SPELL_PRIEST_SHIELD_DISCIPLINE_PASSIVE))
                    caster->CastSpell(caster, SPELL_PRIEST_SHIELD_DISCIPLINE_ENERGIZE, true);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_power_word_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectApply += AuraEffectApplyFn(spell_pri_power_word_shield_AuraScript::OnApply, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_pri_power_word_shield_AuraScript::HandleOnRemove, EFFECT_0, AuraType::SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pri_power_word_shield_AuraScript();
    }
};

// 33110 - Prayer of Mending Heal
class spell_pri_prayer_of_mending_heal : public SpellScriptLoader
{
    public:
        spell_pri_prayer_of_mending_heal() : SpellScriptLoader("spell_pri_prayer_of_mending_heal") { }

        class spell_pri_prayer_of_mending_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_prayer_of_mending_heal_SpellScript);

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
                OnEffectHitTarget += SpellEffectFn(spell_pri_prayer_of_mending_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_prayer_of_mending_heal_SpellScript();
        }
};

// 139 - Renew
class spell_pri_renew : public SpellScriptLoader
{
    public:
        spell_pri_renew() : SpellScriptLoader("spell_pri_renew") { }

        class spell_pri_renew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_renew_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_DIVINE_TOUCH))
                    return false;
                return true;
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
                        uint32 heal = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), aurEff->GetAmount(), DOT, aurEff->GetSpellEffectInfo());
                        heal = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), heal, DOT, aurEff->GetSpellEffectInfo());
                        int32 basepoints0 = CalculatePct(int32(heal) * aurEff->GetTotalTicks(), empoweredRenewAurEff->GetAmount());
                        caster->CastCustomSpell(GetTarget(), SPELL_PRIEST_DIVINE_TOUCH, &basepoints0, NULL, NULL, true, NULL, aurEff);
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_pri_renew_AuraScript::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_renew_AuraScript();
        }
};

// 32379 - Shadow Word Death
class spell_pri_shadow_word_death : public SpellScriptLoader
{
    public:
        spell_pri_shadow_word_death() : SpellScriptLoader("spell_pri_shadow_word_death") { }

        class spell_pri_shadow_word_death_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_shadow_word_death_SpellScript);

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
                OnHit += SpellHitFn(spell_pri_shadow_word_death_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_shadow_word_death_SpellScript();
        }
};

// 15473 - Shadowform
class spell_pri_shadowform : public SpellScriptLoader
{
    public:
        spell_pri_shadowform() : SpellScriptLoader("spell_pri_shadowform") { }

        class spell_pri_shadowform_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_shadowform_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pri_shadowform_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pri_shadowform_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_shadowform_AuraScript();
        }
};

// 15286 - Vampiric Embrace
class spell_pri_vampiric_embrace : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_embrace() : SpellScriptLoader("spell_pri_vampiric_embrace") { }

        class spell_pri_vampiric_embrace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_vampiric_embrace_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL))
                    return false;
                return true;
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

                GetTarget()->CastCustomSpell((Unit*)NULL, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, &team, &self, NULL, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_embrace_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_embrace_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_vampiric_embrace_AuraScript();
        }
};

// 15290 - Vampiric Embrace (heal)
class spell_pri_vampiric_embrace_target : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_embrace_target() : SpellScriptLoader("spell_pri_vampiric_embrace_target") { }

        class spell_pri_vampiric_embrace_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_vampiric_embrace_target_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove(GetCaster());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_vampiric_embrace_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_vampiric_embrace_target_SpellScript();
        }
};

// 34914 - Vampiric Touch
class spell_pri_vampiric_touch : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_touch() : SpellScriptLoader("spell_pri_vampiric_touch") { }

        class spell_pri_vampiric_touch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_vampiric_touch_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL) ||
                    !sSpellMgr->GetSpellInfo(SPELL_GEN_REPLENISHMENT))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetUnitOwner())
                        if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                        {
                            int32 damage = aurEff->GetAmount() * 8;
                            // backfire damage
                            caster->CastCustomSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, &damage, NULL, NULL, true, NULL, aurEff);
                        }
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget() == GetCaster();
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                eventInfo.GetProcTarget()->CastSpell((Unit*)NULL, SPELL_GEN_REPLENISHMENT, true, NULL, aurEff);
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_pri_vampiric_touch_AuraScript::HandleDispel);
                DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_touch_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_touch_AuraScript::HandleEffectProc, EFFECT_2, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pri_vampiric_touch_AuraScript();
        }
};

// 121536 - Angelic Feather talent
class spell_pri_angelic_feather_trigger : public SpellScriptLoader
{
    public:
        spell_pri_angelic_feather_trigger() : SpellScriptLoader("spell_pri_angelic_feather_trigger") { }

        class spell_pri_angelic_feather_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_angelic_feather_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER))
                    return false;
                return true;
            }

            void HandleEffectDummy(SpellEffIndex /*effIndex*/)
            {
                Position destPos = GetHitDest()->GetPosition();
                float radius = GetEffectInfo()->CalcRadius();

                // Caster is prioritary
                if (GetCaster()->IsWithinDist2d(&destPos, radius))
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_ANGELIC_FEATHER_AURA, true);
                }
                else
                {
                    SpellCastTargets targets;
                    targets.SetDst(destPos);
                    GetCaster()->CastSpell(targets, sSpellMgr->GetSpellInfo(SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER), nullptr);
                }
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_pri_angelic_feather_trigger_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pri_angelic_feather_trigger_SpellScript();
        }
};

// Angelic Feather areatrigger - created by SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER
class areatrigger_pri_angelic_feather : public AreaTriggerEntityScript
{
public:
    areatrigger_pri_angelic_feather() : AreaTriggerEntityScript("areatrigger_pri_angelic_feather") { }

    struct areatrigger_pri_angelic_featherAI : AreaTriggerAI
    {
        areatrigger_pri_angelic_featherAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        // Called when the AreaTrigger has just been initialized, just before added to map
        void OnInitialize() override
        {
            if (Unit* caster = at->GetCaster())
            {
                std::vector<AreaTrigger*> areaTriggers = caster->GetAreaTriggers(SPELL_PRIEST_ANGELIC_FEATHER_AREATRIGGER);

                if (areaTriggers.size() >= 3)
                    areaTriggers.front()->SetDuration(0);
            }
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
            {
                if (caster->IsFriendlyTo(unit))
                {
                    // If target already has aura, increase duration to max 130% of initial duration
                    caster->CastSpell(unit, SPELL_PRIEST_ANGELIC_FEATHER_AURA, true);
                    at->SetDuration(0);
                }
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_pri_angelic_featherAI(areatrigger);
    }
};

void AddSC_priest_spell_scripts()
{
    new spell_pri_body_and_soul();
    new spell_pri_circle_of_healing();
    new spell_pri_dispel_magic();
    new spell_pri_divine_aegis();
    new spell_pri_divine_hymn();
    new spell_pri_glyph_of_prayer_of_healing();
    new spell_pri_hymn_of_hope();
    new spell_pri_improved_power_word_shield();
    new spell_pri_item_greater_heal_refund();
    new spell_pri_guardian_spirit();
    new spell_pri_leap_of_faith_effect_trigger();
    new spell_pri_levitate();
    new spell_pri_lightwell_renew();
    new spell_pri_mana_burn();
    new spell_pri_mana_leech();
    new spell_pri_mind_sear();
    new spell_pri_pain_and_suffering_proc();
    new spell_pri_penance();
    new spell_pri_phantasm();
    new spell_pri_power_word_shield();
    new spell_pri_prayer_of_mending_heal();
    new spell_pri_renew();
    new spell_pri_shadow_word_death();
    new spell_pri_shadowform();
    new spell_pri_vampiric_embrace();
    new spell_pri_vampiric_embrace_target();
    new spell_pri_vampiric_touch();
    new spell_pri_angelic_feather_trigger();
    new areatrigger_pri_angelic_feather();
}
