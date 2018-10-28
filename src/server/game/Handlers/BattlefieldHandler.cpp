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
#include "SharedDefines.h"
#include "WorldPacket.h"

void WorldSession::SendBattlefieldInvitePlayerToWar(BattlefieldBattleId battleId, uint32 zoneId, uint32 acceptTime)
{
}

void WorldSession::SendBattlefieldInvitePlayerToQueue(BattlefieldBattleId battleId)
{
}

void WorldSession::SendBattlefieldQueueInviteResponse(BattlefieldBattleId battleId, uint32 zoneId, bool canQueue, bool full)
{
}

void WorldSession::SendBattlefieldEntered(BattlefieldBattleId battleId)
{
}

void WorldSession::SendBattlefieldLeaveMessage(BattlefieldBattleId battleId, BattlefieldLeaveReason reason /*= BATTLEFIELD_LEAVE_REASON_EXITED*/)
{
}

void WorldSession::SendBattlefieldEjectPending(BattlefieldBattleId battleId, bool remove)
{
}

void WorldSession::HandleBattlefieldEntryInviteResponse(WorldPackets::Battlefield::BattlefieldMgrEntryInviteResponse& entryInviteResponse)
{
}

void WorldSession::HandleBattlefieldQueueInviteResponse(WorldPackets::Battlefield::BattlefieldMgrQueueInviteResponse& queueInviteResponse)
{
}

void WorldSession::HandleBattlefieldExitRequest(WorldPackets::Battlefield::BattlefieldMgrExitRequest& exitRequest)
{
}
