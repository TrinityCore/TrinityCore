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

#ifndef TRINITYCORE_TYPES_H
#define TRINITYCORE_TYPES_H

#include <type_traits>

namespace Trinity
{
    template <bool HasType, typename T>
    struct find_type_result
    {
        static constexpr bool has_type = HasType;
        using type = T;
    };

    template <typename T>
    struct find_type_result<false, T>
    {
        static constexpr bool has_type = false;
    };

    namespace Impl
    {
        template <template <typename> typename Check, typename T, typename... Ts>
        consteval auto find_type_in_list_if_impl()
        {
            if constexpr (Check<T>::value)
                return find_type_result<true, T>();
            else if constexpr (sizeof...(Ts) == 0)
                return find_type_result<false, void>();
            else
                return find_type_in_list_if_impl<Check, Ts...>();
        }
    }

    /*
        Utility to find a type matching predicate (Check) in a given type list (Ts)
        Evaluates to Trinity::find_type_result
        Check must be a type that contains static bool ::value, _v aliases don't work

        using Example1 = Trinity::find_type_in_list_if<Trinity::is_tuple, int, std::string, std::tuple<int, int, int>, char>;
        Example1::has_type == true; // Example1::type is Trinity::find_type_result<true, std::tuple<int, int, int>>

        using Example2 = Trinity::find_type_in_list_if<Trinity::is_tuple, int, std::string, char>;
        Example1::has_type == false; // Example2::type is not defined
    */
    template<template<typename...> typename Check, typename... Ts>
    using find_type_in_list_if = decltype(Impl::find_type_in_list_if_impl<Check, Ts...>());

    template <typename T, typename... Us>
    constexpr bool has_type_in_list_v = std::disjunction_v<std::is_same<T, Us>...>;

    template <typename T>
    struct dependant_false { static constexpr bool value = false; };

    template <typename T>
    constexpr bool dependant_false_v = dependant_false<T>::value;
}

#endif // TRINITYCORE_TYPES_H
