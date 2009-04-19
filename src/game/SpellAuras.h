/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef TRINITY_SPELLAURAS_H
#define TRINITY_SPELLAURAS_H

#include "SpellAuraDefines.h"

class Unit;
struct SpellEntry;
struct SpellModifier;
struct ProcTriggerSpell;

// forward decl
class Aura;
class AuraEffect;

typedef void(AuraEffect::*pAuraHandler)(bool Apply, bool Real);
// Real == true at aura add/remove
// Real == false at aura mod unapply/reapply; when adding/removing dependent aura/item/stat mods
//
// Code in aura handler can be guarded by if(Real) check if it should execution only at real add/remove of aura
//
// MAIN RULE: Code MUST NOT be guarded by if(Real) check if it modifies any stats
//      (percent auras, stats mods, etc)
// Second rule: Code must be guarded by if(Real) check if it modifies object state (start/stop attack, send packets to client, etc)
//
// Other case choice: each code line moved under if(Real) check is Trinity speedup,
//      each setting object update field code line moved under if(Real) check is significant Trinity speedup, and less server->client data sends
//      each packet sending code moved under if(Real) check is _large_ Trinity speedup, and lot less server->client data sends

class TRINITY_DLL_SPEC Aura
{
    friend void Player::SendAurasForTarget(Unit *target);
    public:
        virtual ~Aura();
                Aura(SpellEntry const* spellproto, uint32 effMask, int32 *currentBasePoints, Unit *target, Unit *caster = NULL, Item* castItem = NULL);

        SpellEntry const* GetSpellProto() const { return m_spellProto; }
        uint32 GetId() const{ return m_spellProto->Id; }
        uint64 GetCastItemGUID() const { return m_castItemGuid; }

        uint64 const& GetCasterGUID() const { return m_caster_guid; }
        Unit* GetCaster() const;
        Unit* GetTarget() const { return m_target; }

        time_t GetAuraApplyTime() const { return m_applyTime; }

        int32 GetAuraMaxDuration() const { return m_maxduration; }
        void SetAuraMaxDuration(int32 duration) { m_maxduration = duration; }
        int32 GetAuraDuration() const { return m_duration; }
        void SetAuraDuration(int32 duration);
        void RefreshAura(){ SetAuraDuration (m_maxduration); }

        void SendAuraUpdate();
        uint8 GetAuraSlot() const { return m_auraSlot; }
        void SetAuraSlot(uint8 slot) { m_auraSlot = slot; }
        uint8 GetAuraCharges() const { return m_procCharges; }
        void SetAuraCharges(uint8 charges);
        void DropAuraCharge();
        void SetProcDamage(uint32 val) { m_procDamage = val; }
        uint32 GetProcDamage() const { return m_procDamage; }

        int8 GetStackAmount() const {return m_stackAmount;}
        void SetStackAmount(uint8 num);
        bool modStackAmount(int32 num); // return true if last charge dropped
        uint32 GetAuraStateMask(){return m_auraStateMask;}
        void SetAuraState(uint8 num){m_auraStateMask |= 1<<(num-1);}  //modifies aura's aura state (not unit!)

        void SetRemoveMode(AuraRemoveMode mode) { m_removeMode = mode; }
        uint8 GetRemoveMode() const {return m_removeMode;}

        inline uint8 GetEffectMask() const {return m_auraFlags & 7;}
        AuraEffect * GetPartAura (uint8 effIndex) const {return m_partAuras[effIndex];}
        bool SetPartAura(AuraEffect* aurEff, uint8 effIndex);

        bool IsPositive() const { return m_positive; }
        void SetNegative() { m_positive = false; }
        void SetPositive() { m_positive = true; }
        bool IsPermanent() const { return m_permanent; }
        void SetPermanent(bool val) { m_permanent = val; }

        bool IsPassive() const { return m_isPassive; }
        bool IsDeathPersistent() const { return m_isDeathPersist; }
        bool IsRemovedOnShapeLost() const { return m_isRemovedOnShapeLost; }
        bool IsUpdated() const { return m_updated; }
        bool IsRemoved() const { return m_isRemoved; }
        void SetUpdated(bool val) { m_updated = val; }

        bool IsPersistent() const;
        bool IsAreaAura() const;
        bool IsAuraType(AuraType type) const;
        void SetLoadedState(uint64 caster_guid,int32 maxduration,int32 duration,int32 charges, uint8 stackamount, int32 * amount);
        bool HasEffect(uint8 effIndex) const {return bool (m_partAuras[effIndex]);}
        inline void HandleEffects(bool apply)
        {
            for (uint8 i = 0; i<MAX_SPELL_EFFECTS;++i)
                if (m_partAuras[i])
                    m_target->HandleAuraEffect(m_partAuras[i], apply);
        }
        void ApplyAllModifiers(bool apply, bool Real=false);

        void Update(uint32 diff);

        void _AddAura();
        void _RemoveAura();

        // Allow Apply Aura Handler to modify and access m_AuraDRGroup
        void setDiminishGroup(DiminishingGroup group) { m_AuraDRGroup = group; }
        DiminishingGroup getDiminishGroup() const { return m_AuraDRGroup; }

        // Single cast aura helpers
        void UnregisterSingleCastAura();
        bool IsSingleTarget() const {return m_isSingleTargetAura;}
        void SetIsSingleTarget(bool val) { m_isSingleTargetAura = val;}

    private:
        SpellEntry const *m_spellProto;
        Unit * const m_target;
        uint64 m_caster_guid;
        uint64 m_castItemGuid;                              // it is NOT safe to keep a pointer to the item because it may get deleted
        time_t m_applyTime;

        int32 m_maxduration;                                // Max aura duration
        int32 m_duration;                                   // Current time
        int32 m_timeCla;                                    // Timer for power per sec calcultion

        AuraRemoveMode m_removeMode:8;                      // Store info for know remove aura reason
        DiminishingGroup m_AuraDRGroup:8;                   // Diminishing

        uint8 m_auraSlot;                                   // Aura slot on unit (for show in client)
        uint8 m_auraFlags;                                  // Aura info flag (for send data to client)
        uint8 m_auraLevel;                                  // Aura level (store caster level for correct show level dep amount)
        uint8 m_procCharges;                                // Aura charges (0 for infinite)
        uint32 m_procDamage;                                // used in aura proc code
        uint8 m_stackAmount;                                // Aura stack amount
        uint32 m_auraStateMask;
        AuraEffect * m_partAuras[3];

        bool m_isDeathPersist:1;
        bool m_isRemovedOnShapeLost:1;
        bool m_isPassive:1;
        bool m_positive:1;
        bool m_permanent:1;
        bool m_isRemoved:1;
        bool m_updated:1;                                   // Prevent remove aura by stack if set
        bool m_isSingleTargetAura:1;                        // true if it's a single target spell and registered at caster - can change at spell steal for example
};

class TRINITY_DLL_SPEC AuraEffect
{
    public:
        friend AuraEffect* CreateAuraEffect(Aura * parentAura, uint32 effIndex, int32 *currentBasePoints, Unit * caster, Item * castItem);
        friend void Aura::SetStackAmount(uint8 stackAmount);
        //aura handlers
        void HandleNULL(bool, bool)
        {
            // NOT IMPLEMENTED
        }
        void HandleUnused(bool, bool)
        {
            // NOT USED BY ANY SPELL OR USELESS
        }
        void HandleNoImmediateEffect(bool, bool)
        {
            // aura not have immediate effect at add/remove and handled by ID in other code place
        }
        void HandleBindSight(bool Apply, bool Real);
        void HandleModPossess(bool Apply, bool Real);
        void HandlePeriodicDamage(bool Apply, bool Real);
        void HandleAuraDummy(bool Apply, bool Real);
        void HandleAuraPeriodicDummy(bool apply, bool Real);
        void HandleModConfuse(bool Apply, bool Real);
        void HandleModCharm(bool Apply, bool Real);
        void HandleModFear(bool Apply, bool Real);
        void HandlePeriodicHeal(bool Apply, bool Real);
        void HandleModAttackSpeed(bool Apply, bool Real);
        void HandleModMeleeRangedSpeedPct(bool apply, bool Real);
        void HandleModCombatSpeedPct(bool apply, bool Real);
        void HandleModThreat(bool Apply, bool Real);
        void HandleModTaunt(bool Apply, bool Real);
        void HandleFeignDeath(bool Apply, bool Real);
        void HandleAuraModDisarm(bool Apply, bool Real);
        void HandleAuraModStalked(bool Apply, bool Real);
        void HandleAuraWaterWalk(bool Apply, bool Real);
        void HandleAuraFeatherFall(bool Apply, bool Real);
        void HandleAuraHover(bool Apply, bool Real);
        void HandleAddModifier(bool Apply, bool Real);
        void HandleAddTargetTrigger(bool Apply, bool Real);
        void HandleAuraModStun(bool Apply, bool Real);
        void HandleModDamageDone(bool Apply, bool Real);
        void HandleAuraUntrackable(bool Apply, bool Real);
        void HandleAuraEmpathy(bool Apply, bool Real);
        void HandleModOffhandDamagePercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPower(bool Apply, bool Real);
        void HandleAuraModIncreaseEnergyPercent(bool Apply, bool Real);
        void HandleAuraModIncreaseHealthPercent(bool Apply, bool Real);
        void HandleAuraModRegenInterrupt(bool Apply, bool Real);
        void HandleHaste(bool Apply, bool Real);
        void HandlePeriodicTriggerSpell(bool Apply, bool Real);
        void HandlePeriodicTriggerSpellWithValue(bool apply, bool Real);
        void HandlePeriodicEnergize(bool Apply, bool Real);
        void HandleAuraModResistanceExclusive(bool Apply, bool Real);
        void HandleAuraModPetTalentsPoints(bool Apply, bool Real);
        void HandleModStealth(bool Apply, bool Real);
        void HandleInvisibility(bool Apply, bool Real);
        void HandleInvisibilityDetect(bool Apply, bool Real);
        void HandleAuraModTotalHealthPercentRegen(bool Apply, bool Real);
        void HandleAuraModTotalEnergyPercentRegen(bool Apply, bool Real);
        void HandleAuraModResistance(bool Apply, bool Real);
        void HandleAuraModRoot(bool Apply, bool Real);
        void HandleAuraModSilence(bool Apply, bool Real);
        void HandleAuraModStat(bool Apply, bool Real);
        void HandleAuraModIncreaseSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseMountedSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseFlightSpeed(bool Apply, bool Real);
        void HandleAuraModDecreaseSpeed(bool Apply, bool Real);
        void HandleAuraModUseNormalSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseHealth(bool Apply, bool Real);
        void HandleAuraModIncreaseEnergy(bool Apply, bool Real);
        void HandleAuraModShapeshift(bool Apply, bool Real);
        void HandleAuraModEffectImmunity(bool Apply, bool Real);
        void HandleAuraModStateImmunity(bool Apply, bool Real);
        void HandleAuraModSchoolImmunity(bool Apply, bool Real);
        void HandleAuraModDmgImmunity(bool Apply, bool Real);
        void HandleAuraModDispelImmunity(bool Apply, bool Real);
        void HandleAuraProcTriggerSpell(bool Apply, bool Real);
        void HandleAuraTrackCreatures(bool Apply, bool Real);
        void HandleAuraTrackResources(bool Apply, bool Real);
        void HandleAuraModParryPercent(bool Apply, bool Real);
        void HandleAuraModDodgePercent(bool Apply, bool Real);
        void HandleAuraModBlockPercent(bool Apply, bool Real);
        void HandleAuraModCritPercent(bool Apply, bool Real);
        void HandlePeriodicLeech(bool Apply, bool Real);
        void HandleModHitChance(bool Apply, bool Real);
        void HandleModSpellHitChance(bool Apply, bool Real);
        void HandleAuraModScale(bool Apply, bool Real);
        void HandlePeriodicManaLeech(bool Apply, bool Real);
        void HandlePeriodicHealthFunnel(bool apply, bool Real);
        void HandleModCastingSpeed(bool Apply, bool Real);
        void HandleAuraMounted(bool Apply, bool Real);
        void HandleWaterBreathing(bool Apply, bool Real);
        void HandleModBaseResistance(bool Apply, bool Real);
        void HandleModRegen(bool Apply, bool Real);
        void HandleModPowerRegen(bool Apply, bool Real);
        void HandleModPowerRegenPCT(bool Apply, bool Real);
        void HandleChannelDeathItem(bool Apply, bool Real);
        void HandlePeriodicDamagePCT(bool Apply, bool Real);
        void HandleAuraModAttackPower(bool Apply, bool Real);
        void HandleAuraTransform(bool Apply, bool Real);
        void HandleModSpellCritChance(bool Apply, bool Real);
        void HandleAuraModIncreaseSwimSpeed(bool Apply, bool Real);
        void HandleModPowerCostPCT(bool Apply, bool Real);
        void HandleModPowerCost(bool Apply, bool Real);
        void HandleFarSight(bool Apply, bool Real);
        void HandleModPossessPet(bool Apply, bool Real);
        void HandleModMechanicImmunity(bool Apply, bool Real);
        void HandleModStateImmunityMask(bool apply, bool Real);
        void HandleAuraModSkill(bool Apply, bool Real);
        void HandleModDamagePercentDone(bool Apply, bool Real);
        void HandleModPercentStat(bool Apply, bool Real);
        void HandleModResistancePercent(bool Apply, bool Real);
        void HandleAuraModBaseResistancePCT(bool Apply, bool Real);
        void HandleModShieldBlockPCT(bool Apply, bool Real);
        void HandleAuraTrackStealthed(bool Apply, bool Real);
        void HandleModShieldBlock(bool Apply, bool Real);
        void HandleForceReaction(bool Apply, bool Real);
        void HandleAuraModRangedHaste(bool Apply, bool Real);
        void HandleRangedAmmoHaste(bool Apply, bool Real);
        void HandleModHealingDone(bool Apply, bool Real);
        void HandleModTotalPercentStat(bool Apply, bool Real);
        void HandleAuraModTotalThreat(bool Apply, bool Real);
        void HandleModUnattackable(bool Apply, bool Real);
        void HandleAuraModPacify(bool Apply, bool Real);
        void HandleAuraGhost(bool Apply, bool Real);
        void HandleAuraAllowFlight(bool Apply, bool Real);
        void HandleModRating(bool apply, bool Real);
        void HandleModRatingFromStat(bool apply, bool Real);
        void HandleModTargetResistance(bool apply, bool Real);
        void HandleAuraModAttackPowerPercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPowerPercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPowerOfStatPercent(bool apply, bool Real);
        void HandleAuraModAttackPowerOfStatPercent(bool apply, bool Real);
        void HandleSpiritOfRedemption(bool apply, bool Real);
        void HandleModManaRegen(bool apply, bool Real);
        void HandleComprehendLanguage(bool apply, bool Real);
        void HandleShieldBlockValue(bool apply, bool Real);
        void HandleModSpellCritChanceShool(bool apply, bool Real);
        void HandleAuraRetainComboPoints(bool apply, bool Real);
        void HandleModSpellDamagePercentFromStat(bool apply, bool Real);
        void HandleModSpellHealingPercentFromStat(bool apply, bool Real);
        void HandleAuraModDispelResist(bool apply, bool Real);
        void HandleAuraControlVehicle(bool apply, bool Real);
        void HandleModSpellDamagePercentFromAttackPower(bool apply, bool Real);
        void HandleModSpellHealingPercentFromAttackPower(bool apply, bool Real);
        void HandleAuraModPacifyAndSilence(bool Apply, bool Real);
        void HandleAuraModIncreaseMaxHealth(bool apply, bool Real);
        void HandleAuraModExpertise(bool apply, bool Real);
        void HandleForceMoveForward(bool apply, bool Real);
        void HandleAuraModResistenceOfStatPercent(bool apply, bool Real);
        void HandleAuraPowerBurn(bool apply, bool Real);
        void HandleSchoolAbsorb(bool apply, bool Real);
        void HandlePreventFleeing(bool apply, bool Real);
        void HandleManaShield(bool apply, bool Real);
        void HandleArenaPreparation(bool apply, bool Real);
        void HandleAuraConvertRune(bool apply, bool Real);
        void HandleAuraIncreaseBaseHealthPercent(bool Apply, bool Real);
        void HandleNoReagentUseAura(bool Apply, bool Real);
        void HandlePhase(bool Apply, bool Real);
        void HandleAuraAllowOnlyAbility(bool apply, bool Real);

        // add/remove SPELL_AURA_MOD_SHAPESHIFT (36) linked auras
        void HandleShapeshiftBoosts(bool apply);

        inline Unit * GetCaster() const{ return m_parentAura->GetCaster(); }
        inline uint64 GetCasterGUID() const{ return m_parentAura->GetCasterGUID(); }
        Aura * GetParentAura() const { return m_parentAura; }

        SpellEntry const* GetSpellProto() const { return m_spellProto; }
        uint32 GetId() const { return m_spellProto->Id; }
        uint32 GetEffIndex() const { return m_effIndex; }
        int32 GetBasePoints() const { return m_currentBasePoints; }
        int32 GetAuraAmplitude(){return m_amplitude;}
        virtual void Update(uint32 diff);

        uint32 GetTickNumber() const { return m_tickNumber; }
        bool IsAreaAura() const { return m_isAreaAura; }
        bool IsPeriodic() const { return m_isPeriodic; }
        bool IsPersistent() const { return m_isPersistent; }
        bool isAffectedOnSpell(SpellEntry const *spell) const;

        void ApplyModifier(bool apply, bool Real = false);
        void HandleAuraEffect(bool apply);
        void ApplyAllModifiers(bool apply, bool Real);

        Unit* GetTriggerTarget() const;
        void TriggerSpell();
        void TriggerSpellWithValue();
        void PeriodicTick();
        void PeriodicDummyTick();

        int32 GetMiscBValue() const {return m_spellProto->EffectMiscValueB[m_effIndex];}
        int32 GetMiscValue() const {return m_spellProto->EffectMiscValue[m_effIndex];}
        uint32 GetAuraName() const {return m_auraName;}
        int32 GetAmount() const {return m_amount;}
        void SetAmount(int32 amount) { m_amount = amount; }
        void CleanupTriggeredSpells();

    protected:
        AuraEffect (Aura * parentAura, uint8 effIndex, int32 * currentBasePoints , Unit * caster,Item * castItem);
        Aura * const m_parentAura;
        Unit * const m_target;

        SpellEntry const *m_spellProto;
        uint32 m_tickNumber;

        uint8 m_effIndex;
        AuraType m_auraName;
        int32 m_currentBasePoints;
        int32 m_amount;

        SpellModifier *m_spellmod;

        int32 m_periodicTimer;                              // Timer for periodic auras
        int32 m_amplitude;

        bool m_isPeriodic:1;
        bool m_isAreaAura:1;
        bool m_isPersistent:1;
};

class TRINITY_DLL_SPEC AreaAuraEffect : public AuraEffect
{
    public:
        AreaAuraEffect(Aura * parentAura, uint32 effIndex, int32 * currentBasePoints, Unit * caster=NULL, Item * castItem=NULL);
        ~AreaAuraEffect();
        void Update(uint32 diff);
    private:
        float m_radius;
        int32 m_removeTime;
        AreaAuraType m_areaAuraType;
};

class TRINITY_DLL_SPEC PersistentAreaAuraEffect : public AuraEffect
{
    public:
        PersistentAreaAuraEffect(Aura * parentAura, uint32 eff, int32 *currentBasePoints, Unit *caster = NULL, Item* castItem = NULL);
        ~PersistentAreaAuraEffect();
        void Update(uint32 diff);
};
AuraEffect* CreateAuraEffect(Aura * parentAura, uint32 effIndex, int32 *currentBasePoints, Unit * caster, Item * castItem = NULL);
#endif
