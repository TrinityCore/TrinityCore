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
 * Scripts for spells with SPELLFAMILY_WARRIOR and SPELLFAMILY_GENERIC spells used by warrior players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warr_".
 */

#include "ScriptMgr.h"
#include "Map.h"
#include "MoveSpline.h"
#include "PathGenerator.h"
#include "Player.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellScript.h"

enum WarriorSpells
{
    SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND     = 50622,
    SPELL_WARRIOR_BLOODTHIRST_HEAL                  = 117313,
    SPELL_WARRIOR_CHARGE                            = 34846,
    SPELL_WARRIOR_CHARGE_EFFECT                     = 218104,
    SPELL_WARRIOR_CHARGE_EFFECT_BLAZING_TRAIL       = 198337,
    SPELL_WARRIOR_CHARGE_PAUSE_RAGE_DECAY           = 109128,
    SPELL_WARRIOR_CHARGE_ROOT_EFFECT                = 105771,
    SPELL_WARRIOR_CHARGE_SLOW_EFFECT                = 236027,
    SPELL_WARRIOR_COLOSSUS_SMASH                    = 167105,
    SPELL_WARRIOR_COLOSSUS_SMASH_EFFECT             = 208086,
    SPELL_WARRIOR_EXECUTE                           = 20647,
    SPELL_WARRIOR_GLYPH_OF_THE_BLAZING_TRAIL        = 123779,
    SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP              = 159708,
    SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP_BUFF         = 133278,
    SPELL_WARRIOR_HEROIC_LEAP_JUMP                  = 178368,
    SPELL_WARRIOR_IMPENDING_VICTORY                 = 202168,
    SPELL_WARRIOR_IMPENDING_VICTORY_HEAL            = 202166,
    SPELL_WARRIOR_IMPROVED_HEROIC_LEAP              = 157449,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_BUFF        = 65156,
    SPELL_WARRIOR_JUGGERNAUT_CRIT_BONUS_TALENT      = 64976,
    SPELL_WARRIOR_LAST_STAND_TRIGGERED              = 12976,
    SPELL_WARRIOR_MORTAL_STRIKE                     = 12294,
    SPELL_WARRIOR_MORTAL_WOUNDS                     = 213667,
    SPELL_WARRIOR_RALLYING_CRY                      = 97463,
    SPELL_WARRIOR_REND                              = 94009,
    SPELL_WARRIOR_RETALIATION_DAMAGE                = 22858,
    SPELL_WARRIOR_SECOUND_WIND_PROC_RANK_1          = 29834,
    SPELL_WARRIOR_SECOUND_WIND_PROC_RANK_2          = 29838,
    SPELL_WARRIOR_SECOUND_WIND_TRIGGER_RANK_1       = 29841,
    SPELL_WARRIOR_SECOUND_WIND_TRIGGER_RANK_2       = 29842,
    SPELL_WARRIOR_SHIELD_SLAM                       = 23922,
    SPELL_WARRIOR_SHOCKWAVE                         = 46968,
    SPELL_WARRIOR_SHOCKWAVE_STUN                    = 132168,
    SPELL_WARRIOR_SLAM                              = 50782,
    SPELL_WARRIOR_STOICISM                          = 70845,
    SPELL_WARRIOR_STORM_BOLT_STUN                   = 132169,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1   = 12723,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2   = 26654,
    SPELL_WARRIOR_TAUNT                             = 355,
    SPELL_WARRIOR_TRAUMA_EFFECT                     = 215537,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_1        = 46859,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_RANK_2        = 46860,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_1     = 64849,
    SPELL_WARRIOR_UNRELENTING_ASSAULT_TRIGGER_2     = 64850,
    SPELL_WARRIOR_VENGEANCE                         = 76691,
    SPELL_WARRIOR_VICTORIOUS                        = 32216,
    SPELL_WARRIOR_VICTORY_RUSH_HEAL                 = 118779,
};

enum WarriorMisc
{
    SPELL_VISUAL_BLAZING_CHARGE = 26423
};

// 23881 - Bloodthirst
class spell_warr_bloodthirst : public SpellScriptLoader
{
public:
    spell_warr_bloodthirst() : SpellScriptLoader("spell_warr_bloodthirst") { }

    class spell_warr_bloodthirst_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warr_bloodthirst_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_WARRIOR_BLOODTHIRST_HEAL
            });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_BLOODTHIRST_HEAL, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_warr_bloodthirst_SpellScript::HandleDummy, EFFECT_3, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warr_bloodthirst_SpellScript();
    }
};

// 100 - Charge
class spell_warr_charge : public SpellScriptLoader
{
    public:
        spell_warr_charge() : SpellScriptLoader("spell_warr_charge") { }

        class spell_warr_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_charge_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo
                ({
                    SPELL_WARRIOR_CHARGE_EFFECT,
                    SPELL_WARRIOR_CHARGE_EFFECT_BLAZING_TRAIL
                });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = SPELL_WARRIOR_CHARGE_EFFECT;
                if (GetCaster()->HasAura(SPELL_WARRIOR_GLYPH_OF_THE_BLAZING_TRAIL))
                    spellId = SPELL_WARRIOR_CHARGE_EFFECT_BLAZING_TRAIL;

                GetCaster()->CastSpell(GetHitUnit(), spellId, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_charge_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_charge_SpellScript();
        }
};

// 126661 - Warrior Charge Drop Fire Periodic
class spell_warr_charge_drop_fire_periodic : public SpellScriptLoader
{
    public:
        spell_warr_charge_drop_fire_periodic() : SpellScriptLoader("spell_warr_charge_drop_fire_periodic") { }

        class spell_warr_charge_drop_fire_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warr_charge_drop_fire_periodic_AuraScript);

            void DropFireVisual(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                if (GetTarget()->IsSplineEnabled())
                {
                    for (uint32 i = 0; i < 5; ++i)
                    {
                        int32 timeOffset = 6 * i * aurEff->GetPeriod() / 25;
                        Movement::Location loc = GetTarget()->movespline->ComputePosition(timeOffset);
                        GetTarget()->SendPlaySpellVisual(Position(loc.x, loc.y, loc.z), 0.f, SPELL_VISUAL_BLAZING_CHARGE, 0, 0, 1.f, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_charge_drop_fire_periodic_AuraScript::DropFireVisual, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_charge_drop_fire_periodic_AuraScript();
        }
};

// 198337 - Charge Effect (dropping Blazing Trail)
// 218104 - Charge Effect
class spell_warr_charge_effect : public SpellScriptLoader
{
    public:
        spell_warr_charge_effect() : SpellScriptLoader("spell_warr_charge_effect") { }

        class spell_warr_charge_effect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_charge_effect_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo
                ({
                    SPELL_WARRIOR_CHARGE_PAUSE_RAGE_DECAY,
                    SPELL_WARRIOR_CHARGE_ROOT_EFFECT,
                    SPELL_WARRIOR_CHARGE_SLOW_EFFECT
                });
            }

            void HandleCharge(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                caster->CastCustomSpell(SPELL_WARRIOR_CHARGE_PAUSE_RAGE_DECAY, SPELLVALUE_BASE_POINT0, 0, caster, true);
                caster->CastSpell(target, SPELL_WARRIOR_CHARGE_ROOT_EFFECT, true);
                caster->CastSpell(target, SPELL_WARRIOR_CHARGE_SLOW_EFFECT, true);
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_warr_charge_effect_SpellScript::HandleCharge, EFFECT_0, SPELL_EFFECT_CHARGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_charge_effect_SpellScript();
        }
};

// 167105 - Colossus Smash 7.1.5
class spell_warr_colossus_smash : public SpellScriptLoader
{
    public:
        spell_warr_colossus_smash() : SpellScriptLoader("spell_warr_colossus_smash") { }

        class spell_warr_colossus_smash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_colossus_smash_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_COLOSSUS_SMASH_EFFECT });
            }

            void HandleOnHit()
            {
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_WARRIOR_COLOSSUS_SMASH_EFFECT, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_warr_colossus_smash_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_colossus_smash_SpellScript();
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

// 5308 - Execute
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
                /*Unit* caster = GetCaster();
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
                }*/
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

// Heroic leap - 6544
class spell_warr_heroic_leap : public SpellScriptLoader
{
public:
    spell_warr_heroic_leap() : SpellScriptLoader("spell_warr_heroic_leap") { }

    class spell_warr_heroic_leap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warr_heroic_leap_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_WARRIOR_HEROIC_LEAP_JUMP });
        }

        SpellCastResult CheckElevation()
        {
            if (WorldLocation const* dest = GetExplTargetDest())
            {
                if (GetCaster()->HasUnitMovementFlag(MOVEMENTFLAG_ROOT))
                    return SPELL_FAILED_ROOTED;

                if (GetCaster()->GetMap()->Instanceable())
                {
                    float range = GetSpellInfo()->GetMaxRange(true, GetCaster()) * 1.5f;

                    PathGenerator generatedPath(GetCaster());
                    generatedPath.SetPathLengthLimit(range);

                    bool result = generatedPath.CalculatePath(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), false, true);
                    if (generatedPath.GetPathType() & PATHFIND_SHORT)
                        return SPELL_FAILED_OUT_OF_RANGE;
                    else if (!result || generatedPath.GetPathType() & PATHFIND_NOPATH)
                    {
                        result = generatedPath.CalculatePath(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), false, false);
                        if (generatedPath.GetPathType() & PATHFIND_SHORT)
                            return SPELL_FAILED_OUT_OF_RANGE;
                        else if (!result || generatedPath.GetPathType() & PATHFIND_NOPATH)
                            return SPELL_FAILED_NOPATH;
                    }
                }
                else if (dest->GetPositionZ() > GetCaster()->GetPositionZ() + 4.0f)
                    return SPELL_FAILED_NOPATH;

                return SPELL_CAST_OK;
            }

            return SPELL_FAILED_NO_VALID_TARGETS;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (WorldLocation* dest = GetHitDest())
                GetCaster()->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_WARRIOR_HEROIC_LEAP_JUMP, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warr_heroic_leap_SpellScript::CheckElevation);
            OnEffectHit += SpellEffectFn(spell_warr_heroic_leap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warr_heroic_leap_SpellScript();
    }
};

// Heroic Leap (triggered by Heroic Leap (6544)) - 178368
class spell_warr_heroic_leap_jump : public SpellScriptLoader
{
public:
    spell_warr_heroic_leap_jump() : SpellScriptLoader("spell_warr_heroic_leap_jump") { }

    class spell_warr_heroic_leap_jump_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warr_heroic_leap_jump_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP,
                SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP_BUFF,
                SPELL_WARRIOR_IMPROVED_HEROIC_LEAP,
                SPELL_WARRIOR_TAUNT
            });
        }

        void AfterJump(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster()->HasAura(SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP))
                GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP_BUFF, true);
            if (GetCaster()->HasAura(SPELL_WARRIOR_IMPROVED_HEROIC_LEAP))
                GetCaster()->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_TAUNT, true);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_warr_heroic_leap_jump_SpellScript::AfterJump, EFFECT_1, SPELL_EFFECT_JUMP_DEST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warr_heroic_leap_jump_SpellScript();
    }
};

// 202168 - Impending Victory
class spell_warr_impending_victory : public SpellScriptLoader
{
    public:
        spell_warr_impending_victory() : SpellScriptLoader("spell_warr_impending_victory") { }

        class spell_warr_impending_victory_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_impending_victory_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_IMPENDING_VICTORY_HEAL });
            }

            void HandleAfterCast()
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster, SPELL_WARRIOR_IMPENDING_VICTORY_HEAL, true);
                caster->RemoveAurasDueToSpell(SPELL_WARRIOR_VICTORIOUS);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_warr_impending_victory_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_impending_victory_SpellScript();
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
/// 7.1.5
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
                int32 bp0 = CalculatePct(target->GetMaxHealth(), GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue());
                target->CastCustomSpell(SPELL_WARRIOR_STOICISM, SPELLVALUE_BASE_POINT0, bp0, nullptr, true);
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

// 12294 - Mortal Strike 7.1.5
class spell_warr_mortal_strike : public SpellScriptLoader
{
    public:
        spell_warr_mortal_strike() : SpellScriptLoader("spell_warr_mortal_strike") { }

        class spell_warr_mortal_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warr_mortal_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_MORTAL_WOUNDS });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_WARRIOR_MORTAL_WOUNDS, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warr_mortal_strike_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warr_mortal_strike_SpellScript();
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
                    int32 mws = caster->GetBaseAttackTime(BASE_ATTACK);
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
                    SPELL_WARRIOR_SECOUND_WIND_PROC_RANK_1,
                    SPELL_WARRIOR_SECOUND_WIND_PROC_RANK_2,
                    SPELL_WARRIOR_SECOUND_WIND_TRIGGER_RANK_1,
                    SPELL_WARRIOR_SECOUND_WIND_TRIGGER_RANK_2
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

                if (GetSpellInfo()->Id == SPELL_WARRIOR_SECOUND_WIND_PROC_RANK_1)
                    spellId = SPELL_WARRIOR_SECOUND_WIND_TRIGGER_RANK_1;
                else if (GetSpellInfo()->Id == SPELL_WARRIOR_SECOUND_WIND_PROC_RANK_2)
                    spellId = SPELL_WARRIOR_SECOUND_WIND_TRIGGER_RANK_2;
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

// 46968 - Shockwave
class spell_warr_shockwave : public SpellScriptLoader
{
public:
    spell_warr_shockwave() : SpellScriptLoader("spell_warr_shockwave") { }

    class spell_warr_shockwave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warr_shockwave_SpellScript);

        bool Validate(SpellInfo const* spellInfo) override
        {
            if (!ValidateSpellInfo({ SPELL_WARRIOR_SHOCKWAVE, SPELL_WARRIOR_SHOCKWAVE_STUN }))
                return false;

            return spellInfo->GetEffect(EFFECT_0) && spellInfo->GetEffect(EFFECT_3);
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void HandleStun(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_SHOCKWAVE_STUN, true);
            ++_targetCount;
        }

        // Cooldown reduced by 20 sec if it strikes at least 3 targets.
        void HandleAfterCast()
        {
            if (_targetCount >= uint32(GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue()))
                GetCaster()->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, -(GetSpellInfo()->GetEffect(EFFECT_3)->CalcValue() * IN_MILLISECONDS));
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warr_shockwave_SpellScript::HandleStun, EFFECT_0, SPELL_EFFECT_DUMMY);
            AfterCast += SpellCastFn(spell_warr_shockwave_SpellScript::HandleAfterCast);
        }

        uint32 _targetCount = 0;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warr_shockwave_SpellScript();
    }
};

// 107570 - Storm Bolt
class spell_warr_storm_bolt : public SpellScriptLoader
{
public:
    spell_warr_storm_bolt() : SpellScriptLoader("spell_warr_storm_bolt") { }

    class spell_warr_storm_bolt_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warr_storm_bolt_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_WARRIOR_STORM_BOLT_STUN
            });
        }

        void HandleOnHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_STORM_BOLT_STUN, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warr_storm_bolt_SpellScript::HandleOnHit, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warr_storm_bolt_SpellScript();
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
                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                {
                    SpellInfo const* spellInfo = damageInfo->GetSpellInfo();
                    if (spellInfo && (spellInfo->Id == SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND || (spellInfo->Id == SPELL_WARRIOR_EXECUTE && !_procTarget->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))))
                    {
                        // If triggered by Execute (while target is not under 20% hp) or Bladestorm deals normalized weapon damage
                        GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2, true, nullptr, aurEff);
                    }
                    else
                    {
                        int32 damage = damageInfo->GetDamage();
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

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_SLAM });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                // Remove cooldown on Shield Slam
                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_SHIELD_SLAM, true);
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

// 215538 - Trauma
class spell_warr_trauma : public SpellScriptLoader
{
public:
    spell_warr_trauma() : SpellScriptLoader("spell_warr_trauma") { }

    class spell_warr_trauma_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warr_trauma_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_WARRIOR_TRAUMA_EFFECT });
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActionTarget();
            //Get the Remaining Damage from the aura (if exist)
            int32 remainingDamage = target->GetRemainingPeriodicAmount(target->GetGUID(), SPELL_WARRIOR_TRAUMA_EFFECT, SPELL_AURA_PERIODIC_DAMAGE);
            //Get 25% of damage from the spell casted (Slam & Whirlwind) plus Remaining Damage from Aura
            int32 damage = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()) / sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_TRAUMA_EFFECT, GetCastDifficulty())->GetMaxTicks()) + remainingDamage;
            GetCaster()->CastCustomSpell(SPELL_WARRIOR_TRAUMA_EFFECT, SPELLVALUE_BASE_POINT0, damage, target, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_warr_trauma_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warr_trauma_AuraScript();
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

// 32215 - Victorious State
class spell_warr_victorious_state : public SpellScriptLoader
{
    public:
        spell_warr_victorious_state() : SpellScriptLoader("spell_warr_victorious_state") { }

        class spell_warr_victorious_state_Aurascript : public AuraScript
        {
            PrepareAuraScript(spell_warr_victorious_state_Aurascript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARRIOR_IMPENDING_VICTORY });
            }

            void HandleOnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
            {
                if (procInfo.GetActor()->GetTypeId() == TYPEID_PLAYER && procInfo.GetActor()->ToPlayer()->GetPrimarySpecialization() == TALENT_SPEC_WARRIOR_FURY)
                    PreventDefaultAction();

                procInfo.GetActor()->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_IMPENDING_VICTORY, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warr_victorious_state_Aurascript::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_victorious_state_Aurascript();
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
                return ValidateSpellInfo
                ({
                    SPELL_WARRIOR_VICTORIOUS,
                    SPELL_WARRIOR_VICTORY_RUSH_HEAL
                });
            }

            void HandleHeal()
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster, SPELL_WARRIOR_VICTORY_RUSH_HEAL, true);
                caster->RemoveAurasDueToSpell(SPELL_WARRIOR_VICTORIOUS);
            }

            void Register() override
            {
                AfterCast += SpellCastFn(spell_warr_victory_rush_SpellScript::HandleHeal);
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

            bool Load() override
            {
                _procTarget = nullptr;
                return true;
            }

            /*
            bool CheckProc(ProcEventInfo& eventInfo)
            {
                _procTarget = GetCaster();
                return _procTarget && eventInfo.GetDamageInfo();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 damage = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue()));

                GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_VIGILANCE_PROC, true, nullptr, aurEff);
                _procTarget->CastCustomSpell(_procTarget, SPELL_WARRIOR_VENGEANCE, &damage, &damage, &damage, true, nullptr, aurEff);
            }
            */

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
                //DoCheckProc += AuraCheckProcFn(spell_warr_vigilance_AuraScript::CheckProc);
                //OnEffectProc += AuraEffectProcFn(spell_warr_vigilance_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
                OnEffectRemove += AuraEffectRemoveFn(spell_warr_vigilance_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }

            Unit* _procTarget = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warr_vigilance_AuraScript();
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
    new spell_warr_charge();
    new spell_warr_charge_drop_fire_periodic();
    new spell_warr_charge_effect();
    new spell_warr_colossus_smash();
    new spell_warr_concussion_blow();
    new spell_warr_execute();
    new spell_warr_heroic_leap();
    new spell_warr_heroic_leap_jump();
    new spell_warr_impending_victory();
    new spell_warr_intimidating_shout();
    new spell_warr_item_t10_prot_4p_bonus();
    new spell_warr_lambs_to_the_slaughter();
    new spell_warr_last_stand();
    new spell_warr_mortal_strike();
    new spell_warr_overpower();
    new spell_warr_rallying_cry();
    new spell_warr_rend();
    new spell_warr_retaliation();
    new spell_warr_second_wind_proc();
    new spell_warr_second_wind_trigger();
    new spell_warr_shattering_throw();
    new spell_warr_shockwave();
    new spell_warr_slam();
    new spell_warr_storm_bolt();
    new spell_warr_sudden_death();
    new spell_warr_sweeping_strikes();
    new spell_warr_sword_and_board();
    new spell_warr_trauma();
    new spell_warr_t3_prot_8p_bonus();
    new spell_warr_victorious_state();
    new spell_warr_victory_rush();
    new spell_warr_vigilance();
    new spell_warr_vigilance_trigger();
}
