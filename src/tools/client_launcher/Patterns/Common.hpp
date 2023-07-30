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

#ifndef ClientLauncherPatternsCommon_h__
#define ClientLauncherPatternsCommon_h__

#include <vector>

namespace ClientLauncher
{
    namespace Patterns
    {
        struct Common
        {
            static const std::vector<unsigned char> Modulus() { return { 0x91, 0xD5, 0x9B, 0xB7, 0xD4, 0xE1, 0x83, 0xA5 }; }
            static const std::vector<unsigned char> BinaryVersionCheck() { return{ 0x57, 0x4F, 0x57, 0x43, 0x4F, 0x4D, 0x53, 0x41, 0x54, 0x43, 0x4C, 0x49, 0x45, 0x4E, 0x54, 0x31, 0x35, 0x35, 0x39, 0x35 }; }
        };
    }
}

#endif // ClientLauncherPatternsCommon_h__
