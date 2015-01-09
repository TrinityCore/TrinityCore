/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "ItemPackets.h"

void WorldPackets::Item::BuyBackItem::Read()
{
    _worldPacket >> VendorGUID;
    _worldPacket >> Slot;
}

void WorldPackets::Item::ItemRefundInfo::Read()
{
    _worldPacket >> ItemGUID;
}

void WorldPackets::Item::RepairItem::Read()
{
    _worldPacket >> NpcGUID;
    _worldPacket >> ItemGUID;
    UseGuildBank = _worldPacket.ReadBit();
}

void WorldPackets::Item::SellItem::Read()
{
    _worldPacket >> VendorGUID;
    _worldPacket >> ItemGUID;
    _worldPacket >> Amount;
}

WorldPacket const* WorldPackets::Item::SetProficiency::Write()
{
    _worldPacket << ProficiencyMask;
    _worldPacket << ProficiencyClass;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemBonusInstanceData const& itemBonusInstanceData)
{
    data << itemBonusInstanceData.Context;
    data << uint32(itemBonusInstanceData.BonusListIDs.size());
    for (uint32 bonusID : itemBonusInstanceData.BonusListIDs)
        data << bonusID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemInstance const& itemInstance)
{
    data << itemInstance.ItemID;
    data << itemInstance.RandomPropertiesSeed;
    data << itemInstance.RandomPropertiesID;

    data.WriteBit(itemInstance.ItemBonus.HasValue);
    data.WriteBit(!itemInstance.Modifications.empty());
    data.FlushBits();

    if (itemInstance.ItemBonus.HasValue)
        data << itemInstance.ItemBonus.Value;

    if (!itemInstance.Modifications.empty())
    {
        data << uint32(itemInstance.Modifications.size() * sizeof(uint32));
        for (int32 itemMod : itemInstance.Modifications)
            data << itemMod;
    }

    return data;
}

ByteBuffer& WorldPackets::Item::operator>>(ByteBuffer& data, InvUpdate& invUpdate)
{
    invUpdate.Items.resize(data.ReadBits(2));
    for (size_t i = 0; i < invUpdate.Items.size(); ++i)
    {
        data >> invUpdate.Items[i].ContainerSlot;
        data >> invUpdate.Items[i].Slot;
    }

    return data;
}

WorldPacket const* WorldPackets::Item::InventoryChangeFailure::Write()
{
    _worldPacket << int8(BagResult);
    _worldPacket << Item[0];
    _worldPacket << Item[1];
    _worldPacket << uint8(ContainerBSlot); // bag type subclass, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2

    switch (BagResult)
    {
        case EQUIP_ERR_CANT_EQUIP_LEVEL_I:
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW:
            _worldPacket << int32(Level);
            break;
        /// @todo: add more cases
        default:
            break;
    }

    return &_worldPacket;
}

void WorldPackets::Item::SplitItem::Read()
{
    _worldPacket >> Inv
                 >> FromPackSlot
                 >> FromSlot
                 >> ToPackSlot
                 >> ToSlot
                 >> Quantity;
}

void WorldPackets::Item::SwapInvItem::Read()
{
    _worldPacket >> Inv
                 >> Slot2
                 >> Slot1;
}

void WorldPackets::Item::SwapItem::Read()
{
    _worldPacket >> Inv
                 >> ContainerSlotB
                 >> ContainerSlotA
                 >> SlotB
                 >> SlotA;
}

void WorldPackets::Item::AutoEquipItem::Read()
{
    _worldPacket >> Inv
                 >> PackSlot
                 >> Slot;
}

void WorldPackets::Item::DestroyItem::Read()
{
    _worldPacket >> Count
                 >> ContainerId
                 >> SlotNum;
}
