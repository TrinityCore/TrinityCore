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

#ifndef TRINITYCORE_STRING_FORMAT_H
#define TRINITYCORE_STRING_FORMAT_H

#include "Optional.h"
#include <fmt/core.h>

namespace Trinity
{
    template<typename... Args>
    using FormatString = fmt::format_string<Args...>;

    using FormatStringView = fmt::string_view;

    using FormatArgs = fmt::format_args;

    template<typename... Args>
    constexpr auto MakeFormatArgs(Args&&... args) { return fmt::make_format_args(args...); }

    /// Default TC string format function.
    template<typename... Args>
    inline std::string StringFormat(FormatString<Args...> fmt, Args&&... args)
    {
        try
        {
            return fmt::format(fmt, std::forward<Args>(args)...);
        }
        catch (std::exception const& formatError)
        {
            return fmt::format("An error occurred formatting string \"{}\" : {}", fmt, formatError.what());
        }
    }

    template<typename OutputIt, typename... Args>
    inline OutputIt StringFormatTo(OutputIt out, FormatString<Args...> fmt, Args&&... args)
    {
        try
        {
            return fmt::format_to(out, fmt, std::forward<Args>(args)...);
        }
        catch (std::exception const& formatError)
        {
            return fmt::format_to(out, "An error occurred formatting string \"{}\" : {}", fmt, formatError.what());
        }
    }

    inline std::string StringVFormat(FormatStringView fmt, FormatArgs args)
    {
        try
        {
            return fmt::vformat(fmt, args);
        }
        catch (std::exception const& formatError)
        {
            return fmt::format("An error occurred formatting string \"{}\" : {}", fmt, formatError.what());
        }
    }

    template<typename OutputIt>
    inline OutputIt StringVFormatTo(OutputIt out, FormatStringView fmt, FormatArgs args)
    {
        try
        {
            return fmt::vformat_to(out, fmt, args);
        }
        catch (std::exception const& formatError)
        {
            return fmt::format_to(out, "An error occurred formatting string \"{}\" : {}", fmt, formatError.what());
        }
    }

    /// Returns true if the given char pointer is null.
    inline bool IsFormatEmptyOrNull(char const* fmt)
    {
        return fmt == nullptr;
    }

    /// Returns true if the given std::string is empty.
    inline bool IsFormatEmptyOrNull(std::string const& fmt)
    {
        return fmt.empty();
    }

    /// Returns true if the given std::string_view is empty.
    inline constexpr bool IsFormatEmptyOrNull(std::string_view fmt)
    {
        return fmt.empty();
    }

    inline constexpr bool IsFormatEmptyOrNull(fmt::string_view fmt)
    {
        return fmt.size() == 0;
    }
}

template<typename T, typename Char>
struct fmt::formatter<Optional<T>, Char> : formatter<T, Char>
{
    template<typename FormatContext>
    auto format(Optional<T> const& value, FormatContext& ctx) const -> decltype(ctx.out())
    {
        if (value.has_value())
            return formatter<T, Char>::format(*value, ctx);

        return formatter<std::string_view, Char>().format("(nullopt)", ctx);
    }
};

#endif
