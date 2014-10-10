/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PacketsBase_h__
#define PacketsBase_h__

#include "AuthCodes.h"
#include "BitStream.h"
#include "Define.h"
#include "Errors.h"
#include <string>
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;

namespace Battlenet
{
    class BitStream;
    class Session;

    enum Channel
    {
        AUTHENTICATION  = 0,
        CONNECTION      = 1,
        WOWREALM        = 2,
        FRIENDS         = 3,
        PRESENCE        = 4,
        CHAT            = 5,
        SUPPORT         = 7,
        ACHIEVEMENT     = 8,
        CACHE           = 11,
        PROFILE         = 14
    };

    struct PacketHeader
    {
        PacketHeader(uint32 opcode, uint32 channel) : Opcode(opcode), Channel(channel) { }
        PacketHeader() : Opcode(0), Channel(AUTHENTICATION) { }

        uint32 Opcode;
        int32 Channel;

        bool operator<(PacketHeader const& right) const
        {
            if (Opcode < right.Opcode)
                return true;
            if (Opcode > right.Opcode)
                return false;

            return Channel < right.Channel;
        }

        bool operator==(PacketHeader const& right) const
        {
            return Opcode == right.Opcode && Channel == right.Channel;
        }

        std::string ToString() const;
    };

    class Packet
    {
    public:
        Packet(PacketHeader const& header, BitStream& stream) : _header(header), _stream(stream) { }
        virtual ~Packet() { }

        PacketHeader const& GetHeader() const { return _header; }

        virtual void Write() = 0;
        virtual void Read() = 0;

        virtual std::string ToString() const = 0;

    protected:
        PacketHeader _header;
        BitStream& _stream;

    private:
        Packet(Packet const& right);
        Packet& operator=(Packet const& right);
    };

    class ClientPacket : public Packet
    {
    public:
        ClientPacket(PacketHeader const& header, BitStream& stream) : Packet(header, stream) { }

        void Write() override final { ASSERT(!"Write not implemented for this packet."); }
        virtual void CallHandler(Session* session) const = 0;
    };

    class ServerPacket : public Packet
    {
    public:
        ServerPacket(PacketHeader const& header);
        ~ServerPacket();

        void Read() override final { ASSERT(!"Read not implemented for server packets."); }

        uint8* GetData() { return _stream.GetBuffer(); }
        uint8 const* GetData() const { return _stream.GetBuffer(); }
        size_t GetSize() const { return _stream.GetSize(); }
    };
}

#endif // PacketsBase_h__
