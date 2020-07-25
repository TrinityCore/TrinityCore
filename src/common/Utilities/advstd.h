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

#include <cstddef>
#include <initializer_list>
#include <type_traits>

// this namespace holds implementations of upcoming stdlib features that our c++ version doesn't have yet
namespace advstd
{
    // C++17 std::size
    template <typename C>
    constexpr auto size(const C& c) { return c.size(); }

    template <typename T, std::size_t N>
    constexpr std::size_t size(const T(&)[N]) noexcept { return N; }

    // C++17 std::data
    template <typename C>
    constexpr auto data(C& c) { return c.data(); }

    template <typename C>
    constexpr auto data(C const& c) { return c.data(); }

    template <typename T, std::size_t N>
    constexpr T* data(T(&a)[N]) noexcept { return a; }

    template <typename T, std::size_t N>
    constexpr T const* data(const T(&a)[N]) noexcept { return a; }

    template <typename T>
    constexpr T const* data(std::initializer_list<T> l) noexcept { return l.begin(); }
}

#endif
