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

#include "LFGPacketsCommon.h"
#include "PacketOperators.h"

namespace WorldPackets::LFG
{
ByteBuffer& operator>>(ByteBuffer& data, RideTicket& ticket)
{
    data >> ticket.RequesterGuid;
    data >> ticket.Id;
    data >> As<uint32>(ticket.Type);
    data >> ticket.Time;
    data >> Bits<1>(ticket.IsCrossFaction);
    data.ResetBitPos();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, RideTicket const& ticket)
{
    data << ticket.RequesterGuid;
    data << uint32(ticket.Id);
    data << As<uint32>(ticket.Type);
    data << ticket.Time;
    data << Bits<1>(ticket.IsCrossFaction);
    data.FlushBits();

    return data;
}
}
