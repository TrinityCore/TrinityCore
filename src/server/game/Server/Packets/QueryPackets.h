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
#include "PacketUtilities.h"
#include "Creature.h"
#include "GameObject.h"
#include "ItemPrototype.h"
#include "NPCHandler.h"
#include "ObjectMgr.h"
#include "QuestDef.h"

namespace WorldPackets
{
    namespace Query
    {
        class QueryPlayerName final : public ClientPacket
        {
            public:        
                QueryPlayerName(WorldPacket&& packet) : ClientPacket(CMSG_NAME_QUERY, std::move(packet)) { }

                void Read() override;

                ObjectGuid Player;
        };

        struct PlayerGuidLookupData
        {
            bool Initialize(ObjectGuid const& guid, Player const* player = nullptr);

            std::string Name;
            uint8 VirtualRealmAddress = 0;
            uint8 Race = RACE_NONE;
            uint8 Sex = GENDER_NONE;
            uint8 Class = CLASS_NONE;
            uint8 Level = 0;
            DeclinedName const* DeclinedNames = nullptr;
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

        class QueryPetName final : public ClientPacket
        {
            public:
                QueryPetName(WorldPacket&& packet) : ClientPacket(CMSG_PET_NAME_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 Number;
                ObjectGuid Pet;
        };

        class QueryPetNameResponse final : public ServerPacket
        {
            public:
                QueryPetNameResponse() : ServerPacket(SMSG_PET_NAME_QUERY_RESPONSE, 16) { }

                WorldPacket const* Write() override;

                uint32 Number;
                Optional<DeclinedName> DeclinedNames;
                std::string Name;
                uint32 Timestamp = 0;
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

                time_t CurrentTime;
                int32 TimeOutRequest;
        };

        class QueryCreature final : public ClientPacket
        {
            public:
                QueryCreature(WorldPacket&& packet) : ClientPacket(CMSG_CREATURE_QUERY, std::move(packet)) { }

                void Read() override;

                ObjectGuid Guid;
                uint32 CreatureID;
        };

        class QueryCreatureResponse final : public ServerPacket
        {
            public:
                struct CreatureStats
                {
                    std::string Name;
                    std::string NameAlt;
                    std::string CursorName;
                    uint32 Flags;
                    uint32 CreatureType;
                    uint32 CreatureFamily;
                    uint32 Classification;
                    uint32 ProxyCreatureID[MAX_KILL_CREDIT];
                    uint32 CreatureDisplayID[MAX_CREATURE_MODELS];
                    float HpMulti;
                    float EnergyMulti;
                    bool Leader;
                    uint32 QuestItems[MAX_CREATURE_QUEST_ITEMS];
                    uint32 CreatureMovementInfoID;
                };

                QueryCreatureResponse() : ServerPacket(SMSG_CREATURE_QUERY_RESPONSE, 100) { }

                WorldPacket const* Write() override;

                uint32 CreatureID;
                Optional<CreatureStats> Stats;
        };

        class QueryItem final : public ClientPacket
        {
            public:
                QueryItem(WorldPacket&& packet) : ClientPacket(CMSG_ITEM_QUERY_SINGLE, std::move(packet)) { }

                void Read() override;

                uint32 ItemID;
        };

        class QueryItemResponse final : public ServerPacket
        {
            public:
                QueryItemResponse() : ServerPacket(SMSG_ITEM_QUERY_SINGLE_RESPONSE) { }

                WorldPacket const* Write() override;

                uint32 ItemID;
                Optional<ItemTemplate> Info;
        };

        class QueryGameObject final : public ClientPacket
        {
            public:
                QueryGameObject(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJECT_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 GameObjectID;
                ObjectGuid Guid;
        };

        class QueryGameObjectResponse final : public ServerPacket
        {
            public:
                struct GameObjectStats
                {
                    std::string Name;
                    std::string IconName;
                    std::string CastBarCaption;
                    std::string UnkString;
                    uint32 Type = 0;
                    uint32 DisplayID = 0;
                    uint32 Data[MAX_GAMEOBJECT_DATA];
                    float Size = 0.0f;
                    uint32 QuestItems[MAX_GAMEOBJECT_QUEST_ITEMS];
                };

                QueryGameObjectResponse() : ServerPacket(SMSG_GAMEOBJECT_QUERY_RESPONSE, 150) { }

                WorldPacket const* Write() override;

                uint32 GameObjectID;
                Optional<GameObjectStats> Stats;
        };

        class QueryCorpseLocation final : public ClientPacket
        {
            public:
                QueryCorpseLocation(WorldPacket&& packet) : ClientPacket(CMSG_CORPSE_QUERY, std::move(packet)) { }

                void Read() override { }
        };

        class QueryCorpseLocationResponse final : public ServerPacket
        {
            public:
                struct CorpseLoc
                {
                    G3D::Vector3 Position;
                    uint32 ActualMapID = 0;
                    uint32 MapID = 0;
                };

                QueryCorpseLocationResponse() : ServerPacket(SMSG_CORPSE_QUERY, 25) { }

                WorldPacket const* Write() override;

                Optional<CorpseLoc> Location;
        };

        class QueryCorpseMapPosition final : public ClientPacket
        {
            public:
                QueryCorpseMapPosition(WorldPacket&& packet) : ClientPacket(CMSG_CORPSE_MAP_POSITION_QUERY, std::move(packet)) { }

                void Read() override { _worldPacket >> Unknown; }

                uint32 Unknown;
        };

        class QueryCorpseMapPositionResponse : public ServerPacket
        {
            public:
                QueryCorpseMapPositionResponse() : ServerPacket(SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE, 16) { }

                WorldPacket const* Write() override;
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
                QueryNPCTextResponse() : ServerPacket(SMSG_NPC_TEXT_UPDATE, 256) { }

                WorldPacket const* Write() override;

                uint32 TextID = 0;
                bool Allow = false;
                float Probabilities[MAX_GOSSIP_TEXT_OPTIONS];
                std::string Texts[2][MAX_GOSSIP_TEXT_OPTIONS];
                uint32 Languages[MAX_GOSSIP_TEXT_OPTIONS];
                QEmote Emotes[MAX_GOSSIP_TEXT_OPTIONS][MAX_GOSSIP_TEXT_EMOTES];
            private:
                static std::string const DefaultGossip;
        };

        class QueryPageText final : public ClientPacket
        {
            public:
                QueryPageText(WorldPacket&& packet) : ClientPacket(CMSG_PAGE_TEXT_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 PageID = 0;
                ObjectGuid Guid;
        };

        class QueryPageTextResponse final : public ServerPacket
        {
            public:
                struct PageTextInfo
                {
                    uint32 ID = 0;
                    uint16 NextPageID = 0;
                    std::string Text;
                };

                QueryPageTextResponse() : ServerPacket(SMSG_PAGE_TEXT_QUERY_RESPONSE, 50) { }

                WorldPacket const* Write() override;

                bool Allow = false;
                PageTextInfo Page;
            private:
                static std::string const MissingText;
        };
        
        class QuestPOIQuery final : public ClientPacket
        {
            public:
                QuestPOIQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_POI_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 MissingQuestCount = 0;
                uint32 MissingQuestPOIs[MAX_QUEST_LOG_SIZE];
        };

        class QuestPOIQueryResponse : public ServerPacket
        {
            public:
                struct QuestPOIBlobPoint
                {
                    int32 X = 0;
                    int32 Y = 0;
                };

                struct QuestPOIBlobData
                {
                    uint32 BlobIndex = 0;
                    int32 ObjectiveIndex = 0;
                    uint32 MapID = 0;
                    uint32 WorldMapAreaID = 0;
                    uint32 Floor = 0;
                    uint32 Unk3 = 0;
                    uint32 Unk4 = 0;
                    std::vector<QuestPOIBlobPoint> QuestPOIBlobPointStats;
                };

                struct QuestPOIData
                {
                    uint32 QuestID = 0;
                    std::vector<QuestPOIBlobData> QuestPOIBlobDataStats;
                };

                QuestPOIQueryResponse() : ServerPacket(SMSG_QUEST_POI_QUERY_RESPONSE) { }

                WorldPacket const* Write() override;

                std::vector<QuestPOIData> QuestPOIDataStats;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Query::PlayerGuidLookupData const& lookupData);

#endif // QueryPackets_h__
