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
#include "Group.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum PaladinSpells
{
    SPELL_PALADIN_AVENGERS_SHIELD                = 31935,
    SPELL_PALADIN_AURA_MASTERY_IMMUNE            = 64364,
    SPELL_PALADIN_BEACON_OF_LIGHT                = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL           = 53652,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID   = 37878,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN = 37879,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST  = 37880,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN  = 37881,
    SPELL_PALADIN_BLINDING_LIGHT_EFFECT          = 105421,
    SPELL_PALADIN_CONCENTRACTION_AURA            = 19746,
    SPELL_PALADIN_DIVINE_PURPOSE_PROC            = 90174,
    SPELL_PALADIN_DIVINE_STEED_HUMAN             = 221883,
    SPELL_PALADIN_DIVINE_STEED_DRAENEI           = 221887,
    SPELL_PALADIN_DIVINE_STEED_BLOODELF          = 221886,
    SPELL_PALADIN_DIVINE_STEED_TAUREN            = 221885,
    SPELL_PALADIN_DIVINE_STORM_DAMAGE            = 224239,
    SPELL_PALADIN_ENDURING_LIGHT                 = 40471,
    SPELL_PALADIN_ENDURING_JUDGEMENT             = 40472,
    SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1          = 9799,
    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE          = 25997,
    SPELL_PALADIN_FINAL_STAND                    = 204077,
    SPELL_PALADIN_FINAL_STAND_EFFECT             = 204079,
    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_HOLY_MENDING                   = 64891,
    SPELL_PALADIN_HOLY_POWER_ARMOR               = 28790,
    SPELL_PALADIN_HOLY_POWER_ATTACK_POWER        = 28791,
    SPELL_PALADIN_HOLY_POWER_SPELL_POWER         = 28793,
    SPELL_PALADIN_HOLY_POWER_MP5                 = 28795,
    SPELL_PALADIN_HOLY_SHOCK_R1                  = 20473,
    SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE           = 25912,
    SPELL_PALADIN_HOLY_SHOCK_R1_HEALING          = 25914,
    SPELL_PALADIN_IMMUNE_SHIELD_MARKER           = 61988,
    SPELL_PALADIN_ITEM_HEALING_TRANCE            = 37706,
    SPELL_PALADIN_JUDGEMENT_DAMAGE               = 54158,
    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT        = 31790,
    SPELL_PALADIN_SANCTIFIED_WRATH               = 57318,
    SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1     = 53375,
    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS          = 25742
};

enum PaladinSpellVisualKit
{
    PALADIN_VISUAL_KIT_DIVINE_STORM = 73892
};

/*
// 31850 - Ardent Defender
class spell_pal_ardent_defender : public SpellScriptLoader
{
    public:
        spell_pal_ardent_defender() : SpellScriptLoader("spell_pal_ardent_defender") { }

        class spell_pal_ardent_defender_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_ardent_defender_AuraScript);

            uint32 _absorbPct = 0;
            uint32 _healPct = 0;

            enum Spell
            {
                PAL_SPELL_ARDENT_DEFENDER_HEAL = 66235
            };

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ PAL_SPELL_ARDENT_DEFENDER_HEAL });
            }

            bool Load() override
            {
                _absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
                _healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & canBeRecalculated)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                Unit* victim = GetTarget();
                int32 remainingHealth = victim->GetHealth() - dmgInfo.GetDamage();
                uint32 allowedHealth = victim->CountPctFromMaxHealth(35);
                // If damage kills us
                if (remainingHealth <= 0 && !victim->ToPlayer()->HasSpellCooldown(PAL_SPELL_ARDENT_DEFENDER_HEAL))
                {
                    // Cast healing spell, completely avoid damage
                    absorbAmount = dmgInfo.GetDamage();

                    float defenseSkillValue = victim->GetDefenseSkillValue();
                    // Max heal when defense skill denies critical hits from raid bosses
                    // Formula: max defense at level + 140 (raiting from gear)
                    float reqDefForMaxHeal = victim->GetMaxSkillValueForLevel() + 140.0f;
                    float defenseFactor = std::min(1.0f, defenseSkillValue / reqDefForMaxHeal);

                    int32 healAmount = int32(victim->CountPctFromMaxHealth(static_cast<uint32>(lroundf(_healPct * defenseFactor))));
                    victim->CastCustomSpell(victim, PAL_SPELL_ARDENT_DEFENDER_HEAL, &healAmount, nullptr, nullptr, true, nullptr, aurEff);
                    victim->ToPlayer()->AddSpellCooldown(PAL_SPELL_ARDENT_DEFENDER_HEAL, 0, time(nullptr) + 120);
                }
                else if (remainingHealth < int32(allowedHealth))
                {
                    // Reduce damage that brings us under 35% (or full damage if we are already under 35%) by x%
                    uint32 damageToReduce = (victim->GetHealth() < allowedHealth)
                        ? dmgInfo.GetDamage()
                        : allowedHealth - remainingHealth;
                    absorbAmount = CalculatePct(damageToReduce, _absorbPct);
                }
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_ardent_defender_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_ardent_defender_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_ardent_defender_AuraScript();
        }
};
*/

// 37877 - Blessing of Faith
class spell_pal_blessing_of_faith : public SpellScript
{
    PrepareSpellScript(spell_pal_blessing_of_faith);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID,
            SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN,
            SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST,
            SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* unitTarget = GetHitUnit())
        {
            uint32 spell_id = 0;
            switch (unitTarget->getClass())
            {
                case CLASS_DRUID:
                    spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID;
                    break;
                case CLASS_PALADIN:
                    spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN;
                    break;
                case CLASS_PRIEST:
                    spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST;
                    break;
                case CLASS_SHAMAN:
                    spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN;
                    break;
                default:
                    return; // ignore for non-healing classes
            }
            Unit* caster = GetCaster();
            caster->CastSpell(caster, spell_id, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_blessing_of_faith::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1022 - Blessing of Protection
// 204018 - Blessing of Spellwarding
class spell_pal_blessing_of_protection : public SpellScript
{
    PrepareSpellScript(spell_pal_blessing_of_protection);

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
    PrepareSpellScript(spell_pal_blinding_light);

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

// 642 - Divine Shield
class spell_pal_divine_shield : public SpellScript
{
    PrepareSpellScript(spell_pal_divine_shield);

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
    PrepareSpellScript(spell_pal_divine_steed);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PALADIN_DIVINE_STEED_HUMAN,
            SPELL_PALADIN_DIVINE_STEED_DRAENEI,
            SPELL_PALADIN_DIVINE_STEED_BLOODELF,
            SPELL_PALADIN_DIVINE_STEED_TAUREN
        });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();

        uint32 spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
        switch (caster->getRace())
        {
            case RACE_HUMAN:
            case RACE_DWARF:
                spellId = SPELL_PALADIN_DIVINE_STEED_HUMAN;
                break;
            case RACE_DRAENEI:
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
    PrepareSpellScript(spell_pal_divine_storm);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_STORM_DAMAGE });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();
        caster->SendPlaySpellVisualKit(PALADIN_VISUAL_KIT_DIVINE_STORM, 0, 0);
    }

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        caster->CastSpell(target, SPELL_PALADIN_DIVINE_STORM_DAMAGE, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_pal_divine_storm::HandleOnCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_divine_storm::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// -75806 - Grand Crusader
class spell_pal_grand_crusader : public SpellScriptLoader
{
    public:
        spell_pal_grand_crusader() : SpellScriptLoader("spell_pal_grand_crusader") { }

        class spell_pal_grand_crusader_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_grand_crusader_AuraScript);

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
                DoCheckProc += AuraCheckProcFn(spell_pal_grand_crusader_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_grand_crusader_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_grand_crusader_AuraScript();
        }
};

// 54968 - Glyph of Holy Light
class spell_pal_glyph_of_holy_light : public SpellScript
{
    PrepareSpellScript(spell_pal_glyph_of_holy_light);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 const maxTargets = GetSpellInfo()->MaxAffectedTargets;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(maxTargets);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_glyph_of_holy_light::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
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

        public:
            spell_pal_hand_of_sacrifice_AuraScript()
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
                OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_hand_of_sacrifice_AuraScript();
        }
};

// 20473 - Holy Shock
class spell_pal_holy_shock : public SpellScript
{
    PrepareSpellScript(spell_pal_holy_shock);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_R1, DIFFICULTY_NONE);
        if (!firstRankSpellInfo)
            return false;

        // can't use other spell than holy shock due to spell_ranks dependency
        if (!spellInfo->IsRankOf(firstRankSpellInfo))
            return false;

        uint8 rank = spellInfo->GetRank();
        if (!sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE, rank, true) || !sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING, rank, true))
            return false;

        return true;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            uint8 rank = GetSpellInfo()->GetRank();
            if (caster->IsFriendlyTo(unitTarget))
                caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING, rank), true);
            else
                caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE, rank), true);
        }
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

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 37705 - Healing Discount
class spell_pal_item_healing_discount : public AuraScript
{
    PrepareAuraScript(spell_pal_item_healing_discount);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ITEM_HEALING_TRANCE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ITEM_HEALING_TRANCE, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_item_healing_discount::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 40470 - Paladin Tier 6 Trinket
class spell_pal_item_t6_trinket : public AuraScript
{
    PrepareAuraScript(spell_pal_item_t6_trinket);

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
            eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_item_t6_trinket::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 20271 - Judgement
/// Updated 4.3.4
class spell_pal_judgement : public SpellScriptLoader
{
    public:
        spell_pal_judgement() : SpellScriptLoader("spell_pal_judgement") { }

        class spell_pal_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_SpellScript);

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_JUDGEMENT_DAMAGE });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = SPELL_PALADIN_JUDGEMENT_DAMAGE;

                // some seals have SPELL_AURA_DUMMY in EFFECT_2
                Unit::AuraEffectList const& auras = GetCaster()->GetAuraEffectsByType(SPELL_AURA_DUMMY);
                for (Unit::AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                {
                    if ((*i)->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_SEAL && (*i)->GetEffIndex() == EFFECT_2)
                    {
                        if (sSpellMgr->GetSpellInfo((*i)->GetAmount(), GetCastDifficulty()))
                        {
                            spellId = (*i)->GetAmount();
                            break;
                        }
                    }
                }

                GetCaster()->CastSpell(GetHitUnit(), spellId, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgement_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_judgement_SpellScript();
        }
};

// 633 - Lay on Hands
class spell_pal_lay_on_hands : public SpellScript
{
    PrepareSpellScript(spell_pal_lay_on_hands);

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
class spell_pal_light_s_beacon : public SpellScriptLoader
{
    public:
        spell_pal_light_s_beacon() : SpellScriptLoader("spell_pal_light_s_beacon") { }

        class spell_pal_light_s_beacon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_light_s_beacon_AuraScript);

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
                        std::list<AuraApplication*> applications;
                        (*itr)->GetApplicationList(applications);
                        if (!applications.empty())
                            eventInfo.GetActor()->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, heal, applications.front()->GetTarget(), true);
                        return;
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_light_s_beacon_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_light_s_beacon_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_light_s_beacon_AuraScript();
        }
};

// 85256 - Templar's Verdict
/// Updated 4.3.4
class spell_pal_templar_s_verdict : public SpellScript
{
    PrepareSpellScript(spell_pal_templar_s_verdict);

    bool Validate (SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_PURPOSE_PROC });
    }

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
            return false;

        return true;
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        int32 damage = GetHitDamage();

        if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
            damage *= 7.5;  // 7.5*30% = 225%
        else
        {
            switch (caster->GetPower(POWER_HOLY_POWER))
            {
                case 0: // 1 Holy Power
                    // same damage
                    break;
                case 1: // 2 Holy Power
                    damage *= 3;    // 3*30 = 90%
                    break;
                case 2: // 3 Holy Power
                    damage *= 7.5;  // 7.5*30% = 225%
                    break;
            }
        }

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict::ChangeDamage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

// 28789 - Holy Power
class spell_pal_t3_6p_bonus : public SpellScriptLoader
{
    public:
        spell_pal_t3_6p_bonus() : SpellScriptLoader("spell_pal_t3_6p_bonus") { }

        class spell_pal_t3_6p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_t3_6p_bonus_AuraScript);

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

                switch (target->getClass())
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

                caster->CastSpell(target, spellId, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_t3_6p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_t3_6p_bonus_AuraScript();
        }
};

// 64890 Item - Paladin T8 Holy 2P Bonus
class spell_pal_t8_2p_bonus : public SpellScriptLoader
{
    public:
        spell_pal_t8_2p_bonus() : SpellScriptLoader("spell_pal_t8_2p_bonus") { }

        class spell_pal_t8_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_t8_2p_bonus_AuraScript);

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
                amount /= spellInfo->GetMaxTicks();
                // Add remaining ticks to damage done
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_PALADIN_HOLY_MENDING, SPELL_AURA_PERIODIC_HEAL);

                caster->CastCustomSpell(SPELL_PALADIN_HOLY_MENDING, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_t8_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_t8_2p_bonus_AuraScript();
        }
};

void AddSC_paladin_spell_scripts()
{
    //new spell_pal_ardent_defender();
    RegisterSpellScript(spell_pal_blessing_of_faith);
    RegisterSpellScript(spell_pal_blessing_of_protection);
    RegisterSpellScript(spell_pal_blinding_light);
    RegisterSpellScript(spell_pal_divine_shield);
    RegisterSpellScript(spell_pal_divine_steed);
    RegisterSpellScript(spell_pal_divine_storm);
    RegisterSpellScript(spell_pal_glyph_of_holy_light);
    new spell_pal_grand_crusader();
    new spell_pal_hand_of_sacrifice();
    RegisterSpellScript(spell_pal_holy_shock);
    RegisterAuraScript(spell_pal_item_healing_discount);
    RegisterAuraScript(spell_pal_item_t6_trinket);
    new spell_pal_judgement();
    RegisterSpellScript(spell_pal_lay_on_hands);
    new spell_pal_light_s_beacon();
    RegisterSpellScript(spell_pal_templar_s_verdict);
    new spell_pal_t3_6p_bonus();
    new spell_pal_t8_2p_bonus();
}
