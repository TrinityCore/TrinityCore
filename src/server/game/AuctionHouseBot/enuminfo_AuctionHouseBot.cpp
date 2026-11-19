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

#include "AuctionHouseBot.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/************************************************************************\
|* data for enum 'AuctionQuality' in 'AuctionHouseBot.h' auto-generated *|
\************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<AuctionQuality>::ToString(AuctionQuality value)
{
    switch (value)
    {
        case AUCTION_QUALITY_GRAY: return { "AUCTION_QUALITY_GRAY", "AUCTION_QUALITY_GRAY", "" };
        case AUCTION_QUALITY_WHITE: return { "AUCTION_QUALITY_WHITE", "AUCTION_QUALITY_WHITE", "" };
        case AUCTION_QUALITY_GREEN: return { "AUCTION_QUALITY_GREEN", "AUCTION_QUALITY_GREEN", "" };
        case AUCTION_QUALITY_BLUE: return { "AUCTION_QUALITY_BLUE", "AUCTION_QUALITY_BLUE", "" };
        case AUCTION_QUALITY_PURPLE: return { "AUCTION_QUALITY_PURPLE", "AUCTION_QUALITY_PURPLE", "" };
        case AUCTION_QUALITY_ORANGE: return { "AUCTION_QUALITY_ORANGE", "AUCTION_QUALITY_ORANGE", "" };
        case AUCTION_QUALITY_YELLOW: return { "AUCTION_QUALITY_YELLOW", "AUCTION_QUALITY_YELLOW", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuctionQuality>::Count() { return 7; }

template <>
TC_API_EXPORT AuctionQuality EnumUtils<AuctionQuality>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return AUCTION_QUALITY_GRAY;
        case 1: return AUCTION_QUALITY_WHITE;
        case 2: return AUCTION_QUALITY_GREEN;
        case 3: return AUCTION_QUALITY_BLUE;
        case 4: return AUCTION_QUALITY_PURPLE;
        case 5: return AUCTION_QUALITY_ORANGE;
        case 6: return AUCTION_QUALITY_YELLOW;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuctionQuality>::ToIndex(AuctionQuality value)
{
    switch (value)
    {
        case AUCTION_QUALITY_GRAY: return 0;
        case AUCTION_QUALITY_WHITE: return 1;
        case AUCTION_QUALITY_GREEN: return 2;
        case AUCTION_QUALITY_BLUE: return 3;
        case AUCTION_QUALITY_PURPLE: return 4;
        case AUCTION_QUALITY_ORANGE: return 5;
        case AUCTION_QUALITY_YELLOW: return 6;
        default: throw std::out_of_range("value");
    }
}

/**************************************************************************\
|* data for enum 'AuctionHouseType' in 'AuctionHouseBot.h' auto-generated *|
\**************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<AuctionHouseType>::ToString(AuctionHouseType value)
{
    switch (value)
    {
        case AUCTION_HOUSE_NEUTRAL: return { "AUCTION_HOUSE_NEUTRAL", "AUCTION_HOUSE_NEUTRAL", "" };
        case AUCTION_HOUSE_ALLIANCE: return { "AUCTION_HOUSE_ALLIANCE", "AUCTION_HOUSE_ALLIANCE", "" };
        case AUCTION_HOUSE_HORDE: return { "AUCTION_HOUSE_HORDE", "AUCTION_HOUSE_HORDE", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuctionHouseType>::Count() { return 3; }

template <>
TC_API_EXPORT AuctionHouseType EnumUtils<AuctionHouseType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return AUCTION_HOUSE_NEUTRAL;
        case 1: return AUCTION_HOUSE_ALLIANCE;
        case 2: return AUCTION_HOUSE_HORDE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuctionHouseType>::ToIndex(AuctionHouseType value)
{
    switch (value)
    {
        case AUCTION_HOUSE_NEUTRAL: return 0;
        case AUCTION_HOUSE_ALLIANCE: return 1;
        case AUCTION_HOUSE_HORDE: return 2;
        default: throw std::out_of_range("value");
    }
}
}
