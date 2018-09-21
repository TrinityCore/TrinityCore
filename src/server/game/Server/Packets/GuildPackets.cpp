/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
    _worldPacket >> GuildGuid;
    _worldPacket >> PlayerGuid;
}

WorldPackets::Guild::QueryGuildInfoResponse::QueryGuildInfoResponse()
    : ServerPacket(SMSG_QUERY_GUILD_INFO_RESPONSE) { }

WorldPacket const* WorldPackets::Guild::QueryGuildInfoResponse::Write()
{
    _worldPacket << GuildGuid;
    _worldPacket.WriteBit(Info.is_initialized());
    _worldPacket.FlushBits();

    if (Info)
    {
        _worldPacket << Info->GuildGUID;
        _worldPacket << uint32(Info->VirtualRealmAddress);
        _worldPacket << uint32(Info->Ranks.size());
        _worldPacket << uint32(Info->EmblemStyle);
        _worldPacket << uint32(Info->EmblemColor);
        _worldPacket << uint32(Info->BorderStyle);
        _worldPacket << uint32(Info->BorderColor);
        _worldPacket << uint32(Info->BackgroundColor);
        _worldPacket.WriteBits(Info->GuildName.size(), 7);
        _worldPacket.FlushBits();

        for (GuildInfo::GuildInfoRank const& rank : Info->Ranks)
        {
            _worldPacket << uint32(rank.RankID);
            _worldPacket << uint32(rank.RankOrder);
            _worldPacket.WriteBits(rank.RankName.size(), 7);
            _worldPacket.FlushBits();

            _worldPacket.WriteString(rank.RankName);
        }

        _worldPacket.WriteString(Info->GuildName);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildRoster::Write()
{
    _worldPacket << NumAccounts;
    _worldPacket.AppendPackedTime(CreateDate);
    _worldPacket << GuildFlags;
    _worldPacket << uint32(MemberData.size());
    _worldPacket.WriteBits(WelcomeText.length(), 10);
    _worldPacket.WriteBits(InfoText.length(), 11);
    _worldPacket.FlushBits();

    for (GuildRosterMemberData const& member : MemberData)
        _worldPacket << member;

    _worldPacket.WriteString(WelcomeText);
    _worldPacket.WriteString(InfoText);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildRosterUpdate::Write()
{
    _worldPacket << uint32(MemberData.size());

    for (GuildRosterMemberData const& member : MemberData)
        _worldPacket << member;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildUpdateMotdText::Read()
{
    uint32 textLen = _worldPacket.ReadBits(10);
    MotdText = _worldPacket.ReadString(textLen);
}

WorldPacket const* WorldPackets::Guild::GuildCommandResult::Write()
{
    _worldPacket << Result;
    _worldPacket << Command;

    _worldPacket.WriteBits(Name.length(), 8);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

void WorldPackets::Guild::DeclineGuildInvites::Read()
{
    Allow = _worldPacket.ReadBit();
}

void WorldPackets::Guild::GuildInviteByName::Read()
{
    uint32 nameLen = _worldPacket.ReadBits(9);
    Name = _worldPacket.ReadString(nameLen);
}

WorldPacket const* WorldPackets::Guild::GuildInvite::Write()
{
    _worldPacket.WriteBits(InviterName.length(), 6);
    _worldPacket.WriteBits(GuildName.length(), 7);
    _worldPacket.WriteBits(OldGuildName.length(), 7);
    _worldPacket.FlushBits();

    _worldPacket << InviterVirtualRealmAddress;
    _worldPacket << GuildVirtualRealmAddress;
    _worldPacket << GuildGUID;
    _worldPacket << OldGuildVirtualRealmAddress;
    _worldPacket << OldGuildGUID;
    _worldPacket << EmblemStyle;
    _worldPacket << EmblemColor;
    _worldPacket << BorderStyle;
    _worldPacket << BorderColor;
    _worldPacket << Background;
    _worldPacket << AchievementPoints;

    _worldPacket.WriteString(InviterName);
    _worldPacket.WriteString(GuildName);
    _worldPacket.WriteString(OldGuildName);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterProfessionData const& rosterProfessionData)
{
    data << rosterProfessionData.DbID;
    data << rosterProfessionData.Rank;
    data << rosterProfessionData.Step;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRosterMemberData const& rosterMemberData)
{
    data << rosterMemberData.Guid;
    data << rosterMemberData.RankID;
    data << rosterMemberData.AreaID;
    data << rosterMemberData.PersonalAchievementPoints;
    data << rosterMemberData.GuildReputation;
    data << rosterMemberData.LastSave;

    for (uint8 i = 0; i < 2; i++)
        data << rosterMemberData.Profession[i];

    data << rosterMemberData.VirtualRealmAddress;
    data << rosterMemberData.Status;
    data << rosterMemberData.Level;
    data << rosterMemberData.ClassID;
    data << rosterMemberData.Gender;

    data.WriteBits(rosterMemberData.Name.length(), 6);
    data.WriteBits(rosterMemberData.Note.length(), 8);
    data.WriteBits(rosterMemberData.OfficerNote.length(), 8);
    data.WriteBit(rosterMemberData.Authenticated);
    data.WriteBit(rosterMemberData.SorEligible);
    data.FlushBits();

    data.WriteString(rosterMemberData.Name);
    data.WriteString(rosterMemberData.Note);
    data.WriteString(rosterMemberData.OfficerNote);

    return data;
}

WorldPacket const* WorldPackets::Guild::GuildEventPresenceChange::Write()
{
    _worldPacket << Guid;
    _worldPacket << VirtualRealmAddress;

    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket.WriteBit(LoggedOn);
    _worldPacket.WriteBit(Mobile);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventMotd::Write()
{
    _worldPacket.WriteBits(MotdText.length(), 10);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(MotdText);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventPlayerJoined::Write()
{
    _worldPacket << Guid;
    _worldPacket << VirtualRealmAddress;

    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventRankChanged::Write()
{
    _worldPacket << RankID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventBankMoneyChanged::Write()
{
    _worldPacket << Money;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventLogQueryResults::Write()
{
    _worldPacket.reserve(4 + Entry.size() * 38);

    _worldPacket << uint32(Entry.size());

    for (GuildEventEntry const& entry : Entry)
    {
        _worldPacket << entry.PlayerGUID;
        _worldPacket << entry.OtherGUID;
        _worldPacket << entry.TransactionType;
        _worldPacket << entry.RankID;
        _worldPacket << entry.TransactionDate;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventPlayerLeft::Write()
{
    _worldPacket.WriteBit(Removed);
    _worldPacket.WriteBits(LeaverName.length(), 6);
    _worldPacket.FlushBits();

    if (Removed)
    {
        _worldPacket.WriteBits(RemoverName.length(), 6);
        _worldPacket.FlushBits();

        _worldPacket << RemoverGUID;
        _worldPacket << RemoverVirtualRealmAddress;
        _worldPacket.WriteString(RemoverName);
    }

    _worldPacket << LeaverGUID;
    _worldPacket << LeaverVirtualRealmAddress;
    _worldPacket.WriteString(LeaverName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildPermissionsQueryResults::Write()
{
    _worldPacket << RankID;
    _worldPacket << WithdrawGoldLimit;
    _worldPacket << Flags;
    _worldPacket << NumTabs;
    _worldPacket << uint32(Tab.size());

    for (GuildRankTabPermissions const& tab : Tab)
    {
        _worldPacket << tab.Flags;
        _worldPacket << tab.WithdrawItemLimit;
    }

    return &_worldPacket;
}

void WorldPackets::Guild::GuildSetRankPermissions::Read()
{
    _worldPacket >> RankID;
    _worldPacket >> RankOrder;
    _worldPacket >> Flags;
    _worldPacket >> OldFlags;
    _worldPacket >> WithdrawGoldLimit;

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        _worldPacket >> TabFlags[i];
        _worldPacket >> TabWithdrawItemLimit[i];
    }

    _worldPacket.ResetBitPos();
    uint32 rankNameLen = _worldPacket.ReadBits(7);

    RankName = _worldPacket.ReadString(rankNameLen);
}

WorldPacket const* WorldPackets::Guild::GuildEventNewLeader::Write()
{
    _worldPacket.WriteBit(SelfPromoted);
    _worldPacket.WriteBits(NewLeaderName.length(), 6);
    _worldPacket.WriteBits(OldLeaderName.length(), 6);
    _worldPacket.FlushBits();

    _worldPacket << OldLeaderGUID;
    _worldPacket << OldLeaderVirtualRealmAddress;
    _worldPacket << NewLeaderGUID;
    _worldPacket << NewLeaderVirtualRealmAddress;

    _worldPacket.WriteString(NewLeaderName);
    _worldPacket.WriteString(OldLeaderName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventTabModified::Write()
{
    _worldPacket << Tab;

    _worldPacket.WriteBits(Name.length(), 7);
    _worldPacket.WriteBits(Icon.length(), 9);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Name);
    _worldPacket.WriteString(Icon);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventTabTextChanged::Write()
{
    _worldPacket << Tab;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRankData const& rankData)
{
    data << rankData.RankID;
    data << rankData.RankOrder;
    data << rankData.Flags;
    data << rankData.WithdrawGoldLimit;

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        data << rankData.TabFlags[i];
        data << rankData.TabWithdrawItemLimit[i];
    }

    data.WriteBits(rankData.RankName.length(), 7);
    data.FlushBits();

    data.WriteString(rankData.RankName);

    return data;
}

void WorldPackets::Guild::GuildAddRank::Read()
{
    uint32 nameLen = _worldPacket.ReadBits(7);
    _worldPacket.ResetBitPos();

    _worldPacket >> RankOrder;
    Name = _worldPacket.ReadString(nameLen);
}

void WorldPackets::Guild::GuildAssignMemberRank::Read()
{
    _worldPacket >> Member;
    _worldPacket >> RankOrder;
}

void WorldPackets::Guild::GuildDeleteRank::Read()
{
    _worldPacket >> RankOrder;
}

void WorldPackets::Guild::GuildGetRanks::Read()
{
    _worldPacket >> GuildGUID;
}

WorldPacket const* WorldPackets::Guild::GuildRanks::Write()
{
    _worldPacket << uint32(Ranks.size());

    for (GuildRankData const& rank : Ranks)
        _worldPacket << rank;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildSendRankChange::Write()
{
    _worldPacket << Officer;
    _worldPacket << Other;
    _worldPacket << RankID;

    _worldPacket.WriteBit(Promote);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Guild::GuildShiftRank::Read()
{
    _worldPacket >> RankOrder;
    ShiftUp = _worldPacket.ReadBit();
}

void WorldPackets::Guild::GuildUpdateInfoText::Read()
{
    uint32 textLen = _worldPacket.ReadBits(11);
    InfoText = _worldPacket.ReadString(textLen);
}

void WorldPackets::Guild::GuildSetMemberNote::Read()
{
    _worldPacket >> NoteeGUID;

    uint32 noteLen = _worldPacket.ReadBits(8);
    IsPublic = _worldPacket.ReadBit();

    Note = _worldPacket.ReadString(noteLen);
}

WorldPacket const* WorldPackets::Guild::GuildMemberUpdateNote::Write()
{
    _worldPacket.reserve(16 + 2 + Note.size());

    _worldPacket << Member;

    _worldPacket.WriteBits(Note.length(), 8);
    _worldPacket.WriteBit(IsPublic);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Note);

    return &_worldPacket;
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

void WorldPackets::Guild::GuildChangeNameRequest::Read()
{
    uint32 nameLen = _worldPacket.ReadBits(7);
    NewName = _worldPacket.ReadString(nameLen);
}

WorldPacket const* WorldPackets::Guild::GuildFlaggedForRename::Write()
{
    _worldPacket.WriteBit(FlagSet);

    return &_worldPacket;
}

void WorldPackets::Guild::RequestGuildPartyState::Read()
{
    _worldPacket >> GuildGUID;
}

WorldPacket const* WorldPackets::Guild::GuildPartyState::Write()
{
    _worldPacket.WriteBit(InGuildParty);
    _worldPacket.FlushBits();

    _worldPacket << NumMembers;
    _worldPacket << NumRequired;
    _worldPacket << GuildXPEarnedMult;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRewardItem const& rewardItem)
{
    data << rewardItem.ItemID;
    data << rewardItem.Unk4;
    data << uint32(rewardItem.AchievementsRequired.size());
    data << uint64(rewardItem.RaceMask);
    data << rewardItem.MinGuildLevel;
    data << rewardItem.MinGuildRep;
    data << rewardItem.Cost;

    for (uint8 i = 0; i < rewardItem.AchievementsRequired.size(); i++)
        data << rewardItem.AchievementsRequired[i];

    return data;
}

void WorldPackets::Guild::RequestGuildRewardsList::Read()
{
    _worldPacket >> CurrentVersion;
}

WorldPacket const* WorldPackets::Guild::GuildRewardList::Write()
{
    _worldPacket << Version;
    _worldPacket << uint32(RewardItems.size());

    for (GuildRewardItem const& item : RewardItems)
        _worldPacket << item;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankActivate::Read()
{
    _worldPacket >> Banker;
    FullUpdate = _worldPacket.ReadBit();
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

    _worldPacket.ResetBitPos();
    uint32 nameLen = _worldPacket.ReadBits(7);
    uint32 iconLen = _worldPacket.ReadBits(9);

    Name = _worldPacket.ReadString(nameLen);
    Icon = _worldPacket.ReadString(iconLen);
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

    FullUpdate = _worldPacket.ReadBit();
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
    _worldPacket << Money;
    _worldPacket << Tab;
    _worldPacket << WithdrawalsRemaining;
    _worldPacket << uint32(TabInfo.size());
    _worldPacket << uint32(ItemInfo.size());
    _worldPacket.WriteBit(FullUpdate);
    _worldPacket.FlushBits();

    for (GuildBankTabInfo const& tab : TabInfo)
    {
        _worldPacket << tab.TabIndex;
        _worldPacket.WriteBits(tab.Name.length(), 7);
        _worldPacket.WriteBits(tab.Icon.length(), 9);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(tab.Name);
        _worldPacket.WriteString(tab.Icon);
    }

    for (GuildBankItemInfo const& item : ItemInfo)
    {
        _worldPacket << item.Slot;
        _worldPacket << item.Count;
        _worldPacket << item.EnchantmentID;
        _worldPacket << item.Charges;
        _worldPacket << item.OnUseEnchantmentID;
        _worldPacket << item.Flags;
        _worldPacket << item.Item;
        _worldPacket.WriteBits(item.SocketEnchant.size(), 2);
        _worldPacket.WriteBit(item.Locked);
        _worldPacket.FlushBits();

        for (Item::ItemGemData const& socketEnchant : item.SocketEnchant)
            _worldPacket << socketEnchant;
    }

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankSwapItems::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ItemID;
    _worldPacket >> BankTab1;
    _worldPacket >> BankSlot1;
    _worldPacket >> ItemID1;
    _worldPacket >> BankItemCount;
    _worldPacket >> ContainerSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> ToSlot;
    _worldPacket >> StackCount;

    _worldPacket.ResetBitPos();
    BankOnly = _worldPacket.ReadBit();
    AutoStore = _worldPacket.ReadBit();
}

void WorldPackets::Guild::GuildBankLogQuery::Read()
{
    _worldPacket >> Tab;
}

WorldPacket const* WorldPackets::Guild::GuildBankLogQueryResults::Write()
{
    _worldPacket << Tab;
    _worldPacket << uint32(Entry.size());
    _worldPacket.WriteBit(WeeklyBonusMoney.is_initialized());
    _worldPacket.FlushBits();

    for (GuildBankLogEntry const& logEntry : Entry)
    {
        _worldPacket << logEntry.PlayerGUID;
        _worldPacket << logEntry.TimeOffset;
        _worldPacket << logEntry.EntryType;

        _worldPacket.WriteBit(logEntry.Money.is_initialized());
        _worldPacket.WriteBit(logEntry.ItemID.is_initialized());
        _worldPacket.WriteBit(logEntry.Count.is_initialized());
        _worldPacket.WriteBit(logEntry.OtherTab.is_initialized());
        _worldPacket.FlushBits();

        if (logEntry.Money.is_initialized())
            _worldPacket << *logEntry.Money;

        if (logEntry.ItemID.is_initialized())
            _worldPacket << *logEntry.ItemID;

        if (logEntry.Count.is_initialized())
            _worldPacket << *logEntry.Count;

        if (logEntry.OtherTab.is_initialized())
            _worldPacket << *logEntry.OtherTab;
    }

    if (WeeklyBonusMoney)
        _worldPacket << *WeeklyBonusMoney;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankTextQuery::Read()
{
    _worldPacket >> Tab;
}

WorldPacket const* WorldPackets::Guild::GuildBankTextQueryResult::Write()
{
    _worldPacket << Tab;

    _worldPacket.WriteBits(Text.length(), 14);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Text);

    return &_worldPacket;
}

void WorldPackets::Guild::GuildBankSetTabText::Read()
{
    _worldPacket >> Tab;
    TabText = _worldPacket.ReadString(_worldPacket.ReadBits(14));
}

void WorldPackets::Guild::GuildQueryNews::Read()
{
    _worldPacket >> GuildGUID;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildNewsEvent const& newsEvent)
{
    data << newsEvent.Id;
    data.AppendPackedTime(newsEvent.CompletedDate);
    data << newsEvent.Type;
    data << newsEvent.Flags;

    for (uint8 i = 0; i < 2; i++)
        data << newsEvent.Data[i];

    data << newsEvent.MemberGuid;
    data << uint32(newsEvent.MemberList.size());

    for (ObjectGuid memberGuid : newsEvent.MemberList)
        data << memberGuid;

    data.WriteBit(newsEvent.Item.is_initialized());
    data.FlushBits();

    if (newsEvent.Item)
        data << *newsEvent.Item;  // WorldPackets::Item::ItemInstance

    return data;
}

WorldPacket const* WorldPackets::Guild::GuildNews::Write()
{
    _worldPacket << uint32(NewsEvents.size());
    for (GuildNewsEvent const& newsEvent : NewsEvents)
        _worldPacket << newsEvent;

    return &_worldPacket;
}

void WorldPackets::Guild::GuildNewsUpdateSticky::Read()
{
    _worldPacket >> GuildGUID;
    _worldPacket >> NewsID;

    NewsID = _worldPacket.ReadBit();
}

void WorldPackets::Guild::GuildSetGuildMaster::Read()
{
    uint32 nameLen = _worldPacket.ReadBits(9);
    NewMasterName = _worldPacket.ReadString(nameLen);
}

WorldPacket const* WorldPackets::Guild::GuildChallengeUpdate::Write()
{
    for (int32 i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        _worldPacket << int32(CurrentCount[i]);

    for (int32 i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        _worldPacket << int32(MaxCount[i]);

    for (int32 i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        _worldPacket << int32(MaxLevelGold[i]);

    for (int32 i = 0; i < GUILD_CHALLENGES_TYPES; ++i)
        _worldPacket << int32(Gold[i]);

    return &_worldPacket;
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

void WorldPackets::Guild::GuildSetAchievementTracking::Read()
{
    uint32 count;
    _worldPacket >> count;

    for (uint32 i = 0; i < count; ++i)
    {
        uint32 value;
        _worldPacket >> value;
        AchievementIDs.insert(value);
    }
}

WorldPacket const* WorldPackets::Guild::GuildNameChanged::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket.WriteBits(GuildName.length(), 7);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(GuildName);

    return &_worldPacket;
}
