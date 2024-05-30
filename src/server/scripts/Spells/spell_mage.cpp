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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "GridNotifiers.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum MageSpells
{
    SPELL_MAGE_ALTER_TIME_AURA                   = 110909,
    SPELL_MAGE_ALTER_TIME_VISUAL                 = 347402,
    SPELL_MAGE_ARCANE_ALTER_TIME_AURA            = 342246,
    SPELL_MAGE_ARCANE_BARRAGE_ENERGIZE           = 321529,
    SPELL_MAGE_ARCANE_BARRAGE_R3                 = 321526,
    SPELL_MAGE_ARCANE_CHARGE                     = 36032,
    SPELL_MAGE_ARCANE_MAGE                       = 137021,
    SPELL_MAGE_BLAZING_BARRIER_TRIGGER           = 235314,
    SPELL_MAGE_BLINK                             = 1953,
    SPELL_MAGE_BLIZZARD_DAMAGE                   = 190357,
    SPELL_MAGE_BLIZZARD_SLOW                     = 12486,
    SPELL_MAGE_CAUTERIZE_DOT                     = 87023,
    SPELL_MAGE_CAUTERIZED                        = 87024,
    SPELL_MAGE_CHILLED                           = 205708,
    SPELL_MAGE_COMET_STORM_DAMAGE                = 153596,
    SPELL_MAGE_COMET_STORM_VISUAL                = 228601,
    SPELL_MAGE_CONE_OF_COLD                      = 120,
    SPELL_MAGE_CONE_OF_COLD_SLOW                 = 212792,
    SPELL_MAGE_CONJURE_REFRESHMENT               = 116136,
    SPELL_MAGE_CONJURE_REFRESHMENT_TABLE         = 167145,
    SPELL_MAGE_DRAGONHAWK_FORM                   = 32818,
    SPELL_MAGE_ETHEREAL_BLINK                    = 410939,
    SPELL_MAGE_EVERWARM_SOCKS                    = 320913,
    SPELL_MAGE_FEEL_THE_BURN                     = 383391,
    SPELL_MAGE_FINGERS_OF_FROST                  = 44544,
    SPELL_MAGE_FIRE_BLAST                        = 108853,
    SPELL_MAGE_FLURRY_DAMAGE                     = 228596,
    SPELL_MAGE_FIRESTARTER                       = 205026,
    SPELL_MAGE_FROST_NOVA                        = 122,
    SPELL_MAGE_GIRAFFE_FORM                      = 32816,
    SPELL_MAGE_ICE_BARRIER                       = 11426,
    SPELL_MAGE_ICE_BLOCK                         = 45438,
    SPELL_MAGE_IGNITE                            = 12654,
    SPELL_MAGE_INCANTERS_FLOW                    = 116267,
    SPELL_MAGE_LIVING_BOMB_EXPLOSION             = 44461,
    SPELL_MAGE_LIVING_BOMB_PERIODIC              = 217694,
    SPELL_MAGE_MANA_SURGE                        = 37445,
    SPELL_MAGE_MASTER_OF_TIME                    = 342249,
    SPELL_MAGE_RADIANT_SPARK_PROC_BLOCKER        = 376105,
    SPELL_MAGE_RAY_OF_FROST_BONUS                = 208141,
    SPELL_MAGE_RAY_OF_FROST_FINGERS_OF_FROST     = 269748,
    SPELL_MAGE_REVERBERATE                       = 281482,
    SPELL_MAGE_RING_OF_FROST_DUMMY               = 91264,
    SPELL_MAGE_RING_OF_FROST_FREEZE              = 82691,
    SPELL_MAGE_RING_OF_FROST_SUMMON              = 113724,
    SPELL_MAGE_SERPENT_FORM                      = 32817,
    SPELL_MAGE_SHEEP_FORM                        = 32820,
    SPELL_MAGE_SHIMMER                           = 212653,
    SPELL_MAGE_SLOW                              = 31589,
    SPELL_MAGE_SQUIRREL_FORM                     = 32813,
    SPELL_MAGE_SUPERNOVA                         = 157980,
    SPELL_MAGE_WORGEN_FORM                       = 32819,
    SPELL_PET_NETHERWINDS_FATIGUED               = 160455,
    SPELL_MAGE_ICE_LANCE_TRIGGER                 = 228598,
    SPELL_MAGE_THERMAL_VOID                      = 155149,
    SPELL_MAGE_ICY_VEINS                         = 12472,
    SPELL_MAGE_CHAIN_REACTION_DUMMY              = 278309,
    SPELL_MAGE_CHAIN_REACTION                    = 278310,
    SPELL_MAGE_TOUCH_OF_THE_MAGI_EXPLODE         = 210833,
    SPELL_MAGE_WINTERS_CHILL                     = 228358
};

// 110909 - Alter Time Aura
// 342246 - Alter Time Aura
class spell_mage_alter_time_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_ALTER_TIME_VISUAL,
            SPELL_MAGE_MASTER_OF_TIME,
            SPELL_MAGE_BLINK,
        });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* unit = GetTarget();
        _health = unit->GetHealth();
        _pos = unit->GetPosition();
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* unit = GetTarget();
        if (unit->GetDistance(_pos) <= 100.0f && GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            unit->SetHealth(_health);
            unit->NearTeleportTo(_pos);

            if (unit->HasAura(SPELL_MAGE_MASTER_OF_TIME))
            {
                SpellInfo const* blink = sSpellMgr->AssertSpellInfo(SPELL_MAGE_BLINK, DIFFICULTY_NONE);
                unit->GetSpellHistory()->ResetCharges(blink->ChargeCategoryId);
            }
            unit->CastSpell(unit, SPELL_MAGE_ALTER_TIME_VISUAL);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_mage_alter_time_aura::OnApply, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_alter_time_aura::AfterRemove, EFFECT_0, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS, AURA_EFFECT_HANDLE_REAL);
    }

private:
    uint64 _health = 0;
    Position _pos;
};

// 127140 - Alter Time Active
// 342247 - Alter Time Active
class spell_mage_alter_time_active : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_ALTER_TIME_AURA,
            SPELL_MAGE_ARCANE_ALTER_TIME_AURA,
        });
    }

    void RemoveAlterTimeAura(SpellEffIndex /*effIndex*/)
    {
        Unit* unit = GetCaster();
        unit->RemoveAura(SPELL_MAGE_ALTER_TIME_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
        unit->RemoveAura(SPELL_MAGE_ARCANE_ALTER_TIME_AURA, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_alter_time_active::RemoveAlterTimeAura, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 44425 - Arcane Barrage
class spell_mage_arcane_barrage : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_ARCANE_BARRAGE_R3, SPELL_MAGE_ARCANE_BARRAGE_ENERGIZE })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
    }

    void ConsumeArcaneCharges()
    {
        Unit* caster = GetCaster();

        // Consume all arcane charges
        if (int32 arcaneCharges = -caster->ModifyPower(POWER_ARCANE_CHARGES, -caster->GetMaxPower(POWER_ARCANE_CHARGES), false))
            if (AuraEffect const* auraEffect = caster->GetAuraEffect(SPELL_MAGE_ARCANE_BARRAGE_R3, EFFECT_0, caster->GetGUID()))
                caster->CastSpell(caster, SPELL_MAGE_ARCANE_BARRAGE_ENERGIZE, { SPELLVALUE_BASE_POINT0, arcaneCharges * auraEffect->GetAmount() / 100 });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->GetGUID() != _primaryTarget)
            SetHitDamage(CalculatePct(GetHitDamage(), GetEffectInfo(EFFECT_1).CalcValue(GetCaster())));
    }

    void MarkPrimaryTarget(SpellEffIndex /*effIndex*/)
    {
        _primaryTarget = GetHitUnit()->GetGUID();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_barrage::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectLaunchTarget += SpellEffectFn(spell_mage_arcane_barrage::MarkPrimaryTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_mage_arcane_barrage::ConsumeArcaneCharges);
    }

    ObjectGuid _primaryTarget;
};

// 195302 - Arcane Charge
class spell_mage_arcane_charge_clear : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_ARCANE_CHARGE });
    }

    void RemoveArcaneCharge(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_CHARGE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_charge_clear::RemoveArcaneCharge, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 1449 - Arcane Explosion
class spell_mage_arcane_explosion : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!ValidateSpellInfo({ SPELL_MAGE_ARCANE_MAGE, SPELL_MAGE_REVERBERATE }))
            return false;

        if (!ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } }))
            return false;

        return spellInfo->GetEffect(EFFECT_1).IsEffect(SPELL_EFFECT_SCHOOL_DAMAGE);
    }

    void CheckRequiredAuraForBaselineEnergize(SpellEffIndex effIndex)
    {
        if (!GetUnitTargetCountForEffect(EFFECT_1) || !GetCaster()->HasAura(SPELL_MAGE_ARCANE_MAGE))
            PreventHitDefaultEffect(effIndex);
    }

    void HandleReverberate(SpellEffIndex effIndex)
    {
        bool procTriggered = [&]()
        {
            Unit const* caster = GetCaster();
            AuraEffect const* triggerChance = caster->GetAuraEffect(SPELL_MAGE_REVERBERATE, EFFECT_0);
            if (!triggerChance)
                return false;

            AuraEffect const* requiredTargets = caster->GetAuraEffect(SPELL_MAGE_REVERBERATE, EFFECT_1);
            if (!requiredTargets)
                return false;

            return GetUnitTargetCountForEffect(EFFECT_1) >= requiredTargets->GetAmount() && roll_chance_i(triggerChance->GetAmount());
        }();

        if (!procTriggered)
            PreventHitDefaultEffect(effIndex);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_explosion::CheckRequiredAuraForBaselineEnergize, EFFECT_0, SPELL_EFFECT_ENERGIZE);
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_explosion::HandleReverberate, EFFECT_2, SPELL_EFFECT_ENERGIZE);
    }
};

// 235313 - Blazing Barrier
class spell_mage_blazing_barrier : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLAZING_BARRIER_TRIGGER });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
            amount = int32(caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()) * 7.0f);
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetDamageInfo()->GetVictim();
        Unit* target = eventInfo.GetDamageInfo()->GetAttacker();

        if (caster && target)
            caster->CastSpell(target, SPELL_MAGE_BLAZING_BARRIER_TRIGGER, true);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_blazing_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectProc += AuraEffectProcFn(spell_mage_blazing_barrier::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 190356 - Blizzard
// 4658 - AreaTrigger Create Properties
struct areatrigger_mage_blizzard : AreaTriggerAI
{
    areatrigger_mage_blizzard(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _tickTimer(TICK_PERIOD) { }

    static constexpr Milliseconds TICK_PERIOD = Milliseconds(1000);

    void OnUpdate(uint32 diff) override
    {
        _tickTimer -= Milliseconds(diff);

        while (_tickTimer <= 0s)
        {
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(at->GetPosition(), SPELL_MAGE_BLIZZARD_DAMAGE);

            _tickTimer += TICK_PERIOD;
        }
    }

private:
    Milliseconds _tickTimer;
};

// 190357 - Blizzard (Damage)
class spell_mage_blizzard_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLIZZARD_SLOW });
    }

    void HandleSlow(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGE_BLIZZARD_SLOW, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_blizzard_damage::HandleSlow, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 198063 - Burning Determination
class spell_mage_burning_determination : public AuraScript
{
    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
            if (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_INTERRUPT) | (1 << MECHANIC_SILENCE)))
                return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_burning_determination::CheckProc);
    }
};

// 86949 - Cauterize
class spell_mage_cauterize : public SpellScript
{
    void SuppressSpeedBuff(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_mage_cauterize::SuppressSpeedBuff, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

class spell_mage_cauterize_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } }) && ValidateSpellInfo
        ({
            SPELL_MAGE_CAUTERIZE_DOT,
            SPELL_MAGE_CAUTERIZED,
            spellInfo->GetEffect(EFFECT_2).TriggerSpell
        });
    }

    void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        AuraEffect const* effect1 = GetEffect(EFFECT_1);
        if (!effect1 ||
            !GetTargetApplication()->HasEffect(EFFECT_1) ||
            dmgInfo.GetDamage() < GetTarget()->GetHealth() ||
            dmgInfo.GetDamage() > GetTarget()->GetMaxHealth() * 2 ||
            GetTarget()->HasAura(SPELL_MAGE_CAUTERIZED))
        {
            PreventDefaultAction();
            return;
        }

        GetTarget()->SetHealth(GetTarget()->CountPctFromMaxHealth(effect1->GetAmount()));
        GetTarget()->CastSpell(GetTarget(), GetEffectInfo(EFFECT_2).TriggerSpell, TRIGGERED_FULL_MASK);
        GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_CAUTERIZE_DOT, TRIGGERED_FULL_MASK);
        GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_CAUTERIZED, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_mage_cauterize_AuraScript::HandleAbsorb, EFFECT_0);
    }
};

// 235219 - Cold Snap
class spell_mage_cold_snap : public SpellScript
{
    static uint32 constexpr SpellsToReset[] =
    {
        SPELL_MAGE_CONE_OF_COLD,
        SPELL_MAGE_ICE_BARRIER,
        SPELL_MAGE_ICE_BLOCK,
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(SpellsToReset) && ValidateSpellInfo({ SPELL_MAGE_FROST_NOVA });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        for (uint32 spellId : SpellsToReset)
            GetCaster()->GetSpellHistory()->ResetCooldown(spellId, true);

        GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_MAGE_FROST_NOVA, GetCastDifficulty())->ChargeCategoryId);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_cold_snap::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class CometStormEvent : public BasicEvent
{
public:
    CometStormEvent(Unit* caster, ObjectGuid originalCastId, Position const& dest) : _caster(caster), _originalCastId(originalCastId), _dest(dest), _count(0) { }

    bool Execute(uint64 time, uint32 /*diff*/) override
    {
        Position destPosition = {_dest.GetPositionX() + frand(-3.0f, 3.0f), _dest.GetPositionY() + frand(-3.0f, 3.0f), _dest.GetPositionZ()};
        _caster->CastSpell(destPosition, SPELL_MAGE_COMET_STORM_VISUAL,
            CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetOriginalCastId(_originalCastId));
        ++_count;

        if (_count >= 7)
            return true;

        _caster->m_Events.AddEvent(this, Milliseconds(time) + randtime(100ms, 275ms));
        return false;
    }

private:
    Unit* _caster;
    ObjectGuid _originalCastId;
    Position _dest;
    uint8 _count;
};

// 153595 - Comet Storm (launch)
class spell_mage_comet_storm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_COMET_STORM_VISUAL });
    }

    void EffectHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->m_Events.AddEventAtOffset(new CometStormEvent(GetCaster(), GetSpell()->m_castId, *GetHitDest()), randtime(100ms, 275ms));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_comet_storm::EffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228601 - Comet Storm (damage)
class spell_mage_comet_storm_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_COMET_STORM_DAMAGE });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(*GetHitDest(), SPELL_MAGE_COMET_STORM_DAMAGE,
            CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetOriginalCastId(GetSpell()->m_originalCastId));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_comet_storm_damage::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 120 - Cone of Cold
class spell_mage_cone_of_cold : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_CONE_OF_COLD_SLOW });
    }

    void HandleSlow(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGE_CONE_OF_COLD_SLOW, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_cone_of_cold::HandleSlow, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 190336 - Conjure Refreshment
class spell_mage_conjure_refreshment : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_CONJURE_REFRESHMENT,
            SPELL_MAGE_CONJURE_REFRESHMENT_TABLE
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            Group* group = caster->GetGroup();
            if (group)
                caster->CastSpell(caster, SPELL_MAGE_CONJURE_REFRESHMENT_TABLE, true);
            else
                caster->CastSpell(caster, SPELL_MAGE_CONJURE_REFRESHMENT, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_conjure_refreshment::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 410939 - Ethereal Blink
class spell_mage_ethereal_blink : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLINK, SPELL_MAGE_SHIMMER });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        PreventDefaultAction();

        // this proc only works for players because teleport relocation happens after an ACK
        GetTarget()->CastSpell(*procInfo.GetProcSpell()->m_targets.GetDst(), aurEff->GetSpellEffectInfo().TriggerSpell, CastSpellExtraArgs(aurEff)
            .SetTriggeringSpell(procInfo.GetProcSpell())
            .SetCustomArg(GetTarget()->GetPosition()));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_ethereal_blink::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 410941 - Ethereal Blink
class spell_mage_ethereal_blink_triggered : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLINK, SPELL_MAGE_SHIMMER, SPELL_MAGE_SLOW })
            && ValidateSpellEffect({ { SPELL_MAGE_ETHEREAL_BLINK, EFFECT_3 } });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Position const* src = std::any_cast<Position>(&GetSpell()->m_customArg);
        WorldLocation const* dst = GetExplTargetDest();
        if (!src || !dst)
        {
            targets.clear();
            return;
        }

        targets.remove_if([&](WorldObject* target)
        {
            return !target->IsInBetween(*src, *dst, (target->GetCombatReach() + GetCaster()->GetCombatReach()) / 2.0f);
        });

        AuraEffect const* reductionEffect = GetCaster()->GetAuraEffect(SPELL_MAGE_ETHEREAL_BLINK, EFFECT_2);
        if (!reductionEffect)
            return;

        Seconds reduction = Seconds(reductionEffect->GetAmount()) * targets.size();

        if (AuraEffect const* cap = GetCaster()->GetAuraEffect(SPELL_MAGE_ETHEREAL_BLINK, EFFECT_3))
            if (reduction > Seconds(cap->GetAmount()))
                reduction = Seconds(cap->GetAmount());

        if (reduction > 0s)
        {
            GetCaster()->GetSpellHistory()->ModifyCooldown(SPELL_MAGE_BLINK, -reduction);
            GetCaster()->GetSpellHistory()->ModifyCooldown(SPELL_MAGE_SHIMMER, -reduction);
        }
    }

    void TriggerSlow(SpellEffIndex /*effIndex*/)
    {
        int32 effectivenessPct = 100;
        if (AuraEffect const* effectivenessEffect = GetCaster()->GetAuraEffect(SPELL_MAGE_ETHEREAL_BLINK, EFFECT_1))
            effectivenessPct = effectivenessEffect->GetAmount();

        int32 slowPct = sSpellMgr->AssertSpellInfo(SPELL_MAGE_SLOW, DIFFICULTY_NONE)->GetEffect(EFFECT_0).CalcBaseValue(GetCaster(), GetHitUnit());
        ApplyPct(slowPct, effectivenessPct);

        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGE_SLOW, CastSpellExtraArgs(GetSpell())
            .AddSpellMod(SPELLVALUE_BASE_POINT0, slowPct));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_ethereal_blink_triggered::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_mage_ethereal_blink_triggered::TriggerSlow, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 383395 - Feel the Burn
class spell_mage_feel_the_burn : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FEEL_THE_BURN });
    }

    void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect const* valueHolder = caster->GetAuraEffect(SPELL_MAGE_FEEL_THE_BURN, EFFECT_0))
                amount = valueHolder->GetAmount();

        canBeRecalculated = false;
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_feel_the_burn::CalcAmount, EFFECT_0, SPELL_AURA_MASTERY);
    }
};

// 112965 - Fingers of Frost
class spell_mage_fingers_of_frost : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FINGERS_OF_FROST });
    }

    bool CheckFrostboltProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->IsAffected(SPELLFAMILY_MAGE, flag128(0, 0x2000000, 0, 0))
            && roll_chance_i(aurEff->GetAmount());
    }

    bool CheckFrozenOrbProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        return eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->IsAffected(SPELLFAMILY_MAGE, flag128(0, 0, 0x80, 0))
            && roll_chance_i(aurEff->GetAmount());
    }

    void Trigger(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(GetTarget(), SPELL_MAGE_FINGERS_OF_FROST, aurEff);
    }

    void Register() override
    {
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_mage_fingers_of_frost::CheckFrostboltProc, EFFECT_0, SPELL_AURA_DUMMY);
        DoCheckEffectProc += AuraCheckEffectProcFn(spell_mage_fingers_of_frost::CheckFrozenOrbProc, EFFECT_1, SPELL_AURA_DUMMY);
        AfterEffectProc += AuraEffectProcFn(spell_mage_fingers_of_frost::Trigger, EFFECT_0, SPELL_AURA_DUMMY);
        AfterEffectProc += AuraEffectProcFn(spell_mage_fingers_of_frost::Trigger, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 133 - Fireball
// 11366 - Pyroblast
class spell_mage_firestarter : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FIRESTARTER });
    }

    void CalcCritChance(Unit const* victim, float& critChance)
    {
        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_MAGE_FIRESTARTER, EFFECT_0))
            if (victim->GetHealthPct() >= aurEff->GetAmount())
                critChance = 100.0f;
    }

    void Register() override
    {
        OnCalcCritChance += SpellOnCalcCritChanceFn(spell_mage_firestarter::CalcCritChance);
    }
};

// 321712 - Pyroblast
class spell_mage_firestarter_dots : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FIRESTARTER });
    }

    void CalcCritChance(AuraEffect const* /*aurEff*/, Unit const* victim, float& critChance)
    {
        if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_MAGE_FIRESTARTER, EFFECT_0))
            if (victim->GetHealthPct() >= aurEff->GetAmount())
                critChance = 100.0f;
    }

    void Register() override
    {
        DoEffectCalcCritChance += AuraEffectCalcCritChanceFn(spell_mage_firestarter_dots::CalcCritChance, EFFECT_ALL, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 205029 - Flame On
class spell_mage_flame_on : public AuraScript
{
   bool Validate(SpellInfo const* spellInfo) override
   {
       return ValidateSpellInfo({ SPELL_MAGE_FIRE_BLAST })
           && sSpellCategoryStore.HasRecord(sSpellMgr->AssertSpellInfo(SPELL_MAGE_FIRE_BLAST, DIFFICULTY_NONE)->ChargeCategoryId)
           && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } });
   }

   void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
   {
       canBeRecalculated = false;
       amount = -GetPctOf(GetEffectInfo(EFFECT_2).CalcValue() * IN_MILLISECONDS, sSpellCategoryStore.AssertEntry(sSpellMgr->AssertSpellInfo(SPELL_MAGE_FIRE_BLAST, DIFFICULTY_NONE)->ChargeCategoryId)->ChargeRecoveryTime);
   }

   void Register() override
   {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_flame_on::CalculateAmount, EFFECT_1, SPELL_AURA_CHARGE_RECOVERY_MULTIPLIER);
   }
};

// 44614 - Flurry
class spell_mage_flurry : public SpellScript
{
    class FlurryEvent : public BasicEvent
    {
    public:
        FlurryEvent(Unit* caster, ObjectGuid const& target, ObjectGuid const& originalCastId, int32 count)
            : _caster(caster), _target(target), _originalCastId(originalCastId), _count(count) { }

        bool Execute(uint64 time, uint32 /*diff*/) override
        {
            Unit* target = ObjectAccessor::GetUnit(*_caster, _target);

            if (!target)
                return true;

            _caster->CastSpell(target, SPELL_MAGE_FLURRY_DAMAGE, CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetOriginalCastId(_originalCastId));

            if (!--_count)
                return true;

            _caster->m_Events.AddEvent(this, Milliseconds(time) + randtime(300ms, 400ms));
            return false;
        }

    private:
        Unit* _caster;
        ObjectGuid _target;
        ObjectGuid _originalCastId;
        int32 _count;
    };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FLURRY_DAMAGE });
    }

    void EffectHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->m_Events.AddEventAtOffset(new FlurryEvent(GetCaster(), GetHitUnit()->GetGUID(), GetSpell()->m_castId, GetEffectValue() - 1), randtime(300ms, 400ms));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_flurry::EffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228354 - Flurry (damage)
class spell_mage_flurry_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_WINTERS_CHILL });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGE_WINTERS_CHILL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_flurry_damage::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 116 - Frostbolt
class spell_mage_frostbolt : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_CHILLED });
    }

    void HandleChilled()
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, SPELL_MAGE_CHILLED, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_mage_frostbolt::HandleChilled);
    }
};

// 386737 - Hyper Impact
class spell_mage_hyper_impact : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_SUPERNOVA });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_MAGE_SUPERNOVA, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_hyper_impact::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 11426 - Ice Barrier
class spell_mage_ice_barrier : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_CHILLED
        });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
            amount += int32(caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()) * 10.0f);
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        Unit* caster = eventInfo.GetDamageInfo()->GetVictim();
        Unit* target = eventInfo.GetDamageInfo()->GetAttacker();

        if (caster && target)
            caster->CastSpell(target, SPELL_MAGE_CHILLED, true);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_ice_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectProc += AuraEffectProcFn(spell_mage_ice_barrier::HandleProc, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// 45438 - Ice Block
class spell_mage_ice_block : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_EVERWARM_SOCKS });
    }

    void PreventStunWithEverwarmSocks(WorldObject*& target)
    {
        if (GetCaster()->HasAura(SPELL_MAGE_EVERWARM_SOCKS))
            target = nullptr;
    }

    void PreventEverwarmSocks(WorldObject*& target)
    {
        if (!GetCaster()->HasAura(SPELL_MAGE_EVERWARM_SOCKS))
            target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_mage_ice_block::PreventStunWithEverwarmSocks, EFFECT_0, TARGET_UNIT_CASTER);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_mage_ice_block::PreventEverwarmSocks, EFFECT_5, TARGET_UNIT_CASTER);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_mage_ice_block::PreventEverwarmSocks, EFFECT_6, TARGET_UNIT_CASTER);
    }
};

// Ice Lance - 30455
class spell_mage_ice_lance : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_ICE_LANCE_TRIGGER,
            SPELL_MAGE_THERMAL_VOID,
            SPELL_MAGE_ICY_VEINS,
            SPELL_MAGE_CHAIN_REACTION_DUMMY,
            SPELL_MAGE_CHAIN_REACTION,
            SPELL_MAGE_FINGERS_OF_FROST
        });
    }

    void IndexTarget(SpellEffIndex /*effIndex*/)
    {
        _orderedTargets.push_back(GetHitUnit()->GetGUID());
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        std::ptrdiff_t index = std::distance(_orderedTargets.begin(), std::find(_orderedTargets.begin(), _orderedTargets.end(), target->GetGUID()));

        if (index == 0 // only primary target triggers these benefits
            && target->HasAuraState(AURA_STATE_FROZEN, GetSpellInfo(), caster))
        {
            // Thermal Void
            if (Aura const* thermalVoid = caster->GetAura(SPELL_MAGE_THERMAL_VOID))
                if (!thermalVoid->GetSpellInfo()->GetEffects().empty())
                    if (Aura* icyVeins = caster->GetAura(SPELL_MAGE_ICY_VEINS))
                        icyVeins->SetDuration(icyVeins->GetDuration() + thermalVoid->GetSpellInfo()->GetEffect(EFFECT_0).CalcValue(caster) * IN_MILLISECONDS);

            // Chain Reaction
            if (caster->HasAura(SPELL_MAGE_CHAIN_REACTION_DUMMY))
                caster->CastSpell(caster, SPELL_MAGE_CHAIN_REACTION, true);
        }

        // put target index for chain value multiplier into EFFECT_1 base points, otherwise triggered spell doesn't know which damage multiplier to apply
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_FULL_MASK;
        args.AddSpellMod(SPELLVALUE_BASE_POINT1, index);
        caster->CastSpell(target, SPELL_MAGE_ICE_LANCE_TRIGGER, args);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_mage_ice_lance::IndexTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget += SpellEffectFn(spell_mage_ice_lance::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

    std::vector<ObjectGuid> _orderedTargets;
};

// 228598 - Ice Lance
class spell_mage_ice_lance_damage : public SpellScript
{
    void ApplyDamageMultiplier(SpellEffIndex /*effIndex*/)
    {
        SpellValue const* spellValue = GetSpellValue();
        if (spellValue->CustomBasePointsMask & (1 << EFFECT_1))
        {
            int32 originalDamage = GetHitDamage();
            float targetIndex = float(spellValue->EffectBasePoints[EFFECT_1]);
            float multiplier = std::pow(GetEffectInfo().CalcDamageMultiplier(GetCaster(), GetSpell()), targetIndex);
            SetHitDamage(int32(originalDamage * multiplier));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_ice_lance_damage::ApplyDamageMultiplier, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 12846 - Ignite
class spell_mage_ignite : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_IGNITE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget() != nullptr;
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        SpellInfo const* igniteDot = sSpellMgr->AssertSpellInfo(SPELL_MAGE_IGNITE, GetCastDifficulty());
        int32 pct = aurEff->GetAmount();

        ASSERT(igniteDot->GetMaxTicks() > 0);
        int32 amount = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), pct) / igniteDot->GetMaxTicks());

        CastSpellExtraArgs args(aurEff);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, amount);
        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_MAGE_IGNITE, args);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_ignite::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_mage_ignite::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 37447 - Improved Mana Gems
// 61062 - Improved Mana Gems
class spell_mage_imp_mana_gems : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_MANA_SURGE });
    }

    void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_MAGE_MANA_SURGE, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_imp_mana_gems::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// 1463 - Incanter's Flow
class spell_mage_incanters_flow : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_INCANTERS_FLOW });
    }

    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        // Incanter's flow should not cycle out of combat
        if (!GetTarget()->IsInCombat())
            return;

        if (Aura* aura = GetTarget()->GetAura(SPELL_MAGE_INCANTERS_FLOW))
        {
            uint32 stacks = aura->GetStackAmount();

            // Force always to values between 1 and 5
            if ((modifier == -1 && stacks == 1) || (modifier == 1 && stacks == 5))
            {
                modifier *= -1;
                return;
            }

            aura->ModStackAmount(modifier);
        }
        else
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_INCANTERS_FLOW, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_incanters_flow::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    int8 modifier = 1;
};

// 44457 - Living Bomb
class spell_mage_living_bomb : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_LIVING_BOMB_PERIODIC });
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGE_LIVING_BOMB_PERIODIC, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT2, 1));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_living_bomb::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 44461 - Living Bomb
class spell_mage_living_bomb_explosion : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return spellInfo->NeedsExplicitUnitTarget() && ValidateSpellInfo({ SPELL_MAGE_LIVING_BOMB_PERIODIC });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetExplTargetWorldObject());
    }

    void HandleSpread(SpellEffIndex /*effIndex*/)
    {
        if (GetSpellValue()->EffectBasePoints[EFFECT_0] > 0)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGE_LIVING_BOMB_PERIODIC, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT2, 0));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_living_bomb_explosion::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_mage_living_bomb_explosion::HandleSpread, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 217694 - Living Bomb
class spell_mage_living_bomb_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_LIVING_BOMB_EXPLOSION });
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_MAGE_LIVING_BOMB_EXPLOSION, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount()));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_living_bomb_periodic::AfterRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

enum SilvermoonPolymorph
{
    NPC_AUROSALIA       = 18744
};

/// @todo move out of here and rename - not a mage spell
// 32826 - Polymorph (Visual)
class spell_mage_polymorph_visual : public SpellScript
{
    static const uint32 PolymorhForms[6];

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(PolymorhForms);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetCaster()->FindNearestCreature(NPC_AUROSALIA, 30.0f))
            if (target->GetTypeId() == TYPEID_UNIT)
                target->CastSpell(target, PolymorhForms[urand(0, 5)], true);
    }

    void Register() override
    {
        // add dummy effect spell handler to Polymorph visual
        OnEffectHitTarget += SpellEffectFn(spell_mage_polymorph_visual::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

uint32 const spell_mage_polymorph_visual::PolymorhForms[6] =
{
    SPELL_MAGE_SQUIRREL_FORM,
    SPELL_MAGE_GIRAFFE_FORM,
    SPELL_MAGE_SERPENT_FORM,
    SPELL_MAGE_DRAGONHAWK_FORM,
    SPELL_MAGE_WORGEN_FORM,
    SPELL_MAGE_SHEEP_FORM
};

// 235450 - Prismatic Barrier
class spell_mage_prismatic_barrier : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellEffect({ { spellInfo->Id, EFFECT_5 } });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
            amount = int32(CalculatePct(caster->GetMaxHealth(), GetEffectInfo(EFFECT_5).CalcValue(caster)));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_prismatic_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// 376103 - Radiant Spark
class spell_mage_radiant_spark : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RADIANT_SPARK_PROC_BLOCKER });
    }

    bool CheckProc(AuraEffect const* /*aurEff*/, ProcEventInfo& procInfo)
    {
        return !procInfo.GetProcTarget()->HasAura(SPELL_MAGE_RADIANT_SPARK_PROC_BLOCKER, GetCasterGUID());
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& procInfo)
    {
        Aura* vulnerability = procInfo.GetProcTarget()->GetAura(aurEff->GetSpellEffectInfo().TriggerSpell, GetCasterGUID());
        if (vulnerability && vulnerability->GetStackAmount() == vulnerability->CalcMaxStackAmount())
        {
            PreventDefaultAction();
            vulnerability->Remove();
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_RADIANT_SPARK_PROC_BLOCKER, true);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_radiant_spark::HandleProc, EFFECT_2, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 205021 - Ray of Frost
class spell_mage_ray_of_frost : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_MAGE_RAY_OF_FROST_FINGERS_OF_FROST });
    }

    void HandleOnHit()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_MAGE_RAY_OF_FROST_FINGERS_OF_FROST, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_mage_ray_of_frost::HandleOnHit);
    }
};

class spell_mage_ray_of_frost_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_MAGE_RAY_OF_FROST_BONUS, SPELL_MAGE_RAY_OF_FROST_FINGERS_OF_FROST });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
        {
            if (aurEff->GetTickNumber() > 1) // First tick should deal base damage
               caster->CastSpell(caster, SPELL_MAGE_RAY_OF_FROST_BONUS, true);
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->RemoveAurasDueToSpell(SPELL_MAGE_RAY_OF_FROST_FINGERS_OF_FROST);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_ray_of_frost_aura::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_ray_of_frost_aura::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 136511 - Ring of Frost
class spell_mage_ring_of_frost : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RING_OF_FROST_SUMMON, SPELL_MAGE_RING_OF_FROST_FREEZE })
            && ValidateSpellEffect({ { SPELL_MAGE_RING_OF_FROST_SUMMON, EFFECT_0 } });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (TempSummon* ringOfFrost = GetRingOfFrostMinion())
            GetTarget()->CastSpell(ringOfFrost->GetPosition(), SPELL_MAGE_RING_OF_FROST_FREEZE, true);
    }

    void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        std::list<TempSummon*> minions;
        GetTarget()->GetAllMinionsByEntry(minions, sSpellMgr->AssertSpellInfo(SPELL_MAGE_RING_OF_FROST_SUMMON, GetCastDifficulty())->GetEffect(EFFECT_0).MiscValue);

        // Get the last summoned RoF, save it and despawn older ones
        for (TempSummon* summon : minions)
        {
            if (TempSummon* ringOfFrost = GetRingOfFrostMinion())
            {
                if (summon->GetTimer() > ringOfFrost->GetTimer())
                {
                    ringOfFrost->DespawnOrUnsummon();
                    _ringOfFrostGUID = summon->GetGUID();
                }
                else
                    summon->DespawnOrUnsummon();
            }
            else
                _ringOfFrostGUID = summon->GetGUID();
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_ring_of_frost::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        OnEffectApply += AuraEffectApplyFn(spell_mage_ring_of_frost::Apply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }

private:
    TempSummon* GetRingOfFrostMinion() const
    {
        if (Creature* creature = ObjectAccessor::GetCreature(*GetOwner(), _ringOfFrostGUID))
            return creature->ToTempSummon();
        return nullptr;
    }

    ObjectGuid _ringOfFrostGUID;
};

// 82691 - Ring of Frost (freeze efect)
class spell_mage_ring_of_frost_freeze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RING_OF_FROST_SUMMON, SPELL_MAGE_RING_OF_FROST_FREEZE })
            && ValidateSpellEffect({ { SPELL_MAGE_RING_OF_FROST_SUMMON, EFFECT_0 } });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        WorldLocation const* dest = GetExplTargetDest();
        float outRadius = sSpellMgr->AssertSpellInfo(SPELL_MAGE_RING_OF_FROST_SUMMON, GetCastDifficulty())->GetEffect(EFFECT_0).CalcRadius(nullptr, SpellTargetIndex::TargetB);
        float inRadius = 6.5f;

        targets.remove_if([dest, outRadius, inRadius](WorldObject* target)
        {
            Unit* unit = target->ToUnit();
            if (!unit)
                return true;
            return unit->HasAura(SPELL_MAGE_RING_OF_FROST_DUMMY) || unit->HasAura(SPELL_MAGE_RING_OF_FROST_FREEZE) || unit->GetExactDist(dest) > outRadius || unit->GetExactDist(dest) < inRadius;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_ring_of_frost_freeze::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

class spell_mage_ring_of_frost_freeze_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RING_OF_FROST_DUMMY });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            if (GetCaster())
                GetCaster()->CastSpell(GetTarget(), SPELL_MAGE_RING_OF_FROST_DUMMY, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_ring_of_frost_freeze_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 157980 - Supernova
class spell_mage_supernova : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (GetExplTargetUnit() == GetHitUnit())
        {
            uint32 damage = GetHitDamage();
            AddPct(damage, GetEffectInfo(EFFECT_0).CalcValue());
            SetHitDamage(damage);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_supernova::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 210824 - Touch of the Magi (Aura)
class spell_mage_touch_of_the_magi_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_TOUCH_OF_THE_MAGI_EXPLODE });
    }

    void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (damageInfo)
        {
            if (damageInfo->GetAttacker() == GetCaster() && damageInfo->GetVictim() == GetTarget())
            {
                uint32 extra = CalculatePct(damageInfo->GetDamage(), 25);
                if (extra > 0)
                    aurEff->ChangeAmount(aurEff->GetAmount() + extra);
            }
        }
    }

    void AfterRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        int32 amount = aurEff->GetAmount();
        if (!amount || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_MAGE_TOUCH_OF_THE_MAGI_EXPLODE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_BASE_POINT0, amount));
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_touch_of_the_magi_aura::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_touch_of_the_magi_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 33395 Water Elemental's Freeze
class spell_mage_water_elemental_freeze : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_FINGERS_OF_FROST });
    }

    void HandleImprovedFreeze()
    {
        Unit* owner = GetCaster()->GetOwner();
        if (!owner)
            return;

        owner->CastSpell(owner, SPELL_MAGE_FINGERS_OF_FROST, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_mage_water_elemental_freeze::HandleImprovedFreeze);
    }
};

void AddSC_mage_spell_scripts()
{
    RegisterSpellScript(spell_mage_alter_time_aura);
    RegisterSpellScript(spell_mage_alter_time_active);
    RegisterSpellScript(spell_mage_arcane_barrage);
    RegisterSpellScript(spell_mage_arcane_charge_clear);
    RegisterSpellScript(spell_mage_arcane_explosion);
    RegisterSpellScript(spell_mage_blazing_barrier);
    RegisterAreaTriggerAI(areatrigger_mage_blizzard);
    RegisterSpellScript(spell_mage_blizzard_damage);
    RegisterSpellScript(spell_mage_burning_determination);
    RegisterSpellAndAuraScriptPair(spell_mage_cauterize, spell_mage_cauterize_AuraScript);
    RegisterSpellScript(spell_mage_cold_snap);
    RegisterSpellScript(spell_mage_comet_storm);
    RegisterSpellScript(spell_mage_comet_storm_damage);
    RegisterSpellScript(spell_mage_cone_of_cold);
    RegisterSpellScript(spell_mage_conjure_refreshment);
    RegisterSpellScript(spell_mage_ethereal_blink);
    RegisterSpellScript(spell_mage_ethereal_blink_triggered);
    RegisterSpellScript(spell_mage_feel_the_burn);
    RegisterSpellScript(spell_mage_fingers_of_frost);
    RegisterSpellScript(spell_mage_firestarter);
    RegisterSpellScript(spell_mage_firestarter_dots);
    RegisterSpellScript(spell_mage_flame_on);
    RegisterSpellScript(spell_mage_flurry);
    RegisterSpellScript(spell_mage_flurry_damage);
    RegisterSpellScript(spell_mage_frostbolt);
    RegisterSpellScript(spell_mage_hyper_impact);
    RegisterSpellScript(spell_mage_ice_barrier);
    RegisterSpellScript(spell_mage_ice_block);
    RegisterSpellScript(spell_mage_ice_lance);
    RegisterSpellScript(spell_mage_ice_lance_damage);
    RegisterSpellScript(spell_mage_ignite);
    RegisterSpellScript(spell_mage_imp_mana_gems);
    RegisterSpellScript(spell_mage_incanters_flow);
    RegisterSpellScript(spell_mage_living_bomb);
    RegisterSpellScript(spell_mage_living_bomb_explosion);
    RegisterSpellScript(spell_mage_living_bomb_periodic);
    RegisterSpellScript(spell_mage_polymorph_visual);
    RegisterSpellScript(spell_mage_prismatic_barrier);
    RegisterSpellScript(spell_mage_radiant_spark);
    RegisterSpellAndAuraScriptPair(spell_mage_ray_of_frost, spell_mage_ray_of_frost_aura);
    RegisterSpellScript(spell_mage_ring_of_frost);
    RegisterSpellAndAuraScriptPair(spell_mage_ring_of_frost_freeze, spell_mage_ring_of_frost_freeze_AuraScript);
    RegisterSpellScript(spell_mage_supernova);
    RegisterSpellScript(spell_mage_touch_of_the_magi_aura);
    RegisterSpellScript(spell_mage_water_elemental_freeze);
}
