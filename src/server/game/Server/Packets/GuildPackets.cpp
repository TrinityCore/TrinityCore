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
#include "PacketOperators.h"

namespace WorldPackets::Guild
{
void QueryGuildInfo::Read()
{
    _worldPacket >> GuildGuid;
    _worldPacket >> PlayerGuid;
}

WorldPacket const* QueryGuildInfoResponse::Write()
{
    _worldPacket << GuildGuid;
    _worldPacket << OptionalInit(Info);
    _worldPacket.FlushBits();

    if (Info)
    {
        _worldPacket << Info->GuildGUID;
        _worldPacket << uint32(Info->VirtualRealmAddress);
        _worldPacket << Size<uint32>(Info->Ranks);
        _worldPacket << uint32(Info->EmblemStyle);
        _worldPacket << uint32(Info->EmblemColor);
        _worldPacket << uint32(Info->BorderStyle);
        _worldPacket << uint32(Info->BorderColor);
        _worldPacket << uint32(Info->BackgroundColor);
        _worldPacket << SizedString::BitsSize<7>(Info->GuildName);
        _worldPacket.FlushBits();

        for (GuildInfo::GuildInfoRank const& rank : Info->Ranks)
        {
            _worldPacket << uint32(rank.RankID);
            _worldPacket << uint32(rank.RankOrder);
            _worldPacket << SizedString::BitsSize<7>(rank.RankName);
            _worldPacket.FlushBits();

            _worldPacket << SizedString::Data(rank.RankName);
        }

        _worldPacket << SizedString::Data(Info->GuildName);
    }

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildRosterProfessionData const& rosterProfessionData)
{
    data << int32(rosterProfessionData.DbID);
    data << int32(rosterProfessionData.Rank);
    data << int32(rosterProfessionData.Step);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildRosterMemberData const& rosterMemberData)
{
    data << rosterMemberData.Guid;
    data << int32(rosterMemberData.RankID);
    data << int32(rosterMemberData.AreaID);
    data << int32(rosterMemberData.PersonalAchievementPoints);
    data << int32(rosterMemberData.GuildReputation);
    data << float(rosterMemberData.LastSave);

    for (uint8 i = 0; i < 2; i++)
        data << rosterMemberData.Profession[i];

    data << uint32(rosterMemberData.VirtualRealmAddress);
    data << uint8(rosterMemberData.Status);
    data << uint8(rosterMemberData.Level);
    data << uint8(rosterMemberData.ClassID);
    data << uint8(rosterMemberData.Gender);
    data << uint64(rosterMemberData.GuildClubMemberID);
    data << uint8(rosterMemberData.RaceID);
    data << int32(rosterMemberData.TimerunningSeasonID);

    data << SizedString::BitsSize<6>(rosterMemberData.Name);
    data << SizedString::BitsSize<8>(rosterMemberData.Note);
    data << SizedString::BitsSize<8>(rosterMemberData.OfficerNote);
    data << Bits<1>(rosterMemberData.Authenticated);
    data.FlushBits();

    data << rosterMemberData.DungeonScore;

    data << SizedString::Data(rosterMemberData.Name);
    data << SizedString::Data(rosterMemberData.Note);
    data << SizedString::Data(rosterMemberData.OfficerNote);

    return data;
}

WorldPacket const* GuildRoster::Write()
{
    _worldPacket << int32(NumAccounts);
    _worldPacket << CreateDate;
    _worldPacket << int32(GuildFlags);
    _worldPacket << Size<uint32>(MemberData);
    _worldPacket << SizedString::BitsSize<11>(WelcomeText);
    _worldPacket << SizedString::BitsSize<11>(InfoText);
    _worldPacket.FlushBits();

    for (GuildRosterMemberData const& member : MemberData)
        _worldPacket << member;

    _worldPacket << SizedString::Data(WelcomeText);
    _worldPacket << SizedString::Data(InfoText);

    return &_worldPacket;
}

void GuildUpdateMotdText::Read()
{
    _worldPacket >> SizedString::BitsSize<11>(MotdText);

    _worldPacket >> SizedString::Data(MotdText);
}

WorldPacket const* GuildCommandResult::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket << uint8(Command);

    _worldPacket << SizedString::BitsSize<8>(Name);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

void AcceptGuildInvite::Read()
{
    _worldPacket >> GuildGuid;
}

void GuildDeclineInvitation::Read()
{
    _worldPacket >> GuildGuid;
    _worldPacket >> Bits<1>(IsAuto);
}

void DeclineGuildInvites::Read()
{
    _worldPacket >> Bits<1>(Allow);
}

void GuildInviteByName::Read()
{
    _worldPacket >> SizedString::BitsSize<9>(Name);
    _worldPacket >> OptionalInit(ArenaTeam);

    _worldPacket >> SizedString::Data(Name);

    if (ArenaTeam)
        _worldPacket >> *ArenaTeam;
}

WorldPacket const* GuildInvite::Write()
{
    _worldPacket << SizedString::BitsSize<6>(InviterName);
    _worldPacket << SizedString::BitsSize<7>(GuildName);
    _worldPacket << SizedString::BitsSize<7>(OldGuildName);
    _worldPacket.FlushBits();

    _worldPacket << uint32(InviterVirtualRealmAddress);
    _worldPacket << uint32(GuildVirtualRealmAddress);
    _worldPacket << GuildGUID;
    _worldPacket << uint32(OldGuildVirtualRealmAddress);
    _worldPacket << OldGuildGUID;
    _worldPacket << uint32(EmblemStyle);
    _worldPacket << uint32(EmblemColor);
    _worldPacket << uint32(BorderStyle);
    _worldPacket << uint32(BorderColor);
    _worldPacket << uint32(Background);
    _worldPacket << int32(AchievementPoints);

    _worldPacket << SizedString::Data(InviterName);
    _worldPacket << SizedString::Data(GuildName);
    _worldPacket << SizedString::Data(OldGuildName);

    return &_worldPacket;
}

WorldPacket const* GuildEventStatusChange::Write()
{
    _worldPacket << Guid;
    _worldPacket << Bits<1>(AFK);
    _worldPacket << Bits<1>(DND);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* GuildEventPresenceChange::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(VirtualRealmAddress);

    _worldPacket << SizedString::BitsSize<6>(Name);
    _worldPacket << Bits<1>(LoggedOn);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

WorldPacket const* GuildEventMotd::Write()
{
    _worldPacket << SizedString::BitsSize<11>(MotdText);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(MotdText);

    return &_worldPacket;
}

WorldPacket const* GuildEventPlayerJoined::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint32(VirtualRealmAddress);

    _worldPacket << SizedString::BitsSize<6>(Name);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

WorldPacket const* GuildEventRankChanged::Write()
{
    _worldPacket << RankID;

    return &_worldPacket;
}

WorldPacket const* GuildEventBankMoneyChanged::Write()
{
    _worldPacket << Money;

    return &_worldPacket;
}

WorldPacket const* GuildEventLogQueryResults::Write()
{
    _worldPacket.reserve(4 + Entry.size() * 38);

    _worldPacket << Size<uint32>(Entry);

    for (GuildEventEntry const& entry : Entry)
    {
        _worldPacket << entry.PlayerGUID;
        _worldPacket << entry.OtherGUID;
        _worldPacket << uint8(entry.TransactionType);
        _worldPacket << uint8(entry.RankID);
        _worldPacket << uint32(entry.TransactionDate);
    }

    return &_worldPacket;
}

WorldPacket const* GuildEventPlayerLeft::Write()
{
    _worldPacket << Bits<1>(Removed);
    _worldPacket << SizedString::BitsSize<6>(LeaverName);

    if (Removed)
    {
        _worldPacket << SizedString::BitsSize<6>(RemoverName);

        _worldPacket << RemoverGUID;
        _worldPacket << uint32(RemoverVirtualRealmAddress);
        _worldPacket << SizedString::Data(RemoverName);
    }

    _worldPacket << LeaverGUID;
    _worldPacket << uint32(LeaverVirtualRealmAddress);
    _worldPacket << SizedString::Data(LeaverName);

    return &_worldPacket;
}

WorldPacket const* GuildPermissionsQueryResults::Write()
{
    _worldPacket << uint32(RankID);
    _worldPacket << int32(Flags);
    _worldPacket << int32(WithdrawGoldLimit);
    _worldPacket << int32(NumTabs);
    _worldPacket << Size<uint32>(Tab);

    for (GuildRankTabPermissions const& tab : Tab)
    {
        _worldPacket << int32(tab.Flags);
        _worldPacket << int32(tab.WithdrawItemLimit);
    }

    return &_worldPacket;
}

void GuildSetRankPermissions::Read()
{
    _worldPacket >> RankID;
    _worldPacket >> RankOrder;
    _worldPacket >> Flags;
    _worldPacket >> WithdrawGoldLimit;

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        _worldPacket >> TabFlags[i];
        _worldPacket >> TabWithdrawItemLimit[i];
    }

    _worldPacket.ResetBitPos();
    _worldPacket >> SizedString::BitsSize<7>(RankName);

    _worldPacket >> SizedString::Data(RankName);

    _worldPacket >> OldFlags;
}

WorldPacket const* GuildEventNewLeader::Write()
{
    _worldPacket << Bits<1>(SelfPromoted);
    _worldPacket << SizedString::BitsSize<6>(OldLeaderName);
    _worldPacket << SizedString::BitsSize<6>(NewLeaderName);
    _worldPacket.FlushBits();

    _worldPacket << OldLeaderGUID;
    _worldPacket << uint32(OldLeaderVirtualRealmAddress);
    _worldPacket << NewLeaderGUID;
    _worldPacket << uint32(NewLeaderVirtualRealmAddress);

    _worldPacket << SizedString::Data(OldLeaderName);
    _worldPacket << SizedString::Data(NewLeaderName);

    return &_worldPacket;
}

WorldPacket const* GuildEventTabModified::Write()
{
    _worldPacket << int32(Tab);

    _worldPacket << SizedString::BitsSize<7>(Name);
    _worldPacket << SizedString::BitsSize<9>(Icon);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);
    _worldPacket << SizedString::Data(Icon);

    return &_worldPacket;
}

WorldPacket const* GuildEventTabTextChanged::Write()
{
    _worldPacket << Tab;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildRankData const& rankData)
{
    data << uint8(rankData.RankID);
    data << int32(rankData.RankOrder);
    data << uint32(rankData.Flags);
    data << uint32(rankData.WithdrawGoldLimit);

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        data << uint32(rankData.TabFlags[i]);
        data << uint32(rankData.TabWithdrawItemLimit[i]);
    }

    data << SizedString::BitsSize<7>(rankData.RankName);
    data.FlushBits();

    data << SizedString::Data(rankData.RankName);

    return data;
}

void GuildAddRank::Read()
{
    _worldPacket >> SizedString::BitsSize<7>(Name);

    _worldPacket >> RankOrder;
    _worldPacket >> SizedString::Data(Name);
}

void GuildAssignMemberRank::Read()
{
    _worldPacket >> Member;
    _worldPacket >> RankOrder;
}

void GuildDeleteRank::Read()
{
    _worldPacket >> RankOrder;
}

void GuildGetRanks::Read()
{
    _worldPacket >> GuildGUID;
}

WorldPacket const* GuildRanks::Write()
{
    _worldPacket << Size<uint32>(Ranks);

    for (GuildRankData const& rank : Ranks)
        _worldPacket << rank;

    return &_worldPacket;
}

WorldPacket const* GuildSendRankChange::Write()
{
    _worldPacket << Officer;
    _worldPacket << Other;
    _worldPacket << uint32(RankID);

    _worldPacket << Bits<1>(Promote);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void GuildShiftRank::Read()
{
    _worldPacket >> RankOrder;
    _worldPacket >> Bits<1>(ShiftUp);
}

void GuildUpdateInfoText::Read()
{
    _worldPacket >> SizedString::BitsSize<11>(InfoText);

    _worldPacket >> SizedString::Data(InfoText);
}

void GuildSetMemberNote::Read()
{
    _worldPacket >> NoteeGUID;

    _worldPacket >> SizedString::BitsSize<8>(Note);
    _worldPacket >> Bits<1>(IsPublic);

    _worldPacket >> SizedString::Data(Note);
}

WorldPacket const* GuildMemberUpdateNote::Write()
{
    _worldPacket.reserve(16 + 2 + Note.size());

    _worldPacket << Member;

    _worldPacket << SizedString::BitsSize<8>(Note);
    _worldPacket << Bits<1>(IsPublic);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Note);

    return &_worldPacket;
}

void GuildDemoteMember::Read()
{
    _worldPacket >> Demotee;
}

void GuildPromoteMember::Read()
{
    _worldPacket >> Promotee;
}

void GuildOfficerRemoveMember::Read()
{
    _worldPacket >> Removee;
}

void GuildChangeNameRequest::Read()
{
    _worldPacket >> SizedString::BitsSize<7>(NewName);

    _worldPacket >> SizedString::Data(NewName);
}

WorldPacket const* GuildFlaggedForRename::Write()
{
    _worldPacket << Bits<1>(FlagSet);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void RequestGuildPartyState::Read()
{
    _worldPacket >> GuildGUID;
}

WorldPacket const* GuildPartyState::Write()
{
    _worldPacket << int32(NumMembers);
    _worldPacket << int32(NumRequired);
    _worldPacket << float(GuildXPEarnedMult);
    _worldPacket << Bits<1>(InGuildParty);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildRewardItem const& rewardItem)
{
    data << uint32(rewardItem.ItemID);
    data << uint32(rewardItem.AchievementLogic);
    data << Size<uint32>(rewardItem.AchievementsRequired);
    data << uint64(rewardItem.RaceMask.RawValue);
    data << int32(rewardItem.MinGuildLevel);
    data << int32(rewardItem.MinGuildRep);
    data << uint64(rewardItem.Cost);

    for (std::size_t i = 0; i < rewardItem.AchievementsRequired.size(); i++)
        data << uint32(rewardItem.AchievementsRequired[i]);

    return data;
}

void RequestGuildRewardsList::Read()
{
    _worldPacket >> CurrentVersion;
}

WorldPacket const* GuildRewardList::Write()
{
    _worldPacket << Version;
    _worldPacket << Size<uint32>(RewardItems);

    for (GuildRewardItem const& item : RewardItems)
        _worldPacket << item;

    return &_worldPacket;
}

void GuildBankActivate::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Bits<1>(FullUpdate);
}

void GuildBankBuyTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
}

void GuildBankUpdateTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;

    _worldPacket.ResetBitPos();
    _worldPacket >> SizedString::BitsSize<7>(Name);
    _worldPacket >> SizedString::BitsSize<9>(Icon);

    _worldPacket >> SizedString::Data(Name);
    _worldPacket >> SizedString::Data(Icon);
}

void GuildBankDepositMoney::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Money;
}

void GuildBankQueryTab::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Tab;

    _worldPacket >> Bits<1>(FullUpdate);
}

WorldPacket const* GuildBankRemainingWithdrawMoney::Write()
{
    _worldPacket << RemainingWithdrawMoney;

    return &_worldPacket;
}

void GuildBankWithdrawMoney::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> Money;
}

WorldPacket const* GuildBankQueryResults::Write()
{
    _worldPacket << uint64(Money);
    _worldPacket << int32(Tab);
    _worldPacket << int32(WithdrawalsRemaining);
    _worldPacket << Size<uint32>(TabInfo);
    _worldPacket << Size<uint32>(ItemInfo);
    _worldPacket << Bits<1>(FullUpdate);
    _worldPacket.FlushBits();

    for (GuildBankTabInfo const& tab : TabInfo)
    {
        _worldPacket << int32(tab.TabIndex);
        _worldPacket << SizedString::BitsSize<7>(tab.Name);
        _worldPacket << SizedString::BitsSize<9>(tab.Icon);
        _worldPacket.FlushBits();

        _worldPacket << SizedString::Data(tab.Name);
        _worldPacket << SizedString::Data(tab.Icon);
    }

    for (GuildBankItemInfo const& item : ItemInfo)
    {
        _worldPacket << int32(item.Slot);
        _worldPacket << int32(item.Count);
        _worldPacket << int32(item.EnchantmentID);
        _worldPacket << int32(item.Charges);
        _worldPacket << int32(item.OnUseEnchantmentID);
        _worldPacket << int32(item.Flags);
        _worldPacket << item.Item;
        _worldPacket << BitsSize<2>(item.SocketEnchant);
        _worldPacket << Bits<1>(item.Locked);
        _worldPacket.FlushBits();

        for (Item::ItemGemData const& socketEnchant : item.SocketEnchant)
            _worldPacket << socketEnchant;
    }

    return &_worldPacket;
}

void AutoGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void StoreGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void SwapItemWithGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void SwapGuildBankItemWithGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab[0];
    _worldPacket >> BankSlot[0];
    _worldPacket >> BankTab[1];
    _worldPacket >> BankSlot[1];
}

void MoveGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> BankTab1;
    _worldPacket >> BankSlot1;
}

void MergeItemWithGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> StackCount;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void SplitItemToGuildBank::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> StackCount;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void MergeGuildBankItemWithItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> StackCount;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void SplitGuildBankItemToInventory::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> ContainerItemSlot;
    _worldPacket >> StackCount;
    _worldPacket >> OptionalInit(ContainerSlot);

    if (ContainerSlot)
        _worldPacket >> *ContainerSlot;
}

void AutoStoreGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
}

void MergeGuildBankItemWithGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> BankTab1;
    _worldPacket >> BankSlot1;
    _worldPacket >> StackCount;
}

void SplitGuildBankItem::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> BankTab;
    _worldPacket >> BankSlot;
    _worldPacket >> BankTab1;
    _worldPacket >> BankSlot1;
    _worldPacket >> StackCount;
}

void GuildBankLogQuery::Read()
{
    _worldPacket >> Tab;
}

WorldPacket const* GuildBankLogQueryResults::Write()
{
    _worldPacket << int32(Tab);
    _worldPacket << Size<uint32>(Entry);
    _worldPacket << OptionalInit(WeeklyBonusMoney);
    _worldPacket.FlushBits();

    for (GuildBankLogEntry const& logEntry : Entry)
    {
        _worldPacket << logEntry.PlayerGUID;
        _worldPacket << uint32(logEntry.TimeOffset);
        _worldPacket << int8(logEntry.EntryType);

        _worldPacket << OptionalInit(logEntry.Money);
        _worldPacket << OptionalInit(logEntry.ItemID);
        _worldPacket << OptionalInit(logEntry.Count);
        _worldPacket << OptionalInit(logEntry.OtherTab);
        _worldPacket.FlushBits();

        if (logEntry.Money)
            _worldPacket << uint64(*logEntry.Money);

        if (logEntry.ItemID)
            _worldPacket << int32(*logEntry.ItemID);

        if (logEntry.Count)
            _worldPacket << int32(*logEntry.Count);

        if (logEntry.OtherTab)
            _worldPacket << int8(*logEntry.OtherTab);
    }

    if (WeeklyBonusMoney)
        _worldPacket << uint64(*WeeklyBonusMoney);

    return &_worldPacket;
}

void GuildBankTextQuery::Read()
{
    _worldPacket >> Tab;
}

WorldPacket const* GuildBankTextQueryResult::Write()
{
    _worldPacket << int32(Tab);

    _worldPacket << SizedString::BitsSize<14>(Text);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Text);

    return &_worldPacket;
}

void GuildBankSetTabText::Read()
{
    _worldPacket >> Tab;
    _worldPacket >> SizedString::BitsSize<14>(TabText);

    _worldPacket >> SizedString::Data(TabText);
}

void GuildQueryNews::Read()
{
    _worldPacket >> GuildGUID;
}

ByteBuffer& operator<<(ByteBuffer& data, GuildNewsEvent const& newsEvent)
{
    data << int32(newsEvent.Id);
    data << newsEvent.CompletedDate;
    data << int8(newsEvent.Type);
    data << int32(newsEvent.Flags);

    for (std::size_t i = 0; i < newsEvent.Data.size(); ++i)
        data << int32(newsEvent.Data[i]);

    data << newsEvent.MemberGuid;
    data << Size<uint32>(newsEvent.MemberList);

    for (ObjectGuid const& memberGuid : newsEvent.MemberList)
        data << memberGuid;

    data << OptionalInit(newsEvent.Item);
    data.FlushBits();

    if (newsEvent.Item)
        data << *newsEvent.Item;  // WorldPackets::Item::ItemInstance

    return data;
}

WorldPacket const* GuildNews::Write()
{
    _worldPacket << Size<uint32>(NewsEvents);
    for (GuildNewsEvent const& newsEvent : NewsEvents)
        _worldPacket << newsEvent;

    return &_worldPacket;
}

void GuildNewsUpdateSticky::Read()
{
    _worldPacket >> GuildGUID;
    _worldPacket >> NewsID;
    _worldPacket >> Bits<1>(Sticky);
}

void GuildSetGuildMaster::Read()
{
    _worldPacket >> SizedString::BitsSize<9>(NewMasterName);

    _worldPacket >> SizedString::Data(NewMasterName);
}

WorldPacket const* GuildChallengeUpdate::Write()
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

void SaveGuildEmblem::Read()
{
    _worldPacket >> Vendor;
    _worldPacket >> EStyle;
    _worldPacket >> EColor;
    _worldPacket >> BStyle;
    _worldPacket >> BColor;
    _worldPacket >> Bg;
}

WorldPacket const* PlayerSaveGuildEmblem::Write()
{
    _worldPacket << int32(Error);

    return &_worldPacket;
}

void GuildSetAchievementTracking::Read()
{
    _worldPacket >> Size<uint32>(AchievementIDs);

    for (uint32& achievementID : AchievementIDs)
        _worldPacket >> achievementID;
}

WorldPacket const* GuildNameChanged::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << SizedString::BitsSize<7>(GuildName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(GuildName);

    return &_worldPacket;
}
}
