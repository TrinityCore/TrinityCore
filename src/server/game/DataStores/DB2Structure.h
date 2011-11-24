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
#include "DBCEnums.h"
#include "Define.h"
#include "Path.h"
#include "Util.h"
#include "Vehicle.h"
#include "SharedDefines.h"

#include <map>
#include <set>
#include <vector>

// Structures used to access raw DB2 data and required packing to portability
struct ItemEntry
{
   uint32   ID;                                             // 0
   uint32   Class;                                          // 1
   uint32   SubClass;                                       // 2
   int32    Unk0;                                           // 3
   int32    Material;                                       // 4
   uint32   DisplayId;                                      // 5
   uint32   InventoryType;                                  // 6
   uint32   Sheath;                                         // 7
};

struct ItemSparseEntry
{
    uint32     ID;                                           // 0
    uint32     Quality;                                      // 1
    uint32     Flags;                                        // 2
    uint32     Flags2;                                       // 3
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
    char*      Name;                                         // 96
    char*      Name2;                                        // 97
    char*      Name3;                                        // 98
    char*      Name4;                                        // 99
    char*      Description;                                  // 100
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
    uint32     MaxDurability;                                // 111
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
    int32      Field130;                                     // 129
    int32      Field131;                                     // 130
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
    //uint32    Unknown[5];                               // 26-30
};

#endif