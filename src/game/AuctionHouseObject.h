/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _AUCTION_HOUSE_H
#define _AUCTION_HOUSE_H

#include "SharedDefines.h"

#define MIN_AUCTION_TIME (12*HOUR)

enum AuctionError
{
    AUCTION_OK = 0,
    AUCTION_INTERNAL_ERROR = 2,
    AUCTION_NOT_ENOUGHT_MONEY = 3,
    AUCTION_ITEM_NOT_FOUND = 4,
    CANNOT_BID_YOUR_AUCTION_ERROR = 10
};

enum AuctionAction
{
    AUCTION_SELL_ITEM = 0,
    AUCTION_CANCEL = 1,
    AUCTION_PLACE_BID = 2
};

struct AuctionEntry
{
    uint32 Id;
    uint32 auctioneer;
    uint32 item_guidlow;
    uint32 item_template;
    uint32 owner;
    uint32 startbid;                                        //maybe useless
    uint32 bid;
    uint32 buyout;
    time_t time;
    uint32 bidder;
    uint32 deposit;                                         //deposit can be calculated only when creating auction
    uint32 location;
};

//this class is used as auctionhouse instance
class AuctionHouseObject
{
    public:
        AuctionHouseObject() {}
        ~AuctionHouseObject()
        {
            for (AuctionEntryMap::iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
                delete itr->second;
        }

        typedef std::map<uint32, AuctionEntry*> AuctionEntryMap;

        uint32 Getcount() { return AuctionsMap.size(); }

        AuctionEntryMap::iterator GetAuctionsBegin() {return AuctionsMap.begin();}
        AuctionEntryMap::iterator GetAuctionsEnd() {return AuctionsMap.end();}

        void AddAuction(AuctionEntry *ah)
        {
            ASSERT( ah );
            AuctionsMap[ah->Id] = ah;
        }

        AuctionEntry* GetAuction(uint32 id) const
        {
            AuctionEntryMap::const_iterator itr = AuctionsMap.find( id );
            if( itr != AuctionsMap.end() )
                return itr->second;
            return NULL;
        }

        bool RemoveAuction(uint32 id)
        {
            AuctionEntryMap::iterator i = AuctionsMap.find(id);
            if (i == AuctionsMap.end())
            {
                return false;
            }
            AuctionsMap.erase(i);
            return true;
        }

    private:
        AuctionEntryMap AuctionsMap;
};
#endif

