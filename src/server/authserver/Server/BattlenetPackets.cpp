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

#include "BattlenetPackets.h"
#include "Common.h"
#include "Util.h"
#include <limits>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <boost/asio/ip/address.hpp>

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

void Battlenet::AuthChallenge::Read()
{
    Program = _stream.ReadFourCC();
    Platform = _stream.ReadFourCC();
    Locale = _stream.ReadFourCC();

    Components.resize(_stream.Read<uint32>(6));
    for (size_t i = 0; i < Components.size(); ++i)
    {
        Component& component = Components[i];
        component.Program = _stream.ReadFourCC();
        component.Platform = _stream.ReadFourCC();
        component.Build = _stream.Read<uint32>(32);
    }

    if (_stream.Read<uint32>(1))
        Login = _stream.ReadString(9, 3);
}

std::string Battlenet::AuthChallenge::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::AuthChallenge Program: " << Program << ", Platform: " << Platform << ", Locale: " << Locale;
    for (Component const& component : Components)
        stream << std::endl << "Battlenet::Component Program: " << component.Program << ", Platform: " << component.Platform << ", Build: " << component.Build;

    if (!Login.empty())
        stream << std::endl << "Battlenet::AuthChallenge Login: " << Login;

    return stream.str();
}

void Battlenet::AuthResumeInfo::Read()
{
    Program = _stream.ReadFourCC();
    Platform = _stream.ReadFourCC();
    Locale = _stream.ReadFourCC();

    Components.resize(_stream.Read<uint32>(6));
    for (size_t i = 0; i < Components.size(); ++i)
    {
        Component& component = Components[i];
        component.Program = _stream.ReadFourCC();
        component.Platform = _stream.ReadFourCC();
        component.Build = _stream.Read<uint32>(32);
    }

    Login = _stream.ReadString(9, 3);
    Region = _stream.Read<uint8>(8);
    GameAccountName = _stream.ReadString(5, 1);
}

std::string Battlenet::AuthResumeInfo::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::AuthReconnect Program: " << Program << ", Platform: " << Platform << ", Locale: " << Locale;
    for (Component const& component : Components)
        stream << std::endl << "Battlenet::Component Program: " << component.Program << ", Platform: " << component.Platform << ", Build: " << component.Build;

    stream << std::endl << "Battlenet::AuthReconnect Login: " << Login;
    stream << std::endl << "Battlenet::AuthReconnect Region: " << uint32(Region);
    stream << std::endl << "Battlenet::AuthReconnect GameAccountName: " << GameAccountName;

    return stream.str();
}

Battlenet::ProofRequest::~ProofRequest()
{
    for (size_t i = 0; i < Modules.size(); ++i)
        delete Modules[i];
}

void Battlenet::ProofRequest::Write()
{
    _stream.Write(Modules.size(), 3);
    for (ModuleInfo const* info : Modules)
    {
        _stream.WriteBytes(info->Type.c_str(), 4);
        _stream.WriteFourCC(info->Region);
        _stream.WriteBytes(info->ModuleId, 32);
        _stream.Write(info->DataSize, 10);
        _stream.WriteBytes(info->Data, info->DataSize);
    }
}

std::string Battlenet::ProofRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::ProofRequest modules " << Modules.size();
    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", DataSize " << module->DataSize << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}

Battlenet::ProofResponse::~ProofResponse()
{
    for (size_t i = 0; i < Modules.size(); ++i)
        delete Modules[i];
}

void Battlenet::ProofResponse::Read()
{
    Modules.resize(_stream.Read<uint32>(3));
    for (size_t i = 0; i < Modules.size(); ++i)
    {
        BitStream*& dataStream = Modules[i];
        dataStream = new BitStream(_stream.Read<uint32>(10));
        memcpy(dataStream->GetBuffer(), _stream.ReadBytes(dataStream->GetSize()).get(), dataStream->GetSize());
    }
}

std::string Battlenet::ProofResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::ProofResponse Modules " << Modules.size();
    for (BitStream* module : Modules)
    {
        std::string hexStr = ByteArrayToHexStr(module->GetBuffer(), module->GetSize());
        stream << std::endl << "Battlenet::ProofResponse::ModuleData Size: " << module->GetSize() << ", Data: " << hexStr;
    }

    return stream.str();
}

Battlenet::AuthComplete::~AuthComplete()
{
    for (ModuleInfo* m : Modules)
        delete m;
}

void Battlenet::AuthComplete::Write()
{
    _stream.Write(Result != 0, 1);
    if (Result == 0)
    {
        _stream.Write(Modules.size(), 3);
        for (size_t i = 0; i < Modules.size(); ++i)
        {
            ModuleInfo* info = Modules[i];
            _stream.WriteBytes(info->Type.c_str(), 4);
            _stream.WriteFourCC(info->Region);
            _stream.WriteBytes(info->ModuleId, 32);
            _stream.Write(info->DataSize, 10);
            _stream.WriteBytes(info->Data, info->DataSize);
        }

        _stream.Write(PingTimeout + std::numeric_limits<int32>::min(), 32);
        _stream.Write(1, 1);
        // if written == 1
        {
            _stream.Write(1, 1);
            // if written == 1
            {
                _stream.Write(Threshold, 32);
                _stream.Write(Rate, 32);
            }
        }

        _stream.WriteString(FirstName, 8); // First name
        _stream.WriteString(LastName, 8); // Last name - not set for WoW

        _stream.Write(AccountId, 32);
        _stream.Write(Region, 8);
        _stream.Write(0, 64);

        _stream.Write(GameAccountRegion, 8);
        _stream.WriteString(GameAccountName, 5, -1);
        _stream.Write(GameAccountFlags, 64);

        _stream.Write(0, 32);
    }
    else
    {
        _stream.Write(!Modules.empty(), 1);
        if (!Modules.empty())
        {
            ModuleInfo* info = Modules[0];
            _stream.WriteBytes(info->Type.c_str(), 4);
            _stream.WriteFourCC(info->Region);
            _stream.WriteBytes(info->ModuleId, 32);
        }

        _stream.Write(ErrorType, 2);
        if (ErrorType == 1)
        {
            _stream.Write(Result, 16);
            _stream.Write(0x80000000, 32);
        }
    }
}

std::string Battlenet::AuthComplete::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::AuthComplete AuthResult " << Result << " PingTimeout " << PingTimeout << " Threshold " << Threshold << " Rate " << Rate
        << " FirstName " << FirstName << " LastName " << LastName << " AccountId " << AccountId << " Region " << uint32(Region) << " GameAccountName " << GameAccountName
        << " GameAccountFlags " << GameAccountFlags << " Modules " << Modules.size();

    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", DataSize " << module->DataSize << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}

void Battlenet::AuthComplete::SetAuthResult(AuthResult result)
{
    ErrorType = result != AUTH_OK ? 1 : 0;
    Result = result;
}

Battlenet::AuthResume::~AuthResume()
{
    for (ModuleInfo* m : Modules)
        delete m;
}

void Battlenet::AuthResume::Write()
{
    _stream.Write(Result != 0, 1);
    if (Result == 0)
    {
        _stream.Write(Modules.size(), 3);
        for (size_t i = 0; i < Modules.size(); ++i)
        {
            ModuleInfo* info = Modules[i];
            _stream.WriteBytes(info->Type.c_str(), 4);
            _stream.WriteFourCC(info->Region);
            _stream.WriteBytes(info->ModuleId, 32);
            _stream.Write(info->DataSize, 10);
            _stream.WriteBytes(info->Data, info->DataSize);
        }

        _stream.Write(PingTimeout + std::numeric_limits<int32>::min(), 32);
        _stream.Write(1, 1);
        // if written == 1
        {
            _stream.Write(1, 1);
            // if written == 1
            {
                _stream.Write(Threshold, 32);
                _stream.Write(Rate, 32);
            }
        }
    }
    else
    {
        _stream.Write(!Modules.empty(), 1);
        if (!Modules.empty())
        {
            ModuleInfo* info = Modules[0];
            _stream.WriteBytes(info->Type.c_str(), 4);
            _stream.WriteFourCC(info->Region);
            _stream.WriteBytes(info->ModuleId, 32);
        }

        _stream.Write(ErrorType, 2);
        if (ErrorType == 1)
        {
            _stream.Write(Result, 16);
            _stream.Write(0x80000000, 32);
        }
    }
}

std::string Battlenet::AuthResume::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::AuthResume AuthResult " << Result << " PingTimeout " << PingTimeout << " Threshold " << Threshold << " Rate " << Rate << " Modules " << Modules.size();
    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", DataSize " << module->DataSize << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}

void Battlenet::AuthResume::SetAuthResult(AuthResult result)
{
    ErrorType = result != AUTH_OK ? 1 : 0;
    Result = result;
}

Battlenet::RealmCharacterCounts::~RealmCharacterCounts()
{
    for (ServerPacket* realmData : RealmData)
        delete realmData;
}

void Battlenet::RealmCharacterCounts::Write()
{
    _stream.Write(false, 1);    // failure
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

std::string Battlenet::RealmCharacterCounts::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::RealmCharacterCounts Realms " << CharacterCounts.size();

    for (CharacterCountEntry const& entry : CharacterCounts)
        stream << std::endl << "Region " << uint32(entry.Realm.Region) << " Battlegroup " << uint32(entry.Realm.Region) << " Index " << entry.Realm.Index << " Characters " << entry.CharacterCount;

    for (ServerPacket* realmData : RealmData)
        stream << std::endl << realmData->ToString();

    return stream.str().c_str();
}

void Battlenet::RealmUpdate::Write()
{
    _stream.Write(true, 1);     // Success
    _stream.Write(Type + -std::numeric_limits<int32>::min(), 32);
    _stream.WriteFloat(Population);
    _stream.Write(Flags, 8);
    _stream.Write(Lock, 8);
    _stream.Write(Timezone, 32);
    _stream.Write(!Version.empty(), 1);
    if (!Version.empty())
    {
        _stream.WriteString(Version, 5);
        _stream.Write(Build, 32);

        boost::asio::ip::address_v4::bytes_type ip = Address.address().to_v4().to_bytes();
        uint16 port = Address.port();

        EndianConvertReverse(ip);
        EndianConvertReverse(port);

        _stream.WriteBytes(ip.data(), 4);
        _stream.WriteBytes(&port, 2);
    }

    _stream.WriteString(Name, 10);

    _stream.Write(Battlegroup, 8);
    _stream.Write(Index, 32);
    _stream.Write(Region, 8);
}

std::string Battlenet::RealmUpdate::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::RealmUpdate Timezone " << Timezone << " Population " << Population << " Lock " << uint32(Lock) << " Type " << Type << " Name " << Name
        << " Flags " << uint32(Flags) << " Region " << uint32(Region) << " Battlegroup " << uint32(Battlegroup) << " Index " << Index;

    if (!Version.empty())
        stream << " Version " << Version;

    return stream.str().c_str();
}

void Battlenet::RealmJoinRequest::Read()
{
    Realm.Battlegroup = _stream.Read<uint8>(8);
    Realm.Index = _stream.Read<uint32>(32);
    Realm.Region = _stream.Read<uint8>(8);
    ClientSeed = _stream.Read<uint32>(32);
}

std::string Battlenet::RealmJoinRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::RealmJoinRequest ClientSeed " << ClientSeed << " Region " << uint32(Realm.Region) << " Battlegroup " << uint32(Realm.Battlegroup) << " Index " << Realm.Index;
    return stream.str().c_str();
}

void Battlenet::RealmJoinResult::Write()
{
    _stream.Write(0, 27);
    _stream.Write(0, 1);    // Fail
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

std::string Battlenet::RealmJoinResult::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::RealmJoinResult ServerSeed " << ServerSeed << " IPv4 Addresses " << IPv4.size() << " IPv6 Addresses " << IPv6.size();
    for (tcp::endpoint const& addr : IPv4)
        stream << std::endl << "Battlenet::RealmJoinResult::Address " << boost::lexical_cast<std::string>(addr);

    for (tcp::endpoint const& addr : IPv6)
        stream << std::endl << "Battlenet::RealmJoinResult::Address " << boost::lexical_cast<std::string>(addr);

    return stream.str().c_str();
}
