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

#ifndef TRINITY_ADVSTD_H
#define TRINITY_ADVSTD_H

#include <version>

#ifdef __cpp_lib_bit_cast
#include <bit>
#else
#include <cstring> // for memcpy
#endif
#include <compare>

// this namespace holds implementations of upcoming stdlib features that our c++ version doesn't have yet
namespace advstd
{
// libc++ is missing these two
[[nodiscard]] constexpr bool is_eq(std::partial_ordering cmp) noexcept { return cmp == 0; }
[[nodiscard]] constexpr bool is_neq(std::partial_ordering cmp) noexcept { return cmp != 0; }

#ifdef __cpp_lib_bit_cast
using std::bit_cast;
#else
// libstdc++ v10 is missing this
template <typename To, typename From,
    std::enable_if_t<std::conjunction_v<
        std::bool_constant<sizeof(To) == sizeof(From)>,
        std::is_trivially_copyable<To>,
        std::is_trivially_copyable<From>>, int> = 0>
[[nodiscard]] constexpr To bit_cast(From const& from) noexcept
{
    To to;
    std::memcpy(&to, &from, sizeof(To));
    return to;
}
#endif
}

#endif
