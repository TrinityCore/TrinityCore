/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

class Unit;
struct SpellEntry;
struct SpellModifier;
struct ProcTriggerSpell;

// forward decl
class AuraEffect;
class Aura;
class DynamicObject;
class AuraScript;

// update aura target map every 500 ms instead of every update - reduce amount of grid searcher calls
#define UPDATE_TARGET_MAP_INTERVAL 500

class AuraApplication
{
    friend void Unit::_ApplyAura(AuraApplication * aurApp, uint8 effMask);
    friend void Unit::_UnapplyAura(AuraApplicationMap::iterator &i, AuraRemoveMode removeMode);
    friend void Unit::_ApplyAuraEffect(Aura * aura, uint8 effIndex);
    friend AuraApplication * Unit::_CreateAuraApplication(Aura * aura, uint8 effMask);
    private:
        Unit * const m_target;
        Aura * const m_base;
        uint8 m_slot;                                   // Aura slot on unit
        uint8 m_flags;                                  // Aura info flag
        uint8 m_effectsToApply;                         // Used only at spell hit to determine which effect should be applied
        AuraRemoveMode m_removeMode:8;                  // Store info for know remove aura reason
        bool m_needClientUpdate:1;
        bool m_isNeedManyNegativeEffects:1;

        explicit AuraApplication(Unit * target, Unit * caster, Aura * base, uint8 effMask);
        void _Remove();
    private:
        bool _CheckPositive(Unit * caster) const;
        void _HandleEffect(uint8 effIndex, bool apply);
    public:

        Unit * GetTarget() const { return m_target; }
        Aura * GetBase() const { return m_base; }

        uint8 GetSlot() const { return m_slot; }
        uint8 GetFlags() const { return m_flags; }
        uint8 GetEffectMask() const { return m_flags & (AFLAG_EFF_INDEX_0 | AFLAG_EFF_INDEX_1 | AFLAG_EFF_INDEX_2); }
        bool HasEffect(uint8 effect) const { ASSERT(effect < MAX_SPELL_EFFECTS);  return m_flags & (1<<effect); }
        bool IsPositive() const { return m_flags & AFLAG_POSITIVE; }
        uint8 GetEffectsToApply() const { return m_effectsToApply; }

        void SetRemoveMode(AuraRemoveMode mode) { m_removeMode = mode; }
        AuraRemoveMode GetRemoveMode() const {return m_removeMode;}

        void SetNeedClientUpdate() { m_needClientUpdate = true;}
        bool IsNeedClientUpdate() const { return m_needClientUpdate;}
        void ClientUpdate(bool remove = false);
};

class Aura
{
    public:
        typedef std::map<uint64, AuraApplication *> ApplicationMap;

        static Aura * TryCreate(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount = NULL, Item * castItem = NULL, uint64 casterGUID = 0);
        static Aura * TryCreate(SpellEntry const* spellproto, WorldObject * owner, Unit * caster, int32 *baseAmount = NULL, Item * castItem = NULL, uint64 casterGUID = 0);
        static Aura * Create(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount = NULL, Item * castItem = NULL, uint64 casterGUID = 0);
        explicit Aura(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID);
        ~Aura();

        SpellEntry const* GetSpellProto() const { return m_spellProto; }
        uint32 GetId() const{ return GetSpellProto()->Id; }

        uint64 GetCastItemGUID() const { return m_castItemGuid; }
        uint64 const& GetCasterGUID() const { return m_casterGuid; }
        Unit* GetCaster() const;
        WorldObject * GetOwner() const { return m_owner; }
        Unit * GetUnitOwner() const { ASSERT(GetType() == UNIT_AURA_TYPE); return (Unit*)m_owner; }
        DynamicObject * GetDynobjOwner() const { ASSERT(GetType() == DYNOBJ_AURA_TYPE); return (DynamicObject*)m_owner; }

        AuraObjectType GetType() const;

        virtual void _ApplyForTarget(Unit * target, Unit * caster, AuraApplication * auraApp);
        virtual void _UnapplyForTarget(Unit * target, Unit * caster, AuraApplication * auraApp);
        void _Remove(AuraRemoveMode removeMode);
        virtual void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT) = 0;

        virtual void FillTargetMap(std::map<Unit *, uint8> & targets, Unit * caster) = 0;
        void UpdateTargetMap(Unit * caster, bool apply = true);

        void _RegisterForTargets() {Unit * caster = GetCaster(); UpdateTargetMap(caster, false);}
        void ApplyForTargets() {Unit * caster = GetCaster(); UpdateTargetMap(caster, true);}
        void _ApplyEffectForTargets(uint8 effIndex);

        void UpdateOwner(uint32 diff, WorldObject * owner);
        void Update(uint32 diff, Unit * caster);

        time_t GetApplyTime() const { return m_applyTime; }
        int32 GetMaxDuration() const { return m_maxDuration; }
        void SetMaxDuration(int32 duration) { m_maxDuration = duration; }
        int32 GetDuration() const { return m_duration; }
        void SetDuration(int32 duration, bool withMods = false);
        void RefreshDuration();
        bool IsExpired() const { return !GetDuration();}
        bool IsPermanent() const { return GetMaxDuration() == -1; }

        uint8 GetCharges() const { return m_procCharges; }
        void SetCharges(uint8 charges);
        bool DropCharge();

        uint8 GetStackAmount() const { return m_stackAmount; }
        void SetStackAmount(uint8 num, bool applied = true);
        bool ModStackAmount(int32 num); // return true if last charge dropped

        uint8 GetCasterLevel() const { return m_casterLevel; }

        bool IsPassive() const;
        bool IsDeathPersistent() const;
        bool IsRemovedOnShapeLost(Unit * target) const { return (GetCasterGUID() == target->GetGUID() && m_spellProto->Stances && !(m_spellProto->AttributesEx2 & SPELL_ATTR2_NOT_NEED_SHAPESHIFT) && !(m_spellProto->Attributes & SPELL_ATTR0_NOT_SHAPESHIFT)); }
        bool CanBeSaved() const;
        bool IsRemoved() const { return m_isRemoved; }
        bool IsVisible() const;
        // Single cast aura helpers
        bool IsSingleTarget() const {return m_isSingleTarget;}
        void SetIsSingleTarget(bool val) { m_isSingleTarget = val;}
        void UnregisterSingleTarget();

        void SetLoadedState(int32 maxduration, int32 duration, int32 charges, uint8 stackamount, uint8 recalculateMask, int32 * amount);

        // helpers for aura effects
        bool HasEffect(uint8 effIndex) const { return bool(GetEffect(effIndex)); }
        bool HasEffectType(AuraType type) const;
        AuraEffect * GetEffect(uint8 effIndex) const { ASSERT (effIndex < MAX_SPELL_EFFECTS); return m_effects[effIndex]; }
        uint8 GetEffectMask() const { uint8 effMask = 0; for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i) if (m_effects[i]) effMask |= 1<<i; return effMask; }
        void RecalculateAmountOfEffects();
        void HandleAllEffects(AuraApplication const * aurApp, uint8 mode, bool apply);

        // Helpers for targets
        ApplicationMap const & GetApplicationMap() {return m_applications;}
        const AuraApplication * GetApplicationOfTarget (uint64 const & guid) const { ApplicationMap::const_iterator itr = m_applications.find(guid); if (itr != m_applications.end()) return itr->second; return NULL; }
        AuraApplication * GetApplicationOfTarget (uint64 const & guid) { ApplicationMap::iterator itr = m_applications.find(guid); if (itr != m_applications.end()) return itr->second; return NULL; }
        bool IsAppliedOnTarget(uint64 const & guid) const { return m_applications.find(guid) != m_applications.end(); }

        void SetNeedClientUpdateForTargets() const;
        void HandleAuraSpecificMods(AuraApplication const * aurApp, Unit * caster, bool apply);
        bool CanBeAppliedOn(Unit *target);
        bool CheckAreaTarget(Unit *target);

        // AuraScript
        void LoadScripts();
        bool CallScriptEffectApplyHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode);
        bool CallScriptEffectRemoveHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode);
        bool CallScriptEffectPeriodicHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp);
        void CallScriptEffectUpdatePeriodicHandlers(AuraEffect * aurEff);
        void CallScriptEffectCalcAmountHandlers(AuraEffect const * aurEff, int32 & amount, bool & canBeRecalculated);
        void CallScriptEffectCalcPeriodicHandlers(AuraEffect const * aurEff, bool & isPeriodic, int32 & amplitude);
        void CallScriptEffectCalcSpellModHandlers(AuraEffect const * aurEff, SpellModifier *& spellMod);
        std::list<AuraScript *> m_loadedScripts;
    private:
        void _DeleteRemovedApplications();
    protected:
        SpellEntry const * const m_spellProto;
        uint64 const m_casterGuid;
        uint64 const m_castItemGuid;                        // it is NOT safe to keep a pointer to the item because it may get deleted
        time_t const m_applyTime;
        WorldObject * const m_owner;                        //

        int32 m_maxDuration;                                // Max aura duration
        int32 m_duration;                                   // Current time
        int32 m_timeCla;                                    // Timer for power per sec calcultion
        int32 m_updateTargetMapInterval;                    // Timer for UpdateTargetMapOfEffect

        uint8 const m_casterLevel;                          // Aura level (store caster level for correct show level dep amount)
        uint8 m_procCharges;                                // Aura charges (0 for infinite)
        uint8 m_stackAmount;                                // Aura stack amount

        AuraEffect * m_effects[3];
        ApplicationMap m_applications;

        bool m_isRemoved:1;
        bool m_isSingleTarget:1;                        // true if it's a single target spell and registered at caster - can change at spell steal for example

    private:
        Unit::AuraApplicationList m_removedApplications;
};

class UnitAura : public Aura
{
    friend Aura * Aura::Create(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID);
    protected:
        explicit UnitAura(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID);
    public:
        void _ApplyForTarget(Unit * target, Unit * caster, AuraApplication * aurApp);
        void _UnapplyForTarget(Unit * target, Unit * caster, AuraApplication * aurApp);

        void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        void FillTargetMap(std::map<Unit *, uint8> & targets, Unit * caster);

        // Allow Apply Aura Handler to modify and access m_AuraDRGroup
        void SetDiminishGroup(DiminishingGroup group) { m_AuraDRGroup = group; }
        DiminishingGroup GetDiminishGroup() const { return m_AuraDRGroup; }

    private:
        DiminishingGroup m_AuraDRGroup:8;               // Diminishing
};

class DynObjAura : public Aura
{
    friend Aura * Aura::Create(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID);
    protected:
        explicit DynObjAura(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID);
    public:
        void Remove(AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        void FillTargetMap(std::map<Unit *, uint8> & targets, Unit * caster);
};
#endif
