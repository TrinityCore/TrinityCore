/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>

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

GameTime* GameTime::instance()
{
    static GameTime instance;
    return &instance;
}

time_t GameTime::GetStartTime() const
{
    return _startTime;
}

time_t GameTime::GetGameTime() const
{
    return _gameTime;
}

uint32 GameTime::GetGameTimeMS() const
{
    return _gameMSTime;
}

std::chrono::system_clock::time_point GameTime::GetGameTimeSystemPoint() const
{
    return _gameTimeSystemPoint;
}

std::chrono::steady_clock::time_point GameTime::GetGameTimeSteadyPoint() const
{
    return _gameTimeSteadyPoint;
}

uint32 GameTime::GetUptime() const
{
    return uint32(_gameTime - _startTime);
}

void GameTime::UpdateGameTimers()
{
    _gameTime = time(nullptr);
    _gameMSTime = getMSTime();
    _gameTimeSystemPoint = std::chrono::system_clock::now();
    _gameTimeSteadyPoint = std::chrono::steady_clock::now();
}

void GameTime::SetStartTime()
{
    _startTime = _gameTime;
}
