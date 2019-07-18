/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

#include "ScriptedCreature.h"
#include "ScriptSystem.h"
#include "WaypointDefines.h"

class Quest;

#define DEFAULT_MAX_PLAYER_DISTANCE 50

enum eEscortState
{
    STATE_ESCORT_NONE       = 0x000,                        //nothing in progress
    STATE_ESCORT_ESCORTING  = 0x001,                        //escort are in progress
    STATE_ESCORT_RETURNING  = 0x002,                        //escort is returning after being in combat
    STATE_ESCORT_PAUSED     = 0x004                         //will not proceed with waypoints before state is removed
};

struct TC_GAME_API npc_escortAI : public ScriptedAI
{
    public:
        explicit npc_escortAI(Creature* creature);
        ~npc_escortAI() { }

        // CreatureAI functions

        void MoveInLineOfSight(Unit* who) override;

        void JustDied(Unit*) override;

        void JustRespawned() override;

        void ReturnToLastPoint();

        void EnterEvadeMode(EvadeReason /*why*/ = EVADE_REASON_OTHER) override;

        void UpdateAI(uint32 diff) override;        // the "internal" update, calls UpdateEscortAI()
        virtual void UpdateEscortAI(uint32 diff);   // used when it's needed to add code in update (abilities, scripted events, etc)

        void MovementInform(uint32, uint32) override;

        // EscortAI functions
        void AddWaypoint(uint32 id, float x, float y, float z, uint32 waitTime = 0);    // waitTime is in ms

        virtual void WaypointReached(uint32 pointId) = 0;
        virtual void WaypointStart(uint32 /*pointId*/) { }

        void Start(bool isActiveAttacker = true, bool run = false, ObjectGuid playerGUID = ObjectGuid::Empty, Quest const* quest = NULL, bool instantRespawn = false, bool canLoopPath = false, bool resetWaypoints = true);

        void SetRun(bool on = true);
        void SetEscortPaused(bool on);

        bool HasEscortState(uint32 escortState) { return (m_uiEscortState & escortState) != 0; }
        virtual bool IsEscorted() const override { return (m_uiEscortState & STATE_ESCORT_ESCORTING); }

        void SetMaxPlayerDistance(float newMax) { MaxPlayerDistance = newMax; }
        float GetMaxPlayerDistance() const { return MaxPlayerDistance; }

        void SetDespawnAtEnd(bool despawn) { DespawnAtEnd = despawn; }
        void SetDespawnAtFar(bool despawn) { DespawnAtFar = despawn; }
        bool GetAttack() const { return m_bIsActiveAttacker; }//used in EnterEvadeMode override
        void SetCanAttack(bool attack) { m_bIsActiveAttacker = attack; }
        ObjectGuid GetEventStarterGUID() const { return m_uiPlayerGUID; }
        void SetWaitTimer(uint32 Timer) { m_uiWPWaitTimer = Timer; }

    protected:
        Player* GetPlayerForEscort();

    private:
        bool AssistPlayerInCombatAgainst(Unit* who);
        bool IsPlayerOrGroupInRange();
        void FillPointMovementListForCreature();

        void AddEscortState(uint32 escortState) { m_uiEscortState |= escortState; }
        void RemoveEscortState(uint32 escortState) { m_uiEscortState &= ~escortState; }

        ObjectGuid m_uiPlayerGUID;
        uint32 m_uiWPWaitTimer;
        uint32 m_uiPlayerCheckTimer;
        uint32 m_uiEscortState;
        float MaxPlayerDistance;
        uint32 LastWP;

        WaypointPath _path;

        Quest const* m_pQuestForEscort;                     //generally passed in Start() when regular escort script.

        bool m_bIsActiveAttacker;                           //obsolete, determined by faction.
        bool m_bIsRunning;                                  //all creatures are walking by default (has flag MOVEMENTFLAG_WALK)
        bool m_bCanInstantRespawn;                          //if creature should respawn instantly after escort over (if not, database respawntime are used)
        bool m_bCanReturnToStart;                           //if creature can walk same path (loop) without despawn. Not for regular escort quests.
        bool DespawnAtEnd;
        bool DespawnAtFar;
        bool ScriptWP;
        bool HasImmuneToNPCFlags;
        bool m_bStarted;
        bool m_bEnded;
};
#endif
