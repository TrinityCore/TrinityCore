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

#include "GuildPackets.h"
#include "ObjectGuid.h"

WorldPackets::Guild::QueryGuildInfo::QueryGuildInfo(WorldPacket&& packet)
    : ClientPacket(std::move(packet))
{
    ASSERT(_worldPacket.GetOpcode() == CMSG_GUILD_QUERY);
}

void WorldPackets::Guild::QueryGuildInfo::Read()
{
    _worldPacket >> GuildGuid;
    _worldPacket >> PlayerGuid;
}

WorldPackets::Guild::QueryGuildInfoResponse::QueryGuildInfoResponse()
    : ServerPacket(SMSG_GUILD_QUERY_RESPONSE) { }

WorldPacket const* WorldPackets::Guild::QueryGuildInfoResponse::Write()
{
    _worldPacket << GuildGuid;
    _worldPacket.WriteBit(Info.HasValue);

    if (Info.HasValue)
    {
        _worldPacket << Info.value.GuildGUID;
        _worldPacket << uint32(Info.value.VirtualRealmAddress);
        _worldPacket << uint32(Info.value.Ranks.size());
        _worldPacket << uint32(Info.value.EmblemStyle);
        _worldPacket << uint32(Info.value.EmblemColor);
        _worldPacket << uint32(Info.value.BorderStyle);
        _worldPacket << uint32(Info.value.BorderColor);
        _worldPacket << uint32(Info.value.BackgroundColor);

        for (GuildInfo::GuildInfoRank const& rank : Info.value.Ranks)
        {
            _worldPacket << uint32(rank.RankID);
            _worldPacket << uint32(rank.RankOrder);

            _worldPacket.WriteBits(rank.RankName.size(), 7);
            _worldPacket.WriteString(rank.RankName);
        }

        _worldPacket.WriteBits(Info.value.GuildName.size(), 7);
        _worldPacket.WriteString(Info.value.GuildName);
    }
    _worldPacket.FlushBits();

    return &_worldPacket;
}
