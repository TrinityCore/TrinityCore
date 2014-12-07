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

#ifndef QueryPackets_h__
#define QueryPackets_h__

#include "Packet.h"
#include "Creature.h"
#include "NPCHandler.h"
#include "DB2Stores.h"

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
            bool IsDeleted             = false;
            ObjectGuid AccountID;
            ObjectGuid BnetAccountID;
            ObjectGuid GuidActual;
            std::string Name;
            uint32 VirtualRealmAddress = 0;
            uint8 Race                 = RACE_NONE;
            uint8 Sex                  = GENDER_NONE;
            uint8 ClassID              = CLASS_NONE;
            uint8 Level                = 0;
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
            int32 RecordID   = 0;

            // These are not sent directly
            uint32 Locale = 0;
            DB2StorageBase const* Data = nullptr;
        };
    }
}

#endif // QueryPackets_h__
