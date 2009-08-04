#include <vector>
#include <iostream>
#include "time.h"

#include "ObjectMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "Config/ConfigEnv.h"
#include "Database/DatabaseEnv.h"

#include "AuctionHouseBot.h"
#include "AuctionHouseMgr.h"
#include "Bag.h"
#include "Item.h"
#include "Log.h"
#include "Player.h"

using namespace std;

static bool debug_Out = sConfig.GetBoolDefault("AuctionHouseBot.DEBUG", false);

static vector<uint32> npcItems;
static vector<uint32> lootItems;
static vector<uint32> greyTradeGoodsBin;
static vector<uint32> whiteTradeGoodsBin;
static vector<uint32> greenTradeGoodsBin;
static vector<uint32> blueTradeGoodsBin;
static vector<uint32> purpleTradeGoodsBin;
static vector<uint32> orangeTradeGoodsBin;
static vector<uint32> yellowTradeGoodsBin;
static vector<uint32> greyItemsBin;
static vector<uint32> whiteItemsBin;
static vector<uint32> greenItemsBin;
static vector<uint32> blueItemsBin;
static vector<uint32> purpleItemsBin;
static vector<uint32> orangeItemsBin;
static vector<uint32> yellowItemsBin;

static bool AHBSeller = 0;
static bool AHBBuyer = 0;

static bool Vendor_Items = 0;
static bool Loot_Items = 0;
static bool Other_Items = 0;

static bool No_Bind = 0;
static bool Bind_When_Picked_Up = 0;
static bool Bind_When_Equipped = 0;
static bool Bind_When_Use = 0;
static bool Bind_Quest_Item = 0;

static AHBConfig AllianceConfig = AHBConfig(2);
static AHBConfig HordeConfig = AHBConfig(6);
static AHBConfig NeutralConfig = AHBConfig(7);
time_t _lastrun_a;
time_t _lastrun_h;
time_t _lastrun_n;

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static inline uint32 minValue(uint32 a, uint32 b)
{
   return a <= b ? a : b;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
static void addNewAuctions(Player *AHBplayer, AHBConfig *config)
{
    if (!AHBSeller)
        return;
    AuctionHouseEntry const* ahEntry = auctionmgr.GetAuctionHouseEntry(config->GetAHFID());
    AuctionHouseObject* auctionHouse = auctionmgr.GetAuctionsMap(config->GetAHFID());
    uint32 items = 0;
    uint32 minItems = config->GetMinItems();
    uint32 maxItems = config->GetMaxItems();
    uint32 auctions = auctionHouse->Getcount();
    uint32 AuctioneerGUID = 0;
    switch (config->GetAHID()){
        case 2:
            AuctioneerGUID = 79707; //Human in stormwind.
        case 6:
            AuctioneerGUID = 4656; //orc in Orgrimmar
        case 7:
            AuctioneerGUID = 23442; //goblin in GZ
        default:
            AuctioneerGUID = 23442; //default to neutral 7
    }

    if (auctions >= minItems)
      return;
    if (auctions <= maxItems)
    {
        if ((maxItems - auctions) > ItemsPerCycle)
            items = ItemsPerCycle;
        else
            items = (maxItems - auctions);
    }
    uint32 greyTGcount = config->GetPercents(AHB_GREY_TG);
    uint32 whiteTGcount = config->GetPercents(AHB_WHITE_TG);
    uint32 greenTGcount = config->GetPercents(AHB_GREEN_TG);
    uint32 blueTGcount = config->GetPercents(AHB_BLUE_TG);
    uint32 purpleTGcount = config->GetPercents(AHB_PURPLE_TG);
    uint32 orangeTGcount = config->GetPercents(AHB_ORANGE_TG);
    uint32 yellowTGcount = config->GetPercents(AHB_YELLOW_TG);
    uint32 greyIcount = config->GetPercents(AHB_GREY_I);
    uint32 whiteIcount = config->GetPercents(AHB_WHITE_I);
    uint32 greenIcount = config->GetPercents(AHB_GREEN_I);
    uint32 blueIcount = config->GetPercents(AHB_BLUE_I);
    uint32 purpleIcount = config->GetPercents(AHB_PURPLE_I);
    uint32 orangeIcount = config->GetPercents(AHB_ORANGE_I);
    uint32 yellowIcount = config->GetPercents(AHB_YELLOW_I);
    uint32 total = greyTGcount + whiteTGcount + greenTGcount + blueTGcount
                 + purpleTGcount + orangeTGcount + yellowTGcount
                 + whiteIcount + greenIcount + blueIcount + purpleIcount
                 + orangeIcount + yellowIcount;

    uint32 greyTGoods = 0;
    uint32 whiteTGoods = 0;
    uint32 greenTGoods = 0;
    uint32 blueTGoods = 0;
    uint32 purpleTGoods = 0;
    uint32 orangeTGoods = 0;
    uint32 yellowTGoods = 0;

    uint32 greyItems = 0;
    uint32 whiteItems = 0;
    uint32 greenItems = 0;
    uint32 blueItems = 0;
    uint32 purpleItems = 0;
    uint32 orangeItems = 0;
    uint32 yellowItems = 0;

    for (AuctionHouseObject::AuctionEntryMap::iterator itr = auctionHouse->GetAuctionsBegin();itr != auctionHouse->GetAuctionsEnd();++itr)
    {
        AuctionEntry *Aentry = itr->second;
        Item *item = auctionmgr.GetAItem(Aentry->item_guidlow);
        if( item )
        {
            ItemPrototype const *prototype = item->GetProto();
            if( prototype )
            {
                switch (prototype->Quality)
                {
                 case 0:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++greyTGoods;
                    else
                       ++greyItems;
                    break;

                 case 1:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++whiteTGoods;
                    else
                       ++whiteItems;
                    break;

                 case 2:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++greenTGoods;
                    else
                       ++greenItems;
                    break;

                 case 3:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++blueTGoods;
                    else
                       ++blueItems;
                    break;

                 case 4:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++purpleTGoods;
                    else
                       ++purpleItems;
                    break;

                 case 5:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++orangeTGoods;
                    else
                       ++orangeItems;
                    break;

                 case 6:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       ++yellowTGoods;
                    else
                       ++yellowItems;
                    break;
                }
            }
        }
    }
    // only insert a few at a time, so as not to peg the processor
    for (uint32 cnt = 1;cnt <= items;cnt++)
    {
        uint32 itemID = 0;
        while (itemID == 0)
        {
            uint32 choice = urand(0, 13);
            switch (choice)
            {
            case 0:
                {
                    if ((greyItemsBin.size() > 0) && (greyItems < greyIcount))
                    {
                         itemID = greyItemsBin[urand(0, greyItemsBin.size() - 1)];
                         ++greyItems;
                         break;
                    }
                }
            case 1:
                {
                    if ((whiteItemsBin.size() > 0) && (whiteItems < whiteIcount))
                    {
                         itemID = whiteItemsBin[urand(0, whiteItemsBin.size() - 1)];
                         ++whiteItems;
                         break;
                    }
                }
            case 2:
                {
                    if ((greenItemsBin.size() > 0) && (greenItems < greenIcount))
                    {
                         itemID = greenItemsBin[urand(0, greenItemsBin.size() - 1)];
                         ++greenItems;
                         break;
                    }
                }
            case 3:
                {
                    if ((blueItemsBin.size() > 0) && (blueItems < blueIcount))
                    {
                         itemID = blueItemsBin[urand(0, blueItemsBin.size() - 1)];
                         ++blueItems;
                         break;
                    }
                }
            case 4:
                {
                    if ((purpleItemsBin.size() > 0) && (purpleItems < purpleIcount))
                    {
                        itemID = purpleItemsBin[urand(0, purpleItemsBin.size() - 1)];
                        ++purpleItems;
                        break;
                    }
                }
            case 5:
                {
                    if ((orangeItemsBin.size() > 0) && (orangeItems < orangeIcount))
                    {
                        itemID = orangeItemsBin[urand(0, orangeItemsBin.size() - 1)];
                        ++orangeItems;
                        break;
                    }
                }
            case 6:
                {
                    if ((yellowItemsBin.size() > 0) && (yellowItems < yellowIcount))
                    {
                        itemID = yellowItemsBin[urand(0, yellowItemsBin.size() - 1)];
                        ++yellowItems;
                        break;
                    }
                }
            case 7:
                {
                    if ((greyTradeGoodsBin.size() > 0) && (greyTGoods < greyTGcount))
                    {
                         itemID = whiteTradeGoodsBin[urand(0, whiteTradeGoodsBin.size() - 1)];
                         ++greyTGoods;
                         break;
                    }
                }
            case 8:
                {
                    if ((whiteTradeGoodsBin.size() > 0) && (whiteTGoods < whiteTGcount))
                    {
                         itemID = whiteTradeGoodsBin[urand(0, whiteTradeGoodsBin.size() - 1)];
                         ++whiteTGoods;
                         break;
                    }
                }
            case 9:
                {
                    if ((greenTradeGoodsBin.size() > 0) && (greenTGoods < greenTGcount))
                    {
                         itemID = greenTradeGoodsBin[urand(0, greenTradeGoodsBin.size() - 1)];
                         ++greenTGoods;
                         break;
                    }
                }
            case 10:
                {
                    if ((blueTradeGoodsBin.size() > 0) && (blueTGoods < blueTGcount))
                    {
                         itemID = blueTradeGoodsBin[urand(0, blueTradeGoodsBin.size() - 1)];
                         ++blueTGoods;
                         break;
                    }
                }
            case 11:
                {
                    if ((purpleTradeGoodsBin.size() > 0) && (purpleTGoods < purpleTGcount))
                    {
                         itemID = purpleTradeGoodsBin[urand(0, purpleTradeGoodsBin.size() - 1)];
                         ++purpleTGoods;
                         break;
                    }
                }
            case 12:
                {
                    if ((orangeTradeGoodsBin.size() > 0) && (orangeTGoods < orangeTGcount))
                    {
                         itemID = orangeTradeGoodsBin[urand(0, orangeTradeGoodsBin.size() - 1)];
                         ++orangeTGoods;
                         break;
                    }
                }
            case 13:
                {
                    if ((yellowTradeGoodsBin.size() > 0) && (yellowTGoods < yellowTGcount))
                    {
                         itemID = yellowTradeGoodsBin[urand(0, yellowTradeGoodsBin.size() - 1)];
                         ++yellowTGoods;
                         break;
                    }
                }
            default:
                {
                    break;
                }
            }
        }

        ItemPrototype const* prototype = objmgr.GetItemPrototype(itemID);
        if (prototype == NULL)
        {
         sLog.outString("AuctionHouseBot: Huh?!?! prototype == NULL");
         continue;
        }

        Item* item = Item::CreateItem(itemID, 1, AHBplayer);
        item->AddToUpdateQueueOf(AHBplayer);
        if (item == NULL)
        {
            sLog.outString("AuctionHouseBot: Item::CreateItem() returned NULL");
            break;
        }

        uint32 randomPropertyId = Item::GenerateItemRandomPropertyId(itemID);
        if (randomPropertyId != 0)
         item->SetItemRandomProperties(randomPropertyId);

        uint64 buyoutPrice;
        uint64 bidPrice = 0;
        uint32 stackCount = urand(1, item->GetMaxStackCount());

        switch (SellMethod)
        {
        case 0:
            buyoutPrice  = prototype->SellPrice * item->GetCount();
            break;
        case 1:
            buyoutPrice  = prototype->BuyPrice * item->GetCount();
            break;
        default:
            buyoutPrice = 0;
            break;
        }

        switch (prototype->Quality)
        {
         case 0:
            if (config->GetMaxStack(AHB_GREY) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_GREY)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_GREY), config->GetMaxPrice(AHB_GREY)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_GREY), config->GetMaxBidPrice(AHB_GREY));
            bidPrice /= 100;
            break;

         case 1:
            if (config->GetMaxStack(AHB_WHITE) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_WHITE)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_WHITE), config->GetMaxPrice(AHB_WHITE)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_WHITE), config->GetMaxBidPrice(AHB_WHITE));
            bidPrice /= 100;
            break;

         case 2:
            if (config->GetMaxStack(AHB_GREEN) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_GREEN)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_GREEN), config->GetMaxPrice(AHB_GREEN)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_GREEN), config->GetMaxBidPrice(AHB_GREEN));
            bidPrice /= 100;
            break;

         case 3:
            if (config->GetMaxStack(AHB_BLUE) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_BLUE)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_BLUE), config->GetMaxPrice(AHB_BLUE)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_BLUE), config->GetMaxBidPrice(AHB_BLUE));
            bidPrice /= 100;
            break;

         case 4:
            if (config->GetMaxStack(AHB_PURPLE) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_PURPLE)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_PURPLE), config->GetMaxPrice(AHB_PURPLE)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_PURPLE), config->GetMaxBidPrice(AHB_PURPLE));
            bidPrice /= 100;
            break;
         case 5:
            if (config->GetMaxStack(AHB_ORANGE) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_ORANGE)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_ORANGE), config->GetMaxPrice(AHB_ORANGE)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_ORANGE), config->GetMaxBidPrice(AHB_ORANGE));
            bidPrice /= 100;
            break;
         case 6:
            if (config->GetMaxStack(AHB_YELLOW) != 0)
            {
               stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(AHB_YELLOW)));
            }
            buyoutPrice *= urand(config->GetMinPrice(AHB_YELLOW), config->GetMaxPrice(AHB_YELLOW)) * stackCount;
            buyoutPrice /= 100;
            bidPrice = buyoutPrice * urand(config->GetMinBidPrice(AHB_YELLOW), config->GetMaxBidPrice(AHB_YELLOW));
            bidPrice /= 100;
            break;
        }

        if(auctionmgr.GetAItem(GUID_LOPART(item->GetGUID())))
        {
            sLog.outError("Item %u not found", item->GetEntry());
            break;
        }
        if(!item->CanBeTraded())
        {
            sLog.outError("Item %u can't be traded", item->GetEntry());
            break;
        }

        if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FLAGS_CONJURED) || item->GetUInt32Value(ITEM_FIELD_DURATION))
        {
            sLog.outError("Item %u is conjured or has a duration", item->GetEntry());
            break;
        }
        uint32 etime = urand(1,3);
        switch(etime)
        {
            case 1:
                etime = 43200;
                break;
            case 2:
                etime = 86400;
                break;
            case 3:
                etime = 172800;
                break;
            default:
                etime = 86400;
                break;
        }
        uint32 dep = auctionmgr.GetAuctionDeposit( ahEntry, etime, item );

        item->SetCount(stackCount);

        AuctionEntry* auctionEntry = new AuctionEntry;
        auctionEntry->Id = objmgr.GenerateAuctionID();
        auctionEntry->auctioneer = AuctioneerGUID;
        auctionEntry->item_guidlow = item->GetGUIDLow();
        auctionEntry->item_template = item->GetEntry();
        auctionEntry->owner = AHBplayer->GetGUIDLow();
        auctionEntry->startbid = bidPrice;
        auctionEntry->buyout = buyoutPrice;
        auctionEntry->bidder = 0;
        auctionEntry->bid = 0;
        auctionEntry->deposit = dep;
        auctionEntry->expire_time = (time_t) etime + time(NULL);
        auctionEntry->auctionHouseEntry = ahEntry;
        item->SaveToDB();
        item->RemoveFromUpdateQueueOf(AHBplayer);
        auctionmgr.AddAItem(item);
        auctionHouse->AddAuction(auctionEntry);
        auctionEntry->SaveToDB();
    }
}

static void addNewAuctionBuyerBotBid(Player *AHBplayer, AHBConfig *config, WorldSession *session)
{
    if (!AHBBuyer)
        return;

    // Fetches content of selected AH
    AuctionHouseObject* auctionHouse = auctionmgr.GetAuctionsMap(config->GetAHFID());
    AuctionHouseObject::AuctionEntryMap::iterator itr;

    itr = auctionHouse->GetAuctionsBegin();
    vector<uint32> possibleBids;

    while (itr != auctionHouse->GetAuctionsEnd())
    {
        AuctionHouseObject::AuctionEntryMap::iterator tmp = itr;
        ++itr;
        // Check if the auction is ours
        // if it is, we skip this iteration.
        if(tmp->second->owner == AHBplayerGUID)
        {
            continue;
        }
        // Check that we haven't bidded in this auction already.
        if(tmp->second->bidder != AHBplayerGUID)
        {
            uint32 tmpdata = tmp->second->Id;
            possibleBids.push_back(tmpdata);
        }
    }

    uint32 bids = config->GetBidsPerInterval();
    for (uint32 count = 0; count < bids; ++count)
    {
        // Do we have anything to bid? If not, stop here.
        if(possibleBids.empty())
            return;

        // Choose random auction from possible auctions
        uint32 vectorPos = urand(0, possibleBids.size() - 1);
        vector<uint32>::iterator iter = possibleBids.begin();
        advance(iter, vectorPos);
        // from auctionhousehandler.cpp, creates auction pointer & player pointer
        AuctionEntry* auction = auctionHouse->GetAuction(*iter);
        // Erase the auction from the vector to prevent bidding on item in next itteration.
        possibleBids.erase(iter);

        // get exact item information
        Item *pItem = auctionmgr.GetAItem(auction->item_guidlow);
        if (!pItem)
        {
            sLog.outError("Item doesn't exists, perhaps bought already?");
            return;
        }

        // get item prototype
        ItemPrototype const* prototype = objmgr.GetItemPrototype(auction->item_template);

        // check which price we have to use, startbid or if it is bidded already
        if(debug_Out)
        {
            sLog.outError("Auction Number: %u", auction->Id);
            sLog.outError("Item Template: %u", auction->item_template);
            sLog.outError("Buy Price: %u", prototype->BuyPrice);
            sLog.outError("Sell Price: %u", prototype->SellPrice);
            sLog.outError("Quality: %u", prototype->Quality);
        }

        uint32 currentprice;
        if(auction->bid)
        {
            currentprice = auction->bid;
            if(debug_Out)
            {sLog.outError("Current Price: %u", auction->bid);}
        }
        else
        {
            currentprice = auction->startbid;
            if(debug_Out)
            {sLog.outError("Current Price: %u", auction->startbid);}
        }

        // Prepare portion from maximum bid
        uint32 tmprate2 = urand(0, 100);
        double tmprate = static_cast<double>(tmprate2);
        double bidrate = tmprate / 100;
        long double bidMax = 0;
        if(debug_Out)
        {
            sLog.outError("tmprate: %f", tmprate);
            sLog.outError("bidrate: %f", bidrate);
        }

        // check that bid has acceptable value and take bid based on vendorprice, stacksize and quality
        switch (BuyMethod)
        {
            case 0:
            {
                switch (prototype->Quality)
                {
                    case 0:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY);
                        break;
                    case 1:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE);
                        break;
                    case 2:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN);
                        break;
                    case 3:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE);
                        break;
                    case 4:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE);
                    case 5:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_ORANGE))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_ORANGE);
                    case 6:
                        if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_YELLOW))
                            bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_YELLOW);
                        break;
                    default:
                        // quality is something it shouldn't be, let's get out of here
                        if(debug_Out)
                            sLog.outError("bidMax(fail): %f", bidMax);
                        return;
                }
                break;
            }
            case 1:
            {
                switch (prototype->Quality)
                {
                    case 0:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY);
                        break;
                    case 1:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE);
                        break;
                    case 2:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN);
                        break;
                    case 3:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE);
                        break;
                    case 4:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE);
                    case 5:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_ORANGE))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_ORANGE);
                    case 6:
                        if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_YELLOW))
                            bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_YELLOW);
                        break;
                    default:
                        // quality is something it shouldn't be, let's get out of here
                        if(debug_Out)
                            sLog.outError("bidMax(fail): %f", bidMax);
                        return;
                }
                break;
            }
            default:
                bidMax = 0;
                break;
        }

        if(debug_Out)
            sLog.outError("bidMax(succeed): %f", bidMax);

        // check some special items, and do recalculating to their prices
        switch (prototype->Class)
        {
            // ammo
            case 6:
                bidMax = 0;
                break;
            default:
                break;
        }

        if(bidMax == 0)
        {
            // quality check failed to get bidmax, let's get out of here
            return;
        }

        // Calculate our bid
        long double bidvalue = currentprice + ( (bidMax - currentprice) * bidrate);
        // Convert to uint32
        uint32 bidprice = static_cast<uint32>(bidvalue);
        if(debug_Out)
        {
            sLog.outError("bidprice: %u", bidprice);
            sLog.outError("bidvalue: %f", bidvalue);
        }

        // Check our bid is high enough to be valid. If not, correct it to minimum.
        if((currentprice + auction->GetAuctionOutBid()) > bidprice)
        {
            bidprice = currentprice + auction->GetAuctionOutBid();
            if(debug_Out)
                sLog.outError("bidprice(>): %u", bidprice);
        }

        // Check wether we do normal bid, or buyout
        if ((bidprice < auction->buyout) || (auction->buyout == 0))
        {

            if (auction->bidder > 0)
            {
                if ( auction->bidder == AHBplayer->GetGUIDLow() )
                {
                    //pl->ModifyMoney( -int32(price - auction->bid));
                }
                else
                {
                    // mail to last bidder and return money
                    session->SendAuctionOutbiddedMail( auction , bidprice );
                    //pl->ModifyMoney( -int32(price) );
                }
            }

            auction->bidder = AHBplayer->GetGUIDLow();
            auction->bid = bidprice;

            // Saving auction into database
            CharacterDatabase.PExecute("UPDATE auctionhouse SET buyguid = '%u',lastbid = '%u' WHERE id = '%u'", auction->bidder, auction->bid, auction->Id);
        }
        else
        {
            //buyout
            if (AHBplayer->GetGUIDLow() == auction->bidder )
            {
                //pl->ModifyMoney(-int32(auction->buyout - auction->bid));
            }
            else
            {
                //pl->ModifyMoney(-int32(auction->buyout));
                if ( auction->bidder )
                {
                    session->SendAuctionOutbiddedMail( auction, auction->buyout );
                }
            }
            auction->bidder = AHBplayer->GetGUIDLow();
            auction->bid = auction->buyout;

            // Send mails to buyer & seller
            auctionmgr.SendAuctionSuccessfulMail( auction );
            auctionmgr.SendAuctionWonMail( auction );

            // Remove item from auctionhouse
            auctionmgr.RemoveAItem(auction->item_guidlow);
            // Remove auction
            auctionHouse->RemoveAuction(auction->Id);
            // Remove from database
            auction->DeleteFromDB();
            delete auction;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void AuctionHouseBot()
{
    time_t _newrun = time(NULL);
    if ((!AHBSeller) && (!AHBBuyer))
      return;

    WorldSession _session(AHBplayerAccount, NULL, SEC_PLAYER, true, 0, LOCALE_enUS);
    Player _AHBplayer(&_session);
    _AHBplayer.MinimalLoadFromDB(NULL, AHBplayerGUID);
    ObjectAccessor::Instance().AddObject(&_AHBplayer);

    if(!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        addNewAuctions(&_AHBplayer, &AllianceConfig);
        if (((_newrun - _lastrun_a) > (AllianceConfig.GetBiddingInterval() * 60)) && (AllianceConfig.GetBidsPerInterval() > 0))
        {
            addNewAuctionBuyerBotBid(&_AHBplayer, &AllianceConfig, &_session);
            _lastrun_a = _newrun;
        }
        addNewAuctions(&_AHBplayer, &HordeConfig);
        if (((_newrun - _lastrun_h) > (HordeConfig.GetBiddingInterval() *60)) && (HordeConfig.GetBidsPerInterval() > 0))
        {
            addNewAuctionBuyerBotBid(&_AHBplayer, &HordeConfig, &_session);
            _lastrun_h = _newrun;
        }
    }
    addNewAuctions(&_AHBplayer, &NeutralConfig);
    if (((_newrun - _lastrun_n) > (NeutralConfig.GetBiddingInterval() * 60)) && (NeutralConfig.GetBidsPerInterval() > 0))
    {
        addNewAuctionBuyerBotBid(&_AHBplayer, &NeutralConfig, &_session);
        _lastrun_n = _newrun;
    }
    ObjectAccessor::Instance().RemoveObject(&_AHBplayer);
}
///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void AuctionHouseBotInit()
{
    AHBSeller = sConfig.GetBoolDefault("AuctionHouseBot.EnableSeller", false);
    AHBBuyer = sConfig.GetBoolDefault("AuctionHouseBot.EnableBuyer", false);
    No_Bind = sConfig.GetBoolDefault("AuctionHouseBot.No_Bind", true);
    Bind_When_Picked_Up = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Picked_Up", false);
    Bind_When_Equipped = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Equipped", true);
    Bind_When_Use = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Use", true);
    Bind_Quest_Item = sConfig.GetBoolDefault("AuctionHouseBot.Bind_Quest_Item", false);

    if(!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        AuctionHouseBotLoadValues(&AllianceConfig);
        AuctionHouseBotLoadValues(&HordeConfig);
    }
    AuctionHouseBotLoadValues(&NeutralConfig);

    if (AHBSeller)
    {
        Vendor_Items = sConfig.GetBoolDefault("AuctionHouseBot.VendorItems", false);
        Loot_Items = sConfig.GetBoolDefault("AuctionHouseBot.LootItems", true);
        Other_Items = sConfig.GetBoolDefault("AuctionHouseBot.OtherItems", false);

        QueryResult* results = (QueryResult*) NULL;
        char npcQuery[] = "SELECT distinct `item` FROM `npc_vendor`";
        results = WorldDatabase.PQuery(npcQuery);
        if (results != NULL)
        {
          do
          {
             Field* fields = results->Fetch();
             npcItems.push_back(fields[0].GetUInt32());

          } while (results->NextRow());

          delete results;
        }
        else
        {
          sLog.outString("AuctionHouseBot: \"%s\" failed", npcQuery);
        }

        char lootQuery[] = "SELECT `item` FROM `creature_loot_template` UNION "
                          "SELECT `item` FROM `disenchant_loot_template` UNION "
                          "SELECT `item` FROM `fishing_loot_template` UNION "
                          "SELECT `item` FROM `gameobject_loot_template` UNION "
                          "SELECT `item` FROM `item_loot_template` UNION "
                          "SELECT `item` FROM `pickpocketing_loot_template` UNION "
                          "SELECT `item` FROM `prospecting_loot_template` UNION "
                          "SELECT `item` FROM `skinning_loot_template`";

        results = WorldDatabase.PQuery(lootQuery);
        if (results != NULL)
        {
          do
          {
             Field* fields = results->Fetch();
             lootItems.push_back(fields[0].GetUInt32());

          } while (results->NextRow());

          delete results;
        }
        else
        {
          sLog.outString("AuctionHouseBot: \"%s\" failed", lootQuery);
        }

        for (uint32 itemID = 0; itemID < sItemStorage.MaxEntry; itemID++)
        {
            ItemPrototype const* prototype = objmgr.GetItemPrototype(itemID);

            if (prototype == NULL)
             continue;

            switch (prototype->Bonding)
            {
            case 0:
                if (!No_Bind)
                    continue;
                break;
            case 1:
                if (!Bind_When_Picked_Up)
                    continue;
                break;
            case 2:
                if (!Bind_When_Equipped)
                    continue;
                break;
            case 3:
                if (!Bind_When_Use)
                    continue;
                break;
            case 4:
                if (!Bind_Quest_Item)
                    continue;
                break;
            default:
                continue;
                break;
            }

            switch (SellMethod)
            {
            case 0:
                if (prototype->SellPrice == 0)
                    continue;
                break;
            case 1:
                if (prototype->BuyPrice == 0)
                    continue;
                break;
            default:
                continue;
                break;
            }

            if ((prototype->Quality < 0) || (prototype->Quality > 6))
             continue;

            if (Vendor_Items == 0)
            {
                bool isVendorItem = false;

                for (unsigned int i = 0; (i < npcItems.size()) && (!isVendorItem); i++)
                {
                 if (itemID == npcItems[i])
                    isVendorItem = true;
                }

                if (isVendorItem)
                 continue;
            }

            if (Loot_Items == 0)
            {
                bool isLootItem = false;

                for (unsigned int i = 0; (i < lootItems.size()) && (!isLootItem); i++)
                {
                 if (itemID == lootItems[i])
                    isLootItem = true;
                }

                if (isLootItem)
                 continue;
            }

            if (Other_Items == 0)
            {
                bool isVendorItem = false;
                bool isLootItem = false;

                for (unsigned int i = 0; (i < npcItems.size()) && (!isVendorItem); i++)
                {
                 if (itemID == npcItems[i])
                    isVendorItem = true;
                }
                for (unsigned int i = 0; (i < lootItems.size()) && (!isLootItem); i++)
                {
                 if (itemID == lootItems[i])
                    isLootItem = true;
                }
                if ((!isLootItem) && (!isVendorItem))
                    continue;
            }

            switch (prototype->Quality)
            {
             case 0:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   greyTradeGoodsBin.push_back(itemID);
                else
                   greyItemsBin.push_back(itemID);
                break;

             case 1:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   whiteTradeGoodsBin.push_back(itemID);
                else
                   whiteItemsBin.push_back(itemID);
                break;

             case 2:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   greenTradeGoodsBin.push_back(itemID);
                else
                   greenItemsBin.push_back(itemID);
                break;

             case 3:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   blueTradeGoodsBin.push_back(itemID);
                else
                   blueItemsBin.push_back(itemID);
                break;

             case 4:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   purpleTradeGoodsBin.push_back(itemID);
                else
                   purpleItemsBin.push_back(itemID);
                break;

             case 5:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   orangeTradeGoodsBin.push_back(itemID);
                else
                   orangeItemsBin.push_back(itemID);
                break;

             case 6:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   yellowTradeGoodsBin.push_back(itemID);
                else
                   yellowItemsBin.push_back(itemID);
                break;
            }
        }

        if (
           (greyTradeGoodsBin.size() == 0) &&
           (whiteTradeGoodsBin.size() == 0) &&
           (greenTradeGoodsBin.size() == 0) &&
           (blueTradeGoodsBin.size() == 0) &&
           (purpleTradeGoodsBin.size() == 0) &&
           (orangeTradeGoodsBin.size() == 0) &&
           (yellowTradeGoodsBin.size() == 0) &&
           (greyItemsBin.size() == 0) &&
           (whiteItemsBin.size() == 0) &&
           (greenItemsBin.size() == 0) &&
           (blueItemsBin.size() == 0) &&
           (purpleItemsBin.size() == 0) &&
           (orangeItemsBin.size() == 0) &&
           (yellowItemsBin.size() == 0)
           )
        {
          sLog.outString("AuctionHouseBot: No items");
          AHBSeller = 0;
        }

        sLog.outString("AuctionHouseBot:");
        sLog.outString("loaded %u grey trade goods", greyTradeGoodsBin.size());
        sLog.outString("loaded %u white trade goods", whiteTradeGoodsBin.size());
        sLog.outString("loaded %u green trade goods", greenTradeGoodsBin.size());
        sLog.outString("loaded %u blue trade goods", blueTradeGoodsBin.size());
        sLog.outString("loaded %u purple trade goods", purpleTradeGoodsBin.size());
        sLog.outString("loaded %u orange trade goods", orangeTradeGoodsBin.size());
        sLog.outString("loaded %u yellow trade goods", yellowTradeGoodsBin.size());
        sLog.outString("loaded %u grey items", greyItemsBin.size());
        sLog.outString("loaded %u white items", whiteItemsBin.size());
        sLog.outString("loaded %u green items", greenItemsBin.size());
        sLog.outString("loaded %u blue items", blueItemsBin.size());
        sLog.outString("loaded %u purple items", purpleItemsBin.size());
        sLog.outString("loaded %u orange items", orangeItemsBin.size());
        sLog.outString("loaded %u yellow items", yellowItemsBin.size());
    }
    sLog.outString("AuctionHouseBot by Paradox (original by ChrisK) has been loaded.");
    sLog.outString("AuctionHouseBot now includes AHBuyer by Kerbe and Paradox");

}
void AuctionHouseBotCommands(uint32 command, uint32 ahMapID, uint32 col, char* args)
{
    AHBConfig *config;
    switch (ahMapID)
    {
    case 2:
        config = &AllianceConfig;
        break;
    case 6:
        config = &HordeConfig;
        break;
    case 7:
        config = &NeutralConfig;
        break;
    }
    std::string color;
    switch (col)
    {
    case AHB_GREY:
        color = "grey";
        break;
    case AHB_WHITE:
        color = "white";
        break;
    case AHB_GREEN:
        color = "green";
        break;
    case AHB_BLUE:
        color = "blue";
        break;
    case AHB_PURPLE:
        color = "purple";
        break;
    case AHB_ORANGE:
        color = "orange";
        break;
    case AHB_YELLOW:
        color = "yellow";
        break;
    default:
        break;
    }
    switch (command)
    {
    case 0:     //ahexpire
        {
            AuctionHouseObject* auctionHouse = auctionmgr.GetAuctionsMap(config->GetAHFID());

            AuctionHouseObject::AuctionEntryMap::iterator itr;
            itr = auctionHouse->GetAuctionsBegin();

            while (itr != auctionHouse->GetAuctionsEnd())
            {
              if (itr->second->owner == AHBplayerGUID)
                 itr->second->expire_time = sWorld.GetGameTime();

              ++itr;
            }
        }break;
    case 1:     //min items
        {
            char * param1 = strtok(args, " ");
            uint32 minItems = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minitems = '%u' WHERE auctionhouse = '%u'", minItems, ahMapID);
            config->SetMinItems(minItems);
        }break;
    case 2:     //max items
        {
            char * param1 = strtok(args, " ");
            uint32 maxItems = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxitems = '%u' WHERE auctionhouse = '%u'", maxItems, ahMapID);
            config->SetMaxItems(maxItems);
        }break;
    case 3:     //min time Deprecated (Place holder for future commands)
        {
        }break;
    case 4:     //max time Deprecated (Place holder for future commands)
        {
        }break;
    case 5:     //percentages
        {
            char * param1 = strtok(args, " ");
            char * param2 = strtok(NULL, " ");
            char * param3 = strtok(NULL, " ");
            char * param4 = strtok(NULL, " ");
            char * param5 = strtok(NULL, " ");
            char * param6 = strtok(NULL, " ");
            char * param7 = strtok(NULL, " ");
            char * param8 = strtok(NULL, " ");
            char * param9 = strtok(NULL, " ");
            char * param10 = strtok(NULL, " ");
            char * param11 = strtok(NULL, " ");
            char * param12 = strtok(NULL, " ");
            char * param13 = strtok(NULL, " ");
            char * param14 = strtok(NULL, " ");
            uint32 greytg = (uint32) strtoul(param1, NULL, 0);
            uint32 whitetg = (uint32) strtoul(param2, NULL, 0);
            uint32 greentg = (uint32) strtoul(param3, NULL, 0);
            uint32 bluetg = (uint32) strtoul(param4, NULL, 0);
            uint32 purpletg = (uint32) strtoul(param5, NULL, 0);
            uint32 orangetg = (uint32) strtoul(param6, NULL, 0);
            uint32 yellowtg = (uint32) strtoul(param7, NULL, 0);
            uint32 greyi = (uint32) strtoul(param8, NULL, 0);
            uint32 whitei = (uint32) strtoul(param9, NULL, 0);
            uint32 greeni = (uint32) strtoul(param10, NULL, 0);
            uint32 bluei = (uint32) strtoul(param11, NULL, 0);
            uint32 purplei = (uint32) strtoul(param12, NULL, 0);
            uint32 orangei = (uint32) strtoul(param13, NULL, 0);
            uint32 yellowi = (uint32) strtoul(param14, NULL, 0);

            CharacterDatabase.BeginTransaction();
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentgreytradegoods = '%u' WHERE auctionhouse = '%u'", greytg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentwhitetradegoods = '%u' WHERE auctionhouse = '%u'", whitetg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentgreentradegoods = '%u' WHERE auctionhouse = '%u'", greentg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentbluetradegoods = '%u' WHERE auctionhouse = '%u'", bluetg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentpurpletradegoods = '%u' WHERE auctionhouse = '%u'", purpletg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentorangetradegoods = '%u' WHERE auctionhouse = '%u'", orangetg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentyellowtradegoods = '%u' WHERE auctionhouse = '%u'", yellowtg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentgreyitems = '%u' WHERE auctionhouse = '%u'", greyi, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentwhiteitems = '%u' WHERE auctionhouse = '%u'", whitei, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentgreenitems = '%u' WHERE auctionhouse = '%u'", greeni, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentblueitems = '%u' WHERE auctionhouse = '%u'", bluei, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentpurpleitems = '%u' WHERE auctionhouse = '%u'", purplei, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentorangeitems = '%u' WHERE auctionhouse = '%u'", orangei, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentyellowitems = '%u' WHERE auctionhouse = '%u'", yellowi, ahMapID);
            CharacterDatabase.CommitTransaction();
            config->SetPercentages(greytg, whitetg, greentg, bluetg, purpletg, orangetg, yellowtg, greyi, whitei, greeni, bluei, purplei, orangei, yellowi);
        }break;
    case 6:     //min prices
        {
            char * param1 = strtok(args, " ");
            uint32 minPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), minPrice, ahMapID);
            config->SetMinPrice(col, minPrice);
        }break;
    case 7:     //max prices
        {
            char * param1 = strtok(args, " ");
            uint32 maxPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxPrice, ahMapID);
            config->SetMaxPrice(col, maxPrice);
        }break;
    case 8:     //min bid price
        {
            char * param1 = strtok(args, " ");
            uint32 minBidPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minbidprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), minBidPrice, ahMapID);
            config->SetMinBidPrice(col, minBidPrice);
        }break;
    case 9:     //max bid price
        {
            char * param1 = strtok(args, " ");
            uint32 maxBidPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxbidprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxBidPrice, ahMapID);
            config->SetMaxBidPrice(col, maxBidPrice);
        }break;
    case 10:        //max stacks
        {
            char * param1 = strtok(args, " ");
            uint32 maxStack = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxstack%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxStack, ahMapID);
            config->SetMaxStack(col, maxStack);
        }break;
    case 11:        //buyer bid prices
        {
            char * param1 = strtok(args, " ");
            uint32 buyerPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET buyerprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), buyerPrice, ahMapID);
            config->SetBuyerPrice(col, buyerPrice);
        }break;
    case 12:        //buyer bidding interval
        {
            char * param1 = strtok(args, " ");
            uint32 bidInterval = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET buyerbiddinginterval = '%u' WHERE auctionhouse = '%u'", bidInterval, ahMapID);
            config->SetBiddingInterval(bidInterval);
        }break;
    case 13:        //buyer bids per interval
        {
            char * param1 = strtok(args, " ");
            uint32 bidsPerInterval = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET buyerbidsperinterval = '%u' WHERE auctionhouse = '%u'", bidsPerInterval, ahMapID);
            config->SetBidsPerInterval(bidsPerInterval);
        }break;
    default:
        break;
    }
}
void AuctionHouseBotLoadValues(AHBConfig *config)
{
    if (AHBSeller)
    {
        //load min and max items
        config->SetMinItems(CharacterDatabase.PQuery("SELECT minitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxItems(CharacterDatabase.PQuery("SELECT maxitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minItems = %u", config->GetMinItems());
        sLog.outError("maxItems = %u", config->GetMaxItems());}
        //load percentages
        uint32 greytg = CharacterDatabase.PQuery("SELECT percentgreytradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 whitetg = CharacterDatabase.PQuery("SELECT percentwhitetradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 greentg = CharacterDatabase.PQuery("SELECT percentgreentradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 bluetg = CharacterDatabase.PQuery("SELECT percentbluetradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 purpletg = CharacterDatabase.PQuery("SELECT percentpurpletradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 orangetg = CharacterDatabase.PQuery("SELECT percentorangetradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 yellowtg = CharacterDatabase.PQuery("SELECT percentyellowtradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 greyi = CharacterDatabase.PQuery("SELECT percentgreyitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 whitei = CharacterDatabase.PQuery("SELECT percentwhiteitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 greeni = CharacterDatabase.PQuery("SELECT percentgreenitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 bluei = CharacterDatabase.PQuery("SELECT percentblueitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 purplei = CharacterDatabase.PQuery("SELECT percentpurpleitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 orangei = CharacterDatabase.PQuery("SELECT percentorangeitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 yellowi = CharacterDatabase.PQuery("SELECT percentyellowitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        config->SetPercentages(greytg, whitetg, greentg, bluetg, purpletg, orangetg, yellowtg, greyi, whitei, greeni, bluei, purplei, orangei, yellowi);
        if(debug_Out)
        {
            sLog.outError("percentGreyTradeGoods = %u", config->GetPercentages(AHB_GREY_TG));
            sLog.outError("percentWhiteTradeGoods = %u", config->GetPercentages(AHB_WHITE_TG));
            sLog.outError("percentGreenTradeGoods = %u", config->GetPercentages(AHB_GREEN_TG));
            sLog.outError("percentBlueTradeGoods = %u", config->GetPercentages(AHB_BLUE_TG));
            sLog.outError("percentPurpleTradeGoods = %u", config->GetPercentages(AHB_PURPLE_TG));
            sLog.outError("percentOrangeTradeGoods = %u", config->GetPercentages(AHB_ORANGE_TG));
            sLog.outError("percentYellowTradeGoods = %u", config->GetPercentages(AHB_YELLOW_TG));
            sLog.outError("percentGreyItems = %u", config->GetPercentages(AHB_GREY_I));
            sLog.outError("percentWhiteItems = %u", config->GetPercentages(AHB_WHITE_I));
            sLog.outError("percentGreenItems = %u", config->GetPercentages(AHB_GREEN_I));
            sLog.outError("percentBlueItems = %u", config->GetPercentages(AHB_BLUE_I));
            sLog.outError("percentPurpleItems = %u", config->GetPercentages(AHB_PURPLE_I));
            sLog.outError("percentOrangeItems = %u", config->GetPercentages(AHB_ORANGE_I));
            sLog.outError("percentYellowItems = %u", config->GetPercentages(AHB_YELLOW_I));
        }
        //load min and max prices
        config->SetMinPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT minpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT maxpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPriceGrey = %u", config->GetMinPrice(AHB_GREY));
        sLog.outError("maxPriceGrey = %u", config->GetMaxPrice(AHB_GREY));}
        config->SetMinPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT minpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT maxpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPriceWhite = %u", config->GetMinPrice(AHB_WHITE));
        sLog.outError("maxPriceWhite = %u", config->GetMaxPrice(AHB_WHITE));}
        config->SetMinPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT minpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT maxpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPriceGreen = %u", config->GetMinPrice(AHB_GREEN));
        sLog.outError("maxPriceGreen = %u", config->GetMaxPrice(AHB_GREEN));}
        config->SetMinPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT minpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT maxpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPriceBlue = %u", config->GetMinPrice(AHB_BLUE));
        sLog.outError("maxPriceBlue = %u", config->GetMaxPrice(AHB_BLUE));}
        config->SetMinPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT minpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT maxpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPricePurple = %u", config->GetMinPrice(AHB_PURPLE));
        sLog.outError("maxPricePurple = %u", config->GetMaxPrice(AHB_PURPLE));}
        config->SetMinPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT minpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT maxpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPriceOrange = %u", config->GetMinPrice(AHB_ORANGE));
        sLog.outError("maxPriceOrange = %u", config->GetMaxPrice(AHB_ORANGE));}
        config->SetMinPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT minpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT maxpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minPriceYellow = %u", config->GetMinPrice(AHB_YELLOW));
        sLog.outError("maxPriceYellow = %u", config->GetMaxPrice(AHB_YELLOW));}
        //load min and max bid prices
        config->SetMinBidPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT minbidpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError(",minBidPriceGrey = %u", config->GetMinBidPrice(AHB_GREY));}
        config->SetMaxBidPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT maxbidpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPriceGrey = %u", config->GetMaxBidPrice(AHB_GREY));}
        config->SetMinBidPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT minbidpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError(",minBidPriceWhite = %u", config->GetMinBidPrice(AHB_WHITE));}
        config->SetMaxBidPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT maxbidpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPriceWhite = %u", config->GetMaxBidPrice(AHB_WHITE));}
        config->SetMinBidPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT minbidpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minBidPriceGreen = %u", config->GetMinBidPrice(AHB_GREEN));}
        config->SetMaxBidPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT maxbidpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPriceGreen = %u", config->GetMaxBidPrice(AHB_GREEN));}
        config->SetMinBidPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT minbidpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minBidPriceBlue = %u", config->GetMinBidPrice(AHB_BLUE));}
        config->SetMaxBidPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT maxbidpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPriceBlue = %u", config->GetMinBidPrice(AHB_BLUE));}
        config->SetMinBidPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT minbidpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minBidPricePurple = %u", config->GetMinBidPrice(AHB_PURPLE));}
        config->SetMaxBidPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT maxbidpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPricePurple = %u", config->GetMaxBidPrice(AHB_PURPLE));}
        config->SetMinBidPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT minbidpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minBidPriceOrange = %u", config->GetMinBidPrice(AHB_ORANGE));}
        config->SetMaxBidPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT maxbidpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPriceOrange = %u", config->GetMaxBidPrice(AHB_ORANGE));}
        config->SetMinBidPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT minbidpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minBidPriceYellow = %u", config->GetMinBidPrice(AHB_YELLOW));}
        config->SetMaxBidPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT maxbidpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxBidPriceYellow = %u", config->GetMaxBidPrice(AHB_YELLOW));}
        //load max stacks
        config->SetMaxStack(AHB_GREY, CharacterDatabase.PQuery("SELECT maxstackgrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackGrey = %u", config->GetMaxStack(AHB_GREY));}
        config->SetMaxStack(AHB_WHITE, CharacterDatabase.PQuery("SELECT maxstackwhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackWhite = %u", config->GetMaxStack(AHB_WHITE));}
        config->SetMaxStack(AHB_GREEN, CharacterDatabase.PQuery("SELECT maxstackgreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackGreen = %u", config->GetMaxStack(AHB_GREEN));}
        config->SetMaxStack(AHB_BLUE, CharacterDatabase.PQuery("SELECT maxstackblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackBlue = %u", config->GetMaxStack(AHB_BLUE));}
        config->SetMaxStack(AHB_PURPLE, CharacterDatabase.PQuery("SELECT maxstackpurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackPurple = %u", config->GetMaxStack(AHB_PURPLE));}
        config->SetMaxStack(AHB_ORANGE, CharacterDatabase.PQuery("SELECT maxstackorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackOrange = %u", config->GetMaxStack(AHB_ORANGE));}
        config->SetMaxStack(AHB_YELLOW, CharacterDatabase.PQuery("SELECT maxstackyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("maxStackYellow = %u", config->GetMaxStack(AHB_YELLOW));}
    }
    if (AHBBuyer)
    {
        //load buyer bid prices
        config->SetBuyerPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT buyerpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT buyerpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT buyerpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT buyerpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT buyerpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT buyerpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT buyerpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {
            sLog.outError("buyerPriceGrey = %u", config->GetBuyerPrice(AHB_GREY));
            sLog.outError("buyerPriceWhite = %u", config->GetBuyerPrice(AHB_WHITE));
            sLog.outError("buyerPriceGreen = %u", config->GetBuyerPrice(AHB_GREEN));
            sLog.outError("buyerPriceBlue = %u", config->GetBuyerPrice(AHB_BLUE));
            sLog.outError("buyerPricePurple = %u", config->GetBuyerPrice(AHB_PURPLE));
            sLog.outError("buyerPriceOrange = %u", config->GetBuyerPrice(AHB_ORANGE));
            sLog.outError("buyerPriceYellow = %u", config->GetBuyerPrice(AHB_YELLOW));
        }
        //load bidding interval
        config->SetBiddingInterval(CharacterDatabase.PQuery("SELECT buyerbiddinginterval FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("buyerBiddingInterval = %u", config->GetBiddingInterval());}
        //load bids per interval
        config->SetBidsPerInterval(CharacterDatabase.PQuery("SELECT buyerbidsperinterval FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("buyerBidsPerInterval = %u", config->GetBidsPerInterval());}
    }
}
