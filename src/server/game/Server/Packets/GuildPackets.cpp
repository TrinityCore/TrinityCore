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
        for (Guild::GuildBankItemInfo::GuildBankSocketEnchant const& socketEnchant : item.SocketEnchant)
        {
            _worldPacket << uint32(socketEnchant.SocketIndex);
            _worldPacket << uint32(socketEnchant.SocketEnchantID);
        }

        _worldPacket << uint32(item.EnchantmentID);
        _worldPacket << uint32(item.ReforgeEnchantmentID);
        _worldPacket << uint32(item.OnUseEnchantmentID);
        _worldPacket << uint32(item.Count);
        _worldPacket << uint32(item.Slot);
        _worldPacket << uint32(item.Flags);
        _worldPacket << uint32(item.Item.ItemID);
        _worldPacket << uint32(item.Item.RandomPropertiesID);
        _worldPacket << uint32(item.Charges);
        _worldPacket << uint32(item.Item.RandomPropertiesSeed);
    }

    _worldPacket << uint32(Tab);
    _worldPacket << uint32(WithdrawalsRemaining);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEvent::Write()
{
    _worldPacket << uint8(EventType);
    _worldPacket << uint8(Param.size());
    for (std::string param : Param)
        _worldPacket << param;
    _worldPacket << GUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildReputationWeeklyCap::Write()
{
    _worldPacket << uint32(Cap);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildXP::Write()
{
    _worldPacket << uint64(TotalXP);
    _worldPacket << uint64(GuildRemainingXP);
    _worldPacket << uint64(GuildTodayXP);
    _worldPacket << uint64(WeeklyXP);
    _worldPacket << uint64(GuildCurrentXP);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildRoster::Write()
{
    _worldPacket.WriteBits(WelcomeText.length(), 11);
    _worldPacket.WriteBits(MemberData.size(), 18);

    for (GuildRosterMemberData const& member : MemberData)
    {
        _worldPacket.WriteBit(member.Guid[3]);
        _worldPacket.WriteBit(member.Guid[4]);
        _worldPacket.WriteBit(member.Authenticated);
        _worldPacket.WriteBit(member.SorEligible);
        _worldPacket.WriteBits(member.Note.length(), 8);
        _worldPacket.WriteBits(member.OfficerNote.length(), 8);
        _worldPacket.WriteBit(member.Guid[0]);
        _worldPacket.WriteBits(member.Name.length(), 7);
        _worldPacket.WriteBit(member.Guid[1]);
        _worldPacket.WriteBit(member.Guid[2]);
        _worldPacket.WriteBit(member.Guid[6]);
        _worldPacket.WriteBit(member.Guid[5]);
        _worldPacket.WriteBit(member.Guid[7]);
    }

    _worldPacket.WriteBits(InfoText.length(), 12);
    _worldPacket.FlushBits();

    for (GuildRosterMemberData const& member : MemberData)
        _worldPacket << member;

    _worldPacket.WriteString(InfoText);
    _worldPacket.WriteString(WelcomeText);
    _worldPacket << uint32(NumAccounts);
    _worldPacket << uint32(WeeklyRepCap);
    _worldPacket.AppendPackedTime(CreateDate);
    _worldPacket << uint32(GuildFlags);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterProfessionData const& rosterProfessionData)
{
    data << uint32(rosterProfessionData.Step);
    data << uint32(rosterProfessionData.Rank);
    data << uint32(rosterProfessionData.DbID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterMemberData const& rosterMemberData)
{
    data << uint8(rosterMemberData.ClassID);
    data << uint32(rosterMemberData.GuildReputation);
    data.WriteByteSeq(rosterMemberData.Guid[0]);
    data << uint64(rosterMemberData.WeeklyXP);
    data << uint32(rosterMemberData.RankID);
    data << uint32(rosterMemberData.PersonalAchievementPoints);

    for (uint8 i = 0; i < 2; i++)
        data << rosterMemberData.Profession[i];

    data.WriteByteSeq(rosterMemberData.Guid[2]);
    data << uint8(rosterMemberData.Status);
    data << uint32(rosterMemberData.AreaID);
    data << uint64(rosterMemberData.TotalXP);
    data.WriteByteSeq(rosterMemberData.Guid[7]);
    data << uint32(rosterMemberData.GuildRepToCap);
    data.WriteString(rosterMemberData.Note);
    data.WriteByteSeq(rosterMemberData.Guid[3]);
    data << uint8(rosterMemberData.Level);
    data << int32(rosterMemberData.VirtualRealmAddress); // Todo: Validate
    data.WriteByteSeq(rosterMemberData.Guid[5]);
    data.WriteByteSeq(rosterMemberData.Guid[4]);
    data << uint8(rosterMemberData.Gender);
    data.WriteByteSeq(rosterMemberData.Guid[1]);
    data << float(rosterMemberData.LastSave);
    data.WriteString(rosterMemberData.OfficerNote);
    data.WriteByteSeq(rosterMemberData.Guid[6]);
    data.WriteString(rosterMemberData.Name);

    return data;
}

