/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#include "SpellAuraDefines.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "SQLStorage.h"

#include "UnorderedMap.h"

#include "Player.h"

#include <map>

class Player;
class Spell;
struct SpellModifier;

// only used in code
enum SpellCategories
{
    SPELLCATEGORY_HEALTH_MANA_POTIONS = 4,
    SPELLCATEGORY_DEVOUR_MAGIC        = 12,
    SPELLCATEGORY_JUDGEMENT           = 1210,               // Judgement (seal trigger)
    SPELLCATEGORY_FOOD             = 11,
    SPELLCATEGORY_DRINK            = 59,
};

enum SpellDisableTypes
{
    SPELL_DISABLE_PLAYER            = 0x1,
    SPELL_DISABLE_CREATURE          = 0x2,
    SPELL_DISABLE_PET               = 0x4,
    SPELL_DISABLE_DEPRECATED_SPELL  = 0x8
};

enum SpellEffectTargetTypes
{
    SPELL_REQUIRE_NONE,
    SPELL_REQUIRE_UNIT,
    SPELL_REQUIRE_DEST,
    SPELL_REQUIRE_ITEM,
    SPELL_REQUIRE_CASTER,
    SPELL_REQUIRE_GOBJECT,
};

enum SpellSelectTargetTypes
{
    TARGET_TYPE_DEFAULT,
    TARGET_TYPE_UNIT_CASTER,
    TARGET_TYPE_UNIT_TARGET,
    TARGET_TYPE_UNIT_NEARBY,
    TARGET_TYPE_AREA_SRC,
    TARGET_TYPE_AREA_DST,
    TARGET_TYPE_AREA_CONE,
    TARGET_TYPE_DEST_CASTER,
    TARGET_TYPE_DEST_TARGET,
    TARGET_TYPE_DEST_DEST,
    TARGET_TYPE_DEST_SPECIAL,
    TARGET_TYPE_CHANNEL,
};

//SpellFamilyFlags
enum SpellFamilyFlag
{
    // SPELLFAMILYFLAG  = SpellFamilyFlags[0]
    // SPELLFAMILYFLAG1 = SpellFamilyFlags[1]
    // SPELLFAMILYFLAG2 = SpellFamilyFlags[2]

    // Rogue
    SPELLFAMILYFLAG_ROGUE_VANISH            = 0x00000800,
    SPELLFAMILYFLAG_ROGUE_STEALTH           = 0x00400000,
    SPELLFAMILYFLAG_ROGUE_BACKSTAB          = 0x00800004,
    SPELLFAMILYFLAG_ROGUE_SAP               = 0x00000080,
    SPELLFAMILYFLAG_ROGUE_FEINT             = 0x08000000,
    SPELLFAMILYFLAG_ROGUE_KIDNEYSHOT        = 0x00200000,
    SPELLFAMILYFLAG1_ROGUE_HUNGERFORBLOOD   = 0x01000000,
    SPELLFAMILYFLAG_ROGUE_VAN_EVAS_SPRINT   = 0x00000860,    // Vanish, Evasion, Sprint
    SPELLFAMILYFLAG1_ROGUE_COLDB_SHADOWSTEP = 0x00000240,    // Cold Blood, Shadowstep
    SPELLFAMILYFLAG_ROGUE_KICK              = 0x00000010,   // Kick
    SPELLFAMILYFLAG1_ROGUE_DISMANTLE        = 0x00100000,   // Dismantle
    SPELLFAMILYFLAG_ROGUE_BLADE_FLURRY      = 0x40000000,   // Blade Flurry
    SPELLFAMILYFLAG1_ROGUE_BLADE_FLURRY     = 0x00000800,   // Blade Flurry
    //SPELLFAMILYFLAG_ROGUE__FINISHING_MOVE  = 0x9003E0000LL,

    // Warrior
    SPELLFAMILYFLAG_WARRIOR_SUNDERARMOR     = 0x00004000,
    SPELLFAMILYFLAG_WARRIOR_CHARGE          = 0x00000001,
    SPELLFAMILYFLAG_WARRIOR_SLAM            = 0x00200000,
    SPELLFAMILYFLAG_WARRIOR_EXECUTE         = 0x20000000,
    SPELLFAMILYFLAG_WARRIOR_CONCUSSION_BLOW = 0x04000000,

    // Warlock
    SPELLFAMILYFLAG_WARLOCK_LIFETAP         = 0x00040000,

    // Priest
    SPELLFAMILYFLAG1_PRIEST_PENANCE         = 0x00800000,

    // Druid
    SPELLFAMILYFLAG2_DRUID_STARFALL         = 0x00000100,

    // Paladin
    SPELLFAMILYFLAG1_PALADIN_DIVINESTORM    = 0x00020000,

    // Shaman
    SPELLFAMILYFLAG_SHAMAN_FROST_SHOCK      = 0x80000000,
    SPELLFAMILYFLAG_SHAMAN_HEALING_STREAM   = 0x00002000,
    SPELLFAMILYFLAG_SHAMAN_MANA_SPRING      = 0x00004000,
    SPELLFAMILYFLAG2_SHAMAN_LAVA_LASH       = 0x00000004,
    SPELLFAMILYFLAG_SHAMAN_FLAMETONGUE      = 0x00200000,
    SPELLFAMILYFLAG_SHAMAN_FIRE_NOVA        = 0x28000000,

    // Deathknight
    SPELLFAMILYFLAG_DK_DEATH_STRIKE         = 0x00000010,
    SPELLFAMILYFLAG1_DK_SCOURGE_STRIKE      = 0x08000000,
    SPELLFAMILYFLAG_DK_DEATH_COIL           = 0x00002000,
    SPELLFAMILYFLAG1_DK_HUNGERING_COLD      = 0x00001000,


    // TODO: Figure out a more accurate name for the following familyflag(s)
    SPELLFAMILYFLAG_SHAMAN_TOTEM_EFFECTS    = 0x04000000,  // Seems to be linked to most totems and some totem effects
};


// Spell clasification
enum SpellSpecific
{
    SPELL_SPECIFIC_NORMAL            = 0,
    SPELL_SPECIFIC_SEAL              = 1,
    SPELL_SPECIFIC_AURA              = 3,
    SPELL_SPECIFIC_STING             = 4,
    SPELL_SPECIFIC_CURSE             = 5,
    SPELL_SPECIFIC_ASPECT            = 6,
    SPELL_SPECIFIC_TRACKER           = 7,
    SPELL_SPECIFIC_WARLOCK_ARMOR     = 8,
    SPELL_SPECIFIC_MAGE_ARMOR        = 9,
    SPELL_SPECIFIC_ELEMENTAL_SHIELD  = 10,
    SPELL_SPECIFIC_MAGE_POLYMORPH    = 11,
    SPELL_SPECIFIC_JUDGEMENT         = 13,
    SPELL_SPECIFIC_WARLOCK_CORRUPTION= 17,
    SPELL_SPECIFIC_FOOD              = 19,
    SPELL_SPECIFIC_DRINK             = 20,
    SPELL_SPECIFIC_FOOD_AND_DRINK    = 21,
    SPELL_SPECIFIC_PRESENCE          = 22,
    SPELL_SPECIFIC_CHARM             = 23,
    SPELL_SPECIFIC_SCROLL            = 24,
    SPELL_SPECIFIC_MAGE_ARCANE_BRILLANCE = 25,
    SPELL_SPECIFIC_WARRIOR_ENRAGE    = 26,
    SPELL_SPECIFIC_PRIEST_DIVINE_SPIRIT = 27,
    SPELL_SPECIFIC_HAND              = 28,
    SPELL_SPECIFIC_PHASE             = 29,
};

#define SPELL_LINKED_MAX_SPELLS  200000

enum SpellLinkedType
{
    SPELL_LINK_CAST     = 0,            // +: cast; -: remove
    SPELL_LINK_HIT      = 1 * 200000,
    SPELL_LINK_AURA     = 2 * 200000,   // +: aura; -: immune
    SPELL_LINK_REMOVE   = 0,
};

Unit * GetTriggeredSpellCaster(SpellEntry const * spellInfo, Unit * caster, Unit * target);
SpellSpecific GetSpellSpecific(SpellEntry const * spellInfo);
AuraState GetSpellAuraState(SpellEntry const * spellInfo);

// Different spell properties
inline float GetSpellRadiusForHostile(SpellRadiusEntry const *radius) { return (radius ? radius->radiusHostile : 0); }
inline float GetSpellRadiusForFriend(SpellRadiusEntry const *radius) { return (radius ? radius->radiusFriend : 0); }
uint32 GetSpellCastTime(SpellEntry const* spellInfo, Spell * spell = NULL);
uint32 GetDispelChance(Unit* auraCaster, Unit* target, uint32 spellId, bool offensive, bool *result);
inline float GetSpellMinRangeForHostile(SpellRangeEntry const *range) { return (range ? range->minRangeHostile : 0); }
inline float GetSpellMaxRangeForHostile(SpellRangeEntry const *range) { return (range ? range->maxRangeHostile : 0); }
inline float GetSpellMinRangeForFriend(SpellRangeEntry const *range) { return (range ? range->minRangeFriend : 0); }
inline float GetSpellMaxRangeForFriend(SpellRangeEntry const *range) { return (range ? range->maxRangeFriend : 0); }
inline uint32 GetSpellRangeType(SpellRangeEntry const *range) { return (range ? range->type : 0); }
inline uint32 GetSpellRecoveryTime(SpellEntry const *spellInfo) { return spellInfo->RecoveryTime > spellInfo->CategoryRecoveryTime ? spellInfo->RecoveryTime : spellInfo->CategoryRecoveryTime; }
int32 GetSpellDuration(SpellEntry const *spellInfo);
int32 GetSpellMaxDuration(SpellEntry const *spellInfo);
inline float GetSpellRadius(SpellEntry const *spellInfo, uint32 effectIdx, bool positive)
{
    return positive
        ? GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(spellInfo->EffectRadiusIndex[effectIdx]))
        : GetSpellRadiusForHostile(sSpellRadiusStore.LookupEntry(spellInfo->EffectRadiusIndex[effectIdx]));
}

inline float GetSpellMaxRange(SpellEntry const *spellInfo, bool positive)
{
    return positive
        ? GetSpellMaxRangeForFriend(sSpellRangeStore.LookupEntry(spellInfo->rangeIndex))
        : GetSpellMaxRangeForHostile(sSpellRangeStore.LookupEntry(spellInfo->rangeIndex));
}

inline float GetSpellMinRange(SpellEntry const *spellInfo, bool positive)
{
    return positive
        ? GetSpellMinRangeForFriend(sSpellRangeStore.LookupEntry(spellInfo->rangeIndex))
        : GetSpellMinRangeForHostile(sSpellRangeStore.LookupEntry(spellInfo->rangeIndex));
}

inline float GetSpellMinRange(uint32 id, bool positive)
{
    SpellEntry const *spellInfo = GetSpellStore()->LookupEntry(id);
    if (!spellInfo) return 0;
    return GetSpellMinRange(spellInfo, positive);
}

inline float GetSpellMaxRange(uint32 id, bool positive)
{
    SpellEntry const *spellInfo = GetSpellStore()->LookupEntry(id);
    if (!spellInfo) return 0;
    return GetSpellMaxRange(spellInfo, positive);
}

/*struct DispelEntry
{
    uint64 casterGuid;
    uint32 spellId;
    Unit * caster;
    uint8 stackAmount;

    bool operator < (const DispelEntry & _Right) const
    {
        return (spellId != _Right.spellId ? spellId < _Right.spellId : casterGuid < _Right.casterGuid);
    }
};*/

inline bool IsSpellHaveEffect(SpellEntry const *spellInfo, SpellEffects effect)
{
    for (int i= 0; i < 3; ++i)
        if (SpellEffects(spellInfo->Effect[i]) == effect)
            return true;
    return false;
}

inline bool IsSpellHaveAura(SpellEntry const *spellInfo, AuraType aura)
{
    for (int i= 0; i < 3; ++i)
        if (AuraType(spellInfo->EffectApplyAuraName[i]) == aura)
            return true;
    return false;
}

//bool IsNoStackAuraDueToAura(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2);

inline bool IsSealSpell(SpellEntry const *spellInfo)
{
    //Collection of all the seal family flags. No other paladin spell has any of those.
    return spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN &&
        (spellInfo->SpellFamilyFlags[1] & 0x26000C00
        || spellInfo->SpellFamilyFlags[0] & 0x0A000000);
}

inline bool IsElementalShield(SpellEntry const *spellInfo)
{
    // family flags 10 (Lightning), 42 (Earth), 37 (Water), proc shield from T2 8 pieces bonus
    return (spellInfo->SpellFamilyFlags[1] & 0x420
        || spellInfo->SpellFamilyFlags[0] & 0x00000400)
        || spellInfo->Id == 23552;
}

inline bool IsExplicitDiscoverySpell(SpellEntry const *spellInfo)
{
    return (((spellInfo->Effect[0] == SPELL_EFFECT_CREATE_RANDOM_ITEM
        || spellInfo->Effect[0] == SPELL_EFFECT_CREATE_ITEM_2)
        && spellInfo->Effect[1] == SPELL_EFFECT_SCRIPT_EFFECT)
        || spellInfo->Id == 64323);                          // Book of Glyph Mastery (Effect0 == SPELL_EFFECT_SCRIPT_EFFECT without any other data)
}

inline bool IsLootCraftingSpell(SpellEntry const *spellInfo)
{
    return (spellInfo->Effect[0] == SPELL_EFFECT_CREATE_RANDOM_ITEM ||
        // different random cards from Inscription (121==Virtuoso Inking Set category) r without explicit item
        (spellInfo->Effect[0] == SPELL_EFFECT_CREATE_ITEM_2 &&
        (spellInfo->TotemCategory[0] != 0 || spellInfo->EffectItemType[0]==0)));
}

bool IsHigherHankOfSpell(uint32 spellId_1,uint32 spellId_2);
bool IsSingleFromSpellSpecificPerCaster(SpellSpecific spellSpec1, SpellSpecific spellSpec2);
bool IsSingleFromSpellSpecificPerTarget(SpellSpecific spellSpec1, SpellSpecific spellSpec2);
bool IsPassiveSpell(uint32 spellId);
bool IsPassiveSpell(SpellEntry const * spellInfo);
bool IsAutocastableSpell(uint32 spellId);

uint32 CalculatePowerCost(SpellEntry const * spellInfo, Unit const * caster, SpellSchoolMask schoolMask);

inline bool IsPassiveSpellStackableWithRanks(SpellEntry const* spellProto)
{
    if (!IsPassiveSpell(spellProto->Id))
        return false;

    return !IsSpellHaveEffect(spellProto,SPELL_EFFECT_APPLY_AURA);
}

inline bool IsDeathPersistentSpell(SpellEntry const *spellInfo)
{
    return spellInfo->AttributesEx3 & SPELL_ATTR_EX3_DEATH_PERSISTENT;
}

inline bool IsNonCombatSpell(SpellEntry const *spellInfo)
{
    return (spellInfo->Attributes & SPELL_ATTR_CANT_USED_IN_COMBAT) != 0;
}

bool IsPositiveSpell(uint32 spellId);
bool IsPositiveEffect(uint32 spellId, uint32 effIndex);
bool IsPositiveTarget(uint32 targetA, uint32 targetB);
bool IsDispelableBySpell(SpellEntry const * dispelSpell, uint32 spellId, bool def = false);

bool IsSingleTargetSpell(SpellEntry const *spellInfo);
bool IsSingleTargetSpells(SpellEntry const *spellInfo1, SpellEntry const *spellInfo2);

extern bool IsAreaEffectTarget[TOTAL_SPELL_TARGETS];
extern SpellEffectTargetTypes EffectTargetType[TOTAL_SPELL_EFFECTS];
extern SpellSelectTargetTypes SpellTargetType[TOTAL_SPELL_TARGETS];

inline bool IsCasterSourceTarget(uint32 target)
{
    switch (SpellTargetType[target])
    {
        case TARGET_TYPE_UNIT_CASTER:
        case TARGET_TYPE_AREA_SRC:
        case TARGET_TYPE_AREA_CONE:
        case TARGET_TYPE_DEST_CASTER:
            return true;
        default:
            break;
    }
    return false;
}

inline bool IsPositionTarget(uint32 target)
{
    switch (SpellTargetType[target])
    {
        case TARGET_TYPE_DEST_CASTER:
        case TARGET_TYPE_DEST_TARGET:
        case TARGET_TYPE_DEST_DEST:
            return true;
        default:
            break;
    }
    return false;
}

inline bool IsSpellWithCasterSourceTargetsOnly(SpellEntry const* spellInfo)
{
    for (int i = 0; i < 3; ++i)
    {
        uint32 targetA = spellInfo->EffectImplicitTargetA[i];
        if (targetA && !IsCasterSourceTarget(targetA))
            return false;

        uint32 targetB = spellInfo->EffectImplicitTargetB[i];
        if (targetB && !IsCasterSourceTarget(targetB))
            return false;

        if (!targetA && !targetB)
            return false;
    }
    return true;
}

inline bool IsAreaOfEffectSpell(SpellEntry const *spellInfo)
{
    if (IsAreaEffectTarget[spellInfo->EffectImplicitTargetA[0]] || IsAreaEffectTarget[spellInfo->EffectImplicitTargetB[0]])
        return true;
    if (IsAreaEffectTarget[spellInfo->EffectImplicitTargetA[1]] || IsAreaEffectTarget[spellInfo->EffectImplicitTargetB[1]])
        return true;
    if (IsAreaEffectTarget[spellInfo->EffectImplicitTargetA[2]] || IsAreaEffectTarget[spellInfo->EffectImplicitTargetB[2]])
        return true;
    return false;
}

inline bool IsAreaAuraEffect(uint32 effect)
{
    if (effect == SPELL_EFFECT_APPLY_AREA_AURA_PARTY    ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID     ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_FRIEND   ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_ENEMY    ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_PET      ||
        effect == SPELL_EFFECT_APPLY_AREA_AURA_OWNER)
        return true;
    return false;
}

inline bool HasAreaAuraEffect(SpellEntry const *spellInfo)
{
    for (uint8 i=0;i<MAX_SPELL_EFFECTS;++i)
        if (IsAreaAuraEffect(spellInfo->Effect[i]))
            return true;
    return false;
}

inline bool IsUnitOwnedAuraEffect(uint32 effect)
{
    return (IsAreaAuraEffect(effect) || effect == SPELL_EFFECT_APPLY_AURA);
}

inline bool IsDispel(SpellEntry const *spellInfo)
{
    //spellsteal is also dispel
    if (spellInfo->Effect[0] == SPELL_EFFECT_DISPEL ||
        spellInfo->Effect[1] == SPELL_EFFECT_DISPEL ||
        spellInfo->Effect[2] == SPELL_EFFECT_DISPEL)
        return true;
    return false;
}

inline bool IsDispelSpell(SpellEntry const *spellInfo)
{
    //spellsteal is also dispel
    if (spellInfo->Effect[0] == SPELL_EFFECT_STEAL_BENEFICIAL_BUFF ||
        spellInfo->Effect[1] == SPELL_EFFECT_STEAL_BENEFICIAL_BUFF ||
        spellInfo->Effect[2] == SPELL_EFFECT_STEAL_BENEFICIAL_BUFF
        ||IsDispel(spellInfo))
        return true;
    return false;
}

inline bool isSpellBreakStealth(SpellEntry const* spellInfo)
{
    return !(spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_BREAK_STEALTH);
}

inline bool IsAutoRepeatRangedSpell(SpellEntry const* spellInfo)
{
    return spellInfo->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG;
}

inline bool IsRangedWeaponSpell(SpellEntry const* spellInfo)
{
    //spell->DmgClass == SPELL_DAMAGE_CLASS_RANGED should be checked outside
    return (spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER && !(spellInfo->SpellFamilyFlags[1] & 0x10000000)) // for 53352, cannot find better way
        || (spellInfo->EquippedItemSubClassMask & ITEM_SUBCLASS_MASK_WEAPON_RANGED);
}

SpellCastResult GetErrorAtShapeshiftedCast (SpellEntry const *spellInfo, uint32 form);

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
        if (spellInfo->Effect[i] && spellInfo->EffectMechanic[i])
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
DiminishingLevels GetDiminishingReturnsMaxLevel(DiminishingGroup group);
int32 GetDiminishingReturnsLimitDuration(DiminishingGroup group, SpellEntry const* spellproto);

// Spell proc event related declarations (accessed using SpellMgr functions)
enum ProcFlags
{
   PROC_FLAG_NONE                            = 0x00000000,

   PROC_FLAG_KILLED                          = 0x00000001,    // 00 Killed by agressor
   PROC_FLAG_KILL                            = 0x00000002,    // 01 Kill target (in most cases need XP/Honor reward)

   PROC_FLAG_SUCCESSFUL_MELEE_HIT            = 0x00000004,    // 02 Successful melee auto attack
   PROC_FLAG_TAKEN_MELEE_HIT                 = 0x00000008,    // 03 Taken damage from melee auto attack hit

   PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT      = 0x00000010,    // 04 Successful attack by Spell that use melee weapon
   PROC_FLAG_TAKEN_MELEE_SPELL_HIT           = 0x00000020,    // 05 Taken damage by Spell that use melee weapon

   PROC_FLAG_SUCCESSFUL_RANGED_HIT           = 0x00000040,    // 06 Successful Ranged auto attack
   PROC_FLAG_TAKEN_RANGED_HIT                = 0x00000080,    // 07 Taken damage from ranged auto attack

   PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT     = 0x00000100,    // 08 Successful Ranged attack by Spell that use ranged weapon
   PROC_FLAG_TAKEN_RANGED_SPELL_HIT          = 0x00000200,    // 09 Taken damage by Spell that use ranged weapon

   PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL_HIT   = 0x00000400,    // 10 Successful Positive spell hit
   PROC_FLAG_TAKEN_POSITIVE_SPELL            = 0x00000800,    // 11 Taken Positive spell hit

   PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT   = 0x00001000,    // 12 Successful Negative spell hit
   PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT        = 0x00002000,    // 13 Taken Negative spell hit

   PROC_FLAG_SUCCESSFUL_POSITIVE_MAGIC_SPELL = 0x00004000,    // 14 Successful Positive Magic spell hit
   PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL      = 0x00008000,    // 15 Taken Positive Magic spell hit

   PROC_FLAG_SUCCESSFUL_NEGATIVE_MAGIC_SPELL = 0x00010000,    // 16 Successful Negative Magic spell hit
   PROC_FLAG_TAKEN_NEGATIVE_MAGIC_SPELL      = 0x00020000,    // 17 Taken Negative Magic spell hit

   PROC_FLAG_ON_DO_PERIODIC                  = 0x00040000,    // 18 Successful do periodic (damage / healing, determined from 14,16 flags)
   PROC_FLAG_ON_TAKE_PERIODIC                = 0x00080000,    // 19 Taken spell periodic (damage / healing, determined from 15,17 flags)

   PROC_FLAG_TAKEN_ANY_DAMAGE                = 0x00100000,    // 20 Taken any damage
   PROC_FLAG_ON_TRAP_ACTIVATION              = 0x00200000,    // 21 On trap activation (possibly needs name change to ON_GAMEOBJECT_CAST or USE)

   PROC_FLAG_TAKEN_OFFHAND_HIT               = 0x00400000,    // 22 Taken off-hand melee attacks (this is probably wrong)
   PROC_FLAG_SUCCESSFUL_OFFHAND_HIT          = 0x00800000,    // 23 Successful off-hand melee attacks (this is probably wrong)

   PROC_FLAG_DEATH                           = 0x01000000     // 24 Died in any way
};

#define MELEE_BASED_TRIGGER_MASK (PROC_FLAG_SUCCESSFUL_MELEE_HIT        | \
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
   PROC_EX_FULL_BLOCK          = 0x0002000,                 // block al attack damage
   PROC_EX_RESERVED2           = 0x0004000,
   PROC_EX_NOT_ACTIVE_SPELL    = 0x0008000,                 // Spell mustn't do damage/heal to proc
   PROC_EX_EX_TRIGGER_ALWAYS   = 0x0010000,                 // If set trigger always no matter of hit result
   PROC_EX_EX_ONE_TIME_TRIGGER = 0x0020000,                 // If set trigger always but only one time (not implemented yet)
   PROC_EX_ONLY_ACTIVE_SPELL   = 0x0040000,                 // Spell has to do damage/heal to proc

   // Flags for internal use - do not use these in db!
   PROC_EX_INTERNAL_CANT_PROC  = 0x0800000,
   PROC_EX_INTERNAL_DOT        = 0x1000000,
   PROC_EX_INTERNAL_HOT        = 0x2000000,
   PROC_EX_INTERNAL_TRIGGERED  = 0x4000000,
   PROC_EX_INTERNAL_REQ_FAMILY = 0x8000000
};

#define AURA_SPELL_PROC_EX_MASK \
   (PROC_EX_NORMAL_HIT | PROC_EX_CRITICAL_HIT | PROC_EX_MISS | \
    PROC_EX_RESIST | PROC_EX_DODGE | PROC_EX_PARRY | PROC_EX_BLOCK | \
    PROC_EX_EVADE | PROC_EX_IMMUNE | PROC_EX_DEFLECT | \
    PROC_EX_ABSORB | PROC_EX_REFLECT | PROC_EX_INTERRUPT)

struct SpellProcEventEntry
{
    uint32      schoolMask;                                 // if nonzero - bit mask for matching proc condition based on spell candidate's school: Fire=2, Mask=1<<(2-1)=2
    uint32      spellFamilyName;                            // if nonzero - for matching proc condition based on candidate spell's SpellFamilyNamer value
    flag96      spellFamilyMask;                            // if nonzero - for matching proc condition based on candidate spell's SpellFamilyFlags  (like auras 107 and 108 do)
    uint32      procFlags;                                  // bitmask for matching proc event
    uint32      procEx;                                     // proc Extend info (see ProcFlagsEx)
    float       ppmRate;                                    // for melee (ranged?) damage spells - proc rate per minute. if zero, falls back to flat chance from Spell.dbc
    float       customChance;                               // Owerride chance (in most cases for debug only)
    uint32      cooldown;                                   // hidden cooldown used for some spell proc events, applied to _triggered_spell_
};

struct SpellBonusEntry
{
    float  direct_damage;
    float  dot_damage;
    float  ap_bonus;
    float  ap_dot_bonus;
};

typedef UNORDERED_MAP<uint32, SpellProcEventEntry> SpellProcEventMap;

struct SpellEnchantProcEntry
{
    uint32      customChance;
    float       PPMChance;
    uint32      procEx;
};

typedef UNORDERED_MAP<uint32, SpellEnchantProcEntry> SpellEnchantProcEventMap;
typedef UNORDERED_MAP<uint32, SpellBonusEntry>     SpellBonusMap;

enum SpellGroup
{
    SPELL_GROUP_ELIXIR_BATTLE = 1,
    SPELL_GROUP_ELIXIR_GUARDIAN = 2,
    SPELL_GROUP_ELIXIR_UNSTABLE = 3,
    SPELL_GROUP_ELIXIR_SHATTRATH = 4,
    SPELL_GROUP_CORE_RANGE_MAX = 5,
};

#define SPELL_GROUP_DB_RANGE_MIN 1000

//                  spell_id, group_id
typedef std::multimap<uint32, SpellGroup > SpellSpellGroupMap;
typedef std::pair<SpellSpellGroupMap::const_iterator,SpellSpellGroupMap::const_iterator> SpellSpellGroupMapBounds;

//                      group_id, spell_id
typedef std::multimap<SpellGroup, int32> SpellGroupSpellMap;
typedef std::pair<SpellGroupSpellMap::const_iterator,SpellGroupSpellMap::const_iterator> SpellGroupSpellMapBounds;

enum SpellGroupStackRule
{
    SPELL_GROUP_STACK_RULE_DEFAULT = 0,
    SPELL_GROUP_STACK_RULE_EXCLUSIVE = 1,
    SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER = 2,
};
#define SPELL_GROUP_STACK_RULE_MAX 3

typedef std::map<SpellGroup, SpellGroupStackRule> SpellGroupStackMap;

typedef std::map<uint32, uint16> SpellThreatMap;

// Spell script target related declarations (accessed using SpellMgr functions)
enum SpellScriptTargetType
{
    SPELL_TARGET_TYPE_GAMEOBJECT = 0,
    SPELL_TARGET_TYPE_CREATURE   = 1,
    SPELL_TARGET_TYPE_DEAD       = 2,
    SPELL_TARGET_TYPE_CONTROLLED = 3,
};

#define MAX_SPELL_TARGET_TYPE 4

struct SpellTargetEntry
{
    SpellTargetEntry(SpellScriptTargetType type_,uint32 targetEntry_) : type(type_), targetEntry(targetEntry_) {}
    SpellScriptTargetType type;
    uint32 targetEntry;
};

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

        PetAura(uint32 petEntry, uint32 aura, bool _removeOnChangePet, int _damage) :
        removeOnChangePet(_removeOnChangePet), damage(_damage)
        {
            auras[petEntry] = aura;
        }

        uint32 GetAura(uint32 petEntry) const
        {
            std::map<uint32, uint32>::const_iterator itr = auras.find(petEntry);
            if (itr != auras.end())
                return itr->second;
            std::map<uint32, uint32>::const_iterator itr2 = auras.find(0);
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
        std::map<uint32, uint32> auras;
        bool removeOnChangePet;
        int32 damage;
};
typedef std::map<uint32, PetAura> SpellPetAuraMap;

struct SpellArea
{
    uint32 spellId;
    uint32 areaId;                                          // zone/subzone/or 0 is not limited to zone
    uint32 questStart;                                      // quest start (quest must be active or rewarded for spell apply)
    uint32 questEnd;                                        // quest end (quest don't must be rewarded for spell apply)
    int32  auraSpell;                                       // spell aura must be applied for spell apply)if possitive) and it don't must be applied in other case
    uint32 raceMask;                                        // can be applied only to races
    Gender gender;                                          // can be applied only to gender
    bool questStartCanActive;                               // if true then quest start can be active (not only rewarded)
    bool autocast;                                          // if true then auto applied at area enter, in other case just allowed to cast

    // helpers
    bool IsFitToRequirements(Player const* player, uint32 newZone, uint32 newArea) const;
};

typedef std::multimap<uint32,SpellArea> SpellAreaMap;
typedef std::multimap<uint32,SpellArea const*> SpellAreaForQuestMap;
typedef std::multimap<uint32,SpellArea const*> SpellAreaForAuraMap;
typedef std::multimap<uint32,SpellArea const*> SpellAreaForAreaMap;
typedef std::pair<SpellAreaMap::const_iterator,SpellAreaMap::const_iterator> SpellAreaMapBounds;
typedef std::pair<SpellAreaForQuestMap::const_iterator,SpellAreaForQuestMap::const_iterator> SpellAreaForQuestMapBounds;
typedef std::pair<SpellAreaForAuraMap::const_iterator, SpellAreaForAuraMap::const_iterator>  SpellAreaForAuraMapBounds;
typedef std::pair<SpellAreaForAreaMap::const_iterator, SpellAreaForAreaMap::const_iterator>  SpellAreaForAreaMapBounds;

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

//                   spell_id  req_spell
typedef std::multimap<uint32, uint32> SpellRequiredMap;
typedef std::pair<SpellRequiredMap::const_iterator,SpellRequiredMap::const_iterator> SpellRequiredMapBounds;

//                   req_spell spell_id
typedef std::multimap<uint32, uint32> SpellsRequiringSpellMap;
typedef std::pair<SpellsRequiringSpellMap::const_iterator,SpellsRequiringSpellMap::const_iterator> SpellsRequiringSpellMapBounds;

// Spell learning properties (accessed using SpellMgr functions)
struct SpellLearnSkillNode
{
    uint16 skill;
    uint16 step;
    uint16 value;                                           // 0  - max skill value for player level
    uint16 maxvalue;                                        // 0  - max skill value for player level
};

typedef std::map<uint32, SpellLearnSkillNode> SpellLearnSkillMap;

struct SpellLearnSpellNode
{
    uint32 spell;
    bool active;                                            // show in spellbook or not
    bool autoLearned;
};

typedef std::multimap<uint32, SpellLearnSpellNode> SpellLearnSpellMap;
typedef std::pair<SpellLearnSpellMap::const_iterator,SpellLearnSpellMap::const_iterator> SpellLearnSpellMapBounds;

typedef std::multimap<uint32, SkillLineAbilityEntry const*> SkillLineAbilityMap;
typedef std::pair<SkillLineAbilityMap::const_iterator,SkillLineAbilityMap::const_iterator> SkillLineAbilityMapBounds;

typedef std::multimap<uint32, uint32> PetLevelupSpellSet;
typedef std::map<uint32, PetLevelupSpellSet> PetLevelupSpellMap;

typedef std::map<uint32, uint32> SpellDifficultySearcherMap;

struct PetDefaultSpellsEntry
{
    uint32 spellid[MAX_CREATURE_SPELL_DATA_SLOT];
};

// < 0 for petspelldata id, > 0 for creature_id
typedef std::map<int32, PetDefaultSpellsEntry> PetDefaultSpellsMap;

inline bool IsPrimaryProfessionSkill(uint32 skill)
{
    SkillLineEntry const *pSkill = sSkillLineStore.LookupEntry(skill);
    if (!pSkill)
        return false;

    if (pSkill->categoryId != SKILL_CATEGORY_PROFESSION)
        return false;

    return true;
}

inline bool IsProfessionSkill(uint32 skill)
{
    return  IsPrimaryProfessionSkill(skill) || skill == SKILL_FISHING || skill == SKILL_COOKING || skill == SKILL_FIRST_AID;
}

#define SPELL_ATTR_CU_CONE_BACK         0x00000002
#define SPELL_ATTR_CU_CONE_LINE         0x00000004
#define SPELL_ATTR_CU_SHARE_DAMAGE      0x00000008
#define SPELL_ATTR_CU_AURA_CC           0x00000040
#define SPELL_ATTR_CU_DIRECT_DAMAGE     0x00000100
#define SPELL_ATTR_CU_CHARGE            0x00000200
#define SPELL_ATTR_CU_LINK_CAST         0x00000400
#define SPELL_ATTR_CU_LINK_HIT          0x00000800
#define SPELL_ATTR_CU_LINK_AURA         0x00001000
#define SPELL_ATTR_CU_LINK_REMOVE       0x00002000
#define SPELL_ATTR_CU_PICKPOCKET        0x00004000
#define SPELL_ATTR_CU_EXCLUDE_SELF      0x00008000
#define SPELL_ATTR_CU_NEGATIVE_EFF0     0x00010000
#define SPELL_ATTR_CU_NEGATIVE_EFF1     0x00020000
#define SPELL_ATTR_CU_NEGATIVE_EFF2     0x00040000
#define SPELL_ATTR_CU_NEGATIVE          0x00070000

typedef std::vector<uint32> SpellCustomAttribute;
typedef std::vector<bool> EnchantCustomAttribute;

typedef std::map<int32, std::vector<int32> > SpellLinkedMap;

inline bool IsProfessionOrRidingSkill(uint32 skill)
{
    return  IsProfessionSkill(skill) || skill == SKILL_RIDING;
}

class SpellMgr
{
    // Constructors
    public:
        SpellMgr();
        ~SpellMgr();

    // Accessors (const or static functions)
    public:

        bool IsAffectedByMod(SpellEntry const *spellInfo, SpellModifier *mod) const;

        SpellSpellGroupMapBounds GetSpellSpellGroupMapBounds(uint32 spell_id) const
        {
            spell_id = GetFirstSpellInChain(spell_id);
            return SpellSpellGroupMapBounds(mSpellSpellGroup.lower_bound(spell_id),mSpellSpellGroup.upper_bound(spell_id));
        }
        uint32 IsSpellMemberOfSpellGroup(uint32 spellid, SpellGroup groupid) const
        {
            SpellSpellGroupMapBounds spellGroup = GetSpellSpellGroupMapBounds(spellid);
            for (SpellSpellGroupMap::const_iterator itr = spellGroup.first; itr != spellGroup.second ; ++itr)
            {
                if (itr->second == groupid)
                    return true;
            }
            return false;
        }

        SpellGroupSpellMapBounds GetSpellGroupSpellMapBounds(SpellGroup group_id) const
        {
            return SpellGroupSpellMapBounds(mSpellGroupSpell.lower_bound(group_id),mSpellGroupSpell.upper_bound(group_id));
        }
        void GetSetOfSpellsInSpellGroup(SpellGroup group_id, std::set<uint32>& foundSpells) const
        {
            std::set<SpellGroup> usedGroups;
            GetSetOfSpellsInSpellGroup(group_id, foundSpells, usedGroups);
        }
        void GetSetOfSpellsInSpellGroup(SpellGroup group_id, std::set<uint32>& foundSpells, std::set<SpellGroup>& usedGroups) const
        {
            if (usedGroups.find(group_id) != usedGroups.end())
                return;
            usedGroups.insert(group_id);

            SpellGroupSpellMapBounds groupSpell = GetSpellGroupSpellMapBounds(group_id);
            for (SpellGroupSpellMap::const_iterator itr = groupSpell.first; itr != groupSpell.second ; ++itr)
            {
                if (itr->second < 0)
                {
                    SpellGroup currGroup = (SpellGroup)abs(itr->second);
                    GetSetOfSpellsInSpellGroup(currGroup, foundSpells, usedGroups);
                }
                else
                {
                    foundSpells.insert(itr->second);
                }
            }
        }

        SpellGroupStackRule CheckSpellGroupStackRules(uint32 spellid_1, uint32 spellid_2) const
        {
            spellid_1 = GetFirstSpellInChain(spellid_1);
            spellid_2 = GetFirstSpellInChain(spellid_2);
            if (spellid_1 == spellid_2)
                return SPELL_GROUP_STACK_RULE_DEFAULT;
            // find SpellGroups which are common for both spells
            SpellSpellGroupMapBounds spellGroup1 = GetSpellSpellGroupMapBounds(spellid_1);
            std::set<SpellGroup> groups;
            for (SpellSpellGroupMap::const_iterator itr = spellGroup1.first; itr != spellGroup1.second ; ++itr)
            {
                if (IsSpellMemberOfSpellGroup(spellid_2, itr->second))
                {
                    bool add = true;
                    SpellGroupSpellMapBounds groupSpell = GetSpellGroupSpellMapBounds(itr->second);
                    for (SpellGroupSpellMap::const_iterator itr2 = groupSpell.first; itr2 != groupSpell.second ; ++itr2)
                    {
                        if (itr2->second < 0)
                        {
                            SpellGroup currGroup = (SpellGroup)abs(itr2->second);
                            if (IsSpellMemberOfSpellGroup(spellid_1, currGroup) && IsSpellMemberOfSpellGroup(spellid_2, currGroup))
                            {
                                add = false;
                                break;
                            }
                        }
                    }
                    if (add)
                        groups.insert(itr->second);
                }
            }

            SpellGroupStackRule rule = SPELL_GROUP_STACK_RULE_DEFAULT;

            for (std::set<SpellGroup>::iterator itr = groups.begin() ; itr!= groups.end() ; ++itr)
            {
                SpellGroupStackMap::const_iterator found = mSpellGroupStack.find(*itr);
                if (found != mSpellGroupStack.end())
                    rule = found->second;
                if (rule)
                    break;
            }
            return rule;
        }

        uint16 GetSpellThreat(uint32 spellid) const
        {
            SpellThreatMap::const_iterator itr = mSpellThreatMap.find(spellid);
            if (itr == mSpellThreatMap.end())
                return 0;

            return itr->second;
        }

        // Spell proc events
        SpellProcEventEntry const* GetSpellProcEvent(uint32 spellId) const
        {
            SpellProcEventMap::const_iterator itr = mSpellProcEventMap.find(spellId);
            if (itr != mSpellProcEventMap.end())
                return &itr->second;
            return NULL;
        }

        bool IsSpellProcEventCanTriggeredBy(SpellProcEventEntry const * spellProcEvent, uint32 EventProcFlag, SpellEntry const * procSpell, uint32 procFlags, uint32 procExtra, bool active);

        SpellEnchantProcEntry const* GetSpellEnchantProcEvent(uint32 enchId) const
        {
            SpellEnchantProcEventMap::const_iterator itr = mSpellEnchantProcEventMap.find(enchId);
            if (itr != mSpellEnchantProcEventMap.end())
                return &itr->second;
            return NULL;
        }

        // Spell bonus data
        SpellBonusEntry const* GetSpellBonusData(uint32 spellId) const
        {
            // Lookup data
            SpellBonusMap::const_iterator itr = mSpellBonusMap.find(spellId);
            if (itr != mSpellBonusMap.end())
                return &itr->second;
            // Not found, try lookup for 1 spell rank if exist
            if (uint32 rank_1 = GetFirstSpellInChain(spellId))
            {
                SpellBonusMap::const_iterator itr2 = mSpellBonusMap.find(rank_1);
                if (itr2 != mSpellBonusMap.end())
                    return &itr2->second;
            }
            return NULL;
        }

        // Spell Difficulty data
        SpellEntry const* GetSpellForDifficultyFromSpell(SpellEntry const* spell, Unit* Caster)
        {
            //spell never can be NULL in this case!
            if (!Caster->ToCreature() || !Caster->ToCreature()->GetMap() ||  !Caster->ToCreature()->GetMap()->IsDungeon())
                return spell;

            uint32 mode = uint32(Caster->ToCreature()->GetMap()->GetSpawnMode());
            if (mode >= MAX_DIFFICULTY)
            {
                sLog.outError("GetSpellForDifficultyFromSpell: Incorrect Difficulty for spell %u.", spell->Id);
                return spell;//return source spell
            }
            uint32 SpellDiffId = GetSpellDifficultyId(spell->Id);
            if (!SpellDiffId)
                return spell;//return source spell, it has only REGULAR_DIFFICULTY

            SpellDifficultyEntry const *SpellDiff = sSpellDifficultyStore.LookupEntry(SpellDiffId);
            if (!SpellDiff)
            {
                sLog.outDebug("GetSpellForDifficultyFromSpell: SpellDifficultyEntry not found for spell %u. This Should never happen.", spell->Id);
                return spell;//return source spell
            }
            if (SpellDiff->SpellID[mode] <= 0 && mode > DUNGEON_DIFFICULTY_HEROIC)
            {
                uint8 baseMode = mode;
                mode -= 2;
                sLog.outDebug("GetSpellForDifficultyFromSpell: spell %u mode %u spell is NULL, using mode %u", spell->Id, baseMode, mode);
            }
            if (SpellDiff->SpellID[mode] <= 0)
            {
                sLog.outErrorDb("GetSpellForDifficultyFromSpell: spell %u mode %u spell is 0. Check spelldifficulty_dbc!", spell->Id, mode);
                return spell;
            }
            SpellEntry const*  newSpell = sSpellStore.LookupEntry(SpellDiff->SpellID[mode]);
            if (!newSpell)
            {
                sLog.outDebug("GetSpellForDifficultyFromSpell: spell %u not found in SpellStore. Check spelldifficulty_dbc!", SpellDiff->SpellID[mode]);
                return spell;
            }
            sLog.outDebug("GetSpellForDifficultyFromSpell: spellid for spell %u in mode %u is %u ", spell->Id, mode, newSpell->Id);
            return newSpell;
        }

        // Spell target coordinates
        SpellTargetPosition const* GetSpellTargetPosition(uint32 spell_id) const
        {
            SpellTargetPositionMap::const_iterator itr = mSpellTargetPositions.find(spell_id);
            if (itr != mSpellTargetPositions.end())
                return &itr->second;
            return NULL;
        }

        // Spell ranks chains
        SpellChainNode const* GetSpellChainNode(uint32 spell_id) const
        {
            SpellChainMap::const_iterator itr = mSpellChains.find(spell_id);
            if (itr == mSpellChains.end())
                return NULL;

            return &itr->second;
        }

        uint32 GetFirstSpellInChain(uint32 spell_id) const
        {
            if (SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->first;

            return spell_id;
        }

        uint32 GetSpellWithRank(uint32 spell_id, uint32 rank) const
        {
            if (SpellChainNode const* node = GetSpellChainNode(spell_id))
            {
                if (rank != node->rank)
                    return GetSpellWithRank(node->rank < rank ? node->next : node->prev, rank);
            }
            return spell_id;
        }

        uint32 GetPrevSpellInChain(uint32 spell_id) const
        {
            if (SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->prev;

            return 0;
        }

        uint32 GetNextSpellInChain(uint32 spell_id) const
        {
            if (SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->next;

            return 0;
        }

        SpellRequiredMapBounds GetSpellsRequiredForSpellBounds(uint32 spell_id) const
        {
            return SpellRequiredMapBounds(mSpellReq.lower_bound(spell_id),mSpellReq.upper_bound(spell_id));
        }

        SpellsRequiringSpellMapBounds GetSpellsRequiringSpellBounds(uint32 spell_id) const
        {
            return SpellsRequiringSpellMapBounds(mSpellsReqSpell.lower_bound(spell_id),mSpellsReqSpell.upper_bound(spell_id));
        }
        bool IsSpellRequiringSpell(uint32 spellid, uint32 req_spellid) const
        {
            SpellsRequiringSpellMapBounds spellsRequiringSpell = GetSpellsRequiringSpellBounds(req_spellid);
            for (SpellsRequiringSpellMap::const_iterator itr = spellsRequiringSpell.first; itr != spellsRequiringSpell.second; ++itr)
            {
                if (itr->second == spellid)
                    return true;
            }
            return false;
        }

        uint8 GetSpellRank(uint32 spell_id) const
        {
            if (SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->rank;

            return 0;
        }

        uint32 GetLastSpellInChain(uint32 spell_id) const
        {
            if (SpellChainNode const* node = GetSpellChainNode(spell_id))
                return node->last;

            return spell_id;
        }

        uint32 IsArenaAllowedEnchancment(uint32 ench_id) const
        {
            return mEnchantCustomAttr[ench_id];
        }

        uint8 IsHighRankOfSpell(uint32 spell1,uint32 spell2) const
        {
            SpellChainMap::const_iterator itr1 = mSpellChains.find(spell1);
            SpellChainMap::const_iterator itr2 = mSpellChains.find(spell2);
            if (itr1 == mSpellChains.end() || itr2 == mSpellChains.end())
                return false;

            if (itr1->second.first == itr2->second.first)
                if (itr1->second.rank > itr2->second.rank)
                    return true;
            return false;
        }

        bool IsRankSpellDueToSpell(SpellEntry const *spellInfo_1,uint32 spellId_2) const;
        static bool canStackSpellRanks(SpellEntry const *spellInfo);
        bool CanAurasStack(SpellEntry const *spellInfo_1, SpellEntry const *spellInfo_2, bool sameCaster) const;

        SpellEntry const* SelectAuraRankForPlayerLevel(SpellEntry const* spellInfo, uint32 playerLevel) const;

        // Spell learning
        SpellLearnSkillNode const* GetSpellLearnSkill(uint32 spell_id) const
        {
            SpellLearnSkillMap::const_iterator itr = mSpellLearnSkills.find(spell_id);
            if (itr != mSpellLearnSkills.end())
                return &itr->second;
            else
                return NULL;
        }

        bool IsSpellLearnSpell(uint32 spell_id) const
        {
            return mSpellLearnSpells.find(spell_id) != mSpellLearnSpells.end();
        }

        SpellLearnSpellMapBounds GetSpellLearnSpellMapBounds(uint32 spell_id) const
        {
            return SpellLearnSpellMapBounds(mSpellLearnSpells.lower_bound(spell_id),mSpellLearnSpells.upper_bound(spell_id));
        }

        bool IsSpellLearnToSpell(uint32 spell_id1,uint32 spell_id2) const
        {
            SpellLearnSpellMapBounds bounds = GetSpellLearnSpellMapBounds(spell_id1);
            for (SpellLearnSpellMap::const_iterator i = bounds.first; i != bounds.second; ++i)
                if (i->second.spell == spell_id2)
                    return true;
            return false;
        }

        static bool IsProfessionOrRidingSpell(uint32 spellId);
        static bool IsProfessionSpell(uint32 spellId);
        static bool IsPrimaryProfessionSpell(uint32 spellId);
        bool IsPrimaryProfessionFirstRankSpell(uint32 spellId) const;

        bool IsSkillBonusSpell(uint32 spellId) const;
        bool IsSkillTypeSpell(uint32 spellId, SkillType type) const;
        static int32 CalculateSpellEffectAmount(SpellEntry const * spellEntry, uint8 effIndex, Unit const * caster = NULL, int32 const * basePoints = NULL, Unit const * target = NULL);
        static int32 CalculateSpellEffectBaseAmount(int32 value, SpellEntry const * spellEntry, uint8 effIndex);

        // Spell correctess for client using
        static bool IsSpellValid(SpellEntry const * spellInfo, Player* pl = NULL, bool msg = true);

        SkillLineAbilityMapBounds GetSkillLineAbilityMapBounds(uint32 spell_id) const
        {
            return SkillLineAbilityMapBounds(mSkillLineAbilityMap.lower_bound(spell_id),mSkillLineAbilityMap.upper_bound(spell_id));
        }

        PetAura const* GetPetAura(uint32 spell_id, uint8 eff)
        {
            SpellPetAuraMap::const_iterator itr = mSpellPetAuraMap.find((spell_id<<8) + eff);
            if (itr != mSpellPetAuraMap.end())
                return &itr->second;
            else
                return NULL;
        }

        PetLevelupSpellSet const* GetPetLevelupSpellList(uint32 petFamily) const
        {
            PetLevelupSpellMap::const_iterator itr = mPetLevelupSpellMap.find(petFamily);
            if (itr != mPetLevelupSpellMap.end())
                return &itr->second;
            else
                return NULL;
        }

        uint32 GetSpellCustomAttr(uint32 spell_id) const
        {
            if (spell_id >= mSpellCustomAttr.size())
                return 0;
            else
                return mSpellCustomAttr[spell_id];
        }

        const std::vector<int32> *GetSpellLinked(int32 spell_id) const
        {
            SpellLinkedMap::const_iterator itr = mSpellLinkedMap.find(spell_id);
            return itr != mSpellLinkedMap.end() ? &(itr->second) : NULL;
        }

        // < 0 for petspelldata id, > 0 for creature_id
        PetDefaultSpellsEntry const* GetPetDefaultSpellsEntry(int32 id) const
        {
            PetDefaultSpellsMap::const_iterator itr = mPetDefaultSpellsMap.find(id);
            if (itr != mPetDefaultSpellsMap.end())
                return &itr->second;
            return NULL;
        }

        SpellCastResult GetSpellAllowedInLocationError(SpellEntry const *spellInfo, uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player = NULL);

        SpellAreaMapBounds GetSpellAreaMapBounds(uint32 spell_id) const
        {
            return SpellAreaMapBounds(mSpellAreaMap.lower_bound(spell_id),mSpellAreaMap.upper_bound(spell_id));
        }

        SpellAreaForQuestMapBounds GetSpellAreaForQuestMapBounds(uint32 quest_id, bool active) const
        {
            if (active)
                return SpellAreaForQuestMapBounds(mSpellAreaForActiveQuestMap.lower_bound(quest_id),mSpellAreaForActiveQuestMap.upper_bound(quest_id));
            else
                return SpellAreaForQuestMapBounds(mSpellAreaForQuestMap.lower_bound(quest_id),mSpellAreaForQuestMap.upper_bound(quest_id));
        }

        SpellAreaForQuestMapBounds GetSpellAreaForQuestEndMapBounds(uint32 quest_id) const
        {
            return SpellAreaForQuestMapBounds(mSpellAreaForQuestEndMap.lower_bound(quest_id),mSpellAreaForQuestEndMap.upper_bound(quest_id));
        }

        SpellAreaForAuraMapBounds GetSpellAreaForAuraMapBounds(uint32 spell_id) const
        {
            return SpellAreaForAuraMapBounds(mSpellAreaForAuraMap.lower_bound(spell_id),mSpellAreaForAuraMap.upper_bound(spell_id));
        }

        SpellAreaForAreaMapBounds GetSpellAreaForAreaMapBounds(uint32 area_id) const
        {
            return SpellAreaForAreaMapBounds(mSpellAreaForAreaMap.lower_bound(area_id),mSpellAreaForAreaMap.upper_bound(area_id));
        }

        bool IsSrcTargetSpell(SpellEntry const *spellInfo) const;

        inline bool IsCasterSourceTarget(uint32 target)
        {
            switch (SpellTargetType[target])
            {
                case TARGET_TYPE_UNIT_TARGET:
                case TARGET_TYPE_DEST_TARGET:
                    return false;
                default:
                    break;
            }
            return true;
        }

        inline bool IsSpellWithCasterSourceTargetsOnly(SpellEntry const* spellInfo)
        {
            for (int i = 0; i < 3; ++i)
                if (uint32 target = spellInfo->EffectImplicitTargetA[i])
                    if (!IsCasterSourceTarget(target))
                        return false;
            return true;
        }
        uint32 GetSpellDifficultyId(uint32 spellId)
        {
            SpellDifficultySearcherMap::const_iterator i = mSpellDifficultySearcherMap.find(spellId);
            return i == mSpellDifficultySearcherMap.end() ? 0 : (*i).second;
        }
        void SetSpellDifficultyId(uint32 spellId, uint32 id) { mSpellDifficultySearcherMap[spellId] = id; }

        const SpellsRequiringSpellMap GetSpellsRequiringSpell()
        {
            return this->mSpellsReqSpell;
        }

        uint32 GetSpellRequired(uint32 spell_id) const
        {
            SpellRequiredMap::const_iterator itr = mSpellReq.find(spell_id);

            if (itr == mSpellReq.end())
                return NULL;

            return itr->second;
        }

    // Modifiers
    public:
        static SpellMgr& Instance();

        // Loading data at server startup
        void LoadSpellRanks();
        void LoadSpellRequired();
        void LoadSpellLearnSkills();
        void LoadSpellLearnSpells();
        void LoadSpellGroups();
        void LoadSpellProcEvents();
        void LoadSpellBonusess();
        void LoadSpellTargetPositions();
        void LoadSpellThreats();
        void LoadSkillLineAbilityMap();
        void LoadSpellPetAuras();
        void LoadSpellCustomAttr();
        void LoadEnchantCustomAttr();
        void LoadSpellEnchantProcData();
        void LoadSpellLinked();
        void LoadPetLevelupSpellMap();
        void LoadPetDefaultSpells();
        void LoadSpellAreas();
        void LoadSpellGroupStackRules();

    private:
        bool _isPositiveSpell(uint32 spellId, bool deep) const;
        bool _isPositiveEffect(uint32 spellId, uint32 effIndex, bool deep) const;

        SpellChainMap      mSpellChains;
        SpellsRequiringSpellMap   mSpellsReqSpell;
        SpellRequiredMap   mSpellReq;
        SpellLearnSkillMap mSpellLearnSkills;
        SpellLearnSpellMap mSpellLearnSpells;
        SpellTargetPositionMap mSpellTargetPositions;
        SpellSpellGroupMap mSpellSpellGroup;
        SpellGroupSpellMap mSpellGroupSpell;
        SpellThreatMap     mSpellThreatMap;
        SpellProcEventMap  mSpellProcEventMap;
        SpellBonusMap      mSpellBonusMap;
        SkillLineAbilityMap mSkillLineAbilityMap;
        SpellPetAuraMap     mSpellPetAuraMap;
        SpellCustomAttribute  mSpellCustomAttr;
        SpellLinkedMap      mSpellLinkedMap;
        SpellGroupStackMap   mSpellGroupStack;
        SpellEnchantProcEventMap     mSpellEnchantProcEventMap;
        EnchantCustomAttribute  mEnchantCustomAttr;
        PetLevelupSpellMap  mPetLevelupSpellMap;
        PetDefaultSpellsMap mPetDefaultSpellsMap;           // only spells not listed in related mPetLevelupSpellMap entry
        SpellAreaMap         mSpellAreaMap;
        SpellAreaForQuestMap mSpellAreaForQuestMap;
        SpellAreaForQuestMap mSpellAreaForActiveQuestMap;
        SpellAreaForQuestMap mSpellAreaForQuestEndMap;
        SpellAreaForAuraMap  mSpellAreaForAuraMap;
        SpellAreaForAreaMap  mSpellAreaForAreaMap;
        SpellDifficultySearcherMap mSpellDifficultySearcherMap;
};

#define spellmgr SpellMgr::Instance()
#endif
