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

/** \file
    \ingroup world
*/

#include "WeatherMgr.h"
#include "Log.h"
#include "ObjectMgr.h"

WeatherMgr::~WeatherMgr()
{
    ///- Empty the WeatherMap
    for (WeatherMap::const_iterator itr = m_weathers.begin(); itr != m_weathers.end(); ++itr)
        delete itr->second;

    m_weathers.clear();
}

/// Find a Weather object by the given zoneid
Weather* WeatherMgr::FindWeather(uint32 id) const
{
    WeatherMap::const_iterator itr = m_weathers.find(id);

    if (itr != m_weathers.end())
        return itr->second;
    else
        return 0;
}

/// Remove a Weather object for the given zoneid
void WeatherMgr::RemoveWeather(uint32 id)
{
    // not called at the moment. Kept for completeness
    WeatherMap::iterator itr = m_weathers.find(id);

    if (itr != m_weathers.end())
    {
        delete itr->second;
        m_weathers.erase(itr);
    }
}

/// Add a Weather object to the list
Weather* WeatherMgr::AddWeather(uint32 zone_id)
{
    WeatherData const* weatherChances = GetWeatherChances(zone_id);

    // zone not have weather, ignore
    if (!weatherChances)
        return NULL;

    Weather* w = new Weather(zone_id,weatherChances);
    m_weathers[w->GetZone()] = w;
    w->ReGenerate();
    w->UpdateWeather();
    return w;
}

void WeatherMgr::LoadWeatherData()
{
    uint32 oldMSTime = getMSTime();

    uint32 count = 0;

    //                                                0     1                   2                   3                    4                   5                   6                    7                 8                 9                  10                  11                  12                                13
    QueryResult result = WorldDatabase.Query("SELECT zone, spring_rain_chance, spring_snow_chance, spring_storm_chance, summer_rain_chance, summer_snow_chance, summer_storm_chance, fall_rain_chance, fall_snow_chance, fall_storm_chance, winter_rain_chance, winter_snow_chance, winter_storm_chance, ScriptName FROM game_weather");

    if (!result)
    {
        sLog.outErrorDb(">> Loaded 0 weather definitions. DB table `game_weather` is empty.");
        sLog.outString();
        return;
    }


    do
    {
        Field *fields = result->Fetch();

        uint32 zone_id = fields[0].GetUInt32();

        WeatherData& wzc = mWeatherZoneMap[zone_id];

        for (uint8 season = 0; season < WEATHER_SEASONS; ++season)
        {
            wzc.data[season].rainChance  = fields[season * (MAX_WEATHER_TYPE-1) + 1].GetUInt32();
            wzc.data[season].snowChance  = fields[season * (MAX_WEATHER_TYPE-1) + 2].GetUInt32();
            wzc.data[season].stormChance = fields[season * (MAX_WEATHER_TYPE-1) + 3].GetUInt32();

            if (wzc.data[season].rainChance > 100)
            {
                wzc.data[season].rainChance = 25;
                sLog.outErrorDb("Weather for zone %u season %u has wrong rain chance > 100%%",zone_id,season);
            }

            if (wzc.data[season].snowChance > 100)
            {
                wzc.data[season].snowChance = 25;
                sLog.outErrorDb("Weather for zone %u season %u has wrong snow chance > 100%%",zone_id,season);
            }

            if (wzc.data[season].stormChance > 100)
            {
                wzc.data[season].stormChance = 25;
                sLog.outErrorDb("Weather for zone %u season %u has wrong storm chance > 100%%",zone_id,season);
            }
        }

        wzc.ScriptId = sObjectMgr.GetScriptId(fields[13].GetCString());

        ++count;
    }
    while (result->NextRow());

    sLog.outString(">> Loaded %u weather definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    sLog.outString();
}

void WeatherMgr::Update(uint32 diff)
{
    ///- Send an update signal to Weather objects
    WeatherMap::iterator itr, next;
    for (itr = m_weathers.begin(); itr != m_weathers.end(); itr = next)
    {
        next = itr;
        ++next;

        ///- and remove Weather objects for zones with no player
                                                        //As interval > WorldTick
        if (!itr->second->Update(diff))
        {
            delete itr->second;
            m_weathers.erase(itr);
        }
    }
}
