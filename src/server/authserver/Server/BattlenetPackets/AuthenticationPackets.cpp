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

#include "AuthenticationPackets.h"
#include "BattlenetSession.h"
#include "Util.h"

void Battlenet::Authentication::LogonRequest::Read()
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

std::string Battlenet::Authentication::LogonRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::LogonRequest Program: " << Program << ", Platform: " << Platform << ", Locale: " << Locale;
    for (Component const& component : Components)
        stream << std::endl << "Battlenet::Component Program: " << component.Program << ", Platform: " << component.Platform << ", Build: " << component.Build;

    if (!Login.empty())
        stream << std::endl << "Battlenet::Authentication::LogonRequest Login: " << Login;

    return stream.str();
}

void Battlenet::Authentication::LogonRequest::CallHandler(Session* session) const
{
    session->HandleLogonRequest(*this);
}

void Battlenet::Authentication::ResumeRequest::Read()
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

std::string Battlenet::Authentication::ResumeRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ResumeRequest Program: " << Program << ", Platform: " << Platform << ", Locale: " << Locale;
    for (Component const& component : Components)
        stream << std::endl << "Battlenet::Component Program: " << component.Program << ", Platform: " << component.Platform << ", Build: " << component.Build;

    stream << std::endl << "Login: " << Login;
    stream << std::endl << "Region: " << uint32(Region);
    stream << std::endl << "GameAccountName: " << GameAccountName;

    return stream.str();
}

void Battlenet::Authentication::ResumeRequest::CallHandler(Session* session) const
{
    session->HandleResumeRequest(*this);
}

Battlenet::Authentication::ProofRequest::~ProofRequest()
{
    for (size_t i = 0; i < Modules.size(); ++i)
        delete Modules[i];
}

void Battlenet::Authentication::ProofRequest::Write()
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

std::string Battlenet::Authentication::ProofRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ProofRequest modules " << Modules.size();
    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", DataSize " << module->DataSize << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}

Battlenet::Authentication::ProofResponse::~ProofResponse()
{
    for (size_t i = 0; i < Modules.size(); ++i)
        delete Modules[i];
}

void Battlenet::Authentication::ProofResponse::Read()
{
    Modules.resize(_stream.Read<uint32>(3));
    for (size_t i = 0; i < Modules.size(); ++i)
    {
        BitStream*& dataStream = Modules[i];
        dataStream = new BitStream(_stream.Read<uint32>(10));
        memcpy(dataStream->GetBuffer(), _stream.ReadBytes(dataStream->GetSize()).get(), dataStream->GetSize());
    }
}

std::string Battlenet::Authentication::ProofResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ProofResponse Modules " << Modules.size();
    for (BitStream* module : Modules)
    {
        std::string hexStr = ByteArrayToHexStr(module->GetBuffer(), module->GetSize());
        stream << std::endl << "Battlenet::Authentication::ProofResponse::ModuleData Size: " << module->GetSize() << ", Data: " << hexStr;
    }

    return stream.str();
}

void Battlenet::Authentication::ProofResponse::CallHandler(Session* session) const
{
    session->HandleProofResponse(*this);
}

Battlenet::Authentication::LogonResponse::~LogonResponse()
{
    for (ModuleInfo* m : Modules)
        delete m;
}

void Battlenet::Authentication::LogonResponse::Write()
{
    _stream.Write(Result.ResultValue != ResponseFailure::UPDATE, 1);
    if (Result.ResultValue == ResponseFailure::UPDATE)
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
        _stream.Write(1, 1);    // RegulatorRules != NULL (not a pointer for us, always write)
        // if written == 1
        {
            _stream.Write(RegulatorRules.Type == Regulator::LEAKY_BUCKET, 1);
            if (RegulatorRules.Type == Regulator::LEAKY_BUCKET)
            {
                _stream.Write(RegulatorRules.Threshold, 32);
                _stream.Write(RegulatorRules.Rate, 32);
            }
        }

        _stream.WriteString(FirstName, 8); // First name
        _stream.WriteString(LastName, 8); // Last name - not set for WoW

        _stream.Write(AccountId, 32);
        _stream.Write(Region, 8);
        _stream.Write(Flags, 64);

        _stream.Write(GameAccountRegion, 8);
        _stream.WriteString(GameAccountName, 5, -1);
        _stream.Write(GameAccountFlags, 64);

        _stream.Write(FailedLogins, 32);
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

        _stream.Write(Result.ResultValue, 2);
        if (Result.ResultValue == ResponseFailure::FAILURE)
        {
            _stream.Write(Result.Error, 16);
            _stream.Write(Result.Wait + std::numeric_limits<int32>::min(), 32);
        }
    }
}

std::string Battlenet::Authentication::LogonResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::LogonResponse AuthResult " << Result.Error << " PingTimeout " << PingTimeout
        << " RegulatorRules.Threshold " << RegulatorRules.Threshold << " RegulatorRules.Rate " << RegulatorRules.Rate
        << " FirstName " << FirstName << " LastName " << LastName << " AccountId " << AccountId << " Region " << uint32(Region) << " GameAccountName " << GameAccountName
        << " GameAccountFlags " << GameAccountFlags << " FailedLogins " << FailedLogins << " Modules " << Modules.size();

    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", DataSize " << module->DataSize << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}

void Battlenet::Authentication::LogonResponse::SetAuthResult(AuthResult result)
{
    Result.ResultValue = result != AUTH_OK ? ResponseFailure::FAILURE : ResponseFailure::UPDATE;
    Result.Error = result;
}

Battlenet::Authentication::ResumeResponse::~ResumeResponse()
{
    for (ModuleInfo* m : Modules)
        delete m;
}

void Battlenet::Authentication::ResumeResponse::Write()
{
    _stream.Write(Result.ResultValue != ResponseFailure::UPDATE, 1);
    if (Result.ResultValue == ResponseFailure::UPDATE)
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
        _stream.Write(1, 1);    // RegulatorRules != NULL (not a pointer for us, always write)
        // if written == 1
        {
            _stream.Write(RegulatorRules.Type == Regulator::LEAKY_BUCKET, 1);
            if (RegulatorRules.Type == Regulator::LEAKY_BUCKET)
            {
                _stream.Write(RegulatorRules.Threshold, 32);
                _stream.Write(RegulatorRules.Rate, 32);
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

        _stream.Write(Result.ResultValue, 2);
        if (Result.ResultValue == ResponseFailure::FAILURE)
        {
            _stream.Write(Result.Error, 16);
            _stream.Write(Result.Wait + std::numeric_limits<int32>::min(), 32);
        }
    }
}

std::string Battlenet::Authentication::ResumeResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ResumeResponse AuthResult " << Result.Error << " PingTimeout " << PingTimeout
        << " RegulatorRules.Threshold " << RegulatorRules.Threshold << " RegulatorRules.Rate " << RegulatorRules.Rate
        << " Modules " << Modules.size();

    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", DataSize " << module->DataSize << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}

void Battlenet::Authentication::ResumeResponse::SetAuthResult(AuthResult result)
{
    Result.ResultValue = result != AUTH_OK ? ResponseFailure::FAILURE : ResponseFailure::UPDATE;
    Result.Error = result;
}
