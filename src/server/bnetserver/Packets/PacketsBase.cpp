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

#include "Packets.h"
#include "Session.h"
#include <sstream>

std::string Battlenet::PacketHeader::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::PacketHeader opcode: " << Opcode << ", channel: " << Channel;
    return stream.str();
}

Battlenet::ServerPacket::ServerPacket(PacketHeader const& header) : Packet(header, *new BitStream())
{
    _stream.Write(header.Opcode, 6);
    _stream.Write(1, 1);
    _stream.Write(header.Channel, 4);
}

Battlenet::ServerPacket::~ServerPacket()
{
    delete &_stream;
}

void Battlenet::ClientPacket::CallHandler(Session* session)
{
    session->LogUnhandledPacket(*this);
    _handled = false;
}
