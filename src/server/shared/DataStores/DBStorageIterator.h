/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
class DBStorageIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    DBStorageIterator() : _index(nullptr), _pos(0), _end(0) { }
    DBStorageIterator(T** index, uint32 size, uint32 pos = 0) : _index(index), _pos(pos), _end(size)
    {
        if (_pos < _end)
        {
            while (_pos < _end && !_index[_pos])
                ++_pos;
        }
    }

    T const* operator->() { return _index[_pos]; }
    T const* operator*() { return _index[_pos]; }

    bool operator==(DBStorageIterator const& right) const { /*ASSERT(_index == right._index, "Iterator belongs to a different container")*/ return _pos == right._pos; }
    bool operator!=(DBStorageIterator const& right) const { return !(*this == right); }

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
    T** _index;
    uint32 _pos;
    uint32 _end;
};

#endif // DBStorageIterator_h__
