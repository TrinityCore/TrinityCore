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
#include "Util.h"

#pragma pack(push, 1)

struct AchievementEntry
{
    uint32 ID;                                                      // 0
    int32  Faction;                                                 // 1 -1=all, 0=horde, 1=alliance
    int32  MapID;                                                   // 2 -1=none
    uint32 Supercedes;                                              // 3 its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    LocalizedString* Title;                                         // 4
    LocalizedString* Description;                                   // 5
    uint32 Category;                                                // 6
    uint32 Points;                                                  // 7 reward points
    uint32 UIOrder;                                                 // 8
    uint32 Flags;                                                   // 9
    uint32 IconID;                                                  // 10 icon (from SpellIcon.dbc)
    LocalizedString* Reward;                                        // 11
    uint32 MinimumCriteria;                                         // 12 - need this count of completed criterias (own or referenced achievement criterias)
    uint32 SharesCriteria;                                          // 13 - referenced achievement (counting of all completed criterias)
    uint32 CriteriaTree;                                            // 14
};

struct AreaGroupEntry
{
    uint32 ID;                                                      // 0
};

struct AreaGroupMemberEntry
{
    uint32 ID;                                                      // 0
    uint32 AreaGroupID;                                             // 1
    uint32 AreaID;                                                  // 2
};

struct AuctionHouseEntry
{
    uint32 ID;                                                      // 0
    uint32 FactionID;                                               // 1 id of faction.dbc for player factions associated with city
    uint32 DepositRate;                                             // 2 1/3 from real
    uint32 ConsignmentRate;                                         // 3
    LocalizedString* Name;                                          // 4
};

struct BarberShopStyleEntry
{
    uint32 ID;                                                      // 0
    uint32 Type;                                                    // 1 value 0 -> hair, value 2 -> facialhair
    LocalizedString* DisplayName;                                   // 2
    LocalizedString* Description;                                   // 3
    float  CostModifier;                                            // 4
    uint32 Race;                                                    // 5
    uint32 Sex;                                                     // 6
    uint32 Data;                                                    // 7 (real ID to hair/facial hair)
};

struct BattlePetBreedQualityEntry
{
    uint32 ID;                                                      // 0
    uint32 Quality;                                                 // 1
    float Modifier;                                                 // 2
};

struct BattlePetBreedStateEntry
{
    uint32 ID;                                                      // 0
    uint32 BreedID;                                                 // 1
    uint32 State;                                                   // 2
    int32 Value;                                                    // 3
};

struct BattlePetSpeciesEntry
{
    uint32 ID;                                                      // 0
    uint32 CreatureID;                                              // 1
    uint32 IconFileID;                                              // 2
    uint32 SummonSpellID;                                           // 3
    uint32 PetType;                                                 // 4
    int32  Source;                                                  // 5
    uint32 Flags;                                                   // 6
    LocalizedString* SourceText;                                    // 7
    LocalizedString* Description;                                   // 8
};

struct BattlePetSpeciesStateEntry
{
    uint32 ID;                                                      // 0
    uint32 SpeciesID;                                               // 1
    uint32 State;                                                   // 2
    int32 Value;                                                    // 3
};

#define MAX_BROADCAST_TEXT_EMOTES 3

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

#define MAX_OUTFIT_ITEMS 24

struct CharStartOutfitEntry
{
    uint32 ID;                                                      // 0
    uint8  RaceID;                                                  // 1
    uint8  ClassID;                                                 // 2
    uint8  GenderID;                                                // 3
    uint8  OutfitID;                                                // 4
    int32  ItemID[MAX_OUTFIT_ITEMS];                                // 5-28
    uint32 PetDisplayID;                                            // 29 Pet Model ID for starting pet
    uint32 PetFamilyID;                                             // 30 Pet Family Entry for starting pet
};

struct ChrClassesXPowerTypesEntry
{
    uint32 ID;                                                      // 0
    uint32 ClassID;                                                 // 1
    uint32 PowerType;                                               // 2
};

struct CinematicSequencesEntry
{
    uint32 ID;                                                      // 0
    uint32 SoundID;                                                 // 1
    uint32 Camera[8];                                               // 2-9
};

struct CreatureDisplayInfoEntry
{
    uint32 ID;                                                      // 0
    uint32 ModelID;                                                 // 1
    uint32 SoundID;                                                 // 2
    uint32 ExtendedDisplayInfoID;                                   // 3
    float  CreatureModelScale;                                      // 4
    float  Unknown620;                                              // 5
    uint32 CreatureModelAlpha;                                      // 6
    LocalizedString* TextureVariation[3];                           // 7-9
    LocalizedString* PortraitTextureName;                           // 10
    uint32 PortraitCreatureDisplayInfoID;                           // 11
    uint32 SizeClass;                                               // 12
    uint32 BloodID;                                                 // 13
    uint32 NPCSoundID;                                              // 14
    uint32 ParticleColorID;                                         // 15
    uint32 CreatureGeosetData;                                      // 16
    uint32 ObjectEffectPackageID;                                   // 17
    uint32 AnimReplacementSetID;                                    // 18
    uint32 Flags;                                                   // 19
    int32  Gender;                                                  // 20
    uint32 StateSpellVisualKitID;                                   // 21
};

struct CreatureTypeEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Name;                                          // 1
    uint32 Flags;                                                   // 2 no exp? critters, non-combat pets, gas cloud.
};

struct CriteriaEntry
{
    uint32 ID;                                                      // 0
    uint32 Type;                                                    // 1
    union
    {
        uint32 ID;
        // ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE          = 0
        // ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE     = 20
        uint32 CreatureID;

        // ACHIEVEMENT_CRITERIA_TYPE_WIN_BG                 = 1
        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND  = 15
        // ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP           = 16
        // ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA              = 32
        // ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA             = 33
        uint32 MapID;

        // ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL      = 7
        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL      = 40
        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS = 75
        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE       = 112
        uint32 SkillID;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT   = 8
        uint32 AchievementID;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE = 11
        uint32 ZoneID;

        // ACHIEVEMENT_CRITERIA_TYPE_CURRENCY = 12
        uint32 CurrencyID;

        // ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON       = 18
        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID          = 19
        uint32 GroupSize;

        // ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM            = 26
        uint32 DamageType;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST         = 27
        uint32 QuestID;

        // ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET        = 28
        // ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2       = 69
        // ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL             = 29
        // ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2            = 110
        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL            = 34
        uint32 SpellID;

        // ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE
        uint32 ObjectiveId;

        // ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA = 31
        // ACHIEVEMENT_CRITERIA_TYPE_ENTER_AREA             = 163
        // ACHIEVEMENT_CRITERIA_TYPE_LEAVE_AREA             = 164
        uint32 AreaID;

        // ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM               = 36
        // ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM               = 41
        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM              = 42
        // ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM             = 57
        // ACHIEVEMENT_CRITERIA_TYPE_OWN_TOY                = 185
        uint32 ItemID;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING    = 38
        // ACHIEVEMENT_CRITERIA_TYPE_REACH_TEAM_RATING      = 39
        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING = 39
        uint32 TeamType;

        // ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA           = 43
        uint32 WorldMapOverlayID;

        // ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION        = 46
        uint32 FactionID;

        // ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM        = 49
        uint32 ItemSlot;

        // ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT      = 50
        // ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT      = 51
        uint32 RollValue;

        // ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS               = 52
        uint32 ClassID;

        // ACHIEVEMENT_CRITERIA_TYPE_HK_RACE                = 53
        uint32 RaceID;

        // ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE               = 54
        uint32 EmoteID;

        // ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT         = 68
        // ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT     = 72
        uint32 GameObjectID;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_POWER          = 96
        uint32 PowerType;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_STAT           = 97
        uint32 StatType;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER     = 98
        uint32 SpellSchool;

        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE              = 109
        uint32 LootType;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER = 165
        uint32 DungeonEncounterID;

        // ACHIEVEMENT_CRITERIA_TYPE_CONSTRUCT_GARRISON_BUILDING = 169
        uint32 GarrBuildingID;

        // ACHIEVEMENT_CRITERIA_TYPE_UPGRADE_GARRISON       = 170
        uint32 GarrisonLevel;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GARRISON_MISSION = 174
        uint32 GarrMissionID;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GARRISON_SHIPMENT = 182
        uint32 CharShipmentContainerID;
    } Asset;                                                        // 2
    uint32 StartEvent;                                              // 3
    uint32 StartAsset;                                              // 4
    uint32 StartTimer;                                              // 5
    uint32 FailEvent;                                               // 6
    uint32 FailAsset;                                               // 7
    uint32 ModifierTreeId;                                          // 8
    uint32 Flags;                                                   // 9
    uint32 EligibilityWorldStateID;                                 // 10
    uint32 EligibilityWorldStateValue;                              // 11
};

struct CriteriaTreeEntry
{
    uint32 ID;                                                      // 0
    uint32 CriteriaID;                                              // 1
    uint64 Amount;                                                  // 2
    uint32 Operator;                                                // 3
    uint32 Parent;                                                  // 4
    uint32 Flags;                                                   // 5
    LocalizedString* Description;                                   // 6
    uint32 OrderIndex;                                              // 7
};

struct CurrencyTypesEntry
{
    uint32 ID;                                                      // 0
    uint32  CategoryID;                                             // 1
    LocalizedString* Name;                                          // 2
    LocalizedString* InventoryIcon[2];                              // 3-4
    uint32 SpellWeight;                                             // 5
    uint32 SpellCategory;                                           // 6
    uint32 MaxQty;                                                  // 7
    uint32 MaxEarnablePerWeek;                                      // 8
    uint32 Flags;                                                   // 9
    uint32 Quality;                                                 // 10
    LocalizedString* Description;                                   // 11
};

struct CurvePointEntry
{
    uint32 ID;                                                      // 0
    uint32 CurveID;                                                 // 1
    uint32 Index;                                                   // 2
    float X;                                                        // 3
    float Y;                                                        // 4
};

struct DestructibleModelDataEntry
{
    uint32 ID;                                                      // 0
    struct
    {
        uint32 DisplayID;                                           // 1
        uint32 ImpactEffectDoodadSet;                               // 2
        uint32 AmbientDoodadSet;                                    // 3
        uint32 NameSet;                                             // 4
    } StateDamaged;
    struct
    {
        uint32 DisplayID;                                           // 5
        uint32 DestructionDoodadSet;                                // 6
        uint32 ImpactEffectDoodadSet;                               // 7
        uint32 AmbientDoodadSet;                                    // 8
        uint32 NameSet;                                             // 9
    } StateDestroyed;
    struct
    {
        uint32 DisplayID;                                           // 10
        uint32 DestructionDoodadSet;                                // 11
        uint32 ImpactEffectDoodadSet;                               // 12
        uint32 AmbientDoodadSet;                                    // 13
        uint32 NameSet;                                             // 14
    } StateRebuilding;
    struct
    {
        uint32 DisplayID;                                           // 15
        uint32 InitDoodadSet;                                       // 16
        uint32 AmbientDoodadSet;                                    // 17
        uint32 NameSet;                                             // 18
    } StateSmoke;
    uint32 EjectDirection;                                          // 19
    uint32 RepairGroundFx;                                          // 20
    uint32 DoNotHighlight;                                          // 21
    uint32 HealEffect;                                              // 22
    uint32 HealEffectSpeed;                                         // 23
};

struct DurabilityQualityEntry
{
    uint32 ID;                                                      // 0
    float  QualityMod;                                              // 1
};

struct GameObjectsEntry
{
    uint32 ID;                                                      // 0
    uint32 MapID;                                                   // 1
    uint32 DisplayID;                                               // 2
    DBCPosition3D Position;                                         // 3-5
    float RotationX;                                                // 6
    float RotationY;                                                // 7
    float RotationZ;                                                // 8
    float RotationW;                                                // 9
    float Size;                                                     // 10
    uint32 PhaseUseFlags;                                           // 11
    uint32 PhaseID;                                                 // 12
    uint32 PhaseGroupID;                                            // 13
    uint32 Type;                                                    // 14
    uint32 Data[8];                                                 // 15-22
    LocalizedString* Name;                                          // 23
};

struct GameTablesEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Name;                                          // 1
    uint32 NumRows;                                                 // 2
    uint32 NumColumns;                                              // 3
};

struct GarrAbilityEntry
{
    uint32 ID;                                                      // 0
    uint32 Flags;                                                   // 1
    LocalizedString* Name;                                          // 2
    LocalizedString* Description;                                   // 3
    uint32 IconFileDataID;                                          // 4
    uint32 OtherFactionGarrAbilityID;                               // 5
    uint32 GarrAbilityCategoryID;                                   // 6
    uint32 FollowerTypeID;                                          // 7
};

struct GarrBuildingEntry
{
    uint32 ID;                                                      // 0
    uint32 HordeGameObjectID;                                       // 1
    uint32 AllianceGameObjectID;                                    // 2
    uint32 Unknown;                                                 // 3
    uint32 Type;                                                    // 4
    uint32 Level;                                                   // 5
    LocalizedString* NameAlliance;                                  // 6
    LocalizedString* NameHorde;                                     // 7
    LocalizedString* Description;                                   // 8
    LocalizedString* Tooltip;                                       // 9
    uint32 BuildDuration;                                           // 10
    uint32 CostCurrencyID;                                          // 11
    int32  CostCurrencyAmount;                                      // 12
    uint32 HordeTexPrefixKitID;                                     // 13
    uint32 AllianceTexPrefixKitID;                                  // 14
    uint32 IconFileDataID;                                          // 15
    uint32 BonusAmount;                                             // 16
    uint32 Flags;                                                   // 17
    uint32 AllianceActivationScenePackageID;                        // 18
    uint32 HordeActivationScenePackageID;                           // 19
    uint32 MaxShipments;                                            // 20
    uint32 FollowerRequiredGarrAbilityID;                           // 21
    uint32 FollowerGarrAbilityEffectID;                             // 22
    int32  CostMoney;                                               // 23
};

struct GarrBuildingPlotInstEntry
{
    uint32 ID;                                                      // 0
    uint32 GarrBuildingID;                                          // 1
    uint32 UiTextureAtlasMemberID;                                  // 2
    uint32 GarrSiteLevelPlotInstID;                                 // 3
    DBCPosition2D LandmarkOffset;                                   // 4-5
};

struct GarrClassSpecEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* NameMale;                                      // 1
    LocalizedString* NameFemale;                                    // 2
    LocalizedString* NameGenderless;                                // 3
    uint32 ClassAtlasID;                                            // 4 UiTextureAtlasMember.db2 ref
    uint32 GarrFollItemSetID;                                       // 5
};

struct GarrFollowerEntry
{
    uint32 ID;                                                      // 0
    uint32 FollowerTypeID;                                          // 1
    uint32 HordeCreatureID;                                         // 2
    uint32 AllianceCreatureID;                                      // 3
    uint32 HordeUiAnimRaceInfoID;                                   // 4
    uint32 AllianceUiAnimRaceInfoID;                                // 5
    uint32 Quality;                                                 // 6
    uint32 HordeGarrClassSpecID;                                    // 7
    uint32 AllianceGarrClassSpecID;                                 // 8
    uint32 HordeGarrFollItemSetID;                                  // 9
    uint32 AllianceGarrFollItemSetID;                               // 10
    uint32 Level;                                                   // 11
    uint32 ItemLevelWeapon;                                         // 12
    uint32 ItemLevelArmor;                                          // 13
    uint32 Unknown1;                                                // 14
    uint32 Flags;                                                   // 15
    LocalizedString* HordeSourceText;                               // 16
    LocalizedString* AllianceSourceText;                            // 17
    int32 Unknown2;                                                 // 18
    int32 Unknown3;                                                 // 19
    uint32 HordePortraitIconID;                                     // 20
    uint32 AlliancePortraitIconID;                                  // 21
    uint32 HordeListPortraitTextureKitID;                           // 22
    uint32 AllianceListPortraitTextureKitID;                        // 23
};

struct GarrFollowerXAbilityEntry
{
    uint32 ID;                                                      // 0
    uint32 GarrFollowerID;                                          // 1
    uint32 GarrAbilityID;                                           // 2
    uint32 FactionIndex;                                            // 3
};

struct GarrPlotEntry
{
    uint32 ID;                                                      // 0
    uint32 GarrPlotUICategoryID;                                    // 1
    uint32 PlotType;                                                // 2
    uint32 Flags;                                                   // 3
    LocalizedString* Name;                                          // 4
    uint32 MinCount;                                                // 5
    uint32 MaxCount;                                                // 6
    uint32 AllianceConstructionGameObjectID;                        // 7
    uint32 HordeConstructionGameObjectID;                           // 8
};

struct GarrPlotBuildingEntry
{
    uint32 ID;                                                      // 0
    uint32 GarrPlotID;                                              // 1
    uint32 GarrBuildingID;                                          // 2
};

struct GarrPlotInstanceEntry
{
    uint32 ID;                                                      // 0
    uint32 GarrPlotID;                                              // 1
    LocalizedString* Name;                                          // 2
};

struct GarrSiteLevelEntry
{
    uint32 ID;                                                      // 0
    uint32 Level;                                                   // 1
    uint32 MapID;                                                   // 2
    uint32 SiteID;                                                  // 3
    uint32 UITextureKitID;                                          // 4
    DBCPosition2D TownHall;                                         // 5-6
    uint32 MovieID;                                                 // 7
    uint32 Level2;                                                  // 8
    uint32 UpgradeResourceCost;                                     // 9
    uint32 UpgradeMoneyCost;                                        // 10
};

struct GarrSiteLevelPlotInstEntry
{
    uint32 ID;                                                       // 0
    uint32 GarrSiteLevelID;                                          // 1
    uint32 GarrPlotInstanceID;                                       // 2
    DBCPosition2D Landmark;                                          // 3-4
    uint32 Unknown;                                                  // 5
};

struct GlyphSlotEntry
{
    uint32 ID;                                                      // 0
    uint32 Type;                                                    // 1
    uint32 Tooltip;                                                 // 2
};

struct GuildPerkSpellsEntry
{
    uint32 ID;                                                      // 0
    uint32 GuildLevel;                                              // 1
    uint32 SpellID;                                                 // 2
};

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 16
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32 ID;                                                      // 0
    uint32 Duration[MAX_HOLIDAY_DURATIONS];                         // 1-10
    uint32 Date[MAX_HOLIDAY_DATES];                                 // 11-26 (dates in unix time starting at January, 1, 2000)
    uint32 Region;                                                  // 27
    uint32 Looping;                                                 // 28
    uint32 CalendarFlags[MAX_HOLIDAY_FLAGS];                        // 29-38
    uint32 HolidayNameID;                                           // 39 HolidayNames.dbc
    uint32 HolidayDescriptionID;                                    // 40 HolidayDescriptions.dbc
    LocalizedString* TextureFilename;                               // 41
    uint32 Priority;                                                // 42
    uint32 CalendarFilterType;                                      // 43 (-1 = Fishing Contest, 0 = Unk, 1 = Darkmoon Festival, 2 = Yearly holiday)
    uint32 Flags;                                                   // 44 (0 = Darkmoon Faire, Fishing Contest and Wotlk Launch, rest is 1)
};

struct ImportPriceArmorEntry
{
    uint32 ID;                                                      // 0
    float  ClothFactor;                                             // 1
    float  LeatherFactor;                                           // 2
    float  MailFactor;                                              // 3
    float  PlateFactor;                                             // 4
};

struct ImportPriceQualityEntry
{
    uint32 ID;                                                      // 0
    float  Factor;                                                  // 1
};

struct ImportPriceShieldEntry
{
    uint32 ID;                                                      // 0
    float  Factor;                                                  // 1
};

struct ImportPriceWeaponEntry
{
    uint32 ID;                                                      // 0
    float  Factor;                                                  // 1
};

struct ItemAppearanceEntry
{
    uint32 ID;                                                      // 0
    uint32 DisplayID;                                               // 1
    uint32 IconFileDataID;                                          // 2
};

struct ItemBonusEntry
{
    uint32 ID;                                                      // 0
    uint32 BonusListID;                                             // 1
    uint32 Type;                                                    // 2
    int32  Value[2];                                                // 3-4
    uint32 Index;                                                   // 5
};

struct ItemBonusTreeNodeEntry
{
    uint32 ID;                                                      // 0
    uint32 BonusTreeID;                                             // 1
    uint32 BonusTreeModID;                                          // 2
    uint32 SubTreeID;                                               // 3
    uint32 BonusListID;                                             // 4
};

struct ItemClassEntry
{
    uint32 ID;                                                      // 0
    uint32 Flags;                                                   // 1
    float  PriceMod;                                                // 2
    LocalizedString* Name;                                          // 3
};

struct ItemCurrencyCostEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemId;                                                  // 1
};

struct ItemDisenchantLootEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemClass;                                               // 1
    int32  ItemSubClass;                                            // 2
    uint32 ItemQuality;                                             // 3
    uint32 MinItemLevel;                                            // 4
    uint32 MaxItemLevel;                                            // 5
    uint32 RequiredDisenchantSkill;                                 // 6
};

struct ItemEffectEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemID;                                                  // 1
    uint32 OrderIndex;                                              // 2
    uint32 SpellID;                                                 // 3
    uint32 Trigger;                                                 // 4
    int32  Charges;                                                 // 5
    int32  Cooldown;                                                // 6
    uint32 Category;                                                // 7
    int32  CategoryCooldown;                                        // 8
    uint32 ChrSpecializationID;                                     // 9
};

struct ItemEntry
{
    uint32 ID;                                                      // 0
    uint32 Class;                                                   // 1
    uint32 SubClass;                                                // 2
    int32  SoundOverrideSubclass;                                   // 3
    int32  Material;                                                // 4
    uint32 InventoryType;                                           // 5
    uint32 Sheath;                                                  // 6
    uint32 FileDataID;                                              // 7
    uint32 GroupSoundsID;                                           // 8
};

#define MAX_ITEM_EXT_COST_ITEMS         5
#define MAX_ITEM_EXT_COST_CURRENCIES    5

struct ItemExtendedCostEntry
{
    uint32 ID;                                                      // 0 extended-cost entry id
    uint32 RequiredArenaSlot;                                       // 3 arena slot restrictions (min slot value)
    uint32 RequiredItem[MAX_ITEM_EXT_COST_ITEMS];                   // 3-6 required item id
    uint32 RequiredItemCount[MAX_ITEM_EXT_COST_ITEMS];              // 7-11 required count of 1st item
    uint32 RequiredPersonalArenaRating;                             // 12 required personal arena rating
    uint32 ItemPurchaseGroup;                                       // 13
    uint32 RequiredCurrency[MAX_ITEM_EXT_COST_CURRENCIES];          // 14-18 required curency id
    uint32 RequiredCurrencyCount[MAX_ITEM_EXT_COST_CURRENCIES];     // 19-23 required curency count
    uint32 RequiredFactionId;                                       // 24
    uint32 RequiredFactionStanding;                                 // 25
    uint32 RequirementFlags;                                        // 26
    uint32 RequiredAchievement;                                     // 27
    uint32 RequiredMoney;                                           // 28
};

struct ItemLimitCategoryEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Name;                                          // 1
    uint32 Quantity;                                                // 2
    uint32 Flags;                                                   // 3
};

struct ItemModifiedAppearanceEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemID;                                                  // 1
    uint32 AppearanceModID;                                         // 2
    uint32 AppearanceID;                                            // 3
    uint32 IconFileDataID;                                          // 4
    uint32 Index;                                                   // 5
};

struct ItemPriceBaseEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemLevel;                                               // 1 Item level (1 - 1000)
    float  ArmorFactor;                                             // 2 Price factor for armor
    float  WeaponFactor;                                            // 3 Price factor for weapons
};

#define MAX_ITEM_RANDOM_PROPERTIES 5

struct ItemRandomPropertiesEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* InternalName;                                  // 1
    uint32 Enchantment[MAX_ITEM_RANDOM_PROPERTIES];                 // 2-6
    LocalizedString* Name;                                          // 7
};

struct ItemRandomSuffixEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Name;                                          // 1
    LocalizedString* InternalName;                                  // 2
    uint32 Enchantment[MAX_ITEM_RANDOM_PROPERTIES];                 // 3-7
    uint32 AllocationPct[MAX_ITEM_RANDOM_PROPERTIES];               // 8-12
};

#define MAX_ITEM_PROTO_FLAGS 3
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_STATS  10

struct ItemSparseEntry
{
    uint32 ID;                                                      // 0
    uint32 Quality;                                                 // 1
    uint32 Flags[MAX_ITEM_PROTO_FLAGS];                             // 2-4
    float  Unk1;                                                    // 5
    float  Unk2;                                                    // 6
    uint32 BuyCount;                                                // 7
    uint32 BuyPrice;                                                // 8
    uint32 SellPrice;                                               // 9
    uint32 InventoryType;                                           // 10
    int32  AllowableClass;                                          // 11
    int32  AllowableRace;                                           // 12
    uint32 ItemLevel;                                               // 13
    int32  RequiredLevel;                                           // 14
    uint32 RequiredSkill;                                           // 15
    uint32 RequiredSkillRank;                                       // 16
    uint32 RequiredSpell;                                           // 17
    uint32 RequiredHonorRank;                                       // 18
    uint32 RequiredCityRank;                                        // 19
    uint32 RequiredReputationFaction;                               // 20
    uint32 RequiredReputationRank;                                  // 21
    uint32 MaxCount;                                                // 22
    uint32 Stackable;                                               // 23
    uint32 ContainerSlots;                                          // 24
    int32  ItemStatType[MAX_ITEM_PROTO_STATS];                      // 25 - 34
    int32  ItemStatValue[MAX_ITEM_PROTO_STATS];                     // 35 - 44
    int32  ItemStatAllocation[MAX_ITEM_PROTO_STATS];                // 45 - 54
    float  ItemStatSocketCostMultiplier[MAX_ITEM_PROTO_STATS];      // 55 - 64
    uint32 ScalingStatDistribution;                                 // 65
    uint32 DamageType;                                              // 66
    uint32 Delay;                                                   // 67
    float  RangedModRange;                                          // 68
    uint32 Bonding;                                                 // 69
    LocalizedString* Name;                                          // 70
    LocalizedString* Name2;                                         // 71
    LocalizedString* Name3;                                         // 72
    LocalizedString* Name4;                                         // 73
    LocalizedString* Description;                                   // 74
    uint32 PageText;                                                // 75
    uint32 LanguageID;                                              // 76
    uint32 PageMaterial;                                            // 77
    uint32 StartQuest;                                              // 78
    uint32 LockID;                                                  // 79
    int32  Material;                                                // 80
    uint32 Sheath;                                                  // 81
    uint32 RandomProperty;                                          // 82
    uint32 RandomSuffix;                                            // 83
    uint32 ItemSet;                                                 // 84
    uint32 Area;                                                    // 85
    uint32 Map;                                                     // 86
    uint32 BagFamily;                                               // 87
    uint32 TotemCategory;                                           // 88
    uint32 SocketColor[MAX_ITEM_PROTO_SOCKETS];                     // 89-91
    uint32 SocketBonus;                                             // 92
    uint32 GemProperties;                                           // 93
    float  ArmorDamageModifier;                                     // 94
    uint32 Duration;                                                // 95
    uint32 ItemLimitCategory;                                       // 96
    uint32 HolidayID;                                               // 97
    float  StatScalingFactor;                                       // 98
    uint32 CurrencySubstitutionID;                                  // 99
    uint32 CurrencySubstitutionCount;                               // 100
    uint32 ItemNameDescriptionID;                                   // 101
};

struct ItemSpecEntry
{
    uint32 ID;                                                      // 0
    uint32 MinLevel;                                                // 1
    uint32 MaxLevel;                                                // 2
    uint32 ItemType;                                                // 3
    uint32 PrimaryStat;                                             // 4
    uint32 SecondaryStat;                                           // 5
    uint32 SpecID;                                                  // 6
};

struct ItemSpecOverrideEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemID;                                                  // 1
    uint32 SpecID;                                                  // 2
};

struct ItemToBattlePetSpeciesEntry
{
    uint32      ID;                                                 // 0
    uint32      BattlePetSpeciesID;                                 // 1
};

struct ItemXBonusTreeEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemID;                                                  // 1
    uint32 BonusTreeID;                                             // 2
};

#define KEYCHAIN_SIZE   32

struct KeyChainEntry
{
    uint32 Id;
    uint8  Key[KEYCHAIN_SIZE];
};

struct MailTemplateEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Body;                                          // 1
};

struct ModifierTreeEntry
{
    uint32 ID;                                                      // 0
    uint32 Type;                                                    // 1
    uint32 Asset[2];                                                // 2-3
    uint32 Operator;                                                // 4
    uint32 Amount;                                                  // 5
    uint32 Parent;                                                  // 6
};

struct MountEntry
{
    uint32 Id;
    uint32 SpellId;
    uint32 MountTypeId;
    uint32 DisplayId;
    uint32 Flags;
    LocalizedString* Name;
    LocalizedString* Description;
    LocalizedString* SourceDescription;
    uint32 Source;
    uint32 PlayerConditionId;
};

struct MountCapabilityEntry
{
    uint32 ID;                                                      // 0
    uint32 Flags;                                                   // 1
    uint32 RequiredRidingSkill;                                     // 2
    uint32 RequiredArea;                                            // 3
    uint32 RequiredAura;                                            // 4
    uint32 RequiredSpell;                                           // 5
    uint32 SpeedModSpell;                                           // 6
    int32  RequiredMap;                                             // 7
};

struct MountTypeXCapabilityEntry
{
    uint32 ID;                                                      // 0
    uint32 MountTypeID;                                             // 1
    uint32 OrderIndex;                                              // 2
    uint32 MountCapabilityID;                                       // 3
};

struct NameGenEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Name;                                          // 1
    uint32 Race;                                                    // 2
    uint32 Sex;                                                     // 3
};

struct NamesProfanityEntry
{
    uint32 ID;                                                      // 0
    char const* Name;                                               // 1
    int32 Language;                                                 // 2
};

struct NamesReservedEntry
{
    uint32 ID;                                                      // 0
    char const* Name;                                               // 1
};

struct NamesReservedLocaleEntry
{
    uint32 ID;                                                      // 0
    char const* Name;                                               // 1
    uint32 LocaleMask;                                              // 2
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32 ID;                                                      // 0
    uint32 SpellID[MAX_OVERRIDE_SPELL];                             // 1-10
    uint32 Flags;                                                   // 11
    uint32 PlayerActionbarFileDataID;                               // 12
};

struct PhaseXPhaseGroupEntry
{
    uint32 ID;
    uint32 PhaseID;
    uint32 PhaseGroupID;
};

struct QuestMoneyRewardEntry
{
    uint32 Level;                                                   // 0
    uint32 Money[10];                                               // 1
};

struct QuestPackageItemEntry
{
    uint32 ID;                                                      // 0
    uint32 QuestPackageID;                                          // 1
    uint32 ItemID;                                                  // 2
    uint32 ItemCount;                                               // 3
    uint32 FilterType;                                              // 4
};

struct QuestSortEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* SortName;                                      // 1
};

struct QuestV2Entry
{
    uint32 ID;                                                      // 0
    uint32 UniqueBitFlag;                                           // 1
};

struct QuestXPEntry
{
    uint32 ID;                                                      // 0
    uint32 Exp[10];                                                 // 1
};

struct ScalingStatDistributionEntry
{
    uint32 ID;                                                      // 0
    uint32 MinLevel;                                                // 1
    uint32 MaxLevel;                                                // 2
    uint32 ItemLevelCurveID;                                        // 3
};

struct SoundEntriesEntry
{
    uint32 ID;                                                      // 0
    uint32 SoundType;                                               // 1
    LocalizedString* Name;                                          // 2
    uint32 FileDataID[20];                                          // 3-22
    uint32 Freq[20];                                                // 23-42
    float  VolumeFloat;                                             // 43
    uint32 Flags;                                                   // 44
    float  MinDistance;                                             // 45
    float  DistanceCutoff;                                          // 46
    uint32 EAXDef;                                                  // 47
    uint32 SoundEntriesAdvancedID;                                  // 48
    float  VolumeVariationPlus;                                     // 49
    float  VolumeVariationMinus;                                    // 50
    float  PitchVariationPlus;                                      // 51
    float  PitchVariationMinus;                                     // 52
    float  PitchAdjust;                                             // 53
    uint32 DialogType;                                              // 54
    uint32 BusOverwriteID;                                          // 55
};

struct SpecializationSpellsEntry
{
    uint32 ID;                                                      // 0
    uint32 SpecID;                                                  // 1
    uint32 OrderIndex;                                              // 2
    uint32 SpellID;                                                 // 3
    uint32 OverridesSpellID;                                        // 4
    LocalizedString* Description;                                   // 5
};

struct SpellAuraRestrictionsEntry
{
    uint32 ID;                                                      // 0
    uint32 CasterAuraState;                                         // 1
    uint32 TargetAuraState;                                         // 2
    uint32 ExcludeCasterAuraState;                                  // 3
    uint32 ExcludeTargetAuraState;                                  // 4
    uint32 CasterAuraSpell;                                         // 5
    uint32 TargetAuraSpell;                                         // 6
    uint32 ExcludeCasterAuraSpell;                                  // 7
    uint32 ExcludeTargetAuraSpell;                                  // 8
};

struct SpellCastingRequirementsEntry
{
    uint32 ID;                                                      // 0
    uint32 FacingCasterFlags;                                       // 1
    uint32 MinFactionID;                                            // 1
    uint32 MinReputation;                                           // 3
    uint32 RequiredAreasID;                                         // 4
    uint32 RequiredAuraVision;                                      // 5
    uint32 RequiresSpellFocus;                                      // 6
};

struct SpellCastTimesEntry
{
    uint32 ID;                                                      // 0
    int32  CastTime;                                                // 1
    int32  CastTimePerLevel;                                        // 2
    int32  MinCastTime;                                             // 3
};

struct SpellClassOptionsEntry
{
    uint32  ID;                                                     // 0
    uint32  ModalNextSpell;                                         // 1
    flag128 SpellClassMask;                                         // 2-5
    uint32  SpellClassSet;                                          // 6
};

struct SpellDurationEntry
{
    uint32 ID;                                                      // 0
    int32  Duration[3];                                             // 1-3
};

struct SpellItemEnchantmentConditionEntry
{
    uint32 ID;                                                      // 0
    uint8  LTOperandType[5];                                        // 1-2
    uint32 LTOperand[5];                                            // 2-6
    uint8  Operator[5];                                             // 7-8
    uint8  RTOperandType[5];                                        // 8-9
    uint32 RTOperand[5];                                            // 10-14
    uint8  Logic[5];                                                // 15-16
};

struct SpellLearnSpellEntry
{
    uint32 ID;                                                      // 0
    uint32 LearnSpellID;                                            // 1
    uint32 SpellID;                                                 // 2
    uint32 OverridesSpellID;                                        // 3
};

struct SpellMiscEntry
{
    uint32 ID;                                                      // 0
    uint32 Attributes;                                              // 1
    uint32 AttributesEx;                                            // 2
    uint32 AttributesExB;                                           // 3
    uint32 AttributesExC;                                           // 4
    uint32 AttributesExD;                                           // 5
    uint32 AttributesExE;                                           // 6
    uint32 AttributesExF;                                           // 7
    uint32 AttributesExG;                                           // 8
    uint32 AttributesExH;                                           // 9
    uint32 AttributesExI;                                           // 10
    uint32 AttributesExJ;                                           // 11
    uint32 AttributesExK;                                           // 12
    uint32 AttributesExL;                                           // 13
    uint32 AttributesExM;                                           // 14
    uint32 CastingTimeIndex;                                        // 15
    uint32 DurationIndex;                                           // 16
    uint32 RangeIndex;                                              // 17
    float  Speed;                                                   // 18
    uint32 SpellIconID;                                             // 21
    uint32 ActiveIconID;                                            // 22
    uint32 SchoolMask;                                              // 23
    float  MultistrikeSpeedMod;                                     // 24
};

struct SpellPowerEntry
{
    uint32 ID;                                                      // 0
    uint32 SpellID;                                                 // 1
    uint32 PowerIndex;                                              // 2
    uint32 PowerType;                                               // 3
    uint32 ManaCost;                                                // 4
    uint32 ManaCostPerLevel;                                        // 5
    uint32 ManaCostPerSecond;                                       // 6
    uint32 ManaCostAdditional;                                      // 7 Spell uses [ManaCost, ManaCost+ManaCostAdditional] power - affects tooltip parsing as multiplier on SpellEffectEntry::EffectPointsPerResource
                                                                    //   only SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE, SPELL_EFFECT_WEAPON_DAMAGE, SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    uint32 PowerDisplayID;                                          // 8
    uint32 UnitPowerBarID;                                          // 9
    float  ManaCostPercentage;                                      // 10
    float  ManaCostPercentagePerSecond;                             // 11
    uint32 RequiredAura;                                            // 12
    float  HealthCostPercentage;                                    // 13
};

struct SpellPowerDifficultyEntry
{
    uint32 SpellPowerID;                                            // 0
    uint32 DifficultyID;                                            // 1
    uint32 PowerIndex;                                              // 2
};

struct SpellRadiusEntry
{
    uint32 ID;                                                      // 0
    float  Radius;                                                  // 1
    float  RadiusPerLevel;                                          // 2
    float  RadiusMin;                                               // 3
    float  RadiusMax;                                               // 4
};

struct SpellRangeEntry
{
    uint32 ID;                                                      // 0
    float  MinRangeHostile;                                         // 1
    float  MinRangeFriend;                                          // 2
    float  MaxRangeHostile;                                         // 3
    float  MaxRangeFriend;                                          // 4
    uint32 Flags;                                                   // 5
    LocalizedString* DisplayName;                                   // 6
    LocalizedString* DisplayNameShort;                              // 7
};

#define MAX_SPELL_REAGENTS 8

struct SpellReagentsEntry
{
    uint32 ID;                                                      // 0
    int32  Reagent[MAX_SPELL_REAGENTS];                             // 1-8
    uint32 ReagentCount[MAX_SPELL_REAGENTS];                        // 9-16
};

struct SpellRuneCostEntry
{
    uint32 ID;                                                      // 0
    uint32 RuneCost[4];                                             // 1-4 (0=blood, 1=unholy, 2=frost, 3=death)
    uint32 RunicPower;                                              // 5

    bool NoRuneCost() const { return RuneCost[0] == 0 && RuneCost[1] == 0 && RuneCost[2] == 0 && RuneCost[3] == 0; }
    bool NoRunicPowerGain() const { return RunicPower == 0; }
};

#define MAX_SPELL_TOTEMS 2

struct SpellTotemsEntry
{
    uint32 ID;                                                      // 0
    uint32 RequiredTotemCategoryID[MAX_SPELL_TOTEMS];               // 1
    uint32 Totem[MAX_SPELL_TOTEMS];                                 // 2
};

struct SpellXSpellVisualEntry
{
    uint32 ID;                                                      // 0
    uint32 SpellID;                                                 // 1
    uint32 DifficultyID;                                            // 2
    uint32 SpellVisualID[2];                                        // 3-4
    float  Unk620;                                                  // 5
    uint32 PlayerConditionID;                                       // 6
    uint32 Flags;                                                   // 7
};

struct TaxiNodesEntry
{
    uint32 ID;                                                      // 0
    uint32 MapID;                                                   // 1
    DBCPosition3D Pos;                                              // 2-4
    LocalizedString* Name;                                          // 5
    uint32 MountCreatureID[2];                                      // 6-7
    uint32 ConditionID;                                             // 8
    uint32 LearnableIndex;                                          // 9 - some kind of index only for learnable nodes
    uint32 Flags;                                                   // 10
    DBCPosition2D MapOffset;                                        // 11-12
};

struct TaxiPathEntry
{
    uint32 ID;                                                      // 0
    uint32 From;                                                    // 1
    uint32 To;                                                      // 2
    uint32 Cost;                                                    // 3
};

struct TaxiPathNodeEntry
{
    uint32 ID;                                                      // 0
    uint32 PathID;                                                  // 1
    uint32 NodeIndex;                                               // 2
    uint32 MapID;                                                   // 3
    DBCPosition3D Loc;                                              // 4-6
    uint32 Flags;                                                   // 7
    uint32 Delay;                                                   // 8
    uint32 ArrivalEventID;                                          // 9
    uint32 DepartureEventID;                                        // 10
};

struct TotemCategoryEntry
{
    uint32 ID;                                                      // 0
    LocalizedString* Name;                                          // 1
    uint32 CategoryType;                                            // 2
    uint32 CategoryMask;                                            // 3
};

struct ToyEntry
{
    uint32 ID;                                                      // 0
    uint32 ItemID;                                                  // 1
    uint32 Flags;                                                   // 2
    LocalizedString* Description;                                   // 3
    uint32 CategoryFilter;                                          // 4
};

struct TransportAnimationEntry
{
    uint32 ID;                                                      // 0
    uint32 TransportID;                                             // 1
    uint32 TimeIndex;                                               // 2
    DBCPosition3D Pos;                                              // 3-5
    uint32 SequenceID;                                              // 6
};

struct TransportRotationEntry
{
    uint32 ID;                                                      // 0
    uint32 TransportID;                                             // 1
    uint32 TimeIndex;                                               // 2
    float  X;                                                       // 3
    float  Y;                                                       // 4
    float  Z;                                                       // 5
    float  W;                                                       // 6
};

struct UnitPowerBarEntry
{
    uint32 ID;                                                      // 0
    uint32 MinPower;                                                // 1
    uint32 MaxPower;                                                // 2
    uint32 StartPower;                                              // 3
    uint32 CenterPower;                                             // 4
    float  RegenerationPeace;                                       // 5
    float  RegenerationCombat;                                      // 6
    uint32 BarType;                                                 // 7
    uint32 FileDataID[6];                                           // 8-13
    uint32 Color[6];                                                // 14-19
    uint32 Flags;                                                   // 20
    LocalizedString* Name;                                          // 21
    LocalizedString* Cost;                                          // 22
    LocalizedString* OutOfError;                                    // 23
    LocalizedString* ToolTip;                                       // 24
    float  StartInset;                                              // 25
    float  EndInset;                                                // 26
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32 ID;                                                      // 0
    uint32 MapAreaID;                                               // 1 idx in WorldMapArea.dbc
    uint32 AreaID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];                  // 2-5
    LocalizedString* TextureName;                                   // 6
    uint32 TextureWidth;                                            // 7
    uint32 TextureHeight;                                           // 8
    uint32 OffsetX;                                                 // 9
    uint32 OffsetY;                                                 // 10
    uint32 HitRectTop;                                              // 11
    uint32 HitRectLeft;                                             // 12
    uint32 HitRectBottom;                                           // 13
    uint32 HitRectRight;                                            // 14
    uint32 PlayerConditionID;                                       // 15
};

#pragma pack(pop)

struct TaxiPathBySourceAndDestination
{
    TaxiPathBySourceAndDestination() : ID(0), price(0) { }
    TaxiPathBySourceAndDestination(uint32 _id, uint32 _price) : ID(_id), price(_price) { }

    uint32 ID;
    uint32 price;
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

#define TaxiMaskSize 217
typedef uint8 TaxiMask[TaxiMaskSize];

#endif
