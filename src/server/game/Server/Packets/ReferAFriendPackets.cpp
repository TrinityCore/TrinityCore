/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ReferAFriendPackets.h"

void WorldPackets::RaF::AcceptLevelGrant::Read()
{
    _worldPacket >> Granter;
}

void WorldPackets::RaF::GrantLevel::Read()
{
    _worldPacket >> Target;
}

WorldPacket const* WorldPackets::RaF::ProposeLevelGrant::Write()
{
    _worldPacket << Sender;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::RaF::ReferAFriendFailure::Write()
{
    _worldPacket << int32(Reason);
    // Client uses this string only if Reason == ERR_REFER_A_FRIEND_NOT_IN_GROUP || Reason == ERR_REFER_A_FRIEND_SUMMON_OFFLINE_S
    // but always reads it from packet
    _worldPacket.WriteBits(Str.length(), 6);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Str);

    return &_worldPacket;
}
