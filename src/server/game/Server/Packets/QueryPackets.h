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
#include "ObjectGuid.h"

#include "SharedDefines.h"
#include "Creature.h"
#include "GameObject.h"
#include "ItemTemplate.h"
#include "QuestDef.h"

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
                ObjectGuid Guid;
        };

        struct CreatureStats
        {
            std::string Name;
            std::string NameAlt;
            std::string CursorName;
            uint32 Flags = 0;
            uint32 CreatureType = 0;
            uint32 CreatureFamily = 0;
            uint32 Classification = 0;
            uint32 ProxyCreatureID[MAX_KILL_CREDIT] = { };
            uint32 CreatureDisplayID[MAX_CREATURE_MODELS] = { };
            float HpMulti = 0.0f;
            float EnergyMulti = 0.0f;
            bool Leader = false;
            uint32 QuestItems[MAX_CREATURE_QUEST_ITEMS] = { };
            uint32 CreatureMovementInfoID = 0;
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
                ObjectGuid Guid;
        };

        struct GameObjectStats
        {
            std::string Name;
            std::string IconName;
            std::string CastBarCaption;
            std::string UnkString;
            uint32 Type = 0;
            uint32 DisplayID = 0;
            uint32 Data[MAX_GAMEOBJECT_DATA] = { };
            float Size = 0.0f;
            uint32 QuestItems[MAX_GAMEOBJECT_QUEST_ITEMS] = { };
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

        class QueryItemSingle final : public ClientPacket
        {
            public:
                QueryItemSingle(WorldPacket&& packet) : ClientPacket(CMSG_ITEM_QUERY_SINGLE, std::move(packet)) { }

                void Read() override;

                uint32 ItemID = 0;
        };

        struct ItemDamageData
        {
            float DamageMin = 0.0f;
            float DamageMax = 0.0f;
            uint32 DamageType = 0;
        };

        struct ItemStatData
        {
            uint32 ItemStatType = 0;
            int32 ItemStatValue = 0;
        };

        struct ItemSpellData
        {
            int32 SpellId = -1;
            uint32 SpellTrigger = 0;
            int32 SpellCharges = 0;
            int32 SpellCooldown = -1;
            uint32 SpellCategory = 0;
            int32 SpellCategoryCooldown = -1;
        };

        struct ItemSocketData
        {
            uint32 Color = 0;
            uint32 Content = 0;
        };

        struct ItemStats
        {
            uint32 Class = 0;
            uint32 SubClass = 0;
            int32 SoundOverrideSubclass = 0;
            std::string Name;
            uint32 DisplayInfoID = 0;
            uint32 Quality = 0;
            uint32 Flags = 0;
            uint32 Flags2 = 0;
            int32 BuyPrice = 0;
            uint32 SellPrice = 0;
            uint32 InventoryType = 0;
            uint32 AllowableClass = 0;
            uint32 AllowableRace = 0;
            uint32 ItemLevel = 0;
            uint32 RequiredLevel = 0;
            uint32 RequiredSkill = 0;
            uint32 RequiredSkillRank = 0;
            uint32 RequiredSpell = 0;
            uint32 RequiredHonorRank = 0;
            uint32 RequiredCityRank = 0;
            uint32 RequiredReputationFaction = 0;
            uint32 RequiredReputationRank = 0;
            int32 MaxCount = 0;
            int32 Stackable = 0;
            uint32 ContainerSlots = 0;
            uint32 StatsCount = 0;
            ItemStatData ItemStat[MAX_ITEM_PROTO_STATS];
            uint32 ScalingStatDistribution = 0;
            uint32 ScalingStatValue = 0;
            ItemDamageData Damage[MAX_ITEM_PROTO_DAMAGES];
            uint32 Resistance[MAX_SPELL_SCHOOL] = { };
            uint32 Delay = 0;
            uint32 AmmoType = 0;
            float RangedModRange = 0.0f;
            ItemSpellData Spells[MAX_ITEM_PROTO_SPELLS];
            uint32 Bonding = 0;
            std::string Description;
            uint32 PageText = 0;
            uint32 LanguageID = 0;
            uint32 PageMaterial = 0;
            uint32 StartQuest = 0;
            uint32 LockID = 0;
            int32 Material = 0;
            uint32 Sheath = 0;
            int32 RandomProperty = 0;
            int32 RandomSuffix = 0;
            uint32 Block = 0;
            uint32 ItemSet = 0;
            uint32 MaxDurability = 0;
            uint32 Area = 0;
            uint32 Map = 0;
            uint32 BagFamily = 0;
            uint32 TotemCategory = 0;
            ItemSocketData Socket[MAX_ITEM_PROTO_SOCKETS];
            uint32 SocketBonus = 0;
            uint32 GemProperties = 0;
            uint32 RequiredDisenchantSkill = 0;
            float ArmorDamageModifier = 0.0f;
            uint32 Duration = 0;
            uint32 ItemLimitCategory = 0;
            uint32 HolidayId = 0;
        };

        class QueryItemSingleResponse final : public ServerPacket
        {
            public:
                QueryItemSingleResponse() : ServerPacket(SMSG_ITEM_QUERY_SINGLE_RESPONSE, 500) { }

                WorldPacket const* Write() override;

                uint32 ItemID = 0;
                bool Allow = false;
                ItemStats Stats;
        };

        class QuestPOIQuery final : public ClientPacket
        {
            public:
                QuestPOIQuery(WorldPacket&& packet) : ClientPacket(CMSG_QUEST_POI_QUERY, std::move(packet)) { }

                void Read() override;

                uint32 MissingQuestCount = 0;
                uint32 MissingQuestPOIs[MAX_QUEST_LOG_SIZE] = { };
        };
    }
}

#endif // QueryPackets_h__
