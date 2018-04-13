/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef CreatureData_h__
#define CreatureData_h__

#include "DBCEnums.h"
#include "Optional.h"
#include "SharedDefines.h"
#include "UnitDefines.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

struct ItemTemplate;

enum CreatureDifficultyFlags
{
    CREATURE_DIFFICULTYFLAGS_UNK1                              = 0x00000001, // Related to mounts
    CREATURE_DIFFICULTYFLAGS_NO_EXPERIENCE                     = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_NO_LOOT                           = 0x00000004,
    CREATURE_DIFFICULTYFLAGS_UNKILLABLE                        = 0x00000008,
    CREATURE_DIFFICULTYFLAGS_TAMEABLE                          = 0x00000010, // CREATURE_TYPEFLAGS_TAMEABLE
    CREATURE_DIFFICULTYFLAGS_IMMUNE_TO_PC                      = 0x00000020, // UNIT_FLAG_IMMUNE_TO_PC
    CREATURE_DIFFICULTYFLAGS_IMMUNE_TO_NPC                     = 0x00000040, // UNIT_FLAG_IMMUNE_TO_NPC
    CREATURE_DIFFICULTYFLAGS_UNK2                              = 0x00000080,
    CREATURE_DIFFICULTYFLAGS_SESSILE                           = 0x00000100, // Creature is rooted
    CREATURE_DIFFICULTYFLAGS_NOT_SELECTABLE                    = 0x00000200, // UNIT_FLAG_NOT_SELECTABLE
    CREATURE_DIFFICULTYFLAGS_UNK3                              = 0x00000400, // Related to health - it seems similar to CREATURE_DIFFICULTYFLAGS_2_KEEP_HEALTH_POINTS_AT_RESET
    CREATURE_DIFFICULTYFLAGS_NO_CORPSE_UPON_DEATH              = 0x00000800, // Creature instantly disappear when killed
    CREATURE_DIFFICULTYFLAGS_UNK5                              = 0x00001000,
    CREATURE_DIFFICULTYFLAGS_UNK6                              = 0x00002000,
    CREATURE_DIFFICULTYFLAGS_UNK7                              = 0x00004000,
    CREATURE_DIFFICULTYFLAGS_UNK8                              = 0x00008000,
    CREATURE_DIFFICULTYFLAGS_BOSS                              = 0x00010000, // CREATURE_TYPEFLAGS_BOSS
    CREATURE_DIFFICULTYFLAGS_UNK9                              = 0x00020000,
    CREATURE_DIFFICULTYFLAGS_WATER_BOUND                       = 0x00040000,
    CREATURE_DIFFICULTYFLAGS_CAN_PENETRATE_WATER               = 0x00080000,
    CREATURE_DIFFICULTYFLAGS_UNK10                             = 0x00100000,
    CREATURE_DIFFICULTYFLAGS_GHOST                             = 0x00200000, // CREATURE_TYPEFLAGS_GHOST
    CREATURE_DIFFICULTYFLAGS_UNK11                             = 0x00400000,
    CREATURE_DIFFICULTYFLAGS_DO_NOT_PLAY_WOUND_PARRY_ANIMATION = 0x00800000, // CREATURE_TYPEFLAGS_DO_NOT_PLAY_WOUND_PARRY_ANIMATION
    CREATURE_DIFFICULTYFLAGS_HIDE_FACTION_TOOLTIP              = 0x01000000, // CREATURE_TYPEFLAGS_HIDE_FACTION_TOOLTIP
    CREATURE_DIFFICULTYFLAGS_IGNORE_COMBAT                     = 0x02000000,
    CREATURE_DIFFICULTYFLAGS_UNK12                             = 0x04000000,
    CREATURE_DIFFICULTYFLAGS_SUMMON_GUARD_IF_IN_AGGRO_RANGE    = 0x08000000, // Creature will summon a guard if player is within its aggro range (even if creature doesn't attack per se)
    CREATURE_DIFFICULTYFLAGS_ONLY_SWIM                         = 0x10000000, // UNIT_FLAG_UNK_15
    CREATURE_DIFFICULTYFLAGS_UNK13                             = 0x20000000, // Related to gravity
    CREATURE_DIFFICULTYFLAGS_TFLAG_UNK5                        = 0x40000000, // CREATURE_TYPEFLAGS_UNK5
    CREATURE_DIFFICULTYFLAGS_LARGE_AOI                         = 0x80000000  // UnitFlags2 0x200000
};

enum CreatureDifficultyFlags2
{
    CREATURE_DIFFICULTYFLAGS_2_UNK1                            = 0x00000001,
    CREATURE_DIFFICULTYFLAGS_2_FORCE_PARTY_MEMBERS_INTO_COMBAT = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_2_UNK2                            = 0x00000004,
    CREATURE_DIFFICULTYFLAGS_2_SPELL_ATTACKABLE                = 0x00000008, // CREATURE_TYPEFLAGS_SPELL_ATTACKABLE
    CREATURE_DIFFICULTYFLAGS_2_UNK3                            = 0x00000010,
    CREATURE_DIFFICULTYFLAGS_2_UNK4                            = 0x00000020,
    CREATURE_DIFFICULTYFLAGS_2_UNK5                            = 0x00000040,
    CREATURE_DIFFICULTYFLAGS_2_UNK6                            = 0x00000080,
    CREATURE_DIFFICULTYFLAGS_2_UNK7                            = 0x00000100,
    CREATURE_DIFFICULTYFLAGS_2_UNK8                            = 0x00000200,
    CREATURE_DIFFICULTYFLAGS_2_UNK9                            = 0x00000400,
    CREATURE_DIFFICULTYFLAGS_2_DEAD_INTERACT                   = 0x00000800, // CREATURE_TYPEFLAGS_DEAD_INTERACT
    CREATURE_DIFFICULTYFLAGS_2_UNK10                           = 0x00001000,
    CREATURE_DIFFICULTYFLAGS_2_UNK11                           = 0x00002000,
    CREATURE_DIFFICULTYFLAGS_2_HERBLOOT                        = 0x00004000, // CREATURE_TYPEFLAGS_HERBLOOT
    CREATURE_DIFFICULTYFLAGS_2_MININGLOOT                      = 0x00008000, // CREATURE_TYPEFLAGS_MININGLOOT
    CREATURE_DIFFICULTYFLAGS_2_DONT_LOG_DEATH                  = 0x00010000, // CREATURE_TYPEFLAGS_DONT_LOG_DEATH
    CREATURE_DIFFICULTYFLAGS_2_UNK12                           = 0x00020000,
    CREATURE_DIFFICULTYFLAGS_2_MOUNTED_COMBAT                  = 0x00040000, // CREATURE_TYPEFLAGS_MOUNTED_COMBAT
    CREATURE_DIFFICULTYFLAGS_2_UNK13                           = 0x00080000,
    CREATURE_DIFFICULTYFLAGS_2_UNK14                           = 0x00100000, // This flag seems similar to CREATURE_DIFFICULTYFLAGS_IGNORE_COMBAT
    CREATURE_DIFFICULTYFLAGS_2_UNK15                           = 0x00200000,
    CREATURE_DIFFICULTYFLAGS_2_UNK16                           = 0x00400000,
    CREATURE_DIFFICULTYFLAGS_2_UNK17                           = 0x00800000,
    CREATURE_DIFFICULTYFLAGS_2_UNK18                           = 0x01000000,
    CREATURE_DIFFICULTYFLAGS_2_HIDE_BODY                       = 0x02000000, // UNIT_FLAG2_UNK1
    CREATURE_DIFFICULTYFLAGS_2_UNK19                           = 0x04000000,
    CREATURE_DIFFICULTYFLAGS_2_SERVER_ONLY                     = 0x08000000,
    CREATURE_DIFFICULTYFLAGS_2_CAN_SAFE_FALL                   = 0x10000000,
    CREATURE_DIFFICULTYFLAGS_2_CAN_ASSIST                      = 0x20000000, // CREATURE_TYPEFLAGS_CAN_ASSIST
    CREATURE_DIFFICULTYFLAGS_2_KEEP_HEALTH_POINTS_AT_RESET     = 0x40000000,
    CREATURE_DIFFICULTYFLAGS_2_IS_PET_BAR_USED                 = 0x80000000  // CREATURE_TYPEFLAGS_IS_PET_BAR_USED
};

enum CreatureDifficultyFlags3
{
    CREATURE_DIFFICULTYFLAGS_3_UNK1                           = 0x00000001,
    CREATURE_DIFFICULTYFLAGS_3_UNK2                           = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_3_INSTANTLY_APPEAR_MODEL         = 0x00000004, // UNIT_FLAG2_INSTANTLY_APPEAR_MODEL
    CREATURE_DIFFICULTYFLAGS_3_MASK_UID                       = 0x00000008, // CREATURE_TYPEFLAG_MASK_UID
    CREATURE_DIFFICULTYFLAGS_3_ENGINEERLOOT                   = 0x00000010, // CREATURE_TYPEFLAGS_ENGINEERLOOT
    CREATURE_DIFFICULTYFLAGS_3_UNK3                           = 0x00000020,
    CREATURE_DIFFICULTYFLAGS_3_UNK4                           = 0x00000040,
    CREATURE_DIFFICULTYFLAGS_3_UNK5                           = 0x00000080,
    CREATURE_DIFFICULTYFLAGS_3_CANNOT_SWIM                    = 0x00000100, // UNIT_FLAG_UNK_14
    CREATURE_DIFFICULTYFLAGS_3_EXOTIC                         = 0x00000200, // CREATURE_TYPEFLAGS_EXOTIC
    CREATURE_DIFFICULTYFLAGS_3_GIGANTIC_AOI                   = 0x00000400, // Since MoP, creatures with that flag have UnitFlags2 0x400000
    CREATURE_DIFFICULTYFLAGS_3_INFINITE_AOI                   = 0x00000800, // Since MoP, creatures with that flag have UnitFlags2 0x40000000
    CREATURE_DIFFICULTYFLAGS_3_WATERWALKING                   = 0x00001000,
    CREATURE_DIFFICULTYFLAGS_3_HIDE_NAMEPLATE                 = 0x00002000, // CREATURE_TYPEFLAGS_HIDE_NAMEPLATE
    CREATURE_DIFFICULTYFLAGS_3_UNK6                           = 0x00004000,
    CREATURE_DIFFICULTYFLAGS_3_UNK7                           = 0x00008000,
    CREATURE_DIFFICULTYFLAGS_3_USE_DEFAULT_COLLISION_BOX      = 0x00010000, // CREATURE_TYPEFLAGS_USE_DEFAULT_COLLISION_BOX
    CREATURE_DIFFICULTYFLAGS_3_UNK8                           = 0x00020000,
    CREATURE_DIFFICULTYFLAGS_3_IS_SIEGE_WEAPON                = 0x00040000, // CREATURE_TYPEFLAGS_IS_SIEGE_WEAPON
    CREATURE_DIFFICULTYFLAGS_3_UNK9                           = 0x00080000,
    CREATURE_DIFFICULTYFLAGS_3_UNK10                          = 0x00100000,
    CREATURE_DIFFICULTYFLAGS_3_UNK11                          = 0x00200000,
    CREATURE_DIFFICULTYFLAGS_3_PROJECTILE_COLLISION           = 0x00400000, // CREATURE_TYPEFLAGS_PROJECTILE_COLLISION
    CREATURE_DIFFICULTYFLAGS_3_CAN_BE_MULTITAPPED             = 0x00800000,
    CREATURE_DIFFICULTYFLAGS_3_DO_NOT_PLAY_MOUNTED_ANIMATIONS = 0x01000000, // CREATURE_TYPEFLAGS_DO_NOT_PLAY_MOUNTED_ANIMATIONS
    CREATURE_DIFFICULTYFLAGS_3_DISABLE_TURN                   = 0x02000000, // UNIT_FLAG2_DISABLE_TURN
    CREATURE_DIFFICULTYFLAGS_3_UNK12                          = 0x04000000,
    CREATURE_DIFFICULTYFLAGS_3_UNK13                          = 0x08000000,
    CREATURE_DIFFICULTYFLAGS_3_UNK14                          = 0x10000000,
    CREATURE_DIFFICULTYFLAGS_3_IS_LINK_ALL                    = 0x20000000, // CREATURE_TYPEFLAGS_IS_LINK_ALL
    CREATURE_DIFFICULTYFLAGS_3_UNK15                          = 0x40000000,
    CREATURE_DIFFICULTYFLAGS_3_UNK16                          = 0x80000000
};

enum CreatureDifficultyFlags4
{
    CREATURE_DIFFICULTYFLAGS_4_HAS_NO_BIRTH_ANIMATION              = 0x00000001, // SMSG_UPDATE_OBJECT's "NoBirthAnim"
    CREATURE_DIFFICULTYFLAGS_4_UNK1                                = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_4_UNK2                                = 0x00000004,
    CREATURE_DIFFICULTYFLAGS_4_INTERACT_ONLY_WITH_CREATOR          = 0x00000008, // CREATURE_TYPEFLAGS_INTERACT_ONLY_WITH_CREATOR
    CREATURE_DIFFICULTYFLAGS_4_DO_NOT_PLAY_UNIT_EVENT_SOUNDS       = 0x00000010, // CREATURE_TYPEFLAGS_DO_NOT_PLAY_UNIT_EVENT_SOUNDS
    CREATURE_DIFFICULTYFLAGS_4_HAS_NO_SHADOW_BLOB                  = 0x00000020, // CREATURE_TYPEFLAGS_HAS_NO_SHADOW_BLOB
    CREATURE_DIFFICULTYFLAGS_4_UNK3                                = 0x00000040,
    CREATURE_DIFFICULTYFLAGS_4_UNK4                                = 0x00000080,
    CREATURE_DIFFICULTYFLAGS_4_UNK5                                = 0x00000100,
    CREATURE_DIFFICULTYFLAGS_4_UNK6                                = 0x00000200,
    CREATURE_DIFFICULTYFLAGS_4_UNK7                                = 0x00000400,
    CREATURE_DIFFICULTYFLAGS_4_UNK8                                = 0x00000800,
    CREATURE_DIFFICULTYFLAGS_4_UNK9                                = 0x00001000,
    CREATURE_DIFFICULTYFLAGS_4_UNK10                               = 0x00002000,
    CREATURE_DIFFICULTYFLAGS_4_UNK11                               = 0x00004000,
    CREATURE_DIFFICULTYFLAGS_4_UFLAG2_UNK20                        = 0x00008000, // UnitFlags2 0x100000
    CREATURE_DIFFICULTYFLAGS_4_UNK12                               = 0x00010000,
    CREATURE_DIFFICULTYFLAGS_4_UNK13                               = 0x00020000,
    CREATURE_DIFFICULTYFLAGS_4_UNK14                               = 0x00040000,
    CREATURE_DIFFICULTYFLAGS_4_FORCE_GOSSIP                        = 0x00080000, // CREATURE_TYPEFLAGS_FORCE_GOSSIP
    CREATURE_DIFFICULTYFLAGS_4_UNK15                               = 0x00100000,
    CREATURE_DIFFICULTYFLAGS_4_DO_NOT_SHEATHE                      = 0x00200000, // CREATURE_TYPEFLAGS_DO_NOT_SHEATHE
    CREATURE_DIFFICULTYFLAGS_4_IGNORE_SPELL_MIN_RANGE_RESTRICTIONS = 0x00400000, // UnitFlags2 0x8000000
    CREATURE_DIFFICULTYFLAGS_4_UNK16                               = 0x00800000,
    CREATURE_DIFFICULTYFLAGS_4_PREVENT_SWIM                        = 0x01000000, // UnitFlags2 0x1000000
    CREATURE_DIFFICULTYFLAGS_4_HIDE_IN_COMBAT_LOG                  = 0x02000000, // UnitFlags2 0x2000000
    CREATURE_DIFFICULTYFLAGS_4_UNK17                               = 0x04000000,
    CREATURE_DIFFICULTYFLAGS_4_UNK18                               = 0x08000000,
    CREATURE_DIFFICULTYFLAGS_4_UNK19                               = 0x10000000,
    CREATURE_DIFFICULTYFLAGS_4_DO_NOT_TARGET_ON_INTERACTION        = 0x20000000, // CREATURE_TYPEFLAGS_DO_NOT_TARGET_ON_INTERACTION
    CREATURE_DIFFICULTYFLAGS_4_DO_NOT_RENDER_OBJECT_NAME           = 0x40000000, // CREATURE_TYPEFLAGS_DO_NOT_RENDER_OBJECT_NAME
    CREATURE_DIFFICULTYFLAGS_4_UNIT_IS_QUEST_BOSS                  = 0x80000000  // CREATURE_TYPEFLAGS_UNIT_IS_QUEST_BOSS
};

enum CreatureDifficultyFlags5
{
    CREATURE_DIFFICULTYFLAGS_5_CANNOT_SWITCH_TARGETS        = 0x00000001, // UnitFlags2 0x4000000
    CREATURE_DIFFICULTYFLAGS_5_UNK1                         = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_5_UFLAG2_UNK30                 = 0x00000004, // UnitFlags2 0x10000000
    CREATURE_DIFFICULTYFLAGS_5_UNK2                         = 0x00000008,
    CREATURE_DIFFICULTYFLAGS_5_UNK3                         = 0x00000010,
    CREATURE_DIFFICULTYFLAGS_5_UNK4                         = 0x00000020,
    CREATURE_DIFFICULTYFLAGS_5_UNK5                         = 0x00000040,
    CREATURE_DIFFICULTYFLAGS_5_UNK6                         = 0x00000080,
    CREATURE_DIFFICULTYFLAGS_5_CAN_INTERACT_EVEN_IF_HOSTILE = 0x00000100, // UNIT_FLAG2_ALLOW_ENEMY_INTERACT
    CREATURE_DIFFICULTYFLAGS_5_UNK7                         = 0x00000200,
    CREATURE_DIFFICULTYFLAGS_5_TFLAG2_UNK1                  = 0x00000400, // CREATURE_TYPEFLAGS_2_UNK1
    CREATURE_DIFFICULTYFLAGS_5_TFLAG2_UNK2                  = 0x00000800, // CREATURE_TYPEFLAGS_2_UNK2
    CREATURE_DIFFICULTYFLAGS_5_TFLAG2_UNK3                  = 0x00001000, // CREATURE_TYPEFLAGS_2_UNK3
    CREATURE_DIFFICULTYFLAGS_5_UFLAG2_UNK19                 = 0x00002000, // UnitFlags2 0x80000
    CREATURE_DIFFICULTYFLAGS_5_UNK8                         = 0x00004000,
    CREATURE_DIFFICULTYFLAGS_5_UNK9                         = 0x00008000,
    CREATURE_DIFFICULTYFLAGS_5_UNK10                        = 0x00010000,
    CREATURE_DIFFICULTYFLAGS_5_UNK11                        = 0x00020000,
    CREATURE_DIFFICULTYFLAGS_5_UNK12                        = 0x00040000,
    CREATURE_DIFFICULTYFLAGS_5_UNK13                        = 0x00080000,
    CREATURE_DIFFICULTYFLAGS_5_TFLAG2_UNK4                  = 0x00100000, // CREATURE_TYPEFLAGS_2_UNK4
    CREATURE_DIFFICULTYFLAGS_5_UNK14                        = 0x00200000,
    CREATURE_DIFFICULTYFLAGS_5_UNK15                        = 0x00400000,
    CREATURE_DIFFICULTYFLAGS_5_TFLAG2_UNK5                  = 0x00800000, // CREATURE_TYPEFLAGS_2_UNK5
    CREATURE_DIFFICULTYFLAGS_5_UNK16                        = 0x01000000,
    CREATURE_DIFFICULTYFLAGS_5_UNK17                        = 0x02000000,
    CREATURE_DIFFICULTYFLAGS_5_UNK18                        = 0x04000000,
    CREATURE_DIFFICULTYFLAGS_5_UNK19                        = 0x08000000,
    CREATURE_DIFFICULTYFLAGS_5_UNK20                        = 0x10000000,
    CREATURE_DIFFICULTYFLAGS_5_UNK21                        = 0x20000000,
    CREATURE_DIFFICULTYFLAGS_5_TFLAG2_UNK6                  = 0x40000000, // CREATURE_TYPEFLAGS_2_UNK6
    CREATURE_DIFFICULTYFLAGS_5_UNK22                        = 0x80000000
};

enum CreatureDifficultyFlags6
{
    CREATURE_DIFFICULTYFLAGS_6_UNK1         = 0x00000001,
    CREATURE_DIFFICULTYFLAGS_6_UNK2         = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_6_UNK3         = 0x00000004,
    CREATURE_DIFFICULTYFLAGS_6_UNK4         = 0x00000008,
    CREATURE_DIFFICULTYFLAGS_6_UNK5         = 0x00000010,
    CREATURE_DIFFICULTYFLAGS_6_UNK6         = 0x00000020,
    CREATURE_DIFFICULTYFLAGS_6_UNK7         = 0x00000040,
    CREATURE_DIFFICULTYFLAGS_6_TFLAG2_UNK7  = 0x00000080,
    CREATURE_DIFFICULTYFLAGS_6_UNK8         = 0x00000100,
    CREATURE_DIFFICULTYFLAGS_6_UNK9         = 0x00000200,
    CREATURE_DIFFICULTYFLAGS_6_UNK10        = 0x00000400,
    CREATURE_DIFFICULTYFLAGS_6_UNK11        = 0x00000800,
    CREATURE_DIFFICULTYFLAGS_6_UNK12        = 0x00001000,
    CREATURE_DIFFICULTYFLAGS_6_UNK13        = 0x00002000,
    CREATURE_DIFFICULTYFLAGS_6_UNK14        = 0x00004000,
    CREATURE_DIFFICULTYFLAGS_6_UNK15        = 0x00008000,
    CREATURE_DIFFICULTYFLAGS_6_UNK16        = 0x00010000,
    CREATURE_DIFFICULTYFLAGS_6_UNK17        = 0x00020000,
    CREATURE_DIFFICULTYFLAGS_6_UNK18        = 0x00040000,
    CREATURE_DIFFICULTYFLAGS_6_UNK19        = 0x00080000,
    CREATURE_DIFFICULTYFLAGS_6_UNK20        = 0x00100000,
    CREATURE_DIFFICULTYFLAGS_6_UNK21        = 0x00200000,
    CREATURE_DIFFICULTYFLAGS_6_UNK22        = 0x00400000,
    CREATURE_DIFFICULTYFLAGS_6_UNK23        = 0x00800000,
    CREATURE_DIFFICULTYFLAGS_6_UNK24        = 0x01000000,
    CREATURE_DIFFICULTYFLAGS_6_UNK25        = 0x02000000,
    CREATURE_DIFFICULTYFLAGS_6_UNK26        = 0x04000000,
    CREATURE_DIFFICULTYFLAGS_6_UNK27        = 0x08000000,
    CREATURE_DIFFICULTYFLAGS_6_UNK28        = 0x10000000,
    CREATURE_DIFFICULTYFLAGS_6_UNK29        = 0x20000000,
    CREATURE_DIFFICULTYFLAGS_6_UNK30        = 0x40000000,
    CREATURE_DIFFICULTYFLAGS_6_TFLAG2_UNK14 = 0x80000000
};

enum CreatureDifficultyFlags7
{
    CREATURE_DIFFICULTYFLAGS_7_TFLAG2_UNK15 = 0x00000001,
    CREATURE_DIFFICULTYFLAGS_7_TFLAG2_UNK16 = 0x00000002,
    CREATURE_DIFFICULTYFLAGS_7_TFLAG2_UNK17 = 0x00000004,
    CREATURE_DIFFICULTYFLAGS_7_UNK1         = 0x00000008
};

enum CreatureFlagsExtra
{
    CREATURE_FLAG_EXTRA_INSTANCE_BIND        = 0x00000001,       // creature kill bind instance with killer and killer's group
    CREATURE_FLAG_EXTRA_CIVILIAN             = 0x00000002,       // not aggro (ignore faction/reputation hostility)
    CREATURE_FLAG_EXTRA_NO_PARRY             = 0x00000004,       // creature can't parry
    CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN      = 0x00000008,       // creature can't counter-attack at parry
    CREATURE_FLAG_EXTRA_NO_BLOCK             = 0x00000010,       // creature can't block
    CREATURE_FLAG_EXTRA_NO_CRUSH             = 0x00000020,       // creature can't do crush attacks
    CREATURE_FLAG_EXTRA_NO_XP_AT_KILL        = 0x00000040,       // creature kill not provide XP
    CREATURE_FLAG_EXTRA_TRIGGER              = 0x00000080,       // trigger creature
    CREATURE_FLAG_EXTRA_NO_TAUNT             = 0x00000100,       // creature is immune to taunt auras and effect attack me
    CREATURE_FLAG_EXTRA_WORLDEVENT           = 0x00004000,       // custom flag for world event creatures (left room for merging)
    CREATURE_FLAG_EXTRA_GUARD                = 0x00008000,       // Creature is guard
    CREATURE_FLAG_EXTRA_NO_CRIT              = 0x00020000,       // creature can't do critical strikes
    CREATURE_FLAG_EXTRA_NO_SKILLGAIN         = 0x00040000,       // creature won't increase weapon skills
    CREATURE_FLAG_EXTRA_TAUNT_DIMINISH       = 0x00080000,       // Taunt is a subject to diminishing returns on this creautre
    CREATURE_FLAG_EXTRA_ALL_DIMINISH         = 0x00100000,       // creature is subject to all diminishing returns as player are
    CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ = 0x00200000,       // creature does not need to take player damage for kill credit
    CREATURE_FLAG_EXTRA_DUNGEON_BOSS         = 0x10000000,       // creature is a dungeon boss (SET DYNAMICALLY, DO NOT ADD IN DB)
    CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING   = 0x20000000,       // creature ignore pathfinding
    CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK   = 0x40000000        // creature is immune to knockback effects
};

#define CREATURE_FLAG_EXTRA_DB_ALLOWED (CREATURE_FLAG_EXTRA_INSTANCE_BIND | CREATURE_FLAG_EXTRA_CIVILIAN | \
    CREATURE_FLAG_EXTRA_NO_PARRY | CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN | CREATURE_FLAG_EXTRA_NO_BLOCK | \
    CREATURE_FLAG_EXTRA_NO_CRUSH | CREATURE_FLAG_EXTRA_NO_XP_AT_KILL | CREATURE_FLAG_EXTRA_TRIGGER | \
    CREATURE_FLAG_EXTRA_NO_TAUNT | CREATURE_FLAG_EXTRA_WORLDEVENT | CREATURE_FLAG_EXTRA_NO_CRIT | \
    CREATURE_FLAG_EXTRA_NO_SKILLGAIN | CREATURE_FLAG_EXTRA_TAUNT_DIMINISH | CREATURE_FLAG_EXTRA_ALL_DIMINISH | \
    CREATURE_FLAG_EXTRA_GUARD | CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING | CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ | CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK)

const uint32 CREATURE_REGEN_INTERVAL = 2 * IN_MILLISECONDS;
const uint32 CREATURE_NOPATH_EVADE_TIME = 5 * IN_MILLISECONDS;

const uint8 MAX_KILL_CREDIT = 2;
const uint32 MAX_CREATURE_MODELS = 4;
const uint32 MAX_CREATURE_NAMES = 4;
const uint32 MAX_CREATURE_SPELLS = 8;
const uint32 MAX_CREATURE_DIFFICULTIES = 3;

struct CreatureLevelScaling
{
    uint16 MinLevel;
    uint16 MaxLevel;
    int16 DeltaLevelMin;
    int16 DeltaLevelMax;
};

// from `creature_template` table
struct TC_GAME_API CreatureTemplate
{
    uint32  Entry;
    uint32  DifficultyEntry[MAX_CREATURE_DIFFICULTIES];
    uint32  KillCredit[MAX_KILL_CREDIT];
    uint32  Modelid1;
    uint32  Modelid2;
    uint32  Modelid3;
    uint32  Modelid4;
    std::string  Name;
    std::string FemaleName;
    std::string  SubName;
    std::string  TitleAlt;
    std::string  IconName;
    uint32  GossipMenuId;
    int16   minlevel;
    int16   maxlevel;
    Optional<CreatureLevelScaling> levelScaling;
    int32   HealthScalingExpansion;
    uint32  RequiredExpansion;
    uint32  VignetteID;                                     /// @todo Read Vignette.db2
    uint32  faction;
    uint64  npcflag;
    float   speed_walk;
    float   speed_run;
    float   scale;
    uint32  rank;
    uint32  dmgschool;
    uint32  BaseAttackTime;
    uint32  RangeAttackTime;
    float   BaseVariance;
    float   RangeVariance;
    uint32  unit_class;                                     // enum Classes. Note only 4 classes are known for creatures.
    uint32  unit_flags;                                     // enum UnitFlags mask values
    uint32  unit_flags2;                                    // enum UnitFlags2 mask values
    uint32  unit_flags3;                                    // enum UnitFlags3 mask values
    uint32  dynamicflags;
    CreatureFamily  family;                                 // enum CreatureFamily values (optional)
    uint32  trainer_class;
    uint32  type;                                           // enum CreatureType values
    uint32  type_flags;                                     // enum CreatureTypeFlags mask values
    uint32  type_flags2;                                    // unknown enum, only set for 4 creatures (with value 1)
    uint32  lootid;
    uint32  pickpocketLootId;
    uint32  SkinLootId;
    int32   resistance[MAX_SPELL_SCHOOL];
    uint32  spells[MAX_CREATURE_SPELLS];
    uint32  VehicleId;
    uint32  mingold;
    uint32  maxgold;
    std::string AIName;
    uint32  MovementType;
    uint32  InhabitType;
    float   HoverHeight;
    float   ModHealth;
    float   ModHealthExtra;
    float   ModMana;
    float   ModManaExtra;                                   // Added in 4.x, this value is usually 2 for a small group of creatures with double mana
    float   ModArmor;
    float   ModDamage;
    float   ModExperience;
    bool    RacialLeader;
    uint32  movementId;
    bool    RegenHealth;
    uint32  MechanicImmuneMask;
    uint32  flags_extra;
    uint32  ScriptID;
    uint32  GetRandomValidModelId() const;
    uint32  GetFirstValidModelId() const;
    uint32  GetFirstInvisibleModel() const;
    uint32  GetFirstVisibleModel() const;

    // helpers
    SkillType GetRequiredLootSkill() const
    {
        if (type_flags & CREATURE_TYPE_FLAG_HERB_SKINNING_SKILL)
            return SKILL_HERBALISM;
        else if (type_flags & CREATURE_TYPE_FLAG_MINING_SKINNING_SKILL)
            return SKILL_MINING;
        else if (type_flags & CREATURE_TYPE_FLAG_ENGINEERING_SKINNING_SKILL)
            return SKILL_ENGINEERING;
        else
            return SKILL_SKINNING;                          // normal case
    }

    bool IsExotic() const
    {
        return (type_flags & CREATURE_TYPE_FLAG_EXOTIC_PET) != 0;
    }

    bool IsTameable(bool canTameExotic) const
    {
        if (type != CREATURE_TYPE_BEAST || family == CREATURE_FAMILY_NONE || (type_flags & CREATURE_TYPE_FLAG_TAMEABLE_PET) == 0)
            return false;

        // if can tame exotic then can tame any tameable
        return canTameExotic || !IsExotic();
    }

    static int32 DifficultyIDToDifficultyEntryIndex(uint32 difficulty)
    {
        switch (difficulty)
        {
            case DIFFICULTY_NONE:
            case DIFFICULTY_NORMAL:
            case DIFFICULTY_10_N:
            case DIFFICULTY_40:
            case DIFFICULTY_3_MAN_SCENARIO_N:
            case DIFFICULTY_NORMAL_RAID:
                return -1;
            case DIFFICULTY_HEROIC:
            case DIFFICULTY_25_N:
            case DIFFICULTY_3_MAN_SCENARIO_HC:
            case DIFFICULTY_HEROIC_RAID:
                return 0;
            case DIFFICULTY_10_HC:
            case DIFFICULTY_MYTHIC_KEYSTONE:
            case DIFFICULTY_MYTHIC_RAID:
                return 1;
            case DIFFICULTY_25_HC:
                return 2;
            case DIFFICULTY_LFR:
            case DIFFICULTY_LFR_NEW:
            case DIFFICULTY_EVENT_RAID:
            case DIFFICULTY_EVENT_DUNGEON:
            case DIFFICULTY_EVENT_SCENARIO:
            default:
                return -1;
        }
    }
};

#pragma pack(push, 1)

// Defines base stats for creatures (used to calculate HP/mana/armor/attackpower/rangedattackpower/all damage).
struct TC_GAME_API CreatureBaseStats
{
    uint32 BaseHealth[MAX_EXPANSIONS];
    uint32 BaseMana;
    uint32 BaseArmor;
    uint32 AttackPower;
    uint32 RangedAttackPower;
    float BaseDamage[MAX_EXPANSIONS];

    // Helpers

    uint32 GenerateHealth(CreatureTemplate const* info) const
    {
        return uint32(ceil(BaseHealth[info->HealthScalingExpansion] * info->ModHealth * info->ModHealthExtra));
    }

    uint32 GenerateMana(CreatureTemplate const* info) const
    {
        // Mana can be 0.
        if (!BaseMana)
            return 0;

        return uint32(ceil(BaseMana * info->ModMana * info->ModManaExtra));
    }

    uint32 GenerateArmor(CreatureTemplate const* info) const
    {
        return uint32(ceil(BaseArmor * info->ModArmor));
    }

    float GenerateBaseDamage(CreatureTemplate const* info) const
    {
        return BaseDamage[info->HealthScalingExpansion];
    }

    static CreatureBaseStats const* GetBaseStats(uint8 level, uint8 unitClass);
};

struct CreatureLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> NameAlt;
    std::vector<std::string> Title;
    std::vector<std::string> TitleAlt;
};

struct EquipmentItem
{
    uint32 ItemId = 0;
    uint16 AppearanceModId = 0;
    uint16 ItemVisual = 0;
};

struct EquipmentInfo
{
    EquipmentItem Items[MAX_EQUIPMENT_ITEMS];
};

// from `creature` table
struct CreatureData
{
    CreatureData() : id(0), mapid(0), displayid(0), equipmentId(0),
                     posX(0.0f), posY(0.0f), posZ(0.0f), orientation(0.0f), spawntimesecs(0),
                     spawndist(0.0f), currentwaypoint(0), curhealth(0), curmana(0), movementType(0),
                     spawnMask(0), npcflag(0), unit_flags(0), unit_flags2(0), unit_flags3(0), dynamicflags(0),
                     phaseUseFlags(0), phaseId(0), phaseGroup(0), terrainSwapMap(-1), ScriptId(0), dbData(true) { }
    uint32 id;                                              // entry in creature_template
    uint16 mapid;
    uint32 displayid;
    int8 equipmentId;
    float posX;
    float posY;
    float posZ;
    float orientation;
    uint32 spawntimesecs;
    float spawndist;
    uint32 currentwaypoint;
    uint32 curhealth;
    uint32 curmana;
    uint8 movementType;
    uint64 spawnMask;
    uint64 npcflag;
    uint32 unit_flags;                                      // enum UnitFlags mask values
    uint32 unit_flags2;                                     // enum UnitFlags2 mask values
    uint32 unit_flags3;                                     // enum UnitFlags3 mask values
    uint32 dynamicflags;
    uint8 phaseUseFlags;
    uint32 phaseId;
    uint32 phaseGroup;
    int32 terrainSwapMap;
    uint32 ScriptId;
    bool dbData;
};

struct CreatureModelInfo
{
    float bounding_radius;
    float combat_reach;
    int8 gender;
    uint32 displayId_other_gender;
    bool is_trigger;
};

enum InhabitTypeValues
{
    INHABIT_GROUND = 1,
    INHABIT_WATER  = 2,
    INHABIT_AIR    = 4,
    INHABIT_ROOT   = 8,
    INHABIT_ANYWHERE = INHABIT_GROUND | INHABIT_WATER | INHABIT_AIR | INHABIT_ROOT
};

#pragma pack(pop)

// `creature_addon` table
struct CreatureAddon
{
    uint32 path_id;
    uint32 mount;
    uint32 bytes1;
    uint32 bytes2;
    uint32 emote;
    uint16 aiAnimKit;
    uint16 movementAnimKit;
    uint16 meleeAnimKit;
    std::vector<uint32> auras;
};

// Vendors
struct VendorItem
{
    VendorItem() : item(0), maxcount(0), incrtime(0), ExtendedCost(0), Type(0), PlayerConditionId(0), IgnoreFiltering(false) { }

    uint32 item;
    uint32 maxcount;                                        // 0 for infinity item amount
    uint32 incrtime;                                        // time for restore items amount if maxcount != 0
    uint32 ExtendedCost;
    uint8  Type;
    std::vector<int32> BonusListIDs;
    uint32 PlayerConditionId;
    bool IgnoreFiltering;

    //helpers
    bool IsGoldRequired(ItemTemplate const* pProto) const;
};

struct VendorItemData
{
    std::vector<VendorItem> m_items;

    VendorItem const* GetItem(uint32 slot) const
    {
        if (slot >= m_items.size())
            return nullptr;

        return &m_items[slot];
    }
    bool Empty() const { return m_items.empty(); }
    uint32 GetItemCount() const { return uint32(m_items.size()); }
    void AddItem(VendorItem vItem)
    {
        m_items.emplace_back(std::move(vItem));
    }
    bool RemoveItem(uint32 item_id, uint8 type);
    VendorItem const* FindItemCostPair(uint32 item_id, uint32 extendedCost, uint8 type) const;
    void Clear()
    {
        m_items.clear();
    }
};

#endif // CreatureData_h__
