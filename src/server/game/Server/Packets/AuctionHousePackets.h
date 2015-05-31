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
#define AuctionHousePackets_h__

#include "Packet.h"
#include "AuctionHouseMgr.h"

namespace WorldPackets
{
    namespace AuctionHouse
    {
        class AuctionHelloRequest final : public ClientPacket
        {
            public:
                AuctionHelloRequest(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_HELLO, std::move(packet)) { }

                void Read() override;

                ObjectGuid Guid;
        };

        class AuctionHelloResponse final : public ServerPacket
        {
            public:
                AuctionHelloResponse();

                WorldPacket const* Write() override;

                ObjectGuid Guid;
                uint32 Entry;
                bool OpenForBusiness = true;
        };

        class AuctionCommandResult final : public ServerPacket
        {
            public:
                AuctionCommandResult();

                WorldPacket const* Write() override;

                uint32 AuctionId     = 0; ///< the id of the auction that triggered this notification
                uint32 Action        = 0; ///< the type of action that triggered this notification. Possible values are @ref AuctionAction
                uint32 ErrorCode     = 0; ///< the error code that was generated when trying to perform the action. Possible values are @ref AuctionError
                uint32 BidError      = 0; ///< the bid error. Possible values are @ref AuctionError
        };

        class AuctionBidderNotify final : public ServerPacket
        {
            public:
                AuctionBidderNotify() : ServerPacket(SMSG_AUCTION_BIDDER_NOTIFICATION, 32) { }

                WorldPacket const* Write() override;

                uint32 AuctionID = 0;
                uint32 HouseID = 0;
                ObjectGuid BidderGuid;
                uint32 BidSum = 0;
                uint32 OutBid = 0;
                uint32 ItemID = 0;
        };

        class AuctionOwnerNotify final : public ServerPacket
        {
            public:
                AuctionOwnerNotify() : ServerPacket(SMSG_AUCTION_OWNER_NOTIFICATION, 32) { }

                WorldPacket const* Write() override;

                AuctionEntry const* Entry = nullptr;
        };

        class AuctionSellItem final : public ClientPacket
        {
            public:
                struct AuctionItemForSale
                {
                    ObjectGuid Guid;
                    uint32 UseCount = 0;
                };

                AuctionSellItem(WorldPacket&& packet) : ClientPacket(CMSG_AUCTION_SELL_ITEM, std::move(packet)) { }

                void Read() override;

                ObjectGuid Auctioneer;
                uint32 BuyoutPrice = 0;
                uint32 MinBid = 0;
                uint32 RunTime = 0;
                std::vector<AuctionItemForSale> Items;
        };
    }
}

#endif
