/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

#include "ScriptSystem.h"

#define DEFAULT_MAX_PLAYER_DISTANCE 50

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

struct TRINITY_DLL_DECL npc_escortAI : public ScriptedAI
{
    public:
        explicit npc_escortAI(Creature* pCreature);
        ~npc_escortAI() {}

        // CreatureAI functions
        void AttackStart(Unit* who);

        void MoveInLineOfSight(Unit* who);

        void JustDied(Unit*);

        void JustRespawned();

        void ReturnToLastPoint();

        void EnterEvadeMode();

        void UpdateAI(const uint32);                        //the "internal" update, calls UpdateEscortAI()
        virtual void UpdateEscortAI(const uint32);          //used when it's needed to add code in update (abilities, scripted events, etc)

        void MovementInform(uint32, uint32);

        // EscortAI functions
        void AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs = 0);

        virtual void WaypointReached(uint32 uiPointId) = 0;
        virtual void WaypointStart(uint32 uiPointId) {}

        void Start(bool bIsActiveAttacker = true, bool bRun = false, uint64 uiPlayerGUID = 0, const Quest* pQuest = NULL, bool bInstantRespawn = false, bool bCanLoopPath = false);

        void SetRun(bool bRun = true);
        void SetEscortPaused(bool uPaused);

        bool HasEscortState(uint32 uiEscortState) { return (m_uiEscortState & uiEscortState); }
        virtual bool IsEscorted() { return (m_uiEscortState & STATE_ESCORT_ESCORTING); }

        void SetMaxPlayerDistance(float newMax) { MaxPlayerDistance = newMax; }
        float GetMaxPlayerDistance() { return MaxPlayerDistance; }

        void SetDespawnAtEnd(bool despawn) { DespawnAtEnd = despawn; }
        void SetDespawnAtFar(bool despawn) { DespawnAtFar = despawn; }
        bool GetAttack() { return m_bIsActiveAttacker; }//used in EnterEvadeMode override
        void SetCanAttack(bool attack) { m_bIsActiveAttacker = attack; }
        uint64 GetEventStarterGUID() { return m_uiPlayerGUID; }

    protected:
        Player* GetPlayerForEscort() { return (Player*)Unit::GetUnit(*m_creature, m_uiPlayerGUID); }

    private:
        bool AssistPlayerInCombat(Unit* pWho);
        bool IsPlayerOrGroupInRange();
        void FillPointMovementListForCreature();

        void AddEscortState(uint32 uiEscortState) { m_uiEscortState |= uiEscortState; }
        void RemoveEscortState(uint32 uiEscortState) { m_uiEscortState &= ~uiEscortState; }

        uint64 m_uiPlayerGUID;
        uint32 m_uiWPWaitTimer;
        uint32 m_uiPlayerCheckTimer;
        uint32 m_uiEscortState;
        float MaxPlayerDistance;

        const Quest* m_pQuestForEscort;                     //generally passed in Start() when regular escort script.

        std::list<Escort_Waypoint> WaypointList;
        std::list<Escort_Waypoint>::iterator CurrentWP;

        bool m_bIsActiveAttacker;                           //obsolete, determined by faction.
        bool m_bIsRunning;                                  //all creatures are walking by default (has flag MOVEMENTFLAG_WALK)
        bool m_bCanInstantRespawn;                          //if creature should respawn instantly after escort over (if not, database respawntime are used)
        bool m_bCanReturnToStart;                           //if creature can walk same path (loop) without despawn. Not for regular escort quests.
        bool DespawnAtEnd;
        bool DespawnAtFar;
        bool ScriptWP;
};
#endif

