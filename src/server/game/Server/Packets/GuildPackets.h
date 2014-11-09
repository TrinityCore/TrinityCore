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

#ifndef GuildPackets_h__
#define GuildPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Guild
    {
        class QueryGuildInfo final : public ClientPacket
        {
        public:
            QueryGuildInfo(WorldPacket&& packet);

            void Read() override;

            ObjectGuid PlayerGuid;
            ObjectGuid GuildGuid;
        };

        class QueryGuildInfoResponse final : public ServerPacket
        {
        public:
            struct GuildInfo
            {
                ObjectGuid GuildGUID;

                uint32 VirtualRealmAddress = 0; ///< a special identifier made from the Index, BattleGroup and Region.

                std::string GuildName;

                struct GuildInfoRank
                {
                    GuildInfoRank(uint32 id, uint32 order, std::string const& name)
                        : RankID(id), RankOrder(order), RankName(name) { }

                    uint32 RankID;
                    uint32 RankOrder;
                    std::string RankName;

                    bool operator<(GuildInfoRank const& right) const
                    {
                        return RankID < right.RankID;
                    }
                };

                std::set<GuildInfoRank> Ranks;

                uint32 EmblemStyle = 0;
                uint32 EmblemColor = 0;
                uint32 BorderStyle = 0;
                uint32 BorderColor = 0;
                uint32 BackgroundColor = 0;
            };

            QueryGuildInfoResponse();

            WorldPacket const* Write() override;

            ObjectGuid GuildGuid;
            Optional<GuildInfo> Info;
        };
    }
}

#endif // GuildPackets_h__
