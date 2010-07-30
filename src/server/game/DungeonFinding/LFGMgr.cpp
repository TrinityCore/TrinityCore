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
#include "LFGMgr.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"

/*********************************************************/
/***                    LFG QUEUES                     ***/
/*********************************************************/

LFGQueue::LFGQueue()
{
    m_LfgQueue.clear();
    avgWaitTime = -1;
    waitTimeTanks = -1;
    waitTimeHealer = -1;
    waitTimeDps = -1;
}

LFGQueue::~LFGQueue()
{
    m_LfgQueue.clear();
}

void LFGQueue::AddToQueue(uint64 guid, LfgQueueInfo* pqInfo)
{
    delete m_LfgQueue[guid];
    m_LfgQueue[guid] = pqInfo;
    // ATM will only add it to the queue... No find group implementation... yet (on purpose)
}

bool LFGQueue::RemoveFromQueue(uint64 guid)
{
    if (m_LfgQueue.empty())
        return false;

    LfgQueueInfoMap::iterator itr = m_LfgQueue.find(guid);
    if (itr == m_LfgQueue.end())
        return false;

    delete itr->second;
    m_LfgQueue.erase(itr);
    return true;
}

LfgQueueInfo* LFGQueue::GetQueueInfo(uint64 guid)
{
    return m_LfgQueue[guid];
}

void LFGQueue::Update()
{
    if (m_LfgQueue.empty())
        return;

    Player *plr;
    LfgQueueInfo *queue;
    time_t currTime = time(NULL);
    uint32 queuedTime;
    uint8 role = 0;
    int32 waitTime = -1;
    for (LfgQueueInfoMap::const_iterator itQueue = m_LfgQueue.begin(); itQueue != m_LfgQueue.end(); ++itQueue)
    {
        queue = itQueue->second;
        // Update queue status
        queuedTime = uint32(currTime - queue->joinTime);
        for (LfgRolesMap::const_iterator itPlayer = queue->roles.begin(); itPlayer != queue->roles.end(); ++itPlayer)
        {
            plr = objmgr.GetPlayer(itPlayer->first);
            if (!plr)
                continue;
            role = itPlayer->second;
            if (role & ROLE_TANK)
            {
                if (role & ROLE_HEALER || role & ROLE_DAMAGE)
                    waitTime = avgWaitTime;
                else
                    waitTime = waitTimeTanks;
            }
            else if (role & ROLE_HEALER)
            {
                if (role & ROLE_DAMAGE)
                    waitTime = avgWaitTime;
                else
                    waitTime = waitTimeDps;
            }
            plr->GetSession()->SendLfgQueueStatus(queue->dungeonId, waitTime, avgWaitTime, waitTimeTanks, waitTimeHealer, waitTimeDps, queuedTime, queue->tanks, queue->healers, queue->dps);
        }
    }
}

LFGMgr::LFGMgr()
{
    m_QueueTimer = 0;
    m_update = true;
}

LFGMgr::~LFGMgr()
{
    // RewardList to be removed -> query quest system
    for (LfgRewardList::iterator it = m_RewardList.begin(); it != m_RewardList.end(); ++it)
        delete *it;
    m_RewardList.clear();

    // RewardDoneList to be removed -> query quest system
    for (LfgRewardList::iterator it = m_RewardDoneList.begin(); it != m_RewardDoneList.end(); ++it)
        delete *it;
    m_RewardDoneList.clear();

    for(LFGQueueMap::iterator it = m_Queues.begin(); it != m_Queues.end(); ++it)
        delete it->second;
    m_Queues.clear();

    for (LfgDungeonMap::iterator it = m_DungeonsMap.begin(); it != m_DungeonsMap.end(); ++it)
    {
        it->second->clear();
        delete it->second;
    }
    m_DungeonsMap.clear();

    for (LfgRoleCheckMap::iterator it = m_RoleChecks.begin(); it != m_RoleChecks.end(); ++it)
        delete it->second;
    m_RoleChecks.clear();
}

void LFGMgr::Update(uint32 diff)
{
    if (!m_update)
        return;

    // Update all players status queue info
    if (m_QueueTimer > LFG_QUEUEUPDATE_INTERVAL)
    {
        m_QueueTimer = 0;
        for (LFGQueueMap::iterator it = m_Queues.begin(); it != m_Queues.end(); ++it)
            it->second->Update();
    }
    else
        m_QueueTimer += diff;

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
            plr = objmgr.GetPlayer(itRoles->first);
            if (!plr)
                continue;
            plr->GetSession()->SendPacket(&data);
            plr->m_lookingForGroup.applyDungeons.clear();
            plr->m_lookingForGroup.roles = 0;

            if (itRoles->first == pRoleCheck->leader)
                plr->GetSession()->SendLfgJoinResult(LFG_JOIN_FAILED, pRoleCheck->result);
        }
        delete pRoleCheck;
        m_RoleChecks.erase(itRoleCheck);
    }
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
    m_DungeonsMap[LFG_ALL_DUNGEONS] = GetAllDungeons();
    m_DungeonsMap[LFG_RANDOM_CLASSIC] = GetDungeonsByRandom(LFG_RANDOM_CLASSIC);
    m_DungeonsMap[LFG_RANDOM_BC_NORMAL] = GetDungeonsByRandom(LFG_RANDOM_BC_NORMAL);
    m_DungeonsMap[LFG_RANDOM_BC_HEROIC] = GetDungeonsByRandom(LFG_RANDOM_BC_HEROIC);
    m_DungeonsMap[LFG_RANDOM_LK_NORMAL] = GetDungeonsByRandom(LFG_RANDOM_LK_NORMAL);
    m_DungeonsMap[LFG_RANDOM_LK_HEROIC] = GetDungeonsByRandom(LFG_RANDOM_LK_HEROIC);
}

/// <summary>
/// Adds the player to lfg queue
/// </summary>
/// <param name="plr">Player</param>
void LFGMgr::Join(Player *plr)
{
    Group *grp = plr->GetGroup();

    // TODO - 2010-05-27 Anyone can init rolecheck when already in a LFD Group?
    if (grp && grp->GetLeaderGUID() != plr->GetGUID())
        return;

    // Previous checks before joining
    LfgJoinResult result = LFG_JOIN_OK;
    if (plr->InBattleGround() || plr->InArena())
        result = LFG_JOIN_USING_BG_SYSTEM;
    else if (plr->HasAura(LFG_SPELL_DESERTER))
        result = LFG_JOIN_DESERTER;
    else if (plr->HasAura(LFG_SPELL_COOLDOWN))
        result = LFG_JOIN_RANDOM_COOLDOWN;
    else
    {
        // Check if all dungeons are valid
        for (LfgDungeonSet::const_iterator it = plr->m_lookingForGroup.applyDungeons.begin(); it != plr->m_lookingForGroup.applyDungeons.end(); ++it)
        {
            if ((m_DungeonsMap[LFG_ALL_DUNGEONS])->find(*it) == (m_DungeonsMap[LFG_ALL_DUNGEONS])->end())
            {
                result = LFG_JOIN_DUNGEON_INVALID;
                break;
            }
        }
    }

    if (grp && result == LFG_JOIN_OK)
    {
        if (grp->GetMembersCount() > MAXGROUPSIZE)
            result = LFG_JOIN_TOO_MUCH_MEMBERS;
        else if(grp->isRaidGroup())
            result = LFG_JOIN_MIXED_RAID_DUNGEON;
        else
        {
            for (GroupReference *itr = grp->GetFirstMember(); itr != NULL && result == LFG_JOIN_OK; itr = itr->next())
            {
                if (Player *plrg = itr->getSource())
                {
                    if (plrg->HasAura(LFG_SPELL_DESERTER))
                        result = LFG_JOIN_PARTY_DESERTER;
                    else if (plrg->HasAura(LFG_SPELL_COOLDOWN))
                        result = LFG_JOIN_PARTY_RANDOM_COOLDOWN;
                }
                else
                    result = LFG_JOIN_DISCONNECTED;
            }
        }
    }

    if (result != LFG_JOIN_OK)
    {
        plr->m_lookingForGroup.applyDungeons.clear();
        plr->m_lookingForGroup.roles = 0;
        plr->GetSession()->SendLfgJoinResult(result, 0);
        return;
    }

    if (grp)
    {
        Player *plrg = NULL;
        for (GroupReference *itr = plr->GetGroup()->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            plrg = itr->getSource();                        // Not null, checked earlier
            plrg->m_lookingForGroup.applyDungeons = plr->m_lookingForGroup.applyDungeons;
            plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_JOIN_PROPOSAL);
        }
        UpdateRoleCheck(grp, plr);
    }
    else
    {
        plr->GetSession()->SendLfgJoinResult(LFG_JOIN_OK, 0);
        plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_JOIN_PROPOSAL);

        // Add player to queue
        LfgQueueInfo *pqInfo;
        uint8 groupType = 0;
        uint8 tanks = LFG_TANKS_NEEDED;
        uint8 healers = LFG_HEALERS_NEEDED;
        uint8 dps = LFG_DPS_NEEDED;
        if (plr->m_lookingForGroup.roles & ROLE_TANK)
            --tanks;
        else if (plr->m_lookingForGroup.roles & ROLE_HEALER)
            --healers;
        else
            --dps;
        m_update = false;
        for (LfgDungeonSet::const_iterator it = plr->m_lookingForGroup.applyDungeons.begin(); it != plr->m_lookingForGroup.applyDungeons.end(); ++it)
        {
            groupType = GetDungeonGroupType(*it);
            pqInfo = m_Queues[groupType] ? m_Queues[groupType]->GetQueueInfo(plr->GetGUID()) : NULL;
            // if exist we have already added the player with another dungeon sharing same GroupType
            if (pqInfo)
                continue;
            pqInfo = new LfgQueueInfo();
            pqInfo->dungeonId = *it;
            pqInfo->joinTime = time_t(time(NULL));
            pqInfo->tanks = tanks;
            pqInfo->healers = healers;
            pqInfo->dps = dps;
            pqInfo->roles[plr->GetGUID()] = plr->m_lookingForGroup.roles;
            if (!m_Queues[groupType])
                m_Queues[groupType] = new LFGQueue();
            m_Queues[groupType]->AddToQueue(plr->GetGUID(), pqInfo);
        }
        m_update = true;
    }
}

/// <summary>
/// Leave the lfg queue
/// </summary>
/// <param name="plr">Player (could be NULL)</param>
/// <param name="grp">Group (could be NULL)</param>
void LFGMgr::Leave(Player *plr, Group *grp /* = NULL*/)
{
    uint64 guid = grp ? grp->GetGUID() : plr ? plr->GetGUID() : 0;
    ASSERT(guid);

    // Check if player was in a rolecheck
    if (grp)
    {
        LfgRoleCheckMap::iterator itRoleCheck = m_RoleChecks.find(GUID_LOPART(grp->GetGUID()));
        if (itRoleCheck != m_RoleChecks.end())
        {
            UpdateRoleCheck(grp);                           // No player to update role = LFG_ROLECHECK_ABORTED
            return;
        }
    }

    // Check if player/group was in the queue
    bool inQueue = false;
    for (LFGQueueMap::iterator it = m_Queues.begin(); it != m_Queues.end(); ++it)
        inQueue |= it->second->RemoveFromQueue(guid);

    // Not in queue
    if (!inQueue)
        return;

    if (grp)
    {
        for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            if (Player *plrg = itr->getSource())
            {
                plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
                plrg->m_lookingForGroup.applyDungeons.clear();
                plrg->m_lookingForGroup.roles = 0;
            }
    }
    else
    {
        plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
        plr->m_lookingForGroup.applyDungeons.clear();
        plr->m_lookingForGroup.roles = 0;
    }
}

/// <summary>
/// Update the Role check info with the player selected role.
/// </summary>
/// <param name="grp">Group</param>
/// <param name="plr">Player</param>
void LFGMgr::UpdateRoleCheck(Group *grp, Player *plr /* = NULL*/)
{
    ASSERT(grp);

    uint32 rolecheckId = GUID_LOPART(grp->GetGUID());
    LfgRoleCheck *pRoleCheck = NULL;
    LfgRolesMap check_roles;
    LfgRoleCheckMap::iterator itRoleCheck = m_RoleChecks.find(rolecheckId);
    bool newRoleCheck = itRoleCheck == m_RoleChecks.end();
    if (newRoleCheck)
    {
        if (!grp->IsLeader(plr->GetGUID()))
            return;

        pRoleCheck = new LfgRoleCheck();
        pRoleCheck->cancelTime = time_t(time(NULL)) + LFG_TIME_ROLECHECK;
        pRoleCheck->result = LFG_ROLECHECK_INITIALITING;
        pRoleCheck->leader = plr->GetGUID();

        for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            if (Player *plrg = itr->getSource())
                pRoleCheck->roles[plrg->GetGUID()] = 0;

        pRoleCheck->dungeons = plr->m_lookingForGroup.applyDungeons;
    }
    else
        pRoleCheck = itRoleCheck->second;

    LfgLockStatusMap *playersLockMap = NULL;
    if (plr)
    {
        // Player selected no role.
        if (plr->m_lookingForGroup.roles < ROLE_TANK)
            pRoleCheck->result = LFG_ROLECHECK_NO_ROLE;
        else
        {
            // Check if all players have selected a role
            pRoleCheck->roles[plr->GetGUID()] = plr->m_lookingForGroup.roles;
            uint8 size = 0;
            for (LfgRolesMap::const_iterator itRoles = pRoleCheck->roles.begin(); itRoles != pRoleCheck->roles.end() && itRoles->second != ROLE_NONE; ++itRoles)
                ++size;

            if (pRoleCheck->roles.size() == size)
            {
                // use temporal var to check roles, CheckGroupRoles modifies the roles
                for (LfgRolesMap::const_iterator itRoles = pRoleCheck->roles.begin(); itRoles != pRoleCheck->roles.end(); ++itRoles)
                    check_roles[itRoles->first] = itRoles->second;

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
                            playersLockMap = GetPartyLockStatusDungeons(plr, m_DungeonsMap[*it]);
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
            session->SendLfgRoleChosen(plr->GetGUID(), plr->m_lookingForGroup.roles);
        session->SendPacket(&data);

        switch(pRoleCheck->result)
        {
        case LFG_ROLECHECK_INITIALITING:
            continue;
        case LFG_ROLECHECK_FINISHED:
            if (!playersLockMap)
            {
                session->SendLfgUpdateParty(LFG_UPDATETYPE_ADDED_TO_QUEUE);
            }
            else
            {
                if (grp->IsLeader(plrg->GetGUID()))
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
                plrg->m_lookingForGroup.applyDungeons.clear();
                plrg->m_lookingForGroup.roles = 0;
            }
            break;
        default:
            if (grp->IsLeader(plrg->GetGUID()))
                session->SendLfgJoinResult(LFG_JOIN_FAILED, pRoleCheck->result);
            session->SendLfgUpdateParty(LFG_UPDATETYPE_ROLECHECK_FAILED);
            plrg->m_lookingForGroup.applyDungeons.clear();
            plrg->m_lookingForGroup.roles = 0;
            break;
        }
    }

    if (pRoleCheck->result == LFG_ROLECHECK_FINISHED)
    {
        // Add qroup to queue
        LfgQueueInfo *pqInfo;
        uint8 groupType = 0;
        uint8 tanks = LFG_TANKS_NEEDED;
        uint8 healers = LFG_HEALERS_NEEDED;
        uint8 dps = LFG_DPS_NEEDED;
        for (LfgRolesMap::const_iterator it = check_roles.begin(); it != check_roles.end(); ++it)
        {
            if (it->second & ROLE_TANK)
                --tanks;
            else if (it->second & ROLE_HEALER)
                --healers;
            else
                --dps;
        }
        uint64 guid = grp->GetGUID();
        m_update = false;
        for (LfgDungeonSet::const_iterator it = pRoleCheck->dungeons.begin(); it != pRoleCheck->dungeons.end(); ++it)
        {
            groupType = GetDungeonGroupType(*it);
            pqInfo = m_Queues[groupType] ? m_Queues[groupType]->GetQueueInfo(guid) : NULL;
            // if exist we have already added the player with another dungeon sharing same GroupType
            if (pqInfo)
                continue;
            pqInfo = new LfgQueueInfo();
            pqInfo->dungeonId = *it;
            pqInfo->joinTime = time_t(time(NULL));
            pqInfo->tanks = tanks;
            pqInfo->healers = healers;
            pqInfo->dps = dps;
            for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                if (Player *plrg = itr->getSource())
                    pqInfo->roles[plrg->GetGUID()] = plrg->m_lookingForGroup.roles;
            }
            if (!m_Queues[groupType])
                m_Queues[groupType] = new LFGQueue();
            m_Queues[groupType]->AddToQueue(guid, pqInfo);
        }
        m_update = true;
    }

    if (pRoleCheck->result != LFG_ROLECHECK_INITIALITING)
    {
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
/// <param name="groles">Map of roles</param>
/// <param name="firstCall">bool, will be used to remove ROLE_LEADER</param>
/// <returns>bool</returns>
bool LFGMgr::CheckGroupRoles(LfgRolesMap &groles, bool removeLeaderFlag /*= true*/)
{
    if (!groles.size())
        return false;

    uint8 damage = 0;
    uint8 tank = 0;
    uint8 healer = 0;
    uint64 tguid = 0;
    uint64 hguid = 0;
    uint64 dguid = 0;
    uint64 guid = 0;
    uint8 role = 0;

    if (removeLeaderFlag)
        for (LfgRolesMap::iterator it = groles.begin(); it != groles.end(); ++it)
            it->second &= ~ROLE_LEADER;

    for (LfgRolesMap::const_iterator it = groles.begin(); it != groles.end(); ++it)
    {
        guid = it->first;
        role = it->second;

        if (role == ROLE_NONE)
            return false;

        if (role & ROLE_TANK)
        {
            if (!tank)
            {
                tguid = guid;
                ++tank;
            }
            else
            {
                if (groles[tguid] == ROLE_TANK)
                    tguid = guid;
                groles[tguid] -= ROLE_TANK;
                return CheckGroupRoles(groles, false);
            }
        }

        if (role & ROLE_HEALER)
        {
            if (!healer)
            {
                hguid = guid;
                ++healer;
            }
            else
            {
                if (groles[hguid] == ROLE_HEALER)
                    hguid = guid;
                groles[hguid] -= ROLE_HEALER;
                return CheckGroupRoles(groles, false);
            }
        }

        if (role & ROLE_DAMAGE)
        {
            if (damage < 3)
            {
                if (!damage)
                    dguid = guid;
                ++damage;
            }
            else
            {
                if (groles[dguid] == ROLE_DAMAGE)
                    dguid = guid;
                groles[dguid] -= ROLE_DAMAGE;
                if (!CheckGroupRoles(groles, false))
                    groles[dguid] += ROLE_DAMAGE;
                else
                    return true;
            }
        }
    }
    return true;
}



// --------------------------------------------------------------------------//
// Packet Functions
// --------------------------------------------------------------------------//

/// <summary>
/// Build lfgRolecheck packet
/// </summary>
/// <param name="data">WorldPacket</param>
/// <param name="plr">Player</param>
/// <param name="status">Player status in LFG system</param>
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
    data << uint64(pRoleCheck->leader);                     // Guid
    data << uint8(roles > 0);                               // Ready
    data << uint32(roles);                                  // Roles
    plr = objmgr.GetPlayer(pRoleCheck->leader);
    if (plr)
        data << uint8(plr->getLevel());                     // Level
    else
        data << uint8(0);

    for (LfgRolesMap::const_iterator itPlayers = pRoleCheck->roles.begin(); itPlayers != pRoleCheck->roles.end(); ++itPlayers)
    {
        if (itPlayers->first == pRoleCheck->leader)
            continue;

        roles = itPlayers->second;
        data << uint64(itPlayers->first);                   // Guid
        data << uint8(roles > 0);                           // Ready
        data << uint32(roles);                              // Roles
        plr = objmgr.GetPlayer(pRoleCheck->leader);
        if (plr)
            data << uint8(plr->getLevel());                 // Level
        else
            data << uint8(0);
    }
}

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
        data << uint8(0);
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
    ASSERT(lockMap);

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
/// Get all Group members list of dungeons that can't be done and reason
/// leader excluded as the list given is he list he can do
/// </summary>
/// <param name="grp">Group</param>
/// <param name="dungeons">Dungeons to check</param>
/// <returns>LfgLockStatusMap*</returns>
LfgLockStatusMap* LFGMgr::GetPartyLockStatusDungeons(Player *plr, LfgDungeonSet *dungeons)
{
    ASSERT(plr);
    ASSERT(dungeons);
    Group *grp = plr->GetGroup();
    if (!grp)
        return NULL;

    Player *plrg;
    LfgLockStatusSet *dungeonSet = NULL;
    LfgLockStatusMap *dungeonMap = new LfgLockStatusMap();
    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        plrg = itr->getSource();
        if (!plrg || plrg == plr)
            continue;

        dungeonSet = GetPlayerLockStatusDungeons(plrg, dungeons);
        if (dungeonSet)
            (*dungeonMap)[plrg->GetGUID()] = dungeonSet;
    }

    if (!dungeonMap->size())
    {
        delete dungeonMap;
        dungeonMap = NULL;
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

/// <summary>
/// Given a Dungeon id returns the dungeon Group Type
/// </summary>
/// <param name="dungeonId">Dungeon id</param>
/// <returns>uint8: GroupType</returns>
uint8 LFGMgr::GetDungeonGroupType(uint32 dungeonId)
{
    LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(dungeonId);
    if (!dungeon)
        return 0;

    return dungeon->grouptype;
}
