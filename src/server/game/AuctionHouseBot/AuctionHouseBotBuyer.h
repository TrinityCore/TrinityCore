/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef AUCTION_HOUSE_BOT_BUYER_H
#define AUCTION_HOUSE_BOT_BUYER_H

#include "Define.h"
#include "AuctionHouseMgr.h"
#include "AuctionHouseBot.h"

struct BuyerAuctionEval
{
    BuyerAuctionEval() : AuctionId(0), LastChecked(0), LastExist(0) { }

    uint32  AuctionId;
    time_t  LastChecked;
    time_t  LastExist;
};

struct BuyerItemInfo
{
    BuyerItemInfo() : BidItemCount(0), BuyItemCount(0), MinBuyPrice(0), MinBidPrice(0), TotalBuyPrice(0), TotalBidPrice(0) { }

    uint32  BidItemCount;
    uint32  BuyItemCount;
    uint32  MinBuyPrice;
    uint32  MinBidPrice;
    double  TotalBuyPrice;
    double  TotalBidPrice;
};

typedef std::map<uint32, BuyerItemInfo> BuyerItemInfoMap;
typedef std::map<uint32, BuyerAuctionEval> CheckEntryMap;

struct BuyerConfiguration
{
    BuyerConfiguration() : BuyerEnabled(false), _houseType(AUCTION_HOUSE_NEUTRAL) { }

    void Initialize(AuctionHouseType houseType)
    {
        _houseType = houseType;
    }

    AuctionHouseType GetHouseType() const { return _houseType; }

    BuyerItemInfoMap SameItemInfo;
    CheckEntryMap EligibleItems;
    bool BuyerEnabled;

private:
    AuctionHouseType _houseType;
};

// This class handle all Buyer method
// (holder of AuctionBotConfig for each auction house type)
class TC_GAME_API AuctionBotBuyer : public AuctionBotAgent
{
public:
    AuctionBotBuyer();
    ~AuctionBotBuyer();

    bool Initialize() override;
    bool Update(AuctionHouseType houseType) override;

    void LoadConfig();
    void BuyAndBidItems(BuyerConfiguration& config);

private:
    uint32 _checkInterval;
    BuyerConfiguration _houseConfig[MAX_AUCTION_HOUSE_TYPE];

    void LoadBuyerValues(BuyerConfiguration& config);

    // ahInfo can be NULL
    bool RollBuyChance(BuyerItemInfo const* ahInfo, Item const* item, AuctionEntry const* auction, uint32 bidPrice);
    bool RollBidChance(BuyerItemInfo const* ahInfo, Item const* item, AuctionEntry const* auction, uint32 bidPrice);
    void PlaceBidToEntry(AuctionEntry* auction, uint32 bidPrice);
    void BuyEntry(AuctionEntry* auction, AuctionHouseObject* auctionHouse);
    void PrepareListOfEntry(BuyerConfiguration& config);
    uint32 GetItemInformation(BuyerConfiguration& config);
    uint32 GetVendorPrice(uint32 quality);
    uint32 GetChanceMultiplier(uint32 quality);
};

#endif
