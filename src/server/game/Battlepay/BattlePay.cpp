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
#include "BattlePay.h"
#include "Language.h"
#include "ObjectMgr.h"

BattlePay::BattlePay(Player* owner) : _owner(owner), m_enabled(false), m_available(false), m_currency(BATTLE_PAY_CURRENCY_DOLLAR)
{
}

void BattlePay::SendBattlePayPurchaseList()
{
    WorldPackets::BattlePay::BattlePayGetPurchaseListResponse response;

    response.Result = 0;

    _owner->SendDirectMessage(response.Write());
}

void BattlePay::SendBattlePayDistributionList()
{
    WorldPackets::BattlePay::BattlePayGetDistributionListResponse response;

    response.Result = 0;

    _owner->SendDirectMessage(response.Write());
}

void BattlePay::SendBattlePayProductList()
{
    WorldPackets::BattlePay::BattlePayGetProductListResponse response;

    response.CurrencyID = sBattlePayMgr->GetStoreCurrency();
    response.Result = 0; // BATTLE_PAY_RESULT_PRODUCT_LISTED

    for (auto const& p : _product)
        response.Products.push_back(&p.second.PacketInfo);

    for (auto const& p : _group)
        response.Groups.push_back(&p.second.PacketInfo);

    for (auto const& p : _entry)
        response.ShopEntries.push_back(&p.second.PacketInfo);

    _owner->SendDirectMessage(response.Write());
}

void BattlePay::SendBattlePayUpdateVasPurchaseStates()
{
    SendBattlePayProductList();
}