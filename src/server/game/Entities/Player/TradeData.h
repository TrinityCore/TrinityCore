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

#ifndef TradeData_h__
#define TradeData_h__

#include "ObjectGuid.h"

enum TradeSlots
{
    TRADE_SLOT_COUNT          = 7,
    TRADE_SLOT_TRADED_COUNT   = 6,
    TRADE_SLOT_NONTRADED      = 6,
    TRADE_SLOT_INVALID        = -1
};

class Item;
class Player;

class TC_GAME_API TradeData
{
public:
    TradeData(Player* player, Player* trader) :
        _player(player), _trader(trader), _accepted(false), _acceptProccess(false),
        _money(0), _spell(0), _spellCastItem() { }

    Player* GetTrader() const { return _trader; }
    TradeData* GetTraderData() const;

    Item* GetItem(TradeSlots slot) const;
    bool HasItem(ObjectGuid itemGuid) const;
    TradeSlots GetTradeSlotForItem(ObjectGuid itemGuid) const;
    void SetItem(TradeSlots slot, Item* item, bool update = false);

    uint32 GetSpell() const { return _spell; }
    void SetSpell(uint32 spell_id, Item* castItem = nullptr);

    Item*  GetSpellCastItem() const;
    bool HasSpellCastItem() const { return !_spellCastItem.IsEmpty(); }

    uint32 GetMoney() const { return _money; }
    void SetMoney(uint32 money);

    bool IsAccepted() const { return _accepted; }
    void SetAccepted(bool state, bool forTrader = false);

    bool IsInAcceptProcess() const { return _acceptProccess; }
    void SetInAcceptProcess(bool state) { _acceptProccess = state; }

private:
    void Update(bool for_trader = true) const;

    Player*    _player;                                // Player who own of this TradeData
    Player*    _trader;                                // Player who trade with _player

    bool       _accepted;                              // _player press accept for trade list
    bool       _acceptProccess;                        // one from player/trader press accept and this processed

    uint32     _money;                                 // _player place money to trade

    uint32     _spell;                                 // _player apply spell to non-traded slot item
    ObjectGuid _spellCastItem;                         // applied spell cast by item use

    ObjectGuid _items[TRADE_SLOT_COUNT];               // traded items from _player side including non-traded slot
};

#endif // TradeData_h__
