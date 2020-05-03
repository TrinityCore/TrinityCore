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

#ifndef BattlenetPackets_h__
#define BattlenetPackets_h__

#include "Packet.h"
#include "BattlenetRpcErrorCodes.h"
#include "MessageBuffer.h"
#include <array>

namespace WorldPackets
{
    namespace Battlenet
    {
        struct MethodCall
        {
            uint64 Type = 0;
            uint64 ObjectId = 0;
            uint32 Token = 0;

            uint32 GetServiceHash() const { return uint32(Type >> 32); }
            uint32 GetMethodId() const { return uint32(Type & 0xFFFFFFFF); }
        };

        class Notification final : public ServerPacket
        {
        public:
            Notification() : ServerPacket(SMSG_BATTLENET_NOTIFICATION, 8 + 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            MethodCall Method;
            ByteBuffer Data;
        };

        class Response final : public ServerPacket
        {
        public:
            Response() : ServerPacket(SMSG_BATTLENET_RESPONSE, 4 + 8 + 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            BattlenetRpcErrorCode BnetStatus = ERROR_OK;
            MethodCall Method;
            ByteBuffer Data;
        };

        class SetSessionState final : public ServerPacket
        {
        public:
            SetSessionState() : ServerPacket(SMSG_BATTLENET_SET_SESSION_STATE, 1) { }

            WorldPacket const* Write() override;

            uint8 State = 0;
            bool SuppressNotification = true;
        };

        class RealmListTicket final : public ServerPacket
        {
        public:
            RealmListTicket() : ServerPacket(SMSG_BATTLENET_REALM_LIST_TICKET) { }

            WorldPacket const* Write() override;

            uint32 Token = 0;
            bool Allow = false;
            ByteBuffer Ticket;
        };

        class Request final : public ClientPacket
        {
        public:
            Request(WorldPacket&& packet) : ClientPacket(CMSG_BATTLENET_REQUEST, std::move(packet)) { }

            void Read() override;

            MethodCall Method;
            MessageBuffer Data;
        };

        class RequestRealmListTicket final : public ClientPacket
        {
        public:
            RequestRealmListTicket(WorldPacket&& packet) : ClientPacket(CMSG_BATTLENET_REQUEST_REALM_LIST_TICKET, std::move(packet)) { }

            void Read() override;

            uint32 Token = 0;
            std::array<uint8, 32> Secret = { };
        };
    }
}

#endif // BattlenetPackets_h__
