/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_DB2STRUCTURE_H
#define TRINITY_DB2STRUCTURE_H

#include "Common.h"
#include "DBCEnums.h"
#include "Path.h"

#pragma pack(push, 1)

#define MAX_BROADCAST_TEXT_EMOTES 3
#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 16
#define MAX_HOLIDAY_FLAGS 10
#define MAX_ITEM_PROTO_FLAGS 3
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_STATS  10

struct AreaGroupEntry
{
    uint32      ID;                                                 // 0
};

struct AreaGroupMemberEntry
{
    uint32      ID;                                                 // 0
    uint32      AreaGroupID;                                        // 1
    uint32      AreaID;                                             // 2
};

struct BroadcastTextEntry
{
    uint32 ID;
    int32 Language;
    LocalizedString* MaleText;
    LocalizedString* FemaleText;
    uint32 EmoteID[MAX_BROADCAST_TEXT_EMOTES];
    uint32 EmoteDelay[MAX_BROADCAST_TEXT_EMOTES];
    uint32 SoundID;
    uint32 UnkEmoteID;
    uint32 Type;
};

struct CurrencyTypesEntry
{
    uint32      ID;                                                 // 0
    uint32      CategoryID;                                         // 1
    LocalizedString* Name_lang;                                     // 2
    LocalizedString* InventoryIcon[2];                              // 3-4
    uint32      SpellWeight;                                        // 5
    uint32      SpellCategory;                                      // 6
    uint32      MaxQty;                                             // 7
    uint32      MaxEarnablePerWeek;                                 // 8
    uint32      Flags;                                              // 9
    uint32      Quality;                                            // 10
    LocalizedString* Description_lang;                              // 11
};

struct CurvePointEntry
{
    uint32 ID;                                                      // 0
    uint32 CurveID;                                                 // 1
    uint32 Index;                                                   // 2
    float X;                                                        // 3
    float Y;                                                        // 4
};

struct HolidaysEntry
{
    uint32      ID;                                                 // 0
    uint32      Duration[MAX_HOLIDAY_DURATIONS];                    // 1-10
    uint32      Date[MAX_HOLIDAY_DATES];                            // 11-26 (dates in unix time starting at January, 1, 2000)
    uint32      Region;                                             // 27
    uint32      Looping;                                            // 28
    uint32      CalendarFlags[MAX_HOLIDAY_FLAGS];                   // 29-38
    uint32      HolidayNameID;                                      // 39 HolidayNames.dbc
    uint32      HolidayDescriptionID;                               // 40 HolidayDescriptions.dbc
    LocalizedString* TextureFilename;                               // 41
    uint32      Priority;                                           // 42
    uint32      CalendarFilterType;                                 // 43 (-1 = Fishing Contest, 0 = Unk, 1 = Darkmoon Festival, 2 = Yearly holiday)
    uint32      Flags;                                              // 44 (0 = Darkmoon Faire, Fishing Contest and Wotlk Launch, rest is 1)
};

struct ItemAppearanceEntry
{
    uint32      ID;                                                 // 0 (reference to ItemModifiedAppearance.db2?)
    uint32      DisplayID;                                          // 1
    uint32      IconFileDataID;                                     // 2
};

struct ItemBonusEntry
{
    uint32      ID;                                                 // 0
    uint32      BonusListID;                                        // 1
    uint32      Type;                                               // 2
    int32       Value[2];                                           // 3-4
    uint32      Index;                                              // 5
};

struct ItemBonusTreeNodeEntry
{
    uint32      ID;                                                 // 0
    uint32      BonusTreeID;                                        // 1
    uint32      BonusTreeModID;                                     // 2
    uint32      SubTreeID;                                          // 3
    uint32      BonusListID;                                        // 4
};

struct ItemCurrencyCostEntry
{
    uint32      ID;                                                 // 0
    uint32      ItemId;                                             // 1
};

struct ItemEffectEntry
{
    uint32      ID;                                                 // 0
    uint32      ItemID;                                             // 1
    uint32      OrderIndex;                                         // 2
    uint32      SpellID;                                            // 3
    uint32      Trigger;                                            // 4
    uint32      Charges;                                            // 5
    int32       Cooldown;                                           // 6
    uint32      Category;                                           // 7
    int32       CategoryCooldown;                                   // 8
};

struct ItemEntry
{
    uint32      ID;                                                 // 0
    uint32      Class;                                              // 1
    uint32      SubClass;                                           // 2
    int32       SoundOverrideSubclass;                              // 3
    int32       Material;                                           // 4
    uint32      InventoryType;                                      // 5
    uint32      Sheath;                                             // 6
    uint32      FileDataID;                                         // 7
    uint32      GroupSoundsID;                                      // 8
};

#define MAX_ITEM_EXT_COST_ITEMS         5
#define MAX_ITEM_EXT_COST_CURRENCIES    5

struct ItemExtendedCostEntry
{
    uint32      ID;                                                 // 0 extended-cost entry id
    uint32      RequiredArenaSlot;                                  // 3 arena slot restrictions (min slot value)
    uint32      RequiredItem[MAX_ITEM_EXT_COST_ITEMS];              // 3-6 required item id
    uint32      RequiredItemCount[MAX_ITEM_EXT_COST_ITEMS];         // 7-11 required count of 1st item
    uint32      RequiredPersonalArenaRating;                        // 12 required personal arena rating
    uint32      ItemPurchaseGroup;                                  // 13
    uint32      RequiredCurrency[MAX_ITEM_EXT_COST_CURRENCIES];     // 14-18 required curency id
    uint32      RequiredCurrencyCount[MAX_ITEM_EXT_COST_CURRENCIES];// 19-23 required curency count
    uint32      RequiredFactionId;                                  // 24
    uint32      RequiredFactionStanding;                            // 25
    uint32      RequirementFlags;                                   // 26
    uint32      RequiredAchievement;                                // 27
    uint32      RequiredMoney;                                      // 28
};

struct ItemModifiedAppearanceEntry
{
    uint32      ID;                                                 // 0
    uint32      ItemID;                                             // 1
    uint32      AppearanceModID;                                    // 2
    uint32      AppearanceID;                                       // 3
    uint32      IconFileDataID;                                     // 4
    uint32      Index;                                              // 5
};

struct ItemSparseEntry
{
    uint32      ID;                                                 // 0
    uint32      Quality;                                            // 1
    uint32      Flags[MAX_ITEM_PROTO_FLAGS];                        // 2-4
    float       Unk1;                                               // 5
    float       Unk2;                                               // 6
    uint32      BuyCount;                                           // 7
    uint32      BuyPrice;                                           // 8
    uint32      SellPrice;                                          // 9
    uint32      InventoryType;                                      // 10
    int32       AllowableClass;                                     // 11
    int32       AllowableRace;                                      // 12
    uint32      ItemLevel;                                          // 13
    int32       RequiredLevel;                                      // 14
    uint32      RequiredSkill;                                      // 15
    uint32      RequiredSkillRank;                                  // 16
    uint32      RequiredSpell;                                      // 17
    uint32      RequiredHonorRank;                                  // 18
    uint32      RequiredCityRank;                                   // 19
    uint32      RequiredReputationFaction;                          // 20
    uint32      RequiredReputationRank;                             // 21
    uint32      MaxCount;                                           // 22
    uint32      Stackable;                                          // 23
    uint32      ContainerSlots;                                     // 24
    int32       ItemStatType[MAX_ITEM_PROTO_STATS];                 // 25 - 34
    int32       ItemStatValue[MAX_ITEM_PROTO_STATS];                // 35 - 44
    int32       ItemStatAllocation[MAX_ITEM_PROTO_STATS];           // 45 - 54
    float       ItemStatSocketCostMultiplier[MAX_ITEM_PROTO_STATS]; // 55 - 64
    uint32      ScalingStatDistribution;                            // 65
    uint32      DamageType;                                         // 66
    uint32      Delay;                                              // 67
    float       RangedModRange;                                     // 68
    uint32      Bonding;                                            // 69
    LocalizedString* Name;                                          // 70
    LocalizedString* Name2;                                         // 71
    LocalizedString* Name3;                                         // 72
    LocalizedString* Name4;                                         // 73
    LocalizedString* Description;                                   // 74
    uint32      PageText;                                           // 75
    uint32      LanguageID;                                         // 76
    uint32      PageMaterial;                                       // 77
    uint32      StartQuest;                                         // 78
    uint32      LockID;                                             // 79
    int32       Material;                                           // 80
    uint32      Sheath;                                             // 81
    uint32      RandomProperty;                                     // 82
    uint32      RandomSuffix;                                       // 83
    uint32      ItemSet;                                            // 84
    uint32      Area;                                               // 85
    uint32      Map;                                                // 86
    uint32      BagFamily;                                          // 87
    uint32      TotemCategory;                                      // 88
    uint32      SocketColor[MAX_ITEM_PROTO_SOCKETS];                // 89-91
    uint32      SocketBonus;                                        // 92
    uint32      GemProperties;                                      // 93
    float       ArmorDamageModifier;                                // 94
    uint32      Duration;                                           // 95
    uint32      ItemLimitCategory;                                  // 96
    uint32      HolidayID;                                          // 97
    float       StatScalingFactor;                                  // 98
    uint32      CurrencySubstitutionID;                             // 99
    uint32      CurrencySubstitutionCount;                          // 100
    uint32      ItemNameDescriptionID;                              // 101
};

struct ItemXBonusTreeEntry
{
    uint32      ID;                                                 // 0
    uint32      ItemID;                                             // 1
    uint32      BonusTreeID;                                        // 2
};

#define KEYCHAIN_SIZE   32

struct KeyChainEntry
{
    uint32      Id;
    uint8       Key[KEYCHAIN_SIZE];
};

struct MountEntry
{
    uint32 Id;
    uint32 MountTypeId;
    uint32 DisplayId;
    uint32 Flags;
    LocalizedString* Name;
    LocalizedString* Description;
    LocalizedString* SourceDescription;
    uint32 Source;
    uint32 SpellId;
    uint32 PlayerConditionId;
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32      ID;                                                 // 0
    uint32      SpellID[MAX_OVERRIDE_SPELL];                        // 1-10
    uint32      Flags;                                              // 11
    uint32      PlayerActionbarFileDataID;                          // 12
};

struct PhaseXPhaseGroupEntry
{
    uint32      ID;
    uint32      PhaseID;
    uint32      PhaseGroupID;
};

struct SoundEntriesEntry
{
    uint32      ID;                                                 // 0
    uint32      SoundType;                                          // 1
    LocalizedString* Name;                                          // 2
    uint32      FileDataID[20];                                     // 3-22
    uint32      Freq[20];                                           // 23-42
    float       VolumeFloat;                                        // 43
    uint32      Flags;                                              // 44
    float       MinDistance;                                        // 45
    float       DistanceCutoff;                                     // 46
    uint32      EAXDef;                                             // 47
    uint32      SoundEntriesAdvancedID;                             // 48
    float       VolumeVariationPlus;                                // 49
    float       VolumeVariationMinus;                               // 50
    float       PitchVariationPlus;                                 // 51
    float       PitchVariationMinus;                                // 52
    float       PitchAdjust;                                        // 53
    uint32      DialogType;                                         // 54
    uint32      BusOverwriteID;                                     // 55
};

struct SpellAuraRestrictionsEntry
{
    uint32      ID;                                                 // 0
    uint32      CasterAuraState;                                    // 1
    uint32      TargetAuraState;                                    // 2
    uint32      ExcludeCasterAuraState;                             // 3
    uint32      ExcludeTargetAuraState;                             // 4
    uint32      CasterAuraSpell;                                    // 5
    uint32      TargetAuraSpell;                                    // 6
    uint32      ExcludeCasterAuraSpell;                             // 7
    uint32      ExcludeTargetAuraSpell;                             // 8
};

struct SpellCastingRequirementsEntry
{
    uint32      ID;                                                 // 0
    uint32      FacingCasterFlags;                                  // 1
    uint32      MinFactionID;                                       // 1
    uint32      MinReputation;                                      // 3
    uint32      RequiredAreasID;                                    // 4
    uint32      RequiredAuraVision;                                 // 5
    uint32      RequiresSpellFocus;                                 // 6
};

struct SpellClassOptionsEntry
{
    uint32      ID;                                                 // 0
    uint32      ModalNextSpell;                                     // 1
    flag128     SpellClassMask;                                     // 2
    uint32      SpellClassSet;                                      // 3
};

struct SpellLearnSpellEntry
{
    uint32      ID;                                                 // 0
    uint32      LearnSpellID;                                       // 1
    uint32      SpellID;                                            // 2
    uint32      OverridesSpellID;                                   // 3
};

struct SpellMiscEntry
{
    uint32      ID;                                                 // 0
    uint32      Attributes;                                         // 1
    uint32      AttributesEx;                                       // 2
    uint32      AttributesExB;                                      // 3
    uint32      AttributesExC;                                      // 4
    uint32      AttributesExD;                                      // 5
    uint32      AttributesExE;                                      // 6
    uint32      AttributesExF;                                      // 7
    uint32      AttributesExG;                                      // 8
    uint32      AttributesExH;                                      // 9
    uint32      AttributesExI;                                      // 10
    uint32      AttributesExJ;                                      // 11
    uint32      AttributesExK;                                      // 12
    uint32      AttributesExL;                                      // 13
    uint32      AttributesExM;                                      // 14
    uint32      CastingTimeIndex;                                   // 15
    uint32      DurationIndex;                                      // 16
    uint32      RangeIndex;                                         // 17
    float       Speed;                                              // 18
    uint32      SpellVisualID[2];                                   // 19-20
    uint32      SpellIconID;                                        // 21
    uint32      ActiveIconID;                                       // 22
    uint32      SchoolMask;                                         // 23
    float       MultistrikeSpeedMod;                                // 24
};

struct SpellPowerEntry
{
    uint32      ID;                                                 // 0
    uint32      SpellID;                                            // 1
    uint32      PowerIndex;                                         // 2
    uint32      PowerType;                                          // 3
    uint32      ManaCost;                                           // 4
    uint32      ManaCostPerLevel;                                   // 5
    uint32      ManaCostPerSecond;                                  // 6
    uint32      ManaCostAdditional;                                 // 7 Spell uses [ManaCost, ManaCost+ManaCostAdditional] power - affects tooltip parsing as multiplier on SpellEffectEntry::EffectPointsPerResource
                                                                    //   only SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE, SPELL_EFFECT_WEAPON_DAMAGE, SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    uint32      PowerDisplayID;                                     // 8
    uint32      UnitPowerBarID;                                     // 9
    float       ManaCostPercentage;                                 // 10
    float       ManaCostPercentagePerSecond;                        // 11
    uint32      RequiredAura;                                       // 12
    float       HealthCostPercentage;                               // 13
};

#define MAX_SPELL_REAGENTS 8

struct SpellReagentsEntry
{
    uint32      ID;                                                 // 0
    int32       Reagent[MAX_SPELL_REAGENTS];                        // 1-8
    uint32      ReagentCount[MAX_SPELL_REAGENTS];                   // 9-16
    uint32      CurrencyID;                                         // 17
    uint32      CurrencyCount;                                      // 18
};

struct SpellRuneCostEntry
{
    uint32      ID;                                                 // 0
    uint32      RuneCost[4];                                        // 1-4 (0=blood, 1=unholy, 2=frost, 3=death)
    uint32      RunicPower;                                         // 5

    bool NoRuneCost() const { return RuneCost[0] == 0 && RuneCost[1] == 0 && RuneCost[2] == 0 && RuneCost[3] == 0; }
    bool NoRunicPowerGain() const { return RunicPower == 0; }
};

#define MAX_SPELL_TOTEMS 2

struct SpellTotemsEntry
{
    uint32      ID;                                                 // 0
    uint32      RequiredTotemCategoryID[MAX_SPELL_TOTEMS];          // 1
    uint32      Totem[MAX_SPELL_TOTEMS];                            // 2
};

struct TaxiNodesEntry
{
    uint32           ID;                                            // 0
    uint32           MapID;                                         // 1
    DBCPosition3D    Pos;                                           // 2-4
    LocalizedString* Name_lang;                                     // 5
    uint32           MountCreatureID[2];                            // 6-7
    uint32           ConditionID;                                   // 8
    uint32           LearnableIndex;                                // 9 - some kind of index only for learnable nodes
    uint32           Flags;                                         // 10
    DBCPosition2D    MapOffset;                                     // 11-12
};

struct TaxiPathEntry
{
    uint32          ID;                                             // 0
    uint32          From;                                           // 1
    uint32          To;                                             // 2
    uint32          Cost;                                           // 3
};

struct TaxiPathNodeEntry
{
    uint32          ID;                                             // 0
    uint32          PathID;                                         // 1
    uint32          NodeIndex;                                      // 2
    uint32          MapID;                                          // 3
    DBCPosition3D   Loc;                                            // 4-6
    uint32          Flags;                                          // 7
    uint32          Delay;                                          // 8
    uint32          ArrivalEventID;                                 // 9
    uint32          DepartureEventID;                               // 10
};

#pragma pack(pop)

typedef std::map<uint32, SpellPowerEntry const*> SpellPowerBySpellIDMap;

struct TaxiPathBySourceAndDestination
{
    TaxiPathBySourceAndDestination() : ID(0), price(0) { }
    TaxiPathBySourceAndDestination(uint32 _id, uint32 _price) : ID(_id), price(_price) { }

    uint32    ID;
    uint32    price;
};
typedef std::map<uint32, TaxiPathBySourceAndDestination> TaxiPathSetForSource;
typedef std::map<uint32, TaxiPathSetForSource> TaxiPathSetBySource;

struct TaxiPathNodePtr
{
    TaxiPathNodePtr() : i_ptr(NULL) { }
    TaxiPathNodePtr(TaxiPathNodeEntry const* ptr) : i_ptr(ptr) { }
    TaxiPathNodeEntry const* i_ptr;
    operator TaxiPathNodeEntry const& () const { return *i_ptr; }
};

typedef Path<TaxiPathNodePtr, TaxiPathNodeEntry const> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

#define TaxiMaskSize 114
typedef uint8 TaxiMask[TaxiMaskSize];

#endif
