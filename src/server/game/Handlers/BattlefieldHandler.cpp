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
#include "BattlefieldPackets.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "WorldPacket.h"

/**
 * @fn void WorldSession::SendBattlefieldInvitePlayerToWar(uint32 battleId, uint32 zoneId, uint32 acceptTime)
 *
 * @brief Sends join war frame to the player
 *
 * @param battleId   BattlefieldId enum
 * @param zoneId     Zone where the battlefield is
 * @param acceptTime Time in seconds displayed
 */
void WorldSession::SendBattlefieldInvitePlayerToWar(uint32 battleId, uint32 zoneId, uint32 acceptTime)
{
    WorldPackets::Battlefield::MgrEntryInvite entryInvite;
    entryInvite.BattleID = battleId;
    entryInvite.ZoneID = zoneId;
    entryInvite.ExpireTime = uint32(time(nullptr) + acceptTime);
    SendPacket(entryInvite.Write());
}

/**
 * @fn void WorldSession::SendBattlefieldInvitePlayerToQueue(uint32 battleId)
 *
 * @brief Sends join queue frame to the player
 *
 * @param battleId BattlefieldId enum
 */
void WorldSession::SendBattlefieldInvitePlayerToQueue(uint32 battleId)
{
    WorldPackets::Battlefield::MgrQueueInvite queueInvite;
    queueInvite.BattleID = battleId;
    queueInvite.Warmup = 1; // not implemented
    SendPacket(queueInvite.Write());
}

/**
 * @fn void WorldSession::SendBattlefieldQueueInviteResponse(uint32 battleId, uint32 zoneId, bool canQueue, bool full)
 *
 * @brief Sends queue information to the player
 *
 * @param battleId BattlefieldId enum
 * @param zoneId   Zone where the battlefield is
 * @param canQueue Inform if the player can join queue or not
 * @param full     Inform if its full or not
 */
void WorldSession::SendBattlefieldQueueInviteResponse(uint32 battleId, uint32 zoneId, bool canQueue, bool full)
{
    WorldPackets::Battlefield::MgrQueueRequestResponse queueRequestResponse;
    queueRequestResponse.BattleID = battleId;
    queueRequestResponse.ZoneID = zoneId;
    queueRequestResponse.Accepted = canQueue ? 1 : 0;
    queueRequestResponse.LoggingIn = !full;
    queueRequestResponse.Warmup = 1; // not implemented
    SendPacket(queueRequestResponse.Write());
}

/**
 * @fn void WorldSession::SendBattlefieldEntered(uint32 battleId)
 *
 * @brief Sent when the player joins a battlefield
 *
 * @param battleId BattlefieldId enum
 */
void WorldSession::SendBattlefieldEntered(uint32 battleId)
{
    WorldPackets::Battlefield::MgrEntered entered;
    entered.BattleID = battleId;
    entered.OnOffense = true; // not implemented
    entered.Relocated = true; // not implemented
    entered.ClearedAFK = _player->isAFK();
    SendPacket(entered.Write());
}

/**
 * @fn void WorldSession::SendBattlefieldLeaveMessage(uint32 battleId, BFLeaveReason reason)
 *
 * @brief Sent when the player leaves the battlefield
 *
 * @param battleId BattlefieldId enum
 * @param reason   Reason why player the left
 */
void WorldSession::SendBattlefieldLeaveMessage(uint32 battleId, BFLeaveReason reason /*= BF_LEAVE_REASON_EXITED*/)
{
    WorldPackets::Battlefield::MgrEjected ejected;
    ejected.BattleID = battleId;
    ejected.Reason = uint8(reason);
    ejected.BattleStatus = 2; // not implemented
    ejected.Relocated = false; // not implemented
    SendPacket(ejected.Write());
}

void WorldSession::SendBattlefieldEjectPending(bool remove)
{
}

/**
* @fn void WorldSession::HandleBattlefieldEntryInviteResponse(WorldPackets::Battlefield::MgrEntryInviteResponse& entryInviteResponse)
*
* @brief Sent on join to battlefield war response
*/
void WorldSession::HandleBattlefieldEntryInviteResponse(WorldPackets::Battlefield::MgrEntryInviteResponse& entryInviteResponse)
{
    uint32 battleId = entryInviteResponse.BattleID;
    bool accepted = entryInviteResponse.AcceptedInvite;
    TC_LOG_DEBUG("misc", "WorldSession::HandleBattlefieldEntryInviteResponse: battleId: %u, accepted: %u", battleId, accepted);

    Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(BattlefieldId(battleId));
    if (!battlefield)
        return;

    if (accepted)
        battlefield->PlayerAcceptsInviteToWar(_player);
    else
        battlefield->PlayerLeavesQueue(_player, true);
}

/**
 * @fn void WorldSession::HandleBattlefieldQueueInviteResponse(WorldPackets::Battlefield::MgrQueueInviteResponse& queueInviteResponse)
 *
 * @brief Sent on battlefield queue response
 */
void WorldSession::HandleBattlefieldQueueInviteResponse(WorldPackets::Battlefield::MgrQueueInviteResponse& queueInviteResponse)
{
    uint32 battleId = queueInviteResponse.BattleID;
    bool accepted = queueInviteResponse.AcceptedInvite;
    TC_LOG_DEBUG("misc", "WorldSession::HandleBattlefieldQueueInviteResponse: battleId: %u, accepted: %u", battleId, accepted);

    Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(BattlefieldId(battleId));
    if (!battlefield)
        return;

    if (accepted)
        battlefield->PlayerAcceptsInviteToQueue(_player);
}

/**
 * @fn void WorldSession::HandleBattlefieldExitRequest(WorldPackets::Battlefield::MgrExitRequest& exitRequest)
 *
 * @brief Sent on battlefield queue exit request
 */
void WorldSession::HandleBattlefieldExitRequest(WorldPackets::Battlefield::MgrExitRequest& exitRequest)
{
    uint32 battleId = exitRequest.BattleID;
    TC_LOG_DEBUG("misc", "HandleBfExitRequest: battleId: %u ", battleId);

    Battlefield* battlefield = sBattlefieldMgr->GetBattlefield(BattlefieldId(battleId));
    if (!battlefield)
        return;

    battlefield->PlayerLeavesQueue(_player);
}
