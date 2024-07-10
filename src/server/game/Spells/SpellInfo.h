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

#ifndef _SPELLINFO_H
#define _SPELLINFO_H

#include "SharedDefines.h"
#include "DB2Structure.h"
#include "Object.h"
#include "SpellAuraDefines.h"
#include "SpellDefines.h"
#include <bitset>

class AuraEffect;
class Item;
class Player;
class Spell;
class SpellMgr;
class SpellInfo;
class Unit;
class WorldObject;
struct Condition;
struct SpellChainNode;
struct SpellModifier;
struct SpellTargetPosition;
enum WeaponAttackType : uint8;

enum SpellTargetSelectionCategories
{
    TARGET_SELECT_CATEGORY_NYI,
    TARGET_SELECT_CATEGORY_DEFAULT,
    TARGET_SELECT_CATEGORY_CHANNEL,
    TARGET_SELECT_CATEGORY_NEARBY,
    TARGET_SELECT_CATEGORY_CONE,
    TARGET_SELECT_CATEGORY_AREA,
    TARGET_SELECT_CATEGORY_TRAJ,
    TARGET_SELECT_CATEGORY_LINE
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
    TARGET_CHECK_PASSENGER,
    TARGET_CHECK_SUMMONED
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
    SPELL_ATTR0_CU_AURA_CC                       = 0x00000020,
    SPELL_ATTR0_CU_DONT_BREAK_STEALTH            = 0x00000040,
    SPELL_ATTR0_CU_CAN_CRIT                      = 0x00000080,
    SPELL_ATTR0_CU_DIRECT_DAMAGE                 = 0x00000100,
    SPELL_ATTR0_CU_CHARGE                        = 0x00000200,
    SPELL_ATTR0_CU_PICKPOCKET                    = 0x00000400,
    SPELL_ATTR0_CU_DEPRECATED_ROLLING_PERIODIC   = 0x00000800, // DO NOT REUSE
    SPELL_ATTR0_CU_DEPRECATED_NEGATIVE_EFF0      = 0x00001000, // DO NOT REUSE
    SPELL_ATTR0_CU_DEPRECATED_NEGATIVE_EFF1      = 0x00002000, // DO NOT REUSE
    SPELL_ATTR0_CU_DEPRECATED_NEGATIVE_EFF2      = 0x00004000, // DO NOT REUSE
    SPELL_ATTR0_CU_IGNORE_ARMOR                  = 0x00008000,
    SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER      = 0x00010000,
    SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET      = 0x00020000,
    SPELL_ATTR0_CU_ALLOW_INFLIGHT_TARGET         = 0x00040000,
    SPELL_ATTR0_CU_NEEDS_AMMO_DATA               = 0x00080000,
    SPELL_ATTR0_CU_BINARY_SPELL                  = 0x00100000,
    SPELL_ATTR0_CU_SCHOOLMASK_NORMAL_WITH_MAGIC  = 0x00200000,
    SPELL_ATTR0_CU_DEPRECATED_LIQUID_AURA        = 0x00400000, // DO NOT REUSE
    SPELL_ATTR0_CU_IS_TALENT                     = 0x00800000,
    SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED          = 0x01000000,
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
        StaticData(SpellTargetObjectTypes objectType, SpellTargetReferenceTypes referenceType, SpellTargetSelectionCategories selectionCategory,
            SpellTargetCheckTypes checkType, SpellTargetDirectionTypes directionType) : ObjectType(objectType), ReferenceType(referenceType),
            SelectionCategory(selectionCategory), SelectionCheckType(checkType), DirectionType(directionType) { }

        SpellTargetObjectTypes ObjectType;    // type of object returned by target type
        SpellTargetReferenceTypes ReferenceType; // defines which object is used as a reference when selecting target
        SpellTargetSelectionCategories SelectionCategory;
        SpellTargetCheckTypes SelectionCheckType; // defines selection criteria
        SpellTargetDirectionTypes DirectionType; // direction for cone and dest targets
    };
    static std::array<StaticData, TOTAL_SPELL_TARGETS> _data;
};

class TC_GAME_API SpellEffectInfo
{
    friend class SpellInfo;
    SpellInfo const* _spellInfo;
public:
    SpellEffIndex EffectIndex;
    SpellEffectName Effect;
    AuraType  ApplyAuraName;
    uint32    ApplyAuraPeriod;
    float     BasePoints;
    float     RealPointsPerLevel;
    float     PointsPerResource;
    float     Amplitude;
    float     ChainAmplitude;
    float     BonusCoefficient;
    int32     MiscValue;
    int32     MiscValueB;
    Mechanics Mechanic;
    float     PositionFacing;
    SpellImplicitTargetInfo TargetA;
    SpellImplicitTargetInfo TargetB;
    SpellRadiusEntry const* TargetARadiusEntry;
    SpellRadiusEntry const* TargetBRadiusEntry;
    int32     ChainTargets;
    uint32    ItemType;
    uint32    TriggerSpell;
    flag128   SpellClassMask;
    float     BonusCoefficientFromAP;
    std::shared_ptr<std::vector<Condition>> ImplicitTargetConditions;
    EnumFlag<SpellEffectAttributes> EffectAttributes;
    // SpellScalingEntry
    struct ScalingInfo
    {
        int32 Class;
        float Coefficient;
        float Variance;
        float ResourceCoefficient;
    } Scaling;

    explicit SpellEffectInfo();
    explicit SpellEffectInfo(SpellInfo const* spellInfo, SpellEffectEntry const& effect);
    SpellEffectInfo(SpellEffectInfo const&) = delete;
    SpellEffectInfo(SpellEffectInfo&&) noexcept;
    SpellEffectInfo& operator=(SpellEffectInfo const&) = delete;
    SpellEffectInfo& operator=(SpellEffectInfo&&) noexcept;
    ~SpellEffectInfo();

    bool IsEffect() const;
    bool IsEffect(SpellEffectName effectName) const;
    bool IsAura() const;
    bool IsAura(AuraType aura) const;
    bool IsTargetingArea() const;
    bool IsAreaAuraEffect() const;
    bool IsUnitOwnedAuraEffect() const;

    int32 CalcValue(WorldObject const* caster = nullptr, int32 const* basePoints = nullptr, Unit const* target = nullptr, float* variance = nullptr, uint32 castItemId = 0, int32 itemLevel = -1) const;
    int32 CalcBaseValue(WorldObject const* caster, Unit const* target, uint32 itemId, int32 itemLevel) const;
    float CalcValueMultiplier(WorldObject* caster, Spell* spell = nullptr) const;
    float CalcDamageMultiplier(WorldObject* caster, Spell* spell = nullptr) const;

    bool HasRadius(SpellTargetIndex targetIndex) const;
    float CalcRadius(WorldObject* caster = nullptr, SpellTargetIndex targetIndex = SpellTargetIndex::TargetA, Spell* = nullptr) const;

    uint32 GetProvidedTargetMask() const;
    uint32 GetMissingTargetMask(bool srcSet = false, bool dstSet = false, uint32 mask = 0) const;

    SpellEffectImplicitTargetTypes GetImplicitTargetType() const;
    SpellTargetObjectTypes GetUsedTargetObjectType() const;
    ExpectedStatType GetScalingExpectedStat() const;

    struct ImmunityInfo;
    ImmunityInfo const* GetImmunityInfo() const { return _immunityInfo.get(); }

private:
    struct StaticData
    {
        StaticData(SpellEffectImplicitTargetTypes implicitTargetType, SpellTargetObjectTypes usedTargetObjectType)
            : ImplicitTargetType(implicitTargetType), UsedTargetObjectType(usedTargetObjectType) { }

        SpellEffectImplicitTargetTypes ImplicitTargetType; // defines what target can be added to effect target list if there's no valid target type provided for effect
        SpellTargetObjectTypes UsedTargetObjectType; // defines valid target object type for spell effect
    };
    static std::array<StaticData, TOTAL_SPELL_EFFECTS> _data;

    std::unique_ptr<ImmunityInfo> _immunityInfo;
};

typedef std::vector<SpellXSpellVisualEntry const*> SpellVisualVector;
typedef std::unordered_map<uint32, SpellVisualVector> SpellVisualMap;

typedef std::vector<AuraEffect*> AuraEffectVector;

struct SpellInfoLoadHelper;

struct TC_GAME_API SpellDiminishInfo
{
    DiminishingGroup DiminishGroup = DIMINISHING_NONE;
    DiminishingReturnsType DiminishReturnType = DRTYPE_NONE;
    DiminishingLevels DiminishMaxLevel = DIMINISHING_LEVEL_IMMUNE;
    int32 DiminishDurationLimit = 0;
};

struct SpellPowerCost
{
    Powers Power;
    int32 Amount;
};

class TC_GAME_API SpellInfo
{
    friend class SpellMgr;

    public:
        uint32 const Id = 0;
        ::Difficulty const Difficulty = DIFFICULTY_NONE;
        uint32 CategoryId = 0;
        uint32 Dispel = 0;
        uint32 Mechanic = 0;
        uint32 Attributes = 0;
        uint32 AttributesEx = 0;
        uint32 AttributesEx2 = 0;
        uint32 AttributesEx3 = 0;
        uint32 AttributesEx4 = 0;
        uint32 AttributesEx5 = 0;
        uint32 AttributesEx6 = 0;
        uint32 AttributesEx7 = 0;
        uint32 AttributesEx8 = 0;
        uint32 AttributesEx9 = 0;
        uint32 AttributesEx10 = 0;
        uint32 AttributesEx11 = 0;
        uint32 AttributesEx12 = 0;
        uint32 AttributesEx13 = 0;
        uint32 AttributesEx14 = 0;
        uint32 AttributesCu = 0;
        std::bitset<MAX_SPELL_EFFECTS> NegativeEffects;
        uint64 Stances = 0;
        uint64 StancesNot = 0;
        uint32 Targets = 0;
        uint32 TargetCreatureType = 0;
        uint32 RequiresSpellFocus = 0;
        uint32 FacingCasterFlags = 0;
        uint32 CasterAuraState = 0;
        uint32 TargetAuraState = 0;
        uint32 ExcludeCasterAuraState = 0;
        uint32 ExcludeTargetAuraState = 0;
        uint32 CasterAuraSpell = 0;
        uint32 TargetAuraSpell = 0;
        uint32 ExcludeCasterAuraSpell = 0;
        uint32 ExcludeTargetAuraSpell = 0;
        AuraType CasterAuraType = SPELL_AURA_NONE;
        AuraType TargetAuraType = SPELL_AURA_NONE;
        AuraType ExcludeCasterAuraType = SPELL_AURA_NONE;
        AuraType ExcludeTargetAuraType = SPELL_AURA_NONE;
        SpellCastTimesEntry const* CastTimeEntry = nullptr;
        uint32 RecoveryTime = 0;
        uint32 CategoryRecoveryTime = 0;
        uint32 StartRecoveryCategory = 0;
        uint32 StartRecoveryTime = 0;
        uint32 CooldownAuraSpellId = 0;
        EnumFlag<SpellInterruptFlags> InterruptFlags = SpellInterruptFlags::None;
        EnumFlag<SpellAuraInterruptFlags> AuraInterruptFlags = SpellAuraInterruptFlags::None;
        EnumFlag<SpellAuraInterruptFlags2> AuraInterruptFlags2 = SpellAuraInterruptFlags2::None;
        EnumFlag<SpellAuraInterruptFlags> ChannelInterruptFlags = SpellAuraInterruptFlags::None;
        EnumFlag<SpellAuraInterruptFlags2> ChannelInterruptFlags2 = SpellAuraInterruptFlags2::None;
        ProcFlagsInit ProcFlags;
        uint32 ProcChance = 0;
        uint32 ProcCharges = 0;
        uint32 ProcCooldown = 0;
        float ProcBasePPM = 0.0f;
        std::vector<SpellProcsPerMinuteModEntry const*> ProcPPMMods;
        uint32 MaxLevel = 0;
        uint32 BaseLevel = 0;
        uint32 SpellLevel = 0;
        SpellDurationEntry const* DurationEntry = nullptr;
        std::array<SpellPowerEntry const*, MAX_POWERS_PER_SPELL> PowerCosts = {};
        SpellRangeEntry const* RangeEntry = nullptr;
        float Speed = 0.0f;
        float LaunchDelay = 0.0f;
        uint32 StackAmount = 0;
        std::array<int32, MAX_SPELL_TOTEMS> Totem = {};
        std::array<uint16, MAX_SPELL_TOTEMS> TotemCategory = {};
        std::array<int32, MAX_SPELL_REAGENTS> Reagent = {};
        std::array<int16, MAX_SPELL_REAGENTS> ReagentCount = {};
        std::vector<SpellReagentsCurrencyEntry const*> ReagentsCurrency;
        int32 EquippedItemClass = -1;
        int32 EquippedItemSubClassMask = 0;
        int32 EquippedItemInventoryTypeMask = 0;
        uint32 IconFileDataId = 0;
        uint32 ActiveIconFileDataId = 0;
        uint32 ContentTuningId = 0;
        uint32 ShowFutureSpellPlayerConditionID = 0;
        LocalizedString const* SpellName = nullptr;
        float ConeAngle = 0.0f;
        float Width = 0.0f;
        uint32 MaxTargetLevel = 0;
        uint32 MaxAffectedTargets = 0;
        uint32 SpellFamilyName = 0;
        flag128 SpellFamilyFlags;
        uint32 DmgClass = 0;
        uint32 PreventionType = 0;
        int32 RequiredAreasID = -1;
        uint32 SchoolMask = 0;
        uint32 ChargeCategoryId = 0;
        std::unordered_set<uint32> Labels;
        std::vector<Milliseconds> EmpowerStageThresholds;

        // SpellScalingEntry
        struct ScalingInfo
        {
            uint32 MinScalingLevel = 0;
            uint32 MaxScalingLevel = 0;
            uint32 ScalesFromItemLevel = 0;
        } Scaling;

        uint32 ExplicitTargetMask = 0;
        SpellChainNode const* ChainEntry = nullptr;
        struct
        {
            int32 MaxTargets = 0;               // The amount of targets after the damage decreases by the Square Root AOE formula
            int32 NumNonDiminishedTargets = 0;  // The amount of targets that still take the full amount before the damage decreases by the Square Root AOE formula
        } SqrtDamageAndHealingDiminishing;

        explicit SpellInfo(SpellNameEntry const* spellName, ::Difficulty difficulty, SpellInfoLoadHelper const& data);
        explicit SpellInfo(SpellNameEntry const* spellName, ::Difficulty difficulty, std::vector<SpellEffectEntry> const& effects);
        SpellInfo(SpellInfo const&) = delete;
        SpellInfo(SpellInfo&&) = delete;
        ~SpellInfo();

        SpellInfo& operator=(SpellInfo const&) = delete;
        SpellInfo& operator=(SpellInfo&&) noexcept = delete;

        uint32 GetCategory() const;
        bool HasEffect(SpellEffectName effect) const;
        bool HasAura(AuraType aura) const;
        bool HasAreaAuraEffect() const;
        bool HasOnlyDamageEffects() const;
        bool HasTargetType(::Targets target) const;

        bool HasAttribute(SpellAttr0 attribute) const { return !!(Attributes & attribute); }
        bool HasAttribute(SpellAttr1 attribute) const { return !!(AttributesEx & attribute); }
        bool HasAttribute(SpellAttr2 attribute) const { return !!(AttributesEx2 & attribute); }
        bool HasAttribute(SpellAttr3 attribute) const { return !!(AttributesEx3 & attribute); }
        bool HasAttribute(SpellAttr4 attribute) const { return !!(AttributesEx4 & attribute); }
        bool HasAttribute(SpellAttr5 attribute) const { return !!(AttributesEx5 & attribute); }
        bool HasAttribute(SpellAttr6 attribute) const { return !!(AttributesEx6 & attribute); }
        bool HasAttribute(SpellAttr7 attribute) const { return !!(AttributesEx7 & attribute); }
        bool HasAttribute(SpellAttr8 attribute) const { return !!(AttributesEx8 & attribute); }
        bool HasAttribute(SpellAttr9 attribute) const { return !!(AttributesEx9 & attribute); }
        bool HasAttribute(SpellAttr10 attribute) const { return !!(AttributesEx10 & attribute); }
        bool HasAttribute(SpellAttr11 attribute) const { return !!(AttributesEx11 & attribute); }
        bool HasAttribute(SpellAttr12 attribute) const { return !!(AttributesEx12 & attribute); }
        bool HasAttribute(SpellAttr13 attribute) const { return !!(AttributesEx13 & attribute); }
        bool HasAttribute(SpellAttr14 attribute) const { return !!(AttributesEx14 & attribute); }
        bool HasAttribute(SpellCustomAttributes customAttribute) const { return !!(AttributesCu & customAttribute); }

        bool CanBeInterrupted(WorldObject const* interruptCaster, Unit const* interruptTarget, bool ignoreImmunity = false) const;

        bool HasAnyAuraInterruptFlag() const;
        bool HasAuraInterruptFlag(SpellAuraInterruptFlags flag) const { return AuraInterruptFlags.HasFlag(flag); }
        bool HasAuraInterruptFlag(SpellAuraInterruptFlags2 flag) const { return AuraInterruptFlags2.HasFlag(flag); }

        bool HasChannelInterruptFlag(SpellAuraInterruptFlags flag) const { return ChannelInterruptFlags.HasFlag(flag); }
        bool HasChannelInterruptFlag(SpellAuraInterruptFlags2 flag) const { return ChannelInterruptFlags2.HasFlag(flag); }

        bool IsExplicitDiscovery() const;
        bool IsLootCrafting() const;
        bool IsProfession() const;
        bool IsPrimaryProfession() const;
        bool IsPrimaryProfessionFirstRank() const;
        bool IsAbilityOfSkillType(uint32 skillType) const;

        bool IsAffectingArea() const;
        bool IsTargetingArea() const;
        bool NeedsExplicitUnitTarget() const;
        bool NeedsToBeTriggeredByCaster(SpellInfo const* triggeringSpell) const;

        bool IsPassive() const;
        bool IsAutocastable() const;
        bool IsAutocastEnabledByDefault() const;
        bool IsStackableWithRanks() const;
        bool IsPassiveStackableWithRanks() const;
        bool IsMultiSlotAura() const;
        bool IsStackableOnOneSlotWithDifferentCasters() const;
        bool IsCooldownStartedOnEvent() const;
        bool IsDeathPersistent() const;
        bool IsRequiringDeadTarget() const;
        bool IsAllowingDeadTarget() const;
        bool IsGroupBuff() const;
        bool CanBeUsedInCombat(Unit const* caster) const;
        bool IsPositive() const;
        bool IsPositiveEffect(uint8 effIndex) const;
        bool IsChanneled() const;
        bool IsMoveAllowedChannel() const;
        bool IsNextMeleeSwingSpell() const;
        bool IsRangedWeaponSpell() const;
        bool IsAutoRepeatRangedSpell() const;
        bool IsEmpowerSpell() const;
        bool HasInitialAggro() const;
        bool HasHitDelay() const;

        WeaponAttackType GetAttackType() const;

        bool IsItemFitToSpellRequirements(Item const* item) const;

        bool IsAffected(uint32 familyName, flag128 const& familyFlags) const;

        bool IsAffectedBySpellMods() const;
        bool IsAffectedBySpellMod(SpellModifier const* mod) const;

        bool CanPierceImmuneAura(SpellInfo const* auraSpellInfo) const;
        bool CanDispelAura(SpellInfo const* auraSpellInfo) const;

        bool IsSingleTarget() const;
        bool IsAuraExclusiveBySpecificWith(SpellInfo const* spellInfo) const;
        bool IsAuraExclusiveBySpecificPerCasterWith(SpellInfo const* spellInfo) const;

        SpellCastResult CheckShapeshift(uint32 form) const;
        SpellCastResult CheckLocation(uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player = nullptr) const;
        SpellCastResult CheckTarget(WorldObject const* caster, WorldObject const* target, bool implicit = true) const;
        SpellCastResult CheckExplicitTarget(WorldObject const* caster, WorldObject const* target, Item const* itemTarget = nullptr) const;
        SpellCastResult CheckVehicle(Unit const* caster) const;
        bool CheckTargetCreatureType(Unit const* target) const;

        SpellSchoolMask GetSchoolMask() const;
        uint64 GetAllEffectsMechanicMask() const;
        uint64 GetEffectMechanicMask(SpellEffIndex effIndex) const;
        uint64 GetSpellMechanicMaskByEffectMask(uint32 effectMask) const;
        Mechanics GetEffectMechanic(SpellEffIndex effIndex) const;
        uint32 GetDispelMask() const;
        static uint32 GetDispelMask(DispelType type);
        uint32 GetExplicitTargetMask() const;

        AuraStateType GetAuraState() const;
        SpellSpecificType GetSpellSpecific() const;

        float GetMinRange(bool positive = false) const;
        float GetMaxRange(bool positive = false, WorldObject* caster = nullptr, Spell* spell = nullptr) const;

        int32 CalcDuration(WorldObject const* caster = nullptr) const;
        int32 GetDuration() const;
        int32 GetMaxDuration() const;

        uint32 GetMaxTicks() const;

        uint32 CalcCastTime(Spell* spell = nullptr) const;
        uint32 GetRecoveryTime() const;

        Optional<SpellPowerCost> CalcPowerCost(Powers powerType, bool optionalCost, WorldObject const* caster, SpellSchoolMask schoolMask, Spell* spell = nullptr) const;
        Optional<SpellPowerCost> CalcPowerCost(SpellPowerEntry const* power, bool optionalCost, WorldObject const* caster, SpellSchoolMask schoolMask, Spell* spell = nullptr) const;
        std::vector<SpellPowerCost> CalcPowerCost(WorldObject const* caster, SpellSchoolMask schoolMask, Spell* spell = nullptr) const;

        float CalcProcPPM(Unit* caster, int32 itemLevel) const;

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

        uint32 GetSpellXSpellVisualId(WorldObject const* caster = nullptr, WorldObject const* viewer = nullptr) const;
        uint32 GetSpellVisual(WorldObject const* caster = nullptr, WorldObject const* viewer = nullptr) const;

        std::vector<SpellEffectInfo> const& GetEffects() const { return _effects; }
        SpellEffectInfo const& GetEffect(SpellEffIndex index) const { ASSERT(index < _effects.size()); return _effects[index]; }

        // spell diminishing returns
        DiminishingGroup GetDiminishingReturnsGroupForSpell() const;
        DiminishingReturnsType GetDiminishingReturnsGroupType() const;
        DiminishingLevels GetDiminishingReturnsMaxLevel() const;
        int32 GetDiminishingReturnsLimitDuration() const;

        // spell immunities
        void ApplyAllSpellImmunitiesTo(Unit* target, SpellEffectInfo const& spellEffectInfo, bool apply) const;
        bool CanSpellProvideImmunityAgainstAura(SpellInfo const* auraSpellInfo) const;
        bool CanSpellEffectProvideImmunityAgainstAuraEffect(SpellEffectInfo const& immunityEffectInfo, SpellInfo const* auraSpellInfo, SpellEffectInfo const& auraEffectInfo) const;
        bool SpellCancelsAuraEffect(AuraEffect const* aurEff) const;

        uint64 GetAllowedMechanicMask() const;

        uint64 GetMechanicImmunityMask(Unit const* caster) const;

        // Player Condition
        bool MeetsFutureSpellPlayerCondition(Player const* player) const;

        bool HasLabel(uint32 labelId) const;

    private:
        // loading helpers
        void _InitializeExplicitTargetMask();
        void _InitializeSpellPositivity();
        void _LoadSpellSpecific();
        void _LoadAuraState();
        void _LoadSpellDiminishInfo();
        void _LoadImmunityInfo();
        void _LoadSqrtTargetLimit(int32 maxTargets, int32 numNonDiminishedTargets,
            Optional<SpellEffIndex> maxTargetsEffectValueHolder,
            Optional<SpellEffIndex> numNonDiminishedTargetsEffectValueHolder);

        // unloading helpers
        void _UnloadImplicitTargetConditionLists();

    private:
        std::vector<SpellEffectInfo> _effects;
        SpellVisualVector _visuals;
        SpellSpecificType _spellSpecific = SPELL_SPECIFIC_NORMAL;
        AuraStateType _auraState = AURA_STATE_NONE;

        SpellDiminishInfo _diminishInfo;
        uint64 _allowedMechanicMask = 0;
};

#endif // _SPELLINFO_H
