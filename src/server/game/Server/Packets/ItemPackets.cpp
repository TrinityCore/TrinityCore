/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
        for (uint32 itemMod : itemInstance.Modifications)
            data << itemMod;
    }

    return data;
}

WorldPacket const* WorldPackets::Item::EquipError::Write()
{
    _worldPacket << uint8(msg);
    _worldPacket << itemGUID1;
    _worldPacket << itemGUID2;
    _worldPacket << uint8(0); // bag type subclass, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_ITEM_DOESNT_GO_INTO_BAG2

    switch (msg)
    {
        case EQUIP_ERR_CANT_EQUIP_LEVEL_I:
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW:
        {
            _worldPacket << level;
            break;
        }
        default:
            break;
    }

    return &_worldPacket;
}

void WorldPackets::Item::SplitItem::Read()
{
    itemCount = _worldPacket.ReadBits(2);
    _worldPacket >> srcbag >> srcslot >> dstbag >> dstslot >> count;
}

void WorldPackets::Item::SwapInvItem::Read()
{
    itemCount = _worldPacket.ReadBits(2);
    for (uint32 i = 0; i < itemCount; ++i)
    {
        _worldPacket.read_skip<uint8>(); // bag
        _worldPacket.read_skip<uint8>(); // slot
    }
    _worldPacket >> dstslot >> srcslot;
}

void WorldPackets::Item::SwapItem::Read()
{
    itemCount = _worldPacket.ReadBits(2);
    for (uint32 i = 0; i < itemCount; ++i)
    {
        _worldPacket.read_skip<uint8>(); // bag
        _worldPacket.read_skip<uint8>(); // slot
    }
    _worldPacket >> dstbag >> srcbag >> dstslot >> srcslot;
}

void WorldPackets::Item::AutoEquipItem::Read()
{
    itemCount = _worldPacket.ReadBits(2);

    _worldPacket >> srcbag >> srcslot;
    _worldPacket.read_skip<uint8>();
    _worldPacket.read_skip<uint8>();
}

void WorldPackets::Item::DestroyItem::Read()
{
    _worldPacket >> count >> bag >> slot;
}