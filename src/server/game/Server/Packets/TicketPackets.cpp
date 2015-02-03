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

#include "TicketPackets.h"
#include "TicketMgr.h"

namespace WorldPackets::Ticket
{
WorldPacket const* GMTicketSystemStatus::Write()
{
    _worldPacket << int32(Status);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GMTicketInfo const& gmTicketInfo)
{
    data << int32(gmTicketInfo.TicketID);
    data << gmTicketInfo.TicketDescription;
    data << uint8(gmTicketInfo.Category);
    data << float(gmTicketInfo.TicketOpenTime);
    data << float(gmTicketInfo.OldestTicketTime);
    data << float(gmTicketInfo.UpdateTime);
    data << uint8(gmTicketInfo.AssignedToGM);
    data << uint8(gmTicketInfo.OpenedByGM);

    return data;
}

WorldPacket const* GMTicketGetTicketResponse::Write()
{
    _worldPacket << int32(Result);
    if (Result == GMTICKET_STATUS_HASTEXT)
        _worldPacket << Info;

    return &_worldPacket;
}
}
