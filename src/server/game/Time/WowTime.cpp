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

#include "WowTime.h"
#include "ByteBuffer.h"
#include "Errors.h"
#include "Util.h"

uint32 WowTime::GetPackedTime() const
{
    return ((_year % 100) & 0x1F) << 24
        | (_month & 0xF) << 20
        | (_monthDay & 0x3F) << 14
        | (_weekDay & 0x7) << 11
        | (_hour & 0x1F) << 6
        | (_minute & 0x3F)
        | (_flags & 0x3) << 29;
}

void WowTime::SetPackedTime(uint32 packedTime)
{
    _year = (packedTime >> 24) & 0x1F;
    if (_year == 31)
        _year = -1;

    _month = (packedTime >> 20) & 0xF;
    if (_month == 15)
        _month = -1;

    _monthDay = (packedTime >> 14) & 0x3F;
    if (_monthDay == 63)
        _monthDay = -1;

    _weekDay = (packedTime >> 11) & 0x7;
    if (_weekDay == 7)
        _weekDay = -1;

    _hour = (packedTime >> 6) & 0x1F;
    if (_hour == 31)
        _hour = -1;

    _minute = packedTime & 0x3F;
    if (_minute == 63)
        _minute = -1;

    _flags = (packedTime >> 29) & 0x3;
    if (_flags == 3)
        _flags = -1;
}

std::time_t WowTime::GetUnixTimeFromUtcTime() const
{
    if (_year < 0 || _month < 0 || _monthDay < 0)
        return 0;

    std::tm buf{};
    buf.tm_year = _year + 100;
    buf.tm_mon = _month;
    buf.tm_mday = _monthDay + 1;
    if (_hour >= 0)
    {
        buf.tm_hour = _hour;
        if (_minute >= 0)
            buf.tm_min = _minute;
    }
    buf.tm_isdst = -1;
    buf.tm_wday = _weekDay;

    return timegm(&buf);
}

void WowTime::SetUtcTimeFromUnixTime(std::time_t unixTime)
{
    std::tm buf;
    if (!::gmtime_r(&unixTime, &buf))
        return;

    _year = (buf.tm_year - 100) % 100;
    _month = buf.tm_mon;
    _monthDay = buf.tm_mday - 1;
    _weekDay = buf.tm_wday;
    _hour = buf.tm_hour;
    _minute = buf.tm_min;
}

void WowTime::SetYear(int32 year)
{
    ASSERT(year == -1 || (year >= 0 && year < 32));
    _year = year;
}

void WowTime::SetMonth(int8 month)
{
    ASSERT(month == -1 || (month >= 0 && month < 12));
    _month = month;
}

void WowTime::SetMonthDay(int8 monthDay)
{
    ASSERT(monthDay == -1 || (monthDay >= 0 && monthDay < 32));
    _monthDay = monthDay;
}

void WowTime::SetWeekDay(int8 weekDay)
{
    ASSERT(weekDay == -1 || (weekDay >= 0 && weekDay < 7));
    _weekDay = weekDay;
}

void WowTime::SetHour(int8 hour)
{
    ASSERT(hour == -1 || (hour >= 0 && hour < 24));
    _hour = hour;
}

void WowTime::SetMinute(int8 minute)
{
    ASSERT(minute == -1 || (minute >= 0 && minute < 60));
    _minute = minute;
}

void WowTime::SetFlags(int8 flags)
{
    ASSERT(flags == -1 || (flags >= 0 && flags < 3));
    _flags = flags;
}

std::strong_ordering operator<=>(WowTime const& left, WowTime const& right)
{
    auto compareFieldIfSet = [&]<typename T>(T WowTime::*field) -> std::strong_ordering
    {
        if (left.*field < 0 || right.*field < 0)
            return std::strong_ordering::equal;

        return left.*field <=> right.*field;
    };

    if (std::strong_ordering cmp = compareFieldIfSet(&WowTime::_year); advstd::is_neq(cmp))
        return cmp;

    if (std::strong_ordering cmp = compareFieldIfSet(&WowTime::_month); advstd::is_neq(cmp))
        return cmp;

    if (std::strong_ordering cmp = compareFieldIfSet(&WowTime::_monthDay); advstd::is_neq(cmp))
        return cmp;

    if (std::strong_ordering cmp = compareFieldIfSet(&WowTime::_weekDay); advstd::is_neq(cmp))
        return cmp;

    if (std::strong_ordering cmp = compareFieldIfSet(&WowTime::_year); advstd::is_neq(cmp))
        return cmp;

    if (std::strong_ordering cmp = compareFieldIfSet(&WowTime::_hour); advstd::is_neq(cmp))
        return cmp;

    return std::strong_ordering::equal;
}

bool WowTime::IsInRange(WowTime const& from, WowTime const& to) const
{
    if (from > to)
        return *this >= from || *this < to;

    return *this >= from && *this < to;
}

WowTime& WowTime::operator+=(Seconds seconds)
{
    time_t unixTime = GetUnixTimeFromUtcTime();
    unixTime += seconds.count();
    SetUtcTimeFromUnixTime(unixTime);
    return *this;
}

WowTime WowTime::operator+(Seconds seconds) const
{
    return WowTime(*this) += seconds;
}

WowTime& WowTime::operator-=(Seconds seconds)
{
    time_t unixTime = GetUnixTimeFromUtcTime();
    unixTime -= seconds.count();
    SetUtcTimeFromUnixTime(unixTime);
    return *this;
}

WowTime WowTime::operator-(Seconds seconds) const
{
    return WowTime(*this) -= seconds;
}

ByteBuffer& operator<<(ByteBuffer& data, WowTime const& wowTime)
{
    data << uint32(wowTime.GetPackedTime());
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WowTime& wowTime)
{
    uint32 packedTime = 0;
    data >> packedTime;
    wowTime.SetPackedTime(packedTime);
    return data;
}
