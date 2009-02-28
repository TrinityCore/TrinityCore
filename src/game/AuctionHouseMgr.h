/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifndef _AUCTION_HOUSE_MGR_H
#define _AUCTION_HOUSE_MGR_H

#include "SharedDefines.h"
#include "Policies/Singleton.h"

class Item;
class Player;
class WorldPacket;

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
    uint32 auctioneer;                                      // creature low guid
    uint32 item_guidlow;
    uint32 item_template;
    uint32 owner;
    uint32 startbid;                                        //maybe useless
    uint32 bid;
    uint32 buyout;
    time_t expire_time;
    uint32 bidder;
    uint32 deposit;                                         //deposit can be calculated only when creating auction
    AuctionHouseEntry const* auctionHouseEntry;             // in AuctionHouse.dbc

    // helpers
    uint32 GetHouseId() const { return auctionHouseEntry->houseId; }
    uint32 GetHouseFaction() const { return auctionHouseEntry->faction; }
    uint32 GetAuctionCut() const;
    uint32 GetAuctionOutBid() const;
    bool BuildAuctionInfo(WorldPacket & data) const;
    void DeleteFromDB() const;
    void SaveToDB() const;
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
        return itr != AuctionsMap.end() ? itr->second : NULL;
    }

    bool RemoveAuction(uint32 id)
    {
        return AuctionsMap.erase(id) ? true : false;
    }

    void Update();

    void BuildListBidderItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount);
    void BuildListOwnerItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount);
    void BuildListAuctionItems(WorldPacket& data, Player* player,
        std::wstring const& searchedname, uint32 listfrom, uint32 levelmin, uint32 levelmax, uint32 usable,
        uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
        uint32& count, uint32& totalcount);

  private:
    AuctionEntryMap AuctionsMap;
};

class AuctionHouseMgr
{
  public:
    AuctionHouseMgr();
    ~AuctionHouseMgr();

    typedef UNORDERED_MAP<uint32, Item*> ItemMap;

    AuctionHouseObject* GetAuctionsMap( uint32 factionTemplateId );

    Item* GetAItem(uint32 id)
    {
        ItemMap::const_iterator itr = mAitems.find(id);
        if (itr != mAitems.end())
        {
            return itr->second;
        }
        return NULL;
    }

    //auction messages
    void SendAuctionWonMail( AuctionEntry * auction );
    void SendAuctionSalePendingMail( AuctionEntry * auction );
    void SendAuctionSuccessfulMail( AuctionEntry * auction );
    void SendAuctionExpiredMail( AuctionEntry * auction );
    static uint32 GetAuctionDeposit(AuctionHouseEntry const* entry, uint32 time, Item *pItem);
    static AuctionHouseEntry const* GetAuctionHouseEntry(uint32 factionTemplateId);

  public:
    //load first auction items, because of check if item exists, when loading
    void LoadAuctionItems();
    void LoadAuctions();

    void AddAItem(Item* it);
    bool RemoveAItem(uint32 id);

    void Update();

  private:
    AuctionHouseObject mHordeAuctions;
    AuctionHouseObject mAllianceAuctions;
    AuctionHouseObject mNeutralAuctions;

    ItemMap mAitems;
};

#define auctionmgr Trinity::Singleton<AuctionHouseMgr>::Instance()

#endif
