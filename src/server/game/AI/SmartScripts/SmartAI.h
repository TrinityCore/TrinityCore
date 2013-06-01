/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "Spell.h"

#include "SmartScript.h"
#include "SmartScriptMgr.h"
#include "GameObjectAI.h"

enum SmartEscortState
{
    SMART_ESCORT_NONE       = 0x000,                        //nothing in progress
    SMART_ESCORT_ESCORTING  = 0x001,                        //escort is in progress
    SMART_ESCORT_RETURNING  = 0x002,                        //escort is returning after being in combat
    SMART_ESCORT_PAUSED     = 0x004                         //will not proceed with waypoints before state is removed
};

enum SmartEscortVars
{
    SMART_ESCORT_MAX_PLAYER_DIST        = 50,
    SMART_MAX_AID_DIST    = SMART_ESCORT_MAX_PLAYER_DIST / 2
};

class SmartAI : public CreatureAI
{
    public:
        ~SmartAI(){}
        explicit SmartAI(Creature* c);

        // Start moving to the desired MovePoint
        void StartPath(bool run = false, uint32 path = 0, bool repeat = false, Unit* invoker = NULL);
        bool LoadPath(uint32 entry);
        void PausePath(uint32 delay, bool forced = false);
        void StopPath(uint32 DespawnTime = 0, uint32 quest = 0, bool fail = false);
        void EndPath(bool fail = false);
        void ResumePath();
        WayPoint* GetNextWayPoint();
        bool HasEscortState(uint32 uiEscortState) { return (mEscortState & uiEscortState); }
        void AddEscortState(uint32 uiEscortState) { mEscortState |= uiEscortState; }
        void RemoveEscortState(uint32 uiEscortState) { mEscortState &= ~uiEscortState; }
        void SetAutoAttack(bool on) { mCanAutoAttack = on; }
        void SetCombatMove(bool on);
        bool CanCombatMove() { return mCanCombatMove; }
        void SetFollow(Unit* target, float dist = 0.0f, float angle = 0.0f, uint32 credit = 0, uint32 end = 0, uint32 creditType = 0);

        void SetScript9(SmartScriptHolder& e, uint32 entry, Unit* invoker);
        SmartScript* GetScript() { return &mScript; }
        bool IsEscortInvokerInRange();

        // Called when creature is spawned or respawned
        void JustRespawned();

        // Called after InitializeAI(), EnterEvadeMode() for resetting variables
        void Reset();

        // Called at reaching home after evade
        void JustReachedHome();

        // Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
        void EnterCombat(Unit* enemy);

        // Called for reaction at stopping attack at no attackers or targets
        void EnterEvadeMode();

        // Called when the creature is killed
        void JustDied(Unit* killer);

        // Called when the creature kills a unit
        void KilledUnit(Unit* victim);

        // Called when the creature summon successfully other creature
        void JustSummoned(Creature* creature);

        // Tell creature to attack and follow the victim
        void AttackStart(Unit* who);

        // Called if IsVisible(Unit* who) is true at each *who move, reaction at visibility zone enter
        void MoveInLineOfSight(Unit* who);

        // Called when hit by a spell
        void SpellHit(Unit* unit, const SpellInfo* spellInfo);

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, const SpellInfo* spellInfo);

        // Called at any Damage from any attacker (before damage apply)
        void DamageTaken(Unit* doneBy, uint32& damage);

        // Called when the creature receives heal
        void HealReceived(Unit* doneBy, uint32& addhealth);

        // Called at World update tick
        void UpdateAI(uint32 diff);

        // Called at text emote receive from player
        void ReceiveEmote(Player* player, uint32 textEmote);

        // Called at waypoint reached or point movement finished
        void MovementInform(uint32 MovementType, uint32 Data);

        // Called when creature is summoned by another unit
        void IsSummonedBy(Unit* summoner);

        // Called at any Damage to any victim (before damage apply)
        void DamageDealt(Unit* doneTo, uint32& damage, DamageEffectType /*damagetype*/);

        // Called when a summoned creature dissapears (UnSommoned)
        void SummonedCreatureDespawn(Creature* unit);

        // called when the corpse of this creature gets removed
        void CorpseRemoved(uint32& respawnDelay);

        // Called at World update tick if creature is charmed
        void UpdateAIWhileCharmed(const uint32 diff);

        // Called when a Player/Creature enters the creature (vehicle)
        void PassengerBoarded(Unit* who, int8 seatId, bool apply);

        // Called when gets initialized, when creature is added to world
        void InitializeAI();

        // Called when creature gets charmed by another unit
        void OnCharmed(bool apply);

        // Called when victim is in line of sight
        bool CanAIAttack(const Unit* who) const;

        // Used in scripts to share variables
        void DoAction(int32 param = 0);

        // Used in scripts to share variables
        uint32 GetData(uint32 id = 0) const;

        // Used in scripts to share variables
        void SetData(uint32 id, uint32 value);

        // Used in scripts to share variables
        void SetGUID(uint64 guid, int32 id = 0);

        // Used in scripts to share variables
        uint64 GetGUID(int32 id = 0) const;

        //core related
        static int Permissible(const Creature*);

        // Called at movepoint reached
        void MovepointReached(uint32 id);

        // Makes the creature run/walk
        void SetRun(bool run = true);

        void SetFly(bool fly = true);

        void SetSwim(bool swim = true);

        void SetInvincibilityHpLevel(uint32 level) { mInvincibilityHpLevel = level; }

        void sGossipHello(Player* player);
        void sGossipSelect(Player* player, uint32 sender, uint32 action);
        void sGossipSelectCode(Player* player, uint32 sender, uint32 action, const char* code);
        void sQuestAccept(Player* player, Quest const* quest);
        //void sQuestSelect(Player* player, Quest const* quest);
        //void sQuestComplete(Player* player, Quest const* quest);
        void sQuestReward(Player* player, Quest const* quest, uint32 opt);
        bool sOnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex);
        void sOnGameEvent(bool start, uint16 eventId);

        uint32 mEscortQuestID;

        void SetDespawnTime (uint32 t)
        {
            mDespawnTime = t;
            mDespawnState = t ? 1 : 0;
        }
        void StartDespawn() { mDespawnState = 2; }

        void RemoveAuras();

        void OnSpellClick(Unit* clicker, bool& result);

    private:
        uint32 mFollowCreditType;
        uint32 mFollowArrivedTimer;
        uint32 mFollowCredit;
        uint32 mFollowArrivedEntry;
        uint64 mFollowGuid;
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
        WayPoint* mLastWP;
        Position mLastOOCPos;//set on enter combat
        uint32 GetWPCount() { return mWayPoints ? mWayPoints->size() : 0; }
        bool mCanRepeatPath;
        bool mRun;
        bool mCanAutoAttack;
        bool mCanCombatMove;
        bool mForcedPaused;
        uint32 mInvincibilityHpLevel;
        bool AssistPlayerInCombat(Unit* who);

        uint32 mDespawnTime;
        uint32 mDespawnState;
        void UpdateDespawn(const uint32 diff);
        uint32 mEscortInvokerCheckTimer;
};

class SmartGameObjectAI : public GameObjectAI
{
    public:
        SmartGameObjectAI(GameObject* g) : GameObjectAI(g), go(g) {}
        ~SmartGameObjectAI() {}

        void UpdateAI(uint32 diff);
        void InitializeAI();
        void Reset();
        SmartScript* GetScript() { return &mScript; }
        static int Permissible(const GameObject* g);

        bool GossipHello(Player* player);
        bool GossipSelect(Player* player, uint32 sender, uint32 action);
        bool GossipSelectCode(Player* /*player*/, uint32 /*sender*/, uint32 /*action*/, const char* /*code*/);
        bool QuestAccept(Player* player, Quest const* quest);
        bool QuestReward(Player* player, Quest const* quest, uint32 opt);
        uint32 GetDialogStatus(Player* /*player*/);
        void Destroyed(Player* player, uint32 eventId);
        void SetData(uint32 id, uint32 value);
        void SetScript9(SmartScriptHolder& e, uint32 entry, Unit* invoker);
        void OnGameEvent(bool start, uint16 eventId);
        void OnStateChanged(uint32 state, Unit* unit);
        void EventInform(uint32 eventId);

    protected:
        GameObject* const go;
        SmartScript mScript;
};
#endif
