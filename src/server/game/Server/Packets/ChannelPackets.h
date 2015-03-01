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

#ifndef ChannelPackets_h__
#define ChannelPackets_h__

#include "Packet.h"
#include "Channel.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Channel
    {
        class ChannelListResponse final : public ServerPacket
        {
        public:
            struct ChannelPlayer
            {
                ChannelPlayer(ObjectGuid const& guid, uint32 realm, uint8 flags) :
                    Guid(guid), VirtualRealmAddress(realm), Flags(flags) { }

                ObjectGuid Guid; ///< Player Guid
                uint32 VirtualRealmAddress;
                uint8 Flags;     ///< @see enum ChannelMemberFlags
            };

            ChannelListResponse() : ServerPacket(SMSG_CHANNEL_LIST) { }

            WorldPacket const* Write() override;

            std::vector<ChannelPlayer> _Members;
            std::string _Channel; ///< Channel Name
            uint8 _ChannelFlags = 0; ///< @see enum ChannelFlags
            bool _Display = false;
        };

        class ChannelNotify final : public ServerPacket
        {
        public:
            ChannelNotify() : ServerPacket(SMSG_CHANNEL_NOTIFY, 80) { }

            WorldPacket const* Write() override;

            std::string Sender;
            ObjectGuid SenderGuid;
            ObjectGuid SenderAccountID;
            uint8 Type                = 0; ///< @see enum ChatNotify
            uint8 OldFlags            = 0; ///< @see enum ChannelMemberFlags
            uint8 NewFlags            = 0; ///< @see enum ChannelMemberFlags
            std::string _Channel;          ///< Channel Name
            uint32 SenderVirtualRealm = 0;
            ObjectGuid TargetGuid;
            uint32 TargetVirtualRealm = 0;
            int32 ChatChannelID       = 0;
        };

        class ChannelNotifyJoined final : public ServerPacket
        {
        public:
            ChannelNotifyJoined() : ServerPacket(SMSG_CHANNEL_NOTIFY_JOINED, 50) { }

            WorldPacket const* Write() override;

            std::string ChannelWelcomeMsg;
            int32 ChatChannelID = 0;
            int32 InstanceID    = 0;
            uint8 _ChannelFlags = 0; ///< @see enum ChannelFlags
            std::string _Channel;     ///< Channel Name
        };

        class ChannelNotifyLeft final : public ServerPacket
        {
            public:
            ChannelNotifyLeft() : ServerPacket(SMSG_CHANNEL_NOTIFY_LEFT, 30) { }

            WorldPacket const* Write() override;

            std::string Channel;    ///< Channel Name
            int32 ChatChannelID = 0;
            bool Suspended = false; ///< User Leave - false, On Zone Change - true
        };

        class ChannelPlayerCommand final : public ClientPacket
        {
        public:
            ChannelPlayerCommand(WorldPacket&& packet) : ClientPacket(std::move(packet))
            {
                switch (GetOpcode())
                {
                    default:
                        ASSERT(false);/*
                    case CMSG_CHANNEL_ANNOUNCEMENTS:
                    case CMSG_CHANNEL_BAN:
                    case CMSG_CHANNEL_DECLINE_INVITE:
                    case CMSG_CHANNEL_DISPLAY_LIST:
                    case CMSG_CHANNEL_INVITE:
                    case CMSG_CHANNEL_KICK:
                    case CMSG_CHANNEL_LIST:
                    //case CMSG_CHANNEL_MODERATE:
                    case CMSG_CHANNEL_MODERATOR:
                    case CMSG_CHANNEL_MUTE:
                    case CMSG_CHANNEL_OWNER:
                    case CMSG_CHANNEL_PASSWORD:
                    case CMSG_CHANNEL_SET_OWNER:
                    case CMSG_CHANNEL_SILENCE_ALL:
                    case CMSG_CHANNEL_SILENCE_VOICE:
                    case CMSG_CHANNEL_UNBAN:
                    case CMSG_CHANNEL_UNMODERATOR:
                    case CMSG_CHANNEL_UNMUTE:
                    case CMSG_CHANNEL_UNSILENCE_ALL:
                    case CMSG_CHANNEL_UNSILENCE_VOICE:
                    case CMSG_CHANNEL_VOICE_OFF:
                    case CMSG_CHANNEL_VOICE_ON:*/
                        break;
                }
            }

            void Read() override;

            std::string ChannelName;
            std::string Name;
        };

        class JoinChannel final : public ClientPacket
        {
        public:
            JoinChannel(WorldPacket&& packet) : ClientPacket(CMSG_JOIN_CHANNEL, std::move(packet)) { }

            void Read() override;

            std::string Password;
            std::string ChannelName;
            bool CreateVoiceSession = false;
            int32 ChatChannelId         = 0;
            bool Internal           = false;
        };

        class LeaveChannel final : public ClientPacket
        {
        public:
            LeaveChannel(WorldPacket&& packet) : ClientPacket(CMSG_LEAVE_CHANNEL, std::move(packet)) { }

            void Read() override;

            int32 ZoneChannelID = 0;
            std::string ChannelName;
        };
    }
}

#endif // ChannelPackets_h__
