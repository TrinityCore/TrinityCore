/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "GuildPackets.h"

void WorldPackets::Guild::GuildBankActivate::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> FullUpdate;
}

void WorldPackets::Guild::GuildBankQueryTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Tab;
    _worldPacket >> FullUpdate;
}

void WorldPackets::Guild::GuildBankBuyTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
}

void WorldPackets::Guild::GuildBankUpdateTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> Name;
    _worldPacket >> Icon;
}

WorldPacket const* WorldPackets::Guild::GuildBankQueryResults::Write()
{
    _worldPacket.WriteBit(FullUpdate);
    _worldPacket.WriteBits(ItemInfo.size(), 20);
    _worldPacket.WriteBits(TabInfo.size(), 22);

    for (GuildBankItemInfo const& item : ItemInfo)
    {
        _worldPacket.WriteBit(item.Locked);
        _worldPacket.WriteBits(item.SocketEnchant.size(), 23);
    }

    for (GuildBankTabInfo const& tab : TabInfo)
    {
        _worldPacket.WriteBits(tab.Icon.length(), 9);
        _worldPacket.WriteBits(tab.Name.length(), 7);
    }

    _worldPacket.FlushBits();

    for (GuildBankTabInfo const& tab : TabInfo)
    {
        _worldPacket.WriteString(tab.Icon);
        _worldPacket << uint32(tab.TabIndex);
        _worldPacket.WriteString(tab.Name);
    }

    _worldPacket << uint64(Money);

    for (GuildBankItemInfo const& item : ItemInfo)
    {
        for (Item::ItemGemData const& socketEnchant : item.SocketEnchant)
            _worldPacket << socketEnchant;

        _worldPacket << uint32(item.EnchantmentID);
        _worldPacket << uint32(item.ReforgeEnchantmentID);
        _worldPacket << uint32(item.OnUseEnchantmentID);
        _worldPacket << int32(item.Count);
        _worldPacket << int32(item.Slot);
        _worldPacket << int32(item.Flags);
        _worldPacket << int32(item.Item.ItemID);
        _worldPacket << int32(item.RandomPropertiesID);
        _worldPacket << int32(item.Charges);
        _worldPacket << int32(item.RandomPropertiesSeed);
    }

     _worldPacket << uint32(Tab);
     _worldPacket << uint32(WithdrawalsRemaining);

    return &_worldPacket;
}
