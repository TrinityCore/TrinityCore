/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
            MoveSetVehicleRecID() : ServerPacket(SMSG_MOVE_SET_VEHICLE_REC_ID, 16 + 4 + 4) { }

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
            SetVehicleRecID() : ServerPacket(SMSG_SET_VEHICLE_REC_ID, 16 + 4) { }

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

        class MoveDismissVehicle final : public ClientPacket
        {
        public:
            MoveDismissVehicle(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_DISMISS_VEHICLE, std::move(packet)) { }

            void Read() override;

            MovementInfo Status;
        };

        class RequestVehiclePrevSeat final : public ClientPacket
        {
        public:
            RequestVehiclePrevSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_PREV_SEAT, std::move(packet)) { }

            void Read() override { }
        };

        class RequestVehicleNextSeat final : public ClientPacket
        {
        public:
            RequestVehicleNextSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_NEXT_SEAT, std::move(packet)) { }

            void Read() override { }
        };

        class MoveChangeVehicleSeats final : public ClientPacket
        {
        public:
            MoveChangeVehicleSeats(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_CHANGE_VEHICLE_SEATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid DstVehicle;
            MovementInfo Status;
            uint8 DstSeatIndex = 255;
        };

        class RequestVehicleSwitchSeat final : public ClientPacket
        {
        public:
            RequestVehicleSwitchSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_SWITCH_SEAT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vehicle;
            uint8 SeatIndex = 255;
        };

        class RideVehicleInteract final : public ClientPacket
        {
        public:
            RideVehicleInteract(WorldPacket&& packet) : ClientPacket(CMSG_RIDE_VEHICLE_INTERACT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vehicle;
        };

        class EjectPassenger final : public ClientPacket
        {
        public:
            EjectPassenger(WorldPacket&& packet) : ClientPacket(CMSG_EJECT_PASSENGER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Passenger;
        };

        class RequestVehicleExit final : public ClientPacket
        {
        public:
            RequestVehicleExit(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_EXIT, std::move(packet)) { }

            void Read() override { }
        };
    }
}

#endif // VehiclePackets_h__
