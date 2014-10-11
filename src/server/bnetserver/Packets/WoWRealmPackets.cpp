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

#include "WoWRealmPackets.h"
#include "Session.h"
#include <boost/lexical_cast.hpp>
#include <boost/asio/ip/address.hpp>

std::string Battlenet::WoWRealm::ListSubscribeRequest::ToString() const
{
    return "Battlenet::WoWRealm::ListSubscribeRequest";
}

void Battlenet::WoWRealm::ListSubscribeRequest::CallHandler(Session* session)
{
    session->HandleListSubscribeRequest(*this);
}

std::string Battlenet::WoWRealm::ListUnsubscribe::ToString() const
{
    return "Battlenet::WoWRealm::ListUnsubscribe";
}

void Battlenet::WoWRealm::ListUnsubscribe::CallHandler(Session* session)
{
    session->HandleListUnsubscribe(*this);
}

Battlenet::WoWRealm::ListSubscribeResponse::~ListSubscribeResponse()
{
    for (ServerPacket* realmData : RealmData)
        delete realmData;
}

void Battlenet::WoWRealm::ListSubscribeResponse::Write()
{
    _stream.Write(Response, 1);
    if (Response == SUCCESS)
    {
        _stream.Write(CharacterCounts.size(), 7);
        for (CharacterCountEntry const& entry : CharacterCounts)
        {
            _stream.Write(entry.Realm.Battlegroup, 8);
            _stream.Write(entry.Realm.Index, 32);
            _stream.Write(entry.Realm.Region, 8);
            _stream.Write(entry.CharacterCount, 16);
        }

        for (ServerPacket* realmData : RealmData)
        {
            realmData->Write();
            _stream.WriteBytes(realmData->GetData(), realmData->GetSize());
        }
    }
    else
        _stream.Write(ResponseCode, 8);
}

std::string Battlenet::WoWRealm::ListSubscribeResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListSubscribeResponse";

    if (Response == SUCCESS)
    {
        stream << " Realms " << CharacterCounts.size();

        for (CharacterCountEntry const& entry : CharacterCounts)
            stream << std::endl << "Region " << uint32(entry.Realm.Region) << " Battlegroup " << uint32(entry.Realm.Region) << " Index " << entry.Realm.Index << " Characters " << entry.CharacterCount;

        for (ServerPacket* realmData : RealmData)
            stream << std::endl << realmData->ToString();
    }
    else
        stream << " Failure";

    return stream.str().c_str();
}

void Battlenet::WoWRealm::ListUpdate::Write()
{
    _stream.Write(UpdateState, 1);
    if (UpdateState == UPDATE)
    {
        _stream.Write(Type + -std::numeric_limits<int32>::min(), 32);
        _stream.WriteFloat(Population);
        _stream.Write(Flags, 8);
        _stream.Write(Lock, 8);
        _stream.Write(Timezone, 32);
        _stream.Write(!Version.empty(), 1);
        if (!Version.empty())
        {
            _stream.WriteString(Version, 5);
            _stream.Write(Id.Build, 32);

            boost::asio::ip::address_v4::bytes_type ip = Address.address().to_v4().to_bytes();
            uint16 port = Address.port();

            EndianConvertReverse(ip);
            EndianConvertReverse(port);

            _stream.WriteBytes(ip.data(), 4);
            _stream.WriteBytes(&port, 2);
        }

        _stream.WriteString(Name, 10);
    }

    _stream.Write(Id.Battlegroup, 8);
    _stream.Write(Id.Index, 32);
    _stream.Write(Id.Region, 8);
}

std::string Battlenet::WoWRealm::ListUpdate::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::ListUpdate Timezone " << Timezone << " Population " << Population << " Lock " << uint32(Lock) << " Type " << Type << " Name " << Name
        << " Flags " << uint32(Flags) << " Region " << uint32(Id.Region) << " Battlegroup " << uint32(Id.Battlegroup) << " Index " << Id.Index;

    if (!Version.empty())
        stream << " Version " << Version;

    return stream.str().c_str();
}

void Battlenet::WoWRealm::JoinRequestV2::Read()
{
    Realm.Battlegroup = _stream.Read<uint8>(8);
    Realm.Index = _stream.Read<uint32>(32);
    Realm.Region = _stream.Read<uint8>(8);
    ClientSeed = _stream.Read<uint32>(32);
}

std::string Battlenet::WoWRealm::JoinRequestV2::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::JoinRequestV2 ClientSeed " << ClientSeed << " Region " << uint32(Realm.Region) << " Battlegroup " << uint32(Realm.Battlegroup) << " Index " << Realm.Index;
    return stream.str().c_str();
}

void Battlenet::WoWRealm::JoinRequestV2::CallHandler(Session* session)
{
    session->HandleJoinRequestV2(*this);
}

void Battlenet::WoWRealm::JoinResponseV2::Write()
{
    _stream.Write(0, 27);
    _stream.Write(Response, 1);
    if (Response == SUCCESS)
    {
        _stream.Write(ServerSeed, 32);
        _stream.Write(IPv6.size(), 5);
        for (tcp::endpoint const& addr : IPv6)
        {
            boost::asio::ip::address_v6::bytes_type ip = addr.address().to_v6().to_bytes();
            uint16 port = addr.port();

            EndianConvertReverse(port);

            _stream.WriteBytes(ip.data(), 16);
            _stream.WriteBytes(&port, 2);
        }

        _stream.Write(IPv4.size(), 5);
        for (tcp::endpoint const& addr : IPv4)
        {
            boost::asio::ip::address_v4::bytes_type ip = addr.address().to_v4().to_bytes();
            uint16 port = addr.port();

            EndianConvertReverse(port);

            _stream.WriteBytes(ip.data(), 4);
            _stream.WriteBytes(&port, 2);
        }
    }
    else
        _stream.Write(ResponseCode, 8);
}

std::string Battlenet::WoWRealm::JoinResponseV2::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::WoWRealm::JoinResponseV2";
    if (Response == SUCCESS)
    {
        stream << " ServerSeed " << ServerSeed << " IPv4 Addresses " << IPv4.size() << " IPv6 Addresses " << IPv6.size();
        for (tcp::endpoint const& addr : IPv4)
            stream << std::endl << "Battlenet::WoWRealm::JoinResponseV2::Address " << boost::lexical_cast<std::string>(addr);

        for (tcp::endpoint const& addr : IPv6)
            stream << std::endl << "Battlenet::WoWRealm::JoinResponseV2::Address " << boost::lexical_cast<std::string>(addr);
    }
    else
        stream << " Failure";

    return stream.str().c_str();
}
