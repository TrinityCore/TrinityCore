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

#ifndef TRINITY_SPELLAURAS_H
#define TRINITY_SPELLAURAS_H

#include "SpellAuraDefines.h"
#include "SpellInfo.h"
#include "UniqueTrackablePtr.h"
#include <typeinfo>

class SpellInfo;
struct SpellModifier;
struct ProcTriggerSpell;
struct SpellProcEntry;

namespace WorldPackets
{
    namespace Spells
    {
        struct AuraInfo;
    }
}

// forward decl
class Aura;
class AuraEffect;
class AuraScript;
class DamageInfo;
class DispelInfo;
class DynObjAura;
class ChargeDropEvent;
class DynamicObject;
class HealInfo;
class ProcEventInfo;
class Unit;
class UnitAura;

// update aura target map every 500 ms instead of every update - reduce amount of grid searcher calls
#define UPDATE_TARGET_MAP_INTERVAL 500

class TC_GAME_API AuraApplication
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
        Unit* GetTarget() const { return _target; }
        Aura* GetBase() const { return _base; }

        uint8 GetSlot() const { return _slot; }
        uint16 GetFlags() const { return _flags; }
        uint32 GetEffectMask() const { return _effectMask; }
        bool HasEffect(uint8 effect) const { ASSERT(effect < MAX_SPELL_EFFECTS); return (_effectMask & (1 << effect)) != 0; }
        bool IsPositive() const { return (_flags & AFLAG_POSITIVE) != 0; }
        bool IsSelfcast() const { return (_flags & AFLAG_NOCASTER) != 0; }

        uint32 GetEffectsToApply() const { return _effectsToApply; }
        void UpdateApplyEffectMask(uint32 newEffMask, bool canHandleNewEffects);

        void SetRemoveMode(AuraRemoveMode mode) { _removeMode = mode; }
        AuraRemoveMode GetRemoveMode() const { return _removeMode; }

        void SetNeedClientUpdate();
        bool IsNeedClientUpdate() const { return _needClientUpdate; }
        void BuildUpdatePacket(WorldPackets::Spells::AuraInfo& auraInfo, bool remove);
        void ClientUpdate(bool remove = false);

        std::string GetDebugInfo() const;
};

// Structure representing database aura primary key fields
struct AuraKey
{
    ObjectGuid Caster;
    ObjectGuid Item;
    uint32 SpellId;
    uint32 EffectMask;

    friend std::strong_ordering operator<=>(AuraKey const& left, AuraKey const& right) = default;
};

struct AuraLoadEffectInfo
{
    std::array<int32, MAX_SPELL_EFFECTS> Amounts;
    std::array<int32, MAX_SPELL_EFFECTS> BaseAmounts;
};

class TC_GAME_API Aura
{
    friend class Unit;

    public:
        typedef std::unordered_map<ObjectGuid, AuraApplication*> ApplicationMap;

        static uint32 BuildEffectMaskForOwner(SpellInfo const* spellProto, uint32 availableEffectMask, WorldObject* owner);
        static Aura* TryRefreshStackOrCreate(AuraCreateInfo& createInfo, bool updateEffectMask = true);
        static Aura* TryCreate(AuraCreateInfo& createInfo);
        static Aura* Create(AuraCreateInfo& createInfo);
        explicit Aura(AuraCreateInfo const& createInfo);
        void _InitEffects(uint32 effMask, Unit* caster, int32 const* baseAmount);
        void SaveCasterInfo(Unit* caster);
        virtual ~Aura();

        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        uint32 GetId() const{ return GetSpellInfo()->Id; }
        Difficulty GetCastDifficulty() const { return m_castDifficulty; }

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

        AuraObjectType GetType() const;

        virtual void _ApplyForTarget(Unit* target, Unit* caster, AuraApplication * auraApp);
        virtual void _UnapplyForTarget(Unit* target, Unit* caster, AuraApplication * auraApp);
        void _Remove(AuraRemoveMode removeMode);
        virtual void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT) = 0;

        virtual void FillTargetMap(std::unordered_map<Unit*, uint32>& targets, Unit* caster) = 0;
        void UpdateTargetMap(Unit* caster, bool apply = true);

        void _RegisterForTargets() { Unit* caster = GetCaster(); UpdateTargetMap(caster, false); }
        void ApplyForTargets() { Unit* caster = GetCaster(); UpdateTargetMap(caster, true); }
        void _ApplyEffectForTargets(uint8 effIndex);

        void UpdateOwner(uint32 diff, WorldObject* owner);
        void Update(uint32 diff, Unit* caster);

        time_t GetApplyTime() const { return m_applyTime; }
        int32 GetMaxDuration() const { return m_maxDuration; }
        void SetMaxDuration(int32 duration) { m_maxDuration = duration; }
        int32 CalcMaxDuration() const { return CalcMaxDuration(GetCaster()); }
        int32 CalcMaxDuration(Unit* caster) const;
        static int32 CalcMaxDuration(SpellInfo const* spellInfo, WorldObject const* caster, std::vector<SpellPowerCost> const* powerCosts);
        int32 GetDuration() const { return m_duration; }
        void SetDuration(int32 duration, bool withMods = false);
        void RefreshDuration(bool withMods = false);
        void RefreshTimers(bool resetPeriodicTimer);
        bool IsExpired() const { return !GetDuration() && !m_dropEvent; }
        bool IsPermanent() const { return GetMaxDuration() == -1; }

        uint8 GetCharges() const { return m_procCharges; }
        void SetCharges(uint8 charges);
        uint8 CalcMaxCharges(Unit* caster) const;
        uint8 CalcMaxCharges() const { return CalcMaxCharges(GetCaster()); }
        bool ModCharges(int32 num, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        bool DropCharge(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT) { return ModCharges(-1, removeMode); }
        void ModChargesDelayed(int32 num, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void DropChargeDelayed(uint32 delay, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        uint8 GetStackAmount() const { return m_stackAmount; }
        void SetStackAmount(uint8 num);
        bool ModStackAmount(int32 num, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT, bool resetPeriodicTimer = true);
        uint32 CalcMaxStackAmount() const;
        bool IsUsingStacks() const;

        uint8 GetCasterLevel() const { return m_casterLevel; }

        bool HasMoreThanOneEffectForType(AuraType auraType) const;
        bool IsArea() const;
        bool IsPassive() const;
        bool IsDeathPersistent() const;

        bool IsRemovedOnShapeLost(Unit* target) const;

        bool CanBeSaved() const;
        bool IsRemoved() const { return m_isRemoved; }
        // Single cast aura helpers
        bool IsSingleTarget() const {return m_isSingleTarget; }
        bool IsSingleTargetWith(Aura const* aura) const;
        void SetIsSingleTarget(bool val) { m_isSingleTarget = val; }
        void UnregisterSingleTarget();
        int32 CalcDispelChance(Unit const* auraTarget, bool offensive) const;

        /**
        * @fn AuraKey Aura::GenerateKey(uint32& recalculateMask) const
        *
        * @brief Fills a helper structure containing aura primary key for `character_aura`, `character_aura_effect`, `pet_aura`, `pet_aura_effect` tables.
        *
        * @param [out] recalculateMask Mask of effects that can be recalculated to store in database - not part of aura key.
        *
        * @return Aura key.
        */
        AuraKey GenerateKey(uint32& recalculateMask) const;
        void SetLoadedState(int32 maxDuration, int32 duration, int32 charges, uint8 stackAmount, uint32 recalculateMask, int32* amount);

        bool HasEffect(uint8 effIndex) const { return GetEffect(effIndex) != nullptr; }
        bool HasEffectType(AuraType type) const;
        static bool EffectTypeNeedsSendingAmount(AuraType type);
        AuraEffect* GetEffect(uint32 index) const;
        uint32 GetEffectMask() const;
        void RecalculateAmountOfEffects();
        void HandleAllEffects(AuraApplication * aurApp, uint8 mode, bool apply);

        // Helpers for targets
        ApplicationMap const& GetApplicationMap() { return m_applications; }
        void GetApplicationVector(std::vector<AuraApplication*>& applications) const;
        AuraApplication const* GetApplicationOfTarget(ObjectGuid guid) const;
        AuraApplication* GetApplicationOfTarget(ObjectGuid guid);
        bool IsAppliedOnTarget(ObjectGuid guid) const;

        void SetNeedClientUpdateForTargets() const;
        void HandleAuraSpecificMods(AuraApplication const* aurApp, Unit* caster, bool apply, bool onReapply);
        bool CanBeAppliedOn(Unit* target);
        bool CheckAreaTarget(Unit* target);
        bool CanStackWith(Aura const* existingAura) const;

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
        virtual void Heartbeat() { }

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
        void CallScriptCalcDamageAndHealingHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod);
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

        UnitAura* ToUnitAura() { if (GetType() == UNIT_AURA_TYPE) return reinterpret_cast<UnitAura*>(this); else return nullptr; }
        UnitAura const* ToUnitAura() const { if (GetType() == UNIT_AURA_TYPE) return reinterpret_cast<UnitAura const*>(this); else return nullptr; }

        DynObjAura* ToDynObjAura() { if (GetType() == DYNOBJ_AURA_TYPE) return reinterpret_cast<DynObjAura*>(this); else return nullptr; }
        DynObjAura const* ToDynObjAura() const { if (GetType() == DYNOBJ_AURA_TYPE) return reinterpret_cast<DynObjAura const*>(this); else return nullptr; }

        template <class Script>
        Script* GetScript() const
        {
            return static_cast<Script*>(GetScriptByType(typeid(Script)));
        }

        std::vector<AuraScript*> m_loadedScripts;

        AuraEffectVector const& GetAuraEffects() const { return _effects; }

        virtual std::string GetDebugInfo() const;

        Trinity::unique_weak_ptr<Aura> GetWeakPtr() const { return m_scriptRef; }

        Aura(Aura const&) = delete;
        Aura(Aura&&) = delete;

        Aura& operator=(Aura const&) = delete;
        Aura& operator=(Aura&&) = delete;

    private:
        AuraScript* GetScriptByType(std::type_info const& type) const;
        void _DeleteRemovedApplications();

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

        int32 m_maxDuration;                                // Max aura duration
        int32 m_duration;                                   // Current time
        int32 m_timeCla;                                    // Timer for power per sec calcultion
        std::vector<SpellPowerEntry const*> m_periodicCosts;// Periodic costs
        int32 m_updateTargetMapInterval;                    // Timer for UpdateTargetMapOfEffect

        uint8 const m_casterLevel;                          // Aura level (store caster level for correct show level dep amount)
        uint8 m_procCharges;                                // Aura charges (0 for infinite)
        uint8 m_stackAmount;                                // Aura stack amount

        ApplicationMap m_applications;

        bool m_isRemoved;
        bool m_isSingleTarget;                              // true if it's a single target spell and registered at caster - can change at spell steal for example
        bool m_isUsingCharges;

        ChargeDropEvent* m_dropEvent;

        TimePoint m_procCooldown;
        TimePoint m_lastProcAttemptTime;
        TimePoint m_lastProcSuccessTime;

    private:
        std::vector<AuraApplication*> _removedApplications;

        AuraEffectVector _effects;

        struct NoopAuraDeleter { void operator()(Aura*) const { /*noop - not managed*/ } };
        Trinity::unique_trackable_ptr<Aura> m_scriptRef;
};

class TC_GAME_API UnitAura : public Aura
{
    friend Aura* Aura::Create(AuraCreateInfo& createInfo);
    protected:
        explicit UnitAura(AuraCreateInfo const& createInfo);
    public:
        void _ApplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp) override;
        void _UnapplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp) override;

        void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT) override;

        void FillTargetMap(std::unordered_map<Unit*, uint32>& targets, Unit* caster) override;

        // Allow Apply Aura Handler to modify and access m_AuraDRGroup
        void SetDiminishGroup(DiminishingGroup group) { m_AuraDRGroup = group; }
        DiminishingGroup GetDiminishGroup() const { return m_AuraDRGroup; }

        void AddStaticApplication(Unit* target, uint32 effMask);

        void Heartbeat() override;
        void HandlePeriodicFoodSpellVisualKit();

    private:
        DiminishingGroup m_AuraDRGroup;                 // Diminishing
        std::unordered_map<ObjectGuid, uint32> _staticApplications; // non-area auras
};

class TC_GAME_API DynObjAura : public Aura
{
    friend Aura* Aura::Create(AuraCreateInfo& createInfo);
    protected:
        explicit DynObjAura(AuraCreateInfo const& createInfo);
    public:
        DynObjAura(SpellInfo const* spellproto, ObjectGuid castId, uint32 effMask, WorldObject* owner, Unit* caster, Difficulty castDifficulty, int32 *baseAmount, Item* castItem, ObjectGuid casterGUID, ObjectGuid castItemGuid, uint32 castItemId, int32 castItemLevel);

        void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT) override;

        void FillTargetMap(std::unordered_map<Unit*, uint32>& targets, Unit* caster) override;
};

#endif
