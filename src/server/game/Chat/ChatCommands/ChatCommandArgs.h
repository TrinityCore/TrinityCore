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

#ifndef TRINITY_CHATCOMMANDARGS_H
#define TRINITY_CHATCOMMANDARGS_H

#include "ChatCommandHelpers.h"
#include "ChatCommandTags.h"
#include "ChatCommandHyperlinks.h"

struct GameTele;

namespace Trinity {
namespace ChatCommands {

/************************** ARGUMENT HANDLERS *******************************************\
|* Define how to extract contents of a certain requested type from a string             *|
|* Must implement the following:                                                        *|
|* - TryConsume: T&, char const* -> char const*                                         *|
|*   returns nullptr if no match, otherwise pointer to first character of next token    *|
|*     - if nullptr is returned, state of T& is indeterminate                           *|
|*     - otherwise, T& should be initialized to the intended return value               *|
|*                                                                                      *|
\****************************************************************************************/
template <typename T, typename = void>
struct ArgInfo { static_assert(!advstd::is_same_v<T,T>, "Invalid command parameter type - see ChatCommandArgs.h for possible types"); };

// catch-all for signed integral types
template <typename T>
struct ArgInfo<T, std::enable_if_t<advstd::is_integral_v<T> && advstd::is_signed_v<T>>>
{
    static char const* TryConsume(T& val, char const* args)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try { val = std::stoll(token); }
        catch (...) { return nullptr; }
        return next;
    }
};

// catch-all for unsigned integral types
template <typename T>
struct ArgInfo<T, std::enable_if_t<advstd::is_integral_v<T> && advstd::is_unsigned_v<T>>>
{
    static char const* TryConsume(T& val, char const* args)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try { val = std::stoull(token); }
        catch (...) { return nullptr; }
        return next;
    }
};

// catch-all for floating point types
template <typename T>
struct ArgInfo<T, std::enable_if_t<advstd::is_floating_point_v<T>>>
{
    static char const* TryConsume(T& val, char const* args)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try { val = std::stold(token); }
        catch (...) { return nullptr; }
        return std::isfinite(val) ? next : nullptr;
    }
};

// string
template <>
struct ArgInfo<std::string, void>
{
    static char const* TryConsume(std::string& val, char const* args)
    {
        char const* next = args;
        if (size_t len = tokenize(next))
        {
            val.assign(args, len);
            return next;
        }
        else
            return nullptr;
    }
};

// a container tag
template <typename T>
struct ArgInfo<T, std::enable_if_t<advstd::is_base_of_v<ContainerTag, T>>>
{
    static char const* TryConsume(T& tag, char const* args)
    {
        return tag.TryConsume(args);
    }
};

// AchievementEntry* from numeric id or link
template <>
struct TC_GAME_API ArgInfo<AchievementEntry const*>
{
    static char const* TryConsume(AchievementEntry const*&, char const*);
};

// GameTele* from string name or link
template <>
struct TC_GAME_API ArgInfo<GameTele const*>
{
    static char const* TryConsume(GameTele const*&, char const*);
};

// bool from 1/0 or on/off
template <>
struct TC_GAME_API ArgInfo<bool>
{
    static char const* TryConsume(bool&, char const*);
};

}}

#endif
