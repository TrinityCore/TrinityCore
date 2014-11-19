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

#pragma once

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace EquipmentSet
    {
        struct EquipmentSetData
        {
            uint64 Guid  = 0; ///< Set Identifier
            uint32 SetID = 0; ///< Index
            uint32 IgnoreMask = 0;
            std::string SetName;
            std::string SetIcon;
            ObjectGuid Pieces[EQUIPMENT_SLOT_END];
        };

        class LoadEquipmentSet final : public ServerPacket
        {
        public:
            LoadEquipmentSet() : ServerPacket(SMSG_EQUIPMENT_SET_LIST, 4) { }

            WorldPacket const* Write() override;

            std::vector<EquipmentSetData> SetData;
        };
    }
}
