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

#ifndef TRINITYCORE_AUCTION_HOUSE_PACKETS_H
#define TRINITYCORE_AUCTION_HOUSE_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace AuctionHouse
    {
        class AuctionHelloRequest final : public ClientPacket
        {
        public:
            explicit AuctionHelloRequest(WorldPacket&& packet) : ClientPacket(MSG_AUCTION_HELLO, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class AuctionHelloResponse final : public ServerPacket
        {
        public:
            explicit AuctionHelloResponse() : ServerPacket(MSG_AUCTION_HELLO, 8 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Auctioneer;
            int32 AuctionHouseID = 0;
            bool OpenForBusiness = true;
        };

        class AuctionCommandResult final : public ServerPacket
        {
        public:
            explicit AuctionCommandResult() : ServerPacket(SMSG_AUCTION_COMMAND_RESULT, 4 + 4 + 4 + 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 AuctionID      = 0; ///< the id of the auction that triggered this notification
            int32 Command        = 0; ///< the type of action that triggered this notification. Possible values are @ref AuctionAction
            int32 ErrorCode      = 0; ///< the error code that was generated when trying to perform the action. Possible values are @ref AuctionError
            int32 BagResult      = 0; ///< the bid error. Possible values are @ref AuctionError
            ObjectGuid Guid;          ///< the GUID of the bidder for this auction.
            uint32 MinIncrement  = 0; ///< the sum of outbid is (1% of current bid) * 5, if the bid is too small, then this value is 1 copper.
            uint32 Money         = 0; ///< the amount of money that the player bid in copper
        };
    }
}

#endif // TRINITYCORE_AUCTION_HOUSE_PACKETS_H
