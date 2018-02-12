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
 
#ifndef TRINITY_MEMORYOF_H
#define TRINITY_MEMORYOF_H

#include "Errors.h"
#include "Object.h"
#include <type_traits>

class Object;

template <typename OBJ>
struct MemoryOf : public ObjectGuid
{
    /*static_assert(std::is_base_of<Object, OBJ>::value, "Invalid MemoryOf declaration!");*/

    MemoryOf() : ObjectGuid(), _obj(nullptr) {}
    MemoryOf(OBJ* obj) : ObjectGuid(obj ? obj->GetGUID() : ObjectGuid::Empty), _obj(obj) {}

    OBJ* unchecked_ptr() const { return _obj; }

    explicit operator bool() const { return _obj != nullptr; }
    operator OBJ*() const { return unchecked_ptr(); }

    OBJ* operator*() const { return ASSERT_NOTNULL(unchecked_ptr()); }
    OBJ* operator->() const { return operator*(); }

    void operator=(OBJ* obj) { _obj = obj; }

    void Set(OBJ* obj)
    {
        if (obj)
            ObjectGuid::Set(obj->GetGUID());
        else
            ObjectGuid::Clear();
        _obj = obj;
    }

    private:
        OBJ * _obj;
};

#endif
