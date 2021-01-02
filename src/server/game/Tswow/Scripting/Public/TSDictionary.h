/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include <map>

template <typename K, typename V>
struct TSDictionary {
    std::map<K, V> _map;

public:
    TSDictionary() {

    }

    TSDictionary(std::initializer_list<std::pair<K, V>> list) {
        for (auto& pair : list) {
            _map.insert(pair);
        }
    }

    auto contains(K key) {
        return _map.find(key)!=_map.end();
    }

    auto get_length() {
        return _map.size();
    }

    auto get(K key)
    {
        return _map[key];
    }

    auto set(K key, V value)
    {
        _map[key] = value;
    }

    auto filter(std::function<bool(K, V)> p)
    {
        TSDictionary<K, V> dest;
        typename std::map<K, V>::iterator it;
        for (it = _map.begin(); it != _map.end(); ++it)
        {
            if (p(it->first, it->second))
            {
                dest.set(it->first, it->second);
            }
        }
        return dest;
    }

    template <typename P, typename I>
    auto reduce(P p, I initial)
    {
        I cur = initial;
        typename std::map<K, V>::iterator it;
        for (it = _map.begin(); it != _map.end(); ++it)
        {
            cur = p(cur, it->first, it->second);
        }
        return cur;
    }

    void forEach(std::function<void(K, V)> p)
    {
        typename std::map<K, V>::iterator it;
        for (it = _map.begin(); it != _map.end(); ++it)
        {
            p(it->first, it->second);
        }
    }
};

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const TSDictionary<K, V> * map)
{
    os << (*map);
    return os;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const TSDictionary<K,V> map)
{
    os << "{" << std::endl;
    uint32_t ctr = 0;
    for (auto& g : map._map) {
        if (++ctr < map._map.size())
        {
            os << "    " << g.first << ":" << g.second << "," << std::endl;
        }
        else
        {
            os << "    " << g.first << ":" << g.second << std::endl;
        }
    }
    os << "}";
    return os;
}

#define MakeDictionary TSDictionary