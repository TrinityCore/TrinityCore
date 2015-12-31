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
            CMSG_GET_SOCIAL_NETWORK_FRIENDS             = 0x0D,  // Deprecated in client
            CMSG_SOCIAL_NETWORK_CONNECT                 = 0x0F,  // Deprecated in client
            CMSG_SOCIAL_NETWORK_DISCONNECT              = 0x11,  // Deprecated in client
            CMSG_SOCIAL_NETWORK_CHECK_CONNECTED         = 0x13,  // Deprecated in client
            CMSG_REALID_FRIEND_INVITE                   = 0x16,  // Deprecated in client
            CMSG_SEND_INVITATION_REQUEST                = 0x1A,  // Not implemented

            SMSG_FRIEND_INVITE_NOTIFY                   = 0x01,  // Not implemented
            SMSG_FRIEND_INVITE_RESULT                   = 0x03,  // Not implemented
            SMSG_TOONS_OF_FRIEND_NOTIFY                 = 0x06,  // Not implemented
            SMSG_BLOCK_INVITE_NOTIFY                    = 0x07,  // Deprecated in client
            SMSG_BLOCK_ADD_FAILURE                      = 0x09,  // Not implemented
            SMSG_FRIENDS_OF_FRIEND                      = 0x0C,  // Deprecated in client
            SMSG_SOCIAL_NETWORK_FRIENDS                 = 0x0E,  // Deprecated in client
            SMSG_SOCIAL_NETWORK_CONNECT_RESULT          = 0x10,  // Deprecated in client
            SMSG_SOCIAL_NETWORK_DISCONNECT_RESULT       = 0x12,  // Deprecated in client
            SMSG_SOCIAL_NETWORK_CHECK_CONNECTED_RESULT  = 0x14,  // Deprecated in client
            SMSG_MAX_FRIENDS_NOTIFY                     = 0x15,  // Not implemented
            SMSG_FRIENDS_LIST_NOTIFY_3                  = 0x18,  // Deprecated in client
            SMSG_SEND_INVITATION_RESULT                 = 0x1B,  // Not implemented
            SMSG_FRIEND_INVITATION_ADDED_NOTIFY         = 0x1C,  // Not implemented
            SMSG_FRIEND_INVITATION_REMOVED_NOTIFY       = 0x1D,  // Not implemented
            SMSG_FRIENDS_LIST_NOTIFY_5                  = 0x1E,  // Not implemented
            SMSG_ACCOUNT_BLOCK_ADDED_NOTIFY             = 0x1F,  // Not implemented
            SMSG_ACCOUNT_BLOCK_REMOVED_NOTIFY           = 0x20,  // Not implemented
            SMSG_TOON_BLOCK_NOTIFY                      = 0x21,  // Not implemented
            SMSG_FRIENDS_OF_FRIEND_RESULT               = 0x22   // Not implemented
        };

        class SendInvitationRequest final : public ClientPacket
        {
        public:
            SendInvitationRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream) { }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) override;

            uint32 Token = 0;

            Optional<uint32> PresenceId;
            Optional<GameAccount::Handle> GameAccount;
            Optional<uint32> AccountId;
            Optional<std::string> AccountMail;
            Optional<std::string> Nickname;

            Optional<std::string> InvitationMsg;
            std::string Source;
            uint32 Role = 0;
        };
    }
}

#endif // FriendsPackets_h__
