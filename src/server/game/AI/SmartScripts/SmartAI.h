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

#ifndef TRINITY_SMARTAI_H
#define TRINITY_SMARTAI_H

#include "Define.h"
#include "CreatureAI.h"
#include "GameObjectAI.h"
#include "Position.h"
#include "SmartScript.h"
#include "WaypointDefines.h"

enum SmartEscortState : uint8
{
    SMART_ESCORT_NONE       = 0x00, // nothing in progress
    SMART_ESCORT_ESCORTING  = 0x01, // escort is in progress
    SMART_ESCORT_RETURNING  = 0x02, // escort is returning after being in combat
    SMART_ESCORT_PAUSED     = 0x04  // will not proceed with waypoints before state is removed
};

static float constexpr SMART_ESCORT_MAX_PLAYER_DIST = 60.f;
static float constexpr SMART_MAX_AID_DIST = SMART_ESCORT_MAX_PLAYER_DIST / 2.f;

class TC_GAME_API SmartAI : public CreatureAI
{
    public:
        ~SmartAI() { }
        explicit SmartAI(Creature* creature);

        // core related
        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

        // Check whether we are currently permitted to make the creature take action
        bool IsAIControlled() const;

        // Start moving to the desired MovePoint
        void StartPath(bool run = false, uint32 pathId = 0, bool repeat = false, Unit* invoker = nullptr, uint32 nodeId = 1);
        bool LoadPath(uint32 entry);
        void PausePath(uint32 delay, bool forced = false);
        void StopPath(uint32 DespawnTime = 0, uint32 quest = 0, bool fail = false);
        void EndPath(bool fail = false);
        void ResumePath();
        bool HasEscortState(uint32 escortState) const { return (_escortState & escortState) != 0; }
        void AddEscortState(uint32 escortState) { _escortState |= escortState; }
        void RemoveEscortState(uint32 escortState) { _escortState &= ~escortState; }
        void SetAutoAttack(bool on) { _canAutoAttack = on; }
        void SetCombatMove(bool on);
        bool CanCombatMove() { return _canCombatMove; }
        void SetFollow(Unit* target, float dist = 0.0f, float angle = 0.0f, uint32 credit = 0, uint32 end = 0, uint32 creditType = 0);
        void StopFollow(bool complete);
        bool IsEscortInvokerInRange();

        void WaypointPathStarted(uint32 pathId) override;
        void WaypointStarted(uint32 nodeId, uint32 pathId) override;
        void WaypointReached(uint32 nodeId, uint32 pathId) override;
        void WaypointPathEnded(uint32 nodeId, uint32 pathId) override;

        void SetTimedActionList(SmartScriptHolder& e, uint32 entry, Unit* invoker);
        SmartScript* GetScript() { return &_script; }

        // Called at reaching home after evade, InitializeAI(), EnterEvadeMode() for resetting variables
        void JustReachedHome() override;

        // Called for reaction at enter to combat if not in combat yet (enemy can be nullptr)
        void JustEngagedWith(Unit* enemy) override;

        // Called for reaction at stopping attack at no attackers or targets
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override;

        // Called when the creature is killed
        void JustDied(Unit* killer) override;

        // Called when the creature kills a unit
        void KilledUnit(Unit* victim) override;

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* creature) override;

        // Tell creature to attack and follow the victim
        void AttackStart(Unit* who) override;

        // Called if IsVisible(Unit* who) is true at each *who move, reaction at visibility zone enter
        void MoveInLineOfSight(Unit* who) override;

        // Called when hit by a spell
        void SpellHit(Unit* unit, SpellInfo const* spellInfo) override;

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override;

        // Called at any Damage from any attacker (before damage apply)
        void DamageTaken(Unit* doneBy, uint32& damage) override;

        // Called when the creature receives heal
        void HealReceived(Unit* doneBy, uint32& addhealth) override;

        // Called at World update tick
        void UpdateAI(uint32 diff) override;

        // Called at text emote receive from player
        void ReceiveEmote(Player* player, uint32 textEmote) override;

        // Called at waypoint reached or point movement finished
        void MovementInform(uint32 MovementType, uint32 Data) override;

        // Called when creature is summoned by another unit
        void IsSummonedBy(WorldObject* summoner) override;

        // Called at any Damage to any victim (before damage apply)
        void DamageDealt(Unit* doneTo, uint32& damage, DamageEffectType /*damagetype*/) override;

        // Called when a summoned creature dissapears (UnSommoned)
        void SummonedCreatureDespawn(Creature* unit) override;

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& respawnDelay) override;

        // Called when a Player/Creature enters the creature (vehicle)
        void PassengerBoarded(Unit* who, int8 seatId, bool apply) override;

        // Called when gets initialized
        void InitializeAI() override;

        // Called once creature is fully added to world
        void JustAppeared() override;

        // Called when creature gets charmed by another unit
        void OnCharmed(bool isNew) override;

        // Used in scripts to share variables
        void DoAction(int32 param = 0) override;

        // Used in scripts to share variables
        uint32 GetData(uint32 id = 0) const override;

        // Used in scripts to share variables
        void SetData(uint32 id, uint32 value) override { SetData(id, value, nullptr); }
        void SetData(uint32 id, uint32 value, Unit* invoker);

        // Used in scripts to share variables
        void SetGUID(ObjectGuid const& guid, int32 id = 0) override;

        // Used in scripts to share variables
        ObjectGuid GetGUID(int32 id = 0) const override;

        // Makes the creature run/walk
        void SetRun(bool run = true);

        void SetCanFly(bool fly = true);

        void SetDisableGravity(bool disable = true);

        void SetSwim(bool swim = true);

        void SetEvadeDisabled(bool disable = true);

        void SetInvincibilityHpLevel(uint32 level) { _invincibilityHPLevel = level; }

        bool GossipHello(Player* player) override;
        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override;
        bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code) override;
        void QuestAccept(Player* player, Quest const* quest) override;
        void QuestReward(Player* player, Quest const* quest, uint32 opt) override;
        void OnGameEvent(bool start, uint16 eventId) override;

        void SetDespawnTime (uint32 t)
        {
            _despawnTime = t;
            _despawnState = t ? 1 : 0;
        }
        void StartDespawn() { _despawnState = 2; }

        void OnSpellClick(Unit* clicker, bool spellClickHandled) override;

        void SetWPPauseTimer(uint32 time) { _waypointPauseTimer = time; }

        void SetGossipReturn(bool val) { _gossipReturn = val; }

        void SetEscortQuest(uint32 questID) { _escortQuestId = questID; }

    private:
        bool AssistPlayerInCombatAgainst(Unit* who);
        void ReturnToLastOOCPos();
        void CheckConditions(uint32 diff);
        void UpdatePath(uint32 diff);
        void UpdateFollow(uint32 diff);
        void UpdateDespawn(uint32 diff);

        SmartScript _script;
        bool _charmed;
        uint32 _followCreditType;
        uint32 _followArrivedTimer;
        uint32 _followCredit;
        uint32 _followArrivedEntry;
        ObjectGuid _followGUID;
        float _followDistance;
        float _followAngle;

        uint32 _escortState;
        uint32 _escortNPCFlags;
        uint32 _escortInvokerCheckTimer;
        WaypointPath _path;
        uint32 _currentWaypointNode;
        bool _waypointReached;
        uint32 _waypointPauseTimer;
        bool _waypointPauseForced;
        bool _repeatWaypointPath;
        bool _OOCReached;
        bool _waypointPathEnded;

        bool _run;
        bool _evadeDisabled;
        bool _canAutoAttack;
        bool _canCombatMove;
        uint32 _invincibilityHPLevel;

        uint32 _despawnTime;
        uint32 _despawnState;

        // Vehicle conditions
        bool _vehicleConditions;
        uint32 _vehicleConditionsTimer;

        // Gossip
        bool _gossipReturn;

        uint32 _escortQuestId;
};

class TC_GAME_API SmartGameObjectAI : public GameObjectAI
{
    public:
        SmartGameObjectAI(GameObject* go) : GameObjectAI(go), _gossipReturn(false) { }
        ~SmartGameObjectAI() { }

        void UpdateAI(uint32 diff) override;
        void InitializeAI() override;
        void Reset() override;
        SmartScript* GetScript() { return &_script; }
        static int32 Permissible(GameObject const* /*go*/) { return PERMIT_BASE_NO; }

        bool GossipHello(Player* player) override;
        bool OnReportUse(Player* player) override;
        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override;
        bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code) override;
        void QuestAccept(Player* player, Quest const* quest) override;
        void QuestReward(Player* player, Quest const* quest, uint32 opt) override;
        void Destroyed(WorldObject* attacker, uint32 eventId) override;
        void SetData(uint32 id, uint32 value, Unit* invoker);
        void SetData(uint32 id, uint32 value) override { SetData(id, value, nullptr); }
        void SetTimedActionList(SmartScriptHolder& e, uint32 entry, Unit* invoker);
        void OnGameEvent(bool start, uint16 eventId) override;
        void OnLootStateChanged(uint32 state, Unit* unit) override;
        void EventInform(uint32 eventId) override;
        void SpellHit(Unit* unit, SpellInfo const* spellInfo) override;

        // Called when the gameobject summon successfully other creature
        void JustSummoned(Creature* creature) override;

        // Called when a summoned creature dissapears (UnSommoned)
        void SummonedCreatureDespawn(Creature* unit) override;

        void SetGossipReturn(bool val) { _gossipReturn = val; }

    private:
        SmartScript _script;

        // Gossip
        bool _gossipReturn;
};

/// Registers scripts required by the SAI scripting system
void AddSC_SmartScripts();

#endif
