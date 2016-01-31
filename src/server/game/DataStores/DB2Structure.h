/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "Util.h"

#pragma pack(push, 1)

struct AchievementEntry
{
    uint32 ID;
    LocalizedString* Title;
    LocalizedString* Description;
    uint32 Flags;
    LocalizedString* Reward;
    int16  MapID;                                                   // -1 = none
    uint16 Supercedes;                                              // its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    uint16 Category;
    uint16 UIOrder;
    uint16 IconID;
    uint16 SharesCriteria;                                          // referenced achievement (counting of all completed criterias)
    uint16 CriteriaTree;
    int8  Faction;                                                  // -1 = all, 0 = horde, 1 = alliance
    uint8 Points;
    uint8 MinimumCriteria;                                          // need this count of completed criterias (own or referenced achievement criterias)
};

struct AnimKitEntry
{
    uint32 OneShotDuration;
    uint16 OneShotStopAnimKitID;
    uint16 LowDefAnimKitID;
};

struct AreaGroupMemberEntry
{
    uint16 AreaGroupID;
    uint16 AreaID;
};

struct ArmorLocationEntry
{
    float Modifier[5];
};

struct AuctionHouseEntry
{
    LocalizedString* Name;
    uint16 FactionID;                                               // id of faction.dbc for player factions associated with city
    uint8 DepositRate;
    uint8 ConsignmentRate;
};

struct BankBagSlotPricesEntry
{
    uint32 Cost;
};

struct BarberShopStyleEntry
{
    uint32 ID;
    LocalizedString* DisplayName;
    LocalizedString* Description;
    float CostModifier;
    uint8 Type;                                                     // value 0 -> hair, value 2 -> facialhair
    uint8 Race;
    uint8 Sex;
    uint8 Data;                                                     // real ID to hair/facial hair
};

struct BattlePetBreedQualityEntry
{
    float Modifier;
    uint8 Quality;
};

struct BattlePetBreedStateEntry
{
    uint32 ID;
    int16 Value;
    uint8 BreedID;
    uint8 State;
};

struct BattlePetSpeciesEntry
{
    uint32 ID;
    uint32 CreatureID;
    uint32 IconFileID;
    uint32 SummonSpellID;
    LocalizedString* SourceText;
    LocalizedString* Description;
    uint16 Flags;
    uint8 PetType;
    int8  Source;
};

struct BattlePetSpeciesStateEntry
{
    uint32 ID;
    int32 Value;
    uint16 SpeciesID;
    uint8 State;
};

#define MAX_BROADCAST_TEXT_EMOTES 3

struct BroadcastTextEntry
{
    LocalizedString* MaleText;
    LocalizedString* FemaleText;
    uint16 EmoteID[MAX_BROADCAST_TEXT_EMOTES];
    uint16 EmoteDelay[MAX_BROADCAST_TEXT_EMOTES];
    uint16 SoundID;
    uint16 UnkEmoteID;
    uint8 Language;
    uint8 Type;
};

#define MAX_OUTFIT_ITEMS 24

struct CharStartOutfitEntry
{
    int32 ItemID[MAX_OUTFIT_ITEMS];
    uint32 PetDisplayID;                                            // Pet Model ID for starting pet
    uint8 RaceID;
    uint8 ClassID;
    uint8 GenderID;
    uint8 OutfitID;
    uint8 PetFamilyID;                                              // Pet Family Entry for starting pet
};

struct ChatChannelsEntry
{
    uint32 Flags;
    LocalizedString* Name;
    LocalizedString* Shortcut;
    uint8 FactionGroup;
};

struct ChrClassesXPowerTypesEntry
{
    uint8 ClassID;
    uint8 PowerType;
};

struct ChrRacesEntry
{
    uint32 ID;
    uint32 Flags;
    char const* ClientPrefix;
    char const* ClientFileString;
    LocalizedString* Name;
    LocalizedString* NameFemale;
    LocalizedString* NameMale;
    char const* FacialHairCustomization[2];
    char const* HairCustomization;
    uint32 CreateScreenFileDataID;
    uint32 SelectScreenFileDataID;
    float MaleCustomizeOffset[3];
    float FemaleCustomizeOffset[3];
    uint32 LowResScreenFileDataID;
    uint16 FactionID;
    uint16 ExplorationSoundID;
    uint16 MaleDisplayID;
    uint16 FemaleDisplayID;
    uint16 ResSicknessSpellID;
    uint16 SplashSoundID;
    uint16 CinematicSequenceID;
    uint16 UAMaleCreatureSoundDataID;
    uint16 UAFemaleCreatureSoundDataID;
    uint16 HighResMaleDisplayID;
    uint16 HighResFemaleDisplayID;
    uint16 Unk;
    uint8 BaseLanguage;
    uint8 CreatureType;
    uint8 TeamID;
    uint8 RaceRelated;
    uint8 UnalteredVisualRaceID;
    uint8 CharComponentTextureLayoutID;
    uint8 DefaultClassID;
    uint8 NeutralRaceID;
    uint8 CharComponentTexLayoutHiResID;
};

#define MAX_MASTERY_SPELLS 2

struct ChrSpecializationEntry
{
    uint32 ID;
    uint32 MasterySpellID[MAX_MASTERY_SPELLS];
    uint32 Flags;
    uint32 AnimReplacementSetID;
    LocalizedString* Name;
    LocalizedString* Name2;
    LocalizedString* Description;
    char* BackgroundFile;
    uint16 SpellIconID;
    uint8 ClassID;
    uint8 OrderIndex;
    uint8 PetTalentType;
    uint8 Role;
    uint8 PrimaryStatOrder;
};

struct CinematicSequencesEntry
{
    uint16 SoundID;
    uint16 Camera[8];
};

struct CreatureDisplayInfoEntry
{
    uint32 ID;
    uint32 ExtendedDisplayInfoID;
    float CreatureModelScale;
    float PlayerModelScale;
    uint32 TextureVariation[3];
    char const* PortraitTextureName;
    uint32 PortraitCreatureDisplayInfoID;
    uint32 CreatureGeosetData;
    uint32 StateSpellVisualKitID;
    uint16 ModelID;
    uint16 SoundID;
    uint16 NPCSoundID;
    uint16 ParticleColorID;
    uint16 ObjectEffectPackageID;
    uint16 AnimReplacementSetID;
    uint8 CreatureModelAlpha;
    uint8 SizeClass;
    uint8 BloodID;
    uint8 Flags;
    int8 Gender;
    int8 Unk700;
};

struct CreatureDisplayInfoExtraEntry
{
    uint32 FileDataID;
    uint32 HDFileDataID;
    uint8 DisplayRaceID;
    uint8 DisplaySexID;
    uint8 DisplayClassID;
    uint8 SkinID;
    uint8 FaceID;
    uint8 HairStyleID;
    uint8 HairColorID;
    uint8 FacialHairID;
    uint8 CustomDisplayOption[3];
    uint8 Flags;
};

struct CreatureTypeEntry
{
    LocalizedString* Name;
    uint8 Flags;                                                    // no exp? critters, non-combat pets, gas cloud.
};

struct CriteriaEntry
{
    union
    {
        uint32 ID;
        // CRITERIA_TYPE_KILL_CREATURE          = 0
        // CRITERIA_TYPE_KILLED_BY_CREATURE     = 20
        uint32 CreatureID;

        // CRITERIA_TYPE_WIN_BG                 = 1
        // CRITERIA_TYPE_COMPLETE_BATTLEGROUND  = 15
        // CRITERIA_TYPE_DEATH_AT_MAP           = 16
        // CRITERIA_TYPE_WIN_ARENA              = 32
        // CRITERIA_TYPE_PLAY_ARENA             = 33
        uint32 MapID;

        // CRITERIA_TYPE_REACH_SKILL_LEVEL      = 7
        // CRITERIA_TYPE_LEARN_SKILL_LEVEL      = 40
        // CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS = 75
        // CRITERIA_TYPE_LEARN_SKILL_LINE       = 112
        uint32 SkillID;

        // CRITERIA_TYPE_COMPLETE_ACHIEVEMENT   = 8
        uint32 AchievementID;

        // CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE = 11
        uint32 ZoneID;

        // CRITERIA_TYPE_CURRENCY = 12
        uint32 CurrencyID;

        // CRITERIA_TYPE_DEATH_IN_DUNGEON       = 18
        // CRITERIA_TYPE_COMPLETE_RAID          = 19
        uint32 GroupSize;

        // CRITERIA_TYPE_DEATHS_FROM            = 26
        uint32 DamageType;

        // CRITERIA_TYPE_COMPLETE_QUEST         = 27
        uint32 QuestID;

        // CRITERIA_TYPE_BE_SPELL_TARGET        = 28
        // CRITERIA_TYPE_BE_SPELL_TARGET2       = 69
        // CRITERIA_TYPE_CAST_SPELL             = 29
        // CRITERIA_TYPE_CAST_SPELL2            = 110
        // CRITERIA_TYPE_LEARN_SPELL            = 34
        uint32 SpellID;

        // CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE
        uint32 ObjectiveId;

        // CRITERIA_TYPE_HONORABLE_KILL_AT_AREA = 31
        // CRITERIA_TYPE_ENTER_AREA             = 163
        // CRITERIA_TYPE_LEAVE_AREA             = 164
        uint32 AreaID;

        // CRITERIA_TYPE_OWN_ITEM               = 36
        // CRITERIA_TYPE_USE_ITEM               = 41
        // CRITERIA_TYPE_LOOT_ITEM              = 42
        // CRITERIA_TYPE_EQUIP_ITEM             = 57
        // CRITERIA_TYPE_OWN_TOY                = 185
        uint32 ItemID;

        // CRITERIA_TYPE_HIGHEST_TEAM_RATING    = 38
        // CRITERIA_TYPE_REACH_TEAM_RATING      = 39
        // CRITERIA_TYPE_HIGHEST_PERSONAL_RATING = 39
        uint32 TeamType;

        // CRITERIA_TYPE_EXPLORE_AREA           = 43
        uint32 WorldMapOverlayID;

        // CRITERIA_TYPE_GAIN_REPUTATION        = 46
        uint32 FactionID;

        // CRITERIA_TYPE_EQUIP_EPIC_ITEM        = 49
        uint32 ItemSlot;

        // CRITERIA_TYPE_ROLL_NEED_ON_LOOT      = 50
        // CRITERIA_TYPE_ROLL_GREED_ON_LOOT      = 51
        uint32 RollValue;

        // CRITERIA_TYPE_HK_CLASS               = 52
        uint32 ClassID;

        // CRITERIA_TYPE_HK_RACE                = 53
        uint32 RaceID;

        // CRITERIA_TYPE_DO_EMOTE               = 54
        uint32 EmoteID;

        // CRITERIA_TYPE_USE_GAMEOBJECT         = 68
        // CRITERIA_TYPE_FISH_IN_GAMEOBJECT     = 72
        uint32 GameObjectID;

        // CRITERIA_TYPE_HIGHEST_POWER          = 96
        uint32 PowerType;

        // CRITERIA_TYPE_HIGHEST_STAT           = 97
        uint32 StatType;

        // CRITERIA_TYPE_HIGHEST_SPELLPOWER     = 98
        uint32 SpellSchool;

        // CRITERIA_TYPE_LOOT_TYPE              = 109
        uint32 LootType;

        // CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER = 165
        uint32 DungeonEncounterID;

        // CRITERIA_TYPE_CONSTRUCT_GARRISON_BUILDING = 169
        uint32 GarrBuildingID;

        // CRITERIA_TYPE_UPGRADE_GARRISON       = 170
        uint32 GarrisonLevel;

        // CRITERIA_TYPE_COMPLETE_GARRISON_MISSION = 174
        uint32 GarrMissionID;

        // CRITERIA_TYPE_COMPLETE_GARRISON_SHIPMENT = 182
        uint32 CharShipmentContainerID;
    } Asset;
    uint32 StartAsset;
    uint32 FailAsset;
    uint16 StartTimer;
    uint16 ModifierTreeId;
    uint16 EligibilityWorldStateID;
    uint8 Type;
    uint8 StartEvent;
    uint8 FailEvent;
    uint8 Flags;
    uint8 EligibilityWorldStateValue;
};

struct CriteriaTreeEntry
{
    uint32 Amount;
    LocalizedString* Description;
    uint16 CriteriaID;
    uint16 Parent;
    uint16 Flags;
    uint16 OrderIndex;
    uint8 Operator;
};

struct CurrencyTypesEntry
{
    uint32 ID;
    LocalizedString* Name;
    char const* InventoryIcon[2];
    uint32 MaxQty;
    uint32 MaxEarnablePerWeek;
    uint32 Flags;
    LocalizedString* Description;
    uint8 CategoryID;
    uint8 SpellWeight;
    uint8 SpellCategory;
    uint8 Quality;
};

struct CurvePointEntry
{
    float X;
    float Y;
    uint16 CurveID;
    uint8 Index;
};

struct DestructibleModelDataEntry
{
    uint16 StateDamagedDisplayID;
    uint16 StateDestroyedDisplayID;
    uint16 StateRebuildingDisplayID;
    uint16 StateSmokeDisplayID;
    uint16 HealEffectSpeed;
    uint8 StateDamagedImpactEffectDoodadSet;
    uint8 StateDamagedAmbientDoodadSet;
    uint8 StateDamagedNameSet;
    uint8 StateDestroyedDestructionDoodadSet;
    uint8 StateDestroyedImpactEffectDoodadSet;
    uint8 StateDestroyedAmbientDoodadSet;
    uint8 StateDestroyedNameSet;
    uint8 StateRebuildingDestructionDoodadSet;
    uint8 StateRebuildingImpactEffectDoodadSet;
    uint8 StateRebuildingAmbientDoodadSet;
    uint8 StateRebuildingNameSet;
    uint8 StateSmokeInitDoodadSet;
    uint8 StateSmokeAmbientDoodadSet;
    uint8 StateSmokeNameSet;
    uint8 EjectDirection;
    uint8 DoNotHighlight;
    uint8 HealEffect;
};

struct DurabilityCostsEntry
{
    uint16 WeaponSubClassCost[21];
    uint16 ArmorSubClassCost[8];
};

struct DurabilityQualityEntry
{
    float QualityMod;
};

struct EmotesEntry
{
    char const* EmoteSlashCommand;
    uint32 SpellVisualKitID;
    uint32 EmoteFlags;
    uint16 AnimID;
    uint16 EmoteSoundID;
    uint8 EmoteSpecProc;
    uint8 EmoteSpecProcParam;
};

struct EmotesTextSoundEntry
{
    uint16 EmotesTextId;
    uint16 SoundId;
    uint8 RaceId;
    uint8 SexId;
    uint8 ClassId;
};

struct GameObjectsEntry
{
    uint32 ID;
    DBCPosition3D Position;
    float RotationX;
    float RotationY;
    float RotationZ;
    float RotationW;
    float Size;
    int32 Data[8];
    LocalizedString* Name;
    uint16 MapID;
    uint16 DisplayID;
    uint16 PhaseID;
    uint16 PhaseGroupID;
    uint8 PhaseUseFlags;
    uint8 Type;
};

struct GameObjectDisplayInfoEntry
{
    uint32 FileDataID;
    DBCPosition3D GeoBoxMin;
    DBCPosition3D GeoBoxMax;
    float OverrideLootEffectScale;
    float OverrideNameScale;
    uint16 ObjectEffectPackageID;
};

struct GameTablesEntry
{
    LocalizedString* Name;
    uint16 NumRows;
    uint8 NumColumns;
};

struct GarrAbilityEntry
{
    uint32 ID;
    LocalizedString* Name;
    LocalizedString* Description;
    uint32 IconFileDataID;
    uint16 OtherFactionGarrAbilityID;
    uint8 Flags;
    uint8 GarrAbilityCategoryID;
    uint8 FollowerTypeID;
};

struct GarrBuildingEntry
{
    uint32 HordeGameObjectID;
    uint32 AllianceGameObjectID;
    LocalizedString* NameAlliance;
    LocalizedString* NameHorde;
    LocalizedString* Description;
    LocalizedString* Tooltip;
    uint32 IconFileDataID;
    uint16 BuildDuration;
    uint16 CostCurrencyID;
    int16 CostCurrencyAmount;
    uint16 AllianceActivationScenePackageID;
    uint16 HordeActivationScenePackageID;
    int16 CostMoney;
    uint8 Unknown;
    uint8 Type;
    uint8 Level;
    uint8 HordeTexPrefixKitID;
    uint8 AllianceTexPrefixKitID;
    uint8 BonusAmount;
    uint8 Flags;
    uint8 MaxShipments;
    uint8 FollowerRequiredGarrAbilityID;
    uint8 FollowerGarrAbilityEffectID;
    uint8 GarrTypeID;
};

struct GarrBuildingPlotInstEntry
{
    uint32 ID;
    DBCPosition2D LandmarkOffset;
    uint16 UiTextureAtlasMemberID;
    uint16 GarrSiteLevelPlotInstID;
    uint8 GarrBuildingID;
};

struct GarrClassSpecEntry
{
    uint32 ID;
    LocalizedString* NameMale;
    LocalizedString* NameFemale;
    LocalizedString* NameGenderless;
    uint16 ClassAtlasID;                                            // UiTextureAtlasMember.db2 ref
    uint8 GarrFollItemSetID;
    uint8 Unknown700;
};

struct GarrFollowerEntry
{
    uint32 HordeCreatureID;
    uint32 AllianceCreatureID;
    LocalizedString* HordeSourceText;
    LocalizedString* AllianceSourceText;
    uint32 HordePortraitIconID;
    uint32 AlliancePortraitIconID;
    uint16 ItemLevelWeapon;
    uint16 ItemLevelArmor;
    uint8 FollowerTypeID;
    uint8 HordeUiAnimRaceInfoID;
    uint8 AllianceUiAnimRaceInfoID;
    uint8 Quality;
    uint8 HordeGarrClassSpecID;
    uint8 AllianceGarrClassSpecID;
    uint8 HordeGarrFollItemSetID;
    uint8 AllianceGarrFollItemSetID;
    uint8 Level;
    uint8 Unknown1;
    uint8 Flags;
    int8 Unknown2;
    int8 Unknown3;
    uint8 HordeListPortraitTextureKitID;
    uint8 AllianceListPortraitTextureKitID;
    uint8 GarrTypeID;
};

struct GarrFollowerXAbilityEntry
{
    uint16 GarrFollowerID;
    uint16 GarrAbilityID;
    uint8 FactionIndex;
};

struct GarrPlotEntry
{
    LocalizedString* Name;
    uint32 AllianceConstructionGameObjectID;
    uint32 HordeConstructionGameObjectID;
    uint8 GarrPlotUICategoryID;
    uint8 PlotType;
    uint8 Flags;
    uint8 MinCount;
    uint8 MaxCount;
};

struct GarrPlotBuildingEntry
{
    uint8 GarrPlotID;
    uint8 GarrBuildingID;
};

struct GarrPlotInstanceEntry
{
    LocalizedString* Name;
    uint8 GarrPlotID;
};

struct GarrSiteLevelEntry
{
    DBCPosition2D TownHall;
    uint16 MapID;
    uint16 UpgradeResourceCost;
    uint16 UpgradeMoneyCost;
    uint8 Level;
    uint8 SiteID;
    uint8 UITextureKitID;
    uint8 MovieID;
    uint8 Level2;
};

struct GarrSiteLevelPlotInstEntry
{
    DBCPosition2D Landmark;
    uint16 GarrSiteLevelID;
    uint8 GarrPlotInstanceID;
    uint8 Unknown;
};

struct GemPropertiesEntry
{
    uint32 Type;
    uint16 EnchantID;
    uint16 MinItemLevel;
    uint8 MaxCountInv;
    uint8 MaxCountItem;
};

struct GlyphPropertiesEntry
{
    uint32 SpellID;
    uint16 SpellIconID;
    uint8 Type;
    uint8 GlyphExclusiveCategoryID;
};

struct GlyphSlotEntry
{
    uint8 Type;
    uint8 Tooltip;
};

struct GuildColorBackgroundEntry
{
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct GuildColorBorderEntry
{
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct GuildColorEmblemEntry
{
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct GuildPerkSpellsEntry
{
    uint32 SpellID;
    uint8 GuildLevel;
};

struct HeirloomEntry
{
    uint32 ID;
    uint32 ItemID;
    LocalizedString* SourceText;
    uint32 OldItem[2];
    uint32 NextDifficultyItemID;
    uint32 UpgradeItemID[2];
    uint16 ItemBonusListID[2];
    uint8 Flags;
    uint8 Source;
};

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 16
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32 Date[MAX_HOLIDAY_DATES];                                 // dates in unix time starting at January, 1, 2000
    char const* TextureFilename;
    uint16 Duration[MAX_HOLIDAY_DURATIONS];
    uint16 Region;
    uint8 Looping;
    uint8 CalendarFlags[MAX_HOLIDAY_FLAGS];
    uint8 HolidayNameID;
    uint8 HolidayDescriptionID;
    uint8 Priority;
    int8 CalendarFilterType;
    uint8 Flags;
};

struct ImportPriceArmorEntry
{
    float ClothFactor;
    float LeatherFactor;
    float MailFactor;
    float PlateFactor;
};

struct ImportPriceQualityEntry
{
    float Factor;
};

struct ImportPriceShieldEntry
{
    float Factor;
};

struct ImportPriceWeaponEntry
{
    float Factor;
};

struct ItemEntry
{
    uint32 FileDataID;
    uint8 Class;
    uint8 SubClass;
    int8 SoundOverrideSubclass;
    int8 Material;
    uint8 InventoryType;
    uint8 Sheath;
    uint8 GroupSoundsID;
};

struct ItemAppearanceEntry
{
    uint32 DisplayID;
    uint32 IconFileDataID;
    uint8 ObjectComponentSlot;
};

struct ItemArmorQualityEntry
{
    float QualityMod[7];
    uint16 ItemLevel;
};

struct ItemArmorShieldEntry
{
    float Quality[7];
    uint16 ItemLevel;
};

struct ItemArmorTotalEntry
{
    float Value[4];
    uint16 ItemLevel;
};

struct ItemBagFamilyEntry
{
    LocalizedString* Name;
};

struct ItemBonusEntry
{
    uint32 ID;
    int32 Value[2];
    uint16 BonusListID;
    uint8 Type;
    uint8 Index;
};

struct ItemBonusTreeNodeEntry
{
    uint16 BonusTreeID;
    uint16 SubTreeID;
    uint16 BonusListID;
    uint8 BonusTreeModID;
};

struct ItemClassEntry
{
    float PriceMod;
    LocalizedString* Name;
    uint8 Flags;
};

struct ItemCurrencyCostEntry
{
    uint32 ItemId;
};

struct ItemDamageAmmoEntry
{
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageOneHandEntry
{
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageOneHandCasterEntry
{
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageTwoHandEntry
{
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageTwoHandCasterEntry
{
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDisenchantLootEntry
{
    uint16 MinItemLevel;
    uint16 MaxItemLevel;
    uint16 RequiredDisenchantSkill;
    uint8 ItemClass;
    int8 ItemSubClass;
    uint8 ItemQuality;
};

struct ItemEffectEntry
{
    uint32 ItemID;
    uint32 SpellID;
    int32 Cooldown;
    int32 CategoryCooldown;
    int16 Charges;
    uint16 Category;
    uint16 ChrSpecializationID;
    uint8 OrderIndex;
    uint8 Trigger;
};

#define MAX_ITEM_EXT_COST_ITEMS         5
#define MAX_ITEM_EXT_COST_CURRENCIES    5

struct ItemExtendedCostEntry
{
    uint32 RequiredItem[MAX_ITEM_EXT_COST_ITEMS];                   // required item id
    uint32 RequiredCurrencyCount[MAX_ITEM_EXT_COST_CURRENCIES];     // required curency count
    uint32 RequiredMoney;
    uint16 RequiredItemCount[MAX_ITEM_EXT_COST_ITEMS];              // required count of 1st item
    uint16 RequiredPersonalArenaRating;                             // required personal arena rating
    uint16 RequiredCurrency[MAX_ITEM_EXT_COST_CURRENCIES];          // required curency id
    uint8 RequiredArenaSlot;                                        // arena slot restrictions (min slot value)
    uint8 RequiredFactionId;
    uint8 RequiredFactionStanding;
    uint8 RequirementFlags;
    uint8 RequiredAchievement;
};

struct ItemLimitCategoryEntry
{
    LocalizedString* Name;
    uint8 Quantity;
    uint8 Flags;
};

struct ItemModifiedAppearanceEntry
{
    uint32 ID;
    uint32 ItemID;
    uint16 AppearanceID;
    uint8 AppearanceModID;
    uint8 Index;
};

struct ItemPriceBaseEntry
{
    float ArmorFactor;
    float WeaponFactor;
    uint16 ItemLevel;
};

#define MAX_ITEM_RANDOM_PROPERTIES 5

struct ItemRandomPropertiesEntry
{
    LocalizedString* Name;
    uint16 Enchantment[MAX_ITEM_RANDOM_PROPERTIES];
};

struct ItemRandomSuffixEntry
{
    LocalizedString* Name;
    LocalizedString* InternalName;
    uint16 Enchantment[MAX_ITEM_RANDOM_PROPERTIES];
    uint16 AllocationPct[MAX_ITEM_RANDOM_PROPERTIES];
};

#define MAX_ITEM_SET_ITEMS 17

struct ItemSetEntry
{
    LocalizedString* Name;
    uint32 ItemID[MAX_ITEM_SET_ITEMS];
    uint16 RequiredSkillRank;
    uint8 RequiredSkill;
};

struct ItemSetSpellEntry
{
    uint32 SpellID;
    uint16 ItemSetID;
    uint16 ChrSpecID;
    uint8 Threshold;
};

#define MAX_ITEM_PROTO_FLAGS 3
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_STATS  10

struct ItemSparseEntry
{
    uint32 Flags[MAX_ITEM_PROTO_FLAGS];
    float Unk1;
    float Unk2;
    uint32 BuyPrice;
    uint32 SellPrice;
    int32 AllowableClass;
    int32 AllowableRace;
    uint32 RequiredSpell;
    uint32 MaxCount;
    uint32 Stackable;
    int32 ItemStatAllocation[MAX_ITEM_PROTO_STATS];
    float ItemStatSocketCostMultiplier[MAX_ITEM_PROTO_STATS];
    float RangedModRange;
    LocalizedString* Name;
    LocalizedString* Name2;
    LocalizedString* Name3;
    LocalizedString* Name4;
    LocalizedString* Description;
    uint32 BagFamily;
    float ArmorDamageModifier;
    uint32 Duration;
    float StatScalingFactor;
    uint16 ItemLevel;
    uint16 RequiredSkill;
    uint16 RequiredSkillRank;
    uint16 RequiredReputationFaction;
    int16 ItemStatValue[MAX_ITEM_PROTO_STATS];
    uint16 ScalingStatDistribution;
    uint16 Delay;
    uint16 PageText;
    uint16 StartQuest;
    uint16 LockID;
    uint16 RandomProperty;
    uint16 RandomSuffix;
    uint16 ItemSet;
    uint16 Area;
    uint16 Map;
    uint16 SocketBonus;
    uint16 GemProperties;
    uint16 ItemLimitCategory;
    uint16 HolidayID;
    uint16 ItemNameDescriptionID;
    uint8 Quality;
    uint8 BuyCount;
    uint8 InventoryType;
    int8 RequiredLevel;
    uint8 RequiredHonorRank;
    uint8 RequiredCityRank;
    uint8 RequiredReputationRank;
    uint8 ContainerSlots;
    int8 ItemStatType[MAX_ITEM_PROTO_STATS];
    uint8 DamageType;
    uint8 Bonding;
    uint8 LanguageID;
    uint8 PageMaterial;
    int8 Material;
    uint8 Sheath;
    uint8 TotemCategory;
    uint8 SocketColor[MAX_ITEM_PROTO_SOCKETS];
    uint8 CurrencySubstitutionID;
    uint8 CurrencySubstitutionCount;
    uint8 ArtifactID;
};

struct ItemSpecEntry
{
    uint16 SpecID;
    uint8 MinLevel;
    uint8 MaxLevel;
    uint8 ItemType;
    uint8 PrimaryStat;
    uint8 SecondaryStat;
};

struct ItemSpecOverrideEntry
{
    uint32 ItemID;
    uint16 SpecID;
};

struct ItemToBattlePetSpeciesEntry
{
    uint16 BattlePetSpeciesID;
};

struct ItemXBonusTreeEntry
{
    uint32 ItemID;
    uint16 BonusTreeID;
};

#define KEYCHAIN_SIZE   32

struct KeyChainEntry
{
    uint8 Key[KEYCHAIN_SIZE];
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32 Index[MAX_LOCK_CASE];
    uint16 Skill[MAX_LOCK_CASE];
    uint8 Type[MAX_LOCK_CASE];
    uint8 Action[MAX_LOCK_CASE];
};

struct MailTemplateEntry
{
    LocalizedString* Body;
};

struct ModifierTreeEntry
{
    uint32 Asset[2];
    uint16 Parent;
    uint8 Type;
    uint8 Unk700;
    uint8 Operator;
    uint8 Amount;
};

struct MountEntry
{
    uint32 ID;
    uint32 SpellId;
    uint32 DisplayId;
    LocalizedString* Name;
    LocalizedString* Description;
    LocalizedString* SourceDescription;
    uint16 MountTypeId;
    uint16 Flags;
    uint16 PlayerConditionId;
    uint8 Source;
};

struct MountCapabilityEntry
{
    uint32 ID;
    uint32 RequiredSpell;
    uint32 SpeedModSpell;
    uint16 RequiredRidingSkill;
    uint16 RequiredArea;
    int16 RequiredMap;
    uint8 Flags;
    uint8 RequiredAura;
};

struct MountTypeXCapabilityEntry
{
    uint16 MountTypeID;
    uint16 MountCapabilityID;
    uint8 OrderIndex;
};

struct MovieEntry
{
    uint32 AudioFileDataID;
    uint32 SubtitleFileDataID;
    uint8 Volume;
    uint8 KeyID;
};

struct NameGenEntry
{
    LocalizedString* Name;
    uint8 Race;
    uint8 Sex;
};

struct NamesProfanityEntry
{
    char const* Name;
    int8 Language;
};

struct NamesReservedEntry
{
    char const* Name;
};

struct NamesReservedLocaleEntry
{
    char const* Name;
    uint8 LocaleMask;
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32 SpellID[MAX_OVERRIDE_SPELL];
    uint32 PlayerActionbarFileDataID;
    uint8 Flags;
};

struct PhaseXPhaseGroupEntry
{
    uint16 PhaseID;
    uint16 PhaseGroupID;
};

struct PlayerConditionEntry
{
    uint32 RaceMask;
    uint32 SkillLogic;
    uint32 ReputationLogic;
    uint32 PrevQuestLogic;
    uint32 CurrQuestLogic;
    uint32 CurrentCompletedQuestLogic;
    uint32 SpellLogic;
    uint32 SpellID[4];
    uint32 ItemLogic;
    uint32 ItemID[4];
    uint32 Time[2];
    uint32 AuraSpellLogic;
    uint32 AuraSpellID[4];
    uint32 AchievementLogic;
    uint32 AreaLogic;
    uint32 QuestKillLogic;
    uint32 QuestKillMonster[6];
    LocalizedString* FailureDescription;
    uint32 Unknown700_1;
    uint32 Unknown700_2;
    uint16 MinLevel;
    uint16 MaxLevel;
    uint16 ClassMask;
    uint16 SkillID[4];
    int16 MinSkill[4];
    int16 MaxSkill[4];
    uint16 MinFactionID[3];
    uint16 MaxFactionID;
    uint16 PrevQuestID[4];
    uint16 CurrQuestID[4];
    uint16 CurrentCompletedQuestID[4];
    uint16 Explored[2];
    uint16 WorldStateExpressionID;
    uint16 Achievement[4];
    uint16 AreaID[4];
    uint16 QuestKillID;
    uint16 PhaseID;
    uint16 MinAvgItemLevel;
    uint16 MaxAvgItemLevel;
    uint16 MinAvgEquippedItemLevel;
    uint16 MaxAvgEquippedItemLevel;
    uint16 ModifierTreeID;
    uint8 Flags;
    int8 Gender;
    int8 NativeGender;
    uint8 LanguageID;
    uint8 MinLanguage;
    uint8 MaxLanguage;
    uint8 MinReputation[3];
    uint8 MaxReputation;
    uint8 Unknown1;
    uint8 MinPVPRank;
    uint8 MaxPVPRank;
    uint8 PvpMedal;
    uint8 ItemCount[4];
    uint8 ItemFlags;
    uint8 AuraCount[4];
    uint8 WeatherID;
    uint8 PartyStatus;
    uint8 LifetimeMaxPVPRank;
    uint8 LfgLogic;
    uint8 LfgStatus[4];
    uint8 LfgCompare[4];
    uint8 LfgValue[4];
    uint8 CurrencyLogic;
    uint8 CurrencyID[4];
    uint8 CurrencyCount[4];
    int8 MinExpansionLevel;
    int8 MaxExpansionLevel;
    int8 MinExpansionTier;
    int8 MaxExpansionTier;
    uint8 MinGuildLevel;
    uint8 MaxGuildLevel;
    uint8 PhaseUseFlags;
    uint8 PhaseGroupID;
    int8 ChrSpecializationIndex;
    int8 ChrSpecializationRole;
    int8 PowerType;
    int8 PowerTypeComp;
    int8 PowerTypeValue;
};

struct PowerDisplayEntry
{
    char const* GlobalStringBaseTag;
    uint8 PowerType;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct PvPDifficultyEntry
{
    uint16 MapID;
    uint8 BracketID;
    uint8 MinLevel;
    uint8 MaxLevel;

    // helpers
    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(BracketID); }
};

struct QuestFactionRewardEntry
{
    int16 QuestRewFactionValue[10];
};

struct QuestMoneyRewardEntry
{
    uint32 Money[10];
};

struct QuestPackageItemEntry
{
    uint32 ItemID;
    uint16 QuestPackageID;
    uint8 ItemCount;
    uint8 FilterType;
};

struct QuestSortEntry
{
    LocalizedString* SortName;
};

struct QuestV2Entry
{
    uint16 UniqueBitFlag;
};

struct QuestXPEntry
{
    uint16 Exp[10];
};

struct RandPropPointsEntry
{
    uint16 EpicPropertiesPoints[5];
    uint16 RarePropertiesPoints[5];
    uint16 UncommonPropertiesPoints[5];
};

struct ScalingStatDistributionEntry
{
    uint16 ItemLevelCurveID;
    uint8 MinLevel;
    uint8 MaxLevel;
};

struct SkillLineEntry
{
    LocalizedString* DisplayName;
    LocalizedString* Description;
    LocalizedString* AlternateVerb;
    uint16 SpellIconID;
    uint16 Flags;
    uint8 CategoryID;
    uint8 CanLink;
    uint8 ParentSkillLineID;
};

struct SkillLineAbilityEntry
{
    uint32 SpellID;
    uint32 RaceMask;
    uint32 ClassMask;
    uint32 SupercedesSpell;
    uint16 SkillLine;
    uint16 MinSkillLineRank;
    uint16 TrivialSkillLineRankHigh;
    uint16 TrivialSkillLineRankLow;
    uint16 UniqueBit;
    uint16 TradeSkillCategoryID;
    uint8 AquireMethod;
    uint8 NumSkillUps;
};

struct SkillRaceClassInfoEntry
{
    int32 RaceMask;
    uint16 SkillID;
    int16 ClassMask;
    uint16 Flags;
    uint16 SkillTierID;
    uint8 Availability;
    uint8 MinLevel;
};

struct SoundKitEntry
{
    uint32 ID;
    uint8 SoundType;
    LocalizedString* Name;
    float VolumeFloat;
    float MinDistance;
    float DistanceCutoff;
    float VolumeVariationPlus;
    float VolumeVariationMinus;
    float PitchVariationPlus;
    float PitchVariationMinus;
    float PitchAdjust;
    uint16 Flags;
    uint16 SoundEntriesAdvancedID;
    uint8 EAXDef;
    uint8 DialogType;
    uint8 BusOverwriteID;
    uint8 Unk700;
};

struct SpecializationSpellsEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 OverridesSpellID;
    LocalizedString* Description;
    uint16 SpecID;
    uint8 OrderIndex;
};

struct SpellEntry
{
    uint32 ID;
    LocalizedString* Name;
    LocalizedString* NameSubtext;
    LocalizedString* Description;
    LocalizedString* AuraDescription;
    uint32 MiscID;
    uint16 DescriptionVariablesID;
};

struct SpellAuraOptionsEntry
{
    uint32 SpellID;
    uint32 ProcCharges;
    uint32 ProcTypeMask;
    uint32 ProcCategoryRecovery;
    uint16 CumulativeAura;
    uint8 DifficultyID;
    uint8 ProcChance;
    uint8 SpellProcsPerMinuteID;
};

struct SpellAuraRestrictionsEntry
{
    uint32 SpellID;
    uint32 CasterAuraSpell;
    uint32 TargetAuraSpell;
    uint32 ExcludeCasterAuraSpell;
    uint32 ExcludeTargetAuraSpell;
    uint8 DifficultyID;
    uint8 CasterAuraState;
    uint8 TargetAuraState;
    uint8 ExcludeCasterAuraState;
    uint8 ExcludeTargetAuraState;
};

struct SpellCastTimesEntry
{
    int32 CastTime;
    int32 MinCastTime;
    int16 CastTimePerLevel;
};

struct SpellCastingRequirementsEntry
{
    uint32 SpellID;
    uint16 MinFactionID;
    uint16 RequiredAreasID;
    uint16 RequiresSpellFocus;
    uint8 FacingCasterFlags;
    uint8 MinReputation;
    uint8 RequiredAuraVision;
};

struct SpellCategoriesEntry
{
    uint32 SpellID;
    uint16 Category;
    uint16 StartRecoveryCategory;
    uint16 ChargeCategory;
    uint8 DifficultyID;
    uint8 DefenseType;
    uint8 DispelType;
    uint8 Mechanic;
    uint8 PreventionType;
};

struct SpellCategoryEntry
{
    LocalizedString* Name;
    int32 ChargeRecoveryTime;
    uint8 Flags;
    uint8 UsesPerWeek;
    uint8 MaxCharges;
};

struct SpellClassOptionsEntry
{
    uint32 SpellID;
    flag128 SpellClassMask;
    uint16  ModalNextSpell;
    uint8  SpellClassSet;
};

struct SpellCooldownsEntry
{
    uint32 SpellID;
    uint32 CategoryRecoveryTime;
    uint32 RecoveryTime;
    uint32 StartRecoveryTime;
    uint8 DifficultyID;
};

struct SpellDurationEntry
{
    int32 Duration;
    int32 MaxDuration;
    int16 DurationPerLevel;
};

struct SpellEffectEntry
{
    uint32 ID;
    float EffectAmplitude;
    uint32 EffectAuraPeriod;
    uint32 EffectBasePoints;
    float EffectBonusCoefficient;
    float EffectChainAmplitude;
    uint32 EffectDieSides;
    uint32 EffectItemType;
    int32 EffectMiscValue;
    int32 EffectMiscValueB;
    float EffectPointsPerResource;
    float EffectRealPointsPerLevel;
    flag128 EffectSpellClassMask;
    uint32 EffectTriggerSpell;
    float EffectPosFacing;
    uint32 SpellID;
    uint32 EffectAttributes;
    float BonusCoefficientFromAP;
    uint16 EffectAura;
    uint16 EffectChainTargets;
    uint8 DifficultyID;
    uint8 Effect;
    uint8 EffectMechanic;
    uint8 EffectRadiusIndex;
    uint8 EffectRadiusMaxIndex;
    uint8 ImplicitTarget[2];
    uint8 EffectIndex;
};

#define MAX_SPELL_EFFECTS 32
#define MAX_EFFECT_MASK 0xFFFFFFFF

struct SpellEffectScalingEntry
{
    float Coefficient;
    float Variance;
    float ResourceCoefficient;
    uint32 SpellEffectID;
};

struct SpellEquippedItemsEntry
{
    uint32 SpellID;
    int32 EquippedItemInventoryTypeMask;
    int32 EquippedItemSubClassMask;
    int8 EquippedItemClass;
};

struct SpellFocusObjectEntry
{
    LocalizedString* Name;
};

struct SpellInterruptsEntry
{
    uint32 SpellID;
    uint32 AuraInterruptFlags[2];
    uint32 ChannelInterruptFlags[2];
    uint16 InterruptFlags;
    uint8 DifficultyID;
};

struct SpellItemEnchantmentConditionEntry
{
    uint8 LTOperandType[5];
    uint8 LTOperand[5];
    uint8 Operator[5];
    uint8 RTOperandType[5];
    uint8 RTOperand[5];
    uint8 Logic[5];
};

struct SpellLearnSpellEntry
{
    uint32 LearnSpellID;
    uint32 SpellID;
    uint32 OverridesSpellID;
};

struct SpellLevelsEntry
{
    uint32 SpellID;
    uint16 BaseLevel;
    uint16 MaxLevel;
    uint16 SpellLevel;
    uint8 DifficultyID;
    uint8 MaxUsableLevel;
};

struct SpellMiscEntry
{
    uint32 Attributes;
    uint32 AttributesEx;
    uint32 AttributesExB;
    uint32 AttributesExC;
    uint32 AttributesExD;
    uint32 AttributesExE;
    uint32 AttributesExF;
    uint32 AttributesExG;
    uint32 AttributesExH;
    uint32 AttributesExI;
    uint32 AttributesExJ;
    uint32 AttributesExK;
    uint32 AttributesExL;
    uint32 AttributesExM;
    float Speed;
    float MultistrikeSpeedMod;
    uint16 CastingTimeIndex;
    uint16 DurationIndex;
    uint16 RangeIndex;
    uint16 SpellIconID;
    uint16 ActiveIconID;
    uint8 SchoolMask;
};

struct SpellPowerEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 ManaCost;
    float ManaCostPercentage;
    float ManaCostPercentagePerSecond;
    uint32 RequiredAura;
    float HealthCostPercentage;
    uint16 ManaCostPerSecond;
    uint16 ManaCostAdditional;                                      // Spell uses [ManaCost, ManaCost+ManaCostAdditional] power - affects tooltip parsing as multiplier on SpellEffectEntry::EffectPointsPerResource
                                                                    //   only SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE, SPELL_EFFECT_WEAPON_DAMAGE, SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    uint16 PowerDisplayID;
    uint16 UnitPowerBarID;
    uint8 PowerIndex;
    uint8 PowerType;
    uint8 ManaCostPerLevel;
};

struct SpellPowerDifficultyEntry
{
    uint32 SpellPowerID;
    uint8 DifficultyID;
    uint8 PowerIndex;
};

struct SpellProcsPerMinuteEntry
{
    uint32 ID;
    float BaseProcRate;
    uint32 Flags;
};

struct SpellProcsPerMinuteModEntry
{
    uint32 ID;
    uint32 Type;
    uint32 Param;
    float Coeff;
    uint32 SpellProcsPerMinuteID;
};

struct SpellRadiusEntry
{
    float Radius;
    float RadiusPerLevel;
    float RadiusMin;
    float RadiusMax;
};

struct SpellRangeEntry
{
    float MinRangeHostile;
    float MinRangeFriend;
    float MaxRangeHostile;
    float MaxRangeFriend;
    LocalizedString* DisplayName;
    LocalizedString* DisplayNameShort;
    uint8 Flags;
};

#define MAX_SPELL_REAGENTS 8

struct SpellReagentsEntry
{
    uint32 SpellID;
    int32 Reagent[MAX_SPELL_REAGENTS];
    uint16 ReagentCount[MAX_SPELL_REAGENTS];
};

struct SpellScalingEntry
{
    uint32 SpellID;
    uint16 ScalesFromItemLevel;
    int8 ScalingClass;
    uint8 MaxScalingLevel;
};

struct SpellShapeshiftEntry
{
    uint32 SpellID;
    uint32 ShapeshiftExclude[2];
    uint32 ShapeshiftMask[2];
    uint8 StanceBarOrder;
};

#define MAX_SHAPESHIFT_SPELLS 8

struct SpellShapeshiftFormEntry
{
    LocalizedString* Name;
    float WeaponDamageVariance;
    uint32 Flags;
    uint16 AttackIconID;
    uint16 CombatRoundTime;
    uint16 CreatureDisplayID[4];
    uint16 PresetSpellID[MAX_SHAPESHIFT_SPELLS];
    int8 CreatureType;
    uint8 MountTypeID;
    uint8 BonusActionBar;
};

struct SpellTargetRestrictionsEntry
{
    uint32 SpellID;
    float ConeAngle;
    float Width;
    uint32 Targets;
    uint16 MaxTargetLevel;
    uint16 TargetCreatureType;
    uint8 DifficultyID;
    uint8 MaxAffectedTargets;
};

#define MAX_SPELL_TOTEMS 2

struct SpellTotemsEntry
{
    uint32 SpellID;
    uint32 Totem[MAX_SPELL_TOTEMS];
    uint8 RequiredTotemCategoryID[MAX_SPELL_TOTEMS];
};

struct SpellXSpellVisualEntry
{
    uint32 ID;
    uint32 SpellID;
    float Unk620;
    uint16 SpellVisualID[2];
    uint16 PlayerConditionID;
    uint8 DifficultyID;
    uint8 Flags;
};

struct SummonPropertiesEntry
{
    uint32 Category;
    uint32 Faction;
    uint32 Type;
    int32 Slot;
    uint32 Flags;
};

struct TaxiNodesEntry
{
    uint32 ID;
    DBCPosition3D Pos;
    LocalizedString* Name;
    uint32 MountCreatureID[2];
    DBCPosition2D MapOffset;
    uint16 MapID;
    uint16 ConditionID;
    uint16 LearnableIndex;
    uint8 Flags;
};

struct TaxiPathEntry
{
    uint32 ID;
    uint16 From;
    uint16 To;
    uint16 Cost;
};

struct TaxiPathNodeEntry
{
    uint32 ID;
    DBCPosition3D Loc;
    uint32 Delay;
    uint16 PathID;
    uint16 MapID;
    uint16 ArrivalEventID;
    uint16 DepartureEventID;
    uint8 NodeIndex;
    uint8 Flags;
};

struct TotemCategoryEntry
{
    LocalizedString* Name;
    uint32 CategoryMask;
    uint8 CategoryType;
};

struct ToyEntry
{
    uint32 ID;
    uint32 ItemID;
    LocalizedString* Description;
    uint8 Flags;
    uint8 CategoryFilter;
};

struct TransportAnimationEntry
{
    uint32 TransportID;
    uint32 TimeIndex;
    DBCPosition3D Pos;
    uint8 SequenceID;
};

struct TransportRotationEntry
{
    uint32 TransportID;
    uint32 TimeIndex;
    float X;
    float Y;
    float Z;
    float W;
};

struct UnitPowerBarEntry
{
    uint32 MaxPower;
    float RegenerationPeace;
    float RegenerationCombat;
    uint32 FileDataID[6];
    uint32 Color[6];
    LocalizedString* Name;
    LocalizedString* Cost;
    LocalizedString* OutOfError;
    LocalizedString* ToolTip;
    float StartInset;
    float EndInset;
    uint16 StartPower;
    uint16 Flags;
    uint8 MinPower;
    uint8 CenterPower;
    uint8 BarType;
};

struct VehicleSeatEntry
{
    uint32 Flags[3];
    DBCPosition3D AttachmentOffset;
    float EnterPreDelay;
    float EnterSpeed;
    float EnterGravity;
    float EnterMinDuration;
    float EnterMaxDuration;
    float EnterMinArcHeight;
    float EnterMaxArcHeight;
    float ExitPreDelay;
    float ExitSpeed;
    float ExitGravity;
    float ExitMinDuration;
    float ExitMaxDuration;
    float ExitMinArcHeight;
    float ExitMaxArcHeight;
    float PassengerYaw;
    float PassengerPitch;
    float PassengerRoll;
    float VehicleEnterAnimDelay;
    float VehicleExitAnimDelay;
    float CameraEnteringDelay;
    float CameraEnteringDuration;
    float CameraExitingDelay;
    float CameraExitingDuration;
    DBCPosition3D CameraOffset;
    float CameraPosChaseRate;
    float CameraFacingChaseRate;
    float CameraEnteringZoom;
    float CameraSeatZoomMin;
    float CameraSeatZoomMax;
    uint32 UISkinFileDataID;
    int16 EnterAnimStart;
    int16 EnterAnimLoop;
    int16 RideAnimStart;
    int16 RideAnimLoop;
    int16 RideUpperAnimStart;
    int16 RideUpperAnimLoop;
    int16 ExitAnimStart;
    int16 ExitAnimLoop;
    int16 ExitAnimEnd;
    int16 VehicleEnterAnim;
    int16 VehicleExitAnim;
    int16 VehicleRideAnimLoop;
    uint16 EnterUISoundID;
    uint16 ExitUISoundID;
    uint16 EnterAnimKitID;
    uint16 RideAnimKitID;
    uint16 ExitAnimKitID;
    uint16 VehicleEnterAnimKitID;
    uint16 VehicleRideAnimKitID;
    uint16 VehicleExitAnimKitID;
    uint16 CameraModeID;
    int8 AttachmentID;
    int8 PassengerAttachmentID;
    int8 VehicleEnterAnimBone;
    int8 VehicleExitAnimBone;
    int8 VehicleRideAnimLoopBone;
    uint8 VehicleAbilityDisplay;

    bool CanEnterOrExit() const
    {
        return ((Flags[0] & VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT) != 0 ||
                //If it has anmation for enter/ride, means it can be entered/exited by logic
                (Flags[0] & (VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER | VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE)) != 0);
    }
    bool CanSwitchFromSeat() const { return (Flags[0] & VEHICLE_SEAT_FLAG_CAN_SWITCH) != 0; }
    bool IsUsableByOverride() const
    {
        return (Flags[0] & (VEHICLE_SEAT_FLAG_UNCONTROLLED | VEHICLE_SEAT_FLAG_UNK18)
                                    || (Flags[1] & (VEHICLE_SEAT_FLAG_B_USABLE_FORCED | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2 |
                                        VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3 | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4)));
    }
    bool IsEjectable() const { return (Flags[1] & VEHICLE_SEAT_FLAG_B_EJECTABLE) != 0; }
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    char const* TextureName;
    uint16 MapAreaID;                                               // idx in WorldMapArea.dbc
    uint16 AreaID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];
    uint16 TextureWidth;
    uint16 TextureHeight;
    uint16 OffsetX;
    uint16 OffsetY;
    uint16 HitRectTop;
    uint16 HitRectLeft;
    uint16 HitRectBottom;
    uint16 HitRectRight;
    uint16 PlayerConditionID;
};

struct WorldMapTransformsEntry
{
    DBCPosition3D RegionMin;
    DBCPosition3D RegionMax;
    DBCPosition2D RegionOffset;
    float RegionScale;
    uint16 MapID;
    uint16 NewMapID;
    uint16 NewDungeonMapID;
    uint16 NewAreaID;
    uint8 Flags;
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

typedef std::vector<TaxiPathNodeEntry const*> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

#define TaxiMaskSize 226
typedef std::array<uint8, TaxiMaskSize> TaxiMask;

#endif
