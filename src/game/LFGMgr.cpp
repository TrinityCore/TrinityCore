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
#include "Policies/SingletonImp.h"
#include "Common.h"
#include "SharedDefines.h"
#include "Group.h"
#include "Player.h"
#include "LFGMgr.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"

INSTANTIATE_SINGLETON_1(LFGMgr);

LFGMgr::LFGMgr()
{
}

LFGMgr::~LFGMgr()
{
    for (LfgRewardList::iterator it = m_RewardList.begin(); it != m_RewardList.end(); ++it)
        delete *it;
    m_RewardList.clear();

    for (LfgRewardList::iterator it = m_RewardDoneList.begin(); it != m_RewardDoneList.end(); ++it)
        delete *it;
    m_RewardDoneList.clear();

    for (LfgDungeonMap::iterator it = m_DungeonsMap.begin(); it != m_DungeonsMap.end(); ++it)
    {
        it->second->clear();
        delete it->second;
    }
    m_DungeonsMap.clear();
}

/// <summary>
/// Initialize Looking For Group
/// </summary>
void LFGMgr::InitLFG()
{
    // Fill reward data
    LfgReward *reward;
    for (uint8 i = 0; i <= LFG_REWARD_DATA_SIZE; ++i)
    {
        reward = new LfgReward();
        reward->strangers = 0;
        reward->baseXP = RewardDungeonData[i][0];
        reward->baseMoney = RewardDungeonData[i][1];
        reward->variableMoney = 0;
        reward->variableXP = 0;
        reward->itemId = RewardDungeonData[i][2];
        reward->displayId = RewardDungeonData[i][3];
        reward->stackCount = RewardDungeonData[i][4];
        m_RewardList.push_back(reward);
    }

    for (uint8 i = 0; i < LFG_REWARD_DATA_SIZE; ++i)
    {
        reward = new LfgReward();
        reward->strangers = 0;
        reward->baseXP = RewardDungeonDoneData[i][0];
        reward->baseMoney = RewardDungeonDoneData[i][1];
        reward->variableMoney = 0;
        reward->variableXP = 0;
        reward->itemId = RewardDungeonDoneData[i][2];
        reward->displayId = RewardDungeonDoneData[i][3];
        reward->stackCount = RewardDungeonDoneData[i][4];
        m_RewardDoneList.push_back(reward);
    }
    // Initialize dungeonMap
    m_DungeonsMap[LFG_ALL_DUNGEONS] = GetAllDungeons();
    /* This will be used later.
    m_DungeonsMap[LFG_RANDOM_CLASSIC] = GetDungeonsByRandom(LFG_RANDOM_CLASSIC);
    m_DungeonsMap[LFG_RANDOM_BC_NORMAL] = GetDungeonsByRandom(LFG_RANDOM_BC_NORMAL);
    m_DungeonsMap[LFG_RANDOM_BC_HEROIC] = GetDungeonsByRandom(LFG_RANDOM_BC_HEROIC);
    m_DungeonsMap[LFG_RANDOM_LK_NORMAL] = GetDungeonsByRandom(LFG_RANDOM_LK_NORMAL);
    m_DungeonsMap[LFG_RANDOM_LK_HEROIC] = GetDungeonsByRandom(LFG_RANDOM_LK_HEROIC);
    */
}



// --------------------------------------------------------------------------//
// Packet Functions
// --------------------------------------------------------------------------//

/// <summary>
/// Build and Send LFG lock player info and reward
/// </summary>
/// <param name="plr">Player</param>
void LFGMgr::SendLfgPlayerInfo(Player *plr)
{
    uint32 rsize = 0;
    uint32 lsize = 0;
    LfgDungeonSet *randomlist = GetRandomDungeons(plr->getLevel(), plr->GetSession()->Expansion());
    LfgLockStatusSet *lockSet = GetPlayerLockStatusDungeons(plr, m_DungeonsMap[LFG_ALL_DUNGEONS]);
    if (randomlist)
        rsize = randomlist->size();
    if (lockSet)
        lsize = lockSet->size();

    sLog.outDebug("SMSG_LFG_PLAYER_INFO");
    WorldPacket data(SMSG_LFG_PLAYER_INFO, 1 + rsize * (4 + 1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4) + 4 + lsize * (4 + 4));
    if (!randomlist)
    {
        data << uint8(0);
    }
    else
    {
        data << uint8(randomlist->size());                  // Random Dungeon count
        for (LfgDungeonSet::iterator it = randomlist->begin(); it != randomlist->end(); ++it)
        {
            data << uint32(*it);                            // Entry
            BuildRewardBlock(data, *it, plr);
        }
        randomlist->clear();
        delete randomlist;
    }
    BuildPlayerLockDungeonBlock(data, lockSet);
    plr->GetSession()->SendPacket(&data);
}

/// <summary>
/// Build and Send LFG lock party info and reward
/// </summary>
/// <param name="plr">Player</param>
void LFGMgr::SendLfgPartyInfo(Player *plr)
{
    if (LfgLockStatusMap *lockMap = GetPartyLockStatusDungeons(plr, m_DungeonsMap[LFG_ALL_DUNGEONS]))
    {
        uint32 size = 0;
        for (LfgLockStatusMap::const_iterator it = lockMap->begin(); it != lockMap->end(); ++it)
            size += 8 + 4 + it->second->size() * (4 + 4);
        sLog.outDebug("SMSG_LFG_PARTY_INFO");
        WorldPacket data(SMSG_LFG_PARTY_INFO, 1 + size);
        BuildPartyLockDungeonBlock(data, lockMap);
        plr->GetSession()->SendPacket(&data);
    }
}

/// <summary>
/// Build Reward packet structure for a given dungeon
/// </summary>
/// <param name="data">WorldPacket</param>
/// <param name="dungeon">Dungeon entry</param>
/// <param name="plr">Player</param>
void LFGMgr::BuildRewardBlock(WorldPacket &data, uint32 dungeon, Player *plr)
{
    bool done = plr->m_lookingForGroup.isDungeonDone(dungeon);
    LfgReward *reward = GetRandomDungeonReward(dungeon, done, plr->getLevel());

    if (!reward)
        return;

    data << uint8(done);
    if (data.GetOpcode() == SMSG_LFG_PLAYER_REWARD)
        data << uint32(reward->strangers);
    data << uint32(reward->baseMoney);
    data << uint32(reward->baseXP);
    data << uint32(reward->variableMoney);
    data << uint32(reward->variableXP);
    data << uint8(reward->itemId != 0);
    if (reward->itemId)
    {
        data << uint32(reward->itemId);
        data << uint32(reward->displayId);
        data << uint32(reward->stackCount);
    }
}

/// <summary>
/// Build Party Dungeon lock status packet
/// </summary>
/// <param name="data">WorldPacket</param>
/// <param name="lock">lock status map</param>
void LFGMgr::BuildPartyLockDungeonBlock(WorldPacket &data, LfgLockStatusMap *lockMap)
{
    assert(lockMap);

    data << uint8(lockMap->size());

    LfgLockStatusSet *lockSet;
    uint64 guid;
    for (LfgLockStatusMap::const_iterator it = lockMap->begin(); it != lockMap->end(); ++it)
    {
        guid = it->first;
        lockSet = it->second;
        if (!lockSet)
            continue;

        data << uint64(guid);                               // Player guid
        BuildPlayerLockDungeonBlock(data, lockSet);
    }
    lockMap->clear();
    delete lockMap;
}

/// <summary>
/// Build Player Dungeon lock status packet
/// </summary>
/// <param name="data">WorldPacket</param>
/// <param name="lock">lock status list</param>
void LFGMgr::BuildPlayerLockDungeonBlock(WorldPacket &data, LfgLockStatusSet *lockSet)
{
    assert(lockSet);
    data << uint32(lockSet->size());                        // Size of lock dungeons
    for (LfgLockStatusSet::iterator it = lockSet->begin(); it != lockSet->end(); ++it)
    {
        data << uint32((*it)->dungeon);                     // Dungeon entry + type
        data << uint32((*it)->lockstatus);                  // Lock status
        delete (*it);
    }
    lockSet->clear();
    delete lockSet;
}




// --------------------------------------------------------------------------//
// Auxiliar Functions
// --------------------------------------------------------------------------//

/// <summary>
/// Get all Group members list of dungeons that can't be done and reason
/// leader excluded as the list given is he list he can do
/// </summary>
/// <param name="grp">Group</param>
/// <param name="dungeons">Dungeons to check</param>
/// <returns>LfgLockStatusMap*</returns>
LfgLockStatusMap* LFGMgr::GetPartyLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons)
{
    assert(plr);
    assert(dungeons);
    Group *grp = plr->GetGroup();
    if (!grp)
        return NULL;

    Player *plrg;
    LfgLockStatusMap *dungeonMap = new LfgLockStatusMap();
    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        plrg = itr->getSource();
        if (!plrg || plrg == plr)
            continue;
        (*dungeonMap)[plrg->GetGUID()] = GetPlayerLockStatusDungeons(plrg, dungeons);
    }
    return dungeonMap;
}

/// <summary>
/// Get list of dungeons player can't do and reasons
/// </summary>
/// <param name="plr">Player</param>
/// <param name="dungeons">Dungeons to check</param>
/// <returns>LfgLockStatusSet*</returns>
LfgLockStatusSet* LFGMgr::GetPlayerLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons)
{
    LfgLockStatusSet *list = new LfgLockStatusSet();
    LfgLockStatus *lockstatus = NULL;
    LFGDungeonEntry const *dungeon;
    LfgLockStatusType locktype;
    uint8 level = plr->getLevel();
    uint8 expansion = plr->GetSession()->Expansion();

    for (LfgDungeonSet::const_iterator it = dungeons->begin(); it != dungeons->end(); ++it)
    {
        dungeon = sLFGDungeonStore.LookupEntry(*it);
        assert(dungeon); // Will never happen - We provide a list from sLFGDungeonStore

        locktype = LFG_LOCKSTATUS_OK;
        if (dungeon->expansion > expansion)
            locktype = LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION;
        else if (dungeon->minlevel > level)
            locktype = LFG_LOCKSTATUS_TOO_LOW_LEVEL;
        else if (dungeon->maxlevel < level)
            locktype = LFG_LOCKSTATUS_TOO_HIGH_LEVEL;
        /* TODO - Use these types when needed...
        else if ()
            locktype = LFG_LOCKSTATUS_TOO_LOG_GEAR_SCORE;
        else if ()
            locktype = LFG_LOCKSTATUS_TOO_HIGH_GEAR_SCORE;
        else if () // Locked due to WG, closed by GM, done daily, etc
            locktype = LFG_LOCKSTATUS_RAID_LOCKED;
        else if ()
            locktype = LFG_LOCKSTATUS_ATTUNEMENT_TOO_LOW_LEVEL;
        else if ()
            locktype = LFG_LOCKSTATUS_ATTUNEMENT_TOO_HIGH_LEVEL;
        else if () // Need list of instances and needed quest to enter
            locktype = LFG_LOCKSTATUS_QUEST_NOT_COMPLETED;
        else if () // Need list of instances and needed key to enter
            locktype = LFG_LOCKSTATUS_MISSING_ITEM;
        else if () // Need list of instances and needed season to open
            locktype = LFG_LOCKSTATUS_NOT_IN_SEASON;
        */

        if (locktype != LFG_LOCKSTATUS_OK)
        {
            lockstatus = new LfgLockStatus();
            lockstatus->dungeon = dungeon->Entry();
            lockstatus->lockstatus = locktype;
            list->insert(lockstatus);
        }
    }
    return list;
}

/// <summary>
/// Get the dungeon list that can be done.
/// </summary>
/// <returns>LfgDungeonSet*</returns>
LfgDungeonSet* LFGMgr::GetAllDungeons()
{
    LfgDungeonSet *dungeons = new LfgDungeonSet();
    LFGDungeonEntry const *dungeon;
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        dungeon = sLFGDungeonStore.LookupEntry(i);
        if (!dungeon || dungeon->type == LFG_TYPE_ZONE)
            continue;
        dungeons->insert(dungeon->ID);
    }
    if (!dungeons->size())
    {
        delete dungeons;
        return NULL;
    }
    else
        return dungeons;
}

/// <summary>
/// Get the dungeon list that can be done given a random dungeon entry.
/// </summary>
/// <param name="randomdungeon">Random dungeon entry</param>
/// <returns>LfgDungeonSet*</returns>
LfgDungeonSet* LFGMgr::GetDungeonsByRandom(uint32 randomdungeon)
{
    LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(randomdungeon);
    if (!dungeon)
        return NULL;

    uint32 grouptype = dungeon->grouptype;
    LfgDungeonSet *random = new LfgDungeonSet();
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        dungeon = sLFGDungeonStore.LookupEntry(i);
        if (!dungeon || dungeon->type == LFG_TYPE_RANDOM || dungeon->grouptype != grouptype)
            continue;
        random->insert(dungeon->ID);
    }
    if (!random->size())
    {
        delete random;
        return NULL;
    }
    else
        return random;
}

/// <summary>
/// Get the random dungeon list that can be done at a certain level and expansion.
/// </summary>
/// <param name="level">Player level</param>
/// <param name="expansion">Player account expansion</param>
/// <returns>LfgDungeonSet*</returns>
LfgDungeonSet* LFGMgr::GetRandomDungeons(uint8 level, uint8 expansion)
{
    LfgDungeonSet *list = new LfgDungeonSet();
    LFGDungeonEntry const *dungeon;
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        dungeon = sLFGDungeonStore.LookupEntry(i);
        if (dungeon && dungeon->expansion <= expansion && dungeon->type == LFG_TYPE_RANDOM &&
            dungeon->minlevel <= level && level <= dungeon->maxlevel)
            list->insert(dungeon->Entry());
    }
    return list;
}

/// <summary>
/// Get the reward of a given random dungeon
/// </summary>
/// <param name="dungeon">random dungeon id</param>
/// <param name="done">Dungeon previously done</param>
/// <returns></returns>
LfgReward* LFGMgr::GetRandomDungeonReward(uint32 dungeon, bool done, uint8 level)
{
    uint8 index = 0;
    switch((dungeon & 0x00FFFFFF))                          // Get dungeon id from dungeon entry
    {
    case LFG_RANDOM_CLASSIC:
        if (level < 15)
            index = LFG_REWARD_LEVEL0;
        else if (level < 24)
            index = LFG_REWARD_LEVEL1;
        else if (level < 35)
            index = LFG_REWARD_LEVEL2;
        else if (level < 46)
            index = LFG_REWARD_LEVEL3;
        else if (level < 56)
            index = LFG_REWARD_LEVEL4;
        else
            index = LFG_REWARD_LEVEL5;
        break;
    case LFG_RANDOM_BC_NORMAL:
            index = LFG_REWARD_BC_NORMAL;
        break;
    case LFG_RANDOM_BC_HEROIC:
            index = LFG_REWARD_BC_HEROIC;
        break;
    case LFG_RANDOM_LK_NORMAL:
        index = level == 80 ? LFG_REWARD_LK_NORMAL80 : LFG_REWARD_LK_NORMAL;
        break;
    case LFG_RANDOM_LK_HEROIC:
        index = LFG_REWARD_LK_HEROIC;
        break;
    default:                                                // This should never happen!
        done = false;
        index = LFG_REWARD_LEVEL0;
        sLog.outError("LFGMgr::GetRandomDungeonReward: Dungeon %u is not random dungeon!", dungeon);
        break;
    }
    return done ? m_RewardDoneList.at(index) : m_RewardList.at(index);
}