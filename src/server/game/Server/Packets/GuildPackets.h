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

#ifndef GuildPackets_h__
#define GuildPackets_h__

#include "Packet.h"
#include "Guild.h"

namespace WorldPackets
{
    namespace Guild
    {
        class QueryGuildInfo final : public ClientPacket
        {
            public:
                QueryGuildInfo(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 GuildID;
        };

        class QueryGuildInfoResponse final : public ServerPacket
        {
            public:
                QueryGuildInfoResponse();

                WorldPacket const* Write() override;

                uint32 GuildID;
                std::string GuildName;
                std::string RankName[GUILD_RANKS_MAX_COUNT];
                uint32 EmblemStyle = 0;
                uint32 EmblemColor = 0;
                uint32 BorderStyle = 0;
                uint32 BorderColor = 0;
                uint32 BackgroundColor = 0;
        };
    }
}

#endif // GuildPackets_h__
