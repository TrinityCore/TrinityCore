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

#include "BattlepayPackets.h"
#include "BattlepayMgr.h"
#include "Player.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayDisplayInfo const& display)
{
    data.WriteBits(display.Name1.length(), 10);
    data.WriteBits(display.Name1.length(), 10);
    data.WriteBits(display.Name1.length(), 13);

    data.WriteBit(display.CreatureDisplayInfoID.is_initialized());
    data.WriteBit(display.FileDataID.is_initialized());
    data.WriteBit(display.Flags.is_initialized());
    data.FlushBits();

    if (display.CreatureDisplayInfoID)
        data <<  *display.CreatureDisplayInfoID;

    if (display.FileDataID)
        data <<  *display.FileDataID;

    if (display.Flags)
        data <<  *display.Flags;

    data.WriteString(display.Name1);
    data.WriteString(display.Name2);
    data.WriteString(display.Name3);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayProductItem const& item)
{
    data << item.ID;
    data << item.ItemID;
    data << item.Quantity;
    
    data.WriteBit(item.DisplayInfo.is_initialized());
    data.WriteBit(item.PetResult.is_initialized());

    data.WriteBit(item.HasPet);
    data.WriteBit(item.HasMount);
    data.WriteBit(item.HasBattlePayDisplayInfo);
    data.FlushBits();

    if (item.DisplayInfo)
        data << *item.DisplayInfo;
    
    /*if (item.PetResult)
        data << *item.PetResult;*/

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayProductGroup const& group)
{
    data << group.GroupID;
    data << group.IconFileDataID;
    data << group.DisplayType;
    data << group.Ordering;

    data.WriteBits(group.Name.length(), 8);
    data.FlushBits();

    data.WriteString(group.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayShopEntry const& shop)
{
    data << shop.EntryID;
    data << shop.GroupID;
    data << shop.ProductID;
    data << shop.Ordering;
    data << shop.Flags;
    data << shop.BannerType;

    data.WriteBit(shop.DisplayInfo.is_initialized());
    data.FlushBits();

    if (shop.DisplayInfo)
        data << *shop.DisplayInfo;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayProduct const& product)
{
    data << product.ProductID;
    data << product.NormalPriceFixedPoint;
    data << product.CurrentPriceFixedPoint;
    
    for (WorldPackets::BattlePay::BattlePayProductItem const& item : product.Items)
        data << item;

    data << product.Type;
    data << product.ChoiceType;
    data << product.Flags;
    
    data.WriteBit(product.DisplayInfo.is_initialized());
    data.FlushBits();

    if (product.DisplayInfo)
        data << *product.DisplayInfo;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayDistributionObject const& object)
{
    data << object.DistributionID;
    data << object.Status;
    data << object.ProductID;
    data << object.TargetPlayer;
    data << object.TargetVirtualRealm;
    data << object.TargetNativeRealm;
    data << object.PurchaseID;
    
    data.WriteBit(object.Product.is_initialized());
    data.WriteBit(object.Revoked);
    data.FlushBits();

    if (object.Product)
        data << *object.Product;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayPurchase const& purchase)
{
    data << purchase.PurchaseID;
    data << purchase.Status;
    data << purchase.ResultCode;
    data << purchase.ProductID;

    data.WriteBits(purchase.WalletName.length(), 8);
    data.FlushBits();

    data.WriteString(purchase.WalletName);

    return data;
}

WorldPacket const* WorldPackets::BattlePay::BattlePayGetProductListResponse::Write()
{
    _worldPacket.reserve(4 + 4 +
        Products.size() * sizeof(BattlePayProduct) +
        Groups.size() * sizeof(BattlePayProductGroup) +
        ShopEntries.size() * sizeof(BattlePayShopEntry));

    _worldPacket << uint32(Result);
    _worldPacket << uint32(CurrencyID);
    _worldPacket << uint32(Products.size());
    _worldPacket << uint32(Groups.size());
    _worldPacket << uint32(ShopEntries.size());

    for (BattlePayProduct const* product : Products)
        _worldPacket << *product;

    for (BattlePayProductGroup const* group : Groups)
        _worldPacket << *group;

    for (BattlePayShopEntry const* entry : ShopEntries)
        _worldPacket << *entry;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePay::BattlePayStartPurchaseResponse::Write()
{
    return &_worldPacket;
}

void WorldPackets::BattlePay::BattlePayConfirmPurchaseResponse::Read()
{
}

WorldPacket const* WorldPackets::BattlePay::BattlePayGetPurchaseListResponse::Write()
{
    _worldPacket << Result;
    _worldPacket << Purchases.size();

    for (BattlePayPurchase const* purchase : Purchases)
        _worldPacket << *purchase;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePay::BattlePayGetDistributionListResponse::Write()
{
    _worldPacket << Result;
    _worldPacket << DistributionObjects.size();

    for (BattlePayDistributionObject const* object : DistributionObjects)
        _worldPacket << *object;

    return &_worldPacket;
}

void WorldPackets::BattlePay::BattlePayUpdateVasPurchaseStates::Read()
{  
}

void WorldPackets::BattlePay::BattlePayGetPurchaseList::Read()
{
}

void WorldPackets::BattlePay::BattlePayGetProductList::Read()
{
}