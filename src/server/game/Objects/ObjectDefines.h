/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __OBJECT_DEFINES_H
#define __OBJECT_DEFINES_H

#include "Common.h"


#define CONTACT_DISTANCE            0.5f
#define INTERACTION_DISTANCE        5.0f
#define ATTACK_DISTANCE             5.0f
#define INSPECT_DISTANCE            10.0f
#define TRADE_DISTANCE              11.11f

#define MAX_VISIBILITY_DISTANCE     SIZE_OF_GRIDS      // max distance for visible object show, used to be 333 yards
#define DEFAULT_VISIBILITY_DISTANCE 100.0f             // default visible distance on continents, used to be 90 yards
#define DEFAULT_VISIBILITY_INSTANCE 170.0f             // default visible distance in instances, used to be 120 yards
#define DEFAULT_VISIBILITY_BG       533.0f             // default visible distance in BG, used to be 180 yards
#define DEFAULT_VISIBILITY_MODIFIER 0.0f               // default visibility modifier on some units that should be seen beyond normal visibility distances
#define DEFAULT_CREATURE_SUMMON_LIMIT  100             // default maximum number of creatures an object can have summoned at once

#define VISIBILITY_DISTANCE_GIGANTIC    400.0f
#define VISIBILITY_DISTANCE_LARGE       200.0f
#define VISIBILITY_DISTANCE_NORMAL      100.0f
#define VISIBILITY_DISTANCE_SMALL       50.0f
#define VISIBILITY_DISTANCE_TINY        25.0f

#define DEFAULT_WORLD_OBJECT_SIZE   0.388999998569489f      // currently used (correctly?) for any non Unit world objects. This is actually the bounding_radius, like player/creature from creature_model_data
#define DEFAULT_OBJECT_SCALE        1.0f                    // player/item scale as default, npc/go from database, pets from dbc
#define DEFAULT_GNOME_SCALE         1.15f
#define DEFAULT_TAUREN_MALE_SCALE   1.35f                   // Tauren Male Player Scale by default
#define DEFAULT_TAUREN_FEMALE_SCALE 1.25f                   // Tauren Female Player Scale by default

#define MAX_STEALTH_DETECT_RANGE    45.0f

// TrinityCore
#define DEFAULT_COMBAT_REACH        1.5f
#define MIN_MELEE_REACH             2.0f
#define NOMINAL_MELEE_RANGE         5.0f
#define MELEE_RANGE                 (NOMINAL_MELEE_RANGE - MIN_MELEE_REACH * 2)

#define LEEWAY_MIN_MOVE_SPEED       4.97f
#define LEEWAY_BONUS_RANGE          2.66f

enum TempSummonType
{
    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN          = 1,             // despawns after a specified time (out of combat) OR when the creature disappears
    TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN        = 2,             // despawns after a specified time (out of combat) OR when the creature dies
    TEMPSUMMON_TIMED_DESPAWN                  = 3,             // despawns after a specified time
    TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT    = 4,             // despawns after a specified time after the creature is out of combat
    TEMPSUMMON_CORPSE_DESPAWN                 = 5,             // despawns instantly after death
    TEMPSUMMON_CORPSE_TIMED_DESPAWN           = 6,             // despawns after a specified time after death
    TEMPSUMMON_DEAD_DESPAWN                   = 7,             // despawns when the creature disappears
    TEMPSUMMON_MANUAL_DESPAWN                 = 8,             // despawns when UnSummon() is called
    TEMPSUMMON_TIMED_COMBAT_OR_DEAD_DESPAWN   = 9,             // despawns after a specified time (in or out of combat) OR when the creature disappears
    TEMPSUMMON_TIMED_COMBAT_OR_CORPSE_DESPAWN = 10,            // despawns after a specified time (in or out of combat) OR when the creature dies
};

enum ObjectSpawnFlags
{
    SPAWN_FLAG_ACTIVE               = 0x01,
    SPAWN_FLAG_DISABLED             = 0x02,
    SPAWN_FLAG_RANDOM_RESPAWN_TIME  = 0x04,
    SPAWN_FLAG_DYNAMIC_RESPAWN_TIME = 0x08,
    SPAWN_FLAG_FORCE_DYNAMIC_ELITE  = 0x10, // creature only
    SPAWN_FLAG_EVADE_OUT_HOME_AREA  = 0x20, // creature only
    SPAWN_FLAG_NOT_VISIBLE          = 0x40, // creature only
    SPAWN_FLAG_DEAD                 = 0x80, // creature only
};

enum WorldMasks
{
    // Sees absolutely nothing 
    WORLD_ALONE            = 0x00,
    WORLD_DEFAULT_MASK     = 0x01,
    // Helpers
    WORLD_DEFAULT_OBJECT   = (WORLD_DEFAULT_MASK),
    WORLD_DEFAULT_UNIT     = (WORLD_DEFAULT_MASK),
    WORLD_DEFAULT_CREATURE = (WORLD_DEFAULT_MASK),
    WORLD_DEFAULT_CHAR     = (WORLD_DEFAULT_MASK),
    WORLD_SEE_ALL          = 0xF,
};


#endif
