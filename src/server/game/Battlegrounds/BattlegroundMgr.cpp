/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "BattlegroundMgr.h"
#include "BattlegroundAB.h"
#include "BattlegroundAV.h"
#include "BattlegroundBE.h"
#include "BattlegroundBFG.h"
#include "BattlegroundDS.h"
#include "BattlegroundEY.h"
#include "BattlegroundIC.h"
#include "BattlegroundNA.h"
#include "BattlegroundPackets.h"
#include "BattlegroundRL.h"
#include "BattlegroundRV.h"
#include "BattlegroundSA.h"
#include "BattlegroundTP.h"
#include "BattlegroundWS.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SharedDefines.h"
#include "World.h"

bool BattlegroundTemplate::IsArena() const
{
    return BattlemasterEntry->InstanceType == MAP_ARENA;
}

uint16 BattlegroundTemplate::GetMinPlayersPerTeam() const
{
    return BattlemasterEntry->MinPlayers;
}

uint16 BattlegroundTemplate::GetMaxPlayersPerTeam() const
{
    return BattlemasterEntry->MaxPlayers;
}

uint8 BattlegroundTemplate::GetMinLevel() const
{
    return BattlemasterEntry->MinLevel;
}

uint8 BattlegroundTemplate::GetMaxLevel() const
{
    return BattlemasterEntry->MaxLevel;
}

/*********************************************************/
/***            BATTLEGROUND MANAGER                   ***/
/*********************************************************/

BattlegroundMgr::BattlegroundMgr() :
    m_NextRatedArenaUpdate(sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER)),
    m_UpdateTimer(0), m_ArenaTesting(false), m_Testing(false)
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
    }

    bgDataStore.clear();

    for (auto itr = m_BGFreeSlotQueue.begin(); itr != m_BGFreeSlotQueue.end(); ++itr)
        while (!itr->second.empty())
            delete itr->second.front();

    m_BGFreeSlotQueue.clear();
}

BattlegroundMgr* BattlegroundMgr::instance()
{
    static BattlegroundMgr instance;
    return &instance;
}

// used to update running battlegrounds, and delete finished ones
void BattlegroundMgr::Update(uint32 diff)
{
    m_UpdateTimer += diff;
    if (m_UpdateTimer > BATTLEGROUND_OBJECTIVE_UPDATE_INTERVAL)
    {
        for (BattlegroundDataContainer::iterator itr1 = bgDataStore.begin(); itr1 != bgDataStore.end(); ++itr1)
        {
            BattlegroundContainer& bgs = itr1->second.m_Battlegrounds;
            BattlegroundContainer::iterator itrDelete = bgs.begin();
            for (BattlegroundContainer::iterator itr = itrDelete; itr != bgs.end();)
            {
                itrDelete = itr++;
                Battleground* bg = itrDelete->second;

                bg->Update(m_UpdateTimer);
                if (bg->ToBeDeleted())
                {
                    itrDelete->second = nullptr;
                    bgs.erase(itrDelete);
                    BattlegroundClientIdsContainer& clients = itr1->second.m_ClientBattlegroundIds[bg->GetBracketId()];
                    if (!clients.empty())
                        clients.erase(bg->GetClientInstanceID());

                    delete bg;
                }
            }
        }

        m_UpdateTimer = 0;
    }

    // update events timer
    for (std::pair<BattlegroundQueueTypeId const, BattlegroundQueue>& pair : m_BattlegroundQueues)
        pair.second.UpdateEvents(diff);

    // update scheduled queues
    if (!m_QueueUpdateScheduler.empty())
    {
        std::vector<ScheduledQueueUpdate> scheduled;
        std::swap(scheduled, m_QueueUpdateScheduler);

        for (uint8 i = 0; i < scheduled.size(); i++)
        {
            uint32 arenaMMRating = scheduled[i].ArenaMatchmakerRating;
            BattlegroundQueueTypeId bgQueueTypeId = scheduled[i].QueueId;
            BattlegroundBracketId bracket_id = scheduled[i].BracketId;
            GetBattlegroundQueue(bgQueueTypeId).BattlegroundQueueUpdate(diff, bracket_id, arenaMMRating);
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
            for (uint8 teamSize : { ARENA_TYPE_2v2, ARENA_TYPE_3v3, ARENA_TYPE_5v5 })
            {
                BattlegroundQueueTypeId ratedArenaQueueId = BGQueueTypeId(BATTLEGROUND_AA, BattlegroundQueueIdType::Arena, true, teamSize);
                for (int bracket = BG_BRACKET_ID_FIRST; bracket < MAX_BATTLEGROUND_BRACKETS; ++bracket)
                    GetBattlegroundQueue(ratedArenaQueueId).BattlegroundQueueUpdate(diff, BattlegroundBracketId(bracket), 0);
            }

            m_NextRatedArenaUpdate = sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER);
        }
        else
            m_NextRatedArenaUpdate -= diff;
    }
}

void BattlegroundMgr::BuildBattlegroundStatusHeader(WorldPackets::Battleground::BattlefieldStatusHeader* header, Player* player, uint32 ticketId, uint32 joinTime, BattlegroundQueueTypeId queueId)
{
    header->Ticket.RequesterGuid = player->GetGUID();
    header->Ticket.Id = ticketId;
    header->Ticket.Type = WorldPackets::LFG::RideType::Battlegrounds;
    header->Ticket.Time = joinTime;
    header->QueueID.push_back(queueId.GetPacked());
    header->RangeMin = 0; // seems to always be 0
    header->RangeMax = DEFAULT_MAX_LEVEL; // alwyas max level of current expansion. Might be limited to account
    header->TeamSize = queueId.TeamSize;
    header->InstanceID = 0; // seems to always be 0
    header->RegisteredMatch = queueId.Rated;
    header->TournamentRules = false;
}

void BattlegroundMgr::BuildBattlegroundStatusNone(WorldPackets::Battleground::BattlefieldStatusNone* battlefieldStatus, Player* player, uint32 ticketId, uint32 joinTime)
{
    battlefieldStatus->Ticket.RequesterGuid = player->GetGUID();
    battlefieldStatus->Ticket.Id = ticketId;
    battlefieldStatus->Ticket.Type = WorldPackets::LFG::RideType::Battlegrounds;
    battlefieldStatus->Ticket.Time = joinTime;
}

void BattlegroundMgr::BuildBattlegroundStatusNeedConfirmation(WorldPackets::Battleground::BattlefieldStatusNeedConfirmation* battlefieldStatus, Battleground* bg, Player* player, uint32 ticketId, uint32 joinTime, uint32 timeout, BattlegroundQueueTypeId queueId)
{
    BuildBattlegroundStatusHeader(&battlefieldStatus->Hdr, player, ticketId, joinTime, queueId);
    battlefieldStatus->Mapid = bg->GetMapId();
    battlefieldStatus->Timeout = timeout;
    battlefieldStatus->Role = 0;
}

void BattlegroundMgr::BuildBattlegroundStatusActive(WorldPackets::Battleground::BattlefieldStatusActive* battlefieldStatus, Battleground* bg, Player* player, uint32 ticketId, uint32 joinTime, BattlegroundQueueTypeId queueId)
{
    BuildBattlegroundStatusHeader(&battlefieldStatus->Hdr, player, ticketId, joinTime, queueId);
    battlefieldStatus->ShutdownTimer = bg->GetRemainingTime();
    battlefieldStatus->ArenaFaction = player->GetBGTeam() == HORDE ? PVP_TEAM_HORDE : PVP_TEAM_ALLIANCE;
    battlefieldStatus->LeftEarly = false;
    battlefieldStatus->StartTimer = bg->GetElapsedTime();
    battlefieldStatus->Mapid = bg->GetMapId();
}

void BattlegroundMgr::BuildBattlegroundStatusQueued(WorldPackets::Battleground::BattlefieldStatusQueued* battlefieldStatus, Player* player, uint32 ticketId, uint32 joinTime, BattlegroundQueueTypeId queueId, uint32 avgWaitTime, bool asGroup)
{
    BuildBattlegroundStatusHeader(&battlefieldStatus->Hdr, player, ticketId, joinTime, queueId);
    battlefieldStatus->AverageWaitTime = avgWaitTime;
    battlefieldStatus->AsGroup = asGroup;
    battlefieldStatus->SuspendedQueue = false;
    battlefieldStatus->EligibleForMatchmaking = true;
    battlefieldStatus->WaitTime = GetMSTimeDiffToNow(joinTime);
}

void BattlegroundMgr::BuildBattlegroundStatusFailed(WorldPackets::Battleground::BattlefieldStatusFailed* battlefieldStatus, BattlegroundQueueTypeId queueId, Player* pPlayer, uint32 ticketId, GroupJoinBattlegroundResult result, ObjectGuid const* errorGuid /*= nullptr*/)
{
    battlefieldStatus->Ticket.RequesterGuid = pPlayer->GetGUID();
    battlefieldStatus->Ticket.Id = ticketId;
    battlefieldStatus->Ticket.Type = WorldPackets::LFG::RideType::Battlegrounds;
    battlefieldStatus->Ticket.Time = pPlayer->GetBattlegroundQueueJoinTime(queueId);
    battlefieldStatus->QueueID = queueId.GetPacked();
    battlefieldStatus->Reason = result;
    if (errorGuid && (result == ERR_BATTLEGROUND_NOT_IN_BATTLEGROUND || result == ERR_BATTLEGROUND_JOIN_TIMED_OUT))
        battlefieldStatus->ClientID = *errorGuid;
}

Battleground* BattlegroundMgr::GetBattleground(uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    if (!instanceId)
        return nullptr;

    BattlegroundDataContainer::const_iterator begin, end;

    if (bgTypeId == BATTLEGROUND_TYPE_NONE || IsRandomBattleground(bgTypeId))
    {
        begin = bgDataStore.begin();
        end = bgDataStore.end();
    }
    else
    {
        end = bgDataStore.find(bgTypeId);
        if (end == bgDataStore.end())
            return nullptr;
        begin = end++;
    }

    for (BattlegroundDataContainer::const_iterator it = begin; it != end; ++it)
    {
        BattlegroundContainer const& bgs = it->second.m_Battlegrounds;
        BattlegroundContainer::const_iterator itr = bgs.find(instanceId);
        if (itr != bgs.end())
           return itr->second;
    }

    return nullptr;
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
Battleground* BattlegroundMgr::CreateNewBattleground(BattlegroundQueueTypeId queueId, BattlegroundBracketId bracketId)
{
    BattlegroundTypeId bgTypeId = GetRandomBG(BattlegroundTypeId(queueId.BattlemasterListId));

    // get the template BG
    BattlegroundTemplate const* bg_template = GetBattlegroundTemplateByTypeId(bgTypeId);

    if (!bg_template)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground: CreateNewBattleground - bg template not found for {}", bgTypeId);
        return nullptr;
    }

    PVPDifficultyEntry const* bracketEntry = DB2Manager::GetBattlegroundBracketById(bg_template->BattlemasterEntry->MapID[0], bracketId);
    if (!bracketEntry)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground: CreateNewBattleground: bg bracket entry not found for map {} bracket id {}", bg_template->BattlemasterEntry->MapID[0], bracketId);
        return nullptr;
    }

    Battleground* bg = nullptr;
    // create a copy of the BG template
    switch (bgTypeId)
    {
        case BATTLEGROUND_AV:
            bg = new BattlegroundAV(bg_template);
            break;
        case BATTLEGROUND_WS:
        case BATTLEGROUND_WG_CTF:
            bg = new BattlegroundWS(bg_template);
            break;
        case BATTLEGROUND_AB:
        case BATTLEGROUND_DOM_AB:
            bg = new BattlegroundAB(bg_template);
            break;
        case BATTLEGROUND_NA:
            bg = new BattlegroundNA(bg_template);
            break;
        case BATTLEGROUND_BE:
            bg = new BattlegroundBE(bg_template);
            break;
        case BATTLEGROUND_EY:
            bg = new BattlegroundEY(bg_template);
            break;
        case BATTLEGROUND_RL:
            bg = new BattlegroundRL(bg_template);
            break;
        case BATTLEGROUND_SA:
            bg = new BattlegroundSA(bg_template);
            break;
        case BATTLEGROUND_DS:
            bg = new BattlegroundDS(bg_template);
            break;
        case BATTLEGROUND_RV:
            bg = new BattlegroundRV(bg_template);
            break;
        case BATTLEGROUND_IC:
            bg = new BattlegroundIC(bg_template);
            break;
        case BATTLEGROUND_TP:
            bg = new BattlegroundTP(bg_template);
            break;
        case BATTLEGROUND_BFG:
            bg = new BattlegroundBFG(bg_template);
            break;
        case BATTLEGROUND_RB:
        case BATTLEGROUND_AA:
        case BATTLEGROUND_RANDOM_EPIC:
        default:
            return nullptr;
    }

    bg->SetBracket(bracketEntry);
    bg->SetInstanceID(sMapMgr->GenerateInstanceId());
    bg->SetClientInstanceID(CreateClientVisibleInstanceId(BattlegroundTypeId(queueId.BattlemasterListId), bracketEntry->GetBracketId()));
    // reset the new bg (set status to status_wait_queue from status_none)
    // this shouldn't be needed anymore as a new Battleground instance is created each time. But some bg sub classes still depend on it.
    bg->Reset();
    bg->SetStatus(STATUS_WAIT_JOIN); // start the joining of the bg
    bg->SetArenaType(queueId.TeamSize);
    bg->SetRated(queueId.Rated);

    return bg;
}

void BattlegroundMgr::LoadBattlegroundTemplates()
{
    uint32 oldMSTime = getMSTime();

    //                                               0   1                 2              3             4       5
    QueryResult result = WorldDatabase.Query("SELECT ID, AllianceStartLoc, HordeStartLoc, StartMaxDist, Weight, ScriptName FROM battleground_template");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 battlegrounds. DB table `battleground_template` is empty.");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        BattlegroundTypeId bgTypeId = BattlegroundTypeId(fields[0].GetUInt32());

        if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, bgTypeId, nullptr))
            continue;

        // can be overwrite by values from DB
        BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(bgTypeId);
        if (!bl)
        {
            TC_LOG_ERROR("bg.battleground", "Battleground ID {} could not be found in BattlemasterList.dbc. The battleground was not created.", bgTypeId);
            continue;
        }

        BattlegroundTemplate& bgTemplate = _battlegroundTemplates[bgTypeId];
        bgTemplate.Id                = bgTypeId;
        float dist                   = fields[3].GetFloat();
        bgTemplate.MaxStartDistSq    = dist * dist;
        bgTemplate.Weight            = fields[4].GetUInt8();
        bgTemplate.ScriptId          = sObjectMgr->GetScriptId(fields[5].GetString());
        bgTemplate.BattlemasterEntry = bl;

        if (bgTemplate.Id != BATTLEGROUND_AA && !IsRandomBattleground(bgTemplate.Id))
        {
            uint32 startId = fields[1].GetUInt32();
            if (WorldSafeLocsEntry const* start = sObjectMgr->GetWorldSafeLoc(startId))
                bgTemplate.StartLocation[TEAM_ALLIANCE] = start;
            else if (bgTemplate.StartLocation[TEAM_ALLIANCE]) // reload case
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains a non-existing WorldSafeLocs.dbc id {} in field `AllianceStartLoc`. Ignoring.", bgTemplate.Id, startId);
            else
            {
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains a non-existing WorldSafeLocs.dbc id {} in field `AllianceStartLoc`. BG not created.", bgTemplate.Id, startId);
                _battlegroundTemplates.erase(bgTypeId);
                continue;
            }

            startId = fields[2].GetUInt32();
            if (WorldSafeLocsEntry const* start = sObjectMgr->GetWorldSafeLoc(startId))
                bgTemplate.StartLocation[TEAM_HORDE] = start;
            else if (bgTemplate.StartLocation[TEAM_HORDE]) // reload case
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains a non-existing WorldSafeLocs.dbc id {} in field `HordeStartLoc`. Ignoring.", bgTemplate.Id, startId);
            else
            {
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains a non-existing WorldSafeLocs.dbc id {} in field `HordeStartLoc`. BG not created.", bgTemplate.Id, startId);
                _battlegroundTemplates.erase(bgTypeId);
                continue;
            }
        }

        if (bgTemplate.BattlemasterEntry->MapID[1] == -1) // in this case we have only one mapId
            _battlegroundMapTemplates[bgTemplate.BattlemasterEntry->MapID[0]] = &_battlegroundTemplates[bgTypeId];

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} battlegrounds in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void BattlegroundMgr::SendBattlegroundList(Player* player, ObjectGuid const& guid, BattlegroundTypeId bgTypeId)
{
    BattlegroundTemplate const* bgTemplate = GetBattlegroundTemplateByTypeId(bgTypeId);
    if (!bgTemplate)
        return;

    WorldPackets::Battleground::BattlefieldList battlefieldList;
    battlefieldList.BattlemasterGuid = guid;
    battlefieldList.BattlemasterListID = bgTypeId;
    battlefieldList.MinLevel = bgTemplate->GetMinLevel();
    battlefieldList.MaxLevel = bgTemplate->GetMaxLevel();
    battlefieldList.PvpAnywhere = guid.IsEmpty();
    battlefieldList.HasRandomWinToday = player->GetRandomWinner();
    player->SendDirectMessage(battlefieldList.Write());
}

void BattlegroundMgr::SendToBattleground(Player* player, uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    if (Battleground* bg = GetBattleground(instanceId, bgTypeId))
    {
        uint32 mapid = bg->GetMapId();
        Team team = player->GetBGTeam();

        WorldSafeLocsEntry const* pos = bg->GetTeamStartPosition(Battleground::GetTeamIndexByTeamId(team));
        TC_LOG_DEBUG("bg.battleground", "BattlegroundMgr::SendToBattleground: Sending {} to map {}, {} (bgType {})", player->GetName(), mapid, pos->Loc.ToString(), bgTypeId);
        player->TeleportTo(pos->Loc);
    }
    else
        TC_LOG_ERROR("bg.battleground", "BattlegroundMgr::SendToBattleground: Instance {} (bgType {}) not found while trying to teleport player {}", instanceId, bgTypeId, player->GetName());
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

bool BattlegroundMgr::IsRandomBattleground(uint32 battlemasterListId)
{
    return battlemasterListId == BATTLEGROUND_RB || battlemasterListId == BATTLEGROUND_RANDOM_EPIC;
}

BattlegroundQueueTypeId BattlegroundMgr::BGQueueTypeId(uint16 battlemasterListId, BattlegroundQueueIdType type, bool rated, uint8 teamSize)
{
    return { battlemasterListId, AsUnderlyingType(type), rated, teamSize };
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

bool BattlegroundMgr::IsValidQueueId(BattlegroundQueueTypeId bgQueueTypeId)
{
    BattlemasterListEntry const* battlemasterList = sBattlemasterListStore.LookupEntry(bgQueueTypeId.BattlemasterListId);
    if (!battlemasterList)
        return false;

    switch (BattlegroundQueueIdType(bgQueueTypeId.Type))
    {
        case BattlegroundQueueIdType::Battleground:
            if (battlemasterList->InstanceType != MAP_BATTLEGROUND)
                return false;
            if (bgQueueTypeId.TeamSize)
                return false;
            break;
        case BattlegroundQueueIdType::Arena:
            if (battlemasterList->InstanceType != MAP_ARENA)
                return false;
            if (!bgQueueTypeId.Rated)
                return false;
            if (!bgQueueTypeId.TeamSize)
                return false;
            break;
        case BattlegroundQueueIdType::Wargame:
            if (bgQueueTypeId.Rated)
                return false;
            break;
        case BattlegroundQueueIdType::ArenaSkirmish:
            if (battlemasterList->InstanceType != MAP_ARENA)
                return false;
            if (!bgQueueTypeId.Rated)
                return false;
            if (bgQueueTypeId.TeamSize != ARENA_TYPE_3v3)
                return false;
            break;
        default:
            return false;
    }

    return true;
}

void BattlegroundMgr::ScheduleQueueUpdate(uint32 arenaMatchmakerRating, BattlegroundQueueTypeId bgQueueTypeId, BattlegroundBracketId bracket_id)
{
    //This method must be atomic, @todo add mutex
    //we will use only 1 number created of bgTypeId and bracket_id
    ScheduledQueueUpdate scheduleId{ arenaMatchmakerRating, bgQueueTypeId, bracket_id };
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
                TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) listed in `battlemaster_entry` is not a battlemaster.", entry);
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Creature (Entry: {}) listed in `battlemaster_entry` does not exist.", entry);
            continue;
        }

        uint32 bgTypeId  = fields[1].GetUInt32();
        if (!sBattlemasterListStore.LookupEntry(bgTypeId))
        {
            TC_LOG_ERROR("sql.sql", "Table `battlemaster_entry` contains entry {} for a non-existing battleground type {}, ignored.", entry, bgTypeId);
            continue;
        }

        mBattleMastersMap[entry] = BattlegroundTypeId(bgTypeId);
    }
    while (result->NextRow());

    CheckBattleMasters();

    TC_LOG_INFO("server.loading", ">> Loaded {} battlemaster entries in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void BattlegroundMgr::CheckBattleMasters()
{
    CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
    for (auto const& creatureTemplatePair : ctc)
    {
        if ((creatureTemplatePair.second.npcflag & UNIT_NPC_FLAG_BATTLEMASTER) && !mBattleMastersMap.count(creatureTemplatePair.first))
        {
            TC_LOG_ERROR("sql.sql", "Creature_Template Entry: {} has UNIT_NPC_FLAG_BATTLEMASTER, but no data in the `battlemaster_entry` table. Removing flag.", creatureTemplatePair.first);
            const_cast<CreatureTemplate&>(creatureTemplatePair.second).npcflag &= ~UNIT_NPC_FLAG_BATTLEMASTER;
        }
    }
}

HolidayIds BattlegroundMgr::BGTypeToWeekendHolidayId(BattlegroundTypeId bgTypeId)
{
    switch (bgTypeId)
    {
        case BATTLEGROUND_AV:  return HOLIDAY_CALL_TO_ARMS_AV;
        case BATTLEGROUND_EY:  return HOLIDAY_CALL_TO_ARMS_ES;
        case BATTLEGROUND_WS:  return HOLIDAY_CALL_TO_ARMS_WG;
        case BATTLEGROUND_SA:  return HOLIDAY_CALL_TO_ARMS_SA;
        case BATTLEGROUND_AB:  return HOLIDAY_CALL_TO_ARMS_AB;
        case BATTLEGROUND_IC:  return HOLIDAY_CALL_TO_ARMS_IC;
        case BATTLEGROUND_TP:  return HOLIDAY_CALL_TO_ARMS_TP;
        case BATTLEGROUND_BFG: return HOLIDAY_CALL_TO_ARMS_BG;
        default: return HOLIDAY_NONE;
    }
}

BattlegroundTypeId BattlegroundMgr::WeekendHolidayIdToBGType(HolidayIds holiday)
{
    switch (holiday)
    {
        case HOLIDAY_CALL_TO_ARMS_AV: return BATTLEGROUND_AV;
        case HOLIDAY_CALL_TO_ARMS_ES: return BATTLEGROUND_EY;
        case HOLIDAY_CALL_TO_ARMS_WG: return BATTLEGROUND_WS;
        case HOLIDAY_CALL_TO_ARMS_SA: return BATTLEGROUND_SA;
        case HOLIDAY_CALL_TO_ARMS_AB: return BATTLEGROUND_AB;
        case HOLIDAY_CALL_TO_ARMS_IC: return BATTLEGROUND_IC;
        case HOLIDAY_CALL_TO_ARMS_TP: return BATTLEGROUND_TP;
        case HOLIDAY_CALL_TO_ARMS_BG: return BATTLEGROUND_BFG;
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
        std::vector<BattlegroundTypeId> ids;
        ids.reserve(16);
        std::vector<double> weights;
        weights.reserve(16);
        for (int32 mapId : bgTemplate->BattlemasterEntry->MapID)
        {
            if (mapId == -1)
                break;

            if (BattlegroundTemplate const* bg = GetBattlegroundTemplateByMapId(mapId))
            {
                ids.push_back(bg->Id);
                weights.push_back(bg->Weight);
            }
        }

        return *Trinity::Containers::SelectRandomWeightedContainerElement(ids, std::span(weights));
    }

    return BATTLEGROUND_TYPE_NONE;
}

BGFreeSlotQueueContainer& BattlegroundMgr::GetBGFreeSlotQueueStore(uint32 mapId)
{
    return m_BGFreeSlotQueue[mapId];
}

void BattlegroundMgr::AddToBGFreeSlotQueue(Battleground* bg)
{
    m_BGFreeSlotQueue[bg->GetMapId()].push_front(bg);
}

void BattlegroundMgr::RemoveFromBGFreeSlotQueue(uint32 mapId, uint32 instanceId)
{
    BGFreeSlotQueueContainer& queues = m_BGFreeSlotQueue[mapId];
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
