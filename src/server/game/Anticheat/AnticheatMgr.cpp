/*
 * Copyright (C) 2011-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "AnticheatMgr.h"
#include "Chat.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"

static float const CLIMB_ANGLE = 1.9f;

// wrapper for std::tan that prevents very large parameter
/// note: defined in Spell.cpp (move here?)
float tangent(float x);

AnticheatMgr::AnticheatMgr() : m_enabled(false) { }

AnticheatMgr::~AnticheatMgr()
{
    for (AnticheatCheck* check : m_checks)
        delete check;
}

AnticheatMgr* AnticheatMgr::instance()
{
    static AnticheatMgr instance;
    return &instance;
}

void AnticheatMgr::LoadSettings()
{
    // needed for reload
    for (AnticheatCheck* check : m_checks)
        delete check;

    m_checks.clear();

    m_enabled = sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE);
    if (!m_enabled)
        return;

    uint32 enabledChecksMask = sWorld->getIntConfig(CONFIG_ANTICHEAT_DETECTIONS_ENABLED);
    if ((enabledChecksMask & SPEED_HACK_DETECTION) != 0)
        m_checks.push_back(new SpeedHackCheck());

    if ((enabledChecksMask & FLY_HACK_DETECTION) != 0)
        m_checks.push_back(new FlyHackCheck());

    if ((enabledChecksMask & WALK_WATER_HACK_DETECTION) != 0)
        m_checks.push_back(new WalkOnWaterCheck());

    if ((enabledChecksMask & JUMP_HACK_DETECTION) != 0)
        m_checks.push_back(new JumpHackCheck());

    if ((enabledChecksMask & TELEPORT_PLANE_HACK_DETECTION) != 0)
        m_checks.push_back(new TeleportPlaneCheck());

    if ((enabledChecksMask & CLIMB_HACK_DETECTION) != 0)
        m_checks.push_back(new ClimbHackCheck());
}

template <ReportTypes type>
void AnticheatCheckBase<type>::HackReport(Player* player, AnticheatData* playerData) const
{
    bool sendReport = false;
    uint32 reportDelay = sWorld->getIntConfig(CONFIG_ANTICHEAT_PLAYER_REPORT_DELAY);

    if (type != REPORT_TYPE_JUMP)
    {
        uint32 actualTime = getMSTime();

        if (!playerData->GetTempReportsTimer(type))
            playerData->SetTempReportsTimer(actualTime, type);

        if (!playerData->GetLastReportTimer())
            playerData->SetLastReportTimer(actualTime);

        sendReport = getMSTimeDiff(playerData->GetLastReportTimer(), actualTime) >= reportDelay;

        if (getMSTimeDiff(playerData->GetTempReportsTimer(type), actualTime) < 3000)
        {
            playerData->SetTempReports(playerData->GetTempReports(type) + 1, type);
            if (playerData->GetTempReports(type) < 3)
                return;
        }
        else
        {
            playerData->SetTempReportsTimer(actualTime, type);
            playerData->SetTempReports(1, type);
            return;
        }
    }

    // generating creationTime for average calculation
    if (!playerData->GetTotalReports())
        playerData->SetCreationTime(getMSTime());

    // increasing total_reports
    playerData->SetTotalReports(playerData->GetTotalReports() + 1);
    // increasing specific cheat report
    playerData->SetTypeReports(type, playerData->GetTypeReports(type) + 1);

    // diff time for average calculation
    uint32 diffTime = getMSTimeDiff(playerData->GetCreationTime(), getMSTime()) / IN_MILLISECONDS;

    if (diffTime > 0)
    {
        // Average == Reports per second
        float average = float(playerData->GetTotalReports()) / float(diffTime);
        playerData->SetAverage(average);
    }

    if (sWorld->getIntConfig(CONFIG_ANTICHEAT_MAX_REPORTS_FOR_DAILY_REPORT) < playerData->GetTotalReports())
    {
        if (!playerData->GetDailyReportState())
        {
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AC_PLAYER_DAILY_REPORTS);
            stmt->setUInt32(0, player->GetGUID().GetCounter());
            trans->Append(stmt);

            uint8 index = 0;
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AC_PLAYER_DAILY_REPORTS);
            stmt->setUInt32(index,   player->GetGUID().GetCounter());
            stmt->setFloat (++index, playerData->GetAverage());
            stmt->setUInt32(++index, playerData->GetTotalReports());
            for (uint8 i = 0; i < MAX_REPORT_TYPES; ++i)
                stmt->setUInt32(++index, playerData->GetTypeReports(static_cast<ReportTypes>(i)));

            stmt->setUInt32(++index, playerData->GetCreationTime());
            trans->Append(stmt);

            CharacterDatabase.CommitTransaction(trans);
            playerData->SetDailyReportState(true);
        }
    }

    if (sendReport && playerData->GetTotalReports() > sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
    {
        playerData->SetLastReportTimer(getMSTime());

        WorldPacket data;
        std::string str = Trinity::StringFormat(sObjectMgr->GetTrinityStringForDBCLocale(LANG_AC_CHEAT_REPORT), player->GetName().c_str(), player->GetName().c_str());
        ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, NULL, NULL, str);
        sWorld->SendGlobalGMMessage(&data);
    }
}

bool SpeedHackCheck::OnCheck(Player* player, AnticheatData* /*playerData*/, MovementInfo const& movementInfo, uint16 /*opcode = 0*/) const
{
    // We also must check the map because the movementFlag can be modified by the client.
    // If we just check the flag, they could always add that flag and always skip the speed hacking detection.
    // 369 == DEEPRUN TRAM
    if (player->m_movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT) && player->GetMapId() == 369)
        return false;

    uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&player->m_movementInfo.pos);
    uint8 moveType = 0;

    // we need to know HOW is the player moving
    // TO-DO: Should we check the incoming movement flags?
    if (player->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
        moveType = MOVE_SWIM;
    else if (player->IsFlying())
        moveType = MOVE_FLIGHT;
    else if (player->HasUnitMovementFlag(MOVEMENTFLAG_WALKING))
        moveType = MOVE_WALK;
    else
        moveType = MOVE_RUN;

    // how many yards the player can do in one sec.
    uint32 speedRate = (uint32)(player->GetSpeed(UnitMoveType(moveType)) + movementInfo.jump.xyspeed);
    if (!speedRate && player->GetVehicle())
        speedRate = player->GetVehicleBase()->GetSpeed(UnitMoveType(moveType));

    // how long the player took to move to here.
    uint32 timeDiff = getMSTimeDiff(player->m_movementInfo.time, movementInfo.time);
    if (!timeDiff)
        timeDiff = 1;

    // this is the distance doable by the player in 1 sec, using the time done to move to this point.
    uint32 clientSpeedRate = distance2D * 1000 / timeDiff;

    // we did the (uint32) cast to accept a margin of tolerance
    if (clientSpeedRate > speedRate)
    {
        TC_LOG_TRACE("entities.player.character", "AnticheatMgr:: Speed-Hack detected on player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
        return true;
    }

    return false;
}

bool FlyHackCheck::OnCheck(Player* player, AnticheatData* /*playerData*/, MovementInfo const& /* movementInfo */, uint16 /*opcode = 0*/) const
{
    if (!player->m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING))
        return false;

    if (player->HasAuraType(SPELL_AURA_FLY) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED))
        return false;

    TC_LOG_TRACE("entities.player.character", "AnticheatMgr:: Fly-Hack detected on player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
    return true;
}

bool WalkOnWaterCheck::OnCheck(Player* player, AnticheatData* /*playerData*/, MovementInfo const& /* movementInfo */, uint16 /*opcode = 0*/) const
{
    if (!player->m_movementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING))
        return false;

    // if we are a ghost we can walk on water
    if (!player->IsAlive())
        return false;

    if (player->HasAuraType(SPELL_AURA_FEATHER_FALL) ||
        player->HasAuraType(SPELL_AURA_SAFE_FALL) ||
        player->HasAuraType(SPELL_AURA_WATER_WALK))
        return false;

    TC_LOG_TRACE("entities.player.character", "AnticheatMgr:: Walk on Water - Hack detected on player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
    return true;
}

bool JumpHackCheck::OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& /*movementInfo*/, uint16 opcode /*= 0*/) const
{
    if (playerData->GetLastOpcode() == MSG_MOVE_JUMP && opcode == MSG_MOVE_JUMP)
    {
        TC_LOG_TRACE("entities.player.character", "AnticheatMgr:: Jump-Hack detected on player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
        return true;
    }

    return false;
}

bool TeleportPlaneCheck::OnCheck(Player* player, AnticheatData* /*playerData*/, MovementInfo const& movementInfo, uint16 /*opcode = 0*/) const
{
    if (player->m_movementInfo.pos.GetPositionZ() != 0 ||
        movementInfo.pos.GetPositionZ() != 0)
        return false;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING))
        return false;

    //DEAD_FALLING was deprecated
    //if (player->getDeathState() == DEAD_FALLING)
    //    return;
    float x, y, z;
    player->GetPosition(x, y, z);
    float ground_Z = player->GetMap()->GetHeight(x, y, z);
    float z_diff = fabs(ground_Z - z);

    // we are not really walking there
    if (z_diff > 1.0f)
    {
        TC_LOG_TRACE("entities.player.character", "AnticheatMgr:: Teleport To Plane - Hack detected on player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
        return true;
    }

    return false;
}

// basic detection
bool ClimbHackCheck::OnCheck(Player* player, AnticheatData* playerData, MovementInfo const& movementInfo, uint16 opcode /*= 0*/) const
{
    if (opcode != MSG_MOVE_HEARTBEAT || playerData->GetLastOpcode() != MSG_MOVE_HEARTBEAT)
        return false;

    // in this case we don't care if they are "legal" flags, they are handled in another parts of the Anticheat Manager.
    if (player->IsInWater() ||
        player->IsFlying() ||
        player->IsFalling())
        return false;

    Position playerPos = player->GetPosition();

    float deltaZ = std::fabs(playerPos.GetPositionZ() - movementInfo.pos.GetPositionZ());
    float deltaXY = movementInfo.pos.GetExactDist2d(&playerPos);

    // Prevent divide by 0
    if (G3D::fuzzyEq(deltaXY, 0.f))
        return false;

    float angle = Position::NormalizeOrientation(tangent(deltaZ / deltaXY));

    if (angle > CLIMB_ANGLE)
    {
        TC_LOG_TRACE("entities.player.character", "AnticheatMgr:: Climb-Hack detected on player %s (%s)", player->GetName().c_str(), player->GetGUID().ToString().c_str());
        return true;
    }

    return false;
}

void AnticheatMgr::StartHackDetection(Player* player, MovementInfo const& movementInfo, uint16 opcode)
{
    if (!m_enabled)
        return;

    // Disable anticheat for Game Masters
    if (player->CanBeGameMaster())
        return;

    AnticheatData& plData = m_playerMap[player->GetGUID()];
    if (player->IsInFlight() || player->GetTransport() || player->GetVehicle())
    {
        plData.SetLastOpcode(opcode);
        return;
    }

    for (AnticheatCheck* check : m_checks)
        if (check->OnCheck(player, &plData, movementInfo, opcode))
            check->HackReport(player, &plData);

    plData.SetLastOpcode(opcode);
}

void AnticheatMgr::HandlePlayerLogin(Player* player, PreparedQueryResult result)
{
    AnticheatData& plData = m_playerMap[player->GetGUID()];

    if (result)
        plData.SetDailyReportState(true);
}

void AnticheatMgr::HandlePlayerLogout(ObjectGuid const& guid)
{
    // We must also delete it at logout to prevent have data of offline players in the db when we query the database (IE: The GM Command)
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AC_PLAYER_REPORTS);
    stmt->setUInt32(0, guid.GetCounter());
    CharacterDatabase.Execute(stmt);

    // Delete not needed data from the memory.
    m_playerMap.erase(guid);
}

void AnticheatMgr::SavePlayerData(ObjectGuid const& guid, SQLTransaction& trans)
{
    AnticheatData const& playerData = m_playerMap[guid];
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AC_PLAYER_REPORTS);
    stmt->setUInt32(0, guid.GetCounter());
    trans->Append(stmt);

    uint8 index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AC_PLAYER_REPORTS);
    stmt->setUInt32(index  , guid.GetCounter());
    stmt->setFloat (++index, playerData.GetAverage());
    stmt->setUInt32(++index, playerData.GetTotalReports());
    for (uint8 i = 0; i < MAX_REPORT_TYPES; ++i)
        stmt->setUInt32(++index, playerData.GetTypeReports(static_cast<ReportTypes>(i)));

    stmt->setUInt32(++index, playerData.GetCreationTime());
    trans->Append(stmt);
}

bool AnticheatMgr::AnticheatGlobalCommand(ChatHandler* handler)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    // Mutex protected part
    {
        boost::shared_lock<boost::shared_mutex> lock(*HashMapHolder<Player>::GetLock());

        HashMapHolder<Player>::MapType const& m = ObjectAccessor::GetPlayers();
        for (auto const& pair : m)
            SavePlayerData(pair.second->GetGUID(), trans);
    }
    CharacterDatabase.DirectCommitTransaction(trans);

    QueryResult resultDB = CharacterDatabase.Query("SELECT guid,average,total_reports FROM players_reports_status WHERE total_reports > 0 ORDER BY average ASC LIMIT 5");
    if (!resultDB)
    {
        handler->SendSysMessage(LANG_NO_PLAYERS_FOUND);
        handler->SetSentErrorMessage(true);
        return false;
    }
    else
    {
        handler->SendSysMessage(LANG_COMMAND_ACGLOBAL_BAR);
        handler->SendSysMessage(LANG_COMMAND_ACGLOBAL_AVERAGE_INFO);
        do
        {
            Field* fields = resultDB->Fetch();

            ObjectGuid::LowType lowGuid = fields[0].GetUInt32();
            float average = fields[1].GetFloat();
            uint32 total_reports = fields[2].GetUInt32();

            if (Player* player = sObjectMgr->GetPlayerByLowGUID(lowGuid))
                handler->PSendSysMessage(LANG_COMMAND_ACGLOBAL_AVERAGE_STATS, player->GetName().c_str(), average, total_reports);

        } while (resultDB->NextRow());
    }

    resultDB = CharacterDatabase.Query("SELECT guid, average, total_reports FROM players_reports_status WHERE total_reports > 0 ORDER BY total_reports DESC LIMIT 5");

    if (!resultDB)
    {
        handler->SendSysMessage(LANG_NO_PLAYERS_FOUND);
        handler->SetSentErrorMessage(true);
        return false;
    }
    else
    {
        handler->SendSysMessage(LANG_COMMAND_ACGLOBAL_BAR);
        handler->PSendSysMessage(LANG_COMMAND_ACGLOBAL_REPORT_INFO);
        do
        {
            Field* fields = resultDB->Fetch();

            ObjectGuid::LowType lowGuid = fields[0].GetUInt32();
            float average = fields[1].GetFloat();
            uint32 total_reports = fields[2].GetUInt32();

            if (Player* player = sObjectMgr->GetPlayerByLowGUID(lowGuid))
                handler->PSendSysMessage(LANG_COMMAND_ACGLOBAL_REPORT_STATS, player->GetName().c_str(), total_reports, average);

        } while (resultDB->NextRow());
    }

    return true;
}

void AnticheatMgr::ResetDailyReportStates()
{
    for (auto& plData : m_playerMap)
        plData.second.SetDailyReportState(false);
}
