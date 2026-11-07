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

#include "StringFormat.h"
#include <fmt/format.h>

namespace Trinity::Impl
{
std::string StringVFormat(FormatStringView fmt, FormatArgs args) noexcept
try
{
    return fmt::vformat(fmt, args);
}
catch (std::exception const& formatError)
{
    return fmt::format(R"(An error occurred formatting string "{}" : {})", fmt, formatError.what());
}

void StringVFormatToImpl(fmt::detail::buffer<char>& buffer, FormatStringView fmt, FormatArgs args) noexcept
try
{
    fmt::detail::vformat_to(buffer, fmt, args, {});
}
catch (std::exception const& formatError)
{
    fmt::detail::vformat_to(buffer, FormatStringView(R"(An error occurred formatting string "{}" : {})"), MakeFormatArgs(fmt, formatError.what()), {});
}
}

// explicit template instantiations
template struct TC_COMMON_API fmt::formatter<int>;
template struct TC_COMMON_API fmt::formatter<unsigned>;
template struct TC_COMMON_API fmt::formatter<long long>;
template struct TC_COMMON_API fmt::formatter<unsigned long long>;
template struct TC_COMMON_API fmt::formatter<bool>;
template struct TC_COMMON_API fmt::formatter<char>;
template struct TC_COMMON_API fmt::formatter<float>;
template struct TC_COMMON_API fmt::formatter<double>;
template struct TC_COMMON_API fmt::formatter<long double>;
template struct TC_COMMON_API fmt::formatter<char const*>;
template struct TC_COMMON_API fmt::formatter<void const*>;
template struct TC_COMMON_API fmt::formatter<fmt::basic_string_view<char>>;

template TC_COMMON_API fmt::appender fmt::detail::native_formatter<int, char, fmt::detail::type::int_type>::format<fmt::format_context>(int const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<unsigned, char, fmt::detail::type::uint_type>::format<fmt::format_context>(unsigned const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<long long, char, fmt::detail::type::long_long_type>::format<fmt::format_context>(long long const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<unsigned long long, char, fmt::detail::type::ulong_long_type>::format<fmt::format_context>(unsigned long long const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<bool, char, fmt::detail::type::bool_type>::format<fmt::format_context>(bool const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<char, char, fmt::detail::type::char_type>::format<fmt::format_context>(char const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<float, char, fmt::detail::type::float_type>::format<fmt::format_context>(float const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<double, char, fmt::detail::type::double_type>::format<fmt::format_context>(double const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<long double, char, fmt::detail::type::long_double_type>::format<fmt::format_context>(long double const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<char const*, char, fmt::detail::type::cstring_type>::format<fmt::format_context>(char const* const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<void const*, char, fmt::detail::type::pointer_type>::format<fmt::format_context>(void const* const&, format_context &) const;
template TC_COMMON_API fmt::appender fmt::detail::native_formatter<fmt::string_view, char, fmt::detail::type::string_type>::format<fmt::format_context>(string_view const&, format_context &) const;
