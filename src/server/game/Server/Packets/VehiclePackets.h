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

#ifndef TRINITYCORE_VEHICLE_PACKETS_H
#define TRINITYCORE_VEHICLE_PACKETS_H

#include "Packet.h"
#include "MovementPackets.h"

namespace WorldPackets
{
    namespace Vehicle
    {
        class MoveSetVehicleRecID final : public ServerPacket
        {
        public:
            explicit MoveSetVehicleRecID() : ServerPacket(SMSG_MOVE_SET_VEHICLE_REC_ID, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0;
            int32 VehicleRecID = 0;
        };

        class MoveSetVehicleRecIdAck final : public ClientPacket
        {
        public:
            explicit MoveSetVehicleRecIdAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_SET_VEHICLE_REC_ID_ACK, std::move(packet)) { }

            void Read() override;

            WorldPackets::Movement::MovementAck Data;
            int32 VehicleRecID = 0;
        };

        class SetVehicleRecID final : public ServerPacket
        {
        public:
            explicit SetVehicleRecID() : ServerPacket(SMSG_SET_VEHICLE_REC_ID, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid VehicleGUID;
            int32 VehicleRecID = 0;
        };

        class OnCancelExpectedRideVehicleAura final : public ServerPacket
        {
        public:
            explicit OnCancelExpectedRideVehicleAura() : ServerPacket(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class MoveDismissVehicle final : public ClientPacket
        {
        public:
            explicit MoveDismissVehicle(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_DISMISS_VEHICLE, std::move(packet)) { }

            void Read() override;

            MovementInfo Status;
        };

        class RequestVehiclePrevSeat final : public ClientPacket
        {
        public:
            explicit RequestVehiclePrevSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_PREV_SEAT, std::move(packet)) { }

            void Read() override { }
        };

        class RequestVehicleNextSeat final : public ClientPacket
        {
        public:
            explicit RequestVehicleNextSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_NEXT_SEAT, std::move(packet)) { }

            void Read() override { }
        };

        class MoveChangeVehicleSeats final : public ClientPacket
        {
        public:
            explicit MoveChangeVehicleSeats(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_CHANGE_VEHICLE_SEATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid DstVehicle;
            MovementInfo Status;
            uint8 DstSeatIndex = 255;
        };

        class RequestVehicleSwitchSeat final : public ClientPacket
        {
        public:
            explicit RequestVehicleSwitchSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_SWITCH_SEAT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vehicle;
            uint8 SeatIndex = 255;
        };

        class RideVehicleInteract final : public ClientPacket
        {
        public:
            explicit RideVehicleInteract(WorldPacket&& packet) : ClientPacket(CMSG_RIDE_VEHICLE_INTERACT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vehicle;
        };

        class EjectPassenger final : public ClientPacket
        {
        public:
            explicit EjectPassenger(WorldPacket&& packet) : ClientPacket(CMSG_EJECT_PASSENGER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Passenger;
        };

        class RequestVehicleExit final : public ClientPacket
        {
        public:
            explicit RequestVehicleExit(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_EXIT, std::move(packet)) { }

            void Read() override { }
        };
    }
}

#endif // TRINITYCORE_VEHICLE_PACKETS_H
