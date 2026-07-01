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

#include "AreaTriggerAI.h"
#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Pet.h"
#include "ObjectAccessor.h"

#include "Custom_Mage_Defines.h"

namespace Scripts::Custom::Mage
{
    // Returns the Freeze mastery bonus % (EFFECT_0) from 1246752, or 0 if not present
    static float GetMasteryFreezeBonus(Unit const* caster)
    {
        if (AuraEffect const* mastery = caster->GetAuraEffect(Spells::MasteryFreezeShatter, EFFECT_0))
            return mastery->GetAmount();
        return 0.0f;
    }

    // Returns the Shatter mastery bonus % (EFFECT_1) from 1246752, or 0 if not present
    static float GetMasteryShatterBonus(Unit const* caster)
    {
        if (AuraEffect const* mastery = caster->GetAuraEffect(Spells::MasteryFreezeShatter, EFFECT_1))
            return mastery->GetAmount();
        return 0.0f;
    }

    // 263725 - Clearcasting Proc
    class aura_mage_clearcasting_proc : public AuraScript
    {
        bool CheckProc(ProcEventInfo& eventInfo)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return false;

            if (eventInfo.GetSpellInfo()->Id == Spells::ArcaneExplosion || eventInfo.GetSpellInfo()->Id == Spells::ArcaneMissiles)
            {
                if (!caster->HasAura(Spells::ConcentrationBuff))
                {
                    if (GetStackAmount() > 1)
                        ModStackAmount(-1);
                    else
                        return true;
                }

            }

            return false;
        }
        void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            Remove();
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(aura_mage_clearcasting_proc::CheckProc);
            OnEffectProc += AuraEffectProcFn(aura_mage_clearcasting_proc::HandleProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
        }
    };

    // 12654 - Ignite DOT
    class spell_mage_ignite_periodic : public AuraScript
    {
        void CalculateRefreshedDot(AuraEffect const* /*aurEff*/, SpellEffectValue& amount, bool& canBeRecalculated)
        {
            canBeRecalculated = false;
            _critDamageValues.emplace_back(std::make_pair(2, amount));

            amount = 0;
            for (auto const& damageValuePair : _critDamageValues)
                amount += damageValuePair.second;
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            int32 newDotValue = 0;
            bool changed = false;
            for (std::vector<std::pair<uint8, int32>>::iterator itr = _critDamageValues.begin(); itr != _critDamageValues.end();)
            {
                --itr->first;
                newDotValue += itr->second;
                if (itr->first == 0)
                {
                    itr = _critDamageValues.erase(itr);
                    changed = true;
                }
                else
                    ++itr;
            }

            if (changed)
                const_cast<AuraEffect*>(aurEff)->SetAmount(newDotValue);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_ignite_periodic::CalculateRefreshedDot, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_ignite_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }

    private:
        std::vector<std::pair<uint8, int32>> _critDamageValues;
    };

    // 84714 - Frozen Orb (cast) - Manually spawn AreaTrigger at caster position
    class spell_mage_frozen_orb : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::FrozenOrbDamage });
        }

        SpellCastResult CheckCast()
        {
            return SPELL_CAST_OK; // No target required
        }

        void CaptureCasterPosition()
        {
            // Capture BEFORE the engine rotates caster toward the target
            Unit* caster = GetCaster();
            if (caster)
                _spawnPos = caster->GetPosition(); // full Position including orientation
        }

        void HandleCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            // Remove the DBC aura that was just applied to the caster - it creates a caster-attached AT
            // that applies Chilled to nearby enemies as the player moves. Our custom AT handles this.
            caster->RemoveAurasDueToSpell(Spells::FrozenOrb);

            AreaTriggerCreatePropertiesId createPropertiesId(70001, true);
            AreaTrigger::CreateAreaTrigger(createPropertiesId, _spawnPos, 15000, caster, nullptr, { 0, 0 }, nullptr, GetSpell());

            // 385167 - Everlasting Frost: casting Frozen Orb grants EFFECT_0 stacks of Fingers of Frost
            if (AuraEffect const* evFrost = caster->GetAuraEffect(Spells::EverlastingFrost, EFFECT_0))
            {
                int32 stacks = evFrost->GetAmount();
                for (int32 i = 0; i < stacks; ++i)
                    caster->CastSpell(caster, Spells::FingersOfFrost, true);
            }

            // 460590 - Permafrost Lances: Frozen Orb increases Shatter damage by 10% for its duration (15s)
            if (caster->HasAura(Spells::PermafrostLances))
            {
                caster->RemoveAurasDueToSpell(Spells::PermafrostLancesBuff);
                if (Aura* buff = caster->AddAura(Spells::PermafrostLancesBuff, caster))
                {
                    buff->SetDuration(15000);
                    buff->SetMaxDuration(15000);
                }
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_mage_frozen_orb::CheckCast);
            BeforeCast += SpellCastFn(spell_mage_frozen_orb::CaptureCasterPosition);
            AfterCast += SpellCastFn(spell_mage_frozen_orb::HandleCast);
        }

    private:
        Position _spawnPos;
    };

    // 84714 - Frozen Orb AreaTrigger
    // AreaTrigger that spawns at caster, moves forward, then homes in on nearest enemy
    struct at_mage_frozen_orb : public AreaTriggerAI
    {
        using AreaTriggerAI::AreaTriggerAI;

        void OnInitialize() override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            _casterOrientation = caster->GetOrientation();

            // Use GetFirstCollisionPosition like other projectile ATs (monk, DH) - angle 0 = straight forward
            Position destPos = at->GetFirstCollisionPosition(40.0f, 0.0f);

            PathGenerator firstPath(at);
            firstPath.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);
            at->InitSplines(firstPath.GetPath(), 8.0f);
        }

        void OnCreate(Spell const* /*creatingSpell*/) override
        {
            // After 1 second, start homing in on nearest enemy
            // 200ms grace period before first path recalc to avoid speed spike from forward spline transition
            _scheduler.Schedule(1s, [this](TaskContext& /*task*/)
                {
                    _isHoming = true;
                    _scheduler.Schedule(200ms, [this](TaskContext& innerTask)
                        {
                            UpdateMovement();
                            innerTask.Repeat(500ms);
                        });
                });

            // Periodic damage every 750ms (20 ticks over 15 seconds) - cast FROM the AT itself so dest targeting works correctly
            _scheduler.Schedule(750ms, [this](TaskContext& task)
                {
                    if (at->GetCaster())
                    {
                        CastSpellExtraArgs args(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                        args.SetOriginalCaster(at->GetCasterGuid());
                        at->CastSpell(at->GetPosition(), Spells::FrozenOrbDamage, args);
                    }
                    task.Repeat(750ms);
                });
        }

        void OnUpdate(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

        void UpdateMovement()
        {
            if (!_isHoming)
                return;

            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            // Find nearest enemy within 60 yards
            Unit* target = nullptr;
            float minDist = 60.0f;

            std::list<Unit*> targets;
            Trinity::AnyUnfriendlyUnitInObjectRangeCheck check(at, caster, 60.0f);
            Trinity::UnitListSearcher searcher(at, targets, check);
            Cell::VisitAllObjects(at, searcher, 60.0f);

            for (Unit* unit : targets)
            {
                if (!unit->IsAlive())
                    continue;
                if (!caster->IsInCombatWith(unit))
                    continue;
                float dist = at->GetDistance2d(unit);
                if (dist < minDist)
                {
                    minDist = dist;
                    target = unit;
                }
            }

            if (!target)
                return;

            // Update path to target
            at->SetPathTarget(target->GetGUID());

            if (at->IsInDist2d(target, 0.5f))
                return;

            PathGenerator path(at);
            path.CalculatePath(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), false);
            at->InitSplines(path.GetPath(), 2.5f);
        }

    private:
        TaskScheduler _scheduler;
        bool _isHoming = false;
        float _casterOrientation = 0.0f;
    };

    // 84721 - Frozen Orb (damage)
// Applies Chilled slow debuff to damaged targets
    class spell_mage_frozen_orb_damage : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::Chilled, Spells::FingersOfFrost, Spells::EverlastingFrost });
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            // Retail: damage is reduced by 10% for each target hit beyond 8
            _targetCount = uint32(targets.size());
        }

        void HandleLaunch(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetOriginalCaster(); // AT casts this; original caster is the mage
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            // Guard: only damage valid attack targets
            if (!caster->IsValidAttackTarget(target, GetSpellInfo()))
            {
                SetEffectValue(0);
                return;
            }

            // DBC Coefficient is 0; we apply SP scaling manually here
            int32 spellPower = caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FROST);
            float damage = 75.0f + spellPower * 0.408f;

            // Mastery: Freeze and Shatter (1246752) EFFECT_0 - Freeze group bonus
            AddPct(damage, GetMasteryFreezeBonus(caster));

            // Retail: 10% reduction per target hit beyond 8
            if (_targetCount > 8)
            {
                float reduction = 1.0f - 0.1f * float(_targetCount - 8);
                if (reduction < 0.0f) reduction = 0.0f;
                damage *= reduction;
            }

            SetEffectValue(int32(damage));
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetOriginalCaster(); // original caster is the mage
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            if (!caster->IsValidAttackTarget(target, GetSpellInfo()))
                return;

            caster->CastSpell(target, Spells::Chilled, TRIGGERED_IGNORE_CAST_IN_PROGRESS);

            // 385167 - Everlasting Frost: EFFECT_1% chance to grant Fingers of Frost on Frozen Orb damage
            if (AuraEffect const* evFrost = caster->GetAuraEffect(Spells::EverlastingFrost, EFFECT_1))
                if (roll_chance(evFrost->GetAmount()))
                    caster->CastSpell(caster, Spells::FingersOfFrost, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_frozen_orb_damage::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectLaunchTarget += SpellEffectFn(spell_mage_frozen_orb_damage::HandleLaunch, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnEffectHitTarget += SpellEffectFn(spell_mage_frozen_orb_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    private:
        uint32 _targetCount = 0;
    };

    // 235219 - Cold Snap
    // Resets cooldown of Ice Barrier, Frost Nova, Cone of Cold, Ice Cold, and Ice Block
    class spell_mage_cold_snap_custom : public SpellScript
    {
        static uint32 constexpr SpellsToReset[] =
        {
            Spells::IceBarrier,
            Spells::FrostNova,
            Spells::ConeOfCold,
            Spells::IceCold,
            Spells::IceBlock,
        };

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(SpellsToReset);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            for (uint32 spellId : SpellsToReset)
            {
                caster->GetSpellHistory()->ResetCooldown(spellId, true);
                if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, GetCastDifficulty()))
                    if (spellInfo->ChargeCategoryId)
                        caster->GetSpellHistory()->RestoreCharge(spellInfo->ChargeCategoryId);
            }
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_mage_cold_snap_custom::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    // 112965 - Fingers of Frost
    // Base 15% chance on Frostbolt to grant Fingers of Frost.
    // Frozen Touch (205030) adds its EFFECT_0 value to this chance.
    class spell_mage_fingers_of_frost_custom : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::FingersOfFrost, Spells::FrozenTouch });
        }

        bool CheckFrostboltProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetSpellInfo() || !eventInfo.GetSpellInfo()->IsAffected(SPELLFAMILY_MAGE, flag128(0, 0x2000000, 0, 0)))
                return false;

            int32 chance = aurEff->GetAmount();
            if (AuraEffect const* frozenTouch = GetTarget()->GetAuraEffect(Spells::FrozenTouch, EFFECT_0))
                chance += frozenTouch->GetAmount();

            return roll_chance(chance);
        }

        void Trigger(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            eventInfo.GetActor()->CastSpell(GetTarget(), Spells::FingersOfFrost, aurEff);
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_mage_fingers_of_frost_custom::CheckFrostboltProc, EFFECT_0, SPELL_AURA_DUMMY);
            AfterEffectProc += AuraEffectProcFn(spell_mage_fingers_of_frost_custom::Trigger, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    // Track Brain Freeze boosted Flurry casts by OriginalCastId (workaround for aura interrupt issues)
    // Key = Flurry(44614) CastId, Value = pending missiles for that Flurry cast
    static std::unordered_map<ObjectGuid, int32> g_BrainFreezePendingMissiles;

    // Translation map: 228596's CastId -> Flurry's CastId (so 228354 can find its counter)
    static std::unordered_map<ObjectGuid, ObjectGuid> g_BrainFreezeCastIdChain;

    // 44614 - Flurry (cast) - Manual missile control
    class spell_mage_flurry_custom : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::FlurryDamage, Spells::FlurryMissileDamage, 1247769, Spells::BrainFreezeBuff });
        }

        void HandleBeforeCast()
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if (!caster || !target)
                return;

            // Determine number of missiles: 3 base, 4 with talent
            int32 numMissiles = caster->HasAura(1247769) ? 4 : 3;

            // Brain Freeze: check for buff and track via OriginalCastId (workaround for aura interrupt issues)
            ObjectGuid castId = GetSpell()->m_castId;
            if (Aura* brainFreeze = caster->GetAura(Spells::BrainFreezeBuff))
            {
                g_BrainFreezePendingMissiles[castId] = numMissiles;
                caster->RemoveAura(brainFreeze); // Remove immediately so it doesn't get interrupted
            }
            else
            {
                g_BrainFreezePendingMissiles.erase(castId);
            }

            // Cast first missile immediately
            ObjectGuid flurryCastId = GetSpell()->m_castId;
            auto args1 = CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS).SetOriginalCastId(flurryCastId);
            caster->CastSpell(target, Spells::FlurryDamage, args1);

            // Schedule remaining missiles with delays
            for (int32 i = 1; i < numMissiles; ++i)
            {
                Milliseconds delay = randtime(300ms, 400ms) * i;
                ObjectGuid targetGuid = target->GetGUID();
                ObjectGuid castId = GetSpell()->m_castId;
                caster->m_Events.AddEventAtOffset([caster, targetGuid, castId]
                    {
                        if (Unit* target = ObjectAccessor::GetUnit(*caster, targetGuid))
                        {
                            auto args = CastSpellExtraArgs(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR).SetOriginalCastId(castId);
                            caster->CastSpell(target, Spells::FlurryDamage, args);
                        }
                    }, delay);
            }
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_mage_flurry_custom::HandleBeforeCast);
        }
    };

    // 228596 - Flurry (damage) - Captures Brain Freeze state from parent Flurry cast
    class spell_mage_flurry_damage_spell : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::FlurryMissileDamage, Spells::BrainFreezeBuff });
        }

        void HandleCast()
        {
            // Check if our originalCastId (Flurry's CastId) has a Brain Freeze entry
            ObjectGuid flurryCastId = GetSpell()->m_originalCastId;
            ObjectGuid myCastId = GetSpell()->m_castId;

            auto it = g_BrainFreezePendingMissiles.find(flurryCastId);
            if (it != g_BrainFreezePendingMissiles.end())
                g_BrainFreezeCastIdChain[myCastId] = flurryCastId;
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_mage_flurry_damage_spell::HandleCast);
        }
    };

    // 228354 - Flurry (actual missile damage spell)
    class spell_mage_flurry_missile_damage : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::Freezing, Spells::ShatterPassive, Spells::BrainFreezeBuff });
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            // Apply Freezing on every missile hit when Shatter passive is present
            if (caster->HasAura(Spells::ShatterPassive))
                caster->CastSpell(target, Spells::Freezing, true);

            // Mastery: Freeze and Shatter (1246752) EFFECT_0 - Freeze group bonus
            if (float masteryPct = GetMasteryFreezeBonus(caster))
            {
                int32 dmg = GetHitDamage();
                AddPct(dmg, masteryPct);
                SetHitDamage(dmg);
            }

            // Piercing Cold (378919): +20% extra crit damage for Flurry missiles.
            // GetHitDamage() is pre-crit here (OnEffectHitTarget fires before CalculateSpellDamageTaken).
            // Add amount/2% now so after engine's *2 crit: net extra = amount% of base.
            if (IsHitCrit())
                if (AuraEffect const* piercingCold = caster->GetAuraEffect(Spells::PiercingCold, EFFECT_0))
                {
                    int32 dmg = GetHitDamage();
                    dmg += CalculatePct(dmg, piercingCold->GetAmount() / 2.0f);
                    SetHitDamage(dmg);
                }

            // Brain Freeze: +50% damage per missile if this cast had the buff
            ObjectGuid damageSpellCastId = GetSpell()->m_originalCastId;

            auto chainIt = g_BrainFreezeCastIdChain.find(damageSpellCastId);
            if (chainIt == g_BrainFreezeCastIdChain.end())
                return;

            ObjectGuid flurryCastId = chainIt->second;

            auto it = g_BrainFreezePendingMissiles.find(flurryCastId);
            if (it == g_BrainFreezePendingMissiles.end() || it->second <= 0)
                return;

            int32 currentDamage = GetHitDamage();
            SetHitDamage(currentDamage + currentDamage / 2); // +50%

            it->second--; // Consume one missile
            if (it->second <= 0)
            {
                g_BrainFreezePendingMissiles.erase(it);
                g_BrainFreezeCastIdChain.erase(chainIt);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_flurry_missile_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 228597 - Frostbolt (damage component)
    class spell_mage_frostbolt_damage : public SpellScript
    {
        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ Spells::PiercingCold });
        }

        void HandlePiercingCold(SpellEffIndex /*effIndex*/)
        {
            if (!IsHitCrit())
                return;
            Unit* caster = GetCaster();
            if (AuraEffect const* piercingCold = caster->GetAuraEffect(Spells::PiercingCold, EFFECT_0))
            {
                // GetHitDamage() is pre-crit (OnEffectHitTarget fires before CalculateSpellDamageTaken).
                // Adding amount/2% pre-crit: after engine *2 = base*(1+X/200)*2 = base*2 + base*(X/100) = +X% of base extra.
                int32 dmg = GetHitDamage();
                dmg += CalculatePct(dmg, piercingCold->GetAmount() / 2.0f);
                SetHitDamage(dmg);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_frostbolt_damage::HandlePiercingCold, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };
}

void AddSC_custom_mage_spell_fixes()
{
    using namespace Scripts::Custom::Mage;

    RegisterAreaTriggerAI(at_mage_frozen_orb);

    RegisterSpellScript(aura_mage_clearcasting_proc);
    RegisterSpellScript(spell_mage_cold_snap_custom);
    RegisterSpellScript(spell_mage_fingers_of_frost_custom);
    RegisterSpellScript(spell_mage_frozen_orb);
    RegisterSpellScript(spell_mage_frozen_orb_damage);
    RegisterSpellScript(spell_mage_ignite_periodic);
    RegisterSpellScript(spell_mage_flurry_custom);
    RegisterSpellScript(spell_mage_flurry_damage_spell);
    RegisterSpellScript(spell_mage_flurry_missile_damage);
    RegisterSpellScript(spell_mage_frostbolt_damage);
}
