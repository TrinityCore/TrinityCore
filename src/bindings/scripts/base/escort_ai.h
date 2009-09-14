/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

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

struct TRINITY_DLL_DECL npc_escortAI : public ScriptedAI
{
    public:
        explicit npc_escortAI(Creature* pCreature);
        ~npc_escortAI() {}

        // Pure Virtual Functions
        virtual void WaypointReached(uint32 uiPointId) = 0;
        virtual void WaypointStart(uint32 uiPointId) {}

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

        bool IsPlayerOrGroupInRange();

        Player* GetPlayerForEscort()
        {
            return Unit::GetPlayer(m_uiPlayerGUID);
        }

        void FillPointMovementListForCreature();

        void Start(bool bIsActiveAttacker = true, bool bRun = false, uint64 uiPlayerGUID = 0, const Quest* pQuest = NULL, bool bInstantRespawn = false, bool bCanLoopPath = false);

        void SetRun(bool bRun = true);

        void SetMaxPlayerDistance(float newMax) { MaxPlayerDistance = newMax; }
        float GetMaxPlayerDistance() { return MaxPlayerDistance; }

        void SetCanMelee(bool usemelee) { CanMelee = usemelee; }
        void SetDespawnAtEnd(bool despawn) { DespawnAtEnd = despawn; }
        void SetDespawnAtFar(bool despawn) { DespawnAtFar = despawn; }
        bool GetAttack() { return m_bIsActiveAttacker; }//used in EnterEvadeMode override
        bool GetIsBeingEscorted() { return IsBeingEscorted; }//used in EnterEvadeMode override
        void SetReturning(bool returning) { m_bIsReturning = returning; }//used in EnterEvadeMode override
        void SetCanAttack(bool attack) { m_bIsActiveAttacker = attack; }
        uint64 GetEventStarterGUID() { return m_uiPlayerGUID; }

    // EscortAI variables
    protected:
        bool IsBeingEscorted;
        bool IsOnHold;

    private:
        uint64 m_uiPlayerGUID;
        uint32 m_uiWPWaitTimer;
        uint32 m_uiPlayerCheckTimer;
        float MaxPlayerDistance;

        const Quest* m_pQuestForEscort;                     //generally passed in Start() when regular escort script.

        std::list<Escort_Waypoint> WaypointList;
        std::list<Escort_Waypoint>::iterator CurrentWP;

        bool m_bIsActiveAttacker;                           //possible obsolete, and should be determined with db only (civilian)
        bool m_bIsReturning;                                //in use when creature leave combat, and are returning to combat start position
        bool m_bIsRunning;                                  //all creatures are walking by default (has flag MOVEMENTFLAG_WALK)
        bool m_bCanInstantRespawn;                          //if creature should respawn instantly after escort over (if not, database respawntime are used)
        bool m_bCanReturnToStart;                           //if creature can walk same path (loop) without despawn. Not for regular escort quests.
        bool CanMelee;
        bool DespawnAtEnd;
        bool DespawnAtFar;
        bool ScriptWP;
};
#endif

