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

namespace WorldPackets::Loot
{
static ByteBuffer& operator<<(ByteBuffer& data, LootItemData const& lootItem)
{
    data << Bits<2>(lootItem.Type);
    data << Bits<3>(lootItem.UIType);
    data << Bits<1>(lootItem.CanTradeToTapList);
    data.FlushBits();
    data << lootItem.Loot; // WorldPackets::Item::ItemInstance
    data << uint32(lootItem.Quantity);
    data << uint8(lootItem.LootItemType);
    data << uint8(lootItem.LootListID);
    return data;
}

static ByteBuffer& operator<<(ByteBuffer& data, LootCurrency const& lootCurrency)
{
    data << uint32(lootCurrency.CurrencyID);
    data << uint32(lootCurrency.Quantity);
    data << uint8(lootCurrency.LootListID);
    data << Bits<3>(lootCurrency.UIType);
    data.FlushBits();
    return data;
}

void LootUnit::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* LootResponse::Write()
{
    _worldPacket << Owner;
    _worldPacket << LootObj;
    _worldPacket << uint8(FailureReason);
    _worldPacket << uint8(AcquireReason);
    _worldPacket << uint8(_LootMethod);
    _worldPacket << uint8(Threshold);
    _worldPacket << uint32(Coins);
    _worldPacket << uint32(Items.size());
    _worldPacket << uint32(Currencies.size());
    _worldPacket << Bits<1>(Acquired);
    _worldPacket << Bits<1>(AELooting);
    _worldPacket << Bits<1>(SuppressError);
    _worldPacket.FlushBits();

    for (LootItemData const& item : Items)
        _worldPacket << item;

    for (LootCurrency const& currency : Currencies)
        _worldPacket << currency;

    return &_worldPacket;
}

void LootItem::Read()
{
    uint32 Count;
    _worldPacket >> Count;

    Loot.resize(Count);
    for (uint32 i = 0; i < Count; ++i)
    {
        _worldPacket >> Loot[i].Object;
        _worldPacket >> Loot[i].LootListID;
    }

    _worldPacket >> Bits<1>(IsSoftInteract);
}

void MasterLootItem::Read()
{
    uint32 Count;
    _worldPacket >> Count;
    _worldPacket >> Target;

    Loot.resize(Count);
    for (uint32 i = 0; i < Count; ++i)
    {
        _worldPacket >> Loot[i].Object;
        _worldPacket >> Loot[i].LootListID;
    }
}

WorldPacket const* LootRemoved::Write()
{
    _worldPacket << Owner;
    _worldPacket << LootObj;
    _worldPacket << LootListID;

    return &_worldPacket;
}

void LootRelease::Read()
{
    _worldPacket >> Unit;
}

void LootMoney::Read()
{
    _worldPacket >> Bits<1>(IsSoftInteract);
}

WorldPacket const* LootMoneyNotify::Write()
{
    _worldPacket << uint64(Money);
    _worldPacket << uint64(MoneyMod);
    _worldPacket << Bits<1>(SoleLooter);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* CoinRemoved::Write()
{
    _worldPacket << LootObj;

    return &_worldPacket;
}

void LootRoll::Read()
{
    _worldPacket >> LootObj;
    _worldPacket >> LootListID;
    _worldPacket >> RollType;
}

WorldPacket const* LootReleaseResponse::Write()
{
    _worldPacket << LootObj;
    _worldPacket << Owner;

    return &_worldPacket;
}

WorldPacket const* LootList::Write()
{
    _worldPacket << Owner;
    _worldPacket << LootObj;

    _worldPacket << OptionalInit(Master);
    _worldPacket << OptionalInit(RoundRobinWinner);

    _worldPacket.FlushBits();

    if (Master)
        _worldPacket << *Master;

    if (RoundRobinWinner)
        _worldPacket << *RoundRobinWinner;

    return &_worldPacket;
}

void SetLootSpecialization::Read()
{
    _worldPacket >> SpecID;
}

WorldPacket const* StartLootRoll::Write()
{
    _worldPacket << LootObj;
    _worldPacket << int32(MapID);
    _worldPacket << RollTime;
    _worldPacket << uint8(ValidRolls);
    _worldPacket.append(LootRollIneligibleReason.data(), LootRollIneligibleReason.size());
    _worldPacket << uint8(Method);
    _worldPacket << int32(DungeonEncounterID);
    _worldPacket << Item;

    return &_worldPacket;
}

WorldPacket const* LootRollBroadcast::Write()
{
    _worldPacket << LootObj;
    _worldPacket << Player;
    _worldPacket << int32(Roll);
    _worldPacket << uint8(RollType);
    _worldPacket << int32(DungeonEncounterID);
    _worldPacket << Item;
    _worldPacket << Bits<1>(Autopassed);
    _worldPacket << Bits<1>(OffSpec);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* LootRollWon::Write()
{
    _worldPacket << LootObj;
    _worldPacket << Winner;
    _worldPacket << int32(Roll);
    _worldPacket << uint8(RollType);
    _worldPacket << int32(DungeonEncounterID);
    _worldPacket << Item;
    _worldPacket << Bits<1>(MainSpec);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* LootAllPassed::Write()
{
    _worldPacket << LootObj;
    _worldPacket << int32(DungeonEncounterID);
    _worldPacket << Item;

    return &_worldPacket;
}

WorldPacket const* LootRollsComplete::Write()
{
    _worldPacket << LootObj;
    _worldPacket << uint8(LootListID);
    _worldPacket << int32(DungeonEncounterID);

    return &_worldPacket;
}

WorldPacket const* MasterLootCandidateList::Write()
{
    _worldPacket << LootObj;
    _worldPacket << uint32(Players.size());
    for (ObjectGuid const& player : Players)
        _worldPacket << player;

    return &_worldPacket;
}

WorldPacket const* AELootTargets::Write()
{
    _worldPacket << uint32(Count);

    return &_worldPacket;
}
}
