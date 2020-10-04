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
#include "StringFormat.h"
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
    |* - TryConsume: T&, ChatHandler const*, std::string_view -> ChatCommandResult          *|
    |*   - on match, returns tail of the provided argument string (as std::string_view)     *|
    |*   - on specific error, returns error message (as std::string&& or char const*)       *|
    |*   - on generic error, returns std::nullopt (this will print command usage)           *|
    |*                                                                                      *|
    |*   - if a match is returned, T& should be initialized to the matched value            *|
    |*   - otherwise, the state of T& is indeterminate and caller will not use it           *|
    |*                                                                                      *|
    \****************************************************************************************/
    template <typename T, typename = void>
    struct ArgInfo { static_assert(Trinity::dependant_false_v<T>, "Invalid command parameter type - see ChatCommandArgs.h for possible types"); };

    // catch-all for number types
    template <typename T>
    struct ArgInfo<T, std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>>>
    {
        static ChatCommandResult TryConsume(T& val, ChatHandler const* handler, std::string_view args)
        {
            auto [token, tail] = tokenize(args);
            if (token.empty())
                return std::nullopt;

            if (Optional<T> v = StringTo<T>(token, 0))
                val = *v;
            else
                return FormatTrinityString(handler, LANG_CMDPARSER_STRING_VALUE_INVALID, STRING_VIEW_FMT_ARG(token), GetTypeName<T>().c_str());

            if constexpr (std::is_floating_point_v<T>)
            {
                if (!std::isfinite(val))
                    return FormatTrinityString(handler, LANG_CMDPARSER_STRING_VALUE_INVALID, STRING_VIEW_FMT_ARG(token), GetTypeName<T>().c_str());
            }

            return tail;
        }
    };

    // string_view
    template <>
    struct ArgInfo<std::string_view, void>
    {
        static ChatCommandResult TryConsume(std::string_view& val, ChatHandler const*, std::string_view args)
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
        static ChatCommandResult TryConsume(std::string& val, ChatHandler const* handler, std::string_view args)
        {
            std::string_view view;
            ChatCommandResult next = ArgInfo<std::string_view>::TryConsume(view, handler, args);
            if (next)
                val.assign(view);
            return next;
        }
    };

    // wstring
    template <>
    struct ArgInfo<std::wstring, void>
    {
        static ChatCommandResult TryConsume(std::wstring& val, ChatHandler const* handler, std::string_view args)
        {
            std::string_view utf8view;
            ChatCommandResult next = ArgInfo<std::string_view>::TryConsume(utf8view, handler, args);

            if (next)
            {
                if (Utf8toWStr(utf8view, val))
                    return next;
                else
                    return GetTrinityString(handler, LANG_CMDPARSER_INVALID_UTF8);
            }
            else
                return std::nullopt;
        }
    };

    // enum
    template <typename T>
    struct ArgInfo<T, std::enable_if_t<std::is_enum_v<T>>>
    {
        using SearchMap = std::map<std::string_view, Optional<T>, StringCompareLessI_T>;
        static SearchMap MakeSearchMap()
        {
            SearchMap map;
            for (T val : EnumUtils::Iterate<T>())
            {
                EnumText text = EnumUtils::ToString(val);

                std::string_view title(text.Title);
                std::string_view constant(text.Constant);

                auto [constantIt, constantNew] = map.try_emplace(title, val);
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

        static inline SearchMap const _map = MakeSearchMap();

        static T const* Match(std::string_view s)
        {
            auto it = _map.lower_bound(s);
            if (it == _map.end() || !StringStartsWithI(it->first, s)) // not a match
                return nullptr;

            if (!StringEqualI(it->first, s)) // we don't have an exact match - check if it is unique
            {
                auto it2 = it;
                ++it2;
                if ((it2 != _map.end()) && StringStartsWithI(it2->first, s)) // not unique
                    return nullptr;
            }

            if (it->second)
                return &*it->second;
            else
                return nullptr;
        }

        static ChatCommandResult TryConsume(T& val, ChatHandler const* handler, std::string_view args)
        {
            std::string_view strVal;
            ChatCommandResult next1 = ArgInfo<std::string_view>::TryConsume(strVal, handler, args);
            if (next1)
            {
                if (T const* match = Match(strVal))
                {
                    val = *match;
                    return next1;
                }
            }

            // Value not found. Try to parse arg as underlying type and cast it to enum type
            using U = std::underlying_type_t<T>;
            U uVal = 0;
            if (ChatCommandResult next2 = ArgInfo<U>::TryConsume(uVal, handler, args))
            {
                if (EnumUtils::IsValid<T>(uVal))
                {
                    val = static_cast<T>(uVal);
                    return next2;
                }
            }

            if (next1)
                return FormatTrinityString(handler, LANG_CMDPARSER_STRING_VALUE_INVALID, STRING_VIEW_FMT_ARG(strVal), GetTypeName<T>().c_str());
            else
                return next1;
        }
    };

    // a container tag
    template <typename T>
    struct ArgInfo<T, std::enable_if_t<std::is_base_of_v<ContainerTag, T>>>
    {
        static ChatCommandResult TryConsume(T& tag, ChatHandler const* handler, std::string_view args)
        {
            return tag.TryConsume(handler, args);
        }
    };

    // non-empty vector
    template <typename T>
    struct ArgInfo<std::vector<T>, void>
    {
        static ChatCommandResult TryConsume(std::vector<T>& val, ChatHandler const* handler, std::string_view args)
        {
            val.clear();
            ChatCommandResult next = ArgInfo<T>::TryConsume(val.emplace_back(), handler, args);

            if (!next)
                return next;

            while (ChatCommandResult next2 = ArgInfo<T>::TryConsume(val.emplace_back(), handler, *next))
                next = std::move(next2);

            val.pop_back();
            return next;
        }
    };

    // fixed-size array
    template <typename T, size_t N>
    struct ArgInfo<std::array<T, N>, void>
    {
        static ChatCommandResult TryConsume(std::array<T, N>& val, ChatHandler const* handler, std::string_view args)
        {
            ChatCommandResult next = args;
            for (T& t : val)
                if (!(next = ArgInfo<T>::TryConsume(t, handler, *next)))
                    break;
            return next;
        }
    };

    // variant
    template <typename... Ts>
    struct ArgInfo<Trinity::ChatCommands::Variant<Ts...>>
    {
        using V = std::variant<Ts...>;
        static constexpr size_t N = std::variant_size_v<V>;

        template <size_t I>
        static ChatCommandResult TryAtIndex([[maybe_unused]] Trinity::ChatCommands::Variant<Ts...>& val, [[maybe_unused]] ChatHandler const* handler, [[maybe_unused]] std::string_view args)
        {
            if constexpr (I < N)
            {
                ChatCommandResult thisResult = ArgInfo<std::variant_alternative_t<I, V>>::TryConsume(val.template emplace<I>(), handler, args);
                if (thisResult)
                    return thisResult;
                else
                {
                    ChatCommandResult nestedResult = TryAtIndex<I + 1>(val, handler, args);
                    if (nestedResult || !thisResult.HasErrorMessage())
                        return nestedResult;
                    if (!nestedResult.HasErrorMessage())
                        return thisResult;
                    if (StringStartsWith(nestedResult.GetErrorMessage(), "\""))
                        return Trinity::StringFormat("\"%s\"\n%s %s", thisResult.GetErrorMessage().c_str(), GetTrinityString(handler, LANG_CMDPARSER_OR), nestedResult.GetErrorMessage().c_str());
                    else
                        return Trinity::StringFormat("\"%s\"\n%s \"%s\"", thisResult.GetErrorMessage().c_str(), GetTrinityString(handler, LANG_CMDPARSER_OR), nestedResult.GetErrorMessage().c_str());
                }
            }
            else
                return std::nullopt;
        }

        static ChatCommandResult TryConsume(Trinity::ChatCommands::Variant<Ts...>& val, ChatHandler const* handler, std::string_view args)
        {
            ChatCommandResult result = TryAtIndex<0>(val, handler, args);
            if (result.HasErrorMessage() && (result.GetErrorMessage().find('\n') != std::string::npos))
                return Trinity::StringFormat("%s %s", GetTrinityString(handler, LANG_CMDPARSER_EITHER), result.GetErrorMessage().c_str());
            return result;
        }
    };

    // AchievementEntry* from numeric id or link
    template <>
    struct TC_GAME_API ArgInfo<AchievementEntry const*>
    {
        static ChatCommandResult TryConsume(AchievementEntry const*&, ChatHandler const*, std::string_view);
    };

    // GameTele* from string name or link
    template <>
    struct TC_GAME_API ArgInfo<GameTele const*>
    {
        static ChatCommandResult TryConsume(GameTele const*&, ChatHandler const*, std::string_view);
    };

    // ItemTemplate* from numeric id or link
    template <>
    struct TC_GAME_API ArgInfo<ItemTemplate const*>
    {
        static ChatCommandResult TryConsume(ItemTemplate const*&, ChatHandler const*, std::string_view);
    };

    // SpellInfo const* from spell id or link
    template <>
    struct TC_GAME_API ArgInfo<SpellInfo const*>
    {
        static ChatCommandResult TryConsume(SpellInfo const*&, ChatHandler const*, std::string_view);
    };

}

#endif
