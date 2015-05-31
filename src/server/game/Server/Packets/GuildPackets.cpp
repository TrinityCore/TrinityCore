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

#include "GuildPackets.h"

void WorldPackets::Guild::QueryGuildInfo::Read()
{
    _worldPacket >> GuildID;
}

WorldPackets::Guild::QueryGuildInfoResponse::QueryGuildInfoResponse()
    : ServerPacket(SMSG_GUILD_QUERY_RESPONSE) { }

WorldPacket const* WorldPackets::Guild::QueryGuildInfoResponse::Write()
{
    uint8 usedRanks = 0;

    _worldPacket << uint32(GuildID);

    _worldPacket << GuildName;

    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
    {
        _worldPacket << RankName[i];
        if (!RankName[i].empty())
            ++usedRanks;
    }

    _worldPacket << uint32(EmblemStyle);
    _worldPacket << uint32(EmblemColor);
    _worldPacket << uint32(BorderStyle);
    _worldPacket << uint32(BorderColor);
    _worldPacket << uint32(BackgroundColor);

    _worldPacket << uint32(usedRanks);

    return &_worldPacket;
}
