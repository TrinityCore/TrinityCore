/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ClientLauncherPatternsWindows_h__
#define ClientLauncherPatternsWindows_h__

#include "Define.h"
#include <vector>

namespace ClientLauncher
{
    namespace Patterns
    {
        namespace Windows
        {
            static std::vector<uint8> LauncherLoginParametersLocation()
            {
                char const path[] = R"(Software\Blizzard Entertainment\Battle.net\Launch Options\)";
                return std::vector<uint8>(std::begin(path), std::end(path));
            }

            struct x86
            {
                static std::vector<uint8> CertBundleCASCLocalFile() { return{ 0x6A, 0x00, 0x50, 0x8D, 0x45, 0xF8, 0x50, 0x68 }; }
                static std::vector<uint8> CertBundleSignatureCheck() { return{ 0x83, 0xC4, 0x0C, 0x84, 0xC0, 0x75, 0x08, 0x46, 0x83, 0xFE, 0x02 }; }
                static std::vector<uint8> LauncherLoginParametersLocation() { return ::ClientLauncher::Patterns::Windows::LauncherLoginParametersLocation(); }
            };

            struct x64
            {
                static std::vector<uint8> CertBundleCASCLocalFile() { return{ 0x45, 0x33, 0xC9, 0x48, 0x89, 0x9C, 0x24, 0x00, 0x02 }; }
                static std::vector<uint8> CertBundleSignatureCheck() { return{ 0x75, 0x0B, 0x48, 0xFF, 0xC7, 0x48, 0x83, 0xFF, 0x02 }; }
                static std::vector<uint8> LauncherLoginParametersLocation() { return ::ClientLauncher::Patterns::Windows::LauncherLoginParametersLocation(); }
            };
        };
    }
}

#endif // ClientLauncherPatternsWindows_h__
