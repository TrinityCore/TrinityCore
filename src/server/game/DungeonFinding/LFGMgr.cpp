/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "SharedDefines.h"
#include "DBCStores.h"

#include "DisableMgr.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "SocialMgr.h"
#include "LFGMgr.h"
#include "LFGScripts.h"

#include "Group.h"
#include "Player.h"

LFGMgr::LFGMgr(): m_update(true), m_QueueTimer(0), m_lfgProposalId(1),
m_WaitTimeAvg(-1), m_WaitTimeTank(-1), m_WaitTimeHealer(-1), m_WaitTimeDps(-1),
m_NumWaitTimeAvg(0), m_NumWaitTimeTank(0), m_NumWaitTimeHealer(0), m_NumWaitTimeDps(0)
{
    m_update = sWorld.getBoolConfig(CONFIG_DUNGEON_FINDER_ENABLE);
    if (m_update)
    {
        new LFGScripts();

        // Initialize dungeon cache
        for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
        {
            LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(i);
            if (dungeon && dungeon->type != LFG_TYPE_ZONE)
            {
                if (dungeon->type != LFG_TYPE_RANDOM)
                    m_CachedDungeonMap[dungeon->grouptype].insert(dungeon->ID);
                m_CachedDungeonMap[0].insert(dungeon->ID);
            }
        }
    }
}

LFGMgr::~LFGMgr()
{
    for (LfgRewardMap::iterator itr = m_RewardMap.begin(); itr != m_RewardMap.end(); ++itr)
        delete itr->second;

    for (LfgQueueInfoMap::iterator it = m_QueueInfoMap.begin(); it != m_QueueInfoMap.end(); ++it)
        delete it->second;

    for (LfgProposalMap::iterator it = m_Proposals.begin(); it != m_Proposals.end(); ++it)
        delete it->second;

    for (LfgPlayerBootMap::iterator it = m_Boots.begin(); it != m_Boots.end(); ++it)
        delete it->second;

    for (LfgRoleCheckMap::iterator it = m_RoleChecks.begin(); it != m_RoleChecks.end(); ++it)
        delete it->second;
}

/// Load achievement <-> encounter associations
void LFGMgr::LoadDungeonEncounters()
{
    m_EncountersByAchievement.clear();

    uint32 count = 0;
    QueryResult result = WorldDatabase.Query("SELECT achievementId, dungeonId FROM lfg_dungeon_encounters");

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
        bar.step();
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


/// Load rewards for completing dungeons
void LFGMgr::LoadRewards()
{
    for (LfgRewardMap::iterator itr = m_RewardMap.begin(); itr != m_RewardMap.end(); ++itr)
        delete itr->second;
    m_RewardMap.clear();

    uint32 count = 0;
    // ORDER BY is very important for GetRandomDungeonReward!
    QueryResult result = WorldDatabase.Query("SELECT dungeonId, maxLevel, firstQuestId, firstMoneyVar, firstXPVar, otherQuestId, otherMoneyVar, otherXPVar FROM lfg_dungeon_rewards ORDER BY dungeonId, maxLevel ASC");

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
        bar.step();
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

void LFGMgr::Update(uint32 diff)
{
    if (!m_update)
        return;

    m_update = false;
    time_t currTime = time(NULL);

    // Remove obsolete role checks
    for (LfgRoleCheckMap::iterator it = m_RoleChecks.begin(); it != m_RoleChecks.end();)
    {
        LfgRoleCheckMap::iterator itRoleCheck = it++;
        LfgRoleCheck* pRoleCheck = itRoleCheck->second;
        if (currTime < pRoleCheck->cancelTime)
            continue;
        pRoleCheck->result = LFG_ROLECHECK_MISSING_ROLE;

        for (LfgRolesMap::const_iterator itRoles = pRoleCheck->roles.begin(); itRoles != pRoleCheck->roles.end(); ++itRoles)
            if (Player* plr = sObjectMgr.GetPlayerByLowGUID(itRoles->first))
            {
                plr->GetSession()->SendLfgRoleCheckUpdate(pRoleCheck);
                plr->ClearLfgState();

                if (itRoles->first == pRoleCheck->leader)
                    plr->GetSession()->SendLfgJoinResult(LFG_JOIN_FAILED, pRoleCheck->result);
            }
        delete pRoleCheck;
        m_RoleChecks.erase(itRoleCheck);
    }

    // Remove obsolete proposals
    for (LfgProposalMap::iterator it = m_Proposals.begin(); it != m_Proposals.end();)
    {
        LfgProposalMap::iterator itRemove = it++;
        if (itRemove->second->cancelTime < currTime)
            RemoveProposal(itRemove, LFG_UPDATETYPE_PROPOSAL_FAILED);
    }

    // Remove obsolete kicks
    for (LfgPlayerBootMap::iterator it = m_Boots.begin(); it != m_Boots.end();)
    {
        LfgPlayerBootMap::iterator itBoot = it++;
        LfgPlayerBoot* pBoot = itBoot->second;
        if (pBoot->cancelTime < currTime)
        {
            pBoot->inProgress = false;
            for (LfgAnswerMap::const_iterator itVotes = pBoot->votes.begin(); itVotes != pBoot->votes.end(); ++itVotes)
                if (Player* plrg = sObjectMgr.GetPlayerByLowGUID(itVotes->first))
                    if (plrg->GetGUIDLow() != pBoot->victimLowGuid)
                        plrg->GetSession()->SendLfgBootPlayer(pBoot);
            delete pBoot;
            m_Boots.erase(itBoot);
        }
    }

    // Check if a proposal can be formed with the new groups being added
    for (LfgGuidListMap::iterator it = m_newToQueue.begin(); it != m_newToQueue.end(); ++it)
    {
        LfgGuidList& newToQueue = it->second;
        LfgGuidList& currentQueue = m_currentQueue[it->first];
        LfgGuidList firstNew;
        while (!newToQueue.empty())
        {
            sLog.outDebug("LFGMgr::Update: QueueId %u: checking [" UI64FMTD "] newToQueue(%u), currentQueue(%u)", it->first, newToQueue.front(), uint32(newToQueue.size()), uint32(currentQueue.size()));
            firstNew.push_back(newToQueue.front());
            LfgGuidList temporalList = currentQueue;
            if (LfgProposal* pProposal = FindNewGroups(firstNew, temporalList)) // Group found!
            {
                // Remove groups in the proposal from new and current queues (not from queue map)
                for (LfgGuidList::const_iterator itQueue = pProposal->queues.begin(); itQueue != pProposal->queues.end(); ++itQueue)
                {
                    currentQueue.remove(*itQueue);
                    newToQueue.remove(*itQueue);
                }
                m_Proposals[++m_lfgProposalId] = pProposal;

                uint32 lowGuid = 0;
                for (LfgProposalPlayerMap::const_iterator itPlayers = pProposal->players.begin(); itPlayers != pProposal->players.end(); ++itPlayers)
                {
                    lowGuid = itPlayers->first;
                    if (Player* plr = sObjectMgr.GetPlayerByLowGUID(itPlayers->first))
                    {
                        plr->SetLfgState(LFG_STATE_PROPOSAL);
                        if (plr->GetGroup())
                        {
                            plr->GetGroup()->SetLfgState(LFG_STATE_PROPOSAL);
                            plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_PROPOSAL_BEGIN, plr->GetLfgDungeons(), plr->GetLfgComment());
                        }
                        else
                            plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_PROPOSAL_BEGIN, plr->GetLfgDungeons(), plr->GetLfgComment());
                        plr->GetSession()->SendLfgUpdateProposal(m_lfgProposalId, pProposal);
                    }
                }

                if (pProposal->state == LFG_PROPOSAL_SUCCESS)
                    UpdateProposal(m_lfgProposalId, lowGuid, true);
            }
            else
            {
                currentQueue.push_back(newToQueue.front());// Group not found, add this group to the queue.
                newToQueue.pop_front();
            }
            firstNew.clear();
        }
    }

    // Update all players status queue info
    if (m_QueueTimer > LFG_QUEUEUPDATE_INTERVAL)
    {
        m_QueueTimer = 0;
        time_t currTime = time(NULL);
        for (LfgQueueInfoMap::const_iterator itQueue = m_QueueInfoMap.begin(); itQueue != m_QueueInfoMap.end(); ++itQueue)
        {
            LfgQueueInfo* queue = itQueue->second;
            if (!queue)
            {
                sLog.outError("LFGMgr::Update: [" UI64FMTD "] queued with null queue info!", itQueue->first);
                continue;
            }
            uint32 dungeonId = (*queue->dungeons.begin());
            uint32 queuedTime = uint32(currTime - queue->joinTime);
            uint8 role = ROLE_NONE;
            for (LfgRolesMap::const_iterator itPlayer = queue->roles.begin(); itPlayer != queue->roles.end(); ++itPlayer)
                role |= itPlayer->second;
            role &= ~ROLE_LEADER;

            int32 waitTime = -1;
            switch(role)
            {
                case ROLE_NONE:                             // Should not happen - just in case
                    waitTime = -1;
                    break;
                case ROLE_TANK:
                    waitTime = m_WaitTimeTank;
                    break;
                case ROLE_HEALER:
                    waitTime = m_WaitTimeHealer;
                    break;
                case ROLE_DAMAGE:
                    waitTime = m_WaitTimeDps;
                    break;
                default:
                    waitTime = m_WaitTimeAvg;
                    break;
            }

            for (LfgRolesMap::const_iterator itPlayer = queue->roles.begin(); itPlayer != queue->roles.end(); ++itPlayer)
                if (Player* plr = sObjectMgr.GetPlayerByLowGUID(itPlayer->first))
                    plr->GetSession()->SendLfgQueueStatus(dungeonId, waitTime, m_WaitTimeAvg, m_WaitTimeTank, m_WaitTimeHealer, m_WaitTimeDps, queuedTime, queue->tanks, queue->healers, queue->dps);
        }
    }
    else
        m_QueueTimer += diff;
    m_update = true;
}

/**
   Add a guid to the queue of guids to be added to main queue. It guid its already
   in queue does nothing. If this function is called guid is not in the main queue
   (No need to check it here)

   @param[in]     guid Player or group guid to add to queue
   @param[in]     queueId Queue Id to add player/group to
*/
void LFGMgr::AddToQueue(uint64& guid, uint8 queueId)
{
    if (sWorld.getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP))
        queueId = 0;

    LfgGuidList& list = m_newToQueue[queueId];
    if (std::find(list.begin(), list.end(), guid) != list.end())
        sLog.outDebug("LFGMgr::AddToQueue: [" UI64FMTD "] already in new queue. ignoring", guid);
    else
    {
        list.push_back(guid);
        sLog.outDebug("LFGMgr::AddToQueue: [" UI64FMTD "] added to m_newToQueue (size: %u)", guid, uint32(list.size()));
    }
}

/**
   Removes a guid from the main and new queues.

   @param[in]     guid Player or group guid to add to queue
   @return true if guid was found in main queue.
*/
bool LFGMgr::RemoveFromQueue(uint64& guid)
{
    for (LfgGuidListMap::iterator it = m_currentQueue.begin(); it != m_currentQueue.end(); ++it)
        it->second.remove(guid);

    for (LfgGuidListMap::iterator it = m_newToQueue.begin(); it != m_newToQueue.end(); ++it)
        it->second.remove(guid);

    RemoveFromCompatibles(guid);

    LfgQueueInfoMap::iterator it = m_QueueInfoMap.find(guid);
    if (it != m_QueueInfoMap.end())
    {
        delete it->second;
        m_QueueInfoMap.erase(it);
        sLog.outDebug("LFGMgr::RemoveFromQueue: [" UI64FMTD "] removed", guid);
        return true;
    }
    else
    {
        sLog.outDebug("LFGMgr::RemoveFromQueue: [" UI64FMTD "] not in queue", guid);
        return false;
    }
    
}

/**
    Adds the player/group to lfg queue. If player is in a group then it is the leader
    of the group tying to join the group. Join conditions are checked before adding
    to the new queue.

   @param[in]     plr Player trying to join (or leader of group trying to join)
   @param[in]     roles Player selected roles
   @param[in]     dungeons Dungeons the player/group is applying for
   @param[in]     comment Player selected comment
*/
void LFGMgr::Join(Player* plr, uint8 roles, LfgDungeonSet& dungeons, std::string& comment)
{
    if (!plr || !plr->GetSession() || !dungeons.size())
      return;

    Group* grp = plr->GetGroup();
    uint64 guid = plr->GetGUID();
    uint64 gguid = grp ? grp->GetGUID() : guid;
    LfgJoinResult result = LFG_JOIN_OK;
    PlayerSet players;
    uint32 rDungeonId = 0;
    bool isContinue = grp && grp->isLFGGroup() && grp->GetLfgState() != LFG_STATE_FINISHED_DUNGEON;

    // Do not allow to change dungeon in the middle of a current dungeon
    if (isContinue)
    {
        dungeons.clear();
        dungeons.insert(grp->GetLfgDungeonEntry());
    }

    // Already in queue?
    LfgQueueInfoMap::iterator itQueue = m_QueueInfoMap.find(gguid);
    if (itQueue != m_QueueInfoMap.end())
    {
        bool sameDungeons = true;
        for (LfgDungeonSet::const_iterator it = plr->GetLfgDungeons()->begin(); it != plr->GetLfgDungeons()->end() && sameDungeons; ++it)
            if (dungeons.find(*it) == dungeons.end())
                sameDungeons = false;

        if (sameDungeons)                                   // Joining the same dungeons -- Send OK
        {
            plr->GetSession()->SendLfgJoinResult(LFG_JOIN_OK);
            if (grp)
            {
                for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
                    if (itr->getSource() && itr->getSource()->GetSession())
                        itr->getSource()->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_ADDED_TO_QUEUE, &dungeons, comment);
            }
        }
        else if (!isContinue)                              // Different dungeons and it's not an offer to continue
        {
            // Different dungeons and it's not a LfgGroup in the middle of a dungeon that need more people
            Leave(plr, grp);
            Join(plr, roles, dungeons, comment);
        }
        return;
    }

    // Check player or group member restrictions
    if (plr->InBattleground() || plr->InArena() || plr->InBattlegroundQueue())
        result = LFG_JOIN_USING_BG_SYSTEM;
    else if (plr->HasAura(LFG_SPELL_DUNGEON_DESERTER))
        result = LFG_JOIN_DESERTER;
    else if (plr->HasAura(LFG_SPELL_DUNGEON_COOLDOWN))
        result = LFG_JOIN_RANDOM_COOLDOWN;
    else if (!dungeons.size())
        result = LFG_JOIN_NOT_MEET_REQS;
    else if (grp)
    {
        if (grp->GetMembersCount() > MAXGROUPSIZE)
            result = LFG_JOIN_TOO_MUCH_MEMBERS;
        else
        {
            uint8 memberCount = 0;
            for (GroupReference* itr = grp->GetFirstMember(); itr != NULL && result == LFG_JOIN_OK; itr = itr->next())
            {
                if (Player* plrg = itr->getSource())
                {
                    if (plrg->HasAura(LFG_SPELL_DUNGEON_DESERTER))
                        result = LFG_JOIN_PARTY_DESERTER;
                    else if (plrg->HasAura(LFG_SPELL_DUNGEON_COOLDOWN))
                        result = LFG_JOIN_PARTY_RANDOM_COOLDOWN;
                    else if (plrg->InBattleground() || plrg->InArena() || plrg->InBattlegroundQueue())
                        result = LFG_JOIN_USING_BG_SYSTEM;
                    ++memberCount;
                    players.insert(plrg);
                }
            }
            if (memberCount != grp->GetMembersCount())
                result = LFG_JOIN_DISCONNECTED;
        }
    }
    else
        players.insert(plr);

    // Check if all dungeons are valid
    bool isRaid = false;
    if (result == LFG_JOIN_OK)
    {
        bool isDungeon = false;
        for (LfgDungeonSet::const_iterator it = dungeons.begin(); it != dungeons.end() && result == LFG_JOIN_OK; ++it)
        {
            switch(GetDungeonType(*it))
            {
                case LFG_TYPE_RANDOM:
                    if (dungeons.size() > 1)               // Only allow 1 random dungeon
                        result = LFG_JOIN_DUNGEON_INVALID;
                    else
                        rDungeonId = (*dungeons.begin());
                    // No break on purpose (Random can only be dungeon or heroic dungeon)
                case LFG_TYPE_HEROIC:
                case LFG_TYPE_DUNGEON:
                    if (isRaid)
                        result = LFG_JOIN_MIXED_RAID_DUNGEON;
                    isDungeon = true;
                    break;
                case LFG_TYPE_RAID:
                    if (isDungeon)
                        result = LFG_JOIN_MIXED_RAID_DUNGEON;
                    isRaid = true;
                    break;
                default:
                    result = LFG_JOIN_DUNGEON_INVALID;
                    break;
            }
        }

        // Expand random dungeons and check restrictions        
        if (rDungeonId)
            dungeons = GetDungeonsByRandom(rDungeonId);

        LfgLockStatusMap* lockStatusMap = CheckCompatibleDungeons(dungeons, players);
        if (!dungeons.size())
        {
            sLog.outDebug("LFGMgr::Join: [" UI64FMTD "] joining with %u members. result: LFG_JOIN_PARTY_NOT_MEET_REQS", guid, uint8(players.size()));
            plr->GetSession()->SendLfgJoinResult(LFG_JOIN_PARTY_NOT_MEET_REQS, 0, lockStatusMap);
        }
        if (lockStatusMap)
        {
            for (LfgLockStatusMap::iterator it = lockStatusMap->begin(); it != lockStatusMap->end(); ++it)
                delete it->second;
            delete lockStatusMap;
        }
        if (!dungeons.size())
            return;
    }

    // Can't join. Send result
    if (result != LFG_JOIN_OK)
    {
        sLog.outDebug("LFGMgr::Join: [" UI64FMTD "] joining with %u members. result: %u", guid, grp ? grp->GetMembersCount() : 1, result);
        plr->GetSession()->SendLfgJoinResult(result);
        return;
    }

    // FIXME - Raid browser not supported yet
    if (isRaid)
    {
        sLog.outDebug("LFGMgr::Join: [" UI64FMTD "] trying to join raid browser and it's disabled.", guid);
        return;
    }

    plr->SetLfgComment(comment);
    plr->SetLfgRoles(roles);

    if (grp)                                               // Begin rolecheck
    {
        // Create new rolecheck
        LfgRoleCheck* pRoleCheck = new LfgRoleCheck();
        pRoleCheck->cancelTime = time_t(time(NULL)) + LFG_TIME_ROLECHECK;
        pRoleCheck->result = LFG_ROLECHECK_INITIALITING;
        pRoleCheck->leader = plr->GetGUIDLow();
        pRoleCheck->dungeons = dungeons;
        pRoleCheck->rDungeonId = rDungeonId;
        m_RoleChecks[grp->GetLowGUID()] = pRoleCheck;

        if (rDungeonId)
        {
            dungeons.clear();
            dungeons.insert(rDungeonId);
        }

        grp->SetLfgState(LFG_STATE_ROLECHECK);
        // Send update to player
        for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            if (Player* plrg = itr->getSource())
            {
                plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_JOIN_PROPOSAL, &dungeons, comment);
                plrg->SetLfgState(LFG_STATE_ROLECHECK);
                if (!isContinue)
                {
                    plrg->GetLfgDungeons()->clear();
                    for (LfgDungeonSet::const_iterator it = dungeons.begin(); it != dungeons.end(); ++it)
                        plrg->GetLfgDungeons()->insert(*it);
                }
                pRoleCheck->roles[plrg->GetGUIDLow()] = 0;
            }
        }
        // Update leader role
        UpdateRoleCheck(grp, plr, true);
    }
    else                                                   // Add player to queue
    {
        // Send update to player
        plr->GetSession()->SendLfgJoinResult(LFG_JOIN_OK);
        plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_JOIN_PROPOSAL, &dungeons, comment);
        plr->SetLfgState(LFG_STATE_QUEUED);
        if (!isContinue)
        {
            plr->GetLfgDungeons()->clear();
            if (rDungeonId)
                plr->GetLfgDungeons()->insert(rDungeonId);
            else
                for (LfgDungeonSet::const_iterator it = dungeons.begin(); it != dungeons.end(); ++it)
                    plr->GetLfgDungeons()->insert(*it);
        }

        // Queue player
        LfgQueueInfo* pqInfo = new LfgQueueInfo();
        pqInfo->joinTime = time_t(time(NULL));
        pqInfo->roles[plr->GetGUIDLow()] = plr->GetLfgRoles();
        pqInfo->dungeons = dungeons;
        uint8 roles = plr->GetLfgRoles();
        if (roles & ROLE_TANK)
            --pqInfo->tanks;
        else if (roles & ROLE_HEALER)
            --pqInfo->healers;
        else
            --pqInfo->dps;

        m_QueueInfoMap[guid] = pqInfo;
        AddToQueue(guid, uint8(plr->GetTeam()));
    }
    sLog.outDebug("LFGMgr::Join: [" UI64FMTD "] joined with %u members. dungeons: %u", guid, grp ? grp->GetMembersCount() : 1, uint8(dungeons.size()));
}

/**
    Leaves Dungeon System. Player/Group is removed from queue, rolechecks, proposals
    or votekicks. Player or group needs to be not NULL and using Dungeon System

   @param[in]     plr Player trying to leave (can be NULL)
   @param[in]     grp Group trying to leave (default NULL)
*/
void LFGMgr::Leave(Player* plr, Group* grp /* = NULL*/)
{
    if (!plr && !grp)
        return;

    uint64 guid = 0;
    LfgState state;

    if (grp)
    {
        guid = grp->GetGUID();
        state = grp->GetLfgState();
    }
    else
    {
        guid = plr->GetGUID();
        state = plr->GetLfgState();
    }

    sLog.outDebug("LFGMgr::Leave: [" UI64FMTD "]", guid);
    switch(state)
    {
        case LFG_STATE_QUEUED:
            RemoveFromQueue(guid);
            if (grp)
            {
                grp->RestoreLfgState();
                for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
                    if (Player* plrg = itr->getSource())
                    {
                        plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
                        plrg->ClearLfgState();
                    }
            }
            else
            {
                plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
                plr->ClearLfgState();
            }
            break;
        case LFG_STATE_ROLECHECK:
            if (grp)
                UpdateRoleCheck(grp);                      // No player to update role = LFG_ROLECHECK_ABORTED
            break;
        case LFG_STATE_PROPOSAL:
        {
            // Remove from Proposals
            LfgProposalMap::iterator it = m_Proposals.begin();
            uint32 lowguid = plr ? plr->GetGUIDLow() : GUID_LOPART(grp->GetLeaderGUID());
            while (it != m_Proposals.end())
            {
                LfgProposalPlayerMap::iterator itPlayer = it->second->players.find(lowguid);
                if (itPlayer != it->second->players.end())
                {
                    // Mark the player/leader of group who left as didn't accept the proposal
                    itPlayer->second->accept = LFG_ANSWER_DENY;
                    break;
                }
                ++it;
            }

            // Remove from queue - if proposal is found, RemoveProposal will call RemoveFromQueue
            if (it != m_Proposals.end())
                RemoveProposal(it, LFG_UPDATETYPE_PROPOSAL_DECLINED);
            break;
        }
        default:
            break;
    }
}

/**
   Sends the leader of a group the offer to continue popup

   @param[in]     grp Group to send offer to
*/
void LFGMgr::OfferContinue(Group* grp)
{
    Player* leader = grp ? sObjectMgr.GetPlayer(grp->GetLeaderGUID()) : NULL;
    if (leader)
        leader->GetSession()->SendLfgOfferContinue(grp->GetLfgDungeonEntry(false));
}

/**
   Checks que main queue to try to form a Lfg group. Returns first match found (if any)

   @param[in]     check List of guids trying to match with other groups
   @param[in]     all List of all other guids in main queue to match against
   @return Pointer to proposal, if match is found
*/
LfgProposal* LFGMgr::FindNewGroups(LfgGuidList& check, LfgGuidList& all)
{
    sLog.outDebug("LFGMgr::FindNewGroup: (%s) - all(%s)", ConcatenateGuids(check).c_str(), ConcatenateGuids(all).c_str());

    LfgProposal* pProposal = NULL;
    if (!check.size() || check.size() > MAXGROUPSIZE || !CheckCompatibility(check, pProposal))
        return NULL;

    // Try to match with queued groups
    while (!pProposal && all.size() > 0)
    {
        check.push_back(all.front());        
        all.pop_front();
        pProposal = FindNewGroups(check, all);
        check.pop_back();
    }
    return pProposal;
}

/**
   Check compatibilities between groups

   @param[in]     check List of guids to check compatibilities
   @param[out]    pProposal Proposal found if groups are compatibles and Match
   @return true if group are compatibles
*/
bool LFGMgr::CheckCompatibility(LfgGuidList check, LfgProposal*& pProposal)
{
    if (pProposal)                                         // Do not check anything if we already have a proposal
        return false;

    std::string strGuids = ConcatenateGuids(check);

    if (check.size() > MAXGROUPSIZE || !check.size())
    {
        sLog.outDebug("LFGMgr::CheckCompatibility: (%s): Size wrong - Not compatibles", strGuids.c_str());
        return false;
    }

    if (check.size() == 1 && IS_PLAYER_GUID(check.front())) // Player joining dungeon... compatible
        return true;

    // Previously cached?
    LfgAnswer answer = GetCompatibles(strGuids);
    if (answer != LFG_ANSWER_PENDING)
    {
        sLog.outDebug("LFGMgr::CheckCompatibility: (%s) compatibles (cached): %d", strGuids.c_str(), answer);
        return bool(answer);
    }
    
    // Check all but new compatiblitity
    if (check.size() > 2)
    {
        uint64 frontGuid = check.front();
        check.pop_front();

        // Check all-but-new compatibilities (New,A,B,C,D) --> check(A,B,C,D)
        if (!CheckCompatibility(check, pProposal))          // Group not compatible
        {
            sLog.outDebug("LFGMgr::CheckCompatibility: (%s) not compatibles (%s not compatibles)", strGuids.c_str(), ConcatenateGuids(check).c_str());
            SetCompatibles(strGuids, false);
            return false;
        }
        check.push_front(frontGuid);
        // all-but-new compatibles, now check with new
    }

    uint8 numPlayers = 0;
    uint8 numLfgGroups = 0;
    uint32 groupLowGuid = 0;
    LfgQueueInfoMap pqInfoMap;
    for (LfgGuidList::const_iterator it = check.begin(); it != check.end() && numLfgGroups < 2 && numPlayers <= MAXGROUPSIZE; ++it)
    {
        uint64 guid = (*it);
        LfgQueueInfoMap::iterator itQueue = m_QueueInfoMap.find(guid);
        if (itQueue == m_QueueInfoMap.end())
        {
            sLog.outError("LFGMgr::CheckCompatibility: [" UI64FMTD "] is not queued but listed as queued!", (*it));
            RemoveFromQueue(guid);
            return false;
        }
        pqInfoMap[guid] = itQueue->second;
        numPlayers += itQueue->second->roles.size();

        if (IS_GROUP(guid))
        {
            uint32 lowGuid = GUID_LOPART(guid);
            if (Group* grp = sObjectMgr.GetGroupByGUID(lowGuid))
                if (grp->isLFGGroup())
                {
                    if (!numLfgGroups)
                        groupLowGuid = lowGuid;
                    ++numLfgGroups;
                }
        }
    }

    if (check.size() == 1 && numPlayers != MAXGROUPSIZE)   // Single group with less than MAXGROUPSIZE - Compatibles
        return true;

    // Do not match - groups already in a lfgDungeon or too much players
    if (numLfgGroups > 1 || numPlayers > MAXGROUPSIZE)
    {
        SetCompatibles(strGuids, false);
        if (numLfgGroups > 1)
            sLog.outDebug("LFGMgr::CheckCompatibility: (%s) More than one Lfggroup (%u)", strGuids.c_str(), numLfgGroups);
        else
            sLog.outDebug("LFGMgr::CheckCompatibility: (%s) Too much players (%u)", strGuids.c_str(), numPlayers);
        return false;
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

    if (rolesMap.size() != numPlayers)                     // Player in multiples queues!
        return false;

    PlayerSet players;
    for (LfgRolesMap::const_iterator it = rolesMap.begin(); it != rolesMap.end(); ++it)
    {
        Player* plr = sObjectMgr.GetPlayerByLowGUID(it->first);
        if (!plr)
            sLog.outDebug("LFGMgr::CheckCompatibility: (%s) Warning! %u offline! Marking as not compatibles!", strGuids.c_str(), it->first);
        else
        {
            for (PlayerSet::const_iterator itPlayer = players.begin(); itPlayer != players.end() && plr; ++itPlayer)
            {
                // Do not form a group with ignoring candidates
                if (plr->GetSocial()->HasIgnore((*itPlayer)->GetGUIDLow()) || (*itPlayer)->GetSocial()->HasIgnore(plr->GetGUIDLow()))
                {
                    sLog.outDebug("LFGMgr::CheckCompatibility: (%s) Players [" UI64FMTD "] and [" UI64FMTD "] ignoring", strGuids.c_str(), (*itPlayer)->GetGUID(), plr->GetGUID());
                    plr = NULL;
                }
            }
            if (plr)
                players.insert(plr);
        }
    }

    // if we dont have the same ammount of players then we have self ignoring candidates or different faction groups
    // otherwise check if roles are compatible
    if (players.size() != numPlayers || !CheckGroupRoles(rolesMap))
    {
        if (players.size() == numPlayers)
            sLog.outDebug("LFGMgr::CheckCompatibility: (%s) Roles not compatible", strGuids.c_str());
        SetCompatibles(strGuids, false);
        return false;
    }

    // ----- Selected Dungeon checks -----
    // Check if there are any compatible dungeon from the selected dungeons
    LfgDungeonSet compatibleDungeons;

    LfgQueueInfoMap::const_iterator itFirst = pqInfoMap.begin();
    for (LfgDungeonSet::const_iterator itDungeon = itFirst->second->dungeons.begin(); itDungeon != itFirst->second->dungeons.end(); ++itDungeon)
    {
        LfgQueueInfoMap::const_iterator itOther = itFirst;
        ++itOther;
        while(itOther != pqInfoMap.end() && itOther->second->dungeons.find(*itDungeon) != itOther->second->dungeons.end())
            ++itOther;

        if (itOther == pqInfoMap.end())
            compatibleDungeons.insert(*itDungeon);
    }
    CheckCompatibleDungeons(compatibleDungeons, players, false);

    if (!compatibleDungeons.size())
    {
        SetCompatibles(strGuids, false);
        return false;
    }
    SetCompatibles(strGuids, true);

    // ----- Group is compatible, if we have MAXGROUPSIZE members then match is found
    if (numPlayers != MAXGROUPSIZE)
    {
        sLog.outDebug("LFGMgr::CheckCompatibility: (%s) Compatibles but not match. Players(%u)", strGuids.c_str(), numPlayers);
        return true;
    }
    sLog.outDebug("LFGMgr::CheckCompatibility: (%s) MATCH! Group formed", strGuids.c_str());

    // GROUP FORMED!
    // TODO - Improve algorithm to select proper group based on Item Level
    // Do not match bad tank and bad healer on same group

    // Select a random dungeon from the compatible list
    // TODO - Select the dungeon based on group item Level, not just random
    LfgDungeonSet::const_iterator itDungeon = compatibleDungeons.begin();
    for (uint8 i = 0; i < urand(0, compatibleDungeons.size() - 1); ++i)
        ++itDungeon;

    // Create a new proposal
    pProposal = new LfgProposal(*itDungeon);
    pProposal->cancelTime = time_t(time(NULL)) + LFG_TIME_PROPOSAL;
    pProposal->state = LFG_PROPOSAL_INITIATING;
    pProposal->queues = check;
    pProposal->groupLowGuid = groupLowGuid;

    // Assign new roles to players and assign new leader
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
        uint32 lowGuid = (*itPlayers)->GetGUIDLow();
        LfgProposalPlayer* ppPlayer = new LfgProposalPlayer();
        if (Group* grp = (*itPlayers)->GetGroup())
        {
            ppPlayer->groupLowGuid = grp->GetLowGUID();
            if (grp->isLFGGroup()) // Player from existing group, autoaccept
            {
                ppPlayer->accept = LFG_ANSWER_AGREE;
                ++numAccept;
            }
        }
        ppPlayer->role = rolesMap[lowGuid];
        pProposal->players[lowGuid] = ppPlayer;
    }
    if (numAccept == MAXGROUPSIZE)
        pProposal->state = LFG_PROPOSAL_SUCCESS;

    return true;
}

/**
   Update the Role check info with the player selected role.

   @param[in]     grp Group to update rolecheck
   @param[in]     plr Player to update role (NULL = Rolecheck Failed)
   @param[in]     newRoleCheck Determines if its a new rolecheck (Default false)
*/
void LFGMgr::UpdateRoleCheck(Group* grp, Player* plr /* = NULL*/, bool newRoleCheck /* = false */)
{
    if (!grp)
        return;

    LfgRolesMap check_roles;
    LfgRoleCheckMap::iterator itRoleCheck = m_RoleChecks.find(grp->GetLowGUID());
    if (itRoleCheck == m_RoleChecks.end())
        return;

    LfgRoleCheck* pRoleCheck = itRoleCheck->second;
    if (!plr)
        pRoleCheck->result = LFG_ROLECHECK_ABORTED;
    else if (plr->GetLfgRoles() < ROLE_TANK)               // Player selected no role.
        pRoleCheck->result = LFG_ROLECHECK_NO_ROLE;
    else
    {
        pRoleCheck->roles[plr->GetGUIDLow()] = plr->GetLfgRoles();

        // Check if all players have selected a role
        LfgRolesMap::const_iterator itRoles = pRoleCheck->roles.begin();
        while (itRoles != pRoleCheck->roles.end() && itRoles->second != ROLE_NONE)
            ++itRoles;

        if (itRoles == pRoleCheck->roles.end())
        {
            // use temporal var to check roles, CheckGroupRoles modifies the roles
            check_roles = pRoleCheck->roles;
            pRoleCheck->result = CheckGroupRoles(check_roles) ? LFG_ROLECHECK_FINISHED : LFG_ROLECHECK_WRONG_ROLES;
        }
    }

    uint8 team = 0;
    LfgDungeonSet dungeons;
    if (pRoleCheck->rDungeonId)
        dungeons.insert(pRoleCheck->rDungeonId);
    else
        dungeons = pRoleCheck->dungeons;

    for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* plrg = itr->getSource();
        if (!plrg)
            continue;

        team = plrg->GetTeam();
        WorldSession* session = plrg->GetSession();
        if (!newRoleCheck && plr)
            session->SendLfgRoleChosen(plr->GetGUID(), plr->GetLfgRoles());
        session->SendLfgRoleCheckUpdate(pRoleCheck);

        switch(pRoleCheck->result)
        {
            case LFG_ROLECHECK_INITIALITING:
                continue;
            case LFG_ROLECHECK_FINISHED:
                plrg->SetLfgState(LFG_STATE_QUEUED);
                session->SendLfgUpdateParty(LFG_UPDATETYPE_ADDED_TO_QUEUE, &dungeons, plrg->GetLfgComment());
                break;
            default:
                if (grp->GetLeaderGUID() == plrg->GetGUID())
                    session->SendLfgJoinResult(LFG_JOIN_FAILED, pRoleCheck->result);
                session->SendLfgUpdateParty(LFG_UPDATETYPE_ROLECHECK_FAILED);
                plrg->ClearLfgState();
                break;
        }
    }

    if (pRoleCheck->result == LFG_ROLECHECK_FINISHED)
    {
        grp->SetLfgState(LFG_STATE_QUEUED);
        LfgQueueInfo* pqInfo = new LfgQueueInfo();
        pqInfo->joinTime = time_t(time(NULL));
        pqInfo->roles = pRoleCheck->roles;
        pqInfo->dungeons = pRoleCheck->dungeons;

        // Set queue roles needed - As we are using check_roles will not have more that 1 tank, 1 healer, 3 dps
        for (LfgRolesMap::const_iterator it = check_roles.begin(); it != check_roles.end(); ++it)
        {
            uint8 roles = it->second;
            if (roles & ROLE_TANK)
                --pqInfo->tanks;
            else if (roles & ROLE_HEALER)
                --pqInfo->healers;
            else
                --pqInfo->dps;
        }

        uint64 guid = grp->GetGUID();
        m_QueueInfoMap[guid] = pqInfo;
        AddToQueue(guid, team);
    }

    if (pRoleCheck->result != LFG_ROLECHECK_INITIALITING)
    {
        if (pRoleCheck->result != LFG_ROLECHECK_FINISHED)
            grp->RestoreLfgState();
        delete pRoleCheck;
        m_RoleChecks.erase(itRoleCheck);
    }
}

/**
   Remove from cached compatible dungeons any entry that contains the given guid

   @param[in]     guid Guid to remove from compatible cache
*/
void LFGMgr::RemoveFromCompatibles(uint64 guid)
{
    std::stringstream out;
    out << guid;
    std::string strGuid = out.str();

    sLog.outDebug("LFGMgr::RemoveFromCompatibles: Removing [" UI64FMTD "]", guid);
    for (LfgCompatibleMap::iterator itNext = m_CompatibleMap.begin(); itNext != m_CompatibleMap.end();)
    {
        LfgCompatibleMap::iterator it = itNext++;
        if (it->first.find(strGuid) != std::string::npos)  // Found, remove it
            m_CompatibleMap.erase(it);
    }
}

/**
   Stores the compatibility of a list of guids

   @param[in]     key String concatenation of guids (| used as separator)
   @param[in]     compatibles Compatibles or not
*/
void LFGMgr::SetCompatibles(std::string key, bool compatibles)
{
    m_CompatibleMap[key] = LfgAnswer(compatibles);
}

/**
   Get the compatibility of a group of guids

   @param[in]     key String concatenation of guids (| used as separator)
   @return 1 (Compatibles), 0 (Not compatibles), -1 (Not set)
*/
LfgAnswer LFGMgr::GetCompatibles(std::string key)
{
    LfgAnswer answer = LFG_ANSWER_PENDING;
    LfgCompatibleMap::iterator it = m_CompatibleMap.find(key);
    if (it != m_CompatibleMap.end())
        answer = it->second;

    return answer;
}

/**
   Given a list of dungeons remove the dungeons players have restrictions.

   @param[in,out] dungeons Dungeons to check restrictions
   @param[in]     players Set of players to check their dungeon restrictions
   @param[in]     returnLockMap Determines when to return a function value (Default true)
   @return Map of players Lock status info of given dungeons
*/
LfgLockStatusMap* LFGMgr::CheckCompatibleDungeons(LfgDungeonSet& dungeons, PlayerSet& players, bool returnLockMap /* = true */)
{
    if (!dungeons.size())
        return NULL;

    LfgLockStatusMap* pLockDungeons = GetGroupLockStatusDungeons(players, dungeons, false);
    if (pLockDungeons) // Found dungeons not compatible, remove them from the set
    {
        for (LfgLockStatusMap::const_iterator itLockMap = pLockDungeons->begin(); itLockMap != pLockDungeons->end() && dungeons.size(); ++itLockMap)
        {
            for(LfgLockStatusSet::const_iterator itLockSet = itLockMap->second->begin(); itLockSet != itLockMap->second->end(); ++itLockSet)
            {
                LfgDungeonSet::iterator itDungeon = dungeons.find((*itLockSet)->dungeon);
                if (itDungeon != dungeons.end())
                     dungeons.erase(itDungeon);
            }
            if (!returnLockMap)
                delete itLockMap->second;
        }
        if (!returnLockMap)
        {
            delete pLockDungeons;
            return NULL;
        }
    }
    return pLockDungeons;
}

/**
   Check if a group can be formed with the given group roles

   @param[in]     groles Map of roles to check
   @param[in]     removeLeaderFlag Determines if we have to remove leader flag (only used first call, Default = true)
   @return True if roles are compatible
*/
bool LFGMgr::CheckGroupRoles(LfgRolesMap& groles, bool removeLeaderFlag /*= true*/)
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
        if (it->second == ROLE_NONE)
            return false;

        if (it->second & ROLE_TANK)
        {
            if (it->second != ROLE_TANK)
            {
                it->second -= ROLE_TANK;
                if (CheckGroupRoles(groles, false))
                    return true;
                it->second += ROLE_TANK;
            }
            else if (tank == LFG_TANKS_NEEDED)
                return false;
            else
                tank++;
        }

        if (it->second & ROLE_HEALER)
        {
            if (it->second != ROLE_HEALER)
            {
                it->second -= ROLE_HEALER;
                if (CheckGroupRoles(groles, false))
                    return true;
                it->second += ROLE_HEALER;
            }
            else if (healer == LFG_HEALERS_NEEDED)
                return false;
            else
                healer++;
        }

        if (it->second & ROLE_DAMAGE)
        {
            if (it->second != ROLE_DAMAGE)
            {
                it->second -= ROLE_DAMAGE;
                if (CheckGroupRoles(groles, false))
                    return true;
                it->second += ROLE_DAMAGE;
            }
            else if (damage == LFG_DPS_NEEDED)
                return false;
            else
                damage++;
        }
    }
    return (tank + healer + damage) == uint8(groles.size());
}

/**
   Update Proposal info with player answer

   @param[in]     proposalId Proposal id to be updated
   @param[in]     lowguid Player low guid to update answer
   @param[in]     accept Player answer
*/
void LFGMgr::UpdateProposal(uint32 proposalId, uint32 lowGuid, bool accept)
{
    // Check if the proposal exists
    LfgProposalMap::iterator itProposal = m_Proposals.find(proposalId);
    if (itProposal == m_Proposals.end())
        return;
    LfgProposal* pProposal = itProposal->second;

    // Check if proposal have the current player
    LfgProposalPlayerMap::iterator itProposalPlayer = pProposal->players.find(lowGuid);
    if (itProposalPlayer == pProposal->players.end())
        return;
    LfgProposalPlayer* ppPlayer = itProposalPlayer->second;

    ppPlayer->accept = LfgAnswer(accept);
    sLog.outDebug("LFGMgr::UpdateProposal: Player [" UI64FMTD "] of proposal %u selected: %u", MAKE_NEW_GUID(lowGuid, 0, HIGHGUID_PLAYER), proposalId, accept);
    if (!accept)
    {
        RemoveProposal(itProposal, LFG_UPDATETYPE_PROPOSAL_DECLINED);
        return;
    }

    LfgPlayerList players;
    LfgPlayerList playersToTeleport;

    // check if all have answered and reorder players (leader first)
    bool allAnswered = true;
    for (LfgProposalPlayerMap::const_iterator itPlayers = pProposal->players.begin(); itPlayers != pProposal->players.end(); ++itPlayers)
    {
        if (Player* plr = sObjectMgr.GetPlayerByLowGUID(itPlayers->first))
        {
            if (itPlayers->first == pProposal->leaderLowGuid)
                players.push_front(plr);
            else
                players.push_back(plr);

            // Only teleport new players
            Group* grp = plr->GetGroup();
            if (!grp || !grp->isLFGGroup() || grp->GetLfgState() == LFG_STATE_FINISHED_DUNGEON) 
                playersToTeleport.push_back(plr);
        }

        if (itPlayers->second->accept != LFG_ANSWER_AGREE)   // No answer (-1) or not accepted (0)
            allAnswered = false;
    }

    if (!allAnswered)
    {
        for (LfgPlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
            (*it)->GetSession()->SendLfgUpdateProposal(proposalId, pProposal);
    }
    else
    {
        bool sendUpdate = pProposal->state != LFG_PROPOSAL_SUCCESS;
        pProposal->state = LFG_PROPOSAL_SUCCESS;
        time_t joinTime = time_t(time(NULL));
        std::map<uint64, int32> waitTimesMap;
        // Save wait times before redoing groups
        for (LfgPlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
        {
            LfgProposalPlayer* pPlayer = pProposal->players[(*it)->GetGUIDLow()];
            uint32 lowgroupguid = (*it)->GetGroup() ? (*it)->GetGroup()->GetLowGUID() : 0;
            if (pPlayer->groupLowGuid != lowgroupguid)
                sLog.outError("LFGMgr::UpdateProposal: [" UI64FMTD "] group mismatch: actual (%u) - queued (%u)", (*it)->GetGUID(), lowgroupguid, pPlayer->groupLowGuid);

            uint64 guid = pPlayer->groupLowGuid ? MAKE_NEW_GUID(pPlayer->groupLowGuid, 0, HIGHGUID_GROUP) : (*it)->GetGUID();
            LfgQueueInfoMap::iterator itQueue = m_QueueInfoMap.find(guid);
            if (itQueue == m_QueueInfoMap.end())
            {
                sLog.outError("LFGMgr::UpdateProposal: Queue info for guid [" UI64FMTD "] not found!", guid);
                waitTimesMap[(*it)->GetGUID()] = -1;
            }
            else
                waitTimesMap[(*it)->GetGUID()] = int32(joinTime - itQueue->second->joinTime);
        }

        // Create a new group (if needed)
        Group* grp = pProposal->groupLowGuid ? sObjectMgr.GetGroupByGUID(pProposal->groupLowGuid) : NULL;
        for (LfgPlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
        {
            Player* plr = (*it);
            Group* group = plr->GetGroup();
            if (sendUpdate)
                plr->GetSession()->SendLfgUpdateProposal(proposalId, pProposal);
            if (group)
            {
                plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_GROUP_FOUND);
                if (group != grp)
                    plr->RemoveFromGroup();
            }
            else
                plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_GROUP_FOUND);

            if (!grp)
            {
                grp = new Group();
                grp->Create(plr->GetGUID(), plr->GetName());
                grp->ConvertToLFG();
                grp->SetLfgState(LFG_STATE_PROPOSAL);
                sObjectMgr.AddGroup(grp);
            }
            else if (group != grp)
                grp->AddMember(plr->GetGUID(), plr->GetName());

            // Update timers
            uint8 role = plr->GetLfgRoles();
            role &= ~ROLE_LEADER;
            switch(role)
            {
                case ROLE_DAMAGE:
                    m_WaitTimeDps = int32((m_WaitTimeDps * m_NumWaitTimeDps + waitTimesMap[plr->GetGUID()]) / ++m_NumWaitTimeDps);
                    break;
                case ROLE_HEALER:
                    m_WaitTimeHealer = int32((m_WaitTimeHealer * m_NumWaitTimeHealer + waitTimesMap[plr->GetGUID()]) / ++m_NumWaitTimeHealer);
                    break;
                case ROLE_TANK:
                    m_WaitTimeTank = int32((m_WaitTimeTank * m_NumWaitTimeTank + waitTimesMap[plr->GetGUID()]) / ++m_NumWaitTimeTank);
                    break;
                default:
                    m_WaitTimeAvg = int32((m_WaitTimeAvg * m_NumWaitTimeAvg + waitTimesMap[plr->GetGUID()]) / ++m_NumWaitTimeAvg);
                    break;
            }
            grp->SetLfgRoles(plr->GetGUID(), pProposal->players[plr->GetGUIDLow()]->role);
            plr->SetLfgState(LFG_STATE_DUNGEON);
        }

        // Set the dungeon difficulty
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(pProposal->dungeonId);
        ASSERT(dungeon);
        grp->SetDungeonDifficulty(Difficulty(dungeon->difficulty));
        grp->SetLfgDungeonEntry(dungeon->Entry());
        grp->SetLfgState(LFG_STATE_DUNGEON);

        // Remove players/groups from Queue
        for (LfgGuidList::const_iterator it = pProposal->queues.begin(); it != pProposal->queues.end(); ++it)
        {
            uint64 guid = (*it);
            RemoveFromQueue(guid);
        }

        // Teleport Player
        for (LfgPlayerList::const_iterator it = playersToTeleport.begin(); it != playersToTeleport.end(); ++it)
            TeleportPlayer(*it, false);

        // Update group info
        grp->SendUpdate();

        delete pProposal;
        m_Proposals.erase(itProposal);
    }
}

/**
   Remove a proposal from the pool, remove the group that didn't accept (if needed) and readd the other members to the queue

   @param[in]     itProposal Iterator to the proposal to remove
   @param[in]     type Type of removal (LFG_UPDATETYPE_PROPOSAL_FAILED, LFG_UPDATETYPE_PROPOSAL_DECLINED)
*/
void LFGMgr::RemoveProposal(LfgProposalMap::iterator itProposal, LfgUpdateType type)
{
    LfgProposal* pProposal = itProposal->second;
    pProposal->state = LFG_PROPOSAL_FAILED;

    sLog.outDebug("LFGMgr::RemoveProposal: Proposal %u, state FAILED, UpdateType %u", itProposal->first, type);
    // Mark all people that didn't answered as no accept
    if (type == LFG_UPDATETYPE_PROPOSAL_FAILED)
        for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
            if (it->second->accept == LFG_ANSWER_PENDING)
                it->second->accept = LFG_ANSWER_DENY;

    // Mark players/groups to be removed
    LfgGuidSet toRemove;
    for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
    {
        if (it->second->accept == LFG_ANSWER_AGREE)
            continue;

        uint64 guid = it->second->groupLowGuid ? MAKE_NEW_GUID(it->second->groupLowGuid, 0, HIGHGUID_GROUP) : MAKE_NEW_GUID(it->first, 0, HIGHGUID_PLAYER);
        // Player didn't accept or still pending when no secs left
        if (it->second->accept == LFG_ANSWER_DENY || type == LFG_UPDATETYPE_PROPOSAL_FAILED)
        {
            it->second->accept = LFG_ANSWER_DENY;
            toRemove.insert(guid);
        }
    }

    uint8 team = 0;
    // Notify players
    for (LfgProposalPlayerMap::const_iterator it = pProposal->players.begin(); it != pProposal->players.end(); ++it)
    {
        Player* plr = sObjectMgr.GetPlayerByLowGUID(it->first);
        if (!plr)
            continue;

        team = uint8(plr->GetTeam());
        plr->GetSession()->SendLfgUpdateProposal(itProposal->first, pProposal);

        Group* grp = plr->GetGroup();
        uint64 guid = plr->GetGUID();
        uint64 gguid = it->second->groupLowGuid ? MAKE_NEW_GUID(it->second->groupLowGuid, 0, HIGHGUID_GROUP) : guid;

        if (toRemove.find(gguid) != toRemove.end())         // Didn't accept or in same group that someone that didn't accept
        {
            LfgUpdateType updateType;
            if (it->second->accept == LFG_ANSWER_DENY)
            {
                updateType = type;
                sLog.outDebug("LFGMgr::RemoveProposal: [" UI64FMTD "] didn't accept. Removing from queue and compatible cache", guid);
            }
            else
            {
                updateType = LFG_UPDATETYPE_REMOVED_FROM_QUEUE;
                sLog.outDebug("LFGMgr::RemoveProposal: [" UI64FMTD "] in same group that someone that didn't accept. Removing from queue and compatible cache", guid);
            }
            plr->ClearLfgState();
            if (grp)
            {
                grp->RestoreLfgState();
                plr->GetSession()->SendLfgUpdateParty(updateType);
            }
            else
                plr->GetSession()->SendLfgUpdatePlayer(updateType);
        }
        else
        {
            sLog.outDebug("LFGMgr::RemoveProposal: Readding [" UI64FMTD "] to queue.", guid);
            plr->SetLfgState(LFG_STATE_QUEUED);
            if (grp)
            {
                grp->SetLfgState(LFG_STATE_QUEUED);
                plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_ADDED_TO_QUEUE, plr->GetLfgDungeons(), plr->GetLfgComment());
            }
            else
                plr->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_ADDED_TO_QUEUE, plr->GetLfgDungeons(), plr->GetLfgComment());
        }
    }

    // Remove players/groups from queue
    for (LfgGuidSet::const_iterator it = toRemove.begin(); it != toRemove.end(); ++it)
    {
        uint64 guid = *it;
        RemoveFromQueue(guid);
        pProposal->queues.remove(guid);
    }

    // Readd to queue
    for (LfgGuidList::const_iterator it = pProposal->queues.begin(); it != pProposal->queues.end(); ++it)
    {
        uint64 guid = *it;
        AddToQueue(guid, team);
    }

    delete pProposal;
    m_Proposals.erase(itProposal);
}

/**
   Initialize a boot kick vote

   @param[in]     grp Group the vote kicks belongs to
   @param[in]     kicker Kicker low guid
   @param[in]     victim Victim low guid
   @param[in]     reason Kick reason
*/
void LFGMgr::InitBoot(Group* grp, uint32 kicker, uint32 victim, std::string reason)
{
    if (!grp)
        return;

    grp->SetLfgState(LFG_STATE_BOOT);

    LfgPlayerBoot* pBoot = new LfgPlayerBoot();
    pBoot->inProgress = true;
    pBoot->cancelTime = time_t(time(NULL)) + LFG_TIME_BOOT;
    pBoot->reason = reason;
    pBoot->victimLowGuid = victim;
    pBoot->votedNeeded = GROUP_LFG_KICK_VOTES_NEEDED;
    PlayerSet players;

    // Set votes
    for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        if (Player* plrg = itr->getSource())
        {
            plrg->SetLfgState(LFG_STATE_BOOT);
            uint32 pLowGuid = plrg->GetGUIDLow();
            if (pLowGuid == victim)
                pBoot->votes[pLowGuid] = LFG_ANSWER_DENY;  // Victim auto vote NO
            else if (pLowGuid == kicker)
                pBoot->votes[pLowGuid] = LFG_ANSWER_AGREE; // Kicker auto vote YES
            else
            {
                pBoot->votes[pLowGuid] = LFG_ANSWER_PENDING; // Other members need to vote
                players.insert(plrg);
            }
        }
    }

    // Notify players
    for (PlayerSet::const_iterator it = players.begin(); it != players.end(); ++it)
        (*it)->GetSession()->SendLfgBootPlayer(pBoot);

    m_Boots[grp->GetLowGUID()] = pBoot;
}

/**
   Update Boot info with player answer

   @param[in]     plr Player who has answered
   @param[in]     accept player answer
*/
void LFGMgr::UpdateBoot(Player* plr, bool accept)
{
    Group* grp = plr ? plr->GetGroup() : NULL;
    if (!grp)
        return;

    uint32 bootId = grp->GetLowGUID();
    uint32 lowGuid = plr->GetGUIDLow();

    LfgPlayerBootMap::iterator itBoot = m_Boots.find(bootId);
    if (itBoot == m_Boots.end())
        return;

    LfgPlayerBoot* pBoot = itBoot->second;
    if (!pBoot)
        return;

    if (pBoot->votes[lowGuid] != LFG_ANSWER_PENDING)       // Cheat check: Player can't vote twice
        return;

    pBoot->votes[lowGuid] = LfgAnswer(accept);

    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    for (LfgAnswerMap::const_iterator itVotes = pBoot->votes.begin(); itVotes != pBoot->votes.end(); ++itVotes)
    {
        if (itVotes->second != LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (itVotes->second == LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }

    if (agreeNum == pBoot->votedNeeded ||                  // Vote passed
        votesNum == pBoot->votes.size() ||                 // All voted but not passed
        (pBoot->votes.size() - votesNum + agreeNum) < pBoot->votedNeeded) // Vote didnt passed
    {
        // Send update info to all players
        pBoot->inProgress = false;
        for (LfgAnswerMap::const_iterator itVotes = pBoot->votes.begin(); itVotes != pBoot->votes.end(); ++itVotes)
            if (Player* plrg = sObjectMgr.GetPlayerByLowGUID(itVotes->first))
                if (plrg->GetGUIDLow() != pBoot->victimLowGuid)
                {
                    plrg->SetLfgState(LFG_STATE_DUNGEON);
                    plrg->GetSession()->SendLfgBootPlayer(pBoot);
                }

        grp->SetLfgState(LFG_STATE_DUNGEON);
        if (agreeNum == pBoot->votedNeeded)                // Vote passed - Kick player
        {
            Player::RemoveFromGroup(grp, MAKE_NEW_GUID(pBoot->victimLowGuid, 0, HIGHGUID_PLAYER));
            if (Player* victim = sObjectMgr.GetPlayerByLowGUID(pBoot->victimLowGuid))
            {
                TeleportPlayer(victim, true, false);
                victim->SetLfgState(LFG_STATE_NONE);
            }
            OfferContinue(grp);
            grp->SetLfgKicks(grp->GetLfgKicks() + 1);
            
        }
        delete pBoot;
        m_Boots.erase(itBoot);
    }
}

/**
   Teleports the player in or out the dungeon

   @param[in]     plr Player to teleport
   @param[in]     out Teleport out (true) or in (false)
   @param[in]     fromOpcode Function called from opcode handlers? (Default false)
*/
void LFGMgr::TeleportPlayer(Player* plr, bool out, bool fromOpcode /*= false*/)
{
    sLog.outDebug("LFGMgr::TeleportPlayer: [" UI64FMTD "] is being teleported %s", plr->GetGUID(), out ? "out" : "in");
    if (out)
    {
        plr->RemoveAurasDueToSpell(LFG_SPELL_LUCK_OF_THE_DRAW);
        plr->TeleportToBGEntryPoint();
        return;
    }

    // TODO Add support for LFG_TELEPORTERROR_FATIGUE
    LfgTeleportError error = LFG_TELEPORTERROR_OK;
    Group* grp = plr->GetGroup();

    if (!grp || !grp->isLFGGroup())                        // should never happen, but just in case...
        error = LFG_TELEPORTERROR_INVALID_LOCATION;
    else if (!plr->isAlive())
        error = LFG_TELEPORTERROR_PLAYER_DEAD;
    else if (plr->IsFalling() || plr->hasUnitState(UNIT_STAT_JUMPING))
        error = LFG_TELEPORTERROR_FALLING;
    else
    {
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(grp->GetLfgDungeonEntry());

        if (!dungeon)
            error = LFG_TELEPORTERROR_INVALID_LOCATION;
        else if (plr->GetMapId() != uint32(dungeon->map))  // Do not teleport players in dungeon to the entrance
        {
            uint32 mapid = 0;
            float x = 0;
            float y = 0;
            float z = 0;
            float orientation = 0;

            if (!fromOpcode)
            {
                
                // Select a player inside to be teleported to
                for (GroupReference* itr = grp->GetFirstMember(); itr != NULL && !mapid; itr = itr->next())
                {
                    Player* plrg = itr->getSource();
                    if (plrg && plrg != plr && plrg->GetMapId() == uint32(dungeon->map))
                    {
                        mapid = plrg->GetMapId();
                        x = plrg->GetPositionX();
                        y = plrg->GetPositionY();
                        z = plrg->GetPositionZ();
                        orientation = plrg->GetOrientation();
                    }
                }
            }

            if (!mapid)
            {
                AreaTrigger const* at = sObjectMgr.GetMapEntranceTrigger(dungeon->map);
                if (!at)
                {
                    sLog.outError("LfgMgr::TeleportPlayer: Failed to teleport [" UI64FMTD "]: No areatrigger found for map: %u difficulty: %u", plr->GetGUID(), dungeon->map, dungeon->difficulty);
                    error = LFG_TELEPORTERROR_INVALID_LOCATION;
                }
                else
                {
                    mapid = at->target_mapId;
                    x = at->target_X;
                    y = at->target_Y;
                    z = at->target_Z;
                    orientation = at->target_Orientation;
                }
            }

            if (error == LFG_TELEPORTERROR_OK)
            {
                if (!plr->GetMap()->IsDungeon() && !plr->GetMap()->IsRaid())
                    plr->SetBattlegroundEntryPoint();

                if (plr->isInFlight())
                {
                    plr->GetMotionMaster()->MovementExpired();
                    plr->CleanupAfterTaxiFlight();
                }

                if (plr->TeleportTo(mapid, x, y, z, orientation))
                    // FIXME - HACK - this should be done by teleport, when teleporting far
                    plr->RemoveAurasByType(SPELL_AURA_MOUNTED);
                else
                {
                    error = LFG_TELEPORTERROR_INVALID_LOCATION;
                    sLog.outError("LfgMgr::TeleportPlayer: Failed to teleport [" UI64FMTD "] to map %u: ", plr->GetGUID(), mapid);
                }
            }
        }
    }

    if (error != LFG_TELEPORTERROR_OK)
        plr->GetSession()->SendLfgTeleportError(error);
}

/**
   Give completion reward to player

   @param[in]     dungeonId Dungeonid (Obsolete)
   @param[in]     plr Player to reward
*/
void LFGMgr::RewardDungeonDoneFor(const uint32 dungeonId, Player* player)
{
    Group* group = player->GetGroup();
    if (!group || !group->isLFGGroup())
    {
        sLog.outDebug("LFGMgr::RewardDungeonDoneFor: [" UI64FMTD "] is not in a group or not a LFGGroup. Ignoring", player->GetGUID());
        return;
    }

    if (player->GetLfgState() == LFG_STATE_FINISHED_DUNGEON)
    {
        sLog.outDebug("LFGMgr::RewardDungeonDoneFor: [" UI64FMTD "] Already rewarded player. Ignoring", player->GetGUID());
        return;
    }

    // Mark dungeon as finished
    group->SetLfgState(LFG_STATE_FINISHED_DUNGEON);

    // Clear player related lfg stuff
    uint32 rDungeonId = (*player->GetLfgDungeons()->begin());
    player->ClearLfgState();
    player->SetLfgState(LFG_STATE_FINISHED_DUNGEON);

    // Give rewards only if its a random dungeon
    LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(rDungeonId);
    if (!dungeon || dungeon->type != LFG_TYPE_RANDOM)
    {
        sLog.outDebug("LFGMgr::RewardDungeonDoneFor: [" UI64FMTD "] dungeon %u is not random. Queued for %u dungeons", player->GetGUID(), rDungeonId, uint8(player->GetLfgDungeons()->size()));
        return;
    }

    // Update achievements
    if (dungeon->difficulty == DUNGEON_DIFFICULTY_HEROIC)
        player->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS, 1);

    LfgReward const* reward = GetRandomDungeonReward(rDungeonId, player->getLevel());
    if (!reward)
        return;

    uint8 index = 0;
    Quest const* qReward = sObjectMgr.GetQuestTemplate(reward->reward[index].questId);
    if (!qReward)
        return;

    // if we can take the quest, means that we haven't done this kind of "run", IE: First Heroic Random of Day.
    if (player->CanRewardQuest(qReward,false))
        player->RewardQuest(qReward,0,NULL,false);
    else
    {
        index = 1;
        qReward = sObjectMgr.GetQuestTemplate(reward->reward[index].questId);
        if (!qReward)
            return;
        // we give reward without informing client (retail does this)
        player->RewardQuest(qReward,0,NULL,false);
    }

    // Give rewards
    sLog.outDebug("LFGMgr::RewardDungeonDoneFor: [" UI64FMTD "] done dungeon %u,%s previously done.", player->GetGUID(), group->GetLfgDungeonEntry(), index > 0 ? " " : " not");
    player->GetSession()->SendLfgPlayerReward(dungeon->Entry(), group->GetLfgDungeonEntry(false), index, reward, qReward);
}

// --------------------------------------------------------------------------//
// Auxiliar Functions
// --------------------------------------------------------------------------//

/**
   Get all Group members list of all dungeons that can't be done and reason
   leader excluded as the list given is he list he can do

   @param[in]     plr Players to check group lock status
   @returns Map of player's group dungeon Lock status
*/
LfgLockStatusMap* LFGMgr::GetPartyLockStatusDungeons(Player* plr)
{
    Group* grp = plr->GetGroup();
    if (!grp)
        return NULL;

    PlayerSet players;
    for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* plrg = itr->getSource();
        if (plrg && plrg != plr)
            players.insert(plrg);
    }

    LfgDungeonSet allDungeons = GetDungeonsByRandom(0);
    return GetGroupLockStatusDungeons(players, allDungeons, true);
}

/**
   Get list of all dungeons player can't do and reasons

   @param[in]     plr Players to check dungeon lock status
   @returns Set of player's dungeon Lock status
*/
LfgLockStatusSet* LFGMgr::GetPlayerLockStatusDungeons(Player* plr)
{
    LfgDungeonSet allDungeons = GetDungeonsByRandom(0);
    return GetPlayerLockStatusDungeons(plr, allDungeons, true);
}

/**
   Given a group get the dungeons that can't be done and reason

   @param[in]     players Players to check lock status
   @param[in]     dungeons Dungeons to check
   @param[in]     useEntry Use dungeon entry (true) or id (false)
   @returns Map of player's dungeon Lock status
*/
LfgLockStatusMap* LFGMgr::GetGroupLockStatusDungeons(PlayerSet& players, LfgDungeonSet& dungeons, bool useEntry)
{
    LfgLockStatusMap* dungeonMap = new LfgLockStatusMap();
    for (PlayerSet::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        if (LfgLockStatusSet* dungeonSet = GetPlayerLockStatusDungeons(*itr, dungeons, useEntry))
            (*dungeonMap)[(*itr)->GetGUIDLow()] = dungeonSet;

    if (!dungeonMap->size())
    {
        delete dungeonMap;
        dungeonMap = NULL;
    }
    return dungeonMap;
}

/**
   Given a list of dungeon return the list of dungeons player can't do and reasons

   @param[in]     plr Players to check dungeon lock status
   @param[in]     dungeons Dungeons to check (Default = NULL, means check all dungeons)
   @param[in]     useEntry Use dungeon entry (true) or id (false)
   @returns Set of player's dungeon Lock status
*/
LfgLockStatusSet* LFGMgr::GetPlayerLockStatusDungeons(Player* plr, LfgDungeonSet& dungeons, bool useEntry)
{
    LfgLockStatusSet* list = new LfgLockStatusSet();
    uint8 level = plr->getLevel();
    uint8 expansion = plr->GetSession()->Expansion();

    for (LfgDungeonSet::const_iterator it = dungeons.begin(); it != dungeons.end(); ++it)
    {
        LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(*it);
        if (!dungeon) // should never happen - We provide a list from sLFGDungeonStore
            continue;

        AccessRequirement const* ar = sObjectMgr.GetAccessRequirement(dungeon->map, Difficulty(dungeon->difficulty));

        LfgLockStatusType locktype = LFG_LOCKSTATUS_OK;
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
                locktype = LFG_LOCKSTATUS_RAID_LOCKED;       // FIXME: Check the correct lock value
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
            LfgLockStatus* lockstatus = new LfgLockStatus();
            lockstatus->dungeon = useEntry ? dungeon->Entry(): dungeon->ID;
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

/**
   Get the dungeon list that can be done given a random dungeon entry.

   @param[in]     randomdungeon Random dungeon id (if value = 0 will return all dungeons)
   @returns Set of dungeons that can be done.
*/
LfgDungeonSet LFGMgr::GetDungeonsByRandom(uint32 randomdungeon)
{
    LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(randomdungeon);
    uint8 groupType = dungeon ? dungeon->grouptype : 0;
    return m_CachedDungeonMap[groupType];                  // Return a copy
}

/**
   Get the reward of a given random dungeon at a certain level

   @param[in]     dungeon dungeon id
   @param[in]     level Player level
   @returns Reward
*/
LfgReward const* LFGMgr::GetRandomDungeonReward(uint32 dungeon, uint8 level)
{
    LfgReward const* rew = NULL;
    LfgRewardMapBounds bounds = m_RewardMap.equal_range(dungeon & 0x00FFFFFF);
    for (LfgRewardMap::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
    {
        rew = itr->second;
        // ordered properly at loading
        if (itr->second->maxLevel >= level)
            break;
    }

    return rew;
}

/**
   Given a Dungeon id returns the dungeon Type

   @param[in]     dungeon dungeon id
   @returns Dungeon type
*/
LfgType LFGMgr::GetDungeonType(uint32 dungeonId)
{
    LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(dungeonId);
    if (!dungeon)
        return LFG_TYPE_NONE;

    return LfgType(dungeon->type);
}

/**
   Given a Achievement id returns the related dungeon id

   @param[in]     achievementId Achievement id
   @returns dungeon id
*/
uint32 LFGMgr::GetDungeonIdForAchievement(uint32 achievementId)
{
    std::map<uint32, uint32>::iterator itr = m_EncountersByAchievement.find(achievementId);
    if (itr != m_EncountersByAchievement.end())
        return itr->second;

    return 0;
};

/**
   Given a list of guids returns the concatenation using | as delimiter

   @param[in]     check list of guids
   @returns Concatenated string
*/
std::string LFGMgr::ConcatenateGuids(LfgGuidList check)
{
    if (check.empty())
        return "";

    std::ostringstream o;
    LfgGuidList::const_iterator it = check.begin();
    o << (*it);
    for (++it; it != check.end(); ++it)
        o << "|" << (*it);
    return o.str();
}
