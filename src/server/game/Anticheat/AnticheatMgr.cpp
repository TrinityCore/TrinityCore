/*
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

AnticheatMgr::AnticheatMgr() 
{
}

AnticheatMgr::~AnticheatMgr()
{
}

void AnticheatMgr::DeletePlayerReport(Player* player)
{
    if (!player->GetSession())
        return;

    CharacterDatabase.PExecute("DELETE FROM players_reports_status WHERE guid IN (SELECT guid FROM characters WHERE account=%u)",player->GetSession()->GetAccountId());
}

void AnticheatMgr::BuildReport(Player* player,uint8 reportType)
{
    if (player->anticheatData.total_reports == 0)
    {
        player->anticheatData.creation_time = time(NULL);
        CharacterDatabase.PExecute("INSERT IGNORE INTO players_reports_status (guid,creation_time) VALUES (%u,%u);",player->GetGUIDLow(),player->anticheatData.creation_time);
    }

    std::string report_type = report_types[reportType];

    player->anticheatData.type_reports[reportType]++;

    uint64 actual_time = time(NULL) - player->anticheatData.creation_time;

    player->anticheatData.average = player->anticheatData.total_reports > 0 ? ((player->anticheatData.average * (player->anticheatData.total_reports)) + actual_time) / (player->anticheatData.total_reports + 1) : 0;
    player->anticheatData.total_reports++;

    CharacterDatabase.PExecute("UPDATE players_reports_status SET %s=%u, total_reports=%u, average=%u WHERE guid=%u",report_type.c_str(),player->anticheatData.type_reports[reportType],player->anticheatData.total_reports,player->anticheatData.average,player->GetGUIDLow());
    
    if (player->anticheatData.total_reports > sWorld->getIntConfig(CONFIG_ANTICHEAT_REPORTS_INGAME_NOTIFICATION))
    {
        // display warning at the center of the screen, hacky way?
        std::string str = "";
        str = "|cFFFFFC00[AC]|cFF00FFFF[|cFF60FF00" + std::string(player->GetName()) + "|cFF00FFFF] Possible cheater!";
        WorldPacket data(SMSG_NOTIFICATION, (str.size()+1));
        data << str;
        sWorld->SendGlobalGMMessage(&data);
    }
}

void AnticheatMgr::DisableAnticheatDetection(Player* player, bool teleport)
{
    player->anticheatData.disableACCheck = true;
    player->anticheatData.disableACCheckTimer = (teleport ? 7000 : 5000);
}

void AnticheatMgr::HandleHackDetectionTimer(Player* player,uint32 diffTime)
{
    if (player->anticheatData.disableACCheck)
    {
        if (player->anticheatData.disableACCheckTimer <= diffTime)
        {
            player->anticheatData.disableACCheck = false;
        } else player->anticheatData.disableACCheckTimer -= diffTime;
    }
}

void AnticheatMgr::JumpHackDetection(Player* player, MovementInfo movementInfo,uint32 opcode)
{
    if (player->anticheatData.lastOpcode == MSG_MOVE_JUMP && opcode == MSG_MOVE_JUMP)
    {
        BuildReport(player,JUMP_HACK_REPORT);
        sLog->outError("Jump Hack Detection Player LowGuid %u",player->GetGUIDLow());
    }
}

void AnticheatMgr::WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!player->anticheatData.lastMovementInfo.HasMovementFlag(MOVEMENTFLAG_WATERWALKING))
        return;

    // if we are a ghost we can walk on water
    if (!player->isAlive())
        return;

    if (player->HasAuraType(SPELL_AURA_FEATHER_FALL) ||
        player->HasAuraType(SPELL_AURA_SAFE_FALL) ||
        player->HasAuraType(SPELL_AURA_WATER_WALK))
        return;

    sLog->outError("Walk on Water Player LowGuid %u",player->GetGUIDLow());
    BuildReport(player,WALK_WATER_HACK_REPORT);

}

void AnticheatMgr::FlyHackDetection(Player* player, MovementInfo movementInfo)
{
    if (!player->anticheatData.lastMovementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING))
        return;
    
    if (player->HasAuraType(SPELL_AURA_FLY) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) ||
        player->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED))
        return;
    
    sLog->outError("FlyHack Player LowGuid %u",player->GetGUIDLow());
    BuildReport(player,FLY_HACK_REPORT);
}

void AnticheatMgr::TeleportPlaneHackDetection(Player* player, MovementInfo movementInfo)
{
    if (player->anticheatData.lastMovementInfo.pos.GetPositionZ() != 0 ||
        movementInfo.pos.GetPositionZ() != 0)
        return;

    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING))
        return;

    if (player->getDeathState() == DEAD_FALLING)
        return;
    float x, y, z;
    player->GetPosition(x, y, z);
    float ground_Z = player->GetMap()->GetHeight(x, y, z);
    float z_diff = fabs(ground_Z - z);   

    // we are not really walking there
    if (z_diff > 1.0f)
        BuildReport(player,TELEPORT_PLANE_HACK_REPORT);
}

void AnticheatMgr::StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode)
{
    if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        return;

    if (player->isGameMaster())
        return;

    if (player->anticheatData.disableACCheck || player->isInFlight() || player->GetTransport() || player->GetVehicle())
    {
        player->anticheatData.lastMovementInfo = movementInfo;
        player->anticheatData.lastOpcode = opcode;
        return;
    }

    SpeedHackDetection(player,movementInfo);
    FlyHackDetection(player,movementInfo);
    WalkOnWaterHackDetection(player,movementInfo);
    JumpHackDetection(player,movementInfo,opcode);
    TeleportPlaneHackDetection(player, movementInfo);

    player->anticheatData.lastMovementInfo = movementInfo;
    player->anticheatData.lastOpcode = opcode;
}


void AnticheatMgr::SpeedHackDetection(Player* player,MovementInfo movementInfo)
{
    uint32 distance2D = (uint32)movementInfo.pos.GetExactDist2d(&player->anticheatData.lastMovementInfo.pos);
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
    uint32 speedRate = (uint32)(player->GetSpeed(UnitMoveType(moveType)) + movementInfo.j_xyspeed);
    
    // how long the player took to move to here.
    uint32 timeDiff = getMSTimeDiff(player->anticheatData.lastMovementInfo.time,movementInfo.time);

    if (timeDiff == 0)
        timeDiff = 1;

    // this is the distance doable by the player in 1 sec, using the time done to move to this point.
    uint32 clientSpeedRate = distance2D * 1000 / timeDiff;

    //sLog->outError("fallxy %f fallz %f Distance2D %u clientSpeedRate %u speedRate %u timeDiff %u ",movementInfo.j_xyspeed, movementInfo.j_zspeed,distance2D,clientSpeedRate,speedRate,timeDiff);
    
    // we did the (uint32) cast to accept a margin of tolerance
    if (clientSpeedRate > speedRate)
    {
        BuildReport(player,SPEED_HACK_REPORT);
        sLog->outError("Speed Hack Player LowGuid %u",player->GetGUIDLow());
    }
}