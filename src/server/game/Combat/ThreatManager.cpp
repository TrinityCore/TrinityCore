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

#include "ThreatManager.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "MotionMaster.h"
#include "Player.h"
#include "TemporarySummon.h"
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
    _mgr._needClientUpdate = true;
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
    _mgr._needClientUpdate = true;
}

void ThreatReference::UpdateOffline()
{
    bool const shouldBeOffline = ShouldBeOffline();
    if (shouldBeOffline == IsOffline())
        return;

    if (shouldBeOffline)
    {
        _online = ONLINE_STATE_OFFLINE;
        HeapNotifyDecreased();
        _mgr.SendRemoveToClients(_victim);
    }
    else
    {
        _online = ShouldBeSuppressed() ? ONLINE_STATE_SUPPRESSED : ONLINE_STATE_ONLINE;
        HeapNotifyIncreased();
        _mgr.RegisterForAIUpdate(this);
    }
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

bool ThreatReference::ShouldBeOffline() const
{
    if (!_owner->CanSeeOrDetect(_victim))
        return true;
    if (!_owner->_IsTargetAcceptable(_victim) || !_owner->CanCreatureAttack(_victim))
        return true;
    if (!FlagsAllowFighting(_owner, _victim) || !FlagsAllowFighting(_victim, _owner))
        return true;
    return false;
}

bool ThreatReference::ShouldBeSuppressed() const
{
    if (IsTaunting()) // a taunting victim can never be suppressed
        return false;
    if (_victim->IsImmunedToDamage(_owner->GetMeleeDamageSchoolMask()))
        return true;
    if (_victim->HasAuraType(SPELL_AURA_MOD_CONFUSE))
        return true;
    if (_victim->HasBreakableByDamageAuraType(SPELL_AURA_MOD_STUN))
        return true;
    return false;
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

    _mgr._needClientUpdate = true;
}

void ThreatReference::ClearThreat()
{
    _mgr.ClearThreat(this);
}

void ThreatReference::UnregisterAndFree()
{
    _owner->GetThreatManager().PurgeThreatListRef(_victim->GetGUID());
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

    // summons cannot have a threat list if they were summoned by a player
    if (cWho->HasUnitTypeMask(UNIT_MASK_MINION | UNIT_MASK_GUARDIAN))
        if (TempSummon const* tWho = cWho->ToTempSummon())
            if (tWho->GetSummonerGUID().IsPlayer())
                return false;

    return true;
}

ThreatManager::ThreatManager(Unit* owner) : _owner(owner), _ownerCanHaveThreatList(false), _needClientUpdate(false), _updateTimer(THREAT_UPDATE_INTERVAL), _currentVictimRef(nullptr), _fixateRef(nullptr)
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
    if (!CanHaveThreatList() || IsThreatListEmpty(true))
        return;
    if (_updateTimer <= tdiff)
    {
        UpdateVictim();
        _updateTimer = THREAT_UPDATE_INTERVAL;
    }
    else
        _updateTimer -= tdiff;
}

Unit* ThreatManager::GetCurrentVictim()
{
    if (!_currentVictimRef || _currentVictimRef->ShouldBeOffline())
        UpdateVictim();
    ASSERT(!_currentVictimRef || _currentVictimRef->IsAvailable());
    return _currentVictimRef ? _currentVictimRef->GetVictim() : nullptr;
}

Unit* ThreatManager::GetLastVictim() const
{
    if (_currentVictimRef && !_currentVictimRef->ShouldBeOffline())
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

std::vector<ThreatReference*> ThreatManager::GetModifiableThreatList()
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

void ThreatManager::EvaluateSuppressed(bool canExpire)
{
    for (auto const& pair : _threatenedByMe)
    {
        bool const shouldBeSuppressed = pair.second->ShouldBeSuppressed();
        if (pair.second->IsOnline() && shouldBeSuppressed)
        {
            pair.second->_online = ThreatReference::ONLINE_STATE_SUPPRESSED;
            pair.second->HeapNotifyDecreased();
        }
        else if (canExpire && pair.second->IsSuppressed() && !shouldBeSuppressed)
        {
            pair.second->_online = ThreatReference::ONLINE_STATE_ONLINE;
            pair.second->HeapNotifyIncreased();
        }
    }
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
        ThreatReference* const ref = it->second;
        // SUPPRESSED threat states don't go back to ONLINE until threat is caused by them (retail behavior)
        if (ref->GetOnlineState() == ThreatReference::ONLINE_STATE_SUPPRESSED)
            if (!ref->ShouldBeSuppressed())
            {
                ref->_online = ThreatReference::ONLINE_STATE_ONLINE;
                ref->HeapNotifyIncreased();
            }

        if (ref->IsOnline())
            ref->AddThreat(amount);
        return;
    }

    // ok, we're now in combat - create the threat list reference and push it to the respective managers
    ThreatReference* ref = new ThreatReference(this, target);
    PutThreatListRef(target->GetGUID(), ref);
    target->GetThreatManager().PutThreatenedByMeRef(_owner->GetGUID(), ref);

    ref->UpdateOffline();
    if (ref->IsOnline()) // we only add the threat if the ref is currently available
        ref->AddThreat(amount);

    if (!_currentVictimRef)
        UpdateVictim();
    else
        ProcessAIUpdates();
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

    // taunt aura update also re-evaluates all suppressed states (retail behavior)
    EvaluateSuppressed(true);
}

void ThreatManager::ResetAllThreat()
{
    for (auto const& pair : _myThreatListEntries)
        pair.second->ScaleThreat(0.0f);
}

void ThreatManager::ClearThreat(Unit* target)
{
    auto it = _myThreatListEntries.find(target->GetGUID());
    if (it != _myThreatListEntries.end())
        ClearThreat(it->second);
}

void ThreatManager::ClearThreat(ThreatReference* ref)
{
    SendRemoveToClients(ref->_victim);
    ref->UnregisterAndFree();
    if (!_currentVictimRef)
        UpdateVictim();
}

void ThreatManager::ClearAllThreat()
{
    if (!_myThreatListEntries.empty())
    {
        SendClearAllThreatToClients();
        do
            _myThreatListEntries.begin()->second->UnregisterAndFree();
        while (!_myThreatListEntries.empty());
    }
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

void ThreatManager::UpdateVictim()
{
    ThreatReference const* const newVictim = ReselectVictim();
    bool const newHighest = newVictim && (newVictim != _currentVictimRef);

    _currentVictimRef = newVictim;
    if (newHighest || _needClientUpdate)
    {
        SendThreatListToClients(newHighest);
        _needClientUpdate = false;
    }

    ProcessAIUpdates();
}

ThreatReference const* ThreatManager::ReselectVictim()
{
    if (_sortedThreatList.empty())
        return nullptr;

    for (auto const& pair : _myThreatListEntries)
        pair.second->UpdateOffline(); // AI notifies are processed in ::UpdateVictim caller

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
    ASSERT(false, "Current victim not found in sorted threat list even though it has a reference - manager desync!");
    return nullptr;
}

void ThreatManager::ProcessAIUpdates()
{
    CreatureAI* ai = ASSERT_NOTNULL(_owner->ToCreature())->AI();
    std::vector<ThreatReference const*> v(std::move(_needsAIUpdate)); // _needsAIUpdate is now empty in case this triggers a recursive call
    if (!ai)
        return;
    for (ThreatReference const* ref : v)
        ai->JustStartedThreateningMe(ref->GetVictim());
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

void ThreatManager::ForwardThreatForAssistingMe(Unit* assistant, float baseAmount, SpellInfo const* spell, bool ignoreModifiers)
{
    if (spell && spell->HasAttribute(SPELL_ATTR1_NO_THREAT)) // shortcut, none of the calls would do anything
        return;
    if (_threatenedByMe.empty())
        return;

    std::vector<Creature*> canBeThreatened, cannotBeThreatened;
    for (auto const& pair : _threatenedByMe)
    {
        Creature* owner = pair.second->GetOwner();
        if (!owner->HasUnitState(UNIT_STATE_CONTROLLED))
            canBeThreatened.push_back(owner);
        else
            cannotBeThreatened.push_back(owner);
    }

    if (!canBeThreatened.empty()) // targets under CC cannot gain assist threat - split evenly among the rest
    {
        float const perTarget = baseAmount / canBeThreatened.size();
        for (Creature* threatened : canBeThreatened)
            threatened->GetThreatManager().AddThreat(assistant, perTarget, spell, ignoreModifiers);
    }

    for (Creature* threatened : cannotBeThreatened)
        threatened->GetThreatManager().AddThreat(assistant, 0.0f, spell, true);
}

void ThreatManager::RemoveMeFromThreatLists()
{
    while (!_threatenedByMe.empty())
    {
        auto& ref = _threatenedByMe.begin()->second;
        ref->_mgr.ClearThreat(_owner);
    }
}

void ThreatManager::UpdateMyTempModifiers()
{
    int32 mod = 0;
    for (AuraEffect const* eff : _owner->GetAuraEffectsByType(SPELL_AURA_MOD_TOTAL_THREAT))
        mod += eff->GetAmount();

    if (_threatenedByMe.empty())
        return;

    auto it = _threatenedByMe.begin();
    bool const isIncrease = (it->second->_tempModifier < mod);
    do
    {
        it->second->_tempModifier = mod;
        if (isIncrease)
            it->second->HeapNotifyIncreased();
        else
            it->second->HeapNotifyDecreased();
    } while ((++it) != _threatenedByMe.end());
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

void ThreatManager::SendClearAllThreatToClients() const
{
    WorldPacket data(SMSG_THREAT_CLEAR, 8);
    data << _owner->GetPackGUID();
    _owner->SendMessageToSet(&data, false);
}

void ThreatManager::SendRemoveToClients(Unit const* victim) const
{
    WorldPacket data(SMSG_THREAT_REMOVE, 16);
    data << _owner->GetPackGUID();
    data << victim->GetPackGUID();
    _owner->SendMessageToSet(&data, false);
}

void ThreatManager::SendThreatListToClients(bool newHighest) const
{
    WorldPacket data(newHighest ? SMSG_HIGHEST_THREAT_UPDATE : SMSG_THREAT_UPDATE, (_sortedThreatList.size() + 2) * 8); // guess
    data << _owner->GetPackGUID();
    if (newHighest)
        data << _currentVictimRef->GetVictim()->GetPackGUID();
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
    _needClientUpdate = true;
    auto& inMap = _myThreatListEntries[guid];
    ASSERT(!inMap, "Duplicate threat reference at %p being inserted on %s for %s - memory leak!", ref, _owner->GetGUID().ToString().c_str(), guid.ToString().c_str());
    inMap = ref;
    ref->_handle = _sortedThreatList.push(ref);
}

void ThreatManager::PurgeThreatListRef(ObjectGuid const& guid)
{
    auto it = _myThreatListEntries.find(guid);
    if (it == _myThreatListEntries.end())
        return;
    ThreatReference* ref = it->second;
    _myThreatListEntries.erase(it);
    _sortedThreatList.erase(ref->_handle);

    if (_fixateRef == ref)
        _fixateRef = nullptr;
    if (_currentVictimRef == ref)
        _currentVictimRef = nullptr;
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
