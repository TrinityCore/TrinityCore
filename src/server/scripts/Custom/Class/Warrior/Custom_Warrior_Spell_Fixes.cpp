/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellScript.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "TaskScheduler.h"

#include <algorithm>
#include <vector>

#include "Custom_Warrior_Defines.h"

namespace Scripts::Custom::Warrior
{
    namespace WarriorThrowHelpers
    {
        bool AbsorbCanAffectSpell(AuraEffect const* aurEff, SpellInfo const* spellInfo)
        {
            if (!aurEff || !spellInfo)
                return false;

            uint32 absorbSchoolMask = uint32(aurEff->GetMiscValue());
            if (!absorbSchoolMask)
                return true;

            return (absorbSchoolMask & uint32(spellInfo->GetSchoolMask())) != 0;
        }

        void DamageAbsorbShields(Unit* target, SpellInfo const* spellInfo, int32 rawDamage, int32 bonusPct)
        {
            if (!target || !spellInfo || rawDamage <= 0 || bonusPct <= 0)
                return;

            std::vector<AuraEffect*> absorbEffects;
            int32 totalAbsorb = 0;

            Unit::AuraEffectList const& absorbs = target->GetAuraEffectsByType(SPELL_AURA_SCHOOL_ABSORB);
            for (AuraEffect const* aurEffConst : absorbs)
            {
                AuraEffect* aurEff = const_cast<AuraEffect*>(aurEffConst);
                if (!WarriorThrowHelpers::AbsorbCanAffectSpell(aurEff, spellInfo))
                    continue;

                int32 amount = aurEff->GetAmount();
                if (amount <= 0)
                    continue;

                absorbEffects.push_back(aurEff);
                totalAbsorb += amount;
            }

            if (totalAbsorb <= 0 || absorbEffects.empty())
                return;

            int32 absorbedPortion = std::min(totalAbsorb, rawDamage);
            int64 bonusShieldDamage = (int64(absorbedPortion) * int64(bonusPct)) / 100;
            if (bonusShieldDamage <= 0)
                return;

            std::vector<Aura*> aurasToRemove;

            for (AuraEffect* aurEff : absorbEffects)
            {
                if (!aurEff || bonusShieldDamage <= 0)
                    break;

                int32 currentAmount = aurEff->GetAmount();
                if (currentAmount <= 0)
                    continue;

                int32 reduction = int32(std::min<int64>(currentAmount, bonusShieldDamage));
                bonusShieldDamage -= reduction;

                int32 newAmount = currentAmount - reduction;
                if (newAmount <= 0)
                {
                    aurEff->ChangeAmount(0);

                    if (Aura* aura = aurEff->GetBase())
                        if (std::find(aurasToRemove.begin(), aurasToRemove.end(), aura) == aurasToRemove.end())
                            aurasToRemove.push_back(aura);
                }
                else
                    aurEff->ChangeAmount(newAmount);
            }

            for (Aura* aura : aurasToRemove)
                if (aura)
                    aura->Remove();
        }
    }

    // 18499 - Berserker Rage
    class spell_warr_berserker_rage : public SpellScript
    {

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::FEARLESS });
        }

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(Spells::FEARLESS))
                caster->RemoveMovementImpairingAuras(true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_warr_berserker_rage::HandleOnHit);
        }
    };

    // 262150 - Dreadnaught (attached to 7384 - Overpower)
    class spell_warr_dreadnaught : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellEffect({ { Spells::DREADNAUGHT_DAMAGE, EFFECT_0 }, { Spells::DREADNAUGHT_DAMAGE, EFFECT_1 } });
        }

        bool Load() override
        {
            return GetCaster()->HasAura(Spells::DREADNAUGHT);
        }

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Difficulty difficulty = caster->GetMap()->GetDifficultyID();
            SpellInfo const* damageInfo = sSpellMgr->GetSpellInfo(Spells::DREADNAUGHT_DAMAGE, difficulty);
            if (!damageInfo)
                return;

            SpellEffectInfo const& dmgEffect = damageInfo->GetEffect(EFFECT_0);
            float radius = dmgEffect.CalcRadius(caster).Max;

            std::list<Unit*> targets;
            auto work = [&](Unit* unit)
            {
                if (!caster->IsHostileTo(unit))
                    return;
                if (!unit->IsAlive())
                    return;
                if (!caster->isInFront(unit, float(M_PI) / 6.0f))
                    return;
                if (!caster->IsWithinDistInMap(unit, radius))
                    return;
                targets.push_back(unit);
            };
            Trinity::UnitWorker worker(caster, work);
            Cell::VisitAllObjects(caster, worker, radius);

            targets.sort(Trinity::ObjectDistanceOrderPred(caster, true));
            for (Unit* unit : targets)
            {
                caster->CastSpell(unit, Spells::DREADNAUGHT_DAMAGE, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                    .TriggeringSpell = GetSpell()
                });
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_warr_dreadnaught::HandleOnHit);
        }
    };

    // 845 - Cleave
    class spell_warr_cleave_dmg : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::CRUSHING_COMBO_BUFF });
        }

        void HandleOnHitTarget(SpellEffIndex /*effIndex*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
                if (caster->HasAura(Spells::FERVOR_OF_BATTLE))
                    if (Unit* target = caster->GetSelectedUnit())
                        if (caster->IsValidAttackTarget(target))
                            caster->CastSpell(target, Spells::SLAM_ARMS, true);
        }

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(Spells::CRUSHING_COMBO_BUFF))
            {
                caster->RemoveAuraFromStack(Spells::CRUSHING_COMBO_BUFF);
                caster->GetSpellHistory()->ResetCooldown(Spells::CLEAVE, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warr_cleave_dmg::HandleOnHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            AfterCast += SpellCastFn(spell_warr_cleave_dmg::HandleAfterCast);
        }
    };

    // Whirlwind - 190411
    class spell_warr_whirlwind : public SpellScript
    {
        void HandleAfterCast()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            if (caster->HasAura(Spells::WRECKING_BALL_EFFECT))
                caster->RemoveAura(Spells::WRECKING_BALL_EFFECT);

            if (caster->HasAura(Spells::MEAT_CLEAVER_TALENT))
                if (roll_chance(10))
                    caster->CastSpell(nullptr, Spells::ENRAGE, true);

            if (caster->HasAura(Spells::THIRST_FOR_BATTLE))
            {
                caster->AddAura(Spells::THIRST_FOR_BATTLE_BUFF, caster);
                if (AuraEffect* thirst = caster->GetAura(Spells::THIRST_FOR_BATTLE_BUFF)->GetEffect(0))
                    thirst->GetAmount();
            }

            caster->AddAura(Spells::WHIRLWIND_CLEAVE_AURA, caster);

            if (caster->HasAura(Spells::IMPROVED_WHIRLWIND))
            {
                if (_targetCount == 0)
                {
                    caster->ModifyPower(POWER_RAGE, 30);
                }
                else if (_targetCount <= 5)
                {
                    caster->ModifyPower(POWER_RAGE, _power * 10 + 30);
                }
                else if (_targetCount >= 5)
                {
                    caster->ModifyPower(POWER_RAGE, 80);
                }
            }
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            ++_targetCount;
            ++_power;

            Unit* caster = GetCaster();

            if (!caster)
                return;

            bool improvedWhirlwind = caster->HasAura(Spells::IMPROVED_WHIRLWIND);
            bool hasRend = GetCaster()->HasSpell(Spells::REND);

            if (hasRend && improvedWhirlwind)
            {
                GetCaster()->CastSpell(GetHitUnit(), Spells::REND_AURA, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
                    });
            }
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_warr_whirlwind::HandleAfterCast);
            OnEffectHitTarget += SpellEffectFn(spell_warr_whirlwind::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

        uint32 _power = 0;
        uint32 _targetCount = 0;
    };

    // 1680 Whirlwind
    class spell_warr_whirlwind_dmg : public SpellScript
    {
        void HandleOnHitTarget(SpellEffIndex /*effIndex*/)
        {
            if (Player* caster = GetCaster()->ToPlayer())
                if (caster->HasAura(Spells::FERVOR_OF_BATTLE))
                    if (Unit* target = caster->GetSelectedUnit())
                        if (caster->IsValidAttackTarget(target))
                            caster->CastSpell(target, Spells::SLAM_ARMS, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warr_whirlwind_dmg::HandleOnHitTarget, EFFECT_0, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    // 394354 - Wrecking Throw Damage
    class spell_warr_wrecking_throw_damage : public SpellScript
    {
        void HandleAbsorbShieldDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            int32 rawDamage = GetHitDamage();
            if (rawDamage <= 0)
                rawDamage = GetEffectInfo(EFFECT_0).CalcValue(caster);

            if (rawDamage <= 0)
                return;

            int32 bonusPct = GetEffectInfo(EFFECT_2).CalcValue(caster);
            WarriorThrowHelpers::DamageAbsorbShields(target, GetSpellInfo(), rawDamage, bonusPct);
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_warr_wrecking_throw_damage::HandleAbsorbShieldDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 871 - Shield Wall
    class spell_warr_shield_wall : public AuraScript
    {
        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            if (caster->HasAura(Spells::UNBREAKABLE_WILL))
                caster->CastSpell(caster, Spells::UNBREAKABLE_WILL_PROC, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_warr_shield_wall::HandleApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    // 772 - Rend
    class spell_warr_rend : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::REND_AURA });
        }

        void HandleRend(SpellEffIndex /*effIndex*/) const
        {
            GetCaster()->CastSpell(GetHitUnit(), Spells::REND_AURA, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
                });
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_warr_rend::HandleRend, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 386208 - Defensive Stance
    class spell_warr_defensive_stance : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::DEFENSIVE_STANCE, Spells::DEFENSIVE_STANCE_SPIKE_TALENT });
        }

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            _absorbAmount = std::max(int32(1), aurEff->GetAmountAsInt());
            const_cast<AuraEffect*>(aurEff)->SetAmount(_absorbAmount);
        }

        void HandleAbsorb(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
        {
            absorbAmount = 0;
            PreventDefaultAction();
            aurEff->SetAmount(_absorbAmount);
        }

        int32 _absorbAmount = 0;

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return eventInfo.GetDamageInfo() != nullptr && eventInfo.GetDamageInfo()->GetDamage() > 0;
        }

        void PrepareProc(ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();
        }

        void HandleProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            DamageInfo* damageInfo = eventInfo.GetDamageInfo();
            uint32 damageTaken = damageInfo->GetDamage();

            if (caster->HasAura(Spells::DEFENSIVE_STANCE_SPIKE_TALENT))
            {
                AuraEffect const* thresholdEff = GetEffect(EFFECT_4);
                AuraEffect const* reductionEff = GetEffect(EFFECT_5);
                if (thresholdEff && reductionEff)
                {
                    float thresholdPct = float(thresholdEff->GetAmount());
                    float reductionPct = float(reductionEff->GetAmount());
                    uint32 maxHealth = caster->GetMaxHealth();
                    if (maxHealth > 0 && float(damageTaken) >= CalculatePct(float(maxHealth), thresholdPct))
                    {
                        uint32 absorbAmount = uint32(CalculatePct(float(damageTaken), reductionPct));
                        if (absorbAmount > 0)
                            damageInfo->AbsorbDamage(absorbAmount);
                    }
                }
            }

            damageTaken = damageInfo->GetDamage();
            if (damageTaken > 0)
            {
                int32 rageAmount = int32((50.0f * float(damageTaken)) / float(caster->GetMaxHealth()));
                if (rageAmount > 0)
                    caster->ModifyPower(POWER_RAGE, 10 * rageAmount);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_warr_defensive_stance::OnApply, EFFECT_FIRST_FOUND, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_warr_defensive_stance::HandleAbsorb, EFFECT_FIRST_FOUND);
            DoCheckProc += AuraCheckProcFn(spell_warr_defensive_stance::CheckProc);
            DoPrepareProc += AuraProcFn(spell_warr_defensive_stance::PrepareProc);
            OnProc += AuraProcFn(spell_warr_defensive_stance::HandleProc);
        }
    };

    // 29838 - Second Wind
    class spell_warr_second_wind_proc : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::SECOND_WIND_2PC, Spells::SECOND_WIND_6PC });
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            target->CastSpell(target, Spells::SECOND_WIND_6PC, true);
        }

        void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            if (DamageInfo const* dmgInfo = eventInfo.GetDamageInfo())
            {
                if (dmgInfo->GetDamage() <= 0)
                    return;

                target->RemoveAura(Spells::SECOND_WIND_6PC);

                if (target->HealthBelowPct(35) && !target->HasAura(Spells::SECOND_WIND_2PC))
                    target->CastSpell(target, Spells::SECOND_WIND_2PC, true);

                _lastDamageTime = getMSTime();
            }
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            if (GetMSTimeDiffToNow(_lastDamageTime) < 5000)
                return;

            if (!target->HasAura(Spells::SECOND_WIND_6PC))
                target->CastSpell(target, Spells::SECOND_WIND_6PC, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_warr_second_wind_proc::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectProc += AuraEffectProcFn(spell_warr_second_wind_proc::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_second_wind_proc::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }

        uint32 _lastDamageTime = 0;
    };

    // 202147 - Second Wind (6% no-damage heal)
    class spell_warr_second_wind_6pc : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::SECOND_WIND_2PC });
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            if (target->HealthBelowPct(35) && !target->HasAura(Spells::SECOND_WIND_2PC))
                target->CastSpell(target, Spells::SECOND_WIND_2PC, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_second_wind_6pc::OnPeriodic, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
        }
    };

    // 458245 - Second Wind (2% low-HP scaling heal)
    class spell_warr_second_wind_2pc : public AuraScript
    {
        void CalculateAmount(AuraEffect const* /*aurEff*/, SpellEffectValue& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;

            Unit* target = GetUnitOwner();
            if (!target)
                return;

            float hpPct = target->GetHealthPct();

            if (hpPct <= 2.0f)
            {
                amount = 6.0;
                return;
            }

            if (hpPct <= 4.0f)
            {
                amount = 4.0 + (4.0f - hpPct);
                return;
            }

            amount = 2.0 + (35.0f - hpPct) * 2.0f / 31.0f;
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetUnitOwner();
            if (!target)
                return;

            if (target->GetHealthPct() > 35.0f)
            {
                PreventDefaultAction();
                GetAura()->SetDuration(0);
            }
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warr_second_wind_2pc::CalculateAmount, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_second_wind_2pc::OnPeriodic, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
        }
    };

    // 202095 - Indomitable
    class spell_warr_indomitable : public AuraScript
    {
        bool Validate(SpellInfo const* spellInfo) override
        {
            return ValidateSpellInfo({ Spells::INDOMITABLE_HEAL })
                && ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 }, { spellInfo->Id, EFFECT_1 } })
                && spellInfo->GetEffect(EFFECT_0).IsAura()
                && spellInfo->GetEffect(EFFECT_1).IsAura();
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Spell const* procSpell = eventInfo.GetProcSpell();
            if (!procSpell)
                return false;

            _rageAccumulator += procSpell->GetPowerTypeCostAmount(POWER_RAGE).value_or(0);
            return _rageAccumulator >= GetEffect(EFFECT_1)->GetAmount();
        }

        void HandleProc(ProcEventInfo const& /*eventInfo*/)
        {
            Unit* target = GetTarget();

            int32 threshold = GetEffect(EFFECT_1)->GetAmount();
            if (threshold <= 0)
                return;

            int32 healPct = GetEffect(EFFECT_0)->GetAmount() / 10;
            AuraEffect const* aurEff = GetEffect(EFFECT_0);

            while (_rageAccumulator >= threshold)
            {
                _rageAccumulator -= threshold;

                target->CastSpell(target, Spells::INDOMITABLE_HEAL,
                    CastSpellExtraArgs()
                        .SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR)
                        .SetTriggeringAura(aurEff)
                        .AddSpellMod(SPELLVALUE_BASE_POINT0, healPct));
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_warr_indomitable::CheckProc);
            OnProc += AuraProcFn(spell_warr_indomitable::HandleProc);
        }

    private:
        int32 _rageAccumulator = 0;
    };

    // 376079 - Champion's Spear
    struct at_warr_champions_spear : AreaTriggerAI
    {
        using AreaTriggerAI::AreaTriggerAI;

        void OnCreate(Spell const* /*creatingSpell*/) override
        {
            _scheduler.Schedule(1s, [this](TaskContext task)
            {
                Unit* caster = at->GetCaster();
                if (!caster)
                {
                    task.Repeat(1s);
                    return;
                }

                Position const center = at->GetPosition();

                for (ObjectGuid const& guid : at->GetInsideUnits())
                {
                    Unit* unit = ObjectAccessor::GetUnit(*at, guid);
                    if (!unit)
                        continue;

                    if (!unit->HasAura(Spells::CHAMPIONS_SPEAR_AURA, caster->GetGUID()))
                        continue;

                    unit->CastSpell(center, Spells::CHAMPIONS_SPEAR_PULL,
                        CastSpellExtraArgsInit{
                            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                        });

                    unit->CastSpell(center, Spells::CHAMPIONS_SPEAR_CHAIN_VISUAL,
                        CastSpellExtraArgsInit{
                            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                        });
                }

                task.Repeat(1s);
            });
        }

        void OnUpdate(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    // 202316 - Fervor of Battle
    class spell_warr_fervor_of_battle : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::SLAM_ARMS, Spells::FERVOR_OF_BATTLE });
        }

        void HandleSlam(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster || !caster->HasAura(Spells::FERVOR_OF_BATTLE))
                return;

            SpellInfo const* fervorInfo = sSpellMgr->GetSpellInfo(Spells::FERVOR_OF_BATTLE, GetCastDifficulty());
            int32 fervorBP0 = fervorInfo->GetEffect(EFFECT_0).CalcValue(caster);

            int64 const targetsHit = GetUnitTargetCountForEffect(EFFECT_0);
            if (targetsHit < fervorBP0)
                return;

            Unit* target = GetExplTargetUnit();
            caster->CastSpell(target, Spells::SLAM_ARMS, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS
                              | TRIGGERED_DONT_REPORT_CAST_ERROR
                              | TRIGGERED_IGNORE_POWER_COST
                              | TRIGGERED_CAST_DIRECTLY,
                .TriggeringSpell = GetSpell()
            });
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_warr_fervor_of_battle::HandleSlam, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 228920 - Ravager
    class spell_warr_ravager : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RAVAGER_SUMMON });
        }

        void SummonRavager(SpellEffIndex /*effIndex*/) const
        {
            GetCaster()->CastSpell(*GetHitDest(), Spells::RAVAGER_SUMMON, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_warr_ravager::SummonRavager, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    // 228920 - Ravager - Periodic AuraScript
    class spell_warr_ravager_aurascript : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RAVAGER_PERIODIC_DAMAGE })
                && ValidateSpellEffect({ { Spells::RAVAGER_SUMMON, EFFECT_0 } });
        }

        std::vector<Unit*> FindRavagerSummons(Unit const* owner) const
        {
            std::vector<Unit*> summons;
            int32 const summonedCreatureEntry = sSpellMgr->GetSpellInfo(Spells::RAVAGER_SUMMON, GetCastDifficulty())->GetEffect(EFFECT_0).MiscValue;
            for (Unit* summon : owner->m_Controlled)
                if (summon->GetEntry() == static_cast<uint32>(summonedCreatureEntry))
                    summons.push_back(summon);

            return summons;
        }

        void HandlePeriodic(AuraEffect const* /*auraEffect*/) const
        {
            std::vector<Unit*> const ravagers = FindRavagerSummons(GetTarget());
            for (Unit* ravager : ravagers)
            {
                GetTarget()->CastSpell(ravager->GetWorldLocation(), Spells::RAVAGER_PERIODIC_DAMAGE, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                });

                ravager->SendPlaySpellVisual(ravager->GetPosition(), Spells::SPELL_VISUAL_RAVAGER, 0, 0, 0, true, 0);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warr_ravager_aurascript::HandlePeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    // 156287 - Ravager (damage)
    class spell_warr_ravager_damage_rage_gain : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RAVAGER_RAGE_GAIN });
        }

        void HandleRavagerDamage() const
        {
            GetCaster()->CastSpell(nullptr, Spells::RAVAGER_RAGE_GAIN, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_warr_ravager_damage_rage_gain::HandleRavagerDamage);
        }
    };

    // 394352 - Shattering Throw Damage
    class spell_warr_shattering_throw_damage : public SpellScript
    {
        void HandleAbsorbShieldDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            int32 rawDamage = GetHitDamage();
            if (rawDamage <= 0)
                rawDamage = GetEffectInfo(EFFECT_0).CalcValue(caster);

            if (rawDamage <= 0)
                return;

            int32 bonusPct = GetEffectInfo(EFFECT_2).CalcValue(caster);
            WarriorThrowHelpers::DamageAbsorbShields(target, GetSpellInfo(), rawDamage, bonusPct);
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (Player* player = caster->ToPlayer())
                if (player->GetPrimarySpecialization() == ChrSpecialization::WarriorFury)
                    SetHitDamage(int32(GetHitDamage() * 1.2f));
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_warr_shattering_throw_damage::HandleAbsorbShieldDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnEffectHitTarget += SpellEffectFn(spell_warr_shattering_throw_damage::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };
}

void AddSC_custom_warrior_spell_fixes()
{
    using namespace Scripts::Custom::Warrior;

    RegisterAreaTriggerAI(at_warr_champions_spear);

    RegisterSpellScript(spell_warr_berserker_rage);
    RegisterSpellScript(spell_warr_dreadnaught);
    RegisterSpellScript(spell_warr_cleave_dmg);
    RegisterSpellScript(spell_warr_whirlwind);
    RegisterSpellScript(spell_warr_whirlwind_dmg);
    RegisterSpellScript(spell_warr_wrecking_throw_damage);
    RegisterSpellScript(spell_warr_shield_wall);
    RegisterSpellScript(spell_warr_rend);
    RegisterSpellScript(spell_warr_defensive_stance);
    RegisterSpellScript(spell_warr_second_wind_proc);
    RegisterSpellScript(spell_warr_second_wind_6pc);
    RegisterSpellScript(spell_warr_second_wind_2pc);
    RegisterSpellScript(spell_warr_indomitable);
    RegisterSpellScript(spell_warr_fervor_of_battle);
    RegisterSpellAndAuraScriptPair(spell_warr_ravager, spell_warr_ravager_aurascript);
    RegisterSpellScript(spell_warr_ravager_damage_rage_gain);
    RegisterSpellScript(spell_warr_shattering_throw_damage);
}
