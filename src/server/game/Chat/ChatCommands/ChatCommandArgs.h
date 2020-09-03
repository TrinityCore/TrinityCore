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
#include "StringConvert.h"
#include "Util.h"
#include <charconv>
#include <map>
#include <string>
#include <string_view>

struct GameTele;

namespace Trinity::Impl::ChatCommands
{

/************************** ARGUMENT HANDLERS *******************************************\
|* Define how to extract contents of a certain requested type from a string             *|
|* Must implement the following:                                                        *|
|* - TryConsume: T&, std::string_view -> Optional<std::string_view>                     *|
|*   returns nullopt if no match, otherwise tail of argument string                     *|
|*     - if nullopt is returned, state of T& is indeterminate                           *|
|*     - otherwise, T& should be initialized to the intended return value               *|
|*                                                                                      *|
\****************************************************************************************/
template <typename T, typename = void>
struct ArgInfo { static_assert(Trinity::dependant_false_v<T>, "Invalid command parameter type - see ChatCommandArgs.h for possible types"); };

// catch-all for number types
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>>>
{
    static Optional<std::string_view> TryConsume(T& val, std::string_view args)
    {
        auto [token, tail] = tokenize(args);
        if (token.empty())
            return std::nullopt;

        if (Optional<T> v = StringTo<T>(token, 0))
            val = *v;
        else
            return std::nullopt;

        if constexpr (std::is_floating_point_v<T>)
        {
            if (!std::isfinite(val))
                return std::nullopt;
        }

        return tail;
    }
};

// string_view
template <>
struct ArgInfo<std::string_view, void>
{
    static Optional<std::string_view> TryConsume(std::string_view& val, std::string_view args)
    {
        auto [token, next] = tokenize(args);
        if (token.empty())
            return std::nullopt;
        val = token;
        return next;
    }
};

// string
template <>
struct ArgInfo<std::string, void>
{
    static Optional<std::string_view> TryConsume(std::string& val, std::string_view args)
    {
        std::string_view view;
        Optional<std::string_view> next = ArgInfo<std::string_view>::TryConsume(view, args);
        if (next)
            val.assign(view);
        return next;
    }
};

// wstring
template <>
struct ArgInfo<std::wstring, void>
{
    static Optional<std::string_view> TryConsume(std::wstring& val, std::string_view args)
    {
        std::string_view utf8view;
        Optional<std::string_view> next = ArgInfo<std::string_view>::TryConsume(utf8view, args);

        if (next && Utf8toWStr(utf8view, val))
            return next;
        else
            return std::nullopt;
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

    static Optional<std::string_view> TryConsume(T& val, std::string_view args)
    {
        std::string strVal;
        Optional<std::string_view> next = ArgInfo<std::string>::TryConsume(strVal, args);

        if (next)
        {
            if (T const* match = Match(strVal))
            {
                val = *match;
                return next;
            }
        }

        // Value not found. Try to parse arg as underlying type and cast it to enum type
        using U = std::underlying_type_t<T>;
        U uVal = 0;
        next = ArgInfo<U>::TryConsume(uVal, args);
        if (next && EnumUtils::IsValid<T>(uVal))
        {
            val = static_cast<T>(uVal);
            return next;
        }

        return std::nullopt;
    }
};

// a container tag
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_base_of_v<ContainerTag, T>>>
{
    static Optional<std::string_view> TryConsume(T& tag, std::string_view args)
    {
        return tag.TryConsume(args);
    }
};

template <typename T>
struct ArgInfo<std::vector<T>, void>
{
    static Optional<std::string_view> TryConsume(std::vector<T>& val, std::string_view args)
    {
        val.clear();
        Optional<std::string_view> next = ArgInfo<T>::TryConsume(val.emplace_back(), args);

        if (!next)
            return std::nullopt;

        while (Optional<std::string_view> next2 = ArgInfo<T>::TryConsume(val.emplace_back(), *next))
            next = next2;

        val.pop_back();
        return next;
    }
};

template <typename T, size_t N>
struct ArgInfo<std::array<T, N>, void>
{
    static Optional<std::string_view> TryConsume(std::array<T, N>& val, std::string_view args)
    {
        Optional<std::string_view> next = args;
        for (T& t : val)
            if (!(next = ArgInfo<T>::TryConsume(t, *next)))
                return std::nullopt;
        return next;
    }
};

// AchievementEntry* from numeric id or link
template <>
struct TC_GAME_API ArgInfo<AchievementEntry const*>
{
    static Optional<std::string_view> TryConsume(AchievementEntry const*&, std::string_view);
};

// GameTele* from string name or link
template <>
struct TC_GAME_API ArgInfo<GameTele const*>
{
    static Optional<std::string_view> TryConsume(GameTele const*&, std::string_view);
};

// SpellInfo const* from spell id or link
template <>
struct TC_GAME_API ArgInfo<SpellInfo const*>
{
    static Optional<std::string_view> TryConsume(SpellInfo const*&, std::string_view);
};

}

#endif
