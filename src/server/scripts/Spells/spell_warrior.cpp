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
    SPELL_WARRIOR_MORTAL_STRIKE                     = 12294,
    SPELL_WARRIOR_MORTAL_WOUNDS                     = 213667,
    SPELL_WARRIOR_RALLYING_CRY                      = 97463,
    SPELL_WARRIOR_SHOCKWAVE                         = 46968,
    SPELL_WARRIOR_SHOCKWAVE_STUN                    = 132168,
    SPELL_WARRIOR_STOICISM                          = 70845,
    SPELL_WARRIOR_STORM_BOLT_STUN                   = 132169,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1   = 12723,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2   = 26654,
    SPELL_WARRIOR_TAUNT                             = 355,
    SPELL_WARRIOR_TRAUMA_EFFECT                     = 215537,
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
            return ValidateSpellInfo({ SPELL_WARRIOR_BLOODTHIRST_HEAL });
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
                caster->CastSpell(caster, SPELL_WARRIOR_CHARGE_PAUSE_RAGE_DECAY, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, 0));
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

// 6544 - Heroic leap
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
                GetCaster()->CastSpell(*dest, SPELL_WARRIOR_HEROIC_LEAP_JUMP, true);
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
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, int32(GetHitUnit()->CountPctFromMaxHealth(GetEffectValue())));

                GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_RALLYING_CRY, args);
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
                GetCaster()->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, Seconds(-GetSpellInfo()->GetEffect(EFFECT_3)->CalcValue()));
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

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                {
                    SpellInfo const* spellInfo = damageInfo->GetSpellInfo();
                    if (spellInfo && (spellInfo->Id == SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND || (spellInfo->Id == SPELL_WARRIOR_EXECUTE && !_procTarget->HasAuraState(AURA_STATE_WOUNDED_20_PERCENT))))
                    {
                        // If triggered by Execute (while target is not under 20% hp) or Bladestorm deals normalized weapon damage
                        GetTarget()->CastSpell(_procTarget, SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2, aurEff);
                    }
                    else
                    {
                        CastSpellExtraArgs args(aurEff);
                        args.AddSpellMod(SPELLVALUE_BASE_POINT0, damageInfo->GetDamage());
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

        void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* target = eventInfo.GetActionTarget();
            //Get the Remaining Damage from the aura (if exist)
            int32 remainingDamage = target->GetRemainingPeriodicAmount(target->GetGUID(), SPELL_WARRIOR_TRAUMA_EFFECT, SPELL_AURA_PERIODIC_DAMAGE);
            //Get 25% of damage from the spell casted (Slam & Whirlwind) plus Remaining Damage from Aura
            int32 damage = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()) / sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_TRAUMA_EFFECT, GetCastDifficulty())->GetMaxTicks()) + remainingDamage;
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
            GetCaster()->CastSpell(target, SPELL_WARRIOR_TRAUMA_EFFECT, args);
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

            void HandleOnProc(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
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

void AddSC_warrior_spell_scripts()
{
    new spell_warr_bloodthirst();
    new spell_warr_charge();
    new spell_warr_charge_drop_fire_periodic();
    new spell_warr_charge_effect();
    new spell_warr_colossus_smash();
    new spell_warr_heroic_leap();
    new spell_warr_heroic_leap_jump();
    new spell_warr_impending_victory();
    new spell_warr_intimidating_shout();
    new spell_warr_item_t10_prot_4p_bonus();
    new spell_warr_mortal_strike();
    new spell_warr_rallying_cry();
    new spell_warr_shockwave();
    new spell_warr_storm_bolt();
    new spell_warr_sudden_death();
    new spell_warr_sweeping_strikes();
    new spell_warr_trauma();
    new spell_warr_t3_prot_8p_bonus();
    new spell_warr_victorious_state();
    new spell_warr_victory_rush();
}
