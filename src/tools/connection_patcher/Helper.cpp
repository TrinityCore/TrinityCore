/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2020 TrinityCore <https://www.trinitycore.org/>
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

#include "Helper.hpp"

#include <SHA256.h>
#include <Util.h>

#include <stdexcept>

namespace Connection_Patcher
{
    namespace Helper
    {
        Constants::BinaryTypes GetBinaryType(std::vector<unsigned char> const& data)
        {
            // Check MS-DOS magic
            if (*reinterpret_cast<uint16_t const*>(data.data()) == 0x5A4D)
            {
                uint32_t const peOffset(*reinterpret_cast<uint32_t const*>(data.data() + 0x3C));

                // Check PE magic
                if (*reinterpret_cast<uint32_t const*>(data.data() + peOffset) != 0x4550)
                    throw std::invalid_argument("Not a PE file!");

                return Constants::BinaryTypes(*reinterpret_cast<uint16_t const*>(data.data() + peOffset + 4));
            }
            else
            {
                return Constants::BinaryTypes(*reinterpret_cast<uint32_t const*>(data.data()));
            }
        }

        std::string GetFileChecksum(std::vector<unsigned char> const& data)
        {
            SHA256Hash h;
            h.UpdateData(data.data(), data.size());
            h.Finalize();

            return ByteArrayToHexStr(h.GetDigest(), h.GetLength());
        }
    }
}
