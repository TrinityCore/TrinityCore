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

#include "BlackMarketPackets.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "BlackMarketMgr.h"

void WorldSession::HandleBlackMarketOpen(WorldPackets::BlackMarket::BlackMarketOpen& packet)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Guid, UNIT_NPC_FLAG_BLACK_MARKET);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketHello - Unit (GUID: %s) not found or you can't interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendBlackMarketOpenResult(packet.Guid, unit);
}

void WorldSession::SendBlackMarketOpenResult(ObjectGuid guid, Creature* /*auctioneer*/)
{
    WorldPackets::BlackMarket::BlackMarketOpenResult packet;
    packet.Guid = guid;
    packet.Enable = sBlackMarketMgr->IsEnabled();
    SendPacket(packet.Write());
}

void WorldSession::HandleBlackMarketRequestItems(WorldPackets::BlackMarket::BlackMarketRequestItems& packet)
{
    if (!sBlackMarketMgr->IsEnabled())
        return;

    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(packet.Guid, UNIT_NPC_FLAG_BLACK_MARKET);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketRequestItems - Unit (GUID: %s) not found or you can't interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    WorldPackets::BlackMarket::BlackMarketRequestItemsResult result;
    sBlackMarketMgr->BuildItemsResponse(result, GetPlayer());
    SendPacket(result.Write());
}

void WorldSession::HandleBlackMarketBidOnItem(WorldPackets::BlackMarket::BlackMarketBidOnItem& packet)
{
    if (!sBlackMarketMgr->IsEnabled())
        return;

    Player* player = GetPlayer();
    Creature* unit = player->GetNPCIfCanInteractWith(packet.Guid, UNIT_NPC_FLAG_BLACK_MARKET);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketBidOnItem - Unit (GUID: %s) not found or you can't interact with him.", packet.Guid.ToString().c_str());
        return;
    }

    BlackMarketEntry* entry = sBlackMarketMgr->GetAuctionByID(packet.MarketID);
    if (!entry)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketBidOnItem - Player (%s, name: %s) tried to bid on a nonexistent auction (MarketId: %i).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), packet.MarketID);
        SendBlackMarketBidOnItemResult(ERR_BMAH_ITEM_NOT_FOUND, packet.MarketID, packet.Item);
        return;
    }

    if (entry->GetBidder() == player->GetGUID().GetCounter())
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketBidOnItem - Player (%s, name: %s) tried to place a bid on an item he already bid on. (MarketId: %i).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), packet.MarketID);
        SendBlackMarketBidOnItemResult(ERR_BMAH_ALREADY_BID, packet.MarketID, packet.Item);
        return;
    }

    if (!entry->ValidateBid(packet.bidAmount))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketBidOnItem - Player (%s, name: %s) tried to place an invalid bid. Amount: %lu (MarketId: %i).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), packet.bidAmount, packet.MarketID);
        SendBlackMarketBidOnItemResult(ERR_BMAH_HIGHER_BID, packet.MarketID, packet.Item);
        return;
    }

    if (!player->HasEnoughMoney(packet.bidAmount))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketBidOnItem - Player (%s, name: %s) does not have enough money to place bid. (MarketId: %i).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), packet.MarketID);
        SendBlackMarketBidOnItemResult(ERR_BMAH_NOT_ENOUGH_MONEY, packet.MarketID, packet.Item);
        return;
    }

    if (entry->GetSecondsRemaining() <= 0)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketBidOnItem - Player (%s, name: %s) tried to bid on a completed auction. (MarketId: %i).", player->GetGUID().ToString().c_str(), player->GetName().c_str(), packet.MarketID);
        SendBlackMarketBidOnItemResult(ERR_BMAH_DATABASE_ERROR, packet.MarketID, packet.Item);
        return;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    sBlackMarketMgr->SendAuctionOutbidMail(entry, trans);
    entry->PlaceBid(packet.bidAmount, player, trans);

    CharacterDatabase.CommitTransaction(trans);

    SendBlackMarketBidOnItemResult(ERR_BMAH_OK, packet.MarketID, packet.Item);
}

void WorldSession::SendBlackMarketBidOnItemResult(int32 result, int32 marketId, WorldPackets::Item::ItemInstance& item)
{
    WorldPackets::BlackMarket::BlackMarketBidOnItemResult packet;

    packet.MarketID = marketId;
    packet.Item = item;
    packet.Result = result;

    SendPacket(packet.Write());
}

void WorldSession::SendBlackMarketWonNotification(BlackMarketEntry const* entry, Item const* item)
{
    WorldPackets::BlackMarket::BlackMarketWon packet;

    packet.MarketID = entry->GetMarketId();
    packet.Item.Initialize(item);

    SendPacket(packet.Write());
}

void WorldSession::SendBlackMarketOutbidNotification(BlackMarketTemplate const* templ)
{
    WorldPackets::BlackMarket::BlackMarketOutbid packet;

    packet.MarketID = templ->MarketID;
    packet.Item = templ->Item;

    SendPacket(packet.Write());
}
