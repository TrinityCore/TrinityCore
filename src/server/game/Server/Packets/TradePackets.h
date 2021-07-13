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

#ifndef TradePackets_h__
#define TradePackets_h__

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include <array>

namespace WorldPackets
{
    namespace Trade
    {
        class InitiateTrade final : public ClientPacket
        {
        public:
            InitiateTrade(WorldPacket&& packet) : ClientPacket(CMSG_INITIATE_TRADE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class TradeStatus final : public ServerPacket
        {
        public:
            TradeStatus() : ServerPacket(SMSG_TRADE_STATUS, 1 + 1 + 8 + 4 + 4 + 1 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ::TradeStatus Status = TRADE_STATUS_INITIATED;
            ObjectGuid Partner;
            int32 CurrencyType = 0;
            int32 CurrencyQuantity = 0;
            int32 BagResult = 0;
            uint32 ItemID = 0;
            uint32 ID = 0;
            uint8 TradeSlot = 0;
            bool FailureForYou = false;
            bool PartnerIsSameBnetAccount = false;
        };

        struct UnwrappedTradeItem
        {
            Item::ItemInstance Item;
            ObjectGuid Creator;
            int32 EnchantID = 0;
            int32 ReforgeEnchantmentID = 0;
            int32 Charges = 0;
            uint32 MaxDurability = 0;
            uint32 Durability = 0;
            std::array<int32, 3> SocketEnchant = { };
            bool Lock = false;
        };

        struct TradeItem
        {
            uint8 Slot = 0;
            int32 EntryID = 0;
            int32 StackCount = 0;
            ObjectGuid GiftCreator;
            Optional<UnwrappedTradeItem> Unwrapped;
        };

        class TradeUpdated final : public ServerPacket
        {
        public:
            TradeUpdated() : ServerPacket(SMSG_TRADE_UPDATED, 4 + 4 + 8 + 4 + 4 + 4 + 1 + 4 + 3) { }

            WorldPacket const* Write() override;

            uint64 Gold = 0;
            uint32 ID = 0;
            uint32 CurrentStateIndex = 0;
            uint32 ClientStateIndex = 0;
            int32 CurrencyType = 0;
            int32 CurrencyQuantity = 0;
            int32 ProposedEnchantment = 0;
            uint8 WhichPlayer = 0;
            std::vector<TradeItem> Items;
        };

        class AcceptTrade final : public ClientPacket
        {
        public:
            AcceptTrade(WorldPacket&& packet) : ClientPacket(CMSG_ACCEPT_TRADE, std::move(packet)) { }

            void Read() override;

            uint32 StateIndex = 0;
        };
    }
}

#endif
