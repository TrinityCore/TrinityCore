/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __TRINITY_VEHICLE_H
#define __TRINITY_VEHICLE_H

#include "ObjectDefines.h"

struct VehicleEntry;
struct VehicleSeatEntry;
class Unit;

enum PowerType
{
    POWER_STEAM                                  = 61,
    POWER_PYRITE                                 = 41,
    POWER_HEAT                                   = 101,
    POWER_OOZE                                   = 121,
    POWER_BLOOD                                  = 141,
    POWER_WRATH                                  = 142
};

enum VehicleFlags
{
    VEHICLE_FLAG_ADJUST_AIM_ANGLE                = 0x00000400,           // Lua_IsVehicleAimAngleAdjustable
    VEHICLE_FLAG_ADJUST_AIM_POWER                = 0x00000800,           // Lua_IsVehicleAimPowerAdjustable
    VEHICLE_FLAG_CUSTOM_PITCH                    = 0x00000040,           // If set use pitchMin and pitchMax from DBC, otherwise pitchMin = -pi/2, pitchMax = pi/2
};

enum VehicleSeatFlags
{
    VEHICLE_SEAT_FLAG_HIDE_PASSENGER             = 0x00000200,           // Passenger is hidden
    VEHICLE_SEAT_FLAG_UNK11                      = 0x00000400,
    VEHICLE_SEAT_FLAG_CAN_CONTROL                = 0x00000800,           // Lua_UnitInVehicleControlSeat
    VEHICLE_SEAT_FLAG_CAN_ATTACK                 = 0x00004000,           // Can attack, cast spells and use items from vehicle?
    VEHICLE_SEAT_FLAG_USABLE                     = 0x02000000,           // Lua_CanExitVehicle
    VEHICLE_SEAT_FLAG_CAN_SWITCH                 = 0x04000000,           // Lua_CanSwitchVehicleSeats
    VEHICLE_SEAT_FLAG_CAN_CAST                   = 0x20000000,           // Lua_UnitHasVehicleUI
};

enum VehicleSeatFlagsB
{
    VEHICLE_SEAT_FLAG_B_NONE                     = 0x00000000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED            = 0x00000002, 
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2          = 0x00000040,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3          = 0x00000100,
};

enum VehicleSpells
{
    VEHICLE_SPELL_PARACHUTE                      = 45472
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

struct VehicleScalingInfo
{
    uint32 ID;
    float baseItemLevel;
    float scalingFactor;
};

typedef std::vector<VehicleAccessory> VehicleAccessoryList;
typedef std::map<uint32, VehicleAccessoryList> VehicleAccessoryMap;
typedef std::map<uint32, VehicleScalingInfo> VehicleScalingMap;
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
        void InstallAllAccessories(uint32 entry);

        Unit *GetBase() const { return me; }
        VehicleEntry const *GetVehicleInfo() const { return m_vehicleInfo; }

        bool HasEmptySeat(int8 seatId) const;
        Unit *GetPassenger(int8 seatId) const;
        int8 GetNextEmptySeat(int8 seatId, bool next, bool byAura = false) const;
        bool AddPassenger(Unit *passenger, int8 seatId = -1, bool byAura = false);
        void RemovePassenger(Unit *passenger);
        void RelocatePassengers(float x, float y, float z, float ang);
        void RemoveAllPassengers();
        void Dismiss();
        bool IsVehicleInUse() { return m_Seats.begin() != m_Seats.end(); }

        SeatMap m_Seats;

    protected:
        Unit *me;
        VehicleEntry const *m_vehicleInfo;
        uint32 m_usableSeatNum;         // Number of seats that match VehicleSeatEntry::UsableByPlayer, used for proper display flags
        uint32 m_bonusHP;

        void InstallAccessory(uint32 entry, int8 seatId, bool minion = true);
};
#endif
