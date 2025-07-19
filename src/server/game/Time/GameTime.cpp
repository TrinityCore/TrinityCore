/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information

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

#include "GameTime.h"
#include "Timer.h"
#include "Timezone.h"
#include "Util.h"
#include "WowTime.h"

namespace GameTime
{
    time_t const StartTime = time(nullptr);

    time_t GameTime = time(nullptr);
    uint32 GameMSTime = 0;

    SystemTimePoint GameTimeSystemPoint = SystemTimePoint::min();
    TimePoint GameTimeSteadyPoint = TimePoint::min();

    tm DateTime;

    WowTime UtcWow;
    WowTime Wow;

    time_t GetStartTime()
    {
        return StartTime;
    }

    time_t GetGameTime()
    {
        return GameTime;
    }

    uint32 GetGameTimeMS()
    {
        return GameMSTime;
    }

    SystemTimePoint GetSystemTime()
    {
        return GameTimeSystemPoint;
    }

    TimePoint Now()
    {
        return GameTimeSteadyPoint;
    }

    template<typename Clock>
    typename Clock::time_point GetTime()
    {
        static_assert(!std::is_same<Clock, Clock>::value, "Missing specialization for GetGameTimePoint");
    }

    template<>
    SystemTimePoint GetTime<std::chrono::system_clock>()
    {
        return GetSystemTime();
    }

    template<>
    TimePoint GetTime<std::chrono::steady_clock>()
    {
        return Now();
    }

    uint32 GetUptime()
    {
        return uint32(GameTime - StartTime);
    }

    tm const* GetDateAndTime()
    {
        return &DateTime;
    }

    WowTime const* GetUtcWowTime()
    {
        return &UtcWow;
    }

    WowTime const* GetWowTime()
    {
        return &Wow;
    }

    void UpdateGameTimers()
    {
        GameTime = time(nullptr);
        GameMSTime = getMSTime();
        GameTimeSystemPoint = std::chrono::system_clock::now();
        GameTimeSteadyPoint = std::chrono::steady_clock::now();
        localtime_r(&GameTime, &DateTime);
        UtcWow.SetUtcTimeFromUnixTime(GameTime);
        Wow = UtcWow + Trinity::Timezone::GetSystemZoneOffsetAt(GameTimeSystemPoint);
    }
}
