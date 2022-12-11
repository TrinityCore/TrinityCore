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

#ifndef GuildPackets_h__
#define GuildPackets_h__

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"
#include "Guild.h"

namespace WorldPackets
{
    namespace Guild
    {
        class GuildBankActivate final : public ClientPacket
        {
        public:
            GuildBankActivate(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_ACTIVATE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            bool FullUpdate = false;
        };

        class GuildBankQueryTab final : public ClientPacket
        {
        public:
            GuildBankQueryTab(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_QUERY_TAB, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint8 Tab = 0;
            bool FullUpdate = false;
        };

        class GuildBankBuyTab final : public ClientPacket
        {
        public:
            GuildBankBuyTab(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_BUY_TAB, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint8 BankTab = 0;
        };

        class GuildBankUpdateTab final : public ClientPacket
        {
        public:
            GuildBankUpdateTab(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_UPDATE_TAB, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint8 BankTab = 0;
            std::string Name;
            std::string Icon;
        };

        class GuildBankDepositMoney final : public ClientPacket
        {
        public:
            GuildBankDepositMoney(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_DEPOSIT_MONEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint64 Money = 0;
        };

        class GuildBankWithdrawMoney final : public ClientPacket
        {
        public:
            GuildBankWithdrawMoney(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_WITHDRAW_MONEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint64 Money = 0;
        };

        class GuildPermissionsQuery final : public ClientPacket
        {
        public:
            GuildPermissionsQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_PERMISSIONS_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        class GuildBankRemainingWithdrawMoneyQuery final : public ClientPacket
        {
        public:
            GuildBankRemainingWithdrawMoneyQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_REMAINING_WITHDRAW_MONEY_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        class GuildBankLogQuery final : public ClientPacket
        {
        public:
            GuildBankLogQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_LOG_QUERY, std::move(packet)) { }

            void Read() override;

            int32 Tab = 0;
        };

        class GuildBankSwapItems final : public ClientPacket
        {
        public:
            GuildBankSwapItems(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            int32 StackCount = 0;
            int32 BankItemCount = 0;
            uint32 ItemID = 0;
            uint32 ItemID1 = 0;
            uint8 ToSlot = 0;
            uint8 BankSlot = 0;
            uint8 BankSlot1 = 0;
            uint8 BankTab = 0;
            uint8 BankTab1 = 0;
            uint8 ContainerSlot = 0;
            uint8 ContainerItemSlot = 0;
            bool AutoStore = false;
            bool BankOnly = false;
        };

        class GuildBankTextQuery final : public ClientPacket
        {
        public:
            GuildBankTextQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_TEXT_QUERY, std::move(packet)) { }

            void Read() override;

            int32 Tab = 0;
        };

        class GuildBankSetTabText final : public ClientPacket
        {
        public:
            GuildBankSetTabText(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_SET_TAB_TEXT, std::move(packet)) { }

            void Read() override;

            int32 Tab = 0;
            std::string TabText;
        };

        class GuildXPQuery final : public ClientPacket
        {
        public:
            GuildXPQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_XP_QUERY, std::move(packet)) { }

            ObjectGuid GuildGUID;

            void Read() override;
        };

        struct GuildBankItemInfo
        {
            struct GuildBankSocketEnchant
            {
                int32 SocketIndex = 0;
                int32 SocketEnchantID = 0;
            };

            WorldPackets::Item::ItemInstance Item;
            int32 Slot = 0;
            int32 Count = 0;
            int32 EnchantmentID = 0;
            int32 Charges = 0;
            int32 OnUseEnchantmentID = 0;
            int32 ReforgeEnchantmentID = 0;
            int32 Flags = 0;
            bool Locked = false;
            std::vector<GuildBankSocketEnchant> SocketEnchant;
        };

        class GuildQueryRecipes final : public ClientPacket
        {
        public:
            GuildQueryRecipes(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_QUERY_RECIPES, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildGUID;
        };

        struct GuildBankTabInfo
        {
            int32 TabIndex = 0;
            std::string Name;
            std::string Icon;
        };

        class GuildBankQueryResults final : public ServerPacket
        {
        public:
            GuildBankQueryResults() : ServerPacket(SMSG_GUILD_BANK_QUERY_RESULTS, 25) { }

            WorldPacket const* Write() override;

            std::vector<GuildBankItemInfo> ItemInfo;
            std::vector<GuildBankTabInfo> TabInfo;
            int32 WithdrawalsRemaining = 0;
            int32 Tab = 0;
            uint64 Money = 0;
            bool FullUpdate = false;
        };

        class GuildEvent final : public ServerPacket
        {
        public:
            GuildEvent() : ServerPacket(SMSG_GUILD_EVENT, 3) { }

            WorldPacket const* Write() override;

            uint8 EventType = 0;
            std::vector<std::string> Param;
            ObjectGuid GUID;
        };

        class GuildMemberDailyReset final : public ServerPacket
        {
        public:
            GuildMemberDailyReset() : ServerPacket(SMSG_GUILD_MEMBER_DAILY_RESET, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class GuildReputationWeeklyCap final : public ServerPacket
        {
        public:
            GuildReputationWeeklyCap() : ServerPacket(SMSG_GUILD_REPUTATION_WEEKLY_CAP, 4) { }

            WorldPacket const* Write() override;

            uint32 Cap = 0;
        };

        class GuildXP final : public ServerPacket
        {
        public:
            GuildXP() : ServerPacket(SMSG_GUILD_XP, 40) { }

            WorldPacket const* Write() override;

            int64 WeeklyXP = 0;
            int64 TotalXP = 0;
            int64 GuildTodayXP = 0;
            int64 GuildRemainingXP = 0;
            int64 GuildCurrentXP = 0;
        };

        struct GuildRosterProfessionData
        {
            int32 DbID = 0;
            int32 Rank = 0;
            int32 Step = 0;
        };

        struct GuildRosterMemberData
        {
            ObjectGuid Guid;
            int64 WeeklyXP = 0;
            int64 TotalXP = 0;
            int32 RankID = 0;
            int32 AreaID = 0;
            int32 PersonalAchievementPoints = 0;
            int32 GuildReputation = 0;
            int32 GuildRepToCap = 0;
            float LastSave = 0.0f;
            std::string Name;
            uint32 VirtualRealmAddress = 0;
            std::string Note;
            std::string OfficerNote;
            uint8 Status = 0;
            uint8 Level = 0;
            uint8 ClassID = 0;
            uint8 Gender = 0;
            bool Authenticated = false;
            bool SorEligible = false;
            GuildRosterProfessionData Profession[2];
        };

        class GuildRoster final : public ServerPacket
        {
        public:
            GuildRoster() : ServerPacket(SMSG_GUILD_ROSTER, 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildRosterMemberData> MemberData;
            std::string WelcomeText;
            std::string InfoText;
            uint32 CreateDate = 0;
            int32 NumAccounts = 0;
            int32 GuildFlags = 0;
            int32 WeeklyRepCap = 0;
        };

        class GuildRosterUpdate final : public ServerPacket
        {
        public:
            GuildRosterUpdate() : ServerPacket(SMSG_GUILD_ROSTER_UPDATE, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildRosterMemberData> MemberData;
        };

        class GuildGetRoster final : public ClientPacket
        {
        public:
            GuildGetRoster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_ROSTER, std::move(packet)) { }

            void Read() override { }
        };

        struct GuildRecipesData
        {
            uint32 SkillLineID = 0;
            std::array<uint8, GUILD_RECIPES_COUNT> SkillLineBitArray = { };
        };

        class GuildKnownRecipes final : public ServerPacket
        {
        public:
            GuildKnownRecipes() : ServerPacket(SMSG_GUILD_KNOWN_RECIPES, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildRecipesData> Recipes;
        };

        class GuildQueryMembersForRecipe : public ClientPacket
        {
        public:
            GuildQueryMembersForRecipe(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_QUERY_MEMBERS_FOR_RECIPE, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildGUID;
            int32 UniqueBit = 0;
            int32 SkillLineID = 0;
            int32 SpellID = 0;
        };

        class GuildMembersWithRecipe final : public ServerPacket
        {
        public:
            GuildMembersWithRecipe() : ServerPacket(SMSG_GUILD_MEMBERS_WITH_RECIPE, 8) { }

            WorldPacket const* Write() override;

            int32 SpellID = 0;
            std::vector<ObjectGuid> Members;
            int32 SkillLineID = 0;
        };

        class GuildQueryMemberRecipes : public ClientPacket
        {
        public:
            GuildQueryMemberRecipes(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_QUERY_MEMBER_RECIPES, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildMember;
            ObjectGuid GuildGUID;
            int32 SkillLineID = 0;
        };

        class GuildMemberRecipes final : public ServerPacket
        {
        public:
            GuildMemberRecipes() : ServerPacket(SMSG_GUILD_MEMBER_RECIPES, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid Member;
            int32 SkillRank = 0;
            int32 SkillLineID = 0;
            int32 SkillStep = 0;
            std::array<uint8, GUILD_RECIPES_COUNT> SkillLineBitArray = { };
        };

        class RequestGuildRewardsList final : public ClientPacket
        {
        public:
            RequestGuildRewardsList(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_GUILD_REWARDS_LIST, std::move(packet)) { }

            void Read() override;

            uint32 CurrentVersion = 0;
        };

        struct GuildRewardItem
        {
            uint32 ItemID = 0;
            uint32 Unk4 = 0;
            uint32 AchievementRequired;
            uint32 RaceMask = 0;
            int32 MinGuildRep = 0;
            uint64 Cost = 0;
        };

        class GuildRewardList final : public ServerPacket
        {
        public:
            GuildRewardList() : ServerPacket(SMSG_GUILD_REWARD_LIST, 8) { }

            WorldPacket const* Write() override;

            std::vector<GuildRewardItem> RewardItems;
            int32 Version = 0;
        };

        class GuildChallengeUpdateRequest final : public ClientPacket
        {
        public:
            GuildChallengeUpdateRequest(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_REQUEST_CHALLENGE_UPDATE, std::move(packet)) { }

            void Read() override { }
        };

        class GuildChallengeUpdate final : public ServerPacket
        {
        public:
            GuildChallengeUpdate() : ServerPacket(SMSG_GUILD_CHALLENGE_UPDATE, 80) { }

            WorldPacket const* Write() override;

            std::array<int32, MAX_GUILD_CHALLENGE_TYPES> Xp = { };
            std::array<int32, MAX_GUILD_CHALLENGE_TYPES> CurrentCount = { };
            std::array<int32, MAX_GUILD_CHALLENGE_TYPES> MaxCount = { };
            std::array<int32, MAX_GUILD_CHALLENGE_TYPES> Gold = { };
            std::array<int32, MAX_GUILD_CHALLENGE_TYPES> MaxLevelGold = { };
        };

        class GuildChallengeCompleted final : public ServerPacket
        {
        public:
            GuildChallengeCompleted() : ServerPacket(SMSG_GUILD_CHALLENGE_COMPLETED, 20) { }

            WorldPacket const* Write() override;

            int32 MaxCount = 0;
            int32 ChallengeType = 0;
            int32 GoldAwarded = 0;
            int32 XpAwarded = 0;
            int32 CurrentCount = 0;
        };

        // SMSG_GUILD_COMMAND_RESULT_2 is the currently used opcode. SMSG_GUILD_COMMAND_RESULT is a JAM opcode but according to sniffs it has not been used yet
        class GuildCommandResult final : public ServerPacket
        {
        public:
            GuildCommandResult() : ServerPacket(SMSG_GUILD_COMMAND_RESULT_2, 9) { }

            WorldPacket const* Write() override;

            std::string Name;
            int32 Result = 0;
            int32 Command = 0;
        };

        class GuildBankTextQueryResult : public ServerPacket
        {
        public:
            GuildBankTextQueryResult() : ServerPacket(SMSG_GUILD_BANK_TEXT_QUERY_RESULT, 4 + 2) { }

            WorldPacket const* Write() override;

            int32 Tab = 0;
            std::string Text;
        };

        class GuildNameChanged final : ServerPacket
        {
        public:
            GuildNameChanged() : ServerPacket(SMSG_GUILD_NAME_CHANGED, 33) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            std::string GuildName;
        };

        struct GuildInfoRank
        {
            uint32 RankID = 0;
            uint32 RankOrder = 0;
            std::string RankName;
        };

        class QueryGuildInfoResponse final : ServerPacket
        {
        public:
            QueryGuildInfoResponse() : ServerPacket(SMSG_QUERY_GUILD_INFO_RESPONSE) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            std::string GuildName;

            std::array<GuildInfoRank, GUILD_RANKS_MAX_COUNT> Ranks;

            uint32 RanksSize = 0;
            uint32 EmblemStyle = 0;
            uint32 EmblemColor = 0;
            uint32 BorderStyle = 0;
            uint32 BorderColor = 0;
            uint32 BackgroundColor = 0;
        };

        struct GuildRankData
        {
            uint8 RankID = 0;
            int32 RankOrder = 0;
            uint32 Flags = 0;
            uint32 WithdrawGoldLimit = 0;
            std::string RankName;
            std::array<uint32, GUILD_BANK_MAX_TABS> TabFlags = { };
            std::array<uint32, GUILD_BANK_MAX_TABS> TabWithdrawItemLimit = { };
        };

        class GuildRanks final : public ServerPacket
        {
        public:
            GuildRanks() : ServerPacket(SMSG_GUILD_RANKS, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildRankData> Ranks;
        };

        class ReplaceGuildMaster final : public ClientPacket
        {
        public:
            ReplaceGuildMaster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_REPLACE_GUILD_MASTER, std::move(packet)) { }

            void Read() override { }
        };

        class SetGuildMaster final : public ClientPacket
        {
        public:
            SetGuildMaster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_GUILD_MASTER, std::move(packet)) { }

            void Read() override;

            bool IsDethrone = false;
            std::string NewMasterName;
        };

        struct GuildNewsEvent
        {
            int32 Id = 0;
            int32 Type = 0;
            int32 Flags = 0;
            uint32 CompletedDate = 0;
            std::array<int32, 2> Data = { };
            ObjectGuid MemberGuid;
            std::vector<ObjectGuid> MemberList;
        };

        class GuildNews final : public ServerPacket
        {
        public:
            GuildNews() : ServerPacket(SMSG_GUILD_NEWS, 25) { }

            WorldPacket const* Write() override;

            std::vector<GuildNewsEvent> NewsEvents;
        };

        struct GuildEventEntry
        {
            ObjectGuid PlayerGUID;
            ObjectGuid OtherGUID;
            uint8 TransactionType = 0;
            uint8 RankID = 0;
            uint32 TransactionDate = 0;
        };

        class GuildEventLogQueryResults final : public ServerPacket
        {
        public:
            GuildEventLogQueryResults() : ServerPacket(SMSG_GUILD_EVENT_LOG_QUERY_RESULTS, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildEventEntry> Entry;
        };

        struct GuildBankLogEntry
        {
            ObjectGuid PlayerGUID;
            uint32 TimeOffset = 0;
            int8 EntryType = 0;
            Optional<uint64> Money;
            Optional<int32> ItemID;
            Optional<int32> Count;
            Optional<int8> OtherTab;
        };

        class GuildBankLogQueryResults final : public ServerPacket
        {
        public:
            GuildBankLogQueryResults() : ServerPacket(SMSG_GUILD_BANK_LOG_QUERY_RESULTS, 25) { }

            WorldPacket const* Write() override;

            int32 Tab = 0;
            std::vector<GuildBankLogEntry> Entry;
            Optional<uint64> WeeklyBonusMoney;
        };

        class GuildReputationReactionChanged final : public ServerPacket
        {
        public:
            GuildReputationReactionChanged() : ServerPacket(SMSG_GUILD_REPUTATION_REACTION_CHANGED, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid MemberGUID;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterProfessionData const& rosterProfessionData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterMemberData const& rosterMemberData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRewardItem const& rewardItem);

#endif // GuildPackets_h__
