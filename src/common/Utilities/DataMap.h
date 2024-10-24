/*
 * Originally written by Rochet2 - Copyright (C) 2018+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: http://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 * Touched up by SPP MDic for 335 TC Master
 */

#ifndef _DATA_MAP_H_
#define _DATA_MAP_H_

#include <string>
#include <unordered_map>
#include <memory>
#include <type_traits>

class DataMap
{
public:
        /**
         * Base class that you should inherit in your script.
         * Inheriting classes can be stored to DataMap
         */
class Base
{
    public:
    virtual ~Base() = default;
};

/**
 * Returns a pointer to object of requested type stored with given key or nullptr
 */
template<class T> T * Get(std::string const& k) const
{
static_assert(std::is_base_of<Base, T>::value, "T must derive from Base");
if (Container.empty())
     return nullptr;

    auto it = Container.find(k);
if (it != Container.end())
     return dynamic_cast<T*>(it->second.get());
return nullptr;

}

/**
 * Returns a pointer to object of requested type stored with given key
 * or default constructs one and returns that one
 */

template<class T, typename std::enable_if<std::is_default_constructible<T>::value, int>::type = 0>
T * GetDefault(std::string const& k)
{
static_assert(std::is_base_of<Base, T>::value, "T must derive from Base");
if (T* v = Get<T>(k))
     return v;
T * v = new T();
Container.emplace(k, std::unique_ptr<T>(v));
return v;

}

/**
 * Stores a new object that inherits the Base class with the given key
 */
void Set(std::string const& k, Base * v) { Container[k] = std::unique_ptr<Base>(v); }

/**
 * Removes objects with given key and returns true if one was removed, false otherwise
 */

bool Erase(std::string const& k) { return Container.erase(k) != 0; }

private:
    std::unordered_map<std::string, std::unique_ptr<Base>> Container;
};

#endif