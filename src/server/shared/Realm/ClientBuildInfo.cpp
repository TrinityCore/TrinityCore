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
#include "DatabaseEnv.h"
#include "Util.h"
#include <algorithm>
#include <cctype>

namespace
{
std::vector<ClientBuild::Info> Builds;
}

namespace ClientBuild
{
std::array<char, 5> ToCharArray(uint32 value)
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

bool Platform::IsValid(std::string_view platform)
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

void LoadBuildInfo()
{
    Builds.clear();

    //                                                              0             1              2              3      4              5              6
    if (QueryResult result = LoginDatabase.Query("SELECT majorVersion, minorVersion, bugfixVersion, hotfixVersion, build, win64AuthSeed, mac64AuthSeed, macArmAuthSeed FROM build_info ORDER BY build ASC"))
    {
        do
        {
            using namespace ClientBuild;

            Field* fields = result->Fetch();
            Info& build = Builds.emplace_back();
            build.MajorVersion = fields[0].GetUInt32();
            build.MinorVersion = fields[1].GetUInt32();
            build.BugfixVersion = fields[2].GetUInt32();
            std::string hotfixVersion = fields[3].GetString();
            if (hotfixVersion.length() < build.HotfixVersion.size())
                std::ranges::copy(hotfixVersion, build.HotfixVersion.begin());
            else
                build.HotfixVersion = { };

            build.Build = fields[4].GetUInt32();
            std::string win64AuthSeedHexStr = fields[5].GetString();
            if (win64AuthSeedHexStr.length() == AuthKey::Size * 2)
            {
                AuthKey& buildKey = build.AuthKeys.emplace_back();
                buildKey.Variant = { .Platform = PlatformType::Windows, .Arch = Arch::x64, .Type = Type::Retail };
                HexStrToByteArray(win64AuthSeedHexStr, buildKey.Key);
            }

            std::string mac64AuthSeedHexStr = fields[6].GetString();
            if (mac64AuthSeedHexStr.length() == AuthKey::Size * 2)
            {
                AuthKey& buildKey = build.AuthKeys.emplace_back();
                buildKey.Variant = { .Platform = PlatformType::macOS, .Arch = Arch::x64, .Type = Type::Retail };
                HexStrToByteArray(mac64AuthSeedHexStr, buildKey.Key);
            }

            std::string macArmAuthSeedHexStr = fields[7].GetString();
            if (macArmAuthSeedHexStr.length() == AuthKey::Size * 2)
            {
                AuthKey& buildKey = build.AuthKeys.emplace_back();
                buildKey.Variant = { .Platform = PlatformType::macOS, .Arch = Arch::Arm64, .Type = Type::Retail };
                HexStrToByteArray(macArmAuthSeedHexStr, buildKey.Key);
            }

        } while (result->NextRow());
    }
}

Info const* GetBuildInfo(uint32 build)
{
    auto buildInfo = std::ranges::find(Builds, build, &Info::Build);
    return buildInfo != Builds.end() ? &*buildInfo : nullptr;
}

uint32 GetMinorMajorBugfixVersionForBuild(uint32 build)
{
    auto buildInfo = std::ranges::lower_bound(Builds, build, {}, &Info::Build);
    return buildInfo != Builds.end() ? (buildInfo->MajorVersion * 10000 + buildInfo->MinorVersion * 100 + buildInfo->BugfixVersion) : 0;
}
}
