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

#include "WhoPackets.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Who::WhoWord& word)
{
    data >> word.Word;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Who::WhoRequest& request)
{
    data >> request.MinLevel;
    data >> request.MaxLevel;
    data >> request.Name;
    data >> request.Guild;
    data >> request.RaceFilter;
    data >> request.ClassFilter;

    uint32 areas = 0;
    data >> areas;

    request.Areas.resize(areas);
    for (size_t i = 0; i < request.Areas.size(); ++i)
        data >> request.Areas[i];

    uint32 words = 0;
    data >> words;

    request.Words.resize(words);
    for (size_t i = 0; i < request.Words.size(); ++i)
        data >> request.Words[i];

    return data;
}

void WorldPackets::Who::WhoRequestPkt::Read()
{
    _worldPacket >> Request;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Who::WhoEntry const& entry)
{
    data << entry.PlayerData.Name;
    data << entry.GuildName;
    data << uint32(entry.PlayerData.Level);
    data << uint32(entry.PlayerData.ClassID);
    data << uint32(entry.PlayerData.Race);
    data << uint8(entry.PlayerData.Sex);
    data << uint32(entry.AreaID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Who::WhoResponse const& response)
{
    data << uint32(response.Entries.size()); // Number of displayed characters
    data << uint32(response.Entries.size()); // Number of matching characters (when using filters) TODO

    for (WorldPackets::Who::WhoEntry const& whoEntry : response.Entries)
        data << whoEntry;

    return data;
}

WorldPacket const* WorldPackets::Who::WhoResponsePkt::Write()
{
    _worldPacket << Response;

    return &_worldPacket;
}
