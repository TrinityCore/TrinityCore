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

#ifndef TRINITYCORE_DURATION_H
#define TRINITYCORE_DURATION_H

#include <chrono>

/// Milliseconds shorthand typedef.
using Milliseconds = std::chrono::milliseconds;
using FloatMilliseconds = std::chrono::duration<float, Milliseconds::period>;

/// Seconds shorthand typedef.
using Seconds = std::chrono::seconds;
using FloatSeconds = std::chrono::duration<float, Seconds::period>;

/// Minutes shorthand typedef.
using Minutes = std::chrono::minutes;
using FloatMinutes = std::chrono::duration<float, Minutes::period>;

/// Hours shorthand typedef.
using Hours = std::chrono::hours;
using FloatHours = std::chrono::duration<float, Hours::period>;

/// time_point shorthand typedefs
typedef std::chrono::steady_clock::time_point TimePoint;
typedef std::chrono::system_clock::time_point SystemTimePoint;

/// Makes std::chrono_literals globally available.
using namespace std::chrono_literals;

constexpr std::chrono::days operator""_days(unsigned long long days)
{
    return std::chrono::days(days);
}

#endif // TRINITYCORE_DURATION_H
