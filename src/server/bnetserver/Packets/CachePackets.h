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

#ifndef CachePackets_h__
#define CachePackets_h__

#include "ModuleManager.h"
#include "PacketsBase.h"

namespace Battlenet
{
    namespace Cache
    {
        enum Opcode
        {
            CMSG_GATEWAY_LOOKUP_REQUEST     = 0x2,  // Not implemented
            CMSG_CONNECT_REQUEST            = 0x4,  // Not implemented
            CMSG_DATA_CHUNK                 = 0x7,  // Not implemented
            CMSG_GET_STREAM_ITEMS_REQUEST   = 0x9,

            SMSG_GATEWAY_LOOKUP_RESPONSE    = 0x3,  // Not implemented
            SMSG_CONNECT_RESPONSE           = 0x4,  // Not implemented
            SMSG_PUBLISH_LIST_RESPONSE      = 0x7,  // Not implemented
            SMSG_RESULT                     = 0x8,  // Not implemented
            SMSG_GET_STREAM_ITEMS_RESPONSE  = 0x9
        };

        class GetStreamItemsRequest final : public ClientPacket
        {
        public:
            GetStreamItemsRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_GET_STREAM_ITEMS_REQUEST, CACHE) && "Invalid packet header for GetStreamItemsRequest");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) override;

            enum
            {
                BEFORE = 0,
                AFTER = 1
            };

            uint32 Token = 0;
            uint8 MaxItems = 0;
            int32 ReferenceTime = 0;
            uint8 Direction = BEFORE;

            struct StreamId : public PrintableComponent
            {
                enum
                {
                    INDEX = 0,
                    DESCRIPTION = 1
                };

                int32 Type;

                uint16 Index;
                struct DescriptionType : public PrintableComponent
                {
                    std::string Channel;
                    std::string ItemName;

                    std::string ToString() const override;
                } Description;

                std::string ToString() const override;
            } Stream;

            std::string Locale;
        };

        class GetStreamItemsResponse final : public ServerPacket
        {
        public:
            GetStreamItemsResponse() : ServerPacket(PacketHeader(SMSG_GET_STREAM_ITEMS_RESPONSE, CACHE))
            {
            }

            ~GetStreamItemsResponse();

            void Write() override;
            std::string ToString() const override;

            std::vector<ModuleInfo*> Items;
            uint16 Offset = 0;
            uint16 TotalNumItems = 1;
            uint32 Token = 0;
        };
    }
}

#endif // CachePackets_h__
