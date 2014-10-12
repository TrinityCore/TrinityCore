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

#ifndef WoWRealmPackets_h__
#define WoWRealmPackets_h__

#include "PacketsBase.h"
#include "RealmList.h"

namespace Battlenet
{
    namespace WoWRealm
    {
        enum Opcode
        {
            CMSG_LIST_SUBSCRIBE_REQUEST     = 0x0,
            CMSG_LIST_UNSUBSCRIBE           = 0x1,
            CMSG_JOIN_REQUEST_V2            = 0x8,
            CMSG_MULTI_LOGON_REQUEST_V2     = 0x9,  // Not implemented

            SMSG_LIST_SUBSCRIBE_RESPONSE    = 0x0,
            SMSG_LIST_UPDATE                = 0x2,
            SMSG_LIST_COMPLETE              = 0x3,
            SMSG_TOON_READY                 = 0x6,  // Not implemented
            SMSG_TOON_LOGGED_OUT            = 0x7,  // Not implemented
            SMSG_JOIN_RESPONSE_V2           = 0x8
        };

        class ListSubscribeRequest final : public ClientPacket
        {
        public:
            ListSubscribeRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_LIST_SUBSCRIBE_REQUEST, WOWREALM) && "Invalid packet header for ListSubscribeRequest");
            }

            void Read() override { }
            std::string ToString() const override;
            void CallHandler(Session* session) override;
        };

        class ListUnsubscribe final : public ClientPacket
        {
        public:
            ListUnsubscribe(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_LIST_UNSUBSCRIBE, WOWREALM) && "Invalid packet header for ListUnsubscribe");
            }

            void Read() override { }
            std::string ToString() const override;
            void CallHandler(Session* session) override;
        };

        class JoinRequestV2 final : public ClientPacket
        {
        public:
            JoinRequestV2(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_JOIN_REQUEST_V2, WOWREALM) && "Invalid packet header for RealmJoinRequest");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) override;

            uint32 ClientSeed;
            RealmId Realm;
        };

        class ListSubscribeResponse final : public ServerPacket
        {
        public:
            enum Result
            {
                SUCCESS = 0,
                FAILURE = 1
            };

            ListSubscribeResponse() : ServerPacket(PacketHeader(SMSG_LIST_SUBSCRIBE_RESPONSE, WOWREALM)),
                Response(SUCCESS), ResponseCode(26)
            {
            }

            ~ListSubscribeResponse();

            struct CharacterCountEntry
            {
                RealmId Realm;
                uint32 CharacterCount;
            };

            void Write() override;
            std::string ToString() const override;

            Result Response;
            uint8 ResponseCode;
            std::vector<CharacterCountEntry> CharacterCounts;
            std::vector<ServerPacket*> RealmData;
        };

        class ListUpdate final : public ServerPacket
        {
        public:
            enum State
            {
                DELETED = 0,
                UPDATE  = 1
            };

            ListUpdate() : ServerPacket(PacketHeader(SMSG_LIST_UPDATE, WOWREALM)), UpdateState(UPDATE),
                Timezone(0), Population(0.0f), Lock(0), Type(0), Name(""), Version(""), Flags(0)
            {
            }

            void Write() override;
            std::string ToString() const override;

            int UpdateState;
            uint32 Timezone;
            float Population;
            uint8 Lock;
            uint32 Type;
            std::string Name;
            std::string Version;
            tcp::endpoint Address;
            uint8 Flags;
            RealmId Id;
        };

        class ListComplete final : public ServerPacket
        {
        public:
            ListComplete() : ServerPacket(PacketHeader(SMSG_LIST_COMPLETE, WOWREALM))
            {
            }

            void Write() override { }
            std::string ToString() const override { return "Battlenet::WoWRealm::ListComplete"; }
        };

        class JoinResponseV2 final : public ServerPacket
        {
        public:
            enum Result
            {
                SUCCESS = 0,
                FAILURE = 1
            };

            JoinResponseV2() : ServerPacket(PacketHeader(SMSG_JOIN_RESPONSE_V2, WOWREALM)),
                Response(SUCCESS), ResponseCode(26), ServerSeed(0)
            {
            }

            void Write() override;
            std::string ToString() const override;

            Result Response;
            uint8 ResponseCode;
            uint32 ServerSeed;
            std::vector<tcp::endpoint> IPv4;
            std::vector<tcp::endpoint> IPv6;
        };
    }
}

#endif // WoWRealmPackets_h__
