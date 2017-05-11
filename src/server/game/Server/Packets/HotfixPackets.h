/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef HotfixPackets_h__
#define HotfixPackets_h__

#include "Packet.h"
#include "Common.h"
#include "DB2Stores.h"
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace Hotfix
    {
        class DBQueryBulk final : public ClientPacket
        {
        public:
            struct DBQueryRecord
            {
                ObjectGuid GUID;
                uint32 RecordID = 0;
            };

            DBQueryBulk(WorldPacket&& packet) : ClientPacket(CMSG_DB_QUERY_BULK, std::move(packet)) { }

            void Read() override;

            uint32 TableHash = 0;
            std::vector<DBQueryRecord> Queries;
        };

        class DBReply final : public ServerPacket
        {
        public:
            DBReply() : ServerPacket(SMSG_DB_REPLY, 12) { }

            WorldPacket const* Write() override;

            uint32 TableHash = 0;
            uint32 Timestamp = 0;
            uint32 RecordID = 0;
            bool Allow = false;
            ByteBuffer Data;
        };

        class HotfixList final : public ServerPacket
        {
        public:
            HotfixList(int32 hotfixCacheVersion, std::map<int32, HotfixData> const& hotfixes)
                : ServerPacket(SMSG_HOTFIX_LIST), HotfixCacheVersion(hotfixCacheVersion), Hotfixes(hotfixes) { }

            WorldPacket const* Write() override;

            int32 HotfixCacheVersion;
            std::map<int32, HotfixData> const& Hotfixes;
        };

        class HotfixQuery final : public ClientPacket
        {
        public:
            HotfixQuery(WorldPacket&& packet) : ClientPacket(CMSG_HOTFIX_QUERY, std::move(packet)) { }

            void Read() override;

            std::vector<int32> Hotfixes;
        };

        class HotfixQueryResponse final : public ServerPacket
        {
        public:
            struct HotfixRecord
            {
                uint32 TableHash = 0;
                int32 RecordID = 0;
                Optional<ByteBuffer> HotfixData;
            };

            struct HotfixData
            {
                int32 ID = 0;
                std::vector<HotfixRecord> Records;
            };

            HotfixQueryResponse() : ServerPacket(SMSG_HOTFIX_QUERY_RESPONSE) { }

            WorldPacket const* Write() override;

            std::vector<HotfixData> Hotfixes;
        };
    }
}

#endif // HotfixPackets_h__
