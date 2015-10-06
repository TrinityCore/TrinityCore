/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ConnectionPackets_h__
#define ConnectionPackets_h__

#include "PacketsBase.h"

namespace Battlenet
{
    namespace Connection
    {
        enum Opcode
        {
            CMSG_PING               = 0x0,
            CMSG_ENABLE_ENCRYPTION  = 0x5,
            CMSG_LOGOUT_REQUEST     = 0x6,
            CMSG_DISCONNECT_REQUEST = 0x7,  // Not handled
            CMSG_CONNECTION_CLOSING = 0x9,

            SMSG_PONG               = 0x0,
            SMSG_BOOM               = 0x1,  // Not implemented
            SMSG_REGULATOR_UPDATE   = 0x2,  // Not implemented
            SMSG_SERVER_VERSION     = 0x3,  // Not implemented
            SMSG_STUN_SERVERS       = 0x4   // Not implemented
        };

        class Ping final : public ClientPacket
        {
        public:
            Ping(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_PING, CONNECTION) && "Invalid packet header for Ping");
            }

            void Read() override { }
            std::string ToString() const override;
            void CallHandler(Session* session) override;
        };

        class EnableEncryption final : public ClientPacket
        {
        public:
            EnableEncryption(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_ENABLE_ENCRYPTION, CONNECTION) && "Invalid packet header for EnableEncryption");
            }

            void Read() override { }
            std::string ToString() const override;
            void CallHandler(Session* session) override;
            uint8* GetRemainingData() { return _stream.GetBuffer() + (((_stream.GetReadPos() + 7) & ~7) / 8); }
            size_t GetRemainingSize() const { return _stream.GetSize() - (((_stream.GetReadPos() + 7) & ~7) / 8); }
        };

        class LogoutRequest final : public ClientPacket
        {
        public:
            LogoutRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_LOGOUT_REQUEST, CONNECTION) && "Invalid packet header for LogoutRequest");
            }

            void Read() override { }
            std::string ToString() const override;
            void CallHandler(Session* session) override;
        };

        class DisconnectRequest final : public ClientPacket
        {
        public:
            DisconnectRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_DISCONNECT_REQUEST, CONNECTION) && "Invalid packet header for DisconnectRequest");
            }

            void Read() override;
            std::string ToString() const override;

            uint16 Error = 0;
            uint32 Timeout = 0;
        };

        class ConnectionClosing final : public ClientPacket
        {
        public:
            enum ClosingReason
            {
                PACKET_TOO_LARGE = 1,
                PACKET_CORRUPT = 2,
                PACKET_INVALID = 3,
                PACKET_INCORRECT = 4,
                HEADER_CORRUPT = 5,
                HEADER_IGNORED = 6,
                HEADER_INCORRECT = 7,
                PACKET_REJECTED = 8,
                CHANNEL_UNHANDLED = 9,
                COMMAND_UNHANDLED = 10,
                COMMAND_BAD_PERMISSIONS = 11,
                DIRECT_CALL = 12,
                TIMEOUT = 13,
            };

            struct PacketInfo : public PrintableComponent
            {
                std::string Layer;
                std::string Command;
                uint16 Offset;
                uint16 Size;
                uint32 Time;

                std::string ToString() const override;
            };

            ConnectionClosing(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_CONNECTION_CLOSING, CONNECTION) && "Invalid packet header for ConnectionClosing");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) override;

            PacketHeader Header;
            ClosingReason Reason = PACKET_CORRUPT;
            std::vector<PacketInfo> Packets;
            time_t Now = 0;
        };

        class Pong final : public ServerPacket
        {
        public:
            Pong() : ServerPacket(PacketHeader(SMSG_PONG, CONNECTION))
            {
            }

            void Write() override { }
            std::string ToString() const override;
        };
    }
}

#endif // ConnectionPackets_h__
