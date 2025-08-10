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

#ifndef __GAMETIME_H
#define __GAMETIME_H

#include "Define.h"
#include "Duration.h"

class WowTime;

namespace GameTime
{
    // Server start time
    TC_GAME_API time_t GetStartTime();

    // Current server time (unix) in seconds
    TC_GAME_API time_t GetGameTime();

    // Milliseconds since server start
    TC_GAME_API uint32 GetGameTimeMS();

    /// Current chrono system_clock time point
    TC_GAME_API SystemTimePoint GetSystemTime();

    /// Current chrono steady_clock time point
    TC_GAME_API TimePoint Now();

    /// Current chrono Clock time point
    template<typename Clock>
    typename Clock::time_point GetTime();

    /// Uptime (in secs)
    TC_GAME_API uint32 GetUptime();

    TC_GAME_API tm const* GetDateAndTime();

    TC_GAME_API WowTime const* GetUtcWowTime();

    TC_GAME_API WowTime const* GetWowTime();

    void UpdateGameTimers();

    template<> TC_GAME_API SystemTimePoint GetTime<std::chrono::system_clock>();
    template<> TC_GAME_API TimePoint GetTime<std::chrono::steady_clock>();
}

#endif
