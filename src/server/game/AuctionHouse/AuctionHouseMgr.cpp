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

#include "AuctionHouseMgr.h"
#include "AuctionHouseBot.h"
#include "AccountMgr.h"
#include "Bag.h"
#include "Common.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Realm.h"
#include "ScriptMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

enum eAuctionHouse
{
    AH_MINIMUM_DEPOSIT = 100
};

AuctionHouseMgr::AuctionHouseMgr() { }

AuctionHouseMgr::~AuctionHouseMgr()
{
    for (ItemMap::iterator itr = mAitems.begin(); itr != mAitems.end(); ++itr)
        delete itr->second;
}

AuctionHouseMgr* AuctionHouseMgr::instance()
{
    static AuctionHouseMgr instance;
    return &instance;
}

AuctionHouseObject* AuctionHouseMgr::GetAuctionsMap(uint32 factionTemplateId)
{
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
        return &mNeutralAuctions;

    // teams have linked auction houses
    FactionTemplateEntry const* uEntry = sFactionTemplateStore.LookupEntry(factionTemplateId);
    if (!uEntry)
        return &mNeutralAuctions;
    else if (uEntry->ourMask & FACTION_MASK_ALLIANCE)
        return &mAllianceAuctions;
    else if (uEntry->ourMask & FACTION_MASK_HORDE)
        return &mHordeAuctions;
    else
        return &mNeutralAuctions;
}

AuctionHouseObject* AuctionHouseMgr::GetAuctionsMapByHouseId(uint8 auctionHouseId)
{
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
        return &mNeutralAuctions;

    switch(auctionHouseId)
    {
        case AUCTIONHOUSE_ALLIANCE : return &mAllianceAuctions;
        case AUCTIONHOUSE_HORDE : return &mHordeAuctions;
        default : return &mNeutralAuctions;
    }
}

uint32 AuctionHouseMgr::GetAuctionDeposit(AuctionHouseEntry const* entry, uint32 time, Item* pItem, uint32 count)
{
    uint32 MSV = pItem->GetTemplate()->SellPrice;

    if (MSV <= 0)
        return AH_MINIMUM_DEPOSIT * sWorld->getRate(RATE_AUCTION_DEPOSIT);

    float multiplier = CalculatePct(float(entry->depositPercent), 3);
    uint32 timeHr = (((time / 60) / 60) / 12);
    uint32 deposit = uint32(MSV * multiplier * sWorld->getRate(RATE_AUCTION_DEPOSIT));
    float remainderbase = float(MSV * multiplier * sWorld->getRate(RATE_AUCTION_DEPOSIT)) - deposit;

    deposit *= timeHr * count;

    int i = count;
    while (i > 0 && (remainderbase * i) != uint32(remainderbase * i))
        i--;

    if (i)
        deposit += remainderbase * i * timeHr;

    TC_LOG_DEBUG("auctionHouse", "MSV:        %u", MSV);
    TC_LOG_DEBUG("auctionHouse", "Items:      %u", count);
    TC_LOG_DEBUG("auctionHouse", "Multiplier: %f", multiplier);
    TC_LOG_DEBUG("auctionHouse", "Deposit:    %u", deposit);
    TC_LOG_DEBUG("auctionHouse", "Deposit rm: %f", remainderbase * count);

    if (deposit < AH_MINIMUM_DEPOSIT * sWorld->getRate(RATE_AUCTION_DEPOSIT))
        return AH_MINIMUM_DEPOSIT * sWorld->getRate(RATE_AUCTION_DEPOSIT);
    else
        return deposit;
}

//does not clear ram
void AuctionHouseMgr::SendAuctionWonMail(AuctionEntry* auction, SQLTransaction& trans)
{
    Item* pItem = GetAItem(auction->itemGUIDLow);
    if (!pItem)
        return;

    uint32 bidderAccId = 0;
    ObjectGuid bidderGuid(HighGuid::Player, auction->bidder);
    Player* bidder = ObjectAccessor::FindConnectedPlayer(bidderGuid);
    // data for gm.log
    std::string bidderName;
    bool logGmTrade = false;

    if (bidder)
    {
        bidderAccId = bidder->GetSession()->GetAccountId();
        bidderName = bidder->GetName();
        logGmTrade = bidder->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE);
    }
    else
    {
        bidderAccId = sCharacterCache->GetCharacterAccountIdByGuid(bidderGuid);
        logGmTrade = AccountMgr::HasPermission(bidderAccId, rbac::RBAC_PERM_LOG_GM_TRADE, realm.Id.Realm);

        if (logGmTrade && !sCharacterCache->GetCharacterNameByGuid(bidderGuid, bidderName))
            bidderName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);
    }

    if (logGmTrade)
    {
        ObjectGuid ownerGuid = ObjectGuid(HighGuid::Player, auction->owner);
        std::string ownerName;
        if (!sCharacterCache->GetCharacterNameByGuid(ownerGuid, ownerName))
            ownerName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);

        uint32 ownerAccId = sCharacterCache->GetCharacterAccountIdByGuid(ownerGuid);

        sLog->outCommand(bidderAccId, "GM %s (Account: %u) won item in auction: %s (Entry: %u Count: %u) and pay money: %u. Original owner %s (Account: %u)",
            bidderName.c_str(), bidderAccId, pItem->GetTemplate()->Name1.c_str(), pItem->GetEntry(), pItem->GetCount(), auction->bid, ownerName.c_str(), ownerAccId);
    }

    // receiver exist
    if ((bidder || bidderAccId) && !sAuctionBotConfig->IsBotChar(auction->bidder))
    {
        // set owner to bidder (to prevent delete item with sender char deleting)
        // owner in `data` will set at mail receive and item extracting
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
        stmt->setUInt32(0, auction->bidder);
        stmt->setUInt32(1, pItem->GetGUID().GetCounter());
        trans->Append(stmt);

        if (bidder)
        {
            bidder->GetSession()->SendAuctionBidderNotification(auction->GetHouseId(), auction->Id, bidderGuid, 0, 0, auction->itemEntry);
            // FIXME: for offline player need also
            bidder->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS, 1);
        }

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_WON), AuctionEntry::BuildAuctionMailBody(auction->owner, auction->bid, auction->buyout, 0, 0))
            .AddItem(pItem)
            .SendMailTo(trans, MailReceiver(bidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
    }
    else
    {
        // bidder doesn't exist, delete the item
        sAuctionMgr->RemoveAItem(auction->itemGUIDLow, true, &trans);
    }
}

void AuctionHouseMgr::SendAuctionSalePendingMail(AuctionEntry* auction, SQLTransaction& trans)
{
    ObjectGuid owner_guid(HighGuid::Player, auction->owner);
    Player* owner = ObjectAccessor::FindConnectedPlayer(owner_guid);
    uint32 owner_accId = sCharacterCache->GetCharacterAccountIdByGuid(owner_guid);
    // owner exist (online or offline)
    if ((owner || owner_accId) && !sAuctionBotConfig->IsBotChar(auction->owner))
        MailDraft(auction->BuildAuctionMailSubject(AUCTION_SALE_PENDING), AuctionEntry::BuildAuctionMailBody(auction->bidder, auction->bid, auction->buyout, auction->deposit, auction->GetAuctionCut()))
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED);
}

//call this method to send mail to auction owner, when auction is successful, it does not clear ram
void AuctionHouseMgr::SendAuctionSuccessfulMail(AuctionEntry* auction, SQLTransaction& trans)
{
    ObjectGuid owner_guid(HighGuid::Player, auction->owner);
    Player* owner = ObjectAccessor::FindConnectedPlayer(owner_guid);
    uint32 owner_accId = sCharacterCache->GetCharacterAccountIdByGuid(owner_guid);
    // owner exist
    if ((owner || owner_accId) && !sAuctionBotConfig->IsBotChar(auction->owner))
    {
        uint32 profit = auction->bid + auction->deposit - auction->GetAuctionCut();

        //FIXME: what do if owner offline
        if (owner)
        {
            owner->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS, profit);
            owner->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD, auction->bid);
            //send auction owner notification, bidder must be current!
            owner->GetSession()->SendAuctionOwnerNotification(auction);
        }

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_SUCCESSFUL), AuctionEntry::BuildAuctionMailBody(auction->bidder, auction->bid, auction->buyout, auction->deposit, auction->GetAuctionCut()))
            .AddMoney(profit)
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED, sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY));
    }
}

//does not clear ram
void AuctionHouseMgr::SendAuctionExpiredMail(AuctionEntry* auction, SQLTransaction& trans)
{
    //return an item in auction to its owner by mail
    Item* pItem = GetAItem(auction->itemGUIDLow);
    if (!pItem)
        return;

    ObjectGuid owner_guid(HighGuid::Player, auction->owner);
    Player* owner = ObjectAccessor::FindConnectedPlayer(owner_guid);
    uint32 owner_accId = sCharacterCache->GetCharacterAccountIdByGuid(owner_guid);
    // owner exist
    if ((owner || owner_accId) && !sAuctionBotConfig->IsBotChar(auction->owner))
    {
        if (owner)
            owner->GetSession()->SendAuctionOwnerNotification(auction);

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_EXPIRED), AuctionEntry::BuildAuctionMailBody(0, 0, auction->buyout, auction->deposit, 0))
            .AddItem(pItem)
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED, 0);
    }
    else
    {
        // owner doesn't exist, delete the item
        sAuctionMgr->RemoveAItem(auction->itemGUIDLow, true, &trans);
    }
}

//this function sends mail to old bidder
void AuctionHouseMgr::SendAuctionOutbiddedMail(AuctionEntry* auction, uint32 newPrice, Player* newBidder, SQLTransaction& trans)
{
    ObjectGuid oldBidder_guid(HighGuid::Player, auction->bidder);
    Player* oldBidder = ObjectAccessor::FindConnectedPlayer(oldBidder_guid);

    uint32 oldBidder_accId = 0;
    if (!oldBidder)
        oldBidder_accId = sCharacterCache->GetCharacterAccountIdByGuid(oldBidder_guid);

    // old bidder exist
    if ((oldBidder || oldBidder_accId) && !sAuctionBotConfig->IsBotChar(auction->bidder))
    {
        if (oldBidder && newBidder)
            oldBidder->GetSession()->SendAuctionBidderNotification(auction->GetHouseId(), auction->Id, newBidder->GetGUID(), newPrice, auction->GetAuctionOutBid(), auction->itemEntry);

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_OUTBIDDED), AuctionEntry::BuildAuctionMailBody(auction->owner, auction->bid, auction->buyout, auction->deposit, auction->GetAuctionCut()))
            .AddMoney(auction->bid)
            .SendMailTo(trans, MailReceiver(oldBidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
    }
}

//this function sends mail, when auction is cancelled to old bidder
void AuctionHouseMgr::SendAuctionCancelledToBidderMail(AuctionEntry* auction, SQLTransaction& trans)
{
    ObjectGuid bidder_guid = ObjectGuid(HighGuid::Player, auction->bidder);
    Player* bidder = ObjectAccessor::FindConnectedPlayer(bidder_guid);

    uint32 bidder_accId = 0;
    if (!bidder)
        bidder_accId = sCharacterCache->GetCharacterAccountIdByGuid(bidder_guid);

    // bidder exist
    if ((bidder || bidder_accId) && !sAuctionBotConfig->IsBotChar(auction->bidder))
        MailDraft(auction->BuildAuctionMailSubject(AUCTION_CANCELLED_TO_BIDDER), AuctionEntry::BuildAuctionMailBody(auction->owner, auction->bid, auction->buyout, auction->deposit, 0))
            .AddMoney(auction->bid)
            .SendMailTo(trans, MailReceiver(bidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
}

void AuctionHouseMgr::LoadAuctionItems()
{
    uint32 oldMSTime = getMSTime();

    // need to clear in case we are reloading
    if (!mAitems.empty())
    {
        for (ItemMap::iterator itr = mAitems.begin(); itr != mAitems.end(); ++itr)
            delete itr->second;

        mAitems.clear();
    }

    // data needs to be at first place for Item::LoadFromDB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_ITEMS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 auction items. DB table `auctionhouse` or `item_instance` is empty!");

        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        ObjectGuid::LowType item_guid = fields[11].GetUInt32();
        uint32 itemEntry    = fields[12].GetUInt32();

        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
        if (!proto)
        {
            TC_LOG_ERROR("misc", "AuctionHouseMgr::LoadAuctionItems: Unknown item (GUID: %u item entry: #%u) in auction, skipped.", item_guid, itemEntry);
            continue;
        }

        Item* item = NewItemOrBag(proto);
        if (!item->LoadFromDB(item_guid, ObjectGuid::Empty, fields, itemEntry))
        {
            delete item;
            continue;
        }
        AddAItem(item);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u auction items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void AuctionHouseMgr::LoadAuctions()
{
    uint32 oldMSTime = getMSTime();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTIONS);
    PreparedQueryResult resultAuctions = CharacterDatabase.Query(stmt);

    if (!resultAuctions)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 auctions. DB table `auctionhouse` is empty.");

        return;
    }

    // parse bidder list
    std::unordered_map<uint32, std::unordered_set<ObjectGuid>> biddersByAuction;
    PreparedStatement* stmt2 = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_BIDDERS);

    uint32 countBidders = 0;
    if (PreparedQueryResult resultBidders = CharacterDatabase.Query(stmt2))
    {
        do
        {
            Field* fields = resultBidders->Fetch();
            biddersByAuction[fields[0].GetUInt32()].insert(ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt32()));
            ++countBidders;
        }
        while (resultBidders->NextRow());
    }

    // parse auctions from db
    uint32 countAuctions = 0;
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    do
    {
        Field* fields = resultAuctions->Fetch();

        AuctionEntry* aItem = new AuctionEntry();
        if (!aItem->LoadFromDB(fields))
        {
            aItem->DeleteFromDB(trans);
            delete aItem;
            continue;
        }

        auto it = biddersByAuction.find(aItem->Id);
        if (it != biddersByAuction.end())
            aItem->bidders = std::move(it->second);

        GetAuctionsMapByHouseId(aItem->houseId)->AddAuction(aItem);
        ++countAuctions;
    } while (resultAuctions->NextRow());

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("server.loading", ">> Loaded %u auctions with %u bidders in %u ms", countAuctions, countBidders, GetMSTimeDiffToNow(oldMSTime));
}

void AuctionHouseMgr::AddAItem(Item* it)
{
    ASSERT(it);
    ASSERT(mAitems.find(it->GetGUID().GetCounter()) == mAitems.end());
    mAitems[it->GetGUID().GetCounter()] = it;
}

bool AuctionHouseMgr::RemoveAItem(ObjectGuid::LowType id, bool deleteItem /*= false*/, SQLTransaction* trans /*= nullptr*/)
{
    ItemMap::iterator i = mAitems.find(id);
    if (i == mAitems.end())
        return false;

    if (deleteItem)
    {
        ASSERT(trans);
        i->second->FSetState(ITEM_REMOVED);
        i->second->SaveToDB(*trans);
    }

    mAitems.erase(i);
    return true;
}

bool AuctionHouseMgr::PendingAuctionAdd(Player* player, AuctionEntry* aEntry)
{
    PlayerAuctions* thisAH;
    auto itr = pendingAuctionMap.find(player->GetGUID());
    if (itr != pendingAuctionMap.end())
    {
        thisAH = itr->second.first;

        // Get deposit so far
        uint32 totalDeposit = 0;
        for (AuctionEntry const* thisAuction : *thisAH)
            totalDeposit += thisAuction->deposit;

        // Add this deposit
        totalDeposit += aEntry->deposit;

        if (!player->HasEnoughMoney(totalDeposit))
            return false;
    }
    else
    {
        thisAH = new PlayerAuctions;
        pendingAuctionMap[player->GetGUID()] = AuctionPair(thisAH, 0);
    }
    thisAH->push_back(aEntry);
    return true;
}

uint32 AuctionHouseMgr::PendingAuctionCount(Player const* player) const
{
    auto const itr = pendingAuctionMap.find(player->GetGUID());
    if (itr != pendingAuctionMap.end())
        return itr->second.first->size();

    return 0;
}

void AuctionHouseMgr::PendingAuctionProcess(Player* player)
{
    auto iterMap = pendingAuctionMap.find(player->GetGUID());
    if (iterMap == pendingAuctionMap.end())
        return;

    PlayerAuctions* thisAH = iterMap->second.first;

    uint32 totaldeposit = 0;
    auto itrAH = thisAH->begin();
    for (; itrAH != thisAH->end(); ++itrAH)
    {
        AuctionEntry* AH = (*itrAH);
        if (!player->HasEnoughMoney(totaldeposit + AH->deposit))
            break;

        totaldeposit += AH->deposit;
    }

    // expire auctions we cannot afford
    if (itrAH != thisAH->end())
    {
        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        do
        {
            AuctionEntry* AH = (*itrAH);
            AH->expire_time = GameTime::GetGameTime();
            AH->DeleteFromDB(trans);
            AH->SaveToDB(trans);
            ++itrAH;
        } while (itrAH != thisAH->end());

        CharacterDatabase.CommitTransaction(trans);
    }

    pendingAuctionMap.erase(player->GetGUID());
    delete thisAH;
    player->ModifyMoney(-int32(totaldeposit));
}

void AuctionHouseMgr::UpdatePendingAuctions()
{
    for (auto itr = pendingAuctionMap.begin(); itr != pendingAuctionMap.end();)
    {
        ObjectGuid playerGUID = itr->first;
        if (Player* player = ObjectAccessor::FindConnectedPlayer(playerGUID))
        {
            // Check if there were auctions since last update process if not
            if (PendingAuctionCount(player) == itr->second.second)
            {
                ++itr;
                PendingAuctionProcess(player);
            }
            else
            {
                ++itr;
                pendingAuctionMap[playerGUID].second = PendingAuctionCount(player);
            }
        }
        else
        {
            // Expire any auctions that we couldn't get a deposit for
            TC_LOG_WARN("auctionHouse", "Player %s was offline, unable to retrieve deposit!", playerGUID.ToString().c_str());
            PlayerAuctions* thisAH = itr->second.first;
            ++itr;
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            for (auto AHitr = thisAH->begin(); AHitr != thisAH->end();)
            {
                AuctionEntry* AH = (*AHitr);
                ++AHitr;
                AH->expire_time = GameTime::GetGameTime();
                AH->DeleteFromDB(trans);
                AH->SaveToDB(trans);
            }
            CharacterDatabase.CommitTransaction(trans);
            pendingAuctionMap.erase(playerGUID);
            delete thisAH;
        }
    }
}

void AuctionHouseMgr::Update()
{
    mHordeAuctions.Update();
    mAllianceAuctions.Update();
    mNeutralAuctions.Update();
}

AuctionHouseEntry const* AuctionHouseMgr::GetAuctionHouseEntry(uint32 factionTemplateId)
{
    uint32 houseid = AUCTIONHOUSE_NEUTRAL; // goblin auction house

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        // FIXME: found way for proper auctionhouse selection by another way
        // AuctionHouse.dbc have faction field with _player_ factions associated with auction house races.
        // but no easy way convert creature faction to player race faction for specific city
        FactionTemplateEntry const* u_entry = sFactionTemplateStore.LookupEntry(factionTemplateId);
        if (!u_entry)
            houseid = AUCTIONHOUSE_NEUTRAL; // goblin auction house
        else if (u_entry->ourMask & FACTION_MASK_ALLIANCE)
            houseid = AUCTIONHOUSE_ALLIANCE; // human auction house
        else if (u_entry->ourMask & FACTION_MASK_HORDE)
            houseid = AUCTIONHOUSE_HORDE; // orc auction house
        else
            houseid = AUCTIONHOUSE_NEUTRAL; // goblin auction house
    }

    return sAuctionHouseStore.LookupEntry(houseid);
}

AuctionHouseEntry const* AuctionHouseMgr::GetAuctionHouseEntryFromHouse(uint8 houseId)
{
    return (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION)) ? sAuctionHouseStore.LookupEntry(AUCTIONHOUSE_NEUTRAL) : sAuctionHouseStore.LookupEntry(houseId);
}

void AuctionHouseObject::AddAuction(AuctionEntry* auction)
{
    ASSERT(auction);

    AuctionsMap[auction->Id] = auction;
    sScriptMgr->OnAuctionAdd(this, auction);
}

bool AuctionHouseObject::RemoveAuction(AuctionEntry* auction)
{
    bool wasInMap = AuctionsMap.erase(auction->Id) ? true : false;

    sScriptMgr->OnAuctionRemove(this, auction);

    // we need to delete the entry, it is not referenced any more
    delete auction;
    return wasInMap;
}

void AuctionHouseObject::Update()
{
    time_t curTime = GameTime::GetGameTime();
    ///- Handle expired auctions

    // If storage is empty, no need to update. next == NULL in this case.
    if (AuctionsMap.empty())
        return;

    // Clear expired throttled players
    for (PlayerGetAllThrottleMap::const_iterator itr = GetAllThrottleMap.begin(); itr != GetAllThrottleMap.end();)
    {
        if (itr->second <= curTime)
            itr = GetAllThrottleMap.erase(itr);
        else
            ++itr;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    for (AuctionEntryMap::iterator it = AuctionsMap.begin(); it != AuctionsMap.end();)
    {
        // from auctionhousehandler.cpp, creates auction pointer & player pointer
        AuctionEntry* auction = it->second;
        // Increment iterator due to AuctionEntry deletion
        ++it;

        ///- filter auctions expired on next update
        if (auction->expire_time > curTime + 60)
            continue;

        ///- Either cancel the auction if there was no bidder
        if (auction->bidder == 0 && auction->bid == 0)
        {
            sAuctionMgr->SendAuctionExpiredMail(auction, trans);
            sScriptMgr->OnAuctionExpire(this, auction);
        }
        ///- Or perform the transaction
        else
        {
            //we should send an "item sold" message if the seller is online
            //we send the item to the winner
            //we send the money to the seller
            sAuctionMgr->SendAuctionSuccessfulMail(auction, trans);
            sAuctionMgr->SendAuctionWonMail(auction, trans);
            sScriptMgr->OnAuctionSuccessful(this, auction);
        }

        ///- In any case clear the auction
        auction->DeleteFromDB(trans);

        sAuctionMgr->RemoveAItem(auction->itemGUIDLow);
        RemoveAuction(auction);
    }

    // Run DB changes
    CharacterDatabase.CommitTransaction(trans);
}

void AuctionHouseObject::BuildListBidderItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount)
{
    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->bidders.find(player->GetGUID()) != Aentry->bidders.end())
        {
            if (itr->second->BuildAuctionInfo(data))
                ++count;

            ++totalcount;
        }
    }
}

void AuctionHouseObject::BuildListOwnerItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount)
{
    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->owner == player->GetGUID().GetCounter())
        {
            if (Aentry->BuildAuctionInfo(data))
                ++count;

            ++totalcount;
        }
    }
}

void AuctionHouseObject::BuildListAuctionItems(WorldPacket& data, Player* player,
    std::wstring const& wsearchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
    uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
    uint32& count, uint32& totalcount, bool getall)
{
    LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
    int locdbc_idx = player->GetSession()->GetSessionDbcLocale();

    time_t curTime = GameTime::GetGameTime();

    auto itr = GetAllThrottleMap.find(player->GetGUID());
    time_t throttleTime = itr != GetAllThrottleMap.end() ? itr->second : curTime;

    if (getall && throttleTime <= curTime)
    {
        for (AuctionEntryMap::const_iterator it = AuctionsMap.begin(); it != AuctionsMap.end(); ++it)
        {
            AuctionEntry* Aentry = it->second;
            // Skip expired auctions
            if (Aentry->expire_time < curTime)
                continue;

            Item* item = sAuctionMgr->GetAItem(Aentry->itemGUIDLow);
            if (!item)
                continue;

            ++count;
            ++totalcount;
            Aentry->BuildAuctionInfo(data, item);

            if (count >= MAX_GETALL_RETURN)
                break;
        }
        GetAllThrottleMap[player->GetGUID()] = curTime + sWorld->getIntConfig(CONFIG_AUCTION_GETALL_DELAY);
        return;
    }

    for (AuctionEntryMap::const_iterator it = AuctionsMap.begin(); it != AuctionsMap.end(); ++it)
    {
        AuctionEntry* Aentry = it->second;
        // Skip expired auctions
        if (Aentry->expire_time < curTime)
            continue;

        Item* item = sAuctionMgr->GetAItem(Aentry->itemGUIDLow);
        if (!item)
            continue;

        ItemTemplate const* proto = item->GetTemplate();

        if (itemClass != 0xffffffff && proto->Class != itemClass)
            continue;

        if (itemSubClass != 0xffffffff && proto->SubClass != itemSubClass)
            continue;

        if (inventoryType != 0xffffffff && proto->InventoryType != inventoryType)
            continue;

        if (quality != 0xffffffff && proto->Quality != quality)
            continue;

        if (levelmin != 0x00 && (proto->RequiredLevel < levelmin || (levelmax != 0x00 && proto->RequiredLevel > levelmax)))
            continue;

        if (usable != 0x00 && player->CanUseItem(item) != EQUIP_ERR_OK)
            continue;

        // Allow search by suffix (ie: of the Monkey) or partial name (ie: Monkey)
        // No need to do any of this if no search term was entered
        if (!wsearchedname.empty())
        {
            std::string name = proto->Name1;
            if (name.empty())
                continue;

            // local name
            if (localeConstant != LOCALE_enUS)
                if (ItemLocale const* il = sObjectMgr->GetItemLocale(proto->ItemId))
                    ObjectMgr::GetLocaleString(il->Name, localeConstant, name);

            // DO NOT use GetItemEnchantMod(proto->RandomProperty) as it may return a result
            //  that matches the search but it may not equal item->GetItemRandomPropertyId()
            //  used in BuildAuctionInfo() which then causes wrong items to be listed
            int32 propRefID = item->GetItemRandomPropertyId();

            if (propRefID)
            {
                // Append the suffix to the name (ie: of the Monkey) if one exists
                // These are found in ItemRandomSuffix.dbc and ItemRandomProperties.dbc
                //  even though the DBC names seem misleading

                char* const* suffix = nullptr;

                if (propRefID < 0)
                {
                    ItemRandomSuffixEntry const* itemRandSuffix = sItemRandomSuffixStore.LookupEntry(-propRefID);
                    if (itemRandSuffix)
                        suffix = itemRandSuffix->nameSuffix;
                }
                else
                {
                    ItemRandomPropertiesEntry const* itemRandProp = sItemRandomPropertiesStore.LookupEntry(propRefID);
                    if (itemRandProp)
                        suffix = itemRandProp->nameSuffix;
                }

                // dbc local name
                if (suffix)
                {
                    // Append the suffix (ie: of the Monkey) to the name using localization
                    // or default enUS if localization is invalid
                    name += ' ';
                    name += suffix[locdbc_idx >= 0 ? locdbc_idx : LOCALE_enUS];
                }
            }

            // Perform the search (with or without suffix)
            if (!Utf8FitTo(name, wsearchedname))
                continue;
        }

        // Add the item if no search term or if entered search term was found
        if (count < 50 && totalcount >= listfrom)
        {
            ++count;
            Aentry->BuildAuctionInfo(data, item);
        }
        ++totalcount;
    }
}

//this function inserts to WorldPacket auction's data
bool AuctionEntry::BuildAuctionInfo(WorldPacket& data, Item* sourceItem) const
{
    Item* item = (sourceItem) ? sourceItem : sAuctionMgr->GetAItem(itemGUIDLow);
    if (!item)
    {
        TC_LOG_ERROR("misc", "AuctionEntry::BuildAuctionInfo: Auction %u has a non-existent item: %u", Id, itemGUIDLow);
        return false;
    }
    data << uint32(Id);
    data << uint32(item->GetEntry());

    for (uint8 i = 0; i < MAX_INSPECTED_ENCHANTMENT_SLOT; ++i)
    {
        data << uint32(item->GetEnchantmentId(EnchantmentSlot(i)));
        data << uint32(item->GetEnchantmentDuration(EnchantmentSlot(i)));
        data << uint32(item->GetEnchantmentCharges(EnchantmentSlot(i)));
    }

    data << int32(item->GetItemRandomPropertyId());                 // Random item property id
    data << uint32(item->GetItemSuffixFactor());                    // SuffixFactor
    data << uint32(item->GetCount());                               // item->count
    data << uint32(item->GetSpellCharges());                        // item->charge FFFFFFF
    data << uint32(0);                                              // Unknown
    data << uint64(owner);                                          // Auction->owner
    data << uint32(startbid);                                       // Auction->startbid (not sure if useful)
    data << uint32(bid ? GetAuctionOutBid() : 0);
    // Minimal outbid
    data << uint32(buyout);                                         // Auction->buyout
    data << uint32((expire_time - GameTime::GetGameTime()) * IN_MILLISECONDS);   // time left
    data << uint64(bidder);                                         // auction->bidder current
    data << uint32(bid);                                            // current bid
    return true;
}

uint32 AuctionEntry::GetAuctionCut() const
{
    int32 cut = int32(CalculatePct(bid, auctionHouseEntry->cutPercent) * sWorld->getRate(RATE_AUCTION_CUT));
    return std::max(cut, 0);
}

/// the sum of outbid is (1% from current bid)*5, if bid is very small, it is 1c
uint32 AuctionEntry::GetAuctionOutBid() const
{
    uint32 outbid = CalculatePct(bid, 5);
    return outbid ? outbid : 1;
}

void AuctionEntry::DeleteFromDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt;

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION);
    stmt->setUInt32(0, Id);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION_BIDDERS);
    stmt->setUInt32(0, Id);
    trans->Append(stmt);
}

void AuctionEntry::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AUCTION);
    stmt->setUInt32(0, Id);
    stmt->setUInt8(1, houseId);
    stmt->setUInt32(2, itemGUIDLow);
    stmt->setUInt32(3, owner);
    stmt->setUInt32(4, buyout);
    stmt->setUInt32(5, uint32(expire_time));
    stmt->setUInt32(6, bidder);
    stmt->setUInt32(7, bid);
    stmt->setUInt32(8, startbid);
    stmt->setUInt32(9, deposit);
    trans->Append(stmt);
}

bool AuctionEntry::LoadFromDB(Field* fields)
{
    Id = fields[0].GetUInt32();
    houseId = fields[1].GetUInt8();
    itemGUIDLow = fields[2].GetUInt32();
    itemEntry = fields[3].GetUInt32();
    itemCount = fields[4].GetUInt32();
    owner = fields[5].GetUInt32();
    buyout = fields[6].GetUInt32();
    expire_time = fields[7].GetUInt32();
    bidder = fields[8].GetUInt32();
    bid = fields[9].GetUInt32();
    startbid = fields[10].GetUInt32();
    deposit = fields[11].GetUInt32();

    auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntryFromHouse(houseId);
    if (!auctionHouseEntry)
    {
        TC_LOG_ERROR("misc", "Auction %u has invalid house id %u", Id, houseId);
        return false;
    }

    // check if sold item exists for guid
    // and itemEntry in fact (GetAItem will fail if problematic in result check in AuctionHouseMgr::LoadAuctionItems)
    if (!sAuctionMgr->GetAItem(itemGUIDLow))
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing item : %u", Id, itemGUIDLow);
        return false;
    }

    return true;
}
std::string AuctionEntry::BuildAuctionMailSubject(MailAuctionAnswers response) const
{
    std::ostringstream strm;
    strm << itemEntry << ":0:" << response << ':' << Id << ':' << itemCount;
    return strm.str();
}

std::string AuctionEntry::BuildAuctionMailBody(ObjectGuid::LowType lowGuid, uint32 bid, uint32 buyout, uint32 deposit, uint32 cut)
{
    std::ostringstream strm;
    strm.width(16);
    strm << std::right << std::hex << ObjectGuid(HighGuid::Player, lowGuid).GetRawValue();   // HighGuid::Player always present, even for empty guids
    strm << std::dec << ':' << bid << ':' << buyout;
    strm << ':' << deposit << ':' << cut;
    return strm.str();
}
