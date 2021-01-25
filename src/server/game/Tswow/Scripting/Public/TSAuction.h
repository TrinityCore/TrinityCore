/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSMain.h"
#include "TSString.h"
#include "TSArray.h"

struct AuctionEntry;

struct TC_GAME_API TSAuctionEntry {
    AuctionEntry* entry;

    TSAuctionEntry(AuctionEntry* entry);

    TSAuctionEntry* operator->() {return this;}
    
    uint32 GetID();
    uint8 GetHouseID();
    uint64 GetItemID();
    uint32 GetItemEntry();
    uint32 GetItemCount();
    uint64 GetOwnerID();
    uint32 GetStartBid();
    uint32 GetBid();
    uint32 GetBuyout();
    uint64 GetExpireTime();
    uint64 GetBidder();
    uint32 GetDeposit();
    uint32 GetETime();
    TSArray<uint64> GetBidders();
    uint32 GetFlags();

    void SetItemID(uint64 itemId);
    void SetItemEntry(uint32 itemEntry);
    void SetItemCount(uint32 itemCount);
    void SetOwnerID(uint64 ownerId);
    void SetStartBid(uint32 startBid);
    void SetBid(uint32 bid);
    void SetBuyout(uint32 buyout);
    void SetBidder(uint64 bidder);
    void SetDeposit(uint32 deposit);
    void SetETime(uint32 eTime);
    void SetFlags(uint32 flags);
};

class AuctionHouseObject;
struct TC_GAME_API TSAuctionHouseObject {
    AuctionHouseObject* obj;
    TSAuctionHouseObject(AuctionHouseObject* obj) { this->obj = obj;};
    TSAuctionHouseObject* operator->(){return this;}

    TSArray<uint32> GetKeys();
    TSAuctionEntry GetEntry(uint32 key);
    bool RemoveAuction(uint32 key);
    bool RemoveAuction(TSAuctionEntry entry);
    uint32 GetCount();
    void AddAuction(TSAuctionEntry entry);
};