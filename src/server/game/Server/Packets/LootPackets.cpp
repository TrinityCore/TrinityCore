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

#include "LootPackets.h"

namespace WorldPackets::Loot
{
static ByteBuffer& operator<<(ByteBuffer& data, LootItemData const& lootItem)
{
    data << uint8(lootItem.LootListID);
    data << uint32(lootItem.ItemID);
    data << uint32(lootItem.Quantity);
    data << uint32(lootItem.ItemDisplayInfoID);
    data << int32(lootItem.RandomPropertiesSeed);
    data << int32(lootItem.RandomPropertiesID);
    data << uint8(lootItem.UIType);

    return data;
}

void LootUnit::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* LootResponse::Write()
{
    _worldPacket << Owner;
    _worldPacket << uint8(AcquireReason);
    if (AcquireReason)
    {
        _worldPacket << uint32(Coins);
        _worldPacket << uint8(Items.size());
        for (LootItemData const& item : Items)
            _worldPacket << item;
    }
    else
        _worldPacket << uint8(FailureReason);

    return &_worldPacket;
}

void LootItem::Read()
{
    _worldPacket >> LootListID;
}

WorldPacket const* LootRemoved::Write()
{
    _worldPacket << LootListID;

    return &_worldPacket;
}
}
