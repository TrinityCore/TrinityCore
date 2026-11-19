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

#include "FourCC.h"
#include "StringFormat.h"
#include <cctype>

template <typename FormatContext>
auto fmt::formatter<FourCC<void>, char, void>::format(FourCC<void> fcc, FormatContext& ctx) const -> decltype(ctx.out())
{
    auto printByte = [](auto itr, uint8 b)
    {
        if (std::isprint(b))
            *itr = static_cast<char>(b);
        else
            Trinity::StringFormatTo(itr, R"(\x{:02X})", b);
    };

    printByte(ctx.out(), (fcc.Value >> 24) & 0xFF);
    printByte(ctx.out(), (fcc.Value >> 16) & 0xFF);
    printByte(ctx.out(), (fcc.Value >>  8) & 0xFF);
    printByte(ctx.out(), (fcc.Value >>  0) & 0xFF);

    return ctx.out();
}

template TC_COMMON_API fmt::appender fmt::formatter<FourCC<void>>::format<fmt::format_context>(FourCC<void>, format_context&) const;
