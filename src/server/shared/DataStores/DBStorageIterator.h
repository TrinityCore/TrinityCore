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

#ifndef DBStorageIterator_h__
#define DBStorageIterator_h__

#include "Define.h"
#include <iterator>

template<class T>
class DBStorageIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    DBStorageIterator() : _index(nullptr), _pos(0), _end(0) { }
    DBStorageIterator(value_type const* index, uint32 size, uint32 pos = 0) : _index(index), _pos(pos), _end(size)
    {
        if (_pos < _end)
        {
            while (_pos < _end && !_index[_pos])
                ++_pos;
        }
    }

    value_type const& operator->() const { return _index[_pos]; }
    value_type const& operator*() const { return _index[_pos]; }

    bool operator==(DBStorageIterator const& right) const { /*ASSERT(_index == right._index, "Iterator belongs to a different container")*/ return _pos == right._pos; }

    DBStorageIterator& operator++()
    {
        if (_pos < _end)
        {
            do
                ++_pos;
            while (_pos < _end && !_index[_pos]);
        }

        return *this;
    }

    DBStorageIterator operator++(int)
    {
        DBStorageIterator tmp = *this;
        ++*this;
        return tmp;
    }

private:
    value_type const* _index;
    uint32 _pos;
    uint32 _end;
};

#endif // DBStorageIterator_h__
