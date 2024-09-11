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

// EnumUtils: DESCRIBE THIS
enum Races
{
    RACE_NONE                         = 0,  // SKIP
    RACE_HUMAN                        = 1,  // TITLE Human
    RACE_ORC                          = 2,  // TITLE Orc
    RACE_DWARF                        = 3,  // TITLE Dwarf
    RACE_NIGHTELF                     = 4,  // TITLE Night Elf
    RACE_UNDEAD_PLAYER                = 5,  // TITLE Undead
    RACE_TAUREN                       = 6,  // TITLE Tauren
    RACE_GNOME                        = 7,  // TITLE Gnome
    RACE_TROLL                        = 8,  // TITLE Troll
    RACE_GOBLIN                       = 9,  // TITLE Goblin
    RACE_BLOODELF                     = 10, // TITLE Blood Elf
    RACE_DRAENEI                      = 11, // TITLE Draenei
    //RACE_FEL_ORC                    = 12,
    //RACE_NAGA                       = 13,
    //RACE_BROKEN                     = 14,
    //RACE_SKELETON                   = 15,
    //RACE_VRYKUL                     = 16,
    //RACE_TUSKARR                    = 17,
    //RACE_FOREST_TROLL               = 18,
    //RACE_TAUNKA                     = 19,
    //RACE_NORTHREND_SKELETON         = 20,
    //RACE_ICE_TROLL                  = 21,
    RACE_WORGEN                       = 22, // TITLE Worgen
    //RACE_GILNEAN                    = 23,
    RACE_PANDAREN_NEUTRAL             = 24, // TITLE Pandaren DESCRIPTION Pandaren (Neutral)
    RACE_PANDAREN_ALLIANCE            = 25, // TITLE Pandaren DESCRIPTION Pandaren (Alliance)
    RACE_PANDAREN_HORDE               = 26, // TITLE Pandaren DESCRIPTION Pandaren (Horde)
    RACE_NIGHTBORNE                   = 27, // TITLE Nightborne
    RACE_HIGHMOUNTAIN_TAUREN          = 28, // TITLE Highmountain Tauren
    RACE_VOID_ELF                     = 29, // TITLE Void Elf
    RACE_LIGHTFORGED_DRAENEI          = 30, // TITLE Lightforged Draenei
    RACE_ZANDALARI_TROLL              = 31, // TITLE Zandalari Troll
    RACE_KUL_TIRAN                    = 32, // TITLE Kul Tiran
    //RACE_THIN_HUMAN                 = 33,
    RACE_DARK_IRON_DWARF              = 34, // TITLE Dark Iron Dwarf DESCRIPTION Dark Iron Dwarf (RaceMask bit 11)
    RACE_VULPERA                      = 35, // TITLE Vulpera DESCRIPTION Vulpera (RaceMask bit 12)
    RACE_MAGHAR_ORC                   = 36, // TITLE Mag'har Orc DESCRIPTION Mag'har Orc (RaceMask bit 13)
    RACE_MECHAGNOME                   = 37, // TITLE Mechagnome DESCRIPTION Mechagnome (RaceMask bit 14)
    RACE_DRACTHYR_ALLIANCE            = 52, // TITLE Dracthyr DESCRIPTION Dracthyr (Alliance) (RaceMask bit 16)
    RACE_DRACTHYR_HORDE               = 70, // TITLE Dracthyr DESCRIPTION Dracthyr (Horde) (RaceMask bit 15)
    //RACE_COMPANION_DRAKE            = 71,
    //RACE_COMPANION_PROTO_DRAGON     = 72,
    //RACE_COMPANION_SERPENT          = 73,
    //RACE_COMPANION_WYVERN           = 74,
    //RACE_DRACTHYR_VISAGE_ALLIANCE   = 75,
    //RACE_DRACTHYR_VISAGE_HORDE      = 76,
    //RACE_COMPANION_PTERRODAX        = 77,
    //RACE_COMPANION_NETHERWING_DRAKE = 80,
    //RACE_ROSTRUM_STORM_GRYPHON      = 82,
    //RACE_ROSTRUM_FAERIE_DRAGON      = 83,
    RACE_EARTHEN_DWARF_HORDE          = 84, // TITLE Earthen DESCRIPTION Earthen (Horde) (RaceMask bit 17)
    RACE_EARTHEN_DWARF_ALLIANCE       = 85, // TITLE Earthen DESCRIPTION Earthen (Alliance) (RaceMask bit 18)
    //RACE_HARRONIR                   = 86,
    //RACE_ROSTRUM_AIRSHIP            = 87,
};

// max+1 for player race
#define MAX_RACES                       88

namespace Trinity
{
template<typename T>
struct RaceMask
{
    static_assert(std::is_integral_v<T>, "RaceMask<T> must be integral");

    T RawValue;

    constexpr bool HasRace(uint8 raceId) const
    {
        return (RawValue & GetMaskForRace(raceId)) != 0;
    }

    static constexpr int32 GetRaceBit(uint8 raceId)
    {
        switch (raceId)
        {
            case RACE_HUMAN:
            case RACE_ORC:
            case RACE_DWARF:
            case RACE_NIGHTELF:
            case RACE_UNDEAD_PLAYER:
            case RACE_TAUREN:
            case RACE_GNOME:
            case RACE_TROLL:
            case RACE_GOBLIN:
            case RACE_BLOODELF:
            case RACE_DRAENEI:
            case RACE_WORGEN:
            case RACE_PANDAREN_NEUTRAL:
            case RACE_PANDAREN_ALLIANCE:
            case RACE_PANDAREN_HORDE:
            case RACE_NIGHTBORNE:
            case RACE_HIGHMOUNTAIN_TAUREN:
            case RACE_VOID_ELF:
            case RACE_LIGHTFORGED_DRAENEI:
            case RACE_ZANDALARI_TROLL:
            case RACE_KUL_TIRAN:
                return raceId - 1;
            case RACE_DARK_IRON_DWARF:
                return 11;
            case RACE_VULPERA:
                return 12;
            case RACE_MAGHAR_ORC:
                return 13;
            case RACE_MECHAGNOME:
                return 14;
            case RACE_DRACTHYR_ALLIANCE:
                return 16;
            case RACE_DRACTHYR_HORDE:
                return 15;
            case RACE_EARTHEN_DWARF_HORDE:
                return 17;
            case RACE_EARTHEN_DWARF_ALLIANCE:
                return 18;
            default:
                break;
        }
        return -1;
    }

    static constexpr T GetMaskForRace(uint8 raceId)
    {
        int32 raceBit = GetRaceBit(raceId);
        return raceBit >= 0 && uint32(raceBit) < sizeof(T) * 8 ? (T(1) << raceBit) : T(0);
    }

    constexpr bool IsEmpty() const { return RawValue == T(0); }

    constexpr RaceMask operator&(RaceMask right) const { return { RawValue & right.RawValue }; }
    constexpr RaceMask operator|(RaceMask right) const { return { RawValue | right.RawValue }; }
    constexpr RaceMask operator~() const { return { ~RawValue }; }
};
}

constexpr Trinity::RaceMask<uint64> RACEMASK_ALL_PLAYABLE = { std::integral_constant<uint64,
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
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_MECHAGNOME)          |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DRACTHYR_ALLIANCE)   |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DRACTHYR_HORDE)      |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_EARTHEN_DWARF_HORDE)>::value };

constexpr Trinity::RaceMask<uint64> RACEMASK_NEUTRAL = { std::integral_constant<uint64, Trinity::RaceMask<uint64>::GetMaskForRace(RACE_PANDAREN_NEUTRAL)>::value };

constexpr Trinity::RaceMask<uint64> RACEMASK_ALLIANCE = { std::integral_constant<uint64,
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
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_MECHAGNOME)          |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_DRACTHYR_ALLIANCE)   |
     Trinity::RaceMask<uint64>::GetMaskForRace(RACE_EARTHEN_DWARF_ALLIANCE)>::value };

constexpr Trinity::RaceMask<uint64> RACEMASK_HORDE = { std::integral_constant<uint64, (RACEMASK_ALL_PLAYABLE & ~(RACEMASK_NEUTRAL | RACEMASK_ALLIANCE)).RawValue>::value };

#endif // RaceMask_h__
