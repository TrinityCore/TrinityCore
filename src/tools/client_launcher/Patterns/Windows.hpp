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

#ifndef ClientLauncherPatternsWindows_h__
#define ClientLauncherPatternsWindows_h__

#include <vector>

namespace ClientLauncher
{
    namespace Patterns
    {
        namespace Windows
        {
            struct x86
            {
                static const std::vector<unsigned char> Password() { return { 0x74, 0x89, 0x8B, 0x16, 0x8B, 0x42, 0x04 }; }
            };

            struct x64
            {
                static const std::vector<unsigned char> Password() { return { 0x74, 0x84, 0x48, 0x8B, 0x03 }; }
            };
        };
    }
}

#endif // ClientLauncherPatternsWindows_h__
