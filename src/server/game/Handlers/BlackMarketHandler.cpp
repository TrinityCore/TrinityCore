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
#include "BlackMarketMgr.h"
#include "BlackMarketPackets.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Log.h"
#include "NPCPackets.h"
#include "Player.h"

void WorldSession::HandleBlackMarketOpen(WorldPackets::BlackMarket::BlackMarketOpen& blackMarketOpen)
{
    Creature* unit = GetPlayer()->GetNPCIfCanInteractWith(blackMarketOpen.Guid, UNIT_NPC_FLAG_BLACK_MARKET, UNIT_NPC_FLAG_2_BLACK_MARKET_VIEW);
    if (!unit)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleBlackMarketHello - Unit (GUID: {}) not found or you can't interact with him.", blackMarketOpen.Guid.ToString());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendBlackMarketOpenResult(blackMarketOpen.Guid, unit);
}

void WorldSession::SendBlackMarketOpenResult(ObjectGuid guid, Creature* /*auctioneer*/)
{
    WorldPackets::NPC::NPCInteractionOpenResult npcInteraction;
    npcInteraction.Npc = guid;
    npcInteraction.InteractionType = PlayerInteractionType::BlackMarketAuctioneer;
    npcInteraction.Success = sBlackMarketMgr->IsEnabled();
    SendPacket(npcInteraction.Write());
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
    packet.RandomPropertiesID = 0;

    SendPacket(packet.Write());
}
