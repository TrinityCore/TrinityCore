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

#ifndef ArenaPackets_h__
#define ArenaPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace Arena
    {
        class PvpSeason final : public ServerPacket
        {
        public:
            PvpSeason() : ServerPacket(SMSG_PVP_SEASON, 4 + 4 + 4 + 4 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            int32 Unk0 = 0;
            int32 Unk1 = 0;
            int32 CurrentArenaSeason = 0;
            int32 PreviousArenaSeason = 0;
            int32 CurrentArenaUsesTeams = 0;
            int32 PreviousArenaUsesTeams = 0;
            int32 Unk6 = 0;
            bool Unk7 = 0;
            bool Unk8 = 0;
            bool Unk9 = 0;
        };

        class CArenaTeamRoster final : public ClientPacket
        {
        public:
            CArenaTeamRoster(WorldPacket&& packet) : ClientPacket(CMSG_ARENA_TEAM_ROSTER, std::move(packet)) { }

            void Read() override;

            int32 TeamID = 0;

        };

        struct ArenaTeamMember
        {
            ObjectGuid MemberGUID;
            bool Online = false;
            uint32 Rank = 0;
            uint8 Level = 0;
            uint8 ClassID = 0;
            int32 WeekMatches = 0;
            int32 WeekWins = 0;
            int32 SeasonMatches = 0;
            int32 SeasonWins = 0;
            int32 ContributionRating = 0;
            std::string Name;
            Optional<float> GDFRating = 0.0f;
            Optional<float> GDFVariance = 0.0f;
        };

        class SArenaTeamRoster final : public ServerPacket
        {
        public:
            SArenaTeamRoster() : ServerPacket(SMSG_ARENA_TEAM_ROSTER, 100) { }

            WorldPacket const* Write() override;

            int32 TeamID = 0;
            int32 TeamSize = 0;
            int32 MatchesPlayed = 0;
            int32 MatchesWon = 0;
            int32 SeasonMatchesPlayed = 0;
            int32 SeasonMatchesWon = 0;
            int32 Rating = 0;
            int32 Ranking = 0;
            bool Disqualified = false;

            std::vector<ArenaTeamMember> Members;
        };

        class QueryArenaTeamResponse final : public ServerPacket
        {
        public:
            QueryArenaTeamResponse() : ServerPacket(SMSG_QUERY_ARENA_TEAM_RESPONSE, 50) { }

            WorldPacket const* Write() override;

            int32 TeamID = 0;
            bool Allow = false;
            int32 TeamSize = 0;
            int32 EmblemBackground = 0;
            int32 EmblemIconStyle = 0;
            int32 EmblemIconColor = 0;
            int32 EmblemBorderStyle = 0;
            int32 EmblemBorderColor = 0;
            std::string Name;
        };

        class ArenaTeamAccept final : public ClientPacket
        {
        public:
            ArenaTeamAccept(WorldPacket&& packet) : ClientPacket(CMSG_ARENA_TEAM_ACCEPT, std::move(packet)) { }

            void Read() override { }
        };

        class ArenaTeamDecline final : public ClientPacket
        {
        public:
            ArenaTeamDecline(WorldPacket&& packet) : ClientPacket(CMSG_ARENA_TEAM_DECLINE, std::move(packet)) { }

            void Read() override { }
        };

        class ArenaTeamCommandResult final : public ServerPacket
        {
        public:
            ArenaTeamCommandResult() : ServerPacket(SMSG_ARENA_TEAM_COMMAND_RESULT, 50) { }

            WorldPacket const* Write() override;

            uint8 Action = 0;
            uint8 ErrorID = 0;
            std::string TeamName;
            std::string PlayerName;
        };

        class ArenaTeamEvent final : public ServerPacket
        {
        public:
            ArenaTeamEvent() : ServerPacket(SMSG_ARENA_TEAM_EVENT, 1 + 2 + 2 + 2) { }

            WorldPacket const* Write() override;

            uint8 Event = 0;
            std::array<std::string, 3> Params = { };
        };

        class ArenaTeamDisband final : public ClientPacket
        {
        public:
            ArenaTeamDisband(WorldPacket&& packet) : ClientPacket(CMSG_ARENA_TEAM_DISBAND, std::move(packet)) { }

            void Read() override;

            int32 TeamID = 0;

        };

        class ArenaTeamLeave final : public ClientPacket
        {
        public:
            ArenaTeamLeave(WorldPacket&& packet) : ClientPacket(CMSG_ARENA_TEAM_LEAVE, std::move(packet)) { }

            void Read() override;

            int32 TeamID = 0;

        };

        ByteBuffer& operator<<(ByteBuffer& data, ArenaTeamMember const& member);
    }
}

#endif // ArenaPackets_h__
