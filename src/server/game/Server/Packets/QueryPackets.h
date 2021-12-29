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
#include "CreatureData.h"
#include "GameObjectData.h"
#include "DB2Stores.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "QuestDef.h"
#include "SharedDefines.h"

class Player;

namespace WorldPackets
{
    namespace Query
    {
        class QueryCreature final : public ClientPacket
        {
        public:
            QueryCreature(WorldPacket&& packet) : ClientPacket(CMSG_CREATURE_QUERY, std::move(packet)) { }

            void Read() override;

            uint32 CreatureID = 0;
            ObjectGuid GUID;
        };

        struct CreatureStats
        {
            std::array<std::string, 4> Name = {};
            std::array<std::string, 4> NameAlt = {};
            std::string Title;
            std::string CursorName;
            std::array<uint32, 2> Flags = {};
            uint32 CreatureType = 0;
            uint32 CreatureFamily = 0;
            uint32 Classification = 0;
            std::array<uint32, MAX_KILL_CREDIT> ProxyCreatureID = {};
            std::array<uint32, MAX_CREATURE_MODELS> CreatureDisplayID = {};
            float HpMulti = 0.0f;
            float EnergyMulti = 0.0f;
            bool Leader = false;
            std::array<uint32, MAX_CREATURE_QUEST_ITEMS> QuestItems = {};
            uint32 CreatureMovementInfoID = 0;
            uint32 RequiredExpansion = 0;
        };

        class QueryCreatureResponse final : public ServerPacket
        {
        public:
            QueryCreatureResponse() : ServerPacket(SMSG_CREATURE_QUERY_RESPONSE, 100) { }

            WorldPacket const* Write() override;

            bool Allow = false;
            CreatureStats Stats;
            uint32 CreatureID = 0;
        };

        class QueryGameObject final : public ClientPacket
        {
        public:
            QueryGameObject(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJECT_QUERY, std::move(packet)) { }

            void Read() override;

            uint32 GameObjectID = 0;
            ObjectGuid GUID;
        };

        struct GameObjectStats
        {
            std::array<std::string, 4> Name = {};
            std::string IconName;
            std::string CastBarCaption;
            std::string UnkString;
            uint32 Type = 0;
            uint32 DisplayID = 0;
            std::array<uint32, MAX_GAMEOBJECT_DATA> Data = {};
            float Size = 0.0f;
            std::array<uint32, MAX_GAMEOBJECT_QUEST_ITEMS> QuestItems = {};
            int32 RequiredLevel = 0;
        };

        class QueryGameObjectResponse final : public ServerPacket
        {
        public:
            QueryGameObjectResponse() : ServerPacket(SMSG_GAMEOBJECT_QUERY_RESPONSE, 150) { }

            WorldPacket const* Write() override;

            uint32 GameObjectID = 0;
            bool Allow = false;
            GameObjectStats Stats;
        };

        class QuestPOIQuery final : public ClientPacket
        {
        public:
            QuestPOIQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_POI_QUERY, std::move(packet)) { }

            void Read() override;

            uint32 MissingQuestCount = 0;
            std::array<uint32, MAX_QUEST_LOG_SIZE> MissingQuestPOIs = {};
        };

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
            std::string RealmName;
            uint8 Race = RACE_NONE;
            uint8 Sex = GENDER_NONE;
            uint8 ClassID = CLASS_NONE;
            uint8 Level = 0;
            Optional<DeclinedName> DeclinedNames;
        };

        class QueryPlayerNameResponse final : public ServerPacket
        {
        public:
            QueryPlayerNameResponse() : ServerPacket(SMSG_QUERY_PLAYER_NAME_RESPONSE, 8+1+1+1+1+1+10) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            uint8 Result = 0; // 0 - full packet, != 0 - only guid
            PlayerGuidLookupData Data;
        };
    }
}

#endif // QueryPackets_h__
