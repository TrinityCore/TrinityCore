/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PacketUtilities_h__
#define PacketUtilities_h__

#include "ByteBuffer.h"
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>

inline ByteBuffer& operator<<(ByteBuffer& data, G3D::Vector2 const& v)
{
    data << v.x << v.y;
    return data;
}

inline ByteBuffer& operator>>(ByteBuffer& data, G3D::Vector2& v)
{
    data >> v.x >> v.y;
    return data;
}

inline ByteBuffer& operator<<(ByteBuffer& data, G3D::Vector3 const& v)
{
    data << v.x << v.y << v.z;
    return data;
}

inline ByteBuffer& operator>>(ByteBuffer& data, G3D::Vector3& v)
{
    data >> v.x >> v.y >> v.z;
    return data;
}

namespace WorldPackets
{
    template <typename T>
    class CompactArray
    {
    public:
        CompactArray() : _mask(0) { }

        CompactArray(CompactArray const& right)
            : _mask(right._mask), _contents(right._contents) { }

        CompactArray(CompactArray&& right)
            : _mask(right._mask), _contents(std::move(right._contents))
        {
            right._mask = 0;
        }

        CompactArray& operator= (CompactArray const& right)
        {
            _mask = right._mask;
            _contents = right._contents;
            return *this;
        }

        CompactArray& operator= (CompactArray&& right)
        {
            _mask = right._mask;
            right._mask = 0;
            _contents = std::move(right._contents);
            return *this;
        }

        uint32 GetMask() const { return _mask; }
        T const& operator[](size_t index) const { return _contents.at(index); }
        size_t GetSize() const { return _contents.size(); }

        void Insert(size_t index, T const& value)
        {
            ASSERT(index < 0x20);

            _mask |= 1 << index;
            if (_contents.size() <= index)
                _contents.resize(index + 1);
            _contents[index] = value;
        }

        void Clear()
        {
            _mask = 0;
            _contents.clear();
        }

    private:
        uint32 _mask;
        std::vector<T> _contents;
    };

    template <typename T>
    ByteBuffer& operator<<(ByteBuffer& data, CompactArray<T> const& v)
    {
        uint32 mask = v.GetMask();
        data << uint32(mask);
        for (size_t i = 0; i < v.GetSize(); ++i)
        {
            if (mask & (1 << i))
                data << v[i];
        }

        return data;
    }

    template <typename T>
    ByteBuffer& operator>>(ByteBuffer& data, CompactArray<T>& v)
    {
        uint32 mask;
        data >> mask;

        for (size_t index = 0; mask != 0; mask >>= 1, ++index)
        {
            if ((mask & 1) != 0)
            {
                T value;
                data >> value;
                v.Insert(index, value);
            }
        }

        return data;
    }
}

#endif // PacketUtilities_h__
