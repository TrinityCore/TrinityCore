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
 * Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pal_".
 */

#include "ScriptMgr.h"
#include "Group.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "Spell.h"

enum PaladinSpells
{
    SPELL_PALADIN_ANCIENT_HEALER                        = 86674,
    SPELL_PALADIN_ANCIENT_CRUSADER                      = 86701,
    SPELL_PALADIN_ANCIENT_CRUSADER_GUARDIAN             = 86703,
    SPELL_PALADIN_ANCIENT_FURY                          = 86704,
    SPELL_PALADIN_ANCIENT_POWER                         = 86700,
    SPELL_PALADIN_ARDENT_DEFENDER_HEAL                  = 66235,
    SPELL_PALADIN_AVENGERS_SHIELD                       = 31935,
    SPELL_PALADIN_AURA_MASTERY_IMMUNE                   = 64364,
    SPELL_PALADIN_BEACON_OF_LIGHT                       = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL                  = 53652,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID          = 37878,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN        = 37879,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST         = 37880,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN         = 37881,
    SPELL_PALADIN_CENSURE                               = 31803,
    SPELL_PALADIN_CONCENTRACTION_AURA                   = 19746,
    SPELL_PALADIN_CONSECRATION_TRIGGERED                = 81297,
    SPELL_PALADIN_CRUSADER_STRIKE                       = 35395,
    SPELL_PALADIN_DIVINE_PURPOSE_PROC                   = 90174,
    SPELL_PALADIN_DIVINE_SACRIFICE                      = 64205,
    SPELL_PALADIN_DIVINE_STORM                          = 53385,
    SPELL_PALADIN_DIVINE_STORM_DUMMY                    = 54171,
    SPELL_PALADIN_DIVINE_STORM_HEAL                     = 54172,
    SPELL_PALADIN_ETERNAL_GLORY_PROC                    = 88676,
    SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1                 = 9799,
    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE                 = 25997,
    SPELL_PALADIN_FORBEARANCE                           = 25771,
    SPELL_PALADIN_GLYPH_OF_SALVATION                    = 63225,
    SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_HOLY        = 86669,
    SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_PROTECTION  = 86659,
    SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_RETRIBUTION = 86698,
    SPELL_PALADIN_HAND_OF_LIGHT                         = 96172,
    SPELL_PALADIN_HAND_OF_SACRIFICE                     = 6940,
    SPELL_PALADIN_HOLY_LIGHT                            = 635,
    SPELL_PALADIN_HOLY_RADIANCE_TRIGGERED               = 86452,
    SPELL_PALADIN_HOLY_SHOCK_R1                         = 20473,
    SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE                  = 25912,
    SPELL_PALADIN_HOLY_SHOCK_R1_HEALING                 = 25914,
    SPELL_PALADIN_ILLUMINATED_HEALING                   = 86273,
    SPELL_PALADIN_IMMUNE_SHIELD_MARKER                  = 61988,
    SPELL_PALADIN_IMPROVED_CONCENTRACTION_AURA          = 63510,
    SPELL_PALADIN_IMPROVED_DEVOTION_AURA                = 63514,
    SPELL_PALADIN_ITEM_HEALING_TRANCE                   = 37706,
    SPELL_PALADIN_JUDGEMENT_DAMAGE                      = 54158,
    SPELL_PALADIN_JUDGEMENTS_OF_THE_BOLD                = 89906,
    SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE_PASSIVE        = 31878,
    SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE                = 31930,
    SPELL_PALADIN_JUDGEEMENT_OF_TRUTH                   = 31804,
    SPELL_PALADIN_LIGHT_OF_THE_ANCIENT_KINGS            = 86678,
    SPELL_PALADIN_LONG_ARM_OF_THE_LAW                   = 87173,
    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT               = 31790,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA           = 63531,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1             = 31869,
    SPELL_PALADIN_SANCTIFIED_WRATH                      = 57318,
    SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1            = 53375,
    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS                 = 20154,
    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS_DAMAGE          = 25742,
    SPELL_PALADIN_SEAL_OF_TRUTH                         = 31801,
    SPELL_PALADIN_SEAL_OF_TRUTH_DAMAGE                  = 42463,
    SPELL_PALADIN_SEAL_OF_JUSTICE                       = 20164,
    SPELL_PALADIN_SWIFT_RETRIBUTION_R1                  = 53379,
    SPELL_PALADIN_TEMPLARS_VERDICT                      = 85256
};

enum MiscSpells
{
    SPELL_GENERIC_ARENA_DAMPENING                = 74410,
    SPELL_GENERIC_BATTLEGROUND_DAMPENING         = 74411,
    SPELL_GENERIC_REPLENISHMENT                  = 57669
};

enum PaladinSpellIcons
{
    PALADIN_ICON_ID_RETRIBUTION_AURA             = 555,
    PALADIN_ICOM_ID_SELFLESS_HEALER              = 3924,
    PALADIN_ICON_ID_ETERNAL_GLORY                = 2944,
    PALADIN_ICON_ID_GLYPH_OF_THE_LONG_WORD       = 4127,
    PALADIN_ICON_ID_GLYPH_OF_LIGHT_OF_DAWN       = 5154,
    PALADIN_ICON_ID_GLYPH_OF_EXORCISM            = 292
};

enum PaladinCreatures
{
    NPC_PALADIN_CONSECRATION                     = 43499
};

class spell_pal_ardent_defender : public AuraScript
{
    PrepareAuraScript(spell_pal_ardent_defender);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_ARDENT_DEFENDER_HEAL });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetDamage() >= target->GetHealth())
        {
            int32 health = target->CountPctFromMaxHealth(15);
            target->CastCustomSpell(SPELL_PALADIN_ARDENT_DEFENDER_HEAL, SPELLVALUE_BASE_POINT0, health, target, true, nullptr, aurEff);
            Remove();
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_ardent_defender::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_ardent_defender::Absorb, EFFECT_0);
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
                return ValidateSpellInfo({ SPELL_PALADIN_AURA_MASTERY_IMMUNE });
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
                return ValidateSpellInfo({ SPELL_PALADIN_CONCENTRACTION_AURA });
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
class spell_pal_avenging_wrath : public AuraScript
{
    PrepareAuraScript(spell_pal_avenging_wrath);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_SANCTIFIED_WRATH,
                SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1
            });
    }

    void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetAuraOfRankedSpell(SPELL_PALADIN_SANCTIFIED_WRATH_TALENT_R1))
            target->CastSpell(target, SPELL_PALADIN_SANCTIFIED_WRATH, true, nullptr, aurEff);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_PALADIN_SANCTIFIED_WRATH);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_pal_avenging_wrath::HandleApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_pal_avenging_wrath::HandleRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
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
                OnEffectHitTarget += SpellEffectFn(spell_pal_blessing_of_faith_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_blessing_of_faith_SpellScript();
        }
};

// 26573 - Consecration
class spell_pal_consecration : public SpellScriptLoader
{
    public:
        spell_pal_consecration() : SpellScriptLoader("spell_pal_consecration") { }

        class spell_pal_consecration_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_consecration_AuraScript);

            bool Load() override
            {
                // Store the position of the initial Consecration cast for triggering the damage
                castPos = GetCaster()->GetPosition();
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_CONSECRATION_TRIGGERED });
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                // For some reason Consecration also applies on nearby enemies
                // In this case the following code should not happen
                if (GetTarget() != GetCaster())
                    return;

                if (Unit* caster = GetCaster())
                    caster->CastSpell(castPos.GetPositionX(), castPos.GetPositionY(), castPos.GetPositionZ(), SPELL_PALADIN_CONSECRATION_TRIGGERED, true, nullptr, aurEff);
            }

        private:
            Position castPos;

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_consecration_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_consecration_AuraScript();
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

            uint32 healPct = 0;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_STORM_DUMMY });
            }

            bool Load() override
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }

            void TriggerHeal()
            {
                Unit* caster = GetCaster();
                caster->CastCustomSpell(SPELL_PALADIN_DIVINE_STORM_DUMMY, SPELLVALUE_BASE_POINT0, CalculatePct(GetHitDamage(), healPct), caster, true);
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

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_STORM_HEAL });
            }

            void CountTargets(std::list<WorldObject*>& targetList)
            {
                _targetCount = targetList.size();
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!_targetCount || !GetHitUnit() || !GetEffectValue())
                    return;

                int32 heal = GetEffectValue() / _targetCount;
                GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_PALADIN_DIVINE_STORM_HEAL, &heal, nullptr, nullptr, true);
            }

            uint32 _targetCount = 0;

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
                return ValidateSpellInfo({ SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE });
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 damage = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetProcTarget(), true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye_AuraScript::HandleEffectProc, EFFECT_0, m_scriptSpellId == SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1 ? SPELL_AURA_DUMMY : SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_eye_for_an_eye_AuraScript();
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

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->ToPlayer()->GetSpellHistory()->ResetCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
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

// 63510 - Improved Concentraction Aura (Area Aura)
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
                return ValidateSpellInfo({ SPELL_PALADIN_ITEM_HEALING_TRANCE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ITEM_HEALING_TRANCE, true, nullptr, aurEff);
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

// 20271 - Judgement
/// Updated 4.3.4
class spell_pal_judgement : public SpellScriptLoader
{
    public:
        spell_pal_judgement() : SpellScriptLoader("spell_pal_judgement") { }

        class spell_pal_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_PALADIN_JUDGEMENT_DAMAGE,
                    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS,
                    SPELL_PALADIN_SEAL_OF_TRUTH,
                });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                uint32 spellId = SPELL_PALADIN_JUDGEMENT_DAMAGE;
                int32 bp = 0;
                float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
                int32 holy = caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
                holy += GetHitUnit()->SpellBaseDamageBonusTaken(SPELL_SCHOOL_MASK_HOLY);

                // some seals have SPELL_AURA_DUMMY in EFFECT_2
                Unit::AuraEffectList const& auras = caster->GetAuraEffectsByType(SPELL_AURA_DUMMY);
                for (Unit::AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                {
                    if ((*i)->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_SEAL && (*i)->GetEffIndex() == EFFECT_2)
                    {
                        if (sSpellMgr->GetSpellInfo((*i)->GetAmount()))
                        {
                            spellId = (*i)->GetAmount();
                            break;
                        }
                    }
                }

                if (caster->HasAura(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS))
                    bp = 1 + int32(ap * 0.2f + 0.32f * holy);
                else if (caster->HasAura(SPELL_PALADIN_SEAL_OF_TRUTH))
                    bp = 1 + int32(ap * 0.142f + 0.223f * holy);
                else
                    bp = 1 + int32(ap * 0.16f + 0.25f * holy);

                caster->CastCustomSpell(spellId, SPELLVALUE_BASE_POINT0, bp, GetHitUnit(), true, nullptr);
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
class spell_pal_lay_on_hands : public SpellScriptLoader
{
    public:
        spell_pal_lay_on_hands() : SpellScriptLoader("spell_pal_lay_on_hands") { }

        class spell_pal_lay_on_hands_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_lay_on_hands_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_FORBEARANCE, SPELL_PALADIN_IMMUNE_SHIELD_MARKER });
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                    if (caster == target)
                        if (target->HasAura(SPELL_PALADIN_FORBEARANCE) ||
                            target->HasAura(SPELL_PALADIN_IMMUNE_SHIELD_MARKER))
                        {
                            return SPELL_FAILED_TARGET_AURASTATE;
                        }

                return SPELL_CAST_OK;
            }

            void HandleScript()
            {
                Unit* caster = GetCaster();
                if (caster == GetHitUnit())
                {
                    caster->CastSpell(caster, SPELL_PALADIN_FORBEARANCE, true);
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
                return ValidateSpellInfo({ SPELL_PALADIN_BEACON_OF_LIGHT, SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELL_PALADIN_HOLY_LIGHT });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActionTarget()->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT, eventInfo.GetActor()->GetGUID()))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 heal = eventInfo.GetHealInfo()->GetHeal();

                if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PALADIN_HOLY_LIGHT)
                    heal = int32(CalculatePct(heal, aurEff->GetAmount()));

                Unit::AuraList const& auras = GetCaster()->GetSingleCastAuras();
                for (Aura* const& aura : auras)
                {
                    if (aura->GetId() == SPELL_PALADIN_BEACON_OF_LIGHT)
                    {
                        std::list<AuraApplication*> applications;
                        aura->GetApplicationList(applications);
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
                return ValidateSpellInfo({ SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT });
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

// 53600 - Shield of the Righteous
/// Updated 4.3.4
class spell_pal_shield_of_the_righteous : public SpellScriptLoader
{
    public:
        spell_pal_shield_of_the_righteous() : SpellScriptLoader("spell_pal_shield_of_the_righteous") { }

        class spell_pal_shield_of_the_righteous_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_shield_of_the_righteous_SpellScript);

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
                int32 damage = GetHitDamage();

                // Because 1 Holy Power (HP) is consumed when casting spell,
                // GetPower(POWER_HOLY_POWER) will return 0 when player has 1 HP,
                // return 1 at 2 HP, and 2 at 3 HP
                int32 hp = GetCaster()->GetPower(POWER_HOLY_POWER);

                // Holy Power Scaling: 3 times damage at 2 HP, 6 times at 3 HP
                damage *= 0.5 * hp * hp + 1.5 * hp + 1;

                SetHitDamage(damage);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_shield_of_the_righteous_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_shield_of_the_righteous_SpellScript();
        }
};

// 85256 - Templar's Verdict
/// Updated 4.3.4
class spell_pal_templar_s_verdict : public SpellScriptLoader
{
    public:
        spell_pal_templar_s_verdict() : SpellScriptLoader("spell_pal_templar_s_verdict") { }

        class spell_pal_templar_s_verdict_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_templar_s_verdict_SpellScript);

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
                OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_pal_templar_s_verdict_SpellScript();
        }
};

// 20154 - Seal of Righteousness - melee proc dummy (addition ${$MWS*(0.011*$AP+0.022*$SPH)} damage)
/// Updated 4.3.4
class spell_pal_seal_of_righteousness : public SpellScriptLoader
{
    public:
        spell_pal_seal_of_righteousness() : SpellScriptLoader("spell_pal_seal_of_righteousness") { }

        class spell_pal_seal_of_righteousness_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_seal_of_righteousness_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS_DAMAGE });
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
                int32 bp = int32((ap * 0.011f + 0.022f * holy) * GetTarget()->GetAttackTime(BASE_ATTACK) / 1000);
                GetTarget()->CastCustomSpell(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS_DAMAGE, SPELLVALUE_BASE_POINT0, bp, eventInfo.GetProcTarget(), true, nullptr, aurEff);
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

// 76669 - Illuminated Healing
class spell_pal_illuminated_healing : public SpellScriptLoader
{
    public:
        spell_pal_illuminated_healing() : SpellScriptLoader("spell_pal_illuminated_healing") { }

        class spell_pal_illuminated_healing_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_illuminated_healing_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_PALADIN_ILLUMINATED_HEALING });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = eventInfo.GetProcTarget())
                    {
                        uint32 shieldAmount = CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount());
                        caster->CastCustomSpell(SPELL_PALADIN_ILLUMINATED_HEALING, SPELLVALUE_BASE_POINT0, shieldAmount, target, true, nullptr, aurEff);
                    }
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_illuminated_healing_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_illuminated_healing_AuraScript();
        }
};

// 76672 - Hand of Light
class spell_pal_hand_of_light : public SpellScriptLoader
{
    public:
        spell_pal_hand_of_light() : SpellScriptLoader("spell_pal_hand_of_light") { }

        class spell_pal_hand_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_hand_of_light_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_PALADIN_TEMPLARS_VERDICT,
                    SPELL_PALADIN_CRUSADER_STRIKE,
                    SPELL_PALADIN_DIVINE_STORM
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                return spellInfo &&
                    (spellInfo->Id == SPELL_PALADIN_TEMPLARS_VERDICT ||
                        spellInfo->Id == SPELL_PALADIN_CRUSADER_STRIKE ||
                        spellInfo->Id == SPELL_PALADIN_DIVINE_STORM);
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = eventInfo.GetProcTarget())
                    {
                        uint32 damageAmount = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
                        caster->CastCustomSpell(SPELL_PALADIN_HAND_OF_LIGHT, SPELLVALUE_BASE_POINT0, damageAmount, target, true, nullptr, aurEff);
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_hand_of_light_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_hand_of_light_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pal_hand_of_light_AuraScript();
        }
};

// 31878 - Judgements of the Wise (Passive)
// 89901 - Judgements of the Bold (Passive)
class spell_pal_judgements : public AuraScript
{
    PrepareAuraScript(spell_pal_judgements);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE,
                SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE_PASSIVE,
                SPELL_PALADIN_JUDGEMENTS_OF_THE_BOLD
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        uint32 spellId = GetSpellInfo()->Id == SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE_PASSIVE ?
            SPELL_PALADIN_JUDGEMENTS_OF_THE_WISE : SPELL_PALADIN_JUDGEMENTS_OF_THE_BOLD;

        Unit* actor = eventInfo.GetActor();

        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(spellId))
        {
            int32 bp = 0;
            if (uint32 mana = actor->GetCreateMana())
                bp = CalculatePct(CalculatePct(mana, spell->Effects[EFFECT_0].BasePoints), spell->GetMaxTicks());

            actor->CastCustomSpell(actor, spellId, &bp, nullptr, nullptr, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_judgements::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 879 - Exorcism
class spell_pal_exorcism : public SpellScript
{
    PrepareSpellScript(spell_pal_exorcism);

    void HandleDamage()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 damage = GetHitDamage();
        int32 ap = int32(caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.344f);
        int32 holy = caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
        holy += GetHitUnit()->SpellBaseDamageBonusTaken(SPELL_SCHOOL_MASK_HOLY);
        holy *= 0.344f;
        SetHitDamage(damage + std::max(ap, holy));
    }

    void ApplyDotBonus()
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        if (!target || !caster)
            return;

        int32 damage = GetHitDamage();

        if (AuraEffect* exorcismAuraEff = target->GetAuraEffect(GetSpellInfo()->Id, EFFECT_1, caster->GetGUID()))
        {
            if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICON_ID_GLYPH_OF_EXORCISM, EFFECT_0))
            {
                uint8 ticks = exorcismAuraEff->GetTotalTicks();
                if (!ticks)
                    return;

                int32 amount = CalculatePct(damage, aurEff->GetAmount()) / ticks;
                exorcismAuraEff->SetAmount(amount);
            }
        }
    }

    void Register() override
    {
        BeforeHit += SpellHitFn(spell_pal_exorcism::HandleDamage);
        AfterHit += SpellHitFn(spell_pal_exorcism::ApplyDotBonus);
    }
};

class spell_pal_exorcism_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_pal_exorcism_AuraScript);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (!caster->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICON_ID_GLYPH_OF_EXORCISM, EFFECT_0))
            Remove();
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_pal_exorcism_AuraScript::HandleApply, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 31801 - Seal of Truth
class spell_pal_seal_of_truth : public AuraScript
{
    PrepareAuraScript(spell_pal_seal_of_truth);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_CENSURE,
                SPELL_PALADIN_SEAL_OF_TRUTH_DAMAGE,
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* actor = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        if (Aura* aura = target->GetAura(SPELL_PALADIN_CENSURE, actor->GetGUID()))
            if (aura->GetStackAmount() == 5)
                actor->CastSpell(target, SPELL_PALADIN_SEAL_OF_TRUTH_DAMAGE, true, nullptr, aurEff);

        float ap = eventInfo.GetActor()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.0270f;
        int32 holy = eventInfo.GetActor()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
        holy += eventInfo.GetProcTarget()->SpellBaseDamageBonusTaken(SPELL_SCHOOL_MASK_HOLY);
        holy *= 0.01f;

        if (ap || holy)
        {
            int32 damage = int32(holy + ap);
            actor->CastCustomSpell(target, SPELL_PALADIN_CENSURE, &damage, nullptr, nullptr, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_truth::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -87168 - Long Arm of the Law
class spell_pal_long_arm_of_the_law : public AuraScript
{
    PrepareAuraScript(spell_pal_long_arm_of_the_law);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_LONG_ARM_OF_THE_LAW });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (roll_chance_i(GetEffect(EFFECT_0)->GetAmount()))
            if (Spell const* spell = eventInfo.GetProcSpell())
                if (Unit* target = spell->m_targets.GetUnitTarget())
                    return (eventInfo.GetActor()->GetDistance2d(target) > 15.0f);

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_LONG_ARM_OF_THE_LAW, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_long_arm_of_the_law::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_long_arm_of_the_law::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 31876 - Communion
class spell_pal_communion : public AuraScript
{
    PrepareAuraScript(spell_pal_communion);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GENERIC_REPLENISHMENT });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_GENERIC_REPLENISHMENT, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_communion::HandleProc, EFFECT_1, SPELL_AURA_ADD_FLAT_MODIFIER);
    }
};

// 85285  - Sacred Shield
class spell_pal_sacred_shield : public AuraScript
{
    PrepareAuraScript(spell_pal_sacred_shield);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (DamageInfo* damage = eventInfo.GetDamageInfo())
            return (GetTarget()->HealthBelowPctDamaged(30, damage->GetDamage()));

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell);
        int32 absorb = (spell->Effects[EFFECT_0].CalcValue() * 2) + target->GetTotalAttackPowerValue(BASE_ATTACK) * 2.8f;
        target->CastCustomSpell(spell->Id, SPELLVALUE_BASE_POINT0, absorb, target, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_sacred_shield::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_sacred_shield::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 85673 - Word of Glory
class spell_pal_word_of_glory: public SpellScript
{
    PrepareSpellScript(spell_pal_word_of_glory);

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
            return false;

        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_DIVINE_PURPOSE_PROC,
                SPELL_PALADIN_ETERNAL_GLORY_PROC
            });
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 heal = GetHitHeal();

        if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
            heal += heal * 2;
        else
            heal += heal * caster->GetPower(POWER_HOLY_POWER);

        if (caster != GetHitUnit())
            if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICOM_ID_SELFLESS_HEALER, EFFECT_0))
                heal += CalculatePct(heal, aurEff->GetAmount());

        SetHitHeal(heal);
    }

    void HandleEternalGlory()
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICON_ID_ETERNAL_GLORY, EFFECT_0))
            {
                if (roll_chance_i(aurEff->GetAmount()))
                {
                    uint8 powerCost = 1 + GetSpell()->GetPowerCost();
                    caster->CastCustomSpell(SPELL_PALADIN_ETERNAL_GLORY_PROC, SPELLVALUE_BASE_POINT0, powerCost, caster, true, nullptr, aurEff);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_word_of_glory::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
        AfterCast += SpellCastFn(spell_pal_word_of_glory::HandleEternalGlory);
    }
};

class spell_pal_word_of_glory_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_pal_word_of_glory_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_PURPOSE_PROC });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetTarget()->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICON_ID_GLYPH_OF_THE_LONG_WORD, EFFECT_1))
            Remove();
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
            amount += amount * 2;
        else
            amount += amount * caster->GetPower(POWER_HOLY_POWER);

        if (caster != GetUnitOwner())
            if (AuraEffect* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICOM_ID_SELFLESS_HEALER, EFFECT_0))
                amount += CalculatePct(amount, aurEff->GetAmount());
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_pal_word_of_glory_AuraScript::HandleApply, EFFECT_1, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_word_of_glory_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_PERIODIC_HEAL);
    }
};

// -85803 - Selfless Healer
class spell_pal_selfless_healer : public AuraScript
{
    PrepareAuraScript(spell_pal_selfless_healer);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (HealInfo* heal = eventInfo.GetHealInfo())
            return (heal->GetTarget() != GetTarget());

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell);
        target->CastCustomSpell(spell->Id, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_selfless_healer::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_selfless_healer::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// -85117 - Divine Purpose
class spell_pal_divine_purpose : public AuraScript
{
    PrepareAuraScript(spell_pal_divine_purpose);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_PURPOSE_PROC });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (AuraEffect* divineEff = GetTarget()->GetAuraEffect(SPELL_PALADIN_DIVINE_PURPOSE_PROC, EFFECT_0))
            if (divineEff->IsAffectingSpell(eventInfo.GetSpellInfo()))
                return false;

        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
            return roll_chance_i(aurEff->GetAmount());

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_DIVINE_PURPOSE_PROC, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_divine_purpose::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_divine_purpose::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_pal_inquisition : public SpellScript
{
    PrepareSpellScript(spell_pal_inquisition);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_DIVINE_PURPOSE_PROC });
    }

    void ChangeDuration()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* aura = caster->GetAura(GetSpellInfo()->Id))
        {
            uint8 power = caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC) ? 2 : caster->GetPower(POWER_HOLY_POWER);
            int32 duration = aura->GetDuration();
            duration += duration * power;
            aura->SetDuration(duration);
        }

    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_pal_inquisition::ChangeDuration);
    }
};

class spell_pal_guardian_of_ancient_kings : public SpellScript
{
    PrepareSpellScript(spell_pal_guardian_of_ancient_kings);

    bool Validate(SpellInfo const* spell) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_HOLY,
                SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_PROTECTION,
                SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_RETRIBUTION,
                SPELL_PALADIN_ANCIENT_HEALER,
                SPELL_PALADIN_ANCIENT_CRUSADER
            });
    }

    void HandleDummyEffect()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        switch (caster->GetPrimaryTalentTree(caster->GetActiveSpec()))
        {
            case TALENT_TREE_PALADIN_HOLY:
                caster->CastSpell(caster, SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_HOLY, true);
                caster->CastSpell(caster, SPELL_PALADIN_ANCIENT_HEALER, true);
                break;
            case TALENT_TREE_PALADIN_PROTECTION:
                caster->CastSpell(caster, SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_PROTECTION, true);
                break;
            case TALENT_TREE_PALADIN_RETRIBUTION:
                caster->CastSpell(caster, SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_RETRIBUTION, true);
                caster->CastSpell(caster, SPELL_PALADIN_ANCIENT_CRUSADER, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pal_guardian_of_ancient_kings::HandleDummyEffect);
    }
};

class spell_pal_ancient_healer : public AuraScript
{
    PrepareAuraScript(spell_pal_ancient_healer);

    bool Load() override
    {    
        _procCount = 0;
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_LIGHT_OF_THE_ANCIENT_KINGS,
                SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_HOLY
            });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return _procCount < 5;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        HealInfo* heal = eventInfo.GetHealInfo();
        if (!heal)
            return;

        int32 bp0 = heal->GetHeal();
        int32 bp1 = CalculatePct(heal->GetHeal(), 10);


        for (Unit* guardian : GetTarget()->m_Controlled)
        {
            if (guardian->GetUInt32Value(UNIT_CREATED_BY_SPELL) == SPELL_PALADIN_GUARDIAN_OF_ANCIENT_KINGS_HOLY)
                guardian->CastCustomSpell(heal->GetTarget(), SPELL_PALADIN_LIGHT_OF_THE_ANCIENT_KINGS, &bp0, &bp1, nullptr, false, nullptr, aurEff);
        }

        _procCount++;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pal_ancient_healer::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pal_ancient_healer::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    uint8 _procCount;
};

class spell_pal_ancient_crusader : public AuraScript
{
    PrepareAuraScript(spell_pal_ancient_crusader);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PALADIN_ANCIENT_POWER,
                SPELL_PALADIN_ANCIENT_CRUSADER_GUARDIAN,
                SPELL_PALADIN_ANCIENT_FURY
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (m_scriptSpellId == SPELL_PALADIN_ANCIENT_CRUSADER_GUARDIAN)
        {
            if (TempSummon* summon = GetTarget()->ToTempSummon())
                if (Unit* summoner = summon->GetSummoner())
                    summoner->CastSpell(summoner, SPELL_PALADIN_ANCIENT_POWER, true, nullptr, aurEff);
        }
        else
            GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ANCIENT_POWER, true, nullptr, aurEff);
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (m_scriptSpellId != SPELL_PALADIN_ANCIENT_CRUSADER)
            return;

        Unit* target = GetTarget();
        if (Aura* aura = target->GetAura(SPELL_PALADIN_ANCIENT_POWER))
        {
            target->CastSpell(target, SPELL_PALADIN_ANCIENT_FURY, true, nullptr, aurEff);
            aura->Remove();
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_pal_ancient_crusader::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_pal_ancient_crusader::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_pal_ancient_fury : public SpellScript
{
    PrepareSpellScript(spell_pal_ancient_fury);

    bool Load() override
    {
        _targetCount = 0;
        return true;
    }

    void CountTargets(std::list<WorldObject*>& targets)
    {
        _targetCount = targets.size();
    }

    void CalculateDamage()
    {
        Unit* caster = GetCaster();
        if (!_targetCount || !caster)
            return;

        if (Aura* powerAura = caster->GetAura(SPELL_PALADIN_ANCIENT_POWER))
        {
            int32 damage = GetHitDamage() * powerAura->GetStackAmount();
            SetHitDamage(damage / _targetCount);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_ancient_fury::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnHit += SpellHitFn(spell_pal_ancient_fury::CalculateDamage);
    }

private:
    uint32 _targetCount;
};

// 85222 - Light of Dawn
class spell_pal_light_of_dawn: public SpellScript
{
    PrepareSpellScript(spell_pal_light_of_dawn);

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
            return false;

        return true;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 const maxTargets = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_PALADIN, PALADIN_ICON_ID_GLYPH_OF_LIGHT_OF_DAWN, EFFECT_0) ? 6 : 4;

        if (targets.size() > maxTargets)
        {
            targets.sort(Trinity::HealthPctOrderPred());
            targets.resize(maxTargets);
        }
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        int32 heal = GetSpellInfo()->Effects[EFFECT_1].CalcValue(caster, nullptr, GetHitUnit());
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo()->Id, SPELLMOD_DAMAGE, heal);

        heal += caster->SpellHealingBonusDone(GetHitUnit(), GetSpellInfo(), heal, HEAL, EFFECT_1);
        heal += heal * caster->GetPower(POWER_HOLY_POWER);

        // For some reason there is a 2nd effect that is being calculated correctly so we will use its data
        PreventHitEffect(EFFECT_1);
        SetHitHeal(heal);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_dawn::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_light_of_dawn::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ALLY);
    }
};

// 82327 - Holy Radiance
class spell_pal_holy_radiance: public SpellScript
{
    PrepareSpellScript(spell_pal_holy_radiance);

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
            return false;

        _targetCount = 0;

        return true;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        _targetCount = targets.size();
    }

    void HandleHeal(SpellEffIndex /*effIndex*/)
    {
        if (uint32 heal = GetHitHeal())
            if (_targetCount > 6)
                SetHitHeal((heal * 6) / _targetCount);
    }
private:
    uint8 _targetCount;

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pal_holy_radiance::HandleHeal, EFFECT_1, SPELL_EFFECT_HEAL);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_holy_radiance::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

class spell_pal_holy_radiance_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_pal_holy_radiance_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PALADIN_HOLY_RADIANCE_TRIGGERED });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_PALADIN_HOLY_RADIANCE_TRIGGERED, true, nullptr, aurEff);
    }

private:
    Position castPos;

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_holy_radiance_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_paladin_spell_scripts()
{
    RegisterAuraScript(spell_pal_ardent_defender);
    RegisterAuraScript(spell_pal_ancient_healer);
    RegisterAuraScript(spell_pal_ancient_crusader);
    RegisterSpellScript(spell_pal_ancient_fury);
    new spell_pal_aura_mastery();
    new spell_pal_aura_mastery_immune();
    RegisterAuraScript(spell_pal_avenging_wrath);
    new spell_pal_blessing_of_faith();
    RegisterAuraScript(spell_pal_communion);
    new spell_pal_consecration();
    RegisterAuraScript(spell_pal_divine_purpose);
    new spell_pal_divine_sacrifice();
    new spell_pal_divine_storm();
    new spell_pal_divine_storm_dummy();
    RegisterSpellAndAuraScriptPair(spell_pal_exorcism, spell_pal_exorcism_AuraScript);
    new spell_pal_exorcism_and_holy_wrath_damage();
    new spell_pal_eye_for_an_eye();
    new spell_pal_glyph_of_holy_light();
    new spell_pal_grand_crusader();
    RegisterSpellScript(spell_pal_guardian_of_ancient_kings);
    new spell_pal_hand_of_light();
    RegisterSpellAndAuraScriptPair(spell_pal_holy_radiance, spell_pal_holy_radiance_AuraScript);
    new spell_pal_hand_of_sacrifice();
    new spell_pal_holy_shock();
    new spell_pal_illuminated_healing();
    new spell_pal_improved_aura_effect("spell_pal_improved_concentraction_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_improved_devotion_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_sanctified_retribution_effect");
    RegisterSpellScript(spell_pal_inquisition);
    new spell_pal_item_healing_discount();
    new spell_pal_judgement();
    RegisterAuraScript(spell_pal_judgements);
    new spell_pal_lay_on_hands();
    new spell_pal_light_s_beacon();
    RegisterSpellScript(spell_pal_light_of_dawn);
    RegisterAuraScript(spell_pal_long_arm_of_the_law);
    new spell_pal_righteous_defense();
    RegisterAuraScript(spell_pal_sacred_shield);
    new spell_pal_seal_of_righteousness();
    RegisterAuraScript(spell_pal_seal_of_truth);
    new spell_pal_shield_of_the_righteous();
    RegisterAuraScript(spell_pal_selfless_healer);
    new spell_pal_templar_s_verdict();
    RegisterSpellAndAuraScriptPair(spell_pal_word_of_glory, spell_pal_word_of_glory_AuraScript);
}
