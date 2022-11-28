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

void WorldPackets::Ticket::Complaint::Read()
{
    _worldPacket >> ComplaintType; // 0 = mail, 1 = chat
    _worldPacket >> Offender.PlayerGuid;

    switch (ComplaintType)
    {
        case 0: // mail
            _worldPacket.read_skip<uint32>(); // unused
            _worldPacket >> MailID;
            _worldPacket.read_skip<uint32>(); // unused
            break;
        case 1: // chat
            _worldPacket >> Chat.ChatFlags;
            _worldPacket >> Chat.Command;
            _worldPacket >> Chat.ChannelID;
            _worldPacket >> Offender.TimeSinceOffence;
            _worldPacket >> Chat.MessageLog;
            break;
        default:
            break;
    }
}

WorldPacket const* WorldPackets::Ticket::ComplaintResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << uint8(ComplaintType);

    return &_worldPacket;
}
