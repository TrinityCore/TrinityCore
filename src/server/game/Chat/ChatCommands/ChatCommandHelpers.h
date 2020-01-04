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

#ifndef TRINITY_CHATCOMMANDHELPERS_H
#define TRINITY_CHATCOMMANDHELPERS_H

#include "advstd.h"
#include <type_traits>

namespace Trinity {
namespace ChatCommands {

static constexpr char COMMAND_DELIMITER = ' ';

/***************** HELPERS *************************\
|* These really aren't for outside use...          *|
\***************************************************/
inline size_t tokenize(char const*& end)
{
    size_t len = 0;
    for (; *end && *end != COMMAND_DELIMITER; ++end, ++len);
    for (; *end && *end == COMMAND_DELIMITER; ++end);
    return len;
}

template <typename T, typename = void>
struct tag_base
{
    using type = T;
};

template <typename T>
using tag_base_t = typename tag_base<T>::type;

template <typename...>
struct are_all_assignable
{
    static constexpr bool value = true;
};

template <typename T1, typename T2, typename... Ts>
struct are_all_assignable<T1, T2, Ts...>
{
    static constexpr bool value = advstd::is_assignable_v<T1&, T2> && are_all_assignable<T1, Ts...>::value;
};

template <size_t index, typename T1, typename... Ts>
struct get_nth : get_nth<index-1, Ts...> { };

template <typename T1, typename... Ts>
struct get_nth<0, T1, Ts...>
{
    using type = T1;
};

template <size_t index, typename... Ts>
using get_nth_t = typename get_nth<index, Ts...>::type;

}}

#endif
