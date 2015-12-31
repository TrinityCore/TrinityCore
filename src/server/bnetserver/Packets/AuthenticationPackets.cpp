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

#include "AuthenticationPackets.h"
#include "Session.h"
#include "Util.h"

std::string Battlenet::Authentication::RequestCommon::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::RequestCommon" << std::endl;
    APPEND_FIELD(stream, Program);
    APPEND_FIELD(stream, Platform);
    APPEND_FIELD(stream, Locale);
    APPEND_FIELD(stream, Versions);
    return stream.str();
}

void Battlenet::Authentication::ResumeRequest::Read()
{
    Common.Program = _stream.ReadFourCC();
    Common.Platform = _stream.ReadFourCC();
    Common.Locale = _stream.ReadFourCC();

    Common.Versions.resize(_stream.Read<uint32>(6));
    for (size_t i = 0; i < Common.Versions.size(); ++i)
    {
        Version::Record& component = Common.Versions[i];
        component.ProgramId = _stream.ReadFourCC();
        component.Component = _stream.ReadFourCC();
        component.Version = _stream.Read<uint32>(32);
    }

    Account = _stream.ReadString(9, 3);
    GameAccountRegion = _stream.Read<uint8>(8);
    GameAccountName = _stream.ReadString(5, 1);
}

std::string Battlenet::Authentication::ResumeRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ResumeRequest" << std::endl;
    APPEND_FIELD(stream, Common);
    APPEND_FIELD(stream, Account);
    APPEND_FIELD(stream, GameAccountRegion);
    APPEND_FIELD(stream, GameAccountName);
    return stream.str();
}

void Battlenet::Authentication::ResumeRequest::CallHandler(Session* session)
{
    session->HandleResumeRequest(*this);
}

Battlenet::Authentication::ProofResponse::~ProofResponse()
{
    for (size_t i = 0; i < Response.size(); ++i)
        delete Response[i];
}

void Battlenet::Authentication::ProofResponse::Read()
{
    Response.resize(_stream.Read<uint32>(3));
    for (size_t i = 0; i < Response.size(); ++i)
    {
        BitStream*& dataStream = Response[i];
        dataStream = new BitStream(_stream.Read<uint32>(10));
        memcpy(dataStream->GetBuffer(), _stream.ReadBytes(dataStream->GetSize()).get(), dataStream->GetSize());
    }
}

std::string Battlenet::Authentication::ProofResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ProofRequest" << std::endl;
    APPEND_FIELD(stream, Response.size());
    return stream.str();
}

void Battlenet::Authentication::ProofResponse::CallHandler(Session* session)
{
    session->HandleProofResponse(*this);
}

void Battlenet::Authentication::LogonRequest3::Read()
{
    Common.Program = _stream.ReadFourCC();
    Common.Platform = _stream.ReadFourCC();
    Common.Locale = _stream.ReadFourCC();

    Common.Versions.resize(_stream.Read<uint32>(6));
    for (size_t i = 0; i < Common.Versions.size(); ++i)
    {
        Version::Record& component = Common.Versions[i];
        component.ProgramId = _stream.ReadFourCC();
        component.Component = _stream.ReadFourCC();
        component.Version = _stream.Read<uint32>(32);
    }

    if (_stream.Read<uint32>(1))
        Account = _stream.ReadString(9, 3);

    Compatibility = _stream.Read<uint64>(64);
}

std::string Battlenet::Authentication::LogonRequest3::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::LogonRequest3" << std::endl;
    APPEND_FIELD(stream, Common);
    APPEND_FIELD(stream, Account);
    APPEND_FIELD(stream, Compatibility);
    return stream.str();
}

void Battlenet::Authentication::LogonRequest3::CallHandler(Session* session)
{
    session->HandleLogonRequest(*this);
}

Battlenet::Authentication::LogonResponse::~LogonResponse()
{
    for (ModuleInfo* m : Result.Success.FinalRequest)
        delete m;
}

void Battlenet::Authentication::LogonResponse::Write()
{
    _stream.Write(Result.Type, 1);
    if (Result.Type == ResultType::SUCCESS)
    {
        _stream.Write(Result.Success.FinalRequest.size(), 3);
        for (size_t i = 0; i < Result.Success.FinalRequest.size(); ++i)
        {
            ModuleInfo* info = Result.Success.FinalRequest[i];
            _stream.WriteBytes(info->Handle.Type.c_str(), 4);
            _stream.WriteFourCC(info->Handle.Region);
            _stream.WriteBytes(info->Handle.ModuleId, 32);
            _stream.Write(info->DataSize, 10);
            _stream.WriteBytes(info->Data, info->DataSize);
        }

        _stream.Write(Result.Success.PingTimeout + std::numeric_limits<int32>::min(), 32);
        _stream.Write(Result.Success.RegulatorRules.is_initialized(), 1);
        if (Result.Success.RegulatorRules.is_initialized())
        {
            _stream.Write(Result.Success.RegulatorRules->Type == Regulator::LEAKY_BUCKET, 1);
            if (Result.Success.RegulatorRules->Type == Regulator::LEAKY_BUCKET)
            {
                _stream.Write(Result.Success.RegulatorRules->LeakyBucket.Threshold, 32);
                _stream.Write(Result.Success.RegulatorRules->LeakyBucket.Rate, 32);
            }
        }

        _stream.WriteString(Result.Success.FullName.GivenName, 8);
        _stream.WriteString(Result.Success.FullName.Surname, 8);
        _stream.Write(Result.Success.AccountId, 32);
        _stream.Write(Result.Success.Region, 8);
        _stream.Write(Result.Success.Flags, 64);
        _stream.Write(Result.Success.GameAccountRegion, 8);
        _stream.WriteString(Result.Success.GameAccountName, 5, -1);
        _stream.Write(Result.Success.GameAccountFlags, 64);
        _stream.Write(Result.Success.LogonFailures, 32);
    }
    else
    {
        _stream.Write(Result.Failure.Strings.is_initialized(), 1);
        if (Result.Failure.Strings.is_initialized())
        {
            _stream.WriteBytes(Result.Failure.Strings->Type.c_str(), 4);
            _stream.WriteFourCC(Result.Failure.Strings->Region);
            _stream.WriteBytes(Result.Failure.Strings->ModuleId, 32);
        }

        _stream.Write(Result.Failure.Result.Type, 2);
        if (Result.Failure.Result.Type == FailureType::FAILURE)
        {
            _stream.Write(Result.Failure.Result.Failure.Error, 16);
            _stream.Write(Result.Failure.Result.Failure.Wait + std::numeric_limits<int32>::min(), 32);
        }
    }

    _stream.Write(Raf.is_initialized(), 1);
    if (Raf.is_initialized())
    {
        _stream.Write(Raf->size(), 10);
        _stream.WriteBytes(Raf->data(), Raf->size());
    }
}

std::string Battlenet::Authentication::LogonResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::LogonResponse" << std::endl;
    APPEND_FIELD(stream, Result);
    APPEND_FIELD(stream, Raf);
    return stream.str();
}

std::string Battlenet::Authentication::FailureType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::FailureType" << std::endl;
    APPEND_FIELD(stream, Strings);
    APPEND_FIELD(stream, Result);
    return stream.str();
}

std::string Battlenet::Authentication::FailureType::ResultType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ResponseFailure::Result" << std::endl;
    switch (Type)
    {
        case UPDATE:
            APPEND_FIELD(stream, Update);
            break;
        case FAILURE:
            APPEND_FIELD(stream, Failure);
            break;
        case VERSION_CHECK_DISCONNECT:
            APPEND_FIELD(stream, VersionCheckDisconnect);
            break;
        default:
            break;
    }
    return stream.str();
}

std::string Battlenet::Authentication::FailureType::ResultType::UpdateType::ToString() const
{
    return "Battlenet::Authentication::ResponseFailure::Result::Update";
}

std::string Battlenet::Authentication::FailureType::ResultType::FailureType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ResponseFailure::Result::Failure" << std::endl;
    APPEND_FIELD(stream, Error);
    APPEND_FIELD(stream, Wait);
    return stream.str();
}

std::string Battlenet::Authentication::FailureType::ResultType::VersionCheckDisconnectType::ToString() const
{
    return "Battlenet::Authentication::ResponseFailure::Result::VersionCheckDisconnect";
}

std::string Battlenet::Authentication::Regulator::NoneType::ToString() const
{
    return "Battlenet::Regulator::None";
}

std::string Battlenet::Authentication::Regulator::LeakyBucketType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Regulator::LeakyBucket" << std::endl;
    APPEND_FIELD(stream, Threshold);
    APPEND_FIELD(stream, Rate);
    return stream.str();
}

std::string Battlenet::Authentication::Regulator::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Regulator" << std::endl;
    switch (Type)
    {
        case NONE:
            APPEND_FIELD(stream, None);
            break;
        case LEAKY_BUCKET:
            APPEND_FIELD(stream, LeakyBucket);
            break;
        default:
            break;
    }
    return stream.str();
}

std::string Battlenet::Authentication::LogonResponse::ResultType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::LogonResponse::Result" << std::endl;
    switch (Type)
    {
        case SUCCESS:
            APPEND_FIELD(stream, Success);
            break;
        case FAILURE:
            APPEND_FIELD(stream, Failure);
            break;
        default:
            break;
    }
    return stream.str();
}

std::string Battlenet::Authentication::LogonResponse::ResultType::SuccessType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::LogonResponse::Result::Success" << std::endl;
    APPEND_FIELD(stream, FinalRequest);
    APPEND_FIELD(stream, PingTimeout);
    APPEND_FIELD(stream, RegulatorRules);
    APPEND_FIELD(stream, FullName);
    APPEND_FIELD(stream, AccountId);
    APPEND_FIELD(stream, Region);
    APPEND_FIELD(stream, Flags);
    APPEND_FIELD(stream, GameAccountRegion);
    APPEND_FIELD(stream, GameAccountName);
    APPEND_FIELD(stream, GameAccountFlags);
    APPEND_FIELD(stream, LogonFailures);
    return stream.str();
}

void Battlenet::Authentication::LogonResponse::SetAuthResult(AuthResult result)
{
    Result.Type = result != AUTH_OK ? ResultType::FAILURE : ResultType::SUCCESS;
    Result.Failure.Result.Failure.Error = result;
}

Battlenet::Authentication::ResumeResponse::~ResumeResponse()
{
    for (ModuleInfo* m : Result.Success.FinalRequest)
        delete m;
}

void Battlenet::Authentication::ResumeResponse::Write()
{
    _stream.Write(Result.Type, 1);
    if (Result.Type == ResultType::SUCCESS)
    {
        _stream.Write(Result.Success.FinalRequest.size(), 3);
        for (size_t i = 0; i < Result.Success.FinalRequest.size(); ++i)
        {
            ModuleInfo* info = Result.Success.FinalRequest[i];
            _stream.WriteBytes(info->Handle.Type.c_str(), 4);
            _stream.WriteFourCC(info->Handle.Region);
            _stream.WriteBytes(info->Handle.ModuleId, 32);
            _stream.Write(info->DataSize, 10);
            _stream.WriteBytes(info->Data, info->DataSize);
        }

        _stream.Write(Result.Success.PingTimeout + std::numeric_limits<int32>::min(), 32);
        _stream.Write(Result.Success.RegulatorRules.is_initialized(), 1);
        if (Result.Success.RegulatorRules.is_initialized())
        {
            _stream.Write(Result.Success.RegulatorRules->Type == Regulator::LEAKY_BUCKET, 1);
            if (Result.Success.RegulatorRules->Type == Regulator::LEAKY_BUCKET)
            {
                _stream.Write(Result.Success.RegulatorRules->LeakyBucket.Threshold, 32);
                _stream.Write(Result.Success.RegulatorRules->LeakyBucket.Rate, 32);
            }
        }
    }
    else
    {
        _stream.Write(Result.Failure.Strings.is_initialized(), 1);
        if (Result.Failure.Strings.is_initialized())
        {
            _stream.WriteBytes(Result.Failure.Strings->Type.c_str(), 4);
            _stream.WriteFourCC(Result.Failure.Strings->Region);
            _stream.WriteBytes(Result.Failure.Strings->ModuleId, 32);
        }

        _stream.Write(Result.Failure.Result.Type, 2);
        if (Result.Failure.Result.Type == FailureType::FAILURE)
        {
            _stream.Write(Result.Failure.Result.Failure.Error, 16);
            _stream.Write(Result.Failure.Result.Failure.Wait + std::numeric_limits<int32>::min(), 32);
        }
    }
}

std::string Battlenet::Authentication::ResumeResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ResumeResponse" << std::endl;
    return stream.str();
}

void Battlenet::Authentication::ResumeResponse::SetAuthResult(AuthResult result)
{
    Result.Type = result != AUTH_OK ? ResultType::FAILURE : ResultType::SUCCESS;
    Result.Failure.Result.Failure.Error = result;
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
        _stream.WriteBytes(info->Handle.Type.c_str(), 4);
        _stream.WriteFourCC(info->Handle.Region);
        _stream.WriteBytes(info->Handle.ModuleId, 32);
        _stream.Write(info->DataSize, 10);
        _stream.WriteBytes(info->Data, info->DataSize);
    }
}

std::string Battlenet::Authentication::ProofRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Authentication::ProofRequest" << std::endl;
    APPEND_FIELD(stream, Modules);
    return stream.str();
}
