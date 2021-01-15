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
#include "ObjectGuid.h"
#include "QueryPackets.h"
#include "RaceMask.h"

namespace WorldPackets
{
    namespace Who
    {
        class WhoIsRequest final : public ClientPacket
        {
        public:
            WhoIsRequest(WorldPacket&& packet) : ClientPacket(CMSG_WHO_IS, std::move(packet)) { }

            void Read() override;

            std::string CharName;
        };

        class WhoIsResponse final : public ServerPacket
        {
        public:
            WhoIsResponse() : ServerPacket(SMSG_WHO_IS, 2) { }

            WorldPacket const* Write() override;

            std::string AccountName;
        };

        struct WhoWord
        {
            std::string Word;
        };

        struct WhoRequestServerInfo
        {
            int32 FactionGroup = 0;
            int32 Locale = 0;
            uint32 RequesterVirtualRealmAddress = 0;
        };

        struct WhoRequest
        {
            int32 MinLevel = 0;
            int32 MaxLevel = 0;
            std::string Name;
            std::string VirtualRealmName;
            std::string Guild;
            std::string GuildVirtualRealmName;
            Trinity::RaceMask<int64> RaceFilter = { SI64LIT(0) };
            int32 ClassFilter = -1;
            std::vector<WhoWord> Words;
            bool ShowEnemies = false;
            bool ShowArenaPlayers = false;
            bool ExactName = false;
            Optional<WhoRequestServerInfo> ServerInfo;
        };

        class WhoRequestPkt final : public ClientPacket
        {
        public:
            WhoRequestPkt(WorldPacket&& packet) : ClientPacket(CMSG_WHO, std::move(packet)) { }

            void Read() override;

            WhoRequest Request;
            uint32 RequestID = 0;
            Array<int32, 10> Areas;
        };

        struct WhoEntry
        {
            Query::PlayerGuidLookupData PlayerData;
            ObjectGuid GuildGUID;
            uint32 GuildVirtualRealmAddress = 0;
            std::string GuildName;
            int32 AreaID = 0;
            bool IsGM = false;
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

            uint32 RequestID = 0;
            WhoResponse Response;
        };
    }
}

#endif // WhoPackets_h__
