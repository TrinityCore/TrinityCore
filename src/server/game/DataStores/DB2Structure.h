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

struct SpellMiscEntry
{
    //uint32 ID;                                         // 0        m_ID
    uint32 Attributes;                                   // 1        m_attribute
    uint32 AttributesEx;                                 // 2        m_attributesEx
    uint32 AttributesEx2;                                // 3        m_attributesExB
    uint32 AttributesEx3;                                // 4        m_attributesExC
    uint32 AttributesEx4;                                // 5        m_attributesExD
    uint32 AttributesEx5;                                // 6        m_attributesExE
    uint32 AttributesEx6;                                // 7        m_attributesExF
    uint32 AttributesEx7;                                // 8        m_attributesExG
    uint32 AttributesEx8;                                // 9        m_attributesExH
    uint32 AttributesEx9;                                // 10       m_attributesExI
    uint32 AttributesEx10;                               // 11       m_attributesExJ
    uint32 AttributesEx11;                               // 12       m_attributesExK
    uint32 AttributesEx12;                               // 13       m_attributesExL
    uint32 AttributesEx13;                               // 14       m_attributesExL
    uint32 CastingTimeIndex;                             // 15       m_castingTimeIndex
    uint32 DurationIndex;                                // 16       m_durationIndex
    uint32 RangeIndex;                                   // 17       m_rangeIndex
    float Speed;                                         // 18       m_speed
    uint32 SpellVisual[2];                               // 19-20    m_spellVisualID
    uint32 SpellIconID;                                  // 21       m_spellIconID
    uint32 ActiveIconID;                                 // 22       m_activeIconID
    uint32 SchoolMask;                                   // 23       m_schoolMask
    //float UnkWod;                                      // 24
};

// SpellClassOptions.db2
struct SpellClassOptionsEntry
{
    //uint32    ID;                                         // 0       m_ID
    //uint32    modalNextSpell;                             // 1       m_modalNextSpell
    flag128   SpellFamilyFlags;                             // 2-5
    uint32    SpellFamilyName;                              // 6       m_spellClassSet
};

// SpellPower.db2
struct SpellPowerEntry
{
    //uint32   ID;                                          // 0
    uint32   PowerType;                                     // 1
    uint32   ManaCost;                                      // 2
    uint32   ManaCostPerlevel;                              // 3
    uint32   ManaPerSecond;                                 // 4
    uint32   ManaPerSecondPerLevel;                         // 5
    uint32   PowerDisplayId;                                // 6
    float    ManaCostPercentage;                            // 7
    //float    UnkMop1;                                     // 8
    uint32   RequiredAura;                                  // 9
    //float    UnkMop2;                                     // 10
    //uint32   UnkWod1;                                     // 11
    //uint32   UnkWod2;                                     // 12
    //uint32   UnkWod3;                                     // 13
};

// SpellAuraRestrictions.db2
struct SpellAuraRestrictionsEntry
{
    //uint32    ID;                                         // 0        m_ID
    uint32    CasterAuraState;                              // 1       m_casterAuraState
    uint32    TargetAuraState;                              // 2       m_targetAuraState
    uint32    CasterAuraStateNot;                           // 3       m_excludeCasterAuraState
    uint32    TargetAuraStateNot;                           // 4       m_excludeTargetAuraState
    uint32    CasterAuraSpell;                              // 5       m_casterAuraSpell
    uint32    TargetAuraSpell;                              // 6       m_targetAuraSpell
    uint32    ExcludeCasterAuraSpell;                       // 7       m_excludeCasterAuraSpell
    uint32    ExcludeTargetAuraSpell;                       // 8       m_excludeTargetAuraSpell
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    //uint32      id;                                       // 0
    uint32      SpellID[MAX_OVERRIDE_SPELL];                // 1-10
    //uint32    Unk1;                                       // 11
    //int32     Unk2;                                       // 12    SpellBarNameId?
};

// GCC has alternative #pragma pack(N) syntax and old gcc version does not support pack(push, N), also any gcc version does not support it at some platform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

#endif