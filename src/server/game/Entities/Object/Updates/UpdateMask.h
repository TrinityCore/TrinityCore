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

#ifndef __UPDATEMASK_H
#define __UPDATEMASK_H

#include "UpdateFields.h"
#include "ByteBuffer.h"
#include "Errors.h"

class UpdateMask
{
public:
    UpdateMask() : _bits(nullptr), _fieldCount(0) { }

    void SetBit(uint32 index)
    {
        _bits[index] = 1;
    }

    void UnsetBit(uint32 index)
    {
        _bits[index] = 0;
    }

    bool GetBit(uint32 index) const
    {
        return _bits[index] != 0;
    }

    void SetCount(uint32 valuesCount)
    {
        _bits = std::make_unique<uint8[]>(valuesCount);
        std::uninitialized_fill_n(&_bits[0], valuesCount, 0);
        _fieldCount = valuesCount;
    }

    void Clear()
    {
        if (_bits)
            std::fill_n(&_bits[0], _fieldCount, 0);
    }

private:
    std::unique_ptr<uint8[]> _bits;
    uint32 _fieldCount;
};

class UpdateMaskPacketBuilder
{
public:
    /// Type representing how client reads update mask
    using ClientUpdateMaskType = uint32;

    enum UpdateMaskCount
    {
        CLIENT_UPDATE_MASK_BITS = sizeof(ClientUpdateMaskType) * 8,
    };

    explicit UpdateMaskPacketBuilder(uint32 valuesCount) : _lastSetBit(0)
    {
        std::size_t blockCount = CalculateBlockCount(valuesCount);
        _mask = std::make_unique<ClientUpdateMaskType[]>(blockCount);
        std::uninitialized_fill_n(&_mask[0], blockCount, 0);
    }

    void SetBit(uint32 bit)
    {
        _mask[GetBlockIndex(bit)] |= GetBlockFlag(bit);
        _lastSetBit = bit;
    }

    void AppendToPacket(ByteBuffer* data)
    {
        uint8 blockCount = CalculateBlockCount(_lastSetBit + 1);
        *data << uint8(blockCount);
        if (blockCount)
            data->append(&_mask[0], blockCount);
    }

private:
    static constexpr uint8 CalculateBlockCount(uint32 fieldCount)
    {
        return (fieldCount + CLIENT_UPDATE_MASK_BITS - 1) / CLIENT_UPDATE_MASK_BITS;
    }

    static constexpr std::size_t GetBlockIndex(uint32 bit)
    {
        return bit / 32;
    }

    static constexpr uint32 GetBlockFlag(uint32 bit)
    {
        return 1u << (bit % 32);
    }

    std::unique_ptr<ClientUpdateMaskType[]> _mask;
    uint32 _lastSetBit;
};

#endif
