/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Session.h"
#include "ConnectionPackets.h"

std::string Battlenet::Connection::Ping::ToString() const
{
    return "Battlenet::Connection::Ping";
}

void Battlenet::Connection::Ping::CallHandler(Session* session)
{
    session->HandlePing(*this);
}

std::string Battlenet::Connection::EnableEncryption::ToString() const
{
    return "Battlenet::Connection::EnableEncryption";
}

void Battlenet::Connection::EnableEncryption::CallHandler(Session* session)
{
    session->HandleEnableEncryption(*this);
}

std::string Battlenet::Connection::LogoutRequest::ToString() const
{
    return "Battlenet::Connection::LogoutRequest";
}

void Battlenet::Connection::LogoutRequest::CallHandler(Session* session)
{
    session->HandleLogoutRequest(*this);
}

void Battlenet::Connection::DisconnectRequest::Read()
{
    Timeout = _stream.Read<uint16>(16);
    Tick = _stream.Read<uint32>(32);
}

std::string Battlenet::Connection::DisconnectRequest::ToString() const
{
    std::ostringstream str;
    str << "Battlenet::Connection::DisconnectRequest Timeout: " << Timeout << ", Tick: " << Tick;
    return str.str();
}

void Battlenet::Connection::ConnectionClosing::Read()
{
    Reason = _stream.Read<ClosingReason>(4);
    if (_stream.Read<bool>(1))  // HasHeader
    {
        Header.Opcode = _stream.Read<uint32>(6);
        if (_stream.Read<bool>(1))
            Header.Channel = _stream.Read<int32>(4);
    }

    Now = _stream.Read<time_t>(32);
    _stream.Read<uint32>(25);
    auto bytes = _stream.ReadBytes(_stream.Read<uint8>(8)); // BadData
    Packets.resize(_stream.Read<uint8>(6));
    for (size_t i = 0; i < Packets.size(); ++i)
    {
        PacketInfo& info = Packets[i];
        info.CommandName = _stream.ReadFourCC();
        info.LayerId = _stream.Read<uint32>(16);
        info.Channel = _stream.ReadFourCC();
        info.Timestamp = _stream.Read<uint32>(32);
        info.Size = _stream.Read<uint32>(16);
    }
}

std::string Battlenet::Connection::ConnectionClosing::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Connection::ConnectionClosing Reason: " << Reason << ", Now: " << Now << ", Packet history size: " << Packets.size();
    for (PacketInfo const& packet : Packets)
        stream << std::endl << "Battlenet::Connection::ConnectionClosing::PacketInfo LayerId: " << packet.LayerId
        << ", Channel: " << packet.Channel << ", CommandName: " << packet.CommandName << ", Size: " << packet.Size << ", Timestamp: " << packet.Timestamp;

    return stream.str();
}

void Battlenet::Connection::ConnectionClosing::CallHandler(Session* session)
{
    session->HandleConnectionClosing(*this);
}

std::string Battlenet::Connection::Pong::ToString() const
{
    return "Battlenet::Connection::Pong";
}
