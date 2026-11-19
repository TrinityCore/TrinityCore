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

#ifndef TRINITYCORE_SOCIAL_PACKETS_H
#define TRINITYCORE_SOCIAL_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"

struct FriendInfo;
enum FriendsResult : uint8;

namespace WorldPackets
{
    namespace Social
    {
        class SendContactList final : public ClientPacket
        {
        public:
            explicit SendContactList(WorldPacket&& packet) : ClientPacket(CMSG_SEND_CONTACT_LIST, std::move(packet)) { }

            void Read() override;

            uint32 Flags = 0; ///< @see enum SocialFlag
        };

        struct ContactInfo
        {
            ObjectGuid Guid;
            ObjectGuid WowAccountGuid;
            uint32 VirtualRealmAddr = 0;
            uint32 NativeRealmAddr  = 0;
            uint32 TypeFlags        = 0; ///< @see enum SocialFlag
            std::string Notes;
            uint8 Status            = 0; ///< @see enum FriendStatus
            uint32 AreaID           = 0;
            uint32 Level            = 0;
            int8 ClassID            = CLASS_NONE;
        };

        class ContactList final : public ServerPacket
        {
        public:
            explicit ContactList() : ServerPacket(SMSG_CONTACT_LIST) { }

            WorldPacket const* Write() override;

            std::vector<ContactInfo> Contacts;
            uint32 Flags = 0; ///< @see enum SocialFlag
        };

        class FriendStatus final : public ServerPacket
        {
        public:
            explicit FriendStatus() : ServerPacket(SMSG_FRIEND_STATUS) { }

            WorldPacket const* Write() override;

            uint32 VirtualRealmAddress = 0;
            std::string Notes;
            int8 ClassID               = CLASS_NONE;
            uint8 Status               = 0; ///< @see enum FriendStatus
            ObjectGuid Guid;
            ObjectGuid WowAccountGuid;
            uint32 Level               = 0;
            uint32 AreaID              = 0;
            uint8 FriendResult         = 0; ///< @see enum FriendsResult
        };

        struct QualifiedGUID
        {
            ObjectGuid Guid;
            uint32 VirtualRealmAddress = 0;
        };

        class AddFriend final : public ClientPacket
        {
        public:
            explicit AddFriend(WorldPacket&& packet) : ClientPacket(CMSG_ADD_FRIEND, std::move(packet)) { }

            void Read() override;

            std::string Notes;
            std::string Name;
        };

        class DelFriend final : public ClientPacket
        {
        public:
            explicit DelFriend(WorldPacket&& packet) : ClientPacket(CMSG_DEL_FRIEND, std::move(packet)) { }

            void Read() override;

            QualifiedGUID Player;
        };

        class SetContactNotes final : public ClientPacket
        {
        public:
            explicit SetContactNotes(WorldPacket&& packet) : ClientPacket(CMSG_SET_CONTACT_NOTES, std::move(packet)) { }

            void Read() override;

            QualifiedGUID Player;
            std::string Notes;
        };

        class AddIgnore final : public ClientPacket
        {
        public:
            explicit AddIgnore(WorldPacket&& packet) : ClientPacket(CMSG_ADD_IGNORE, std::move(packet)) { }

            void Read() override;

            std::string Name;
            ObjectGuid AccountGUID;
        };

        class DelIgnore final : public ClientPacket
        {
        public:
            explicit DelIgnore(WorldPacket&& packet) : ClientPacket(CMSG_DEL_IGNORE, std::move(packet)) { }

            void Read() override;

            QualifiedGUID Player;
        };

        class SocialContractRequest final : public ClientPacket
        {
        public:
            explicit SocialContractRequest(WorldPacket&& packet) : ClientPacket(CMSG_SOCIAL_CONTRACT_REQUEST, std::move(packet)) { }

            void Read() override { }
        };

        class SocialContractRequestResponse final : public ServerPacket
        {
        public:
            explicit SocialContractRequestResponse() : ServerPacket(SMSG_SOCIAL_CONTRACT_REQUEST_RESPONSE, 1) { }

            WorldPacket const* Write() override;

            bool ShowSocialContract = false;
        };
    }
}

#endif // TRINITYCORE_SOCIAL_PACKETS_H
