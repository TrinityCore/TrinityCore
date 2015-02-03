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

#ifndef TRINITYCORE_TICKET_PACKETS_H
#define TRINITYCORE_TICKET_PACKETS_H

#include "Packet.h"

namespace WorldPackets
{
    namespace Ticket
    {
        class GMTicketGetSystemStatus final : public ClientPacket
        {
        public:
            explicit GMTicketGetSystemStatus(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_SYSTEMSTATUS, std::move(packet)) { }

            void Read() override { }
        };

        class GMTicketSystemStatus final : public ServerPacket
        {
        public:
            explicit GMTicketSystemStatus() : ServerPacket(SMSG_GMTICKET_SYSTEMSTATUS, 4) { }

            WorldPacket const* Write() override;

            int32 Status = 0;
        };

        class GMTicketGetTicket final : public ClientPacket
        {
        public:
            explicit GMTicketGetTicket(WorldPacket&& packet) : ClientPacket(CMSG_GMTICKET_GETTICKET, std::move(packet)) { }

            void Read() override { }
        };

        struct GMTicketInfo
        {
            int32 TicketID = 0;
            std::string_view TicketDescription;
            uint8 Category = 0;
            float TicketOpenTime = 0;
            float OldestTicketTime = 0;
            float UpdateTime = 0;
            uint8 AssignedToGM = 0;
            uint8 OpenedByGM = 0;
        };

        class GMTicketGetTicketResponse final : public ServerPacket
        {
        public:
            explicit GMTicketGetTicketResponse() : ServerPacket(SMSG_GMTICKET_GETTICKET) { }

            WorldPacket const* Write() override;

            int32 Result = 0;
            GMTicketInfo Info;
        };
    }
}

#endif // TRINITYCORE_TICKET_PACKETS_H
