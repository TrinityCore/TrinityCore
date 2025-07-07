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
#include "PacketOperators.h"

namespace WorldPackets::Channel
{
WorldPacket const* ChannelListResponse::Write()
{
    _worldPacket << Bits<1>(_Display);
    _worldPacket << SizedString::BitsSize<7>(_Channel);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << Size<uint32>(_Members);
    _worldPacket << SizedString::Data(_Channel);

    for (ChannelPlayer const& player : _Members)
    {
        _worldPacket << player.Guid;
        _worldPacket << uint32(player.VirtualRealmAddress);
        _worldPacket << uint8(player.Flags);
    }

    return &_worldPacket;
}

WorldPacket const* ChannelNotify::Write()
{
    _worldPacket << Bits<6>(Type);
    _worldPacket << SizedString::BitsSize<7>(_Channel);
    _worldPacket << SizedString::BitsSize<6>(Sender);

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

    _worldPacket << SizedString::Data(_Channel);
    _worldPacket << SizedString::Data(Sender);

    return &_worldPacket;
}

WorldPacket const* ChannelNotifyJoined::Write()
{
    _worldPacket << SizedString::BitsSize<7>(_Channel);
    _worldPacket << SizedString::BitsSize<11>(ChannelWelcomeMsg);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint8(Unknown1107);
    _worldPacket << int32(ChatChannelID);
    _worldPacket << uint64(InstanceID);
    _worldPacket << ChannelGUID;
    _worldPacket << SizedString::Data(_Channel);
    _worldPacket << SizedString::Data(ChannelWelcomeMsg);

    return &_worldPacket;
}

WorldPacket const* ChannelNotifyLeft::Write()
{
    _worldPacket << SizedString::BitsSize<7>(Channel);
    _worldPacket << Bits<1>(Suspended);
    _worldPacket << int32(ChatChannelID);
    _worldPacket << SizedString::Data(Channel);

    return &_worldPacket;
}

WorldPacket const* UserlistAdd::Write()
{
    _worldPacket << AddedUserGUID;
    _worldPacket << uint8(UserFlags);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket << SizedString::BitsSize<7>(ChannelName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(ChannelName);

    return &_worldPacket;
}

WorldPacket const* UserlistRemove::Write()
{
    _worldPacket << RemovedUserGUID;
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket << SizedString::BitsSize<7>(ChannelName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(ChannelName);

    return &_worldPacket;
}

WorldPacket const* UserlistUpdate::Write()
{
    _worldPacket << UpdatedUserGUID;
    _worldPacket << uint8(UserFlags);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << int32(ChannelID);
    _worldPacket << SizedString::BitsSize<7>(ChannelName);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(ChannelName);

    return &_worldPacket;
}

ChannelCommand::ChannelCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    switch (packet.GetOpcode())
    {
        case CMSG_CHAT_CHANNEL_ANNOUNCEMENTS:
        case CMSG_CHAT_CHANNEL_DECLINE_INVITE:
        case CMSG_CHAT_CHANNEL_DISPLAY_LIST:
        case CMSG_CHAT_CHANNEL_LIST:
        case CMSG_CHAT_CHANNEL_OWNER:
            break;
        default:
            ABORT();
            break;
    }
}

void ChannelCommand::Read()
{
    _worldPacket >> SizedString::BitsSize<7>(ChannelName);

    _worldPacket >> SizedString::Data(ChannelName);
}

ChannelPlayerCommand::ChannelPlayerCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
{
    switch (GetOpcode())
    {
        case CMSG_CHAT_CHANNEL_BAN:
        case CMSG_CHAT_CHANNEL_INVITE:
        case CMSG_CHAT_CHANNEL_KICK:
        case CMSG_CHAT_CHANNEL_MODERATOR:
        case CMSG_CHAT_CHANNEL_SET_OWNER:
        case CMSG_CHAT_CHANNEL_SILENCE_ALL:
        case CMSG_CHAT_CHANNEL_UNBAN:
        case CMSG_CHAT_CHANNEL_UNMODERATOR:
        case CMSG_CHAT_CHANNEL_UNSILENCE_ALL:
            break;
        default:
            ABORT();
            break;
    }
}

void ChannelPlayerCommand::Read()
{
    _worldPacket >> SizedString::BitsSize<7>(ChannelName);
    _worldPacket >> SizedString::BitsSize<9>(Name);

    _worldPacket >> SizedString::Data(ChannelName);
    _worldPacket >> SizedString::Data(Name);
}

void ChannelPassword::Read()
{
    _worldPacket >> SizedString::BitsSize<7>(ChannelName);
    _worldPacket >> SizedString::BitsSize<7>(Password);

    _worldPacket >> SizedString::Data(ChannelName);
    _worldPacket >> SizedString::Data(Password);
}

void JoinChannel::Read()
{
    _worldPacket >> ChatChannelId;
    _worldPacket >> Bits<1>(CreateVoiceSession);
    _worldPacket >> Bits<1>(Internal);
    _worldPacket >> SizedString::BitsSize<7>(ChannelName);
    _worldPacket >> SizedString::BitsSize<7>(Password);

    _worldPacket >> SizedString::Data(ChannelName);
    _worldPacket >> SizedString::Data(Password);
}

void LeaveChannel::Read()
{
    _worldPacket >> ZoneChannelID;
    _worldPacket >> SizedString::BitsSize<7>(ChannelName);
    _worldPacket >> SizedString::Data(ChannelName);
}
}
