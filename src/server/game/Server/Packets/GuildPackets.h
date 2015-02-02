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
#include "ObjectGuid.h"
#include "Guild.h"

namespace WorldPackets
{
    namespace Guild
    {

        struct GuildRank
        {
            GuildRank() { }

            GuildRank(uint32 id, uint32 order, std::string const& name)
                : RankID(id), RankOrder(order), RankName(name) { }

            uint32 RankID;
            uint32 RankOrder;
            uint32 Flags;
            uint32 WithdrawGoldLimit;

            std::string RankName;

            struct GuildRankTabInfo
            {
                int32 TabFlags;
                int32 TabWithdrawItemLimit;
            };

            GuildRankTabInfo TabInfo[GUILD_BANK_MAX_TABS];

            bool operator<(GuildRank const& right) const
            {
                return RankID < right.RankID;
            }
        };

        class QueryGuildInfo final : public ClientPacket
        {
        public:
            QueryGuildInfo(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_QUERY, std::move(packet)) { }

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

                std::set<GuildRank> Ranks;

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

        class GuildGetRoster final : public ClientPacket
        {
        public:
            GuildGetRoster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_ROSTER, std::move(packet)) { }

            void Read() override { }
        };

        class GuildRosterResponse final : public ServerPacket
        {
        public:
            struct GuildMemberInfo
            {
                ObjectGuid MemberGUID;
                uint32 RankID;
                uint32 AreaID;
                uint32 AchivementPoints;
                uint32 Reputation;
                float LastOnlineTime; //LastSave

                struct GuildMemberProfession
                {
                    uint32 ID;
                    uint32 Rank;
                    uint32 Step;
                };

                GuildMemberProfession Professions[2];
                uint32 VirtualRealmAddress;
                uint8 Flags;
                uint8 Level;
                uint8 Class;
                uint8 Gender;
                bool Authenticated;
                bool ScrollOfResurrection;
                std::string Name;
                std::string Note;
                std::string OfficerNote;

                bool operator<(GuildMemberInfo const& right) const
                {
                    return LastOnlineTime < right.LastOnlineTime;
                }

            };
            GuildRosterResponse() : ServerPacket(SMSG_GUILD_ROSTER) { }

            WorldPacket const* Write() override;

            uint32 MemberCount = 0; //NumAccounts
            time_t CreatedDate;
            uint32 GuildFlags;

            std::set<GuildMemberInfo> Members;

            std::string WelcomeText;
            std::string InfoText;
        };

        class GuildGetRanks final : public ClientPacket
        {
        public:
            GuildGetRanks(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_RANKS, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildGUID;
        };

        class GuildRanksResponse final : public ServerPacket
        {
        public:
            GuildRanksResponse() : ServerPacket(SMSG_GUILD_RANKS) { }

            WorldPacket const* Write() override;

            std::set<GuildRank> Ranks;
        };
    }
}

#endif // GuildPackets_h__
