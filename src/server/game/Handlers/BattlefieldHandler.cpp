/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "WorldPacket.h"

/**
 * @fn void WorldSession::SendBattlefieldInvitePlayerToWar(uint32 battleId, uint32 zoneId, uint32 acceptTime)
 *
 * @brief Sends join war frame to the player
 *
 * @param battleId   BattlefieldIDs enum
 * @param zoneId     Zone where the battlefield is
 * @param acceptTime Time in seconds displayed
 */
void WorldSession::SendBattlefieldInvitePlayerToWar(uint32 battleId, uint32 zoneId, uint32 acceptTime)
{
    WorldPacket data(SMSG_BATTLEFIELD_MGR_ENTRY_INVITE, 12);
    data << uint32(battleId);
    data << uint32(zoneId);
    data << uint32(time(nullptr) + acceptTime);
    SendPacket(&data);
}

/**
 * @fn void WorldSession::SendBattlefieldInvitePlayerToQueue(uint32 battleId)
 *
 * @brief Sends join queue frame to the player
 *
 * @param battleId BattlefieldIDs enum
 */
void WorldSession::SendBattlefieldInvitePlayerToQueue(uint32 battleId)
{
    WorldPacket data(SMSG_BATTLEFIELD_MGR_QUEUE_INVITE, 5);
    data << uint32(battleId);
    data << uint8(1); // warmup ? used ?
    SendPacket(&data);
}

/**
 * @fn void WorldSession::SendBattlefieldQueueInviteResponse(uint32 battleId, uint32 zoneId, bool canQueue, bool full)
 *
 * @brief Sends queue information to the player
 *
 * @param battleId BattlefieldIDs enum
 * @param zoneId   Zone where the battlefield is
 * @param canQueue Inform if the player can join queue or not
 * @param full     Inform if its full or not
 */
void WorldSession::SendBattlefieldQueueInviteResponse(uint32 battleId, uint32 zoneId, bool canQueue, bool full)
{
    WorldPacket data(SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE, 11);
    data << uint32(battleId);
    data << uint32(zoneId);
    data << uint8(canQueue ? 1 : 0); // Accepted    // 0 you cannot queue    // 1 you are queued
    data << uint8(full ? 0 : 1);     // Logging In  // 0 full                // 1 queue for upcoming
    data << uint8(1);                // Warmup
    SendPacket(&data);
}

/**
 * @fn void WorldSession::SendBattlefieldEntered(uint32 battleId)
 *
 * @brief Sent when the player joins a battlefield
 *
 * @param battleId BattlefieldIDs enum
 */
void WorldSession::SendBattlefieldEntered(uint32 battleId)
{
    WorldPacket data(SMSG_BATTLEFIELD_MGR_ENTERED, 7);
    data << uint32(battleId);
    data << uint8(1);                        // unk
    data << uint8(1);                        // unk
    data << uint8(_player->isAFK() ? 1 : 0); // Clear AFK
    SendPacket(&data);
}

/**
 * @fn void WorldSession::SendBattlefieldLeaveMessage(uint32 battleId, BFLeaveReason reason)
 *
 * @brief Sent when the player leaves the battlefield
 *
 * @param battleId BattlefieldIDs enum
 * @param reason   Reason why player the left
 */
void WorldSession::SendBattlefieldLeaveMessage(uint32 battleId, BFLeaveReason reason /*= BF_LEAVE_REASON_EXITED*/)
{
    WorldPacket data(SMSG_BATTLEFIELD_MGR_EJECTED, 7);
    data << uint32(battleId);
    data << uint8(reason); // byte Reason
    data << uint8(2);      // byte BattleStatus
    data << uint8(0);      // bool Relocated
    SendPacket(&data);
}

/**
 * @fn void WorldSession::HandleBattlefieldQueueInviteResponse(WorldPacket& recvData)
 *
 * @brief Sent on battlefield queue response
 */
void WorldSession::HandleBattlefieldQueueInviteResponse(WorldPacket& recvData)
{
    uint32 battleId;
    uint8 accepted;
    recvData >> battleId >> accepted;

    TC_LOG_DEBUG("misc", "WorldSession::HandleBattlefieldQueueInviteResponse: battleId: %u, accepted: %u", battleId, accepted);

    Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
    if (!battlefield)
        return;

    if (accepted)
        battlefield->PlayerAcceptsInviteToQueue(_player);
}

/**
 * @fn void WorldSession::HandleBattlefieldEntryInviteResponse(WorldPacket& recvData)
 *
 * @brief Sent on join to battlefield war response
 */
void WorldSession::HandleBattlefieldEntryInviteResponse(WorldPacket& recvData)
{
    uint32 battleId;
    uint8 accepted;
    recvData >> battleId >> accepted;
    TC_LOG_DEBUG("misc", "WorldSession::HandleBattlefieldEntryInviteResponse: battleId: %u, accepted: %u", battleId, accepted);

    Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
    if (!battlefield)
        return;

    if (accepted)
        battlefield->PlayerAcceptsInviteToWar(_player);
    else
        battlefield->PlayerLeavesQueue(_player, true);
}

/**
 * @fn void WorldSession::HandleBattlefieldExitRequest(WorldPacket& recvData)
 *
 * @brief Sent on battlefield queue exit request
 */
void WorldSession::HandleBattlefieldExitRequest(WorldPacket& recvData)
{
    uint32 battleId;
    recvData >> battleId;
    TC_LOG_DEBUG("misc", "HandleBfExitRequest: battleId: %u ", battleId);

    Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(battleId);
    if (!battlefield)
        return;

    battlefield->PlayerLeavesQueue(_player);
}
