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

namespace WorldPackets::AuctionHouse
{
void AuctionHelloRequest::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* AuctionHelloResponse::Write()
{
    _worldPacket << Auctioneer;
    _worldPacket << int32(AuctionHouseID);
    _worldPacket << bool(OpenForBusiness);

    return &_worldPacket;
}

WorldPacket const* AuctionCommandResult::Write()
{
    _worldPacket << int32(AuctionID);
    _worldPacket << int32(Command);
    _worldPacket << int32(ErrorCode);

    switch (ErrorCode)
    {
        case ERR_AUCTION_OK:
            if (Command == AUCTION_PLACE_BID)
                _worldPacket << uint32(MinIncrement);
            break;
        case ERR_AUCTION_INVENTORY:
            _worldPacket << int32(BagResult);
            break;
        case ERR_AUCTION_HIGHER_BID:
            _worldPacket << Guid;
            _worldPacket << uint32(Money);
            _worldPacket << uint32(MinIncrement);
            break;
        default:
            break;
    }

    return &_worldPacket;
}
}
