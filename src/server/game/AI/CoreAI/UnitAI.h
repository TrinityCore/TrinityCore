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

#ifndef TRINITY_UNITAI_H
#define TRINITY_UNITAI_H

#include "Containers.h"
#include "EventMap.h"
#include "ObjectGuid.h"
#include "ThreatManager.h"

#define CAST_AI(a, b)   (dynamic_cast<a*>(b))
#define ENSURE_AI(a,b)  (EnsureAI<a>(b))

template<class T, class U>
inline T* EnsureAI(U* ai)
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
    SELECT_TARGET_RANDOM = 0,                               //Just selects a random target
    SELECT_TARGET_TOPAGGRO,                                 //Selects targes from top aggro to bottom
    SELECT_TARGET_BOTTOMAGGRO,                              //Selects targets from bottom aggro to top
    SELECT_TARGET_NEAREST,
    SELECT_TARGET_FARTHEST
};

// default predicate function to select target based on distance, player and/or aura criteria
struct TC_GAME_API DefaultTargetSelector
{
    Unit const* me;
    float m_dist;
    bool m_playerOnly;
    int32 m_aura;

    // unit: the reference unit
    // dist: if 0: ignored, if > 0: maximum distance to the reference unit, if < 0: minimum distance to the reference unit
    // playerOnly: self explaining
    // aura: if 0: ignored, if > 0: the target shall have the aura, if < 0, the target shall NOT have the aura
    DefaultTargetSelector(Unit const* unit, float dist, bool playerOnly, int32 aura) : me(unit), m_dist(dist), m_playerOnly(playerOnly), m_aura(aura) { }

    bool operator()(Unit const* target) const;
};

// Target selector for spell casts checking range, auras and attributes
/// @todo Add more checks from Spell::CheckCast
struct TC_GAME_API SpellTargetSelector : public std::unary_function<Unit*, bool>
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
struct TC_GAME_API NonTankTargetSelector : public std::unary_function<Unit*, bool>
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
    const Unit* _me;
    float _dist;
    bool _playerOnly;
    bool _inLos;
};

TC_GAME_API void SortByDistanceTo(Unit* reference, std::list<Unit*>& targets);

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
        virtual void SetGUID(ObjectGuid /*guid*/, int32 /*id*/ = 0) { }
        virtual ObjectGuid GetGUID(int32 /*id*/ = 0) const { return ObjectGuid::Empty; }

        Unit* SelectTarget(SelectAggroTarget targetType, uint32 position = 0, float dist = 0.0f, bool playerOnly = false, int32 aura = 0);
        // Select the targets satisfying the predicate.
        template<class PREDICATE>
        Unit* SelectTarget(SelectAggroTarget targetType, uint32 position, PREDICATE const& predicate)
        {
            ThreatContainer::StorageType const& threatlist = GetThreatManager().getThreatList();
            if (position >= threatlist.size())
                return nullptr;

            std::list<Unit*> targetList;
            Unit* currentVictim = nullptr;
            if (auto currentVictimReference = GetThreatManager().getCurrentVictim())
            {
                currentVictim = currentVictimReference->getTarget();

                // Current victim always goes first
                if (currentVictim && predicate(currentVictim))
                    targetList.push_back(currentVictim);
            }

            for (HostileReference* hostileRef : threatlist)
            {
                if (currentVictim != nullptr && hostileRef->getTarget() != currentVictim && predicate(hostileRef->getTarget()))
                    targetList.push_back(hostileRef->getTarget());
                else if (currentVictim == nullptr && predicate(hostileRef->getTarget()))
                    targetList.push_back(hostileRef->getTarget());
            }

            if (position >= targetList.size())
                return nullptr;

            if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
                SortByDistanceTo(me, targetList);

            switch (targetType)
            {
                case SELECT_TARGET_NEAREST:
                case SELECT_TARGET_TOPAGGRO:
                {
                    auto itr = targetList.begin();
                    std::advance(itr, position);
                    return *itr;
                }
                case SELECT_TARGET_FARTHEST:
                case SELECT_TARGET_BOTTOMAGGRO:
                {
                    auto ritr = targetList.rbegin();
                    std::advance(ritr, position);
                    return *ritr;
                }
                case SELECT_TARGET_RANDOM:
                    return Trinity::Containers::SelectRandomContainerElement(targetList);
                default:
                    break;
            }

            return nullptr;
        }

        void SelectTargetList(std::list<Unit*>& targetList, uint32 num, SelectAggroTarget targetType, float dist = 0.0f, bool playerOnly = false, int32 aura = 0);

        // Select the targets satifying the predicate.
        template <class PREDICATE>
        void SelectTargetList(std::list<Unit*>& targetList, PREDICATE const& predicate, uint32 maxTargets, SelectAggroTarget targetType)
        {
            ThreatContainer::StorageType const& threatlist = GetThreatManager().getThreatList();
            if (threatlist.empty())
                return;

            for (HostileReference* hostileRef : threatlist)
                if (predicate(hostileRef->getTarget()))
                    targetList.push_back(hostileRef->getTarget());

            if (targetList.size() < maxTargets)
                return;

            if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
                SortByDistanceTo(me, targetList);

            if (targetType == SELECT_TARGET_FARTHEST || targetType == SELECT_TARGET_BOTTOMAGGRO)
                targetList.reverse();

            if (targetType == SELECT_TARGET_RANDOM)
                Trinity::Containers::RandomResize(targetList, maxTargets);
            else
                targetList.resize(maxTargets);
        }

        // Called at any Damage to any victim (before damage apply)
        virtual void DamageDealt(Unit* /*victim*/, uint32& /*damage*/, DamageEffectType /*damageType*/) { }

        // Called at any Damage from any attacker (before damage apply)
        // Note: it for recalculation damage or special reaction at damage
        // for attack reaction use AttackedBy called for not DOT damage in Unit::DealDamage also
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
        void DoCast(Unit* victim, uint32 spellId, bool triggered = false);
        void DoCastSelf(uint32 spellId, bool triggered = false) { DoCast(me, spellId, triggered); }
        void DoCastVictim(uint32 spellId, bool triggered = false);
        void DoCastAOE(uint32 spellId, bool triggered = false);

        void DoMeleeAttackIfReady();
        bool DoSpellAttackIfReady(uint32 spellId);

        static AISpellInfoType* AISpellInfo;
        static void FillAISpellInfo();

        virtual void sGossipHello(Player* /*player*/) { }
        virtual void sGossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) { }
        virtual void sGossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, char const* /*code*/) { }
        virtual void sQuestAccept(Player* /*player*/, Quest const* /*quest*/) { }
        virtual void sQuestSelect(Player* /*player*/, Quest const* /*quest*/) { }
        virtual void sQuestReward(Player* /*player*/, Quest const* /*quest*/, uint32 /*opt*/) { }
        virtual bool sOnDummyEffect(Unit* /*caster*/, uint32 /*spellId*/, SpellEffIndex /*effIndex*/) { return false; }
        virtual void sOnGameEvent(bool /*start*/, uint16 /*eventId*/) { }

    private:
        UnitAI(UnitAI const& right) = delete;
        UnitAI& operator=(UnitAI const& right) = delete;

        ThreatManager& GetThreatManager();
};

#endif
