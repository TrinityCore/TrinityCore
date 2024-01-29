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

#include "Common.h"
#include "CellImpl.h"
#include "Containers.h"
#include "DynamicObject.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "ListUtils.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "SpellScript.h"
#include "Unit.h"
#include "Util.h"
#include "Vehicle.h"
#include "World.h"
#include <sstream>

class ChargeDropEvent : public BasicEvent
{
public:
    ChargeDropEvent(Aura* base, AuraRemoveMode mode) : _base(base), _mode(mode) { }
    bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
    {
        // _base is always valid (look in Aura::_Remove())
        _base->ModChargesDelayed(-1, _mode);
        return true;
    }

private:
    Aura* _base;
    AuraRemoveMode _mode;
};

AuraCreateInfo::AuraCreateInfo(ObjectGuid castId, SpellInfo const* spellInfo, Difficulty castDifficulty, uint32 auraEffMask, WorldObject* owner) :
    _castId(castId), _spellInfo(spellInfo), _castDifficulty(castDifficulty), _auraEffectMask(auraEffMask), _owner(owner)
{
    ASSERT(spellInfo);
    ASSERT(auraEffMask);
    ASSERT(owner);

    ASSERT(auraEffMask <= MAX_EFFECT_MASK);
}

AuraApplication::AuraApplication(Unit* target, Unit* caster, Aura* aura, uint32 effMask) :
_target(target), _base(aura), _removeMode(AURA_REMOVE_NONE), _slot(MAX_AURAS),
_flags(AFLAG_NONE), _effectsToApply(effMask), _needClientUpdate(false), _effectMask(0)
{
    ASSERT(GetTarget() && GetBase());

    // Try find slot for aura
    uint8 slot = 0;
    // lookup for free slots in units visibleAuras
    for (AuraApplication* visibleAura : GetTarget()->GetVisibleAuras())
    {
        if (slot < visibleAura->GetSlot())
            break;

        ++slot;
    }

    // Register Visible Aura
    if (slot < MAX_AURAS)
    {
        _slot = slot;
        GetTarget()->SetVisibleAura(this);
        _needClientUpdate = true;
        TC_LOG_DEBUG("spells", "Aura: {} Effect: {} put to unit visible auras slot: {}", GetBase()->GetId(), GetEffectMask(), slot);
    }
    else
        TC_LOG_ERROR("spells", "Aura: {} Effect: {} could not find empty unit visible slot", GetBase()->GetId(), GetEffectMask());

    _InitFlags(caster, effMask);
}

void AuraApplication::_Remove()
{
    // update for out of range group members
    if (GetSlot() < MAX_AURAS)
    {
        GetTarget()->RemoveVisibleAura(this);
        ClientUpdate(true);
    }
}

void AuraApplication::_InitFlags(Unit* caster, uint32 effMask)
{
    // mark as selfcast if needed
    _flags |= (GetBase()->GetCasterGUID() == GetTarget()->GetGUID()) ? AFLAG_NOCASTER : AFLAG_NONE;

    // aura is cast by self or an enemy
    // one negative effect and we know aura is negative
    if (IsSelfcast() || !caster || !caster->IsFriendlyTo(GetTarget()))
    {
        bool negativeFound = false;
        for (uint8 i = 0; i < GetBase()->GetSpellInfo()->GetEffects().size(); ++i)
        {
            if (((1 << i) & effMask) && !GetBase()->GetSpellInfo()->IsPositiveEffect(i))
            {
                negativeFound = true;
                break;
            }
        }
        _flags |= negativeFound ? AFLAG_NEGATIVE : AFLAG_POSITIVE;
    }
    // aura is cast by friend
    // one positive effect and we know aura is positive
    else
    {
        bool positiveFound = false;
        for (uint8 i = 0; i < GetBase()->GetSpellInfo()->GetEffects().size(); ++i)
        {
            if (((1 << i) & effMask) && GetBase()->GetSpellInfo()->IsPositiveEffect(i))
            {
                positiveFound = true;
                break;
            }
        }
        _flags |= positiveFound ? AFLAG_POSITIVE : AFLAG_NEGATIVE;
    }

    auto effectNeedsAmount = [this](AuraEffect const* effect)
    {
        return effect && (GetEffectsToApply() & (1 << effect->GetEffIndex())) && Aura::EffectTypeNeedsSendingAmount(effect->GetAuraType());
    };

    if (GetBase()->GetSpellInfo()->HasAttribute(SPELL_ATTR8_AURA_POINTS_ON_CLIENT)
        || std::find_if(GetBase()->GetAuraEffects().begin(), GetBase()->GetAuraEffects().end(), std::cref(effectNeedsAmount)) != GetBase()->GetAuraEffects().end())
        _flags |= AFLAG_SCALABLE;

    if ((_flags & AFLAG_POSITIVE))
        if (!GetBase()->GetSpellInfo()->IsPassive() && !GetBase()->GetSpellInfo()->HasAttribute(SPELL_ATTR1_NO_AURA_ICON) && GetBase()->GetOwner()->GetGUID() == GetTarget()->GetGUID())
            _flags |= AFLAG_CANCELABLE;

    if (GetBase()->GetSpellInfo()->IsPassive())
        _flags |= AFLAG_PASSIVE;
}

void AuraApplication::_HandleEffect(uint8 effIndex, bool apply)
{
    AuraEffect* aurEff = GetBase()->GetEffect(effIndex);
    if (!aurEff)
    {
        TC_LOG_ERROR("spells", "Aura {} has no effect at effectIndex {} but _HandleEffect was called", GetBase()->GetSpellInfo()->Id, uint32(effIndex));
        return;
    }
    ASSERT(aurEff);
    ASSERT(HasEffect(effIndex) == (!apply));
    ASSERT((1<<effIndex) & _effectsToApply);
    TC_LOG_DEBUG("spells", "AuraApplication::_HandleEffect: {}, apply: {}: amount: {}", aurEff->GetAuraType(), apply, aurEff->GetAmount());

    if (apply)
    {
        ASSERT(!(_effectMask & (1<<effIndex)));
        _effectMask |= 1<<effIndex;
        aurEff->HandleEffect(this, AURA_EFFECT_HANDLE_REAL, true);
    }
    else
    {
        ASSERT(_effectMask & (1<<effIndex));
        _effectMask &= ~(1<<effIndex);
        aurEff->HandleEffect(this, AURA_EFFECT_HANDLE_REAL, false);
    }

    SetNeedClientUpdate();
}

void AuraApplication::UpdateApplyEffectMask(uint32 newEffMask, bool canHandleNewEffects)
{
    if (_effectsToApply == newEffMask)
        return;

    uint32 removeEffMask = (_effectsToApply ^ newEffMask) & (~newEffMask);
    uint32 addEffMask = (_effectsToApply ^ newEffMask) & (~_effectsToApply);

    // quick check, removes application completely
    if (removeEffMask == _effectsToApply && !addEffMask)
    {
        _target->_UnapplyAura(this, AURA_REMOVE_BY_DEFAULT);
        return;
    }

    // update real effects only if they were applied already
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (HasEffect(i) && (removeEffMask & (1 << i)))
            _HandleEffect(i, false);

    _effectsToApply = newEffMask;

    if (canHandleNewEffects)
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (addEffMask & (1 << i))
                _HandleEffect(i, true);
}

void AuraApplication::SetNeedClientUpdate()
{
    if (_needClientUpdate || GetRemoveMode() != AURA_REMOVE_NONE)
        return;

    _needClientUpdate = true;
    _target->SetVisibleAuraUpdate(this);
}

void AuraApplication::BuildUpdatePacket(WorldPackets::Spells::AuraInfo& auraInfo, bool remove)
{
    ASSERT(_target->HasVisibleAura(this) != remove);

    auraInfo.Slot = GetSlot();
    if (remove)
        return;

    Aura const* aura = GetBase();

    WorldPackets::Spells::AuraDataInfo& auraData = auraInfo.AuraData.emplace();
    auraData.CastID = aura->GetCastId();
    auraData.SpellID = aura->GetId();
    auraData.Visual = aura->GetSpellVisual();
    auraData.Flags = GetFlags();
    if (aura->GetType() != DYNOBJ_AURA_TYPE && aura->GetMaxDuration() > 0 && !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR5_DO_NOT_DISPLAY_DURATION))
        auraData.Flags |= AFLAG_DURATION;

    auraData.ActiveFlags = GetEffectMask();
    if (!aura->GetSpellInfo()->HasAttribute(SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL))
        auraData.CastLevel = aura->GetCasterLevel();
    else
        auraData.CastLevel = uint16(aura->GetCastItemLevel());

    // send stack amount for aura which could be stacked (never 0 - causes incorrect display) or charges
    // stack amount has priority over charges (checked on retail with spell 50262)
    auraData.Applications = aura->IsUsingStacks() ? aura->GetStackAmount() : aura->GetCharges();
    if (!aura->GetCasterGUID().IsUnit())
        auraData.CastUnit = ObjectGuid::Empty; // optional data is filled in, but cast unit contains empty guid in packet
    else if (!(auraData.Flags & AFLAG_NOCASTER))
        auraData.CastUnit = aura->GetCasterGUID();

    if (auraData.Flags & AFLAG_DURATION)
    {
        auraData.Duration = aura->GetMaxDuration();
        auraData.Remaining = aura->GetDuration();
    }

    if (auraData.Flags & AFLAG_SCALABLE)
    {
        auraData.Points.reserve(aura->GetAuraEffects().size());
        bool hasEstimatedAmounts = false;
        for (AuraEffect const* effect : GetBase()->GetAuraEffects())
        {
            if (effect && HasEffect(effect->GetEffIndex()))       // Not all of aura's effects have to be applied on every target
            {
                Trinity::Containers::EnsureWritableVectorIndex(auraData.Points, effect->GetEffIndex()) = float(effect->GetAmount());
                if (effect->GetEstimatedAmount())
                    hasEstimatedAmounts = true;
            }
        }
        if (hasEstimatedAmounts)
        {
            // When sending EstimatedPoints all effects (at least up to the last one that uses GetEstimatedAmount) must have proper value in packet
            auraData.EstimatedPoints.resize(auraData.Points.size());
            for (AuraEffect const* effect : GetBase()->GetAuraEffects())
                if (effect && HasEffect(effect->GetEffIndex()))       // Not all of aura's effects have to be applied on every target
                    auraData.EstimatedPoints[effect->GetEffIndex()] = effect->GetEstimatedAmount().value_or(effect->GetAmount());
        }
    }
}

void AuraApplication::ClientUpdate(bool remove)
{
    _needClientUpdate = false;

    WorldPackets::Spells::AuraUpdate update;
    update.UpdateAll = false;
    update.UnitGUID = GetTarget()->GetGUID();

    WorldPackets::Spells::AuraInfo auraInfo;
    BuildUpdatePacket(auraInfo, remove);
    update.Auras.push_back(auraInfo);

    _target->SendMessageToSet(update.Write(), true);
}

std::string AuraApplication::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << "Base: " << (GetBase() ? GetBase()->GetDebugInfo() : "NULL")
        << "\nTarget: " << (GetTarget() ? GetTarget()->GetDebugInfo() : "NULL");
    return sstr.str();
}

uint32 Aura::BuildEffectMaskForOwner(SpellInfo const* spellProto, uint32 availableEffectMask, WorldObject* owner)
{
    ASSERT_NODEBUGINFO(spellProto);
    ASSERT_NODEBUGINFO(owner);
    uint32 effMask = 0;
    switch (owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
            for (SpellEffectInfo const& spellEffectInfo : spellProto->GetEffects())
            {
                if (spellEffectInfo.IsUnitOwnedAuraEffect())
                    effMask |= 1 << spellEffectInfo.EffectIndex;
            }
            break;
        case TYPEID_DYNAMICOBJECT:
            for (SpellEffectInfo const& spellEffectInfo : spellProto->GetEffects())
            {
                if (spellEffectInfo.IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
                    effMask |= 1 << spellEffectInfo.EffectIndex;
            }
            break;
        default:
            ABORT();
            break;
    }

    return effMask & availableEffectMask;
}

Aura* Aura::TryRefreshStackOrCreate(AuraCreateInfo& createInfo, bool updateEffectMask)
{
    ASSERT_NODEBUGINFO(createInfo.Caster || !createInfo.CasterGUID.IsEmpty());

    if (createInfo.IsRefresh)
        *createInfo.IsRefresh = false;

    createInfo._auraEffectMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, createInfo._auraEffectMask, createInfo._owner);
    createInfo._targetEffectMask &= createInfo._auraEffectMask;

    uint32 effMask = createInfo._auraEffectMask;
    if (createInfo._targetEffectMask)
        effMask = createInfo._targetEffectMask;

    if (!effMask)
        return nullptr;

    if (Aura* foundAura = createInfo._owner->ToUnit()->_TryStackingOrRefreshingExistingAura(createInfo))
    {
        // we've here aura, which script triggered removal after modding stack amount
        // check the state here, so we won't create new Aura object
        if (foundAura->IsRemoved())
            return nullptr;

        if (createInfo.IsRefresh)
            *createInfo.IsRefresh = true;

        // add owner
        Unit* unit = createInfo._owner->ToUnit();

        // check effmask on owner application (if existing)
        if (updateEffectMask)
            if (AuraApplication* aurApp = foundAura->GetApplicationOfTarget(unit->GetGUID()))
                aurApp->UpdateApplyEffectMask(effMask, false);
        return foundAura;
    }
    else
        return Create(createInfo);
}

Aura* Aura::TryCreate(AuraCreateInfo& createInfo)
{
    uint32 effMask = createInfo._auraEffectMask;
    if (createInfo._targetEffectMask)
        effMask = createInfo._targetEffectMask;

    effMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, effMask, createInfo._owner);
    if (!effMask)
        return nullptr;

    return Create(createInfo);
}

Aura* Aura::Create(AuraCreateInfo& createInfo)
{
    // try to get caster of aura
    if (!createInfo.CasterGUID.IsEmpty())
    {
        if (createInfo.CasterGUID.IsUnit())
        {
            if (createInfo._owner->GetGUID() == createInfo.CasterGUID)
                createInfo.Caster = createInfo._owner->ToUnit();
            else
                createInfo.Caster = ObjectAccessor::GetUnit(*createInfo._owner, createInfo.CasterGUID);
        }
    }
    else if (createInfo.Caster)
        createInfo.CasterGUID = createInfo.Caster->GetGUID();

    // check if aura can be owned by owner
    if (createInfo._owner->isType(TYPEMASK_UNIT))
        if (!createInfo._owner->IsInWorld() || createInfo._owner->ToUnit()->IsDuringRemoveFromWorld())
            // owner not in world so don't allow to own not self cast single target auras
            if (createInfo.CasterGUID != createInfo._owner->GetGUID() && createInfo._spellInfo->IsSingleTarget())
                return nullptr;

    Aura* aura = nullptr;
    switch (createInfo._owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
        {
            aura = new UnitAura(createInfo);

            // aura can be removed in Unit::_AddAura call
            if (aura->IsRemoved())
                return nullptr;

            // add owner
            uint32 effMask = createInfo._auraEffectMask;
            if (createInfo._targetEffectMask)
                effMask = createInfo._targetEffectMask;

            effMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, effMask, createInfo._owner);
            ASSERT_NODEBUGINFO(effMask);

            Unit* unit = createInfo._owner->ToUnit();
            aura->ToUnitAura()->AddStaticApplication(unit, effMask);
            break;
        }
        case TYPEID_DYNAMICOBJECT:
            createInfo._auraEffectMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, createInfo._auraEffectMask, createInfo._owner);
            ASSERT_NODEBUGINFO(createInfo._auraEffectMask);

            aura = new DynObjAura(createInfo);
            break;
        default:
            ABORT();
            return nullptr;
    }

    // scripts, etc.
    if (aura->IsRemoved())
        return nullptr;

    return aura;
}

Aura::Aura(AuraCreateInfo const& createInfo) :
m_spellInfo(createInfo._spellInfo), m_castDifficulty(createInfo._castDifficulty), m_castId(createInfo._castId), m_casterGuid(createInfo.CasterGUID),
m_castItemGuid(createInfo.CastItemGUID), m_castItemId(createInfo.CastItemId),
m_castItemLevel(createInfo.CastItemLevel), m_spellVisual({ createInfo.Caster ? createInfo.Caster->GetCastSpellXSpellVisualId(createInfo._spellInfo) : createInfo._spellInfo->GetSpellXSpellVisualId() }),
m_applyTime(GameTime::GetGameTime()), m_owner(createInfo._owner), m_timeCla(0), m_updateTargetMapInterval(0),
m_casterLevel(createInfo.Caster ? createInfo.Caster->GetLevel() : m_spellInfo->SpellLevel), m_procCharges(0), m_stackAmount(1),
m_isRemoved(false), m_isSingleTarget(false), m_isUsingCharges(false), m_dropEvent(nullptr),
m_procCooldown(TimePoint::min()),
m_lastProcAttemptTime(GameTime::Now() - Seconds(10)), m_lastProcSuccessTime(GameTime::Now() - Seconds(120))
{
    for (SpellPowerEntry const* power : m_spellInfo->PowerCosts)
        if (power && (power->ManaPerSecond != 0 || power->PowerPctPerSecond > 0.0f))
            m_periodicCosts.push_back(power);

    if (!m_periodicCosts.empty())
        m_timeCla = 1 * IN_MILLISECONDS;

    m_maxDuration = CalcMaxDuration(createInfo.Caster);
    m_duration = m_maxDuration;
    m_procCharges = CalcMaxCharges(createInfo.Caster);
    m_isUsingCharges = m_procCharges != 0;
    // m_casterLevel = cast item level/caster level, caster level should be saved to db, confirmed with sniffs
}

AuraScript* Aura::GetScriptByType(std::type_info const& type) const
{
    for (AuraScript* script : m_loadedScripts)
        if (typeid(*script) == type)
            return script;
    return nullptr;
}

void Aura::_InitEffects(uint32 effMask, Unit* caster, int32 const* baseAmount)
{
    // shouldn't be in constructor - functions in AuraEffect::AuraEffect use polymorphism
    _effects.resize(GetSpellInfo()->GetEffects().size());

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        if (effMask & (1 << spellEffectInfo.EffectIndex))
            _effects[spellEffectInfo.EffectIndex] = new AuraEffect(this, spellEffectInfo, baseAmount ? baseAmount + spellEffectInfo.EffectIndex : nullptr, caster);
}

Aura::~Aura()
{
    // unload scripts
    for (AuraScript* script : m_loadedScripts)
    {
        script->_Unload();
        delete script;
    }

    for (AuraEffect* effect : _effects)
        delete effect;

    ASSERT(m_applications.empty());
    _DeleteRemovedApplications();
}

Unit* Aura::GetCaster() const
{
    if (GetOwner()->GetGUID() == GetCasterGUID())
        return GetUnitOwner();

    return ObjectAccessor::GetUnit(*GetOwner(), GetCasterGUID());
}

WorldObject* Aura::GetWorldObjectCaster() const
{
    if (GetCasterGUID().IsUnit())
        return GetCaster();

    return ObjectAccessor::GetWorldObject(*GetOwner(), GetCasterGUID());
}

AuraEffect* Aura::GetEffect(uint32 index) const
{
    if (index >= _effects.size())
        return nullptr;

    return _effects[index];
}

AuraObjectType Aura::GetType() const
{
    return (m_owner->GetTypeId() == TYPEID_DYNAMICOBJECT) ? DYNOBJ_AURA_TYPE : UNIT_AURA_TYPE;
}

void Aura::_ApplyForTarget(Unit* target, Unit* caster, AuraApplication* auraApp)
{
    ASSERT(target);
    ASSERT(auraApp);
    // aura mustn't be already applied on target
    ASSERT (!IsAppliedOnTarget(target->GetGUID()) && "Aura::_ApplyForTarget: aura musn't be already applied on target");

    m_applications[target->GetGUID()] = auraApp;

    // set infinity cooldown state for spells
    if (caster && caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_spellInfo->IsCooldownStartedOnEvent())
        {
            Item* castItem = !m_castItemGuid.IsEmpty() ? caster->ToPlayer()->GetItemByGuid(m_castItemGuid) : nullptr;
            caster->GetSpellHistory()->StartCooldown(m_spellInfo, castItem ? castItem->GetEntry() : 0, nullptr, true);
        }
    }
}

void Aura::_UnapplyForTarget(Unit* target, Unit* caster, AuraApplication* auraApp)
{
    ASSERT(target);
    ASSERT(auraApp->GetRemoveMode());
    ASSERT(auraApp);

    ApplicationMap::iterator itr = m_applications.find(target->GetGUID());

    /// @todo Figure out why this happens
    if (itr == m_applications.end())
    {
        TC_LOG_ERROR("spells", "Aura::_UnapplyForTarget, target: {}, caster: {}, spell:{} was not found in owners application map!",
        target->GetGUID().ToString(), caster ? caster->GetGUID().ToString().c_str() : "Empty", auraApp->GetBase()->GetSpellInfo()->Id);
        ABORT();
    }

    // aura has to be already applied
    ASSERT(itr->second == auraApp);
    m_applications.erase(itr);

    _removedApplications.push_back(auraApp);

    // reset cooldown state for spells
    if (caster && GetSpellInfo()->IsCooldownStartedOnEvent())
        // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existed cases)
        caster->GetSpellHistory()->SendCooldownEvent(GetSpellInfo());
}

// removes aura from all targets
// and marks aura as removed
void Aura::_Remove(AuraRemoveMode removeMode)
{
    ASSERT (!m_isRemoved);
    m_isRemoved = true;
    ApplicationMap::iterator appItr = m_applications.begin();
    for (appItr = m_applications.begin(); appItr != m_applications.end();)
    {
        AuraApplication * aurApp = appItr->second;
        Unit* target = aurApp->GetTarget();
        target->_UnapplyAura(aurApp, removeMode);
        appItr = m_applications.begin();
    }

    if (m_dropEvent)
    {
        m_dropEvent->ScheduleAbort();
        m_dropEvent = nullptr;
    }
}

void Aura::UpdateTargetMap(Unit* caster, bool apply)
{
    if (IsRemoved())
        return;

    m_updateTargetMapInterval = UPDATE_TARGET_MAP_INTERVAL;

    // fill up to date target list
    //                 target, effMask
    std::unordered_map<Unit*, uint32> targets;

    FillTargetMap(targets, caster);

    std::vector<Unit*> targetsToRemove;

    // mark all auras as ready to remove
    for (auto const& applicationPair : m_applications)
    {
        auto itr = targets.find(applicationPair.second->GetTarget());
        // not found in current area - remove the aura
        if (itr == targets.end())
            targetsToRemove.push_back(applicationPair.second->GetTarget());
        else
        {
            // needs readding - remove now, will be applied in next update cycle
            // (dbcs do not have auras which apply on same type of targets but have different radius, so this is not really needed)
            if (itr->first->IsImmunedToSpell(GetSpellInfo(), caster, true) || !CanBeAppliedOn(itr->first))
            {
                targetsToRemove.push_back(applicationPair.second->GetTarget());
                continue;
            }

            // check target immunities (for existing targets)
            for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
                if (itr->first->IsImmunedToSpellEffect(GetSpellInfo(), spellEffectInfo, caster, true))
                    itr->second &= ~(1 << spellEffectInfo.EffectIndex);

            // needs to add/remove effects from application, don't remove from map so it gets updated
            if (applicationPair.second->GetEffectMask() != itr->second)
                continue;

            // nothing to do - aura already applied
            // remove from auras to register list
            targets.erase(itr);
        }
    }

    // register auras for units
    for (auto itr = targets.begin(); itr != targets.end();)
    {
        bool addUnit = true;
        AuraApplication* aurApp = GetApplicationOfTarget(itr->first->GetGUID());
        if (!aurApp)
        {
            // check target immunities (for new targets)
            for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
                if (itr->first->IsImmunedToSpellEffect(GetSpellInfo(), spellEffectInfo, caster))
                    itr->second &= ~(1 << spellEffectInfo.EffectIndex);

            if (!itr->second || itr->first->IsImmunedToSpell(GetSpellInfo(), caster) || !CanBeAppliedOn(itr->first))
                addUnit = false;
        }

        if (addUnit && !itr->first->IsHighestExclusiveAura(this, true))
            addUnit = false;

        // Dynobj auras don't hit flying targets
        if (GetType() == DYNOBJ_AURA_TYPE && itr->first->IsInFlight())
            addUnit = false;

        // Do not apply aura if it cannot stack with existing auras
        if (addUnit)
        {
            // Allow to remove by stack when aura is going to be applied on owner
            if (itr->first != GetOwner())
            {
                // check if not stacking aura already on target
                // this one prevents unwanted usefull buff loss because of stacking and prevents overriding auras periodicaly by 2 near area aura owners
                for (Unit::AuraApplicationMap::iterator iter = itr->first->GetAppliedAuras().begin(); iter != itr->first->GetAppliedAuras().end(); ++iter)
                {
                    Aura const* aura = iter->second->GetBase();
                    if (!CanStackWith(aura))
                    {
                        addUnit = false;
                        break;
                    }
                }
            }
        }

        if (!addUnit)
            itr = targets.erase(itr);
        else
        {
            // owner has to be in world, or effect has to be applied to self
            if (!GetOwner()->IsSelfOrInSameMap(itr->first))
            {
                /// @todo There is a crash caused by shadowfiend load addon
                TC_LOG_FATAL("spells", "Aura {}: Owner {} (map {}) is not in the same map as target {} (map {}).", GetSpellInfo()->Id,
                    GetOwner()->GetName(), GetOwner()->IsInWorld() ? GetOwner()->GetMap()->GetId() : uint32(-1),
                    itr->first->GetName(), itr->first->IsInWorld() ? itr->first->GetMap()->GetId() : uint32(-1));
                ABORT();
            }

            if (aurApp)
            {
                aurApp->UpdateApplyEffectMask(itr->second, true); // aura is already applied, this means we need to update effects of current application
                itr = targets.erase(itr);
            }
            else
            {
                itr->first->_CreateAuraApplication(this, itr->second);
                ++itr;
            }
        }
    }

    // remove auras from units no longer needing them
    for (Unit* unit : targetsToRemove)
        if (AuraApplication* aurApp = GetApplicationOfTarget(unit->GetGUID()))
            unit->_UnapplyAura(aurApp, AURA_REMOVE_BY_DEFAULT);

    if (!apply)
        return;

    // apply aura effects for units
    for (auto itr = targets.begin(); itr!= targets.end(); ++itr)
    {
        if (AuraApplication* aurApp = GetApplicationOfTarget(itr->first->GetGUID()))
        {
            // owner has to be in world, or effect has to be applied to self
            ASSERT((!GetOwner()->IsInWorld() && GetOwner() == itr->first) || GetOwner()->IsInMap(itr->first));
            itr->first->_ApplyAura(aurApp, itr->second);
        }
    }
}

// targets have to be registered and not have effect applied yet to use this function
void Aura::_ApplyEffectForTargets(uint8 effIndex)
{
    // prepare list of aura targets
    UnitList targetList;
    for (ApplicationMap::iterator appIter = m_applications.begin(); appIter != m_applications.end(); ++appIter)
    {
        if ((appIter->second->GetEffectsToApply() & (1 << effIndex)) && !appIter->second->HasEffect(effIndex))
            targetList.push_back(appIter->second->GetTarget());
    }

    // apply effect to targets
    for (UnitList::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
    {
        if (GetApplicationOfTarget((*itr)->GetGUID()))
        {
            // owner has to be in world, or effect has to be applied to self
            ASSERT((!GetOwner()->IsInWorld() && GetOwner() == *itr) || GetOwner()->IsInMap(*itr));
            (*itr)->_ApplyAuraEffect(this, effIndex);
        }
    }
}
void Aura::UpdateOwner(uint32 diff, WorldObject* owner)
{
    ASSERT(owner == m_owner);

    Unit* caster = GetCaster();
    // Apply spellmods for channeled auras
    // used for example when triggered spell of spell:10 is modded
    Spell* modSpell = nullptr;
    Player* modOwner = nullptr;
    if (caster)
    {
        modOwner = caster->GetSpellModOwner();
        if (modOwner)
        {
            modSpell = modOwner->FindCurrentSpellBySpellId(GetId());
            if (modSpell)
                modOwner->SetSpellModTakingSpell(modSpell, true);
        }
    }

    Update(diff, caster);

    if (m_updateTargetMapInterval <= int32(diff))
        UpdateTargetMap(caster);
    else
        m_updateTargetMapInterval -= diff;

    // update aura effects
    for (AuraEffect* effect : GetAuraEffects())
        if (effect)
            effect->Update(diff, caster);

    // remove spellmods after effects update
    if (modSpell)
        modOwner->SetSpellModTakingSpell(modSpell, false);

    _DeleteRemovedApplications();
}

void Aura::Update(uint32 diff, Unit* caster)
{
    if (m_duration > 0)
    {
        m_duration -= diff;
        if (m_duration < 0)
            m_duration = 0;

        // handle manaPerSecond/manaPerSecondPerLevel
        if (m_timeCla)
        {
            if (m_timeCla > int32(diff))
                m_timeCla -= diff;
            else if (caster && (caster == GetOwner() || !GetSpellInfo()->HasAttribute(SPELL_ATTR2_NO_TARGET_PER_SECOND_COSTS)))
            {
                if (!m_periodicCosts.empty())
                {
                    m_timeCla += 1000 - diff;

                    for (SpellPowerEntry const* power : m_periodicCosts)
                    {
                        if (power->RequiredAuraSpellID && !caster->HasAura(power->RequiredAuraSpellID))
                            continue;

                        int32 manaPerSecond = power->ManaPerSecond;
                        Powers powertype = Powers(power->PowerType);
                        if (powertype != POWER_HEALTH)
                            manaPerSecond += int32(CalculatePct(caster->GetMaxPower(powertype), power->PowerPctPerSecond));
                        else
                            manaPerSecond += int32(CalculatePct(caster->GetMaxHealth(), power->PowerPctPerSecond));

                        if (manaPerSecond)
                        {
                            if (powertype == POWER_HEALTH)
                            {
                                if (int32(caster->GetHealth()) > manaPerSecond)
                                    caster->ModifyHealth(-manaPerSecond);
                                else
                                    Remove();
                            }
                            else if (int32(caster->GetPower(powertype)) >= manaPerSecond)
                                caster->ModifyPower(powertype, -manaPerSecond);
                            else
                                Remove();
                        }
                    }
                }
            }
        }
    }
}

int32 Aura::CalcMaxDuration(Unit* caster) const
{
    return Aura::CalcMaxDuration(GetSpellInfo(), caster, nullptr);
}

/*static*/ int32 Aura::CalcMaxDuration(SpellInfo const* spellInfo, WorldObject const* caster, std::vector<SpellPowerCost> const* powerCosts)
{
    Player* modOwner = nullptr;
    int32 maxDuration;

    if (caster)
    {
        modOwner = caster->GetSpellModOwner();
        maxDuration = caster->CalcSpellDuration(spellInfo, powerCosts);
    }
    else
        maxDuration = spellInfo->GetDuration();

    if (spellInfo->IsPassive() && !spellInfo->DurationEntry)
        maxDuration = -1;

    // IsPermanent() checks max duration (which we are supposed to calculate here)
    if (maxDuration != -1 && modOwner)
        modOwner->ApplySpellMod(spellInfo, SpellModOp::Duration, maxDuration);

    return maxDuration;
}

void Aura::SetDuration(int32 duration, bool withMods)
{
    if (withMods)
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::Duration, duration);

    m_duration = duration;
    SetNeedClientUpdateForTargets();
}

void Aura::RefreshDuration(bool withMods)
{
    Unit* caster = GetCaster();
    if (withMods && caster)
    {
        int32 duration = m_spellInfo->GetMaxDuration();
        // Calculate duration of periodics affected by haste.
        if (m_spellInfo->HasAttribute(SPELL_ATTR8_HASTE_AFFECTS_DURATION))
            duration = int32(duration * caster->m_unitData->ModCastingSpeed);

        SetMaxDuration(duration);
        SetDuration(duration);
    }
    else
        SetDuration(GetMaxDuration());

    if (!m_periodicCosts.empty())
        m_timeCla = 1 * IN_MILLISECONDS;

    // also reset periodic counters
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (AuraEffect* aurEff = GetEffect(i))
            aurEff->ResetTicks();
}

void Aura::RefreshTimers(bool resetPeriodicTimer)
{
    m_maxDuration = CalcMaxDuration();

    // Pandemic Mechanic
    if (m_spellInfo->HasAttribute(SPELL_ATTR13_PERIODIC_REFRESH_EXTENDS_DURATION))
    {
        // Pandemic doesn't reset periodic timer
        resetPeriodicTimer = false;

        int32 pandemicDuration = CalculatePct(m_maxDuration, 30.f);
        m_maxDuration = std::max(GetDuration(), std::min(pandemicDuration, GetDuration()) + m_maxDuration);
    }

    RefreshDuration();

    Unit* caster = GetCaster();
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (AuraEffect* aurEff = GetEffect(i))
            aurEff->CalculatePeriodic(caster, resetPeriodicTimer, false);
}

void Aura::SetCharges(uint8 charges)
{
    if (m_procCharges == charges)
        return;

    m_procCharges = charges;
    m_isUsingCharges = m_procCharges != 0;
    SetNeedClientUpdateForTargets();
}

uint8 Aura::CalcMaxCharges(Unit* caster) const
{
    uint32 maxProcCharges = m_spellInfo->ProcCharges;
    if (SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetSpellInfo()))
        maxProcCharges = procEntry->Charges;

    if (caster)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::ProcCharges, maxProcCharges);

    return uint8(maxProcCharges);
}

bool Aura::ModCharges(int32 num, AuraRemoveMode removeMode)
{
    if (IsUsingCharges())
    {
        int32 charges = m_procCharges + num;
        int32 maxCharges = CalcMaxCharges();

        // limit charges (only on charges increase, charges may be changed manually)
        if ((num > 0) && (charges > int32(maxCharges)))
            charges = maxCharges;
        // we're out of charges, remove
        else if (charges <= 0)
        {
            Remove(removeMode);
            return true;
        }

        SetCharges(charges);
    }

    return false;
}

void Aura::ModChargesDelayed(int32 num, AuraRemoveMode removeMode)
{
    m_dropEvent = nullptr;
    ModCharges(num, removeMode);
}

void Aura::DropChargeDelayed(uint32 delay, AuraRemoveMode removeMode)
{
    // aura is already during delayed charge drop
    if (m_dropEvent)
        return;
    // only units have events
    Unit* owner = m_owner->ToUnit();
    if (!owner)
        return;

    m_dropEvent = new ChargeDropEvent(this, removeMode);
    owner->m_Events.AddEvent(m_dropEvent, owner->m_Events.CalculateTime(Milliseconds(delay)));
}

void Aura::SetStackAmount(uint8 stackAmount)
{
    m_stackAmount = stackAmount;
    Unit* caster = GetCaster();

    std::vector<AuraApplication*> applications;
    GetApplicationVector(applications);

    for (AuraApplication* aurApp : applications)
        if (!aurApp->GetRemoveMode())
            HandleAuraSpecificMods(aurApp, caster, false, true);

    for (AuraEffect* aurEff : GetAuraEffects())
        if (aurEff)
            aurEff->ChangeAmount(aurEff->CalculateAmount(caster), false, true);

    for (AuraApplication* aurApp : applications)
        if (!aurApp->GetRemoveMode())
            HandleAuraSpecificMods(aurApp, caster, true, true);

    SetNeedClientUpdateForTargets();
}

bool Aura::IsUsingStacks() const
{
    return m_spellInfo->StackAmount > 0 || m_stackAmount > 1;
}

uint32 Aura::CalcMaxStackAmount() const
{
    int32 maxStackAmount = m_spellInfo->StackAmount;
    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo, SpellModOp::MaxAuraStacks, maxStackAmount);

    return maxStackAmount;
}

bool Aura::ModStackAmount(int32 num, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/, bool resetPeriodicTimer /*= true*/)
{
    int32 stackAmount = m_stackAmount + num;
    int32 maxStackAmount = int32(CalcMaxStackAmount());

    // limit the stack amount (only on stack increase, stack amount may be changed manually)
    if ((num > 0) && (stackAmount > maxStackAmount))
    {
        // not stackable aura - set stack amount to 1
        if (!m_spellInfo->StackAmount)
            stackAmount = 1;
        else
            stackAmount = m_spellInfo->StackAmount;
    }
    // we're out of stacks, remove
    else if (stackAmount <= 0)
    {
        Remove(removeMode);
        return true;
    }

    bool refresh = stackAmount >= GetStackAmount() && (m_spellInfo->StackAmount || (!m_spellInfo->HasAttribute(SPELL_ATTR1_AURA_UNIQUE) && !m_spellInfo->HasAttribute(SPELL_ATTR5_AURA_UNIQUE_PER_CASTER)));

    // Update stack amount
    SetStackAmount(stackAmount);

    if (refresh)
    {
        RefreshTimers(resetPeriodicTimer);

        // reset charges
        SetCharges(CalcMaxCharges());
    }

    SetNeedClientUpdateForTargets();
    return false;
}

bool Aura::HasMoreThanOneEffectForType(AuraType auraType) const
{
    uint32 count = 0;
    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        if (HasEffect(spellEffectInfo.EffectIndex) && spellEffectInfo.ApplyAuraName == auraType)
            ++count;

    return count > 1;
}

bool Aura::IsArea() const
{
    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        if (HasEffect(spellEffectInfo.EffectIndex) && spellEffectInfo.IsAreaAuraEffect())
            return true;

    return false;
}

bool Aura::IsPassive() const
{
    return GetSpellInfo()->IsPassive();
}

bool Aura::IsDeathPersistent() const
{
    return GetSpellInfo()->IsDeathPersistent();
}

bool Aura::IsRemovedOnShapeLost(Unit* target) const
{
    return GetCasterGUID() == target->GetGUID()
        && m_spellInfo->Stances
        && !m_spellInfo->HasAttribute(SPELL_ATTR2_ALLOW_WHILE_NOT_SHAPESHIFTED_CASTER_FORM)
        && !m_spellInfo->HasAttribute(SPELL_ATTR0_NOT_SHAPESHIFTED);
}

bool Aura::CanBeSaved() const
{
    if (IsPassive())
        return false;

    if (GetSpellInfo()->IsChanneled())
        return false;

    // Check if aura is single target, not only spell info
    if (GetCasterGUID() != GetOwner()->GetGUID())
    {
        // owner == caster for area auras, check for possible bad data in DB
        for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        {
            if (!spellEffectInfo.IsEffect())
                continue;

            if (spellEffectInfo.IsTargetingArea() || spellEffectInfo.IsAreaAuraEffect())
                return false;
        }

        if (IsSingleTarget() || GetSpellInfo()->IsSingleTarget())
            return false;
    }

    if (GetSpellInfo()->HasAttribute(SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED))
        return false;

    // don't save auras removed by proc system
    if (IsUsingCharges() && !GetCharges())
        return false;

    // don't save permanent auras triggered by items, they'll be recasted on login if necessary
    if (!GetCastItemGUID().IsEmpty() && IsPermanent())
        return false;

    return true;
}

bool Aura::IsSingleTargetWith(Aura const* aura) const
{
    // Same spell?
    if (GetSpellInfo()->IsRankOf(aura->GetSpellInfo()))
        return true;

    SpellSpecificType spec = GetSpellInfo()->GetSpellSpecific();
    // spell with single target specific types
    switch (spec)
    {
        case SPELL_SPECIFIC_MAGE_POLYMORPH:
            if (aura->GetSpellInfo()->GetSpellSpecific() == spec)
                return true;
            break;
        default:
            break;
    }

    return false;
}

void Aura::UnregisterSingleTarget()
{
    ASSERT(m_isSingleTarget);
    Unit* caster = GetCaster();
    ASSERT(caster);
    Trinity::Containers::Lists::RemoveUnique(caster->GetSingleCastAuras(), this);
    SetIsSingleTarget(false);
}

int32 Aura::CalcDispelChance(Unit const* /*auraTarget*/, bool /*offensive*/) const
{
    // we assume that aura dispel chance is 100% on start
    // need formula for level difference based chance
    int32 resistChance = 0;

    // Apply dispel mod from aura caster
    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::DispelResistance, resistChance);

    RoundToInterval(resistChance, 0, 100);
    return 100 - resistChance;
}

AuraKey Aura::GenerateKey(uint32& recalculateMask) const
{
    AuraKey key;
    key.Caster = GetCasterGUID();
    key.Item = GetCastItemGUID();
    key.SpellId = GetId();
    key.EffectMask = 0;
    recalculateMask = 0;
    for (uint32 i = 0; i < _effects.size(); ++i)
    {
        if (AuraEffect const* effect = _effects[i])
        {
            key.EffectMask |= 1 << i;
            if (effect->CanBeRecalculated())
                recalculateMask |= 1 << i;
        }
    }

    return key;
}

void Aura::SetLoadedState(int32 maxDuration, int32 duration, int32 charges, uint8 stackAmount, uint32 recalculateMask, int32* amount)
{
    m_maxDuration = maxDuration;
    m_duration = duration;
    m_procCharges = charges;
    m_isUsingCharges = m_procCharges != 0;
    m_stackAmount = stackAmount;
    Unit* caster = GetCaster();
    for (AuraEffect* effect : GetAuraEffects())
    {
        if (!effect)
            continue;

        effect->SetAmount(amount[effect->GetEffIndex()]);
        effect->SetCanBeRecalculated((recalculateMask & (1 << effect->GetEffIndex())) != 0);
        effect->CalculatePeriodic(caster, false, true);
        effect->CalculateSpellMod();
        effect->RecalculateAmount(caster);
    }
}

bool Aura::HasEffectType(AuraType type) const
{
    for (AuraEffect* effect : GetAuraEffects())
    {
        if (effect && effect->GetAuraType() == type)
            return true;
    }
    return false;
}

bool Aura::EffectTypeNeedsSendingAmount(AuraType type)
{
    switch (type)
    {
        case SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS:
        case SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS_TRIGGERED:
        case SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN:
        case SPELL_AURA_MOD_MAX_CHARGES:
        case SPELL_AURA_CHARGE_RECOVERY_MOD:
        case SPELL_AURA_CHARGE_RECOVERY_MULTIPLIER:
            return true;
        default:
            break;
    }

    return false;
}

void Aura::RecalculateAmountOfEffects()
{
    ASSERT (!IsRemoved());
    Unit* caster = GetCaster();
    for (AuraEffect* effect : GetAuraEffects())
        if (effect && !IsRemoved())
            effect->RecalculateAmount(caster);
}

void Aura::HandleAllEffects(AuraApplication * aurApp, uint8 mode, bool apply)
{
    ASSERT (!IsRemoved());
    for (AuraEffect* effect : GetAuraEffects())
        if (effect && !IsRemoved())
            effect->HandleEffect(aurApp, mode, apply);
}

uint32 Aura::GetEffectMask() const
{
    uint32 effMask = 0;
    for (AuraEffect* aurEff : GetAuraEffects())
        if (aurEff)
            effMask |= 1 << aurEff->GetEffIndex();
    return effMask;
}

void Aura::GetApplicationVector(std::vector<AuraApplication*>& applications) const
{
    for (auto const& applicationPair : m_applications)
    {
        if (!applicationPair.second->GetEffectMask())
            continue;

        applications.push_back(applicationPair.second);
    }
}

AuraApplication const* Aura::GetApplicationOfTarget(ObjectGuid guid) const
{
    return Trinity::Containers::MapGetValuePtr(m_applications, guid);
}

AuraApplication* Aura::GetApplicationOfTarget(ObjectGuid guid)
{
    return Trinity::Containers::MapGetValuePtr(m_applications, guid);
}

bool Aura::IsAppliedOnTarget(ObjectGuid guid) const
{
    return m_applications.contains(guid);
}

void Aura::SetNeedClientUpdateForTargets() const
{
    for (ApplicationMap::const_iterator appIter = m_applications.begin(); appIter != m_applications.end(); ++appIter)
        appIter->second->SetNeedClientUpdate();
}

// trigger effects on real aura apply/remove
void Aura::HandleAuraSpecificMods(AuraApplication const* aurApp, Unit* caster, bool apply, bool onReapply)
{
    Unit* target = aurApp->GetTarget();
    AuraRemoveMode removeMode = aurApp->GetRemoveMode();
    // handle spell_area table
    SpellAreaForAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForAuraMapBounds(GetId());
    if (saBounds.first != saBounds.second)
    {
        uint32 zone, area;
        target->GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            // some auras remove at aura remove
            if (itr->second->flags & SPELL_AREA_FLAG_AUTOREMOVE && !itr->second->IsFitToRequirements(target->ToPlayer(), zone, area))
                target->RemoveAurasDueToSpell(itr->second->spellId);
            // some auras applied at aura apply
            else if (itr->second->flags & SPELL_AREA_FLAG_AUTOCAST)
            {
                if (!target->HasAura(itr->second->spellId))
                    target->CastSpell(target, itr->second->spellId, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                        .SetOriginalCastId(GetCastId()));
            }
        }
    }

    // handle spell_linked_spell table
    if (!onReapply)
    {
        // apply linked auras
        if (apply)
        {
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_AURA, GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->ApplySpellImmune(GetId(), IMMUNITY_ID, -(*itr), true);
                    else if (caster)
                        caster->AddAura(*itr, target);
                }
            }
        }
        else
        {
            // remove linked auras
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_REMOVE, GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->RemoveAurasDueToSpell(-(*itr));
                    else if (removeMode != AURA_REMOVE_BY_DEATH)
                        target->CastSpell(target, *itr, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                            .SetOriginalCaster(GetCasterGUID())
                            .SetOriginalCastId(GetCastId()));
                }
            }
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_AURA, GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->ApplySpellImmune(GetId(), IMMUNITY_ID, -(*itr), false);
                    else
                        target->RemoveAura(*itr, GetCasterGUID(), 0, removeMode);
                }
            }
        }
    }
    else if (apply)
    {
        // modify stack amount of linked auras
        if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_AURA, GetId()))
        {
            for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                if (*itr > 0)
                    if (Aura* triggeredAura = target->GetAura(*itr, GetCasterGUID()))
                        triggeredAura->ModStackAmount(GetStackAmount() - triggeredAura->GetStackAmount());
        }
    }

    // mods at aura apply
    if (apply)
    {
        switch (GetSpellInfo()->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
                switch (GetId())
                {
                    case 33572: // Gronn Lord's Grasp, becomes stoned
                        if (GetStackAmount() >= 5 && !target->HasAura(33652))
                            target->CastSpell(target, 33652, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCastId(GetCastId()));
                        break;
                    case 50836: //Petrifying Grip, becomes stoned
                        if (GetStackAmount() >= 5 && !target->HasAura(50812))
                            target->CastSpell(target, 50812, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCastId(GetCastId()));
                        break;
                    case 60970: // Heroic Fury (remove Intercept cooldown)
                        if (target->GetTypeId() == TYPEID_PLAYER)
                            target->GetSpellHistory()->ResetCooldown(20252, true);
                        break;
                }
                break;
            case SPELLFAMILY_DRUID:
                if (!caster)
                    break;
                // Rejuvenation
                if (GetSpellInfo()->SpellFamilyFlags[0] & 0x10 && GetEffect(EFFECT_0))
                {
                    // Druid T8 Restoration 4P Bonus
                    if (caster->HasAura(64760))
                    {
                        CastSpellExtraArgs args(GetEffect(EFFECT_0));
                        args.AddSpellMod(SPELLVALUE_BASE_POINT0, GetEffect(EFFECT_0)->GetAmount());
                        caster->CastSpell(target, 64801, args);
                    }
                }
                break;
        }
    }
    // mods at aura remove
    else
    {
        switch (GetSpellInfo()->SpellFamilyName)
        {
            case SPELLFAMILY_MAGE:
                switch (GetId())
                {
                    case 66: // Invisibility
                        if (removeMode != AURA_REMOVE_BY_EXPIRE)
                            break;
                        target->CastSpell(target, 32612, GetEffect(1));
                        break;
                    default:
                        break;
                }
                break;
            case SPELLFAMILY_PRIEST:
                if (!caster)
                    break;
                // Power word: shield
                if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL && GetSpellInfo()->SpellFamilyFlags[0] & 0x00000001)
                {
                    // Rapture
                    if (Aura const* aura = caster->GetAuraOfRankedSpell(47535))
                    {
                        // check cooldown
                        if (caster->GetTypeId() == TYPEID_PLAYER)
                        {
                            if (caster->GetSpellHistory()->HasCooldown(aura->GetSpellInfo()))
                            {
                                // This additional check is needed to add a minimal delay before cooldown in in effect
                                // to allow all bubbles broken by a single damage source proc mana return
                                if (caster->GetSpellHistory()->GetRemainingCooldown(aura->GetSpellInfo()) <= 11s)
                                    break;
                            }
                            else    // and add if needed
                                caster->GetSpellHistory()->AddCooldown(aura->GetId(), 0, 12s);
                        }

                        // effect on caster
                        if (AuraEffect const* aurEff = aura->GetEffect(0))
                        {
                            float multiplier = float(aurEff->GetAmount());
                            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                            args.SetOriginalCastId(GetCastId());
                            args.AddSpellMod(SPELLVALUE_BASE_POINT0, CalculatePct(caster->GetMaxPower(POWER_MANA), multiplier));
                            caster->CastSpell(caster, 47755, args);
                        }
                    }
                }
                break;
            case SPELLFAMILY_ROGUE:
                // Remove Vanish on stealth remove
                if (GetId() == 1784)
                    target->RemoveAurasWithFamily(SPELLFAMILY_ROGUE, flag128(0x0000800, 0, 0, 0), target->GetGUID());
                break;
        }
    }

    // mods at aura apply or remove
    switch (GetSpellInfo()->SpellFamilyName)
    {
        case SPELLFAMILY_HUNTER:
            switch (GetId())
            {
                case 19574: // Bestial Wrath
                    // The Beast Within cast on owner if talent present
                    if (Unit* owner = target->GetOwner())
                    {
                        // Search talent
                        if (owner->HasAura(34692))
                        {
                            if (apply)
                                owner->CastSpell(owner, 34471, GetEffect(0));
                            else
                                owner->RemoveAurasDueToSpell(34471);
                        }
                    }
                    break;
            }
            break;
        case SPELLFAMILY_PALADIN:
            switch (GetId())
            {
                case 31842: // Divine Favor
                    // Item - Paladin T10 Holy 2P Bonus
                    if (target->HasAura(70755))
                    {
                        if (apply)
                            target->CastSpell(target, 71166, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCastId(GetCastId()));
                        else
                            target->RemoveAurasDueToSpell(71166);
                    }
                    break;
            }
            break;
    }
}

bool Aura::CanBeAppliedOn(Unit* target)
{
    // unit not in world or during remove from world
    if (!target->IsInWorld() || target->IsDuringRemoveFromWorld())
    {
        // area auras mustn't be applied
        if (GetOwner() != target)
            return false;
        // do not apply non-selfcast single target auras
        if (GetCasterGUID() != GetOwner()->GetGUID() && GetSpellInfo()->IsSingleTarget())
            return false;
        return true;
    }
    else
        return CheckAreaTarget(target);
}

bool Aura::CheckAreaTarget(Unit* target)
{
    return CallScriptCheckAreaTargetHandlers(target);
}

bool Aura::CanStackWith(Aura const* existingAura) const
{
    // Can stack with self
    if (this == existingAura)
        return true;

    bool sameCaster = GetCasterGUID() == existingAura->GetCasterGUID();
    SpellInfo const* existingSpellInfo = existingAura->GetSpellInfo();

    // Dynobj auras do not stack when they come from the same spell cast by the same caster
    if (GetType() == DYNOBJ_AURA_TYPE || existingAura->GetType() == DYNOBJ_AURA_TYPE)
    {
        if (sameCaster && m_spellInfo->Id == existingSpellInfo->Id)
            return false;
        return true;
    }

    // passive auras don't stack with another rank of the spell cast by same caster
    if (IsPassive() && sameCaster && (m_spellInfo->IsDifferentRankOf(existingSpellInfo) || (m_spellInfo->Id == existingSpellInfo->Id && m_castItemGuid.IsEmpty())))
        return false;

    for (SpellEffectInfo const& spellEffectInfo : existingSpellInfo->GetEffects())
    {
        // prevent remove triggering aura by triggered aura
        if (spellEffectInfo.TriggerSpell == GetId())
            return true;
    }

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        // prevent remove triggered aura by triggering aura refresh
        if (spellEffectInfo.TriggerSpell == existingAura->GetId())
            return true;
    }

    // check spell specific stack rules
    if (m_spellInfo->IsAuraExclusiveBySpecificWith(existingSpellInfo)
        || (sameCaster && m_spellInfo->IsAuraExclusiveBySpecificPerCasterWith(existingSpellInfo)))
        return false;

    // check spell group stack rules
    switch (sSpellMgr->CheckSpellGroupStackRules(m_spellInfo, existingSpellInfo))
    {
        case SPELL_GROUP_STACK_RULE_EXCLUSIVE:
        case SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST: // if it reaches this point, existing aura is lower/equal
            return false;
        case SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER:
            if (sameCaster)
                return false;
            break;
        case SPELL_GROUP_STACK_RULE_DEFAULT:
        case SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT:
        default:
            break;
    }

    if (m_spellInfo->SpellFamilyName != existingSpellInfo->SpellFamilyName)
        return true;

    if (!sameCaster)
    {
        // Channeled auras can stack if not forbidden by db or aura type
        if (existingAura->GetSpellInfo()->IsChanneled())
            return true;

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_DOT_STACKING_RULE))
            return true;

        // check same periodic auras
        auto hasPeriodicNonAreaEffect = [](SpellInfo const* spellInfo)
        {
            for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            {
                switch (spellEffectInfo.ApplyAuraName)
                {
                    // DOT or HOT from different casters will stack
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_WEAPON_PERCENT_DAMAGE:
                    case SPELL_AURA_PERIODIC_DUMMY:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    case SPELL_AURA_PERIODIC_ENERGIZE:
                    case SPELL_AURA_PERIODIC_MANA_LEECH:
                    case SPELL_AURA_PERIODIC_LEECH:
                    case SPELL_AURA_POWER_BURN:
                    case SPELL_AURA_OBS_MOD_POWER:
                    case SPELL_AURA_OBS_MOD_HEALTH:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                    case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                        // periodic auras which target areas are not allowed to stack this way (replenishment for example)
                        if (spellEffectInfo.IsTargetingArea())
                            return false;
                        return true;
                    default:
                        break;
                }
            }
            return false;
        };

        if (hasPeriodicNonAreaEffect(m_spellInfo) && hasPeriodicNonAreaEffect(existingSpellInfo))
            return true;
    }

    if (HasEffectType(SPELL_AURA_CONTROL_VEHICLE) && existingAura->HasEffectType(SPELL_AURA_CONTROL_VEHICLE))
    {
        Vehicle* veh = nullptr;
        if (GetOwner()->ToUnit())
            veh = GetOwner()->ToUnit()->GetVehicleKit();

        if (!veh)           // We should probably just let it stack. Vehicle system will prevent undefined behaviour later
            return true;

        if (!veh->GetAvailableSeatCount())
            return false;   // No empty seat available

        return true; // Empty seat available (skip rest)
    }

    if (HasEffectType(SPELL_AURA_SHOW_CONFIRMATION_PROMPT) || HasEffectType(SPELL_AURA_SHOW_CONFIRMATION_PROMPT_WITH_DIFFICULTY))
        if (existingAura->HasEffectType(SPELL_AURA_SHOW_CONFIRMATION_PROMPT) || existingAura->HasEffectType(SPELL_AURA_SHOW_CONFIRMATION_PROMPT_WITH_DIFFICULTY))
            return false;

    // spell of same spell rank chain
    if (m_spellInfo->IsRankOf(existingSpellInfo))
    {
        // don't allow passive area auras to stack
        if (m_spellInfo->IsMultiSlotAura() && !IsArea())
            return true;
        if (!GetCastItemGUID().IsEmpty() && !existingAura->GetCastItemGUID().IsEmpty())
            if (GetCastItemGUID() != existingAura->GetCastItemGUID() && (m_spellInfo->HasAttribute(SPELL_ATTR0_CU_ENCHANT_PROC)))
                return true;
        // same spell with same caster should not stack
        return false;
    }

    return true;
}

bool Aura::IsProcOnCooldown(TimePoint now) const
{
    return m_procCooldown > now;
}

void Aura::AddProcCooldown(SpellProcEntry const* procEntry, TimePoint now)
{
    // cooldowns should be added to the whole aura (see 51698 area aura)
    int32 procCooldown = procEntry->Cooldown.count();
    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::ProcCooldown, procCooldown);

    m_procCooldown = now + Milliseconds(procCooldown);
}

void Aura::ResetProcCooldown()
{
    m_procCooldown = GameTime::Now();
}

void Aura::PrepareProcToTrigger(AuraApplication* aurApp, ProcEventInfo& eventInfo, TimePoint now)
{
    bool prepare = CallScriptPrepareProcHandlers(aurApp, eventInfo);
    if (!prepare)
        return;

    SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetSpellInfo());
    ASSERT(procEntry);

    PrepareProcChargeDrop(procEntry, eventInfo);

    // cooldowns should be added to the whole aura (see 51698 area aura)
    AddProcCooldown(procEntry, now);

    SetLastProcSuccessTime(now);
}

void Aura::PrepareProcChargeDrop(SpellProcEntry const* procEntry, ProcEventInfo const& eventInfo)
{
    // take one charge, aura expiration will be handled in Aura::TriggerProcOnEvent (if needed)
    if (!(procEntry->AttributesMask & PROC_ATTR_USE_STACKS_FOR_CHARGES) && IsUsingCharges() && (!eventInfo.GetSpellInfo() || !eventInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES)))
    {
        --m_procCharges;
        SetNeedClientUpdateForTargets();
    }
}

void Aura::ConsumeProcCharges(SpellProcEntry const* procEntry)
{
    // Remove aura if we've used last charge to proc
    if (procEntry->AttributesMask & PROC_ATTR_USE_STACKS_FOR_CHARGES)
    {
        ModStackAmount(-1);
    }
    else if (IsUsingCharges())
    {
        if (!GetCharges())
            Remove();
    }
}

uint32 Aura::GetProcEffectMask(AuraApplication* aurApp, ProcEventInfo& eventInfo, TimePoint now) const
{
    SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetSpellInfo());
    // only auras with spell proc entry can trigger proc
    if (!procEntry)
        return 0;

    // check spell triggering us
    if (Spell const* spell = eventInfo.GetProcSpell())
    {
        // Do not allow auras to proc from effect triggered from itself
        if (spell->IsTriggeredByAura(m_spellInfo))
            return 0;

        // check if aura can proc when spell is triggered (exception for hunter auto shot & wands)
        if (!GetSpellInfo()->HasAttribute(SPELL_ATTR3_CAN_PROC_FROM_PROCS) && !(procEntry->AttributesMask & PROC_ATTR_TRIGGERED_CAN_PROC) && !(eventInfo.GetTypeMask() & AUTO_ATTACK_PROC_FLAG_MASK))
            if (spell->IsTriggered() && !spell->GetSpellInfo()->HasAttribute(SPELL_ATTR3_NOT_A_PROC))
                return 0;

        if (spell->m_CastItem && (procEntry->AttributesMask & PROC_ATTR_CANT_PROC_FROM_ITEM_CAST))
            return 0;

        if (spell->GetSpellInfo()->HasAttribute(SPELL_ATTR4_SUPPRESS_WEAPON_PROCS) && GetSpellInfo()->HasAttribute(SPELL_ATTR6_AURA_IS_WEAPON_PROC))
            return 0;

        if (GetSpellInfo()->HasAttribute(SPELL_ATTR12_ONLY_PROC_FROM_CLASS_ABILITIES) && !spell->GetSpellInfo()->HasAttribute(SPELL_ATTR13_ALLOW_CLASS_ABILITY_PROCS))
            return 0;

        if (eventInfo.GetTypeMask() & TAKEN_HIT_PROC_FLAG_MASK)
        {
            if (spell->GetSpellInfo()->HasAttribute(SPELL_ATTR3_SUPPRESS_TARGET_PROCS)
                && !GetSpellInfo()->HasAttribute(SPELL_ATTR7_CAN_PROC_FROM_SUPPRESSED_TARGET_PROCS))
                return 0;
        }
        else
        {
            if (spell->GetSpellInfo()->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS)
                && !spell->GetSpellInfo()->HasAttribute(SPELL_ATTR12_ENABLE_PROCS_FROM_SUPPRESSED_CASTER_PROCS)
                && !GetSpellInfo()->HasAttribute(SPELL_ATTR12_CAN_PROC_FROM_SUPPRESSED_CASTER_PROCS))
                return 0;
        }
    }

    // check don't break stealth attr present
    if (m_spellInfo->HasAura(SPELL_AURA_MOD_STEALTH))
    {
        if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
            if (spellInfo->HasAttribute(SPELL_ATTR0_CU_DONT_BREAK_STEALTH))
                return 0;
    }

    // check if we have charges to proc with
    if (IsUsingCharges())
    {
        if (!GetCharges())
            return 0;

        if (procEntry->AttributesMask & PROC_ATTR_REQ_SPELLMOD)
            if (Spell const* spell = eventInfo.GetProcSpell())
                if (!spell->m_appliedMods.count(const_cast<Aura*>(this)))
                    return 0;
    }

    // check proc cooldown
    if (IsProcOnCooldown(now))
        return 0;

    // do checks against db data
    if (!SpellMgr::CanSpellTriggerProcOnEvent(*procEntry, eventInfo))
        return 0;

    // do checks using conditions table
    if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_SPELL_PROC, GetId(), eventInfo.GetActor(), eventInfo.GetActionTarget()))
        return 0;

    // AuraScript Hook
    bool check = const_cast<Aura*>(this)->CallScriptCheckProcHandlers(aurApp, eventInfo);
    if (!check)
        return 0;

    // At least one effect has to pass checks to proc aura
    uint32 procEffectMask = aurApp->GetEffectMask();
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (procEffectMask & (1u << i))
            if ((procEntry->DisableEffectsMask & (1u << i)) || !GetEffect(i)->CheckEffectProc(aurApp, eventInfo))
                procEffectMask &= ~(1u << i);

    if (!procEffectMask)
        return 0;

    /// @todo
    // do allow additional requirements for procs
    // this is needed because this is the last moment in which you can prevent aura charge drop on proc
    // and possibly a way to prevent default checks (if there're going to be any)

    // Check if current equipment meets aura requirements
    // do that only for passive spells
    /// @todo this needs to be unified for all kinds of auras
    Unit* target = aurApp->GetTarget();
    if (IsPassive() && target->GetTypeId() == TYPEID_PLAYER && GetSpellInfo()->EquippedItemClass != -1)
    {
        if (!GetSpellInfo()->HasAttribute(SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT))
        {
            Item* item = nullptr;
            if (GetSpellInfo()->EquippedItemClass == ITEM_CLASS_WEAPON)
            {
                if (target->ToPlayer()->IsInFeralForm())
                    return 0;

                if (DamageInfo const* damageInfo = eventInfo.GetDamageInfo())
                {
                    if (damageInfo->GetAttackType() != OFF_ATTACK)
                        item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                    else
                        item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                }
            }
            else if (GetSpellInfo()->EquippedItemClass == ITEM_CLASS_ARMOR)
            {
                // Check if player is wearing shield
                item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            }

            if (!item || item->IsBroken() || !item->IsFitToSpellRequirements(GetSpellInfo()))
                return 0;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_PROC_OUTDOORS))
        if (!target->IsOutdoors())
            return 0;

    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_PROC_ON_CASTER))
        if (target->GetGUID() != GetCasterGUID())
            return 0;

    if (!m_spellInfo->HasAttribute(SPELL_ATTR4_ALLOW_PROC_WHILE_SITTING))
        if (!target->IsStandState())
            return 0;

    bool success = roll_chance_f(CalcProcChance(*procEntry, eventInfo));

    const_cast<Aura*>(this)->SetLastProcAttemptTime(now);

    if (success)
        return procEffectMask;

    return 0;
}

float Aura::CalcProcChance(SpellProcEntry const& procEntry, ProcEventInfo& eventInfo) const
{
    float chance = procEntry.Chance;
    // calculate chances depending on unit with caster's data
    // so talents modifying chances and judgements will have properly calculated proc chance
    if (Unit* caster = GetCaster())
    {
        // calculate ppm chance if present and we're using weapon
        if (eventInfo.GetDamageInfo() && procEntry.ProcsPerMinute != 0)
        {
            uint32 WeaponSpeed = caster->GetBaseAttackTime(eventInfo.GetDamageInfo()->GetAttackType());
            chance = caster->GetPPMProcChance(WeaponSpeed, procEntry.ProcsPerMinute, GetSpellInfo());
        }

        if (GetSpellInfo()->ProcBasePPM > 0.0f)
            chance = CalcPPMProcChance(caster);

        // apply chance modifer aura, applies also to ppm chance (see improved judgement of light spell)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::ProcChance, chance);
    }

    // proc chance is reduced by an additional 3.333% per level past 60
    if ((procEntry.AttributesMask & PROC_ATTR_REDUCE_PROC_60) && eventInfo.GetActor()->GetLevel() > 60)
        chance = std::max(0.f, (1.f - ((eventInfo.GetActor()->GetLevel() - 60) * 1.f / 30.f)) * chance);

    return chance;
}

void Aura::TriggerProcOnEvent(uint32 procEffectMask, AuraApplication* aurApp, ProcEventInfo& eventInfo)
{
    if (procEffectMask)
    {
        bool prevented = CallScriptProcHandlers(aurApp, eventInfo);
        if (!prevented)
        {
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (!(procEffectMask & (1 << i)))
                    continue;

                // OnEffectProc / AfterEffectProc hooks handled in AuraEffect::HandleProc()
                if (aurApp->HasEffect(i))
                    GetEffect(i)->HandleProc(aurApp, eventInfo);
            }

            CallScriptAfterProcHandlers(aurApp, eventInfo);
        }
    }

    ConsumeProcCharges(ASSERT_NOTNULL(sSpellMgr->GetSpellProcEntry(GetSpellInfo())));
}

float Aura::CalcPPMProcChance(Unit* actor) const
{
    using FSeconds = std::chrono::duration<float, Seconds::period>;

    // Formula see http://us.battle.net/wow/en/forum/topic/8197741003#1
    float ppm = m_spellInfo->CalcProcPPM(actor, GetCastItemLevel());
    float averageProcInterval = 60.0f / ppm;

    TimePoint currentTime = GameTime::Now();
    float secondsSinceLastAttempt = std::min(std::chrono::duration_cast<FSeconds>(currentTime - m_lastProcAttemptTime).count(), 10.0f);
    float secondsSinceLastProc = std::min(std::chrono::duration_cast<FSeconds>(currentTime - m_lastProcSuccessTime).count(), 1000.0f);

    float chance = std::max(1.0f, 1.0f + ((secondsSinceLastProc / averageProcInterval - 1.5f) * 3.0f)) * ppm * secondsSinceLastAttempt / 60.0f;
    RoundToInterval(chance, 0.0f, 1.0f);
    return chance * 100.0f;
}

void Aura::_DeleteRemovedApplications()
{
    for (AuraApplication* aurApp : _removedApplications)
        delete aurApp;

    _removedApplications.clear();
}

void Aura::LoadScripts()
{
    sScriptMgr->CreateAuraScripts(m_spellInfo->Id, m_loadedScripts, this);
    for (AuraScript* script : m_loadedScripts)
    {
        TC_LOG_DEBUG("spells", "Aura::LoadScripts: Script `{}` for aura `{}` is loaded now", script->GetScriptName(), m_spellInfo->Id);
        script->Register();
    }
}

bool Aura::CallScriptCheckAreaTargetHandlers(Unit* target)
{
    bool result = true;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_AREA_TARGET);
        for (AuraScript::CheckAreaTargetHandler const& checkAreaTarget : script->DoCheckAreaTarget)
            result &= checkAreaTarget.Call(script, target);

        script->_FinishScriptCall();
    }
    return result;
}

void Aura::CallScriptDispel(DispelInfo* dispelInfo)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_DISPEL);
        for (AuraScript::AuraDispelHandler const& onDispel : script->OnDispel)
            onDispel.Call(script, dispelInfo);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptAfterDispel(DispelInfo* dispelInfo)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_AFTER_DISPEL);
        for (AuraScript::AuraDispelHandler const& afterDispel : script->AfterDispel)
            afterDispel.Call(script, dispelInfo);

        script->_FinishScriptCall();
    }
}

bool Aura::CallScriptEffectApplyHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    bool preventDefault = false;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_APPLY, aurApp);
        for (AuraScript::EffectApplyHandler const& onEffectApply : script->OnEffectApply)
            if (onEffectApply.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectApply.Call(script, aurEff, mode);

        if (!preventDefault)
            preventDefault = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }

    return preventDefault;
}

bool Aura::CallScriptEffectRemoveHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    bool preventDefault = false;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_REMOVE, aurApp);
        for (AuraScript::EffectApplyHandler const& onEffectRemove : script->OnEffectRemove)
            if (onEffectRemove.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectRemove.Call(script, aurEff, mode);

        if (!preventDefault)
            preventDefault = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }
    return preventDefault;
}

void Aura::CallScriptAfterEffectApplyHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_APPLY, aurApp);
        for (AuraScript::EffectApplyHandler const& afterEffectApply : script->AfterEffectApply)
            if (afterEffectApply.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                afterEffectApply.Call(script, aurEff, mode);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptAfterEffectRemoveHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_REMOVE, aurApp);
        for (AuraScript::EffectApplyHandler const& afterEffectRemove : script->AfterEffectRemove)
            if (afterEffectRemove.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                afterEffectRemove.Call(script, aurEff, mode);

        script->_FinishScriptCall();
    }
}

bool Aura::CallScriptEffectPeriodicHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp)
{
    bool preventDefault = false;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_PERIODIC, aurApp);
        for (AuraScript::EffectPeriodicHandler const& onEffectPeriodic : script->OnEffectPeriodic)
            if (onEffectPeriodic.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectPeriodic.Call(script, aurEff);

        if (!preventDefault)
            preventDefault = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }

    return preventDefault;
}

void Aura::CallScriptEffectUpdatePeriodicHandlers(AuraEffect* aurEff)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_UPDATE_PERIODIC);
        for (AuraScript::EffectUpdatePeriodicHandler const& onEffectUpdatePeriodic : script->OnEffectUpdatePeriodic)
            if (onEffectUpdatePeriodic.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectUpdatePeriodic.Call(script, aurEff);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcAmountHandlers(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_AMOUNT);
        for (AuraScript::EffectCalcAmountHandler const& effectCalcAmount : script->DoEffectCalcAmount)
            if (effectCalcAmount.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effectCalcAmount.Call(script, aurEff, amount, canBeRecalculated);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcPeriodicHandlers(AuraEffect const* aurEff, bool& isPeriodic, int32& amplitude)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_PERIODIC);
        for (AuraScript::EffectCalcPeriodicHandler const& effectCalcPeriodic : script->DoEffectCalcPeriodic)
            if (effectCalcPeriodic.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effectCalcPeriodic.Call(script, aurEff, isPeriodic, amplitude);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcSpellModHandlers(AuraEffect const* aurEff, SpellModifier*& spellMod)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_SPELLMOD);
        for (AuraScript::EffectCalcSpellModHandler const& effectCalcSpellMod : script->DoEffectCalcSpellMod)
            if (effectCalcSpellMod.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effectCalcSpellMod.Call(script, aurEff, spellMod);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcCritChanceHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, Unit const* victim, float& critChance)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_CRIT_CHANCE, aurApp);
        for (AuraScript::EffectCalcCritChanceHandler const& effectCalcCritChance : script->DoEffectCalcCritChance)
            if (effectCalcCritChance.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effectCalcCritChance.Call(script, aurEff, victim, critChance);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptCalcDamageAndHealingHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, Unit* victim, int32& damageOrHealing, int32& flatMod, float& pctMod)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_DAMAGE_AND_HEALING, aurApp);
        for (AuraScript::EffectCalcDamageAndHealingHandler const& effectCalcDamageAndHealing : script->DoEffectCalcDamageAndHealing)
            if (effectCalcDamageAndHealing.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effectCalcDamageAndHealing.Call(script, aurEff, victim, damageOrHealing, flatMod, pctMod);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount, bool& defaultPrevented)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_ABSORB, aurApp);
        for (AuraScript::EffectAbsorbHandler const& onEffectAbsorb : script->OnEffectAbsorb)
            if (onEffectAbsorb.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectAbsorb.Call(script, aurEff, dmgInfo, absorbAmount);

        if (!defaultPrevented)
            defaultPrevented = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB, aurApp);
        for (AuraScript::EffectAbsorbHandler const& afterEffectAbsorb : script->AfterEffectAbsorb)
            if (afterEffectAbsorb.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                afterEffectAbsorb.Call(script, aurEff, dmgInfo, absorbAmount);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, HealInfo& healInfo, uint32& absorbAmount, bool& defaultPrevented)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_ABSORB, aurApp);
        for (AuraScript::EffectAbsorbHealHandler const& onEffectAbsorbHeal : script->OnEffectAbsorbHeal)
            if (onEffectAbsorbHeal.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectAbsorbHeal.Call(script, aurEff, healInfo, absorbAmount);

        if (!defaultPrevented)
            defaultPrevented = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, HealInfo& healInfo, uint32& absorbAmount)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB, aurApp);
        for (AuraScript::EffectAbsorbHealHandler const& afterEffectAbsorbHeal : script->AfterEffectAbsorbHeal)
            if (afterEffectAbsorbHeal.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                afterEffectAbsorbHeal.Call(script, aurEff, healInfo, absorbAmount);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount, bool& defaultPrevented)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_MANASHIELD, aurApp);
        for (AuraScript::EffectAbsorbHandler const& onEffectManaShield : script->OnEffectManaShield)
            if (onEffectManaShield.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectManaShield.Call(script, aurEff, dmgInfo, absorbAmount);

        if (!defaultPrevented)
            defaultPrevented = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD, aurApp);
        for (AuraScript::EffectAbsorbHandler const& afterEffectManaShield : script->AfterEffectManaShield)
            if (afterEffectManaShield.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                afterEffectManaShield.Call(script, aurEff, dmgInfo, absorbAmount);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectSplitHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& splitAmount)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_SPLIT, aurApp);
        for (AuraScript::EffectAbsorbHandler const& effectSplit : script->OnEffectSplit)
            if (effectSplit.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effectSplit.Call(script, aurEff, dmgInfo, splitAmount);

        script->_FinishScriptCall();
    }
}

void Aura::CallScriptEnterLeaveCombatHandlers(AuraApplication const* aurApp, bool isNowInCombat)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_ENTER_LEAVE_COMBAT, aurApp);
        for (AuraScript::EnterLeaveCombatHandler const& onEnterLeaveCombat : script->OnEnterLeaveCombat)
            onEnterLeaveCombat.Call(script, isNowInCombat);

        script->_FinishScriptCall();
    }
}

bool Aura::CallScriptCheckProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool result = true;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_PROC, aurApp);
        for (AuraScript::CheckProcHandler const& checkProc : script->DoCheckProc)
            result &= checkProc.Call(script, eventInfo);

        script->_FinishScriptCall();
    }

    return result;
}

bool Aura::CallScriptPrepareProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool prepare = true;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_PREPARE_PROC, aurApp);
        for (AuraScript::AuraProcHandler const& prepareProc : script->DoPrepareProc)
            prepareProc.Call(script, eventInfo);

        if (prepare)
            prepare = !script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }

    return prepare;
}

bool Aura::CallScriptProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool handled = false;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_PROC, aurApp);
        for (AuraScript::AuraProcHandler const& onProc : script->OnProc)
            onProc.Call(script, eventInfo);

        handled |= script->_IsDefaultActionPrevented();
        script->_FinishScriptCall();
    }

    return handled;
}

void Aura::CallScriptAfterProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_AFTER_PROC, aurApp);
        for (AuraScript::AuraProcHandler const& afterProc : script->AfterProc)
            afterProc.Call(script, eventInfo);

        script->_FinishScriptCall();
    }
}

bool Aura::CallScriptCheckEffectProcHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool result = true;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_EFFECT_PROC, aurApp);
        for (AuraScript::CheckEffectProcHandler const& checkEffectProc : script->DoCheckEffectProc)
            if (checkEffectProc.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                result &= checkEffectProc.Call(script, aurEff, eventInfo);

        script->_FinishScriptCall();
    }

    return result;
}

bool Aura::CallScriptEffectProcHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool preventDefault = false;
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_PROC, aurApp);
        for (AuraScript::EffectProcHandler const& onEffectProc : script->OnEffectProc)
            if (onEffectProc.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                onEffectProc.Call(script, aurEff, eventInfo);

        if (!preventDefault)
            preventDefault = script->_IsDefaultActionPrevented();

        script->_FinishScriptCall();
    }
    return preventDefault;
}

void Aura::CallScriptAfterEffectProcHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    for (AuraScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_PROC, aurApp);
        for (AuraScript::EffectProcHandler const& afterEffectProc : script->AfterEffectProc)
            if (afterEffectProc.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                afterEffectProc.Call(script, aurEff, eventInfo);

        script->_FinishScriptCall();
    }
}

std::string Aura::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << "Id: " << GetId() << " Name: '" << (*GetSpellInfo()->SpellName)[sWorld->GetDefaultDbcLocale()] << "' Caster: " << GetCasterGUID().ToString()
        << "\nOwner: " << (GetOwner() ? GetOwner()->GetDebugInfo() : "NULL");
    return sstr.str();
}

UnitAura::UnitAura(AuraCreateInfo const& createInfo)
    : Aura(createInfo)
{
    m_AuraDRGroup = DIMINISHING_NONE;
    LoadScripts();
    _InitEffects(createInfo._auraEffectMask, createInfo.Caster, createInfo.BaseAmount);
    GetUnitOwner()->_AddAura(this, createInfo.Caster);
}

void UnitAura::_ApplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp)
{
    Aura::_ApplyForTarget(target, caster, aurApp);

    // register aura diminishing on apply
    if (DiminishingGroup group = GetDiminishGroup())
        target->ApplyDiminishingAura(group, true);
}

void UnitAura::_UnapplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp)
{
    Aura::_UnapplyForTarget(target, caster, aurApp);

    // unregister aura diminishing (and store last time)
    if (DiminishingGroup group = GetDiminishGroup())
        target->ApplyDiminishingAura(group, false);
}

void UnitAura::Remove(AuraRemoveMode removeMode)
{
    if (IsRemoved())
        return;
    GetUnitOwner()->RemoveOwnedAura(this, removeMode);
}

void UnitAura::FillTargetMap(std::unordered_map<Unit*, uint32>& targets, Unit* caster)
{
    if (GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD) && !GetUnitOwner()->IsAlive())
        return;

    Unit* ref = caster;
    if (!ref)
        ref = GetUnitOwner();

    // add non area aura targets
    // static applications go through spell system first, so we assume they meet conditions
    for (auto const& targetPair : _staticApplications)
    {
        Unit* target = ObjectAccessor::GetUnit(*GetUnitOwner(), targetPair.first);
        if (!target && targetPair.first == GetUnitOwner()->GetGUID())
            target = GetUnitOwner();

        if (target)
            targets.emplace(target, targetPair.second);
    }

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        if (!HasEffect(spellEffectInfo.EffectIndex))
            continue;

        // area auras only
        if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            continue;

        // skip area update if owner is not in world!
        if (!GetUnitOwner()->IsInWorld())
            continue;

        if (GetUnitOwner()->HasUnitState(UNIT_STATE_ISOLATED))
            continue;

        std::vector<WorldObject*> units;
        ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions.get();

        float radius = spellEffectInfo.CalcRadius(ref);
        float extraSearchRadius = 0.0f;

        SpellTargetCheckTypes selectionType = TARGET_CHECK_DEFAULT;
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM:
                selectionType = TARGET_CHECK_PARTY;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
                selectionType = TARGET_CHECK_RAID;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
                selectionType = TARGET_CHECK_ALLY;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
                selectionType = TARGET_CHECK_ENEMY;
                extraSearchRadius = radius > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_PET:
                if (!condList || sConditionMgr->IsObjectMeetToConditions(GetUnitOwner(), ref, *condList))
                    units.push_back(GetUnitOwner());
                [[fallthrough]];
            case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
            {
                if (Unit* owner = GetUnitOwner()->GetCharmerOrOwner())
                    if (GetUnitOwner()->IsWithinDistInMap(owner, radius))
                        if (!condList || sConditionMgr->IsObjectMeetToConditions(owner, ref, *condList))
                            units.push_back(owner);
                break;
            }
            case SPELL_EFFECT_APPLY_AURA_ON_PET:
            {
                if (Unit* pet = ObjectAccessor::GetUnit(*GetUnitOwner(), GetUnitOwner()->GetPetGUID()))
                    if (!condList || sConditionMgr->IsObjectMeetToConditions(pet, ref, *condList))
                        units.push_back(pet);
                break;
            }
            case SPELL_EFFECT_APPLY_AREA_AURA_SUMMONS:
            {
                if (!condList || sConditionMgr->IsObjectMeetToConditions(GetUnitOwner(), ref, *condList))
                    units.push_back(GetUnitOwner());

                selectionType = TARGET_CHECK_SUMMONED;
                break;
            }
            default:
                break;
        }

        if (selectionType != TARGET_CHECK_DEFAULT)
        {
            if (uint32 containerTypeMask = Spell::GetSearcherTypeMask(m_spellInfo, spellEffectInfo, TARGET_OBJECT_TYPE_UNIT, condList))
            {
                Trinity::WorldObjectSpellAreaTargetCheck check(radius, GetUnitOwner(), ref, GetUnitOwner(), m_spellInfo, selectionType, condList, TARGET_OBJECT_TYPE_UNIT);
                Trinity::WorldObjectListSearcher searcher(GetUnitOwner(), units, check, containerTypeMask);
                searcher.i_phaseShift = &PhasingHandler::GetAlwaysVisiblePhaseShift();
                Spell::SearchTargets(searcher, containerTypeMask, GetUnitOwner(), GetUnitOwner(), radius + extraSearchRadius);

                // by design WorldObjectSpellAreaTargetCheck allows not-in-world units (for spells) but for auras it is not acceptable
                Trinity::Containers::EraseIf(units, [this](WorldObject const* unit) { return !unit->IsSelfOrInSameMap(GetUnitOwner()); });
            }
        }

        for (WorldObject* unit : units)
            targets[static_cast<Unit*>(unit)] |= 1 << spellEffectInfo.EffectIndex;
    }
}

void UnitAura::AddStaticApplication(Unit* target, uint32 effMask)
{
    // only valid for non-area auras
    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        if ((effMask & (1 << spellEffectInfo.EffectIndex)) && !spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            effMask &= ~(1 << spellEffectInfo.EffectIndex);
    }

    if (!effMask)
        return;

    _staticApplications[target->GetGUID()] |= effMask;
}

DynObjAura::DynObjAura(AuraCreateInfo const& createInfo)
    : Aura(createInfo)
{
    LoadScripts();
    ASSERT(GetDynobjOwner());
    ASSERT(GetDynobjOwner()->IsInWorld());
    ASSERT(createInfo.Caster);
    ASSERT(GetDynobjOwner()->GetMap() == createInfo.Caster->GetMap());
    _InitEffects(createInfo._auraEffectMask, createInfo.Caster, createInfo.BaseAmount);
    GetDynobjOwner()->SetAura(this);
}

void DynObjAura::Remove(AuraRemoveMode removeMode)
{
    if (IsRemoved())
        return;
    _Remove(removeMode);
}

void DynObjAura::FillTargetMap(std::unordered_map<Unit*, uint32>& targets, Unit* /*caster*/)
{
    Unit* dynObjOwnerCaster = GetDynobjOwner()->GetCaster();
    float radius = GetDynobjOwner()->GetRadius();

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        if (!HasEffect(spellEffectInfo.EffectIndex))
            continue;

        // we can't use effect type like area auras to determine check type, check targets
        SpellTargetCheckTypes selectionType = spellEffectInfo.TargetA.GetCheckType();
        if (spellEffectInfo.TargetB.GetReferenceType() == TARGET_REFERENCE_TYPE_DEST)
            selectionType = spellEffectInfo.TargetB.GetCheckType();

        std::vector<Unit*> units;
        ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions.get();

        Trinity::WorldObjectSpellAreaTargetCheck check(radius, GetDynobjOwner(), dynObjOwnerCaster, dynObjOwnerCaster, m_spellInfo, selectionType, condList, TARGET_OBJECT_TYPE_UNIT);
        Trinity::UnitListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(GetDynobjOwner(), units, check);
        Cell::VisitAllObjects(GetDynobjOwner(), searcher, radius);

        // by design WorldObjectSpellAreaTargetCheck allows not-in-world units (for spells) but for auras it is not acceptable
        units.erase(std::remove_if(units.begin(), units.end(), [this](Unit* unit) { return !unit->IsSelfOrInSameMap(GetDynobjOwner()); }), units.end());

        for (Unit* unit : units)
            targets[unit] |= 1 << spellEffectInfo.EffectIndex;
    }
}
