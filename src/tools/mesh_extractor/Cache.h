#ifndef CACHE_H
#define CACHE_H
#include <string>
#include <map>
#include "Common.h"

class WorldModelRoot;
class Model;
class ADT;

template<class K, class T>
class GenericCache
{
public:
    GenericCache() {}

    static const int32 FlushLimit = 1000;
    
    void Insert(K key, T* val)
    {
        if (_items.size() > FlushLimit)
            Clear();
        _items[key] = val;
    }

    T* Get(K key)
    {
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
};

class CacheClass
{
public:
    CacheClass() {}
    GenericCache<std::string, Model> ModelCache;
    GenericCache<std::string, WorldModelRoot> WorldModelCache;
    GenericCache<std::pair<int32,int32>, ADT> AdtCache;
    void Clear()
    {
        AdtCache.Clear();
    }
};

extern CacheClass* Cache;
#endif