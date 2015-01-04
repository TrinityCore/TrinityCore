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

#ifndef TRINITYCORE_ITEM_PACKETS_H
#define TRINITYCORE_ITEM_PACKETS_H

#include "ItemDefines.h"
#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace Item
    {
        class BuyBackItem final : public ClientPacket
        {
        public:
            explicit BuyBackItem(WorldPacket&& packet) : ClientPacket(CMSG_BUYBACK_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid VendorGUID;
            uint32 Slot = 0;
        };

        class GetItemPurchaseData final : public ClientPacket
        {
        public:
            explicit GetItemPurchaseData(WorldPacket&& packet) : ClientPacket(CMSG_ITEM_REFUND_INFO, std::move(packet)) { }

            void Read() override;

            ObjectGuid ItemGUID;
        };

        class RepairItem final : public ClientPacket
        {
        public:
            explicit RepairItem(WorldPacket&& packet) : ClientPacket(CMSG_REPAIR_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid NpcGUID;
            ObjectGuid ItemGUID;
            bool UseGuildBank = false;
        };

        class SellItem final : public ClientPacket
        {
        public:
            explicit SellItem(WorldPacket&& packet) : ClientPacket(CMSG_SELL_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid VendorGUID;
            ObjectGuid ItemGUID;
            uint32 Amount = 0;
        };

        class SetProficiency final : public ServerPacket
        {
        public:
            explicit SetProficiency() : ServerPacket(SMSG_SET_PROFICIENCY, 1 + 4) { }

            WorldPacket const* Write() override;

            uint32 ProficiencyMask = 0;
            uint8 ProficiencyClass = 0;
        };

        class InventoryChangeFailure final : public ServerPacket
        {
        public:
            explicit InventoryChangeFailure() : ServerPacket(SMSG_INVENTORY_CHANGE_FAILURE, 22) { }

            WorldPacket const* Write() override;

            uint8 BagResult = EQUIP_ERR_OK; /// @see enum InventoryResult
            uint8 ContainerBSlot = 0;
            ObjectGuid SrcContainer;
            ObjectGuid DstContainer;
            int32 SrcSlot = 0;
            int32 LimitCategory = 0;
            int32 Level = 0;
            ObjectGuid Item[2];
        };

        class SplitItem final : public ClientPacket
        {
        public:
            explicit SplitItem(WorldPacket&& packet) : ClientPacket(CMSG_SPLIT_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 ToSlot = 0;
            uint8 ToPackSlot = 0;
            uint8 FromPackSlot = 0;
            int32 Quantity = 0;
            uint8 FromSlot = 0;
        };

        class SwapInvItem final : public ClientPacket
        {
        public:
            explicit SwapInvItem(WorldPacket&& packet) : ClientPacket(CMSG_SWAP_INV_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 Slot1 = 0; /// Source Slot
            uint8 Slot2 = 0; /// Destination Slot
        };

        class SwapItem final : public ClientPacket
        {
        public:
            explicit SwapItem(WorldPacket&& packet) : ClientPacket(CMSG_SWAP_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 SlotA = 0;
            uint8 ContainerSlotB = 0;
            uint8 SlotB = 0;
            uint8 ContainerSlotA = 0;
        };

        class AutoEquipItem final : public ClientPacket
        {
        public:
            explicit AutoEquipItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOEQUIP_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 Slot = 0;
            uint8 PackSlot = 0;
        };

        class DestroyItem final : public ClientPacket
        {
        public:
            explicit DestroyItem(WorldPacket&& packet) : ClientPacket(CMSG_DESTROYITEM, std::move(packet)) { }

            void Read() override;

            uint32 Count = 0;
            uint8 SlotNum = 0;
            uint8 ContainerId = 0;
        };
    }
}

#endif // TRINITYCORE_ITEM_PACKETS_H
