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

#ifndef TRINITY_SCRIPTEDESCORTAI_H
#define TRINITY_SCRIPTEDESCORTAI_H

#include "ScriptedCreature.h"
#include "WaypointDefines.h"

class Quest;

#define DEFAULT_MAX_PLAYER_DISTANCE 100

enum EscortState : uint32
{
    STATE_ESCORT_NONE       = 0x00, // nothing in progress
    STATE_ESCORT_ESCORTING  = 0x01, // escort is in progress
    STATE_ESCORT_RETURNING  = 0x02, // escort is returning after being in combat
    STATE_ESCORT_PAUSED     = 0x04  // escort is paused, wont continue with next waypoint
};

struct TC_GAME_API EscortAI : public ScriptedAI
{
    public:
        explicit EscortAI(Creature* creature);
        ~EscortAI() { }

        void InitializeAI() override;
        void MoveInLineOfSight(Unit* who) override;
        void JustDied(Unit*) override;
        void ReturnToLastPoint();
        void EnterEvadeMode(EvadeReason why) override;
        void MovementInform(uint32, uint32) override;
        void UpdateAI(uint32 diff) override; // the "internal" update, calls UpdateEscortAI()

        virtual void UpdateEscortAI(uint32 diff); // used when it's needed to add code in update (abilities, scripted events, etc)
        void AddWaypoint(uint32 id, float x, float y, float z, bool run);
        void AddWaypoint(uint32 id, float x, float y, float z, float orientation = 0.f, Optional<Milliseconds> waitTime = {}, bool run = false);
        void ResetPath();
        void LoadPath(uint32 pathId);
        void Start(bool isActiveAttacker = true, ObjectGuid playerGUID = ObjectGuid::Empty, Quest const* quest = nullptr, bool instantRespawn = false, bool canLoopPath = false);

        void SetEscortPaused(bool on);
        void SetPauseTimer(Milliseconds timer) { _pauseTimer = timer; }
        bool HasEscortState(uint32 escortState) { return (_escortState & escortState) != 0; }
        bool IsEscorted() const override { return !_playerGUID.IsEmpty(); }
        void SetMaxPlayerDistance(float newMax) { _maxPlayerDistance = newMax; }
        float GetMaxPlayerDistance() const { return _maxPlayerDistance; }
        void SetDespawnAtEnd(bool despawn) { _despawnAtEnd = despawn; }
        void SetDespawnAtFar(bool despawn) { _despawnAtFar = despawn; }
        bool IsActiveAttacker() const { return _activeAttacker; } // obsolete
        void SetActiveAttacker(bool enable) { _activeAttacker = enable; }
        ObjectGuid GetEventStarterGUID() const { return _playerGUID; }

    protected:
        Player* GetPlayerForEscort();

    private:
        bool AssistPlayerInCombatAgainst(Unit* who);
        bool IsPlayerOrGroupInRange();

        void AddEscortState(uint32 escortState) { _escortState |= escortState; }
        void RemoveEscortState(uint32 escortState) { _escortState &= ~escortState; }

        ObjectGuid _playerGUID;
        Milliseconds _pauseTimer;
        uint32 _playerCheckTimer;
        uint32 _escortState;
        float _maxPlayerDistance;

        Quest const* _escortQuest; // generally passed in Start() when regular escort script.

        WaypointPath _path;

        bool _activeAttacker;      // obsolete, determined by faction.
        bool _instantRespawn;      // if creature should respawn instantly after escort over (if not, database respawntime are used)
        bool _returnToStart;       // if creature can walk same path (loop) without despawn. Not for regular escort quests.
        bool _despawnAtEnd;
        bool _despawnAtFar;
        bool _hasImmuneToNPCFlags;
        bool _started;
        bool _ended;
        bool _resume;
};

#endif
