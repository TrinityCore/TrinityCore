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

#ifndef ClientPatcherPatchesWindows_h__
#define ClientPatcherPatchesWindows_h__

#include "Define.h"
#include <vector>

namespace ClientPatcher
{
    namespace Patches
    {
        namespace Windows
        {
            struct x86
            {
                static std::vector<unsigned char> BNet() { return { 0x89, 0x48, 0x08, 0xC7, 0x40, 0x0C, 0xD5, 0xF8, 0x7F, 0x82, 0x90 }; }
                static std::vector<unsigned char> Signature() { return { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9 }; }
            };

            struct x64
            {
                static std::vector<unsigned char> BNet() { return { 0xB8, 0xD5, 0xF8, 0x7F, 0x82, 0x89, 0x41, 0x0C, 0x48, 0x8B, 0xC1, 0xC3 }; }
                static std::vector<unsigned char> Signature() { return { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9 }; }
            };
        };
    }
}

#endif // ClientPatcherPatchesWindows_h__
