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

#include "AuctionHousePackets.h"

void WorldPackets::AuctionHouse::AuctionHelloRequest::Read()
{
    _worldPacket >> Guid;
}

WorldPackets::AuctionHouse::AuctionHelloResponse::AuctionHelloResponse()
    : ServerPacket(SMSG_AUCTION_HELLO, 13) { }

WorldPacket const* WorldPackets::AuctionHouse::AuctionHelloResponse::Write()
{
    _worldPacket << uint64(Guid);
    _worldPacket << uint32(Entry);
    _worldPacket << uint8(OpenForBusiness ? 1 : 0); // 3.3.3: 1 - AH enabled, 0 - AH disabled

    return &_worldPacket;
}

WorldPackets::AuctionHouse::AuctionCommandResult::AuctionCommandResult()
    : ServerPacket(SMSG_AUCTION_COMMAND_RESULT, 16) { }

WorldPacket const* WorldPackets::AuctionHouse::AuctionCommandResult::Write()
{
    _worldPacket << uint32(AuctionId);
    _worldPacket << uint32(Action);
    _worldPacket << uint32(ErrorCode);

    if (!ErrorCode && Action)
        _worldPacket << uint32(BidError);                                   //when bid, then send 0, once...

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionBidderNotify::Write()
{
    _worldPacket << uint32(HouseID);
    _worldPacket << uint32(AuctionID);
    _worldPacket << BidderGuid;
    _worldPacket << uint32(BidSum);
    _worldPacket << uint32(OutBid);
    _worldPacket << uint32(ItemID);
    _worldPacket << uint32(0);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionOwnerNotify::Write()
{
    if (Entry)
    {
        _worldPacket << uint32(Entry->Id);
        _worldPacket << uint32(Entry->bid);
        _worldPacket << uint32(0);                                      //unk
        _worldPacket << uint64(0);                                      //unk (bidder guid?)
        _worldPacket << uint32(Entry->itemEntry);
        _worldPacket << uint32(0);                                      //unk
        _worldPacket << float(0);                                       //unk (time?)
    }

    return &_worldPacket;
}

void WorldPackets::AuctionHouse::AuctionSellItem::Read()
{
    _worldPacket >> Auctioneer;

    uint32 ItemsCount = _worldPacket.read<uint32>();

    for (uint32 i = 0; i < ItemsCount; ++i)
    {
        WorldPackets::AuctionHouse::AuctionSellItem::AuctionItemForSale item;
        _worldPacket >> item.Guid;
        _worldPacket >> item.UseCount;
        Items.emplace_back(item);
    }

    _worldPacket >> MinBid;
    _worldPacket >> BuyoutPrice;
    _worldPacket >> RunTime;
}
