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

#include "BlackMarketMgr.h"
#include "Player.h"
#include "Language.h"

void BlackMarketMgr::LoadTemplates()
{
    uint32 oldMSTime = getMSTime();

    // Clear in case we are reloading
    if (!mTemplates.empty())
    {
        for (BlackMarketTemplateMap::iterator itr = mTemplates.begin(); itr != mTemplates.end(); ++itr)
            delete itr->second;

        mTemplates.clear();
    }

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_BLACKMARKET_TEMPLATE);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 black market templates. DB table `blackmarket_template` is empty.");
        return;
    }

    uint32 count = 0;

    SQLTransaction trans = WorldDatabase.BeginTransaction();
    do
    {
        Field* fields = result->Fetch();
        BlackMarketTemplate* templ = new BlackMarketTemplate;

        if (!templ->LoadFromDB(fields)) // Add checks
        {
            delete templ;
            continue;
        }

        AddTemplate(templ);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u black market templates in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void BlackMarketMgr::LoadAuctions()
{
    uint32 oldMSTime = getMSTime();

    // Clear in case we are reloading
    if (!mAuctions.empty())
    {
        for (BlackMarketEntryMap::iterator itr = mAuctions.begin(); itr != mAuctions.end(); ++itr)
            delete itr->second;

        mAuctions.clear();
    }

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_BLACKMARKET_AUCTIONS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 black market auctions. DB table `blackmarket_auctions` is empty.");
        return;
    }

    uint32 count = 0;
    _LastUpdate = time(nullptr); //Set update time before loading

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    do
    {
        Field* fields = result->Fetch();
        BlackMarketEntry* auction = new BlackMarketEntry;

        if (!auction->LoadFromDB(fields))
        {
            auction->DeleteFromDB(trans);
            delete auction;
            continue;
        }

        if (auction->IsCompleted())
        {
            auction->DeleteFromDB(trans);
            delete auction;
            continue;
        }

        AddAuction(auction);
        ++count;
    } while (result->NextRow());

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("server.loading", ">> Loaded %u black market auctions in %u ms.", count, GetMSTimeDiffToNow(oldMSTime));
}

void BlackMarketMgr::Update(bool updateTime)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    time_t now = time(nullptr);
    for (BlackMarketEntryMap::iterator itr = mAuctions.begin(); itr != mAuctions.end(); ++itr)
    {
        BlackMarketEntry* entry = itr->second;

        if (entry->IsCompleted() && entry->GetBidder())
            SendAuctionWonMail(entry, trans);

        if (updateTime)
            entry->Update(now);
    }

    if (updateTime)
        _LastUpdate = now;

    CharacterDatabase.CommitTransaction(trans);
}

void BlackMarketMgr::RefreshAuctions()
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    // Delete completed auctions
    for (BlackMarketEntryMap::iterator itr = mAuctions.begin(); itr != mAuctions.end();)
    {
        BlackMarketEntry* entry = itr->second;
        if (!entry->IsCompleted())
        {
            ++itr;
            continue;
        }

        entry->DeleteFromDB(trans);
        itr = mAuctions.erase(itr);
        delete entry;
    }

    CharacterDatabase.CommitTransaction(trans);
    trans = CharacterDatabase.BeginTransaction();

    while (mAuctions.size() < sWorld->getIntConfig(CONFIG_BLACKMARKET_MAXAUCTIONS))
    {
        // All possible items exist
        if (mAuctions.size() >= mTemplates.size())
            break;

        BlackMarketTemplateMap::iterator itr = mTemplates.begin();
        std::advance(itr, rand32() % mTemplates.size()); // Get a random auction

        if (!roll_chance_f(itr->second->Chance))
            continue;

        int32 marketId = itr->second->MarketID;
        if (!GetAuctionByID(marketId)) //Check if auction already exists
        {
            BlackMarketEntry* entry = new BlackMarketEntry;
            entry->Initialize(marketId);
            entry->SaveToDB(trans);
            AddAuction(entry);
        }
    }

    CharacterDatabase.CommitTransaction(trans);

    Update(true);
}

bool BlackMarketMgr::IsEnabled() const
{
    return sWorld->getBoolConfig(CONFIG_BLACKMARKET_ENABLED);
}

void BlackMarketMgr::BuildItemsResponse(WorldPackets::BlackMarket::BlackMarketRequestItemsResult &packet, Player *player)
{
    packet.LastUpdateID = _LastUpdate;

    for (BlackMarketEntryMap::iterator itr = mAuctions.begin(); itr != mAuctions.end(); ++itr)
    {
        WorldPackets::BlackMarket::BlackMarketItem item;
        item.Initialize(itr->second, player);

        packet.Items.push_back(item);
    }
}

void BlackMarketMgr::AddAuction(BlackMarketEntry* auction)
{
    mAuctions.insert(std::pair<int32, BlackMarketEntry*>(auction->GetMarketId(), auction));
}

void BlackMarketMgr::AddTemplate(BlackMarketTemplate* templ)
{
    mTemplates.insert(std::pair<int32, BlackMarketTemplate*>(templ->MarketID, templ));
}

void BlackMarketMgr::SendAuctionWonMail(BlackMarketEntry* entry, SQLTransaction& trans)
{
    // Mail already sent
    if (entry->GetMailSent())
        return;

    uint32 bidderAccId = 0;
    ObjectGuid bidderGuid = ObjectGuid::Create<HighGuid::Player>(entry->GetBidder());
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
        bidderAccId = ObjectMgr::GetPlayerAccountIdByGUID(bidderGuid);

        if (!bidderAccId) // Account exists
            return;

        logGmTrade = AccountMgr::HasPermission(bidderAccId, rbac::RBAC_PERM_LOG_GM_TRADE, realmHandle.Index);

        if (logGmTrade && !ObjectMgr::GetPlayerNameByGUID(bidderGuid, bidderName))
            bidderName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);
    }

    // Create item
    BlackMarketTemplate* templ = entry->GetTemplate();
    Item* item = Item::CreateItem(templ->Item.ItemID, templ->Quantity);

    if (!item)
        return;

    if (templ->Item.ItemBonus)
        for (int32 bonusList : templ->Item.ItemBonus->BonusListIDs)
            item->AddBonuses(bonusList);

    item->SetOwnerGUID(bidderGuid);

    item->SaveToDB(trans);

    // Log trade
    if (logGmTrade)
    {
        sLog->outCommand(bidderAccId, "GM %s (Account: %u) won item in blackmarket auction: %s (Entry: %u Count: %u) and payed gold : %u.",
            bidderName.c_str(), bidderAccId, item->GetTemplate()->GetDefaultLocaleName(), item->GetEntry(), item->GetCount(), entry->GetCurrentBid() / GOLD);
    }

    if (bidder)
    {
        bidder->GetSession()->SendBlackMarketWonNotification(entry, item);
    }

    MailDraft(entry->BuildAuctionMailSubject(BMAH_AUCTION_WON), entry->BuildAuctionMailBody())
        .AddItem(item)
        .SendMailTo(trans, MailReceiver(bidder, entry->GetBidder()), entry, MAIL_CHECK_MASK_COPIED);

    entry->MailSent();
}

void BlackMarketMgr::SendAuctionOutbidMail(BlackMarketEntry* entry, SQLTransaction& trans)
{
    ObjectGuid oldBidder_guid = ObjectGuid::Create<HighGuid::Player>(entry->GetBidder());
    Player* oldBidder = ObjectAccessor::FindConnectedPlayer(oldBidder_guid);

    uint32 oldBidder_accId = 0;
    if (!oldBidder)
        oldBidder_accId = ObjectMgr::GetPlayerAccountIdByGUID(oldBidder_guid);

    // old bidder exist
    if (!oldBidder && !oldBidder_accId)
        return;

    if (oldBidder)
        oldBidder->GetSession()->SendBlackMarketOutbidNotification(entry->GetTemplate());

    MailDraft(entry->BuildAuctionMailSubject(BMAH_AUCTION_OUTBID), entry->BuildAuctionMailBody())
        .AddMoney(entry->GetCurrentBid())
        .SendMailTo(trans, MailReceiver(oldBidder, entry->GetBidder()), entry, MAIL_CHECK_MASK_COPIED);
}

BlackMarketEntry* BlackMarketMgr::GetAuctionByID(int32 marketId) const
{
    BlackMarketEntryMap::const_iterator itr = mAuctions.find(marketId);
    if (itr != mAuctions.end())
        return itr->second;

    return nullptr;
}

BlackMarketTemplate* BlackMarketMgr::GetTemplateByID(int32 marketId) const
{
    BlackMarketTemplateMap::const_iterator itr = mTemplates.find(marketId);
    if (itr != mTemplates.end())
        return itr->second;

    return nullptr;
}

bool BlackMarketTemplate::LoadFromDB(Field* fields)
{
    MarketID = fields[0].GetInt32();
    SellerNPC = fields[1].GetInt32();
    Item.ItemID = fields[2].GetUInt32();
    Quantity = fields[3].GetInt32();
    MinBid = fields[4].GetUInt64();
    Duration = static_cast<time_t>(fields[5].GetUInt32());
    Chance = fields[6].GetFloat();

    Tokenizer bonusListIDsTok(fields[7].GetString(), ' ');
    std::vector<int32> bonusListIDs;
    for (char const* token : bonusListIDsTok)
    {
        int32 bonusListID = atol(token);
        bonusListIDs.push_back(bonusListID);
    }

    if (!bonusListIDs.empty())
    {
        Item.ItemBonus = boost::in_place();
        Item.ItemBonus->BonusListIDs = bonusListIDs;
    }

    if (!sObjectMgr->GetCreatureTemplate(SellerNPC))
    {
        TC_LOG_ERROR("misc", "Black market template %i does not have a valid seller. (Entry: %u)", MarketID, SellerNPC);
        return false;
    }

    if (!sObjectMgr->GetItemTemplate(Item.ItemID))
    {
        TC_LOG_ERROR("misc", "Black market template %i does not have a valid item. (Entry: %u)", MarketID, Item.ItemID);
        return false;
    }

    return true;
}

void BlackMarketEntry::Update(time_t newTimeOfUpdate)
{
    _secondsRemaining = _secondsRemaining - (newTimeOfUpdate - sBlackMarketMgr->GetLastUpdate());
}

BlackMarketTemplate* BlackMarketEntry::GetTemplate() const
{
    return sBlackMarketMgr->GetTemplateByID(_marketId);
}

time_t BlackMarketEntry::GetSecondsRemaining() const
{
    return _secondsRemaining - (time(nullptr) - sBlackMarketMgr->GetLastUpdate());
}

time_t BlackMarketEntry::GetExpirationTime() const
{
    return time(nullptr) + GetSecondsRemaining();
}

bool BlackMarketEntry::IsCompleted() const
{
    return GetSecondsRemaining() <= 0;
}

bool BlackMarketEntry::LoadFromDB(Field* fields)
{
    _marketId = fields[0].GetInt32();

    // Invalid MarketID
    BlackMarketTemplate* templ = sBlackMarketMgr->GetTemplateByID(_marketId);
    if (!templ)
    {
        TC_LOG_ERROR("misc", "Black market auction %i does not have a valid id.", _marketId);
        return false;
    }

    _currentBid = fields[1].GetUInt64();
    _secondsRemaining =  static_cast<time_t>(fields[2].GetInt32()) - sBlackMarketMgr->GetLastUpdate();
    _numBids = fields[3].GetInt32();
    _bidder = fields[4].GetUInt64();

    // Either no bidder or existing player
    if (_bidder && !sObjectMgr->GetPlayerAccountIdByGUID(ObjectGuid::Create<HighGuid::Player>(_bidder))) // Probably a better way to check if player exists
    {
        TC_LOG_ERROR("misc", "Black market auction %i does not have a valid bidder (GUID: " UI64FMTD " ).", _marketId, _bidder);
        return false;
    }

    return true;
}

void BlackMarketEntry::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_BLACKMARKET_AUCTIONS);

    stmt->setInt32(0, _marketId);
    stmt->setUInt64(1, _currentBid);
    stmt->setInt32(2, GetExpirationTime());
    stmt->setInt32(3, _numBids);
    stmt->setUInt64(4, _bidder);

    trans->Append(stmt);
}

void BlackMarketEntry::DeleteFromDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_BLACKMARKET_AUCTIONS);
    stmt->setInt32(0, _marketId);
    trans->Append(stmt);
}

bool BlackMarketEntry::ValidateBid(uint64 bid) const
{
    if (bid <= _currentBid)
        return false;

    if (bid < _currentBid + GetMinIncrement())
        return false;

    if (bid >= BMAH_MAX_BID)
        return false;

    return true;
}

void BlackMarketEntry::PlaceBid(uint64 bid, Player* player, SQLTransaction& trans)   //Updated
{
    if (bid < _currentBid)
        return;

    _currentBid = bid;
    ++_numBids;

    if (GetSecondsRemaining() < 30 * MINUTE)
        _secondsRemaining += 30 * MINUTE;

    _bidder = player->GetGUID().GetCounter();

    player->ModifyMoney(-static_cast<int64>(bid));


    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_BLACKMARKET_AUCTIONS);

    stmt->setUInt64(0, _currentBid);
    stmt->setInt32(1, GetExpirationTime());
    stmt->setInt32(2, _numBids);
    stmt->setUInt64(3, _bidder);
    stmt->setInt32(4, _marketId);

    trans->Append(stmt);

    sBlackMarketMgr->Update(true);
}

std::string BlackMarketEntry::BuildAuctionMailSubject(BMAHMailAuctionAnswers response) const
{
    std::ostringstream strm;
    strm << GetTemplate()->Item.ItemID << ":0:" << response << ':' << GetMarketId() << ':' << GetTemplate()->Quantity;
    return strm.str();
}

std::string BlackMarketEntry::BuildAuctionMailBody()
{
    std::ostringstream strm;
    strm << GetTemplate()->SellerNPC << ':' << _currentBid;

    return strm.str();
}

