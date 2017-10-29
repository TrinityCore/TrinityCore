/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Containers.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Timer.h"
#include "Weather.h"

namespace WeatherMgr
{

namespace
{
    std::unordered_map<uint32, WeatherData> _weatherData;
}

WeatherData const* GetWeatherData(uint32 zone_id)
{
    return Trinity::Containers::MapGetValuePtr(_weatherData, zone_id);
}

void LoadWeatherData()
{
    uint32 oldMSTime = getMSTime();

    uint32 count = 0;

    QueryResult result = WorldDatabase.Query("SELECT "
        "zone, spring_rain_chance, spring_snow_chance, spring_storm_chance,"
        "summer_rain_chance, summer_snow_chance, summer_storm_chance,"
        "fall_rain_chance, fall_snow_chance, fall_storm_chance,"
        "winter_rain_chance, winter_snow_chance, winter_storm_chance,"
        "ScriptName FROM game_weather");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 weather definitions. DB table `game_weather` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 zone_id = fields[0].GetUInt32();

        WeatherData& wzc = _weatherData[zone_id];

        for (uint8 season = 0; season < WEATHER_SEASONS; ++season)
        {
            wzc.data[season].rainChance  = fields[season * (MAX_WEATHER_TYPE-1) + 1].GetUInt8();
            wzc.data[season].snowChance  = fields[season * (MAX_WEATHER_TYPE-1) + 2].GetUInt8();
            wzc.data[season].stormChance = fields[season * (MAX_WEATHER_TYPE-1) + 3].GetUInt8();

            if (wzc.data[season].rainChance > 100)
            {
                wzc.data[season].rainChance = 25;
                TC_LOG_ERROR("sql.sql", "Weather for zone %u season %u has wrong rain chance > 100%%", zone_id, season);
            }

            if (wzc.data[season].snowChance > 100)
            {
                wzc.data[season].snowChance = 25;
                TC_LOG_ERROR("sql.sql", "Weather for zone %u season %u has wrong snow chance > 100%%", zone_id, season);
            }

            if (wzc.data[season].stormChance > 100)
            {
                wzc.data[season].stormChance = 25;
                TC_LOG_ERROR("sql.sql", "Weather for zone %u season %u has wrong storm chance > 100%%", zone_id, season);
            }
        }

        wzc.ScriptId = sObjectMgr->GetScriptId(fields[13].GetString());

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u weather definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

} // namespace
