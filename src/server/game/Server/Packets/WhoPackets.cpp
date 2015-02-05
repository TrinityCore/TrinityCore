/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "WhoPackets.h"

namespace WorldPackets::Who
{
void WhoIsRequest::Read()
{
    _worldPacket >> CharName;
}

WorldPacket const* WhoIsResponse::Write()
{
    _worldPacket << AccountName;

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, WhoWord& word)
{
    data >> word.Word;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WhoRequest& request)
{
    data >> request.MinLevel;
    data >> request.MaxLevel;
    data >> request.Name;
    data >> request.Guild;
    data >> request.RaceFilter;
    data >> request.ClassFilter;

    request.Areas.resize(data.read<uint32>());
    for (int32& area : request.Areas)
        data >> area;

    request.Words.resize(data.read<uint32>());
    for (WhoWord& word : request.Words)
        data >> word;

    return data;
}

void WhoRequestPkt::Read()
{
    _worldPacket >> Request;
}

ByteBuffer& operator<<(ByteBuffer& data, WhoEntry const& entry)
{
    data << entry.Name;
    data << entry.GuildName;
    data << int32(entry.Level);
    data << int32(entry.ClassID);
    data << int32(entry.Race);
    data << uint8(entry.Sex);
    data << int32(entry.AreaID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WhoResponse const& response)
{
    data << uint32(response.Entries.size());
    data << uint32(response.TotalMatches);

    for (size_t i = 0; i < response.Entries.size(); ++i)
        data << response.Entries[i];

    return data;
}

WorldPacket const* WhoResponsePkt::Write()
{
    _worldPacket << Response;

    return &_worldPacket;
}
}
