/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "ObjectGuid.h"
#include <map>
#include <set>
#include <unordered_map>

class Item;
class Player;
class WorldPacket;
struct AuctionHouseEntry;

#define MIN_AUCTION_TIME (12*HOUR)
#define MAX_AUCTION_ITEMS 160
#define MAX_GETALL_RETURN 55000

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

enum AuctionHouses
{
    AUCTIONHOUSE_ALLIANCE       = 2,
    AUCTIONHOUSE_HORDE          = 6,
    AUCTIONHOUSE_NEUTRAL        = 7
};

struct TC_GAME_API AuctionEntry
{
    uint32 Id;
    uint8 houseId;
    ObjectGuid::LowType itemGUIDLow;
    uint32 itemEntry;
    uint32 itemCount;
    ObjectGuid::LowType owner;
    uint32 startbid;                                        //maybe useless
    uint32 bid;
    uint32 buyout;
    time_t expire_time;
    ObjectGuid::LowType bidder;
    uint32 deposit;                                         //deposit can be calculated only when creating auction
    uint32 etime;
    std::unordered_set<ObjectGuid> bidders;
    AuctionHouseEntry const* auctionHouseEntry;             // in AuctionHouse.dbc

    // helpers
    uint8 GetHouseId() const { return houseId; }
    uint32 GetAuctionCut() const;
    uint32 GetAuctionOutBid() const;
    bool BuildAuctionInfo(WorldPacket & data, Item* sourceItem = nullptr) const;
    void DeleteFromDB(SQLTransaction& trans) const;
    void SaveToDB(SQLTransaction& trans) const;
    bool LoadFromDB(Field* fields);
    std::string BuildAuctionMailSubject(MailAuctionAnswers response) const;
    static std::string BuildAuctionMailBody(ObjectGuid::LowType lowGuid, uint32 bid, uint32 buyout, uint32 deposit, uint32 cut);

};

//this class is used as auctionhouse instance
class TC_GAME_API AuctionHouseObject
{
  public:
    ~AuctionHouseObject()
    {
        for (AuctionEntryMap::iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
            delete itr->second;
    }

    typedef std::map<uint32, AuctionEntry*> AuctionEntryMap;
    typedef std::unordered_map<ObjectGuid, time_t> PlayerGetAllThrottleMap;

    uint32 Getcount() const { return AuctionsMap.size(); }

    AuctionEntryMap::iterator GetAuctionsBegin() {return AuctionsMap.begin();}
    AuctionEntryMap::iterator GetAuctionsEnd() {return AuctionsMap.end();}

    AuctionEntry* GetAuction(uint32 id) const
    {
        AuctionEntryMap::const_iterator itr = AuctionsMap.find(id);
        return itr != AuctionsMap.end() ? itr->second : nullptr;
    }

    void AddAuction(AuctionEntry* auction);

    bool RemoveAuction(AuctionEntry* auction);

    void Update();

    void BuildListBidderItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount);
    void BuildListOwnerItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount);
    void BuildListAuctionItems(WorldPacket& data, Player* player,
        std::wstring const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
        uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
        uint32& count, uint32& totalcount, bool getall = false);

  private:
    AuctionEntryMap AuctionsMap;

    // Map of throttled players for GetAll, and throttle expiry time
    // Stored here, rather than player object to maintain persistence after logout
    PlayerGetAllThrottleMap GetAllThrottleMap;

};

class TC_GAME_API AuctionHouseMgr
{
    private:
        AuctionHouseMgr();
        ~AuctionHouseMgr();

    public:
        static AuctionHouseMgr* instance();

        typedef std::unordered_map<ObjectGuid::LowType, Item*> ItemMap;
        typedef std::vector<AuctionEntry*> PlayerAuctions;
        typedef std::pair<PlayerAuctions*, uint32> AuctionPair;

        AuctionHouseObject* GetAuctionsMap(uint32 factionTemplateId);
        AuctionHouseObject* GetAuctionsMapByHouseId(uint8 auctionHouseId);

        Item* GetAItem(ObjectGuid::LowType id)
        {
            ItemMap::const_iterator itr = mAitems.find(id);
            if (itr != mAitems.end())
                return itr->second;

            return nullptr;
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
        static AuctionHouseEntry const* GetAuctionHouseEntryFromHouse(uint8 houseId);
    public:

        //load first auction items, because of check if item exists, when loading
        void LoadAuctionItems();
        void LoadAuctions();

        void AddAItem(Item* it);
        bool RemoveAItem(ObjectGuid::LowType id, bool deleteItem = false, SQLTransaction* trans = nullptr);
        bool PendingAuctionAdd(Player* player, AuctionEntry* aEntry, Item* item);
        uint32 PendingAuctionCount(Player const* player) const;
        void PendingAuctionProcess(Player* player);
        void UpdatePendingAuctions();
        void Update();

    private:

        AuctionHouseObject mHordeAuctions;
        AuctionHouseObject mAllianceAuctions;
        AuctionHouseObject mNeutralAuctions;

        std::map<ObjectGuid, AuctionPair> pendingAuctionMap;

        ItemMap mAitems;
};

#define sAuctionMgr AuctionHouseMgr::instance()

#endif
