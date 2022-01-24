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
#include "Player.h"

namespace WorldPackets
{
namespace Item
{
bool ItemBonuses::operator==(ItemBonuses const& r) const
{
    if (Context != r.Context)
        return false;

    if (BonusListIDs.size() != r.BonusListIDs.size())
        return false;

    return std::is_permutation(BonusListIDs.begin(), BonusListIDs.end(), r.BonusListIDs.begin());
}

bool ItemMod::operator==(ItemMod const& r) const
{
    return Value == r.Value && Type == r.Type;
}

bool ItemModList::operator==(ItemModList const& r) const
{
    if (Values.size() != r.Values.size())
        return false;

    return std::is_permutation(Values.begin(), Values.end(), r.Values.begin());
}

void ItemInstance::Initialize(::Item const* item)
{
    ItemID = item->GetEntry();
    std::vector<int32> const& bonusListIds = item->m_itemData->BonusListIDs;
    if (!bonusListIds.empty())
    {
        ItemBonus.emplace();
        ItemBonus->BonusListIDs.insert(ItemBonus->BonusListIDs.end(), bonusListIds.begin(), bonusListIds.end());
        ItemBonus->Context = item->GetContext();
    }

    for (UF::ItemMod mod : item->m_itemData->Modifiers->Values)
        Modifications.Values.emplace_back(mod.Value, ItemModifier(mod.Type));
}

void ItemInstance::Initialize(UF::SocketedGem const* gem)
{
    ItemID = gem->ItemID;

    ItemBonuses bonus;
    bonus.Context = ItemContext(*gem->Context);
    for (uint16 bonusListId : gem->BonusListIDs)
        if (bonusListId)
            bonus.BonusListIDs.push_back(bonusListId);

    if (bonus.Context != ItemContext::NONE || !bonus.BonusListIDs.empty())
        ItemBonus = bonus;
}

void ItemInstance::Initialize(::LootItem const& lootItem)
{
    ItemID = lootItem.itemid;

    if (!lootItem.BonusListIDs.empty() || lootItem.randomBonusListId)
    {
        ItemBonus.emplace();
        ItemBonus->BonusListIDs = lootItem.BonusListIDs;
        ItemBonus->Context = lootItem.context;
        if (lootItem.randomBonusListId)
            ItemBonus->BonusListIDs.push_back(lootItem.randomBonusListId);
    }
}

void ItemInstance::Initialize(::VoidStorageItem const* voidItem)
{
    ItemID = voidItem->ItemEntry;

    if (voidItem->FixedScalingLevel)
        Modifications.Values.emplace_back(voidItem->FixedScalingLevel, ITEM_MODIFIER_TIMEWALKER_LEVEL);

    if (voidItem->ArtifactKnowledgeLevel)
        Modifications.Values.emplace_back(voidItem->ArtifactKnowledgeLevel, ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL);

    if (!voidItem->BonusListIDs.empty())
    {
        ItemBonus.emplace();
        ItemBonus->Context = voidItem->Context;
        ItemBonus->BonusListIDs = voidItem->BonusListIDs;
    }
}

bool ItemInstance::operator==(ItemInstance const& r) const
{
    if (ItemID != r.ItemID)
        return false;

    if (ItemBonus.has_value() != r.ItemBonus.has_value())
        return false;

    if (Modifications != r.Modifications)
        return false;

    if (ItemBonus.has_value() && *ItemBonus != *r.ItemBonus)
        return false;

    return true;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemBonuses const& itemBonusInstanceData)
{
    data << uint8(itemBonusInstanceData.Context);
    data << uint32(itemBonusInstanceData.BonusListIDs.size());
    for (uint32 bonusID : itemBonusInstanceData.BonusListIDs)
        data << uint32(bonusID);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, ItemBonuses& itemBonusInstanceData)
{
    uint32 bonusListIdSize;

    itemBonusInstanceData.Context = data.read<ItemContext>();
    data >> bonusListIdSize;

    for (uint32 i = 0u; i < bonusListIdSize; ++i)
    {
        uint32 bonusId;
        data >> bonusId;
        itemBonusInstanceData.BonusListIDs.push_back(bonusId);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemMod const& itemMod)
{
    data << int32(itemMod.Value);
    data << uint8(itemMod.Type);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, ItemMod& itemMod)
{
    data >> itemMod.Value;
    itemMod.Type = data.read<ItemModifier, uint8>();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemModList const& itemModList)
{
    data.WriteBits(itemModList.Values.size(), 6);
    data.FlushBits();

    for (ItemMod const& itemMod : itemModList.Values)
        data << itemMod;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, ItemModList& itemModList)
{
    itemModList.Values.resize(data.ReadBits(6));
    data.ResetBitPos();

    for (ItemMod& itemMod : itemModList.Values)
        data >> itemMod;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemInstance const& itemInstance)
{
    data << int32(itemInstance.ItemID);

    data.WriteBit(itemInstance.ItemBonus.has_value());
    data.FlushBits();

    data << itemInstance.Modifications;

    if (itemInstance.ItemBonus)
        data << *itemInstance.ItemBonus;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, ItemInstance& itemInstance)
{
    data >> itemInstance.ItemID;

    bool hasItemBonus = data.ReadBit();
    data.ResetBitPos();

    data >> itemInstance.Modifications;

    if (hasItemBonus)
    {
        itemInstance.ItemBonus.emplace();
        data >> *itemInstance.ItemBonus;
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemEnchantData const& itemEnchantData)
{
    data << int32(itemEnchantData.ID);
    data << uint32(itemEnchantData.Expiration);
    data << int32(itemEnchantData.Charges);
    data << uint8(itemEnchantData.Slot);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ItemGemData const& itemGemData)
{
    data << uint8(itemGemData.Slot);
    data << itemGemData.Item;
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, ItemGemData& itemGemData)
{
    data >> itemGemData.Slot;
    data >> itemGemData.Item;
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, InvUpdate& invUpdate)
{
    invUpdate.Items.resize(data.ReadBits(2));
    data.ResetBitPos();
    for (InvUpdate::InvItem& item : invUpdate.Items)
    {
        data >> item.ContainerSlot;
        data >> item.Slot;
    }

    return data;
}
}
}
