#include "ObjectMgr.h"
#include "AuctionHouseMgr.h"
#include "AuctionHouseBot.h"
#include <vector>

#include "Policies/SingletonImp.h"
INSTANTIATE_SINGLETON_1(AuctionHouseBot);

using namespace std;
vector<uint32> npcItems;
vector<uint32> lootItems;
vector<uint32> greyTradeGoodsBin;
vector<uint32> whiteTradeGoodsBin;
vector<uint32> greenTradeGoodsBin;
vector<uint32> blueTradeGoodsBin;
vector<uint32> purpleTradeGoodsBin;
vector<uint32> orangeTradeGoodsBin;
vector<uint32> yellowTradeGoodsBin;
vector<uint32> greyItemsBin;
vector<uint32> whiteItemsBin;
vector<uint32> greenItemsBin;
vector<uint32> blueItemsBin;
vector<uint32> purpleItemsBin;
vector<uint32> orangeItemsBin;
vector<uint32> yellowItemsBin;
AuctionHouseBot::AuctionHouseBot()
{
    debug_Out = false;
    debug_Out_Filters = false;
    AHBSeller = false;
    AHBBuyer = false;

    //Begin Filters

    Vendor_Items = false;
    Loot_Items = false;
    Other_Items = false;
    Vendor_TGs = false;
    Loot_TGs = false;
    Other_TGs = false;

    No_Bind = false;
    Bind_When_Picked_Up = false;
    Bind_When_Equipped = false;
    Bind_When_Use = false;
    Bind_Quest_Item = false;

    DisableBeta_PTR_Unused = false;
    DisablePermEnchant = false;
#if CLIENT_VER > 300
    DisableConjured = false;
#endif
    DisableGems = false;
    DisableMoney = false;
    DisableMoneyLoot = false;
    DisableLootable = false;
    DisableKeys = false;
    DisableDuration = false;
    DisableBOP_Or_Quest_NoReqLevel = false;

    DisableWarriorItems = false;
    DisablePaladinItems = false;
    DisableHunterItems = false;
    DisableRogueItems = false;
    DisablePriestItems = false;
    DisableDKItems = false;
    DisableShamanItems = false;
    DisableMageItems = false;
    DisableWarlockItems = false;
    DisableUnusedClassItems = false;
    DisableDruidItems = false;

    DisableItemsBelowLevel = 0;
    DisableItemsAboveLevel = 0;
    DisableTGsBelowLevel = 0;
    DisableTGsAboveLevel = 0;
    DisableItemsBelowGUID = 0;
    DisableItemsAboveGUID = 0;
    DisableTGsBelowGUID = 0;
    DisableTGsAboveGUID = 0;
    DisableItemsBelowReqLevel = 0;
    DisableItemsAboveReqLevel = 0;
    DisableTGsBelowReqLevel = 0;
    DisableTGsAboveReqLevel = 0;
    DisableItemsBelowReqSkillRank = 0;
    DisableItemsAboveReqSkillRank = 0;
    DisableTGsBelowReqSkillRank = 0;
    DisableTGsAboveReqSkillRank = 0;

    //End Filters

    _lastrun_a = time(NULL);
    _lastrun_h = time(NULL);
    _lastrun_n = time(NULL);

    AllianceConfig = AHBConfig(2);
    HordeConfig = AHBConfig(6);
    NeutralConfig = AHBConfig(7);
}

AuctionHouseBot::~AuctionHouseBot()
{
}

void AuctionHouseBot::addNewAuctions(Player *AHBplayer, AHBConfig *config)
{
    if (!AHBSeller)
    {
        if (debug_Out) sLog.outError("AHSeller: Disabled");
        return;
    }

    uint32 minItems = config->GetMinItems();
    uint32 maxItems = config->GetMaxItems();

    if (maxItems == 0)
    {
        //if (debug_Out) sLog.outString("AHSeller: Auctions disabled");
        return;
    }

    AuctionHouseEntry const* ahEntry = auctionmgr.GetAuctionHouseEntry(config->GetAHFID());
    if (!ahEntry)
    {
        return;
    }
    AuctionHouseObject* auctionHouse = auctionmgr.GetAuctionsMap(config->GetAHFID());
    if (!auctionHouse)
    {
        return;
    }

    uint32 auctions = auctionHouse->Getcount();

    if (auctions >= minItems)
    {
        //if (debug_Out) sLog.outString("AHSeller: Auctions above minimum");
        return;
    }

    if (auctions >= maxItems)
    {
        //if (debug_Out) sLog.outString("AHSeller: Auctions at or above maximum");
        return;
    }

    uint32 items = 0;
    if ((maxItems - auctions) >= ItemsPerCycle)
        items = ItemsPerCycle;
    else
        items = (maxItems - auctions);

    if (debug_Out) sLog.outString("AHSeller: Adding %u Auctions", items);

    uint32 AuctioneerGUID = 0;

    switch (config->GetAHID())
    {
    case 2:
        AuctioneerGUID = 79707; //Human in stormwind.
        break;
    case 6:
        AuctioneerGUID = 4656; //orc in Orgrimmar
        break;
    case 7:
        AuctioneerGUID = 23442; //goblin in GZ
        break;
    default:
        if (debug_Out) sLog.outError("AHSeller: GetAHID() - Default switch reached");
        AuctioneerGUID = 23442; //default to neutral 7
        break;
    }

    if (debug_Out) sLog.outString("AHSeller: Current Auctineer GUID is %u", AuctioneerGUID);

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

    uint32 greyTGoods = config->GetItemCounts(AHB_GREY_TG);
    uint32 whiteTGoods = config->GetItemCounts(AHB_WHITE_TG);
    uint32 greenTGoods = config->GetItemCounts(AHB_GREEN_TG);
    uint32 blueTGoods = config->GetItemCounts(AHB_BLUE_TG);
    uint32 purpleTGoods = config->GetItemCounts(AHB_PURPLE_TG);
    uint32 orangeTGoods = config->GetItemCounts(AHB_ORANGE_TG);
    uint32 yellowTGoods = config->GetItemCounts(AHB_YELLOW_TG);

    uint32 greyItems = config->GetItemCounts(AHB_GREY_I);
    uint32 whiteItems = config->GetItemCounts(AHB_WHITE_I);
    uint32 greenItems = config->GetItemCounts(AHB_GREEN_I);
    uint32 blueItems = config->GetItemCounts(AHB_BLUE_I);
    uint32 purpleItems = config->GetItemCounts(AHB_PURPLE_I);
    uint32 orangeItems = config->GetItemCounts(AHB_ORANGE_I);
    uint32 yellowItems = config->GetItemCounts(AHB_YELLOW_I);
    if (debug_Out) sLog.outString("AHSeller: %u items", items);

    // only insert a few at a time, so as not to peg the processor
    for (uint32 cnt = 1; cnt <= items; cnt++)
    {
    if (debug_Out) sLog.outString("AHSeller: %u count", cnt);
        uint32 itemID = 0;
        uint32 itemColor = 99;
        uint32 loopbreaker = 0;
        while (itemID == 0 && loopbreaker <= 50)
        {
            ++loopbreaker;
            uint32 choice = urand(0, 13);
            itemColor = choice;
            switch (choice)
            {
            case 0:
                {
                    if ((greyItemsBin.size() > 0) && (greyItems < greyIcount))
                        itemID = greyItemsBin[urand(0, greyItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 1:
                {
                    if ((whiteItemsBin.size() > 0) && (whiteItems < whiteIcount))
                        itemID = whiteItemsBin[urand(0, whiteItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 2:
                {
                    if ((greenItemsBin.size() > 0) && (greenItems < greenIcount))
                        itemID = greenItemsBin[urand(0, greenItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 3:
                {
                    if ((blueItemsBin.size() > 0) && (blueItems < blueIcount))
                        itemID = blueItemsBin[urand(0, blueItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 4:
                {
                    if ((purpleItemsBin.size() > 0) && (purpleItems < purpleIcount))
                        itemID = purpleItemsBin[urand(0, purpleItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 5:
                {
                    if ((orangeItemsBin.size() > 0) && (orangeItems < orangeIcount))
                        itemID = orangeItemsBin[urand(0, orangeItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 6:
                {
                    if ((yellowItemsBin.size() > 0) && (yellowItems < yellowIcount))
                        itemID = yellowItemsBin[urand(0, yellowItemsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 7:
                {
                    if ((greyTradeGoodsBin.size() > 0) && (greyTGoods < greyTGcount))
                        itemID = greyTradeGoodsBin[urand(0, greyTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 8:
                {
                    if ((whiteTradeGoodsBin.size() > 0) && (whiteTGoods < whiteTGcount))
                        itemID = whiteTradeGoodsBin[urand(0, whiteTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 9:
                {
                    if ((greenTradeGoodsBin.size() > 0) && (greenTGoods < greenTGcount))
                        itemID = greenTradeGoodsBin[urand(0, greenTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 10:
                {
                    if ((blueTradeGoodsBin.size() > 0) && (blueTGoods < blueTGcount))
                        itemID = blueTradeGoodsBin[urand(0, blueTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 11:
                {
                    if ((purpleTradeGoodsBin.size() > 0) && (purpleTGoods < purpleTGcount))
                        itemID = purpleTradeGoodsBin[urand(0, purpleTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 12:
                {
                    if ((orangeTradeGoodsBin.size() > 0) && (orangeTGoods < orangeTGcount))
                        itemID = orangeTradeGoodsBin[urand(0, orangeTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            case 13:
                {
                    if ((yellowTradeGoodsBin.size() > 0) && (yellowTGoods < yellowTGcount))
                        itemID = yellowTradeGoodsBin[urand(0, yellowTradeGoodsBin.size() - 1)];
                    else continue;
                    break;
                }
            default:
                {
                    if (debug_Out) sLog.outError("AHSeller: itemID Switch - Default Reached");
                    break;
                }
            }

            if (itemID == 0)
            {
                if (debug_Out) sLog.outError("AHSeller: Item::CreateItem() - ItemID is 0");
                continue;
            }

            ItemPrototype const* prototype = objmgr.GetItemPrototype(itemID);
            if (prototype == NULL)
            {
                if (debug_Out) sLog.outError("AHSeller: Huh?!?! prototype == NULL");
                continue;
            }

            Item* item = Item::CreateItem(itemID, 1, AHBplayer);
            if (item == NULL)
            {
                if (debug_Out) sLog.outError("AHSeller: Item::CreateItem() returned NULL");
                break;
            }
            item->AddToUpdateQueueOf(AHBplayer);

            uint32 randomPropertyId = Item::GenerateItemRandomPropertyId(itemID);
            if (randomPropertyId != 0)
                item->SetItemRandomProperties(randomPropertyId);

            uint64 buyoutPrice = 0;
            uint64 bidPrice = 0;
            uint32 stackCount = 1;

            switch (SellMethod)
            {
            case 0:
                buyoutPrice  = prototype->SellPrice;
                break;
            case 1:
                buyoutPrice  = prototype->BuyPrice;
                break;
            }

            if ((prototype->Quality >= 0) && (prototype->Quality <= AHB_MAX_QUALITY))
            {
                if (config->GetMaxStack(prototype->Quality) > 1 && item->GetMaxStackCount() > 1)
                    stackCount = urand(1, minValue(item->GetMaxStackCount(), config->GetMaxStack(prototype->Quality)));
                else if (config->GetMaxStack(prototype->Quality) == 0 && item->GetMaxStackCount() > 1)
                    stackCount = urand(1, item->GetMaxStackCount());
                else
                    stackCount = 1;
                buyoutPrice *= urand(config->GetMinPrice(prototype->Quality), config->GetMaxPrice(prototype->Quality));
                buyoutPrice /= 100;
                bidPrice = buyoutPrice * urand(config->GetMinBidPrice(prototype->Quality), config->GetMaxBidPrice(prototype->Quality));
                bidPrice /= 100;
            }
            else
            {
                // quality is something it shouldn't be, let's get out of here
                if (debug_Out) sLog.outError("AHBuyer: Quality %u not Supported", prototype->Quality);
                item->RemoveFromUpdateQueueOf(AHBplayer);
                continue;
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
            item->SetCount(stackCount);

            uint32 dep = auctionmgr.GetAuctionDeposit(ahEntry, etime, item);

            AuctionEntry* auctionEntry = new AuctionEntry;
            auctionEntry->Id = objmgr.GenerateAuctionID();
            auctionEntry->auctioneer = AuctioneerGUID;
            auctionEntry->item_guidlow = item->GetGUIDLow();
            auctionEntry->item_template = item->GetEntry();
            auctionEntry->owner = AHBplayer->GetGUIDLow();
            auctionEntry->startbid = bidPrice * stackCount;
            auctionEntry->buyout = buyoutPrice * stackCount;
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

            switch(itemColor)
            {
            case 0:
                ++greyItems;
                break;
            case 1:
                ++whiteItems;
                break;
            case 2:
                ++greenItems;
                break;
            case 3:
                ++blueItems;
                break;
            case 4:
                ++purpleItems;
                break;
            case 5:
                ++orangeItems;
                break;
            case 6:
                ++yellowItems;
                break;
            case 7:
                ++greyTGoods;
                break;
            case 8:
                ++whiteTGoods;
                break;
            case 9:
                ++greenTGoods;
                break;
            case 10:
                ++blueTGoods;
                break;
            case 11:
                ++purpleTGoods;
                break;
            case 12:
                ++orangeTGoods;
                break;
            case 13:
                ++yellowTGoods;
                break;
            default:
                break;
            }
        }
    }
}
void AuctionHouseBot::addNewAuctionBuyerBotBid(Player *AHBplayer, AHBConfig *config, WorldSession *session)
{
    if (!AHBBuyer)
    {
        if (debug_Out) sLog.outError("AHBuyer: Disabled");
        return;
    }

    QueryResult* result = CharacterDatabase.PQuery("SELECT id FROM auctionhouse WHERE itemowner<>%u AND buyguid<>%u", AHBplayerGUID, AHBplayerGUID);

    if (!result)
    {
        delete result;
        return;
    }

    if (result->GetRowCount() == 0)
    {
        delete result;
        return;
    }

    // Fetches content of selected AH
    AuctionHouseObject* auctionHouse = auctionmgr.GetAuctionsMap(config->GetAHFID());
    vector<uint32> possibleBids;

    do
    {
        uint32 tmpdata = result->Fetch()->GetUInt32();
        possibleBids.push_back(tmpdata);
    }while (result->NextRow());
    delete result;

    for (uint32 count = 1; count <= config->GetBidsPerInterval(); ++count)
    {
        // Do we have anything to bid? If not, stop here.
        if (possibleBids.empty())
        {
            //if (debug_Out) sLog.outString("AHBuyer: I have no items to bid on.");
            count = config->GetBidsPerInterval();
            continue;
        }

        // Choose random auction from possible auctions
        uint32 vectorPos = urand(0, possibleBids.size() - 1);
        vector<uint32>::iterator iter = possibleBids.begin();
        advance(iter, vectorPos);

        // from auctionhousehandler.cpp, creates auction pointer & player pointer
        AuctionEntry* auction = auctionHouse->GetAuction(*iter);

        // Erase the auction from the vector to prevent bidding on item in next iteration.
        possibleBids.erase(iter);

        if (!auction)
        {
            continue;
        }

        // get exact item information
        Item *pItem = auctionmgr.GetAItem(auction->item_guidlow);
        if (!pItem)
        {
            if (debug_Out) sLog.outError("AHBuyer: Item %u doesn't exist, perhaps bought already?", auction->item_guidlow);
            continue;
        }

        // get item prototype
        ItemPrototype const* prototype = objmgr.GetItemPrototype(auction->item_template);

        // check which price we have to use, startbid or if it is bidded already
        uint32 currentprice;
        if (auction->bid)
            currentprice = auction->bid;
        else
            currentprice = auction->startbid;

        // Prepare portion from maximum bid
        double bidrate = static_cast<double>(urand(1, 100)) / 100;
        long double bidMax = 0;

        // check that bid has acceptable value and take bid based on vendorprice, stacksize and quality
        switch (BuyMethod)
        {
        case 0:
            {
                if ((prototype->Quality >= 0) && (prototype->Quality <= AHB_MAX_QUALITY))
                {
                    if (currentprice < prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(prototype->Quality))
                        bidMax = prototype->SellPrice * pItem->GetCount() * config->GetBuyerPrice(prototype->Quality);
                }
                else
                {
                    // quality is something it shouldn't be, let's get out of here
                    if (debug_Out) sLog.outError("AHBuyer: Quality %u not Supported", prototype->Quality);
                    continue;
                }
                break;
            }
        case 1:
            {
                if ((prototype->Quality >= 0) && (prototype->Quality <= AHB_MAX_QUALITY))
                {
                    if (currentprice < prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(prototype->Quality))
                        bidMax = prototype->BuyPrice * pItem->GetCount() * config->GetBuyerPrice(prototype->Quality);
                }
                else
                {
                    // quality is something it shouldn't be, let's get out of here
                    if (debug_Out) sLog.outError("AHBuyer: Quality %u not Supported", prototype->Quality);
                    continue;
                }
                break;
            }
        }

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

        if (bidMax == 0)
        {
            // quality check failed to get bidmax, let's get out of here
            continue;
        }

        // Calculate our bid
        long double bidvalue = currentprice + ((bidMax - currentprice) * bidrate);
        // Convert to uint32
        uint32 bidprice = static_cast<uint32>(bidvalue);

        // Check our bid is high enough to be valid. If not, correct it to minimum.
        if ((currentprice + auction->GetAuctionOutBid()) > bidprice)
            bidprice = currentprice + auction->GetAuctionOutBid();

        if (debug_Out)
        {
            sLog.outString("-------------------------------------------------");
            sLog.outString("AHBuyer: Info for Auction #%u:", auction->Id);
            sLog.outString("AHBuyer: AuctionHouse: %u", auction->GetHouseId());
            sLog.outString("AHBuyer: Auctioneer: %u", auction->auctioneer);
            sLog.outString("AHBuyer: Owner: %u", auction->owner);
            sLog.outString("AHBuyer: Bidder: %u", auction->bidder);
            sLog.outString("AHBuyer: Starting Bid: %u", auction->startbid);
            sLog.outString("AHBuyer: Current Bid: %u", currentprice);
            sLog.outString("AHBuyer: Buyout: %u", auction->buyout);
            sLog.outString("AHBuyer: Deposit: %u", auction->deposit);
            sLog.outString("AHBuyer: Expire Time: %u", auction->expire_time);
            sLog.outString("AHBuyer: Bid Rate: %f", bidrate);
            sLog.outString("AHBuyer: Bid Max: %f", bidMax);
            sLog.outString("AHBuyer: Bid Value: %f", bidvalue);
            sLog.outString("AHBuyer: Bid Price: %u", bidprice);
            sLog.outString("AHBuyer: Item GUID: %u", auction->item_guidlow);
            sLog.outString("AHBuyer: Item Template: %u", auction->item_template);
            sLog.outString("AHBuyer: Item Info:");
            sLog.outString("AHBuyer: Item ID: %u", prototype->ItemId);
            sLog.outString("AHBuyer: Buy Price: %u", prototype->BuyPrice);
            sLog.outString("AHBuyer: Sell Price: %u", prototype->SellPrice);
            sLog.outString("AHBuyer: Bonding: %u", prototype->Bonding);
            sLog.outString("AHBuyer: Quality: %u", prototype->Quality);
            sLog.outString("AHBuyer: Item Level: %u", prototype->ItemLevel);
            sLog.outString("AHBuyer: Ammo Type: %u", prototype->AmmoType);
            sLog.outString("-------------------------------------------------");
        }

        // Check whether we do normal bid, or buyout
        if ((bidprice < auction->buyout) || (auction->buyout == 0))
        {

            if (auction->bidder > 0)
            {
                if (auction->bidder == AHBplayer->GetGUIDLow())
                {
                    //pl->ModifyMoney(-int32(price - auction->bid));
                }
                else
                {
                    // mail to last bidder and return money
                    session->SendAuctionOutbiddedMail(auction , bidprice);
                    //pl->ModifyMoney(-int32(price));
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
            if ((auction->bidder) && (AHBplayer->GetGUIDLow() != auction->bidder))
            {
                session->SendAuctionOutbiddedMail(auction, auction->buyout);
            }
            auction->bidder = AHBplayer->GetGUIDLow();
            auction->bid = auction->buyout;

            // Send mails to buyer & seller
            auctionmgr.SendAuctionSalePendingMail(auction);
            auctionmgr.SendAuctionSuccessfulMail(auction);
            auctionmgr.SendAuctionWonMail(auction);
            auction->DeleteFromDB();
            uint32 item_template = auction->item_template;
            auctionmgr.RemoveAItem(auction->item_guidlow);
            auctionHouse->RemoveAuction(auction, item_template);
        }
    }
}

void AuctionHouseBot::Update()
{
    time_t _newrun = time(NULL);
    if ((!AHBSeller) && (!AHBBuyer))
        return;

    WorldSession _session(AHBplayerAccount, NULL, SEC_PLAYER, true, 0, LOCALE_enUS);
    Player _AHBplayer(&_session);
    _AHBplayer.MinimalLoadFromDB(NULL, AHBplayerGUID);
    ObjectAccessor::Instance().AddObject(&_AHBplayer);

    // Only for testing, this can likely be removed, once I know it's working as expected.
    /*
    AuctionHouseObject* auctionHouse1 = auctionmgr.GetAuctionsMap(55);
    AuctionHouseObject* auctionHouse2 = auctionmgr.GetAuctionsMap(29);
    AuctionHouseObject* auctionHouse3 = auctionmgr.GetAuctionsMap(120);
    uint32 totalItemsAH = (auctionHouse1->Getcount() + auctionHouse2->Getcount() + auctionHouse3->Getcount());
    uint32 totalItems = (AllianceConfig.TotalItemCounts() + HordeConfig.TotalItemCounts() + NeutralConfig.TotalItemCounts());
    if (totalItemsAH != totalItems)
    {
        sLog.outError("AHBot: The AuctionHouses say there are %u auctions, but, I think there are %u auctions...", totalItemsAH, totalItems);
        return;
    }
    */

    // Add New Bids
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        addNewAuctions(&_AHBplayer, &AllianceConfig);
        if (((_newrun - _lastrun_a) >= (AllianceConfig.GetBiddingInterval() * MINUTE)) && (AllianceConfig.GetBidsPerInterval() > 0))
        {
            //if (debug_Out) sLog.outString("AHBuyer: %u seconds have passed since last bid", (_newrun - _lastrun_a));
            //if (debug_Out) sLog.outString("AHBuyer: Bidding on Alliance Auctions");
            addNewAuctionBuyerBotBid(&_AHBplayer, &AllianceConfig, &_session);
            _lastrun_a = _newrun;
        }

        addNewAuctions(&_AHBplayer, &HordeConfig);
        if (((_newrun - _lastrun_h) >= (HordeConfig.GetBiddingInterval() * MINUTE)) && (HordeConfig.GetBidsPerInterval() > 0))
        {
            //if (debug_Out) sLog.outString("AHBuyer: %u seconds have passed since last bid", (_newrun - _lastrun_h));
            //if (debug_Out) sLog.outString("AHBuyer: Bidding on Horde Auctions");
            addNewAuctionBuyerBotBid(&_AHBplayer, &HordeConfig, &_session);
            _lastrun_h = _newrun;
        }
    }

    addNewAuctions(&_AHBplayer, &NeutralConfig);
    if (((_newrun - _lastrun_n) >= (NeutralConfig.GetBiddingInterval() * MINUTE)) && (NeutralConfig.GetBidsPerInterval() > 0))
    {
        //if (debug_Out) sLog.outString("AHBuyer: %u seconds have passed since last bid", (_newrun - _lastrun_n));
        //if (debug_Out) sLog.outString("AHBuyer: Bidding on Neutral Auctions");
        addNewAuctionBuyerBotBid(&_AHBplayer, &NeutralConfig, &_session);
        _lastrun_n = _newrun;
    }
    ObjectAccessor::Instance().RemoveObject(&_AHBplayer);
}

void AuctionHouseBot::Initialize()
{
    debug_Out = sConfig.GetBoolDefault("AuctionHouseBot.DEBUG", false);
    debug_Out_Filters = sConfig.GetBoolDefault("AuctionHouseBot.DEBUG_FILTERS", false);

    AHBSeller = sConfig.GetBoolDefault("AuctionHouseBot.EnableSeller", false);
    AHBBuyer = sConfig.GetBoolDefault("AuctionHouseBot.EnableBuyer", false);
    SellMethod = sConfig.GetBoolDefault("AuctionHouseBot.UseBuyPriceForSeller", false);
    BuyMethod = sConfig.GetBoolDefault("AuctionHouseBot.UseBuyPriceForBuyer", false);

    AHBplayerAccount = sConfig.GetIntDefault("AuctionHouseBot.Account", 0);
    AHBplayerGUID = sConfig.GetIntDefault("AuctionHouseBot.GUID", 0);
    ItemsPerCycle = sConfig.GetIntDefault("AuctionHouseBot.ItemsPerCycle", 200);

    //Begin Filters

    Vendor_Items = sConfig.GetBoolDefault("AuctionHouseBot.VendorItems", false);
    Loot_Items = sConfig.GetBoolDefault("AuctionHouseBot.LootItems", true);
    Other_Items = sConfig.GetBoolDefault("AuctionHouseBot.OtherItems", false);
    Vendor_TGs = sConfig.GetBoolDefault("AuctionHouseBot.VendorTradeGoods", false);
    Loot_TGs = sConfig.GetBoolDefault("AuctionHouseBot.LootTradeGoods", true);
    Other_TGs = sConfig.GetBoolDefault("AuctionHouseBot.OtherTradeGoods", false);

    No_Bind = sConfig.GetBoolDefault("AuctionHouseBot.No_Bind", true);
    Bind_When_Picked_Up = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Picked_Up", false);
    Bind_When_Equipped = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Equipped", true);
    Bind_When_Use = sConfig.GetBoolDefault("AuctionHouseBot.Bind_When_Use", true);
    Bind_Quest_Item = sConfig.GetBoolDefault("AuctionHouseBot.Bind_Quest_Item", false);

    DisableBeta_PTR_Unused = sConfig.GetBoolDefault("AuctionHouseBot.DisableBeta_PTR_Unused", false);
    DisablePermEnchant = sConfig.GetBoolDefault("AuctionHouseBot.DisablePermEnchant", false);
#if CLIENT_VER > 300
    DisableConjured = sConfig.GetBoolDefault("AuctionHouseBot.DisableConjured", false);
#endif
    DisableGems = sConfig.GetBoolDefault("AuctionHouseBot.DisableGems", false);
    DisableMoney = sConfig.GetBoolDefault("AuctionHouseBot.DisableMoney", false);
    DisableMoneyLoot = sConfig.GetBoolDefault("AuctionHouseBot.DisableMoneyLoot", false);
    DisableLootable = sConfig.GetBoolDefault("AuctionHouseBot.DisableLootable", false);
    DisableKeys = sConfig.GetBoolDefault("AuctionHouseBot.DisableKeys", false);
    DisableDuration = sConfig.GetBoolDefault("AuctionHouseBot.DisableDuration", false);
    DisableBOP_Or_Quest_NoReqLevel = sConfig.GetBoolDefault("AuctionHouseBot.DisableBOP_Or_Quest_NoReqLevel", false);

    DisableWarriorItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableWarriorItems", false);
    DisablePaladinItems = sConfig.GetBoolDefault("AuctionHouseBot.DisablePaladinItems", false);
    DisableHunterItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableHunterItems", false);
    DisableRogueItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableRogueItems", false);
    DisablePriestItems = sConfig.GetBoolDefault("AuctionHouseBot.DisablePriestItems", false);
    DisableDKItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableDKItems", false);
    DisableShamanItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableShamanItems", false);
    DisableMageItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableMageItems", false);
    DisableWarlockItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableWarlockItems", false);
    DisableUnusedClassItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableUnusedClassItems", false);
    DisableDruidItems = sConfig.GetBoolDefault("AuctionHouseBot.DisableDruidItems", false);

    DisableItemsBelowLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsBelowLevel", 0);
    DisableItemsAboveLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsAboveLevel", 0);
    DisableTGsBelowLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsBelowLevel", 0);
    DisableTGsAboveLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsAboveLevel", 0);
    DisableItemsBelowGUID = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsBelowGUID", 0);
    DisableItemsAboveGUID = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsAboveGUID", 0);
    DisableTGsBelowGUID = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsBelowGUID", 0);
    DisableTGsAboveGUID = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsAboveGUID", 0);
    DisableItemsBelowReqLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsBelowReqLevel", 0);
    DisableItemsAboveReqLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsAboveReqLevel", 0);
    DisableTGsBelowReqLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsBelowReqLevel", 0);
    DisableTGsAboveReqLevel = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsAboveReqLevel", 0);
    DisableItemsBelowReqSkillRank = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsBelowReqSkillRank", 0);
    DisableItemsAboveReqSkillRank = sConfig.GetIntDefault("AuctionHouseBot.DisableItemsAboveReqSkillRank", 0);
    DisableTGsBelowReqSkillRank = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsBelowReqSkillRank", 0);
    DisableTGsAboveReqSkillRank = sConfig.GetIntDefault("AuctionHouseBot.DisableTGsAboveReqSkillRank", 0);

    //End Filters
    if (!sWorld.getConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        LoadValues(&AllianceConfig);
        LoadValues(&HordeConfig);
    }
    LoadValues(&NeutralConfig);

    if (AHBSeller)
    {
        QueryResult* results = (QueryResult*) NULL;
        char npcQuery[] = "SELECT distinct item FROM npc_vendor";
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
            if (debug_Out) sLog.outString("AuctionHouseBot: \"%s\" failed", npcQuery);
        }

        char lootQuery[] = "SELECT item FROM creature_loot_template UNION "
            "SELECT item FROM disenchant_loot_template UNION "
            "SELECT item FROM fishing_loot_template UNION "
            "SELECT item FROM gameobject_loot_template UNION "
            "SELECT item FROM item_loot_template UNION "
#if CLIENT_VER > 300
            "SELECT item FROM milling_loot_template UNION "
#endif
            "SELECT item FROM pickpocketing_loot_template UNION "
            "SELECT item FROM prospecting_loot_template UNION "
            "SELECT item FROM skinning_loot_template";

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
            if (debug_Out) sLog.outString("AuctionHouseBot: \"%s\" failed", lootQuery);
        }

        for (uint32 itemID = 0; itemID < sItemStorage.MaxEntry; itemID++)
        {
            ItemPrototype const* prototype = objmgr.GetItemPrototype(itemID);

            if (prototype == NULL)
                continue;

            switch (prototype->Bonding)
            {
            case NO_BIND:
                if (!No_Bind)
                    continue;
                break;
            case BIND_WHEN_PICKED_UP:
                if (!Bind_When_Picked_Up)
                    continue;
                break;
            case BIND_WHEN_EQUIPED:
                if (!Bind_When_Equipped)
                    continue;
                break;
            case BIND_WHEN_USE:
                if (!Bind_When_Use)
                    continue;
                break;
            case BIND_QUEST_ITEM:
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
            }

            if ((prototype->Quality < 0) || (prototype->Quality > 6))
                continue;

            if ((Vendor_Items == 0) && !(prototype->Class == ITEM_CLASS_TRADE_GOODS))
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

            if ((Vendor_TGs == 0) && (prototype->Class == ITEM_CLASS_TRADE_GOODS))
            {
                bool isVendorTG = false;

                for (unsigned int i = 0; (i < npcItems.size()) && (!isVendorTG); i++)
                {
                    if (itemID == npcItems[i])
                        isVendorTG = true;
                }

                if (isVendorTG)
                    continue;
            }

            if ((Loot_Items == 0) && !(prototype->Class == ITEM_CLASS_TRADE_GOODS))
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

            if ((Loot_TGs == 0) && (prototype->Class == ITEM_CLASS_TRADE_GOODS))
            {
                bool isLootTG = false;

                for (unsigned int i = 0; (i < lootItems.size()) && (!isLootTG); i++)
                {
                    if (itemID == lootItems[i])
                        isLootTG = true;
                }

                if (isLootTG)
                    continue;
            }

            if ((Other_Items == 0) && !(prototype->Class == ITEM_CLASS_TRADE_GOODS))
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

            if ((Other_TGs == 0) && (prototype->Class == ITEM_CLASS_TRADE_GOODS))
            {
                bool isVendorTG = false;
                bool isLootTG = false;

                for (unsigned int i = 0; (i < npcItems.size()) && (!isVendorTG); i++)
                {
                    if (itemID == npcItems[i])
                        isVendorTG = true;
                }
                for (unsigned int i = 0; (i < lootItems.size()) && (!isLootTG); i++)
                {
                    if (itemID == lootItems[i])
                        isLootTG = true;
                }
                if ((!isLootTG) && (!isVendorTG))
                    continue;
            }

             //TODO:Make list of items and create a vector
            // Disable PTR/Beta/Unused items
            if ((DisableBeta_PTR_Unused) && ((prototype->ItemId == 21878) || (prototype->ItemId == 27774) || (prototype->ItemId == 27811) || (prototype->ItemId == 28117) || (prototype->ItemId == 28112)))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (PTR/Beta/Unused Item)", prototype->ItemId);
                continue;
            }

            // Disable permanent enchants items
            if ((DisablePermEnchant) && (prototype->Class == ITEM_CLASS_PERMANENT))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Permanent Enchant Item)", prototype->ItemId);
                continue;
            }

#if CLIENT_VER > 300
            // Disable conjured items
            if ((DisableConjured) && (prototype->IsConjuredConsumable()))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Conjured Consumable)", prototype->ItemId);
                continue;
            }
#endif

            // Disable gems
            if ((DisableGems) && (prototype->Class == ITEM_CLASS_GEM))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Gem)", prototype->ItemId);
                continue;
            }

            // Disable money
            if ((DisableMoney) && (prototype->Class == ITEM_CLASS_MONEY))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Money)", prototype->ItemId);
                continue;
            }

            // Disable moneyloot
            if ((DisableMoneyLoot) && (prototype->MinMoneyLoot > 0))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (MoneyLoot)", prototype->ItemId);
                continue;
            }

            // Disable lootable items
            if ((DisableLootable) && (prototype->Flags & 4))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Lootable Item)", prototype->ItemId);
                continue;
            }

            // Disable Keys
            if ((DisableKeys) && (prototype->Class == ITEM_CLASS_KEY))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Quest Item)", prototype->ItemId);
                continue;
            }

            // Disable items with duration
            if ((DisableDuration) && (prototype->Duration > 0))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Has a Duration)", prototype->ItemId);
                continue;
            }

            // Disable items which are BOP or Quest Items and have a required level lower than the item level
            if ((DisableBOP_Or_Quest_NoReqLevel) && ((prototype->Bonding == BIND_WHEN_PICKED_UP || prototype->Bonding == BIND_QUEST_ITEM) && (prototype->RequiredLevel < prototype->ItemLevel)))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (BOP or BQI and Required Level is less than Item Level)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Warrior
            if ((DisableWarriorItems) && (prototype->AllowableClass == 1))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Warrior Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Paladin
            if ((DisablePaladinItems) && (prototype->AllowableClass == 2))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Paladin Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Hunter
            if ((DisableHunterItems) && (prototype->AllowableClass == 4))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Hunter Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Rogue
            if ((DisableRogueItems) && (prototype->AllowableClass == 8))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Rogue Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Priest
            if ((DisablePriestItems) && (prototype->AllowableClass == 16))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Priest Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for DK
            if ((DisableDKItems) && (prototype->AllowableClass == 32))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (DK Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Shaman
            if ((DisableShamanItems) && (prototype->AllowableClass == 64))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Shaman Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Mage
            if ((DisableMageItems) && (prototype->AllowableClass == 128))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Mage Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Warlock
            if ((DisableWarlockItems) && (prototype->AllowableClass == 256))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Warlock Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Unused Class
            if ((DisableUnusedClassItems) && (prototype->AllowableClass == 512))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Unused Item)", prototype->ItemId);
                continue;
            }

            // Disable items specifically for Druid
            if ((DisableDruidItems) && (prototype->AllowableClass == 1024))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Druid Item)", prototype->ItemId);
                continue;
            }

             // Disable Items below level X
            if ((DisableItemsBelowLevel) && (prototype->Class != ITEM_CLASS_TRADE_GOODS) && (prototype->ItemLevel < DisableItemsBelowLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Item Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

            // Disable Items above level X
            if ((DisableItemsAboveLevel) && (prototype->Class != ITEM_CLASS_TRADE_GOODS) && (prototype->ItemLevel > DisableItemsAboveLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Item Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

           // Disable Trade Goods below level X
            if ((DisableTGsBelowLevel) && (prototype->Class == ITEM_CLASS_TRADE_GOODS) && (prototype->ItemLevel < DisableTGsBelowLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Trade Good %u disabled (Trade Good Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

           // Disable Trade Goods above level X
            if ((DisableTGsAboveLevel) && (prototype->Class == ITEM_CLASS_TRADE_GOODS) && (prototype->ItemLevel > DisableTGsAboveLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Trade Good %u disabled (Trade Good Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

            // Disable Items below GUID X
            if ((DisableItemsBelowGUID) && (prototype->Class != ITEM_CLASS_TRADE_GOODS) && (prototype->ItemId < DisableItemsBelowGUID))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Item Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

            // Disable Items above GUID X
            if ((DisableItemsAboveGUID) && (prototype->Class != ITEM_CLASS_TRADE_GOODS) && (prototype->ItemId > DisableItemsAboveGUID))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Item Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

            // Disable Trade Goods below GUID X
            if ((DisableTGsBelowGUID) && (prototype->Class == ITEM_CLASS_TRADE_GOODS) && (prototype->ItemId < DisableTGsBelowGUID))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Trade Good Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

            // Disable Trade Goods above GUID X
            if ((DisableTGsAboveGUID) && (prototype->Class == ITEM_CLASS_TRADE_GOODS) && (prototype->ItemId > DisableTGsAboveGUID))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (Trade Good Level = %u)", prototype->ItemId, prototype->ItemLevel);
                continue;
            }

            // Disable Items for level lower than X
            if ((DisableItemsBelowReqLevel) && (prototype->RequiredLevel < DisableItemsBelowReqLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (RequiredLevel = %u)", prototype->ItemId, prototype->RequiredLevel);
                continue;
            }

            // Disable Items for level higher than X
            if ((DisableItemsAboveReqLevel) && (prototype->RequiredLevel > DisableItemsAboveReqLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (RequiredLevel = %u)", prototype->ItemId, prototype->RequiredLevel);
                continue;
            }

            // Disable Trade Goods for level lower than X
            if ((DisableTGsBelowReqLevel) && (prototype->RequiredLevel < DisableTGsBelowReqLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Trade Good %u disabled (RequiredLevel = %u)", prototype->ItemId, prototype->RequiredLevel);
                continue;
            }

            // Disable Trade Goods for level higher than X
            if ((DisableTGsAboveReqLevel) && (prototype->RequiredLevel > DisableTGsAboveReqLevel))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Trade Good %u disabled (RequiredLevel = %u)", prototype->ItemId, prototype->RequiredLevel);
                continue;
            }

            // Disable Items that require skill lower than X
            if ((DisableItemsBelowReqSkillRank) && (prototype->RequiredSkillRank < DisableItemsBelowReqSkillRank))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (RequiredSkillRank = %u)", prototype->ItemId, prototype->RequiredSkillRank);
                continue;
            }

            // Disable Items that require skill higher than X
            if ((DisableItemsAboveReqSkillRank) && (prototype->RequiredSkillRank > DisableItemsAboveReqSkillRank))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (RequiredSkillRank = %u)", prototype->ItemId, prototype->RequiredSkillRank);
                continue;
            }

            // Disable Trade Goods that require skill lower than X
            if ((DisableTGsBelowReqSkillRank) && (prototype->RequiredSkillRank < DisableTGsBelowReqSkillRank))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (RequiredSkillRank = %u)", prototype->ItemId, prototype->RequiredSkillRank);
                continue;
            }

            // Disable Trade Goods that require skill higher than X
            if ((DisableTGsAboveReqSkillRank) && (prototype->RequiredSkillRank > DisableTGsAboveReqSkillRank))
            {
                if (debug_Out_Filters) sLog.outString("AuctionHouseBot: Item %u disabled (RequiredSkillRank = %u)", prototype->ItemId, prototype->RequiredSkillRank);
                continue;
            }

            switch (prototype->Quality)
            {
            case AHB_GREY:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    greyTradeGoodsBin.push_back(itemID);
                else
                    greyItemsBin.push_back(itemID);
                break;

            case AHB_WHITE:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    whiteTradeGoodsBin.push_back(itemID);
                else
                    whiteItemsBin.push_back(itemID);
                break;

            case AHB_GREEN:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    greenTradeGoodsBin.push_back(itemID);
                else
                    greenItemsBin.push_back(itemID);
                break;

            case AHB_BLUE:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    blueTradeGoodsBin.push_back(itemID);
                else
                    blueItemsBin.push_back(itemID);
                break;

            case AHB_PURPLE:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    purpleTradeGoodsBin.push_back(itemID);
                else
                    purpleItemsBin.push_back(itemID);
                break;

            case AHB_ORANGE:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    orangeTradeGoodsBin.push_back(itemID);
                else
                    orangeItemsBin.push_back(itemID);
                break;

            case AHB_YELLOW:
                if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                    yellowTradeGoodsBin.push_back(itemID);
                else
                    yellowItemsBin.push_back(itemID);
                break;
            }
        }

        if ((greyTradeGoodsBin.size() == 0) &&
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
            (yellowItemsBin.size() == 0))
        {
            sLog.outError("AuctionHouseBot: No items");
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

void AuctionHouseBot::IncrementItemCounts(AuctionEntry* ah)
{
    // from auctionhousehandler.cpp, creates auction pointer & player pointer

    // get exact item information
    Item *pItem = auctionmgr.GetAItem(ah->item_guidlow);
    if (!pItem)
    {
        if (debug_Out) sLog.outError("AHBot: Item %u doesn't exist, perhaps bought already?", ah->item_guidlow);
        return;
    }

    // get item prototype
    ItemPrototype const* prototype = objmgr.GetItemPrototype(ah->item_template);

    AHBConfig *config;

    FactionTemplateEntry const* u_entry = sFactionTemplateStore.LookupEntry(ah->GetHouseFaction());
    if (!u_entry)
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Neutral", ah->GetHouseFaction());
        config = &NeutralConfig;
    }
    else if (u_entry->ourMask & FACTION_MASK_ALLIANCE)
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Alliance", ah->GetHouseFaction());
        config = &AllianceConfig;
    }
    else if (u_entry->ourMask & FACTION_MASK_HORDE)
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Horde", ah->GetHouseFaction());
        config = &HordeConfig;
    }
    else
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Neutral", ah->GetHouseFaction());
        config = &NeutralConfig;
    }

    config->IncItemCounts(prototype->Class, prototype->Quality);
}

void AuctionHouseBot::DecrementItemCounts(AuctionEntry* ah, uint32 item_template)
{
    // get item prototype
    ItemPrototype const* prototype = objmgr.GetItemPrototype(item_template);

    AHBConfig *config;

    FactionTemplateEntry const* u_entry = sFactionTemplateStore.LookupEntry(ah->GetHouseFaction());
    if (!u_entry)
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Neutral", ah->GetHouseFaction());
        config = &NeutralConfig;
    }
    else if (u_entry->ourMask & FACTION_MASK_ALLIANCE)
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Alliance", ah->GetHouseFaction());
        config = &AllianceConfig;
    }
    else if (u_entry->ourMask & FACTION_MASK_HORDE)
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Horde", ah->GetHouseFaction());
        config = &HordeConfig;
    }
    else
    {
        if (debug_Out) sLog.outError("AHBot: %u returned as House Faction. Neutral", ah->GetHouseFaction());
        config = &NeutralConfig;
    }

    config->DecItemCounts(prototype->Class, prototype->Quality);
}

void AuctionHouseBot::Commands(uint32 command, uint32 ahMapID, uint32 col, char* args)
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
        }
        break;
    case 1:     //min items
        {
            char * param1 = strtok(args, " ");
            uint32 minItems = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minitems = '%u' WHERE auctionhouse = '%u'", minItems, ahMapID);
            config->SetMinItems(minItems);
        }
        break;
    case 2:     //max items
        {
            char * param1 = strtok(args, " ");
            uint32 maxItems = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxitems = '%u' WHERE auctionhouse = '%u'", maxItems, ahMapID);
            config->SetMaxItems(maxItems);
        }
        break;
    case 3:     //min time Deprecated (Place holder for future commands)
        break;
    case 4:     //max time Deprecated (Place holder for future commands)
        break;
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
        }
        break;
    case 6:     //min prices
        {
            char * param1 = strtok(args, " ");
            uint32 minPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), minPrice, ahMapID);
            config->SetMinPrice(col, minPrice);
        }
        break;
    case 7:     //max prices
        {
            char * param1 = strtok(args, " ");
            uint32 maxPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxPrice, ahMapID);
            config->SetMaxPrice(col, maxPrice);
        }
        break;
    case 8:     //min bid price
        {
            char * param1 = strtok(args, " ");
            uint32 minBidPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET minbidprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), minBidPrice, ahMapID);
            config->SetMinBidPrice(col, minBidPrice);
        }
        break;
    case 9:     //max bid price
        {
            char * param1 = strtok(args, " ");
            uint32 maxBidPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxbidprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxBidPrice, ahMapID);
            config->SetMaxBidPrice(col, maxBidPrice);
        }
        break;
    case 10:        //max stacks
        {
            char * param1 = strtok(args, " ");
            uint32 maxStack = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET maxstack%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), maxStack, ahMapID);
            config->SetMaxStack(col, maxStack);
        }
        break;
    case 11:        //buyer bid prices
        {
            char * param1 = strtok(args, " ");
            uint32 buyerPrice = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET buyerprice%s = '%u' WHERE auctionhouse = '%u'",color.c_str(), buyerPrice, ahMapID);
            config->SetBuyerPrice(col, buyerPrice);
        }
        break;
    case 12:        //buyer bidding interval
        {
            char * param1 = strtok(args, " ");
            uint32 bidInterval = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET buyerbiddinginterval = '%u' WHERE auctionhouse = '%u'", bidInterval, ahMapID);
            config->SetBiddingInterval(bidInterval);
        }
        break;
    case 13:        //buyer bids per interval
        {
            char * param1 = strtok(args, " ");
            uint32 bidsPerInterval = (uint32) strtoul(param1, NULL, 0);
            CharacterDatabase.PExecute("UPDATE auctionhousebot SET buyerbidsperinterval = '%u' WHERE auctionhouse = '%u'", bidsPerInterval, ahMapID);
            config->SetBidsPerInterval(bidsPerInterval);
        }
        break;
    default:
        break;
    }
}

void AuctionHouseBot::LoadValues(AHBConfig *config)
{
    if (debug_Out) sLog.outString("Start Settings for %s Auctionhouses:", CharacterDatabase.PQuery("SELECT name FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetString());
    if (AHBSeller)
    {
        //load min and max items
        config->SetMinItems(CharacterDatabase.PQuery("SELECT minitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxItems(CharacterDatabase.PQuery("SELECT maxitems FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
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
        //load min and max prices
        config->SetMinPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT minpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT maxpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT minpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT maxpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT minpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT maxpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT minpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT maxpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT minpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT maxpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT minpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT maxpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT minpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT maxpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        //load min and max bid prices
        config->SetMinBidPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT minbidpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_GREY, CharacterDatabase.PQuery("SELECT maxbidpricegrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinBidPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT minbidpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_WHITE, CharacterDatabase.PQuery("SELECT maxbidpricewhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinBidPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT minbidpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_GREEN, CharacterDatabase.PQuery("SELECT maxbidpricegreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinBidPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT minbidpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_BLUE, CharacterDatabase.PQuery("SELECT maxbidpriceblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinBidPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT minbidpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_PURPLE, CharacterDatabase.PQuery("SELECT maxbidpricepurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinBidPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT minbidpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_ORANGE, CharacterDatabase.PQuery("SELECT maxbidpriceorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMinBidPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT minbidpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxBidPrice(AHB_YELLOW, CharacterDatabase.PQuery("SELECT maxbidpriceyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        //load max stacks
        config->SetMaxStack(AHB_GREY, CharacterDatabase.PQuery("SELECT maxstackgrey FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxStack(AHB_WHITE, CharacterDatabase.PQuery("SELECT maxstackwhite FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxStack(AHB_GREEN, CharacterDatabase.PQuery("SELECT maxstackgreen FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxStack(AHB_BLUE, CharacterDatabase.PQuery("SELECT maxstackblue FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxStack(AHB_PURPLE, CharacterDatabase.PQuery("SELECT maxstackpurple FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxStack(AHB_ORANGE, CharacterDatabase.PQuery("SELECT maxstackorange FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        config->SetMaxStack(AHB_YELLOW, CharacterDatabase.PQuery("SELECT maxstackyellow FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if (debug_Out)
        {
            sLog.outString("minItems                = %u", config->GetMinItems());
            sLog.outString("maxItems                = %u", config->GetMaxItems());
            sLog.outString("percentGreyTradeGoods   = %u", config->GetPercentages(AHB_GREY_TG));
            sLog.outString("percentWhiteTradeGoods  = %u", config->GetPercentages(AHB_WHITE_TG));
            sLog.outString("percentGreenTradeGoods  = %u", config->GetPercentages(AHB_GREEN_TG));
            sLog.outString("percentBlueTradeGoods   = %u", config->GetPercentages(AHB_BLUE_TG));
            sLog.outString("percentPurpleTradeGoods = %u", config->GetPercentages(AHB_PURPLE_TG));
            sLog.outString("percentOrangeTradeGoods = %u", config->GetPercentages(AHB_ORANGE_TG));
            sLog.outString("percentYellowTradeGoods = %u", config->GetPercentages(AHB_YELLOW_TG));
            sLog.outString("percentGreyItems        = %u", config->GetPercentages(AHB_GREY_I));
            sLog.outString("percentWhiteItems       = %u", config->GetPercentages(AHB_WHITE_I));
            sLog.outString("percentGreenItems       = %u", config->GetPercentages(AHB_GREEN_I));
            sLog.outString("percentBlueItems        = %u", config->GetPercentages(AHB_BLUE_I));
            sLog.outString("percentPurpleItems      = %u", config->GetPercentages(AHB_PURPLE_I));
            sLog.outString("percentOrangeItems      = %u", config->GetPercentages(AHB_ORANGE_I));
            sLog.outString("percentYellowItems      = %u", config->GetPercentages(AHB_YELLOW_I));
            sLog.outString("minPriceGrey            = %u", config->GetMinPrice(AHB_GREY));
            sLog.outString("maxPriceGrey            = %u", config->GetMaxPrice(AHB_GREY));
            sLog.outString("minPriceWhite           = %u", config->GetMinPrice(AHB_WHITE));
            sLog.outString("maxPriceWhite           = %u", config->GetMaxPrice(AHB_WHITE));
            sLog.outString("minPriceGreen           = %u", config->GetMinPrice(AHB_GREEN));
            sLog.outString("maxPriceGreen           = %u", config->GetMaxPrice(AHB_GREEN));
            sLog.outString("minPriceBlue            = %u", config->GetMinPrice(AHB_BLUE));
            sLog.outString("maxPriceBlue            = %u", config->GetMaxPrice(AHB_BLUE));
            sLog.outString("minPricePurple          = %u", config->GetMinPrice(AHB_PURPLE));
            sLog.outString("maxPricePurple          = %u", config->GetMaxPrice(AHB_PURPLE));
            sLog.outString("minPriceOrange          = %u", config->GetMinPrice(AHB_ORANGE));
            sLog.outString("maxPriceOrange          = %u", config->GetMaxPrice(AHB_ORANGE));
            sLog.outString("minPriceYellow          = %u", config->GetMinPrice(AHB_YELLOW));
            sLog.outString("maxPriceYellow          = %u", config->GetMaxPrice(AHB_YELLOW));
            sLog.outString("minBidPriceGrey         = %u", config->GetMinBidPrice(AHB_GREY));
            sLog.outString("maxBidPriceGrey         = %u", config->GetMaxBidPrice(AHB_GREY));
            sLog.outString("minBidPriceWhite        = %u", config->GetMinBidPrice(AHB_WHITE));
            sLog.outString("maxBidPriceWhite        = %u", config->GetMaxBidPrice(AHB_WHITE));
            sLog.outString("minBidPriceGreen        = %u", config->GetMinBidPrice(AHB_GREEN));
            sLog.outString("maxBidPriceGreen        = %u", config->GetMaxBidPrice(AHB_GREEN));
            sLog.outString("minBidPriceBlue         = %u", config->GetMinBidPrice(AHB_BLUE));
            sLog.outString("maxBidPriceBlue         = %u", config->GetMinBidPrice(AHB_BLUE));
            sLog.outString("minBidPricePurple       = %u", config->GetMinBidPrice(AHB_PURPLE));
            sLog.outString("maxBidPricePurple       = %u", config->GetMaxBidPrice(AHB_PURPLE));
            sLog.outString("minBidPriceOrange       = %u", config->GetMinBidPrice(AHB_ORANGE));
            sLog.outString("maxBidPriceOrange       = %u", config->GetMaxBidPrice(AHB_ORANGE));
            sLog.outString("minBidPriceYellow       = %u", config->GetMinBidPrice(AHB_YELLOW));
            sLog.outString("maxBidPriceYellow       = %u", config->GetMaxBidPrice(AHB_YELLOW));
            sLog.outString("maxStackGrey            = %u", config->GetMaxStack(AHB_GREY));
            sLog.outString("maxStackWhite           = %u", config->GetMaxStack(AHB_WHITE));
            sLog.outString("maxStackGreen           = %u", config->GetMaxStack(AHB_GREEN));
            sLog.outString("maxStackBlue            = %u", config->GetMaxStack(AHB_BLUE));
            sLog.outString("maxStackPurple          = %u", config->GetMaxStack(AHB_PURPLE));
            sLog.outString("maxStackOrange          = %u", config->GetMaxStack(AHB_ORANGE));
            sLog.outString("maxStackYellow          = %u", config->GetMaxStack(AHB_YELLOW));
        }
        AuctionHouseEntry const* ahEntry = auctionmgr.GetAuctionHouseEntry(config->GetAHFID());
        AuctionHouseObject* auctionHouse = auctionmgr.GetAuctionsMap(config->GetAHFID());

        config->ResetItemCounts();
        uint32 auctions = auctionHouse->Getcount();

        if (auctions)
        {
            for (AuctionHouseObject::AuctionEntryMap::const_iterator itr = auctionHouse->GetAuctionsBegin(); itr != auctionHouse->GetAuctionsEnd(); ++itr)
            {
                AuctionEntry *Aentry = itr->second;
                Item *item = auctionmgr.GetAItem(Aentry->item_guidlow);
                if (item)
                {
                    ItemPrototype const *prototype = item->GetProto();
                    if (prototype)
                    {
                        switch (prototype->Quality)
                        {
                        case 0:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_GREY_TG);
                            else
                                config->IncItemCounts(AHB_GREY_I);
                            break;
                        case 1:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_WHITE_TG);
                            else
                                config->IncItemCounts(AHB_WHITE_I);
                            break;
                        case 2:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_GREEN_TG);
                            else
                                config->IncItemCounts(AHB_GREEN_I);
                            break;
                        case 3:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_BLUE_TG);
                            else
                                config->IncItemCounts(AHB_BLUE_I);
                            break;
                        case 4:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_PURPLE_TG);
                            else
                                config->IncItemCounts(AHB_PURPLE_I);
                            break;
                        case 5:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_ORANGE_TG);
                            else
                                config->IncItemCounts(AHB_ORANGE_I);
                            break;
                        case 6:
                            if (prototype->Class == ITEM_CLASS_TRADE_GOODS)
                                config->IncItemCounts(AHB_YELLOW_TG);
                            else
                                config->IncItemCounts(AHB_YELLOW_I);
                            break;
                        }
                    }
                }
            }
        }
        if (debug_Out)
        {
            sLog.outString("Current Items in %s Auctionhouses:", CharacterDatabase.PQuery("SELECT name FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetString());
            sLog.outString("Grey Trade Goods\t%u\tGrey Items\t%u", config->GetItemCounts(AHB_GREY_TG), config->GetItemCounts(AHB_GREY_I));
            sLog.outString("White Trade Goods\t%u\tWhite Items\t%u", config->GetItemCounts(AHB_WHITE_TG), config->GetItemCounts(AHB_WHITE_I));
            sLog.outString("Green Trade Goods\t%u\tGreen Items\t%u", config->GetItemCounts(AHB_GREEN_TG), config->GetItemCounts(AHB_GREEN_I));
            sLog.outString("Blue Trade Goods\t%u\tBlue Items\t%u", config->GetItemCounts(AHB_BLUE_TG), config->GetItemCounts(AHB_BLUE_I));
            sLog.outString("Purple Trade Goods\t%u\tPurple Items\t%u", config->GetItemCounts(AHB_PURPLE_TG), config->GetItemCounts(AHB_PURPLE_I));
            sLog.outString("Orange Trade Goods\t%u\tOrange Items\t%u", config->GetItemCounts(AHB_ORANGE_TG), config->GetItemCounts(AHB_ORANGE_I));
            sLog.outString("Yellow Trade Goods\t%u\tYellow Items\t%u", config->GetItemCounts(AHB_YELLOW_TG), config->GetItemCounts(AHB_YELLOW_I));
        }
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
        //load bidding interval
        config->SetBiddingInterval(CharacterDatabase.PQuery("SELECT buyerbiddinginterval FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        //load bids per interval
        config->SetBidsPerInterval(CharacterDatabase.PQuery("SELECT buyerbidsperinterval FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetUInt32());
        if (debug_Out)
        {
            sLog.outString("buyerPriceGrey          = %u", config->GetBuyerPrice(AHB_GREY));
            sLog.outString("buyerPriceWhite         = %u", config->GetBuyerPrice(AHB_WHITE));
            sLog.outString("buyerPriceGreen         = %u", config->GetBuyerPrice(AHB_GREEN));
            sLog.outString("buyerPriceBlue          = %u", config->GetBuyerPrice(AHB_BLUE));
            sLog.outString("buyerPricePurple        = %u", config->GetBuyerPrice(AHB_PURPLE));
            sLog.outString("buyerPriceOrange        = %u", config->GetBuyerPrice(AHB_ORANGE));
            sLog.outString("buyerPriceYellow        = %u", config->GetBuyerPrice(AHB_YELLOW));
            sLog.outString("buyerBiddingInterval    = %u", config->GetBiddingInterval());
            sLog.outString("buyerBidsPerInterval    = %u", config->GetBidsPerInterval());
        }
    }
    if (debug_Out) sLog.outString("End Settings for %s Auctionhouses:", CharacterDatabase.PQuery("SELECT name FROM auctionhousebot WHERE auctionhouse = %u",config->GetAHID())->Fetch()->GetString());
}
