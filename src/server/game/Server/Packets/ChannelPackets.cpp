/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ChannelPackets.h"
#include "Channel.h"

void WorldPackets::Channel::ChannelListRequest::Read()
{
    ChannelName = _worldPacket.ReadString(_worldPacket.ReadBits(7));
}

WorldPacket const* WorldPackets::Channel::ChannelListResponse::Write()
{
    _worldPacket.WriteBit(Display);
    _worldPacket.WriteBits(Channel.length(), 7);
    _worldPacket << uint8(ChannelFlags);
    _worldPacket << uint32(Members.size());
    _worldPacket.WriteString(Channel);

    for (ChannelPlayer const& player : Members)
    {
        _worldPacket << player.Guid;
        _worldPacket << uint32(player.VirtualRealmAddress);
        _worldPacket << uint8(player.Flags);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotify::Write()
{
    _worldPacket.WriteBits(Type, 6);
    _worldPacket.WriteBits(Channel.length(), 7);
    _worldPacket.WriteBits(Sender.length(), 6);

    _worldPacket << SenderGuid;
    _worldPacket << SenderAccountID;
    _worldPacket << uint32(SenderVirtualRealm);
    _worldPacket << TargetGuid;
    _worldPacket << uint32(TargetVirtualRealm);
    _worldPacket << int32(ChatChannelID);

    if (Type == CHAT_MODE_CHANGE_NOTICE)
    {
        _worldPacket << uint8(OldFlags);
        _worldPacket << uint8(NewFlags);
    }

    _worldPacket.WriteString(Channel);
    _worldPacket.WriteString(Sender);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotifyJoined::Write()
{
    _worldPacket.WriteBits(Channel.length(), 7);
    _worldPacket.WriteBits(ChannelWelcomeMsg.length(), 10);
    _worldPacket << uint8(ChannelFlags);
    _worldPacket << int32(ChatChannelID);
    _worldPacket << uint64(InstanceID);
    _worldPacket.WriteString(Channel);
    _worldPacket.WriteString(ChannelWelcomeMsg);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotifyLeft::Write()
{
    _worldPacket.WriteBits(Channel.length(), 7);
    _worldPacket.WriteBit(Suspended);
    _worldPacket << int32(ChatChannelID);
    _worldPacket.WriteString(Channel);

    return &_worldPacket;
}

void WorldPackets::Channel::JoinChannel::Read()
{
    _worldPacket >> ChatChannelId;
    CreateVoiceSession = _worldPacket.ReadBit();
    Internal = _worldPacket.ReadBit();
    uint32 channelLength = _worldPacket.ReadBits(7);
    uint32 passwordLength = _worldPacket.ReadBits(7);
    ChannelName = _worldPacket.ReadString(channelLength);
    Password = _worldPacket.ReadString(passwordLength);
}

void WorldPackets::Channel::LeaveChannel::Read()
{
    _worldPacket >> ZoneChannelID;
    ChannelName = _worldPacket.ReadString(_worldPacket.ReadBits(7));
}
