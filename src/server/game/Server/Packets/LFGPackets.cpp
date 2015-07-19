/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "LFGPackets.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket)
{
    data >> ticket.RequesterGuid;
    data >> ticket.Id;
    data >> ticket.Type;
    data >> ticket.Time;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket)
{
    data << ticket.RequesterGuid;
    data << int32(ticket.Id);
    data << int32(ticket.Type);
    data << uint32(ticket.Time);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgBootInfo const& bootInfo)
{
    data.WriteBit(bootInfo.VoteInProgress);
    data.WriteBit(bootInfo.VotePassed);
    data.WriteBit(bootInfo.MyVoteCompleted);
    data.WriteBit(bootInfo.MyVote);
    data.WriteBits(bootInfo.Reason.length(), 8);
    data.FlushBits();

    data << ObjectGuid(bootInfo.Target);
    data << uint32(bootInfo.TotalVotes);
    data << uint32(bootInfo.BootVotes);
    data << int32(bootInfo.TimeLeft);
    data << uint32(bootInfo.VotesNeeded);

    data.WriteString(std::string(bootInfo.Reason));

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerDungeonInfo const& playerDungeonInfo)
{
    data << playerDungeonInfo.Slot;
    data << playerDungeonInfo.CompletionQuantity;
    data << playerDungeonInfo.CompletionLimit;
    data << playerDungeonInfo.CompletionCurrencyID;
    data << playerDungeonInfo.SpecificQuantity;
    data << playerDungeonInfo.SpecificLimit;
    data << playerDungeonInfo.OverallQuantity;
    data << playerDungeonInfo.OverallLimit;
    data << playerDungeonInfo.PurseWeeklyQuantity;
    data << playerDungeonInfo.PurseWeeklyLimit;
    data << playerDungeonInfo.PurseQuantity;
    data << playerDungeonInfo.PurseLimit;
    data << playerDungeonInfo.Quantity;
    data << playerDungeonInfo.CompletedMask;
    data << playerDungeonInfo.ShortageRewardCount;

    data << playerDungeonInfo.Rewards;

    for (uint32 i = 0; i < playerDungeonInfo.ShortageRewardCount; i++)
        data << playerDungeonInfo.ShortageReward;

    data.WriteBit(playerDungeonInfo.FirstReward);
    data.WriteBit(playerDungeonInfo.ShortageEligible);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGPlayerRewards const& playerRewards)
{
    data << playerRewards.RewardItem;
    data << playerRewards.RewardItemQuantity;
    data << playerRewards.BonusCurrency;

    data.WriteBit(playerRewards.IsCurrency);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& clientBlackList)
{
    data.WriteBit(clientBlackList.PlayerGuid.is_initialized());
    data << clientBlackList.Slot;
    data.FlushBits();

    if (clientBlackList.PlayerGuid)
        data << *clientBlackList.PlayerGuid;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& clientBlackListSlot)
{
    data << uint32(clientBlackListSlot.Slot);
    data << uint32(clientBlackListSlot.Reason);
    data << uint32(clientBlackListSlot.SubReason1);
    data << uint32(clientBlackListSlot.SubReason2);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestRewards)
{
    data << playerQuestRewards.Mask;
    data << playerQuestRewards.RewardMoney;
    data << playerQuestRewards.RewardXP;
    data << playerQuestRewards.Item;
    data << playerQuestRewards.Currency;
    data << playerQuestRewards.BonusCurrency;

    data.WriteBit(playerQuestRewards.UnkBit);
    data.FlushBits();

    if (playerQuestRewards.UnkBit)
        data << playerQuestRewards.UnkWoD62;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest& joinRequest)
{
    data >> joinRequest.ActivityID;
    data >> joinRequest.RequiredItemLevel;

    auto nameLen = data.ReadBits(8);
    auto commentLen = data.ReadBits(11);
    auto voiceLen = data.ReadBits(8);

    joinRequest.Name = data.ReadString(nameLen);
    joinRequest.Comment = data.ReadString(commentLen);
    joinRequest.VoiceChat = data.ReadString(voiceLen);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest const& joinRequest)
{
    data << uint32(joinRequest.ActivityID);
    data << uint32(joinRequest.RequiredItemLevel);

    data.WriteBits(joinRequest.Name.length(), 8);
    data.WriteBits(joinRequest.Comment.length(), 11);
    data.WriteBits(joinRequest.VoiceChat.length(), 8);
    data.FlushBits();

    data.WriteString(joinRequest.Name);
    data.WriteString(joinRequest.Comment);
    data.WriteString(joinRequest.VoiceChat);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& item)
{
    data << item.ItemID;
    data << item.Quantity;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& currency)
{
    data << currency.CurrencyID;
    data << currency.Quantity;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListBlacklist const& listBlackList)
{
    data << listBlackList.Entries;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListBlacklistEntry const& listBlackListEntry)
{
    data << listBlackListEntry.ActivityID;
    data << listBlackListEntry.Reason;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGProposalUpdatePlayer const& update)
{
    data << update.Roles;
    data.WriteBit(update.Me);
    data.WriteBit(update.SameParty);
    data.WriteBit(update.Responded);
    data.WriteBit(update.Accepted);

    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGSearchResultPlayer const& player)
{
    // Casting because hard as fuck to know which is which xD
    // Order is probably not at all correct. Will have to use some sniffs for this.
    data << ObjectGuid(player.Guid);
    data << uint32(player.SpecID);
    data << uint8(player.ChrClass);
    data << uint8(player.Level);
    data << uint8(player.Race);
    data << uint32(player.Agility);
    data << uint32(player.Armor);
    data << uint32(player.AttackPower);
    data << uint32(player.BlockRating);
    data << uint32(player.ParryRating);
    data << uint32(player.HasteRating);
    data << float(player.GearRating);
    data << float(player.AvgItemLevel);
    data << uint32(player.CritMelee);
    data << uint32(player.CritRanged);
    data << uint32(player.CritSpell);
    data << uint32(player.DefenseRating);
    data << uint32(player.DodgeRating);
    data << float(player.Mp5);
    data << float(player.Mp5InCombat);
    data << uint32(player.PlusHealing);
    data << uint32(player.MaxHealth);
    data << uint32(player.MaxMana);
    data << uint32(player.SpellDamage);
    data << uint32(player.BossKills);
    data << float(player.Expertise);
    data << uint32(player.InstanceCompletedMask);
    data << uint32(player.NativeRealmAddress);
    data << uint32(player.VirtualRealmAddress);
    data << ObjectGuid(player.PartyGuid);
    data << uint8(player.RolesDesired);
    data << uint32(player.Area);
    data << uint8(player.Status);
    data << uint64(player.InstanceID);
    data << uint32(player.ChangeMask);

    data.WriteBits(player.Comment.length(), 8);
    data.WriteBit(player.IsLeader);
    data.FlushBits();

    data.WriteString(std::string(player.Comment));

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGSearchResultParty const& party)
{
    data << party.Guid;
    data << party.ChangeMask;
    data << party.InstanceID;
    data << party.InstanceCompletedMask;
    data << party.Needs[3];

    data.WriteBits(party.Comment.length(), 8);
    data.FlushBits();

    data.WriteString(party.Comment);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGRoleCheckUpdateMember const& member)
{
    data << member.Guid;
    data << member.RolesDesired;
    data << member.Level;

    data.WriteBit(member.RoleCheckComplete);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::LFG::LFGJoinResult::Write()
{
    _worldPacket << Result;
    _worldPacket << BlackList;
    _worldPacket << ResultDetail;
    _worldPacket << Ticket;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGListJoinResult::Write()
{
    _worldPacket << Ticket;
    _worldPacket << Result;
    _worldPacket << ResultDetail;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGQueueStatus::Write()
{
    _worldPacket << Ticket;
    _worldPacket << Slot;
    _worldPacket << AvgWaitTime;
    _worldPacket << QueuedTime;

    for (uint32 i = 0; i < 3; i++)
    {
        _worldPacket << AvgWaitTimeByRole[i];
        _worldPacket << LastNeeded[i];
    }

    _worldPacket << AvgWaitTimeMe;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGRoleCheckUpdate::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << RoleCheckStatus;
    _worldPacket << JoinSlotsCount;
    _worldPacket << BgQueueID;
    _worldPacket << ActivityID;
    _worldPacket << MembersCount;

    for (uint32 i = 0; i < JoinSlotsCount; i++)
        _worldPacket << JoinSlots;

    for (uint32 i = 0; i < MembersCount; i++)
        _worldPacket << Members;

    _worldPacket.WriteBit(IsBeginning);
    _worldPacket.WriteBit(ShowRoleCheck);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGUpdateStatus::Write()
{
    _worldPacket << Ticket;
    _worldPacket << SubType;
    _worldPacket << Reason;

    for (uint32 i = 0; i < 3; i++)
        _worldPacket << Needs[i];

    _worldPacket << SlotsCount;
    _worldPacket << RequestedRoles;
    _worldPacket << SuspendedPlayersCount;

    for (uint32 i = 0; i < SlotsCount; i++)
        _worldPacket << Slots;

    for (uint32 i = 0; i < SuspendedPlayersCount; i++)
        _worldPacket << SuspendedPlayers;

    _worldPacket.WriteBit(IsParty);
    _worldPacket.WriteBit(NotifyUI);
    _worldPacket.WriteBit(Joined);
    _worldPacket.WriteBit(LfgJoined);
    _worldPacket.WriteBit(Queued);
    _worldPacket.WriteBits(Comment.length(), 8);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(Comment);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGListUpdateStatus::Write()
{
    _worldPacket << Ticket;
    _worldPacket << Request;
    _worldPacket << Unk;
    _worldPacket << Reason;

    _worldPacket.WriteBit(Listed);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGListUpdateBlacklist::Write()
{
    _worldPacket << BlacklistEntryCount;
    for (uint32 i = 0; i < BlacklistEntryCount; i++)
        _worldPacket << Blacklist;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGProposalUpdate::Write()
{
    _worldPacket << Ticket;
    _worldPacket << InstanceID;
    _worldPacket << ProposalID;
    _worldPacket << Slot;
    _worldPacket << State;
    _worldPacket << CompletedMask;
    _worldPacket << PlayersCount;

    for (uint32 i = 0; i < PlayersCount; i++)
        _worldPacket << Players;

    _worldPacket.WriteBit(ValidCompletedMask);
    _worldPacket.WriteBit(ProposalSilent);
    _worldPacket.FlushBits;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGSearchResults::Write()
{
    _worldPacket << Ticket;
    _worldPacket << CountTotalParties;
    _worldPacket << CountTotalPlayers;
    _worldPacket << SlotID;
    _worldPacket << SlotType;

    _worldPacket << Removes;

    _worldPacket.WriteBit(Incremental);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGSlotInvalid::Write()
{
    _worldPacket << Reason;
    _worldPacket << SubReason1;
    _worldPacket << SubReason2;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGOfferContinue::Write()
{
    _worldPacket << Slot;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGBootPlayer::Write()
{
    _worldPacket << Info;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPartyInfo::Write()
{
    _worldPacket << Player;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPlayerInfo::Write()
{
    _worldPacket << BlackList;
    _worldPacket << Dungeon;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPlayerReward::Write()
{
    _worldPacket << ActualSlot;
    _worldPacket << QueuedSlot;
    _worldPacket << RewardMoney;
    _worldPacket << AddedXP;
    _worldPacket << RewardsCount;

    for (uint32 i = 0; i < RewardsCount; i++)
        _worldPacket << Rewards;

    return &_worldPacket;
}

void WorldPackets::LFG::LFGListJoin::Read()
{
    _worldPacket >> Info;
}

void WorldPackets::LFG::LFGListUpdateRequest::Read()
{
    _worldPacket >> Info;
    _worldPacket >> Ticket;
}

void WorldPackets::LFG::LFGListLeave::Read()
{
    _worldPacket >> Ticket;
}

void WorldPackets::LFG::DfLeave::Read()
{
    _worldPacket >> Ticket;
}

void WorldPackets::LFG::DfSearchJoin::Read()
{
    _worldPacket >> Slot;
}

void WorldPackets::LFG::DfSearchLeave::Read()
{
    _worldPacket >> Slot;
}

void WorldPackets::LFG::DfGetSystemInfo::Read()
{
    _worldPacket >> Player;
    _worldPacket >> PartyIndex;
}

void WorldPackets::LFG::DfSetComment::Read()
{
    _worldPacket >> Ticket;

    auto commentLen = _worldPacket.ReadBits(8);
    Comment = _worldPacket.ReadString(commentLen);
}

void WorldPackets::LFG::DfSetRoles::Read()
{
    _worldPacket >> RolesDesired;
    _worldPacket >> PartyIndex;
}

//void WorldPackets::LFG::DfSetNeeds::Read()
//{
//}

void WorldPackets::LFG::DfBootPlayerVote::Read()
{
    _worldPacket >> Vote;
}

void WorldPackets::LFG::DfTeleport::Read()
{
    _worldPacket >> TeleportOut;
}

void WorldPackets::LFG::DfProposalResponse::Read()
{
    _worldPacket >> Ticket;
    _worldPacket >> InstanceID;
    _worldPacket >> ProposalID;

    Accepted = _worldPacket.ReadBit();
}

void WorldPackets::LFG::DfJoin::Read()
{
    _worldPacket >> QueueAsGroup;
    auto commentLength = _worldPacket.ReadBits(8);
    _worldPacket >> PartyIndex;
    _worldPacket >> Roles;
    _worldPacket >> slotsCount;

    for (uint32 i = 0; i < 3; i++)
        _worldPacket >> Needs[i];

    Comment = _worldPacket.ReadString(commentLength);

    for (uint32 i = 0; i < slotsCount; i++)
        _worldPacket >> Slots;
}