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

#ifndef QueryPackets_h__
#define QueryPackets_h__

#include "Packet.h"
#include "DB2Stores.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"

class Player;

namespace WorldPackets
{
    namespace Query
    {
        struct DBQueryRecord
        {
            ObjectGuid GUID;
            uint32 RecordID;
        };

        class DBQueryBulk final : public ClientPacket
        {
        public:
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
            int32 RecordID = 0;
            ByteBuffer Data;
        };

        class HotfixNotifyBlob final : public ServerPacket
        {
        public:
            HotfixNotifyBlob() : ServerPacket(SMSG_HOTFIX_NOTIFY_BLOB, 4) { }

            WorldPacket const* Write() override;

            HotfixData const* Hotfixes = nullptr;
        };

        struct PlayerGuidLookupData
        {
            bool Initialize(ObjectGuid const& guid, Player const* player = nullptr);

            std::string Name;
            uint8 Race = RACE_NONE;
            uint8 Sex = GENDER_NONE;
            uint8 ClassID = CLASS_NONE;
            uint8 Level = 0;
        };
    }
}

#endif // QueryPackets_h__
