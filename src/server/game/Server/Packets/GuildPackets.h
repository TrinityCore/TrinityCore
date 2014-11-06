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

class ObjectGuid;

namespace WorldPackets
{
    namespace Guild
    {
        class GuildQuery final : public ClientPacket
        {
        public:
            GuildQuery(WorldPacket&& packet);

            void Read() override;

            ObjectGuid GuildGuid;
            ObjectGuid PlayerGuid;
        };

        class GuildQueryResponse final : public ServerPacket
        {
        public:
            struct GuildInfo
            {
                ObjectGuid GuildGuid;

                uint32 VirtualRealmAddress = 0;
                uint32 EmblemStyle = 0;
                uint32 EmblemColor = 0;
                uint32 BorderStyle = 0;
                uint32 BorderColor = 0;
                uint32 BackgroundColor = 0;

                struct RankInfo
                {
                    RankInfo(uint32 id, uint32 order, std::string const& name)
                        : Id(id), Order(order), Name(name) { }

                    uint32 Id;
                    uint32 Order;
                    std::string Name;

                    bool operator<(RankInfo const& right) const
                    {
                        return Id < right.Id;
                    }
                };

                std::set<RankInfo> Ranks;

                std::string Name;
            };

            GuildQueryResponse();

            WorldPacket const* Write() override;

            ObjectGuid GuildGuid;
            Optional<GuildInfo> Info;
        };
    }
}

#endif // GuildPackets_h__
