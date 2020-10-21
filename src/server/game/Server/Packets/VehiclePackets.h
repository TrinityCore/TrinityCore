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

#ifndef VehiclePackets_h__
#define VehiclePackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Vehicle
    {
        class SetVehicleRecID final : public ServerPacket
        {
        public:
            SetVehicleRecID() : ServerPacket(SMSG_SET_VEHICLE_REC_ID, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid VehicleGUID;
            int32 VehicleRecID = 0;
        };
    }
}

#endif // VehiclePackets_h__
