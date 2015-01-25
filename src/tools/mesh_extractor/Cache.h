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

#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <map>
#include "Define.h"
#include <ace/Guard_T.h>
#include <ace/Synch.h>
#include "WorldModelRoot.h"
#include "Model.h"

template<class K, class T>
class GenericCache
{
public:
    GenericCache() {}

    static const uint32 FlushLimit = 300; // We can't get too close to filling up all the memory, and we have to be wary of the maximum number of open streams.

    void Insert(K key, T* val)
    {
        ACE_GUARD(ACE_Thread_Mutex, g, mutex);

        if (_items.size() > FlushLimit)
            Clear();
        _items[key] = val;
    }

    T* Get(K key)
    {
        ACE_GUARD_RETURN(ACE_Thread_Mutex, g, mutex, NULL);
        typename std::map<K, T*>::iterator itr = _items.find(key);
        if (itr != _items.end())
            return itr->second;
        return NULL;
    }

    void Clear()
    {
        for (typename std::map<K, T*>::iterator itr = _items.begin(); itr != _items.end(); ++itr)
            delete itr->second;
        _items.clear();
    }
private:
    std::map<K, T*> _items;
    ACE_Thread_Mutex mutex;
};

class CacheClass
{
public:
    CacheClass() {}
    GenericCache<std::string, Model> ModelCache;
    GenericCache<std::string, WorldModelRoot> WorldModelCache;

    void Clear()
    {
        ModelCache.Clear();
        WorldModelCache.Clear();
    }
};

extern CacheClass* Cache;
#endif
