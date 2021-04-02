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
#include <string>
#include <memory>
#include <cstdint>
#include <functional>
#include "TSString.h"

#define GetDBObject GetObject

struct TC_GAME_API TSStorageContainer {
    uint32_t modid;
    std::shared_ptr<void> ptr;
    TSStorageContainer(uint32_t modid, std::shared_ptr<void> ptr)
    {
        this->modid= modid;
        this->ptr = ptr;
    }

    TSStorageContainer()
    {
        modid = 0;
        ptr = nullptr;
    }
};

struct TC_GAME_API TSStorage {
    std::map<std::string, TSStorageContainer> map;
    std::map<std::string, int32_t> ints;
    std::map<std::string, uint32_t> uints;
    std::map<std::string, std::string> strings;
    std::map<std::string, double> floats;

    TSStorage* operator->(){return this;}

    template <typename T>
    std::shared_ptr<T> SetObject(uint32_t modid, TSString key, std::shared_ptr<T> item)
    {
        map[key.std_str()] = TSStorageContainer(modid, std::static_pointer_cast<void>(item));
        return item;
    }

    uint32_t SetUInt(TSString key, uint32_t value)
    {
        uints[key.std_str()] = value;
        return value;
    }

    bool HasUInt(TSString key)
    {
        return uints.find(key.std_str()) != uints.end();
    }

    uint32_t GetUInt(TSString key, uint32_t def = 0)
    {
        auto itr = uints.find(key.std_str());
        if(itr == uints.end())
        {
            return def;
        }
        return itr->second;
    }

    int32_t SetInt(TSString key, int32_t value)
    {
        ints[key.std_str()] = value;
        return value;
    }

    bool HasInt(TSString key)
    {
        return ints.find(key.std_str()) != ints.end();
    }

    int32_t GetInt(TSString key, int32_t def = 0)
    {
        auto itr = ints.find(key.std_str());
        if(itr == ints.end())
        {
            return def;
        }

        return itr->second;
    }

    TSString GetString(TSString key, TSString def = JSTR(""))
    {
        auto itr = strings.find(key.std_str());
        if(itr == strings.end())
        {
            return def;
        }
        return JSTR(itr->second);
    }

    bool HasString(TSString key)
    {
        return strings.find(key.std_str()) != strings.end();
    }

    TSString SetString(TSString key, TSString value)
    {
        strings[key.std_str()] = value.std_str();
        return value;
    }

    double SetFloat(TSString key, double value)
    {
        floats[key.std_str()] = value;
        return value;
    }

    bool HasFloat(TSString key)
    {
        return floats.find(key.std_str()) != floats.end();
    }

    double GetFloat(TSString key, float def = 0)
    {
        auto itr = floats.find(key);
        if(itr == floats.end())
        {
            return def;
        }
        return itr->second;
    }

    bool HasObject(uint32_t modid, TSString key)
    {
        return map.find(key) != map.end();
    }

    template <typename T>
    std::shared_ptr<T> GetObject(uint32_t modid, TSString key, std::function<std::shared_ptr<T>()> defaultValue = nullptr)
    {
        auto itr = map.find(key);
        if(itr == map.end())
        {
            return SetObject(modid,key,defaultValue());
        }
        else
        {
            return std::static_pointer_cast<T>(itr->second.ptr);
        }
    }
};
