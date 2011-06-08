/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "Opcodes.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Unit.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "DynamicObject.h"
#include "ObjectAccessor.h"
#include "Util.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

AuraApplication::AuraApplication(Unit * target, Unit * caster, Aura * aura, uint8 effMask):
m_target(target), m_base(aura), m_slot(MAX_AURAS), m_flags(AFLAG_NONE),
m_effectsToApply(effMask), m_removeMode(AURA_REMOVE_NONE), m_needClientUpdate(false)
{
    ASSERT(GetTarget() && GetBase());

    if (GetBase()->CanBeSentToClient())
    {
        // Try find slot for aura
        uint8 slot = MAX_AURAS;
        // Lookup for auras already applied from spell
        if (AuraApplication * foundAura = GetTarget()->GetAuraApplication(GetBase()->GetId(), GetBase()->GetCasterGUID(), GetBase()->GetCastItemGUID()))
        {
            // allow use single slot only by auras from same caster
            slot = foundAura->GetSlot();
        }
        else
        {
            Unit::VisibleAuraMap const * visibleAuras = GetTarget()->GetVisibleAuras();
            // lookup for free slots in units visibleAuras
            Unit::VisibleAuraMap::const_iterator itr = visibleAuras->find(0);
            for (uint32 freeSlot = 0; freeSlot < MAX_AURAS; ++itr , ++freeSlot)
            {
                if (itr == visibleAuras->end() || itr->first != freeSlot)
                {
                    slot = freeSlot;
                    break;
                }
            }
        }

        // Register Visible Aura
        if (slot < MAX_AURAS)
        {
            m_slot = slot;
            GetTarget()->SetVisibleAura(slot, this);
            SetNeedClientUpdate();
            sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Aura: %u Effect: %d put to unit visible auras slot: %u", GetBase()->GetId(), GetEffectMask(), slot);
        }
        else
            sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Aura: %u Effect: %d could not find empty unit visible slot", GetBase()->GetId(), GetEffectMask());
    }

    _InitFlags(caster, effMask);
}

void AuraApplication::_Remove()
{
    uint8 slot = GetSlot();

    if (slot >= MAX_AURAS)
        return;

    if (AuraApplication * foundAura = m_target->GetAuraApplication(GetBase()->GetId(), GetBase()->GetCasterGUID(), GetBase()->GetCastItemGUID()))
    {
        // Reuse visible aura slot by aura which is still applied - prevent storing dead pointers
        if (slot == foundAura->GetSlot())
        {
            if (GetTarget()->GetVisibleAura(slot) == this)
            {
                GetTarget()->SetVisibleAura(slot, foundAura);
                foundAura->SetNeedClientUpdate();
            }
            // set not valid slot for aura - prevent removing other visible aura
            slot = MAX_AURAS;
        }
    }

    // update for out of range group members
    if (slot < MAX_AURAS)
    {
        GetTarget()->RemoveVisibleAura(slot);
        ClientUpdate(true);
    }
}

void AuraApplication::_InitFlags(Unit * caster, uint8 effMask)
{
    // mark as selfcasted if needed
    m_flags |= (GetBase()->GetCasterGUID() == GetTarget()->GetGUID()) ? AFLAG_CASTER : AFLAG_NONE;

    // aura is casted by self or an enemy
    // one negative effect and we know aura is negative
    if (IsSelfcasted() || !caster || !caster->IsFriendlyTo(GetTarget()))
    {
        bool negativeFound = false;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (((1<<i) & effMask) && !IsPositiveEffect(GetBase()->GetId(), i))
            {
                negativeFound = true;
                break;
            }
        }
        m_flags |= negativeFound ? AFLAG_NEGATIVE : AFLAG_POSITIVE;
    }
    // aura is casted by friend
    // one positive effect and we know aura is positive
    else
    {
        bool positiveFound = false;
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (((1<<i) & effMask) && IsPositiveEffect(GetBase()->GetId(), i))
            {
                positiveFound = true;
                break;
            }
        }
        m_flags |= positiveFound ? AFLAG_POSITIVE : AFLAG_NEGATIVE;
    }
}

void AuraApplication::_HandleEffect(uint8 effIndex, bool apply)
{
    AuraEffect * aurEff = GetBase()->GetEffect(effIndex);
    ASSERT(aurEff);
    ASSERT(HasEffect(effIndex) == (!apply));
    ASSERT((1<<effIndex) & m_effectsToApply);
    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "AuraApplication::_HandleEffect: %u, apply: %u: amount: %u", aurEff->GetAuraType(), apply, aurEff->GetAmount());

    if (apply)
    {
        ASSERT(!(m_flags & (1<<effIndex)));
        m_flags |= 1<<effIndex;
        aurEff->HandleEffect(this, AURA_EFFECT_HANDLE_REAL, true);
    }
    else
    {
        ASSERT(m_flags & (1<<effIndex));
        m_flags &= ~(1<<effIndex);
        aurEff->HandleEffect(this, AURA_EFFECT_HANDLE_REAL, false);

        // Remove all triggered by aura spells vs unlimited duration
        aurEff->CleanupTriggeredSpells(GetTarget());
    }
    SetNeedClientUpdate();
}

void AuraApplication::BuildUpdatePacket(ByteBuffer& data, bool remove) const
{
    data << uint8(m_slot);

    if (remove)
    {
        ASSERT(!m_target->GetVisibleAura(m_slot));
        data << uint32(0);
        return;
    }
    ASSERT(m_target->GetVisibleAura(m_slot));

    Aura const * aura = GetBase();
    data << uint32(aura->GetId());
    uint32 flags = m_flags;
    if (aura->GetMaxDuration() > 0 && !(aura->GetSpellProto()->AttributesEx5 & SPELL_ATTR5_HIDE_DURATION))
        flags |= AFLAG_DURATION;
    data << uint8(flags);
    data << uint8(aura->GetCasterLevel());
    data << uint8(aura->GetStackAmount() > 1 ? aura->GetStackAmount() : (aura->GetCharges()) ? aura->GetCharges() : 1);

    if (!(flags & AFLAG_CASTER))
        data.appendPackGUID(aura->GetCasterGUID());

    if (flags & AFLAG_DURATION)
    {
        data << uint32(aura->GetMaxDuration());
        data << uint32(aura->GetDuration());
    }
}

void AuraApplication::ClientUpdate(bool remove)
{
    m_needClientUpdate = false;

    WorldPacket data(SMSG_AURA_UPDATE);
    data.append(GetTarget()->GetPackGUID());
    BuildUpdatePacket(data, remove);

    m_target->SendMessageToSet(&data, true);
}

uint8 Aura::BuildEffectMaskForOwner(SpellEntry const* spellProto, uint8 avalibleEffectMask, WorldObject* owner)
{
    ASSERT(spellProto);
    ASSERT(owner);
    uint8 effMask = 0;
    switch(owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
            for (uint8 i = 0; i< MAX_SPELL_EFFECTS; ++i)
            {
                if (IsUnitOwnedAuraEffect(spellProto->Effect[i]))
                    effMask |= 1 << i;
            }
            break;
        case TYPEID_DYNAMICOBJECT:
            for (uint8 i = 0; i< MAX_SPELL_EFFECTS; ++i)
            {
                if (spellProto->Effect[i] == SPELL_EFFECT_PERSISTENT_AREA_AURA)
                    effMask |= 1 << i;
            }
            break;
        default:
            break;
    }
    return effMask & avalibleEffectMask;
}

Aura* Aura::TryRefreshStackOrCreate(SpellEntry const* spellproto, uint8 tryEffMask, WorldObject* owner, Unit* caster, int32* baseAmount /*= NULL*/, Item* castItem /*= NULL*/, uint64 casterGUID /*= 0*/, bool* refresh /*= NULL*/)
{
    ASSERT(spellproto);
    ASSERT(owner);
    ASSERT(caster || casterGUID);
    ASSERT(tryEffMask <= MAX_EFFECT_MASK);
    if (refresh)
        *refresh = false;
    uint8 effMask = Aura::BuildEffectMaskForOwner(spellproto, tryEffMask, owner);
    if (!effMask)
        return NULL;
    if (Aura* foundAura = owner->ToUnit()->_TryStackingOrRefreshingExistingAura(spellproto, effMask, caster, baseAmount, castItem, casterGUID))
    {
        // we've here aura, which script triggered removal after modding stack amount
        // check the state here, so we won't create new Aura object
        if (foundAura->IsRemoved())
            return NULL;

        if (refresh)
            *refresh = true;
        return foundAura;
    }
    else
        return Create(spellproto, effMask, owner, caster, baseAmount, castItem, casterGUID);
}

Aura* Aura::TryCreate(SpellEntry const* spellproto, uint8 tryEffMask, WorldObject* owner, Unit* caster, int32* baseAmount /*= NULL*/, Item* castItem /*= NULL*/, uint64 casterGUID /*= 0*/)
{
    ASSERT(spellproto);
    ASSERT(owner);
    ASSERT(caster || casterGUID);
    ASSERT(tryEffMask <= MAX_EFFECT_MASK);
    uint8 effMask = Aura::BuildEffectMaskForOwner(spellproto, tryEffMask, owner);
    if (!effMask)
        return NULL;
    return Create(spellproto, effMask, owner, caster, baseAmount, castItem, casterGUID);
}

Aura* Aura::Create(SpellEntry const* spellproto, uint8 effMask, WorldObject* owner, Unit* caster, int32* baseAmount, Item* castItem, uint64 casterGUID)
{
    ASSERT(effMask);
    ASSERT(spellproto);
    ASSERT(owner);
    ASSERT(caster || casterGUID);
    ASSERT(effMask <= MAX_EFFECT_MASK);
    // try to get caster of aura
    if (casterGUID)
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
            // owner not in world so don't allow to own not self casted single target auras
            if (casterGUID != owner->GetGUID() && IsSingleTargetSpell(spellproto))
                return NULL;

    Aura* aura = NULL;
    switch (owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
            aura = new UnitAura(spellproto, effMask, owner, caster, baseAmount, castItem, casterGUID);
            break;
        case TYPEID_DYNAMICOBJECT:
            aura = new DynObjAura(spellproto, effMask, owner, caster, baseAmount, castItem, casterGUID);
            break;
        default:
            ASSERT(false);
            return NULL;
    }
    // aura can be removed in Unit::_AddAura call
    if (aura->IsRemoved())
        return NULL;
    return aura;
}

Aura::Aura(SpellEntry const* spellproto, WorldObject * owner, Unit * caster, Item * castItem, uint64 casterGUID) :
m_spellProto(spellproto), m_casterGuid(casterGUID ? casterGUID : caster->GetGUID()),
m_castItemGuid(castItem ? castItem->GetGUID() : 0), m_applyTime(time(NULL)),
m_owner(owner), m_timeCla(0), m_updateTargetMapInterval(0),
m_casterLevel(caster ? caster->getLevel() : m_spellProto->spellLevel), m_procCharges(0), m_stackAmount(1),
m_isRemoved(false), m_isSingleTarget(false)
{
    if (m_spellProto->manaPerSecond || m_spellProto->manaPerSecondPerLevel)
        m_timeCla = 1 * IN_MILLISECONDS;

    m_maxDuration = CalcMaxDuration(caster);
    m_duration = m_maxDuration;
    m_procCharges = CalcMaxCharges(caster);
}

void Aura::_InitEffects(uint8 effMask, Unit * caster, int32 *baseAmount)
{
    // shouldn't be in constructor - functions in AuraEffect::AuraEffect use polymorphism
    for (uint8 i=0 ; i<MAX_SPELL_EFFECTS; ++i)
    {
        if (effMask & (uint8(1) << i))
            m_effects[i] = new AuraEffect(this, i, baseAmount ? baseAmount + i : NULL, caster);
        else
            m_effects[i] = NULL;
    }
}

Aura::~Aura()
{
    // unload scripts
    while(!m_loadedScripts.empty())
    {
        std::list<AuraScript *>::iterator itr = m_loadedScripts.begin();
        (*itr)->_Unload();
        delete (*itr);
        m_loadedScripts.erase(itr);
    }

    // free effects memory
    for (uint8 i = 0 ; i < MAX_SPELL_EFFECTS; ++i)
         delete m_effects[i];

    ASSERT(m_applications.empty());
    _DeleteRemovedApplications();
}

Unit* Aura::GetCaster() const
{
    if (GetOwner()->GetGUID() == GetCasterGUID())
        return GetUnitOwner();
    if (AuraApplication const * aurApp = GetApplicationOfTarget(GetCasterGUID()))
        return aurApp->GetTarget();

    return ObjectAccessor::GetUnit(*GetOwner(), GetCasterGUID());
}

AuraObjectType Aura::GetType() const
{
    return (m_owner->GetTypeId() == TYPEID_DYNAMICOBJECT) ? DYNOBJ_AURA_TYPE : UNIT_AURA_TYPE;
}

void Aura::_ApplyForTarget(Unit * target, Unit * caster, AuraApplication * auraApp)
{
    ASSERT(target);
    ASSERT(auraApp);
    // aura mustn't be already applied on target
    ASSERT (!IsAppliedOnTarget(target->GetGUID()) && "Aura::_ApplyForTarget: aura musn't be already applied on target");

    m_applications[target->GetGUID()] = auraApp;

    // set infinity cooldown state for spells
    if (caster && caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_spellProto->Attributes & SPELL_ATTR0_DISABLED_WHILE_ACTIVE)
        {
            Item* castItem = m_castItemGuid ? caster->ToPlayer()->GetItemByGuid(m_castItemGuid) : NULL;
            caster->ToPlayer()->AddSpellAndCategoryCooldowns(m_spellProto, castItem ? castItem->GetEntry() : 0, NULL, true);
        }
    }
}

void Aura::_UnapplyForTarget(Unit * target, Unit * caster, AuraApplication * auraApp)
{
    ASSERT(target);
    ASSERT(auraApp->GetRemoveMode());
    ASSERT(auraApp);

    ApplicationMap::iterator itr = m_applications.find(target->GetGUID());

    // TODO: Figure out why this happens
    if (itr == m_applications.end())
    {
        sLog->outError("Aura::_UnapplyForTarget, target:%u, caster:%u, spell:%u was not found in owners application map!",
        target->GetGUIDLow(), caster->GetGUIDLow(), auraApp->GetBase()->GetSpellProto()->Id);
        ASSERT(false);
    }

    // aura has to be already applied
    ASSERT(itr->second == auraApp);
    m_applications.erase(itr);

    m_removedApplications.push_back(auraApp);

    // reset cooldown state for spells
    if (caster && caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (GetSpellProto()->Attributes & SPELL_ATTR0_DISABLED_WHILE_ACTIVE)
            // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existed cases)
            caster->ToPlayer()->SendCooldownEvent(GetSpellProto());
    }
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
        AuraApplication * aurApp =  appItr->second;
        Unit * target = aurApp->GetTarget();
        target->_UnapplyAura(aurApp, removeMode);
        appItr = m_applications.begin();
    }
}

void Aura::UpdateTargetMap(Unit * caster, bool apply)
{
    if (IsRemoved())
        return;

    m_updateTargetMapInterval = UPDATE_TARGET_MAP_INTERVAL;

    // fill up to date target list
    //       target, effMask
    std::map<Unit *, uint8> targets;

    FillTargetMap(targets, caster);

    UnitList targetsToRemove;

    // mark all auras as ready to remove
    for (ApplicationMap::iterator appIter = m_applications.begin(); appIter != m_applications.end();++appIter)
    {
        std::map<Unit *, uint8>::iterator existing = targets.find(appIter->second->GetTarget());
        // not found in current area - remove the aura
        if (existing == targets.end())
            targetsToRemove.push_back(appIter->second->GetTarget());
        else
        {
            // needs readding - remove now, will be applied in next update cycle
            // (dbcs do not have auras which apply on same type of targets but have different radius, so this is not really needed)
            if (appIter->second->GetEffectMask() != existing->second || !CanBeAppliedOn(existing->first))
                targetsToRemove.push_back(appIter->second->GetTarget());
            // nothing todo - aura already applied
            // remove from auras to register list
            targets.erase(existing);
        }
    }

    // register auras for units
    for (std::map<Unit *, uint8>::iterator itr = targets.begin(); itr!= targets.end();)
    {
        // aura mustn't be already applied on target
        if (AuraApplication * aurApp = GetApplicationOfTarget(itr->first->GetGUID()))
        {
            // the core created 2 different units with same guid
            // this is a major failue, which i can't fix right now
            // let's remove one unit from aura list
            // this may cause area aura "bouncing" between 2 units after each update
            // but because we know the reason of a crash we can remove the assertion for now
            if (aurApp->GetTarget() != itr->first)
            {
                // remove from auras to register list
                targets.erase(itr++);
                continue;
            }
            else
            {
                // ok, we have one unit twice in target map (impossible, but...)
                ASSERT(false);
            }
        }

        bool addUnit = true;
        // check target immunities
        if (itr->first->IsImmunedToSpell(GetSpellProto())
            || !CanBeAppliedOn(itr->first))
            addUnit = false;

        if (addUnit)
        {
            // persistent area aura does not hit flying targets
            if (GetType() == DYNOBJ_AURA_TYPE)
            {
                if (itr->first->isInFlight())
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
                        Aura const * aura = iter->second->GetBase();
                        if (!sSpellMgr->CanAurasStack(this, aura, aura->GetCasterGUID() == GetCasterGUID()))
                        {
                            addUnit = false;
                            break;
                        }
                    }
                }
            }
        }
        if (!addUnit)
            targets.erase(itr++);
        else
        {
            // owner has to be in world, or effect has to be applied to self
            ASSERT((!GetOwner()->IsInWorld() && GetOwner() == itr->first) || GetOwner()->IsInMap(itr->first));
            itr->first->_CreateAuraApplication(this, itr->second);
            ++itr;
        }
    }

    // remove auras from units no longer needing them
    for (UnitList::iterator itr = targetsToRemove.begin(); itr != targetsToRemove.end();++itr)
        if (AuraApplication * aurApp = GetApplicationOfTarget((*itr)->GetGUID()))
            (*itr)->_UnapplyAura(aurApp, AURA_REMOVE_BY_DEFAULT);

    if (!apply)
        return;

    // apply aura effects for units
    for (std::map<Unit *, uint8>::iterator itr = targets.begin(); itr!= targets.end();++itr)
    {
        if (AuraApplication * aurApp = GetApplicationOfTarget(itr->first->GetGUID()))
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
        if ((appIter->second->GetEffectsToApply() & (1<<effIndex)) && !appIter->second->HasEffect(effIndex))
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
void Aura::UpdateOwner(uint32 diff, WorldObject * owner)
{
    ASSERT(owner == m_owner);

    Unit * caster = GetCaster();
    // Apply spellmods for channeled auras
    // used for example when triggered spell of spell:10 is modded
    Spell * modSpell = NULL;
    Player * modOwner = NULL;
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
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_effects[i])
            m_effects[i]->Update(diff, caster);

    // remove spellmods after effects update
    if (modSpell)
        modOwner->SetSpellModTakingSpell(modSpell, false);

    _DeleteRemovedApplications();
}

void Aura::Update(uint32 diff, Unit * caster)
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
                if (int32 manaPerSecond = m_spellProto->manaPerSecond + m_spellProto->manaPerSecondPerLevel * caster->getLevel())
                {
                    m_timeCla += 1000 - diff;

                    Powers powertype = Powers(m_spellProto->powerType);
                    if (powertype == POWER_HEALTH)
                    {
                        if (int32(caster->GetHealth()) > manaPerSecond)
                            caster->ModifyHealth(-manaPerSecond);
                        else
                        {
                            Remove();
                            return;
                        }
                    }
                    else
                    {
                        if (int32(caster->GetPower(powertype)) >= manaPerSecond)
                            caster->ModifyPower(powertype, -manaPerSecond);
                        else
                        {
                            Remove();
                            return;
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
        maxDuration = caster->CalcSpellDuration(m_spellProto);
    }
    else
        maxDuration = GetSpellDuration(m_spellProto);

    if (IsPassive() && m_spellProto->DurationIndex == 0)
        maxDuration = -1;

    if (!IsPermanent() && modOwner)
        modOwner->ApplySpellMod(GetId(), SPELLMOD_DURATION, maxDuration);
    return maxDuration;
}

void Aura::SetDuration(int32 duration, bool withMods)
{
    if (withMods)
    {
        if (Unit * caster = GetCaster())
            if (Player * modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetId(), SPELLMOD_DURATION, duration);
    }
    m_duration = duration;
    SetNeedClientUpdateForTargets();
}

void Aura::RefreshDuration()
{
    SetDuration(GetMaxDuration());

    if (m_spellProto->manaPerSecond || m_spellProto->manaPerSecondPerLevel)
        m_timeCla = 1 * IN_MILLISECONDS;
}

void Aura::SetCharges(uint8 charges)
{
    if (m_procCharges == charges)
        return;
    m_procCharges = charges;
    SetNeedClientUpdateForTargets();
}

uint8 Aura::CalcMaxCharges(Unit * caster) const
{
    uint8 maxProcCharges = m_spellProto->procCharges;
    
    if (caster)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetId(), SPELLMOD_CHARGES, maxProcCharges);
    return maxProcCharges;
}

bool Aura::ModCharges(int32 num, AuraRemoveMode removeMode)
{
    if (m_procCharges)
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

void Aura::SetStackAmount(uint8 stackAmount)
{
    m_stackAmount = stackAmount;
    Unit * caster = GetCaster();
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (HasEffect(i))
            m_effects[i]->ChangeAmount(m_effects[i]->CalculateAmount(caster), false, true);
    SetNeedClientUpdateForTargets();
}

bool Aura::ModStackAmount(int32 num, AuraRemoveMode removeMode)
{
    int32 stackAmount = m_stackAmount + num;

    // limit the stack amount (only on stack increase, stack amount may be changed manually)
    if ((num > 0) && (stackAmount > int32(m_spellProto->StackAmount)))
    {
        // not stackable aura - set stack amount to 1
        if(!m_spellProto->StackAmount)
            stackAmount = 1;
        else
            stackAmount = m_spellProto->StackAmount;
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
        RefreshDuration();
    SetNeedClientUpdateForTargets();
    return false;
}

bool Aura::IsPassive() const
{
    return IsPassiveSpell(GetSpellProto());
}

bool Aura::IsDeathPersistent() const
{
    return IsDeathPersistentSpell(GetSpellProto());
}

bool Aura::CanBeSaved() const
{
    if (IsPassive())
        return false;

    if (GetCasterGUID() != GetOwner()->GetGUID())
        if (IsSingleTargetSpell(GetSpellProto()))
            return false;

    // Can't be saved - aura handler relies on calculated amount and changes it
    if (HasEffectType(SPELL_AURA_CONVERT_RUNE))
        return false;

    // No point in saving this, since the stable dialog can't be open on aura load anyway.
    if (HasEffectType(SPELL_AURA_OPEN_STABLE))
        return false;

    // Incanter's Absorbtion - considering the minimal duration and problems with aura stacking
    // we skip saving this aura
    if (GetId() == 44413)
        return false;

    return true;
}

bool Aura::CanBeSentToClient() const
{
    return !IsPassive() || HasAreaAuraEffect(GetSpellProto()) || HasEffectType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
}

void Aura::UnregisterSingleTarget()
{
    ASSERT(m_isSingleTarget);
    Unit * caster = GetCaster();
    // TODO: find a better way to do this.
    if (!caster)
        caster = ObjectAccessor::GetObjectInOrOutOfWorld(GetCasterGUID(), (Unit*)NULL);
    ASSERT(caster);
    caster->GetSingleCastAuras().remove(this);
    SetIsSingleTarget(false);
}

void Aura::SetLoadedState(int32 maxduration, int32 duration, int32 charges, uint8 stackamount, uint8 recalculateMask, int32 * amount)
{
    m_maxDuration = maxduration;
    m_duration = duration;
    m_procCharges = charges;
    m_stackAmount = stackamount;
    Unit * caster = GetCaster();
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_effects[i])
        {
            m_effects[i]->SetAmount(amount[i]);
            m_effects[i]->SetCanBeRecalculated(recalculateMask & (1<<i));
            m_effects[i]->CalculatePeriodic(caster);
            m_effects[i]->CalculateSpellMod();
            m_effects[i]->RecalculateAmount(caster);
        }
}

bool Aura::HasEffectType(AuraType type) const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (HasEffect(i) && m_effects[i]->GetAuraType() == type)
            return true;
    }
    return false;
}

void Aura::RecalculateAmountOfEffects()
{
    ASSERT (!IsRemoved());
    Unit * caster = GetCaster();
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (HasEffect(i))
            m_effects[i]->RecalculateAmount(caster);
}

void Aura::HandleAllEffects(AuraApplication * aurApp, uint8 mode, bool apply)
{
    ASSERT (!IsRemoved());
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_effects[i] && !IsRemoved())
            m_effects[i]->HandleEffect(aurApp, mode, apply);
}

void Aura::SetNeedClientUpdateForTargets() const
{
    for (ApplicationMap::const_iterator appIter = m_applications.begin(); appIter != m_applications.end(); ++appIter)
        appIter->second->SetNeedClientUpdate();
}

// trigger effects on real aura apply/remove
void Aura::HandleAuraSpecificMods(AuraApplication const * aurApp, Unit * caster, bool apply)
{
    Unit * target = aurApp->GetTarget();
    AuraRemoveMode removeMode = aurApp->GetRemoveMode();
    // spell_area table
    SpellAreaForAreaMapBounds saBounds = sSpellMgr->GetSpellAreaForAuraMapBounds(GetId());
    if (saBounds.first != saBounds.second)
    {
        uint32 zone, area;
        target->GetZoneAndAreaId(zone, area);

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            // some auras remove at aura remove
            if (!itr->second->IsFitToRequirements((Player*)target, zone, area))
                target->RemoveAurasDueToSpell(itr->second->spellId);
            // some auras applied at aura apply
            else if (itr->second->autocast)
            {
                if (!target->HasAura(itr->second->spellId))
                    target->CastSpell(target, itr->second->spellId, true);
            }
        }
    }
    // mods at aura apply
    if (apply)
    {
        // Apply linked auras (On first aura apply)
        if (sSpellMgr->GetSpellCustomAttr(GetId()) & SPELL_ATTR0_CU_LINK_AURA)
        {
            if (const std::vector<int32> *spell_triggered = sSpellMgr->GetSpellLinked(GetId() + SPELL_LINK_AURA))
                for (std::vector<int32>::const_iterator itr = spell_triggered->begin(); itr != spell_triggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->ApplySpellImmune(GetId(), IMMUNITY_ID, -(*itr), true);
                    else if (caster)
                        caster->AddAura(*itr, target);
                }
        }
        switch (GetSpellProto()->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
                switch(GetId())
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
                            target->ToPlayer()->RemoveSpellCooldown(20252, true);
                        break;
                }
                break;
            case SPELLFAMILY_DRUID:
                if (!caster)
                    break;
                // Rejuvenation
                if (GetSpellProto()->SpellFamilyFlags[0] & 0x10 && GetEffect(EFFECT_0))
                {
                    // Druid T8 Restoration 4P Bonus
                    if (caster->HasAura(64760))
                    {
                        int32 heal = GetEffect(EFFECT_0)->GetAmount();
                        caster->CastCustomSpell(target, 64801, &heal, NULL, NULL, true, NULL, GetEffect(EFFECT_0));
                    }
                }
                break;
            case SPELLFAMILY_MAGE:
                if (!caster)
                    break;
                if (GetSpellProto()->SpellFamilyFlags[0] & 0x00000001 && GetSpellProto()->SpellFamilyFlags[2] & 0x00000008)
                {
                    // Glyph of Fireball
                    if (caster->HasAura(56368))
                        SetDuration(0);
                }
                else if (GetSpellProto()->SpellFamilyFlags[0] & 0x00000020 && GetSpellProto()->SpellVisual[0] == 13)
                {
                    // Glyph of Frostbolt
                    if (caster->HasAura(56370))
                        SetDuration(0);
                }
                // Todo: This should be moved to similar function in spell::hit
                else if (GetSpellProto()->SpellFamilyFlags[0] & 0x01000000)
                {
                    // Polymorph Sound - Sheep && Penguin
                    if (GetSpellProto()->SpellIconID == 82 && GetSpellProto()->SpellVisual[0] == 12978)
                    {
                        // Glyph of the Penguin
                        if (caster->HasAura(52648))
                            caster->CastSpell(target, 61635, true);
                        else
                            caster->CastSpell(target, 61634, true);
                    }
                }
                switch(GetId())
                {
                    case 12536: // Clearcasting
                    case 12043: // Presence of Mind
                        // Arcane Potency
                        if (AuraEffect const * aurEff = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_MAGE, 2120, 0))
                        {
                            uint32 spellId = 0;

                            switch (aurEff->GetId())
                            {
                                case 31571: spellId = 57529; break;
                                case 31572: spellId = 57531; break;
                                default:
                                    sLog->outError("Aura::HandleAuraSpecificMods: Unknown rank of Arcane Potency (%d) found", aurEff->GetId());
                            }
                            if (spellId)
                                caster->CastSpell(caster, spellId, true);
                        }
                        break;
                    case 44544: // Fingers of Frost
                    {
                        // See if we already have the indicator aura. If not, create one.
                        if (Aura *aur = target->GetAura(74396))
                        {
                            // Aura already there. Refresh duration and set original charges
                            aur->SetCharges(2);
                            aur->RefreshDuration();
                        }
                        else
                            target->AddAura(74396, target);
                    }
                    default:
                        break;
                }
                break;
            case SPELLFAMILY_WARLOCK:
                switch(GetId())
                {
                    case 48020: // Demonic Circle
                        if (target->GetTypeId() == TYPEID_PLAYER)
                            if (GameObject* obj = target->GetGameObject(48018))
                            {
                                target->NearTeleportTo(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), obj->GetOrientation());
                                target->RemoveMovementImpairingAuras();
                            }
                        break;
                }
                break;
            case SPELLFAMILY_PRIEST:
                if (!caster)
                    break;
                // Devouring Plague
                if (GetSpellProto()->SpellFamilyFlags[0] & 0x02000000 && GetEffect(0))
                {
                    // Improved Devouring Plague
                    if (AuraEffect const * aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, 3790, 1))
                    {
                        int32 basepoints0 = aurEff->GetAmount() * GetEffect(0)->GetTotalTicks() * caster->SpellDamageBonus(target, GetSpellProto(), GetEffect(0)->GetAmount(), DOT) / 100;
                        int32 heal = int32(CalculatePctN(basepoints0, 15));
                        caster->CastCustomSpell(target, 63675, &basepoints0, NULL, NULL, true, NULL, GetEffect(0));
                        caster->CastCustomSpell(caster, 75999, &heal, NULL, NULL, true, NULL, GetEffect(0));
                    }
                }
                // Renew
                else if (GetSpellProto()->SpellFamilyFlags[0] & 0x00000040 && GetEffect(0))
                {
                    // Empowered Renew
                    if (AuraEffect const * aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, 3021, 1))
                    {
                        int32 basepoints0 = aurEff->GetAmount() * GetEffect(0)->GetTotalTicks() * caster->SpellHealingBonus(target, GetSpellProto(), GetEffect(0)->GetAmount(), HEAL) / 100;
                        caster->CastCustomSpell(target, 63544, &basepoints0, NULL, NULL, true, NULL, GetEffect(0));
                    }
                }
                // Power Word: Shield
                else if (m_spellProto->SpellFamilyFlags[0] & 0x1 && m_spellProto->SpellFamilyFlags[2] & 0x400 && GetEffect(0))
                {
                    // Glyph of Power Word: Shield
                    if (AuraEffect* glyph = caster->GetAuraEffect(55672, 0))
                    {
                        // instantly heal m_amount% of the absorb-value
                        int32 heal = glyph->GetAmount() * GetEffect(0)->GetAmount()/100;
                        caster->CastCustomSpell(GetUnitOwner(), 56160, &heal, NULL, NULL, true, 0, GetEffect(0));
                    }
                }
                break;
            case SPELLFAMILY_ROGUE:
                // Sprint (skip non player casted spells by category)
                if (GetSpellProto()->SpellFamilyFlags[0] & 0x40 && GetSpellProto()->Category == 44)
                    // in official maybe there is only one icon?
                    if (target->HasAura(58039)) // Glyph of Blurred Speed
                        target->CastSpell(target, 61922, true); // Sprint (waterwalk)
                break;
            case SPELLFAMILY_DEATHKNIGHT:
                if (!caster)
                    break;
                // Frost Fever and Blood Plague
                if (GetSpellProto()->SpellFamilyFlags[2] & 0x2)
                {
                    // Can't proc on self
                    if (GetCasterGUID() == target->GetGUID())
                        break;

                    AuraEffect * aurEff = NULL;
                    // Ebon Plaguebringer / Crypt Fever
                    Unit::AuraEffectList const& TalentAuras = caster->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                    for (Unit::AuraEffectList::const_iterator itr = TalentAuras.begin(); itr != TalentAuras.end(); ++itr)
                    {
                        if ((*itr)->GetMiscValue() == 7282)
                        {
                            aurEff = *itr;
                            // Ebon Plaguebringer - end search if found
                            if ((*itr)->GetSpellProto()->SpellIconID == 1766)
                                break;
                        }
                    }
                    if (aurEff)
                    {
                        uint32 spellId = 0;
                        switch (aurEff->GetId())
                        {
                            // Ebon Plague
                            case 51161: spellId = 51735; break;
                            case 51160: spellId = 51734; break;
                            case 51099: spellId = 51726; break;
                            // Crypt Fever
                            case 49632: spellId = 50510; break;
                            case 49631: spellId = 50509; break;
                            case 49032: spellId = 50508; break;
                            default:
                                sLog->outError("Aura::HandleAuraSpecificMods: Unknown rank of Crypt Fever/Ebon Plague (%d) found", aurEff->GetId());
                        }
                        caster->CastSpell(target, spellId, true, 0, GetEffect(0));
                    }
                }
                break;
        }
    }
    // mods at aura remove
    else
    {
        // Remove Linked Auras
        if (removeMode != AURA_REMOVE_BY_DEATH)
        {
            if (uint32 customAttr = sSpellMgr->GetSpellCustomAttr(GetId()))
            {
                if (customAttr & SPELL_ATTR0_CU_LINK_REMOVE)
                {
                    if (const std::vector<int32> *spell_triggered = sSpellMgr->GetSpellLinked(-(int32)GetId()))
                        for (std::vector<int32>::const_iterator itr = spell_triggered->begin(); itr != spell_triggered->end(); ++itr)
                        {
                            if (*itr < 0)
                                target->RemoveAurasDueToSpell(-(*itr));
                            else if (removeMode != AURA_REMOVE_BY_DEFAULT)
                                target->CastSpell(target, *itr, true, NULL, NULL, GetCasterGUID());
                        }
                }
                if (customAttr & SPELL_ATTR0_CU_LINK_AURA)
                {
                    if (const std::vector<int32> *spell_triggered = sSpellMgr->GetSpellLinked(GetId() + SPELL_LINK_AURA))
                        for (std::vector<int32>::const_iterator itr = spell_triggered->begin(); itr != spell_triggered->end(); ++itr)
                        {
                            if (*itr < 0)
                                target->ApplySpellImmune(GetId(), IMMUNITY_ID, -(*itr), false);
                            else
                                target->RemoveAurasDueToSpell(*itr);
                        }
                }
            }
        }
        switch(GetSpellProto()->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
                switch(GetId())
                {
                    case 61987: // Avenging Wrath
                        // Remove the immunity shield marker on Avenging Wrath removal if Forbearance is not present
                        if (target->HasAura(61988) && !target->HasAura(25771))
                            target->RemoveAura(61988);
                        break;
                    case 72368: // Shared Suffering
                    case 72369:
                        if (caster)
                        {
                            if (AuraEffect* aurEff = GetEffect(0))
                            {
                                int32 remainingDamage = aurEff->GetAmount() * (aurEff->GetTotalTicks() - aurEff->GetTickNumber());
                                if (remainingDamage > 0)
                                    caster->CastCustomSpell(caster, 72373, NULL, &remainingDamage, NULL, true);
                            }
                        }
                        break;
                }
                break;
            case SPELLFAMILY_MAGE:
                switch(GetId())
                {
                    case 66: // Invisibility
                        if (removeMode != AURA_REMOVE_BY_EXPIRE)
                            break;
                        target->CastSpell(target, 32612, true, NULL, GetEffect(1));
                        break;
                    case 74396: // Fingers of Frost
                        // Remove the IGNORE_AURASTATE aura
                        target->RemoveAurasDueToSpell(44544);
                        break;
                    case 44401: //Missile Barrage
                    case 48108: //Hot Streak
                    case 57761: //Fireball!
                        if (removeMode != AURA_REMOVE_BY_EXPIRE || aurApp->GetBase()->IsExpired())
                            break;
                        if (target->HasAura(70752)) //Item - Mage T10 2P Bonus
                            target->CastSpell(target, 70753, true);
                        break;
                    default:
                        break;
                }
                if (!caster)
                    break;
                // Ice barrier - dispel/absorb remove
                if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL && GetSpellProto()->SpellFamilyFlags[1] & 0x1)
                {
                    // Shattered Barrier
                    if (caster->GetDummyAuraEffect(SPELLFAMILY_MAGE, 2945, 0))
                        caster->CastSpell(target, 55080, true, NULL, GetEffect(0));
                }
                break;
            case SPELLFAMILY_WARRIOR:
                if (!caster)
                    break;
                // Spell Reflection
                if (GetSpellProto()->SpellFamilyFlags[1] & 0x2)
                {
                    if (removeMode != AURA_REMOVE_BY_DEFAULT)
                    {
                        // Improved Spell Reflection
                        if (caster->GetDummyAuraEffect(SPELLFAMILY_WARRIOR, 1935, 1))
                        {
                            // aura remove - remove auras from all party members
                            std::list<Unit*> PartyMembers;
                            target->GetPartyMembers(PartyMembers);
                            for (std::list<Unit*>::iterator itr = PartyMembers.begin(); itr != PartyMembers.end(); ++itr)
                            {
                                if ((*itr)!= target)
                                    (*itr)->RemoveAurasWithFamily(SPELLFAMILY_WARRIOR, 0, 0x2, 0, GetCasterGUID());
                            }
                        }
                    }
                }
                break;
            case SPELLFAMILY_WARLOCK:
                if (!caster)
                    break;
                // Curse of Doom
                if (GetSpellProto()->SpellFamilyFlags[1] & 0x02)
                {
                    if (removeMode == AURA_REMOVE_BY_DEATH)
                    {
                        if (caster->GetTypeId() == TYPEID_PLAYER && caster->ToPlayer()->isHonorOrXPTarget(target))
                            caster->CastSpell(target, 18662, true, NULL, GetEffect(0));
                    }
                }
                // Improved Fear
                else if (GetSpellProto()->SpellFamilyFlags[1] & 0x00000400)
                {
                    if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_WARLOCK, 98, 0))
                    {
                        uint32 spellId = 0;
                        switch (aurEff->GetId())
                        {
                            case 53759: spellId = 60947; break;
                            case 53754: spellId = 60946; break;
                            default:
                                sLog->outError("Aura::HandleAuraSpecificMods: Unknown rank of Improved Fear (%d) found", aurEff->GetId());
                        }
                        if (spellId)
                            caster->CastSpell(target, spellId, true);
                    }
                }
                switch(GetId())
                {
                   case 48018: // Demonic Circle
                        target->RemoveGameObject(GetId(), true);
                        target->RemoveAura(62388);
                    break;
                }
                break;
            case SPELLFAMILY_PRIEST:
                if (!caster)
                    break;
                // Shadow word: Pain // Vampiric Touch
                if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL && (GetSpellProto()->SpellFamilyFlags[0] & 0x00008000 || GetSpellProto()->SpellFamilyFlags[1] & 0x00000400))
                {
                    // Shadow Affinity
                    if (AuraEffect const * aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, 178, 1))
                    {
                        int32 basepoints0 = aurEff->GetAmount() * caster->GetCreateMana() / 100;
                        caster->CastCustomSpell(caster, 64103, &basepoints0, NULL, NULL, true, NULL, GetEffect(0));
                    }
                }
                // Power word: shield
                else if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL && GetSpellProto()->SpellFamilyFlags[0] & 0x00000001)
                {
                    // Rapture
                    if (Aura const * aura = caster->GetAuraOfRankedSpell(47535))
                    {
                        // check cooldown
                        if (caster->GetTypeId() == TYPEID_PLAYER)
                        {
                            if (caster->ToPlayer()->HasSpellCooldown(aura->GetId()))
                                break;
                            // and add if needed
                            caster->ToPlayer()->AddSpellCooldown(aura->GetId(), 0, uint32(time(NULL) + 12));
                        }
                        // effect on caster
                        if (AuraEffect const * aurEff = aura->GetEffect(0))
                        {
                            float multiplier = (float)aurEff->GetAmount();
                            if (aurEff->GetId() == 47535)
                                multiplier -= 0.5f;
                            else if (aurEff->GetId() == 47537)
                                multiplier += 0.5f;

                            int32 basepoints0 = int32(CalculatePctF(caster->GetMaxPower(POWER_MANA), multiplier));
                            caster->CastCustomSpell(caster, 47755, &basepoints0, NULL, NULL, true);
                        }
                        // effect on aura target
                        if (AuraEffect const * aurEff = aura->GetEffect(1))
                        {
                            if (!roll_chance_i(aurEff->GetAmount()))
                                break;

                            int32 triggeredSpellId = 0;
                            switch(target->getPowerType())
                            {
                                case POWER_MANA:
                                {
                                    int32 basepoints0 = int32(CalculatePctN(target->GetMaxPower(POWER_MANA), 2));
                                    caster->CastCustomSpell(target, 63654, &basepoints0, NULL, NULL, true);
                                    break;
                                }
                                case POWER_RAGE:   triggeredSpellId = 63653; break;
                                case POWER_ENERGY: triggeredSpellId = 63655; break;
                                case POWER_RUNIC_POWER: triggeredSpellId = 63652; break;
                                default:
                                    break;
                            }
                            if (triggeredSpellId)
                                caster->CastSpell(target, triggeredSpellId, true);
                        }
                    }
                }
                switch(GetId())
                {
                    case 47788: // Guardian Spirit
                        if (removeMode != AURA_REMOVE_BY_EXPIRE)
                            break;
                        if (caster->GetTypeId() != TYPEID_PLAYER)
                            break;

                        Player *player = caster->ToPlayer();
                        // Glyph of Guardian Spirit
                        if (AuraEffect * aurEff = player->GetAuraEffect(63231, 0))
                        {
                            if (!player->HasSpellCooldown(47788))
                                break;

                            player->RemoveSpellCooldown(GetSpellProto()->Id, true);
                            player->AddSpellCooldown(GetSpellProto()->Id, 0, uint32(time(NULL) + aurEff->GetAmount()));

                            WorldPacket data(SMSG_SPELL_COOLDOWN, 8+1+4+4);
                            data << uint64(player->GetGUID());
                            data << uint8(0x0);                                     // flags (0x1, 0x2)
                            data << uint32(GetSpellProto()->Id);
                            data << uint32(aurEff->GetAmount()*IN_MILLISECONDS);
                            player->SendDirectMessage(&data);
                        }
                        break;
                }
                break;
            case SPELLFAMILY_ROGUE:
                // Remove Vanish on stealth remove
                if (GetId() == 1784)
                    target->RemoveAurasWithFamily(SPELLFAMILY_ROGUE, 0x0000800, 0, 0, target->GetGUID());
                break;
            case SPELLFAMILY_PALADIN:
                // Remove the immunity shield marker on Forbearance removal if AW marker is not present
                if (GetId() == 25771 && target->HasAura(61988) && !target->HasAura(61987))
                    target->RemoveAura(61988);
                break;
            case SPELLFAMILY_DEATHKNIGHT:
                // Blood of the North
                // Reaping
                // Death Rune Mastery
                if (GetSpellProto()->SpellIconID == 3041 || GetSpellProto()->SpellIconID == 22 || GetSpellProto()->SpellIconID == 2622)
                {
                    if (!GetEffect(0) || GetEffect(0)->GetAuraType() != SPELL_AURA_PERIODIC_DUMMY)
                        break;
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        break;
                    if (target->ToPlayer()->getClass() != CLASS_DEATH_KNIGHT)
                        break;

                     // aura removed - remove death runes
                    target->ToPlayer()->RemoveRunesByAuraEffect(GetEffect(0));
                }
                break;
            case SPELLFAMILY_HUNTER:
                // Glyph of Freezing Trap
                if (GetSpellProto()->SpellFamilyFlags[0] & 0x00000008)
                    if (caster && caster->HasAura(56845))
                        target->CastSpell(target, 61394, true);
                break;
        }
    }

    // mods at aura apply or remove
    switch (GetSpellProto()->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
            switch (GetId())
            {
                case 50720: // Vigilance
                    if (apply)
                        target->CastSpell(caster, 59665, true, 0, 0, caster->GetGUID());
                    else
                        target->SetReducedThreatPercent(0, 0);
                    break;
            }
            break;
        case SPELLFAMILY_ROGUE:
            // Stealth
            if (GetSpellProto()->SpellFamilyFlags[0] & 0x00400000)
            {
                // Master of subtlety
                if (AuraEffect const * aurEff = target->GetAuraEffectOfRankedSpell(31221, 0))
                {
                    if (!apply)
                        target->CastSpell(target, 31666, true);
                    else
                    {
                        int32 basepoints0 = aurEff->GetAmount();
                        target->CastCustomSpell(target, 31665, &basepoints0, NULL, NULL , true);
                    }
                }
                // Overkill
                if (target->HasAura(58426))
                {
                    if (!apply)
                        target->CastSpell(target, 58428, true);
                    else
                        target->CastSpell(target, 58427, true);
                }
                break;
            }
            break;
        case SPELLFAMILY_HUNTER:
            switch(GetId())
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
            switch(GetId())
            {
                case 19746:
                case 31821:
                    // Aura Mastery Triggered Spell Handler
                    // If apply Concentration Aura -> trigger -> apply Aura Mastery Immunity
                    // If remove Concentration Aura -> trigger -> remove Aura Mastery Immunity
                    // If remove Aura Mastery -> trigger -> remove Aura Mastery Immunity
                    // Do effects only on aura owner
                    if (GetCasterGUID() != target->GetGUID())
                        break;
                    if (apply)
                    {
                        if ((GetSpellProto()->Id == 31821 && target->HasAura(19746, GetCasterGUID())) || (GetSpellProto()->Id == 19746 && target->HasAura(31821)))
                            target->CastSpell(target, 64364, true);
                    }
                    else
                        target->RemoveAurasDueToSpell(64364, GetCasterGUID());
                    break;
                case 31842:
                    if (caster->HasAura(70755))
                    {
                        if (apply)
                            caster->CastSpell(caster, 71166, true);
                        else
                            caster->RemoveAurasDueToSpell(71166);
                    }
                    break;
            }
            break;
        case SPELLFAMILY_DEATHKNIGHT:
            if (GetSpellSpecific(GetSpellProto()) == SPELL_SPECIFIC_PRESENCE)
            {
                AuraEffect *bloodPresenceAura=0;  // healing by damage done
                AuraEffect *frostPresenceAura=0;  // increased health
                AuraEffect *unholyPresenceAura=0; // increased movement speed, faster rune recovery

                // Improved Presences
                Unit::AuraEffectList const& vDummyAuras = target->GetAuraEffectsByType(SPELL_AURA_DUMMY);
                for (Unit::AuraEffectList::const_iterator itr = vDummyAuras.begin(); itr != vDummyAuras.end(); ++itr)
                {
                    switch((*itr)->GetId())
                    {
                        // Improved Blood Presence
                        case 50365:
                        case 50371:
                        {
                            bloodPresenceAura = (*itr);
                            break;
                        }
                        // Improved Frost Presence
                        case 50384:
                        case 50385:
                        {
                            frostPresenceAura = (*itr);
                            break;
                        }
                        // Improved Unholy Presence
                        case 50391:
                        case 50392:
                        {
                            unholyPresenceAura = (*itr);
                            break;
                        }
                    }
                }

                uint32 presence=GetId();
                if (apply)
                {
                    // Blood Presence bonus
                    if (presence == 48266)
                        target->CastSpell(target, 63611, true);
                    else if (bloodPresenceAura)
                    {
                        int32 basePoints1=bloodPresenceAura->GetAmount();
                        target->CastCustomSpell(target, 63611, NULL, &basePoints1, NULL, true, 0, bloodPresenceAura);
                    }
                    // Frost Presence bonus
                    if (presence == 48263)
                        target->CastSpell(target, 61261, true);
                    else if (frostPresenceAura)
                    {
                        int32 basePoints0=frostPresenceAura->GetAmount();
                        target->CastCustomSpell(target, 61261, &basePoints0, NULL, NULL, true, 0, frostPresenceAura);
                    }
                    // Unholy Presence bonus
                    if (presence == 48265)
                    {
                        if (unholyPresenceAura)
                        {
                            // Not listed as any effect, only base points set
                            int32 basePoints0 = SpellMgr::CalculateSpellEffectAmount(unholyPresenceAura->GetSpellProto(), 1);
                            target->CastCustomSpell(target, 63622, &basePoints0 , &basePoints0, &basePoints0, true, 0, unholyPresenceAura);
                            target->CastCustomSpell(target, 65095, &basePoints0 , NULL, NULL, true, 0, unholyPresenceAura);
                        }
                        target->CastSpell(target, 49772, true);
                    }
                    else if (unholyPresenceAura)
                    {
                        int32 basePoints0=unholyPresenceAura->GetAmount();
                        target->CastCustomSpell(target, 49772, &basePoints0, NULL, NULL, true, 0, unholyPresenceAura);
                    }
                }
                else
                {
                    // Remove passive auras
                    if (presence == 48266 || bloodPresenceAura)
                        target->RemoveAurasDueToSpell(63611);
                    if (presence == 48263 || frostPresenceAura)
                        target->RemoveAurasDueToSpell(61261);
                    if (presence == 48265 || unholyPresenceAura)
                    {
                        if (presence == 48265 && unholyPresenceAura)
                        {
                            target->RemoveAurasDueToSpell(63622);
                            target->RemoveAurasDueToSpell(65095);
                        }
                        target->RemoveAurasDueToSpell(49772);
                    }
                }
            }
            break;
        case SPELLFAMILY_WARLOCK:
            // Drain Soul - If the target is at or below 25% health, Drain Soul causes four times the normal damage
            if (GetSpellProto()->SpellFamilyFlags[0] & 0x00004000)
            {
                if (!caster)
                    break;
                if (apply)
                {
                    if (target != caster && !target->HealthAbovePct(25))
                        caster->CastSpell(caster, 100001, true);
                }
                else
                {
                    if (target != caster)
                        caster->RemoveAurasDueToSpell(GetId());
                    else
                        caster->RemoveAurasDueToSpell(100001);
                }
            }
            break;
    }
}

bool Aura::CanBeAppliedOn(Unit *target)
{
    // unit not in world or during remove from world
    if (!target->IsInWorld() || target->IsDuringRemoveFromWorld())
    {
        // area auras mustn't be applied
        if (GetOwner() != target)
            return false;
        // not selfcasted single target auras mustn't be applied
        if (GetCasterGUID() != GetOwner()->GetGUID() && IsSingleTargetSpell(GetSpellProto()))
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
    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Aura::LoadScripts");
    sScriptMgr->CreateAuraScripts(m_spellProto->Id, m_loadedScripts);
    for(std::list<AuraScript *>::iterator itr = m_loadedScripts.begin(); itr != m_loadedScripts.end() ;)
    {
        if (!(*itr)->_Load(this))
        {
            std::list<AuraScript *>::iterator bitr = itr;
            ++itr;
            m_loadedScripts.erase(bitr);
            continue;
        }
        (*itr)->Register();
        ++itr;
    }
}

bool Aura::CallScriptCheckAreaTargetHandlers(Unit* target)
{
    for(std::list<AuraScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_CHECK_AREA_TARGET);
        std::list<AuraScript::CheckAreaTargetHandler>::iterator hookItrEnd = (*scritr)->DoCheckAreaTarget.end(), hookItr = (*scritr)->DoCheckAreaTarget.begin();
        for (; hookItr != hookItrEnd ; ++hookItr)
            if(!(*hookItr).Call(*scritr, target))
                return false;
        (*scritr)->_FinishScriptCall();
    }
    return true;
}

bool Aura::CallScriptEffectApplyHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode)
{
    bool preventDefault = false;
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_APPLY, aurApp);
        std::list<AuraScript::EffectApplyHandler>::iterator effEndItr = (*scritr)->OnEffectApply.end(), effItr = (*scritr)->OnEffectApply.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, mode);
        }
        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();
        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

bool Aura::CallScriptEffectRemoveHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode)
{
    bool preventDefault = false;
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_REMOVE, aurApp);
        std::list<AuraScript::EffectApplyHandler>::iterator effEndItr = (*scritr)->OnEffectRemove.end(), effItr = (*scritr)->OnEffectRemove.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, mode);
        }
        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();
        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

void Aura::CallScriptAfterEffectApplyHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_APPLY, aurApp);
        std::list<AuraScript::EffectApplyHandler>::iterator effEndItr = (*scritr)->AfterEffectApply.end(), effItr = (*scritr)->AfterEffectApply.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, mode);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptAfterEffectRemoveHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp, AuraEffectHandleModes mode)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_REMOVE, aurApp);
        std::list<AuraScript::EffectApplyHandler>::iterator effEndItr = (*scritr)->AfterEffectRemove.end(), effItr = (*scritr)->AfterEffectRemove.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, mode);
        }
        (*scritr)->_FinishScriptCall();
    }
}

bool Aura::CallScriptEffectPeriodicHandlers(AuraEffect const * aurEff, AuraApplication const * aurApp)
{
    bool preventDefault = false;
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_PERIODIC, aurApp);
        std::list<AuraScript::EffectPeriodicHandler>::iterator effEndItr = (*scritr)->OnEffectPeriodic.end(), effItr = (*scritr)->OnEffectPeriodic.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff);
        }
        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultActionPrevented();
        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

void Aura::CallScriptEffectUpdatePeriodicHandlers(AuraEffect * aurEff)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_UPDATE_PERIODIC);
        std::list<AuraScript::EffectUpdatePeriodicHandler>::iterator effEndItr = (*scritr)->OnEffectUpdatePeriodic.end(), effItr = (*scritr)->OnEffectUpdatePeriodic.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcAmountHandlers(AuraEffect const * aurEff, int32 & amount, bool & canBeRecalculated)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_AMOUNT);
        std::list<AuraScript::EffectCalcAmountHandler>::iterator effEndItr = (*scritr)->DoEffectCalcAmount.end(), effItr = (*scritr)->DoEffectCalcAmount.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, amount, canBeRecalculated);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcPeriodicHandlers(AuraEffect const * aurEff, bool & isPeriodic, int32 & amplitude)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_PERIODIC);
        std::list<AuraScript::EffectCalcPeriodicHandler>::iterator effEndItr = (*scritr)->DoEffectCalcPeriodic.end(), effItr = (*scritr)->DoEffectCalcPeriodic.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, isPeriodic, amplitude);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectCalcSpellModHandlers(AuraEffect const * aurEff, SpellModifier *& spellMod)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_SPELLMOD);
        std::list<AuraScript::EffectCalcSpellModHandler>::iterator effEndItr = (*scritr)->DoEffectCalcSpellMod.end(), effItr = (*scritr)->DoEffectCalcSpellMod.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, spellMod);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAbsorbHandlers(AuraEffect * aurEff, AuraApplication const * aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount, bool & /*defaultPrevented*/)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_ABSORB, aurApp);
        std::list<AuraScript::EffectAbsorbHandler>::iterator effEndItr = (*scritr)->OnEffectAbsorb.end(), effItr = (*scritr)->OnEffectAbsorb.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, dmgInfo, absorbAmount);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterAbsorbHandlers(AuraEffect * aurEff, AuraApplication const * aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB, aurApp);
        std::list<AuraScript::EffectAbsorbHandler>::iterator effEndItr = (*scritr)->AfterEffectAbsorb.end(), effItr = (*scritr)->AfterEffectAbsorb.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, dmgInfo, absorbAmount);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectManaShieldHandlers(AuraEffect * aurEff, AuraApplication const * aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount, bool & /*defaultPrevented*/)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_MANASHIELD, aurApp);
        std::list<AuraScript::EffectManaShieldHandler>::iterator effEndItr = (*scritr)->OnEffectManaShield.end(), effItr = (*scritr)->OnEffectManaShield.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, dmgInfo, absorbAmount);
        }
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterManaShieldHandlers(AuraEffect * aurEff, AuraApplication const * aurApp, DamageInfo & dmgInfo, uint32 & absorbAmount)
{
    for(std::list<AuraScript *>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD, aurApp);
        std::list<AuraScript::EffectManaShieldHandler>::iterator effEndItr = (*scritr)->AfterEffectManaShield.end(), effItr = (*scritr)->AfterEffectManaShield.begin();
        for(; effItr != effEndItr ; ++effItr)
        {
            if ((*effItr).IsEffectAffected(m_spellProto, aurEff->GetEffIndex()))
                (*effItr).Call(*scritr, aurEff, dmgInfo, absorbAmount);
        }
        (*scritr)->_FinishScriptCall();
    }
}

UnitAura::UnitAura(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID)
    : Aura(spellproto, owner, caster, castItem, casterGUID)
{
    m_AuraDRGroup = DIMINISHING_NONE;
    LoadScripts();
    _InitEffects(effMask, caster, baseAmount);
    GetUnitOwner()->_AddAura(this, caster);
};

void UnitAura::_ApplyForTarget(Unit * target, Unit * caster, AuraApplication * aurApp)
{
    Aura::_ApplyForTarget(target, caster, aurApp);

    // register aura diminishing on apply
    if (DiminishingGroup group = GetDiminishGroup())
        target->ApplyDiminishingAura(group, true);
}

void UnitAura::_UnapplyForTarget(Unit * target, Unit * caster, AuraApplication * aurApp)
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

void UnitAura::FillTargetMap(std::map<Unit *, uint8> & targets, Unit * caster)
{
    Player * modOwner = NULL;
    if (caster)
        modOwner = caster->GetSpellModOwner();

    for (uint8 effIndex = 0; effIndex < MAX_SPELL_EFFECTS ; ++effIndex)
    {
        if (!HasEffect(effIndex))
            continue;
        UnitList targetList;
        // non-area aura
        if (GetSpellProto()->Effect[effIndex] == SPELL_EFFECT_APPLY_AURA)
        {
            targetList.push_back(GetUnitOwner());
        }
        else
        {
            float radius;
            if (GetSpellProto()->Effect[effIndex] == SPELL_EFFECT_APPLY_AREA_AURA_ENEMY)
                radius = GetSpellRadiusForHostile(sSpellRadiusStore.LookupEntry(GetSpellProto()->EffectRadiusIndex[effIndex]));
            else
                radius = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(GetSpellProto()->EffectRadiusIndex[effIndex]));

            if (modOwner)
                modOwner->ApplySpellMod(GetId(), SPELLMOD_RADIUS, radius);

            if (!GetUnitOwner()->HasUnitState(UNIT_STAT_ISOLATED))
            {
                switch(GetSpellProto()->Effect[effIndex])
                {
                    case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                        targetList.push_back(GetUnitOwner());
                        GetUnitOwner()->GetPartyMemberInDist(targetList, radius);
                        break;
                    case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
                        targetList.push_back(GetUnitOwner());
                        GetUnitOwner()->GetRaidMember(targetList, radius);
                        break;
                    case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
                    {
                        targetList.push_back(GetUnitOwner());
                        Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(GetUnitOwner(), GetUnitOwner(), radius);
                        Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(GetUnitOwner(), targetList, u_check);
                        GetUnitOwner()->VisitNearbyObject(radius, searcher);
                        break;
                    }
                    case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
                    {
                        Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(GetUnitOwner(), GetUnitOwner(), radius); // No GetCharmer in searcher
                        Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(GetUnitOwner(), targetList, u_check);
                        GetUnitOwner()->VisitNearbyObject(radius, searcher);
                        break;
                    }
                    case SPELL_EFFECT_APPLY_AREA_AURA_PET:
                        targetList.push_back(GetUnitOwner());
                    case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
                    {
                        if (Unit *owner = GetUnitOwner()->GetCharmerOrOwner())
                            if (GetUnitOwner()->IsWithinDistInMap(owner, radius))
                                targetList.push_back(owner);
                        break;
                    }
                }
            }
        }

        for (UnitList::iterator itr = targetList.begin(); itr!= targetList.end();++itr)
        {
            std::map<Unit *, uint8>::iterator existing = targets.find(*itr);
            if (existing != targets.end())
                existing->second |= 1<<effIndex;
            else
                targets[*itr] = 1<<effIndex;
        }
    }
}

DynObjAura::DynObjAura(SpellEntry const* spellproto, uint8 effMask, WorldObject * owner, Unit * caster, int32 *baseAmount, Item * castItem, uint64 casterGUID)
    : Aura(spellproto, owner, caster, castItem, casterGUID)
{
    LoadScripts();
    ASSERT(GetDynobjOwner());
    ASSERT(GetDynobjOwner()->IsInWorld());
    ASSERT(GetDynobjOwner()->GetMap() == caster->GetMap());
    _InitEffects(effMask, caster, baseAmount);
    GetDynobjOwner()->SetAura(this);
}

void DynObjAura::Remove(AuraRemoveMode removeMode)
{
    if (IsRemoved())
        return;
    _Remove(removeMode);
}

void DynObjAura::FillTargetMap(std::map<Unit *, uint8> & targets, Unit * /*caster*/)
{
    Unit * dynObjOwnerCaster = GetDynobjOwner()->GetCaster();
    float radius = GetDynobjOwner()->GetRadius();

    for (uint8 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
    {
        if (!HasEffect(effIndex))
            continue;
        UnitList targetList;
        if (GetSpellProto()->EffectImplicitTargetB[effIndex] == TARGET_DEST_DYNOBJ_ALLY
            || GetSpellProto()->EffectImplicitTargetB[effIndex] == TARGET_UNIT_AREA_ALLY_DST)
        {
            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(GetDynobjOwner(), dynObjOwnerCaster, radius);
            Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(GetDynobjOwner(), targetList, u_check);
            GetDynobjOwner()->VisitNearbyObject(radius, searcher);
        }
        else
        {
            Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(GetDynobjOwner(), dynObjOwnerCaster, radius);
            Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(GetDynobjOwner(), targetList, u_check);
            GetDynobjOwner()->VisitNearbyObject(radius, searcher);
        }

        for (UnitList::iterator itr = targetList.begin(); itr!= targetList.end();++itr)
        {
            std::map<Unit *, uint8>::iterator existing = targets.find(*itr);
            if (existing != targets.end())
                existing->second |= 1<<effIndex;
            else
                targets[*itr] = 1<<effIndex;
        }
    }
}

