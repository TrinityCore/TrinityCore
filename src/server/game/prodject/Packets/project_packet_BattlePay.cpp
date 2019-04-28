#include "project_packet_BattlePay.h"

namespace PROJECT {
namespace Packets {
namespace BattlePay {

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::BattlePay::DisplayInfoStruct const& displayInfo)
{
    data.WriteBit(displayInfo.CreatureDisplayInfoID != 0);
    data.WriteBit(displayInfo.FileDataID != 0);

    data.WriteBits(displayInfo.Name1.size(), 10);
    data.WriteBits(displayInfo.Name3.size(), 10);
    data.WriteBits(displayInfo.Description.size(), 13);
    data.WriteBits(displayInfo.Description2.size(), 13);

    data.WriteBit(displayInfo.Flags != 0);
    data.WriteBit(displayInfo.Flags2 != 0);
    data.WriteBit(displayInfo.Flags3 != 0);
    data.WriteBit(displayInfo.Flags4 != 0);
    data.FlushBits();

    data << uint32(displayInfo.UnkBfa.size());

    if (displayInfo.CreatureDisplayInfoID)
        data << displayInfo.CreatureDisplayInfoID;

    if (displayInfo.FileDataID)
        data << displayInfo.FileDataID;

    data.WriteString(displayInfo.Name1);
    data.WriteString(displayInfo.Name3);
    data.WriteString(displayInfo.Description);
    data.WriteString(displayInfo.Description2);

    if (displayInfo.Flags)
        data << displayInfo.Flags;

    if (displayInfo.Flags2)
        data << displayInfo.Flags2;

    if (displayInfo.Flags3)
        data << displayInfo.Flags3;

    if (displayInfo.Flags4)
        data << displayInfo.Flags4;

    for (auto const& item : displayInfo.UnkBfa)
    {
        data.WriteBits(item.Unk3.length(), 10);
        data.FlushBits();

        data << uint32(item.Unk1);
        data << uint32(item.Unk2);
        data.WriteString(item.Unk3);
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::BattlePay::Purchase const& purchase)
{
    data << purchase.PurchaseID;
    data << purchase.Status;
    data << purchase.ResultCode;
    data << purchase.ProductId;

    data.WriteBits(purchase.WalletName.size(), 8);
    data.FlushBits();
    data.WriteString(purchase.WalletName);

    return data;
}

void StartPurchase::Read()
{
    _worldPacket >> ClientToken;
    _worldPacket >> ProductID;
    _worldPacket >> TargetCharacter;
    uint32 len1 = _worldPacket.ReadBits(6);
    uint32 len2 = _worldPacket.ReadBits(12);
    Unk1 = _worldPacket.ReadString(len1);
    Unk2 = _worldPacket.ReadString(len2);
}

void ConfirmPurchaseResponse::Read()
{
    ConfirmPurchase = _worldPacket.ReadBit();
    _worldPacket >> ServerToken;
    _worldPacket >> ClientCurrentPriceFixedPoint;
}

void AckFailedResponse::Read()
{
    _worldPacket >> ServerToken;
}

WorldPacket const* GetProductListResponse::Write()
{
    _worldPacket << Result;
    _worldPacket << CurrencyID;

    _worldPacket << uint32(Products.size());
    _worldPacket << uint32(Products.size()); // ProductItems
    _worldPacket << uint32(Groups.size());
    _worldPacket << uint32(ShopEntries.size());

    for (auto product : Products)
    {
        _worldPacket << product.ID;
        _worldPacket << uint64(product.NormalPrice);
        _worldPacket << uint64(product.CurrentPrice);
        
        _worldPacket << uint32(1); // countProductItems, we always send only 1 product item for each product
        _worldPacket << uint32(product.Flags);
        _worldPacket << uint32(0); //UnkBfa
        //for (countProductItems)
            _worldPacket << uint32(product.ID); // actually it's ProductItem ID, no idea what's that used for

            //for(UnkBfa)
            //_worldpacket << uint32(int);

        _worldPacket.WriteBits(product.Type, 7);

        _worldPacket.WriteBit(product.DisplayInfo.HasDisplayInfo());

        _worldPacket.FlushBits();

        if (product.DisplayInfo.HasDisplayInfo())
            _worldPacket << product.DisplayInfo;
    }

    for (PROJECT::BattlePay::Product product : Products)
    {
        _worldPacket << product.ID;
        _worldPacket << uint8(2);
        _worldPacket << uint32(0);
        _worldPacket << uint32(0);
        _worldPacket << uint32(0);
        _worldPacket << product.ItemID; // ?
        _worldPacket << uint32(2);
        _worldPacket << uint32(0);
        _worldPacket << uint8(0);

        _worldPacket.WriteBit(product.HasProduct());
        _worldPacket.WriteBit(product.PetResult != 0);
        _worldPacket.WriteBits(0, 7); // unkCountProductItem
        _worldPacket.WriteBit(0); // HasDisplayInfo

        if (product.PetResult != 0)
            _worldPacket.WriteBits(product.PetResult, 4);

        _worldPacket.FlushBits();

        // for (unkCountProductItem)

        //if (product.DisplayInfo.HasDisplayInfo())
        //    _worldPacket << product.DisplayInfo;
    }

    for (auto group : Groups)
    {
        _worldPacket << group.GroupID;
        _worldPacket << group.IconFileDataID;
        _worldPacket << group.DisplayType;
        _worldPacket << group.Ordering;
        _worldPacket << group.UnkBfa;

        _worldPacket.WriteBits(group.Name.size(), 8);
        _worldPacket.WriteBits(group.Description.size(), 24);
        _worldPacket.FlushBits();
        _worldPacket.WriteString(group.Name);
        if (group.Description.size() > 1)
            _worldPacket.WriteString(group.Description);
    }

    for (auto shopEntry : ShopEntries)
    {
        _worldPacket << shopEntry.EntryID;
        _worldPacket << shopEntry.GroupID;
        _worldPacket << shopEntry.ProductID;
        _worldPacket << shopEntry.Ordering;
        _worldPacket << shopEntry.Flags;
        _worldPacket << shopEntry.BannerType;
        _worldPacket.WriteBit(shopEntry.DisplayInfo.HasDisplayInfo());
        _worldPacket.FlushBits();
        if (shopEntry.DisplayInfo.HasDisplayInfo())
            _worldPacket << shopEntry.DisplayInfo;
    }

    return &_worldPacket;
}

WorldPacket const* GetPurchaseListResponse::Write()
{
    _worldPacket << Result;
    _worldPacket << uint32(Purchases.size());

    for (auto purchase : Purchases)
        _worldPacket << purchase;

    return &_worldPacket;
}

WorldPacket const* GetDistributionListResponse::Write()
{
    _worldPacket << Result;
    _worldPacket.WriteBits(DistributionObjects.size(), 11);
    _worldPacket.FlushBits();

    //for (auto distributionObject : DistributionObjects)
    //    _worldPacket << distributionObject;

    return &_worldPacket;
}

WorldPacket const* StartPurchaseResponse::Write()
{
    _worldPacket << PurchaseID;
    _worldPacket << ClientToken;
    _worldPacket << PurchaseResult;
    
    return &_worldPacket;
}

WorldPacket const* ConfirmPurchase::Write()
{
    _worldPacket << PurchaseID;
    _worldPacket << CurrentPriceFixedPoint;
    _worldPacket << ServerToken;

    return &_worldPacket;
}

WorldPacket const* PurchaseUpdate::Write()
{
    _worldPacket << uint32(Purchases.size());
    for (auto purchase : Purchases)
        _worldPacket << purchase;

    return &_worldPacket;
}

WorldPacket const* DeliveryEnded::Write()
{
    _worldPacket << DistributionID;
    _worldPacket << uint32(Items.size());
    for (auto item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* AckFailed::Write()
{
    _worldPacket << PurchaseID;
    _worldPacket << ServerToken;
    _worldPacket << Status;
    _worldPacket << Result;

    return &_worldPacket;
}

} // BattlePay
} // Packets
} // PROJECT
