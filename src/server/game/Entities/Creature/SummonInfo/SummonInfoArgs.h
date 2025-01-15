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

#ifndef _SummonInfoArgs_h__
#define _SummonInfoArgs_h__

#include "Define.h"
#include "Duration.h"
#include "Optional.h"
#include "ObjectGuid.h"

struct SummonPropertiesEntry;

// Controls the behavior of a summoned creature and must be set with extreme care. If you want a blank summon that just exists as a permanent spawn, leave all fields untouched
struct SummonInfoArgs
{
    Optional<ObjectGuid> SummonerGUID;
    Optional<uint64> MaxHealth;
    Optional<Milliseconds> Duration;
    Optional<uint32> SummonPropertiesID;
};

#endif // _SummonInfoArgs_h__
