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

#ifndef BLACK_MARKET_H
#define BLACK_MARKET_H

#include "Common.h"
#include "ObjectGuid.h"
#include "BlackMarketPackets.h"
#include "ItemPackets.h"
#include "Item.h"

enum BlackMarketError              // Extracted from client
{
    ERR_BMAH_OK = 0,
    ERR_BMAH_ITEM_NOT_FOUND = 1,
    ERR_BMAH_ALREADY_BID = 2,
    ERR_BMAH_HIGHER_BID = 4,
    ERR_BMAH_DATABASE_ERROR = 6,
    ERR_BMAH_NOT_ENOUGH_MONEY = 7,
    ERR_BMAH_RESTRICTED_ACCOUNT_TRIAL = 9
};

enum BMAHMailAuctionAnswers
{
    BMAH_AUCTION_OUTBID = 0,
    BMAH_AUCTION_WON = 1,
};

const static uint64 BMAH_MAX_BID = 1000000LL * GOLD;

struct BlackMarketTemplate
{
    int32 MarketID;
    int32 SellerNPC;
    int32 Quantity;
    uint64 MinBid;
    time_t Duration;
    float Chance;
    WorldPackets::Item::ItemInstance Item;

    // Helpers
    bool LoadFromDB(Field* fields);
}; 

class BlackMarketEntry
{
public:

    void Update(time_t newTimeOfUpdate);
    void Initialize(int32 marketId)
    {
        _marketId = marketId;
        _secondsRemaining = GetTemplate()->Duration;
    }

    BlackMarketTemplate* GetTemplate() const;
    int32 GetMarketId() const { return _marketId; }

    uint32 GetCurrentBid() const { return _currentBid; }
    void SetCurrentBid(uint32 bid) { _currentBid = bid; }

    int32 GetNumBids() const { return _numBids; }
    void SetNumBids(int32 numBids) { _numBids = numBids; }

    ObjectGuid::LowType GetBidder() const { return _bidder; }
    void SetBidder(ObjectGuid::LowType bidder) { _bidder = bidder; }

    time_t GetSecondsRemaining() const; // Get seconds remaining relative to now
    time_t GetExpirationTime() const;
    bool IsCompleted() const;

    void DeleteFromDB(SQLTransaction& trans) const;
    void SaveToDB(SQLTransaction& trans) const;
    bool LoadFromDB(Field* fields);

    uint64 GetMinIncrement() const { return (_currentBid / 20) - ((_currentBid / 20) % GOLD); } //5% increase every bid (has to be round gold value)
    bool ValidateBid(uint64 bid) const;
    void PlaceBid(uint64 bid, Player* player, SQLTransaction& trans);

    std::string BuildAuctionMailSubject(BMAHMailAuctionAnswers response) const;
    std::string BuildAuctionMailBody();

    void MailSent() { _mailSent = true; } // Set when mail has been sent
    bool GetMailSent() const { return _mailSent; }

private:
    int32 _marketId = 0;
    uint64 _currentBid = 0;
    int32 _numBids = 0;
    ObjectGuid::LowType _bidder = 0;

    time_t _secondsRemaining;

    bool _mailSent = false;
};

class BlackMarketMgr
{
  private:
    BlackMarketMgr() { }
    ~BlackMarketMgr()
    {
        for (BlackMarketEntryMap::iterator itr = mAuctions.begin(); itr != mAuctions.end(); ++itr)
            delete itr->second;
        for (BlackMarketTemplateMap::iterator itr = mTemplates.begin(); itr != mTemplates.end(); ++itr)
            delete itr->second;
    }

  public:
    static BlackMarketMgr* instance()
    {
        static BlackMarketMgr instance;
        return &instance;
    }

    typedef std::map<int32, BlackMarketEntry*> BlackMarketEntryMap;
    typedef std::map<int32, BlackMarketTemplate*> BlackMarketTemplateMap;

    // Load templates first
    void LoadTemplates();
    void LoadAuctions();

    void Update(bool updateTime = false);
    void RefreshAuctions();
    time_t GetLastUpdate() const { return _LastUpdate; }
        
    bool IsEnabled() const;

    void BuildItemsResponse(WorldPackets::BlackMarket::BlackMarketRequestItemsResult &packet, Player *player);
    
    BlackMarketEntry*     GetAuctionByID(int32 marketId) const;
    BlackMarketTemplate* GetTemplateByID(int32 marketId) const;

    void AddAuction(BlackMarketEntry* auction);
    void AddTemplate(BlackMarketTemplate* templ);

    void SendAuctionWonMail(BlackMarketEntry* entry, SQLTransaction& trans);
    void SendAuctionOutbidMail(BlackMarketEntry* entry, SQLTransaction& trans); // Call before incrementing bid

  private:

      BlackMarketEntryMap mAuctions;
      BlackMarketTemplateMap mTemplates;

      time_t _LastUpdate;
};

#define sBlackMarketMgr BlackMarketMgr::instance()

#endif

