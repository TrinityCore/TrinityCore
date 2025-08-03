/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef CONNECTION_PATCHER_PATTERNS_COMMON_HPP
#define CONNECTION_PATCHER_PATTERNS_COMMON_HPP

#include <vector>

namespace Connection_Patcher
{
    namespace Patterns
    {
        struct Common
        {
            static std::vector<unsigned char> Portal() { return { '.', 'a', 'c', 't', 'u', 'a' , 'l', '.', 'b', 'a', 't', 't', 'l', 'e', '.', 'n', 'e', 't', 0x00 }; }
            static std::vector<unsigned char> RSAModulus() { return { 0x91, 0xD5, 0x9B, 0xB7, 0xD4, 0xE1, 0x83, 0xA5 }; }
			static std::vector<unsigned char> CryptoEd25519PublicKey() { return { 0x15, 0xD6, 0x18, 0xBD, 0x7D, 0xB5, 0x77, 0xBD }; }
			static std::vector<unsigned char> BinaryVersion() { return { 0x3C, 0x56, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x3E }; }
			static std::vector<unsigned char> Debug() { return { 'a', 'r', 'c', 't', 'i', 'u' , 'm' }; }
        };
    }
}

#endif
