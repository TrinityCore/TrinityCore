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

#ifndef UpdateMask_h__
#define UpdateMask_h__

#include "Define.h"

namespace UpdateMaskHelpers
{
    inline constexpr uint32 GetBlockIndex(uint32 bit) { return bit / 32; }
    inline constexpr uint32 GetBlockFlag(uint32 bit) { return 1 << (bit % 32); }
}

template<uint32 Bits>
class UpdateMask
{
public:
    static constexpr uint32 BlockCount = (Bits + 31) / 32;
    static constexpr uint32 BlocksMaskCount = (BlockCount + 31) / 32;

    UpdateMask()
    {
        std::fill(std::begin(_blocksMask), std::end(_blocksMask), 0);
        std::fill(std::begin(_blocks), std::end(_blocks), 0);
    }

    UpdateMask(std::initializer_list<uint32> init)
    {
        InitFromBlocks(init.begin(), init.size());
    }

    uint32 GetBlocksMask(uint32 index) const
    {
        return _blocksMask[index];
    }

    uint32 GetBlock(uint32 index) const
    {
        return _blocks[index];
    }

    bool operator[](uint32 index) const
    {
        return (_blocks[index / 32] & (1 << (index % 32))) != 0;
    }

    bool IsAnySet() const
    {
        return std::any_of(std::begin(_blocksMask), std::end(_blocksMask), [](uint32 blockMask)
        {
            return blockMask != 0;
        });
    }

    void Reset(uint32 index)
    {
        std::size_t blockIndex = UpdateMaskHelpers::GetBlockIndex(index);
        if (!(_blocks[blockIndex] &= ~UpdateMaskHelpers::GetBlockFlag(index)))
            _blocksMask[UpdateMaskHelpers::GetBlockIndex(blockIndex)] &= ~UpdateMaskHelpers::GetBlockFlag(blockIndex);
    }

    void ResetAll()
    {
        std::fill(std::begin(_blocksMask), std::end(_blocksMask), 0);
        std::fill(std::begin(_blocks), std::end(_blocks), 0);
    }

    void Set(uint32 index)
    {
        std::size_t blockIndex = UpdateMaskHelpers::GetBlockIndex(index);
        _blocks[blockIndex] |= UpdateMaskHelpers::GetBlockFlag(index);
        _blocksMask[UpdateMaskHelpers::GetBlockIndex(blockIndex)] |= UpdateMaskHelpers::GetBlockFlag(blockIndex);
    }

    void SetAll()
    {
        std::fill(std::begin(_blocksMask), std::end(_blocksMask), 0xFFFFFFFF);
        if (BlocksMaskCount % 32)
        {
            constexpr uint32 unused = 32 - (BlocksMaskCount % 32);
            _blocksMask[BlocksMaskCount - 1] &= (0xFFFFFFFF >> unused);
        }
        std::fill(std::begin(_blocks), std::end(_blocks), 0xFFFFFFFF);
        if (BlockCount % 32)
        {
            constexpr uint32 unused = 32 - (BlockCount % 32);
            _blocks[BlockCount - 1] &= (0xFFFFFFFF >> unused);
        }
    }

    UpdateMask& operator&=(UpdateMask const& right)
    {
        for (uint32 i = 0; i < BlocksMaskCount; ++i)
            _blocksMask[i] &= right._blocksMask[i];

        for (uint32 i = 0; i < BlockCount; ++i)
            if (!(_blocks[i] &= right._blocks[i]))
                _blocksMask[UpdateMaskHelpers::GetBlockIndex(i)] &= ~UpdateMaskHelpers::GetBlockFlag(i);

        return *this;
    }

    UpdateMask& operator|=(UpdateMask const& right)
    {
        for (std::size_t i = 0; i < BlocksMaskCount; ++i)
            _blocksMask[i] |= right._blocksMask[i];

        for (std::size_t i = 0; i < BlockCount; ++i)
            _blocks[i] |= right._blocks[i];

        return *this;
    }

private:
    void InitFromBlocks(uint32 const* input, uint32 size)
    {
        std::fill(std::begin(_blocksMask), std::end(_blocksMask), 0);

        uint32 block = 0;
        for (; block < size; ++block)
            if ((_blocks[block] = input[block]) != 0)
                _blocksMask[UpdateMaskHelpers::GetBlockIndex(block)] |= UpdateMaskHelpers::GetBlockFlag(block);

        for (; block < BlockCount; ++block)
            _blocks[block] = 0;
    }

    uint32 _blocksMask[BlocksMaskCount];
    uint32 _blocks[BlockCount];
};

template<uint32 Bits>
UpdateMask<Bits> operator&(UpdateMask<Bits> const& left, UpdateMask<Bits> const& right)
{
    UpdateMask<Bits> result = left;
    result &= right;
    return result;
}

template<uint32 Bits>
UpdateMask<Bits> operator|(UpdateMask<Bits> const& left, UpdateMask<Bits> const& right)
{
    UpdateMask<Bits> result = left;
    result |= right;
    return result;
}

#endif // UpdateMask_h__
