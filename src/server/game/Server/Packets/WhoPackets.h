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

#ifndef TRINITYCORE_WHO_PACKETS_H
#define TRINITYCORE_WHO_PACKETS_H

#include "Packet.h"
#include "PacketUtilities.h"
#include "SharedDefines.h"

namespace WorldPackets
{
    namespace Who
    {
        class WhoIsRequest final : public ClientPacket
        {
        public:
            explicit WhoIsRequest(WorldPacket&& packet) : ClientPacket(CMSG_WHOIS, std::move(packet)) { }

            void Read() override;

            std::string CharName;
        };

        class WhoIsResponse final : public ServerPacket
        {
        public:
            explicit WhoIsResponse() : ServerPacket(SMSG_WHOIS, 2) { }

            WorldPacket const* Write() override;

            std::string AccountName;
        };

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
            Array<int32, 10> Areas;
            Array<WhoWord, 4> Words;
        };

        class WhoRequestPkt final : public ClientPacket
        {
        public:
            explicit WhoRequestPkt(WorldPacket&& packet) : ClientPacket(CMSG_WHO, std::move(packet)) { }

            void Read() override;

            WhoRequest Request;
        };

        struct WhoEntry
        {
            std::string_view Name;
            std::string_view GuildName;
            int32 Level = 0;
            int32 ClassID = CLASS_NONE;
            int32 Race = RACE_NONE;
            uint8 Sex = GENDER_NONE;
            int32 AreaID = 0;
        };

        struct WhoResponse
        {
            std::vector<WhoEntry> Entries;
            uint32 TotalMatches = 0;
        };

        class WhoResponsePkt final : public ServerPacket
        {
        public:
            explicit WhoResponsePkt() : ServerPacket(SMSG_WHO, 1) { }

            WorldPacket const* Write() override;

            WhoResponse Response;
        };
    }
}

#endif // TRINITYCORE_WHO_PACKETS_H
