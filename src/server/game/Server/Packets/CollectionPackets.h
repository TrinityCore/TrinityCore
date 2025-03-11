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

#ifndef TRINITYCORE_COLLECTION_PACKETS_H
#define TRINITYCORE_COLLECTION_PACKETS_H

#include "DBCEnums.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace Collections
    {
        class CollectionItemSetFavorite final : public ClientPacket
        {
        public:
            CollectionItemSetFavorite(WorldPacket&& packet) : ClientPacket(CMSG_COLLECTION_ITEM_SET_FAVORITE, std::move(packet)) { }

            void Read() override;

            ItemCollectionType Type = ItemCollectionType::None;
            uint32 ID = 0;
            bool IsFavorite = false;
        };

        struct ItemCollectionItemData
        {
            int32 ID = 0;
            ItemCollectionType Type = ItemCollectionType::None;
            int64 Unknown1110 = 0;
            int32 Flags = 0;
        };

        class AccountItemCollectionData final : public ServerPacket
        {
        public:
            AccountItemCollectionData() : ServerPacket(SMSG_ACCOUNT_ITEM_COLLECTION_DATA) { }

            WorldPacket const* Write() override;

            uint32 Unknown1110_1 = 0;
            ItemCollectionType Type = ItemCollectionType::None;
            bool Unknown1110_2 = false;
            std::vector<ItemCollectionItemData> Items;
        };
    }
}

#endif // TRINITYCORE_COLLECTION_PACKETS_H
