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

#include "WorldSession.h"
#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "AuctionHousePackets.h"
#include "CharacterCache.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Util.h"
#include "World.h"
#include <sstream>

void WorldSession::HandleAuctionBrowseQuery(WorldPackets::AuctionHouse::AuctionBrowseQuery& browseQuery)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, browseQuery.TaintedBy.has_value());
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(browseQuery.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListItems - {} not found or you can't interact with him.", browseQuery.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    TC_LOG_DEBUG("auctionHouse", "Auctionhouse search {}, searchedname: {}, levelmin: {}, levelmax: {}, filters: {}",
        browseQuery.Auctioneer.ToString(), browseQuery.Name, browseQuery.MinLevel, browseQuery.MaxLevel, AsUnderlyingType(browseQuery.Filters));

    std::wstring name;
    if (!Utf8toWStr(browseQuery.Name, name))
        return;

    Optional<AuctionSearchClassFilters> classFilters;

    WorldPackets::AuctionHouse::AuctionListBucketsResult listBucketsResult;
    if (!browseQuery.ItemClassFilters.empty())
    {
        classFilters.emplace();

        for (auto const& classFilter : browseQuery.ItemClassFilters)
        {
            if (!classFilter.SubClassFilters.empty())
            {
                for (auto const& subClassFilter : classFilter.SubClassFilters)
                {
                    if (classFilter.ItemClass < MAX_ITEM_CLASS)
                    {
                        classFilters->Classes[classFilter.ItemClass].SubclassMask |= 1 << subClassFilter.ItemSubclass;
                        if (subClassFilter.ItemSubclass < MAX_ITEM_SUBCLASS_TOTAL)
                            classFilters->Classes[classFilter.ItemClass].InvTypes[subClassFilter.ItemSubclass] = subClassFilter.InvTypeMask;
                    }
                }
            }
            else
                classFilters->Classes[classFilter.ItemClass].SubclassMask = AuctionSearchClassFilters::FILTER_SKIP_SUBCLASS;
        }
    }

    auctionHouse->BuildListBuckets(listBucketsResult, _player,
        name, browseQuery.MinLevel, browseQuery.MaxLevel, browseQuery.Filters, classFilters,
        browseQuery.KnownPets, browseQuery.MaxPetLevel, browseQuery.Offset, browseQuery.Sorts);

    listBucketsResult.BrowseMode = AuctionHouseBrowseMode::Search;
    listBucketsResult.DesiredDelay = uint32(throttle.DelayUntilNext.count());
    SendPacket(listBucketsResult.Write());
}

void WorldSession::HandleAuctionCancelCommoditiesPurchase(WorldPackets::AuctionHouse::AuctionCancelCommoditiesPurchase& cancelCommoditiesPurchase)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, cancelCommoditiesPurchase.TaintedBy.has_value(), AuctionCommand::PlaceBid);
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(cancelCommoditiesPurchase.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionCancelCommoditiesPurchase - {} not found or you can't interact with him.",
            cancelCommoditiesPurchase.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());
    auctionHouse->CancelCommodityQuote(_player->GetGUID());
}

void WorldSession::HandleAuctionConfirmCommoditiesPurchase(WorldPackets::AuctionHouse::AuctionConfirmCommoditiesPurchase& confirmCommoditiesPurchase)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, confirmCommoditiesPurchase.TaintedBy.has_value(), AuctionCommand::PlaceBid);
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(confirmCommoditiesPurchase.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionConfirmCommoditiesPurchase - {} not found or you can't interact with him.", confirmCommoditiesPurchase.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    if (auctionHouse->BuyCommodity(trans, _player, confirmCommoditiesPurchase.ItemID, confirmCommoditiesPurchase.Quantity, throttle.DelayUntilNext))
    {
        AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(trans)).AfterComplete([this, buyerGuid = _player->GetGUID(), throttle](bool success)
        {
            if (GetPlayer() && GetPlayer()->GetGUID() == buyerGuid)
            {
                if (success)
                {
                    GetPlayer()->UpdateCriteria(CriteriaType::AuctionsWon, 1);
                    SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::Ok, throttle.DelayUntilNext);
                }
                else
                    SendAuctionCommandResult(0, AuctionCommand::PlaceBid, AuctionResult::CommodityPurchaseFailed, throttle.DelayUntilNext);
            }
        });
    }
}

void WorldSession::HandleAuctionGetCommodityQuote(WorldPackets::AuctionHouse::AuctionGetCommodityQuote& getCommodityQuote)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, getCommodityQuote.TaintedBy.has_value(), AuctionCommand::PlaceBid);
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(getCommodityQuote.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionStartCommoditiesPurchase - {} not found or you can't interact with him.",
            getCommodityQuote.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionGetCommodityQuoteResult commodityQuoteResult;

    if (CommodityQuote const* quote = auctionHouse->CreateCommodityQuote(_player, getCommodityQuote.ItemID, getCommodityQuote.Quantity))
    {
        commodityQuoteResult.TotalPrice = quote->TotalPrice;
        commodityQuoteResult.Quantity = quote->Quantity;
        commodityQuoteResult.QuoteDuration = std::chrono::duration_cast<Milliseconds>(quote->ValidTo - GameTime::Now());
    }

    commodityQuoteResult.ItemID = getCommodityQuote.ItemID;
    commodityQuoteResult.DesiredDelay = uint32(throttle.DelayUntilNext.count());

    SendPacket(commodityQuoteResult.Write());
}

void WorldSession::HandleAuctionHelloOpcode(WorldPackets::AuctionHouse::AuctionHelloRequest& hello)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(hello.Guid, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionHelloOpcode - Unit ({}) not found or you can't interact with him.", hello.Guid.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendAuctionHello(hello.Guid, unit);
}

void WorldSession::HandleAuctionListBiddedItems(WorldPackets::AuctionHouse::AuctionListBiddedItems& listBiddedItems)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, listBiddedItems.TaintedBy.has_value());
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(listBiddedItems.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListBidderItems - {} not found or you can't interact with him.", listBiddedItems.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionListBiddedItemsResult result;

    Player* player = GetPlayer();
    auctionHouse->BuildListBiddedItems(result, player, listBiddedItems.Offset, listBiddedItems.Sorts);
    result.DesiredDelay = uint32(throttle.DelayUntilNext.count());
    SendPacket(result.Write());
}

void WorldSession::HandleAuctionListBucketsByBucketKeys(WorldPackets::AuctionHouse::AuctionListBucketsByBucketKeys& listBucketsByBucketKeys)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, listBucketsByBucketKeys.TaintedBy.has_value());
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(listBucketsByBucketKeys.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListBucketsByBucketKeys - {} not found or you can't interact with him.",
            listBucketsByBucketKeys.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionListBucketsResult listBucketsResult;

    auctionHouse->BuildListBuckets(listBucketsResult, _player, listBucketsByBucketKeys.BucketKeys, listBucketsByBucketKeys.Sorts);

    listBucketsResult.BrowseMode = AuctionHouseBrowseMode::SpecificKeys;
    listBucketsResult.DesiredDelay = uint32(throttle.DelayUntilNext.count());
    SendPacket(listBucketsResult.Write());
}

void WorldSession::HandleAuctionListItemsByBucketKey(WorldPackets::AuctionHouse::AuctionListItemsByBucketKey& listItemsByBucketKey)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, listItemsByBucketKey.TaintedBy.has_value());
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(listItemsByBucketKey.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListItemsByBucketKey - {} not found or you can't interact with him.", listItemsByBucketKey.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionListItemsResult listItemsResult;
    listItemsResult.DesiredDelay = uint32(throttle.DelayUntilNext.count());
    listItemsResult.BucketKey = listItemsByBucketKey.BucketKey;
    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(listItemsByBucketKey.BucketKey.ItemID);
    listItemsResult.ListType = itemTemplate && itemTemplate->GetMaxStackSize() > 1 ? AuctionHouseListType::Commodities : AuctionHouseListType::Items;

    auctionHouse->BuildListAuctionItems(listItemsResult, _player, listItemsByBucketKey.BucketKey, listItemsByBucketKey.Offset, listItemsByBucketKey.Sorts);

    SendPacket(listItemsResult.Write());
}

void WorldSession::HandleAuctionListItemsByItemID(WorldPackets::AuctionHouse::AuctionListItemsByItemID& listItemsByItemID)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, listItemsByItemID.TaintedBy.has_value());
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(listItemsByItemID.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListItemsByItemID - {} not found or you can't interact with him.", listItemsByItemID.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionListItemsResult listItemsResult;
    listItemsResult.DesiredDelay = uint32(throttle.DelayUntilNext.count());
    listItemsResult.BucketKey.ItemID = listItemsByItemID.ItemID;
    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(listItemsByItemID.ItemID);
    listItemsResult.ListType = itemTemplate && itemTemplate->GetMaxStackSize() > 1 ? AuctionHouseListType::Commodities : AuctionHouseListType::Items;

    auctionHouse->BuildListAuctionItems(listItemsResult, _player, listItemsByItemID.ItemID, listItemsByItemID.Offset, listItemsByItemID.Sorts);

    SendPacket(listItemsResult.Write());
}

//this void sends player info about his auctions
void WorldSession::HandleAuctionListOwnedItems(WorldPackets::AuctionHouse::AuctionListOwnedItems& listOwnedItems)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, listOwnedItems.TaintedBy.has_value());
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(listOwnedItems.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionListOwnerItems - {} not found or you can't interact with him.", listOwnedItems.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionListOwnedItemsResult result;

    auctionHouse->BuildListOwnedItems(result, _player, listOwnedItems.Offset, listOwnedItems.Sorts);
    result.DesiredDelay = uint32(throttle.DelayUntilNext.count());
    SendPacket(result.Write());
}

// this function is called when client bids or buys out auction
void WorldSession::HandleAuctionPlaceBid(WorldPackets::AuctionHouse::AuctionPlaceBid& placeBid)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, placeBid.TaintedBy.has_value(), AuctionCommand::PlaceBid);
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(placeBid.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionPlaceBid - {} not found or you can't interact with him.", placeBid.Auctioneer.ToString());
        return;
    }

    // auction house does not deal with copper
    if (placeBid.BidAmount % SILVER)
    {
        SendAuctionCommandResult(placeBid.AuctionID, AuctionCommand::PlaceBid, AuctionResult::BidIncrement, throttle.DelayUntilNext);
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    AuctionPosting* auction = auctionHouse->GetAuction(placeBid.AuctionID);
    if (!auction || auction->IsCommodity())
    {
        SendAuctionCommandResult(placeBid.AuctionID, AuctionCommand::PlaceBid, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
        return;
    }

    Player* player = GetPlayer();

    // check auction owner - cannot buy own auctions
    if (auction->Owner == player->GetGUID() || auction->OwnerAccount == GetAccountGUID())
    {
        SendAuctionCommandResult(placeBid.AuctionID, AuctionCommand::PlaceBid, AuctionResult::BidOwn, throttle.DelayUntilNext);
        return;
    }

    bool canBid = auction->MinBid != 0;
    bool canBuyout = auction->BuyoutOrUnitPrice != 0;

    // buyout attempt with wrong amount
    if (!canBid && placeBid.BidAmount != auction->BuyoutOrUnitPrice)
    {
        SendAuctionCommandResult(placeBid.AuctionID, AuctionCommand::PlaceBid, AuctionResult::BidIncrement, throttle.DelayUntilNext);
        return;
    }

    uint64 minBid = auction->BidAmount ? auction->BidAmount + auction->CalculateMinIncrement() : auction->MinBid;
    if (canBid && placeBid.BidAmount < minBid)
    {
        SendAuctionCommandResult(placeBid.AuctionID, AuctionCommand::PlaceBid, AuctionResult::HigherBid, throttle.DelayUntilNext);
        return;
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    uint64 priceToPay = placeBid.BidAmount;
    if (!auction->Bidder.IsEmpty())
    {
        // return money to previous bidder
        if (auction->Bidder != player->GetGUID())
            auctionHouse->SendAuctionOutbid(auction, player->GetGUID(), placeBid.BidAmount, trans);
        else
            priceToPay = placeBid.BidAmount - auction->BidAmount;
    }

    // check money
    if (!player->HasEnoughMoney(priceToPay))
    {
        SendAuctionCommandResult(placeBid.AuctionID, AuctionCommand::PlaceBid, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
        return;
    }

    player->ModifyMoney(-int64(priceToPay));
    auction->Bidder = player->GetGUID();
    auction->BidAmount = placeBid.BidAmount;
    if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
        auction->ServerFlags |= AuctionPostingServerFlag::GmLogBuyer;
    else
        auction->ServerFlags &= ~AuctionPostingServerFlag::GmLogBuyer;

    if (canBuyout && placeBid.BidAmount == auction->BuyoutOrUnitPrice)
    {
        // buyout
        auctionHouse->SendAuctionSold(auction, nullptr, trans);
        auctionHouse->SendAuctionWon(auction, player, trans);

        auctionHouse->RemoveAuction(trans, auction);
    }
    else
    {
        // place bid
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AUCTION_BID);
        stmt->setUInt64(0, auction->Bidder.GetCounter());
        stmt->setUInt64(1, auction->BidAmount);
        stmt->setUInt8(2, auction->ServerFlags.AsUnderlyingType());
        stmt->setUInt32(3, auction->Id);
        trans->Append(stmt);

        if (auction->BidderHistory.insert(player->GetGUID()).second)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AUCTION_BIDDER);
            stmt->setUInt32(0, auction->Id);
            stmt->setUInt64(1, player->GetGUID().GetCounter());
            trans->Append(stmt);
        }

        // Not sure if we must send this now.
        if (Player* owner = ObjectAccessor::FindConnectedPlayer(auction->Owner))
            owner->GetSession()->SendAuctionOwnerBidNotification(auction);
    }

    player->SaveInventoryAndGoldToDB(trans);
    AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(trans)).AfterComplete(
        [this, auctionId = placeBid.AuctionID, bidAmount = placeBid.BidAmount, auctionPlayerGuid = _player->GetGUID(), throttle](bool success)
    {
        if (GetPlayer() && GetPlayer()->GetGUID() == auctionPlayerGuid)
        {
            if (success)
            {
                GetPlayer()->UpdateCriteria(CriteriaType::HighestAuctionBid, bidAmount);
                SendAuctionCommandResult(auctionId, AuctionCommand::PlaceBid, AuctionResult::Ok, throttle.DelayUntilNext);
            }
            else
                SendAuctionCommandResult(auctionId, AuctionCommand::PlaceBid, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        }
    });
}

void WorldSession::HandleAuctionRemoveItem(WorldPackets::AuctionHouse::AuctionRemoveItem& removeItem)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, removeItem.TaintedBy.has_value(), AuctionCommand::Cancel);
    if (throttle.Throttled)
        return;

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(removeItem.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionRemoveItem - {} not found or you can't interact with him.", removeItem.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    AuctionPosting* auction = auctionHouse->GetAuction(removeItem.AuctionID);
    Player* player = GetPlayer();

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    if (auction && auction->Owner == player->GetGUID())
    {
        if (auction->Bidder.IsEmpty())                   // If we have a bidder, we have to send him the money he paid
        {
            uint64 cancelCost = CalculatePct(auction->BidAmount, 5u);
            if (!player->HasEnoughMoney(cancelCost))          //player doesn't have enough money
            {
                SendAuctionCommandResult(0, AuctionCommand::Cancel, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
                return;
            }
            auctionHouse->SendAuctionCancelledToBidder(auction, trans);
            player->ModifyMoney(-int64(cancelCost));
        }

        auctionHouse->SendAuctionRemoved(auction, player, trans);
    }
    else
    {
        SendAuctionCommandResult(0, AuctionCommand::Cancel, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        //this code isn't possible ... maybe there should be assert
        TC_LOG_ERROR("entities.player.cheat", "CHEATER : {} tried to cancel auction (id: {}) of another player or auction is NULL", player->GetGUID().ToString(), removeItem.AuctionID);
        return;
    }

    // client bug - instead of removing auction in the UI, it only substracts 1 from visible count
    uint32 auctionIdForClient = auction->IsCommodity() ? 0 : auction->Id;

    // Now remove the auction
    player->SaveInventoryAndGoldToDB(trans);
    auctionHouse->RemoveAuction(trans, auction);
    AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(trans)).AfterComplete(
        [this, auctionIdForClient, auctionPlayerGuid = _player->GetGUID(), throttle](bool success)
    {
        if (GetPlayer() && GetPlayer()->GetGUID() == auctionPlayerGuid)
        {
            if (success)
                SendAuctionCommandResult(auctionIdForClient, AuctionCommand::Cancel, AuctionResult::Ok, throttle.DelayUntilNext);        //inform player, that auction is removed
            else
                SendAuctionCommandResult(0, AuctionCommand::Cancel, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        }
    });
}

void WorldSession::HandleAuctionReplicateItems(WorldPackets::AuctionHouse::AuctionReplicateItems& replicateItems)
{
    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(replicateItems.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleReplicateItems - {} not found or you can't interact with him.", replicateItems.Auctioneer.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    WorldPackets::AuctionHouse::AuctionReplicateResponse response;

    auctionHouse->BuildReplicate(response, GetPlayer(),
        replicateItems.ChangeNumberGlobal, replicateItems.ChangeNumberCursor, replicateItems.ChangeNumberTombstone, replicateItems.Count);

    response.DesiredDelay = sWorld->getIntConfig(CONFIG_AUCTION_SEARCH_DELAY) * 5;
    response.Result = 0;
    SendPacket(response.Write());
}

void WorldSession::HandleAuctionRequestFavoriteList(WorldPackets::AuctionHouse::AuctionRequestFavoriteList& /*requestFavoriteList*/)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_FAVORITE_AUCTIONS);
    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    GetQueryProcessor().AddCallback(CharacterDatabase.AsyncQuery(stmt)).WithPreparedCallback([this](PreparedQueryResult favoriteAuctionResult)
    {
        WorldPackets::AuctionHouse::AuctionFavoriteList favoriteItems;
        if (favoriteAuctionResult)
        {
            favoriteItems.Items.reserve(favoriteAuctionResult->GetRowCount());

            do
            {
                Field* fields = favoriteAuctionResult->Fetch();

                WorldPackets::AuctionHouse::AuctionFavoriteInfo& item = favoriteItems.Items.emplace_back();
                item.Order = fields[0].GetUInt32();
                item.ItemID = fields[1].GetUInt32();
                item.ItemLevel = fields[2].GetUInt32();
                item.BattlePetSpeciesID = fields[3].GetUInt32();
                item.SuffixItemNameDescriptionID = fields[4].GetUInt32();

            } while (favoriteAuctionResult->NextRow());

        }
        SendPacket(favoriteItems.Write());
    });
}

void WorldSession::HandleAuctionSellCommodity(WorldPackets::AuctionHouse::AuctionSellCommodity& sellCommodity)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, sellCommodity.TaintedBy.has_value(), AuctionCommand::SellItem);
    if (throttle.Throttled)
        return;

    if (!sellCommodity.UnitPrice || sellCommodity.UnitPrice > MAX_MONEY_AMOUNT)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Player {} {} attempted to sell item with invalid price.", _player->GetName(), _player->GetGUID().ToString());
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        return;
    }

    // auction house does not deal with copper
    if (sellCommodity.UnitPrice % SILVER)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        return;
    }

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(sellCommodity.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Unit {} not found or you can't interact with him.", sellCommodity.Auctioneer.ToString());
        return;
    }

    uint32 houseId = 0;
    AuctionHouseEntry const* auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntry(creature->GetFaction(), &houseId);
    if (!auctionHouseEntry)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Unit {} has wrong faction.", sellCommodity.Auctioneer.ToString());
        return;
    }

    switch (sellCommodity.RunTime)
    {
        case 1 * MIN_AUCTION_TIME / MINUTE:
        case 2 * MIN_AUCTION_TIME / MINUTE:
        case 4 * MIN_AUCTION_TIME / MINUTE:
            break;
        default:
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::AuctionHouseBusy, throttle.DelayUntilNext);
            return;
    }

    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    // find all items for sale
    uint64 totalCount = 0;
    std::unordered_map<ObjectGuid, std::pair<Item*, uint64>> items2;

    for (WorldPackets::AuctionHouse::AuctionItemForSale const& itemForSale : sellCommodity.Items)
    {
        Item* item = _player->GetItemByGuid(itemForSale.Guid);
        if (!item)
        {
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
            return;
        }

        if (item->GetTemplate()->GetMaxStackSize() == 1)
        {
            // not commodity, must use different packet
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
            return;
        }

        // verify that all items belong to the same bucket
        if (!items2.empty() && AuctionsBucketKey::ForItem(item) != AuctionsBucketKey::ForItem(items2.begin()->second.first))
        {
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
            return;
        }

        if (sAuctionMgr->GetAItem(item->GetGUID()) || !item->CanBeTraded() || item->IsNotEmptyBag() ||
            item->GetTemplate()->HasFlag(ITEM_FLAG_CONJURED) || *item->m_itemData->Expiration ||
            item->GetCount() < itemForSale.UseCount)
        {
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
            return;
        }

        std::pair<Item*, uint64>& soldItem = items2[item->GetGUID()];
        soldItem.first = item;
        soldItem.second += itemForSale.UseCount;
        if (item->GetCount() < soldItem.second)
        {
            // check that we have enough of this item to sell
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
            return;
        }

        totalCount += itemForSale.UseCount;
    }

    if (!totalCount)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        return;
    }

    Seconds auctionTime = Seconds(int64(std::chrono::duration_cast<Seconds>(Minutes(sellCommodity.RunTime)).count() * double(sWorld->getRate(RATE_AUCTION_TIME))));
    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    uint64 deposit = AuctionHouseMgr::GetCommodityAuctionDeposit(items2.begin()->second.first->GetTemplate(), Minutes(sellCommodity.RunTime), totalCount);
    if (!_player->HasEnoughMoney(deposit))
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
        return;
    }

    uint32 auctionId = sObjectMgr->GenerateAuctionID();
    AuctionPosting auction;
    auction.Id = auctionId;
    auction.Owner = _player->GetGUID();
    auction.OwnerAccount = GetAccountGUID();
    auction.BuyoutOrUnitPrice = sellCommodity.UnitPrice;
    auction.Deposit = deposit;
    auction.StartTime = GameTime::GetSystemTime();
    auction.EndTime = auction.StartTime + auctionTime;

    // keep track of what was cloned to undo/modify counts later
    std::unordered_map<Item* /*original*/, std::unique_ptr<Item> /*clone*/> clones;
    for (std::pair<ObjectGuid const, std::pair<Item*, uint64>>& it : items2)
    {
        Item* itemForSale;
        if (it.second.first->GetCount() != it.second.second)
        {
            itemForSale = it.second.first->CloneItem(it.second.second, _player);
            if (!itemForSale)
            {
                TC_LOG_ERROR("network", "CMSG_AUCTION_SELL_COMMODITY: Could not create clone of item {}", it.second.first->GetEntry());
                SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
                return;
            }

            clones.emplace(it.second.first, itemForSale);
        }
    }

    if (!sAuctionMgr->PendingAuctionAdd(_player, auctionHouse->GetAuctionHouseId(), auction.Id, auction.Deposit))
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
        return;
    }

    TC_LOG_INFO("network", "CMSG_AUCTION_SELL_COMMODITY: {} {} is selling item {} {} to auctioneer {} with count {} with with unit price {} and with time {} (in sec) in auctionhouse {}",
        _player->GetGUID().ToString(), _player->GetName(), items2.begin()->second.first->GetNameForLocaleIdx(sWorld->GetDefaultDbcLocale()),
        ([&items2]()
        {
            std::stringstream ss;
            auto itr = items2.begin();
            ss << (itr++)->first.ToString();
            for (; itr != items2.end(); ++itr)
                ss << ',' << itr->first.ToString();
            return ss.str();
        }()).c_str(),
        creature->GetGUID().ToString().c_str(), totalCount, sellCommodity.UnitPrice, uint32(auctionTime.count()), auctionHouse->GetAuctionHouseId());

    if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        Item* logItem = items2.begin()->second.first;
        sLog->OutCommand(GetAccountId(), "GM {} (Account: {}) create auction: {} (Entry: {} Count: {})",
            GetPlayerName(), GetAccountId(), logItem->GetNameForLocaleIdx(sWorld->GetDefaultDbcLocale()), logItem->GetEntry(), totalCount);
    }

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    for (std::pair<ObjectGuid const, std::pair<Item*, uint64>> const& it : items2)
    {
        Item* itemForSale = it.second.first;
        auto cloneItr = clones.find(it.second.first);
        if (cloneItr != clones.end())
        {
            Item* original = itemForSale;
            original->SetCount(original->GetCount() - uint32(it.second.second));
            original->SetState(ITEM_CHANGED, _player);
            _player->ItemRemovedQuestCheck(original->GetEntry(), uint32(it.second.second));
            original->SaveToDB(trans);

            itemForSale = cloneItr->second.release();
        }
        else
        {
            _player->MoveItemFromInventory(itemForSale->GetBagSlot(), itemForSale->GetSlot(), true);
            itemForSale->DeleteFromInventoryDB(trans);
        }

        itemForSale->SaveToDB(trans);
        auction.Items.push_back(itemForSale);
    }

    auctionHouse->AddAuction(trans, std::move(auction));
    _player->SaveInventoryAndGoldToDB(trans);

    AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(trans)).AfterComplete([this, auctionId, auctionPlayerGuid = _player->GetGUID(), throttle](bool success)
    {
        if (GetPlayer() && GetPlayer()->GetGUID() == auctionPlayerGuid)
        {
            if (success)
            {
                GetPlayer()->UpdateCriteria(CriteriaType::ItemsPostedAtAuction, 1);
                SendAuctionCommandResult(auctionId, AuctionCommand::SellItem, AuctionResult::Ok, throttle.DelayUntilNext);
            }
            else
                SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        }
    });
}

void WorldSession::HandleAuctionSellItem(WorldPackets::AuctionHouse::AuctionSellItem& sellItem)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, sellItem.TaintedBy.has_value(), AuctionCommand::SellItem);
    if (throttle.Throttled)
        return;

    if (sellItem.Items.size() != 1 || sellItem.Items[0].UseCount != 1)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
        return;
    }

    if (!sellItem.MinBid && !sellItem.BuyoutPrice)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
        return;
    }

    if (sellItem.MinBid > MAX_MONEY_AMOUNT || sellItem.BuyoutPrice > MAX_MONEY_AMOUNT)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Player {} {} attempted to sell item with higher price than max gold amount.", _player->GetName(), _player->GetGUID().ToString());
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::Inventory, throttle.DelayUntilNext, EQUIP_ERR_TOO_MUCH_GOLD);
        return;
    }

    // auction house does not deal with copper
    if (sellItem.MinBid % SILVER || sellItem.BuyoutPrice % SILVER)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        return;
    }

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(sellItem.Auctioneer, UNIT_NPC_FLAG_AUCTIONEER, UNIT_NPC_FLAG_2_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Unit {} not found or you can't interact with him.", sellItem.Auctioneer.ToString());
        return;
    }

    uint32 houseId = 0;
    AuctionHouseEntry const* auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntry(creature->GetFaction(), &houseId);
    if (!auctionHouseEntry)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleAuctionSellItem - Unit {} has wrong faction.", sellItem.Auctioneer.ToString());
        return;
    }

    switch (sellItem.RunTime)
    {
        case 1 * MIN_AUCTION_TIME / MINUTE:
        case 2 * MIN_AUCTION_TIME / MINUTE:
        case 4 * MIN_AUCTION_TIME / MINUTE:
            break;
        default:
            SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::AuctionHouseBusy, throttle.DelayUntilNext);
            return;
    }

    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    Item* item = _player->GetItemByGuid(sellItem.Items[0].Guid);
    if (!item)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
        return;
    }

    if (item->GetTemplate()->GetMaxStackSize() > 1)
    {
        // commodity, must use different packet
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::ItemNotFound, throttle.DelayUntilNext);
        return;
    }

    if (sAuctionMgr->GetAItem(item->GetGUID()) || !item->CanBeTraded() || item->IsNotEmptyBag() ||
        item->GetTemplate()->HasFlag(ITEM_FLAG_CONJURED) || *item->m_itemData->Expiration ||
        item->GetCount() != 1)
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        return;
    }

    Seconds auctionTime = Seconds(int64(std::chrono::duration_cast<Seconds>(Minutes(sellItem.RunTime)).count() * double(sWorld->getRate(RATE_AUCTION_TIME))));
    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(creature->GetFaction());

    uint64 deposit = AuctionHouseMgr::GetItemAuctionDeposit(_player, item, Minutes(sellItem.RunTime));
    if (!_player->HasEnoughMoney(deposit))
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
        return;
    }

    uint32 auctionId = sObjectMgr->GenerateAuctionID();

    AuctionPosting auction;
    auction.Id = auctionId;
    auction.Owner = _player->GetGUID();
    auction.OwnerAccount = GetAccountGUID();
    auction.MinBid = sellItem.MinBid;
    auction.BuyoutOrUnitPrice = sellItem.BuyoutPrice;
    auction.Deposit = deposit;
    auction.BidAmount = sellItem.MinBid;
    auction.StartTime = GameTime::GetSystemTime();
    auction.EndTime = auction.StartTime + auctionTime;

    if (HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->OutCommand(GetAccountId(), "GM {} (Account: {}) create auction: {} (Entry: {} Count: {})",
            GetPlayerName(), GetAccountId(), item->GetTemplate()->GetDefaultLocaleName(), item->GetEntry(), item->GetCount());
    }

    auction.Items.push_back(item);

    TC_LOG_INFO("network", "CMSG_AuctionAction::SellItem: {} {} is selling item {} {} to auctioneer {} with count {} with initial bid {} with buyout {} and with time {} (in sec) in auctionhouse {}",
        _player->GetGUID().ToString(), _player->GetName(), item->GetGUID().ToString(), item->GetTemplate()->GetDefaultLocaleName(),
        creature->GetGUID().ToString(), item->GetCount(), sellItem.MinBid, sellItem.BuyoutPrice, uint32(auctionTime.count()), auctionHouse->GetAuctionHouseId());

    // Add to pending auctions, or fail with insufficient funds error
    if (!sAuctionMgr->PendingAuctionAdd(_player, auctionHouse->GetAuctionHouseId(), auctionId, auction.Deposit))
    {
        SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::NotEnoughMoney, throttle.DelayUntilNext);
        return;
    }

    _player->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    item->DeleteFromInventoryDB(trans);
    item->SaveToDB(trans);

    auctionHouse->AddAuction(trans, std::move(auction));
    _player->SaveInventoryAndGoldToDB(trans);
    AddTransactionCallback(CharacterDatabase.AsyncCommitTransaction(trans)).AfterComplete([this, auctionId, auctionPlayerGuid = _player->GetGUID(), throttle](bool success)
    {
        if (GetPlayer() && GetPlayer()->GetGUID() == auctionPlayerGuid)
        {
            if (success)
            {
                GetPlayer()->UpdateCriteria(CriteriaType::ItemsPostedAtAuction, 1);
                SendAuctionCommandResult(auctionId, AuctionCommand::SellItem, AuctionResult::Ok, throttle.DelayUntilNext);
            }
            else
                SendAuctionCommandResult(0, AuctionCommand::SellItem, AuctionResult::DatabaseError, throttle.DelayUntilNext);
        }
    });
}

void WorldSession::HandleAuctionSetFavoriteItem(WorldPackets::AuctionHouse::AuctionSetFavoriteItem& setFavoriteItem)
{
    AuctionThrottleResult throttle = sAuctionMgr->CheckThrottle(_player, false);
    if (throttle.Throttled)
        return;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_FAVORITE_AUCTION);
    stmt->setUInt64(0, _player->GetGUID().GetCounter());
    stmt->setUInt32(1, setFavoriteItem.Item.Order);
    trans->Append(stmt);

    if (!setFavoriteItem.IsNotFavorite)
    {
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_FAVORITE_AUCTION);
        stmt->setUInt64(0, _player->GetGUID().GetCounter());
        stmt->setUInt32(1, setFavoriteItem.Item.Order);
        stmt->setUInt32(2, setFavoriteItem.Item.ItemID);
        stmt->setUInt32(3, setFavoriteItem.Item.ItemLevel);
        stmt->setUInt32(4, setFavoriteItem.Item.BattlePetSpeciesID);
        stmt->setUInt32(5, setFavoriteItem.Item.SuffixItemNameDescriptionID);
        trans->Append(stmt);
    }

    CharacterDatabase.CommitTransaction(trans);
}

//this void causes that auction window is opened
void WorldSession::SendAuctionHello(ObjectGuid guid, Creature* unit)
{
    if (GetPlayer()->GetLevel() < sWorld->getIntConfig(CONFIG_AUCTION_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_AUCTION_REQ), sWorld->getIntConfig(CONFIG_AUCTION_LEVEL_REQ));
        return;
    }

    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->GetFaction(), nullptr);
    if (!ahEntry)
        return;

    WorldPackets::AuctionHouse::AuctionHelloResponse auctionHelloResponse;
    auctionHelloResponse.Guid = guid;
    auctionHelloResponse.OpenForBusiness = true;                         // 3.3.3: 1 - AH enabled, 0 - AH disabled
    SendPacket(auctionHelloResponse.Write());
}

void WorldSession::SendAuctionCommandResult(uint32 auctionId, AuctionCommand command, AuctionResult errorCode, Milliseconds delayForNextAction, InventoryResult bagError /*= 0*/)
{
    WorldPackets::AuctionHouse::AuctionCommandResult auctionCommandResult;
    auctionCommandResult.AuctionID = auctionId;
    auctionCommandResult.Command = AsUnderlyingType(command);
    auctionCommandResult.ErrorCode = AsUnderlyingType(errorCode);
    auctionCommandResult.BagResult = AsUnderlyingType(bagError);
    auctionCommandResult.DesiredDelay = uint32(delayForNextAction.count());
    SendPacket(auctionCommandResult.Write());
}

void WorldSession::SendAuctionClosedNotification(AuctionPosting const* auction, float mailDelay, bool sold)
{
    WorldPackets::AuctionHouse::AuctionClosedNotification packet;
    packet.Info.Initialize(auction);
    packet.ProceedsMailDelay = mailDelay;
    packet.Sold = sold;
    SendPacket(packet.Write());
}

void WorldSession::SendAuctionOwnerBidNotification(AuctionPosting const* auction)
{
    WorldPackets::AuctionHouse::AuctionOwnerBidNotification packet;
    packet.Info.Initialize(auction);
    packet.Bidder = auction->Bidder;
    packet.MinIncrement = auction->CalculateMinIncrement();
    SendPacket(packet.Write());
}
