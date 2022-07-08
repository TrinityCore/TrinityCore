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

#include "RaceMask.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/********************************************************\
|* data for enum 'Races' in 'RaceMask.h' auto-generated *|
\********************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<Races>::ToString(Races value)
{
    switch (value)
    {
        case RACE_HUMAN: return { "RACE_HUMAN", "Human", "" };
        case RACE_ORC: return { "RACE_ORC", "Orc", "" };
        case RACE_DWARF: return { "RACE_DWARF", "Dwarf", "" };
        case RACE_NIGHTELF: return { "RACE_NIGHTELF", "Night Elf", "" };
        case RACE_UNDEAD_PLAYER: return { "RACE_UNDEAD_PLAYER", "Undead", "" };
        case RACE_TAUREN: return { "RACE_TAUREN", "Tauren", "" };
        case RACE_GNOME: return { "RACE_GNOME", "Gnome", "" };
        case RACE_TROLL: return { "RACE_TROLL", "Troll", "" };
        case RACE_GOBLIN: return { "RACE_GOBLIN", "Goblin", "" };
        case RACE_BLOODELF: return { "RACE_BLOODELF", "Blood Elf", "" };
        case RACE_DRAENEI: return { "RACE_DRAENEI", "Draenei", "" };
        case RACE_WORGEN: return { "RACE_WORGEN", "Worgen", "" };
        case RACE_PANDAREN_NEUTRAL: return { "RACE_PANDAREN_NEUTRAL", "Pandaren", "Pandaren (Neutral)" };
        case RACE_PANDAREN_ALLIANCE: return { "RACE_PANDAREN_ALLIANCE", "Pandaren", "Pandaren (Alliance)" };
        case RACE_PANDAREN_HORDE: return { "RACE_PANDAREN_HORDE", "Pandaren", "Pandaren (Horde)" };
        case RACE_NIGHTBORNE: return { "RACE_NIGHTBORNE", "Nightborne", "" };
        case RACE_HIGHMOUNTAIN_TAUREN: return { "RACE_HIGHMOUNTAIN_TAUREN", "Highmountain Tauren", "" };
        case RACE_VOID_ELF: return { "RACE_VOID_ELF", "Void Elf", "" };
        case RACE_LIGHTFORGED_DRAENEI: return { "RACE_LIGHTFORGED_DRAENEI", "Lightforged Draenei", "" };
        case RACE_ZANDALARI_TROLL: return { "RACE_ZANDALARI_TROLL", "Zandalari Troll", "" };
        case RACE_KUL_TIRAN: return { "RACE_KUL_TIRAN", "Kul Tiran", "" };
        case RACE_DARK_IRON_DWARF: return { "RACE_DARK_IRON_DWARF", "Dark Iron Dwarf", "Dark Iron Dwarf (RaceMask bit 11)" };
        case RACE_VULPERA: return { "RACE_VULPERA", "Vulpera", "Vulpera (RaceMask bit 12)" };
        case RACE_MAGHAR_ORC: return { "RACE_MAGHAR_ORC", "Mag'har Orc", "Mag'har Orc (RaceMask bit 13)" };
        case RACE_MECHAGNOME: return { "RACE_MECHAGNOME", "Mechagnome", "Mechagnome (RaceMask bit 14)" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Races>::Count() { return 25; }

template <>
TC_API_EXPORT Races EnumUtils<Races>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return RACE_HUMAN;
        case 1: return RACE_ORC;
        case 2: return RACE_DWARF;
        case 3: return RACE_NIGHTELF;
        case 4: return RACE_UNDEAD_PLAYER;
        case 5: return RACE_TAUREN;
        case 6: return RACE_GNOME;
        case 7: return RACE_TROLL;
        case 8: return RACE_GOBLIN;
        case 9: return RACE_BLOODELF;
        case 10: return RACE_DRAENEI;
        case 11: return RACE_WORGEN;
        case 12: return RACE_PANDAREN_NEUTRAL;
        case 13: return RACE_PANDAREN_ALLIANCE;
        case 14: return RACE_PANDAREN_HORDE;
        case 15: return RACE_NIGHTBORNE;
        case 16: return RACE_HIGHMOUNTAIN_TAUREN;
        case 17: return RACE_VOID_ELF;
        case 18: return RACE_LIGHTFORGED_DRAENEI;
        case 19: return RACE_ZANDALARI_TROLL;
        case 20: return RACE_KUL_TIRAN;
        case 21: return RACE_DARK_IRON_DWARF;
        case 22: return RACE_VULPERA;
        case 23: return RACE_MAGHAR_ORC;
        case 24: return RACE_MECHAGNOME;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Races>::ToIndex(Races value)
{
    switch (value)
    {
        case RACE_HUMAN: return 0;
        case RACE_ORC: return 1;
        case RACE_DWARF: return 2;
        case RACE_NIGHTELF: return 3;
        case RACE_UNDEAD_PLAYER: return 4;
        case RACE_TAUREN: return 5;
        case RACE_GNOME: return 6;
        case RACE_TROLL: return 7;
        case RACE_GOBLIN: return 8;
        case RACE_BLOODELF: return 9;
        case RACE_DRAENEI: return 10;
        case RACE_WORGEN: return 11;
        case RACE_PANDAREN_NEUTRAL: return 12;
        case RACE_PANDAREN_ALLIANCE: return 13;
        case RACE_PANDAREN_HORDE: return 14;
        case RACE_NIGHTBORNE: return 15;
        case RACE_HIGHMOUNTAIN_TAUREN: return 16;
        case RACE_VOID_ELF: return 17;
        case RACE_LIGHTFORGED_DRAENEI: return 18;
        case RACE_ZANDALARI_TROLL: return 19;
        case RACE_KUL_TIRAN: return 20;
        case RACE_DARK_IRON_DWARF: return 21;
        case RACE_VULPERA: return 22;
        case RACE_MAGHAR_ORC: return 23;
        case RACE_MECHAGNOME: return 24;
        default: throw std::out_of_range("value");
    }
}
}
