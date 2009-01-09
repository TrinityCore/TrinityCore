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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _SPELLMGR_H
#define _SPELLMGR_H

// For static or at-server-startup loaded spell data
// For more high level function for sSpellStore data

#include "SharedDefines.h"
#include "Database/DBCStructure.h"
#include "Database/SQLStorage.h"

#include "Utilities/UnorderedMap.h"

#include "Player.h"

#include <map>

class Player;
class Spell;

extern SQLStorage sSpellThreatStore;

enum SpellFailedReason
{
    SPELL_FAILED_AFFECTING_COMBAT = 0,
    SPELL_FAILED_ALREADY_AT_FULL_HEALTH = 1,
    SPELL_FAILED_ALREADY_AT_FULL_MANA = 2,
    SPELL_FAILED_ALREADY_AT_FULL_POWER = 3,
    SPELL_FAILED_ALREADY_BEING_TAMED = 4,
    SPELL_FAILED_ALREADY_HAVE_CHARM = 5,
    SPELL_FAILED_ALREADY_HAVE_SUMMON = 6,
    SPELL_FAILED_ALREADY_OPEN = 7,
    SPELL_FAILED_AURA_BOUNCED = 8,
    SPELL_FAILED_AUTOTRACK_INTERRUPTED = 9,
    SPELL_FAILED_BAD_IMPLICIT_TARGETS = 10,
    SPELL_FAILED_BAD_TARGETS = 11,
    SPELL_FAILED_CANT_BE_CHARMED = 12,
    SPELL_FAILED_CANT_BE_DISENCHANTED = 13,
    SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL = 14,
    SPELL_FAILED_CANT_BE_MILLED = 15,
    SPELL_FAILED_CANT_BE_PROSPECTED = 16,
    SPELL_FAILED_CANT_CAST_ON_TAPPED = 17,
    SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE = 18,
    SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED = 19,
    SPELL_FAILED_CANT_STEALTH = 20,
    SPELL_FAILED_CASTER_AURASTATE = 21,
    SPELL_FAILED_CASTER_DEAD = 22,
    SPELL_FAILED_CHARMED = 23,
    SPELL_FAILED_CHEST_IN_USE = 24,
    SPELL_FAILED_CONFUSED = 25,
    SPELL_FAILED_DONT_REPORT = 26,
    SPELL_FAILED_EQUIPPED_ITEM = 27,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS = 28,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND = 29,
    SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND = 30,
    SPELL_FAILED_ERROR = 31,
    SPELL_FAILED_FIZZLE = 32,
    SPELL_FAILED_FLEEING = 33,
    SPELL_FAILED_FOOD_LOWLEVEL = 34,
    SPELL_FAILED_HIGHLEVEL = 35,
    SPELL_FAILED_HUNGER_SATIATED = 36,
    SPELL_FAILED_IMMUNE = 37,
    SPELL_FAILED_INCORRECT_AREA = 38,
    SPELL_FAILED_INTERRUPTED = 39,
    SPELL_FAILED_INTERRUPTED_COMBAT = 40,
    SPELL_FAILED_ITEM_ALREADY_ENCHANTED = 41,
    SPELL_FAILED_ITEM_GONE = 42,
    SPELL_FAILED_ITEM_NOT_FOUND = 43,
    SPELL_FAILED_ITEM_NOT_READY = 44,
    SPELL_FAILED_LEVEL_REQUIREMENT = 45,
    SPELL_FAILED_LINE_OF_SIGHT = 46,
    SPELL_FAILED_LOWLEVEL = 47,
    SPELL_FAILED_LOW_CASTLEVEL = 48,
    SPELL_FAILED_MAINHAND_EMPTY = 49,
    SPELL_FAILED_MOVING = 50,
    SPELL_FAILED_NEED_AMMO = 51,
    SPELL_FAILED_NEED_AMMO_POUCH = 52,
    SPELL_FAILED_NEED_EXOTIC_AMMO = 53,
    SPELL_FAILED_NEED_MORE_ITEMS = 54,
    SPELL_FAILED_NOPATH = 55,
    SPELL_FAILED_NOT_BEHIND = 56,
    SPELL_FAILED_NOT_FISHABLE = 57,
    SPELL_FAILED_NOT_FLYING = 58,
    SPELL_FAILED_NOT_HERE = 59,
    SPELL_FAILED_NOT_INFRONT = 60,
    SPELL_FAILED_NOT_IN_CONTROL = 61,
    SPELL_FAILED_NOT_KNOWN = 62,
    SPELL_FAILED_NOT_MOUNTED = 63,
    SPELL_FAILED_NOT_ON_TAXI = 64,
    SPELL_FAILED_NOT_ON_TRANSPORT = 65,
    SPELL_FAILED_NOT_READY = 66,
    SPELL_FAILED_NOT_SHAPESHIFT = 67,
    SPELL_FAILED_NOT_STANDING = 68,
    SPELL_FAILED_NOT_TRADEABLE = 69,
    SPELL_FAILED_NOT_TRADING = 70,
    SPELL_FAILED_NOT_UNSHEATHED = 71,
    SPELL_FAILED_NOT_WHILE_GHOST = 72,
    SPELL_FAILED_NOT_WHILE_LOOTING = 73,
    SPELL_FAILED_NO_AMMO = 74,
    SPELL_FAILED_NO_CHARGES_REMAIN = 75,
    SPELL_FAILED_NO_CHAMPION = 76,
    SPELL_FAILED_NO_COMBO_POINTS = 77,
    SPELL_FAILED_NO_DUELING = 78,
    SPELL_FAILED_NO_ENDURANCE = 79,
    SPELL_FAILED_NO_FISH = 80,
    SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED = 81,
    SPELL_FAILED_NO_MOUNTS_ALLOWED = 82,
    SPELL_FAILED_NO_PET = 83,
    SPELL_FAILED_NO_POWER = 84,
    SPELL_FAILED_NOTHING_TO_DISPEL = 85,
    SPELL_FAILED_NOTHING_TO_STEAL = 86,
    SPELL_FAILED_ONLY_ABOVEWATER = 87,
    SPELL_FAILED_ONLY_DAYTIME = 88,
    SPELL_FAILED_ONLY_INDOORS = 89,
    SPELL_FAILED_ONLY_MOUNTED = 90,
    SPELL_FAILED_ONLY_NIGHTTIME = 91,
    SPELL_FAILED_ONLY_OUTDOORS = 92,
    SPELL_FAILED_ONLY_SHAPESHIFT = 93,
    SPELL_FAILED_ONLY_STEALTHED = 94,
    SPELL_FAILED_ONLY_UNDERWATER = 95,
    SPELL_FAILED_OUT_OF_RANGE = 96,
    SPELL_FAILED_PACIFIED = 97,
    SPELL_FAILED_POSSESSED = 98,
    SPELL_FAILED_REAGENTS = 99,
    SPELL_FAILED_REQUIRES_AREA = 100,
    SPELL_FAILED_REQUIRES_SPELL_FOCUS = 101,
    SPELL_FAILED_ROOTED = 102,
    SPELL_FAILED_SILENCED = 103,
    SPELL_FAILED_SPELL_IN_PROGRESS = 104,
    SPELL_FAILED_SPELL_LEARNED = 105,
    SPELL_FAILED_SPELL_UNAVAILABLE = 106,
    SPELL_FAILED_STUNNED = 107,
    SPELL_FAILED_TARGETS_DEAD = 108,
    SPELL_FAILED_TARGET_AFFECTING_COMBAT = 109,
    SPELL_FAILED_TARGET_AURASTATE = 110,
    SPELL_FAILED_TARGET_DUELING = 111,
    SPELL_FAILED_TARGET_ENEMY = 112,
    SPELL_FAILED_TARGET_ENRAGED = 113,
    SPELL_FAILED_TARGET_FRIENDLY = 114,
    SPELL_FAILED_TARGET_IN_COMBAT = 115,
    SPELL_FAILED_TARGET_IS_PLAYER = 116,
    SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED = 117,
    SPELL_FAILED_TARGET_NOT_DEAD = 118,
    SPELL_FAILED_TARGET_NOT_IN_PARTY = 119,
    SPELL_FAILED_TARGET_NOT_LOOTED = 120,
    SPELL_FAILED_TARGET_NOT_PLAYER = 121,
    SPELL_FAILED_TARGET_NO_POCKETS = 122,
    SPELL_FAILED_TARGET_NO_WEAPONS = 123,
    SPELL_FAILED_TARGET_NO_RANGED_WEAPONS = 124,
    SPELL_FAILED_TARGET_UNSKINNABLE = 125,
    SPELL_FAILED_THIRST_SATIATED = 126,
    SPELL_FAILED_TOO_CLOSE = 127,
    SPELL_FAILED_TOO_MANY_OF_ITEM = 128,
    SPELL_FAILED_TOTEM_CATEGORY = 129,
    SPELL_FAILED_TOTEMS = 130,
    SPELL_FAILED_TRY_AGAIN = 131,
    SPELL_FAILED_UNIT_NOT_BEHIND = 132,
    SPELL_FAILED_UNIT_NOT_INFRONT = 133,
    SPELL_FAILED_WRONG_PET_FOOD = 134,
    SPELL_FAILED_NOT_WHILE_FATIGUED = 135,
    SPELL_FAILED_TARGET_NOT_IN_INSTANCE = 136,
    SPELL_FAILED_NOT_WHILE_TRADING = 137,
    SPELL_FAILED_TARGET_NOT_IN_RAID = 138,
    SPELL_FAILED_TARGET_FREEFORALL = 139,
    SPELL_FAILED_NO_EDIBLE_CORPSES = 140,
    SPELL_FAILED_ONLY_BATTLEGROUNDS = 141,
    SPELL_FAILED_TARGET_NOT_GHOST = 142,
    SPELL_FAILED_TRANSFORM_UNUSABLE = 143,
    SPELL_FAILED_WRONG_WEATHER = 144,
    SPELL_FAILED_DAMAGE_IMMUNE = 145,
    SPELL_FAILED_PREVENTED_BY_MECHANIC = 146,
    SPELL_FAILED_PLAY_TIME = 147,
    SPELL_FAILED_REPUTATION = 148,
    SPELL_FAILED_MIN_SKILL = 149,
    SPELL_FAILED_NOT_IN_ARENA = 150,
    SPELL_FAILED_NOT_ON_SHAPESHIFT = 151,
    SPELL_FAILED_NOT_ON_STEALTHED = 152,
    SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE = 153,
    SPELL_FAILED_NOT_ON_MOUNTED = 154,
    SPELL_FAILED_TOO_SHALLOW = 155,
    SPELL_FAILED_TARGET_NOT_IN_SANCTUARY = 156,
    SPELL_FAILED_TARGET_IS_TRIVIAL = 157,
    SPELL_FAILED_BM_OR_INVISGOD = 158,
    SPELL_FAILED_EXPERT_RIDING_REQUIREMENT = 159,
    SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT = 160,
    SPELL_FAILED_NOT_IDLE = 161,
    SPELL_FAILED_NOT_INACTIVE = 162,
    SPELL_FAILED_PARTIAL_PLAYTIME = 163,
    SPELL_FAILED_NO_PLAYTIME = 164,
    SPELL_FAILED_NOT_IN_BATTLEGROUND = 165,
    SPELL_FAILED_NOT_IN_RAID_INSTANCE = 166,
    SPELL_FAILED_ONLY_IN_ARENA = 167,
    SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE = 168,
    SPELL_FAILED_ON_USE_ENCHANT = 169,
    SPELL_FAILED_NOT_ON_GROUND = 170,
    SPELL_FAILED_CUSTOM_ERROR = 171,
    SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW = 172,
    SPELL_FAILED_TOO_MANY_SOCKETS = 173,
    SPELL_FAILED_INVALID_GLYPH = 174,
    SPELL_FAILED_UNIQUE_GLYPH = 175,
    SPELL_FAILED_GLYPH_SOCKET_LOCKED = 176,
    SPELL_FAILED_NO_VALID_TARGETS = 177,
    SPELL_FAILED_ITEM_AT_MAX_CHARGES = 178,
    SPELL_FAILED_NOT_IN_BARBERSHOP = 179,
    SPELL_FAILED_FISHING_TOO_LOW = 180,
    SPELL_FAILED_UNKNOWN = 181
};

enum SpellFamilyNames
{
    SPELLFAMILY_GENERIC     = 0,
    SPELLFAMILY_UNK1        = 1,                            // events, holidays
    // 2 - unused
    SPELLFAMILY_MAGE        = 3,
    SPELLFAMILY_WARRIOR     = 4,
    SPELLFAMILY_WARLOCK     = 5,
    SPELLFAMILY_PRIEST      = 6,
    SPELLFAMILY_DRUID       = 7,
    SPELLFAMILY_ROGUE       = 8,
    SPELLFAMILY_HUNTER      = 9,
    SPELLFAMILY_PALADIN     = 10,
    SPELLFAMILY_SHAMAN      = 11,
    SPELLFAMILY_UNK2        = 12,                           // 2 spells (silence resistance)
    SPELLFAMILY_POTION      = 13,
    // 14 - unused
    SPELLFAMILY_DEATHKNIGHT = 15,
    // 16 - unused
    SPELLFAMILY_PET         = 17
};

enum SpellDisableTypes
{
    SPELL_DISABLE_PLAYER = 1,
    SPELL_DISABLE_CREATURE = 2
};

enum SpellEffectTargetTypes
{
    SPELL_REQUIRE_NONE,
    SPELL_REQUIRE_UNIT,
    SPELL_REQUIRE_DEST,
    SPELL_REQUIRE_ITEM,
    SPELL_REQUIRE_CASTER,
};

enum SpellSelectTargetTypes
{
    TARGET_TYPE_DEFAULT,
    TARGET_TYPE_UNIT_CASTER,
    TARGET_TYPE_UNIT_TARGET,
    TARGET_TYPE_CHANNEL,
    TARGET_TYPE_AREA_DEST,
    TARGET_TYPE_DEST_CASTER,
    TARGET_TYPE_DEST_TARGET,
    TARGET_TYPE_DEST_DEST,
};

//Some SpellFamilyFlags
#define SPELLFAMILYFLAG_ROGUE_VANISH            0x000000800LL
#define SPELLFAMILYFLAG_ROGUE_STEALTH           0x000400000LL
#define SPELLFAMILYFLAG_ROGUE_BACKSTAB          0x000800004LL
#define SPELLFAMILYFLAG_ROGUE_SAP               0x000000080LL
#define SPELLFAMILYFLAG_ROGUE_FEINT             0x008000000LL
#define SPELLFAMILYFLAG_ROGUE_KIDNEYSHOT        0x000200000LL
#define SPELLFAMILYFLAG_ROGUE__FINISHING_MOVE   0x9003E0000LL
#define SPELLFAMILYFLAG_WARRIOR_SUNDERARMOR     0x000004000LL
#define SPELLFAMILYFLAG_SHAMAN_FROST_SHOCK      0x080000000LL

// Spell clasification
enum SpellSpecific
{
    SPELL_NORMAL            = 0,
    SPELL_SEAL              = 1,
    SPELL_BLESSING          = 2,
    SPELL_AURA              = 3,
    SPELL_STING             = 4,
    SPELL_CURSE             = 5,
    SPELL_ASPECT            = 6,
    SPELL_TRACKER           = 7,
    SPELL_WARLOCK_ARMOR     = 8,
    SPELL_MAGE_ARMOR        = 9,
    SPELL_ELEMENTAL_SHIELD  = 10,
    SPELL_MAGE_POLYMORPH    = 11,
    SPELL_POSITIVE_SHOUT    = 12,
    SPELL_JUDGEMENT         = 13,
    SPELL_BATTLE_ELIXIR     = 14,
    SPELL_GUARDIAN_ELIXIR   = 15,
    SPELL_FLASK_ELIXIR      = 16,
    SPELL_WARLOCK_CORRUPTION= 17,
    SPELL_WELL_FED          = 18,
    SPELL_DRINK             = 19,
    SPELL_FOOD              = 20,
    SPELL_PRESENCE          = 21,
};

SpellSpecific GetSpellSpecific(uint32 spellId);

// Different spell properties
inline float GetSpellRadius(SpellRadiusEntry const *radius) { return (radius ? radius->Radius : 0); }
uint32 GetSpellCastTime(SpellEntry const* spellInfo, Spell const* spell = NULL);
inline float GetSpellMinRange(SpellRangeEntry const *range) { return (range ? range->minRange : 0); }
inline float GetSpellMaxRange(SpellRangeEntry const *range) { return (range ? range->maxRange : 0); }
inline uint32 GetSpellRangeType(SpellRangeEntry const *range) { return (range ? range->type : 0); }
inline uint32 GetSpellRecoveryTime(SpellEntry const *spellInfo) { return spellInfo->RecoveryTime > spellInfo->CategoryRecoveryTime ? spellInfo->RecoveryTime : spellInfo->CategoryRecoveryTime; }
int32 GetSpellDuration(SpellEntry const *spellInfo);
int32 GetSpellMaxDuration(SpellEntry const *spellInfo);

inline bool IsSpellHaveEffect(SpellEntry const *spellInfo, SpellEffects effect)
{
    for(int i= 0; i < 3; ++i)
        if(spellInfo->Effect[i]==effect)
            return true;
    return false;
}

//bool IsNoStackAuraDueToAura(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2);

inline bool IsSealSpell(SpellEntry const *spellInfo)
{
    //Collection of all the seal family flags. No other paladin spell has any of those.
    return spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN &&
        ( spellInfo->SpellFamilyFlags & 0x26000C000A000000LL );
}

inline bool IsElementalShield(SpellEntry const *spellInfo)
{
    // family flags 10 (Lightning), 42 (Earth), 37 (Water), proc shield from T2 8 pieces bonus
    return (spellInfo->SpellFamilyFlags & 0x42000000400LL) || spellInfo->Id == 23552;
}

int32 CompareAuraRanks(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2);
bool IsSingleFromSpellSpecificPerCaster(uint32 spellSpec1, uint32 spellSpec2);
bool IsSingleFromSpellSpecificPerTarget(uint32 spellSpec1, uint32 spellSpec2);
bool IsPassiveSpell(uint32 spellId);

inline bool IsPassiveSpellStackableWithRanks(SpellEntry const* spellProto)
{
    if(!IsPassiveSpell(spellProto->Id))
        return false;

    return !IsSpellHaveEffect(spellProto,SPELL_EFFECT_APPLY_AURA);
}


inline bool IsDeathPersistentSpell(SpellEntry const *spellInfo)
{
    switch(spellInfo->Id)
    {
        case 40214:                                     // Dragonmaw Illusion
        case 35480: case 35481: case 35482:             // Human Illusion
        case 35483: case 39824:                         // Human Illusion
            return true;
    }

    return spellInfo->AttributesEx3 & SPELL_ATTR_EX3_DEATH_PERSISTENT;
}

inline bool IsNonCombatSpell(SpellEntry const *spellInfo)
{
    return (spellInfo->Attributes & SPELL_ATTR_CANT_USED_IN_COMBAT) != 0;
}

bool IsPositiveSpell(uint32 spellId);
bool IsPositiveEffect(uint32 spellId, uint32 effIndex);
bool IsPositiveTarget(uint32 targetA, uint32 targetB);

bool IsSingleTargetSpell(SpellEntry const *spellInfo);
bool IsSingleTargetSpells(SpellEntry const *spellInfo1, SpellEntry const *spellInfo2);

bool IsAuraAddedBySpell(uint32 auraType, uint32 spellId);

uint8 GetSpellAllowedInLocationError(SpellEntry const *spellInfo,uint32 map_id,uint32 zone_id,uint32 area_id);

static bool IsAreaEffectTarget[TOTAL_SPELL_TARGETS];
inline bool IsAreaOfEffectSpell(SpellEntry const *spellInfo)
{
    if(IsAreaEffectTarget[spellInfo->EffectImplicitTargetA[0]] || IsAreaEffectTarget[spellInfo->EffectImplicitTargetB[0]])
        return true;
    if(IsAreaEffectTarget[spellInfo->EffectImplicitTargetA[1]] || IsAreaEffectTarget[spellInfo->EffectImplicitTargetB[1]])
        return true;
    if(IsAreaEffectTarget[spellInfo->EffectImplicitTargetA[2]] || IsAreaEffectTarget[spellInfo->EffectImplicitTargetB[2]])
        return true;
    return false;
}

inline bool IsAreaAuraEffect(uint32 effect)
{
    if( effect == SPELL_EFFECT_APPLY_AREA_AURA_PARTY    ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID     ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_FRIEND   ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_ENEMY    ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_PET      ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_OWNER)
        return true;
    return false;
}

inline bool IsDispelSpell(SpellEntry const *spellInfo)
{
    if (spellInfo->Effect[0] == SPELL_EFFECT_DISPEL ||
        spellInfo->Effect[1] == SPELL_EFFECT_DISPEL ||
        spellInfo->Effect[2] == SPELL_EFFECT_DISPEL )
        return true;
    return false;
}
inline bool isSpellBreakStealth(SpellEntry const* spellInfo)
{
    return !(spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_BREAK_STEALTH);
}

inline bool IsAutoRepeatRangedSpell(SpellEntry const* spellInfo)
{
    return (spellInfo->Attributes & SPELL_ATTR_RANGED) && (spellInfo->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG);
}

uint8 GetErrorAtShapeshiftedCast (SpellEntry const *spellInfo, uint32 form);

inline bool IsChanneledSpell(SpellEntry const* spellInfo)
{
    return (spellInfo->AttributesEx & (SPELL_ATTR_EX_CHANNELED_1 | SPELL_ATTR_EX_CHANNELED_2));
}

inline bool NeedsComboPoints(SpellEntry const* spellInfo)
{
    return (spellInfo->AttributesEx & (SPELL_ATTR_EX_REQ_COMBO_POINTS1 | SPELL_ATTR_EX_REQ_COMBO_POINTS2));
}

inline SpellSchoolMask GetSpellSchoolMask(SpellEntry const* spellInfo)
{
    return SpellSchoolMask(spellInfo->SchoolMask);
}

inline uint32 GetSpellMechanicMask(SpellEntry const* spellInfo, int32 effect)
{
    uint32 mask = 0;
    if (spellInfo->Mechanic)
        mask |= 1<<spellInfo->Mechanic;
    if (spellInfo->EffectMechanic[effect])
        mask |= 1<<spellInfo->EffectMechanic[effect];
    return mask;
}

inline uint32 GetAllSpellMechanicMask(SpellEntry const* spellInfo)
{
    uint32 mask = 0;
    if (spellInfo->Mechanic)
        mask |= 1<<spellInfo->Mechanic;
    for (int i=0; i< 3; ++i)
        if (spellInfo->EffectMechanic[i])
            mask |= 1<<spellInfo->EffectMechanic[i];
    return mask;
}

inline Mechanics GetEffectMechanic(SpellEntry const* spellInfo, int32 effect)
{
    if (spellInfo->EffectMechanic[effect])
        return Mechanics(spellInfo->EffectMechanic[effect]);
    if (spellInfo->Mechanic)
        return Mechanics(spellInfo->Mechanic);
    return MECHANIC_NONE;
}

inline uint32 GetDispellMask(DispelType dispel)
{
    // If dispel all
    if (dispel == DISPEL_ALL)
        return DISPEL_ALL_MASK;
    else
        return (1 << dispel);
}

// Diminishing Returns interaction with spells
DiminishingGroup GetDiminishingReturnsGroupForSpell(SpellEntry const* spellproto, bool triggered);
bool IsDiminishingReturnsGroupDurationLimited(DiminishingGroup group);
DiminishingReturnsType GetDiminishingReturnsGroupType(DiminishingGroup group);

// Spell affects related declarations (accessed using SpellMgr functions)
struct SpellAffectEntry
{
    uint32 SpellClassMask[3];
};
typedef UNORDERED_MAP<uint32, SpellAffectEntry> SpellAffectMap;

// Spell proc event related declarations (accessed using SpellMgr functions)
enum ProcFlags
{
   PROC_FLAG_NONE                          = 0x00000000,

   PROC_FLAG_KILLED                        = 0x00000001,    // 00 Killed by agressor
   PROC_FLAG_KILL                          = 0x00000002,    // 01 Kill target (in most cases need XP/Honor reward)

   PROC_FLAG_SUCCESSFUL_MILEE_HIT          = 0x00000004,    // 02 Successful melee auto attack
   PROC_FLAG_TAKEN_MELEE_HIT               = 0x00000008,    // 03 Taken damage from melee auto attack hit

   PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT    = 0x00000010,    // 04 Successful attack by Spell that use melee weapon
   PROC_FLAG_TAKEN_MELEE_SPELL_HIT         = 0x00000020,    // 05 Taken damage by Spell that use melee weapon

   PROC_FLAG_SUCCESSFUL_RANGED_HIT         = 0x00000040,    // 06 Successful Ranged auto attack
   PROC_FLAG_TAKEN_RANGED_HIT              = 0x00000080,    // 07 Taken damage from ranged auto attack

   PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT   = 0x00000100,    // 08 Successful Ranged attack by Spell that use ranged weapon
   PROC_FLAG_TAKEN_RANGED_SPELL_HIT        = 0x00000200,    // 09 Taken damage by Spell that use ranged weapon

   PROC_FLAG_SUCCESSFUL_POSITIVE_AOE_HIT   = 0x00000400,    // 10 Successful AoE (not 100% shure unused)
   PROC_FLAG_TAKEN_POSITIVE_AOE            = 0x00000800,    // 11 Taken AoE      (not 100% shure unused)

   PROC_FLAG_SUCCESSFUL_AOE_SPELL_HIT      = 0x00001000,    // 12 Successful AoE damage spell hit (not 100% shure unused)
   PROC_FLAG_TAKEN_AOE_SPELL_HIT           = 0x00002000,    // 13 Taken AoE damage spell hit      (not 100% shure unused)

   PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL     = 0x00004000,    // 14 Successful cast positive spell (by default only on healing)
   PROC_FLAG_TAKEN_POSITIVE_SPELL          = 0x00008000,    // 15 Taken positive spell hit (by default only on healing)

   PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT = 0x00010000,    // 16 Successful negative spell cast (by default only on damage)
   PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT      = 0x00020000,    // 17 Taken negative spell (by default only on damage)

   PROC_FLAG_ON_DO_PERIODIC                = 0x00040000,    // 18 Successful do periodic (damage / healing, determined from 14-17 flags)
   PROC_FLAG_ON_TAKE_PERIODIC              = 0x00080000,    // 19 Taken spell periodic (damage / healing, determined from 14-17 flags)

   PROC_FLAG_TAKEN_ANY_DAMAGE              = 0x00100000,    // 20 Taken any damage
   PROC_FLAG_ON_TRAP_ACTIVATION            = 0x00200000,    // 21 On trap activation

   PROC_FLAG_TAKEN_OFFHAND_HIT             = 0x00400000,    // 22 Taken off-hand melee attacks(not used)
   PROC_FLAG_SUCCESSFUL_OFFHAND_HIT        = 0x00800000     // 23 Successful off-hand melee attacks
};

#define MELEE_BASED_TRIGGER_MASK (PROC_FLAG_SUCCESSFUL_MILEE_HIT        | \
                                  PROC_FLAG_TAKEN_MELEE_HIT             | \
                                  PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT  | \
                                  PROC_FLAG_TAKEN_MELEE_SPELL_HIT       | \
                                  PROC_FLAG_SUCCESSFUL_RANGED_HIT       | \
                                  PROC_FLAG_TAKEN_RANGED_HIT            | \
                                  PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT | \
                                  PROC_FLAG_TAKEN_RANGED_SPELL_HIT)

enum ProcFlagsEx
{
   PROC_EX_NONE                = 0x0000000,                 // If none can tigger on Hit/Crit only (passive spells MUST defined by SpellFamily flag)
   PROC_EX_NORMAL_HIT          = 0x0000001,                 // If set only from normal hit (only damage spells)
   PROC_EX_CRITICAL_HIT        = 0x0000002,
   PROC_EX_MISS                = 0x0000004,
   PROC_EX_RESIST              = 0x0000008,
   PROC_EX_DODGE               = 0x0000010,
   PROC_EX_PARRY               = 0x0000020,
   PROC_EX_BLOCK               = 0x0000040,
   PROC_EX_EVADE               = 0x0000080,
   PROC_EX_IMMUNE              = 0x0000100,
   PROC_EX_DEFLECT             = 0x0000200,
   PROC_EX_ABSORB              = 0x0000400,
   PROC_EX_REFLECT             = 0x0000800,
   PROC_EX_INTERRUPT           = 0x0001000,                 // Melee hit result can be Interrupt (not used)
   PROC_EX_RESERVED1           = 0x0002000,
   PROC_EX_RESERVED2           = 0x0004000,
   PROC_EX_RESERVED3           = 0x0008000,
   PROC_EX_EX_TRIGGER_ALWAYS   = 0x0010000,                 // If set trigger always ( no matter another flags) used for drop charges
   PROC_EX_EX_ONE_TIME_TRIGGER = 0x0020000                  // If set trigger always but only one time (not used)
};

struct SpellProcEventEntry
{
    uint32      schoolMask;                                 // if nonzero - bit mask for matching proc condition based on spell candidate's school: Fire=2, Mask=1<<(2-1)=2
    uint32      spellFamilyName;                            // if nonzero - for matching proc condition based on candidate spell's SpellFamilyNamer value
    uint64      spellFamilyMask;                            // if nonzero - for matching proc condition based on candidate spell's SpellFamilyFlags  (like auras 107 and 108 do)
    uint32      spellFamilyMask2;                           // if nonzero - for matching proc condition based on candidate spell's SpellFamilyFlags2 (like auras 107 and 108 do)
    uint32      procFlags;                                  // bitmask for matching proc event
    uint32      procEx;                                     // proc Extend info (see ProcFlagsEx)
    float       ppmRate;                                    // for melee (ranged?) damage spells - proc rate per minute. if zero, falls back to flat chance from Spell.dbc
    float       customChance;                               // Owerride chance (in most cases for debug only)
    uint32      cooldown;                                   // hidden cooldown used for some spell proc events, applied to _triggered_spell_
};

typedef UNORDERED_MAP<uint32, SpellProcEventEntry> SpellProcEventMap;

#define ELIXIR_BATTLE_MASK    0x1
#define ELIXIR_GUARDIAN_MASK  0x2
#define ELIXIR_FLASK_MASK     (ELIXIR_BATTLE_MASK|ELIXIR_GUARDIAN_MASK)
#define ELIXIR_UNSTABLE_MASK  0x4
#define ELIXIR_SHATTRATH_MASK 0x8

typedef std::map<uint32, uint8> SpellElixirMap;

// Spell script target related declarations (accessed using SpellMgr functions)
enum SpellScriptTargetType
{
    SPELL_TARGET_TYPE_GAMEOBJECT = 0,
    SPELL_TARGET_TYPE_CREATURE   = 1,
    SPELL_TARGET_TYPE_DEAD       = 2
};

#define MAX_SPELL_TARGET_TYPE 3

struct SpellTargetEntry
{
    SpellTargetEntry(SpellScriptTargetType type_,uint32 targetEntry_) : type(type_), targetEntry(targetEntry_) {}
    SpellScriptTargetType type;
    uint32 targetEntry;
};

typedef std::multimap<uint32,SpellTargetEntry> SpellScriptTarget;

// coordinates for spells (accessed using SpellMgr functions)
struct SpellTargetPosition
{
    uint32 target_mapId;
    float  target_X;
    float  target_Y;
    float  target_Z;
    float  target_Orientation;
};

typedef UNORDERED_MAP<uint32, SpellTargetPosition> SpellTargetPositionMap;

// Spell pet auras
class PetAura
{
    public:
        PetAura()
        {
            auras.clear();
        }

        PetAura(uint16 petEntry, uint16 aura, bool _removeOnChangePet, int _damage) :
        removeOnChangePet(_removeOnChangePet), damage(_damage)
        {
            auras[petEntry] = aura;
        }

        uint16 GetAura(uint16 petEntry) const
        {
            std::map<uint16, uint16>::const_iterator itr = auras.find(petEntry);
            if(itr != auras.end())
                return itr->second;
            else
            {
                std::map<uint16, uint16>::const_iterator itr = auras.find(0);
                if(itr != auras.end())
                    return itr->second;
                else
                    return 0;
            }
        }

        void AddAura(uint16 petEntry, uint16 aura)
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
        std::map<uint16, uint16> auras;
        bool removeOnChangePet;
        int32 damage;
};
typedef std::map<uint16, PetAura> SpellPetAuraMap;

// Spell rank chain  (accessed using SpellMgr functions)
struct SpellChainNode
{
    uint32 prev;
    uint32 next;
    uint32 first;
    uint32 last;
    uint8  rank;
};

typedef UNORDERED_MAP<uint32, SpellChainNode> SpellChainMap;

//                 spell_id  req_spell
typedef UNORDERED_MAP<uint32, uint32> SpellRequiredMap;

typedef std::multimap<uint32, uint32> SpellsRequiringSpellMap;

// Spell learning properties (accessed using SpellMgr functions)
struct SpellLearnSkillNode
{
    uint32 skill;
    uint32 value;                                           // 0  - max skill value for player level
    uint32 maxvalue;                                        // 0  - max skill value for player level
};

typedef std::map<uint32, SpellLearnSkillNode> SpellLearnSkillMap;

struct SpellLearnSpellNode
{
    uint32 spell;
    bool autoLearned;
};

typedef std::multimap<uint32, SpellLearnSpellNode> SpellLearnSpellMap;

typedef std::multimap<uint32, SkillLineAbilityEntry const*> SkillLineAbilityMap;

typedef std::map<uint32, uint32> PetLevelupSpellSet;
typedef std::map<uint32, PetLevelupSpellSet> PetLevelupSpellMap;

inline bool IsPrimaryProfessionSkill(uint32 skill)
{
    SkillLineEntry const *pSkill = sSkillLineStore.LookupEntry(skill);
    if(!pSkill)
        return false;

    if(pSkill->categoryId != SKILL_CATEGORY_PROFESSION)
        return false;

    return true;
}

inline bool IsProfessionSkill(uint32 skill)
{
    return  IsPrimaryProfessionSkill(skill) || skill == SKILL_FISHING || skill == SKILL_COOKING || skill == SKILL_FIRST_AID;
}

//#define SPELL_ATTR_CU_PLAYERS_ONLY      0x00000001
#define SPELL_ATTR_CU_CONE_BACK         0x00000002
#define SPELL_ATTR_CU_CONE_LINE         0x00000004
#define SPELL_ATTR_CU_SHARE_DAMAGE      0x00000008
#define SPELL_ATTR_CU_AURA_HOT          0x00000010
#define SPELL_ATTR_CU_AURA_DOT          0x00000020
#define SPELL_ATTR_CU_AURA_CC           0x00000040
#define SPELL_ATTR_CU_AURA_SPELL        0x00000080

typedef std::vector<uint32> SpellCustomAttribute;

typedef std::map<int32, std::vector<int32> > SpellLinkedMap;

class SpellMgr
{
    // Constructors
    public:
        SpellMgr();
        ~SpellMgr();

        // Accessors (const or static functions)
    public:
        // Spell affects
        SpellAffectEntry const*GetSpellAffect(uint16 spellId, uint8 effectId) const
        {
            SpellAffectMap::const_iterator itr = mSpellAffectMap.find((spellId<<8) + effectId);
            if( itr != mSpellAffectMap.end( ) )
                return &itr->second;
            return 0;
        }

        bool IsAffectedByMod(SpellEntry const *spellInfo, SpellModifier *mod) const;

        SpellElixirMap const& GetSpellElixirMap() const { return mSpellElixirs; }

        uint32 GetSpellElixirMask(uint32 spellid) const
        {
            SpellElixirMap::const_iterator itr = mSpellElixirs.find(spellid);
            if(itr==mSpellElixirs.end())
                return 0x0;

            return itr->second;
        }

        SpellSpecific GetSpellElixirSpecific(uint32 spellid) const
        {
            uint32 mask = GetSpellElixirMask(spellid);
            if((mask & ELIXIR_FLASK_MASK)==ELIXIR_FLASK_MASK)
                return SPELL_FLASK_ELIXIR;
            else if(mask & ELIXIR_BATTLE_MASK)
                return SPELL_BATTLE_ELIXIR;
            else if(mask & ELIXIR_GUARDIAN_MASK)
                return SPELL_GUARDIAN_ELIXIR;
            else
                return SPELL_NORMAL;
        }

        // Spell proc events
        SpellProcEventEntry const* GetSpellProcEvent(uint32 spellId) const
        {
            SpellProcEventMap::const_iterator itr = mSpellProcEventMap.find(spellId);
            if( itr != mSpellProcEventMap.end( ) )
                return &itr->second;
            return NULL;
        }

        static bool IsSpellProcEventCanTriggeredBy( SpellProcEventEntry const * spellProcEvent, uint32 EventProcFlag, SpellEntry const * procSpell, uint32 procFlags, uint32 procExtra, bool active);

        // Spell target coordinates
        SpellTargetPosition const* GetSpellTargetPosition(uint32 spell_id) const
        {
            SpellTargetPositionMap::const_iterator itr = mSpellTargetPositions.find( spell_id );
            if( itr != mSpellTargetPositions.end( ) )
                return &itr->second;
            return NULL;
        }

        // Spell ranks chains
        SpellChainNode const* GetSpellChainNode(uint32 spell_id) const
        {
            SpellChainMap::const_iterator itr = mSpellChains.find(spell_id);
            if(itr == mSpellChains.end())
                return NULL;

            return &itr->second;
        }

        uint32 GetSpellRequired(uint32 spell_id) const
        {
            SpellRequiredMap::const_iterator itr = mSpellReq.find(spell_id);
            if(itr == mSpellReq.end())
                return NULL;

            return itr->second;
        }

        uint32 GetFirstSpellInChain(uint32 spell_id) const
        {
            if(SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->first;

            return spell_id;
        }

        uint32 GetPrevSpellInChain(uint32 spell_id) const
        {
            if(SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->prev;

            return 0;
        }

        SpellsRequiringSpellMap const& GetSpellsRequiringSpell() const { return mSpellsReqSpell; }

        // Note: not use rank for compare to spell ranks: spell chains isn't linear order
        // Use IsHighRankOfSpell instead
        uint8 GetSpellRank(uint32 spell_id) const
        {
            if(SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->rank;

            return 0;
        }

        uint32 GetLastSpellInChain(uint32 spell_id) const
        {
            if(SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->last;

            return spell_id;
        }

        uint8 IsHighRankOfSpell(uint32 spell1,uint32 spell2) const
        {
            SpellChainMap::const_iterator itr = mSpellChains.find(spell1);

            uint32 rank2 = GetSpellRank(spell2);

            // not ordered correctly by rank value
            if(itr == mSpellChains.end() || !rank2 || itr->second.rank <= rank2)
                return false;

            // check present in same rank chain
            for(; itr != mSpellChains.end(); itr = mSpellChains.find(itr->second.prev))
                if(itr->second.prev==spell2)
                    return true;

            return false;
        }

        bool IsRankSpellDueToSpell(SpellEntry const *spellInfo_1,uint32 spellId_2) const;
        static bool canStackSpellRanks(SpellEntry const *spellInfo);
        bool IsNoStackSpellDueToSpell(uint32 spellId_1, uint32 spellId_2, bool sameCaster) const;

        SpellEntry const* SelectAuraRankForPlayerLevel(SpellEntry const* spellInfo, uint32 playerLevel) const;

        // Spell learning
        SpellLearnSkillNode const* GetSpellLearnSkill(uint32 spell_id) const
        {
            SpellLearnSkillMap::const_iterator itr = mSpellLearnSkills.find(spell_id);
            if(itr != mSpellLearnSkills.end())
                return &itr->second;
            else
                return NULL;
        }

        bool IsSpellLearnSpell(uint32 spell_id) const
        {
            return mSpellLearnSpells.count(spell_id)!=0;
        }

        SpellLearnSpellMap::const_iterator GetBeginSpellLearnSpell(uint32 spell_id) const
        {
            return mSpellLearnSpells.lower_bound(spell_id);
        }

        SpellLearnSpellMap::const_iterator GetEndSpellLearnSpell(uint32 spell_id) const
        {
            return mSpellLearnSpells.upper_bound(spell_id);
        }

        bool IsSpellLearnToSpell(uint32 spell_id1,uint32 spell_id2) const
        {
            SpellLearnSpellMap::const_iterator b = GetBeginSpellLearnSpell(spell_id1);
            SpellLearnSpellMap::const_iterator e = GetEndSpellLearnSpell(spell_id1);
            for(SpellLearnSpellMap::const_iterator i = b; i != e; ++i)
                if(i->second.spell==spell_id2)
                    return true;
            return false;
        }

        static bool IsProfessionSpell(uint32 spellId);
        static bool IsPrimaryProfessionSpell(uint32 spellId);
        bool IsPrimaryProfessionFirstRankSpell(uint32 spellId) const;

        // Spell script targets
        SpellScriptTarget::const_iterator GetBeginSpellScriptTarget(uint32 spell_id) const
        {
            return mSpellScriptTarget.lower_bound(spell_id);
        }

        SpellScriptTarget::const_iterator GetEndSpellScriptTarget(uint32 spell_id) const
        {
            return mSpellScriptTarget.upper_bound(spell_id);
        }

        // Spell correctess for client using
        static bool IsSpellValid(SpellEntry const * spellInfo, Player* pl = NULL, bool msg = true);

        SkillLineAbilityMap::const_iterator GetBeginSkillLineAbilityMap(uint32 spell_id) const
        {
            return mSkillLineAbilityMap.lower_bound(spell_id);
        }

        SkillLineAbilityMap::const_iterator GetEndSkillLineAbilityMap(uint32 spell_id) const
        {
            return mSkillLineAbilityMap.upper_bound(spell_id);
        }

        PetAura const* GetPetAura(uint16 spell_id)
        {
            SpellPetAuraMap::const_iterator itr = mSpellPetAuraMap.find(spell_id);
            if(itr != mSpellPetAuraMap.end())
                return &itr->second;
            else
                return NULL;
        }

        uint32 GetSpellCustomAttr(uint32 spell_id) const
        {
            if(spell_id >= mSpellCustomAttr.size())
                return 0;
            else
                return mSpellCustomAttr[spell_id];
        }

        const std::vector<int32> *GetSpellLinked(int32 spell_id) const
        {
            SpellLinkedMap::const_iterator itr = mSpellLinkedMap.find(spell_id);
            return itr != mSpellLinkedMap.end() ? &(itr->second) : NULL;
        }

        SpellEffectTargetTypes EffectTargetType[TOTAL_SPELL_EFFECTS];
        SpellSelectTargetTypes SpellTargetType[TOTAL_SPELL_TARGETS];

        PetLevelupSpellSet const* GetPetLevelupSpellList(uint32 petFamily) const
        {
            PetLevelupSpellMap::const_iterator itr = mPetLevelupSpellMap.find(petFamily);
            if(itr != mPetLevelupSpellMap.end())
                return &itr->second;
            else
                return NULL;
        }

        // Modifiers
    public:
        static SpellMgr& Instance();

        // Loading data at server startup
        void LoadSpellChains();
        void LoadSpellRequired();
        void LoadSpellLearnSkills();
        void LoadSpellLearnSpells();
        void LoadSpellScriptTarget();
        void LoadSpellAffects();
        void LoadSpellElixirs();
        void LoadSpellProcEvents();
        void LoadSpellTargetPositions();
        void LoadSpellThreats();
        void LoadSkillLineAbilityMap();
        void LoadSpellPetAuras();
        void LoadSpellCustomAttr();
        void LoadSpellLinked();
        void LoadPetLevelupSpellMap();

    private:
        SpellScriptTarget  mSpellScriptTarget;
        SpellChainMap      mSpellChains;
        SpellsRequiringSpellMap   mSpellsReqSpell;
        SpellRequiredMap   mSpellReq;
        SpellLearnSkillMap mSpellLearnSkills;
        SpellLearnSpellMap mSpellLearnSpells;
        SpellTargetPositionMap mSpellTargetPositions;
        SpellAffectMap     mSpellAffectMap;
        SpellElixirMap     mSpellElixirs;
        SpellProcEventMap  mSpellProcEventMap;
        SkillLineAbilityMap mSkillLineAbilityMap;
        SpellPetAuraMap     mSpellPetAuraMap;
        SpellCustomAttribute  mSpellCustomAttr;
        SpellLinkedMap      mSpellLinkedMap;
        PetLevelupSpellMap mPetLevelupSpellMap;
};

#define spellmgr SpellMgr::Instance()
#endif
