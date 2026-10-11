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

#include "FourCC.h"
#include <array>
#include <string_view>
#include <vector>

namespace ClientBuild
{
using namespace FourCCLiterals;

struct Program
{
    using Id = FourCC<Program>;

    static constexpr Id WoW             { "WoW"_fourcc };

    TC_SHARED_API static bool IsValid(std::string_view program);
};

struct Platform
{
    using Id = FourCC<Platform>;

    static constexpr Id Win_x86         { "Win"_fourcc };
    static constexpr Id Win_x64         { "Wn64"_fourcc };
    static constexpr Id Win_arm64       { "WinA"_fourcc };
    static constexpr Id Mac_x86         { "Mac"_fourcc };
    static constexpr Id Mac_x64         { "Mc64"_fourcc };
    static constexpr Id Mac_arm64       { "MacA"_fourcc };

    TC_SHARED_API static bool IsValid(std::string_view platform);
};

struct PlatformType
{
    using Id = FourCC<PlatformType>;

    static constexpr Id Windows         { "Win"_fourcc };
    static constexpr Id macOS           { "Mac"_fourcc };

    TC_SHARED_API static bool IsValid(std::string_view platformType);
};

struct Arch
{
    using Id = FourCC<Arch>;

    static constexpr Id x86             { "x86"_fourcc };
    static constexpr Id x64             { "x64"_fourcc };
    static constexpr Id Arm32           { "A32"_fourcc };
    static constexpr Id Arm64           { "A64"_fourcc };
    static constexpr Id WA32            { "WA32"_fourcc };

    TC_SHARED_API static bool IsValid(std::string_view arch);
};

struct Type
{
    using Id = FourCC<Type>;

    static constexpr Id Retail          { "WoW"_fourcc };
    static constexpr Id RetailChina     { "WoWC"_fourcc };
    static constexpr Id Beta            { "WoWB"_fourcc };
    static constexpr Id BetaRelease     { "WoWE"_fourcc };
    static constexpr Id Ptr             { "WoWT"_fourcc };
    static constexpr Id PtrRelease      { "WoWR"_fourcc };

    TC_SHARED_API static bool IsValid(std::string_view type);
};

struct VariantId
{
    ClientBuild::Platform::Id Platform;
    ClientBuild::Arch::Id Arch;
    ClientBuild::Type::Id Type;

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
