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

#ifndef TRINITYCORE_CHANNEL_PACKETS_H
#define TRINITYCORE_CHANNEL_PACKETS_H

#include "Packet.h"
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
                ChannelPlayer(ObjectGuid const& guid, uint8 flags) :
                    Guid(guid), Flags(flags) { }

                ObjectGuid Guid; ///< Player Guid
                uint8 Flags = 0; ///< @see enum ChannelMemberFlags
            };

            explicit ChannelListResponse() : ServerPacket(SMSG_CHANNEL_LIST) { }

            WorldPacket const* Write() override;

            std::vector<ChannelPlayer> Members;
            std::string _Channel; ///< Channel Name
            uint8 _ChannelFlags = 0; ///< @see enum ChannelFlags
            bool Display = false;
        };

        class ChannelNotify final : public ServerPacket
        {
        public:
            explicit ChannelNotify() : ServerPacket(SMSG_CHANNEL_NOTIFY, 80) { }

            WorldPacket const* Write() override;

            std::string Sender;
            ObjectGuid SenderGuid;
            uint8 Type                = 0; ///< @see enum ChatNotify
            uint8 OldFlags            = 0; ///< @see enum ChannelMemberFlags
            uint8 NewFlags            = 0; ///< @see enum ChannelMemberFlags
            std::string _Channel;          ///< Channel Name
            ObjectGuid TargetGuid;
            int32 ChatChannelID       = 0;
            int32 InstanceID          = 0;
            bool Suspended            = false;
        };

        class ChannelCommand final : public ClientPacket
        {
        public:
            explicit ChannelCommand(WorldPacket&& packet);

            void Read() override;

            std::string ChannelName;
        };

        class ChannelPlayerCommand final : public ClientPacket
        {
        public:
            explicit ChannelPlayerCommand(WorldPacket&& packet);

            void Read() override;

            std::string ChannelName;
            std::string Name;
        };

        class ChannelPassword final : public ClientPacket
        {
        public:
            explicit ChannelPassword(WorldPacket&& packet) : ClientPacket(CMSG_CHANNEL_PASSWORD, std::move(packet)) { }

            void Read() override;

            std::string ChannelName;
            std::string Password;
        };

        class JoinChannel final : public ClientPacket
        {
        public:
            explicit JoinChannel(WorldPacket&& packet) : ClientPacket(CMSG_JOIN_CHANNEL, std::move(packet)) { }

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
            explicit LeaveChannel(WorldPacket&& packet) : ClientPacket(CMSG_LEAVE_CHANNEL, std::move(packet)) { }

            void Read() override;

            int32 ZoneChannelID = 0;
            std::string ChannelName;
        };

        class ChannelMemberCount final : public ServerPacket
        {
        public:
            ChannelMemberCount() : ServerPacket(SMSG_CHANNEL_MEMBER_COUNT, 30 + 1 + 4) { }

            WorldPacket const* Write() override;

            uint8 _ChannelFlags = 0; ///< @see enum ChannelFlags
            uint32 MemberCount = 0;
            std::string ChannelName;
        };
    }
}

#endif // TRINITYCORE_CHANNEL_PACKETS_H
