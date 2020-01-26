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

#ifndef TokenPackets_h__
#define TokenPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Token
    {
        class UpdateListedAuctionableTokens final : public ClientPacket
        {
        public:
            UpdateListedAuctionableTokens(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_WOW_TOKEN_AUCTIONABLE_LIST, std::move(packet)) { }

            void Read() override;

            uint32 UnkInt   = 0;
        };

        class UpdateListedAuctionableTokensResponse final : public ServerPacket
        {
        public:
            UpdateListedAuctionableTokensResponse() : ServerPacket(SMSG_WOW_TOKEN_UPDATE_AUCTIONABLE_LIST_RESPONSE, 12) { }

            WorldPacket const* Write() override;

            struct AuctionableTokenAuctionable
            {
                uint64 UnkInt1      = 0;
                uint32 UnkInt2      = 0;
                uint32 Owner        = 0;
                uint64 BuyoutPrice  = 0;
                uint32 EndTime      = 0;
            };

            uint32 UnkInt           = 0; // send CMSG_UPDATE_WOW_TOKEN_AUCTIONABLE_LIST
            uint32 Result           = 0;
            std::vector<AuctionableTokenAuctionable> AuctionableTokenAuctionableList;
        };

        class RequestWowTokenMarketPrice final : public ClientPacket
        {
        public:
            RequestWowTokenMarketPrice(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_WOW_TOKEN_MARKET_PRICE, std::move(packet)) { }

            void Read() override;

            uint32 UnkInt = 0;
        };

        class WowTokenMarketPriceResponse final : public ServerPacket
        {
        public:
            WowTokenMarketPriceResponse() : ServerPacket(SMSG_WOW_TOKEN_MARKET_PRICE_RESPONSE, 20) { }

            WorldPacket const* Write() override;

            uint64 CurrentMarketPrice   = 0;
            uint32 UnkInt               = 0; // send CMSG_REQUEST_WOW_TOKEN_MARKET_PRICE
            uint32 Result               = 0;
            uint32 AuctionDuration      = 0; // preset auction duration enum
        };
    }
}

#endif // TokenPackets_h__
