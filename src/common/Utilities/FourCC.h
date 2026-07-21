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

#ifndef TRINITYCORE_FOURCC_H
#define TRINITYCORE_FOURCC_H

#include "Define.h"
#include "StringFormatFwd.h"
#include <string_view>

template <typename Tag>
struct FourCC
{
    uint32 Value;

    constexpr FourCC() : Value(0) { }
    explicit constexpr FourCC(uint32 value) : Value(value) { }

    inline static constexpr FourCC FromString(std::string_view text)
    {
        uint32 uintValue = 0;
        for (uint8 c : text)
        {
            uintValue <<= 8;
            uintValue |= c;
        }
        return FourCC(uintValue);
    }

    constexpr bool operator==(FourCC const& right) const = default;

    constexpr std::strong_ordering operator<=>(FourCC const& right) const = default;

    constexpr operator uint32() const { return Value; }

    template <typename Other>
    constexpr bool operator==(FourCC<Other> const& right) const = delete;

    template <typename Other>
    constexpr std::strong_ordering operator<=>(FourCC<Other> const& right) const = delete;
};

namespace FourCCLiterals
{
consteval uint32 operator""_fourcc(char const* chars, std::size_t length)
{
    if (length > sizeof(uint32))
        throw "Text can only be max 4 characters long";

    return FourCC<void>::FromString({ chars, length });
}
}

template <>
struct fmt::formatter<FourCC<void>, char, void> : Trinity::NoArgFormatterBase
{
    template <typename FormatContext>
    auto format(FourCC<void> fcc, FormatContext& ctx) const -> decltype(ctx.out());
};

template <typename Tag>
struct fmt::formatter<FourCC<Tag>, char, void> : fmt::formatter<FourCC<void>, char, void>
{
    template <typename FormatContext>
    auto format(FourCC<Tag> fcc, FormatContext& ctx) const -> decltype(ctx.out())
    {
        return fmt::formatter<FourCC<void>, char, void>::format(FourCC<void>(fcc.Value), ctx);
    }
};

#endif // TRINITYCORE_FOURCC_H
