/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "ItemTemplate.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <map>
#include <set>
#include <unordered_map>

class Item;
class Player;
class WorldPacket;

namespace WorldPackets
{
    namespace AuctionHouse
    {
        struct AuctionItem;
        class AuctionListBidderItemsResult;
        class AuctionListOwnerItemsResult;
        class AuctionListItemsResult;
        class AuctionReplicateResponse;
    }
}

#define MIN_AUCTION_TIME (12*HOUR)

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

struct TC_GAME_API AuctionEntry
{
    uint32 Id;
    ObjectGuid::LowType auctioneer;                                      // creature low guid
    ObjectGuid::LowType itemGUIDLow;
    uint32 itemEntry;
    uint32 itemCount;
    ObjectGuid::LowType owner;
    uint64 startbid;                                        //maybe useless
    uint64 bid;
    uint64 buyout;
    time_t expire_time;
    ObjectGuid::LowType bidder;
    uint64 deposit;                                         //deposit can be calculated only when creating auction
    uint32 etime;
    uint32 houseId;
    AuctionHouseEntry const* auctionHouseEntry;             // in AuctionHouse.dbc
    uint32 factionTemplateId;

    // helpers
    uint32 GetHouseId() const { return houseId; }
    uint32 GetHouseFaction() const { return auctionHouseEntry->FactionID; }
    uint64 GetAuctionCut() const;
    uint64 GetAuctionOutBid() const;
    void BuildAuctionInfo(std::vector<WorldPackets::AuctionHouse::AuctionItem>& items, bool listAuctionItems, Item* sourceItem = nullptr) const;
    void DeleteFromDB(SQLTransaction& trans) const;
    void SaveToDB(SQLTransaction& trans) const;
    bool LoadFromDB(Field* fields);
    std::string BuildAuctionMailSubject(MailAuctionAnswers response) const;
    static std::string BuildAuctionMailBody(uint64 lowGuid, uint64 bid, uint64 buyout, uint64 deposit, uint64 cut);

};

struct AuctionSearchFilters
{
    enum FilterType : uint32
    {
        FILTER_SKIP_CLASS = 0,
        FILTER_SKIP_SUBCLASS = 0xFFFFFFFF,
        FILTER_SKIP_INVTYPE = 0xFFFFFFFF
    };

    struct SubclassFilter
    {
        uint32 SubclassMask = FILTER_SKIP_CLASS;
        std::array<uint32, MAX_ITEM_SUBCLASS_TOTAL> InvTypes = { };
    };

    std::array<SubclassFilter, MAX_ITEM_CLASS> Classes = { };
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

    struct PlayerGetAllThrottleData
    {
        uint32 Global = 0;
        uint32 Cursor = 0;
        uint32 Tombstone = 0;
        time_t NextAllowedReplication = 0;

        bool IsReplicationInProgress() const { return Cursor != Tombstone && Global != 0; }
    };

    typedef std::unordered_map<ObjectGuid, PlayerGetAllThrottleData> PlayerGetAllThrottleMap;

    uint32 Getcount() const { return uint32(AuctionsMap.size()); }

    AuctionEntryMap::iterator GetAuctionsBegin() { return AuctionsMap.begin(); }
    AuctionEntryMap::iterator GetAuctionsEnd() { return AuctionsMap.end(); }

    AuctionEntry* GetAuction(uint32 id) const
    {
        AuctionEntryMap::const_iterator itr = AuctionsMap.find(id);
        return itr != AuctionsMap.end() ? itr->second : NULL;
    }

    void AddAuction(AuctionEntry* auction);

    bool RemoveAuction(AuctionEntry* auction);

    void Update();

    void BuildListBidderItems(WorldPackets::AuctionHouse::AuctionListBidderItemsResult& packet, Player* player, uint32& totalcount);
    void BuildListOwnerItems(WorldPackets::AuctionHouse::AuctionListOwnerItemsResult& packet, Player* player, uint32& totalcount);
    void BuildListAuctionItems(WorldPackets::AuctionHouse::AuctionListItemsResult& packet, Player* player,
        std::wstring const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, bool usable, Optional<AuctionSearchFilters> const& filters, uint32 quality);
    void BuildReplicate(WorldPackets::AuctionHouse::AuctionReplicateResponse& auctionReplicateResult, Player* player,
        uint32 global, uint32 cursor, uint32 tombstone, uint32 count);

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
        AuctionHouseObject* GetBidsMap(uint32 factionTemplateId);

        Item* GetAItem(ObjectGuid::LowType id)
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
        void SendAuctionOutbiddedMail(AuctionEntry* auction, uint64 newPrice, Player* newBidder, SQLTransaction& trans);
        void SendAuctionCancelledToBidderMail(AuctionEntry* auction, SQLTransaction& trans);

        static uint64 GetAuctionDeposit(AuctionHouseEntry const* entry, uint32 time, Item* pItem, uint32 count);
        static AuctionHouseEntry const* GetAuctionHouseEntry(uint32 factionTemplateId, uint32* houseId);

    public:

        //load first auction items, because of check if item exists, when loading
        void LoadAuctionItems();
        void LoadAuctions();

        void AddAItem(Item* it);
        bool RemoveAItem(ObjectGuid::LowType id, bool deleteItem = false);
        void PendingAuctionAdd(Player* player, AuctionEntry* aEntry);
        uint32 PendingAuctionCount(const Player* player) const;
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
