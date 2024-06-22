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

#include "BattlefieldPackets.h"

void WorldPackets::Battlefield::BattlefieldListRequest::Read()
{
    _worldPacket >> BGType;
    _worldPacket >> FromUI;
    _worldPacket >> ListID;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldList::Write()
{
    _worldPacket << BattlemasterGuid;
    _worldPacket << FromUI;
    _worldPacket << uint8(BGType);
    _worldPacket << uint8(MinLevel);
    _worldPacket << uint8(MaxLevel);
    _worldPacket << HasWinToday;
    _worldPacket << uint32(WinnerHonorReward);
    _worldPacket << uint32(WinnerArenaReward);
    _worldPacket << IsRandom;
    _worldPacket << HasRandomWinToday;
    _worldPacket << uint32(RandomWinnerHonorReward);
    _worldPacket << uint32(RandomWinnerArenaReward);
    _worldPacket << uint32(RandomLoserHonorReward);
    _worldPacket << uint32(BattlefielddInstanceCount);
    if (!BattlefielInstanceIDs.empty())
        _worldPacket.append(BattlefielInstanceIDs.data(), BattlefielInstanceIDs.size());

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldStatus::Write()
{
    _worldPacket << uint64(QueueID);
    _worldPacket << Ticket;
    _worldPacket << uint8(RangeMin);
    _worldPacket << uint8(RangeMax);
    _worldPacket << uint32(InstanceID);
    _worldPacket << RegisteredMatch;
    _worldPacket << uint8(BattleStatus);
    _worldPacket << uint16(MapId);
    _worldPacket << ClientID;
    _worldPacket << uint32(InstanceExpiration);
    _worldPacket << uint32(InstanceStartTime);
    _worldPacket << uint8(Team);
    return &_worldPacket;
}

void WorldPackets::Battlefield::BattlefieldPort::Read()
{
    _worldPacket >> Ticket;
    _worldPacket >> AcceptedInvite;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEntryInvite::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << uint32(ZoneID);
    _worldPacket << uint32(ExpireTime);
    return &_worldPacket;
}

void WorldPackets::Battlefield::BattlefieldMgrEntryInviteResponse::Read()
{
    _worldPacket >> BattleID;
    _worldPacket >> AcceptedInvite;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEntered::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << OnOffense;
    _worldPacket << Relocated;
    _worldPacket << ClearedAFK;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrQueueInvite::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << uint8(Warmup);
    return &_worldPacket;
}

void WorldPackets::Battlefield::BattlefieldMgrQueueInviteResponse::Read()
{
    _worldPacket >> BattleID;
    _worldPacket >> AcceptedInvite;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrQueueRequestResponse::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << uint32(ZoneID);
    _worldPacket << int8(Accepted);
    _worldPacket << LoggingIn;
    _worldPacket << uint8(Warmup);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEjectPending::Write()
{
    _worldPacket << Remove;
    _worldPacket << Ticket;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEjected::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << int8(Reason);
    _worldPacket << int8(BattleStatus);
    _worldPacket << Relocated;
    return &_worldPacket;
}

void WorldPackets::Battlefield::BattlefieldMgrExitRequest::Read()
{
    _worldPacket >> BattleID;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrStateChange::Write()
{
    _worldPacket << uint8(OldStatus);
    _worldPacket << uint8(NewStatus);
    return &_worldPacket;
}
