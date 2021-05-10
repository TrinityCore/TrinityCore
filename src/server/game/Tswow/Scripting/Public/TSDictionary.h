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
#include <iostream>
#include "TSArray.h"
#include "TSString.h"

struct TSString;

template <typename K, typename V>
struct TSDictionary {
  std::shared_ptr<std::map<K, V>> _map;
public:
  TSDictionary() {
    _map = std::make_shared<std::map<K, V>>();
  }

  TSDictionary(std::initializer_list<std::pair<K, V>> list) {
    _map = std::make_shared<std::map<K, V>>();
    for (auto& item : list)
    {
      _map->insert(item);
    }
  }

  template <typename T>
  bool operator ==(T value) { return _map == value; }

  operator bool() { return _map == nullptr; }

  auto& operator[](K index) const {
    return (*_map)[index];
  }

  auto& operator[](K index) {
    return (*_map)[index];
  }

  auto contains(K key) {
    return _map->find(key) != _map->end();
  }

  auto get_length() {
    return _map->size();
  }

  auto get(K key)
  {
    return (*_map)[key];
  }

  auto set(K key, V value)
  {
    (*_map)[key] = value;
  }

  constexpr TSDictionary* operator->()
  {
    return this;
  }

  TSArray<K> keys()
  {
    TSArray<K> array;
    typename std::map<K, V>::iterator it;
    for (it = _map->begin(); it != _map->end(); ++it)
    {
      array.push(it->first);
    }
    return array;
  }

  auto filter(std::function<bool(K, V)> p)
  {
    TSDictionary<K, V> dest;
    typename std::map<K, V>::iterator it;
    for (it = _map->begin(); it != _map->end(); ++it)
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
    for (it = _map->begin(); it != _map->end(); ++it)
    {
      cur = p(cur, it->first, it->second);
    }
    return cur;
  }

  void forEach(std::function<void(K, V)> p)
  {
    typename std::map<K, V>::iterator it;
    for (it = _map->begin(); it != _map->end(); ++it)
    {
      p(it->first, it->second);
    }
  }

  TSString stringify(int indention = 0) 
  {
    TSString str = JSTR("{");
    if (get_length() > 0)
    {
      str = str + JSTR("\n");
    }

    unsigned int ctr = 0;
    for (auto& e : *_map)
    {
      if (++ctr >= get_length())
      {
        str += spaces(indention+1) + ToStr(e.first, indention+1) + JSTR(":") + ToStr(e.second,indention+1) + JSTR("\n");
      }
      else
      {
        str += spaces(indention+1) + ToStr(e.first,indention+1) + JSTR(":") + ToStr(e.second,indention+1) + JSTR(",\n");
      }
    }
    return str + spaces(indention)+JSTR("}");
  }

  friend std::ostream& operator<<(std::ostream& os, TSDictionary<K,V> arr)
  {
    os << arr.stringify().c_str();
    return os;
  }

  friend std::ostream& operator<<(std::ostream& os, TSDictionary<K,V>* arr)
  {
    os << (*arr);
    return os;
  }

};

#define MakeDictionary TSDictionary