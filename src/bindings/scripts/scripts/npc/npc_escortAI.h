/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_ESCORTAI_H
#define SC_ESCORTAI_H

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

        // Pure Virtual Functions
        virtual void WaypointReached(uint32) = 0;

        virtual void Aggro(Unit*) = 0;

        virtual void Reset() = 0;

        // CreatureAI functions
        npc_escortAI(Creature *c) : ScriptedAI(c), IsBeingEscorted(false), PlayerTimer(1000) {m_creature->GetPosition(LastPos.x, LastPos.y, LastPos.z);}

        bool IsVisible(Unit*) const;

        void AttackStart(Unit*);

        void MoveInLineOfSight(Unit*);

        void JustRespawned();

        void EnterEvadeMode();

        void UpdateAI(const uint32);

        void MovementInform(uint32, uint32);

        void OnPossess(bool apply);

        // EscortAI functions
        void AddWaypoint(uint32 id, float x, float y, float z, uint32 WaitTimeMs = 0);

        void Start(bool bAttack, bool bDefend, bool bRun, uint64 pGUID = 0);

    // EscortAI variables
    protected:
        uint64 PlayerGUID;
        bool IsBeingEscorted;
        bool IsOnHold;

    private:
        uint32 WaitTimer;
        uint32 PlayerTimer;

        struct
        {
            float x;
            float y;
            float z;
        }LastPos;

        std::list<Escort_Waypoint> WaypointList;
        std::list<Escort_Waypoint>::iterator CurrentWP;

        bool Attack;
        bool Defend;
        bool Returning;
        bool ReconnectWP;
        bool Run;
};
#endif
