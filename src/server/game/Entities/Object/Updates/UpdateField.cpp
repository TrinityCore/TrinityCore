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

#include "UpdateField.h"
#include "ByteBuffer.h"

void UF::WriteDynamicFieldUpdateMask(std::size_t size, std::vector<uint32> const& updateMask, ByteBuffer& data)
{
    data.WriteBits(size, 32);
    if (size > 32)
    {
        if (data.HasUnfinishedBitPack())
            for (std::size_t block = 0; block < size / 32; ++block)
                data.WriteBits(updateMask[block], 32);
        else
            for (std::size_t block = 0; block < size / 32; ++block)
                data << uint32(updateMask[block]);
    }
    else if (size == 32)
    {
        data.WriteBits(updateMask.back(), 32);
        return;
    }

    if (size % 32)
        data.WriteBits(updateMask.back(), size % 32);
}
