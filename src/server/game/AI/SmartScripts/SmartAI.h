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

#ifndef TRINITY_SMARTAI_H
#define TRINITY_SMARTAI_H

#include "Define.h"
#include "CreatureAI.h"
#include "GameObjectAI.h"
#include "Position.h"
#include "SmartScript.h"

struct WayPoint;

enum SmartEscortState
{
    SMART_ESCORT_NONE       = 0x000,                        //nothing in progress
    SMART_ESCORT_ESCORTING  = 0x001,                        //escort is in progress
    SMART_ESCORT_RETURNING  = 0x002,                        //escort is returning after being in combat
    SMART_ESCORT_PAUSED     = 0x004                         //will not proceed with waypoints before state is removed
};

enum SmartEscortVars
{
    SMART_ESCORT_MAX_PLAYER_DIST        = 60,
    SMART_MAX_AID_DIST    = SMART_ESCORT_MAX_PLAYER_DIST / 2
};

class TC_GAME_API SmartAI : public CreatureAI
{
    public:
        ~SmartAI(){ }
        explicit SmartAI(Creature* c);

        // Check whether we are currently permitted to make the creature take action
        bool IsAIControlled() const;

        // Start moving to the desired MovePoint
        void StartPath(bool run = false, uint32 path = 0, bool repeat = false, Unit* invoker = nullptr);
        bool LoadPath(uint32 entry);
        void PausePath(uint32 delay, bool forced = false);
        void StopPath(uint32 DespawnTime = 0, uint32 quest = 0, bool fail = false);
        void EndPath(bool fail = false);
        void ResumePath();
        WayPoint* GetNextWayPoint();
        bool HasEscortState(uint32 uiEscortState) const { return (mEscortState & uiEscortState) != 0; }
        void AddEscortState(uint32 uiEscortState) { mEscortState |= uiEscortState; }
        void RemoveEscortState(uint32 uiEscortState) { mEscortState &= ~uiEscortState; }
        void SetAutoAttack(bool on) { mCanAutoAttack = on; }
        void SetCombatMove(bool on);
        bool CanCombatMove() { return mCanCombatMove; }
        void SetFollow(Unit* target, float dist = 0.0f, float angle = 0.0f, uint32 credit = 0, uint32 end = 0, uint32 creditType = 0);
        void StopFollow(bool complete);

        void SetScript9(SmartScriptHolder& e, uint32 entry, Unit* invoker);
        SmartScript* GetScript() { return &mScript; }
        bool IsEscortInvokerInRange();

        // Called when creature is spawned or respawned
        void JustRespawned() override;

        // Called at reaching home after evade, InitializeAI(), EnterEvadeMode() for resetting variables
        void JustReachedHome() override;

        // Called for reaction at enter to combat if not in combat yet (enemy can be nullptr)
        void EnterCombat(Unit* enemy) override;

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
        void SpellHit(Unit* unit, const SpellInfo* spellInfo) override;

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, const SpellInfo* spellInfo) override;

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
        void IsSummonedBy(Unit* summoner) override;

        // Called at any Damage to any victim (before damage apply)
        void DamageDealt(Unit* doneTo, uint32& damage, DamageEffectType /*damagetype*/) override;

        // Called when a summoned creature dissapears (UnSommoned)
        void SummonedCreatureDespawn(Creature* unit) override;

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& respawnDelay) override;

        // Called when a Player/Creature enters the creature (vehicle)
        void PassengerBoarded(Unit* who, int8 seatId, bool apply) override;

        // Called when gets initialized, when creature is added to world
        void InitializeAI() override;

        // Called when creature gets charmed by another unit
        void OnCharmed(bool apply) override;

        // Called when victim is in line of sight
        bool CanAIAttack(const Unit* who) const override;

        // Used in scripts to share variables
        void DoAction(int32 param = 0) override;

        // Used in scripts to share variables
        uint32 GetData(uint32 id = 0) const override;

        // Used in scripts to share variables
        void SetData(uint32 id, uint32 value) override;

        // Used in scripts to share variables
        void SetGUID(ObjectGuid guid, int32 id = 0) override;

        // Used in scripts to share variables
        ObjectGuid GetGUID(int32 id = 0) const override;

        //core related
        static int32 Permissible(Creature const* /*creature*/) { return PERMIT_BASE_NO; }

        // Called at movepoint reached
        void MovepointReached(uint32 id);

        // Makes the creature run/walk
        void SetRun(bool run = true);

        void SetCanFly(bool fly = true);

        void SetDisableGravity(bool disable = true);

        void SetSwim(bool swim = true);

        void SetEvadeDisabled(bool disable = true);

        void SetInvincibilityHpLevel(uint32 level) { mInvincibilityHpLevel = level; }

        bool GossipHello(Player* player) override;
        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override;
        bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, const char* code) override;
        void QuestAccept(Player* player, Quest const* quest) override;
        void QuestReward(Player* player, Quest const* quest, uint32 opt) override;
        void OnGameEvent(bool start, uint16 eventId) override;

        uint32 mEscortQuestID;

        void SetDespawnTime (uint32 t, uint32 r = 0)
        {
            mDespawnTime = t;
            mRespawnTime = r;
            mDespawnState = t ? 1 : 0;
        }

        void StartDespawn() { mDespawnState = 2; }

        void OnSpellClick(Unit* clicker, bool& result) override;

        void SetWPPauseTimer(uint32 time) { mWPPauseTimer = time; }

        void SetGossipReturn(bool val) { _gossipReturn = val; }

    private:
        bool mIsCharmed;
        uint32 mFollowCreditType;
        uint32 mFollowArrivedTimer;
        uint32 mFollowCredit;
        uint32 mFollowArrivedEntry;
        ObjectGuid mFollowGuid;
        float mFollowDist;
        float mFollowAngle;

        void ReturnToLastOOCPos();
        void UpdatePath(const uint32 diff);
        SmartScript mScript;
        WPPath* mWayPoints;
        uint32 mEscortState;
        uint32 mCurrentWPID;
        uint32 mLastWPIDReached;
        bool mWPReached;
        uint32 mWPPauseTimer;
        uint32 mEscortNPCFlags;
        WayPoint* mLastWP;
        Position mLastOOCPos;//set on enter combat
        uint32 GetWPCount() const { return mWayPoints ? uint32(mWayPoints->size()) : 0; }
        bool mCanRepeatPath;
        bool mRun;
        bool mEvadeDisabled;
        bool mCanAutoAttack;
        bool mCanCombatMove;
        bool mForcedPaused;
        uint32 mInvincibilityHpLevel;
        bool AssistPlayerInCombatAgainst(Unit* who);

        uint32 mDespawnTime;
        uint32 mRespawnTime;
        uint32 mDespawnState;
        void UpdateDespawn(uint32 diff);
        uint32 mEscortInvokerCheckTimer;
        bool mJustReset;

        // Vehicle conditions
        void CheckConditions(uint32 diff);
        bool mHasConditions;
        uint32 mConditionsTimer;

        // Gossip
        bool _gossipReturn;
};

class TC_GAME_API SmartGameObjectAI : public GameObjectAI
{
    public:
        SmartGameObjectAI(GameObject* g) : GameObjectAI(g), _gossipReturn(false) { }
        ~SmartGameObjectAI() { }

        void UpdateAI(uint32 diff) override;
        void InitializeAI() override;
        void Reset() override;
        SmartScript* GetScript() { return &mScript; }
        static int32 Permissible(GameObject const* /*go*/) { return PERMIT_BASE_NO; }

        bool GossipHello(Player* player) override;
        bool OnReportUse(Player* player) override;
        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override;
        bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, const char* code) override;
        void QuestAccept(Player* player, Quest const* quest) override;
        void QuestReward(Player* player, Quest const* quest, uint32 opt) override;
        void Destroyed(Player* player, uint32 eventId) override;
        void SetData(uint32 id, uint32 value) override;
        void SetScript9(SmartScriptHolder& e, uint32 entry, Unit* invoker);
        void OnGameEvent(bool start, uint16 eventId) override;
        void OnLootStateChanged(uint32 state, Unit* unit) override;
        void EventInform(uint32 eventId) override;
        void SpellHit(Unit* unit, const SpellInfo* spellInfo) override;

        void SetGossipReturn(bool val) { _gossipReturn = val; }

    private:
        SmartScript mScript;

        // Gossip
        bool _gossipReturn;
};

/// Registers scripts required by the SAI scripting system
void AddSC_SmartScripts();

#endif
