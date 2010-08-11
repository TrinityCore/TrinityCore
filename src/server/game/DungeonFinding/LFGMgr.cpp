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

#include "Common.h"
#include "SharedDefines.h"
#include "Group.h"
#include "Player.h"
#include "SocialMgr.h"
#include "LFGMgr.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"

LFGMgr::LFGMgr()
{
    m_QueueTimer = 0;
    m_avgWaitTime = -1;
    m_waitTimeTanks = -1;
    m_waitTimeHealer = -1;
    m_waitTimeDps = -1;
    m_update = true;
}

LFGMgr::~LFGMgr()
{
    // FIXME: RewardList to be removed -> query quest system
    for (LfgRewardList::iterator it = m_RewardList.begin(); it != m_RewardList.end(); ++it)
        delete *it;
    m_RewardList.clear();

    // FIXME: RewardDoneList to be removed -> query quest system
    for (LfgRewardList::iterator it = m_RewardDoneList.begin(); it != m_RewardDoneList.end(); ++it)
        delete *it;
    m_RewardDoneList.clear();

    for (LfgQueueInfoMap::iterator it = m_QueueInfoMap.begin(); it != m_QueueInfoMap.end(); ++it)
        delete it->second;
    m_QueueInfoMap.clear();

    for (LfgRoleCheckMap::iterator it = m_RoleChecks.begin(); it != m_RoleChecks.end(); ++it)
        delete it->second;
    m_RoleChecks.clear();

    for (LfgDungeonMap::iterator it = m_CachedDungeonMap.begin(); it != m_CachedDungeonMap.end(); ++it)
        delete it->second;
    m_CachedDungeonMap.clear();
    m_QueueInfoMap.clear();
    m_currentQueue.clear();
    m_newToQueue.clear();
}

void LFGMgr::Update(uint32 diff)
{
    if (!m_update)
        return;

    m_update = false;
    time_t currTime = time(NULL);

    // Remove obsolete role checks
    LfgRoleCheckMap::iterator itRoleCheck;
    LfgRoleCheck *pRoleCheck;
    for (LfgRoleCheckMap::iterator it = m_RoleChecks.begin(); it != m_RoleChecks.end();)
    {
        itRoleCheck = it++;
        pRoleCheck = itRoleCheck->second;
        if (currTime < pRoleCheck->cancelTime)
            continue;
        pRoleCheck->result = LFG_ROLECHECK_MISSING_ROLE;

        WorldPacket data(SMSG_LFG_ROLE_CHECK_UPDATE, 4 + 1 + 1 + pRoleCheck->dungeons.size() * 4 + 1 + pRoleCheck->roles.size() * (8 + 1 + 4 + 1));
        sLog.outDebug("SMSG_LFG_ROLE_CHECK_UPDATE");
        BuildLfgRoleCheck(data, pRoleCheck);
        Player *plr = NULL;
        for (LfgRolesMap::const_iterator itRoles = pRoleCheck->roles.begin(); itRoles != pRoleCheck->roles.end(); ++itRoles)
        {
            plr = sObjectMgr.GetPlayer(itRoles->first);
            if (!plr)
                continue;
            plr->GetSession()->SendPacket(&data);
            plr->GetLfgDungeons()->clear();
            plr->SetLfgRoles(ROLE_NONE);

            if (itRoles->first == pRoleCheck->leader)
                plr->GetSession()->SendLfgJoinResult(LFG_JOIN_FAILED, pRoleCheck->result);
        }
        delete pRoleCheck;
        m_RoleChecks.erase(itRoleCheck);
    }

    // Update all players status queue info
    if (m_QueueTimer > LFG_QUEUEUPDATE_INTERVAL)
    {
        m_QueueTimer = 0;
        time_t currTime = time(NULL);
        int32 waitTime;
        LfgQueueInfo *queue;
        uint32 dungeonId;
        uint32 queuedTime;
        uint8 role;
        for (LfgQueueInfoMap::const_iterator itQueue = m_QueueInfoMap.begin(); itQueue != m_QueueInfoMap.end(); ++itQueue)
        {
            queue = itQueue->second;
            if (!queue)
            {
                if (IS_GROUP(itQueue->first))
                    sLog.outError("LFGMgr::Update: group (lowguid: %u) queued with null queue info!", GUID_LOPART(itQueue->first));
                else
                    sLog.outError("LFGMgr::Update: player (lowguid: %u) queued with null queue info!", GUID_LOPART(itQueue->first));
                continue;
            }
            dungeonId = *queue->dungeons.begin();
            queuedTime = uint32(currTime - queue->joinTime);
            role = ROLE_NONE;
            for (LfgRolesMap::const_iterator itPlayer = queue->roles.begin(); itPlayer != queue->roles.end(); ++itPlayer)
                role |= itPlayer->second;

            waitTime = -1;
            if (role & ROLE_TANK)
            {
                if (role & ROLE_HEALER || role & ROLE_DAMAGE)
                    waitTime = m_avgWaitTime;
                else
                    waitTime = m_waitTimeTanks;
            }
            else if (role & ROLE_HEALER)
            {
                if (role & ROLE_DAMAGE)
                    waitTime = m_avgWaitTime;
                else
                    waitTime = m_waitTimeHealer;
            }
            else if (role & ROLE_DAMAGE)
                waitTime = m_waitTimeDps;

            for (LfgRolesMap::const_iterator itPlayer = queue->roles.begin(); itPlayer != queue->roles.end(); ++itPlayer)
                if (Player * plr = sObjectMgr.GetPlayer(itPlayer->first))
                    plr->GetSession()->SendLfgQueueStatus(dungeonId, waitTime, m_avgWaitTime, m_waitTimeTanks, m_waitTimeHealer, m_waitTimeDps, queuedTime, queue->tanks, queue->healers, queue->dps);
        }
    }
    else
        m_QueueTimer += diff;
    m_update = true;
}

/// <summary>
/// Initialize Looking For Group
/// </summary>
void LFGMgr::InitLFG()
{
    // Fill reward data (to be removed -> query quest system)
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
    GetAllDungeons();
}

/// <summary>
/// Adds the player/group to lfg queue
/// </summary>
/// <param name="Player *">Player</param>
void LFGMgr::Join(Player *plr)
{
    Group *grp = plr->GetGroup();

    if (grp && grp->GetLeaderGUID() != plr->GetGUID())
        return;

    uint64 guid = grp ? grp->GetGUID() : plr->GetGUID();


    LfgJoinResult result = LFG_JOIN_OK;
    // Previous checks before joining
    if (m_QueueInfoMap[guid])
    {
        result = LFG_JOIN_INTERNAL_ERROR;
        if (grp)
            sLog.outError("LFGMgr::Join: group (lowguid: %u) trying to join but is already in queue!", grp->GetLowGUID());
        else
            sLog.outError("LFGMgr::Join: Player (lowguid: %u) trying to join but is already in queue!", plr->GetGUIDLow());
    }
    else if (plr->InBattleground() || plr->InArena())
        result = LFG_JOIN_USING_BG_SYSTEM;
    else if (plr->HasAura(LFG_SPELL_DESERTER))
        result = LFG_JOIN_DESERTER;
    else if (plr->HasAura(LFG_SPELL_COOLDOWN))
        result = LFG_JOIN_RANDOM_COOLDOWN;
    else
    {
        // Check if all dungeons are valid
        for (LfgDungeonSet::const_iterator it = plr->GetLfgDungeons()->begin(); it != plr->GetLfgDungeons()->end(); ++it)
        {
            if (!GetDungeonGroupType(*it))
            {
                result = LFG_JOIN_DUNGEON_INVALID;
                break;
            }
        }
    }

    // Group checks
    if (grp && result == LFG_JOIN_OK)
    {
        if (grp->GetMembersCount() > MAXGROUPSIZE)
            result = LFG_JOIN_TOO_MUCH_MEMBERS;
        else
        {
            Player *plrg;
            uint8 memberCount = 0;
            for (GroupReference *itr = grp->GetFirstMember(); itr != NULL && result == LFG_JOIN_OK; itr = itr->next())
            {
                plrg = itr->getSource();
                if (plrg)
                {
                    if (plrg->HasAura(LFG_SPELL_DESERTER))
                        result = LFG_JOIN_PARTY_DESERTER;
                    else if (plrg->HasAura(LFG_SPELL_COOLDOWN))
                        result = LFG_JOIN_PARTY_RANDOM_COOLDOWN;
                    ++memberCount;
                }
            }
            if (memberCount != grp->GetMembersCount())
                result = LFG_JOIN_DISCONNECTED;
        }
    }

    if (result != LFG_JOIN_OK)                              // Someone can't join. Clear all stuf
    {
        plr->GetLfgDungeons()->clear();
        plr->SetLfgRoles(ROLE_NONE);
        plr->GetSession()->SendLfgJoinResult(result, 0);
        plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_ROLECHECK_FAILED);
        return;
    }

    if (grp)
    {
        Player *plrg = NULL;
        LfgDungeonSet *dungeons;
        for (GroupReference *itr = plr->GetGroup()->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            plrg = itr->getSource();                        // Not null, checked earlier
            dungeons = plrg->GetLfgDungeons();
            for (LfgDungeonSet::const_iterator itDungeon = plr->GetLfgDungeons()->begin(); itDungeon != plr->GetLfgDungeons()->end(); ++itDungeon)
                dungeons->insert(*itDungeon);
            plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_JOIN_PROPOSAL);
        }
        UpdateRoleCheck(grp, plr);
    }
    else
    {
        plr->GetSession()->SendLfgJoinResult(LFG_JOIN_OK, 0);
        plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_JOIN_PROPOSAL);
        LfgRolesMap roles;
        roles[plr->GetGUIDLow()] = plr->GetLfgRoles();
        AddToQueue(plr->GetGUID(), &roles, plr->GetLfgDungeons());
        roles.clear();
    }
}

/// <summary>
/// Leave the lfg queue
/// </summary>
/// <param name="Player *">Player (could be NULL)</param>
/// <param name="Group *">Group (could be NULL)</param>
void LFGMgr::Leave(Player *plr, Group *grp /* = NULL*/)
{
    uint64 guid = grp ? grp->GetGUID() : plr ? plr->GetGUID() : 0;
    ASSERT(guid);

    // Remove from Role Checks
    if (grp)
    {
        LfgRoleCheckMap::const_iterator itRoleCheck = m_RoleChecks.find(GUID_LOPART(guid));
        if (itRoleCheck != m_RoleChecks.end())
        {
            UpdateRoleCheck(grp);                           // No player to update role = LFG_ROLECHECK_ABORTED
            return;
        }
    }

    // Remove from queue
    RemoveFromQueue(guid);

    if (grp)
    {
        for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            if (Player *plrg = itr->getSource())
            {
                plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
                plrg->GetLfgDungeons()->clear();
                plrg->SetLfgRoles(ROLE_NONE);
            }
    }
    else
    {
        plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
        plr->GetLfgDungeons()->clear();
        plr->SetLfgRoles(ROLE_NONE);
    }
}

/// <summary>
/// Creates a QueueInfo and adds it to the queue. Tries to match a group before joining.
/// </summary>
/// <param name="uint64">Player or group guid</param>
/// <param name="LfgRolesMap *">Player roles</param>
/// <param name="LfgDungeonSet *">Selected dungeons</param>
void LFGMgr::AddToQueue(uint64 guid, LfgRolesMap *roles, LfgDungeonSet *dungeons)
{
    ASSERT(roles);
    ASSERT(dungeons);

    LfgQueueInfo *pqInfo = new LfgQueueInfo();
    pqInfo->joinTime = time_t(time(NULL));
    for (LfgRolesMap::const_iterator it = roles->begin(); it != roles->end(); ++it)
    {
        if (pqInfo->tanks && it->second & ROLE_TANK)
            --pqInfo->tanks;
        else if (pqInfo->healers && it->second & ROLE_HEALER)
            --pqInfo->healers;
        else
            --pqInfo->dps;
    }
    for (LfgRolesMap::const_iterator itRoles = roles->begin(); itRoles != roles->end(); ++itRoles)
        pqInfo->roles[itRoles->first] = itRoles->second;

    // Expand random dungeons
    LfgDungeonSet *expandedDungeons = dungeons;
    if (isRandomDungeon(*dungeons->begin()))
        expandedDungeons = GetDungeonsByRandom(*dungeons->begin());

    for (LfgDungeonSet::const_iterator it = expandedDungeons->begin(); it != expandedDungeons->end(); ++it)
        pqInfo->dungeons.insert(*it);

    m_QueueInfoMap[guid] = pqInfo;
    m_newToQueue.push_back(guid);
}

/// <summary>
/// Removes the player/group from all queues
/// </summary>
/// <param name="uint64">Player or group guid</param>
/// <returns>bool</returns>
bool LFGMgr::RemoveFromQueue(uint64 guid)
{
    m_currentQueue.remove(guid);
    m_newToQueue.remove(guid);
    LfgQueueInfoMap::iterator it = m_QueueInfoMap.find(guid);
    if (it != m_QueueInfoMap.end())
    {
        delete it->second;
        m_QueueInfoMap.erase(it);
        return true;
    }
    return false;
}

/// <summary>
/// Update the Role check info with the player selected role.
/// </summary>
/// <param name="Group *">Group</param>
/// <param name="Player *">Player (optional, default NULL)</param>
void LFGMgr::UpdateRoleCheck(Group *grp, Player *plr /* = NULL*/)
{
    ASSERT(grp);

    uint32 rolecheckId = grp->GetLowGUID();
    LfgRoleCheck *pRoleCheck = NULL;
    LfgRolesMap check_roles;
    LfgRoleCheckMap::iterator itRoleCheck = m_RoleChecks.find(rolecheckId);
    bool newRoleCheck = itRoleCheck == m_RoleChecks.end();
    if (newRoleCheck)
    {
        if (grp->GetLeaderGUID() != plr->GetGUID())
            return;

        pRoleCheck = new LfgRoleCheck();
        pRoleCheck->cancelTime = time_t(time(NULL)) + LFG_TIME_ROLECHECK;
        pRoleCheck->result = LFG_ROLECHECK_INITIALITING;
        pRoleCheck->leader = plr->GetGUIDLow();

        for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            if (Player *plrg = itr->getSource())
                pRoleCheck->roles[plrg->GetGUIDLow()] = 0;

        for (LfgDungeonSet::const_iterator itDungeon = plr->GetLfgDungeons()->begin(); itDungeon != plr->GetLfgDungeons()->end(); ++itDungeon)
            pRoleCheck->dungeons.insert(*itDungeon);
    }
    else
        pRoleCheck = itRoleCheck->second;

    LfgLockStatusMap *playersLockMap = NULL;
    if (plr)
    {
        // Player selected no role.
        if (plr->GetLfgRoles() < ROLE_TANK)
            pRoleCheck->result = LFG_ROLECHECK_NO_ROLE;
        else
        {
            // Check if all players have selected a role
            pRoleCheck->roles[plr->GetGUIDLow()] = plr->GetLfgRoles();
            uint8 size = 0;
            for (LfgRolesMap::const_iterator itRoles = pRoleCheck->roles.begin(); itRoles != pRoleCheck->roles.end() && itRoles->second != ROLE_NONE; ++itRoles)
                ++size;

            if (pRoleCheck->roles.size() == size)
            {
                // use temporal var to check roles, CheckGroupRoles modifies the roles
                check_roles = pRoleCheck->roles;
                if (!CheckGroupRoles(check_roles))              // Group is not posible
                    pRoleCheck->result = LFG_ROLECHECK_WRONG_ROLES;
                else
                {
                    // Check if we can find a dungeon for that group
                    pRoleCheck->result = LFG_ROLECHECK_FINISHED;
                    if (pRoleCheck->dungeons.size() > 1)
                        playersLockMap = GetPartyLockStatusDungeons(plr, &pRoleCheck->dungeons);
                    else
                    {
                        LfgDungeonSet::const_iterator it = pRoleCheck->dungeons.begin();
                        LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(*it);
                        if (dungeon && dungeon->type == LFG_TYPE_RANDOM)
                            playersLockMap = GetPartyLockStatusDungeons(plr, GetDungeonsByRandom(*it));
                        else
                            playersLockMap = GetPartyLockStatusDungeons(plr, &pRoleCheck->dungeons);
                    }
                }
            }
        }
    }
    else
        pRoleCheck->result = LFG_ROLECHECK_ABORTED;

    WorldSession *session;
    WorldPacket data(SMSG_LFG_ROLE_CHECK_UPDATE, 4 + 1 + 1 + pRoleCheck->dungeons.size() * 4 + 1 + pRoleCheck->roles.size() * (8 + 1 + 4 + 1));
    sLog.outDebug("SMSG_LFG_ROLE_CHECK_UPDATE");
    BuildLfgRoleCheck(data, pRoleCheck);

    Player *plrg = NULL;
    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        plrg = itr->getSource();
        if (!plrg)
            continue;

        session = plrg->GetSession();
        if (!newRoleCheck && plr)
            session->SendLfgRoleChosen(plr->GetGUID(), plr->GetLfgRoles());
        session->SendPacket(&data);

        switch(pRoleCheck->result)
        {
        case LFG_ROLECHECK_INITIALITING:
            continue;
        case LFG_ROLECHECK_FINISHED:
            if (!playersLockMap)
                session->SendLfgUpdateParty(LFG_UPDATETYPE_ADDED_TO_QUEUE);
            else
            {
                if (grp->GetLeaderGUID() == plrg->GetGUID())
                {
                    uint32 size = 0;
                    for (LfgLockStatusMap::const_iterator it = playersLockMap->begin(); it != playersLockMap->end(); ++it)
                        size += 8 + 4 + it->second->size() * (4 + 4);
                    WorldPacket data(SMSG_LFG_JOIN_RESULT, 4 + 4 + size);
                    sLog.outDebug("SMSG_LFG_JOIN_RESULT");
                    data << uint32(LFG_JOIN_PARTY_NOT_MEET_REQS); // Check Result
                    data << uint32(0);                      // Check Value (always 0 when PartyNotMeetReqs
                    BuildPartyLockDungeonBlock(data, playersLockMap);
                    session->SendPacket(&data);
                }
                session->SendLfgUpdateParty(LFG_UPDATETYPE_ROLECHECK_FAILED);
                plrg->GetLfgDungeons()->clear();
                plrg->SetLfgRoles(ROLE_NONE);
            }
            break;
        default:
            if (grp->GetLeaderGUID() == plrg->GetGUID())
                session->SendLfgJoinResult(LFG_JOIN_FAILED, pRoleCheck->result);
            session->SendLfgUpdateParty(LFG_UPDATETYPE_ROLECHECK_FAILED);
            plrg->GetLfgDungeons()->clear();
            plrg->SetLfgRoles(ROLE_NONE);
            break;
        }
    }

    if (pRoleCheck->result == LFG_ROLECHECK_FINISHED)
        AddToQueue(grp->GetGUID(), &pRoleCheck->roles, &pRoleCheck->dungeons);

    if (pRoleCheck->result != LFG_ROLECHECK_INITIALITING)
    {
        pRoleCheck->dungeons.clear();
        pRoleCheck->roles.clear();
        delete pRoleCheck;
        if (!newRoleCheck)
            m_RoleChecks.erase(itRoleCheck);
    }
    else if (newRoleCheck)
        m_RoleChecks[rolecheckId] = pRoleCheck;
}

/// <summary>
/// Check if a group can be formed with the given group
/// </summary>
/// <param name="LfgRolesMap &">Roles to check</param>
/// <param name="bool">Used to remove ROLE_LEADER</param>
/// <returns>bool</returns>
bool LFGMgr::CheckGroupRoles(LfgRolesMap &groles, bool removeLeaderFlag /*= true*/)
{
    if (!groles.size())
        return false;

    uint8 damage = 0;
    uint8 tank = 0;
    uint8 healer = 0;

    if (removeLeaderFlag)
        for (LfgRolesMap::iterator it = groles.begin(); it != groles.end(); ++it)
            it->second &= ~ROLE_LEADER;

    for (LfgRolesMap::iterator it = groles.begin(); it != groles.end(); ++it)
    {
        switch(it->second)
        {
        case ROLE_NONE:
            return false;
        case ROLE_TANK:
            if (tank == LFG_TANKS_NEEDED)
                return false;
            tank++;
            break;
        case ROLE_HEALER:
            if (healer == LFG_HEALERS_NEEDED)
                return false;
            healer++;
            break;
        case ROLE_DAMAGE:
            if (damage == LFG_DPS_NEEDED)
                return false;
            damage++;
            break;
        default:
            if (it->second & ROLE_TANK)
            {
                it->second -= ROLE_TANK;
                if (CheckGroupRoles(groles, false))
                    return true;
                it->second += ROLE_TANK;
            }

            if (it->second & ROLE_HEALER)
            {
                it->second -= ROLE_HEALER;
                if (CheckGroupRoles(groles, false))
                    return true;
                it->second += ROLE_HEALER;
            }

            if (it->second & ROLE_DAMAGE)
            {
                it->second -= ROLE_DAMAGE;
                return CheckGroupRoles(groles, false);
            }
            break;
        }
    }
    return tank == LFG_TANKS_NEEDED && healer == LFG_HEALERS_NEEDED && damage == LFG_DPS_NEEDED;
}

// --------------------------------------------------------------------------//
// Packet Functions
// --------------------------------------------------------------------------//

/// <summary>
/// Build lfgRolecheck packet
/// </summary>
/// <param name="WorldPacket &">WorldPacket</param>
/// <param name="LfgRoleCheck *">RoleCheck info</param>
void LFGMgr::BuildLfgRoleCheck(WorldPacket &data, LfgRoleCheck *pRoleCheck)
{
    ASSERT(pRoleCheck);

    Player *plr;
    uint8 roles;

    data << uint32(pRoleCheck->result);                     // Check result
    data << uint8(pRoleCheck->result == LFG_ROLECHECK_INITIALITING);
    data << uint8(pRoleCheck->dungeons.size());             // Number of dungeons
    LFGDungeonEntry const *dungeon;
    for (LfgDungeonSet::iterator it = pRoleCheck->dungeons.begin(); it != pRoleCheck->dungeons.end(); ++it)
    {
        dungeon = sLFGDungeonStore.LookupEntry(*it);        // not null - been checked at join time
        data << uint32(dungeon->Entry());                   // Dungeon
    }

    data << uint8(pRoleCheck->roles.size());                // Players in group
    // Leader info MUST be sent 1st :S
    roles = pRoleCheck->roles[pRoleCheck->leader];
    uint64 guid = MAKE_NEW_GUID(pRoleCheck->leader, 0, HIGHGUID_PLAYER);
    data << uint64(guid);                                   // Guid
    data << uint8(roles > 0);                               // Ready
    data << uint32(roles);                                  // Roles
    plr = sObjectMgr.GetPlayer(guid);
    data << uint8(plr ? plr->getLevel() : 0);               // Level

    for (LfgRolesMap::const_iterator itPlayers = pRoleCheck->roles.begin(); itPlayers != pRoleCheck->roles.end(); ++itPlayers)
    {
        if (itPlayers->first == pRoleCheck->leader)
            continue;

        roles = itPlayers->second;
        guid = MAKE_NEW_GUID(itPlayers->first, 0, HIGHGUID_PLAYER);
        data << uint64(guid);                               // Guid
        data << uint8(roles > 0);                           // Ready
        data << uint32(roles);                              // Roles
        plr = sObjectMgr.GetPlayer(guid);
        data << uint8(plr ? plr->getLevel() : 0);           // Level
    }
}

/// <summary>
/// Build and Send LFG lock player info and reward
/// </summary>
/// <param name="Player *">Player</param>
void LFGMgr::SendLfgPlayerInfo(Player *plr)
{
    uint32 rsize = 0;
    uint32 lsize = 0;
    bool done;
    LfgDungeonSet *randomlist = GetRandomDungeons(plr->getLevel(), plr->GetSession()->Expansion());
    LfgLockStatusSet *lockSet = GetPlayerLockStatusDungeons(plr, GetAllDungeons());

    if (randomlist)
        rsize = randomlist->size();

    if (lockSet)
        lsize = lockSet->size();

    sLog.outDebug("SMSG_LFG_PLAYER_INFO");
    WorldPacket data(SMSG_LFG_PLAYER_INFO, 1 + rsize * (4 + 1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4) + 4 + lsize * (1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4));
    if (!randomlist)
        data << uint8(0);
    else
    {
        LfgReward *reward;
        data << uint8(randomlist->size());                  // Random Dungeon count
        for (LfgDungeonSet::iterator it = randomlist->begin(); it != randomlist->end(); ++it)
        {
            done = plr->isLfgDungeonDone(*it);
            reward = GetRandomDungeonReward(*it, done, plr->getLevel());
            data << uint32(*it);                            // Entry
            data << uint8(done);
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
        randomlist->clear();
        delete randomlist;
    }
    BuildPlayerLockDungeonBlock(data, lockSet);
    plr->GetSession()->SendPacket(&data);
}

/// <summary>
/// Build and Send LFG lock party info and reward
/// </summary>
/// <param name="Player *">Player</param>
void LFGMgr::SendLfgPartyInfo(Player *plr)
{
    if (LfgLockStatusMap *lockMap = GetPartyLockStatusDungeons(plr, GetAllDungeons()))
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
/// Build Party Dungeon lock status packet
/// </summary>
/// <param name="WorldPacket &">WorldPacket</param>
/// <param name="LfgLockStatusMap *">lock status map</param>
void LFGMgr::BuildPartyLockDungeonBlock(WorldPacket &data, LfgLockStatusMap *lockMap)
{
    ASSERT(lockMap);

    data << uint8(lockMap->size());

    LfgLockStatusSet *lockSet;
    for (LfgLockStatusMap::const_iterator it = lockMap->begin(); it != lockMap->end(); ++it)
    {
        lockSet = it->second;
        if (!lockSet)
            continue;

        data << uint64(MAKE_NEW_GUID(it->first, 0, HIGHGUID_PLAYER)); // Player guid
        BuildPlayerLockDungeonBlock(data, lockSet);
    }
    lockMap->clear();
    delete lockMap;
}

/// <summary>
/// Build Player Dungeon lock status packet
/// </summary>
/// <param name="WorldPacket &">WorldPacket</param>
/// <param name="LfgLockStatusSet *">lock status list</param>
void LFGMgr::BuildPlayerLockDungeonBlock(WorldPacket &data, LfgLockStatusSet *lockSet)
{
    ASSERT(lockSet);
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
/// Given a group get the dungeons that can't be done and reason
/// </summary>
/// <param name="PlayerSet *">Players to check lock status</param>
/// <param name="LfgDungeonSet *">Dungeons to check</param>
/// <returns>LfgLockStatusMap*</returns>
LfgLockStatusMap* LFGMgr::GetGroupLockStatusDungeons(PlayerSet *pPlayers, LfgDungeonSet *dungeons)
{
    ASSERT(pPlayers);
    ASSERT(dungeons);

    LfgLockStatusSet *dungeonSet = NULL;
    LfgLockStatusMap *dungeonMap = new LfgLockStatusMap();
    for (PlayerSet::const_iterator itr = pPlayers->begin(); itr != pPlayers->end(); ++itr)
    {
        dungeonSet = GetPlayerLockStatusDungeons(*itr, dungeons);
        if (dungeonSet)
            (*dungeonMap)[(*itr)->GetGUID()] = dungeonSet;
    }

    if (!dungeonMap->size())
    {
        delete dungeonMap;
        dungeonMap = NULL;
    }
    return dungeonMap;
}

/// <summary>
/// Get all Group members list of dungeons that can't be done and reason
/// leader excluded as the list given is he list he can do
/// </summary>
/// <param name="Player *">Player to get Party Lock info</param>
/// <param name="LfgDungeonSet *">Dungeons to check</param>
/// <returns>LfgLockStatusMap*</returns>
LfgLockStatusMap* LFGMgr::GetPartyLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons)
{
    ASSERT(plr);
    ASSERT(dungeons);
    Group *grp = plr->GetGroup();
    if (!grp)
        return NULL;

    PlayerSet *pPlayers = new PlayerSet();
    Player *plrg;
    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        plrg = itr->getSource();
        if (plrg && plrg != plr)
            pPlayers->insert(plrg);
    }
    LfgLockStatusMap *dungeonMap = GetGroupLockStatusDungeons(pPlayers, dungeons);
    pPlayers->clear();
    delete pPlayers;
    return dungeonMap;
}

/// <summary>
/// Get list of dungeons player can't do and reasons
/// </summary>
/// <param name="Player *">Player to check lock status</param>
/// <param name="LfgDungeonSet *">Dungeons to check</param>
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
        ASSERT(dungeon); // Will never happen - We provide a list from sLFGDungeonStore

        locktype = LFG_LOCKSTATUS_OK;
        if (dungeon->expansion > expansion)
            locktype = LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION;
        else if (dungeon->minlevel > level)
            locktype = LFG_LOCKSTATUS_TOO_LOW_LEVEL;
        else if (dungeon->maxlevel < level)
            locktype = LFG_LOCKSTATUS_TOO_HIGH_LEVEL;
        /* TODO - Use these types when needed...
        else if ()
            locktype = LFG_LOCKSTATUS_TOO_LOW_GEAR_SCORE;
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
    if (!list->size())
    {
        delete list;
        list = NULL;
    }
    return list;
}

/// <summary>
/// Get the dungeon list that can be done.
/// </summary>
/// <returns>LfgDungeonSet*</returns>
LfgDungeonSet* LFGMgr::GetAllDungeons()
{
    LfgDungeonSet *alldungeons = m_CachedDungeonMap[0];

    if (alldungeons)
        return alldungeons;

    LfgDungeonSet *dungeons;
    LFGDungeonEntry const *dungeon;

    alldungeons = new LfgDungeonSet();
    m_CachedDungeonMap[0] = alldungeons;
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        dungeon = sLFGDungeonStore.LookupEntry(i);
        if (!dungeon || dungeon->type == LFG_TYPE_ZONE)
            continue;
        dungeons = m_CachedDungeonMap[dungeon->grouptype];
        if (!dungeons)
        {
            dungeons = new LfgDungeonSet();
            m_CachedDungeonMap[dungeon->grouptype] = dungeons;
        }
        if (dungeon->type != LFG_TYPE_RANDOM)
            dungeons->insert(dungeon->ID);
        alldungeons->insert(dungeon->ID);
    }

    return alldungeons;
}

/// <summary>
/// Get the dungeon list that can be done given a random dungeon entry.
/// Special case: randomdungeon == 0 then will return all dungeons
/// </summary>
/// <param name="uint32">Random dungeon entry</param>
/// <returns>LfgDungeonSet*</returns>
LfgDungeonSet* LFGMgr::GetDungeonsByRandom(uint32 randomdungeon)
{
    uint8 groupType = 0;
    if (LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(randomdungeon))
        groupType = dungeon->grouptype;

    return m_CachedDungeonMap[groupType];
}

/// <summary>
/// Get the random dungeon list that can be done at a certain level and expansion.
/// </summary>
/// <param name="uint8">Player level</param>
/// <param name="uint8">Player account expansion</param>
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
/// Get the reward of a given random dungeon at a certain level
/// </summary>
/// <param name="uint32">random dungeon id</param>
/// <param name="bool">Dungeon previously done</param>
/// <param name="uint8">Player level</param>
/// <returns>LfgReward*</returns>
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

/// <summary>
/// Given a Dungeon id returns the dungeon Group Type
/// </summary>
/// <param name="uint32">Dungeon id</param>
/// <returns>uint8: GroupType</returns>
uint8 LFGMgr::GetDungeonGroupType(uint32 dungeonId)
{
    LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(dungeonId);
    if (!dungeon)
        return 0;

    return dungeon->grouptype;
}

/// <summary>
/// Given a Dungeon id returns if it's random
/// </summary>
/// <param name="uint32">Dungeon id</param>
/// <returns>bool</returns>
bool LFGMgr::isRandomDungeon(uint32 dungeonId)
{
    LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(dungeonId);
    if (!dungeon)
        return false;

    return dungeon->type == LFG_TYPE_RANDOM;
}