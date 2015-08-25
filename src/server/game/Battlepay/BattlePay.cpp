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
#include "Player.h"

BattlePay::BattlePay(Player* owner) : _owner(owner), m_enabled(false), m_available(false), m_currency(BATTLE_PAY_CURRENCY_DOLLAR)
{
}

void BattlePay::SendBattlePayPurchaseList()
{
    WorldPackets::BattlePay::BattlePayGetPurchaseListResponse response;
    response.Result = 0;

    for (auto const& p : response.Purchases)
    {
        WorldPackets::BattlePay::BattlePayPurchase purchase;

        purchase.ProductID = 0;
        purchase.PurchaseID = 0;
        purchase.ResultCode = 0;
        purchase.Status = 0;
        response.Purchases.push_back(purchase);
    }

    _owner->SendDirectMessage(response.Write());
}

void BattlePay::SendBattlePayDistributionList()
{
    WorldPackets::BattlePay::BattlePayGetDistributionListResponse response;
    response.Result = 0;

    for (auto const& p : response.DistributionObjects)
    {
        WorldPackets::BattlePay::BattlePayDistributionObject object;

        object.ProductID;
        object.Product = boost::in_place();
        object.Revoked = false;
        object.Status = 0;
        object.TargetNativeRealm = 0;
        object.TargetVirtualRealm = 0;
        object.DistributionID = 0;
        object.TargetPlayer = _owner->GetGUID();
        response.DistributionObjects.push_back(object);
    }

    _owner->SendDirectMessage(response.Write());
}

void BattlePay::SendBattlePayProductList()
{
    SendBattlePayDistributionList();
    SendBattlePayPurchaseList();

    WorldPackets::BattlePay::BattlePayGetProductListResponse response;

    response.Result = 0; // BATTLE_PAY_RESULT_PRODUCT_LISTED
    response.CurrencyID = sBattlePayMgr->GetStoreCurrency();

    for (auto const& p : response.Products)
    {
        WorldPackets::BattlePay::BattlePayProduct product;
        product.ProductID = GetProductID();
        product.DisplayInfo = boost::in_place();
        product.CurrentPriceFixedPoint = 0;
        product.Flags = 0;
        product.NormalPriceFixedPoint = 0;
        
        for (auto const& i : product.Items)
        {
            WorldPackets::BattlePay::BattlePayProductItem item;
            item.ID = 0;
            item.ItemID = 0;
            item.DisplayInfo = boost::in_place();
            item.HasMount = false;
            item.PetResult = boost::in_place();
            item.Quantity = 0;
            item.HasPet = false;
            product.Items.push_back(item);
        }

        product.Type = BATTLE_PAY_TYPE_END;
        product.Unk62_1 = 0;
        response.Products.push_back(product);
    }

    for (auto const& p : response.Groups)
    {
        WorldPackets::BattlePay::BattlePayProductGroup group;
        group.GroupID = 0;
        group.IconFileDataID = 0;
        group.DisplayType = 0;
        group.Ordering = 0;
        response.Groups.push_back(group);
    }

    for (auto const& p : response.ShopEntries)
    {
        WorldPackets::BattlePay::BattlePayShopEntry entry;
        entry.Ordering = 0;
        entry.EntryID = 0;
        entry.DisplayInfo = boost::in_place();
        entry.BannerType = 0;
        entry.Flags = 0;
        entry.ProductID = 0;
        entry.GroupID = 0;
        response.ShopEntries.push_back(entry);
    }

    TC_LOG_INFO("network", "WORLD: Received SMSG_BATTLE_PAY_GET_PRODUCT_LIST");
    _owner->SendDirectMessage(response.Write());
}