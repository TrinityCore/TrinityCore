/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "MovementPackets.h"

namespace WorldPackets
{
    namespace Vehicle
    {

        class MoveSetVehicleRecID final : public ServerPacket
        {
        public:
            MoveSetVehicleRecID() : ServerPacket(SMSG_MOVE_SET_VEHICLE_REC_ID) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0;
            int32 VehicleRecID = 0;
        };

        class MoveSetVehicleRecIdAck final : public ClientPacket
        {
        public:
            MoveSetVehicleRecIdAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_SET_VEHICLE_REC_ID_ACK, std::move(packet)) { }

            void Read() override;

            WorldPackets::Movement::MovementAck Data;
            int32 VehicleRecID = 0;
        };

        class SetVehicleRecID final : public ServerPacket
        {
        public:
            SetVehicleRecID() : ServerPacket(SMSG_SET_VEHICLE_REC_ID) { }

            WorldPacket const* Write() override;

            ObjectGuid VehicleGUID;
            int32 VehicleRecID = 0;
        };

        class OnCancelExpectedRideVehicleAura final : public ServerPacket
        {
        public:
            OnCancelExpectedRideVehicleAura() : ServerPacket(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };
    }
}

#endif // VehiclePackets_h__
