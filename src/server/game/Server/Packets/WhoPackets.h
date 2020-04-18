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

#ifndef WhoPackets_h__
#define WhoPackets_h__

#include "Packet.h"
#include "QueryPackets.h"

namespace WorldPackets
{
    namespace Who
    {
        struct WhoWord
        {
            std::string Word;
        };

        struct WhoRequest
        {
            int32 MinLevel = 0;
            int32 MaxLevel = 0;
            std::string Name;
            std::string Guild;
            int32 RaceFilter = -1;
            int32 ClassFilter = -1;
            std::vector<WhoWord> Words;
            std::vector<int32> Areas;
        };

        class WhoRequestPkt final : public ClientPacket
        {
        public:
            WhoRequestPkt(WorldPacket&& packet) : ClientPacket(CMSG_WHO, std::move(packet)) { }

            void Read() override;

            WhoRequest Request;
        };

        struct WhoEntry
        {
            Query::PlayerGuidLookupData PlayerData;
            std::string GuildName;
            int32 AreaID = 0;
        };

        struct WhoResponse
        {
            std::vector<WhoEntry> Entries;
        };

        class WhoResponsePkt final : public ServerPacket
        {
        public:
            WhoResponsePkt() : ServerPacket(SMSG_WHO, 1) { }

            WorldPacket const* Write() override;

            WhoResponse Response;
        };
    }
}

#endif // WhoPackets_h__
