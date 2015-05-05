/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "AuthenticationPackets.h"

WorldPacket const* WorldPackets::Auth::AuthChallenge::Write()
{
    _worldPacket << uint32(DosZeroBits);
    _worldPacket << uint32(Challenge);
    _worldPacket.append<uint32>(DosChallenge, 8);
    return &_worldPacket;
}

void WorldPackets::Auth::AuthSession::Read()
{
    _worldPacket >> Build;
    _worldPacket >> LoginServerID;
    _worldPacket >> Account;
    _worldPacket >> LoginServerType;
    _worldPacket >> LocalChallenge;
    _worldPacket >> RegionID >> BattlegroupID;
    _worldPacket >> RealmID;
    _worldPacket >> DosResponse;
    _worldPacket.read(Digest, SHA_DIGEST_LENGTH);
    AddonInfo = &_worldPacket;
}

WorldPackets::Auth::AuthResponse::AuthResponse()
    : ServerPacket(SMSG_AUTH_RESPONSE, 16) { }

WorldPacket const* WorldPackets::Auth::AuthResponse::Write()
{
    _worldPacket << uint8(Result);
    
    if (SuccessInfo)
    {
        _worldPacket << uint32(SuccessInfo->TimeRemain);
        _worldPacket << uint8(SuccessInfo->TimeOptions);
        _worldPacket << uint32(SuccessInfo->TimeRested);
        _worldPacket << uint8(SuccessInfo->AccountExpansionLevel);
    }

    if (WaitInfo)
    {
        _worldPacket << uint32(WaitInfo->WaitCount);
        _worldPacket << uint8(WaitInfo->HasFCM ? 1 : 0);
    }

    return &_worldPacket;
}

void WorldPackets::Auth::Ping::Read()
{
    _worldPacket >> PingID;
    _worldPacket >> Latency;
}

WorldPackets::Auth::Pong::Pong()
    : ServerPacket(SMSG_PONG, 4) { }

WorldPacket const* WorldPackets::Auth::Pong::Write()
{
    _worldPacket << uint32(PingID);
    return &_worldPacket;
}
