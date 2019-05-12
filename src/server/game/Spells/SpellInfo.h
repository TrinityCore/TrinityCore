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

#ifndef _SPELLINFO_H
#define _SPELLINFO_H

#include "SharedDefines.h"
#include "Util.h"
#include "DBCStructure.h"
#include "Object.h"
#include "SpellAuraDefines.h"

#include <boost/container/flat_set.hpp>

class Unit;
class Player;
class Item;
class Spell;
class SpellInfo;
class WorldObject;
struct SpellChainNode;
struct SpellTargetPosition;
struct SpellDurationEntry;
struct SpellModifier;
struct SpellRangeEntry;
struct SpellRadiusEntry;
struct SpellEntry;
struct SpellCastTimesEntry;
struct Condition;

enum SpellCastTargetFlags : uint32
{
    TARGET_FLAG_NONE            = 0x00000000,
    TARGET_FLAG_UNUSED_1        = 0x00000001,               // not used
    TARGET_FLAG_UNIT            = 0x00000002,               // pguid
    TARGET_FLAG_UNIT_RAID       = 0x00000004,               // not sent, used to validate target (if raid member)
    TARGET_FLAG_UNIT_PARTY      = 0x00000008,               // not sent, used to validate target (if party member)
    TARGET_FLAG_ITEM            = 0x00000010,               // pguid
    TARGET_FLAG_SOURCE_LOCATION = 0x00000020,               // pguid, 3 float
    TARGET_FLAG_DEST_LOCATION   = 0x00000040,               // pguid, 3 float
    TARGET_FLAG_UNIT_ENEMY      = 0x00000080,               // not sent, used to validate target (if enemy)
    TARGET_FLAG_UNIT_ALLY       = 0x00000100,               // not sent, used to validate target (if ally)
    TARGET_FLAG_CORPSE_ENEMY    = 0x00000200,               // pguid
    TARGET_FLAG_UNIT_DEAD       = 0x00000400,               // not sent, used to validate target (if dead creature)
    TARGET_FLAG_GAMEOBJECT      = 0x00000800,               // pguid, used with TARGET_GAMEOBJECT_TARGET
    TARGET_FLAG_TRADE_ITEM      = 0x00001000,               // pguid
    TARGET_FLAG_STRING          = 0x00002000,               // string
    TARGET_FLAG_GAMEOBJECT_ITEM = 0x00004000,               // not sent, used with TARGET_GAMEOBJECT_ITEM_TARGET
    TARGET_FLAG_CORPSE_ALLY     = 0x00008000,               // pguid
    TARGET_FLAG_UNIT_MINIPET    = 0x00010000,               // pguid, used to validate target (if non combat pet)
    TARGET_FLAG_GLYPH_SLOT      = 0x00020000,               // used in glyph spells
    TARGET_FLAG_DEST_TARGET     = 0x00040000,               // sometimes appears with DEST_TARGET spells (may appear or not for a given spell)
    TARGET_FLAG_EXTRA_TARGETS   = 0x00080000,               // uint32 counter, loop { vec3 - screen position (?), guid }, not used so far
    TARGET_FLAG_UNIT_PASSENGER  = 0x00100000,               // guessed, used to validate target (if vehicle passenger)

    TARGET_FLAG_UNIT_MASK = TARGET_FLAG_UNIT | TARGET_FLAG_UNIT_RAID | TARGET_FLAG_UNIT_PARTY
        | TARGET_FLAG_UNIT_ENEMY | TARGET_FLAG_UNIT_ALLY | TARGET_FLAG_UNIT_DEAD | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_UNIT_PASSENGER,
    TARGET_FLAG_GAMEOBJECT_MASK = TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM,
    TARGET_FLAG_CORPSE_MASK = TARGET_FLAG_CORPSE_ALLY | TARGET_FLAG_CORPSE_ENEMY,
    TARGET_FLAG_ITEM_MASK = TARGET_FLAG_TRADE_ITEM | TARGET_FLAG_ITEM | TARGET_FLAG_GAMEOBJECT_ITEM
};

enum SpellTargetSelectionCategories
{
    TARGET_SELECT_CATEGORY_NYI,
    TARGET_SELECT_CATEGORY_DEFAULT,
    TARGET_SELECT_CATEGORY_CHANNEL,
    TARGET_SELECT_CATEGORY_NEARBY,
    TARGET_SELECT_CATEGORY_CONE,
    TARGET_SELECT_CATEGORY_AREA
};

enum SpellTargetReferenceTypes
{
    TARGET_REFERENCE_TYPE_NONE,
    TARGET_REFERENCE_TYPE_CASTER,
    TARGET_REFERENCE_TYPE_TARGET,
    TARGET_REFERENCE_TYPE_LAST,
    TARGET_REFERENCE_TYPE_SRC,
    TARGET_REFERENCE_TYPE_DEST
};

enum SpellTargetObjectTypes : uint8
{
    TARGET_OBJECT_TYPE_NONE = 0,
    TARGET_OBJECT_TYPE_SRC,
    TARGET_OBJECT_TYPE_DEST,
    TARGET_OBJECT_TYPE_UNIT,
    TARGET_OBJECT_TYPE_UNIT_AND_DEST,
    TARGET_OBJECT_TYPE_GOBJ,
    TARGET_OBJECT_TYPE_GOBJ_ITEM,
    TARGET_OBJECT_TYPE_ITEM,
    TARGET_OBJECT_TYPE_CORPSE,
    // only for effect target type
    TARGET_OBJECT_TYPE_CORPSE_ENEMY,
    TARGET_OBJECT_TYPE_CORPSE_ALLY
};

enum SpellTargetCheckTypes : uint8
{
    TARGET_CHECK_DEFAULT,
    TARGET_CHECK_ENTRY,
    TARGET_CHECK_ENEMY,
    TARGET_CHECK_ALLY,
    TARGET_CHECK_PARTY,
    TARGET_CHECK_RAID,
    TARGET_CHECK_RAID_CLASS,
    TARGET_CHECK_PASSENGER
};

enum SpellTargetDirectionTypes
{
    TARGET_DIR_NONE,
    TARGET_DIR_FRONT,
    TARGET_DIR_BACK,
    TARGET_DIR_RIGHT,
    TARGET_DIR_LEFT,
    TARGET_DIR_FRONT_RIGHT,
    TARGET_DIR_BACK_RIGHT,
    TARGET_DIR_BACK_LEFT,
    TARGET_DIR_FRONT_LEFT,
    TARGET_DIR_RANDOM,
    TARGET_DIR_ENTRY
};

enum SpellEffectImplicitTargetTypes
{
    EFFECT_IMPLICIT_TARGET_NONE = 0,
    EFFECT_IMPLICIT_TARGET_EXPLICIT,
    EFFECT_IMPLICIT_TARGET_CASTER
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
    SPELL_SPECIFIC_BANE                          = 30
};

enum SpellCustomAttributes
{
    SPELL_ATTR0_CU_ENCHANT_PROC                  = 0x00000001,
    SPELL_ATTR0_CU_CONE_BACK                     = 0x00000002,
    SPELL_ATTR0_CU_CONE_LINE                     = 0x00000004,
    SPELL_ATTR0_CU_SHARE_DAMAGE                  = 0x00000008,
    SPELL_ATTR0_CU_NO_INITIAL_THREAT             = 0x00000010,
    SPELL_ATTR0_CU_DONT_BREAK_STEALTH            = 0x00000040,
    SPELL_ATTR0_CU_DIRECT_DAMAGE                 = 0x00000100,
    SPELL_ATTR0_CU_CHARGE                        = 0x00000200,
    SPELL_ATTR0_CU_PICKPOCKET                    = 0x00000400,
    SPELL_ATTR0_CU_NEGATIVE_EFF0                 = 0x00001000,
    SPELL_ATTR0_CU_NEGATIVE_EFF1                 = 0x00002000,
    SPELL_ATTR0_CU_NEGATIVE_EFF2                 = 0x00004000,
    SPELL_ATTR0_CU_IGNORE_ARMOR                  = 0x00008000,
    SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER      = 0x00010000,
    SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET      = 0x00020000,
    SPELL_ATTR0_CU_ALLOW_INFLIGHT_TARGET         = 0x00040000,
    SPELL_ATTR0_CU_LIQUID_AURA                   = 0x00400000,

    SPELL_ATTR0_CU_NEGATIVE                      = SPELL_ATTR0_CU_NEGATIVE_EFF0 | SPELL_ATTR0_CU_NEGATIVE_EFF1 | SPELL_ATTR0_CU_NEGATIVE_EFF2
};

uint32 GetTargetFlagMask(SpellTargetObjectTypes objType);

class TC_GAME_API SpellImplicitTargetInfo
{
private:
    Targets _target;
public:
    SpellImplicitTargetInfo() : _target(Targets(0)) { }
    SpellImplicitTargetInfo(uint32 target);

    bool IsArea() const;
    SpellTargetSelectionCategories GetSelectionCategory() const;
    SpellTargetReferenceTypes GetReferenceType() const;
    SpellTargetObjectTypes GetObjectType() const;
    SpellTargetCheckTypes GetCheckType() const;
    SpellTargetDirectionTypes GetDirectionType() const;
    float CalcDirectionAngle() const;

    Targets GetTarget() const;
    uint32 GetExplicitTargetMask(bool& srcSet, bool& dstSet) const;

private:
    struct StaticData
    {
        SpellTargetObjectTypes ObjectType;    // type of object returned by target type
        SpellTargetReferenceTypes ReferenceType; // defines which object is used as a reference when selecting target
        SpellTargetSelectionCategories SelectionCategory;
        SpellTargetCheckTypes SelectionCheckType; // defines selection criteria
        SpellTargetDirectionTypes DirectionType; // direction for cone and dest targets
    };
    static StaticData _data[TOTAL_SPELL_TARGETS];
};

class TC_GAME_API SpellEffectInfo
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
    SpellRadiusEntry const* MaxRadiusEntry;
    uint32    ChainTarget;
    uint32    ItemType;
    uint32    TriggerSpell;
    flag96    SpellClassMask;
    std::vector<Condition*>* ImplicitTargetConditions;
    // SpellScalingEntry
    float     ScalingMultiplier;
    float     DeltaScalingMultiplier;
    float     ComboScalingMultiplier;

    SpellEffectInfo() : _spellInfo(nullptr), _effIndex(0), Effect(0), ApplyAuraName(0), Amplitude(0), DieSides(0),
                        RealPointsPerLevel(0), BasePoints(0), PointsPerComboPoint(0), ValueMultiplier(0), DamageMultiplier(0),
                        BonusMultiplier(0), MiscValue(0), MiscValueB(0), Mechanic(MECHANIC_NONE), RadiusEntry(nullptr), ChainTarget(0),
                        ItemType(0), TriggerSpell(0), ImplicitTargetConditions(nullptr) {}
    SpellEffectInfo(SpellEntry const* spellEntry, SpellInfo const* spellInfo, uint8 effIndex, SpellEffectEntry const* effect);

    bool IsEffect() const;
    bool IsEffect(SpellEffects effectName) const;
    bool IsAura() const;
    bool IsAura(AuraType aura) const;
    bool IsTargetingArea() const;
    bool IsAreaAuraEffect() const;
    bool IsFarUnitTargetEffect() const;
    bool IsFarDestTargetEffect() const;
    bool IsUnitOwnedAuraEffect() const;

    int32 CalcValue(Unit const* caster = nullptr, int32 const* basePoints = nullptr, Unit const* target = nullptr) const;
    int32 CalcBaseValue(int32 value) const;
    float CalcValueMultiplier(Unit* caster, Spell* spell = nullptr) const;
    float CalcDamageMultiplier(Unit* caster, Spell* spell = nullptr) const;

    bool HasRadius() const;
    bool HasMaxRadius() const;
    float CalcRadius(Unit* caster = nullptr, Spell* = nullptr) const;

    uint32 GetProvidedTargetMask() const;
    uint32 GetMissingTargetMask(bool srcSet = false, bool destSet = false, uint32 mask = 0) const;

    SpellEffectImplicitTargetTypes GetImplicitTargetType() const;
    SpellTargetObjectTypes GetUsedTargetObjectType() const;

private:
    struct StaticData
    {
        SpellEffectImplicitTargetTypes ImplicitTargetType; // defines what target can be added to effect target list if there's no valid target type provided for effect
        SpellTargetObjectTypes UsedTargetObjectType; // defines valid target object type for spell effect
    };
    static StaticData _data[TOTAL_SPELL_EFFECTS];
};

struct TC_GAME_API ImmunityInfo
{
    uint32 SchoolImmuneMask = 0;
    uint32 ApplyHarmfulAuraImmuneMask = 0;
    uint32 MechanicImmuneMask = 0;
    uint32 DispelImmune = 0;
    uint32 DamageSchoolMask = 0;

    boost::container::flat_set<AuraType> AuraTypeImmune;
    boost::container::flat_set<SpellEffects> SpellEffectImmune;
};

struct TC_GAME_API SpellDiminishInfo
{
    DiminishingGroup DiminishGroup = DIMINISHING_NONE;
    DiminishingReturnsType DiminishReturnType = DRTYPE_NONE;
    DiminishingLevels DiminishMaxLevel = DIMINISHING_LEVEL_IMMUNE;
    int32 DiminishDurationLimit = 0;
};

class TC_GAME_API SpellInfo
{
    friend class SpellMgr;

    public:
        uint32 Id;
        SpellCategoryEntry const* CategoryEntry;
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
        uint32 AttributesEx8;
        uint32 AttributesEx9;
        uint32 AttributesEx10;
        uint32 AttributesCu;
        uint64 Stances;
        uint64 StancesNot;
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
        char* SpellName;
        char* Rank;
        float ConeAngle;
        uint32 MaxTargetLevel;
        uint32 MaxAffectedTargets;
        uint32 SpellFamilyName;
        flag96 SpellFamilyFlags;
        uint32 DmgClass;
        uint32 PreventionType;
        int32  AreaGroupId;
        uint32 SchoolMask;
        uint32 SpellDifficultyId;
        uint32 SpellScalingId;
        uint32 SpellAuraOptionsId;
        uint32 SpellAuraRestrictionsId;
        uint32 SpellCastingRequirementsId;
        uint32 SpellCategoriesId;
        uint32 SpellClassOptionsId;
        uint32 SpellCooldownsId;
        uint32 SpellEquippedItemsId;
        uint32 SpellInterruptsId;
        uint32 SpellLevelsId;
        uint32 SpellPowerId;
        uint32 SpellReagentsId;
        uint32 SpellShapeshiftId;
        uint32 SpellTargetRestrictionsId;
        uint32 SpellTotemsId;
        uint32 ResearchProjectId;
        // SpellScalingEntry
        int32  CastTimeMin;
        int32  CastTimeMax;
        int32  CastTimeMaxLevel;
        int32  ScalingClass;
        float  CoefBase;
        int32  CoefLevelBase;
        SpellEffectInfo Effects[MAX_SPELL_EFFECTS];
        uint32 ExplicitTargetMask;
        SpellChainNode const* ChainEntry;
        uint32 MaxAuraTargets;

        // struct access functions
        SpellTargetRestrictionsEntry const* GetSpellTargetRestrictions() const;
        SpellAuraOptionsEntry const* GetSpellAuraOptions() const;
        SpellAuraRestrictionsEntry const* GetSpellAuraRestrictions() const;
        SpellCastingRequirementsEntry const* GetSpellCastingRequirements() const;
        SpellCategoriesEntry const* GetSpellCategories() const;
        SpellClassOptionsEntry const* GetSpellClassOptions() const;
        SpellCooldownsEntry const* GetSpellCooldowns() const;
        SpellEquippedItemsEntry const* GetSpellEquippedItems() const;
        SpellInterruptsEntry const* GetSpellInterrupts() const;
        SpellLevelsEntry const* GetSpellLevels() const;
        SpellPowerEntry const* GetSpellPower() const;
        SpellReagentsEntry const* GetSpellReagents() const;
        SpellScalingEntry const* GetSpellScaling() const;
        SpellShapeshiftEntry const* GetSpellShapeshift() const;
        SpellTotemsEntry const* GetSpellTotems() const;

        SpellInfo(SpellEntry const* spellEntry, SpellEffectEntry const** effects);
        ~SpellInfo();

        uint32 GetCategory() const;
        bool HasEffect(SpellEffects effect) const;
        bool HasAura(AuraType aura) const;
        bool HasAreaAuraEffect() const;
        bool HasOnlyDamageEffects() const;

        inline bool HasAttribute(SpellAttr0 attribute)  const { return !!(Attributes & attribute); }
        inline bool HasAttribute(SpellAttr1 attribute)  const { return !!(AttributesEx & attribute); }
        inline bool HasAttribute(SpellAttr2 attribute)  const { return !!(AttributesEx2 & attribute); }
        inline bool HasAttribute(SpellAttr3 attribute)  const { return !!(AttributesEx3 & attribute); }
        inline bool HasAttribute(SpellAttr4 attribute)  const { return !!(AttributesEx4 & attribute); }
        inline bool HasAttribute(SpellAttr5 attribute)  const { return !!(AttributesEx5 & attribute); }
        inline bool HasAttribute(SpellAttr6 attribute)  const { return !!(AttributesEx6 & attribute); }
        inline bool HasAttribute(SpellAttr7 attribute)  const { return !!(AttributesEx7 & attribute); }
        inline bool HasAttribute(SpellAttr8 attribute)  const { return !!(AttributesEx8 & attribute); }
        inline bool HasAttribute(SpellAttr9 attribute)  const { return !!(AttributesEx9 & attribute); }
        inline bool HasAttribute(SpellAttr10 attribute) const { return !!(AttributesEx10 & attribute); }
        inline bool HasAttribute(SpellCustomAttributes customAttribute) const { return !!(AttributesCu & customAttribute); }

        bool IsExplicitDiscovery() const;
        bool IsLootCrafting() const;
        bool IsQuestTame() const;
        bool IsProfessionOrRiding() const;
        bool IsProfession() const;
        bool IsPrimaryProfession() const;
        bool IsPrimaryProfessionFirstRank() const;
        bool IsAbilityLearnedWithProfession() const;
        bool IsAbilityOfSkillType(uint32 skillType) const;

        bool IsAffectingArea() const;
        bool IsTargetingArea() const;
        bool NeedsExplicitUnitTarget() const;
        bool NeedsToBeTriggeredByCaster(SpellInfo const* triggeringSpell) const;

        bool IsPassive() const;
        bool IsRaidMarker() const;
        bool IsAutocastable() const;
        bool IsStackableWithRanks() const;
        bool IsPassiveStackableWithRanks() const;
        bool IsMultiSlotAura() const;
        bool IsStackableOnOneSlotWithDifferentCasters() const;
        bool IsCooldownStartedOnEvent() const;
        bool IsDeathPersistent() const;
        bool IsRequiringDeadTarget() const;
        bool IsAllowingDeadTarget() const;
        bool IsGroupBuff() const;
        bool CanBeUsedInCombat() const;
        bool IsPositive() const;
        bool IsPositiveEffect(uint8 effIndex) const;
        bool IsChanneled() const;
        bool IsMoveAllowedChannel() const;
        bool NeedsComboPoints() const;
        bool IsNextMeleeSwingSpell() const;
        bool IsBreakingStealth() const;
        bool IsRangedWeaponSpell() const;
        bool IsAutoRepeatRangedSpell() const;
        bool HasInitialAggro() const;

        bool IsAffected(uint32 familyName, flag96 const& familyFlags) const;

        bool IsAffectedBySpellMods() const;
        bool IsAffectedBySpellMod(SpellModifier const* mod) const;

        bool CanPierceImmuneAura(SpellInfo const* auraSpellInfo) const;
        bool CanDispelAura(SpellInfo const* auraSpellInfo) const;

        bool IsSingleTarget() const;
        uint32 GetAuraTargetLimit() const { return MaxAuraTargets; };
        bool IsAuraExclusiveBySpecificWith(SpellInfo const* spellInfo) const;
        bool IsAuraExclusiveBySpecificPerCasterWith(SpellInfo const* spellInfo) const;

        SpellCastResult CheckShapeshift(uint32 form) const;
        SpellCastResult CheckLocation(uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player = nullptr) const;
        SpellCastResult CheckTarget(Unit const* caster, WorldObject const* target, bool implicit = true) const;
        SpellCastResult CheckExplicitTarget(Unit const* caster, WorldObject const* target, Item const* itemTarget = nullptr) const;
        SpellCastResult CheckVehicle(Unit const* caster) const;
        bool CheckTargetCreatureType(Unit const* target) const;

        SpellSchoolMask GetSchoolMask() const;
        uint32 GetAllEffectsMechanicMask() const;
        uint32 GetEffectMechanicMask(uint8 effIndex) const;
        uint32 GetSpellMechanicMaskByEffectMask(uint32 effectMask) const;
        Mechanics GetEffectMechanic(uint8 effIndex) const;
        bool HasAnyEffectMechanic() const;
        uint32 GetDispelMask() const;
        static uint32 GetDispelMask(DispelType type);
        uint32 GetExplicitTargetMask() const;

        AuraStateType GetAuraState() const;
        SpellSpecificType GetSpellSpecific() const;

        float GetMinRange(bool positive = false) const;
        float GetMaxRange(bool positive = false, Unit* caster = nullptr, Spell* spell = nullptr) const;

        int32 GetDuration() const;
        int32 GetMaxDuration() const;

        uint32 GetMaxTicks() const;

        uint32 CalcCastTime(uint8 level = 0, Spell* spell = nullptr) const;
        uint32 GetRecoveryTime() const;

        int32 CalcPowerCost(Unit const* caster, SpellSchoolMask schoolMask, Spell* spell = nullptr) const;

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

        // spell diminishing returns
        DiminishingGroup GetDiminishingReturnsGroupForSpell(bool triggered) const;
        DiminishingReturnsType GetDiminishingReturnsGroupType(bool triggered) const;
        DiminishingLevels GetDiminishingReturnsMaxLevel(bool triggered) const;
        int32 GetDiminishingReturnsLimitDuration(bool triggered) const;

        // spell immunities
        void ApplyAllSpellImmunitiesTo(Unit* target, uint8 effIndex, bool apply) const;
        bool CanSpellProvideImmunityAgainstAura(SpellInfo const* auraSpellInfo) const;
        bool SpellCancelsAuraEffect(SpellInfo const* auraSpellInfo, uint8 auraEffIndex) const;

        uint32 GetAllowedMechanicMask() const;

    private:
        // loading helpers
        void _InitializeExplicitTargetMask();
        bool _IsPositiveEffect(uint8 effIndex, bool deep) const;
        bool _IsPositiveSpell() const;
        static bool _IsPositiveTarget(uint32 targetA, uint32 targetB);
        void _LoadSpellSpecific();
        void _LoadAuraState();
        void _LoadSpellDiminishInfo();
        void _LoadImmunityInfo();

        // unloading helpers
        void _UnloadImplicitTargetConditionLists();

        SpellSpecificType _spellSpecific;
        AuraStateType _auraState;

        SpellDiminishInfo _diminishInfoNonTriggered;
        SpellDiminishInfo _diminishInfoTriggered;

        uint32 _allowedMechanicMask;

        ImmunityInfo _immunityInfo[MAX_SPELL_EFFECTS];
};

#endif // _SPELLINFO_H
