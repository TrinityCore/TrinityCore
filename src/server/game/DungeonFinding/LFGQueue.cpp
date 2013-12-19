/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

namespace lfg
{

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

char const* GetCompatibleString(LfgCompatibility compatibles)
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

void LFGQueue::AddToQueue(uint64 guid)
{
    LfgQueueDataContainer::iterator itQueue = QueueDataStore.find(guid);
    if (itQueue == QueueDataStore.end())
    {
        TC_LOG_ERROR("lfg.queue.add", "Queue data not found for [" UI64FMTD "]", guid);
        return;
    }

    AddToNewQueue(guid);
}

void LFGQueue::RemoveFromQueue(uint64 guid)
{
    RemoveFromNewQueue(guid);
    RemoveFromCurrentQueue(guid);
    RemoveFromCompatibles(guid);

    std::ostringstream o;
    o << guid;
    std::string sguid = o.str();

    LfgQueueDataContainer::iterator itDelete = QueueDataStore.end();
    for (LfgQueueDataContainer::iterator itr = QueueDataStore.begin(); itr != QueueDataStore.end(); ++itr)
        if (itr->first != guid)
        {
            if (std::string::npos != itr->second.bestCompatible.find(sguid))
            {
                itr->second.bestCompatible.clear();
                FindBestCompatibleInQueue(itr);
            }
        }
        else
            itDelete = itr;

    if (itDelete != QueueDataStore.end())
        QueueDataStore.erase(itDelete);
}

void LFGQueue::AddToNewQueue(uint64 guid)
{
    newToQueueStore.push_back(guid);
}

void LFGQueue::RemoveFromNewQueue(uint64 guid)
{
    newToQueueStore.remove(guid);
}

void LFGQueue::AddToCurrentQueue(uint64 guid)
{
    currentQueueStore.push_back(guid);
}

void LFGQueue::RemoveFromCurrentQueue(uint64 guid)
{
    currentQueueStore.remove(guid);
}

void LFGQueue::AddQueueData(uint64 guid, time_t joinTime, LfgDungeonSet const& dungeons, LfgRolesMap const& rolesMap)
{
    QueueDataStore[guid] = LfgQueueData(joinTime, dungeons, rolesMap);
    AddToQueue(guid);
}

void LFGQueue::RemoveQueueData(uint64 guid)
{
    LfgQueueDataContainer::iterator it = QueueDataStore.find(guid);
    if (it != QueueDataStore.end())
        QueueDataStore.erase(it);
}

void LFGQueue::UpdateWaitTimeAvg(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = waitTimesAvgStore[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

void LFGQueue::UpdateWaitTimeTank(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = waitTimesTankStore[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

void LFGQueue::UpdateWaitTimeHealer(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = waitTimesHealerStore[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

void LFGQueue::UpdateWaitTimeDps(int32 waitTime, uint32 dungeonId)
{
    LfgWaitTime &wt = waitTimesDpsStore[dungeonId];
    uint32 old_number = wt.number++;
    wt.time = int32((wt.time * old_number + waitTime) / wt.number);
}

/**
   Remove from cached compatible dungeons any entry that contains the given guid

   @param[in]     guid Guid to remove from compatible cache
*/
void LFGQueue::RemoveFromCompatibles(uint64 guid)
{
    std::stringstream out;
    out << guid;
    std::string strGuid = out.str();

    TC_LOG_DEBUG("lfg.queue.data.compatibles.remove", "Removing [" UI64FMTD "]", guid);
    for (LfgCompatibleContainer::iterator itNext = CompatibleMapStore.begin(); itNext != CompatibleMapStore.end();)
    {
        LfgCompatibleContainer::iterator it = itNext++;
        if (std::string::npos != it->first.find(strGuid))
            CompatibleMapStore.erase(it);
    }
}

/**
   Stores the compatibility of a list of guids

   @param[in]     key String concatenation of guids (| used as separator)
   @param[in]     compatibles type of compatibility
*/
void LFGQueue::SetCompatibles(std::string const& key, LfgCompatibility compatibles)
{
    LfgCompatibilityData& data = CompatibleMapStore[key];
    data.compatibility = compatibles;
}

void LFGQueue::SetCompatibilityData(std::string const& key, LfgCompatibilityData const& data)
{
    CompatibleMapStore[key] = data;
}

/**
   Get the compatibility of a group of guids

   @param[in]     key String concatenation of guids (| used as separator)
   @return LfgCompatibility type of compatibility
*/
LfgCompatibility LFGQueue::GetCompatibles(std::string const& key)
{
    LfgCompatibleContainer::iterator itr = CompatibleMapStore.find(key);
    if (itr != CompatibleMapStore.end())
        return itr->second.compatibility;

    return LFG_COMPATIBILITY_PENDING;
}

LfgCompatibilityData* LFGQueue::GetCompatibilityData(std::string const& key)
{
    LfgCompatibleContainer::iterator itr = CompatibleMapStore.find(key);
    if (itr != CompatibleMapStore.end())
        return &(itr->second);

    return NULL;
}

uint8 LFGQueue::FindGroups()
{
    uint8 proposals = 0;
    LfgGuidList firstNew;
    while (!newToQueueStore.empty())
    {
        uint64 frontguid = newToQueueStore.front();
        TC_LOG_DEBUG("lfg.queue.match.check.new", "Checking [" UI64FMTD "] newToQueue(%u), currentQueue(%u)", frontguid, uint32(newToQueueStore.size()), uint32(currentQueueStore.size()));
        firstNew.clear();
        firstNew.push_back(frontguid);
        RemoveFromNewQueue(frontguid);

        LfgGuidList temporalList = currentQueueStore;
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
LfgCompatibility LFGQueue::FindNewGroups(LfgGuidList& check, LfgGuidList& all)
{
    std::string strGuids = ConcatenateGuids(check);
    LfgCompatibility compatibles = GetCompatibles(strGuids);

    TC_LOG_DEBUG("lfg.queue.match.check", "Guids: (%s): %s - all(%s)", strGuids.c_str(), GetCompatibleString(compatibles), ConcatenateGuids(all).c_str());
    if (compatibles == LFG_COMPATIBILITY_PENDING) // Not previously cached, calculate
        compatibles = CheckCompatibility(check);

    if (compatibles == LFG_COMPATIBLES_BAD_STATES && sLFGMgr->AllQueued(check))
    {
        TC_LOG_DEBUG("lfg.queue.match.check", "Guids: (%s) compatibles (cached) changed from bad states to match", strGuids.c_str());
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
LfgCompatibility LFGQueue::CheckCompatibility(LfgGuidList check)
{
    std::string strGuids = ConcatenateGuids(check);
    LfgProposal proposal;
    LfgDungeonSet proposalDungeons;
    LfgGroupsMap proposalGroups;
    LfgRolesMap proposalRoles;

    // Check for correct size
    if (check.size() > MAXGROUPSIZE || check.empty())
    {
        TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s): Size wrong - Not compatibles", strGuids.c_str());
        return LFG_INCOMPATIBLES_WRONG_GROUP_SIZE;
    }

    // Check all-but-new compatiblitity
    if (check.size() > 2)
    {
        uint64 frontGuid = check.front();
        check.pop_front();

        // Check all-but-new compatibilities (New, A, B, C, D) --> check(A, B, C, D)
        LfgCompatibility child_compatibles = CheckCompatibility(check);
        if (child_compatibles < LFG_COMPATIBLES_WITH_LESS_PLAYERS) // Group not compatible
        {
            TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) child %s not compatibles", strGuids.c_str(), ConcatenateGuids(check).c_str());
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
        LfgQueueDataContainer::iterator itQueue = QueueDataStore.find(guid);
        if (itQueue == QueueDataStore.end())
        {
            TC_LOG_ERROR("lfg.queue.match.compatibility.check", "Guid: [" UI64FMTD "] is not queued but listed as queued!", guid);
            RemoveFromQueue(guid);
            return LFG_COMPATIBILITY_PENDING;
        }

        // Store group so we don't need to call Mgr to get it later (if it's player group will be 0 otherwise would have joined as group)
        for (LfgRolesMap::const_iterator it2 = itQueue->second.roles.begin(); it2 != itQueue->second.roles.end(); ++it2)
            proposalGroups[it2->first] = IS_GROUP_GUID(itQueue->first) ? itQueue->first : 0;

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
        TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) sigle group. Compatibles", strGuids.c_str());
        LfgQueueDataContainer::iterator itQueue = QueueDataStore.find(check.front());

        LfgCompatibilityData data(LFG_COMPATIBLES_WITH_LESS_PLAYERS);
        data.roles = itQueue->second.roles;
        LFGMgr::CheckGroupRoles(data.roles);

        UpdateBestCompatibleInQueue(itQueue, strGuids, data.roles);
        SetCompatibilityData(strGuids, data);
        return LFG_COMPATIBLES_WITH_LESS_PLAYERS;
    }

    if (numLfgGroups > 1)
    {
        TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) More than one Lfggroup (%u)", strGuids.c_str(), numLfgGroups);
        SetCompatibles(strGuids, LFG_INCOMPATIBLES_MULTIPLE_LFG_GROUPS);
        return LFG_INCOMPATIBLES_MULTIPLE_LFG_GROUPS;
    }

    if (numPlayers > MAXGROUPSIZE)
    {
        TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) Too much players (%u)", strGuids.c_str(), numPlayers);
        SetCompatibles(strGuids, LFG_INCOMPATIBLES_TOO_MUCH_PLAYERS);
        return LFG_INCOMPATIBLES_TOO_MUCH_PLAYERS;
    }

    // If it's single group no need to check for duplicate players, ignores, bad roles or bad dungeons as it's been checked before joining
    if (check.size() > 1)
    {
        for (LfgGuidList::const_iterator it = check.begin(); it != check.end(); ++it)
        {
            const LfgRolesMap &roles = QueueDataStore[(*it)].roles;
            for (LfgRolesMap::const_iterator itRoles = roles.begin(); itRoles != roles.end(); ++itRoles)
            {
                LfgRolesMap::const_iterator itPlayer;
                for (itPlayer = proposalRoles.begin(); itPlayer != proposalRoles.end(); ++itPlayer)
                {
                    if (itRoles->first == itPlayer->first)
                        TC_LOG_ERROR("lfg.queue.match.compatibility.check", "Guids: ERROR! Player multiple times in queue! [" UI64FMTD "]", itRoles->first);
                    else if (sLFGMgr->HasIgnore(itRoles->first, itPlayer->first))
                        break;
                }
                if (itPlayer == proposalRoles.end())
                    proposalRoles[itRoles->first] = itRoles->second;
            }
        }

        if (uint8 playersize = numPlayers - proposalRoles.size())
        {
            TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) not compatible, %u players are ignoring each other", strGuids.c_str(), playersize);
            SetCompatibles(strGuids, LFG_INCOMPATIBLES_HAS_IGNORES);
            return LFG_INCOMPATIBLES_HAS_IGNORES;
        }

        LfgRolesMap debugRoles = proposalRoles;
        if (!LFGMgr::CheckGroupRoles(proposalRoles))
        {
            std::ostringstream o;
            for (LfgRolesMap::const_iterator it = debugRoles.begin(); it != debugRoles.end(); ++it)
                o << ", " << it->first << ": " << GetRolesString(it->second);

            TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) Roles not compatible%s", strGuids.c_str(), o.str().c_str());
            SetCompatibles(strGuids, LFG_INCOMPATIBLES_NO_ROLES);
            return LFG_INCOMPATIBLES_NO_ROLES;
        }

        LfgGuidList::iterator itguid = check.begin();
        proposalDungeons = QueueDataStore[*itguid].dungeons;
        std::ostringstream o;
        o << ", " << *itguid << ": (" << ConcatenateDungeons(proposalDungeons) << ")";
        for (++itguid; itguid != check.end(); ++itguid)
        {
            LfgDungeonSet temporal;
            LfgDungeonSet &dungeons = QueueDataStore[*itguid].dungeons;
            o << ", " << *itguid << ": (" << ConcatenateDungeons(dungeons) << ")";
            std::set_intersection(proposalDungeons.begin(), proposalDungeons.end(), dungeons.begin(), dungeons.end(), std::inserter(temporal, temporal.begin()));
            proposalDungeons = temporal;
        }

        if (proposalDungeons.empty())
        {
            TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) No compatible dungeons%s", strGuids.c_str(), o.str().c_str());
            SetCompatibles(strGuids, LFG_INCOMPATIBLES_NO_DUNGEONS);
            return LFG_INCOMPATIBLES_NO_DUNGEONS;
        }
    }
    else
    {
        uint64 gguid = *check.begin();
        const LfgQueueData &queue = QueueDataStore[gguid];
        proposalDungeons = queue.dungeons;
        proposalRoles = queue.roles;
        LFGMgr::CheckGroupRoles(proposalRoles);          // assing new roles
    }

    // Enough players?
    if (numPlayers != MAXGROUPSIZE)
    {
        TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) Compatibles but not enough players(%u)", strGuids.c_str(), numPlayers);
        LfgCompatibilityData data(LFG_COMPATIBLES_WITH_LESS_PLAYERS);
        data.roles = proposalRoles;

        for (LfgGuidList::const_iterator itr = check.begin(); itr != check.end(); ++itr)
            UpdateBestCompatibleInQueue(QueueDataStore.find(*itr), strGuids, data.roles);

        SetCompatibilityData(strGuids, data);
        return LFG_COMPATIBLES_WITH_LESS_PLAYERS;
    }

    uint64 gguid = *check.begin();
    proposal.queues = check;
    proposal.isNew = numLfgGroups != 1 || sLFGMgr->GetOldState(gguid) != LFG_STATE_DUNGEON;

    if (!sLFGMgr->AllQueued(check))
    {
        TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) Group MATCH but can't create proposal!", strGuids.c_str());
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

    TC_LOG_DEBUG("lfg.queue.match.compatibility.check", "Guids: (%s) MATCH! Group formed", strGuids.c_str());
    SetCompatibles(strGuids, LFG_COMPATIBLES_MATCH);
    return LFG_COMPATIBLES_MATCH;
}

void LFGQueue::UpdateQueueTimers(time_t currTime)
{
    TC_LOG_TRACE("lfg.queue.timers.update", "Updating queue timers...");
    for (LfgQueueDataContainer::iterator itQueue = QueueDataStore.begin(); itQueue != QueueDataStore.end(); ++itQueue)
    {
        LfgQueueData& queueinfo = itQueue->second;
        uint32 dungeonId = (*queueinfo.dungeons.begin());
        uint32 queuedTime = uint32(currTime - queueinfo.joinTime);
        uint8 role = PLAYER_ROLE_NONE;
        int32 waitTime = -1;
        int32 wtTank = waitTimesTankStore[dungeonId].time;
        int32 wtHealer = waitTimesHealerStore[dungeonId].time;
        int32 wtDps = waitTimesDpsStore[dungeonId].time;
        int32 wtAvg = waitTimesAvgStore[dungeonId].time;

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

        if (queueinfo.bestCompatible.empty())
            FindBestCompatibleInQueue(itQueue);

        LfgQueueStatusData queueData(dungeonId, waitTime, wtAvg, wtTank, wtHealer, wtDps, queuedTime, queueinfo.tanks, queueinfo.healers, queueinfo.dps);
        for (LfgRolesMap::const_iterator itPlayer = queueinfo.roles.begin(); itPlayer != queueinfo.roles.end(); ++itPlayer)
        {
            uint64 pguid = itPlayer->first;
            LFGMgr::SendLfgQueueStatus(pguid, queueData);
        }
    }
}

time_t LFGQueue::GetJoinTime(uint64 guid)
{
    return QueueDataStore[guid].joinTime;
}

std::string LFGQueue::DumpQueueInfo() const
{
    uint32 players = 0;
    uint32 groups = 0;
    uint32 playersInGroup = 0;

    for (uint8 i = 0; i < 2; ++i)
    {
        LfgGuidList const& queue = i ? newToQueueStore : currentQueueStore;
        for (LfgGuidList::const_iterator it = queue.begin(); it != queue.end(); ++it)
        {
            uint64 guid = *it;
            if (IS_GROUP_GUID(guid))
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

std::string LFGQueue::DumpCompatibleInfo(bool full /* = false */) const
{
    std::ostringstream o;
    o << "Compatible Map size: " << CompatibleMapStore.size() << "\n";
    if (full)
        for (LfgCompatibleContainer::const_iterator itr = CompatibleMapStore.begin(); itr != CompatibleMapStore.end(); ++itr)
            o << "(" << itr->first << "): " << GetCompatibleString(itr->second.compatibility) << "\n";

    return o.str();
}

void LFGQueue::FindBestCompatibleInQueue(LfgQueueDataContainer::iterator itrQueue)
{
    TC_LOG_DEBUG("lfg.queue.compatibles.find", "Guid: " UI64FMTD, itrQueue->first);
    std::ostringstream o;
    o << itrQueue->first;
    std::string sguid = o.str();

    for (LfgCompatibleContainer::const_iterator itr = CompatibleMapStore.begin(); itr != CompatibleMapStore.end(); ++itr)
        if (itr->second.compatibility == LFG_COMPATIBLES_WITH_LESS_PLAYERS &&
            std::string::npos != itr->first.find(sguid))
        {
            UpdateBestCompatibleInQueue(itrQueue, itr->first, itr->second.roles);
        }
}

void LFGQueue::UpdateBestCompatibleInQueue(LfgQueueDataContainer::iterator itrQueue, std::string const& key, LfgRolesMap const& roles)
{
    LfgQueueData& queueData = itrQueue->second;

    uint8 storedSize = queueData.bestCompatible.empty() ? 0 :
        std::count(queueData.bestCompatible.begin(), queueData.bestCompatible.end(), '|') + 1;

    uint8 size = std::count(key.begin(), key.end(), '|') + 1;

    if (size <= storedSize)
        return;

    TC_LOG_DEBUG("lfg.queue.compatibles.update", "Changed (%s) to (%s) as best compatible group for " UI64FMTD,
        queueData.bestCompatible.c_str(), key.c_str(), itrQueue->first);

    queueData.bestCompatible = key;
    queueData.tanks = LFG_TANKS_NEEDED;
    queueData.healers = LFG_HEALERS_NEEDED;
    queueData.dps = LFG_DPS_NEEDED;
    for (LfgRolesMap::const_iterator it = roles.begin(); it != roles.end(); ++it)
    {
        uint8 role = it->second;
        if (role & PLAYER_ROLE_TANK)
            --queueData.tanks;
        else if (role & PLAYER_ROLE_HEALER)
            --queueData.healers;
        else
            --queueData.dps;
    }
}

} // namespace lfg
