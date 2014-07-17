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
#include "BattlegroundRL.h"
#include "BattlegroundSA.h"
#include "BattlegroundDS.h"
#include "BattlegroundRV.h"
#include "BattlegroundIC.h"
#include "Chat.h"
#include "Map.h"
#include "MapInstanced.h"
#include "MapManager.h"
#include "Player.h"
#include "GameEventMgr.h"
#include "SharedDefines.h"
#include "Formulas.h"
#include "DisableMgr.h"
#include "Opcodes.h"

/*********************************************************/
/***            BATTLEGROUND MANAGER                   ***/
/*********************************************************/

BattlegroundMgr::BattlegroundMgr() :
    m_NextRatedArenaUpdate(sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER)),
    m_NextAutoDistributionTime(0),
    m_AutoDistributionTimeChecker(0), m_ArenaTesting(false), m_Testing(false)
{ }

BattlegroundMgr::~BattlegroundMgr()
{
    DeleteAllBattlegrounds();
}

void BattlegroundMgr::DeleteAllBattlegrounds()
{
    for (BattlegroundDataContainer::iterator itr1 = bgDataStore.begin(); itr1 != bgDataStore.end(); ++itr1)
    {
        BattlegroundData& data = itr1->second;

        while (!data.m_Battlegrounds.empty())
            delete data.m_Battlegrounds.begin()->second;
        data.m_Battlegrounds.clear();

        while (!data.BGFreeSlotQueue.empty())
            delete data.BGFreeSlotQueue.front();
    }

    bgDataStore.clear();
}

// used to update running battlegrounds, and delete finished ones
void BattlegroundMgr::Update(uint32 diff)
{
    for (BattlegroundDataContainer::iterator itr1 = bgDataStore.begin(); itr1 != bgDataStore.end(); ++itr1)
    {
        BattlegroundContainer& bgs = itr1->second.m_Battlegrounds;
        BattlegroundContainer::iterator itrDelete = bgs.begin();
        // first one is template and should not be deleted
        for (BattlegroundContainer::iterator itr = ++itrDelete; itr != bgs.end();)
        {
            itrDelete = itr++;
            Battleground* bg = itrDelete->second;

            bg->Update(diff);
            if (bg->ToBeDeleted())
            {
                itrDelete->second = NULL;
                bgs.erase(itrDelete);
                BattlegroundClientIdsContainer& clients = itr1->second.m_ClientBattlegroundIds[bg->GetBracketId()];
                if (!clients.empty())
                     clients.erase(bg->GetClientInstanceID());

                delete bg;
            }
        }
    }

    // update events timer
    for (int qtype = BATTLEGROUND_QUEUE_NONE; qtype < MAX_BATTLEGROUND_QUEUE_TYPES; ++qtype)
        m_BattlegroundQueues[qtype].UpdateEvents(diff);

    // update scheduled queues
    if (!m_QueueUpdateScheduler.empty())
    {
        std::vector<uint64> scheduled;
        std::swap(scheduled, m_QueueUpdateScheduler);

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
    if (sWorld->getIntConfig(CONFIG_ARENA_MAX_RATING_DIFFERENCE) && sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER))
    {
        // it's time to force update
        if (m_NextRatedArenaUpdate < diff)
        {
            // forced update for rated arenas (scan all, but skipped non rated)
            TC_LOG_TRACE("bg.arena", "BattlegroundMgr: UPDATING ARENA QUEUES");
            for (int qtype = BATTLEGROUND_QUEUE_2v2; qtype <= BATTLEGROUND_QUEUE_5v5; ++qtype)
                for (int bracket = BG_BRACKET_ID_FIRST; bracket < MAX_BATTLEGROUND_BRACKETS; ++bracket)
                    m_BattlegroundQueues[qtype].BattlegroundQueueUpdate(diff,
                        BATTLEGROUND_AA, BattlegroundBracketId(bracket),
                        BattlegroundMgr::BGArenaType(BattlegroundQueueTypeId(qtype)), true, 0);

            m_NextRatedArenaUpdate = sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER);
        }
        else
            m_NextRatedArenaUpdate -= diff;
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

void BattlegroundMgr::BuildBattlegroundStatusPacket(WorldPacket* data, Battleground* bg, uint8 QueueSlot, uint8 StatusID, uint32 Time1, uint32 Time2, uint8 arenatype, uint32 arenaFaction)
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
    TC_LOG_DEBUG("network", "BattlegroundMgr::BuildBattlegroundStatusPacket: arenatype = %u for bg instanceID %u, TypeID %u.", arenatype, bg->GetClientInstanceID(), bg->GetTypeID());
    *data << uint8(bg->isArena() ? 0xE : 0x0);
    *data << uint32(bg->GetTypeID());
    *data << uint16(0x1F90);
    // End of uint64 segment, decomposed this way for simplicity
    *data << uint8(bg->GetMinLevel());
    *data << uint8(bg->GetMaxLevel());
    *data << uint32(bg->GetClientInstanceID());
    // alliance/horde for BG and skirmish/rated for Arenas
    // following displays the minimap-icon 0 = faction icon 1 = arenaicon
    *data << uint8(bg->isRated());                              // 1 for rated match, 0 for bg or non rated match

    *data << uint32(StatusID);                                  // status
    switch (StatusID)
    {
        case STATUS_WAIT_QUEUE:                                 // status_in_queue
            *data << uint32(Time1);                             // average wait time, milliseconds
            *data << uint32(Time2);                             // time in queue, updated every minute!, milliseconds
            break;
        case STATUS_WAIT_JOIN:                                  // status_invite
            *data << uint32(bg->GetMapId());                    // map id
            *data << uint64(0);                                 // 3.3.5, unknown
            *data << uint32(Time1);                             // time to remove from queue, milliseconds
            break;
        case STATUS_IN_PROGRESS:                                // status_in_progress
            *data << uint32(bg->GetMapId());                    // map id
            *data << uint64(0);                                 // 3.3.5, unknown
            *data << uint32(Time1);                             // time to bg auto leave, 0 at bg start, 120000 after bg end, milliseconds
            *data << uint32(Time2);                             // time from bg start, milliseconds
            *data << uint8(arenaFaction == ALLIANCE ? 1 : 0);   // arenafaction (0 for horde, 1 for alliance)
            break;
        default:
            TC_LOG_ERROR("bg.battleground", "Unknown BG status!");
            break;
    }
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

    BattlegroundDataContainer::const_iterator it = bgDataStore.find(bgTypeId);
    if (it == bgDataStore.end())
        return NULL;

    for (BattlegroundContainer::const_iterator itr = it->second.m_Battlegrounds.begin(); itr != it->second.m_Battlegrounds.end(); ++itr)
    {
        if (itr->second->GetClientInstanceID() == instanceId)
            return itr->second;
    }

    return NULL;
}

Battleground* BattlegroundMgr::GetBattleground(uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    if (!instanceId)
        return NULL;

    BattlegroundDataContainer::const_iterator begin, end;

    if (bgTypeId == BATTLEGROUND_TYPE_NONE)
    {
        begin = bgDataStore.begin();
        end = bgDataStore.end();
    }
    else
    {
        end = bgDataStore.find(bgTypeId);
        if (end == bgDataStore.end())
            return NULL;
        begin = end++;
    }

    for (BattlegroundDataContainer::const_iterator it = begin; it != end; ++it)
    {
        BattlegroundContainer const& bgs = it->second.m_Battlegrounds;
        BattlegroundContainer::const_iterator itr = bgs.find(instanceId);
        if (itr != bgs.end())
           return itr->second;
    }

    return NULL;
}

Battleground* BattlegroundMgr::GetBattlegroundTemplate(BattlegroundTypeId bgTypeId)
{
    BattlegroundDataContainer::const_iterator itr = bgDataStore.find(bgTypeId);
    if (itr == bgDataStore.end())
        return NULL;

    BattlegroundContainer const& bgs = itr->second.m_Battlegrounds;
    //map is sorted and we can be sure that lowest instance id has only BG template
    return bgs.empty() ? NULL : bgs.begin()->second;
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

    BattlegroundClientIdsContainer& clientIds = bgDataStore[bgTypeId].m_ClientBattlegroundIds[bracket_id];
    uint32 lastId = 0;
    for (BattlegroundClientIdsContainer::const_iterator itr = clientIds.begin(); itr != clientIds.end();)
    {
        if ((++lastId) != *itr)                             //if there is a gap between the ids, we will break..
            break;
        lastId = *itr;
    }

    clientIds.insert(++lastId);
    return lastId;
}

// create a new battleground that will really be used to play
Battleground* BattlegroundMgr::CreateNewBattleground(BattlegroundTypeId originalBgTypeId, PvPDifficultyEntry const* bracketEntry, uint8 arenaType, bool isRated)
{
    BattlegroundTypeId bgTypeId = GetRandomBG(originalBgTypeId);

    // get the template BG
    Battleground* bg_template = GetBattlegroundTemplate(bgTypeId);

    if (!bg_template)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground: CreateNewBattleground - bg template not found for %u", bgTypeId);
        return NULL;
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
        case BATTLEGROUND_AA:
        default:
            return NULL;
    }

    bool isRandom = bgTypeId != originalBgTypeId && !bg->isArena();

    bg->SetBracket(bracketEntry);
    bg->SetInstanceID(sMapMgr->GenerateInstanceId());
    bg->SetClientInstanceID(CreateClientVisibleInstanceId(originalBgTypeId, bracketEntry->GetBracketId()));
    bg->Reset();                     // reset the new bg (set status to status_wait_queue from status_none)
    bg->SetStatus(STATUS_WAIT_JOIN); // start the joining of the bg
    bg->SetArenaType(arenaType);
    bg->SetTypeID(originalBgTypeId);
    bg->SetRandomTypeID(bgTypeId);
    bg->SetRated(isRated);
    bg->SetRandom(isRandom);

    // Set up correct min/max player counts for scoreboards
    if (bg->isArena())
    {
        uint32 maxPlayersPerTeam = 0;
        switch (arenaType)
        {
            case ARENA_TYPE_2v2:
                maxPlayersPerTeam = 2;
                break;
            case ARENA_TYPE_3v3:
                maxPlayersPerTeam = 3;
                break;
            case ARENA_TYPE_5v5:
                maxPlayersPerTeam = 5;
                break;
        }

        bg->SetMaxPlayersPerTeam(maxPlayersPerTeam);
        bg->SetMaxPlayers(maxPlayersPerTeam * 2);
    }

    return bg;
}

// used to create the BG templates
bool BattlegroundMgr::CreateBattleground(BattlegroundTemplate const* bgTemplate)
{
    Battleground* bg = GetBattlegroundTemplate(bgTemplate->Id);
    if (!bg)
    {
        // Create the BG
        switch (bgTemplate->Id)
        {
            case BATTLEGROUND_AV:
                bg = new BattlegroundAV();
                break;
            case BATTLEGROUND_WS:
                bg = new BattlegroundWS();
                break;
            case BATTLEGROUND_AB:
                bg = new BattlegroundAB();
                break;
            case BATTLEGROUND_NA:
                bg = new BattlegroundNA();
                break;
            case BATTLEGROUND_BE:
                bg = new BattlegroundBE();
                break;
            case BATTLEGROUND_EY:
                bg = new BattlegroundEY();
                break;
            case BATTLEGROUND_RL:
                bg = new BattlegroundRL();
                break;
            case BATTLEGROUND_SA:
                bg = new BattlegroundSA();
                break;
            case BATTLEGROUND_DS:
                bg = new BattlegroundDS();
                break;
            case BATTLEGROUND_RV:
                bg = new BattlegroundRV();
                break;
            case BATTLEGROUND_IC:
                bg = new BattlegroundIC();
                break;
            case BATTLEGROUND_AA:
                bg = new Battleground();
                break;
            case BATTLEGROUND_RB:
                bg = new Battleground();
                bg->SetRandom(true);
                break;
            default:
                return false;
        }

        bg->SetTypeID(bgTemplate->Id);
        bg->SetInstanceID(0);
        AddBattleground(bg);
    }

    bg->SetMapId(bgTemplate->BattlemasterEntry->mapid[0]);
    bg->SetName(bgTemplate->BattlemasterEntry->name[sWorld->GetDefaultDbcLocale()]);
    bg->SetArenaorBGType(bgTemplate->IsArena());
    bg->SetMinPlayersPerTeam(bgTemplate->MinPlayersPerTeam);
    bg->SetMaxPlayersPerTeam(bgTemplate->MaxPlayersPerTeam);
    bg->SetMinPlayers(bgTemplate->MinPlayersPerTeam * 2);
    bg->SetMaxPlayers(bgTemplate->MaxPlayersPerTeam * 2);
    bg->SetTeamStartPosition(TEAM_ALLIANCE, bgTemplate->StartLocation[TEAM_ALLIANCE]);
    bg->SetTeamStartPosition(TEAM_HORDE,    bgTemplate->StartLocation[TEAM_HORDE]);
    bg->SetStartMaxDist(bgTemplate->MaxStartDistSq);
    bg->SetLevelRange(bgTemplate->MinLevel, bgTemplate->MaxLevel);
    bg->SetScriptId(bgTemplate->ScriptId);

    return true;
}

void BattlegroundMgr::LoadBattlegroundTemplates()
{
    uint32 oldMSTime = getMSTime();

    _battlegroundMapTemplates.clear();
    _battlegroundTemplates.clear();

    //                                               0   1                  2                  3       4       5                 6               7              8            9             10      11
    QueryResult result = WorldDatabase.Query("SELECT id, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, AllianceStartLoc, AllianceStartO, HordeStartLoc, HordeStartO, StartMaxDist, Weight, ScriptName FROM battleground_template");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 battlegrounds. DB table `battleground_template` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        BattlegroundTypeId bgTypeId = BattlegroundTypeId(fields[0].GetUInt32());

        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, bgTypeId, NULL))
            continue;

        // can be overwrite by values from DB
        BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(bgTypeId);
        if (!bl)
        {
            TC_LOG_ERROR("bg.battleground", "Battleground ID %u not found in BattlemasterList.dbc. Battleground not created.", bgTypeId);
            continue;
        }

        BattlegroundTemplate bgTemplate;
        bgTemplate.Id                = bgTypeId;
        bgTemplate.MinPlayersPerTeam = fields[1].GetUInt16();
        bgTemplate.MaxPlayersPerTeam = fields[2].GetUInt16();
        bgTemplate.MinLevel          = fields[3].GetUInt8();
        bgTemplate.MaxLevel          = fields[4].GetUInt8();
        float dist                   = fields[9].GetFloat();
        bgTemplate.MaxStartDistSq    = dist * dist;
        bgTemplate.Weight            = fields[10].GetUInt8();
        bgTemplate.ScriptId          = sObjectMgr->GetScriptId(fields[11].GetCString());
        bgTemplate.BattlemasterEntry = bl;

        if (bgTemplate.MaxPlayersPerTeam == 0 || bgTemplate.MinPlayersPerTeam > bgTemplate.MaxPlayersPerTeam)
        {
            TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id %u has bad values for MinPlayersPerTeam (%u) and MaxPlayersPerTeam(%u)",
                bgTemplate.Id, bgTemplate.MinPlayersPerTeam, bgTemplate.MaxPlayersPerTeam);
            continue;
        }

        if (bgTemplate.MinLevel == 0 || bgTemplate.MaxLevel == 0 || bgTemplate.MinLevel > bgTemplate.MaxLevel)
        {
            TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id %u has bad values for MinLevel (%u) and MaxLevel (%u)",
                bgTemplate.Id, bgTemplate.MinLevel, bgTemplate.MaxLevel);
            continue;
        }

        if (bgTemplate.Id != BATTLEGROUND_AA && bgTemplate.Id != BATTLEGROUND_RB)
        {
            uint32 startId = fields[5].GetUInt32();
            if (WorldSafeLocsEntry const* start = sWorldSafeLocsStore.LookupEntry(startId))
            {
                bgTemplate.StartLocation[TEAM_ALLIANCE].Relocate(start->x, start->y, start->z, fields[6].GetFloat());
            }
            else
            {
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id %u has non-existed WorldSafeLocs.dbc id %u in field `AllianceStartLoc`. BG not created.", bgTemplate.Id, startId);
                continue;
            }

            startId = fields[7].GetUInt32();
            if (WorldSafeLocsEntry const* start = sWorldSafeLocsStore.LookupEntry(startId))
            {
                bgTemplate.StartLocation[TEAM_HORDE].Relocate(start->x, start->y, start->z, fields[8].GetFloat());
            }
            else
            {
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id %u has non-existed WorldSafeLocs.dbc id %u in field `HordeStartLoc`. BG not created.", bgTemplate.Id, startId);
                continue;
            }
        }

        if (!CreateBattleground(&bgTemplate))
            continue;

        _battlegroundTemplates[bgTypeId] = bgTemplate;

        if (bgTemplate.BattlemasterEntry->mapid[1] == -1) // in this case we have only one mapId
            _battlegroundMapTemplates[bgTemplate.BattlemasterEntry->mapid[0]] = &_battlegroundTemplates[bgTypeId];

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u battlegrounds in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void BattlegroundMgr::InitAutomaticArenaPointDistribution()
{
    if (!sWorld->getBoolConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS))
        return;

    time_t wstime = time_t(sWorld->getWorldState(WS_ARENA_DISTRIBUTION_TIME));
    time_t curtime = time(NULL);
    TC_LOG_DEBUG("bg.battleground", "Initializing Automatic Arena Point Distribution");
    if (wstime < curtime)
    {
        m_NextAutoDistributionTime = curtime;           // reset will be called in the next update
        TC_LOG_DEBUG("bg.battleground", "Battleground: Next arena point distribution time in the past, reseting it now.");
    }
    else
        m_NextAutoDistributionTime = wstime;
    TC_LOG_DEBUG("bg.battleground", "Automatic Arena Point Distribution initialized.");
}

void BattlegroundMgr::BuildBattlegroundListPacket(WorldPacket* data, uint64 guid, Player* player, BattlegroundTypeId bgTypeId, uint8 fromWhere)
{
    if (!player)
        return;

    uint32 winner_kills = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_HONOR_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_HONOR_FIRST);
    uint32 winner_arena = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_ARENA_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_ARENA_FIRST);
    uint32 loser_kills = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_LOSER_HONOR_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_LOSER_HONOR_FIRST);

    winner_kills = Trinity::Honor::hk_honor_at_level(player->getLevel(), float(winner_kills));
    loser_kills = Trinity::Honor::hk_honor_at_level(player->getLevel(), float(loser_kills));

    data->Initialize(SMSG_BATTLEFIELD_LIST);
    *data << uint64(guid);                                  // battlemaster guid
    *data << uint8(fromWhere);                              // from where you joined
    *data << uint32(bgTypeId);                              // battleground id
    *data << uint8(0);                                      // unk
    *data << uint8(0);                                      // unk

    // Rewards
    *data << uint8(player->GetRandomWinner());              // 3.3.3 hasWin
    *data << uint32(winner_kills);                          // 3.3.3 winHonor
    *data << uint32(winner_arena);                          // 3.3.3 winArena
    *data << uint32(loser_kills);                           // 3.3.3 lossHonor

    uint8 isRandom = bgTypeId == BATTLEGROUND_RB;

    *data << uint8(isRandom);                               // 3.3.3 isRandom
    if (isRandom)
    {
        // Rewards (random)
        *data << uint8(player->GetRandomWinner());          // 3.3.3 hasWin_Random
        *data << uint32(winner_kills);                      // 3.3.3 winHonor_Random
        *data << uint32(winner_arena);                      // 3.3.3 winArena_Random
        *data << uint32(loser_kills);                       // 3.3.3 lossHonor_Random
    }

    if (bgTypeId == BATTLEGROUND_AA)                        // arena
        *data << uint32(0);                                 // unk (count?)
    else                                                    // battleground
    {
        size_t count_pos = data->wpos();
        *data << uint32(0);                                 // number of bg instances

        BattlegroundDataContainer::iterator it = bgDataStore.find(bgTypeId);
        if (it != bgDataStore.end())
        {
            // expected bracket entry
            if (PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(it->second.m_Battlegrounds.begin()->second->GetMapId(), player->getLevel()))
            {
                uint32 count = 0;
                BattlegroundBracketId bracketId = bracketEntry->GetBracketId();
                BattlegroundClientIdsContainer& clientIds = it->second.m_ClientBattlegroundIds[bracketId];
                for (BattlegroundClientIdsContainer::const_iterator itr = clientIds.begin(); itr != clientIds.end(); ++itr)
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
    if (Battleground* bg = GetBattleground(instanceId, bgTypeId))
    {
        uint32 mapid = bg->GetMapId();
        uint32 team = player->GetBGTeam();
        if (team == 0)
            team = player->GetTeam();

        Position const* pos = bg->GetTeamStartPosition(Battleground::GetTeamIndexByTeamId(team));
        TC_LOG_DEBUG("bg.battleground", "BattlegroundMgr::SendToBattleground: Sending %s to map %u, %s (bgType %u)", player->GetName().c_str(), mapid, pos->ToString().c_str(), bgTypeId);
        player->TeleportTo(mapid, pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation());
    }
    else
        TC_LOG_ERROR("bg.battleground", "BattlegroundMgr::SendToBattleground: Instance %u (bgType %u) not found while trying to teleport player %s", instanceId, bgTypeId, player->GetName().c_str());
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
    return bgTypeId == BATTLEGROUND_AA
            || bgTypeId == BATTLEGROUND_BE
            || bgTypeId == BATTLEGROUND_NA
            || bgTypeId == BATTLEGROUND_DS
            || bgTypeId == BATTLEGROUND_RV
            || bgTypeId == BATTLEGROUND_RL;
}

BattlegroundQueueTypeId BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId bgTypeId, uint8 arenaType)
{
    switch (bgTypeId)
    {
        case BATTLEGROUND_AB:
            return BATTLEGROUND_QUEUE_AB;
        case BATTLEGROUND_AV:
            return BATTLEGROUND_QUEUE_AV;
        case BATTLEGROUND_EY:
            return BATTLEGROUND_QUEUE_EY;
        case BATTLEGROUND_IC:
            return BATTLEGROUND_QUEUE_IC;
        case BATTLEGROUND_RB:
            return BATTLEGROUND_QUEUE_RB;
        case BATTLEGROUND_SA:
            return BATTLEGROUND_QUEUE_SA;
        case BATTLEGROUND_WS:
            return BATTLEGROUND_QUEUE_WS;
        case BATTLEGROUND_AA:
        case BATTLEGROUND_BE:
        case BATTLEGROUND_DS:
        case BATTLEGROUND_NA:
        case BATTLEGROUND_RL:
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
    sWorld->SendWorldText(m_Testing ? LANG_DEBUG_BG_ON : LANG_DEBUG_BG_OFF);
}

void BattlegroundMgr::ToggleArenaTesting()
{
    m_ArenaTesting = !m_ArenaTesting;
    sWorld->SendWorldText(m_ArenaTesting ? LANG_DEBUG_ARENA_ON : LANG_DEBUG_ARENA_OFF);
}

void BattlegroundMgr::SetHolidayWeekends(uint32 mask)
{
    for (uint32 bgtype = 1; bgtype < MAX_BATTLEGROUND_TYPE_ID; ++bgtype)
        if (Battleground* bg = GetBattlegroundTemplate(BattlegroundTypeId(bgtype)))
            bg->SetHoliday((mask & (1 << bgtype)) != 0);
}

void BattlegroundMgr::ScheduleQueueUpdate(uint32 arenaMatchmakerRating, uint8 arenaType, BattlegroundQueueTypeId bgQueueTypeId, BattlegroundTypeId bgTypeId, BattlegroundBracketId bracket_id)
{
    //This method must be atomic, @todo add mutex
    //we will use only 1 number created of bgTypeId and bracket_id
    uint64 const scheduleId = ((uint64)arenaMatchmakerRating << 32) | (uint32(arenaType) << 24) | (bgQueueTypeId << 16) | (bgTypeId << 8) | bracket_id;
    if (std::find(m_QueueUpdateScheduler.begin(), m_QueueUpdateScheduler.end(), scheduleId) == m_QueueUpdateScheduler.end())
        m_QueueUpdateScheduler.push_back(scheduleId);
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
        TC_LOG_INFO("server.loading", ">> Loaded 0 battlemaster entries. DB table `battlemaster_entry` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        ++count;

        Field* fields = result->Fetch();

        uint32 entry = fields[0].GetUInt32();
        if (CreatureTemplate const* cInfo = sObjectMgr->GetCreatureTemplate(entry))
        {
            if ((cInfo->npcflag & UNIT_NPC_FLAG_BATTLEMASTER) == 0)
                TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) listed in `battlemaster_entry` is not a battlemaster.", entry);
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: %u) listed in `battlemaster_entry` does not exist.", entry);
            continue;
        }

        uint32 bgTypeId  = fields[1].GetUInt32();
        if (!sBattlemasterListStore.LookupEntry(bgTypeId))
        {
            TC_LOG_ERROR("sql.sql", "Table `battlemaster_entry` contain entry %u for not existed battleground type %u, ignored.", entry, bgTypeId);
            continue;
        }

        mBattleMastersMap[entry] = BattlegroundTypeId(bgTypeId);
    }
    while (result->NextRow());

    CheckBattleMasters();

    TC_LOG_INFO("server.loading", ">> Loaded %u battlemaster entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void BattlegroundMgr::CheckBattleMasters()
{
    CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
    for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
    {
        if ((itr->second.npcflag & UNIT_NPC_FLAG_BATTLEMASTER) && mBattleMastersMap.find(itr->second.Entry) == mBattleMastersMap.end())
        {
            TC_LOG_ERROR("sql.sql", "CreatureTemplate (Entry: %u) has UNIT_NPC_FLAG_BATTLEMASTER but no data in `battlemaster_entry` table. Removing flag!", itr->second.Entry);
            const_cast<CreatureTemplate*>(&itr->second)->npcflag &= ~UNIT_NPC_FLAG_BATTLEMASTER;
        }
    }
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

BattlegroundTypeId BattlegroundMgr::GetRandomBG(BattlegroundTypeId bgTypeId)
{
    if (BattlegroundTemplate const* bgTemplate = GetBattlegroundTemplateByTypeId(bgTypeId))
    {
        uint32 weight = 0;
        BattlegroundSelectionWeightMap selectionWeights;

        for (int32 mapId : bgTemplate->BattlemasterEntry->mapid)
        {
            if (mapId == -1)
                break;

            if (BattlegroundTemplate const* bg = GetBattlegroundTemplateByMapId(mapId))
            {
                weight += bg->Weight;
                selectionWeights[bg->Id] = bg->Weight;
            }
        }

        // there is only one bg to select
        if (selectionWeights.size() == 1)
            return selectionWeights.begin()->first;

        if (weight)
        {
            // Select a random value
            uint32 selectedWeight = urand(0, weight - 1);
            // Select the correct bg (if we have in DB A(10), B(20), C(10), D(15) --> [0---A---9|10---B---29|30---C---39|40---D---54])
            weight = 0;
            for (auto it : selectionWeights)
            {
                weight += it.second;
                if (selectedWeight < weight)
                    return it.first;
            }
        }
    }

    return BATTLEGROUND_TYPE_NONE;
}

BGFreeSlotQueueContainer& BattlegroundMgr::GetBGFreeSlotQueueStore(BattlegroundTypeId bgTypeId)
{
    return bgDataStore[bgTypeId].BGFreeSlotQueue;
}

void BattlegroundMgr::AddToBGFreeSlotQueue(BattlegroundTypeId bgTypeId, Battleground* bg)
{
    bgDataStore[bgTypeId].BGFreeSlotQueue.push_front(bg);
}

void BattlegroundMgr::RemoveFromBGFreeSlotQueue(BattlegroundTypeId bgTypeId, uint32 instanceId)
{
    BGFreeSlotQueueContainer& queues = bgDataStore[bgTypeId].BGFreeSlotQueue;
    for (BGFreeSlotQueueContainer::iterator itr = queues.begin(); itr != queues.end(); ++itr)
        if ((*itr)->GetInstanceID() == instanceId)
        {
            queues.erase(itr);
            return;
        }
}

void BattlegroundMgr::AddBattleground(Battleground* bg)
{
    if (bg)
        bgDataStore[bg->GetTypeID()].m_Battlegrounds[bg->GetInstanceID()] = bg;
}

void BattlegroundMgr::RemoveBattleground(BattlegroundTypeId bgTypeId, uint32 instanceId)
{
    bgDataStore[bgTypeId].m_Battlegrounds.erase(instanceId);
}

