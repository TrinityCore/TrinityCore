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

#ifndef Tuples_h__
#define Tuples_h__

#include <tuple>

namespace Trinity
{
    template <typename T, typename Tuple>
    struct has_type;

    template <typename T, typename... Us>
    struct has_type<T, std::tuple<Us...>> : std::disjunction<std::is_same<T, Us>...>
    {
    };

    template <typename T, typename... Us>
    constexpr bool has_type_v = has_type<T, Us...>::value;

    template<typename>
    struct is_tuple : std::false_type
    {
    };

    template<typename... Ts>
    struct is_tuple<std::tuple<Ts...>> : std::true_type
    {
    };

    template<typename... Ts>
    constexpr bool is_tuple_v = is_tuple<Ts...>::value;

    namespace Impl
    {
        template <class T, class Tuple, size_t... I>
        T* new_from_tuple(Tuple&& args, std::index_sequence<I...>)
        {
            return new T(std::get<I>(std::forward<Tuple>(args))...);
        }
    }

    template<class T, class Tuple>
    [[nodiscard]] T* new_from_tuple(Tuple&& args)
    {
        return Impl::new_from_tuple<T>(std::forward<Tuple>(args), std::make_index_sequence<std::tuple_size_v<std::remove_reference_t<Tuple>>>{});
    }
}

#endif // Tuples_h__
