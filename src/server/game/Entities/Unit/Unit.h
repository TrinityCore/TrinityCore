/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __UNIT_H
#define __UNIT_H

#include "EventProcessor.h"
#include "FollowerReference.h"
#include "FollowerRefManager.h"
#include "HostileRefManager.h"
#include "MotionMaster.h"
#include "Object.h"
#include "SpellAuraDefines.h"
#include "ThreatManager.h"
#include "MoveSplineInit.h"
#include <boost/container/flat_set.hpp>

#define WORLD_TRIGGER   12999
#define ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE 197886
#define SPELL_DH_DOUBLE_JUMP 196055

enum SpellInterruptFlags
{
    SPELL_INTERRUPT_FLAG_MOVEMENT     = 0x01, // why need this for instant?
    SPELL_INTERRUPT_FLAG_PUSH_BACK    = 0x02, // push back
    SPELL_INTERRUPT_FLAG_UNK3         = 0x04, // any info?
    SPELL_INTERRUPT_FLAG_INTERRUPT    = 0x08, // interrupt
    SPELL_INTERRUPT_FLAG_ABORT_ON_DMG = 0x10  // _complete_ interrupt on direct damage
    //SPELL_INTERRUPT_UNK             = 0x20                // unk, 564 of 727 spells having this spell start with "Glyph"
};

// See SpellAuraInterruptFlags for other values definitions
enum SpellChannelInterruptFlags
{
    CHANNEL_INTERRUPT_FLAG_INTERRUPT    = 0x08,  // interrupt
    CHANNEL_FLAG_DELAY                  = 0x4000
};

enum SpellAuraInterruptFlags : uint32
{
    AURA_INTERRUPT_FLAG_HITBYSPELL          = 0x00000001,   // 0    removed when getting hit by a negative spell?
    AURA_INTERRUPT_FLAG_TAKE_DAMAGE         = 0x00000002,   // 1    removed by any damage
    AURA_INTERRUPT_FLAG_CAST                = 0x00000004,   // 2    cast any spells
    AURA_INTERRUPT_FLAG_MOVE                = 0x00000008,   // 3    removed by any movement
    AURA_INTERRUPT_FLAG_TURNING             = 0x00000010,   // 4    removed by any turning
    AURA_INTERRUPT_FLAG_JUMP                = 0x00000020,   // 5    removed by entering combat
    AURA_INTERRUPT_FLAG_NOT_MOUNTED         = 0x00000040,   // 6    removed by dismounting
    AURA_INTERRUPT_FLAG_NOT_ABOVEWATER      = 0x00000080,   // 7    removed by entering water
    AURA_INTERRUPT_FLAG_NOT_UNDERWATER      = 0x00000100,   // 8    removed by leaving water
    AURA_INTERRUPT_FLAG_NOT_SHEATHED        = 0x00000200,   // 9    removed by unsheathing
    AURA_INTERRUPT_FLAG_TALK                = 0x00000400,   // 10   talk to npc / loot? action on creature
    AURA_INTERRUPT_FLAG_USE                 = 0x00000800,   // 11   mine/use/open action on gameobject
    AURA_INTERRUPT_FLAG_MELEE_ATTACK        = 0x00001000,   // 12   removed by attacking
    AURA_INTERRUPT_FLAG_SPELL_ATTACK        = 0x00002000,   // 13   ???
    AURA_INTERRUPT_FLAG_UNK14               = 0x00004000,   // 14
    AURA_INTERRUPT_FLAG_TRANSFORM           = 0x00008000,   // 15   removed by transform?
    AURA_INTERRUPT_FLAG_UNK16               = 0x00010000,   // 16
    AURA_INTERRUPT_FLAG_MOUNT               = 0x00020000,   // 17   misdirect, aspect, swim speed
    AURA_INTERRUPT_FLAG_NOT_SEATED          = 0x00040000,   // 18   removed by standing up (used by food and drink mostly and sleep/Fake Death like)
    AURA_INTERRUPT_FLAG_CHANGE_MAP          = 0x00080000,   // 19   leaving map/getting teleported
    AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION    = 0x00100000,   // 20   removed by auras that make you invulnerable, or make other to lose selection on you
    AURA_INTERRUPT_FLAG_UNK21               = 0x00200000,   // 21
    AURA_INTERRUPT_FLAG_TELEPORTED          = 0x00400000,   // 22
    AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT    = 0x00800000,   // 23   removed by entering pvp combat
    AURA_INTERRUPT_FLAG_DIRECT_DAMAGE       = 0x01000000,   // 24   removed by any direct damage
    AURA_INTERRUPT_FLAG_LANDING             = 0x02000000,   // 25   removed by hitting the ground
    AURA_INTERRUPT_FLAG_LEAVE_COMBAT        = 0x80000000,   // 31   removed by leaving combat

    AURA_INTERRUPT_FLAG_NOT_VICTIM = (AURA_INTERRUPT_FLAG_HITBYSPELL | AURA_INTERRUPT_FLAG_TAKE_DAMAGE | AURA_INTERRUPT_FLAG_DIRECT_DAMAGE)
};

enum SpellModOp
{
    SPELLMOD_DAMAGE                 = 0,
    SPELLMOD_DURATION               = 1,
    SPELLMOD_THREAT                 = 2,
    SPELLMOD_EFFECT1                = 3,
    SPELLMOD_CHARGES                = 4,
    SPELLMOD_RANGE                  = 5,
    SPELLMOD_RADIUS                 = 6,
    SPELLMOD_CRITICAL_CHANCE        = 7,
    SPELLMOD_ALL_EFFECTS            = 8,
    SPELLMOD_NOT_LOSE_CASTING_TIME  = 9,
    SPELLMOD_CASTING_TIME           = 10,
    SPELLMOD_COOLDOWN               = 11,
    SPELLMOD_EFFECT2                = 12,
    SPELLMOD_IGNORE_ARMOR           = 13,
    SPELLMOD_COST                   = 14, // Used when SpellPowerEntry::PowerIndex == 0
    SPELLMOD_CRIT_DAMAGE_BONUS      = 15,
    SPELLMOD_RESIST_MISS_CHANCE     = 16,
    SPELLMOD_JUMP_TARGETS           = 17,
    SPELLMOD_CHANCE_OF_SUCCESS      = 18,
    SPELLMOD_ACTIVATION_TIME        = 19,
    SPELLMOD_DAMAGE_MULTIPLIER      = 20,
    SPELLMOD_GLOBAL_COOLDOWN        = 21,
    SPELLMOD_DOT                    = 22,
    SPELLMOD_EFFECT3                = 23,
    SPELLMOD_BONUS_MULTIPLIER       = 24,
    // spellmod 25
    SPELLMOD_PROC_PER_MINUTE        = 26,
    SPELLMOD_VALUE_MULTIPLIER       = 27,
    SPELLMOD_RESIST_DISPEL_CHANCE   = 28,
    SPELLMOD_CRIT_DAMAGE_BONUS_2    = 29, //one not used spell
    SPELLMOD_SPELL_COST_REFUND_ON_FAIL = 30,
    SPELLMOD_STACK_AMOUNT           = 31, // has no effect on tooltip parsing
    SPELLMOD_EFFECT4                = 32,
    SPELLMOD_EFFECT5                = 33,
    SPELLMOD_SPELL_COST2            = 34, // Used when SpellPowerEntry::PowerIndex == 1
    SPELLMOD_JUMP_DISTANCE          = 35,
    SPELLMOD_STACK_AMOUNT2          = 37  // same as SPELLMOD_STACK_AMOUNT but affects tooltips
};

#define MAX_SPELLMOD 39

enum SpellValueMod
{
    SPELLVALUE_BASE_POINT0,
    SPELLVALUE_BASE_POINT1,
    SPELLVALUE_BASE_POINT2,
    SPELLVALUE_BASE_POINT3,
    SPELLVALUE_BASE_POINT4,
    SPELLVALUE_BASE_POINT5,
    SPELLVALUE_BASE_POINT6,
    SPELLVALUE_BASE_POINT7,
    SPELLVALUE_BASE_POINT8,
    SPELLVALUE_BASE_POINT9,
    SPELLVALUE_BASE_POINT10,
    SPELLVALUE_BASE_POINT11,
    SPELLVALUE_BASE_POINT12,
    SPELLVALUE_BASE_POINT13,
    SPELLVALUE_BASE_POINT14,
    SPELLVALUE_BASE_POINT15,
    SPELLVALUE_BASE_POINT16,
    SPELLVALUE_BASE_POINT17,
    SPELLVALUE_BASE_POINT18,
    SPELLVALUE_BASE_POINT19,
    SPELLVALUE_BASE_POINT20,
    SPELLVALUE_BASE_POINT21,
    SPELLVALUE_BASE_POINT22,
    SPELLVALUE_BASE_POINT23,
    SPELLVALUE_BASE_POINT24,
    SPELLVALUE_BASE_POINT25,
    SPELLVALUE_BASE_POINT26,
    SPELLVALUE_BASE_POINT27,
    SPELLVALUE_BASE_POINT28,
    SPELLVALUE_BASE_POINT29,
    SPELLVALUE_BASE_POINT30,
    SPELLVALUE_BASE_POINT31,
    SPELLVALUE_BASE_POINT_END,
    SPELLVALUE_RADIUS_MOD,
    SPELLVALUE_MAX_TARGETS,
    SPELLVALUE_AURA_STACK
};

class CustomSpellValues
{
    typedef std::pair<SpellValueMod, int32> CustomSpellValueMod;
    typedef std::vector<CustomSpellValueMod> StorageType;

public:
    typedef StorageType::const_iterator const_iterator;

public:
    void AddSpellMod(SpellValueMod mod, int32 value)
    {
        storage_.push_back(CustomSpellValueMod(mod, value));
    }

    const_iterator begin() const
    {
        return storage_.begin();
    }

    const_iterator end() const
    {
        return storage_.end();
    }

private:
    StorageType storage_;
};

enum SpellFacingFlags
{
    SPELL_FACING_FLAG_INFRONT = 0x0001
};

#define BASE_MINDAMAGE 1.0f
#define BASE_MAXDAMAGE 2.0f
#define BASE_ATTACK_TIME 2000

// byte value (UNIT_FIELD_BYTES_1, 0)
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
    UNIT_STAND_STATE_KNEEL             = 8,
    UNIT_STAND_STATE_SUBMERGED         = 9
};

// byte flag value (UNIT_FIELD_BYTES_1, 2)
enum UnitStandFlags
{
    UNIT_STAND_FLAGS_UNK1         = 0x01,
    UNIT_STAND_FLAGS_CREEP        = 0x02,
    UNIT_STAND_FLAGS_UNTRACKABLE  = 0x04,
    UNIT_STAND_FLAGS_UNK4         = 0x08,
    UNIT_STAND_FLAGS_UNK5         = 0x10,
    UNIT_STAND_FLAGS_ALL          = 0xFF
};

enum UnitBytes0Offsets
{
    UNIT_BYTES_0_OFFSET_RACE            = 0,
    UNIT_BYTES_0_OFFSET_CLASS           = 1,
    UNIT_BYTES_0_OFFSET_PLAYER_CLASS    = 2,
    UNIT_BYTES_0_OFFSET_GENDER          = 3
};

enum UnitBytes1Offsets
{
    UNIT_BYTES_1_OFFSET_STAND_STATE = 0,
    UNIT_BYTES_1_OFFSET_PET_TALENTS = 1,    // unused
    UNIT_BYTES_1_OFFSET_VIS_FLAG    = 2,
    UNIT_BYTES_1_OFFSET_ANIM_TIER   = 3
};

enum UnitBytes2Offsets
{
    UNIT_BYTES_2_OFFSET_SHEATH_STATE    = 0,
    UNIT_BYTES_2_OFFSET_PVP_FLAG        = 1,
    UNIT_BYTES_2_OFFSET_PET_FLAGS       = 2,
    UNIT_BYTES_2_OFFSET_SHAPESHIFT_FORM = 3
};

// byte flags value (UNIT_FIELD_BYTES_1, 3)
enum UnitBytes1_Flags
{
    UNIT_BYTE1_FLAG_ALWAYS_STAND    = 0x01,
    UNIT_BYTE1_FLAG_HOVER           = 0x02,
    UNIT_BYTE1_FLAG_UNK_3           = 0x04,
    UNIT_BYTE1_FLAG_ALL             = 0xFF
};

// high byte (3 from 0..3) of UNIT_FIELD_BYTES_2
enum ShapeshiftForm
{
    FORM_NONE                       = 0,
    FORM_CAT_FORM                   = 1,
    FORM_TREE_OF_LIFE               = 2,
    FORM_TRAVEL_FORM                = 3,
    FORM_AQUATIC_FORM               = 4,
    FORM_BEAR_FORM                  = 5,
    FORM_AMBIENT                    = 6,
    FORM_GHOUL                      = 7,
    FORM_DIRE_BEAR_FORM             = 8,
    FORM_CRANE_STANCE               = 9,
    FORM_THARONJA_SKELETON          = 10,
    FORM_DARKMOON_TEST_OF_STRENGTH  = 11,
    FORM_BLB_PLAYER                 = 12,
    FORM_SHADOW_DANCE               = 13,
    FORM_CREATURE_BEAR              = 14,
    FORM_CREATURE_CAT               = 15,
    FORM_GHOST_WOLF                 = 16,
    FORM_BATTLE_STANCE              = 17,
    FORM_DEFENSIVE_STANCE           = 18,
    FORM_BERSERKER_STANCE           = 19,
    FORM_SERPENT_STANCE             = 20,
    FORM_ZOMBIE                     = 21,
    FORM_METAMORPHOSIS              = 22,
    FORM_OX_STANCE                  = 23,
    FORM_TIGER_STANCE               = 24,
    FORM_UNDEAD                     = 25,
    FORM_FRENZY                     = 26,
    FORM_FLIGHT_FORM_EPIC           = 27,
    FORM_SHADOWFORM                 = 28,
    FORM_FLIGHT_FORM                = 29,
    FORM_STEALTH                    = 30,
    FORM_MOONKIN_FORM               = 31,
    FORM_SPIRIT_OF_REDEMPTION       = 32,
    FORM_GLADIATOR_STANCE           = 33
};

// low byte (0 from 0..3) of UNIT_FIELD_BYTES_2
enum SheathState : uint8
{
    SHEATH_STATE_UNARMED  = 0,                              // non prepared weapon
    SHEATH_STATE_MELEE    = 1,                              // prepared melee weapon
    SHEATH_STATE_RANGED   = 2                               // prepared ranged weapon
};

#define MAX_SHEATH_STATE    3

// byte (1 from 0..3) of UNIT_FIELD_BYTES_2
enum UnitPVPStateFlags
{
    UNIT_BYTE2_FLAG_PVP         = 0x01,
    UNIT_BYTE2_FLAG_UNK1        = 0x02,
    UNIT_BYTE2_FLAG_FFA_PVP     = 0x04,
    UNIT_BYTE2_FLAG_SANCTUARY   = 0x08,
    UNIT_BYTE2_FLAG_UNK4        = 0x10,
    UNIT_BYTE2_FLAG_UNK5        = 0x20,
    UNIT_BYTE2_FLAG_UNK6        = 0x40,
    UNIT_BYTE2_FLAG_UNK7        = 0x80
};

// byte (2 from 0..3) of UNIT_FIELD_BYTES_2
enum UnitRename
{
    UNIT_CAN_BE_RENAMED     = 0x01,
    UNIT_CAN_BE_ABANDONED   = 0x02
};

#define MAX_SPELL_CHARM         4
#define MAX_SPELL_VEHICLE       6
#define MAX_SPELL_POSSESS       8
#define MAX_SPELL_CONTROL_BAR   10

#define MAX_AGGRO_RESET_TIME 10 // in seconds
#define MAX_AGGRO_RADIUS 45.0f  // yards

enum VictimState
{
    VICTIMSTATE_INTACT         = 0, // set when attacker misses
    VICTIMSTATE_HIT            = 1, // victim got clear/blocked hit
    VICTIMSTATE_DODGE          = 2,
    VICTIMSTATE_PARRY          = 3,
    VICTIMSTATE_INTERRUPT      = 4,
    VICTIMSTATE_BLOCKS         = 5, // unused? not set when blocked, even on full block
    VICTIMSTATE_EVADES         = 6,
    VICTIMSTATE_IS_IMMUNE      = 7,
    VICTIMSTATE_DEFLECTS       = 8
};

enum HitInfo
{
    HITINFO_NORMALSWING         = 0x00000000,
    HITINFO_UNK1                = 0x00000001,               // req correct packet structure
    HITINFO_AFFECTS_VICTIM      = 0x00000002,
    HITINFO_OFFHAND             = 0x00000004,
    HITINFO_UNK2                = 0x00000008,
    HITINFO_MISS                = 0x00000010,
    HITINFO_FULL_ABSORB         = 0x00000020,
    HITINFO_PARTIAL_ABSORB      = 0x00000040,
    HITINFO_FULL_RESIST         = 0x00000080,
    HITINFO_PARTIAL_RESIST      = 0x00000100,
    HITINFO_CRITICALHIT         = 0x00000200,               // critical hit
    HITINFO_UNK10               = 0x00000400,
    HITINFO_UNK11               = 0x00000800,
    HITINFO_UNK12               = 0x00001000,
    HITINFO_BLOCK               = 0x00002000,               // blocked damage
    HITINFO_UNK14               = 0x00004000,               // set only if meleespellid is present//  no world text when victim is hit for 0 dmg(HideWorldTextForNoDamage?)
    HITINFO_UNK15               = 0x00008000,               // player victim?// something related to blod sprut visual (BloodSpurtInBack?)
    HITINFO_GLANCING            = 0x00010000,
    HITINFO_CRUSHING            = 0x00020000,
    HITINFO_NO_ANIMATION        = 0x00040000,
    HITINFO_UNK19               = 0x00080000,
    HITINFO_UNK20               = 0x00100000,
    HITINFO_SWINGNOHITSOUND     = 0x00200000,               // unused?
    HITINFO_UNK22               = 0x00400000,
    HITINFO_RAGE_GAIN           = 0x00800000,
    HITINFO_FAKE_DAMAGE         = 0x01000000                // enables damage animation even if no damage done, set only if no damage
};

//i would like to remove this: (it is defined in item.h
enum InventorySlot
{
    NULL_BAG                   = 0,
    NULL_SLOT                  = 255
};

struct FactionTemplateEntry;
struct LiquidTypeEntry;
struct MountCapabilityEntry;
struct SpellValue;

class AuraApplication;
class Aura;
class UnitAura;
class AuraEffect;
class Creature;
class Spell;
class SpellInfo;
class SpellEffectInfo;
class SpellHistory;
class DynamicObject;
class GameObject;
class Item;
class Pet;
class PetAura;
class Minion;
class Guardian;
class UnitAI;
class Totem;
class Transport;
class Vehicle;
class VehicleJoinEvent;
class TransportBase;
class SpellCastTargets;
namespace Movement
{
    class MoveSpline;
}
namespace WorldPackets
{
    namespace CombatLog
    {
        class CombatLogServerPacket;
    }
}

typedef std::list<Unit*> UnitList;
typedef std::list<std::pair<Aura*, uint8>> DispelChargesList;

struct SpellImmune
{
    uint32 type;
    uint32 spellId;
};

typedef std::list<SpellImmune> SpellImmuneList;

enum UnitModifierType
{
    BASE_VALUE = 0,
    BASE_PCT_EXCLUDE_CREATE = 1,    // percent modifier affecting all stat values from auras and gear but not player base for level
    BASE_PCT = 2,
    TOTAL_VALUE = 3,
    TOTAL_PCT = 4,
    MODIFIER_TYPE_END = 5
};

enum WeaponDamageRange
{
    MINDAMAGE,
    MAXDAMAGE
};

enum AuraRemoveMode
{
    AURA_REMOVE_NONE = 0,
    AURA_REMOVE_BY_DEFAULT = 1,       // scripted remove, remove by stack with aura with different ids and sc aura remove
    AURA_REMOVE_BY_CANCEL,
    AURA_REMOVE_BY_ENEMY_SPELL,       // dispel and absorb aura destroy
    AURA_REMOVE_BY_EXPIRE,            // aura duration has ended
    AURA_REMOVE_BY_DEATH
};

enum TriggerCastFlags
{
    TRIGGERED_NONE                                  = 0x00000000,   //! Not triggered
    TRIGGERED_IGNORE_GCD                            = 0x00000001,   //! Will ignore GCD
    TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD          = 0x00000002,   //! Will ignore Spell and Category cooldowns
    TRIGGERED_IGNORE_POWER_AND_REAGENT_COST         = 0x00000004,   //! Will ignore power and reagent cost
    TRIGGERED_IGNORE_CAST_ITEM                      = 0x00000008,   //! Will not take away cast item or update related achievement criteria
    TRIGGERED_IGNORE_AURA_SCALING                   = 0x00000010,   //! Will ignore aura scaling
    TRIGGERED_IGNORE_CAST_IN_PROGRESS               = 0x00000020,   //! Will not check if a current cast is in progress
    TRIGGERED_IGNORE_COMBO_POINTS                   = 0x00000040,   //! Will ignore combo point requirement
    TRIGGERED_CAST_DIRECTLY                         = 0x00000080,   //! In Spell::prepare, will be cast directly without setting containers for executed spell
    TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS           = 0x00000100,   //! Will ignore interruptible aura's at cast
    TRIGGERED_IGNORE_SET_FACING                     = 0x00000200,   //! Will not adjust facing to target (if any)
    TRIGGERED_IGNORE_SHAPESHIFT                     = 0x00000400,   //! Will ignore shapeshift checks
    TRIGGERED_IGNORE_CASTER_AURASTATE               = 0x00000800,   //! Will ignore caster aura states including combat requirements and death state
    TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE   = 0x00002000,   //! Will ignore mounted/on vehicle restrictions
    TRIGGERED_IGNORE_CASTER_AURAS                   = 0x00010000,   //! Will ignore caster aura restrictions or requirements
    TRIGGERED_DISALLOW_PROC_EVENTS                  = 0x00020000,   //! Disallows proc events from triggered spell (default)
    TRIGGERED_DONT_REPORT_CAST_ERROR                = 0x00040000,   //! Will return SPELL_FAILED_DONT_REPORT in CheckCast functions
    TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT      = 0x00080000,   //! Will ignore equipped item requirements
    TRIGGERED_IGNORE_TARGET_CHECK                   = 0x00100000,   //! Will ignore most target checks (mostly DBC target checks)
    TRIGGERED_FULL_MASK                             = 0xFFFFFFFF
};

enum UnitMods
{
    UNIT_MOD_STAT_STRENGTH,                                 // UNIT_MOD_STAT_STRENGTH..UNIT_MOD_STAT_INTELLECT must be in existed order, it's accessed by index values of Stats enum.
    UNIT_MOD_STAT_AGILITY,
    UNIT_MOD_STAT_STAMINA,
    UNIT_MOD_STAT_INTELLECT,
    UNIT_MOD_HEALTH,
    UNIT_MOD_MANA,                                          // UNIT_MOD_MANA..UNIT_MOD_RUNIC_POWER must be in existed order, it's accessed by index values of Powers enum.
    UNIT_MOD_RAGE,
    UNIT_MOD_FOCUS,
    UNIT_MOD_ENERGY,
    UNIT_MOD_UNUSED,                                        // Old UNIT_MOD_HAPPINESS
    UNIT_MOD_RUNE,
    UNIT_MOD_RUNIC_POWER,
    UNIT_MOD_SOUL_SHARDS,
    UNIT_MOD_ECLIPSE,
    UNIT_MOD_HOLY_POWER,
    UNIT_MOD_ALTERNATIVE,
    UNIT_MOD_MAELSTROM,
    UNIT_MOD_CHI,
    UNIT_MOD_INSANITY,
    UNIT_MOD_BURNING_EMBERS,
    UNIT_MOD_DEMONIC_FURY,
    UNIT_MOD_ARCANE_CHARGES,
    UNIT_MOD_FURY,
    UNIT_MOD_PAIN,
    UNIT_MOD_ARMOR,                                         // UNIT_MOD_ARMOR..UNIT_MOD_RESISTANCE_ARCANE must be in existed order, it's accessed by index values of SpellSchools enum.
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
    UNIT_MOD_END,
    // synonyms
    UNIT_MOD_STAT_START = UNIT_MOD_STAT_STRENGTH,
    UNIT_MOD_STAT_END = UNIT_MOD_STAT_INTELLECT + 1,
    UNIT_MOD_RESISTANCE_START = UNIT_MOD_ARMOR,
    UNIT_MOD_RESISTANCE_END = UNIT_MOD_RESISTANCE_ARCANE + 1,
    UNIT_MOD_POWER_START = UNIT_MOD_MANA,
    UNIT_MOD_POWER_END = UNIT_MOD_PAIN + 1
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
    PCT_MOD,
    MOD_END
};

enum DeathState
{
    ALIVE          = 0,
    JUST_DIED      = 1,
    CORPSE         = 2,
    DEAD           = 3,
    JUST_RESPAWNED = 4
};

enum UnitState
{
    UNIT_STATE_DIED            = 0x00000001,                     // player has fake death aura
    UNIT_STATE_MELEE_ATTACKING = 0x00000002,                     // player is melee attacking someone
    //UNIT_STATE_MELEE_ATTACK_BY = 0x00000004,                     // player is melee attack by someone
    UNIT_STATE_STUNNED         = 0x00000008,
    UNIT_STATE_ROAMING         = 0x00000010,
    UNIT_STATE_CHASE           = 0x00000020,
    //UNIT_STATE_SEARCHING       = 0x00000040,
    UNIT_STATE_FLEEING         = 0x00000080,
    UNIT_STATE_IN_FLIGHT       = 0x00000100,                     // player is in flight mode
    UNIT_STATE_FOLLOW          = 0x00000200,
    UNIT_STATE_ROOT            = 0x00000400,
    UNIT_STATE_CONFUSED        = 0x00000800,
    UNIT_STATE_DISTRACTED      = 0x00001000,
    UNIT_STATE_ISOLATED        = 0x00002000,                     // area auras do not affect other players
    UNIT_STATE_ATTACK_PLAYER   = 0x00004000,
    UNIT_STATE_CASTING         = 0x00008000,
    UNIT_STATE_POSSESSED       = 0x00010000,
    UNIT_STATE_CHARGING        = 0x00020000,
    UNIT_STATE_JUMPING         = 0x00040000,
    UNIT_STATE_MOVE            = 0x00100000,
    UNIT_STATE_ROTATING        = 0x00200000,
    UNIT_STATE_EVADE           = 0x00400000,
    UNIT_STATE_ROAMING_MOVE    = 0x00800000,
    UNIT_STATE_CONFUSED_MOVE   = 0x01000000,
    UNIT_STATE_FLEEING_MOVE    = 0x02000000,
    UNIT_STATE_CHASE_MOVE      = 0x04000000,
    UNIT_STATE_FOLLOW_MOVE     = 0x08000000,
    UNIT_STATE_IGNORE_PATHFINDING = 0x10000000,                 // do not use pathfinding in any MovementGenerator
    UNIT_STATE_ALL_STATE_SUPPORTED = UNIT_STATE_DIED | UNIT_STATE_MELEE_ATTACKING | UNIT_STATE_STUNNED | UNIT_STATE_ROAMING | UNIT_STATE_CHASE
                                   | UNIT_STATE_FLEEING | UNIT_STATE_IN_FLIGHT | UNIT_STATE_FOLLOW | UNIT_STATE_ROOT | UNIT_STATE_CONFUSED
                                   | UNIT_STATE_DISTRACTED | UNIT_STATE_ISOLATED | UNIT_STATE_ATTACK_PLAYER | UNIT_STATE_CASTING
                                   | UNIT_STATE_POSSESSED | UNIT_STATE_CHARGING | UNIT_STATE_JUMPING | UNIT_STATE_MOVE | UNIT_STATE_ROTATING
                                   | UNIT_STATE_EVADE | UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE
                                   | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE | UNIT_STATE_IGNORE_PATHFINDING,
    UNIT_STATE_UNATTACKABLE    = UNIT_STATE_IN_FLIGHT,
    // for real move using movegen check and stop (except unstoppable flight)
    UNIT_STATE_MOVING          = UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE,
    UNIT_STATE_CONTROLLED      = (UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING),
    UNIT_STATE_LOST_CONTROL    = (UNIT_STATE_CONTROLLED | UNIT_STATE_JUMPING | UNIT_STATE_CHARGING),
    UNIT_STATE_SIGHTLESS       = (UNIT_STATE_LOST_CONTROL | UNIT_STATE_EVADE),
    UNIT_STATE_CANNOT_AUTOATTACK     = (UNIT_STATE_LOST_CONTROL | UNIT_STATE_CASTING),
    UNIT_STATE_CANNOT_TURN     = (UNIT_STATE_LOST_CONTROL | UNIT_STATE_ROTATING),
    // stay by different reasons
    UNIT_STATE_NOT_MOVE        = UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DIED | UNIT_STATE_DISTRACTED,
    UNIT_STATE_ALL_STATE       = 0xffffffff                      //(UNIT_STATE_STOPPED | UNIT_STATE_MOVING | UNIT_STATE_IN_COMBAT | UNIT_STATE_IN_FLIGHT)
};

enum UnitMoveType
{
    MOVE_WALK           = 0,
    MOVE_RUN            = 1,
    MOVE_RUN_BACK       = 2,
    MOVE_SWIM           = 3,
    MOVE_SWIM_BACK      = 4,
    MOVE_TURN_RATE      = 5,
    MOVE_FLIGHT         = 6,
    MOVE_FLIGHT_BACK    = 7,
    MOVE_PITCH_RATE     = 8
};

#define MAX_MOVE_TYPE     9

TC_GAME_API extern float baseMoveSpeed[MAX_MOVE_TYPE];
TC_GAME_API extern float playerBaseMoveSpeed[MAX_MOVE_TYPE];

enum WeaponAttackType : uint8
{
    BASE_ATTACK   = 0,
    OFF_ATTACK    = 1,
    RANGED_ATTACK = 2,
    MAX_ATTACK
};

enum CombatRating
{
    CR_AMPLIFY                          = 0,
    CR_DEFENSE_SKILL                    = 1,
    CR_DODGE                            = 2,
    CR_PARRY                            = 3,
    CR_BLOCK                            = 4,
    CR_HIT_MELEE                        = 5,
    CR_HIT_RANGED                       = 6,
    CR_HIT_SPELL                        = 7,
    CR_CRIT_MELEE                       = 8,
    CR_CRIT_RANGED                      = 9,
    CR_CRIT_SPELL                       = 10,
    CR_MULTISTRIKE                      = 11,
    CR_READINESS                        = 12,
    CR_SPEED                            = 13,
    CR_RESILIENCE_CRIT_TAKEN            = 14,
    CR_RESILIENCE_PLAYER_DAMAGE         = 15,
    CR_LIFESTEAL                        = 16,
    CR_HASTE_MELEE                      = 17,
    CR_HASTE_RANGED                     = 18,
    CR_HASTE_SPELL                      = 19,
    CR_AVOIDANCE                        = 20,
    CR_STURDINESS                       = 21,
    CR_UNUSED_7                         = 22,
    CR_EXPERTISE                        = 23,
    CR_ARMOR_PENETRATION                = 24,
    CR_MASTERY                          = 25,
    CR_PVP_POWER                        = 26,
    CR_CLEAVE                           = 27,
    CR_VERSATILITY_DAMAGE_DONE          = 28,
    CR_VERSATILITY_HEALING_DONE         = 29,
    CR_VERSATILITY_DAMAGE_TAKEN         = 30,
    CR_UNUSED_12                        = 31
};

#define MAX_COMBAT_RATING         32

enum DamageEffectType
{
    DIRECT_DAMAGE           = 0,                            // used for normal weapon damage (not for class abilities or spells)
    SPELL_DIRECT_DAMAGE     = 1,                            // spell/class abilities damage
    DOT                     = 2,
    HEAL                    = 3,
    NODAMAGE                = 4,                            // used also in case when damage applied to health but not applied to spell channelInterruptFlags/etc
    SELF_DAMAGE             = 5
};

// Value masks for UNIT_FIELD_FLAGS
enum UnitFlags : uint32
{
    UNIT_FLAG_SERVER_CONTROLLED     = 0x00000001,           // set only when unit movement is controlled by server - by SPLINE/MONSTER_MOVE packets, together with UNIT_FLAG_STUNNED; only set to units controlled by client; client function CGUnit_C::IsClientControlled returns false when set for owner
    UNIT_FLAG_NON_ATTACKABLE        = 0x00000002,           // not attackable
    UNIT_FLAG_REMOVE_CLIENT_CONTROL = 0x00000004,           // This is a legacy flag used to disable movement player's movement while controlling other units, SMSG_CLIENT_CONTROL replaces this functionality clientside now. CONFUSED and FLEEING flags have the same effect on client movement asDISABLE_MOVE_CONTROL in addition to preventing spell casts/autoattack (they all allow climbing steeper hills and emotes while moving)
    UNIT_FLAG_PVP_ATTACKABLE        = 0x00000008,           // allow apply pvp rules to attackable state in addition to faction dependent state
    UNIT_FLAG_RENAME                = 0x00000010,
    UNIT_FLAG_PREPARATION           = 0x00000020,           // don't take reagents for spells with SPELL_ATTR5_NO_REAGENT_WHILE_PREP
    UNIT_FLAG_UNK_6                 = 0x00000040,
    UNIT_FLAG_NOT_ATTACKABLE_1      = 0x00000080,           // ?? (UNIT_FLAG_PVP_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE
    UNIT_FLAG_IMMUNE_TO_PC          = 0x00000100,           // disables combat/assistance with PlayerCharacters (PC) - see Unit::_IsValidAttackTarget, Unit::_IsValidAssistTarget
    UNIT_FLAG_IMMUNE_TO_NPC         = 0x00000200,           // disables combat/assistance with NonPlayerCharacters (NPC) - see Unit::_IsValidAttackTarget, Unit::_IsValidAssistTarget
    UNIT_FLAG_LOOTING               = 0x00000400,           // loot animation
    UNIT_FLAG_PET_IN_COMBAT         = 0x00000800,           // in combat?, 2.0.8
    UNIT_FLAG_PVP                   = 0x00001000,           // changed in 3.0.3
    UNIT_FLAG_SILENCED              = 0x00002000,           // silenced, 2.1.1
    UNIT_FLAG_CANNOT_SWIM           = 0x00004000,           // 2.0.8
    UNIT_FLAG_UNK_15                = 0x00008000,
    UNIT_FLAG_UNK_16                = 0x00010000,
    UNIT_FLAG_PACIFIED              = 0x00020000,           // 3.0.3 ok
    UNIT_FLAG_STUNNED               = 0x00040000,           // 3.0.3 ok
    UNIT_FLAG_IN_COMBAT             = 0x00080000,
    UNIT_FLAG_TAXI_FLIGHT           = 0x00100000,           // disable casting at client side spell not allowed by taxi flight (mounted?), probably used with 0x4 flag
    UNIT_FLAG_DISARMED              = 0x00200000,           // 3.0.3, disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.
    UNIT_FLAG_CONFUSED              = 0x00400000,
    UNIT_FLAG_FLEEING               = 0x00800000,
    UNIT_FLAG_PLAYER_CONTROLLED     = 0x01000000,           // used in spell Eyes of the Beast for pet... let attack by controlled creature
    UNIT_FLAG_NOT_SELECTABLE        = 0x02000000,
    UNIT_FLAG_SKINNABLE             = 0x04000000,
    UNIT_FLAG_MOUNT                 = 0x08000000,
    UNIT_FLAG_UNK_28                = 0x10000000,
    UNIT_FLAG_UNK_29                = 0x20000000,           // used in Feing Death spell
    UNIT_FLAG_SHEATHE               = 0x40000000,
    UNIT_FLAG_UNK_31                = 0x80000000,
    MAX_UNIT_FLAGS = 33
};

// Value masks for UNIT_FIELD_FLAGS_2
enum UnitFlags2
{
    UNIT_FLAG2_FEIGN_DEATH                  = 0x00000001,
    UNIT_FLAG2_UNK1                         = 0x00000002,   // Hide unit model (show only player equip)
    UNIT_FLAG2_IGNORE_REPUTATION            = 0x00000004,
    UNIT_FLAG2_COMPREHEND_LANG              = 0x00000008,
    UNIT_FLAG2_MIRROR_IMAGE                 = 0x00000010,
    UNIT_FLAG2_INSTANTLY_APPEAR_MODEL       = 0x00000020,   // Unit model instantly appears when summoned (does not fade in)
    UNIT_FLAG2_FORCE_MOVEMENT               = 0x00000040,
    UNIT_FLAG2_DISARM_OFFHAND               = 0x00000080,
    UNIT_FLAG2_DISABLE_PRED_STATS           = 0x00000100,   // Player has disabled predicted stats (Used by raid frames)
    UNIT_FLAG2_DISARM_RANGED                = 0x00000400,   // this does not disable ranged weapon display (maybe additional flag needed?)
    UNIT_FLAG2_REGENERATE_POWER             = 0x00000800,
    UNIT_FLAG2_RESTRICT_PARTY_INTERACTION   = 0x00001000,   // Restrict interaction to party or raid
    UNIT_FLAG2_PREVENT_SPELL_CLICK          = 0x00002000,   // Prevent spellclick
    UNIT_FLAG2_ALLOW_ENEMY_INTERACT         = 0x00004000,
    UNIT_FLAG2_DISABLE_TURN                 = 0x00008000,
    UNIT_FLAG2_UNK2                         = 0x00010000,
    UNIT_FLAG2_PLAY_DEATH_ANIM              = 0x00020000,   // Plays special death animation upon death
    UNIT_FLAG2_ALLOW_CHEAT_SPELLS           = 0x00040000,   // Allows casting spells with AttributesEx7 & SPELL_ATTR7_IS_CHEAT_SPELL
    UNIT_FLAG2_NO_ACTIONS                   = 0x00800000
};

/// Non Player Character flags
enum NPCFlags : uint64
{
    UNIT_NPC_FLAG_NONE                  = 0x0000000000,
    UNIT_NPC_FLAG_GOSSIP                = 0x0000000001,     // 100%
    UNIT_NPC_FLAG_QUESTGIVER            = 0x0000000002,     // 100%
    UNIT_NPC_FLAG_UNK1                  = 0x0000000004,
    UNIT_NPC_FLAG_UNK2                  = 0x0000000008,
    UNIT_NPC_FLAG_TRAINER               = 0x0000000010,     // 100%
    UNIT_NPC_FLAG_TRAINER_CLASS         = 0x0000000020,     // 100%
    UNIT_NPC_FLAG_TRAINER_PROFESSION    = 0x0000000040,     // 100%
    UNIT_NPC_FLAG_VENDOR                = 0x0000000080,     // 100%
    UNIT_NPC_FLAG_VENDOR_AMMO           = 0x0000000100,     // 100%, general goods vendor
    UNIT_NPC_FLAG_VENDOR_FOOD           = 0x0000000200,     // 100%
    UNIT_NPC_FLAG_VENDOR_POISON         = 0x0000000400,     // guessed
    UNIT_NPC_FLAG_VENDOR_REAGENT        = 0x0000000800,     // 100%
    UNIT_NPC_FLAG_REPAIR                = 0x0000001000,     // 100%
    UNIT_NPC_FLAG_FLIGHTMASTER          = 0x0000002000,     // 100%
    UNIT_NPC_FLAG_SPIRITHEALER          = 0x0000004000,     // guessed
    UNIT_NPC_FLAG_SPIRITGUIDE           = 0x0000008000,     // guessed
    UNIT_NPC_FLAG_INNKEEPER             = 0x0000010000,     // 100%
    UNIT_NPC_FLAG_BANKER                = 0x0000020000,     // 100%
    UNIT_NPC_FLAG_PETITIONER            = 0x0000040000,     // 100% 0xC0000 = guild petitions, 0x40000 = arena team petitions
    UNIT_NPC_FLAG_TABARDDESIGNER        = 0x0000080000,     // 100%
    UNIT_NPC_FLAG_BATTLEMASTER          = 0x0000100000,     // 100%
    UNIT_NPC_FLAG_AUCTIONEER            = 0x0000200000,     // 100%
    UNIT_NPC_FLAG_STABLEMASTER          = 0x0000400000,     // 100%
    UNIT_NPC_FLAG_GUILD_BANKER          = 0x0000800000,     // cause client to send 997 opcode
    UNIT_NPC_FLAG_SPELLCLICK            = 0x0001000000,     // cause client to send 1015 opcode (spell click)
    UNIT_NPC_FLAG_PLAYER_VEHICLE        = 0x0002000000,     // players with mounts that have vehicle data should have it set
    UNIT_NPC_FLAG_MAILBOX               = 0x0004000000,     // mailbox
    UNIT_NPC_FLAG_ARTIFACT_POWER_RESPEC = 0x0008000000,     // artifact powers reset
    UNIT_NPC_FLAG_TRANSMOGRIFIER        = 0x0010000000,     // transmogrification
    UNIT_NPC_FLAG_VAULTKEEPER           = 0x0020000000,     // void storage
    UNIT_NPC_FLAG_BLACK_MARKET          = 0x0080000000,     // black market
    UNIT_NPC_FLAG_ITEM_UPGRADE_MASTER   = 0x0100000000,
    UNIT_NPC_FLAG_GARRISON_ARCHITECT    = 0x0200000000,
    UNIT_NPC_FLAG_STEERING              = 0x0400000000,
    UNIT_NPC_FLAG_SHIPMENT_CRAFTER      = 0x1000000000,
    UNIT_NPC_FLAG_GARRISON_MISSION_NPC  = 0x2000000000,
    UNIT_NPC_FLAG_TRADESKILL_NPC        = 0x4000000000,
    UNIT_NPC_FLAG_BLACK_MARKET_VIEW     = 0x8000000000
};

enum MovementFlags
{
    MOVEMENTFLAG_NONE                  = 0x00000000,
    MOVEMENTFLAG_FORWARD               = 0x00000001,
    MOVEMENTFLAG_BACKWARD              = 0x00000002,
    MOVEMENTFLAG_STRAFE_LEFT           = 0x00000004,
    MOVEMENTFLAG_STRAFE_RIGHT          = 0x00000008,
    MOVEMENTFLAG_LEFT                  = 0x00000010,
    MOVEMENTFLAG_RIGHT                 = 0x00000020,
    MOVEMENTFLAG_PITCH_UP              = 0x00000040,
    MOVEMENTFLAG_PITCH_DOWN            = 0x00000080,
    MOVEMENTFLAG_WALKING               = 0x00000100,               // Walking
    MOVEMENTFLAG_DISABLE_GRAVITY       = 0x00000200,               // Former MOVEMENTFLAG_LEVITATING. This is used when walking is not possible.
    MOVEMENTFLAG_ROOT                  = 0x00000400,               // Must not be set along with MOVEMENTFLAG_MASK_MOVING
    MOVEMENTFLAG_FALLING               = 0x00000800,               // damage dealt on that type of falling
    MOVEMENTFLAG_FALLING_FAR           = 0x00001000,
    MOVEMENTFLAG_PENDING_STOP          = 0x00002000,
    MOVEMENTFLAG_PENDING_STRAFE_STOP   = 0x00004000,
    MOVEMENTFLAG_PENDING_FORWARD       = 0x00008000,
    MOVEMENTFLAG_PENDING_BACKWARD      = 0x00010000,
    MOVEMENTFLAG_PENDING_STRAFE_LEFT   = 0x00020000,
    MOVEMENTFLAG_PENDING_STRAFE_RIGHT  = 0x00040000,
    MOVEMENTFLAG_PENDING_ROOT          = 0x00080000,
    MOVEMENTFLAG_SWIMMING              = 0x00100000,               // appears with fly flag also
    MOVEMENTFLAG_ASCENDING             = 0x00200000,               // press "space" when flying
    MOVEMENTFLAG_DESCENDING            = 0x00400000,
    MOVEMENTFLAG_CAN_FLY               = 0x00800000,               // Appears when unit can fly AND also walk
    MOVEMENTFLAG_FLYING                = 0x01000000,               // unit is actually flying. pretty sure this is only used for players. creatures use disable_gravity
    MOVEMENTFLAG_SPLINE_ELEVATION      = 0x02000000,               // used for flight paths
    MOVEMENTFLAG_WATERWALKING          = 0x04000000,               // prevent unit from falling through water
    MOVEMENTFLAG_FALLING_SLOW          = 0x08000000,               // active rogue safe fall spell (passive)
    MOVEMENTFLAG_HOVER                 = 0x10000000,               // hover, cannot jump
    MOVEMENTFLAG_DISABLE_COLLISION     = 0x20000000,

    MOVEMENTFLAG_MASK_MOVING =
        MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT |
        MOVEMENTFLAG_FALLING | MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING,

    MOVEMENTFLAG_MASK_TURNING =
        MOVEMENTFLAG_LEFT | MOVEMENTFLAG_RIGHT | MOVEMENTFLAG_PITCH_UP | MOVEMENTFLAG_PITCH_DOWN,

    MOVEMENTFLAG_MASK_MOVING_FLY =
        MOVEMENTFLAG_FLYING | MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_DESCENDING,

    // Movement flags allowed for creature in CreateObject - we need to keep all other enabled serverside
    // to properly calculate all movement
    MOVEMENTFLAG_MASK_CREATURE_ALLOWED =
        MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_ROOT | MOVEMENTFLAG_SWIMMING |
        MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_WATERWALKING | MOVEMENTFLAG_FALLING_SLOW | MOVEMENTFLAG_HOVER | MOVEMENTFLAG_DISABLE_COLLISION,

    /// @todo if needed: add more flags to this masks that are exclusive to players
    MOVEMENTFLAG_MASK_PLAYER_ONLY =
        MOVEMENTFLAG_FLYING,

    /// Movement flags that have change status opcodes associated for players
    MOVEMENTFLAG_MASK_HAS_PLAYER_STATUS_OPCODE = MOVEMENTFLAG_DISABLE_GRAVITY | MOVEMENTFLAG_ROOT |
        MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_WATERWALKING | MOVEMENTFLAG_FALLING_SLOW | MOVEMENTFLAG_HOVER | MOVEMENTFLAG_DISABLE_COLLISION
};

enum MovementFlags2
{
    MOVEMENTFLAG2_NONE                                      = 0x00000000,
    MOVEMENTFLAG2_NO_STRAFE                                 = 0x00000001,
    MOVEMENTFLAG2_NO_JUMPING                                = 0x00000002,
    MOVEMENTFLAG2_FULL_SPEED_TURNING                        = 0x00000004,
    MOVEMENTFLAG2_FULL_SPEED_PITCHING                       = 0x00000008,
    MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING                     = 0x00000010,
    MOVEMENTFLAG2_IS_VEHICLE_EXIT_VOLUNTARY                 = 0x00000020,
    MOVEMENTFLAG2_JUMP_SPLINE_IN_AIR                        = 0x00000040,
    MOVEMENTFLAG2_ANIM_TIER_IN_TRANS                        = 0x00000080,
    MOVEMENTFLAG2_WATERWALKING_FULL_PITCH                   = 0x00000100, // will always waterwalk, even if facing the camera directly down
    MOVEMENTFLAG2_VEHICLE_PASSENGER_IS_TRANSITION_ALLOWED   = 0x00000200,
    MOVEMENTFLAG2_CAN_SWIM_TO_FLY_TRANS                     = 0x00000400,
    MOVEMENTFLAG2_UNK11                                     = 0x00000800, // terrain normal calculation is disabled if this flag is not present, client automatically handles setting this flag
    MOVEMENTFLAG2_CAN_TURN_WHILE_FALLING                    = 0x00001000,
    MOVEMENTFLAG2_UNK13                                     = 0x00002000, // set automatically by the client for aura 373
    MOVEMENTFLAG2_IGNORE_MOVEMENT_FORCES                    = 0x00004000,
    MOVEMENTFLAG2_UNK15                                     = 0x00008000,
    MOVEMENTFLAG2_CAN_DOUBLE_JUMP                           = 0x00010000,
    MOVEMENTFLAG2_DOUBLE_JUMP                               = 0x00020000,
    // these flags cannot be sent (18 bits in packet)
    MOVEMENTFLAG2_UNK18                                     = 0x00040000,
    MOVEMENTFLAG2_UNK19                                     = 0x00080000,
    MOVEMENTFLAG2_INTERPOLATED_MOVEMENT                     = 0x00100000,
    MOVEMENTFLAG2_INTERPOLATED_TURNING                      = 0x00200000,
    MOVEMENTFLAG2_INTERPOLATED_PITCHING                     = 0x00400000
};

enum UnitTypeMask
{
    UNIT_MASK_NONE                  = 0x00000000,
    UNIT_MASK_SUMMON                = 0x00000001,
    UNIT_MASK_MINION                = 0x00000002,
    UNIT_MASK_GUARDIAN              = 0x00000004,
    UNIT_MASK_TOTEM                 = 0x00000008,
    UNIT_MASK_PET                   = 0x00000010,
    UNIT_MASK_VEHICLE               = 0x00000020,
    UNIT_MASK_PUPPET                = 0x00000040,
    UNIT_MASK_HUNTER_PET            = 0x00000080,
    UNIT_MASK_CONTROLABLE_GUARDIAN  = 0x00000100,
    UNIT_MASK_ACCESSORY             = 0x00000200
};

struct DiminishingReturn
{
    DiminishingReturn(DiminishingGroup group, uint32 t, uint32 count)
        : DRGroup(group), stack(0), hitTime(t), hitCount(count)
    { }

    DiminishingGroup        DRGroup:16;
    uint16                  stack:16;
    uint32                  hitTime;
    uint32                  hitCount;
};

enum MeleeHitOutcome
{
    MELEE_HIT_EVADE, MELEE_HIT_MISS, MELEE_HIT_DODGE, MELEE_HIT_BLOCK, MELEE_HIT_PARRY,
    MELEE_HIT_GLANCING, MELEE_HIT_CRIT, MELEE_HIT_CRUSHING, MELEE_HIT_NORMAL
};

class DispelInfo
{
public:
    explicit DispelInfo(Unit* dispeller, uint32 dispellerSpellId, uint8 chargesRemoved) :
    _dispellerUnit(dispeller), _dispellerSpell(dispellerSpellId), _chargesRemoved(chargesRemoved) { }

    Unit* GetDispeller() const { return _dispellerUnit; }
    uint32 GetDispellerSpellId() const { return _dispellerSpell; }
    uint8 GetRemovedCharges() const { return _chargesRemoved; }
    void SetRemovedCharges(uint8 amount)
    {
        _chargesRemoved = amount;
    }
private:
    Unit* _dispellerUnit;
    uint32 _dispellerSpell;
    uint8 _chargesRemoved;
};

struct CleanDamage
{
    CleanDamage(uint32 mitigated, uint32 absorbed, WeaponAttackType _attackType, MeleeHitOutcome _hitOutCome) :
    absorbed_damage(absorbed), mitigated_damage(mitigated), attackType(_attackType), hitOutCome(_hitOutCome) { }

    uint32 absorbed_damage;
    uint32 mitigated_damage;

    WeaponAttackType attackType;
    MeleeHitOutcome hitOutCome;
};

struct CalcDamageInfo;
struct SpellNonMeleeDamage;

class TC_GAME_API DamageInfo
{
private:
    Unit* const m_attacker;
    Unit* const m_victim;
    uint32 m_damage;
    SpellInfo const* const m_spellInfo;
    SpellSchoolMask const m_schoolMask;
    DamageEffectType const m_damageType;
    WeaponAttackType m_attackType;
    uint32 m_absorb;
    uint32 m_resist;
    uint32 m_block;
    uint32 m_hitMask;
public:
    DamageInfo(Unit* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, DamageEffectType damageType, WeaponAttackType attackType);
    explicit DamageInfo(CalcDamageInfo const& dmgInfo);
    DamageInfo(SpellNonMeleeDamage const& spellNonMeleeDamage, DamageEffectType damageType, WeaponAttackType attackType);

    void ModifyDamage(int32 amount);
    void AbsorbDamage(uint32 amount);
    void ResistDamage(uint32 amount);
    void BlockDamage(uint32 amount);

    Unit* GetAttacker() const { return m_attacker; }
    Unit* GetVictim() const { return m_victim; }
    SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
    SpellSchoolMask GetSchoolMask() const { return m_schoolMask; }
    DamageEffectType GetDamageType() const { return m_damageType; }
    WeaponAttackType GetAttackType() const { return m_attackType; }
    uint32 GetDamage() const { return m_damage; }
    uint32 GetAbsorb() const { return m_absorb; }
    uint32 GetResist() const { return m_resist; }
    uint32 GetBlock() const { return m_block; }

    uint32 GetHitMask() const;
};

class TC_GAME_API HealInfo
{
private:
    Unit* const _healer;
    Unit* const _target;
    uint32 _heal;
    uint32 _absorb;
    SpellInfo const* const _spellInfo;
    SpellSchoolMask const _schoolMask;
    uint32 _hitMask;

public:
    explicit HealInfo(Unit* healer, Unit* target, uint32 heal, SpellInfo const* spellInfo, SpellSchoolMask schoolMask);

    void AbsorbHeal(uint32 amount);

    Unit* GetHealer() const { return _healer; }
    Unit* GetTarget() const { return _target; }
    uint32 GetHeal() const { return _heal; }
    uint32 GetAbsorb() const { return _absorb; }
    SpellInfo const* GetSpellInfo() const { return _spellInfo; };
    SpellSchoolMask GetSchoolMask() const { return _schoolMask; };

    uint32 GetHitMask() const;
};

class TC_GAME_API ProcEventInfo
{
public:
    ProcEventInfo(Unit* actor, Unit* actionTarget, Unit* procTarget, uint32 typeMask,
                  uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask,
                  Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo);

    Unit* GetActor() { return _actor; }
    Unit* GetActionTarget() const { return _actionTarget; }
    Unit* GetProcTarget() const { return _procTarget; }

    uint32 GetTypeMask() const { return _typeMask; }
    uint32 GetSpellTypeMask() const { return _spellTypeMask; }
    uint32 GetSpellPhaseMask() const { return _spellPhaseMask; }
    uint32 GetHitMask() const { return _hitMask; }

    SpellInfo const* GetSpellInfo() const;
    SpellSchoolMask GetSchoolMask() const;

    DamageInfo* GetDamageInfo() const { return _damageInfo; }
    HealInfo* GetHealInfo() const { return _healInfo; }

private:
    Unit* const _actor;
    Unit* const _actionTarget;
    Unit* const _procTarget;
    uint32 _typeMask;
    uint32 _spellTypeMask;
    uint32 _spellPhaseMask;
    uint32 _hitMask;
    Spell* _spell;
    DamageInfo* _damageInfo;
    HealInfo* _healInfo;
};

// Struct for use in Unit::CalculateMeleeDamage
// Need create structure like in SMSG_ATTACKERSTATEUPDATE opcode
struct CalcDamageInfo
{
    Unit  *attacker;             // Attacker
    Unit  *target;               // Target for damage
    uint32 damageSchoolMask;
    uint32 damage;
    uint32 absorb;
    uint32 resist;
    uint32 blocked_amount;
    uint32 HitInfo;
    uint32 TargetState;
// Helper
    WeaponAttackType attackType; //
    uint32 procAttacker;
    uint32 procVictim;
    uint32 procEx;
    uint32 cleanDamage;          // Used only for rage calculation
    MeleeHitOutcome hitOutCome;  /// @todo remove this field (need use TargetState)
};

// Spell damage info structure based on structure sending in SMSG_SPELLNONMELEEDAMAGELOG opcode
struct TC_GAME_API SpellNonMeleeDamage
{
    SpellNonMeleeDamage(Unit* _attacker, Unit* _target, uint32 _SpellID, uint32 _schoolMask, ObjectGuid _castId = ObjectGuid::Empty);

    Unit   *target;
    Unit   *attacker;
    ObjectGuid castId;
    uint32 SpellID;
    uint32 damage;
    uint32 schoolMask;
    uint32 absorb;
    uint32 resist;
    bool   periodicLog;
    uint32 blocked;
    uint32 HitInfo;
    // Used for help
    uint32 cleanDamage;
    uint32 preHitHealth;
};

struct SpellPeriodicAuraLogInfo
{
    SpellPeriodicAuraLogInfo(AuraEffect const* _auraEff, uint32 _damage, uint32 _overDamage, uint32 _absorb, uint32 _resist, float _multiplier, bool _critical)
        : auraEff(_auraEff), damage(_damage), overDamage(_overDamage), absorb(_absorb), resist(_resist), multiplier(_multiplier), critical(_critical){ }

    AuraEffect const* auraEff;
    uint32 damage;
    uint32 overDamage;                                      // overkill/overheal
    uint32 absorb;
    uint32 resist;
    float  multiplier;
    bool   critical;
};

uint32 createProcExtendMask(SpellNonMeleeDamage* damageInfo, SpellMissInfo missCondition);

struct RedirectThreatInfo
{
    RedirectThreatInfo() : _threatPct(0) { }
    ObjectGuid _targetGUID;
    uint32 _threatPct;

    ObjectGuid GetTargetGUID() const { return _targetGUID; }
    uint32 GetThreatPct() const { return _threatPct; }

    void Set(ObjectGuid guid, uint32 pct)
    {
        _targetGUID = guid;
        _threatPct = pct;
    }

    void ModifyThreatPct(int32 amount)
    {
        amount += _threatPct;
        _threatPct = uint32(std::max(0, amount));
    }
};

#define MAX_DECLINED_NAME_CASES 5

struct DeclinedName
{
    std::string name[MAX_DECLINED_NAME_CASES];
};

enum CurrentSpellTypes
{
    CURRENT_MELEE_SPELL             = 0,
    CURRENT_GENERIC_SPELL           = 1,
    CURRENT_CHANNELED_SPELL         = 2,
    CURRENT_AUTOREPEAT_SPELL        = 3
};

#define CURRENT_FIRST_NON_MELEE_SPELL 1
#define CURRENT_MAX_SPELL             4

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
    REACT_AGGRESSIVE = 2,
    REACT_ASSIST     = 3
};

enum CommandStates : uint8
{
    COMMAND_STAY    = 0,
    COMMAND_FOLLOW  = 1,
    COMMAND_ATTACK  = 2,
    COMMAND_ABANDON = 3,
    COMMAND_MOVE_TO = 4
};

#define UNIT_ACTION_BUTTON_ACTION(X) (uint32(X) & 0x00FFFFFF)
#define UNIT_ACTION_BUTTON_TYPE(X)   ((uint32(X) & 0xFF000000) >> 24)
#define MAKE_UNIT_ACTION_BUTTON(A, T) (uint32(A) | (uint32(T) << 24))

struct UnitActionBarEntry
{
    UnitActionBarEntry() : packedData(uint32(ACT_DISABLED) << 24) { }

    uint32 packedData;

    // helper
    ActiveStates GetType() const { return ActiveStates(UNIT_ACTION_BUTTON_TYPE(packedData)); }
    uint32 GetAction() const { return UNIT_ACTION_BUTTON_ACTION(packedData); }
    bool IsActionBarForSpell() const
    {
        ActiveStates Type = GetType();
        return Type == ACT_DISABLED || Type == ACT_ENABLED || Type == ACT_PASSIVE;
    }

    void SetActionAndType(uint32 action, ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(action, type);
    }

    void SetType(ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(UNIT_ACTION_BUTTON_ACTION(packedData), type);
    }

    void SetAction(uint32 action)
    {
        packedData = (packedData & 0xFF000000) | UNIT_ACTION_BUTTON_ACTION(action);
    }
};

typedef std::list<Player*> SharedVisionList;

enum CharmType
{
    CHARM_TYPE_CHARM,
    CHARM_TYPE_POSSESS,
    CHARM_TYPE_VEHICLE,
    CHARM_TYPE_CONVERT
};

typedef UnitActionBarEntry CharmSpellInfo;

enum ActionBarIndex
{
    ACTION_BAR_INDEX_START = 0,
    ACTION_BAR_INDEX_PET_SPELL_START = 3,
    ACTION_BAR_INDEX_PET_SPELL_END = 7,
    ACTION_BAR_INDEX_END = 10
};

#define MAX_UNIT_ACTION_BAR_INDEX (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START)

struct TC_GAME_API CharmInfo
{
    public:
        explicit CharmInfo(Unit* unit);
        ~CharmInfo();
        void RestoreState();
        uint32 GetPetNumber() const { return _petnumber; }
        void SetPetNumber(uint32 petnumber, bool statwindow);

        void SetCommandState(CommandStates st) { _CommandState = st; }
        CommandStates GetCommandState() const { return _CommandState; }
        bool HasCommandState(CommandStates state) const { return (_CommandState == state); }

        void InitPossessCreateSpells();
        void InitCharmCreateSpells();
        void InitPetActionBar();
        void InitEmptyActionBar(bool withAttack = true);

                                                            //return true if successful
        bool AddSpellToActionBar(SpellInfo const* spellInfo, ActiveStates newstate = ACT_DECIDE, uint8 preferredSlot = 0);
        bool RemoveSpellFromActionBar(uint32 spell_id);
        void LoadPetActionBar(const std::string& data);
        void BuildActionBar(WorldPacket* data);
        void SetSpellAutocast(SpellInfo const* spellInfo, bool state);
        void SetActionBar(uint8 index, uint32 spellOrAction, ActiveStates type)
        {
            PetActionBar[index].SetActionAndType(spellOrAction, type);
        }
        UnitActionBarEntry const* GetActionBarEntry(uint8 index) const { return &(PetActionBar[index]); }

        void ToggleCreatureAutocast(SpellInfo const* spellInfo, bool apply);

        CharmSpellInfo* GetCharmSpell(uint8 index) { return &(_charmspells[index]); }

        void SetIsCommandAttack(bool val);
        bool IsCommandAttack();
        void SetIsCommandFollow(bool val);
        bool IsCommandFollow();
        void SetIsAtStay(bool val);
        bool IsAtStay();
        void SetIsFollowing(bool val);
        bool IsFollowing();
        void SetIsReturning(bool val);
        bool IsReturning();
        void SaveStayPosition();
        void GetStayPosition(float &x, float &y, float &z);

    private:

        Unit* _unit;
        UnitActionBarEntry PetActionBar[MAX_UNIT_ACTION_BAR_INDEX];
        CharmSpellInfo _charmspells[4];
        CommandStates _CommandState;
        uint32 _petnumber;

        //for restoration after charmed
        ReactStates     _oldReactState;

        bool _isCommandAttack;
        bool _isCommandFollow;
        bool _isAtStay;
        bool _isFollowing;
        bool _isReturning;
        float _stayX;
        float _stayY;
        float _stayZ;
};

// for clearing special attacks
#define REACTIVE_TIMER_START 4000

enum ReactiveType
{
    REACTIVE_DEFENSE      = 0,
    REACTIVE_HUNTER_PARRY = 1,
    REACTIVE_OVERPOWER    = 2
};

#define MAX_REACTIVE 3
#define SUMMON_SLOT_PET     0
#define SUMMON_SLOT_TOTEM   1
#define MAX_TOTEM_SLOT      5
#define SUMMON_SLOT_MINIPET 5
#define SUMMON_SLOT_QUEST   6
#define MAX_SUMMON_SLOT     7

#define MAX_GAMEOBJECT_SLOT 4

enum PlayerTotemType
{
    SUMMON_TYPE_TOTEM_FIRE  = 63,
    SUMMON_TYPE_TOTEM_EARTH = 81,
    SUMMON_TYPE_TOTEM_WATER = 82,
    SUMMON_TYPE_TOTEM_AIR   = 83
};

#define MAX_EQUIPMENT_ITEMS 3

// delay time next attack to prevent client attack animation problems
#define ATTACK_DISPLAY_DELAY 200
#define MAX_PLAYER_STEALTH_DETECT_RANGE 30.0f               // max distance for detection targets by player

struct SpellProcEventEntry;                                 // used only privately

class TC_GAME_API Unit : public WorldObject
{
    public:
        typedef std::set<Unit*> AttackerSet;
        typedef std::set<Unit*> ControlList;

        typedef std::multimap<uint32, Aura*> AuraMap;
        typedef std::pair<AuraMap::const_iterator, AuraMap::const_iterator> AuraMapBounds;
        typedef std::pair<AuraMap::iterator, AuraMap::iterator> AuraMapBoundsNonConst;

        typedef std::multimap<uint32,  AuraApplication*> AuraApplicationMap;
        typedef std::pair<AuraApplicationMap::const_iterator, AuraApplicationMap::const_iterator> AuraApplicationMapBounds;
        typedef std::pair<AuraApplicationMap::iterator, AuraApplicationMap::iterator> AuraApplicationMapBoundsNonConst;

        typedef std::multimap<AuraStateType,  AuraApplication*> AuraStateAurasMap;
        typedef std::pair<AuraStateAurasMap::const_iterator, AuraStateAurasMap::const_iterator> AuraStateAurasMapBounds;

        typedef std::list<AuraEffect*> AuraEffectList;
        typedef std::list<Aura*> AuraList;
        typedef std::list<AuraApplication *> AuraApplicationList;
        typedef std::list<DiminishingReturn> Diminishing;

        struct VisibleAuraSlotCompare { bool operator()(AuraApplication* left, AuraApplication* right) const; };
        typedef std::set<AuraApplication*, VisibleAuraSlotCompare> VisibleAuraContainer;

        virtual ~Unit();

        UnitAI* GetAI() { return i_AI; }
        void SetAI(UnitAI* newAI) { i_AI = newAI; }

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void CleanupBeforeRemoveFromMap(bool finalCleanup);
        void CleanupsBeforeDelete(bool finalCleanup = true) override;                        // used in ~Creature/~Player (or before mass creature delete to remove cross-references to already deleted units)

        void SendCombatLogMessage(WorldPackets::CombatLog::CombatLogServerPacket* combatLog) const;

        DiminishingLevels GetDiminishing(DiminishingGroup  group);
        void IncrDiminishing(DiminishingGroup group);
        float ApplyDiminishingToDuration(DiminishingGroup  group, int32 &duration, Unit* caster, DiminishingLevels Level, int32 limitduration);
        void ApplyDiminishingAura(DiminishingGroup  group, bool apply);
        void ClearDiminishings() { m_Diminishing.clear(); }

        // target dependent range checks
        float GetSpellMaxRangeForTarget(Unit const* target, SpellInfo const* spellInfo) const;
        float GetSpellMinRangeForTarget(Unit const* target, SpellInfo const* spellInfo) const;

        virtual void Update(uint32 time) override;

        void setAttackTimer(WeaponAttackType type, uint32 time) { m_attackTimer[type] = time; }
        void resetAttackTimer(WeaponAttackType type = BASE_ATTACK);
        uint32 getAttackTimer(WeaponAttackType type) const { return m_attackTimer[type]; }
        bool isAttackReady(WeaponAttackType type = BASE_ATTACK) const { return m_attackTimer[type] == 0; }
        bool haveOffhandWeapon() const;
        bool CanDualWield() const { return m_canDualWield; }
        virtual void SetCanDualWield(bool value) { m_canDualWield = value; }
        float GetCombatReach() const { return m_floatValues[UNIT_FIELD_COMBATREACH]; }
        float GetBoundaryRadius() const { return m_floatValues[UNIT_FIELD_BOUNDINGRADIUS]; }
        bool IsWithinCombatRange(const Unit* obj, float dist2compare) const;
        bool IsWithinMeleeRange(Unit const* obj) const;
        float GetMeleeRange(Unit const* target) const;
        bool IsWithinBoundaryRadius(const Unit* obj) const;
        void GetRandomContactPoint(const Unit* target, float &x, float &y, float &z, float distance2dMin, float distance2dMax) const;
        uint32 m_extraAttacks;
        bool m_canDualWield;

        void _addAttacker(Unit* pAttacker);                  // must be called only from Unit::Attack(Unit*)
        void _removeAttacker(Unit* pAttacker);               // must be called only from Unit::AttackStop()
        Unit* getAttackerForHelper() const;                 // If someone wants to help, who to give them
        bool Attack(Unit* victim, bool meleeAttack);
        void CastStop(uint32 except_spellid = 0);
        bool AttackStop();
        void RemoveAllAttackers();
        AttackerSet const& getAttackers() const { return m_attackers; }
        bool isAttackingPlayer() const;
        Unit* GetVictim() const { return m_attacking; }
        // Use this only when 100% sure there is a victim
        Unit* EnsureVictim() const
        {
            ASSERT(m_attacking);
            return m_attacking;
        }

        void CombatStop(bool includingCast = false);
        void CombatStopWithPets(bool includingCast = false);
        void StopAttackFaction(uint32 faction_id);
        Unit* SelectNearbyTarget(Unit* exclude = NULL, float dist = NOMINAL_MELEE_RANGE) const;
        void SendMeleeAttackStop(Unit* victim = NULL);
        void SendMeleeAttackStart(Unit* victim);

        void AddUnitState(uint32 f) { m_state |= f; }
        bool HasUnitState(const uint32 f) const { return (m_state & f) != 0; }
        void ClearUnitState(uint32 f) { m_state &= ~f; }
        bool CanFreeMove() const;

        uint32 HasUnitTypeMask(uint32 mask) const { return mask & m_unitTypeMask; }
        void AddUnitTypeMask(uint32 mask) { m_unitTypeMask |= mask; }
        bool IsSummon() const   { return (m_unitTypeMask & UNIT_MASK_SUMMON) != 0; }
        bool IsGuardian() const { return (m_unitTypeMask & UNIT_MASK_GUARDIAN) != 0; }
        bool IsPet() const      { return (m_unitTypeMask & UNIT_MASK_PET) != 0; }
        bool IsHunterPet() const{ return (m_unitTypeMask & UNIT_MASK_HUNTER_PET) != 0; }
        bool IsTotem() const    { return (m_unitTypeMask & UNIT_MASK_TOTEM) != 0; }
        bool IsVehicle() const  { return (m_unitTypeMask & UNIT_MASK_VEHICLE) != 0; }

        uint8 getLevel() const { return uint8(GetUInt32Value(UNIT_FIELD_LEVEL)); }
        uint8 getLevelForTarget(WorldObject const* /*target*/) const override { return getLevel(); }
        void SetLevel(uint8 lvl);
        uint8 getRace() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE); }
        uint32 getRaceMask() const { return 1 << (getRace()-1); }
        uint8 getClass() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS); }
        uint32 getClassMask() const { return 1 << (getClass()-1); }
        uint8 getGender() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER); }

        float GetStat(Stats stat) const { return float(GetUInt32Value(UNIT_FIELD_STAT+stat)); }
        void SetStat(Stats stat, int32 val) { SetStatInt32Value(UNIT_FIELD_STAT+stat, val); }
        uint32 GetArmor() const { return GetResistance(SPELL_SCHOOL_NORMAL); }
        void SetArmor(int32 val) { SetResistance(SPELL_SCHOOL_NORMAL, val); }

        uint32 GetResistance(SpellSchools school) const { return GetUInt32Value(UNIT_FIELD_RESISTANCES+school); }
        uint32 GetResistance(SpellSchoolMask mask) const;
        void SetResistance(SpellSchools school, int32 val) { SetStatInt32Value(UNIT_FIELD_RESISTANCES+school, val); }

        uint64 GetHealth()    const { return GetUInt64Value(UNIT_FIELD_HEALTH); }
        uint64 GetMaxHealth() const { return GetUInt64Value(UNIT_FIELD_MAXHEALTH); }

        bool IsFullHealth() const { return GetHealth() == GetMaxHealth(); }
        bool HealthBelowPct(int32 pct) const { return GetHealth() < CountPctFromMaxHealth(pct); }
        bool HealthBelowPctDamaged(int32 pct, uint32 damage) const { return int64(GetHealth()) - int64(damage) < int64(CountPctFromMaxHealth(pct)); }
        bool HealthAbovePct(int32 pct) const { return GetHealth() > CountPctFromMaxHealth(pct); }
        bool HealthAbovePctHealed(int32 pct, uint32 heal) const { return uint64(GetHealth()) + uint64(heal) > CountPctFromMaxHealth(pct); }
        float GetHealthPct() const { return GetMaxHealth() ? 100.f * GetHealth() / GetMaxHealth() : 0.0f; }
        uint64 CountPctFromMaxHealth(int32 pct) const { return CalculatePct(GetMaxHealth(), pct); }
        uint64 CountPctFromCurHealth(int32 pct) const { return CalculatePct(GetHealth(), pct); }

        void SetHealth(uint64 val);
        void SetMaxHealth(uint64 val);
        inline void SetFullHealth() { SetHealth(GetMaxHealth()); }
        int64 ModifyHealth(int64 val);
        int64 GetHealthGain(int64 dVal);

        Powers getPowerType() const { return Powers(GetUInt32Value(UNIT_FIELD_DISPLAY_POWER)); }
        void setPowerType(Powers power);
        void UpdateDisplayPower();
        int32 GetPower(Powers power) const;
        int32 GetMinPower(Powers power) const { return power == POWER_LUNAR_POWER ? -100 : 0; }
        int32 GetMaxPower(Powers power) const;
        float GetPowerPct(Powers power) const { return GetMaxPower(power) ? 100.f * GetPower(power) / GetMaxPower(power) : 0.0f; }
        int32 CountPctFromMaxPower(Powers power, int32 pct) const { return CalculatePct(GetMaxPower(power), pct); }
        void SetPower(Powers power, int32 val);
        void SetMaxPower(Powers power, int32 val);
        // returns the change in power
        int32 ModifyPower(Powers power, int32 val);
        int32 ModifyPowerPct(Powers power, float pct, bool apply = true);

        uint32 GetBaseAttackTime(WeaponAttackType att) const;
        void SetBaseAttackTime(WeaponAttackType att, uint32 val);
        void UpdateAttackTimeField(WeaponAttackType att);
        void ApplyAttackTimePercentMod(WeaponAttackType att, float val, bool apply);
        void ApplyCastTimePercentMod(float val, bool apply);

        SheathState GetSheath() const { return SheathState(GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE)); }
        void SetSheath(SheathState sheathed) { SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE, sheathed); }

        // faction template id
        uint32 getFaction() const { return GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE); }
        void setFaction(uint32 faction) { SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, faction); }
        FactionTemplateEntry const* GetFactionTemplateEntry() const;

        ReputationRank GetReactionTo(Unit const* target) const;
        ReputationRank static GetFactionReactionTo(FactionTemplateEntry const* factionTemplateEntry, Unit const* target);

        bool IsHostileTo(Unit const* unit) const;
        bool IsHostileToPlayers() const;
        bool IsFriendlyTo(Unit const* unit) const;
        bool IsNeutralToAll() const;
        bool IsInPartyWith(Unit const* unit) const;
        bool IsInRaidWith(Unit const* unit) const;
        void GetPartyMembers(std::list<Unit*> &units);
        bool IsContestedGuard() const;
        bool IsPvP() const { return HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_PVP); }
        bool IsFFAPvP() const { return HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP); }
        virtual void SetPvP(bool state);

        uint32 GetCreatureType() const;
        uint32 GetCreatureTypeMask() const;

        UnitStandStateType GetStandState() const { return UnitStandStateType(GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE)); }
        bool IsSitState() const;
        bool IsStandState() const;
        void SetStandState(UnitStandStateType state, uint32 animKitID = 0);

        void  SetStandFlags(uint8 flags) { SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, flags); }
        void  RemoveStandFlags(uint8 flags) { RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, flags); }

        bool IsMounted() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT); }
        uint32 GetMountID() const { return GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID); }
        void Mount(uint32 mount, uint32 vehicleId = 0, uint32 creatureEntry = 0);
        void Dismount();
        MountCapabilityEntry const* GetMountCapability(uint32 mountType) const;

        void SendDurabilityLoss(Player* receiver, uint32 percent);
        void PlayOneShotAnimKitId(uint16 animKitId);
        void SetAIAnimKitId(uint16 animKitId);
        uint16 GetAIAnimKitId() const override { return _aiAnimKitId; }
        void SetMovementAnimKitId(uint16 animKitId);
        uint16 GetMovementAnimKitId() const override { return _movementAnimKitId; }
        void SetMeleeAnimKitId(uint16 animKitId);
        uint16 GetMeleeAnimKitId() const override { return _meleeAnimKitId; }

        uint16 GetMaxSkillValueForLevel(Unit const* target = NULL) const { return (target ? getLevelForTarget(target) : getLevel()) * 5; }
        void DealDamageMods(Unit* victim, uint32 &damage, uint32* absorb);
        uint32 DealDamage(Unit* victim, uint32 damage, CleanDamage const* cleanDamage = NULL, DamageEffectType damagetype = DIRECT_DAMAGE, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellInfo const* spellProto = NULL, bool durabilityLoss = true);
        void Kill(Unit* victim, bool durabilityLoss = true);
        void KillSelf(bool durabilityLoss = true) { Kill(this, durabilityLoss); }
        int32 DealHeal(Unit* victim, uint32 addhealth);

        void ProcDamageAndSpell(Unit* victim, uint32 procAttacker, uint32 procVictim, uint32 procEx, uint32 amount, WeaponAttackType attType = BASE_ATTACK, SpellInfo const* procSpell = NULL, SpellInfo const* procAura = NULL);
        void ProcDamageAndSpellFor(bool isVictim, Unit* target, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, SpellInfo const* procSpell, uint32 damage, SpellInfo const* procAura = NULL);

        void GetProcAurasTriggeredOnEvent(AuraApplicationList& aurasTriggeringProc, AuraApplicationList* procAuras, ProcEventInfo eventInfo);
        void TriggerAurasProcOnEvent(CalcDamageInfo& damageInfo);
        void TriggerAurasProcOnEvent(AuraApplicationList* myProcAuras, AuraApplicationList* targetProcAuras,
                                     Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget,
                                     uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell,
                                     DamageInfo* damageInfo, HealInfo* healInfo);
        void TriggerAurasProcOnEvent(ProcEventInfo& eventInfo, AuraApplicationList& procAuras);

        void HandleEmoteCommand(uint32 anim_id);
        void AttackerStateUpdate (Unit* victim, WeaponAttackType attType = BASE_ATTACK, bool extra = false);
        void FakeAttackerStateUpdate(Unit* victim, WeaponAttackType attType = BASE_ATTACK);

        void CalculateMeleeDamage(Unit* victim, uint32 damage, CalcDamageInfo* damageInfo, WeaponAttackType attackType = BASE_ATTACK);
        void DealMeleeDamage(CalcDamageInfo* damageInfo, bool durabilityLoss);
        void HandleProcExtraAttackFor(Unit* victim);

        void CalculateSpellDamageTaken(SpellNonMeleeDamage* damageInfo, int32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType = BASE_ATTACK, bool crit = false);
        void DealSpellDamage(SpellNonMeleeDamage const* damageInfo, bool durabilityLoss);

        // player or player's pet resilience (-1%)
        uint32 GetDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_RESILIENCE_PLAYER_DAMAGE, 1.0f, 100.0f, damage); }

        void ApplyResilience(Unit const* victim, int32* damage) const;

        float MeleeSpellMissChance(Unit const* victim, WeaponAttackType attType, uint32 spellId) const;
        SpellMissInfo MeleeSpellHitResult(Unit* victim, SpellInfo const* spellInfo) const;
        SpellMissInfo MagicSpellHitResult(Unit* victim, SpellInfo const* spellInfo) const;
        SpellMissInfo SpellHitResult(Unit* victim, SpellInfo const* spellInfo, bool canReflect = false);

        float GetUnitDodgeChance(WeaponAttackType attType, Unit const* victim) const;
        float GetUnitParryChance(WeaponAttackType attType, Unit const* victim) const;
        float GetUnitBlockChance(WeaponAttackType attType, Unit const* victim) const;
        float GetUnitMissChance(WeaponAttackType attType) const;
        float GetUnitCriticalChance(WeaponAttackType attackType, Unit const* victim) const;
        int32 GetMechanicResistChance(SpellInfo const* spellInfo) const;
        bool CanUseAttackType(uint8 attacktype) const;

        virtual uint32 GetBlockPercent() const { return 30; }

        float GetWeaponProcChance() const;
        float GetPPMProcChance(uint32 WeaponSpeed, float PPM,  const SpellInfo* spellProto) const;

        MeleeHitOutcome RollMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const;

        bool IsVendor()       const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR); }
        bool IsTrainer()      const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TRAINER); }
        bool IsQuestGiver()   const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER); }
        bool IsGossip()       const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP); }
        bool IsTaxi()         const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_FLIGHTMASTER); }
        bool IsGuildMaster()  const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PETITIONER); }
        bool IsBattleMaster() const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BATTLEMASTER); }
        bool IsBanker()       const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BANKER); }
        bool IsInnkeeper()    const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_INNKEEPER); }
        bool IsSpiritHealer() const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER); }
        bool IsSpiritGuide()  const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITGUIDE); }
        bool IsTabardDesigner()const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TABARDDESIGNER); }
        bool IsAuctioner()    const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_AUCTIONEER); }
        bool IsArmorer()      const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_REPAIR); }
        bool IsServiceProvider() const;
        bool IsSpiritService() const { return HasFlag64(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER | UNIT_NPC_FLAG_SPIRITGUIDE); }
        bool IsCritter() const { return GetCreatureType() == CREATURE_TYPE_CRITTER; }

        bool IsInFlight()  const { return HasUnitState(UNIT_STATE_IN_FLIGHT); }

        bool IsInCombat()  const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); }
        bool IsInCombatWith(Unit const* who) const;
        void CombatStart(Unit* target, bool initialAggro = true);
        void SetInCombatState(bool PvP, Unit* enemy = NULL);
        void SetInCombatWith(Unit* enemy);
        void ClearInCombat();
        uint32 GetCombatTimer() const { return m_CombatTimer; }

        bool HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, uint32 familyFlags) const;
        bool virtual HasSpell(uint32 /*spellID*/) const { return false; }
        bool HasBreakableByDamageAuraType(AuraType type, uint32 excludeAura = 0) const;
        bool HasBreakableByDamageCrowdControlAura(Unit* excludeCasterChannel = NULL) const;

        bool HasStealthAura()      const { return HasAuraType(SPELL_AURA_MOD_STEALTH); }
        bool HasInvisibilityAura() const { return HasAuraType(SPELL_AURA_MOD_INVISIBILITY); }
        bool isFeared()  const { return HasAuraType(SPELL_AURA_MOD_FEAR); }
        bool IsPolymorphed() const;

        bool isFrozen() const;

        bool isTargetableForAttack(bool checkFakeDeath = true) const;

        bool IsValidAttackTarget(Unit const* target) const;
        bool _IsValidAttackTarget(Unit const* target, SpellInfo const* bySpell, WorldObject const* obj = NULL) const;

        bool IsValidAssistTarget(Unit const* target) const;
        bool _IsValidAssistTarget(Unit const* target, SpellInfo const* bySpell) const;

        virtual bool IsInWater() const;
        virtual bool IsUnderWater() const;
        virtual void UpdateUnderwaterState(Map* m, float x, float y, float z);
        bool isInAccessiblePlaceFor(Creature const* c) const;

        void SendHealSpellLog(Unit* victim, uint32 spellID, uint32 health, uint32 overHeal, uint32 absorbed, bool crit = false);
        int32 HealBySpell(Unit* victim, SpellInfo const* spellInfo, uint32 addHealth, bool critical = false);
        void SendEnergizeSpellLog(Unit* victim, uint32 spellID, int32 damage, Powers powertype);
        void EnergizeBySpell(Unit* victim, uint32 SpellID, int32 Damage, Powers powertype);

        void CastSpell(SpellCastTargets const& targets, SpellInfo const* spellInfo, CustomSpellValues const* value, TriggerCastFlags triggerFlags = TRIGGERED_NONE, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastSpell(Unit* victim, uint32 spellId, bool triggered, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastSpell(Unit* victim, uint32 spellId, TriggerCastFlags triggerFlags = TRIGGERED_NONE, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastSpell(Unit* victim, SpellInfo const* spellInfo, bool triggered, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastSpell(Unit* victim, SpellInfo const* spellInfo, TriggerCastFlags triggerFlags = TRIGGERED_NONE, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastSpell(float x, float y, float z, uint32 spellId, bool triggered, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastSpell(GameObject* go, uint32 spellId, bool triggered, Item* castItem = NULL, AuraEffect* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastCustomSpell(Unit* victim, uint32 spellId, int32 const* bp0, int32 const* bp1, int32 const* bp2, bool triggered, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastCustomSpell(uint32 spellId, SpellValueMod mod, int32 value, Unit* victim, bool triggered, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastCustomSpell(uint32 spellId, SpellValueMod mod, int32 value, Unit* victim = NULL, TriggerCastFlags triggerFlags = TRIGGERED_NONE, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        void CastCustomSpell(uint32 spellId, CustomSpellValues const &value, Unit* victim = NULL, TriggerCastFlags triggerFlags = TRIGGERED_NONE, Item* castItem = NULL, AuraEffect const* triggeredByAura = NULL, ObjectGuid originalCaster = ObjectGuid::Empty);
        Aura* AddAura(uint32 spellId, Unit* target);
        Aura* AddAura(SpellInfo const* spellInfo, uint32 effMask, Unit* target);
        void SetAuraStack(uint32 spellId, Unit* target, uint32 stack);
        void SendPlaySpellVisualKit(uint32 id, uint32 type);

        void DeMorph();

        void SendAttackStateUpdate(CalcDamageInfo* damageInfo);
        void SendAttackStateUpdate(uint32 HitInfo, Unit* target, uint8 SwingType, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount);
        void SendSpellNonMeleeDamageLog(SpellNonMeleeDamage const* log);
        void SendPeriodicAuraLog(SpellPeriodicAuraLogInfo* pInfo);
        void SendSpellMiss(Unit* target, uint32 spellID, SpellMissInfo missInfo);
        void SendSpellDamageResist(Unit* target, uint32 spellId);
        void SendSpellDamageImmune(Unit* target, uint32 spellId, bool isPeriodic);

        void NearTeleportTo(Position const& pos, bool casting = false);
        void NearTeleportTo(float x, float y, float z, float orientation, bool casting = false) { NearTeleportTo(Position(x, y, z, orientation), casting); }
        void SendTeleportPacket(Position const& pos);
        virtual bool UpdatePosition(float x, float y, float z, float ang, bool teleport = false);
        // returns true if unit's position really changed
        virtual bool UpdatePosition(const Position &pos, bool teleport = false);
        void UpdateOrientation(float orientation);
        void UpdateHeight(float newZ);

        void SendMoveKnockBack(Player* player, float speedXY, float speedZ, float vcos, float vsin);
        void KnockbackFrom(float x, float y, float speedXY, float speedZ, Movement::SpellEffectExtraData const* spellEffectExtraData = nullptr);
        void JumpTo(float speedXY, float speedZ, bool forward = true);
        void JumpTo(WorldObject* obj, float speedZ, bool withOrientation = false);

        void MonsterMoveWithSpeed(float x, float y, float z, float speed, bool generatePath = false, bool forceDestination = false);


        void SendSetPlayHoverAnim(bool enable);

        bool IsLevitating() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY); }
        bool IsWalking() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_WALKING); }
        bool IsHovering() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_HOVER); }
        bool SetWalk(bool enable);
        bool SetDisableGravity(bool disable);
        bool SetFall(bool enable);
        bool SetSwim(bool enable);
        bool SetCanFly(bool enable);
        bool SetWaterWalking(bool enable);
        bool SetFeatherFall(bool enable);
        bool SetHover(bool enable);
        bool SetCollision(bool disable);
        bool SetCanTransitionBetweenSwimAndFly(bool enable);
        bool SetCanTurnWhileFalling(bool enable);
        bool SetCanDoubleJump(bool enable);
        void SendSetVehicleRecId(uint32 vehicleId);

        void SetInFront(WorldObject const* target);
        void SetFacingTo(float ori, bool force = false);
        void SetFacingToObject(WorldObject const* object, bool force = false);

        void SendChangeCurrentVictimOpcode(HostileReference* pHostileReference);
        void SendClearThreatListOpcode();
        void SendRemoveFromThreatListOpcode(HostileReference* pHostileReference);
        void SendThreatListUpdate();

        void SendClearTarget();

        bool IsAlive() const { return (m_deathState == ALIVE); }
        bool isDying() const { return (m_deathState == JUST_DIED); }
        bool isDead() const { return (m_deathState == DEAD || m_deathState == CORPSE); }
        DeathState getDeathState() const { return m_deathState; }
        virtual void setDeathState(DeathState s);           // overwrited in Creature/Player/Pet

        ObjectGuid GetOwnerGUID() const { return  GetGuidValue(UNIT_FIELD_SUMMONEDBY); }
        void SetOwnerGUID(ObjectGuid owner);
        ObjectGuid GetCreatorGUID() const { return GetGuidValue(UNIT_FIELD_CREATEDBY); }
        void SetCreatorGUID(ObjectGuid creator) { SetGuidValue(UNIT_FIELD_CREATEDBY, creator); }
        ObjectGuid GetMinionGUID() const { return GetGuidValue(UNIT_FIELD_SUMMON); }
        void SetMinionGUID(ObjectGuid guid) { SetGuidValue(UNIT_FIELD_SUMMON, guid); }
        ObjectGuid GetCharmerGUID() const { return GetGuidValue(UNIT_FIELD_CHARMEDBY); }
        void SetCharmerGUID(ObjectGuid owner) { SetGuidValue(UNIT_FIELD_CHARMEDBY, owner); }
        ObjectGuid GetCharmGUID() const { return  GetGuidValue(UNIT_FIELD_CHARM); }
        void SetPetGUID(ObjectGuid guid) { m_SummonSlot[SUMMON_SLOT_PET] = guid; }
        ObjectGuid GetPetGUID() const { return m_SummonSlot[SUMMON_SLOT_PET]; }
        void SetCritterGUID(ObjectGuid guid) { SetGuidValue(UNIT_FIELD_CRITTER, guid); }
        ObjectGuid GetCritterGUID() const { return GetGuidValue(UNIT_FIELD_CRITTER); }

        bool IsControlledByPlayer() const { return m_ControlledByPlayer; }
        ObjectGuid GetCharmerOrOwnerGUID() const;
        ObjectGuid GetCharmerOrOwnerOrOwnGUID() const;
        bool IsCharmedOwnedByPlayerOrPlayer() const { return GetCharmerOrOwnerOrOwnGUID().IsPlayer(); }

        Player* GetSpellModOwner() const;

        Unit* GetOwner() const;
        Guardian* GetGuardianPet() const;
        Minion* GetFirstMinion() const;
        Unit* GetCharmer() const;
        Unit* GetCharm() const;
        Unit* GetCharmerOrOwner() const;
        Unit* GetCharmerOrOwnerOrSelf() const;
        Player* GetCharmerOrOwnerPlayerOrPlayerItself() const;
        Player* GetAffectingPlayer() const;

        void SetMinion(Minion *minion, bool apply);
        void GetAllMinionsByEntry(std::list<TempSummon*>& Minions, uint32 entry);
        void RemoveAllMinionsByEntry(uint32 entry);
        void SetCharm(Unit* target, bool apply);
        Unit* GetNextRandomRaidMemberOrPet(float radius);
        bool SetCharmedBy(Unit* charmer, CharmType type, AuraApplication const* aurApp = NULL);
        void RemoveCharmedBy(Unit* charmer);
        void RestoreFaction();

        ControlList m_Controlled;
        Unit* GetFirstControlled() const;
        void RemoveAllControlled();

        bool IsCharmed() const { return !GetCharmerGUID().IsEmpty(); }
        bool isPossessed() const { return HasUnitState(UNIT_STATE_POSSESSED); }
        bool isPossessedByPlayer() const;
        bool isPossessing() const;
        bool isPossessing(Unit* u) const;

        CharmInfo* GetCharmInfo() { return m_charmInfo; }
        CharmInfo* InitCharmInfo();
        void DeleteCharmInfo();
        void UpdateCharmAI();
        // returns the unit that this player IS CONTROLLING
        Unit* GetUnitBeingMoved() const;
        // returns the player that this player IS CONTROLLING
        Player* GetPlayerBeingMoved() const;
        // returns the player that this unit is BEING CONTROLLED BY
        Player* GetPlayerMovingMe() const { return m_playerMovingMe; }
        // only set for direct client control (possess effects, vehicles and similar)
        Player* m_playerMovingMe;
        SharedVisionList const& GetSharedVisionList() { return m_sharedVision; }
        void AddPlayerToVision(Player* player);
        void RemovePlayerFromVision(Player* player);
        bool HasSharedVision() const { return !m_sharedVision.empty(); }
        void RemoveBindSightAuras();
        void RemoveCharmAuras();

        Pet* CreateTamedPetFrom(Creature* creatureTarget, uint32 spell_id = 0);
        Pet* CreateTamedPetFrom(uint32 creatureEntry, uint32 spell_id = 0);
        bool InitTamedPet(Pet* pet, uint8 level, uint32 spell_id);

        // aura apply/remove helpers - you should better not use these
        Aura* _TryStackingOrRefreshingExistingAura(SpellInfo const* newAura, uint32 effMask, Unit* caster, int32 *baseAmount = NULL, Item* castItem = NULL, ObjectGuid casterGUID = ObjectGuid::Empty, int32 castItemLevel = -1);
        void _AddAura(UnitAura* aura, Unit* caster);
        AuraApplication * _CreateAuraApplication(Aura* aura, uint32 effMask);
        void _ApplyAuraEffect(Aura* aura, uint8 effIndex);
        void _ApplyAura(AuraApplication * aurApp, uint32 effMask);
        void _UnapplyAura(AuraApplicationMap::iterator &i, AuraRemoveMode removeMode);
        void _UnapplyAura(AuraApplication * aurApp, AuraRemoveMode removeMode);
        void _RemoveNoStackAuraApplicationsDueToAura(Aura* aura);
        void _RemoveNoStackAurasDueToAura(Aura* aura);
        bool _IsNoStackAuraDueToAura(Aura* appliedAura, Aura* existingAura) const;
        void _RegisterAuraEffect(AuraEffect* aurEff, bool apply);

        // m_ownedAuras container management
        AuraMap      & GetOwnedAuras()       { return m_ownedAuras; }
        AuraMap const& GetOwnedAuras() const { return m_ownedAuras; }

        void RemoveOwnedAura(AuraMap::iterator &i, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAura(Aura* aura, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        Aura* GetOwnedAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, Aura* except = NULL) const;

        // m_appliedAuras container management
        AuraApplicationMap      & GetAppliedAuras()       { return m_appliedAuras; }
        AuraApplicationMap const& GetAppliedAuras() const { return m_appliedAuras; }

        void RemoveAura(AuraApplicationMap::iterator &i, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(AuraApplication * aurApp, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(Aura* aur, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);

        // Convenience methods removing auras by predicate
        void RemoveAppliedAuras(std::function<bool(AuraApplication const*)> const& check);
        void RemoveOwnedAuras(std::function<bool(Aura const*)> const& check);

        // Optimized overloads taking advantage of map key
        void RemoveAppliedAuras(uint32 spellId, std::function<bool(AuraApplication const*)> const& check);
        void RemoveOwnedAuras(uint32 spellId, std::function<bool(Aura const*)> const& check);

        void RemoveAurasByType(AuraType auraType, std::function<bool(AuraApplication const*)> const& check);

        void RemoveAurasDueToSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAuraFromStack(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT, uint16 num = 1);
        void RemoveAurasDueToSpellByDispel(uint32 spellId, uint32 dispellerSpellId, ObjectGuid casterGUID, Unit* dispeller, uint8 chargesRemoved = 1);
        void RemoveAurasDueToSpellBySteal(uint32 spellId, ObjectGuid casterGUID, Unit* stealer);
        void RemoveAurasDueToItemSpell(uint32 spellId, ObjectGuid castItemGuid);
        void RemoveAurasByType(AuraType auraType, ObjectGuid casterGUID = ObjectGuid::Empty, Aura* except = NULL, bool negative = true, bool positive = true);
        void RemoveNotOwnSingleTargetAuras(uint32 newPhase = 0x0, bool phaseid = false);
        void RemoveAurasWithInterruptFlags(uint32 flag, uint32 except = 0);
        void RemoveAurasWithAttribute(uint32 flags);
        void RemoveAurasWithFamily(SpellFamilyNames family, flag128 const& familyFlag, ObjectGuid casterGUID);
        void RemoveAurasWithMechanic(uint32 mechanic_mask, AuraRemoveMode removemode = AURA_REMOVE_BY_DEFAULT, uint32 except = 0);
        void RemoveMovementImpairingAuras();

        void RemoveAreaAurasDueToLeaveWorld();
        void RemoveAllAuras();
        void RemoveArenaAuras();
        void RemoveAurasOnEvade();
        void RemoveAllAurasOnDeath();
        void RemoveAllAurasRequiringDeadTarget();
        void RemoveAllAurasExceptType(AuraType type);
        void RemoveAllAurasExceptType(AuraType type1, AuraType type2); /// @todo: once we support variadic templates use them here
        void RemoveAllGroupBuffsFromCaster(ObjectGuid casterGUID);
        void DelayOwnedAuras(uint32 spellId, ObjectGuid caster, int32 delaytime);

        void _RemoveAllAuraStatMods();
        void _ApplyAllAuraStatMods();

        AuraEffectList const& GetAuraEffectsByType(AuraType type) const { return m_modAuras[type]; }
        AuraList      & GetSingleCastAuras()       { return m_scAuras; }
        AuraList const& GetSingleCastAuras() const { return m_scAuras; }

        AuraEffect* GetAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetAuraEffectOfRankedSpell(uint32 spellId, uint8 effIndex, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetAuraEffect(AuraType type, SpellFamilyNames name, uint32 iconId, uint8 effIndex) const; // spell mustn't have familyflags
        AuraEffect* GetAuraEffect(AuraType type, SpellFamilyNames family, flag128 const& familyFlag, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetDummyAuraEffect(SpellFamilyNames name, uint32 iconId, uint8 effIndex) const;

        AuraApplication * GetAuraApplication(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraApplication * except = NULL) const;
        Aura* GetAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0) const;

        AuraApplication * GetAuraApplicationOfRankedSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraApplication * except = NULL) const;
        Aura* GetAuraOfRankedSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0) const;

        void GetDispellableAuraList(Unit* caster, uint32 dispelMask, DispelChargesList& dispelList);

        bool HasAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid caster = ObjectGuid::Empty) const;
        uint32 GetAuraCount(uint32 spellId) const;
        bool HasAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0) const;
        bool HasAuraType(AuraType auraType) const;
        bool HasAuraTypeWithCaster(AuraType auratype, ObjectGuid caster) const;
        bool HasAuraTypeWithMiscvalue(AuraType auratype, int32 miscvalue) const;
        bool HasAuraTypeWithAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const;
        bool HasAuraTypeWithValue(AuraType auratype, int32 value) const;
        bool HasNegativeAuraWithInterruptFlag(uint32 flag, ObjectGuid guid = ObjectGuid::Empty) const;
        bool HasNegativeAuraWithAttribute(uint32 flag, ObjectGuid guid = ObjectGuid::Empty) const;
        bool HasAuraWithMechanic(uint32 mechanicMask) const;

        AuraEffect* IsScriptOverriden(SpellInfo const* spell, int32 script) const;
        uint32 GetDiseasesByCaster(ObjectGuid casterGUID, bool remove = false);
        uint32 GetDoTsByCaster(ObjectGuid casterGUID) const;

        int32 GetTotalAuraModifier(AuraType auratype) const;
        float GetTotalAuraMultiplier(AuraType auratype) const;
        int32 GetMaxPositiveAuraModifier(AuraType auratype) const;
        int32 GetMaxNegativeAuraModifier(AuraType auratype) const;

        int32 GetTotalAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        float GetTotalAuraMultiplierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        int32 GetMaxPositiveAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask, const AuraEffect* except = NULL) const;
        int32 GetMaxNegativeAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const;

        int32 GetTotalAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;
        float GetTotalAuraMultiplierByMiscValue(AuraType auratype, int32 misc_value) const;
        int32 GetMaxPositiveAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;
        int32 GetMaxNegativeAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;

        int32 GetTotalAuraModifierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const;
        float GetTotalAuraMultiplierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const;
        int32 GetMaxPositiveAuraModifierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const;
        int32 GetMaxNegativeAuraModifierByAffectMask(AuraType auratype, SpellInfo const* affectedSpell) const;

        float GetResistanceBuffMods(SpellSchools school, bool positive) const;
        void SetResistanceBuffMods(SpellSchools school, bool positive, float val);
        void ApplyResistanceBuffModsMod(SpellSchools school, bool positive, float val, bool apply);
        void ApplyResistanceBuffModsPercentMod(SpellSchools school, bool positive, float val, bool apply);
        void InitStatBuffMods();
        void ApplyStatBuffMod(Stats stat, float val, bool apply);
        void ApplyStatPercentBuffMod(Stats stat, float val, bool apply);
        void SetCreateStat(Stats stat, float val) { m_createStats[stat] = val; }
        void SetCreateHealth(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_HEALTH, val); }
        uint32 GetCreateHealth() const { return GetUInt32Value(UNIT_FIELD_BASE_HEALTH); }
        void SetCreateMana(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_MANA, val); }
        uint32 GetCreateMana() const { return GetUInt32Value(UNIT_FIELD_BASE_MANA); }
        uint32 GetPowerIndex(uint32 powerType) const;
        int32 GetCreatePowers(Powers power) const;
        float GetPosStat(Stats stat) const { return GetFloatValue(UNIT_FIELD_POSSTAT+stat); }
        float GetNegStat(Stats stat) const { return GetFloatValue(UNIT_FIELD_NEGSTAT+stat); }
        float GetCreateStat(Stats stat) const { return m_createStats[stat]; }

        ObjectGuid GetChannelObjectGuid() const { return GetGuidValue(UNIT_FIELD_CHANNEL_OBJECT); }
        void SetChannelObjectGuid(ObjectGuid guid) { SetGuidValue(UNIT_FIELD_CHANNEL_OBJECT, guid); }

        void SetCurrentCastSpell(Spell* pSpell);
        void InterruptSpell(CurrentSpellTypes spellType, bool withDelayed = true, bool withInstant = true);
        void FinishSpell(CurrentSpellTypes spellType, bool ok = true);

        // set withDelayed to true to account delayed spells as cast
        // delayed+channeled spells are always accounted as cast
        // we can skip channeled or delayed checks using flags
        bool IsNonMeleeSpellCast(bool withDelayed, bool skipChanneled = false, bool skipAutorepeat = false, bool isAutoshoot = false, bool skipInstant = true) const;

        // set withDelayed to true to interrupt delayed spells too
        // delayed+channeled spells are always interrupted
        void InterruptNonMeleeSpells(bool withDelayed, uint32 spellid = 0, bool withInstant = true);

        Spell* GetCurrentSpell(CurrentSpellTypes spellType) const { return m_currentSpells[spellType]; }
        Spell* GetCurrentSpell(uint32 spellType) const { return m_currentSpells[spellType]; }
        Spell* FindCurrentSpellBySpellId(uint32 spell_id) const;
        int32 GetCurrentSpellCastTime(uint32 spell_id) const;
        virtual SpellInfo const* GetCastSpellInfo(SpellInfo const* spellInfo) const;
        uint32 GetCastSpellXSpellVisualId(SpellInfo const* spellInfo) const;

        // Check if our current channel spell has attribute SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING
        bool CanMoveDuringChannel() const;

        SpellHistory* GetSpellHistory() { return _spellHistory; }
        SpellHistory const* GetSpellHistory() const { return _spellHistory; }

        ObjectGuid m_SummonSlot[MAX_SUMMON_SLOT];
        ObjectGuid m_ObjectSlot[MAX_GAMEOBJECT_SLOT];

        ShapeshiftForm GetShapeshiftForm() const { return ShapeshiftForm(GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHAPESHIFT_FORM)); }
        void SetShapeshiftForm(ShapeshiftForm form);

        bool IsInFeralForm() const;

        bool IsInDisallowedMountForm() const;

        float m_modMeleeHitChance;
        float m_modRangedHitChance;
        float m_modSpellHitChance;
        int32 m_baseSpellCritChance;

        float m_threatModifier[MAX_SPELL_SCHOOL];

        uint32 m_baseAttackSpeed[MAX_ATTACK];
        float m_modAttackSpeedPct[MAX_ATTACK];
        uint32 m_attackTimer[MAX_ATTACK];

        // Event handler
        EventProcessor m_Events;

        // stat system
        bool HandleStatModifier(UnitMods unitMod, UnitModifierType modifierType, float amount, bool apply);
        void SetModifierValue(UnitMods unitMod, UnitModifierType modifierType, float value) { m_auraModifiersGroup[unitMod][modifierType] = value; }
        float GetModifierValue(UnitMods unitMod, UnitModifierType modifierType) const;
        float GetTotalStatValue(Stats stat) const;
        float GetTotalAuraModValue(UnitMods unitMod) const;
        SpellSchools GetSpellSchoolByAuraGroup(UnitMods unitMod) const;
        Stats GetStatByAuraGroup(UnitMods unitMod) const;
        Powers GetPowerTypeByAuraGroup(UnitMods unitMod) const;
        bool CanModifyStats() const { return m_canModifyStats; }
        void SetCanModifyStats(bool modifyStats) { m_canModifyStats = modifyStats; }
        virtual bool UpdateStats(Stats stat) = 0;
        virtual bool UpdateAllStats() = 0;
        virtual void UpdateResistances(uint32 school) = 0;
        virtual void UpdateAllResistances();
        virtual void UpdateArmor() = 0;
        virtual void UpdateMaxHealth() = 0;
        virtual void UpdateMaxPower(Powers power) = 0;
        virtual void UpdateAttackPowerAndDamage(bool ranged = false) = 0;
        virtual void UpdateDamagePhysical(WeaponAttackType attType);
        float GetTotalAttackPowerValue(WeaponAttackType attType) const;
        float GetWeaponDamageRange(WeaponAttackType attType, WeaponDamageRange type) const;
        void SetBaseWeaponDamage(WeaponAttackType attType, WeaponDamageRange damageRange, float value) { m_weaponDamage[attType][damageRange] = value; }
        virtual void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, float& minDamage, float& maxDamage) = 0;
        uint32 CalculateDamage(WeaponAttackType attType, bool normalized, bool addTotalPct);
        float GetAPMultiplier(WeaponAttackType attType, bool normalized);

        bool isInFrontInMap(Unit const* target, float distance, float arc = float(M_PI)) const;
        bool isInBackInMap(Unit const* target, float distance, float arc = float(M_PI)) const;

        // Visibility system
        bool IsVisible() const;
        void SetVisible(bool x);

        // common function for visibility checks for player/creatures with detection code
        bool SetInPhase(uint32 id, bool update, bool apply) override;
        void UpdateObjectVisibility(bool forced = true) override;

        SpellImmuneList m_spellImmune[MAX_SPELL_IMMUNITY];
        uint32 m_lastSanctuaryTime;

        // Threat related methods
        bool CanHaveThreatList(bool skipAliveCheck = false) const;
        void AddThreat(Unit* victim, float fThreat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellInfo const* threatSpell = NULL);
        float ApplyTotalThreatModifier(float fThreat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL);
        void DeleteThreatList();
        void TauntApply(Unit* victim);
        void TauntFadeOut(Unit* taunter);
        ThreatManager& getThreatManager() { return m_ThreatManager; }
        void addHatedBy(HostileReference* pHostileReference) { m_HostileRefManager.insertFirst(pHostileReference); }
        void removeHatedBy(HostileReference* /*pHostileReference*/) { /* nothing to do yet */ }
        HostileRefManager& getHostileRefManager() { return m_HostileRefManager; }

        VisibleAuraContainer const& GetVisibleAuras() const { return m_visibleAuras; }
        bool HasVisibleAura(AuraApplication* aurApp) const { return m_visibleAuras.count(aurApp) > 0; }
        void SetVisibleAura(AuraApplication* aurApp);
        void SetVisibleAuraUpdate(AuraApplication* aurApp) { m_visibleAurasToUpdate.insert(aurApp); }
        void RemoveVisibleAura(AuraApplication* aurApp);

        uint32 GetInterruptMask() const { return m_interruptMask; }
        void AddInterruptMask(uint32 mask) { m_interruptMask |= mask; }
        void UpdateInterruptMask();

        uint32 GetDisplayId() const { return GetUInt32Value(UNIT_FIELD_DISPLAYID); }
        virtual void SetDisplayId(uint32 modelId);
        uint32 GetNativeDisplayId() const { return GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID); }
        void RestoreDisplayId();
        void SetNativeDisplayId(uint32 modelId) { SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, modelId); }
        void setTransForm(uint32 spellid) { m_transform = spellid;}
        uint32 getTransForm() const { return m_transform;}

        // DynamicObject management
        void _RegisterDynObject(DynamicObject* dynObj);
        void _UnregisterDynObject(DynamicObject* dynObj);
        DynamicObject* GetDynObject(uint32 spellId) const;
        std::vector<DynamicObject*> GetDynObjects(uint32 spellId) const;
        void RemoveDynObject(uint32 spellId);
        void RemoveAllDynObjects();

        GameObject* GetGameObject(uint32 spellId) const;
        std::vector<GameObject*> GetGameObjects(uint32 spellId) const;
        void AddGameObject(GameObject* gameObj);
        void RemoveGameObject(GameObject* gameObj, bool del);
        void RemoveGameObject(uint32 spellid, bool del);
        void RemoveAllGameObjects();

        // AreaTrigger management
        void _RegisterAreaTrigger(AreaTrigger* areaTrigger);
        void _UnregisterAreaTrigger(AreaTrigger* areaTrigger);
        AreaTrigger* GetAreaTrigger(uint32 spellId) const;
        std::vector<AreaTrigger*> GetAreaTriggers(uint32 spellId) const;
        void RemoveAreaTrigger(uint32 spellId);
        void RemoveAllAreaTriggers();

        void ModifyAuraState(AuraStateType flag, bool apply);
        uint32 BuildAuraStateUpdateForTarget(Unit* target) const;
        bool HasAuraState(AuraStateType flag, SpellInfo const* spellProto = NULL, Unit const* Caster = NULL) const;
        void UnsummonAllTotems();
        bool IsMagnet() const;
        Unit* GetMagicHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo);
        Unit* GetMeleeHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo = NULL);

        int32  SpellBaseDamageBonusDone(SpellSchoolMask schoolMask) const;
        int32  SpellBaseDamageBonusTaken(SpellSchoolMask schoolMask) const;
        uint32 SpellDamageBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype, SpellEffectInfo const* effect, uint32 stack = 1) const;
        float  SpellDamagePctDone(Unit* victim, SpellInfo const* spellProto, DamageEffectType damagetype) const;
        uint32 SpellDamageBonusTaken(Unit* caster, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype, SpellEffectInfo const* effect, uint32 stack = 1) const;
        int32  SpellBaseHealingBonusDone(SpellSchoolMask schoolMask) const;
        int32  SpellBaseHealingBonusTaken(SpellSchoolMask schoolMask) const;
        uint32 SpellHealingBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype, SpellEffectInfo const* effect, uint32 stack = 1) const;
        float SpellHealingPctDone(Unit* victim, SpellInfo const* spellProto) const;
        uint32 SpellHealingBonusTaken(Unit* caster, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype, SpellEffectInfo const* effect, uint32 stack = 1) const;

        uint32 MeleeDamageBonusDone(Unit* pVictim, uint32 damage, WeaponAttackType attType, SpellInfo const* spellProto = NULL);
        uint32 MeleeDamageBonusTaken(Unit* attacker, uint32 pdamage, WeaponAttackType attType, SpellInfo const* spellProto = NULL);

        bool   isSpellBlocked(Unit* victim, SpellInfo const* spellProto, WeaponAttackType attackType = BASE_ATTACK);
        bool   isBlockCritical();
        bool   IsSpellCrit(Unit* victim, SpellInfo const* spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK) const;
        float  GetUnitSpellCriticalChance(Unit* victim, SpellInfo const* spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK) const;
        uint32 SpellCriticalDamageBonus(SpellInfo const* spellProto, uint32 damage, Unit* victim);
        uint32 SpellCriticalHealingBonus(SpellInfo const* spellProto, uint32 damage, Unit* victim);

        void SetContestedPvP(Player* attackedPlayer = NULL);

        uint32 GetCastingTimeForBonus(SpellInfo const* spellProto, DamageEffectType damagetype, uint32 CastingTime) const;
        float CalculateDefaultCoefficient(SpellInfo const* spellInfo, DamageEffectType damagetype) const;

        uint32 GetRemainingPeriodicAmount(ObjectGuid caster, uint32 spellId, AuraType auraType, uint8 effectIndex = 0) const;

        void ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply);
        void ApplySpellDispelImmunity(const SpellInfo* spellProto, DispelType type, bool apply);
        virtual bool IsImmunedToSpell(SpellInfo const* spellInfo) const; // redefined in Creature
        uint32 GetSchoolImmunityMask() const;
        uint32 GetMechanicImmunityMask() const;

        bool IsImmunedToDamage(SpellSchoolMask meleeSchoolMask) const;
        bool IsImmunedToDamage(SpellInfo const* spellInfo) const;
        virtual bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index) const; // redefined in Creature

        bool IsDamageReducedByArmor(SpellSchoolMask damageSchoolMask, SpellInfo const* spellInfo = nullptr, int8 effIndex = -1);
        uint32 CalcArmorReducedDamage(Unit* attacker, Unit* victim, const uint32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType = MAX_ATTACK);
        uint32 CalcSpellResistance(Unit* victim, SpellSchoolMask schoolMask, SpellInfo const* spellInfo) const;
        void CalcAbsorbResist(Unit* victim, SpellSchoolMask schoolMask, DamageEffectType damagetype, uint32 const damage, uint32* absorb, uint32* resist, SpellInfo const* spellInfo = NULL);
        void CalcHealAbsorb(Unit* victim, SpellInfo const* spellInfo, uint32& healAmount, uint32& absorb);

        void  UpdateSpeed(UnitMoveType mtype);
        float GetSpeed(UnitMoveType mtype) const;
        float GetSpeedRate(UnitMoveType mtype) const { return m_speed_rate[mtype]; }
        void SetSpeed(UnitMoveType mtype, float newValue);
        void SetSpeedRate(UnitMoveType mtype, float rate);

        float ApplyEffectModifiers(SpellInfo const* spellProto, uint8 effect_index, float value) const;
        int32 CalculateSpellDamage(Unit const* target, SpellInfo const* spellProto, uint8 effect_index, int32 const* basePoints = nullptr, float* variance = nullptr, int32 itemLevel = -1) const;
        int32 CalcSpellDuration(SpellInfo const* spellProto);
        int32 ModSpellDuration(SpellInfo const* spellProto, Unit const* target, int32 duration, bool positive, uint32 effectMask);
        void  ModSpellCastTime(SpellInfo const* spellProto, int32& castTime, Spell* spell = NULL);
        void  ModSpellDurationTime(SpellInfo const* spellProto, int32& castTime, Spell* spell = NULL);
        float CalculateLevelPenalty(SpellInfo const* spellProto) const;

        void addFollower(FollowerReference* pRef) { m_FollowingRefManager.insertFirst(pRef); }
        void removeFollower(FollowerReference* /*pRef*/) { /* nothing to do yet */ }

        MotionMaster* GetMotionMaster() { return i_motionMaster; }
        const MotionMaster* GetMotionMaster() const { return i_motionMaster; }

        bool IsStopped() const { return !(HasUnitState(UNIT_STATE_MOVING)); }
        void StopMoving();

        void AddUnitMovementFlag(uint32 f) { m_movementInfo.AddMovementFlag(f); }
        void RemoveUnitMovementFlag(uint32 f) { m_movementInfo.RemoveMovementFlag(f); }
        bool HasUnitMovementFlag(uint32 f) const { return m_movementInfo.HasMovementFlag(f); }
        uint32 GetUnitMovementFlags() const { return m_movementInfo.GetMovementFlags(); }
        void SetUnitMovementFlags(uint32 f) { m_movementInfo.SetMovementFlags(f); }

        void AddExtraUnitMovementFlag(uint32 f) { m_movementInfo.AddExtraMovementFlag(f); }
        void RemoveExtraUnitMovementFlag(uint32 f) { m_movementInfo.RemoveExtraMovementFlag(f); }
        bool HasExtraUnitMovementFlag(uint32 f) const { return m_movementInfo.HasExtraMovementFlag(f); }
        uint32 GetExtraUnitMovementFlags() const { return m_movementInfo.GetExtraMovementFlags(); }
        void SetExtraUnitMovementFlags(uint32 f) { m_movementInfo.SetExtraMovementFlags(f); }
        bool IsSplineEnabled() const;

        float GetPositionZMinusOffset() const;

        void SetControlled(bool apply, UnitState state);

        ///----------Pet responses methods-----------------
        void SendPetActionFeedback (uint8 msg);
        void SendPetTalk (uint32 pettalk);
        void SendPetAIReaction(ObjectGuid guid);
        ///----------End of Pet responses methods----------

        void propagateSpeedChange() { GetMotionMaster()->propagateSpeedChange(); }

        // reactive attacks
        void ClearAllReactives();
        void StartReactiveTimer(ReactiveType reactive) { m_reactiveTimer[reactive] = REACTIVE_TIMER_START;}
        void UpdateReactives(uint32 p_time);

        // group updates
        void UpdateAuraForGroup();

        // proc trigger system
        bool CanProc() const {return !m_procDeep;}
        void SetCantProc(bool apply);

        // pet auras
        typedef std::set<PetAura const*> PetAuraSet;
        PetAuraSet m_petAuras;
        void AddPetAura(PetAura const* petSpell);
        void RemovePetAura(PetAura const* petSpell);

        uint32 GetModelForForm(ShapeshiftForm form) const;
        uint32 GetModelForTotem(PlayerTotemType totemType);

        // Redirect Threat
        void SetRedirectThreat(ObjectGuid guid, uint32 pct) { _redirectThreadInfo.Set(guid, pct); }
        void ResetRedirectThreat() { SetRedirectThreat(ObjectGuid::Empty, 0); }
        void ModifyRedirectThreat(int32 amount) { _redirectThreadInfo.ModifyThreatPct(amount); }
        uint32 GetRedirectThreatPercent() const { return _redirectThreadInfo.GetThreatPct(); }
        Unit* GetRedirectThreatTarget();

        friend class VehicleJoinEvent;
        bool IsAIEnabled, NeedChangeAI;
        ObjectGuid LastCharmerGUID;
        bool CreateVehicleKit(uint32 id, uint32 creatureEntry, bool loading = false);
        void RemoveVehicleKit(bool onRemoveFromWorld = false);
        Vehicle* GetVehicleKit()const { return m_vehicleKit; }
        Vehicle* GetVehicle()   const { return m_vehicle; }
        void SetVehicle(Vehicle* vehicle) { m_vehicle = vehicle; }
        bool IsOnVehicle(const Unit* vehicle) const;
        Unit* GetVehicleBase()  const;
        Creature* GetVehicleCreatureBase() const;
        ObjectGuid GetTransGUID()   const override;
        /// Returns the transport this unit is on directly (if on vehicle and transport, return vehicle)
        TransportBase* GetDirectTransport() const;

        bool m_ControlledByPlayer;

        bool HandleSpellClick(Unit* clicker, int8 seatId = -1);
        void EnterVehicle(Unit* base, int8 seatId = -1);
        void ExitVehicle(Position const* exitPosition = NULL);
        void ChangeSeat(int8 seatId, bool next = true);

        // Should only be called by AuraEffect::HandleAuraControlVehicle(AuraApplication const* auraApp, uint8 mode, bool apply) const;
        void _ExitVehicle(Position const* exitPosition = NULL);
        void _EnterVehicle(Vehicle* vehicle, int8 seatId, AuraApplication const* aurApp = NULL);

        bool isMoving() const   { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_MASK_MOVING); }
        bool isTurning() const  { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_MASK_TURNING); }
        virtual bool CanFly() const = 0;
        bool IsFlying() const   { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_DISABLE_GRAVITY); }
        bool IsFalling() const;
        virtual bool CanSwim() const;

        void RewardRage(uint32 baseRage);

        virtual float GetFollowAngle() const { return static_cast<float>(M_PI/2); }

        void OutDebugInfo() const;
        virtual bool IsLoading() const { return false; }
        bool IsDuringRemoveFromWorld() const {return m_duringRemoveFromWorld;}

        Pet* ToPet() { if (IsPet()) return reinterpret_cast<Pet*>(this); else return NULL; }
        Pet const* ToPet() const { if (IsPet()) return reinterpret_cast<Pet const*>(this); else return NULL; }

        Totem* ToTotem() { if (IsTotem()) return reinterpret_cast<Totem*>(this); else return NULL; }
        Totem const* ToTotem() const { if (IsTotem()) return reinterpret_cast<Totem const*>(this); else return NULL; }

        TempSummon* ToTempSummon() { if (IsSummon()) return reinterpret_cast<TempSummon*>(this); else return NULL; }
        TempSummon const* ToTempSummon() const { if (IsSummon()) return reinterpret_cast<TempSummon const*>(this); else return NULL; }

        ObjectGuid GetTarget() const { return GetGuidValue(UNIT_FIELD_TARGET); }
        virtual void SetTarget(ObjectGuid const& /*guid*/) = 0;

        // Movement info
        Movement::MoveSpline * movespline;

        // Part of Evade mechanics
        time_t GetLastDamagedTime() const { return _lastDamagedTime; }
        void UpdateLastDamagedTime(SpellInfo const* spellProto);
        void SetLastDamagedTime(time_t val) { _lastDamagedTime = val; }

        int32 GetHighestExclusiveSameEffectSpellGroupValue(AuraEffect const* aurEff, AuraType auraType, bool checkMiscValue = false, int32 miscValue = 0) const;
        bool IsHighestExclusiveAura(Aura const* aura, bool removeOtherAuraApplications = false);

        virtual void Talk(std::string const& text, ChatMsg msgType, Language language, float textRange, WorldObject const* target);
        virtual void Say(std::string const& text, Language language, WorldObject const* target = nullptr);
        virtual void Yell(std::string const& text, Language language, WorldObject const* target = nullptr);
        virtual void TextEmote(std::string const& text, WorldObject const* target = nullptr, bool isBossEmote = false);
        virtual void Whisper(std::string const& text, Language language, Player* target, bool isBossWhisper = false);
        virtual void Talk(uint32 textId, ChatMsg msgType, float textRange, WorldObject const* target);
        virtual void Say(uint32 textId, WorldObject const* target = nullptr);
        virtual void Yell(uint32 textId, WorldObject const* target = nullptr);
        virtual void TextEmote(uint32 textId, WorldObject const* target = nullptr, bool isBossEmote = false);
        virtual void Whisper(uint32 textId, Player* target, bool isBossWhisper = false);

        uint32 GetVirtualItemId(uint32 slot) const;
        uint16 GetVirtualItemAppearanceMod(uint32 slot) const;
        void SetVirtualItem(uint32 slot, uint32 itemId, uint16 appearanceModId = 0, uint16 itemVisual = 0);

    protected:
        explicit Unit (bool isWorldObject);

        void BuildValuesUpdate(uint8 updatetype, ByteBuffer* data, Player* target) const override;
        void DestroyForPlayer(Player* target) const override;

        UnitAI* i_AI, *i_disabledAI;

        void _UpdateSpells(uint32 time);
        void _DeleteRemovedAuras();

        void _UpdateAutoRepeatSpell();

        bool m_AutoRepeatFirstCast;

        float m_createStats[MAX_STATS];

        AttackerSet m_attackers;
        Unit* m_attacking;

        DeathState m_deathState;

        int32 m_procDeep;

        typedef std::list<DynamicObject*> DynObjectList;
        DynObjectList m_dynObj;

        typedef std::list<GameObject*> GameObjectList;
        GameObjectList m_gameObj;

        typedef std::vector<AreaTrigger*> AreaTriggerList;
        AreaTriggerList m_areaTrigger;

        uint32 m_transform;

        Spell* m_currentSpells[CURRENT_MAX_SPELL];

        AuraMap m_ownedAuras;
        AuraApplicationMap m_appliedAuras;
        AuraList m_removedAuras;
        AuraMap::iterator m_auraUpdateIterator;
        uint32 m_removedAurasCount;

        AuraEffectList m_modAuras[TOTAL_AURAS];
        AuraList m_scAuras;                        // cast singlecast auras
        AuraApplicationList m_interruptableAuras;  // auras which have interrupt mask applied on unit
        AuraStateAurasMap m_auraStateAuras;        // Used for improve performance of aura state checks on aura apply/remove
        uint32 m_interruptMask;

        float m_auraModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_END];
        float m_weaponDamage[MAX_ATTACK][2];
        bool m_canModifyStats;

        VisibleAuraContainer m_visibleAuras;
        boost::container::flat_set<AuraApplication*, VisibleAuraSlotCompare> m_visibleAurasToUpdate;

        float m_speed_rate[MAX_MOVE_TYPE];

        CharmInfo* m_charmInfo;
        SharedVisionList m_sharedVision;

        virtual SpellSchoolMask GetMeleeDamageSchoolMask() const;

        MotionMaster* i_motionMaster;

        uint32 m_reactiveTimer[MAX_REACTIVE];
        uint32 m_regenTimer;

        ThreatManager m_ThreatManager;

        Vehicle* m_vehicle;
        Vehicle* m_vehicleKit;

        uint32 m_unitTypeMask;
        LiquidTypeEntry const* _lastLiquid;

        bool IsAlwaysVisibleFor(WorldObject const* seer) const override;
        bool IsAlwaysDetectableFor(WorldObject const* seer) const override;

        void DisableSpline();
    private:
        bool IsTriggeredAtSpellProcEvent(Unit* victim, Aura* aura, SpellInfo const* procSpell, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, bool isVictim, bool active, SpellProcEventEntry const*& spellProcEvent);
        bool RollProcResult(Unit* victim, Aura* aura, WeaponAttackType attType, bool isVictim, SpellProcEventEntry const* spellProcEvent);
        bool HandleDummyAuraProc(Unit* victim, uint32 damage, AuraEffect* triggeredByAura, SpellInfo const* procSpell, uint32 procFlag, uint32 procEx);
        bool HandleAuraProc(Unit* victim, uint32 damage, Aura* triggeredByAura, SpellInfo const* procSpell, uint32 procFlag, uint32 procEx, bool* handled);
        bool HandleProcTriggerSpell(Unit* victim, uint32 damage, AuraEffect* triggeredByAura, SpellInfo const* procSpell, uint32 procFlag, uint32 procEx);
        bool HandleOverrideClassScriptAuraProc(Unit* victim, uint32 damage, AuraEffect* triggeredByAura, SpellInfo const* procSpell);
        bool HandleAuraRaidProcFromChargeWithValue(AuraEffect* triggeredByAura);
        bool HandleAuraRaidProcFromCharge(AuraEffect* triggeredByAura);

        void UpdateSplineMovement(uint32 t_diff);
        void UpdateSplinePosition();

        // player or player's pet
        float GetCombatRatingReduction(CombatRating cr) const;
        uint32 GetCombatRatingDamageReduction(CombatRating cr, float rate, float cap, uint32 damage) const;

    protected:
        void SetFeared(bool apply);
        void SetConfused(bool apply);
        void SetStunned(bool apply);
        void SetRooted(bool apply, bool packetOnly = false);

        uint32 m_movementCounter;       ///< Incrementing counter used in movement packets

    private:

        uint32 m_state;                                     // Even derived shouldn't modify
        uint32 m_CombatTimer;
        TimeTrackerSmall m_movesplineTimer;

        Diminishing m_Diminishing;
        // Manage all Units that are threatened by us
        HostileRefManager m_HostileRefManager;

        FollowerRefManager m_FollowingRefManager;

        RedirectThreatInfo _redirectThreadInfo;

        bool m_cleanupDone; // lock made to not add stuff after cleanup before delete
        bool m_duringRemoveFromWorld; // lock made to not add stuff after begining removing from world

        uint32 _oldFactionId;           ///< faction before charm
        bool _isWalkingBeforeCharm;     ///< Are we walking before we were charmed?

        uint16 _aiAnimKitId;
        uint16 _movementAnimKitId;
        uint16 _meleeAnimKitId;

        time_t _lastDamagedTime; // Part of Evade mechanics

        SpellHistory* _spellHistory;
};

namespace Trinity
{
    // Binary predicate for sorting Units based on percent value of a power
    class PowerPctOrderPred
    {
        public:
            PowerPctOrderPred(Powers power, bool ascending = true) : _power(power), _ascending(ascending) { }

            bool operator()(WorldObject const* objA, WorldObject const* objB) const
            {
                Unit const* a = objA->ToUnit();
                Unit const* b = objB->ToUnit();
                float rA = (a && a->GetMaxPower(_power)) ? float(a->GetPower(_power)) / float(a->GetMaxPower(_power)) : 0.0f;
                float rB = (b && b->GetMaxPower(_power)) ? float(b->GetPower(_power)) / float(b->GetMaxPower(_power)) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

            bool operator()(Unit const* a, Unit const* b) const
            {
                float rA = a->GetMaxPower(_power) ? float(a->GetPower(_power)) / float(a->GetMaxPower(_power)) : 0.0f;
                float rB = b->GetMaxPower(_power) ? float(b->GetPower(_power)) / float(b->GetMaxPower(_power)) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

        private:
            Powers const _power;
            bool const _ascending;
    };

    // Binary predicate for sorting Units based on percent value of health
    class HealthPctOrderPred
    {
        public:
            HealthPctOrderPred(bool ascending = true) : _ascending(ascending) { }

            bool operator()(WorldObject const* objA, WorldObject const* objB) const
            {
                Unit const* a = objA->ToUnit();
                Unit const* b = objB->ToUnit();
                float rA = (a && a->GetMaxHealth()) ? float(a->GetHealth()) / float(a->GetMaxHealth()) : 0.0f;
                float rB = (b && b->GetMaxHealth()) ? float(b->GetHealth()) / float(b->GetMaxHealth()) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

            bool operator() (Unit const* a, Unit const* b) const
            {
                float rA = a->GetMaxHealth() ? float(a->GetHealth()) / float(a->GetMaxHealth()) : 0.0f;
                float rB = b->GetMaxHealth() ? float(b->GetHealth()) / float(b->GetMaxHealth()) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

        private:
            bool const _ascending;
    };
}
#endif
