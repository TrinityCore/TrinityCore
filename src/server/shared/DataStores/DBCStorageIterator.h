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

#ifndef DBCStorageIterator_h__
#define DBCStorageIterator_h__

#include "Define.h"
#include <iterator>

template <class T>
class DBCStorageIterator : public std::iterator<std::forward_iterator_tag, T>
{
    public:
        DBCStorageIterator() : _index(nullptr), _pos(0), _end(0) { }
        DBCStorageIterator(T** index, uint32 size, uint32 pos = 0) : _index(index), _pos(pos), _end(size)
        {
            if (_pos < _end)
            {
                while (_pos < _end && !_index[_pos])
                    ++_pos;
            }
        }

        T const* operator->() { return _index[_pos]; }
        T const* operator*() { return _index[_pos]; }

        bool operator==(DBCStorageIterator const& right) const { /*ASSERT(_index == right._index, "Iterator belongs to a different container")*/ return _pos == right._pos; }
        bool operator!=(DBCStorageIterator const& right) const { return !(*this == right); }

        DBCStorageIterator& operator++()
        {
            if (_pos < _end)
            {
                do
                    ++_pos;
                while (_pos < _end && !_index[_pos]);
            }

            return *this;
        }

        DBCStorageIterator operator++(int)
        {
            DBCStorageIterator tmp = *this;
            ++*this;
            return tmp;
        }

    private:
        T** _index;
        uint32 _pos;
        uint32 _end;
};

#endif // DBCStorageIterator_h__
