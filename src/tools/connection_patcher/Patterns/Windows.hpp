/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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
            struct x86
            {
                static const std::vector<unsigned char> BNet() { return { }; }
                static const std::vector<unsigned char> Portal() { return { '.', 'l', 'o', 'g', 'o', 'n', '.', 'b', 'a', 't', 't', 'l', 'e', '.', 'n', 'e', 't', 0x00 }; }
                static const std::vector<unsigned char> Connect() { return { }; }
                static const std::vector<unsigned char> Password() { return { }; }
                static const std::vector<unsigned char> Signature() { return { }; }
            };

            struct x64
            {
                static const std::vector<unsigned char> BNet() { return { }; }
                static const std::vector<unsigned char> Portal() { return { '.', 'l', 'o', 'g', 'o', 'n', '.', 'b', 'a', 't', 't', 'l', 'e', '.', 'n', 'e', 't', 0x00 }; }
                static const std::vector<unsigned char> Connect() { return { }; }
                static const std::vector<unsigned char> Password() { return { }; }
                static const std::vector<unsigned char> Signature() { return { }; }
            };
        };
    }
}

#endif
