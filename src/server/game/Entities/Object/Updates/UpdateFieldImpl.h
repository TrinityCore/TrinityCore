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

#ifndef TRINITYCORE_UPDATE_FIELD_IMPL_H
#define TRINITYCORE_UPDATE_FIELD_IMPL_H

#include "UpdateField.h"
#include "ByteBuffer.h"

class Player;

namespace UF
{
inline void WriteDynamicFieldUpdateMask(std::size_t size, std::vector<uint32> const& updateMask, ByteBuffer& data, int32 bitsForSize /*= 32*/)
{
    data.WriteBits(size, bitsForSize);
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

inline void WriteCompleteDynamicFieldUpdateMask(std::size_t size, ByteBuffer& data, int32 bitsForSize = 32)
{
    data.WriteBits(size, bitsForSize);
    if (size > 32)
    {
        if (data.HasUnfinishedBitPack())
            for (std::size_t block = 0; block < size / 32; ++block)
                data.WriteBits(0xFFFFFFFFu, 32);
        else
            for (std::size_t block = 0; block < size / 32; ++block)
                data << uint32(0xFFFFFFFFu);
    }
    else if (size == 32)
    {
        data.WriteBits(0xFFFFFFFFu, 32);
        return;
    }

    if (size % 32)
        data.WriteBits(0xFFFFFFFFu, size % 32);
}

template <typename K, typename V, typename T>
inline void WriteMapFieldCreate(MapUpdateFieldBase<K, V> const& map, ByteBuffer& data, T const* owner, Player const* receiver)
{
    data << uint32(map.size());
    for (auto const& [k, v] : map)
    {
        if constexpr (std::is_base_of_v<IsUpdateFieldStructureTag, K>)
            k.WriteCreate(data, owner, receiver);
        else
            data << k;

        if constexpr (std::is_base_of_v<IsUpdateFieldStructureTag, V>)
            v.value.WriteCreate(data, owner, receiver);
        else
            data << v.value;
    }
}

template <typename K, typename V, typename T>
inline void WriteMapFieldUpdate(MapUpdateFieldBase<K, V> const& map, ByteBuffer& data, bool ignoreChangesMask, T const* owner, Player const* receiver)
{
    data << uint8(ignoreChangesMask ? 1 : 0);
    if (ignoreChangesMask)
        UF::WriteMapFieldCreate(map, data, owner, receiver);
    else
    {
        uint16 changesCount = 0;
        size_t changesCountPos = data.wpos();
        data << uint16(changesCount);

        for (auto const& [k, v] : map)
        {
            if (v.state == MapUpdateFieldState::Unchanged)
                continue;

            ++changesCount;

            if constexpr (std::is_base_of_v<IsUpdateFieldStructureTag, K>)
                k.WriteUpdate(data, true /*ignoreChangesMask*/, owner, receiver);
            else
                data << k;

            data << uint8(v.state);
            if (v.state == MapUpdateFieldState::Deleted)
                continue;

            if constexpr (std::is_base_of_v<IsUpdateFieldStructureTag, V>)
                v.value.WriteUpdate(data, true /*ignoreChangesMask*/, owner, receiver); // client bug replaces unchanged values with 0/default so send everything as if it changed
            else
                data << v.value;
        }

        data.put<uint16>(changesCountPos, changesCount);
    }
}
}

#endif // TRINITYCORE_UPDATE_FIELD_IMPL_H
