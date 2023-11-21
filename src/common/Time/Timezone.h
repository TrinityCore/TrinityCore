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

#ifndef TRINITYCORE_TIMEZONE_H
#define TRINITYCORE_TIMEZONE_H

#include "Define.h"
#include "Duration.h"
#include <string>

namespace Trinity::Timezone
{
TC_COMMON_API Minutes GetOffsetByHash(uint32 hash);

// Returns the time offset that must be added to UTC time to get localtime
TC_COMMON_API Minutes GetSystemZoneOffsetAt(SystemTimePoint date);
TC_COMMON_API Minutes GetSystemZoneOffset(bool applyDst = true);

TC_COMMON_API std::string GetSystemZoneName();

TC_COMMON_API std::string_view FindClosestClientSupportedTimezone(std::string_view currentTimezone, Minutes currentTimezoneOffset);
}

#endif // TRINITYCORE_TIMEZONE_H
