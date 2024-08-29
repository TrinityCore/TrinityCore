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

#include "ClientBuildInfo.h"
#include <algorithm>
#include <cctype>

std::array<char, 5> ClientBuild::ToCharArray(uint32 value)
{
    auto normalize = [](uint8 c) -> char
    {
        if (!c || std::isprint(c))
            return char(c);
        return ' ';
    };

    std::array<char, 5> chars = { char((value >> 24) & 0xFF), char((value >> 16) & 0xFF), char((value >> 8) & 0xFF), char(value & 0xFF), '\0' };

    auto firstNonZero = std::ranges::find_if(chars, [](char c) { return c != '\0'; });
    if (firstNonZero != chars.end())
    {
        // move leading zeros to end
        std::rotate(chars.begin(), firstNonZero, chars.end());

        // ensure we only have printable characters remaining
        std::ranges::transform(chars, chars.begin(), normalize);
    }

    return chars;
}

bool ClientBuild::Platform::IsValid(std::string_view platform)
{
    if (platform.length() > sizeof(uint32))
        return false;

    uint32 platformInt = 0;
    for (uint8 c : platform)
    {
        platformInt <<= 8;
        platformInt |= c;
    }

    switch (platformInt)
    {
        case Win_x86:
        case Win_x64:
        case Win_arm64:
        case Mac_x86:
        case Mac_x64:
        case Mac_arm64:
            return true;
        default:
            break;
    }

    return false;
}
