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
#include <type_traits>

// this namespace holds implementations of upcoming stdlib features that our c++ version doesn't have yet
namespace advstd
{
    // C++20 advstd::remove_cvref_t
    template <class T>
    using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

    // C++20 std::type_identity
    template <typename T>
    struct type_identity
    {
        using type = T;
    };

    // C++20 std::type_identity_t
    template <typename T>
    using type_identity_t = typename type_identity<T>::type;
}

#endif
