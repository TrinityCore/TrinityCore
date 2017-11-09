/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONNECTION_PATCHER_PATTERNS_WINDOWS_HPP
#define CONNECTION_PATCHER_PATTERNS_WINDOWS_HPP

#include <vector>

namespace Connection_Patcher
{
    namespace Patterns
    {
        namespace Windows
        {
            static std::vector<unsigned char> LauncherLoginParametersLocation()
            {
                char const path[] = R"(Software\Blizzard Entertainment\Battle.net\Launch Options\)";
                return std::vector<unsigned char>(std::begin(path), std::end(path));
            }

            struct x86
            {
                static std::vector<unsigned char> CertBundleCASCLocalFile() { return{ 0x6A, 0x00, 0x50, 0x8D, 0x45, 0xF8, 0x50, 0x68 }; }
                static std::vector<unsigned char> CertBundleSignatureCheck() { return{ 0x59, 0x59, 0x84, 0xC0, 0x75, 0x08, 0x46, 0x83, 0xFE, 0x02 }; }
                static std::vector<unsigned char> LauncherLoginParametersLocation() { return ::Connection_Patcher::Patterns::Windows::LauncherLoginParametersLocation(); }
            };

            struct x64
            {
                static std::vector<unsigned char> CertBundleCASCLocalFile() { return{ 0x45, 0x33, 0xC9, 0x48, 0x89, 0x9C, 0x24, 0x90, 0x02 }; }
                static std::vector<unsigned char> CertBundleSignatureCheck() { return{ 0x75, 0x0B, 0x48, 0xFF, 0xC7, 0x48, 0x83, 0xFF, 0x02 }; }
                static std::vector<unsigned char> LauncherLoginParametersLocation() { return ::Connection_Patcher::Patterns::Windows::LauncherLoginParametersLocation(); }
            };
        };
    }
}

#endif
