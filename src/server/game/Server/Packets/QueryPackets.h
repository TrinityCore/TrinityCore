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

#ifndef QueryPackets_h__
#define QueryPackets_h__

#include "Packet.h"
#include "Creature.h"
#include "NPCHandler.h"
#include "G3D/Vector3.h"
#include "DB2Stores.h"

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
        };

        struct CreatureStats
        {
            std::string Title;
            std::string TitleAlt;
            std::string CursorName;
            int32 CreatureType = 0;
            int32 CreatureFamily = 0;
            int32 Classification = 0;
            float HpMulti = 0.0f;
            float EnergyMulti = 0.0f;
            bool Leader = false;
            std::vector<int32> QuestItems;
            uint32 CreatureMovementInfoID = 0;
            uint32 RequiredExpansion = 0;
            uint32 Flags[2];
            uint32 ProxyCreatureID[MAX_KILL_CREDIT];
            uint32 CreatureDisplayID[MAX_CREATURE_MODELS];
            std::string Name[MAX_CREATURE_NAMES];
            std::string NameAlt[MAX_CREATURE_NAMES];
        };

        class QueryCreatureResponse final : public ServerPacket
        {
        public:
            QueryCreatureResponse() : ServerPacket(SMSG_CREATURE_QUERY_RESPONSE, 76) { }

            WorldPacket const* Write() override;

            bool Allow = false;
            CreatureStats Stats;
            uint32 CreatureID = 0;
        };

        struct PlayerGuidLookupHint
        {
            Optional<uint32> VirtualRealmAddress; ///< current realm (?) (identifier made from the Index, BattleGroup and Region)
            Optional<uint32> NativeRealmAddress; ///< original realm (?) (identifier made from the Index, BattleGroup and Region)
        };

        class QueryPlayerName final : public ClientPacket
        {
        public:
            QueryPlayerName(WorldPacket&& packet) : ClientPacket(CMSG_NAME_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Player;
            PlayerGuidLookupHint Hint;
        };

        struct PlayerGuidLookupData
        {
            bool Initialize(ObjectGuid const& guid, Player const* player = nullptr);

            bool IsDeleted = false;
            ObjectGuid AccountID;
            ObjectGuid BnetAccountID;
            ObjectGuid GuidActual;
            std::string Name;
            uint32 VirtualRealmAddress = 0;
            uint8 Race = RACE_NONE;
            uint8 Sex = GENDER_NONE;
            uint8 ClassID = CLASS_NONE;
            uint8 Level = 0;
            DeclinedName DeclinedNames;
        };

        class QueryPlayerNameResponse final : public ServerPacket
        {
        public:
            QueryPlayerNameResponse() : ServerPacket(SMSG_NAME_QUERY_RESPONSE, 60) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            uint8 Result = 0; // 0 - full packet, != 0 - only guid
            PlayerGuidLookupData Data;
        };

        class QueryPageText final : public ClientPacket
        {
        public:
            QueryPageText(WorldPacket&& packet) : ClientPacket(CMSG_PAGE_TEXT_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid ItemGUID;
            uint32 PageTextID = 0;
        };

        struct PageTextInfo
        {
            uint32 ID           = 0;
            uint32 NextPageID   = 0;
            std::string Text;
        };

        class QueryPageTextResponse final : public ServerPacket
        {
        public:
            QueryPageTextResponse() : ServerPacket(SMSG_PAGE_TEXT_QUERY_RESPONSE, 15) { }

            WorldPacket const* Write() override;

            bool Allow = false;
            PageTextInfo Info;
            uint32 PageTextID = 0;
        };

        class QueryNPCText final : public ClientPacket
        {
        public:
            QueryNPCText(WorldPacket&& packet) : ClientPacket(CMSG_NPC_TEXT_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
            uint32 TextID = 0;
        };

        class QueryNPCTextResponse final : public ServerPacket
        {
        public:
            QueryNPCTextResponse() : ServerPacket(SMSG_NPC_TEXT_UPDATE, 73) { }

            WorldPacket const* Write() override;

            uint32 TextID = 0;
            bool Allow = false;
            float Probabilities[MAX_GOSSIP_TEXT_OPTIONS];
            uint32 BroadcastTextID[MAX_GOSSIP_TEXT_OPTIONS];
        };

        class DBQueryBulk final : public ClientPacket
        {
        public:
            struct DBQueryRecord
            {
                ObjectGuid GUID;
                int32 RecordID = 0;
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
            int32 RecordID   = 0;
            ByteBuffer Data;
        };

        class HotfixNotifyBlob final : public ServerPacket
        {
        public:
            HotfixNotifyBlob() : ServerPacket(SMSG_HOTFIX_NOTIFY_BLOB, 4) { }

            WorldPacket const* Write() override;

            HotfixData const* Hotfixes = nullptr;
        };

        class QueryGameObject final : public ClientPacket
        {
        public:
            QueryGameObject(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJECT_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
            uint32 GameObjectID = 0;
        };

        struct GameObjectStats
        {
            std::string Name[4];
            std::string IconName;
            std::string CastBarCaption;
            std::string UnkString;
            uint32 Type = 0;
            uint32 DisplayID = 0;
            uint32 Data[MAX_GAMEOBJECT_DATA];
            float Size = 0.0f;
            std::vector<int32> QuestItems;
            uint32 Expansion = 0;

            size_t GetDataSize() const
            {
                //                                         [1..3] always empty '\0'                     '\0'                          '\0'                     '\0'                                 QuestItems counter
                return sizeof(Type) + sizeof(DisplayID) + (Name->size() + (4 * 1)) + (IconName.size() + 1) + (CastBarCaption.size() + 1) + (UnkString.size() + 1) + sizeof(Data) + sizeof(Size) + sizeof(uint8) + (QuestItems.size() * sizeof(int32)) + sizeof(Expansion);
            }
        };

        class QueryGameObjectResponse final : public ServerPacket
        {
        public:
            QueryGameObjectResponse() : ServerPacket(SMSG_GAMEOBJECT_QUERY_RESPONSE, 165) { }

            WorldPacket const* Write() override;

            uint32 GameObjectID = 0;
            bool Allow = false;
            GameObjectStats Stats;
        };

        class QueryCorpseLocationFromClient final : public ClientPacket
        {
        public:
            QueryCorpseLocationFromClient(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_CORPSE_LOCATION_FROM_CLIENT, std::move(packet)) { }

            void Read() override { }
        };

        class CorpseLocation final : public ServerPacket
        {
        public:
            CorpseLocation() : ServerPacket(SMSG_CORPSE_LOCATION, 1 + (5 * 4) + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Transport;
            G3D::Vector3 Position;
            int32 ActualMapID = 0;
            int32 MapID = 0;
            bool Valid = false;
        };

        class QueryCorpseTransport final : public ClientPacket
        {
        public:
            QueryCorpseTransport(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_CORPSE_TRANSPORT , std::move(packet)) { }

            void Read() override;

            ObjectGuid Transport;
        };

        class CorpseTransportQuery final : public ServerPacket
        {
        public:
            CorpseTransportQuery() : ServerPacket(SMSG_CORPSE_TRANSPORT_QUERY, 16) { }

            WorldPacket const* Write() override;

            G3D::Vector3 Position;
            float Facing = 0.0f;
        };

        class QueryTime final : public ClientPacket
        {
        public:
            QueryTime(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_TIME, std::move(packet)) { }

            void Read() override { }
        };

        class QueryTimeResponse final : public ServerPacket
        {
        public:
            QueryTimeResponse() : ServerPacket(SMSG_QUERY_TIME_RESPONSE, 4 + 4) { }

            WorldPacket const* Write() override;

            time_t CurrentTime = time_t(0);
            int32 TimeOutRequest = 0;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupHint const& lookupHint);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupData const& lookupData);

#endif // QueryPackets_h__
