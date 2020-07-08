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

#ifndef LootPackets_h__
#define LootPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "ItemPacketsCommon.h"

namespace WorldPackets
{
    namespace Loot
    {
        class LootList final : public ServerPacket
        {
        public:
            LootList() : ServerPacket(SMSG_LOOT_LIST, 8 + 8 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Owner;
            ObjectGuid Master;
            ObjectGuid RoundRobinWinner;
        };
    }
}

#endif // LootPackets_h__
