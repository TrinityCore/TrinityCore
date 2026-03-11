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

        struct TransmogOutfitSlot
        {
            int8 Slot = 0;
            uint8 SlotOption = 0;
            uint32 ItemModifiedAppearanceID = 0;
            uint8 AppearanceDisplayType = 0;
            uint32 SpellItemEnchantmentID = 0;
            uint8 IllusionDisplayType = 0;
            uint32 Flags = 0;
        };

        class TransmogOutfitUpdateSlots final : public ClientPacket
        {
        public:
            static constexpr uint32 MAX_OUTFIT_SLOTS = 30;

            explicit TransmogOutfitUpdateSlots(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_UPDATE_SLOTS, std::move(packet)) { }

            void Read() override;

            uint32 OutfitID = 0;
            ObjectGuid Npc;
            std::vector<TransmogOutfitSlot> Slots;
            uint8 PaymentType = 0;
        };

        class TransmogOutfitSlotsUpdated final : public ServerPacket
        {
        public:
            explicit TransmogOutfitSlotsUpdated() : ServerPacket(SMSG_TRANSMOG_OUTFIT_SLOTS_UPDATED) { }

            WorldPacket const* Write() override;

            uint32 OutfitID = 0;
            std::vector<TransmogOutfitSlot> Slots;
        };
        class TransmogOutfitNew final : public ClientPacket
        {
        public:
            explicit TransmogOutfitNew(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_NEW, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            std::string Name;
            uint32 Icon = 0;
        };

        class TransmogOutfitUpdateInfo final : public ClientPacket
        {
        public:
            explicit TransmogOutfitUpdateInfo(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOG_OUTFIT_UPDATE_INFO, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            uint64 OutfitID = 0;
            std::string Name;
            uint32 Icon = 0;
        };

        class ClearNewAppearance final : public ClientPacket
        {
        public:
            explicit ClearNewAppearance(WorldPacket&& packet) : ClientPacket(CMSG_CLEAR_NEW_APPEARANCE, std::move(packet)) { }

            void Read() override;

            uint32 ItemModifiedAppearanceID = 0;
        };

        class TransmogOutfitNewEntryAdded final : public ServerPacket
        {
        public:
            explicit TransmogOutfitNewEntryAdded() : ServerPacket(SMSG_TRANSMOG_OUTFIT_NEW_ENTRY_ADDED) { }

            WorldPacket const* Write() override;

            uint64 OutfitID = 0;
        };

        class TransmogOutfitInfoUpdated final : public ServerPacket
        {
        public:
            TransmogOutfitInfoUpdated() : ServerPacket(SMSG_TRANSMOG_OUTFIT_INFO_UPDATED, 8) { }

            WorldPacket const* Write() override;

            uint64 OutfitID = 0;
        };

    }
}

#endif // TRINITYCORE_TRANSMOGRIFICATION_PACKETS_H
