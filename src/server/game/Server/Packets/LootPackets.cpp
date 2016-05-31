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

#include "LootPackets.h"

void WorldPackets::Loot::LootUnit::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* WorldPackets::Loot::LootResponse::Write()
{
    _worldPacket << LootObj;
    _worldPacket << Owner;
    _worldPacket << FailureReason;
    _worldPacket << AcquireReason;
    _worldPacket << LootMethod;
    _worldPacket << Threshold;
    _worldPacket << Coins;
    _worldPacket << uint32(Items.size());
    _worldPacket << uint32(Currencies.size());

    for (LootItemData const& item : Items)
    {
        _worldPacket.WriteBits(item.Type, 2);
        _worldPacket.WriteBits(item.UIType, 3);
        _worldPacket.WriteBit(item.CanTradeToTapList);
        _worldPacket.FlushBits();

        _worldPacket << item.Quantity;
        _worldPacket << item.LootItemType;
        _worldPacket << item.LootListID;
        _worldPacket << item.Loot; // WorldPackets::Item::ItemInstance
    }

    for (LootCurrency const& currency : Currencies)
    {
        _worldPacket << currency.CurrencyID;
        _worldPacket << currency.Quantity;
        _worldPacket << currency.LootListID;
        _worldPacket.WriteBits(currency.UIType, 3);
        _worldPacket.FlushBits();
    }

    _worldPacket.WriteBit(Acquired);
    _worldPacket.WriteBit(AELooting);
    _worldPacket.WriteBit(PersonalLooting);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Loot::LootItem::Read()
{
    uint32 Count;
    _worldPacket >> Count;

    Loot.resize(Count);
    for (uint32 i = 0; i < Count; ++i)
    {
        _worldPacket >> Loot[i].Object;
        _worldPacket >> Loot[i].LootListID;
    }
}

WorldPacket const* WorldPackets::Loot::LootRemoved::Write()
{
    _worldPacket << Owner;
    _worldPacket << LootObj;
    _worldPacket << LootListID;

    return &_worldPacket;
}

void WorldPackets::Loot::LootRelease::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* WorldPackets::Loot::LootMoneyNotify::Write()
{
    _worldPacket << Money;
    _worldPacket.WriteBit(SoleLooter);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::CoinRemoved::Write()
{
    _worldPacket << LootObj;

    return &_worldPacket;
}

void WorldPackets::Loot::LootRoll::Read()
{
    _worldPacket >> LootObj;
    _worldPacket >> LootListID;
    _worldPacket >> RollType;
}

WorldPacket const* WorldPackets::Loot::LootReleaseResponse::Write()
{
    _worldPacket << LootObj;
    _worldPacket << Owner;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Loot::LootList::Write()
{
    _worldPacket << Owner;

    _worldPacket.WriteBit(Master.is_initialized());
    _worldPacket.WriteBit(RoundRobinWinner.is_initialized());

    _worldPacket.FlushBits();

    if (Master)
        _worldPacket << *Master;

    if (RoundRobinWinner)
        _worldPacket << *RoundRobinWinner;

    return &_worldPacket;
}

void WorldPackets::Loot::SetLootSpecialization::Read()
{
    _worldPacket >> SpecID;
}
