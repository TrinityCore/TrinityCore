/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AuctionHouseBot.h"
#include "AuctionHouseMgr.h"
#include "AuctionHousePackets.h"
#include "AccountMgr.h"
#include "Bag.h"
#include "DB2Stores.h"
#include "CharacterCache.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
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
#include <sstream>
#include <vector>

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
    else if (uEntry->FactionGroup & FACTION_MASK_ALLIANCE)
        return &mAllianceAuctions;
    else if (uEntry->FactionGroup & FACTION_MASK_HORDE)
        return &mHordeAuctions;
    else
        return &mNeutralAuctions;
}

uint64 AuctionHouseMgr::GetAuctionDeposit(AuctionHouseEntry const* entry, uint32 time, Item* pItem, uint32 count)
{
    uint32 MSV = pItem->GetTemplate()->GetSellPrice();

    if (MSV <= 0)
        return AH_MINIMUM_DEPOSIT * sWorld->getRate(RATE_AUCTION_DEPOSIT);

    float multiplier = CalculatePct(float(entry->DepositRate), 3);
    uint32 timeHr = (((time / 60) / 60) / 12);
    uint64 deposit = uint64(MSV * multiplier * sWorld->getRate(RATE_AUCTION_DEPOSIT));
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
    TC_LOG_DEBUG("auctionHouse", "Deposit:    " UI64FMTD, deposit);
    TC_LOG_DEBUG("auctionHouse", "Deposit rm: %f", remainderbase * count);

    if (deposit < AH_MINIMUM_DEPOSIT * sWorld->getRate(RATE_AUCTION_DEPOSIT))
        return AH_MINIMUM_DEPOSIT * sWorld->getRate(RATE_AUCTION_DEPOSIT);
    else
        return deposit;
}

//does not clear ram
void AuctionHouseMgr::SendAuctionWonMail(AuctionEntry* auction, CharacterDatabaseTransaction& trans)
{
    Item* item = GetAItem(auction->itemGUIDLow);
    if (!item)
        return;

    uint32 bidderAccId = 0;
    ObjectGuid bidderGuid = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
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
        ObjectGuid ownerGuid = ObjectGuid::Create<HighGuid::Player>(auction->owner);
        std::string ownerName;
        if (!sCharacterCache->GetCharacterNameByGuid(ownerGuid, ownerName))
            ownerName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);

        uint32 ownerAccId = sCharacterCache->GetCharacterAccountIdByGuid(ownerGuid);

        sLog->outCommand(bidderAccId, "GM %s (Account: %u) won item in auction: %s (Entry: %u Count: %u) and pay money: " UI64FMTD ". Original owner %s (Account: %u)",
            bidderName.c_str(), bidderAccId, item->GetTemplate()->GetDefaultLocaleName(), item->GetEntry(), item->GetCount(), auction->bid, ownerName.c_str(), ownerAccId);
    }

    // receiver exist
    if ((bidder || bidderAccId) && !sAuctionBotConfig->IsBotChar(auction->bidder))
    {
        // set owner to bidder (to prevent delete item with sender char deleting)
        // owner in `data` will set at mail receive and item extracting
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
        stmt->setUInt64(0, auction->bidder);
        stmt->setUInt64(1, item->GetGUID().GetCounter());
        trans->Append(stmt);

        if (bidder)
        {
            bidder->GetSession()->SendAuctionWonNotification(auction, item);
            // FIXME: for offline player need also
            bidder->UpdateCriteria(CRITERIA_TYPE_WON_AUCTIONS, 1);
        }

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_WON), AuctionEntry::BuildAuctionMailBody(auction->owner, auction->bid, auction->buyout, 0, 0))
            .AddItem(item)
            .SendMailTo(trans, MailReceiver(bidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
    }
    else
    {
        // bidder doesn't exist, delete the item
        sAuctionMgr->RemoveAItem(auction->itemGUIDLow, true);
    }
}

void AuctionHouseMgr::SendAuctionSalePendingMail(AuctionEntry* auction, CharacterDatabaseTransaction& trans)
{
    ObjectGuid owner_guid = ObjectGuid::Create<HighGuid::Player>(auction->owner);
    Player* owner = ObjectAccessor::FindConnectedPlayer(owner_guid);
    uint32 owner_accId = sCharacterCache->GetCharacterAccountIdByGuid(owner_guid);
    // owner exist (online or offline)
    if ((owner || owner_accId) && !sAuctionBotConfig->IsBotChar(auction->owner))
        MailDraft(auction->BuildAuctionMailSubject(AUCTION_SALE_PENDING), AuctionEntry::BuildAuctionMailBody(auction->bidder, auction->bid, auction->buyout, auction->deposit, auction->GetAuctionCut()))
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED);
}

//call this method to send mail to auction owner, when auction is successful, it does not clear ram
void AuctionHouseMgr::SendAuctionSuccessfulMail(AuctionEntry* auction, CharacterDatabaseTransaction& trans)
{
    ObjectGuid owner_guid = ObjectGuid::Create<HighGuid::Player>(auction->owner);
    Player* owner = ObjectAccessor::FindConnectedPlayer(owner_guid);
    uint32 owner_accId = sCharacterCache->GetCharacterAccountIdByGuid(owner_guid);
    Item* item = GetAItem(auction->itemGUIDLow);

    // owner exist
    if ((owner || owner_accId) && !sAuctionBotConfig->IsBotChar(auction->owner))
    {
        uint64 profit = auction->bid + auction->deposit - auction->GetAuctionCut();

        //FIXME: what do if owner offline
        if (owner && item)
        {
            owner->UpdateCriteria(CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS, profit);
            owner->UpdateCriteria(CRITERIA_TYPE_HIGHEST_AUCTION_SOLD, auction->bid);
            //send auction owner notification, bidder must be current!
            owner->GetSession()->SendAuctionClosedNotification(auction, (float)sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY), true, item);
        }

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_SUCCESSFUL), AuctionEntry::BuildAuctionMailBody(auction->bidder, auction->bid, auction->buyout, auction->deposit, auction->GetAuctionCut()))
            .AddMoney(profit)
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED, sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY));
    }
}

//does not clear ram
void AuctionHouseMgr::SendAuctionExpiredMail(AuctionEntry* auction, CharacterDatabaseTransaction& trans)
{
    //return an item in auction to its owner by mail
    Item* item = GetAItem(auction->itemGUIDLow);
    if (!item)
        return;

    ObjectGuid owner_guid = ObjectGuid::Create<HighGuid::Player>(auction->owner);
    Player* owner = ObjectAccessor::FindConnectedPlayer(owner_guid);
    uint32 owner_accId = sCharacterCache->GetCharacterAccountIdByGuid(owner_guid);
    // owner exist
    if ((owner || owner_accId) && !sAuctionBotConfig->IsBotChar(auction->owner))
    {
        if (owner)
            owner->GetSession()->SendAuctionClosedNotification(auction, 0.0f, false, item);

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_EXPIRED), AuctionEntry::BuildAuctionMailBody(0, 0, auction->buyout, auction->deposit, 0))
            .AddItem(item)
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED, 0);
    }
    else
    {
        // owner doesn't exist, delete the item
        sAuctionMgr->RemoveAItem(auction->itemGUIDLow, true);
    }
}

//this function sends mail to old bidder
void AuctionHouseMgr::SendAuctionOutbiddedMail(AuctionEntry* auction, uint64 /*newPrice*/, Player* /*newBidder*/, CharacterDatabaseTransaction& trans)
{
    ObjectGuid oldBidder_guid = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
    Player* oldBidder = ObjectAccessor::FindConnectedPlayer(oldBidder_guid);

    uint32 oldBidder_accId = 0;
    if (!oldBidder)
        oldBidder_accId = sCharacterCache->GetCharacterAccountIdByGuid(oldBidder_guid);

    Item* item = GetAItem(auction->itemGUIDLow);

    // old bidder exist
    if ((oldBidder || oldBidder_accId) && !sAuctionBotConfig->IsBotChar(auction->bidder))
    {
        if (oldBidder && item)
            oldBidder->GetSession()->SendAuctionOutBidNotification(auction, item);

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_OUTBIDDED), AuctionEntry::BuildAuctionMailBody(auction->owner, auction->bid, auction->buyout, auction->deposit, auction->GetAuctionCut()))
            .AddMoney(auction->bid)
            .SendMailTo(trans, MailReceiver(oldBidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
    }
}

//this function sends mail, when auction is cancelled to old bidder
void AuctionHouseMgr::SendAuctionCancelledToBidderMail(AuctionEntry* auction, CharacterDatabaseTransaction& trans)
{
    ObjectGuid bidder_guid = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
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
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_ITEMS);
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

        ObjectGuid::LowType itemGuid = fields[0].GetUInt64();
        uint32 itemEntry = fields[1].GetUInt32();

        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
        if (!proto)
        {
            TC_LOG_ERROR("misc", "AuctionHouseMgr::LoadAuctionItems: Unknown item (GUID: " UI64FMTD " item entry: #%u) in auction, skipped.", itemGuid, itemEntry);
            continue;
        }

        Item* item = NewItemOrBag(proto);
        if (!item->LoadFromDB(itemGuid, ObjectGuid::Empty, fields, itemEntry))
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

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTIONS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 auctions. DB table `auctionhouse` is empty.");
        return;
    }

    uint32 count = 0;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    do
    {
        Field* fields = result->Fetch();

        AuctionEntry* aItem = new AuctionEntry();
        if (!aItem->LoadFromDB(fields))
        {
            aItem->DeleteFromDB(trans);
            delete aItem;
            continue;
        }

        GetAuctionsMap(aItem->factionTemplateId)->AddAuction(aItem);
        ++count;
    } while (result->NextRow());

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("server.loading", ">> Loaded %u auctions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void AuctionHouseMgr::AddAItem(Item* it)
{
    ASSERT(it);
    ASSERT(mAitems.count(it->GetGUID().GetCounter()) == 0);
    mAitems[it->GetGUID().GetCounter()] = it;
}

bool AuctionHouseMgr::RemoveAItem(ObjectGuid::LowType id, bool deleteItem)
{
    ItemMap::iterator i = mAitems.find(id);
    if (i == mAitems.end())
        return false;

    if (deleteItem)
    {
        CharacterDatabaseTransaction trans = CharacterDatabaseTransaction(nullptr);
        i->second->FSetState(ITEM_REMOVED);
        i->second->SaveToDB(trans);
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
        uint64 totalDeposit = 0;
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

uint32 AuctionHouseMgr::PendingAuctionCount(const Player* player) const
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

    uint64 totaldeposit = 0;
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
        CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

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
    player->ModifyMoney(-int64(totaldeposit));
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
            CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
            for (auto AHitr = thisAH->begin(); AHitr != thisAH->end();)
            {
                AuctionEntry* AH = (*AHitr);
                ++AHitr;
                AH->expire_time = time(nullptr);
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

AuctionHouseEntry const* AuctionHouseMgr::GetAuctionHouseEntry(uint32 factionTemplateId, uint32* houseId)
{
    uint32 houseid = 1; // Auction House

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
    {
        // FIXME: found way for proper auctionhouse selection by another way
        // AuctionHouse.dbc have faction field with _player_ factions associated with auction house races.
        // but no easy way convert creature faction to player race faction for specific city
        switch (factionTemplateId)
        {
            case  120: houseid = 7; break; // booty bay, Blackwater Auction House
            case  474: houseid = 7; break; // gadgetzan, Blackwater Auction House
            case  855: houseid = 7; break; // everlook, Blackwater Auction House
            default:                       // default
            {
                FactionTemplateEntry const* u_entry = sFactionTemplateStore.LookupEntry(factionTemplateId);
                if (!u_entry)
                    houseid = 1; // Auction House
                else if (u_entry->FactionGroup & FACTION_MASK_ALLIANCE)
                    houseid = 2; // Alliance Auction House
                else if (u_entry->FactionGroup & FACTION_MASK_HORDE)
                    houseid = 6; // Horde Auction House
                else
                    houseid = 1; // Auction House
                break;
            }
        }
    }

    if (houseId)
        *houseId = houseid;

    return sAuctionHouseStore.LookupEntry(houseid);
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
        if (itr->second.NextAllowedReplication <= curTime)
            itr = GetAllThrottleMap.erase(itr);
        else
            ++itr;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

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

void AuctionHouseObject::BuildListBidderItems(WorldPackets::AuctionHouse::AuctionListBidderItemsResult& packet, Player* player)
{
    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->bidder == player->GetGUID().GetCounter())
            itr->second->BuildAuctionInfo(packet.Items, false);
    }
}

void AuctionHouseObject::BuildListOwnerItems(WorldPackets::AuctionHouse::AuctionListOwnerItemsResult& packet, Player* player)
{
    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->owner == player->GetGUID().GetCounter())
            Aentry->BuildAuctionInfo(packet.Items, false);
    }
}

void AuctionHouseObject::BuildListAuctionItems(WorldPackets::AuctionHouse::AuctionListItemsResult& packet, Player* player,
    std::wstring const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, EnumClassFlag<AuctionHouseFilterMask> filters,
    Optional<AuctionSearchClassFilters> const& classFilters)
{
    time_t curTime = GameTime::GetGameTime();

    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        // Skip expired auctions
        if (Aentry->expire_time < curTime)
            continue;

        Item* item = sAuctionMgr->GetAItem(Aentry->itemGUIDLow);
        if (!item)
            continue;

        ItemTemplate const* proto = item->GetTemplate();
        if (classFilters)
        {
            // if we dont want any class filters, Optional is not initialized
            // if we dont want this class included, SubclassMask is set to FILTER_SKIP_CLASS
            // if we want this class and did not specify and subclasses, its set to FILTER_SKIP_SUBCLASS
            // otherwise full restrictions apply
            if (classFilters->Classes[proto->GetClass()].SubclassMask == AuctionSearchClassFilters::FILTER_SKIP_CLASS)
                continue;

            if (classFilters->Classes[proto->GetClass()].SubclassMask != AuctionSearchClassFilters::FILTER_SKIP_SUBCLASS)
            {
                if (!(classFilters->Classes[proto->GetClass()].SubclassMask & (1 << proto->GetSubClass())))
                    continue;

                if (!(classFilters->Classes[proto->GetClass()].InvTypes[proto->GetSubClass()] & (1 << proto->GetInventoryType())))
                    continue;
            }
        }

        if (!filters.HasFlag(static_cast<AuctionHouseFilterMask>(1 << (proto->GetQuality() + 4))))
            continue;

        if (levelmin != 0 && (item->GetRequiredLevel() < levelmin || (levelmax != 0 && item->GetRequiredLevel() > levelmax)))
            continue;

        if (filters.HasFlag(AuctionHouseFilterMask::UsableOnly) && player->CanUseItem(item) != EQUIP_ERR_OK)
            continue;

        // Allow search by suffix (ie: of the Monkey) or partial name (ie: Monkey)
        // No need to do any of this if no search term was entered
        if (!searchedname.empty())
        {
            std::string name = proto->GetName(player->GetSession()->GetSessionDbcLocale());
            if (name.empty())
                continue;

            // TODO: Generate name using ItemNameDescription

            // Perform the search (with or without suffix)
            if (!Utf8FitTo(name, searchedname))
                continue;
        }

        // Add the item if no search term or if entered search term was found
        if (packet.Items.size() < 50 && packet.TotalCount >= listfrom)
            Aentry->BuildAuctionInfo(packet.Items, true, item);

        ++packet.TotalCount;
    }
}

void AuctionHouseObject::BuildReplicate(WorldPackets::AuctionHouse::AuctionReplicateResponse& auctionReplicateResult, Player* player,
    uint32 global, uint32 cursor, uint32 tombstone, uint32 count)
{
    time_t curTime = GameTime::GetGameTime();

    auto throttleItr = GetAllThrottleMap.find(player->GetGUID());
    if (throttleItr != GetAllThrottleMap.end())
    {
        if (throttleItr->second.Global != global || throttleItr->second.Cursor != cursor || throttleItr->second.Tombstone != tombstone)
            return;

        if (!throttleItr->second.IsReplicationInProgress() && throttleItr->second.NextAllowedReplication > curTime)
            return;
    }
    else
    {
        throttleItr = GetAllThrottleMap.insert({ player->GetGUID(), PlayerGetAllThrottleData{} }).first;
        throttleItr->second.NextAllowedReplication = curTime + sWorld->getIntConfig(CONFIG_AUCTION_GETALL_DELAY);
        throttleItr->second.Global = uint32(curTime);
    }

    if (AuctionsMap.empty() || !count)
        return;

    auto itr = AuctionsMap.upper_bound(cursor);
    for (; itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* auction = itr->second;
        if (auction->expire_time < curTime)
            continue;

        Item* item = sAuctionMgr->GetAItem(auction->itemGUIDLow);
        if (!item)
            continue;

        auction->BuildAuctionInfo(auctionReplicateResult.Items, true, item);
        if (!--count)
            break;
    }

    auctionReplicateResult.ChangeNumberGlobal = throttleItr->second.Global;
    auctionReplicateResult.ChangeNumberCursor = throttleItr->second.Cursor = !auctionReplicateResult.Items.empty() ? auctionReplicateResult.Items.back().AuctionID : 0;
    auctionReplicateResult.ChangeNumberTombstone = throttleItr->second.Tombstone = !count ? AuctionsMap.rbegin()->first : 0;
}

//this function inserts to WorldPacket auction's data
void AuctionEntry::BuildAuctionInfo(std::vector<WorldPackets::AuctionHouse::AuctionItem>& items, bool listAuctionItems, Item* sourceItem /*= nullptr*/) const
{
    Item* item = (sourceItem) ? sourceItem : sAuctionMgr->GetAItem(itemGUIDLow);
    if (!item)
    {
        TC_LOG_ERROR("misc", "AuctionEntry::BuildAuctionInfo: Auction %u has a non-existent item: " UI64FMTD, Id, itemGUIDLow);
        return;
    }

    WorldPackets::AuctionHouse::AuctionItem auctionItem;

    auctionItem.AuctionID = Id;
    auctionItem.Item.emplace();
    auctionItem.Item->Initialize(item);
    auctionItem.BuyoutPrice = buyout;
    auctionItem.CensorBidInfo = false;
    auctionItem.CensorServerSideInfo = listAuctionItems;
    auctionItem.Charges = item->GetSpellCharges();
    auctionItem.Count = item->GetCount();
    auctionItem.DeleteReason = 0; // Always 0 ?
    auctionItem.DurationLeft = (expire_time - time(nullptr)) * IN_MILLISECONDS;
    auctionItem.EndTime = expire_time;
    auctionItem.Flags = 0; // todo
    auctionItem.ItemGuid = item->GetGUID();
    auctionItem.MinBid = startbid;
    auctionItem.Owner = ObjectGuid::Create<HighGuid::Player>(owner);
    auctionItem.OwnerAccountID = ObjectGuid::Create<HighGuid::WowAccount>(sCharacterCache->GetCharacterAccountIdByGuid(auctionItem.Owner));
    auctionItem.MinIncrement = bidder ? GetAuctionOutBid() : 0;
    auctionItem.Bidder = bidder ? ObjectGuid::Create<HighGuid::Player>(bidder) : ObjectGuid::Empty;
    auctionItem.BidAmount = bidder ? bid : 0;

    for (uint8 i = 0; i < MAX_INSPECTED_ENCHANTMENT_SLOT; i++)
    {
        if (!item->GetEnchantmentId((EnchantmentSlot) i))
            continue;

        auctionItem.Enchantments.emplace_back(item->GetEnchantmentId((EnchantmentSlot) i), item->GetEnchantmentDuration((EnchantmentSlot) i), item->GetEnchantmentCharges((EnchantmentSlot) i), i);
    }

    uint8 i = 0;
    for (UF::SocketedGem const& gemData : item->m_itemData->Gems)
    {
        if (gemData.ItemID)
        {
            WorldPackets::Item::ItemGemData gem;
            gem.Slot = i;
            gem.Item.Initialize(&gemData);
            auctionItem.Gems.push_back(gem);
        }
        ++i;
    }

    items.emplace_back(auctionItem);
}

uint64 AuctionEntry::GetAuctionCut() const
{
    int64 cut = int64(CalculatePct(bid, auctionHouseEntry->ConsignmentRate) * sWorld->getRate(RATE_AUCTION_CUT));
    return std::max(cut, int64(0));
}

/// the sum of outbid is (1% from current bid)*5, if bid is very small, it is 1c
uint64 AuctionEntry::GetAuctionOutBid() const
{
    uint64 outbid = CalculatePct(bid, 5);
    return outbid ? outbid : 1;
}

void AuctionEntry::DeleteFromDB(CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION);
    stmt->setUInt32(0, Id);
    trans->Append(stmt);
}

void AuctionEntry::SaveToDB(CharacterDatabaseTransaction& trans) const
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AUCTION);
    stmt->setUInt32(0, Id);
    stmt->setUInt64(1, auctioneer);
    stmt->setUInt64(2, itemGUIDLow);
    stmt->setUInt64(3, owner);
    stmt->setUInt64(4, buyout);
    stmt->setUInt32(5, uint32(expire_time));
    stmt->setUInt64(6, bidder);
    stmt->setUInt64(7, bid);
    stmt->setUInt64(8, startbid);
    stmt->setUInt64(9, deposit);
    trans->Append(stmt);
}

bool AuctionEntry::LoadFromDB(Field* fields)
{
    Id = fields[0].GetUInt32();
    auctioneer = fields[1].GetUInt64();
    itemGUIDLow = fields[2].GetUInt64();
    itemEntry = fields[3].GetUInt32();
    itemCount = fields[4].GetUInt32();
    owner = fields[5].GetUInt64();
    buyout = fields[6].GetUInt64();
    expire_time = fields[7].GetUInt32();
    bidder = fields[8].GetUInt64();
    bid = fields[9].GetUInt64();
    startbid = fields[10].GetUInt64();
    deposit = fields[11].GetUInt64();

    CreatureData const* auctioneerData = sObjectMgr->GetCreatureData(auctioneer);
    if (!auctioneerData)
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing auctioneer (GUID : " UI64FMTD ")", Id, auctioneer);
        return false;
    }

    CreatureTemplate const* auctioneerInfo = sObjectMgr->GetCreatureTemplate(auctioneerData->id);
    if (!auctioneerInfo)
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing auctioneer (GUID : " UI64FMTD " Entry: %u)", Id, auctioneer, auctioneerData->id);
        return false;
    }

    factionTemplateId = auctioneerInfo->faction;
    auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntry(factionTemplateId, &houseId);
    if (!auctionHouseEntry)
    {
        TC_LOG_ERROR("misc", "Auction %u has auctioneer (GUID : " UI64FMTD " Entry: %u) with wrong faction %u", Id, auctioneer, auctioneerData->id, factionTemplateId);
        return false;
    }

    // check if sold item exists for guid
    // and itemEntry in fact (GetAItem will fail if problematic in result check in AuctionHouseMgr::LoadAuctionItems)
    if (!sAuctionMgr->GetAItem(itemGUIDLow))
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing item : " UI64FMTD, Id, itemGUIDLow);
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

std::string AuctionEntry::BuildAuctionMailBody(uint64 lowGuid, uint64 bid, uint64 buyout, uint64 deposit, uint64 cut)
{
    std::ostringstream strm;
    strm.width(16);
    strm << std::right << std::hex << ObjectGuid::Create<HighGuid::Player>(lowGuid);   // HIGHGUID_PLAYER always present, even for empty guids
    strm << std::dec << ':' << bid << ':' << buyout;
    strm << ':' << deposit << ':' << cut;
    return strm.str();
}
