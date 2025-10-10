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

#include "TokenPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Token
{
void CommerceTokenGetLog::Read()
{
    _worldPacket >> ClientToken;
}

WorldPacket const* CommerceTokenGetLogResponse::Write()
{
    _worldPacket << ClientToken;
    _worldPacket << Result;
    _worldPacket << Size<uint32>(AuctionableTokens);
    for (AuctionableTokenInfo const& auctionableTokenAuctionable : AuctionableTokens)
    {
        _worldPacket << auctionableTokenAuctionable.Id;
        _worldPacket << auctionableTokenAuctionable.LastUpdate;
        _worldPacket << auctionableTokenAuctionable.Status;
        _worldPacket << auctionableTokenAuctionable.Price;
        _worldPacket << auctionableTokenAuctionable.DurationLeft;
    }

    return &_worldPacket;
}

void CommerceTokenGetMarketPrice::Read()
{
    _worldPacket >> ClientToken;
}

WorldPacket const* CommerceTokenGetMarketPriceResponse::Write()
{
    _worldPacket << ClientToken;
    _worldPacket << ServerToken;
    _worldPacket << PriceGuarantee;
    _worldPacket << PriceLockDurationSeconds;

    return &_worldPacket;
}
}
