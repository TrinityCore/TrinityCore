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
    Error = _stream.Read<uint16>(16);
    Timeout = _stream.Read<uint32>(32);
}

std::string Battlenet::Connection::DisconnectRequest::ToString() const
{
    std::ostringstream str;
    str << "Battlenet::Connection::DisconnectRequest" << std::endl;
    APPEND_FIELD(str, Error);
    APPEND_FIELD(str, Timeout);
    return str.str();
}

void Battlenet::Connection::ConnectionClosing::Read()
{
    Packets.resize(_stream.Read<uint8>(6));
    for (size_t i = 0; i < Packets.size(); ++i)
    {
        PacketInfo& info = Packets[i];
        info.Command = _stream.ReadFourCC();
        info.Time = _stream.Read<uint32>(32);
        info.Size = _stream.Read<uint32>(16);
        info.Layer = _stream.ReadFourCC();
        info.Offset = _stream.Read<uint32>(16);
    }

    Reason = _stream.Read<ClosingReason>(4);
    _stream.ReadBytes(_stream.Read<uint8>(8)); // BadData

    if (_stream.Read<bool>(1))  // HasHeader
    {
        Header.Command = _stream.Read<uint32>(6);
        if (_stream.Read<bool>(1))
            Header.Channel = _stream.Read<int32>(4);
    }

    Now = _stream.Read<time_t>(32);
}

std::string Battlenet::Connection::ConnectionClosing::PacketInfo::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Connection::ConnectionClosing::PacketInfo" << std::endl;
    APPEND_FIELD(stream, Layer);
    APPEND_FIELD(stream, Command);
    APPEND_FIELD(stream, Offset);
    APPEND_FIELD(stream, Size);
    APPEND_FIELD(stream, Time);
    return stream.str();
}

std::string Battlenet::Connection::ConnectionClosing::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Connection::ConnectionClosing" << std::endl;
    APPEND_FIELD(stream, Header);
    APPEND_FIELD(stream, Reason);
    APPEND_FIELD(stream, Packets);
    APPEND_FIELD(stream, Now);
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
