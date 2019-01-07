/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TransmogrificationPackets_h__
#define TransmogrificationPackets_h__

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
        };

        class TransmogrifyItems final : public ClientPacket
        {
        public:
            enum
            {
                MAX_TRANSMOGRIFY_ITEMS = 13
            };

            TransmogrifyItems(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOGRIFY_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            Array<TransmogrifyItem, MAX_TRANSMOGRIFY_ITEMS> Items;
            bool CurrentSpecOnly = false;
        };

        class TransmogCollectionUpdate final : public ServerPacket
        {
        public:
            TransmogCollectionUpdate() : ServerPacket(SMSG_TRANSMOG_COLLECTION_UPDATE) { }

            WorldPacket const* Write() override;

            bool IsFullUpdate = false;
            bool IsSetFavorite = false;
            std::vector<uint32> FavoriteAppearances;
        };

        class OpenTransmogrifier final : public ServerPacket
        {
        public:
            OpenTransmogrifier(ObjectGuid const& guid) : ServerPacket(SMSG_OPEN_TRANSMOGRIFIER, 16), Guid(guid) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };
    }
}

#endif // TransmogrificationPackets_h__
