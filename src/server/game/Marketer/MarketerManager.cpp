#include "MarketerManager.h"
#include "JokerManager.h"
#include "GameTime.h"

MarketerManager::MarketerManager()
{
    buyerCheckDelay = 2 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS;
    sellerCheckDelay = 3 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS;

    auctionHouseIDSet.clear();
    auctionHouseIDSet.insert(AuctionHouses::AUCTIONHOUSE_ALLIANCE);
    auctionHouseIDSet.insert(AuctionHouses::AUCTIONHOUSE_HORDE);
    auctionHouseIDSet.insert(AuctionHouses::AUCTIONHOUSE_NEUTRAL);

    vendorUnlimitItemSet.clear();
    QueryResult vendorItemQR = WorldDatabase.Query("SELECT distinct item FROM npc_vendor where maxcount = 0");
    if (vendorItemQR)
    {
        do
        {
            Field* fields = vendorItemQR->Fetch();
            uint32 eachItemEntry = fields[0].GetUInt32();
            vendorUnlimitItemSet.insert(eachItemEntry);
        } while (vendorItemQR->NextRow());
    }

    sellingItemIDMap.clear();
    ItemTemplateContainer const& its = sObjectMgr->GetItemTemplateStore();
    for (auto const& itemTemplatePair : its)
    {
        const ItemTemplate* proto = &itemTemplatePair.second;
        if (!proto)
        {
            continue;
        }
        if (sJokerConfig->Enable)
        {
            if (proto->Class != ItemClass::ITEM_CLASS_GLYPH)
            {
                bool foundInExp = false;
                for (std::unordered_map<uint32, std::unordered_set<uint32>>::iterator expIT = sJokerManager->expansionItemMap.begin(); expIT != sJokerManager->expansionItemMap.end(); expIT++)
                {
                    if (expIT->first <= sJokerConfig->ServerExpansion)
                    {
                        if (expIT->second.find(itemTemplatePair.first) != expIT->second.end())
                        {
                            foundInExp = true;
                            break;
                        }
                    }
                }
                if (!foundInExp)
                {
                    continue;
                }
            }
        }
        if (proto->ItemLevel < 1)
        {
            continue;
        }
        if (proto->Quality < 1)
        {
            continue;
        }
        if (proto->Quality > 4)
        {
            continue;
        }
        if (proto->Bonding != ItemBondingType::NO_BIND && proto->Bonding != ItemBondingType::BIND_WHEN_EQUIPED && proto->Bonding != ItemBondingType::BIND_WHEN_USE)
        {
            continue;
        }
        if (proto->SellPrice == 0 && proto->BuyPrice == 0)
        {
            continue;
        }
        if (vendorUnlimitItemSet.find(proto->ItemId) != vendorUnlimitItemSet.end())
        {
            continue;
        }
        bool sellThis = false;
        switch (proto->Class)
        {
        case ItemClass::ITEM_CLASS_CONSUMABLE:
        {
            sellThis = true;
            break;
        }
        case ItemClass::ITEM_CLASS_CONTAINER:
        {
            if (proto->Quality >= 2)
            {
                sellThis = true;
            }
            break;
        }
        case ItemClass::ITEM_CLASS_WEAPON:
        {
            if (proto->Quality >= 2)
            {
                sellThis = true;
            }
            break;
        }
        case ItemClass::ITEM_CLASS_GEM:
        {
            sellThis = true;
            break;
        }
        case ItemClass::ITEM_CLASS_ARMOR:
        {
            if (proto->Quality >= 2)
            {
                sellThis = true;
            }
            break;
        }
        case ItemClass::ITEM_CLASS_REAGENT:
        {
            sellThis = true;
            break;
        }
        case ItemClass::ITEM_CLASS_PROJECTILE:
        {
            break;
        }
        case ItemClass::ITEM_CLASS_TRADE_GOODS:
        {
            sellThis = true;
            break;
        }
        case ItemClass::ITEM_CLASS_GENERIC:
        {
            break;
        }
        case ItemClass::ITEM_CLASS_RECIPE:
        {
            sellThis = true;
            break;
        }
        case ItemClass::ITEM_CLASS_MONEY:
        {
            break;
        }
        case ItemClass::ITEM_CLASS_QUIVER:
        {
            if (proto->Quality >= 2)
            {
                sellThis = true;
            }
            break;
        }
        case ItemClass::ITEM_CLASS_QUEST:
        {
            sellThis = true;
            break;
        }
        case ItemClass::ITEM_CLASS_KEY:
        {
            break;
        }
        case ItemClass::ITEM_CLASS_PERMANENT:
        {
            break;
        }
        case ItemClass::ITEM_CLASS_MISC:
        {
            if (proto->Quality > 0)
            {
                sellThis = true;
            }
            break;
        }
        case ItemClass::ITEM_CLASS_GLYPH:
        {
            sellThis = true;
            break;
        }
        default:
        {
            break;
        }
        }
        if (sellThis)
        {
            sellingItemIDMap[sellingItemIDMap.size()] = proto->ItemId;
        }
    }
    sellingIndex = 0;
    selling = false;
}

MarketerManager* MarketerManager::instance()
{
    static MarketerManager instance;
    return &instance;
}

void MarketerManager::ResetMarketer()
{
    if (!sMarketerConfig->Reset)
    {
        return;
    }
    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Ready to reset marketer seller");

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    for (std::set<uint32>::iterator ahIDIT = auctionHouseIDSet.begin(); ahIDIT != auctionHouseIDSet.end(); ahIDIT++)
    {
        uint32 ahID = *ahIDIT;
        AuctionHouseEntry const* ahEntry = sAuctionHouseStore.LookupEntry(*ahIDIT);
        AuctionHouseObject* aho = sAuctionMgr->GetAuctionsMapByHouseId(ahID);
        if (!aho)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "AuctionHouseObject is null");
            return;
        }
        std::set<uint32> auctionIDSet;
        auctionIDSet.clear();
        for (std::map<uint32, AuctionEntry*>::iterator aeIT = aho->GetAuctionsBegin(); aeIT != aho->GetAuctionsEnd(); aeIT++)
        {
            auctionIDSet.insert(aeIT->first);
        }
        for (std::set<uint32>::iterator auctionIDIT = auctionIDSet.begin(); auctionIDIT != auctionIDSet.end(); auctionIDIT++)
        {
            AuctionEntry* eachAE = aho->GetAuction(*auctionIDIT);
            if (eachAE)
            {
                if (eachAE->owner == 0)
                {
                    uint32 itemEntry = eachAE->itemEntry;
                    sAuctionMgr->RemoveAItem(eachAE->itemGUIDLow, true, &trans);
                    aho->RemoveAuction(eachAE);
                    eachAE->DeleteFromDB(trans);
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Auction %d removed for auctionhouse %d", itemEntry, ahID);
                }
            }
        }
    }

    CharacterDatabase.CommitTransaction(trans);

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Marketer seller reset");
}

bool MarketerManager::UpdateMarketer(uint32 pmDiff)
{
    if (!sMarketerConfig->Enable)
    {
        return false;
    }
    sellerCheckDelay -= pmDiff;
    if (sellerCheckDelay < 0)
    {
        UpdateSeller();
    }
    if (sMarketerConfig->Buying)
    {
        buyerCheckDelay -= pmDiff;
        if (buyerCheckDelay < 0)
        {
            UpdateBuyer();
        }
    }

    return true;
}

bool MarketerManager::UpdateSeller()
{
    if (selling)
    {
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

        int checkTotalSellCount = 0;
        int maxSellCount = 100;
        while (checkTotalSellCount < maxSellCount)
        {
            if (sellingIndex < sellingItemIDMap.size())
            {
                int itemEntry = sellingItemIDMap[sellingIndex];
                const ItemTemplate* proto = sObjectMgr->GetItemTemplate(itemEntry);
                if (!proto)
                {
                    sellingIndex++;
                    continue;
                }

                bool sellThis = false;
                uint32 stackCount = 1;
                uint32 baseMultiple = urand(5, 10);
                switch (proto->Class)
                {
                case ItemClass::ITEM_CLASS_CONSUMABLE:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_CONTAINER:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_WEAPON:
                {
                    if (proto->Quality > 1)
                    {
                        sellThis = true;
                        stackCount = proto->Stackable;
                    }
                    break;
                }
                case ItemClass::ITEM_CLASS_GEM:
                {
                    sellThis = true;
                    stackCount = proto->Stackable;
                    break;
                }
                case ItemClass::ITEM_CLASS_ARMOR:
                {
                    if (proto->Quality > 1)
                    {
                        sellThis = true;
                        stackCount = proto->Stackable;
                    }
                    break;
                }
                case ItemClass::ITEM_CLASS_REAGENT:
                {
                    sellThis = true;
                    stackCount = proto->Stackable;
                    break;
                }
                case ItemClass::ITEM_CLASS_PROJECTILE:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_TRADE_GOODS:
                {
                    sellThis = true;
                    stackCount = proto->Stackable;
                    baseMultiple = urand(10, 15);
                    break;
                }
                case ItemClass::ITEM_CLASS_GENERIC:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_RECIPE:
                {
                    sellThis = true;
                    stackCount = 1;
                    break;
                }
                case ItemClass::ITEM_CLASS_MONEY:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_QUIVER:
                {
                    if (proto->Quality > 1)
                    {
                        sellThis = true;
                        stackCount = proto->Stackable;
                    }
                    break;
                }
                case ItemClass::ITEM_CLASS_QUEST:
                {
                    sellThis = true;
                    stackCount = 1;
                    if (proto->Stackable > 20)
                    {
                        stackCount = proto->Stackable;
                    }
                    break;
                }
                case ItemClass::ITEM_CLASS_KEY:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_PERMANENT:
                {
                    break;
                }
                case ItemClass::ITEM_CLASS_MISC:
                {
                    if (proto->Quality > 0)
                    {
                        sellThis = true;
                        stackCount = proto->Stackable;
                    }
                    break;
                }
                case ItemClass::ITEM_CLASS_GLYPH:
                {
                    sellThis = true;
                    stackCount = 1;
                    break;
                }
                default:
                {
                    break;
                }
                }
                if (!sellThis)
                {
                    sellingIndex++;
                    continue;
                }
                for (std::set<uint32>::iterator ahIDIT = auctionHouseIDSet.begin(); ahIDIT != auctionHouseIDSet.end(); ahIDIT++)
                {
                    uint32 ahID = *ahIDIT;
                    AuctionHouseEntry const* ahEntry = sAuctionHouseStore.LookupEntry(*ahIDIT);
                    AuctionHouseObject* aho = sAuctionMgr->GetAuctionsMapByHouseId(ahID);
                    if (!aho)
                    {
                        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "AuctionHouseObject is null");
                        return false;
                    }

                    Item* item = Item::CreateItem(proto->ItemId, stackCount, NULL);
                    if (item)
                    {
                        if (int32 randomPropertyId = item->GetItemRandomPropertyId())
                        {
                            item->SetItemRandomProperties(randomPropertyId);
                        }
                        uint32 finalPrice = 0;
                        uint8 qualityMuliplier = 1;
                        if (proto->Quality > 3)
                        {
                            qualityMuliplier = 2;
                        }
                        finalPrice = proto->SellPrice * stackCount * baseMultiple;
                        if (finalPrice == 0)
                        {
                            finalPrice = proto->BuyPrice * stackCount * baseMultiple / 4;
                        }
                        if (finalPrice == 0)
                        {
                            break;
                        }
                        finalPrice = finalPrice * qualityMuliplier;
                        if (finalPrice > 100)
                        {
                            uint32 dep = sAuctionMgr->GetAuctionDeposit(ahEntry, 86400, item, item->GetCount());

                            AuctionEntry* auctionEntry = new AuctionEntry();
                            auctionEntry->Id = sObjectMgr->GenerateAuctionID();
                            auctionEntry->owner = 0;
                            auctionEntry->itemGUIDLow = item->GetGUID().GetCounter();
                            auctionEntry->itemEntry = item->GetEntry();
                            auctionEntry->startbid = finalPrice / 2;
                            auctionEntry->buyout = finalPrice;
                            auctionEntry->houseId = ahID;
                            auctionEntry->bidder = 0;
                            auctionEntry->bid = 0;
                            auctionEntry->deposit = dep;
                            auctionEntry->auctionHouseEntry = ahEntry;
                            //auctionEntry->depositTime = time(NULL);
                            auctionEntry->expire_time = GameTime::GetGameTime() + sMarketerConfig->ExpireTime;
                            item->SaveToDB(trans);
                            sAuctionMgr->AddAItem(item);
                            aho->AddAuction(auctionEntry);
                            auctionEntry->SaveToDB(trans);

                            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Auction %s added for auctionhouse %d", proto->Name1, ahID);
                        }
                    }
                }

                sellingIndex++;
            }
            else
            {
                sellingIndex = 0;
                selling = false;
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Marketer selling finished");
                break;
            }
            checkTotalSellCount++;
        }
        sellerCheckDelay = IN_MILLISECONDS;

        CharacterDatabase.CommitTransaction(trans);
    }
    else if (MarketEmpty())
    {
        sellingIndex = 0;
        selling = true;
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Marketer start selling");
    }
    else
    {
        sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Marketer is not empty");
        sellerCheckDelay = 2 * HOUR * IN_MILLISECONDS;
    }

    return true;
}

bool MarketerManager::MarketEmpty()
{
    for (std::set<uint32>::iterator ahIDIT = auctionHouseIDSet.begin(); ahIDIT != auctionHouseIDSet.end(); ahIDIT++)
    {
        uint32 ahID = *ahIDIT;
        AuctionHouseEntry const* ahEntry = sAuctionHouseStore.LookupEntry(*ahIDIT);
        AuctionHouseObject* aho = sAuctionMgr->GetAuctionsMapByHouseId(ahID);
        if (!aho)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "AuctionHouseObject is null");
            return false;
        }
        for (std::map<uint32, AuctionEntry*>::iterator aeIT = aho->GetAuctionsBegin(); aeIT != aho->GetAuctionsEnd(); aeIT++)
        {
            Item* checkItem = sAuctionMgr->GetAItem(aeIT->second->itemGUIDLow);
            if (!checkItem)
            {
                continue;
            }
            if (aeIT->second->owner == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool MarketerManager::UpdateBuyer()
{
    buyerCheckDelay = HOUR * IN_MILLISECONDS;
    // EJ debug 
    //buyerCheckDelay = 60000;

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Ready to update marketer buyer");

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    std::set<uint32> toBuyAuctionIDSet;
    for (std::set<uint32>::iterator ahIDIT = auctionHouseIDSet.begin(); ahIDIT != auctionHouseIDSet.end(); ahIDIT++)
    {
        uint32 ahID = *ahIDIT;
        AuctionHouseObject* aho = sAuctionMgr->GetAuctionsMapByHouseId(ahID);
        if (!aho)
        {
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "AuctionHouseObject is null");
            return false;
        }
        toBuyAuctionIDSet.clear();
        for (std::map<uint32, AuctionEntry*>::iterator aeIT = aho->GetAuctionsBegin(); aeIT != aho->GetAuctionsEnd(); aeIT++)
        {
            Item* checkItem = sAuctionMgr->GetAItem(aeIT->second->itemGUIDLow);
            if (!checkItem)
            {
                continue;
            }
            if (aeIT->second->owner == 0)
            {
                continue;
            }
            const ItemTemplate* destIT = sObjectMgr->GetItemTemplate(aeIT->second->itemEntry);
            if (destIT->SellPrice == 0 && destIT->BuyPrice == 0)
            {
                continue;
            }
            if (destIT->Quality < 1)
            {
                continue;
            }
            if (destIT->Quality > 4)
            {
                continue;
            }
            if (vendorUnlimitItemSet.find(aeIT->second->itemEntry) != vendorUnlimitItemSet.end())
            {
                continue;
            }
            uint8 buyThis = 1;
            uint32 baseMultiple = 5;
            if (!destIT)
            {
                continue;
            }
            switch (destIT->Class)
            {
            case ItemClass::ITEM_CLASS_CONSUMABLE:
            {
                buyThis = urand(0, 5);
                break;
            }
            case ItemClass::ITEM_CLASS_CONTAINER:
            {
                if (destIT->Quality > 2)
                {
                    buyThis = 0;
                }
                else if (destIT->Quality == 2)
                {
                    buyThis = urand(0, 5);
                }
                break;
            }
            case ItemClass::ITEM_CLASS_WEAPON:
            {
                if (destIT->Quality > 2)
                {
                    buyThis = 0;
                }
                else if (destIT->Quality == 2)
                {
                    buyThis = urand(0, 5);
                }
                break;
            }
            case ItemClass::ITEM_CLASS_GEM:
            {
                buyThis = 0;
                break;
            }
            case ItemClass::ITEM_CLASS_ARMOR:
            {
                if (destIT->Quality > 2)
                {
                    buyThis = 0;
                }
                else if (destIT->Quality == 2)
                {
                    buyThis = urand(0, 5);
                }
                break;
            }
            case ItemClass::ITEM_CLASS_REAGENT:
            {
                buyThis = urand(0, 5);
                break;
            }
            case ItemClass::ITEM_CLASS_PROJECTILE:
            {
                buyThis = urand(0, 10);
                break;
            }
            case ItemClass::ITEM_CLASS_TRADE_GOODS:
            {
                buyThis = 0;
                baseMultiple = 10;
                break;
            }
            case ItemClass::ITEM_CLASS_GENERIC:
            {
                break;
            }
            case ItemClass::ITEM_CLASS_RECIPE:
            {
                buyThis = 0;
                break;
            }
            case ItemClass::ITEM_CLASS_MONEY:
            {
                break;
            }
            case ItemClass::ITEM_CLASS_QUIVER:
            {
                if (destIT->Quality > 2)
                {
                    buyThis = 0;
                }
                else if (destIT->Quality == 2)
                {
                    buyThis = urand(0, 5);
                }
                break;
            }
            case ItemClass::ITEM_CLASS_QUEST:
            {
                buyThis = urand(0, 5);
                break;
            }
            case ItemClass::ITEM_CLASS_KEY:
            {
                break;
            }
            case ItemClass::ITEM_CLASS_PERMANENT:
            {
                break;
            }
            case ItemClass::ITEM_CLASS_GLYPH:
            {
                buyThis = 0;
            }
            default:
            {
                break;
            }
            }
            if (buyThis != 0)
            {
                continue;
            }
            uint32 basePrice = 0;
            uint32 maxAcceptPrice = 0;
            uint8 qualityMuliplier = 1;
            if (destIT->Quality > 3)
            {
                qualityMuliplier = 2;
            }
            uint32 finalPrice = 0;
            if (destIT->SellPrice > 0)
            {
                finalPrice = destIT->SellPrice * checkItem->GetCount();
            }
            else
            {
                finalPrice = destIT->BuyPrice * checkItem->GetCount();

            }
            finalPrice = finalPrice * qualityMuliplier * baseMultiple;
            uint32 buyRate = aeIT->second->buyout * 10 / finalPrice;
            if (aeIT->second->buyout > finalPrice)
            {
                buyRate = buyRate * buyRate;
            }
            if (urand(0, buyRate) == 0)
            {
                toBuyAuctionIDSet.insert(aeIT->first);
            }
        }

        for (std::set<uint32>::iterator toBuyIT = toBuyAuctionIDSet.begin(); toBuyIT != toBuyAuctionIDSet.end(); toBuyIT++)
        {
            AuctionEntry* destAE = aho->GetAuction(*toBuyIT);
            if (destAE)
            {
                destAE->bid = destAE->buyout;
                // Mails must be under transaction control too to prevent data loss
                sAuctionMgr->SendAuctionSalePendingMail(destAE, trans);
                sAuctionMgr->SendAuctionSuccessfulMail(destAE, trans);
                sAuctionMgr->SendAuctionWonMail(destAE, trans);
                // Delete auction from DB
                destAE->DeleteFromDB(trans);
                // Remove auction item and auction from memory
                sAuctionMgr->RemoveAItem(destAE->itemGUIDLow);
                aho->RemoveAuction(destAE);
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Auction %d was bought by marketer buyer", *toBuyIT);
            }
        }
    }

    CharacterDatabase.CommitTransaction(trans);

    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Marketer buyer updated");
    return true;
}
