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

#ifndef TRINITY_OBJECTDEFINES_H
#define TRINITY_OBJECTDEFINES_H

#include "Define.h"

#define CONTACT_DISTANCE                    0.5f
#define INTERACTION_DISTANCE                5.0f
#define ATTACK_DISTANCE                     5.0f
#define INSPECT_DISTANCE                    28.0f
#define TRADE_DISTANCE                      11.11f
#define MAX_VISIBILITY_DISTANCE             SIZE_OF_GRIDS           // max distance for visible objects
#define SIGHT_RANGE_UNIT                    50.0f
#define VISIBILITY_DISTANCE_GIGANTIC        400.0f
#define VISIBILITY_DISTANCE_LARGE           200.0f
#define VISIBILITY_DISTANCE_NORMAL          100.0f
#define VISIBILITY_DISTANCE_SMALL           50.0f
#define VISIBILITY_DISTANCE_TINY            25.0f
#define DEFAULT_VISIBILITY_DISTANCE         VISIBILITY_DISTANCE_NORMAL            // default visible distance, 100 yards on continents
#define DEFAULT_VISIBILITY_INSTANCE         170.0f                  // default visible distance in instances, 170 yards
#define DEFAULT_VISIBILITY_BGARENAS         533.0f                  // default visible distance in BG/Arenas, roughly 533 yards

#define DEFAULT_PLAYER_BOUNDING_RADIUS      0.388999998569489f     // player size, also currently used (correctly?) for any non Unit world objects
#define DEFAULT_PLAYER_COMBAT_REACH         1.5f
#define MIN_MELEE_REACH                     2.0f
#define NOMINAL_MELEE_RANGE                 5.0f
#define MELEE_RANGE                         (NOMINAL_MELEE_RANGE - MIN_MELEE_REACH * 2) //center to center for players

enum class VisibilityDistanceType : uint8
{
    Normal = 0,
    Tiny = 1,
    Small = 2,
    Large = 3,
    Gigantic = 4,
    Infinite = 5,

    Max
};

enum TempSummonType
{
    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN       = 1,             // despawns after a specified time OR when the creature disappears
    TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN     = 2,             // despawns after a specified time OR when the creature dies
    TEMPSUMMON_TIMED_DESPAWN               = 3,             // despawns after a specified time
    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT = 4,             // despawns after a specified time after the creature is out of combat
    TEMPSUMMON_CORPSE_DESPAWN              = 5,             // despawns instantly after death
    TEMPSUMMON_CORPSE_TIMED_DESPAWN        = 6,             // despawns after a specified time after death
    TEMPSUMMON_DEAD_DESPAWN                = 7,             // despawns when the creature disappears
    TEMPSUMMON_MANUAL_DESPAWN              = 8              // despawns when UnSummon() is called
};

enum PhaseMasks
{
    PHASEMASK_NORMAL   = 0x00000001,
    PHASEMASK_ANYWHERE = 0xFFFFFFFF
};

enum NotifyFlags
{
    NOTIFY_NONE                     = 0x00,
    NOTIFY_AI_RELOCATION            = 0x01,
    NOTIFY_VISIBILITY_CHANGED       = 0x02,
    NOTIFY_ALL                      = 0xFF
};

enum GOSummonType
{
   GO_SUMMON_TIMED_OR_CORPSE_DESPAWN = 0,    // despawns after a specified time OR when the summoner dies
   GO_SUMMON_TIMED_DESPAWN = 1     // despawns after a specified time
};

inline uint64 MAKE_PAIR64(uint32 l, uint32 h)
{
    return uint64(l | (uint64(h) << 32));
}

inline uint32 PAIR64_HIPART(uint64 x)
{
    return (uint32)((x >> 32) & UI64LIT(0x00000000FFFFFFFF));
}

inline uint32 PAIR64_LOPART(uint64 x)
{
    return (uint32)(x & UI64LIT(0x00000000FFFFFFFF));
}

inline uint16 MAKE_PAIR16(uint8 l, uint8 h)
{
    return uint16(l | (uint16(h) << 8));
}

inline uint32 MAKE_PAIR32(uint16 l, uint16 h)
{
    return uint32(l | (uint32(h) << 16));
}

inline uint16 PAIR32_HIPART(uint32 x)
{
    return (uint16)((x >> 16) & 0x0000FFFF);
}

inline uint16 PAIR32_LOPART(uint32 x)
{
    return (uint16)(x & 0x0000FFFF);
}

#endif
