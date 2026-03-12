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

#include "InspectPackets.h"
#include "Item.h"

namespace WorldPackets::Inspect
{
void Inspect::Read()
{
    _worldPacket >> Target;
}

ByteBuffer& operator<<(ByteBuffer& data, InspectItemData const& item)
{
    data << uint32(item.ItemID);
    data << uint16(item.EnchantSlots.to_ulong());

    if (!item.Enchants.empty())
        data.append(item.Enchants.data(), item.Enchants.size());

    data << int16(item.RandomPropertiesID);
    data << item.CreatorGUID.WriteAsPacked();
    data << uint32(item.RandomPropertiesSeed);

    return data;
}

InspectItemData::InspectItemData(Item const* item)
{
    CreatorGUID = item->GetGuidValue(ITEM_FIELD_CREATOR);

    ItemID = item->GetEntry();
    RandomPropertiesID = item->GetItemRandomPropertyId();
    RandomPropertiesSeed = item->GetItemSuffixFactor();

    for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
    {
        if (uint32 enchId = item->GetEnchantmentId(EnchantmentSlot(i)))
        {
            EnchantSlots[i] = true;
            Enchants.push_back(enchId);
        }
    }
}

WorldPacket const* InspectResult::Write()
{
    _worldPacket << InspecteeGUID.WriteAsPacked();
    _worldPacket << TalentInfo;
    _worldPacket << uint32(ItemSlots.to_ulong());

    for (InspectItemData const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}
}
