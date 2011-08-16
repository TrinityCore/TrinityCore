/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _SPELLINFO_H
#define _SPELLINFO_H

#include "SharedDefines.h"

class Unit;
class Player;
class Spell;
class SpellInfo;
struct SpellChainNode;
struct SpellTargetPosition;
struct SpellDurationEntry;
struct SpellModifier;
struct SpellRangeEntry;
struct SpellRadiusEntry;
struct SpellEntry;
struct SpellCastTimesEntry;

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

// Spell clasification
enum SpellSpecificType
{
    SPELL_SPECIFIC_NORMAL                        = 0,
    SPELL_SPECIFIC_SEAL                          = 1,
    SPELL_SPECIFIC_AURA                          = 3,
    SPELL_SPECIFIC_STING                         = 4,
    SPELL_SPECIFIC_CURSE                         = 5,
    SPELL_SPECIFIC_ASPECT                        = 6,
    SPELL_SPECIFIC_TRACKER                       = 7,
    SPELL_SPECIFIC_WARLOCK_ARMOR                 = 8,
    SPELL_SPECIFIC_MAGE_ARMOR                    = 9,
    SPELL_SPECIFIC_ELEMENTAL_SHIELD              = 10,
    SPELL_SPECIFIC_MAGE_POLYMORPH                = 11,
    SPELL_SPECIFIC_JUDGEMENT                     = 13,
    SPELL_SPECIFIC_WARLOCK_CORRUPTION            = 17,
    SPELL_SPECIFIC_FOOD                          = 19,
    SPELL_SPECIFIC_DRINK                         = 20,
    SPELL_SPECIFIC_FOOD_AND_DRINK                = 21,
    SPELL_SPECIFIC_PRESENCE                      = 22,
    SPELL_SPECIFIC_CHARM                         = 23,
    SPELL_SPECIFIC_SCROLL                        = 24,
    SPELL_SPECIFIC_MAGE_ARCANE_BRILLANCE         = 25,
    SPELL_SPECIFIC_WARRIOR_ENRAGE                = 26,
    SPELL_SPECIFIC_PRIEST_DIVINE_SPIRIT          = 27,
    SPELL_SPECIFIC_HAND                          = 28,
    SPELL_SPECIFIC_PHASE                         = 29,
};

enum SpellCustomAttributes
{
    SPELL_ATTR0_CU_ENCHANT_PROC                  = 0x00000001,
    SPELL_ATTR0_CU_CONE_BACK                     = 0x00000002,
    SPELL_ATTR0_CU_CONE_LINE                     = 0x00000004,
    SPELL_ATTR0_CU_SHARE_DAMAGE                  = 0x00000008,
    SPELL_ATTR0_CU_NONE1                         = 0x00000010,   // UNUSED
    SPELL_ATTR0_CU_NONE2                         = 0x00000020,   // UNUSED
    SPELL_ATTR0_CU_AURA_CC                       = 0x00000040,
    SPELL_ATTR0_CU_DIRECT_DAMAGE                 = 0x00000100,
    SPELL_ATTR0_CU_CHARGE                        = 0x00000200,
    SPELL_ATTR0_CU_PICKPOCKET                    = 0x00000400,
    SPELL_ATTR0_CU_EXCLUDE_SELF                  = 0x00000800,
    SPELL_ATTR0_CU_NEGATIVE_EFF0                 = 0x00001000,
    SPELL_ATTR0_CU_NEGATIVE_EFF1                 = 0x00002000,
    SPELL_ATTR0_CU_NEGATIVE_EFF2                 = 0x00004000,
    SPELL_ATTR0_CU_IGNORE_ARMOR                  = 0x00008000,
    SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER      = 0x00010000,
    SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET      = 0x00020000,

    SPELL_ATTR0_CU_NEGATIVE                      = SPELL_ATTR0_CU_NEGATIVE_EFF0 | SPELL_ATTR0_CU_NEGATIVE_EFF1 | SPELL_ATTR0_CU_NEGATIVE_EFF2,
};

class SpellImplicitTargetInfo
{
private:
    Targets _target;
public:
    SpellImplicitTargetInfo() {}
    SpellImplicitTargetInfo(uint32 target);

    bool IsArea() const;
    SpellSelectTargetTypes GetType() const;

    Targets GetTarget() const;

    // temporarily avalible to public
    static bool IsPosition(uint32 targetType);
    static SpellSelectTargetTypes Type[TOTAL_SPELL_TARGETS];

private:
    static bool InitStaticData();
    static void InitAreaData();
    static void InitTypeData();

    static bool Init;
    static bool Area[TOTAL_SPELL_TARGETS];
};

class SpellEffectInfo
{
    SpellInfo const* _spellInfo;
    uint8 _effIndex;
public:
    uint32    Effect;
    uint32    ApplyAuraName;
    uint32    Amplitude;
    int32     DieSides;
    float     RealPointsPerLevel;
    int32     BasePoints;
    float     PointsPerComboPoint;
    float     ValueMultiplier;
    float     DamageMultiplier;
    float     BonusMultiplier;
    int32     MiscValue;
    int32     MiscValueB;
    Mechanics Mechanic;
    SpellImplicitTargetInfo TargetA;
    SpellImplicitTargetInfo TargetB;
    SpellRadiusEntry const* RadiusEntry;
    uint32    ChainTarget;
    uint32    ItemType;
    uint32    TriggerSpell;
    flag96    SpellClassMask;

    SpellEffectInfo() {}
    SpellEffectInfo(SpellEntry const* spellEntry, SpellInfo const* spellInfo, uint8 effIndex);

    bool IsEffect() const;
    bool IsEffect(SpellEffects effectName) const;
    bool IsAura() const;
    bool IsAura(AuraType aura) const;
    bool IsArea() const;
    bool IsAreaAuraEffect() const;
    bool IsFarUnitTargetEffect() const;
    bool IsFarDestTargetEffect() const;
    bool IsUnitOwnedAuraEffect() const;

    int32 CalcValue(Unit const* caster = NULL, int32 const* basePoints = NULL, Unit const* target = NULL) const;
    int32 CalcBaseValue(int32 value) const;
    float CalcValueMultiplier(Unit* caster, Spell* spell = NULL) const;
    float CalcDamageMultiplier(Unit* caster, Spell* spell = NULL) const;

    bool HasRadius() const;
    float CalcRadius(Unit* caster = NULL, Spell* = NULL) const;

    SpellEffectTargetTypes GetRequiredTargetType() const;

private:
    static bool InitStaticData();
    static void InitRequiredTargetTypeData();

    static bool Init;
    static SpellEffectTargetTypes RequiredTargetType[TOTAL_SPELL_EFFECTS];
};

class SpellInfo
{
public:
    uint32 Id;
    uint32 Category;
    uint32 Dispel;
    uint32 Mechanic;
    uint32 Attributes;
    uint32 AttributesEx;
    uint32 AttributesEx2;
    uint32 AttributesEx3;
    uint32 AttributesEx4;
    uint32 AttributesEx5;
    uint32 AttributesEx6;
    uint32 AttributesEx7;
    uint32 AttributesCu;
    uint32 Stances;
    uint32 StancesNot;
    uint32 Targets;
    uint32 TargetCreatureType;
    uint32 RequiresSpellFocus;
    uint32 FacingCasterFlags;
    uint32 CasterAuraState;
    uint32 TargetAuraState;
    uint32 CasterAuraStateNot;
    uint32 TargetAuraStateNot;
    uint32 CasterAuraSpell;
    uint32 TargetAuraSpell;
    uint32 ExcludeCasterAuraSpell;
    uint32 ExcludeTargetAuraSpell;
    SpellCastTimesEntry const* CastTimeEntry;
    uint32 RecoveryTime;
    uint32 CategoryRecoveryTime;
    uint32 StartRecoveryCategory;
    uint32 StartRecoveryTime;
    uint32 InterruptFlags;
    uint32 AuraInterruptFlags;
    uint32 ChannelInterruptFlags;
    uint32 ProcFlags;
    uint32 ProcChance;
    uint32 ProcCharges;
    uint32 MaxLevel;
    uint32 BaseLevel;
    uint32 SpellLevel;
    SpellDurationEntry const* DurationEntry;
    uint32 PowerType;
    uint32 ManaCost;
    uint32 ManaCostPerlevel;
    uint32 ManaPerSecond;
    uint32 ManaPerSecondPerLevel;
    uint32 ManaCostPercentage;
    uint32 RuneCostID;
    SpellRangeEntry const* RangeEntry;
    float  Speed;
    uint32 StackAmount;
    uint32 Totem[2];
    int32  Reagent[MAX_SPELL_REAGENTS];
    uint32 ReagentCount[MAX_SPELL_REAGENTS];
    int32  EquippedItemClass;
    int32  EquippedItemSubClassMask;
    int32  EquippedItemInventoryTypeMask;
    uint32 TotemCategory[2];
    uint32 SpellVisual[2];
    uint32 SpellIconID;
    uint32 ActiveIconID;
    char* SpellName[16];
    char* Rank[16];
    uint32 MaxTargetLevel;
    uint32 MaxAffectedTargets;
    uint32 SpellFamilyName;
    flag96 SpellFamilyFlags;
    uint32 DmgClass;
    uint32 PreventionType;
    int32  AreaGroupId;
    uint32 SchoolMask;
    SpellEffectInfo Effects[MAX_SPELL_EFFECTS];
    SpellChainNode const* ChainEntry;

    SpellInfo(SpellEntry const* spellEntry);

    bool HasEffect(SpellEffects effect) const;
    bool HasAura(AuraType aura) const;
    bool HasAreaAuraEffect() const;

    bool IsExplicitDiscovery() const;
    bool IsLootCrafting() const;
    bool IsQuestTame() const;
    bool IsProfessionOrRiding() const;
    bool IsProfession() const;
    bool IsPrimaryProfession() const;
    bool IsPrimaryProfessionFirstRank() const;
    bool IsAbilityLearnedWithProfession() const;
    bool IsAbilityOfSkillType(uint32 skillType) const;

    bool IsAOE() const;
    bool IsRequiringSelectedTarget() const;

    bool IsPassive() const;
    bool IsAutocastable() const;
    bool IsStackableWithRanks() const;
    bool IsPassiveStackableWithRanks() const;
    bool IsMultiSlotAura() const;
    bool IsDeathPersistent() const;
    bool IsRequiringDeadTarget() const;
    bool IsAllowingDeadTarget() const;
    bool CanBeUsedInCombat() const;
    bool IsPositive() const;
    bool IsPositiveEffect(uint8 effIndex) const;
    bool IsChanneled() const;
    bool NeedsComboPoints() const;
    bool IsBreakingStealth() const;
    bool IsRangedWeaponSpell() const;
    bool IsAutoRepeatRangedSpell() const;

    bool IsAffectedBySpellMod(SpellModifier* mod) const;

    bool CanPierceImmuneAura(SpellInfo const* aura) const;
    bool CanDispelAura(SpellInfo const* aura) const;

    bool IsSingleTarget() const;
    bool IsSingleTargetWith(SpellInfo const* spellInfo) const;
    bool IsAuraExclusiveBySpecificWith(SpellInfo const* spellInfo) const;
    bool IsAuraExclusiveBySpecificPerCasterWith(SpellInfo const* spellInfo) const;

    SpellCastResult CheckShapeshift(uint32 form) const;
    SpellCastResult CheckLocation(uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player = NULL) const;

    SpellSchoolMask GetSchoolMask() const;
    uint32 GetAllEffectsMechanicMask() const;
    uint32 GetEffectMechanicMask(uint8 effIndex) const;
    Mechanics GetEffectMechanic(uint8 effIndex) const;
    uint32 GetDispelMask() const;
    static uint32 GetDispelMask(DispelType type);

    AuraStateType GetAuraState() const;
    SpellSpecificType GetSpellSpecific() const;

    float GetMinRange(bool positive = false) const;
    float GetMaxRange(bool positive = false) const;

    int32 GetDuration() const;
    int32 GetMaxDuration() const;

    uint32 CalcCastTime(Unit* caster = NULL, Spell* spell = NULL) const;
    uint32 GetRecoveryTime() const;

    uint32 CalcPowerCost(Unit const* caster, SpellSchoolMask schoolMask) const;

    bool IsRanked() const;
    uint8 GetRank() const;
    SpellInfo const* GetFirstRankSpell() const;
    SpellInfo const* GetLastRankSpell() const;
    SpellInfo const* GetNextRankSpell() const;
    SpellInfo const* GetPrevRankSpell() const;
    SpellInfo const* GetAuraRankForLevel(uint8 level) const;
    bool IsRankOf(SpellInfo const* spellInfo) const;
    bool IsDifferentRankOf(SpellInfo const* spellInfo) const;
    bool IsHighRankOf(SpellInfo const* spellInfo) const;

    // loading helpers
    bool _IsPositiveEffect(uint8 effIndex, bool deep) const;
    bool _IsPositiveSpell() const;
    static bool _IsPositiveTarget(uint32 targetA, uint32 targetB);
};

#endif // _SPELLINFO_H
