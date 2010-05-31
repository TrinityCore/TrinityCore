/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "ObjectMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "Policies/SingletonImp.h"

#include "ArenaTeam.h"
#include "BattleGroundMgr.h"
#include "BattleGroundAV.h"
#include "BattleGroundAB.h"
#include "BattleGroundEY.h"
#include "BattleGroundWS.h"
#include "BattleGroundNA.h"
#include "BattleGroundBE.h"
#include "BattleGroundAA.h"
#include "BattleGroundRL.h"
#include "BattleGroundSA.h"
#include "BattleGroundDS.h"
#include "BattleGroundRV.h"
#include "BattleGroundIC.h"
#include "BattleGroundRB.h"
#include "Chat.h"
#include "Map.h"
#include "MapInstanced.h"
#include "MapManager.h"
#include "Player.h"
#include "GameEventMgr.h"
#include "ProgressBar.h"
#include "SharedDefines.h"
#include "Formulas.h"

INSTANTIATE_SINGLETON_1(BattleGroundMgr);

/*********************************************************/
/***            BATTLEGROUND QUEUE SYSTEM              ***/
/*********************************************************/

BattleGroundQueue::BattleGroundQueue()
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

BattleGroundQueue::~BattleGroundQueue()
{
    m_QueuedPlayers.clear();
    for (int i = 0; i < MAX_BATTLEGROUND_BRACKETS; ++i)
    {
        for (uint32 j = 0; j < BG_QUEUE_GROUP_TYPES_COUNT; ++j)
        {
            for (GroupsQueueType::iterator itr = m_QueuedGroups[i][j].begin(); itr!= m_QueuedGroups[i][j].end(); ++itr)
                delete (*itr);
            m_QueuedGroups[i][j].clear();
        }
    }
}

/*********************************************************/
/***      BATTLEGROUND QUEUE SELECTION POOLS           ***/
/*********************************************************/

// selection pool initialization, used to clean up from prev selection
void BattleGroundQueue::SelectionPool::Init()
{
    SelectedGroups.clear();
    PlayerCount = 0;
}

// remove group info from selection pool
// returns true when we need to try to add new group to selection pool
// returns false when selection pool is ok or when we kicked smaller group than we need to kick
// sometimes it can be called on empty selection pool
bool BattleGroundQueue::SelectionPool::KickGroup(uint32 size)
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
bool BattleGroundQueue::SelectionPool::AddGroup(GroupQueueInfo *ginfo, uint32 desiredCount)
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
GroupQueueInfo * BattleGroundQueue::AddGroup(Player *leader, Group* grp, BattleGroundTypeId BgTypeId, PvPDifficultyEntry const*  backetEntry, uint8 ArenaType, bool isRated, bool isPremade, uint32 arenaRating, uint32 arenateamid)
{
    BattleGroundBracketId bracketId =  backetEntry->GetBracketId();

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
    ginfo->ArenaTeamRating           = arenaRating;
    ginfo->OpponentsTeamRating       = 0;

    ginfo->Players.clear();

    //compute index (if group is premade or joined a rated match) to queues
    uint32 index = 0;
    if (!isRated && !isPremade)
        index += BG_TEAMS_COUNT;
    if (ginfo->Team == HORDE)
        index++;
    sLog.outDebug("Adding Group to BattleGroundQueue bgTypeId : %u, bracket_id : %u, index : %u", BgTypeId, bracketId, index);

    uint32 lastOnlineTime = getMSTime();

    //announce world (this don't need mutex)
    if (isRated && sWorld.getConfig(CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE))
    {
        ArenaTeam *Team = objmgr.GetArenaTeamById(arenateamid);
        if (Team)
            sWorld.SendWorldText(LANG_ARENA_QUEUE_ANNOUNCE_WORLD_JOIN, Team->GetName().c_str(), ginfo->ArenaType, ginfo->ArenaType, ginfo->ArenaTeamRating);
    }

    //add players from group to ginfo
    {
        //ACE_Guard<ACE_Recursive_Thread_Mutex> guard(m_Lock);
        if (grp)
        {
            for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player *member = itr->getSource();
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
        m_QueuedGroups[bracketId][index].push_back(ginfo);

        //announce to world, this code needs mutex
        if (!isRated && !isPremade && sWorld.getConfig(CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_ENABLE))
        {
            if (BattleGround* bg = sBattleGroundMgr.GetBattleGroundTemplate(ginfo->BgTypeId))
            {
                char const* bgName = bg->GetName();
                uint32 MinPlayers = bg->GetMinPlayersPerTeam();
                uint32 qHorde = 0;
                uint32 qAlliance = 0;
                uint32 q_min_level = backetEntry->minLevel;
                uint32 q_max_level = backetEntry->maxLevel;
                GroupsQueueType::const_iterator itr;
                for (itr = m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_ALLIANCE].begin(); itr != m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_ALLIANCE].end(); ++itr)
                    if (!(*itr)->IsInvitedToBGInstanceGUID)
                        qAlliance += (*itr)->Players.size();
                for (itr = m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_HORDE].begin(); itr != m_QueuedGroups[bracketId][BG_QUEUE_NORMAL_HORDE].end(); ++itr)
                    if (!(*itr)->IsInvitedToBGInstanceGUID)
                        qHorde += (*itr)->Players.size();

                // Show queue status to player only (when joining queue)
                if (sWorld.getConfig(CONFIG_BATTLEGROUND_QUEUE_ANNOUNCER_PLAYERONLY))
                {
                    ChatHandler(leader).PSendSysMessage(LANG_BG_QUEUE_ANNOUNCE_SELF, bgName, q_min_level, q_max_level,
                        qAlliance, (MinPlayers > qAlliance) ? MinPlayers - qAlliance : (uint32)0, qHorde, (MinPlayers > qHorde) ? MinPlayers - qHorde : (uint32)0);
                }
                // System message
                else
                {
                    sWorld.SendWorldText(LANG_BG_QUEUE_ANNOUNCE_WORLD, bgName, q_min_level, q_max_level,
                        qAlliance, (MinPlayers > qAlliance) ? MinPlayers - qAlliance : (uint32)0, qHorde, (MinPlayers > qHorde) ? MinPlayers - qHorde : (uint32)0);
                }
            }
        }
        //release mutex
    }

    return ginfo;
}

void BattleGroundQueue::PlayerInvitedToBGUpdateAverageWaitTime(GroupQueueInfo* ginfo, BattleGroundBracketId bracket_id)
{
    uint32 timeInQueue = getMSTimeDiff(ginfo->JoinTime, getMSTime());
    uint8 team_index = BG_TEAM_ALLIANCE;                    //default set to BG_TEAM_ALLIANCE - or non rated arenas!
    if (!ginfo->ArenaType)
    {
        if (ginfo->Team == HORDE)
            team_index = BG_TEAM_HORDE;
    }
    else
    {
        if (ginfo->IsRated)
            team_index = BG_TEAM_HORDE;                     //for rated arenas use BG_TEAM_HORDE
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

uint32 BattleGroundQueue::GetAverageQueueWaitTime(GroupQueueInfo* ginfo, BattleGroundBracketId bracket_id)
{
    uint8 team_index = BG_TEAM_ALLIANCE;                    //default set to BG_TEAM_ALLIANCE - or non rated arenas!
    if (!ginfo->ArenaType)
    {
        if (ginfo->Team == HORDE)
            team_index = BG_TEAM_HORDE;
    }
    else
    {
        if (ginfo->IsRated)
            team_index = BG_TEAM_HORDE;                     //for rated arenas use BG_TEAM_HORDE
    }
    //check if there is enought values(we always add values > 0)
    if (m_WaitTimes[team_index][bracket_id][COUNT_OF_PLAYERS_TO_AVERAGE_WAIT_TIME - 1])
        return (m_SumOfWaitTimes[team_index][bracket_id] / COUNT_OF_PLAYERS_TO_AVERAGE_WAIT_TIME);
    else
        //if there aren't enough values return 0 - not available
        return 0;
}

//remove player from queue and from group info, if group info is empty then remove it too
void BattleGroundQueue::RemovePlayer(const uint64& guid, bool decreaseInvitedCount)
{
    //Player *plr = objmgr.GetPlayer(guid);

    int32 bracket_id = -1;                                     // signed for proper for-loop finish
    QueuedPlayersMap::iterator itr;

    //remove player from map, if he's there
    itr = m_QueuedPlayers.find(guid);
    if (itr == m_QueuedPlayers.end())
    {
        sLog.outError("BattleGroundQueue: couldn't find player to remove GUID: %u", GUID_LOPART(guid));
        return;
    }

    GroupQueueInfo* group = itr->second.GroupInfo;
    GroupsQueueType::iterator group_itr, group_itr_tmp;
    // mostly people with the highest levels are in battlegrounds, thats why
    // we count from MAX_BATTLEGROUND_QUEUES - 1 to 0
    // variable index removes useless searching in other team's queue
    uint32 index = (group->Team == HORDE) ? BG_TEAM_HORDE : BG_TEAM_ALLIANCE;

    for (int32 bracket_id_tmp = MAX_BATTLEGROUND_BRACKETS - 1; bracket_id_tmp >= 0 && bracket_id == -1; --bracket_id_tmp)
    {
        //we must check premade and normal team's queue - because when players from premade are joining bg,
        //they leave groupinfo so we can't use its players size to find out index
        for (uint32 j = index; j < BG_QUEUE_GROUP_TYPES_COUNT; j += BG_QUEUE_NORMAL_ALLIANCE)
        {
            for (group_itr_tmp = m_QueuedGroups[bracket_id_tmp][j].begin(); group_itr_tmp != m_QueuedGroups[bracket_id_tmp][j].end(); ++group_itr_tmp)
            {
                if ((*group_itr_tmp) == group)
                {
                    bracket_id = bracket_id_tmp;
                    group_itr = group_itr_tmp;
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
        sLog.outError("BattleGroundQueue: ERROR Cannot find groupinfo for player GUID: %u", GUID_LOPART(guid));
        return;
    }
    sLog.outDebug("BattleGroundQueue: Removing player GUID %u, from bracket_id %u", GUID_LOPART(guid), (uint32)bracket_id);

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
    {
        BattleGround* bg = sBattleGroundMgr.GetBattleGround(group->IsInvitedToBGInstanceGUID, group->BgTypeId);
        if (bg)
            bg->DecreaseInvitedCount(group->Team);
    }

    // remove player queue info
    m_QueuedPlayers.erase(itr);

    // announce to world if arena team left queue for rated match, show only once
    if (group->ArenaType && group->IsRated && group->Players.empty() && sWorld.getConfig(CONFIG_ARENA_QUEUE_ANNOUNCER_ENABLE))
    {
        ArenaTeam *Team = objmgr.GetArenaTeamById(group->ArenaTeamId);
        if (Team)
            sWorld.SendWorldText(LANG_ARENA_QUEUE_ANNOUNCE_WORLD_EXIT, Team->GetName().c_str(), group->ArenaType, group->ArenaType, group->ArenaTeamRating);
    }

    //if player leaves queue and he is invited to rated arena match, then he have to loose
    if (group->IsInvitedToBGInstanceGUID && group->IsRated && decreaseInvitedCount)
    {
        ArenaTeam * at = objmgr.GetArenaTeamById(group->ArenaTeamId);
        if (at)
        {
            sLog.outDebug("UPDATING memberLost's personal arena rating for %u by opponents rating: %u", GUID_LOPART(guid), group->OpponentsTeamRating);
            Player *plr = objmgr.GetPlayer(guid);
            if (plr)
                at->MemberLost(plr, group->OpponentsTeamRating);
            else
                at->OfflineMemberLost(guid, group->OpponentsTeamRating);
            at->SaveToDB();
        }
    }

    // remove group queue info if needed
    if (group->Players.empty())
    {
        m_QueuedGroups[bracket_id][index].erase(group_itr);
        delete group;
    }
    // if group wasn't empty, so it wasn't deleted, and player have left a rated
    // queue -> everyone from the group should leave too
    // don't remove recursively if already invited to bg!
    else if (!group->IsInvitedToBGInstanceGUID && group->IsRated)
    {
        // remove next player, this is recursive
        // first send removal information
        if (Player *plr2 = objmgr.GetPlayer(group->Players.begin()->first))
        {
            BattleGround * bg = sBattleGroundMgr.GetBattleGroundTemplate(group->BgTypeId);
            BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(group->BgTypeId, group->ArenaType);
            uint32 queueSlot = plr2->GetBattleGroundQueueIndex(bgQueueTypeId);
            plr2->RemoveBattleGroundQueueId(bgQueueTypeId); // must be called this way, because if you move this call to
                                                            // queue->removeplayer, it causes bugs
            WorldPacket data;
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0);
            plr2->GetSession()->SendPacket(&data);
        }
        // then actually delete, this may delete the group as well!
        RemovePlayer(group->Players.begin()->first, decreaseInvitedCount);
    }
}

//returns true when player pl_guid is in queue and is invited to bgInstanceGuid
bool BattleGroundQueue::IsPlayerInvited(const uint64& pl_guid, const uint32 bgInstanceGuid, const uint32 removeTime)
{
    QueuedPlayersMap::const_iterator qItr = m_QueuedPlayers.find(pl_guid);
    return (qItr != m_QueuedPlayers.end()
        && qItr->second.GroupInfo->IsInvitedToBGInstanceGUID == bgInstanceGuid
        && qItr->second.GroupInfo->RemoveInviteTime == removeTime);
}

bool BattleGroundQueue::GetPlayerGroupInfoData(const uint64& guid, GroupQueueInfo* ginfo)
{
    QueuedPlayersMap::const_iterator qItr = m_QueuedPlayers.find(guid);
    if (qItr == m_QueuedPlayers.end())
        return false;
    *ginfo = *(qItr->second.GroupInfo);
    return true;
}

bool BattleGroundQueue::InviteGroupToBG(GroupQueueInfo * ginfo, BattleGround * bg, uint32 side)
{
    // set side if needed
    if (side)
        ginfo->Team = side;

    if (!ginfo->IsInvitedToBGInstanceGUID)
    {
        // not yet invited
        // set invitation
        ginfo->IsInvitedToBGInstanceGUID = bg->GetInstanceID();
        BattleGroundTypeId bgTypeId = bg->GetTypeID();
        BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(bgTypeId, bg->GetArenaType());
        BattleGroundBracketId bracket_id = bg->GetBracketId();

        // set ArenaTeamId for rated matches
        if (bg->isArena() && bg->isRated())
            bg->SetArenaTeamIdForTeam(ginfo->Team, ginfo->ArenaTeamId);

        ginfo->RemoveInviteTime = getMSTime() + INVITE_ACCEPT_WAIT_TIME;

        // loop through the players
        for (std::map<uint64,PlayerQueueInfo*>::iterator itr = ginfo->Players.begin(); itr != ginfo->Players.end(); ++itr)
        {
            // get the player
            Player* plr = objmgr.GetPlayer(itr->first);
            // if offline, skip him, this should not happen - player is removed from queue when he logs out
            if (!plr)
                continue;

            // invite the player
            PlayerInvitedToBGUpdateAverageWaitTime(ginfo, bracket_id);
            //sBattleGroundMgr.InvitePlayer(plr, bg, ginfo->Team);

            // set invited player counters
            bg->IncreaseInvitedCount(ginfo->Team);

            plr->SetInviteForBattleGroundQueueType(bgQueueTypeId, ginfo->IsInvitedToBGInstanceGUID);

            // create remind invite events
            BGQueueInviteEvent* inviteEvent = new BGQueueInviteEvent(plr->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, ginfo->ArenaType, ginfo->RemoveInviteTime);
            plr->m_Events.AddEvent(inviteEvent, plr->m_Events.CalculateTime(INVITATION_REMIND_TIME));
            // create automatic remove events
            BGQueueRemoveEvent* removeEvent = new BGQueueRemoveEvent(plr->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, bgQueueTypeId, ginfo->RemoveInviteTime);
            plr->m_Events.AddEvent(removeEvent, plr->m_Events.CalculateTime(INVITE_ACCEPT_WAIT_TIME));

            WorldPacket data;

            uint32 queueSlot = plr->GetBattleGroundQueueIndex(bgQueueTypeId);

            sLog.outDebug("Battleground: invited plr %s (%u) to BG instance %u queueindex %u bgtype %u, I can't help it if they don't press the enter battle button.",plr->GetName(),plr->GetGUIDLow(),bg->GetInstanceID(),queueSlot,bg->GetTypeID());

            // send status packet
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_JOIN, INVITE_ACCEPT_WAIT_TIME, 0, ginfo->ArenaType);
            plr->GetSession()->SendPacket(&data);
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
void BattleGroundQueue::FillPlayersToBG(BattleGround* bg, BattleGroundBracketId bracket_id)
{
    int32 hordeFree = bg->GetFreeSlotsForTeam(HORDE);
    int32 aliFree   = bg->GetFreeSlotsForTeam(ALLIANCE);

    //iterator for iterating through bg queue
    GroupsQueueType::const_iterator Ali_itr = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE].begin();
    //count of groups in queue - used to stop cycles
    uint32 aliCount = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE].size();
    //index to queue which group is current
    uint32 aliIndex = 0;
    for (; aliIndex < aliCount && m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*Ali_itr), aliFree); aliIndex++)
        ++Ali_itr;
    //the same thing for horde
    GroupsQueueType::const_iterator Horde_itr = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_HORDE].begin();
    uint32 hordeCount = m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_HORDE].size();
    uint32 hordeIndex = 0;
    for (; hordeIndex < hordeCount && m_SelectionPools[BG_TEAM_HORDE].AddGroup((*Horde_itr), hordeFree); hordeIndex++)
        ++Horde_itr;

    //if ofc like BG queue invitation is set in config, then we are happy
    if (sWorld.getConfig(CONFIG_BATTLEGROUND_INVITATION_TYPE) == 0)
        return;

    /*
    if we reached this code, then we have to solve NP - complete problem called Subset sum problem
    So one solution is to check all possible invitation subgroups, or we can use these conditions:
    1. Last time when BattleGroundQueue::Update was executed we invited all possible players - so there is only small possibility
        that we will invite now whole queue, because only 1 change has been made to queues from the last BattleGroundQueue::Update call
    2. Other thing we should consider is group order in queue
    */

    // At first we need to compare free space in bg and our selection pool
    int32 diffAli   = aliFree   - int32(m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount());
    int32 diffHorde = hordeFree - int32(m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount());
    while (abs(diffAli - diffHorde) > 1 && (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() > 0 || m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() > 0))
    {
        //each cycle execution we need to kick at least 1 group
        if (diffAli < diffHorde)
        {
            //kick alliance group, add to pool new group if needed
            if (m_SelectionPools[BG_TEAM_ALLIANCE].KickGroup(diffHorde - diffAli))
            {
                for (; aliIndex < aliCount && m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*Ali_itr), (aliFree >= diffHorde) ? aliFree - diffHorde : 0); aliIndex++)
                    ++Ali_itr;
            }
            //if ali selection is already empty, then kick horde group, but if there are less horde than ali in bg - break;
            if (!m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())
            {
                if (aliFree <= diffHorde + 1)
                    break;
                m_SelectionPools[BG_TEAM_HORDE].KickGroup(diffHorde - diffAli);
            }
        }
        else
        {
            //kick horde group, add to pool new group if needed
            if (m_SelectionPools[BG_TEAM_HORDE].KickGroup(diffAli - diffHorde))
            {
                for (; hordeIndex < hordeCount && m_SelectionPools[BG_TEAM_HORDE].AddGroup((*Horde_itr), (hordeFree >= diffAli) ? hordeFree - diffAli : 0); hordeIndex++)
                    ++Horde_itr;
            }
            if (!m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount())
            {
                if (hordeFree <= diffAli + 1)
                    break;
                m_SelectionPools[BG_TEAM_ALLIANCE].KickGroup(diffAli - diffHorde);
            }
        }
        //count diffs after small update
        diffAli   = aliFree   - int32(m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount());
        diffHorde = hordeFree - int32(m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount());
    }
}

// this method checks if premade versus premade battleground is possible
// then after 30 mins (default) in queue it moves premade group to normal queue
// it tries to invite as much players as it can - to MaxPlayersPerTeam, because premade groups have more than MinPlayersPerTeam players
bool BattleGroundQueue::CheckPremadeMatch(BattleGroundBracketId bracket_id, uint32 MinPlayersPerTeam, uint32 MaxPlayersPerTeam)
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
            m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*ali_group), MaxPlayersPerTeam);
            m_SelectionPools[BG_TEAM_HORDE].AddGroup((*horde_group), MaxPlayersPerTeam);
            //add groups/players from normal queue to size of bigger group
            uint32 maxPlayers = std::min(m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount(), m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount());
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
    uint32 time_before = getMSTime() - sWorld.getConfig(CONFIG_BATTLEGROUND_PREMADE_GROUP_WAIT_FOR_MATCH);
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
bool BattleGroundQueue::CheckNormalMatch(BattleGround* bg_template, BattleGroundBracketId bracket_id, uint32 minPlayers, uint32 maxPlayers)
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
    uint32 j = BG_TEAM_ALLIANCE;
    if (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() < m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())
        j = BG_TEAM_HORDE;
    if (sWorld.getConfig(CONFIG_BATTLEGROUND_INVITATION_TYPE) != 0
        && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() >= minPlayers && m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() >= minPlayers)
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
        if (abs((int32)(m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() - m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())) > 2)
            return false;
    }
    //allow 1v0 if debug bg
    if (sBattleGroundMgr.isTesting() && bg_template->isBattleGround() && (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() || m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount()))
        return true;
    //return true if there are enough players in selection pools - enable to work .debug bg command correctly
    return m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() >= minPlayers && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() >= minPlayers;
}

// this method will check if we can invite players to same faction skirmish match
bool BattleGroundQueue::CheckSkirmishForSameFaction(BattleGroundBracketId bracket_id, uint32 minPlayersPerTeam)
{
    if (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() < minPlayersPerTeam && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() < minPlayersPerTeam)
        return false;
    uint32 teamIndex = BG_TEAM_ALLIANCE;
    uint32 otherTeam = BG_TEAM_HORDE;
    uint32 otherTeamId = HORDE;
    if (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() == minPlayersPerTeam)
    {
        teamIndex = BG_TEAM_HORDE;
        otherTeam = BG_TEAM_ALLIANCE;
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

/*
this method is called when group is inserted, or player / group is removed from BG Queue - there is only one player's status changed, so we don't use while (true) cycles to invite whole queue
it must be called after fully adding the members of a group to ensure group joining
should be called from BattleGround::RemovePlayer function in some cases
*/
void BattleGroundQueue::Update(BattleGroundTypeId bgTypeId, BattleGroundBracketId bracket_id, uint8 arenaType, bool isRated, uint32 arenaRating)
{
    //if no players in queue - do nothing
    if (m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].empty() &&
        m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].empty() &&
        m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_ALLIANCE].empty() &&
        m_QueuedGroups[bracket_id][BG_QUEUE_NORMAL_HORDE].empty())
        return;

    //battleground with free slot for player should be always in the beggining of the queue
    // maybe it would be better to create bgfreeslotqueue for each bracket_id
    BGFreeSlotQueueType::iterator itr, next;
    for (itr = sBattleGroundMgr.BGFreeSlotQueue[bgTypeId].begin(); itr != sBattleGroundMgr.BGFreeSlotQueue[bgTypeId].end(); itr = next)
    {
        next = itr;
        ++next;
        // DO NOT allow queue manager to invite new player to arena
        if ((*itr)->isBattleGround() && (*itr)->GetTypeID() == bgTypeId && (*itr)->GetBracketId() == bracket_id &&
            (*itr)->GetStatus() > STATUS_WAIT_QUEUE && (*itr)->GetStatus() < STATUS_WAIT_LEAVE)
        {
            BattleGround* bg = *itr; //we have to store battleground pointer here, because when battleground is full, it is removed from free queue (not yet implemented!!)
            // and iterator is invalid

            // clear selection pools
            m_SelectionPools[BG_TEAM_ALLIANCE].Init();
            m_SelectionPools[BG_TEAM_HORDE].Init();

            // call a function that does the job for us
            FillPlayersToBG(bg, bracket_id);

            // now everything is set, invite players
            for (GroupsQueueType::const_iterator citr = m_SelectionPools[BG_TEAM_ALLIANCE].SelectedGroups.begin(); citr != m_SelectionPools[BG_TEAM_ALLIANCE].SelectedGroups.end(); ++citr)
                InviteGroupToBG((*citr), bg, (*citr)->Team);
            for (GroupsQueueType::const_iterator citr = m_SelectionPools[BG_TEAM_HORDE].SelectedGroups.begin(); citr != m_SelectionPools[BG_TEAM_HORDE].SelectedGroups.end(); ++citr)
                InviteGroupToBG((*citr), bg, (*citr)->Team);

            if (!bg->HasFreeSlots())
            {
                // remove BG from BGFreeSlotQueue
                bg->RemoveFromBGFreeSlotQueue();
            }
        }
    }

    // finished iterating through the bgs with free slots, maybe we need to create a new bg

    BattleGround * bg_template = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
    if (!bg_template)
    {
        sLog.outError("Battleground: Update: bg template not found for %u", bgTypeId);
        return;
    }

    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketById(bg_template->GetMapId(),bracket_id);
    if (!bracketEntry)
    {
        sLog.outError("Battleground: Update: bg bracket entry not found for map %u bracket id %u", bg_template->GetMapId(), bracket_id);
        return;
    }

    // get the min. players per team, properly for larger arenas as well. (must have full teams for arena matches!)
    uint32 MinPlayersPerTeam = bg_template->GetMinPlayersPerTeam();
    uint32 MaxPlayersPerTeam = bg_template->GetMaxPlayersPerTeam();
    if (sBattleGroundMgr.isTesting())
        MinPlayersPerTeam = 1;
    if (bg_template->isArena())
    {
        if (sBattleGroundMgr.isArenaTesting())
        {
            MaxPlayersPerTeam = 1;
            MinPlayersPerTeam = 1;
        }
        else
        {
            //this switch can be much shorter
            MaxPlayersPerTeam = arenaType;
            MinPlayersPerTeam = arenaType;
            /*switch(arenaType)
            {
            case ARENA_TYPE_2v2:
                MaxPlayersPerTeam = 2;
                MinPlayersPerTeam = 2;
                break;
            case ARENA_TYPE_3v3:
                MaxPlayersPerTeam = 3;
                MinPlayersPerTeam = 3;
                break;
            case ARENA_TYPE_5v5:
                MaxPlayersPerTeam = 5;
                MinPlayersPerTeam = 5;
                break;
            }*/
        }
    }

    m_SelectionPools[BG_TEAM_ALLIANCE].Init();
    m_SelectionPools[BG_TEAM_HORDE].Init();

    if (bg_template->isBattleGround())
    {
        //check if there is premade against premade match
        if (CheckPremadeMatch(bracket_id, MinPlayersPerTeam, MaxPlayersPerTeam))
        {
            //create new battleground
            BattleGround * bg2 = sBattleGroundMgr.CreateNewBattleGround(bgTypeId, bracketEntry, 0, false);
            if (!bg2)
            {
                sLog.outError("BattleGroundQueue::Update - Cannot create battleground: %u", bgTypeId);
                return;
            }
            //invite those selection pools
            for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
                for (GroupsQueueType::const_iterator citr = m_SelectionPools[BG_TEAM_ALLIANCE + i].SelectedGroups.begin(); citr != m_SelectionPools[BG_TEAM_ALLIANCE + i].SelectedGroups.end(); ++citr)
                    InviteGroupToBG((*citr), bg2, (*citr)->Team);
            //start bg
            bg2->StartBattleGround();
            //clear structures
            m_SelectionPools[BG_TEAM_ALLIANCE].Init();
            m_SelectionPools[BG_TEAM_HORDE].Init();
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
            BattleGround * bg2 = sBattleGroundMgr.CreateNewBattleGround(bgTypeId, bracketEntry, arenaType, false);
            if (!bg2)
            {
                sLog.outError("BattleGroundQueue::Update - Cannot create battleground: %u", bgTypeId);
                return;
            }

            // invite those selection pools
            for (uint32 i = 0; i < BG_TEAMS_COUNT; i++)
                for (GroupsQueueType::const_iterator citr = m_SelectionPools[BG_TEAM_ALLIANCE + i].SelectedGroups.begin(); citr != m_SelectionPools[BG_TEAM_ALLIANCE + i].SelectedGroups.end(); ++citr)
                    InviteGroupToBG((*citr), bg2, (*citr)->Team);
            // start bg
            bg2->StartBattleGround();
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
                arenaRating = front1->ArenaTeamRating;
            }
            if (!m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].empty())
            {
                front2 = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].front();
                arenaRating = front2->ArenaTeamRating;
            }
            if (front1 && front2)
            {
                if (front1->JoinTime < front2->JoinTime)
                    arenaRating = front1->ArenaTeamRating;
            }
            else if (!front1 && !front2)
                return; //queues are empty
        }

        //set rating range
        uint32 arenaMinRating = (arenaRating <= sBattleGroundMgr.GetMaxRatingDifference()) ? 0 : arenaRating - sBattleGroundMgr.GetMaxRatingDifference();
        uint32 arenaMaxRating = arenaRating + sBattleGroundMgr.GetMaxRatingDifference();
        // if max rating difference is set and the time past since server startup is greater than the rating discard time
        // (after what time the ratings aren't taken into account when making teams) then
        // the discard time is current_time - time_to_discard, teams that joined after that, will have their ratings taken into account
        // else leave the discard time on 0, this way all ratings will be discarded
        uint32 discardTime = getMSTime() - sBattleGroundMgr.GetRatingDiscardTimer();

        // we need to find 2 teams which will play next game

        GroupsQueueType::iterator itr_team[BG_TEAMS_COUNT];

        //optimalization : --- we dont need to use selection_pools - each update we select max 2 groups

        for (uint32 i = BG_QUEUE_PREMADE_ALLIANCE; i < BG_QUEUE_NORMAL_ALLIANCE; i++)
        {
            // take the group that joined first
            itr_team[i] = m_QueuedGroups[bracket_id][i].begin();
            for (; itr_team[i] != m_QueuedGroups[bracket_id][i].end(); ++(itr_team[i]))
            {
                // if group match conditions, then add it to pool
                if (!(*itr_team[i])->IsInvitedToBGInstanceGUID
                    && (((*itr_team[i])->ArenaTeamRating >= arenaMinRating && (*itr_team[i])->ArenaTeamRating <= arenaMaxRating)
                        || (*itr_team[i])->JoinTime < discardTime))
                {
                    m_SelectionPools[i].AddGroup((*itr_team[i]), MaxPlayersPerTeam);
                    // break for cycle to be able to start selecting another group from same faction queue
                    break;
                }
            }
        }
        // now we are done if we have 2 groups - ali vs horde!
        // if we don't have, we must try to continue search in same queue
        // tmp variables are correctly set
        // this code isn't much userfriendly - but it is supposed to continue search for mathing group in HORDE queue
        if (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() == 0 && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount())
        {
            itr_team[BG_TEAM_ALLIANCE] = itr_team[BG_TEAM_HORDE];
            ++itr_team[BG_TEAM_ALLIANCE];
            for (; itr_team[BG_TEAM_ALLIANCE] != m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].end(); ++(itr_team[BG_TEAM_ALLIANCE]))
            {
                if (!(*itr_team[BG_TEAM_ALLIANCE])->IsInvitedToBGInstanceGUID
                    && (((*itr_team[BG_TEAM_ALLIANCE])->ArenaTeamRating >= arenaMinRating && (*itr_team[BG_TEAM_ALLIANCE])->ArenaTeamRating <= arenaMaxRating)
                        || (*itr_team[BG_TEAM_ALLIANCE])->JoinTime < discardTime))
                {
                    m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*itr_team[BG_TEAM_ALLIANCE]), MaxPlayersPerTeam);
                    break;
                }
            }
        }
        // this code isn't much userfriendly - but it is supposed to continue search for mathing group in ALLIANCE queue
        if (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() == 0 && m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())
        {
            itr_team[BG_TEAM_HORDE] = itr_team[BG_TEAM_ALLIANCE];
            ++itr_team[BG_TEAM_HORDE];
            for (; itr_team[BG_TEAM_HORDE] != m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].end(); ++(itr_team[BG_TEAM_HORDE]))
            {
                if (!(*itr_team[BG_TEAM_HORDE])->IsInvitedToBGInstanceGUID
                    && (((*itr_team[BG_TEAM_HORDE])->ArenaTeamRating >= arenaMinRating && (*itr_team[BG_TEAM_HORDE])->ArenaTeamRating <= arenaMaxRating)
                        || (*itr_team[BG_TEAM_HORDE])->JoinTime < discardTime))
                {
                    m_SelectionPools[BG_TEAM_HORDE].AddGroup((*itr_team[BG_TEAM_HORDE]), MaxPlayersPerTeam);
                    break;
                }
            }
        }

        //if we have 2 teams, then start new arena and invite players!
        if (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount())
        {
            BattleGround* arena = sBattleGroundMgr.CreateNewBattleGround(bgTypeId, bracketEntry, arenaType, true);
            if (!arena)
            {
                sLog.outError("BattlegroundQueue::Update couldn't create arena instance for rated arena match!");
                return;
            }

            (*(itr_team[BG_TEAM_ALLIANCE]))->OpponentsTeamRating = (*(itr_team[BG_TEAM_HORDE]))->ArenaTeamRating;
            sLog.outDebug("setting oposite teamrating for team %u to %u", (*(itr_team[BG_TEAM_ALLIANCE]))->ArenaTeamId, (*(itr_team[BG_TEAM_ALLIANCE]))->OpponentsTeamRating);
            (*(itr_team[BG_TEAM_HORDE]))->OpponentsTeamRating = (*(itr_team[BG_TEAM_ALLIANCE]))->ArenaTeamRating;
            sLog.outDebug("setting oposite teamrating for team %u to %u", (*(itr_team[BG_TEAM_HORDE]))->ArenaTeamId, (*(itr_team[BG_TEAM_HORDE]))->OpponentsTeamRating);
            // now we must move team if we changed its faction to another faction queue, because then we will spam log by errors in Queue::RemovePlayer
            if ((*(itr_team[BG_TEAM_ALLIANCE]))->Team != ALLIANCE)
            {
                // add to alliance queue
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].push_front(*(itr_team[BG_TEAM_ALLIANCE]));
                // erase from horde queue
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].erase(itr_team[BG_TEAM_ALLIANCE]);
                itr_team[BG_TEAM_ALLIANCE] = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].begin();
            }
            if ((*(itr_team[BG_TEAM_HORDE]))->Team != HORDE)
            {
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].push_front(*(itr_team[BG_TEAM_HORDE]));
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].erase(itr_team[BG_TEAM_HORDE]);
                itr_team[BG_TEAM_HORDE] = m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].begin();
            }

            InviteGroupToBG(*(itr_team[BG_TEAM_ALLIANCE]), arena, ALLIANCE);
            InviteGroupToBG(*(itr_team[BG_TEAM_HORDE]), arena, HORDE);

            sLog.outDebug("Starting rated arena match!");

            arena->StartBattleGround();
        }
    }
}

/*********************************************************/
/***            BATTLEGROUND QUEUE EVENTS              ***/
/*********************************************************/

bool BGQueueInviteEvent::Execute(uint64 /*e_time*/, uint32 /*p_time*/)
{
    Player* plr = objmgr.GetPlayer(m_PlayerGuid);
    // player logged off (we should do nothing, he is correctly removed from queue in another procedure)
    if (!plr)
        return true;

    BattleGround* bg = sBattleGroundMgr.GetBattleGround(m_BgInstanceGUID, m_BgTypeId);
    //if battleground ended and its instance deleted - do nothing
    if (!bg)
        return true;

    BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(bg->GetTypeID(), bg->GetArenaType());
    uint32 queueSlot = plr->GetBattleGroundQueueIndex(bgQueueTypeId);
    if (queueSlot < PLAYER_MAX_BATTLEGROUND_QUEUES)         // player is in queue or in battleground
    {
        // check if player is invited to this bg
        BattleGroundQueue &bgQueue = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId];
        if (bgQueue.IsPlayerInvited(m_PlayerGuid, m_BgInstanceGUID, m_RemoveTime))
        {
            WorldPacket data;
            //we must send remaining time in queue
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_JOIN, INVITE_ACCEPT_WAIT_TIME - INVITATION_REMIND_TIME, 0, m_ArenaType);
            plr->GetSession()->SendPacket(&data);
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
    Player* plr = objmgr.GetPlayer(m_PlayerGuid);
    if (!plr)
        // player logged off (we should do nothing, he is correctly removed from queue in another procedure)
        return true;

    BattleGround* bg = sBattleGroundMgr.GetBattleGround(m_BgInstanceGUID, m_BgTypeId);
    //battleground can be deleted already when we are removing queue info
    //bg pointer can be NULL! so use it carefully!

    uint32 queueSlot = plr->GetBattleGroundQueueIndex(m_BgQueueTypeId);
    if (queueSlot < PLAYER_MAX_BATTLEGROUND_QUEUES)         // player is in queue, or in Battleground
    {
        // check if player is in queue for this BG and if we are removing his invite event
        BattleGroundQueue &bgQueue = sBattleGroundMgr.m_BattleGroundQueues[m_BgQueueTypeId];
        if (bgQueue.IsPlayerInvited(m_PlayerGuid, m_BgInstanceGUID, m_RemoveTime))
        {
            sLog.outDebug("Battleground: removing player %u from bg queue for instance %u because of not pressing enter battle in time.",plr->GetGUIDLow(),m_BgInstanceGUID);

            plr->RemoveBattleGroundQueueId(m_BgQueueTypeId);
            bgQueue.RemovePlayer(m_PlayerGuid, true);
            //update queues if battleground isn't ended
            if (bg && bg->isBattleGround() && bg->GetStatus() != STATUS_WAIT_LEAVE)
                sBattleGroundMgr.ScheduleQueueUpdate(0, 0, m_BgQueueTypeId, m_BgTypeId, bg->GetBracketId());

            WorldPacket data;
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0);
            plr->GetSession()->SendPacket(&data);
        }
    }

    //event will be deleted
    return true;
}

void BGQueueRemoveEvent::Abort(uint64 /*e_time*/)
{
    //do nothing
}

/*********************************************************/
/***            BATTLEGROUND MANAGER                   ***/
/*********************************************************/

BattleGroundMgr::BattleGroundMgr() : m_AutoDistributionTimeChecker(0), m_ArenaTesting(false)
{
    for (uint32 i = BATTLEGROUND_TYPE_NONE; i < MAX_BATTLEGROUND_TYPE_ID; i++)
        m_BattleGrounds[i].clear();
    m_NextRatingDiscardUpdate = sWorld.getConfig(CONFIG_ARENA_RATING_DISCARD_TIMER);
    m_Testing=false;
}

BattleGroundMgr::~BattleGroundMgr()
{
    DeleteAllBattleGrounds();
}

void BattleGroundMgr::DeleteAllBattleGrounds()
{
    for (uint32 i = BATTLEGROUND_TYPE_NONE; i < MAX_BATTLEGROUND_TYPE_ID; ++i)
    {
        for (BattleGroundSet::iterator itr = m_BattleGrounds[i].begin(); itr != m_BattleGrounds[i].end();)
        {
            BattleGround * bg = itr->second;
            m_BattleGrounds[i].erase(itr++);
            if (!m_ClientBattleGroundIds[i][bg->GetBracketId()].empty())
                m_ClientBattleGroundIds[i][bg->GetBracketId()].erase(bg->GetClientInstanceID());
            delete bg;
        }
    }

    // destroy template battlegrounds that listed only in queues (other already terminated)
    for (uint32 bgTypeId = 0; bgTypeId < MAX_BATTLEGROUND_TYPE_ID; ++bgTypeId)
    {
        // ~BattleGround call unregistring BG from queue
        while (!BGFreeSlotQueue[bgTypeId].empty())
            delete BGFreeSlotQueue[bgTypeId].front();
    }
}

// used to update running battlegrounds, and delete finished ones
void BattleGroundMgr::Update(uint32 diff)
{
    BattleGroundSet::iterator itr, next;
    for (uint32 i = BATTLEGROUND_TYPE_NONE; i < MAX_BATTLEGROUND_TYPE_ID; ++i)
    {
        itr = m_BattleGrounds[i].begin();
        // skip updating battleground template
        if (itr != m_BattleGrounds[i].end())
            ++itr;
        for (; itr != m_BattleGrounds[i].end(); itr = next)
        {
            next = itr;
            ++next;
            itr->second->Update(diff);
            // use the SetDeleteThis variable
            // direct deletion caused crashes
            if (itr->second->m_SetDeleteThis)
            {
                BattleGround * bg = itr->second;
                m_BattleGrounds[i].erase(itr);
                if (!m_ClientBattleGroundIds[i][bg->GetBracketId()].empty())
                    m_ClientBattleGroundIds[i][bg->GetBracketId()].erase(bg->GetClientInstanceID());
                delete bg;
            }
        }
    }

    // update scheduled queues
    if (!m_QueueUpdateScheduler.empty())
    {
        std::vector<uint64> scheduled;
        {
            //copy vector and clear the other
            scheduled = std::vector<uint64>(m_QueueUpdateScheduler);
            m_QueueUpdateScheduler.clear();
            //release lock
        }

        for (uint8 i = 0; i < scheduled.size(); i++)
        {
            uint32 arenaRating = scheduled[i] >> 32;
            uint8 arenaType = scheduled[i] >> 24 & 255;
            BattleGroundQueueTypeId bgQueueTypeId = BattleGroundQueueTypeId(scheduled[i] >> 16 & 255);
            BattleGroundTypeId bgTypeId = BattleGroundTypeId((scheduled[i] >> 8) & 255);
            BattleGroundBracketId bracket_id = BattleGroundBracketId(scheduled[i] & 255);
            m_BattleGroundQueues[bgQueueTypeId].Update(bgTypeId, bracket_id, arenaType, arenaRating > 0, arenaRating);
        }
    }

    // if rating difference counts, maybe force-update queues
    if (sWorld.getConfig(CONFIG_ARENA_MAX_RATING_DIFFERENCE) && sWorld.getConfig(CONFIG_ARENA_RATING_DISCARD_TIMER))
    {
        // it's time to force update
        if (m_NextRatingDiscardUpdate < diff)
        {
            // forced update for rated arenas (scan all, but skipped non rated)
            sLog.outDebug("BattleGroundMgr: UPDATING ARENA QUEUES");
            for (int qtype = BATTLEGROUND_QUEUE_2v2; qtype <= BATTLEGROUND_QUEUE_5v5; ++qtype)
                for (int bracket = BG_BRACKET_ID_FIRST; bracket < MAX_BATTLEGROUND_BRACKETS; ++bracket)
                    m_BattleGroundQueues[qtype].Update(
                        BATTLEGROUND_AA, BattleGroundBracketId(bracket),
                        BattleGroundMgr::BGArenaType(BattleGroundQueueTypeId(qtype)), true, 0);

            m_NextRatingDiscardUpdate = sWorld.getConfig(CONFIG_ARENA_RATING_DISCARD_TIMER);
        }
        else
            m_NextRatingDiscardUpdate -= diff;
    }
    if (sWorld.getConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS))
    {
        if (m_AutoDistributionTimeChecker < diff)
        {
            if (time(NULL) > m_NextAutoDistributionTime)
            {
                DistributeArenaPoints();
                m_NextAutoDistributionTime = m_NextAutoDistributionTime + BATTLEGROUND_ARENA_POINT_DISTRIBUTION_DAY * sWorld.getConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_INTERVAL_DAYS);
                sWorld.setWorldState(WS_ARENA_DISTRIBUTION_TIME, uint64(m_NextAutoDistributionTime));
            }
            m_AutoDistributionTimeChecker = 600000; // check 10 minutes
        }
        else
            m_AutoDistributionTimeChecker -= diff;
    }
}

void BattleGroundMgr::BuildBattleGroundStatusPacket(WorldPacket *data, BattleGround *bg, uint8 QueueSlot, uint8 StatusID, uint32 Time1, uint32 Time2, uint8 arenatype)
{
    // we can be in 2 queues in same time...

    if (StatusID == 0 || !bg)
    {
        data->Initialize(SMSG_BATTLEFIELD_STATUS, 4+8);
        *data << uint32(QueueSlot);                         // queue id (0...1)
        *data << uint64(0);
        return;
    }

    data->Initialize(SMSG_BATTLEFIELD_STATUS, (4+8+1+1+4+1+4+4+4));
    *data << uint32(QueueSlot);                             // queue id (0...1) - player can be in 2 queues in time
    // The following segment is read as uint64 in client but can be appended as their original type.
    *data << uint8(arenatype);
    sLog.outDebug("BattleGroundMgr::BuildBattleGroundStatusPacket: arenatype = %u for bg instanceID %u, TypeID %u.", arenatype, bg->GetClientInstanceID(), bg->GetTypeID());
    *data << uint8(bg->isArena() ? 0xC : 0x2);
    *data << uint32(bg->GetTypeID());
    *data << uint16(0x1F90);
    // End of uint64 segment, decomposed this way for simplicity
    *data << uint8(0);                                      // 3.3.0
    *data << uint8(0);                                      // 3.3.0
    *data << uint32(bg->GetClientInstanceID());
    // alliance/horde for BG and skirmish/rated for Arenas
    // following displays the minimap-icon 0 = faction icon 1 = arenaicon
    *data << uint8(bg->isRated());                          // 1 for rated match, 0 for bg or non rated match

    *data << uint32(StatusID);                              // status
    switch(StatusID)
    {
        case STATUS_WAIT_QUEUE:                             // status_in_queue
            *data << uint32(Time1);                         // average wait time, milliseconds
            *data << uint32(Time2);                         // time in queue, updated every minute!, milliseconds
            break;
        case STATUS_WAIT_JOIN:                              // status_invite
            *data << uint32(bg->GetMapId());                // map id
            *data << uint32(Time1);                         // time to remove from queue, milliseconds
            break;
        case STATUS_IN_PROGRESS:                            // status_in_progress
            *data << uint32(bg->GetMapId());                // map id
            *data << uint32(Time1);                         // time to bg auto leave, 0 at bg start, 120000 after bg end, milliseconds
            *data << uint32(Time2);                         // time from bg start, milliseconds
            *data << uint8(/*bg->isArena() ? 0 :*/ 1);      // unk, possibly 0 == preparation phase, 1 == battle
            break;
        default:
            sLog.outError("Unknown BG status!");
            break;
    }
}

void BattleGroundMgr::BuildPvpLogDataPacket(WorldPacket *data, BattleGround *bg)
{
    uint8 type = (bg->isArena() ? 1 : 0);
                                                            // last check on 3.0.3
    data->Initialize(MSG_PVP_LOG_DATA, (1+1+4+40*bg->GetPlayerScoresSize()));
    *data << uint8(type);                                   // type (battleground=0/arena=1)

    if (type)                                                // arena
    {
        // it seems this must be according to BG_WINNER_A/H and _NOT_ BG_TEAM_A/H
        for (int i = 1; i >= 0; --i)
        {
            uint32 pointsLost = bg->m_ArenaTeamRatingChanges[i] < 0 ? abs(bg->m_ArenaTeamRatingChanges[i]) : 0;
            uint32 pointsGained = bg->m_ArenaTeamRatingChanges[i] > 0 ? bg->m_ArenaTeamRatingChanges[i] : 0;

            *data << uint32(pointsLost);                        // Rating Lost
            *data << uint32(pointsGained);                      // Rating gained
            *data << uint32(0);                                 // Matchmaking Value
            sLog.outDebug("rating change: %d", bg->m_ArenaTeamRatingChanges[i]);
        }
        for (int i = 1; i >= 0; --i)
        {
            uint32 at_id = bg->m_ArenaTeamIds[i];
            ArenaTeam * at = objmgr.GetArenaTeamById(at_id);
            if (at)
                *data << at->GetName();
            else
                *data << (uint8)0;
        }
    }

    if (bg->GetStatus() != STATUS_WAIT_LEAVE)
    {
        *data << uint8(0);                                  // bg not ended
    }
    else
    {
        *data << uint8(1);                                  // bg ended
        *data << uint8(bg->GetWinner());                    // who win
    }

    *data << (int32)(bg->GetPlayerScoresSize());

    for (BattleGround::BattleGroundScoreMap::const_iterator itr = bg->GetPlayerScoresBegin(); itr != bg->GetPlayerScoresEnd(); ++itr)
    {
        *data << (uint64)itr->first;
        *data << (int32)itr->second->KillingBlows;
        if (type == 0)
        {
            *data << (int32)itr->second->HonorableKills;
            *data << (int32)itr->second->Deaths;
            *data << (int32)(itr->second->BonusHonor);
        }
        else
        {
            Player *plr = objmgr.GetPlayer(itr->first);
            uint32 team = bg->GetPlayerTeam(itr->first);
            if (!team && plr)
                team = plr->GetBGTeam();
            *data << uint8(team == ALLIANCE ? 1 : 0); // green or yellow

        }
        *data << (int32)itr->second->DamageDone;             // damage done
        *data << (int32)itr->second->HealingDone;            // healing done
        switch(bg->GetTypeID(true))                              // battleground specific things
        {
            case BATTLEGROUND_RB:
                switch(bg->GetMapId())
                {
                    case 489:
                        *data << (uint32)0x00000002;        // count of next fields
                        *data << (uint32)((BattleGroundWGScore*)itr->second)->FlagCaptures;         // flag captures
                        *data << (uint32)((BattleGroundWGScore*)itr->second)->FlagReturns;          // flag returns
                        break;
                    case 566:
                        *data << (uint32)0x00000001;        // count of next fields
                        *data << (uint32)((BattleGroundEYScore*)itr->second)->FlagCaptures;         // flag captures
                        break;
                    case 529:
                        *data << (uint32)0x00000002;        // count of next fields
                        *data << (uint32)((BattleGroundABScore*)itr->second)->BasesAssaulted;       // bases asssulted
                        *data << (uint32)((BattleGroundABScore*)itr->second)->BasesDefended;        // bases defended
                        break;
                    case 30:
                        *data << (uint32)0x00000005;        // count of next fields
                        *data << (uint32)((BattleGroundAVScore*)itr->second)->GraveyardsAssaulted;  // GraveyardsAssaulted
                        *data << (uint32)((BattleGroundAVScore*)itr->second)->GraveyardsDefended;   // GraveyardsDefended
                        *data << (uint32)((BattleGroundAVScore*)itr->second)->TowersAssaulted;      // TowersAssaulted
                        *data << (uint32)((BattleGroundAVScore*)itr->second)->TowersDefended;       // TowersDefended
                        *data << (uint32)((BattleGroundAVScore*)itr->second)->MinesCaptured;        // MinesCaptured
                        break;
                    case 607:
                        *data << uint32(2);
                        *data << uint32(((BattleGroundSAScore*)itr->second)->demolishers_destroyed);
                        *data << uint32(((BattleGroundSAScore*)itr->second)->gates_destroyed);
                        break;
                    default:
                        *data << (int32)0;                  // 0
                        break;
                }
            case BATTLEGROUND_AV:
                *data << (uint32)0x00000005;                // count of next fields
                *data << (uint32)((BattleGroundAVScore*)itr->second)->GraveyardsAssaulted;  // GraveyardsAssaulted
                *data << (uint32)((BattleGroundAVScore*)itr->second)->GraveyardsDefended;   // GraveyardsDefended
                *data << (uint32)((BattleGroundAVScore*)itr->second)->TowersAssaulted;      // TowersAssaulted
                *data << (uint32)((BattleGroundAVScore*)itr->second)->TowersDefended;       // TowersDefended
                *data << (uint32)((BattleGroundAVScore*)itr->second)->MinesCaptured;        // MinesCaptured
                break;
            case BATTLEGROUND_WS:
                *data << (uint32)0x00000002;                // count of next fields
                *data << (uint32)((BattleGroundWGScore*)itr->second)->FlagCaptures;         // flag captures
                *data << (uint32)((BattleGroundWGScore*)itr->second)->FlagReturns;          // flag returns
                break;
            case BATTLEGROUND_AB:
                *data << (uint32)0x00000002;                // count of next fields
                *data << (uint32)((BattleGroundABScore*)itr->second)->BasesAssaulted;       // bases asssulted
                *data << (uint32)((BattleGroundABScore*)itr->second)->BasesDefended;        // bases defended
                break;
            case BATTLEGROUND_EY:
                *data << (uint32)0x00000001;                // count of next fields
                *data << (uint32)((BattleGroundEYScore*)itr->second)->FlagCaptures;         // flag captures
                break;
            case BATTLEGROUND_NA:
            case BATTLEGROUND_BE:
            case BATTLEGROUND_AA:
            case BATTLEGROUND_RL:
            case BATTLEGROUND_SA:
                *data << uint32(2);
                *data << uint32(((BattleGroundSAScore*)itr->second)->demolishers_destroyed);
                *data << uint32(((BattleGroundSAScore*)itr->second)->gates_destroyed);
                break;
            case BATTLEGROUND_DS:                           // wotlk
            case BATTLEGROUND_RV:                           // wotlk
            case BATTLEGROUND_IC:                           // wotlk
                *data << (int32)0;                          // 0
                break;
            default:
                sLog.outDebug("Unhandled MSG_PVP_LOG_DATA for BG id %u", bg->GetTypeID());
                *data << (int32)0;
                break;
        }
    }
}

void BattleGroundMgr::BuildGroupJoinedBattlegroundPacket(WorldPacket *data, GroupJoinBattlegroundResult result)
{
    data->Initialize(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
    *data << int32(result);
    if (result == ERR_BATTLEGROUND_JOIN_TIMED_OUT || result == ERR_BATTLEGROUND_JOIN_FAILED)
        *data << uint64(0);                                 // player guid
}

void BattleGroundMgr::BuildUpdateWorldStatePacket(WorldPacket *data, uint32 field, uint32 value)
{
    data->Initialize(SMSG_UPDATE_WORLD_STATE, 4+4);
    *data << uint32(field);
    *data << uint32(value);
}

void BattleGroundMgr::BuildPlaySoundPacket(WorldPacket *data, uint32 soundid)
{
    data->Initialize(SMSG_PLAY_SOUND, 4);
    *data << uint32(soundid);
}

void BattleGroundMgr::BuildPlayerLeftBattleGroundPacket(WorldPacket *data, const uint64& guid)
{
    data->Initialize(SMSG_BATTLEGROUND_PLAYER_LEFT, 8);
    *data << uint64(guid);
}

void BattleGroundMgr::BuildPlayerJoinedBattleGroundPacket(WorldPacket *data, Player *plr)
{
    data->Initialize(SMSG_BATTLEGROUND_PLAYER_JOINED, 8);
    *data << uint64(plr->GetGUID());
}

BattleGround * BattleGroundMgr::GetBattleGroundThroughClientInstance(uint32 instanceId, BattleGroundTypeId bgTypeId)
{
    //cause at HandleBattleGroundJoinOpcode the clients sends the instanceid he gets from
    //SMSG_BATTLEFIELD_LIST we need to find the battleground with this clientinstance-id
    BattleGround* bg = GetBattleGroundTemplate(bgTypeId);
    if (!bg)
        return NULL;

    if (bg->isArena())
        return GetBattleGround(instanceId, bgTypeId);

    for (BattleGroundSet::iterator itr = m_BattleGrounds[bgTypeId].begin(); itr != m_BattleGrounds[bgTypeId].end(); ++itr)
    {
        if (itr->second->GetClientInstanceID() == instanceId)
            return itr->second;
    }
    return NULL;
}

BattleGround * BattleGroundMgr::GetBattleGround(uint32 InstanceID, BattleGroundTypeId bgTypeId)
{
    if (!InstanceID)
        return NULL;
    //search if needed
    BattleGroundSet::iterator itr;
    if (bgTypeId == BATTLEGROUND_TYPE_NONE)
    {
        for (uint32 i = BATTLEGROUND_AV; i < MAX_BATTLEGROUND_TYPE_ID; i++)
        {
            itr = m_BattleGrounds[i].find(InstanceID);
            if (itr != m_BattleGrounds[i].end())
                return itr->second;
        }
        return NULL;
    }
    itr = m_BattleGrounds[bgTypeId].find(InstanceID);
    return ((itr != m_BattleGrounds[bgTypeId].end()) ? itr->second : NULL);
}

BattleGround * BattleGroundMgr::GetBattleGroundTemplate(BattleGroundTypeId bgTypeId)
{
    //map is sorted and we can be sure that lowest instance id has only BG template
    return m_BattleGrounds[bgTypeId].empty() ? NULL : m_BattleGrounds[bgTypeId].begin()->second;
}

uint32 BattleGroundMgr::CreateClientVisibleInstanceId(BattleGroundTypeId bgTypeId, BattleGroundBracketId bracket_id)
{
    if (IsArenaType(bgTypeId))
        return 0;                                           //arenas don't have client-instanceids

    // we create here an instanceid, which is just for
    // displaying this to the client and without any other use..
    // the client-instanceIds are unique for each battleground-type
    // the instance-id just needs to be as low as possible, beginning with 1
    // the following works, because std::set is default ordered with "<"
    // the optimalization would be to use as bitmask std::vector<uint32> - but that would only make code unreadable
    uint32 lastId = 0;
    for (std::set<uint32>::iterator itr = m_ClientBattleGroundIds[bgTypeId][bracket_id].begin(); itr != m_ClientBattleGroundIds[bgTypeId][bracket_id].end();)
    {
        if ((++lastId) != *itr)                             //if there is a gap between the ids, we will break..
            break;
        lastId = *itr;
    }
    m_ClientBattleGroundIds[bgTypeId][bracket_id].insert(lastId + 1);
    return lastId + 1;
}

// create a new battleground that will really be used to play
BattleGround * BattleGroundMgr::CreateNewBattleGround(BattleGroundTypeId bgTypeId, PvPDifficultyEntry const* bracketEntry, uint8 arenaType, bool isRated)
{
    // get the template BG
    BattleGround *bg_template = GetBattleGroundTemplate(bgTypeId);
    BattleGroundTypeIdList *enabledBGsOrArenas = NULL;

    if (!bg_template)
    {
        sLog.outError("BattleGround: CreateNewBattleGround - bg template not found for %u", bgTypeId);
        return NULL;
    }
    bool isRandom = false;

    if (bg_template->isArena())
        enabledBGsOrArenas = &m_EnabledArenas;
    else if (bgTypeId == BATTLEGROUND_RB)
    {
        enabledBGsOrArenas = &m_EnabledBGs;
        isRandom = true;
    }

    if (enabledBGsOrArenas)
    {
        if (!enabledBGsOrArenas->size())
           return NULL;
        uint8 size = enabledBGsOrArenas->size() - 1;
        bgTypeId = enabledBGsOrArenas->at(urand(0,size));
        bg_template = GetBattleGroundTemplate(bgTypeId);
        if (!bg_template)
        {
            sLog.outError("BattleGround: CreateNewBattleGround - bg template not found for %u", bgTypeId);
            return NULL;
        }
    }

    BattleGround *bg = NULL;
    // create a copy of the BG template
    switch(bgTypeId)
    {
        case BATTLEGROUND_AV:
            bg = new BattleGroundAV(*(BattleGroundAV*)bg_template);
            break;
        case BATTLEGROUND_WS:
            bg = new BattleGroundWS(*(BattleGroundWS*)bg_template);
            break;
        case BATTLEGROUND_AB:
            bg = new BattleGroundAB(*(BattleGroundAB*)bg_template);
            break;
        case BATTLEGROUND_NA:
            bg = new BattleGroundNA(*(BattleGroundNA*)bg_template);
            break;
        case BATTLEGROUND_BE:
            bg = new BattleGroundBE(*(BattleGroundBE*)bg_template);
            break;
        case BATTLEGROUND_AA:
            bg = new BattleGroundAA(*(BattleGroundAA*)bg_template);
            break;
        case BATTLEGROUND_EY:
            bg = new BattleGroundEY(*(BattleGroundEY*)bg_template);
            break;
        case BATTLEGROUND_RL:
            bg = new BattleGroundRL(*(BattleGroundRL*)bg_template);
            break;
        case BATTLEGROUND_SA:
            bg = new BattleGroundSA(*(BattleGroundSA*)bg_template);
            break;
        case BATTLEGROUND_DS:
            bg = new BattleGroundDS(*(BattleGroundDS*)bg_template);
            break;
        case BATTLEGROUND_RV:
            bg = new BattleGroundRV(*(BattleGroundRV*)bg_template);
            break;
        case BATTLEGROUND_IC:
            bg = new BattleGroundIC(*(BattleGroundIC*)bg_template);
            break;
        case BATTLEGROUND_RB:
            bg = new BattleGroundRB(*(BattleGroundRB*)bg_template);
            break;
        default:
            //error, but it is handled few lines above
            return 0;
    }

    // generate a new instance id
    bg->SetInstanceID(MapManager::Instance().GenerateInstanceId()); // set instance id
    bg->SetClientInstanceID(CreateClientVisibleInstanceId(isRandom ? BATTLEGROUND_RB : bgTypeId, bracketEntry->GetBracketId()));

    // reset the new bg (set status to status_wait_queue from status_none)
    bg->Reset();

    // start the joining of the bg
    bg->SetStatus(STATUS_WAIT_JOIN);
    bg->SetBracket(bracketEntry);
    bg->SetArenaType(arenaType);
    bg->SetRated(isRated);
    bg->SetRandom(isRandom);
    bg->SetTypeID(isRandom ? BATTLEGROUND_RB : bgTypeId);
    bg->SetRandomTypeID(bgTypeId);

    return bg;
}

// used to create the BG templates
uint32 BattleGroundMgr::CreateBattleGround(BattleGroundTypeId bgTypeId, bool IsArena, uint32 MinPlayersPerTeam, uint32 MaxPlayersPerTeam, uint32 LevelMin, uint32 LevelMax, char* BattleGroundName, uint32 MapID, float Team1StartLocX, float Team1StartLocY, float Team1StartLocZ, float Team1StartLocO, float Team2StartLocX, float Team2StartLocY, float Team2StartLocZ, float Team2StartLocO)
{
    // Create the BG
    BattleGround *bg = NULL;
    switch(bgTypeId)
    {
        case BATTLEGROUND_AV: bg = new BattleGroundAV; break;
        case BATTLEGROUND_WS: bg = new BattleGroundWS; break;
        case BATTLEGROUND_AB: bg = new BattleGroundAB; break;
        case BATTLEGROUND_NA: bg = new BattleGroundNA; break;
        case BATTLEGROUND_BE: bg = new BattleGroundBE; break;
        case BATTLEGROUND_AA: bg = new BattleGroundAA; break;
        case BATTLEGROUND_EY: bg = new BattleGroundEY; break;
        case BATTLEGROUND_RL: bg = new BattleGroundRL; break;
        case BATTLEGROUND_SA: bg = new BattleGroundSA; break;
        case BATTLEGROUND_DS: bg = new BattleGroundDS; break;
        case BATTLEGROUND_RV: bg = new BattleGroundRV; break;
        case BATTLEGROUND_IC: bg = new BattleGroundIC; break;
        case BATTLEGROUND_RB: bg = new BattleGroundRB; break;
        default:
            bg = new BattleGround;
            break;
    }

    bg->SetMapId(MapID);
    bg->SetTypeID(bgTypeId);
    bg->SetInstanceID(0);
    bg->SetArenaorBGType(IsArena);
    bg->SetMinPlayersPerTeam(MinPlayersPerTeam);
    bg->SetMaxPlayersPerTeam(MaxPlayersPerTeam);
    bg->SetMinPlayers(MinPlayersPerTeam * 2);
    bg->SetMaxPlayers(MaxPlayersPerTeam * 2);
    bg->SetName(BattleGroundName);
    bg->SetTeamStartLoc(ALLIANCE, Team1StartLocX, Team1StartLocY, Team1StartLocZ, Team1StartLocO);
    bg->SetTeamStartLoc(HORDE,    Team2StartLocX, Team2StartLocY, Team2StartLocZ, Team2StartLocO);
    bg->SetLevelRange(LevelMin, LevelMax);

    // add bg to update list
    AddBattleGround(bg->GetInstanceID(), bg->GetTypeID(), bg);

    // return some not-null value, bgTypeId is good enough for me
    return bgTypeId;
}

void BattleGroundMgr::CreateInitialBattleGrounds()
{
    float AStartLoc[4];
    float HStartLoc[4];
    uint32 MaxPlayersPerTeam, MinPlayersPerTeam, MinLvl, MaxLvl, start1, start2;
    BattlemasterListEntry const *bl;
    WorldSafeLocsEntry const *start;
    bool IsArena;

    uint32 count = 0;

    //                                                       0   1                 2                 3      4      5                6              7             8
    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT id, MinPlayersPerTeam,MaxPlayersPerTeam,MinLvl,MaxLvl,AllianceStartLoc,AllianceStartO,HordeStartLoc,HordeStartO FROM battleground_template WHERE disable = 0");

    if (!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString();
        sLog.outErrorDb(">> Loaded 0 battlegrounds. DB table `battleground_template` is empty.");
        return;
    }

    barGoLink bar(result->GetRowCount());

    do
    {
        Field *fields = result->Fetch();
        bar.step();

        uint32 bgTypeID_ = fields[0].GetUInt32();

        // can be overwrite by values from DB
        bl = sBattlemasterListStore.LookupEntry(bgTypeID_);
        if (!bl)
        {
            sLog.outError("Battleground ID %u not found in BattlemasterList.dbc. Battleground not created.", bgTypeID_);
            continue;
        }

        BattleGroundTypeId bgTypeID = BattleGroundTypeId(bgTypeID_);

        IsArena = (bl->type == TYPE_ARENA);
        MinPlayersPerTeam = fields[1].GetUInt32();
        MaxPlayersPerTeam = fields[2].GetUInt32();
        MinLvl = fields[3].GetUInt32();
        MaxLvl = fields[4].GetUInt32();
        //check values from DB
        if (MaxPlayersPerTeam == 0 || MinPlayersPerTeam == 0 || MinPlayersPerTeam > MaxPlayersPerTeam)
        {
            MinPlayersPerTeam = 0;                          // by default now expected strong full bg requirement
            MaxPlayersPerTeam = 40;
        }
        if (MinLvl == 0 || MaxLvl == 0 || MinLvl > MaxLvl)
        {
            //TO-DO: FIX ME
            MinLvl = 0;//bl->minlvl;
            MaxLvl = 80;//bl->maxlvl;
        }

        start1 = fields[5].GetUInt32();

        start = sWorldSafeLocsStore.LookupEntry(start1);
        if (start)
        {
            AStartLoc[0] = start->x;
            AStartLoc[1] = start->y;
            AStartLoc[2] = start->z;
            AStartLoc[3] = fields[6].GetFloat();
        }
        else if (bgTypeID == BATTLEGROUND_AA || bgTypeID == BATTLEGROUND_RB)
        {
            AStartLoc[0] = 0;
            AStartLoc[1] = 0;
            AStartLoc[2] = 0;
            AStartLoc[3] = fields[6].GetFloat();
        }
        else
        {
            sLog.outErrorDb("Table `battleground_template` for id %u have non-existed WorldSafeLocs.dbc id %u in field `AllianceStartLoc`. BG not created.", bgTypeID, start1);
            continue;
        }

        start2 = fields[7].GetUInt32();

        start = sWorldSafeLocsStore.LookupEntry(start2);
        if (start)
        {
            HStartLoc[0] = start->x;
            HStartLoc[1] = start->y;
            HStartLoc[2] = start->z;
            HStartLoc[3] = fields[8].GetFloat();
        }
        else if (bgTypeID == BATTLEGROUND_AA || bgTypeID == BATTLEGROUND_RB)
        {
            HStartLoc[0] = 0;
            HStartLoc[1] = 0;
            HStartLoc[2] = 0;
            HStartLoc[3] = fields[8].GetFloat();
        }
        else
        {
            sLog.outErrorDb("Table `battleground_template` for id %u have non-existed WorldSafeLocs.dbc id %u in field `HordeStartLoc`. BG not created.", bgTypeID, start2);
            continue;
        }

        //sLog.outDetail("Creating battleground %s, %u-%u", bl->name[sWorld.GetDBClang()], MinLvl, MaxLvl);
        if (!CreateBattleGround(bgTypeID, IsArena, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, bl->name[sWorld.GetDefaultDbcLocale()], bl->mapid[0], AStartLoc[0], AStartLoc[1], AStartLoc[2], AStartLoc[3], HStartLoc[0], HStartLoc[1], HStartLoc[2], HStartLoc[3]))
            continue;

        if (IsArena)
        {
            if (bgTypeID != BATTLEGROUND_AA)
                m_EnabledArenas.push_back(bgTypeID);
        }
        else if (bgTypeID != BATTLEGROUND_RB)
                m_EnabledBGs.push_back(bgTypeID);
        ++count;
    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u battlegrounds", count);
}

void BattleGroundMgr::InitAutomaticArenaPointDistribution()
{
    if (!sWorld.getConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS))
        return;

    uint64 wstime = sWorld.getWorldState(WS_ARENA_DISTRIBUTION_TIME);
    time_t curtime = time(NULL);
    sLog.outDebug("Initializing Automatic Arena Point Distribution");
    if (wstime < curtime)
    {
        m_NextAutoDistributionTime = curtime;           // reset will be called in the next update
        sLog.outDebug("Battleground: Next arena point distribution time in the past, reseting it now.");
    }
    else
        m_NextAutoDistributionTime = time_t(wstime);
    sLog.outDebug("Automatic Arena Point Distribution initialized.");
}

void BattleGroundMgr::DistributeArenaPoints()
{
    // used to distribute arena points based on last week's stats
    sWorld.SendWorldText(LANG_DIST_ARENA_POINTS_START);

    sWorld.SendWorldText(LANG_DIST_ARENA_POINTS_ONLINE_START);

    //temporary structure for storing maximum points to add values for all players
    std::map<uint32, uint32> PlayerPoints;

    //at first update all points for all team members
    for (ObjectMgr::ArenaTeamMap::iterator team_itr = objmgr.GetArenaTeamMapBegin(); team_itr != objmgr.GetArenaTeamMapEnd(); ++team_itr)
        if (ArenaTeam * at = team_itr->second)
            at->UpdateArenaPointsHelper(PlayerPoints);

    //cycle that gives points to all players
    for (std::map<uint32, uint32>::iterator plr_itr = PlayerPoints.begin(); plr_itr != PlayerPoints.end(); ++plr_itr)
    {
        //update to database
        CharacterDatabase.PExecute("UPDATE characters SET arenaPoints = arenaPoints + '%u' WHERE guid = '%u'", plr_itr->second, plr_itr->first);

        //add points to player if online
        Player* pl = objmgr.GetPlayer(plr_itr->first);
        if (pl)
            pl->ModifyArenaPoints(plr_itr->second);
    }

    PlayerPoints.clear();

    sWorld.SendWorldText(LANG_DIST_ARENA_POINTS_ONLINE_END);

    sWorld.SendWorldText(LANG_DIST_ARENA_POINTS_TEAM_START);
    for (ObjectMgr::ArenaTeamMap::iterator titr = objmgr.GetArenaTeamMapBegin(); titr != objmgr.GetArenaTeamMapEnd(); ++titr)
    {
        if (ArenaTeam * at = titr->second)
        {
            at->FinishWeek();                              // set played this week etc values to 0 in memory, too
            at->SaveToDB();                                // save changes
            at->NotifyStatsChanged();                      // notify the players of the changes
        }
    }

    sWorld.SendWorldText(LANG_DIST_ARENA_POINTS_TEAM_END);

    sWorld.SendWorldText(LANG_DIST_ARENA_POINTS_END);
}

void BattleGroundMgr::BuildBattleGroundListPacket(WorldPacket *data, const uint64& guid, Player* plr, BattleGroundTypeId bgTypeId, uint8 fromWhere)
{
    if (!plr)
        return;

    uint32 win_kills = plr->GetRandomWinner() ? BG_REWARD_WINNER_HONOR_LAST : BG_REWARD_WINNER_HONOR_FIRST;
    uint32 win_arena = plr->GetRandomWinner() ? BG_REWARD_WINNER_ARENA_LAST : BG_REWARD_WINNER_ARENA_FIRST;
    uint32 loos_kills = plr->GetRandomWinner() ? BG_REWARD_LOOSER_HONOR_LAST : BG_REWARD_LOOSER_HONOR_FIRST;

    win_kills = (uint32)Trinity::Honor::hk_honor_at_level(plr->getLevel(), win_kills*2);
    loos_kills = (uint32)Trinity::Honor::hk_honor_at_level(plr->getLevel(), loos_kills*2);

    data->Initialize(SMSG_BATTLEFIELD_LIST);
    *data << uint64(guid);                                  // battlemaster guid
    *data << uint8(fromWhere);                              // from where you joined
    *data << uint32(bgTypeId);                              // battleground id
    *data << uint8(0);                                      // unk
    *data << uint8(0);                                      // unk

    // Rewards
    *data << uint8(plr->GetRandomWinner());               // 3.3.3 hasWin
    *data << uint32(win_kills);                           // 3.3.3 winHonor
    *data << uint32(win_arena);                           // 3.3.3 winArena
    *data << uint32(loos_kills);                          // 3.3.3 lossHonor

    uint8 isRandom = bgTypeId == BATTLEGROUND_RB;

    *data << uint8(isRandom);                               // 3.3.3 isRandom
    if (isRandom)
    {
        // Rewards (random)
        *data << uint8(plr->GetRandomWinner());           // 3.3.3 hasWin_Random
        *data << uint32(win_kills);                       // 3.3.3 winHonor_Random
        *data << uint32(win_arena);                       // 3.3.3 winArena_Random
        *data << uint32(loos_kills);                      // 3.3.3 lossHonor_Random
    }

    if (bgTypeId == BATTLEGROUND_AA)                         // arena
    {
        *data << uint32(0);                                 // unk (count?)
    }
    else                                                    // battleground
    {
        size_t count_pos = data->wpos();
        uint32 count = 0;
        *data << uint32(0);                                 // number of bg instances

        if (BattleGround* bgTemplate = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId))
        {
            // expected bracket entry
            if (PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bgTemplate->GetMapId(),plr->getLevel()))
            {
                BattleGroundBracketId bracketId = bracketEntry->GetBracketId();
                for (std::set<uint32>::iterator itr = m_ClientBattleGroundIds[bgTypeId][bracketId].begin(); itr != m_ClientBattleGroundIds[bgTypeId][bracketId].end();++itr)
                {
                    *data << uint32(*itr);
                    ++count;
                }
                data->put<uint32>(count_pos , count);
            }
        }
    }
}

void BattleGroundMgr::SendToBattleGround(Player *pl, uint32 instanceId, BattleGroundTypeId bgTypeId)
{
    BattleGround *bg = GetBattleGround(instanceId, bgTypeId);
    if (bg)
    {
        uint32 mapid = bg->GetMapId();
        float x, y, z, O;
        uint32 team = pl->GetBGTeam();
        if (team == 0)
            team = pl->GetTeam();
        bg->GetTeamStartLoc(team, x, y, z, O);

        sLog.outDetail("BATTLEGROUND: Sending %s to map %u, X %f, Y %f, Z %f, O %f", pl->GetName(), mapid, x, y, z, O);
        pl->TeleportTo(mapid, x, y, z, O);
    }
    else
    {
        sLog.outError("player %u trying to port to non-existent bg instance %u",pl->GetGUIDLow(), instanceId);
    }
}

void BattleGroundMgr::SendAreaSpiritHealerQueryOpcode(Player *pl, BattleGround *bg, const uint64& guid)
{
    WorldPacket data(SMSG_AREA_SPIRIT_HEALER_TIME, 12);
    uint32 time_ = 30000 - bg->GetLastResurrectTime();      // resurrect every 30 seconds
    if (time_ == uint32(-1))
        time_ = 0;
    data << guid << time_;
    pl->GetSession()->SendPacket(&data);
}

bool BattleGroundMgr::IsArenaType(BattleGroundTypeId bgTypeId)
{
    return (bgTypeId == BATTLEGROUND_AA ||
        bgTypeId == BATTLEGROUND_BE ||
        bgTypeId == BATTLEGROUND_NA ||
        bgTypeId == BATTLEGROUND_DS ||
        bgTypeId == BATTLEGROUND_RV ||
        bgTypeId == BATTLEGROUND_RL ||
        bgTypeId == BATTLEGROUND_DS);
}

BattleGroundQueueTypeId BattleGroundMgr::BGQueueTypeId(BattleGroundTypeId bgTypeId, uint8 arenaType)
{
    switch(bgTypeId)
    {
        case BATTLEGROUND_WS:
            return BATTLEGROUND_QUEUE_WS;
        case BATTLEGROUND_AB:
            return BATTLEGROUND_QUEUE_AB;
        case BATTLEGROUND_AV:
            return BATTLEGROUND_QUEUE_AV;
        case BATTLEGROUND_EY:
            return BATTLEGROUND_QUEUE_EY;
        case BATTLEGROUND_SA:
            return BATTLEGROUND_QUEUE_SA;
        case BATTLEGROUND_IC:
            return BATTLEGROUND_QUEUE_IC;
        case BATTLEGROUND_RB:
            return BATTLEGROUND_QUEUE_RB;
        case BATTLEGROUND_AA:
        case BATTLEGROUND_NA:
        case BATTLEGROUND_RL:
        case BATTLEGROUND_BE:
        case BATTLEGROUND_DS:
        case BATTLEGROUND_RV:
            switch(arenaType)
            {
                case ARENA_TYPE_2v2:
                    return BATTLEGROUND_QUEUE_2v2;
                case ARENA_TYPE_3v3:
                    return BATTLEGROUND_QUEUE_3v3;
                case ARENA_TYPE_5v5:
                    return BATTLEGROUND_QUEUE_5v5;
                default:
                    return BATTLEGROUND_QUEUE_NONE;
            }
        default:
            return BATTLEGROUND_QUEUE_NONE;
    }
}

BattleGroundTypeId BattleGroundMgr::BGTemplateId(BattleGroundQueueTypeId bgQueueTypeId)
{
    switch(bgQueueTypeId)
    {
        case BATTLEGROUND_QUEUE_WS:
            return BATTLEGROUND_WS;
        case BATTLEGROUND_QUEUE_AB:
            return BATTLEGROUND_AB;
        case BATTLEGROUND_QUEUE_AV:
            return BATTLEGROUND_AV;
        case BATTLEGROUND_QUEUE_EY:
            return BATTLEGROUND_EY;
        case BATTLEGROUND_QUEUE_SA:
            return BATTLEGROUND_SA;
        case BATTLEGROUND_QUEUE_IC:
            return BATTLEGROUND_IC;
        case BATTLEGROUND_QUEUE_RB:
            return BATTLEGROUND_RB;
        case BATTLEGROUND_QUEUE_2v2:
        case BATTLEGROUND_QUEUE_3v3:
        case BATTLEGROUND_QUEUE_5v5:
            return BATTLEGROUND_AA;
        default:
            return BattleGroundTypeId(0);                   // used for unknown template (it existed and do nothing)
    }
}

uint8 BattleGroundMgr::BGArenaType(BattleGroundQueueTypeId bgQueueTypeId)
{
    switch(bgQueueTypeId)
    {
        case BATTLEGROUND_QUEUE_2v2:
            return ARENA_TYPE_2v2;
        case BATTLEGROUND_QUEUE_3v3:
            return ARENA_TYPE_3v3;
        case BATTLEGROUND_QUEUE_5v5:
            return ARENA_TYPE_5v5;
        default:
            return 0;
    }
}

void BattleGroundMgr::ToggleTesting()
{
    m_Testing = !m_Testing;
    if (m_Testing)
        sWorld.SendWorldText(LANG_DEBUG_BG_ON);
    else
        sWorld.SendWorldText(LANG_DEBUG_BG_OFF);
}

void BattleGroundMgr::ToggleArenaTesting()
{
    m_ArenaTesting = !m_ArenaTesting;
    if (m_ArenaTesting)
        sWorld.SendWorldText(LANG_DEBUG_ARENA_ON);
    else
        sWorld.SendWorldText(LANG_DEBUG_ARENA_OFF);
}

void BattleGroundMgr::SetHolidayWeekends(uint32 mask)
{
    for (uint32 bgtype = 1; bgtype < MAX_BATTLEGROUND_TYPE_ID; ++bgtype)
    {
        if (BattleGround * bg = GetBattleGroundTemplate(BattleGroundTypeId(bgtype)))
        {
            bg->SetHoliday(mask & (1 << bgtype));
        }
    }
}

void BattleGroundMgr::ScheduleQueueUpdate(uint32 arenaRating, uint8 arenaType, BattleGroundQueueTypeId bgQueueTypeId, BattleGroundTypeId bgTypeId, BattleGroundBracketId bracket_id)
{
    //This method must be atomic, TODO add mutex
    //we will use only 1 number created of bgTypeId and bracket_id
    uint64 schedule_id = ((uint64)arenaRating << 32) | (arenaType << 24) | (bgQueueTypeId << 16) | (bgTypeId << 8) | bracket_id;
    bool found = false;
    for (uint8 i = 0; i < m_QueueUpdateScheduler.size(); i++)
    {
        if (m_QueueUpdateScheduler[i] == schedule_id)
        {
            found = true;
            break;
        }
    }
    if (!found)
        m_QueueUpdateScheduler.push_back(schedule_id);
}

uint32 BattleGroundMgr::GetMaxRatingDifference() const
{
    // this is for stupid people who can't use brain and set max rating difference to 0
    uint32 diff = sWorld.getConfig(CONFIG_ARENA_MAX_RATING_DIFFERENCE);
    if (diff == 0)
        diff = 5000;
    return diff;
}

uint32 BattleGroundMgr::GetRatingDiscardTimer() const
{
    return sWorld.getConfig(CONFIG_ARENA_RATING_DISCARD_TIMER);
}

uint32 BattleGroundMgr::GetPrematureFinishTime() const
{
    return sWorld.getConfig(CONFIG_BATTLEGROUND_PREMATURE_FINISH_TIMER);
}

void BattleGroundMgr::LoadBattleMastersEntry()
{
    mBattleMastersMap.clear();                              // need for reload case

    QueryResult_AutoPtr result = WorldDatabase.Query("SELECT entry,bg_template FROM battlemaster_entry");

    uint32 count = 0;

    if (!result)
    {
        barGoLink bar(1);
        bar.step();

        sLog.outString();
        sLog.outString(">> Loaded 0 battlemaster entries - table is empty!");
        return;
    }

    barGoLink bar(result->GetRowCount());

    do
    {
        ++count;
        bar.step();

        Field *fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        uint32 bgTypeId  = fields[1].GetUInt32();
        if (!sBattlemasterListStore.LookupEntry(bgTypeId))
        {
            sLog.outErrorDb("Table `battlemaster_entry` contain entry %u for not existed battleground type %u, ignored.",entry,bgTypeId);
            continue;
        }

        mBattleMastersMap[entry] = BattleGroundTypeId(bgTypeId);

    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u battlemaster entries", count);
}

HolidayIds BattleGroundMgr::BGTypeToWeekendHolidayId(BattleGroundTypeId bgTypeId)
{
    switch (bgTypeId)
    {
        case BATTLEGROUND_AV: return HOLIDAY_CALL_TO_ARMS_AV;
        case BATTLEGROUND_EY: return HOLIDAY_CALL_TO_ARMS_EY;
        case BATTLEGROUND_WS: return HOLIDAY_CALL_TO_ARMS_WS;
        case BATTLEGROUND_SA: return HOLIDAY_CALL_TO_ARMS_SA;
        default: return HOLIDAY_NONE;
    }
}

BattleGroundTypeId BattleGroundMgr::WeekendHolidayIdToBGType(HolidayIds holiday)
{
    switch (holiday)
    {
        case HOLIDAY_CALL_TO_ARMS_AV: return BATTLEGROUND_AV;
        case HOLIDAY_CALL_TO_ARMS_EY: return BATTLEGROUND_EY;
        case HOLIDAY_CALL_TO_ARMS_WS: return BATTLEGROUND_WS;
        case HOLIDAY_CALL_TO_ARMS_SA: return BATTLEGROUND_SA;
        default: return BATTLEGROUND_TYPE_NONE;
    }
}

bool BattleGroundMgr::IsBGWeekend(BattleGroundTypeId bgTypeId)
{
    return IsHolidayActive(BGTypeToWeekendHolidayId(bgTypeId));
}

void BattleGroundMgr::DoCompleteAchievement(uint32 achievement, Player * player)
{
    AchievementEntry const* AE = GetAchievementStore()->LookupEntry(achievement);

    if (!player)
    {
        //Map::PlayerList const &PlayerList = this->GetPlayers();
        //GroupsQueueType::iterator group = SelectedGroups.begin();

        //if (!PlayerList.isEmpty())
            //for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        //    for (GroupsQueueType::iterator itr = group; itr != SelectedGroups.end(); ++itr)
        //        if (Player *pPlayer = itr->getSource())
        //            pPlayer->CompletedAchievement(AE);
    }
    else
    {
        player->CompletedAchievement(AE);
    }
}
