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

#include "GuildPackets.h"

void WorldPackets::Guild::QueryGuildInfo::Read()
{
    _worldPacket >> GuildId;
}

WorldPackets::Guild::QueryGuildInfoResponse::QueryGuildInfoResponse()
    : ServerPacket(SMSG_GUILD_QUERY_RESPONSE) { }

WorldPacket const* WorldPackets::Guild::QueryGuildInfoResponse::Write()
{
    _worldPacket << GuildId;
    _worldPacket << Info.GuildName;
    for (std::string const& rankName : Info.Ranks)
        _worldPacket << rankName;

    _worldPacket << uint32(Info.EmblemStyle);
    _worldPacket << uint32(Info.EmblemColor);
    _worldPacket << uint32(Info.BorderStyle);
    _worldPacket << uint32(Info.BorderColor);
    _worldPacket << uint32(Info.BackgroundColor);
    _worldPacket << uint32(Info.RankCount);

    return &_worldPacket;
}

void WorldPackets::Guild::GuildCreate::Read()
{
    _worldPacket >> GuildName;
}

WorldPacket const* WorldPackets::Guild::GuildInfoResponse::Write()
{
    _worldPacket << GuildName;
    _worldPacket.AppendPackedTime(CreateDate);
    _worldPacket << int32(NumMembers);
    _worldPacket << int32(NumAccounts);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildRoster::Write()
{
    _worldPacket << uint32(MemberData.size());
    _worldPacket << WelcomeText;
    _worldPacket << InfoText;
    _worldPacket << uint32(RankData.size());

    for (GuildRankData const& rank : RankData)
        _worldPacket << rank;

    for (GuildRosterMemberData const& member : MemberData)
        _worldPacket << member;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildUpdateMotdText::Read()
{
    _worldPacket >> MotdText;
}

WorldPacket const* WorldPackets::Guild::GuildCommandResult::Write()
{
    _worldPacket << int32(Command);
    _worldPacket << Name;
    _worldPacket << int32(Result);

    return &_worldPacket;
}

void WorldPackets::Guild::GuildInviteByName::Read()
{
    _worldPacket >> Name;
}

WorldPacket const* WorldPackets::Guild::GuildInvite::Write()
{
    _worldPacket << InviterName;
    _worldPacket << GuildName;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterMemberData const& rosterMemberData)
{
    data << rosterMemberData.Guid;
    data << uint8(rosterMemberData.Status);
    data << rosterMemberData.Name;
    data << int32(rosterMemberData.RankID);
    data << uint8(rosterMemberData.Level);
    data << uint8(rosterMemberData.ClassID);
    data << uint8(rosterMemberData.Gender);
    data << int32(rosterMemberData.AreaID);
    if (!rosterMemberData.Status)
        data << float(rosterMemberData.LastSave);

    data << rosterMemberData.Note;
    data << rosterMemberData.OfficerNote;

    return data;
}

WorldPacket const* WorldPackets::Guild::GuildEvent::Write()
{
    _worldPacket << uint8(Type);
    _worldPacket << uint8(Params.size());
    for (std::string_view param : Params)
        _worldPacket << param;

    switch (Type)
    {
        case GE_JOINED:
        case GE_LEFT:
        case GE_SIGNED_ON:
        case GE_SIGNED_OFF:
            _worldPacket << Guid;
            break;
        default:
            break;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventLogQueryResults::Write()
{
    _worldPacket.reserve(1 + Entry.size() * sizeof(GuildEventEntry));

    _worldPacket << uint8(Entry.size());

    for (GuildEventEntry const& entry : Entry)
    {
        _worldPacket << uint8(entry.TransactionType);
        _worldPacket << entry.PlayerGUID;
        if (entry.TransactionType != GUILD_EVENT_LOG_JOIN_GUILD && entry.TransactionType != GUILD_EVENT_LOG_LEAVE_GUILD)
            _worldPacket << entry.OtherGUID;
        if (entry.TransactionType == GUILD_EVENT_LOG_PROMOTE_PLAYER || entry.TransactionType == GUILD_EVENT_LOG_DEMOTE_PLAYER)
            _worldPacket << uint8(entry.RankID);
        _worldPacket << uint32(entry.TransactionDate);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildPermissionsQueryResults::Write()
{
    _worldPacket << uint32(RankID);
    _worldPacket << int32(Flags);
    _worldPacket << int32(WithdrawGoldLimit);
    _worldPacket << int8(NumTabs);

    for (GuildRankTabPermissions const& tab : Tab)
    {
        _worldPacket << int32(tab.Flags);
        _worldPacket << int32(tab.WithdrawItemLimit);
    }

    return &_worldPacket;
}

void WorldPackets::Guild::GuildSetRankPermissions::Read()
{
    _worldPacket >> RankID;
    _worldPacket >> Flags;
    _worldPacket >> RankName;
    _worldPacket >> WithdrawGoldLimit;

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        _worldPacket >> TabFlags[i];
        _worldPacket >> TabWithdrawItemLimit[i];
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRankData const& rankData)
{
    data << uint32(rankData.Flags);
    data << uint32(rankData.WithdrawGoldLimit);

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        data << uint32(rankData.TabFlags[i]);
        data << uint32(rankData.TabWithdrawItemLimit[i]);
    }

    return data;
}

void WorldPackets::Guild::GuildAddRank::Read()
{
    _worldPacket >> Name;
}

void WorldPackets::Guild::GuildUpdateInfoText::Read()
{
    _worldPacket >> InfoText;
}

void WorldPackets::Guild::GuildSetMemberNote::Read()
{
    _worldPacket >> NoteeName;
    _worldPacket >> Note;
}

void WorldPackets::Guild::GuildDemoteMember::Read()
{
    _worldPacket >> Demotee;
}

void WorldPackets::Guild::GuildPromoteMember::Read()
{
    _worldPacket >> Promotee;
}

void WorldPackets::Guild::GuildOfficerRemoveMember::Read()
{
    _worldPacket >> Removee;
}

void WorldPackets::Guild::GuildBankActivate::Read()
{
    _worldPacket >> Banker;
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

void WorldPackets::Guild::GuildBankQueryTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Tab;
    _worldPacket >> FullUpdate;
}

WorldPacket const* WorldPackets::Guild::GuildBankRemainingWithdrawMoney::Write()
{
    _worldPacket << RemainingWithdrawMoney;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankWithdrawMoney::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Money;
}

WorldPacket const* WorldPackets::Guild::GuildBankQueryResults::Write()
{
    _worldPacket << uint64(Money);
    _worldPacket << uint8(Tab);
    _withdrawalsRemainingPos = _worldPacket.wpos();
    _worldPacket << int32(WithdrawalsRemaining);
    _worldPacket << uint8(FullUpdate);

    if (!Tab && FullUpdate)
    {
        _worldPacket << uint8(TabInfo.size());
        for (GuildBankTabInfo const& tab : TabInfo)
        {
            _worldPacket << tab.Name;
            _worldPacket << tab.Icon;
        }
    }

    _worldPacket << uint8(ItemInfo.size());
    for (GuildBankItemInfo const& item : ItemInfo)
    {
        _worldPacket << uint8(item.Slot);
        _worldPacket << uint32(item.ItemID);
        if (item.ItemID)
        {
            _worldPacket << int32(item.Flags);
            _worldPacket << int32(item.RandomPropertiesID);
            if (item.RandomPropertiesID)
                _worldPacket << int32(item.RandomPropertiesSeed);

            _worldPacket << int32(item.Count);
            _worldPacket << int32(item.EnchantmentID);
            _worldPacket << uint8(item.Charges);
            _worldPacket << uint8(item.SocketEnchant.size());

            for (GuildBankSocketEnchant const& socketEnchant : item.SocketEnchant)
            {
                _worldPacket << uint8(socketEnchant.SocketIndex);
                _worldPacket << int32(socketEnchant.SocketEnchantID);
            }
        }
    }

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankQueryResults::SetWithdrawalsRemaining(int32 withdrawalsRemaining)
{
    WithdrawalsRemaining = withdrawalsRemaining;
    _worldPacket.put<int32>(_withdrawalsRemainingPos, withdrawalsRemaining);
}

void WorldPackets::Guild::GuildBankSwapItems::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankOnly;

    if (BankOnly)
    {
        // dest
        _worldPacket >> BankTab;
        _worldPacket >> BankSlot;
        _worldPacket >> ItemID;

        // src
        _worldPacket >> BankTab1;
        _worldPacket >> BankSlot1;
        _worldPacket >> ItemID1;

        _worldPacket >> AutoStore;
        _worldPacket >> BankItemCount;
    }
    else
    {
        _worldPacket >> BankTab;
        _worldPacket >> BankSlot;
        _worldPacket >> ItemID;

        _worldPacket >> AutoStore;
        if (AutoStore)
        {
            _worldPacket >> BankItemCount;
            _worldPacket >> ToSlot;
            _worldPacket >> StackCount;
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

void WorldPackets::Guild::GuildBankLogQuery::Read()
{
    _worldPacket >> Tab;
}

WorldPacket const* WorldPackets::Guild::GuildBankLogQueryResults::Write()
{
    _worldPacket << uint8(Tab);
    _worldPacket << uint8(Entry.size());

    for (GuildBankLogEntry const& logEntry : Entry)
    {
        _worldPacket << int8(logEntry.EntryType);
        _worldPacket << logEntry.PlayerGUID;

        switch (logEntry.EntryType)
        {
            case GUILD_BANK_LOG_DEPOSIT_ITEM:
            case GUILD_BANK_LOG_WITHDRAW_ITEM:
                _worldPacket << uint32(logEntry.ItemID);
                _worldPacket << uint32(logEntry.Count);
                break;
            case GUILD_BANK_LOG_MOVE_ITEM:
            case GUILD_BANK_LOG_MOVE_ITEM2:
                _worldPacket << uint32(logEntry.ItemID);
                _worldPacket << uint32(logEntry.Count);
                _worldPacket << uint8(logEntry.OtherTab);
                break;
            default:
                _worldPacket << uint32(logEntry.Money);
                break;
        }

        _worldPacket << uint32(logEntry.TimeOffset);
    }

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankTextQuery::Read()
{
    _worldPacket >> Tab;
}

WorldPacket const* WorldPackets::Guild::GuildBankTextQueryResult::Write()
{
    _worldPacket << uint8(Tab);
    _worldPacket << Text;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankSetTabText::Read()
{
    _worldPacket >> Tab;
    _worldPacket >> TabText;
}

void WorldPackets::Guild::GuildSetGuildMaster::Read()
{
    _worldPacket >> NewMasterName;
}

void WorldPackets::Guild::SaveGuildEmblem::Read()
{
    _worldPacket >> Vendor;
    _worldPacket >> EStyle;
    _worldPacket >> EColor;
    _worldPacket >> BStyle;
    _worldPacket >> BColor;
    _worldPacket >> Bg;
}

WorldPacket const* WorldPackets::Guild::PlayerSaveGuildEmblem::Write()
{
    _worldPacket << int32(Error);

    return &_worldPacket;
}
