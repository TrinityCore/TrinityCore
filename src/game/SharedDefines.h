/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_SHAREDDEFINES_H
#define TRINITY_SHAREDDEFINES_H

#include "Platform/Define.h"
#include <cassert>

enum Gender
{
    GENDER_MALE                        = 0,
    GENDER_FEMALE                      = 1,
    GENDER_NONE                        = 2
};

// Race value is index in ChrRaces.dbc
enum Races
{
    RACE_HUMAN          = 1,
    RACE_ORC            = 2,
    RACE_DWARF          = 3,
    RACE_NIGHTELF       = 4,
    RACE_UNDEAD_PLAYER  = 5,
    RACE_TAUREN         = 6,
    RACE_GNOME          = 7,
    RACE_TROLL          = 8,
    //RACE_GOBLIN         = 9,
    RACE_BLOODELF       = 10,
    RACE_DRAENEI        = 11,
    //RACE_FEL_ORC        = 12,
    //RACE_NAGA           = 13,
    //RACE_BROKEN         = 14,
    //RACE_SKELETON       = 15,
    //RACE_VRYKUL         = 16,
    //RACE_TUSKARR        = 17,
    //RACE_FOREST_TROLL   = 18,
    //RACE_TAUNKA         = 19,
    //RACE_NORTHREND_SKELETON = 20,
    //RACE_ICE_TROLL      = 21
};

// max+1 for player race
#define MAX_RACES         12

#define RACEMASK_ALL_PLAYABLE \
    ((1<<(RACE_HUMAN-1))   |(1<<(RACE_ORC-1))          |(1<<(RACE_DWARF-1))   | \
    (1<<(RACE_NIGHTELF-1))|(1<<(RACE_UNDEAD_PLAYER-1))|(1<<(RACE_TAUREN-1))  | \
    (1<<(RACE_GNOME-1))   |(1<<(RACE_TROLL-1))        |(1<<(RACE_BLOODELF-1))| \
    (1<<(RACE_DRAENEI-1)) )

// Class value is index in ChrClasses.dbc
enum Classes
{
    CLASS_WARRIOR       = 1,
    CLASS_PALADIN       = 2,
    CLASS_HUNTER        = 3,
    CLASS_ROGUE         = 4,
    CLASS_PRIEST        = 5,
    CLASS_DEATH_KNIGHT  = 6,
    CLASS_SHAMAN        = 7,
    CLASS_MAGE          = 8,
    CLASS_WARLOCK       = 9,
    // CLASS_UNK2       = 10,unused
    CLASS_DRUID         = 11,
};

// max+1 for player class
#define MAX_CLASSES       12

#define CLASSMASK_ALL_PLAYABLE \
    ((1<<(CLASS_WARRIOR-1))|(1<<(CLASS_PALADIN-1))|(1<<(CLASS_HUNTER-1))| \
    (1<<(CLASS_ROGUE-1))  |(1<<(CLASS_PRIEST-1)) |(1<<(CLASS_SHAMAN-1))| \
    (1<<(CLASS_MAGE-1))   |(1<<(CLASS_WARLOCK-1))|(1<<(CLASS_DRUID-1))   )

#define CLASSMASK_WAND_USERS ((1<<(CLASS_PRIEST-1))|(1<<(CLASS_MAGE-1))|(1<<(CLASS_WARLOCK-1)))

#define PLAYER_MAX_BATTLEGROUND_QUEUES 3

enum ReputationRank
{
    REP_HATED       = 0,
    REP_HOSTILE     = 1,
    REP_UNFRIENDLY  = 2,
    REP_NEUTRAL     = 3,
    REP_FRIENDLY    = 4,
    REP_HONORED     = 5,
    REP_REVERED     = 6,
    REP_EXALTED     = 7
};

#define MIN_REPUTATION_RANK (REP_HATED)
#define MAX_REPUTATION_RANK 8

enum MoneyConstants
{
    COPPER = 1,
    SILVER = COPPER*100,
    GOLD   = SILVER*100
};

enum Stats
{
    STAT_STRENGTH                      = 0,
    STAT_AGILITY                       = 1,
    STAT_STAMINA                       = 2,
    STAT_INTELLECT                     = 3,
    STAT_SPIRIT                        = 4
};

#define MAX_STATS                        5

enum Powers
{
    POWER_MANA                          = 0,
    POWER_RAGE                          = 1,
    POWER_FOCUS                         = 2,
    POWER_ENERGY                        = 3,
    POWER_HAPPINESS                     = 4,
    POWER_RUNES                         = 5,
    POWER_HEALTH                        = 0xFFFFFFFE    // (-2 as signed value)
};

#define MAX_POWERS                        5                 // not count POWER_RUNES for now

enum SpellSchools
{
    SPELL_SCHOOL_NORMAL                 = 0,
    SPELL_SCHOOL_HOLY                   = 1,
    SPELL_SCHOOL_FIRE                   = 2,
    SPELL_SCHOOL_NATURE                 = 3,
    SPELL_SCHOOL_FROST                  = 4,
    SPELL_SCHOOL_SHADOW                 = 5,
    SPELL_SCHOOL_ARCANE                 = 6
};

#define MAX_SPELL_SCHOOL                  7

enum SpellSchoolMask
{
    SPELL_SCHOOL_MASK_NONE    = 0x00,                       // not exist
    SPELL_SCHOOL_MASK_NORMAL  = (1 << SPELL_SCHOOL_NORMAL), // PHYSICAL (Armor)
    SPELL_SCHOOL_MASK_HOLY    = (1 << SPELL_SCHOOL_HOLY  ),
    SPELL_SCHOOL_MASK_FIRE    = (1 << SPELL_SCHOOL_FIRE  ),
    SPELL_SCHOOL_MASK_NATURE  = (1 << SPELL_SCHOOL_NATURE),
    SPELL_SCHOOL_MASK_FROST   = (1 << SPELL_SCHOOL_FROST ),
    SPELL_SCHOOL_MASK_SHADOW  = (1 << SPELL_SCHOOL_SHADOW),
    SPELL_SCHOOL_MASK_ARCANE  = (1 << SPELL_SCHOOL_ARCANE),

    // unions

    // 124, not include normal and holy damage
    SPELL_SCHOOL_MASK_SPELL   = ( SPELL_SCHOOL_MASK_FIRE   |
                                  SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_FROST  |
                                  SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE ),
    // 126
    SPELL_SCHOOL_MASK_MAGIC   = ( SPELL_SCHOOL_MASK_HOLY | SPELL_SCHOOL_MASK_SPELL ),

    // 127
    SPELL_SCHOOL_MASK_ALL     = ( SPELL_SCHOOL_MASK_NORMAL | SPELL_SCHOOL_MASK_MAGIC )
};

#define SPELL_SCHOOL_MASK_MAGIC                            \
    ( SPELL_SCHOOL_MASK_HOLY | SPELL_SCHOOL_MASK_FIRE | SPELL_SCHOOL_MASK_NATURE |  \
      SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_SHADOW | \
      SPELL_SCHOOL_MASK_ARCANE )

inline SpellSchools GetFirstSchoolInMask(SpellSchoolMask mask)
{
    for(int i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if(mask & (1 << i))
            return SpellSchools(i);

    return SPELL_SCHOOL_NORMAL;
}

enum ItemQualities
{
    ITEM_QUALITY_POOR                  = 0,                 //GREY
    ITEM_QUALITY_NORMAL                = 1,                 //WHITE
    ITEM_QUALITY_UNCOMMON              = 2,                 //GREEN
    ITEM_QUALITY_RARE                  = 3,                 //BLUE
    ITEM_QUALITY_EPIC                  = 4,                 //PURPLE
    ITEM_QUALITY_LEGENDARY             = 5,                 //ORANGE
    ITEM_QUALITY_ARTIFACT              = 6                  //LIGHT YELLOW
};

#define MAX_ITEM_QUALITY                 7

enum SpellCategory
{
    SPELL_CATEGORY_FOOD             = 11,
    SPELL_CATEGORY_DRINK            = 59,
};

// ***********************************
// Spell Attributes definitions
// ***********************************

#define SPELL_ATTR_UNK0                           0x00000001            // 0
#define SPELL_ATTR_RANGED                         0x00000002            // 1 All ranged abilities have this flag
#define SPELL_ATTR_ON_NEXT_SWING_1                0x00000004            // 2 on next swing
#define SPELL_ATTR_UNK3                           0x00000008            // 3 not set in 2.4.2
#define SPELL_ATTR_UNK4                           0x00000010            // 4
#define SPELL_ATTR_UNK5                           0x00000020            // 5 trade spells?
#define SPELL_ATTR_PASSIVE                        0x00000040            // 6 Passive spell
#define SPELL_ATTR_UNK7                           0x00000080            // 7 visible?
#define SPELL_ATTR_UNK8                           0x00000100            // 8
#define SPELL_ATTR_UNK9                           0x00000200            // 9
#define SPELL_ATTR_ON_NEXT_SWING_2                0x00000400            // 10 on next swing 2
#define SPELL_ATTR_UNK11                          0x00000800            // 11
#define SPELL_ATTR_DAYTIME_ONLY                   0x00001000            // 12 only useable at daytime, not set in 2.4.2
#define SPELL_ATTR_NIGHT_ONLY                     0x00002000            // 13 only useable at night, not set in 2.4.2
#define SPELL_ATTR_INDOORS_ONLY                   0x00004000            // 14 only useable indoors, not set in 2.4.2
#define SPELL_ATTR_OUTDOORS_ONLY                  0x00008000            // 15 Only useable outdoors.
#define SPELL_ATTR_NOT_SHAPESHIFT                 0x00010000            // 16 Not while shapeshifted
#define SPELL_ATTR_ONLY_STEALTHED                 0x00020000            // 17 Must be in stealth
#define SPELL_ATTR_UNK18                          0x00040000            // 18
#define SPELL_ATTR_LEVEL_DAMAGE_CALCULATION       0x00080000            // 19 spelldamage depends on caster level
#define SPELL_ATTR_STOP_ATTACK_TARGET             0x00100000            // 20 Stop attack after use this spell (and not begin attack if use)
#define SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK   0x00200000            // 21 Cannot be dodged/parried/blocked
#define SPELL_ATTR_UNK22                          0x00400000            // 22 shoot spells
#define SPELL_ATTR_UNK23                          0x00800000            // 23 castable while dead?
#define SPELL_ATTR_CASTABLE_WHILE_MOUNTED         0x01000000            // 24 castable while mounted
#define SPELL_ATTR_DISABLED_WHILE_ACTIVE          0x02000000            // 25 Activate and start cooldown after aura fade or remove summoned creature or go
#define SPELL_ATTR_UNK26                          0x04000000            // 26 Aura ignore immune?
#define SPELL_ATTR_CASTABLE_WHILE_SITTING         0x08000000            // 27 castable while sitting
#define SPELL_ATTR_CANT_USED_IN_COMBAT            0x10000000            // 28 Cannot be used in combat
#define SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY  0x20000000            // 29 unaffected by invulnerability (hmm possible not...)
#define SPELL_ATTR_BREAKABLE_BY_DAMAGE            0x40000000            // 30 breakable by damage?
#define SPELL_ATTR_CANT_CANCEL                    0x80000000            // 31 positive aura can't be canceled

#define SPELL_ATTR_EX_UNK0                        0x00000001            // 0
#define SPELL_ATTR_EX_DRAIN_ALL_POWER             0x00000002            // 1 use all power (Only paladin Lay of Hands and Bunyanize)
#define SPELL_ATTR_EX_CHANNELED_1                 0x00000004            // 2 channeled 1
#define SPELL_ATTR_EX_UNK3                        0x00000008            // 3
#define SPELL_ATTR_EX_UNK4                        0x00000010            // 4
#define SPELL_ATTR_EX_NOT_BREAK_STEALTH           0x00000020            // 5 Not break stealth
#define SPELL_ATTR_EX_CHANNELED_2                 0x00000040            // 6 channeled 2
#define SPELL_ATTR_EX_NEGATIVE                    0x00000080            // 7
#define SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET        0x00000100            // 8 Spell req target not to be in combat state
#define SPELL_ATTR_EX_UNK9                        0x00000200            // 9
#define SPELL_ATTR_EX_UNK10                       0x00000400            // 10
#define SPELL_ATTR_EX_UNK11                       0x00000800            // 11
#define SPELL_ATTR_EX_UNK12                       0x00001000            // 12
#define SPELL_ATTR_EX_UNK13                       0x00002000            // 13
#define SPELL_ATTR_EX_UNK14                       0x00004000            // 14
#define SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY    0x00008000            // 15 remove auras on immunity
#define SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE 0x00010000            // 16 unaffected by school immunity
#define SPELL_ATTR_EX_UNAUTOCASTABLE_BY_PET       0x00020000            // 17
#define SPELL_ATTR_EX_UNK18                       0x00040000            // 18
#define SPELL_ATTR_EX_UNK19                       0x00080000            // 19
#define SPELL_ATTR_EX_REQ_COMBO_POINTS1           0x00100000            // 20 Req combo points on target
#define SPELL_ATTR_EX_UNK21                       0x00200000            // 21
#define SPELL_ATTR_EX_REQ_COMBO_POINTS2           0x00400000            // 22 Req combo points on target
#define SPELL_ATTR_EX_UNK23                       0x00800000            // 23
#define SPELL_ATTR_EX_UNK24                       0x01000000            // 24 Req fishing pole??
#define SPELL_ATTR_EX_UNK25                       0x02000000            // 25 not set in 2.4.2
#define SPELL_ATTR_EX_UNK26                       0x04000000            // 26
#define SPELL_ATTR_EX_UNK27                       0x08000000            // 27
#define SPELL_ATTR_EX_UNK28                       0x10000000            // 28
#define SPELL_ATTR_EX_UNK29                       0x20000000            // 29
#define SPELL_ATTR_EX_UNK30                       0x40000000            // 30 overpower
#define SPELL_ATTR_EX_UNK31                       0x80000000            // 31

#define SPELL_ATTR_EX2_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX2_UNK1                       0x00000002            // 1
#define SPELL_ATTR_EX2_UNK2                       0x00000004            // 2 boss spells?
#define SPELL_ATTR_EX2_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX2_UNK4                       0x00000010            // 4
#define SPELL_ATTR_EX2_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX2_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX2_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX2_UNK8                       0x00000100            // 8 not set in 2.4.2
#define SPELL_ATTR_EX2_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX2_UNK10                      0x00000400            // 10
#define SPELL_ATTR_EX2_HEALTH_FUNNEL              0x00000800            // 11
#define SPELL_ATTR_EX2_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX2_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX2_UNK14                      0x00004000            // 14
#define SPELL_ATTR_EX2_UNK15                      0x00008000            // 15 not set in 2.4.2
#define SPELL_ATTR_EX2_TAME_BEAST                 0x00010000            // 16
#define SPELL_ATTR_EX2_NOT_RESET_AUTOSHOT         0x00020000            // 17 Hunters Shot and Stings only have this flag
#define SPELL_ATTR_EX2_UNK18                      0x00040000            // 18 Only Revive pet - possible req dead pet
#define SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT        0x00080000            // 19 does not necessarly need shapeshift
#define SPELL_ATTR_EX2_UNK20                      0x00100000            // 20
#define SPELL_ATTR_EX2_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX2_UNK22                      0x00400000            // 22
#define SPELL_ATTR_EX2_UNK23                      0x00800000            // 23 Only mage Arcane Concentration have this flag
#define SPELL_ATTR_EX2_UNK24                      0x01000000            // 24
#define SPELL_ATTR_EX2_UNK25                      0x02000000            // 25
#define SPELL_ATTR_EX2_UNK26                      0x04000000            // 26 unaffected by school immunity
#define SPELL_ATTR_EX2_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX2_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX2_CANT_CRIT                  0x20000000            // 29 Spell can't crit
#define SPELL_ATTR_EX2_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX2_FOOD                       0x80000000            // 31 food, well-fed, and a few others

#define SPELL_ATTR_EX3_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX3_UNK1                       0x00000002            // 1
#define SPELL_ATTR_EX3_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX3_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX3_UNK4                       0x00000010            // 4 Druid Rebirth only this spell have this flag
#define SPELL_ATTR_EX3_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX3_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX3_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX3_PLAYERS_ONLY               0x00000100            // 8 Player only?
#define SPELL_ATTR_EX3_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX3_MAIN_HAND                  0x00000400            // 10 Main hand weapon required
#define SPELL_ATTR_EX3_BATTLEGROUND               0x00000800            // 11 Can casted only on battleground
#define SPELL_ATTR_EX3_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX3_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX3_UNK14                      0x00004000            // 14 "Honorless Target" only this spells have this flag
#define SPELL_ATTR_EX3_UNK15                      0x00008000            // 15 Auto Shoot, Shoot, Throw,  - this is autoshot flag
#define SPELL_ATTR_EX3_UNK16                      0x00010000            // 16
#define SPELL_ATTR_EX3_NO_INITIAL_AGGRO           0x00020000            // 17 no initial aggro
#define SPELL_ATTR_EX3_UNK18                      0x00040000            // 18
#define SPELL_ATTR_EX3_UNK19                      0x00080000            // 19
#define SPELL_ATTR_EX3_DEATH_PERSISTENT           0x00100000            // 20 Death persistent spells
#define SPELL_ATTR_EX3_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX3_REQ_WAND                   0x00400000            // 22 Req wand
#define SPELL_ATTR_EX3_UNK23                      0x00800000            // 23
#define SPELL_ATTR_EX3_REQ_OFFHAND                0x01000000            // 24 Req offhand weapon
#define SPELL_ATTR_EX3_UNK25                      0x02000000            // 25
#define SPELL_ATTR_EX3_UNK26                      0x04000000            // 26
#define SPELL_ATTR_EX3_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX3_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX3_UNK29                      0x20000000            // 29
#define SPELL_ATTR_EX3_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX3_UNK31                      0x80000000            // 31

#define SPELL_ATTR_EX4_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX4_UNK1                       0x00000002            // 1 proc on finishing move?
#define SPELL_ATTR_EX4_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX4_CANT_PROC_FROM_SELFCAST    0x00000008            // 3
#define SPELL_ATTR_EX4_UNK4                       0x00000010            // 4
#define SPELL_ATTR_EX4_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX4_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX4_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX4_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX4_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX4_SPELL_VS_EXTEND_COST       0x00000400            // 10 Rogue Shiv have this flag
#define SPELL_ATTR_EX4_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX4_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX4_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX4_UNK14                      0x00004000            // 14
#define SPELL_ATTR_EX4_UNK15                      0x00008000            // 15
#define SPELL_ATTR_EX4_NOT_USABLE_IN_ARENA        0x00010000            // 16 not usable in arena
#define SPELL_ATTR_EX4_USABLE_IN_ARENA            0x00020000            // 17 usable in arena
#define SPELL_ATTR_EX4_UNK18                      0x00040000            // 18
#define SPELL_ATTR_EX4_UNK19                      0x00080000            // 19
#define SPELL_ATTR_EX4_UNK20                      0x00100000            // 20
#define SPELL_ATTR_EX4_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX4_UNK22                      0x00400000            // 22
#define SPELL_ATTR_EX4_UNK23                      0x00800000            // 23
#define SPELL_ATTR_EX4_UNK24                      0x01000000            // 24
#define SPELL_ATTR_EX4_UNK25                      0x02000000            // 25 pet scaling auras
#define SPELL_ATTR_EX4_CAST_ONLY_IN_OUTLAND       0x04000000            // 26 Can only be used in Outland.
#define SPELL_ATTR_EX4_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX4_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX4_UNK29                      0x20000000            // 29
#define SPELL_ATTR_EX4_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX4_UNK31                      0x80000000            // 31

#define SPELL_ATTR_EX5_UNK0                       0x00000001            // 0
#define SPELL_ATTR_EX5_NO_REAGENT_WHILE_PREP      0x00000002            // 1 not need reagents if UNIT_FLAG_PREPARATION
#define SPELL_ATTR_EX5_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX5_USABLE_WHILE_STUNNED       0x00000008            // 3 usable while stunned
#define SPELL_ATTR_EX5_UNK4                       0x00000010            // 4
#define SPELL_ATTR_EX5_SINGLE_TARGET_SPELL        0x00000020            // 5 Only one target can be apply at a time
#define SPELL_ATTR_EX5_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX5_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX5_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX5_UNK9                       0x00000200            // 9
#define SPELL_ATTR_EX5_UNK10                      0x00000400            // 10
#define SPELL_ATTR_EX5_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX5_UNK12                      0x00001000            // 12
#define SPELL_ATTR_EX5_UNK13                      0x00002000            // 13
#define SPELL_ATTR_EX5_UNK14                      0x00004000            // 14
#define SPELL_ATTR_EX5_UNK15                      0x00008000            // 15
#define SPELL_ATTR_EX5_UNK16                      0x00010000            // 16
#define SPELL_ATTR_EX5_USABLE_WHILE_FEARED        0x00020000            // 17 usable while feared
#define SPELL_ATTR_EX5_USABLE_WHILE_CONFUSED      0x00040000            // 18 usable while confused
#define SPELL_ATTR_EX5_UNK19                      0x00080000            // 19
#define SPELL_ATTR_EX5_UNK20                      0x00100000            // 20
#define SPELL_ATTR_EX5_UNK21                      0x00200000            // 21
#define SPELL_ATTR_EX5_UNK22                      0x00400000            // 22
#define SPELL_ATTR_EX5_UNK23                      0x00800000            // 23
#define SPELL_ATTR_EX5_UNK24                      0x01000000            // 24
#define SPELL_ATTR_EX5_UNK25                      0x02000000            // 25
#define SPELL_ATTR_EX5_UNK26                      0x04000000            // 26
#define SPELL_ATTR_EX5_UNK27                      0x08000000            // 27
#define SPELL_ATTR_EX5_UNK28                      0x10000000            // 28
#define SPELL_ATTR_EX5_UNK29                      0x20000000            // 29
#define SPELL_ATTR_EX5_UNK30                      0x40000000            // 30
#define SPELL_ATTR_EX5_UNK31                      0x80000000            // 31 Forces all nearby enemies to focus attacks caster

#define SPELL_ATTR_EX6_UNK0                       0x00000001            // 0 Only Move spell have this flag
#define SPELL_ATTR_EX6_UNK1                       0x00000002            // 1 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK2                       0x00000004            // 2
#define SPELL_ATTR_EX6_UNK3                       0x00000008            // 3
#define SPELL_ATTR_EX6_UNK4                       0x00000010            // 4 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK5                       0x00000020            // 5
#define SPELL_ATTR_EX6_UNK6                       0x00000040            // 6
#define SPELL_ATTR_EX6_UNK7                       0x00000080            // 7
#define SPELL_ATTR_EX6_UNK8                       0x00000100            // 8
#define SPELL_ATTR_EX6_UNK9                       0x00000200            // 9 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK10                      0x00000400            // 10
#define SPELL_ATTR_EX6_UNK11                      0x00000800            // 11
#define SPELL_ATTR_EX6_UNK12                      0x00001000            // 12 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK13                      0x00002000            // 13 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK14                      0x00004000            // 14 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK15                      0x00008000            // 15 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK16                      0x00010000            // 16 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK17                      0x00020000            // 17 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK18                      0x00040000            // 18 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK19                      0x00080000            // 19 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK20                      0x00100000            // 20 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK21                      0x00200000            // 21 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK22                      0x00400000            // 22 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK23                      0x00800000            // 23 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK24                      0x01000000            // 24 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK25                      0x02000000            // 25 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK26                      0x04000000            // 26 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK27                      0x08000000            // 27 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK28                      0x10000000            // 28 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK29                      0x20000000            // 29 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK30                      0x40000000            // 30 not set in 2.4.2
#define SPELL_ATTR_EX6_UNK31                      0x80000000            // 31 not set in 2.4.2

enum SheathTypes
{
    SHEATHETYPE_NONE                   = 0,
    SHEATHETYPE_MAINHAND               = 1,
    SHEATHETYPE_OFFHAND                = 2,
    SHEATHETYPE_LARGEWEAPONLEFT        = 3,
    SHEATHETYPE_LARGEWEAPONRIGHT       = 4,
    SHEATHETYPE_HIPWEAPONLEFT          = 5,
    SHEATHETYPE_HIPWEAPONRIGHT         = 6,
    SHEATHETYPE_SHIELD                 = 7
};

#define MAX_SHEATHETYPE                  8

enum CharacterSlot
{
    SLOT_HEAD                          = 0,
    SLOT_NECK                          = 1,
    SLOT_SHOULDERS                     = 2,
    SLOT_SHIRT                         = 3,
    SLOT_CHEST                         = 4,
    SLOT_WAIST                         = 5,
    SLOT_LEGS                          = 6,
    SLOT_FEET                          = 7,
    SLOT_WRISTS                        = 8,
    SLOT_HANDS                         = 9,
    SLOT_FINGER1                       = 10,
    SLOT_FINGER2                       = 11,
    SLOT_TRINKET1                      = 12,
    SLOT_TRINKET2                      = 13,
    SLOT_BACK                          = 14,
    SLOT_MAIN_HAND                     = 15,
    SLOT_OFF_HAND                      = 16,
    SLOT_RANGED                        = 17,
    SLOT_TABARD                        = 18,
    SLOT_EMPTY                         = 19
};

enum Language
{
    LANG_UNIVERSAL      = 0,
    LANG_ORCISH         = 1,
    LANG_DARNASSIAN     = 2,
    LANG_TAURAHE        = 3,
    LANG_DWARVISH       = 6,
    LANG_COMMON         = 7,
    LANG_DEMONIC        = 8,
    LANG_TITAN          = 9,
    LANG_THALASSIAN     = 10,
    LANG_DRACONIC       = 11,
    LANG_KALIMAG        = 12,
    LANG_GNOMISH        = 13,
    LANG_TROLL          = 14,
    LANG_GUTTERSPEAK    = 33,
    LANG_DRAENEI        = 35,
    LANG_ZOMBIE         = 36,
    LANG_GNOMISH_BINARY = 37,
    LANG_GOBLIN_BINARY  = 38,
    LANG_ADDON          = 0xFFFFFFFF                        // used by addons, in 2.4.0 not exit, replaced by messagetype?
};

#define LANGUAGES_COUNT   19

enum Team
{
    HORDE               = 67,
    ALLIANCE            = 469,
    //TEAM_STEAMWHEEDLE_CARTEL = 169,                       // not used in code
    //TEAM_ALLIANCE_FORCES     = 891,
    //TEAM_HORDE_FORCES        = 892,
    //TEAM_SANCTUARY           = 936,
    //TEAM_OUTLAND             = 980,
    //TEAM_OTHER               = 0,                         // if ReputationListId > 0 && Flags != FACTION_FLAG_TEAM_HEADER
};

enum SpellEffects
{
    SPELL_EFFECT_INSTAKILL                 = 1,
    SPELL_EFFECT_SCHOOL_DAMAGE             = 2,
    SPELL_EFFECT_DUMMY                     = 3,
    SPELL_EFFECT_PORTAL_TELEPORT           = 4,
    SPELL_EFFECT_TELEPORT_UNITS            = 5,
    SPELL_EFFECT_APPLY_AURA                = 6,
    SPELL_EFFECT_ENVIRONMENTAL_DAMAGE      = 7,
    SPELL_EFFECT_POWER_DRAIN               = 8,
    SPELL_EFFECT_HEALTH_LEECH              = 9,
    SPELL_EFFECT_HEAL                      = 10,
    SPELL_EFFECT_BIND                      = 11,
    SPELL_EFFECT_PORTAL                    = 12,
    SPELL_EFFECT_RITUAL_BASE               = 13,
    SPELL_EFFECT_RITUAL_SPECIALIZE         = 14,
    SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL    = 15,
    SPELL_EFFECT_QUEST_COMPLETE            = 16,
    SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL    = 17,
    SPELL_EFFECT_RESURRECT                 = 18,
    SPELL_EFFECT_ADD_EXTRA_ATTACKS         = 19,
    SPELL_EFFECT_DODGE                     = 20,
    SPELL_EFFECT_EVADE                     = 21,
    SPELL_EFFECT_PARRY                     = 22,
    SPELL_EFFECT_BLOCK                     = 23,
    SPELL_EFFECT_CREATE_ITEM               = 24,
    SPELL_EFFECT_WEAPON                    = 25,
    SPELL_EFFECT_DEFENSE                   = 26,
    SPELL_EFFECT_PERSISTENT_AREA_AURA      = 27,
    SPELL_EFFECT_SUMMON                    = 28,
    SPELL_EFFECT_LEAP                      = 29,
    SPELL_EFFECT_ENERGIZE                  = 30,
    SPELL_EFFECT_WEAPON_PERCENT_DAMAGE     = 31,
    SPELL_EFFECT_TRIGGER_MISSILE           = 32,
    SPELL_EFFECT_OPEN_LOCK                 = 33,
    SPELL_EFFECT_SUMMON_CHANGE_ITEM        = 34,
    SPELL_EFFECT_APPLY_AREA_AURA_PARTY     = 35,
    SPELL_EFFECT_LEARN_SPELL               = 36,
    SPELL_EFFECT_SPELL_DEFENSE             = 37,
    SPELL_EFFECT_DISPEL                    = 38,
    SPELL_EFFECT_LANGUAGE                  = 39,
    SPELL_EFFECT_DUAL_WIELD                = 40,
    SPELL_EFFECT_SUMMON_WILD               = 41,
    SPELL_EFFECT_SUMMON_GUARDIAN           = 42,
    SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER= 43,
    SPELL_EFFECT_SKILL_STEP                = 44,
    SPELL_EFFECT_UNDEFINED_45              = 45,
    SPELL_EFFECT_SPAWN                     = 46,
    SPELL_EFFECT_TRADE_SKILL               = 47,
    SPELL_EFFECT_STEALTH                   = 48,
    SPELL_EFFECT_DETECT                    = 49,
    SPELL_EFFECT_TRANS_DOOR                = 50,
    SPELL_EFFECT_FORCE_CRITICAL_HIT        = 51,
    SPELL_EFFECT_GUARANTEE_HIT             = 52,
    SPELL_EFFECT_ENCHANT_ITEM              = 53,
    SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY    = 54,
    SPELL_EFFECT_TAMECREATURE              = 55,
    SPELL_EFFECT_SUMMON_PET                = 56,
    SPELL_EFFECT_LEARN_PET_SPELL           = 57,
    SPELL_EFFECT_WEAPON_DAMAGE             = 58,
    SPELL_EFFECT_OPEN_LOCK_ITEM            = 59,
    SPELL_EFFECT_PROFICIENCY               = 60,
    SPELL_EFFECT_SEND_EVENT                = 61,
    SPELL_EFFECT_POWER_BURN                = 62,
    SPELL_EFFECT_THREAT                    = 63,
    SPELL_EFFECT_TRIGGER_SPELL             = 64,
    SPELL_EFFECT_HEALTH_FUNNEL             = 65,
    SPELL_EFFECT_POWER_FUNNEL              = 66,
    SPELL_EFFECT_HEAL_MAX_HEALTH           = 67,
    SPELL_EFFECT_INTERRUPT_CAST            = 68,
    SPELL_EFFECT_DISTRACT                  = 69,
    SPELL_EFFECT_PULL                      = 70,
    SPELL_EFFECT_PICKPOCKET                = 71,
    SPELL_EFFECT_ADD_FARSIGHT              = 72,
    SPELL_EFFECT_SUMMON_POSSESSED          = 73,
    SPELL_EFFECT_SUMMON_TOTEM              = 74,
    SPELL_EFFECT_HEAL_MECHANICAL           = 75,
    SPELL_EFFECT_SUMMON_OBJECT_WILD        = 76,
    SPELL_EFFECT_SCRIPT_EFFECT             = 77,
    SPELL_EFFECT_ATTACK                    = 78,
    SPELL_EFFECT_SANCTUARY                 = 79,
    SPELL_EFFECT_ADD_COMBO_POINTS          = 80,
    SPELL_EFFECT_CREATE_HOUSE              = 81,
    SPELL_EFFECT_BIND_SIGHT                = 82,
    SPELL_EFFECT_DUEL                      = 83,
    SPELL_EFFECT_STUCK                     = 84,
    SPELL_EFFECT_SUMMON_PLAYER             = 85,
    SPELL_EFFECT_ACTIVATE_OBJECT           = 86,
    SPELL_EFFECT_SUMMON_TOTEM_SLOT1        = 87,
    SPELL_EFFECT_SUMMON_TOTEM_SLOT2        = 88,
    SPELL_EFFECT_SUMMON_TOTEM_SLOT3        = 89,
    SPELL_EFFECT_SUMMON_TOTEM_SLOT4        = 90,
    SPELL_EFFECT_THREAT_ALL                = 91,
    SPELL_EFFECT_ENCHANT_HELD_ITEM         = 92,
    SPELL_EFFECT_SUMMON_PHANTASM           = 93, //unused
    SPELL_EFFECT_SELF_RESURRECT            = 94,
    SPELL_EFFECT_SKINNING                  = 95,
    SPELL_EFFECT_CHARGE                    = 96,
    SPELL_EFFECT_SUMMON_CRITTER            = 97,
    SPELL_EFFECT_KNOCK_BACK                = 98,
    SPELL_EFFECT_DISENCHANT                = 99,
    SPELL_EFFECT_INEBRIATE                 = 100,
    SPELL_EFFECT_FEED_PET                  = 101,
    SPELL_EFFECT_DISMISS_PET               = 102,
    SPELL_EFFECT_REPUTATION                = 103,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT1       = 104,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT2       = 105,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT3       = 106,
    SPELL_EFFECT_SUMMON_OBJECT_SLOT4       = 107,
    SPELL_EFFECT_DISPEL_MECHANIC           = 108,
    SPELL_EFFECT_SUMMON_DEAD_PET           = 109,
    SPELL_EFFECT_DESTROY_ALL_TOTEMS        = 110,
    SPELL_EFFECT_DURABILITY_DAMAGE         = 111,
    SPELL_EFFECT_SUMMON_DEMON              = 112,
    SPELL_EFFECT_RESURRECT_NEW             = 113,
    SPELL_EFFECT_ATTACK_ME                 = 114,
    SPELL_EFFECT_DURABILITY_DAMAGE_PCT     = 115,
    SPELL_EFFECT_SKIN_PLAYER_CORPSE        = 116,
    SPELL_EFFECT_SPIRIT_HEAL               = 117,
    SPELL_EFFECT_SKILL                     = 118,
    SPELL_EFFECT_APPLY_AREA_AURA_PET       = 119,
    SPELL_EFFECT_TELEPORT_GRAVEYARD        = 120,
    SPELL_EFFECT_NORMALIZED_WEAPON_DMG     = 121,
    SPELL_EFFECT_122                       = 122,
    SPELL_EFFECT_SEND_TAXI                 = 123,
    SPELL_EFFECT_PLAYER_PULL               = 124,
    SPELL_EFFECT_MODIFY_THREAT_PERCENT     = 125,
    SPELL_EFFECT_STEAL_BENEFICIAL_BUFF     = 126,
    SPELL_EFFECT_PROSPECTING               = 127,
    SPELL_EFFECT_APPLY_AREA_AURA_FRIEND    = 128,
    SPELL_EFFECT_APPLY_AREA_AURA_ENEMY     = 129,
    SPELL_EFFECT_REDIRECT_THREAT           = 130,
    SPELL_EFFECT_131                       = 131,
    SPELL_EFFECT_132                       = 132,
    SPELL_EFFECT_UNLEARN_SPECIALIZATION    = 133,
    SPELL_EFFECT_KILL_CREDIT               = 134,
    SPELL_EFFECT_135                       = 135,
    SPELL_EFFECT_HEAL_PCT                  = 136,
    SPELL_EFFECT_ENERGIZE_PCT              = 137,
    SPELL_EFFECT_138                       = 138,
    SPELL_EFFECT_139                       = 139,
    SPELL_EFFECT_FORCE_CAST                = 140,
    SPELL_EFFECT_141                       = 141,
    SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE  = 142,
    SPELL_EFFECT_APPLY_AREA_AURA_OWNER     = 143,
    SPELL_EFFECT_KNOCK_BACK_2              = 144,
    SPELL_EFFECT_145                       = 145,
    SPELL_EFFECT_146                       = 146,
    SPELL_EFFECT_QUEST_FAIL                = 147,
    SPELL_EFFECT_148                       = 148,
    SPELL_EFFECT_149                       = 149,
    SPELL_EFFECT_150                       = 150,
    SPELL_EFFECT_TRIGGER_SPELL_2           = 151,
    SPELL_EFFECT_152                       = 152,
    SPELL_EFFECT_153                       = 153,
    TOTAL_SPELL_EFFECTS                    = 154
};

// Spell aura states
enum AuraState
{   // (C) used in caster aura state     (T) used in target aura state
    // (c) used in caster aura state-not (t) used in target aura state-not
    AURA_STATE_DEFENSE                      = 1,            // C   |
    AURA_STATE_HEALTHLESS_20_PERCENT        = 2,            // CcT |
    AURA_STATE_BERSERKING                   = 3,            // C T |
    //AURA_STATE_UNKNOWN4                   = 4,            //  c t| some limitation to charge spells (?) and target test spells
    AURA_STATE_JUDGEMENT                    = 5,            // C   |
    //AURA_STATE_UNKNOWN6                   = 6,            //     | not used
    AURA_STATE_HUNTER_PARRY                 = 7,            // C   |
    AURA_STATE_ROGUE_ATTACK_FROM_STEALTH    = 7,            // C   | FIX ME: not implemented yet!
    //AURA_STATE_UNKNOWN7c                  = 7,            //  c  | random/focused bursts spells (?)
    //AURA_STATE_UNKNOWN8                   = 8,            //     | not used
    //AURA_STATE_UNKNOWN9                   = 9,            //     | not used
    AURA_STATE_WARRIOR_VICTORY_RUSH         = 10,           // C   | warrior victory rush
    AURA_STATE_HUNTER_CRIT_STRIKE           = 10,           // C   | hunter crit strike
    AURA_STATE_CRIT                         = 11,           // C   |
    AURA_STATE_FAERIE_FIRE                  = 12,           //  c t|
    AURA_STATE_HEALTHLESS_35_PERCENT        = 13,           // C T |
    AURA_STATE_IMMOLATE                     = 14,           //   T |
    AURA_STATE_SWIFTMEND                    = 15,           //   T |
    AURA_STATE_DEADLY_POISON                = 16,           //   T |
    AURA_STATE_FORBEARANCE                  = 17,           //  c t|
    AURA_STATE_WEAKENED_SOUL                = 18,           //    t|
    AURA_STATE_HYPOTHERMIA                  = 19            //  c  |
};

// Spell mechanics
enum Mechanics
{
    MECHANIC_NONE             = 0,
    MECHANIC_CHARM            = 1,
    MECHANIC_CONFUSED         = 2,
    MECHANIC_DISARM           = 3,
    MECHANIC_DISTRACT         = 4,
    MECHANIC_FEAR             = 5,
    MECHANIC_FUMBLE           = 6,
    MECHANIC_ROOT             = 7,
    MECHANIC_PACIFY           = 8,                          //0 spells use this mechanic
    MECHANIC_SILENCE          = 9,
    MECHANIC_SLEEP            = 10,
    MECHANIC_SNARE            = 11,
    MECHANIC_STUN             = 12,
    MECHANIC_FREEZE           = 13,
    MECHANIC_KNOCKOUT         = 14,
    MECHANIC_BLEED            = 15,
    MECHANIC_BANDAGE          = 16,
    MECHANIC_POLYMORPH        = 17,
    MECHANIC_BANISH           = 18,
    MECHANIC_SHIELD           = 19,
    MECHANIC_SHACKLE          = 20,
    MECHANIC_MOUNT            = 21,
    MECHANIC_PERSUADE         = 22,                         //0 spells use this mechanic
    MECHANIC_TURN             = 23,
    MECHANIC_HORROR           = 24,
    MECHANIC_INVULNERABILITY  = 25,
    MECHANIC_INTERRUPT        = 26,
    MECHANIC_DAZE             = 27,
    MECHANIC_DISCOVERY        = 28,
    MECHANIC_IMMUNE_SHIELD    = 29,                         // Divine (Blessing) Shield/Protection and Ice Block
    MECHANIC_SAPPED           = 30
};

// Used for spell 42292 Immune Movement Impairment and Loss of Control (0x49967da6)
#define IMMUNE_TO_MOVEMENT_IMPAIRMENT_AND_LOSS_CONTROL_MASK ( \
    (1<<MECHANIC_CHARM   )|(1<<MECHANIC_CONFUSED )|(1<<MECHANIC_FEAR  )| \
    (1<<MECHANIC_ROOT    )|(1<<MECHANIC_PACIFY   )|(1<<MECHANIC_SLEEP )| \
    (1<<MECHANIC_SNARE   )|(1<<MECHANIC_STUN     )|(1<<MECHANIC_FREEZE)| \
    (1<<MECHANIC_KNOCKOUT)|(1<<MECHANIC_POLYMORPH)|(1<<MECHANIC_BANISH)| \
    (1<<MECHANIC_SHACKLE )|(1<<MECHANIC_TURN     )|(1<<MECHANIC_HORROR)| \
    (1<<MECHANIC_DAZE    )|(1<<MECHANIC_SAPPED   ) )

// Spell dispel type
enum DispelType
{
    DISPEL_NONE         = 0,
    DISPEL_MAGIC        = 1,
    DISPEL_CURSE        = 2,
    DISPEL_DISEASE      = 3,
    DISPEL_POISON       = 4,
    DISPEL_STEALTH      = 5,
    DISPEL_INVISIBILITY = 6,
    DISPEL_ALL          = 7,
    DISPEL_SPE_NPC_ONLY = 8,
    DISPEL_ENRAGE       = 9,
    DISPEL_ZG_TICKET    = 10
};

#define DISPEL_ALL_MASK ( (1<<DISPEL_MAGIC) | (1<<DISPEL_CURSE) | (1<<DISPEL_DISEASE) | (1<<DISPEL_POISON) )

//To all Immune system,if target has immunes,
//some spell that related to ImmuneToDispel or ImmuneToSchool or ImmuneToDamage type can't cast to it,
//some spell_effects that related to ImmuneToEffect<effect>(only this effect in the spell) can't cast to it,
//some aura(related to Mechanics or ImmuneToState<aura>) can't apply to it.
enum SpellImmunity
{
    IMMUNITY_EFFECT                = 0,                     // enum SpellEffects
    IMMUNITY_STATE                 = 1,                     // enum AuraType
    IMMUNITY_SCHOOL                = 2,                     // enum SpellSchoolMask
    IMMUNITY_DAMAGE                = 3,                     // enum SpellSchoolMask
    IMMUNITY_DISPEL                = 4,                     // enum DispelType
    IMMUNITY_MECHANIC              = 5,                     // enum Mechanics
    IMMUNITY_ID                    = 6
};

#define MAX_SPELL_IMMUNITY           7

enum Targets
{
    TARGET_UNIT_CASTER                 = 1,
    TARGET_UNIT_NEARBY_ENEMY           = 2, // only one spell has that, but regardless, it's a target type after all
    TARGET_UNIT_NEARBY_ALLY            = 3,
    TARGET_UNIT_NEARBY_ALLY_UNK        = 4,
    TARGET_UNIT_PET                    = 5,
    TARGET_UNIT_TARGET_ENEMY           = 6,
    TARGET_UNIT_AREA_ENTRY_SRC         = 7,
    TARGET_UNIT_AREA_ENTRY_DST         = 8,
    TARGET_DST_HOME                    = 9,  // uses in teleport to innkeeper spells
    TARGET_UNIT_TARGET_DEST_CASTER     = 11, // teleport target to caster
    TARGET_UNIT_AREA_ENEMY_SRC         = 15,
    TARGET_UNIT_AREA_ENEMY_DST         = 16,
    TARGET_DST_DB                      = 17, // uses in teleport spells and some other
    TARGET_DST_CASTER                  = 18,
    TARGET_UNIT_PARTY_CASTER           = 20,
    TARGET_UNIT_TARGET_ALLY            = 21,
    TARGET_SRC_CASTER                  = 22,
    TARGET_GAMEOBJECT                  = 23,
    //TARGET_OBJECT_OPEN
    TARGET_UNIT_CONE_ENEMY             = 24,
    TARGET_UNIT_TARGET_ANY             = 25,
    TARGET_GAMEOBJECT_ITEM             = 26,
    //TARGET_OBJECT_ITEM_PICKLOCK
    TARGET_UNIT_MASTER                 = 27,
    TARGET_DEST_DYNOBJ_ENEMY           = 28,
    TARGET_DEST_DYNOBJ_ALLY            = 29, // only for effect 27
    TARGET_UNIT_AREA_ALLY_SRC          = 30, // in TargetB used only with TARGET_SRC_CASTER and in self casting range in TargetA
    TARGET_UNIT_AREA_ALLY_DST          = 31,
    TARGET_MINION                      = 32,
    //TARGET_DEST_SUMMON
    TARGET_UNIT_AREA_PARTY_SRC         = 33,
    TARGET_UNIT_AREA_PARTY_DST         = 34, // used in Tranquility
    TARGET_UNIT_TARGET_PARTY           = 35,
    TARGET_DEST_CASTER_RANDOM_UNKNOWN  = 36, //unknown
    TARGET_UNIT_PARTY_TARGET           = 37,
    TARGET_UNIT_NEARBY_ENTRY           = 38,
    TARGET_UNIT_CASTER_FISHING         = 39,
    TARGET_OBJECT_USE                  = 40,
    TARGET_DEST_CASTER_FRONT_LEFT      = 41, //earth totem
    TARGET_DEST_CASTER_BACK_LEFT       = 42, //water totem
    TARGET_DEST_CASTER_BACK_RIGHT      = 43, //air totem
    TARGET_DEST_CASTER_FRONT_RIGHT     = 44, //fire totem
    TARGET_UNIT_CHAINHEAL              = 45,
    TARGET_DST_NEARBY_ENTRY            = 46,
    TARGET_DEST_CASTER_FRONT           = 47,
    TARGET_DEST_CASTER_BACK            = 48,
    TARGET_DEST_CASTER_RIGHT           = 49,
    TARGET_DEST_CASTER_LEFT            = 50,
    TARGET_OBJECT_AREA_SRC             = 51,
    TARGET_OBJECT_AREA_DST             = 52,
    TARGET_DST_TARGET_ENEMY            = 53, // set unit coordinates as dest, only 16 target B imlemented
    TARGET_UNIT_CONE_ENEMY_UNKNOWN     = 54, // 180 degree, or different angle
    TARGET_DEST_CASTER_FRONT_LEAP      = 55, // for a leap spell
    TARGET_UNIT_RAID_CASTER                   = 56,
    TARGET_UNIT_TARGET_RAID            = 57,
    TARGET_UNIT_NEARBY_RAID            = 58,
    TARGET_UNIT_CONE_ALLY              = 59,
    TARGET_UNIT_CONE_ENTRY             = 60,
    TARGET_UNIT_CLASS_TARGET           = 61,
    TARGET_TEST                        = 62, // for a test spell
    TARGET_DEST_TARGET_ANY             = 63,
    TARGET_DEST_TARGET_FRONT           = 64,
    TARGET_DEST_TARGET_BACK            = 65,                // uses in teleport behind spells
    TARGET_DEST_TARGET_RIGHT           = 66,
    TARGET_DEST_TARGET_LEFT            = 67,
    TARGET_DEST_TARGET_FRONT_LEFT      = 68,
    TARGET_DEST_TARGET_BACK_LEFT       = 69,
    TARGET_DEST_TARGET_BACK_RIGHT      = 70,
    TARGET_DEST_TARGET_FRONT_RIGHT     = 71,
    TARGET_DEST_CASTER_RANDOM          = 72,
    TARGET_DEST_CASTER_RADIUS          = 73,
    TARGET_DEST_TARGET_RANDOM          = 74,
    TARGET_DEST_TARGET_RADIUS          = 75,
    TARGET_DEST_CHANNEL                = 76,
    TARGET_UNIT_CHANNEL                = 77,
    TARGET_DEST_DEST_FRONT             = 78,
    TARGET_DEST_DEST_BACK              = 79,
    TARGET_DEST_DEST_RIGHT             = 80,
    TARGET_DEST_DEST_LEFT              = 81,
    TARGET_DEST_DEST_FRONT_LEFT        = 82,
    TARGET_DEST_DEST_BACK_LEFT         = 83,
    TARGET_DEST_DEST_BACK_RIGHT        = 84,
    TARGET_DEST_DEST_FRONT_RIGHT       = 85,
    TARGET_DEST_DEST_RANDOM            = 86,
    TARGET_DEST_DEST                   = 87,
    TARGET_DEST_DYNOBJ_NONE            = 88,
    TARGET_DEST_TRAJ                   = 89,
    TARGET_UNIT_MINIPET                = 90,
    TARGET_CORPSE_AREA_ENEMY_PLAYER    = 93,
};

#define TOTAL_SPELL_TARGETS              94

enum SpellMissInfo
{
    SPELL_MISS_NONE                    = 0,
    SPELL_MISS_MISS                    = 1,
    SPELL_MISS_RESIST                  = 2,
    SPELL_MISS_DODGE                   = 3,
    SPELL_MISS_PARRY                   = 4,
    SPELL_MISS_BLOCK                   = 5,
    SPELL_MISS_EVADE                   = 6,
    SPELL_MISS_IMMUNE                  = 7,
    SPELL_MISS_IMMUNE2                 = 8,
    SPELL_MISS_DEFLECT                 = 9,
    SPELL_MISS_ABSORB                  = 10,
    SPELL_MISS_REFLECT                 = 11
};

enum SpellHitType
{
    SPELL_HIT_TYPE_UNK1 = 0x00001,
    SPELL_HIT_TYPE_CRIT = 0x00002,
    SPELL_HIT_TYPE_UNK2 = 0x00004,
    SPELL_HIT_TYPE_UNK3 = 0x00008,
    SPELL_HIT_TYPE_UNK4 = 0x00020
};

enum SpellDmgClass
{
    SPELL_DAMAGE_CLASS_NONE     = 0,
    SPELL_DAMAGE_CLASS_MAGIC    = 1,
    SPELL_DAMAGE_CLASS_MELEE    = 2,
    SPELL_DAMAGE_CLASS_RANGED   = 3
};

enum SpellPreventionType
{
    SPELL_PREVENTION_TYPE_NONE      = 0,
    SPELL_PREVENTION_TYPE_SILENCE   = 1,
    SPELL_PREVENTION_TYPE_PACIFY    = 2
};

enum GameobjectTypes
{
    GAMEOBJECT_TYPE_DOOR                   = 0,
    GAMEOBJECT_TYPE_BUTTON                 = 1,
    GAMEOBJECT_TYPE_QUESTGIVER             = 2,
    GAMEOBJECT_TYPE_CHEST                  = 3,
    GAMEOBJECT_TYPE_BINDER                 = 4,
    GAMEOBJECT_TYPE_GENERIC                = 5,
    GAMEOBJECT_TYPE_TRAP                   = 6,
    GAMEOBJECT_TYPE_CHAIR                  = 7,
    GAMEOBJECT_TYPE_SPELL_FOCUS            = 8,
    GAMEOBJECT_TYPE_TEXT                   = 9,
    GAMEOBJECT_TYPE_GOOBER                 = 10,
    GAMEOBJECT_TYPE_TRANSPORT              = 11,
    GAMEOBJECT_TYPE_AREADAMAGE             = 12,
    GAMEOBJECT_TYPE_CAMERA                 = 13,
    GAMEOBJECT_TYPE_MAP_OBJECT             = 14,
    GAMEOBJECT_TYPE_MO_TRANSPORT           = 15,
    GAMEOBJECT_TYPE_DUEL_ARBITER           = 16,
    GAMEOBJECT_TYPE_FISHINGNODE            = 17,
    GAMEOBJECT_TYPE_SUMMONING_RITUAL       = 18,
    GAMEOBJECT_TYPE_MAILBOX                = 19,
    GAMEOBJECT_TYPE_AUCTIONHOUSE           = 20,
    GAMEOBJECT_TYPE_GUARDPOST              = 21,
    GAMEOBJECT_TYPE_SPELLCASTER            = 22,
    GAMEOBJECT_TYPE_MEETINGSTONE           = 23,
    GAMEOBJECT_TYPE_FLAGSTAND              = 24,
    GAMEOBJECT_TYPE_FISHINGHOLE            = 25,
    GAMEOBJECT_TYPE_FLAGDROP               = 26,
    GAMEOBJECT_TYPE_MINI_GAME              = 27,
    GAMEOBJECT_TYPE_LOTTERY_KIOSK          = 28,
    GAMEOBJECT_TYPE_CAPTURE_POINT          = 29,
    GAMEOBJECT_TYPE_AURA_GENERATOR         = 30,
    GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY     = 31,
    GAMEOBJECT_TYPE_BARBER_CHAIR           = 32,
    GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING  = 33,
    GAMEOBJECT_TYPE_GUILD_BANK             = 34,
};

#define MAX_GAMEOBJECT_TYPE                  35             // sending to client this or greater value can crash client.

#define GAMEOBJECT_FISHINGNODE_ENTRY        35591           // Better to define it somewhere instead of hardcoding everywhere

enum GameObjectFlags
{
    GO_FLAG_IN_USE          = 0x00000001,                   //disables interaction while animated
    GO_FLAG_LOCKED          = 0x00000002,                   //require key, spell, event, etc to be opened. Makes "Locked" appear in tooltip
    GO_FLAG_INTERACT_COND   = 0x00000004,                   //cannot interact (condition to interact)
    GO_FLAG_TRANSPORT       = 0x00000008,                   //any kind of transport? Object can transport (elevator, boat, car)
    GO_FLAG_UNK1            = 0x00000010,                   //
    GO_FLAG_NODESPAWN       = 0x00000020,                   //never despawn, typically for doors, they just change state
    GO_FLAG_TRIGGERED       = 0x00000040                    //typically, summoned objects. Triggered by spell or other events
};

enum TextEmotes
{
    TEXTEMOTE_AGREE                = 1,
    TEXTEMOTE_AMAZE                = 2,
    TEXTEMOTE_ANGRY                = 3,
    TEXTEMOTE_APOLOGIZE            = 4,
    TEXTEMOTE_APPLAUD              = 5,
    TEXTEMOTE_BASHFUL              = 6,
    TEXTEMOTE_BECKON               = 7,
    TEXTEMOTE_BEG                  = 8,
    TEXTEMOTE_BITE                 = 9,
    TEXTEMOTE_BLEED                = 10,
    TEXTEMOTE_BLINK                = 11,
    TEXTEMOTE_BLUSH                = 12,
    TEXTEMOTE_BONK                 = 13,
    TEXTEMOTE_BORED                = 14,
    TEXTEMOTE_BOUNCE               = 15,
    TEXTEMOTE_BRB                  = 16,
    TEXTEMOTE_BOW                  = 17,
    TEXTEMOTE_BURP                 = 18,
    TEXTEMOTE_BYE                  = 19,
    TEXTEMOTE_CACKLE               = 20,
    TEXTEMOTE_CHEER                = 21,
    TEXTEMOTE_CHICKEN              = 22,
    TEXTEMOTE_CHUCKLE              = 23,
    TEXTEMOTE_CLAP                 = 24,
    TEXTEMOTE_CONFUSED             = 25,
    TEXTEMOTE_CONGRATULATE         = 26,
    TEXTEMOTE_COUGH                = 27,
    TEXTEMOTE_COWER                = 28,
    TEXTEMOTE_CRACK                = 29,
    TEXTEMOTE_CRINGE               = 30,
    TEXTEMOTE_CRY                  = 31,
    TEXTEMOTE_CURIOUS              = 32,
    TEXTEMOTE_CURTSEY              = 33,
    TEXTEMOTE_DANCE                = 34,
    TEXTEMOTE_DRINK                = 35,
    TEXTEMOTE_DROOL                = 36,
    TEXTEMOTE_EAT                  = 37,
    TEXTEMOTE_EYE                  = 38,
    TEXTEMOTE_FART                 = 39,
    TEXTEMOTE_FIDGET               = 40,
    TEXTEMOTE_FLEX                 = 41,
    TEXTEMOTE_FROWN                = 42,
    TEXTEMOTE_GASP                 = 43,
    TEXTEMOTE_GAZE                 = 44,
    TEXTEMOTE_GIGGLE               = 45,
    TEXTEMOTE_GLARE                = 46,
    TEXTEMOTE_GLOAT                = 47,
    TEXTEMOTE_GREET                = 48,
    TEXTEMOTE_GRIN                 = 49,
    TEXTEMOTE_GROAN                = 50,
    TEXTEMOTE_GROVEL               = 51,
    TEXTEMOTE_GUFFAW               = 52,
    TEXTEMOTE_HAIL                 = 53,
    TEXTEMOTE_HAPPY                = 54,
    TEXTEMOTE_HELLO                = 55,
    TEXTEMOTE_HUG                  = 56,
    TEXTEMOTE_HUNGRY               = 57,
    TEXTEMOTE_KISS                 = 58,
    TEXTEMOTE_KNEEL                = 59,
    TEXTEMOTE_LAUGH                = 60,
    TEXTEMOTE_LAYDOWN              = 61,
    TEXTEMOTE_MESSAGE              = 62,
    TEXTEMOTE_MOAN                 = 63,
    TEXTEMOTE_MOON                 = 64,
    TEXTEMOTE_MOURN                = 65,
    TEXTEMOTE_NO                   = 66,
    TEXTEMOTE_NOD                  = 67,
    TEXTEMOTE_NOSEPICK             = 68,
    TEXTEMOTE_PANIC                = 69,
    TEXTEMOTE_PEER                 = 70,
    TEXTEMOTE_PLEAD                = 71,
    TEXTEMOTE_POINT                = 72,
    TEXTEMOTE_POKE                 = 73,
    TEXTEMOTE_PRAY                 = 74,
    TEXTEMOTE_ROAR                 = 75,
    TEXTEMOTE_ROFL                 = 76,
    TEXTEMOTE_RUDE                 = 77,
    TEXTEMOTE_SALUTE               = 78,
    TEXTEMOTE_SCRATCH              = 79,
    TEXTEMOTE_SEXY                 = 80,
    TEXTEMOTE_SHAKE                = 81,
    TEXTEMOTE_SHOUT                = 82,
    TEXTEMOTE_SHRUG                = 83,
    TEXTEMOTE_SHY                  = 84,
    TEXTEMOTE_SIGH                 = 85,
    TEXTEMOTE_SIT                  = 86,
    TEXTEMOTE_SLEEP                = 87,
    TEXTEMOTE_SNARL                = 88,
    TEXTEMOTE_SPIT                 = 89,
    TEXTEMOTE_STARE                = 90,
    TEXTEMOTE_SURPRISED            = 91,
    TEXTEMOTE_SURRENDER            = 92,
    TEXTEMOTE_TALK                 = 93,
    TEXTEMOTE_TALKEX               = 94,
    TEXTEMOTE_TALKQ                = 95,
    TEXTEMOTE_TAP                  = 96,
    TEXTEMOTE_THANK                = 97,
    TEXTEMOTE_THREATEN             = 98,
    TEXTEMOTE_TIRED                = 99,
    TEXTEMOTE_VICTORY              = 100,
    TEXTEMOTE_WAVE                 = 101,
    TEXTEMOTE_WELCOME              = 102,
    TEXTEMOTE_WHINE                = 103,
    TEXTEMOTE_WHISTLE              = 104,
    TEXTEMOTE_WORK                 = 105,
    TEXTEMOTE_YAWN                 = 106,
    TEXTEMOTE_BOGGLE               = 107,
    TEXTEMOTE_CALM                 = 108,
    TEXTEMOTE_COLD                 = 109,
    TEXTEMOTE_COMFORT              = 110,
    TEXTEMOTE_CUDDLE               = 111,
    TEXTEMOTE_DUCK                 = 112,
    TEXTEMOTE_INSULT               = 113,
    TEXTEMOTE_INTRODUCE            = 114,
    TEXTEMOTE_JK                   = 115,
    TEXTEMOTE_LICK                 = 116,
    TEXTEMOTE_LISTEN               = 117,
    TEXTEMOTE_LOST                 = 118,
    TEXTEMOTE_MOCK                 = 119,
    TEXTEMOTE_PONDER               = 120,
    TEXTEMOTE_POUNCE               = 121,
    TEXTEMOTE_PRAISE               = 122,
    TEXTEMOTE_PURR                 = 123,
    TEXTEMOTE_PUZZLE               = 124,
    TEXTEMOTE_RAISE                = 125,
    TEXTEMOTE_READY                = 126,
    TEXTEMOTE_SHIMMY               = 127,
    TEXTEMOTE_SHIVER               = 128,
    TEXTEMOTE_SHOO                 = 129,
    TEXTEMOTE_SLAP                 = 130,
    TEXTEMOTE_SMIRK                = 131,
    TEXTEMOTE_SNIFF                = 132,
    TEXTEMOTE_SNUB                 = 133,
    TEXTEMOTE_SOOTHE               = 134,
    TEXTEMOTE_STINK                = 135,
    TEXTEMOTE_TAUNT                = 136,
    TEXTEMOTE_TEASE                = 137,
    TEXTEMOTE_THIRSTY              = 138,
    TEXTEMOTE_VETO                 = 139,
    TEXTEMOTE_SNICKER              = 140,
    TEXTEMOTE_STAND                = 141,
    TEXTEMOTE_TICKLE               = 142,
    TEXTEMOTE_VIOLIN               = 143,
    TEXTEMOTE_SMILE                = 163,
    TEXTEMOTE_RASP                 = 183,
    TEXTEMOTE_PITY                 = 203,
    TEXTEMOTE_GROWL                = 204,
    TEXTEMOTE_BARK                 = 205,
    TEXTEMOTE_SCARED               = 223,
    TEXTEMOTE_FLOP                 = 224,
    TEXTEMOTE_LOVE                 = 225,
    TEXTEMOTE_MOO                  = 226,
    TEXTEMOTE_OPENFIRE             = 327,
    TEXTEMOTE_FLIRT                = 328,
    TEXTEMOTE_JOKE                 = 329,
    TEXTEMOTE_COMMEND              = 243,
    TEXTEMOTE_WINK                 = 363,
    TEXTEMOTE_PAT                  = 364,
    TEXTEMOTE_SERIOUS              = 365,
    TEXTEMOTE_MOUNTSPECIAL         = 366,
    TEXTEMOTE_GOODLUCK             = 367,
    TEXTEMOTE_BLAME                = 368,
    TEXTEMOTE_BLANK                = 369,
    TEXTEMOTE_BRANDISH             = 370,
    TEXTEMOTE_BREATH               = 371,
    TEXTEMOTE_DISAGREE             = 372,
    TEXTEMOTE_DOUBT                = 373,
    TEXTEMOTE_EMBARRASS            = 374,
    TEXTEMOTE_ENCOURAGE            = 375,
    TEXTEMOTE_ENEMY                = 376,
    TEXTEMOTE_EYEBROW              = 377,
    TEXTEMOTE_TOAST                = 378
};

enum Emote
{
    EMOTE_ONESHOT_NONE                 = 0,
    EMOTE_ONESHOT_TALK                 = 1,
    EMOTE_ONESHOT_BOW                  = 2,
    EMOTE_ONESHOT_WAVE                 = 3,
    EMOTE_ONESHOT_CHEER                = 4,
    EMOTE_ONESHOT_EXCLAMATION          = 5,
    EMOTE_ONESHOT_QUESTION             = 6,
    EMOTE_ONESHOT_EAT                  = 7,
    EMOTE_STATE_DANCE                  = 10,
    EMOTE_ONESHOT_LAUGH                = 11,
    EMOTE_STATE_SLEEP                  = 12,
    EMOTE_STATE_SIT                    = 13,
    EMOTE_ONESHOT_RUDE                 = 14,
    EMOTE_ONESHOT_ROAR                 = 15,
    EMOTE_ONESHOT_KNEEL                = 16,
    EMOTE_ONESHOT_KISS                 = 17,
    EMOTE_ONESHOT_CRY                  = 18,
    EMOTE_ONESHOT_CHICKEN              = 19,
    EMOTE_ONESHOT_BEG                  = 20,
    EMOTE_ONESHOT_APPLAUD              = 21,
    EMOTE_ONESHOT_SHOUT                = 22,
    EMOTE_ONESHOT_FLEX                 = 23,
    EMOTE_ONESHOT_SHY                  = 24,
    EMOTE_ONESHOT_POINT                = 25,
    EMOTE_STATE_STAND                  = 26,
    EMOTE_STATE_READYUNARMED           = 27,
    EMOTE_STATE_WORK                   = 28,
    EMOTE_STATE_POINT                  = 29,
    EMOTE_STATE_NONE                   = 30,
    EMOTE_ONESHOT_WOUND                = 33,
    EMOTE_ONESHOT_WOUNDCRITICAL        = 34,
    EMOTE_ONESHOT_ATTACKUNARMED        = 35,
    EMOTE_ONESHOT_ATTACK1H             = 36,
    EMOTE_ONESHOT_ATTACK2HTIGHT        = 37,
    EMOTE_ONESHOT_ATTACK2HLOOSE        = 38,
    EMOTE_ONESHOT_PARRYUNARMED         = 39,
    EMOTE_ONESHOT_PARRYSHIELD          = 43,
    EMOTE_ONESHOT_READYUNARMED         = 44,
    EMOTE_ONESHOT_READY1H              = 45,
    EMOTE_ONESHOT_READYBOW             = 48,
    EMOTE_ONESHOT_SPELLPRECAST         = 50,
    EMOTE_ONESHOT_SPELLCAST            = 51,
    EMOTE_ONESHOT_BATTLEROAR           = 53,
    EMOTE_ONESHOT_SPECIALATTACK1H      = 54,
    EMOTE_ONESHOT_KICK                 = 60,
    EMOTE_ONESHOT_ATTACKTHROWN         = 61,
    EMOTE_STATE_STUN                   = 64,
    EMOTE_STATE_DEAD                   = 65,
    EMOTE_ONESHOT_SALUTE               = 66,
    EMOTE_STATE_KNEEL                  = 68,
    EMOTE_STATE_USESTANDING            = 69,
    EMOTE_ONESHOT_WAVE_NOSHEATHE       = 70,
    EMOTE_ONESHOT_CHEER_NOSHEATHE      = 71,
    EMOTE_ONESHOT_EAT_NOSHEATHE        = 92,
    EMOTE_STATE_STUN_NOSHEATHE         = 93,
    EMOTE_ONESHOT_DANCE                = 94,
    EMOTE_ONESHOT_SALUTE_NOSHEATH      = 113,
    EMOTE_STATE_USESTANDING_NOSHEATHE  = 133,
    EMOTE_ONESHOT_LAUGH_NOSHEATHE      = 153,
    EMOTE_STATE_WORK_NOSHEATHE         = 173,
    EMOTE_STATE_SPELLPRECAST           = 193,
    EMOTE_ONESHOT_READYRIFLE           = 213,
    EMOTE_STATE_READYRIFLE             = 214,
    EMOTE_STATE_WORK_NOSHEATHE_MINING  = 233,
    EMOTE_STATE_WORK_NOSHEATHE_CHOPWOOD= 234,
    EMOTE_zzOLDONESHOT_LIFTOFF         = 253,
    EMOTE_ONESHOT_LIFTOFF              = 254,
    EMOTE_ONESHOT_YES                  = 273,
    EMOTE_ONESHOT_NO                   = 274,
    EMOTE_ONESHOT_TRAIN                = 275,
    EMOTE_ONESHOT_LAND                 = 293,
    EMOTE_STATE_AT_EASE                = 313,
    EMOTE_STATE_READY1H                = 333,
    EMOTE_STATE_SPELLKNEELSTART        = 353,
    EMOTE_STATE_SUBMERGED              = 373,
    EMOTE_ONESHOT_SUBMERGE             = 374,
    EMOTE_STATE_READY2H                = 375,
    EMOTE_STATE_READYBOW               = 376,
    EMOTE_ONESHOT_MOUNTSPECIAL         = 377,
    EMOTE_STATE_TALK                   = 378,
    EMOTE_STATE_FISHING                = 379,
    EMOTE_ONESHOT_FISHING              = 380,
    EMOTE_ONESHOT_LOOT                 = 381,
    EMOTE_STATE_WHIRLWIND              = 382,
    EMOTE_STATE_DROWNED                = 383,
    EMOTE_STATE_HOLD_BOW               = 384,
    EMOTE_STATE_HOLD_RIFLE             = 385,
    EMOTE_STATE_HOLD_THROWN            = 386,
    EMOTE_ONESHOT_DROWN                = 387,
    EMOTE_ONESHOT_STOMP                = 388,
    EMOTE_ONESHOT_ATTACKOFF            = 389,
    EMOTE_ONESHOT_ATTACKOFFPIERCE      = 390,
    EMOTE_STATE_ROAR                   = 391,
    EMOTE_STATE_LAUGH                  = 392,
    EMOTE_ONESHOT_CREATURE_SPECIAL     = 393,
    EMOTE_ONESHOT_JUMPLANDRUN          = 394,
    EMOTE_ONESHOT_JUMPEND              = 395,
    EMOTE_ONESHOT_TALK_NOSHEATHE       = 396,
    EMOTE_ONESHOT_POINT_NOSHEATHE      = 397,
    EMOTE_STATE_CANNIBALIZE            = 398,
    EMOTE_ONESHOT_JUMPSTART            = 399,
    EMOTE_STATE_DANCESPECIAL           = 400,
    EMOTE_ONESHOT_DANCESPECIAL         = 401,
    EMOTE_ONESHOT_CUSTOMSPELL01        = 402,
    EMOTE_ONESHOT_CUSTOMSPELL02        = 403,
    EMOTE_ONESHOT_CUSTOMSPELL03        = 404,
    EMOTE_ONESHOT_CUSTOMSPELL04        = 405,
    EMOTE_ONESHOT_CUSTOMSPELL05        = 406,
    EMOTE_ONESHOT_CUSTOMSPELL06        = 407,
    EMOTE_ONESHOT_CUSTOMSPELL07        = 408,
    EMOTE_ONESHOT_CUSTOMSPELL08        = 409,
    EMOTE_ONESHOT_CUSTOMSPELL09        = 410,
    EMOTE_ONESHOT_CUSTOMSPELL10        = 411,
    EMOTE_STATE_EXCLAIM                = 412,
    EMOTE_STATE_SIT_CHAIR_MED          = 415,
    EMOTE_STATE_SPELLEFFECT_HOLD       = 422
};

enum Anim
{
    ANIM_STAND                     = 0x0,
    ANIM_DEATH                     = 0x1,
    ANIM_SPELL                     = 0x2,
    ANIM_STOP                      = 0x3,
    ANIM_WALK                      = 0x4,
    ANIM_RUN                       = 0x5,
    ANIM_DEAD                      = 0x6,
    ANIM_RISE                      = 0x7,
    ANIM_STANDWOUND                = 0x8,
    ANIM_COMBATWOUND               = 0x9,
    ANIM_COMBATCRITICAL            = 0xA,
    ANIM_SHUFFLE_LEFT              = 0xB,
    ANIM_SHUFFLE_RIGHT             = 0xC,
    ANIM_WALK_BACKWARDS            = 0xD,
    ANIM_STUN                      = 0xE,
    ANIM_HANDS_CLOSED              = 0xF,
    ANIM_ATTACKUNARMED             = 0x10,
    ANIM_ATTACK1H                  = 0x11,
    ANIM_ATTACK2HTIGHT             = 0x12,
    ANIM_ATTACK2HLOOSE             = 0x13,
    ANIM_PARRYUNARMED              = 0x14,
    ANIM_PARRY1H                   = 0x15,
    ANIM_PARRY2HTIGHT              = 0x16,
    ANIM_PARRY2HLOOSE              = 0x17,
    ANIM_PARRYSHIELD               = 0x18,
    ANIM_READYUNARMED              = 0x19,
    ANIM_READY1H                   = 0x1A,
    ANIM_READY2HTIGHT              = 0x1B,
    ANIM_READY2HLOOSE              = 0x1C,
    ANIM_READYBOW                  = 0x1D,
    ANIM_DODGE                     = 0x1E,
    ANIM_SPELLPRECAST              = 0x1F,
    ANIM_SPELLCAST                 = 0x20,
    ANIM_SPELLCASTAREA             = 0x21,
    ANIM_NPCWELCOME                = 0x22,
    ANIM_NPCGOODBYE                = 0x23,
    ANIM_BLOCK                     = 0x24,
    ANIM_JUMPSTART                 = 0x25,
    ANIM_JUMP                      = 0x26,
    ANIM_JUMPEND                   = 0x27,
    ANIM_FALL                      = 0x28,
    ANIM_SWIMIDLE                  = 0x29,
    ANIM_SWIM                      = 0x2A,
    ANIM_SWIM_LEFT                 = 0x2B,
    ANIM_SWIM_RIGHT                = 0x2C,
    ANIM_SWIM_BACKWARDS            = 0x2D,
    ANIM_ATTACKBOW                 = 0x2E,
    ANIM_FIREBOW                   = 0x2F,
    ANIM_READYRIFLE                = 0x30,
    ANIM_ATTACKRIFLE               = 0x31,
    ANIM_LOOT                      = 0x32,
    ANIM_SPELL_PRECAST_DIRECTED    = 0x33,
    ANIM_SPELL_PRECAST_OMNI        = 0x34,
    ANIM_SPELL_CAST_DIRECTED       = 0x35,
    ANIM_SPELL_CAST_OMNI           = 0x36,
    ANIM_SPELL_BATTLEROAR          = 0x37,
    ANIM_SPELL_READYABILITY        = 0x38,
    ANIM_SPELL_SPECIAL1H           = 0x39,
    ANIM_SPELL_SPECIAL2H           = 0x3A,
    ANIM_SPELL_SHIELDBASH          = 0x3B,
    ANIM_EMOTE_TALK                = 0x3C,
    ANIM_EMOTE_EAT                 = 0x3D,
    ANIM_EMOTE_WORK                = 0x3E,
    ANIM_EMOTE_USE_STANDING        = 0x3F,
    ANIM_EMOTE_EXCLAMATION         = 0x40,
    ANIM_EMOTE_QUESTION            = 0x41,
    ANIM_EMOTE_BOW                 = 0x42,
    ANIM_EMOTE_WAVE                = 0x43,
    ANIM_EMOTE_CHEER               = 0x44,
    ANIM_EMOTE_DANCE               = 0x45,
    ANIM_EMOTE_LAUGH               = 0x46,
    ANIM_EMOTE_SLEEP               = 0x47,
    ANIM_EMOTE_SIT_GROUND          = 0x48,
    ANIM_EMOTE_RUDE                = 0x49,
    ANIM_EMOTE_ROAR                = 0x4A,
    ANIM_EMOTE_KNEEL               = 0x4B,
    ANIM_EMOTE_KISS                = 0x4C,
    ANIM_EMOTE_CRY                 = 0x4D,
    ANIM_EMOTE_CHICKEN             = 0x4E,
    ANIM_EMOTE_BEG                 = 0x4F,
    ANIM_EMOTE_APPLAUD             = 0x50,
    ANIM_EMOTE_SHOUT               = 0x51,
    ANIM_EMOTE_FLEX                = 0x52,
    ANIM_EMOTE_SHY                 = 0x53,
    ANIM_EMOTE_POINT               = 0x54,
    ANIM_ATTACK1HPIERCE            = 0x55,
    ANIM_ATTACK2HLOOSEPIERCE       = 0x56,
    ANIM_ATTACKOFF                 = 0x57,
    ANIM_ATTACKOFFPIERCE           = 0x58,
    ANIM_SHEATHE                   = 0x59,
    ANIM_HIPSHEATHE                = 0x5A,
    ANIM_MOUNT                     = 0x5B,
    ANIM_RUN_LEANRIGHT             = 0x5C,
    ANIM_RUN_LEANLEFT              = 0x5D,
    ANIM_MOUNT_SPECIAL             = 0x5E,
    ANIM_KICK                      = 0x5F,
    ANIM_SITDOWN                   = 0x60,
    ANIM_SITTING                   = 0x61,
    ANIM_SITUP                     = 0x62,
    ANIM_SLEEPDOWN                 = 0x63,
    ANIM_SLEEPING                  = 0x64,
    ANIM_SLEEPUP                   = 0x65,
    ANIM_SITCHAIRLOW               = 0x66,
    ANIM_SITCHAIRMEDIUM            = 0x67,
    ANIM_SITCHAIRHIGH              = 0x68,
    ANIM_LOADBOW                   = 0x69,
    ANIM_LOADRIFLE                 = 0x6A,
    ANIM_ATTACKTHROWN              = 0x6B,
    ANIM_READYTHROWN               = 0x6C,
    ANIM_HOLDBOW                   = 0x6D,
    ANIM_HOLDRIFLE                 = 0x6E,
    ANIM_HOLDTHROWN                = 0x6F,
    ANIM_LOADTHROWN                = 0x70,
    ANIM_EMOTE_SALUTE              = 0x71,
    ANIM_KNEELDOWN                 = 0x72,
    ANIM_KNEELING                  = 0x73,
    ANIM_KNEELUP                   = 0x74,
    ANIM_ATTACKUNARMEDOFF          = 0x75,
    ANIM_SPECIALUNARMED            = 0x76,
    ANIM_STEALTHWALK               = 0x77,
    ANIM_STEALTHSTAND              = 0x78,
    ANIM_KNOCKDOWN                 = 0x79,
    ANIM_EATING                    = 0x7A,
    ANIM_USESTANDINGLOOP           = 0x7B,
    ANIM_CHANNELCASTDIRECTED       = 0x7C,
    ANIM_CHANNELCASTOMNI           = 0x7D,
    ANIM_WHIRLWIND                 = 0x7E,
    ANIM_BIRTH                     = 0x7F,
    ANIM_USESTANDINGSTART          = 0x80,
    ANIM_USESTANDINGEND            = 0x81,
    ANIM_HOWL                      = 0x82,
    ANIM_DROWN                     = 0x83,
    ANIM_DROWNED                   = 0x84,
    ANIM_FISHINGCAST               = 0x85,
    ANIM_FISHINGLOOP               = 0x86,
    ANIM_FLY                       = 0x87,
    ANIM_EMOTE_WORK_NO_SHEATHE     = 0x88,
    ANIM_EMOTE_STUN_NO_SHEATHE     = 0x89,
    ANIM_EMOTE_USE_STANDING_NO_SHEATHE= 0x8A,
    ANIM_SPELL_SLEEP_DOWN          = 0x8B,
    ANIM_SPELL_KNEEL_START         = 0x8C,
    ANIM_SPELL_KNEEL_LOOP          = 0x8D,
    ANIM_SPELL_KNEEL_END           = 0x8E,
    ANIM_SPRINT                    = 0x8F,
    ANIM_IN_FIGHT                  = 0x90,

    ANIM_GAMEOBJ_SPAWN             = 145,
    ANIM_GAMEOBJ_CLOSE             = 146,
    ANIM_GAMEOBJ_CLOSED            = 147,
    ANIM_GAMEOBJ_OPEN              = 148,
    ANIM_GAMEOBJ_OPENED            = 149,
    ANIM_GAMEOBJ_DESTROY           = 150,
    ANIM_GAMEOBJ_DESTROYED         = 151,
    ANIM_GAMEOBJ_REBUILD           = 152,
    ANIM_GAMEOBJ_CUSTOM0           = 153,
    ANIM_GAMEOBJ_CUSTOM1           = 154,
    ANIM_GAMEOBJ_CUSTOM2           = 155,
    ANIM_GAMEOBJ_CUSTOM3           = 156,
    ANIM_GAMEOBJ_DESPAWN           = 157,
    ANIM_HOLD                      = 158,
    ANIM_DECAY                     = 159,
    ANIM_BOWPULL                   = 160,
    ANIM_BOWRELEASE                = 161,
    ANIM_SHIPSTART                 = 162,
    ANIM_SHIPMOVEING               = 163,
    ANIM_SHIPSTOP                  = 164,
    ANIM_GROUPARROW                = 165,
    ANIM_ARROW                     = 166,
    ANIM_CORPSEARROW               = 167,
    ANIM_GUIDEARROW                = 168,
    ANIM_SWAY                      = 169,
    ANIM_DRUIDCATPOUNCE            = 170,
    ANIM_DRUIDCATRIP               = 171,
    ANIM_DRUIDCATRAKE              = 172,
    ANIM_DRUIDCATRAVAGE            = 173,
    ANIM_DRUIDCATCLAW              = 174,
    ANIM_DRUIDCATCOWER             = 175,
    ANIM_DRUIDBEARSWIPE            = 176,
    ANIM_DRUIDBEARBITE             = 177,
    ANIM_DRUIDBEARMAUL             = 178,
    ANIM_DRUIDBEARBASH             = 179,
    ANIM_DRAGONTAIL                = 180,
    ANIM_DRAGONSTOMP               = 181,
    ANIM_DRAGONSPIT                = 182,
    ANIM_DRAGONSPITHOVER           = 183,
    ANIM_DRAGONSPITFLY             = 184,
    ANIM_EMOTEYES                  = 185,
    ANIM_EMOTENO                   = 186,
    ANIM_JUMPLANDRUN               = 187,
    ANIM_LOOTHOLD                  = 188,
    ANIM_LOOTUP                    = 189,
    ANIM_STANDHIGH                 = 190,
    ANIM_IMPACT                    = 191,
    ANIM_LIFTOFF                   = 192,
    ANIM_HOVER                     = 193,
    ANIM_SUCCUBUSENTICE            = 194,
    ANIM_EMOTETRAIN                = 195,
    ANIM_EMOTEDEAD                 = 196,
    ANIM_EMOTEDANCEONCE            = 197,
    ANIM_DEFLECT                   = 198,
    ANIM_EMOTEEATNOSHEATHE         = 199,
    ANIM_LAND                      = 200,
    ANIM_SUBMERGE                  = 201,
    ANIM_SUBMERGED                 = 202,
    ANIM_CANNIBALIZE               = 203,
    ANIM_ARROWBIRTH                = 204,
    ANIM_GROURARROWBIRTH           = 205,
    ANIM_CORPSEARROWBIRTH          = 206,
    ANIM_GUIDEARROWBIRTH           = 207,
    ANIM_EMOTETALKNOSHEATHE        = 208,
    ANIM_EMOTEPOINTNOSHEATHE       = 209,
    ANIM_EMOTESALUTENOSHEATHE      = 210,
    ANIM_EMOTEDANCESPECIAL         = 211,
    ANIM_MUTILATE                  = 212,
    ANIM_CUSTOMSPELL01             = 213,
    ANIM_CUSTOMSPELL02             = 214,
    ANIM_CUSTOMSPELL03             = 215,
    ANIM_CUSTOMSPELL04             = 216,
    ANIM_CUSTOMSPELL05             = 217,
    ANIM_CUSTOMSPELL06             = 218,
    ANIM_CUSTOMSPELL07             = 219,
    ANIM_CUSTOMSPELL08             = 220,
    ANIM_CUSTOMSPELL09             = 221,
    ANIM_CUSTOMSPELL10             = 222,
    ANIM_StealthRun                = 223
};

enum LockKeyType
{
    LOCK_KEY_NONE  = 0,
    LOCK_KEY_ITEM  = 1,
    LOCK_KEY_SKILL = 2
};

enum LockType
{
    LOCKTYPE_PICKLOCK              = 1,
    LOCKTYPE_HERBALISM             = 2,
    LOCKTYPE_MINING                = 3,
    LOCKTYPE_DISARM_TRAP           = 4,
    LOCKTYPE_OPEN                  = 5,
    LOCKTYPE_TREASURE              = 6,
    LOCKTYPE_CALCIFIED_ELVEN_GEMS  = 7,
    LOCKTYPE_CLOSE                 = 8,
    LOCKTYPE_ARM_TRAP              = 9,
    LOCKTYPE_QUICK_OPEN            = 10,
    LOCKTYPE_QUICK_CLOSE           = 11,
    LOCKTYPE_OPEN_TINKERING        = 12,
    LOCKTYPE_OPEN_KNEELING         = 13,
    LOCKTYPE_OPEN_ATTACKING        = 14,
    LOCKTYPE_GAHZRIDIAN            = 15,
    LOCKTYPE_BLASTING              = 16,
    LOCKTYPE_SLOW_OPEN             = 17,
    LOCKTYPE_SLOW_CLOSE            = 18,
    LOCKTYPE_FISHING               = 19
};

enum TrainerType                                            // this is important type for npcs!
{
    TRAINER_TYPE_CLASS             = 0,
    TRAINER_TYPE_MOUNTS            = 1,                     // on blizz it's 2
    TRAINER_TYPE_TRADESKILLS       = 2,
    TRAINER_TYPE_PETS              = 3
};

#define MAX_TRAINER_TYPE 4

enum CreatureType
{
    CREATURE_TYPE_BEAST            = 1,
    CREATURE_TYPE_DRAGONKIN        = 2,
    CREATURE_TYPE_DEMON            = 3,
    CREATURE_TYPE_ELEMENTAL        = 4,
    CREATURE_TYPE_GIANT            = 5,
    CREATURE_TYPE_UNDEAD           = 6,
    CREATURE_TYPE_HUMANOID         = 7,
    CREATURE_TYPE_CRITTER          = 8,
    CREATURE_TYPE_MECHANICAL       = 9,
    CREATURE_TYPE_NOT_SPECIFIED    = 10,
    CREATURE_TYPE_TOTEM            = 11,
    CREATURE_TYPE_NON_COMBAT_PET   = 12,
    CREATURE_TYPE_GAS_CLOUD        = 13
};

uint32 const CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD = (1 << (CREATURE_TYPE_HUMANOID-1)) | (1 << (CREATURE_TYPE_UNDEAD-1));

enum CreatureFamily
{
    CREATURE_FAMILY_WOLF           = 1,
    CREATURE_FAMILY_CAT            = 2,
    CREATURE_FAMILY_SPIDER         = 3,
    CREATURE_FAMILY_BEAR           = 4,
    CREATURE_FAMILY_BOAR           = 5,
    CREATURE_FAMILY_CROCOLISK      = 6,
    CREATURE_FAMILY_CARRION_BIRD   = 7,
    CREATURE_FAMILY_CRAB           = 8,
    CREATURE_FAMILY_GORILLA        = 9,
    CREATURE_FAMILY_RAPTOR         = 11,
    CREATURE_FAMILY_TALLSTRIDER    = 12,
    CREATURE_FAMILY_FELHUNTER      = 15,
    CREATURE_FAMILY_VOIDWALKER     = 16,
    CREATURE_FAMILY_SUCCUBUS       = 17,
    CREATURE_FAMILY_DOOMGUARD      = 19,
    CREATURE_FAMILY_SCORPID        = 20,
    CREATURE_FAMILY_TURTLE         = 21,
    CREATURE_FAMILY_IMP            = 23,
    CREATURE_FAMILY_BAT            = 24,
    CREATURE_FAMILY_HYENA          = 25,
    CREATURE_FAMILY_OWL            = 26,
    CREATURE_FAMILY_WIND_SERPENT   = 27,
    CREATURE_FAMILY_REMOTE_CONTROL = 28,
    CREATURE_FAMILY_FELGUARD       = 29,
    CREATURE_FAMILY_DRAGONHAWK     = 30,
    CREATURE_FAMILY_RAVAGER        = 31,
    CREATURE_FAMILY_WARP_STALKER   = 32,
    CREATURE_FAMILY_SPOREBAT       = 33,
    CREATURE_FAMILY_NETHER_RAY     = 34,
    CREATURE_FAMILY_SERPENT        = 35,
    CREATURE_FAMILY_SEA_LION       = 36
};

enum CreatureTypeFlags
{
    CREATURE_TYPEFLAGS_TAMEABLE   = 0x0001,
    CREATURE_TYPEFLAGS_HERBLOOT   = 0x0100,
    CREATURE_TYPEFLAGS_MININGLOOT = 0x0200
};

enum CreatureEliteType
{
    CREATURE_ELITE_NORMAL          = 0,
    CREATURE_ELITE_ELITE           = 1,
    CREATURE_ELITE_RAREELITE       = 2,
    CREATURE_ELITE_WORLDBOSS       = 3,
    CREATURE_ELITE_RARE            = 4,
    CREATURE_UNKNOWN               = 5                      // found in 2.2.3 for 2 mobs
};

// values based at QuestInfo.dbc
enum QuestTypes
{
    QUEST_TYPE_ELITE               = 1,
    QUEST_TYPE_LIFE                = 21,
    QUEST_TYPE_PVP                 = 41,
    QUEST_TYPE_RAID                = 62,
    QUEST_TYPE_DUNGEON             = 81,
    QUEST_TYPE_WORLD_EVENT         = 82,
    QUEST_TYPE_LEGENDARY           = 83,
    QUEST_TYPE_ESCORT              = 84,
    QUEST_TYPE_HEROIC              = 85,
};

// values based at QuestSort.dbc
enum QuestSort
{
    QUEST_SORT_EPIC                = 1,
    QUEST_SORT_WAILING_CAVERNS_OLD = 21,
    QUEST_SORT_SEASONAL            = 22,
    QUEST_SORT_UNDERCITY_OLD       = 23,
    QUEST_SORT_HERBALISM           = 24,
    QUEST_SORT_SCARLET_MONASTERY_OLD= 25,
    QUEST_SORT_ULDAMN_OLD          = 41,
    QUEST_SORT_WARLOCK             = 61,
    QUEST_SORT_WARRIOR             = 81,
    QUEST_SORT_SHAMAN              = 82,
    QUEST_SORT_FISHING             = 101,
    QUEST_SORT_BLACKSMITHING       = 121,
    QUEST_SORT_PALADIN             = 141,
    QUEST_SORT_MAGE                = 161,
    QUEST_SORT_ROGUE               = 162,
    QUEST_SORT_ALCHEMY             = 181,
    QUEST_SORT_LEATHERWORKING      = 182,
    QUEST_SORT_ENGINERING          = 201,
    QUEST_SORT_TREASURE_MAP        = 221,
    QUEST_SORT_SUNKEN_TEMPLE_OLD   = 241,
    QUEST_SORT_HUNTER              = 261,
    QUEST_SORT_PRIEST              = 262,
    QUEST_SORT_DRUID               = 263,
    QUEST_SORT_TAILORING           = 264,
    QUEST_SORT_SPECIAL             = 284,
    QUEST_SORT_COOKING             = 304,
    QUEST_SORT_FIRST_AID           = 324,
    QUEST_SORT_LEGENDARY           = 344,
    QUEST_SORT_DARKMOON_FAIRE      = 364,
    QUEST_SORT_AHN_QIRAJ_WAR       = 365,
    QUEST_SORT_LUNAR_FESTIVAL      = 366,
    QUEST_SORT_REPUTATION          = 367,
    QUEST_SORT_INVASION            = 368,
    QUEST_SORT_MIDSUMMER           = 369,
    QUEST_SORT_BREWFEST            = 370
};

inline uint8 ClassByQuestSort(int32 QuestSort)
{
    switch(QuestSort)
    {
        case QUEST_SORT_WARLOCK: return CLASS_WARLOCK;
        case QUEST_SORT_WARRIOR: return CLASS_WARRIOR;
        case QUEST_SORT_SHAMAN:  return CLASS_SHAMAN;
        case QUEST_SORT_PALADIN: return CLASS_PALADIN;
        case QUEST_SORT_MAGE:    return CLASS_MAGE;
        case QUEST_SORT_ROGUE:   return CLASS_ROGUE;
        case QUEST_SORT_HUNTER:  return CLASS_HUNTER;
        case QUEST_SORT_PRIEST:  return CLASS_PRIEST;
        case QUEST_SORT_DRUID:   return CLASS_DRUID;
    }
    return 0;
}

enum SkillType
{
    SKILL_FROST                    = 6,
    SKILL_FIRE                     = 8,
    SKILL_ARMS                     = 26,
    SKILL_COMBAT                   = 38,
    SKILL_SUBTLETY                 = 39,
    SKILL_POISONS                  = 40,
    SKILL_SWORDS                   = 43,
    SKILL_AXES                     = 44,
    SKILL_BOWS                     = 45,
    SKILL_GUNS                     = 46,
    SKILL_BEAST_MASTERY            = 50,
    SKILL_SURVIVAL                 = 51,
    SKILL_MACES                    = 54,
    SKILL_HOLY                     = 56,
    SKILL_2H_SWORDS                = 55,
    SKILL_SHADOW                   = 78,
    SKILL_DEFENSE                  = 95,
    SKILL_LANG_COMMON              = 98,
    SKILL_RACIAL_DWARVEN           = 101,
    SKILL_LANG_ORCISH              = 109,
    SKILL_LANG_DWARVEN             = 111,
    SKILL_LANG_DARNASSIAN          = 113,
    SKILL_LANG_TAURAHE             = 115,
    SKILL_DUAL_WIELD               = 118,
    SKILL_RACIAL_TAUREN            = 124,
    SKILL_ORC_RACIAL               = 125,
    SKILL_RACIAL_NIGHT_ELF         = 126,
    SKILL_FIRST_AID                = 129,
    SKILL_FERAL_COMBAT             = 134,
    SKILL_STAVES                   = 136,
    SKILL_LANG_THALASSIAN          = 137,
    SKILL_LANG_DRACONIC            = 138,
    SKILL_LANG_DEMON_TONGUE        = 139,
    SKILL_LANG_TITAN               = 140,
    SKILL_LANG_OLD_TONGUE          = 141,
    SKILL_SURVIVAL2                = 142,
    SKILL_RIDING_HORSE             = 148,
    SKILL_RIDING_WOLF              = 149,
    SKILL_RIDING_RAM               = 152,
    SKILL_RIDING_TIGER             = 150,
    SKILL_SWIMING                  = 155,
    SKILL_2H_MACES                 = 160,
    SKILL_UNARMED                  = 162,
    SKILL_MARKSMANSHIP             = 163,
    SKILL_BLACKSMITHING            = 164,
    SKILL_LEATHERWORKING           = 165,
    SKILL_ALCHEMY                  = 171,
    SKILL_2H_AXES                  = 172,
    SKILL_DAGGERS                  = 173,
    SKILL_THROWN                   = 176,
    SKILL_HERBALISM                = 182,
    SKILL_GENERIC_DND              = 183,
    SKILL_RETRIBUTION              = 184,
    SKILL_COOKING                  = 185,
    SKILL_MINING                   = 186,
    SKILL_PET_IMP                  = 188,
    SKILL_PET_FELHUNTER            = 189,
    SKILL_TAILORING                = 197,
    SKILL_ENGINERING               = 202,
    SKILL_PET_SPIDER               = 203,
    SKILL_PET_VOIDWALKER           = 204,
    SKILL_PET_SUCCUBUS             = 205,
    SKILL_PET_INFERNAL             = 206,
    SKILL_PET_DOOMGUARD            = 207,
    SKILL_PET_WOLF                 = 208,
    SKILL_PET_CAT                  = 209,
    SKILL_PET_BEAR                 = 210,
    SKILL_PET_BOAR                 = 211,
    SKILL_PET_CROCILISK            = 212,
    SKILL_PET_CARRION_BIRD         = 213,
    SKILL_PET_GORILLA              = 215,
    SKILL_PET_CRAB                 = 214,
    SKILL_PET_RAPTOR               = 217,
    SKILL_PET_TALLSTRIDER          = 218,
    SKILL_RACIAL_UNDED             = 220,
    SKILL_WEAPON_TALENTS           = 222,
    SKILL_CROSSBOWS                = 226,
    SKILL_SPEARS                   = 227,
    SKILL_WANDS                    = 228,
    SKILL_POLEARMS                 = 229,
    SKILL_PET_SCORPID              = 236,
    SKILL_ARCANE                   = 237,
    SKILL_OPEN_LOCK                = 242,
    SKILL_PET_TURTLE               = 251,
    SKILL_ASSASSINATION            = 253,
    SKILL_FURY                     = 256,
    SKILL_PROTECTION               = 257,
    SKILL_BEAST_TRAINING           = 261,
    SKILL_PROTECTION2              = 267,
    SKILL_PET_TALENTS              = 270,
    SKILL_PLATE_MAIL               = 293,
    SKILL_LANG_GNOMISH             = 313,
    SKILL_LANG_TROLL               = 315,
    SKILL_ENCHANTING               = 333,
    SKILL_DEMONOLOGY               = 354,
    SKILL_AFFLICTION               = 355,
    SKILL_FISHING                  = 356,
    SKILL_ENHANCEMENT              = 373,
    SKILL_RESTORATION              = 374,
    SKILL_ELEMENTAL_COMBAT         = 375,
    SKILL_SKINNING                 = 393,
    SKILL_MAIL                     = 413,
    SKILL_LEATHER                  = 414,
    SKILL_CLOTH                    = 415,
    SKILL_SHIELD                   = 433,
    SKILL_FIST_WEAPONS             = 473,
    SKILL_RIDING_RAPTOR            = 533,
    SKILL_RIDING_MECHANOSTRIDER    = 553,
    SKILL_RIDING_UNDEAD_HORSE      = 554,
    SKILL_RESTORATION2             = 573,
    SKILL_BALANCE                  = 574,
    SKILL_DESTRUCTION              = 593,
    SKILL_HOLY2                    = 594,
    SKILL_DISCIPLINE               = 613,
    SKILL_LOCKPICKING              = 633,
    SKILL_PET_BAT                  = 653,
    SKILL_PET_HYENA                = 654,
    SKILL_PET_OWL                  = 655,
    SKILL_PET_WIND_SERPENT         = 656,
    SKILL_LANG_GUTTERSPEAK         = 673,
    SKILL_RIDING_KODO              = 713,
    SKILL_RACIAL_TROLL             = 733,
    SKILL_RACIAL_GNOME             = 753,
    SKILL_RACIAL_HUMAN             = 754,
    SKILL_JEWELCRAFTING            = 755,
    SKILL_RACIAL_BLOODELF          = 756,
    SKILL_PET_EVENT_RC             = 758,
    SKILL_LANG_DRAENEI             = 759,
    SKILL_RACIAL_DRAENEI           = 760,
    SKILL_PET_FELGUARD             = 761,
    SKILL_RIDING                   = 762,
    SKILL_PET_DRAGONHAWK           = 763,
    SKILL_PET_NETHER_RAY           = 764,
    SKILL_PET_SPOREBAT             = 765,
    SKILL_PET_WARP_STALKER         = 766,
    SKILL_PET_RAVAGER              = 767,
    SKILL_PET_SERPENT              = 768,
    SKILL_INTERNAL                 = 769
};

#define MAX_SKILL_TYPE               770

inline uint32 SkillByQuestSort(int32 QuestSort)
{
    switch(QuestSort)
    {
        case QUEST_SORT_HERBALISM:      return SKILL_HERBALISM;
        case QUEST_SORT_FISHING:        return SKILL_FISHING;
        case QUEST_SORT_BLACKSMITHING:  return SKILL_BLACKSMITHING;
        case QUEST_SORT_ALCHEMY:        return SKILL_ALCHEMY;
        case QUEST_SORT_LEATHERWORKING: return SKILL_LEATHERWORKING;
        case QUEST_SORT_ENGINERING:     return SKILL_ENGINERING;
        case QUEST_SORT_TAILORING:      return SKILL_TAILORING;
        case QUEST_SORT_COOKING:        return SKILL_COOKING;
        case QUEST_SORT_FIRST_AID:      return SKILL_FIRST_AID;
    }
    return 0;
}

enum SkillCategory
{
    SKILL_CATEGORY_ATTRIBUTES    =  5,
    SKILL_CATEGORY_WEAPON        =  6,
    SKILL_CATEGORY_CLASS         =  7,
    SKILL_CATEGORY_ARMOR         =  8,
    SKILL_CATEGORY_SECONDARY     =  9,                      // secondary professions
    SKILL_CATEGORY_LANGUAGES     = 10,
    SKILL_CATEGORY_PROFESSION    = 11,                      // primary professions
    SKILL_CATEGORY_NOT_DISPLAYED = 12
};

enum TotemCategory
{
    TC_SKINNING_SKIFE              = 1,
    TC_EARTH_TOTEM                 = 2,
    TC_AIR_TOTEM                   = 3,
    TC_FIRE_TOTEM                  = 4,
    TC_WATER_TOTEM                 = 5,
    TC_COPPER_ROD                  = 6,
    TC_SILVER_ROD                  = 7,
    TC_GOLDEN_ROD                  = 8,
    TC_TRUESILVER_ROD              = 9,
    TC_ARCANITE_ROD                = 10,
    TC_MINING_PICK                 = 11,
    TC_PHILOSOPHERS_STONE          = 12,
    TC_BLACKSMITH_HAMMER           = 13,
    TC_ARCLIGHT_SPANNER            = 14,
    TC_GYROMATIC_MA                = 15,
    TC_MASTER_TOTEM                = 21,
    TC_FEL_IRON_ROD                = 41,
    TC_ADAMANTITE_ROD              = 62,
    TC_ETERNIUM_ROD                = 63
};

enum UnitDynFlags
{
    UNIT_DYNFLAG_LOOTABLE          = 0x0001,
    UNIT_DYNFLAG_TRACK_UNIT        = 0x0002,
    UNIT_DYNFLAG_OTHER_TAGGER      = 0x0004,
    UNIT_DYNFLAG_ROOTED            = 0x0008,
    UNIT_DYNFLAG_SPECIALINFO       = 0x0010,
    UNIT_DYNFLAG_DEAD              = 0x0020
};

enum CorpseDynFlags
{
    CORPSE_DYNFLAG_LOOTABLE        = 0x0001
};

// Passive Spell codes explicit used in code
#define SPELL_ID_GENERIC_LEARN                   483
#define SPELL_ID_PASSIVE_BATTLE_STANCE           2457
#define SPELL_ID_PASSIVE_RESURRECTION_SICKNESS   15007
#define SPELL_ID_WEAPON_SWITCH_COOLDOWN_1_5s     6119
#define SPELL_ID_WEAPON_SWITCH_COOLDOWN_1_0s     6123

enum WeatherType
{
    WEATHER_TYPE_FINE       = 0,
    WEATHER_TYPE_RAIN       = 1,
    WEATHER_TYPE_SNOW       = 2,
    WEATHER_TYPE_STORM      = 3,
    WEATHER_TYPE_THUNDERS   = 86,
    WEATHER_TYPE_BLACKRAIN  = 90
};

#define MAX_WEATHER_TYPE 4

enum ChatMsg
{
    CHAT_MSG_ADDON                  = 0xFFFFFFFF,
    CHAT_MSG_SYSTEM                 = 0x00,
    CHAT_MSG_SAY                    = 0x01,
    CHAT_MSG_PARTY                  = 0x02,
    CHAT_MSG_RAID                   = 0x03,
    CHAT_MSG_GUILD                  = 0x04,
    CHAT_MSG_OFFICER                = 0x05,
    CHAT_MSG_YELL                   = 0x06,
    CHAT_MSG_WHISPER                = 0x07,
    CHAT_MSG_WHISPER_INFORM         = 0x08,
    CHAT_MSG_REPLY                  = 0x09,
    CHAT_MSG_EMOTE                  = 0x0A,
    CHAT_MSG_TEXT_EMOTE             = 0x0B,
    CHAT_MSG_MONSTER_SAY            = 0x0C,
    CHAT_MSG_MONSTER_PARTY          = 0x0D,
    CHAT_MSG_MONSTER_YELL           = 0x0E,
    CHAT_MSG_MONSTER_WHISPER        = 0x0F,
    CHAT_MSG_MONSTER_EMOTE          = 0x10,
    CHAT_MSG_CHANNEL                = 0x11,
    CHAT_MSG_CHANNEL_JOIN           = 0x12,
    CHAT_MSG_CHANNEL_LEAVE          = 0x13,
    CHAT_MSG_CHANNEL_LIST           = 0x14,
    CHAT_MSG_CHANNEL_NOTICE         = 0x15,
    CHAT_MSG_CHANNEL_NOTICE_USER    = 0x16,
    CHAT_MSG_AFK                    = 0x17,
    CHAT_MSG_DND                    = 0x18,
    CHAT_MSG_IGNORED                = 0x19,
    CHAT_MSG_SKILL                  = 0x1A,
    CHAT_MSG_LOOT                   = 0x1B,
    CHAT_MSG_MONEY                  = 0x1C,
    CHAT_MSG_OPENING                = 0x1D,
    CHAT_MSG_TRADESKILLS            = 0x1E,
    CHAT_MSG_PET_INFO               = 0x1F,
    CHAT_MSG_COMBAT_MISC_INFO       = 0x20,
    CHAT_MSG_COMBAT_XP_GAIN         = 0x21,
    CHAT_MSG_COMBAT_HONOR_GAIN      = 0x22,
    CHAT_MSG_COMBAT_FACTION_CHANGE  = 0x23,
    CHAT_MSG_BG_SYSTEM_NEUTRAL      = 0x24,
    CHAT_MSG_BG_SYSTEM_ALLIANCE     = 0x25,
    CHAT_MSG_BG_SYSTEM_HORDE        = 0x26,
    CHAT_MSG_RAID_LEADER            = 0x27,
    CHAT_MSG_RAID_WARNING           = 0x28,
    CHAT_MSG_RAID_BOSS_WHISPER      = 0x29,
    CHAT_MSG_RAID_BOSS_EMOTE        = 0x2A,
    CHAT_MSG_FILTERED               = 0x2B,
    CHAT_MSG_BATTLEGROUND           = 0x2C,
    CHAT_MSG_BATTLEGROUND_LEADER    = 0x2D,
    CHAT_MSG_RESTRICTED             = 0x2E,
};

#define MAX_CHAT_MSG_TYPE 0x2F

// Values from ItemPetFood (power of (value-1) used for compare with CreatureFamilyEntry.petDietMask
enum PetDiet
{
    PET_DIET_MEAT     = 1,
    PET_DIET_FISH     = 2,
    PET_DIET_CHEESE   = 3,
    PET_DIET_BREAD    = 4,
    PET_DIET_FUNGAS   = 5,
    PET_DIET_FRUIT    = 6,
    PET_DIET_RAW_MEAT = 7,
    PET_DIET_RAW_FISH = 8
};

#define MAX_PET_DIET 9

#define CHAIN_SPELL_JUMP_RADIUS 10

// Max values for Guild & Guild Bank
#define GUILD_BANK_MAX_TABS         6
#define GUILD_BANK_MAX_SLOTS        98
#define GUILD_BANK_MAX_LOGS         24
#define GUILD_EVENTLOG_MAX_ENTRIES  100
#define GUILD_MAX_RANKS             10

enum AiReaction
{
    AI_REACTION_UNK1    = 1,
    AI_REACTION_AGGRO   = 2,
    AI_REACTION_UNK3    = 3,
    AI_REACTION_UNK4    = 4
};

// Diminishing Returns Types
enum DiminishingReturnsType
{
    DRTYPE_NONE         = 0,                                // this spell is not diminished, but may have limited it's duration to 10s
    DRTYPE_PLAYER       = 1,                                // this spell is diminished only when applied on players
    DRTYPE_ALL          = 2                                 // this spell is diminished in every case
};

// Diminishing Return Groups
enum DiminishingGroup
{
    // Common Groups
    DIMINISHING_NONE,
    DIMINISHING_CONTROL_STUN,                               // Player Controlled stuns
    DIMINISHING_TRIGGER_STUN,                               // By aura proced stuns, usualy chance on hit talents
    DIMINISHING_SLEEP,
    DIMINISHING_CONTROL_ROOT,                               // Immobilizing effects from casted spells
    DIMINISHING_TRIGGER_ROOT,                               // Immobilizing effects from triggered spells like Frostbite
    DIMINISHING_FEAR,                                       // Non-warlock fears
    DIMINISHING_CHARM,
    // Mage Specific
    DIMINISHING_POLYMORPH,
    // Rogue Specific
    DIMINISHING_KIDNEYSHOT,                                 // Kidney Shot is not diminished with Cheap Shot
    // Warlock Specific
    DIMINISHING_DEATHCOIL,                                  // Death Coil Diminish only with another Death Coil
    DIMINISHING_WARLOCK_FEAR,                               // Also with Sedduction
    // Shared Class Specific
    DIMINISHING_BLIND_CYCLONE,                              // From 2.3.0
    DIMINISHING_DISARM,                                     // From 2.3.0
    DIMINISHING_SILENCE,                                    // From 2.3.0
    DIMINISHING_FREEZE,                                     // Hunter's Freezing Trap
    DIMINISHING_KNOCKOUT,                                   // Also with Sap, all Knockout mechanics are here
    DIMINISHING_BANISH,
    // Other
    // Don't Diminish, but limit duration to 10s
    DIMINISHING_LIMITONLY
};

enum DungeonDifficulties
{
    DIFFICULTY_NORMAL = 0,
    DIFFICULTY_HEROIC = 1,
    TOTAL_DIFFICULTIES
};

enum SummonType
{
    SUMMON_TYPE_CRITTER     = 41,
    SUMMON_TYPE_GUARDIAN    = 61,
    SUMMON_TYPE_TOTEM_SLOT1 = 63,
    SUMMON_TYPE_WILD        = 64,
    SUMMON_TYPE_POSESSED    = 65,
    SUMMON_TYPE_DEMON       = 66,
    SUMMON_TYPE_SUMMON      = 67,
    SUMMON_TYPE_TOTEM_SLOT2 = 81,
    SUMMON_TYPE_TOTEM_SLOT3 = 82,
    SUMMON_TYPE_TOTEM_SLOT4 = 83,
    SUMMON_TYPE_TOTEM       = 121,
    SUMMON_TYPE_UNKNOWN3    = 181,
    SUMMON_TYPE_UNKNOWN4    = 187,
    SUMMON_TYPE_UNKNOWN1    = 247,
    SUMMON_TYPE_CRITTER2    = 407,
    SUMMON_TYPE_CRITTER3    = 307,
    SUMMON_TYPE_UNKNOWN5    = 409,
    SUMMON_TYPE_POSESSED3   = 427,
    SUMMON_TYPE_POSESSED2   = 428
};

enum ResponseCodes
{
    RESPONSE_SUCCESS                                       = 0x00,
    RESPONSE_FAILURE                                       = 0x01,
    RESPONSE_CANCELLED                                     = 0x02,
    RESPONSE_DISCONNECTED                                  = 0x03,
    RESPONSE_FAILED_TO_CONNECT                             = 0x04,
    RESPONSE_CONNECTED                                     = 0x05,
    RESPONSE_VERSION_MISMATCH                              = 0x06,

    CSTATUS_CONNECTING                                     = 0x07,
    CSTATUS_NEGOTIATING_SECURITY                           = 0x08,
    CSTATUS_NEGOTIATION_COMPLETE                           = 0x09,
    CSTATUS_NEGOTIATION_FAILED                             = 0x0A,
    CSTATUS_AUTHENTICATING                                 = 0x0B,

    AUTH_OK                                                = 0x0C,
    AUTH_FAILED                                            = 0x0D,
    AUTH_REJECT                                            = 0x0E,
    AUTH_BAD_SERVER_PROOF                                  = 0x0F,
    AUTH_UNAVAILABLE                                       = 0x10,
    AUTH_SYSTEM_ERROR                                      = 0x11,
    AUTH_BILLING_ERROR                                     = 0x12,
    AUTH_BILLING_EXPIRED                                   = 0x13,
    AUTH_VERSION_MISMATCH                                  = 0x14,
    AUTH_UNKNOWN_ACCOUNT                                   = 0x15,
    AUTH_INCORRECT_PASSWORD                                = 0x16,
    AUTH_SESSION_EXPIRED                                   = 0x17,
    AUTH_SERVER_SHUTTING_DOWN                              = 0x18,
    AUTH_ALREADY_LOGGING_IN                                = 0x19,
    AUTH_LOGIN_SERVER_NOT_FOUND                            = 0x1A,
    AUTH_WAIT_QUEUE                                        = 0x1B,
    AUTH_BANNED                                            = 0x1C,
    AUTH_ALREADY_ONLINE                                    = 0x1D,
    AUTH_NO_TIME                                           = 0x1E,
    AUTH_DB_BUSY                                           = 0x1F,
    AUTH_SUSPENDED                                         = 0x20,
    AUTH_PARENTAL_CONTROL                                  = 0x21,
    AUTH_LOCKED_ENFORCED                                   = 0x22,

    REALM_LIST_IN_PROGRESS                                 = 0x23,
    REALM_LIST_SUCCESS                                     = 0x24,
    REALM_LIST_FAILED                                      = 0x25,
    REALM_LIST_INVALID                                     = 0x26,
    REALM_LIST_REALM_NOT_FOUND                             = 0x27,

    ACCOUNT_CREATE_IN_PROGRESS                             = 0x28,
    ACCOUNT_CREATE_SUCCESS                                 = 0x29,
    ACCOUNT_CREATE_FAILED                                  = 0x2A,

    CHAR_LIST_RETRIEVING                                   = 0x2B,
    CHAR_LIST_RETRIEVED                                    = 0x2C,
    CHAR_LIST_FAILED                                       = 0x2D,

    CHAR_CREATE_IN_PROGRESS                                = 0x2E,
    CHAR_CREATE_SUCCESS                                    = 0x2F,
    CHAR_CREATE_ERROR                                      = 0x30,
    CHAR_CREATE_FAILED                                     = 0x31,
    CHAR_CREATE_NAME_IN_USE                                = 0x32,
    CHAR_CREATE_DISABLED                                   = 0x33,
    CHAR_CREATE_PVP_TEAMS_VIOLATION                        = 0x34,
    CHAR_CREATE_SERVER_LIMIT                               = 0x35,
    CHAR_CREATE_ACCOUNT_LIMIT                              = 0x36,
    CHAR_CREATE_SERVER_QUEUE                               = 0x37,
    CHAR_CREATE_ONLY_EXISTING                              = 0x38,
    CHAR_CREATE_EXPANSION                                  = 0x39,

    CHAR_DELETE_IN_PROGRESS                                = 0x3A,
    CHAR_DELETE_SUCCESS                                    = 0x3B,
    CHAR_DELETE_FAILED                                     = 0x3C,
    CHAR_DELETE_FAILED_LOCKED_FOR_TRANSFER                 = 0x3D,
    CHAR_DELETE_FAILED_GUILD_LEADER                        = 0x3E,
    CHAR_DELETE_FAILED_ARENA_CAPTAIN                       = 0x3F,

    CHAR_LOGIN_IN_PROGRESS                                 = 0x40,
    CHAR_LOGIN_SUCCESS                                     = 0x41,
    CHAR_LOGIN_NO_WORLD                                    = 0x42,
    CHAR_LOGIN_DUPLICATE_CHARACTER                         = 0x43,
    CHAR_LOGIN_NO_INSTANCES                                = 0x44,
    CHAR_LOGIN_FAILED                                      = 0x45,
    CHAR_LOGIN_DISABLED                                    = 0x46,
    CHAR_LOGIN_NO_CHARACTER                                = 0x47,
    CHAR_LOGIN_LOCKED_FOR_TRANSFER                         = 0x48,
    CHAR_LOGIN_LOCKED_BY_BILLING                           = 0x49,

    CHAR_NAME_SUCCESS                                      = 0x4A,
    CHAR_NAME_FAILURE                                      = 0x4B,
    CHAR_NAME_NO_NAME                                      = 0x4C,
    CHAR_NAME_TOO_SHORT                                    = 0x4D,
    CHAR_NAME_TOO_LONG                                     = 0x4E,
    CHAR_NAME_INVALID_CHARACTER                            = 0x4F,
    CHAR_NAME_MIXED_LANGUAGES                              = 0x50,
    CHAR_NAME_PROFANE                                      = 0x51,
    CHAR_NAME_RESERVED                                     = 0x52,
    CHAR_NAME_INVALID_APOSTROPHE                           = 0x53,
    CHAR_NAME_MULTIPLE_APOSTROPHES                         = 0x54,
    CHAR_NAME_THREE_CONSECUTIVE                            = 0x55,
    CHAR_NAME_INVALID_SPACE                                = 0x56,
    CHAR_NAME_CONSECUTIVE_SPACES                           = 0x57,
    CHAR_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS        = 0x58,
    CHAR_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END = 0x59,
    CHAR_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME            = 0x5A,
};

/// Ban function modes
enum BanMode
{
    BAN_ACCOUNT,
    BAN_CHARACTER,
    BAN_IP
};

/// Ban function return codes
enum BanReturn
{
    BAN_SUCCESS,
    BAN_SYNTAX_ERROR,
    BAN_NOTFOUND
};
#endif

