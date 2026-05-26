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

#ifndef TRINITYCORE_NPC_PACKETS_H
#define TRINITYCORE_NPC_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "Position.h"
#include <array>

enum GossipOptionIcon : uint8;

namespace WorldPackets
{
    namespace NPC
    {
        // CMSG_BANKER_ACTIVATE
        // CMSG_BATTLEMASTER_HELLO
        // CMSG_BINDER_ACTIVATE
        // CMSG_GOSSIP_HELLO
        // CMSG_LIST_INVENTORY
        // CMSG_TRAINER_LIST
        class Hello final : public ClientPacket
        {
        public:
            Hello(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        struct ClientGossipOptions
        {
            int32 GossipOptionID = 0;
            GossipOptionIcon OptionNPC = {};
            int32 OptionFlags = 0;
            uint32 OptionCost = 0;
            std::string_view Text;
            std::string_view Confirm;
        };

        struct ClientGossipText
        {
            int32 QuestID = 0;
            int32 QuestLevel = 0;
            int32 QuestType = 0;
            bool Repeatable = false;
            std::string_view QuestTitle;
            int32 QuestFlags = 0;
        };

        ByteBuffer& operator<<(ByteBuffer& data, ClientGossipText const& gossipText);

        class GossipMessage final : public ServerPacket
        {
        public:
            explicit GossipMessage() : ServerPacket(SMSG_GOSSIP_MESSAGE, 200) { }

            WorldPacket const* Write() override;

            std::vector<ClientGossipOptions> GossipOptions;
            ObjectGuid GossipGUID;
            std::vector<ClientGossipText> GossipText;
            int32 RandomTextID = 0;
            int32 GossipID = 0;
        };

        struct VendorItem
        {
            int32 MuID = 0;
            uint32 Item = 0;
            uint32 ItemDisplayInfoID = 0;
            int32 Quantity = -1;
            int32 Price = 0;
            int32 Durability = 0;
            int32 StackCount = 0;
            int32 ExtendedCostID = 0;
        };

        class VendorInventory final : public ServerPacket
        {
        public:
            explicit VendorInventory() : ServerPacket(SMSG_LIST_INVENTORY, 600) { }

            WorldPacket const* Write() override;

            int8 Reason = 0;
            std::vector<VendorItem> Items;
            ObjectGuid Vendor;
        };

        struct TrainerListSpell
        {
            int32 SpellID          = 0;
            uint8 Usable           = 0;
            int32 MoneyCost        = 0;
            std::array<int32, 2> PointCost = { }; // compared with PLAYER_CHARACTER_POINTS in Lua
            uint8 ReqLevel         = 0;
            int32 ReqSkillLine     = 0;
            int32 ReqSkillRank     = 0;
            std::array<int32, 3> ReqAbility = { };
        };

        class TrainerList final : public ServerPacket
        {
        public:
            TrainerList() : ServerPacket(SMSG_TRAINER_LIST) { }

            WorldPacket const* Write() override;

            ObjectGuid TrainerGUID;
            int32 TrainerType = 0;
            std::vector<TrainerListSpell> Spells;
            std::string Greeting;
        };

        class GossipPOI final : public ServerPacket
        {
        public:
            GossipPOI() : ServerPacket(SMSG_GOSSIP_POI, 4 + 4 + 4 + 4 + 4 + 32) { }

            WorldPacket const* Write() override;

            uint32 Flags = 0;
            TaggedPosition<Position::XY> Pos;
            int32 Icon = 0;
            int32 Importance = 0;
            std::string Name;
        };

        class TrainerBuySpell final : public ClientPacket
        {
        public:
            TrainerBuySpell(WorldPacket&& packet) : ClientPacket(CMSG_TRAINER_BUY_SPELL, std::move(packet)) { }

            void Read() override;

            ObjectGuid TrainerGUID;
            int32 SpellID = 0;
        };

        class TrainerBuyFailed final : public ServerPacket
        {
        public:
            TrainerBuyFailed() : ServerPacket(SMSG_TRAINER_BUY_FAILED, 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid TrainerGUID;
            int32 SpellID             = 0;
            int32 TrainerFailedReason = 0;
        };

        class TrainerBuySucceeded final : public ServerPacket
        {
        public:
            TrainerBuySucceeded() : ServerPacket(SMSG_TRAINER_BUY_SUCCEEDED, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid TrainerGUID;
            int32 SpellID = 0;
        };
    }
}

#endif // TRINITYCORE_NPC_PACKETS_H
