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

#ifndef TRINITY_CREATUREAI_H
#define TRINITY_CREATUREAI_H

#include "LootItemType.h"
#include "ObjectDefines.h"
#include "Optional.h"
#include "QuestDef.h"
#include "UnitAI.h"

class AreaBoundary;
class AreaTrigger;
class Creature;
class DynamicObject;
class GameObject;
class PlayerAI;
class WorldObject;
struct Position;
enum class QuestGiverStatus : uint64;

typedef std::vector<AreaBoundary const*> CreatureBoundary;

#define TIME_INTERVAL_LOOK   5000
#define VISIBILITY_RANGE    10000

enum Permitions : int32
{
    PERMIT_BASE_NO               = -1,
    PERMIT_BASE_IDLE             = 1,
    PERMIT_BASE_REACTIVE         = 100,
    PERMIT_BASE_PROACTIVE        = 200,
    PERMIT_BASE_FACTION_SPECIFIC = 400,
    PERMIT_BASE_SPECIAL          = 800
};

enum SCEquip
{
    EQUIP_NO_CHANGE = -1,
    EQUIP_UNEQUIP   = 0
};

class TC_GAME_API CreatureAI : public UnitAI
{
    protected:
        Creature* const me;

        bool UpdateVictim();

        Creature* DoSummon(uint32 entry, Position const& pos, Milliseconds despawnTime = 30s, TempSummonType summonType = TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        Creature* DoSummon(uint32 entry, WorldObject* obj, float radius = 5.0f, Milliseconds despawnTime = 30s, TempSummonType summonType = TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        Creature* DoSummonFlyer(uint32 entry, WorldObject* obj, float flightZ, float radius = 5.0f, Milliseconds despawnTime = 30s, TempSummonType summonType = TEMPSUMMON_CORPSE_TIMED_DESPAWN);

    public:
        explicit CreatureAI(Creature* creature, uint32 scriptId = {});

        virtual ~CreatureAI();

        // Gets the id of the AI (script id)
        uint32 GetId() const { return _scriptId; }

        bool IsEngaged() const { return _isEngaged; }

        void Talk(uint8 id, WorldObject const* whisperTarget = nullptr);

        /// == Reactions At =================================

        // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
        void MoveInLineOfSight_Safe(Unit* who);

        // Trigger Creature "Alert" state (creature can see stealthed unit)
        void TriggerAlert(Unit const* who) const;

        // Called for reaction at stopping attack at no attackers or targets
        virtual void EnterEvadeMode(EvadeReason why = EvadeReason::Other);

        // Called for reaction whenever we start being in combat (overridden from base UnitAI)
        void JustEnteredCombat(Unit* /*who*/) override;

        // Called for reaction whenever a new non-offline unit is added to the threat list
        virtual void JustStartedThreateningMe(Unit* who) { if (!IsEngaged()) EngagementStart(who); }

        // Called for reaction when initially engaged - this will always happen _after_ JustEnteredCombat
        virtual void JustEngagedWith(Unit* /*who*/) { }

        // Called when the creature reaches 0 health (or 1 if unkillable).
        virtual void OnHealthDepleted(Unit* /*attacker*/, bool /*isKill*/) { }

        // Called when the creature is killed
        virtual void JustDied(Unit* /*killer*/) { }

        // Called when the creature kills a unit
        virtual void KilledUnit(Unit* /*victim*/) { }

        // Called when the creature summon successfully other creature
        virtual void JustSummoned(Creature* /*summon*/) { }
        virtual void IsSummonedBy(WorldObject* /*summoner*/) { }

        virtual void SummonedCreatureDespawn(Creature* /*summon*/) { }
        virtual void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) { }

        // Called when the creature successfully summons a gameobject
        virtual void JustSummonedGameobject(GameObject* /*gameobject*/) { }
        virtual void SummonedGameobjectDespawn(GameObject* /*gameobject*/) { }

        // Called when the creature successfully registers a dynamicobject
        virtual void JustRegisteredDynObject(DynamicObject* /*dynObject*/) { }
        virtual void JustUnregisteredDynObject(DynamicObject* /*dynObject*/) { }

        // Called when the creature successfully registers an areatrigger
        virtual void JustRegisteredAreaTrigger(AreaTrigger* /*areaTrigger*/) { }
        virtual void JustUnregisteredAreaTrigger(AreaTrigger* /*areaTrigger*/) { }

        // Called when hit by a spell
        virtual void SpellHit(WorldObject* /*caster*/, SpellInfo const* /*spellInfo*/) { }

        // Called when spell hits a target
        virtual void SpellHitTarget(WorldObject* /*target*/, SpellInfo const* /*spellInfo*/) { }

        // Called when a spell finishes
        virtual void OnSpellCast(SpellInfo const* /*spell*/) { }

        // Called when a spell fails
        virtual void OnSpellFailed(SpellInfo const* /*spell*/) { }

        // Called when a spell starts
        virtual void OnSpellStart(SpellInfo const* /*spell*/) { }

        // Called when a channeled spell finishes
        virtual void OnChannelFinished(SpellInfo const* /*spell*/) { }

        // Should return true if the NPC is currently being escorted
        virtual bool IsEscorted() const { return false; }

        // Called when creature appears in the world (spawn, respawn, grid load etc...)
        virtual void JustAppeared();

        // Called at waypoint reached or point movement finished
        virtual void MovementInform(uint32 /*type*/, uint32 /*id*/) { }

        void OnCharmed(bool isNew) override;

        // Called at reaching home after evade
        virtual void JustReachedHome() { }

        void DoZoneInCombat() { DoZoneInCombat(me); }
        static void DoZoneInCombat(Creature* creature);

        // Called at text emote receive from player
        virtual void ReceiveEmote(Player* /*player*/, uint32 /*emoteId*/) { }

        // Called when owner takes damage
        virtual void OwnerAttackedBy(Unit* attacker) { OnOwnerCombatInteraction(attacker); }

        // Called when owner attacks something
        virtual void OwnerAttacked(Unit* target) { OnOwnerCombatInteraction(target); }

        /// == Triggered Actions Requested ==================

        // Called when creature attack expected (if creature can and no have current victim)
        void AttackStart(Unit* victim) override;

        // Called at World update tick
        //virtual void UpdateAI(const uint32 /*diff*/) { }

        /// == State checks =================================

        // Is unit visible for MoveInLineOfSight
        //virtual bool IsVisible(Unit*) const { return false; }

        // called when the corpse of this creature gets removed
        virtual void CorpseRemoved(uint32& /*respawnDelay*/) { }

        // Called when victim entered water and creature can not enter water
        //virtual bool CanReachByRangeAttack(Unit*) { return false; }

        /// == Gossip system ================================

        // Called when the dialog status between a player and the creature is requested.
        virtual Optional<QuestGiverStatus> GetDialogStatus(Player const* player);

        // Called when a player opens a gossip dialog with the creature.
        virtual bool OnGossipHello(Player* /*player*/) { return false; }

        // Called when a player selects a gossip item in the creature's gossip menu.
        virtual bool OnGossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) { return false; }

        // Called when a player selects a gossip with a code in the creature's gossip menu.
        virtual bool OnGossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, char const* /*code*/) { return false; }

        // Called when a player accepts a quest from the creature.
        virtual void OnQuestAccept(Player* /*player*/, Quest const* /*quest*/) { }

        // Called when a player completes a quest and is rewarded, opt is the selected item's index or 0
        virtual void OnQuestReward(Player* /*player*/, Quest const* /*quest*/, LootItemType /*type*/, uint32 /*opt*/) { }

        /// == Waypoints system =============================

        virtual void WaypointStarted(uint32 /*nodeId*/, uint32 /*pathId*/) { }
        virtual void WaypointReached(uint32 /*nodeId*/, uint32 /*pathId*/) { }
        virtual void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) { }

        /// == Fields =======================================

        virtual void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool /*apply*/) { }

        virtual void OnSpellClick(Unit* /*clicker*/, bool /*spellClickHandled*/) { }

        virtual bool CanSeeAlways(WorldObject const* /*obj*/) { return false; }

        // Called when a player is charmed by the creature
        // If a PlayerAI* is returned, that AI is placed on the player instead of the default charm AI
        // Object destruction is handled by Unit::RemoveCharmedBy
        virtual PlayerAI* GetAIForCharmedPlayer(Player* /*who*/) { return nullptr; }

        // intended for encounter design/debugging. do not use for other purposes. expensive.
        int32 VisualizeBoundary(Seconds duration, Unit* owner = nullptr, bool fill = false) const;

        // boundary system methods
        virtual bool CheckInRoom();
        CreatureBoundary const* GetBoundary() const { return _boundary; }
        void SetBoundary(CreatureBoundary const* boundary, bool negativeBoundaries = false);

        static bool IsInBounds(CreatureBoundary const& boundary, Position const* who);
        bool IsInBoundary(Position const* who = nullptr) const;

    protected:
        void EngagementStart(Unit* who);
        void EngagementOver();
        virtual void MoveInLineOfSight(Unit* /*who*/);

        bool _EnterEvadeMode(EvadeReason why = EvadeReason::Other);

        CreatureBoundary const* _boundary;
        bool _negateBoundary;

    private:
        void OnOwnerCombatInteraction(Unit* target);

        uint32 const _scriptId;
        bool _isEngaged;
        bool _moveInLOSLocked;
};

#endif
