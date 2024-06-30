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

#include "LFGPacketsCommon.h"
#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Battlefield
    {
        class BattlefieldListRequest final : public ClientPacket
        {
        public:
            BattlefieldListRequest(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_LIST, std::move(packet)) { }

            void Read() override;

            uint8 BGType = 0;
            bool FromUI = false;
            int32 ListID = 0;
        };

        class BattlefieldList final : public ServerPacket
        {
        public:
            BattlefieldList() : ServerPacket(SMSG_BATTLEFIELD_LIST, 16 + 1 + 1 + 1 + 1 + 1 + 4 + 4 + 1 + 1 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid BattlemasterGuid;
            bool FromUI = false;
            uint8 BGType = 0;
            uint8 MinLevel = 0;
            uint8 MaxLevel = 0;
            bool HasWinToday = false;
            uint32 WinnerHonorReward = 0;
            uint32 WinnerArenaReward = 0;
            bool IsRandom = false;
            bool HasRandomWinToday = false;
            uint32 RandomWinnerHonorReward = 0;
            uint32 RandomWinnerArenaReward = 0;
            uint32 RandomLoserHonorReward = 0;
            uint32 BattlefielddInstanceCount = 0;
            std::vector<uint32> BattlefielInstanceIDs;
        };

        class BattlefieldStatus final : public ServerPacket
        {
        public:
            BattlefieldStatus() : ServerPacket(SMSG_BATTLEFIELD_STATUS, 8 + sizeof(Ticket) + 1 + 1 + 4 + 1 + 1 + 2 + 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            uint64 QueueID = 0;
            WorldPackets::LFG::RideTicket Ticket;
            uint8 RangeMin = 0;
            uint8 RangeMax = 0;
            uint32 InstanceID = 0;
            bool RegisteredMatch = false;
            uint8 BattleStatus = 0;
            uint16 MapId = 0;
            ObjectGuid ClientID;
            uint32 InstanceExpiration = 0;
            uint32 InstanceStartTime = 0;
            uint8 Team = 0;
        };

        class BattlefieldPort final : public ClientPacket
        {
        public:
            BattlefieldPort(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_PORT, std::move(packet)) { }

            void Read() override;

            WorldPackets::LFG::RideTicket Ticket;
            bool AcceptedInvite = false;
        };

        class BattlefieldLeave final : public ClientPacket
        {
        public:
            BattlefieldLeave(WorldPacket&& packet) : ClientPacket(CMSG_LEAVE_BATTLEFIELD, std::move(packet)) { }

            void Read() override { }

            WorldPackets::LFG::RideTicket Ticket;
        };

        class BattlefieldMgrEntryInvite final : public ServerPacket
        {
        public:
            BattlefieldMgrEntryInvite() : ServerPacket(SMSG_BATTLEFIELD_MGR_ENTRY_INVITE, 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            uint32 ZoneID = 0;
            time_t ExpireTime = time_t(0);
        };

        class BattlefieldMgrEntryInviteResponse final : public ClientPacket
        {
        public:
            BattlefieldMgrEntryInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_MGR_ENTRY_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 BattleID = 0;
            bool AcceptedInvite = false;
        };

        class BattlefieldMgrEntered final : public ServerPacket
        {
        public:
            BattlefieldMgrEntered() : ServerPacket(SMSG_BATTLEFIELD_MGR_ENTERED, 4 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            bool OnOffense = false;
            bool Relocated = false;
            bool ClearedAFK = false;
        };

        class BattlefieldMgrQueueInvite final : public ServerPacket
        {
        public:
            BattlefieldMgrQueueInvite() : ServerPacket(SMSG_BATTLEFIELD_MGR_QUEUE_INVITE, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            uint8 Warmup = 0;
        };

        class BattlefieldMgrQueueInviteResponse final : public ClientPacket
        {
        public:
            BattlefieldMgrQueueInviteResponse(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_MGR_QUEUE_INVITE_RESPONSE, std::move(packet)) { }

            void Read() override;

            uint32 BattleID = 0;
            bool AcceptedInvite = false;
        };

        class BattlefieldMgrQueueRequestResponse final : public ServerPacket
        {
        public:
            BattlefieldMgrQueueRequestResponse() : ServerPacket(SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE, 4 + 4 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            uint32 ZoneID = 0;
            int8 Accepted = 0;
            bool LoggingIn = false;
            uint8 Warmup = 0;
        };

        class BattlefieldMgrEjectPending final : public ServerPacket
        {
        public:
            BattlefieldMgrEjectPending() : ServerPacket(SMSG_BATTLEFIELD_MGR_EJECT_PENDING, 1 + sizeof(Ticket)) { }

            WorldPacket const* Write() override;

            bool Remove = false;
            WorldPackets::LFG::RideTicket Ticket;
        };

        class BattlefieldMgrEjected final : public ServerPacket
        {
        public:
            BattlefieldMgrEjected() : ServerPacket(SMSG_BATTLEFIELD_MGR_EJECTED, 4 + 1 + 1 + 1) { }

            WorldPacket const* Write() override;

            uint32 BattleID = 0;
            int8 Reason = 0;
            int8 BattleStatus = 0;
            bool Relocated = false;
        };

        class BattlefieldMgrExitRequest final : public ClientPacket
        {
        public:
            BattlefieldMgrExitRequest(WorldPacket&& packet) : ClientPacket(CMSG_BATTLEFIELD_MGR_EXIT_REQUEST, std::move(packet)) { }

            void Read() override;

            uint32 BattleID = 0;
        };

        class BattlefieldMgrStateChange final : public ServerPacket
        {
        public:
            BattlefieldMgrStateChange() : ServerPacket(SMSG_BATTLEFIELD_MGR_STATE_CHANGE, 1 + 1) { }

            WorldPacket const* Write() override;

            uint8 OldStatus = 0;
            uint8 NewStatus = 0;
        };
    }
}

#endif // BattlefieldPackets_h__
