/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Common.h"
#include "CellImpl.h"
#include "Config.h"
#include "DB2Stores.h"
#include "DynamicObject.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
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

AuraApplication::AuraApplication(Unit* target, Unit* caster, Aura* aura, uint32 effMask):
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
        TC_LOG_DEBUG("spells", "Aura: %u Effect: %d put to unit visible auras slot: %u", GetBase()->GetId(), GetEffectMask(), slot);
    }
    else
        TC_LOG_ERROR("spells", "Aura: %u Effect: %d could not find empty unit visible slot", GetBase()->GetId(), GetEffectMask());

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
        for (SpellEffectInfo const* effect : GetBase()->GetSpellEffectInfos())
        {
            if (effect && ((1 << effect->EffectIndex) & effMask) && !GetBase()->GetSpellInfo()->IsPositiveEffect(effect->EffectIndex))
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
        for (SpellEffectInfo const* effect : GetBase()->GetSpellEffectInfos())
        {
            if (effect && ((1 << effect->EffectIndex) & effMask) && GetBase()->GetSpellInfo()->IsPositiveEffect(effect->EffectIndex))
            {
                positiveFound = true;
                break;
            }
        }
        _flags |= positiveFound ? AFLAG_POSITIVE : AFLAG_NEGATIVE;
    }

    if (GetBase()->GetSpellInfo()->HasAttribute(SPELL_ATTR8_AURA_SEND_AMOUNT) ||
        GetBase()->HasEffectType(SPELL_AURA_MOD_SPELL_CATEGORY_COOLDOWN) ||
        GetBase()->HasEffectType(SPELL_AURA_MOD_MAX_CHARGES) ||
        GetBase()->HasEffectType(SPELL_AURA_CHARGE_RECOVERY_MOD) ||
        GetBase()->HasEffectType(SPELL_AURA_CHARGE_RECOVERY_MULTIPLIER))
        _flags |= AFLAG_SCALABLE;
}

void AuraApplication::_HandleEffect(uint8 effIndex, bool apply)
{
    AuraEffect* aurEff = GetBase()->GetEffect(effIndex);
    if (!aurEff)
    {
        TC_LOG_ERROR("spells", "Aura %u has no effect at effectIndex %u but _HandleEffect was called", GetBase()->GetSpellInfo()->Id, uint32(effIndex));
        return;
    }
    ASSERT(aurEff);
    ASSERT(HasEffect(effIndex) == (!apply));
    ASSERT((1<<effIndex) & _effectsToApply);
    TC_LOG_DEBUG("spells", "AuraApplication::_HandleEffect: %u, apply: %u: amount: %u", aurEff->GetAuraType(), apply, aurEff->GetAmount());

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

    auraInfo.AuraData = boost::in_place();

    Aura const* aura = GetBase();

    WorldPackets::Spells::AuraDataInfo& auraData = auraInfo.AuraData.get();
    auraData.CastID = aura->GetCastGUID();
    auraData.SpellID = aura->GetId();
    auraData.SpellXSpellVisualID = aura->GetSpellXSpellVisualId();
    auraData.Flags = GetFlags();
    if (aura->GetMaxDuration() > 0 && !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR5_HIDE_DURATION))
        auraData.Flags |= AFLAG_DURATION;

    auraData.ActiveFlags = GetEffectMask();
    if (!aura->GetSpellInfo()->HasAttribute(SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL))
        auraData.CastLevel = aura->GetCasterLevel();
    else
        auraData.CastLevel = uint16(aura->GetCastItemLevel());

    // send stack amount for aura which could be stacked (never 0 - causes incorrect display) or charges
    // stack amount has priority over charges (checked on retail with spell 50262)
    auraData.Applications = aura->GetSpellInfo()->StackAmount ? aura->GetStackAmount() : aura->GetCharges();
    if (!(auraData.Flags & AFLAG_NOCASTER))
        auraData.CastUnit = aura->GetCasterGUID();

    if (auraData.Flags & AFLAG_DURATION)
    {
        auraData.Duration = aura->GetMaxDuration();
        auraData.Remaining = aura->GetDuration();
    }

    if (auraData.Flags & AFLAG_SCALABLE)
    {
        auraData.Points.resize(aura->GetAuraEffects().size(), 0.0f);
        for (AuraEffect const* effect : GetBase()->GetAuraEffects())
            if (effect && HasEffect(effect->GetEffIndex()))       // Not all of aura's effects have to be applied on every target
                auraData.Points[effect->GetEffIndex()] = float(effect->GetAmount());
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

uint32 Aura::BuildEffectMaskForOwner(SpellInfo const* spellProto, uint32 availableEffectMask, WorldObject* owner)
{
    ASSERT(spellProto);
    ASSERT(owner);
    uint32 effMask = 0;
    switch (owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
            for (SpellEffectInfo const* effect : spellProto->GetEffectsForDifficulty(owner->GetMap()->GetDifficultyID()))
            {
                if (effect && effect->IsUnitOwnedAuraEffect())
                    effMask |= 1 << effect->EffectIndex;
            }
            break;
        case TYPEID_DYNAMICOBJECT:
            for (SpellEffectInfo const* effect : spellProto->GetEffectsForDifficulty(owner->GetMap()->GetDifficultyID()))
            {
                if (effect && effect->Effect == SPELL_EFFECT_PERSISTENT_AREA_AURA)
                    effMask |= 1 << effect->EffectIndex;
            }
            break;
        default:
            ABORT();
            break;
    }

    return effMask & availableEffectMask;
}

Aura* Aura::TryRefreshStackOrCreate(SpellInfo const* spellproto, ObjectGuid castId, uint32 tryEffMask, WorldObject* owner, Unit* caster, int32* baseAmount /*= nullptr*/, Item* castItem /*= nullptr*/, ObjectGuid casterGUID /*= ObjectGuid::Empty*/, bool* refresh /*= nullptr*/, bool resetPeriodicTimer /*= true*/, ObjectGuid castItemGuid /*= ObjectGuid::Empty*/, int32 castItemLevel /*= -1*/)
{
    ASSERT(spellproto);
    ASSERT(owner);
    ASSERT(caster || !casterGUID.IsEmpty());
    ASSERT(tryEffMask <= MAX_EFFECT_MASK);
    if (refresh)
        *refresh = false;

    uint32 effMask = Aura::BuildEffectMaskForOwner(spellproto, tryEffMask, owner);
    if (!effMask)
        return nullptr;

    if (Aura* foundAura = owner->ToUnit()->_TryStackingOrRefreshingExistingAura(spellproto, effMask, caster, baseAmount, castItem, casterGUID, resetPeriodicTimer, castItemGuid, castItemLevel))
    {
        // we've here aura, which script triggered removal after modding stack amount
        // check the state here, so we won't create new Aura object
        if (foundAura->IsRemoved())
            return nullptr;

        if (refresh)
            *refresh = true;

        return foundAura;
    }
    else
        return Create(spellproto, castId, effMask, owner, caster, baseAmount, castItem, casterGUID, castItemGuid, castItemLevel);
}

Aura* Aura::TryCreate(SpellInfo const* spellproto, ObjectGuid castId, uint32 tryEffMask, WorldObject* owner, Unit* caster, int32* baseAmount /*= nullptr*/, Item* castItem /*= nullptr*/, ObjectGuid casterGUID /*= ObjectGuid::Empty*/, ObjectGuid castItemGuid /*= ObjectGuid::Empty*/, int32 castItemLevel /*= -1*/)
{
    ASSERT(spellproto);
    ASSERT(owner);
    ASSERT(caster || !casterGUID.IsEmpty());
    ASSERT(tryEffMask <= MAX_EFFECT_MASK);
    uint32 effMask = Aura::BuildEffectMaskForOwner(spellproto, tryEffMask, owner);
    if (!effMask)
        return nullptr;

    return Create(spellproto, castId, effMask, owner, caster, baseAmount, castItem, casterGUID, castItemGuid, castItemLevel);
}

Aura* Aura::Create(SpellInfo const* spellproto, ObjectGuid castId, uint32 effMask, WorldObject* owner, Unit* caster, int32 *baseAmount, Item* castItem, ObjectGuid casterGUID, ObjectGuid castItemGuid, int32 castItemLevel)
{
    ASSERT(effMask);
    ASSERT(spellproto);
    ASSERT(owner);
    ASSERT(caster || !casterGUID.IsEmpty());
    ASSERT(effMask <= MAX_EFFECT_MASK);
    // try to get caster of aura
    if (!casterGUID.IsEmpty())
    {
        if (owner->GetGUID() == casterGUID)
            caster = owner->ToUnit();
        else
            caster = ObjectAccessor::GetUnit(*owner, casterGUID);
    }
    else
        casterGUID = caster->GetGUID();

    // check if aura can be owned by owner
    if (owner->isType(TYPEMASK_UNIT))
        if (!owner->IsInWorld() || ((Unit*)owner)->IsDuringRemoveFromWorld())
            // owner not in world so don't allow to own not self cast single target auras
            if (casterGUID != owner->GetGUID() && spellproto->IsSingleTarget())
                return nullptr;

    Aura* aura = nullptr;
    switch (owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
            aura = new UnitAura(spellproto, castId, effMask, owner, caster, baseAmount, castItem, casterGUID, castItemGuid, castItemLevel);
            break;
        case TYPEID_DYNAMICOBJECT:
            aura = new DynObjAura(spellproto, castId, effMask, owner, caster, baseAmount, castItem, casterGUID, castItemGuid, castItemLevel);
            break;
        default:
            ABORT();
            return nullptr;
    }

    // aura can be removed in Unit::_AddAura call
    if (aura->IsRemoved())
        return nullptr;
    return aura;
}

Aura::Aura(SpellInfo const* spellproto, ObjectGuid castId, WorldObject* owner, Unit* caster, Item* castItem, ObjectGuid casterGUID, ObjectGuid castItemGuid, int32 castItemLevel) :
m_spellInfo(spellproto), m_castGuid(castId), m_casterGuid(!casterGUID.IsEmpty() ? casterGUID : caster->GetGUID()),
m_castItemGuid(castItem ? castItem->GetGUID() : castItemGuid), m_castItemLevel(castItemLevel), m_spellXSpellVisualId(caster ? caster->GetCastSpellXSpellVisualId(spellproto) : spellproto->GetSpellXSpellVisualId()),
m_applyTime(time(NULL)), m_owner(owner), m_timeCla(0), m_updateTargetMapInterval(0),
m_casterLevel(caster ? caster->getLevel() : m_spellInfo->SpellLevel), m_procCharges(0), m_stackAmount(1),
m_isRemoved(false), m_isSingleTarget(false), m_isUsingCharges(false), m_dropEvent(nullptr),
m_procCooldown(std::chrono::steady_clock::time_point::min()),
m_lastProcAttemptTime(std::chrono::steady_clock::now() - Seconds(10)), m_lastProcSuccessTime(std::chrono::steady_clock::now() - Seconds(120))
{
    std::vector<SpellPowerEntry const*> powers = sDB2Manager.GetSpellPowers(GetId(), caster ? caster->GetMap()->GetDifficultyID() : DIFFICULTY_NONE);
    for (SpellPowerEntry const* power : powers)
        if (power->ManaCostPerSecond != 0 || power->ManaCostPercentagePerSecond > 0.0f)
            m_periodicCosts.push_back(power);

    if (!m_periodicCosts.empty())
        m_timeCla = 1 * IN_MILLISECONDS;

    m_maxDuration = CalcMaxDuration(caster);
    m_duration = m_maxDuration;
    m_procCharges = CalcMaxCharges(caster);
    m_isUsingCharges = m_procCharges != 0;
    // m_casterLevel = cast item level/caster level, caster level should be saved to db, confirmed with sniffs
}

AuraScript* Aura::GetScriptByName(std::string const& scriptName) const
{
    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
        if ((*itr)->_GetScriptName()->compare(scriptName) == 0)
            return *itr;
    return nullptr;
}

SpellEffectInfo const* Aura::GetSpellEffectInfo(uint32 index) const
{
    if (index >= _spelEffectInfos.size())
        return nullptr;

    return _spelEffectInfos[index];
}

void Aura::_InitEffects(uint32 effMask, Unit* caster, int32 *baseAmount)
{
    // shouldn't be in constructor - functions in AuraEffect::AuraEffect use polymorphism
    _spelEffectInfos = m_spellInfo->GetEffectsForDifficulty(GetOwner()->GetMap()->GetDifficultyID());

    ASSERT(!_spelEffectInfos.empty());

    _effects.resize(GetSpellEffectInfos().size());

    for (SpellEffectInfo const* effect : GetSpellEffectInfos())
    {
        if (effect && effMask & (1 << effect->EffectIndex))
            _effects[effect->EffectIndex] = new AuraEffect(this, effect->EffectIndex, baseAmount ? baseAmount + effect->EffectIndex : NULL, caster);
    }
}

Aura::~Aura()
{
    // unload scripts
    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
    {
        (*itr)->_Unload();
        delete (*itr);
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
    if (AuraApplication const* aurApp = GetApplicationOfTarget(GetCasterGUID()))
        return aurApp->GetTarget();

    return ObjectAccessor::GetUnit(*GetOwner(), GetCasterGUID());
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

void Aura::_ApplyForTarget(Unit* target, Unit* caster, AuraApplication * auraApp)
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
            Item* castItem = !m_castItemGuid.IsEmpty() ? caster->ToPlayer()->GetItemByGuid(m_castItemGuid) : NULL;
            caster->GetSpellHistory()->StartCooldown(m_spellInfo, castItem ? castItem->GetEntry() : 0, nullptr, true);
        }
    }
}

void Aura::_UnapplyForTarget(Unit* target, Unit* caster, AuraApplication * auraApp)
{
    ASSERT(target);
    ASSERT(auraApp->GetRemoveMode());
    ASSERT(auraApp);

    ApplicationMap::iterator itr = m_applications.find(target->GetGUID());

    /// @todo Figure out why this happens
    if (itr == m_applications.end())
    {
        TC_LOG_ERROR("spells", "Aura::_UnapplyForTarget, target: %s, caster:%s, spell:%u was not found in owners application map!",
            target->GetGUID().ToString().c_str(), caster ? caster->GetGUID().ToString().c_str() : "Empty", auraApp->GetBase()->GetSpellInfo()->Id);
        ABORT();
    }

    // aura has to be already applied
    ASSERT(itr->second == auraApp);
    m_applications.erase(itr);

    m_removedApplications.push_back(auraApp);

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

    std::deque<Unit*> targetsToRemove;

    // mark all auras as ready to remove
    for (ApplicationMap::iterator appIter = m_applications.begin(); appIter != m_applications.end();++appIter)
    {
        auto itr = targets.find(appIter->second->GetTarget());
        // not found in current area - remove the aura
        if (itr == targets.end())
            targetsToRemove.push_back(appIter->second->GetTarget());
        else
        {
            // needs readding - remove now, will be applied in next update cycle
            // (dbcs do not have auras which apply on same type of targets but have different radius, so this is not really needed)
            if (appIter->second->GetEffectMask() != itr->second || !CanBeAppliedOn(itr->first))
                targetsToRemove.push_back(appIter->second->GetTarget());
            // nothing todo - aura already applied
            // remove from auras to register list
            targets.erase(itr);
        }
    }

    // register auras for units
    for (auto itr = targets.begin(); itr!= targets.end();)
    {
        // aura mustn't be already applied on target
        if (AuraApplication* aurApp = GetApplicationOfTarget(itr->first->GetGUID()))
        {
            // the core created 2 different units with same guid
            // this is a major failue, which i can't fix right now
            // let's remove one unit from aura list
            // this may cause area aura "bouncing" between 2 units after each update
            // but because we know the reason of a crash we can remove the assertion for now
            if (aurApp->GetTarget() != itr->first)
            {
                // remove from auras to register list
                itr = targets.erase(itr);
                continue;
            }
            else
            {
                // ok, we have one unit twice in target map (impossible, but...)
                ABORT();
            }
        }

        bool addUnit = true;
        // check target immunities
        for (uint8 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        {
            if (itr->first->IsImmunedToSpellEffect(GetSpellInfo(), effIndex))
                itr->second &= ~(1 << effIndex);
        }
        if (!itr->second
            || itr->first->IsImmunedToSpell(GetSpellInfo())
            || !CanBeAppliedOn(itr->first))
            addUnit = false;

        if (addUnit && !itr->first->IsHighestExclusiveAura(this, true))
            addUnit = false;

        if (addUnit)
        {
            // persistent area aura does not hit flying targets
            if (GetType() == DYNOBJ_AURA_TYPE)
            {
                if (itr->first->IsInFlight())
                    addUnit = false;
            }
            // unit auras can not stack with each other
            else // (GetType() == UNIT_AURA_TYPE)
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
        }
        if (!addUnit)
            itr = targets.erase(itr);
        else
        {
            // owner has to be in world, or effect has to be applied to self
            if (!GetOwner()->IsSelfOrInSameMap(itr->first))
            {
                /// @todo There is a crash caused by shadowfiend load addon
                TC_LOG_FATAL("spells", "Aura %u: Owner %s (map %u) is not in the same map as target %s (map %u).", GetSpellInfo()->Id,
                    GetOwner()->GetName().c_str(), GetOwner()->IsInWorld() ? GetOwner()->GetMap()->GetId() : uint32(-1),
                    itr->first->GetName().c_str(), itr->first->IsInWorld() ? itr->first->GetMap()->GetId() : uint32(-1));
                ABORT();
            }
            itr->first->_CreateAuraApplication(this, itr->second);
            ++itr;
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
    Spell* modSpell = NULL;
    Player* modOwner = NULL;
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
            else if (caster)
            {
                if (!m_periodicCosts.empty())
                {
                    m_timeCla += 1000 - diff;

                    for (SpellPowerEntry const* power : m_periodicCosts)
                    {
                        if (power->RequiredAura && !caster->HasAura(power->RequiredAura))
                            continue;

                        int32 manaPerSecond = power->ManaCostPerSecond;
                        Powers powertype = Powers(power->PowerType);
                        if (powertype != POWER_HEALTH)
                            manaPerSecond += int32(CalculatePct(caster->GetMaxPower(powertype), power->ManaCostPercentagePerSecond));
                        else
                            manaPerSecond += int32(CalculatePct(caster->GetMaxHealth(), power->ManaCostPercentagePerSecond));

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
    Player* modOwner = NULL;
    int32 maxDuration;

    if (caster)
    {
        modOwner = caster->GetSpellModOwner();
        maxDuration = caster->CalcSpellDuration(m_spellInfo);
    }
    else
        maxDuration = m_spellInfo->GetDuration();

    if (IsPassive() && !m_spellInfo->DurationEntry)
        maxDuration = -1;

    // IsPermanent() checks max duration (which we are supposed to calculate here)
    if (maxDuration != -1 && modOwner)
        modOwner->ApplySpellMod(GetId(), SPELLMOD_DURATION, maxDuration);

    return maxDuration;
}

void Aura::SetDuration(int32 duration, bool withMods)
{
    if (withMods)
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetId(), SPELLMOD_DURATION, duration);

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
        if (caster->HasAuraTypeWithAffectMask(SPELL_AURA_PERIODIC_HASTE, m_spellInfo) || m_spellInfo->HasAttribute(SPELL_ATTR5_HASTE_AFFECT_DURATION))
            duration = int32(duration * caster->GetFloatValue(UNIT_MOD_CAST_SPEED));

        SetMaxDuration(duration);
        SetDuration(duration);
    }
    else
        SetDuration(GetMaxDuration());

    if (!m_periodicCosts.empty())
        m_timeCla = 1 * IN_MILLISECONDS;
}

void Aura::RefreshTimers(bool resetPeriodicTimer)
{
    m_maxDuration = CalcMaxDuration();
    if (m_spellInfo->HasAttribute(SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER))
    {
        int32 minPeriod = m_maxDuration;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (AuraEffect const* eff = GetEffect(i))
                if (int32 period = eff->GetPeriod())
                    minPeriod = std::min(period, minPeriod);

        // If only one tick remaining, roll it over into new duration
        if (GetDuration() <= minPeriod)
        {
            m_maxDuration += GetDuration();
            resetPeriodicTimer = false;
        }
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
    if (SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetId()))
        maxProcCharges = procEntry->Charges;

    if (caster)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetId(), SPELLMOD_CHARGES, maxProcCharges);

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
    owner->m_Events.AddEvent(m_dropEvent, owner->m_Events.CalculateTime(delay));
}

void Aura::SetStackAmount(uint8 stackAmount)
{
    m_stackAmount = stackAmount;
    Unit* caster = GetCaster();

    std::list<AuraApplication*> applications;
    GetApplicationList(applications);

    for (std::list<AuraApplication*>::const_iterator apptItr = applications.begin(); apptItr != applications.end(); ++apptItr)
        if (!(*apptItr)->GetRemoveMode())
            HandleAuraSpecificMods(*apptItr, caster, false, true);

    for (AuraEffect* effect : GetAuraEffects())
        if (effect)
            effect->ChangeAmount(effect->CalculateAmount(caster), false, true);

    for (std::list<AuraApplication*>::const_iterator apptItr = applications.begin(); apptItr != applications.end(); ++apptItr)
        if (!(*apptItr)->GetRemoveMode())
        {
            HandleAuraSpecificMods(*apptItr, caster, true, true);
            HandleAuraSpecificPeriodics(*apptItr, caster);
        }

    SetNeedClientUpdateForTargets();
}

bool Aura::ModStackAmount(int32 num, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/, bool resetPeriodicTimer /*= true*/)
{
    int32 stackAmount = m_stackAmount + num;

    // limit the stack amount (only on stack increase, stack amount may be changed manually)
    if ((num > 0) && (stackAmount > int32(m_spellInfo->StackAmount)))
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

    bool refresh = stackAmount >= GetStackAmount();

    // Update stack amount
    SetStackAmount(stackAmount);

    if (refresh)
    {
        RefreshSpellMods();
        RefreshTimers(resetPeriodicTimer);

        // reset charges
        SetCharges(CalcMaxCharges());
    }

    SetNeedClientUpdateForTargets();
    return false;
}

void Aura::RefreshSpellMods()
{
    for (Aura::ApplicationMap::const_iterator appIter = m_applications.begin(); appIter != m_applications.end(); ++appIter)
        if (Player* player = appIter->second->GetTarget()->ToPlayer())
            player->RestoreAllSpellMods(0, this);
}

bool Aura::HasMoreThanOneEffectForType(AuraType auraType) const
{
    uint32 count = 0;
    for (SpellEffectInfo const* effect : GetSpellEffectInfos())
        if (effect && HasEffect(effect->EffectIndex) && AuraType(effect->ApplyAuraName) == auraType)
            ++count;

    return count > 1;
}

bool Aura::IsArea() const
{
    for (SpellEffectInfo const* effect : GetSpellEffectInfos())
        if (effect && HasEffect(effect->EffectIndex) && effect->IsAreaAuraEffect())
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

bool Aura::CanBeSaved() const
{
    if (IsPassive())
        return false;

    if (GetCasterGUID() != GetOwner()->GetGUID())
        if (GetSpellInfo()->IsSingleTarget())
            return false;

    // No point in saving this, since the stable dialog can't be open on aura load anyway.
    if (HasEffectType(SPELL_AURA_OPEN_STABLE))
        return false;

    // Can't save vehicle auras, it requires both caster & target to be in world
    if (HasEffectType(SPELL_AURA_CONTROL_VEHICLE))
        return false;

    // Incanter's Absorbtion - considering the minimal duration and problems with aura stacking
    // we skip saving this aura
    // Also for some reason other auras put as MultiSlot crash core on keeping them after restart,
    // so put here only these for which you are sure they get removed
    switch (GetId())
    {
        case 44413: // Incanter's Absorption
        case 40075: // Fel Flak Fire
        case 55849: // Power Spark
            return false;
    }

    // When a druid logins, he doesnt have either eclipse power, nor the marker auras, nor the eclipse buffs. Dont save them.
    if (GetId() == 67483 || GetId() == 67484 || GetId() == 48517 || GetId() == 48518)
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
        case SPELL_SPECIFIC_JUDGEMENT:
        case SPELL_SPECIFIC_MAGE_POLYMORPH:
            if (aura->GetSpellInfo()->GetSpellSpecific() == spec)
                return true;
            break;
        default:
            break;
    }

    if (HasEffectType(SPELL_AURA_CONTROL_VEHICLE) && aura->HasEffectType(SPELL_AURA_CONTROL_VEHICLE))
        return true;

    return false;
}

void Aura::UnregisterSingleTarget()
{
    ASSERT(m_isSingleTarget);
    Unit* caster = GetCaster();
    ASSERT(caster);
    caster->GetSingleCastAuras().remove(this);
    SetIsSingleTarget(false);
}

int32 Aura::CalcDispelChance(Unit* auraTarget, bool offensive) const
{
    // we assume that aura dispel chance is 100% on start
    // need formula for level difference based chance
    int32 resistChance = 0;

    // Apply dispel mod from aura caster
    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetId(), SPELLMOD_RESIST_DISPEL_CHANCE, resistChance);

    // Dispel resistance from target SPELL_AURA_MOD_DISPEL_RESIST
    // Only affects offensive dispels
    if (offensive && auraTarget)
        resistChance += auraTarget->GetTotalAuraModifier(SPELL_AURA_MOD_DISPEL_RESIST);

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
    for (AuraEffect* effect : GetAuraEffects())
        if (effect)
            effMask |= 1 << effect->GetEffIndex();
    return effMask;
}

void Aura::GetApplicationList(Unit::AuraApplicationList& applicationList) const
{
    for (Aura::ApplicationMap::const_iterator appIter = m_applications.begin(); appIter != m_applications.end(); ++appIter)
    {
        if (appIter->second->GetEffectMask())
            applicationList.push_back(appIter->second);
    }
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
            if (!itr->second->IsFitToRequirements(target->ToPlayer(), zone, area))
                target->RemoveAurasDueToSpell(itr->second->spellId);
            // some auras applied at aura apply
            else if (itr->second->autocast)
            {
                if (!target->HasAura(itr->second->spellId))
                    target->CastSpell(target, itr->second->spellId, true);
            }
        }
    }

    // handle spell_linked_spell table
    if (!onReapply)
    {
        // apply linked auras
        if (apply)
        {
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(GetId() + SPELL_LINK_AURA))
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
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(-(int32)GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->RemoveAurasDueToSpell(-(*itr));
                    else if (removeMode != AURA_REMOVE_BY_DEATH)
                        target->CastSpell(target, *itr, true, NULL, NULL, GetCasterGUID());
                }
            }
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(GetId() + SPELL_LINK_AURA))
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
        if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(GetId() + SPELL_LINK_AURA))
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
                    case 32474: // Buffeting Winds of Susurrus
                        if (target->GetTypeId() == TYPEID_PLAYER)
                            target->ToPlayer()->ActivateTaxiPathTo(506, GetId());
                        break;
                    case 33572: // Gronn Lord's Grasp, becomes stoned
                        if (GetStackAmount() >= 5 && !target->HasAura(33652))
                            target->CastSpell(target, 33652, true);
                        break;
                    case 50836: //Petrifying Grip, becomes stoned
                        if (GetStackAmount() >= 5 && !target->HasAura(50812))
                            target->CastSpell(target, 50812, true);
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
                        int32 heal = GetEffect(EFFECT_0)->GetAmount();
                        caster->CastCustomSpell(target, 64801, &heal, NULL, NULL, true, NULL, GetEffect(EFFECT_0));
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
                        target->CastSpell(target, 32612, true, NULL, GetEffect(1));
                        target->CombatStop();
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
                            if (caster->GetSpellHistory()->HasCooldown(aura->GetId()))
                            {
                                // This additional check is needed to add a minimal delay before cooldown in in effect
                                // to allow all bubbles broken by a single damage source proc mana return
                                if (caster->GetSpellHistory()->GetRemainingCooldown(aura->GetSpellInfo()) <= 11 * IN_MILLISECONDS)
                                    break;
                            }
                            else    // and add if needed
                                caster->GetSpellHistory()->AddCooldown(aura->GetId(), 0, std::chrono::seconds(12));
                        }

                        // effect on caster
                        if (AuraEffect const* aurEff = aura->GetEffect(0))
                        {
                            float multiplier = float(aurEff->GetAmount());
                            int32 basepoints0 = int32(CalculatePct(caster->GetMaxPower(POWER_MANA), multiplier));
                            caster->CastCustomSpell(caster, 47755, &basepoints0, NULL, NULL, true);
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
                                owner->CastSpell(owner, 34471, true, 0, GetEffect(0));
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
                            target->CastSpell(target, 71166, true);
                        else
                            target->RemoveAurasDueToSpell(71166);
                    }
                    break;
            }
            break;
    }
}

void Aura::HandleAuraSpecificPeriodics(AuraApplication const* aurApp, Unit* caster)
{
    Unit* target = aurApp->GetTarget();

    if (!caster || aurApp->GetRemoveMode())
        return;

    for (AuraEffect* effect : GetAuraEffects())
    {
        if (!effect || effect->IsAreaAuraEffect() || effect->IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
            continue;

        switch (effect->GetSpellEffectInfo()->ApplyAuraName)
        {
            case SPELL_AURA_PERIODIC_DAMAGE:
            case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
            case SPELL_AURA_PERIODIC_LEECH:
            {
                // ignore non positive values (can be result apply spellmods to aura damage
                uint32 damage = std::max(effect->GetAmount(), 0);

                // Script Hook For HandlePeriodicDamageAurasTick -- Allow scripts to change the Damage pre class mitigation calculations
                sScriptMgr->ModifyPeriodicDamageAurasTick(target, caster, damage);

                effect->SetDonePct(caster->SpellDamagePctDone(target, m_spellInfo, DOT)); // Calculate done percentage first!
                effect->SetDamage(caster->SpellDamageBonusDone(target, m_spellInfo, damage, DOT, effect->GetSpellEffectInfo(), GetStackAmount()) * effect->GetDonePct());
                effect->SetCritChance(caster->GetUnitSpellCriticalChance(target, m_spellInfo, m_spellInfo->GetSchoolMask()));
                break;
            }
            case SPELL_AURA_PERIODIC_HEAL:
            case SPELL_AURA_OBS_MOD_HEALTH:
            {
                // ignore non positive values (can be result apply spellmods to aura damage
                uint32 damage = std::max(effect->GetAmount(), 0);

                // Script Hook For HandlePeriodicDamageAurasTick -- Allow scripts to change the Damage pre class mitigation calculations
                sScriptMgr->ModifyPeriodicDamageAurasTick(target, caster, damage);

                effect->SetDonePct(caster->SpellHealingPctDone(target, m_spellInfo)); // Calculate done percentage first!
                effect->SetDamage(caster->SpellHealingBonusDone(target, m_spellInfo, damage, DOT, effect->GetSpellEffectInfo(), GetStackAmount()) * effect->GetDonePct());
                effect->SetCritChance(caster->GetUnitSpellCriticalChance(target, m_spellInfo, m_spellInfo->GetSchoolMask()));
                break;
            }
            default:
                break;
        }
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

    // Dynobj auras always stack
    if (GetType() == DYNOBJ_AURA_TYPE || existingAura->GetType() == DYNOBJ_AURA_TYPE)
        return true;

    SpellInfo const* existingSpellInfo = existingAura->GetSpellInfo();
    bool sameCaster = GetCasterGUID() == existingAura->GetCasterGUID();

    // passive auras don't stack with another rank of the spell cast by same caster
    if (IsPassive() && sameCaster && (m_spellInfo->IsDifferentRankOf(existingSpellInfo) || (m_spellInfo->Id == existingSpellInfo->Id && m_castItemGuid.IsEmpty())))
        return false;

    for (SpellEffectInfo const* effect : existingAura->GetSpellEffectInfos())
    {
        // prevent remove triggering aura by triggered aura
        if (effect && effect->TriggerSpell == GetId())
            return true;
    }

    for (SpellEffectInfo const* effect : GetSpellEffectInfos())
    {
        // prevent remove triggered aura by triggering aura refresh
        if (effect && effect->TriggerSpell == existingAura->GetId())
            return true;
    }

    // Check for custom server setting to allow tracking both Herbs and Minerals
    // Note: The following are client limitations and cannot be coded for:
    //  * The minimap tracking icon will display whichever skill is activated second
    //  * The minimap tracking list will only show a check mark next to the last skill activated
    //    Sometimes this bugs out and doesn't switch the check mark. It has no effect on the actual tracking though.
    //  * The minimap dots are yellow for both resources
    if (m_spellInfo->HasAura(GetOwner()->GetMap()->GetDifficultyID(), SPELL_AURA_TRACK_RESOURCES) && existingSpellInfo->HasAura(GetOwner()->GetMap()->GetDifficultyID(), SPELL_AURA_TRACK_RESOURCES))
        return sWorld->getBoolConfig(CONFIG_ALLOW_TRACK_BOTH_RESOURCES);

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

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_STACK_FOR_DIFF_CASTERS))
            return true;

        // check same periodic auras
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            SpellEffectInfo const* effect = GetSpellEffectInfo(i);
            if (!effect)
                continue;
            switch (effect->ApplyAuraName)
            {
                // DOT or HOT from different casters will stack
                case SPELL_AURA_PERIODIC_DAMAGE:
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
                    {
                        SpellEffectInfo const* existingEffect = GetSpellEffectInfo(i);
                        // periodic auras which target areas are not allowed to stack this way (replenishment for example)
                        if (effect->IsTargetingArea() || (existingEffect && existingEffect->IsTargetingArea()))
                            break;
                    }
                    return true;
                default:
                    break;
            }
        }
    }

    if (HasEffectType(SPELL_AURA_CONTROL_VEHICLE) && existingAura->HasEffectType(SPELL_AURA_CONTROL_VEHICLE))
    {
        Vehicle* veh = NULL;
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

bool Aura::IsProcOnCooldown(std::chrono::steady_clock::time_point now) const
{
    return m_procCooldown > now;
}

void Aura::AddProcCooldown(std::chrono::steady_clock::time_point cooldownEnd)
{
    m_procCooldown = cooldownEnd;
}

void Aura::PrepareProcToTrigger(AuraApplication* aurApp, ProcEventInfo& eventInfo, std::chrono::steady_clock::time_point now)
{
    bool prepare = CallScriptPrepareProcHandlers(aurApp, eventInfo);
    if (!prepare)
        return;

    // take one charge, aura expiration will be handled in Aura::TriggerProcOnEvent (if needed)
    if (IsUsingCharges())
    {
        --m_procCharges;
        SetNeedClientUpdateForTargets();
    }

    SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetId());
    ASSERT(procEntry);

    // cooldowns should be added to the whole aura (see 51698 area aura)
    AddProcCooldown(now + procEntry->Cooldown);

    SetLastProcSuccessTime(now);
}

uint32 Aura::IsProcTriggeredOnEvent(AuraApplication* aurApp, ProcEventInfo& eventInfo, std::chrono::steady_clock::time_point now) const
{
    SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetId());
    // only auras with spell proc entry can trigger proc
    if (!procEntry)
        return 0;

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
    if (!sSpellMgr->CanSpellTriggerProcOnEvent(*procEntry, eventInfo))
        return 0;

    // check don't break stealth attr present
    if (m_spellInfo->HasAura(DIFFICULTY_NONE, SPELL_AURA_MOD_STEALTH))
    {
        if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
            if (spellInfo->HasAttribute(SPELL_ATTR0_CU_DONT_BREAK_STEALTH))
                return 0;
    }

    // check if aura can proc when spell is triggered (exception for hunter auto shot & wands)
    if (!(procEntry->AttributesMask & PROC_ATTR_TRIGGERED_CAN_PROC) && !(eventInfo.GetTypeMask() & AUTO_ATTACK_PROC_FLAG_MASK))
        if (Spell const* spell = eventInfo.GetProcSpell())
            if (spell->IsTriggered())
                if (!GetSpellInfo()->HasAttribute(SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED))
                    return 0;

    // do checks using conditions table
    if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_SPELL_PROC, GetId(), eventInfo.GetActor(), eventInfo.GetActionTarget()))
        return 0;

    // AuraScript Hook
    bool check = const_cast<Aura*>(this)->CallScriptCheckProcHandlers(aurApp, eventInfo);
    if (!check)
        return 0;

    // At least one effect has to pass checks to proc aura
    uint32 procEffectMask = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (aurApp->HasEffect(i))
            if (GetEffect(i)->CheckEffectProc(aurApp, eventInfo))
                procEffectMask |= (1 << i);

    if (!procEffectMask)
        return 0;

    /// @todo
    // do allow additional requirements for procs
    // this is needed because this is the last moment in which you can prevent aura charge drop on proc
    // and possibly a way to prevent default checks (if there're going to be any)

    // Aura added by spell can't trigger from self (prevent drop charges/do triggers)
    // But except periodic and kill triggers (can triggered from self)
    if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
        if (spellInfo->Id == GetId() && !(eventInfo.GetTypeMask() & (PROC_FLAG_TAKEN_PERIODIC | PROC_FLAG_KILL)))
            return 0;

    // Check if current equipment meets aura requirements
    // do that only for passive spells
    /// @todo this needs to be unified for all kinds of auras
    Unit* target = aurApp->GetTarget();
    if (IsPassive() && target->GetTypeId() == TYPEID_PLAYER)
    {
        if (GetSpellInfo()->EquippedItemClass == ITEM_CLASS_WEAPON)
        {
            if (target->ToPlayer()->IsInFeralForm())
                return 0;

            if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
            {
                WeaponAttackType attType = damageInfo->GetAttackType();
                Item* item = nullptr;
                if (attType == BASE_ATTACK || attType == RANGED_ATTACK)
                    item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                else if (attType == OFF_ATTACK)
                    item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

                if (!item || item->IsBroken() || item->GetTemplate()->GetClass() != ITEM_CLASS_WEAPON || !((1 << item->GetTemplate()->GetSubClass()) & GetSpellInfo()->EquippedItemSubClassMask))
                    return 0;
            }
        }
        else if (GetSpellInfo()->EquippedItemClass == ITEM_CLASS_ARMOR)
        {
            // Check if player is wearing shield
            Item* item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            if (!item || item->IsBroken() || item->GetTemplate()->GetClass() != ITEM_CLASS_ARMOR || !((1 << item->GetTemplate()->GetSubClass()) & GetSpellInfo()->EquippedItemSubClassMask))
                return 0;
        }
    }

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
            modOwner->ApplySpellMod(GetId(), SPELLMOD_CHANCE_OF_SUCCESS, chance);
    }
    return chance;
}

void Aura::TriggerProcOnEvent(uint32 procEffectMask, AuraApplication* aurApp, ProcEventInfo& eventInfo)
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

    // Remove aura if we've used last charge to proc
    if (IsUsingCharges() && !GetCharges())
        Remove();
}

float Aura::CalcPPMProcChance(Unit* actor) const
{
    using FSeconds = std::chrono::duration<float, Seconds::period>;

    // Formula see http://us.battle.net/wow/en/forum/topic/8197741003#1
    float ppm = m_spellInfo->CalcProcPPM(actor, m_castItemLevel);
    float averageProcInterval = 60.0f / ppm;

    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    float secondsSinceLastAttempt = std::min(std::chrono::duration_cast<FSeconds>(currentTime - m_lastProcAttemptTime).count(), 10.0f);
    float secondsSinceLastProc = std::min(std::chrono::duration_cast<FSeconds>(currentTime - m_lastProcSuccessTime).count(), 1000.0f);

    float chance = std::max(1.0f, 1.0f + ((secondsSinceLastProc / averageProcInterval - 1.5f) * 3.0f)) * ppm * secondsSinceLastAttempt / 60.0f;
    RoundToInterval(chance, 0.0f, 1.0f);
    return chance * 100.0f;
}

void Aura::_DeleteRemovedApplications()
{
    while (!m_removedApplications.empty())
    {
        delete m_removedApplications.front();
        m_removedApplications.pop_front();
    }
}

void Aura::LoadScripts()
{
    sScriptMgr->CreateAuraScripts(m_spellInfo->Id, m_loadedScripts, this);
    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
    {
        TC_LOG_DEBUG("spells", "Aura::LoadScripts: Script `%s` for aura `%u` is loaded now", (*itr)->_GetScriptName()->c_str(), m_spellInfo->Id);
        (*itr)->Register();
    }
}

bool Aura::CallScriptCheckAreaTargetHandlers(Unit* target)
{
    bool result = true;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_AREA_TARGET);
        auto hookItrEnd = (*scritr)->DoCheckAreaTarget.end(), hookItr = (*scritr)->DoCheckAreaTarget.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            result &= hookItr->Call(*scritr, target);

        (*scritr)->_FinishScriptCall();
    }
    return result;
}

void Aura::CallScriptDispel(DispelInfo* dispelInfo)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_DISPEL);
        auto hookItrEnd = (*scritr)->OnDispel.end(), hookItr = (*scritr)->OnDispel.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(*scritr, dispelInfo);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptAfterDispel(DispelInfo* dispelInfo)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_AFTER_DISPEL);
        auto hookItrEnd = (*scritr)->AfterDispel.end(), hookItr = (*scritr)->AfterDispel.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(*scritr, dispelInfo);

        (*scritr)->_FinishScriptCall();
    }
}

bool Aura::CallScriptEffectApplyHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_APPLY, aurApp);
        auto effEndItr = (*scritr)->OnEffectApply.end(), effItr = (*scritr)->OnEffectApply.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, mode);

        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();

        (*scritr)->_FinishScriptCall();
    }

    return preventDefault;
}

bool Aura::CallScriptEffectRemoveHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_REMOVE, aurApp);
        auto effEndItr = (*scritr)->OnEffectRemove.end(), effItr = (*scritr)->OnEffectRemove.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, mode);

        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();

        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

void Aura::CallScriptAfterEffectApplyHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_APPLY, aurApp);
        auto effEndItr = (*scritr)->AfterEffectApply.end(), effItr = (*scritr)->AfterEffectApply.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, mode);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptAfterEffectRemoveHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, AuraEffectHandleModes mode)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_REMOVE, aurApp);
        auto effEndItr = (*scritr)->AfterEffectRemove.end(), effItr = (*scritr)->AfterEffectRemove.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, mode);

        (*scritr)->_FinishScriptCall();
    }
}

bool Aura::CallScriptEffectPeriodicHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp)
{
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_PERIODIC, aurApp);
        auto effEndItr = (*scritr)->OnEffectPeriodic.end(), effItr = (*scritr)->OnEffectPeriodic.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff);

        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();

        (*scritr)->_FinishScriptCall();
    }

    return preventDefault;
}

void Aura::CallScriptEffectUpdatePeriodicHandlers(AuraEffect* aurEff)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_UPDATE_PERIODIC);
        auto effEndItr = (*scritr)->OnEffectUpdatePeriodic.end(), effItr = (*scritr)->OnEffectUpdatePeriodic.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcAmountHandlers(AuraEffect const* aurEff, int32 & amount, bool & canBeRecalculated)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_AMOUNT);
        auto effEndItr = (*scritr)->DoEffectCalcAmount.end(), effItr = (*scritr)->DoEffectCalcAmount.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, amount, canBeRecalculated);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcPeriodicHandlers(AuraEffect const* aurEff, bool & isPeriodic, int32 & amplitude)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_PERIODIC);
        auto effEndItr = (*scritr)->DoEffectCalcPeriodic.end(), effItr = (*scritr)->DoEffectCalcPeriodic.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, isPeriodic, amplitude);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcSpellModHandlers(AuraEffect const* aurEff, SpellModifier* & spellMod)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_SPELLMOD);
        auto effEndItr = (*scritr)->DoEffectCalcSpellMod.end(), effItr = (*scritr)->DoEffectCalcSpellMod.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, spellMod);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount, bool& defaultPrevented)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_ABSORB, aurApp);
        auto effEndItr = (*scritr)->OnEffectAbsorb.end(), effItr = (*scritr)->OnEffectAbsorb.begin();
        for (; effItr != effEndItr; ++effItr)

            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);

        if (!defaultPrevented)
            defaultPrevented = (*scritr)->_IsDefaultActionPrevented();

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB, aurApp);
        auto effEndItr = (*scritr)->AfterEffectAbsorb.end(), effItr = (*scritr)->AfterEffectAbsorb.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount, bool & /*defaultPrevented*/)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_MANASHIELD, aurApp);
        auto effEndItr = (*scritr)->OnEffectManaShield.end(), effItr = (*scritr)->OnEffectManaShield.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD, aurApp);
        auto effEndItr = (*scritr)->AfterEffectManaShield.end(), effItr = (*scritr)->AfterEffectManaShield.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectSplitHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo & dmgInfo, uint32 & splitAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_SPLIT, aurApp);
        auto effEndItr = (*scritr)->OnEffectSplit.end(), effItr = (*scritr)->OnEffectSplit.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, splitAmount);

        (*scritr)->_FinishScriptCall();
    }
}

bool Aura::CallScriptCheckProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool result = true;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_PROC, aurApp);
        auto hookItrEnd = (*scritr)->DoCheckProc.end(), hookItr = (*scritr)->DoCheckProc.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            result &= hookItr->Call(*scritr, eventInfo);

        (*scritr)->_FinishScriptCall();
    }

    return result;
}

bool Aura::CallScriptPrepareProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool prepare = true;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_PREPARE_PROC, aurApp);
        auto effEndItr = (*scritr)->DoPrepareProc.end(), effItr = (*scritr)->DoPrepareProc.begin();
        for (; effItr != effEndItr; ++effItr)
            effItr->Call(*scritr, eventInfo);

        if (prepare)
            prepare = !(*scritr)->_IsDefaultActionPrevented();

        (*scritr)->_FinishScriptCall();
    }

    return prepare;
}

bool Aura::CallScriptProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool handled = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_PROC, aurApp);
        auto hookItrEnd = (*scritr)->OnProc.end(), hookItr = (*scritr)->OnProc.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(*scritr, eventInfo);

        handled |= (*scritr)->_IsDefaultActionPrevented();
        (*scritr)->_FinishScriptCall();
    }

    return handled;
}

void Aura::CallScriptAfterProcHandlers(AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_AFTER_PROC, aurApp);
        auto hookItrEnd = (*scritr)->AfterProc.end(), hookItr = (*scritr)->AfterProc.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(*scritr, eventInfo);

        (*scritr)->_FinishScriptCall();
    }
}

bool Aura::CallScriptCheckEffectProcHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool result = true;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_EFFECT_PROC, aurApp);
        auto hookItrEnd = (*scritr)->DoCheckEffectProc.end(), hookItr = (*scritr)->DoCheckEffectProc.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            if (hookItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                result &= hookItr->Call(*scritr, aurEff, eventInfo);

        (*scritr)->_FinishScriptCall();
    }

    return result;
}

bool Aura::CallScriptEffectProcHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_PROC, aurApp);
        auto effEndItr = (*scritr)->OnEffectProc.end(), effItr = (*scritr)->OnEffectProc.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, eventInfo);

        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();

        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

void Aura::CallScriptAfterEffectProcHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, ProcEventInfo& eventInfo)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_PROC, aurApp);
        auto effEndItr = (*scritr)->AfterEffectProc.end(), effItr = (*scritr)->AfterEffectProc.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, eventInfo);

        (*scritr)->_FinishScriptCall();
    }
}

UnitAura::UnitAura(SpellInfo const* spellproto, ObjectGuid castId, uint32 effMask, WorldObject* owner, Unit* caster, int32 *baseAmount, Item* castItem, ObjectGuid casterGUID, ObjectGuid castItemGuid, int32 castItemLevel)
    : Aura(spellproto, castId, owner, caster, castItem, casterGUID, castItemGuid, castItemLevel)
{
    m_AuraDRGroup = DIMINISHING_NONE;
    LoadScripts();
    _InitEffects(effMask, caster, baseAmount);
    GetUnitOwner()->_AddAura(this, caster);
}

void UnitAura::_ApplyForTarget(Unit* target, Unit* caster, AuraApplication * aurApp)
{
    Aura::_ApplyForTarget(target, caster, aurApp);

    // register aura diminishing on apply
    if (DiminishingGroup group = GetDiminishGroup())
        target->ApplyDiminishingAura(group, true);
}

void UnitAura::_UnapplyForTarget(Unit* target, Unit* caster, AuraApplication * aurApp)
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
    for (SpellEffectInfo const* effect : GetSpellEffectInfos())
    {
        if (!effect || !HasEffect(effect->EffectIndex))
            continue;

        std::deque<Unit*> units;
        // non-area aura
        if (effect->Effect == SPELL_EFFECT_APPLY_AURA)
        {
            units.push_back(GetUnitOwner());
        }
        else
        {
            float radius = effect->CalcRadius(caster);

            if (!GetUnitOwner()->HasUnitState(UNIT_STATE_ISOLATED))
            {
                switch (effect->Effect)
                {
                    case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                    case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
                    {
                        units.push_back(GetUnitOwner());
                        Trinity::AnyGroupedUnitInObjectRangeCheck u_check(GetUnitOwner(), GetUnitOwner(), radius, effect->Effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID, m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS));
                        Trinity::UnitListSearcher<Trinity::AnyGroupedUnitInObjectRangeCheck> searcher(GetUnitOwner(), units, u_check);
                        Cell::VisitAllObjects(GetUnitOwner(), searcher, radius);
                        break;
                    }
                    case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
                    {
                        units.push_back(GetUnitOwner());
                        Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(GetUnitOwner(), GetUnitOwner(), radius, m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS));
                        Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(GetUnitOwner(), units, u_check);
                        Cell::VisitAllObjects(GetUnitOwner(), searcher, radius);
                        break;
                    }
                    case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
                    {
                        Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(GetUnitOwner(), GetUnitOwner(), radius, m_spellInfo); // No GetCharmer in searcher
                        Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(GetUnitOwner(), units, u_check);
                        Cell::VisitAllObjects(GetUnitOwner(), searcher, radius);
                        break;
                    }
                    case SPELL_EFFECT_APPLY_AREA_AURA_PET:
                        units.push_back(GetUnitOwner());
                        // no break
                    case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
                    {
                        if (Unit* owner = GetUnitOwner()->GetCharmerOrOwner())
                            if (GetUnitOwner()->IsWithinDistInMap(owner, radius))
                                units.push_back(owner);
                        break;
                    }
                }
            }
        }

        for (Unit* unit : units)
        {
            auto itr = targets.find(unit);
            if (itr != targets.end())
                itr->second |= 1 << effect->EffectIndex;
            else
                targets[unit] = 1 << effect->EffectIndex;
        }
    }
}

DynObjAura::DynObjAura(SpellInfo const* spellproto, ObjectGuid castId, uint32 effMask, WorldObject* owner, Unit* caster, int32 *baseAmount, Item* castItem, ObjectGuid casterGUID, ObjectGuid castItemGuid, int32 castItemLevel)
    : Aura(spellproto, castId, owner, caster, castItem, casterGUID, castItemGuid, castItemLevel)
{
    LoadScripts();
    ASSERT(GetDynobjOwner());
    ASSERT(GetDynobjOwner()->IsInWorld());
    ASSERT(GetDynobjOwner()->GetMap() == caster->GetMap());
    _InitEffects(effMask, caster, baseAmount);
    GetDynobjOwner()->SetAura(this);
}

bool ChargeDropEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    // _base is always valid (look in Aura::_Remove())
    _base->ModChargesDelayed(-1, _mode);
    return true;
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

    for (SpellEffectInfo const* effect : GetSpellEffectInfos())
    {
        if (!effect || !HasEffect(effect->EffectIndex))
            continue;

        std::deque<Unit*> units;
        if (effect->TargetB.GetTarget() == TARGET_DEST_DYNOBJ_ALLY
            || effect->TargetB.GetTarget() == TARGET_UNIT_DEST_AREA_ALLY)
        {
            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(GetDynobjOwner(), dynObjOwnerCaster, radius, m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS));
            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(GetDynobjOwner(), units, u_check);
            Cell::VisitAllObjects(GetDynobjOwner(), searcher, radius);
        }
        else
        {
            Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(GetDynobjOwner(), dynObjOwnerCaster, radius);
            Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(GetDynobjOwner(), units, u_check);
            Cell::VisitAllObjects(GetDynobjOwner(), searcher, radius);
        }

        for (Unit* unit : units)
        {
            auto itr = targets.find(unit);
            if (itr != targets.end())
                itr->second |= 1 << effect->EffectIndex;
            else
                targets[unit] = 1 << effect->EffectIndex;
        }
    }
}
