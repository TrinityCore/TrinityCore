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

#ifndef TRINITYCORE_LOOT_PACKETS_H
#define TRINITYCORE_LOOT_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace Loot
    {
        class LootUnit final : public ClientPacket
        {
        public:
            explicit LootUnit(WorldPacket&& packet) : ClientPacket(CMSG_LOOT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        struct LootItemData
        {
            uint8 LootListID = 0;
            uint8 UIType = 0;
            uint32 ItemID = 0;
            uint32 Quantity = 0;
            uint32 ItemDisplayInfoID = 0;
            int32 RandomPropertiesSeed = 0;
            int32 RandomPropertiesID = 0;
        };

        class LootResponse final : public ServerPacket
        {
        public:
            explicit LootResponse() : ServerPacket(SMSG_LOOT_RESPONSE, 100) { }

            WorldPacket const* Write() override;

            ObjectGuid Owner;
            uint8 AcquireReason  = 0;
            uint8 FailureReason  = 17;
            uint32 Coins = 0;
            std::vector<LootItemData> Items;
        };

        class LootItem final : public ClientPacket
        {
        public:
            explicit LootItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_LOOT_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 LootListID = 0;
        };

        class LootRemoved final : public ServerPacket
        {
        public:
            explicit LootRemoved() : ServerPacket(SMSG_LOOT_REMOVED, 1) { }

            WorldPacket const* Write() override;

            uint8 LootListID = 0;
        };

        class LootRelease final : public ClientPacket
        {
        public:
            explicit LootRelease(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_RELEASE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class LootMoney final : public ClientPacket
        {
        public:
            explicit LootMoney(WorldPacket&& packet) : ClientPacket(CMSG_LOOT_MONEY, std::move(packet)) { }

            void Read() override { }
        };

        class LootMoneyNotify final : public ServerPacket
        {
        public:
            explicit LootMoneyNotify() : ServerPacket(SMSG_LOOT_MONEY_NOTIFY, 4 + 1) { }

            WorldPacket const* Write() override;

            uint32 Money = 0;
            bool SoleLooter = false;
        };

        class CoinRemoved final : public ServerPacket
        {
        public:
            explicit CoinRemoved() : ServerPacket(SMSG_LOOT_CLEAR_MONEY, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };
    }
}

#endif
