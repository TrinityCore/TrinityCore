/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _LFGMGR_H
#define _LFGMGR_H

#include "Common.h"
#include <ace/Singleton.h>
#include "LFG.h"
#include "LFGGroupData.h"
#include "LFGPlayerData.h"

class LFGPlayerScript;
class LFGGroupScript;
class Group;
class Player;

enum LFGMgrEnum
{
    LFG_TIME_ROLECHECK                           = 40 * IN_MILLISECONDS,
    LFG_TIME_BOOT                                = 120,
    LFG_TIME_PROPOSAL                            = 120,
    LFG_QUEUEUPDATE_INTERVAL                     = 15 * IN_MILLISECONDS,
    LFG_SPELL_DUNGEON_COOLDOWN                   = 71328,
    LFG_SPELL_DUNGEON_DESERTER                   = 71041,
    LFG_SPELL_LUCK_OF_THE_DRAW                   = 72221,
    LFG_GROUP_KICK_VOTES_NEEDED                  = 3
};

enum LfgFlags
{
    LFG_FLAG_UNK1                                = 0x1,
    LFG_FLAG_UNK2                                = 0x2,
    LFG_FLAG_SEASONAL                            = 0x4,
    LFG_FLAG_UNK3                                = 0x8
};

/// Determines the type of instance
enum LfgType
{
    LFG_TYPE_NONE                                = 0,
    LFG_TYPE_DUNGEON                             = 1,
    LFG_TYPE_RAID                                = 2,
    LFG_TYPE_HEROIC                              = 5,
    LFG_TYPE_RANDOM                              = 6
};

/// Proposal states
enum LfgProposalState
{
    LFG_PROPOSAL_INITIATING                      = 0,
    LFG_PROPOSAL_FAILED                          = 1,
    LFG_PROPOSAL_SUCCESS                         = 2
};

/// Teleport errors
enum LfgTeleportError
{
    // 7 = "You can't do that right now" | 5 = No client reaction
    LFG_TELEPORTERROR_OK                         = 0,      // Internal use
    LFG_TELEPORTERROR_PLAYER_DEAD                = 1,
    LFG_TELEPORTERROR_FALLING                    = 2,
    LFG_TELEPORTERROR_IN_VEHICLE                 = 3,
    LFG_TELEPORTERROR_FATIGUE                    = 4,
    LFG_TELEPORTERROR_INVALID_LOCATION           = 6,
    LFG_TELEPORTERROR_CHARMING                   = 8       // FIXME - It can be 7 or 8 (Need proper data)
};

/// Queue join results
enum LfgJoinResult
{
    // 3 = No client reaction | 18 = "Rolecheck failed"
    LFG_JOIN_OK                                  = 0,      // Joined (no client msg)
    LFG_JOIN_FAILED                              = 1,      // RoleCheck Failed
    LFG_JOIN_GROUPFULL                           = 2,      // Your group is full
    LFG_JOIN_INTERNAL_ERROR                      = 4,      // Internal LFG Error
    LFG_JOIN_NOT_MEET_REQS                       = 5,      // You do not meet the requirements for the chosen dungeons
    LFG_JOIN_PARTY_NOT_MEET_REQS                 = 6,      // One or more party members do not meet the requirements for the chosen dungeons
    LFG_JOIN_MIXED_RAID_DUNGEON                  = 7,      // You cannot mix dungeons, raids, and random when picking dungeons
    LFG_JOIN_MULTI_REALM                         = 8,      // The dungeon you chose does not support players from multiple realms
    LFG_JOIN_DISCONNECTED                        = 9,      // One or more party members are pending invites or disconnected
    LFG_JOIN_PARTY_INFO_FAILED                   = 10,     // Could not retrieve information about some party members
    LFG_JOIN_DUNGEON_INVALID                     = 11,     // One or more dungeons was not valid
    LFG_JOIN_DESERTER                            = 12,     // You can not queue for dungeons until your deserter debuff wears off
    LFG_JOIN_PARTY_DESERTER                      = 13,     // One or more party members has a deserter debuff
    LFG_JOIN_RANDOM_COOLDOWN                     = 14,     // You can not queue for random dungeons while on random dungeon cooldown
    LFG_JOIN_PARTY_RANDOM_COOLDOWN               = 15,     // One or more party members are on random dungeon cooldown
    LFG_JOIN_TOO_MUCH_MEMBERS                    = 16,     // You can not enter dungeons with more that 5 party members
    LFG_JOIN_USING_BG_SYSTEM                     = 17      // You can not use the dungeon system while in BG or arenas
};

/// Role check states
enum LfgRoleCheckState
{
    LFG_ROLECHECK_DEFAULT                        = 0,      // Internal use = Not initialized.
    LFG_ROLECHECK_FINISHED                       = 1,      // Role check finished
    LFG_ROLECHECK_INITIALITING                   = 2,      // Role check begins
    LFG_ROLECHECK_MISSING_ROLE                   = 3,      // Someone didn't selected a role after 2 mins
    LFG_ROLECHECK_WRONG_ROLES                    = 4,      // Can't form a group with that role selection
    LFG_ROLECHECK_ABORTED                        = 5,      // Someone leave the group
    LFG_ROLECHECK_NO_ROLE                        = 6       // Someone selected no role
};

// Forward declaration (just to have all typedef together)
struct LFGDungeonEntry;
struct LfgReward;
struct LfgQueueInfo;
struct LfgRoleCheck;
struct LfgProposal;
struct LfgProposalPlayer;
struct LfgPlayerBoot;

typedef std::map<uint8, LfgGuidList> LfgGuidListMap;
typedef std::set<Player*> PlayerSet;
typedef std::list<Player*> LfgPlayerList;
typedef std::multimap<uint32, LfgReward const*> LfgRewardMap;
typedef std::pair<LfgRewardMap::const_iterator, LfgRewardMap::const_iterator> LfgRewardMapBounds;
typedef std::map<std::string, LfgAnswer> LfgCompatibleMap;
typedef std::map<uint8, LfgDungeonSet> LfgCachedDungeonMap;
typedef std::map<uint64, LfgAnswer> LfgAnswerMap;
typedef std::map<uint64, LfgRoleCheck> LfgRoleCheckMap;
typedef std::map<uint64, LfgQueueInfo*> LfgQueueInfoMap;
typedef std::map<uint32, LfgProposal*> LfgProposalMap;
typedef std::map<uint64, LfgProposalPlayer*> LfgProposalPlayerMap;
typedef std::map<uint64, LfgPlayerBoot> LfgPlayerBootMap;
typedef std::map<uint64, LfgGroupData> LfgGroupDataMap;
typedef std::map<uint64, LfgPlayerData> LfgPlayerDataMap;
typedef UNORDERED_MAP<uint32, LFGDungeonEntry> LFGDungeonMap;

// Data needed by SMSG_LFG_JOIN_RESULT
struct LfgJoinResultData
{
    LfgJoinResultData(LfgJoinResult _result = LFG_JOIN_OK, LfgRoleCheckState _state = LFG_ROLECHECK_DEFAULT):
        result(_result), state(_state) {}
    LfgJoinResult result;
    LfgRoleCheckState state;
    LfgLockPartyMap lockmap;
};

// Data needed by SMSG_LFG_UPDATE_PARTY and SMSG_LFG_UPDATE_PLAYER
struct LfgUpdateData
{
    LfgUpdateData(LfgUpdateType _type = LFG_UPDATETYPE_DEFAULT): updateType(_type), comment("") {}
    LfgUpdateData(LfgUpdateType _type, LfgDungeonSet const& _dungeons, std::string _comment):
        updateType(_type), dungeons(_dungeons), comment(_comment) {}

    LfgUpdateType updateType;
    LfgDungeonSet dungeons;
    std::string comment;
};

// Data needed by SMSG_LFG_QUEUE_STATUS
struct LfgQueueStatusData
{
    LfgQueueStatusData(uint32 _dungeonId = 0, int32 _waitTime = -1, int32 _waitTimeAvg = -1, int32 _waitTimeTank = -1, int32 _waitTimeHealer = -1,
        int32 _waitTimeDps = -1, uint32 _queuedTime = 0, uint8 _tanks = 0, uint8 _healers = 0, uint8 _dps = 0) :
        dungeonId(_dungeonId), waitTime(_waitTime), waitTimeAvg(_waitTimeAvg), waitTimeTank(_waitTimeTank), waitTimeHealer(_waitTimeHealer),
        waitTimeDps(_waitTimeDps), queuedTime(_queuedTime), tanks(_tanks), healers(_healers), dps(_dps) {}

    uint32 dungeonId;
    int32 waitTime;
    int32 waitTimeAvg;
    int32 waitTimeTank;
    int32 waitTimeHealer;
    int32 waitTimeDps;
    uint32 queuedTime;
    uint8 tanks;
    uint8 healers;
    uint8 dps;
};

/// Reward info
struct LfgReward
{
    uint32 maxLevel;
    struct
    {
        uint32 questId;
        uint32 variableMoney;
        uint32 variableXP;
    } reward[2];

    LfgReward(uint32 _maxLevel = 0, uint32 firstQuest = 0, uint32 firstVarMoney = 0, uint32 firstVarXp = 0, uint32 otherQuest = 0, uint32 otherVarMoney = 0, uint32 otherVarXp = 0)
        : maxLevel(_maxLevel)
    {
        reward[0].questId = firstQuest;
        reward[0].variableMoney = firstVarMoney;
        reward[0].variableXP = firstVarXp;
        reward[1].questId = otherQuest;
        reward[1].variableMoney = otherVarMoney;
        reward[1].variableXP = otherVarXp;
    }
};

/// Stores player or group queue info
struct LfgQueueInfo
{
    LfgQueueInfo(): joinTime(0), tanks(LFG_TANKS_NEEDED), healers(LFG_HEALERS_NEEDED), dps(LFG_DPS_NEEDED) {};
    time_t joinTime;                                       ///< Player queue join time (to calculate wait times)
    uint8 tanks;                                           ///< Tanks needed
    uint8 healers;                                         ///< Healers needed
    uint8 dps;                                             ///< Dps needed
    LfgDungeonSet dungeons;                                ///< Selected Player/Group Dungeon/s
    LfgRolesMap roles;                                     ///< Selected Player Role/s
};

/// Stores player data related to proposal to join
struct LfgProposalPlayer
{
    LfgProposalPlayer(): role(0), accept(LFG_ANSWER_PENDING), groupLowGuid(0) {};
    uint8 role;                                            ///< Proposed role
    LfgAnswer accept;                                      ///< Accept status (-1 not answer | 0 Not agree | 1 agree)
    uint32 groupLowGuid;                                   ///< Original group guid (Low guid) 0 if no original group
};

/// Stores group data related to proposal to join
struct LfgProposal
{
    LfgProposal(uint32 dungeon = 0): dungeonId(dungeon), state(LFG_PROPOSAL_INITIATING), groupLowGuid(0), leader(0), cancelTime(0) {}

    ~LfgProposal()
    {
        for (LfgProposalPlayerMap::iterator it = players.begin(); it != players.end(); ++it)
            delete it->second;
    };
    uint32 dungeonId;                                      ///< Dungeon to join
    LfgProposalState state;                                ///< State of the proposal
    uint32 groupLowGuid;                                   ///< Proposal group (0 if new)
    uint64 leader;                                         ///< Leader guid.
    time_t cancelTime;                                     ///< Time when we will cancel this proposal
    LfgGuidList queues;                                    ///< Queue Ids to remove/readd
    LfgProposalPlayerMap players;                          ///< Players data
};

/// Stores all rolecheck info of a group that wants to join
struct LfgRoleCheck
{
    time_t cancelTime;                                     ///< Time when the rolecheck will fail
    LfgRolesMap roles;                                     ///< Player selected roles
    LfgRoleCheckState state;                               ///< State of the rolecheck
    LfgDungeonSet dungeons;                                ///< Dungeons group is applying for (expanded random dungeons)
    uint32 rDungeonId;                                     ///< Random Dungeon Id.
    uint64 leader;                                         ///< Leader of the group
};

/// Stores information of a current vote to kick someone from a group
struct LfgPlayerBoot
{
    time_t cancelTime;                                     ///< Time left to vote
    bool inProgress;                                       ///< Vote in progress
    LfgAnswerMap votes;                                    ///< Player votes (-1 not answer | 0 Not agree | 1 agree)
    uint64 victim;                                         ///< Player guid to be kicked (can't vote)
    uint8 votedNeeded;                                     ///< Votes needed to kick the player
    std::string reason;                                    ///< kick reason
};

struct LFGDungeonEntry
{
    LFGDungeonEntry(): id(0), name(""), map(0), type(0), expansion(0), group(0), minlevel(0),
        maxlevel(0), difficulty(REGULAR_DIFFICULTY), seasonal(false), x(0.0f), y(0.0f), z(0.0f), o(0.0f)
        { }
    LFGDungeonEntry(LFGDungeonEntryDbc const* dbc): id(dbc->ID), name(dbc->name[0]), map(dbc->map),
        type(dbc->type), expansion(dbc->expansion), group(dbc->grouptype),
        minlevel(dbc->minlevel), maxlevel(dbc->maxlevel), difficulty(Difficulty(dbc->difficulty)),
        seasonal(dbc->flags & LFG_FLAG_SEASONAL), x(0.0f), y(0.0f), z(0.0f), o(0.0f)
        { }

    uint32 id;
    std::string name;
    uint16 map;
    uint8 type;
    uint8 expansion;
    uint8 group;
    uint8 minlevel;
    uint8 maxlevel;
    Difficulty difficulty;
    bool seasonal;
    float x, y, z, o;

    // Helpers
    uint32 Entry() const { return id + (type << 24); }
};

class LFGMgr
{
    friend class ACE_Singleton<LFGMgr, ACE_Null_Mutex>;

    private:
        LFGMgr();
        ~LFGMgr();

    public:
        void Update(uint32 diff);

        // Reward
        void LoadRewards();
        void RewardDungeonDoneFor(uint32 const dungeonId, Player* player);
        LfgReward const* GetRandomDungeonReward(uint32 dungeon, uint8 level);

        // Queue
        void JoinLfg(Player* player, uint8 roles, LfgDungeonSet& dungeons, std::string const& comment);
        void LeaveLfg(Player* player, Group* grp = NULL);

        // Role Check
        void UpdateRoleCheck(uint64 gguid, uint64 guid = 0, uint8 roles = PLAYER_ROLE_NONE);

        // Proposals
        void UpdateProposal(uint32 proposalId, uint64 guid, bool accept);

        // Teleportation
        void TeleportPlayer(Player* player, bool out, bool fromOpcode = false);

        // Vote kick
        void InitBoot(Group* grp, uint64 kguid, uint64 vguid, std::string const& reason);
        void UpdateBoot(Player* player, bool accept);
        void OfferContinue(Group* grp);

        void InitializeLockedDungeons(Player* player, uint8 level = 0);

        void SetRoles(uint64 guid, uint8 roles);
        void SetComment(uint64 guid, std::string const& comment);
        void SetState(uint64 guid, LfgState state);
        void SetSelectedDungeons(uint64 guid, LfgDungeonSet const& dungeons);

        void _LoadFromDB(Field* fields, uint64 guid);
        void _SaveToDB(uint64 guid, uint32 db_guid);

        void RemovePlayerData(uint64 guid);
        void RemoveGroupData(uint64 guid);

        LfgLockMap const& GetLockedDungeons(uint64 guid);
        LfgDungeonSet const& GetSelectedDungeons(uint64 guid);
        uint32 GetDungeon(uint64 guid, bool asId = true);
        LfgState GetState(uint64 guid);
        uint8 GetKicksLeft(uint64 gguid);
        bool IsLfgGroup(uint64 guid);
        uint8 GetRoles(uint64 guid);
        std::string const& GetComment(uint64 gguid);
        bool IsTeleported(uint64 guid);

        static bool HasIgnore(uint64 guid1, uint64 guid2);
        static void SendLfgQueueStatus(uint64 guid, LfgQueueStatusData const& data);

        bool IsSeasonActive(uint32 dungeonId);

        static std::string ConcatenateDungeons(LfgDungeonSet const& dungeons);
        static std::string GetRolesString(uint8 roles);
        static char const * GetStateString(LfgState state);

        void LoadLFGDungeons(bool reload = false);
        LFGDungeonEntry const* GetLFGDungeon(uint32 id);
        LFGDungeonMap& GetLFGDungeonMap();

        void ClearState(uint64 guid, char const *debugMsg);
    private:

        void RestoreState(uint64 guid, char const *debugMsg);
        
        void SetDungeon(uint64 guid, uint32 dungeon);
        void SetLockedDungeons(uint64 guid, LfgLockMap const& lock);
        void DecreaseKicksLeft(uint64 guid);

        // Queue
        void AddToQueue(uint64 guid, uint8 queueId);
        bool RemoveFromQueue(uint64 guid);

        // Proposals
        void RemoveProposal(LfgProposalMap::iterator itProposal, LfgUpdateType type);

        // Group Matching
        LfgProposal* FindNewGroups(LfgGuidList& check, LfgGuidList& all);
        bool CheckGroupRoles(LfgRolesMap &groles, bool removeLeaderFlag = true);
        bool CheckCompatibility(LfgGuidList check, LfgProposal*& pProposal);
        void GetCompatibleDungeons(LfgDungeonSet& dungeons, PlayerSet const& players, LfgLockPartyMap& lockMap);
        void SetCompatibles(std::string concatenatedGuids, bool compatibles);
        LfgAnswer GetCompatibles(std::string concatenatedGuids);
        void RemoveFromCompatibles(uint64 guid);

        // Generic
        LfgDungeonSet const& GetDungeonsByRandom(uint32 randomdungeon);
        LfgType GetDungeonType(uint32 dungeon);
        std::string ConcatenateGuids(LfgGuidList check);

        void SendLfgBootProposalUpdate(uint64 guid, LfgPlayerBoot const& boot);
        void SendLfgJoinResult(uint64 guid, LfgJoinResultData const& data);
        void SendLfgRoleChosen(uint64 guid, uint64 pguid, uint8 roles);
        void SendLfgRoleCheckUpdate(uint64 guid, LfgRoleCheck const& roleCheck);
        void SendLfgUpdateParty(uint64 guid, LfgUpdateData const& data);
        void SendLfgUpdatePlayer(uint64 guid, LfgUpdateData const& data);
        void SendLfgUpdateProposal(uint64 guid, uint32 proposalId, LfgProposal const& proposal);

        // General variables
        uint32 m_QueueTimer;                               ///< used to check interval of update
        uint32 m_lfgProposalId;                            ///< used as internal counter for proposals
        uint32 m_options;                                  ///< Stores config options

        int32 m_WaitTimeAvg;                               ///< Average wait time to find a group queuing as multiple roles
        int32 m_WaitTimeTank;                              ///< Average wait time to find a group queuing as tank
        int32 m_WaitTimeHealer;                            ///< Average wait time to find a group queuing as healer
        int32 m_WaitTimeDps;                               ///< Average wait time to find a group queuing as dps
        uint32 m_NumWaitTimeAvg;                           ///< Num of players used to calc avs wait time
        uint32 m_NumWaitTimeTank;                          ///< Num of players used to calc tank wait time
        uint32 m_NumWaitTimeHealer;                        ///< Num of players used to calc healers wait time
        uint32 m_NumWaitTimeDps;                           ///< Num of players used to calc dps wait time
        LfgCachedDungeonMap m_CachedDungeonMap;            ///< Stores all dungeons by groupType
        // Reward System
        LfgRewardMap m_RewardMap;                          ///< Stores rewards for random dungeons
        LFGDungeonMap  m_LfgDungeonMap;
        // Queue
        LfgQueueInfoMap m_QueueInfoMap;                    ///< Queued groups
        LfgGuidListMap m_currentQueue;                     ///< Ordered list. Used to find groups
        LfgGuidListMap m_newToQueue;                       ///< New groups to add to queue
        LfgCompatibleMap m_CompatibleMap;                  ///< Compatible dungeons
        LfgGuidList m_teleport;                            ///< Players being teleported
        // Rolecheck - Proposal - Vote Kicks
        LfgRoleCheckMap m_RoleChecks;                      ///< Current Role checks
        LfgProposalMap m_Proposals;                        ///< Current Proposals
        LfgPlayerBootMap m_Boots;                          ///< Current player kicks
        LfgPlayerDataMap m_Players;                        ///< Player data
        LfgGroupDataMap m_Groups;                          ///< Group data

        LFGPlayerScript *m_lfgPlayerScript;
        LFGGroupScript *m_lfgGroupScript;
};

#define sLFGMgr ACE_Singleton<LFGMgr, ACE_Null_Mutex>::instance()
#endif
