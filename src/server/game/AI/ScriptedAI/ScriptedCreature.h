/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef SCRIPTEDCREATURE_H_
#define SCRIPTEDCREATURE_H_

#include "CreatureAI.h"
#include "Creature.h" // convenience include for scripts, all uses of ScriptedCreature also need Creature (except ScriptedCreature itself doesn't need Creature)
#include "DBCEnums.h"
#include "TaskScheduler.h"

class InstanceScript;

class TC_GAME_API SummonList
{
public:
    typedef GuidList StorageType;
    typedef StorageType::iterator iterator;
    typedef StorageType::const_iterator const_iterator;
    typedef StorageType::size_type size_type;
    typedef StorageType::value_type value_type;

    explicit SummonList(Creature* creature)
        : me(creature)
    { }

    // And here we see a problem of original inheritance approach. People started
    // to exploit presence of std::list members, so I have to provide wrappers

    iterator begin()
    {
        return storage_.begin();
    }

    const_iterator begin() const
    {
        return storage_.begin();
    }

    iterator end()
    {
        return storage_.end();
    }

    const_iterator end() const
    {
        return storage_.end();
    }

    iterator erase(iterator i)
    {
        return storage_.erase(i);
    }

    bool empty() const
    {
        return storage_.empty();
    }

    size_type size() const
    {
        return storage_.size();
    }

    // Clear the underlying storage. This does NOT despawn the creatures - use DespawnAll for that!
    void clear()
    {
        storage_.clear();
    }

    void Summon(Creature const* summon);
    void Despawn(Creature const* summon);
    void DespawnEntry(uint32 entry);
    void DespawnAll();

    template <typename T>
    void DespawnIf(T const &predicate)
    {
        storage_.remove_if(predicate);
    }

    template <class Predicate>
    void DoAction(int32 info, Predicate&& predicate, uint16 max = 0)
    {
        // We need to use a copy of SummonList here, otherwise original SummonList would be modified
        StorageType listCopy = storage_;
        Trinity::Containers::RandomResize<StorageType, Predicate>(listCopy, std::forward<Predicate>(predicate), max);
        DoActionImpl(info, listCopy);
    }

    void DoZoneInCombat(uint32 entry = 0, float maxRangeToNearestTarget = 250.0f);
    void RemoveNotExisting();
    bool HasEntry(uint32 entry) const;

private:
    void DoActionImpl(int32 action, StorageType const& summons);

    Creature* me;
    StorageType storage_;
};

class TC_GAME_API EntryCheckPredicate
{
    public:
        EntryCheckPredicate(uint32 entry) : _entry(entry) { }
        bool operator()(ObjectGuid const& guid) const { return guid.GetEntry() == _entry; }

    private:
        uint32 _entry;
};

class TC_GAME_API DummyEntryCheckPredicate
{
    public:
        bool operator()(ObjectGuid const&) const { return true; }
};

struct TC_GAME_API ScriptedAI : public CreatureAI
{
    explicit ScriptedAI(Creature* creature);
    virtual ~ScriptedAI() { }

    // *************
    //CreatureAI Functions
    // *************

    void AttackStartNoMove(Unit* target);

    // Called at any Damage from any attacker (before damage apply)
    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override { }

    //Called at World update tick
    virtual void UpdateAI(uint32 diff) override;

    //Called at creature death
    void JustDied(Unit* /*killer*/) override { }

    //Called at creature killing another unit
    void KilledUnit(Unit* /*victim*/) override { }

    // Called when the creature summon successfully other creature
    void JustSummoned(Creature* /*summon*/) override { }

    // Called when a summoned creature is despawned
    void SummonedCreatureDespawn(Creature* /*summon*/) override { }

    // Called when hit by a spell
    void SpellHit(Unit* /*caster*/, SpellInfo const* /*spell*/) override { }

    // Called when spell hits a target
    void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) override { }

    // Called when AI is temporarily replaced or put back when possess is applied or removed
    void OnPossess(bool /*apply*/) { }

    // *************
    // Variables
    // *************

    //For fleeing
    bool IsFleeing;

    // *************
    //Pure virtual functions
    // *************

    //Called at creature reset either by death or evade
    void Reset() override { }

    //Called at creature aggro either by MoveInLOS or Attack Start
    void EnterCombat(Unit* /*victim*/) override { }

    // Called before EnterCombat even before the creature is in combat.
    void AttackStart(Unit* /*target*/) override;

    // *************
    //AI Helper Functions
    // *************

    //Start movement toward victim
    void DoStartMovement(Unit* target, float distance = 0.0f, float angle = 0.0f);

    //Start no movement on victim
    void DoStartNoMovement(Unit* target);

    //Stop attack of current victim
    void DoStopAttack();

    //Cast spell by spell info
    void DoCastSpell(Unit* target, SpellInfo const* spellInfo, bool triggered = false);

    //Plays a sound to all nearby players
    void DoPlaySoundToSet(WorldObject* source, uint32 soundId);

    //Drops all threat to 0%. Does not remove players from the threat list
    void DoResetThreat();

    float DoGetThreat(Unit* unit);
    void DoModifyThreatPercent(Unit* unit, int32 pct);

    void DoTeleportTo(float x, float y, float z, uint32 time = 0);
    void DoTeleportTo(float const pos[4]);

    //Teleports a player without dropping threat (only teleports to same map)
    void DoTeleportPlayer(Unit* unit, float x, float y, float z, float o);
    void DoTeleportAll(float x, float y, float z, float o);

    //Returns friendly unit with the most amount of hp missing from max hp
    Unit* DoSelectLowestHpFriendly(float range, uint32 minHPDiff = 1);

    //Returns friendly unit with hp pct below specified and with specified entry
    Unit* DoSelectBelowHpPctFriendlyWithEntry(uint32 entry, float range, uint8 hpPct = 1, bool excludeSelf = true);

    //Returns a list of friendly CC'd units within range
    std::list<Creature*> DoFindFriendlyCC(float range);

    //Returns a list of all friendly units missing a specific buff within range
    std::list<Creature*> DoFindFriendlyMissingBuff(float range, uint32 spellId);

    //Return a player with at least minimumRange from me
    Player* GetPlayerAtMinimumRange(float minRange);

    //Spawns a creature relative to me
    Creature* DoSpawnCreature(uint32 entry, float offsetX, float offsetY, float offsetZ, float angle, uint32 type, uint32 despawntime);

    bool HealthBelowPct(uint32 pct) const;
    bool HealthAbovePct(uint32 pct) const;

    //Returns spells that meet the specified criteria from the creatures spell list
    SpellInfo const* SelectSpell(Unit* target, uint32 school, uint32 mechanic, SelectTargetType targets, float rangeMin, float rangeMax, SelectEffect effect);

    void SetEquipmentSlots(bool loadDefault, int32 mainHand = EQUIP_NO_CHANGE, int32 offHand = EQUIP_NO_CHANGE, int32 ranged = EQUIP_NO_CHANGE);

    // Used to control if MoveChase() is to be used or not in AttackStart(). Some creatures does not chase victims
    // NOTE: If you use SetCombatMovement while the creature is in combat, it will do NOTHING - This only affects AttackStart
    //       You should make the necessary to make it happen so.
    //       Remember that if you modified _isCombatMovementAllowed (e.g: using SetCombatMovement) it will not be reset at Reset().
    //       It will keep the last value you set.
    void SetCombatMovement(bool allowMovement);
    bool IsCombatMovementAllowed() const { return _isCombatMovementAllowed; }

    // return true for heroic mode. i.e.
    //   - for dungeon in mode 10-heroic,
    //   - for raid in mode 10-Heroic
    //   - for raid in mode 25-heroic
    // DO NOT USE to check raid in mode 25-normal.
    bool IsHeroic() const { return _isHeroic; }

    // return the dungeon or raid difficulty
    Difficulty GetDifficulty() const { return _difficulty; }

    // return true for 25 man or 25 man heroic mode
    bool Is25ManRaid() const { return _difficulty == DIFFICULTY_25_N || _difficulty == DIFFICULTY_25_HC; }

    template<class T> inline
    const T& DUNGEON_MODE(const T& normal5, const T& heroic10) const
    {
        switch (_difficulty)
        {
            case DIFFICULTY_NORMAL:
                return normal5;
            case DIFFICULTY_HEROIC:
                return heroic10;
            default:
                break;
        }

        return heroic10;
    }

    template<class T> inline
    const T& RAID_MODE(const T& normal10, const T& normal25) const
    {
        switch (_difficulty)
        {
            case DIFFICULTY_10_N:
                return normal10;
            case DIFFICULTY_25_N:
                return normal25;
            default:
                break;
        }

        return normal25;
    }

    template<class T> inline
    const T& RAID_MODE(const T& normal10, const T& normal25, const T& heroic10, const T& heroic25) const
    {
        switch (_difficulty)
        {
            case DIFFICULTY_10_N:
                return normal10;
            case DIFFICULTY_25_N:
                return normal25;
            case DIFFICULTY_10_HC:
                return heroic10;
            case DIFFICULTY_25_HC:
                return heroic25;
            default:
                break;
        }

        return heroic25;
    }

    private:
        Difficulty _difficulty;
        bool _isCombatMovementAllowed;
        bool _isHeroic;
};

class TC_GAME_API BossAI : public ScriptedAI
{
    public:
        BossAI(Creature* creature, uint32 bossId);
        virtual ~BossAI() { }

        InstanceScript* const instance;

        void JustSummoned(Creature* summon) override;
        void SummonedCreatureDespawn(Creature* summon) override;

        virtual void UpdateAI(uint32 diff) override;

        // Hook used to execute events scheduled into EventMap without the need
        // to override UpdateAI
        // note: You must re-schedule the event within this method if the event
        // is supposed to run more than once
        virtual void ExecuteEvent(uint32 /*eventId*/) { }

        virtual void ScheduleTasks() { }

        void Reset() override { _Reset(); }
        void EnterCombat(Unit* /*who*/) override { _EnterCombat(); }
        void JustDied(Unit* /*killer*/) override { _JustDied(); }
        void JustReachedHome() override { _JustReachedHome(); }

        bool CanAIAttack(Unit const* target) const override;

    protected:
        void _Reset();
        void _EnterCombat();
        void _JustDied();
        void _JustReachedHome();
        void _DespawnAtEvade(uint32 delayToRespawn = 30, Creature* who = nullptr);
        void _DespawnAtEvade(Seconds const& time, Creature* who = nullptr) { _DespawnAtEvade(uint32(time.count()), who); }

        void TeleportCheaters();

        EventMap events;
        SummonList summons;
        TaskScheduler scheduler;

    private:
        uint32 const _bossId;
};

class TC_GAME_API WorldBossAI : public ScriptedAI
{
    public:
        WorldBossAI(Creature* creature);
        virtual ~WorldBossAI() { }

        void JustSummoned(Creature* summon) override;
        void SummonedCreatureDespawn(Creature* summon) override;

        virtual void UpdateAI(uint32 diff) override;

        // Hook used to execute events scheduled into EventMap without the need
        // to override UpdateAI
        // note: You must re-schedule the event within this method if the event
        // is supposed to run more than once
        virtual void ExecuteEvent(uint32 /*eventId*/) { }

        void Reset() override { _Reset(); }
        void EnterCombat(Unit* /*who*/) override { _EnterCombat(); }
        void JustDied(Unit* /*killer*/) override { _JustDied(); }

    protected:
        void _Reset();
        void _EnterCombat();
        void _JustDied();

        EventMap events;
        SummonList summons;
};

// SD2 grid searchers.
inline Creature* GetClosestCreatureWithEntry(WorldObject* source, uint32 entry, float maxSearchRange, bool alive = true)
{
    return source->FindNearestCreature(entry, maxSearchRange, alive);
}

inline GameObject* GetClosestGameObjectWithEntry(WorldObject* source, uint32 entry, float maxSearchRange)
{
    return source->FindNearestGameObject(entry, maxSearchRange);
}

template <typename Container>
inline void GetCreatureListWithEntryInGrid(Container& container, WorldObject* source, uint32 entry, float maxSearchRange)
{
    source->GetCreatureListWithEntryInGrid(container, entry, maxSearchRange);
}

template <typename Container>
inline void GetGameObjectListWithEntryInGrid(Container& container, WorldObject* source, uint32 entry, float maxSearchRange)
{
    source->GetGameObjectListWithEntryInGrid(container, entry, maxSearchRange);
}

template <typename Container>
inline void GetPlayerListInGrid(Container& container, WorldObject* source, float maxSearchRange)
{
    source->GetPlayerListInGrid(container, maxSearchRange);
}

#endif // SCRIPTEDCREATURE_H_
