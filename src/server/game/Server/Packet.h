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

#ifndef PacketBaseWorld_h__
#define PacketBaseWorld_h__

#include "WorldPacket.h"

namespace WorldPackets
{
    class Packet
    {
    public:
        Packet(WorldPacket&& worldPacket) : _worldPacket(std::move(worldPacket)) { }

        virtual ~Packet() = default;

        Packet(Packet const& right) = delete;
        Packet& operator=(Packet const& right) = delete;

        virtual WorldPacket const* Write() = 0;
        virtual void Read() = 0;

        WorldPacket const* GetRawPacket() const { return &_worldPacket; }
        size_t GetSize() const { return _worldPacket.size(); }
        ConnectionType GetConnection() const { return _worldPacket.GetConnection(); }

    protected:
        WorldPacket _worldPacket;
    };

    class ServerPacket : public Packet
    {
    public:
        ServerPacket(OpcodeServer opcode, size_t initialSize = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : Packet(WorldPacket(opcode, initialSize, connection)) { }

        void Read() override final { ASSERT(!"Read not implemented for server packets."); }

        void Clear() { _worldPacket.clear(); }
        WorldPacket&& Move() { return std::move(_worldPacket); }

        OpcodeServer GetOpcode() const { return OpcodeServer(_worldPacket.GetOpcode()); }
    };

    class ClientPacket : public Packet
    {
    public:
        ClientPacket(WorldPacket&& packet) : Packet(std::move(packet)) { }
        ClientPacket(OpcodeClient expectedOpcode, WorldPacket&& packet) : Packet(std::move(packet)) { ASSERT(GetOpcode() == expectedOpcode); }

        WorldPacket const* Write() override final
        {
            ASSERT(!"Write not allowed for client packets.");
            // Shut up some compilers
            return nullptr;
        }

        OpcodeClient GetOpcode() const { return OpcodeClient(_worldPacket.GetOpcode()); }
    };
}

#endif // PacketBaseWorld_h__
