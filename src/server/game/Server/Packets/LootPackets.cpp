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

#include "LootPackets.h"
#include "ItemPacketsCommon.h"

WorldPacket const* WorldPackets::Loot::LootMoneyNotify::Write()
{
    _worldPacket << uint32(Money);
    _worldPacket << uint8(SoleLooter);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::LootRemoved::Write()
{
    _worldPacket << uint8(LootListID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::LootReleaseResponse::Write()
{
    _worldPacket << LootObj;
    _worldPacket << uint8(UnkBool);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::LootList::Write()
{
    _worldPacket << Owner;
    _worldPacket << Master.WriteAsPacked();
    _worldPacket << RoundRobinWinner.WriteAsPacked();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::DisenchantCredit::Write()
{
    _worldPacket.WriteBit(Disenchanter[0]);
    _worldPacket.WriteBit(Disenchanter[6]);
    _worldPacket.WriteBit(Disenchanter[3]);
    _worldPacket.WriteBit(Disenchanter[1]);
    _worldPacket.WriteBit(Disenchanter[7]);
    _worldPacket.WriteBit(Disenchanter[5]);
    _worldPacket.WriteBit(Disenchanter[2]);
    _worldPacket.WriteBit(Disenchanter[4]);

    _worldPacket << int32(Item.ItemID);

    _worldPacket.WriteByteSeq(Disenchanter[4]);
    _worldPacket.WriteByteSeq(Disenchanter[1]);

    _worldPacket << int32(Item.RandomPropertiesID);
    _worldPacket << int32(Item.RandomPropertiesSeed);

    _worldPacket.WriteByteSeq(Disenchanter[6]);
    _worldPacket.WriteByteSeq(Disenchanter[5]);
    _worldPacket.WriteByteSeq(Disenchanter[2]);
    _worldPacket.WriteByteSeq(Disenchanter[7]);
    _worldPacket.WriteByteSeq(Disenchanter[3]);
    _worldPacket.WriteByteSeq(Disenchanter[0]);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Loot::LootItemData const& lootItemData)
{
    data << uint8(lootItemData.LootListID);
    data << uint32(lootItemData.Loot.ItemID);
    data << uint32(lootItemData.Quantity);
    data << int32(lootItemData.Loot.ItemDisplayID);
    data << int32(lootItemData.Loot.RandomPropertiesSeed);
    data << int32(lootItemData.Loot.RandomPropertiesID);
    data << uint8(lootItemData.UIType);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Loot::LootCurrency const& lootCurrency)
{
    data << uint8(lootCurrency.LootListID);
    data << uint32(lootCurrency.CurrencyID);
    data << uint32(lootCurrency.Quantity);

    return data;
}

WorldPacket const* WorldPackets::Loot::LootResponse::Write()
{
    _worldPacket << Owner;
    _worldPacket << uint8(AcquireReason);
    if (!AcquireReason)
    {
        _worldPacket << uint8(FailureReason);
        return &_worldPacket;
    }

    _worldPacket << uint32(Coins);
    _worldPacket << uint8(Items.size());
    _worldPacket << uint8(Currencies.size());

    for (LootItemData const& lootItemData : Items)
        _worldPacket << lootItemData;

    for (LootCurrency const& lootCurrency : Currencies)
        _worldPacket << lootCurrency;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::LootContents::Write()
{
    _worldPacket.WriteBits(Items.size(), 21);
    _worldPacket.FlushBits();

    for (LootItemData const& lootItem : Items)
    {
        _worldPacket << uint32(lootItem.Loot.ItemDisplayID);
        _worldPacket << int32(lootItem.Loot.RandomPropertiesSeed);
        _worldPacket << int32(lootItem.Quantity);
        _worldPacket << uint32(lootItem.Loot.ItemID);
        _worldPacket << int32(lootItem.Loot.RandomPropertiesID);
    }

    return &_worldPacket;
}
