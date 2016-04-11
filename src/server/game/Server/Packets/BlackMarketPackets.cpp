/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "BlackMarketMgr.h"
#include "Player.h"

void WorldPackets::BlackMarket::BlackMarketItem::Initialize(BlackMarketEntry *const entry, Player* player)
{
    BlackMarketTemplate const* templ = entry->GetTemplate();

    MarketID = entry->GetMarketId();
    SellerNPC = templ->SellerNPC;
    Item = templ->Item;
    Quantity = templ->Quantity;

    // No bids yet
    if (!entry->GetNumBids())
    {
        MinBid = templ->MinBid;
        MinIncrement = 1;
    }
    else
    {
        MinIncrement = entry->GetMinIncrement(); // 5% increment minimum
        MinBid = entry->GetCurrentBid() + MinIncrement;
    }

    CurrentBid = entry->GetCurrentBid();
    SecondsRemaining = entry->GetSecondsRemaining();
    HighBid = (entry->GetBidder() == player->GetGUID().GetCounter());
    NumBids = entry->GetNumBids();
}

void WorldPackets::BlackMarket::BlackMarketOpen::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketOpenResult::Write()
{
    _worldPacket << Guid;
    _worldPacket.WriteBit(Enable);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::BlackMarket::BlackMarketRequestItems::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> LastUpdateID;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BlackMarket::BlackMarketItem const& blackMarketItem)
{
    data << int32(blackMarketItem.MarketID);
    data << int32(blackMarketItem.SellerNPC);
    data << blackMarketItem.Item;
    data << int32(blackMarketItem.Quantity);
    data << uint64(blackMarketItem.MinBid);
    data << uint64(blackMarketItem.MinIncrement);
    data << uint64(blackMarketItem.CurrentBid);
    data << int32(blackMarketItem.SecondsRemaining);
    data << int32(blackMarketItem.NumBids);
    data.WriteBit(blackMarketItem.HighBid);
    data.FlushBits();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::BlackMarket::BlackMarketItem& blackMarketItem)
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
    blackMarketItem.HighBid = data.ReadBit();

    return data;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketRequestItemsResult::Write()
{
    _worldPacket << uint32(LastUpdateID);
    _worldPacket << uint32(Items.size());

    for (BlackMarketItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

void WorldPackets::BlackMarket::BlackMarketBidOnItem::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> MarketID;
    _worldPacket >> Item;
    _worldPacket >> BidAmount;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketBidOnItemResult::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << Item;
    _worldPacket << int32(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketOutbid::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << Item;
    _worldPacket << int32(RandomPropertiesID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketWon::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << Item;
    _worldPacket << int32(RandomPropertiesID);

    return &_worldPacket;
}
