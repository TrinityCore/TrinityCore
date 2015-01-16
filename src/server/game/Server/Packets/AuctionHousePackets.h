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

#ifndef AuctionHousePackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

struct AuctionEntry;

namespace WorldPackets
{
    namespace AuctionHouse
    {
        class AuctionHello final : public ClientPacket
        {
        public:
            AuctionHello(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_HELLO, std::move(packet)) { }
            
            void Read() override;
            ObjectGuid Guid;
        };

        class AuctionHelloResponse final : public ServerPacket
        {
        public:
            AuctionHelloResponse() : ServerPacket(SMSG_AUCTION_HELLO, 1 + 16) { }
            
            WorldPacket const* Write() override;
            
            ObjectGuid Guid;
            bool OpenForBusiness = true;
        };
        
        class AuctionCommandResult final : public ServerPacket
        {
            public:
                AuctionCommandResult();

                /**
                 * @fn  void WorldPackets::AuctionHousePackets::AuctionCommandResult::InitializeAuction(AuctionEntry* auction);
                 *
                 * @brief   Initialize the following fields: AuctionId, Bid, AuctionOutBid, Bidder
                 *
                 * @param   auction         The relevant auction object
                 */
                void InitializeAuction(AuctionEntry* auction);

                WorldPacket const* Write() override;

                uint32 AuctionId     = 0; ///< the id of the auction that triggered this notification
                uint32 Action        = 0; ///< the type of action that triggered this notification. Possible values are @ref AuctionAction
                uint32 ErrorCode     = 0; ///< the error code that was generated when trying to perform the action. Possible values are @ref AuctionError
                uint64 Bid           = 0; ///< the amount of money that the player bid in copper
                uint32 BidError      = 0; ///< the bid error. Possible values are @ref AuctionError
                ObjectGuid Bidder;        ///< the GUID of the bidder for this auction.
                uint64 AuctionOutBid = 0; ///< the sum of outbid is (1% of current bid) * 5, if the bid is too small, then this value is 1 copper.
        };
    }
}

#endif // AuctionHousePackets_h__
