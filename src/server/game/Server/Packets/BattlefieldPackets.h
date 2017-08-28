/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef BattlefieldPackets_h__
#define BattlefieldPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Battlefield
    {
        class MgrEntryInvite final : public ServerPacket
        {
        public:
            MgrEntryInvite() : ServerPacket(SMSG_BATTLEFIELD_MGR_ENTRY_INVITE, 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            uint32 ZoneID = 0;
            time_t ExpireTime = time_t(0);
        };

        class MgrEntryInviteResponse final : public ClientPacket
        {
        public:
            MgrEntryInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 BattleID = 0;
            bool AcceptedInvite = false;
        };

        class MgrQueueInvite final : public ServerPacket
        {
        public:
            MgrQueueInvite() : ServerPacket(SMSG_BATTLEFIELD_MGR_QUEUE_INVITE, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            uint8 Warmup = 0;
        };

        class MgrQueueInviteResponse final : public ClientPacket
        {
        public:
            MgrQueueInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 BattleID = 0;
            bool AcceptedInvite = false;
        };

        class MgrQueueRequestResponse final : public ServerPacket
        {
        public:
            MgrQueueRequestResponse() : ServerPacket(SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE, 4 + 4 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            uint32 ZoneID = 0;
            int8 Accepted = 0;
            bool LoggingIn = false;
            uint8 Warmup = 0;
        };

        class MgrExitRequest final : public ClientPacket
        {
        public:
            MgrExitRequest(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_MGR_EXIT_REQUEST, std::move(packet)) { }

            void Read() override;

            uint32 BattleID = 0;
        };

        class MgrEntered final : public ServerPacket
        {
        public:
            MgrEntered() : ServerPacket(SMSG_BATTLEFIELD_MGR_ENTERED, 4 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            bool OnOffense = false;
            bool Relocated = false;
            bool ClearedAFK = false;
        };

        class MgrEjected final : public ServerPacket
        {
        public:
            MgrEjected() : ServerPacket(SMSG_BATTLEFIELD_MGR_EJECTED, 4 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            int8 Reason = 0;
            int8 BattleStatus = 0;
            bool Relocated = false;
        };
    }
}

#endif // BattlefieldPackets_h__
