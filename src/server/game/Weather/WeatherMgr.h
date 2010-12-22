/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

/// \addtogroup world
/// @{
/// \file

#ifndef __WEATHERMGR_H
#define __WEATHERMGR_H

#include "Common.h"
#include "SharedDefines.h"
#include "Timer.h"
#include "Weather.h"
#include <ace/Singleton.h>

class WeatherMgr
{
    friend class ACE_Singleton<WeatherMgr, ACE_Null_Mutex>;
    WeatherMgr() {}
    ~WeatherMgr();

    public:

        void LoadWeatherData();

        Weather* FindWeather(uint32 id) const;
        Weather* AddWeather(uint32 zone_id);
        void RemoveWeather(uint32 zone_id);

        WeatherData const* GetWeatherChances(uint32 zone_id) const
        {
            WeatherZoneMap::const_iterator itr = mWeatherZoneMap.find(zone_id);
            if (itr != mWeatherZoneMap.end())
                return &itr->second;
            else
                return NULL;
        }

        void Update(uint32 diff);

        typedef UNORDERED_MAP<uint32, Weather*> WeatherMap;
        typedef UNORDERED_MAP<uint32, WeatherData> WeatherZoneMap;

    private:

        WeatherMap m_weathers;
        WeatherZoneMap mWeatherZoneMap;
};

#define sWeatherMgr ACE_Singleton<WeatherMgr, ACE_Null_Mutex>::instance()

#endif
