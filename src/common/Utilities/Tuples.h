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

#ifndef TRINITYCORE_TUPLES_H
#define TRINITYCORE_TUPLES_H

#include <tuple>

namespace Trinity
{
    template <typename... Ts>
    constexpr bool is_tuple_v = false;

    template <typename... Ts>
    constexpr bool is_tuple_v<std::tuple<Ts...>> = true;

    template <typename... Ts>
    using is_tuple_t = std::bool_constant<is_tuple_v<Ts...>>;

    template <typename T, typename... Us>
    constexpr bool tuple_has_type_v = false;

    template <typename T, typename... Us>
    constexpr bool tuple_has_type_v<T, std::tuple<Us...>> = std::disjunction_v<std::is_same<T, Us>...>;

    template <typename T, typename... Us>
    using tuple_has_type_t = std::bool_constant<tuple_has_type_v<T, Us...>>;

    namespace Impl
    {
        template <class T, class Tuple, size_t... I>
        inline T* new_from_tuple(Tuple&& args, std::index_sequence<I...>)
        {
            return new T(std::get<I>(std::forward<Tuple>(args))...);
        }
    }

    template <class T, class Tuple>
    [[nodiscard]] inline T* new_from_tuple(Tuple&& args)
    {
        return Impl::new_from_tuple<T>(std::forward<Tuple>(args), std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<Tuple>>>{});
    }

    template <std::size_t I>
    inline constexpr auto TupleElement = []<typename Tuple>(Tuple&& tuple) constexpr -> decltype(auto) { return std::get<I>(std::forward<Tuple>(tuple)); };
}

#endif // TRINITYCORE_TUPLES_H
