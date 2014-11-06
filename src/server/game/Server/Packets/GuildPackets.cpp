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

WorldPackets::Guild::GuildQuery::GuildQuery(WorldPacket&& packet)
    : ClientPacket(std::move(packet))
{
    ASSERT(_worldPacket.GetOpcode() == CMSG_GUILD_QUERY);
}

void WorldPackets::Guild::GuildQuery::Read()
{
    _worldPacket >> GuildGuid;
    _worldPacket >> PlayerGuid;
}

WorldPackets::Guild::GuildQueryResponse::GuildQueryResponse()
    : ServerPacket(SMSG_GUILD_QUERY_RESPONSE) { }

WorldPacket const* WorldPackets::Guild::GuildQueryResponse::Write()
{
    _worldPacket << GuildGuid;
    _worldPacket.WriteBit(Info.HasValue);

    if (Info.HasValue)
    {
        _worldPacket << Info.value.GuildGuid;
        _worldPacket << uint32(Info.value.VirtualRealmAddress);
        _worldPacket << uint32(Info.value.Ranks.size());
        _worldPacket << uint32(Info.value.EmblemStyle);
        _worldPacket << uint32(Info.value.EmblemColor);
        _worldPacket << uint32(Info.value.BorderStyle);
        _worldPacket << uint32(Info.value.BorderColor);
        _worldPacket << uint32(Info.value.BackgroundColor);

        for (GuildInfo::RankInfo const& rank : Info.value.Ranks)
        {
            _worldPacket << uint32(rank.Id);
            _worldPacket << uint32(rank.Order);

            _worldPacket.WriteBits(rank.Name.size(), 7);
            _worldPacket << rank.Name;
        }

        _worldPacket.WriteBits(Info.value.Name.size(), 7);
        _worldPacket << Info.value.Name;
    }
    _worldPacket.FlushBits();

    return &_worldPacket;
}
