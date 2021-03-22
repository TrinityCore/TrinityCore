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

#include "UnitAI.h"
#include "Common.h"
#include "ObjectDefines.h"

class AreaBoundary;
class AreaTrigger;
class Creature;
class DynamicObject;
class GameObject;
class PlayerAI;
class WorldObject;
struct Position;

typedef std::vector<AreaBoundary const*> CreatureBoundary;

#define TIME_INTERVAL_LOOK   5000
#define VISIBILITY_RANGE    10000

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
        bool UpdateVictimWithGaze();

        void SetGazeOn(Unit* target);

        Creature* DoSummon(uint32 entry, Position const& pos, uint32 despawnTime = 30000, TempSummonType summonType = TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        Creature* DoSummon(uint32 entry, WorldObject* obj, float radius = 5.0f, uint32 despawnTime = 30000, TempSummonType summonType = TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        Creature* DoSummonFlyer(uint32 entry, WorldObject* obj, float flightZ, float radius = 5.0f, uint32 despawnTime = 30000, TempSummonType summonType = TEMPSUMMON_CORPSE_TIMED_DESPAWN);

        bool CheckBoundary(Position const* who = nullptr) const;

    public:
        enum EvadeReason
        {
            EVADE_REASON_NO_HOSTILES,       // the creature's threat list is empty
            EVADE_REASON_BOUNDARY,          // the creature has moved outside its evade boundary
            EVADE_REASON_NO_PATH,           // the creature was unable to reach its target for over 5 seconds
            EVADE_REASON_SEQUENCE_BREAK,    // this is a boss and the pre-requisite encounters for engaging it are not defeated yet
            EVADE_REASON_OTHER
        };

        explicit CreatureAI(Creature* creature);

        virtual ~CreatureAI();

        void Talk(uint8 id, WorldObject const* whisperTarget = nullptr);

        /// == Reactions At =================================

        // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
        void MoveInLineOfSight_Safe(Unit* who);

        // Trigger Creature "Alert" state (creature can see stealthed unit)
        void TriggerAlert(Unit const* who) const;

        // Called for reaction at stopping attack at no attackers or targets
        virtual void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER);

        // Called for reaction when initially engaged
        virtual void EnterCombat(Unit* /*victim*/) { }

        // Called when the creature is killed
        virtual void JustDied(Unit* /*killer*/) { }

        // Called when the creature kills a unit
        virtual void KilledUnit(Unit* /*victim*/) { }

        // Called when the creature summon successfully other creature
        virtual void JustSummoned(Creature* /*summon*/) { }
        virtual void IsSummonedBy(Unit* /*summoner*/) { }

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
        virtual void SpellHit(Unit* /*caster*/, SpellInfo const* /*spell*/) { }

        // Called when spell hits a target
        virtual void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) { }

        virtual bool IsEscorted() const { return false; }

        // Called when creature appears in the world (spawn, respawn, grid load etc...)
        virtual void JustAppeared() { }

        // Called at waypoint reached or point movement finished
        virtual void MovementInform(uint32 /*type*/, uint32 /*id*/) { }

        void OnCharmed(bool apply) override;

        // Called when a spell cast gets interrupted
        virtual void OnSpellCastInterrupt(SpellInfo const* /*spell*/) { }

        // Called when a spell cast has been successfully finished
        virtual void OnSuccessfulSpellCast(SpellInfo const* /*spell*/) { }

        // Called at reaching home after evade
        virtual void JustReachedHome() { }

        void DoZoneInCombat(Creature* creature = nullptr, float maxRangeToNearestTarget = 250.0f);

        // Called at text emote receive from player
        virtual void ReceiveEmote(Player* /*player*/, uint32 /*emoteId*/) { }

        // Called when owner takes damage
        virtual void OwnerAttackedBy(Unit* attacker) { _OnOwnerCombatInteraction(attacker); }

        // Called when owner attacks something
        virtual void OwnerAttacked(Unit* target) { _OnOwnerCombatInteraction(target); }

        /// == Triggered Actions Requested ==================

        // Called when creature attack expected (if creature can and no have current victim)
        //virtual void AttackStart(Unit*) { }

        // Called at World update tick
        //virtual void UpdateAI(const uint32 /*diff*/) { }

        /// == State checks =================================

        // Is unit visible for MoveInLineOfSight
        //virtual bool IsVisible(Unit*) const { return false; }

        // called when the corpse of this creature gets removed
        virtual void CorpseRemoved(uint32& /*respawnDelay*/) { }

        // Called when victim entered water and creature can not enter water
        //virtual bool CanReachByRangeAttack(Unit*) { return false; }

        /// == Fields =======================================

        virtual void PassengerBoarded(Unit* /*passenger*/, int8 /*seatId*/, bool /*apply*/) { }

        virtual void OnSpellClick(Unit* /*clicker*/, bool& /*result*/) { }

        virtual bool CanSeeAlways(WorldObject const* /*obj*/) { return false; }

        // Called when a player is charmed by the creature
        // If a PlayerAI* is returned, that AI is placed on the player instead of the default charm AI
        // Object destruction is handled by Unit::RemoveCharmedBy
        virtual PlayerAI* GetAIForCharmedPlayer(Player* /*who*/) { return nullptr; }
        // Should return true if the NPC is target of an escort quest
        // If onlyIfActive is set, should return true only if the escort quest is currently active
        virtual bool IsEscortNPC(bool /*onlyIfActive*/) const { return false; }

        // intended for encounter design/debugging. do not use for other purposes. expensive.
        int32 VisualizeBoundary(uint32 duration, Unit* owner = nullptr, bool fill = false) const;
        virtual bool CheckInRoom();
        CreatureBoundary const* GetBoundary() const { return _boundary; }
        void SetBoundary(CreatureBoundary const* boundary, bool negativeBoundaries = false);

        static bool IsInBounds(CreatureBoundary const& boundary, Position const* who);

    protected:
        virtual void MoveInLineOfSight(Unit* /*who*/);

        bool _EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER);

        CreatureBoundary const* _boundary;
        bool _negateBoundary;

    private:
        bool m_MoveInLineOfSight_locked;
        void _OnOwnerCombatInteraction(Unit* target);
};

enum Permitions : int32
{
    PERMIT_BASE_NO                 = -1,
    PERMIT_BASE_IDLE               = 1,
    PERMIT_BASE_REACTIVE           = 100,
    PERMIT_BASE_PROACTIVE          = 200,
    PERMIT_BASE_FACTION_SPECIFIC   = 400,
    PERMIT_BASE_SPECIAL            = 800
};

#endif
