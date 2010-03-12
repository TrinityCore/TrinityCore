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

#ifndef __TRINITY_VEHICLE_H
#define __TRINITY_VEHICLE_H

#include "ObjectDefines.h"

struct VehicleEntry;
struct VehicleSeatEntry;
class Unit;

enum PowerType
{
    POWER_STEAM     = 61,
    POWER_PYRITE    = 41,
};

struct VehicleSeat
{
    explicit VehicleSeat(VehicleSeatEntry const *_seatInfo) : seatInfo(_seatInfo), passenger(NULL) {}
    VehicleSeatEntry const *seatInfo;
    Unit* passenger;
};

struct VehicleAccessory
{
    explicit VehicleAccessory(uint32 _uiAccessory, int8 _uiSeat, bool _bMinion) : uiAccessory(_uiAccessory), uiSeat(_uiSeat), bMinion(_bMinion) {}
    uint32 uiAccessory;
    int8 uiSeat;
    uint32 bMinion;
};

typedef std::vector<VehicleAccessory> VehicleAccessoryList;
typedef std::map<uint32, VehicleAccessoryList> VehicleAccessoryMap;

typedef std::map<int8, VehicleSeat> SeatMap;

class Vehicle
{
    public:
        explicit Vehicle(Unit *unit, VehicleEntry const *vehInfo);
        virtual ~Vehicle();

        void Install();
        void Uninstall();
        void Reset();
        void Die();
        void InstallAllAccessories();

        Unit *GetBase() const { return me; }
        VehicleEntry const *GetVehicleInfo() { return m_vehicleInfo; }

        bool HasEmptySeat(int8 seatId) const;
        Unit *GetPassenger(int8 seatId) const;
        int8 GetNextEmptySeat(int8 seatId, bool next) const;
        bool AddPassenger(Unit *passenger, int8 seatId = -1);
        void RemovePassenger(Unit *passenger);
        void RelocatePassengers(float x, float y, float z, float ang);
        void RemoveAllPassengers();
        void Dismiss();

        SeatMap m_Seats;

    protected:
        Unit *me;
        VehicleEntry const *m_vehicleInfo;
        uint32 m_usableSeatNum;

        void InstallAccessory(uint32 entry, int8 seatId, bool minion = true);
};
#endif
