/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_FOLLOWERAI_H
#define SC_FOLLOWERAI_H

#include "ScriptSystem.h"

enum eFollowState
{
    STATE_FOLLOW_NONE       = 0x000,
    STATE_FOLLOW_INPROGRESS = 0x001,                        //must always have this state for any follow
    STATE_FOLLOW_RETURNING  = 0x002,                        //when returning to combat start after being in combat
    STATE_FOLLOW_PAUSED     = 0x004,                        //disables following
    STATE_FOLLOW_COMPLETE   = 0x008,                        //follow is completed and may end
    STATE_FOLLOW_PREEVENT   = 0x010,                        //not implemented (allow pre event to run, before follow is initiated)
    STATE_FOLLOW_POSTEVENT  = 0x020                         //can be set at complete and allow post event to run
};

class FollowerAI : public ScriptedAI
{
    public:
        explicit FollowerAI(Creature* creature);
        ~FollowerAI() { }

        //virtual void WaypointReached(uint32 uiPointId) = 0;

        void MovementInform(uint32 motionType, uint32 pointId);

        void AttackStart(Unit*);

        void MoveInLineOfSight(Unit*);

        void EnterEvadeMode();

        void JustDied(Unit*);

        void JustRespawned();

        void UpdateAI(uint32);                        //the "internal" update, calls UpdateFollowerAI()
        virtual void UpdateFollowerAI(uint32);        //used when it's needed to add code in update (abilities, scripted events, etc)

        void StartFollow(Player* player, uint32 factionForFollower = 0, const Quest* quest = NULL);

        void SetFollowPaused(bool bPaused);                 //if special event require follow mode to hold/resume during the follow
        void SetFollowComplete(bool bWithEndEvent = false);

        bool HasFollowState(uint32 uiFollowState) { return (m_uiFollowState & uiFollowState); }

    protected:
        Player* GetLeaderForFollower();

    private:
        void AddFollowState(uint32 uiFollowState) { m_uiFollowState |= uiFollowState; }
        void RemoveFollowState(uint32 uiFollowState) { m_uiFollowState &= ~uiFollowState; }

        bool AssistPlayerInCombat(Unit* who);

        uint64 m_uiLeaderGUID;
        uint32 m_uiUpdateFollowTimer;
        uint32 m_uiFollowState;

        const Quest* m_pQuestForFollow;                     //normally we have a quest
};

#endif
