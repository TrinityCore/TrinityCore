/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_VEHICLE_H
#define MANGOSSERVER_VEHICLE_H

#include "ObjectDefines.h"
#include "Creature.h"
#include "Unit.h"

class Vehicle : public Creature
{
    public:
        explicit Vehicle();
        virtual ~Vehicle();

        void AddToWorld();
        void RemoveFromWorld();

        bool Create (uint32 guidlow, Map *map, uint32 phaseMask, uint32 Entry, uint32 vehicleId, uint32 team);

        void setDeathState(DeathState s);                   // overwrite virtual Creature::setDeathState and Unit::setDeathState
        void Update(uint32 diff);                           // overwrite virtual Creature::Update and Unit::Update

        uint32 GetVehicleId() { return m_vehicleId; }
        void SetVehicleId(uint32 vehicleid) { m_vehicleId = vehicleid; }

        void Dismiss();

        bool LoadFromDB(uint32 guid, Map *map);
    protected:
        uint32 m_vehicleId;

    private:
        void SaveToDB(uint32, uint8)                        // overwrited of Creature::SaveToDB     - don't must be called
        {
            assert(false);
        }
        void DeleteFromDB()                                 // overwrited of Creature::DeleteFromDB - don't must be called
        {
            assert(false);
        }
};
#endif
