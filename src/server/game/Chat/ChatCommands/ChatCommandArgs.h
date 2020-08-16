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
#include "SmartEnum.h"
#include "Util.h"
#include <map>

struct GameTele;

namespace Trinity
{
namespace ChatCommands
{

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
struct ArgInfo { static_assert(!std::is_same_v<T,T>, "Invalid command parameter type - see ChatCommandArgs.h for possible types"); };

// catch-all for signed integral types
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>>>
{
    static char const* TryConsume(T& val, char const* args)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try
        {
            size_t processedChars = 0;
            val = std::stoll(token, &processedChars, 0);
            if (processedChars != token.length())
                return nullptr;
        }
        catch (...) { return nullptr; }
        return next;
    }
};

// catch-all for unsigned integral types
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>>>
{
    static char const* TryConsume(T& val, char const* args)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try
        {
            size_t processedChars = 0;
            val = std::stoull(token, &processedChars, 0);
            if (processedChars != token.length())
                return nullptr;
        }
        catch (...) { return nullptr; }
        return next;
    }
};

// catch-all for floating point types
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_floating_point_v<T>>>
{
    static char const* TryConsume(T& val, char const* args)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try
        {
            size_t processedChars = 0;
            val = std::stold(token, &processedChars);
            if (processedChars != token.length())
                return nullptr;
        }
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

// enum
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_enum_v<T>>>
{
    static std::map<std::string, Optional<T>> MakeSearchMap()
    {
        std::map<std::string, Optional<T>> map;
        for (T val : EnumUtils::Iterate<T>())
        {
            EnumText text = EnumUtils::ToString(val);

            std::string title(text.Title);
            strToLower(title);
            std::string constant(text.Constant);
            strToLower(constant);

            auto [constantIt, constantNew] = map.try_emplace(constant, val);
            if (!constantNew)
                constantIt->second = std::nullopt;

            if (title != constant)
            {
                auto [titleIt, titleNew] = map.try_emplace(title, val);
                if (!titleNew)
                    titleIt->second = std::nullopt;
            }
        }
        return map;
    }

    static inline std::map<std::string, Optional<T>> const SearchMap = MakeSearchMap();

    static T const* Match(std::string s)
    {
        strToLower(s);

        auto it = SearchMap.lower_bound(s);
        if (it == SearchMap.end() || !StringStartsWith(it->first, s)) // not a match
            return nullptr;

        if (it->first != s) // we don't have an exact match - check if it is unique
        {
            auto it2 = it;
            ++it2;
            if (it2 != SearchMap.end() && StringStartsWith(it2->first, s)) // not unique
                return nullptr;
        }

        if (it->second)
            return &*it->second;
        else
            return nullptr;
    }

    static char const* TryConsume(T& val, char const* args)
    {
        std::string strVal;
        char const* ret = ArgInfo<std::string>::TryConsume(strVal, args);

        if (!ret)
            return nullptr;

        if (T const* tmpVal = Match(strVal))
        {
            val = *tmpVal;
            return ret;
        }

        // Value not found. Try to parse arg as underlying type and cast it to enum type
        using U = std::underlying_type_t<T>;
        U uVal = 0;
        ret = ArgInfo<U>::TryConsume(uVal, args);
        if (ret)
            val = static_cast<T>(uVal);

        return ret;
    }
};

// a container tag
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_base_of_v<ContainerTag, T>>>
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

// CurrencyTypesEntry* from numeric id or link
template <>
struct TC_GAME_API ArgInfo<CurrencyTypesEntry const*>
{
    static char const* TryConsume(CurrencyTypesEntry const*&, char const*);
};

// GameTele* from string name or link
template <>
struct TC_GAME_API ArgInfo<GameTele const*>
{
    static char const* TryConsume(GameTele const*&, char const*);
};

// SpellInfo const* from spell id or link
template <>
struct TC_GAME_API ArgInfo<SpellInfo const*>
{
    static char const* TryConsume(SpellInfo const*&, char const*);
};

// bool from 1/0 or on/off
template <>
struct TC_GAME_API ArgInfo<bool>
{
    static char const* TryConsume(bool&, char const*);
};

}
}

#endif
