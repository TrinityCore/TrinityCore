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

#ifndef RaceMask_h__
#define RaceMask_h__

#include "Define.h"
#include <type_traits>

enum Races
{
    RACE_NONE                   = 0,
    RACE_HUMAN                  = 1,
    RACE_ORC                    = 2,
    RACE_DWARF                  = 3,
    RACE_NIGHTELF               = 4,
    RACE_UNDEAD_PLAYER          = 5,
    RACE_TAUREN                 = 6,
    RACE_GNOME                  = 7,
    RACE_TROLL                  = 8,
    RACE_GOBLIN                 = 9,
    RACE_BLOODELF               = 10,
    RACE_DRAENEI                = 11,
    //RACE_FEL_ORC              = 12,
    //RACE_NAGA                 = 13,
    //RACE_BROKEN               = 14,
    //RACE_SKELETON             = 15,
    //RACE_VRYKUL               = 16,
    //RACE_TUSKARR              = 17,
    //RACE_FOREST_TROLL         = 18,
    //RACE_TAUNKA               = 19,
    //RACE_NORTHREND_SKELETON   = 20,
    //RACE_ICE_TROLL            = 21,
    RACE_WORGEN                 = 22,
    //RACE_GILNEAN              = 23,
    RACE_PANDAREN_NEUTRAL       = 24,
    RACE_PANDAREN_ALLIANCE      = 25,
    RACE_PANDAREN_HORDE         = 26,
    RACE_NIGHTBORNE             = 27,
    RACE_HIGHMOUNTAIN_TAUREN    = 28,
    RACE_VOID_ELF               = 29,
    RACE_LIGHTFORGED_DRAENEI    = 30,
    RACE_ZANDALARI_TROLL        = 31,
    RACE_KUL_TIRAN              = 32,
    //RACE_THIN_HUMAN           = 33,
    RACE_DARK_IRON_DWARF        = 34, // RaceMask bit 11
    RACE_VULPERA                = 35, // RaceMask bit 12
    RACE_MAGHAR_ORC             = 36, // RaceMask bit 13
    RACE_MECHAGNOME             = 37  // RaceMask bit 14
};

// max+1 for player race
#define MAX_RACES         38

namespace Trinity
{
template<typename T>
struct RaceMask
{
    static_assert(std::is_integral<T>::value, "RaceMask<T> must be integral");

    T RawValue;

    constexpr bool HasRace(uint8 raceId) const
    {
        return (RawValue & GetMaskForRace(raceId)) != 0;
    }

    static constexpr T GetMaskForRace(uint8 raceId)
    {
        constexpr int32 raceBits[MAX_RACES] =
        {
            0, 0, 1, 2, 3, 4, 5, 6, 7, 8,
            9, 10, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, 21, -1, 23, 24, 25, 26, 27, 28,
            29, 30, 31, -1, 11, 12, 13, 14
        };
        return raceId < MAX_RACES && raceBits[raceId] >= 0 && raceBits[raceId] < 64 ? (T(1) << raceBits[raceId]) : T(0);
    }

    constexpr operator bool() const { return RawValue != T(0); }
    constexpr bool operator!() const { return !operator bool(); }
};
}

constexpr uint64 RACEMASK_ALL_PLAYABLE = std::integral_constant<uint64,
    // force compile time evaluation via integral_constant
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_HUMAN)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_ORC)                 |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DWARF)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_NIGHTELF)            |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_UNDEAD_PLAYER)       |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_TAUREN)              |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_GNOME)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_TROLL)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_BLOODELF)            |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DRAENEI)             |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_GOBLIN)              |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_WORGEN)              |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_PANDAREN_NEUTRAL)    |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_PANDAREN_ALLIANCE)   |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_PANDAREN_HORDE)      |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_NIGHTBORNE)          |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_HIGHMOUNTAIN_TAUREN) |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_VOID_ELF)            |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_LIGHTFORGED_DRAENEI) |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_ZANDALARI_TROLL)     |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_KUL_TIRAN)           |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DARK_IRON_DWARF)     |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_VULPERA)             |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_MAGHAR_ORC)          |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_MECHAGNOME)>::value;

constexpr uint64 RACEMASK_NEUTRAL = std::integral_constant<uint64, Trinity::RaceMask<uint64>::GetMaskForRace(RACE_PANDAREN_NEUTRAL)>::value;

constexpr uint64 RACEMASK_ALLIANCE = std::integral_constant<uint64,
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_HUMAN)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DWARF)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_NIGHTELF)            |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_GNOME)               |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DRAENEI)             |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_WORGEN)              |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_PANDAREN_ALLIANCE)   |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_VOID_ELF)            |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_LIGHTFORGED_DRAENEI) |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_KUL_TIRAN)           |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DARK_IRON_DWARF)     |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_MECHAGNOME)>::value;

constexpr uint64 RACEMASK_HORDE = std::integral_constant<uint64, RACEMASK_ALL_PLAYABLE & ~(RACEMASK_NEUTRAL | RACEMASK_ALLIANCE)>::value;

#endif // RaceMask_h__
