/*#ifndef __CHALLENGEMGR_H
#define __CHALLENGEMGR_H
 
#include "BattlegroundMgr.h"
#include "Player.h"
#include "Chat.h"
#include <ace/Singleton.h>
 
// not used for now
//enum ChallengeErrors {
//    CHALLENGE_ERR_OK,
//    CHALLENGE_ERR_IN_BG,
//    CHALLENGE_ERR_CANT_FIND_PLAYER
//};
 
enum ArenaChallengeType {
    ARENA_CHALLENGE_TYPE_1v1    = 1,
    ARENA_CHALLENGE_TYPE_2v2    = 2,
    ARENA_CHALLENGE_TYPE_3v3    = 3,
    ARENA_CHALLENGE_TYPE_5v5    = 5
};
 
enum ChallengeIntervals {
    CHALLENGE_OFFER_WAITING   = 20000, // 20 sec
    CHALLENGE_START_COUNTDOWN = 40000 // 40 sec
};
 
struct ChallengeOption {
    uint8 mode;
    bool enable;
 
    bool changed;        // for saving in db
};
 
class ChallengeMgr {
 
        friend class ACE_Singleton<ChallengeMgr, ACE_Null_Mutex>;
 
    private:
        ChallengeMgr() {}
        ~ChallengeMgr() {}
 
    public:
        void Update(uint32 diff);
 
        void LoadOptions();
 
        bool InviteGroupsToArena(Player *leader1, Player *leader2, ArenaChallengeType type);
        bool CanInvitePlayer(Player *player, BattlegroundQueueTypeId bgQueueTypeId);
 
        bool MakeChallengeOffer(Player *challenger, Player *challengeTo, ArenaChallengeType type, ChatHandler* handler);
 
        GroupQueueInfo* CreateGroupQueueInfo(Player *player, BattlegroundTypeId bgTypeId, uint8 arenatype);
        GroupQueueInfo* CreateGroupQueueInfo(Group *group, BattlegroundTypeId bgTypeId, uint8 arenatype);
 
        typedef std::map<uint64, ChallengeOption*> OptionsContainer;
        ChallengeOption* GetChallengeOption(uint64 playerGuid);
 
    private:
        bool InviteGroupToArena(GroupQueueInfo* ginfo, Battleground* bg, uint32 side);
 
        OptionsContainer m_options;
        EventProcessor m_events;
};
 
class ChallengeWaitingAcceptEvent : public BasicEvent
{
    public:
        ChallengeWaitingAcceptEvent(uint64 pl_guid)
            : m_PlayerGuid(pl_guid)
        {}
 
        virtual ~ChallengeWaitingAcceptEvent() {}
 
        virtual bool Execute(uint64 e_time, uint32 p_time);
        virtual void Abort(uint64 e_time);
    private:
        uint64 m_PlayerGuid;
};
#define sChallengeMgr ACE_Singleton<ChallengeMgr, ACE_Null_Mutex>::instance()
#endif