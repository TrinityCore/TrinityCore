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

#include "TradePackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Trade
{
void AcceptTrade::Read()
{
    _worldPacket >> StateIndex;
}

void ClearTradeItem::Read()
{
    _worldPacket >> TradeSlot;
}

void InitiateTrade::Read()
{
    _worldPacket >> Guid;
}

void SetTradeCurrency::Read()
{
    _worldPacket >> Type >> Quantity;
}

void SetTradeGold::Read()
{
    _worldPacket >> Coinage;
}

void SetTradeItem::Read()
{
    _worldPacket >> TradeSlot >> PackSlot >> ItemSlotInPack;
}

WorldPacket const* TradeStatus::Write()
{
    _worldPacket << Bits<1>(PartnerIsSameBnetAccount);
    _worldPacket << Bits<5>(Status);
    switch (Status)
    {
        case TRADE_STATUS_FAILED:
            _worldPacket << Bits<1>(FailureForYou);
            _worldPacket << int32(BagResult);
            _worldPacket << int32(ItemID);
            break;
        case TRADE_STATUS_INITIATED:
            _worldPacket << uint32(ID);
            break;
        case TRADE_STATUS_PROPOSED:
            _worldPacket << Partner;
            _worldPacket << PartnerAccount;
            break;
        case TRADE_STATUS_WRONG_REALM:
        case TRADE_STATUS_NOT_ON_TAPLIST:
            _worldPacket << uint8(TradeSlot);
            break;
        case TRADE_STATUS_NOT_ENOUGH_CURRENCY:
        case TRADE_STATUS_CURRENCY_NOT_TRADABLE:
            _worldPacket << int32(CurrencyType);
            _worldPacket << int32(CurrencyQuantity);
            break;
        default:
            _worldPacket.FlushBits();
            break;
    }

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& buffer, UnwrappedTradeItem const& unwrappedTradeItem)
{
    buffer << int32(unwrappedTradeItem.EnchantID);
    buffer << int32(unwrappedTradeItem.OnUseEnchantmentID);
    buffer << unwrappedTradeItem.Creator;
    buffer << int32(unwrappedTradeItem.Charges);
    buffer << uint32(unwrappedTradeItem.MaxDurability);
    buffer << uint32(unwrappedTradeItem.Durability);
    buffer << BitsSize<2>(unwrappedTradeItem.Gems);
    buffer << Bits<1>(unwrappedTradeItem.Lock);
    buffer.FlushBits();

    for (Item::ItemGemData const& gem : unwrappedTradeItem.Gems)
        buffer << gem;

    return buffer;
}

ByteBuffer& operator<<(ByteBuffer& buffer, TradeItem const& tradeItem)
{
    buffer << uint8(tradeItem.Slot);
    buffer << uint32(tradeItem.StackCount);
    buffer << tradeItem.GiftCreator;
    buffer << tradeItem.Item;
    buffer << OptionalInit(tradeItem.Unwrapped);
    buffer.FlushBits();
    if (tradeItem.Unwrapped)
        buffer << *tradeItem.Unwrapped;

    return buffer;
}

WorldPacket const* TradeUpdated::Write()
{
    _worldPacket << uint8(WhichPlayer);
    _worldPacket << uint32(ID);
    _worldPacket << uint32(ClientStateIndex);
    _worldPacket << uint32(CurrentStateIndex);
    _worldPacket << uint64(Gold);
    _worldPacket << int32(CurrencyType);
    _worldPacket << int32(CurrencyQuantity);
    _worldPacket << int32(ProposedEnchantment);
    _worldPacket << Size<uint32>(Items);

    for (TradeItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}
}
