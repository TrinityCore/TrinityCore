/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

        class AvailableHotfixes final : public ServerPacket
        {
        public:
            AvailableHotfixes(int32 hotfixCacheVersion, uint32 hotfixCount, DB2Manager::HotfixContainer const& hotfixes)
                : ServerPacket(SMSG_AVAILABLE_HOTFIXES), HotfixCacheVersion(hotfixCacheVersion), HotfixCount(hotfixCount), Hotfixes(hotfixes) { }

            WorldPacket const* Write() override;

            int32 HotfixCacheVersion;
            uint32 HotfixCount;
            DB2Manager::HotfixContainer const& Hotfixes;
        };

        struct HotfixRecord
        {
            uint32 TableHash = 0;
            int32 RecordID = 0;
            int32 HotfixID = 0;
        };

        class HotfixRequest final : public ClientPacket
        {
        public:
            HotfixRequest(WorldPacket&& packet) : ClientPacket(CMSG_HOTFIX_REQUEST, std::move(packet)) { }

            void Read() override;

            uint32 ClientBuild = 0;
            uint32 DataBuild = 0;
            std::vector<HotfixRecord> Hotfixes;
        };

        class HotfixResponse final : public ServerPacket
        {
        public:
            struct HotfixData
            {
                HotfixRecord Record;
                Optional<uint32> Size;
            };

            HotfixResponse() : ServerPacket(SMSG_HOTFIX_RESPONSE) { }

            WorldPacket const* Write() override;

            std::vector<HotfixData> Hotfixes;
            ByteBuffer HotfixContent;
        };
    }
}

#endif // HotfixPackets_h__
