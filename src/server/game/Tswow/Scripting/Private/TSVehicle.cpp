/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <memory.h>
#include "Object.h"
#include "Vehicle.h"
#include "TSIncludes.h"
#include "TSVehicle.h"
#include "TSUnit.h"

TSVehicle::TSVehicle(Vehicle *vehicle)
{
    this->vehicle = vehicle;
}

TSVehicle::TSVehicle()
{
    this->vehicle = nullptr;
}

#ifndef CLASSIC
#ifndef TBC

/**
 * Returns true if the [Unit] passenger is on board
 *
 * @param [Unit] passenger
 * @return bool isOnBoard
 */
bool TSVehicle::IsOnBoard(TSUnit _passenger)
{
    auto passenger = _passenger.unit;
#if defined TRINITY || AZEROTHCORE
    return passenger->IsOnVehicle(vehicle->GetBase());
#else
    return vehicle->HasOnBoard(passenger);
#endif
}
    
/**
 * Returns the [Vehicle]'s owner
 *
 * @return [Unit] owner
 */
TSUnit  TSVehicle::GetOwner() 
{
#if defined TRINITY || AZEROTHCORE
     return TSUnit(vehicle->GetBase());
#else
     return TSUnit(vehicle->GetOwner());
#endif
}
    
/**
 * Returns the [Vehicle]'s entry
 *
 * @return uint32 entry
 */
uint32 TSVehicle::GetEntry() 
{
#if defined TRINITY || AZEROTHCORE
    return vehicle->GetVehicleInfo()->ID;
#else
    return vehicle->GetVehicleEntry()->m_ID;
#endif
}
    
/**
 * Returns the [Vehicle]'s passenger in the specified seat
 *
 * @param int8 seat
 * @return [Unit] passenger
 */
TSUnit  TSVehicle::GetPassenger(int8 seatId) 
{
     return TSUnit(vehicle->GetPassenger(seatId));
}
    
/**
 * Adds [Unit] passenger to a specified seat in the [Vehicle]
 *
 * @param [Unit] passenger
 * @param int8 seat
 */
void TSVehicle::AddPassenger(TSUnit _passenger,int8 seatId)
{
    auto passenger = _passenger.unit;
#if defined TRINITY || AZEROTHCORE
    vehicle->AddPassenger(passenger, seatId);
#else
    if (vehicle->CanBoard(passenger))
        vehicle->Board(passenger, seatId);
#endif
}
    
/**
 * Removes [Unit] passenger from the [Vehicle]
 *
 * @param [Unit] passenger
 */
void TSVehicle::RemovePassenger(TSUnit _passenger)
{
    auto passenger = _passenger.unit;
#if defined TRINITY || AZEROTHCORE
    vehicle->RemovePassenger(passenger);
#else
    vehicle->UnBoard(passenger, false);
#endif
}
    
    
#endif // CLASSIC
#endif // TBC
