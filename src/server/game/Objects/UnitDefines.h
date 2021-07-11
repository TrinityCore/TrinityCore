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

#ifndef __UNIT_DEFINES_H
#define __UNIT_DEFINES_H

#include "Common.h"

enum UnitMoveType
{
    MOVE_WALK           = 0,
    MOVE_RUN            = 1,
    MOVE_RUN_BACK       = 2,
    MOVE_SWIM           = 3,
    MOVE_SWIM_BACK      = 4,
    MOVE_TURN_RATE      = 5,
};

#define MAX_MOVE_TYPE 6

extern float baseMoveSpeed[MAX_MOVE_TYPE];

#define MOVEMENT_PACKET_TIME_DELAY 0

enum MovementChangeType
{
    INVALID,

    ROOT,
    WATER_WALK,
    SET_HOVER,
    FEATHER_FALL,

    SPEED_CHANGE_WALK,
    SPEED_CHANGE_RUN,
    SPEED_CHANGE_RUN_BACK,
    SPEED_CHANGE_SWIM,
    SPEED_CHANGE_SWIM_BACK,
    RATE_CHANGE_TURN,

    TELEPORT,
    KNOCK_BACK
};

// No orientation check for auto attacks or spells below this distance.
#define NO_FACING_CHECKS_DISTANCE 1.4f

// Delay time next attack to prevent client attack animation problems
#define ATTACK_DISPLAY_DELAY 200

// For this time difference is computed regen value
#define REGEN_TIME_FULL     2000

#define BASE_MELEERANGE_OFFSET 1.33f
#define BASE_MINDAMAGE 1.0f
#define BASE_MAXDAMAGE 2.0f
#define BASE_ATTACK_TIME 2000

enum UnitBytes0Offsets : uint8
{
    UNIT_BYTES_0_OFFSET_RACE       = 0,
    UNIT_BYTES_0_OFFSET_CLASS      = 1,
    UNIT_BYTES_0_OFFSET_GENDER     = 2,
    UNIT_BYTES_0_OFFSET_POWER_TYPE = 3,
};

enum UnitBytes1Offsets : uint8
{
    UNIT_BYTES_1_OFFSET_STAND_STATE     = 0,
    UNIT_BYTES_1_OFFSET_PET_LOYALTY     = 1,
    UNIT_BYTES_1_OFFSET_SHAPESHIFT_FORM = 2,
    UNIT_BYTES_1_OFFSET_VIS_FLAG        = 3,
};

enum UnitBytes2Offsets : uint8
{
    UNIT_BYTES_2_OFFSET_SHEATH_STATE = 0,
    UNIT_BYTES_2_OFFSET_MISC_FLAGS   = 1,
    UNIT_BYTES_2_OFFSET_PET_FLAGS    = 2,
    UNIT_BYTES_2_OFFSET_UNKNOWN      = 3, // shapeshift form in tbc
};

// byte value (UNIT_FIELD_BYTES_1,0)
enum UnitStandStateType
{
    UNIT_STAND_STATE_STAND             = 0,
    UNIT_STAND_STATE_SIT               = 1,
    UNIT_STAND_STATE_SIT_CHAIR         = 2,
    UNIT_STAND_STATE_SLEEP             = 3,
    UNIT_STAND_STATE_SIT_LOW_CHAIR     = 4,
    UNIT_STAND_STATE_SIT_MEDIUM_CHAIR  = 5,
    UNIT_STAND_STATE_SIT_HIGH_CHAIR    = 6,
    UNIT_STAND_STATE_DEAD              = 7,
    UNIT_STAND_STATE_KNEEL             = 8
};

#define MAX_UNIT_STAND_STATE             9

// byte flags value (UNIT_FIELD_BYTES_1,3)
// These flags seem to be related to visibility
// In wotlk+ they are moved to UNIT_FIELD_BYTES_1,2
enum UnitVisFlags
{
    UNIT_VIS_FLAGS_GHOST       = 0x01, // applied by SPELL_AURA_GHOST
    UNIT_VIS_FLAGS_CREEP       = 0x02, // applied by SPELL_AURA_MOD_STEALTH
    UNIT_VIS_FLAGS_UNTRACKABLE = 0x04, // applied by SPELL_AURA_UNTRACKABLE
    UNIT_VIS_FLAGS_ALL         = 0xFF
};

// byte value (UNIT_FIELD_BYTES_2,0)
enum SheathState
{
    SHEATH_STATE_UNARMED  = 0,                              // non prepared weapon
    SHEATH_STATE_MELEE    = 1,                              // prepared melee weapon
    SHEATH_STATE_RANGED   = 2                               // prepared ranged weapon
};

#define MAX_SHEATH_STATE    3

// byte flags value (UNIT_FIELD_BYTES_2,1)
enum UnitBytes2_Flags
{
    UNIT_BYTE2_FLAG_PVP         = 0x01,
    UNIT_BYTE2_FLAG_UNK1        = 0x02,
    UNIT_BYTE2_FLAG_FFA_PVP     = 0x04,
    UNIT_BYTE2_FLAG_UNK3        = 0x08,                     // FLAG_SANCTUARY on 3.3.5
    UNIT_BYTE2_FLAG_AURAS       = 0x10,                     // show possitive auras as positive, and allow its dispel
    UNIT_BYTE2_FLAG_UNK5        = 0x20,
    UNIT_BYTE2_FLAG_UNK6        = 0x40,
    UNIT_BYTE2_FLAG_UNK7        = 0x80
};

#define CREATURE_MAX_SPELLS     4

enum Swing
{
    NOSWING                    = 0,
    SINGLEHANDEDSWING          = 1,
    TWOHANDEDSWING             = 2
};

enum VictimState
{
    VICTIMSTATE_UNAFFECTED     = 0,                         // seen in relation with HITINFO_MISS
    VICTIMSTATE_NORMAL         = 1,
    VICTIMSTATE_DODGE          = 2,
    VICTIMSTATE_PARRY          = 3,
    VICTIMSTATE_INTERRUPT      = 4,
    VICTIMSTATE_BLOCKS         = 5,
    VICTIMSTATE_EVADES         = 6,
    VICTIMSTATE_IS_IMMUNE      = 7,
    VICTIMSTATE_DEFLECTS       = 8
};

enum HitInfo
{
    HITINFO_NORMALSWING         = 0x00000000,
    HITINFO_UNK0                = 0x00000001,               // req correct packet structure
    HITINFO_AFFECTS_VICTIM      = 0x00000002,               // no being hit animation on victim without it
    HITINFO_LEFTSWING           = 0x00000004,
    HITINFO_UNK3                = 0x00000008,
    HITINFO_MISS                = 0x00000010,
    HITINFO_ABSORB              = 0x00000020,               // plays absorb sound
    HITINFO_RESIST              = 0x00000040,               // resisted atleast some damage
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    HITINFO_CRITICALHIT         = 0x00000080,
#else
    HITINFO_CRITICALHIT         = 0x00000008,
#endif
    HITINFO_UNK8                = 0x00000100,               // wotlk?
    HITINFO_UNK9                = 0x00002000,               // wotlk?
    HITINFO_GLANCING            = 0x00004000,
    HITINFO_CRUSHING            = 0x00008000,
    HITINFO_NOACTION            = 0x00010000,
    HITINFO_SWINGNOHITSOUND     = 0x00080000
};

//i would like to remove this: (it is defined in item.h
enum InventorySlot
{
    NULL_BAG                   = 0,
    NULL_SLOT                  = 255
};

enum UnitModifierType
{
    BASE_VALUE = 0,
    BASE_PCT = 1,
    TOTAL_VALUE = 2,
    TOTAL_PCT = 3,
    MODIFIER_TYPE_END = 4
};

enum WeaponDamageRange
{
    MINDAMAGE,
    MAXDAMAGE
};

enum DamageTypeToSchool
{
    RESISTANCE,
    DAMAGE_DEALT,
    DAMAGE_TAKEN
};

enum AuraRemoveMode
{
    AURA_REMOVE_BY_DEFAULT,
    AURA_REMOVE_BY_STACK,                                   // at replace by similar aura
    AURA_REMOVE_BY_CANCEL,
    AURA_REMOVE_BY_DISPEL,
    AURA_REMOVE_BY_DEATH,
    AURA_REMOVE_BY_DELETE,                                  // use for speedup and prevent unexpected effects at player logout/pet unsummon (must be used _only_ after save), delete.
    AURA_REMOVE_BY_SHIELD_BREAK,                            // when absorb shield is removed by damage
    AURA_REMOVE_BY_EXPIRE,                                  // at duration end
    AURA_REMOVE_BY_CHANNEL,                                 // when removing an aura due to channel finish or cancel
    AURA_REMOVE_BY_RANGE,                                   // when removing an area aura due to being out of range
    AURA_REMOVE_BY_GROUP                                    // when removing an aura due to not being in the same group (includes pet ownership)
};

enum UnitMods
{
    UNIT_MOD_STAT_STRENGTH,                                 // UNIT_MOD_STAT_STRENGTH..UNIT_MOD_STAT_SPIRIT must be in existing order, it's accessed by index values of Stats enum.
    UNIT_MOD_STAT_AGILITY,
    UNIT_MOD_STAT_STAMINA,
    UNIT_MOD_STAT_INTELLECT,
    UNIT_MOD_STAT_SPIRIT,
    UNIT_MOD_HEALTH,
    UNIT_MOD_MANA,                                          // UNIT_MOD_MANA..UNIT_MOD_HAPPINESS must be in existing order, it's accessed by index values of Powers enum.
    UNIT_MOD_RAGE,
    UNIT_MOD_FOCUS,
    UNIT_MOD_ENERGY,
    UNIT_MOD_HAPPINESS,
    UNIT_MOD_ARMOR,                                         // UNIT_MOD_ARMOR..UNIT_MOD_RESISTANCE_ARCANE must be in existing order, it's accessed by index values of SpellSchools enum.
    UNIT_MOD_RESISTANCE_HOLY,
    UNIT_MOD_RESISTANCE_FIRE,
    UNIT_MOD_RESISTANCE_NATURE,
    UNIT_MOD_RESISTANCE_FROST,
    UNIT_MOD_RESISTANCE_SHADOW,
    UNIT_MOD_RESISTANCE_ARCANE,
    UNIT_MOD_ATTACK_POWER,
    UNIT_MOD_ATTACK_POWER_RANGED,
    UNIT_MOD_DAMAGE_MAINHAND,
    UNIT_MOD_DAMAGE_OFFHAND,
    UNIT_MOD_DAMAGE_RANGED,
    UNIT_MOD_DAMAGE_PHYSICAL,
    UNIT_MOD_END,
    // synonyms
    UNIT_MOD_STAT_START = UNIT_MOD_STAT_STRENGTH,
    UNIT_MOD_STAT_END = UNIT_MOD_STAT_SPIRIT + 1,
    UNIT_MOD_RESISTANCE_START = UNIT_MOD_ARMOR,
    UNIT_MOD_RESISTANCE_END = UNIT_MOD_RESISTANCE_ARCANE + 1,
    UNIT_MOD_POWER_START = UNIT_MOD_MANA,
    UNIT_MOD_POWER_END = UNIT_MOD_HAPPINESS + 1
};

enum BaseModGroup
{
    CRIT_PERCENTAGE,
    RANGED_CRIT_PERCENTAGE,
    OFFHAND_CRIT_PERCENTAGE,
    SHIELD_BLOCK_VALUE,
    BASEMOD_END
};

enum BaseModType
{
    FLAT_MOD,
    PCT_MOD
};

#define MOD_END (PCT_MOD+1)

enum DeathState
{
    ALIVE          = 0,                                     // show as alive
    JUST_DIED      = 1,                                     // temporary state at die, for creature auto converted to CORPSE, for player at next update call
    CORPSE         = 2,                                     // corpse state, for player spirit is still within the corpse
    DEAD           = 3,                                     // for creature despawned state (corpse despawned), for player spirit has been released (player is ghost)
    JUST_ALIVED    = 4,                                     // temporary state at resurrection, for creature auto converted to ALIVE, for player at next update call
    CORPSE_FALLING = 5                                      // corpse state in case when corpse still falling to ground
};

// internal state flags for some auras and movement generators, other.
enum UnitState
{
    // persistent state (applied by aura/etc until expire)
    UNIT_STAT_MELEE_ATTACKING = 0x00000001,                     // unit is melee attacking someone Unit::Attack
    UNIT_STAT_NO_KILL_REWARD  = 0x00000002,                     // Unit should yield no reward (Honor/XP/Rep) on kill
    UNIT_STAT_FEIGN_DEATH     = 0x00000004,                     // Unit::SetFeignDeath - a successful feign death is currently active
    UNIT_STAT_STUNNED         = 0x00000008,                     // Aura::HandleAuraModStun
    UNIT_STAT_ROOT            = 0x00000010,                     // Aura::HandleAuraModRoot
    UNIT_STAT_ISOLATED        = 0x00000020,                     // area auras do not affect other players, Aura::HandleAuraModSchoolImmunity
    UNIT_STAT_POSSESSED       = 0x00000040,                     // Aura::HandleAuraModPossess

    // persistent movement generator state (all time while movement generator applied to unit (independent from top state of movegen)
    UNIT_STAT_TAXI_FLIGHT     = 0x00000080,                     // player is in flight mode (in fact interrupted at far teleport until next map telport landing)
    UNIT_STAT_DISTRACTED      = 0x00000100,                     // DistractedMovementGenerator active

    // persistent movement generator state with non-persistent mirror states for stop support
    // (can be removed temporary by stop command or another movement generator apply)
    // not use _MOVE versions for generic movegen state, it can be removed temporary for unit stop and etc
    UNIT_STAT_CONFUSED        = 0x00000200,                     // ConfusedMovementGenerator active/onstack
    //UNIT_STAT_CONFUSED_MOVE   = 0x00000400,                   // No longer in use (Nostalrius)
    UNIT_STAT_ROAMING         = 0x00000800,                     // RandomMovementGenerator/PointMovementGenerator/WaypointMovementGenerator active (now always set)
    UNIT_STAT_ROAMING_MOVE    = 0x00001000,
    UNIT_STAT_CHASE           = 0x00002000,                     // ChaseMovementGenerator active
    UNIT_STAT_CHASE_MOVE      = 0x00004000,
    UNIT_STAT_FOLLOW          = 0x00008000,                     // FollowMovementGenerator active
    UNIT_STAT_FOLLOW_MOVE     = 0x00010000,
    UNIT_STAT_FLEEING         = 0x00020000,                     // FleeMovementGenerator/TimedFleeingMovementGenerator active/onstack
    UNIT_STAT_FLEEING_MOVE    = 0x00040000,
    // MMAPS
    UNIT_STAT_IGNORE_PATHFINDING    = 0x00080000,               // do not use pathfinding in any MovementGenerator

    UNIT_STAT_PENDING_ROOT          = 0x00100000,
    UNIT_STAT_PENDING_STUNNED       = 0x00200000,
    UNIT_STAT_FLYING_ALLOWED        = 0x00400000,               // has gm fly mode enabled

    // High-level states
    UNIT_STAT_NO_COMBAT_MOVEMENT = 0x01000000,
    UNIT_STAT_RUNNING            = 0x02000000,
    UNIT_STAT_IGNORE_MOVE_LOS    = 0x04000000,

    UNIT_STAT_ALLOW_INCOMPLETE_PATH = 0x08000000, // allow movement with incomplete or partial paths
    UNIT_STAT_ALLOW_LOS_ATTACK      = 0x10000000, // allow melee attacks without LoS
    // masks (only for check)

    // can't move currently
    UNIT_STAT_CAN_NOT_MOVE    = UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_FEIGN_DEATH,

    // stay by different reasons
    UNIT_STAT_NOT_MOVE        = UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_FEIGN_DEATH |
                                UNIT_STAT_DISTRACTED,

    // stay or scripted movement for effect( = in player case you can't move by client command)
    UNIT_STAT_NO_FREE_MOVE    = UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_FEIGN_DEATH |
                                UNIT_STAT_TAXI_FLIGHT |
                                UNIT_STAT_CONFUSED | UNIT_STAT_FLEEING,

    // not react at move in sight or other
    UNIT_STAT_CAN_NOT_REACT   = UNIT_STAT_STUNNED | UNIT_STAT_FEIGN_DEATH |
                                UNIT_STAT_CONFUSED | UNIT_STAT_FLEEING,

    // AI disabled by some reason
    UNIT_STAT_LOST_CONTROL    = UNIT_STAT_FLEEING | UNIT_STAT_POSSESSED,

    // above 2 state cases
    UNIT_STAT_CAN_NOT_REACT_OR_LOST_CONTROL  = UNIT_STAT_CAN_NOT_REACT | UNIT_STAT_LOST_CONTROL,

    // masks (for check or reset)

    // for real move using movegen check and stop (except unstoppable flight)
    UNIT_STAT_MOVING          = UNIT_STAT_ROAMING_MOVE | UNIT_STAT_CHASE_MOVE | UNIT_STAT_FOLLOW_MOVE | UNIT_STAT_FLEEING_MOVE,

    UNIT_STAT_ALL_STATE       = 0xFFFFFFFF,
    UNIT_STAT_ALL_DYN_STATES  = UNIT_STAT_ALL_STATE & ~(UNIT_STAT_NO_COMBAT_MOVEMENT | UNIT_STAT_RUNNING | UNIT_STAT_IGNORE_PATHFINDING),
};

enum UnitVisibility
{
    VISIBILITY_OFF                = 0,                      // absolute, not detectable, GM-like, can see all other
    VISIBILITY_ON                 = 1,
    VISIBILITY_GROUP_STEALTH      = 2,                      // detect chance, seen and can see group members
    VISIBILITY_GROUP_INVISIBILITY = 3,                      // invisibility, can see and can be seen only another invisible unit or invisible detection unit, set only if not stealthed, and in checks not used (mask used instead)
    VISIBILITY_GROUP_NO_DETECT    = 4,                      // state just at stealth apply for update Grid state. Don't remove, otherwise stealth spells will break
    VISIBILITY_RESPAWN            = 5                       // special totally not detectable visibility for force delete object at respawn command
};

// [-ZERO] Need recheck values
// Value masks for UNIT_FIELD_FLAGS
enum UnitFlags
{
    UNIT_FLAG_NONE                  = 0x00000000,
    UNIT_FLAG_UNK_0                 = 0x00000001,           // Movement checks disabled, likely paired with loss of client control packet.
    UNIT_FLAG_NON_ATTACKABLE        = 0x00000002,           // not attackable
    UNIT_FLAG_DISABLE_MOVE          = 0x00000004,
    UNIT_FLAG_PLAYER_CONTROLLED     = 0x00000008,           // players, pets, totems, guardians, companions, charms, any units associated with players
    UNIT_FLAG_PET_RENAME            = 0x00000010,           // Old pet rename: moved to UNIT_FIELD_BYTES_2,2 in TBC+
    UNIT_FLAG_PET_ABANDON           = 0x00000020,           // Old pet abandon: moved to UNIT_FIELD_BYTES_2,2 in TBC+
    UNIT_FLAG_UNK_6                 = 0x00000040,
    UNIT_FLAG_IMMUNE_TO_PLAYER      = 0x00000100,           // Target is immune to players
    UNIT_FLAG_IMMUNE_TO_NPC         = 0x00000200,           // Target is immune to creatures
    UNIT_FLAG_PVP                   = 0x00001000,
    UNIT_FLAG_SILENCED              = 0x00002000,           // silenced, 2.1.1
    UNIT_FLAG_UNK_14                = 0x00004000,
    UNIT_FLAG_USE_SWIM_ANIMATION    = 0x00008000,
    UNIT_FLAG_NON_ATTACKABLE_2      = 0x00010000,           // removes attackable icon, if on yourself, cannot assist self but can cast TARGET_UNIT_CASTER spells - added by SPELL_AURA_MOD_UNATTACKABLE
    UNIT_FLAG_PACIFIED              = 0x00020000,
    UNIT_FLAG_STUNNED               = 0x00040000,           // Unit is a subject to stun, turn and strafe movement disabled
    UNIT_FLAG_IN_COMBAT             = 0x00080000,
    UNIT_FLAG_TAXI_FLIGHT           = 0x00100000,           // Unit is on taxi, paired with a duplicate loss of client control packet (likely a legacy serverside hack). Disables any spellcasts not allowed in taxi flight client-side.
    UNIT_FLAG_CONFUSED              = 0x00400000,           // Unit is a subject to confused movement, movement checks disabled, paired with loss of client control packet.
    UNIT_FLAG_FLEEING               = 0x00800000,           // Unit is a subject to fleeing movement, movement checks disabled, paired with loss of client control packet.
    UNIT_FLAG_POSSESSED             = 0x01000000,           // Unit is under remote control by another unit, movement checks disabled, paired with loss of client control packet. New master is allowed to use melee attack and can't select this unit via mouse in the world (as if it was own character).
    UNIT_FLAG_NOT_SELECTABLE        = 0x02000000,
    UNIT_FLAG_SKINNABLE             = 0x04000000,
    UNIT_FLAG_AURAS_VISIBLE         = 0x08000000,           // magic detect
    UNIT_FLAG_SHEATHE               = 0x40000000,
    UNIT_FLAG_IMMUNE                = 0x80000000,           // Immune to damage

    // [-ZERO] TBC enumerations [?]
    UNIT_FLAG_NOT_ATTACKABLE_1      = 0x00000080,           // ?? (UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE
    UNIT_FLAG_LOOTING               = 0x00000400,           // loot animation
    UNIT_FLAG_PET_IN_COMBAT         = 0x00000800,           // in combat?, 2.0.8
    UNIT_FLAG_DISARMED              = 0x00200000,           // disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.

    UNIT_FLAG_UNK_28                = 0x10000000,
    UNIT_FLAG_UNK_29                = 0x20000000,           // used in Feing Death spell
};

/// Non Player Character flags
enum NPCFlags
{
    UNIT_NPC_FLAG_NONE                  = 0x00000000,
    UNIT_NPC_FLAG_GOSSIP                = 0x00000001,       // 100%
    UNIT_NPC_FLAG_QUESTGIVER            = 0x00000002,       // 100%
    UNIT_NPC_FLAG_VENDOR                = 0x00000004,       // 100%
    UNIT_NPC_FLAG_FLIGHTMASTER          = 0x00000008,       // 100%
    UNIT_NPC_FLAG_TRAINER               = 0x00000010,       // 100%
    UNIT_NPC_FLAG_SPIRITHEALER          = 0x00000020,       // guessed
    UNIT_NPC_FLAG_SPIRITGUIDE           = 0x00000040,       // guessed
    UNIT_NPC_FLAG_INNKEEPER             = 0x00000080,       // 100%
    UNIT_NPC_FLAG_BANKER                = 0x00000100,       // 100%
    UNIT_NPC_FLAG_PETITIONER            = 0x00000200,       // 100% 0xC0000 = guild petitions
    UNIT_NPC_FLAG_TABARDDESIGNER        = 0x00000400,       // 100%
    UNIT_NPC_FLAG_BATTLEMASTER          = 0x00000800,       // 100%
    UNIT_NPC_FLAG_AUCTIONEER            = 0x00001000,       // 100%
    UNIT_NPC_FLAG_STABLEMASTER          = 0x00002000,       // 100%
    UNIT_NPC_FLAG_REPAIR                = 0x00004000,       // 100%
    UNIT_NPC_FLAG_OUTDOORPVP            = 0x20000000,       // custom flag for outdoor pvp creatures || Custom flag
};

enum AutoAttackCheckResult
{
    ATTACK_RESULT_OK = 0,
    ATTACK_RESULT_NOT_IN_RANGE = 1,
    ATTACK_RESULT_BAD_FACING = 2,
    ATTACK_RESULT_CANT_ATTACK = 3,
    ATTACK_RESULT_DEAD = 4,
    ATTACK_RESULT_FRIENDLY_TARGET = 5,
};

enum ActiveStates
{
    ACT_PASSIVE  = 0x01,                                    // 0x01 - passive
    ACT_DISABLED = 0x81,                                    // 0x80 - castable
    ACT_ENABLED  = 0xC1,                                    // 0x40 | 0x80 - auto cast + castable
    ACT_COMMAND  = 0x07,                                    // 0x01 | 0x02 | 0x04
    ACT_REACTION = 0x06,                                    // 0x02 | 0x04
    ACT_DECIDE   = 0x00                                     // custom
};

enum ReactStates
{
    REACT_PASSIVE    = 0,
    REACT_DEFENSIVE  = 1,
    REACT_AGGRESSIVE = 2
};

enum CommandStates
{
    COMMAND_STAY    = 0,
    COMMAND_FOLLOW  = 1,
    COMMAND_ATTACK  = 2,
    COMMAND_DISMISS = 3
};

enum ActionBarIndex
{
    ACTION_BAR_INDEX_START = 0,
    ACTION_BAR_INDEX_PET_SPELL_START = 3,
    ACTION_BAR_INDEX_PET_SPELL_END = 7,
    ACTION_BAR_INDEX_END = 10,
};

#define MAX_UNIT_ACTION_BAR_INDEX (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START)

// used in CallForAllControlledUnits/CheckAllControlledUnits
enum ControlledUnitMask
{
    CONTROLLED_PET = 0x01,
    CONTROLLED_MINIPET = 0x02,
    CONTROLLED_GUARDIANS = 0x04,                            // including PROTECTOR_PET
    CONTROLLED_CHARM = 0x08,
    CONTROLLED_TOTEMS = 0x10,
};

// for clearing special attacks
#define REACTIVE_TIMER_START 4000

enum ReactiveType
{
    REACTIVE_DEFENSE = 1,
    REACTIVE_HUNTER_PARRY = 2,
    REACTIVE_CRIT = 3,
    //REACTIVE_HUNTER_CRIT  = 4,
    REACTIVE_OVERPOWER = 5
};

#define MAX_REACTIVE 6

// for Unit::AddAura
enum AddAuraFlags
{
    ADD_AURA_NO_OPTION = 0x00,
    ADD_AURA_POSITIVE = 0x01,
    ADD_AURA_NEGATIVE = 0x02,
    ADD_AURA_PASSIVE = 0x04,
    ADD_AURA_PERMANENT = 0x08,
};


enum UnitDebugFlags
{
    DEBUG_SPELL_COMPUTE_RESISTS = 0x01,
    DEBUG_PACKETS_RECV          = 0x02,
    DEBUG_PACKETS_SEND          = 0x04,
    DEBUG_AI                    = 0x08,
    DEBUG_DR                    = 0x10,
    DEBUG_CHEAT                 = 0x20,
    DEBUG_PROCS                 = 0x40,
    DEBUG_SPELLS_DAMAGE         = 0x80,
};


enum TeleportToOptions
{
    TELE_TO_GM_MODE             = 0x01,
    TELE_TO_NOT_LEAVE_TRANSPORT = 0x02,
    TELE_TO_NOT_LEAVE_COMBAT    = 0x04,
    TELE_TO_NOT_UNSUMMON_PET    = 0x08,
    TELE_TO_SPELL               = 0x10,
    TELE_TO_FORCE_MAP_CHANGE    = 0x20,
};

#define UNIT_DEFAULT_MELEE_Z_LIMIT 36                                    // vertical range diff limit for melee attacks (no meleeing units that fly too high overhead)

enum MovementModType
{
    MOV_MOD_FLEE_FOR_ASSISTANCE = 0,
    MOV_MOD_FLEE_IN_FEAR        = 1,
    MOV_MOD_CONFUSED            = 2
};

enum UnitMountResult
{
    MOUNTRESULT_INVALIDMOUNTEE  = 0,    // You can't mount that unit!
    MOUNTRESULT_TOOFARAWAY      = 1,    // That mount is too far away!
    MOUNTRESULT_ALREADYMOUNTED  = 2,    // You're already mounted!
    MOUNTRESULT_NOTMOUNTABLE    = 3,    // That unit can't be mounted!
    MOUNTRESULT_NOTYOURPET      = 4,    // That mount isn't your pet!
    MOUNTRESULT_OTHER           = 5,    // internal
    MOUNTRESULT_LOOTING         = 6,    // You can't mount while looting!
    MOUNTRESULT_RACECANTMOUNT   = 7,    // You can't mount because of your race!
    MOUNTRESULT_SHAPESHIFTED    = 8,    // You can't mount while shapeshifted!
    MOUNTRESULT_FORCEDDISMOUNT  = 9,    // You dismount before continuing.
    MOUNTRESULT_OK              = 10    // no error
};

enum UnitDismountResult
{
    DISMOUNTRESULT_NOPET        = 0,    // internal
    DISMOUNTRESULT_NOTMOUNTED   = 1,    // You're not mounted!
    DISMOUNTRESULT_NOTYOURPET   = 2,    // internal
    DISMOUNTRESULT_OK           = 3     // no error
};

// First entry in CreatureDisplayInfo.dbc
#define UNIT_DISPLAY_ID_BOX 4

enum ModelIds
{
    MODEL_HUMAN_MALE    = 49,
    MODEL_HUMAN_FEMALE  = 50,
    MODEL_ORC_MALE      = 51,
    MODEL_ORC_FEMALE    = 52,
    MODEL_DWARF_MALE    = 53,
    MODEL_DWARF_FEMALE  = 54,
    MODEL_NELF_MALE     = 55,
    MODEL_NELF_FEMALE   = 56,
    MODEL_UNDEAD_MALE   = 57,
    MODEL_UNDEAD_FEMALE = 58,
    MODEL_TAUREN_MALE   = 59,
    MODEL_TAUREN_FEMALE = 60,
    MODEL_GNOME_MALE    = 182,
    MODEL_GNOME_FEMALE  = 183,
    MODEL_TROLL_MALE    = 185,
    MODEL_TROLL_FEMALE  = 186,
};

#endif
