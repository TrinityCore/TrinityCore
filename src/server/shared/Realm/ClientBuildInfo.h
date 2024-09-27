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

#ifndef TRINITYCORE_CLIENT_BUILD_INFO_H
#define TRINITYCORE_CLIENT_BUILD_INFO_H

#include "Define.h"
#include <array>
#include <string_view>
#include <vector>

namespace ClientBuild
{
inline constexpr uint32 ToFourCC(std::string_view text)
{
    uint32 uintValue = 0;
    for (uint8 c : text)
    {
        uintValue <<= 8;
        uintValue |= c;
    }
    return uintValue;
}

consteval uint32 operator""_fourcc(char const* chars, std::size_t length)
{
    if (length > sizeof(uint32))
        throw "Text can only be max 4 characters long";

    return ToFourCC({ chars, length });
}

TC_SHARED_API std::array<char, 5> ToCharArray(uint32 value);

namespace Platform
{
    inline constexpr uint32 Win_x86     = "Win"_fourcc;
    inline constexpr uint32 Mac_x86     = "OSX"_fourcc;

    TC_SHARED_API bool IsValid(std::string_view platform);
}

struct ExecutableHash
{
    static constexpr std::size_t Size = 20;

    uint32 Platform;
    std::array<uint8, Size> Hash;
};

struct Info
{
    uint32 Build;
    uint32 MajorVersion;
    uint32 MinorVersion;
    uint32 BugfixVersion;
    std::array<char, 4> HotfixVersion;
    std::vector<ExecutableHash> ExecutableHashes;
};

TC_SHARED_API void LoadBuildInfo();
TC_SHARED_API Info const* GetBuildInfo(uint32 build);
}

#endif // TRINITYCORE_CLIENT_BUILD_INFO_H
