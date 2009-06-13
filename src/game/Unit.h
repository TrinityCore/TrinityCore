/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
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

#ifndef __UNIT_H
#define __UNIT_H

#include "Common.h"
#include "Object.h"
#include "Opcodes.h"
#include "SpellAuraDefines.h"
#include "UpdateFields.h"
#include "SharedDefines.h"
#include "ThreatManager.h"
#include "HostilRefManager.h"
#include "FollowerReference.h"
#include "FollowerRefManager.h"
#include "Utilities/EventProcessor.h"
#include "MotionMaster.h"
#include "DBCStructure.h"
#include <list>

#define WORLD_TRIGGER   12999

enum SpellInterruptFlags
{
    SPELL_INTERRUPT_FLAG_MOVEMENT     = 0x01, // why need this for instant?
    SPELL_INTERRUPT_FLAG_PUSH_BACK    = 0x02, // push back
    SPELL_INTERRUPT_FLAG_INTERRUPT    = 0x04, // interrupt
    SPELL_INTERRUPT_FLAG_AUTOATTACK   = 0x08, // no
    SPELL_INTERRUPT_FLAG_ABORT_ON_DMG = 0x10,               // _complete_ interrupt on direct damage
    //SPELL_INTERRUPT_UNK             = 0x20                // unk, 564 of 727 spells having this spell start with "Glyph"
};

enum SpellChannelInterruptFlags
{
    CHANNEL_FLAG_DAMAGE      = 0x0002,
    CHANNEL_FLAG_MOVEMENT    = 0x0008,
    CHANNEL_FLAG_TURNING     = 0x0010,
    CHANNEL_FLAG_DAMAGE2     = 0x0080,
    CHANNEL_FLAG_DELAY       = 0x4000
};

enum SpellAuraInterruptFlags
{
    AURA_INTERRUPT_FLAG_HITBYSPELL          = 0x00000001,   // 0    removed when getting hit by a negative spell?
    AURA_INTERRUPT_FLAG_TAKE_DAMAGE         = 0x00000002,   // 1    removed by any damage
    AURA_INTERRUPT_FLAG_CAST                = 0x00000004,   // 2    cast any spells
    AURA_INTERRUPT_FLAG_MOVE                = 0x00000008,   // 3    removed by any movement
    AURA_INTERRUPT_FLAG_TURNING             = 0x00000010,   // 4    removed by any turning
    AURA_INTERRUPT_FLAG_JUMP                = 0x00000020,   // 5    removed by entering combat
    AURA_INTERRUPT_FLAG_NOT_MOUNTED         = 0x00000040,   // 6    removed by unmounting
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
    AURA_INTERRUPT_FLAG_NOT_SEATED          = 0x00040000,   // 18   removed by standing up
    AURA_INTERRUPT_FLAG_CHANGE_MAP          = 0x00080000,   // 19   leaving map/getting teleported
    AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION    = 0x00100000,   // 20   removed by auras that make you invulnerable, or make other to loose selection on you
    AURA_INTERRUPT_FLAG_UNK21               = 0x00200000,   // 21
    AURA_INTERRUPT_FLAG_TELEPORTED          = 0x00400000,   // 22
    AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT    = 0x00800000,   // 23   removed by entering pvp combat
    AURA_INTERRUPT_FLAG_DIRECT_DAMAGE       = 0x01000000,   // 24   removed by any direct damage

    AURA_INTERRUPT_FLAG_NOT_VICTIM = (AURA_INTERRUPT_FLAG_HITBYSPELL | AURA_INTERRUPT_FLAG_TAKE_DAMAGE | AURA_INTERRUPT_FLAG_DIRECT_DAMAGE),
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
    SPELLMOD_COST                   = 14,
    SPELLMOD_CRIT_DAMAGE_BONUS      = 15,
    SPELLMOD_RESIST_MISS_CHANCE     = 16,
    SPELLMOD_JUMP_TARGETS           = 17,
    SPELLMOD_CHANCE_OF_SUCCESS      = 18,
    SPELLMOD_ACTIVATION_TIME        = 19,
    SPELLMOD_EFFECT_PAST_FIRST      = 20,
    SPELLMOD_GLOBAL_COOLDOWN        = 21, //TODO: GCD is not checked by server currently
    SPELLMOD_DOT                    = 22,
    SPELLMOD_EFFECT3                = 23,
    SPELLMOD_SPELL_BONUS_DAMAGE     = 24,
    // spellmod 25
    SPELLMOD_PROC_PER_MINUTE        = 26,
    SPELLMOD_MULTIPLE_VALUE         = 27,
    SPELLMOD_RESIST_DISPEL_CHANCE   = 28,
    SPELLMOD_CRIT_DAMAGE_BONUS_2    = 29, //one not used spell
    SPELLMOD_SPELL_COST_REFUND_ON_FAIL = 30
};

#define MAX_SPELLMOD 32

enum SpellValueMod
{
    SPELLVALUE_BASE_POINT0,
    SPELLVALUE_BASE_POINT1,
    SPELLVALUE_BASE_POINT2,
    SPELLVALUE_RADIUS_MOD,
    SPELLVALUE_MAX_TARGETS,
};

typedef std::pair<SpellValueMod, int32>     CustomSpellValueMod;
class CustomSpellValues : public std::vector<CustomSpellValueMod>
{
    public:
        void AddSpellMod(SpellValueMod mod, int32 value)
        {
            push_back(std::make_pair(mod, value));
        }
};

enum SpellFacingFlags
{
    SPELL_FACING_FLAG_INFRONT = 0x0001
};

#define BASE_MINDAMAGE 1.0f
#define BASE_MAXDAMAGE 2.0f
#define BASE_ATTACK_TIME 2000

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

// byte flag value (UNIT_FIELD_BYTES_1,2)
enum UnitStandFlags
{
    UNIT_STAND_FLAGS_CREEP        = 0x02,
    UNIT_STAND_FLAGS_ALL          = 0xFF
};

// byte flags value (UNIT_FIELD_BYTES_1,3)
enum UnitBytes1_Flags
{
    UNIT_BYTE1_FLAG_ALWAYS_STAND = 0x01,
    UNIT_BYTE1_FLAG_UNTRACKABLE  = 0x04,
    UNIT_BYTE1_FLAG_ALL          = 0xFF
};

// high byte (3 from 0..3) of UNIT_FIELD_BYTES_2
enum ShapeshiftForm
{
    FORM_NONE               = 0x00,
    FORM_CAT                = 0x01,
    FORM_TREE               = 0x02,
    FORM_TRAVEL             = 0x03,
    FORM_AQUA               = 0x04,
    FORM_BEAR               = 0x05,
    FORM_AMBIENT            = 0x06,
    FORM_GHOUL              = 0x07,
    FORM_DIREBEAR           = 0x08,
    FORM_CREATUREBEAR       = 0x0E,
    FORM_CREATURECAT        = 0x0F,
    FORM_GHOSTWOLF          = 0x10,
    FORM_BATTLESTANCE       = 0x11,
    FORM_DEFENSIVESTANCE    = 0x12,
    FORM_BERSERKERSTANCE    = 0x13,
    FORM_TEST               = 0x14,
    FORM_ZOMBIE             = 0x15,
    FORM_METAMORPHOSIS      = 0x16,
    FORM_FLIGHT_EPIC        = 0x1B,
    FORM_SHADOW             = 0x1C,
    FORM_FLIGHT             = 0x1D,
    FORM_STEALTH            = 0x1E,
    FORM_MOONKIN            = 0x1F,
    FORM_SPIRITOFREDEMPTION = 0x20
};

// low byte ( 0 from 0..3 ) of UNIT_FIELD_BYTES_2
enum SheathState
{
    SHEATH_STATE_UNARMED  = 0,                              // non prepared weapon
    SHEATH_STATE_MELEE    = 1,                              // prepared melee weapon
    SHEATH_STATE_RANGED   = 2                               // prepared ranged weapon
};

#define MAX_SHEATH_STATE    3

// byte (1 from 0..3) of UNIT_FIELD_BYTES_2
enum UnitBytes2_Flags
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
    UNIT_RENAME_NOT_ALLOWED = 0x02,
    UNIT_RENAME_ALLOWED     = 0x03
};

#define CREATURE_MAX_SPELLS     8
#define MAX_SPELL_CHARM         4
#define MAX_SPELL_VEHICLE       6
#define MAX_SPELL_POSSESS       8
#define MAX_SPELL_CONTROL_BAR   10

enum Swing
{
    NOSWING                    = 0,
    SINGLEHANDEDSWING          = 1,
    TWOHANDEDSWING             = 2
};

enum VictimState
{
    VICTIMSTATE_UNKNOWN1       = 0,
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
    HITINFO_UNK1                = 0x00000001,               // req correct packet structure
    HITINFO_NORMALSWING2        = 0x00000002,
    HITINFO_LEFTSWING           = 0x00000004,
    HITINFO_UNK2                = 0x00000008,
    HITINFO_MISS                = 0x00000010,
    HITINFO_ABSORB              = 0x00000020,               // absorbed damage
    HITINFO_ABSORB2             = 0x00000040,               // absorbed damage
    HITINFO_RESIST              = 0x00000080,               // resisted atleast some damage
    HITINFO_RESIST2             = 0x00000100,               // resisted atleast some damage
    HITINFO_CRITICALHIT         = 0x00000200,               // critical hit
    // 0x00000400
    // 0x00000800
    // 0x00001000
    HITINFO_BLOCK               = 0x00002000,               // blocked damage
    // 0x00004000
    // 0x00008000
    HITINFO_GLANCING            = 0x00010000,
    HITINFO_CRUSHING            = 0x00020000,
    HITINFO_NOACTION            = 0x00040000,               // guessed
    // 0x00080000
    // 0x00100000
    HITINFO_SWINGNOHITSOUND     = 0x00200000,               // guessed
    // 0x00400000
    HITINFO_UNK3                = 0x00800000
};

//i would like to remove this: (it is defined in item.h
enum InventorySlot
{
    NULL_BAG                   = 0,
    NULL_SLOT                  = 255
};

struct FactionTemplateEntry;
struct SpellEntry;
struct SpellValue;

class Aura;
class AuraEffect;
class Creature;
class Spell;
class DynamicObject;
class GameObject;
class Item;
class Pet;
class Path;
class PetAura;
class Minion;
class Guardian;
class UnitAI;
class Transport;

struct SpellImmune
{
    uint32 type;
    uint32 spellId;
};

typedef std::list<SpellImmune> SpellImmuneList;

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
    AURA_REMOVE_BY_DEFAULT=0,
    AURA_REMOVE_BY_STACK,               // change stack, single aura remove,
    AURA_REMOVE_BY_CANCEL,
    AURA_REMOVE_BY_ENEMY_SPELL,              // dispel and absorb aura destroy
    AURA_REMOVE_BY_EXPIRE,              // dispel and absorb aura destroy
    AURA_REMOVE_BY_DEATH
};

enum UnitMods
{
    UNIT_MOD_STAT_STRENGTH,                                 // UNIT_MOD_STAT_STRENGTH..UNIT_MOD_STAT_SPIRIT must be in existed order, it's accessed by index values of Stats enum.
    UNIT_MOD_STAT_AGILITY,
    UNIT_MOD_STAT_STAMINA,
    UNIT_MOD_STAT_INTELLECT,
    UNIT_MOD_STAT_SPIRIT,
    UNIT_MOD_HEALTH,
    UNIT_MOD_MANA,                                          // UNIT_MOD_MANA..UNIT_MOD_RUNIC_POWER must be in existed order, it's accessed by index values of Powers enum.
    UNIT_MOD_RAGE,
    UNIT_MOD_FOCUS,
    UNIT_MOD_ENERGY,
    UNIT_MOD_HAPPINESS,
    UNIT_MOD_RUNE,
    UNIT_MOD_RUNIC_POWER,
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
    UNIT_MOD_STAT_END = UNIT_MOD_STAT_SPIRIT + 1,
    UNIT_MOD_RESISTANCE_START = UNIT_MOD_ARMOR,
    UNIT_MOD_RESISTANCE_END = UNIT_MOD_RESISTANCE_ARCANE + 1,
    UNIT_MOD_POWER_START = UNIT_MOD_MANA,
    UNIT_MOD_POWER_END = UNIT_MOD_RUNIC_POWER + 1
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
    ALIVE       = 0,
    JUST_DIED   = 1,
    CORPSE      = 2,
    DEAD        = 3,
    JUST_ALIVED = 4,
    DEAD_FALLING= 5
};

enum UnitState
{
    UNIT_STAT_DIED            = 0x00000001,
    UNIT_STAT_MELEE_ATTACKING = 0x00000002,                     // player is melee attacking someone
    //UNIT_STAT_MELEE_ATTACK_BY = 0x00000004,                     // player is melee attack by someone
    UNIT_STAT_STUNNED         = 0x00000008,
    UNIT_STAT_ROAMING         = 0x00000010,
    UNIT_STAT_CHASE           = 0x00000020,
    //UNIT_STAT_SEARCHING       = 0x00000040,
    UNIT_STAT_FLEEING         = 0x00000080,
    UNIT_STAT_IN_FLIGHT       = 0x00000100,                     // player is in flight mode
    UNIT_STAT_FOLLOW          = 0x00000200,
    UNIT_STAT_ROOT            = 0x00000400,
    UNIT_STAT_CONFUSED        = 0x00000800,
    UNIT_STAT_DISTRACTED      = 0x00001000,
    UNIT_STAT_ISOLATED        = 0x00002000,                     // area auras do not affect other players
    UNIT_STAT_ATTACK_PLAYER   = 0x00004000,
    UNIT_STAT_CASTING         = 0x00008000,
    UNIT_STAT_POSSESSED       = 0x00010000,
    UNIT_STAT_CHARGING        = 0x00020000,
    UNIT_STAT_JUMPING         = 0x00040000,
    UNIT_STAT_ONVEHICLE       = 0x00080000,
    UNIT_STAT_MOVE            = 0x00100000,
    //UNIT_STAT_WALK            = 0x00200000,
    UNIT_STAT_UNATTACKABLE    = (UNIT_STAT_IN_FLIGHT | UNIT_STAT_ONVEHICLE),
    UNIT_STAT_MOVING          = (UNIT_STAT_ROAMING | UNIT_STAT_CHASE),
    UNIT_STAT_CONTROLLED      = (UNIT_STAT_CONFUSED | UNIT_STAT_STUNNED | UNIT_STAT_FLEEING),
    UNIT_STAT_LOST_CONTROL    = (UNIT_STAT_CONTROLLED | UNIT_STAT_JUMPING | UNIT_STAT_CHARGING),
    UNIT_STAT_SIGHTLESS       = (UNIT_STAT_LOST_CONTROL),
    UNIT_STAT_CANNOT_AUTOATTACK     = (UNIT_STAT_LOST_CONTROL | UNIT_STAT_CASTING),
    UNIT_STAT_ALL_STATE       = 0xffffffff                      //(UNIT_STAT_STOPPED | UNIT_STAT_MOVING | UNIT_STAT_IN_COMBAT | UNIT_STAT_IN_FLIGHT)
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

extern float baseMoveSpeed[MAX_MOVE_TYPE];

enum WeaponAttackType
{
    BASE_ATTACK   = 0,
    OFF_ATTACK    = 1,
    RANGED_ATTACK = 2,
    MAX_ATTACK
};

enum CombatRating
{
    CR_WEAPON_SKILL             = 0,
    CR_DEFENSE_SKILL            = 1,
    CR_DODGE                    = 2,
    CR_PARRY                    = 3,
    CR_BLOCK                    = 4,
    CR_HIT_MELEE                = 5,
    CR_HIT_RANGED               = 6,
    CR_HIT_SPELL                = 7,
    CR_CRIT_MELEE               = 8,
    CR_CRIT_RANGED              = 9,
    CR_CRIT_SPELL               = 10,
    CR_HIT_TAKEN_MELEE          = 11,
    CR_HIT_TAKEN_RANGED         = 12,
    CR_HIT_TAKEN_SPELL          = 13,
    CR_CRIT_TAKEN_MELEE         = 14,
    CR_CRIT_TAKEN_RANGED        = 15,
    CR_CRIT_TAKEN_SPELL         = 16,
    CR_HASTE_MELEE              = 17,
    CR_HASTE_RANGED             = 18,
    CR_HASTE_SPELL              = 19,
    CR_WEAPON_SKILL_MAINHAND    = 20,
    CR_WEAPON_SKILL_OFFHAND     = 21,
    CR_WEAPON_SKILL_RANGED      = 22,
    CR_EXPERTISE                = 23,
    CR_ARMOR_PENETRATION        = 24
};

#define MAX_COMBAT_RATING         25

enum DamageEffectType
{
    DIRECT_DAMAGE           = 0,                            // used for normal weapon damage (not for class abilities or spells)
    SPELL_DIRECT_DAMAGE     = 1,                            // spell/class abilities damage
    DOT                     = 2,
    HEAL                    = 3,
    NODAMAGE                = 4,                            // used also in case when damage applied to health but not applied to spell channelInterruptFlags/etc
    SELF_DAMAGE             = 5
};

enum UnitVisibility
{
    VISIBILITY_OFF                = 0,                      // absolute, not detectable, GM-like, can see all other
    VISIBILITY_ON                 = 1,
    VISIBILITY_GROUP_STEALTH      = 2,                      // detect chance, seen and can see group members
    //VISIBILITY_GROUP_INVISIBILITY = 3,                      // invisibility, can see and can be seen only another invisible unit or invisible detection unit, set only if not stealthed, and in checks not used (mask used instead)
    //VISIBILITY_GROUP_NO_DETECT    = 4,                      // state just at stealth apply for update Grid state. Don't remove, otherwise stealth spells will break
    VISIBILITY_RESPAWN            = 5                       // special totally not detectable visibility for force delete object at respawn command
};

// Value masks for UNIT_FIELD_FLAGS
enum UnitFlags
{
    UNIT_FLAG_UNK_0            = 0x00000001,
    UNIT_FLAG_NON_ATTACKABLE   = 0x00000002,                // not attackable
    UNIT_FLAG_DISABLE_MOVE     = 0x00000004,
    UNIT_FLAG_PVP_ATTACKABLE   = 0x00000008,                // allow apply pvp rules to attackable state in addition to faction dependent state
    UNIT_FLAG_RENAME           = 0x00000010,
    UNIT_FLAG_PREPARATION      = 0x00000020,                // don't take reagents for spells with SPELL_ATTR_EX5_NO_REAGENT_WHILE_PREP
    UNIT_FLAG_UNK_6            = 0x00000040,
    UNIT_FLAG_NOT_ATTACKABLE_1 = 0x00000080,                // ?? (UNIT_FLAG_PVP_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE
    UNIT_FLAG_NOT_ATTACKABLE_2 = 0x00000100,                // 2.0.8
    UNIT_FLAG_UNK_9            = 0x00000200,                // 3.0.3 - makes you unable to attack everything
    UNIT_FLAG_LOOTING          = 0x00000400,                // loot animation
    UNIT_FLAG_PET_IN_COMBAT    = 0x00000800,                // in combat?, 2.0.8
    UNIT_FLAG_PVP              = 0x00001000,                // changed in 3.0.3
    UNIT_FLAG_SILENCED         = 0x00002000,                // silenced, 2.1.1
    UNIT_FLAG_UNK_14           = 0x00004000,                // 2.0.8
    UNIT_FLAG_UNK_15           = 0x00008000,
    UNIT_FLAG_UNK_16           = 0x00010000,
    UNIT_FLAG_PACIFIED         = 0x00020000,                // 3.0.3 ok
    UNIT_FLAG_STUNNED          = 0x00040000,                // 3.0.3 ok
    UNIT_FLAG_IN_COMBAT        = 0x00080000,
    UNIT_FLAG_TAXI_FLIGHT      = 0x00100000,                // disable casting at client side spell not allowed by taxi flight (mounted?), probably used with 0x4 flag
    UNIT_FLAG_DISARMED         = 0x00200000,                // 3.0.3, disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.
    UNIT_FLAG_CONFUSED         = 0x00400000,
    UNIT_FLAG_FLEEING          = 0x00800000,
    UNIT_FLAG_UNK_24           = 0x01000000,                // used in spell Eyes of the Beast for pet...
    UNIT_FLAG_NOT_SELECTABLE   = 0x02000000,
    UNIT_FLAG_SKINNABLE        = 0x04000000,
    UNIT_FLAG_MOUNT            = 0x08000000,
    UNIT_FLAG_UNK_28           = 0x10000000,
    UNIT_FLAG_UNK_29           = 0x20000000,                // used in Feing Death spell
    UNIT_FLAG_SHEATHE          = 0x40000000,
    UNIT_FLAG_UNK_31           = 0x80000000
};

// Value masks for UNIT_FIELD_FLAGS_2
enum UnitFlags2
{
    UNIT_FLAG2_FEIGN_DEATH      = 0x00000001,
    UNIT_FLAG2_UNK1             = 0x00000002,               // Hide unit model (show only player equip)
    UNIT_FLAG2_COMPREHEND_LANG  = 0x00000008,
    UNIT_FLAG2_FORCE_MOVE       = 0x00000040,
    UNIT_FLAG2_DISARM_OFFHAND   = 0x00000080,
    UNIT_FLAG2_DISARM_RANGED    = 0x00000400,               //this does not disable ranged weapon display (maybe additional flag needed?)
    UNIT_FLAG2_REGENERATE_POWER = 0x00000800
};

/// Non Player Character flags
enum NPCFlags
{
    UNIT_NPC_FLAG_NONE                  = 0x00000000,
    UNIT_NPC_FLAG_GOSSIP                = 0x00000001,       // 100%
    UNIT_NPC_FLAG_QUESTGIVER            = 0x00000002,       // guessed, probably ok
    UNIT_NPC_FLAG_UNK1                  = 0x00000004,
    UNIT_NPC_FLAG_UNK2                  = 0x00000008,
    UNIT_NPC_FLAG_TRAINER               = 0x00000010,       // 100%
    UNIT_NPC_FLAG_TRAINER_CLASS         = 0x00000020,       // 100%
    UNIT_NPC_FLAG_TRAINER_PROFESSION    = 0x00000040,       // 100%
    UNIT_NPC_FLAG_VENDOR                = 0x00000080,       // 100%
    UNIT_NPC_FLAG_VENDOR_AMMO           = 0x00000100,       // 100%, general goods vendor
    UNIT_NPC_FLAG_VENDOR_FOOD           = 0x00000200,       // 100%
    UNIT_NPC_FLAG_VENDOR_POISON         = 0x00000400,       // guessed
    UNIT_NPC_FLAG_VENDOR_REAGENT        = 0x00000800,       // 100%
    UNIT_NPC_FLAG_REPAIR                = 0x00001000,       // 100%
    UNIT_NPC_FLAG_FLIGHTMASTER          = 0x00002000,       // 100%
    UNIT_NPC_FLAG_SPIRITHEALER          = 0x00004000,       // guessed
    UNIT_NPC_FLAG_SPIRITGUIDE           = 0x00008000,       // guessed
    UNIT_NPC_FLAG_INNKEEPER             = 0x00010000,       // 100%
    UNIT_NPC_FLAG_BANKER                = 0x00020000,       // 100%
    UNIT_NPC_FLAG_PETITIONER            = 0x00040000,       // 100% 0xC0000 = guild petitions, 0x40000 = arena team petitions
    UNIT_NPC_FLAG_TABARDDESIGNER        = 0x00080000,       // 100%
    UNIT_NPC_FLAG_BATTLEMASTER          = 0x00100000,       // 100%
    UNIT_NPC_FLAG_AUCTIONEER            = 0x00200000,       // 100%
    UNIT_NPC_FLAG_STABLEMASTER          = 0x00400000,       // 100%
    UNIT_NPC_FLAG_GUILD_BANKER          = 0x00800000,       // cause client to send 997 opcode
    UNIT_NPC_FLAG_SPELLCLICK            = 0x01000000,       // cause client to send 1015 opcode (spell click)
    UNIT_NPC_FLAG_GUARD                 = 0x10000000,       // custom flag for guards
    UNIT_NPC_FLAG_OUTDOORPVP            = 0x20000000,       // custom flag for outdoor pvp creatures
};

enum MoveFlags
{
    MOVEFLAG_JUMP               = 0x00000800,
    MOVEFLAG_WALK               = 0x00001000,
    MOVEFLAG_FLY                = 0x00002000,
    MOVEFLAG_GLIDE              = 0x00003000, // dragon
    MOVEFLAG_ENTER_TRANSPORT    = 0x00800000,
};

enum MovementFlags
{
    MOVEMENTFLAG_NONE           = 0x00000000,
    MOVEMENTFLAG_FORWARD        = 0x00000001,
    MOVEMENTFLAG_BACKWARD       = 0x00000002,
    MOVEMENTFLAG_STRAFE_LEFT    = 0x00000004,
    MOVEMENTFLAG_STRAFE_RIGHT   = 0x00000008,
    MOVEMENTFLAG_LEFT           = 0x00000010,
    MOVEMENTFLAG_RIGHT          = 0x00000020,
    MOVEMENTFLAG_PITCH_UP       = 0x00000040,
    MOVEMENTFLAG_PITCH_DOWN     = 0x00000080,
    MOVEMENTFLAG_WALK_MODE      = 0x00000100,               // Walking
    MOVEMENTFLAG_ONTRANSPORT    = 0x00000200,               // Used for flying on some creatures
    MOVEMENTFLAG_LEVITATING     = 0x00000400,
    MOVEMENTFLAG_FLY_UNK1       = 0x00000800,
    MOVEMENTFLAG_JUMPING        = 0x00001000,
    MOVEMENTFLAG_UNK4           = 0x00002000,
    MOVEMENTFLAG_FALLING        = 0x00004000,
    // 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000
    MOVEMENTFLAG_SWIMMING       = 0x00200000,               // appears with fly flag also
    MOVEMENTFLAG_FLY_UP         = 0x00400000,               // press "space" when flying
    MOVEMENTFLAG_CAN_FLY        = 0x00800000,
    MOVEMENTFLAG_FLYING         = 0x01000000,               // fly land
    MOVEMENTFLAG_FLYING2        = 0x02000000,               // fly hover
    MOVEMENTFLAG_SPLINE         = 0x04000000,               // used for flight paths
    MOVEMENTFLAG_SPLINE2        = 0x08000000,               // used for flight paths
    MOVEMENTFLAG_WATERWALKING   = 0x10000000,               // prevent unit from falling through water
    MOVEMENTFLAG_SAFE_FALL      = 0x20000000,               // active rogue safe fall spell (passive)
    MOVEMENTFLAG_UNK3           = 0x40000000
};

/*
enum MonsterMovementFlags
{
    MONSTER_MOVE_NONE           = 0x00000000,
    MONSTER_MOVE_FORWARD        = 0x00000001,
    MONSTER_MOVE_BACKWARD       = 0x00000002,
    MONSTER_MOVE_STRAFE_LEFT    = 0x00000004,
    MONSTER_MOVE_STRAFE_RIGHT   = 0x00000008,
    MONSTER_MOVE_LEFT           = 0x00000010,               // turn
    MONSTER_MOVE_RIGHT          = 0x00000020,               // turn
    MONSTER_MOVE_PITCH_UP       = 0x00000040,
    MONSTER_MOVE_PITCH_DOWN     = 0x00000080,
    MONSTER_MOVE_TELEPORT       = 0x00000100,
    MONSTER_MOVE_TELEPORT2      = 0x00000200,
    MONSTER_MOVE_LEVITATING     = 0x00000400,
    MONSTER_MOVE_UNK1           = 0x00000800,               // float+uint32
    MONSTER_MOVE_WALK           = 0x00001000,               // run2?
    MONSTER_MOVE_SPLINE         = 0x00002000,               // spline n*(float x,y,z)
    // 0x4000, 0x8000, 0x10000, 0x20000 run
    MONSTER_MOVE_SPLINE2        = 0x00040000,               // spline n*(float x,y,z)
    MONSTER_MOVE_UNK2           = 0x00080000,               // used for flying mobs
    MONSTER_MOVE_UNK3           = 0x00100000,               // used for flying mobs
    MONSTER_MOVE_UNK4           = 0x00200000,               // uint8+uint32
    MONSTER_MOVE_UNK5           = 0x00400000,               // run in place, then teleport to final point
    MONSTER_MOVE_UNK6           = 0x00800000,               // teleport
    MONSTER_MOVE_UNK7           = 0x01000000,               // run
    MONSTER_MOVE_FLY            = 0x02000000,               // swimming/flying (depends on mob?)
    MONSTER_MOVE_UNK9           = 0x04000000,               // run
    MONSTER_MOVE_UNK10          = 0x08000000,               // run
    MONSTER_MOVE_UNK11          = 0x10000000,               // run
    MONSTER_MOVE_UNK12          = 0x20000000,               // run
    MONSTER_MOVE_UNK13          = 0x40000000,               // levitating

    // masks
    MONSTER_MOVE_SPLINE_FLY     = 0x00003000,               // fly by points
};
*/

struct MovementInfo
{
    // common
    uint32  flags;
    uint16  unk1;
    uint32  time;
    float   x, y, z, o;
    // transport
    uint64  t_guid;
    float   t_x, t_y, t_z, t_o;
    uint32  t_time;
    int8    t_seat;
    // swimming and unknown
    float   s_pitch;
    // last fall time
    uint32  fallTime;
    // jumping
    float   j_zspeed, j_sinAngle, j_cosAngle, j_xyspeed;
    // spline
    float   u_unk1;

    MovementInfo()
    {
        flags = 0;
        time = t_time = fallTime = 0;
        unk1 = 0;
        x = y = z = o = t_x = t_y = t_z = t_o = s_pitch = j_zspeed = j_sinAngle = j_cosAngle = j_xyspeed = u_unk1 = 0.0f;
        t_guid = 0;
    }

    uint32 GetMovementFlags() { return flags; }
    void AddMovementFlag(uint32 flag) { flags |= flag; }
    bool HasMovementFlag(uint32 flag) const { return flags & flag; }
};

enum DiminishingLevels
{
    DIMINISHING_LEVEL_1             = 0,
    DIMINISHING_LEVEL_2             = 1,
    DIMINISHING_LEVEL_3             = 2,
    DIMINISHING_LEVEL_IMMUNE        = 3
};

struct DiminishingReturn
{
    DiminishingReturn(DiminishingGroup group, uint32 t, uint32 count)
        : DRGroup(group), stack(0), hitTime(t), hitCount(count)
    {}

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

struct CleanDamage
{
    CleanDamage(uint32 _damage, WeaponAttackType _attackType, MeleeHitOutcome _hitOutCome) :
    damage(_damage), attackType(_attackType), hitOutCome(_hitOutCome) {}

    uint32 damage;
    WeaponAttackType attackType;
    MeleeHitOutcome hitOutCome;
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
    MeleeHitOutcome hitOutCome;  // TODO: remove this field (need use TargetState)
};

// Spell damage info structure based on structure sending in SMSG_SPELLNONMELEEDAMAGELOG opcode
struct SpellNonMeleeDamage{
    SpellNonMeleeDamage(Unit *_attacker, Unit *_target, uint32 _SpellID, uint32 _schoolMask)
        : target(_target), attacker(_attacker), SpellID(_SpellID), damage(0), overkill(0), schoolMask(_schoolMask),
        absorb(0), resist(0), physicalLog(false), unused(false), blocked(0), HitInfo(0), cleanDamage(0)
    {}

    Unit   *target;
    Unit   *attacker;
    uint32 SpellID;
    uint32 damage;
    uint32 overkill;
    uint32 schoolMask;
    uint32 absorb;
    uint32 resist;
    bool   physicalLog;
    bool   unused;
    uint32 blocked;
    uint32 HitInfo;
    // Used for help
    uint32 cleanDamage;
};

struct SpellPeriodicAuraLogInfo
{
    SpellPeriodicAuraLogInfo(AuraEffect *_auraEff, uint32 _damage, uint32 _overDamage, uint32 _absorb, uint32 _resist, float _multiplier)
        : auraEff(_auraEff), damage(_damage), overDamage(_overDamage), absorb(_absorb), resist(_resist), multiplier(_multiplier) {}

    AuraEffect *auraEff;
    uint32 damage;
    uint32 absorb;
    uint32 resist;
    uint32 overDamage;                                      // overkill/overheal
    float  multiplier;
};

uint32 createProcExtendMask(SpellNonMeleeDamage *damageInfo, SpellMissInfo missCondition);

#define MAX_DECLINED_NAME_CASES 5

struct DeclinedName
{
    std::string name[MAX_DECLINED_NAME_CASES];
};

enum CurrentSpellTypes
{
    CURRENT_MELEE_SPELL = 0,
    CURRENT_FIRST_NON_MELEE_SPELL = 1,                      // just counter
    CURRENT_GENERIC_SPELL = 1,
    CURRENT_AUTOREPEAT_SPELL = 2,
    CURRENT_CHANNELED_SPELL = 3,
    CURRENT_MAX_SPELL = 4                                   // just counter
};

enum ActiveStates
{
    ACT_PASSIVE  = 0x0100,                                  // 0x0100 - passive
    ACT_DISABLED = 0x8100,                                  // 0x8000 - castable
    ACT_ENABLED  = 0xC100,                                  // 0x4000 | 0x8000 - auto cast + castable
    ACT_COMMAND  = 0x0700,                                  // 0x0100 | 0x0200 | 0x0400
    ACT_REACTION = 0x0600,                                  // 0x0200 | 0x0400
    ACT_DECIDE   = 0x0001                                   // what is it?
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
    COMMAND_ABANDON = 3
};

struct UnitActionBarEntry
{
    UnitActionBarEntry() : SpellOrAction(0), Type(ACT_DISABLED) {}

    uint16 SpellOrAction;
    uint16 Type;

    // helper
    bool IsActionBarForSpell() const
    {
        return Type == ACT_DISABLED || Type == ACT_ENABLED || Type == ACT_PASSIVE;
    }
};

struct CharmSpellEntry
{
    uint16 spellId;
    uint16 active;
};

typedef std::list<Player*> SharedVisionList;

enum CharmType
{
    CHARM_TYPE_CHARM,
    CHARM_TYPE_POSSESS,
    CHARM_TYPE_VEHICLE,
    CHARM_TYPE_CONVERT,
};

enum ActionBarIndex
{
    ACTION_BAR_INDEX_START = 0,
    ACTION_BAR_INDEX_PET_SPELL_START = 3,
    ACTION_BAR_INDEX_PET_SPELL_END = 7,
    ACTION_BAR_INDEX_END = 10,
};

#define MAX_UNIT_ACTION_BAR_INDEX (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START)

struct CharmInfo
{
    public:
        explicit CharmInfo(Unit* unit);
        ~CharmInfo();
        uint32 GetPetNumber() const { return m_petnumber; }
        void SetPetNumber(uint32 petnumber, bool statwindow);

        void SetCommandState(CommandStates st) { m_CommandState = st; }
        CommandStates GetCommandState() { return m_CommandState; }
        bool HasCommandState(CommandStates state) { return (m_CommandState == state); }
        //void SetReactState(ReactStates st) { m_reactState = st; }
        //ReactStates GetReactState() { return m_reactState; }
        //bool HasReactState(ReactStates state) { return (m_reactState == state); }

        void InitPossessCreateSpells();
        void InitCharmCreateSpells();
        void InitPetActionBar();
        void InitEmptyActionBar(bool withAttack = true);

                                                            //return true if successful
        bool AddSpellToActionBar(uint32 spellid, ActiveStates newstate = ACT_DECIDE);
        bool RemoveSpellFromActionBar(uint32 spell_id);
        void LoadPetActionBar(std::string data);
        void BuildActionBar(WorldPacket* data);
        void SetSpellAutocast(uint32 spell_id, bool state);
        void SetActionBar(uint8 index, uint32 spellOrAction,ActiveStates type)
        {
            PetActionBar[index].Type = type;
            PetActionBar[index].SpellOrAction = spellOrAction;
        }
        UnitActionBarEntry const* GetActionBarEntry(uint8 index) const { return &(PetActionBar[index]); }

        void ToggleCreatureAutocast(uint32 spellid, bool apply);

        CharmSpellEntry* GetCharmSpell(uint8 index) { return &(m_charmspells[index]); }
    private:

        Unit* m_unit;
        UnitActionBarEntry PetActionBar[MAX_UNIT_ACTION_BAR_INDEX];
        CharmSpellEntry m_charmspells[4];
        CommandStates   m_CommandState;
        //ReactStates     m_reactState;
        uint32          m_petnumber;
        bool            m_barInit;

        //for restoration after charmed
        ReactStates     m_oldReactState;
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

// delay time next attack to prevent client attack animation problems
#define ATTACK_DISPLAY_DELAY 200

struct SpellProcEventEntry;                                 // used only privately

class TRINITY_DLL_SPEC Unit : public WorldObject
{
    public:
        typedef std::set<Unit*> AttackerSet;
        typedef std::set<Unit*> ControlList;
        typedef std::pair<uint32, uint8> spellEffectPair;
        typedef std::multimap<uint32,  Aura*> AuraMap;
        typedef std::list<AuraEffect *> AuraEffectList;
        typedef std::list<Aura *> AuraList;
        typedef std::list<DiminishingReturn> Diminishing;
        typedef std::set<uint32> ComboPointHolderSet;

        typedef std::map<uint8, Aura*> VisibleAuraMap;

        virtual ~Unit ( );

        void AddToWorld();
        void RemoveFromWorld();

        void CleanupsBeforeDelete();                        // used in ~Creature/~Player (or before mass creature delete to remove cross-references to already deleted units)

        DiminishingLevels GetDiminishing(DiminishingGroup  group);
        void IncrDiminishing(DiminishingGroup group);
        void ApplyDiminishingToDuration(DiminishingGroup  group, int32 &duration,Unit* caster, DiminishingLevels Level);
        void ApplyDiminishingAura(DiminishingGroup  group, bool apply);
        void ClearDiminishings() { m_Diminishing.clear(); }

        //target dependent range checks
        uint32 GetSpellMaxRangeForTarget(Unit* target,const SpellRangeEntry * rangeEntry);
        uint32 GetSpellMinRangeForTarget(Unit* target,const SpellRangeEntry * rangeEntry);
        uint32 GetSpellRadiusForTarget(Unit* target,const SpellRadiusEntry * radiusEntry);

        virtual void Update( uint32 time );

        void setAttackTimer(WeaponAttackType type, uint32 time) { m_attackTimer[type] = time; }
        void resetAttackTimer(WeaponAttackType type = BASE_ATTACK);
        uint32 getAttackTimer(WeaponAttackType type) const { return m_attackTimer[type]; }
        bool isAttackReady(WeaponAttackType type = BASE_ATTACK) const { return m_attackTimer[type] == 0; }
        bool haveOffhandWeapon() const;
        bool CanDualWield() const { return m_canDualWield; }
        void SetCanDualWield(bool value) { m_canDualWield = value; }
        float GetCombatReach() const { return m_floatValues[UNIT_FIELD_COMBATREACH]; }
        float GetMeleeReach() const { float reach = m_floatValues[UNIT_FIELD_COMBATREACH]; return reach > MIN_MELEE_REACH ? reach : MIN_MELEE_REACH; }
        bool IsWithinCombatRange(const Unit *obj, float dist2compare) const;
        bool IsWithinMeleeRange(const Unit *obj, float dist = MELEE_RANGE) const;
        void GetRandomContactPoint( const Unit* target, float &x, float &y, float &z, float distance2dMin, float distance2dMax ) const;
        uint32 m_extraAttacks;
        bool m_canDualWield;

        void _addAttacker(Unit *pAttacker)                  // must be called only from Unit::Attack(Unit*)
        {
            m_attackers.insert(pAttacker);
        }
        void _removeAttacker(Unit *pAttacker)               // must be called only from Unit::AttackStop()
        {
            m_attackers.erase(pAttacker);
        }
        Unit * getAttackerForHelper()                       // If someone wants to help, who to give them
        {
            if (getVictim() != NULL)
                return getVictim();

            if (!m_attackers.empty())
                return *(m_attackers.begin());

            return NULL;
        }
        bool Attack(Unit *victim, bool meleeAttack);
        void CastStop(uint32 except_spellid = 0);
        bool AttackStop();
        void RemoveAllAttackers();
        AttackerSet const& getAttackers() const { return m_attackers; }
        bool isAttackingPlayer() const;
        Unit* getVictim() const { return m_attacking; }
        void CombatStop(bool includingCast = false);
        void CombatStopWithPets(bool includingCast = false);
        Unit* SelectNearbyTarget(float dist = NOMINAL_MELEE_RANGE) const;
        bool hasNegativeAuraWithInterruptFlag(uint32 flag);
        void SendMeleeAttackStop(Unit* victim);
        void SendMeleeAttackStart(Unit* pVictim);

        void addUnitState(uint32 f) { m_state |= f; }
        bool hasUnitState(const uint32 f) const { return (m_state & f); }
        void clearUnitState(uint32 f) { m_state &= ~f; }
        bool CanFreeMove() const
        {
            return !hasUnitState(UNIT_STAT_CONFUSED | UNIT_STAT_FLEEING | UNIT_STAT_IN_FLIGHT |
                UNIT_STAT_ROOT | UNIT_STAT_STUNNED | UNIT_STAT_DISTRACTED ) && GetOwnerGUID()==0;
        }

        uint32 getLevel() const { return GetUInt32Value(UNIT_FIELD_LEVEL); }
        virtual uint32 getLevelForTarget(Unit const* /*target*/) const { return getLevel(); }
        void SetLevel(uint32 lvl);
        uint8 getRace() const { return GetByteValue(UNIT_FIELD_BYTES_0, 0); }
        uint32 getRaceMask() const { return 1 << (getRace()-1); }
        uint8 getClass() const { return GetByteValue(UNIT_FIELD_BYTES_0, 1); }
        uint32 getClassMask() const { return 1 << (getClass()-1); }
        uint8 getGender() const { return GetByteValue(UNIT_FIELD_BYTES_0, 2); }

        float GetStat(Stats stat) const { return float(GetUInt32Value(UNIT_FIELD_STAT0+stat)); }
        void SetStat(Stats stat, int32 val) { SetStatInt32Value(UNIT_FIELD_STAT0+stat, val); }
        uint32 GetArmor() const { return GetResistance(SPELL_SCHOOL_NORMAL) ; }
        void SetArmor(int32 val) { SetResistance(SPELL_SCHOOL_NORMAL, val); }

        uint32 GetResistance(SpellSchools school) const { return GetUInt32Value(UNIT_FIELD_RESISTANCES+school); }
        void SetResistance(SpellSchools school, int32 val) { SetStatInt32Value(UNIT_FIELD_RESISTANCES+school,val); }

        uint32 GetHealth()    const { return GetUInt32Value(UNIT_FIELD_HEALTH); }
        uint32 GetMaxHealth() const { return GetUInt32Value(UNIT_FIELD_MAXHEALTH); }
        void SetHealth(   uint32 val);
        void SetMaxHealth(uint32 val);
        int32 ModifyHealth(int32 val);
        int32 GetHealthGain(int32 dVal);

        Powers getPowerType() const { return Powers(GetByteValue(UNIT_FIELD_BYTES_0, 3)); }
        void setPowerType(Powers power);
        uint32 GetPower(   Powers power) const { return GetUInt32Value(UNIT_FIELD_POWER1   +power); }
        uint32 GetMaxPower(Powers power) const { return GetUInt32Value(UNIT_FIELD_MAXPOWER1+power); }
        void SetPower(   Powers power, uint32 val);
        void SetMaxPower(Powers power, uint32 val);
        int32 ModifyPower(Powers power, int32 val);
        void ApplyPowerMod(Powers power, uint32 val, bool apply);
        void ApplyMaxPowerMod(Powers power, uint32 val, bool apply);

        uint32 GetAttackTime(WeaponAttackType att) const
        {
           float f_BaseAttackTime = GetFloatValue(UNIT_FIELD_BASEATTACKTIME+att) / m_modAttackSpeedPct[att];
           return (uint32)f_BaseAttackTime;
        }
            
        void SetAttackTime(WeaponAttackType att, uint32 val) { SetFloatValue(UNIT_FIELD_BASEATTACKTIME+att,val*m_modAttackSpeedPct[att]); }
        void ApplyAttackTimePercentMod(WeaponAttackType att,float val, bool apply);
        void ApplyCastTimePercentMod(float val, bool apply);

        SheathState GetSheath() const { return SheathState(GetByteValue(UNIT_FIELD_BYTES_2, 0)); }
        virtual void SetSheath( SheathState sheathed ) { SetByteValue(UNIT_FIELD_BYTES_2, 0, sheathed); }

        // faction template id
        uint32 getFaction() const { return GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE); }
        void setFaction(uint32 faction) { SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, faction ); }
        FactionTemplateEntry const* getFactionTemplateEntry() const;
        bool IsHostileTo(Unit const* unit) const;
        bool IsHostileToPlayers() const;
        bool IsFriendlyTo(Unit const* unit) const;
        bool IsNeutralToAll() const;
        bool IsInPartyWith(Unit const* unit) const;
        bool IsInRaidWith(Unit const* unit) const;
        void GetPartyMemberInDist(std::list<Unit*> &units, float dist);
        void GetPartyMembers(std::list<Unit*> &units);
        void GetRaidMember(std::list<Unit*> &units, float dist);
        bool IsContestedGuard() const
        {
            if(FactionTemplateEntry const* entry = getFactionTemplateEntry())
                return entry->IsContestedGuardFaction();

            return false;
        }
        bool IsPvP() const { return HasByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP); }
        void SetPvP(bool state)
        {
            if(state)
                SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP);
            else
                RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP);
        }
        uint32 GetCreatureType() const;
        uint32 GetCreatureTypeMask() const
        {
            uint32 creatureType = GetCreatureType();
            return (creatureType >= 1) ? (1 << (creatureType - 1)) : 0;
        }

        uint8 getStandState() const { return GetByteValue(UNIT_FIELD_BYTES_1, 0); }
        bool IsSitState() const;
        bool IsStandState() const;
        void SetStandState(uint8 state);

        void  SetStandFlags(uint8 flags) { SetByteFlag(UNIT_FIELD_BYTES_1, 2,flags); }
        void  RemoveStandFlags(uint8 flags) { RemoveByteFlag(UNIT_FIELD_BYTES_1, 2,flags); }

        bool IsMounted() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT ); }
        uint32 GetMountID() const { return GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID); }
        void Mount(uint32 mount);
        void Unmount();

        uint16 GetMaxSkillValueForLevel(Unit const* target = NULL) const { return (target ? getLevelForTarget(target) : getLevel()) * 5; }
        void RemoveSpellbyDamageTaken(uint32 damage, uint32 spell);
        void DealDamageMods(Unit *pVictim, uint32 &damage, uint32* absorb);
        uint32 DealDamage(Unit *pVictim, uint32 damage, CleanDamage const* cleanDamage = NULL, DamageEffectType damagetype = DIRECT_DAMAGE, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellEntry const *spellProto = NULL, bool durabilityLoss = true);
        void Kill(Unit *pVictim, bool durabilityLoss = true);
        int32 DealHeal(Unit *pVictim, uint32 addhealth, SpellEntry const *spellProto, bool critical = false);

        void ProcDamageAndSpell(Unit *pVictim, uint32 procAttacker, uint32 procVictim, uint32 procEx, uint32 amount, WeaponAttackType attType = BASE_ATTACK, SpellEntry const *procSpell = NULL, SpellEntry const * procAura = NULL);
        void ProcDamageAndSpellFor( bool isVictim, Unit * pTarget, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, SpellEntry const * procSpell, uint32 damage , SpellEntry const * procAura = NULL);

        void HandleEmoteCommand(uint32 anim_id);
        void AttackerStateUpdate (Unit *pVictim, WeaponAttackType attType = BASE_ATTACK, bool extra = false );

        //float MeleeMissChanceCalc(const Unit *pVictim, WeaponAttackType attType) const;

        void CalculateMeleeDamage(Unit *pVictim, uint32 damage, CalcDamageInfo *damageInfo, WeaponAttackType attackType = BASE_ATTACK);
        void DealMeleeDamage(CalcDamageInfo *damageInfo, bool durabilityLoss);

        void CalculateSpellDamageTaken(SpellNonMeleeDamage *damageInfo, int32 damage, SpellEntry const *spellInfo, WeaponAttackType attackType = BASE_ATTACK);
        int32 GetIgnoredArmorMultiplier(SpellEntry const *spellInfo, WeaponAttackType attackType);
        void DealSpellDamage(SpellNonMeleeDamage *damageInfo, bool durabilityLoss);

        float MeleeSpellMissChance(const Unit *pVictim, WeaponAttackType attType, int32 skillDiff, uint32 spellId) const;
        SpellMissInfo MeleeSpellHitResult(Unit *pVictim, SpellEntry const *spell);
        SpellMissInfo MagicSpellHitResult(Unit *pVictim, SpellEntry const *spell);
        SpellMissInfo SpellHitResult(Unit *pVictim, SpellEntry const *spell, bool canReflect = false);

        float GetUnitDodgeChance()    const;
        float GetUnitParryChance()    const;
        float GetUnitBlockChance()    const;
        float GetUnitCriticalChance(WeaponAttackType attackType, const Unit *pVictim) const;
        int32 GetMechanicResistChance(const SpellEntry *spell);
        bool CanUseAttackType( uint8 attacktype ) const
        {
            switch(attacktype)
            {
                case BASE_ATTACK: return !HasFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISARMED);
                case OFF_ATTACK: return !HasFlag(UNIT_FIELD_FLAGS_2,UNIT_FLAG2_DISARM_OFFHAND);
                case RANGED_ATTACK: return !HasFlag(UNIT_FIELD_FLAGS_2,UNIT_FLAG2_DISARM_RANGED);
            }
            return true;
        }

        virtual uint32 GetShieldBlockValue() const =0;
        uint32 GetUnitMeleeSkill(Unit const* target = NULL) const { return (target ? getLevelForTarget(target) : getLevel()) * 5; }
        uint32 GetDefenseSkillValue(Unit const* target = NULL) const;
        uint32 GetWeaponSkillValue(WeaponAttackType attType, Unit const* target = NULL) const;
        float GetWeaponProcChance() const;
        float GetPPMProcChance(uint32 WeaponSpeed, float PPM,  const SpellEntry * spellProto) const;

        MeleeHitOutcome RollMeleeOutcomeAgainst (const Unit *pVictim, WeaponAttackType attType) const;
        MeleeHitOutcome RollMeleeOutcomeAgainst (const Unit *pVictim, WeaponAttackType attType, int32 crit_chance, int32 miss_chance, int32 dodge_chance, int32 parry_chance, int32 block_chance) const;

        bool isVendor()       const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR ); }
        bool isTrainer()      const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TRAINER ); }
        bool isQuestGiver()   const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER ); }
        bool isGossip()       const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP ); }
        bool isTaxi()         const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_FLIGHTMASTER ); }
        bool isGuildMaster()  const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PETITIONER ); }
        bool isBattleMaster() const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BATTLEMASTER ); }
        bool isBanker()       const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BANKER ); }
        bool isInnkeeper()    const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_INNKEEPER ); }
        bool isSpiritHealer() const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER ); }
        bool isSpiritGuide()  const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITGUIDE ); }
        bool isTabardDesigner()const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TABARDDESIGNER ); }
        bool isAuctioner()    const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_AUCTIONEER ); }
        bool isArmorer()      const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_REPAIR ); }
        bool isServiceProvider() const
        {
            return HasFlag( UNIT_NPC_FLAGS,
                UNIT_NPC_FLAG_VENDOR | UNIT_NPC_FLAG_TRAINER | UNIT_NPC_FLAG_FLIGHTMASTER |
                UNIT_NPC_FLAG_PETITIONER | UNIT_NPC_FLAG_BATTLEMASTER | UNIT_NPC_FLAG_BANKER |
                UNIT_NPC_FLAG_INNKEEPER | UNIT_NPC_FLAG_GUARD | UNIT_NPC_FLAG_SPIRITHEALER |
                UNIT_NPC_FLAG_SPIRITGUIDE | UNIT_NPC_FLAG_TABARDDESIGNER | UNIT_NPC_FLAG_AUCTIONEER );
        }
        bool isSpiritService() const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER | UNIT_NPC_FLAG_SPIRITGUIDE ); }

        //Need fix or use this
        bool isGuard() const  { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GUARD); }

        bool isInFlight()  const { return hasUnitState(UNIT_STAT_IN_FLIGHT); }

        bool isInCombat()  const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); }
        void CombatStart(Unit* target);
        void SetInCombatState(bool PvP, Unit* enemy = NULL);
        void SetInCombatWith(Unit* enemy);
        void ClearInCombat();
        uint32 GetCombatTimer() const { return m_CombatTimer; }

        bool HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, uint32 familyFlags) const;
        bool virtual HasSpell(uint32 /*spellID*/) const { return false; }

        bool HasStealthAura()      const { return HasAuraType(SPELL_AURA_MOD_STEALTH); }
        bool HasInvisibilityAura() const { return HasAuraType(SPELL_AURA_MOD_INVISIBILITY); }
        bool isFeared()  const { return HasAuraType(SPELL_AURA_MOD_FEAR); }
        bool isInRoots() const { return HasAuraType(SPELL_AURA_MOD_ROOT); }
        bool IsPolymorphed() const;

        bool isFrozen() const;

        bool isTargetableForAttack() const;
        bool isAttackableByAOE() const;
        bool canAttack(Unit const* target, bool force = true) const;
        virtual bool IsInWater() const;
        virtual bool IsUnderWater() const;
        bool isInAccessiblePlaceFor(Creature const* c) const;

        void SendHealSpellLog(Unit *pVictim, uint32 SpellID, uint32 Damage, bool critical, int32 gain);
        void SendEnergizeSpellLog(Unit *pVictim, uint32 SpellID, uint32 Damage,Powers powertype);
        uint32 SpellNonMeleeDamageLog(Unit *pVictim, uint32 spellID, uint32 damage);
        void CastSpell(Unit* Victim, uint32 spellId, bool triggered, Item *castItem = NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void CastSpell(Unit* Victim, SpellEntry const *spellInfo, bool triggered, Item *castItem= NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void CastSpell(float x, float y, float z, uint32 spellId, bool triggered, Item *castItem = NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void CastCustomSpell(Unit* Victim, uint32 spellId, int32 const* bp0, int32 const* bp1, int32 const* bp2, bool triggered, Item *castItem= NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void CastCustomSpell(uint32 spellId, SpellValueMod mod, int32 value, Unit* Victim = NULL, bool triggered = true, Item *castItem = NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void CastCustomSpell(uint32 spellId, CustomSpellValues const &value, Unit* Victim = NULL, bool triggered = true, Item *castItem = NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void CastSpell(GameObject *go, uint32 spellId, bool triggered, Item *castItem = NULL, AuraEffect* triggeredByAura = NULL, uint64 originalCaster = 0);
        void AddAura(uint32 spellId, Unit *target);
        void SetAuraStack(uint32 spellId, Unit *target, uint32 stack);
        void HandleAuraEffect(AuraEffect * aureff, bool apply);
        Aura *AddAuraEffect(const SpellEntry * spellInfo, uint8 effIndex, Unit* caster, int32 * basePoints=NULL, Unit * source=NULL);

        bool IsDamageToThreatSpell(SpellEntry const * spellInfo) const;

        void DeMorph();

        void SendAttackStateUpdate(CalcDamageInfo *damageInfo);
        void SendAttackStateUpdate(uint32 HitInfo, Unit *target, uint8 SwingType, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount);
        void SendSpellNonMeleeDamageLog(SpellNonMeleeDamage *log);
        void SendSpellNonMeleeDamageLog(Unit *target,uint32 SpellID, uint32 Damage, SpellSchoolMask damageSchoolMask, uint32 AbsorbedDamage, uint32 Resist, bool PhysicalDamage, uint32 Blocked, bool CriticalHit = false);
        void SendPeriodicAuraLog(SpellPeriodicAuraLogInfo *pInfo);
        void SendSpellMiss(Unit *target, uint32 spellID, SpellMissInfo missInfo);

        void NearTeleportTo(float x, float y, float z, float orientation, bool casting = false);

        void KnockbackFrom(float x, float y, float speedXY, float speedZ);
        void JumpTo(float speedXY, float speedZ, bool forward = true);
        void JumpTo(WorldObject *obj, float speedZ);

        void SendMonsterStop();
        void SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint32 Time, Player* player = NULL);
        void SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint32 MoveFlags, uint32 time, float speedZ, Player *player = NULL);
        //void SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint8 type, uint32 MovementFlags, uint32 Time, Player* player = NULL);
        void SendMonsterMoveByPath(Path const& path, uint32 start, uint32 end);
        void SendMonsterMoveTransport(Vehicle *vehicle, bool apply);
        void SendMonsterMoveWithSpeed(float x, float y, float z, uint32 transitTime = 0, Player* player = NULL);
        void SendMonsterMoveWithSpeedToCurrentDestination(Player* player = NULL);
        void SendMovementFlagUpdate();

        void BuildHeartBeatMsg(WorldPacket *data) const;
        void OutMovementInfo() const;

        bool isAlive() const { return (m_deathState == ALIVE); };
        bool isDead() const { return ( m_deathState == DEAD || m_deathState == CORPSE ); };
        DeathState getDeathState() { return m_deathState; };
        virtual void setDeathState(DeathState s);           // overwrited in Creature/Player/Pet

        uint64 GetOwnerGUID() const { return  GetUInt64Value(UNIT_FIELD_SUMMONEDBY); }
        uint64 GetCreatorGUID() const { return GetUInt64Value(UNIT_FIELD_CREATEDBY); }
        void SetCreatorGUID(uint64 creator) { SetUInt64Value(UNIT_FIELD_CREATEDBY, creator); }
        uint64 GetMinionGUID() const { return GetUInt64Value(UNIT_FIELD_SUMMON); }
        void SetMinionGUID(uint64 guid) { SetUInt64Value(UNIT_FIELD_SUMMON, guid); }
        uint64 GetCharmerGUID() const { return GetUInt64Value(UNIT_FIELD_CHARMEDBY); }
        void SetCharmerGUID(uint64 owner) { SetUInt64Value(UNIT_FIELD_CHARMEDBY, owner); }
        uint64 GetCharmGUID() const { return  GetUInt64Value(UNIT_FIELD_CHARM); }
        void SetPetGUID(uint64 guid) { m_SummonSlot[SUMMON_SLOT_PET] = guid; }
        uint64 GetPetGUID() const { return m_SummonSlot[SUMMON_SLOT_PET]; }

        bool IsControlledByPlayer() const { return m_ControlledByPlayer; }
        uint64 GetCharmerOrOwnerGUID() const { return GetCharmerGUID() ? GetCharmerGUID() : GetOwnerGUID(); }
        uint64 GetCharmerOrOwnerOrOwnGUID() const
        {
            if(uint64 guid = GetCharmerOrOwnerGUID())
                return guid;
            return GetGUID();
        }
        bool isCharmedOwnedByPlayerOrPlayer() const { return IS_PLAYER_GUID(GetCharmerOrOwnerOrOwnGUID()); }

        Player* GetSpellModOwner() const;

        Unit* GetOwner() const;
        Guardian *GetGuardianPet() const;
        Minion *GetFirstMinion() const;
        Unit* GetCharmer() const;
        Unit* GetCharm() const;
        Unit* GetCharmerOrOwner() const { return GetCharmerGUID() ? GetCharmer() : GetOwner(); }
        Unit* GetCharmerOrOwnerOrSelf() const
        {
            if(Unit *u = GetCharmerOrOwner())
                return u;

            return (Unit*)this;
        }
        Player* GetCharmerOrOwnerPlayerOrPlayerItself() const;

        void SetMinion(Minion *minion, bool apply);
        void SetCharm(Unit* target, bool apply);
        Unit* GetNextRandomRaidMemberOrPet(float radius);
        void SetCharmedBy(Unit* charmer, CharmType type);
        void RemoveCharmedBy(Unit* charmer);
        void RestoreFaction();

        ControlList m_Controlled;
        Unit* GetFirstControlled() const;
        void RemoveAllControlled();

        bool isCharmed() const { return GetCharmerGUID() != 0; }
        bool isPossessed() const { return hasUnitState(UNIT_STAT_POSSESSED); }
        bool isPossessedByPlayer() const { return hasUnitState(UNIT_STAT_POSSESSED) && IS_PLAYER_GUID(GetCharmerGUID()); }
        bool isPossessing() const
        {
            if(Unit *u = GetCharm())
                return u->isPossessed();
            else
                return false;
        }
        bool isPossessing(Unit* u) const { return u->isPossessed() && GetCharmGUID() == u->GetGUID(); }

        CharmInfo* GetCharmInfo() { return m_charmInfo; }
        CharmInfo* InitCharmInfo();
        void       DeleteCharmInfo();
        void UpdateCharmAI();
        SharedVisionList const& GetSharedVisionList() { return m_sharedVision; }
        void AddPlayerToVision(Player* plr);
        void RemovePlayerFromVision(Player* plr);
        bool HasSharedVision() const { return !m_sharedVision.empty(); }
        void RemoveBindSightAuras();
        void RemoveCharmAuras();

        Pet* CreateTamedPetFrom(Creature* creatureTarget,uint32 spell_id = 0);

        bool AddAura(Aura *aur, bool handleEffects = true);

        void RemoveAura(AuraMap::iterator &i, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(uint32 spellId, uint64 caster = 0 ,AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(Aura * aur, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAurasDueToSpell(uint32 spellId, uint64 caster = NULL ,AuraRemoveMode removeMode= AURA_REMOVE_BY_DEFAULT);
        void RemoveAuraFromStack(uint32 spellId, uint64 caster = NULL ,AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        inline void RemoveAuraFromStack(AuraMap::iterator &iter,AuraRemoveMode removeMode);
        void RemoveAurasDueToSpellByDispel(uint32 spellId, uint64 casterGUID, Unit *dispeler);
        void RemoveAurasDueToSpellBySteal(uint32 spellId, uint64 casterGUID, Unit *stealer);
        void RemoveAurasDueToItemSpell(Item* castItem,uint32 spellId);
        void RemoveAurasByType(AuraType auraType, uint64 casterGUID = 0, Aura * except=NULL, bool negative = true, bool positive = true);
        void RemoveAurasByTypeWithDispel(AuraType auraType, Spell * spell = NULL);
        void RemoveNotOwnSingleTargetAuras();
        bool RemoveNoStackAurasDueToAura(Aura *Aur);
        void RemoveAurasWithInterruptFlags(uint32 flag, uint32 except = NULL);
        void RemoveAurasWithFamily(uint32 family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, uint64 casterGUID);
        void RemoveMovementImpairingAuras();
        void RemoveAllAuras();
        void RemoveArenaAuras(bool onleave = false);
        void RemoveAllAurasOnDeath();
        void DelayAura(uint32 spellId, uint64 caster, int32 delaytime);

        float GetResistanceBuffMods(SpellSchools school, bool positive) const { return GetFloatValue(positive ? UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE+school : UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE+school ); }
        void SetResistanceBuffMods(SpellSchools school, bool positive, float val) { SetFloatValue(positive ? UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE+school : UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE+school,val); }
        void ApplyResistanceBuffModsMod(SpellSchools school, bool positive, float val, bool apply) { ApplyModSignedFloatValue(positive ? UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE+school : UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE+school, val, apply); }
        void ApplyResistanceBuffModsPercentMod(SpellSchools school, bool positive, float val, bool apply) { ApplyPercentModFloatValue(positive ? UNIT_FIELD_RESISTANCEBUFFMODSPOSITIVE+school : UNIT_FIELD_RESISTANCEBUFFMODSNEGATIVE+school, val, apply); }
        void InitStatBuffMods()
        {
            for(int i = STAT_STRENGTH; i < MAX_STATS; ++i) SetFloatValue(UNIT_FIELD_POSSTAT0+i, 0);
            for(int i = STAT_STRENGTH; i < MAX_STATS; ++i) SetFloatValue(UNIT_FIELD_NEGSTAT0+i, 0);
        }
        void ApplyStatBuffMod(Stats stat, float val, bool apply) { ApplyModSignedFloatValue((val > 0 ? UNIT_FIELD_POSSTAT0+stat : UNIT_FIELD_NEGSTAT0+stat), val, apply); }
        void ApplyStatPercentBuffMod(Stats stat, float val, bool apply)
        {
            ApplyPercentModFloatValue(UNIT_FIELD_POSSTAT0+stat, val, apply);
            ApplyPercentModFloatValue(UNIT_FIELD_NEGSTAT0+stat, val, apply);
        }
        void SetCreateStat(Stats stat, float val) { m_createStats[stat] = val; }
        void SetCreateHealth(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_HEALTH, val); }
        uint32 GetCreateHealth() const { return GetUInt32Value(UNIT_FIELD_BASE_HEALTH); }
        void SetCreateMana(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_MANA, val); }
        uint32 GetCreateMana() const { return GetUInt32Value(UNIT_FIELD_BASE_MANA); }
        uint32 GetCreatePowers(Powers power) const;
        float GetPosStat(Stats stat) const { return GetFloatValue(UNIT_FIELD_POSSTAT0+stat); }
        float GetNegStat(Stats stat) const { return GetFloatValue(UNIT_FIELD_NEGSTAT0+stat); }
        float GetCreateStat(Stats stat) const { return m_createStats[stat]; }

        void SetCurrentCastedSpell(Spell * pSpell);
        virtual void ProhibitSpellScholl(SpellSchoolMask /*idSchoolMask*/, uint32 /*unTimeMs*/ ) { }
        void InterruptSpell(uint32 spellType, bool withDelayed = true, bool withInstant = true);

        // set withDelayed to true to account delayed spells as casted
        // delayed+channeled spells are always accounted as casted
        // we can skip channeled or delayed checks using flags
        bool IsNonMeleeSpellCasted(bool withDelayed, bool skipChanneled = false, bool skipAutorepeat = false, bool isAutoshoot = false) const;

        // set withDelayed to true to interrupt delayed spells too
        // delayed+channeled spells are always interrupted
        void InterruptNonMeleeSpells(bool withDelayed, uint32 spellid = 0, bool withInstant = true);

        Spell* FindCurrentSpellBySpellId(uint32 spell_id) const;

        Spell* m_currentSpells[CURRENT_MAX_SPELL];

        uint32 m_addDmgOnce;
        uint64 m_SummonSlot[MAX_SUMMON_SLOT];
        uint64 m_ObjectSlot[4];
        uint32 m_detectInvisibilityMask;
        uint32 m_invisibilityMask;

        uint32 m_ShapeShiftFormSpellId;
        ShapeshiftForm m_form;
        bool IsInFeralForm() const { return m_form == FORM_CAT || m_form == FORM_BEAR || m_form == FORM_DIREBEAR; }

        float m_modMeleeHitChance;
        float m_modRangedHitChance;
        float m_modSpellHitChance;
        int32 m_baseSpellCritChance;

        float m_threatModifier[MAX_SPELL_SCHOOL];
        float m_modAttackSpeedPct[3];

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
        virtual void UpdateArmor() = 0;
        virtual void UpdateMaxHealth() = 0;
        virtual void UpdateMaxPower(Powers power) = 0;
        virtual void UpdateAttackPowerAndDamage(bool ranged = false) = 0;
        virtual void UpdateDamagePhysical(WeaponAttackType attType) = 0;
        float GetTotalAttackPowerValue(WeaponAttackType attType) const;
        float GetWeaponDamageRange(WeaponAttackType attType ,WeaponDamageRange type) const;
        void SetBaseWeaponDamage(WeaponAttackType attType ,WeaponDamageRange damageRange, float value) { m_weaponDamage[attType][damageRange] = value; }

        bool isInFrontInMap(Unit const* target,float distance, float arc = M_PI) const;
        void SetInFront(Unit const* target);
        bool isInBackInMap(Unit const* target, float distance, float arc = M_PI) const;
        bool isInLine(Unit const* target, float distance) const;

        // Visibility system
        UnitVisibility GetVisibility() const { return m_Visibility; }
        void SetVisibility(UnitVisibility x);
        void DestroyForNearbyPlayers();

        // common function for visibility checks for player/creatures with detection code
        virtual bool canSeeOrDetect(Unit const* u, bool detect, bool inVisibleList = false, bool is3dDistance = true) const = 0;
        bool isVisibleForOrDetect(Unit const* u, bool detect, bool inVisibleList = false, bool is3dDistance = true) const;
        bool canDetectInvisibilityOf(Unit const* u) const;
        bool canDetectStealthOf(Unit const* u, float distance) const;
        void SetPhaseMask(uint32 newPhaseMask, bool update);// overwrite WorldObject::SetPhaseMask

        // virtual functions for all world objects types
        bool isVisibleForInState(Player const* u, bool inVisibleList) const;
        // function for low level grid visibility checks in player/creature cases
        virtual bool IsVisibleInGridForPlayer(Player const* pl) const = 0;

        AuraList      & GetSingleCastAuras()       { return m_scAuras; }
        AuraList const& GetSingleCastAuras() const { return m_scAuras; }
        SpellImmuneList m_spellImmune[MAX_SPELL_IMMUNITY];

        // Threat related methods
        bool CanHaveThreatList() const;
        void AddThreat(Unit* pVictim, float threat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellEntry const *threatSpell = NULL);
        float ApplyTotalThreatModifier(float threat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL);
        void DeleteThreatList();
        void TauntApply(Unit* pVictim);
        void TauntFadeOut(Unit *taunter);
        ThreatManager& getThreatManager() { return m_ThreatManager; }
        void addHatedBy(HostilReference* pHostilReference) { m_HostilRefManager.insertFirst(pHostilReference); };
        void removeHatedBy(HostilReference* /*pHostilReference*/ ) { /* nothing to do yet */ }
        HostilRefManager& getHostilRefManager() { return m_HostilRefManager; }

        VisibleAuraMap const *GetVisibleAuras() { return &m_visibleAuras; }
        Aura * GetVisibleAura(uint8 slot)
        {
            VisibleAuraMap::iterator itr = m_visibleAuras.find(slot);
            if(itr != m_visibleAuras.end())
                return itr->second;
            return 0;
        }
        void SetVisibleAura(uint8 slot, Aura * aur){ m_visibleAuras[slot]=aur; }
        void RemoveVisibleAura(uint8 slot){ m_visibleAuras.erase(slot); }
        void SendAuraVisualForSelf(bool apply, uint32 id, uint8 effmask = 0);

        AuraMap      & GetAuras()       { return m_Auras; }
        AuraMap const& GetAuras() const { return m_Auras; }
        AuraEffectList const& GetAurasByType(AuraType type) const { return m_modAuras[type]; }

        AuraEffect * GetAuraEffect(uint32 spellId, uint8 effIndex, uint64 casterGUID = 0) const;
        Aura * GetAura(uint32 spellId, uint64 casterGUID = 0) const;
        AuraEffect* GetAura(AuraType type, uint32 family, uint32 familyFlag1 , uint32 familyFlag2=0, uint32 familyFlag3=0, uint64 casterGUID=0);
        bool HasAuraEffect(uint32 spellId, uint8 effIndex, uint64 caster = 0) const;
        bool HasAura(uint32 spellId, uint64 caster = 0) const;
        bool HasAura(Aura * aur) const;
        bool HasAuraType(AuraType auraType) const;
        bool HasAuraTypeWithMiscvalue(AuraType auratype, uint32 miscvalue) const;
        AuraEffect* GetDummyAura(uint32 spell_id) const;
        AuraEffect* GetDummyAura(SpellFamilyNames name, uint32 iconId) const;
        uint32 GetDiseasesByCaster(uint64 casterGUID, bool remove = false);
        uint32 GetDoTsByCaster(uint64 casterGUID) const;

        int32 GetTotalAuraModifier(AuraType auratype) const;
        float GetTotalAuraMultiplier(AuraType auratype) const;
        int32 GetMaxPositiveAuraModifier(AuraType auratype);
        int32 GetMaxNegativeAuraModifier(AuraType auratype) const;

        int32 GetTotalAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        float GetTotalAuraMultiplierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        int32 GetMaxPositiveAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        int32 GetMaxNegativeAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const;

        int32 GetTotalAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;
        float GetTotalAuraMultiplierByMiscValue(AuraType auratype, int32 misc_value) const;
        int32 GetMaxPositiveAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;
        int32 GetMaxNegativeAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;

        uint32 GetInterruptMask() const { return m_interruptMask; }
        void AddInterruptMask(uint32 mask) { m_interruptMask |= mask; }
        void UpdateInterruptMask();

        uint32 GetDisplayId() { return GetUInt32Value(UNIT_FIELD_DISPLAYID); }
        void SetDisplayId(uint32 modelId);
        uint32 GetNativeDisplayId() { return GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID); }
        void SetNativeDisplayId(uint32 modelId) { SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, modelId); }
        void setTransForm(uint32 spellid) { m_transform = spellid;}
        uint32 getTransForm() const { return m_transform;}

        DynamicObject* GetDynObject(uint32 spellId, uint32 effIndex);
        DynamicObject* GetDynObject(uint32 spellId);
        void AddDynObject(DynamicObject* dynObj);
        void RemoveDynObject(uint32 spellid);
        void RemoveDynObjectWithGUID(uint64 guid) { m_dynObjGUIDs.remove(guid); }
        void RemoveAllDynObjects();

        GameObject* GetGameObject(uint32 spellId) const;
        void AddGameObject(GameObject* gameObj);
        void RemoveGameObject(GameObject* gameObj, bool del);
        void RemoveGameObject(uint32 spellid, bool del);
        void RemoveAllGameObjects();

        uint32 CalculateDamage(WeaponAttackType attType, bool normalized);
        float GetAPMultiplier(WeaponAttackType attType, bool normalized);
        void ModifyAuraState(AuraState flag, bool apply);
        bool HasAuraState(AuraState flag, SpellEntry const *spellProto = NULL, Unit * Caster = NULL) const ;
        void UnsummonAllTotems();
        Unit* SelectMagnetTarget(Unit *victim, SpellEntry const *spellInfo = NULL);
        int32 SpellBaseDamageBonus(SpellSchoolMask schoolMask);
        int32 SpellBaseHealingBonus(SpellSchoolMask schoolMask);
        int32 SpellBaseDamageBonusForVictim(SpellSchoolMask schoolMask, Unit *pVictim);
        int32 SpellBaseHealingBonusForVictim(SpellSchoolMask schoolMask, Unit *pVictim);
        uint32 SpellDamageBonus(Unit *pVictim, SpellEntry const *spellProto, uint32 damage, DamageEffectType damagetype, uint32 stack = 1);
        uint32 SpellHealingBonus(Unit *pVictim, SpellEntry const *spellProto, uint32 healamount, DamageEffectType damagetype, uint32 stack = 1);
        bool   isSpellBlocked(Unit *pVictim, SpellEntry const *spellProto, WeaponAttackType attackType = BASE_ATTACK);
        bool   isBlockCritical();
        bool   isSpellCrit(Unit *pVictim, SpellEntry const *spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK);
        uint32 SpellCriticalDamageBonus(SpellEntry const *spellProto, uint32 damage, Unit *pVictim);
        uint32 SpellCriticalHealingBonus(SpellEntry const *spellProto, uint32 damage, Unit *pVictim);

        void SetLastManaUse(uint32 spellCastTime) { m_lastManaUse = spellCastTime; }
        bool IsUnderLastManaUseEffect() const;

        void SetContestedPvP(Player *attackedPlayer = NULL);

        void MeleeDamageBonus(Unit *pVictim, uint32 *damage, WeaponAttackType attType, SpellEntry const *spellProto = NULL);
        uint32 GetCastingTimeForBonus( SpellEntry const *spellProto, DamageEffectType damagetype, uint32 CastingTime );

        void ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply);
        void ApplySpellDispelImmunity(const SpellEntry * spellProto, DispelType type, bool apply);
        virtual bool IsImmunedToSpell(SpellEntry const* spellInfo);
                                                            // redefined in Creature
        bool IsImmunedToDamage(SpellSchoolMask meleeSchoolMask);
        bool IsImmunedToDamage(SpellEntry const* spellInfo);
        virtual bool IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const;
                                                            // redefined in Creature

        uint32 CalcArmorReducedDamage(Unit* pVictim, const uint32 damage, SpellEntry const *spellInfo, WeaponAttackType attackType=MAX_ATTACK);
        void CalcAbsorbResist(Unit *pVictim, SpellSchoolMask schoolMask, DamageEffectType damagetype, const uint32 damage, uint32 *absorb, uint32 *resist, SpellEntry const *spellInfo = NULL);

        void  UpdateSpeed(UnitMoveType mtype, bool forced);
        float GetSpeed( UnitMoveType mtype ) const;
        float GetSpeedRate( UnitMoveType mtype ) const { return m_speed_rate[mtype]; }
        void SetSpeed(UnitMoveType mtype, float rate, bool forced = false);
        float m_TempSpeed;

        void SetHover(bool on);
        bool isHover() const { return HasAuraType(SPELL_AURA_HOVER); }

        void _RemoveAllAuraMods();
        void _ApplyAllAuraMods();

        int32 CalculateSpellDamage(SpellEntry const* spellProto, uint8 effect_index, int32 basePoints, Unit const* target);
        int32 CalcSpellDuration(SpellEntry const* spellProto);
        int32 ModSpellDuration(SpellEntry const* spellProto, Unit const* target, int32 duration, bool positive);
        void  ModSpellCastTime(SpellEntry const* spellProto, int32 & castTime, Spell * spell=NULL);
        float CalculateLevelPenalty(SpellEntry const* spellProto) const;

        void addFollower(FollowerReference* pRef) { m_FollowingRefManager.insertFirst(pRef); }
        void removeFollower(FollowerReference* /*pRef*/ ) { /* nothing to do yet */ }
        static Unit* GetUnit(WorldObject& object, uint64 guid);
        static Player* GetPlayer(uint64 guid);
        static Creature* GetCreature(WorldObject& object, uint64 guid);

        MotionMaster* GetMotionMaster() { return &i_motionMaster; }

        bool IsStopped() const { return !(hasUnitState(UNIT_STAT_MOVING)); }
        void StopMoving();

        void AddUnitMovementFlag(uint32 f) { m_movementInfo.flags |= f; }
        void RemoveUnitMovementFlag(uint32 f) { m_movementInfo.flags &= ~f; }
        uint32 HasUnitMovementFlag(uint32 f) const { return m_movementInfo.flags & f; }
        uint32 GetUnitMovementFlags() const { return m_movementInfo.flags; }
        void SetUnitMovementFlags(uint32 f) { m_movementInfo.flags = f; }

        void SetControlled(bool apply, UnitState state);

        void AddComboPointHolder(uint32 lowguid) { m_ComboPointHolders.insert(lowguid); }
        void RemoveComboPointHolder(uint32 lowguid) { m_ComboPointHolders.erase(lowguid); }
        void ClearComboPointHolders();

        ///----------Pet responses methods-----------------
        void SendPetCastFail(uint32 spellid, SpellCastResult msg);
        void SendPetActionFeedback (uint8 msg);
        void SendPetTalk (uint32 pettalk);
        void SendPetSpellCooldown (uint32 spellid, time_t cooltime);
        void SendPetClearCooldown (uint32 spellid);
        void SendPetAIReaction(uint64 guid);
        ///----------End of Pet responses methods----------

        void propagateSpeedChange() { GetMotionMaster()->propagateSpeedChange(); }

        // reactive attacks
        void ClearAllReactives();
        void StartReactiveTimer( ReactiveType reactive ) { m_reactiveTimer[reactive] = REACTIVE_TIMER_START;}
        void UpdateReactives(uint32 p_time);

        // group updates
        void UpdateAuraForGroup(uint8 slot);

        // proc trigger system
        bool CanProc(){return !m_procDeep;}
        void SetCantProc( bool apply)
        {
            if(apply)
                ++m_procDeep;
            else
            {
                assert(m_procDeep);
                --m_procDeep;
            }
        }

        // pet auras
        typedef std::set<PetAura const*> PetAuraSet;
        PetAuraSet m_petAuras;
        void AddPetAura(PetAura const* petSpell);
        void RemovePetAura(PetAura const* petSpell);

        // relocation notification
        void SetToNotify();
        bool m_Notified;
        int32 m_NotifyListPos;
        float oldX, oldY;

        void SetReducedThreatPercent(uint32 pct, uint64 guid)
        {
            m_reducedThreatPercent = pct;
            m_misdirectionTargetGUID = guid;
        }
        uint32 GetReducedThreatPercent() { return m_reducedThreatPercent; }
        Unit *GetMisdirectionTarget() { return m_misdirectionTargetGUID ? GetUnit(*this, m_misdirectionTargetGUID) : NULL; }

        bool IsAIEnabled, NeedChangeAI;
        MovementInfo m_movementInfo;
        Vehicle *m_Vehicle;
        float GetTransOffsetX() const { return m_movementInfo.t_x; }
        float GetTransOffsetY() const { return m_movementInfo.t_y; }
        float GetTransOffsetZ() const { return m_movementInfo.t_z; }
        float GetTransOffsetO() const { return m_movementInfo.t_o; }
        uint32 GetTransTime()   const { return m_movementInfo.t_time; }
        int8 GetTransSeat()     const { return m_movementInfo.t_seat; }

        bool m_ControlledByPlayer;

        void EnterVehicle(Vehicle *vehicle, int8 seatId = -1);
        void ExitVehicle();
        void ChangeSeat(int8 seatId, bool next = true);

        // Transports
        Transport * GetTransport() const { return m_transport; }
        void SetTransport(Transport * t) { m_transport = t; }

        void BuildMovementPacket(ByteBuffer *data) const;
    protected:
        explicit Unit ();

        UnitAI *i_AI, *i_disabledAI;

        // Transports
        Transport * m_transport;

        void _UpdateSpells(uint32 time);
        void _DeleteAuras();

        void _UpdateAutoRepeatSpell();

        bool m_AutoRepeatFirstCast;

        uint32 m_attackTimer[MAX_ATTACK];

        float m_createStats[MAX_STATS];

        AttackerSet m_attackers;
        Unit* m_attacking;

        DeathState m_deathState;

        AuraMap m_Auras;
        uint32 m_removedAurasCount;
        int32 m_procDeep;

        typedef std::list<uint64> DynObjectGUIDs;
        DynObjectGUIDs m_dynObjGUIDs;

        typedef std::list<GameObject*> GameObjectList;
        GameObjectList m_gameObj;
        bool m_isSorted;
        uint32 m_transform;

        AuraEffectList m_modAuras[TOTAL_AURAS];
        AuraList m_scAuras;                        // casted singlecast auras
        AuraList m_interruptableAuras;
        AuraList m_ccAuras;
        AuraList m_removedAuras;
        uint32 m_interruptMask;

        float m_auraModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_END];
        float m_weaponDamage[MAX_ATTACK][2];
        bool m_canModifyStats;
        //std::list< spellEffectPair > AuraSpells[TOTAL_AURAS];  // TODO: use this if ok for mem
        VisibleAuraMap m_visibleAuras;

        float m_speed_rate[MAX_MOVE_TYPE];

        CharmInfo *m_charmInfo;
        SharedVisionList m_sharedVision;

        virtual SpellSchoolMask GetMeleeDamageSchoolMask() const;

        MotionMaster i_motionMaster;
        //uint32 m_unit_movement_flags;

        uint32 m_reactiveTimer[MAX_REACTIVE];
        uint32 m_regenTimer;

        ThreatManager m_ThreatManager;

    private:
        bool IsTriggeredAtSpellProcEvent(Unit *pVictim, Aura* aura, SpellEntry const * procSpell, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, bool isVictim, bool active, SpellProcEventEntry const *& spellProcEvent );
        bool HandleDummyAuraProc(   Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        bool HandleObsModEnergyAuraProc(   Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        bool HandleModDamagePctTakenAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        bool HandleHasteAuraProc(   Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        bool HandleProcTriggerSpell(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        bool HandleOverrideClassScriptAuraProc(Unit *pVictim, uint32 damage, AuraEffect* triggeredByAura, SpellEntry const *procSpell, uint32 cooldown);
        bool HandleAuraRaidProcFromChargeWithValue(AuraEffect* triggeredByAura);
        bool HandleAuraRaidProcFromCharge(AuraEffect* triggeredByAura);

        void SetFeared(bool apply);
        void SetConfused(bool apply);
        void SetStunned(bool apply);
        void SetRooted(bool apply);

        uint32 m_state;                                     // Even derived shouldn't modify
        uint32 m_CombatTimer;
        uint32 m_lastManaUse;                               // msecs

        UnitVisibility m_Visibility;

        Diminishing m_Diminishing;
        // Manage all Units threatening us
//        ThreatManager m_ThreatManager;
        // Manage all Units that are threatened by us
        HostilRefManager m_HostilRefManager;

        FollowerRefManager m_FollowingRefManager;

        ComboPointHolderSet m_ComboPointHolders;

        uint32 m_reducedThreatPercent;
        uint64 m_misdirectionTargetGUID;
};

namespace Trinity
{
    template<class T>
    void RandomResizeList(std::list<T> &_list, uint32 _size)
    {
        while(_list.size() > _size)
        {
            typename std::list<T>::iterator itr = _list.begin();
            advance(itr, urand(0, _list.size() - 1));
            _list.erase(itr);
        }
    }
}

#endif

