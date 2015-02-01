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

#pragma once

namespace WorldPackets
{
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

    template <typename T>
    struct CompactArray
    {
    public:
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
        uint32 _mask = 0;
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
}
