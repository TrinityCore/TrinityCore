/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

#include "ScriptedAI.h"

class Quest;

struct Escort_Waypoint
{
    Escort_Waypoint(uint32 _id, float _x, float _y, float _z, uint32 _w)
    {
        id = _id;
        x = _x;
        y = _y;
        z = _z;
        WaitTimeMs = _w;
    }

    uint32 id;
    float x;
    float y;
    float z;
    uint32 WaitTimeMs;
};

enum eEscortState
{
    STATE_ESCORT_NONE       = 0x000,                        //nothing in progress
    STATE_ESCORT_ESCORTING  = 0x001,                        //escort are in progress
    STATE_ESCORT_RETURNING  = 0x002,                        //escort is returning after being in combat
    STATE_ESCORT_PAUSED     = 0x004                         //will not proceed with waypoints before state is removed
};

class ChatHandler;

struct npc_escortAI : ScriptedAI
{
        explicit npc_escortAI(Creature* pCreature);
        ~npc_escortAI() override {}

        void Aggro(Unit*) override;

        void Reset() override = 0;

        void ResetCreature() override {}

        // CreatureAI functions
        void AttackStart(Unit*) override;

        void EnterCombat(Unit*) override;

        void MoveInLineOfSight(Unit*) override;

        void JustDied(Unit*) override;

        void setCurrentWP (uint32 wp);
        uint32 getCurrentWP() const { return m_currentWaypointIdx; }

        void JustRespawned() override;

        void EnterEvadeMode() override;

        void UpdateAI(uint32 const) override;               //the "internal" update, calls UpdateEscortAI()
        virtual void UpdateEscortAI(uint32 const);          //used when it's needed to add code in update (abilities, scripted events, etc)

        void ResetEscort();                                 // Kills the NPC and returns it to the original state

        void MovementInform(uint32, uint32) override;

        // EscortAI functions
        //void AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs = 0);

        virtual void WaypointReached(uint32 uiPointId) = 0;
        virtual void WaypointStart(uint32 /*uiPointId*/) {}

        void Start(bool bRun = false, uint64 uiPlayerGUID = 0, Quest const* pQuest = nullptr, bool bInstantRespawn = false, bool bCanLoopPath = false);
        void Stop();
        void SetRun(bool bRun = true);
        void SetEscortPaused(bool uPaused);

        //! Enables/disables pathfinding between waypoints. Pathfinding is enabled by default.
        void SetPathfindingEnabledBetweenWaypoints(bool bEnabled) { m_bIsPathfindingEnabledBetweenWaypoints = bEnabled; }
        //! Controls a delay for before the first waypoint(in milliseconds). 0: prevents waypoint path to start. Default: 2500.
        void SetDelayBeforeTheFirstWaypoint(uint32 uiWPDelayMs) { m_uiDelayBeforeTheFirstWaypoint = uiWPDelayMs; }

        bool HasEscortState(uint32 uiEscortState) const { return m_uiEscortState & uiEscortState; }
        void SetMaxPlayerDistance(float dist) { m_MaxPlayerDistance = dist;}
        void SetMaxAssistDistance(float dist) { m_MaxAssistDistance = dist;}
        void GetAIInformation(ChatHandler& /*reader*/) override;

        void ReturnToCombatStartPosition();

        void AddEscortState(uint32 uiEscortState) { m_uiEscortState |= uiEscortState; }
        void RemoveEscortState(uint32 uiEscortState) { m_uiEscortState &= ~uiEscortState; }

        // use distinct position from Creature to prevent unnecessary overrides
        void SetCombatStartPosition(float x, float y, float z) { m_combatStartX = x; m_combatStartY = y; m_combatStartZ = z; }
        void GetCombatStartPosition(float &x, float &y, float &z) const { x = m_combatStartX; y = m_combatStartY; z = m_combatStartZ; }

    protected:
        Player* GetPlayerForEscort() const;
        virtual void JustStartedEscort() {}

    private:
        bool AssistPlayerInCombat(Unit* pWho);
        bool IsPlayerOrGroupInRange() const;
        void FillPointMovementListForCreature();

        uint64 m_uiPlayerGUID;
        uint32 m_uiWPWaitTimer;
        uint32 m_uiPlayerCheckTimer;
        uint32 m_uiEscortState;
        uint32 m_uiDelayBeforeTheFirstWaypoint;

        Quest const* m_pQuestForEscort;                     //generally passed in Start() when regular escort script.

        std::vector<Escort_Waypoint> WaypointList;
        uint32  m_currentWaypointIdx;
        std::vector<Escort_Waypoint>::iterator CurrentWP;

        bool m_bIsRunning;                                  //all creatures are walking by default (has flag SPLINEFLAG_WALKMODE)
        bool m_bCanInstantRespawn;                          //if creature should respawn instantly after escort over (if not, database respawntime are used)
        bool m_bCanReturnToStart;                           //if creature can walk same path (loop) without despawn. Not for regular escort quests.
        bool m_bIsPathfindingEnabledBetweenWaypoints;       //all creatures are using pathfinding between waypoints by default

        float m_MaxPlayerDistance;
        float m_MaxAssistDistance;
        float m_combatStartX, m_combatStartY, m_combatStartZ, m_combatStartO;
};
#endif
