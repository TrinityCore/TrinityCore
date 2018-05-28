/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Creature.h"
#include "CreatureAI.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ThreatManager.h"
#include "Unit.h"
#include "UnitAI.h"
#include "UnitDefines.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "ObjectAccessor.h"
#include "WorldPacket.h"
#include <algorithm>

const CompareThreatLessThan ThreatManager::CompareThreat;

void ThreatReference::AddThreat(float amount)
{
    if (amount == 0.0f)
        return;
    _baseAmount = std::max<float>(_baseAmount + amount, 0.0f);
    if (amount > 0.0f)
        HeapNotifyIncreased();
    else
        HeapNotifyDecreased();
}

void ThreatReference::ScaleThreat(float factor)
{
    if (factor == 1.0f)
        return;
    _baseAmount *= factor;
    if (factor > 1.0f)
        HeapNotifyIncreased();
    else
        HeapNotifyDecreased();
}

void ThreatReference::UpdateOnlineState()
{
    OnlineState onlineState = SelectOnlineState();
    if (onlineState == _online)
        return;
    bool increase = (onlineState > _online);
    _online = onlineState;
    if (increase)
        HeapNotifyIncreased();
    else
        HeapNotifyDecreased();

    if (!IsAvailable())
        _owner->GetThreatManager().SendRemoveToClients(_victim);
}

/*static*/ bool ThreatReference::FlagsAllowFighting(Unit const* a, Unit const* b)
{
    if (a->GetTypeId() == TYPEID_UNIT && a->ToCreature()->IsTrigger())
        return false;
    if (a->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED))
    {
        if (b->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC))
            return false;
    }
    else
    {
        if (b->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC))
            return false;
    }
    return true;
}

ThreatReference::OnlineState ThreatReference::SelectOnlineState()
{
    // first, check all offline conditions
    if (!_owner->CanSeeOrDetect(_victim)) // not in map/phase, or stealth/invis
        return ONLINE_STATE_OFFLINE;
    if (_victim->HasUnitState(UNIT_STATE_DIED)) // feign death
        return ONLINE_STATE_OFFLINE;
    if (!FlagsAllowFighting(_owner, _victim) || !FlagsAllowFighting(_victim, _owner))
        return ONLINE_STATE_OFFLINE;
    if (_owner->IsAIEnabled && !_owner->GetAI()->CanAIAttack(_victim))
        return ONLINE_STATE_OFFLINE;
    // next, check suppression (immunity to chosen melee attack school)
    if (_victim->IsImmunedToDamage(_owner->GetMeleeDamageSchoolMask()))
        return ONLINE_STATE_SUPPRESSED;
    // or any form of CC that will break on damage - disorient, polymorph, blind etc
    if (_victim->HasBreakableByDamageCrowdControlAura())
        return ONLINE_STATE_SUPPRESSED;
    // no suppression - we're online
    return ONLINE_STATE_ONLINE;
}

void ThreatReference::UpdateTauntState(TauntState state)
{
    // Check for SPELL_AURA_MOD_DETAUNT (applied from owner to victim)
    if (state < TAUNT_STATE_TAUNT && _victim->HasAuraTypeWithCaster(SPELL_AURA_MOD_DETAUNT, _owner->GetGUID()))
        state = TAUNT_STATE_DETAUNT;

    if (state == _taunted)
        return;

    std::swap(state, _taunted);

    if (_taunted < state)
        HeapNotifyDecreased();
    else
        HeapNotifyIncreased();
}

void ThreatReference::ClearThreat(bool sendRemove)
{
    _owner->GetThreatManager().PurgeThreatListRef(_victim->GetGUID(), sendRemove);
    _victim->GetThreatManager().PurgeThreatenedByMeRef(_owner->GetGUID());
    delete this;
}

/*static*/ bool ThreatManager::CanHaveThreatList(Unit const* who)
{
    Creature const* cWho = who->ToCreature();
    // only creatures can have threat list
    if (!cWho)
        return false;

    // pets, totems and triggers cannot have threat list
    if (cWho->IsPet() || cWho->IsTotem() || cWho->IsTrigger())
        return false;

    // summons cannot have a threat list, unless they are controlled by a creature
    if (cWho->HasUnitTypeMask(UNIT_MASK_MINION | UNIT_MASK_GUARDIAN) && !cWho->GetOwnerGUID().IsCreature())
        return false;

    return true;
}

ThreatManager::ThreatManager(Unit* owner) : _owner(owner), _ownerCanHaveThreatList(false), _ownerEngaged(false), _updateClientTimer(CLIENT_THREAT_UPDATE_INTERVAL), _currentVictimRef(nullptr), _fixateRef(nullptr)
{
    for (int8 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        _singleSchoolModifiers[i] = 1.0f;
}

ThreatManager::~ThreatManager()
{
    ASSERT(_myThreatListEntries.empty(), "ThreatManager::~ThreatManager - %s: we still have %zu things threatening us, one of them is %s.", _owner->GetGUID().ToString().c_str(), _myThreatListEntries.size(), _myThreatListEntries.begin()->first.ToString().c_str());
    ASSERT(_sortedThreatList.empty(), "ThreatManager::~ThreatManager - %s: we still have %zu things threatening us, one of them is %s.", _owner->GetGUID().ToString().c_str(), _sortedThreatList.size(), (*_sortedThreatList.begin())->GetVictim()->GetGUID().ToString().c_str());
    ASSERT(_threatenedByMe.empty(), "ThreatManager::~ThreatManager - %s: we are still threatening %zu things, one of them is %s.", _owner->GetGUID().ToString().c_str(), _threatenedByMe.size(), _threatenedByMe.begin()->first.ToString().c_str());
}

void ThreatManager::Initialize()
{
    _ownerCanHaveThreatList = ThreatManager::CanHaveThreatList(_owner);
}

void ThreatManager::Update(uint32 tdiff)
{
    if (!CanHaveThreatList() || !IsEngaged())
        return;
    if (_updateClientTimer <= tdiff)
    {
        _updateClientTimer = CLIENT_THREAT_UPDATE_INTERVAL;
        SendThreatListToClients();
    }
    else
        _updateClientTimer -= tdiff;
}

Unit* ThreatManager::GetCurrentVictim() const
{
    if (_currentVictimRef)
        return _currentVictimRef->GetVictim();
    return nullptr;
}

Unit* ThreatManager::GetAnyTarget() const
{
    for (ThreatReference const* ref : _sortedThreatList)
        if (!ref->IsOffline())
            return ref->GetVictim();
    return nullptr;
}

Unit* ThreatManager::SelectVictim()
{
    if (_sortedThreatList.empty())
        return nullptr;

    ThreatReference const* newVictimRef = ReselectVictim();
    if (newVictimRef != _currentVictimRef)
    {
        if (newVictimRef)
            SendNewVictimToClients(newVictimRef);

        _currentVictimRef = newVictimRef;
    }
    return newVictimRef ? newVictimRef->GetVictim() : nullptr;
}

bool ThreatManager::IsThreatListEmpty(bool includeOffline) const
{
    if (includeOffline)
        return _sortedThreatList.empty();
    for (ThreatReference const* ref : _sortedThreatList)
        if (ref->IsAvailable())
            return false;
    return true;
}

bool ThreatManager::IsThreatenedBy(ObjectGuid const& who, bool includeOffline) const
{
    auto it = _myThreatListEntries.find(who);
    if (it == _myThreatListEntries.end())
        return false;
    return (includeOffline || it->second->IsAvailable());
}
bool ThreatManager::IsThreatenedBy(Unit const* who, bool includeOffline) const { return IsThreatenedBy(who->GetGUID(), includeOffline); }

float ThreatManager::GetThreat(Unit const* who, bool includeOffline) const
{
    auto it = _myThreatListEntries.find(who->GetGUID());
    if (it == _myThreatListEntries.end())
        return 0.0f;
    return (includeOffline || it->second->IsAvailable()) ? it->second->GetThreat() : 0.0f;
}

std::vector<ThreatReference*> ThreatManager::GetModifiableThreatList() const
{
    std::vector<ThreatReference*> list;
    list.reserve(_myThreatListEntries.size());
    for (auto it = _sortedThreatList.ordered_begin(), end = _sortedThreatList.ordered_end(); it != end; ++it)
        list.push_back(const_cast<ThreatReference*>(*it));
    return list;
}

bool ThreatManager::IsThreateningAnyone(bool includeOffline) const
{
    if (includeOffline)
        return !_threatenedByMe.empty();
    for (auto const& pair : _threatenedByMe)
        if (pair.second->IsAvailable())
            return true;
    return false;
}

bool ThreatManager::IsThreateningTo(ObjectGuid const& who, bool includeOffline) const
{
    auto it = _threatenedByMe.find(who);
    if (it == _threatenedByMe.end())
        return false;
    return (includeOffline || it->second->IsAvailable());
}
bool ThreatManager::IsThreateningTo(Unit const* who, bool includeOffline) const { return IsThreateningTo(who->GetGUID(), includeOffline); }

void ThreatManager::UpdateOnlineStates(bool meThreateningOthers, bool othersThreateningMe)
{
    if (othersThreateningMe)
        for (auto const& pair : _myThreatListEntries)
            pair.second->UpdateOnlineState();
    if (meThreateningOthers)
        for (auto const& pair : _threatenedByMe)
            pair.second->UpdateOnlineState();
}

static void SaveCreatureHomePositionIfNeed(Creature* c)
{
    MovementGeneratorType const movetype = c->GetMotionMaster()->GetCurrentMovementGeneratorType();
    if (movetype == WAYPOINT_MOTION_TYPE || movetype == POINT_MOTION_TYPE || (c->IsAIEnabled && c->AI()->IsEscorted()))
        c->SetHomePosition(c->GetPosition());
}

void ThreatManager::AddThreat(Unit* target, float amount, SpellInfo const* spell, bool ignoreModifiers, bool ignoreRedirects)
{
    // step 1: we can shortcut if the spell has one of the NO_THREAT attrs set - nothing will happen
    if (spell)
    {
        if (spell->HasAttribute(SPELL_ATTR1_NO_THREAT))
            return;
        if (!_owner->IsEngaged() && spell->HasAttribute(SPELL_ATTR3_NO_INITIAL_AGGRO))
            return;
    }

    // while riding a vehicle, all threat goes to the vehicle, not the pilot
    if (Unit* vehicle = target->GetVehicleBase())
    {
        AddThreat(vehicle, amount, spell, ignoreModifiers, ignoreRedirects);
        if (target->HasUnitTypeMask(UNIT_MASK_ACCESSORY)) // accessories are fully treated as components of the parent and cannot have threat
            return;
        amount = 0.0f;
    }

    // if we cannot actually have a threat list, we instead just set combat state and avoid creating threat refs altogether
    if (!CanHaveThreatList())
    {
        CombatManager& combatMgr = _owner->GetCombatManager();
        if (!combatMgr.SetInCombatWith(target))
            return;
        // traverse redirects and put them in combat, too
        for (auto const& pair : target->GetThreatManager()._redirectInfo)
            if (!combatMgr.IsInCombatWith(pair.first))
                if (Unit* redirTarget = ObjectAccessor::GetUnit(*_owner, pair.first))
                    combatMgr.SetInCombatWith(redirTarget);
        return;
    }

    // apply threat modifiers to the amount
    if (!ignoreModifiers)
        amount = CalculateModifiedThreat(amount, target, spell);

    // if we're increasing threat, send some/all of it to redirection targets instead if applicable
    if (!ignoreRedirects && amount > 0.0f)
    {
        auto const& redirInfo = target->GetThreatManager()._redirectInfo;
        if (!redirInfo.empty())
        {
            float const origAmount = amount;
            // intentional iteration by index - there's a nested AddThreat call further down that might cause AI calls which might modify redirect info through spells
            for (size_t i = 0; i < redirInfo.size(); ++i)
            {
                auto const pair = redirInfo[i]; // (victim,pct)
                Unit* redirTarget = nullptr;
                auto it = _myThreatListEntries.find(pair.first); // try to look it up in our threat list first (faster)
                if (it != _myThreatListEntries.end())
                    redirTarget = it->second->_victim;
                else
                    redirTarget = ObjectAccessor::GetUnit(*_owner, pair.first);

                if (redirTarget)
                {
                    float amountRedirected = CalculatePct(origAmount, pair.second);
                    AddThreat(redirTarget, amountRedirected, spell, true, true);
                    amount -= amountRedirected;
                }
            }
        }
    }

    // ensure we're in combat (threat implies combat!)
    if (!_owner->GetCombatManager().SetInCombatWith(target)) // if this returns false, we're not actually in combat, and thus cannot have threat!
        return;                                              // typical causes: bad scripts trying to add threat to GMs, dead targets etc

    // ok, now we actually apply threat
    // check if we already have an entry - if we do, just increase threat for that entry and we're done
    auto it = _myThreatListEntries.find(target->GetGUID());
    if (it != _myThreatListEntries.end())
    {
        it->second->AddThreat(amount);
        return;
    }

    // ok, we're now in combat - create the threat list reference and push it to the respective managers
    ThreatReference* ref = new ThreatReference(this, target, amount);
    PutThreatListRef(target->GetGUID(), ref);
    target->GetThreatManager().PutThreatenedByMeRef(_owner->GetGUID(), ref);
    if (!_ownerEngaged)
    {
        _ownerEngaged = true;

        Creature* cOwner = _owner->ToCreature();
        ASSERT(cOwner); // if we got here the owner can have a threat list, and must be a creature!
        SaveCreatureHomePositionIfNeed(cOwner);
        if (cOwner->IsAIEnabled)
            cOwner->AI()->JustEngagedWith(target);
    }
}

void ThreatManager::ScaleThreat(Unit* target, float factor)
{
    auto it = _myThreatListEntries.find(target->GetGUID());
    if (it != _myThreatListEntries.end())
        it->second->ScaleThreat(std::max<float>(factor,0.0f));
}

void ThreatManager::MatchUnitThreatToHighestThreat(Unit* target)
{
    if (_sortedThreatList.empty())
        return;

    auto it = _sortedThreatList.ordered_begin(), end = _sortedThreatList.ordered_end();
    ThreatReference const* highest = *it;
    if (!highest->IsAvailable())
        return;

    if (highest->IsTaunting() && ((++it) != end)) // might need to skip this - max threat could be the preceding element (there is only one taunt element)
    {
        ThreatReference const* a = *it;
        if (a->IsAvailable() && a->GetThreat() > highest->GetThreat())
            highest = a;
    }

    AddThreat(target, highest->GetThreat() - GetThreat(target, true), nullptr, true, true);
}

void ThreatManager::TauntUpdate()
{
    std::list<AuraEffect*> const& tauntEffects = _owner->GetAuraEffectsByType(SPELL_AURA_MOD_TAUNT);

    uint32 state = ThreatReference::TAUNT_STATE_TAUNT;
    std::unordered_map<ObjectGuid, ThreatReference::TauntState> tauntStates;
    // Only the last taunt effect applied by something still on our threat list is considered
    for (auto it = tauntEffects.begin(), end = tauntEffects.end(); it != end; ++it)
        tauntStates[(*it)->GetCasterGUID()] = ThreatReference::TauntState(state++);

    for (auto const& pair : _myThreatListEntries)
    {
        auto it = tauntStates.find(pair.first);
        if (it != tauntStates.end())
            pair.second->UpdateTauntState(it->second);
        else
            pair.second->UpdateTauntState();
    }
}

void ThreatManager::ResetAllThreat()
{
    for (auto const& pair : _myThreatListEntries)
        pair.second->SetThreat(0.0f);
}

void ThreatManager::ClearThreat(Unit* target)
{
    auto it = _myThreatListEntries.find(target->GetGUID());
    if (it != _myThreatListEntries.end())
        it->second->ClearThreat();
}

void ThreatManager::ClearAllThreat()
{
    _ownerEngaged = false;
    if (_myThreatListEntries.empty())
        return;

    SendClearAllThreatToClients();
    do
        _myThreatListEntries.begin()->second->ClearThreat(false);
    while (!_myThreatListEntries.empty());
}

void ThreatManager::FixateTarget(Unit* target)
{
    if (target)
    {
        auto it = _myThreatListEntries.find(target->GetGUID());
        if (it != _myThreatListEntries.end())
        {
            _fixateRef = it->second;
            return;
        }
    }
    _fixateRef = nullptr;
}

Unit* ThreatManager::GetFixateTarget() const
{
    if (_fixateRef)
        return _fixateRef->GetVictim();
    else
        return nullptr;
}

ThreatReference const* ThreatManager::ReselectVictim()
{
    // fixated target is always preferred
    if (_fixateRef && _fixateRef->IsAvailable())
        return _fixateRef;

    ThreatReference const* oldVictimRef = _currentVictimRef;
    if (oldVictimRef && oldVictimRef->IsOffline())
        oldVictimRef = nullptr;
    // in 99% of cases - we won't need to actually look at anything beyond the first element
    ThreatReference const* highest = _sortedThreatList.top();
    // if the highest reference is offline, the entire list is offline, and we indicate this
    if (!highest->IsAvailable())
        return nullptr;
    // if we have no old victim, or old victim is still highest, then highest is our target and we're done
    if (!oldVictimRef || highest == oldVictimRef)
        return highest;
    // if highest threat doesn't break 110% of old victim, nothing below it is going to do so either; new victim = old victim and done
    if (!ThreatManager::CompareReferencesLT(oldVictimRef, highest, 1.1f))
        return oldVictimRef;
    // if highest threat breaks 130%, it's our new target regardless of range (and we're done)
    if (ThreatManager::CompareReferencesLT(oldVictimRef, highest, 1.3f))
        return highest;
    // if it doesn't break 130%, we need to check if it's melee - if yes, it breaks 110% (we checked earlier) and is our new target
    if (_owner->IsWithinMeleeRange(highest->_victim))
        return highest;
    // If we get here, highest threat is ranged, but below 130% of current - there might be a melee that breaks 110% below us somewhere, so now we need to actually look at the next highest element
    // luckily, this is a heap, so getting the next highest element is O(log n), and we're just gonna do that repeatedly until we've seen enough targets (or find a target)
    auto it = _sortedThreatList.ordered_begin(), end = _sortedThreatList.ordered_end();
    while (it != end)
    {
        ThreatReference const* next = *it;
        // if we've found current victim, we're done (nothing above is higher, and nothing below can be higher)
        if (next == oldVictimRef)
            return next;
        // if next isn't above 110% threat, then nothing below it can be either - we're done, old victim stays
        if (!ThreatManager::CompareReferencesLT(oldVictimRef, next, 1.1f))
            return oldVictimRef;
        // if next is melee, he's above 110% and our new victim
        if (_owner->IsWithinMeleeRange(next->_victim))
            return next;
        // otherwise the next highest target may still be a melee above 110% and we need to look further
        ++it;
    }
    // we should have found the old victim at some point in the loop above, so execution should never get to this point
    ASSERT(false && "Current victim not found in sorted threat list even though it has a reference - manager desync!");
    return nullptr;
}

// returns true if a is LOWER on the threat list than b
/*static*/ bool ThreatManager::CompareReferencesLT(ThreatReference const* a, ThreatReference const* b, float aWeight)
{
    if (a->_online != b->_online) // online state precedence (ONLINE > SUPPRESSED > OFFLINE)
        return a->_online < b->_online;
    if (a->_taunted != b->_taunted) // taunt state precedence (TAUNT > NONE > DETAUNT)
        return a->_taunted < b->_taunted;
    return (a->GetThreat()*aWeight < b->GetThreat());
}

/*static*/ float ThreatManager::CalculateModifiedThreat(float threat, Unit const* victim, SpellInfo const* spell)
{
    // modifiers by spell
    if (spell)
    {
        if (SpellThreatEntry const* threatEntry = sSpellMgr->GetSpellThreatEntry(spell->Id))
            if (threatEntry->pctMod != 1.0f) // flat/AP modifiers handled in Spell::HandleThreatSpells
                threat *= threatEntry->pctMod;

        if (Player* modOwner = victim->GetSpellModOwner())
            modOwner->ApplySpellMod(spell->Id, SPELLMOD_THREAT, threat);
    }

    // modifiers by effect school
    ThreatManager const& victimMgr = victim->GetThreatManager();
    SpellSchoolMask const mask = spell ? spell->GetSchoolMask() : SPELL_SCHOOL_MASK_NORMAL;
    switch (mask)
    {
        case SPELL_SCHOOL_MASK_NORMAL:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_NORMAL];
            break;
        case SPELL_SCHOOL_MASK_HOLY:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_HOLY];
            break;
        case SPELL_SCHOOL_MASK_FIRE:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_FIRE];
            break;
        case SPELL_SCHOOL_MASK_NATURE:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_NATURE];
            break;
        case SPELL_SCHOOL_MASK_FROST:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_FROST];
            break;
        case SPELL_SCHOOL_MASK_SHADOW:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_SHADOW];
            break;
        case SPELL_SCHOOL_MASK_ARCANE:
            threat *= victimMgr._singleSchoolModifiers[SPELL_SCHOOL_ARCANE];
            break;
        default:
        {
            auto it = victimMgr._multiSchoolModifiers.find(mask);
            if (it != victimMgr._multiSchoolModifiers.end())
            {
                threat *= it->second;
                break;
            }
            float mod = victim->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_THREAT, mask);
            victimMgr._multiSchoolModifiers[mask] = mod;
            threat *= mod;
            break;
        }
    }
    return threat;
}

void ThreatManager::SendClearAllThreatToClients() const
{
    WorldPacket data(SMSG_THREAT_CLEAR, 8);
    data << _owner->GetPackGUID();
    _owner->SendMessageToSet(&data, false);
}

void ThreatManager::SendThreatListToClients() const
{
    WorldPacket data(SMSG_THREAT_UPDATE, (_sortedThreatList.size() + 1) * 8); // guess
    data << _owner->GetPackGUID();
    size_t countPos = data.wpos();
    data << uint32(0); // placeholder
    uint32 count = 0;
    for (ThreatReference const* ref : _sortedThreatList)
    {
        if (!ref->IsAvailable()) // @todo check if suppressed threat should get sent for bubble/iceblock/hop etc
            continue;
        data << ref->GetVictim()->GetPackGUID();
        data << uint32(ref->GetThreat() * 100);
        ++count;
    }
    data.put<uint32>(countPos, count);
    _owner->SendMessageToSet(&data, false);
}

void ThreatManager::ForwardThreatForAssistingMe(Unit* assistant, float baseAmount, SpellInfo const* spell, bool ignoreModifiers)
{
    if (spell && spell->HasAttribute(SPELL_ATTR1_NO_THREAT)) // shortcut, none of the calls would do anything
        return;
    if (_threatenedByMe.empty())
        return;
    float const perTarget = baseAmount / _threatenedByMe.size(); // Threat is divided evenly among all targets (LibThreat sourced)
    for (auto const& pair : _threatenedByMe)
        pair.second->GetOwner()->GetThreatManager().AddThreat(assistant, perTarget, spell, ignoreModifiers);
}

void ThreatManager::RemoveMeFromThreatLists()
{
    while (!_threatenedByMe.empty())
        _threatenedByMe.begin()->second->ClearThreat();
}

void ThreatManager::UpdateMyTempModifiers()
{
    int32 mod = 0;
    for (AuraEffect const* eff : _owner->GetAuraEffectsByType(SPELL_AURA_MOD_TOTAL_THREAT))
        mod += eff->GetAmount();

    for (auto const& pair : _threatenedByMe)
    {
        pair.second->_tempModifier = mod;
        pair.second->HeapNotifyChanged();
    }
}

void ThreatManager::UpdateMySpellSchoolModifiers()
{
    for (uint8 i = 0; i < MAX_SPELL_SCHOOL; ++i)
        _singleSchoolModifiers[i] = _owner->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_THREAT, 1 << i);
    _multiSchoolModifiers.clear();
}

void ThreatManager::RegisterRedirectThreat(uint32 spellId, ObjectGuid const& victim, uint32 pct)
{
    _redirectRegistry[spellId][victim] = pct;
    UpdateRedirectInfo();
}

void ThreatManager::UnregisterRedirectThreat(uint32 spellId)
{
    auto it = _redirectRegistry.find(spellId);
    if (it == _redirectRegistry.end())
        return;
    _redirectRegistry.erase(it);
    UpdateRedirectInfo();
}

void ThreatManager::UnregisterRedirectThreat(uint32 spellId, ObjectGuid const& victim)
{
    auto it = _redirectRegistry.find(spellId);
    if (it == _redirectRegistry.end())
        return;
    auto& victimMap = it->second;
    auto it2 = victimMap.find(victim);
    if (it2 == victimMap.end())
        return;
    victimMap.erase(it2);
    UpdateRedirectInfo();
}

void ThreatManager::SendRemoveToClients(Unit const* victim) const
{
    WorldPacket data(SMSG_THREAT_REMOVE, 16);
    data << _owner->GetPackGUID();
    data << victim->GetPackGUID();
    _owner->SendMessageToSet(&data, false);
}

void ThreatManager::SendNewVictimToClients(ThreatReference const* victimRef) const
{
    WorldPacket data(SMSG_HIGHEST_THREAT_UPDATE, (_sortedThreatList.size() + 2) * 8);
    data << _owner->GetPackGUID();
    data << victimRef->_victim->GetPackGUID();
    size_t countPos = data.wpos();
    data << uint32(0); // placeholder
    uint32 count = 0;
    for (ThreatReference const* ref : _sortedThreatList)
    {
        if (!ref->IsAvailable())
            continue;
        data << ref->GetVictim()->GetPackGUID();
        data << uint32(ref->GetThreat() * 100);
        ++count;
    }
    data.put<uint32>(countPos, count);
    _owner->SendMessageToSet(&data, false);
}

void ThreatManager::PutThreatListRef(ObjectGuid const& guid, ThreatReference* ref)
{
    auto& inMap = _myThreatListEntries[guid];
    ASSERT(!inMap, "Duplicate threat reference at %p being inserted on %s for %s - memory leak!", ref, _owner->GetGUID().ToString().c_str(), guid.ToString().c_str());
    inMap = ref;
    ref->_handle = _sortedThreatList.push(ref);
}

void ThreatManager::PurgeThreatListRef(ObjectGuid const& guid, bool sendRemove)
{
    auto it = _myThreatListEntries.find(guid);
    if (it == _myThreatListEntries.end())
        return;
    ThreatReference* ref = it->second;
    _myThreatListEntries.erase(it);

    if (_currentVictimRef == ref)
        _currentVictimRef = nullptr;
    if (_fixateRef == ref)
        _fixateRef = nullptr;

    _sortedThreatList.erase(ref->_handle);
    if (sendRemove && ref->IsAvailable())
        SendRemoveToClients(ref->_victim);
}

void ThreatManager::PutThreatenedByMeRef(ObjectGuid const& guid, ThreatReference* ref)
{
    auto& inMap = _threatenedByMe[guid];
    ASSERT(!inMap, "Duplicate threatened-by-me reference at %p being inserted on %s for %s - memory leak!", ref, _owner->GetGUID().ToString().c_str(), guid.ToString().c_str());
    inMap = ref;
}

void ThreatManager::PurgeThreatenedByMeRef(ObjectGuid const& guid)
{
    auto it = _threatenedByMe.find(guid);
    if (it != _threatenedByMe.end())
        _threatenedByMe.erase(it);
}

void ThreatManager::UpdateRedirectInfo()
{
    _redirectInfo.clear();
    uint32 totalPct = 0;
    for (auto const& pair : _redirectRegistry) // (spellid, victim -> pct)
        for (auto const& victimPair : pair.second) // (victim,pct)
        {
            uint32 thisPct = std::min<uint32>(100 - totalPct, victimPair.second);
            if (thisPct > 0)
            {
                _redirectInfo.push_back({ victimPair.first, thisPct });
                totalPct += thisPct;
                ASSERT(totalPct <= 100);
                if (totalPct == 100)
                    return;
            }
        }
}
