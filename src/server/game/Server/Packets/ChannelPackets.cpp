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

#include "ChannelPackets.h"
#include "Channel.h"
#include "Errors.h"

WorldPacket const* WorldPackets::Channel::ChannelListResponse::Write()
{
    _worldPacket << uint8(Display);
    _worldPacket << _Channel;
    _worldPacket << uint8(_ChannelFlags);
    _worldPacket << uint32(Members.size());

    for (ChannelPlayer const& player : Members)
    {
        _worldPacket << player.Guid;
        _worldPacket << uint8(player.Flags);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotify::Write()
{
    _worldPacket << uint8(Type);
    _worldPacket << _Channel;

    switch (Type)
    {
        case CHAT_JOINED_NOTICE:
        case CHAT_LEFT_NOTICE:
        case CHAT_PASSWORD_CHANGED_NOTICE:
        case CHAT_OWNER_CHANGED_NOTICE:
        case CHAT_ANNOUNCEMENTS_ON_NOTICE:
        case CHAT_ANNOUNCEMENTS_OFF_NOTICE:
        case CHAT_MODERATION_ON_NOTICE:
        case CHAT_MODERATION_OFF_NOTICE:
        case CHAT_PLAYER_ALREADY_MEMBER_NOTICE:
        case CHAT_INVITE_NOTICE:
        case CHAT_VOICE_ON_NOTICE:
        case CHAT_VOICE_OFF_NOTICE:
            _worldPacket << SenderGuid;
            break;
        case CHAT_YOU_JOINED_NOTICE:
            _worldPacket << uint8(NewFlags);
            _worldPacket << int32(ChatChannelID);
            _worldPacket << int32(InstanceID);
            break;
        case CHAT_YOU_LEFT_NOTICE:
            _worldPacket << int32(ChatChannelID);
            _worldPacket << uint8(Suspended);
            break;
        case CHAT_PLAYER_NOT_FOUND_NOTICE:
        case CHAT_CHANNEL_OWNER_NOTICE:
        case CHAT_PLAYER_NOT_BANNED_NOTICE:
        case CHAT_PLAYER_INVITED_NOTICE:
        case CHAT_PLAYER_INVITE_BANNED_NOTICE:
            _worldPacket << Sender;
            break;
        case CHAT_MODE_CHANGE_NOTICE:
            _worldPacket << SenderGuid;
            _worldPacket << uint8(OldFlags);
            _worldPacket << uint8(NewFlags);
            break;
        case CHAT_PLAYER_KICKED_NOTICE:
        case CHAT_PLAYER_BANNED_NOTICE:
        case CHAT_PLAYER_UNBANNED_NOTICE:
            _worldPacket << TargetGuid;
            _worldPacket << SenderGuid;
            break;
        default:
            break;
    }

    return &_worldPacket;
}

WorldPackets::Channel::ChannelCommand::ChannelCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    switch (packet.GetOpcode())
    {
        case CMSG_CHANNEL_ANNOUNCEMENTS:
        case CMSG_DECLINE_CHANNEL_INVITE:
        case CMSG_CHANNEL_DISPLAY_LIST:
        case CMSG_CHANNEL_LIST:
        case CMSG_CHANNEL_OWNER:
        case CMSG_GET_CHANNEL_MEMBER_COUNT:
        case CMSG_CHANNEL_VOICE_ON:
        case CMSG_CHANNEL_VOICE_OFF:
        case CMSG_SET_CHANNEL_WATCH:
            break;
        default:
            ABORT();
            break;
    }
}

void WorldPackets::Channel::ChannelCommand::Read()
{
    _worldPacket >> ChannelName;
}

WorldPackets::Channel::ChannelPlayerCommand::ChannelPlayerCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    switch (GetOpcode())
    {
        case CMSG_CHANNEL_BAN:
        case CMSG_CHANNEL_INVITE:
        case CMSG_CHANNEL_KICK:
        case CMSG_CHANNEL_MODERATOR:
        case CMSG_CHANNEL_MUTE:
        case CMSG_CHANNEL_SET_OWNER:
        case CMSG_CHANNEL_SILENCE_ALL:
        case CMSG_CHANNEL_UNBAN:
        case CMSG_CHANNEL_UNMODERATOR:
        case CMSG_CHANNEL_UNMUTE:
        case CMSG_CHANNEL_UNSILENCE_ALL:
            break;
        default:
            ABORT();
            break;
    }
}

void WorldPackets::Channel::ChannelPlayerCommand::Read()
{
    _worldPacket >> ChannelName;
    _worldPacket >> Name;
}

void WorldPackets::Channel::ChannelPassword::Read()
{
    _worldPacket >> ChannelName;
    _worldPacket >> Password;
}

void WorldPackets::Channel::JoinChannel::Read()
{
    _worldPacket >> ChatChannelId;
    _worldPacket >> CreateVoiceSession;
    _worldPacket >> Internal;
    _worldPacket >> ChannelName;
    _worldPacket >> Password;
}

void WorldPackets::Channel::LeaveChannel::Read()
{
    _worldPacket >> ZoneChannelID;
    _worldPacket >> ChannelName;
}

WorldPacket const* WorldPackets::Channel::ChannelMemberCount::Write()
{
    _worldPacket << ChannelName;
    _worldPacket << uint8(_ChannelFlags);
    _worldPacket << uint32(MemberCount);

    return &_worldPacket;
}
