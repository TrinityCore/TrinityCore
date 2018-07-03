/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef game_AchievementPackets_h__
#define game_AchievementPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Achievement
    {
        struct EarnedAchievement
        {
            uint32 Id = 0;
            time_t Date = time_t(0);
            ObjectGuid Owner;
            uint32 VirtualRealmAddress = 0;
            uint32 NativeRealmAddress = 0;
        };

        struct CriteriaProgress
        {
            uint32 Id = 0;
            uint64 Quantity = 0;
            ObjectGuid Player;
            uint32 Flags = 0;
            time_t Date = time_t(0);
            uint32 TimeFromStart = 0;
            uint32 TimeFromCreate = 0;
        };

        struct AllAchievements
        {
            std::vector<EarnedAchievement> Earned;
            std::vector<CriteriaProgress> Progress;
        };

        class AllAchievementData final : public ServerPacket
        {
        public:
            AllAchievementData() : ServerPacket(SMSG_ALL_ACHIEVEMENT_DATA) { }

            WorldPacket const* Write() override;

            AllAchievements Data;
        };

        class RespondInspectAchievements final : public ServerPacket
        {
        public:
            RespondInspectAchievements() : ServerPacket(SMSG_RESPOND_INSPECT_ACHIEVEMENTS) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            AllAchievements Data;
        };

        class CriteriaUpdate final : public ServerPacket
        {
        public:
            CriteriaUpdate() : ServerPacket(SMSG_CRITERIA_UPDATE, 4 + 8 + 16 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 CriteriaID = 0;
            uint64 Quantity = 0;
            ObjectGuid PlayerGUID;
            uint32 Flags = 0;
            time_t CurrentTime = time_t(0);
            uint32 ElapsedTime = 0;
            uint32 CreationTime = 0;
        };

        class CriteriaDeleted final : public ServerPacket
        {
        public:
            CriteriaDeleted() : ServerPacket(SMSG_CRITERIA_DELETED, 4) { }

            WorldPacket const* Write() override;

            uint32 CriteriaID = 0;
        };

        class AchievementDeleted final : public ServerPacket
        {
        public:
            AchievementDeleted() : ServerPacket(SMSG_ACHIEVEMENT_DELETED, 4) { }

            WorldPacket const* Write() override;

            uint32 AchievementID = 0;
            uint32 Immunities = 0; // this is just garbage, not used by client
        };

        class AchievementEarned final : public ServerPacket
        {
        public:
            AchievementEarned() : ServerPacket(SMSG_ACHIEVEMENT_EARNED, 16 + 4 + 4 + 4 + 4 + 1 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Earner;
            uint32 EarnerNativeRealm = 0;
            uint32 EarnerVirtualRealm = 0;
            uint32 AchievementID = 0;
            time_t Time = time_t(0);
            bool Initial = false;
            ObjectGuid Sender;
        };

        class ServerFirstAchievement final : public ServerPacket
        {
        public:
            ServerFirstAchievement() : ServerPacket(SMSG_SERVER_FIRST_ACHIEVEMENT) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            std::string Name;
            uint32 AchievementID = 0;
            bool GuildAchievement = false;
        };

        struct GuildCriteriaProgress
        {
            int32 CriteriaID = 0;
            uint32 DateCreated = 0;
            uint32 DateStarted = 0;
            time_t DateUpdated = 0;
            uint64 Quantity = 0;
            ObjectGuid PlayerGUID;
            int32 Flags = 0;
        };

        class GuildCriteriaUpdate final : public ServerPacket
        {
        public:
            GuildCriteriaUpdate() : ServerPacket(SMSG_GUILD_CRITERIA_UPDATE) { }

            WorldPacket const* Write() override;

            std::vector<GuildCriteriaProgress> Progress;
        };

        class GuildCriteriaDeleted final : public ServerPacket
        {
        public:
            GuildCriteriaDeleted() : ServerPacket(SMSG_GUILD_CRITERIA_DELETED, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            int32 CriteriaID = 0;
        };

        class GuildSetFocusedAchievement final : public ClientPacket
        {
        public:
            GuildSetFocusedAchievement(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_FOCUSED_ACHIEVEMENT, std::move(packet)) { }

            void Read() override;

            uint32 AchievementID = 0;
        };

        class GuildAchievementDeleted final : public ServerPacket
        {
        public:
            GuildAchievementDeleted() : ServerPacket(SMSG_GUILD_ACHIEVEMENT_DELETED, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            uint32 AchievementID = 0;
            time_t TimeDeleted = time_t(0);
        };

        class GuildAchievementEarned final : public ServerPacket
        {
        public:
            GuildAchievementEarned() : ServerPacket(SMSG_GUILD_ACHIEVEMENT_EARNED, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 AchievementID = 0;
            ObjectGuid GuildGUID;
            time_t TimeEarned = time_t(0);
        };

        class AllGuildAchievements final : public ServerPacket
        {
        public:
            AllGuildAchievements() : ServerPacket(SMSG_ALL_GUILD_ACHIEVEMENTS) { }

            WorldPacket const* Write() override;

            std::vector<EarnedAchievement> Earned;
        };

        class GuildGetAchievementMembers final : public ClientPacket
        {
        public:
            GuildGetAchievementMembers(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_ACHIEVEMENT_MEMBERS, std::move(packet)) { }

            void Read() override;

            ObjectGuid PlayerGUID;
            ObjectGuid GuildGUID;
            int32 AchievementID = 0;
        };

        struct GuildAchievementMember
        {
            GuildAchievementMember() = default;
            GuildAchievementMember(ObjectGuid guid) : MemberGUID(guid) { }

            ObjectGuid MemberGUID;
        };

        class GuildAchievementMembers final : public ServerPacket
        {
        public:
            GuildAchievementMembers() : ServerPacket(SMSG_GUILD_ACHIEVEMENT_MEMBERS) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            int32 AchievementID = 0;
            std::vector<GuildAchievementMember> Member;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::CriteriaProgress const& criteria);

#endif // game_AchievementPackets_h__
