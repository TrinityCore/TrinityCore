/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include <tuple>
#include <type_traits>
#include <utility>

// this namespace holds implementations of upcoming stdlib features that our c++ version doesn't have yet
namespace advstd
{
    // C++17 std::apply (constrained to only function pointers, not all callable)
    template <typename... Ts>
    using apply_tuple_type = std::tuple<std::remove_cv_t<std::remove_reference_t<Ts>>...>;
    template <typename R, typename... Ts, std::size_t... I>
    R apply_impl(R(*func)(Ts...), apply_tuple_type<Ts...>&& args, std::index_sequence<I...>)
    {
        return func(std::get<I>(std::forward<apply_tuple_type<Ts...>>(args))...);
    }
    template <typename R, typename... Ts>
    R apply(R(*func)(Ts...), apply_tuple_type<Ts...>&& args)
    {
        return apply_impl(func, std::forward<apply_tuple_type<Ts...>>(args), std::index_sequence_for<Ts...>{});
    }

#define forward_1v(stdname, type) template <typename T> constexpr type stdname ## _v = std::stdname<T>::value
#define forward_2v(stdname, type) template <typename U, typename V> constexpr type stdname ## _v = std::stdname<U,V>::value

    // C++17 std::is_same_v
    forward_2v(is_same, bool);

    // C++17 std::is_integral_v
    forward_1v(is_integral, bool);

    // C++17 std::is_assignable_v
    forward_2v(is_assignable, bool);

    // C++17 std::is_signed_v
    forward_1v(is_signed, bool);

    // C++17 std::is_unsigned_v
    forward_1v(is_unsigned, bool);

    // C++17 std::is_base_of_v
    forward_2v(is_base_of, bool);

    // C++17 std::is_floating_point_v
    forward_1v(is_floating_point, bool);

    // C++17 std::is_pointer_v
    forward_1v(is_pointer, bool);

    // C++17 std::is_reference_v
    forward_1v(is_reference, bool);

    // C++17 std::tuple_size_v
    forward_1v(tuple_size, size_t);

    // C++17 std::is_enum_v
    forward_1v(is_enum, bool);

    // C++17 std::is_arithmetic_v
    forward_1v(is_arithmetic, bool);

#undef forward_1v
#undef forward_2v

    // C++17 std::size
    template <class C>
    constexpr auto size(const C& c) -> decltype(c.size()) { return c.size(); }

    template <class T, std::size_t N>
    constexpr std::size_t size(const T(&)[N]) noexcept { return N; }

    // C++20 std::remove_cvref_t
    template <class T>
    using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;
}

#endif
