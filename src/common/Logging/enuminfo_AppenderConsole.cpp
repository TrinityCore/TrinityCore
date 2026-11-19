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

#include "AppenderConsole.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/********************************************************************\
|* data for enum 'ColorTypes' in 'AppenderConsole.h' auto-generated *|
\********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<ColorTypes>::ToString(ColorTypes value)
{
    switch (value)
    {
        case BLACK: return { "BLACK", "BLACK", "" };
        case RED: return { "RED", "RED", "" };
        case GREEN: return { "GREEN", "GREEN", "" };
        case BROWN: return { "BROWN", "BROWN", "" };
        case BLUE: return { "BLUE", "BLUE", "" };
        case MAGENTA: return { "MAGENTA", "MAGENTA", "" };
        case CYAN: return { "CYAN", "CYAN", "" };
        case GREY: return { "GREY", "GREY", "" };
        case YELLOW: return { "YELLOW", "YELLOW", "" };
        case LRED: return { "LRED", "LRED", "" };
        case LGREEN: return { "LGREEN", "LGREEN", "" };
        case LBLUE: return { "LBLUE", "LBLUE", "" };
        case LMAGENTA: return { "LMAGENTA", "LMAGENTA", "" };
        case LCYAN: return { "LCYAN", "LCYAN", "" };
        case WHITE: return { "WHITE", "WHITE", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ColorTypes>::Count() { return 15; }

template <>
TC_API_EXPORT ColorTypes EnumUtils<ColorTypes>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return BLACK;
        case 1: return RED;
        case 2: return GREEN;
        case 3: return BROWN;
        case 4: return BLUE;
        case 5: return MAGENTA;
        case 6: return CYAN;
        case 7: return GREY;
        case 8: return YELLOW;
        case 9: return LRED;
        case 10: return LGREEN;
        case 11: return LBLUE;
        case 12: return LMAGENTA;
        case 13: return LCYAN;
        case 14: return WHITE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ColorTypes>::ToIndex(ColorTypes value)
{
    switch (value)
    {
        case BLACK: return 0;
        case RED: return 1;
        case GREEN: return 2;
        case BROWN: return 3;
        case BLUE: return 4;
        case MAGENTA: return 5;
        case CYAN: return 6;
        case GREY: return 7;
        case YELLOW: return 8;
        case LRED: return 9;
        case LGREEN: return 10;
        case LBLUE: return 11;
        case LMAGENTA: return 12;
        case LCYAN: return 13;
        case WHITE: return 14;
        default: throw std::out_of_range("value");
    }
}
}
