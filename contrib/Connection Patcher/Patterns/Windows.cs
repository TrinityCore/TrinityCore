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

namespace Connection_Patcher.Patterns
{
    class Windows
    {
        public static class x86
        {
            public static byte[] BNet       = { 0x8B, 0x75, 0x08, 0x8D, 0x78, 0x0C };
            public static byte[] Connect    = { 0x74, 0x33, 0x6A, 0x04, 0xFF, 0x75, 0xF8 };
            public static byte[] Password   = { 0x74, 0x89, 0x8B, 0x16, 0x8B, 0x42, 0x04 };
            public static byte[] Signature  = { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x84, 0xC0, 0x75, 0x5F, 0x33, 0xC0 };
        }

        public static class x64
        {
            public static byte[] BNet       = { 0x8B, 0x02, 0x89, 0x41, 0x0C, 0x48, 0x8B, 0xC1, 0xC3 };
            public static byte[] Portal     = { 0x2E, 0x6C, 0x6F, 0x67, 0x6F, 0x6E, 0x2E, 0x62, 0x61, 0x74, 0x74, 0x6C, 0x65, 0x2E, 0x6E, 0x65, 0x74, 0x00 };
            public static byte[] Connect    = { 0x74, 0x2C, 0x48, 0x8D, 0x4C, 0x24, 0x78 };
            public static byte[] Password   = { 0x74, 0x84, 0x48, 0x8B, 0x03 };
            public static byte[] Signature  = { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x84, 0xC0, 0x0F, 0x85, 0x88, 0x00, 0x00, 0x00, 0x45, 0x33, 0xC0 };
        }
    }
}
