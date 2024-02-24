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

#ifndef _SPELLMGR_H
#define _SPELLMGR_H

// For static or at-server-startup loaded spell data

#include "Define.h"
#include "DBCEnums.h"
#include "Duration.h"
#include "EnumFlag.h"
#include "Errors.h"
#include "FlagsArray.h"
#include "Hash.h"
#include "IteratorPair.h"
#include "RaceMask.h"
#include "SharedDefines.h"
#include "SpellDefines.h"
#include <bitset>
#include <functional>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class SpellInfo;
class Player;
class Unit;
class ProcEventInfo;
struct SkillLineAbilityEntry;
struct SpellAuraOptionsEntry;
struct SpellAuraRestrictionsEntry;
struct SpellCastingRequirementsEntry;
struct SpellCategoriesEntry;
struct SpellClassOptionsEntry;
struct SpellCooldownsEntry;
struct SpellEffectEntry;
struct SpellEquippedItemsEntry;
struct SpellInterruptsEntry;
struct SpellLabelEntry;
struct SpellLevelsEntry;
struct SpellMiscEntry;
struct SpellNameEntry;
struct SpellPowerEntry;
struct SpellReagentsEntry;
struct SpellReagentsCurrencyEntry;
struct SpellScalingEntry;
struct SpellShapeshiftEntry;
struct SpellTargetRestrictionsEntry;
struct SpellTotemsEntry;
struct SpellXSpellVisualEntry;
enum AuraType : uint32;

// only used in code
enum SpellCategories
{
    SPELLCATEGORY_HEALTH_MANA_POTIONS = 4,
    SPELLCATEGORY_DEVOUR_MAGIC        = 12,
    SPELLCATEGORY_JUDGEMENT           = 1210,               // Judgement (seal trigger)
    SPELLCATEGORY_FOOD                = 11,
    SPELLCATEGORY_DRINK               = 59
};

//SpellFamilyFlags
enum SpellFamilyFlag
{
    // SPELLFAMILYFLAG  = SpellFamilyFlags[0]
    // SPELLFAMILYFLAG1 = SpellFamilyFlags[1]
    // SPELLFAMILYFLAG2 = SpellFamilyFlags[2]

    // Rogue
    SPELLFAMILYFLAG0_ROGUE_VANISH               = 0x00000800,
    SPELLFAMILYFLAG0_ROGUE_VAN_SPRINT           = 0x00000840, // Vanish, Sprint
    SPELLFAMILYFLAG1_ROGUE_SHADOWSTEP           = 0x00000200, // Shadowstep
    SPELLFAMILYFLAG0_ROGUE_KICK                 = 0x00000010, // Kick
    SPELLFAMILYFLAG1_ROGUE_DISMANTLE_SMOKE_BOMB = 0x80100000, // Dismantle, Smoke Bomb

    // Warrior
    SPELLFAMILYFLAG_WARRIOR_CHARGE              = 0x00000001,
    SPELLFAMILYFLAG_WARRIOR_SLAM                = 0x00200000,
    SPELLFAMILYFLAG_WARRIOR_EXECUTE             = 0x20000000,
    SPELLFAMILYFLAG_WARRIOR_CONCUSSION_BLOW     = 0x04000000,

    // Warlock
    SPELLFAMILYFLAG_WARLOCK_LIFETAP             = 0x00040000,

    // Druid
    SPELLFAMILYFLAG2_DRUID_STARFALL             = 0x00000100,

    // Paladin
    SPELLFAMILYFLAG1_PALADIN_DIVINESTORM        = 0x00020000,

    // Shaman
    SPELLFAMILYFLAG_SHAMAN_FROST_SHOCK          = 0x80000000,
    SPELLFAMILYFLAG_SHAMAN_HEALING_STREAM       = 0x00002000,
    SPELLFAMILYFLAG_SHAMAN_MANA_SPRING          = 0x00004000,
    SPELLFAMILYFLAG2_SHAMAN_LAVA_LASH           = 0x00000004,
    SPELLFAMILYFLAG_SHAMAN_FIRE_NOVA            = 0x28000000,

    // Deathknight
    SPELLFAMILYFLAG_DK_DEATH_STRIKE             = 0x00000010,
    SPELLFAMILYFLAG_DK_DEATH_COIL               = 0x00002000,

    /// @todo Figure out a more accurate name for the following familyflag(s)
    SPELLFAMILYFLAG_SHAMAN_TOTEM_EFFECTS        = 0x04000000  // Seems to be linked to most totems and some totem effects
};

enum SpellLinkedType
{
    SPELL_LINK_CAST     = 0,            // +: cast; -: remove
    SPELL_LINK_HIT      = 1,
    SPELL_LINK_AURA     = 2,            // +: aura; -: immune
    SPELL_LINK_REMOVE   = 3
};

// Spell proc event related declarations (accessed using SpellMgr functions)
enum ProcFlags : uint32
{
    PROC_FLAG_NONE                              = 0x00000000,

    PROC_FLAG_HEARTBEAT                         = 0x00000001,    // 00 Killed by agressor - not sure about this flag
    PROC_FLAG_KILL                              = 0x00000002,    // 01 Kill target (in most cases need XP/Honor reward)

    PROC_FLAG_DEAL_MELEE_SWING                  = 0x00000004,    // 02 Done melee auto attack
    PROC_FLAG_TAKE_MELEE_SWING                  = 0x00000008,    // 03 Taken melee auto attack

    PROC_FLAG_DEAL_MELEE_ABILITY                = 0x00000010,    // 04 Done attack by Spell that has dmg class melee
    PROC_FLAG_TAKE_MELEE_ABILITY                = 0x00000020,    // 05 Taken attack by Spell that has dmg class melee

    PROC_FLAG_DEAL_RANGED_ATTACK                = 0x00000040,    // 06 Done ranged auto attack
    PROC_FLAG_TAKE_RANGED_ATTACK                = 0x00000080,    // 07 Taken ranged auto attack

    PROC_FLAG_DEAL_RANGED_ABILITY               = 0x00000100,    // 08 Done attack by Spell that has dmg class ranged
    PROC_FLAG_TAKE_RANGED_ABILITY               = 0x00000200,    // 09 Taken attack by Spell that has dmg class ranged

    PROC_FLAG_DEAL_HELPFUL_ABILITY              = 0x00000400,    // 10 Done positive spell that has dmg class none
    PROC_FLAG_TAKE_HELPFUL_ABILITY              = 0x00000800,    // 11 Taken positive spell that has dmg class none

    PROC_FLAG_DEAL_HARMFUL_ABILITY              = 0x00001000,    // 12 Done negative spell that has dmg class none
    PROC_FLAG_TAKE_HARMFUL_ABILITY              = 0x00002000,    // 13 Taken negative spell that has dmg class none

    PROC_FLAG_DEAL_HELPFUL_SPELL                = 0x00004000,    // 14 Done positive spell that has dmg class magic
    PROC_FLAG_TAKE_HELPFUL_SPELL                = 0x00008000,    // 15 Taken positive spell that has dmg class magic

    PROC_FLAG_DEAL_HARMFUL_SPELL                = 0x00010000,    // 16 Done negative spell that has dmg class magic
    PROC_FLAG_TAKE_HARMFUL_SPELL                = 0x00020000,    // 17 Taken negative spell that has dmg class magic

    PROC_FLAG_DEAL_HARMFUL_PERIODIC             = 0x00040000,    // 18 Successful do periodic (damage)
    PROC_FLAG_TAKE_HARMFUL_PERIODIC             = 0x00080000,    // 19 Taken spell periodic (damage)

    PROC_FLAG_TAKE_ANY_DAMAGE                   = 0x00100000,    // 20 Taken any damage

    PROC_FLAG_DEAL_HELPFUL_PERIODIC             = 0x00200000,    // 21 On trap activation (possibly needs name change to ON_GAMEOBJECT_CAST or USE)

    PROC_FLAG_MAIN_HAND_WEAPON_SWING            = 0x00400000,    // 22 Done main-hand melee attacks (spell and autoattack)
    PROC_FLAG_OFF_HAND_WEAPON_SWING             = 0x00800000,    // 23 Done off-hand melee attacks (spell and autoattack)

    PROC_FLAG_DEATH                             = 0x01000000,    // 24 Died in any way

    PROC_FLAG_JUMP                              = 0x02000000,    // 25 Jumped

    PROC_FLAG_PROC_CLONE_SPELL                  = 0x04000000,    // 26 Proc Clone Spell

    PROC_FLAG_ENTER_COMBAT                      = 0x08000000,    // 27 Entered combat

    PROC_FLAG_ENCOUNTER_START                   = 0x10000000,    // 28 Encounter started

    PROC_FLAG_CAST_ENDED                        = 0x20000000,    // 29 Cast Ended

    PROC_FLAG_LOOTED                            = 0x40000000,    // 30 Looted (took from loot, not opened loot window)

    PROC_FLAG_TAKE_HELPFUL_PERIODIC             = 0x80000000,    // 31 Take Helpful Periodic

    // flag masks
    AUTO_ATTACK_PROC_FLAG_MASK                  = PROC_FLAG_DEAL_MELEE_SWING | PROC_FLAG_TAKE_MELEE_SWING
                                                | PROC_FLAG_DEAL_RANGED_ATTACK | PROC_FLAG_TAKE_RANGED_ATTACK,

    MELEE_PROC_FLAG_MASK                        = PROC_FLAG_DEAL_MELEE_SWING | PROC_FLAG_TAKE_MELEE_SWING
                                                | PROC_FLAG_DEAL_MELEE_ABILITY | PROC_FLAG_TAKE_MELEE_ABILITY
                                                | PROC_FLAG_MAIN_HAND_WEAPON_SWING | PROC_FLAG_OFF_HAND_WEAPON_SWING,

    RANGED_PROC_FLAG_MASK                       = PROC_FLAG_DEAL_RANGED_ATTACK | PROC_FLAG_TAKE_RANGED_ATTACK
                                                | PROC_FLAG_DEAL_RANGED_ABILITY | PROC_FLAG_TAKE_RANGED_ABILITY,

    SPELL_PROC_FLAG_MASK                        = PROC_FLAG_DEAL_MELEE_ABILITY | PROC_FLAG_TAKE_MELEE_ABILITY
                                                | PROC_FLAG_DEAL_RANGED_ATTACK | PROC_FLAG_TAKE_RANGED_ATTACK
                                                | PROC_FLAG_DEAL_RANGED_ABILITY | PROC_FLAG_TAKE_RANGED_ABILITY
                                                | PROC_FLAG_DEAL_HELPFUL_ABILITY | PROC_FLAG_TAKE_HELPFUL_ABILITY
                                                | PROC_FLAG_DEAL_HARMFUL_ABILITY | PROC_FLAG_TAKE_HARMFUL_ABILITY
                                                | PROC_FLAG_DEAL_HELPFUL_SPELL | PROC_FLAG_TAKE_HELPFUL_SPELL
                                                | PROC_FLAG_DEAL_HARMFUL_SPELL | PROC_FLAG_TAKE_HARMFUL_SPELL
                                                | PROC_FLAG_DEAL_HARMFUL_PERIODIC | PROC_FLAG_TAKE_HARMFUL_PERIODIC
                                                | PROC_FLAG_DEAL_HELPFUL_PERIODIC | PROC_FLAG_TAKE_HELPFUL_PERIODIC,

    DONE_HIT_PROC_FLAG_MASK                     = PROC_FLAG_DEAL_MELEE_SWING | PROC_FLAG_DEAL_RANGED_ATTACK
                                                | PROC_FLAG_DEAL_MELEE_ABILITY | PROC_FLAG_DEAL_RANGED_ABILITY
                                                | PROC_FLAG_DEAL_HELPFUL_ABILITY | PROC_FLAG_DEAL_HARMFUL_ABILITY
                                                | PROC_FLAG_DEAL_HELPFUL_SPELL | PROC_FLAG_DEAL_HARMFUL_SPELL
                                                | PROC_FLAG_DEAL_HARMFUL_PERIODIC | PROC_FLAG_DEAL_HELPFUL_PERIODIC
                                                | PROC_FLAG_MAIN_HAND_WEAPON_SWING | PROC_FLAG_OFF_HAND_WEAPON_SWING,

    TAKEN_HIT_PROC_FLAG_MASK                    = PROC_FLAG_TAKE_MELEE_SWING | PROC_FLAG_TAKE_RANGED_ATTACK
                                                | PROC_FLAG_TAKE_MELEE_ABILITY | PROC_FLAG_TAKE_RANGED_ABILITY
                                                | PROC_FLAG_TAKE_HELPFUL_ABILITY | PROC_FLAG_TAKE_HARMFUL_ABILITY
                                                | PROC_FLAG_TAKE_HELPFUL_SPELL | PROC_FLAG_TAKE_HARMFUL_SPELL
                                                | PROC_FLAG_TAKE_HARMFUL_PERIODIC | PROC_FLAG_TAKE_HELPFUL_PERIODIC
                                                | PROC_FLAG_TAKE_ANY_DAMAGE,

    REQ_SPELL_PHASE_PROC_FLAG_MASK              = SPELL_PROC_FLAG_MASK & DONE_HIT_PROC_FLAG_MASK
};

DEFINE_ENUM_FLAG(ProcFlags);

enum ProcFlags2 : int32
{
    PROC_FLAG_2_NONE                            = 0x00000000,
    PROC_FLAG_2_TARGET_DIES                     = 0x00000001,
    PROC_FLAG_2_KNOCKBACK                       = 0x00000002,
    PROC_FLAG_2_CAST_SUCCESSFUL                 = 0x00000004
};

DEFINE_ENUM_FLAG(ProcFlags2);

#define MELEE_BASED_TRIGGER_MASK (PROC_FLAG_DEAL_MELEE_SWING    | \
                                  PROC_FLAG_TAKE_MELEE_SWING    | \
                                  PROC_FLAG_DEAL_MELEE_ABILITY  | \
                                  PROC_FLAG_TAKE_MELEE_ABILITY  | \
                                  PROC_FLAG_DEAL_RANGED_ATTACK  | \
                                  PROC_FLAG_TAKE_RANGED_ATTACK  | \
                                  PROC_FLAG_DEAL_RANGED_ABILITY | \
                                  PROC_FLAG_TAKE_RANGED_ABILITY)

enum ProcFlagsSpellType : uint32
{
    PROC_SPELL_TYPE_NONE              = 0x0000000,
    PROC_SPELL_TYPE_DAMAGE            = 0x0000001, // damage type of spell
    PROC_SPELL_TYPE_HEAL              = 0x0000002, // heal type of spell
    PROC_SPELL_TYPE_NO_DMG_HEAL       = 0x0000004, // other spells
    PROC_SPELL_TYPE_MASK_ALL          = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_HEAL | PROC_SPELL_TYPE_NO_DMG_HEAL
};

DEFINE_ENUM_FLAG(ProcFlagsSpellType);

enum ProcFlagsSpellPhase : uint32
{
    PROC_SPELL_PHASE_NONE             = 0x0000000,
    PROC_SPELL_PHASE_CAST             = 0x0000001,
    PROC_SPELL_PHASE_HIT              = 0x0000002,
    PROC_SPELL_PHASE_FINISH           = 0x0000004,
    PROC_SPELL_PHASE_MASK_ALL         = PROC_SPELL_PHASE_CAST | PROC_SPELL_PHASE_HIT | PROC_SPELL_PHASE_FINISH
};

DEFINE_ENUM_FLAG(ProcFlagsSpellPhase);

enum ProcFlagsHit : uint32
{
    PROC_HIT_NONE                = 0x0000000, // no value - PROC_HIT_NORMAL | PROC_HIT_CRITICAL for TAKEN proc type, PROC_HIT_NORMAL | PROC_HIT_CRITICAL | PROC_HIT_ABSORB for DONE
    PROC_HIT_NORMAL              = 0x0000001, // non-critical hits
    PROC_HIT_CRITICAL            = 0x0000002,
    PROC_HIT_MISS                = 0x0000004,
    PROC_HIT_FULL_RESIST         = 0x0000008,
    PROC_HIT_DODGE               = 0x0000010,
    PROC_HIT_PARRY               = 0x0000020,
    PROC_HIT_BLOCK               = 0x0000040, // partial or full block
    PROC_HIT_EVADE               = 0x0000080,
    PROC_HIT_IMMUNE              = 0x0000100,
    PROC_HIT_DEFLECT             = 0x0000200,
    PROC_HIT_ABSORB              = 0x0000400, // partial or full absorb
    PROC_HIT_REFLECT             = 0x0000800,
    PROC_HIT_INTERRUPT           = 0x0001000,
    PROC_HIT_FULL_BLOCK          = 0x0002000,
    PROC_HIT_DISPEL              = 0x0004000,
    PROC_HIT_MASK_ALL            = 0x0007FFF
};

DEFINE_ENUM_FLAG(ProcFlagsHit);

enum ProcAttributes : uint32
{
    PROC_ATTR_NONE                      = 0x0000000,
    PROC_ATTR_REQ_EXP_OR_HONOR          = 0x0000001, // requires proc target to give exp or honor for aura proc
    PROC_ATTR_TRIGGERED_CAN_PROC        = 0x0000002, // aura can proc even with triggered spells
    PROC_ATTR_REQ_POWER_COST            = 0x0000004, // requires triggering spell to have a power cost for aura proc
    PROC_ATTR_REQ_SPELLMOD              = 0x0000008, // requires triggering spell to be affected by proccing aura to drop charges
    PROC_ATTR_USE_STACKS_FOR_CHARGES    = 0x0000010, // consuming proc drops a stack from proccing aura instead of charge

    PROC_ATTR_REDUCE_PROC_60            = 0x0000080, // aura should have a reduced chance to proc if level of proc Actor > 60
    PROC_ATTR_CANT_PROC_FROM_ITEM_CAST  = 0x0000100, // do not allow aura proc if proc is caused by a spell casted by item
};

DEFINE_ENUM_FLAG(ProcAttributes);

#define PROC_ATTR_ALL_ALLOWED (PROC_ATTR_REQ_EXP_OR_HONOR       | \
                               PROC_ATTR_TRIGGERED_CAN_PROC     | \
                               PROC_ATTR_REQ_POWER_COST         | \
                               PROC_ATTR_REQ_SPELLMOD           | \
                               PROC_ATTR_USE_STACKS_FOR_CHARGES | \
                               PROC_ATTR_REDUCE_PROC_60)

struct SpellProcEntry
{
    uint32 SchoolMask = 0;                                      // if nonzero - bitmask for matching proc condition based on spell's school
    uint32 SpellFamilyName = 0;                                 // if nonzero - for matching proc condition based on candidate spell's SpellFamilyName
    flag128 SpellFamilyMask;                                    // if nonzero - bitmask for matching proc condition based on candidate spell's SpellFamilyFlags
    ProcFlagsInit ProcFlags;                                    // if nonzero - overwrite procFlags field for given Spell.dbc entry, bitmask for matching proc condition, see enum ProcFlags
    ProcFlagsSpellType SpellTypeMask = PROC_SPELL_TYPE_NONE;    // if nonzero - bitmask for matching proc condition based on candidate spell's damage/heal effects, see enum ProcFlagsSpellType
    ProcFlagsSpellPhase SpellPhaseMask = PROC_SPELL_PHASE_NONE; // if nonzero - bitmask for matching phase of a spellcast on which proc occurs, see enum ProcFlagsSpellPhase
    ProcFlagsHit HitMask = PROC_HIT_NONE;                       // if nonzero - bitmask for matching proc condition based on hit result, see enum ProcFlagsHit
    ProcAttributes AttributesMask = PROC_ATTR_NONE;             // bitmask, see ProcAttributes
    uint32 DisableEffectsMask = 0;                              // bitmask
    float ProcsPerMinute = 0.0f;                                // if nonzero - chance to proc is equal to value * aura caster's weapon speed / 60
    float Chance = 0.0f;                                        // if nonzero - owerwrite procChance field for given Spell.dbc entry, defines chance of proc to occur, not used if ProcsPerMinute set
    Milliseconds Cooldown = 0ms;                                // if nonzero - cooldown in secs for aura proc, applied to aura
    uint32 Charges = 0;                                         // if nonzero - overwrite procCharges field for given Spell.dbc entry, defines how many times proc can occur before aura remove, 0 - infinite
};

enum EnchantProcAttributes
{
    ENCHANT_PROC_ATTR_WHITE_HIT  = 0x0000001, // enchant shall only proc off white hits (not abilities)
    ENCHANT_PROC_ATTR_LIMIT_60   = 0x0000002  // enchant effects shall be reduced past lvl 60
};

struct SpellEnchantProcEntry
{
    float       Chance;         // if nonzero - overwrite SpellItemEnchantment value
    float       ProcsPerMinute; // if nonzero - chance to proc is equal to value * aura caster's weapon speed / 60
    uint32      HitMask;        // if nonzero - bitmask for matching proc condition based on hit result, see enum ProcFlagsHit
    uint32      AttributesMask; // bitmask, see EnchantProcAttributes
};

typedef std::unordered_map<uint32, SpellEnchantProcEntry> SpellEnchantProcEventMap;

enum SpellGroup
{
    SPELL_GROUP_NONE             = 0,
    SPELL_GROUP_ELIXIR_BATTLE    = 1,
    SPELL_GROUP_ELIXIR_GUARDIAN  = 2,
    SPELL_GROUP_ELIXIR_UNSTABLE  = 3,
    SPELL_GROUP_ELIXIR_SHATTRATH = 4,
    SPELL_GROUP_CORE_RANGE_MAX   = 5
};

namespace std
{
    template<>
    struct hash<SpellGroup>
    {
        size_t operator()(SpellGroup const& group) const noexcept
        {
            return hash<uint32>()(uint32(group));
        }
    };
}

#define SPELL_GROUP_DB_RANGE_MIN 1000

//                  spell_id, group_id
typedef std::unordered_multimap<uint32, SpellGroup> SpellSpellGroupMap;
typedef std::pair<SpellSpellGroupMap::const_iterator, SpellSpellGroupMap::const_iterator> SpellSpellGroupMapBounds;

//                      group_id, spell_id
typedef std::unordered_multimap<SpellGroup, int32> SpellGroupSpellMap;
typedef std::pair<SpellGroupSpellMap::const_iterator, SpellGroupSpellMap::const_iterator> SpellGroupSpellMapBounds;

enum SpellGroupStackRule
{
    SPELL_GROUP_STACK_RULE_DEFAULT,
    SPELL_GROUP_STACK_RULE_EXCLUSIVE,
    SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER,
    SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT,
    SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST,
    SPELL_GROUP_STACK_RULE_MAX
};

typedef std::unordered_map<SpellGroup, SpellGroupStackRule> SpellGroupStackMap;

typedef std::unordered_map<SpellGroup, std::unordered_set<uint32 /*auraName*/>> SameEffectStackMap;

struct SpellThreatEntry
{
    int32       flatMod;                                    // flat threat-value for this Spell  - default: 0
    float       pctMod;                                     // threat-multiplier for this Spell  - default: 1.0f
    float       apPctMod;                                   // Pct of AP that is added as Threat - default: 0.0f
};

typedef std::unordered_map<uint32, SpellThreatEntry> SpellThreatMap;

// coordinates for spells (accessed using SpellMgr functions)
struct SpellTargetPosition
{
    uint32 target_mapId;
    float  target_X;
    float  target_Y;
    float  target_Z;
    float  target_Orientation;
};

typedef std::map<std::pair<uint32 /*spell_id*/, SpellEffIndex /*effIndex*/>, SpellTargetPosition> SpellTargetPositionMap;

// Enum with EffectRadiusIndex and their actual radius
enum EffectRadiusIndex
{
    EFFECT_RADIUS_2_YARDS       = 7,
    EFFECT_RADIUS_5_YARDS       = 8,
    EFFECT_RADIUS_20_YARDS      = 9,
    EFFECT_RADIUS_30_YARDS      = 10,
    EFFECT_RADIUS_45_YARDS      = 11,
    EFFECT_RADIUS_100_YARDS     = 12,
    EFFECT_RADIUS_10_YARDS      = 13,
    EFFECT_RADIUS_8_YARDS       = 14,
    EFFECT_RADIUS_3_YARDS       = 15,
    EFFECT_RADIUS_1_YARD        = 16,
    EFFECT_RADIUS_13_YARDS      = 17,
    EFFECT_RADIUS_15_YARDS      = 18,
    EFFECT_RADIUS_18_YARDS      = 19,
    EFFECT_RADIUS_25_YARDS      = 20,
    EFFECT_RADIUS_35_YARDS      = 21,
    EFFECT_RADIUS_200_YARDS     = 22,
    EFFECT_RADIUS_40_YARDS      = 23,
    EFFECT_RADIUS_65_YARDS      = 24,
    EFFECT_RADIUS_70_YARDS      = 25,
    EFFECT_RADIUS_4_YARDS       = 26,
    EFFECT_RADIUS_50_YARDS      = 27,
    EFFECT_RADIUS_50000_YARDS   = 28,
    EFFECT_RADIUS_6_YARDS       = 29,
    EFFECT_RADIUS_500_YARDS     = 30,
    EFFECT_RADIUS_80_YARDS      = 31,
    EFFECT_RADIUS_12_YARDS      = 32,
    EFFECT_RADIUS_99_YARDS      = 33,
    EFFECT_RADIUS_55_YARDS      = 35,
    EFFECT_RADIUS_0_YARDS       = 36,
    EFFECT_RADIUS_7_YARDS       = 37,
    EFFECT_RADIUS_21_YARDS      = 38,
    EFFECT_RADIUS_34_YARDS      = 39,
    EFFECT_RADIUS_9_YARDS       = 40,
    EFFECT_RADIUS_150_YARDS     = 41,
    EFFECT_RADIUS_11_YARDS      = 42,
    EFFECT_RADIUS_16_YARDS      = 43,
    EFFECT_RADIUS_0_5_YARDS     = 44,   // 0.5 yards
    EFFECT_RADIUS_10_YARDS_2    = 45,
    EFFECT_RADIUS_5_YARDS_2     = 46,
    EFFECT_RADIUS_15_YARDS_2    = 47,
    EFFECT_RADIUS_60_YARDS      = 48,
    EFFECT_RADIUS_90_YARDS      = 49,
    EFFECT_RADIUS_15_YARDS_3    = 50,
    EFFECT_RADIUS_60_YARDS_2    = 51,
    EFFECT_RADIUS_5_YARDS_3     = 52,
    EFFECT_RADIUS_60_YARDS_3    = 53,
    EFFECT_RADIUS_50000_YARDS_2 = 54,
    EFFECT_RADIUS_130_YARDS     = 55,
    EFFECT_RADIUS_38_YARDS      = 56,
    EFFECT_RADIUS_45_YARDS_2    = 57,
    EFFECT_RADIUS_32_YARDS      = 59,
    EFFECT_RADIUS_44_YARDS      = 60,
    EFFECT_RADIUS_14_YARDS      = 61,
    EFFECT_RADIUS_47_YARDS      = 62,
    EFFECT_RADIUS_23_YARDS      = 63,
    EFFECT_RADIUS_3_5_YARDS     = 64,   // 3.5 yards
    EFFECT_RADIUS_80_YARDS_2    = 65
};

// Spell pet auras
class TC_GAME_API PetAura
{
    private:
        typedef std::unordered_map<uint32, uint32> PetAuraMap;

    public:
        PetAura() : removeOnChangePet(false), damage(0) { }

        PetAura(uint32 petEntry, uint32 aura, bool _removeOnChangePet, int _damage) :
        removeOnChangePet(_removeOnChangePet), damage(_damage)
        {
            auras[petEntry] = aura;
        }

        uint32 GetAura(uint32 petEntry) const
        {
            PetAuraMap::const_iterator itr = auras.find(petEntry);
            if (itr != auras.end())
                return itr->second;
            PetAuraMap::const_iterator itr2 = auras.find(0);
            if (itr2 != auras.end())
                return itr2->second;
            return 0;
        }

        void AddAura(uint32 petEntry, uint32 aura)
        {
            auras[petEntry] = aura;
        }

        bool IsRemovedOnChangePet() const
        {
            return removeOnChangePet;
        }

        int32 GetDamage() const
        {
            return damage;
        }

    private:
        PetAuraMap auras;
        bool removeOnChangePet;
        int32 damage;
};
typedef std::map<uint32, PetAura> SpellPetAuraMap;

enum SpellAreaFlag
{
    SPELL_AREA_FLAG_AUTOCAST                                = 0x1, // if has autocast, spell is applied on enter
    SPELL_AREA_FLAG_AUTOREMOVE                              = 0x2, // if has autoremove, spell is remove automatically inside zone/area (always removed on leaving area or zone)
    SPELL_AREA_FLAG_IGNORE_AUTOCAST_ON_QUEST_STATUS_CHANGE  = 0x4, // if this flag is set then spell will not be applied automatically on quest status change
};

struct TC_GAME_API SpellArea
{
    uint32 spellId;
    uint32 areaId;                                          // zone/subzone/or 0 is not limited to zone
    uint32 questStart;                                      // quest start (quest must be active or rewarded for spell apply)
    uint32 questEnd;                                        // quest end (quest must not be rewarded for spell apply)
    int32  auraSpell;                                       // spell aura must be applied for spell apply)if possitive) and it must not be applied in other case
    Trinity::RaceMask<uint64> raceMask;                     // can be applied only to races
    Gender gender;                                          // can be applied only to gender
    uint32 questStartStatus;                                // QuestStatus that quest_start must have in order to keep the spell
    uint32 questEndStatus;                                  // QuestStatus that the quest_end must have in order to keep the spell (if the quest_end's status is different than this, the spell will be dropped)
    uint8 flags;                                            // if SPELL_AREA_FLAG_AUTOCAST then auto applied at area enter, in other case just allowed to cast || if SPELL_AREA_FLAG_AUTOREMOVE then auto removed inside area (will allways be removed on leaved even without flag)

    // helpers
    bool IsFitToRequirements(Player const* player, uint32 newZone, uint32 newArea) const;
};

typedef std::multimap<uint32, SpellArea> SpellAreaMap;
typedef std::multimap<uint32, SpellArea const*> SpellAreaForQuestMap;
typedef std::multimap<uint32, SpellArea const*> SpellAreaForAuraMap;
typedef std::multimap<uint32, SpellArea const*> SpellAreaForAreaMap;
typedef std::pair<SpellAreaMap::const_iterator, SpellAreaMap::const_iterator> SpellAreaMapBounds;
typedef std::pair<SpellAreaForQuestMap::const_iterator, SpellAreaForQuestMap::const_iterator> SpellAreaForQuestMapBounds;
typedef std::pair<SpellAreaForAuraMap::const_iterator, SpellAreaForAuraMap::const_iterator> SpellAreaForAuraMapBounds;
typedef std::pair<SpellAreaForAreaMap::const_iterator, SpellAreaForAreaMap::const_iterator> SpellAreaForAreaMapBounds;

// Spell rank chain  (accessed using SpellMgr functions)
struct SpellChainNode
{
    SpellInfo const* prev;
    SpellInfo const* next;
    SpellInfo const* first;
    SpellInfo const* last;
    uint8  rank;
};

typedef std::unordered_map<uint32, SpellChainNode> SpellChainMap;

//                   spell_id  req_spell
typedef std::multimap<uint32, uint32> SpellRequiredMap;
typedef std::pair<SpellRequiredMap::const_iterator, SpellRequiredMap::const_iterator> SpellRequiredMapBounds;

//                   req_spell spell_id
typedef std::multimap<uint32, uint32> SpellsRequiringSpellMap;
typedef std::pair<SpellsRequiringSpellMap::const_iterator, SpellsRequiringSpellMap::const_iterator> SpellsRequiringSpellMapBounds;

// Spell learning properties (accessed using SpellMgr functions)
struct SpellLearnSkillNode
{
    uint16 skill;
    uint16 step;
    uint16 value;                                           // 0  - max skill value for player level
    uint16 maxvalue;                                        // 0  - max skill value for player level
};

typedef std::unordered_map<uint32, SpellLearnSkillNode> SpellLearnSkillMap;

struct SpellLearnSpellNode
{
    uint32 Spell;
    uint32 OverridesSpell;
    bool Active;                    // show in spellbook or not
    bool AutoLearned;               // This marks the spell as automatically learned from another source that - will only be used for unlearning
};

enum class SpellOtherImmunity : uint8
{
    None        = 0x0,
    AoETarget   = 0x1,
    ChainTarget = 0x2
};

DEFINE_ENUM_FLAG(SpellOtherImmunity)

struct CreatureImmunities
{
    std::bitset<MAX_SPELL_SCHOOL> School;
    std::bitset<DISPEL_MAX> DispelType;
    std::bitset<MAX_MECHANIC> Mechanic;
    std::vector<SpellEffectName> Effect;
    std::vector<AuraType> Aura;
    EnumFlag<SpellOtherImmunity> Other = SpellOtherImmunity::None;
};

typedef std::multimap<uint32, SpellLearnSpellNode> SpellLearnSpellMap;
typedef std::pair<SpellLearnSpellMap::const_iterator, SpellLearnSpellMap::const_iterator> SpellLearnSpellMapBounds;

typedef std::multimap<uint32, SkillLineAbilityEntry const*> SkillLineAbilityMap;
typedef std::pair<SkillLineAbilityMap::const_iterator, SkillLineAbilityMap::const_iterator> SkillLineAbilityMapBounds;

typedef std::set<uint32> PetFamilySpellsSet;
typedef std::map<uint32, PetFamilySpellsSet> PetFamilySpellsStore;

typedef std::multimap<uint32, uint32> PetLevelupSpellSet;
typedef std::map<uint32, PetLevelupSpellSet> PetLevelupSpellMap;

typedef std::map<uint32, uint32> SpellDifficultySearcherMap;

#define MAX_CREATURE_SPELL_DATA_SLOT 4

struct PetDefaultSpellsEntry
{
    uint32 spellid[MAX_CREATURE_SPELL_DATA_SLOT];
};

// < 0 for petspelldata id, > 0 for creature_id
typedef std::map<int32, PetDefaultSpellsEntry> PetDefaultSpellsMap;

typedef std::unordered_map<std::pair<SpellLinkedType, uint32>, std::vector<int32>> SpellLinkedMap;

bool IsPrimaryProfessionSkill(uint32 skill);

bool IsWeaponSkill(uint32 skill);

inline bool IsProfessionSkill(uint32 skill)
{
    return IsPrimaryProfessionSkill(skill) || skill == SKILL_FISHING || skill == SKILL_COOKING;
}

inline bool IsProfessionOrRidingSkill(uint32 skill)
{
    return IsProfessionSkill(skill) || skill == SKILL_RIDING;
}

bool IsPartOfSkillLine(uint32 skillId, uint32 spellId);

TC_GAME_API extern PetFamilySpellsStore                         sPetFamilySpellsStore;

struct SpellInfoLoadHelper
{
    SpellAuraOptionsEntry const* AuraOptions = nullptr;
    SpellAuraRestrictionsEntry const* AuraRestrictions = nullptr;
    SpellCastingRequirementsEntry const* CastingRequirements = nullptr;
    SpellCategoriesEntry const* Categories = nullptr;
    SpellClassOptionsEntry const* ClassOptions = nullptr;
    SpellCooldownsEntry const* Cooldowns = nullptr;
    std::array<SpellEffectEntry const*, MAX_SPELL_EFFECTS> Effects = { };
    SpellEquippedItemsEntry const* EquippedItems = nullptr;
    SpellInterruptsEntry const* Interrupts = nullptr;
    std::vector<SpellLabelEntry const*> Labels;
    SpellLevelsEntry const* Levels = nullptr;
    SpellMiscEntry const* Misc = nullptr;
    std::array<SpellPowerEntry const*, MAX_POWERS_PER_SPELL> Powers = { };
    SpellReagentsEntry const* Reagents = nullptr;
    std::vector<SpellReagentsCurrencyEntry const*> ReagentsCurrency;
    SpellScalingEntry const* Scaling = nullptr;
    SpellShapeshiftEntry const* Shapeshift = nullptr;
    SpellTargetRestrictionsEntry const* TargetRestrictions = nullptr;
    SpellTotemsEntry const* Totems = nullptr;
    std::vector<SpellXSpellVisualEntry const*> Visuals; // only to group visuals when parsing sSpellXSpellVisualStore, not for loading
};

typedef std::map<std::pair<uint32 /*SpellId*/, uint8 /*RaceId*/>, uint32 /*DisplayId*/> SpellTotemModelMap;

class TC_GAME_API SpellMgr
{
    // Constructors
    private:
        SpellMgr();
        ~SpellMgr();

    // Accessors (const or static functions)
    public:
        SpellMgr(SpellMgr const& right) = delete;
        SpellMgr(SpellMgr&& right) = delete;
        SpellMgr& operator=(SpellMgr const& right) = delete;
        SpellMgr& operator=(SpellMgr&& right) = delete;

        static SpellMgr* instance();

        // Spell correctness for client using
        static bool IsSpellValid(SpellInfo const* spellInfo, Player* player = nullptr, bool msg = true);

        // Spell Ranks table
        SpellChainNode const* GetSpellChainNode(uint32 spell_id) const;
        uint32 GetFirstSpellInChain(uint32 spell_id) const;
        uint32 GetLastSpellInChain(uint32 spell_id) const;
        uint32 GetNextSpellInChain(uint32 spell_id) const;
        uint32 GetPrevSpellInChain(uint32 spell_id) const;
        uint8 GetSpellRank(uint32 spell_id) const;
        // not strict check returns provided spell if rank not avalible
        uint32 GetSpellWithRank(uint32 spell_id, uint32 rank, bool strict = false) const;

        // Spell Required table
        Trinity::IteratorPair<SpellRequiredMap::const_iterator> GetSpellsRequiredForSpellBounds(uint32 spell_id) const;
        SpellsRequiringSpellMapBounds GetSpellsRequiringSpellBounds(uint32 spell_id) const;
        bool IsSpellRequiringSpell(uint32 spellid, uint32 req_spellid) const;

        // Spell learning
        SpellLearnSkillNode const* GetSpellLearnSkill(uint32 spell_id) const;
        SpellLearnSpellMapBounds GetSpellLearnSpellMapBounds(uint32 spell_id) const;
        bool IsSpellLearnSpell(uint32 spell_id) const;
        bool IsSpellLearnToSpell(uint32 spell_id1, uint32 spell_id2) const;

        // Spell target coordinates
        SpellTargetPosition const* GetSpellTargetPosition(uint32 spell_id, SpellEffIndex effIndex) const;

        // Spell Groups table
        SpellSpellGroupMapBounds GetSpellSpellGroupMapBounds(uint32 spell_id) const;
        bool IsSpellMemberOfSpellGroup(uint32 spellid, SpellGroup groupid) const;

        SpellGroupSpellMapBounds GetSpellGroupSpellMapBounds(SpellGroup group_id) const;
        void GetSetOfSpellsInSpellGroup(SpellGroup group_id, std::set<uint32>& foundSpells) const;
        void GetSetOfSpellsInSpellGroup(SpellGroup group_id, std::set<uint32>& foundSpells, std::set<SpellGroup>& usedGroups) const;

        // Spell Group Stack Rules table
        bool AddSameEffectStackRuleSpellGroups(SpellInfo const* spellInfo, uint32 auraType, int32 amount, std::map<SpellGroup, int32>& groups) const;
        SpellGroupStackRule CheckSpellGroupStackRules(SpellInfo const* spellInfo1, SpellInfo const* spellInfo2) const;
        SpellGroupStackRule GetSpellGroupStackRule(SpellGroup groupid) const;

        // Spell proc table
        SpellProcEntry const* GetSpellProcEntry(SpellInfo const* spellInfo) const;
        static bool CanSpellTriggerProcOnEvent(SpellProcEntry const& procEntry, ProcEventInfo& eventInfo);

        // Spell threat table
        SpellThreatEntry const* GetSpellThreatEntry(uint32 spellID) const;

        SkillLineAbilityMapBounds GetSkillLineAbilityMapBounds(uint32 spell_id) const;

        PetAura const* GetPetAura(uint32 spell_id, uint8 eff) const;

        SpellEnchantProcEntry const* GetSpellEnchantProcEvent(uint32 enchId) const;
        bool IsArenaAllowedEnchancment(uint32 ench_id) const;

        std::vector<int32> const* GetSpellLinked(SpellLinkedType type, uint32 spell_id) const;

        PetLevelupSpellSet const* GetPetLevelupSpellList(uint32 petFamily) const;
        PetDefaultSpellsEntry const* GetPetDefaultSpellsEntry(int32 id) const;

        // Spell area
        SpellAreaMapBounds GetSpellAreaMapBounds(uint32 spell_id) const;
        SpellAreaForQuestMapBounds GetSpellAreaForQuestMapBounds(uint32 quest_id) const;
        SpellAreaForQuestMapBounds GetSpellAreaForQuestEndMapBounds(uint32 quest_id) const;
        SpellAreaForAuraMapBounds GetSpellAreaForAuraMapBounds(uint32 spell_id) const;
        SpellAreaForAreaMapBounds GetSpellAreaForAreaMapBounds(uint32 area_id) const;

        // Immunities
        static CreatureImmunities const* GetCreatureImmunities(int32 creatureImmunitiesId);

        // SpellInfo object management
        SpellInfo const* GetSpellInfo(uint32 spellId, Difficulty difficulty) const;

        // Use this only with 100% valid spellIds
        SpellInfo const* AssertSpellInfo(uint32 spellId, Difficulty difficulty) const
        {
            SpellInfo const* spellInfo = GetSpellInfo(spellId, difficulty);
            ASSERT(spellInfo);
            return spellInfo;
        }

        void ForEachSpellInfo(std::function<void(SpellInfo const*)> callback);
        void ForEachSpellInfoDifficulty(uint32 spellId, std::function<void(SpellInfo const*)> callback);

        void LoadPetFamilySpellsStore();

        uint32 GetModelForTotem(uint32 spellId, uint8 race) const;

    // Modifiers
    public:

        // Loading data at server startup
        void UnloadSpellInfoChains();
        void LoadSpellRanks();
        void LoadSpellRequired();
        void LoadSpellLearnSkills();
        void LoadSpellLearnSpells();
        void LoadSpellTargetPositions();
        void LoadSpellGroups();
        void LoadSpellGroupStackRules();
        void LoadSpellProcs();
        void LoadSpellThreats();
        void LoadSkillLineAbilityMap();
        void LoadSpellPetAuras();
        void LoadSpellEnchantProcData();
        void LoadSpellLinked();
        void LoadPetLevelupSpellMap();
        void LoadPetDefaultSpells();
        void LoadSpellAreas();
        void LoadSpellInfoStore();
        void UnloadSpellInfoStore();
        void UnloadSpellInfoImplicitTargetConditionLists();
        void LoadSpellInfoServerside();
        void LoadSpellInfoCustomAttributes();
        void LoadSpellInfoCorrections();
        void LoadSpellInfoSpellSpecificAndAuraState();
        void LoadSpellInfoDiminishing();
        void LoadSpellInfoImmunities();
        void LoadSpellTotemModel();

    private:
        SpellDifficultySearcherMap mSpellDifficultySearcherMap;
        SpellChainMap              mSpellChains;
        SpellsRequiringSpellMap    mSpellsReqSpell;
        SpellRequiredMap           mSpellReq;
        SpellLearnSkillMap         mSpellLearnSkills;
        SpellLearnSpellMap         mSpellLearnSpells;
        SpellTargetPositionMap     mSpellTargetPositions;
        SpellSpellGroupMap         mSpellSpellGroup;
        SpellGroupSpellMap         mSpellGroupSpell;
        SpellGroupStackMap         mSpellGroupStack;
        SameEffectStackMap         mSpellSameEffectStack;
        SpellThreatMap             mSpellThreatMap;
        SpellPetAuraMap            mSpellPetAuraMap;
        SpellLinkedMap             mSpellLinkedMap;
        SpellEnchantProcEventMap   mSpellEnchantProcEventMap;
        SpellAreaMap               mSpellAreaMap;
        SpellAreaForQuestMap       mSpellAreaForQuestMap;
        SpellAreaForQuestMap       mSpellAreaForQuestEndMap;
        SpellAreaForAuraMap        mSpellAreaForAuraMap;
        SpellAreaForAreaMap        mSpellAreaForAreaMap;
        SkillLineAbilityMap        mSkillLineAbilityMap;
        PetLevelupSpellMap         mPetLevelupSpellMap;
        PetDefaultSpellsMap        mPetDefaultSpellsMap;           // only spells not listed in related mPetLevelupSpellMap entry
        SpellTotemModelMap         mSpellTotemModel;
};

#define sSpellMgr SpellMgr::instance()

#endif
