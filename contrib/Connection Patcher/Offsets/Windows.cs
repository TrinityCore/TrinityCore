/*
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

namespace Connection_Patcher.Offsets
{
    static class Windows
    {
        public static class x86
        {
            public static readonly long BNet = 0xD3259;
            public static readonly long Send = 0x889CA;
            public static readonly long Recv = 0x86EEE;
            public static readonly long Signature = 0x20B79;
            public static readonly long RealmList = 0x228D6C;
        }

        public static class x64
        {
            public static readonly long BNet = 0;
            public static readonly long Send = 0xAAB6B;
            public static readonly long Recv = 0xA9FA3;
            public static readonly long Signature = 0;
            public static readonly long RealmList = 0x2BB33C;
        }
    }
}
