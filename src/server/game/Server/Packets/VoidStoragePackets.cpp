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

#include "VoidStoragePackets.h"
#include "PacketOperators.h"

namespace WorldPackets::VoidStorage
{
WorldPacket const* VoidTransferResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

void UnlockVoidStorage::Read()
{
    _worldPacket >> Npc;
}

void QueryVoidStorage::Read()
{
    _worldPacket >> Npc;
}

WorldPacket const* VoidStorageFailed::Write()
{
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, VoidItem const& voidItem)
{
    data << voidItem.Guid;
    data << voidItem.Creator;
    data << uint32(voidItem.Slot);
    data << voidItem.Item;

    return data;
}

WorldPacket const* VoidStorageContents::Write()
{
    _worldPacket.reserve(1 + Items.size() * sizeof(VoidItem));

    _worldPacket << BitsSize<8>(Items);
    _worldPacket.FlushBits();

    for (VoidItem const& voidItem : Items)
        _worldPacket << voidItem;

    return &_worldPacket;
}

void VoidStorageTransfer::Read()
{
    _worldPacket >> Npc;
    _worldPacket >> Size<uint32>(Deposits);
    _worldPacket >> Size<uint32>(Withdrawals);

    for (ObjectGuid& deposit : Deposits)
        _worldPacket >> deposit;

    for (ObjectGuid& withdrawal : Withdrawals)
        _worldPacket >> withdrawal;
}

WorldPacket const* VoidStorageTransferChanges::Write()
{
    _worldPacket.reserve(1 + AddedItems.size() * sizeof(VoidItem) + RemovedItems.size() * 16);

    _worldPacket << BitsSize<4>(AddedItems);
    _worldPacket << BitsSize<4>(RemovedItems);
    _worldPacket.FlushBits();

    for (VoidItem const& addedItem : AddedItems)
        _worldPacket << addedItem;

    for (ObjectGuid const& removedItem : RemovedItems)
        _worldPacket << removedItem;

    return &_worldPacket;
}

void SwapVoidItem::Read()
{
    _worldPacket >> Npc;
    _worldPacket >> VoidItemGuid;
    _worldPacket >> DstSlot;
}

WorldPacket const* VoidItemSwapResponse::Write()
{
    _worldPacket << VoidItemA << uint32(VoidItemSlotA);
    _worldPacket << VoidItemB << uint32(VoidItemSlotB);

    return &_worldPacket;
}
}
