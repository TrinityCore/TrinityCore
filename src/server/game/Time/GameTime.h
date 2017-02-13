/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Timer.h"

#include <chrono>

class TC_GAME_API GameTime
{
    public:
        GameTime();

        static GameTime* instance();

        // Server start time
        time_t GetStartTime() const;

        // Current server time (unix) in seconds
        time_t GetGameTime() const;

        // Milliseconds since server start
        uint32 GetGameTimeMS() const;

        /// Current chrono system_clock time point
        std::chrono::system_clock::time_point GetGameTimeSystemPoint() const;

        /// Current chrono steady_clock time point
        std::chrono::steady_clock::time_point GetGameTimeSteadyPoint() const;

        /// Uptime (in secs)
        uint32 GetUptime() const;

        void UpdateGameTimers();
        void SetStartTime();

    private:
        // Game Time
        time_t _startTime;
        time_t _gameTime;
        uint32 _gameMSTime;
        std::chrono::system_clock::time_point _gameTimeSystemPoint;
        std::chrono::steady_clock::time_point _gameTimeSteadyPoint;
};

#define sGameTime GameTime::instance()

#endif
