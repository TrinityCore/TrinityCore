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
            std::string ToString() const override { return "Battlenet::WoWRealm::ListSubscribeRequest"; }

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
            std::string ToString() const override { return "Battlenet::WoWRealm::ListUnsubscribe"; }
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

            uint32 ClientSalt = 0;
            PrintableRealmHandle Id;
        };

        class ListSubscribeResponse final : public ServerPacket
        {
        public:
            ListSubscribeResponse() : ServerPacket(PacketHeader(SMSG_LIST_SUBSCRIBE_RESPONSE, WOWREALM))
            {
            }

            struct ToonCountEntry : public PrintableComponent
            {
                ToonCountEntry(PrintableRealmHandle const& realm, uint16 count) : Realm(realm), Count(count) { }

                PrintableRealmHandle Realm;
                uint16 Count;

                std::string ToString() const override;
            };

            void Write() override;
            std::string ToString() const override;

            enum
            {
                SUCCESS = 0,
                FAILURE = 1
            };

            int32 Type = SUCCESS;

            std::vector<ToonCountEntry> ToonCounts;
            Wow::AuthResult Failure = Wow::WOW_SUCCESS;
        };

        class ListUpdate final : public ServerPacket
        {
        public:
            ListUpdate() : ServerPacket(PacketHeader(SMSG_LIST_UPDATE, WOWREALM))
            {
            }

            void Write() override;
            std::string ToString() const override;

            PrintableRealmHandle Id;

            struct PrivilegedDataType : public PrintableComponent
            {
                std::string Version;
                uint32 ConfigId = 0;
                tcp::endpoint Address;

                std::string ToString() const override;
            };

            struct StateType : public PrintableComponent
            {
                enum
                {
                    DELETED = 0,
                    UPDATE  = 1
                };

                int32 Type = UPDATE;
                struct DeleteType : public PrintableComponent
                {
                    std::string ToString() const override { return "Battlenet::WoWRealm::ListUpdate::State::Delete"; }
                } Delete;

                struct UpdateType : public PrintableComponent
                {
                    uint8 InfoFlags = 0;
                    std::string Name;
                    int32 Type = 0;
                    uint32 Category = 0;
                    uint8 StateFlags = 0;
                    float Population = 0.0f;
                    Optional<PrivilegedDataType> PrivilegedData;

                    std::string ToString() const override;
                } Update;

                std::string ToString() const override;
            } State;
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

        class ToonReady final : public ServerPacket
        {
        public:
            ToonReady() : ServerPacket(PacketHeader(SMSG_TOON_READY, WOWREALM))
            {
            }

            void Write() override;
            std::string ToString() const override;

            Toon::FullName Name;
            Toon::Handle Handle;
            Profile::RecordAddress ProfileAddress;
        };

        class ToonLoggedOut final : public ServerPacket
        {
        public:
            ToonLoggedOut() : ServerPacket(PacketHeader(SMSG_TOON_LOGGED_OUT, WOWREALM))
            {
            }

            void Write() override { }
            std::string ToString() const override { return "Battlenet::WoWRealm::ToonLoggedOut"; }
        };

        class JoinResponseV2 final : public ServerPacket
        {
        public:
            JoinResponseV2() : ServerPacket(PacketHeader(SMSG_JOIN_RESPONSE_V2, WOWREALM))
            {
            }

            void Write() override;
            std::string ToString() const override;

            enum
            {
                SUCCESS = 0,
                FAILURE = 1
            };

            int32 Type = SUCCESS;
            struct SuccessType : public PrintableComponent
            {
                uint32 ServerSalt;
                std::vector<tcp::endpoint> IPv4;
                std::vector<tcp::endpoint> IPv6;

                std::string ToString() const override;
            } Success;

            Wow::AuthResult Failure = Wow::WOW_SUCCESS;
        };
    }
}

#endif // WoWRealmPackets_h__
