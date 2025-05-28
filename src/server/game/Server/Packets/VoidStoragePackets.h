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

#ifndef TRINITYCORE_VOID_STORAGE_PACKETS_H
#define TRINITYCORE_VOID_STORAGE_PACKETS_H

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"

namespace WorldPackets
{
    namespace VoidStorage
    {
        class VoidTransferResult final : public ServerPacket
        {
        public:
            explicit VoidTransferResult(int32 result) : ServerPacket(SMSG_VOID_TRANSFER_RESULT, 4), Result(result) { }

            WorldPacket const* Write() override;

            int32 Result;
        };

        class UnlockVoidStorage final : public ClientPacket
        {
        public:
            explicit UnlockVoidStorage(WorldPacket&& packet) : ClientPacket(CMSG_UNLOCK_VOID_STORAGE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
        };

        class QueryVoidStorage final : public ClientPacket
        {
        public:
            explicit QueryVoidStorage(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_VOID_STORAGE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
        };

        class VoidStorageFailed final : public ServerPacket
        {
        public:
            explicit VoidStorageFailed() : ServerPacket(SMSG_VOID_STORAGE_FAILED, 1) { }

            WorldPacket const* Write() override;

            uint8 Reason = 0;
        };

        struct VoidItem
        {
            ObjectGuid Guid;
            ObjectGuid Creator;
            uint32 Slot = 0;
            WorldPackets::Item::ItemInstance Item;
        };

        class VoidStorageContents final : public ServerPacket
        {
        public:
            explicit VoidStorageContents() : ServerPacket(SMSG_VOID_STORAGE_CONTENTS, 0) { }

            WorldPacket const* Write() override;

            std::vector<VoidItem> Items;
        };

        class VoidStorageTransfer final : public ClientPacket
        {
        public:
            explicit VoidStorageTransfer(WorldPacket&& packet) : ClientPacket(CMSG_VOID_STORAGE_TRANSFER, std::move(packet)) { }

            void Read() override;

            Array<ObjectGuid, VOID_STORAGE_MAX_WITHDRAW> Withdrawals;
            Array<ObjectGuid, VOID_STORAGE_MAX_DEPOSIT> Deposits;
            ObjectGuid Npc;
        };

        class VoidStorageTransferChanges final : public ServerPacket
        {
        public:
            explicit VoidStorageTransferChanges() : ServerPacket(SMSG_VOID_STORAGE_TRANSFER_CHANGES, 0) { }

            WorldPacket const* Write() override;

            std::vector<ObjectGuid> RemovedItems;
            std::vector<VoidItem> AddedItems;
        };

        class SwapVoidItem final : public ClientPacket
        {
        public:
            explicit SwapVoidItem(WorldPacket&& packet) : ClientPacket(CMSG_SWAP_VOID_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            ObjectGuid VoidItemGuid;
            uint32 DstSlot = 0;
        };

        class VoidItemSwapResponse final : public ServerPacket
        {
        public:
            explicit VoidItemSwapResponse() : ServerPacket(SMSG_VOID_ITEM_SWAP_RESPONSE, 16 + 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid VoidItemA;
            ObjectGuid VoidItemB;
            uint32 VoidItemSlotA = 0;
            uint32 VoidItemSlotB = 0;
        };
    }
}

#endif // TRINITYCORE_VOID_STORAGE_PACKETS_H
