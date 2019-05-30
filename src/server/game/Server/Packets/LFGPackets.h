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

#ifndef LFGPackets_h__
#define LFGPackets_h__

#include "Packet.h"
#include "LFGPacketsCommon.h"
#include "Optional.h"

namespace lfg
{
    enum LfgTeleportResult : uint8;
}

namespace WorldPackets
{
    namespace LFG
    {
        class LFGJoin final : public ClientPacket
        {
        public:
            LFGJoin(WorldPacket&& packet) : ClientPacket(CMSG_LFG_JOIN, std::move(packet)) { }

            void Read() override;

            uint32 Roles = 0;
            std::string Comment;
            Array<uint32, 50> Slots;
        };

        class LFGLeave final : public ClientPacket
        {
        public:
            LFGLeave(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LEAVE, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
        };
    }
}

#endif // LFGPackets_h__
