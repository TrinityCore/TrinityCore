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

#include "ArenaTeamMgr.h"
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
#include "BattlegroundPackets.h"
#include "Common.h"
#include "Containers.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "Language.h"
#include "Map.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "SharedDefines.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"

bool BattlegroundTemplate::IsArena() const
{
    return BattlemasterEntry->InstanceType == MAP_ARENA;
}

/*********************************************************/
/***            BATTLEGROUND MANAGER                   ***/
/*********************************************************/

BattlegroundMgr::BattlegroundMgr() :
    m_NextRatedArenaUpdate(sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER)),
    m_NextAutoDistributionTime(0),
    m_AutoDistributionTimeChecker(0), m_UpdateTimer(0), m_ArenaTesting(false), m_Testing(false)
{ }

BattlegroundMgr::~BattlegroundMgr()
{
    DeleteAllBattlegrounds();
}

void BattlegroundMgr::DeleteAllBattlegrounds()
{
    bgDataStore.clear();
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
            // first one is template and should not be deleted
            for (BattlegroundContainer::iterator itr = ++itrDelete; itr != bgs.end();)
            {
                itrDelete = itr++;
                Battleground* bg = itrDelete->second.get();

                bg->Update(m_UpdateTimer);
                if (bg->ToBeDeleted())
                {
                    BattlegroundClientIdsContainer& clients = itr1->second.m_ClientBattlegroundIds[bg->GetBracketId()];
                    if (!clients.empty())
                        clients.erase(bg->GetClientInstanceID());

                    // move out unique_ptr to delete after erasing
                    Trinity::unique_trackable_ptr<Battleground> bgPtr = std::move(itrDelete->second);

                    bgs.erase(itrDelete);
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

        for (auto& [arenaMMRating, bgQueueTypeId] : scheduled)
            GetBattlegroundQueue(bgQueueTypeId).BattlegroundQueueUpdate(diff, arenaMMRating > 0, arenaMMRating);
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
                for (int bracket = BG_BRACKET_ID_FIRST; bracket < MAX_BATTLEGROUND_BRACKETS; ++bracket)
                {
                    BattlegroundQueueTypeId ratedArenaQueueId = BGQueueTypeId(BATTLEGROUND_AA, bracket, teamSize);
                    if (BattlegroundQueue* arenaQueue = Trinity::Containers::MapGetValuePtr(m_BattlegroundQueues, ratedArenaQueueId))
                        arenaQueue->BattlegroundQueueUpdate(diff, true, 0);
                }
            }

            m_NextRatedArenaUpdate = sWorld->getIntConfig(CONFIG_ARENA_RATED_UPDATE_TIMER);
        }
        else
            m_NextRatedArenaUpdate -= diff;
    }

    if (sWorld->getBoolConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS))
    {
        if (m_AutoDistributionTimeChecker < diff)
        {
            if (GameTime::GetGameTime() > m_NextAutoDistributionTime)
            {
                sArenaTeamMgr->DistributeArenaPoints();

                time_t arenaDistributionTime = sWorld->getWorldState(WS_ARENA_DISTRIBUTION_TIME) == 0 ? m_NextAutoDistributionTime : time_t(sWorld->getWorldState(WS_ARENA_DISTRIBUTION_TIME));
                m_NextAutoDistributionTime = arenaDistributionTime + BATTLEGROUND_ARENA_POINT_DISTRIBUTION_DAY * sWorld->getIntConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_INTERVAL_DAYS);
                sWorld->setWorldState(WS_ARENA_DISTRIBUTION_TIME, uint64(m_NextAutoDistributionTime));
            }
            m_AutoDistributionTimeChecker = 600000; // check 10 minutes
        }
        else
            m_AutoDistributionTimeChecker -= diff;
    }
}

void BattlegroundMgr::BuildBattlegroundStatusHeader(WorldPackets::Battleground::BattlefieldStatusHeader* header, Battleground const* bg, uint32 queueSlot, BattlegroundQueueTypeId queueId)
{
    header->QueueSlot = queueSlot;
    header->QueueID = queueId.GetPacked();
    header->RangeMin = bg->GetMinLevel();
    header->RangeMax = bg->GetMaxLevel();
    header->InstanceID = bg->GetClientInstanceID();
    header->RegisteredMatch = bg->isRated();
}

void BattlegroundMgr::BuildBattlegroundStatusNone(WorldPackets::Battleground::BattlefieldStatusNone* battlefieldStatus, uint32 queueSlot)
{
    battlefieldStatus->QueueSlot = queueSlot;
}

void BattlegroundMgr::BuildBattlegroundStatusNeedConfirmation(WorldPackets::Battleground::BattlefieldStatusNeedConfirmation* battlefieldStatus, Battleground const* bg, uint32 queueSlot, uint32 timeout, BattlegroundQueueTypeId queueId)
{
    BuildBattlegroundStatusHeader(&battlefieldStatus->Hdr, bg, queueSlot, queueId);
    battlefieldStatus->Mapid = bg->GetMapId();
    battlefieldStatus->Timeout = timeout;
}

void BattlegroundMgr::BuildBattlegroundStatusActive(WorldPackets::Battleground::BattlefieldStatusActive* battlefieldStatus, Battleground const* bg, Player const* player, uint32 queueSlot, BattlegroundQueueTypeId queueId)
{
    BuildBattlegroundStatusHeader(&battlefieldStatus->Hdr, bg, queueSlot, queueId);
    battlefieldStatus->ShutdownTimer = bg->GetEndTime();
    battlefieldStatus->ArenaFaction = player->GetBGTeam() == HORDE ? PVP_TEAM_HORDE : PVP_TEAM_ALLIANCE;
    battlefieldStatus->StartTimer = bg->GetStartTime();
    battlefieldStatus->Mapid = bg->GetMapId();
    if (bg->IsRandom())
    {
        BattlegroundTemplate const* realTemplate = sBattlegroundMgr->GetBattlegroundTemplateByTypeId(bg->GetTypeID(true));
        if (PvPDifficultyEntry const* realBracket = GetBattlegroundBracketByLevel(realTemplate->MapIDs.front(), DEFAULT_MAX_LEVEL))
            battlefieldStatus->RandomQueueID = BattlegroundQueueTypeId{
                .BattlemasterListId = uint16(realTemplate->Id),
                .BracketId = uint8(realBracket->GetBracketId()),
                .TeamSize = 0
            }.GetPacked();
    }
}

void BattlegroundMgr::BuildBattlegroundStatusQueued(WorldPackets::Battleground::BattlefieldStatusQueued* battlefieldStatus, Battleground const* bg, uint32 queueSlot, uint32 joinTime, BattlegroundQueueTypeId queueId, uint32 avgWaitTime)
{
    BuildBattlegroundStatusHeader(&battlefieldStatus->Hdr, bg, queueSlot, queueId);
    battlefieldStatus->AverageWaitTime = avgWaitTime;
    battlefieldStatus->WaitTime = GetMSTimeDiffToNow(joinTime);
}

void BattlegroundMgr::BuildBattlegroundStatusFailed(WorldPackets::Battleground::BattlefieldStatusFailed* battlefieldStatus, GroupJoinBattlegroundResult result, ObjectGuid const* errorGuid /*= nullptr*/)
{
    battlefieldStatus->Reason = result;
    if (errorGuid && (result == ERR_BATTLEGROUND_NOT_IN_BATTLEGROUND || result == ERR_BATTLEGROUND_JOIN_TIMED_OUT))
        battlefieldStatus->ClientID = *errorGuid;
}

void BattlegroundMgr::BuildGroupJoinedBattlegroundPacket(WorldPackets::Battleground::GroupJoinedBattleground* groupJoinedBattleground, BattlegroundTypeId bgTypeId)
{
    groupJoinedBattleground->Reason = bgTypeId;
}

Battleground* BattlegroundMgr::GetBattlegroundThroughClientInstance(uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    //cause at HandleBattlegroundJoinOpcode the clients sends the instanceid he gets from
    //SMSG_BATTLEFIELD_LIST we need to find the battleground with this clientinstance-id
    Battleground* bg = GetBattlegroundTemplate(bgTypeId);
    if (!bg)
        return nullptr;

    if (bg->isArena())
        return GetBattleground(instanceId, bgTypeId);

    BattlegroundDataContainer::const_iterator it = bgDataStore.find(bgTypeId);
    if (it == bgDataStore.end())
        return nullptr;

    for (BattlegroundContainer::const_iterator itr = it->second.m_Battlegrounds.begin(); itr != it->second.m_Battlegrounds.end(); ++itr)
    {
        if (itr->second->GetClientInstanceID() == instanceId)
            return itr->second.get();
    }

    return nullptr;
}

Battleground* BattlegroundMgr::GetBattleground(uint32 instanceId, BattlegroundTypeId bgTypeId)
{
    if (!instanceId)
        return nullptr;

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
            return nullptr;
        begin = end++;
    }

    for (BattlegroundDataContainer::const_iterator it = begin; it != end; ++it)
    {
        BattlegroundContainer const& bgs = it->second.m_Battlegrounds;
        BattlegroundContainer::const_iterator itr = bgs.find(instanceId);
        if (itr != bgs.end())
           return itr->second.get();
    }

    return nullptr;
}

Battleground* BattlegroundMgr::GetBattlegroundTemplate(BattlegroundTypeId bgTypeId)
{
    BattlegroundDataContainer::const_iterator itr = bgDataStore.find(bgTypeId);
    if (itr == bgDataStore.end())
        return nullptr;

    BattlegroundContainer const& bgs = itr->second.m_Battlegrounds;
    //map is sorted and we can be sure that lowest instance id has only BG template
    return bgs.empty() ? nullptr : bgs.begin()->second.get();
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
        TC_LOG_ERROR("bg.battleground", "Battleground: CreateNewBattleground - bg template not found for {}", bgTypeId);
        return nullptr;
    }

    Battleground* bg = nullptr;
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
            return nullptr;
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

    bg->SetMapId(!bgTemplate->MapIDs.empty() ? bgTemplate->MapIDs.front() : -1);
    bg->SetName(bgTemplate->BattlemasterEntry->Name[sWorld->GetDefaultDbcLocale()]);
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
    QueryResult result = WorldDatabase.Query("SELECT ID, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, AllianceStartLoc, AllianceStartO, HordeStartLoc, HordeStartO, StartMaxDist, Weight, ScriptName FROM battleground_template");
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

        BattlegroundTemplate bgTemplate;
        bgTemplate.Id                = bgTypeId;
        bgTemplate.MinPlayersPerTeam = fields[1].GetUInt16();
        bgTemplate.MaxPlayersPerTeam = fields[2].GetUInt16();
        bgTemplate.MinLevel          = fields[3].GetUInt8();
        bgTemplate.MaxLevel          = fields[4].GetUInt8();
        float dist                   = fields[9].GetFloat();
        bgTemplate.MaxStartDistSq    = dist * dist;
        bgTemplate.Weight            = fields[10].GetUInt8();
        bgTemplate.ScriptId          = sObjectMgr->GetScriptId(fields[11].GetString());
        bgTemplate.BattlemasterEntry = bl;
        for (int32 mapId : bl->MapID)
            if (sMapStore.LookupEntry(mapId))
                bgTemplate.MapIDs.push_back(mapId);

        if (bgTemplate.MaxPlayersPerTeam == 0 || bgTemplate.MinPlayersPerTeam > bgTemplate.MaxPlayersPerTeam)
        {
            TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains bad values for MinPlayersPerTeam ({}) and MaxPlayersPerTeam({}).",
                bgTemplate.Id, bgTemplate.MinPlayersPerTeam, bgTemplate.MaxPlayersPerTeam);
            continue;
        }

        if (bgTemplate.MinLevel == 0 || bgTemplate.MaxLevel == 0 || bgTemplate.MinLevel > bgTemplate.MaxLevel)
        {
            TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains bad values for MinLevel ({}) and MaxLevel ({}).",
                bgTemplate.Id, bgTemplate.MinLevel, bgTemplate.MaxLevel);
            continue;
        }

        if (bgTemplate.Id != BATTLEGROUND_AA && bgTemplate.Id != BATTLEGROUND_RB)
        {
            uint32 startId = fields[5].GetUInt32();
            if (WorldSafeLocsEntry const* start = sWorldSafeLocsStore.LookupEntry(startId))
            {
                bgTemplate.StartLocation[TEAM_ALLIANCE].Relocate(start->Loc.X, start->Loc.Y, start->Loc.Z, fields[6].GetFloat());
            }
            else
            {
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains a non-existing WorldSafeLocs.dbc id {} in field `AllianceStartLoc`. BG not created.", bgTemplate.Id, startId);
                continue;
            }

            startId = fields[7].GetUInt32();
            if (WorldSafeLocsEntry const* start = sWorldSafeLocsStore.LookupEntry(startId))
            {
                bgTemplate.StartLocation[TEAM_HORDE].Relocate(start->Loc.X, start->Loc.Y, start->Loc.Z, fields[8].GetFloat());
            }
            else
            {
                TC_LOG_ERROR("sql.sql", "Table `battleground_template` for id {} contains a non-existing WorldSafeLocs.dbc id {} in field `HordeStartLoc`. BG not created.", bgTemplate.Id, startId);
                continue;
            }
        }

        if (!CreateBattleground(&bgTemplate))
            continue;

        _battlegroundTemplates[bgTypeId] = bgTemplate;

        if (bgTemplate.MapIDs.size() == 1)
            _battlegroundMapTemplates[bgTemplate.MapIDs[0]] = &_battlegroundTemplates[bgTypeId];

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} battlegrounds in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void BattlegroundMgr::InitAutomaticArenaPointDistribution()
{
    if (!sWorld->getBoolConfig(CONFIG_ARENA_AUTO_DISTRIBUTE_POINTS) || !sWorld->getBoolConfig(CONFIG_ARENA_SEASON_IN_PROGRESS))
        return;

    time_t wstime = time_t(sWorld->getWorldState(WS_ARENA_DISTRIBUTION_TIME));
    time_t curtime = GameTime::GetGameTime();
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

void BattlegroundMgr::SendBattlegroundList(Player* player, ObjectGuid const& guid, BattlegroundTypeId bgTypeId)
{
    if (!player)
        return;

    uint32 winner_kills = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_HONOR_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_HONOR_FIRST);
    uint32 winner_arena = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_ARENA_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_WINNER_ARENA_FIRST);
    uint32 loser_kills = player->GetRandomWinner() ? sWorld->getIntConfig(CONFIG_BG_REWARD_LOSER_HONOR_LAST) : sWorld->getIntConfig(CONFIG_BG_REWARD_LOSER_HONOR_FIRST);

    winner_kills = Trinity::Honor::hk_honor_at_level(player->GetLevel(), float(winner_kills));
    loser_kills = Trinity::Honor::hk_honor_at_level(player->GetLevel(), float(loser_kills));

    WorldPackets::Battleground::BattlefieldList battlefieldList;
    battlefieldList.BattlemasterGuid = guid;
    battlefieldList.PvpAnywhere = guid.IsEmpty();
    battlefieldList.BattlemasterListID = bgTypeId;
    battlefieldList.MinLevel = 0;
    battlefieldList.MaxLevel = 0;

    battlefieldList.HasHolidayWinToday = player->GetRandomWinner();
    battlefieldList.HolidayWinHonorCurrencyBonus = winner_kills;
    battlefieldList.HolidayFirstWinArenaCurrencyBonus = winner_arena;
    battlefieldList.HolidayLossHonorCurrencyBonus = loser_kills;

    battlefieldList.HasRandomWinToday = player->GetRandomWinner();
    battlefieldList.RandomWinHonorCurrencyBonus = winner_kills;
    battlefieldList.RandomFirstWinArenaCurrencyBonus = winner_arena;
    battlefieldList.RandomLossHonorCurrencyBonus = loser_kills;

    if (bgTypeId != BATTLEGROUND_AA)
    {
        if (BattlegroundData const* battlegrounds = Trinity::Containers::MapGetValuePtr(bgDataStore, bgTypeId))
        {
            // expected bracket entry
            if (PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(battlegrounds->m_Battlegrounds.begin()->second->GetMapId(), player->GetLevel()))
                battlefieldList.Battlefields = &battlegrounds->m_ClientBattlegroundIds[bracketEntry->GetBracketId()];
        }
    }

    player->SendDirectMessage(battlefieldList.Write());
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
        TC_LOG_DEBUG("bg.battleground", "BattlegroundMgr::SendToBattleground: Sending {} to map {}, {} (bgType {})", player->GetName(), mapid, pos->ToString(), bgTypeId);
        player->TeleportTo(mapid, pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation());
    }
    else
        TC_LOG_ERROR("bg.battleground", "BattlegroundMgr::SendToBattleground: Instance {} (bgType {}) not found while trying to teleport player {}", instanceId, bgTypeId, player->GetName());
}

void BattlegroundMgr::SendAreaSpiritHealerQueryOpcode(Player* player, Battleground* bg, ObjectGuid guid)
{
    WorldPackets::Battleground::AreaSpiritHealerTime areaSpiritHealerTime;
    areaSpiritHealerTime.HealerGuid = guid;
    areaSpiritHealerTime.TimeLeft = std::max(30000 - int32(bg->GetLastResurrectTime()), 0);
    player->SendDirectMessage(areaSpiritHealerTime.Write());
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
    return battlemasterListId == BATTLEGROUND_RB;
}

BattlegroundQueueTypeId BattlegroundMgr::BGQueueTypeId(BattlegroundTypeId bgTypeId, uint8 bracketId, uint8 arenaType)
{
    return { .BattlemasterListId = uint16(bgTypeId), .BracketId = bracketId, .TeamSize = arenaType };
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

void BattlegroundMgr::ResetHolidays()
{
    for (uint32 i = BATTLEGROUND_AV; i < MAX_BATTLEGROUND_TYPE_ID; i++)
        if (Battleground* bg = GetBattlegroundTemplate(BattlegroundTypeId(i)))
            bg->SetHoliday(false);
}

void BattlegroundMgr::SetHolidayActive(uint32 battlegroundId)
{
    if (Battleground* bg = GetBattlegroundTemplate(BattlegroundTypeId(battlegroundId)))
        bg->SetHoliday(true);
}

bool BattlegroundMgr::IsValidQueueId(BattlegroundQueueTypeId bgQueueTypeId)
{
    BattlegroundTemplate const* battlemasterList = GetBattlegroundTemplateByTypeId(BattlegroundTypeId(bgQueueTypeId.BattlemasterListId));
    if (!battlemasterList)
        return false;

    switch (battlemasterList->BattlemasterEntry->InstanceType)
    {
        case MAP_BATTLEGROUND:
            if (bgQueueTypeId.TeamSize)
                return false;
            break;
        case MAP_ARENA:
            if (!bgQueueTypeId.TeamSize)
                return false;
            break;
        default:
            break;
    }

    if (battlemasterList->MapIDs.empty())
        return false;

    if (!GetBattlegroundBracketById(battlemasterList->MapIDs[0], BattlegroundBracketId(bgQueueTypeId.BracketId)))
        return false;

    return true;
}

void BattlegroundMgr::ScheduleQueueUpdate(uint32 arenaMatchmakerRating, BattlegroundQueueTypeId bgQueueTypeId)
{
    //This method must be atomic, @todo add mutex
    //we will use only 1 number created of bgTypeId and bracket_id
    ScheduledQueueUpdate scheduleId{ arenaMatchmakerRating, bgQueueTypeId };
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
        std::vector<BattlegroundTemplate const*> ids;
        ids.reserve(bgTemplate->MapIDs.size());
        for (int32 mapId : bgTemplate->MapIDs)
            if (BattlegroundTemplate const* bg = GetBattlegroundTemplateByMapId(mapId))
                ids.push_back(bg);

        if (!ids.empty())
            return (*Trinity::Containers::SelectRandomWeightedContainerElement(ids, [](BattlegroundTemplate const* bg) { return bg->Weight; }))->Id;
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
    {
        Trinity::unique_trackable_ptr<Battleground>& ptr = bgDataStore[bg->GetTypeID()].m_Battlegrounds[bg->GetInstanceID()];
        ptr.reset(bg);
        bg->SetWeakPtr(ptr);
    }
}
