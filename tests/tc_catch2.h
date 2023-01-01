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

#ifndef TRINITY_CATCH2_H
#define TRINITY_CATCH2_H

#include "Optional.h"
#include <iostream>
#include <typeinfo>

template <typename T>
std::ostream& operator<<(std::ostream& os, Optional<T> const& value)
{
    os << "Opt";
    if (value)
        os << " { " << *value << " }";
    else
        os << " (<empty>)";
    return os;
}

inline std::ostream& operator<<(std::ostream& os, std::nullopt_t)
{
    os << "<empty>";
    return os;
}

#include "catch2/catch.hpp"

#endif
