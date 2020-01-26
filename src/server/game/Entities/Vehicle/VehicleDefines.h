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

#ifndef __TRINITY_VEHICLEDEFINES_H
#define __TRINITY_VEHICLEDEFINES_H

#include "Define.h"
#include <vector>
#include <map>

struct VehicleSeatEntry;

enum PowerType
{
    POWER_STEAM                                  = 61,
    POWER_PYRITE                                 = 41,
    POWER_HEAT                                   = 101,
    POWER_OOZE                                   = 121,
    POWER_BLOOD                                  = 141,
    POWER_WRATH                                  = 142,
    POWER_ARCANE_ENERGY                          = 143,
    POWER_LIFE_ENERGY                            = 144,
    POWER_SUN_ENERGY                             = 145,
    POWER_SWING_VELOCITY                         = 146,
    POWER_SHADOWFLAME_ENERGY                     = 147,
    POWER_BLUE_POWER                             = 148,
    POWER_PURPLE_POWER                           = 149,
    POWER_GREEN_POWER                            = 150,
    POWER_ORANGE_POWER                           = 151,
    POWER_ENERGY_2                               = 153,
    POWER_ARCANEENERGY                           = 161,
    POWER_WIND_POWER_1                           = 162,
    POWER_WIND_POWER_2                           = 163,
    POWER_WIND_POWER_3                           = 164,
    POWER_FUEL                                   = 165,
    POWER_SUN_POWER                              = 166,
    POWER_TWILIGHT_ENERGY                        = 169,
    POWER_VENOM                                  = 174,
    POWER_ORANGE_POWER_2                         = 176,
    POWER_CONSUMING_FLAME                        = 177,
    POWER_PYROCLASTIC_FRENZY                     = 178,
    POWER_FLASHFIRE                              = 179,
};

enum VehicleFlags
{
    VEHICLE_FLAG_NO_STRAFE                       = 0x00000001,           // Sets MOVEFLAG2_NO_STRAFE
    VEHICLE_FLAG_NO_JUMPING                      = 0x00000002,           // Sets MOVEFLAG2_NO_JUMPING
    VEHICLE_FLAG_FULLSPEEDTURNING                = 0x00000004,           // Sets MOVEFLAG2_FULLSPEEDTURNING
    VEHICLE_FLAG_ALLOW_PITCHING                  = 0x00000010,           // Sets MOVEFLAG2_ALLOW_PITCHING
    VEHICLE_FLAG_FULLSPEEDPITCHING               = 0x00000020,           // Sets MOVEFLAG2_FULLSPEEDPITCHING
    VEHICLE_FLAG_CUSTOM_PITCH                    = 0x00000040,           // If set use pitchMin and pitchMax from DBC, otherwise pitchMin = -pi/2, pitchMax = pi/2
    VEHICLE_FLAG_ADJUST_AIM_ANGLE                = 0x00000400,           // Lua_IsVehicleAimAngleAdjustable
    VEHICLE_FLAG_ADJUST_AIM_POWER                = 0x00000800,           // Lua_IsVehicleAimPowerAdjustable
    VEHICLE_FLAG_FIXED_POSITION                  = 0x00200000            // Used for cannons, when they should be rooted
};

enum VehicleSpells
{
    VEHICLE_SPELL_RIDE_HARDCODED                 = 46598,
    VEHICLE_SPELL_PARACHUTE                      = 45472
};

struct PassengerInfo
{
    ObjectGuid Guid;
    bool IsUnselectable;
    bool IsGravityDisabled;

    void Reset()
    {
        Guid.Clear();
        IsUnselectable = false;
        IsGravityDisabled = false;
    }
};

struct VehicleSeat
{
    explicit VehicleSeat(VehicleSeatEntry const* seatInfo) : SeatInfo(seatInfo)
    {
        Passenger.Reset();
    }

    bool IsEmpty() const { return Passenger.Guid.IsEmpty(); }

    VehicleSeatEntry const* SeatInfo;
    PassengerInfo Passenger;
};

struct VehicleAccessory
{
    VehicleAccessory(uint32 entry, int8 seatId, bool isMinion, uint8 summonType, uint32 summonTime) :
        AccessoryEntry(entry), IsMinion(isMinion), SummonTime(summonTime), SeatId(seatId), SummonedType(summonType) { }
    uint32 AccessoryEntry;
    bool IsMinion;
    uint32 SummonTime;
    int8 SeatId;
    uint8 SummonedType;
};

typedef std::vector<VehicleAccessory> VehicleAccessoryList;
typedef std::map<ObjectGuid::LowType, VehicleAccessoryList> VehicleAccessoryContainer;
typedef std::map<uint32, VehicleAccessoryList> VehicleAccessoryTemplateContainer;
typedef std::map<int8, VehicleSeat> SeatMap;

class TransportBase
{
protected:
    TransportBase() { }
    virtual ~TransportBase() { }

public:
    /// This method transforms supplied transport offsets into global coordinates
    virtual void CalculatePassengerPosition(float& x, float& y, float& z, float* o = NULL) const = 0;

    /// This method transforms supplied global coordinates into local offsets
    virtual void CalculatePassengerOffset(float& x, float& y, float& z, float* o = NULL) const = 0;

    static void CalculatePassengerPosition(float& x, float& y, float& z, float* o, float transX, float transY, float transZ, float transO)
    {
        float inx = x, iny = y, inz = z;
        if (o)
            *o = Position::NormalizeOrientation(transO + *o);

        x = transX + inx * std::cos(transO) - iny * std::sin(transO);
        y = transY + iny * std::cos(transO) + inx * std::sin(transO);
        z = transZ + inz;
    }

    static void CalculatePassengerOffset(float& x, float& y, float& z, float* o, float transX, float transY, float transZ, float transO)
    {
        if (o)
            *o = Position::NormalizeOrientation(*o - transO);

        z -= transZ;
        y -= transY;    // y = searchedY * std::cos(o) + searchedX * std::sin(o)
        x -= transX;    // x = searchedX * std::cos(o) + searchedY * std::sin(o + pi)
        float inx = x, iny = y;
        y = (iny - inx * std::tan(transO)) / (std::cos(transO) + std::sin(transO) * std::tan(transO));
        x = (inx + iny * std::tan(transO)) / (std::cos(transO) + std::sin(transO) * std::tan(transO));
    }
};

#endif
