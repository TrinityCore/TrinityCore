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

#ifndef TRINITY_SPELLAURAEFFECTS_H
#define TRINITY_SPELLAURAEFFECTS_H

#include "SpellAuras.h"

class AuraEffect;
class Unit;
class WorldObject;

typedef void(AuraEffect::*pAuraEffectHandler)(AuraApplication const* aurApp, uint8 mode, bool apply) const;

class TC_GAME_API AuraEffect
{
    friend void Aura::_InitEffects(uint32 effMask, Unit* caster, int32 const* baseAmount);
    friend Aura::~Aura();
    friend class Unit;

    private:
        ~AuraEffect();
        explicit AuraEffect(Aura* base, SpellEffectInfo const& spellEfffectInfo, int32 const* baseAmount, Unit* caster);

    public:
        Unit* GetCaster() const { return GetBase()->GetCaster(); }
        ObjectGuid GetCasterGUID() const { return GetBase()->GetCasterGUID(); }
        Aura* GetBase() const { return m_base; }

        template <typename Container>
        void GetTargetList(Container& targetContainer) const;

        template <typename Container>
        void GetApplicationList(Container& applicationContainer) const;

        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        uint32 GetId() const { return m_spellInfo->Id; }
        SpellEffIndex GetEffIndex() const { return m_effectInfo.EffectIndex; }
        int32 GetBaseAmount() const { return m_baseAmount; }
        int32 GetPeriod() const { return _period; }

        int32 GetMiscValueB() const { return GetSpellEffectInfo().MiscValueB; }
        int32 GetMiscValue() const { return GetSpellEffectInfo().MiscValue; }
        AuraType GetAuraType() const { return GetSpellEffectInfo().ApplyAuraName; }
        int32 GetAmount() const { return _amount; }
        void SetAmount(int32 amount) { _amount = amount; m_canBeRecalculated = false; }

        Optional<float> GetEstimatedAmount() const { return _estimatedAmount; }

        int32 GetPeriodicTimer() const { return _periodicTimer; }
        void SetPeriodicTimer(int32 periodicTimer) { _periodicTimer = periodicTimer; }

        int32 CalculateAmount(Unit* caster);
        static Optional<float> CalculateEstimatedAmount(Unit const* caster, Unit* target, SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, int32 amount, uint8 stack, AuraEffect const* aurEff);
        Optional<float> CalculateEstimatedAmount(Unit const* caster, int32 amount) const;
        static float CalculateEstimatedfTotalPeriodicAmount(Unit* caster, Unit* target, SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, float amount, uint8 stack);
        void CalculatePeriodic(Unit* caster, bool resetPeriodicTimer = true, bool load = false);
        void CalculateSpellMod();
        void ChangeAmount(int32 newAmount, bool mark = true, bool onStackOrReapply = false, AuraEffect const* triggeredBy = nullptr);
        void RecalculateAmount(AuraEffect const* triggeredBy = nullptr) { if (!CanBeRecalculated()) return; ChangeAmount(CalculateAmount(GetCaster()), false, false, triggeredBy); }
        void RecalculateAmount(Unit* caster, AuraEffect const* triggeredBy = nullptr) { if (!CanBeRecalculated()) return; ChangeAmount(CalculateAmount(caster), false, false, triggeredBy); }
        bool CanBeRecalculated() const { return m_canBeRecalculated; }
        void SetCanBeRecalculated(bool val) { m_canBeRecalculated = val; }
        void HandleEffect(AuraApplication * aurApp, uint8 mode, bool apply, AuraEffect const* triggeredBy = nullptr);
        void HandleEffect(Unit* target, uint8 mode, bool apply, AuraEffect const* triggeredBy = nullptr);
        void ApplySpellMod(Unit* target, bool apply, AuraEffect const* triggeredBy = nullptr);

        void Update(uint32 diff, Unit* caster);

        uint32 GetTickNumber() const { return _ticksDone; }
        uint32 GetRemainingTicks() const { return GetTotalTicks() - _ticksDone; }
        uint32 GetTotalTicks() const;
        void ResetPeriodic(bool resetPeriodicTimer = false);
        void ResetTicks() { _ticksDone = 0; }

        bool IsPeriodic() const { return m_isPeriodic; }
        void SetPeriodic(bool isPeriodic) { m_isPeriodic = isPeriodic; }
        bool IsAffectingSpell(SpellInfo const* spell) const;
        bool HasSpellClassMask() const { return !!GetSpellEffectInfo().SpellClassMask; }

        void SendTickImmune(Unit* target, Unit* caster) const;
        void PeriodicTick(AuraApplication* aurApp, Unit* caster) const;

        bool CheckEffectProc(AuraApplication* aurApp, ProcEventInfo& eventInfo) const;
        void HandleProc(AuraApplication* aurApp, ProcEventInfo& eventInfo);

        // add/remove SPELL_AURA_MOD_SHAPESHIFT (36) linked auras
        void HandleShapeshiftBoosts(Unit* target, bool apply) const;

        SpellEffectInfo const& GetSpellEffectInfo() const { return m_effectInfo; }

        bool IsEffect() const { return m_effectInfo.Effect != 0; }
        bool IsEffect(SpellEffectName effectName) const { return m_effectInfo.Effect == effectName; }
        bool IsAreaAuraEffect() const;

    private:
        Aura* const m_base;

        SpellInfo const* const m_spellInfo;
        SpellEffectInfo const& m_effectInfo;

        SpellModifier* m_spellmod;

        int32 const m_baseAmount;
        int32 _amount;
        Optional<float> _estimatedAmount;   // for periodic damage and healing auras this will include damage done bonuses

        // periodic stuff
        int32 _periodicTimer;
        int32 _period;          // time between consecutive ticks
        uint32 _ticksDone;      // ticks counter

        bool m_canBeRecalculated;
        bool m_isPeriodic;

        float GetCritChanceFor(Unit const* caster, Unit const* target) const;

    public:
        // aura effect apply/remove handlers
        void HandleNULL(AuraApplication const* /*aurApp*/, uint8 /*mode*/, bool /*apply*/) const
        {
            // not implemented
        }
        void HandleUnused(AuraApplication const* /*aurApp*/, uint8 /*mode*/, bool /*apply*/) const
        {
            // useless
        }
        void HandleNoImmediateEffect(AuraApplication const* /*aurApp*/, uint8 /*mode*/, bool /*apply*/) const
        {
            // aura type not have immediate effect at add/remove and handled by ID in other code place
        }
        //  visibility & phases
        void HandleModInvisibilityDetect(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModInvisibility(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModStealth(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModStealthLevel(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModStealthDetect(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleDetectAmore(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleSpiritOfRedemption(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraGhost(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandlePhase(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandlePhaseGroup(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandlePhaseAlwaysVisible(AuraApplication const* aurApp, uint8 mode, bool apply) const;

        //  unit model
        void HandleAuraModShapeshift(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraTransform(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModScale(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraCloneCaster(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  fight
        void HandleFeignDeath(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModUnattackable(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDisarm(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModSilence(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModPacify(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModPacifyAndSilence(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModNoActions(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  tracking
        void HandleAuraTrackCreatures(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraTrackStealthed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStalked(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraUntrackable(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  skills & talents
        void HandleAuraModSkill(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraAllowTalentSwapping(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  movement
        void HandleAuraMounted(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraAllowFlight(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraWaterWalk(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraFeatherFall(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraHover(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleWaterBreathing(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleForceMoveForward(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraCanTurnWhileFalling(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleIgnoreMovementForces(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleDisableInertia(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleSetCantSwim(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  threat
        void HandleModThreat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModTotalThreat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModTaunt(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModDetaunt(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModFixate(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  control
        void HandleModConfuse(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModFear(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStun(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRoot(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandlePreventFleeing(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRootAndDisableGravity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStunAndDisableGravity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  charm
        void HandleModPossess(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModPossessPet(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModCharm(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleCharmConvert(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraControlVehicle(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  modify speed
        void HandleAuraModIncreaseSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseMountedSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseFlightSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseSwimSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDecreaseSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModUseNormalSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModMinimumSpeedRate(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModMovementForceMagnitude(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  immunity
        void HandleModMechanicImmunityMask(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModMechanicImmunity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModEffectImmunity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStateImmunity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModSchoolImmunity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDmgImmunity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDispelImmunity(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  modify stats
        //   resistance
        void HandleAuraModResistance(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModBaseResistancePCT(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModResistancePercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModBaseResistance(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModTargetResistance(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //    stat
        void HandleAuraModStat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModPercentStat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModSpellDamagePercentFromStat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModSpellHealingPercentFromStat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModHealingDone(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModHealingDonePct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModTotalPercentStat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModExpertise(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModBonusArmor(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModBonusArmorPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModArmorPctFromStat(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModStatBonusPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleOverrideSpellPowerByAttackPower(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleOverrideAttackPowerBySpellPower(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModVersatilityByPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModMaxPower(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //   heal and energize
        void HandleModPowerRegen(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModPowerRegenPCT(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModManaRegenPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseHealth(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseMaxHealth(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseEnergy(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseEnergyPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseHealthPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraIncreaseBaseHealthPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseBaseManaPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModManaCostPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModPowerDisplay(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModOverridePowerDisplay(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModMaxPowerPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleTriggerSpellOnHealthPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //   fight
        void HandleAuraModParryPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDodgePercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModBlockPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRegenInterrupt(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModWeaponCritPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModSpellHitChance(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModSpellCritChance(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModCritPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //   attack speed
        void HandleModCastingSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModMeleeRangedSpeedPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModCombatSpeedPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModAttackSpeed(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModMeleeSpeedPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedHaste(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //   combat rating
        void HandleModRating(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModRatingPct(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //   attack power
        void HandleAuraModAttackPower(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedAttackPower(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModAttackPowerPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedAttackPowerPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //   damage bonus
        void HandleModDamageDone(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModDamagePercentDone(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModOffhandDamagePercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleShieldBlockValue(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleShieldBlockValuePercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  power cost
        void HandleModPowerCost(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleArenaPreparation(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleNoReagentUseAura(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        //  others
        void HandleAuraDummy(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleChannelDeathItem(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleBindSight(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleForceReaction(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraEmpathy(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModFaction(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleLearnSpell(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleComprehendLanguage(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModAlternativeDefaultLanguage(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraLinked(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraOpenStable(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraModFakeInebriation(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraOverrideSpells(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraSetVehicle(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleSetVignette(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandlePreventResurrection(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleMastery(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAuraForceWeather(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleEnableAltPower(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModSpellCategoryCooldown(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleShowConfirmationPrompt(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleOverridePetSpecs(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleAllowUsingGameobjectsWhileMounted(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandlePlayScene(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleCreateAreaTrigger(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleLinkedSummon(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleSetFFAPvP(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModOverrideZonePVPType(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleBattlegroundPlayerPosition(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleTriggerSpellOnPowerAmount(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleTriggerSpellOnPowerPercent(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleTriggerSpellOnExpire(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleStoreTeleportReturnPoint(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleMountRestrictions(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleCosmeticMounted(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleModRequiredMountCapabilityFlags(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleSuppressItemPassiveEffectBySpellLabel(AuraApplication const* aurApp, uint8 mode, bool apply) const;
        void HandleForceBreathBar(AuraApplication const* aurApp, uint8 mode, bool apply) const;

        // aura effect periodic tick handlers
        void HandlePeriodicTriggerSpellAuraTick(Unit* target, Unit* caster) const;
        void HandlePeriodicTriggerSpellWithValueAuraTick(Unit* target, Unit* caster) const;
        void HandlePeriodicDamageAurasTick(Unit* target, Unit* caster) const;
        void HandlePeriodicHealthLeechAuraTick(Unit* target, Unit* caster) const;
        void HandlePeriodicHealthFunnelAuraTick(Unit* target, Unit* caster) const;
        void HandlePeriodicHealAurasTick(Unit* target, Unit* caster) const;
        void HandlePeriodicManaLeechAuraTick(Unit* target, Unit* caster) const;
        void HandleObsModPowerAuraTick(Unit* target, Unit* caster) const;
        void HandlePeriodicEnergizeAuraTick(Unit* target, Unit* caster) const;
        void HandlePeriodicPowerBurnAuraTick(Unit* target, Unit* caster) const;

        bool CanPeriodicTickCrit() const;
        float CalcPeriodicCritChance(Unit const* caster) const;

        // aura effect proc handlers
        void HandleBreakableCCAuraProc(AuraApplication* aurApp, ProcEventInfo& eventInfo);
        void HandleProcTriggerSpellAuraProc(AuraApplication* aurApp, ProcEventInfo& eventInfo);
        void HandleProcTriggerSpellWithValueAuraProc(AuraApplication* aurApp, ProcEventInfo& eventInfo);
        void HandleProcTriggerDamageAuraProc(AuraApplication* aurApp, ProcEventInfo& eventInfo);

        // pvp talents
        void HandleAuraPvpTalents(AuraApplication const* auraApp, uint8 mode, bool apply) const;

        void HandleAuraActAsControlZone(AuraApplication const* aurApp, uint8 mode, bool apply) const;
};

namespace Trinity
{
    // Binary predicate for sorting the priority of absorption aura effects
    class AbsorbAuraOrderPred
    {
        public:
            AbsorbAuraOrderPred() { }
            bool operator() (AuraEffect* aurEffA, AuraEffect* aurEffB) const
            {
                SpellInfo const* spellProtoA = aurEffA->GetSpellInfo();
                SpellInfo const* spellProtoB = aurEffB->GetSpellInfo();

                // Fel Blossom
                if (spellProtoA->Id == 28527)
                    return true;
                if (spellProtoB->Id == 28527)
                    return false;

                // Ice Barrier
                if (spellProtoA->GetCategory() == 471)
                    return true;
                if (spellProtoB->GetCategory() == 471)
                    return false;

                // Sacrifice
                if (spellProtoA->Id == 7812)
                    return true;
                if (spellProtoB->Id == 7812)
                    return false;

                // Cauterize (must be last)
                if (spellProtoA->Id == 86949)
                    return false;
                if (spellProtoB->Id == 86949)
                    return true;

                // Spirit of Redemption (must be last)
                if (spellProtoA->Id == 20711)
                    return false;
                if (spellProtoB->Id == 20711)
                    return true;

                return false;
            }
    };
}
#endif
