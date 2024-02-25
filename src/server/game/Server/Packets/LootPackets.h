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

enum class LootRollIneligibilityReason : uint32;

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
            uint8 Type              = 0;
            uint8 UIType            = 0;
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
            uint8 _LootMethod    = 0; ///< @see enum LootMethod
            uint8 AcquireReason  = 0;
            uint8 FailureReason  = 17; // Most common value
            uint32 Coins         = 0;
            std::vector<LootItemData> Items;
            std::vector<LootCurrency> Currencies;
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

            Array<LootRequest, 1000> Loot;
            bool IsSoftInteract = false;
        };

        class MasterLootItem final : public ClientPacket
        {
        public:
            MasterLootItem(WorldPacket&& packet) : ClientPacket(CMSG_MASTER_LOOT_ITEM, std::move(packet)) { }

            void Read() override;

            Array<LootRequest, 1000> Loot;
            ObjectGuid Target;
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

            void Read() override;

            bool IsSoftInteract = false;
        };

        class LootMoneyNotify final : public ServerPacket
        {
        public:
            LootMoneyNotify() : ServerPacket(SMSG_LOOT_MONEY_NOTIFY, 5) { }

            WorldPacket const* Write() override;

            uint64 Money = 0;
            uint64 MoneyMod = 0;
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

        class LootReleaseAll final : public ServerPacket
        {
        public:
            LootReleaseAll() : ServerPacket(SMSG_LOOT_RELEASE_ALL, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class LootList final : public ServerPacket
        {
        public:
            LootList() : ServerPacket(SMSG_LOOT_LIST, 3 * 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Owner;
            ObjectGuid LootObj;
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

        class StartLootRoll final : public ServerPacket
        {
        public:
            StartLootRoll() : ServerPacket(SMSG_START_LOOT_ROLL) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            int32 MapID = 0;
            Duration<Milliseconds, uint32> RollTime;
            uint8 Method = 0;
            uint8 ValidRolls = 0;
            std::array<LootRollIneligibilityReason, 5> LootRollIneligibleReason = { };
            LootItemData Item;
            int32 DungeonEncounterID = 0;
        };

        class LootRollBroadcast final : public ServerPacket
        {
        public:
            LootRollBroadcast() : ServerPacket(SMSG_LOOT_ROLL) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            ObjectGuid Player;
            int32 Roll = 0;             ///< Roll value can be negative, it means that it is an "offspec" roll but only during roll selection broadcast (not when sending the result)
            uint8 RollType = 0;
            LootItemData Item;
            bool Autopassed = false;    ///< Triggers message |HlootHistory:%d|h[Loot]|h: You automatically passed on: %s because you cannot loot that item.
            bool OffSpec = false;
            int32 DungeonEncounterID = 0;
        };

        class LootRollWon final : public ServerPacket
        {
        public:
            LootRollWon() : ServerPacket(SMSG_LOOT_ROLL_WON) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            ObjectGuid Winner;
            int32 Roll = 0;
            uint8 RollType = 0;
            LootItemData Item;
            bool MainSpec = false;
            int32 DungeonEncounterID = 0;
        };

        class LootAllPassed final : public ServerPacket
        {
        public:
            LootAllPassed() : ServerPacket(SMSG_LOOT_ALL_PASSED) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            LootItemData Item;
            int32 DungeonEncounterID = 0;
        };

        class LootRollsComplete final : public ServerPacket
        {
        public:
            LootRollsComplete() : ServerPacket(SMSG_LOOT_ROLLS_COMPLETE, 16 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid LootObj;
            uint8 LootListID = 0;
            int32 DungeonEncounterID = 0;
        };

        class MasterLootCandidateList final : public ServerPacket
        {
        public:
            MasterLootCandidateList() : ServerPacket(SMSG_MASTER_LOOT_CANDIDATE_LIST, 18 + 40 * 18) { }

            WorldPacket const* Write() override;

            GuidUnorderedSet Players;
            ObjectGuid LootObj;
        };

        class AELootTargets final : public ServerPacket
        {
        public:
            AELootTargets(uint32 count) : ServerPacket(SMSG_AE_LOOT_TARGETS, 4), Count(count) { }

            WorldPacket const* Write() override;

            uint32 Count = 0;
        };

        class AELootTargetsAck final : public ServerPacket
        {
        public:
            AELootTargetsAck() : ServerPacket(SMSG_AE_LOOT_TARGET_ACK, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };
    }
}

#endif // LootPackets_h__
