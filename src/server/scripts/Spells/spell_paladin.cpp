/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "Group.h"

enum PaladinSpells
{
	//Spells related to Guardian of ancient kings
    SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS         = 86150, //Dummy
    SPELL_PALADIN_GUARDIAN_RETRIBUTION           = 86698,
    SPELL_PALADIN_GUARDIAN_HOLY                  = 86669,
    SPELL_PALADIN_GUARDIAN_PROTECTION            = 86659,

    SPELL_PALADIN_AVENGERS_SHIELD               = 31935,
    SPELL_PALADIN_AURA_MASTERY_IMMUNE            = 64364,
    SPELL_PALADIN_BEACON_OF_LIGHT_MARKER         = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL           = 53652,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID   = 37878,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN = 37879,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST  = 37880,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN  = 37881,
    SPELL_PALADIN_CONCENTRACTION_AURA            = 19746,
    SPELL_PALADIN_DIVINE_PURPOSE_PROC            = 90174,
    SPELL_PALADIN_DIVINE_SACRIFICE               = 64205,
    SPELL_PALADIN_DIVINE_STORM                   = 53385,
    SPELL_PALADIN_DIVINE_STORM_DUMMY             = 54171,
    SPELL_PALADIN_DIVINE_STORM_HEAL              = 54172,
    SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1          = 9799,
    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE          = 25997,
    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_GLYPH_OF_SALVATION             = 63225,
    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_HOLY_LIGHT                     = 635,
    SPELL_PALADIN_HOLY_SHOCK_R1                  = 20473,
    SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE           = 25912,
    SPELL_PALADIN_HOLY_SHOCK_R1_HEALING          = 25914,
    SPELL_PALADIN_IMMUNE_SHIELD_MARKER           = 61988,
    SPELL_PALADIN_IMPROVED_CONCENTRACTION_AURA   = 63510,
    SPELL_PALADIN_IMPROVED_DEVOTION_AURA         = 63514,
    SPELL_PALADIN_ITEM_HEALING_TRANCE            = 37706,
    SPELL_PALADIN_JUDGEMENT_DAMAGE               = 54158, 
    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT        = 31790,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA    = 63531,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1      = 31869,
    SPELL_PALADIN_SEAL_OF_JUSTICE                = 20164, 
    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS          = 25742,
    SPELL_PALADIN_SWIFT_RETRIBUTION_R1           = 53379,
    SPELL_PALADIN_SEAL_OF_INSIGHT                = 20167,
    SPELL_PALADIN_SACRED_SHIELD_TRIGGERED        = 96263
};

enum MiscSpells
{
    SPELL_GENERIC_ARENA_DAMPENING                = 74410,
    SPELL_GENERIC_BATTLEGROUND_DAMPENING         = 74411
};

enum PaladinSpellIcons
{
    PALADIN_ICON_ID_RETRIBUTION_AURA             = 555
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

            uint32 absorbPct, healPct;

            enum Spell
            {
                PAL_SPELL_ARDENT_DEFENDER_HEAL = 66235,
            };

            bool Load() OVERRIDE
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & canBeRecalculated)
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
                if (remainingHealth <= 0 && !victim->ToPlayer()->HasSpellCooldown(PAL_SPELL_ARDENT_DEFENDER_HEAL))
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
                    victim->ToPlayer()->AddSpellCooldown(PAL_SPELL_ARDENT_DEFENDER_HEAL, 0, time(NULL) + 120);
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

            void Register() OVERRIDE
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_ardent_defender_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_ardent_defender_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_ardent_defender_AuraScript();
        }
};
*/

// 31821 - Aura Mastery
class spell_pal_aura_mastery : public SpellScriptLoader
{
    public:
        spell_pal_aura_mastery() : SpellScriptLoader("spell_pal_aura_mastery") { }

        class spell_pal_aura_mastery_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_aura_mastery_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pal_aura_mastery_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_aura_mastery_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_CONCENTRACTION_AURA))
                    return false;
                return true;
            }

            bool CheckAreaTarget(Unit* target)
            {
                return target->HasAura(SPELL_PALADIN_CONCENTRACTION_AURA, GetCasterGUID());
            }

            void Register() OVERRIDE
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_pal_aura_mastery_immune_AuraScript::CheckAreaTarget);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_aura_mastery_immune_AuraScript();
        }
};

// 53651 - Beacon of Light
class spell_pal_beacon_of_light : public SpellScriptLoader
{
    public:
        spell_pal_beacon_of_light() : SpellScriptLoader("spell_pal_beacon_of_light") { }

        class spell_pal_beacon_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_beacon_of_light_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActionTarget()->GetAura(SPELL_PALADIN_BEACON_OF_LIGHT_MARKER, GetCasterGUID()))
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
                for (Unit::AuraList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
           if(!(*itr))
           continue;
                    if ((*itr)->GetId() == SPELL_PALADIN_BEACON_OF_LIGHT_MARKER)
                    {
                        std::list<AuraApplication*> applications;
                        (*itr)->GetApplicationList(applications);
                        if (applications.empty())
                            return;

                        GetCaster()->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, heal, applications.front()->GetTarget(), true, NULL, aurEff);
                        return;
                    }
                }
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_beacon_of_light_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_beacon_of_light_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_beacon_of_light_AuraScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_blessing_of_faith_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_blessing_of_faith_SpellScript();
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

            bool Load() OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectSplit += AuraEffectSplitFn(spell_pal_divine_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            uint32 healPct;

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STORM_DUMMY))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }

            void TriggerHeal()
            {
                Unit* caster = GetCaster();
                caster->CastCustomSpell(SPELL_PALADIN_DIVINE_STORM_DUMMY, SPELLVALUE_BASE_POINT0, (GetHitDamage() * healPct) / 100, caster, true);
            }

            void Register() OVERRIDE
            {
                AfterHit += SpellHitFn(spell_pal_divine_storm_SpellScript::TriggerHeal);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_divine_storm_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_divine_storm_dummy_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            void Register() OVERRIDE
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pal_exorcism_and_holy_wrath_damage_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_exorcism_and_holy_wrath_damage_AuraScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_AVENGERS_SHIELD))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetTarget()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->ToPlayer()->RemoveSpellCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_grand_crusader_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_grand_crusader_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_grand_crusader_AuraScript();
        }
};

// -9799 - Eye for an Eye dream wow 
class spell_pal_eye_for_an_eye : public SpellScriptLoader
{
    public:
        spell_pal_eye_for_an_eye() : SpellScriptLoader("spell_pal_eye_for_an_eye") { }

        class spell_pal_eye_for_an_eye_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_eye_for_an_eye_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
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

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_pal_eye_for_an_eye_AuraScript();
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

            int32 remainingAmount;

            bool Load() OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* spellInfo) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            void Register() OVERRIDE
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_pal_improved_aura_effect_AuraScript::CheckAreaTarget);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_item_healing_discount_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_item_healing_discount_AuraScript();
        }
};

// 20271 - Judgement
class spell_pal_judgement : public SpellScriptLoader
{
    public:
        spell_pal_judgement() : SpellScriptLoader("spell_pal_judgement") { }

        class spell_pal_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SEAL_OF_INSIGHT) || 
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_SEAL_OF_JUSTICE))
                    return false;

                return true;
            }
            
            void SwitchSpell()
            {
                if(Unit* target = GetExplTargetUnit())
                {
                    Unit* caster = GetCaster();
                    uint32 spellId = 0;

                    // Seal of Truth and Seal of Righteousness have a dummy aura on effect 2
                    Unit::AuraApplicationMap & sealAuras = caster->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::iterator iter = sealAuras.begin(); iter != sealAuras.end();)
                    {
                        Aura* aura = iter->second->GetBase();
                        if (aura->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_SEAL)
                        {
                            if (AuraEffect* aureff = aura->GetEffect(2))
                            {
                                if (aureff->GetAuraType() == SPELL_AURA_DUMMY)
                                {
                                    if (sSpellMgr->GetSpellInfo(aureff->GetAmount()))
                                        spellId = aureff->GetAmount();
                                    break;
                                }
                            }
                            if (!spellId)
                            {
                                switch (iter->first)
                                {
                                    // Seal of Insight, Seal of Justice
                                    case SPELL_PALADIN_SEAL_OF_JUSTICE:
                                    case SPELL_PALADIN_SEAL_OF_INSIGHT:
                                        spellId = SPELL_PALADIN_JUDGEMENT_DAMAGE;
                                }
                            }
                            break;
                        }
                        else
                            ++iter;
                    }
                    // Cast Judgement
                    if (spellId)
                        caster->CastSpell(target, spellId, true);
                }
            }

            void Register() OVERRIDE
            {
                OnCast += SpellCastFn(spell_pal_judgement_SpellScript::SwitchSpell);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_FORBEARANCE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_IMMUNE_SHIELD_MARKER))
                    return false;
                return true;
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

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_lay_on_hands_SpellScript::CheckCast);
                AfterHit += SpellHitFn(spell_pal_lay_on_hands_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_lay_on_hands_SpellScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
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

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_righteous_defense_SpellScript();
        }
};

//85285 Sacred Shield
//DELETE FROM spell_script_names WHERE spell_id = 85285;
//INSERT INTO spell_script_names VALUES (20165,'spell_pal_sacred_shield');
//INSERT INTO `conditions` VALUES ('24','0','85285','0','0','38','1','30','4','0','0','0','0','',NULL);

class spell_pal_sacred_shield : public SpellScriptLoader
{
    public:
        spell_pal_sacred_shield() : SpellScriptLoader("spell_pal_sacred_shield") { }

        class spell_pal_sacred_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_sacred_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SACRED_SHIELD_TRIGGERED))
                    return false;
                return true;
            }

			bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->HasSpellCooldown(SPELL_PALADIN_SACRED_SHIELD_TRIGGERED))
                        return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
				if(Player* p = GetTarget()->ToPlayer())
				{
					int32 absorb_amount = int32(1 + 2.8 * p->GetTotalAttackPowerValue(BASE_ATTACK));
					int32 heal_improvement_pct = 20;
					p->CastCustomSpell(p,SPELL_PALADIN_SACRED_SHIELD_TRIGGERED,&absorb_amount,&heal_improvement_pct,NULL,true);
					p->AddSpellCooldown(SPELL_PALADIN_SACRED_SHIELD_TRIGGERED,0,time(NULL)+60);
				}

            }

            void Register() OVERRIDE
            {
				DoCheckProc += AuraCheckProcFn(spell_pal_sacred_shield_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_sacred_shield_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_sacred_shield_AuraScript();
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

            bool Validate (SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                    return false;

                return true;
            }

            bool Load() OVERRIDE
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
                            damage = damage;
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_templar_s_verdict_SpellScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget();
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

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_seal_of_righteousness_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_righteousness_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_seal_of_righteousness_AuraScript();
        }
};

class spell_pal_guardian_ancient_kings : public SpellScriptLoader
{
    public:
        spell_pal_guardian_ancient_kings() : SpellScriptLoader("spell_pal_guardian_ancient_kings") { }

        class spell_pal_guardian_ancient_kings_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_guardian_ancient_kings_SpellScript);

            bool Validate (SpellInfo const* /*spellEntry*/)
            {
				if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_GUARDIAN_HOLY) ||
					!sSpellMgr->GetSpellInfo(SPELL_PALADIN_GUARDIAN_RETRIBUTION) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_GUARDIAN_PROTECTION))
					return false;

				return true;
            }

            bool Load() OVERRIDE
            {

               if (GetCaster()->GetTypeId() != TYPEID_PLAYER) //Check if caster is a player. 
                return false;

			   else if(GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
				   return false;

			   else
			   return true;
            }

			void HandleDummy(SpellEffIndex /*effIndex*/)
			{
				if (Unit* caster = GetCaster())
				{
					//Check first spell in every spec to decide which guardian should be summoned.
					if (caster->ToPlayer()->HasSpell(20473)) 
					{
						caster->CastSpell(caster, SPELL_PALADIN_GUARDIAN_HOLY, false);
						return;
					}

					else if (caster->ToPlayer()->HasSpell(31935)) 
					{
						caster->CastSpell(caster, SPELL_PALADIN_GUARDIAN_PROTECTION, false);
						return;
					}

					else if (caster->ToPlayer()->HasSpell(85256)) 
					{
						caster->CastSpell(caster, SPELL_PALADIN_GUARDIAN_RETRIBUTION, false);
						return;
					}
				}
			}

            void Register() OVERRIDE
            {
                OnEffectLaunch += SpellEffectFn(spell_pal_guardian_ancient_kings_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_guardian_ancient_kings_SpellScript();
        }
};

// 20425 - Judgement of Command DREAM WOW

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

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgement_of_command_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pal_judgement_of_command_SpellScript();
        }
};

/// judgmenets pala DREAM WOW 

enum Judgements
{
	SPELL_JUDGEMENT_TRIGGER           = 23590, 
	SPELL_JUDGEMENT_LONG_ARM_OF_LAWL  = 87173,
	SPELL_JUDGEMENT_WISE              = 31930,
	SPELL_JUDGEMENT_BOLD              = 89906,
	SPELL_JUDGEMENT_PURE              = 53655,
	SPELL_JUDGEMENT_ENLIGHTENED       = 87188,
};

/// Updated 4.3.4
class spell_pal_judgements : public SpellScriptLoader
{
    public:
        spell_pal_judgements() : SpellScriptLoader("spell_pal_judgements") { }

        class spell_pal_judgements_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgements_SpellScript);

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

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
		        {
                	caster->CastSpell(target, SPELL_JUDGEMENT_TRIGGER, true);
                	int32 regen = 0;

         	        if (caster->HasAura(89901)) // Jugements of the bold
                 	{
                   	   regen = int32(caster->GetCreateMana() * 0.025);
                   	   caster->CastCustomSpell(caster, SPELL_JUDGEMENT_BOLD, &regen, 0, 0, true);
		  	        }
         	  	    if (caster->HasAura(31878)) // Judgements of the Wise
                	{
                        regen = int32(caster->GetCreateMana() * 0.030);
                   	    caster->CastCustomSpell(caster, SPELL_JUDGEMENT_WISE, &regen, 0, 0, true);
		  	        }

		 	        if (caster->HasAura(87168)) // Long arm of Lawl Rank 1
				    {
                  		  if (roll_chance_i(50.0f))
                      		  if (caster->GetDistance(target) > 15.0f || !caster->IsWithinDistInMap(target, 15.0f)) 
                    				caster->CastSpell(caster, SPELL_JUDGEMENT_LONG_ARM_OF_LAWL, true);
			        }
		   	        else if (caster->HasAura(87172)) // Long arm of Lawl Rank 2
					{
                       	 if (caster->GetDistance(target) > 15.0f || !caster->IsWithinDistInMap(target, 15.0f)) 
                    	     caster->CastSpell(caster, SPELL_JUDGEMENT_LONG_ARM_OF_LAWL, true);
				    }

		 		    if (caster->HasAura(53671)) // Judgements of the Pure
                    		caster->CastSpell(caster, SPELL_JUDGEMENT_PURE, true);
		  	        if (caster->HasAura(53673)) 
                    		caster->CastSpell(caster, SPELL_JUDGEMENT_PURE+1, true);
		  	        if (caster->HasAura(54151)) 
                    		caster->CastSpell(caster, SPELL_JUDGEMENT_PURE+2, true);

		  	        if (caster->HasAura(53556)) // Enlightened Judgements
                    		caster->CastSpell(caster, SPELL_JUDGEMENT_ENLIGHTENED, true);
		  	        if (caster->HasAura(53557)) 
                    		caster->CastSpell(caster, SPELL_JUDGEMENT_ENLIGHTENED+1, true);
		        }
            } 


            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgements_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pal_judgements_SpellScript();
        }
};

// Light of Dawn dream wow 
class spell_pal_lod : public SpellScriptLoader
{
    public:
        spell_pal_lod() : SpellScriptLoader("spell_pal_lod") { }

        class spell_pal_lod_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_lod_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                std::list<Unit*> temp;
                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); itr++)
                    if (Unit* unit = (*itr)->ToUnit())
                        temp.push_back(unit);

                targets.clear();
                temp.sort(Trinity::HealthPctOrderPred());
                if (temp.size() > 6)
                    temp.resize(6);                
                for (std::list<Unit*>::iterator itr = temp.begin(); itr != temp.end(); itr++)
                    targets.push_back((WorldObject*)(*itr));
            }

			void HandleOnEffectHit(SpellEffIndex /*effIndex*/)
			{
				Player * p = GetCaster()->ToPlayer();
				int32 heal = int32(GetEffectValue() + 0.156*p->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_ALL));
				int8 hp_charges = p->GetPower(POWER_HOLY_POWER); //Formula: 606 a 874 por cada carga de Holy Power
				int32 total_heal = heal * (hp_charges + 1); //El mas 1 es porque Trinity detecta mal las cargas de poder sagrado, cuando tienes 3 te detecta solo 2, cuando tienes 2 te detecta 1 y cuando tienes 1 no te detecta ninguna.
				SetHitHeal(total_heal);
			}

            void HandleAfterCast()
            {
                Player* p = GetCaster()->ToPlayer();
                p->SetPower(POWER_HOLY_POWER, 0);           
	        }

            void Register()
            {

                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_lod_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_pal_lod_SpellScript::HandleOnEffectHit, EFFECT_0, SPELL_EFFECT_HEAL);
                AfterCast += SpellCastFn(spell_pal_lod_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pal_lod_SpellScript();
        }
};

// 53600 - Shield of the Righteous DREAM WOW 
/// Updated 4.3.4
class spell_pal_shield_of_the_righteous : public SpellScriptLoader
{
    public:
        spell_pal_shield_of_the_righteous() : SpellScriptLoader("spell_pal_shield_of_the_righteous") { }

        class spell_pal_shield_of_the_righteous_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_shield_of_the_righteous_SpellScript);

            bool Load()
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
                damage *= 0.5*hp*hp + 1.5*hp + 1;

                SetHitDamage(damage);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_shield_of_the_righteous_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pal_shield_of_the_righteous_SpellScript();
        }
};


//  20165 Seal of Insight
//DELETE FROM spell_script_names WHERE spell_id = 20165;
//INSERT INTO spell_script_names VALUES (20165,'spell_pal_seal_of_insight');

class spell_pal_seal_of_insight : public SpellScriptLoader
{
    public:
        spell_pal_seal_of_insight() : SpellScriptLoader("spell_pal_seal_of_insight") { }

        class spell_pal_seal_of_insight_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_seal_of_insight_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SEAL_OF_INSIGHT))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
				if(Player* p = GetCaster()->ToPlayer())
				{
					int32 heal_amount = int32(0.15*p->GetTotalAttackPowerValue(BASE_ATTACK)+0.15*p->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_ALL));
					int32 mana_amount = p->GetMaxPower(POWER_MANA) * 0.04;
					p->CastCustomSpell(p,SPELL_PALADIN_SEAL_OF_INSIGHT,&heal_amount,&mana_amount,NULL,true);
				}

            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_insight_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_seal_of_insight_AuraScript();
        }
};

// Inquisition DREAM WOW
class spell_pal_inquisition : public SpellScriptLoader
{
    public:
        spell_pal_inquisition() : SpellScriptLoader("spell_pal_inquisition") { }

        class spell_pal_inquisition_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_inquisition_SpellScript);

            void HandleApply(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                int8 holypower = caster->GetPower(POWER_HOLY_POWER);
		  int32 total_power = (holypower + 1);
                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                holypower = GetCaster()->GetMaxPower(POWER_HOLY_POWER);
                Aura* aura = GetHitAura();
                aura->SetDuration(aura->GetMaxDuration() * total_power);
            }
			
	     void HandleAfterCast()
            {
                Player* p = GetCaster()->ToPlayer();
                p->SetPower(POWER_HOLY_POWER, 0);           
	     }
			
            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_inquisition_SpellScript::HandleApply, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
		  AfterCast += SpellCastFn(spell_pal_inquisition_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pal_inquisition_SpellScript();
        }
};

void AddSC_paladin_spell_scripts()
{
    //new spell_pal_ardent_defender();
    new spell_pal_aura_mastery();
    new spell_pal_aura_mastery_immune();
    new spell_pal_beacon_of_light();
    new spell_pal_blessing_of_faith();
    new spell_pal_divine_sacrifice();
    new spell_pal_divine_storm();
    new spell_pal_divine_storm_dummy();
    new spell_pal_exorcism_and_holy_wrath_damage();
    new spell_pal_eye_for_an_eye();
    new spell_pal_grand_crusader();
    new spell_pal_hand_of_sacrifice();
    new spell_pal_holy_shock();
    new spell_pal_improved_aura_effect("spell_pal_improved_concentraction_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_improved_devotion_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_sanctified_retribution_effect");
    new spell_pal_item_healing_discount();
    new spell_pal_judgement();
    new spell_pal_lay_on_hands();
    new spell_pal_righteous_defense();
    new spell_pal_sacred_shield();
    new spell_pal_templar_s_verdict();
    new spell_pal_seal_of_righteousness();
    new spell_pal_guardian_ancient_kings();
    new spell_pal_judgement_of_command();
    new spell_pal_judgements();
    new spell_pal_shield_of_the_righteous();
    new spell_pal_seal_of_insight();
    new spell_pal_lod();
    new spell_pal_inquisition();
	
}