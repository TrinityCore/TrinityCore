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

#ifndef TRINITYCORE_TRANSMOGRIFICATION_PACKETS_H
#define TRINITYCORE_TRANSMOGRIFICATION_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "PacketUtilities.h"

enum class TransmogOutfitDisplayType : uint8;
enum class TransmogOutfitEntrySource : uint8;
enum class TransmogOutfitSetType : uint8;
enum class TransmogOutfitSlot : int8;
enum class TransmogOutfitSlotOption : uint8;

namespace WorldPackets
{
    namespace Transmogrification
    {
        struct TransmogrifyItem
        {
            int32 ItemModifiedAppearanceID = 0;
            uint32 Slot = 0;
            int32 SpellItemEnchantmentID = 0;
            int32 SecondaryItemModifiedAppearanceID = 0;
        };

        class TransmogrifyItems final : public ClientPacket
        {
        public:
            enum
            {
                MAX_TRANSMOGRIFY_ITEMS = 13
            };

            explicit TransmogrifyItems(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOGRIFY_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            Array<TransmogrifyItem, MAX_TRANSMOGRIFY_ITEMS> Items;
            bool CurrentSpecOnly = false;
        };

        struct TransmogOutfitDataInfo
        {
            TransmogOutfitSetType SetType = { };
            bool SituationsEnabled = false;
            uint32 Icon = 0;
            std::string_view Name;
        };

        class TransmogOutfitNew final : public ClientPacket
        {
        public:
            explicit TransmogOutfitNew(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_NEW, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            TransmogOutfitDataInfo Info;
            TransmogOutfitEntrySource Source = { };
        };

        class TransmogOutfitNewEntryAdded final : public ServerPacket
        {
        public:
            explicit TransmogOutfitNewEntryAdded() : ServerPacket(SMSG_TRANSMOG_OUTFIT_NEW_ENTRY_ADDED, 4) { }

            WorldPacket const* Write() override;

            uint32 TransmogOutfitID = 0;
        };

        class TransmogOutfitUpdateInfo final : public ClientPacket
        {
        public:
            explicit TransmogOutfitUpdateInfo(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_UPDATE_INFO, std::move(packet)) { }

            void Read() override;

            uint32 OutfitID = 0;
            ObjectGuid Npc;
            TransmogOutfitDataInfo Info;
        };

        class TransmogOutfitInfoUpdated final : public ServerPacket
        {
        public:
            explicit TransmogOutfitInfoUpdated() : ServerPacket(SMSG_TRANSMOG_OUTFIT_INFO_UPDATED, 4 + 1 + 4 + 1 + 1 + 128) { }

            WorldPacket const* Write() override;

            uint32 TransmogOutfitID = 0;
            TransmogOutfitDataInfo const* OutfitInfo = nullptr;
        };

        struct TransmogOutfitSituationInfo
        {
            uint32 SituationID = 0;
            uint32 SpecID = 0;
            uint32 LoadoutID = 0;
            uint32 EquipmentSetID = 0;
        };

        class TransmogOutfitUpdateSituations final : public ClientPacket
        {
        public:
            explicit TransmogOutfitUpdateSituations(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_UPDATE_SITUATIONS, std::move(packet)) { }

            void Read() override;

            uint32 OutfitID = 0;
            ObjectGuid Npc;
            bool SituationsEnabled = false;
            Array<TransmogOutfitSituationInfo, 100> Situations;
        };

        class TransmogOutfitSituationsUpdated final : public ServerPacket
        {
        public:
            explicit TransmogOutfitSituationsUpdated() : ServerPacket(SMSG_TRANSMOG_OUTFIT_SITUATIONS_UPDATED, 4 + 4 + 10 * (4 + 4 + 4 + 4) + 1) { }

            WorldPacket const* Write() override;

            uint32 TransmogOutfitID = 0;
            bool SituationsEnabled = false;
            std::span<TransmogOutfitSituationInfo const> Situations;
        };

        struct TransmogOutfitSlotData
        {
            TransmogOutfitSlot Slot = { };
            TransmogOutfitSlotOption SlotOption = { };
            TransmogOutfitDisplayType AppearanceDisplayType = { };
            TransmogOutfitDisplayType IllusionDisplayType = { };
            uint32 ItemModifiedAppearanceID = 0;
            uint32 SpellItemEnchantmentID = 0;
            uint32 Flags = 0;
        };

        class TransmogOutfitUpdateSlots final : public ClientPacket
        {
        public:
            explicit TransmogOutfitUpdateSlots(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_UPDATE_SLOTS, std::move(packet)) { }

            void Read() override;

            uint32 OutfitID = 0;
            Array<TransmogOutfitSlotData, 30> Slots;
            ObjectGuid Npc;
            uint64 Cost = 0;
            bool UseAvailableDiscount = false;
        };

        class TransmogOutfitSlotsUpdated final : public ServerPacket
        {
        public:
            explicit TransmogOutfitSlotsUpdated() : ServerPacket(SMSG_TRANSMOG_OUTFIT_SLOTS_UPDATED, 4 + 4 + 30 * (1 + 1 + 4 + 1 + 4 + 1 + 4)) { }

            WorldPacket const* Write() override;

            uint32 TransmogOutfitID = 0;
            std::span<TransmogOutfitSlotData const> Slots;
        };

        class AccountTransmogUpdate final : public ServerPacket
        {
        public:
            explicit AccountTransmogUpdate() : ServerPacket(SMSG_ACCOUNT_TRANSMOG_UPDATE) { }

            WorldPacket const* Write() override;

            bool IsFullUpdate = false;
            bool IsSetFavorite = false;
            std::vector<uint32> FavoriteAppearances;
            std::vector<uint32> NewAppearances;
        };
    }
}

#endif // TRINITYCORE_TRANSMOGRIFICATION_PACKETS_H
