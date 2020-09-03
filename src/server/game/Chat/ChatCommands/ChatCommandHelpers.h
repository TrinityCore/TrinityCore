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

#include <string_view>
#include <type_traits>

namespace Trinity::Impl::ChatCommands
{
    /***************** HELPERS *************************\
    |* These really aren't for outside use...          *|
    \***************************************************/

    static constexpr char COMMAND_DELIMITER = ' ';

    template <typename T, typename = void>
    struct tag_base
    {
        using type = T;
    };

    template <typename T>
    using tag_base_t = typename tag_base<T>::type;

    struct TokenizeResult {
        explicit operator bool() { return !token.empty(); }
        std::string_view token;
        std::string_view tail;
    };

    inline TokenizeResult tokenize(std::string_view args)
    {
        TokenizeResult result;
        if (size_t delimPos = args.find(COMMAND_DELIMITER); delimPos != std::string_view::npos)
        {
            result.token = args.substr(0, delimPos);
            if (size_t tailPos = args.find_first_not_of(COMMAND_DELIMITER, delimPos); tailPos != std::string_view::npos)
                result.tail = args.substr(tailPos);
        }
        else
            result.token = args;

        return result;
    }

    template <typename T, typename... Ts>
    struct are_all_assignable
    {
        static constexpr bool value = (std::is_assignable_v<T&, Ts> && ...);
    };

    template <typename... Ts>
    struct are_all_assignable<void, Ts...>
    {
        static constexpr bool value = false;
    };

    template <std::size_t index, typename T1, typename... Ts>
    struct get_nth : get_nth<index-1, Ts...> { };

    template <typename T1, typename... Ts>
    struct get_nth<0, T1, Ts...>
    {
        using type = T1;
    };

    template <std::size_t index, typename... Ts>
    using get_nth_t = typename get_nth<index, Ts...>::type;
}

#endif
