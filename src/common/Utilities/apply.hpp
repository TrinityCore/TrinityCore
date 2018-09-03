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
 
#ifndef TRINITY_APPLY_HPP
#define TRINITY_APPLY_HPP

#include <cstddef>
#include <tuple>
#include <utility>

namespace Trinity {
    template <typename R, typename... Ts, std::size_t... I>
    R apply_impl(R(*func)(Ts...), std::tuple<Ts...> args, std::index_sequence<I...>)
    {
        return func(std::get<I>(args)...);
    }

    template <typename R, typename... Ts>
    R apply(R(*func)(Ts...), std::tuple<Ts...> args)
    {
        return apply_impl(func, args, std::index_sequence_for<Ts...>{});
    }
}

#endif
