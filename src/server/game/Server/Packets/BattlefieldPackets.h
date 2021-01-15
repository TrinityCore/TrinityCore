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

#ifndef BattlefieldPackets_h__
#define BattlefieldPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Battlefield
    {
        class BFMgrEntryInvite final : public ServerPacket
        {
        public:
            BFMgrEntryInvite() : ServerPacket(SMSG_BF_MGR_ENTRY_INVITE, 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 QueueID = 0;
            int32 AreaID = 0;
            time_t ExpireTime = time_t(0);
        };

        class BFMgrEntryInviteResponse final : public ClientPacket
        {
        public:
            BFMgrEntryInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_BF_MGR_ENTRY_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint64 QueueID = 0;
            bool AcceptedInvite = false;
        };

        class BFMgrQueueInvite final : public ServerPacket
        {
        public:
            BFMgrQueueInvite() : ServerPacket(SMSG_BF_MGR_QUEUE_INVITE, 8 + 4 + 4 + 4 + 4 + 4 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint64 QueueID = 0;
            int8 BattleState = 0;
            uint32 Timeout = std::numeric_limits<uint32>::max();    // unused in client
            int32 MinLevel = 0;                                     // unused in client
            int32 MaxLevel = 0;                                     // unused in client
            int32 MapID = 0;                                        // unused in client
            uint32 InstanceID = 0;                                  // unused in client
            int8 Index = 0;                                         // unused in client
        };

        class BFMgrQueueInviteResponse final : public ClientPacket
        {
        public:
            BFMgrQueueInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_BF_MGR_QUEUE_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint64 QueueID = 0;
            bool AcceptedInvite = false;
        };

        class BFMgrQueueRequestResponse final : public ServerPacket
        {
        public:
            BFMgrQueueRequestResponse() : ServerPacket(SMSG_BF_MGR_QUEUE_REQUEST_RESPONSE, 8 + 4 + 1 + 16 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint64 QueueID = 0;
            int32 AreaID = 0;
            int8 Result = 0;
            ObjectGuid FailedPlayerGUID;
            int8 BattleState = 0;
            bool LoggingIn = false;
        };

        class BFMgrQueueExitRequest final : public ClientPacket
        {
        public:
            BFMgrQueueExitRequest(WorldPacket&& packet) : ClientPacket(CMSG_BF_MGR_QUEUE_EXIT_REQUEST, std::move(packet)) { }

            void Read() override;

            uint64 QueueID = 0;
        };

        class BFMgrEntering final : public ServerPacket
        {
        public:
            BFMgrEntering() : ServerPacket(SMSG_BF_MGR_ENTERING, 1 + 8) { }

            WorldPacket const* Write() override;

            bool ClearedAFK = false;
            bool Relocated = false;
            bool OnOffense = false;
            uint64 QueueID = 0;
        };

        class BFMgrEjected final : public ServerPacket
        {
        public:
            BFMgrEjected() : ServerPacket(SMSG_BF_MGR_EJECTED, 8 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint64 QueueID = 0;
            int8 Reason = 0;
            int8 BattleState = 0;
            bool Relocated = false;
        };
    }
}

#endif // BattlefieldPackets_h__
