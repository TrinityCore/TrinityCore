/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& clientBlackList)
{
    data.WriteBit(clientBlackList.PlayerGuid.is_initialized());
    data.FlushBits();

    data << clientBlackList.Slot;

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
    _worldPacket << JoinSlots.size();
    _worldPacket << BgQueueID;
    _worldPacket << ActivityID;
    _worldPacket << Members.size();

    for (uint32 i = 0; i < JoinSlots.size(); i++)
        _worldPacket << JoinSlots;

    for (auto const& members : Members)
    {
        _worldPacket << members.Guid;
        _worldPacket << members.RoleCheckComplete;
        _worldPacket << members.RolesDesired;
        _worldPacket << members.Level;
    }

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
    _worldPacket << Players.size();

    for (auto const& players : Players)
    {
        _worldPacket << players.Roles;
        _worldPacket.WriteBit(players.Me);
        _worldPacket.WriteBit(players.SameParty);
        _worldPacket.WriteBit(players.Responded);
        _worldPacket.WriteBit(players.Accepted);

        _worldPacket.FlushBits();
    }

    _worldPacket.WriteBit(ValidCompletedMask);
    _worldPacket.WriteBit(ProposalSilent);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGSearchResults::Write()
{
    _worldPacket << Ticket;
    _worldPacket << CountTotalParties;
    _worldPacket << CountTotalPlayers;
    _worldPacket << SlotID;
    _worldPacket << SlotType;

    for (auto const& party : Parties)
    {
        _worldPacket << party.Guid;
        _worldPacket << party.ChangeMask;
        _worldPacket << party.InstanceID;
        _worldPacket << party.InstanceCompletedMask;
        _worldPacket << party.Needs[3];

        _worldPacket.WriteBits(party.Comment.length(), 8);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(party.Comment);
    }

    for (auto const& player : Players)
    {
        _worldPacket << player.Guid;
        _worldPacket << uint32(player.SpecID);
        _worldPacket << uint8(player.ChrClass);
        _worldPacket << uint8(player.Level);
        _worldPacket << uint8(player.Race);
        _worldPacket << uint32(player.Agility);
        _worldPacket << uint32(player.Armor);
        _worldPacket << uint32(player.AttackPower);
        _worldPacket << uint32(player.BlockRating);
        _worldPacket << uint32(player.ParryRating);
        _worldPacket << uint32(player.HasteRating);
        _worldPacket << float(player.GearRating);
        _worldPacket << float(player.AvgItemLevel);
        _worldPacket << uint32(player.CritMelee);
        _worldPacket << uint32(player.CritRanged);
        _worldPacket << uint32(player.CritSpell);
        _worldPacket << uint32(player.DefenseRating);
        _worldPacket << uint32(player.DodgeRating);
        _worldPacket << float(player.Mp5);
        _worldPacket << float(player.Mp5InCombat);
        _worldPacket << uint32(player.PlusHealing);
        _worldPacket << uint32(player.MaxHealth);
        _worldPacket << uint32(player.MaxMana);
        _worldPacket << uint32(player.SpellDamage);
        _worldPacket << uint32(player.BossKills);
        _worldPacket << float(player.Expertise);
        _worldPacket << uint32(player.InstanceCompletedMask);
        _worldPacket << uint32(player.NativeRealmAddress);
        _worldPacket << uint32(player.VirtualRealmAddress);
        _worldPacket << ObjectGuid(player.PartyGuid);
        _worldPacket << uint8(player.RolesDesired);
        _worldPacket << uint32(player.Area);
        _worldPacket << uint8(player.Status);
        _worldPacket << uint64(player.InstanceID);
        _worldPacket << uint32(player.ChangeMask);

        _worldPacket.WriteBits(player.Comment.length(), 8);
        _worldPacket.WriteBit(player.IsLeader);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(player.Comment);
    }

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
    _worldPacket.WriteBit(Info.VoteInProgress);
    _worldPacket.WriteBit(Info.VotePassed);
    _worldPacket.WriteBit(Info.MyVoteCompleted);
    _worldPacket.WriteBit(Info.MyVote);
    _worldPacket.WriteBits(Info.Reason.length(), 8);
    _worldPacket.FlushBits();

    _worldPacket << ObjectGuid(Info.Target);
    _worldPacket << uint32(Info.TotalVotes);
    _worldPacket << uint32(Info.BootVotes);
    _worldPacket << int32(Info.TimeLeft);
    _worldPacket << uint32(Info.VotesNeeded);

    _worldPacket.WriteString(std::string(Info.Reason));

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPartyInfo::Write()
{
    _worldPacket << Player;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPlayerInfo::Write()
{
    _worldPacket << int16(Dungeon.size());
    _worldPacket << BlackList;

    for (auto const& dungeon : Dungeon)
    {
        {
            _worldPacket << int32(dungeon.Slot);
            _worldPacket << int32(dungeon.CompletionQuantity);
            _worldPacket << int32(dungeon.CompletionLimit);
            _worldPacket << int32(dungeon.CompletionCurrencyID);
            _worldPacket << int32(dungeon.SpecificQuantity);
            _worldPacket << int32(dungeon.SpecificLimit);
            _worldPacket << int32(dungeon.OverallQuantity);
            _worldPacket << int32(dungeon.OverallLimit);
            _worldPacket << int32(dungeon.PurseWeeklyQuantity);
            _worldPacket << int32(dungeon.PurseWeeklyLimit);
            _worldPacket << int32(dungeon.PurseQuantity);
            _worldPacket << int32(dungeon.PurseLimit);
            _worldPacket << int32(dungeon.Quantity);
            _worldPacket << int32(dungeon.CompletedMask);

            _worldPacket << int32(dungeon.ShortageReward.size());

            _worldPacket << dungeon.Rewards;

            for (auto const& reward : dungeon.ShortageReward)
                _worldPacket << reward;

            _worldPacket.WriteBit(dungeon.FirstReward);
            _worldPacket.WriteBit(dungeon.ShortageEligible);
            _worldPacket.FlushBits();
        }
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPlayerReward::Write()
{
    _worldPacket << ActualSlot;
    _worldPacket << QueuedSlot;
    _worldPacket << RewardMoney;
    _worldPacket << AddedXP;
    _worldPacket << Rewards.size();

    for (auto const& rewards : Rewards)
    {
        _worldPacket << rewards.RewardItem;
        _worldPacket << rewards.RewardItemQuantity;
        _worldPacket << rewards.BonusCurrency;

        _worldPacket.WriteBit(rewards.IsCurrency);
        _worldPacket.FlushBits();
    }

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