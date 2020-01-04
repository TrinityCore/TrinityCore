/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Util.h"
#include "CachePackets.h"

void Battlenet::Cache::GetStreamItemsRequest::Read()
{
    if (_stream.Read<bool>(1))
    {
        _stream.Read<uint16>(11);   // padding
        ItemName = _stream.ReadFourCC();
        Channel = _stream.ReadFourCC();
    }
    else
        _stream.Read<uint16>(16);

    _stream.Read<bool>(1);  // StreamDirection
    ReferenceTime = _stream.Read<int32>(32) - std::numeric_limits<int32>::min();
    Locale = _stream.ReadFourCC();
    Index = _stream.Read<uint32>(32);
    _stream.Read<uint8>(6); // Module count, always 0
}

std::string Battlenet::Cache::GetStreamItemsRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::GetStreamItemsRequest Channel: " << Channel << ", ItemName: " << ItemName
        << ", Locale: " << Locale << ", Index: " << Index;
    return stream.str();
}

void Battlenet::Cache::GetStreamItemsRequest::CallHandler(Session* session)
{
    session->HandleGetStreamItemsRequest(*this);
}

Battlenet::Cache::GetStreamItemsResponse::~GetStreamItemsResponse()
{
    for (size_t i = 0; i < Modules.size(); ++i)
        delete Modules[i];
}

void Battlenet::Cache::GetStreamItemsResponse::Write()
{
    _stream.Write(0, 16);
    _stream.Write(Modules.size(), 6);
    for (ModuleInfo const* info : Modules)
    {
        _stream.WriteBytes(info->Type.c_str(), 4);
        _stream.WriteFourCC(info->Region);
        _stream.WriteBytes(info->ModuleId, 32);
        _stream.WriteBytes(info->Data, 4);
    }

    _stream.Write(Index, 32);
    _stream.Write(0, 17);   // padding
    _stream.Write(1, 16);
    _stream.Write(0, 2);
}

std::string Battlenet::Cache::GetStreamItemsResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::GetStreamItemsResponse modules " << Modules.size();
    for (ModuleInfo const* module : Modules)
        stream << std::endl << "Battlenet::ModuleInfo Locale " << module->Region.c_str() << ", ModuleId " << ByteArrayToHexStr(module->ModuleId, 32) << ", Data " << ByteArrayToHexStr(module->Data, module->DataSize);

    return stream.str();
}
