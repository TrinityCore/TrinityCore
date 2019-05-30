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

        class LFGProposalResponse final : public ClientPacket
        {
        public:
            LFGProposalResponse(WorldPacket&& packet) : ClientPacket(CMSG_LFG_PROPOSAL_RESULT, std::move(packet)) { }

            void Read() override;

            RideTicket Ticket;
            uint64 InstanceID = 0;
            uint32 ProposalID = 0;
            bool Accepted = false;
        };

        class LFGSetRoles final : public ClientPacket
        {
        public:
            LFGSetRoles(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_ROLES, std::move(packet)) { }

            void Read() override;

            uint32 RolesDesired = 0;
        };

        class LFGSetComment final : public ClientPacket
        {
        public:
            LFGSetComment(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_COMMENT, std::move(packet)) { }

            void Read() override;

            std::string Comment;
        };

        class LFGBootPlayerVote final : public ClientPacket
        {
        public:
            LFGBootPlayerVote(WorldPacket&& packet) : ClientPacket(CMSG_LFG_SET_BOOT_VOTE, std::move(packet)) { }

            void Read() override;

            bool Vote = false;
        };

        class LFGTeleport final : public ClientPacket
        {
        public:
            LFGTeleport(WorldPacket&& packet) : ClientPacket(CMSG_LFG_TELEPORT, std::move(packet)) { }

            void Read() override;

            bool TeleportOut = false;
        };

        class LFGGetSystemInfo final : public ClientPacket
        {
        public:
            LFGGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_LFG_LOCK_INFO_REQUEST, std::move(packet)) { }

            void Read() override;

            bool Player = false;
        };
    }
}

#endif // LFGPackets_h__
