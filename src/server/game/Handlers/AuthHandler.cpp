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

#include "Opcodes.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "AuthenticationPackets.h"

void WorldSession::SendAuthResponse(uint8 code, bool shortForm, uint32 queuePos)
{
    WorldPackets::Auth::AuthResponse packet;
    packet.Result = code;
    
    packet.SuccessInfo = boost::in_place();
    packet.SuccessInfo->AccountExpansionLevel = Expansion();
    packet.SuccessInfo->TimeOptions = 0;
    packet.SuccessInfo->TimeRemain = 0;
    packet.SuccessInfo->TimeRested = 0;

    if (!shortForm)
    {
        packet.WaitInfo = boost::in_place();
        packet.WaitInfo->HasFCM = false;
        packet.WaitInfo->WaitCount = queuePos;
    }

    SendPacket(packet.Write());
}

void WorldSession::SendClientCacheVersion(uint32 version)
{
    WorldPacket data(SMSG_CLIENTCACHE_VERSION, 4);
    data << uint32(version);
    SendPacket(&data);
}
