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
#include "Guild.h"
#include "ObjectGuid.h"
#include "PacketUtilities.h"

namespace WorldPackets
{
    namespace Guild
    {
        class QueryGuildInfo final : public ClientPacket
        {
        public:
            QueryGuildInfo(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_GUILD_INFO, std::move(packet)) { }

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
            ObjectGuid PlayerGuid;
            Optional<GuildInfo> Info;
        };

        class GuildGetRoster final : public ClientPacket
        {
        public:
            GuildGetRoster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_ROSTER, std::move(packet)) { }

            void Read() override { }
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
        };

        class GuildRosterUpdate final : public ServerPacket
        {
        public:
            GuildRosterUpdate() : ServerPacket(SMSG_GUILD_ROSTER_UPDATE, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildRosterMemberData> MemberData;
        };

        class GuildUpdateMotdText final : public ClientPacket
        {
        public:
            GuildUpdateMotdText(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_UPDATE_MOTD_TEXT, std::move(packet)) { }

            void Read() override;

            std::string MotdText;
        };

        class GuildCommandResult final : public ServerPacket
        {
        public:
            GuildCommandResult() : ServerPacket(SMSG_GUILD_COMMAND_RESULT, 9) { }

            WorldPacket const* Write() override;

            std::string Name;
            int32 Result = 0;
            int32 Command = 0;
        };

        class AcceptGuildInvite final : public ClientPacket
        {
        public:
            AcceptGuildInvite(WorldPacket&& packet) : ClientPacket(CMSG_ACCEPT_GUILD_INVITE, std::move(packet)) { }

            void Read() override { }
        };

        class GuildDeclineInvitation final : public ClientPacket
        {
        public:
            GuildDeclineInvitation(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_DECLINE_INVITATION, std::move(packet)) { }

            void Read() override { }
        };

        class DeclineGuildInvites final : public ClientPacket
        {
        public:
            DeclineGuildInvites(WorldPacket&& packet) : ClientPacket(CMSG_DECLINE_GUILD_INVITES, std::move(packet)) { }

            void Read() override;

            bool Allow = false;
        };

        class GuildInviteByName final : public ClientPacket
        {
        public:
            GuildInviteByName(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_INVITE_BY_NAME, std::move(packet)) { }

            void Read() override;

            std::string Name;
        };

        class GuildInvite final : public ServerPacket
        {
        public:
            GuildInvite() : ServerPacket(SMSG_GUILD_INVITE, 68) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            ObjectGuid OldGuildGUID;
            int32 AchievementPoints = 0;
            uint32 EmblemColor = 0;
            uint32 EmblemStyle = 0;
            uint32 BorderStyle = 0;
            uint32 BorderColor = 0;
            uint32 Background = 0;
            uint32 GuildVirtualRealmAddress = 0;
            uint32 OldGuildVirtualRealmAddress = 0;
            uint32 InviterVirtualRealmAddress = 0;
            std::string InviterName;
            std::string GuildName;
            std::string OldGuildName;
        };

        class GuildEventStatusChange final : public ServerPacket
        {
        public:
            GuildEventStatusChange() : ServerPacket(SMSG_GUILD_EVENT_STATUS_CHANGE, 16 + 1) {  }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            bool AFK = false;
            bool DND = false;
        };

        class GuildEventPresenceChange final : public ServerPacket
        {
        public:
            GuildEventPresenceChange() : ServerPacket(SMSG_GUILD_EVENT_PRESENCE_CHANGE, 16 + 4 + 1 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            uint32 VirtualRealmAddress = 0;
            std::string Name;
            bool Mobile = false;
            bool LoggedOn = false;
        };

        class GuildEventMotd final : public ServerPacket
        {
        public:
            GuildEventMotd() : ServerPacket(SMSG_GUILD_EVENT_MOTD, 1) { }

            WorldPacket const* Write() override;

            std::string MotdText;
        };

        class GuildEventPlayerJoined final : public ServerPacket
        {
        public:
            GuildEventPlayerJoined() : ServerPacket(SMSG_GUILD_EVENT_PLAYER_JOINED, 21) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            std::string Name;
            uint32 VirtualRealmAddress = 0;
        };

        class GuildEventRankChanged final : public ServerPacket
        {
        public:
            GuildEventRankChanged() : ServerPacket(SMSG_GUILD_EVENT_RANK_CHANGED, 4) { }

            WorldPacket const* Write() override;

            int32 RankID = 0;
        };

        class GuildEventRanksUpdated final : public ServerPacket
        {
        public:
            GuildEventRanksUpdated() : ServerPacket(SMSG_GUILD_EVENT_RANKS_UPDATED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class GuildEventBankMoneyChanged final : public ServerPacket
        {
        public:
            GuildEventBankMoneyChanged() : ServerPacket(SMSG_GUILD_EVENT_BANK_MONEY_CHANGED, 8) { }

            WorldPacket const* Write() override;

            uint64 Money = 0;
        };

        class GuildEventDisbanded final : public ServerPacket
        {
        public:
            GuildEventDisbanded() : ServerPacket(SMSG_GUILD_EVENT_DISBANDED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        struct GuildEventEntry
        {
            ObjectGuid PlayerGUID;
            ObjectGuid OtherGUID;
            uint8 TransactionType = 0;
            uint8 RankID = 0;
            uint32 TransactionDate = 0;
        };

        class GuildEventLogQuery final : public ClientPacket
        {
        public:
            GuildEventLogQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_EVENT_LOG_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        class GuildEventLogQueryResults final : public ServerPacket
        {
        public:
            GuildEventLogQueryResults() : ServerPacket(SMSG_GUILD_EVENT_LOG_QUERY_RESULTS, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildEventEntry> Entry;
        };

        class GuildEventPlayerLeft final : public ServerPacket
        {
        public:
            GuildEventPlayerLeft() : ServerPacket(SMSG_GUILD_EVENT_PLAYER_LEFT, 43) { }

            WorldPacket const* Write() override;

            ObjectGuid LeaverGUID;
            std::string LeaverName;
            uint32 LeaverVirtualRealmAddress = 0;
            ObjectGuid RemoverGUID;
            std::string RemoverName;
            uint32 RemoverVirtualRealmAddress = 0;
            bool Removed = false;
        };

        class GuildEventNewLeader final : public ServerPacket
        {
        public:
            GuildEventNewLeader() : ServerPacket(SMSG_GUILD_EVENT_NEW_LEADER, 43) { }

            WorldPacket const* Write() override;

            ObjectGuid NewLeaderGUID;
            std::string NewLeaderName;
            uint32 NewLeaderVirtualRealmAddress = 0;
            ObjectGuid OldLeaderGUID;
            std::string OldLeaderName;
            uint32 OldLeaderVirtualRealmAddress = 0;
            bool SelfPromoted = false;
        };

        class GuildEventTabAdded final : public ServerPacket
        {
        public:
            GuildEventTabAdded() : ServerPacket(SMSG_GUILD_EVENT_TAB_ADDED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class GuildEventTabModified final : public ServerPacket
        {
        public:
            GuildEventTabModified() : ServerPacket(SMSG_GUILD_EVENT_TAB_MODIFIED, 6) { }

            WorldPacket const* Write() override;

            std::string Icon;
            std::string Name;
            int32 Tab = 0;
        };

        class GuildEventTabTextChanged final : public ServerPacket
        {
        public:
            GuildEventTabTextChanged() : ServerPacket(SMSG_GUILD_EVENT_TAB_TEXT_CHANGED, 4) { }

            WorldPacket const* Write() override;

            int32 Tab = 0;
        };

        class GuildEventBankContentsChanged final : public ServerPacket
        {
        public:
            GuildEventBankContentsChanged() : ServerPacket(SMSG_GUILD_EVENT_BANK_CONTENTS_CHANGED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class GuildPermissionsQuery final : public ClientPacket
        {
        public:
            GuildPermissionsQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_PERMISSIONS_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        class GuildPermissionsQueryResults final : public ServerPacket
        {
        public:
            struct GuildRankTabPermissions
            {
                int32 Flags = 0;
                int32 WithdrawItemLimit = 0;
            };

            GuildPermissionsQueryResults() : ServerPacket(SMSG_GUILD_PERMISSIONS_QUERY_RESULTS, 20) { }

            WorldPacket const* Write() override;

            int32 NumTabs = 0;
            int32 WithdrawGoldLimit = 0;
            int32 Flags = 0;
            uint32 RankID = 0;
            std::vector<GuildRankTabPermissions> Tab;
        };

        class GuildSetRankPermissions final : public ClientPacket
        {
        public:
            GuildSetRankPermissions(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_RANK_PERMISSIONS, std::move(packet)) { }

            void Read() override;

            uint8 RankID = 0;
            int32 RankOrder = 0;
            uint32 WithdrawGoldLimit = 0;
            uint32 Flags = 0;
            uint32 OldFlags = 0;
            uint32 TabFlags[GUILD_BANK_MAX_TABS];
            uint32 TabWithdrawItemLimit[GUILD_BANK_MAX_TABS];
            std::string RankName;
        };

        class GuildAddRank final : public ClientPacket
        {
        public:
            GuildAddRank(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_ADD_RANK, std::move(packet)) { }

            void Read() override;

            std::string Name;
            int32 RankOrder = 0;
        };

        class GuildAssignMemberRank final : public ClientPacket
        {
        public:
            GuildAssignMemberRank(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_ASSIGN_MEMBER_RANK, std::move(packet)) { }

            void Read() override;

            ObjectGuid Member;
            int32 RankOrder = 0;
        };

        class GuildDeleteRank final : public ClientPacket
        {
        public:
            GuildDeleteRank(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_DELETE_RANK, std::move(packet)) { }

            void Read() override;

            int32 RankOrder = 0;
        };

        class GuildGetRanks final : public ClientPacket
        {
        public:
            GuildGetRanks(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_RANKS, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildGUID;
        };

        struct GuildRankData
        {
            uint8 RankID = 0;
            int32 RankOrder = 0;
            uint32 Flags = 0;
            uint32 WithdrawGoldLimit = 0;
            std::string RankName;
            uint32 TabFlags[GUILD_BANK_MAX_TABS];
            uint32 TabWithdrawItemLimit[GUILD_BANK_MAX_TABS];
        };

        class GuildRanks final : public ServerPacket
        {
        public:
            GuildRanks() : ServerPacket(SMSG_GUILD_RANKS, 4) { }

            WorldPacket const* Write() override;

            std::vector<GuildRankData> Ranks;
        };

        class GuildSendRankChange final : public ServerPacket
        {
        public:
            GuildSendRankChange() : ServerPacket(SMSG_GUILD_SEND_RANK_CHANGE, 43) { }

            WorldPacket const* Write() override;

            ObjectGuid Other;
            ObjectGuid Officer;
            bool Promote = false;
            uint32 RankID = 0;
        };

        class GuildShiftRank final : public ClientPacket
        {
        public:
            GuildShiftRank(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SHIFT_RANK, std::move(packet)) { }

            void Read() override;

            bool ShiftUp = false;
            int32 RankOrder = 0;
        };

        class GuildUpdateInfoText final : public ClientPacket
        {
        public:
            GuildUpdateInfoText(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_UPDATE_INFO_TEXT, std::move(packet)) { }

            void Read() override;

            std::string InfoText;
        };

        class GuildSetMemberNote final : public ClientPacket
        {
        public:
            GuildSetMemberNote(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_MEMBER_NOTE, std::move(packet)) { }

            void Read() override;

            ObjectGuid NoteeGUID;
            bool IsPublic = false;          ///< 0 == Officer, 1 == Public
            std::string Note;
        };

        class GuildMemberUpdateNote final : public ServerPacket
        {
        public:
            GuildMemberUpdateNote() : ServerPacket(SMSG_GUILD_MEMBER_UPDATE_NOTE, 21) { }

            WorldPacket const* Write() override;

            ObjectGuid Member;
            bool IsPublic = false;          ///< 0 == Officer, 1 == Public
            std::string Note;
        };

        class GuildMemberDailyReset final : public ServerPacket
        {
        public:
            GuildMemberDailyReset() : ServerPacket(SMSG_GUILD_MEMBER_DAILY_RESET, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class GuildDelete final : public ClientPacket
        {
        public:
            GuildDelete(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_DELETE, std::move(packet)) { }

            void Read() override { }
        };

        class GuildDemoteMember final : public ClientPacket
        {
        public:
            GuildDemoteMember(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_DEMOTE_MEMBER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Demotee;
        };

        class GuildPromoteMember final : public ClientPacket
        {
        public:
            GuildPromoteMember(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_PROMOTE_MEMBER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Promotee;
        };

        class GuildOfficerRemoveMember : public ClientPacket
        {
        public:
            GuildOfficerRemoveMember(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_OFFICER_REMOVE_MEMBER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Removee;
        };

        class GuildLeave final : public ClientPacket
        {
        public:
            GuildLeave(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_LEAVE, std::move(packet)) { }

            void Read() override { }
        };

        class GuildChangeNameRequest final : public ClientPacket
        {
        public:
            GuildChangeNameRequest(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_CHANGE_NAME_REQUEST, std::move(packet)) { }

            void Read() override;

            std::string NewName;
        };

        class GuildFlaggedForRename final : public ServerPacket
        {
        public:
            GuildFlaggedForRename() : ServerPacket(SMSG_GUILD_FLAGGED_FOR_RENAME, 1) { }

            WorldPacket const* Write() override;

            bool FlagSet = false;
        };

        class RequestGuildPartyState final : public ClientPacket
        {
        public:
            RequestGuildPartyState(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_GUILD_PARTY_STATE, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildGUID;
        };

        class GuildPartyState final : public ServerPacket
        {
        public:
            GuildPartyState() : ServerPacket(SMSG_GUILD_PARTY_STATE, 15) { }

            WorldPacket const* Write() override;

            float GuildXPEarnedMult = 0.0f;
            int32 NumMembers = 0;
            int32 NumRequired = 0;
            bool InGuildParty = false;
        };

        class RequestGuildRewardsList final : public ClientPacket
        {
        public:
            RequestGuildRewardsList(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_GUILD_REWARDS_LIST, std::move(packet)) { }

            void Read() override;

            Timestamp<> CurrentVersion;
        };

        struct GuildRewardItem
        {
            uint32 ItemID = 0;
            uint32 Unk4 = 0;
            std::vector<uint32> AchievementsRequired;
            Trinity::RaceMask<uint64> RaceMask = { 0 };
            int32 MinGuildLevel = 0;
            int32 MinGuildRep = 0;
            uint64 Cost = 0;
        };

        class GuildRewardList final : public ServerPacket
        {
        public:
            GuildRewardList() : ServerPacket(SMSG_GUILD_REWARD_LIST, 8) { }

            WorldPacket const* Write() override;

            std::vector<GuildRewardItem> RewardItems;
            Timestamp<> Version;
        };

        class GuildBankActivate final : public ClientPacket
        {
        public:
            GuildBankActivate(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_ACTIVATE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
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

        class GuildBankQueryTab final : public ClientPacket
        {
        public:
            GuildBankQueryTab(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_QUERY_TAB, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint8 Tab = 0;
            bool FullUpdate = false;
        };


        class GuildBankRemainingWithdrawMoneyQuery final : public ClientPacket
        {
        public:
            GuildBankRemainingWithdrawMoneyQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_REMAINING_WITHDRAW_MONEY_QUERY, std::move(packet)) { }

            void Read() override { }
        };

        class GuildBankRemainingWithdrawMoney final : public ServerPacket
        {
        public:
            GuildBankRemainingWithdrawMoney() : ServerPacket(SMSG_GUILD_BANK_REMAINING_WITHDRAW_MONEY, 8) { }

            WorldPacket const* Write() override;

            int64 RemainingWithdrawMoney = 0;
        };

        class GuildBankWithdrawMoney final : public ClientPacket
        {
        public:
            GuildBankWithdrawMoney(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_WITHDRAW_MONEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            uint64 Money = 0;
        };

        struct GuildBankItemInfo
        {
            WorldPackets::Item::ItemInstance Item;
            int32 Slot = 0;
            int32 Count = 0;
            int32 EnchantmentID = 0;
            int32 Charges = 0;
            int32 OnUseEnchantmentID = 0;
            int32 Flags = 0;
            bool Locked = false;
            std::vector<Item::ItemGemData> SocketEnchant;
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

        // TODO: research new guild bank opcodes
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

        class GuildBankLogQuery final : public ClientPacket
        {
        public:
            GuildBankLogQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_LOG_QUERY, std::move(packet)) { }

            void Read() override;

            int32 Tab = 0;
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

        class GuildBankTextQuery final : public ClientPacket
        {
        public:
            GuildBankTextQuery(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_TEXT_QUERY, std::move(packet)) { }

            void Read() override;

            int32 Tab = 0;
        };

        class GuildBankTextQueryResult : public ServerPacket
        {
        public:
            GuildBankTextQueryResult() : ServerPacket(SMSG_GUILD_BANK_TEXT_QUERY_RESULT, 4 + 2) { }

            WorldPacket const* Write() override;

            int32 Tab = 0;
            std::string Text;
        };

        class GuildBankSetTabText final : public ClientPacket
        {
        public:
            GuildBankSetTabText(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_BANK_SET_TAB_TEXT, std::move(packet)) { }

            void Read() override;

            int32 Tab = 0;
            std::string TabText;
        };

        class GuildQueryNews final : public ClientPacket
        {
        public:
            GuildQueryNews(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_QUERY_NEWS, std::move(packet)) { }

            void Read() override;

            ObjectGuid GuildGUID;
        };

        struct GuildNewsEvent
        {
            int32 Id = 0;
            uint32 CompletedDate = 0;
            int32 Type = 0;
            int32 Flags = 0;
            std::array<int32, 2> Data = { };
            ObjectGuid MemberGuid;
            std::vector<ObjectGuid> MemberList;
            Optional<Item::ItemInstance> Item;
        };

        class GuildNews final : public ServerPacket
        {
        public:
            GuildNews() : ServerPacket(SMSG_GUILD_NEWS, 25) { }

            WorldPacket const* Write() override;

            std::vector<GuildNewsEvent> NewsEvents;
        };

        class GuildNewsUpdateSticky final : public ClientPacket
        {
        public:
            GuildNewsUpdateSticky(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_NEWS_UPDATE_STICKY, std::move(packet)) { }

            void Read() override;

            int32 NewsID = 0;
            ObjectGuid GuildGUID;
            bool Sticky = false;
        };

        class GuildReplaceGuildMaster final : public ClientPacket
        {
        public:
            GuildReplaceGuildMaster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_REPLACE_GUILD_MASTER, std::move(packet)) { }

            void Read() override { }
        };

        class GuildSetGuildMaster final : public ClientPacket
        {
        public:
            GuildSetGuildMaster(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_GUILD_MASTER, std::move(packet)) { }

            void Read() override;

            std::string NewMasterName;
        };

        class GuildChallengeUpdateRequest final : public ClientPacket
        {
        public:
            GuildChallengeUpdateRequest(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_CHALLENGE_UPDATE_REQUEST, std::move(packet)) { }

            void Read() override { }
        };

        class GuildChallengeUpdate final : public ServerPacket
        {
        public:
            GuildChallengeUpdate() : ServerPacket(SMSG_GUILD_CHALLENGE_UPDATE, 96) { }

            WorldPacket const* Write() override;

            int32 CurrentCount[GUILD_CHALLENGES_TYPES];
            int32 MaxCount[GUILD_CHALLENGES_TYPES];
            int32 Gold[GUILD_CHALLENGES_TYPES];
            int32 MaxLevelGold[GUILD_CHALLENGES_TYPES];
        };

        class SaveGuildEmblem final : public ClientPacket
        {
        public:
            SaveGuildEmblem(WorldPacket&& packet) : ClientPacket(CMSG_SAVE_GUILD_EMBLEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vendor;
            int32 BStyle = 0;
            int32 EStyle = 0;
            int32 BColor = 0;
            int32 EColor = 0;
            int32 Bg = 0;
        };

        class PlayerSaveGuildEmblem final : public ServerPacket
        {
        public:
            PlayerSaveGuildEmblem() : ServerPacket(SMSG_PLAYER_SAVE_GUILD_EMBLEM, 4) { }

            WorldPacket const* Write() override;

            int32 Error = 0;
        };

        class GuildSetAchievementTracking final : public ClientPacket
        {
        public:
            GuildSetAchievementTracking(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_ACHIEVEMENT_TRACKING, std::move(packet)) { }

            void Read() override;

            Array<uint32, 10> AchievementIDs;
        };

        class GuildNameChanged final : ServerPacket
        {
        public:
            GuildNameChanged() : ServerPacket(SMSG_GUILD_NAME_CHANGED, 40) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            std::string GuildName;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterProfessionData const& rosterProfessionData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterMemberData const& rosterMemberData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRankData const& rankData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRewardItem const& rewardItem);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildNewsEvent const& newsEvent);

#endif // GuildPackets_h__
