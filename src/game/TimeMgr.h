/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _TIMEMGR_H
#define _TIMEMGR_H

#include "Timer.h"
#include "Policies/Singleton.h"

struct IntervalTimer
{
    public:
        IntervalTimer() : _interval(0), _current(0) {}

        void Update(time_t diff) { _current += diff; if(_current<0) _current=0;}
        bool Passed() { return _current >= _interval; }
        void Reset() { if(_current >= _interval) _current -= _interval;  }

        void SetCurrent(time_t current) { _current = current; }
        void SetInterval(time_t interval) { _interval = interval; }
        time_t GetInterval() const { return _interval; }
        time_t GetCurrent() const { return _current; }

    private:
        time_t _interval;
        time_t _current;
};

template <typename T> struct TimeTrack
{
    public:
        TimeTrack(T expire) : i_expireTime(expire) {}
        void Update(T diff) { i_expireTime -= diff; }
        bool Passed(void) const { return (i_expireTime <= 0); }
        void Reset(T interval) { i_expireTime = interval; }
        T GetExpireTime(void) const { return i_expireTime; }
    private:
        T i_expireTime;
};

typedef TimeTrack<time_t> TimeTracker;
typedef TimeTrack<int32> TimeTrackerSmall;

struct PeriodicTimer
{
    public:
        PeriodicTimer(int32 period, int32 start_time) :
            i_expireTime(start_time), i_period(period) {}

        bool Update(const uint32 &diff);
        void SetPeriodic(int32 period, int32 start_time);

    private:
        int32 i_period;
        int32 i_expireTime;
};

class GameTime
{
    public:
        /// When server started?
        time_t const& GetStartTime() const { return m_startTime; }
        /// What time is it?
        time_t const& GetGameTime() const { return m_gameTime; }
        /// Uptime (in secs)
        uint32 GetUptime() const { return uint32(m_gameTime - m_startTime); }

        void SetGameTime(void) { m_gameTime  = time(NULL); }
        void SetStartTime(void){ m_startTime = time(NULL); }
    private:
        time_t m_gameTime;
        time_t m_startTime;
};

#define sGameTime Trinity::Singleton<GameTime>::Instance()

#endif
