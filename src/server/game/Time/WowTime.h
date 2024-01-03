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

#ifndef TRINITYCORE_WOWTIME_H
#define TRINITYCORE_WOWTIME_H

#include "Define.h"
#include "Duration.h"
#include "advstd.h"
#include <compare>
#include <ctime>

class ByteBuffer;

class WowTime
{
public:
    uint32 GetPackedTime() const;
    void SetPackedTime(uint32 packedTime);

    std::time_t GetUnixTimeFromUtcTime() const;
    void SetUtcTimeFromUnixTime(std::time_t unixTime);

    int32 GetYear() const { return _year; }
    void SetYear(int32 year);

    int8 GetMonth() const { return _month; }
    void SetMonth(int8 month);

    int8 GetMonthDay() const { return _monthDay; }
    void SetMonthDay(int8 monthDay);

    int8 GetWeekDay() const { return _weekDay; }
    void SetWeekDay(int8 weekDay);

    int8 GetHour() const { return _hour; }
    void SetHour(int8 hour);

    int8 GetMinute() const { return _minute; }
    void SetMinute(int8 minute);

    int8 GetFlags() const { return _flags; }
    void SetFlags(int8 flags);

    int8 GetHolidayOffset() const { return _holidayOffset; }
    void SetHolidayOffset(int8 holidayOffset) { _holidayOffset = holidayOffset; }

    friend TC_GAME_API std::strong_ordering operator<=>(WowTime const& left, WowTime const& right);
    friend TC_GAME_API bool operator==(WowTime const& left, WowTime const& right)
    {
        return advstd::is_eq(left <=> right);
    }

    bool IsInRange(WowTime const& from, WowTime const& to) const;

    WowTime& operator+=(Seconds seconds);
    WowTime operator+(Seconds seconds) const;

    WowTime& operator-=(Seconds seconds);
    WowTime operator-(Seconds seconds) const;

    friend TC_GAME_API ByteBuffer& operator<<(ByteBuffer& data, WowTime const& wowTime);
    friend TC_GAME_API ByteBuffer& operator>>(ByteBuffer& data, WowTime& wowTime);

private:
    int32 _year = -1;
    int8 _month = -1;
    int8 _monthDay = -1;
    int8 _weekDay = -1;
    int8 _hour = -1;
    int8 _minute = -1;
    int8 _flags = -1;
    int8 _holidayOffset = 0;
};

#endif // TRINITYCORE_WOWTIME_H
