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

void WorldPackets::Guild::GuildQueryRecipes::Read()
{
    GuildGUID[5] = _worldPacket.ReadBit();
    GuildGUID[6] = _worldPacket.ReadBit();
    GuildGUID[1] = _worldPacket.ReadBit();
    GuildGUID[4] = _worldPacket.ReadBit();
    GuildGUID[2] = _worldPacket.ReadBit();
    GuildGUID[7] = _worldPacket.ReadBit();
    GuildGUID[0] = _worldPacket.ReadBit();
    GuildGUID[3] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(GuildGUID[3]);
    _worldPacket.ReadByteSeq(GuildGUID[1]);
    _worldPacket.ReadByteSeq(GuildGUID[0]);
    _worldPacket.ReadByteSeq(GuildGUID[5]);
    _worldPacket.ReadByteSeq(GuildGUID[4]);
    _worldPacket.ReadByteSeq(GuildGUID[2]);
    _worldPacket.ReadByteSeq(GuildGUID[6]);
    _worldPacket.ReadByteSeq(GuildGUID[7]);
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

WorldPacket const* WorldPackets::Guild::GuildRosterUpdate::Write()
{
    _worldPacket.WriteBits(MemberData.size(), 18);

    for (GuildRosterMemberData const& member : MemberData)
    {
        _worldPacket.WriteBits(member.Name.length(), 7);
        _worldPacket.WriteBit(member.Guid[3]);
        _worldPacket.WriteBit(member.Guid[4]);
        _worldPacket.WriteBit(member.Authenticated);
        _worldPacket.WriteBit(member.SorEligible);
        _worldPacket.WriteBits(member.Note.length(), 8);
        _worldPacket.WriteBits(member.OfficerNote.length(), 8);
        _worldPacket.WriteBit(member.Guid[0]);
        _worldPacket.WriteBit(member.Guid[1]);
        _worldPacket.WriteBit(member.Guid[2]);
        _worldPacket.WriteBit(member.Guid[6]);
        _worldPacket.WriteBit(member.Guid[5]);
        _worldPacket.WriteBit(member.Guid[7]);
    }

    _worldPacket.FlushBits();

    for (GuildRosterMemberData const& rosterMemberData : MemberData)
    {
        _worldPacket << uint8(rosterMemberData.Gender);
        _worldPacket << uint32(rosterMemberData.GuildRepToCap);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[1]);
        _worldPacket << uint64(rosterMemberData.TotalXP);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[2]);

        for (uint8 i = 0; i < 2; i++)
        {
            _worldPacket << uint32(rosterMemberData.Profession[i].Rank);
            _worldPacket << uint32(rosterMemberData.Profession[i].DbID);
            _worldPacket << uint32(rosterMemberData.Profession[i].Step);
        }

        _worldPacket.WriteByteSeq(rosterMemberData.Guid[0]);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[6]);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[7]);
        _worldPacket << uint32(rosterMemberData.RankID);
        _worldPacket.WriteString(rosterMemberData.Note);
        _worldPacket.WriteString(rosterMemberData.OfficerNote);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[4]);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[5]);
        _worldPacket << uint32(rosterMemberData.GuildReputation);
        _worldPacket << uint32(rosterMemberData.PersonalAchievementPoints);
        _worldPacket << float(rosterMemberData.LastSave);
        _worldPacket << uint64(rosterMemberData.WeeklyXP);
        _worldPacket << uint8(rosterMemberData.Level);
        _worldPacket << uint8(rosterMemberData.ClassID);
        _worldPacket.WriteByteSeq(rosterMemberData.Guid[3]);
        _worldPacket << uint8(rosterMemberData.Status);
        _worldPacket << uint32(rosterMemberData.AreaID);
        _worldPacket.WriteString(rosterMemberData.Name);
        _worldPacket << int32(rosterMemberData.VirtualRealmAddress); // Todo: Validate
    }

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

WorldPacket const* WorldPackets::Guild::GuildKnownRecipes::Write()
{
    _worldPacket.WriteBits(Recipes.size(), 16);

    for (GuildRecipesData recipe : Recipes)
    {
        _worldPacket << int32(recipe.SkillLineID);
        for (uint16 i = 0; i < recipe.SkillLineBitArray.max_size(); i++)
            _worldPacket << uint8(recipe.SkillLineBitArray[i]);
    }

    return &_worldPacket;
}

void WorldPackets::Guild::GuildQueryMembersForRecipe::Read()
{
    _worldPacket >> SpellID;
    _worldPacket >> SkillLineID;
    _worldPacket >> UniqueBit;

    GuildGUID[4] = _worldPacket.ReadBit();
    GuildGUID[1] = _worldPacket.ReadBit();
    GuildGUID[0] = _worldPacket.ReadBit();
    GuildGUID[3] = _worldPacket.ReadBit();
    GuildGUID[6] = _worldPacket.ReadBit();
    GuildGUID[7] = _worldPacket.ReadBit();
    GuildGUID[5] = _worldPacket.ReadBit();
    GuildGUID[2] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(GuildGUID[1]);
    _worldPacket.ReadByteSeq(GuildGUID[6]);
    _worldPacket.ReadByteSeq(GuildGUID[5]);
    _worldPacket.ReadByteSeq(GuildGUID[0]);
    _worldPacket.ReadByteSeq(GuildGUID[3]);
    _worldPacket.ReadByteSeq(GuildGUID[7]);
    _worldPacket.ReadByteSeq(GuildGUID[2]);
    _worldPacket.ReadByteSeq(GuildGUID[4]);
}

WorldPacket const* WorldPackets::Guild::GuildMembersWithRecipe::Write()
{
    _worldPacket.WriteBits(Members.size(), 26);

    for (ObjectGuid guid : Members)
    {
        _worldPacket.WriteBit(guid[2]);
        _worldPacket.WriteBit(guid[3]);
        _worldPacket.WriteBit(guid[1]);
        _worldPacket.WriteBit(guid[6]);
        _worldPacket.WriteBit(guid[0]);
        _worldPacket.WriteBit(guid[7]);
        _worldPacket.WriteBit(guid[4]);
        _worldPacket.WriteBit(guid[3]);
    }

    _worldPacket.FlushBits();

    for (ObjectGuid guid : Members)
    {
        _worldPacket.WriteByteSeq(guid[1]);
        _worldPacket.WriteByteSeq(guid[5]);
        _worldPacket.WriteByteSeq(guid[6]);
        _worldPacket.WriteByteSeq(guid[7]);
        _worldPacket.WriteByteSeq(guid[2]);
        _worldPacket.WriteByteSeq(guid[3]);
        _worldPacket.WriteByteSeq(guid[0]);
        _worldPacket.WriteByteSeq(guid[4]);
    }

    _worldPacket << int32(SpellID);
    _worldPacket << uint32(SkillLineID);

    return &_worldPacket;
}

void WorldPackets::Guild::GuildQueryMemberRecipes::Read()
{
    _worldPacket >> SkillLineID;

    GuildMember[2] = _worldPacket.ReadBit();
    GuildGUID[1] = _worldPacket.ReadBit();
    GuildMember[1] = _worldPacket.ReadBit();
    GuildGUID[0] = _worldPacket.ReadBit();
    GuildGUID[6] = _worldPacket.ReadBit();
    GuildMember[7] = _worldPacket.ReadBit();
    GuildGUID[4] = _worldPacket.ReadBit();
    GuildGUID[3] = _worldPacket.ReadBit();
    GuildGUID[7] = _worldPacket.ReadBit();
    GuildMember[5] = _worldPacket.ReadBit();
    GuildMember[0] = _worldPacket.ReadBit();
    GuildGUID[5] = _worldPacket.ReadBit();
    GuildMember[3] = _worldPacket.ReadBit();
    GuildMember[6] = _worldPacket.ReadBit();
    GuildGUID[2] = _worldPacket.ReadBit();
    GuildMember[4] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(GuildMember[2]);
    _worldPacket.ReadByteSeq(GuildMember[6]);
    _worldPacket.ReadByteSeq(GuildGUID[4]);
    _worldPacket.ReadByteSeq(GuildGUID[2]);
    _worldPacket.ReadByteSeq(GuildMember[1]);
    _worldPacket.ReadByteSeq(GuildGUID[7]);
    _worldPacket.ReadByteSeq(GuildGUID[3]);
    _worldPacket.ReadByteSeq(GuildGUID[1]);
    _worldPacket.ReadByteSeq(GuildMember[3]);
    _worldPacket.ReadByteSeq(GuildMember[0]);
    _worldPacket.ReadByteSeq(GuildGUID[0]);
    _worldPacket.ReadByteSeq(GuildMember[7]);
    _worldPacket.ReadByteSeq(GuildMember[4]);
    _worldPacket.ReadByteSeq(GuildGUID[5]);
    _worldPacket.ReadByteSeq(GuildGUID[6]);
    _worldPacket.ReadByteSeq(GuildMember[5]);
}

WorldPacket const* WorldPackets::Guild::GuildMemberRecipes::Write()
{
    _worldPacket.WriteBit(Member[0]);
    _worldPacket.WriteBit(Member[3]);
    _worldPacket.WriteBit(Member[7]);
    _worldPacket.WriteBit(Member[4]);
    _worldPacket.WriteBit(Member[6]);
    _worldPacket.WriteBit(Member[2]);
    _worldPacket.WriteBit(Member[1]);
    _worldPacket.WriteBit(Member[5]);

    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(Member[0]);
    _worldPacket.WriteByteSeq(Member[1]);
    _worldPacket.WriteByteSeq(Member[7]);
    _worldPacket.WriteByteSeq(Member[4]);
    _worldPacket.WriteByteSeq(Member[5]);

    _worldPacket << int32(SkillRank);

    for (uint16 i = 0; i < SkillLineBitArray.max_size(); i++)
        _worldPacket << uint8(SkillLineBitArray[i]);

    _worldPacket.WriteByteSeq(Member[3]);
    _worldPacket.WriteByteSeq(Member[6]);
    _worldPacket.WriteByteSeq(Member[2]);

    _worldPacket << int32(SkillLineID);
    _worldPacket << int32(SkillStep);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRewardItem const& rewardItem)
{
    data << uint32(rewardItem.MinGuildRep);
    data << uint32(rewardItem.RaceMask);
    data << uint32(rewardItem.ItemID);
    data << uint64(rewardItem.Cost);
    data << uint32(rewardItem.Unk4);
    data << uint32(rewardItem.AchievementRequired);

    return data;
}

void WorldPackets::Guild::RequestGuildRewardsList::Read()
{
    _worldPacket >> CurrentVersion;
}

WorldPacket const* WorldPackets::Guild::GuildRewardList::Write()
{
    _worldPacket.WriteBits(RewardItems.size(), 21);
    _worldPacket.FlushBits();

    for (GuildRewardItem const& item : RewardItems)
        _worldPacket << item;

    _worldPacket << int32(Version);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildChallengeUpdate::Write()
{
    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
        _worldPacket << int32(Xp[i]);

    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
        _worldPacket << int32(MaxLevelGold[i]);

    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
        _worldPacket << int32(MaxCount[i]);

    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
        _worldPacket << int32(Gold[i]);

    for (uint8 i = 0; i < MAX_GUILD_CHALLENGE_TYPES; i++)
        _worldPacket << int32(CurrentCount[i]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildChallengeCompleted::Write()
{
    _worldPacket << int32(ChallengeType);
    _worldPacket << int32(GoldAwarded);
    _worldPacket << int32(CurrentCount);
    _worldPacket << int32(XpAwarded);
    _worldPacket << int32(MaxCount);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildCommandResult::Write()
{
    _worldPacket << uint32(Command);
    _worldPacket << Name;
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildBankTextQueryResult::Write()
{
    _worldPacket.WriteBits(Text.length(), 14);
    _worldPacket.FlushBits();

    _worldPacket << uint32(Tab);
    _worldPacket.WriteString(Text);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildNameChanged::Write()
{
    _worldPacket.WriteBit(GuildGUID[5]);
    _worldPacket.WriteBits(GuildName.length(), 8);
    _worldPacket.WriteBit(GuildGUID[4]);
    _worldPacket.WriteBit(GuildGUID[0]);
    _worldPacket.WriteBit(GuildGUID[6]);
    _worldPacket.WriteBit(GuildGUID[3]);
    _worldPacket.WriteBit(GuildGUID[1]);
    _worldPacket.WriteBit(GuildGUID[7]);
    _worldPacket.WriteBit(GuildGUID[2]);

    _worldPacket.WriteByteSeq(GuildGUID[3]);
    _worldPacket.WriteByteSeq(GuildGUID[2]);
    _worldPacket.WriteByteSeq(GuildGUID[7]);
    _worldPacket.WriteByteSeq(GuildGUID[1]);
    _worldPacket.WriteByteSeq(GuildGUID[0]);
    _worldPacket.WriteByteSeq(GuildGUID[6]);
    _worldPacket.WriteString(GuildName);
    _worldPacket.WriteByteSeq(GuildGUID[4]);
    _worldPacket.WriteByteSeq(GuildGUID[5]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::QueryGuildInfoResponse::Write()
{
    _worldPacket << GuildGUID;
    _worldPacket << GuildName;

    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
        _worldPacket << Ranks[i].RankName;

    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
        _worldPacket << uint32(Ranks[i].RankOrder);

    for (uint8 i = 0; i < GUILD_RANKS_MAX_COUNT; ++i)
        _worldPacket << uint32(Ranks[i].RankID);

    _worldPacket << uint32(EmblemStyle);
    _worldPacket << uint32(EmblemColor);
    _worldPacket << uint32(BorderStyle);
    _worldPacket << uint32(BorderColor);
    _worldPacket << uint32(BackgroundColor);

    _worldPacket << uint32(RanksSize);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Guild::GuildRankData const& rankData)
{
    data << int32(rankData.RankID);

    for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; i++)
    {
        data << int32(rankData.TabWithdrawItemLimit[i]);
        data << int32(rankData.TabFlags[i]);
    }

    data << int32(rankData.WithdrawGoldLimit);
    data << int32(rankData.Flags);
    data.WriteString(rankData.RankName);
    data << int32(rankData.RankOrder);
    return data;
}

WorldPacket const* WorldPackets::Guild::GuildRanks::Write()
{
    _worldPacket.WriteBits(Ranks.size(), 18);

    for (GuildRankData const& rank : Ranks)
        _worldPacket.WriteBits(rank.RankName.length(), 7);

    _worldPacket.FlushBits();

    for (GuildRankData const& rank : Ranks)
        _worldPacket << rank;

    return &_worldPacket;
}

void WorldPackets::Guild::SetGuildMaster::Read()
{
    uint8 nameLen = _worldPacket.ReadBits(7);

    IsDethrone = _worldPacket.ReadBit();
    NewMasterName = _worldPacket.ReadString(nameLen);
}

WorldPacket const* WorldPackets::Guild::GuildNews::Write()
{
    _worldPacket.WriteBits(NewsEvents.size(), 21);

    for (GuildNewsEvent const& newsEvent : NewsEvents)
    {
        _worldPacket.WriteBits(newsEvent.MemberList.size(), 26);
        _worldPacket.WriteBit(newsEvent.MemberGuid[7]);

        for (ObjectGuid const& memberGuid : newsEvent.MemberList)
        {
            _worldPacket.WriteBit(memberGuid[7]);
            _worldPacket.WriteBit(memberGuid[1]);
            _worldPacket.WriteBit(memberGuid[5]);
            _worldPacket.WriteBit(memberGuid[3]);
            _worldPacket.WriteBit(memberGuid[4]);
            _worldPacket.WriteBit(memberGuid[6]);
            _worldPacket.WriteBit(memberGuid[0]);
            _worldPacket.WriteBit(memberGuid[2]);
        }

        _worldPacket.WriteBit(newsEvent.MemberGuid[0]);
        _worldPacket.WriteBit(newsEvent.MemberGuid[6]);
        _worldPacket.WriteBit(newsEvent.MemberGuid[5]);
        _worldPacket.WriteBit(newsEvent.MemberGuid[4]);
        _worldPacket.WriteBit(newsEvent.MemberGuid[3]);
        _worldPacket.WriteBit(newsEvent.MemberGuid[1]);
        _worldPacket.WriteBit(newsEvent.MemberGuid[2]);
    }

    _worldPacket.FlushBits();

    for (GuildNewsEvent const& newsEvent : NewsEvents)
    {
        for (ObjectGuid const& memberGuid : newsEvent.MemberList)
        {
            _worldPacket.WriteByteSeq(memberGuid[0]);
            _worldPacket.WriteByteSeq(memberGuid[1]);
            _worldPacket.WriteByteSeq(memberGuid[4]);
            _worldPacket.WriteByteSeq(memberGuid[7]);
            _worldPacket.WriteByteSeq(memberGuid[5]);
            _worldPacket.WriteByteSeq(memberGuid[6]);
            _worldPacket.WriteByteSeq(memberGuid[3]);
            _worldPacket.WriteByteSeq(memberGuid[2]);
        }

        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[5]);

        _worldPacket << uint32(newsEvent.Flags);

        for (int32 data : newsEvent.Data)
            _worldPacket << int32(data);

        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[7]);
        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[6]);
        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[2]);
        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[3]);
        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[0]);
        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[4]);
        _worldPacket.WriteByteSeq(newsEvent.MemberGuid[1]);

        _worldPacket << int32(newsEvent.Id);
        _worldPacket << int32(newsEvent.Type);
        _worldPacket.AppendPackedTime(newsEvent.CompletedDate);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildEventLogQueryResults::Write()
{
    _worldPacket.WriteBits(Entry.size(), 23);

    for (GuildEventEntry const& entry : Entry)
    {
        _worldPacket.WriteBit(entry.PlayerGUID[2]);
        _worldPacket.WriteBit(entry.PlayerGUID[4]);
        _worldPacket.WriteBit(entry.OtherGUID[7]);
        _worldPacket.WriteBit(entry.OtherGUID[6]);
        _worldPacket.WriteBit(entry.PlayerGUID[3]);
        _worldPacket.WriteBit(entry.OtherGUID[3]);
        _worldPacket.WriteBit(entry.OtherGUID[5]);
        _worldPacket.WriteBit(entry.PlayerGUID[7]);
        _worldPacket.WriteBit(entry.PlayerGUID[5]);
        _worldPacket.WriteBit(entry.PlayerGUID[0]);
        _worldPacket.WriteBit(entry.OtherGUID[4]);
        _worldPacket.WriteBit(entry.OtherGUID[2]);
        _worldPacket.WriteBit(entry.OtherGUID[0]);
        _worldPacket.WriteBit(entry.OtherGUID[1]);
        _worldPacket.WriteBit(entry.PlayerGUID[1]);
        _worldPacket.WriteBit(entry.PlayerGUID[6]);
    }

    _worldPacket.FlushBits();

    for (GuildEventEntry const& entry : Entry)
    {
        _worldPacket.WriteByteSeq(entry.OtherGUID[3]);
        _worldPacket.WriteByteSeq(entry.OtherGUID[2]);
        _worldPacket.WriteByteSeq(entry.OtherGUID[5]);

        _worldPacket << uint8(entry.RankID);

        _worldPacket.WriteByteSeq(entry.OtherGUID[4]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[0]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[4]);

        _worldPacket << uint32(entry.TransactionDate);

        _worldPacket.WriteByteSeq(entry.PlayerGUID[7]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[3]);
        _worldPacket.WriteByteSeq(entry.OtherGUID[0]);
        _worldPacket.WriteByteSeq(entry.OtherGUID[6]);
        _worldPacket.WriteByteSeq(entry.OtherGUID[7]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[5]);

        _worldPacket << uint8(entry.TransactionType);

        _worldPacket.WriteByteSeq(entry.OtherGUID[1]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[2]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[6]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[1]);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildBankLogQueryResults::Write()
{
    _worldPacket.WriteBit(WeeklyBonusMoney.has_value());
    _worldPacket.WriteBits(Entry.size(), 23);

    for (GuildBankLogEntry const& entry : Entry)
    {
        _worldPacket.WriteBit(entry.Money.has_value());
        _worldPacket.WriteBit(entry.PlayerGUID[4]);
        _worldPacket.WriteBit(entry.PlayerGUID[1]);
        _worldPacket.WriteBit(entry.ItemID.has_value());
        _worldPacket.WriteBit(entry.Count.has_value());
        _worldPacket.WriteBit(entry.PlayerGUID[2]);
        _worldPacket.WriteBit(entry.PlayerGUID[5]);
        _worldPacket.WriteBit(entry.PlayerGUID[3]);
        _worldPacket.WriteBit(entry.PlayerGUID[6]);
        _worldPacket.WriteBit(entry.PlayerGUID[0]);
        _worldPacket.WriteBit(entry.OtherTab.has_value());
        _worldPacket.WriteBit(entry.PlayerGUID[7]);
    }

    _worldPacket.FlushBits();

    for (GuildBankLogEntry const& entry : Entry)
    {
        _worldPacket.WriteByteSeq(entry.PlayerGUID[6]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[1]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[5]);

        if (entry.Count.has_value())
            _worldPacket << int32(*entry.Count);

        _worldPacket << int8(entry.EntryType);

        _worldPacket.WriteByteSeq(entry.PlayerGUID[2]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[4]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[0]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[7]);
        _worldPacket.WriteByteSeq(entry.PlayerGUID[3]);

        if (entry.ItemID.has_value())
            _worldPacket << int32(*entry.ItemID);

        _worldPacket << uint32(entry.TimeOffset);

        if (entry.Money.has_value())
            _worldPacket << uint64(*entry.Money);

        if (entry.OtherTab.has_value())
            _worldPacket << int8(*entry.OtherTab);
    }

    _worldPacket << int32(Tab);

    if (WeeklyBonusMoney.has_value())
        _worldPacket << uint64(*WeeklyBonusMoney);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Guild::GuildReputationReactionChanged::Write()
{
    _worldPacket.WriteBit(MemberGUID[1]);
    _worldPacket.WriteBit(MemberGUID[6]);
    _worldPacket.WriteBit(MemberGUID[2]);
    _worldPacket.WriteBit(MemberGUID[4]);
    _worldPacket.WriteBit(MemberGUID[0]);
    _worldPacket.WriteBit(MemberGUID[3]);
    _worldPacket.WriteBit(MemberGUID[7]);
    _worldPacket.WriteBit(MemberGUID[5]);

    _worldPacket.WriteByteSeq(MemberGUID[4]);
    _worldPacket.WriteByteSeq(MemberGUID[6]);
    _worldPacket.WriteByteSeq(MemberGUID[5]);
    _worldPacket.WriteByteSeq(MemberGUID[7]);
    _worldPacket.WriteByteSeq(MemberGUID[2]);
    _worldPacket.WriteByteSeq(MemberGUID[0]);
    _worldPacket.WriteByteSeq(MemberGUID[3]);
    _worldPacket.WriteByteSeq(MemberGUID[1]);

    return &_worldPacket;
}
