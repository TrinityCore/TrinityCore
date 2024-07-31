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

#ifndef NPCPackets_h__
#define NPCPackets_h__

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"
#include "Position.h"
#include <array>

enum class GossipOptionFlags : int32;
enum class GossipOptionNpc : uint8;
enum class GossipOptionStatus : uint8;
enum class GossipOptionRewardType : uint8;
enum class PlayerInteractionType : int32;

namespace WorldPackets
{
    namespace NPC
    {
        // CMSG_BANKER_ACTIVATE
        // CMSG_BINDER_ACTIVATE
        // CMSG_BINDER_CONFIRM
        // CMSG_GOSSIP_HELLO
        // CMSG_LIST_INVENTORY
        // CMSG_TRAINER_LIST
        // CMSG_BATTLEMASTER_HELLO
        class Hello final : public ClientPacket
        {
        public:
            Hello(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class TC_GAME_API NPCInteractionOpenResult final : public ServerPacket
        {
        public:
            NPCInteractionOpenResult() : ServerPacket(SMSG_NPC_INTERACTION_OPEN_RESULT, 16 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Npc;
            PlayerInteractionType InteractionType = {};
            bool Success = true;
        };

        struct TreasureItem
        {
            GossipOptionRewardType Type = GossipOptionRewardType(0);
            int32 ID = 0;
            int32 Quantity = 0;
        };

        struct TreasureLootList
        {
            std::vector<TreasureItem> Items;
        };

        struct ClientGossipOptions
        {
            int32 GossipOptionID  = 0;
            GossipOptionNpc OptionNPC = {};
            uint8 OptionFlags   = 0;
            int32 OptionCost    = 0;
            uint32 OptionLanguage = 0;
            GossipOptionFlags Flags = {};
            int32 OrderIndex = 0;
            GossipOptionStatus Status = {};
            std::string_view Text;
            std::string_view Confirm;
            TreasureLootList Treasure;
            Optional<int32> SpellID;
            Optional<int32> OverrideIconID;
        };

        struct ClientGossipText
        {
            int32 QuestID = 0;
            int32 ContentTuningID = 0;
            int32 QuestType = 0;
            bool Repeatable = false;
            bool Important = false;
            std::string QuestTitle;
            std::array<int32, 2> QuestFlags = { };
        };

        ByteBuffer& operator<<(ByteBuffer& data, ClientGossipText const& gossipText);

        class GossipMessage final : public ServerPacket
        {
        public:
            GossipMessage() : ServerPacket(SMSG_GOSSIP_MESSAGE, 200) { }

            WorldPacket const* Write() override;

            std::vector<ClientGossipOptions> GossipOptions;
            int32 FriendshipFactionID = 0;
            ObjectGuid GossipGUID;
            std::vector<ClientGossipText> GossipText;
            Optional<int32> TextID;             // in classic variants this still holds npc_text id
            Optional<int32> BroadcastTextID;
            int32 GossipID = 0;
        };

        class GossipSelectOption final : public ClientPacket
        {
        public:
            GossipSelectOption(WorldPacket&& packet) : ClientPacket(CMSG_GOSSIP_SELECT_OPTION, std::move(packet)) { }

            void Read() override;

            ObjectGuid GossipUnit;
            int32 GossipOptionID = 0;
            int32 GossipID = 0;
            std::string PromotionCode;
        };

        class GossipOptionNPCInteraction final : public ServerPacket
        {
        public:
            GossipOptionNPCInteraction() : ServerPacket(SMSG_GOSSIP_OPTION_NPC_INTERACTION, 16 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid GossipGUID;
            int32 GossipNpcOptionID = 0;
            Optional<int32> FriendshipFactionID;
        };

        class GossipComplete final : public ServerPacket
        {
        public:
            GossipComplete() : ServerPacket(SMSG_GOSSIP_COMPLETE, 0) { }

            WorldPacket const* Write() override;

            bool SuppressSound = false;
        };

        struct VendorItem
        {
            int32 MuID                      = 0;
            int32 Type                      = 0;
            WorldPackets::Item::ItemInstance Item;
            int32 Quantity                  = -1;
            uint64 Price                    = 0;
            int32 Durability                = 0;
            int32 StackCount                = 0;
            int32 ExtendedCostID            = 0;
            int32 PlayerConditionFailed     = 0;
            bool Locked                     = false;
            bool DoNotFilterOnVendor        = false;
            bool Refundable                 = false;
        };

        class VendorInventory final : public ServerPacket
        {
        public:
            VendorInventory() : ServerPacket(SMSG_VENDOR_INVENTORY, 600) { }

            WorldPacket const* Write() override;

            uint8 Reason = 0;
            std::vector<VendorItem> Items;
            ObjectGuid Vendor;
        };

        struct TrainerListSpell
        {
            int32 SpellID       = 0;
            uint32 MoneyCost    = 0;
            uint32 ReqSkillLine = 0;
            uint32 ReqSkillRank = 0;
            std::array<int32, 3> ReqAbility = { };
            uint8 Usable        = 0;
            uint8 ReqLevel      = 0;
        };

        class TrainerList final : public ServerPacket
        {
        public:
            TrainerList() : ServerPacket(SMSG_TRAINER_LIST, 150) { }

            WorldPacket const* Write() override;

            ObjectGuid TrainerGUID;
            int32 TrainerType   = 0;
            int32 TrainerID     = 1;
            std::vector<TrainerListSpell> Spells;
            std::string Greeting;
        };

        class GossipPOI final : public ServerPacket
        {
        public:
            GossipPOI() : ServerPacket(SMSG_GOSSIP_POI, 2 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 ID            = 0;
            uint32 Flags        = 0;
            TaggedPosition<Position::XYZ> Pos;
            int32 Icon          = 0;
            int32 Importance    = 0;
            int32 WMOGroupID    = 0;
            std::string Name;
        };

        class SpiritHealerActivate final : public ClientPacket
        {
        public:
            SpiritHealerActivate(WorldPacket&& packet) : ClientPacket(CMSG_SPIRIT_HEALER_ACTIVATE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Healer;
        };

        class TabardVendorActivate final : public ClientPacket
        {
        public:
            TabardVendorActivate(WorldPacket&& packet) : ClientPacket(CMSG_TABARD_VENDOR_ACTIVATE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vendor;
            int32 Type = 0;
        };

        class TrainerBuySpell final : public ClientPacket
        {
        public:
            TrainerBuySpell(WorldPacket&& packet) : ClientPacket(CMSG_TRAINER_BUY_SPELL, std::move(packet)) { }

            void Read() override;

            ObjectGuid TrainerGUID;
            int32 TrainerID     = 0;
            int32 SpellID       = 0;
        };

        class TrainerBuyFailed final : public ServerPacket
        {
        public:
            TrainerBuyFailed() : ServerPacket(SMSG_TRAINER_BUY_FAILED, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid TrainerGUID;
            int32 SpellID               = 0;
            int32 TrainerFailedReason   = 0;
        };

        class RequestStabledPets final : public ClientPacket
        {
        public:
            RequestStabledPets(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_STABLED_PETS, std::move(packet)) { }

            void Read() override;

            ObjectGuid StableMaster;
        };

        class SetPetSlot final : public ClientPacket
        {
        public:
            SetPetSlot(WorldPacket&& packet) : ClientPacket(CMSG_SET_PET_SLOT, std::move(packet)) { }

            void Read() override;

            ObjectGuid StableMaster;
            uint32 PetNumber = 0;
            uint8 DestSlot = 0;
        };
    }
}

#endif // NPCPackets_h__
