/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "Group.h"

enum PaladinSpells
{
    SPELL_PALADIN_DIVINE_PLEA                    = 54428,
    SPELL_PALADIN_BLESSING_OF_SANCTUARY_BUFF     = 67480,
    SPELL_PALADIN_BLESSING_OF_SANCTUARY_ENERGIZE = 57319,

    SPELL_PALADIN_HOLY_SHOCK_R1                  = 20473,
    SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE           = 25912,
    SPELL_PALADIN_HOLY_SHOCK_R1_HEALING          = 25914,
    SPELL_PALADIN_ILLUMINATION_ENERGIZE          = 20272,

    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID   = 37878,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN = 37879,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST  = 37880,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN  = 37881,

    SPELL_PALADIN_BEACON_OF_LIGHT                = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_1         = 53652,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_2         = 53653,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_3         = 53654,
    SPELL_PALADIN_HOLY_LIGHT                     = 635,

    SPELL_PALADIN_DIVINE_STORM                   = 53385,
    SPELL_PALADIN_DIVINE_STORM_DUMMY             = 54171,
    SPELL_PALADIN_DIVINE_STORM_HEAL              = 54172,

    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE          = 25997,

    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_AVENGING_WRATH_MARKER          = 61987,
    SPELL_PALADIN_IMMUNE_SHIELD_MARKER           = 61988,

    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_DIVINE_SACRIFICE               = 64205,

    SPELL_PALADIN_ITEM_HEALING_TRANCE            = 37706,

    SPELL_PALADIN_JUDGEMENT_DAMAGE               = 54158,
    SPELL_PALADIN_JUDGEMENT_OF_JUSTICE           = 20184,
    SPELL_PALADIN_JUDGEMENT_OF_LIGHT             = 20185,
    SPELL_PALADIN_JUDGEMENT_OF_WISDOM            = 20186,

    SPELL_PALADIN_JUDGEMENT_OF_LIGHT_HEAL        = 20267,
    SPELL_PALADIN_JUDGEMENT_OF_WISDOM_MANA       = 20268,

    SPELL_PALADIN_GLYPH_OF_SALVATION             = 63225,

    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT        = 31790,

    SPELL_PALADIN_SANCTIFIED_WRATH               = 57318,
    SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1     = 53375,

    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS          = 25742,

    SPELL_PALADIN_CONCENTRACTION_AURA            = 19746,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1      = 31869,
    SPELL_PALADIN_SWIFT_RETRIBUTION_R1           = 53379,

    SPELL_PALADIN_IMPROVED_CONCENTRACTION_AURA   = 63510,
    SPELL_PALADIN_IMPROVED_DEVOTION_AURA         = 63514,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA    = 63531,
    SPELL_PALADIN_AURA_MASTERY_IMMUNE            = 64364,

    SPELL_GENERIC_ARENA_DAMPENING                = 74410,
    SPELL_GENERIC_BATTLEGROUND_DAMPENING         = 74411,

    SPELL_PALADIN_SACRED_SHIELD                  = 53601,
    SPELL_PALADIN_T9_HOLY_4P_BONUS               = 67191,
    SPELL_PALADIN_FLASH_OF_LIGHT_PROC            = 66922,

    SPELL_PALADIN_JUDGEMENTS_OF_THE_JUST_PROC    = 68055,

    SPELL_PALADIN_GLYPH_OF_DIVINITY_PROC         = 54986,

    SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE_MANA    = 31930,
    SPELL_REPLENISHMENT                          = 57669,
    SPELL_PALADIN_RIGHTEOUS_VENGEANCE_DAMAGE     = 61840,
    SPELL_PALADIN_SHEATH_OF_LIGHT_HEAL           = 54203,
    SPELL_PALADIN_SACRED_SHIELD_TRIGGER          = 58597,
    SPELL_PALADIN_T8_HOLY_4P_BONUS               = 64895,
    SPELL_PALADIN_HEART_OF_THE_CRUSADER_EFF_R1   = 21183,

    SPELL_PALADIN_HOLY_POWER_ARMOR               = 28790,
    SPELL_PALADIN_HOLY_POWER_ATTACK_POWER        = 28791,
    SPELL_PALADIN_HOLY_POWER_SPELL_POWER         = 28793,
    SPELL_PALADIN_HOLY_POWER_MP5                 = 28795,

    SPELL_PALADIN_HOLY_VENGEANCE                 = 31803,
    SPELL_PALADIN_SEAL_OF_VENGEANCE_DAMAGE       = 42463,
    SPELL_PALADIN_BLOOD_CORRUPTION               = 53742,
    SPELL_PALADIN_SEAL_OF_CORRUPTION_DAMAGE      = 53739,

    SPELL_PALADIN_SPIRITUAL_ATTUNEMENT_MANA      = 31786,

    SPELL_PALADIN_ENDURING_LIGHT                 = 40471,
    SPELL_PALADIN_ENDURING_JUDGEMENT             = 40472,

    SPELL_PALADIN_GLYPH_OF_HOLY_LIGHT_HEAL       = 54968,
    SPELL_PALADIN_HOLY_MENDING                   = 64891
};

enum PaladinSpellIcons
{
    PALADIN_ICON_ID_RETRIBUTION_AURA             = 555
};

// 31850 - Ardent Defender
class spell_pal_ardent_defender : public SpellScriptLoader
{
    public:
        spell_pal_ardent_defender() : SpellScriptLoader("spell_pal_ardent_defender") { }

        class spell_pal_ardent_defender_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_ardent_defender_AuraScript);

        public:
            spell_pal_ardent_defender_AuraScript()
            {
                absorbPct = 0;
                healPct = 0;
            }

        private:
            uint32 absorbPct, healPct;

            enum Spell
            {
                PAL_SPELL_ARDENT_DEFENDER_HEAL = 66235,
            };

            bool Load() override
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit* victim = GetTarget();
                int32 remainingHealth = victim->GetHealth() - dmgInfo.GetDamage();
                uint32 allowedHealth = victim->CountPctFromMaxHealth(35);
                // If damage kills us
                if (remainingHealth <= 0 && !victim->GetSpellHistory()->HasCooldown(PAL_SPELL_ARDENT_DEFENDER_HEAL))
                {
                    // Cast healing spell, completely avoid damage
                    absorbAmount = dmgInfo.GetDamage();

                    uint32 defenseSkillValue = victim->GetDefenseSkillValue();
                    // Max heal when defense skill denies critical hits from raid bosses
                    // Formula: max defense at level + 140 (raiting from gear)
                    uint32 reqDefForMaxHeal  = victim->getLevel() * 5 + 140;
                    float pctFromDefense = (defenseSkillValue >= reqDefForMaxHeal)
                        ? 1.0f
                        : float(defenseSkillValue) / float(reqDefForMaxHeal);

                    int32 healAmount = int32(victim->CountPctFromMaxHealth(uint32(healPct * pctFromDefense)));
                    victim->CastCustomSpell(victim, PAL_SPELL_ARDENT_DEFENDER_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff);
                    victim->GetSpellHistory()->AddCooldown(PAL_SPELL_ARDENT_DEFENDER_HEAL, 0, std::chrono::minutes(2));
                }
                else if (remainingHealth < int32(allowedHealth))
                {
                    // Reduce damage that brings us under 35% (or full damage if we are already under 35%) by x%
                    uint32 damageToReduce = (victim->GetHealth() < allowedHealth)
                        ? dmgInfo.GetDamage()
                        : allowedHealth - remainingHealth;
                    absorbAmount = CalculatePct(damageToReduce, absorbPct);
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

// 31821 - Aura Mastery
class spell_pal_aura_mastery : public SpellScriptLoader
{
    public:
        spell_pal_aura_mastery() : SpellScriptLoader("spell_pal_aura_mastery") { }

        class spell_pal_aura_mastery_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_aura_mastery_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_AURA_MASTERY_IMMUNE))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_AURA_MASTERY_IMMUNE, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveOwnedAura(SPELL_PALADIN_AURA_MASTERY_IMMUNE, GetCasterGUID());
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pal_aura_mastery_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_aura_mastery_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_aura_mastery_AuraScript();
        }
};

// 64364 - Aura Mastery Immune
class spell_pal_aura_mastery_immune : public SpellScriptLoader
{
    public:
        spell_pal_aura_mastery_immune() : SpellScriptLoader("spell_pal_aura_mastery_immune") { }

        class spell_pal_aura_mastery_immune_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_aura_mastery_immune_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_CONCENTRACTION_AURA))
                    return false;
                return true;
            }

            bool CheckAreaTarget(Unit* target)
            {
                return target->HasAura(SPELL_PALADIN_CONCENTRACTION_AURA, GetCasterGUID());
            }

            void Register() override
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_pal_aura_mastery_immune_AuraScript::CheckAreaTarget);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_aura_mastery_immune_AuraScript();
        }
};

// 31884 - Avenging Wrath
class spell_pal_avenging_wrath : public SpellScriptLoader
{
    public:
        spell_pal_avenging_wrath() : SpellScriptLoader("spell_pal_avenging_wrath") { }

        class spell_pal_avenging_wrath_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_avenging_wrath_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SANCTIFIED_WRATH)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1))
                    return false;
                return true;
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (AuraEffect const* aurEff = target->GetAuraEffectOfRankedSpell(SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1, EFFECT_2))
                {
                    int32 basepoints = aurEff->GetAmount();
                    target->CastCustomSpell(target, SPELL_PALADIN_SANCTIFIED_WRATH, &basepoints, &basepoints, NULL, true, NULL, aurEff);
                }
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_PALADIN_SANCTIFIED_WRATH);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_pal_avenging_wrath_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_avenging_wrath_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_avenging_wrath_AuraScript();
        }
};

// 37877 - Blessing of Faith
class spell_pal_blessing_of_faith : public SpellScriptLoader
{
    public:
        spell_pal_blessing_of_faith() : SpellScriptLoader("spell_pal_blessing_of_faith") { }

        class spell_pal_blessing_of_faith_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_blessing_of_faith_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN))
                    return false;
                return true;
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
                OnEffectHitTarget += SpellEffectFn(spell_pal_blessing_of_faith_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_blessing_of_faith_SpellScript();
        }
};

// 20911 - Blessing of Sanctuary
// 25899 - Greater Blessing of Sanctuary
class spell_pal_blessing_of_sanctuary : public SpellScriptLoader
{
    public:
        spell_pal_blessing_of_sanctuary() : SpellScriptLoader("spell_pal_blessing_of_sanctuary") { }

        class spell_pal_blessing_of_sanctuary_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_blessing_of_sanctuary_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_SANCTUARY_BUFF))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_SANCTUARY_ENERGIZE))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (Unit* caster = GetCaster())
                    caster->CastSpell(target, SPELL_PALADIN_BLESSING_OF_SANCTUARY_BUFF, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->RemoveAura(SPELL_PALADIN_BLESSING_OF_SANCTUARY_BUFF, GetCasterGUID());
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetTarget()->getPowerType() == POWER_MANA;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_BLESSING_OF_SANCTUARY_ENERGIZE, true, NULL, aurEff);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pal_blessing_of_sanctuary_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_blessing_of_sanctuary_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                DoCheckProc += AuraCheckProcFn(spell_pal_blessing_of_sanctuary_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_blessing_of_sanctuary_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_blessing_of_sanctuary_AuraScript();
        }
};

// -31871 - Divine Purpose
class spell_pal_divine_purpose : public SpellScriptLoader
{
    public:
        spell_pal_divine_purpose() : SpellScriptLoader("spell_pal_divine_purpose") { }

        class spell_pal_divine_purpose_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_divine_purpose_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (!roll_chance_i(aurEff->GetAmount()))
                    return;

                eventInfo.GetProcTarget()->RemoveAurasWithMechanic(1 << MECHANIC_STUN, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_divine_purpose_AuraScript::HandleProc, EFFECT_2, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_divine_purpose_AuraScript();
        }
};

// 64205 - Divine Sacrifice
class spell_pal_divine_sacrifice : public SpellScriptLoader
{
    public:
        spell_pal_divine_sacrifice() : SpellScriptLoader("spell_pal_divine_sacrifice") { }

        class spell_pal_divine_sacrifice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_divine_sacrifice_AuraScript);

            uint32 groupSize, minHpPct;
            int32 remainingAmount;

            bool Load() override
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (caster->ToPlayer()->GetGroup())
                            groupSize = caster->ToPlayer()->GetGroup()->GetMembersCount();
                        else
                            groupSize = 1;
                    }
                    else
                        return false;

                    remainingAmount = (caster->CountPctFromMaxHealth(GetSpellInfo()->Effects[EFFECT_2].CalcValue(caster)) * groupSize);
                    minHpPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(caster);
                    return true;
                }
                return false;
            }

            void Split(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & splitAmount)
            {
                remainingAmount -= splitAmount;
                // break when absorbed everything it could, or if the casters hp drops below 20%
                if (Unit* caster = GetCaster())
                    if (remainingAmount <= 0 || (caster->GetHealthPct() < minHpPct))
                        caster->RemoveAura(SPELL_PALADIN_DIVINE_SACRIFICE);
            }

            void Register() override
            {
                OnEffectSplit += AuraEffectSplitFn(spell_pal_divine_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_divine_sacrifice_AuraScript();
        }
};

// 53385 - Divine Storm
class spell_pal_divine_storm : public SpellScriptLoader
{
    public:
        spell_pal_divine_storm() : SpellScriptLoader("spell_pal_divine_storm") { }

        class spell_pal_divine_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_divine_storm_SpellScript);

        public:
            spell_pal_divine_storm_SpellScript()
            {
                healPct = 0;
            }

        private:
            uint32 healPct;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STORM_DUMMY))
                    return false;
                return true;
            }

            bool Load() override
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }

            void TriggerHeal()
            {
                Unit* caster = GetCaster();
                caster->CastCustomSpell(SPELL_PALADIN_DIVINE_STORM_DUMMY, SPELLVALUE_BASE_POINT0, (GetHitDamage() * healPct) / 100, caster, true);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_pal_divine_storm_SpellScript::TriggerHeal);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_divine_storm_SpellScript();
        }
};

// 54171 - Divine Storm (Dummy)
class spell_pal_divine_storm_dummy : public SpellScriptLoader
{
    public:
        spell_pal_divine_storm_dummy() : SpellScriptLoader("spell_pal_divine_storm_dummy") { }

        class spell_pal_divine_storm_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_divine_storm_dummy_SpellScript);

        public:
            spell_pal_divine_storm_dummy_SpellScript()
            {
                _targetCount = 0;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STORM_HEAL))
                    return false;
                return true;
            }

            void CountTargets(std::list<WorldObject*>& targetList)
            {
                _targetCount = targetList.size();
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!_targetCount || ! GetHitUnit())
                    return;

                int32 heal = GetEffectValue() / _targetCount;
                GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_PALADIN_DIVINE_STORM_HEAL, &heal, NULL, NULL, true);
            }
        private:
            uint32 _targetCount;

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_divine_storm_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_divine_storm_dummy_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_divine_storm_dummy_SpellScript();
        }
};

// 33695 - Exorcism and Holy Wrath Damage
class spell_pal_exorcism_and_holy_wrath_damage : public SpellScriptLoader
{
    public:
        spell_pal_exorcism_and_holy_wrath_damage() : SpellScriptLoader("spell_pal_exorcism_and_holy_wrath_damage") { }

        class spell_pal_exorcism_and_holy_wrath_damage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_exorcism_and_holy_wrath_damage_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(aurEff->GetBase());
                    spellMod->op = SPELLMOD_DAMAGE;
                    spellMod->type = SPELLMOD_FLAT;
                    spellMod->spellId = GetId();
                    spellMod->mask[1] = 0x200002;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() override
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pal_exorcism_and_holy_wrath_damage_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_exorcism_and_holy_wrath_damage_AuraScript();
        }
};

// -9799 - Eye for an Eye
class spell_pal_eye_for_an_eye : public SpellScriptLoader
{
    public:
        spell_pal_eye_for_an_eye() : SpellScriptLoader("spell_pal_eye_for_an_eye") { }

        class spell_pal_eye_for_an_eye_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_eye_for_an_eye_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                // return damage % to attacker but < 50% own total health
                int32 damage = int32(std::min(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()), GetTarget()->GetMaxHealth() / 2));
                GetTarget()->CastCustomSpell(SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_eye_for_an_eye_AuraScript();
        }
};

// 54939 - Glyph of Divinity
class spell_pal_glyph_of_divinity : public SpellScriptLoader
{
    public:
        spell_pal_glyph_of_divinity() : SpellScriptLoader("spell_pal_glyph_of_divinity") { }

        class spell_pal_glyph_of_divinity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_glyph_of_divinity_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_GLYPH_OF_DIVINITY_PROC))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                // Lay on Hands (Rank 1) does not have mana effect
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || spellInfo->Effects[EFFECT_1].Effect != SPELL_EFFECT_ENERGIZE)
                    return;

                Unit* caster = eventInfo.GetActor();
                if (caster == eventInfo.GetProcTarget())
                    return;

                int32 mana = spellInfo->Effects[EFFECT_1].CalcValue() * 2;
                caster->CastCustomSpell(SPELL_PALADIN_GLYPH_OF_DIVINITY_PROC, SPELLVALUE_BASE_POINT1, mana, (Unit*)nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_glyph_of_divinity_AuraScript::OnProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_glyph_of_divinity_AuraScript();
        }
};

// 54968 - Glyph of Holy Light
class spell_pal_glyph_of_holy_light : public SpellScriptLoader
{
    public:
        spell_pal_glyph_of_holy_light() : SpellScriptLoader("spell_pal_glyph_of_holy_light") { }

        class spell_pal_glyph_of_holy_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_glyph_of_holy_light_SpellScript);

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
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_glyph_of_holy_light_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_glyph_of_holy_light_SpellScript();
        }
};

// 54937 - Glyph of Holy Light (dummy aura)
class spell_pal_glyph_of_holy_light_dummy : public SpellScriptLoader
{
    public:
        spell_pal_glyph_of_holy_light_dummy() : SpellScriptLoader("spell_pal_glyph_of_holy_light_dummy") { }

        class spell_pal_glyph_of_holy_light_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_glyph_of_holy_light_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_GLYPH_OF_HOLY_LIGHT_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());

                caster->CastCustomSpell(SPELL_PALADIN_GLYPH_OF_HOLY_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_glyph_of_holy_light_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_glyph_of_holy_light_dummy_AuraScript();
        }
};

// 63521 - Guarded by The Light
class spell_pal_guarded_by_the_light : public SpellScriptLoader
{
    public:
        spell_pal_guarded_by_the_light() : SpellScriptLoader("spell_pal_guarded_by_the_light") { }

        class spell_pal_guarded_by_the_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_guarded_by_the_light_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_PLEA))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                // Divine Plea
                if (Aura* aura = GetCaster()->GetAura(SPELL_PALADIN_DIVINE_PLEA))
                    aura->RefreshDuration();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_guarded_by_the_light_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_guarded_by_the_light_SpellScript();
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

// 1038 - Hand of Salvation
class spell_pal_hand_of_salvation : public SpellScriptLoader
{
    public:
        spell_pal_hand_of_salvation() : SpellScriptLoader("spell_pal_hand_of_salvation") { }

        class spell_pal_hand_of_salvation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_hand_of_salvation_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Glyph of Salvation
                    if (caster->GetGUID() == GetUnitOwner()->GetGUID())
                        if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_PALADIN_GLYPH_OF_SALVATION, EFFECT_0))
                            amount -= aurEff->GetAmount();
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_hand_of_salvation_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_hand_of_salvation_AuraScript();
        }
};

// -20335 - Heart of the Crusader
class spell_pal_heart_of_the_crusader : public SpellScriptLoader
{
    public:
        spell_pal_heart_of_the_crusader() : SpellScriptLoader("spell_pal_heart_of_the_crusader") { }

        class spell_pal_heart_of_the_crusader_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_heart_of_the_crusader_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HEART_OF_THE_CRUSADER_EFF_R1))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                uint32 spellId = sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HEART_OF_THE_CRUSADER_EFF_R1, GetSpellInfo()->GetRank());
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_heart_of_the_crusader_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_heart_of_the_crusader_AuraScript();
        }
};

// -20473 - Holy Shock
class spell_pal_holy_shock : public SpellScriptLoader
{
    public:
        spell_pal_holy_shock() : SpellScriptLoader("spell_pal_holy_shock") { }

        class spell_pal_holy_shock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_holy_shock_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_R1);
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
                OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_holy_shock_SpellScript();
        }
};

// -20210 - Illumination
class spell_pal_illumination : public SpellScriptLoader
{
public:
    spell_pal_illumination() : SpellScriptLoader("spell_pal_illumination") { }

    class spell_pal_illumination_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_illumination_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING) ||
                !sSpellMgr->GetSpellInfo(SPELL_PALADIN_ILLUMINATION_ENERGIZE) ||
                !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_R1))
                return false;
            return true;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            // this script is valid only for the Holy Shock procs of illumination
            if (eventInfo.GetHealInfo() && eventInfo.GetHealInfo()->GetSpellInfo())
            {
                SpellInfo const* originalSpell = nullptr;

                // if proc comes from the Holy Shock heal, need to get mana cost of original spell - else it's the original heal itself
                if (eventInfo.GetHealInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x00010000)
                    originalSpell = sSpellMgr->GetSpellInfo(sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1, eventInfo.GetHealInfo()->GetSpellInfo()->GetRank()));
                else
                    originalSpell = eventInfo.GetHealInfo()->GetSpellInfo();

                if (originalSpell && aurEff->GetSpellInfo())
                {
                    Unit* target = eventInfo.GetActor(); // Paladin is the target of the energize
                    uint32 bp = CalculatePct(originalSpell->CalcPowerCost(target, originalSpell->GetSchoolMask()), aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue());
                    target->CastCustomSpell(SPELL_PALADIN_ILLUMINATION_ENERGIZE, SPELLVALUE_BASE_POINT0, bp, target, true, nullptr, aurEff);
                }
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_pal_illumination_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pal_illumination_AuraScript();
    }
};

// Maybe this is incorrect
// These spells should always be cast on login, regardless of whether the player has the talent or not

// -20254 - Improved Concentration Aura
// -20138 - Improved Devotion Aura
//  31869 - Sanctified Retribution
// -53379 - Swift Retribution
class spell_pal_improved_aura : public SpellScriptLoader
{
    public:
        spell_pal_improved_aura(char const* name, uint32 spellId) : SpellScriptLoader(name), _spellId(spellId) { }

        class spell_pal_improved_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_improved_aura_AuraScript);

        public:
            spell_pal_improved_aura_AuraScript(uint32 spellId) : AuraScript(), _spellId(spellId) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_spellId)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_SWIFT_RETRIBUTION_R1))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                GetTarget()->RemoveOwnedAura(_spellId, GetCasterGUID()); // need to remove to reapply spellmods
                target->CastSpell(target, _spellId, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                uint32 spellId = GetSpellInfo()->GetFirstRankSpell()->Id;

                if ((spellId == SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1 && GetTarget()->GetAuraOfRankedSpell(SPELL_PALADIN_SWIFT_RETRIBUTION_R1))
                    || (spellId == SPELL_PALADIN_SWIFT_RETRIBUTION_R1 && GetTarget()->GetAuraOfRankedSpell(SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1)))
                    return;

                GetTarget()->RemoveOwnedAura(_spellId, GetCasterGUID());
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pal_improved_aura_AuraScript::HandleEffectApply, EFFECT_FIRST_FOUND, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_improved_aura_AuraScript::HandleEffectRemove, EFFECT_FIRST_FOUND, SPELL_AURA_ADD_FLAT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
            }

        private:
            uint32 _spellId;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_improved_aura_AuraScript(_spellId);
        }

    private:
        uint32 _spellId;
};

// 63510 - Improved Concentration Aura (Area Aura)
// 63514 - Improved Devotion Aura (Area Aura)
// 63531 - Sanctified Retribution (Area Aura)
class spell_pal_improved_aura_effect : public SpellScriptLoader
{
    public:
        spell_pal_improved_aura_effect(char const* name) : SpellScriptLoader(name) { }

        class spell_pal_improved_aura_effect_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_improved_aura_effect_AuraScript);

            bool CheckAreaTarget(Unit* target)
            {
                Unit::AuraApplicationMap& appliedAuras = target->GetAppliedAuras();
                for (Unit::AuraApplicationMap::iterator itr = appliedAuras.begin(); itr != appliedAuras.end(); ++itr)
                {
                    Aura const* aura = itr->second->GetBase();
                    if (aura->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_AURA && aura->GetCasterGUID() == GetCasterGUID())
                    {
                        // Not allow for Retribution Aura (prevent stacking) - Retribution Aura Overflow and Retribution Aura has same spell effects
                        if (GetSpellInfo()->Id == SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA && aura->GetSpellInfo()->SpellIconID == PALADIN_ICON_ID_RETRIBUTION_AURA)
                            return false;
                        return true;
                    }
                }

                return false;
            }

            void Register() override
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_pal_improved_aura_effect_AuraScript::CheckAreaTarget);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_improved_aura_effect_AuraScript();
        }
};

// -20234 - Improved Lay on Hands
class spell_pal_improved_lay_of_hands : public SpellScriptLoader
{
    public:
        spell_pal_improved_lay_of_hands() : SpellScriptLoader("spell_pal_improved_lay_of_hands") { }

        class spell_pal_improved_lay_of_hands_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_improved_lay_of_hands_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].TriggerSpell))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActionTarget()->CastSpell(eventInfo.GetActionTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true, nullptr, aurEff, GetTarget()->GetGUID());
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_improved_lay_of_hands_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_improved_lay_of_hands_AuraScript();
        }
};

// -53569 - Infusion of Light
class spell_pal_infusion_of_light : public SpellScriptLoader
{
    public:
        spell_pal_infusion_of_light() : SpellScriptLoader("spell_pal_infusion_of_light") { }

        class spell_pal_infusion_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_infusion_of_light_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SACRED_SHIELD) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_T9_HOLY_4P_BONUS) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_FLASH_OF_LIGHT_PROC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
                {
                    // Flash of Light HoT on Flash of Light when Sacred Shield active
                    if (spellInfo->SpellFamilyFlags[0] & 0x40000000 && spellInfo->SpellIconID == 242)
                    {
                        PreventDefaultAction();

                        HealInfo* healInfo = eventInfo.GetHealInfo();
                        if (!healInfo || !healInfo->GetHeal())
                            return;

                        Unit* procTarget = eventInfo.GetActionTarget();
                        if (procTarget && procTarget->HasAura(SPELL_PALADIN_SACRED_SHIELD))
                        {
                            Unit* target = GetTarget();
                            int32 duration = sSpellMgr->AssertSpellInfo(SPELL_PALADIN_FLASH_OF_LIGHT_PROC)->GetMaxDuration() / 1000;
                            int32 pct = GetSpellInfo()->Effects[EFFECT_2].CalcValue();
                            int32 bp0 = CalculatePct(healInfo->GetHeal() / duration, pct);

                            // Item - Paladin T9 Holy 4P Bonus
                            if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_PALADIN_T9_HOLY_4P_BONUS, 0))
                                AddPct(bp0, aurEff->GetAmount());

                            target->CastCustomSpell(SPELL_PALADIN_FLASH_OF_LIGHT_PROC, SPELLVALUE_BASE_POINT0, bp0, procTarget, true, nullptr, aurEff);
                        }
                    }
                    // but should not proc on non-critical Holy Shocks
                    else if ((spellInfo->SpellFamilyFlags[0] & 0x200000 || spellInfo->SpellFamilyFlags[1] & 0x10000) && !(eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
                        PreventDefaultAction();
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_infusion_of_light_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_infusion_of_light_AuraScript();
        }
};

// 37705 - Healing Discount
class spell_pal_item_healing_discount : public SpellScriptLoader
{
    public:
        spell_pal_item_healing_discount() : SpellScriptLoader("spell_pal_item_healing_discount") { }

        class spell_pal_item_healing_discount_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_item_healing_discount_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_ITEM_HEALING_TRANCE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ITEM_HEALING_TRANCE, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_item_healing_discount_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_item_healing_discount_AuraScript();
        }
};

// 40470 - Paladin Tier 6 Trinket
class spell_pal_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_pal_item_t6_trinket() : SpellScriptLoader("spell_pal_item_t6_trinket") { }

        class spell_pal_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_ENDURING_LIGHT) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_ENDURING_JUDGEMENT))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
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
                    eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_item_t6_trinket_AuraScript();
        }
};

// 53407 - Judgement of Justice
// 20271 - Judgement of Light
// 53408 - Judgement of Wisdom
class spell_pal_judgement : public SpellScriptLoader
{
    public:
        spell_pal_judgement(char const* scriptName, uint32 spellId) : SpellScriptLoader(scriptName), _spellId(spellId) { }

        class spell_pal_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_SpellScript);

        public:
            spell_pal_judgement_SpellScript(uint32 spellId) : SpellScript(), _spellId(spellId) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_JUDGEMENT_DAMAGE)
                    || !sSpellMgr->GetSpellInfo(_spellId))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId2 = SPELL_PALADIN_JUDGEMENT_DAMAGE;

                // some seals have SPELL_AURA_DUMMY in EFFECT_2
                Unit::AuraEffectList const& auras = GetCaster()->GetAuraEffectsByType(SPELL_AURA_DUMMY);
                for (Unit::AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                {
                    if ((*i)->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_SEAL && (*i)->GetEffIndex() == EFFECT_2)
                    {
                        if (sSpellMgr->GetSpellInfo((*i)->GetAmount()))
                        {
                            spellId2 = (*i)->GetAmount();
                            break;
                        }
                    }
                }

                GetCaster()->CastSpell(GetHitUnit(), _spellId, true);
                GetCaster()->CastSpell(GetHitUnit(), spellId2, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgement_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        private:
            uint32 const _spellId;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_judgement_SpellScript(_spellId);
        }

    private:
        uint32 const _spellId;
};

// 20425 - Judgement of Command
class spell_pal_judgement_of_command : public SpellScriptLoader
{
    public:
        spell_pal_judgement_of_command() : SpellScriptLoader("spell_pal_judgement_of_command") { }

        class spell_pal_judgement_of_command_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_of_command_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* unitTarget = GetHitUnit())
                    if (SpellInfo const* spell_proto = sSpellMgr->GetSpellInfo(GetEffectValue()))
                        GetCaster()->CastSpell(unitTarget, spell_proto, true, NULL);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgement_of_command_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_judgement_of_command_SpellScript();
        }
};

// 20185 - Judgement of Light
class spell_pal_judgement_of_light_heal : public SpellScriptLoader
{
    public:
        spell_pal_judgement_of_light_heal() : SpellScriptLoader("spell_pal_judgement_of_light_heal") { }

        class spell_pal_judgement_of_light_heal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_judgement_of_light_heal_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_JUDGEMENT_OF_LIGHT_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetProcTarget();
                int32 amount = static_cast<int32>(caster->CountPctFromMaxHealth(aurEff->GetAmount()));

                caster->CastCustomSpell(SPELL_PALADIN_JUDGEMENT_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_judgement_of_light_heal_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_judgement_of_light_heal_AuraScript();
        }
};

// 20186 - Judgement of Wisdom
class spell_pal_judgement_of_wisdom_mana : public SpellScriptLoader
{
    public:
        spell_pal_judgement_of_wisdom_mana() : SpellScriptLoader("spell_pal_judgement_of_wisdom_mana") { }

        class spell_pal_judgement_of_wisdom_mana_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_judgement_of_wisdom_mana_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_JUDGEMENT_OF_WISDOM_MANA))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget()->getPowerType() == POWER_MANA;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetProcTarget();
                int32 amount = CalculatePct(static_cast<int32>(caster->GetCreateMana()), aurEff->GetAmount());

                caster->CastCustomSpell(SPELL_PALADIN_JUDGEMENT_OF_WISDOM_MANA, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_judgement_of_wisdom_mana_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_judgement_of_wisdom_mana_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_judgement_of_wisdom_mana_AuraScript();
        }
};

// -53695 - Judgements of the Just
class spell_pal_judgements_of_the_just : public SpellScriptLoader
{
    public:
        spell_pal_judgements_of_the_just() : SpellScriptLoader("spell_pal_judgements_of_the_just") { }

        class spell_pal_judgements_of_the_just_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_judgements_of_the_just_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_JUDGEMENTS_OF_THE_JUST_PROC))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetActionTarget(), SPELL_PALADIN_JUDGEMENTS_OF_THE_JUST_PROC, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_judgements_of_the_just_AuraScript::OnProc, EFFECT_0, SPELL_AURA_ADD_FLAT_MODIFIER);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_judgements_of_the_just_AuraScript();
        }
};

// -31876 - Judgements of the Wise
class spell_pal_judgements_of_the_wise : public SpellScriptLoader
{
    public:
        spell_pal_judgements_of_the_wise() : SpellScriptLoader("spell_pal_judgements_of_the_wise") { }

        class spell_pal_judgements_of_the_wise_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_judgements_of_the_wise_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_REPLENISHMENT) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE_MANA))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                caster->CastSpell((Unit*)nullptr, SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE_MANA, true);
                caster->CastSpell((Unit*)nullptr, SPELL_REPLENISHMENT, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_judgements_of_the_wise_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_judgements_of_the_wise_AuraScript();
        }
};

// -633 - Lay on Hands
class spell_pal_lay_on_hands : public SpellScriptLoader
{
    public:
        spell_pal_lay_on_hands() : SpellScriptLoader("spell_pal_lay_on_hands") { }

        class spell_pal_lay_on_hands_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_lay_on_hands_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_FORBEARANCE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_AVENGING_WRATH_MARKER))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_IMMUNE_SHIELD_MARKER))
                    return false;
                return true;
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                    if (caster == target)
                        if (target->HasAura(SPELL_PALADIN_FORBEARANCE) || target->HasAura(SPELL_PALADIN_AVENGING_WRATH_MARKER) || target->HasAura(SPELL_PALADIN_IMMUNE_SHIELD_MARKER))
                            return SPELL_FAILED_TARGET_AURASTATE;

                return SPELL_CAST_OK;
            }

            void HandleScript()
            {
                Unit* caster = GetCaster();
                if (caster == GetHitUnit())
                {
                    caster->CastSpell(caster, SPELL_PALADIN_FORBEARANCE, true);
                    caster->CastSpell(caster, SPELL_PALADIN_AVENGING_WRATH_MARKER, true);
                    caster->CastSpell(caster, SPELL_PALADIN_IMMUNE_SHIELD_MARKER, true);
                }
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_lay_on_hands_SpellScript::CheckCast);
                AfterHit += SpellHitFn(spell_pal_lay_on_hands_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_lay_on_hands_SpellScript();
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
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_1)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_2)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_3)
                    || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_LIGHT))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (GetTarget()->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT, eventInfo.GetActor()->GetGUID()))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                SpellInfo const* procSpell = eventInfo.GetSpellInfo();
                if (!procSpell)
                    return;

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                uint32 healSpellId = procSpell->IsRankOf(sSpellMgr->AssertSpellInfo(SPELL_PALADIN_HOLY_LIGHT)) ? SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_1 : SPELL_PALADIN_BEACON_OF_LIGHT_HEAL_3;
                uint32 heal = CalculatePct(healInfo->GetHeal(), aurEff->GetAmount());

                Unit* beaconTarget = GetCaster();
                if (!beaconTarget || !beaconTarget->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT, eventInfo.GetActor()->GetGUID()))
                    return;

                /// @todo: caster must be the healed unit to perform distance checks correctly
                ///        but that will break animation on clientside
                ///        caster in spell packets must be the healing unit
                eventInfo.GetActor()->CastCustomSpell(healSpellId, SPELLVALUE_BASE_POINT0, heal, beaconTarget, true);
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

// 31789 - Righteous Defense
class spell_pal_righteous_defense : public SpellScriptLoader
{
    public:
        spell_pal_righteous_defense() : SpellScriptLoader("spell_pal_righteous_defense") { }

        class spell_pal_righteous_defense_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_righteous_defense_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT))
                    return false;
                return true;
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (Unit* target = GetExplTargetUnit())
                {
                    if (!target->IsFriendlyTo(caster) || target->getAttackers().empty())
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleTriggerSpellLaunch(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
            }

            void HandleTriggerSpellHit(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT, true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_righteous_defense_SpellScript::CheckCast);
                //! WORKAROUND
                //! target select will be executed in hitphase of effect 0
                //! so we must handle trigger spell also in hit phase (default execution in launch phase)
                //! see issue #3718
                OnEffectLaunchTarget += SpellEffectFn(spell_pal_righteous_defense_SpellScript::HandleTriggerSpellLaunch, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
                OnEffectHitTarget += SpellEffectFn(spell_pal_righteous_defense_SpellScript::HandleTriggerSpellHit, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_righteous_defense_SpellScript();
        }
};

// -53380 - Righteous Vengeance
class spell_pal_righteous_vengeance : public SpellScriptLoader
{
    public:
        spell_pal_righteous_vengeance() : SpellScriptLoader("spell_pal_righteous_vengeance") { }

        class spell_pal_righteous_vengeance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_righteous_vengeance_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_RIGHTEOUS_VENGEANCE_DAMAGE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_PALADIN_RIGHTEOUS_VENGEANCE_DAMAGE);
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();
                // Add remaining ticks to damage done
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_PALADIN_RIGHTEOUS_VENGEANCE_DAMAGE, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_PALADIN_RIGHTEOUS_VENGEANCE_DAMAGE, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_righteous_vengeance_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_righteous_vengeance_AuraScript();
        }
};

// 58597 - Sacred Shield
class spell_pal_sacred_shield : public SpellScriptLoader
{
    public:
        spell_pal_sacred_shield() : SpellScriptLoader("spell_pal_sacred_shield") { }

        class spell_pal_sacred_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_sacred_shield_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // +75.00% from sp bonus
                    float bonus = CalculatePct(caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()), 75.0f);

                    // Divine Guardian is only applied at the spell healing bonus because it was already applied to the base value in CalculateSpellDamage
                    bonus = caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), bonus);
                    bonus *= caster->CalculateLevelPenalty(GetSpellInfo());

                    amount += int32(bonus);

                    // Arena - Dampening
                    if (AuraEffect const* auraEffArenaDampening = caster->GetAuraEffect(SPELL_GENERIC_ARENA_DAMPENING, EFFECT_0))
                        AddPct(amount, auraEffArenaDampening->GetAmount());
                    // Battleground - Dampening
                    else if (AuraEffect const* auraEffBattlegroudDampening = caster->GetAuraEffect(SPELL_GENERIC_BATTLEGROUND_DAMPENING, EFFECT_0))
                        AddPct(amount, auraEffBattlegroudDampening->GetAmount());
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_sacred_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_sacred_shield_AuraScript();
        }
};

// 53601 - Sacred Shield (dummy)
class spell_pal_sacred_shield_dummy : public SpellScriptLoader
{
    public:
        spell_pal_sacred_shield_dummy() : SpellScriptLoader("spell_pal_sacred_shield_dummy") { }

        class spell_pal_sacred_shield_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_sacred_shield_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SACRED_SHIELD_TRIGGER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_T8_HOLY_4P_BONUS))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
                if (_cooldownEnd > now)
                    return;

                Seconds cooldown(aurEff->GetAmount());
                if (AuraEffect const* bonus = caster->GetAuraEffect(SPELL_PALADIN_T8_HOLY_4P_BONUS, EFFECT_0, caster->GetGUID()))
                    cooldown = Seconds(bonus->GetAmount());

                _cooldownEnd = now + cooldown;
                caster->CastSpell(eventInfo.GetActionTarget(), SPELL_PALADIN_SACRED_SHIELD_TRIGGER, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_sacred_shield_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

            // Cooldown tracking can't be done in DB because of T8 bonus
            std::chrono::steady_clock::time_point _cooldownEnd = std::chrono::steady_clock::time_point::min();
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_sacred_shield_dummy_AuraScript();
        }
};

// 20154, 21084 - Seal of Righteousness - melee proc dummy (addition ${$MWS*(0.022*$AP+0.044*$SPH)} damage)
class spell_pal_seal_of_righteousness : public SpellScriptLoader
{
    public:
        spell_pal_seal_of_righteousness() : SpellScriptLoader("spell_pal_seal_of_righteousness") { }

        class spell_pal_seal_of_righteousness_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_seal_of_righteousness_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS))
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

                float ap = GetTarget()->GetTotalAttackPowerValue(BASE_ATTACK);
                int32 holy = GetTarget()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
                holy += eventInfo.GetProcTarget()->SpellBaseDamageBonusTaken(SPELL_SCHOOL_MASK_HOLY);
                int32 bp = int32((ap * 0.022f + 0.044f * holy) * GetTarget()->GetAttackTime(BASE_ATTACK) / 1000);
                GetTarget()->CastCustomSpell(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS, SPELLVALUE_BASE_POINT0, bp, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_seal_of_righteousness_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_righteousness_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_seal_of_righteousness_AuraScript();
        }
};

// 31801 - Seal of Vengeance
// 53736 - Seal of Corruption
template <uint32 DoTSpellId, uint32 DamageSpellId>
class spell_pal_seal_of_vengeance : public SpellScriptLoader
{
    public:
        spell_pal_seal_of_vengeance(char const* ScriptName) : SpellScriptLoader(ScriptName) { }

        template <uint32 DoTSpell, uint32 DamageSpell>
        class spell_pal_seal_of_vengeance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_seal_of_vengeance_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(DoTSpell) ||
                    !sSpellMgr->GetSpellInfo(DamageSpell))
                    return false;
                return true;
            }

            /*
            When an auto-attack lands (does not dodge/parry/miss) that can proc a seal the of the following things happen independently of each other (see 2 roll system).

            1) A "hidden strike" which uses melee combat mechanics occurs. If it lands it refreshes/stacks SoV DoT. Only white swings can trigger a refresh or stack. (This hidden strike mechanic can also proc things like berserking..)
            2) A weapon damage based proc will occur if you used a special (CS/DS/judge) or if you have a 5 stack (from auto attacks). This attack can not be avoided.

            Remember #2 happens regardless of #1 landing, it just requires the initial attack (autos, cs, etc) to land.

            Stack Number    % of Weapon Damage  % with SotP
            0               0%                  0%
            1               6.6%                7.6%
            2               13.2%               15.2%
            3               19.8%               22.8%
            4               26.4%               30.4%
            5               33%                 38%
            */

            void HandleApplyDoT(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!(eventInfo.GetTypeMask() & PROC_FLAG_DONE_MELEE_AUTO_ATTACK))
                    return;

                // don't cast triggered, spell already has SPELL_ATTR4_CAN_CAST_WHILE_CASTING attr
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), DoTSpell, false);
            }

            void HandleSeal(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PALADIN, 0x00000000, 0x00000800, 0x00000000, caster->GetGUID());
                if (!aurEff)
                    return;

                uint8 stacks = aurEff->GetBase()->GetStackAmount();
                uint8 maxStacks = aurEff->GetSpellInfo()->StackAmount;

                if (stacks < maxStacks && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_SPELL_MELEE_DMG_CLASS))
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(DamageSpell);
                int32 amount = spellInfo->Effects[EFFECT_0].CalcValue();
                amount *= stacks;
                amount /= maxStacks;

                caster->CastCustomSpell(DamageSpell, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_vengeance_AuraScript::HandleApplyDoT, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_vengeance_AuraScript::HandleSeal, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_seal_of_vengeance_AuraScript<DoTSpellId, DamageSpellId>();
        }
};

// -31785 - Spiritual Attunement
class spell_pal_spiritual_attunement : public SpellScriptLoader
{
    public:
        spell_pal_spiritual_attunement() : SpellScriptLoader("spell_pal_spiritual_attunement") { }

        class spell_pal_spiritual_attunement_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_spiritual_attunement_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SPIRITUAL_ATTUNEMENT_MANA))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // "when healed by other friendly targets' spells"
                if (eventInfo.GetProcTarget() == eventInfo.GetActionTarget())
                    return false;

                return eventInfo.GetHealInfo() && eventInfo.GetHealInfo()->GetEffectiveHeal();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                HealInfo* healInfo = eventInfo.GetHealInfo();
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetEffectiveHeal()), aurEff->GetAmount());

                eventInfo.GetActionTarget()->CastCustomSpell(SPELL_PALADIN_SPIRITUAL_ATTUNEMENT_MANA, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_spiritual_attunement_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_spiritual_attunement_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_spiritual_attunement_AuraScript();
        }
};

// -53501 - Sheath of Light
class spell_pal_sheath_of_light : public SpellScriptLoader
{
    public:
        spell_pal_sheath_of_light() : SpellScriptLoader("spell_pal_sheath_of_light") { }

        class spell_pal_sheath_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_sheath_of_light_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SHEATH_OF_LIGHT_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_PALADIN_SHEATH_OF_LIGHT_HEAL);
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();
                // Add remaining ticks to damage done
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_PALADIN_SHEATH_OF_LIGHT_HEAL, SPELL_AURA_PERIODIC_HEAL);

                caster->CastCustomSpell(SPELL_PALADIN_SHEATH_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_sheath_of_light_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_sheath_of_light_AuraScript();
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
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_POWER_ARMOR) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_POWER_ATTACK_POWER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_POWER_SPELL_POWER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_POWER_MP5))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
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

                caster->CastSpell(target, spellId, true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_MENDING))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_PALADIN_HOLY_MENDING);
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();
                // Add remaining ticks to damage done
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_PALADIN_HOLY_MENDING, SPELL_AURA_PERIODIC_HEAL);

                caster->CastCustomSpell(SPELL_PALADIN_HOLY_MENDING, SPELLVALUE_BASE_POINT0, amount, target, true);
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
    new spell_pal_ardent_defender();
    new spell_pal_aura_mastery();
    new spell_pal_aura_mastery_immune();
    new spell_pal_avenging_wrath();
    new spell_pal_blessing_of_faith();
    new spell_pal_blessing_of_sanctuary();
    new spell_pal_divine_purpose();
    new spell_pal_divine_sacrifice();
    new spell_pal_divine_storm();
    new spell_pal_divine_storm_dummy();
    new spell_pal_exorcism_and_holy_wrath_damage();
    new spell_pal_eye_for_an_eye();
    new spell_pal_glyph_of_divinity();
    new spell_pal_glyph_of_holy_light();
    new spell_pal_glyph_of_holy_light_dummy();
    new spell_pal_guarded_by_the_light();
    new spell_pal_hand_of_sacrifice();
    new spell_pal_hand_of_salvation();
    new spell_pal_heart_of_the_crusader();
    new spell_pal_holy_shock();
    new spell_pal_illumination();
    new spell_pal_improved_aura("spell_pal_improved_concentraction_aura", SPELL_PALADIN_IMPROVED_CONCENTRACTION_AURA);
    new spell_pal_improved_aura("spell_pal_improved_devotion_aura", SPELL_PALADIN_IMPROVED_DEVOTION_AURA);
    new spell_pal_improved_aura("spell_pal_sanctified_retribution", SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA);
    new spell_pal_improved_aura("spell_pal_swift_retribution", SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA);
    new spell_pal_improved_aura_effect("spell_pal_improved_concentraction_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_improved_devotion_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_sanctified_retribution_effect");
    new spell_pal_improved_lay_of_hands();
    new spell_pal_infusion_of_light();
    new spell_pal_item_healing_discount();
    new spell_pal_item_t6_trinket();
    new spell_pal_judgement("spell_pal_judgement_of_justice", SPELL_PALADIN_JUDGEMENT_OF_JUSTICE);
    new spell_pal_judgement("spell_pal_judgement_of_light", SPELL_PALADIN_JUDGEMENT_OF_LIGHT);
    new spell_pal_judgement("spell_pal_judgement_of_wisdom", SPELL_PALADIN_JUDGEMENT_OF_WISDOM);
    new spell_pal_judgement_of_command();
    new spell_pal_judgement_of_light_heal();
    new spell_pal_judgement_of_wisdom_mana();
    new spell_pal_judgements_of_the_just();
    new spell_pal_judgements_of_the_wise();
    new spell_pal_lay_on_hands();
    new spell_pal_light_s_beacon();
    new spell_pal_righteous_defense();
    new spell_pal_righteous_vengeance();
    new spell_pal_sacred_shield();
    new spell_pal_sacred_shield_dummy();
    new spell_pal_seal_of_righteousness();
    new spell_pal_seal_of_vengeance<SPELL_PALADIN_HOLY_VENGEANCE, SPELL_PALADIN_SEAL_OF_VENGEANCE_DAMAGE>("spell_pal_seal_of_vengeance");
    new spell_pal_seal_of_vengeance<SPELL_PALADIN_BLOOD_CORRUPTION, SPELL_PALADIN_SEAL_OF_CORRUPTION_DAMAGE>("spell_pal_seal_of_corruption");
    new spell_pal_spiritual_attunement();
    new spell_pal_sheath_of_light();
    new spell_pal_t3_6p_bonus();
    new spell_pal_t8_2p_bonus();
}
