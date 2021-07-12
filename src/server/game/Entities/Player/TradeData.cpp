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

#include "TradeData.h"
#include "Item.h"
#include "Player.h"
#include "Random.h"
#include "TradePackets.h"
#include "WorldSession.h"

TradeData* TradeData::GetTraderData() const
{
    return _trader->GetTradeData();
}

Item* TradeData::GetItem(TradeSlots slot) const
{
    return !_items[slot].IsEmpty() ? _player->GetItemByGuid(_items[slot]) : nullptr;
}

bool TradeData::HasItem(ObjectGuid itemGuid) const
{
    for (uint8 i = 0; i < TRADE_SLOT_COUNT; ++i)
        if (_items[i] == itemGuid)
            return true;

    return false;
}

TradeSlots TradeData::GetTradeSlotForItem(ObjectGuid itemGuid) const
{
    for (uint8 i = 0; i < TRADE_SLOT_COUNT; ++i)
        if (_items[i] == itemGuid)
            return TradeSlots(i);

    return TRADE_SLOT_INVALID;
}

Item* TradeData::GetSpellCastItem() const
{
    return !_spellCastItem.IsEmpty() ? _player->GetItemByGuid(_spellCastItem) : nullptr;
}

void TradeData::SetItem(TradeSlots slot, Item* item, bool update /*= false*/)
{
    ObjectGuid itemGuid;
    if (item)
        itemGuid = item->GetGUID();

    if (_items[slot] == itemGuid && !update)
        return;

    _items[slot] = itemGuid;

    SetAccepted(false);
    GetTraderData()->SetAccepted(false);

    UpdateServerStateIndex();

    Update();

    // need remove possible trader spell applied to changed item
    if (slot == TRADE_SLOT_NONTRADED)
        GetTraderData()->SetSpell(0);

    // need remove possible player spell applied (possible move reagent)
    SetSpell(0);
}

void TradeData::SetSpell(uint32 spell_id, Item* castItem /*= nullptr*/)
{
    ObjectGuid itemGuid = castItem ? castItem->GetGUID() : ObjectGuid::Empty;

    if (_spell == spell_id && _spellCastItem == itemGuid)
        return;

    _spell = spell_id;
    _spellCastItem = itemGuid;

    SetAccepted(false);
    GetTraderData()->SetAccepted(false);

    UpdateServerStateIndex();

    Update(true);                                           // send spell info to item owner
    Update(false);                                          // send spell info to caster self
}

void TradeData::SetMoney(uint64 money)
{
    if (_money == money)
        return;

    if (!_player->HasEnoughMoney(money))
    {
        WorldPackets::Trade::TradeStatus info;
        info.Status = TRADE_STATUS_FAILED;
        info.BagResult = EQUIP_ERR_NOT_ENOUGH_MONEY;
        _player->GetSession()->SendTradeStatus(info);
        return;
    }

    _money = money;

    SetAccepted(false);
    GetTraderData()->SetAccepted(false);

    UpdateServerStateIndex();

    Update(true);
}

void TradeData::UpdateServerStateIndex()
{
    m_serverStateIndex = rand32();
}

void TradeData::Update(bool forTrader /*= true*/) const
{
    if (forTrader)
        _trader->GetSession()->SendUpdateTrade(true);      // player state for trader
    else
        _player->GetSession()->SendUpdateTrade(false);     // player state for player
}

void TradeData::SetAccepted(bool state, bool forTrader /*= false*/)
{
    _accepted = state;

    if (!state)
    {
        WorldPackets::Trade::TradeStatus info;

        info.Status = TRADE_STATUS_UNACCEPTED;
        if (forTrader)
            _trader->GetSession()->SendTradeStatus(info);
        else
            _player->GetSession()->SendTradeStatus(info);
    }
}
