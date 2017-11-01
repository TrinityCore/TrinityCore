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

#ifndef ClientLauncherPatchesWindows_h__
#define ClientLauncherPatchesWindows_h__

#include "Define.h"
#include <vector>

namespace ClientLauncher
{
    namespace Patches
    {
        namespace Windows
        {
            static std::vector<uint8> LauncherLoginParametersLocation()
            {
                char const path[] = R"(Software\TrinityCore Developers\Battle.net\Launch Options\)";
                return std::vector<uint8>(std::begin(path), std::end(path));
            }

            struct x86
            {
                static std::vector<uint8> CertBundleCASCLocalFile() { return{ 0x6A, 0x01 }; }
                static std::vector<uint8> CertBundleSignatureCheck() { return{ 0x59, 0x59, 0x84, 0xC0, 0xEB }; }
                static std::vector<uint8> LauncherLoginParametersLocation() { return ::ClientLauncher::Patches::Windows::LauncherLoginParametersLocation(); }
            };

            struct x64
            {
                static std::vector<uint8> CertBundleCASCLocalFile() { return{ 0x41, 0xB1, 0x01 }; }
                static std::vector<uint8> CertBundleSignatureCheck() { return{ 0xEB }; }
                static std::vector<uint8> LauncherLoginParametersLocation() { return ::ClientLauncher::Patches::Windows::LauncherLoginParametersLocation(); }
            };
        };
    }
}

#endif // ClientLauncherPatchesWindows_h__
