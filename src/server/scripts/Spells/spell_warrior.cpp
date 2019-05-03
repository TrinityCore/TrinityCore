/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_WARRIOR and SPELLFAMILY_GENERIC spells used by warrior players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warr_".
 */

#include "ScriptMgr.h"
#include "ItemTemplate.h"
#include "Optional.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum WarriorSpells
{
    SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND     = 50622,
    SPELL_WARRIOR_BLOODTHIRST                       = 23885,
    SPELL_WARRIOR_BLOODTHIRST_DAMAGE                = 23881,
    SPELL_WARRIOR_BLOODSURGE_R1                     = 46913,
    SPELL_WARRIOR_CHARGE                            = 34846,
    SPELL_WARRIOR_DAMAGE_SHIELD_DAMAGE              = 59653,
    SPELL_WARRIOR_DEEP_WOUNDS_RANK_1                = 12162,
    SPELL_WARRIOR_DEEP_WOUNDS_RANK_2                = 12850,
    SPELL_WARRIOR_DEEP_WOUNDS_RANK_3                = 12868,
    SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC              = 12721,
    SPELL_WARRIOR_EXECUTE                           = 20647,
    SPELL_WARRIOR_EXECUTE_GCD_REDUCED               = 71069,
    SPELL_WARRIOR_EXTRA_CHARGE                      = 70849,
    SPELL_WARRIOR_GLYPH_OF_EXECUTION                = 58367,
    SPELL_WARRIOR_GLYPH_OF_VIGILANCE                = 63326,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF        = 65156,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT      = 64976,
    SPELL_WARRIOR_LAST_STAND_TRIGGERED              = 12976,
    SPELL_WARRIOR_RETALIATION_DAMAGE                = 20240,
    SPELL_WARRIOR_SLAM                              = 50783,
    SPELL_WARRIOR_SLAM_GCD_REDUCED                  = 71072,
    SPELL_WARRIOR_SUDDEN_DEATH_R1                   = 29723,
    SPELL_WARRIOR_SUNDER_ARMOR                      = 58567,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1   = 12723,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2   = 26654,
    SPELL_WARRIOR_TAUNT                             = 355,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_1        = 46859,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_2        = 46860,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_1     = 64849,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_2     = 64850,
    SPELL_WARRIOR_VIGILANCE_PROC                    = 50725,
    SPELL_WARRIOR_VIGILANCE_REDIRECT_THREAT         = 59665,
    SPELL_WARRIOR_IMPROVED_SPELL_REFLECTION_TRIGGER = 59725,
    SPELL_WARRIOR_SECOND_WIND_TRIGGER_1             = 29841,
    SPELL_WARRIOR_SECOND_WIND_TRIGGER_2             = 29842,
    SPELL_WARRIOR_GLYPH_OF_BLOCKING                 = 58374,
    SPELL_WARRIOR_STOICISM                          = 70845,
    SPELL_WARRIOR_T10_MELEE_4P_BONUS                = 70847
};

enum WarriorSpellIcons
{
    WARRIOR_ICON_ID_SUDDEN_DEATH                    = 1989
};

enum MiscSpells
{
    SPELL_PALADIN_BLESSING_OF_SANCTUARY             = 20911,
    SPELL_PALADIN_GREATER_BLESSING_OF_SANCTUARY     = 25899,
    SPELL_PRIEST_RENEWED_HOPE                       = 63944,
    SPELL_GEN_DAMAGE_REDUCTION_AURA                 = 68066,
    SPELL_CATEGORY_SHIELD_SLAM                      = 1209
};

// 23881 - Bloodthirst
class spell_warr_bloodthirst : public SpellScriptLoader
{
    public:
        spell_warr_bloodthirst() : SpellScriptLoader("spell_warr_bloodthirst") { }

        class spell_warr_bloodthirst_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_bloodthirst_SpellScript);

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                uint32 APbonus = GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK);
                if (Unit* victim = GetHitUnit())
                    APbonus += victim->GetTotalAuraModifier(SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS);

                SetEffectValue(CalculatePct(APbonus, GetEffectValue()));
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_BLOODTHIRST, true);
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_warr_bloodthirst_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHit += SpellEffectFn(spell_warr_bloodthirst_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_bloodthirst_SpellScript();
        }
};

// 23880 - Bloodthirst (Heal)
class spell_warr_bloodthirst_heal : public SpellScriptLoader
{
    public:
        spell_warr_bloodthirst_heal() : SpellScriptLoader("spell_warr_bloodthirst_heal") { }

        class spell_warr_bloodthirst_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_bloodthirst_heal_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_BLOODTHIRST_DAMAGE });
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_BLOODTHIRST_DAMAGE);
                int32 const healPct = spellInfo->Effects[EFFECT_1].CalcValue(GetCaster());
                SetEffectValue(GetCaster()->CountPctFromMaxHealth(healPct));
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_warr_bloodthirst_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_bloodthirst_heal_SpellScript();
        }
};

// -100 - Charge
class spell_warr_charge : public SpellScriptLoader
{
    public:
        spell_warr_charge() : SpellScriptLoader("spell_warr_charge") { }

        class spell_warr_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_charge_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT, SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF, SPELL_WARRIOR_CHARGE });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(GetEffectValue());
                caster->CastSpell(caster, SPELL_WARRIOR_CHARGE, args);

                // Juggernaut crit bonus
                if (caster->HasAura(SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT))
                    caster->CastSpell(caster, SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_charge_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_charge_SpellScript();
        }
};

// 12809 - Concussion Blow
class spell_warr_concussion_blow : public SpellScriptLoader
{
    public:
        spell_warr_concussion_blow() : SpellScriptLoader("spell_warr_concussion_blow") { }

        class spell_warr_concussion_blow_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_concussion_blow_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                SetEffectValue(CalculatePct(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetSpellInfo()->Effects[EFFECT_2].CalcValue()));
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_warr_concussion_blow_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_concussion_blow_SpellScript();
        }
};

// -58872 - Damage Shield
class spell_warr_damage_shield : public SpellScriptLoader
{
    public:
        spell_warr_damage_shield() : SpellScriptLoader("spell_warr_damage_shield") { }

        class spell_warr_damage_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_damage_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_DAMAGE_SHIELD_DAMAGE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                // % of amount blocked
                int32 damage = CalculatePct(int32(GetTarget()->GetShieldBlockValue()), aurEff->GetAmount());
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(damage);
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARRIOR_DAMAGE_SHIELD_DAMAGE, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_damage_shield_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_damage_shield_AuraScript();
        }
};

// -12162 - Deep Wounds
class spell_warr_deep_wounds : public SpellScriptLoader
{
    public:
        spell_warr_deep_wounds() : SpellScriptLoader("spell_warr_deep_wounds") { }

        class spell_warr_deep_wounds_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_deep_wounds_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARRIOR_DEEP_WOUNDS_RANK_1,
                    SPELL_WARRIOR_DEEP_WOUNDS_RANK_2,
                    SPELL_WARRIOR_DEEP_WOUNDS_RANK_3,
                    SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC
                });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    ApplyPct(damage, 16 * GetSpellInfo()->GetRank());

                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC);

                    ASSERT(spellInfo->GetMaxTicks() > 0);
                    damage /= spellInfo->GetMaxTicks();

                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellBP0(damage);
                    caster->CastSpell(target, SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC, args);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_deep_wounds_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_deep_wounds_SpellScript();
        }
};

// -12834 - Deep Wounds Aura
class spell_warr_deep_wounds_aura : public SpellScriptLoader
{
    public:
        spell_warr_deep_wounds_aura() : SpellScriptLoader("spell_warr_deep_wounds_aura") { }

        class spell_warr_deep_wounds_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_deep_wounds_aura_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo)
                    return false;

                return eventInfo.GetActor()->GetTypeId() == TYPEID_PLAYER;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* actor = eventInfo.GetActor();
                float damage = 0.f;

                if (eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK)
                    damage = (actor->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE) + actor->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE)) / 2.f;
                else
                    damage = (actor->GetFloatValue(UNIT_FIELD_MINDAMAGE) + actor->GetFloatValue(UNIT_FIELD_MAXDAMAGE)) / 2.f;

                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(damage);
                actor->CastSpell(eventInfo.GetProcTarget(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, args);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_deep_wounds_aura_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_deep_wounds_aura_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_deep_wounds_aura_AuraScript();
        }
};

// -5308 - Execute
class spell_warr_execute : public SpellScriptLoader
{
    public:
        spell_warr_execute() : SpellScriptLoader("spell_warr_execute") { }

        class spell_warr_execute_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_execute_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_EXECUTE, SPELL_WARRIOR_GLYPH_OF_EXECUTION });
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    SpellInfo const* spellInfo = GetSpellInfo();
                    int32 rageUsed = std::min<int32>(300 - spellInfo->CalcPowerCost(caster, SpellSchoolMask(spellInfo->SchoolMask)), caster->GetPower(POWER_RAGE));
                    int32 newRage = std::max<int32>(0, caster->GetPower(POWER_RAGE) - rageUsed);

                    // Sudden Death rage save
                    if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_GENERIC, WARRIOR_ICON_ID_SUDDEN_DEATH, EFFECT_0))
                    {
                        int32 ragesave = aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue() * 10;
                        newRage = std::max(newRage, ragesave);
                    }

                    caster->SetPower(POWER_RAGE, uint32(newRage));
                    // Glyph of Execution bonus
                    if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_WARRIOR_GLYPH_OF_EXECUTION, EFFECT_0))
                        rageUsed += aurEff->GetAmount() * 10;


                    int32 bp = GetEffectValue() + int32(rageUsed * spellInfo->Effects[effIndex].DamageMultiplier + caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.2f);
                    CastSpellExtraArgs args(GetOriginalCaster()->GetGUID());
                    args.AddSpellBP0(bp);
                    caster->CastSpell(target, SPELL_WARRIOR_EXECUTE, args);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_execute_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_execute_SpellScript();
        }
};

// -29723 - Sudden Death
// -46913 - Bloodsurge
class spell_warr_extra_proc : public SpellScriptLoader
{
    public:
        spell_warr_extra_proc() : SpellScriptLoader("spell_warr_extra_proc") { }

        class spell_warr_extra_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_extra_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARRIOR_T10_MELEE_4P_BONUS,
                    SPELL_WARRIOR_EXTRA_CHARGE,
                    SPELL_WARRIOR_SLAM_GCD_REDUCED,
                    SPELL_WARRIOR_EXECUTE_GCD_REDUCED
                });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                Unit* target = GetTarget();
                AuraEffect const* bonusAurEff = target->GetAuraEffect(SPELL_WARRIOR_T10_MELEE_4P_BONUS, EFFECT_0);
                if (!bonusAurEff)
                    return;

                if (!roll_chance_i(bonusAurEff->GetAmount()))
                    return;

                target->CastSpell(nullptr, SPELL_WARRIOR_EXTRA_CHARGE, aurEff);

                SpellInfo const* auraInfo = aurEff->GetSpellInfo();
                if (auraInfo->IsRankOf(sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_BLOODSURGE_R1)))
                    target->CastSpell(nullptr, SPELL_WARRIOR_SLAM_GCD_REDUCED, aurEff);
                else if (auraInfo->IsRankOf(sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_SUDDEN_DEATH_R1)))
                    target->CastSpell(nullptr, SPELL_WARRIOR_EXECUTE_GCD_REDUCED, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_extra_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_extra_proc_AuraScript();
        }
};

// 58375 - Glyph of Blocking
class spell_warr_glyph_of_blocking : public SpellScriptLoader
{
    public:
        spell_warr_glyph_of_blocking() : SpellScriptLoader("spell_warr_glyph_of_blocking") { }

        class spell_warr_glyph_of_blocking_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_glyph_of_blocking_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_GLYPH_OF_BLOCKING });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, SPELL_WARRIOR_GLYPH_OF_BLOCKING, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_glyph_of_blocking_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_glyph_of_blocking_AuraScript();
        }
};

// 58387 - Glyph of Sunder Armor
class spell_warr_glyph_of_sunder_armor : public SpellScriptLoader
{
    public:
        spell_warr_glyph_of_sunder_armor() : SpellScriptLoader("spell_warr_glyph_of_sunder_armor") { }

        class spell_warr_glyph_of_sunder_armor_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_glyph_of_sunder_armor_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(aurEff->GetBase());
                    spellMod->op = SpellModOp(aurEff->GetMiscValue());
                    spellMod->type = SPELLMOD_FLAT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() override
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_warr_glyph_of_sunder_armor_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_glyph_of_sunder_armor_AuraScript();
        }
};

// -59088 - Improved Spell Reflection
class spell_warr_improved_spell_reflection : public SpellScriptLoader
{
    public:
        spell_warr_improved_spell_reflection() : SpellScriptLoader("spell_warr_improved_spell_reflection") { }

        class spell_warr_improved_spell_reflection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_improved_spell_reflection_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_IMPROVED_SPELL_REFLECTION_TRIGGER });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                CastSpellExtraArgs args(aurEff);
                args.AddSpellMod(SPELLVALUE_MAX_TARGETS, aurEff->GetAmount());
                caster->CastSpell(caster, SPELL_WARRIOR_IMPROVED_SPELL_REFLECTION_TRIGGER, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_improved_spell_reflection_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_improved_spell_reflection_AuraScript();
        }
};

// 5246 - Intimidating Shout
class spell_warr_intimidating_shout : public SpellScriptLoader
{
    public:
        spell_warr_intimidating_shout() : SpellScriptLoader("spell_warr_intimidating_shout") { }

        class spell_warr_intimidating_shout_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_intimidating_shout_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove(GetExplTargetWorldObject());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_intimidating_shout_SpellScript();
        }
};

// 70844 - Item - Warrior T10 Protection 4P Bonus
class spell_warr_item_t10_prot_4p_bonus : public SpellScriptLoader
{
    public:
        spell_warr_item_t10_prot_4p_bonus() : SpellScriptLoader("spell_warr_item_t10_prot_4p_bonus") { }

        class spell_warr_item_t10_prot_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_item_t10_prot_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_STOICISM });
            }

            void HandleProc(ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* target = eventInfo.GetActionTarget();
                int32 bp0 = CalculatePct(target->GetMaxHealth(), GetSpellInfo()->Effects[EFFECT_1].CalcValue());
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(bp0);
                target->CastSpell(nullptr, SPELL_WARRIOR_STOICISM, args);
            }

            void Register() override
            {
                OnProc += AuraProcFn(spell_warr_item_t10_prot_4p_bonus_AuraScript::HandleProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_item_t10_prot_4p_bonus_AuraScript();
        }
};

// 12975 - Last Stand
class spell_warr_last_stand : public SpellScriptLoader
{
    public:
        spell_warr_last_stand() : SpellScriptLoader("spell_warr_last_stand") { }

        class spell_warr_last_stand_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_last_stand_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_LAST_STAND_TRIGGERED });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(caster->CountPctFromMaxHealth(GetEffectValue()));
                caster->CastSpell(caster, SPELL_WARRIOR_LAST_STAND_TRIGGERED, args);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_warr_last_stand_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_last_stand_SpellScript();
        }
};

// 7384, 7887, 11584, 11585 - Overpower
class spell_warr_overpower : public SpellScriptLoader
{
    public:
        spell_warr_overpower() : SpellScriptLoader("spell_warr_overpower") { }

        class spell_warr_overpower_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_overpower_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = 0;
                if (GetCaster()->HasAura(SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_1))
                    spellId = SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_1;
                else if (GetCaster()->HasAura(SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_2))
                    spellId = SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_2;

                if (!spellId)
                    return;

                if (Player* target = GetHitPlayer())
                    if (target->IsNonMeleeSpellCast(false, false, true)) // UNIT_STATE_CASTING should not be used here, it's present during a tick for instant casts
                        target->CastSpell(target, spellId, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_overpower_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ANY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_overpower_SpellScript();
        }
};

// -772 - Rend
class spell_warr_rend : public SpellScriptLoader
{
    public:
        spell_warr_rend() : SpellScriptLoader("spell_warr_rend") { }

        class spell_warr_rend_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_rend_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
            {
                if (Unit* caster = GetCaster())
                {
                    canBeRecalculated = false;

                    // $0.2 * (($MWB + $mwb) / 2 + $AP / 14 * $MWS) bonus per tick
                    float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
                    int32 mws = caster->GetAttackTime(BASE_ATTACK);
                    float mwbMin = 0.f;
                    float mwbMax = 0.f;
                    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
                    {
                        mwbMin += caster->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE, i);
                        mwbMax += caster->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE, i);
                    }

                    float mwb = ((mwbMin + mwbMax) / 2 + ap * mws / 14000) * 0.2f;
                    amount += int32(caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), mwb));

                    // "If used while your target is above 75% health, Rend does 35% more damage."
                    // as for 3.1.3 only ranks above 9 (wrong tooltip?)
                    if (GetSpellInfo()->GetRank() >= 9)
                    {
                        if (GetUnitOwner()->HasAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT, GetSpellInfo(), caster))
                            AddPct(amount, GetSpellInfo()->Effects[EFFECT_2].CalcValue(caster));
                    }
                }
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warr_rend_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_rend_AuraScript();
        }
};

// 20230 - Retaliation
class spell_warr_retaliation : public SpellScriptLoader
{
    public:
        spell_warr_retaliation() : SpellScriptLoader("spell_warr_retaliation") { }

        class spell_warr_retaliation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_retaliation_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_RETALIATION_DAMAGE });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // check attack comes not from behind and warrior is not stunned
                return GetTarget()->isInFront(eventInfo.GetActor(), float(M_PI)) && !GetTarget()->HasUnitState(UNIT_STATE_STUNNED);
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARRIOR_RETALIATION_DAMAGE, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_retaliation_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_retaliation_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_retaliation_AuraScript();
        }
};

// -29834 - Second Wind
class spell_warr_second_wind : public SpellScriptLoader
{
    public:
        spell_warr_second_wind() : SpellScriptLoader("spell_warr_second_wind") { }

        class spell_warr_second_wind_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_second_wind_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARRIOR_SECOND_WIND_TRIGGER_1,
                    SPELL_WARRIOR_SECOND_WIND_TRIGGER_2
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return false;

                return (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_STUN))) != 0;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                static uint32 const triggeredSpells[2] = { SPELL_WARRIOR_SECOND_WIND_TRIGGER_1, SPELL_WARRIOR_SECOND_WIND_TRIGGER_2 };

                PreventDefaultAction();
                Unit* caster = eventInfo.GetActionTarget();
                uint32 spellId = triggeredSpells[GetSpellInfo()->GetRank() - 1];
                caster->CastSpell(caster, spellId, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_second_wind_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_second_wind_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_second_wind_AuraScript();
        }
};

// 64380, 65941 - Shattering Throw
class spell_warr_shattering_throw : public SpellScriptLoader
{
    public:
        spell_warr_shattering_throw() : SpellScriptLoader("spell_warr_shattering_throw") { }

        class spell_warr_shattering_throw_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_shattering_throw_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                // remove shields, will still display immune to damage part
                if (Unit* target = GetHitUnit())
                    target->RemoveAurasWithMechanic(1 << MECHANIC_IMMUNE_SHIELD, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_shattering_throw_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_shattering_throw_SpellScript();
        }
};

// -1464 - Slam
class spell_warr_slam : public SpellScriptLoader
{
    public:
        spell_warr_slam() : SpellScriptLoader("spell_warr_slam") { }

        class spell_warr_slam_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_slam_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_SLAM });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(GetEffectValue());
                GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_SLAM, args);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_slam_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_slam_SpellScript();
        }
};

// 12328, 18765, 35429 - Sweeping Strikes
class spell_warr_sweeping_strikes : public SpellScriptLoader
{
    public:
        spell_warr_sweeping_strikes() : SpellScriptLoader("spell_warr_sweeping_strikes") { }

        class spell_warr_sweeping_strikes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_sweeping_strikes_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2 });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                _procTarget = eventInfo.GetActor()->SelectNearbyTarget(eventInfo.GetProcTarget());
                return _procTarget != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                {
                    SpellInfo const* spellInfo = damageInfo->GetSpellInfo();
                    if (spellInfo && (spellInfo->Id == SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND || (spellInfo->Id == SPELL_WARRIOR_EXECUTE && !_procTarget->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))))
                    {
                        // If triggered by Execute (while target is not under 20% hp) or Bladestorm deals normalized weapon damage
                        GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2, aurEff);
                    }
                    else
                    {
                        CastSpellExtraArgs args(aurEff);
                        args.AddSpellBP0(damageInfo->GetDamage());
                        GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1, args);
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_sweeping_strikes_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_sweeping_strikes_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

            Unit* _procTarget = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_sweeping_strikes_AuraScript();
        }
};

// -46951 - Sword and Board
class spell_warr_sword_and_board : public SpellScriptLoader
{
    public:
        spell_warr_sword_and_board() : SpellScriptLoader("spell_warr_sword_and_board") { }

        class spell_warr_sword_and_board_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_sword_and_board_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                // Remove cooldown on Shield Slam
                GetTarget()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
                    return spellInfo && spellInfo->GetCategory() == SPELL_CATEGORY_SHIELD_SLAM;
                }, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_sword_and_board_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_sword_and_board_AuraScript();
        }
};

// 28845 - Cheat Death
class spell_warr_t3_prot_8p_bonus : public SpellScriptLoader
{
    public:
        spell_warr_t3_prot_8p_bonus() : SpellScriptLoader("spell_warr_t3_prot_8p_bonus") { }

        class spell_warr_t3_prot_8p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_t3_prot_8p_bonus_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActionTarget()->HealthBelowPct(20))
                    return true;

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (damageInfo && damageInfo->GetDamage())
                    if (GetTarget()->HealthBelowPctDamaged(20, damageInfo->GetDamage()))
                        return true;

                return false;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_t3_prot_8p_bonus_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_t3_prot_8p_bonus_AuraScript();
        }
};

// 50720 - Vigilance
class spell_warr_vigilance : public SpellScriptLoader
{
    public:
        spell_warr_vigilance() : SpellScriptLoader("spell_warr_vigilance") { }

        class spell_warr_vigilance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_vigilance_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARRIOR_GLYPH_OF_VIGILANCE,
                    SPELL_WARRIOR_VIGILANCE_PROC,
                    SPELL_WARRIOR_VIGILANCE_REDIRECT_THREAT,
                    SPELL_GEN_DAMAGE_REDUCTION_AURA
                });
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->CastSpell(target, SPELL_GEN_DAMAGE_REDUCTION_AURA, true);

                if (Unit* caster = GetCaster())
                    target->CastSpell(caster, SPELL_WARRIOR_VIGILANCE_REDIRECT_THREAT, true);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target->HasAura(SPELL_GEN_DAMAGE_REDUCTION_AURA) &&
                    !(target->HasAura(SPELL_PALADIN_BLESSING_OF_SANCTUARY) ||
                    target->HasAura(SPELL_PALADIN_GREATER_BLESSING_OF_SANCTUARY) ||
                    target->HasAura(SPELL_PRIEST_RENEWED_HOPE)))
                {
                    target->RemoveAurasDueToSpell(SPELL_GEN_DAMAGE_REDUCTION_AURA);
                }

                target->GetThreatManager().UnregisterRedirectThreat(SPELL_WARRIOR_VIGILANCE_REDIRECT_THREAT, GetCasterGUID());
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _procTarget = GetCaster();
                return _procTarget != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_VIGILANCE_PROC, aurEff);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_warr_vigilance_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectRemove += AuraEffectRemoveFn(spell_warr_vigilance_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                DoCheckProc += AuraCheckProcFn(spell_warr_vigilance_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_vigilance_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }

            Unit* _procTarget = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_vigilance_AuraScript();
        }
};

// 59665 - Vigilance (Redirect Threat)
class spell_warr_vigilance_redirect_threat : public SpellScriptLoader
{
    public:
        spell_warr_vigilance_redirect_threat() : SpellScriptLoader("spell_warr_vigilance_redirect_threat") { }

        class spell_warr_vigilance_redirect_threat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_vigilance_redirect_threat_SpellScript);

            void CheckGlyph(SpellEffIndex /*effIndex*/)
            {
                if (Unit* warrior = GetHitUnit())
                    if (AuraEffect const* glyph = warrior->GetAuraEffect(SPELL_WARRIOR_GLYPH_OF_VIGILANCE, EFFECT_0))
                        SetEffectValue(GetEffectValue() + glyph->GetAmount());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_vigilance_redirect_threat_SpellScript::CheckGlyph, EFFECT_0, SPELL_EFFECT_REDIRECT_THREAT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_vigilance_redirect_threat_SpellScript();
        }
};

// 50725 - Vigilance (Reset Taunt Cooldown)
class spell_warr_vigilance_trigger : public SpellScriptLoader
{
    public:
        spell_warr_vigilance_trigger() : SpellScriptLoader("spell_warr_vigilance_trigger") { }

        class spell_warr_vigilance_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_vigilance_trigger_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                // Remove Taunt cooldown
                if (Player* target = GetHitPlayer())
                    target->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_TAUNT, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_vigilance_trigger_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_vigilance_trigger_SpellScript();
        }
};

void AddSC_warrior_spell_scripts()
{
    new spell_warr_bloodthirst();
    new spell_warr_bloodthirst_heal();
    new spell_warr_charge();
    new spell_warr_concussion_blow();
    new spell_warr_damage_shield();
    new spell_warr_deep_wounds();
    new spell_warr_deep_wounds_aura();
    new spell_warr_execute();
    new spell_warr_extra_proc();
    new spell_warr_glyph_of_blocking();
    new spell_warr_glyph_of_sunder_armor();
    new spell_warr_improved_spell_reflection();
    new spell_warr_intimidating_shout();
    new spell_warr_item_t10_prot_4p_bonus();
    new spell_warr_last_stand();
    new spell_warr_overpower();
    new spell_warr_rend();
    new spell_warr_retaliation();
    new spell_warr_second_wind();
    new spell_warr_shattering_throw();
    new spell_warr_slam();
    new spell_warr_sweeping_strikes();
    new spell_warr_sword_and_board();
    new spell_warr_t3_prot_8p_bonus();
    new spell_warr_vigilance();
    new spell_warr_vigilance_redirect_threat();
    new spell_warr_vigilance_trigger();
}
