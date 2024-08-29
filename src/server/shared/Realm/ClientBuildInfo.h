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
consteval uint32 operator""_fourcc(char const* chars, std::size_t length)
{
    if (length > sizeof(uint32))
        throw "Text can only be max 4 characters long";

    uint32 uintValue = 0;
    for (uint8 c : std::string_view(chars, length))
    {
        uintValue <<= 8;
        uintValue |= c;
    }

    return uintValue;
}

TC_SHARED_API std::array<char, 5> ToCharArray(uint32 value);

namespace Platform
{
    inline constexpr uint32 Win_x86     = "Win"_fourcc;
    inline constexpr uint32 Win_x64     = "Wn64"_fourcc;
    inline constexpr uint32 Win_arm64   = "WinA"_fourcc;
    inline constexpr uint32 Mac_x86     = "Mac"_fourcc;
    inline constexpr uint32 Mac_x64     = "Mc64"_fourcc;
    inline constexpr uint32 Mac_arm64   = "MacA"_fourcc;

    TC_SHARED_API bool IsValid(std::string_view platform);
}

namespace PlatformType
{
    inline constexpr uint32 Windows     = "Win"_fourcc;
    inline constexpr uint32 macOS       = "Mac"_fourcc;
}

namespace Arch
{
    inline constexpr uint32 x86         = "x86"_fourcc;
    inline constexpr uint32 x64         = "x64"_fourcc;
    inline constexpr uint32 Arm32       = "A32"_fourcc;
    inline constexpr uint32 Arm64       = "A64"_fourcc;
    inline constexpr uint32 WA32        = "WA32"_fourcc;
}

namespace Type
{
    inline constexpr uint32 Retail      = "WoW"_fourcc;
    inline constexpr uint32 RetailChina = "WoWC"_fourcc;
    inline constexpr uint32 Beta        = "WoWB"_fourcc;
    inline constexpr uint32 BetaRelease = "WoWE"_fourcc;
    inline constexpr uint32 Ptr         = "WoWT"_fourcc;
    inline constexpr uint32 PtrRelease  = "WoWR"_fourcc;
}

struct VariantId
{
    uint32 Platform;
    uint32 Arch;
    uint32 Type;

    friend bool operator==(VariantId const& left, VariantId const& right) = default;
};

struct AuthKey
{
    static constexpr std::size_t Size = 16;

    VariantId Variant;
    std::array<uint8, Size> Key;
};

struct Info
{
    uint32 Build;
    uint32 MajorVersion;
    uint32 MinorVersion;
    uint32 BugfixVersion;
    std::array<char, 4> HotfixVersion;
    std::vector<AuthKey> AuthKeys;
};

TC_SHARED_API void LoadBuildInfo();
TC_SHARED_API Info const* GetBuildInfo(uint32 build);
TC_SHARED_API uint32 GetMinorMajorBugfixVersionForBuild(uint32 build);
}

#endif // TRINITYCORE_CLIENT_BUILD_INFO_H
