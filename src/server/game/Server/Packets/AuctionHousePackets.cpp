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

namespace WorldPackets
{
namespace AuctionHouse
{
AuctionBucketKey& AuctionBucketKey::operator=(AuctionsBucketKey const& key)
{
    ItemID = key.ItemId;
    ItemLevel = key.ItemLevel;

    if (key.BattlePetSpeciesId)
        BattlePetSpeciesID = key.BattlePetSpeciesId;

    if (key.SuffixItemNameDescriptionId)
        SuffixItemNameDescriptionID = key.SuffixItemNameDescriptionId;

    return *this;
}

ByteBuffer& operator>>(ByteBuffer& data, AuctionBucketKey& itemKey)
{
    data.ResetBitPos();
    itemKey.ItemID = data.ReadBits(20);

    if (data.ReadBit())
        itemKey.BattlePetSpeciesID.emplace();

    itemKey.ItemLevel = data.ReadBits(11);

    if (data.ReadBit())
        itemKey.SuffixItemNameDescriptionID.emplace();

    if (itemKey.BattlePetSpeciesID)
        data >> *itemKey.BattlePetSpeciesID;

    if (itemKey.SuffixItemNameDescriptionID)
        data >> *itemKey.SuffixItemNameDescriptionID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionBucketKey const& itemKey)
{
    data.WriteBits(itemKey.ItemID, 20);
    data.WriteBit(itemKey.BattlePetSpeciesID.has_value());
    data.WriteBits(itemKey.ItemLevel, 11);
    data.WriteBit(itemKey.SuffixItemNameDescriptionID.has_value());
    data.FlushBits();

    if (itemKey.BattlePetSpeciesID)
        data << uint16(*itemKey.BattlePetSpeciesID);

    if (itemKey.SuffixItemNameDescriptionID)
        data << uint16(*itemKey.SuffixItemNameDescriptionID);

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
    filterClass.SubClassFilters.resize(data.ReadBits(5));
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

    data.WriteBit(bucketInfo.MaxBattlePetQuality.has_value());
    data.WriteBit(bucketInfo.MaxBattlePetLevel.has_value());
    data.WriteBit(bucketInfo.BattlePetBreedID.has_value());
    data.WriteBit(bucketInfo.Unk901_1.has_value());
    data.WriteBit(bucketInfo.ContainsOwnerItem);
    data.WriteBit(bucketInfo.ContainsOnlyCollectedAppearances);
    data.FlushBits();

    if (bucketInfo.MaxBattlePetQuality)
        data << uint8(*bucketInfo.MaxBattlePetQuality);

    if (bucketInfo.MaxBattlePetLevel)
        data << uint8(*bucketInfo.MaxBattlePetLevel);

    if (bucketInfo.BattlePetBreedID)
        data << uint8(*bucketInfo.BattlePetBreedID);

    if (bucketInfo.Unk901_1)
        data << uint32(*bucketInfo.Unk901_1);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionItem const& auctionItem)
{
    data.WriteBit(auctionItem.Item.has_value());
    data.WriteBits(auctionItem.Enchantments.size(), 4);
    data.WriteBits(auctionItem.Gems.size(), 2);
    data.WriteBit(auctionItem.MinBid.has_value());
    data.WriteBit(auctionItem.MinIncrement.has_value());
    data.WriteBit(auctionItem.BuyoutPrice.has_value());
    data.WriteBit(auctionItem.UnitPrice.has_value());
    data.WriteBit(auctionItem.CensorServerSideInfo);
    data.WriteBit(auctionItem.CensorBidInfo);
    data.WriteBit(auctionItem.AuctionBucketKey.has_value());
    data.WriteBit(auctionItem.Creator.has_value());
    if (!auctionItem.CensorBidInfo)
    {
        data.WriteBit(auctionItem.Bidder.has_value());
        data.WriteBit(auctionItem.BidAmount.has_value());
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

void AuctionBidderNotification::Initialize(::AuctionPosting const* auction, ::Item const* item)
{
    AuctionID = auction->Id;
    Item.Initialize(item);
    Bidder = auction->Bidder;
}

ByteBuffer& operator<<(ByteBuffer& data, AuctionBidderNotification const& bidderNotification)
{
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
    Filters = _worldPacket.read<AuctionHouseFilterMask, uint32>();

    uint32 knownPetsSize = _worldPacket.read<uint32>();
    uint32 const sizeLimit = sBattlePetSpeciesStore.GetNumRows() / (sizeof(decltype(KnownPets)::value_type) * 8) + 1;
    if (knownPetsSize >= sizeLimit)
        throw PacketArrayMaxCapacityException(knownPetsSize, sizeLimit);

    KnownPets.resize(knownPetsSize);
    _worldPacket >> MaxPetLevel;
    _worldPacket >> Unused1026;
    for (uint8& knownPetMask : KnownPets)
        _worldPacket >> knownPetMask;

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    uint32 nameLength = _worldPacket.ReadBits(8);
    ItemClassFilters.resize(_worldPacket.ReadBits(3));
    Sorts.resize(_worldPacket.ReadBits(2));

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    Name = _worldPacket.ReadString(nameLength);
    for (AuctionListFilterClass& filterClass : ItemClassFilters)
        _worldPacket >> filterClass;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionCancelCommoditiesPurchase::Read()
{
    _worldPacket >> Auctioneer;
    if (_worldPacket.ReadBit())
    {
        TaintedBy.emplace();
        _worldPacket >> *TaintedBy;
    }
}

void AuctionConfirmCommoditiesPurchase::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ItemID;
    _worldPacket >> Quantity;
    if (_worldPacket.ReadBit())
    {
        TaintedBy.emplace();
        _worldPacket >> *TaintedBy;
    }
}

void AuctionHelloRequest::Read()
{
    _worldPacket >> Guid;
}

void AuctionListBiddedItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    AuctionIDs.resize(_worldPacket.ReadBits(7));
    Sorts.resize(_worldPacket.ReadBits(2));

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

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    BucketKeys.resize(_worldPacket.ReadBits(7));
    Sorts.resize(_worldPacket.ReadBits(2));

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

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    Sorts.resize(_worldPacket.ReadBits(2));

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

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    Sorts.resize(_worldPacket.ReadBits(2));

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionSortDef& sortDef : Sorts)
        _worldPacket >> sortDef;
}

void AuctionListOwnedItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    Sorts.resize(_worldPacket.ReadBits(2));

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
    if (_worldPacket.ReadBit())
    {
        TaintedBy.emplace();
        _worldPacket >> *TaintedBy;
    }
}

void AuctionRemoveItem::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> AuctionID;
    _worldPacket >> ItemID;
    if (_worldPacket.ReadBit())
    {
        TaintedBy.emplace();
        _worldPacket >> *TaintedBy;
    }
}

void AuctionReplicateItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ChangeNumberGlobal;
    _worldPacket >> ChangeNumberCursor;
    _worldPacket >> ChangeNumberTombstone;
    _worldPacket >> Count;
    if (_worldPacket.ReadBit())
    {
        TaintedBy.emplace();
        _worldPacket >> *TaintedBy;
    }
}

void AuctionSellCommodity::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> UnitPrice;
    _worldPacket >> RunTime;

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    Items.resize(_worldPacket.ReadBits(6));

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

    if (_worldPacket.ReadBit())
        TaintedBy.emplace();

    Items.resize(_worldPacket.ReadBits(6));

    if (TaintedBy)
        _worldPacket >> *TaintedBy;

    for (AuctionItemForSale& item : Items)
        _worldPacket >> item;
}

void AuctionSetFavoriteItem::Read()
{
    IsNotFavorite = _worldPacket.ReadBit();
    _worldPacket >> Item;
}

void AuctionGetCommodityQuote::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> ItemID;
    _worldPacket >> Quantity;
    if (_worldPacket.ReadBit())
    {
        TaintedBy.emplace();
        _worldPacket >> *TaintedBy;
    }
}

WorldPacket const* AuctionClosedNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << float(ProceedsMailDelay);
    _worldPacket.WriteBit(Sold);
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
    _worldPacket.WriteBit(TotalPrice.has_value());
    _worldPacket.WriteBit(Quantity.has_value());
    _worldPacket.WriteBit(QuoteDuration.has_value());
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
    _worldPacket.WriteBits(Items.size(), 7);
    _worldPacket.FlushBits();

    for (AuctionFavoriteInfo const& favoriteInfo : Items)
        _worldPacket << favoriteInfo;

    return &_worldPacket;
}

WorldPacket const* AuctionHelloResponse::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(PurchasedItemDeliveryDelay);
    _worldPacket << uint32(CancelledItemDeliveryDelay);
    _worldPacket.WriteBit(OpenForBusiness);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* AuctionListBiddedItemsResult::Write()
{
    _worldPacket << uint32(Items.size());
    _worldPacket << uint32(DesiredDelay);
    _worldPacket.WriteBit(HasMoreResults);
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
    _worldPacket.WriteBits(AsUnderlyingType(BrowseMode), 1);
    _worldPacket.WriteBit(HasMoreResults);
    _worldPacket.FlushBits();

    for (BucketInfo const& bucketInfo : Buckets)
        _worldPacket << bucketInfo;

    return &_worldPacket;
}

WorldPacket const* AuctionListItemsResult::Write()
{
    _worldPacket << uint32(Items.size());
    _worldPacket << uint32(Unknown830);
    _worldPacket << uint32(TotalCount);
    _worldPacket << uint32(DesiredDelay);
    _worldPacket.WriteBits(AsUnderlyingType(ListType), 2);
    _worldPacket.WriteBit(HasMoreResults);
    _worldPacket.FlushBits();

    _worldPacket << BucketKey;

    for (AuctionItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* AuctionListOwnedItemsResult::Write()
{
    _worldPacket << int32(Items.size());
    _worldPacket << int32(SoldItems.size());
    _worldPacket << uint32(DesiredDelay);
    _worldPacket.WriteBit(HasMoreResults);
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
}
