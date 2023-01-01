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

#ifndef FlagsArray_h__
#define FlagsArray_h__

#include "Define.h"
#include <array>

template<typename T, size_t N>
class FlagsArray
{
public:
    constexpr FlagsArray operator&(FlagsArray const& right) const
    {
        FlagsArray temp = *this;
        temp &= right;
        return temp;
    }

    constexpr FlagsArray& operator&=(FlagsArray const& right)
    {
        for (size_t i = 0; i < N; ++i)
            _storage[i] &= right[i];

        return *this;
    }

    constexpr FlagsArray operator|(FlagsArray const& right) const
    {
        FlagsArray temp = *this;
        temp |= right;
        return temp;
    }

    constexpr FlagsArray& operator|=(FlagsArray const& right)
    {
        for (size_t i = 0; i < N; ++i)
            _storage[i] |= right[i];

        return *this;
    }

    constexpr FlagsArray operator~() const
    {
        FlagsArray temp = *this;
        for (size_t i = 0; i < N; ++i)
            temp._storage[i] = ~_storage[i];

        return temp;
    }

    constexpr FlagsArray operator^(FlagsArray const& right) const
    {
        FlagsArray temp = *this;
        temp ^= right;
        return temp;
    }

    constexpr FlagsArray& operator^=(FlagsArray const& right)
    {
        for (size_t i = 0; i < N; ++i)
            _storage[i] ^= right[i];

        return *this;
    }

    constexpr explicit operator bool() const
    {
        for (size_t i = 0; i < N; ++i)
            if (_storage[i])
                return true;

        return false;
    }

    constexpr bool operator !() const
    {
        return !(bool(*this));
    }

    constexpr T& operator[](size_t i)
    {
        return _storage[i];
    }

    constexpr T const& operator [](size_t i) const
    {
        return _storage[i];
    }

    constexpr FlagsArray& operator=(std::array<T, N> const& right)
    {
        _storage = right;
        return *this;
    }

protected:
    std::array<T, N> _storage = { };
};

class flag128 : public FlagsArray<uint32, 4>
{
public:
    constexpr flag128(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0)
    {
        _storage[0] = p1;
        _storage[1] = p2;
        _storage[2] = p3;
        _storage[3] = p4;
    }

    constexpr bool IsEqual(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0) const
    {
        return (_storage[0] == p1 && _storage[1] == p2 && _storage[2] == p3 && _storage[3] == p4);
    }

    constexpr bool HasFlag(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0) const
    {
        return (_storage[0] & p1 || _storage[1] & p2 || _storage[2] & p3 || _storage[3] & p4);
    }

    constexpr void Set(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0)
    {
        _storage[0] = p1;
        _storage[1] = p2;
        _storage[2] = p3;
        _storage[3] = p4;
    }
};

#endif // FlagsArray_h__
