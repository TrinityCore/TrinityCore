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

#include "BattlePayMgr.h"
#include "BattlePayPackets.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"

void WorldSession::HandleBattlePayGetProductList(WorldPackets::BattlePay::BattlePayGetProductList& packet)
{
    if (!sBattlePayMgr->IsStoreEnabled())
        return;

    TC_LOG_INFO("network", "WORLD: Received CMSG_BATTLE_PAY_GET_PRODUCT_LIST");
    sBattlePayMgr->SendBattlePayProductList(this);
}

void WorldSession::HandleBattlePayGetPurchaseList(WorldPackets::BattlePay::BattlePayGetPurchaseList& packet)
{
    TC_LOG_INFO("network", "WORLD: Received CMSG_BATTLE_PAY_GET_PURCHSE_LIST");
    sBattlePayMgr->SendBattlePayPurchaseList(this);
}

void WorldSession::HandleBattlePayUpdateVasPurchaseStates(WorldPackets::BattlePay::BattlePayUpdateVasPurchaseStates& packet)
{
    TC_LOG_INFO("network", "WORLD: Received CMSG_UPDATE_VAS_PURCHASE_STATES");
    sBattlePayMgr->SendBattlePayUpdateVasPurchaseStates(this);
}

void WorldSession::HandleBattlePayGetDistributionList(WorldPackets::BattlePay::BattlePayGetDistributionList& packet)
{
    TC_LOG_INFO("network", "WORLD: Received CMSG_GET_DISTRIBUTION_LISTS");
    sBattlePayMgr->SendBattlePayDistributionList(this);
}

void WorldSession::HandleUpdateListedAuctionableTokens(WorldPackets::BattlePay::UpdateListedAuctionableTokens& updateListedAuctionableTokens)
{
    TC_LOG_INFO("network", "WORLD: Received CMSG_UPDATE_AUCTIONABLE_TOKENS");
    sBattlePayMgr->SendAuctionableTokenResponse(this, updateListedAuctionableTokens.UnkInt);
}

void WorldSession::HandleRequestWowTokenMarketPrice(WorldPackets::BattlePay::RequestWowTokenMarketPrice& requestWowTokenMarketPrice)
{
    TC_LOG_INFO("network", "WORLD: Received CMSG_REQUEST_WOW_TOKEN_MARKET_PRICE");
    sBattlePayMgr->SendWowTokenMarketPriceResponse(this, requestWowTokenMarketPrice.UnkInt);
}

void WorldSession::HandleWowTokenCheckVeteranEligibility(WorldPackets::BattlePay::WowTokenCheckVeteranEligibility& checkEligibility)
{
    TC_LOG_INFO("network", "WORLD: Received CMSG_CHECK_WOW_TOKEN_VETERAN_ELIGIBILITY");
    sBattlePayMgr->SendWowTokenEligibilityResponse(this, checkEligibility.Unk62);
}