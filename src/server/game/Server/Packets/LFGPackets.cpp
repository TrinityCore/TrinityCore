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

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LfgPlayerDungeonInfo& playerDungeonInfo)
{
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGPlayerRewards& playerRewards)
{
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGBlackList& blackList)
{
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot& blackListSlot)
{
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward& playerQuestRewards)
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
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGPlayerRewards const& playerRewards)
{
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& blackList)
{
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& blackListSlot)
{
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestRewards)
{
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
    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::ClientLFGPlayerReward::Write()
{
    return &_worldPacket;
}

void WorldPackets::LFG::UserClientLFGListJoin::Read()
{
}

void WorldPackets::LFG::UserClientLFGListUpdateRequest::Read()
{
}

void WorldPackets::LFG::UserClientLFGListLeave::Read()
{
}

void WorldPackets::LFG::UserClientDFLeave::Read()
{
}

void WorldPackets::LFG::UserClientDFSearchJoin::Read()
{
}

void WorldPackets::LFG::UserClientDFSearchLeave::Read()
{
}

void WorldPackets::LFG::UserClientDFGetSystemInfo::Read()
{
}

void WorldPackets::LFG::UserClientDFSetComment::Read()
{
}

void WorldPackets::LFG::UserClientDFSetRoles::Read()
{
}

//void WorldPackets::LFG::UserClientDFSetNeeds::Read()
//{
//}

void WorldPackets::LFG::UserClientDFBootPlayerVote::Read()
{
}

void WorldPackets::LFG::UserClientDFTeleport::Read()
{
}

void WorldPackets::LFG::UserClientDFProposalResponse::Read()
{
}

void WorldPackets::LFG::UserClientDFJoin::Read()
{
}