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

#include "BlackMarketPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::BlackMarket
{
void BlackMarketOpen::Read()
{
    _worldPacket >> Guid;
}

void BlackMarketRequestItems::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> LastUpdateID;
}

ByteBuffer& operator<<(ByteBuffer& data, BlackMarketItem const& blackMarketItem)
{
    data << int32(blackMarketItem.MarketID);
    data << int32(blackMarketItem.SellerNPC);
    data << int32(blackMarketItem.Quantity);
    data << uint64(blackMarketItem.MinBid);
    data << uint64(blackMarketItem.MinIncrement);
    data << uint64(blackMarketItem.CurrentBid);
    data << int32(blackMarketItem.SecondsRemaining);
    data << int32(blackMarketItem.NumBids);
    data << blackMarketItem.Item;
    data << Bits<1>(blackMarketItem.HighBid);
    data.FlushBits();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, BlackMarketItem& blackMarketItem)
{
    data >> blackMarketItem.MarketID;
    data >> blackMarketItem.SellerNPC;
    data >> blackMarketItem.Item;
    data >> blackMarketItem.Quantity;
    data >> blackMarketItem.MinBid;
    data >> blackMarketItem.MinIncrement;
    data >> blackMarketItem.CurrentBid;
    data >> blackMarketItem.SecondsRemaining;
    data >> blackMarketItem.NumBids;
    data >> Bits<1>(blackMarketItem.HighBid);

    return data;
}

WorldPacket const* BlackMarketRequestItemsResult::Write()
{
    _worldPacket << LastUpdateID;
    _worldPacket << Size<uint32>(Items);

    for (BlackMarketItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

void BlackMarketBidOnItem::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> MarketID;
    _worldPacket >> BidAmount;
    _worldPacket >> Item;
}

WorldPacket const* BlackMarketBidOnItemResult::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << int32(Result);
    _worldPacket << Item;

    return &_worldPacket;
}

WorldPacket const* BlackMarketOutbid::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << int32(RandomPropertiesID);
    _worldPacket << Item;

    return &_worldPacket;
}

WorldPacket const* BlackMarketWon::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << int32(RandomPropertiesID);
    _worldPacket << Item;

    return &_worldPacket;
}
}
