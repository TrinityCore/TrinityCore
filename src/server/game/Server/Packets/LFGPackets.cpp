/*
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#include "LFGPackets.h"

void WorldPackets::LFG::LFGJoin::Read()
{
    _worldPacket >> Roles;
    for (uint8 i = 0; i < 3; ++i)
        _worldPacket.read_skip<uint32>();

    uint32 commentLength = _worldPacket.ReadBits(9);
    Slots.resize(_worldPacket.ReadBits(24));
    Comment = _worldPacket.ReadString(commentLength);

    for (uint32& slot : Slots)
        _worldPacket >> slot;
}


void WorldPackets::LFG::LFGLeave::Read()
{
    _worldPacket.read_skip<uint32>();
    _worldPacket >> Ticket.Time;
    uint32 type = 0;
    _worldPacket >> type;
    Ticket.Type = RideType(type);
    _worldPacket >> Ticket.Id;

    ObjectGuid& requesterGuid = Ticket.RequesterGuid;
    requesterGuid[4] = _worldPacket.ReadBit();
    requesterGuid[5] = _worldPacket.ReadBit();
    requesterGuid[0] = _worldPacket.ReadBit();
    requesterGuid[6] = _worldPacket.ReadBit();
    requesterGuid[2] = _worldPacket.ReadBit();
    requesterGuid[7] = _worldPacket.ReadBit();
    requesterGuid[1] = _worldPacket.ReadBit();
    requesterGuid[3] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(requesterGuid[7]);
    _worldPacket.ReadByteSeq(requesterGuid[4]);
    _worldPacket.ReadByteSeq(requesterGuid[3]);
    _worldPacket.ReadByteSeq(requesterGuid[2]);
    _worldPacket.ReadByteSeq(requesterGuid[6]);
    _worldPacket.ReadByteSeq(requesterGuid[0]);
    _worldPacket.ReadByteSeq(requesterGuid[1]);
    _worldPacket.ReadByteSeq(requesterGuid[5]);
}
