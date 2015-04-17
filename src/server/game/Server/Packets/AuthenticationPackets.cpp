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

WorldPackets::Auth::AuthResponse::AuthResponse(bool shortForm)
    : ServerPacket(SMSG_AUTH_RESPONSE, shortForm ? 11 : 16), que(!shortForm) { }

WorldPacket const* WorldPackets::Auth::AuthResponse::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << uint32(SuccessInfo.TimeRemain);
    _worldPacket << uint8(SuccessInfo.TimeOptions);
    _worldPacket << uint32(SuccessInfo.TimeRested);
    _worldPacket << uint8(SuccessInfo.AccountExpansionLevel);

    if (que)
    {
        _worldPacket << uint32(WaitInfo.WaitCount);
        _worldPacket << uint8(WaitInfo.HasFCM);
    }

    return &_worldPacket;
}
