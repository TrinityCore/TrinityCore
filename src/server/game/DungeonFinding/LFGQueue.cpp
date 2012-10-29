/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ObjectDefines.h"
#include "Containers.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "Group.h"
#include "LFGQueue.h"
#include "LFGMgr.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "World.h"
#include "GroupMgr.h"

/**
   Given a list of guids returns the concatenation using | as delimiter

   @param[in]     check list of guids
   @returns Concatenated string
*/
std::string ConcatenateGuids(LfgGuidList const& check)
{
    if (check.empty())
        return "";

    // need the guids in order to avoid duplicates
    LfgGuidSet guids(check.begin(), check.end());

    std::ostringstream o;

    LfgGuidSet::const_iterator it = guids.begin();
    o << (*it);
    for (++it; it != guids.end(); ++it)
        o << '|' << (*it);

    return o.str();
}

char const * GetCompatibleString(LfgCompatibility compatibles)
{
    switch (compatibles)
    {
        case LFG_COMPATIBILITY_PENDING:
            return "Pending";
        case LFG_COMPATIBLES_BAD_STATES:
            return "Compatibles (Bad States)";
        case LFG_COMPATIBLES_MATCH:
            return "Match";
        case LFG_COMPATIBLES_WITH_LESS_PLAYERS:
            return "Compatibles (Not enough players)";
        case LFG_INCOMPATIBLES_HAS_IGNORES:
            return "Has ignores";
        case LFG_INCOMPATIBLES_MULTIPLE_LFG_GROUPS:
            return "Multiple Lfg Groups";
        case LFG_INCOMPATIBLES_NO_DUNGEONS:
            return "Incompatible dungeons";
        case LFG_INCOMPATIBLES_NO_ROLES:
            return "Incompatible roles";
        case LFG_INCOMPATIBLES_TOO_MUCH_PLAYERS:
            return "Too much players";
        case LFG_INCOMPATIBLES_WRONG_GROUP_SIZE:
            return "Wrong group size";
        default:
            return "Unknown";
    }
}

void LfgQueue::AddToQueue(uint64 guid)
{
    LfgQueueDataMap::iterator itQueue = m_QueueDataMap.find(guid);
    if (itQueue == m_QueueDataMap.end())
    {
        sLog->outError(LOG_FILTER_LFG, "LfgQueue::AddToQueue: Queue data not found for [" UI64FMTD "]", guid);
        return;
    }

    AddToNewQueue(guid);
}

void LfgQueue::RemoveFromQueue(uint64 guid)
{
    RemoveFromNewQueue(guid);
    RemoveFromCurrentQueue(guid);
    RemoveFromCompatibles(guid);
    RemoveQueueData(guid);
}

void LfgQueue::AddToNewQueue(uint64 guid)
{
    m_newToQueue.push_back(guid);
}

void LfgQueue::RemoveFromNewQueue(uint64 guid)
{
    m_newToQueue.remove(guid);
}

void LfgQueue::AddToCurrentQueue(uint64 guid)
{
    m_currentQueue.push_back(guid);
}

void LfgQueue::RemoveFromCurrentQueue(uint64 guid)
{
    m_currentQueue.remove(guid);
}

void LfgQueue::AddQueueData(uint64 guid, time_t joinTime, const LfgDungeonSet &dungeons, const LfgRolesMap &rolesMap)
{
    m_QueueDataMap[guid] = LfgQueueData(joinTime, dungeons, rolesMap);
    AddToQueue(guid);
}

void LfgQueue::RemoveQueueData(uint64 guid)
{
    LfgQueueDataMap::iterator it = m_QueueDataMap.find(guid);
    if (it != m_QueueDataMap.end())
        m_QueueDataMap.erase(it);
}

void LfgQueue::UpdateWaitTimeAvg(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = m_waitTimesAvg[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

void LfgQueue::UpdateWaitTimeTank(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = m_waitTimesTank[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

void LfgQueue::UpdateWaitTimeHealer(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = m_waitTimesHealer[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

void LfgQueue::UpdateWaitTimeDps(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = m_waitTimesDps[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

/**
   Remove from cached compatible dungeons any entry that contains the given guid

   @param[in]     guid Guid to remove from compatible cache
*/
void LfgQueue::RemoveFromCompatibles(uint64 guid)
{
    std::stringstream out;
    out << guid;
    std::string strGuid = out.str();

    sLog->outDebug(LOG_FILTER_LFG, "LfgQueue::RemoveFromCompatibles: Removing [" UI64FMTD "]", guid);
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
   @param[in]     compatibles type of compatibility
*/
void LfgQueue::SetCompatibles(const std::string &key, LfgCompatibility compatibles)
{
    m_CompatibleMap[key] = compatibles;
}

/**
   Get the compatibility of a group of guids

   @param[in]     key String concatenation of guids (| used as separator)
   @return LfgCompatibility type of compatibility
*/
LfgCompatibility LfgQueue::GetCompatibles(std::string const& key)
{
    LfgCompatibleMap::iterator it = m_CompatibleMap.find(key);
    if (it != m_CompatibleMap.end())
        return it->second;

    return LFG_COMPATIBILITY_PENDING;
}

uint8 LfgQueue::FindGroups()
{
    uint8 proposals = 0;
    LfgGuidList firstNew;
    while (!m_newToQueue.empty())
    {
        uint64 frontguid = m_newToQueue.front();
        sLog->outDebug(LOG_FILTER_LFG, "LfgQueue::FindGroups: checking [" UI64FMTD "] newToQueue(%u), currentQueue(%u)", frontguid, uint32(m_newToQueue.size()), uint32(m_currentQueue.size()));
        firstNew.clear();
        firstNew.push_back(frontguid);
        RemoveFromNewQueue(frontguid);

        LfgGuidList temporalList = m_currentQueue;
        LfgCompatibility compatibles = FindNewGroups(firstNew, temporalList);

        if (compatibles == LFG_COMPATIBLES_MATCH)
            ++proposals;
        else
            AddToCurrentQueue(frontguid);                  // Lfg group not found, add this group to the queue.
    }
    return proposals;
}

/**
   Checks que main queue to try to form a Lfg group. Returns first match found (if any)

   @param[in]     check List of guids trying to match with other groups
   @param[in]     all List of all other guids in main queue to match against
   @return LfgCompatibility type of compatibility between groups
*/
LfgCompatibility LfgQueue::FindNewGroups(LfgGuidList& check, LfgGuidList& all)
{
    std::string strGuids = ConcatenateGuids(check);
    LfgCompatibility compatibles = GetCompatibles(strGuids);

    sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::FindNewGroup: (%s): %s - all(%s)", strGuids.c_str(), GetCompatibleString(compatibles), ConcatenateGuids(all).c_str());
    if (compatibles == LFG_COMPATIBILITY_PENDING) // Not previously cached, calculate
        compatibles = CheckCompatibility(check);

    if (compatibles == LFG_COMPATIBLES_BAD_STATES && sLFGMgr->AllQueued(check))
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::FindNewGroup: (%s) compatibles (cached) changed from bad states to match", strGuids.c_str());
        SetCompatibles(strGuids, LFG_COMPATIBLES_MATCH);
        return LFG_COMPATIBLES_MATCH;
    }

    if (compatibles != LFG_COMPATIBLES_WITH_LESS_PLAYERS)
        return compatibles;

    // Try to match with queued groups
    while (!all.empty())
    {
        check.push_back(all.front());
        all.pop_front();
        LfgCompatibility subcompatibility = FindNewGroups(check, all);
        if (subcompatibility == LFG_COMPATIBLES_MATCH)
            return LFG_COMPATIBLES_MATCH;
        check.pop_back();
    }
    return compatibles;
}

/**
   Check compatibilities between groups. If group is Matched proposal will be created

   @param[in]     check List of guids to check compatibilities
   @return LfgCompatibility type of compatibility
*/
LfgCompatibility LfgQueue::CheckCompatibility(LfgGuidList check)
{
    std::string strGuids = ConcatenateGuids(check);
    LfgProposal proposal;
    LfgDungeonSet proposalDungeons;
    LfgGroupsMap proposalGroups;
    LfgRolesMap proposalRoles;

    // Check for correct size
    if (check.size() > MAXGROUPSIZE || check.empty())
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s): Size wrong - Not compatibles", strGuids.c_str());
        return LFG_INCOMPATIBLES_WRONG_GROUP_SIZE;
    }

    // Player joining alone always compatible
    if (check.size() == 1 && IS_PLAYER_GUID(check.front()))
        return LFG_COMPATIBLES_WITH_LESS_PLAYERS;

    // Check all-but-new compatiblitity
    if (check.size() > 2)
    {
        uint64 frontGuid = check.front();
        check.pop_front();

        // Check all-but-new compatibilities (New, A, B, C, D) --> check(A, B, C, D)
        LfgCompatibility child_compatibles = CheckCompatibility(check);
        if (child_compatibles < LFG_COMPATIBLES_WITH_LESS_PLAYERS) // Group not compatible
        {
            sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) child %s not compatibles", strGuids.c_str(), ConcatenateGuids(check).c_str());
            SetCompatibles(strGuids, child_compatibles);
            return child_compatibles;
        }
        check.push_front(frontGuid);
    }

    // Check if more than one LFG group and number of players joining
    uint8 numPlayers = 0;
    uint8 numLfgGroups = 0;
    for (LfgGuidList::const_iterator it = check.begin(); it != check.end() && numLfgGroups < 2 && numPlayers <= MAXGROUPSIZE; ++it)
    {
        uint64 guid = (*it);
        LfgQueueDataMap::iterator itQueue = m_QueueDataMap.find(guid);
        if (itQueue == m_QueueDataMap.end())
        {
            sLog->outError(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: [" UI64FMTD "] is not queued but listed as queued!", guid);
            RemoveFromQueue(guid);
            return LFG_COMPATIBILITY_PENDING;
        }

        // Store group so we don't need to call Mgr to get it later (if it's player group will be 0 otherwise would have joined as group)
        for (LfgRolesMap::const_iterator it2 = itQueue->second.roles.begin(); it2 != itQueue->second.roles.end(); ++it2)
            proposalGroups[it2->first] = IS_GROUP(itQueue->first) ? itQueue->first : 0;

        numPlayers += itQueue->second.roles.size();

        if (sLFGMgr->IsLfgGroup(guid))
        {
            if (!numLfgGroups)
                proposal.group = guid;
            ++numLfgGroups;
        }
    }

    // Group with less that MAXGROUPSIZE members always compatible
    if (check.size() == 1 && numPlayers != MAXGROUPSIZE)
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) sigle group. Compatibles", strGuids.c_str());
        return LFG_COMPATIBLES_WITH_LESS_PLAYERS;
    }

    if (numLfgGroups > 1)
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) More than one Lfggroup (%u)", strGuids.c_str(), numLfgGroups);
        SetCompatibles(strGuids, LFG_INCOMPATIBLES_MULTIPLE_LFG_GROUPS);
        return LFG_INCOMPATIBLES_MULTIPLE_LFG_GROUPS;
    }

    if (numPlayers > MAXGROUPSIZE)
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) Too much players (%u)", strGuids.c_str(), numPlayers);
        SetCompatibles(strGuids, LFG_INCOMPATIBLES_TOO_MUCH_PLAYERS);
        return LFG_INCOMPATIBLES_TOO_MUCH_PLAYERS;
    }

    // If it's single group no need to check for duplicate players, ignores, bad roles or bad dungeons as it's been checked before joining
    if (check.size() > 1)
    {
        for (LfgGuidList::const_iterator it = check.begin(); it != check.end(); ++it)
        {
            const LfgRolesMap &roles = m_QueueDataMap[(*it)].roles;
            for (LfgRolesMap::const_iterator itRoles = roles.begin(); itRoles != roles.end(); ++itRoles)
            {
                LfgRolesMap::const_iterator itPlayer;
                for (itPlayer = proposalRoles.begin(); itPlayer != proposalRoles.end(); ++itPlayer)
                {
                    if (itRoles->first == itPlayer->first)
                        sLog->outError(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: ERROR! Player multiple times in queue! [" UI64FMTD "]", itRoles->first);
                    else if (sLFGMgr->HasIgnore(itRoles->first, itPlayer->first))
                        break;
                }
                if (itPlayer == proposalRoles.end())
                    proposalRoles[itRoles->first] = itRoles->second;
            }
        }

        if (uint8 playersize = numPlayers - proposalRoles.size())
        {
            sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) not compatible, %u players are ignoring each other", strGuids.c_str(), playersize);
            SetCompatibles(strGuids, LFG_INCOMPATIBLES_HAS_IGNORES);
            return LFG_INCOMPATIBLES_HAS_IGNORES;
        }

        LfgRolesMap debugRoles = proposalRoles; // DEBUG
        if (!LFGMgr::CheckGroupRoles(proposalRoles))
        {
            std::ostringstream o;
            for (LfgRolesMap::const_iterator it = debugRoles.begin(); it != debugRoles.end(); ++it)
                o << ", " << it->first << ": " << sLFGMgr->GetRolesString(it->second);

            sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) Roles not compatible%s", strGuids.c_str(), o.str().c_str());
            SetCompatibles(strGuids, LFG_INCOMPATIBLES_NO_ROLES);
            return LFG_INCOMPATIBLES_NO_ROLES;
        }

        LfgGuidList::iterator itguid = check.begin();
        proposalDungeons = m_QueueDataMap[*itguid].dungeons;
        std::ostringstream o;
        o << ", " << *itguid << ": (" << sLFGMgr->ConcatenateDungeons(proposalDungeons) << ")";
        for (++itguid; itguid != check.end(); ++itguid)
        {
            LfgDungeonSet temporal;
            LfgDungeonSet &dungeons = m_QueueDataMap[*itguid].dungeons;
            o << ", " << *itguid << ": (" << sLFGMgr->ConcatenateDungeons(dungeons) << ")";
            std::set_intersection(proposalDungeons.begin(), proposalDungeons.end(), dungeons.begin(), dungeons.end(), std::inserter(temporal, temporal.begin()));
            proposalDungeons = temporal;
        }

        if (proposalDungeons.empty())
        {
            sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) No compatible dungeons%s", strGuids.c_str(), o.str().c_str());
            SetCompatibles(strGuids, LFG_INCOMPATIBLES_NO_DUNGEONS);
            return LFG_INCOMPATIBLES_NO_DUNGEONS;
        }
    }
    else
    {
        uint64 gguid = *check.begin();
        const LfgQueueData &queue = m_QueueDataMap[gguid];
        proposalDungeons = queue.dungeons;
        proposalRoles = queue.roles;
        LFGMgr::CheckGroupRoles(proposalRoles);          // assing new roles
    }

    // Enough players?
    if (numPlayers != MAXGROUPSIZE)
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) Compatibles but not enough players(%u)", strGuids.c_str(), numPlayers);
        SetCompatibles(strGuids, LFG_COMPATIBLES_WITH_LESS_PLAYERS);
        return LFG_COMPATIBLES_WITH_LESS_PLAYERS;
    }

    proposal.queues = check;
    if (check.size() == 1)
    {
        for (LfgGroupsMap::const_iterator it = proposalGroups.begin(); it != proposalGroups.end(); ++it)
            if (proposal.group && it->second != proposal.group)
                proposal.isNew = false;
    }

    if (!sLFGMgr->AllQueued(check))
    {
        sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) Group MATCH but can't create proposal!", strGuids.c_str());
        SetCompatibles(strGuids, LFG_COMPATIBLES_BAD_STATES);
        return LFG_COMPATIBLES_BAD_STATES;
    }

    // Create a new proposal
    proposal.cancelTime = time(NULL) + LFG_TIME_PROPOSAL;
    proposal.state = LFG_PROPOSAL_INITIATING;
    proposal.leader = 0;
    proposal.dungeonId = Trinity::Containers::SelectRandomContainerElement(proposalDungeons);

    bool leader = false;
    for (LfgRolesMap::const_iterator itRoles = proposalRoles.begin(); itRoles != proposalRoles.end(); ++itRoles)
    {
        // Assing new leader
        if (itRoles->second & PLAYER_ROLE_LEADER)
        {
            if (!leader || !proposal.leader || urand(0, 1))
                proposal.leader = itRoles->first;
            leader = true;
        }
        else if (!leader && (!proposal.leader || urand(0, 1)))
            proposal.leader = itRoles->first;

        // Assing player data and roles
        LfgProposalPlayer &data = proposal.players[itRoles->first];
        data.role = itRoles->second;
        data.group = proposalGroups.find(itRoles->first)->second;
        if (!proposal.isNew && data.group && data.group == proposal.group) // Player from existing group, autoaccept
            data.accept = LFG_ANSWER_AGREE;
    }

    // Mark proposal members as not queued (but not remove queue data)
    for (LfgGuidList::const_iterator itQueue = proposal.queues.begin(); itQueue != proposal.queues.end(); ++itQueue)
    {
        uint64 guid = (*itQueue);
        RemoveFromNewQueue(guid);
        RemoveFromCurrentQueue(guid);
    }

    sLFGMgr->AddProposal(proposal);

    sLog->outDebug(LOG_FILTER_LFG, "LFGQueue::CheckCompatibility: (%s) MATCH! Group formed", strGuids.c_str());
    SetCompatibles(strGuids, LFG_COMPATIBLES_MATCH);
    return LFG_COMPATIBLES_MATCH;
}

void LfgQueue::UpdateQueueTimers(time_t currTime)
{
    for (LfgQueueDataMap::const_iterator itQueue = m_QueueDataMap.begin(); itQueue != m_QueueDataMap.end(); ++itQueue)
    {
        const LfgQueueData &queueinfo = itQueue->second;
        uint32 dungeonId = (*queueinfo.dungeons.begin());
        uint32 queuedTime = uint32(currTime - queueinfo.joinTime);
        uint8 role = PLAYER_ROLE_NONE;
        int32 waitTime = -1;
        int32 wtTank = m_waitTimesTank[dungeonId].time;
        int32 wtHealer = m_waitTimesHealer[dungeonId].time;
        int32 wtDps = m_waitTimesDps[dungeonId].time;
        int32 wtAvg = m_waitTimesAvg[dungeonId].time;

        for (LfgRolesMap::const_iterator itPlayer = queueinfo.roles.begin(); itPlayer != queueinfo.roles.end(); ++itPlayer)
            role |= itPlayer->second;
        role &= ~PLAYER_ROLE_LEADER;

        switch (role)
        {
            case PLAYER_ROLE_NONE:                                // Should not happen - just in case
                waitTime = -1;
                break;
            case PLAYER_ROLE_TANK:
                waitTime = wtTank;
                break;
            case PLAYER_ROLE_HEALER:
                waitTime = wtHealer;
                break;
            case PLAYER_ROLE_DAMAGE:
                waitTime = wtDps;
                break;
            default:
                waitTime = wtAvg;
                break;
        }

        LfgQueueStatusData queueData(dungeonId, waitTime, wtAvg, wtTank, wtHealer, wtDps, queuedTime, queueinfo.tanks, queueinfo.healers, queueinfo.dps);
        for (LfgRolesMap::const_iterator itPlayer = queueinfo.roles.begin(); itPlayer != queueinfo.roles.end(); ++itPlayer)
        {
            uint64 pguid = itPlayer->first;
            LFGMgr::SendLfgQueueStatus(pguid, queueData);
        }
    }
}

time_t LfgQueue::GetJoinTime(uint64 guid)
{
    return m_QueueDataMap[guid].joinTime;
}

LfgCompatibleMap const& LfgQueue::GetCompatibleMap()
{
    return m_CompatibleMap;
}

std::string LfgQueue::DumpQueueInfo() const
{
    uint32 players = 0;
    uint32 groups = 0;
    uint32 playersInGroup = 0;

    for (uint8 i = 0; i < 2; ++i)
    {
        LfgGuidList const& queue = i ? m_newToQueue : m_currentQueue;
        for (LfgGuidList::const_iterator it = queue.begin(); it != queue.end(); ++it)
        {
            uint64 guid = *it;
            if (IS_GROUP(guid))
            {
                groups++;
                playersInGroup += sLFGMgr->GetPlayerCount(guid);
            }
            else
                players++;
        }
    }
    std::ostringstream o;
    o << "Queued Players: " << players << " (in group: " << playersInGroup << ") Groups: " << groups << "\n";
    return o.str();
}

std::string LfgQueue::DumpCompatibleInfo(bool full /* = false */) const
{
    std::ostringstream o;
    o << "Compatible Map size: " << m_CompatibleMap.size() << "\n";
    if (full)
        for (LfgCompatibleMap::const_iterator itr = m_CompatibleMap.begin(); itr != m_CompatibleMap.end(); ++itr)
            o << "(" << itr->first << "): " << GetCompatibleString(itr->second) << "\n";

    return o.str();
}
