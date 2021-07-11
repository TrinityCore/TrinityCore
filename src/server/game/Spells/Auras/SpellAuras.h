/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#ifndef MANGOS_SPELLAURAS_H
#define MANGOS_SPELLAURAS_H

#include "SpellAuraDefines.h"
#include "SpellInfo.h"
#include <typeinfo>
#include "DBCEnums.h"
#include "ObjectGuid.h"

/**
 * Used to modify what an Aura does to a player/npc.
 * Accessible through Aura::m_modifier.
 * \see CreateAura
 * \see Aura
 * \see AreaAura
 * \see AuraType
 */
struct Modifier
{
    /**
     * Decides what the aura does, ie, it may have the
     * value AuraType::SPELL_AURA_MOD_BASE_RESISTANCE_PCT which
     * would change the base armor of a player.
     */
    AuraType m_auraname;
    /**
     * By how much the aura should change the affected
     * value. Ie, -27 would make the value decided by Modifier::m_miscvalue
     * be reduced by 27% if the earlier mentioned AuraType
     * would have been used. And 27 would increase the value by 27%
     */
    float m_amount;
    /**
     * A miscvalue that is dependent on what the aura will do, this
     * is usually decided by the AuraType, ie:
     * with AuraType::SPELL_AURA_MOD_BASE_RESISTANCE_PCT this value
     * could be SpellSchoolMask::SPELL_SCHOOL_MASK_NORMAL which would
     * tell the aura that it should change armor.
     * If Modifier::m_auraname would have been AuraType::SPELL_AURA_MOUNTED
     * then m_miscvalue would have decided which model the mount should have
     */
    int32 m_miscvalue;
    /**
     * Decides how often the aura should be applied, if it is
     * set to 0 it's only applied once and then removed when
     * the Aura is removed
     */
    int32 periodictime;
};

struct HeartBeatData
{
    uint32 timer;
    uint32 hitChance;
};

class Unit;
class SpellEntry;
struct SpellModifier;
struct ProcTriggerSpell;

// forward decl
class Aura;

// internal helper
struct ReapplyAffectedPassiveAurasHelper;

class SpellAuraHolder
{
    friend class Unit;

    private:
        Unit* const _target;
        Aura* const _base;
        AuraRemoveMode _removeMode:8;                  // Store info for know remove aura reason
        uint8 _slot;                                   // Aura slot on unit
        uint16 _flags;                                 // Aura info flag
        uint32 _effectsToApply;                        // Used only at spell hit to determine which effect should be applied
        bool _needClientUpdate:1;
        uint32 _effectMask;

        explicit AuraApplication(Unit* target, Unit* caster, Aura* base, uint32 effMask);
        void _Remove();

        void _InitFlags(Unit* caster, uint32 effMask);
        void _HandleEffect(uint8 effIndex, bool apply);
    public:
        SpellAuraHolder (SpellEntry const* spellproto, Unit* target, Unit* caster, Item* castItem, WorldObject* realCaster);
        Aura* m_auras[MAX_EFFECT_INDEX];

    public:
        Unit* GetTarget() const { return _target; }
        Aura* GetBase() const { return _base; }
        void AddAura(Aura* aura, SpellEffectIndex index);
        void RemoveAura(SpellEffectIndex index);
        void ApplyAuraModifiers(bool apply, bool real = false);
        void _AddSpellAuraHolder();
        void _RemoveSpellAuraHolder();
        void HandleSpellSpecificBoosts(bool apply);
        void HandleCastOnAuraRemoval() const;
        void CleanupTriggeredSpells();

        uint8 GetSlot() const { return _slot; }
        uint16 GetFlags() const { return _flags; }
        uint32 GetEffectMask() const { return _effectMask; }
        bool HasEffect(uint8 effect) const { ASSERT(effect < MAX_SPELL_EFFECTS); return (_effectMask & (1 << effect)) != 0; }
        bool IsPositive() const { return (_flags & AFLAG_POSITIVE) != 0; }
        bool IsSelfcast() const { return (_flags & AFLAG_NOCASTER) != 0; }

        uint32 GetEffectsToApply() const { return _effectsToApply; }
        void UpdateApplyEffectMask(uint32 newEffMask, bool canHandleNewEffects);
        void setDiminishGroup(DiminishingGroup group) { m_AuraDRGroup = group; }
        void setDiminishLevel(DiminishingLevels level) { m_AuraDRLevel = level; }
        DiminishingGroup getDiminishGroup() const { return m_AuraDRGroup; }

        uint32 GetStackAmount() const { return m_stackAmount; }
        void SetStackAmount(uint32 stackAmount);
        bool ModStackAmount(int32 num); // return true if last charge dropped

        void SetNeedClientUpdate();
        bool IsNeedClientUpdate() const { return _needClientUpdate; }
        void BuildUpdatePacket(WorldPackets::Spells::AuraInfo& auraInfo, bool remove);
        void ClientUpdate(bool remove = false);

        std::string GetDebugInfo() const;
};
        Aura* GetAuraByEffectIndex(SpellEffectIndex index) const { return m_auras[index]; }

// Structure representing database aura primary key fields
struct AuraKey
{
    ObjectGuid Caster;
    ObjectGuid Item;
    uint32 SpellId;
    uint32 EffectMask;
        uint32 GetId() const;
        SpellEntry const* GetSpellProto() const { return m_spellProto; }

    bool operator<(AuraKey const& right) const
    {
        auto comparisonTuple = [](AuraKey const& k) { return std::tie(k.Caster, k.Item, k.SpellId, k.EffectMask); };

        return comparisonTuple(*this) < comparisonTuple(right);
    }
};
        ObjectGuid const& GetCasterGuid() const { return m_casterGuid; }
        void SetCasterGuid(ObjectGuid guid) { m_casterGuid = guid; }
        ObjectGuid const& GetRealCasterGuid() const { return m_realCasterGuid; }
        void SetRealCasterGuid(ObjectGuid guid) { m_realCasterGuid = guid; }
        ObjectGuid const& GetCastItemGuid() const { return m_castItemGuid; }
        Unit* GetCaster() const;
        SpellCaster* GetRealCaster() const;
        Unit* GetTarget() const { return m_target; }
        void SetTarget(Unit* target) { m_target = target; }

        // Nostalrius
        void CalculateHeartBeat(Unit* caster, Unit* target);
        float _heartBeatRandValue;
        HeartBeatData* _pveHeartBeatData;

        // Debuff limit
        void CalculateForDebuffLimit();
        bool IsAffectedByDebuffLimit() const { return m_debuffLimitAffected; }
        void SetAffectedByDebuffLimit(bool isAffectedByDebuffLimit);
        bool IsMoreImportantDebuffThan(SpellAuraHolder* other) const;
        bool m_debuffLimitAffected;
        uint32 m_debuffLimitScore; // + haut => + important
        // Refresh de buff
        void Refresh(Unit* caster, Unit* target, SpellAuraHolder* pRefreshWithAura);
        bool CanBeRefreshedBy(SpellAuraHolder* other) const;
        // FIN NOSTALRIUS

        bool IsPermanent() const { return m_permanent; }
        void SetPermanent(bool permanent) { m_permanent = permanent; }
        bool IsPassive() const { return m_isPassive; }
        void SetPassive(bool on) { m_isPassive = on; }
        bool IsDeathPersistent() const { return m_isDeathPersist; }
        bool IsPersistent() const;
        bool IsPositive() const;
        bool IsAreaAura() const;                            // if one from auras of holder applied as area aura
        bool IsWeaponBuffCoexistableWith(SpellAuraHolder const* ref) const;
        bool IsNeedVisibleSlot(Unit const* caster) const;
        bool IsRemovedOnShapeLost() const { return m_isRemovedOnShapeLost; }
        bool IsInUse() const { return m_in_use;}
        bool IsDeleted() const { return m_deleted;}
        bool IsEmptyHolder() const;

        void SetDeleted() { m_deleted = true; }

        void SetInUse(bool state)
        {
            if (state)
                ++m_in_use;
            else
            {
                if (m_in_use)
                    --m_in_use;
            }
        }

struct AuraLoadEffectInfo
{
    std::array<int32, MAX_SPELL_EFFECTS> Amounts;
    std::array<int32, MAX_SPELL_EFFECTS> BaseAmounts;
};
        void UpdateHolder(uint32 diff) { SetInUse(true); Update(diff); SetInUse(false); }
        void Update(uint32 diff);
        void RefreshHolder();
        void RefreshAuraPeriodicTimers(int32 duration = 0);

        bool IsSingleTarget() const { return m_isSingleTarget; }
        void SetIsSingleTarget(bool val) { m_isSingleTarget = val; }
        bool IsChanneled() { return m_isChanneled; }
        void UnregisterSingleCastHolder();

        int32 GetAuraMaxDuration() const { return m_maxDuration; }
        void SetAuraMaxDuration(int32 duration);
        int32 GetAuraDuration() const { return m_duration; }
        void SetAuraDuration(int32 duration) { m_duration = duration; };

        uint8 GetAuraSlot() const { return m_auraSlot; }
        void SetAuraSlot(uint8 slot) { m_auraSlot = slot; }
        uint8 GetAuraLevel() const { return m_auraLevel; }
        void SetAuraLevel(uint8 level) { m_auraLevel = level; }
        uint32 GetAuraCharges() const { return m_procCharges; }
        void SetAuraCharges(uint32 charges)
        {
            if (m_procCharges == charges)
                return;
            m_procCharges = charges;

class TC_GAME_API Aura
{
    friend class Unit;

    public:
        typedef std::unordered_map<ObjectGuid, AuraApplication*> ApplicationMap;
            UpdateAuraApplication();
        }
        bool DropAuraCharge()                               // return true if last charge dropped
        {
            if (m_procCharges == 0)
                return false;

        static uint32 BuildEffectMaskForOwner(SpellInfo const* spellProto, uint32 availableEffectMask, WorldObject* owner);
        static Aura* TryRefreshStackOrCreate(AuraCreateInfo& createInfo, bool updateEffectMask = true);
        static Aura* TryCreate(AuraCreateInfo& createInfo);
        static Aura* Create(AuraCreateInfo& createInfo);
        explicit Aura(AuraCreateInfo const& createInfo);
        void _InitEffects(uint32 effMask, Unit* caster, int32 const* baseAmount);
        void SaveCasterInfo(Unit* caster);
        virtual ~Aura();
            m_procCharges--;
            UpdateAuraApplication();
            return m_procCharges == 0;
        }

        time_t GetAuraApplyTime() const { return m_applyTime; }

        ObjectGuid GetCastId() const { return m_castId; }
        ObjectGuid GetCasterGUID() const { return m_casterGuid; }
        ObjectGuid GetCastItemGUID() const { return m_castItemGuid; }
        uint32 GetCastItemId() const { return m_castItemId; }
        int32 GetCastItemLevel() const { return m_castItemLevel; }
        SpellCastVisual GetSpellVisual() const { return m_spellVisual; }
        Unit* GetCaster() const;
        WorldObject* GetWorldObjectCaster() const;
        WorldObject* GetOwner() const { return m_owner; }
        Unit* GetUnitOwner() const { ASSERT(GetType() == UNIT_AURA_TYPE); return m_owner->ToUnit(); }
        DynamicObject* GetDynobjOwner() const { ASSERT(GetType() == DYNOBJ_AURA_TYPE); return m_owner->ToDynObject(); }
        void SetRemoveMode(AuraRemoveMode mode) { m_removeMode = mode; }
        AuraRemoveMode GetRemoveMode() const { return m_removeMode; }
        void SetLoadedState(ObjectGuid const& casterGUID, ObjectGuid const& itemGUID, uint32 stackAmount, uint32 charges, int32 maxduration, int32 duration)
        {
            m_casterGuid   = casterGUID;
            m_castItemGuid = itemGUID;
            m_procCharges  = charges;
            m_stackAmount  = stackAmount;
            SetAuraMaxDuration(maxduration);
            SetAuraDuration(duration);
        }

        bool HasMechanic(uint32 mechanic) const;
        bool HasMechanicMask(uint32 mechanicMask) const;

        void UpdateAuraDuration() const;

        void SetAura(uint32 slot, bool remove);
        void SetAuraFlag(uint32 slot, bool add);
        void SetAuraLevel(uint32 slot, uint32 level);

        void _RegisterForTargets() { Unit* caster = GetCaster(); UpdateTargetMap(caster, false); }
        void ApplyForTargets() { Unit* caster = GetCaster(); UpdateTargetMap(caster, true); }
        void _ApplyEffectForTargets(uint8 effIndex);
        void SetTargetSecondaryThreatFocus(bool v) { m_makesTargetSecondaryFocus = v; }
        bool IsTargetSecondaryThreatFocus() const { return m_makesTargetSecondaryFocus; }

        void SetTriggered(bool t) { m_spellTriggered = t; }
        bool IsTriggered() const { return m_spellTriggered; }

        time_t GetApplyTime() const { return m_applyTime; }
        int32 GetMaxDuration() const { return m_maxDuration; }
        void SetMaxDuration(int32 duration) { m_maxDuration = duration; }
        int32 CalcMaxDuration() const { return CalcMaxDuration(GetCaster()); }
        int32 CalcMaxDuration(Unit* caster) const;
        static int32 CalcMaxDuration(SpellInfo const* spellInfo, WorldObject* caster);
        int32 GetDuration() const { return m_duration; }
        void SetDuration(int32 duration, bool withMods = false);
        void RefreshDuration(bool withMods = false);
        void RefreshTimers(bool resetPeriodicTimer);
        bool IsExpired() const { return !GetDuration() && !m_dropEvent; }
        bool IsPermanent() const { return GetMaxDuration() == -1; }
        ~SpellAuraHolder();
    private:
        void UpdateAuraApplication();                       // called at charges or stack changes

        Unit* m_target;
        ObjectGuid m_casterGuid;
        ObjectGuid m_realCasterGuid;
        ObjectGuid m_castItemGuid;                          // it is NOT safe to keep a pointer to the item because it may get deleted
        time_t m_applyTime;

        uint8 GetStackAmount() const { return m_stackAmount; }
        void SetStackAmount(uint8 num);
        bool ModStackAmount(int32 num, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT, bool resetPeriodicTimer = true);
        uint32 CalcMaxStackAmount() const;
        bool IsUsingStacks() const;
        SpellEntry const* m_spellProto;

        uint8 m_auraSlot;                                   // Aura slot on unit (for show in client)
        uint8 m_auraLevel;                                  // Aura level (store caster level for correct show level dep amount)
        uint32 m_procCharges;                               // Aura charges (0 for infinite)
        uint32 m_stackAmount;                               // Aura stack amount
        int32 m_maxDuration;                                // Max aura duration
        int32 m_duration;                                   // Current time
        int32 m_timeCla;                                    // Timer for power per sec calculation

        AuraRemoveMode m_removeMode:8;                      // Store info for know remove aura reason
        DiminishingGroup m_AuraDRGroup:8;                   // Diminishing
        DiminishingLevels m_AuraDRLevel:8;

        bool m_permanent:1;
        bool m_isPassive:1;
        bool m_isDeathPersist:1;
        bool m_isRemovedOnShapeLost:1;
        bool m_isSingleTarget:1;                            // true if it's a single target spell and registered at caster - can change at spell steal for example
        bool m_deleted:1;
        bool m_isChanneled:1;
        bool m_makesTargetSecondaryFocus;
        bool m_spellTriggered;                              // applied by a triggered spell (used in debuff priority computation)

        bool IsRemovedOnShapeLost(Unit* target) const;
        uint32 m_in_use;                                    // > 0 while in SpellAuraHolder::ApplyModifiers call/SpellAuraHolder::Update/etc
};

typedef void(Aura::*pAuraHandler)(bool Apply, bool Real);
// Real == true at aura add/remove
// Real == false at aura mod unapply/reapply; when adding/removing dependent aura/item/stat mods
//
// Code in aura handler can be guarded by if (Real) check if it should execution only at real add/remove of aura
//
// MAIN RULE: Code MUST NOT be guarded by if (Real) check if it modifies any stats
//      (percent auras, stats mods, etc)
// Second rule: Code must be guarded by if (Real) check if it modifies object state (start/stop attack, send packets to client, etc)
//
// Other case choice: each code line moved under if (Real) check is mangos speedup,
//      each setting object update field code line moved under if (Real) check is significant mangos speedup, and less server->client data sends
//      each packet sending code moved under if (Real) check is _large_ mangos speedup, and lot less server->client data sends

class Aura
{
    friend struct ReapplyAffectedPassiveAurasHelper;
    friend Aura* CreateAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster, Item* castItem);

    public:
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
        void HandleModConfuse(bool Apply, bool Real);
        void HandleModCharm(bool Apply, bool Real);
        void HandleModFear(bool Apply, bool Real);
        void HandlePeriodicHeal(bool Apply, bool Real);
        void HandleModAttackSpeed(bool Apply, bool Real);
        void HandleModThreat(bool Apply, bool Real);
        void HandleModTaunt(bool Apply, bool Real);
        void HandleFeignDeath(bool Apply, bool Real);
        void HandleAuraModDisarm(bool Apply, bool Real);
        void HandleAuraModStalked(bool Apply, bool Real);
        void HandleAuraWaterWalk(bool Apply, bool Real);
        void HandleAuraFeatherFall(bool Apply, bool Real);
        void HandleAuraHover(bool Apply, bool Real);
        void HandleAddModifier(bool Apply, bool Real);
        void HandleAuraModStun(bool Apply, bool Real);
        void HandleModDamageDone(bool Apply, bool Real);
        void HandleAuraUntrackable(bool Apply, bool Real);
        void HandleAuraEmpathy(bool Apply, bool Real);
        void HandleModOffhandDamagePercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPower(bool Apply, bool Real);
        void HandleAuraModIncreaseEnergyPercent(bool Apply, bool Real);
        void HandleAuraModIncreaseHealthPercent(bool Apply, bool Real);
        void HandleAuraModRegenInterrupt(bool Apply, bool Real);
        void HandleModMeleeSpeedPct(bool Apply, bool Real);
        void HandlePeriodicTriggerSpell(bool Apply, bool Real);
        void HandlePeriodicTriggerSpellWithValue(bool apply, bool Real);
        void HandlePeriodicEnergize(bool Apply, bool Real);
        void HandleAuraModResistanceExclusive(bool Apply, bool Real);
        void HandleAuraSafeFall(bool Apply, bool Real);
        void HandleModStealth(bool Apply, bool Real);
        void HandleInvisibility(bool Apply, bool Real);
        void HandleInvisibilityDetect(bool Apply, bool Real);
        void HandleAuraModTotalHealthPercentRegen(bool Apply, bool Real);
        void HandleAuraModTotalManaPercentRegen(bool Apply, bool Real);
        void HandleAuraModResistance(bool Apply, bool Real);
        void HandleAuraModRoot(bool Apply, bool Real);
        void HandleAuraModSilence(bool Apply, bool Real);
        void HandleAuraModStat(bool Apply, bool Real);
        void HandleAuraModIncreaseSpeed(bool Apply, bool Real);
        void HandleAuraModIncreaseMountedSpeed(bool Apply, bool Real);
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
        void HandleModWaterBreathing(bool apply, bool Real);
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
        void HandleReflectSpellsSchool(bool Apply, bool Real);
        void HandleFarSight(bool Apply, bool Real);
        void HandleModPossessPet(bool Apply, bool Real);
        void HandleModMechanicImmunity(bool Apply, bool Real);
        void HandleModMechanicImmunityMask(bool Apply, bool Real);
        void HandleAuraModSkill(bool Apply, bool Real);
        void HandleModDamagePercentDone(bool Apply, bool Real);
        void HandleModPercentStat(bool Apply, bool Real);
        void HandleAurasVisible(bool Apply, bool Real);
        void HandleModResistancePercent(bool Apply, bool Real);
        void HandleAuraModBaseResistancePercent(bool Apply, bool Real);
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
        void HandleAuraModAttackPowerPercent(bool apply, bool Real);
        void HandleAuraModRangedAttackPowerPercent(bool apply, bool Real);
        void HandleSpiritOfRedemption(bool apply, bool Real);
        void HandleAuraAoeCharm(bool apply, bool real);
        void HandleShieldBlockValue(bool apply, bool Real);
        void HandleModSpellCritChanceSchool(bool apply, bool Real);
        void HandleAuraRetainComboPoints(bool apply, bool Real);
        void HandleModSpellDamagePercentFromStat(bool apply, bool Real);
        void HandleModSpellHealingPercentFromStat(bool apply, bool Real);
        void HandleAuraModPacifyAndSilence(bool Apply, bool Real);
        void HandleAuraModResistenceOfStatPercent(bool apply, bool Real);
        void HandleAuraPowerBurn(bool apply, bool Real);
        void HandleSchoolAbsorb(bool apply, bool Real);
        void HandlePreventFleeing(bool apply, bool Real);
        void HandleManaShield(bool apply, bool Real);
        // Nostalrius
        void HandleAuraAuraSpell(bool apply, bool real);
        void HandleInterruptRegen(bool apply, bool real);

        virtual ~Aura();

        void SetModifier(AuraType t, float a, uint32 pt, int32 miscValue);
        Modifier*       GetModifier()       { return &m_modifier; }
        Modifier const* GetModifier() const { return &m_modifier; }
        int32 GetMiscValue() const;

        SpellEntry const* GetSpellProto() const { return GetHolder()->GetSpellProto(); }
        uint32 GetId() const{ return GetHolder()->GetId(); }
        ObjectGuid const& GetCastItemGuid() const { return GetHolder()->GetCastItemGuid(); }
        ObjectGuid const& GetCasterGuid() const { return GetHolder()->GetCasterGuid(); }
        ObjectGuid const& GetRealCasterGuid() const { return GetHolder()->GetRealCasterGuid(); }
        Unit* GetCaster() const { return GetHolder()->GetCaster(); }
        SpellCaster* GetRealCaster() const { return GetHolder()->GetRealCaster(); }
        Unit* GetTarget() const { return GetHolder()->GetTarget(); }

        bool HasEffect(uint8 effIndex) const { return GetEffect(effIndex) != nullptr; }
        bool HasEffectType(AuraType type) const;
        static bool EffectTypeNeedsSendingAmount(AuraType type);
        AuraEffect* GetEffect(uint32 index) const;
        uint32 GetEffectMask() const;
        void RecalculateAmountOfEffects();
        void HandleAllEffects(AuraApplication * aurApp, uint8 mode, bool apply);
        SpellEffectIndex GetEffIndex() const{ return m_effIndex; }
        int32 GetBasePoints() const { return m_currentBasePoints; }

        // Helpers for targets
        ApplicationMap const& GetApplicationMap() { return m_applications; }
        void GetApplicationVector(std::vector<AuraApplication*>& applicationVector) const;
        AuraApplication const* GetApplicationOfTarget(ObjectGuid guid) const { ApplicationMap::const_iterator itr = m_applications.find(guid); if (itr != m_applications.end()) return itr->second; return nullptr; }
        AuraApplication* GetApplicationOfTarget(ObjectGuid guid) { ApplicationMap::iterator itr = m_applications.find(guid); if (itr != m_applications.end()) return itr->second; return nullptr; }
        bool IsAppliedOnTarget(ObjectGuid guid) const { return m_applications.find(guid) != m_applications.end(); }
        int32 GetAuraMaxDuration() const { return GetHolder()->GetAuraMaxDuration(); }
        int32 GetAuraDuration() const { return GetHolder()->GetAuraDuration(); }
        time_t GetAuraApplyTime() const { return m_applyTime; }
        uint32 GetAuraTicks() const { return m_periodicTick; }
        int32 GetAuraPeriodicTimer() const { return m_periodicTimer; }
        uint32 GetAuraMaxTicks() const
        {
            int32 maxDuration = GetAuraMaxDuration();
            return maxDuration > 0 && m_modifier.periodictime > 0 ? maxDuration / m_modifier.periodictime : 0;
        }
        uint32 GetStackAmount() const { return GetHolder()->GetStackAmount(); }

        void SetNeedClientUpdateForTargets() const;
        void HandleAuraSpecificMods(AuraApplication const* aurApp, Unit* caster, bool apply, bool onReapply);
        bool CanBeAppliedOn(Unit* target);
        bool CheckAreaTarget(Unit* target);
        bool CanStackWith(Aura const* existingAura) const;
        void CalculatePeriodic(Player* modOwner, bool create);
        void SetLoadedState(float damage, uint32 periodicTime)
        {
            m_modifier.m_amount = damage;
            m_modifier.periodictime = periodicTime;

        bool IsProcOnCooldown(TimePoint now) const;
        void AddProcCooldown(SpellProcEntry const* procEntry, TimePoint now);
        void ResetProcCooldown();
        bool IsUsingCharges() const { return m_isUsingCharges; }
        void SetUsingCharges(bool val) { m_isUsingCharges = val; }
        void PrepareProcToTrigger(AuraApplication* aurApp, ProcEventInfo& eventInfo, TimePoint now);
        void PrepareProcChargeDrop(SpellProcEntry const* procEntry, ProcEventInfo const& eventInfo);
        void ConsumeProcCharges(SpellProcEntry const* procEntry);
        uint32 GetProcEffectMask(AuraApplication* aurApp, ProcEventInfo& eventInfo, TimePoint now) const;
        float CalcProcChance(SpellProcEntry const& procEntry, ProcEventInfo& eventInfo) const;
        void TriggerProcOnEvent(uint32 procEffectMask, AuraApplication* aurApp, ProcEventInfo& eventInfo);
        float CalcPPMProcChance(Unit* actor) const;
        void SetLastProcAttemptTime(TimePoint lastProcAttemptTime) { m_lastProcAttemptTime = lastProcAttemptTime; }
        void SetLastProcSuccessTime(TimePoint lastProcSuccessTime) { m_lastProcSuccessTime = lastProcSuccessTime; }
            if (uint32 maxticks = GetAuraMaxTicks())
                m_periodicTick = maxticks - GetAuraDuration() / m_modifier.periodictime;
        }

        // AuraScript
        void LoadScripts();
        bool CallScriptCheckAreaTargetHandlers(Unit* target);
        void CallScriptDispel(DispelInfo* dispelInfo);
        void CallScriptAfterDispel(DispelInfo* dispelInfo);
        bool CallScriptEffectApplyHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode);
        bool CallScriptEffectRemoveHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode);
        void CallScriptAfterEffectApplyHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode);
        void CallScriptAfterEffectRemoveHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode);
        bool CallScriptEffectPeriodicHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp);
        void CallScriptEffectUpdatePeriodicHandlers(AuraEffect* aurEff);
        void CallScriptEffectCalcAmountHandlers(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated);
        void CallScriptEffectCalcPeriodicHandlers(AuraEffect const* aurEff, bool& isPeriodic, int32& amplitude);
        void CallScriptEffectCalcSpellModHandlers(AuraEffect const* aurEff, SpellModifier*& spellMod);
        void CallScriptEffectCalcCritChanceHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, Unit const* victim, float& critChance);
        void CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount, bool & defaultPrevented);
        void CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount);
        void CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, HealInfo& healInfo, uint32& absorbAmount, bool& defaultPrevented);
        void CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, HealInfo& healInfo, uint32& absorbAmount);
        void CallScriptEffectManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount, bool & defaultPrevented);
        void CallScriptEffectAfterManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount);
        void CallScriptEffectSplitHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& splitAmount);
        void CallScriptEnterLeaveCombatHandlers(AuraApplication const* aurApp, bool isNowInCombat);
        // Spell Proc Hooks
        bool CallScriptCheckProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        bool CallScriptCheckEffectProcHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        bool CallScriptPrepareProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        bool CallScriptProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        void CallScriptAfterProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        bool CallScriptEffectProcHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        void CallScriptAfterEffectProcHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo);
        bool IsPositive() const { return m_positive; }
        bool IsPersistent() const { return m_isPersistent; }
        bool IsAreaAura() const { return m_isAreaAura; }
        bool IsPeriodic() const { return m_isPeriodic; }
        bool IsInUse() const { return m_in_use; }
        bool IsChanneled() const { return GetHolder()->IsChanneled(); }
        // NOSTALRIUS
        void SetPositive(bool pos) { m_positive = pos; }
        void SetPersistent(bool on) { m_isPersistent = on; }
        // Auras exclusifs
        bool m_exclusive;
        bool m_applied;
        void ComputeExclusive();
        bool IsExclusive() const { return m_exclusive; }
        bool IsApplied() const { return m_applied; }
        // Results :
        // - 0 : Not in the same category.
        // - 1 : I am more important. I apply myself. 
        // - 2 : Other aura is more important. It applies. 
        int CheckExclusiveWith(Aura const* other) const;
        bool ExclusiveAuraCanApply();
        void ExclusiveAuraUnapply();
        // FIN NOSTALRIUS

        UnitAura* ToUnitAura() { if (GetType() == UNIT_AURA_TYPE) return reinterpret_cast<UnitAura*>(this); else return nullptr; }
        UnitAura const* ToUnitAura() const { if (GetType() == UNIT_AURA_TYPE) return reinterpret_cast<UnitAura const*>(this); else return nullptr; }

        DynObjAura* ToDynObjAura() { if (GetType() == DYNOBJ_AURA_TYPE) return reinterpret_cast<DynObjAura*>(this); else return nullptr; }
        DynObjAura const* ToDynObjAura() const { if (GetType() == DYNOBJ_AURA_TYPE) return reinterpret_cast<DynObjAura const*>(this); else return nullptr; }

        template <class Script>
        Script* GetScript() const
        {
            return static_cast<Script*>(GetScriptByType(typeid(Script)));
        void SetInUse(bool state)
        {
            if (state)
                ++m_in_use;
            else
            {
                if (m_in_use)
                    --m_in_use;
            }
        }
        // NOSTALRIUS: Ajout de 'skipCheckExclusive'
        void ApplyModifier(bool apply, bool Real = false, bool skipCheckExclusive = false);

        void UpdatePeriodicTimer(int32 duration);
        void UpdateAura(uint32 diff) { SetInUse(true); Update(diff); SetInUse(false); }
        // Called only in Aura::Update, for area aura owners to update affected targets
        virtual void UpdateForAffected(uint32 diff);
        void Refresh(Unit* caster, Unit* target, SpellAuraHolder* pRefreshWithHolder);

        void SetRemoveMode(AuraRemoveMode mode) { m_removeMode = mode; }
        AuraRemoveMode GetRemoveMode() const { return m_removeMode;  }

        virtual Unit* GetTriggerTarget() const { return m_spellAuraHolder->GetTarget(); }

        virtual std::string GetDebugInfo() const;

        Aura(Aura const&) = delete;
        Aura(Aura&&) = delete;

        Aura& operator=(Aura const&) = delete;
        Aura& operator=(Aura&&) = delete;

    private:
        AuraScript* GetScriptByType(std::type_info const& type) const;
        void _DeleteRemovedApplications();
        // add/remove SPELL_AURA_MOD_SHAPESHIFT (36) linked auras
        void HandleShapeshiftBoosts(bool apply);

    protected:
        SpellInfo const* const m_spellInfo;
        Difficulty const m_castDifficulty;
        ObjectGuid const m_castId;
        ObjectGuid const m_casterGuid;
        ObjectGuid const m_castItemGuid;                    // it is NOT safe to keep a pointer to the item because it may get deleted
        uint32 m_castItemId;
        int32 m_castItemLevel;
        SpellCastVisual const m_spellVisual;
        time_t const m_applyTime;
        WorldObject* const m_owner;
        void TriggerSpell();

        // more limited that used in future versions (spell_affect table based only), so need be careful with backporting uses
        bool isAffectedOnSpell(SpellEntry const* spell) const;
        bool CanProcFrom(SpellEntry const* spell, uint32 EventProcEx, uint32 procEx, bool active, bool useClassMask) const;

        SpellAuraHolder* GetHolder() const { return m_spellAuraHolder; }

        bool IsLastAuraOnHolder();
        SpellModifier* GetSpellModifier() const { return m_spellmod; }
    protected:
        Aura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = nullptr, Item* castItem = nullptr);

        // must be called only from Aura::UpdateAura
        virtual void Update(uint32 diff);

        // must be called only from Aura*::Update
        void PeriodicTick(SpellEntry const* sProto = nullptr, AuraType auraType = SPELL_AURA_NONE, uint32 data = 0);
        void PeriodicDummyTick();

        TimePoint m_procCooldown;
        TimePoint m_lastProcAttemptTime;
        TimePoint m_lastProcSuccessTime;
        float CalculateDotDamage() const;
        void ReapplyAffectedPassiveAuras();

    private:
        std::vector<AuraApplication*> _removedApplications;
        Modifier m_modifier;
        SpellModifier *m_spellmod;

        time_t m_applyTime;

class TC_GAME_API UnitAura : public Aura
{
    friend Aura* Aura::Create(AuraCreateInfo& createInfo);
    protected:
        explicit UnitAura(AuraCreateInfo const& createInfo);
    public:
        void _ApplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp) override;
        void _UnapplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp) override;
        int32 m_currentBasePoints;                          // cache SpellEntry::CalculateSimpleValue and use for set custom base points
        int32 m_periodicTimer;                              // Timer for periodic auras
        uint32 m_periodicTick;                              // Tick count pass (including current if use in tick code) from aura apply, used for some tick count dependent aura effects

        AuraRemoveMode m_removeMode:8;                      // Store info for know remove aura reason

        SpellEffectIndex m_effIndex :8;                     // Aura effect index in spell

        bool m_positive:1;
        bool m_isPeriodic:1;
        bool m_isAreaAura:1;
        bool m_isPersistent:1;

        uint32 m_in_use;                                    // > 0 while in Aura::ApplyModifier call/Aura::Update/etc

        void AddStaticApplication(Unit* target, uint32 effMask);

        SpellAuraHolder* const m_spellAuraHolder;
    private:
        DiminishingGroup m_AuraDRGroup;                 // Diminishing
        std::unordered_map<ObjectGuid, uint32> _staticApplications; // non-area auras
        void ReapplyAffectedPassiveAuras(Unit* target);
};

class AreaAura : public Aura
{
    public:
        AreaAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = nullptr, Item* castItem = nullptr, uint32 originalRankSpellId = 0);
        ~AreaAura() override;
    protected:
        void Update(uint32 diff) override;
        void UpdateForAffected(uint32 diff) override;
    private:
        float m_radius;
        AreaAuraType m_areaAuraType;
        uint32       m_originalRankSpellId;
};

class PersistentAreaAura : public Aura
{
    public:
        PersistentAreaAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = nullptr, Item* castItem = nullptr);
        ~PersistentAreaAura() override;
    protected:
        void Update(uint32 diff) override;
};

class SingleEnemyTargetAura : public Aura
{
    friend Aura* CreateAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster, Item* castItem);

    public:
        ~SingleEnemyTargetAura() override;
        Unit* GetTriggerTarget() const override;

    protected:
        SingleEnemyTargetAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = nullptr, Item* castItem = nullptr);
        ObjectGuid m_castersTargetGuid;
};

Aura* CreateAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32* currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster = nullptr, Item* castItem = nullptr);
SpellAuraHolder* CreateSpellAuraHolder(SpellEntry const* spellproto, Unit* target, Unit* caster, WorldObject* realCaster, Item* castItem = nullptr);
#endif
