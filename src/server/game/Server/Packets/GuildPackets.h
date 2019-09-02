/*
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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
            int64 GuildCurrentXP;
        };
    }
}

#endif // GuildPackets_h__
