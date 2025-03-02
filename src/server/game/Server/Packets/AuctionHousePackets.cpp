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

#include "AuctionHousePackets.h"
#include "AuctionHouseMgr.h"
#include "DB2Stores.h"
#include "ObjectGuid.h"
#include "Util.h"

namespace WorldPackets::AuctionHouse
{
AuctionBucketKey& AuctionBucketKey::operator=(AuctionsBucketKey const& key)
{
    ItemID = key.ItemId;
    ItemLevel = key.ItemLevel;

    if (key.BattlePetSpeciesId)
        BattlePetSpeciesID = key.BattlePetSpeciesId;

    if (key.SuffixItemNameDescriptionId)
        ItemSuffix = key.SuffixItemNameDescriptionId;

    return *this;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionBucketKey& itemKey)
{
    data.ResetBitPos();
    data >> Bits<20>(itemKey.ItemID);
    data >> OptionalInit(itemKey.BattlePetSpeciesID);
    data >> Bits<11>(itemKey.ItemLevel);
    data >> OptionalInit(itemKey.ItemSuffix);

    if (itemKey.BattlePetSpeciesID)
        data >> *itemKey.BattlePetSpeciesID;

    if (itemKey.ItemSuffix)
        data >> *itemKey.ItemSuffix;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionBucketKey const& itemKey)
{
    data << Bits<20>(itemKey.ItemID);
    data << OptionalInit(itemKey.BattlePetSpeciesID);
    data << Bits<11>(itemKey.ItemLevel);
    data << OptionalInit(itemKey.ItemSuffix);
    data.FlushBits();

    if (itemKey.BattlePetSpeciesID)
        data << uint16(*itemKey.BattlePetSpeciesID);

    if (itemKey.ItemSuffix)
        data << uint16(*itemKey.ItemSuffix);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionListFilterSubClass& filterSubClass)
{
    data >> filterSubClass.InvTypeMask;
    data >> filterSubClass.ItemSubclass;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionListFilterClass& filterClass)
{
    data >> filterClass.ItemClass;
    data >> BitsSize<5>(filterClass.SubClassFilters);
    for (AuctionListFilterSubClass& filterSubClass : filterClass.SubClassFilters)
        data >> filterSubClass;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionSortDef& sortDef)
{
    data.ResetBitPos();
    data >> As<uint8>(sortDef.SortOrder);
    data >> Bits<1>(sortDef.ReverseSort);

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionItemForSale& auctionItemForSale)
{
    data >> auctionItemForSale.Guid;
    data >> auctionItemForSale.UseCount;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionFavoriteInfo& favoriteInfo)
{
    data >> favoriteInfo.Order;
    data >> favoriteInfo.ItemID;
    data >> favoriteInfo.ItemLevel;
    data >> favoriteInfo.BattlePetSpeciesID;
    data >> favoriteInfo.SuffixItemNameDescriptionID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionFavoriteInfo const& favoriteInfo)
{
    data << uint32(favoriteInfo.Order);
    data << uint32(favoriteInfo.ItemID);
    data << uint32(favoriteInfo.ItemLevel);
    data << uint32(favoriteInfo.BattlePetSpeciesID);
    data << uint32(favoriteInfo.SuffixItemNameDescriptionID);

    return data;
}

void AuctionOwnerNotification::Initialize(::AuctionPosting const* auction)
{
    AuctionID = auction->Id;
    Item.Initialize(auction->Items[0]);
    BidAmount = auction->BidAmount;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionOwnerNotification const& ownerNotification)
{
    data << int32(ownerNotification.AuctionID);
    data << uint64(ownerNotification.BidAmount);
    data << ownerNotification.Item;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, BucketInfo const& bucketInfo)
{
    data << bucketInfo.Key;
    data << int32(bucketInfo.TotalQuantity);
    data << int32(bucketInfo.RequiredLevel);
    data << uint64(bucketInfo.MinPrice);
    data << uint32(bucketInfo.ItemModifiedAppearanceIDs.size());
    if (!bucketInfo.ItemModifiedAppearanceIDs.empty())
        data.append(bucketInfo.ItemModifiedAppearanceIDs.data(), bucketInfo.ItemModifiedAppearanceIDs.size());

    data << OptionalInit(bucketInfo.MaxBattlePetQuality);
    data << OptionalInit(bucketInfo.MaxBattlePetLevel);
    data << OptionalInit(bucketInfo.BattlePetBreedID);
    data << OptionalInit(bucketInfo.BattlePetLevelMask);
    data << Bits<1>(bucketInfo.ContainsOwnerItem);
    data << Bits<1>(bucketInfo.ContainsOnlyCollectedAppearances);
    data.FlushBits();

    if (bucketInfo.MaxBattlePetQuality)
        data << uint8(*bucketInfo.MaxBattlePetQuality);

    if (bucketInfo.MaxBattlePetLevel)
        data << uint8(*bucketInfo.MaxBattlePetLevel);

    if (bucketInfo.BattlePetBreedID)
        data << uint8(*bucketInfo.BattlePetBreedID);

    if (bucketInfo.BattlePetLevelMask)
        data << uint32(*bucketInfo.BattlePetLevelMask);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionItem const& auctionItem)
{
    data << OptionalInit(auctionItem.Item);
    data << BitsSize<4>(auctionItem.Enchantments);
    data << BitsSize<2>(auctionItem.Gems);
    data << OptionalInit(auctionItem.MinBid);
    data << OptionalInit(auctionItem.MinIncrement);
    data << OptionalInit(auctionItem.BuyoutPrice);
    data << OptionalInit(auctionItem.UnitPrice);
    data << Bits<1>(auctionItem.CensorServerSideInfo);
    data << Bits<1>(auctionItem.CensorBidInfo);
    data << OptionalInit(auctionItem.AuctionBucketKey);
    data << OptionalInit(auctionItem.Creator);
    if (!auctionItem.CensorBidInfo)
    {
        data << OptionalInit(auctionItem.Bidder);
        data << OptionalInit(auctionItem.BidAmount);
    }

    data.FlushBits();

    if (auctionItem.Item)
        data << *auctionItem.Item;

    data << int32(auctionItem.Count);
    data << int32(auctionItem.Charges);
    data << int32(auctionItem.Flags);
    data << int32(auctionItem.AuctionID);
    data << auctionItem.Owner;
    data << int32(auctionItem.DurationLeft);
    data << uint8(auctionItem.DeleteReason);
    data << uint32(auctionItem.Unused1110);

    for (WorldPackets::Item::ItemEnchantData const& enchant : auctionItem.Enchantments)
        data << enchant;

    if (auctionItem.MinBid)
        data << uint64(*auctionItem.MinBid);

    if (auctionItem.MinIncrement)
        data << uint64(*auctionItem.MinIncrement);

    if (auctionItem.BuyoutPrice)
        data << uint64(*auctionItem.BuyoutPrice);

    if (auctionItem.UnitPrice)
        data << uint64(*auctionItem.UnitPrice);

    if (!auctionItem.CensorServerSideInfo)
    {
        data << auctionItem.ItemGuid;
        data << auctionItem.OwnerAccountID;
        data << int32(auctionItem.EndTime);
    }

    if (auctionItem.Creator)
        data << *auctionItem.Creator;

    if (!auctionItem.CensorBidInfo)
    {
        if (auctionItem.Bidder)
            data << *auctionItem.Bidder;

        if (auctionItem.BidAmount)
            data << uint64(*auctionItem.BidAmount);
    }

    for (WorldPackets::Item::ItemGemData const& gem : auctionItem.Gems)
        data << gem;

    if (auctionItem.AuctionBucketKey)
        data << *auctionItem.AuctionBucketKey;

    return data;
}

void AuctionBidderNotification::Initialize(int32 auctionHouseId, ::AuctionPosting const* auction, ::Item const* item)
{
    AuctionHouseID = auctionHouseId;
    AuctionID = auction->Id;
    Item.Initialize(item);
    Bidder = auction->Bidder;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionBidderNotification const& bidderNotification)
{
    data << int32(bidderNotification.AuctionHouseID);
    data << int32(bidderNotification.AuctionID);
    data << bidderNotification.Bidder;
    data << bidderNotification.Item;
    return data;
}

void AuctionBrowseQuery::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;
    _worldPacket >> MinLevel;
    _worldPacket >> MaxLevel;
    _worldPacket >> Unused1007_1;
    _worldPacket >> Unused1007_2;
    _worldPacket >> As<uint32>(Filters);

    uint32 knownPetsSize = _worldPacket.read<uint32>();
    uint32 const sizeLimit = sBattlePetSpeciesStore.GetNumRows() / (sizeof(decltype(KnownPets)::value_type) * 8) + 1;
    if (knownPetsSize >= sizeLimit)
        throw PacketArrayMaxCapacityException(knownPetsSize, sizeLimit);

    KnownPets.resize(knownPetsSize);
    _worldPacket >> MaxPetLevel;
    _worldPacket >> Unused1026;
    for (uint8& knownPetMask : KnownPets)
        _worldPacket >> knownPetMask;

    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> SizedString::BitsSize<8>(Name);
    _worldPacket >> BitsSize<3>(ItemClassFilters);
    _worldPacket >> BitsSize<2>(Sorts);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    _worldPacket >> SizedString::Data(Name);
    for (AuctionListFilterClass& filterClass : ItemClassFilters)
        _worldPacket >> filterClass;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionCancelCommoditiesPurchase::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> OptionalInit(TaintedBy);
    if (TaintedBy)
        _worldPacket >> *TaintedBy;
}

void AuctionConfirmCommoditiesPurchase::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ItemID;
    _worldPacket >> Quantity;
    _worldPacket >> OptionalInit(TaintedBy);
    if (TaintedBy)
        _worldPacket >> *TaintedBy;
}

void AuctionHelloRequest::Read()
{
    _worldPacket >> Guid;
}

void AuctionListBiddedItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<7>(AuctionIDs);
    _worldPacket >> BitsSize<2>(Sorts);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (uint32& auctionID : AuctionIDs)
        _worldPacket >> auctionID;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionListBucketsByBucketKeys::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<7>(BucketKeys);
    _worldPacket >> BitsSize<2>(Sorts);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionBucketKey& bucketKey : BucketKeys)
        _worldPacket >> bucketKey;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionListItemsByBucketKey::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;
    _worldPacket >> Unknown830;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<2>(Sorts);

    _worldPacket >> BucketKey;

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionListItemsByItemID::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ItemID;
    _worldPacket >> SuffixItemNameDescriptionID;
    _worldPacket >> Offset;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<2>(Sorts);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionListOwnedItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<2>(Sorts);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionPlaceBid::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> AuctionID;
    _worldPacket >> BidAmount;
    _worldPacket >> OptionalInit(TaintedBy);
    if (TaintedBy)
        _worldPacket >> *TaintedBy;
}

void AuctionRemoveItem::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> AuctionID;
    _worldPacket >> ItemID;
    _worldPacket >> OptionalInit(TaintedBy);
    if (TaintedBy)
        _worldPacket >> *TaintedBy;
}

void AuctionReplicateItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ChangeNumberGlobal;
    _worldPacket >> ChangeNumberCursor;
    _worldPacket >> ChangeNumberTombstone;
    _worldPacket >> Count;
    _worldPacket >> OptionalInit(TaintedBy);
    if (TaintedBy)
        _worldPacket >> *TaintedBy;
}

void AuctionSellCommodity::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> UnitPrice;
    _worldPacket >> RunTime;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<6>(Items);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionItemForSale& item : Items)
        _worldPacket >> item;
}

void AuctionSellItem::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> MinBid;
    _worldPacket >> BuyoutPrice;
    _worldPacket >> RunTime;
    _worldPacket >> OptionalInit(TaintedBy);
    _worldPacket >> BitsSize<6>(Items);

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionItemForSale& item : Items)
        _worldPacket >> item;
}

void AuctionSetFavoriteItem::Read()
{
    _worldPacket >> Bits<1>(IsNotFavorite);
    _worldPacket >> Item;
}

void AuctionGetCommodityQuote::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ItemID;
    _worldPacket >> Quantity;
    _worldPacket >> OptionalInit(TaintedBy);
    if (TaintedBy)
        _worldPacket >> *TaintedBy;
}

WorldPacket const* AuctionClosedNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << float(ProceedsMailDelay);
    _worldPacket << Bits<1>(Sold);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* AuctionCommandResult::Write()
{
    _worldPacket << int32(AuctionID);
    _worldPacket << int32(Command);
    _worldPacket << int32(ErrorCode);
    _worldPacket << int32(BagResult);
    _worldPacket << Guid;
    _worldPacket << uint64(MinIncrement);
    _worldPacket << uint64(Money);
    _worldPacket << uint32(DesiredDelay);

    return &_worldPacket;
}

WorldPacket const* AuctionGetCommodityQuoteResult::Write()
{
    _worldPacket << OptionalInit(TotalPrice);
    _worldPacket << OptionalInit(Quantity);
    _worldPacket << OptionalInit(QuoteDuration);
    _worldPacket << int32(ItemID);
    _worldPacket << uint32(DesiredDelay);

    if (TotalPrice)
        _worldPacket << uint64(*TotalPrice);

    if (Quantity)
        _worldPacket << uint32(*Quantity);

    if (QuoteDuration)
        _worldPacket << *QuoteDuration;

    return &_worldPacket;
}

WorldPacket const* AuctionFavoriteList::Write()
{
    _worldPacket << uint32(DesiredDelay);
    _worldPacket << BitsSize<7>(Items);
    _worldPacket.FlushBits();

    for (AuctionFavoriteInfo const& favoriteInfo : Items)
        _worldPacket << favoriteInfo;

    return &_worldPacket;
}

WorldPacket const* AuctionHelloResponse::Write()
{
    _worldPacket << Auctioneer;
    _worldPacket << uint32(PurchaseDeliveryDelay);
    _worldPacket << uint32(CancelDeliveryDelay);
    _worldPacket << int32(AuctionHouseID);
    _worldPacket << Bits<1>(OpenForBusiness);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* AuctionListBiddedItemsResult::Write()
{
    _worldPacket << uint32(Items.size());
    _worldPacket << uint32(DesiredDelay);
    _worldPacket << Bits<1>(HasMoreResults);
    _worldPacket.FlushBits();

    for (AuctionItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* AuctionListBucketsResult::Write()
{
    _worldPacket << uint32(Buckets.size());
    _worldPacket << uint32(DesiredDelay);
    _worldPacket << int32(Unknown830_0);
    _worldPacket << int32(Unknown830_1);
    _worldPacket << Bits<1>(BrowseMode);
    _worldPacket << Bits<1>(HasMoreResults);
    _worldPacket.FlushBits();

    for (BucketInfo const& bucketInfo : Buckets)
        _worldPacket << bucketInfo;

    return &_worldPacket;
}

WorldPacket const* AuctionListItemsResult::Write()
{
    {
        _worldPacket << uint32(Items.size());
        _worldPacket << uint32(Unknown830);
        _worldPacket << uint32(DesiredDelay);
        for (AuctionItem const& item : Items)
            _worldPacket << item;
    }

    {
        _worldPacket << Bits<2>(ListType);
        _worldPacket << Bits<1>(HasMoreResults);
        _worldPacket.FlushBits();

        _worldPacket << BucketKey;
        _worldPacket << uint32(TotalCount);
    }

    return &_worldPacket;
}

WorldPacket const* AuctionListOwnedItemsResult::Write()
{
    _worldPacket << int32(Items.size());
    _worldPacket << int32(SoldItems.size());
    _worldPacket << uint32(DesiredDelay);
    _worldPacket << Bits<1>(HasMoreResults);
    _worldPacket.FlushBits();

    for (AuctionItem const& item : Items)
        _worldPacket << item;

    for (AuctionItem const& item : SoldItems)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* AuctionOutbidNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << uint64(BidAmount);
    _worldPacket << uint64(MinIncrement);

    return &_worldPacket;
}

WorldPacket const* AuctionOwnerBidNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << uint64(MinIncrement);
    _worldPacket << Bidder;

    return &_worldPacket;
}

WorldPacket const* AuctionReplicateResponse::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket << uint32(DesiredDelay);
    _worldPacket << uint32(ChangeNumberGlobal);
    _worldPacket << uint32(ChangeNumberCursor);
    _worldPacket << uint32(ChangeNumberTombstone);
    _worldPacket << uint32(Items.size());

    for (AuctionItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* AuctionWonNotification::Write()
{
    _worldPacket << Info;

    return &_worldPacket;
}
}
