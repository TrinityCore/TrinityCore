#ifndef CACHE_H
#define CACHE_H
#include <string>
#include "Common.h"

class WorldModelRoot;
class Model;

template<class T>
class GenericCache
{
public:
    GenericCache() {}

    static const int32 FlushLimit = 1000;
    
    void Insert(std::string key, T* val)
    {
        if (_items.size() > FlushLimit)
            Clear();
        _items.insert(key, val);
    }

    T* Get(std::string key)
    {
        UNORDERED_MAP<std::string, T*>::iterator itr = _items.find(key);
        if (itr != _items.end())
            return itr->second;
        return NULL;
    }

    void Clear() { _items.clear(); }
private:
    UNORDERED_MAP<std::string, T*> _items;
};

class CacheClass
{
public:
    CacheClass() {}
    GenericCache<Model> ModelCache;
    GenericCache<WorldModelRoot> WorldModelCache;
};

extern CacheClass* Cache;
#endif