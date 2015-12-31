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

#include "WoWRealmPackets.h"
#include "Session.h"
#include <boost/lexical_cast.hpp>
#include <boost/asio/ip/address.hpp>

void Battlenet::WoWRealm::ListSubscribeRequest::CallHandler(Session* session)
{
    session->HandleListSubscribeRequest(*this);
}

void Battlenet::WoWRealm::ListUnsubscribe::CallHandler(Session* session)
{
    session->HandleListUnsubscribe(*this);
}

void Battlenet::WoWRealm::JoinRequestV2::Read()
{
    ClientSalt = _stream.Read<uint32>(32);
    _stream.ReadSkip(20);
    Id.Region = _stream.Read<uint8>(8);
    _stream.ReadSkip(12);
    Id.Site = _stream.Read<uint8>(8);
    Id.Realm = _stream.Read<uint32>(32);
}

std::string Battlenet::WoWRealm::JoinRequestV2::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::JoinRequestV2" << std::endl;
    APPEND_FIELD(stream, Id);
    APPEND_FIELD(stream, ClientSalt);
    return stream.str();
}

void Battlenet::WoWRealm::JoinRequestV2::CallHandler(Session* session)
{
    session->HandleJoinRequestV2(*this);
}

void Battlenet::WoWRealm::ListSubscribeResponse::Write()
{
    _stream.Write(Type, 1);
    if (Type == SUCCESS)
    {
        _stream.Write(ToonCounts.size(), 7);
        for (ToonCountEntry const& entry : ToonCounts)
        {
            _stream.Write(entry.Realm.Region, 8);
            _stream.WriteSkip(12);
            _stream.Write(entry.Realm.Site, 8);
            _stream.Write(entry.Realm.Realm, 32);
            _stream.Write(entry.Count, 16);
        }
    }
    else
        _stream.Write(Failure, 8);
}

std::string Battlenet::WoWRealm::ListSubscribeResponse::ToonCountEntry::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListSubscribeResponse::ToonCountEntry" << std::endl;
    APPEND_FIELD(stream, Realm);
    APPEND_FIELD(stream, Count);
    return stream.str();
}

std::string Battlenet::WoWRealm::ListSubscribeResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListSubscribeResponse" << std::endl;

    if (Type == SUCCESS)
        APPEND_FIELD(stream, ToonCounts);
    else
        APPEND_FIELD(stream, Failure);

    return stream.str();
}

void Battlenet::WoWRealm::ListUpdate::Write()
{
    _stream.Write(State.Type, 1);
    if (State.Type == StateType::UPDATE)
    {
        _stream.Write(State.Update.Category, 32);
        _stream.WriteFloat(State.Update.Population);
        _stream.Write(State.Update.StateFlags, 8);
        _stream.WriteSkip(19);
        _stream.Write(State.Update.Type + -std::numeric_limits<int32>::min(), 32);
        _stream.WriteString(State.Update.Name, 10);
        _stream.Write(State.Update.PrivilegedData.is_initialized(), 1);
        if (State.Update.PrivilegedData.is_initialized())
        {
            _stream.WriteString(State.Update.PrivilegedData->Version, 5);
            _stream.Write(State.Update.PrivilegedData->ConfigId, 32);

            boost::asio::ip::address_v4::bytes_type ip = State.Update.PrivilegedData->Address.address().to_v4().to_bytes();
            uint16 port = State.Update.PrivilegedData->Address.port();

            EndianConvertReverse(ip);
            EndianConvertReverse(port);

            _stream.WriteBytes(ip.data(), 4);
            _stream.WriteBytes(&port, 2);
        }

        _stream.Write(State.Update.InfoFlags, 8);
    }

    _stream.Write(Id.Region, 8);
    _stream.WriteSkip(12);
    _stream.Write(Id.Site, 8);
    _stream.Write(Id.Realm, 32);
}

std::string Battlenet::WoWRealm::ListUpdate::PrivilegedDataType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::RealmInfo::PrivilegedData" << std::endl;
    APPEND_FIELD(stream, Version);
    APPEND_FIELD(stream, ConfigId);
    APPEND_FIELD(stream, Address);
    return stream.str();
}

std::string Battlenet::WoWRealm::ListUpdate::StateType::UpdateType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListUpdate::State::Update" << std::endl;
    APPEND_FIELD(stream, InfoFlags);
    APPEND_FIELD(stream, Name);
    APPEND_FIELD(stream, Type);
    APPEND_FIELD(stream, Category);
    APPEND_FIELD(stream, StateFlags);
    APPEND_FIELD(stream, Population);
    APPEND_FIELD(stream, PrivilegedData);
    return stream.str();
}

std::string Battlenet::WoWRealm::ListUpdate::StateType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListUpdate::State" << std::endl;

    if (Type == UPDATE)
        APPEND_FIELD(stream, Update);
    else
        APPEND_FIELD(stream, Delete);

    return stream.str();
}

std::string Battlenet::WoWRealm::ListUpdate::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListUpdate" << std::endl;
    APPEND_FIELD(stream, Id);
    APPEND_FIELD(stream, State);
    return stream.str();
}

void Battlenet::WoWRealm::ToonReady::Write()
{
    _stream.Write(Name.Region, 8);
    _stream.WriteFourCC(Name.ProgramId);
    _stream.Write(Name.Realm, 32);
    _stream.WriteString(Name.Name, 7, -2);
    _stream.WriteSkip(21);
    _stream.Write(ProfileAddress.Id, 64);
    _stream.Write(ProfileAddress.Label, 32);
    _stream.Write(Handle.Id, 64);
    _stream.Write(Handle.Realm, 32);
    _stream.Write(Handle.Region, 8);
    _stream.WriteFourCC(Handle.ProgramId);
}

std::string Battlenet::WoWRealm::ToonReady::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ToonReady" << std::endl;
    APPEND_FIELD(stream, Name);
    APPEND_FIELD(stream, Handle);
    APPEND_FIELD(stream, ProfileAddress);
    return stream.str();
}

void Battlenet::WoWRealm::JoinResponseV2::Write()
{
    _stream.Write(Type, 1);
    if (Type == SUCCESS)
    {
        _stream.Write(Success.ServerSalt, 32);
        _stream.Write(Success.IPv4.size(), 5);
        for (tcp::endpoint const& addr : Success.IPv4)
        {
            boost::asio::ip::address_v4::bytes_type ip = addr.address().to_v4().to_bytes();
            uint16 port = addr.port();

            EndianConvertReverse(port);

            _stream.WriteBytes(ip.data(), 4);
            _stream.WriteBytes(&port, 2);
        }

        _stream.Write(Success.IPv6.size(), 5);
        for (tcp::endpoint const& addr : Success.IPv6)
        {
            boost::asio::ip::address_v6::bytes_type ip = addr.address().to_v6().to_bytes();
            uint16 port = addr.port();

            EndianConvertReverse(port);

            _stream.WriteBytes(ip.data(), 16);
            _stream.WriteBytes(&port, 2);
        }
    }
    else
        _stream.Write(Failure, 8);
}

std::string Battlenet::WoWRealm::JoinResponseV2::SuccessType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::JoinResponseV2::Success" << std::endl;
    APPEND_FIELD(stream, ServerSalt);
    APPEND_FIELD(stream, IPv4);
    APPEND_FIELD(stream, IPv6);
    return stream.str();
}

std::string Battlenet::WoWRealm::JoinResponseV2::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::JoinResponseV2" << std::endl;

    if (Type == SUCCESS)
        APPEND_FIELD(stream, Success);
    else
        APPEND_FIELD(stream, Failure);

    return stream.str();
}
