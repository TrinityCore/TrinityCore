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
#include "EnumFlag.h"
#include "SmartEnum.h"
#include "StringConvert.h"
#include "StringFormat.h"
#include "Util.h"
#include <string>
#include <string_view>
#include <vector>

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
    template <typename T>
    struct ArgInfo { static_assert(Trinity::dependant_false_v<T>, "Invalid command parameter type - see ChatCommandArgs.h for possible types"); };

    TC_GAME_API void InvalidStringValueFormatError(ChatCommandResult& result, ChatHandler const* handler, std::string_view arg, std::type_info const& type) noexcept;

    // catch-all for number types
    template <typename T> requires std::is_arithmetic_v<T>
    struct ArgInfo<T>
    {
        static ChatCommandResult TryConsume(T& val, ChatHandler const* handler, std::string_view args) noexcept
        {
            auto [token, tail] = tokenize(args);
            ChatCommandResult result = std::nullopt;
            if (token.empty())
                return result;

            Optional<T> v = StringTo<T>(token, 0);
            if (!v)
            {
                InvalidStringValueFormatError(result, handler, token, typeid(T));
                return result;
            }

            if constexpr (std::is_floating_point_v<T>)
            {
                if (!std::isfinite(val))
                {
                    InvalidStringValueFormatError(result, handler, token, typeid(T));
                    return result;
                }
            }

            val = *v;
            result = tail;

            return result;
        }
    };

    // string_view
    template <>
    struct ArgInfo<std::string_view>
    {
        static ChatCommandResult TryConsume(std::string_view& val, ChatHandler const*, std::string_view args) noexcept
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
    struct ArgInfo<std::string>
    {
        static ChatCommandResult TryConsume(std::string& val, ChatHandler const* handler, std::string_view args) noexcept
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
    struct ArgInfo<std::wstring>
    {
        static ChatCommandResult TryConsume(std::wstring& val, ChatHandler const* handler, std::string_view args) noexcept
        {
            std::string_view utf8view;
            ChatCommandResult next = ArgInfo<std::string_view>::TryConsume(utf8view, handler, args);

            if (next)
            {
                if (!Utf8toWStr(utf8view, val))
                    next = GetTrinityString(handler, LANG_CMDPARSER_INVALID_UTF8);
            }
            else
                next = std::nullopt;

            return next;
        }
    };

    // enum
    struct TC_GAME_API EnumArgInfoBase
    {
        using SearchMap = std::vector<std::pair<std::string_view, Optional<int64>>>;

        static void AddSearchMapEntry(SearchMap& map, int64 val, EnumText const& text) noexcept;

        static int64 const* Match(SearchMap const& map, std::string_view s) noexcept;
    };

    template <typename T> requires std::is_enum_v<T>
    struct ArgInfo<T> : EnumArgInfoBase
    {
        static SearchMap MakeSearchMap() noexcept
        {
            SearchMap map;
            for (T val : EnumUtils::Iterate<T>())
                EnumArgInfoBase::AddSearchMapEntry(map, int64(val), EnumUtils::ToString(val));

            return map;
        }

        static inline SearchMap const _map = MakeSearchMap();

        static ChatCommandResult TryConsume(T& val, ChatHandler const* handler, std::string_view args) noexcept
        {
            std::string_view strVal;
            ChatCommandResult next1 = ArgInfo<std::string_view>::TryConsume(strVal, handler, args);
            if (next1)
            {
                if (int64 const* match = Match(_map, strVal))
                {
                    val = static_cast<T>(*match);
                    return next1;
                }
            }

            // Value not found. Try to parse arg as underlying type and cast it to enum type
            do
            {
                using U = std::underlying_type_t<T>;
                U uVal = 0;
                if (ChatCommandResult next2 = ArgInfo<U>::TryConsume(uVal, handler, args))
                {
                    // validate numeric value only if its not a flag to allow combined flags
                    if constexpr (!EnumTraits::IsFlag<T>::value)
                        if (!EnumUtils::IsValid<T>(uVal))
                            break;

                    val = static_cast<T>(uVal);
                    next1 = *next2;
                    return next1;
                }
            } while (false);

            // We successfully parsed a token but it couldn't be converted to enum - replace it with error
            if (next1)
                InvalidStringValueFormatError(next1, handler, strVal, typeid(T));

            return next1;
        }
    };

    // a container tag
    template <typename T> requires std::is_base_of_v<ContainerTag, T>
    struct ArgInfo<T>
    {
        static ChatCommandResult TryConsume(T& tag, ChatHandler const* handler, std::string_view args) noexcept
        {
            return tag.TryConsume(handler, args);
        }
    };

    // non-empty vector
    template <typename T>
    struct ArgInfo<std::vector<T>>
    {
        static ChatCommandResult TryConsume(std::vector<T>& val, ChatHandler const* handler, std::string_view args) noexcept
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
    struct ArgInfo<std::array<T, N>>
    {
        static ChatCommandResult TryConsume(std::array<T, N>& val, ChatHandler const* handler, std::string_view args) noexcept
        {
            ChatCommandResult next = args;
            for (T& t : val)
                if (!(next = ArgInfo<T>::TryConsume(t, handler, *next)))
                    break;
            return next;
        }
    };

    // variant
    TC_GAME_API bool HandleVariantChatCommandConsumeResults(ChatCommandResult& combined, ChatCommandResult&& current, ChatHandler const* handler) noexcept;
    TC_GAME_API void PrefixVariantChatCommandError(ChatCommandResult& combined, ChatHandler const* handler) noexcept;

    template <typename... Ts>
    struct ArgInfo<Trinity::ChatCommands::Variant<Ts...>>
    {
        using Variant = std::variant<Ts...>;

        template <std::size_t... I>
        inline static bool TryConsume(ChatCommandResult& result, Variant& val, ChatHandler const* handler, std::string_view args, std::index_sequence<I...>) noexcept
        {
            return (HandleVariantChatCommandConsumeResults(result, ArgInfo<std::variant_alternative_t<I, Variant>>::TryConsume(val.template emplace<I>(), handler, args), handler) || ...);
        }

        static ChatCommandResult TryConsume(Trinity::ChatCommands::Variant<Ts...>& val, ChatHandler const* handler, std::string_view args) noexcept
        {
            ChatCommandResult result = std::nullopt;
            if (!TryConsume(result, val, handler, args, std::index_sequence_for<Ts...>()))
                PrefixVariantChatCommandError(result, handler);
            return result;
        }
    };

    // AchievementEntry* from numeric id or link
    template <>
    struct TC_GAME_API ArgInfo<AchievementEntry const*>
    {
        static ChatCommandResult TryConsume(AchievementEntry const*&, ChatHandler const*, std::string_view) noexcept;
    };

    // CurrencyTypesEntry* from numeric id or link
    template <>
    struct TC_GAME_API ArgInfo<CurrencyTypesEntry const*>
    {
        static ChatCommandResult TryConsume(CurrencyTypesEntry const*&, ChatHandler const*, std::string_view) noexcept;
    };

    // GameTele* from string name or link
    template <>
    struct TC_GAME_API ArgInfo<GameTele const*>
    {
        static ChatCommandResult TryConsume(GameTele const*&, ChatHandler const*, std::string_view) noexcept;
    };

    // ItemTemplate* from numeric id or link
    template <>
    struct TC_GAME_API ArgInfo<ItemTemplate const*>
    {
        static ChatCommandResult TryConsume(ItemTemplate const*&, ChatHandler const*, std::string_view) noexcept;
    };

    // Quest* from numeric id or link
    template <>
    struct TC_GAME_API ArgInfo<Quest const*>
    {
        static ChatCommandResult TryConsume(Quest const*&, ChatHandler const*, std::string_view) noexcept;
    };

    // SpellInfo const* from spell id or link
    template <>
    struct TC_GAME_API ArgInfo<SpellInfo const*>
    {
        static ChatCommandResult TryConsume(SpellInfo const*&, ChatHandler const*, std::string_view) noexcept;
    };

}

#endif
