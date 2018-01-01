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

#include "ChannelPackets.h"
#include "Channel.h"
#include "Errors.h"

WorldPacket const* WorldPackets::Channel::ChannelListResponse::Write()
{
    _worldPacket.WriteBit(_Display);
    _worldPacket.WriteBits(_Channel.length(), 7);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(_Members.size());
    _worldPacket.WriteString(_Channel);

    for (ChannelPlayer const& player : _Members)
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
    _worldPacket.WriteBits(_Channel.length(), 7);
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

    _worldPacket.WriteString(_Channel);
    _worldPacket.WriteString(Sender);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotifyJoined::Write()
{
    _worldPacket.WriteBits(_Channel.length(), 7);
    _worldPacket.WriteBits(ChannelWelcomeMsg.length(), 10);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << int32(ChatChannelID);
    _worldPacket << uint64(InstanceID);
    _worldPacket.WriteString(_Channel);
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

WorldPacket const* WorldPackets::Channel::UserlistAdd::Write()
{
    _worldPacket << AddedUserGUID;
    _worldPacket << uint8(UserFlags);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket.WriteBits(ChannelName.length(), 7);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(ChannelName);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::UserlistRemove::Write()
{
    _worldPacket << RemovedUserGUID;
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket.WriteBits(ChannelName.length(), 7);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(ChannelName);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::UserlistUpdate::Write()
{
    _worldPacket << UpdatedUserGUID;
    _worldPacket << uint8(UserFlags);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket.WriteBits(ChannelName.length(), 7);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(ChannelName);
    return &_worldPacket;
}

WorldPackets::Channel::ChannelCommand::ChannelCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    switch (packet.GetOpcode())
    {
        case CMSG_CHAT_CHANNEL_ANNOUNCEMENTS:
        case CMSG_CHAT_CHANNEL_DECLINE_INVITE:
        case CMSG_CHAT_CHANNEL_DISPLAY_LIST:
        case CMSG_CHAT_CHANNEL_LIST:
        case CMSG_CHAT_CHANNEL_MODERATE:
        case CMSG_CHAT_CHANNEL_OWNER:
            break;
        default:
            ABORT();
            break;
    }
}

void WorldPackets::Channel::ChannelCommand::Read()
{
    ChannelName = _worldPacket.ReadString(_worldPacket.ReadBits(7));
}

WorldPackets::Channel::ChannelPlayerCommand::ChannelPlayerCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    switch (GetOpcode())
    {
        case CMSG_CHAT_CHANNEL_BAN:
        case CMSG_CHAT_CHANNEL_INVITE:
        case CMSG_CHAT_CHANNEL_KICK:
        case CMSG_CHAT_CHANNEL_MODERATOR:
        case CMSG_CHAT_CHANNEL_MUTE:
        case CMSG_CHAT_CHANNEL_SET_OWNER:
        case CMSG_CHAT_CHANNEL_SILENCE_ALL:
        case CMSG_CHAT_CHANNEL_UNBAN:
        case CMSG_CHAT_CHANNEL_UNMODERATOR:
        case CMSG_CHAT_CHANNEL_UNMUTE:
        case CMSG_CHAT_CHANNEL_UNSILENCE_ALL:
            break;
        default:
            ABORT();
            break;
    }
}

void WorldPackets::Channel::ChannelPlayerCommand::Read()
{
    uint32 channelNameLength = _worldPacket.ReadBits(7);
    uint32 nameLength = _worldPacket.ReadBits(9);
    ChannelName = _worldPacket.ReadString(channelNameLength);
    Name = _worldPacket.ReadString(nameLength);
}

void WorldPackets::Channel::ChannelPassword::Read()
{
    uint32 channelNameLength = _worldPacket.ReadBits(7);
    uint32 passwordLength = _worldPacket.ReadBits(7);
    ChannelName = _worldPacket.ReadString(channelNameLength);
    Password = _worldPacket.ReadString(passwordLength);
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
