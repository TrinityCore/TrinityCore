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
#include "Policies/Singleton.h"
#include "Group.h"
#include "LFG.h"


enum LfgType
{
    LFG_TYPE_DUNGEON = 1,
    LFG_TYPE_RAID    = 2,
    LFG_TYPE_QUEST   = 3,
    LFG_TYPE_ZONE    = 4,
    LFG_TYPE_HEROIC  = 5,
    LFG_TYPE_RANDOM  = 6,
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

class LFGMgr
{
public:
    LFGMgr();
    ~LFGMgr();

    void InitLFG();
    void SendLfgPlayerInfo(Player *plr);
    void SendLfgPartyInfo(Player *plr);

private:
    void BuildAvailableRandomDungeonList(WorldPacket &data, Player *plr);
    void BuildRewardBlock(WorldPacket &data, uint32 dungeon, Player *plr);
    void BuildPlayerLockDungeonBlock(WorldPacket &data, LfgLockStatusSet *lockSet);
    void BuildPartyLockDungeonBlock(WorldPacket &data, LfgLockStatusMap *lockMap);
    LfgLockStatusMap* GetPartyLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons);
    LfgLockStatusSet* GetPlayerLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons);
    LfgDungeonSet* GetRandomDungeons(uint8 level, uint8 expansion);
    LfgDungeonSet* GetDungeonsByRandom(uint32 randomdungeon);
    LfgDungeonSet* GetAllDungeons();
    LfgReward* GetRandomDungeonReward(uint32 dungeon, bool done, uint8 level);

    LfgRewardList m_RewardList;
    LfgRewardList m_RewardDoneList;
    LfgDungeonMap m_DungeonsMap;
};

#define sLFGMgr Trinity::Singleton<LFGMgr>::Instance()
#endif
