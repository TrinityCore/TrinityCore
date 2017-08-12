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

#include "BattlefieldPackets.h"

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
    AcceptedInvite = _worldPacket.read<uint8>() != 0;
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
    AcceptedInvite = _worldPacket.read<uint8>() != 0;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrQueueRequestResponse::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << uint32(ZoneID);
    _worldPacket << int8(Accepted);
    _worldPacket << uint8(LoggingIn);
    _worldPacket << uint8(Warmup);
    return &_worldPacket;
}

void WorldPackets::Battlefield::BattlefieldMgrExitRequest::Read()
{
    _worldPacket >> BattleID;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEntered::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << uint8(OnOffense);
    _worldPacket << uint8(Relocated);
    _worldPacket << uint8(ClearedAFK);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEjected::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << int8(Reason);
    _worldPacket << int8(BattleStatus);
    _worldPacket << uint8(Relocated);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlefield::BattlefieldMgrEjectPending::Write()
{
    _worldPacket << uint32(BattleID);
    _worldPacket << uint8(Remove);
    return &_worldPacket;
}
