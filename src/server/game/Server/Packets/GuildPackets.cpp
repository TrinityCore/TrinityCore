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

void WorldPackets::Guild::GuildBankDepositMoney::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Money;
}

void WorldPackets::Guild::GuildBankWithdrawMoney::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Money;
}

void WorldPackets::Guild::GuildBankLogQuery::Read()
{
    _worldPacket >> Tab;
}

void WorldPackets::Guild::GuildBankSwapItems::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankOnly;

    if (BankOnly)
    {
        _worldPacket >> BankTab;
        _worldPacket >> BankSlot;
        _worldPacket >> ItemID;
        _worldPacket >> BankTab1;
        _worldPacket >> BankSlot1;
        _worldPacket >> ItemID1;
        _worldPacket >> ToSlot;
        _worldPacket >> StackCount;
    }
    else
    {
        _worldPacket >> BankTab;
        _worldPacket >> BankSlot;
        _worldPacket >> ItemID;
        _worldPacket >> AutoStore;
        if (AutoStore)
        {
            _worldPacket >> StackCount;
            _worldPacket >> ToSlot;
            _worldPacket >> BankItemCount;
        }
        else
        {
            _worldPacket >> ContainerSlot;
            _worldPacket >> ContainerItemSlot;
            _worldPacket >> ToSlot;
            _worldPacket >> StackCount;
        }
    }
}

void WorldPackets::Guild::GuildBankTextQuery::Read()
{
    _worldPacket >> Tab;
}

void WorldPackets::Guild::GuildBankSetTabText::Read()
{
    _worldPacket >> Tab;
    uint32 length = _worldPacket.ReadBits(14);
    TabText = _worldPacket.ReadString(length);
}

void WorldPackets::Guild::GuildXPQuery::Read()
{
    GuildGUID[2] = _worldPacket.ReadBit();
    GuildGUID[1] = _worldPacket.ReadBit();
    GuildGUID[0] = _worldPacket.ReadBit();
    GuildGUID[5] = _worldPacket.ReadBit();
    GuildGUID[4] = _worldPacket.ReadBit();
    GuildGUID[7] = _worldPacket.ReadBit();
    GuildGUID[6] = _worldPacket.ReadBit();
    GuildGUID[3] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(GuildGUID[7]);
    _worldPacket.ReadByteSeq(GuildGUID[2]);
    _worldPacket.ReadByteSeq(GuildGUID[3]);
    _worldPacket.ReadByteSeq(GuildGUID[6]);
    _worldPacket.ReadByteSeq(GuildGUID[1]);
    _worldPacket.ReadByteSeq(GuildGUID[5]);
    _worldPacket.ReadByteSeq(GuildGUID[0]);
    _worldPacket.ReadByteSeq(GuildGUID[4]);
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

    for (GuildBankTabInfo const& tab : TabInfo)
    {
        _worldPacket.WriteString(tab.Icon);
        _worldPacket << uint32(tab.TabIndex);
        _worldPacket.WriteString(tab.Name);
    }

    _worldPacket << uint64(Money);

    for (GuildBankItemInfo const& item : ItemInfo)
    {
        for (Guild::GuildBankItemInfo::GuildBankSocketEnchant const& socketEnchant : item.SocketEnchant)
        {
            _worldPacket << socketEnchant.SocketIndex;
            _worldPacket << socketEnchant.SocketEnchantID;
        }

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

    _worldPacket.FlushBits();
    _worldPacket << uint32(Tab);
    _worldPacket << uint32(WithdrawalsRemaining);

    return &_worldPacket;
}
