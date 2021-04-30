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

#include "ItemPacketsCommon.h"
#include "Item.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Loot.h"

void WorldPackets::Item::ItemInstance::Initialize(::Item const* item)
{
    ItemID               = item->GetEntry();
    ItemDisplayID        = item->GetDisplayId();
    RandomPropertiesID   = item->GetItemRandomPropertyId();
    RandomPropertiesSeed = item->GetItemSuffixFactor();
}

void WorldPackets::Item::ItemInstance::Initialize(::LootItem const& lootItem)
{
    ItemID                  = lootItem.itemid;
    ItemDisplayID           = ASSERT_NOTNULL(sObjectMgr->GetItemTemplate(lootItem.itemid))->GetDisplayID();
    RandomPropertiesID      = lootItem.randomPropertyId.Type == ItemRandomEnchantmentType::Property ? lootItem.randomPropertyId.Id : -int32(lootItem.randomPropertyId.Id);
    RandomPropertiesSeed    = lootItem.randomSuffix;
}

bool WorldPackets::Item::ItemInstance::operator==(ItemInstance const& r) const
{
    if (ItemID != r.ItemID || RandomPropertiesID != r.RandomPropertiesID || RandomPropertiesSeed != r.RandomPropertiesSeed)
        return false;
    return true;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemInstance const& itemInstance)
{
    data << int32(itemInstance.ItemID);
    data << int32(itemInstance.RandomPropertiesID);
    data << int32(itemInstance.RandomPropertiesSeed);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Item::ItemInstance& itemInstance)
{
    data >> itemInstance.ItemID;
    data >> itemInstance.RandomPropertiesID;
    data >> itemInstance.RandomPropertiesSeed;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemEnchantData const& itemEnchantData)
{
    data << int32(itemEnchantData.ID);
    data << uint32(itemEnchantData.Expiration);
    data << int32(itemEnchantData.Charges);
    data << uint8(itemEnchantData.Slot);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemGemData const& itemGemData)
{
    data << uint32(itemGemData.Slot);
    data << uint32(itemGemData.EnchantmentId);
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Item::ItemGemData& itemGemData)
{
    data >> itemGemData.Slot;
    data >> itemGemData.EnchantmentId;
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Item::InvUpdate& invUpdate)
{
    invUpdate.Items.resize(data.ReadBits(2));
    for (size_t i = 0; i < invUpdate.Items.size(); ++i)
    {
        data >> invUpdate.Items[i].ContainerSlot;
        data >> invUpdate.Items[i].Slot;
    }

    return data;
}
