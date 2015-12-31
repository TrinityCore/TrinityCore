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
#include "Util.h"
#include "CachePackets.h"

void Battlenet::Cache::GetStreamItemsRequest::Read()
{
    _stream.ReadSkip(31);
    Token = _stream.Read<uint32>(32);
    ReferenceTime = _stream.Read<int32>(32) - std::numeric_limits<int32>::min();
    Direction = _stream.Read<uint8>(1);
    MaxItems = _stream.Read<uint8>(6);
    Locale = _stream.ReadFourCC();
    Stream.Type = _stream.Read<uint8>(1);
    if (Stream.Type == StreamId::DESCRIPTION)
    {
        Stream.Description.ItemName = _stream.ReadFourCC();
        Stream.Description.Channel = _stream.ReadFourCC();
    }
    else
        Stream.Index = _stream.Read<uint16>(16);
}

std::string Battlenet::Cache::GetStreamItemsRequest::StreamId::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::GetStreamItemsRequest::StreamId" << std::endl;

    if (Type == INDEX)
        APPEND_FIELD(stream, Index);
    else
        APPEND_FIELD(stream, Description);

    return stream.str();
}

std::string Battlenet::Cache::GetStreamItemsRequest::StreamId::DescriptionType::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::GetStreamItemsRequest::StreamId::Description" << std::endl;
    APPEND_FIELD(stream, Channel);
    APPEND_FIELD(stream, ItemName);
    return stream.str();
}

std::string Battlenet::Cache::GetStreamItemsRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::GetStreamItemsRequest" << std::endl;
    APPEND_FIELD(stream, Token);
    APPEND_FIELD(stream, MaxItems);
    APPEND_FIELD(stream, ReferenceTime);
    APPEND_FIELD(stream, Direction);
    APPEND_FIELD(stream, Stream);
    APPEND_FIELD(stream, Locale);
    return stream.str();
}

void Battlenet::Cache::GetStreamItemsRequest::CallHandler(Session* session)
{
    session->HandleGetStreamItemsRequest(*this);
}

Battlenet::Cache::GetStreamItemsResponse::~GetStreamItemsResponse()
{
    for (size_t i = 0; i < Items.size(); ++i)
        delete Items[i];
}

void Battlenet::Cache::GetStreamItemsResponse::Write()
{
    _stream.Write(Offset, 16);
    _stream.Write(TotalNumItems, 16);
    _stream.Write(Token, 32);
    _stream.Write(Items.size(), 6);
    for (ModuleInfo const* info : Items)
    {
        _stream.WriteBytes(info->Handle.Type.c_str(), 4);
        _stream.WriteFourCC(info->Handle.Region);
        _stream.WriteBytes(info->Handle.ModuleId, 32);
        _stream.WriteSkip(27);
        _stream.WriteBytes(info->Data, 4);
    }
}

std::string Battlenet::Cache::GetStreamItemsResponse::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Cache::GetStreamItemsResponse" << std::endl;
    APPEND_FIELD(stream, Items);
    APPEND_FIELD(stream, Offset);
    APPEND_FIELD(stream, TotalNumItems);
    APPEND_FIELD(stream, Token);
    return stream.str();
}
