/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Bag.h"
#include "BankPackets.h"
#include "Item.h"
#include "DB2Stores.h"
#include "Log.h"
#include "NPCPackets.h"
#include "Opcodes.h"
#include "Player.h"
#include "WorldPacket.h"
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

    if (_player->IsBankPos(packet.Bag, packet.Slot))                    // moving from bank to inventory
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, item, false, true);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, NULL);
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
            _player->SendEquipError(msg, item, NULL);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        _player->BankItem(dest, item, true);
    }
}

void WorldSession::HandleAutoBankReagentOpcode(WorldPackets::Bank::AutoBankReagent& packet)
{
    TC_LOG_DEBUG("network", "STORAGE: receive bag = %u, slot = %u", packet.Bag, packet.Slot);

    if (!CanUseBank())
    {
        TC_LOG_ERROR("network", "WORLD: HandleAutoBankReagentOpcode - Unit (%s) not found or you can't interact with him.", m_currentBankerGUID.ToString().c_str());
        return;
    }

    if (!GetPlayer()->HasUnlockedReagentBank())
    {
        TC_LOG_ERROR("network", "WORLD: HandleAutoBankReagentOpcode - Player(%s) can not use reagent bank", GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    Item* item = _player->GetItemByPos(packet.Bag, packet.Slot);
    if (!item)
        return;

    if (_player->IsReagentBankPos(packet.Bag, packet.Slot))             // moving from reagent bank to inventory
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, item, false, true);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, NULL);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        if (Item const* storedItem = _player->StoreItem(dest, item, true))
            _player->ItemAddedQuestCheck(storedItem->GetEntry(), storedItem->GetCount());

    }
    else                                                                // moving from inventory to reagent bank
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false, true, true);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, NULL);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        _player->BankItem(dest, item, true);
    }
}

void WorldSession::HandleBankerActivateOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_BANKER);
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
            _player->SendEquipError(msg, item, NULL);
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
            _player->SendEquipError(msg, item, NULL);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        _player->BankItem(dest, item, true);
    }
}

void WorldSession::HandleAutoStoreBankReagentOpcode(WorldPackets::Bank::AutoStoreBankReagent& packet)
{
    TC_LOG_DEBUG("network", "STORAGE: receive bag = %u, slot = %u", packet.Bag, packet.Slot);

    if (!CanUseBank())
    {
        TC_LOG_ERROR("network", "WORLD: HandleAutoStoreReagentBankItemOpcode - Unit (%s) not found or you can't interact with him.", m_currentBankerGUID.ToString().c_str());
        return;
    }

    if (!GetPlayer()->HasUnlockedReagentBank())
    {
        TC_LOG_ERROR("network", "WORLD: HandleAutoStoreReagentBankItemOpcode - Player(%s) can not use reagent bank", GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    Item* item = _player->GetItemByPos(packet.Bag, packet.Slot);
    if (!item)
        return;

    if (_player->IsReagentBankPos(packet.Bag, packet.Slot))             // moving from reagent bank to inventory
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanStoreItem(NULL_BAG, NULL_SLOT, dest, item, false);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, NULL);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        if (Item const* storedItem = _player->StoreItem(dest, item, true))
            _player->ItemAddedQuestCheck(storedItem->GetEntry(), storedItem->GetCount());

    }
    else                                                                // moving from inventory to reagent bank
    {
        ItemPosCountVec dest;
        InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false, true, true);
        if (msg != EQUIP_ERR_OK)
        {
            _player->SendEquipError(msg, item, NULL);
            return;
        }

        _player->RemoveItem(packet.Bag, packet.Slot, true);
        _player->BankItem(dest, item, true);
    }
}

void WorldSession::HandleBuyBankSlotOpcode(WorldPackets::Bank::BuyBankSlot& packet)
{
    WorldPacket data(SMSG_BUY_BANK_SLOT_RESULT, 4);
    if (!CanUseBank(packet.Guid))
    {
        data << uint32(ERR_BANKSLOT_NOTBANKER);
        SendPacket(&data);
        TC_LOG_ERROR("network", "WORLD: HandleBuyBankSlotOpcode - %s not found or you can't interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    uint32 slot = _player->GetBankBagSlotCount();

    // next slot
    ++slot;

    TC_LOG_INFO("network", "PLAYER: Buy bank bag slot, slot number = %u", slot);

    BankBagSlotPricesEntry const* slotEntry = sBankBagSlotPricesStore.LookupEntry(slot);

    if (!slotEntry)
    {
        data << uint32(ERR_BANKSLOT_FAILED_TOO_MANY);
        SendPacket(&data);
        return;
    }

    uint32 price = slotEntry->Cost;

    if (!_player->HasEnoughMoney(uint64(price)))
    {
        data << uint32(ERR_BANKSLOT_INSUFFICIENT_FUNDS);
        SendPacket(&data);
        return;
    }

    _player->SetBankBagSlotCount(slot);
    _player->ModifyMoney(-int64(price));

     data << uint32(ERR_BANKSLOT_OK);
     SendPacket(&data);

    _player->UpdateCriteria(CRITERIA_TYPE_BUY_BANK_SLOT);
}

void WorldSession::SendShowBank(ObjectGuid guid)
{
    m_currentBankerGUID = guid;
    WorldPackets::NPC::ShowBank packet;
    packet.Guid = guid;
    SendPacket(packet.Write());
}

void WorldSession::HandleBuyReagentBankOpcode(WorldPackets::NPC::Hello& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Unit, UNIT_NPC_FLAG_BANKER);
    if (!unit)
    {
        TC_LOG_ERROR("network", "WORLD: HandleBuyReagentBankOpcode - %s not found or you can not interact with him.", packet.Unit.ToString().c_str());
        return;
    }

    if (GetPlayer()->HasUnlockedReagentBank())
        return;

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    int64 price = 100 * GOLD;
    if (!GetPlayer()->HasEnoughMoney(uint64(price)))
        return;

    GetPlayer()->ModifyMoney(-int64(price));
    GetPlayer()->UnlockReagentBank();
}

void WorldSession::HandleDepositReagentBankOpcode(WorldPackets::Bank::DepositReagentBank& packet)
{
    Creature* unit = _player->GetNPCIfCanInteractWith(packet.Guid, UNIT_NPC_FLAG_BANKER);
    if (!unit)
    {
        TC_LOG_ERROR("network", "WORLD: HandleDepositReagentBankOpcode - %s not found or you can not interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    if (!_player->HasUnlockedReagentBank())
        return;

    for (uint32 bagSlot = INVENTORY_SLOT_BAG_START; bagSlot < INVENTORY_SLOT_BAG_END; ++bagSlot)
    {
        if (Bag* bag = (Bag*)GetPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, bagSlot))
        {
            for (uint32 slot = 0; slot < bag->GetBagSize(); ++slot)
            {
                if (Item* item = _player->GetItemByPos(bagSlot, slot))
                {
                    if (item->GetTemplate()->GetClass() != ITEM_CLASS_TRADE_GOODS)
                        continue;

                    if (!(item->GetTemplate()->GetFlags2() & ITEM_FLAG2_USED_IN_A_TRADESKILL))
                        continue;

                    ItemPosCountVec dest;
                    InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false, true, true);
                    if (msg != EQUIP_ERR_OK)
                    {
                        _player->SendEquipError(msg, item, NULL);
                        return;
                    }

                    _player->RemoveItem(bagSlot, slot, true);
                    _player->BankItem(dest, item, true);
                }
            }
        }
    }

    for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; slot++)
    {
        if (Item* item = _player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
        {
            if (item->GetTemplate()->GetClass() != ITEM_CLASS_TRADE_GOODS)
                continue;

            if (!(item->GetTemplate()->GetFlags2() & ITEM_FLAG2_USED_IN_A_TRADESKILL))
                continue;

            ItemPosCountVec dest;
            InventoryResult msg = _player->CanBankItem(NULL_BAG, NULL_SLOT, dest, item, false, true, true);
            if (msg != EQUIP_ERR_OK)
            {
                _player->SendEquipError(msg, item, NULL);
                return;
            }

            _player->RemoveItem(INVENTORY_SLOT_BAG_0, slot, true);
            _player->BankItem(dest, item, true);
        }
    }
}
