/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_FOLLOWERAI_H
#define SC_FOLLOWERAI_H

class TRINITY_DLL_DECL FollowerAI : public ScriptedAI
{
    public:
        explicit FollowerAI(Creature* pCreature);
        ~FollowerAI() {}

        //virtual void WaypointReached(uint32 uiPointId) = 0;

        void MovementInform(uint32 uiMotionType, uint32 uiPointId);

        void AttackStart(Unit*);

        void MoveInLineOfSight(Unit*);

        void EnterEvadeMode();

        void JustDied(Unit*);

        void JustRespawned();

        void UpdateAI(const uint32);                        //the "internal" update, calls UpdateFollowerAI()
        virtual void UpdateFollowerAI(const uint32);        //used when it's needed to add code in update (abilities, scripted events, etc)

        void StartFollow(Player* pPlayer, uint32 uiFactionForFollower = 0, const Quest* pQuest = NULL);

    protected:
        void SetFollowComplete() { m_bIsFollowComplete = true; }
        bool IsFollowComplete() { return m_bIsFollowComplete; }

        Player* GetLeaderForFollower();

    private:
        uint64 m_uiLeaderGUID;
        uint32 m_uiUpdateFollowTimer;

        bool m_bIsFollowing;
        bool m_bIsReturnToLeader;
        bool m_bIsFollowComplete;

        const Quest* m_pQuestForFollow;                     //normally we have a quest
};

#endif
