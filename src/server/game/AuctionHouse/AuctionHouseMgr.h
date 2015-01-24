/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _AUCTION_HOUSE_MGR_H
#define _AUCTION_HOUSE_MGR_H

#include "Common.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"

class Item;
class Player;
class WorldPacket;

#define MIN_AUCTION_TIME (12*HOUR)
#define MAX_AUCTION_ITEMS 160

enum AuctionError
{
    ERR_AUCTION_OK                  = 0,
    ERR_AUCTION_INVENTORY           = 1,
    ERR_AUCTION_DATABASE_ERROR      = 2,
    ERR_AUCTION_NOT_ENOUGHT_MONEY   = 3,
    ERR_AUCTION_ITEM_NOT_FOUND      = 4,
    ERR_AUCTION_HIGHER_BID          = 5,
    ERR_AUCTION_BID_INCREMENT       = 7,
    ERR_AUCTION_BID_OWN             = 10,
    ERR_AUCTION_RESTRICTED_ACCOUNT  = 13
};

enum AuctionAction
{
    AUCTION_SELL_ITEM   = 0,
    AUCTION_CANCEL      = 1,
    AUCTION_PLACE_BID   = 2
};

enum MailAuctionAnswers
{
    AUCTION_OUTBIDDED           = 0,
    AUCTION_WON                 = 1,
    AUCTION_SUCCESSFUL          = 2,
    AUCTION_EXPIRED             = 3,
    AUCTION_CANCELLED_TO_BIDDER = 4,
    AUCTION_CANCELED            = 5,
    AUCTION_SALE_PENDING        = 6
};

struct AuctionEntry
{
    uint32 Id;
    uint32 auctioneer;                                      // creature low guid
    uint32 itemGUIDLow;
    uint32 itemEntry;
    uint32 itemCount;
    uint32 owner;
    uint32 startbid;                                        //maybe useless
    uint32 bid;
    uint32 buyout;
    time_t expire_time;
    uint32 bidder;
    uint32 deposit;                                         //deposit can be calculated only when creating auction
    AuctionHouseEntry const* auctionHouseEntry;             // in AuctionHouse.dbc
    uint32 factionTemplateId;

    // helpers
    uint32 GetHouseId() const { return auctionHouseEntry->houseId; }
    uint32 GetHouseFaction() const { return auctionHouseEntry->faction; }
    uint32 GetAuctionCut() const;
    uint32 GetAuctionOutBid() const;
    bool BuildAuctionInfo(WorldPacket & data) const;
    void DeleteFromDB(SQLTransaction& trans) const;
    void SaveToDB(SQLTransaction& trans) const;
    bool LoadFromDB(Field* fields);
    std::string BuildAuctionMailSubject(MailAuctionAnswers response) const;
    static std::string BuildAuctionMailBody(uint32 lowGuid, uint32 bid, uint32 buyout, uint32 deposit, uint32 cut);

};

//this class is used as auctionhouse instance
class AuctionHouseObject
{
  public:
    ~AuctionHouseObject()
    {
        for (AuctionEntryMap::iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
            delete itr->second;
    }

    typedef std::map<uint32, AuctionEntry*> AuctionEntryMap;

    uint32 Getcount() const { return AuctionsMap.size(); }

    AuctionEntryMap::iterator GetAuctionsBegin() {return AuctionsMap.begin();}
    AuctionEntryMap::iterator GetAuctionsEnd() {return AuctionsMap.end();}

    AuctionEntry* GetAuction(uint32 id) const
    {
        AuctionEntryMap::const_iterator itr = AuctionsMap.find(id);
        return itr != AuctionsMap.end() ? itr->second : NULL;
    }

    void AddAuction(AuctionEntry* auction);

    bool RemoveAuction(AuctionEntry* auction);

    void Update();

    void BuildListBidderItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount);
    void BuildListOwnerItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount);
    void BuildListAuctionItems(WorldPacket& data, Player* player,
        std::wstring const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
        uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
        uint32& count, uint32& totalcount);

  private:
    AuctionEntryMap AuctionsMap;
};

class AuctionHouseMgr
{
    private:
        AuctionHouseMgr();
        ~AuctionHouseMgr();

    public:
        static AuctionHouseMgr* instance()
        {
            static AuctionHouseMgr instance;
            return &instance;
        }

        typedef std::unordered_map<uint32, Item*> ItemMap;

        AuctionHouseObject* GetAuctionsMap(uint32 factionTemplateId);
        AuctionHouseObject* GetBidsMap(uint32 factionTemplateId);

        Item* GetAItem(uint32 id)
        {
            ItemMap::const_iterator itr = mAitems.find(id);
            if (itr != mAitems.end())
                return itr->second;

            return NULL;
        }

        //auction messages
        void SendAuctionWonMail(AuctionEntry* auction, SQLTransaction& trans);
        void SendAuctionSalePendingMail(AuctionEntry* auction, SQLTransaction& trans);
        void SendAuctionSuccessfulMail(AuctionEntry* auction, SQLTransaction& trans);
        void SendAuctionExpiredMail(AuctionEntry* auction, SQLTransaction& trans);
        void SendAuctionOutbiddedMail(AuctionEntry* auction, uint32 newPrice, Player* newBidder, SQLTransaction& trans);
        void SendAuctionCancelledToBidderMail(AuctionEntry* auction, SQLTransaction& trans);

        static uint32 GetAuctionDeposit(AuctionHouseEntry const* entry, uint32 time, Item* pItem, uint32 count);
        static AuctionHouseEntry const* GetAuctionHouseEntry(uint32 factionTemplateId);

    public:

        //load first auction items, because of check if item exists, when loading
        void LoadAuctionItems();
        void LoadAuctions();

        void AddAItem(Item* it);
        bool RemoveAItem(uint32 id, bool deleteItem = false);

        void Update();

    private:

        AuctionHouseObject mHordeAuctions;
        AuctionHouseObject mAllianceAuctions;
        AuctionHouseObject mNeutralAuctions;

        ItemMap mAitems;
};

#define sAuctionMgr AuctionHouseMgr::instance()

#endif
