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
 * Scripts for spells with SPELLFAMILY_WARRIOR and SPELLFAMILY_GENERIC spells used by warrior players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warr_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "Item.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "GridNotifiersImpl.h"

enum WarriorSpells
{
    SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND     = 50622,
    SPELL_WARRIOR_BLITZ_RANK_1                      = 80976,
    SPELL_WARRIOR_BLITZ_RANK_2                      = 80977,
    SPELL_WARRIOR_BLOODTHIRST                       = 23885,
    SPELL_WARRIOR_BLOODTHIRST_DAMAGE                = 23881,
    SPELL_WARRIOR_CHARGE                            = 34846,
    SPELL_WARRIOR_CHARGE_STUN                       = 7922,
    SPELL_WARRIOR_COLOSSUS_SMASH                    = 86346,
    SPELL_WARRIOR_DEEP_WOUNDS_RANK_1                = 12834,
    SPELL_WARRIOR_DEEP_WOUNDS_RANK_2                = 12849,
    SPELL_WARRIOR_DEEP_WOUNDS_RANK_3                = 12867,
    SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC              = 12721,
    SPELL_WARRIOR_EXECUTE                           = 20647,
    SPELL_WARRIOR_GLYPH_OF_EXECUTION                = 58367,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF        = 65156,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT      = 64976,
    SPELL_WARRIOR_LAST_STAND_TRIGGERED              = 12976,
    SPELL_WARRIOR_MORTAL_STRIKE                     = 12294,
    SPELL_WARRIOR_OPPORTUNITY_STRIKE                = 76858,
    SPELL_WARRIOR_RALLYING_CRY                      = 97463,
    SPELL_WARRIOR_REND                              = 94009,
    SPELL_WARRIOR_RETALIATION_DAMAGE                = 22858,
    SPELL_WARRIOR_SECOND_WIND_PROC_RANK_1           = 29834,
    SPELL_WARRIOR_SECOND_WIND_PROC_RANK_2           = 29838,
    SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_1        = 29841,
    SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_2        = 29842,
    SPELL_WARRIOR_SHIELD_SLAM                       = 23922,
    SPELL_WARRIOR_SLAM                              = 50782,
    SPELL_WARRIOR_SUNDER_ARMOR                      = 58567,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1   = 12723,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2   = 26654,
    SPELL_WARRIOR_TAUNT                             = 355,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_1        = 46859,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_2        = 46860,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_1     = 64849,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_2     = 64850,
    SPELL_WARRIOR_VICTORIOUS                        = 32216,
    SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY      = 82368,
    SPELL_WARRIOR_VIGILANCE_PROC                    = 50725,
    SPELL_WARRIOR_VENGEANCE                         = 76691
};

enum WarriorSpellIcons
{
    WARRIOR_ICON_ID_SUDDEN_DEATH                    = 1989,
    WARRIOR_ICON_ID_BLOOD_AND_THUNDER               = 5057
};


enum MiscSpells
{
    SPELL_PALADIN_BLESSING_OF_SANCTUARY             = 20911,
    SPELL_PALADIN_GREATER_BLESSING_OF_SANCTUARY     = 25899,
    SPELL_PRIEST_RENEWED_HOPE                       = 63944
};

/// Updated 4.3.4
class spell_warr_bloodthirst : public SpellScriptLoader
{
    public:
        spell_warr_bloodthirst() : SpellScriptLoader("spell_warr_bloodthirst") { }

        class spell_warr_bloodthirst_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_bloodthirst_SpellScript);

            void HandleDamage(SpellEffIndex effIndex)
            {
                int32 damage = GetEffectValue();
                ApplyPct(damage, GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK));

                if (Unit* target = GetHitUnit())
                {
                    damage = GetCaster()->SpellDamageBonusDone(target, GetSpellInfo(), uint32(damage), SPELL_DIRECT_DAMAGE, effIndex);
                    damage = target->SpellDamageBonusTaken(GetCaster(), GetSpellInfo(), uint32(damage), SPELL_DIRECT_DAMAGE);
                }
                SetHitDamage(damage);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                GetCaster()->CastCustomSpell(GetCaster(), SPELL_WARRIOR_BLOODTHIRST, &damage, nullptr, nullptr, true, nullptr);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_bloodthirst_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHit += SpellEffectFn(spell_warr_bloodthirst_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_bloodthirst_SpellScript();
        }
};

/// Updated 4.3.4
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
                SetHitHeal(GetCaster()->CountPctFromMaxHealth(spellInfo->Effects[EFFECT_1].CalcValue(GetCaster())) / 100);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_bloodthirst_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_bloodthirst_heal_SpellScript();
        }
};

/// Updated 4.3.4
class spell_warr_charge : public SpellScriptLoader
{
    public:
        spell_warr_charge() : SpellScriptLoader("spell_warr_charge") { }

        class spell_warr_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_charge_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_WARRIOR_BLITZ_RANK_1,
                        SPELL_WARRIOR_BLITZ_RANK_2,
                        SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT,
                        SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF,
                        SPELL_WARRIOR_CHARGE,
                    });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 chargeBasePoints0 = GetEffectValue();
                Unit* caster = GetCaster();
                caster->CastCustomSpell(caster, SPELL_WARRIOR_CHARGE, &chargeBasePoints0, nullptr, nullptr, true);

                // Juggernaut crit bonus
                if (caster->HasAura(SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT))
                    caster->CastSpell(caster, SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF, true);

                if ((!caster->HasAura(SPELL_WARRIOR_BLITZ_RANK_1) && !caster->HasAura(SPELL_WARRIOR_BLITZ_RANK_2)))
                    return;

                if (Unit* target = GetExplTargetUnit())
                {
                    std::list<Unit*> targets;
                    Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(target, target, 5.0f);
                    Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(target, targets, u_check);
                    Cell::VisitAllObjects(target, searcher, 5.0f);

                    targets.remove(target);

                    for (std::list<Unit*>::iterator tIter = targets.begin(); tIter != targets.end();)
                    {
                        if (!target->IsWithinLOSInMap(*tIter) || (*tIter)->IsTotem() || (*tIter)->IsSpiritService() || (*tIter)->IsCritter())
                            targets.erase(tIter++);
                        else
                            ++tIter;
                    }

                    if (!targets.empty())
                        if (Unit* blitzTarget = Trinity::Containers::SelectRandomContainerElement(targets))
                            caster->CastSpell(blitzTarget, SPELL_WARRIOR_CHARGE_STUN, true);
                }
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

/// Updated 4.3.4
class spell_warr_concussion_blow : public SpellScriptLoader
{
    public:
        spell_warr_concussion_blow() : SpellScriptLoader("spell_warr_concussion_blow") { }

        class spell_warr_concussion_blow_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_concussion_blow_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                SetHitDamage(CalculatePct(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetEffectValue()));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_concussion_blow_SpellScript::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_concussion_blow_SpellScript();
        }
};

// Updated 4.3.4
// -12834 - Deep Wounds
class spell_warr_deep_wounds : public SpellScriptLoader
{
    public:
        spell_warr_deep_wounds() : SpellScriptLoader("spell_warr_deep_wounds") { }

        class spell_warr_deep_wounds_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_deep_wounds_AuraScript);

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

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                if (Player* player = GetUnitOwner()->ToPlayer())
                {
                    int32 damage = 0;
                    Item* mainhandWeapon = player->GetWeaponForAttack(BASE_ATTACK);
                    Item* offhandWeapon = player->GetWeaponForAttack(OFF_ATTACK);
                    if (mainhandWeapon)
                        damage += (mainhandWeapon->GetTemplate()->DamageMin + mainhandWeapon->GetTemplate()->DamageMax) * 0.5f;
                    if (offhandWeapon)
                        damage += (mainhandWeapon->GetTemplate()->DamageMin + mainhandWeapon->GetTemplate()->DamageMax) * 0.5f;

                    damage = CalculatePct(damage, 16 * GetSpellInfo()->GetRank());

                    if (damage)
                        if (SpellInfo const* periodicSpell = sSpellMgr->GetSpellInfo(SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC))
                                if (uint32 ticks = periodicSpell->GetMaxTicks())
                                    damage = damage / ticks;

                    if (Unit* target = eventInfo.GetProcTarget())
                        player->CastCustomSpell(target, SPELL_WARRIOR_DEEP_WOUNDS_PERIODIC, &damage, 0, 0, true, nullptr, aurEff);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_deep_wounds_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_deep_wounds_AuraScript();
        }
};

/// Updated 4.3.4
class spell_warr_execute : public SpellScriptLoader
{
    public:
        spell_warr_execute() : SpellScriptLoader("spell_warr_execute") { }

        class spell_warr_execute_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_execute_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (GetHitUnit())
                {
                    SpellInfo const* spellInfo = GetSpellInfo();
                    int32 rageUsed = std::min<int32>(200 - spellInfo->CalcPowerCost(caster, SpellSchoolMask(spellInfo->SchoolMask)), caster->GetPower(POWER_RAGE));
                    int32 newRage = std::max<int32>(0, caster->GetPower(POWER_RAGE) - rageUsed);

                    // Sudden Death rage save
                    if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_GENERIC, WARRIOR_ICON_ID_SUDDEN_DEATH, EFFECT_0))
                    {
                        int32 ragesave = aurEff->GetSpellInfo()->Effects[EFFECT_0].CalcValue() * 10;
                        newRage = std::max(newRage, ragesave);
                    }

                    caster->SetPower(POWER_RAGE, uint32(newRage));

                    /// Formula taken from the DBC: "${10+$AP*0.437*$m1/100}"
                    int32 baseDamage = int32(10 + caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.437f * GetEffectValue() / 100.0f);
                    /// Formula taken from the DBC: "${$ap*0.874*$m1/100-1} = 20 rage"
                    int32 moreDamage = int32(rageUsed * (caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.874f * GetEffectValue() / 100.0f - 1) / 200);
                    SetHitDamage(baseDamage + moreDamage);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_execute_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_execute_SpellScript();
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

// -84583 Lambs to the Slaughter
class spell_warr_lambs_to_the_slaughter : public SpellScriptLoader
{
    public:
        spell_warr_lambs_to_the_slaughter() : SpellScriptLoader("spell_warr_lambs_to_the_slaughter") { }

        class spell_warr_lambs_to_the_slaughter_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_lambs_to_the_slaughter_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_MORTAL_STRIKE, SPELL_WARRIOR_REND });
            }

            void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                if (Aura* aur = eventInfo.GetProcTarget()->GetAura(SPELL_WARRIOR_REND, GetTarget()->GetGUID()))
                    aur->SetDuration(aur->GetSpellInfo()->GetMaxDuration(), true);

            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_lambs_to_the_slaughter_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_lambs_to_the_slaughter_AuraScript();
        }
};

/// Updated 4.3.4
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
                int32 healthModSpellBasePoints0 = int32(caster->CountPctFromMaxHealth(GetEffectValue()));
                caster->CastCustomSpell(caster, SPELL_WARRIOR_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, nullptr, nullptr, true, nullptr);
            }

            void Register() override
            {
                // add dummy effect spell handler to Last Stand
                OnEffectHit += SpellEffectFn(spell_warr_last_stand_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_last_stand_SpellScript();
        }
};

// 7384 - Overpower
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

// 97462 - Rallying Cry
class spell_warr_rallying_cry : public SpellScriptLoader
{
    public:
        spell_warr_rallying_cry() : SpellScriptLoader("spell_warr_rallying_cry") { }

        class spell_warr_rallying_cry_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_rallying_cry_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_RALLYING_CRY });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() ==  TYPEID_PLAYER;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                int32 basePoints0 = int32(GetHitUnit()->CountPctFromMaxHealth(GetEffectValue()));

                GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_WARRIOR_RALLYING_CRY, &basePoints0, nullptr, nullptr, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_rallying_cry_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_rallying_cry_SpellScript();
        }
};

// 94009 - Rend
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

                    // $0.25 * (($MWB + $mwb) / 2 + $AP / 14 * $MWS) bonus per tick
                    float ap = caster->GetTotalAttackPowerValue(BASE_ATTACK);
                    int32 mws = caster->GetAttackTime(BASE_ATTACK);
                    float mwbMin = caster->GetWeaponDamageRange(BASE_ATTACK, MINDAMAGE);
                    float mwbMax = caster->GetWeaponDamageRange(BASE_ATTACK, MAXDAMAGE);
                    float mwb = ((mwbMin + mwbMax) / 2 + ap * mws / 14000) * 0.25f;
                    amount += int32(caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), mwb));
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
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARRIOR_RETALIATION_DAMAGE, true, nullptr, aurEff);
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

/// Updated 4.3.4
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
                if (GetHitUnit())
                    GetCaster()->CastCustomSpell(SPELL_WARRIOR_SLAM, SPELLVALUE_BASE_POINT0, GetEffectValue(), GetHitUnit(), TRIGGERED_FULL_MASK);
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

class spell_warr_second_wind_proc : public SpellScriptLoader
{
    public:
        spell_warr_second_wind_proc() : SpellScriptLoader("spell_warr_second_wind_proc") { }

        class spell_warr_second_wind_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_second_wind_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARRIOR_SECOND_WIND_PROC_RANK_1,
                    SPELL_WARRIOR_SECOND_WIND_PROC_RANK_2,
                    SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_1,
                    SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_2
                });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetProcTarget() == GetTarget())
                    return false;
                if (!eventInfo.GetDamageInfo()->GetSpellInfo() || !(eventInfo.GetDamageInfo()->GetSpellInfo()->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_STUN))))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                uint32 spellId = 0;

                if (GetSpellInfo()->Id == SPELL_WARRIOR_SECOND_WIND_PROC_RANK_1)
                    spellId = SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_1;
                else if (GetSpellInfo()->Id == SPELL_WARRIOR_SECOND_WIND_PROC_RANK_2)
                    spellId = SPELL_WARRIOR_SECOND_WIND_TRIGGER_RANK_2;
                if (!spellId)
                    return;

                GetTarget()->CastSpell(GetTarget(), spellId, true, nullptr, aurEff);

            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_second_wind_proc_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_second_wind_proc_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_second_wind_proc_AuraScript();
        }
};

class spell_warr_second_wind_trigger : public SpellScriptLoader
{
    public:
        spell_warr_second_wind_trigger() : SpellScriptLoader("spell_warr_second_wind_trigger") { }

        class spell_warr_second_wind_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_second_wind_trigger_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = int32(GetUnitOwner()->CountPctFromMaxHealth(amount));
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warr_second_wind_trigger_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_PERIODIC_HEAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_second_wind_trigger_AuraScript();
        }
};

// 52437 - Sudden Death
class spell_warr_sudden_death : public SpellScriptLoader
{
    public:
        spell_warr_sudden_death() : SpellScriptLoader("spell_warr_sudden_death") { }

        class spell_warr_sudden_death_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_sudden_death_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_COLOSSUS_SMASH });
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                // Remove cooldown on Colossus Smash
                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_COLOSSUS_SMASH, true);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectRemoveFn(spell_warr_sudden_death_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL); // correct?
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_sudden_death_AuraScript();
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
                if (eventInfo.GetDamageInfo())
                {
                    SpellInfo const* spellInfo = eventInfo.GetDamageInfo()->GetSpellInfo();
                    if (spellInfo && (spellInfo->Id == SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND || (spellInfo->Id == SPELL_WARRIOR_EXECUTE && !_procTarget->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))))
                    {
                        // If triggered by Execute (while target is not under 20% hp) or Bladestorm deals normalized weapon damage
                        GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2, true, nullptr, aurEff);
                    }
                    else
                    {
                        int32 damage = eventInfo.GetDamageInfo()->GetDamage();
                        GetTarget()->CastCustomSpell(SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1, SPELLVALUE_BASE_POINT0, damage, _procTarget, true, nullptr, aurEff);
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

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_SLAM });
            }

            void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                // Remove cooldown on Shield Slam
                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_SHIELD_SLAM, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_sword_and_board_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_sword_and_board_AuraScript();
        }
};

// 34428 - Victory Rush
class spell_warr_victory_rush : public SpellScriptLoader
{
public:
    spell_warr_victory_rush() : SpellScriptLoader("spell_warr_victory_rush") { }

    class spell_warr_victory_rush_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warr_victory_rush_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
                {
                    SPELL_WARRIOR_VICTORIOUS,
                    SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY
                });
        }

        void HandleHit(SpellEffIndex effIndex)
        {
            GetCaster()->RemoveAurasDueToSpell(SPELL_WARRIOR_VICTORIOUS);
            GetCaster()->RemoveAurasDueToSpell(SPELL_WARRIOR_VICTORIOUS_IMPENDING_VICTORY);
            SetHitDamage(CalculatePct(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK), GetEffectValue()));
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warr_victory_rush_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warr_victory_rush_SpellScript();
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
                return ValidateSpellInfo({ SPELL_WARRIOR_VENGEANCE });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                _procTarget = GetCaster();
                return _procTarget && eventInfo.GetDamageInfo();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 damage = std::min(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue()), CalculatePct(_procTarget->GetMaxHealth(), 10));

                GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_VIGILANCE_PROC, true, nullptr, aurEff);
                _procTarget->CastCustomSpell(_procTarget, SPELL_WARRIOR_VENGEANCE, &damage, &damage, &damage, true, nullptr, aurEff);
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->HasAura(SPELL_WARRIOR_VENGEANCE))
                        caster->RemoveAurasDueToSpell(SPELL_WARRIOR_VENGEANCE);
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_vigilance_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_vigilance_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                OnEffectRemove += AuraEffectRemoveFn(spell_warr_vigilance_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }

            Unit* _procTarget = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_vigilance_AuraScript();
        }
};

// 50725 Vigilance
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

// 76838 - Strikes of Opportunity
class spell_warr_strikes_of_opportunity : public SpellScriptLoader
{
    public:
        spell_warr_strikes_of_opportunity() : SpellScriptLoader("spell_warr_strikes_of_opportunity") { }

        class spell_warr_strikes_of_opportunity_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_strikes_of_opportunity_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_OPPORTUNITY_STRIKE });
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    if (Unit* target = eventInfo.GetActionTarget())
                        caster->CastSpell(target, SPELL_WARRIOR_OPPORTUNITY_STRIKE, true, nullptr, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warr_strikes_of_opportunity_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warr_strikes_of_opportunity_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_strikes_of_opportunity_AuraScript();
        }
};

class spell_warr_thunder_clap : public SpellScriptLoader
{
    public:
        spell_warr_thunder_clap() : SpellScriptLoader("spell_warr_thunder_clap") { }

        class spell_warr_thunder_clap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_thunder_clap_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_REND });
            }

            bool Load() override
            {
                allowRendSpread = false;
                if (AuraEffect* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_WARRIOR, WARRIOR_ICON_ID_BLOOD_AND_THUNDER, EFFECT_0))
                    return roll_chance_i(aurEff->GetAmount());

                return false;
            }

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                for (std::list<WorldObject*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    if (Unit* target = (*itr)->ToUnit())
                        if (target->HasAura(SPELL_WARRIOR_REND))
                            allowRendSpread = true;
            }

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                if (allowRendSpread)
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_REND, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_thunder_clap_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_warr_thunder_clap_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }

        private:
            bool allowRendSpread;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_thunder_clap_SpellScript();
        }
};

class spell_warr_shield_specialization : public AuraScript
{
    PrepareAuraScript(spell_warr_shield_specialization);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetHitMask() & PROC_HIT_REFLECT)
        {
            PreventDefaultAction();
            Unit* target = GetTarget();
            if (SpellInfo const* spell = sSpellMgr->GetSpellInfo((GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell)))
            {
                int32 bp = spell->Effects[EFFECT_0].CalcValue() * 4;
                target->CastCustomSpell(spell->Id, SPELLVALUE_BASE_POINT0, bp, nullptr, true, nullptr, aurEff);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warr_shield_specialization::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

class spell_warr_devastate : public SpellScript
{
    PrepareSpellScript(spell_warr_devastate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SUNDER_ARMOR });
    }

    void HandleBonusDamage(SpellEffIndex effIndex)
    {
        if (Aura* aura = GetHitUnit()->GetAura(SPELL_WARRIOR_SUNDER_ARMOR))
        {
            uint8 stacks = std::max(0, aura->GetStackAmount() - 1);
            int32 damage = GetSpellInfo()->Effects[effIndex].CalcValue(GetCaster(), nullptr, GetHitUnit());
            SetHitDamage(GetHitDamage() + (stacks * damage));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_devastate::HandleBonusDamage, EFFECT_1, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
    }
};

class spell_warr_blood_craze : public AuraScript
{
    PrepareAuraScript(spell_warr_blood_craze);

    void HandleCalcAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
    {
        int32 bp = GetSpellInfo()->Effects[EFFECT_0].BasePoints / 2;
        uint8 totalTicks = aurEff->GetTotalTicks();
        amount = CalculatePct(GetUnitOwner()->GetMaxHealth(), (float)bp / totalTicks);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warr_blood_craze::HandleCalcAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
    }
};

void AddSC_warrior_spell_scripts()
{
    RegisterAuraScript(spell_warr_blood_craze);
    new spell_warr_bloodthirst();
    new spell_warr_bloodthirst_heal();
    new spell_warr_charge();
    new spell_warr_concussion_blow();
    RegisterSpellScript(spell_warr_devastate);
    new spell_warr_deep_wounds();
    new spell_warr_execute();
    new spell_warr_glyph_of_sunder_armor();
    new spell_warr_intimidating_shout();
    new spell_warr_lambs_to_the_slaughter();
    new spell_warr_last_stand();
    new spell_warr_overpower();
    new spell_warr_rallying_cry();
    new spell_warr_rend();
    new spell_warr_retaliation();
    new spell_warr_second_wind_proc();
    new spell_warr_second_wind_trigger();
    new spell_warr_shattering_throw();
    RegisterAuraScript(spell_warr_shield_specialization);
    new spell_warr_slam();
    new spell_warr_strikes_of_opportunity();
    new spell_warr_sudden_death();
    new spell_warr_sweeping_strikes();
    new spell_warr_sword_and_board();
    new spell_warr_thunder_clap();
    new spell_warr_victory_rush();
    new spell_warr_vigilance();
    new spell_warr_vigilance_trigger();
}
