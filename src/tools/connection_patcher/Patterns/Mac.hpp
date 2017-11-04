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

#ifndef CONNECTION_PATCHER_PATTERNS_MAC_HPP
#define CONNECTION_PATCHER_PATTERNS_MAC_HPP

#include <vector>

namespace Connection_Patcher
{
    namespace Patterns
    {
        namespace Mac
        {
            struct x64
            {
                static std::vector<unsigned char> CertBundleCASCLocalFile() { return{ 0x48, 0x8D, 0x55, 0xDC, 0x31, 0xDB, 0x31, 0xC9 }; }
                static std::vector<unsigned char> CertBundleSignatureCheck() { return{ 0x45, 0x84, 0xFF, 0xB0, 0x01, 0x75, 0x03, 0x44, 0x89 }; }
                static std::vector<unsigned char> LauncherLoginParametersLocation()
                {
                    char const path[] = "net.battle";
                    return std::vector<unsigned char>(std::begin(path), std::end(path));
                }
            };
        };
    }
}

#endif
