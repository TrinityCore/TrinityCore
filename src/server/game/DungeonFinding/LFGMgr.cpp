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
#include "DisableMgr.h"
#include "WorldPacket.h"
#include "ProgressBar.h"

LFGMgr::LFGMgr()
{
    m_QueueTimer = 0;
    m_WaitTimeAvg = -1;
    m_WaitTimeTank = -1;
    m_WaitTimeHealer = -1;
    m_WaitTimeDps = -1;
    m_NumWaitTimeAvg = 0;
    m_NumWaitTimeTank = 0;
    m_NumWaitTimeHealer = 0;
    m_NumWaitTimeDps = 0;
    m_update = true;
    m_lfgProposalId = 1;
    GetAllDungeons();
}

LFGMgr::~LFGMgr()
{
    for (LfgRewardMap::iterator itr = m_RewardMap.begin(); itr != m_RewardMap.end(); ++itr)
        delete itr->second;
    m_RewardMap.clear();

    m_EncountersByAchievement.clear();

    for (LfgQueueInfoMap::iterator it = m_QueueInfoMap.begin(); it != m_QueueInfoMap.end(); ++it)
        delete it->second;
    m_QueueInfoMap.clear();

    for (LfgProposalMap::iterator it = m_Proposals.begin(); it != m_Proposals.end(); ++it)
        delete it->second;
    m_Proposals.clear();

    for (LfgPlayerBootMap::iterator it = m_Boots.begin(); it != m_Boots.end(); ++it)
        delete it->second;
    m_Boots.clear();

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


// Temporal add to try to find bugs that leaves data inconsistent
void LFGMgr::Cleaner()
{
    LfgQueueInfoMap::iterator itQueue;
    LfgGuidList::iterator itGuidListRemove;
    LfgGuidList eraseList;

    for (LfgQueueInfoMap::iterator it = m_QueueInfoMap.begin(); it != m_QueueInfoMap.end();)
    {
        itQueue = it++;
        // Remove empty queues
        if (!itQueue->second)
        {
            sLog.outError("LFGMgr::Cleaner: removing " UI64FMTD " from QueueInfoMap, data is null", itQueue->first);
            m_QueueInfoMap.erase(itQueue);
        }
        // Remove queue with empty players
        else if(!itQueue->second->roles.size())
        {
            sLog.outError("LFGMgr::Cleaner: removing " UI64FMTD " from QueueInfoMap, no players in queue!", itQueue->first);
            m_QueueInfoMap.erase(itQueue);
        }
    }

    // Remove from NewToQueue those guids that do not exist in queueMap
    for (LfgGuidList::iterator it = m_newToQueue.begin(); it != m_newToQueue.end();)
    {
        itGuidListRemove = it++;
        if (m_QueueInfoMap.find(*itGuidListRemove) == m_QueueInfoMap.end())
        {
            eraseList.push_back(*itGuidListRemove);
            m_newToQueue.erase(itGuidListRemove);
            sLog.outError("LFGMgr::Cleaner: removing " UI64FMTD " from newToQueue, no queue info with that guid", *itGuidListRemove);
        }
    }

    // Remove from currentQueue those guids that do not exist in queueMap
    for (LfgGuidList::iterator it = m_currentQueue.begin(); it != m_currentQueue.end();)
    {
        itGuidListRemove = it++;
        if (m_QueueInfoMap.find(*itGuidListRemove) == m_QueueInfoMap.end())
        {
            eraseList.push_back(*itGuidListRemove);
            m_newToQueue.erase(itGuidListRemove);
            sLog.outError("LFGMgr::Cleaner: removing " UI64FMTD " from currentQueue, no queue info with that guid", *itGuidListRemove);
        }
    }

    for (LfgGuidList::iterator it = eraseList.begin(); it != eraseList.end(); ++it)
    {
        if (IS_GROUP(*it))
        {
            if (Group *grp = sObjectMgr.GetGroupByGUID(GUID_LOPART(*it)))
                for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
                    if (Player *plr = itr->getSource())
                        plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
        }
        else
            if (Player *plr = sObjectMgr.GetPlayer(*it))
                plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
    }
}

// Temporal added to perform consistency check before adding
void LFGMgr::AddGuidToNewQueue(uint64 guid)
{
    // Consistency check
    LfgGuidList::const_iterator it;
    for (it = m_newToQueue.begin(); it != m_newToQueue.end(); ++it)
    {
        if (*it == guid)
        {
            sLog.outError("LFGMgr::AddToQueue: " UI64FMTD " being added to queue and it was already added. ignoring", guid);
            break;
        }
    }
    if (it == m_newToQueue.end())
    {
        LfgGuidList::iterator itRemove;
        for (LfgGuidList::iterator it = m_currentQueue.begin(); it != m_currentQueue.end() && *it != guid;)
        {
            itRemove = it++;
            if (*itRemove == guid)
            {
                sLog.outError("LFGMgr::AddToQueue: " UI64FMTD " being added to queue and already in current queue (removing to readd)", guid);
                m_currentQueue.erase(itRemove);
                break;
            }
        }
        // Add to queue
        m_newToQueue.push_back(guid);
    }
}

void LFGMgr::Update(uint32 diff)
{
    if (!m_update || !sWorld.getBoolConfig(CONFIG_DUNGEON_FINDER_ENABLE))
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

    // Remove obsolete proposals
    LfgProposalMap::iterator itRemove;
    for (LfgProposalMap::iterator it = m_Proposals.begin(); it != m_Proposals.end();)
    {
        itRemove = it++;
        if (itRemove->second->cancelTime < currTime)
            RemoveProposal(itRemove, LFG_UPDATETYPE_PROPOSAL_FAILED);
    }

    // Remove obsolete kicks
    LfgPlayerBootMap::iterator itBoot;
    LfgPlayerBoot *pBoot;
    for (LfgPlayerBootMap::iterator it = m_Boots.begin(); it != m_Boots.end();)
    {
        itBoot = it++;
        pBoot = itBoot->second;
        if (pBoot->cancelTime < currTime)
        {
            Group *grp = sObjectMgr.GetGroupByGUID(itBoot->first);
            pBoot->inProgress = false;
            for (LfgAnswerMap::const_iterator itVotes = pBoot->votes.begin(); itVotes != pBoot->votes.end(); ++itVotes)
                if (Player *plrg = sObjectMgr.GetPlayer(itVotes->first))
                    if (plrg->GetGUIDLow() != pBoot->victimLowGuid)
                        plrg->GetSession()->SendLfgBootPlayer(pBoot);
            if (grp)
                grp->SetLfgKickActive(false);
            delete pBoot;
            m_Boots.erase(itBoot);
        }
    }

    // Consistency cleaner
    Cleaner();

    // Check if a proposal can be formed with the new groups being added
    LfgProposalList proposals;
    LfgGuidList firstNew;
    if (!m_newToQueue.empty())
    {
        firstNew.push_back(m_newToQueue.front());
        FindNewGroups(firstNew, m_currentQueue, &proposals);
        if (proposals.size())                               // Group found!
        {
            LfgProposal *pProposal = *proposals.begin();
            // TODO: Create algorithm to select better group based on GS (uses to be good tank with bad healer and viceversa)

            // Remove groups in the proposal new and current queues (not from queue map)
            for (LfgGuidList::const_iterator it = pProposal->queues.begin(); it != pProposal->queues.end(); ++it)
            {
                m_currentQueue.remove(*it);
                m_newToQueue.remove(*it);
            }
            m_Proposals[++m_lfgProposalId] = pProposal;

            uint32 lowGuid = 0;
            for (LfgProposalPlayerMap::const_iterator itPlayers = pProposal->players.begin(); itPlayers != pProposal->players.end(); ++itPlayers)
            {
                lowGuid = itPlayers->first;
                if (Player *plr = sObjectMgr.GetPlayer(itPlayers->first))
                {
                    if (plr->GetGroup())
                        plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_PROPOSAL_BEGIN);
                    else
                        plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_PROPOSAL_BEGIN);
                    plr->GetSession()->SendUpdateProposal(m_lfgProposalId, pProposal);
                }
            }

            if (pProposal->state == LFG_PROPOSAL_SUCCESS)
                UpdateProposal(m_lfgProposalId, lowGuid, 1);

            // Clean up
            for (LfgProposalList::iterator it = proposals.begin(); it != proposals.end(); ++it)
            {
                if ((*it) == pProposal)                     // Do not remove the selected proposal;
                    continue;
                (*it)->queues.clear();
                for (LfgProposalPlayerMap::iterator itPlayers = (*it)->players.begin(); itPlayers != (*it)->players.end(); ++itPlayers)
                    delete itPlayers->second;
                (*it)->players.clear();
                delete (*it);
            }
            proposals.clear();
        }
        else
        {
            m_currentQueue.push_back(m_newToQueue.front()); // Group not found, add this group to the queue.
            m_newToQueue.pop_front();
        }
        firstNew.clear();
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
                    waitTime = m_WaitTimeAvg;
                else
                    waitTime = m_WaitTimeTank;
            }
            else if (role & ROLE_HEALER)
            {
                if (role & ROLE_DAMAGE)
                    waitTime = m_WaitTimeAvg;
                else
                    waitTime = m_WaitTimeHealer;
            }
            else if (role & ROLE_DAMAGE)
                waitTime = m_WaitTimeDps;

            for (LfgRolesMap::const_iterator itPlayer = queue->roles.begin(); itPlayer != queue->roles.end(); ++itPlayer)
                if (Player * plr = sObjectMgr.GetPlayer(itPlayer->first))
                    plr->GetSession()->SendLfgQueueStatus(dungeonId, waitTime, m_WaitTimeAvg, m_WaitTimeTank, m_WaitTimeHealer, m_WaitTimeDps, queuedTime, queue->tanks, queue->healers, queue->dps);
        }
    }
    else
        m_QueueTimer += diff;
    m_update = true;
}

/// <summary>
/// Load achievement <-> encounter associations
/// </summary>
void LFGMgr::LoadDungeonEncounters()
{
    m_EncountersByAchievement.clear();

    uint32 count = 0;
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT achievementId, dungeonId FROM lfg_dungeon_encounters");

    if (!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded 0 dungeon encounter lfg associations. DB table `lfg_dungeon_encounters` is empty!");
        return;
    }

    barGoLink bar(result->GetRowCount());

    Field* fields = NULL;
    do
    {
        fields = result->Fetch();
        uint32 achievementId = fields[0].GetUInt32();
        uint32 dungeonId = fields[1].GetUInt32();

        if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementId))
        {
            if (!(achievement->flags & ACHIEVEMENT_FLAG_COUNTER))
            {
                sLog.outErrorDb("Achievement %u specified in table `lfg_dungeon_encounters` is not a statistic!", achievementId);
                continue;
            }
        }
        else
        {
            sLog.outErrorDb("Achievement %u specified in table `lfg_dungeon_encounters` does not exist!", achievementId);
            continue;
        }

        if (!sLFGDungeonStore.LookupEntry(dungeonId))
        {
            sLog.outErrorDb("Dungeon %u specified in table `lfg_dungeon_encounters` does not exist!", dungeonId);
            continue;
        }

        m_EncountersByAchievement[achievementId] = dungeonId;
        ++count;
    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u dungeon encounter lfg associations.", count);
}

/// <summary>
/// Load rewards for completing dungeons
/// </summary>
void LFGMgr::LoadRewards()
{
    for (LfgRewardMap::iterator itr = m_RewardMap.begin(); itr != m_RewardMap.end(); ++itr)
        delete itr->second;
    m_RewardMap.clear();

    uint32 count = 0;
    // ORDER BY is very important for GetRandomDungeonReward!
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT dungeonId, maxLevel, firstQuestId, firstMoneyVar, firstXPVar, otherQuestId, otherMoneyVar, otherXPVar FROM lfg_dungeon_rewards ORDER BY dungeonId, maxLevel ASC");

    if (!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded 0 lfg dungeon rewards. DB table `lfg_dungeon_rewards` is empty!");
        return;
    }

    barGoLink bar(result->GetRowCount());

    Field* fields = NULL;
    do
    {
        fields = result->Fetch();
        uint32 dungeonId = fields[0].GetUInt32();
        uint32 maxLevel = fields[1].GetUInt8();
        uint32 firstQuestId = fields[2].GetUInt32();
        uint32 firstMoneyVar = fields[3].GetUInt32();
        uint32 firstXPVar = fields[4].GetUInt32();
        uint32 otherQuestId = fields[5].GetUInt32();
        uint32 otherMoneyVar = fields[6].GetUInt32();
        uint32 otherXPVar = fields[7].GetUInt32();

        if (!sLFGDungeonStore.LookupEntry(dungeonId))
        {
            sLog.outErrorDb("Dungeon %u specified in table `lfg_dungeon_rewards` does not exist!", dungeonId);
            continue;
        }

        if (!maxLevel || maxLevel > sWorld.getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            sLog.outErrorDb("Level %u specified for dungeon %u in table `lfg_dungeon_rewards` can never be reached!", maxLevel, dungeonId);
            maxLevel = sWorld.getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
        }

        if (firstQuestId && !sObjectMgr.GetQuestTemplate(firstQuestId))
        {
            sLog.outErrorDb("First quest %u specified for dungeon %u in table `lfg_dungeon_rewards` does not exist!", firstQuestId, dungeonId);
            firstQuestId = 0;
        }

        if (otherQuestId && !sObjectMgr.GetQuestTemplate(otherQuestId))
        {
            sLog.outErrorDb("Other quest %u specified for dungeon %u in table `lfg_dungeon_rewards` does not exist!", otherQuestId, dungeonId);
            otherQuestId = 0;
        }

        m_RewardMap.insert(LfgRewardMap::value_type(dungeonId, new LfgReward(maxLevel, firstQuestId, firstMoneyVar, firstXPVar, otherQuestId, otherMoneyVar, otherXPVar)));
        ++count;
    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u lfg dungeon rewards.", count);
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
    LfgQueueInfoMap::iterator itQueue = m_QueueInfoMap.find(guid);
    if (itQueue != m_QueueInfoMap.end())
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
            if (plrg != plr)
            {
                dungeons = plrg->GetLfgDungeons();
                dungeons->clear();
                for (LfgDungeonSet::const_iterator itDungeon = plr->GetLfgDungeons()->begin(); itDungeon != plr->GetLfgDungeons()->end(); ++itDungeon)
                    dungeons->insert(*itDungeon);
            }
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
    if (plr && !plr->GetLfgUpdate())
        return;

    uint64 guid = grp ? grp->GetGUID() : plr ? plr->GetGUID() : 0;

    // Remove from Role Checks
    if (grp)
    {
        grp->SetLfgQueued(false);
        LfgRoleCheckMap::const_iterator itRoleCheck = m_RoleChecks.find(GUID_LOPART(guid));
        if (itRoleCheck != m_RoleChecks.end())
        {
            UpdateRoleCheck(grp);                           // No player to update role = LFG_ROLECHECK_ABORTED
            return;
        }
    }

    // Remove from queue
    RemoveFromQueue(guid);

    // Remove from Proposals
    for (LfgProposalMap::iterator it = m_Proposals.begin(); it != m_Proposals.end(); ++it)
    {
        // Mark the player/leader of group who left as didn't accept the proposal
        for (LfgProposalPlayerMap::iterator itPlayer = it->second->players.begin(); itPlayer != it->second->players.end(); ++itPlayer)
            if ((plr && itPlayer->first == plr->GetGUIDLow()) || (grp && itPlayer->first == GUID_LOPART(grp->GetLeaderGUID())))
                itPlayer->second->accept = 0;
    }

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
/// Given a Lfg group checks if leader needs to be show the popup to select more players
/// </summary>
/// <param name="Group *">Group than needs new players</param>
void LFGMgr::OfferContinue(Group *grp)
{
    if (grp && grp->GetLfgStatus() != LFG_STATUS_COMPLETE)
        if (Player *leader = sObjectMgr.GetPlayer(grp->GetLeaderGUID()))
            leader->GetSession()->SendLfgOfferContinue(grp->GetLfgDungeonEntry(false));
}

/// <summary>
/// Creates a QueueInfo and adds it to the queue. Tries to match a group before joining.
/// </summary>
/// <param name="uint64">Player or group guid</param>
/// <param name="LfgRolesMap *">Player roles</param>
/// <param name="LfgDungeonSet *">Selected dungeons</param>
void LFGMgr::AddToQueue(uint64 guid, LfgRolesMap *roles, LfgDungeonSet *dungeons)
{
    if (!roles || !dungeons)
        return;

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
    AddGuidToNewQueue(guid);
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
/// Check the queue to try to match groups. Returns all the posible matches
/// </summary>
/// <param name="LfgGuidList &">Guids we trying to match with the rest of groups</param>
/// <param name="LfgGuidList">All guids in queue</param>
/// <param name="LfgProposalList *">Proposals found.</param>
void LFGMgr::FindNewGroups(LfgGuidList &check, LfgGuidList all, LfgProposalList *proposals)
{
    if (!check.size() || check.size() > MAXGROUPSIZE)
        return;

    uint8 numPlayers = 0;
    uint8 numLfgGroups = 0;
    uint32 groupLowGuid = 0;
    LfgQueueInfoMap pqInfoMap;
    LfgQueueInfoMap::iterator itQueue;
    for (LfgGuidList::const_iterator it = check.begin(); it != check.end() && numLfgGroups < 2 && numPlayers <= MAXGROUPSIZE; ++it)
    {
        itQueue = m_QueueInfoMap.find(*it);
        if (itQueue == m_QueueInfoMap.end())
        {
            sLog.outError("LFGMgr::FindNewGroups: " UI64FMTD " is not queued but listed as queued!", *it);
            return;
        }
        pqInfoMap[*it] = itQueue->second;
        numPlayers += itQueue->second->roles.size();

        if (IS_GROUP(*it))
        {
            uint32 lowGuid = GUID_LOPART(*it);
            if (Group *grp = sObjectMgr.GetGroupByGUID(lowGuid))
                if (grp->isLFGGroup())
                {
                    if (!numLfgGroups)
                        groupLowGuid = lowGuid;
                    ++numLfgGroups;
                }
        }
    }

    // Do not match groups already in a lfgDungeon
    if (numLfgGroups > 1 || numPlayers > MAXGROUPSIZE)
    {
        pqInfoMap.clear();
        return;
    }

    if (numPlayers < MAXGROUPSIZE)
    {
        while (!all.empty() && !proposals->size())
        {
            check.push_back(all.front());
            all.pop_front();
            FindNewGroups(check, all, proposals);
            check.pop_back();
        }
        pqInfoMap.clear();
        return;
    }

    // ----- Player checks -----
    LfgRolesMap rolesMap;
    uint32 newLeaderLowGuid = 0;
    for (LfgQueueInfoMap::const_iterator it = pqInfoMap.begin(); it != pqInfoMap.end(); ++it)
    {
        for (LfgRolesMap::const_iterator itRoles = it->second->roles.begin(); itRoles != it->second->roles.end(); ++itRoles)
        {
            // Assign new leader
            if (itRoles->second & ROLE_LEADER && (!newLeaderLowGuid || urand(0, 1)))
                newLeaderLowGuid = itRoles->first;
            rolesMap[itRoles->first] = itRoles->second;
        }
    }

    if (rolesMap.size() != MAXGROUPSIZE)
    {
        sLog.outError("LFGMgr::FindNewGroups: There is a player multiple times in queue.");
        return;
    }

    Player *plr;
    PlayerSet players;
    for (LfgRolesMap::const_iterator it = rolesMap.begin(); it != rolesMap.end(); ++it)
    {
        plr = sObjectMgr.GetPlayer(it->first);
        for (PlayerSet::const_iterator itPlayer = players.begin(); itPlayer != players.end() && plr; ++itPlayer)
        {
            // Do not form a group with ignoring candidates
            if (plr->GetSocial()->HasIgnore((*itPlayer)->GetGUIDLow()) || (*itPlayer)->GetSocial()->HasIgnore(plr->GetGUIDLow()))
                plr = NULL;
            // neither with diferent faction if it's not a mixed faction server
            else if (plr->GetTeam() != (*itPlayer)->GetTeam() && !sWorld.getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP))
                plr = NULL;
        }
        if (plr)
            players.insert(plr);
    }

    // if we dont have MAXGROUPSIZE (5) then we have self ignoring candidates or different faction groups
    // otherwise check if roles are compatible
    if (players.size() != MAXGROUPSIZE || !CheckGroupRoles(rolesMap))
    {
        players.clear();
        pqInfoMap.clear();
        return;
    }

    // ----- Selected Dungeon checks -----
    // Check if there are any compatible dungeon from the selected dungeons

    LfgDungeonSet *compatibleDungeons = new LfgDungeonSet();
    bool compatibleDungeon;
    LfgQueueInfoMap::const_iterator itFirst = pqInfoMap.begin();
    LfgQueueInfoMap::const_iterator itOther;
    LfgDungeonSet::const_iterator itDungeon;

    // Get the first group and compare with the others to select all common dungeons
    for (itDungeon = itFirst->second->dungeons.begin(); itDungeon != itFirst->second->dungeons.end(); ++itDungeon)
    {
        itOther = itFirst;
        compatibleDungeon = true;
        for (++itOther; itOther != pqInfoMap.end() && compatibleDungeon; ++itOther)
            if (itOther->second->dungeons.find(*itDungeon) == itOther->second->dungeons.end())
                compatibleDungeon = false;
        if (compatibleDungeon)
            compatibleDungeons->insert(*itDungeon);
    }

    // now remove those with restrictions
    LfgLockStatusMap *pLockDungeons = GetGroupLockStatusDungeons(&players, compatibleDungeons);
    if (pLockDungeons) // Found dungeons not compatible, remove them from the set
    {
        LfgLockStatusSet *pLockSet = NULL;
        for (LfgLockStatusMap::const_iterator itLockMap = pLockDungeons->begin(); itLockMap != pLockDungeons->end() && compatibleDungeons->size(); ++itLockMap)
        {
            pLockSet = itLockMap->second;
            for(LfgLockStatusSet::const_iterator itLockSet = pLockSet->begin(); itLockSet != pLockSet->end(); ++itLockSet)
            {
                itDungeon = compatibleDungeons->find((*itLockSet)->dungeon);
                if (itDungeon != compatibleDungeons->end())
                     compatibleDungeons->erase(itDungeon);
            }
            pLockSet->clear();
            delete pLockSet;
        }
        pLockDungeons->clear();
        delete pLockDungeons;
    }

    pqInfoMap.clear();
    // Any compatible dungeon after checking restrictions?
    if (!compatibleDungeons->size())
    {
        delete compatibleDungeons;
        compatibleDungeons = NULL;
        players.clear();
        return;
    }

    // Select a random dungeon from the compatible list
    itDungeon = compatibleDungeons->begin();
    uint32 selectedDungeon = urand(0, compatibleDungeons->size() - 1);
    while (selectedDungeon > 0)
    {
        ++itDungeon;
        --selectedDungeon;
    }
    selectedDungeon = *itDungeon;
    compatibleDungeons->clear();
    delete compatibleDungeons;

    // Create a new proposal
    LfgProposal *pProposal = new LfgProposal(selectedDungeon);
    pProposal->cancelTime = time_t(time(NULL)) + LFG_TIME_PROPOSAL;
    pProposal->queues = check;
    pProposal->groupLowGuid = groupLowGuid;

    // Assign new roles to players and assign new leader
    LfgProposalPlayer *ppPlayer;
    uint32 lowGuid;
    PlayerSet::const_iterator itPlayers = players.begin();
    if (!newLeaderLowGuid)
    {
        uint8 pos = urand(0, players.size() - 1);
        for (uint8 i = 0; i < pos; ++i)
            ++itPlayers;
        newLeaderLowGuid = (*itPlayers)->GetGUIDLow();
    }
    pProposal->leaderLowGuid = newLeaderLowGuid;

    uint8 numAccept = 0;
    for (itPlayers = players.begin(); itPlayers != players.end(); ++itPlayers)
    {
        lowGuid = (*itPlayers)->GetGUIDLow();
        ppPlayer = new LfgProposalPlayer();
        Group *grp = (*itPlayers)->GetGroup();
        if (grp)
        {
            ppPlayer->groupLowGuid = grp->GetLowGUID();
            if (grp->GetLfgDungeonEntry() == selectedDungeon && ppPlayer->groupLowGuid == pProposal->groupLowGuid) // Player from existing group, autoaccept
            {
                ppPlayer->accept = 1;
                ++numAccept;
            }
        }
        ppPlayer->role = rolesMap[lowGuid];
        pProposal->players[lowGuid] = ppPlayer;
    }
    if (numAccept == MAXGROUPSIZE)
        pProposal->state = LFG_PROPOSAL_SUCCESS;

    if (!proposals)
        proposals = new LfgProposalList();
    proposals->push_back(pProposal);
    players.clear();
}

/// <summary>
/// Update the Role check info with the player selected role.
/// </summary>
/// <param name="Group *">Group</param>
/// <param name="Player *">Player (optional, default NULL)</param>
void LFGMgr::UpdateRoleCheck(Group *grp, Player *plr /* = NULL*/)
{
    if (!grp)
        return;

    uint32 rolecheckId = grp->GetLowGUID();
    LfgRoleCheck *pRoleCheck = NULL;
    LfgRolesMap check_roles;
    LfgRoleCheckMap::iterator itRoleCheck = m_RoleChecks.find(rolecheckId);
    LfgDungeonSet *dungeons = plr->GetLfgDungeons();
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

        // Check if it's offer continue or trying to find a new instance after a random assigned (Join Random + LfgGroup)
        if (grp->isLFGGroup() && dungeons->size() == 1 && isRandomDungeon(*dungeons->begin()) && grp->GetLfgDungeonEntry())
            pRoleCheck->dungeons.insert(grp->GetLfgDungeonEntry());
        else
            for (LfgDungeonSet::const_iterator itDungeon = dungeons->begin(); itDungeon != dungeons->end(); ++itDungeon)
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
    {
        grp->SetLfgQueued(true);
        AddToQueue(grp->GetGUID(), &pRoleCheck->roles, &pRoleCheck->dungeons);
    }

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
    return true;
}

/// <summary>
/// Update Proposal info with player answer
/// </summary>
/// <param name="uint32">Id of the proposal</param>
/// <param name="uint32">Player low guid</param>
/// <param name="uint8">Player answer</param>
void LFGMgr::UpdateProposal(uint32 proposalId, uint32 lowGuid, uint8 accept)
{
    // Check if the proposal exists
    LfgProposalMap::iterator itProposal = m_Proposals.find(proposalId);
    if (itProposal == m_Proposals.end())
        return;
    LfgProposal *pProposal = itProposal->second;

    // Check if proposal have the current player
    LfgProposalPlayerMap::iterator itProposalPlayer = pProposal->players.find(lowGuid);
    if (itProposalPlayer == pProposal->players.end())
        return;
    LfgProposalPlayer *ppPlayer = itProposalPlayer->second;

    ppPlayer->accept = accept;
    if (!accept)
    {
        RemoveProposal(itProposal, LFG_UPDATETYPE_PROPOSAL_DECLINED);
        return;
    }

    LfgPlayerList players;
    Player *plr;

    // check if all have answered and reorder players (leader first)
    bool allAnswered = true;
    for (LfgProposalPlayerMap::const_iterator itPlayers = pProposal->players.begin(); itPlayers != pProposal->players.end(); ++itPlayers)
    {
        plr = sObjectMgr.GetPlayer(itPlayers->first);

        if (plr)
        {
            if (itPlayers->first == pProposal->leaderLowGuid)
                players.push_front(plr);
            else
                players.push_back(plr);
        }

        if (itPlayers->second->accept < 1)                  // No answer (-1) or not accepted (0)
            allAnswered = false;
    }

    if (!allAnswered)
    {
        for (LfgPlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
            (*it)->GetSession()->SendUpdateProposal(proposalId, pProposal);
    }
    else
    {
        bool sendUpdate = pProposal->state != LFG_PROPOSAL_SUCCESS;
        pProposal->state = LFG_PROPOSAL_SUCCESS;
        time_t joinTime = time_t(time(NULL));
        uint8 role = 0;
        int32 waitTime = -1;
        LfgQueueInfoMap::iterator itQueue;
        uint64 guid = 0;

        // Create a new group (if needed)
        Group *grp = sObjectMgr.GetGroupByGUID(pProposal->groupLowGuid);
        for (LfgPlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
        {
            plr = *it;
            if (sendUpdate)
                plr->GetSession()->SendUpdateProposal(proposalId, pProposal);
            plr->SetLfgUpdate(false);
            if (plr->GetGroup())
            {
                guid = plr->GetGroup()->GetGUID();
                plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_GROUP_FOUND);
                if (plr->GetGroup() != grp)
                    plr->RemoveFromGroup();
            }
            else
            {
                guid = plr->GetGUID();
                plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_GROUP_FOUND);
            }

            if (!grp)
            {
                grp = new Group();
                grp->Create(plr->GetGUID(), plr->GetName());
                grp->ConvertToLFG();
                sObjectMgr.AddGroup(grp);
            }
            else if (plr->GetGroup() != grp)
                grp->AddMember(plr->GetGUID(), plr->GetName());
            plr->SetLfgUpdate(true);
            // Update timers
            role = plr->GetLfgRoles();
            itQueue = m_QueueInfoMap.find(guid);
            if (itQueue == m_QueueInfoMap.end())
            {
                sLog.outError("LFGMgr::UpdateProposal: Queue info for guid " UI64FMTD " not found!", guid);
                waitTime = -1;
            }
            else
            {
                waitTime = int32(joinTime - itQueue->second->joinTime);

                if (role & ROLE_TANK)
                {
                    if (role & ROLE_HEALER || role & ROLE_DAMAGE)
                        m_WaitTimeAvg = int32((m_WaitTimeAvg * m_NumWaitTimeAvg + waitTime) / ++m_NumWaitTimeAvg);
                    else
                        m_WaitTimeTank = int32((m_WaitTimeTank * m_NumWaitTimeTank + waitTime) / ++m_NumWaitTimeTank);
                }
                else if (role & ROLE_HEALER)
                {
                    if (role & ROLE_DAMAGE)
                        m_WaitTimeAvg = int32((m_WaitTimeAvg * m_NumWaitTimeAvg + waitTime) / ++m_NumWaitTimeAvg);
                    else
                        m_WaitTimeHealer = int32((m_WaitTimeHealer * m_NumWaitTimeHealer + waitTime) / ++m_NumWaitTimeHealer);
                }
                else if (role & ROLE_DAMAGE)
                    m_WaitTimeDps = int32((m_WaitTimeDps * m_NumWaitTimeDps + waitTime) / ++m_NumWaitTimeDps);
            }

            grp->SetLfgRoles(plr->GetGUID(), pProposal->players[plr->GetGUIDLow()]->role);
        }

        // Set the dungeon difficulty
        LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(pProposal->dungeonId);
        ASSERT(dungeon);
        grp->SetDungeonDifficulty(Difficulty(dungeon->difficulty));
        grp->SetLfgDungeonEntry(dungeon->Entry());
        grp->SetLfgStatus(LFG_STATUS_NOT_SAVED);
        grp->SendUpdate();

        // Remove players/groups from Queue
        for (LfgGuidList::const_iterator it = pProposal->queues.begin(); it != pProposal->queues.end(); ++it)
            RemoveFromQueue(*it);

        // Teleport Player
        for (LfgPlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
            TeleportPlayer(*it, false);

        for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
            delete it->second;
        pProposal->players.clear();
        pProposal->queues.clear();
        delete pProposal;
        m_Proposals.erase(itProposal);
    }
    players.clear();
}

/// <summary>
/// Remove a proposal from the pool, remove the group that didn't accept (if needed) and readd the other members to the queue
/// </summary>
/// <param name="LfgProposalMap::iterator">Proposal to remove</param>
/// <param name="LfgUpdateType">Type of removal (LFG_UPDATETYPE_PROPOSAL_FAILED, LFG_UPDATETYPE_PROPOSAL_DECLINED)</param>
void LFGMgr::RemoveProposal(LfgProposalMap::iterator itProposal, LfgUpdateType type)
{
    Player *plr;
    uint64 guid;
    LfgUpdateType updateType;
    LfgQueueInfoMap::iterator itQueue;
    LfgProposal *pProposal = itProposal->second;
    pProposal->state = LFG_PROPOSAL_FAILED;

    // Mark all people that didn't answered as no accept
    if (type == LFG_UPDATETYPE_PROPOSAL_FAILED)
        for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
            if (it->second->accept < 1)
                it->second->accept = 0;

    // Inform players
    for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
    {
        plr = sObjectMgr.GetPlayer(it->first);
        if (!plr)
            continue;
        guid = plr->GetGroup() ? plr->GetGroup()->GetGUID(): plr->GetGUID();

        plr->GetSession()->SendUpdateProposal(itProposal->first, pProposal);
        // Remove members that didn't accept
        itQueue = m_QueueInfoMap.find(guid);
        if (!it->second->accept)
        {
            updateType = type;
            plr->GetLfgDungeons()->clear();
            plr->SetLfgRoles(ROLE_NONE);

            if (itQueue != m_QueueInfoMap.end())
                m_QueueInfoMap.erase(itQueue);
        }
        else                                                // Readd to queue
        {
            if (itQueue == m_QueueInfoMap.end())            // Can't readd! misssing queue info!
                updateType = LFG_UPDATETYPE_REMOVED_FROM_QUEUE;
            else
            {
                itQueue->second->joinTime = time_t(time(NULL));
                AddGuidToNewQueue(guid);
                updateType = LFG_UPDATETYPE_ADDED_TO_QUEUE;
            }
        }

        if (plr->GetGroup())
            plr->GetSession()->SendLfgUpdateParty(updateType);
        else
            plr->GetSession()->SendLfgUpdatePlayer(updateType);

    }

    for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
        delete it->second;
    pProposal->players.clear();
    pProposal->queues.clear();
    delete pProposal;
    m_Proposals.erase(itProposal);
}

/// <summary>
/// Initialize a boot kick vote
/// </summary>
/// <param name="Group *">Group</param>
/// <param name="uint32">Player low guid who inits the vote kick</param>
/// <param name="uint32">Player low guid to be kicked </param>
/// <param name="std::string">kick reason</param>
void LFGMgr::InitBoot(Group *grp, uint32 iLowGuid, uint32 vLowguid, std::string reason)
{
    if (!grp)
        return;

    LfgPlayerBoot *pBoot = new LfgPlayerBoot();
    pBoot->inProgress = true;
    pBoot->cancelTime = time_t(time(NULL)) + LFG_TIME_BOOT;
    pBoot->reason = reason;
    pBoot->victimLowGuid = vLowguid;
    pBoot->votedNeeded = GROUP_LFG_KICK_VOTES_NEEDED;
    PlayerSet players;

    uint32 pLowGuid = 0;
    for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        if (Player *plrg = itr->getSource())
        {
            pLowGuid = plrg->GetGUIDLow();
            if (pLowGuid == vLowguid)
                pBoot->votes[pLowGuid] = 0;                 // Victim auto vote NO
            else if (pLowGuid == iLowGuid)
                pBoot->votes[pLowGuid] = 1;                 // Kicker auto vote YES
            else
            {
                pBoot->votes[pLowGuid] = -1;                // Other members need to vote
                players.insert(plrg);
            }
        }
    }

    for (PlayerSet::const_iterator it = players.begin(); it != players.end(); ++it)
        (*it)->GetSession()->SendLfgBootPlayer(pBoot);

    grp->SetLfgKickActive(true);
    m_Boots[grp->GetLowGUID()] = pBoot;
}

/// <summary>
/// Update Boot info with player answer
/// </summary>
/// <param name="Player *">Player guid</param>
/// <param name="uint8">Player answer</param>
void LFGMgr::UpdateBoot(Player *plr, uint8 accept)
{
    Group *grp = plr ? plr->GetGroup() : NULL;
    if (!grp)
        return;

    uint32 bootId = grp->GetLowGUID();
    uint32 lowGuid = plr->GetGUIDLow();

    LfgPlayerBootMap::iterator itBoot = m_Boots.find(bootId);
    if (itBoot == m_Boots.end())
        return;

    LfgPlayerBoot *pBoot = itBoot->second;
    if (!pBoot)
        return;

    if (pBoot->votes[lowGuid] != -1)                           // Cheat check: Player can't vote twice
        return;

    pBoot->votes[lowGuid] = accept;

    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    for (LfgAnswerMap::const_iterator itVotes = pBoot->votes.begin(); itVotes != pBoot->votes.end(); ++itVotes)
    {
        if (itVotes->second != -1)
        {
            ++votesNum;
            if (itVotes->second == 1)
                ++agreeNum;
        }
    }

    if (agreeNum == pBoot->votedNeeded ||                   // Vote passed
        votesNum == pBoot->votes.size() ||                  // All voted but not passed
        (pBoot->votes.size() - votesNum + agreeNum) < pBoot->votedNeeded) // Vote didnt passed
    {
        // Send update info to all players
        pBoot->inProgress = false;
        for (LfgAnswerMap::const_iterator itVotes = pBoot->votes.begin(); itVotes != pBoot->votes.end(); ++itVotes)
            if (Player *plrg = sObjectMgr.GetPlayer(itVotes->first))
                if (plrg->GetGUIDLow() != pBoot->victimLowGuid)
                    plrg->GetSession()->SendLfgBootPlayer(pBoot);

        if (agreeNum == pBoot->votedNeeded)                 // Vote passed - Kick player
        {
            Player::RemoveFromGroup(grp, MAKE_NEW_GUID(pBoot->victimLowGuid, 0, HIGHGUID_PLAYER));
            if (Player *victim = sObjectMgr.GetPlayer(pBoot->victimLowGuid))
                victim->TeleportToBGEntryPoint();
            OfferContinue(grp);
            grp->SetLfgKicks(grp->GetLfgKicks() + 1);
        }
        grp->SetLfgKickActive(false);
        delete pBoot;
        m_Boots.erase(itBoot);
    }
}

/// <summary>
/// Teleports the player in or out the dungeon
/// </summary>
/// <param name="Player *">Player</param>
/// <param name="bool">Teleport out</param>
void LFGMgr::TeleportPlayer(Player *plr, bool out)
{
    if (out)
    {
        plr->TeleportToBGEntryPoint();
        return;
    }

    if (!plr->isAlive())
    {
        plr->GetSession()->SendLfgTeleportError(LFG_TELEPORTERROR_PLAYER_DEAD);
        return;
    }

    if (plr->IsFalling() || plr->hasUnitState(UNIT_STAT_JUMPING))
    {
        plr->GetSession()->SendLfgTeleportError(LFG_TELEPORTERROR_FALLING);
        return;
    }

    // TODO Add support for LFG_TELEPORTERROR_FATIGUE and LFG_TELEPORTERROR_INVALID_LOCATION
    if (Group *grp = plr->GetGroup())
        if (LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(grp->GetLfgDungeonEntry()))
            if (AreaTrigger const* at = sObjectMgr.GetMapEntranceTrigger(dungeon->map))
            {
                if (!plr->GetMap()->IsDungeon() && !plr->GetMap()->IsRaid())
                    plr->SetBattlegroundEntryPoint();
                // TODO: Teleport to group
                plr->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, at->target_Orientation);
            }
}

/// <summary>
/// Give completion reward to player
/// </summary>
/// <param name="const uint32">dungeonId</param>
/// <param name="Player *">player</param>
void LFGMgr::RewardDungeonDoneFor(const uint32 dungeonId, Player *player)
{
    Group* group = player->GetGroup();
    if (!group || !group->isLFGGroup())
        return;

    // Mark dungeon as finished
    if (!group->isLfgDungeonComplete())
        group->SetLfgStatus(LFG_STATUS_COMPLETE);

    // Clear player related lfg stuff
    uint32 rDungeonId = *player->GetLfgDungeons()->begin();
    player->GetLfgDungeons()->clear();
    player->SetLfgRoles(ROLE_NONE);
 
    // Give rewards only if its a random dungeon
    LFGDungeonEntry const *dungeon = sLFGDungeonStore.LookupEntry(dungeonId);
    if (!dungeon || dungeon->type != LFG_TYPE_RANDOM)
        return;

    // Mark random dungeon as complete
    uint8 index = player->isLfgDungeonDone(rDungeonId) ? 1 : 0;
    if (!index)
        player->SetLfgDungeonDone(rDungeonId);

    // Update achievements
    if (dungeon->difficulty == DUNGEON_DIFFICULTY_HEROIC)
        player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS, 1);

    LfgReward const* reward = GetRandomDungeonReward(rDungeonId, player->getLevel());
    if (!reward)
        return;

    Quest const* qReward = sObjectMgr.GetQuestTemplate(reward->reward[index].questId);
    if (!qReward)
        return;

    // Give rewards
    player->GetSession()->SendLfgPlayerReward(dungeon->Entry(), group->GetLfgDungeonEntry(false), index, reward, qReward);

    if (qReward->GetRewItemsCount() > 0)
    {
        for (uint32 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        {
            if (uint32 itemId = qReward->RewItemId[i])
            {
                ItemPosCountVec dest;
                if (player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, qReward->RewItemCount[i]) == EQUIP_ERR_OK)
                {
                    Item* item = player->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
                    player->SendNewItem(item, qReward->RewItemCount[i], true, false);
                }
            }
        }
    }

    // Not give XP in case already completed once repeatable quest
    uint32 XP = uint32(qReward->XPValue(player) * sWorld.getRate(RATE_XP_QUEST));

    XP += (MAXGROUPSIZE - group->GetMembersCount()) * reward->reward[index].variableXP;

    // Give player extra money if GetRewOrReqMoney > 0 and get ReqMoney if negative
    int32 moneyRew = qReward->GetRewOrReqMoney();

    if (player->getLevel() < sWorld.getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        player->GiveXP(XP, NULL);
    else
        moneyRew += int32(qReward->GetRewMoneyMaxLevel() * sWorld.getRate(RATE_DROP_MONEY));

    moneyRew += (MAXGROUPSIZE - group->GetMembersCount()) * reward->reward[index].variableMoney;

    if (moneyRew)
        player->ModifyMoney(moneyRew);
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
        if (!dungeon)
        {
            sLog.outError("LFGMgr::BuildLfgRoleCheck: Dungeon %u does not exist in dbcs", *it);
            data << uint32(0);
        }
        else
            data << uint32(dungeon->Entry());               // Dungeon
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
/// Build Party Dungeon lock status packet
/// </summary>
/// <param name="WorldPacket &">WorldPacket</param>
/// <param name="LfgLockStatusMap *">lock status map</param>
void LFGMgr::BuildPartyLockDungeonBlock(WorldPacket &data, LfgLockStatusMap *lockMap)
{
    if (!lockMap || !lockMap->size())
    {
        data << uint8(0);
        return;
    }

    data << uint8(lockMap->size());
    for (LfgLockStatusMap::const_iterator it = lockMap->begin(); it != lockMap->end(); ++it)
    {
        data << uint64(MAKE_NEW_GUID(it->first, 0, HIGHGUID_PLAYER)); // Player guid
        BuildPlayerLockDungeonBlock(data, it->second);
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
    if (!lockSet || !lockSet->size())
    {
        data << uint8(0);
        return;
    }
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
    if (!pPlayers || !dungeons)
        return NULL;

    LfgLockStatusSet *dungeonSet = NULL;
    LfgLockStatusMap *dungeonMap = new LfgLockStatusMap();
    for (PlayerSet::const_iterator itr = pPlayers->begin(); itr != pPlayers->end(); ++itr)
    {
        dungeonSet = GetPlayerLockStatusDungeons(*itr, dungeons);
        if (dungeonSet)
            (*dungeonMap)[(*itr)->GetGUIDLow()] = dungeonSet;
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
    if (!plr)
        return NULL;

    if (!dungeons)
        dungeons = GetAllDungeons();

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
    AccessRequirement const* ar;

    if (!dungeons)
        dungeons = GetAllDungeons();

    for (LfgDungeonSet::const_iterator it = dungeons->begin(); it != dungeons->end(); ++it)
    {
        dungeon = sLFGDungeonStore.LookupEntry(*it);
        if (!dungeon) // should never happen - We provide a list from sLFGDungeonStore
            continue;

        ar = sObjectMgr.GetAccessRequirement(dungeon->map, Difficulty(dungeon->difficulty));

        locktype = LFG_LOCKSTATUS_OK;
        if (dungeon->expansion > expansion)
            locktype = LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION;
        else if (sDisableMgr.IsDisabledFor(DISABLE_TYPE_MAP, dungeon->map, plr))
            locktype = LFG_LOCKSTATUS_RAID_LOCKED;
        else if (dungeon->difficulty > DUNGEON_DIFFICULTY_NORMAL && plr->GetBoundInstance(dungeon->map, Difficulty(dungeon->difficulty)))
            locktype = LFG_LOCKSTATUS_RAID_LOCKED;
        else if (dungeon->minlevel > level)
            locktype = LFG_LOCKSTATUS_TOO_LOW_LEVEL;
        else if (dungeon->maxlevel < level)
            locktype = LFG_LOCKSTATUS_TOO_HIGH_LEVEL;
        else if (locktype == LFG_LOCKSTATUS_OK && ar)
        {
            if (ar->achievement && !plr->GetAchievementMgr().HasAchieved(sAchievementStore.LookupEntry(ar->achievement)))
                locktype = LFG_LOCKSTATUS_RAID_LOCKED; // FIXME: Check the correct lock value
            else if (plr->GetTeam() == ALLIANCE && ar->quest_A && !plr->GetQuestRewardStatus(ar->quest_A))
                locktype = LFG_LOCKSTATUS_QUEST_NOT_COMPLETED;
            else if (plr->GetTeam() == HORDE && ar->quest_H && !plr->GetQuestRewardStatus(ar->quest_H))
                locktype = LFG_LOCKSTATUS_QUEST_NOT_COMPLETED;
            else
                if (ar->item)
                {
                    if (!plr->HasItemCount(ar->item, 1) && (!ar->item2 || !plr->HasItemCount(ar->item2, 1)))
                        locktype = LFG_LOCKSTATUS_MISSING_ITEM;
                }
                else if (ar->item2 && !plr->HasItemCount(ar->item2, 1))
                    locktype = LFG_LOCKSTATUS_MISSING_ITEM;
        }
        /* TODO VoA closed if WG is not under team control (LFG_LOCKSTATUS_RAID_LOCKED)
            locktype = LFG_LOCKSTATUS_TOO_LOW_GEAR_SCORE;
            locktype = LFG_LOCKSTATUS_TOO_HIGH_GEAR_SCORE;
            locktype = LFG_LOCKSTATUS_ATTUNEMENT_TOO_LOW_LEVEL;
            locktype = LFG_LOCKSTATUS_ATTUNEMENT_TOO_HIGH_LEVEL;
            locktype = LFG_LOCKSTATUS_NOT_IN_SEASON; // Need list of instances and needed season to open
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
/// <param name="uint8">Player level</param>
/// <returns>LfgReward const*</returns>
LfgReward const* LFGMgr::GetRandomDungeonReward(uint32 dungeon, uint8 level)
{
    LfgReward const* rew = NULL;
    LfgRewardMapBounds bounds = m_RewardMap.equal_range(dungeon & 0x00FFFFFF);
    uint8 index = 0;
    for (LfgRewardMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
    {
        rew = itr->second;
        // ordered properly at loading
        if (itr->second->maxLevel >= level)
            break;
    }

    return rew;
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
