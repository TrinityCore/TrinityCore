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

#include "BankPackets.h"
#include "Item.h"
#include "DB2Stores.h"
#include "Log.h"
#include "NPCPackets.h"
#include "Player.h"
#include "WorldSession.h"

void WorldSession::HandleAutoBankItemOpcode(WorldPackets::Bank::AutoBankItem& packet)
{
    TC_LOG_DEBUG("network", "STORAGE: receive bag = %u, slot = %u", packet.Bag, packet.Slot);

    if (!CanUseBank())
    {
        TC_LOG_ERROR("network", "WORLD: HandleAutoBankItemOpcode - Unit (%s) not found or you can't interact with him.", m_currentBankerGUID.ToString().c_str());
        return;
    }

    Item* item = _player->GetItemByPos(packet.Bag, packet.Slot);
    if (!item)
        return;

    ItemPosCountVec dest;
    InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false);
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, item, nullptr);
        return;
    }

    if (dest.size() == 1 && dest[0].pos == item->GetPos())
    {
        _player->SendEquipError(EQUIP_ERR_CANT_SWAP, item, nullptr);
        return;
    }

    _player->RemoveItem(packet.Bag, packet.Slot, true);
    _player->ItemRemovedQuestCheck(item->GetEntry(), item->GetCount());
    _player->BankItem(dest, item, true);
}

void WorldSession::HandleBankerActivateOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_BANKER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_ERROR("network", "WORLD: HandleBankerActivateOpcode - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // set currentBankerGUID for other bank action

    SendShowBank(packet.Unit);
}

void WorldSession::HandleAutoStoreBankItemOpcode(WorldPackets::Bank::AutoStoreBankItem& packet)
{
    TC_LOG_DEBUG("network", "STORAGE: receive bag = %u, slot = %u", packet.Bag, packet.Slot);

    if (!CanUseBank())
    {
        TC_LOG_ERROR("network", "WORLD: HandleAutoStoreBankItemOpcode - Unit (%s) not found or you can't interact with him.", m_currentBankerGUID.ToString().c_str());
        return;
    }

    Item* item = _player->GetItemByPos(packet.Bag, packet.Slot);
    if (!item)
        return;

    if (_player->IsBankPos(packet.Bag, packet.Slot))                    // moving from bank to inventory
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, item, false);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, nullptr);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        if (Item const* storedItem = _player->StoreItem(dest, item, true))
            _player->ItemAddedQuestCheck(storedItem->GetEntry(), storedItem->GetCount());

    }
    else                                                                // moving from inventory to bank
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, nullptr);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        _player->BankItem(dest, item, true);
    }
}

void WorldSession::HandleBuyBankSlotOpcode(WorldPackets::Bank::BuyBankSlot& packet)
{
    if (!CanUseBank(packet.Guid))
    {
        TC_LOG_ERROR("network", "WORLD: HandleBuyBankSlotOpcode - %s not found or you can't interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    uint32 slot = _player->GetBankBagSlotCount();

    // next slot
    ++slot;

    TC_LOG_INFO("network", "PLAYER: Buy bank bag slot, slot number = %u", slot);

    BankBagSlotPricesEntry const* slotEntry = sBankBagSlotPricesStore.LookupEntry(slot);
    if (!slotEntry)
        return;

    uint32 price = slotEntry->Cost;

    if (!_player->HasEnoughMoney(uint64(price)))
        return;

    _player->SetBankBagSlotCount(slot);
    _player->ModifyMoney(-int64(price));

    _player->UpdateCriteria(CriteriaType::BankSlotsPurchased);
}

void WorldSession::HandleBuyReagentBankOpcode(WorldPackets::Bank::ReagentBank& reagentBank)
{
    if (!CanUseBank(reagentBank.Banker))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBuyReagentBankOpcode - %s not found or you can't interact with him.", reagentBank.Banker.ToString().c_str());
        return;
    }

    if (_player->IsReagentBankUnlocked())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBuyReagentBankOpcode - Player (%s, name: %s) tried to unlock reagent bank a 2nd time.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str());
        return;
    }

    constexpr int64 price = 100 * GOLD;

    if (!_player->HasEnoughMoney(price))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBuyReagentBankOpcode - Player (%s, name: %s) without enough gold.", _player->GetGUID().ToString().c_str(), _player->GetName().c_str());
        return;
    }

    _player->ModifyMoney(-price);
    _player->UnlockReagentBank();
}

void WorldSession::HandleReagentBankDepositOpcode(WorldPackets::Bank::ReagentBank& reagentBank)
{
    if (!CanUseBank(reagentBank.Banker))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleReagentBankDepositOpcode - %s not found or you can't interact with him.", reagentBank.Banker.ToString().c_str());
        return;
    }

    if (!_player->IsReagentBankUnlocked())
    {
        _player->SendEquipError(EQUIP_ERR_REAGENT_BANK_LOCKED);
        return;
    }

    // query all reagents from player's inventory
    bool anyDeposited = false;
    for (Item* item : _player->GetCraftingReagentItemsToDeposit())
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false, true, true);
        if (msg != EQUIP_ERR_OK)
        {
            if (msg != EQUIP_ERR_REAGENT_BANK_FULL || !anyDeposited)
                _player->SendEquipError(msg, item, NULL);
            break;
        }

        if (dest.size() == 1 && dest[0].pos == item->GetPos())
        {
            _player->SendEquipError(EQUIP_ERR_CANT_SWAP, item, NULL);
            continue;
        }

        // store reagent
        _player->RemoveItem(item->GetBagSlot(), item->GetSlot(), true);
        _player->BankItem(dest, item, true);
        anyDeposited = true;
    }
}

void WorldSession::HandleAutoBankReagentOpcode(WorldPackets::Bank::AutoBankReagent& autoBankReagent)
{
    if (!CanUseBank())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAutoBankReagentOpcode - %s not found or you can't interact with him.", m_currentBankerGUID.ToString().c_str());
        return;
    }

    if (!_player->IsReagentBankUnlocked())
    {
        _player->SendEquipError(EQUIP_ERR_REAGENT_BANK_LOCKED);
        return;
    }

    Item* item = _player->GetItemByPos(autoBankReagent.PackSlot, autoBankReagent.Slot);
    if (!item)
        return;

    ItemPosCountVec dest;
    InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false, true, true);
    if (msg != EQUIP_ERR_OK)
    {
        _player->SendEquipError(msg, item, NULL);
        return;
    }

    if (dest.size() == 1 && dest[0].pos == item->GetPos())
    {
        _player->SendEquipError(EQUIP_ERR_CANT_SWAP, item, NULL);
        return;
    }

    _player->RemoveItem(autoBankReagent.PackSlot, autoBankReagent.Slot, true);
    _player->BankItem(dest, item, true);
}

void WorldSession::HandleAutoStoreBankReagentOpcode(WorldPackets::Bank::AutoStoreBankReagent& autoStoreBankReagent)
{
    if (!CanUseBank())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAutoBankReagentOpcode - %s not found or you can't interact with him.", m_currentBankerGUID.ToString().c_str());
        return;
    }

    if (!_player->IsReagentBankUnlocked())
    {
        _player->SendEquipError(EQUIP_ERR_REAGENT_BANK_LOCKED);
        return;
    }

    Item* pItem = _player->GetItemByPos(autoStoreBankReagent.Slot, autoStoreBankReagent.PackSlot);
    if (!pItem)
        return;

    if (_player->IsReagentBankPos(autoStoreBankReagent.Slot, autoStoreBankReagent.PackSlot))
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, pItem, false);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, pItem, NULL);
            return;
        }

        _player->RemoveItem(autoStoreBankReagent.Slot, autoStoreBankReagent.PackSlot, true);
        _player->StoreItem(dest, pItem, true);
    }
    else
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, pItem, false, true, true);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, pItem, NULL);
            return;
        }

        _player->RemoveItem(autoStoreBankReagent.Slot, autoStoreBankReagent.PackSlot, true);
        _player->BankItem(dest, pItem, true);
    }
}

void WorldSession::SendShowBank(ObjectGuid guid)
{
    m_currentBankerGUID = guid;
    WorldPackets::NPC::ShowBank packet;
    packet.Guid = guid;
    SendPacket(packet.Write());
}
