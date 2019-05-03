/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "Packet.h"
#include "Errors.h"

WorldPackets::Packet::Packet(WorldPacket&& worldPacket) : _worldPacket(std::move(worldPacket))
{
}

WorldPackets::ServerPacket::ServerPacket(OpcodeServer opcode, size_t initialSize /*= 200*/) : Packet(WorldPacket(opcode, initialSize))
{
}

void WorldPackets::ServerPacket::Read()
{
    ASSERT(!"Read not implemented for server packets.");
}

WorldPackets::ClientPacket::ClientPacket(OpcodeClient expectedOpcode, WorldPacket&& packet) : Packet(std::move(packet))
{
    ASSERT(GetOpcode() == expectedOpcode);
}

WorldPackets::ClientPacket::ClientPacket(WorldPacket&& packet)
    : Packet(std::move(packet))
{
}

WorldPacket const* WorldPackets::ClientPacket::Write()
{
    ASSERT(!"Write not allowed for client packets.");
    // Shut up some compilers
    return nullptr;
}
