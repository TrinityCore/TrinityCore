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

#include "VehiclePackets.h"

namespace WorldPackets::Vehicle
{
WorldPacket const* MoveSetVehicleRecID::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << int32(VehicleRecID);

    return &_worldPacket;
}

void MoveSetVehicleRecIdAck::Read()
{
    _worldPacket >> Data;
    _worldPacket >> VehicleRecID;
}

WorldPacket const* SetVehicleRecID::Write()
{
    _worldPacket << VehicleGUID;
    _worldPacket << int32(VehicleRecID);

    return &_worldPacket;
}

void MoveDismissVehicle::Read()
{
    _worldPacket >> Status;
}

void MoveChangeVehicleSeats::Read()
{
    _worldPacket >> Status;
    _worldPacket >> DstVehicle;
    _worldPacket >> DstSeatIndex;
}

void RequestVehicleSwitchSeat::Read()
{
    _worldPacket >> Vehicle;
    _worldPacket >> SeatIndex;
}

void RideVehicleInteract::Read()
{
    _worldPacket >> Vehicle;
}

void EjectPassenger::Read()
{
    _worldPacket >> Passenger;
}
}
