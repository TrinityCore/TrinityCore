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

void WorldPackets::Who::WhoIsRequest::Read()
{
    CharName = _worldPacket.ReadString(_worldPacket.ReadBits(6));
}

WorldPacket const* WorldPackets::Who::WhoIsResponse::Write()
{
    _worldPacket.WriteBits(AccountName.length(), 11);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(AccountName);

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Who::WhoWord& word)
{
    word.Word = data.ReadString(data.ReadBits(7));
    data.ResetBitPos();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Who::WhoRequestServerInfo>& serverInfo)
{
    serverInfo = boost::in_place();

    data >> serverInfo->FactionGroup;
    data >> serverInfo->Locale;
    data >> serverInfo->RequesterVirtualRealmAddress;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Who::WhoRequest& request)
{
    data >> request.MinLevel;
    data >> request.MaxLevel;
    data >> request.RaceFilter.RawValue;
    data >> request.ClassFilter;

    uint32 nameLength = data.ReadBits(6);
    uint32 virtualRealmNameLength = data.ReadBits(9);
    uint32 guildNameLength = data.ReadBits(7);
    uint32 guildVirtualRealmNameLength = data.ReadBits(9);
    request.Words.resize(data.ReadBits(3));

    request.ShowEnemies = data.ReadBit();
    request.ShowArenaPlayers = data.ReadBit();
    request.ExactName = data.ReadBit();

    bool hasWhoRequest = data.ReadBit();
    data.ResetBitPos();

    for (size_t i = 0; i < request.Words.size(); ++i)
        data >> request.Words[i];

    request.Name = data.ReadString(nameLength);
    request.VirtualRealmName = data.ReadString(virtualRealmNameLength);
    request.Guild = data.ReadString(guildNameLength);
    request.GuildVirtualRealmName = data.ReadString(guildVirtualRealmNameLength);

    if (hasWhoRequest)
        data >> request.ServerInfo;

    return data;
}

void WorldPackets::Who::WhoRequestPkt::Read()
{
    Areas.resize(_worldPacket.ReadBits(4));

    _worldPacket >> Request;
    _worldPacket >> RequestID;

    for (size_t i = 0; i < Areas.size(); ++i)
        _worldPacket >> Areas[i];
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Who::WhoEntry const& entry)
{
    data << entry.PlayerData;

    data << entry.GuildGUID;
    data << uint32(entry.GuildVirtualRealmAddress);
    data << int32(entry.AreaID);

    data.WriteBits(entry.GuildName.length(), 7);
    data.WriteBit(entry.IsGM);
    data.FlushBits();

    data.WriteString(entry.GuildName);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Who::WhoResponse const& response)
{
    data.WriteBits(response.Entries.size(), 6);
    data.FlushBits();

    for (WorldPackets::Who::WhoEntry const& whoEntry : response.Entries)
        data << whoEntry;

    return data;
}

WorldPacket const* WorldPackets::Who::WhoResponsePkt::Write()
{
    _worldPacket << uint32(RequestID);
    _worldPacket << Response;

    return &_worldPacket;
}
