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

    static const uint32 FlushLimit = 300;

    void Insert(K key, T* val)
    {
        ACE_GUARD(ACE_Thread_Mutex, g, mutex);
        if (_items.find(key) != _items.end()) // Make sure that the object isn't in the cache already
            delete _items[key]; // Delete the previous item
        _items[key] = val; // Reassign it
    }

    T* Get(K key)
    {
        ACE_GUARD_RETURN(ACE_Thread_Mutex, g, mutex, NULL);
        typename std::map<K, T*>::iterator itr = _items.find(key);
        if (itr != _items.end())
            return itr->second;
        else
        {
            T* t = new T(key); // Create the object
            _items[key] = t;
            return t;
        }
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
