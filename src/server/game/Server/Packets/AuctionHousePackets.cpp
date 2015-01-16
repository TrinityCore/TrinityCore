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
#include "AuctionHouseMgr.h"
#include "ObjectGuid.h"

void WorldPackets::AuctionHouse::AuctionHello::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionHelloResponse::Write()
{
    _worldPacket << Guid;
    _worldPacket.WriteBit(OpenForBusiness);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPackets::AuctionHouse::AuctionCommandResult::AuctionCommandResult()
    : ServerPacket(SMSG_AUCTION_COMMAND_RESULT, 4 + 4 + 4 + 8 + 4 + 8 + 8 + 8) { }

void WorldPackets::AuctionHouse::AuctionCommandResult::InitializeAuction(AuctionEntry* auction)
{
    if (auction)
    {
        AuctionId     = auction->Id;
        Bid           = auction->bid;
        AuctionOutBid = auction->GetAuctionOutBid();
        Bidder        = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
    }
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionCommandResult::Write()
{
    _worldPacket << uint32(AuctionId);
    _worldPacket << uint32(Action);
    _worldPacket << uint32(ErrorCode);

    switch (ErrorCode)
    {
        case ERR_AUCTION_OK:
            if (Action == AUCTION_PLACE_BID)
                _worldPacket << uint64(Bid ? AuctionOutBid : 0);
            break;
        case ERR_AUCTION_INVENTORY:
            _worldPacket << uint32(BidError);
            break;
        case ERR_AUCTION_HIGHER_BID:
            _worldPacket << Bidder;
            _worldPacket << uint64(Bid);
            _worldPacket << uint64(Bid ? AuctionOutBid : 0);
            break;
    }

    return &_worldPacket;
}
