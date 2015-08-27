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
    data.WriteBit(display.CreatureDisplayInfoID.is_initialized());
    data.WriteBit(display.FileDataID.is_initialized());

    data.WriteBits(display.Name1.length(), 10);
    data.WriteBits(display.Name2.length(), 10);
    data.WriteBits(display.Name3.length(), 13);

    data.WriteBit(display.Flags.is_initialized());
    data.FlushBits();

    if (display.CreatureDisplayInfoID)
        data <<  *display.CreatureDisplayInfoID;

    if (display.FileDataID)
        data <<  *display.FileDataID;

    data.WriteString(display.Name1);
    data.WriteString(display.Name2);
    data.WriteString(display.Name3);

    if (display.Flags)
        data << *display.Flags;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BATTLEPETRESULT const& pet)
{
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayProductItem const& item)
{
    data << item.ID;
    data << item.ItemID;
    data << item.Quantity;
    
    data.WriteBit(item.DisplayInfo.is_initialized());
    data.WriteBit(item.HasPet);
    data.WriteBit(item.PetResult.is_initialized());
    //data.WriteBit(item.HasMount);
    data.FlushBits();

    if (item.HasPet)
        data.WriteBits(0, 4);

    if (item.DisplayInfo)
        data << *item.DisplayInfo;

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
    data << uint32(shop.EntryID);
    data << uint32(shop.GroupID);
    data << uint32(shop.ProductID);
    data << uint32(shop.Ordering);
    data << uint32(shop.Flags);
    data << uint8(shop.BannerType);

    data.WriteBit(shop.DisplayInfo.is_initialized());
    data.FlushBits();

    if (shop.DisplayInfo)
        data << *shop.DisplayInfo;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayProduct const& product)
{
    data << uint32(product.ProductID);

    data << uint64(product.NormalPriceFixedPoint);
    data << uint64(product.CurrentPriceFixedPoint);

    data << uint8(product.Type);
    data << uint32(product.Flags);

    data.WriteBits(product.Items.size(), 7);
    data.WriteBits(product.Unk62_1, 7);
    data.WriteBit(product.DisplayInfo.is_initialized());
    data.FlushBits();

    for (WorldPackets::BattlePay::BattlePayProductItem const& item : product.Items)
        data << item;

    if (product.DisplayInfo)
        data << *product.DisplayInfo;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePay::BattlePayDistributionObject const& object)
{
    data << uint64(object.DistributionID);

    data << uint32(object.Status);
    data << uint32(object.ProductID);

    data << object.TargetPlayer;
    data << uint32(object.TargetVirtualRealm);
    data << uint32(object.TargetNativeRealm);

    data << uint64(object.PurchaseID);
    
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
    /*_worldPacket.reserve(4 + 4 +
        Products.size() * sizeof(BattlePayProduct) +
        Groups.size() * sizeof(BattlePayProductGroup) +
        ShopEntries.size() * sizeof(BattlePayShopEntry));*/

    _worldPacket << uint32(Result);
    _worldPacket << uint32(CurrencyID);
    _worldPacket << uint32(Products.size());
    _worldPacket << uint32(Groups.size());
    _worldPacket << uint32(ShopEntries.size());

    for (BattlePayProduct const& product : Products)
        _worldPacket << product;

    for (BattlePayProductGroup const& group : Groups)
        _worldPacket << group;

    for (BattlePayShopEntry const& entry : ShopEntries)
        _worldPacket << entry;

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

    for (BattlePayPurchase const& purchase : Purchases)
        _worldPacket << purchase;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePay::BattlePayGetDistributionListResponse::Write()
{
    _worldPacket << Result;
    _worldPacket.WriteBits(DistributionObjects.size(), 11);

    for (BattlePayDistributionObject const& object : DistributionObjects)
        _worldPacket << object;

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

WorldPacket const* WorldPackets::BattlePay::BattlePayDistributionUpdate::Write()
{
    _worldPacket << DistributionObject;

    return &_worldPacket;
}

void WorldPackets::BattlePay::BattlePayStartPurchase::Read()
{
    _worldPacket >> ClientToken;
    _worldPacket >> ProductID;
    _worldPacket >> TargetCharacter;
}

void WorldPackets::BattlePay::BattlePayAckFailedResponse::Read()
{
    _worldPacket >> ServerToken;
}

void WorldPackets::BattlePay::BattlePayDistributionAssignToTarget::Read()
{
    _worldPacket >> ClientToken;
    _worldPacket >> DistributionID;
    _worldPacket >> TargetCharacter;
}

WorldPacket const* WorldPackets::BattlePay::BattlePayPurchaseUpdate::Write()
{
    for (auto const& purchase : Purchases)
        _worldPacket << purchase;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePay::BattlePayUpdateVasPurchaseStatesResponse::Write()
{
    _worldPacket.WriteBits(Count, 6);
    _worldPacket.FlushBits();

    for (auto i = 0; i < Count; i++)
    {
        _worldPacket << Guid;
        _worldPacket << State;
        _worldPacket << Unk1;

        _worldPacket.WriteBits(UnkBits2, 2);
        _worldPacket.FlushBits();

        for (auto j = 0; j < UnkBits2; j++)
            _worldPacket << Unk2;
    }

    return &_worldPacket;
}

void WorldPackets::BattlePay::UpdateListedAuctionableTokens::Read()
{
    _worldPacket >> UnkInt;
}

WorldPacket const* WorldPackets::BattlePay::UpdateListedAuctionableTokensResponse::Write()
{
    _worldPacket << UnkInt;
    _worldPacket << Result;
    _worldPacket << uint32(AuctionableTokenAuctionableList.size());
    for (AuctionableTokenAuctionable const& auctionableTokenAuctionable : AuctionableTokenAuctionableList)
    {
        _worldPacket << auctionableTokenAuctionable.UnkInt1;
        _worldPacket << auctionableTokenAuctionable.UnkInt2;
        _worldPacket << auctionableTokenAuctionable.Owner;
        _worldPacket << auctionableTokenAuctionable.BuyoutPrice;
        _worldPacket << auctionableTokenAuctionable.EndTime;
    }

    return &_worldPacket;
}

void WorldPackets::BattlePay::RequestWowTokenMarketPrice::Read()
{
    _worldPacket >> UnkInt;
}

WorldPacket const* WorldPackets::BattlePay::WowTokenMarketPriceResponse::Write()
{
    _worldPacket << CurrentMarketPrice;
    _worldPacket << UnkInt;
    _worldPacket << Result;
    _worldPacket << UnkInt2;

    return &_worldPacket;
}

void WorldPackets::BattlePay::WowTokenCheckVeteranEligibility::Read()
{
    _worldPacket >> Unk62;
}

WorldPacket const* WorldPackets::BattlePay::WowTokenCheckVeteranEligibilityResponse::Write()
{
    _worldPacket << CurrentMarketPrice;
    _worldPacket << Result;
    _worldPacket << Unk62;

    return &_worldPacket;
}