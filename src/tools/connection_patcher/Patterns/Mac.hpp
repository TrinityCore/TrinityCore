/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
                static const std::vector<unsigned char> BNet     () { return { 0x8B, 0x06, 0x89, 0x47, 0x0C, 0x5D, 0xC3 }; }
                static const std::vector<unsigned char> Portal   () { return { }; }
                static const std::vector<unsigned char> Connect  () { return { }; }
                static const std::vector<unsigned char> Password () { return { 0x0F, 0x84, 0x00, 0xFF, 0xFF, 0xFF, 0x49, 0x8B, 0x45, 0x00, 0xB9, 0x40 }; }
                static const std::vector<unsigned char> Signature() { return { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x45, 0x31, 0xED, 0x4D, 0x89, 0xFC, 0x84, 0xC0, 0x75 }; }
            };
        };
    }
}

#endif
