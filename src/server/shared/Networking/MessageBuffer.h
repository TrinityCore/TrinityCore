/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __MESSAGEBUFFER_H_
#define __MESSAGEBUFFER_H_

#include "Define.h"
#include <vector>

class MessageBuffer
{
    typedef std::vector<uint8>::size_type size_type;

public:
    MessageBuffer() : _wpos(0), _storage() { }

    MessageBuffer(MessageBuffer const& right) : _wpos(right._wpos), _storage(right._storage) { }

    MessageBuffer(MessageBuffer&& right) : _wpos(right._wpos), _storage(right.Move()) { }

    void Reset()
    {
        _storage.clear();
        _wpos = 0;
    }

    bool IsMessageReady() const { return _wpos == _storage.size(); }

    size_type GetMissingSize() const { return _storage.size() - _wpos; }

    uint8* Data() { return _storage.data(); }

    void Grow(size_type bytes)
    {
        _storage.resize(_storage.size() + bytes);
    }

    uint8* GetWritePointer() { return &_storage[_wpos]; }

    void WriteCompleted(size_type bytes) { _wpos += bytes; }

    void ResetWritePointer() { _wpos = 0; }

    size_type GetSize() const { return _storage.size(); }

    std::vector<uint8>&& Move()
    {
        _wpos = 0;
        return std::move(_storage);
    }

    MessageBuffer& operator=(MessageBuffer& right)
    {
        if (this != &right)
        {
            _wpos = right._wpos;
            _storage = right._storage;
        }

        return *this;
    }

    MessageBuffer& operator=(MessageBuffer&& right)
    {
        if (this != &right)
        {
            _wpos = right._wpos;
            _storage = right.Move();
        }

        return *this;
    }

private:
    size_type _wpos;
    std::vector<uint8> _storage;
};

#endif /* __MESSAGEBUFFER_H_ */
