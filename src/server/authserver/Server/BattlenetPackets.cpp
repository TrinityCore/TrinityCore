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

    if (GetHeader().Opcode == CMSG_AUTH_CHALLENGE_NEW)
        _stream.FinishReading();
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
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", BlobSize " << module->DataSize;

    return stream.str();
}

Battlenet::ProofResponse::~ProofResponse()
{
    for (size_t i = 0; i < Modules.size(); ++i)
        delete[] Modules[i].Data;
}

void Battlenet::ProofResponse::Read()
{
    Modules.resize(_stream.Read<uint32>(3));
    for (size_t i = 0; i < Modules.size(); ++i)
    {
        ModuleData& data = Modules[i];
        data.Size = _stream.Read<uint32>(10);
        data.Data = _stream.ReadBytes(data.Size);
    }
}

std::string Battlenet::ProofResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::ProofResponse Modules " << Modules.size();
    for (ModuleData const& module : Modules)
    {
        std::string hexStr = ByteArrayToHexStr(module.Data, module.Size);
        stream << std::endl << "Battlenet::ProofResponse::ModuleData Size: " << module.Size << ", Data: " << hexStr;
    }

    return stream.str();
}

void Battlenet::AuthComplete::Write()
{
    _stream.Write(Result != 0, 1);
    if (Result == 0)
    {
        _stream.Write(Modules.size(), 3);
        for (size_t i = 0; i < Modules.size(); ++i)
        {
            ModuleInfo& info = Modules[i];
            _stream.WriteBytes(info.Type.c_str(), 4);
            _stream.WriteFourCC(info.Region);
            _stream.WriteBytes(info.ModuleId, 32);
            _stream.Write(info.DataSize, 10);
            _stream.WriteBytes(info.Data, info.DataSize);
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

        // todo more
    }
    else
    {
        _stream.Write(!Modules.empty(), 1);
        if (!Modules.empty())
        {
            ModuleInfo& info = Modules[0];
            _stream.WriteBytes(info.Type.c_str(), 4);
            _stream.WriteFourCC(info.Region);
            _stream.WriteBytes(info.ModuleId, 32);
            _stream.Write(info.DataSize, 10);
            _stream.WriteBytes(info.Data, info.DataSize);
        }

        _stream.Write(ErrorType, 2);
        if (ErrorType == 1)
        {
            _stream.Write<uint16>(Result, 16);
            _stream.Write(0, 32);
        }
    }
}

std::string Battlenet::AuthComplete::ToString() const
{
    return "Battlenet::AuthComplete";
}

void Battlenet::AuthComplete::SetAuthResult(AuthResult result)
{
    ErrorType = result != AUTH_OK ? 1 : 0;
    Result = result;
}
