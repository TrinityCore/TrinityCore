/*
 * Copyright (C) 2021 tswow <https://github.com/tswow/>
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

#include <iostream>
#include <map>
#include <set>
#include <string>

template <typename T>
struct DBMapEntry {
  DBMapEntry() = default;
  DBMapEntry(T value, bool dirty) :
    _value(value),
    _dirty(dirty) {}
  T _value;
  bool _dirty;
};

template <typename K, typename V>
class TSDBDict {
public:
  TSDBDict<K, V>* operator->() { return this; }
  void set_silent(K key, V value)
  {
    _map[key] = DBMapEntry<V>(value, false);
  }

  void set(K key, V value)
  {
    auto itr = _map.find(key);
    if (itr == _map.end())
    {
      _map.insert(std::make_pair(key, DBMapEntry<V>(value, true)));
    }
    else
    {
      itr->second._dirty = true;
      itr->second._value = value;
    }
    _erases.erase(key);
  }

  V get(K key)
  {
    return _map.find(key)->second._value;
  }

  void erase(K key)
  {
    _map.erase(key);
    _erases.insert(key);
  }

  bool contains(K key)
  {
    return _map.find(key) == _map.end();
  }

  void clear()
  {
    _erases.clear();
    for (auto& val : _map)
    {
      val.second._dirty = false;
    }
  }

  auto map_begin()
  {
    return _map.begin();
  }

  auto map_end()
  {
    return _map.end();
  }

  auto erases_begin()
  {
    return _erases.begin();
  }

  auto erases_end()
  {
    return _erases.end();
  }

  TSString stringify(int indention = 0) {
    std::string str = "";
    for (int i = 0; i < indention; ++i) str += " ";
    str += "{\n";
    for (auto& itr : _map)
    {
      for (int i = 0; i < indention+4; ++i) str += " ";
      str += stritem(itr.first) + ": " + stritem(itr.second._value)+ ",";
      str += "\n";
    }
    for (int i = 0; i < indention; ++i) str += " ";
    str += "}\n";
    return JSTR(str);
  }
private:
  std::map<K, DBMapEntry<V>> _map;
  std::set<K> _erases;

  std::string stritem(std::string v) { return v; }
  template <typename T>
  std::string stritem(T v) { return std::to_string(v); }
};

template <typename K, typename V>
TSDBDict<K, V> MakeDBDict()
{
  return TSDBDict<K, V>();
}