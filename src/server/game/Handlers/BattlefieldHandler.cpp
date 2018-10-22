/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "WorldPacket.h"

void WorldSession::SendBattlefieldInvitePlayerToWar(uint32 battleId, uint32 zoneId, uint32 acceptTime)
{
}

void WorldSession::SendBattlefieldInvitePlayerToQueue(uint32 battleId)
{
}

void WorldSession::SendBattlefieldQueueInviteResponse(uint32 battleId, uint32 zoneId, bool canQueue, bool full)
{
}

void WorldSession::SendBattlefieldEntered(uint32 battleId)
{
}

void WorldSession::SendBattlefieldLeaveMessage(uint32 battleId, BFLeaveReason reason /*= BF_LEAVE_REASON_EXITED*/)
{
}

void WorldSession::SendBattlefieldEjectPending(uint32 battleId, bool remove)
{
}

void WorldSession::HandleBattlefieldEntryInviteResponse(WorldPacket& recvData)
{
}

void WorldSession::HandleBattlefieldQueueInviteResponse(WorldPacket& recvData)
{
}

void WorldSession::HandleBattlefieldExitRequest(WorldPacket& recvData)
{
}
