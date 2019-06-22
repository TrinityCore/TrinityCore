/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

 #ifndef TRINITY_THREATMANAGER_H
 #define TRINITY_THREATMANAGER_H

#include "Common.h"
#include "IteratorPair.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include <boost/heap/fibonacci_heap.hpp>
#include <array>
#include <unordered_map>
#include <vector>

class Creature;
class Unit;
class SpellInfo;

/********************************************************************************************************************************************************\
 *                                                           DEV DOCUMENTATION: THREAT SYSTEM                                                           *
 *                                            (future devs: please keep this up-to-date if you change the system)                                       *
 * The threat system works based on dynamically allocated threat list entries.                                                                          *
 *                                                                                                                                                      *
 * Each such entry is a ThreatReference object, which is always stored in exactly three places:                                                         *
 *  - The threatened unit's (from now: reference "owner") sorted and unsorted threat lists                                                              *
 *  - The threatening unit's (from now: reference "victim") threatened-by-me list                                                                       *
 * A ThreatReference object carries the following implicit guarantees:                                                                                  *
 *  - Both owner and victim are valid units, which are currently in the world. Neither can be nullptr.                                                  *
 *  - There is an active combat reference between owner and victim.                                                                                     *
 *                                                                                                                                                      *
 * Note that (threat => combat) is a strong guarantee provided in conjunction with CombatManager. Thus:                                                 *
 *  - Adding threat will also create a combat reference between the units if one doesn't exist yet (even if the owner can't have a threat list!)        *
 *  - Ending combat between two units will also delete any threat references that may exist between them.                                               *
 *                                                                                                                                                      *
 * To manage a creature's threat list, ThreatManager maintains a heap of threat reference const pointers.                                               *
 * This heap is kept well-structured in all methods that modify ThreatReference, and is used to select the next target.                                 *
 *                                                                                                                                                      *
 * Selection uses the following properties on ThreatReference, in order:                                                                                *
 * - Online state (one of ONLINE, SUPPRESSED, OFFLINE):                                                                                                 *
 *   - ONLINE:     Normal threat state, target is valid and attackable                                                                                  *
 *   - SUPPRESSED: Target is attackable, but inopportune. This is used for targets under immunity effects and damage-breaking CC.                       *
 *                 Targets with SUPPRESSED threat can still be valid targets, but any target with ONLINE threat will be preferred.                      *
 *   - OFFLINE:    The target is, for whatever reason, not valid at this time (for example, IMMUNE_TO_X flags or game master state).                    *
 *                 These targets can never be selected, and GetCurrentVictim will return nullptr if all targets are OFFLINE (typically causing evade).  *
 *   - Related methods: GetOnlineState, IsOnline, IsAvailable, IsOffline                                                                                *
 * - Taunt state (one of TAUNT, NONE, DETAUNT), the names speak for themselves                                                                          *
 *   - Related methods: GetTauntState, IsTaunting, IsDetaunted                                                                                          *
 * - Actual threat value (GetThreat)                                                                                                                    *
 *                                                                                                                                                      *
 * The current (= last selected) victim can be accessed using GetCurrentVictim.                                                                         *
 * Beyond that, ThreatManager has a variety of helpers and notifiers, which are documented inline below.                                                *
 *                                                                                                                                                      *
 * SPECIAL NOTE: Please be aware that any iterator may be invalidated if you modify a ThreatReference. The heap holds const pointers for a reason, but  *
 *                 that doesn't mean you're scot free. A variety of actions (casting spells, teleporting units, and so forth) can cause changes to      *
 *                 the threat list. Use with care - or default to GetModifiableThreatList(), which inherently copies entries.                           *
\********************************************************************************************************************************************************/

class ThreatReference;
struct CompareThreatLessThan
{
    CompareThreatLessThan() {}
    bool operator()(ThreatReference const* a, ThreatReference const* b) const;
};

// Please check Game/Combat/ThreatManager.h for documentation on how this class works!
class TC_GAME_API ThreatManager
{
    public:
        typedef boost::heap::fibonacci_heap<ThreatReference const*, boost::heap::compare<CompareThreatLessThan>> threat_list_heap;
        class ThreatListIterator;
        static const uint32 THREAT_UPDATE_INTERVAL = 1000u;

        static bool CanHaveThreatList(Unit const* who);

        ThreatManager(Unit* owner);
        ~ThreatManager();
        // called from ::Create methods just after construction (once all fields on owner have been populated)
        // should not be called from anywhere else
        void Initialize();
        // called from Creature::Update (only creatures can have their own threat list)
        // should not be called from anywhere else
        void Update(uint32 tdiff);

        // never nullptr
        Unit* GetOwner() const { return _owner; }
        // can our owner have a threat list?
        // identical to ThreatManager::CanHaveThreatList(GetOwner())
        bool CanHaveThreatList() const { return _ownerCanHaveThreatList; }
        // returns the current victim - this can be nullptr if owner's threat list is empty, or has only offline targets
        Unit* GetCurrentVictim();
        Unit* GetCurrentVictim() const;
        // returns an arbitrary non-offline victim from owner's threat list if one exists, nullptr otherwise
        Unit* GetAnyTarget() const;

        // are there any entries in owner's threat list?
        bool IsThreatListEmpty(bool includeOffline = false) const;
        // is there a threat list entry on owner's threat list with victim == who?
        bool IsThreatenedBy(ObjectGuid const& who, bool includeOffline = false) const;
        // is there a threat list entry on owner's threat list with victim == who?
        bool IsThreatenedBy(Unit const* who, bool includeOffline = false) const;
        // returns ThreatReference amount if a ref exists, 0.0f otherwise
        float GetThreat(Unit const* who, bool includeOffline = false) const;
        size_t GetThreatListSize() const { return _sortedThreatList.size(); }
        // fastest of the three threat list getters - gets the threat list in "arbitrary" order
        // iterators will invalidate on adding/removing entries from the threat list; slightly less finicky than GetSorted.
        Trinity::IteratorPair<ThreatListIterator> GetUnsortedThreatList() const { return { _myThreatListEntries.begin(), _myThreatListEntries.end() }; }
        // slightly slower than GetUnsorted, but, well...sorted - only use it if you need the sorted property, of course
        // this iterator pair will invalidate on any modification (even indirect) of the threat list; spell casts and similar can all induce this!
        // note: current tank is NOT guaranteed to be the first entry in this list - check GetCurrentVictim separately if you want that!
        Trinity::IteratorPair<threat_list_heap::ordered_iterator> GetSortedThreatList() const { return { _sortedThreatList.ordered_begin(), _sortedThreatList.ordered_end() }; }
        // slowest of the three threat list getters (by far), but lets you modify the threat references - this is also sorted
        std::vector<ThreatReference*> GetModifiableThreatList() const;

        // does any unit have a threat list entry with victim == this.owner?
        bool IsThreateningAnyone(bool includeOffline = false) const;
        // is there a threat list entry on who's threat list for this.owner?
        bool IsThreateningTo(ObjectGuid const& who, bool includeOffline = false) const;
        // is there a threat list entry on who's threat list for this.owner?
        bool IsThreateningTo(Unit const* who, bool includeOffline = false) const;
        auto const& GetThreatenedByMeList() const { return _threatenedByMe; }

        // Notify the ThreatManager that its owner may now be suppressed on others' threat lists (immunity or damage-breakable CC being applied)
        void EvaluateSuppressed(bool canExpire = false);
        ///== AFFECT MY THREAT LIST ==
        void AddThreat(Unit* target, float amount, SpellInfo const* spell = nullptr, bool ignoreModifiers = false, bool ignoreRedirects = false);
        void ScaleThreat(Unit* target, float factor);
        // Modify target's threat by +percent%
        void ModifyThreatByPercent(Unit* target, int32 percent) { if (percent) ScaleThreat(target, 0.01f*float(100 + percent)); }
        // Resets the specified unit's threat to zero
        void ResetThreat(Unit* target) { ScaleThreat(target, 0.0f); }
        // Sets the specified unit's threat to be equal to the highest entry on the threat list
        void MatchUnitThreatToHighestThreat(Unit* target);
        // Notify the ThreatManager that we have a new taunt aura (or a taunt aura expired)
        void TauntUpdate();
        // Sets all threat refs in owner's threat list to have zero threat
        void ResetAllThreat();
        // Removes specified target from the threat list
        void ClearThreat(Unit* target);
        void ClearThreat(ThreatReference* ref);
        // Removes all targets from the threat list (will cause evade in UpdateVictim if called)
        void ClearAllThreat();

        // Fixate on the passed target; this target will always be selected until the fixate is cleared
        // (if the target is not in the threat list, does nothing)
        void FixateTarget(Unit* target);
        void ClearFixate() { FixateTarget(nullptr); }
        Unit* GetFixateTarget() const;

        ///== AFFECT OTHERS' THREAT LISTS ==
        // what it says on the tin - call AddThreat on everything that's threatened by us with the specified params
        void ForwardThreatForAssistingMe(Unit* assistant, float baseAmount, SpellInfo const* spell = nullptr, bool ignoreModifiers = false);
        // delete all ThreatReferences with victim == owner
        void RemoveMeFromThreatLists();
        // re-calculates the temporary threat modifier from auras on myself
        void UpdateMyTempModifiers();
        // re-calculate SPELL_AURA_MOD_THREAT modifiers
        void UpdateMySpellSchoolModifiers();

        ///== REDIRECT SYSTEM ==
        // Register a redirection effect that redirects pct% of threat generated by owner to victim
        void RegisterRedirectThreat(uint32 spellId, ObjectGuid const& victim, uint32 pct);
        // Unregister a redirection effort for all victims
        void UnregisterRedirectThreat(uint32 spellId);
        // Unregister a redirection effect for a specific victim
        void UnregisterRedirectThreat(uint32 spellId, ObjectGuid const& victim);

    private:
        Unit* const _owner;
        bool _ownerCanHaveThreatList;

        static const CompareThreatLessThan CompareThreat;
        static bool CompareReferencesLT(ThreatReference const* a, ThreatReference const* b, float aWeight);
        static float CalculateModifiedThreat(float threat, Unit const* victim, SpellInfo const* spell);

        // send opcodes (all for my own threat list)
        void SendClearAllThreatToClients() const;
        void SendRemoveToClients(Unit const* victim) const;
        void SendThreatListToClients(bool newHighest) const;

        ///== MY THREAT LIST ==
        void PutThreatListRef(ObjectGuid const& guid, ThreatReference* ref);
        void PurgeThreatListRef(ObjectGuid const& guid);

        bool _needClientUpdate;
        uint32 _updateTimer;
        threat_list_heap _sortedThreatList;
        std::unordered_map<ObjectGuid, ThreatReference*> _myThreatListEntries;

        // picks a new victim - called from ::Update periodically
        void UpdateVictim();
        ThreatReference const* ReselectVictim();
        ThreatReference const* _currentVictimRef;
        ThreatReference const* _fixateRef;

        ///== OTHERS' THREAT LISTS ==
        void PutThreatenedByMeRef(ObjectGuid const& guid, ThreatReference* ref);
        void PurgeThreatenedByMeRef(ObjectGuid const& guid);
        std::unordered_map<ObjectGuid, ThreatReference*> _threatenedByMe; // these refs are entries for myself on other units' threat lists
        std::array<float, MAX_SPELL_SCHOOL> _singleSchoolModifiers; // most spells are single school - we pre-calculate these and store them
        mutable std::unordered_map<std::underlying_type<SpellSchoolMask>::type, float> _multiSchoolModifiers; // these are calculated on demand

        // redirect system (is kind of dumb, but that's because none of the redirection spells actually have any aura effect associated with them, so spellscript needs to deal with it)
        void UpdateRedirectInfo();
        std::vector<std::pair<ObjectGuid, uint32>> _redirectInfo; // current redirection targets and percentages (updated from registry in ThreatManager::UpdateRedirectInfo)
        std::unordered_map<uint32, std::unordered_map<ObjectGuid, uint32>> _redirectRegistry; // spellid -> (victim -> pct); all redirection effects on us (removal individually managed by spell scripts because blizzard is dumb)

    public:
        ThreatManager(ThreatManager const&) = delete;
        ThreatManager& operator=(ThreatManager const&) = delete;

        class ThreatListIterator
        {
            private:
                decltype(_myThreatListEntries)::const_iterator _it;

            public:
                ThreatReference const* operator*() const { return _it->second; }
                ThreatReference const* operator->() const { return _it->second; }
                ThreatListIterator& operator++() { ++_it; return *this; }
                bool operator==(ThreatListIterator const& o) const { return _it == o._it; }
                bool operator!=(ThreatListIterator const& o) const { return _it != o._it; }
                ThreatListIterator(decltype(_it) it) : _it(it) {}
        };

    friend class ThreatReference;
    friend struct CompareThreatLessThan;
    friend class debug_commandscript;
};

// Please check Game/Combat/ThreatManager.h for documentation on how this class works!
class TC_GAME_API ThreatReference
{
    public:
        enum TauntState : uint32 { TAUNT_STATE_DETAUNT = 0, TAUNT_STATE_NONE = 1, TAUNT_STATE_TAUNT = 2 };
        enum OnlineState { ONLINE_STATE_ONLINE = 2, ONLINE_STATE_SUPPRESSED = 1, ONLINE_STATE_OFFLINE = 0 };

        Creature* GetOwner() const { return _owner; }
        Unit* GetVictim() const { return _victim; }
        float GetThreat() const { return std::max<float>(_baseAmount + (float)_tempModifier, 0.0f); }
        OnlineState GetOnlineState() const { return _online; }
        bool IsOnline() const { return (_online >= ONLINE_STATE_ONLINE); }
        bool IsAvailable() const { return (_online > ONLINE_STATE_OFFLINE); }
        bool IsSuppressed() const { return (_online == ONLINE_STATE_SUPPRESSED); }
        bool IsOffline() const { return (_online <= ONLINE_STATE_OFFLINE); }
        TauntState GetTauntState() const { return IsTaunting() ? TAUNT_STATE_TAUNT : _taunted; }
        bool IsTaunting() const { return _taunted >= TAUNT_STATE_TAUNT; }
        bool IsDetaunted() const { return _taunted == TAUNT_STATE_DETAUNT; }

        void AddThreat(float amount);
        void ScaleThreat(float factor);
        void ModifyThreatByPercent(int32 percent) { if (percent) ScaleThreat(0.01f*float(100 + percent)); }
        void UpdateOffline();

        void ClearThreat(); // dealloc's this

    private:
        static bool FlagsAllowFighting(Unit const* a, Unit const* b);

        ThreatReference(ThreatManager* mgr, Unit* victim) :
            _owner(reinterpret_cast<Creature*>(mgr->_owner)), _mgr(*mgr), _victim(victim),
            _baseAmount(0.0f), _tempModifier(0), _taunted(TAUNT_STATE_NONE)
        {
            _online = ShouldBeSuppressed() ? ONLINE_STATE_SUPPRESSED : ONLINE_STATE_ONLINE;
        }

        void UnregisterAndFree();

        bool ShouldBeOffline() const;
        bool ShouldBeSuppressed() const;
        void UpdateTauntState(TauntState state = TAUNT_STATE_NONE);
        Creature* const _owner;
        ThreatManager& _mgr;
        void HeapNotifyIncreased() { _mgr._sortedThreatList.increase(_handle); }
        void HeapNotifyDecreased() { _mgr._sortedThreatList.decrease(_handle); }
        Unit* const _victim;
        OnlineState _online;
        float _baseAmount;
        int32 _tempModifier; // Temporary effects (auras with SPELL_AURA_MOD_TOTAL_THREAT) - set from victim's threatmanager in ThreatManager::UpdateMyTempModifiers
        TauntState _taunted;
        ThreatManager::threat_list_heap::handle_type _handle;

    public:
        ThreatReference(ThreatReference const&) = delete;
        ThreatReference& operator=(ThreatReference const&) = delete;

    friend class ThreatManager;
    friend struct CompareThreatLessThan;
};

inline bool CompareThreatLessThan::operator()(ThreatReference const* a, ThreatReference const* b) const { return ThreatManager::CompareReferencesLT(a, b, 1.0f); }

 #endif
