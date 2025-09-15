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
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Player.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellScript.h"

enum WarriorSpells
{
    SPELL_WARRIOR_AVATAR                            = 107574,
    SPELL_WARRIOR_BLADESTORM                        = 227847,
    SPELL_WARRIOR_BLADESTORM_PERIODIC_WHIRLWIND     = 50622,
    SPELL_WARRIOR_BLOODTHIRST_HEAL                  = 117313,
    SPELL_WARRIOR_BOUNDING_STRIDE_AURA              = 202163,
    SPELL_WARRIOR_BOUNDING_STRIDE                   = 202164,
    SPELL_WARRIOR_CHARGE                            = 34846,
    SPELL_WARRIOR_CHARGE_DROP_FIRE_PERIODIC         = 126661,
    SPELL_WARRIOR_CHARGE_EFFECT                     = 198337,
    SPELL_WARRIOR_CHARGE_ROOT_EFFECT                = 105771,
    SPELL_WARRIOR_COLD_STEEL_HOT_BLOOD_TALENT       = 383959,
    SPELL_WARRIOR_COLOSSUS_SMASH                    = 167105,
    SPELL_WARRIOR_COLOSSUS_SMASH_AURA               = 208086,
    SPELL_WARRIOR_CRITICAL_THINKING_ENERGIZE        = 392776,
    SPELL_WARRIOR_DEFT_EXPERIENCE                   = 383295,
    SPELL_WARRIOR_EXECUTE                           = 20647,
    SPELL_WARRIOR_ENRAGE                            = 184362,
    SPELL_WARRIOR_FRENZIED_ENRAGE                   = 383848,
    SPELL_WARRIOR_FRENZY_TALENT                     = 335077,
    SPELL_WARRIOR_FRENZY_BUFF                       = 335082,
    SPELL_WARRIOR_FRESH_MEAT_DEBUFF                 = 316044,
    SPELL_WARRIOR_FRESH_MEAT_TALENT                 = 215568,
    SPELL_WARRIOR_FUELED_BY_VIOLENCE_HEAL           = 383104,
    SPELL_WARRIOR_GLYPH_OF_THE_BLAZING_TRAIL        = 123779,
    SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP              = 159708,
    SPELL_WARRIOR_GLYPH_OF_HEROIC_LEAP_BUFF         = 133278,
    SPELL_WARRIOR_GUSHING_WOUND                     = 385042,
    SPELL_WARRIOR_HEROIC_LEAP_JUMP                  = 178368,
    SPELL_WARRIOR_HEROIC_LEAP_DAMAGE                = 52174,
    SPELL_WARRIOR_IGNORE_PAIN                       = 190456,
    SPELL_WARRIOR_IMPROVED_RAGING_BLOW              = 383854,
    SPELL_WARRIOR_IMPROVED_WHIRLWIND                = 12950,
    SPELL_WARRIOR_INTIMIDATING_SHOUT_MENACE_AOE     = 316595,
    SPELL_WARRIOR_INVIGORATING_FURY                 = 385174,
    SPELL_WARRIOR_INVIGORATING_FURY_TALENT          = 383468,
    SPELL_WARRIOR_IN_FOR_THE_KILL                   = 248621,
    SPELL_WARRIOR_IN_FOR_THE_KILL_HASTE             = 248622,
    SPELL_WARRIOR_IMPENDING_VICTORY                 = 202168,
    SPELL_WARRIOR_IMPENDING_VICTORY_HEAL            = 202166,
    SPELL_WARRIOR_IMPROVED_HEROIC_LEAP              = 157449,
    SPELL_WARRIOR_MORTAL_STRIKE                     = 12294,
    SPELL_WARRIOR_MORTAL_WOUNDS                     = 115804,
    SPELL_WARRIOR_POWERFUL_ENRAGE                   = 440277,
    SPELL_WARRIOR_RALLYING_CRY                      = 97463,
    SPELL_WARRIOR_RAVAGER                           = 228920,
    SPELL_WARRIOR_RECKLESSNESS                      = 1719,
    SPELL_WARRIOR_RUMBLING_EARTH                    = 275339,
    SPELL_WARRIOR_SHIELD_BLOCK_AURA                 = 132404,
    SPELL_WARRIOR_SHIELD_CHARGE_EFFECT              = 385953,
    SPELL_WARRIOR_SHIELD_SLAM                       = 23922,
    SPELL_WARRIOR_SHIELD_SLAM_MARKER                = 224324,
    SPELL_WARRIOR_SHIELD_WALL                       = 871,
    SPELL_WARRIOR_SHOCKWAVE                         = 46968,
    SPELL_WARRIOR_SHOCKWAVE_STUN                    = 132168,
    SPELL_WARRIOR_SLAUGHTERING_STRIKES              = 388004,
    SPELL_WARRIOR_SLAUGHTERING_STRIKES_BUFF         = 393931,
    SPELL_WARRIOR_STOICISM                          = 70845,
    SPELL_WARRIOR_STORM_BOLT_STUN                   = 132169,
    SPELL_WARRIOR_STORM_BOLTS                       = 436162,
    SPELL_WARRIOR_STRATEGIST                        = 384041,
    SPELL_WARRIOR_SUDDEN_DEATH                      = 280721,
    SPELL_WARRIOR_SUDDEN_DEATH_BUFF                 = 280776,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_1   = 12723,
    SPELL_WARRIOR_SWEEPING_STRIKES_EXTRA_ATTACK_2   = 26654,
    SPELL_WARRIOR_TAUNT                             = 355,
    SPELL_WARRIOR_TITANIC_RAGE                      = 394329,
    SPELL_WARRIOR_TRAUMA_EFFECT                     = 215537,
    SPELL_WARRIOR_VICIOUS_CONTEMPT                  = 383885,
    SPELL_WARRIOR_VICTORIOUS                        = 32216,
    SPELL_WARRIOR_VICTORY_RUSH_HEAL                 = 118779,
    SPELL_WARRIOR_WARBREAKER                        = 262161,
    SPELL_WARRIOR_WHIRLWIND_CLEAVE_AURA             = 85739,
    SPELL_WARRIOR_WHIRLWIND_ENERGIZE                = 280715,
    SPELL_WARRIOR_WRATH_AND_FURY                    = 392936
};

enum WarriorMisc
{
    SPELL_VISUAL_BLAZING_CHARGE = 26423
};

static void ApplyWhirlwindCleaveAura(Player* caster, Difficulty difficulty, Spell const* triggeringSpell)
{
    SpellInfo const* whirlwindCleaveAuraInfo = sSpellMgr->AssertSpellInfo(SPELL_WARRIOR_WHIRLWIND_CLEAVE_AURA, difficulty);
    int32 stackAmount = static_cast<int32>(whirlwindCleaveAuraInfo->StackAmount);
    caster->ApplySpellMod(whirlwindCleaveAuraInfo, SpellModOp::MaxAuraStacks, stackAmount);

    caster->CastSpell(nullptr, SPELL_WARRIOR_WHIRLWIND_CLEAVE_AURA, CastSpellExtraArgsInit{
        .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
        .TriggeringSpell = triggeringSpell,
        .SpellValueOverrides = { { SPELLVALUE_AURA_STACK, stackAmount } }
    });
}

// 152278 - Anger Management
class spell_warr_anger_management_proc : public AuraScript
{
    static bool ValidateProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo, ChrSpecialization spec)
    {
        if (aurEff->GetAmount() == 0)
            return false;

        Player const* player = eventInfo.GetActor()->ToPlayer();
        if (!player)
            return false;

        Spell const* procSpell = eventInfo.GetProcSpell();
        if (!procSpell)
            return false;

        if (procSpell->GetPowerTypeCostAmount(POWER_RAGE) <= 0)
            return false;

        return player->GetPrimarySpecialization() == spec;
    }

    static bool CheckArmsProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        if (!ValidateProc(aurEff, eventInfo, ChrSpecialization::WarriorArms))
            return false;

        // exclude non-attacks such as Ignore Pain
        if (!eventInfo.GetSpellInfo()->IsAffected(SPELLFAMILY_WARRIOR, { 0x100, 0x0, 0x0, 0x0 }))
            return false;

        return true;
    }

    static bool CheckFuryProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        return ValidateProc(aurEff, eventInfo, ChrSpecialization::WarriorFury);
    }

    static bool CheckProtectionProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        return ValidateProc(aurEff, eventInfo, ChrSpecialization::WarriorProtection);
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_WARRIOR_COLOSSUS_SMASH,
            SPELL_WARRIOR_BLADESTORM,
            SPELL_WARRIOR_RAVAGER,
            SPELL_WARRIOR_WARBREAKER,
            SPELL_WARRIOR_RECKLESSNESS,
            SPELL_WARRIOR_AVATAR,
            SPELL_WARRIOR_SHIELD_WALL
        });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo, std::span<int32 const> spellIds) const
    {
        int32 rageCost = *eventInfo.GetProcSpell()->GetPowerTypeCostAmount(POWER_RAGE) / 10; // db values are 10x the actual rage cost
        float multiplier  = static_cast<float>(rageCost) / static_cast<float>(aurEff->GetAmount());
        Milliseconds cooldownMod = -duration_cast<Milliseconds>(multiplier * CooldownReduction);

        for (int32 spellId : spellIds)
            GetTarget()->GetSpellHistory()->ModifyCooldown(spellId, cooldownMod);
    }

    void OnProcArms(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        HandleProc(aurEff, eventInfo, ArmsSpellIds);
    }

    void OnProcFury(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        HandleProc(aurEff, eventInfo, FurySpellIds);
    }

    void OnProcProtection(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        HandleProc(aurEff, eventInfo, ProtectionSpellIds);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_warr_anger_management_proc::CheckArmsProc, EFFECT_0, SPELL_AURA_DUMMY);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_warr_anger_management_proc::CheckProtectionProc, EFFECT_1, SPELL_AURA_DUMMY);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_warr_anger_management_proc::CheckFuryProc, EFFECT_2, SPELL_AURA_DUMMY);

        OnEffectProc += AuraEffectProcFn(spell_warr_anger_management_proc::OnProcArms, EFFECT_0, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_warr_anger_management_proc::OnProcProtection, EFFECT_1, SPELL_AURA_DUMMY);
        OnEffectProc += AuraEffectProcFn(spell_warr_anger_management_proc::OnProcFury, EFFECT_2, SPELL_AURA_DUMMY);
    }

    static constexpr FloatMilliseconds CooldownReduction = 1s;
    static constexpr std::array<int32, 4> ArmsSpellIds = { SPELL_WARRIOR_COLOSSUS_SMASH, SPELL_WARRIOR_WARBREAKER, SPELL_WARRIOR_BLADESTORM, SPELL_WARRIOR_RAVAGER };
    static constexpr std::array<int32, 3> FurySpellIds = { SPELL_WARRIOR_RECKLESSNESS, SPELL_WARRIOR_BLADESTORM, SPELL_WARRIOR_RAVAGER };
    static constexpr std::array<int32, 2> ProtectionSpellIds = { SPELL_WARRIOR_AVATAR, SPELL_WARRIOR_SHIELD_WALL };
};

// 392536 - Ashen Juggernaut
class spell_warr_ashen_juggernaut : public AuraScript
{
    static bool CheckProc(AuraScript const&, ProcEventInfo const& eventInfo)
    {
        // should only proc on primary target
        return eventInfo.GetActionTarget() == eventInfo.GetProcSpell()->m_targets.GetUnitTarget();
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_warr_ashen_juggernaut::CheckProc);
    }
};

// 107574 - Avatar
class spell_warr_avatar : public SpellScript
{
    void HandleRemoveImpairingAuras(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->RemoveMovementImpairingAuras(true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_avatar::HandleRemoveImpairingAuras, EFFECT_5, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 23881 - Bloodthirst
// 335096 - Bloodbath
class spell_warr_bloodthirst : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_BLOODTHIRST_HEAL });
    }

    void CastHeal(SpellEffIndex /*effIndex*/) const
    {
        if (GetHitUnit() != GetExplTargetUnit())
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_BLOODTHIRST_HEAL, CastSpellExtraArgsInit
        {
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_bloodthirst::CastHeal, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
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
        return ValidateSpellInfo({ SPELL_WARRIOR_CHARGE_EFFECT });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_CHARGE_EFFECT, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
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

        Unit* target = GetTarget();
        if (target->IsSplineEnabled())
        {
            Movement::Location from = target->movespline->ComputePosition();
            Movement::Location to = target->movespline->ComputePosition(aurEff->GetPeriod());

            int32 fireCount = std::lround((to - from).length());

            for (int32 i = 0; i < fireCount; ++i)
            {
                int32 timeOffset = i * aurEff->GetPeriod() / fireCount;
                Movement::Location loc = target->movespline->ComputePosition(timeOffset);
                target->SendPlaySpellVisual(Position(loc.x, loc.y, loc.z), SPELL_VISUAL_BLAZING_CHARGE, 0, 0, 1.f, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_charge_drop_fire_periodic::DropFireVisual, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 198337 - Charge Effect
class spell_warr_charge_effect : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_WARRIOR_CHARGE_ROOT_EFFECT,
            SPELL_WARRIOR_CHARGE_DROP_FIRE_PERIODIC
        });
    }

    void HandleCharge(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        CastSpellExtraArgs const args = CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_FULL_MASK & ~TRIGGERED_CAST_DIRECTLY,
            .TriggeringSpell = GetSpell()
        };

        if (caster->HasAura(SPELL_WARRIOR_GLYPH_OF_THE_BLAZING_TRAIL))
            caster->CastSpell(target, SPELL_WARRIOR_CHARGE_DROP_FIRE_PERIODIC, args);

        caster->CastSpell(target, SPELL_WARRIOR_CHARGE_ROOT_EFFECT, args);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_warr_charge_effect::HandleCharge, EFFECT_0, SPELL_EFFECT_CHARGE);
    }
};

// 23881 - Bloodthirst
// 335096 - Bloodbath
class spell_warr_cold_steel_hot_blood_bloodthirst : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_GUSHING_WOUND, SPELL_WARRIOR_COLD_STEEL_HOT_BLOOD_TALENT });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_COLD_STEEL_HOT_BLOOD_TALENT);
    }

    void CastGushingWound(SpellEffIndex /*effIndex*/) const
    {
        if (!IsHitCrit())
            return;

        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_GUSHING_WOUND, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
            });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_cold_steel_hot_blood_bloodthirst::CastGushingWound, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
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

// 383295 - Deft Experience (attached to 23881 - Bloodthirst)
// 383295 - Deft Experience (attached to 335096 - Bloodbath)
class spell_warr_deft_experience : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARRIOR_DEFT_EXPERIENCE, EFFECT_1 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_DEFT_EXPERIENCE);
    }

    void HandleDeftExperience(SpellEffIndex /*effIndex*/) const
    {
        if (GetHitUnit() != GetExplTargetUnit())
            return;

        Unit const* caster = GetCaster();
        if (Aura* enrageAura = caster->GetAura(SPELL_WARRIOR_ENRAGE))
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_WARRIOR_DEFT_EXPERIENCE, EFFECT_1))
                enrageAura->SetDuration(enrageAura->GetDuration() + aurEff->GetAmount());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_deft_experience::HandleDeftExperience, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
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

// 184361 - Enrage
class spell_warr_enrage_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_FRESH_MEAT_TALENT, SPELL_WARRIOR_FRESH_MEAT_DEBUFF });
    }

    static bool CheckRampageProc(AuraScript const&, AuraEffect const* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || !spellInfo->IsAffected(SPELLFAMILY_WARRIOR, { 0x0, 0x0, 0x0, 0x8000000 }))  // Rampage
            return false;

        return true;
    }

    static bool IsBloodthirst(SpellInfo const* spellInfo)
    {
        // Bloodthirst/Bloodbath
        return spellInfo->IsAffected(SPELLFAMILY_WARRIOR, { 0x0, 0x400 });
    }

    static bool CheckBloodthirstProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo || !IsBloodthirst(spellInfo))
            return false;

        // Fresh Meat talent handling
        if (Unit const* actor = eventInfo.GetActor())
        {
            if (actor->HasAura(SPELL_WARRIOR_FRESH_MEAT_TALENT))
            {
                Spell const* procSpell = eventInfo.GetProcSpell();
                if (!procSpell)
                    return false;

                Unit const* target = procSpell->m_targets.GetUnitTarget();
                if (!target)
                    return false;

                if (!target->HasAura(SPELL_WARRIOR_FRESH_MEAT_DEBUFF, actor->GetGUID()))
                    return true;
            }
        }

        return roll_chance_i(aurEff->GetAmount());
    }

    void HandleProc(ProcEventInfo const& eventInfo)
    {
        PreventDefaultAction();

        Unit* auraTarget = GetTarget();

        auraTarget->CastSpell(nullptr, SPELL_WARRIOR_ENRAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = eventInfo.GetProcSpell()
        });

        // Fresh Meat talent handling
        if (auraTarget->HasAura(SPELL_WARRIOR_FRESH_MEAT_TALENT))
        {
            Spell const* procSpell = eventInfo.GetProcSpell();
            if (!procSpell)
                return;

            if (!IsBloodthirst(procSpell->GetSpellInfo()))
                return;

            if (Unit* bloodthirstTarget = procSpell->m_targets.GetUnitTarget())
                if (!bloodthirstTarget->HasAura(SPELL_WARRIOR_FRESH_MEAT_DEBUFF, auraTarget->GetGUID()))
                    auraTarget->CastSpell(bloodthirstTarget, SPELL_WARRIOR_FRESH_MEAT_DEBUFF, CastSpellExtraArgsInit{
                        .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                    });
        }
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_warr_enrage_proc::CheckRampageProc, EFFECT_0, SPELL_AURA_DUMMY);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_warr_enrage_proc::CheckBloodthirstProc, EFFECT_1, SPELL_AURA_DUMMY);
        OnProc += AuraProcFn(spell_warr_enrage_proc::HandleProc);
    }
};

// 260798 - Execute (Arms, Protection)
class spell_warr_execute_damage : public SpellScript
{
    static void CalculateExecuteDamage(SpellScript const&, SpellEffectInfo const& /*spellEffectInfo*/, Unit const* /*victim*/, int32 const& /*damageOrHealing*/, int32 const& /*flatMod*/, float& pctMod)
    {
        // tooltip has 2 multiplier hardcoded in it $damage=${2.0*$260798s1}
        pctMod *= 2.0f;
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_warr_execute_damage::CalculateExecuteDamage);
    }
};

// 383848 - Frenzied Enrage (attached to 184362 - Enrage)
class spell_warr_frenzied_enrage : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_FRENZIED_ENRAGE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && spellInfo->GetEffect(EFFECT_0).IsAura(SPELL_AURA_MELEE_SLOW)
            && spellInfo->GetEffect(EFFECT_1).IsAura(SPELL_AURA_MOD_INCREASE_SPEED);
    }

    bool Load() override
    {
        return !GetCaster()->HasAura(SPELL_WARRIOR_FRENZIED_ENRAGE);
    }

    static void HandleFrenziedEnrage(SpellScript const&, WorldObject*& target)
    {
        target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_warr_frenzied_enrage::HandleFrenziedEnrage, EFFECT_0, TARGET_UNIT_CASTER);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_warr_frenzied_enrage::HandleFrenziedEnrage, EFFECT_1, TARGET_UNIT_CASTER);
    }
};

// 335082 - frenzy
class spell_warr_frenzy : public AuraScript
{
public:
    void SetTargetGUID(ObjectGuid const& guid) { _targetGUID = guid; }
    ObjectGuid const& GetTargetGUID() const { return _targetGUID; }

private:
    void Register() override { }

    ObjectGuid _targetGUID;
};

// 335077 - Frenzy (attached to 184367 - Rampage)
class spell_warr_frenzy_rampage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_FRENZY_BUFF, SPELL_WARRIOR_FRENZY_TALENT });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_FRENZY_TALENT);
    }

    void HandleAfterCast(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();

        if (hitUnit != GetExplTargetUnit())
            return;

        caster->CastSpell(nullptr, SPELL_WARRIOR_FRENZY_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });

        if (Aura* frenzyAura = caster->GetAura(SPELL_WARRIOR_FRENZY_BUFF))
        {
            if (spell_warr_frenzy* script = frenzyAura->GetScript<spell_warr_frenzy>())
            {
                if (!script->GetTargetGUID().IsEmpty() && script->GetTargetGUID() != hitUnit->GetGUID())
                    frenzyAura->SetStackAmount(1);

                script->SetTargetGUID(hitUnit->GetGUID());
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_frenzy_rampage::HandleAfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 440277 - Powerful Enrage (attached to 184362 - Enrage)
class spell_warr_powerful_enrage : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_POWERFUL_ENRAGE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_4 } })
            && spellInfo->GetEffect(EFFECT_3).IsAura(SPELL_AURA_ADD_PCT_MODIFIER) && spellInfo->GetEffect(EFFECT_3).MiscValue == int32(SpellModOp::HealingAndDamage)
            && spellInfo->GetEffect(EFFECT_4).IsAura(SPELL_AURA_ADD_PCT_MODIFIER) && spellInfo->GetEffect(EFFECT_4).MiscValue == int32(SpellModOp::PeriodicHealingAndDamage);
    }

    bool Load() override
    {
        return !GetCaster()->HasAura(SPELL_WARRIOR_POWERFUL_ENRAGE);
    }

    static void HandlePowerfulEnrage(SpellScript const&, WorldObject*& target)
    {
        target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_warr_powerful_enrage::HandlePowerfulEnrage, EFFECT_3, TARGET_UNIT_CASTER);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_warr_powerful_enrage::HandlePowerfulEnrage, EFFECT_4, TARGET_UNIT_CASTER);
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
        return ValidateSpellInfo({ SPELL_WARRIOR_HEROIC_LEAP_DAMAGE, SPELL_WARRIOR_TAUNT });
    }

    SpellCastResult CheckElevation() const
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

                if (!result || generatedPath.GetPathType() & PATHFIND_NOPATH)
                    return SPELL_FAILED_NOPATH;
            }
            else if (dest->GetPositionZ() > GetCaster()->GetPositionZ() + 4.0f)
                return SPELL_FAILED_NOPATH;

            return SPELL_CAST_OK;
        }

        return SPELL_FAILED_NO_VALID_TARGETS;
    }

    void HandleCast() const
    {
        if (Player* playerCaster = GetCaster()->ToPlayer())
            if (playerCaster->GetPrimarySpecialization() == ChrSpecialization::WarriorProtection)
                playerCaster->GetSpellHistory()->ResetCooldown(SPELL_WARRIOR_TAUNT);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_warr_heroic_leap::HandleCast);
        OnCheckCast += SpellCheckCastFn(spell_warr_heroic_leap::CheckElevation);
    }
};

// 52174 - Heroic Leap (Damage)
class spell_warr_heroic_leap_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_WARRIOR_BOUNDING_STRIDE_AURA,
            SPELL_WARRIOR_BOUNDING_STRIDE
        });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_BOUNDING_STRIDE_AURA);
    }

    void HandleCast() const
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_WARRIOR_BOUNDING_STRIDE, CastSpellExtraArgsInit{
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_warr_heroic_leap_damage::HandleCast);
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

// 12950 - Improved Whirlwind (attached to 190411 - Whirlwind)
class spell_improved_whirlwind : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_IMPROVED_WHIRLWIND, SPELL_WARRIOR_WHIRLWIND_CLEAVE_AURA })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 }, { SPELL_WARRIOR_WHIRLWIND_ENERGIZE, EFFECT_0 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_IMPROVED_WHIRLWIND);
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        int64 const targetsHit = GetUnitTargetCountForEffect(EFFECT_0);
        if (!targetsHit)
            return;

        Player* caster = GetCaster()->ToPlayer();
        if (!caster)
            return;

        int32 const ragePerTarget = GetEffectValue();
        int32 const baseRage = GetEffectInfo(EFFECT_0).CalcValue();
        int32 const maxRage = baseRage + (ragePerTarget * GetEffectInfo(EFFECT_2).CalcValue());
        int32 const rageGained = std::min<int32>(baseRage + (targetsHit * ragePerTarget), maxRage);

        caster->CastSpell(nullptr, SPELL_WARRIOR_WHIRLWIND_ENERGIZE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .SpellValueOverrides = {{ SPELLVALUE_BASE_POINT0, rageGained * 10 } }
        });

        ApplyWhirlwindCleaveAura(caster, GetCastDifficulty(), GetSpell());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_improved_whirlwind::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 5246 - Intimidating Shout
class spell_warr_intimidating_shout : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList) const
    {
        unitList.remove(GetExplTargetWorldObject());
    }

    static void ClearTargets(SpellScript const&, std::list<WorldObject*>& unitList)
    {
        // This is used in effect 3, which is an AOE Root effect.
        // This doesn't seem to be a thing anymore, so we clear the targets list here.
        unitList.clear();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout::ClearTargets, EFFECT_3, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 316594 - Intimidating Shout (Menace Talent, knock back -> root)
class spell_warr_intimidating_shout_menace_knock_back : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_INTIMIDATING_SHOUT_MENACE_AOE });
    }

    void FilterTargets(std::list<WorldObject*>& unitList) const
    {
        unitList.remove(GetExplTargetWorldObject());
    }

    void HandleRoot(SpellEffIndex /*effIndex*/) const
    {
        CastSpellExtraArgs args = CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        };

        GetCaster()->m_Events.AddEventAtOffset([caster = GetCaster(), targetGUID = GetHitUnit()->GetGUID(), castArgs = std::move(args)]()
        {
            if (Unit* targetUnit = ObjectAccessor::GetUnit(*caster, targetGUID))
                caster->CastSpell(targetUnit, SPELL_WARRIOR_INTIMIDATING_SHOUT_MENACE_AOE, castArgs);
        }, 500ms);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_intimidating_shout_menace_knock_back::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_warr_intimidating_shout_menace_knock_back::HandleRoot, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
    }
};

// 385174 - Invigorating Fury (attached to 184364 - Enraged Regeneration)
class spell_warr_invigorating_fury : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_INVIGORATING_FURY, SPELL_WARRIOR_INVIGORATING_FURY_TALENT });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_INVIGORATING_FURY_TALENT);
    }

    void CastHeal() const
    {
        GetCaster()->CastSpell(nullptr, SPELL_WARRIOR_INVIGORATING_FURY, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_warr_invigorating_fury::CastHeal);
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

// 12294 - Mortal Strike
class spell_warr_mortal_strike : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_MORTAL_WOUNDS });
    }

    void HandleMortalWounds(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_MORTAL_WOUNDS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_mortal_strike::HandleMortalWounds, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 383854 - Improved Raging Blow (attached to 85288 - Raging Blow, 335097 - Crushing Blow)
// 392936 - Wrath and Fury (attached to 85288 - Raging Blow, 335097 - Crushing Blow)
class spell_warr_raging_blow_cooldown_reset : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_IMPROVED_RAGING_BLOW })
            && ValidateSpellEffect({{ SPELL_WARRIOR_WRATH_AND_FURY, EFFECT_0 }});
    }

    bool Load() override
    {
        Unit const* caster = GetCaster();
        return caster->HasAura(SPELL_WARRIOR_IMPROVED_RAGING_BLOW) || caster->HasAuraEffect(SPELL_WARRIOR_WRATH_AND_FURY, EFFECT_0);
    }

    void HandleResetCooldown(SpellEffIndex /*effIndex*/) const
    {
        // it is currently impossible to have Wrath and Fury without having Improved Raging Blow, but we will check it anyway
        Unit* caster = GetCaster();
        int32 value = 0;
        if (caster->HasAura(SPELL_WARRIOR_IMPROVED_RAGING_BLOW))
            value = GetEffectValue();

        if (AuraEffect const* auraEffect = caster->GetAuraEffect(SPELL_WARRIOR_WRATH_AND_FURY, EFFECT_0))
            value += auraEffect->GetAmount();

        if (roll_chance_i(value))
            caster->GetSpellHistory()->RestoreCharge(GetSpellInfo()->ChargeCategoryId);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_raging_blow_cooldown_reset::HandleResetCooldown, EFFECT_0, SPELL_EFFECT_DUMMY);
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

// 275339 - (attached to 46968 - Shockwave)
class spell_warr_rumbling_earth : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARRIOR_RUMBLING_EARTH, EFFECT_1 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_RUMBLING_EARTH);
    }

    void HandleCooldownReduction(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Aura const* rumblingEarth = caster->GetAura(SPELL_WARRIOR_RUMBLING_EARTH);
        if (!rumblingEarth)
            return;

        AuraEffect const* minTargetCount = rumblingEarth->GetEffect(EFFECT_0);
        AuraEffect const* cooldownReduction = rumblingEarth->GetEffect(EFFECT_1);
        if (!minTargetCount || !cooldownReduction)
            return;

        if (GetUnitTargetCountForEffect(EFFECT_0) >= minTargetCount->GetAmount())
            GetCaster()->GetSpellHistory()->ModifyCooldown(GetSpellInfo()->Id, Seconds(-cooldownReduction->GetAmount()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_rumbling_earth::HandleCooldownReduction, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
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
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SHOCKWAVE_STUN });
    }

    void HandleStun(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_SHOCKWAVE_STUN, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_shockwave::HandleStun, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 107570 - Storm Bolt
class spell_warr_storm_bolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_STORM_BOLT_STUN });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_WARRIOR_STORM_BOLT_STUN, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warr_storm_bolt::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 107570 - Storm Bolt
class spell_warr_storm_bolts: public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_STORM_BOLTS });
    }

    bool Load() override
    {
        return !GetCaster()->HasAura(SPELL_WARRIOR_STORM_BOLTS);
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        targets.clear();

        if (Unit* target = GetExplTargetUnit())
            targets.push_back(target);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warr_storm_bolts::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
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

    static bool CheckProc(AuraScript const&, AuraEffect const* aurEff, ProcEventInfo const& /*procEvent*/)
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

// 280776 - Sudden Death
class spell_warr_sudden_death : public AuraScript
{
    static bool CheckProc(AuraScript const&, ProcEventInfo const& eventInfo)
    {
        // should only proc on primary target
        return eventInfo.GetActionTarget() == eventInfo.GetProcSpell()->m_targets.GetUnitTarget();
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_warr_sudden_death::CheckProc);
    }
};

// 280721 - Sudden Death
class spell_warr_sudden_death_proc : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_SUDDEN_DEATH_BUFF });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/) const
    {
        GetTarget()->CastSpell(nullptr, SPELL_WARRIOR_SUDDEN_DEATH_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warr_sudden_death_proc::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
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

// 388933 - Tenderize
class spell_warr_tenderize : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_ENRAGE, SPELL_WARRIOR_SLAUGHTERING_STRIKES_BUFF, SPELL_WARRIOR_SLAUGHTERING_STRIKES });
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        GetTarget()->CastSpell(nullptr, SPELL_WARRIOR_ENRAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = eventInfo.GetProcSpell()
        });
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo const& eventInfo) const
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_WARRIOR_SLAUGHTERING_STRIKES))
            return;

        target->CastSpell(nullptr, SPELL_WARRIOR_SLAUGHTERING_STRIKES_BUFF, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = eventInfo.GetProcSpell(),
            .SpellValueOverrides = { { SPELLVALUE_AURA_STACK, aurEff->GetAmount() } }
        });
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_warr_tenderize::HandleProc);
        OnEffectProc += AuraEffectProcFn(spell_warr_tenderize::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 394329 - Titanic Rage
class spell_warr_titanic_rage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_WHIRLWIND_CLEAVE_AURA });
    }

    void HandleProc(ProcEventInfo const& eventInfo) const
    {
        Player* target = GetTarget()->ToPlayer();
        if (!target)
            return;

        target->CastSpell(nullptr, SPELL_WARRIOR_ENRAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = eventInfo.GetProcSpell()
        });

        ApplyWhirlwindCleaveAura(target, GetCastDifficulty(), nullptr);
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_warr_titanic_rage::HandleProc);
    }
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

// 389603 - Unbridled Ferocity
class spell_warr_unbridled_ferocity : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WARRIOR_RECKLESSNESS })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } })
            && spellInfo->GetEffect(EFFECT_0).IsAura(SPELL_AURA_DUMMY)
            && spellInfo->GetEffect(EFFECT_1).IsAura(SPELL_AURA_DUMMY);
    }

    void HandleProc(ProcEventInfo& /*eventInfo*/) const
    {
        int32 durationMs = GetEffect(EFFECT_1)->GetAmount();

        GetTarget()->CastSpell(nullptr, SPELL_WARRIOR_RECKLESSNESS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR | TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD,
            .SpellValueOverrides = { { SPELLVALUE_DURATION, durationMs } }
        });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/) const
    {
        return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_warr_unbridled_ferocity::CheckProc);
        OnProc += AuraProcFn(spell_warr_unbridled_ferocity::HandleProc);
    }
};

// 383885 - Vicious Contempt (attached to 23881 - Bloodthirst)
// 383885 - Vicious Contempt (attached to 335096 - Bloodbath)
class spell_warr_vicious_contempt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellEffect({ { SPELL_WARRIOR_VICIOUS_CONTEMPT, EFFECT_0 } });
    }

    bool Load() override
    {
        return GetCaster()->HasAura(SPELL_WARRIOR_VICIOUS_CONTEMPT);
    }

    void CalculateDamage(SpellEffectInfo const& /*spellEffectInfo*/, Unit const* victim, int32& /*damage*/, int32& /*flatMod*/, float& pctMod) const
    {
        if (!victim->HasAuraState(AURA_STATE_WOUNDED_35_PERCENT))
            return;

        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_WARRIOR_VICIOUS_CONTEMPT, EFFECT_0))
            AddPct(pctMod, aurEff->GetAmount());
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_warr_vicious_contempt::CalculateDamage);
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
    RegisterSpellScript(spell_warr_anger_management_proc);
    RegisterSpellScript(spell_warr_ashen_juggernaut);
    RegisterSpellScript(spell_warr_avatar);
    RegisterSpellScript(spell_warr_bloodthirst);
    RegisterSpellScript(spell_warr_brutal_vitality);
    RegisterSpellScript(spell_warr_charge);
    RegisterSpellScript(spell_warr_charge_drop_fire_periodic);
    RegisterSpellScript(spell_warr_charge_effect);
    RegisterSpellScript(spell_warr_cold_steel_hot_blood_bloodthirst);
    RegisterSpellScript(spell_warr_colossus_smash);
    RegisterSpellScript(spell_warr_critical_thinking);
    RegisterSpellScript(spell_warr_deft_experience);
    RegisterSpellScript(spell_warr_devastator);
    RegisterSpellScript(spell_warr_enrage_proc);
    RegisterSpellScript(spell_warr_execute_damage);
    RegisterSpellScript(spell_warr_frenzied_enrage);
    RegisterSpellScript(spell_warr_frenzy);
    RegisterSpellScript(spell_warr_frenzy_rampage);
    RegisterSpellScript(spell_warr_fueled_by_violence);
    RegisterSpellScript(spell_warr_heroic_leap);
    RegisterSpellScript(spell_warr_heroic_leap_damage);
    RegisterSpellScript(spell_warr_impending_victory);
    RegisterSpellScript(spell_improved_whirlwind);
    RegisterSpellScript(spell_warr_intimidating_shout);
    RegisterSpellScript(spell_warr_intimidating_shout_menace_knock_back);
    RegisterSpellScript(spell_warr_invigorating_fury);
    RegisterSpellScript(spell_warr_item_t10_prot_4p_bonus);
    RegisterSpellScript(spell_warr_mortal_strike);
    RegisterSpellScript(spell_warr_powerful_enrage);
    RegisterSpellScript(spell_warr_raging_blow_cooldown_reset);
    RegisterSpellScript(spell_warr_rallying_cry);
    RegisterSpellScript(spell_warr_rumbling_earth);
    RegisterSpellScript(spell_warr_shield_block);
    RegisterSpellScript(spell_warr_shield_charge);
    RegisterSpellScript(spell_warr_shockwave);
    RegisterSpellScript(spell_warr_storm_bolt);
    RegisterSpellScript(spell_warr_storm_bolts);
    RegisterSpellScript(spell_warr_strategist);
    RegisterSpellScript(spell_warr_sudden_death);
    RegisterSpellScript(spell_warr_sudden_death_proc);
    RegisterSpellScript(spell_warr_sweeping_strikes);
    RegisterSpellScript(spell_warr_tenderize);
    RegisterSpellScript(spell_warr_titanic_rage);
    RegisterSpellScript(spell_warr_trauma);
    RegisterSpellScript(spell_warr_t3_prot_8p_bonus);
    RegisterSpellScript(spell_warr_unbridled_ferocity);
    RegisterSpellScript(spell_warr_vicious_contempt);
    RegisterSpellScript(spell_warr_victorious_state);
    RegisterSpellScript(spell_warr_victory_rush);
}
