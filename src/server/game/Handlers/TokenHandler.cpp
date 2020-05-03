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
#include "WorldSession.h"

void WorldSession::HandleUpdateListedAuctionableTokens(WorldPackets::Token::UpdateListedAuctionableTokens& updateListedAuctionableTokens)
{
    WorldPackets::Token::UpdateListedAuctionableTokensResponse response;

    /// @todo: 6.x fix implementation
    response.UnkInt = updateListedAuctionableTokens.UnkInt;
    response.Result = TOKEN_RESULT_SUCCESS;

    SendPacket(response.Write());
}

void WorldSession::HandleRequestWowTokenMarketPrice(WorldPackets::Token::RequestWowTokenMarketPrice& requestWowTokenMarketPrice)
{
    WorldPackets::Token::WowTokenMarketPriceResponse response;

    /// @todo: 6.x fix implementation
    response.CurrentMarketPrice = 300000000;
    response.UnkInt = requestWowTokenMarketPrice.UnkInt;
    response.Result = TOKEN_RESULT_SUCCESS;
    //packet.ReadUInt32("UnkInt32");

    SendPacket(response.Write());
}
