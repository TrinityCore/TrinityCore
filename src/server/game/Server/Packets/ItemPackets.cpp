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
#include "Player.h"

void WorldPackets::Item::BuyBackItem::Read()
{
    _worldPacket >> VendorGUID
                 >> Slot;
}

void WorldPackets::Item::BuyItem::Read()
{
    _worldPacket >> VendorGUID
                 >> ContainerGUID
                 >> Item
                 >> Quantity
                 >> Muid
                 >> Slot;

    ItemType = static_cast<ItemVendorType>(_worldPacket.ReadBits(2));
}

WorldPacket const* WorldPackets::Item::BuySucceeded::Write()
{
    _worldPacket << VendorGUID
                 << uint32(Muid)
                 << int32(NewQuantity)
                 << uint32(QuantityBought);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Item::BuyFailed::Write()
{
    _worldPacket << VendorGUID
                 << uint32(Muid)
                 << uint8(Reason);

    return &_worldPacket;
}

void WorldPackets::Item::GetItemPurchaseData::Read()
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

WorldPacket const* WorldPackets::Item::ItemTimeUpdate::Write()
{
    _worldPacket << ItemGuid;
    _worldPacket << DurationLeft;

    return &_worldPacket;
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

ByteBuffer& operator>>(ByteBuffer& data, Optional<WorldPackets::Item::ItemBonusInstanceData>& itemBonusInstanceData)
{
    uint32 bonusListIdSize;

    itemBonusInstanceData = boost::in_place();

    data >> itemBonusInstanceData->Context;
    data >> bonusListIdSize;

    for (uint32 i = 0u; i < bonusListIdSize; ++i)
    {
        uint32 bonusId;
        data >> bonusId;
        itemBonusInstanceData->BonusListIDs.push_back(bonusId);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemInstance const& itemInstance)
{
    data << int32(itemInstance.ItemID);
    data << int32(itemInstance.RandomPropertiesSeed);
    data << int32(itemInstance.RandomPropertiesID);

    data.WriteBit(itemInstance.ItemBonus.is_initialized());
    data.WriteBit(itemInstance.Modifications.is_initialized());
    data.FlushBits();

    if (itemInstance.ItemBonus)
        data << *itemInstance.ItemBonus;

    if (itemInstance.Modifications)
        data << *itemInstance.Modifications;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Item::ItemInstance& itemInstance)
{
    data >> itemInstance.ItemID;
    data >> itemInstance.RandomPropertiesSeed;
    data >> itemInstance.RandomPropertiesID;

    bool const hasItemBonus = data.ReadBit();
    bool const hasModifications = data.ReadBit();

    if (hasItemBonus)
        data >> itemInstance.ItemBonus;

    if (hasModifications)
    {
        WorldPackets::CompactArray<int32> modifications;
        data >> modifications;
        itemInstance.Modifications = std::move(modifications);
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

void WorldPackets::Item::ItemInstance::Initialize(::Item const* item)
{
    ItemID               = item->GetEntry();
    RandomPropertiesSeed = item->GetItemSuffixFactor();
    RandomPropertiesID   = item->GetItemRandomPropertyId();
    std::vector<uint32> const& bonusListIds = item->GetDynamicValues(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS);
    if (!bonusListIds.empty())
    {
        ItemBonus = boost::in_place();
        ItemBonus->BonusListIDs.insert(ItemBonus->BonusListIDs.end(), bonusListIds.begin(), bonusListIds.end());
        ItemBonus->Context = item->GetUInt32Value(ITEM_FIELD_CONTEXT);
    }

    if (uint32 mask = item->GetUInt32Value(ITEM_FIELD_MODIFIERS_MASK))
    {
        Modifications = boost::in_place();

        for (size_t i = 0; mask != 0; mask >>= 1, ++i)
            if ((mask & 1) != 0)
                Modifications->Insert(i, item->GetModifier(ItemModifier(i)));
    }
}

void WorldPackets::Item::ItemInstance::Initialize(::LootItem const& lootItem)
{
    ItemID               = lootItem.itemid;
    RandomPropertiesSeed = lootItem.randomSuffix;
    RandomPropertiesID   = lootItem.randomPropertyId;
    if (!lootItem.BonusListIDs.empty())
    {
        ItemBonus = boost::in_place();
        ItemBonus->BonusListIDs = lootItem.BonusListIDs;
        ItemBonus->Context = 0; /// @todo
    }

    /// no Modifications
}

void WorldPackets::Item::ItemInstance::Initialize(::VoidStorageItem const* voidItem)
{
    ItemID = voidItem->ItemEntry;
    RandomPropertiesID = voidItem->ItemRandomPropertyId;
    RandomPropertiesSeed = voidItem->ItemSuffixFactor;
    if (voidItem->ItemUpgradeId)
    {
        Modifications = boost::in_place();
        Modifications->Insert(ITEM_MODIFIER_UPGRADE_ID, voidItem->ItemUpgradeId);
    }

    if (!voidItem->BonusListIDs.empty())
    {
        ItemBonus = boost::in_place();
        ItemBonus->BonusListIDs = voidItem->BonusListIDs;
    }
}

WorldPacket const* WorldPackets::Item::InventoryChangeFailure::Write()
{
    _worldPacket << int8(BagResult);
    _worldPacket << Item[0];
    _worldPacket << Item[1];
    _worldPacket << uint8(ContainerBSlot); // bag type subclass, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_WRONG_BAG_TYPE_2

    switch (BagResult)
    {
        case EQUIP_ERR_CANT_EQUIP_LEVEL_I:
        case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW:
            _worldPacket << int32(Level);
            break;
        case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM:
            _worldPacket << SrcContainer;
            _worldPacket << int32(SrcSlot);
            _worldPacket << DstContainer;
            break;
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS:
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS:
        case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS:
            _worldPacket << int32(LimitCategory);
            break;
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

void WorldPackets::Item::AutoEquipItemSlot::Read()
{
    _worldPacket >> Inv
                 >> Item
                 >> ItemDstSlot;
}

void WorldPackets::Item::AutoStoreBagItem::Read()
{
    _worldPacket >> Inv
                 >> ContainerSlotB
                 >> ContainerSlotA
                 >> SlotA;
}

void WorldPackets::Item::DestroyItem::Read()
{
    _worldPacket >> Count
                 >> ContainerId
                 >> SlotNum;
}

WorldPacket const* WorldPackets::Item::SellResponse::Write()
{
    _worldPacket << VendorGUID
                 << ItemGUID
                 << uint8(Reason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Item::ItemPushResult::Write()
{
    _worldPacket << PlayerGUID;

    _worldPacket << uint8(Slot);
    _worldPacket << int32(SlotInBag);

    _worldPacket << Item;

    _worldPacket << uint32(QuestLogItemID);
    _worldPacket << int32(Quantity);
    _worldPacket << int32(QuantityInInventory);
    _worldPacket << uint32(DungeonEncounterID);
    _worldPacket << int32(BattlePetBreedID);
    _worldPacket << int32(BattlePetBreedQuality);
    _worldPacket << int32(BattlePetSpeciesID);
    _worldPacket << int32(BattlePetLevel);

    _worldPacket << ItemGUID;

    _worldPacket.WriteBit(Pushed);
    _worldPacket.WriteBit(Created);
    _worldPacket.WriteBits(DisplayText, 2);
    _worldPacket.WriteBit(IsBonusRoll);
    _worldPacket.WriteBit(IsEncounterLoot);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Item::ReadItem::Read()
{
    _worldPacket >> PackSlot;
    _worldPacket >> Slot;
}

WorldPacket const* WorldPackets::Item::ReadItemResultFailed::Write()
{
    _worldPacket << Item;
    _worldPacket << Delay;
    _worldPacket.WriteBits(Subcode, 3);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Item::ReadItemResultOK::Write()
{
    _worldPacket << Item;

    return &_worldPacket;
}

void WorldPackets::Item::WrapItem::Read()
{
    _worldPacket >> Inv;
}

void WorldPackets::Item::CancelTempEnchantment::Read()
{
    _worldPacket >> Slot;
}

WorldPacket const* WorldPackets::Item::ItemCooldown::Write()
{
    _worldPacket << ItemGuid;
    _worldPacket << uint32(SpellID);
    _worldPacket << uint32(Cooldown);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Item::ItemEnchantTimeUpdate::Write()
{
    _worldPacket << ItemGuid;
    _worldPacket << uint32(DurationLeft);
    _worldPacket << uint32(Slot);
    _worldPacket << OwnerGuid;

    return &_worldPacket;
}

void WorldPackets::Item::TransmogrifyItems::Read()
{
    _worldPacket >> ItemCount;
    _worldPacket >> NpcGUID;

    for (int i = 0; i < ItemCount; i++)
    {
        TransmogrifyInfo info;
        bool HasSrcItemGUID = _worldPacket.ReadBit();
        bool HasSrcVoidItemGUID = _worldPacket.ReadBit();
        _worldPacket >> info.Item;
        _worldPacket >> info.Slot;

        if (HasSrcItemGUID)
            _worldPacket >> info.SrcItemGUID;

        if (HasSrcVoidItemGUID)
            _worldPacket >> info.SrcVoidItemGUID;

        Info.push_back(info);
    }
}
