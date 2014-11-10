/*
 * Copyright (C) 2011 TrintiyCore <http://www.trinitycore.org/>
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
#include "ItemPrototype.h"

// GCC has alternative #pragma pack(N) syntax and old gcc version does not support pack(push, N), also any gcc version does not support it at some platform
#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

// Structures used to access raw DB2 data and required packing to portability
struct ItemEntry
{
    uint32   ID;                                             // 0
    uint32   Class;                                          // 1
    uint32   SubClass;                                       // 2
    int32    SoundOverrideSubclass;                          // 3
    int32    Material;                                       // 4
    uint32   DisplayId;                                      // 5
    uint32   InventoryType;                                  // 6
    uint32   Sheath;                                         // 7
};

struct ItemCurrencyCostEntry
{
    //uint32  Id;
    uint32  ItemId;
};

struct ItemSparseEntry
{
    uint32     ID;                                           // 0
    uint32     Quality;                                      // 1
    uint32     Flags;                                        // 2
    uint32     Flags2;                                       // 3
    float      Unk430_1;
    float      Unk430_2;
    uint32     BuyCount;
    uint32     BuyPrice;                                     // 4
    uint32     SellPrice;                                    // 5
    uint32     InventoryType;                                // 6
    int32      AllowableClass;                               // 7
    int32      AllowableRace;                                // 8
    uint32     ItemLevel;                                    // 9
    int32      RequiredLevel;                                // 10
    uint32     RequiredSkill;                                // 11
    uint32     RequiredSkillRank;                            // 12
    uint32     RequiredSpell;                                // 13
    uint32     RequiredHonorRank;                            // 14
    uint32     RequiredCityRank;                             // 15
    uint32     RequiredReputationFaction;                    // 16
    uint32     RequiredReputationRank;                       // 17
    uint32     MaxCount;                                     // 18
    uint32     Stackable;                                    // 19
    uint32     ContainerSlots;                               // 20
    int32      ItemStatType[MAX_ITEM_PROTO_STATS];           // 21 - 30
    uint32     ItemStatValue[MAX_ITEM_PROTO_STATS];          // 31 - 40
    int32      ItemStatUnk1[MAX_ITEM_PROTO_STATS];           // 41 - 50
    int32      ItemStatUnk2[MAX_ITEM_PROTO_STATS];           // 51 - 60
    uint32     ScalingStatDistribution;                      // 61
    uint32     DamageType;                                   // 62
    uint32     Delay;                                        // 63
    float      RangedModRange;                               // 64
    int32      SpellId[MAX_ITEM_PROTO_SPELLS];               // 65 - 69
    int32      SpellTrigger[MAX_ITEM_PROTO_SPELLS];          // 70 - 74
    int32      SpellCharges[MAX_ITEM_PROTO_SPELLS];          // 75 - 79
    int32      SpellCooldown[MAX_ITEM_PROTO_SPELLS];         // 80 - 84
    int32      SpellCategory[MAX_ITEM_PROTO_SPELLS];         // 85 - 89
    int32      SpellCategoryCooldown[MAX_ITEM_PROTO_SPELLS]; // 90 - 94
    uint32     Bonding;                                      // 95
    LocalizedString* Name;                                   // 96
    LocalizedString* Name2;                                  // 97
    LocalizedString* Name3;                                  // 98
    LocalizedString* Name4;                                  // 99
    LocalizedString* Description;                            // 100
    uint32     PageText;                                     // 101
    uint32     LanguageID;                                   // 102
    uint32     PageMaterial;                                 // 103
    uint32     StartQuest;                                   // 104
    uint32     LockID;                                       // 105
    int32      Material;                                     // 106
    uint32     Sheath;                                       // 107
    uint32     RandomProperty;                               // 108
    uint32     RandomSuffix;                                 // 109
    uint32     ItemSet;                                      // 110
    uint32     Area;                                         // 112
    uint32     Map;                                          // 113
    uint32     BagFamily;                                    // 114
    uint32     TotemCategory;                                // 115
    uint32     Color[MAX_ITEM_PROTO_SOCKETS];                // 116 - 118
    uint32     Content[MAX_ITEM_PROTO_SOCKETS];              // 119 - 121
    int32      SocketBonus;                                  // 122
    uint32     GemProperties;                                // 123
    float      ArmorDamageModifier;                          // 124
    uint32     Duration;                                     // 125
    uint32     ItemLimitCategory;                            // 126
    uint32     HolidayId;                                    // 127
    float      StatScalingFactor;                            // 128
    int32      CurrencySubstitutionId;                       // 129
    int32      CurrencySubstitutionCount;                    // 130
};

#define MAX_ITEM_EXT_COST_ITEMS         5
#define MAX_ITEM_EXT_COST_CURRENCIES    5

struct ItemExtendedCostEntry
{
    uint32      ID;                                         // 0 extended-cost entry id
    //uint32    reqhonorpoints;                             // 1 required honor points
    //uint32    reqarenapoints;                             // 2 required arena points
    uint32      RequiredArenaSlot;                          // 3 arena slot restrictions (min slot value)
    uint32      RequiredItem[MAX_ITEM_EXT_COST_ITEMS];      // 4-8 required item id
    uint32      RequiredItemCount[MAX_ITEM_EXT_COST_ITEMS]; // 9-13 required count of 1st item
    uint32      RequiredPersonalArenaRating;                // 14 required personal arena rating
    //uint32    ItemPurchaseGroup;                          // 15
    uint32      RequiredCurrency[MAX_ITEM_EXT_COST_CURRENCIES];// 16-20 required curency id
    uint32      RequiredCurrencyCount[MAX_ITEM_EXT_COST_CURRENCIES];// 21-25 required curency count
    uint32      RequiredFactionId;
    uint32      RequiredFactionStanding;
    uint32      RequirementFlags;
    uint32      RequiredGuildLevel;
    uint32      RequiredAchievement;
};

#define KEYCHAIN_SIZE   32

struct KeyChainEntry
{
    uint32      Id;
    uint8       Key[KEYCHAIN_SIZE];
};

struct SpellAuraRestrictionsEntry
{
    //uint32    ID;                                         // 0
    uint32      CasterAuraState;                            // 1
    uint32      TargetAuraState;                            // 2
    uint32      ExcludeCasterAuraState;                     // 3
    uint32      ExcludeTargetAuraState;                     // 4
    uint32      CasterAuraSpell;                            // 5
    uint32      TargetAuraSpell;                            // 6
    uint32      ExcludeCasterAuraSpell;                     // 7
    uint32      ExcludeTargetAuraSpell;                     // 8
};

struct SpellClassOptionsEntry
{
    uint32      ID;                                         // 0
    uint32      ModalNextSpell;                             // 1
    flag128     SpellClassMask;                             // 2
    uint32      SpellClassSet;                              // 3
};

struct SpellMiscEntry
{
    uint32      ID;                                         // 0
    uint32      Attributes;                                 // 1
    uint32      AttributesEx;                               // 2
    uint32      AttributesExB;                              // 3
    uint32      AttributesExC;                              // 4
    uint32      AttributesExD;                              // 5
    uint32      AttributesExE;                              // 6
    uint32      AttributesExF;                              // 7
    uint32      AttributesExG;                              // 8
    uint32      AttributesExH;                              // 9
    uint32      AttributesExI;                              // 10
    uint32      AttributesExJ;                              // 11
    uint32      AttributesExK;                              // 12
    uint32      AttributesExL;                              // 13
    uint32      AttributesExM;                              // 14
    uint32      CastingTimeIndex;                           // 15
    uint32      DurationIndex;                              // 16
    uint32      RangeIndex;                                 // 17
    float       Speed;                                      // 18
    uint32      SpellVisualID[2];                           // 19-20
    uint32      SpellIconID;                                // 21
    uint32      ActiveIconID;                               // 22
    uint32      SchoolMask;                                 // 23
    //float     Unk;                                        // 24
};

struct SpellPowerEntry
{
    uint32      ID;                                         // 0
    uint32      SpellID;                                    // 1
    //uint32    Unk2;                                       // 2
    //uint32    Unk3;                                       // 3
    uint32      ManaCost;                                   // 4
    uint32      ManaCostPerLevel;                           // 5
    uint32      ManaCostPerSecond;                          // 6
    //uint32    Unk4;                                       // 7 (All 0 except one spell: 22570)
    //uint32    Unk5;                                       // 8
    //uint32    Unk6;                                       // 9
    float       ManaCostPercentage;                         // 10
    //float     Unk7;                                       // 11
    //uint32    Unk8;                                       // 12
};

#define MAX_SPELL_REAGENTS 8

struct SpellReagentsEntry
{
    uint32      ID;                                         // 0
    int32       Reagent[MAX_SPELL_REAGENTS];                // 1-8
    uint32      ReagentCount[MAX_SPELL_REAGENTS];           // 9-16
    //uint32    Unk1;                                       // 17
    //uint32    Unk2;                                       // 18
};

struct SpellRuneCostEntry
{
    uint32      ID;                                         // 0
    uint32      RuneCost[3];                                // 1-3 (0=blood, 1=frost, 2=unholy)
    //uint32    Unk;                                        // 4 (All 0 except for 2 ids: 2510, 2748)
    uint32      RunePowerGain;                              // 5

    bool NoRuneCost() const { return RuneCost[0] == 0 && RuneCost[1] == 0 && RuneCost[2] == 0; }
    bool NoRunicPowerGain() const { return RunePowerGain == 0; }
};

// GCC has alternative #pragma pack(N) syntax and old gcc version does not support pack(push, N), also any gcc version does not support it at some platform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

#endif