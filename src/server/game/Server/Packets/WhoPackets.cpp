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

namespace WorldPackets::Who
{
void WhoIsRequest::Read()
{
    _worldPacket >> SizedString::BitsSize<6>(CharName);
    _worldPacket >> SizedString::Data(CharName);
}

WorldPacket const* WhoIsResponse::Write()
{
    _worldPacket << SizedString::BitsSize<11>(AccountName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(AccountName);

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, WhoWord& word)
{
    data.ResetBitPos();
    data >> SizedString::BitsSize<7>(word.Word);
    data >> SizedString::Data(word.Word);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WhoRequestServerInfo& serverInfo)
{
    data >> serverInfo.FactionGroup;
    data >> serverInfo.Locale;
    data >> serverInfo.RequesterVirtualRealmAddress;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WhoRequest& request)
{
    data >> request.MinLevel;
    data >> request.MaxLevel;
    data >> request.RaceFilter.RawValue;
    data >> request.ClassFilter;
    data >> SizedString::BitsSize<6>(request.Name);
    data >> SizedString::BitsSize<9>(request.VirtualRealmName);
    data >> SizedString::BitsSize<7>(request.Guild);
    data >> SizedString::BitsSize<9>(request.GuildVirtualRealmName);
    data >> BitsSize<3>(request.Words);
    data >> Bits<1>(request.ShowEnemies);
    data >> Bits<1>(request.ShowArenaPlayers);
    data >> Bits<1>(request.ExactName);
    data >> OptionalInit(request.ServerInfo);

    for (size_t i = 0; i < request.Words.size(); ++i)
        data >> request.Words[i];

    data >> SizedString::Data(request.Name);
    data >> SizedString::Data(request.VirtualRealmName);
    data >> SizedString::Data(request.Guild);
    data >> SizedString::Data(request.GuildVirtualRealmName);

    if (request.ServerInfo)
        data >> *request.ServerInfo;

    return data;
}

void WhoRequestPkt::Read()
{
    _worldPacket >> BitsSize<4>(Areas);
    _worldPacket >> Bits<1>(IsAddon);
    _worldPacket >> Request;
    _worldPacket >> Token;
    _worldPacket >> Origin;

    for (size_t i = 0; i < Areas.size(); ++i)
        _worldPacket >> Areas[i];
}

ByteBuffer& operator<<(ByteBuffer& data, WhoEntry const& entry)
{
    data << entry.PlayerData;

    data << entry.GuildGUID;
    data << uint32(entry.GuildVirtualRealmAddress);
    data << int32(entry.AreaID);

    data << SizedString::BitsSize<7>(entry.GuildName);
    data << Bits<1>(entry.IsGM);
    data.FlushBits();

    data << SizedString::Data(entry.GuildName);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WhoResponse const& response)
{
    data << BitsSize<6>(response.Entries);
    data.FlushBits();

    for (WhoEntry const& whoEntry : response.Entries)
        data << whoEntry;

    return data;
}

WorldPacket const* WhoResponsePkt::Write()
{
    _worldPacket << uint32(Token);
    _worldPacket << Response;

    return &_worldPacket;
}
}
