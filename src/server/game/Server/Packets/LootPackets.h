/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef LootPackets_h__
#define LootPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "ItemPackets.h"

namespace WorldPackets
{
    namespace Loot
    {
        class LootUnit final : public ClientPacket
        {
        public:
            LootUnit(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_UNIT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        struct LootItemData
        {
            uint8 Type              = 2;
            uint8 UIType            = 7;
            uint32 Quantity         = 0;
            uint8 LootItemType      = 0;
            uint8 LootListID        = 0;
            bool CanTradeToTapList  = false;
            WorldPackets::Item::ItemInstance Loot;
        };

        struct LootCurrency
        {
            uint32 CurrencyID   = 0;
            uint32 Quantity     = 0;
            uint8 LootListID    = 0;
            uint8 UIType        = 0;
        };

        class LootResponse final : public ServerPacket
        {
        public:
            LootResponse() : ServerPacket(SMSG_LOOT_RESPONSE, 100) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            ObjectGuid Owner;
            uint8 Threshold      = 2; // Most common value, 2 = Uncommon
            uint8 LootMethod     = 0;
            uint8 AcquireReason  = 0;
            uint8 FailureReason  = 17; // Most common value
            uint32 Coins         = 0;
            std::vector<LootItemData> Items;
            std::vector<LootCurrency> Currencies;
            bool PersonalLooting = false;
            bool Acquired        = false;
            bool AELooting       = false;
        };

        struct LootRequest
        {
            ObjectGuid Object;
            uint8 LootListID = 0;
        };

        // PlayerCliLootItem
        class LootItem final : public ClientPacket
        {
        public:
            LootItem(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_ITEM, std::move(packet)) { }

            void Read() override;

            std::vector<LootRequest> Loot;
        };

        class LootRemoved final : public ServerPacket
        {
        public:
            LootRemoved() : ServerPacket(SMSG_LOOT_REMOVED, 30) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            ObjectGuid Owner;
            uint8 LootListID = 0;
        };

        class LootRelease final : public ClientPacket
        {
        public:
            LootRelease(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_RELEASE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class LootMoney final : public ClientPacket
        {
        public:
            LootMoney(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_MONEY, std::move(packet)) { }

            void Read() override { }
        };

        class LootMoneyNotify final : public ServerPacket
        {
        public:
            LootMoneyNotify() : ServerPacket(SMSG_LOOT_MONEY_NOTIFY, 5) { }

            WorldPacket const* Write() override;

            uint32 Money = 0;
            bool SoleLooter = false;
        };

        class CoinRemoved final : public ServerPacket
        {
        public:
            CoinRemoved() : ServerPacket(SMSG_COIN_REMOVED, 9) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
        };

        class LootRoll final : public ClientPacket
        {
        public:
            LootRoll(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_ROLL, std::move(packet)) { }

            void Read() override;

            ObjectGuid LootObj;
            uint8 LootListID = 0;
            uint8 RollType = 0;
        };

        class LootReleaseResponse final : public ServerPacket
        {
        public:
            LootReleaseResponse() : ServerPacket(SMSG_LOOT_RELEASE, 32) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            ObjectGuid Owner;
        };

        class LootList final : public ServerPacket
        {
        public:
            LootList() : ServerPacket(SMSG_LOOT_LIST, 3 * 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Owner;
            Optional<ObjectGuid> Master;
            Optional<ObjectGuid> RoundRobinWinner;
        };

        class SetLootSpecialization final : public ClientPacket
        {
        public:
            SetLootSpecialization(WorldPacket&& packet) : ClientPacket(CMSG_SET_LOOT_SPECIALIZATION, std::move(packet)) { }

            void Read() override;

            uint32 SpecID = 0;
        };
    }
}

#endif // LootPackets_h__
