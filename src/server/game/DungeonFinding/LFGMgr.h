/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "DatabaseEnvFwd.h"
#include "LFG.h"
#include "LFGQueue.h"
#include "LFGGroupData.h"
#include "LFGPlayerData.h"
#include <unordered_map>

class Group;
class Player;
class Quest;
struct LFGDungeonsEntry;
enum Difficulty : uint8;

namespace WorldPackets
{
    namespace LFG
    {
        struct RideTicket;
    }
}

namespace lfg
{

enum LfgOptions
{
    LFG_OPTION_ENABLE_DUNGEON_FINDER             = 0x01,
    LFG_OPTION_ENABLE_RAID_BROWSER               = 0x02,
};

enum LFGMgrEnum
{
    LFG_TIME_ROLECHECK                           = 45,
    LFG_TIME_BOOT                                = 120,
    LFG_TIME_PROPOSAL                            = 45,
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
enum LfgTeleportResult : uint8
{
    // 7 = "You can't do that right now" | 5 = No client reaction
    LFG_TELEPORT_RESULT_NONE                = 0,      // Internal use
    LFG_TELEPORT_RESULT_DEAD                = 1,
    LFG_TELEPORT_RESULT_FALLING             = 2,
    LFG_TELEPORT_RESULT_ON_TRANSPORT        = 3,
    LFG_TELEPORT_RESULT_EXHAUSTION          = 4,
    LFG_TELEPORT_RESULT_NO_RETURN_LOCATION  = 6,
    LFG_TELEPORT_RESULT_IMMUNE_TO_SUMMONS   = 8      // FIXME - It can be 7 or 8 (Need proper data)

    // unknown values
    //LFG_TELEPORT_RESULT_NOT_IN_DUNGEON,
    //LFG_TELEPORT_RESULT_NOT_ALLOWED,
    //LFG_TELEPORT_RESULT_ALREADY_IN_DUNGEON
};

/// Queue join results
enum LfgJoinResult
{
    // 3 = No client reaction | 18 = "Rolecheck failed"
    LFG_JOIN_OK                                     = 0x00, // Joined (no client msg)
    LFG_JOIN_GROUP_FULL                             = 0x1F, // Your group is already full.
    LFG_JOIN_NO_LFG_OBJECT                          = 0x21, // Internal LFG Error.
    LFG_JOIN_NO_SLOTS_PLAYER                        = 0x22, // You do not meet the requirements for the chosen dungeons.
    LFG_JOIN_MISMATCHED_SLOTS                       = 0x23, // You cannot mix dungeons, raids, and random when picking dungeons.
    LFG_JOIN_PARTY_PLAYERS_FROM_DIFFERENT_REALMS    = 0x24, // The dungeon you chose does not support players from multiple realms.
    LFG_JOIN_MEMBERS_NOT_PRESENT                    = 0x25, // One or more group members are pending invites or disconnected.
    LFG_JOIN_GET_INFO_TIMEOUT                       = 0x26, // Could not retrieve information about some party members.
    LFG_JOIN_INVALID_SLOT                           = 0x27, // One or more dungeons was not valid.
    LFG_JOIN_DESERTER_PLAYER                        = 0x28, // You can not queue for dungeons until your deserter debuff wears off.
    LFG_JOIN_DESERTER_PARTY                         = 0x29, // One or more party members has a deserter debuff.
    LFG_JOIN_RANDOM_COOLDOWN_PLAYER                 = 0x2A, // You can not queue for random dungeons while on random dungeon cooldown.
    LFG_JOIN_RANDOM_COOLDOWN_PARTY                  = 0x2B, // One or more party members are on random dungeon cooldown.
    LFG_JOIN_TOO_MANY_MEMBERS                       = 0x2C, // You have too many group members to queue for that.
    LFG_JOIN_CANT_USE_DUNGEONS                      = 0x2D, // You cannot queue for a dungeon or raid while using battlegrounds or arenas.
    LFG_JOIN_ROLE_CHECK_FAILED                      = 0x2E, // The Role Check has failed.
    LFG_JOIN_TOO_FEW_MEMBERS                        = 0x34, // You do not have enough group members to queue for that.
    LFG_JOIN_REASON_TOO_MANY_LFG                    = 0x35, // You are queued for too many instances.
    LFG_JOIN_MISMATCHED_SLOTS_LOCAL_XREALM          = 0x37, // You cannot mix realm-only and x-realm entries when listing your name in other raids.
    LFG_JOIN_ALREADY_USING_LFG_LIST                 = 0x3F, // You can't do that while using Premade Groups.
    LFG_JOIN_NOT_LEADER                             = 0x45, // You are not the party leader.
    LFG_JOIN_DEAD                                   = 0x49,

    LFG_JOIN_PARTY_NOT_MEET_REQS                    = 6,      // One or more party members do not meet the requirements for the chosen dungeons (FIXME)
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
struct LFGDungeonData;
struct LfgReward;
struct LfgQueueInfo;
struct LfgRoleCheck;
struct LfgProposal;
struct LfgProposalPlayer;
struct LfgPlayerBoot;

typedef std::map<uint8, LFGQueue> LfgQueueContainer;
typedef std::multimap<uint32, LfgReward const*> LfgRewardContainer;
typedef std::pair<LfgRewardContainer::const_iterator, LfgRewardContainer::const_iterator> LfgRewardContainerBounds;
typedef std::map<uint8, LfgDungeonSet> LfgCachedDungeonContainer;
typedef std::map<ObjectGuid, LfgAnswer> LfgAnswerContainer;
typedef std::map<ObjectGuid, LfgRoleCheck> LfgRoleCheckContainer;
typedef std::map<uint32, LfgProposal> LfgProposalContainer;
typedef std::map<ObjectGuid, LfgProposalPlayer> LfgProposalPlayerContainer;
typedef std::map<ObjectGuid, LfgPlayerBoot> LfgPlayerBootContainer;
typedef std::map<ObjectGuid, LfgGroupData> LfgGroupDataContainer;
typedef std::map<ObjectGuid, LfgPlayerData> LfgPlayerDataContainer;
typedef std::unordered_map<uint32, LFGDungeonData> LFGDungeonContainer;

// Data needed by SMSG_LFG_JOIN_RESULT
struct LfgJoinResultData
{
    LfgJoinResultData(LfgJoinResult _result = LFG_JOIN_OK, LfgRoleCheckState _state = LFG_ROLECHECK_DEFAULT):
        result(_result), state(_state) { }
    LfgJoinResult result;
    LfgRoleCheckState state;
    LfgLockPartyMap lockmap;
};

// Data needed by SMSG_LFG_UPDATE_STATUS
struct LfgUpdateData
{
    LfgUpdateData(LfgUpdateType _type = LFG_UPDATETYPE_DEFAULT): updateType(_type), state(LFG_STATE_NONE) { }
    LfgUpdateData(LfgUpdateType _type, LfgDungeonSet const& _dungeons):
        updateType(_type), state(LFG_STATE_NONE), dungeons(_dungeons) { }
    LfgUpdateData(LfgUpdateType _type, LfgState _state, LfgDungeonSet const& _dungeons):
        updateType(_type), state(_state), dungeons(_dungeons) { }

    LfgUpdateType updateType;
    LfgState state;
    LfgDungeonSet dungeons;
    std::string comment;
};

// Data needed by SMSG_LFG_QUEUE_STATUS
struct LfgQueueStatusData
{
    LfgQueueStatusData(uint8 _queueId = 0, uint32 _dungeonId = 0, int32 _waitTime = -1, int32 _waitTimeAvg = -1, int32 _waitTimeTank = -1, int32 _waitTimeHealer = -1,
        int32 _waitTimeDps = -1, uint32 _queuedTime = 0, uint8 _tanks = 0, uint8 _healers = 0, uint8 _dps = 0) :
        queueId(_queueId), dungeonId(_dungeonId), waitTime(_waitTime), waitTimeAvg(_waitTimeAvg), waitTimeTank(_waitTimeTank),
        waitTimeHealer(_waitTimeHealer), waitTimeDps(_waitTimeDps), queuedTime(_queuedTime), tanks(_tanks), healers(_healers), dps(_dps) { }

    uint8 queueId;
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

struct LfgPlayerRewardData
{
    LfgPlayerRewardData(uint32 random, uint32 current, bool _done, Quest const* _quest):
        rdungeonEntry(random), sdungeonEntry(current), done(_done), quest(_quest) { }
    uint32 rdungeonEntry;
    uint32 sdungeonEntry;
    bool done;
    Quest const* quest;
};

/// Reward info
struct LfgReward
{
    LfgReward(uint32 _maxLevel = 0, uint32 _firstQuest = 0, uint32 _otherQuest = 0):
        maxLevel(_maxLevel), firstQuest(_firstQuest), otherQuest(_otherQuest) { }

    uint32 maxLevel;
    uint32 firstQuest;
    uint32 otherQuest;
};

/// Stores player data related to proposal to join
struct LfgProposalPlayer
{
    LfgProposalPlayer(): role(0), accept(LFG_ANSWER_PENDING), group() { }
    uint8 role;                                            ///< Proposed role
    LfgAnswer accept;                                      ///< Accept status (-1 not answer | 0 Not agree | 1 agree)
    ObjectGuid group;                                      ///< Original group guid. 0 if no original group
};

/// Stores group data related to proposal to join
struct LfgProposal
{
    LfgProposal(uint32 dungeon = 0): id(0), dungeonId(dungeon), state(LFG_PROPOSAL_INITIATING),
        group(), leader(), cancelTime(0), encounters(0), isNew(true)
        { }

    uint32 id;                                             ///< Proposal Id
    uint32 dungeonId;                                      ///< Dungeon to join
    LfgProposalState state;                                ///< State of the proposal
    ObjectGuid group;                                      ///< Proposal group (0 if new)
    ObjectGuid leader;                                     ///< Leader guid.
    time_t cancelTime;                                     ///< Time when we will cancel this proposal
    uint32 encounters;                                     ///< Dungeon Encounters
    bool isNew;                                            ///< Determines if it's new group or not
    GuidList queues;                                       ///< Queue Ids to remove/readd
    GuidList showorder;                                    ///< Show order in update window
    LfgProposalPlayerContainer players;                    ///< Players data
};

/// Stores all rolecheck info of a group that wants to join
struct LfgRoleCheck
{
    time_t cancelTime;                                     ///< Time when the rolecheck will fail
    LfgRolesMap roles;                                     ///< Player selected roles
    LfgRoleCheckState state;                               ///< State of the rolecheck
    LfgDungeonSet dungeons;                                ///< Dungeons group is applying for (expanded random dungeons)
    uint32 rDungeonId;                                     ///< Random Dungeon Id.
    ObjectGuid leader;                                     ///< Leader of the group
};

/// Stores information of a current vote to kick someone from a group
struct LfgPlayerBoot
{
    time_t cancelTime;                                     ///< Time left to vote
    bool inProgress;                                       ///< Vote in progress
    LfgAnswerContainer votes;                              ///< Player votes (-1 not answer | 0 Not agree | 1 agree)
    ObjectGuid victim;                                     ///< Player guid to be kicked (can't vote)
    std::string reason;                                    ///< kick reason
};

struct LFGDungeonData
{
    LFGDungeonData();
    LFGDungeonData(LFGDungeonsEntry const* dbc);

    uint32 id;
    std::string name;
    uint32 map;
    uint8 type;
    uint8 expansion;
    uint8 group;
    uint8 minlevel;
    uint8 maxlevel;
    Difficulty difficulty;
    bool seasonal;
    float x, y, z, o;
    uint16 requiredItemLevel;

    // Helpers
    uint32 Entry() const { return id + (type << 24); }
};

class TC_GAME_API LFGMgr
{
    private:
        LFGMgr();
        ~LFGMgr();

    public:
        static LFGMgr* instance();

        // Functions used outside lfg namespace
        void Update(uint32 diff);

        // World.cpp
        /// Finish the dungeon for the given group. All check are performed using internal lfg data
        void FinishDungeon(ObjectGuid gguid, uint32 dungeonId);
        /// Loads rewards for random dungeons
        void LoadRewards();
        /// Loads dungeons from dbc and adds teleport coords
        void LoadLFGDungeons(bool reload = false);

        // Multiple files
        /// Check if given guid applied for random dungeon
        bool selectedRandomLfgDungeon(ObjectGuid guid);
        /// Check if given guid applied for given map and difficulty. Used to know
        bool inLfgDungeonMap(ObjectGuid guid, uint32 map, Difficulty difficulty);
        /// Get selected dungeons
        LfgDungeonSet const& GetSelectedDungeons(ObjectGuid guid);
        /// Get current lfg state
        LfgState GetState(ObjectGuid guid);
        /// Get current vote kick state
        bool IsVoteKickActive(ObjectGuid gguid);
        /// Get current dungeon
        uint32 GetDungeon(ObjectGuid guid, bool asId = true);
        /// Get the map id of the current dungeon
        uint32 GetDungeonMapId(ObjectGuid guid);
        /// Get kicks left in current group
        uint8 GetKicksLeft(ObjectGuid gguid);
        /// Load Lfg group info from DB
        void _LoadFromDB(Field* fields, ObjectGuid guid);
        /// Initializes player data after loading group data from DB
        void SetupGroupMember(ObjectGuid guid, ObjectGuid gguid);
        /// Return Lfg dungeon entry for given dungeon id
        uint32 GetLFGDungeonEntry(uint32 id);

        // cs_lfg
        /// Get current player roles
        uint8 GetRoles(ObjectGuid guid);
        /// Gets current lfg options
        uint32 GetOptions();
        /// Sets new lfg options
        void SetOptions(uint32 options);
        /// Checks if given lfg option is enabled
        bool isOptionEnabled(uint32 option);
        /// Clears queue - Only for internal testing
        void Clean();
        /// Dumps the state of the queue - Only for internal testing
        std::string DumpQueueInfo(bool full = false);

        // LFGScripts
        /// Get leader of the group (using internal data)
        ObjectGuid GetLeader(ObjectGuid guid);
        /// Sets player team
        void SetTeam(ObjectGuid guid, uint8 team);
        /// Sets player group
        void SetGroup(ObjectGuid guid, ObjectGuid group);
        /// Gets player group
        ObjectGuid GetGroup(ObjectGuid guid);
        /// Sets the leader of the group
        void SetLeader(ObjectGuid gguid, ObjectGuid leader);
        /// Removes saved group data
        void RemoveGroupData(ObjectGuid guid);
        /// Removes a player from a group
        uint8 RemovePlayerFromGroup(ObjectGuid gguid, ObjectGuid guid);
        /// Adds player to group
        void AddPlayerToGroup(ObjectGuid gguid, ObjectGuid guid);

        // LFGHandler
        /// Get locked dungeons
        LfgLockMap const GetLockedDungeons(ObjectGuid guid);
        /// Returns current lfg status
        LfgUpdateData GetLfgStatus(ObjectGuid guid);
        /// Checks if Seasonal dungeon is active
        bool IsSeasonActive(uint32 dungeonId);
        /// Gets the random dungeon reward corresponding to given dungeon and player level
        LfgReward const* GetRandomDungeonReward(uint32 dungeon, uint8 level);
        /// Returns all random and seasonal dungeons for given level and expansion
        LfgDungeonSet GetRandomAndSeasonalDungeons(uint8 level, uint8 expansion);
        /// Teleport a player to/from selected dungeon
        void TeleportPlayer(Player* player, bool out, bool fromOpcode = false);
        /// Inits new proposal to boot a player
        void InitBoot(ObjectGuid gguid, ObjectGuid kguid, ObjectGuid vguid, std::string const& reason);
        /// Updates player boot proposal with new player answer
        void UpdateBoot(ObjectGuid guid, bool accept);
        /// Updates proposal to join dungeon with player answer
        void UpdateProposal(uint32 proposalId, ObjectGuid guid, bool accept);
        /// Updates the role check with player answer
        void UpdateRoleCheck(ObjectGuid gguid, ObjectGuid guid = ObjectGuid::Empty, uint8 roles = PLAYER_ROLE_NONE);
        /// Sets player lfg roles
        void SetRoles(ObjectGuid guid, uint8 roles);
        /// Join Lfg with selected roles, dungeons and comment
        void JoinLfg(Player* player, uint8 roles, LfgDungeonSet& dungeons);
        /// Leaves lfg
        void LeaveLfg(ObjectGuid guid, bool disconnected = false);
        /// Gets unique join queue data
        WorldPackets::LFG::RideTicket const* GetTicket(ObjectGuid guid) const;

        // LfgQueue
        /// Get last lfg state (NONE, DUNGEON or FINISHED_DUNGEON)
        LfgState GetOldState(ObjectGuid guid);
        /// Check if given group guid is lfg
        bool IsLfgGroup(ObjectGuid guid);
        /// Gets the player count of given group
        uint8 GetPlayerCount(ObjectGuid guid);
        /// Add a new Proposal
        uint32 AddProposal(LfgProposal& proposal);
        /// Returns queue id
        uint8 GetQueueId(ObjectGuid guid);
        /// Checks if all players are queued
        bool AllQueued(GuidList const& check);
        /// Gets queue join time
        time_t GetQueueJoinTime(ObjectGuid guid);
        /// Checks if given roles match, modifies given roles map with new roles
        static bool CheckGroupRoles(LfgRolesMap &groles);
        /// Checks if given players are ignoring each other
        static bool HasIgnore(ObjectGuid guid1, ObjectGuid guid2);
        /// Sends queue status to player
        static void SendLfgQueueStatus(ObjectGuid guid, LfgQueueStatusData const& data);

    private:
        uint8 GetTeam(ObjectGuid guid);
        void RestoreState(ObjectGuid guid, char const* debugMsg);
        void ClearState(ObjectGuid guid, char const* debugMsg);
        void SetDungeon(ObjectGuid guid, uint32 dungeon);
        void SetSelectedDungeons(ObjectGuid guid, LfgDungeonSet const& dungeons);
        void DecreaseKicksLeft(ObjectGuid guid);
        void SetTicket(ObjectGuid guid, WorldPackets::LFG::RideTicket const& ticket);
        void SetState(ObjectGuid guid, LfgState state);
        void SetVoteKick(ObjectGuid gguid, bool active);
        void RemovePlayerData(ObjectGuid guid);
        void GetCompatibleDungeons(LfgDungeonSet& dungeons, GuidSet const& players, LfgLockPartyMap& lockMap, bool isContinue);
        void _SaveToDB(ObjectGuid guid, uint32 db_guid);
        LFGDungeonData const* GetLFGDungeon(uint32 id);

        // Proposals
        void RemoveProposal(LfgProposalContainer::iterator itProposal, LfgUpdateType type);
        void MakeNewGroup(LfgProposal const& proposal);

        // Generic
        LFGQueue& GetQueue(ObjectGuid guid);

        LfgDungeonSet const& GetDungeonsByRandom(uint32 randomdungeon);
        LfgType GetDungeonType(uint32 dungeon);

        void SendLfgBootProposalUpdate(ObjectGuid guid, LfgPlayerBoot const& boot);
        void SendLfgJoinResult(ObjectGuid guid, LfgJoinResultData const& data);
        void SendLfgRoleChosen(ObjectGuid guid, ObjectGuid pguid, uint8 roles);
        void SendLfgRoleCheckUpdate(ObjectGuid guid, LfgRoleCheck const& roleCheck);
        void SendLfgUpdateStatus(ObjectGuid guid, LfgUpdateData const& data, bool party);
        void SendLfgUpdateProposal(ObjectGuid guid, LfgProposal const& proposal);

        GuidSet const& GetPlayers(ObjectGuid guid);

        // General variables
        uint32 m_QueueTimer;                               ///< used to check interval of update
        uint32 m_lfgProposalId;                            ///< used as internal counter for proposals
        uint32 m_options;                                  ///< Stores config options

        LfgQueueContainer QueuesStore;                     ///< Queues
        LfgCachedDungeonContainer CachedDungeonMapStore;   ///< Stores all dungeons by groupType
        // Reward System
        LfgRewardContainer RewardMapStore;                 ///< Stores rewards for random dungeons
        LFGDungeonContainer  LfgDungeonStore;
        // Rolecheck - Proposal - Vote Kicks
        LfgRoleCheckContainer RoleChecksStore;             ///< Current Role checks
        LfgProposalContainer ProposalsStore;               ///< Current Proposals
        LfgPlayerBootContainer BootsStore;                 ///< Current player kicks
        LfgPlayerDataContainer PlayersStore;               ///< Player data
        LfgGroupDataContainer GroupsStore;                 ///< Group data
};

} // namespace lfg

#define sLFGMgr lfg::LFGMgr::instance()
#endif
