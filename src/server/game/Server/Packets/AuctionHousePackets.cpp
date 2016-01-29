/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectGuid.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::AuctionHouse::AuctionItem const& auctionItem)
{
    data << auctionItem.Item; // ItemInstance
    data << int32(auctionItem.Count);
    data << int32(auctionItem.Charges);
    data << int32(auctionItem.Enchantments.size());
    data << int32(auctionItem.Flags);
    data << int32(auctionItem.AuctionItemID);
    data << auctionItem.Owner;
    data << uint64(auctionItem.MinBid);
    data << uint64(auctionItem.MinIncrement);
    data << uint64(auctionItem.BuyoutPrice);
    data << int32(auctionItem.DurationLeft);
    data << uint8(auctionItem.DeleteReason);

    for (auto const& enchant : auctionItem.Enchantments)
    {
        data << int32(enchant.ID);
        data << uint32(enchant.Expiration);
        data << int32(enchant.Charges);
        data << uint8(enchant.Slot);
    }

    data.FlushBits();

    bool censorServerSideInfo = !data.WriteBit(auctionItem.CensorServerSideInfo);
    bool censorBidInfo = !data.WriteBit(auctionItem.CensorBidInfo);

    if (censorServerSideInfo)
    {
        data << auctionItem.ItemGuid;
        data << auctionItem.OwnerAccountID;
        data << int32(auctionItem.EndTime);
    }

    if (censorBidInfo)
    {
        data << auctionItem.Bidder;
        data << uint64(auctionItem.BidAmount);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::AuctionHouse::AuctionOwnerNotification const& ownerNotification)
{
    data << int32(ownerNotification.AuctionItemID);
    data << uint64(ownerNotification.BidAmount);
    data << ownerNotification.Item;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::AuctionHouse::AuctionBidderNotification const& bidderNotification)
{
    data << int32(bidderNotification.AuctionItemID);
    data << bidderNotification.Bidder;
    data << bidderNotification.Item;
    return data;
}

void WorldPackets::AuctionHouse::AuctionOwnerNotification::Initialize(::AuctionEntry const* auction, ::Item const* item)
{
    AuctionItemID = auction->Id;
    Item.Initialize(item);
    BidAmount = auction->bid;
}

void WorldPackets::AuctionHouse::AuctionBidderNotification::Initialize(::AuctionEntry const* auction, ::Item const* item)
{
    AuctionItemID = auction->Id;
    Item.Initialize(item);
    Bidder = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
}

void WorldPackets::AuctionHouse::AuctionHelloRequest::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionHelloResponse::Write()
{
    _worldPacket << Guid;
    _worldPacket.WriteBit(OpenForBusiness);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPackets::AuctionHouse::AuctionCommandResult::AuctionCommandResult()
    : ServerPacket(SMSG_AUCTION_COMMAND_RESULT, 4 + 4 + 4 + 8 + 4 + 8 + 8 + 8) { }

void WorldPackets::AuctionHouse::AuctionCommandResult::InitializeAuction(::AuctionEntry* auction)
{
    if (auction)
    {
        AuctionItemID   = auction->Id;
        Money           = auction->bid == auction->buyout ? 0 : auction->bid;
        MinIncrement    = auction->bid == auction->buyout ? 0 : auction->GetAuctionOutBid();
        Guid            = ObjectGuid::Create<HighGuid::Player>(auction->bidder);
    }
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionCommandResult::Write()
{
    _worldPacket << uint32(AuctionItemID);
    _worldPacket << int32(Command);
    _worldPacket << int32(ErrorCode);
    _worldPacket << int32(BagResult);
    _worldPacket << Guid;
    _worldPacket << uint64(MinIncrement);
    _worldPacket << uint64(Money);

    return &_worldPacket;
}

void WorldPackets::AuctionHouse::AuctionSellItem::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> MinBid;
    _worldPacket >> BuyoutPrice;
    _worldPacket >> RunTime;

    uint8 ItemsCount = _worldPacket.ReadBits(5);
    _worldPacket.FlushBits();

    for (uint8 i = 0; i < ItemsCount; i++)
    {
        WorldPackets::AuctionHouse::AuctionSellItem::AuctionItemForSale item;
        _worldPacket >> item.Guid;
        _worldPacket >> item.UseCount;
        Items.emplace_back(item);
    }
}

void WorldPackets::AuctionHouse::AuctionPlaceBid::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> AuctionItemID;
    _worldPacket >> BidAmount;
}

void WorldPackets::AuctionHouse::AuctionListBidderItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;
    uint8 auctionItemIDsCount = _worldPacket.ReadBits(7);
    _worldPacket.FlushBits();

    for (uint8 i = 0; i < auctionItemIDsCount; i++)
    {
        uint32 AuctionItemID = 0;
        _worldPacket >> AuctionItemID;
        AuctionItemIDs.emplace_back(AuctionItemID);
    }
}

void WorldPackets::AuctionHouse::AuctionRemoveItem::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> AuctionItemID;
}

void WorldPackets::AuctionHouse::AuctionReplicateItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Count;
    _worldPacket >> ChangeNumberGlobal;
    _worldPacket >> ChangeNumberCursor;
    _worldPacket >> ChangeNumberTombstone;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionListItemsResult::Write()
{
    _worldPacket << int32(Items.size());
    _worldPacket << int32(TotalCount);
    _worldPacket << int32(DesiredDelay);

    for (auto const& item : Items)
        _worldPacket << item;

    _worldPacket.FlushBits();
    _worldPacket.WriteBit(OnlyUsable);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionListOwnerItemsResult::Write()
{
    _worldPacket << int32(Items.size());
    _worldPacket << uint32(TotalCount);
    _worldPacket << uint32(DesiredDelay);

    for (auto const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionListBidderItemsResult::Write()
{
    _worldPacket << int32(Items.size());
    _worldPacket << uint32(TotalCount);
    _worldPacket << uint32(DesiredDelay);

    for (auto const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

void WorldPackets::AuctionHouse::AuctionListItems::Read()
{
    _worldPacket >> Offset;
    _worldPacket >> Auctioneer;
    _worldPacket >> MinLevel;
    _worldPacket >> MaxLevel;
    _worldPacket >> InvType;
    _worldPacket >> ItemClass;
    _worldPacket >> ItemSubclass;
    _worldPacket >> Quality;
    _worldPacket >> SortCount;

    _worldPacket.FlushBits();
    uint32 nameLength = _worldPacket.ReadBits(8);
    Name = _worldPacket.ReadString(nameLength);
    OnlyUsable = _worldPacket.ReadBit();
    ExactMatch = _worldPacket.ReadBit();

    _worldPacket.read_skip<uint32>(); // DataSize = (SortCount * 2)
    for (int32 i = 0; i < SortCount; i++)
    {
        WorldPackets::AuctionHouse::AuctionListItems::Sort sort;
        _worldPacket >> sort.UnkByte1;
        _worldPacket >> sort.UnkByte2;
        DataSort.emplace_back(sort);
    }
}

void WorldPackets::AuctionHouse::AuctionListOwnerItems::Read()
{
    _worldPacket >> Auctioneer;
    _worldPacket >> Offset;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionListPendingSalesResult::Write()
{
    _worldPacket << int32(Mails.size());
    _worldPacket << int32(TotalNumRecords);

    for (auto const& mail : Mails)
        _worldPacket << mail;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionClosedNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << float(ProceedsMailDelay);
    _worldPacket.WriteBit(Sold);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionOwnerBidNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << uint64(MinIncrement);
    _worldPacket << Bidder;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionWonNotification::Write()
{
    _worldPacket << Info;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionOutBidNotification::Write()
{
    _worldPacket << Info;
    _worldPacket << uint64(BidAmount);
    _worldPacket << uint64(MinIncrement);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::AuctionHouse::AuctionReplicateResponse::Write()
{
    //Todo order
    _worldPacket << int32(ChangeNumberCursor);
    _worldPacket << int32(ChangeNumberGlobal);
    _worldPacket << int32(DesiredDelay);
    _worldPacket << int32(ChangeNumberTombstone);
    _worldPacket << int32(Result);
    _worldPacket << int32(Items.size());

    for (auto const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}
