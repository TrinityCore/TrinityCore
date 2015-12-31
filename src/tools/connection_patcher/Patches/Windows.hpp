/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef CONNECTION_PATCHER_PATCHES_WINDOWS_HPP
#define CONNECTION_PATCHER_PATCHES_WINDOWS_HPP

#include <vector>

namespace Connection_Patcher
{
    namespace Patches
    {
        namespace Windows
        {
            struct x86
            {
                static const std::vector<unsigned char> BNet     () { return { 0xC7, 0x40, 0x0C, 0xD5, 0xF8, 0x7F, 0x82 }; }
                static const std::vector<unsigned char> Password () { return { 0x75 }; }
                static const std::vector<unsigned char> Signature() { return { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xEB }; }
            };

            struct x64
            {
                static const std::vector<unsigned char> BNet     () { return { 0xB8, 0xD5, 0xF8, 0x7F, 0x82, 0x89, 0x41, 0x0C, 0x48, 0x8B, 0xC1, 0xC3 }; }
                static const std::vector<unsigned char> Password () { return { 0x75 }; }
                static const std::vector<unsigned char> Signature() { return { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9 }; }
            };
        };
    }
}

#endif
