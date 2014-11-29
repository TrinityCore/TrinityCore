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

#ifndef ItemPackets_h__
#define ItemPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Item
    {
        class SetProficiency final : public ServerPacket
        {
        public:
            SetProficiency() : ServerPacket(SMSG_SET_PROFICIENCY, 5) { }

            WorldPacket const* Write() override;

            uint32 ProficiencyMask;
            uint8 ProficiencyClass;
        };

        struct ItemBonusInstanceData
        {
            uint8 Context                   = 0;
            std::vector<int32> BonusListIDs;
        };

        struct ItemInstance
        {
            uint32 ItemID                   = 0;
            uint32 RandomPropertiesSeed     = 0;
            uint32 RandomPropertiesID       = 0;
            Optional<ItemBonusInstanceData> ItemBonus;
            std::vector<int32> Modifications;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemBonusInstanceData const& itemBonusInstanceData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Item::ItemInstance const& itemInstance);

#endif // ItemPackets_h__
