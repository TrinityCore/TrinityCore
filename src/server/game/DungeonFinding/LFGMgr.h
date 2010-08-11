/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _LFGMGR_H
#define _LFGMGR_H

#include "Common.h"
#include "ace/Singleton.h"
#include "Group.h"
#include "LFG.h"

enum LFGenum
{
    LFG_TIME_ROLECHECK       = 2*MINUTE,
    LFG_TANKS_NEEDED         = 1,
    LFG_HEALERS_NEEDED       = 1,
    LFG_DPS_NEEDED           = 3,
    LFG_QUEUEUPDATE_INTERVAL = 15000,
    LFG_SPELL_COOLDOWN       = 71328,
    LFG_SPELL_DESERTER       = 71041,
};

enum LfgType
{
    LFG_TYPE_DUNGEON = 1,
    LFG_TYPE_RAID    = 2,
    LFG_TYPE_QUEST   = 3,
    LFG_TYPE_ZONE    = 4,
    LFG_TYPE_HEROIC  = 5,
    LFG_TYPE_RANDOM  = 6,
};

enum LfgGroupType
{
    LFG_GROUPTYPE_CLASSIC      = 1,
    LFG_GROUPTYPE_BC_NORMAL    = 2,
    LFG_GROUPTYPE_BC_HEROIC    = 3,
    LFG_GROUPTYPE_WTLK_NORMAL  = 4,
    LFG_GROUPTYPE_WTLK_HEROIC  = 5,
    LFG_GROUPTYPE_CLASSIC_RAID = 6,
    LFG_GROUPTYPE_BC_RAID      = 7,
    LFG_GROUPTYPE_WTLK_RAID_10 = 8,
    LFG_GROUPTYPE_WTLK_RAID_25 = 9,
};

enum LfgLockStatusType
{
    LFG_LOCKSTATUS_OK                        = 0,           // Internal use only
    LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION    = 1,
    LFG_LOCKSTATUS_TOO_LOW_LEVEL             = 2,
    LFG_LOCKSTATUS_TOO_HIGH_LEVEL            = 3,
    LFG_LOCKSTATUS_TOO_LOW_GEAR_SCORE        = 4,
    LFG_LOCKSTATUS_TOO_HIGH_GEAR_SCORE       = 5,
    LFG_LOCKSTATUS_RAID_LOCKED               = 6,
    LFG_LOCKSTATUS_ATTUNEMENT_TOO_LOW_LEVEL  = 1001,
    LFG_LOCKSTATUS_ATTUNEMENT_TOO_HIGH_LEVEL = 1002,
    LFG_LOCKSTATUS_QUEST_NOT_COMPLETED       = 1022,
    LFG_LOCKSTATUS_MISSING_ITEM              = 1025,
    LFG_LOCKSTATUS_NOT_IN_SEASON             = 1031,
};

enum LfgJoinResult
{
    LFG_JOIN_OK                    = 0,                     // Joined (no client msg)
    LFG_JOIN_FAILED                = 1,                     // RoleCheck Failed
    LFG_JOIN_GROUPFULL             = 2,                     // Your group is full
    LFG_JOIN_UNK3                  = 3,                     // No client reaction
    LFG_JOIN_INTERNAL_ERROR        = 4,                     // Internal LFG Error
    LFG_JOIN_NOT_MEET_REQS         = 5,                     // You do not meet the requirements for the chosen dungeons
    LFG_JOIN_PARTY_NOT_MEET_REQS   = 6,                     // One or more party members do not meet the requirements for the chosen dungeons
    LFG_JOIN_MIXED_RAID_DUNGEON    = 7,                     // You cannot mix dungeons, raids, and random when picking dungeons
    LFG_JOIN_MULTI_REALM           = 8,                     // The dungeon you chose does not support players from multiple realms
    LFG_JOIN_DISCONNECTED          = 9,                     // One or more party members are pending invites or disconnected
    LFG_JOIN_PARTY_INFO_FAILED     = 10,                    // Could not retrieve information about some party members
    LFG_JOIN_DUNGEON_INVALID       = 11,                    // One or more dungeons was not valid
    LFG_JOIN_DESERTER              = 12,                    // You can not queue for dungeons until your deserter debuff wears off
    LFG_JOIN_PARTY_DESERTER        = 13,                    // One or more party members has a deserter debuff
    LFG_JOIN_RANDOM_COOLDOWN       = 14,                    // You can not queue for random dungeons while on random dungeon cooldown
    LFG_JOIN_PARTY_RANDOM_COOLDOWN = 15,                    // One or more party members are on random dungeon cooldown
    LFG_JOIN_TOO_MUCH_MEMBERS      = 16,                    // You can not enter dungeons with more that 5 party members
    LFG_JOIN_USING_BG_SYSTEM       = 17,                    // You can not use the dungeon system while in BG or arenas
    LFG_JOIN_FAILED2               = 18,                    // RoleCheck Failed
};

enum LfgRoleCheckResult
{
    LFG_ROLECHECK_FINISHED     = 1,                         // Role check finished
    LFG_ROLECHECK_INITIALITING = 2,                         // Role check begins
    LFG_ROLECHECK_MISSING_ROLE = 3,                         // Someone didn't selected a role after 2 mins
    LFG_ROLECHECK_WRONG_ROLES  = 4,                         // Can't form a group with that role selection
    LFG_ROLECHECK_ABORTED      = 5,                         // Someone leave the group
    LFG_ROLECHECK_NO_ROLE      = 6,                         // Someone selected no role
};

enum LfgRandomDungeonEntries
{
    LFG_ALL_DUNGEONS       = 0,
    LFG_RANDOM_CLASSIC     = 258,
    LFG_RANDOM_BC_NORMAL   = 259,
    LFG_RANDOM_BC_HEROIC   = 260,
    LFG_RANDOM_LK_NORMAL   = 261,
    LFG_RANDOM_LK_HEROIC   = 262,
};

enum LfgRewardEnums
{
    LFG_REWARD_LEVEL0      = 10,
    LFG_REWARD_LEVEL1      = 0,
    LFG_REWARD_LEVEL2      = 1,
    LFG_REWARD_LEVEL3      = 2,
    LFG_REWARD_LEVEL4      = 3,
    LFG_REWARD_LEVEL5      = 4,
    LFG_REWARD_BC_NORMAL   = 5,
    LFG_REWARD_BC_HEROIC   = 6,
    LFG_REWARD_LK_NORMAL   = 7,
    LFG_REWARD_LK_NORMAL80 = 7,
    LFG_REWARD_LK_HEROIC   = 8,
    LFG_REWARD_DATA_SIZE   = 10,
};

const uint32 RewardDungeonData[LFG_REWARD_DATA_SIZE+1][5] =
{ // XP, money, item, item display, count
    {310, 3500, 51999, 56915, 1},                           // Classic 15-23
    {470, 7000, 52000, 56915, 1},                           // Classic 24-34
    {825, 13000, 52001, 56915, 1},                          // Classic 35-45
    {12250, 16500, 52002, 56915, 1},                        // Classic 46-55
    {14300, 18000, 52003, 56915, 1},                        // Classic 56-60
    {1600, 62000, 52004, 56915, 1},                         // BC Normal
    {1900, 88000, 52005, 56915, 1},                         // BC Heroic
    {33100, 148000, 47241, 62232, 2},                       // LK Normal
    {0, 198600, 47241, 62232, 2},                           // LK Normal - Level 80
    {0, 264600, 49426, 64062, 2},                           // LK Heroic
    {0, 0, 0, 0, 0},                                        // Classic - No level
};

const uint32 RewardDungeonDoneData[LFG_REWARD_DATA_SIZE][5] =
{ // XP, money, item, item display, count
    {200, 1800, 51999, 56915, 1},                           // Classic 15-23
    {310, 3500, 52000, 56915, 1},                           // Classic 24-34
    {550, 6500, 52001, 56915, 1},                           // Classic 35-45
    {8150, 8500, 52002, 56915, 1},                          // Classic 46-55
    {9550, 9000, 52003, 56915, 1},                          // Classic 56-60
    {1100, 31000, 52004, 56915, 1},                         // BC Normal
    {12650, 44000, 52005, 56915, 1},                        // BC Heroic
    {16550, 74000, 0, 0, 0},                                // LK Normal
    {0, 99300, 0, 0, 0},                                    // LK Normal - Level 80
    {0, 132300, 47241, 62232, 2},                           // LK Heroic
};

// Dungeon and reason why player can't join
struct LfgLockStatus
{
    uint32 dungeon;
    LfgLockStatusType lockstatus;
};

// Reward info
struct LfgReward
{
    uint32 strangers;
    uint32 baseMoney;
    uint32 baseXP;
    uint32 variableMoney;
    uint32 variableXP;
    uint32 itemId;
    uint32 displayId;
    uint32 stackCount;
};

typedef std::set<LfgLockStatus*> LfgLockStatusSet;
typedef std::vector<LfgReward*> LfgRewardList;
typedef std::map<uint64, LfgLockStatusSet*> LfgLockStatusMap;
typedef std::map<uint32, LfgDungeonSet*> LfgDungeonMap;

typedef std::map<uint64, int8> LfgAnswerMap;
typedef std::list<uint64> LfgGuidList;
typedef std::map<uint64, uint8> LfgRolesMap;
typedef std::set<uint64> LfgGuidSet;

// Stores player or group queue info
struct LfgQueueInfo
{
    LfgQueueInfo(): tanks(LFG_TANKS_NEEDED), healers(LFG_HEALERS_NEEDED), dps(LFG_DPS_NEEDED) {};
    time_t joinTime;                                        // Player queue join time (to calculate wait times)
    uint8 tanks;                                            // Tanks needed
    uint8 healers;                                          // Healers needed
    uint8 dps;                                              // Dps needed
    LfgDungeonSet dungeons;                                 // Selected Player/Group Dungeon/s
    LfgRolesMap roles;                                      // Selected Player Role/s
};

// Stores all rolecheck info of a group that wants to join LFG
struct LfgRoleCheck
{
    time_t cancelTime;
    LfgRolesMap roles;
    LfgRoleCheckResult result;
    LfgDungeonSet dungeons;
    uint64 leader;
};

typedef std::map<uint64, LfgQueueInfo*> LfgQueueInfoMap;
typedef std::map<uint32, LfgRoleCheck*> LfgRoleCheckMap;

class LFGMgr
{
    friend class ACE_Singleton<LFGMgr, ACE_Null_Mutex>;
    LFGMgr();
    public:
       ~LFGMgr();

        void InitLFG();
        void SendLfgPlayerInfo(Player *plr);
        void SendLfgPartyInfo(Player *plr);
        void Join(Player *plr);
        void Leave(Player *plr, Group *grp = NULL);
        void UpdateRoleCheck(Group *grp, Player *plr = NULL);
        void Update(uint32 diff);

    private:
        void BuildLfgRoleCheck(WorldPacket &data, LfgRoleCheck *pRoleCheck);
        void BuildAvailableRandomDungeonList(WorldPacket &data, Player *plr);
        void BuildRewardBlock(WorldPacket &data, uint32 dungeon, Player *plr);
        void BuildPlayerLockDungeonBlock(WorldPacket &data, LfgLockStatusSet *lockSet);
        void BuildPartyLockDungeonBlock(WorldPacket &data, LfgLockStatusMap *lockMap);
        bool CheckGroupRoles(LfgRolesMap &groles, bool removeLeaderFlag = true);

        void AddToQueue(uint64 guid, LfgRolesMap *roles, LfgDungeonSet *dungeons);
        bool RemoveFromQueue(uint64 guid);
        bool isRandomDungeon(uint32 dungeonId);

        LfgLockStatusMap* GetPartyLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons);
        LfgLockStatusSet* GetPlayerLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons);
        LfgDungeonSet* GetRandomDungeons(uint8 level, uint8 expansion);
        LfgDungeonSet* GetDungeonsByRandom(uint32 randomdungeon);
        LfgDungeonSet* GetAllDungeons();
        LfgReward* GetRandomDungeonReward(uint32 dungeon, bool done, uint8 level);
        uint8 GetDungeonGroupType(uint32 dungeon);

        LfgRewardList m_RewardList;
        LfgRewardList m_RewardDoneList;
        LfgDungeonMap m_DungeonsMap;
        LfgQueueInfoMap m_QueueInfoMap;                     // Queued groups
        LfgGuidList m_currentQueue;                         // Ordered list. Used to find groups
        LfgGuidList m_newToQueue;                           // New groups to add to queue;

        LfgRoleCheckMap m_RoleChecks;                       // Current Role checks
        uint32 m_QueueTimer;                                // used to check interval of update
        int32 m_avgWaitTime;
        int32 m_waitTimeTanks;
        int32 m_waitTimeHealer;
        int32 m_waitTimeDps;
        bool m_update;
};

#define sLFGMgr (*ACE_Singleton<LFGMgr, ACE_Null_Mutex>::instance())
#endif
