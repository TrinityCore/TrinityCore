/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

using Connection_Patcher.Constants;
using System;
using System.IO;
using System.Security.Cryptography;

namespace Connection_Patcher
{
    class Helper
    {
        public static BinaryTypes GetBinaryType(byte[] data)
        {
            BinaryTypes type = 0u;

            using (var reader = new BinaryReader(new MemoryStream(data)))
            {
                var magic = (uint)reader.ReadUInt16();

                // Check MS-DOS magic
                if (magic == 0x5A4D)
                {
                    reader.BaseStream.Seek(0x3C, SeekOrigin.Begin);

                    // Read PE start offset
                    var peOffset = reader.ReadUInt32();

                    reader.BaseStream.Seek(peOffset, SeekOrigin.Begin);

                    var peMagic = reader.ReadUInt32();

                    // Check PE magic
                    if (peMagic != 0x4550)
                        throw new NotSupportedException("Not a PE file!");

                    type = (BinaryTypes)reader.ReadUInt16();
                }
                else
                {
                    reader.BaseStream.Seek(0, SeekOrigin.Begin);

                    type = (BinaryTypes)reader.ReadUInt32();
                }
            }

            return type;
        }

        public static string GetFileChecksum(byte[] data)
        {
            using (var stream = new BufferedStream(new MemoryStream(data), 1200000))
            {
                var sha256 = new SHA256Managed();
                var checksum = sha256.ComputeHash(stream);

                return BitConverter.ToString(checksum).Replace("-", "").ToLower();
            }
        }
    }
}
