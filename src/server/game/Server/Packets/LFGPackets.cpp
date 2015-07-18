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

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LfgBootInfo& bootInfo)
{
    data >> bootInfo.VoteInProgress;
    data >> bootInfo.VotePassed;
    data >> bootInfo.MyVoteCompleted;
    data >> bootInfo.MyVote;
    data >> bootInfo.Target;
    data >> bootInfo.TotalVotes;
    data >> bootInfo.BootVotes;
    data >> bootInfo.TimeLeft;
    data >> bootInfo.VotesNeeded;
    data >> bootInfo.Reason;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::ClientLFGBlackList& clientBlackList)
{
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::ClientLFGBlackListSlot& clientBlackListSlot)
{
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgBootInfo const& bootInfo)
{
    data << bool(bootInfo.VoteInProgress);
    data << bool(bootInfo.VotePassed);
    data << bool(bootInfo.MyVoteCompleted);
    data << bool(bootInfo.MyVote);
    data << ObjectGuid(bootInfo.Target);
    data << uint32(bootInfo.TotalVotes);
    data << uint32(bootInfo.BootVotes);
    data << int32(bootInfo.TimeLeft);
    data << uint32(bootInfo.VotesNeeded);
    data << std::string(bootInfo.Reason);

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

    data << playerDungeonInfo.FirstReward;
    data << playerDungeonInfo.ShortageEligible;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGPlayerRewards const& playerRewards)
{
    data << playerRewards.RewardItem;
    data << playerRewards.RewardItemQuantity;
    data << playerRewards.BonusCurrency;
    data << playerRewards.IsCurrency;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGBlackList const& clientBlackList)
{
    data << clientBlackList.Guid;
    data << clientBlackList.Slots;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::ClientLFGBlackListSlot const& clientBlackListSlot)
{
    data << clientBlackListSlot.Slot;
    data << clientBlackListSlot.Reason;
    data << clientBlackListSlot.SubReason1;
    data << clientBlackListSlot.SubReason2;
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
    data << playerQuestRewards.UnkBit;

    if (playerQuestRewards.UnkBit)
        data << playerQuestRewards.UnkWoD62;

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest& joinRequest)
{
    data >> joinRequest.ActivityID;
    data >> joinRequest.RequiredItemLevel;
    data >> joinRequest.Name;
    data >> joinRequest.Comment;
    data >> joinRequest.VoiceChat;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGListJoinRequest const& joinRequest)
{
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& blackList)
{
    data.WriteBit(blackList.PlayerGuid.is_initialized());
    data << blackList.Slot;

    if (blackList.PlayerGuid)
        data << *blackList.PlayerGuid;

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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& blackListSlot)
{
    data << blackListSlot.Slot;
    data << blackListSlot.Reason;
    data << blackListSlot.SubReason1;
    data << blackListSlot.SubReason2;

    return data;
}

WorldPacket const* WorldPackets::LFG::ClientLFGJoinResult::Write()
{
    _worldPacket << Result;
    _worldPacket << BlackList;
    _worldPacket << ResultDetail;
    _worldPacket << Ticket;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGListJoinResult::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGQueueStatus::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGRoleCheckUpdate::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGUpdateStatus::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGListUpdateStatus::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGListUpdateBlacklist::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGProposalUpdatePlayer::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGProposalUpdate::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGSearchResults::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGSlotInvalid::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGOfferContinue::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLfgBootPlayer::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLfgPartyInfo::Write()
{
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLfgPlayerInfo::Write()
{
    _worldPacket << BlackList;
    _worldPacket << Dungeon;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGPlayerReward::Write()
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

void WorldPackets::LFG::UserClientLFGListJoin::Read()
{
    _worldPacket >> Info;
}

void WorldPackets::LFG::UserClientLFGListUpdateRequest::Read()
{
    _worldPacket >> Info;
    _worldPacket >> Ticket;
}

void WorldPackets::LFG::UserClientLFGListLeave::Read()
{
    _worldPacket >> Ticket;
}

void WorldPackets::LFG::UserClientDFLeave::Read()
{
    _worldPacket >> Ticket;
}

void WorldPackets::LFG::UserClientDFSearchJoin::Read()
{
    _worldPacket >> Slot;
}

void WorldPackets::LFG::UserClientDFSearchLeave::Read()
{
    _worldPacket >> Slot;
}

void WorldPackets::LFG::UserClientDFGetSystemInfo::Read()
{
    _worldPacket >> Player;
    _worldPacket >> PartyIndex;
}

void WorldPackets::LFG::UserClientDFSetComment::Read()
{
    _worldPacket >> Ticket;
    _worldPacket >> Comment;
}

void WorldPackets::LFG::UserClientDFSetRoles::Read()
{
    _worldPacket >> RolesDesired;
    _worldPacket >> PartyIndex;
}

//void WorldPackets::LFG::UserClientDFSetNeeds::Read()
//{
//}

void WorldPackets::LFG::UserClientDFBootPlayerVote::Read()
{
    _worldPacket >> Vote;
}

void WorldPackets::LFG::UserClientDFTeleport::Read()
{
    _worldPacket >> TeleportOut;
}

void WorldPackets::LFG::UserClientDFProposalResponse::Read()
{
    _worldPacket >> Ticket;
    _worldPacket >> InstanceID;
    _worldPacket >> ProposalID;
    _worldPacket >> Accepted;
}

void WorldPackets::LFG::UserClientDFJoin::Read()
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