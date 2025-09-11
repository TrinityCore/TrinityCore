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

#include "Define.h"
#include "Optional.h"
#include "StringFormatFwd.h"
#include <fmt/core.h>

namespace Trinity
{
    template<typename... Args>
    using FormatString = fmt::format_string<Args...>;

    using FormatStringView = fmt::string_view;

    using FormatArgs = fmt::format_args;

    template<typename... Args>
    constexpr auto MakeFormatArgs(Args&&... args) { return fmt::make_format_args(args...); }

    namespace Impl
    {
        TC_COMMON_API std::string StringVFormat(FormatStringView fmt, FormatArgs args) noexcept;

        TC_COMMON_API void StringVFormatToImpl(fmt::detail::buffer<char>& buffer, FormatStringView fmt, FormatArgs args) noexcept;
    }

    using Impl::StringVFormat;

    template<typename OutputIt>
    inline OutputIt StringVFormatTo(OutputIt out, FormatStringView fmt, FormatArgs args) noexcept
    {
        auto&& buf = fmt::detail::get_buffer<char>(out);
        Trinity::Impl::StringVFormatToImpl(buf, fmt, args);
        return fmt::detail::get_iterator(buf, out);
    }

    /// Default TC string format function.
    template<typename... Args>
    inline std::string StringFormat(FormatString<Args...> fmt, Args&&... args) noexcept
    {
        return Trinity::StringVFormat(fmt, Trinity::MakeFormatArgs(std::forward<Args>(args)...));
    }

    template<typename OutputIt, typename... Args>
    inline OutputIt StringFormatTo(OutputIt out, FormatString<Args...> fmt, Args&&... args) noexcept
    {
        return Trinity::StringVFormatTo(out, fmt, Trinity::MakeFormatArgs(std::forward<Args>(args)...));
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

        return formatter<string_view, Char>().format("(nullopt)", ctx);
    }
};

// allow implicit enum to int conversions for formatting
template <typename E, std::enable_if_t<std::is_enum_v<E>, std::nullptr_t> = nullptr>
inline constexpr auto format_as(E e) { return static_cast<std::underlying_type_t<E>>(e); }

#endif
