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

#ifndef LootPackets_h__
#define LootPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "ItemPacketsCommon.h"

namespace WorldPackets
{
    namespace Loot
    {
        class LootMoneyNotify final : public ServerPacket
        {
        public:
            LootMoneyNotify() : ServerPacket(SMSG_LOOT_MONEY_NOTIFY, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 Money = 0;
            bool SoleLooter = false;
        };

        class CoinRemoved final : public ServerPacket
        {
        public:
            CoinRemoved() : ServerPacket(SMSG_COIN_REMOVED, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; };
        };

        class LootRemoved final : public ServerPacket
        {
        public:
            LootRemoved() : ServerPacket(SMSG_LOOT_REMOVED, 1) { }

            WorldPacket const* Write() override;

            uint8 LootListID = 0;
        };

        class LootReleaseResponse final : public ServerPacket
        {
        public:
            LootReleaseResponse() : ServerPacket(SMSG_LOOT_RELEASE, 8 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            bool UnkBool = true;
        };

        class LootList final : public ServerPacket
        {
        public:
            LootList() : ServerPacket(SMSG_LOOT_LIST, 8 + 8 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Owner;
            ObjectGuid Master;
            ObjectGuid RoundRobinWinner;
        };

        class DisenchantCredit final : public ServerPacket
        {
        public:
            DisenchantCredit() : ServerPacket(SMSG_DISENCHANT_CREDIT, 8 + 12) { }

            WorldPacket const* Write() override;

            ObjectGuid Disenchanter;
            WorldPackets::Item::ItemInstance Item;
        };

        struct LootItemData
        {
            uint8 Type              = 0;
            uint8 UIType            = 0;
            uint32 Quantity         = 0;
            uint8 LootItemType      = 0;
            uint8 LootListID        = 0;
            WorldPackets::Item::ItemInstance Loot;
        };

        struct LootCurrency
        {
            uint32 CurrencyID   = 0;
            uint32 Quantity     = 0;
            uint8 LootListID    = 0;
        };

        class LootResponse final : public ServerPacket
        {
        public:
            LootResponse() : ServerPacket(SMSG_LOOT_RESPONSE, 100) { }

            WorldPacket const* Write() override;

            ObjectGuid Owner;
            uint8 Threshold      = 2; // Most common value, 2 = Uncommon
            uint8 AcquireReason  = 0;
            uint8 FailureReason  = 17; // Most common value
            uint32 Coins         = 0;
            std::vector<LootItemData> Items;
            std::vector<LootCurrency> Currencies;
        };

        class LootContents final : public ServerPacket
        {
        public:
            LootContents() : ServerPacket(SMSG_LOOT_CONTENTS, 1) { }

            WorldPacket const* Write() override;

            std::vector<LootItemData> Items;
        };
    }
}

#endif // LootPackets_h__
