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
#include "Spell.h"
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
    SPELL_WARRIOR_COLOSSUS_SMASH_AURA               = 208086,
    SPELL_WARRIOR_CRITICAL_THINKING_ENERGIZE        = 392776,
    SPELL_WARRIOR_EXECUTE                           = 20647,
    SPELL_WARRIOR_FUELED_BY_VIOLENCE_HEAL           = 383104,
    SPELL_WARRIOR_GLYPH_OF_THE_BLAZING_TRAIL        = 123779,
    SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP              = 159708,
    SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP_BUFF         = 133278,
    SPELL_WARRIOR_HEROIC_LEAP_JUMP                  = 178368,
    SPELL_WARRIOR_IGNORE_PAIN                       = 190456,
    SPELL_WARRIOR_IN_FOR_THE_KILL                   = 248621,
    SPELL_WARRIOR_IN_FOR_THE_KILL_HASTE             = 248622,
    SPELL_WARRIOR_IMPENDING_VICTORY                 = 202168,
    SPELL_WARRIOR_IMPENDING_VICTORY_HEAL            = 202166,
    SPELL_WARRIOR_IMPROVED_HEROIC_LEAP              = 157449,
    SPELL_WARRIOR_MORTAL_STRIKE                     = 12294,
    SPELL_WARRIOR_MORTAL_WOUNDS                     = 213667,
    SPELL_WARRIOR_RALLYING_CRY                      = 97463,
    SPELL_WARRIOR_SHIELD_BLOCK_AURA                 = 132404,
    SPELL_WARRIOR_SHIELD_CHARGE_EFFECT              = 385953,
    SPELL_WARRIOR_SHIELD_SLAM                       = 23922,
    SPELL_WARRIOR_SHIELD_SLAM_MARKER                = 224324,
    SPELL_WARRIOR_SHOCKWAVE                         = 46968,
    SPELL_WARRIOR_SHOCKWAVE_STUN                    = 132168,
    SPELL_WARRIOR_STOICISM                          = 70845,
    SPELL_WARRIOR_STORM_BOLT_STUN                   = 132169,
    SPELL_WARRIOR_STRATEGIST                        = 384041,
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
class spell_warr_bloodthirst : public SpellScript
{
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
        OnEffectHit += SpellEffectFn(spell_warr_bloodthirst::HandleDummy, EFFECT_3, SPELL_EFFECT_DUMMY);
    }
};

// 384036 - Brutal Vitality
class spell_warr_brutal_vitality : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_IGNORE_PAIN });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        _damageAmount += CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        if (_damageAmount == 0)
            return;

        if (AuraEffect* ignorePainAura = GetTarget()->GetAuraEffect(SPELL_WARRIOR_IGNORE_PAIN, EFFECT_0))
            ignorePainAura->ChangeAmount(ignorePainAura->GetAmount() + _damageAmount);

        _damageAmount = 0;
    }

    void Register() override
    {
        AfterEffectProc += AuraEffectProcFn(spell_warr_brutal_vitality::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_brutal_vitality::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint32 _damageAmount = 0;
};

// 100 - Charge
class spell_warr_charge : public SpellScript
{
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
        OnEffectHitTarget += SpellEffectFn(spell_warr_charge::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 126661 - Warrior Charge Drop Fire Periodic
class spell_warr_charge_drop_fire_periodic : public AuraScript
{
    void DropFireVisual(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (GetTarget()->IsSplineEnabled())
        {
            for (uint32 i = 0; i < 5; ++i)
            {
                int32 timeOffset = 6 * i * aurEff->GetPeriod() / 25;
                Movement::Location loc = GetTarget()->movespline->ComputePosition(timeOffset);
                GetTarget()->SendPlaySpellVisual(Position(loc.x, loc.y, loc.z), SPELL_VISUAL_BLAZING_CHARGE, 0, 0, 1.f, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_charge_drop_fire_periodic::DropFireVisual, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 198337 - Charge Effect (dropping Blazing Trail)
// 218104 - Charge Effect
class spell_warr_charge_effect : public SpellScript
{
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
        OnEffectLaunchTarget += SpellEffectFn(spell_warr_charge_effect::HandleCharge, EFFECT_0, SPELL_EFFECT_CHARGE);
    }
};

// 167105 - Colossus Smash
// 262161 - Warbreaker
class spell_warr_colossus_smash : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_COLOSSUS_SMASH_AURA, SPELL_WARRIOR_IN_FOR_THE_KILL, SPELL_WARRIOR_IN_FOR_THE_KILL_HASTE })
            && ValidateSpellEffect({ { SPELL_WARRIOR_IN_FOR_THE_KILL, EFFECT_2 } });
    }

    void HandleHit()
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_COLOSSUS_SMASH_AURA, true);

        if (caster->HasAura(SPELL_WARRIOR_IN_FOR_THE_KILL))
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_WARRIOR_IN_FOR_THE_KILL, DIFFICULTY_NONE))
            {
                if (target->HealthBelowPct(spellInfo->GetEffect(EFFECT_2).CalcValue(caster)))
                    _bonusHaste = true;
            }
        }
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_WARRIOR_IN_FOR_THE_KILL, DIFFICULTY_NONE);
        if (!spellInfo)
            return;

        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(spellInfo->GetEffect(EFFECT_0).CalcValue(caster));
        if (_bonusHaste)
            args.AddSpellBP0(spellInfo->GetEffect(EFFECT_1).CalcValue(caster));
        caster->CastSpell(caster, SPELL_WARRIOR_IN_FOR_THE_KILL_HASTE, args);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_warr_colossus_smash::HandleHit);
        AfterCast += SpellCastFn(spell_warr_colossus_smash::HandleAfterCast);
    }

private:
    bool _bonusHaste = false;
};

// 389306 - Critical Thinking
class spell_warr_critical_thinking : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_CRITICAL_THINKING_ENERGIZE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        if (Optional<int32> rageCost = eventInfo.GetProcSpell()->GetPowerTypeCostAmount(POWER_RAGE))
            GetTarget()->CastSpell(nullptr, SPELL_WARRIOR_CRITICAL_THINKING_ENERGIZE, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .AddSpellBP0(CalculatePct(*rageCost, aurEff->GetAmount())));
    }

    void Register() override
    {
        AfterEffectProc += AuraEffectProcFn(spell_warr_critical_thinking::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 236279 - Devastator
class spell_warr_devastator : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } }) && ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_SLAM, SPELL_WARRIOR_SHIELD_SLAM_MARKER });
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*eventInfo*/) const
    {
        if (GetTarget()->GetSpellHistory()->HasCooldown(SPELL_WARRIOR_SHIELD_SLAM))
        {
            if (roll_chance_i(GetEffectInfo(EFFECT_1).CalcValue()))
            {
                GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_SHIELD_SLAM, true);
                GetTarget()->CastSpell(GetTarget(), SPELL_WARRIOR_SHIELD_SLAM_MARKER, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
            }
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warr_devastator::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 383103  - Fueled by Violence
class spell_warr_fueled_by_violence : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_FUELED_BY_VIOLENCE_HEAL });
    }

    void HandleProc(ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        _nextHealAmount += CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), GetEffectInfo(EFFECT_0).CalcValue(GetTarget()));
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (_nextHealAmount == 0)
            return;

        Unit* target = GetTarget();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(_nextHealAmount);

        target->CastSpell(target, SPELL_WARRIOR_FUELED_BY_VIOLENCE_HEAL, args);
        _nextHealAmount = 0;
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_warr_fueled_by_violence::HandleProc);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_fueled_by_violence::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint32 _nextHealAmount = 0;
};

// 6544 - Heroic leap
class spell_warr_heroic_leap : public SpellScript
{
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

                bool result = generatedPath.CalculatePath(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), false);
                if (generatedPath.GetPathType() & PATHFIND_SHORT)
                    return SPELL_FAILED_OUT_OF_RANGE;
                else if (!result || generatedPath.GetPathType() & PATHFIND_NOPATH)
                    return SPELL_FAILED_NOPATH;
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
        OnCheckCast += SpellCheckCastFn(spell_warr_heroic_leap::CheckElevation);
        OnEffectHit += SpellEffectFn(spell_warr_heroic_leap::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Heroic Leap (triggered by Heroic Leap (6544)) - 178368
class spell_warr_heroic_leap_jump : public SpellScript
{
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
        OnEffectHit += SpellEffectFn(spell_warr_heroic_leap_jump::AfterJump, EFFECT_1, SPELL_EFFECT_JUMP_DEST);
    }
};

// 202168 - Impending Victory
class spell_warr_impending_victory : public SpellScript
{
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
        AfterCast += SpellCastFn(spell_warr_impending_victory::HandleAfterCast);
    }
};

// 5246 - Intimidating Shout
class spell_warr_intimidating_shout : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        unitList.remove(GetExplTargetWorldObject());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 70844 - Item - Warrior T10 Protection 4P Bonus
class spell_warr_item_t10_prot_4p_bonus : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_STOICISM })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void HandleProc(ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* target = eventInfo.GetActionTarget();
        int32 bp0 = CalculatePct(target->GetMaxHealth(), GetEffectInfo(EFFECT_1).CalcValue());
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellBP0(bp0);
        target->CastSpell(nullptr, SPELL_WARRIOR_STOICISM, args);
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_warr_item_t10_prot_4p_bonus::HandleProc);
    }
};

// 12294 - Mortal Strike 7.1.5
class spell_warr_mortal_strike : public SpellScript
{
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
        OnEffectHitTarget += SpellEffectFn(spell_warr_mortal_strike::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 97462 - Rallying Cry
class spell_warr_rallying_cry : public SpellScript
{
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
        OnEffectHitTarget += SpellEffectFn(spell_warr_rallying_cry::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 2565 - Shield Block
class spell_warr_shield_block : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_BLOCK_AURA });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(nullptr, SPELL_WARRIOR_SHIELD_BLOCK_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_shield_block::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 385952 - Shield Charge
class spell_warr_shield_charge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_CHARGE_EFFECT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_SHIELD_CHARGE_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_shield_charge::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 46968 - Shockwave
class spell_warr_shockwave : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return !ValidateSpellInfo({ SPELL_WARRIOR_SHOCKWAVE, SPELL_WARRIOR_SHOCKWAVE_STUN })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_3 } });
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
        if (_targetCount >= uint32(GetEffectInfo(EFFECT_0).CalcValue()))
            GetCaster()->ToPlayer()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, Seconds(-GetEffectInfo(EFFECT_3).CalcValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_shockwave::HandleStun, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_warr_shockwave::HandleAfterCast);
    }

    uint32 _targetCount = 0;
};

// 107570 - Storm Bolt
class spell_warr_storm_bolt : public SpellScript
{
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
        OnEffectHitTarget += SpellEffectFn(spell_warr_storm_bolt::HandleOnHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 384041 - Strategist
class spell_warr_strategist : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SHIELD_SLAM, SPELL_WARRIOR_SHIELD_SLAM_MARKER })
            && ValidateSpellEffect({ { SPELL_WARRIOR_STRATEGIST, EFFECT_0 } });
    }

    static bool CheckProc(AuraEffect const* aurEff, ProcEventInfo const& /*procEvent*/)
    {
        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleCooldown(AuraEffect const* /*aurEff*/, ProcEventInfo const& /*procEvent*/) const
    {
        Unit* caster = GetTarget();
        caster->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_SHIELD_SLAM, true);
        caster->CastSpell(caster, SPELL_WARRIOR_SHIELD_SLAM_MARKER, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_warr_strategist::CheckProc, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_warr_strategist::HandleCooldown, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 52437 - Sudden Death
class spell_warr_sudden_death : public AuraScript
{
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
        AfterEffectApply += AuraEffectRemoveFn(spell_warr_sudden_death::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL); // correct?
    }
};

// 12328, 18765, 35429 - Sweeping Strikes
class spell_warr_sweeping_strikes : public AuraScript
{
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
        DoCheckProc += AuraCheckProcFn(spell_warr_sweeping_strikes::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_warr_sweeping_strikes::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

    Unit* _procTarget = nullptr;
};

// 215538 - Trauma
class spell_warr_trauma : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_TRAUMA_EFFECT });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* target = eventInfo.GetActionTarget();
        //Get 25% of damage from the spell casted (Slam & Whirlwind) plus Remaining Damage from Aura
        int32 damage = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()) / sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_TRAUMA_EFFECT, GetCastDifficulty())->GetMaxTicks());
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
        GetCaster()->CastSpell(target, SPELL_WARRIOR_TRAUMA_EFFECT, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warr_trauma::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 28845 - Cheat Death
class spell_warr_t3_prot_8p_bonus : public AuraScript
{
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
        DoCheckProc += AuraCheckProcFn(spell_warr_t3_prot_8p_bonus::CheckProc);
    }
};

// 32215 - Victorious State
class spell_warr_victorious_state : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_IMPENDING_VICTORY });
    }

    void HandleOnProc(AuraEffect* /*aurEff*/, ProcEventInfo& procInfo)
    {
        if (procInfo.GetActor()->GetTypeId() == TYPEID_PLAYER && procInfo.GetActor()->ToPlayer()->GetPrimarySpecialization() == ChrSpecialization::WarriorFury)
            PreventDefaultAction();

        procInfo.GetActor()->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_IMPENDING_VICTORY, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warr_victorious_state::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 34428 - Victory Rush
class spell_warr_victory_rush : public SpellScript
{
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
        AfterCast += SpellCastFn(spell_warr_victory_rush::HandleHeal);
    }
};

void AddSC_warrior_spell_scripts()
{
    RegisterSpellScript(spell_warr_bloodthirst);
    RegisterSpellScript(spell_warr_brutal_vitality);
    RegisterSpellScript(spell_warr_charge);
    RegisterSpellScript(spell_warr_charge_drop_fire_periodic);
    RegisterSpellScript(spell_warr_charge_effect);
    RegisterSpellScript(spell_warr_colossus_smash);
    RegisterSpellScript(spell_warr_critical_thinking);
    RegisterSpellScript(spell_warr_devastator);
    RegisterSpellScript(spell_warr_fueled_by_violence);
    RegisterSpellScript(spell_warr_heroic_leap);
    RegisterSpellScript(spell_warr_heroic_leap_jump);
    RegisterSpellScript(spell_warr_impending_victory);
    RegisterSpellScript(spell_warr_intimidating_shout);
    RegisterSpellScript(spell_warr_item_t10_prot_4p_bonus);
    RegisterSpellScript(spell_warr_mortal_strike);
    RegisterSpellScript(spell_warr_rallying_cry);
    RegisterSpellScript(spell_warr_shield_block);
    RegisterSpellScript(spell_warr_shield_charge);
    RegisterSpellScript(spell_warr_shockwave);
    RegisterSpellScript(spell_warr_storm_bolt);
    RegisterSpellScript(spell_warr_strategist);
    RegisterSpellScript(spell_warr_sudden_death);
    RegisterSpellScript(spell_warr_sweeping_strikes);
    RegisterSpellScript(spell_warr_trauma);
    RegisterSpellScript(spell_warr_t3_prot_8p_bonus);
    RegisterSpellScript(spell_warr_victorious_state);
    RegisterSpellScript(spell_warr_victory_rush);
}
