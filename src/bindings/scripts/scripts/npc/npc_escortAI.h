/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

#define DEFAULT_MAX_PLAYER_DISTANCE 50

extern UNORDERED_MAP<uint32, std::vector<PointMovement> > PointMovementMap;

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
        explicit npc_escortAI(Creature* pCreature) : ScriptedAI(pCreature),
          IsBeingEscorted(false), IsOnHold(false), PlayerGUID(0), MaxPlayerDistance(DEFAULT_MAX_PLAYER_DISTANCE), CanMelee(true), m_uiPlayerCheckTimer(1000), m_uiWPWaitTimer(0),
          m_bIsReturning(false), m_bIsActiveAttacker(true), m_bCanDefendSelf(true), m_bIsRunning(false), DespawnAtEnd(true), DespawnAtFar(true) {}
        ~npc_escortAI() {}

        // Pure Virtual Functions
        virtual void WaypointReached(uint32) = 0;

        // CreatureAI functions
        void AttackStart(Unit* who);

        void MoveInLineOfSight(Unit* who);

        void JustRespawned();

        void ReturnToLastPoint();

        void EnterEvadeMode();

        void UpdateAI(const uint32);

        void MovementInform(uint32, uint32);

        // EscortAI functions
        void AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs = 0);

        void FillPointMovementListForCreature();

        void Start(bool bIsActiveAttacker = true, bool bCanDefendSelf = true, bool bRun = false, uint64 uiPlayerGUID = 0);
        void SetRun(bool bRun = true);

        void SetMaxPlayerDistance(float newMax) { MaxPlayerDistance = newMax; }
        float GetMaxPlayerDistance() { return MaxPlayerDistance; }

        bool IsEscorted() {return IsBeingEscorted;}

        void SetCanMelee(bool usemelee) { CanMelee = usemelee; }
        void SetDespawnAtEnd(bool despawn) { DespawnAtEnd = despawn; }
        void SetDespawnAtFar(bool despawn) { DespawnAtFar = despawn; }
        bool GetAttack() { return m_bIsActiveAttacker; }//used in EnterEvadeMode override
        bool GetIsBeingEscorted() { return IsBeingEscorted; }//used in EnterEvadeMode override
        void SetReturning(bool returning) { m_bIsReturning = returning; }//used in EnterEvadeMode override
        void SetCanAttack(bool attack) { m_bIsActiveAttacker = attack; }
        void SetCanDefend(bool defend) { m_bCanDefendSelf = defend; }        
        uint64 GetEventStarterGUID() { return PlayerGUID; }

    // EscortAI variables
    protected:
        uint64 PlayerGUID;
        bool IsBeingEscorted;
        bool IsOnHold;

    private:
        uint32 m_uiWPWaitTimer;
        uint32 m_uiPlayerCheckTimer;
        float MaxPlayerDistance;

        std::list<Escort_Waypoint> WaypointList;
        std::list<Escort_Waypoint>::iterator CurrentWP;

        bool m_bIsActiveAttacker;                           //possible obsolete, and should be determined with db only (civilian)
        bool m_bCanDefendSelf;                              //rarely used, is true in 99%
        bool m_bIsReturning;                                //in use when creature leave combat, and are returning to combat start position
        bool m_bIsRunning;                                  //all creatures are walking by default (has flag MOVEMENTFLAG_WALK)
        bool CanMelee;
        bool DespawnAtEnd;
        bool DespawnAtFar;
};
#endif

