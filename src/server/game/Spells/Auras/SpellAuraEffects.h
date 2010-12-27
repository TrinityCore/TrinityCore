
#ifndef TRINITY_SPELLAURAEFFECTS_H
#define TRINITY_SPELLAURAEFFECTS_H

class Unit;
class DynamicObject;
class AuraEffect;
class Aura;

#include "SpellAuras.h"

typedef void(AuraEffect::*pAuraEffectHandler)(AuraApplication const * aurApp, uint8 mode, bool apply) const;

class AuraEffect
{
    friend Aura::Aura(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID);
    friend Aura::~Aura();
    private:
        ~AuraEffect();
        explicit AuraEffect(Aura * base, uint8 effIndex, int32 *baseAmount, Unit * caster);
    public:
        Unit * GetCaster() const { return GetBase()->GetCaster(); }
        uint64 GetCasterGUID() const { return GetBase()->GetCasterGUID(); }
        Aura * GetBase() const { return m_base; }
        void GetTargetList(std::list<Unit*> & targetList) const;
        void GetApplicationList(std::list<AuraApplication*> & applicationList) const;

        SpellEntry const * GetSpellProto() const { return m_spellProto; }
        uint32 GetId() const { return m_spellProto->Id; }
        uint32 GetEffIndex() const { return m_effIndex; }
        int32 GetBaseAmount() const { return m_baseAmount; }
        int32 GetAmplitude() const { return m_amplitude; }

        int32 GetMiscValueB() const { return m_spellProto->EffectMiscValueB[m_effIndex]; }
        int32 GetMiscValue() const { return m_spellProto->EffectMiscValue[m_effIndex]; }
        AuraType GetAuraType() const { return (AuraType)m_spellProto->EffectApplyAuraName[m_effIndex]; }
        int32 GetAmount() const { return m_amount; }
        void SetAmount(int32 amount) { m_amount = amount; m_canBeRecalculated = false;}

        int32 GetPeriodicTimer() const { return m_periodicTimer; }
        void SetPeriodicTimer(int32 periodicTimer) { m_periodicTimer = periodicTimer; }

        int32 CalculateAmount(Unit * caster);
        void CalculatePeriodic(Unit * caster, bool create = false);
        void CalculateSpellMod();
        void ChangeAmount(int32 newAmount, bool mark = true);
        void RecalculateAmount() { if (!CanBeRecalculated()) return; ChangeAmount(CalculateAmount(GetCaster()), false); }
        void RecalculateAmount(Unit * caster) { if (!CanBeRecalculated()) return; ChangeAmount(CalculateAmount(caster), false); }
        bool CanBeRecalculated() const { return m_canBeRecalculated; }
        void SetCanBeRecalculated(bool val) { m_canBeRecalculated = val; }
        void HandleEffect(AuraApplication const * aurApp, uint8 mode, bool apply);
        void HandleEffect(Unit * target, uint8 mode, bool apply);
        void ApplySpellMod(Unit * target, bool apply);

        void Update(uint32 diff, Unit * caster);
        void UpdatePeriodic(Unit * caster);

        uint32 GetTickNumber() const { return m_tickNumber; }
        int32 GetTotalTicks() const { return m_amplitude ? (GetBase()->GetMaxDuration() / m_amplitude) : 1;}
        void ResetPeriodic(bool resetPeriodicTimer = false) { if (resetPeriodicTimer) m_periodicTimer = m_amplitude; m_tickNumber = 0;}

        bool IsPeriodic() const { return m_isPeriodic; }
        void SetPeriodic(bool isPeriodic) { m_isPeriodic = isPeriodic; }
        bool IsAffectedOnSpell(SpellEntry const *spell) const;

        void SendTickImmune(Unit * target, Unit *caster) const;

        void PeriodicTick(AuraApplication * aurApp, Unit * caster) const;
        void PeriodicDummyTick(Unit * target, Unit * caster) const;
        Unit* GetTriggerTarget(Unit * target) const;
        void TriggerSpell(Unit * target, Unit * caster) const;
        void TriggerSpellWithValue(Unit * target, Unit * caster) const;

        void CleanupTriggeredSpells(Unit * target);

        // add/remove SPELL_AURA_MOD_SHAPESHIFT (36) linked auras
        void HandleShapeshiftBoosts(Unit * target, bool apply) const;
    private:
        Aura * const m_base;

        SpellEntry const * const m_spellProto;
        uint8 const m_effIndex;
        int32 const m_baseAmount;

        int32 m_amount;
        bool m_canBeRecalculated;

        SpellModifier *m_spellmod;

        bool m_isPeriodic;
        int32 m_periodicTimer;
        int32 m_amplitude;
        uint32 m_tickNumber;
    private:
        bool IsPeriodicTickCrit(Unit * target, Unit const * caster) const;

    public:
        // aura effect handlers
        void HandleNULL(AuraApplication const * /*aurApp*/, uint8 /*mode*/, bool /*apply*/) const
        {
            // not implemented
        }
        void HandleUnused(AuraApplication const * /*aurApp*/, uint8 /*mode*/, bool /*apply*/) const
        {
            // useless
        }
        void HandleNoImmediateEffect(AuraApplication const * /*aurApp*/, uint8 /*mode*/, bool /*apply*/) const
        {
            // aura type not have immediate effect at add/remove and handled by ID in other code place
        }
        //  visibility & phases
        void HandleModInvisibilityDetect(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModInvisibility(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModStealth(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModStealthLevel(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModStealthDetect(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleSpiritOfRedemption(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraGhost(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandlePhase(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  unit model
        void HandleAuraModShapeshift(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraTransform(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModScale(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraCloneCaster(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  fight
        void HandleFeignDeath(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModUnattackable(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDisarm(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModSilence(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModPacify(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModPacifyAndSilence(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraAllowOnlyAbility(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  tracking
        void HandleAuraTrackResources(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraTrackCreatures(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraTrackStealthed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStalked(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraUntrackable(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  skills & talents
        void HandleAuraModPetTalentsPoints(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModSkill(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  movement
        void HandleAuraMounted(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraAllowFlight(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraWaterWalk(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraFeatherFall(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraHover(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleWaterBreathing(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleForceMoveForward(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  threat
        void HandleModThreat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModTotalThreat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModTaunt(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  control
        void HandleModConfuse(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModFear(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStun(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRoot(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandlePreventFleeing(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  charm
        void HandleModPossess(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModPossessPet(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModCharm(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleCharmConvert(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraControlVehicle(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  modify speed
        void HandleAuraModIncreaseSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseMountedSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseFlightSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseSwimSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDecreaseSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModUseNormalSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  immunity
        void HandleModStateImmunityMask(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModMechanicImmunity(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModEffectImmunity(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModStateImmunity(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModSchoolImmunity(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDmgImmunity(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDispelImmunity(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  modify stats
        //   resistance
        void HandleAuraModResistanceExclusive(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModResistance(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModBaseResistancePCT(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModResistancePercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModBaseResistance(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModTargetResistance(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //    stat
        void HandleAuraModStat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModPercentStat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellDamagePercentFromStat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellHealingPercentFromStat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellDamagePercentFromAttackPower(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellHealingPercentFromAttackPower(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModHealingDone(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModTotalPercentStat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModResistenceOfStatPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModExpertise(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //   heal and energize
        void HandleModPowerRegen(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModPowerRegenPCT(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModManaRegen(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseHealth(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseMaxHealth(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseEnergy(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseEnergyPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModIncreaseHealthPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraIncreaseBaseHealthPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //   fight
        void HandleAuraModParryPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModDodgePercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModBlockPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRegenInterrupt(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModWeaponCritPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModHitChance(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellHitChance(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellCritChance(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModSpellCritChanceShool(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModCritPct(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //   attack speed
        void HandleModCastingSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModMeleeRangedSpeedPct(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModCombatSpeedPct(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModAttackSpeed(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModMeleeSpeedPct(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedHaste(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleRangedAmmoHaste(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //   combat rating
        void HandleModRating(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModRatingFromStat(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //   attack power
        void HandleAuraModAttackPower(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedAttackPower(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModAttackPowerPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedAttackPowerPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModRangedAttackPowerOfStatPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModAttackPowerOfStatPercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModAttackPowerOfArmor(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //   damage bonus
        void HandleModDamageDone(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModDamagePercentDone(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModOffhandDamagePercent(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleShieldBlockValue(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  power cost
        void HandleModPowerCostPCT(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleModPowerCost(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleArenaPreparation(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleNoReagentUseAura(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraRetainComboPoints(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        //  others
        void HandleAuraDummy(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleChannelDeathItem(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleBindSight(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleForceReaction(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraEmpathy(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModFaction(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleComprehendLanguage(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraConvertRune(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraLinked(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraOpenStable(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraOverrideSpells(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraSetVehicle(AuraApplication const * aurApp, uint8 mode, bool apply) const;
        void HandleAuraModFakeInebriation(AuraApplication const * aurApp, uint8 mode, bool apply) const;
};

namespace Trinity
{
    // Binary predicate for sorting the priority of absorption aura effects
    class AbsorbAuraOrderPred
    {
        public:
            AbsorbAuraOrderPred() { }
            bool operator() (AuraEffect * aurEffA, AuraEffect * aurEffB) const
            {
                SpellEntry const * spellProtoA = aurEffA->GetSpellProto();
                SpellEntry const * spellProtoB = aurEffB->GetSpellProto();

                // Wards
                if ((spellProtoA->SpellFamilyName == SPELLFAMILY_MAGE) ||
                    (spellProtoA->SpellFamilyName == SPELLFAMILY_WARLOCK))
                    if (spellProtoA->Category == 56)
                        return true;
                if ((spellProtoB->SpellFamilyName == SPELLFAMILY_MAGE) ||
                    (spellProtoB->SpellFamilyName == SPELLFAMILY_WARLOCK))
                    if (spellProtoB->Category == 56)
                        return false;

                // Sacred Shield
                if (spellProtoA->Id == 58597)
                    return true;
                if (spellProtoB->Id == 58597)
                    return false;

                // Fel Blossom
                if (spellProtoA->Id == 28527)
                    return true;
                if (spellProtoB->Id == 28527)
                    return false;

                // Divine Aegis
                if (spellProtoA->Id == 47753)
                    return true;
                if (spellProtoB->Id == 47753)
                    return false;

                // Ice Barrier
                if (spellProtoA->Category == 471)
                    return true;
                if (spellProtoB->Category == 471)
                    return false;

                // Sacrifice
                if ((spellProtoA->SpellFamilyName == SPELLFAMILY_WARLOCK) &&
                    (spellProtoA->SpellIconID == 693))
                    return true;
                if ((spellProtoB->SpellFamilyName == SPELLFAMILY_WARLOCK) &&
                    (spellProtoB->SpellIconID == 693))
                    return false;

                return false;
            }
    };
}
#endif
