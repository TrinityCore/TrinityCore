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

#include "WorldSession.h"
#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "AuctionHousePackets.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Mail.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"

//void called when player click on auctioneer npc
void WorldSession::HandleAuctionHelloOpcode(WorldPackets::AuctionHouse::AuctionHelloRequest& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Guid, UNIT_NPC_FLAG_AUCTIONEER);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionHelloOpcode - Unit (%s) not found or you can't interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendAuctionHello(packet.Guid, unit);
}

//this void causes that auction window is opened
void WorldSession::SendAuctionHello(ObjectGuid guid, Creature* unit)
{
    if (GetPlayer()->getLevel() < sWorld->getIntConfig(CONFIG_AUCTION_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_AUCTION_REQ), sWorld->getIntConfig(CONFIG_AUCTION_LEVEL_REQ));
        return;
    }

    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->getFaction(), nullptr);
    if (!ahEntry)
        return;

    WorldPackets::AuctionHouse::AuctionHelloResponse auctionHelloResponse;
    auctionHelloResponse.Guid = guid;
    auctionHelloResponse.OpenForBusiness = true;                         // 3.3.3: 1 - AH enabled, 0 - AH disabled
    SendPacket(auctionHelloResponse.Write());
}

void WorldSession::SendAuctionCommandResult(AuctionEntry* auction, uint32 action, uint32 errorCode, uint32 /*bidError = 0*/)
{
    WorldPackets::AuctionHouse::AuctionCommandResult auctionCommandResult;
    auctionCommandResult.InitializeAuction(auction);
    auctionCommandResult.Command = action;
    auctionCommandResult.ErrorCode = errorCode;
    SendPacket(auctionCommandResult.Write());
}

void WorldSession::SendAuctionOutBidNotification(AuctionEntry const* auction, Item const* item)
{
    WorldPackets::AuctionHouse::AuctionOutBidNotification packet;
    packet.BidAmount = auction->bid;
    packet.MinIncrement = auction->GetAuctionOutBid();
    packet.Info.Initialize(auction, item);
    SendPacket(packet.Write());
}

void WorldSession::SendAuctionClosedNotification(AuctionEntry const* auction, float mailDelay, bool sold, Item const* item)
{
    WorldPackets::AuctionHouse::AuctionClosedNotification packet;
    packet.Info.Initialize(auction, item);
    packet.ProceedsMailDelay = mailDelay;
    packet.Sold = sold;
    SendPacket(packet.Write());
}

void WorldSession::SendAuctionWonNotification(AuctionEntry const* auction, Item const* item)
{
    WorldPackets::AuctionHouse::AuctionWonNotification packet;
    packet.Info.Initialize(auction, item);
    SendPacket(packet.Write());
}

void WorldSession::SendAuctionOwnerBidNotification(AuctionEntry const* auction, Item const* item)
{
    WorldPackets::AuctionHouse::AuctionOwnerBidNotification packet;
    packet.Info.Initialize(auction, item);
    packet.Bidder = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
    packet.MinIncrement = auction->GetAuctionOutBid();
    SendPacket(packet.Write());
}

//this void creates new auction and adds auction to some auctionhouse
void WorldSession::HandleAuctionSellItem(WorldPackets::AuctionHouse::AuctionSellItem& packet)
{
    for (auto const& item : packet.Items)
        if (!item.Guid || !item.UseCount || item.UseCount > 1000)
            return;

    if (!packet.MinBid || !packet.RunTime)
        return;

    if (packet.MinBid > MAX_MONEY_AMOUNT || packet.BuyoutPrice > MAX_MONEY_AMOUNT)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Player %s (%s) attempted to sell item with higher price than max gold amount.", _player->GetName().c_str(), _player->GetGUID().ToString().c_str());
        SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
        return;
    }


    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Unit (%s) not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    uint32 houseId = 0;
    AuctionHouseEntry const* auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntry(creature->getFaction(), &houseId);
    if (!auctionHouseEntry)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Unit (%s) has wrong faction.", packet.Auctioneer.ToString().c_str());
        return;
    }

    packet.RunTime *= MINUTE;

    switch (packet.RunTime)
    {
        case 1 * MIN_AUCTION_TIME:
        case 2 * MIN_AUCTION_TIME:
        case 4 * MIN_AUCTION_TIME:
            break;
        default:
            return;
    }

    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    uint32 finalCount = 0;
    std::array<Item*, decltype(packet.Items)::max_capacity::value> items;
    items.fill(nullptr);
    for (std::size_t i = 0; i < packet.Items.size(); ++i)
    {
        items[i] = _player->GetItemByGuid(packet.Items[i].Guid);

        if (!items[i])
        {
            SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_ITEM_NOT_FOUND);
            return;
        }

        if (sAuctionMgr->GetAItem(items[i]->GetGUID().GetCounter()) || !items[i]->CanBeTraded() || items[i]->IsNotEmptyBag() ||
            items[i]->GetTemplate()->GetFlags() & ITEM_FLAG_CONJURED || items[i]->GetUInt32Value(ITEM_FIELD_DURATION) ||
            items[i]->GetCount() < packet.Items[i].UseCount)
        {
            SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
            return;
        }

        finalCount += packet.Items[i].UseCount;
    }

    if (packet.Items.empty())
    {
        SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
        return;
    }

    if (!finalCount)
    {
        SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
        return;
    }

    // check if there are 2 identical guids, in this case user is most likely cheating
    for (std::size_t i = 0; i < packet.Items.size() - 1; ++i)
    {
        for (std::size_t j = i + 1; j < packet.Items.size(); ++j)
        {
            if (packet.Items[i].Guid == packet.Items[j].Guid)
            {
                SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
                return;
            }
            if (items[i]->GetEntry() != items[j]->GetEntry())
            {
                SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_ITEM_NOT_FOUND);
                return;
            }
        }
    }

    for (std::size_t i = 0; i < packet.Items.size(); ++i)
    {
        if (items[i]->GetMaxStackCount() < finalCount)
        {
            SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
            return;
        }
    }

    Item* item = items[0];

    uint32 auctionTime = uint32(packet.RunTime * sWorld->getRate(RATE_AUCTION_TIME));
    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    uint64 deposit = sAuctionMgr->GetAuctionDeposit(auctionHouseEntry, packet.RunTime, item, finalCount);
    if (!_player->HasEnoughMoney(deposit))
    {
        SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_NOT_ENOUGHT_MONEY);
        return;
    }

    AuctionEntry* AH = new AuctionEntry();

    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
        AH->auctioneer = UI64LIT(23442);     ///@TODO - HARDCODED DB GUID, BAD BAD BAD
    else
        AH->auctioneer = packet.Auctioneer.GetCounter();

    // Required stack size of auction matches to current item stack size, just move item to auctionhouse
    if (packet.Items.size() == 1 && item->GetCount() == packet.Items[0].UseCount)
    {
        if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
        {
            sLog->outCommand(GetAccountId(), "GM %s (Account: %u) create auction: %s (Entry: %u Count: %u)",
                GetPlayerName().c_str(), GetAccountId(), item->GetTemplate()->GetDefaultLocaleName(), item->GetEntry(), item->GetCount());
        }

        AH->Id = sObjectMgr->GenerateAuctionID();
        AH->itemGUIDLow = item->GetGUID().GetCounter();
        AH->itemEntry = item->GetEntry();
        AH->itemCount = item->GetCount();
        AH->owner = _player->GetGUID().GetCounter();
        AH->startbid = packet.MinBid;
        AH->bidder = UI64LIT(0);
        AH->bid = 0;
        AH->buyout = packet.BuyoutPrice;
        AH->expire_time = time(NULL) + auctionTime;
        AH->deposit = deposit;
        AH->etime = packet.RunTime;
        AH->auctionHouseEntry = auctionHouseEntry;

        TC_LOG_INFO("network", "CMSG_AUCTION_SELL_ITEM: %s %s is selling item %s %s to auctioneer " UI64FMTD " with count %u with initial bid " UI64FMTD " with buyout " UI64FMTD " and with time %u (in sec) in auctionhouse %u",
            _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), item->GetGUID().ToString().c_str(), item->GetTemplate()->GetDefaultLocaleName(), AH->auctioneer, item->GetCount(), packet.MinBid, packet.BuyoutPrice, auctionTime, AH->GetHouseId());
        sAuctionMgr->AddAItem(item);
        auctionHouse->AddAuction(AH);
        sAuctionMgr->PendingAuctionAdd(_player, AH);

        _player->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        item->DeleteFromInventoryDB(trans);
        item->SaveToDB(trans);

        AH->SaveToDB(trans);
        _player->SaveInventoryAndGoldToDB(trans);
        CharacterDatabase.CommitTransaction(trans);

        SendAuctionCommandResult(AH, AUCTION_SELL_ITEM, ERR_AUCTION_OK);

        GetPlayer()->UpdateCriteria(CRITERIA_TYPE_CREATE_AUCTION, 1);
    }
    else // Required stack size of auction does not match to current item stack size, clone item and set correct stack size
    {
        Item* newItem = item->CloneItem(finalCount, _player);
        if (!newItem)
        {
            TC_LOG_ERROR("network", "CMSG_AUCTION_SELL_ITEM: Could not create clone of item %u", item->GetEntry());
            SendAuctionCommandResult(NULL, AUCTION_SELL_ITEM, ERR_AUCTION_DATABASE_ERROR);
            delete AH;
            return;
        }

        if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
        {
            sLog->outCommand(GetAccountId(), "GM %s (Account: %u) create auction: %s (Entry: %u Count: %u)",
                GetPlayerName().c_str(), GetAccountId(), newItem->GetTemplate()->GetDefaultLocaleName(), newItem->GetEntry(), newItem->GetCount());
        }

        AH->Id = sObjectMgr->GenerateAuctionID();
        AH->itemGUIDLow = newItem->GetGUID().GetCounter();
        AH->itemEntry = newItem->GetEntry();
        AH->itemCount = newItem->GetCount();
        AH->owner = _player->GetGUID().GetCounter();
        AH->startbid = packet.MinBid;
        AH->bidder = UI64LIT(0);
        AH->bid = 0;
        AH->buyout = packet.BuyoutPrice;
        AH->expire_time = time(NULL) + auctionTime;
        AH->deposit = deposit;
        AH->etime = packet.RunTime;
        AH->auctionHouseEntry = auctionHouseEntry;

        TC_LOG_INFO("network", "CMSG_AUCTION_SELL_ITEM: %s %s is selling %s %s to auctioneer " UI64FMTD " with count %u with initial bid " UI64FMTD " with buyout " UI64FMTD " and with time %u (in sec) in auctionhouse %u",
            _player->GetGUID().ToString().c_str(), _player->GetName().c_str(), newItem->GetGUID().ToString().c_str(), newItem->GetTemplate()->GetDefaultLocaleName(), AH->auctioneer, newItem->GetCount(), packet.MinBid, packet.BuyoutPrice, auctionTime, AH->GetHouseId());
        sAuctionMgr->AddAItem(newItem);
        auctionHouse->AddAuction(AH);
        sAuctionMgr->PendingAuctionAdd(_player, AH);

        for (std::size_t i = 0; i < packet.Items.size(); ++i)
        {
            Item* item2 = items[i];

            // Item stack count equals required count, ready to delete item - cloned item will be used for auction
            if (item2->GetCount() == packet.Items[i].UseCount)
            {
                _player->MoveItemFromInventory(item2->GetBagSlot(), item2->GetSlot(), true);

                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                item2->DeleteFromInventoryDB(trans);
                item2->DeleteFromDB(trans);
                CharacterDatabase.CommitTransaction(trans);
                delete item2;
            }
            else // Item stack count is bigger than required count, update item stack count and save to database - cloned item will be used for auction
            {
                item2->SetCount(item2->GetCount() - packet.Items[i].UseCount);
                item2->SetState(ITEM_CHANGED, _player);
                _player->ItemRemovedQuestCheck(item2->GetEntry(), packet.Items[i].UseCount);
                item2->SendUpdateToPlayer(_player);

                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                item2->SaveToDB(trans);
                CharacterDatabase.CommitTransaction(trans);
            }
        }

        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        newItem->SaveToDB(trans);
        AH->SaveToDB(trans);
        _player->SaveInventoryAndGoldToDB(trans);
        CharacterDatabase.CommitTransaction(trans);

        SendAuctionCommandResult(AH, AUCTION_SELL_ITEM, ERR_AUCTION_OK);

        GetPlayer()->UpdateCriteria(CRITERIA_TYPE_CREATE_AUCTION, 1);
    }
}

// this function is called when client bids or buys out auction
void WorldSession::HandleAuctionPlaceBid(WorldPackets::AuctionHouse::AuctionPlaceBid& packet)
{
    if (!packet.AuctionItemID || !packet.BidAmount)
        return; // check for cheaters

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionPlaceBid - %s not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    AuctionEntry* auction = auctionHouse->GetAuction(packet.AuctionItemID);
    Player* player = GetPlayer();

    if (!auction || auction->owner == player->GetGUID().GetCounter())
    {
        //you cannot bid your own auction:
        SendAuctionCommandResult(NULL, AUCTION_PLACE_BID, ERR_AUCTION_BID_OWN);
        return;
    }

    // impossible have online own another character (use this for speedup check in case online owner)
    ObjectGuid ownerGuid = ObjectGuid::Create<HighGuid::Player>(auction->owner);
    Player* auction_owner = ObjectAccessor::FindPlayer(ownerGuid);
    if (!auction_owner && ObjectMgr::GetPlayerAccountIdByGUID(ownerGuid) == player->GetSession()->GetAccountId())
    {
        //you cannot bid your another character auction:
        SendAuctionCommandResult(NULL, AUCTION_PLACE_BID, ERR_AUCTION_BID_OWN);
        return;
    }

    // cheating
    if (packet.BidAmount <= auction->bid || packet.BidAmount < auction->startbid)
        return;

    // price too low for next bid if not buyout
    if ((packet.BidAmount < auction->buyout || auction->buyout == 0) &&
        packet.BidAmount < auction->bid + auction->GetAuctionOutBid())
    {
        // client already test it but just in case ...
        SendAuctionCommandResult(auction, AUCTION_PLACE_BID, ERR_AUCTION_HIGHER_BID);
        return;
    }

    if (!player->HasEnoughMoney(packet.BidAmount))
    {
        // client already test it but just in case ...
        SendAuctionCommandResult(auction, AUCTION_PLACE_BID, ERR_AUCTION_NOT_ENOUGHT_MONEY);
        return;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    if (packet.BidAmount < auction->buyout || auction->buyout == 0)
    {
        if (auction->bidder)
        {
            if (auction->bidder == player->GetGUID().GetCounter())
                player->ModifyMoney(-int64(packet.BidAmount - auction->bid));
            else
            {
                // mail to last bidder and return money
                sAuctionMgr->SendAuctionOutbiddedMail(auction, packet.BidAmount, GetPlayer(), trans);
                player->ModifyMoney(-int64(packet.BidAmount));
            }
        }
        else
            player->ModifyMoney(-int64(packet.BidAmount));

        auction->bidder = player->GetGUID().GetCounter();
        auction->bid = packet.BidAmount;
        GetPlayer()->UpdateCriteria(CRITERIA_TYPE_HIGHEST_AUCTION_BID, packet.BidAmount);

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AUCTION_BID);
        stmt->setUInt64(0, auction->bidder);
        stmt->setUInt64(1, auction->bid);
        stmt->setUInt32(2, auction->Id);
        trans->Append(stmt);

        SendAuctionCommandResult(auction, AUCTION_PLACE_BID, ERR_AUCTION_OK);

        // Not sure if we must send this now.
        Player* owner = ObjectAccessor::FindConnectedPlayer(ObjectGuid::Create<HighGuid::Player>(auction->owner));
        Item* item = sAuctionMgr->GetAItem(auction->itemGUIDLow);
        if (owner && item)
            owner->GetSession()->SendAuctionOwnerBidNotification(auction, item);
    }
    else
    {
        //buyout:
        if (player->GetGUID().GetCounter() == auction->bidder)
            player->ModifyMoney(-int64(auction->buyout - auction->bid));
        else
        {
            player->ModifyMoney(-int64(auction->buyout));
            if (auction->bidder)                          //buyout for bidded auction ..
                sAuctionMgr->SendAuctionOutbiddedMail(auction, auction->buyout, GetPlayer(), trans);
        }
        auction->bidder = player->GetGUID().GetCounter();
        auction->bid = auction->buyout;
        GetPlayer()->UpdateCriteria(CRITERIA_TYPE_HIGHEST_AUCTION_BID, auction->buyout);

        SendAuctionCommandResult(auction, AUCTION_PLACE_BID, ERR_AUCTION_OK);

        //- Mails must be under transaction control too to prevent data loss
        sAuctionMgr->SendAuctionSalePendingMail(auction, trans);
        sAuctionMgr->SendAuctionSuccessfulMail(auction, trans);
        sAuctionMgr->SendAuctionWonMail(auction, trans);

        auction->DeleteFromDB(trans);

        sAuctionMgr->RemoveAItem(auction->itemGUIDLow);
        auctionHouse->RemoveAuction(auction);
    }

    player->SaveInventoryAndGoldToDB(trans);
    CharacterDatabase.CommitTransaction(trans);
}

//this void is called when auction_owner cancels his auction
void WorldSession::HandleAuctionRemoveItem(WorldPackets::AuctionHouse::AuctionRemoveItem& packet)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionRemoveItem - %s not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    AuctionEntry* auction = auctionHouse->GetAuction(packet.AuctionItemID);
    Player* player = GetPlayer();

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    if (auction && auction->owner == player->GetGUID().GetCounter())
    {
        Item* item = sAuctionMgr->GetAItem(auction->itemGUIDLow);
        if (item)
        {
            if (auction->bidder)                            // If we have a bidder, we have to send him the money he paid
            {
                uint64 auctionCut = auction->GetAuctionCut();
                if (!player->HasEnoughMoney(auctionCut))          //player doesn't have enough money, maybe message needed
                    return;
                sAuctionMgr->SendAuctionCancelledToBidderMail(auction, trans);
                player->ModifyMoney(-int64(auctionCut));
            }

            // item will deleted or added to received mail list
            MailDraft(auction->BuildAuctionMailSubject(AUCTION_CANCELED), AuctionEntry::BuildAuctionMailBody(0, 0, auction->buyout, auction->deposit, 0))
                .AddItem(item)
                .SendMailTo(trans, player, auction, MAIL_CHECK_MASK_COPIED);
        }
        else
        {
            TC_LOG_ERROR("network", "Auction id: %u got non existing item (item guid : " UI64FMTD ")!", auction->Id, auction->itemGUIDLow);
            SendAuctionCommandResult(NULL, AUCTION_CANCEL, ERR_AUCTION_DATABASE_ERROR);
            return;
        }
    }
    else
    {
        SendAuctionCommandResult(NULL, AUCTION_CANCEL, ERR_AUCTION_DATABASE_ERROR);
        //this code isn't possible ... maybe there should be assert
        TC_LOG_ERROR("entities.player.cheat", "CHEATER: %s tried to cancel auction (id: %u) of another player or auction is NULL", player->GetGUID().ToString().c_str(), packet.AuctionItemID);
        return;
    }

    //inform player, that auction is removed
    SendAuctionCommandResult(auction, AUCTION_CANCEL, ERR_AUCTION_OK);

    // Now remove the auction

    player->SaveInventoryAndGoldToDB(trans);
    auction->DeleteFromDB(trans);
    CharacterDatabase.CommitTransaction(trans);

    sAuctionMgr->RemoveAItem(auction->itemGUIDLow);
    auctionHouse->RemoveAuction(auction);
}

//called when player lists his bids
void WorldSession::HandleAuctionListBidderItems(WorldPackets::AuctionHouse::AuctionListBidderItems& packet)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListBidderItems - %s not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    WorldPackets::AuctionHouse::AuctionListBidderItemsResult result;

    Player* player = GetPlayer();
    auctionHouse->BuildListBidderItems(result, player, result.TotalCount);
    result.DesiredDelay = 300;
    SendPacket(result.Write());
}

//this void sends player info about his auctions
void WorldSession::HandleAuctionListOwnerItems(WorldPackets::AuctionHouse::AuctionListOwnerItems& packet)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListOwnerItems - %s not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    WorldPackets::AuctionHouse::AuctionListOwnerItemsResult result;

    auctionHouse->BuildListOwnerItems(result, _player, result.TotalCount);
    result.DesiredDelay = 300;
    SendPacket(result.Write());
}

//this void is called when player clicks on search button
void WorldSession::HandleAuctionListItems(WorldPackets::AuctionHouse::AuctionListItems& packet)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListItems - %s not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    TC_LOG_DEBUG("auctionHouse", "Auctionhouse search (%s), searchedname: %s, levelmin: %u, levelmax: %u, quality: %u, usable: %u",
        packet.Auctioneer.ToString().c_str(), packet.Name.c_str(), packet.MinLevel, packet.MaxLevel , packet.Quality, packet.OnlyUsable);

    // converting string that we try to find to lower case
    std::wstring wsearchedname;
    if (!Utf8toWStr(packet.Name, wsearchedname))
        return;

    wstrToLower(wsearchedname);

    Optional<AuctionSearchFilters> filters;

    WorldPackets::AuctionHouse::AuctionListItemsResult result;
    if (!packet.ClassFilters.empty())
    {
        filters = boost::in_place();

        for (auto const& classFilter : packet.ClassFilters)
        {
            if (!classFilter.SubClassFilters.empty())
            {
                for (auto const& subClassFilter : classFilter.SubClassFilters)
                {
                    if (classFilter.ItemClass < MAX_ITEM_CLASS)
                    {
                        filters->Classes[classFilter.ItemClass].SubclassMask |= 1 << subClassFilter.ItemSubclass;
                        if (subClassFilter.ItemSubclass < MAX_ITEM_SUBCLASS_TOTAL)
                            filters->Classes[classFilter.ItemClass].InvTypes[subClassFilter.ItemSubclass] = subClassFilter.InvTypeMask;
                    }
                }
            }
            else
                filters->Classes[classFilter.ItemClass].SubclassMask = AuctionSearchFilters::FILTER_SKIP_SUBCLASS;
        }
    }

    auctionHouse->BuildListAuctionItems(result, _player, wsearchedname, packet.Offset, packet.MinLevel, packet.MaxLevel, packet.OnlyUsable, filters, packet.Quality);

    result.DesiredDelay = sWorld->getIntConfig(CONFIG_AUCTION_SEARCH_DELAY);
    result.OnlyUsable = packet.OnlyUsable;
    SendPacket(result.Write());
}

void WorldSession::HandleAuctionListPendingSales(WorldPackets::AuctionHouse::AuctionListPendingSales& /*packet*/)
{
    WorldPackets::AuctionHouse::AuctionListPendingSalesResult result;
    result.TotalNumRecords = 0;
    SendPacket(result.Write());
}

void WorldSession::HandleReplicateItems(WorldPackets::AuctionHouse::AuctionReplicateItems& packet)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(packet.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleReplicateItems - %s not found or you can't interact with him.", packet.Auctioneer.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->getFaction());

    WorldPackets::AuctionHouse::AuctionReplicateResponse response;

    auctionHouse->BuildReplicate(response, GetPlayer(), packet.ChangeNumberGlobal, packet.ChangeNumberCursor, packet.ChangeNumberTombstone, packet.Count);

    response.DesiredDelay = sWorld->getIntConfig(CONFIG_AUCTION_SEARCH_DELAY) * 5;
    response.Result = 0;
    SendPacket(response.Write());
}
