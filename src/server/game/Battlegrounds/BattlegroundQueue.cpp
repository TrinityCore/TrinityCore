/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "ArenaTeamMgr.h"
#include "BattlegroundMgr.h"
#include "DBCStores.h"
#include "Log.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"
    m_QueuedPlayers.clear();

bool BattlegroundQueue::SelectionPool::AddGroup(GroupQueueInfo* ginfo, uint32 desiredCount)
    BattlegroundBracketId bracketId =  bracketEntry->GetBracketId();
    TC_LOG_DEBUG("bg.battleground", "Adding Group to BattlegroundQueue bgTypeId : %u, bracket_id : %u, index : %u", BgTypeId, bracketId, index);
        if (grp)
        {
            for (GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            {
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
    {

/*
============================================================================================
Battleground Queue System
============================================================================================
*/
                uint32 q_min_level = bracketEntry->minLevel;
                uint32 q_max_level = bracketEntry->maxLevel;
    uint8 team_index = BG_TEAM_ALLIANCE;                    //default set to BG_TEAM_ALLIANCE - or non rated arenas!
            team_index = TEAM_HORDE;                     //for rated arenas use TEAM_HORDE
    uint8 team_index = TEAM_ALLIANCE;                    //default set to TEAM_ALLIANCE - or non rated arenas!
void BattlegroundQueue::RemovePlayer(const uint64& guid, bool decreaseInvitedCount)
//namespace Battleground
//{
/**********************************************************************************************//**
 * \fn  void BattlegroundQueue::Insert( BattlegroundQueueElement* element )
 *
 * \brief   Inserts a new element into the queue.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param [in,out]  element The representation of a (collection of) Player(s).
 **************************************************************************************************/

void BattlegroundQueue::Insert( BattlegroundQueueElement* element )
{
    ASSERT(Base::insert(element).second == true && 
        "Element was already inserted to this BattlegroundQueue." && OutDebug());
            playerName = player->GetName();
        TC_LOG_ERROR("bg.battleground", "BattlegroundQueue: couldn't find player %s (%s)", playerName.c_str(), guid.ToString().c_str());
    GroupsQueueType::iterator group_itr;

    if (_hash.GetArenaType() >= ARENA_TYPE_2v2)
    {
        BattlegroundQueueElement* front = *begin();
        //!  If we're the only ones in queue, do not schedule anything
        if (front == element)
            for (group_itr_tmp = m_QueuedGroups[bracket_id_tmp][j].begin(); group_itr_tmp != m_QueuedGroups[bracket_id_tmp][j].end(); ++group_itr_tmp)
            for (; k != m_QueuedGroups[bracket_id_tmp][j].end(); ++k)
                if ((*k) == group)

        sLog->outError("BattlegroundQueue: ERROR Cannot find groupinfo for player GUID: %u", GUID_LOPART(guid));
            return;

        //! (Author: Unknown)
        //! found out the minimum and maximum ratings the newly added team should battle against
        //! arenaRating is the rating of the latest joined team, or 0
        //! 0 is on (automatic update call) and we must set it to team's with longest wait time
        uint32 myRating = element->ArenaMMR ? element->ArenaMMR : front->ArenaMMR;
    {
        if (ArenaTeam* Team = sArenaTeamMgr->GetArenaTeamById(group->ArenaTeamId))
        if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(group->ArenaTeamId))
            sLog->outDebug(LOG_FILTER_BATTLEGROUND, "UPDATING memberLost's personal arena rating for %u by opponents rating: %u", GUID_LOPART(guid), group->OpponentsTeamRating);
            Player *plr = sObjectMgr->GetPlayer(guid);
            if (plr)
        return;

        if (Player* plr2 = ObjectAccessor::FindConnectedPlayer(group->Players.begin()->first))

bool BattlegroundQueue::IsPlayerInvited(const uint64& pl_guid, const uint32 bgInstanceGuid, const uint32 removeTime)
uint32 BattlegroundQueue::GetPlayersInQueue(TeamId id)
{
    return m_SelectionPools[id].GetPlayerCount();
}

bool BattlegroundQueue::InviteGroupToBG(GroupQueueInfo* ginfo, Battleground* bg, uint32 side)

        uint32 minRating = (myRating <= sBattlegroundMgr->GetMaxRatingDifference()) ? 0 : myRating - sBattlegroundMgr->GetMaxRatingDifference();
        uint32 maxRating = myRating + sBattlegroundMgr->GetMaxRatingDifference();

        //! Find an immediate match based on matchmaker rating
        for (std::map<ObjectGuid, PlayerQueueInfo*>::iterator itr = ginfo->Players.begin(); itr != ginfo->Players.end(); ++itr)
        {   
            BattlegroundQueueElement* value = (*itr);
            Player* player = ObjectAccessor::FindConnectedPlayer(itr->first);
            if (value->ArenaMMR >= minRating && value->ArenaMMR <= maxRating)
            if (!player)
            //sBattlegroundMgr->InvitePlayer(player, bg, ginfo->Team);
            plr->SetInviteForBattlegroundQueueType(bgQueueTypeId, ginfo->IsInvitedToBGInstanceGUID);
            BGQueueInviteEvent* inviteEvent = new BGQueueInviteEvent(plr->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, ginfo->ArenaType, ginfo->RemoveInviteTime);
            plr->m_Events.AddEvent(inviteEvent, plr->m_Events.CalculateTime(INVITATION_REMIND_TIME));
            BGQueueRemoveEvent* removeEvent = new BGQueueRemoveEvent(plr->GetGUID(), ginfo->IsInvitedToBGInstanceGUID, bgTypeId, bgQueueTypeId, ginfo->RemoveInviteTime);
            plr->m_Events.AddEvent(removeEvent, plr->m_Events.CalculateTime(INVITE_ACCEPT_WAIT_TIME));
            uint32 queueSlot = plr->GetBattlegroundQueueIndex(bgQueueTypeId);
            sLog->outDebug(LOG_FILTER_BATTLEGROUND, "Battleground: invited plr %s (%u) to BG instance %u queueindex %u bgtype %u, I can't help it if they don't press the enter battle button.", plr->GetName(), plr->GetGUIDLow(), bg->GetInstanceID(), queueSlot, bg->GetTypeID());
                player->GetName().c_str(), player->GetGUID().ToString().c_str(), bg->GetInstanceID(), queueSlot, bg->GetTypeID());
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_JOIN, INVITE_ACCEPT_WAIT_TIME, 0, ginfo->ArenaType);
            plr->GetSession()->SendPacket(&data);
            {
                //! TODO: Invite them both to the actual battleground
                // 
                // 
                //! Erase both elements from the queue since they both found their match.
                erase(value);
                erase(element);
    for (; aliIndex < aliCount && m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*Ali_itr), aliFree); aliIndex++)
    for (; hordeIndex < hordeCount && m_SelectionPools[BG_TEAM_HORDE].AddGroup((*Horde_itr), hordeFree); hordeIndex++)
                return;
    int32 diffAli   = aliFree   - int32(m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount());
    int32 diffHorde = hordeFree - int32(m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount());
    while (abs(diffAli - diffHorde) > 1 && (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() > 0 || m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() > 0))
            if (m_SelectionPools[BG_TEAM_ALLIANCE].KickGroup(diffHorde - diffAli))
                for (; aliIndex < aliCount && m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*Ali_itr), (aliFree >= diffHorde) ? aliFree - diffHorde : 0); aliIndex++)
            if (!m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())
                m_SelectionPools[BG_TEAM_HORDE].KickGroup(diffHorde - diffAli);
            if (m_SelectionPools[BG_TEAM_HORDE].KickGroup(diffAli - diffHorde))
                for (; hordeIndex < hordeCount && m_SelectionPools[BG_TEAM_HORDE].AddGroup((*Horde_itr), (hordeFree >= diffAli) ? hordeFree - diffAli : 0); hordeIndex++)
            if (!m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount())
                m_SelectionPools[BG_TEAM_ALLIANCE].KickGroup(diffAli - diffHorde);
        diffAli   = aliFree   - int32(m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount());
        diffHorde = hordeFree - int32(m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount());
            }
        }

        //! At this point no match is found based on matchmaker rating,
        //! so we schedule a delayed invite while both teams can still find their
        //! match trough MMR.
        //! Let's not re-schedule invites with teams that already have a match scheduled
        Base::const_iterator itr = begin();
        while ((*itr)->InviteScheduled)
            ++itr;        
         
        _events.AddEvent(new ArenaInviteEvent(element, *itr),
                        _events.CalculateTime(sBattlegroundMgr->GetRatingDiscardTimer()));
            m_SelectionPools[BG_TEAM_ALLIANCE].AddGroup((*ali_group), MaxPlayersPerTeam);
            m_SelectionPools[BG_TEAM_HORDE].AddGroup((*horde_group), MaxPlayersPerTeam);
            uint32 maxPlayers = std::min(m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount(), m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount());

        //! Prevent these teams from being re-scheduled for a different match
bool BattlegroundQueue::CheckNormalMatch(Battleground* bg_template, BattlegroundBracketId bracket_id, uint32 minPlayers, uint32 maxPlayers)
        element->InviteScheduled = true;
        (*itr)->InviteScheduled = true;
    uint32 j = BG_TEAM_ALLIANCE;
    if (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() < m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())
        j = BG_TEAM_HORDE;
        && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() >= minPlayers && m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() >= minPlayers)
        if (abs((int32)(m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() - m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount())) > 2)
    if (sBattlegroundMgr->isTesting() && bg_template->isBattleground() && (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() || m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount()))
    return m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() >= minPlayers && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() >= minPlayers;

    if (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() < minPlayersPerTeam && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() < minPlayersPerTeam)
    uint32 teamIndex = BG_TEAM_ALLIANCE;
    uint32 otherTeam = BG_TEAM_HORDE;
    if (m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount() == minPlayersPerTeam)
        teamIndex = BG_TEAM_HORDE;
        otherTeam = BG_TEAM_ALLIANCE;
    }
    else //! Battleground
    {
        element->Data.Faction == ALLIANCE ? 
        _variables._ahCount.AllianceCount += element->Players.size() : 
        _variables._ahCount.HordeCount += element->Players.size();

        if (_variables._ahCount.AllianceCount >= _bgTemplate->MinPlayersPerTeam &&
            _variables._ahCount.HordeCount >= _bgTemplate->MaxPlayersPerTeam)
        {
            //! Invite every player to the battleground
        }
    }
}

{
    m_events.Update(diff);
}

void BattlegroundQueue::Update(BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id, uint8 arenaType, bool isRated, uint32 arenaRating)
    //battleground with free slot for player should be always in the beggining of the queue
    BGFreeSlotQueueType::iterator itr, next;
    for (itr = sBattlegroundMgr->BGFreeSlotQueue[bgTypeId].begin(); itr != sBattlegroundMgr->BGFreeSlotQueue[bgTypeId].end(); itr = next)
        next = itr;
        ++next;
        // DO NOT allow queue manager to invite new player to arena
        if ((*itr)->isBattleground() && (*itr)->GetTypeID() == bgTypeId && (*itr)->GetBracketId() == bracket_id &&
            m_SelectionPools[BG_TEAM_ALLIANCE].Init();
            m_SelectionPools[BG_TEAM_HORDE].Init();
            for (GroupsQueueType::const_iterator citr = m_SelectionPools[BG_TEAM_ALLIANCE].SelectedGroups.begin(); citr != m_SelectionPools[BG_TEAM_ALLIANCE].SelectedGroups.end(); ++citr)
            for (GroupsQueueType::const_iterator citr = m_SelectionPools[BG_TEAM_HORDE].SelectedGroups.begin(); citr != m_SelectionPools[BG_TEAM_HORDE].SelectedGroups.end(); ++citr)
            for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_HORDE].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_HORDE].SelectedGroups.end(); ++citr)
            {
                // remove BG from BGFreeSlotQueue
        "Element was already removed from this BattlegroundQueue." && OutDebug());
            }
        }

/**********************************************************************************************//**
 * \fn  char const* BattlegroundQueue::OutDebug()
 *
 * \brief   Gets diagnostic debug information for this object. Called in various ASSERT calls.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \return  A c-string (char*) with diagnostical information.
 **************************************************************************************************/

char const* BattlegroundQueue::OutDebug()
{
        sLog->outError("Battleground: Update: bg template not found for %u", bgTypeId);
    ss << std::endl;
    ss << "BattlegroundQueue Index: " << uint32(_hash) << std::endl;
    ss << "Rated? : " << _hash.IsRated() << std::endl;
    ss << "Arena Type: " << _hash.GetArenaType() << std::endl;
    ss << "PVP DifficultyEntry Id: " << _hash.GetPvPDifficultyId();
    return ss.str().c_str();
}

/**********************************************************************************************//**
 * \fn  void BattlegroundQueue::Update( uint32 const& diff )
 *
        sLog->outError("Battleground: Update: bg bracket entry not found for map %u bracket id %u", bg_template->GetMapId(), bracket_id);
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param   diff    Time difference in ms since last call to this function.
 **************************************************************************************************/

void BattlegroundQueue::Update( uint32 const& diff )
    if (sBattlegroundMgr->isTesting())
            MaxPlayersPerTeam = arenaType;
            MinPlayersPerTeam = arenaType;
            {
            case ARENA_TYPE_2v2:
}
    else if (sBattlegroundMgr->isTesting())
        MinPlayersPerTeam = 1;

BattlegroundQueue::~BattlegroundQueue()
{
    for (iterator itr = begin(); itr != end();)
    {
        delete (*itr);
        erase(itr++);
    }
            // invite those selection pools
                for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.end(); ++citr)

            m_SelectionPools[TEAM_ALLIANCE].Init();
            m_SelectionPools[TEAM_HORDE].Init();
}

BattlegroundQueue::BattlegroundQueue( BattlegroundQueueIndex hash, PvPDifficultyEntry const* entry ) 
: _hash(hash), _pvpDifficultyEntry(entry)
{
    //! Complicated relations between DBCs and SQL tables.
    for (uint32 i = 0; i < sBattlemasterListStore.GetNumRows(); ++i)
        if (BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(i)) 
            if (bl->mapid[0] == entry->mapId)
                _bgTemplate = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bl->id));
                TC_LOG_ERROR("bg.battleground", "BattlegroundQueue::Update - Cannot create battleground: %u", bgTypeId);

    memset(&_variables, 0, sizeof(_variables));
                for (GroupsQueueType::const_iterator citr = m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.begin(); citr != m_SelectionPools[TEAM_ALLIANCE + i].SelectedGroups.end(); ++citr)
}

        GroupsQueueType::iterator itr_teams[BG_TEAMS_COUNT];
        uint8 found = 0;
        uint8 team = 0;
        for (uint8 i = BG_QUEUE_PREMADE_ALLIANCE; i < BG_QUEUE_NORMAL_ALLIANCE; i++)
 * \fn  void BattlegroundQueueMgr::Initialize()
 *
 * \brief   Initializes this object. Allocate a BattlegroundQueue object for every possible queue.
 * 			There will be 2 * 3 * 108 = 648 seperate queues.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 **************************************************************************************************/
void BattlegroundQueueMgr::Initialize()
{
    for (uint8 rated = 0; rated <= 1; ++rated)
                    team = i;
            return;

        if (found == 1)
                if (!(*itr_team[BG_TEAM_HORDE])->IsInvitedToBGInstanceGUID
                    && (((*itr_team[BG_TEAM_HORDE])->ArenaMatchmakerRating >= arenaMinRating && (*itr_team[BG_TEAM_HORDE])->ArenaMatchmakerRating <= arenaMaxRating)
                        || (*itr_team[BG_TEAM_HORDE])->JoinTime < discardTime))
                    && (*itr_teams[0])->ArenaTeamId != (*itr3)->ArenaTeamId)
        if (m_SelectionPools[BG_TEAM_ALLIANCE].GetPlayerCount() && m_SelectionPools[BG_TEAM_HORDE].GetPlayerCount())
    {
        for (uint8 arenaType = ARENA_TYPE_2v2; arenaType <= ARENA_TYPE_5v5; ++arenaType)
            GroupQueueInfo* hTeam = *itr_teams[TEAM_HORDE];
        {
                sLog->outError("BattlegroundQueue::Update couldn't create arena instance for rated arena match!");
                continue;

            (*(itr_team[BG_TEAM_ALLIANCE]))->OpponentsTeamRating = (*(itr_team[BG_TEAM_HORDE]))->ArenaTeamRating;
            (*(itr_team[BG_TEAM_ALLIANCE]))->OpponentsMatchmakerRating = (*(itr_team[BG_TEAM_HORDE]))->ArenaMatchmakerRating;
            sLog->outDebug(LOG_FILTER_BATTLEGROUND, "setting oposite teamrating for team %u to %u", (*(itr_team[BG_TEAM_ALLIANCE]))->ArenaTeamId, (*(itr_team[BG_TEAM_ALLIANCE]))->OpponentsTeamRating);
            (*(itr_team[BG_TEAM_HORDE]))->OpponentsTeamRating = (*(itr_team[BG_TEAM_ALLIANCE]))->ArenaTeamRating;
            (*(itr_team[BG_TEAM_HORDE]))->OpponentsMatchmakerRating = (*(itr_team[BG_TEAM_ALLIANCE]))->ArenaMatchmakerRating;
            sLog->outDebug(LOG_FILTER_BATTLEGROUND, "setting oposite teamrating for team %u to %u", (*(itr_team[BG_TEAM_HORDE]))->ArenaTeamId, (*(itr_team[BG_TEAM_HORDE]))->OpponentsTeamRating);

                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].push_front(aTeam);
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].erase(itr_teams[TEAM_ALLIANCE]);
            if (hTeam->Team != HORDE)
            {
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_HORDE].push_front(hTeam);
                m_QueuedGroups[bracket_id][BG_QUEUE_PREMADE_ALLIANCE].erase(itr_teams[TEAM_HORDE]);
            }
            arena->SetArenaMatchmakerRating(ALLIANCE, (*(itr_team[BG_TEAM_ALLIANCE]))->ArenaMatchmakerRating);
            arena->SetArenaMatchmakerRating(HORDE, (*(itr_team[BG_TEAM_HORDE]))->ArenaMatchmakerRating);
            InviteGroupToBG(*(itr_team[BG_TEAM_ALLIANCE]), arena, ALLIANCE);
            InviteGroupToBG(*(itr_team[BG_TEAM_HORDE]), arena, HORDE);
            TC_LOG_DEBUG("bg.battleground", "Starting rated arena match!");
        }
    }
}

/**********************************************************************************************//**
 * \fn  void BattlegroundQueueMgr::Update( uint32 const& diff )
 *
 * \brief   Updates the child queues. Called from World::Update thread.
 *
 * \author  Machiavelli
    Player* player = ObjectAccessor::FindConnectedPlayer(m_PlayerGuid);
 *
    if (!plr)
 **************************************************************************************************/

void BattlegroundQueueMgr::Update( uint32 const& diff )
        BattlegroundQueue &bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
{
    QueueMap::const_iterator itr;
    for (itr = Queues.begin(); itr != Queues.end(); ++itr)
        itr->second->Update(diff);
}

/**********************************************************************************************//**
 * \fn  inline void BattlegroundQueueMgr::Insert( BattlegroundQueueElement* element, uint8 rated,
 *      ArenaType arenaType, uint8 difficultyEntryId )
 *
 * \brief   Inserts a new element to the queue. Called from WorldSession handlers.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param [in,out]  element     If non-null, the element. Representation of a (collection of)
 * 					            Player(s)
    Player* player = ObjectAccessor::FindConnectedPlayer(m_PlayerGuid);
    if (!player)
 * \param   arenaType           Type of the arena. (See enum ArenaType)
 * \param   difficultyEntryId   Identifier for the difficulty entry in PvPDifficultyEntry.dbc.
 **************************************************************************************************/

    uint32 queueSlot = player->GetBattlegroundQueueIndex(m_BgQueueTypeId);
void BattlegroundQueueMgr::Insert( BattlegroundQueueElement* element, uint8 rated, ArenaType arenaType, uint8 difficultyEntryId )
{
    Queues[BattlegroundQueueIndex(rated, arenaType, difficultyEntryId)]->Insert(element);
        BattlegroundQueue &bgQueue = sBattlegroundMgr->m_BattlegroundQueues[m_BgQueueTypeId];
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0);
            plr->GetSession()->SendPacket(&data);
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, player, queueSlot, STATUS_NONE, player->GetBattlegroundQueueJoinTime(m_BgTypeId), 0, m_ArenaType);
            player->GetSession()->SendPacket(&data);
}

/**********************************************************************************************//**
 * \fn  bool BattlegroundQueue::ArenaInviteEvent::Execute( uint64 , uint32 )
 *
 * \brief   Executing this event will start an arena match for the two respective teams.
 *
 * \author  Machiavelli
 * \date    7/10/2011
 *
 * \param       Unused
 * \param       Unused
 *
 * \return  true if it succeeds, false if it fails.
 **************************************************************************************************/

bool BattlegroundQueue::ArenaInviteEvent::Execute( uint64 /*e_time*/, uint32 /*p_time*/ )
{
    //! TODO: Invite both arena teams to a match
}

//}  // Namespace Battleground