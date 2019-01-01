/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "WorldSession.h"
#include "Bag.h"
#include "CollectionMgr.h"
#include "Common.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "VoidStoragePackets.h"
#include "World.h"

void WorldSession::SendVoidStorageTransferResult(VoidTransferError result)
{
    SendPacket(WorldPackets::VoidStorage::VoidTransferResult(result).Write());
}

void WorldSession::HandleVoidStorageUnlock(WorldPackets::VoidStorage::UnlockVoidStorage& unlockVoidStorage)
{
    Creature* unit = _player->GetNPCIfCanInteractWith(unlockVoidStorage.Npc, UNIT_NPC_FLAG_VAULTKEEPER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageUnlock - %s not found or player can't interact with it.", unlockVoidStorage.Npc.ToString().c_str());
        return;
    }

    if (_player->IsVoidStorageUnlocked())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageUnlock - Player (%s, name: %s) tried to unlock void storage a 2nd time.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str());
        return;
    }

    _player->ModifyMoney(-int64(VOID_STORAGE_UNLOCK_COST));
    _player->UnlockVoidStorage();
}

void WorldSession::HandleVoidStorageQuery(WorldPackets::VoidStorage::QueryVoidStorage& queryVoidStorage)
{
    Creature* unit = _player->GetNPCIfCanInteractWith(queryVoidStorage.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER | UNIT_NPC_FLAG_VAULTKEEPER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageQuery - %s not found or player can't interact with it.", queryVoidStorage.Npc.ToString().c_str());
        SendPacket(WorldPackets::VoidStorage::VoidStorageFailed().Write());
        return;
    }

    if (!_player->IsVoidStorageUnlocked())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageQuery - Player (%s, name: %s) queried void storage without unlocking it.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str());
        SendPacket(WorldPackets::VoidStorage::VoidStorageFailed().Write());
        return;
    }

    uint8 count = 0;
    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
        if (_player->GetVoidStorageItem(i))
            ++count;

    WorldPackets::VoidStorage::VoidStorageContents voidStorageContents;
    voidStorageContents.Items.reserve(VOID_STORAGE_MAX_SLOT);

    for (uint8 i = 0; i < VOID_STORAGE_MAX_SLOT; ++i)
    {
        VoidStorageItem* item = _player->GetVoidStorageItem(i);
        if (!item)
            continue;

        WorldPackets::VoidStorage::VoidItem voidItem;
        voidItem.Guid = ObjectGuid::Create<HighGuid::Item>(item->ItemId);
        voidItem.Creator = item->CreatorGuid;
        voidItem.Slot = i;
        voidItem.Item.Initialize(item);

        voidStorageContents.Items.push_back(voidItem);
    }

    SendPacket(voidStorageContents.Write());
}

void WorldSession::HandleVoidStorageTransfer(WorldPackets::VoidStorage::VoidStorageTransfer& voidStorageTransfer)
{
    Creature* unit = _player->GetNPCIfCanInteractWith(voidStorageTransfer.Npc, UNIT_NPC_FLAG_VAULTKEEPER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageTransfer - %s not found or player can't interact with it.", voidStorageTransfer.Npc.ToString().c_str());
        return;
    }

    if (!_player->IsVoidStorageUnlocked())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageTransfer - Player (%s, name: %s) queried void storage without unlocking it.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str());
        return;
    }

    if (voidStorageTransfer.Deposits.size() > _player->GetNumOfVoidStorageFreeSlots())
    {
        SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_FULL);
        return;
    }

    uint32 freeBagSlots = 0;
    if (!voidStorageTransfer.Withdrawals.empty())
    {
        // make this a Player function
        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++)
            if (Bag* bag = _player->GetBagByPos(i))
                freeBagSlots += bag->GetFreeSlots();

        uint8 inventoryEnd = INVENTORY_SLOT_ITEM_START + _player->GetInventorySlotCount();
        for (uint8 i = INVENTORY_SLOT_ITEM_START; i < inventoryEnd; i++)
            if (!_player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                ++freeBagSlots;
    }

    if (voidStorageTransfer.Withdrawals.size() > freeBagSlots)
    {
        SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_INVENTORY_FULL);
        return;
    }

    if (!_player->HasEnoughMoney(uint64(voidStorageTransfer.Deposits.size() * VOID_STORAGE_STORE_ITEM_COST)))
    {
        SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_NOT_ENOUGH_MONEY);
        return;
    }

    WorldPackets::VoidStorage::VoidStorageTransferChanges voidStorageTransferChanges;
    voidStorageTransferChanges.AddedItems.reserve(VOID_STORAGE_MAX_DEPOSIT);
    voidStorageTransferChanges.RemovedItems.reserve(VOID_STORAGE_MAX_DEPOSIT);

    uint8 depositCount = 0;
    for (uint32 i = 0; i < voidStorageTransfer.Deposits.size(); ++i)
    {
        Item* item = _player->GetItemByGuid(voidStorageTransfer.Deposits[i]);
        if (!item)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageTransfer - %s %s wants to deposit an invalid item (%s).", _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), voidStorageTransfer.Deposits[i].ToString().c_str());
            continue;
        }

        VoidStorageItem itemVS(sObjectMgr->GenerateVoidStorageItemId(), item->GetEntry(), item->GetGuidValue(ITEM_FIELD_CREATOR),
            item->GetItemRandomEnchantmentId(), item->GetItemSuffixFactor(), item->GetModifier(ITEM_MODIFIER_UPGRADE_ID),
            item->GetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL), item->GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL),
            uint8(item->GetUInt32Value(ITEM_FIELD_CONTEXT)), item->GetDynamicValues(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS));

        WorldPackets::VoidStorage::VoidItem voidItem;
        voidItem.Guid = ObjectGuid::Create<HighGuid::Item>(itemVS.ItemId);
        voidItem.Creator = item->GetGuidValue(ITEM_FIELD_CREATOR);
        voidItem.Item.Initialize(&itemVS);
        voidItem.Slot = _player->AddVoidStorageItem(std::move(itemVS));

        voidStorageTransferChanges.AddedItems.push_back(voidItem);

        _player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
        ++depositCount;
    }

    int64 cost = depositCount * VOID_STORAGE_STORE_ITEM_COST;

    _player->ModifyMoney(-cost);

    for (uint32 i = 0; i < voidStorageTransfer.Withdrawals.size(); ++i)
    {
        uint8 slot = 0;
        VoidStorageItem* itemVS = _player->GetVoidStorageItem(voidStorageTransfer.Withdrawals[i].GetCounter(), slot);
        if (!itemVS)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageTransfer - %s %s tried to withdraw an invalid item (id: %s)", _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), voidStorageTransfer.Withdrawals[i].ToString().c_str());
            continue;
        }

        ItemPosCountVec dest;
        InventoryResult msg = _player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemVS->ItemEntry, 1);
        if (msg != EQUIP_ERR_OK)
        {
            SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_INVENTORY_FULL);
            TC_LOG_DEBUG("network", "WORLD: HandleVoidStorageTransfer - %s %s couldn't withdraw item id %s because inventory was full.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), voidStorageTransfer.Withdrawals[i].ToString().c_str());
            return;
        }

        Item* item = _player->StoreNewItem(dest, itemVS->ItemEntry, true, itemVS->ItemRandomPropertyId, GuidSet(), itemVS->Context, itemVS->BonusListIDs);
        item->SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, itemVS->ItemSuffixFactor);
        item->SetGuidValue(ITEM_FIELD_CREATOR, itemVS->CreatorGuid);
        item->SetModifier(ITEM_MODIFIER_UPGRADE_ID, itemVS->ItemUpgradeId);
        item->SetBinding(true);
        GetCollectionMgr()->AddItemAppearance(item);

        voidStorageTransferChanges.RemovedItems.push_back(ObjectGuid::Create<HighGuid::Item>(itemVS->ItemId));

        _player->DeleteVoidStorageItem(slot);
    }

    SendPacket(voidStorageTransferChanges.Write());

    SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_NO_ERROR);
}

void WorldSession::HandleVoidSwapItem(WorldPackets::VoidStorage::SwapVoidItem& swapVoidItem)
{
    Creature* unit = _player->GetNPCIfCanInteractWith(swapVoidItem.Npc, UNIT_NPC_FLAG_VAULTKEEPER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidSwapItem - %s not found or player can't interact with it.", swapVoidItem.Npc.ToString().c_str());
        return;
    }

    if (!_player->IsVoidStorageUnlocked())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidSwapItem - Player (%s, name: %s) queried void storage without unlocking it.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str());
        return;
    }

    uint8 oldSlot;
    if (!_player->GetVoidStorageItem(swapVoidItem.VoidItemGuid.GetCounter(), oldSlot))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleVoidSwapItem - %s %s requested swapping an invalid item (slot: %u, itemid: %s).", _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), swapVoidItem.DstSlot, swapVoidItem.VoidItemGuid.ToString().c_str());
        return;
    }

    bool usedDestSlot = _player->GetVoidStorageItem(swapVoidItem.DstSlot) != NULL;
    ObjectGuid itemIdDest;
    if (usedDestSlot)
        itemIdDest = ObjectGuid::Create<HighGuid::Item>(_player->GetVoidStorageItem(swapVoidItem.DstSlot)->ItemId);

    if (!_player->SwapVoidStorageItem(oldSlot, swapVoidItem.DstSlot))
    {
        SendVoidStorageTransferResult(VOID_TRANSFER_ERROR_INTERNAL_ERROR_1);
        return;
    }

    WorldPackets::VoidStorage::VoidItemSwapResponse voidItemSwapResponse;
    voidItemSwapResponse.VoidItemA = swapVoidItem.VoidItemGuid;
    voidItemSwapResponse.VoidItemSlotA = swapVoidItem.DstSlot;
    if (usedDestSlot)
    {
        voidItemSwapResponse.VoidItemB = itemIdDest;
        voidItemSwapResponse.VoidItemSlotB = oldSlot;
    }

    SendPacket(voidItemSwapResponse.Write());
}
