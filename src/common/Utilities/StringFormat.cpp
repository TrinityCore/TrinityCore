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
#include "Define.h"
#include <fmt/format.h>

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

template TC_COMMON_API fmt::appender fmt::formatter<int>::format<fmt::format_context>(int const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<unsigned>::format<fmt::format_context>(unsigned const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<long long>::format<fmt::format_context>(long long const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<unsigned long long>::format<fmt::format_context>(unsigned long long const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<bool>::format<fmt::format_context>(bool const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<char>::format<fmt::format_context>(char const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<float>::format<fmt::format_context>(float const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<double>::format<fmt::format_context>(double const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<long double>::format<fmt::format_context>(long double const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<char const*>::format<fmt::format_context>(char const* const&, format_context&) const;
template TC_COMMON_API fmt::appender fmt::formatter<void const*>::format<fmt::format_context>(void const* const&, format_context &) const;
template TC_COMMON_API fmt::appender fmt::formatter<fmt::string_view>::format<fmt::format_context>(string_view const&, format_context &) const;
