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

#ifndef TRINITY_UNITAI_H
#define TRINITY_UNITAI_H

#include "Containers.h"
#include "Errors.h"
#include "EventMap.h"
#include "ObjectGuid.h"
#include "SpellDefines.h"
#include "ThreatManager.h"

#define CAST_AI(a, b)   (dynamic_cast<a*>(b))
#define ENSURE_AI(a,b)  (EnsureAI<a>(b))

template<class T, class U>
T* EnsureAI(U* ai)
{
    T* cast_ai = dynamic_cast<T*>(ai);
    ASSERT(cast_ai);
    return cast_ai;
};

class Player;
class Quest;
class SpellInfo;
class Unit;
struct AISpellInfoType;
enum DamageEffectType : uint8;
enum SpellEffIndex : uint8;

//Selection method used by SelectTarget
enum SelectAggroTarget
{
    SELECT_TARGET_RANDOM = 0,  // just pick a random target
    SELECT_TARGET_MAXTHREAT,   // prefer targets higher in the threat list
    SELECT_TARGET_MINTHREAT,   // prefer targets lower in the threat list
    SELECT_TARGET_MAXDISTANCE, // prefer targets further from us
    SELECT_TARGET_MINDISTANCE  // prefer targets closer to us
};

// default predicate function to select target based on distance, player and/or aura criteria
struct TC_GAME_API DefaultTargetSelector
{
    Unit const* me;
    float m_dist;
    bool m_playerOnly;
    Unit const* except;
    int32 m_aura;

    // unit: the reference unit
    // dist: if 0: ignored, if > 0: maximum distance to the reference unit, if < 0: minimum distance to the reference unit
    // playerOnly: self explaining
    // withMainTank: allow current tank to be selected
    // aura: if 0: ignored, if > 0: the target shall have the aura, if < 0, the target shall NOT have the aura
    DefaultTargetSelector(Unit const* unit, float dist, bool playerOnly, bool withMainTank, int32 aura);
    bool operator()(Unit const* target) const;
};

// Target selector for spell casts checking range, auras and attributes
/// @todo Add more checks from Spell::CheckCast
struct TC_GAME_API SpellTargetSelector
{
    public:
        SpellTargetSelector(Unit* caster, uint32 spellId);
        bool operator()(Unit const* target) const;

    private:
        Unit const* _caster;
        SpellInfo const* _spellInfo;
};

// Very simple target selector, will just skip main target
// NOTE: When passing to UnitAI::SelectTarget remember to use 0 as position for random selection
//       because tank will not be in the temporary list
struct TC_GAME_API NonTankTargetSelector
{
    public:
        NonTankTargetSelector(Unit* source, bool playerOnly = true) : _source(source), _playerOnly(playerOnly) { }
        bool operator()(Unit const* target) const;

    private:
        Unit* _source;
        bool _playerOnly;
};

// Simple selector for units using mana
struct TC_GAME_API PowerUsersSelector
{
    public:
        PowerUsersSelector(Unit const* unit, Powers power, float dist, bool playerOnly) : _me(unit), _power(power), _dist(dist), _playerOnly(playerOnly) { }
        bool operator()(Unit const* target) const;

    private:
        Unit const* _me;
        Powers const _power;
        float const _dist;
        bool const _playerOnly;
};

struct TC_GAME_API FarthestTargetSelector
{
    public:
        FarthestTargetSelector(Unit const* unit, float dist, bool playerOnly, bool inLos) : _me(unit), _dist(dist), _playerOnly(playerOnly), _inLos(inLos) {}
        bool operator()(Unit const* target) const;

    private:
        Unit const* _me;
        float _dist;
        bool _playerOnly;
        bool _inLos;
};

class TC_GAME_API UnitAI
{
    protected:
        Unit* const me;
    public:
        explicit UnitAI(Unit* unit) : me(unit) { }
        virtual ~UnitAI() { }

        virtual bool CanAIAttack(Unit const* /*target*/) const { return true; }
        virtual void AttackStart(Unit* /*target*/);
        virtual void UpdateAI(uint32 diff) = 0;

        virtual void InitializeAI();

        virtual void Reset() { }

        // Called when unit is charmed
        virtual void OnCharmed(bool apply) = 0;

        // Pass parameters between AI
        virtual void DoAction(int32 /*param*/) { }
        virtual uint32 GetData(uint32 /*id = 0*/) const { return 0; }
        virtual void SetData(uint32 /*id*/, uint32 /*value*/) { }
        virtual void SetGUID(ObjectGuid const& /*guid*/, int32 /*id*/ = 0) { }
        virtual ObjectGuid GetGUID(int32 /*id*/ = 0) const { return ObjectGuid::Empty; }

        // Select the best target (in <targetType> order) from the threat list that fulfill the following:
        // - Not among the first <offset> entries in <targetType> order (or MAXTHREAT order, if <targetType> is RANDOM).
        // - Within at most <dist> yards (if dist > 0.0f)
        // - At least -<dist> yards away (if dist < 0.0f)
        // - Is a player (if playerOnly = true)
        // - Not the current tank (if withTank = false)
        // - Has aura with ID <aura> (if aura > 0)
        // - Does not have aura with ID -<aura> (if aura < 0)
        Unit* SelectTarget(SelectAggroTarget targetType, uint32 offset = 0, float dist = 0.0f, bool playerOnly = false, bool withTank = true, int32 aura = 0);
        // Select the best target (in <targetType> order) satisfying <predicate> from the threat list.
        // If <offset> is nonzero, the first <offset> entries in <targetType> order (or MAXTHREAT order, if <targetType> is RANDOM) are skipped.
        template<class PREDICATE>
        Unit* SelectTarget(SelectAggroTarget targetType, uint32 offset, PREDICATE const& predicate)
        {
            ThreatManager& mgr = GetThreatManager();
            // shortcut: if we ignore the first <offset> elements, and there are at most <offset> elements, then we ignore ALL elements
            if (mgr.GetThreatListSize() <= offset)
                return nullptr;

            std::list<Unit*> targetList;
            SelectTargetList(targetList, mgr.GetThreatListSize(), targetType, offset, predicate);

            // maybe nothing fulfills the predicate
            if (targetList.empty())
                return nullptr;

            switch (targetType)
            {
                case SELECT_TARGET_MAXTHREAT:
                case SELECT_TARGET_MINTHREAT:
                case SELECT_TARGET_MAXDISTANCE:
                case SELECT_TARGET_MINDISTANCE:
                    return targetList.front();
                case SELECT_TARGET_RANDOM:
                    return Trinity::Containers::SelectRandomContainerElement(targetList);
                default:
                    return nullptr;
            }
        }

        // Select the best (up to) <num> targets (in <targetType> order) from the threat list that fulfill the following:
        // - Not among the first <offset> entries in <targetType> order (or MAXTHREAT order, if <targetType> is RANDOM).
        // - Within at most <dist> yards (if dist > 0.0f)
        // - At least -<dist> yards away (if dist < 0.0f)
        // - Is a player (if playerOnly = true)
        // - Not the current tank (if withTank = false)
        // - Has aura with ID <aura> (if aura > 0)
        // - Does not have aura with ID -<aura> (if aura < 0)
        // The resulting targets are stored in <targetList> (which is cleared first).
        void SelectTargetList(std::list<Unit*>& targetList, uint32 num, SelectAggroTarget targetType, uint32 offset = 0, float dist = 0.0f, bool playerOnly = false, bool withTank = true, int32 aura = 0);

        // Select the best (up to) <num> targets (in <targetType> order) satisfying <predicate> from the threat list and stores them in <targetList> (which is cleared first).
        // If <offset> is nonzero, the first <offset> entries in <targetType> order (or MAXTHREAT order, if <targetType> is RANDOM) are skipped.
        template <class PREDICATE>
        void SelectTargetList(std::list<Unit*>& targetList, uint32 num, SelectAggroTarget targetType, uint32 offset, PREDICATE const& predicate)
        {
            targetList.clear();
            ThreatManager& mgr = GetThreatManager();
            // shortcut: we're gonna ignore the first <offset> elements, and there's at most <offset> elements, so we ignore them all - nothing to do here
            if (mgr.GetThreatListSize() <= offset)
                return;

            if (targetType == SELECT_TARGET_MAXDISTANCE || targetType == SELECT_TARGET_MINDISTANCE)
            {
                for (ThreatReference const* ref : mgr.GetUnsortedThreatList())
                {
                    if (ref->IsOffline())
                        continue;

                    targetList.push_back(ref->GetVictim());
                }
            }
            else
            {
                Unit* currentVictim = mgr.GetCurrentVictim();
                if (currentVictim)
                    targetList.push_back(currentVictim);

                for (ThreatReference const* ref : mgr.GetSortedThreatList())
                {
                    if (ref->IsOffline())
                        continue;

                    Unit* thisTarget = ref->GetVictim();
                    if (thisTarget != currentVictim)
                        targetList.push_back(thisTarget);
                }
            }

            // shortcut: the list isn't gonna get any larger
            if (targetList.size() <= offset)
            {
                targetList.clear();
                return;
            }

            // right now, list is unsorted for DISTANCE types - re-sort by MAXDISTANCE
            if (targetType == SELECT_TARGET_MAXDISTANCE || targetType == SELECT_TARGET_MINDISTANCE)
                SortByDistance(targetList, targetType == SELECT_TARGET_MINDISTANCE);

            // now the list is MAX sorted, reverse for MIN types
            if (targetType == SELECT_TARGET_MINTHREAT)
                targetList.reverse();

            // ignore the first <offset> elements
            while (offset)
            {
                targetList.pop_front();
                --offset;
            }

            // then finally filter by predicate
            targetList.remove_if([&predicate](Unit* target) { return !predicate(target); });

            if (targetList.size() <= num)
                return;

            if (targetType == SELECT_TARGET_RANDOM)
                Trinity::Containers::RandomResize(targetList, num);
            else
                targetList.resize(num);
        }

        // Called when the unit enters combat
        // (NOTE: Creature engage logic should NOT be here, but in JustEngagedWith, which happens once threat is established!)
        virtual void JustEnteredCombat(Unit* /*who*/) { }

        // Called when the unit leaves combat
        virtual void JustExitedCombat() { }

        // Called when the unit is about to be removed from the world (despawn, grid unload, corpse disappearing, player logging out etc.)
        virtual void LeavingWorld() { }

        // Called at any Damage to any victim (before damage apply)
        virtual void DamageDealt(Unit* /*victim*/, uint32& /*damage*/, DamageEffectType /*damageType*/) { }

        // Called at any Damage from any attacker (before damage apply)
        // Note: it for recalculation damage or special reaction at damage
        virtual void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) { }

        // Called when the creature receives heal
        virtual void HealReceived(Unit* /*done_by*/, uint32& /*addhealth*/) { }

        // Called when the unit heals
        virtual void HealDone(Unit* /*done_to*/, uint32& /*addhealth*/) { }

        /// Called when a spell is interrupted by Spell::EffectInterruptCast
        /// Use to reschedule next planned cast of spell.
        virtual void SpellInterrupted(uint32 /*spellId*/, uint32 /*unTimeMs*/) { }

        void AttackStartCaster(Unit* victim, float dist);

        void DoCast(uint32 spellId);
        void DoCast(Unit* victim, uint32 spellId, CastSpellExtraArgs const& args = {});
        void DoCastSelf(uint32 spellId, CastSpellExtraArgs const& args = {}) { DoCast(me, spellId, args); }
        void DoCastVictim(uint32 spellId, CastSpellExtraArgs const& args = {});
        void DoCastAOE(uint32 spellId, CastSpellExtraArgs const& args = {}) { DoCast(nullptr, spellId, args); }

        float DoGetSpellMaxRange(uint32 spellId, bool positive = false);

        virtual bool ShouldSparWith(Unit const* /*target*/) const { return false; }

        void DoMeleeAttackIfReady();
        bool DoSpellAttackIfReady(uint32 spell);

        static AISpellInfoType* AISpellInfo;
        static void FillAISpellInfo();

        // Called when a game event starts or ends
        virtual void OnGameEvent(bool /*start*/, uint16 /*eventId*/) { }

    private:
        UnitAI(UnitAI const& right) = delete;
        UnitAI& operator=(UnitAI const& right) = delete;

        ThreatManager& GetThreatManager();
        void SortByDistance(std::list<Unit*> list, bool ascending = true);
};

#endif
