/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "ObjectMgr.h"
#include "ArenaTeamMgr.h"
#include "World.h"
#include "WorldPacket.h"

#include "ArenaTeam.h"
#include "BattlegroundMgr.h"
#include "BattlegroundAV.h"
#include "BattlegroundAB.h"
#include "BattlegroundEY.h"
#include "BattlegroundWS.h"
#include "BattlegroundNA.h"
#include "BattlegroundBE.h"
#include "BattlegroundAA.h"
#include "BattlegroundRL.h"
#include "BattlegroundSA.h"
#include "BattlegroundDS.h"
#include "BattlegroundRV.h"
#include "BattlegroundIC.h"
#include "BattlegroundRB.h"
#include "Chat.h"
#include "Map.h"
#include "MapInstanced.h"
#include "MapManager.h"
#include "Player.h"
#include "GameEventMgr.h"
#include "SharedDefines.h"
#include "Formulas.h"
#include "DisableMgr.h"

/*********************************************************/
/***            BATTLEGROUND MANAGER                   ***/
/*********************************************************/

BattlegroundMgr::BattlegroundMgr() : m_AutoDistributionTimeChecker(0), m_ArenaTesting(false)
{
    for (uint32 i = BATTLEGROUND_TYPE_NONE; i < MAX_BATTLEGROUND_TYPE_ID; i++)
        m_Battlegrounds[i].clear();
    m_NextRatingDiscardUpdate = sWorld->getIntConfig(CONFIG_ARENA_RATING_DISCARD_TIMER);
    m_Testing=false;
}

BattlegroundMgr::~BattlegroundMgr()
{
    DeleteAllBattlegrounds();
}

void BattlegroundMgr::DeleteAllBattlegrounds()
{
    for (uint32 i = BATTLEGROUND_TYPE_NONE; i < MAX_BATTLEGROUND_TYPE_ID; ++i)
    {
        for (BattlegroundSet::iterator itr = m_Battlegrounds[i].begin(); itr != m_Battlegrounds[i].end();)
        {
            Battleground* bg = itr->second;
            m_Battlegrounds[i].erase(itr++);
            if (!m_ClientBattlegroundIds[i][bg->GetBracketId()].empty())
                m_ClientBattlegroundIds[i][bg->GetBracketId()].erase(bg->GetClientInstanceID());
            delete bg;
        }
    }

    // destroy template battlegrounds that listed only in queues (other already terminated)
    for (uint32 bgTypeId = 0; bgTypeId < MAX_BATTLEGROUND_TYPE_ID; ++bgTypeId)
    {
        // ~Battleground call unregistring BG from queue
        while (!BGFreeSlotQueue[bgTypeId].empty())
            delete BGFreeSlotQueue[bgTypeId].front();
    }
}

// used to update running battlegrounds, and delete finished ones
void BattlegroundMgr::Update(uint32 diff)
{
    BattlegroundSet::iterator itr, next;
    for (uint32 i = BATTLEGROUND_TYPE_NONE; i < MAX_BATTLEGROUND_TYPE_ID; ++i)
    {
        itr = m_Battlegrounds[i].begin();
        // skip updating battleground template
        if (itr != m_Battlegrounds[i].end())
            ++itr;
        for (; itr != m_Battlegrounds[i].end(); itr = next)
        {
            next = itr;
            ++next;
            itr->second->Update(diff);
            // use the SetDeleteThis variable
            // direct deletion caused crashes
            if (itr->second->ToBeDeleted())
            {
                Battleground* bg = itr->second;
                m_Battlegrounds[i].erase(itr);
                if (!m_ClientBattlegroundIds[i][bg->GetBracketId()].empty())
                    m_ClientBattlegroundIds[i][bg->GetBracketId()].erase(bg->GetClientInstanceID());

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
            uint32 arenaMMRating = scheduled[i] >> 32;
            uint8 arenaType = scheduled[i] >> 24 & 255;
            BattlegroundQueueTypeId bgQueueTypeId = BattlegroundQueueTypeId(scheduled[i] >> 16 & 255);
            BattlegroundTypeId bgTypeId = BattlegroundTypeId((scheduled[i] >> 8) & 255);
            BattlegroundBracketId bracket_id = BattlegroundBracketId(scheduled[i] & 255);
            m_BattlegroundQueues[bgQueueTypeId].BattlegroundQueueUpdate(diff, bgTypeId, bracket_id, arenaType, arenaMMRating > 0, arenaMMRating);
        }
    }

    // if rating difference counts, maybe force-update queues
    if (sWorld->getIntConfig(CONFIG_ARENA_MAX_RATING_DIFFERENCE) && sWorld->getIntConfig(CONFIG_ARENA_RATING_DISCARD_TIMER))
    {
        // it's time to force update
        if (m_NextRatingDiscardUpdate < diff)
        {
            // forced update for rated arenas (scan all, but skipped non rated)
            sLog->outDebug(LOG_FILTER_BATTLEGROUND, "BattlegroundMgr: UPDATING ARENA QUEUES");
            for (int qtype = BATTLEGROUND_QUEUE_2v2; qtype <= BATTLEGROUND_QUEUE_5v5; ++qtype)
                for (int bracket = BG_BRACKET_ID_FIRST; bracket < MAX_BATTLEGROUND_BRACKETS; ++bracket)
                    m_BattlegroundQueues[qtype].BattlegroundQueueUpdate(diff,
                        BATTLEGROUND_AA, BattlegroundBracketId(bracket),
                        BattlegroundMgr::BGArenaType(BattlegroundQueueTypeId(qtype)), true, 0);

            m_NextRatingDiscardUpdate = sWorld->getIntConfig(CONFIG_ARENA_RATING_DISCARD_TIMER);
        }
        else
            m_NextRatingDiscardUpdate -= diff;
    }
    if (sWorld->getBoolConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS))
    {
        if (m_AutoDistributionTimeChecker < diff)
        {
            if (time(NULL) > m_NextAutoDistributionTime)
            {
                sArenaTeamMgr->DistributeArenaPoints();
                m_NextAutoDistributionTime = m_NextAutoDistributionTime + BATTLEGROUND_ARENA_POINT_DISTRIBUTION_DAY * sWorld->getIntConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_INTERVAL_DAYS);
                sWorld->setWorldState(WS_ARENA_DISTRIBUTION_TIME, uint64(m_NextAutoDistributionTime));
            }
            m_AutoDistributionTimeChecker = 600000; // check 10 minutes
        }
        else
            m_AutoDistributionTimeChecker -= diff;
    }
}

void BattlegroundMgr::BuildBattlegroundStatusPacket(WorldPacket* data, Battleground* bg, uint8 QueueSlot, uint8 StatusID, uint32 Time1, uint32 Time2, uint8 arenatype, uint8 uiFrame)
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
    sLog->outDebug(LOG_FILTER_NETWORKIO, "BattlegroundMgr::BuildBattlegroundStatusPacket: arenatype = %u for bg instanceID %u, TypeID %u.", arenatype, bg->GetClientInstanceID(), bg->GetTypeID());
    *data << uint8(bg->isArena() ? 0xC : 0x2);
    *data << uint32(bg->GetTypeID());
    *data << uint16(0x1F90);
    // End of uint64 segment, decomposed this way for simplicity
    *data << uint8(0);                                      // 3.3.0, some level, only saw 80...
    *data << uint8(0);                                      // 3.3.0, some level, only saw 80...
    *data << uint32(bg->GetClientInstanceID());
    // alliance/horde for BG and skirmish/rated for Arenas
    // following displays the minimap-icon 0 = faction icon 1 = arenaicon
    *data << uint8(bg->isRated());                          // 1 for rated match, 0 for bg or non rated match

    *data << uint32(StatusID);                              // status
    switch (StatusID)
    {
        case STATUS_WAIT_QUEUE:                             // status_in_queue
            *data << uint32(Time1);                         // average wait time, milliseconds
            *data << uint32(Time2);                         // time in queue, updated every minute!, milliseconds
            break;
        case STATUS_WAIT_JOIN:                              // status_invite
            *data << uint32(bg->GetMapId());                // map id
            *data << uint64(0);                             // 3.3.5, unknown
            *data << uint32(Time1);                         // time to remove from queue, milliseconds
            break;
        case STATUS_IN_PROGRESS:                            // status_in_progress
            *data << uint32(bg->GetMapId());                // map id
            *data << uint64(0);                             // 3.3.5, unknown
            *data << uint32(Time1);                         // time to bg auto leave, 0 at bg start, 120000 after bg end, milliseconds
            *data << uint32(Time2);                         // time from bg start, milliseconds
            *data << uint8(uiFrame);
            break;
        default:
            sLog->outError("Unknown BG status!");
            break;
    }
}

void BattlegroundMgr::BuildPvpLogDataPacket(WorldPacket* data, Battleground* bg)
{
    uint8 type = (bg->isArena() ? 1 : 0);
                                                            // last check on 3.0.3
    data->Initialize(MSG_PVP_LOG_DATA, (1+1+4+40*bg->GetPlayerScoresSize()));
    *data << uint8(type);                                   // type (battleground=0/arena=1)

    if (type)                                                // arena
    {
        // it seems this must be according to BG_WINNER_A/H and _NOT_ BG_TEAM_A/H
        for (int8 i = 1; i >= 0; --i)
        {
            int32 rating_change = bg->GetArenaTeamRatingChangeByIndex(i);

            uint32 pointsLost = rating_change < 0 ? -rating_change : 0;
            uint32 pointsGained = rating_change > 0 ? rating_change : 0;
            uint32 MatchmakerRating = bg->GetArenaMatchmakerRatingByIndex(i);

            *data << uint32(pointsLost);                    // Rating Lost
            *data << uint32(pointsGained);                  // Rating gained
            *data << uint32(MatchmakerRating);              // Matchmaking Value
            sLog->outDebug(LOG_FILTER_BATTLEGROUND, "rating change: %d", rating_change);
        }
        for (int8 i = 1; i >= 0; --i)
        {
            if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(bg->GetArenaTeamIdByIndex(i)))
                *data << at->GetName();
            else
                *data << uint8(0);
        }
    }

    if (bg->GetStatus() != STATUS_WAIT_LEAVE)
        *data << uint8(0);                                  // bg not ended
    else
    {
        *data << uint8(1);                                  // bg ended
        *data << uint8(bg->GetWinner());                    // who win
    }

    size_t wpos = data->wpos();
    uint32 scoreCount = 0;
    *data << uint32(scoreCount);                            // placeholder

    Battleground::BattlegroundScoreMap::const_iterator itr2 = bg->GetPlayerScoresBegin();
    for (Battleground::BattlegroundScoreMap::const_iterator itr = itr2; itr != bg->GetPlayerScoresEnd();)
    {
        itr2 = itr++;
        if (!bg->IsPlayerInBattleground(itr2->first))
        {
            sLog->outError("Player " UI64FMTD " has scoreboard entry for battleground %u but is not in battleground!", itr->first, bg->GetTypeID(true));
            continue;
        }

        *data << uint64(itr2->first);
        *data << uint32(itr2->second->KillingBlows);
        if (type == 0)
        {
            *data << uint32(itr2->second->HonorableKills);
            *data << uint32(itr2->second->Deaths);
            *data << uint32(itr2->second->BonusHonor);
        }
        else
        {
            Player* player = ObjectAccessor::FindPlayer(itr2->first);
            uint32 team = bg->GetPlayerTeam(itr2->first);
            if (!team && player)
                team = player->GetBGTeam();
            *data << uint8(team == ALLIANCE ? 1 : 0); // green or yellow
        }
        *data << uint32(itr2->second->DamageDone);              // damage done
        *data << uint32(itr2->second->HealingDone);             // healing done
        switch (bg->GetTypeID(true))                             // battleground specific things
        {
            case BATTLEGROUND_RB:
                switch (bg->GetMapId())
                {
                    case 489:
                        *data << uint32(0x00000002);            // count of next fields
                        *data << uint32(((BattlegroundWGScore*)itr2->second)->FlagCaptures);        // flag captures
                        *data << uint32(((BattlegroundWGScore*)itr2->second)->FlagReturns);         // flag returns
                        break;
                    case 566:
                        *data << uint32(0x00000001);            // count of next fields
                        *data << uint32(((BattlegroundEYScore*)itr2->second)->FlagCaptures);        // flag captures
                        break;
                    case 529:
                        *data << uint32(0x00000002);            // count of next fields
                        *data << uint32(((BattlegroundABScore*)itr2->second)->BasesAssaulted);      // bases asssulted
                        *data << uint32(((BattlegroundABScore*)itr2->second)->BasesDefended);       // bases defended
                        break;
                    case 30:
                        *data << uint32(0x00000005);            // count of next fields
                        *data << uint32(((BattlegroundAVScore*)itr2->second)->GraveyardsAssaulted); // GraveyardsAssaulted
                        *data << uint32(((BattlegroundAVScore*)itr2->second)->GraveyardsDefended);  // GraveyardsDefended
                        *data << uint32(((BattlegroundAVScore*)itr2->second)->TowersAssaulted);     // TowersAssaulted
                        *data << uint32(((BattlegroundAVScore*)itr2->second)->TowersDefended);      // TowersDefended
                        *data << uint32(((BattlegroundAVScore*)itr2->second)->MinesCaptured);       // MinesCaptured
                        break;
                    case 607:
                        *data << uint32(0x00000002);            // count of next fields
                        *data << uint32(((BattlegroundSAScore*)itr2->second)->demolishers_destroyed);
                        *data << uint32(((BattlegroundSAScore*)itr2->second)->gates_destroyed);
                        break;
                    case 628:                                   // IC
                        *data << uint32(0x00000002);            // count of next fields
                        *data << uint32(((BattlegroundICScore*)itr2->second)->BasesAssaulted);       // bases asssulted
                        *data << uint32(((BattlegroundICScore*)itr2->second)->BasesDefended);        // bases defended
                    default:
                        *data << uint32(0);
                        break;
                }
            case BATTLEGROUND_AV:
                *data << uint32(0x00000005);                    // count of next fields
                *data << uint32(((BattlegroundAVScore*)itr2->second)->GraveyardsAssaulted); // GraveyardsAssaulted
                *data << uint32(((BattlegroundAVScore*)itr2->second)->GraveyardsDefended);  // GraveyardsDefended
                *data << uint32(((BattlegroundAVScore*)itr2->second)->TowersAssaulted);     // TowersAssaulted
                *data << uint32(((BattlegroundAVScore*)itr2->second)->TowersDefended);      // TowersDefended
                *data << uint32(((BattlegroundAVScore*)itr2->second)->MinesCaptured);       // MinesCaptured
                break;
            case BATTLEGROUND_WS:
                *data << uint32(0x00000002);                    // count of next fields
                *data << uint32(((BattlegroundWGScore*)itr2->second)->FlagCaptures);        // flag captures
                *data << uint32(((BattlegroundWGScore*)itr2->second)->FlagReturns);         // flag returns
                break;
            case BATTLEGROUND_AB:
                *data << uint32(0x00000002);                    // count of next fields
                *data << uint32(((BattlegroundABScore*)itr2->second)->BasesAssaulted);      // bases asssulted
                *data << uint32(((BattlegroundABScore*)itr2->second)->BasesDefended);       // bases defended
                break;
            case BATTLEGROUND_EY:
                *data << uint32(0x00000001);                    // count of next fields
                *data << uint32(((BattlegroundEYScore*)itr2->second)->FlagCaptures);        // flag captures
                break;
            case BATTLEGROUND_SA:
                *data << uint32(0x00000002);                    // count of next fields
                *data << uint32(((BattlegroundSAScore*)itr2->second)->demolishers_destroyed);
                *data << uint32(((BattlegroundSAScore*)itr2->second)->gates_destroyed);
                break;
            case BATTLEGROUND_IC:                           // wotlk
                *data << uint32(0x00000002);                // count of next fields
                *data << uint32(((BattlegroundICScore*)itr2->second)->BasesAssaulted);       // bases asssulted
                *data << uint32(((BattlegroundICScore*)itr2->second)->BasesDefended);        // bases defended
                break;
            case BATTLEGROUND_NA:
            case BATTLEGROUND_BE:
            case BATTLEGROUND_AA:
            case BATTLEGROUND_RL:
            case BATTLEGROUND_DS:                               // wotlk
            case BATTLEGROUND_RV:                               // wotlk
                *data << uint32(0);
                break;
            default:
                sLog->outDebug(LOG_FILTER_NETWORKIO, "Unhandled MSG_PVP_LOG_DATA for BG id %u", bg->GetTypeID());
                *data << uint32(0);
                break;
        }
        // should never happen
        if (++scoreCount >= bg->GetMaxPlayers() && itr != bg->GetPlayerScoresEnd())
        {
            sLog->outError("Battleground %u scoreboard has more entries (%u) than allowed players in this bg (%u)", bg->GetTypeID(true), bg->GetPlayerScoresSize(), bg->GetMaxPlayers());
            break;
        }
    }

    data->put(wpos, scoreCount);
}

void BattlegroundMgr::BuildGroupJoinedBattlegroundPacket(WorldPacket* data, GroupJoinBattlegroundResult result)
{
    data->Initialize(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
    *data << int32(result);
    if (result == ERR_BATTLEGROUND_JOIN_TIMED_OUT || result == ERR_BATTLEGROUND_JOIN_FAILED)
        *data << uint64(0);                                 // player guid
}

void BattlegroundMgr::BuildUpdateWorldStatePacket(WorldPacket* data, uint32 field, uint32 value)
{
    data->Initialize(SMSG_UPDATE_WORLD_STATE, 4+4);
    *data << uint32(field);
    *data << uint32(value);
}

void BattlegroundMgr::BuildPlaySoundPacket(WorldPacket* data, uint32 soundid)
{
    data->Initialize(SMSG_PLAY_SOUND, 4);
    *data << uint32(soundid);
}

void BattlegroundMgr::BuildPlayerLeftBattlegroundPacket(WorldPacket* data, uint64 guid)
{
    data->Initialize(SMSG_BATTLEGROUND_PLAYER_LEFT, 8);
    *data << uint64(guid);
}

void BattlegroundMgr::BuildPlayerJoinedBattlegroundPacket(WorldPacket* data, Player* player)
{
    data->Initialize(SMSG_BATTLEGROUND_PLAYER_JOINED, 8);
    *data << uint64(player->GetGUID());
}

Battleground* BattlegroundMgr::GetBattlegroundThroughClientInstance(uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    //cause at HandleBattlegroundJoinOpcode the clients sends the instanceid he gets from
    //SMSG_BATTLEFIELD_LIST we need to find the battleground with this clientinstance-id
    Battleground* bg = GetBattlegroundTemplate(bgTypeId);
    if (!bg)
        return NULL;

    if (bg->isArena())
        return GetBattleground(instanceId, bgTypeId);

    for (BattlegroundSet::iterator itr = m_Battlegrounds[bgTypeId].begin(); itr != m_Battlegrounds[bgTypeId].end(); ++itr)
    {
        if (itr->second->GetClientInstanceID() == instanceId)
            return itr->second;
    }
    return NULL;
}

Battleground* BattlegroundMgr::GetBattleground(uint32 InstanceID, BattlegroundTypeId bgTypeId)
{
    if (!InstanceID)
        return NULL;
    //search if needed
    BattlegroundSet::iterator itr;
    if (bgTypeId == BATTLEGROUND_TYPE_NONE)
    {
        for (uint32 i = BATTLEGROUND_AV; i < MAX_BATTLEGROUND_TYPE_ID; i++)
        {
            itr = m_Battlegrounds[i].find(InstanceID);
            if (itr != m_Battlegrounds[i].end())
                return itr->second;
        }
        return NULL;
    }
    itr = m_Battlegrounds[bgTypeId].find(InstanceID);
    return ((itr != m_Battlegrounds[bgTypeId].end()) ? itr->second : NULL);
}

Battleground* BattlegroundMgr::GetBattlegroundTemplate(BattlegroundTypeId bgTypeId)
{
    //map is sorted and we can be sure that lowest instance id has only BG template
    return m_Battlegrounds[bgTypeId].empty() ? NULL : m_Battlegrounds[bgTypeId].begin()->second;
}

uint32 BattlegroundMgr::CreateClientVisibleInstanceId(BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id)
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
    for (std::set<uint32>::iterator itr = m_ClientBattlegroundIds[bgTypeId][bracket_id].begin(); itr != m_ClientBattlegroundIds[bgTypeId][bracket_id].end();)
    {
        if ((++lastId) != *itr)                             //if there is a gap between the ids, we will break..
            break;
        lastId = *itr;
    }
    m_ClientBattlegroundIds[bgTypeId][bracket_id].insert(lastId + 1);
    return lastId + 1;
}

// create a new battleground that will really be used to play
Battleground* BattlegroundMgr::CreateNewBattleground(BattlegroundTypeId bgTypeId, PvPDifficultyEntry const* bracketEntry, uint8 arenaType, bool isRated)
{
    // get the template BG
    Battleground* bg_template = GetBattlegroundTemplate(bgTypeId);
    BattlegroundSelectionWeightMap* selectionWeights = NULL;

    if (!bg_template)
    {
        sLog->outError("Battleground: CreateNewBattleground - bg template not found for %u", bgTypeId);
        return NULL;
    }
    bool isRandom = false;

    if (bg_template->isArena())
        selectionWeights = &m_ArenaSelectionWeights;
    else if (bgTypeId == BATTLEGROUND_RB)
    {
        selectionWeights = &m_BGSelectionWeights;
        isRandom = true;
    }

    if (selectionWeights)
    {
        if (selectionWeights->empty())
           return NULL;
        uint32 Weight = 0;
        uint32 selectedWeight = 0;
        bgTypeId = BATTLEGROUND_TYPE_NONE;
        // Get sum of all weights
        for (BattlegroundSelectionWeightMap::const_iterator it = selectionWeights->begin(); it != selectionWeights->end(); ++it)
            Weight += it->second;
        if (!Weight)
            return NULL;
        // Select a random value
        selectedWeight = urand(0, Weight-1);

        // Select the correct bg (if we have in DB A(10), B(20), C(10), D(15) --> [0---A---9|10---B---29|30---C---39|40---D---54])
        Weight = 0;
        for (BattlegroundSelectionWeightMap::const_iterator it = selectionWeights->begin(); it != selectionWeights->end(); ++it)
        {
            Weight += it->second;
            if (selectedWeight < Weight)
            {
                bgTypeId = it->first;
                break;
            }
        }
        bg_template = GetBattlegroundTemplate(bgTypeId);
        if (!bg_template)
        {
            sLog->outError("Battleground: CreateNewBattleground - bg template not found for %u", bgTypeId);
            return NULL;
        }
    }

    Battleground* bg = NULL;
    // create a copy of the BG template
    switch (bgTypeId)
    {
        case BATTLEGROUND_AV:
            bg = new BattlegroundAV(*(BattlegroundAV*)bg_template);
            break;
        case BATTLEGROUND_WS:
            bg = new BattlegroundWS(*(BattlegroundWS*)bg_template);
            break;
        case BATTLEGROUND_AB:
            bg = new BattlegroundAB(*(BattlegroundAB*)bg_template);
            break;
        case BATTLEGROUND_NA:
            bg = new BattlegroundNA(*(BattlegroundNA*)bg_template);
            break;
        case BATTLEGROUND_BE:
            bg = new BattlegroundBE(*(BattlegroundBE*)bg_template);
            break;
        case BATTLEGROUND_AA:
            bg = new BattlegroundAA(*(BattlegroundAA*)bg_template);
            break;
        case BATTLEGROUND_EY:
            bg = new BattlegroundEY(*(BattlegroundEY*)bg_template);
            break;
        case BATTLEGROUND_RL:
            bg = new BattlegroundRL(*(BattlegroundRL*)bg_template);
            break;
        case BATTLEGROUND_SA:
            bg = new BattlegroundSA(*(BattlegroundSA*)bg_template);
            break;
        case BATTLEGROUND_DS:
            bg = new BattlegroundDS(*(BattlegroundDS*)bg_template);
            break;
        case BATTLEGROUND_RV:
            bg = new BattlegroundRV(*(BattlegroundRV*)bg_template);
            break;
        case BATTLEGROUND_IC:
            bg = new BattlegroundIC(*(BattlegroundIC*)bg_template);
            break;
        case BATTLEGROUND_RB:
            bg = new BattlegroundRB(*(BattlegroundRB*)bg_template);
            break;
        default:
            //error, but it is handled few lines above
            return 0;
    }

    // set battelground difficulty before initialization
    bg->SetBracket(bracketEntry);

    // generate a new instance id
    bg->SetInstanceID(sMapMgr->GenerateInstanceId()); // set instance id
    bg->SetClientInstanceID(CreateClientVisibleInstanceId(isRandom ? BATTLEGROUND_RB : bgTypeId, bracketEntry->GetBracketId()));

    // reset the new bg (set status to status_wait_queue from status_none)
    bg->Reset();

    // start the joining of the bg
    bg->SetStatus(STATUS_WAIT_JOIN);
    bg->SetArenaType(arenaType);
    bg->SetRated(isRated);
    bg->SetRandom(isRandom);
    bg->SetTypeID(isRandom ? BATTLEGROUND_RB : bgTypeId);
    bg->SetRandomTypeID(bgTypeId);

    return bg;
}

// used to create the BG templates
uint32 BattlegroundMgr::CreateBattleground(CreateBattlegroundData& data)
{
    // Create the BG
    Battleground* bg = NULL;
    switch (data.bgTypeId)
    {
        case BATTLEGROUND_AV: bg = new BattlegroundAV; break;
        case BATTLEGROUND_WS: bg = new BattlegroundWS; break;
        case BATTLEGROUND_AB: bg = new BattlegroundAB; break;
        case BATTLEGROUND_NA: bg = new BattlegroundNA; break;
        case BATTLEGROUND_BE: bg = new BattlegroundBE; break;
        case BATTLEGROUND_AA: bg = new BattlegroundAA; break;
        case BATTLEGROUND_EY: bg = new BattlegroundEY; break;
        case BATTLEGROUND_RL: bg = new BattlegroundRL; break;
        case BATTLEGROUND_SA: bg = new BattlegroundSA; break;
        case BATTLEGROUND_DS: bg = new BattlegroundDS; break;
        case BATTLEGROUND_RV: bg = new BattlegroundRV; break;
        case BATTLEGROUND_IC: bg = new BattlegroundIC; break;
        case BATTLEGROUND_RB: bg = new BattlegroundRB; break;
        default:
            bg = new Battleground;
            break;
    }

    bg->SetMapId(data.MapID);
    bg->SetTypeID(data.bgTypeId);
    bg->SetInstanceID(0);
    bg->SetArenaorBGType(data.IsArena);
    bg->SetMinPlayersPerTeam(data.MinPlayersPerTeam);
    bg->SetMaxPlayersPerTeam(data.MaxPlayersPerTeam);
    bg->SetMinPlayers(data.MinPlayersPerTeam* 2);
    bg->SetMaxPlayers(data.MaxPlayersPerTeam* 2);
    bg->SetName(data.BattlegroundName);
    bg->SetTeamStartLoc(ALLIANCE, data.Team1StartLocX, data.Team1StartLocY, data.Team1StartLocZ, data.Team1StartLocO);
    bg->SetTeamStartLoc(HORDE,    data.Team2StartLocX, data.Team2StartLocY, data.Team2StartLocZ, data.Team2StartLocO);
    bg->SetLevelRange(data.LevelMin, data.LevelMax);
    bg->SetScriptId(data.scriptId);

    // add bg to update list
    AddBattleground(bg->GetInstanceID(), bg->GetTypeID(), bg);

    // return some not-null value, bgTypeId is good enough for me
    return data.bgTypeId;
}

void BattlegroundMgr::CreateInitialBattlegrounds()
{
    uint32 oldMSTime = getMSTime();

    uint8 selectionWeight;
    BattlemasterListEntry const* bl;

    //                                               0   1                  2                  3       4       5                 6               7              8            9       10
    QueryResult result = WorldDatabase.Query("SELECT id, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, AllianceStartLoc, AllianceStartO, HordeStartLoc, HordeStartO, Weight, ScriptName FROM battleground_template");

    if (!result)
    {
        sLog->outErrorDb(">> Loaded 0 battlegrounds. DB table `battleground_template` is empty.");
        sLog->outString();
        return;
    }

    uint32 count = 0, startId;

    do
    {
        Field* fields = result->Fetch();

        uint32 bgTypeID_ = fields[0].GetUInt32();
        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, bgTypeID_, NULL))
            continue;

        // can be overwrite by values from DB
        bl = sBattlemasterListStore.LookupEntry(bgTypeID_);
        if (!bl)
        {
            sLog->outError("Battleground ID %u not found in BattlemasterList.dbc. Battleground not created.", bgTypeID_);
            continue;
        }

        CreateBattlegroundData data;
        data.bgTypeId = BattlegroundTypeId(bgTypeID_);
        data.IsArena = (bl->type == TYPE_ARENA);
        data.MinPlayersPerTeam = fields[1].GetUInt32();
        data.MaxPlayersPerTeam = fields[2].GetUInt32();
        data.LevelMin = fields[3].GetUInt32();
        data.LevelMax = fields[4].GetUInt32();
        //check values from DB
        if (data.MaxPlayersPerTeam == 0 || data.MinPlayersPerTeam == 0 || data.MinPlayersPerTeam > data.MaxPlayersPerTeam)
        {
            data.MinPlayersPerTeam = 0;                          // by default now expected strong full bg requirement
            data.MaxPlayersPerTeam = 40;
        }
        if (data.LevelMin == 0 || data.LevelMax == 0 || data.LevelMin > data.LevelMax)
        {
            //TO-DO: FIX ME
            data.LevelMin = 0;//bl->minlvl;
            data.LevelMax = 80;//bl->maxlvl;
        }

        startId = fields[5].GetUInt32();
        if (WorldSafeLocsEntry const* start = sWorldSafeLocsStore.LookupEntry(startId))
        {
            data.Team1StartLocX = start->x;
            data.Team1StartLocY = start->y;
            data.Team1StartLocZ = start->z;
            data.Team1StartLocO = fields[6].GetFloat();
        }
        else if (data.bgTypeId == BATTLEGROUND_AA || data.bgTypeId == BATTLEGROUND_RB)
        {
            data.Team1StartLocX = 0;
            data.Team1StartLocY = 0;
            data.Team1StartLocZ = 0;
            data.Team1StartLocO = fields[6].GetFloat();
        }
        else
        {
            sLog->outErrorDb("Table `battleground_template` for id %u have non-existed WorldSafeLocs.dbc id %u in field `AllianceStartLoc`. BG not created.", data.bgTypeId, startId);
            continue;
        }

        startId = fields[7].GetUInt32();
        if (WorldSafeLocsEntry const* start = sWorldSafeLocsStore.LookupEntry(startId))
        {
            data.Team2StartLocX = start->x;
            data.Team2StartLocY = start->y;
            data.Team2StartLocZ = start->z;
            data.Team2StartLocO = fields[8].GetFloat();
        }
        else if (data.bgTypeId == BATTLEGROUND_AA || data.bgTypeId == BATTLEGROUND_RB)
        {
            data.Team2StartLocX = 0;
            data.Team2StartLocY = 0;
            data.Team2StartLocZ = 0;
            data.Team2StartLocO = fields[8].GetFloat();
        }
        else
        {
            sLog->outErrorDb("Table `battleground_template` for id %u have non-existed WorldSafeLocs.dbc id %u in field `HordeStartLoc`. BG not created.", data.bgTypeId, startId);
            continue;
        }

        selectionWeight = fields[9].GetUInt8();
        data.scriptId = sObjectMgr->GetScriptId(fields[10].GetCString());
        data.BattlegroundName = bl->name[sWorld->GetDefaultDbcLocale()];
        data.MapID = bl->mapid[0];

        if (!CreateBattleground(data))
            continue;

        if (data.IsArena)
        {
            if (data.bgTypeId != BATTLEGROUND_AA)
                m_ArenaSelectionWeights[data.bgTypeId] = selectionWeight;
        }
        else if (data.bgTypeId != BATTLEGROUND_RB)
            m_BGSelectionWeights[data.bgTypeId] = selectionWeight;
        ++count;
    }
    while (result->NextRow());

    sLog->outString(">> Loaded %u battlegrounds in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

void BattlegroundMgr::InitAutomaticArenaPointDistribution()
{
    if (!sWorld->getBoolConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS))
        return;

    time_t wstime = time_t(sWorld->getWorldState(WS_ARENA_DISTRIBUTION_TIME));
    time_t curtime = time(NULL);
    sLog->outDebug(LOG_FILTER_BATTLEGROUND, "Initializing Automatic Arena Point Distribution");
    if (wstime < curtime)
    {
        m_NextAutoDistributionTime = curtime;           // reset will be called in the next update
        sLog->outDebug(LOG_FILTER_BATTLEGROUND, "Battleground: Next arena point distribution time in the past, reseting it now.");
    }
    else
        m_NextAutoDistributionTime = wstime;
    sLog->outDebug(LOG_FILTER_BATTLEGROUND, "Automatic Arena Point Distribution initialized.");
}

void BattlegroundMgr::BuildBattlegroundListPacket(WorldPacket* data, uint64 guid, Player* player, BattlegroundTypeId bgTypeId, uint8 fromWhere)
{
    if (!player)
        return;

    uint32 winner_kills = player->GetRandomWinner() ? BG_REWARD_WINNER_HONOR_LAST : BG_REWARD_WINNER_HONOR_FIRST;
    uint32 winner_arena = player->GetRandomWinner() ? BG_REWARD_WINNER_ARENA_LAST : BG_REWARD_WINNER_ARENA_FIRST;
    uint32 loser_kills = player->GetRandomWinner() ? BG_REWARD_LOSER_HONOR_LAST : BG_REWARD_LOSER_HONOR_FIRST;

    winner_kills = Trinity::Honor::hk_honor_at_level(player->getLevel(), float(winner_kills));
    loser_kills = Trinity::Honor::hk_honor_at_level(player->getLevel(), float(loser_kills));

    data->Initialize(SMSG_BATTLEFIELD_LIST);
    *data << uint64(guid);                                  // battlemaster guid
    *data << uint8(fromWhere);                              // from where you joined
    *data << uint32(bgTypeId);                              // battleground id
    *data << uint8(0);                                      // unk
    *data << uint8(0);                                      // unk

    // Rewards
    *data << uint8(player->GetRandomWinner());               // 3.3.3 hasWin
    *data << uint32(winner_kills);                           // 3.3.3 winHonor
    *data << uint32(winner_arena);                           // 3.3.3 winArena
    *data << uint32(loser_kills);                          // 3.3.3 lossHonor

    uint8 isRandom = bgTypeId == BATTLEGROUND_RB;

    *data << uint8(isRandom);                               // 3.3.3 isRandom
    if (isRandom)
    {
        // Rewards (random)
        *data << uint8(player->GetRandomWinner());           // 3.3.3 hasWin_Random
        *data << uint32(winner_kills);                       // 3.3.3 winHonor_Random
        *data << uint32(winner_arena);                       // 3.3.3 winArena_Random
        *data << uint32(loser_kills);                      // 3.3.3 lossHonor_Random
    }

    if (bgTypeId == BATTLEGROUND_AA)                         // arena
    {
        *data << uint32(0);                                 // unk (count?)
    }
    else                                                    // battleground
    {
        size_t count_pos = data->wpos();
        *data << uint32(0);                                 // number of bg instances

        if (Battleground* bgTemplate = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId))
        {
            // expected bracket entry
            if (PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bgTemplate->GetMapId(), player->getLevel()))
            {
                uint32 count = 0;
                BattlegroundBracketId bracketId = bracketEntry->GetBracketId();
                for (std::set<uint32>::iterator itr = m_ClientBattlegroundIds[bgTypeId][bracketId].begin(); itr != m_ClientBattlegroundIds[bgTypeId][bracketId].end();++itr)
                {
                    *data << uint32(*itr);
                    ++count;
                }
                data->put<uint32>(count_pos, count);
            }
        }
    }
}

void BattlegroundMgr::SendToBattleground(Player* player, uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    Battleground* bg = GetBattleground(instanceId, bgTypeId);
    if (bg)
    {
        uint32 mapid = bg->GetMapId();
        float x, y, z, O;
        uint32 team = player->GetBGTeam();
        if (team == 0)
            team = player->GetTeam();
        bg->GetTeamStartLoc(team, x, y, z, O);

        sLog->outDetail("BATTLEGROUND: Sending %s to map %u, X %f, Y %f, Z %f, O %f", player->GetName(), mapid, x, y, z, O);
        player->TeleportTo(mapid, x, y, z, O);
    }
    else
    {
        sLog->outError("player %u is trying to port to non-existent bg instance %u", player->GetGUIDLow(), instanceId);
    }
}

void BattlegroundMgr::SendAreaSpiritHealerQueryOpcode(Player* player, Battleground* bg, uint64 guid)
{
    WorldPacket data(SMSG_AREA_SPIRIT_HEALER_TIME, 12);
    uint32 time_ = 30000 - bg->GetLastResurrectTime();      // resurrect every 30 seconds
    if (time_ == uint32(-1))
        time_ = 0;
    data << guid << time_;
    player->GetSession()->SendPacket(&data);
}

bool BattlegroundMgr::IsArenaType(BattlegroundTypeId bgTypeId)
{
    return (bgTypeId == BATTLEGROUND_AA ||
        bgTypeId == BATTLEGROUND_BE ||
        bgTypeId == BATTLEGROUND_NA ||
        bgTypeId == BATTLEGROUND_DS ||
        bgTypeId == BATTLEGROUND_RV ||
        bgTypeId == BATTLEGROUND_RL);
}

BattlegroundQueueTypeId BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId bgTypeId, uint8 arenaType)
{
    switch (bgTypeId)
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
            switch (arenaType)
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

BattlegroundTypeId BattlegroundMgr::BGTemplateId(BattlegroundQueueTypeId bgQueueTypeId)
{
    switch (bgQueueTypeId)
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
            return BattlegroundTypeId(0);                   // used for unknown template (it existed and do nothing)
    }
}

uint8 BattlegroundMgr::BGArenaType(BattlegroundQueueTypeId bgQueueTypeId)
{
    switch (bgQueueTypeId)
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

void BattlegroundMgr::ToggleTesting()
{
    m_Testing = !m_Testing;
    if (m_Testing)
        sWorld->SendWorldText(LANG_DEBUG_BG_ON);
    else
        sWorld->SendWorldText(LANG_DEBUG_BG_OFF);
}

void BattlegroundMgr::ToggleArenaTesting()
{
    m_ArenaTesting = !m_ArenaTesting;
    if (m_ArenaTesting)
        sWorld->SendWorldText(LANG_DEBUG_ARENA_ON);
    else
        sWorld->SendWorldText(LANG_DEBUG_ARENA_OFF);
}

void BattlegroundMgr::SetHolidayWeekends(uint32 mask)
{
    for (uint32 bgtype = 1; bgtype < MAX_BATTLEGROUND_TYPE_ID; ++bgtype)
    {
        if (Battleground* bg = GetBattlegroundTemplate(BattlegroundTypeId(bgtype)))
        {
            bg->SetHoliday(mask & (1 << bgtype));
        }
    }
}

void BattlegroundMgr::ScheduleQueueUpdate(uint32 arenaMatchmakerRating, uint8 arenaType, BattlegroundQueueTypeId bgQueueTypeId, BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id)
{
    //This method must be atomic, TODO add mutex
    //we will use only 1 number created of bgTypeId and bracket_id
    uint64 schedule_id = ((uint64)arenaMatchmakerRating << 32) | (arenaType << 24) | (bgQueueTypeId << 16) | (bgTypeId << 8) | bracket_id;
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

uint32 BattlegroundMgr::GetMaxRatingDifference() const
{
    // this is for stupid people who can't use brain and set max rating difference to 0
    uint32 diff = sWorld->getIntConfig(CONFIG_ARENA_MAX_RATING_DIFFERENCE);
    if (diff == 0)
        diff = 5000;
    return diff;
}

uint32 BattlegroundMgr::GetRatingDiscardTimer() const
{
    return sWorld->getIntConfig(CONFIG_ARENA_RATING_DISCARD_TIMER);
}

uint32 BattlegroundMgr::GetPrematureFinishTime() const
{
    return sWorld->getIntConfig(CONFIG_BATTLEGROUND_PREMATURE_FINISH_TIMER);
}

void BattlegroundMgr::LoadBattleMastersEntry()
{
    uint32 oldMSTime = getMSTime();

    mBattleMastersMap.clear();                                  // need for reload case

    QueryResult result = WorldDatabase.Query("SELECT entry, bg_template FROM battlemaster_entry");

    if (!result)
    {
        sLog->outString(">> Loaded 0 battlemaster entries. DB table `battlemaster_entry` is empty!");
        sLog->outString();
        return;
    }

    uint32 count = 0;

    do
    {
        ++count;

        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        uint32 bgTypeId  = fields[1].GetUInt32();
        if (!sBattlemasterListStore.LookupEntry(bgTypeId))
        {
            sLog->outErrorDb("Table `battlemaster_entry` contain entry %u for not existed battleground type %u, ignored.", entry, bgTypeId);
            continue;
        }

        mBattleMastersMap[entry] = BattlegroundTypeId(bgTypeId);
    }
    while (result->NextRow());

    sLog->outString(">> Loaded %u battlemaster entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    sLog->outString();
}

HolidayIds BattlegroundMgr::BGTypeToWeekendHolidayId(BattlegroundTypeId bgTypeId)
{
    switch (bgTypeId)
    {
        case BATTLEGROUND_AV: return HOLIDAY_CALL_TO_ARMS_AV;
        case BATTLEGROUND_EY: return HOLIDAY_CALL_TO_ARMS_EY;
        case BATTLEGROUND_WS: return HOLIDAY_CALL_TO_ARMS_WS;
        case BATTLEGROUND_SA: return HOLIDAY_CALL_TO_ARMS_SA;
        case BATTLEGROUND_AB: return HOLIDAY_CALL_TO_ARMS_AB;
        case BATTLEGROUND_IC: return HOLIDAY_CALL_TO_ARMS_IC;
        default: return HOLIDAY_NONE;
    }
}

BattlegroundTypeId BattlegroundMgr::WeekendHolidayIdToBGType(HolidayIds holiday)
{
    switch (holiday)
    {
        case HOLIDAY_CALL_TO_ARMS_AV: return BATTLEGROUND_AV;
        case HOLIDAY_CALL_TO_ARMS_EY: return BATTLEGROUND_EY;
        case HOLIDAY_CALL_TO_ARMS_WS: return BATTLEGROUND_WS;
        case HOLIDAY_CALL_TO_ARMS_SA: return BATTLEGROUND_SA;
        case HOLIDAY_CALL_TO_ARMS_AB: return BATTLEGROUND_AB;
        case HOLIDAY_CALL_TO_ARMS_IC: return BATTLEGROUND_IC;
        default: return BATTLEGROUND_TYPE_NONE;
    }
}

bool BattlegroundMgr::IsBGWeekend(BattlegroundTypeId bgTypeId)
{
    return IsHolidayActive(BGTypeToWeekendHolidayId(bgTypeId));
}