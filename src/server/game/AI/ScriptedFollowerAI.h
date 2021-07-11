/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_FOLLOWERAI_H
#define SC_FOLLOWERAI_H

#include "ScriptedAI.h"
#include "Pet.h"

class Player;

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
        explicit FollowerAI(Creature* pCreature);
        ~FollowerAI() override {}

        //virtual void WaypointReached(uint32 uiPointId) = 0;

        void MovementInform(uint32 uiMotionType, uint32 uiPointId) override;

        void AttackStart(Unit*) override;

        void MoveInLineOfSight(Unit*) override;

        void EnterEvadeMode() override;

        void JustDied(Unit*) override;

        void JustRespawned() override;

        void UpdateAI(uint32 const) override;               // the "internal" update, calls UpdateFollowerAI()
        virtual void UpdateFollowerAI(uint32 const);        // used when it's needed to add code in update (abilities, scripted events, etc)

        void StartFollow(Player* pPlayer, uint32 uiFactionForFollower = 0, Quest const* pQuest = nullptr, float followDist = PET_FOLLOW_DIST);

        void SetFollowPaused(bool bPaused);                 // if special event require follow mode to hold/resume during the follow
        void SetFollowComplete(bool bWithEndEvent = false);
        virtual void OnEscortFailed(bool bDied) {};

        bool HasFollowState(uint32 uiFollowState) const { return m_uiFollowState & uiFollowState; }

        void GetAIInformation(ChatHandler& /*reader*/) override;

    protected:
        Player* GetLeaderForFollower();

    private:
        void AddFollowState(uint32 uiFollowState) { m_uiFollowState |= uiFollowState; }
        void RemoveFollowState(uint32 uiFollowState) { m_uiFollowState &= ~uiFollowState; }

        bool AssistPlayerInCombat(Unit* pWho);

        uint64 m_uiLeaderGUID;
        uint32 m_uiUpdateFollowTimer;
        uint32 m_uiFollowState;

        Quest const* m_pQuestForFollow;                     //normally we have a quest

        float m_uiFollowDistance;
};

#endif
