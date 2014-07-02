/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "BattlegroundMgr.h"
#include "BattlegroundQueue.h"
#include "Chat.h"
#include "Group.h"
#include "Log.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"

/*********************************************************/
/***            BATTLEGROUND QUEUE SYSTEM              ***/
/*********************************************************/

BattlegroundQueue::BattlegroundQueue()
{
    for (uint32 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        for (uint32 j = 0; j < MAX_BATTLEGROUND_BRACKETS; ++j)
        {
            m_SumOfWaitTimes[i][j] = 0;
            m_WaitTimeLastPlayer[i][j] = 0;
            for (uint32 k = 0; k < COUNT_OF_PLAYERS_TO_AVERAGE_WAIT_TIME; ++k)
                m_WaitTimes[i][j][k] = 0;
        }
    }
}

BattlegroundQueue::~BattlegroundQueue()
{
    m_events.KillAllEvents(false);

    for (int i = 0; i < MAX_BATTLEGROUND_BRACKETS; ++i)
    {
        for (uint32 j = 0; j < BG_QUEUE_GROUP_TYPES_COUNT; ++j)
        {
            for (GroupsQueueType::iterator itr = m_QueuedGroups[i][j].begin(); itr!= m_QueuedGroups[i][j].end(); ++itr)
                delete (*itr);
        }
    }
}

/*********************************************************/
/***      BATTLEGROUND QUEUE SELECTION POOLS           ***/
/*********************************************************/

// selection pool initialization, used to clean up from prev selection
void BattlegroundQueue::SelectionPool::Init()
{
    SelectedGroups.clear();
    PlayerCount = 0;
}

// remove group info from selection pool
// returns true when we need to try to add new group to selection pool
// returns false when selection pool is ok or when we kicked smaller group than we need to kick
// sometimes it can be called on empty selection pool
bool BattlegroundQueue::SelectionPool::KickGroup(uint32 size)
{
    //find maxgroup or LAST group with size == size and kick it
    bool found = false;
    GroupsQueueType::iterator groupToKick = SelectedGroups.begin();
    for (GroupsQueueType::iterator itr = groupToKick; itr != SelectedGroups.end(); ++itr)
    {
        if (abs((int32)((*itr)->Players.size() - size)) <= 1)
        {
            groupToKick = itr;
            found = true;
        }
        else if (!found && (*itr)->Players.size() >= (*groupToKick)->Players.size())
            groupToKick = itr;
    }
    //if pool is empty, do nothing
    if (GetPlayerCount())
    {
        //update player count
        GroupQueueInfo* ginfo = (*groupToKick);
        SelectedGroups.erase(groupToKick);
        PlayerCount -= ginfo->Players.size();
        //return false if we kicked smaller group or there are enough players in selection pool
        if (ginfo->Players.size() <= size + 1)
            return false;
    }
    return true;
}

// add group to selection pool
// used when building selection pools
// returns true if we can invite more players, or when we added group to selection pool
// returns false when selection pool is full
bool BattlegroundQueue::SelectionPool::AddGroup(GroupQueueInfo* ginfo, uint32 desiredCount)
{
    //if group is larger than desired count - don't allow to add it to pool
    if (!ginfo->IsInvitedToBGInstanceGUID && desiredCount >= PlayerCount + ginfo->Players.size())
    {
        SelectedGroups.push_back(ginfo);
        // increase selected players count
        PlayerCount += ginfo->Players.size();
        return true;
    }
    if (PlayerCount < desiredCount)
        return true;
    return false;
}

/*********************************************************/
/***               BATTLEGROUND QUEUES                 ***/
/*********************************************************/

// add group or player (grp == NULL) to bg queue with the given leader and bg specifications
GroupQueueInfo* BattlegroundQueue::AddGroup(Player* leader, Group* grp, BattlegroundTypeId BgTypeId, PvPDifficultyEntry const*  bracketEntry, uint8 ArenaType, bool isRated, bool isPremade, uint32 ArenaRating, uint32 MatchmakerRating, uint32 arenateamid)
{
    BattlegroundBracketId bracketId = bracketEntry->GetBracketId();

    // create new ginfo
    GroupQueueInfo* ginfo            = new GroupQueueInfo;
    ginfo->BgTypeId                  = BgTypeId;
    ginfo->ArenaType                 = ArenaType;
    ginfo->ArenaTeamId               = arenateamid;
    ginfo->IsRated                   = isRated;
    ginfo->IsInvitedToBGInstanceGUID = 0;
    ginfo->JoinTime                  = getMSTime();
    ginfo->RemoveInviteTime          = 0;
    ginfo->Team                      = leader->GetTeam();
    ginfo->ArenaTeamRating           = ArenaRating;
    ginfo->ArenaMatchmakerRating     = MatchmakerRating;
    ginfo->OpponentsTeamRating       = 0;
    ginfo->OpponentsMatchmakerRating = 0;

    ginfo->Players.clear();

    //compute index (if group is premade or joined a rated match) to queues
    uint32 index = 0;
    if (!isRated && !isPremade)
        index += BG_TEAMS_COUNT;
    if (ginfo->Team == HORDE)
        index++;
    TC_LOG_DEBUG("bg.battleground", "Adding Group to BattlegroundQueue bgTypeId : %u, bracket_id : %u, index : %u", BgTypeId, bracketId, index);

    uint32 lastOnlineTime = getMSTime();

    //announce world (this don't need mutex)
    if (isRated && sWorld->getBoolConfig(CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE))
    {
        ArenaTeam* Team = sArenaTeamMgr->GetArenaTeamById(arenateamid);
        if (Team)
            sWorld->SendWorldText(LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN, Team->GetName().c_str(), ginfo->ArenaType, ginfo->ArenaType, ginfo->ArenaTeamRating);
    }

    //add players from group to ginfo
    if (grp)
    {
        for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* member = itr->GetSource();
            if (!member)
                continue;   // this should never happen
            PlayerQueueInfo& pl_info = m_QueuedPlayers[member->GetGUID()];
            pl_info.LastOnlineTime   = lastOnlineTime;
            pl_info.GroupInfo        = ginfo;
            // add the pinfo to ginfo's list
            ginfo->Players[member->GetGUID()]  = &pl_info;
        }
    }
    else
    {
        PlayerQueueInfo& pl_info = m_QueuedPlayers[leader->GetGUID()];
        pl_info.LastOnlineTime   = lastOnlineTime;
        pl_info.GroupInfo        = ginfo;
        ginfo->Players[leader->GetGUID()]  = &pl_info;
    }

    //add GroupInfo to m_QueuedGroups
    {
        m_QueuedGroups[bracketId][index].push_back(ginfo);

        //announce to world, this code needs mutex
        if (!isRated && !isPremade && sWorld->getBoolConfig(CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE))
        {
            if (Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(ginfo->BgTypeId))
            {
                char const* bgName = bg->GetName();
                uint32 MinPlayers = bg->GetMinPlayersPerTeam();
                uint32 qHorde = 0;
                uint32 qAlliance = 0;
                uint32 q_min_level = bracketEntry->minLevel;
                uint32 q_max_level = bracketEntry->maxLevel;
                GroupsQueueType::const_iterator itr;
                for (itr = m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_ALLIANCE].begin(); itr != m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_ALLIANCE].end(); ++itr)
                    if (!(*itr)->IsInvitedToBGInstanceGUID)
                        qAlliance += (*itr)->Players.size();
                for (itr = m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_HORDE].begin(); itr != m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_HORDE].end(); ++itr)
                    if (!(*itr)->IsInvitedToBGInstanceGUID)
                        qHorde += (*itr)->Players.size();

                // Show queue status to player only (when joining queue)
                if (sWorld->getBoolConfig(CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_PLAYERONLY))
                {
                    ChatHandler(leader->GetSession()).PSendSysMessage(LANG_BG_QUEUE_ANNOUNCE_SELF, bgName, q_min_level, q_max_level,
                        qAlliance, (MinPlayers > qAlliance) ? MinPlayers - qAlliance : (uint32)0, qHorde, (MinPlayers > qHorde) ? MinPlayers - qHorde : (uint32)0);
                }
                // System message
                else
                {
                    sWorld->SendWorldText(LANG_BG_QUEUE_ANNOUNCE_WORLD, bgName, q_min_level, q_max_level,
                        qAlliance, (MinPlayers > qAlliance) ? MinPlayers - qAlliance : (uint32)0, qHorde, (MinPlayers > qHorde) ? MinPlayers - qHorde : (uint32)0);
                }
            }
        }
        //release mutex
    }

    return ginfo;
}

void BattlegroundQueue::PlayerInvitedToBGUpdateAverageWaitTime(GroupQueueInfo* ginfo, BattlegroundBracketId bracket_id)
{
    uint32 timeInQueue = getMSTimeDiff(ginfo->JoinTime, getMSTime());
    uint8 team_index = TEAM_ALLIANCE;                    //default set to TEAM_ALLIANCE - or non rated arenas!
    if (!ginfo->ArenaType)
    {
        if (ginfo->Team == HORDE)
            team_index = TEAM_HORDE;
    }
    else
    {
        if (ginfo->IsRated)
            team_index = TEAM_HORDE;                     //for rated arenas use TEAM_HORDE
    }

    //store pointer to arrayindex of player that was added first
    uint32* lastPlayerAddedPointer = &(m_WaitTimeLastPlayer[team_index][bracket_id]);
    //remove his time from sum
    m_SumOfWaitTimes[team_index][bracket_id] -= m_WaitTimes[team_index][bracket_id][(*lastPlayerAddedPointer)];
    //set average time to new
    m_WaitTimes[team_index][bracket_id][(*lastPlayerAddedPointer)] = timeInQueue;
    //add new time to sum
    m_SumOfWaitTimes[team_index][bracket_id] += timeInQueue;
    //set index of last player added to next one
    (*lastPlayerAddedPointer)++;
    (*lastPlayerAddedPointer) %= COUNT_OF_PLAYERS_TO_AVERAGE_WAIT_TIME;
}

uint32 BattlegroundQueue::GetAverageQueueWaitTime(GroupQueueInfo* ginfo, BattlegroundBracketId bracket_id) const
{
    uint8 team_index = TEAM_ALLIANCE;                    //default set to TEAM_ALLIANCE - or non rated arenas!
    if (!ginfo->ArenaType)
    {
        if (ginfo->Team == HORDE)
            team_index = TEAM_HORDE;
    }
    else
    {
        if (ginfo->IsRated)
            team_index = TEAM_HORDE;                     //for rated arenas use TEAM_HORDE
    }
    //check if there is enought values(we always add values > 0)
    if (m_WaitTimes[team_index][bracket_id][COUNT_OF_PLAYERS_TO_AVERAGE_WAIT_TIME - 1])
        return (m_SumOfWaitTimes[team_index][bracket_id] / COUNT_OF_PLAYERS_TO_AVERAGE_WAIT_TIME);
    else
        //if there aren't enough values return 0 - not available
        return 0;
}

//remove player from queue and from group info, if group info is empty then remove it too
void BattlegroundQueue::RemovePlayer(uint64 guid, bool decreaseInvitedCount)
{
    int32 bracket_id = -1;                                     // signed for proper for-loop finish
    QueuedPlayersMap::iterator itr;

    //remove player from map, if he's there
    itr = m_QueuedPlayers.find(guid);
    if (itr == m_QueuedPlayers.end())
    {
        std::string playerName = "Unknown";
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            playerName = player->GetName();
        TC_LOG_ERROR("bg.battleground", "BattlegroundQueue: couldn't find player %s (GUID: %u)", playerName.c_str(), GUID_LOPART(guid));
        return;
    }

    GroupQueueInfo* group = itr->second.GroupInfo;
    GroupsQueueType::iterator group_itr;
    // mostly people with the highest levels are in battlegrounds, thats why
    // we count from MAX_BATTLEGROUND_QUEUES - 1 to 0

    uint32 index = (group->Team == HORDE) ? BG_QUEUE_PREMADE_HORDE : BG_QUEUE_PREMADE_ALLIANCE;

    for (int32 bracket_id_tmp = MAX_BATTLEGROUND_BRACKETS - 1; bracket_id_tmp >= 0 && bracket_id == -1; --bracket_id_tmp)
    {
        //we must check premade and normal team's queue - because when players from premade are joining bg,
        //they leave groupinfo so we can't use its players size to find out index
        for (uint32 j = index; j < BG_QUEUE_GROUP_TYPES_COUNT; j += BG_TEAMS_COUNT)
        {
            GroupsQueueType::iterator k = m_QueuedGroups[bracket_id_tmp][j].begin();
            for (; k != m_QueuedGroups[bracket_id_tmp][j].end(); ++k)
            {
                if ((*k) == group)
                {
                    bracket_id = bracket_id_tmp;
                    group_itr = k;
                    //we must store index to be able to erase iterator
                    index = j;
                    break;
                }
            }
        }
    }

    //player can't be in queue without group, but just in case
    if (bracket_id == -1)
    {
        TC_LOG_ERROR("bg.battleground", "BattlegroundQueue: ERROR Cannot find groupinfo for player GUID: %u", GUID_LOPART(guid));
        return;
    }
    TC_LOG_DEBUG("bg.battleground", "BattlegroundQueue: Removing player GUID %u, from bracket_id %u", GUID_LOPART(guid), (uint32)bracket_id);

    // ALL variables are correctly set
    // We can ignore leveling up in queue - it should not cause crash
    // remove player from group
    // if only one player there, remove group

    // remove player queue info from group queue info
    std::map<uint64, PlayerQueueInfo*>::iterator pitr = group->Players.find(guid);
    if (pitr != group->Players.end())
        group->Players.erase(pitr);

    // if invited to bg, and should decrease invited count, then do it
    if (decreaseInvitedCount && group->IsInvitedToBGInstanceGUID)
        if (Battleground* bg = sBattlegroundMgr->GetBattleground(group->IsInvitedToBGInstanceGUID, group->BgTypeId))
            bg->DecreaseInvitedCount(group->Team);

    // remove player queue info
    m_QueuedPlayers.erase(itr);

    // announce to world if arena team left queue for rated match, show only once
    if (group->ArenaType && group->IsRated && group->Players.empty() && sWorld->getBoolConfig(CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE))
        if (ArenaTeam* Team = sArenaTeamMgr->GetArenaTeamById(group->ArenaTeamId))
            sWorld->SendWorldText(LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT, Team->GetName().c_str(), group->ArenaType, group->ArenaType, group->ArenaTeamRating);

    // if player leaves queue and he is invited to rated arena match, then he have to lose
    if (group->IsInvitedToBGInstanceGUID && group->IsRated && decreaseInvitedCount)
    {
        if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(group->ArenaTeamId))
        {
            TC_LOG_DEBUG("bg.battleground", "UPDATING memberLost's personal arena rating for %u by opponents rating: %u", GUID_LOPART(guid), group->OpponentsTeamRating);
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                at->MemberLost(player, group->OpponentsMatchmakerRating);
            else
                at->OfflineMemberLost(guid, group->OpponentsMatchmakerRating);
            at->SaveToDB();
        }
    }

    // remove group queue info if needed
    if (group->Players.empty())
    {
        m_QueuedGroups[bracket_id][index].erase(group_itr);
        delete group;
        return;
    }

    // if group wasn't empty, so it wasn't deleted, and player have left a rated
    // queue -> everyone from the group should leave too
    // don't remove recursively if already invited to bg!
    if (!group->IsInvitedToBGInstanceGUID && group->IsRated)
    {
        // remove next player, this is recursive
        // first send removal information
        if (Player* plr2 = ObjectAccessor::FindPlayer(group->Players.begin()->first))
        {
            Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(group->BgTypeId);
            BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(group->BgTypeId, group->ArenaType);
            uint32 queueSlot = plr2->GetBattlegroundQueueIndex(bgQueueTypeId);
            plr2->RemoveBattlegroundQueueId(bgQueueTypeId); // must be called this way, because if you move this call to
                                                            // queue->removeplayer, it causes bugs
            WorldPacket data;
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0, 0);
            plr2->GetSession()->SendPacket(&data);
        }
        // then actually delete, this may delete the group as well!
        RemovePlayer(group->Players.begin()->first, decreaseInvitedCount);
    }
}

//returns true when player pl_guid is in queue and is invited to bgInstanceGuid
bool BattlegroundQueue::IsPlayerInvited(uint64 pl_guid, const uint32 bgInstanceGuid, const uint32 removeTime)
{
    QueuedPlayersMap::const_iterator qItr = m_QueuedPlayers.find(pl_guid);
    return (qItr != m_QueuedPlayers.end()
        && qItr->second.GroupInfo->IsInvitedToBGInstanceGUID == bgInstanceGuid
        && qItr->second.GroupInfo->RemoveInviteTime == removeTime);
}

bool BattlegroundQueue::GetPlayerGroupInfoData(uint64 guid, GroupQueueInfo* ginfo)
{
    QueuedPlayersMap::const_iterator qItr = m_QueuedPlayers.find(guid);
    if (qItr == m_QueuedPlayers.end())
        return false;
    *ginfo = *(qItr->second.GroupInfo);
    return true;
}

uint32 BattlegroundQueue::GetPlayersInQueue(TeamId id)
{
    return m_SelectionPools[id].GetPlayerCount();
}

bool BattlegroundQueue::InviteGroupToBG(GroupQueueInfo* ginfo, Battleground* bg, uint32 side)
{
    // set side if needed
    if (side)
        ginfo->Team = side;

    if (!ginfo->IsInvitedToBGInstanceGUID)
    {
        // not yet invited
        // set invitation
        ginfo->IsInvitedToBGInstanceGUID = bg->GetInstanceID();
        BattlegroundTypeId bgTypeId = bg->GetTypeID();
        BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, bg->GetArenaType());
        BattlegroundBracketId bracket_id = bg->GetBracketId();

        // set ArenaTeamId for rated matches
        if (bg->isArena() && bg->isRated())
            bg->SetArenaTeamIdForTeam(ginfo->Team, ginfo->ArenaTeamId);

        ginfo->RemoveInviteTime = getMSTime() + INVITE_ACCEPT_WAIT_TIME;

        // loop through the players
        for (std::map<uint64, PlayerQueueInfo*>::iterator itr = ginfo->Players.begin(); itr != ginfo->Players.end(); ++itr)
        {
            // get the player
            Player* player = ObjectAccessor::FindPlayer(itr->first);
            // if offline, skip him, this should not happen - player is removed from queue when he logs out
            if (!player)
                continue;

            // invite the player
            PlayerInvitedToBGUpdateAverageWaitTime(ginfo, bracket_id);
            //sBattlegroundMgr->InvitePlayer(player, bg, ginfo->Team);

            // set invited player counters
            bg->IncreaseInvitedCount(ginfo->Team);

            player->SetInviteForBattlegroundQueueType(bgQueueTypeId, ginfo->IsInvitedToBGInstanceGUID);

            // create remind invite events
            BGQueueInviteEvent* inviteEvent = new BGQueueInviteEvent(player->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, ginfo->ArenaType, ginfo->RemoveInviteTime);
            m_events.AddEvent(inviteEvent, m_events.CalculateTime(INVITATION_REMIND_TIME));
            // create automatic remove events
            BGQueueRemoveEvent* removeEvent = new BGQueueRemoveEvent(player->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, bgQueueTypeId, ginfo->RemoveInviteTime);
            m_events.AddEvent(removeEvent, m_events.CalculateTime(INVITE_ACCEPT_WAIT_TIME));

            WorldPacket data;

            uint32 queueSlot = player->GetBattlegroundQueueIndex(bgQueueTypeId);

            TC_LOG_DEBUG("bg.battleground", "Battleground: invited player %s (%u) to BG instance %u queueindex %u bgtype %u",
                 player->GetName().c_str(), player->GetGUIDLow(), bg->GetInstanceID(), queueSlot, bg->GetTypeID());

            // send status packet
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_JOIN, INVITE_ACCEPT_WAIT_TIME, 0, ginfo->ArenaType, 0);
            player->GetSession()->SendPacket(&data);
        }
        return true;
    }

    return false;
}

/*
This function is inviting players to already running battlegrounds
Invitation type is based on config file
large groups are disadvantageous, because they will be kicked first if invitation type = 1
*/
void BattlegroundQueue::FillPlayersToBG(Battleground* bg, BattlegroundBracketId bracket_id)
{
    int32 hordeFree = bg->GetFreeSlotsForTeam(HORDE);
    int32 aliFree   = bg->GetFreeSlotsForTeam(ALLIANCE);

    //iterator for iterating through bg queue
    GroupsQueueType::const_iterator Ali_itr = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE].begin();
    //count of groups in queue - used to stop cycles
    uint32 aliCount = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE].size();
    //index to queue which group is current
    uint32 aliIndex = 0;
    for (; aliIndex < aliCount && m_SelectionPools[TEAM_ALLIANCE].AddGroup((*Ali_itr), aliFree); aliIndex++)
        ++Ali_itr;
    //the same thing for horde
    GroupsQueueType::const_iterator Horde_itr = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_HORDE].begin();
    uint32 hordeCount = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_HORDE].size();
    uint32 hordeIndex = 0;
    for (; hordeIndex < hordeCount && m_SelectionPools[TEAM_HORDE].AddGroup((*Horde_itr), hordeFree); hordeIndex++)
        ++Horde_itr;

    //if ofc like BG queue invitation is set in config, then we are happy
    if (sWorld->getIntConfig(CONFIG_BATTLEGROUND_INVITATION_TYPE) == 0)
        return;

    /*
    if we reached this code, then we have to solve NP - complete problem called Subset sum problem
    So one solution is to check all possible invitation subgroups, or we can use these conditions:
    1. Last time when BattlegroundQueue::Update was executed we invited all possible players - so there is only small possibility
        that we will invite now whole queue, because only 1 change has been made to queues from the last BattlegroundQueue::Update call
    2. Other thing we should consider is group order in queue
    */

    // At first we need to compare free space in bg and our selection pool
    int32 diffAli   = aliFree   - int32(m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount());
    int32 diffHorde = hordeFree - int32(m_SelectionPools[TEAM_HORDE].GetPlayerCount());
    while (abs(diffAli - diffHorde) > 1 && (m_SelectionPools[TEAM_HORDE].GetPlayerCount() > 0 || m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount() > 0))
    {
        //each cycle execution we need to kick at least 1 group
        if (diffAli < diffHorde)
        {
            //kick alliance group, add to pool new group if needed
            if (m_SelectionPools[TEAM_ALLIANCE].KickGroup(diffHorde - diffAli))
            {
                for (; aliIndex < aliCount && m_SelectionPools[TEAM_ALLIANCE].AddGroup((*Ali_itr), (aliFree >= diffHorde) ? aliFree - diffHorde : 0); aliIndex++)
                    ++Ali_itr;
            }
            //if ali selection is already empty, then kick horde group, but if there are less horde than ali in bg - break;
            if (!m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount())
            {
                if (aliFree <= diffHorde + 1)
                    break;
                m_SelectionPools[TEAM_HORDE].KickGroup(diffHorde - diffAli);
            }
        }
        else
        {
            //kick horde group, add to pool new group if needed
            if (m_SelectionPools[TEAM_HORDE].KickGroup(diffAli - diffHorde))
            {
                for (; hordeIndex < hordeCount && m_SelectionPools[TEAM_HORDE].AddGroup((*Horde_itr), (hordeFree >= diffAli) ? hordeFree - diffAli : 0); hordeIndex++)
                    ++Horde_itr;
            }
            if (!m_SelectionPools[TEAM_HORDE].GetPlayerCount())
            {
                if (hordeFree <= diffAli + 1)
                    break;
                m_SelectionPools[TEAM_ALLIANCE].KickGroup(diffAli - diffHorde);
            }
        }
        //count diffs after small update
        diffAli   = aliFree   - int32(m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount());
        diffHorde = hordeFree - int32(m_SelectionPools[TEAM_HORDE].GetPlayerCount());
    }
}

// this method checks if premade versus premade battleground is possible
// then after 30 mins (default) in queue it moves premade group to normal queue
// it tries to invite as much players as it can - to MaxPlayersPerTeam, because premade groups have more than MinPlayersPerTeam players
bool BattlegroundQueue::CheckPremadeMatch(BattlegroundBracketId bracket_id, uint32 MinPlayersPerTeam, uint32 MaxPlayersPerTeam)
{
    //check match
    if (!m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].empty() && !m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].empty())
    {
        //start premade match
        //if groups aren't invited
        GroupsQueueType::const_iterator ali_group, horde_group;
        for (ali_group = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].begin(); ali_group != m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].end(); ++ali_group)
            if (!(*ali_group)->IsInvitedToBGInstanceGUID)
                break;
        for (horde_group = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].begin(); horde_group != m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].end(); ++horde_group)
            if (!(*horde_group)->IsInvitedToBGInstanceGUID)
                break;

        if (ali_group != m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].end() && horde_group != m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].end())
        {
            m_SelectionPools[TEAM_ALLIANCE].AddGroup((*ali_group), MaxPlayersPerTeam);
            m_SelectionPools[TEAM_HORDE].AddGroup((*horde_group), MaxPlayersPerTeam);
            //add groups/players from normal queue to size of bigger group
            uint32 maxPlayers = std::min(m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount(), m_SelectionPools[TEAM_HORDE].GetPlayerCount());
            GroupsQueueType::const_iterator itr;
            for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
            {
                for (itr = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + i].begin(); itr != m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + i].end(); ++itr)
                {
                    //if itr can join BG and player count is less that maxPlayers, then add group to selectionpool
                    if (!(*itr)->IsInvitedToBGInstanceGUID && !m_SelectionPools[i].AddGroup((*itr), maxPlayers))
                        break;
                }
            }
            //premade selection pools are set
            return true;
        }
    }
    // now check if we can move group from Premade queue to normal queue (timer has expired) or group size lowered!!
    // this could be 2 cycles but i'm checking only first team in queue - it can cause problem -
    // if first is invited to BG and seconds timer expired, but we can ignore it, because players have only 80 seconds to click to enter bg
    // and when they click or after 80 seconds the queue info is removed from queue
    uint32 time_before = getMSTime() - sWorld->getIntConfig(CONFIG_BATTLEGROUND_PREMADE_GROUP_WAIT_FOR_MATCH);
    for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
    {
        if (!m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE + i].empty())
        {
            GroupsQueueType::iterator itr = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE + i].begin();
            if (!(*itr)->IsInvitedToBGInstanceGUID && ((*itr)->JoinTime < time_before || (*itr)->Players.size() < MinPlayersPerTeam))
            {
                //we must insert group to normal queue and erase pointer from premade queue
                m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + i].push_front((*itr));
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE + i].erase(itr);
            }
        }
    }
    //selection pools are not set
    return false;
}

// this method tries to create battleground or arena with MinPlayersPerTeam against MinPlayersPerTeam
bool BattlegroundQueue::CheckNormalMatch(Battleground* bg_template, BattlegroundBracketId bracket_id, uint32 minPlayers, uint32 maxPlayers)
{
    GroupsQueueType::const_iterator itr_team[BG_TEAMS_COUNT];
    for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
    {
        itr_team[i] = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + i].begin();
        for (; itr_team[i] != m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + i].end(); ++(itr_team[i]))
        {
            if (!(*(itr_team[i]))->IsInvitedToBGInstanceGUID)
            {
                m_SelectionPools[i].AddGroup(*(itr_team[i]), maxPlayers);
                if (m_SelectionPools[i].GetPlayerCount() >= minPlayers)
                    break;
            }
        }
    }
    //try to invite same number of players - this cycle may cause longer wait time even if there are enough players in queue, but we want ballanced bg
    uint32 j = TEAM_ALLIANCE;
    if (m_SelectionPools[TEAM_HORDE].GetPlayerCount() < m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount())
        j = TEAM_HORDE;
    if (sWorld->getIntConfig(CONFIG_BATTLEGROUND_INVITATION_TYPE) != 0
        && m_SelectionPools[TEAM_HORDE].GetPlayerCount() >= minPlayers && m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount() >= minPlayers)
    {
        //we will try to invite more groups to team with less players indexed by j
        ++(itr_team[j]);                                         //this will not cause a crash, because for cycle above reached break;
        for (; itr_team[j] != m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + j].end(); ++(itr_team[j]))
        {
            if (!(*(itr_team[j]))->IsInvitedToBGInstanceGUID)
                if (!m_SelectionPools[j].AddGroup(*(itr_team[j]), m_SelectionPools[(j + 1) % BG_TEAMS_COUNT].GetPlayerCount()))
                    break;
        }
        // do not allow to start bg with more than 2 players more on 1 faction
        if (abs((int32)(m_SelectionPools[TEAM_HORDE].GetPlayerCount() - m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount())) > 2)
            return false;
    }
    //allow 1v0 if debug bg
    if (sBattlegroundMgr->isTesting() && bg_template->isBattleground() && (m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount() || m_SelectionPools[TEAM_HORDE].GetPlayerCount()))
        return true;
    //return true if there are enough players in selection pools - enable to work .debug bg command correctly
    return m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount() >= minPlayers && m_SelectionPools[TEAM_HORDE].GetPlayerCount() >= minPlayers;
}

// this method will check if we can invite players to same faction skirmish match
bool BattlegroundQueue::CheckSkirmishForSameFaction(BattlegroundBracketId bracket_id, uint32 minPlayersPerTeam)
{
    if (m_SelectionPools[TEAM_ALLIANCE].GetPlayerCount() < minPlayersPerTeam && m_SelectionPools[TEAM_HORDE].GetPlayerCount() < minPlayersPerTeam)
        return false;
    uint32 teamIndex = TEAM_ALLIANCE;
    uint32 otherTeam = TEAM_HORDE;
    uint32 otherTeamId = HORDE;
    if (m_SelectionPools[TEAM_HORDE].GetPlayerCount() == minPlayersPerTeam)
    {
        teamIndex = TEAM_HORDE;
        otherTeam = TEAM_ALLIANCE;
        otherTeamId = ALLIANCE;
    }
    //clear other team's selection
    m_SelectionPools[otherTeam].Init();
    //store last ginfo pointer
    GroupQueueInfo* ginfo = m_SelectionPools[teamIndex].SelectedGroups.back();
    //set itr_team to group that was added to selection pool latest
    GroupsQueueType::iterator itr_team = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + teamIndex].begin();
    for (; itr_team != m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + teamIndex].end(); ++itr_team)
        if (ginfo == *itr_team)
            break;
    if (itr_team == m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + teamIndex].end())
        return false;
    GroupsQueueType::iterator itr_team2 = itr_team;
    ++itr_team2;
    //invite players to other selection pool
    for (; itr_team2 != m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + teamIndex].end(); ++itr_team2)
    {
        //if selection pool is full then break;
        if (!(*itr_team2)->IsInvitedToBGInstanceGUID && !m_SelectionPools[otherTeam].AddGroup(*itr_team2, minPlayersPerTeam))
            break;
    }
    if (m_SelectionPools[otherTeam].GetPlayerCount() != minPlayersPerTeam)
        return false;

    //here we have correct 2 selections and we need to change one teams team and move selection pool teams to other team's queue
    for (GroupsQueueType::iterator itr = m_SelectionPools[otherTeam].SelectedGroups.begin(); itr != m_SelectionPools[otherTeam].SelectedGroups.end(); ++itr)
    {
        //set correct team
        (*itr)->Team = otherTeamId;
        //add team to other queue
        m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + otherTeam].push_front(*itr);
        //remove team from old queue
        GroupsQueueType::iterator itr2 = itr_team;
        ++itr2;
        for (; itr2 != m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + teamIndex].end(); ++itr2)
        {
            if (*itr2 == *itr)
            {
                m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE + teamIndex].erase(itr2);
                break;
            }
        }
    }
    return true;
}

void BattlegroundQueue::UpdateEvents(uint32 diff)
{
    m_events.Update(diff);
}

/*
this method is called when group is inserted, or player / group is removed from BG Queue - there is only one player's status changed, so we don't use while (true) cycles to invite whole queue
it must be called after fully adding the members of a group to ensure group joining
should be called from Battleground::RemovePlayer function in some cases
*/
void BattlegroundQueue::BattlegroundQueueUpdate(uint32 /*diff*/, BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id, uint8 arenaType, bool isRated, uint32 arenaRating)
{
    //if no players in queue - do nothing
    if (m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].empty() &&
        m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].empty() &&
        m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE].empty() &&
        m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_HORDE].empty())
        return;

    // battleground with free slot for player should be always in the beggining of the queue
    // maybe it would be better to create bgfreeslotqueue for each bracket_id
    BGFreeSlotQueueContainer& bgQueues = sBattlegroundMgr->GetBGFreeSlotQueueStore(bgTypeId);
    for (BGFreeSlotQueueContainer::iterator itr = bgQueues.begin(); itr != bgQueues.end();)
    {
        Battleground* bg = *itr; ++itr;
        // DO NOT allow queue manager to invite new player to rated games
        if (!bg->isRated() && bg->GetTypeID() == bgTypeId && bg->GetBracketId() == bracket_id &&
            bg->GetStatus() > STATUS_WAIT_QUEUE && bg->GetStatus() < STATUS_WAIT_LEAVE)
        {
            // clear selection pools
            m_SelectionPools[TEAM_ALLIANCE].Init();
            m_SelectionPools[TEAM_HORDE].Init();

            // call a function that does the job for us
            FillPlayersToBG(bg, bracket_id);

            // now everything is set, invite players
            for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_ALLIANCE].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_ALLIANCE].SelectedGroups.end(); ++citr)
                InviteGroupToBG((*citr), bg, (*citr)->Team);

            for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_HORDE].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_HORDE].SelectedGroups.end(); ++citr)
                InviteGroupToBG((*citr), bg, (*citr)->Team);

            if (!bg->HasFreeSlots())
                bg->RemoveFromBGFreeSlotQueue();
        }
    }

    // finished iterating through the bgs with free slots, maybe we need to create a new bg

    Battleground* bg_template = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
    if (!bg_template)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground: Update: bg template not found for %u", bgTypeId);
        return;
    }

    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketById(bg_template->GetMapId(), bracket_id);
    if (!bracketEntry)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground: Update: bg bracket entry not found for map %u bracket id %u", bg_template->GetMapId(), bracket_id);
        return;
    }

    // get the min. players per team, properly for larger arenas as well. (must have full teams for arena matches!)
    uint32 MinPlayersPerTeam = bg_template->GetMinPlayersPerTeam();
    uint32 MaxPlayersPerTeam = bg_template->GetMaxPlayersPerTeam();

    if (bg_template->isArena())
    {
        MaxPlayersPerTeam = arenaType;
        MinPlayersPerTeam = sBattlegroundMgr->isArenaTesting() ? 1 : arenaType;
    }
    else if (sBattlegroundMgr->isTesting())
        MinPlayersPerTeam = 1;

    m_SelectionPools[TEAM_ALLIANCE].Init();
    m_SelectionPools[TEAM_HORDE].Init();

    if (bg_template->isBattleground())
    {
        if (CheckPremadeMatch(bracket_id, MinPlayersPerTeam, MaxPlayersPerTeam))
        {
            // create new battleground
            Battleground* bg2 = sBattlegroundMgr->CreateNewBattleground(bgTypeId, bracketEntry, 0, false);
            if (!bg2)
            {
                TC_LOG_ERROR("bg.battleground", "BattlegroundQueue::Update - Cannot create battleground: %u", bgTypeId);
                return;
            }
            // invite those selection pools
            for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
                for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.end(); ++citr)
                    InviteGroupToBG((*citr), bg2, (*citr)->Team);

            bg2->StartBattleground();
            //clear structures
            m_SelectionPools[TEAM_ALLIANCE].Init();
            m_SelectionPools[TEAM_HORDE].Init();
        }
    }

    // now check if there are in queues enough players to start new game of (normal battleground, or non-rated arena)
    if (!isRated)
    {
        // if there are enough players in pools, start new battleground or non rated arena
        if (CheckNormalMatch(bg_template, bracket_id, MinPlayersPerTeam, MaxPlayersPerTeam)
            || (bg_template->isArena() && CheckSkirmishForSameFaction(bracket_id, MinPlayersPerTeam)))
        {
            // we successfully created a pool
            Battleground* bg2 = sBattlegroundMgr->CreateNewBattleground(bgTypeId, bracketEntry, arenaType, false);
            if (!bg2)
            {
                TC_LOG_ERROR("bg.battleground", "BattlegroundQueue::Update - Cannot create battleground: %u", bgTypeId);
                return;
            }

            // invite those selection pools
            for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
                for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.end(); ++citr)
                    InviteGroupToBG((*citr), bg2, (*citr)->Team);
            // start bg
            bg2->StartBattleground();
        }
    }
    else if (bg_template->isArena())
    {
        // found out the minimum and maximum ratings the newly added team should battle against
        // arenaRating is the rating of the latest joined team, or 0
        // 0 is on (automatic update call) and we must set it to team's with longest wait time
        if (!arenaRating)
        {
            GroupQueueInfo* front1 = NULL;
            GroupQueueInfo* front2 = NULL;
            if (!m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].empty())
            {
                front1 = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].front();
                arenaRating = front1->ArenaMatchmakerRating;
            }
            if (!m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].empty())
            {
                front2 = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].front();
                arenaRating = front2->ArenaMatchmakerRating;
            }
            if (front1 && front2)
            {
                if (front1->JoinTime < front2->JoinTime)
                    arenaRating = front1->ArenaMatchmakerRating;
            }
            else if (!front1 && !front2)
                return; //queues are empty
        }

        //set rating range
        uint32 arenaMinRating = (arenaRating <= sBattlegroundMgr->GetMaxRatingDifference()) ? 0 : arenaRating - sBattlegroundMgr->GetMaxRatingDifference();
        uint32 arenaMaxRating = arenaRating + sBattlegroundMgr->GetMaxRatingDifference();
        // if max rating difference is set and the time past since server startup is greater than the rating discard time
        // (after what time the ratings aren't taken into account when making teams) then
        // the discard time is current_time - time_to_discard, teams that joined after that, will have their ratings taken into account
        // else leave the discard time on 0, this way all ratings will be discarded
        uint32 discardTime = getMSTime() - sBattlegroundMgr->GetRatingDiscardTimer();

        // we need to find 2 teams which will play next game
        GroupsQueueType::iterator itr_teams[BG_TEAMS_COUNT];
        uint8 found = 0;
        uint8 team = 0;

        for (uint8 i = BG_QUEUE_PREMADE_ALLIANCE; i < BG_QUEUE_NORMAL_ALLIANCE; i++)
        {
            // take the group that joined first
            GroupsQueueType::iterator itr2 = m_QueuedGroups[bracket_id][i].begin();
            for (; itr2 != m_QueuedGroups[bracket_id][i].end(); ++itr2)
            {
                // if group match conditions, then add it to pool
                if (!(*itr2)->IsInvitedToBGInstanceGUID
                    && (((*itr2)->ArenaMatchmakerRating >= arenaMinRating && (*itr2)->ArenaMatchmakerRating <= arenaMaxRating)
                        || (*itr2)->JoinTime < discardTime))
                {
                    itr_teams[found++] = itr2;
                    team = i;
                    break;
                }
            }
        }

        if (!found)
            return;

        if (found == 1)
        {
            for (GroupsQueueType::iterator itr3 = itr_teams[0]; itr3 != m_QueuedGroups[bracket_id][team].end(); ++itr3)
            {
                if (!(*itr3)->IsInvitedToBGInstanceGUID
                    && (((*itr3)->ArenaMatchmakerRating >= arenaMinRating && (*itr3)->ArenaMatchmakerRating <= arenaMaxRating)
                        || (*itr3)->JoinTime < discardTime)
                    && (*itr_teams[0])->ArenaTeamId != (*itr3)->ArenaTeamId)
                {
                    itr_teams[found++] = itr3;
                    break;
                }
            }
        }

        //if we have 2 teams, then start new arena and invite players!
        if (found == 2)
        {
            GroupQueueInfo* aTeam = *itr_teams[TEAM_ALLIANCE];
            GroupQueueInfo* hTeam = *itr_teams[TEAM_HORDE];
            Battleground* arena = sBattlegroundMgr->CreateNewBattleground(bgTypeId, bracketEntry, arenaType, true);
            if (!arena)
            {
                TC_LOG_ERROR("bg.battleground", "BattlegroundQueue::Update couldn't create arena instance for rated arena match!");
                return;
            }

            aTeam->OpponentsTeamRating = hTeam->ArenaTeamRating;
            hTeam->OpponentsTeamRating = aTeam->ArenaTeamRating;
            aTeam->OpponentsMatchmakerRating = hTeam->ArenaMatchmakerRating;
            hTeam->OpponentsMatchmakerRating = aTeam->ArenaMatchmakerRating;
            TC_LOG_DEBUG("bg.battleground", "setting oposite teamrating for team %u to %u", aTeam->ArenaTeamId, aTeam->OpponentsTeamRating);
            TC_LOG_DEBUG("bg.battleground", "setting oposite teamrating for team %u to %u", hTeam->ArenaTeamId, hTeam->OpponentsTeamRating);

            // now we must move team if we changed its faction to another faction queue, because then we will spam log by errors in Queue::RemovePlayer
            if (aTeam->Team != ALLIANCE)
            {
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].push_front(aTeam);
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].erase(itr_teams[TEAM_ALLIANCE]);
            }
            if (hTeam->Team != HORDE)
            {
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].push_front(hTeam);
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].erase(itr_teams[TEAM_HORDE]);
            }

            arena->SetArenaMatchmakerRating(ALLIANCE, aTeam->ArenaMatchmakerRating);
            arena->SetArenaMatchmakerRating(   HORDE, hTeam->ArenaMatchmakerRating);
            InviteGroupToBG(aTeam, arena, ALLIANCE);
            InviteGroupToBG(hTeam, arena, HORDE);

            TC_LOG_DEBUG("bg.battleground", "Starting rated arena match!");
            arena->StartBattleground();
        }
    }
}

/*********************************************************/
/***            BATTLEGROUND QUEUE EVENTS              ***/
/*********************************************************/

bool BGQueueInviteEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    Player* player = ObjectAccessor::FindPlayer(m_PlayerGuid);
    // player logged off (we should do nothing, he is correctly removed from queue in another procedure)
    if (!player)
        return true;

    Battleground* bg = sBattlegroundMgr->GetBattleground(m_BgInstanceGUID, m_BgTypeId);
    //if battleground ended and its instance deleted - do nothing
    if (!bg)
        return true;

    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bg->GetTypeID(), bg->GetArenaType());
    uint32 queueSlot = player->GetBattlegroundQueueIndex(bgQueueTypeId);
    if (queueSlot < PLAYER_MAX_BATTLEGROUND_QUEUES)         // player is in queue or in battleground
    {
        // check if player is invited to this bg
        BattlegroundQueue &bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        if (bgQueue.IsPlayerInvited(m_PlayerGuid, m_BgInstanceGUID, m_RemoveTime))
        {
            WorldPacket data;
            //we must send remaining time in queue
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_JOIN, INVITE_ACCEPT_WAIT_TIME - INVITATION_REMIND_TIME, 0, m_ArenaType, 0);
            player->GetSession()->SendPacket(&data);
        }
    }
    return true;                                            //event will be deleted
}

void BGQueueInviteEvent::Abort(uint64 /*e_time*/)
{
    //do nothing
}

/*
    this event has many possibilities when it is executed:
    1. player is in battleground (he clicked enter on invitation window)
    2. player left battleground queue and he isn't there any more
    3. player left battleground queue and he joined it again and IsInvitedToBGInstanceGUID = 0
    4. player left queue and he joined again and he has been invited to same battleground again -> we should not remove him from queue yet
    5. player is invited to bg and he didn't choose what to do and timer expired - only in this condition we should call queue::RemovePlayer
    we must remove player in the 5. case even if battleground object doesn't exist!
*/
bool BGQueueRemoveEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    Player* player = ObjectAccessor::FindPlayer(m_PlayerGuid);
    if (!player)
        // player logged off (we should do nothing, he is correctly removed from queue in another procedure)
        return true;

    Battleground* bg = sBattlegroundMgr->GetBattleground(m_BgInstanceGUID, m_BgTypeId);
    //battleground can be deleted already when we are removing queue info
    //bg pointer can be NULL! so use it carefully!

    uint32 queueSlot = player->GetBattlegroundQueueIndex(m_BgQueueTypeId);
    if (queueSlot < PLAYER_MAX_BATTLEGROUND_QUEUES)         // player is in queue, or in Battleground
    {
        // check if player is in queue for this BG and if we are removing his invite event
        BattlegroundQueue &bgQueue = sBattlegroundMgr->GetBattlegroundQueue(m_BgQueueTypeId);
        if (bgQueue.IsPlayerInvited(m_PlayerGuid, m_BgInstanceGUID, m_RemoveTime))
        {
            TC_LOG_DEBUG("bg.battleground", "Battleground: removing player %u from bg queue for instance %u because of not pressing enter battle in time.", player->GetGUIDLow(), m_BgInstanceGUID);

            player->RemoveBattlegroundQueueId(m_BgQueueTypeId);
            bgQueue.RemovePlayer(m_PlayerGuid, true);
            //update queues if battleground isn't ended
            if (bg && bg->isBattleground() && bg->GetStatus() != STATUS_WAIT_LEAVE)
                sBattlegroundMgr->ScheduleQueueUpdate(0, 0, m_BgQueueTypeId, m_BgTypeId, bg->GetBracketId());

            WorldPacket data;
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0, 0);
            player->GetSession()->SendPacket(&data);
        }
    }

    //event will be deleted
    return true;
}

void BGQueueRemoveEvent::Abort(uint64 /*e_time*/)
{
    //do nothing
}
