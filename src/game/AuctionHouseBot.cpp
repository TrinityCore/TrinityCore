#include "AuctionHouseBot.h"
#include "Bag.h"
#include "Config/ConfigEnv.h"
#include "Database/DatabaseEnv.h"
#include "Item.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"
#include "time.h"
#include <vector>
#include <iostream>

using namespace std;

static bool debug_Out = sConfig.GetIntDefault("AuctionHouseBot.DEBUG", 0);

static vector<uint32> npcItems;
static vector<uint32> lootItems;
static vector<uint32> whiteTradeGoods;
static vector<uint32> greenTradeGoods;
static vector<uint32> blueTradeGoods;
static vector<uint32> purpleTradeGoods;
static vector<uint32> whiteItems;
static vector<uint32> greenItems;
static vector<uint32> blueItems;
static vector<uint32> purpleItems;

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
    AuctionHouseObject* auctionHouse = objmgr.GetAuctionsMap(config->GetAHID());
    uint32 items = 0;
    uint32 minItems = config->GetMinItems();
    uint32 maxItems = config->GetMaxItems();
    uint32 auctions = auctionHouse->Getcount();

    if (auctions >= minItems)
      return;
    if (auctions <= maxItems)
    {
        if ((maxItems - auctions) > ItemsPerCycle)
            items = ItemsPerCycle;
        else
            items = (maxItems - auctions);
    }
    uint32 wtgbin = config->GetPercents(AHB_WHITE_TG);
    uint32 gtgbin = config->GetPercents(AHB_GREEN_TG);
    uint32 btgbin = config->GetPercents(AHB_BLUE_TG);
    uint32 ptgbin = config->GetPercents(AHB_PURPLE_TG);
    uint32 wibin = config->GetPercents(AHB_WHITE_I);
    uint32 gibin = config->GetPercents(AHB_GREEN_I);
    uint32 bibin = config->GetPercents(AHB_BLUE_I);
    uint32 pibin = config->GetPercents(AHB_PURPLE_I);
    uint32 total = wtgbin + gtgbin + btgbin + ptgbin + wibin + gibin + bibin + pibin;

    uint32 pItems = 0;
    uint32 bItems = 0;
    uint32 gItems = 0;
    uint32 wItems = 0;
    uint32 pTGoods = 0;
    uint32 bTGoods = 0;
    uint32 gTGoods = 0;
    uint32 wTGoods = 0;
    for (AuctionHouseObject::AuctionEntryMap::iterator itr = auctionHouse->GetAuctionsBegin();itr != auctionHouse->GetAuctionsEnd();++itr)
    {
        AuctionEntry *Aentry = itr->second;
        Item *item = objmgr.GetAItem(Aentry->item_guidlow);
        if( item )
        {
            ItemPrototype const *prototype = item->GetProto();
            if( prototype )
            {
                switch (prototype->Quality)
                {
                 case 0:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       wTGoods = wTGoods + 1;
                    else
                       wItems = wItems + 1;
                    break;

                 case 1:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       wTGoods = wTGoods + 1;
                    else
                       wItems = wItems + 1;
                    break;

                 case 2:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       gTGoods = gTGoods + 1;
                    else
                       gItems = gItems + 1;
                    break;

                 case 3:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       bTGoods = bTGoods + 1;
                    else
                       bItems = bItems + 1;
                    break;

                 case 4:
                    if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                       pTGoods = pTGoods + 1;
                    else
                       pItems = pItems + 1;
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
            uint32 choice = urand(1, 8);
            switch (choice)
            {
            case 1:
                {
                    if ((purpleItems.size() > 0) && (pItems < pibin))
                    {
                        itemID = purpleItems[urand(0, purpleItems.size() - 1)];
                        pItems = pItems + 1;
                        break;
                    }
                }
            case 2:
                {
                    if ((blueItems.size() > 0) && (bItems < bibin))
                    {
                         itemID = blueItems[urand(0, blueItems.size() - 1)];
                         bItems = bItems + 1;
                         break;
                    }
                }
            case 3:
                {
                    if ((greenItems.size() > 0) && (gItems < gibin))
                    {
                         itemID = greenItems[urand(0, greenItems.size() - 1)];
                         gItems = gItems + 1;
                         break;
                    }
                }
            case 4:
                {
                    if ((whiteItems.size() > 0) && (wItems < wibin))
                    {
                         itemID = whiteItems[urand(0, whiteItems.size() - 1)];
                         wItems = wItems + 1;
                         break;
                    }
                }
            case 5:
                {
                    if ((purpleTradeGoods.size() > 0) && (pTGoods < ptgbin))
                    {
                         itemID = purpleTradeGoods[urand(0, purpleTradeGoods.size() - 1)];
                         pTGoods = pTGoods + 1;
                         break;
                    }
                }
            case 6:
                {
                    if ((blueTradeGoods.size() > 0) && (bTGoods < btgbin))
                    {
                         itemID = blueTradeGoods[urand(0, blueTradeGoods.size() - 1)];
                         bTGoods = bTGoods + 1;
                         break;
                    }
                }
            case 7:
                {
                    if ((greenTradeGoods.size() > 0) && (gTGoods < gtgbin))
                    {
                         itemID = greenTradeGoods[urand(0, greenTradeGoods.size() - 1)];
                         gTGoods = gTGoods + 1;
                         break;
                    }
                }
            case 8:
                {
                    if ((whiteTradeGoods.size() > 0) && (wTGoods < wtgbin))
                    {
                         itemID = whiteTradeGoods[urand(0, whiteTradeGoods.size() - 1)];
                         wTGoods = wTGoods + 1;
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

        uint32 buyoutPrice;
        uint32 bidPrice = 0;
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
        }

        item->SetCount(stackCount);

        AuctionEntry* auctionEntry = new AuctionEntry;
        auctionEntry->Id = objmgr.GenerateAuctionID();
        auctionEntry->auctioneer = 0;
        auctionEntry->item_guidlow = item->GetGUIDLow();
        auctionEntry->item_template = item->GetEntry();
        auctionEntry->owner = AHBplayer->GetGUIDLow();
        auctionEntry->startbid = bidPrice;
        auctionEntry->buyout = buyoutPrice;
        auctionEntry->bidder = 0;
        auctionEntry->bid = 0;
        auctionEntry->deposit = 0;
        auctionEntry->location = config->GetAHID();
        auctionEntry->time = (time_t) (urand(config->GetMinTime(), config->GetMaxTime()) * 60 * 60 + time(NULL));
        item->SaveToDB();
        item->RemoveFromUpdateQueueOf(AHBplayer);
        objmgr.AddAItem(item);
        auctionHouse->AddAuction(auctionEntry);

        CharacterDatabase.PExecute("INSERT INTO `auctionhouse` (`id`,"
                                 "`auctioneerguid`,`itemguid`,`item_template`,"
                                 "`itemowner`,`buyoutprice`,`time`,`buyguid`,"
                                 "`lastbid`,`startbid`,`deposit`,`location`) "
                                 "VALUES ('%u', '%u', '%u', '%u', '%u', '%u', "
                                 "'" I64FMTD "', '%u', '%u', '%u', '%u', '%u')",
                                 auctionEntry->Id,
                                 auctionEntry->auctioneer,
                                 auctionEntry->item_guidlow,
                                 auctionEntry->item_template,
                                 auctionEntry->owner,
                                 auctionEntry->buyout,
                                 (uint64) auctionEntry->time,
                                 auctionEntry->bidder,
                                 auctionEntry->bid,
                                 auctionEntry->startbid,
                                 auctionEntry->deposit,
                                 auctionEntry->location);
    }
}

static void addNewAuctionBuyerBotBid(Player *AHBplayer, AHBConfig *config, WorldSession *session)
{
    if (!AHBBuyer)
        return;

        // Fetches content of selected AH
   AuctionHouseObject* auctionHouse = objmgr.GetAuctionsMap(config->GetAHID());
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

      // Do we have anything to bid? If not, stop here.
   if(possibleBids.empty())
   {
      return;
   }

      // Choose random auction from possible auctions
   uint32 auctionID = possibleBids[urand(0, possibleBids.size() - 1)];

      // from auctionhouse.cpp, creates auction pointer & player pointer
   AuctionEntry* auction = auctionHouse->GetAuction(auctionID);

        // get exact item information
   Item *pItem = objmgr.GetAItem(auction->item_guidlow);
   if (!pItem)
   {
      sLog.outError("Item doesn't exists, perhaps bought already?");
      return;
   }

        // get item prototype
   ItemPrototype const* prototype = objmgr.GetItemPrototype(auction->item_template);

        // check which price we have to use, startbid or if it is bidded already
    if(debug_Out)
    {sLog.outError("Auction Number: %u", auction->Id);}
    if(debug_Out)
    {sLog.outError("Item Template: %u", auction->item_template);}
    if(debug_Out)
    {sLog.outError("Buy Price: %u", prototype->BuyPrice);}
    if(debug_Out)
    {sLog.outError("Sell Price: %u", prototype->SellPrice);}
    if(debug_Out)
    {sLog.outError("Quality: %u", prototype->Quality);}
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
   uint32 bidprice;

      // Prepare portion from maximum bid
   uint32 tmprate2 = urand(0, 100);
   double tmprate = static_cast<double>(tmprate2);
    if(debug_Out)
    {sLog.outError("tmprate: %f", tmprate);}
   double bidrate = tmprate / 100;
    if(debug_Out)
    {sLog.outError("bidrate: %f", bidrate);}
   long double bidMax = 0;

      // check that bid has acceptable value and take bid based on vendorprice, stacksize and quality
   switch (BuyMethod)
   {
   case 0:
       switch (prototype->Quality)
       {
       case 0:
          if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY))
          {
             bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY);
          }
          break;
       case 1:
          if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE))
          {
             bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE);
          }
          break;
       case 2:
          if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN))
          {
             bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN);
          }
          break;
       case 3:
          if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE))
          {
             bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE);
          }
          break;
       case 4:
          if(currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE))
          {
             bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE);
          }
          break;
       default:
                // quality is something it shouldn't be, let's get out of here
            if(debug_Out)
            {sLog.outError("bidMax(fail): %f", bidMax);}
          return;
          break;
       }
     break;
   case 1:
       switch (prototype->Quality)
       {
       case 0:
          if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY))
          {
             bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREY);
          }
          break;
       case 1:
          if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE))
          {
             bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_WHITE);
          }
          break;
       case 2:
          if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN))
          {
             bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_GREEN);
          }
          break;
       case 3:
          if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE))
          {
             bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_BLUE);
          }
          break;
       case 4:
          if(currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE))
          {
             bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(AHB_PURPLE);
          }
          break;
       default:
                // quality is something it shouldn't be, let's get out of here
            if(debug_Out)
            {sLog.outError("bidMax(fail): %f", bidMax);}
          return;
          break;
       }
     break;
   default:
       bidMax = 0;
       break;
   }
    if(debug_Out)
    {sLog.outError("bidMax(succeed): %f", bidMax);}

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
    if(debug_Out)
    {sLog.outError("bidvalue: %f", bidvalue);}
      // Convert to uint32
   bidprice = static_cast<uint32>(bidvalue);
    if(debug_Out)
    {sLog.outError("bidprice: %u", bidprice);}

      // Check our bid is high enough to be valid. If not, correct it to minimum.
   if((currentprice + objmgr.GetAuctionOutBid(currentprice)) > bidprice)
   {
      bidprice = currentprice + objmgr.GetAuctionOutBid(currentprice);
        if(debug_Out)
        {sLog.outError("bidprice(>): %u", bidprice);}
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
      objmgr.SendAuctionSuccessfulMail( auction );
      objmgr.SendAuctionWonMail( auction );

         // Remove item from auctionhouse
      objmgr.RemoveAItem(auction->item_guidlow);
         // Remove auction
      auctionHouse->RemoveAuction(auction->Id);
         // Remove from database
      CharacterDatabase.PExecute("DELETE FROM auctionhouse WHERE id = '%u'",auction->Id);

      delete auction;
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

    WorldSession _session(AHBplayerAccount, NULL, 0, true, 0, LOCALE_enUS);
    Player _AHBplayer(&_session);
    _AHBplayer.MinimalLoadFromDB(NULL, AHBplayerGUID);
    ObjectAccessor::Instance().AddObject(&_AHBplayer);

    if(sConfig.GetIntDefault("AllowTwoSide.Interaction.Auction",0) == 0)
    {
        addNewAuctions(&_AHBplayer, &AllianceConfig);
        if (((_newrun - _lastrun_a) > (AllianceConfig.GetBiddingInterval() * 60)) && (AllianceConfig.GetBidsPerInterval() > 0))
        {
            uint32 bids = AllianceConfig.GetBidsPerInterval();
            for (uint32 count = 1;count <= bids;count++)
            {
                addNewAuctionBuyerBotBid(&_AHBplayer, &AllianceConfig, &_session);
                _lastrun_a = _newrun;
            }
        }
        addNewAuctions(&_AHBplayer, &HordeConfig);
        if (((_newrun - _lastrun_h) > (HordeConfig.GetBiddingInterval() *60)) && (HordeConfig.GetBidsPerInterval() > 0))
        {
            uint32 bids = HordeConfig.GetBidsPerInterval();
            for (uint32 count = 1;count <= bids;count++)
            {
                addNewAuctionBuyerBotBid(&_AHBplayer, &HordeConfig, &_session);
                _lastrun_h = _newrun;
            }
        }
    }
    addNewAuctions(&_AHBplayer, &NeutralConfig);
    if (((_newrun - _lastrun_n) > (NeutralConfig.GetBiddingInterval() * 60)) && (NeutralConfig.GetBidsPerInterval() > 0))
    {
        uint32 bids = NeutralConfig.GetBidsPerInterval();
        for (uint32 count = 1;count <= bids;count++)
        {
            addNewAuctionBuyerBotBid(&_AHBplayer, &NeutralConfig, &_session);
            _lastrun_n = _newrun;
        }
    }
    ObjectAccessor::Instance().RemoveObject(&_AHBplayer);
}
///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void AuctionHouseBotInit()
{
    AHBSeller = sConfig.GetBoolDefault("AuctionHouseBot.EnableSeller", 0);
    AHBBuyer = sConfig.GetBoolDefault("AuctionHouseBot.EnableBuyer", 0);
    No_Bind = sConfig.GetBoolDefault("AuctionHouseBot.No_Bind", 1);
    Bind_When_Picked_Up = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Picked_Up", 0);
    Bind_When_Equipped = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Equipped", 1);
    Bind_When_Use = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Use", 1);
    Bind_Quest_Item = sConfig.GetBoolDefault("AuctionHouseBot.Bind_Quest_Item", 0);

    if(sConfig.GetBoolDefault("AllowTwoSide.Interaction.Auction",0) == 0)
    {
        AuctionHouseBotLoadValues(&AllianceConfig);
        AuctionHouseBotLoadValues(&HordeConfig);
    }
    AuctionHouseBotLoadValues(&NeutralConfig);

    if (AHBSeller)
    {
        Vendor_Items = sConfig.GetBoolDefault("AuctionHouseBot.VendorItems", 0);
        Loot_Items = sConfig.GetBoolDefault("AuctionHouseBot.LootItems", 1);
        Other_Items = sConfig.GetBoolDefault("AuctionHouseBot.OtherItems", 0);

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

            if ((prototype->Quality < 1) || (prototype->Quality > 4))
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
             case 1:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   whiteTradeGoods.push_back(itemID);
                else
                   whiteItems.push_back(itemID);
                break;

             case 2:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   greenTradeGoods.push_back(itemID);
                else
                   greenItems.push_back(itemID);
                break;

             case 3:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   blueTradeGoods.push_back(itemID);
                else
                   blueItems.push_back(itemID);
                break;

             case 4:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                   purpleTradeGoods.push_back(itemID);
                else
                   purpleItems.push_back(itemID);
                break;
            }
        }

        if ((whiteTradeGoods.size() == 0) &&
           (greenTradeGoods.size() == 0) &&
           (blueTradeGoods.size() == 0) &&
           (purpleTradeGoods.size() == 0) &&
           (whiteItems.size() == 0) &&
           (greenItems.size() == 0) &&
           (blueItems.size() == 0) &&
           (purpleItems.size() == 0))
        {
          sLog.outString("AuctionHouseBot: No items");
          AHBSeller = 0;
        }

        sLog.outString("AuctionHouseBot:");
        sLog.outString("loaded %d white trade goods", whiteTradeGoods.size());
        sLog.outString("loaded %d green trade goods", greenTradeGoods.size());
        sLog.outString("loaded %d blue trade goods", blueTradeGoods.size());
        sLog.outString("loaded %d purple trade goods", purpleTradeGoods.size());
        sLog.outString("loaded %d white items", whiteItems.size());
        sLog.outString("loaded %d green items", greenItems.size());
        sLog.outString("loaded %d blue items", blueItems.size());
        sLog.outString("loaded %d purple items", purpleItems.size());
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
    default:
        break;
    }
    switch (command)
    {
    case 0:        //ahexpire
        {
            AuctionHouseObject* auctionHouse = objmgr.GetAuctionsMap(ahMapID);

            AuctionHouseObject::AuctionEntryMap::iterator itr;
            itr = auctionHouse->GetAuctionsBegin();

            while (itr != auctionHouse->GetAuctionsEnd())
            {
              if (itr->second->owner == AHBplayerGUID)
                 itr->second->time = sWorld.GetGameTime();

              ++itr;
            }
        }break;
    case 1:        //min items
        {
            char * param1 = strtok(args, " ");
            uint32 minItems = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minitems = '%u' WHERE auctionhouse = '%u'", minItems, ahMapID);
            config->SetMinItems(minItems);
        }break;
    case 2:        //max items
        {
            char * param1 = strtok(args, " ");
            uint32 maxItems = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxitems = '%u' WHERE auctionhouse = '%u'", maxItems, ahMapID);
            config->SetMaxItems(maxItems);
        }break;
    case 3:        //min time
        {
            char * param1 = strtok(args, " ");
            uint32 minTime = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET mintime = '%u' WHERE auctionhouse = '%u'", minTime, ahMapID);
            config->SetMinTime(minTime);
        }break;
    case 4:        //max time
        {
            char * param1 = strtok(args, " ");
            uint32 maxTime = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxtime = '%u' WHERE auctionhouse = '%u'", maxTime, ahMapID);
            config->SetMaxTime(maxTime);
        }break;
    case 5:        //percentages
        {
            char * param1 = strtok(args, " ");
            char * param2 = strtok(NULL, " ");
            char * param3 = strtok(NULL, " ");
            char * param4 = strtok(NULL, " ");
            char * param5 = strtok(NULL, " ");
            char * param6 = strtok(NULL, " ");
            char * param7 = strtok(NULL, " ");
            char * param8 = strtok(NULL, " ");
            uint32 wtg = (uint32) strtoul(param1, NULL, 0);
            uint32 gtg = (uint32) strtoul(param2, NULL, 0);
            uint32 btg = (uint32) strtoul(param3, NULL, 0);
            uint32 ptg = (uint32) strtoul(param4, NULL, 0);
            uint32 wi = (uint32) strtoul(param5, NULL, 0);
            uint32 gi = (uint32) strtoul(param6, NULL, 0);
            uint32 bi = (uint32) strtoul(param7, NULL, 0);
            uint32 pi = (uint32) strtoul(param8, NULL, 0);

            CharacterDatabase.BeginTransaction();
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentwhitetradegoods = '%u' WHERE auctionhouse = '%u'", wtg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentgreentradegoods = '%u' WHERE auctionhouse = '%u'", gtg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentbluetradegoods = '%u' WHERE auctionhouse = '%u'", btg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentpurpletradegoods = '%u' WHERE auctionhouse = '%u'", ptg, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentwhiteitems = '%u' WHERE auctionhouse = '%u'", wi, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentgreenitems = '%u' WHERE auctionhouse = '%u'", gi, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentblueitems = '%u' WHERE auctionhouse = '%u'", bi, ahMapID);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET percentpurpleitems = '%u' WHERE auctionhouse = '%u'", pi, ahMapID);
            CharacterDatabase.CommitTransaction();
            config->SetPercentages(wtg, gtg, btg, ptg, wi, gi, bi, pi);
        }break;
    case 6:        //min prices
        {
            char * param1 = strtok(args, " ");
            uint32 minPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), minPrice, ahMapID);
            config->SetMinPrice(col, minPrice);
        }break;
    case 7:        //max prices
        {
            char * param1 = strtok(args, " ");
            uint32 maxPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxPrice, ahMapID);
            config->SetMaxPrice(col, maxPrice);
        }break;
    case 8:        //min bid price
        {
            char * param1 = strtok(args, " ");
            uint32 minBidPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minbidprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), minBidPrice, ahMapID);
            config->SetMinBidPrice(col, minBidPrice);
        }break;
    case 9:        //max bid price
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
        //load min and max auction times
        config->SetMinTime(CharacterDatabase.PQuery("SELECT mintime FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxTime(CharacterDatabase.PQuery("SELECT maxtime FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("minTime = %u", config->GetMinTime());
        sLog.outError("maxTime = %u", config->GetMaxTime());}
        //load percentages
        uint32 wtg = CharacterDatabase.PQuery("SELECT percentwhitetradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 gtg = CharacterDatabase.PQuery("SELECT percentgreentradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 btg = CharacterDatabase.PQuery("SELECT percentbluetradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 ptg = CharacterDatabase.PQuery("SELECT percentpurpletradegoods FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 wi = CharacterDatabase.PQuery("SELECT percentwhiteitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 gi = CharacterDatabase.PQuery("SELECT percentgreenitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 bi = CharacterDatabase.PQuery("SELECT percentblueitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        uint32 pi = CharacterDatabase.PQuery("SELECT percentpurpleitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32();
        config->SetPercentages(wtg, gtg, btg, ptg, wi, gi, bi, pi);
        if(debug_Out)
        {sLog.outError("percentWhiteTradeGoods = %u", config->GetPercentages(AHB_WHITE_TG));
        sLog.outError("percentGreenTradeGoods = %u", config->GetPercentages(AHB_GREEN_TG));
        sLog.outError("percentBlueTradeGoods = %u", config->GetPercentages(AHB_BLUE_TG));
        sLog.outError("percentPurpleTradeGoods = %u", config->GetPercentages(AHB_PURPLE_TG));
        sLog.outError("percentWhiteItems = %u", config->GetPercentages(AHB_WHITE_I));
        sLog.outError("percentGreenItems = %u", config->GetPercentages(AHB_GREEN_I));
        sLog.outError("percentBlueItems = %u", config->GetPercentages(AHB_BLUE_I));
        sLog.outError("percentPurpleItems = %u", config->GetPercentages(AHB_PURPLE_I));}
        //load min and max prices
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
        //load min and max bid prices
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
        //load max stacks
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
    }
    if (AHBBuyer)
    {
        //load buyer bid prices
        config->SetBuyerPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT buyerpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT buyerpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT buyerpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT buyerpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetBuyerPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT buyerpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if(debug_Out)
        {sLog.outError("buyerPriceGrey = %u", config->GetBuyerPrice(AHB_GREY));
        sLog.outError("buyerPriceWhite = %u", config->GetBuyerPrice(AHB_WHITE));
        sLog.outError("buyerPriceGreen = %u", config->GetBuyerPrice(AHB_GREEN));
        sLog.outError("buyerPriceBlue = %u", config->GetBuyerPrice(AHB_BLUE));
        sLog.outError("buyerPricePurple = %u", config->GetBuyerPrice(AHB_PURPLE));}
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
