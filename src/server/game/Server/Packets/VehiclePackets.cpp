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

#include "VehiclePackets.h"

WorldPacket const* WorldPackets::Vehicle::MoveSetVehicleRecID::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << int32(VehicleRecID);

    return &_worldPacket;
}

void WorldPackets::Vehicle::MoveSetVehicleRecIdAck::Read()
{
    _worldPacket >> Data;
    _worldPacket >> VehicleRecID;
}

WorldPacket const* WorldPackets::Vehicle::SetVehicleRecID::Write()
{
    _worldPacket << VehicleGUID;
    _worldPacket << int32(VehicleRecID);

    return &_worldPacket;
}

void WorldPackets::Vehicle::MoveDismissVehicle::Read()
{
    _worldPacket >> Status;
}

void WorldPackets::Vehicle::MoveChangeVehicleSeats::Read()
{
    _worldPacket >> Status;
    _worldPacket >> DstVehicle;
    _worldPacket >> DstSeatIndex;
}

void WorldPackets::Vehicle::RequestVehicleSwitchSeat::Read()
{
    _worldPacket >> Vehicle;
    _worldPacket >> SeatIndex;
}

void WorldPackets::Vehicle::RideVehicleInteract::Read()
{
    _worldPacket >> Vehicle;
}

void WorldPackets::Vehicle::EjectPassenger::Read()
{
    _worldPacket >> Passenger;
}
