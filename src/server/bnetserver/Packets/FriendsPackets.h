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

#ifndef FriendsPackets_h__
#define FriendsPackets_h__

#include "PacketsBase.h"

namespace Battlenet
{
    namespace Friends
    {
        enum Opcode
        {
            CMSG_FRIEND_INVITE                          = 0x01,  // Not implemented
            CMSG_FRIEND_INVITE_RESPONSE                 = 0x02,  // Not implemented
            CMSG_FRIEND_REMOVE                          = 0x04,  // Not implemented
            CMSG_FRIEND_NOTE                            = 0x05,  // Not implemented
            CMSG_TOONS_OF_FRIEND_REQUEST                = 0x06,  // Not implemented
            CMSG_BLOCK_ADD                              = 0x08,  // Not implemented
            CMSG_BLOCK_REMOVE                           = 0x0A,  // Not implemented
            CMSG_GET_FRIENDS_OF_FRIEND                  = 0x0B,  // Not implemented
            CMSG_GET_SOCIAL_NETWORK_FRIENDS             = 0x0D,  // Not implemented
            CMSG_SOCIAL_NETWORK_CONNECT                 = 0x0F,  // Not implemented
            CMSG_SOCIAL_NETWORK_DISCONNECT              = 0x11,  // Not implemented
            CMSG_SOCIAL_NETWORK_CHECK_CONNECTED         = 0x13,
            CMSG_REALID_FRIEND_INVITE                   = 0x16,  // Not implemented

            SMSG_FRIEND_INVITE_NOTIFY                   = 0x01,  // Not implemented
            SMSG_FRIEND_INVITE_RESULT                   = 0x03,  // Not implemented
            SMSG_TOONS_OF_FRIEND_NOTIFY                 = 0x06,  // Not implemented
            SMSG_BLOCK_INVITE_NOTIFY                    = 0x07,  // Not implemented
            SMSG_BLOCK_ADD_FAILURE                      = 0x09,  // Not implemented
            SMSG_FRIENDS_OF_FRIEND                      = 0x0C,  // Not implemented
            SMSG_SOCIAL_NETWORK_FRIENDS                 = 0x0E,  // Not implemented
            SMSG_SOCIAL_NETWORK_CONNECT_RESULT          = 0x10,  // Not implemented
            SMSG_SOCIAL_NETWORK_DISCONNECT_RESULT       = 0x12,  // Not implemented
            SMSG_SOCIAL_NETWORK_CHECK_CONNECTED_RESULT  = 0x14,
            SMSG_MAX_FRIENDS_NOTIFY                     = 0x15,  // Not implemented
            SMSG_FRIENDS_LIST_NOTIFY_3                  = 0x18   // Not implemented
        };

        class SocialNetworkConnect final : public ClientPacket
        {
        public:
            SocialNetworkConnect(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_SOCIAL_NETWORK_CONNECT, FRIENDS) && "Invalid packet header for SocialNetworkConnect");
            }

            void Read() override;
            std::string ToString() const override;
        };

        class SocialNetworkConnectResult final : public ServerPacket
        {
        public:
            SocialNetworkConnectResult() : ServerPacket(PacketHeader(SMSG_SOCIAL_NETWORK_CONNECT_RESULT, FRIENDS))
            {
            }

            void Write() override;
            std::string ToString() const override;
        };

        class SocialNetworkCheckConnected final : public ClientPacket
        {
        public:
            SocialNetworkCheckConnected(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_SOCIAL_NETWORK_CHECK_CONNECTED, FRIENDS) && "Invalid packet header for SocialNetworkCheckConnected");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) override;

            uint32 SocialNetworkId;
        };

        class SocialNetworkCheckConnectedResult final : public ServerPacket
        {
        public:
            SocialNetworkCheckConnectedResult() : ServerPacket(PacketHeader(SMSG_SOCIAL_NETWORK_CHECK_CONNECTED_RESULT, FRIENDS)),
                SocialNetworkId(0)
            {
            }

            void Write() override;
            std::string ToString() const override;

            uint32 SocialNetworkId;
        };

        class GetFriendsOfFriend final : public ClientPacket
        {
        public:
            GetFriendsOfFriend(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_GET_FRIENDS_OF_FRIEND, FRIENDS) && "Invalid packet header for GetFriendsOfFriend");
            }

            void Read() override;
            std::string ToString() const override;
        };

        class FriendsOfFriend final : public ServerPacket
        {
        public:
            FriendsOfFriend() : ServerPacket(PacketHeader(SMSG_FRIENDS_OF_FRIEND, FRIENDS))
            {
            }

            void Write() override;
            std::string ToString() const override;
        };

        class RealIdFriendInvite final : public ClientPacket
        {
        public:
            RealIdFriendInvite(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_REALID_FRIEND_INVITE, FRIENDS) && "Invalid packet header for RealIdFriendInvite");
            }

            void Read() override;
            std::string ToString() const override;

            std::string Email;
            std::string Message;
        };

        class FriendInviteResult final : public ServerPacket
        {
        public:
            FriendInviteResult() : ServerPacket(PacketHeader(SMSG_FRIEND_INVITE_RESULT, FRIENDS))
            {
            }

            void Write() override;
            std::string ToString() const override;
        };
    }
}

#endif // FriendsPackets_h__
