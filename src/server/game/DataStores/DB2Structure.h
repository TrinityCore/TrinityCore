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

#ifndef TRINITY_DB2STRUCTURE_H
#define TRINITY_DB2STRUCTURE_H

#include "Common.h"
#include "DBCEnums.h"
#include "RaceMask.h"
#include "Util.h"

#pragma pack(push, 1)

struct AchievementEntry
{
    LocalizedString Description;
    LocalizedString Title;
    LocalizedString Reward;
    uint32 ID;
    int16 InstanceID;                                               // -1 = none
    int8 Faction;                                                   // -1 = all, 0 = horde, 1 = alliance
    int16 Supercedes;                                               // its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    int16 Category;
    int8 MinimumCriteria;                                           // need this count of completed criterias (own or referenced achievement criterias)
    int8 Points;
    int32 Flags;
    int16 UiOrder;
    int32 IconFileID;
    int32 RewardItemID;
    uint32 CriteriaTree;
    int16 SharesCriteria;                                           // referenced achievement (counting of all completed criterias)
    int32 CovenantID;
};

struct Achievement_CategoryEntry
{
    LocalizedString Name;
    uint32 ID;
    int16 Parent;
    int8 UiOrder;
};

struct AdventureJournalEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    LocalizedString ButtonText;
    LocalizedString RewardDescription;
    LocalizedString ContinueDescription;
    uint8 Type;
    uint32 PlayerConditionID;
    uint8 Flags;
    uint8 ButtonActionType;
    int32 TextureFileDataID;
    uint16 LfgDungeonID;
    int32 QuestID;
    uint16 BattleMasterListID;
    uint8 PriorityMin;
    uint8 PriorityMax;
    int32 ItemID;
    uint32 ItemQuantity;
    uint16 CurrencyType;
    uint32 CurrencyQuantity;
    uint16 UiMapID;
    uint32 BonusPlayerConditionID[2];
    uint8 BonusValue[2];
};

struct AdventureMapPOIEntry
{
    uint32 ID;
    LocalizedString Title;
    LocalizedString Description;
    DBCPosition2D WorldPosition;
    int8 Type;
    uint32 PlayerConditionID;
    uint32 QuestID;
    uint32 LfgDungeonID;
    int32 RewardItemID;
    uint32 UiTextureAtlasMemberID;
    uint32 UiTextureKitID;
    int32 MapID;
    uint32 AreaTableID;
};

struct AnimationDataEntry
{
    uint32 ID;
    uint16 Fallback;
    uint8 BehaviorTier;
    int32 BehaviorID;
    int32 Flags[2];
};

struct AnimKitEntry
{
    uint32 ID;
    uint32 OneShotDuration;
    uint16 OneShotStopAnimKitID;
    uint16 LowDefAnimKitID;
};

struct AreaGroupMemberEntry
{
    uint32 ID;
    uint16 AreaID;
    uint32 AreaGroupID;
};

struct AreaTableEntry
{
    uint32 ID;
    char const* ZoneName;
    LocalizedString AreaName;
    uint16 ContinentID;
    uint16 ParentAreaID;
    int16 AreaBit;
    uint8 SoundProviderPref;
    uint8 SoundProviderPrefUnderwater;
    uint16 AmbienceID;
    uint16 UwAmbience;
    uint16 ZoneMusic;
    uint16 UwZoneMusic;
    uint16 IntroSound;
    uint32 UwIntroSound;
    uint8 FactionGroupMask;
    float AmbientMultiplier;
    uint8 MountFlags;
    int16 PvpCombatWorldStateID;
    uint8 WildBattlePetLevelMin;
    uint8 WildBattlePetLevelMax;
    uint8 WindSettingsID;
    int32 ContentTuningID;
    int32 Flags[2];
    uint16 LiquidTypeID[4];

    // helpers
    bool IsSanctuary() const
    {
        if (ContinentID == 609)
            return true;
        return (Flags[0] & AREA_FLAG_SANCTUARY) != 0;
    }

    bool IsFlyable() const
    {
        if (Flags[0] & AREA_FLAG_OUTLAND)
        {
            if (!(Flags[0] & AREA_FLAG_NO_FLY_ZONE))
                return true;
        }

        return false;
    }
};

struct AreaTriggerEntry
{
    DBCPosition3D Pos;
    uint32 ID;
    int16 ContinentID;
    int8 PhaseUseFlags;
    int16 PhaseID;
    int16 PhaseGroupID;
    float Radius;
    float BoxLength;
    float BoxWidth;
    float BoxHeight;
    float BoxYaw;
    int8 ShapeType;
    int16 ShapeID;
    int16 AreaTriggerActionSetID;
    int8 Flags;
};

struct ArmorLocationEntry
{
    uint32 ID;
    float Clothmodifier;
    float Leathermodifier;
    float Chainmodifier;
    float Platemodifier;
    float Modifier;
};

struct ArtifactEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 UiTextureKitID;
    int32 UiNameColor;
    int32 UiBarOverlayColor;
    int32 UiBarBackgroundColor;
    uint16 ChrSpecializationID;
    uint8 Flags;
    uint8 ArtifactCategoryID;
    uint32 UiModelSceneID;
    uint32 SpellVisualKitID;
};

struct ArtifactAppearanceEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 ArtifactAppearanceSetID;
    uint8 DisplayIndex;
    uint32 UnlockPlayerConditionID;
    uint8 ItemAppearanceModifierID;
    int32 UiSwatchColor;
    float UiModelSaturation;
    float UiModelOpacity;
    uint8 OverrideShapeshiftFormID;
    uint32 OverrideShapeshiftDisplayID;
    uint32 UiItemAppearanceID;
    uint32 UiAltItemAppearanceID;
    uint8 Flags;
    uint16 UiCameraID;
    uint32 UsablePlayerConditionID;
};

struct ArtifactAppearanceSetEntry
{
    LocalizedString Name;
    LocalizedString Description;
    uint32 ID;
    uint8 DisplayIndex;
    uint16 UiCameraID;
    uint16 AltHandUICameraID;
    int8 ForgeAttachmentOverride;
    uint8 Flags;
    uint32 ArtifactID;
};

struct ArtifactCategoryEntry
{
    uint32 ID;
    int16 XpMultCurrencyID;
    int16 XpMultCurveID;
};

struct ArtifactPowerEntry
{
    DBCPosition2D DisplayPos;
    uint32 ID;
    uint8 ArtifactID;
    uint8 MaxPurchasableRank;
    int32 Label;
    uint8 Flags;
    uint8 Tier;
};

struct ArtifactPowerLinkEntry
{
    uint32 ID;
    uint16 PowerA;
    uint16 PowerB;
};

struct ArtifactPowerPickerEntry
{
    uint32 ID;
    uint32 PlayerConditionID;
};

struct ArtifactPowerRankEntry
{
    uint32 ID;
    uint8 RankIndex;
    int32 SpellID;
    uint16 ItemBonusListID;
    float AuraPointsOverride;
    uint32 ArtifactPowerID;
};

struct ArtifactQuestXPEntry
{
    uint32 ID;
    uint32 Difficulty[10];
};

struct ArtifactTierEntry
{
    uint32 ID;
    uint32 ArtifactTier;
    uint32 MaxNumTraits;
    uint32 MaxArtifactKnowledge;
    uint32 KnowledgePlayerCondition;
    uint32 MinimumEmpowerKnowledge;
};

struct ArtifactUnlockEntry
{
    uint32 ID;
    uint32 PowerID;
    uint8 PowerRank;
    uint16 ItemBonusListID;
    uint32 PlayerConditionID;
    uint32 ArtifactID;
};

struct AuctionHouseEntry
{
    uint32 ID;
    LocalizedString Name;
    uint16 FactionID;                                               // id of faction.dbc for player factions associated with city
    uint8 DepositRate;
    uint8 ConsignmentRate;
};

struct AzeriteEmpoweredItemEntry
{
    uint32 ID;
    int32 ItemID;
    uint32 AzeriteTierUnlockSetID;
    uint32 AzeritePowerSetID;
};

struct AzeriteEssenceEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    int32 SpecSetID;
};

struct AzeriteEssencePowerEntry
{
    uint32 ID;
    LocalizedString SourceAlliance;
    LocalizedString SourceHorde;
    int32 AzeriteEssenceID;
    uint8 Tier;
    int32 MajorPowerDescription;
    int32 MinorPowerDescription;
    int32 MajorPowerActual;
    int32 MinorPowerActual;
};

struct AzeriteItemEntry
{
    uint32 ID;
    int32 ItemID;
};

struct AzeriteItemMilestonePowerEntry
{
    uint32 ID;
    int32 RequiredLevel;
    int32 AzeritePowerID;
    int32 Type;
    int32 AutoUnlock;
};

struct AzeriteKnowledgeMultiplierEntry
{
    uint32 ID;
    float Multiplier;
};

struct AzeriteLevelInfoEntry
{
    uint32 ID;
    uint64 BaseExperienceToNextLevel;
    uint64 MinimumExperienceToNextLevel;
    int32 ItemLevel;
};

struct AzeritePowerEntry
{
    uint32 ID;
    int32 SpellID;
    int32 ItemBonusListID;
    int32 SpecSetID;
    int32 Flags;
};

struct AzeritePowerSetMemberEntry
{
    uint32 ID;
    int32 AzeritePowerSetID;
    int32 AzeritePowerID;
    int32 Class;
    int8 Tier;
    int32 OrderIndex;
};

struct AzeriteTierUnlockEntry
{
    uint32 ID;
    uint8 ItemCreationContext;
    uint8 Tier;
    uint8 AzeriteLevel;
    uint32 AzeriteTierUnlockSetID;
};

struct AzeriteTierUnlockSetEntry
{
    uint32 ID;
    int32 Flags;
};

struct AzeriteUnlockMappingEntry
{
    uint32 ID;
    int32 ItemLevel;
    int32 ItemBonusListHead;
    int32 ItemBonusListShoulders;
    int32 ItemBonusListChest;
    uint32 AzeriteUnlockMappingSetID;
};

struct BankBagSlotPricesEntry
{
    uint32 ID;
    uint32 Cost;
};

struct BannedAddonsEntry
{
    uint32 ID;
    char const* Name;
    char const* Version;
    uint8 Flags;
};

struct BarberShopStyleEntry
{
    uint32 ID;
    LocalizedString DisplayName;
    LocalizedString Description;
    uint8 Type;                                                     // value 0 -> hair, value 2 -> facialhair
    float CostModifier;
    uint8 Race;
    uint8 Sex;
    uint8 Data;                                                     // real ID to hair/facial hair
};

struct BattlePetBreedQualityEntry
{
    uint32 ID;
    float StateMultiplier;
    int8 QualityEnum;
};

struct BattlePetBreedStateEntry
{
    uint32 ID;
    int32 BattlePetStateID;
    uint16 Value;
    uint32 BattlePetBreedID;
};

struct BattlePetSpeciesEntry
{
    LocalizedString Description;
    LocalizedString SourceText;
    uint32 ID;
    int32 CreatureID;
    int32 SummonSpellID;
    int32 IconFileDataID;
    int8 PetTypeEnum;
    uint16 Flags;
    int8 SourceTypeEnum;
    int32 CardUIModelSceneID;
    int32 LoadoutUIModelSceneID;
    int32 CovenantID;

    EnumFlag<BattlePetSpeciesFlags> GetFlags() const { return static_cast<BattlePetSpeciesFlags>(Flags); }
};

struct BattlePetSpeciesStateEntry
{
    uint32 ID;
    uint16 BattlePetStateID;
    int32 Value;
    uint32 BattlePetSpeciesID;
};

struct BattlemasterListEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString GameType;
    LocalizedString ShortDescription;
    LocalizedString LongDescription;
    int8 InstanceType;
    int8 MinLevel;
    int8 MaxLevel;
    int8 RatedPlayers;
    int8 MinPlayers;
    int8 MaxPlayers;
    int8 GroupsAllowed;
    int8 MaxGroupSize;
    int16 HolidayWorldState;
    int32 Flags;
    int32 IconFileDataID;
    int32 RequiredPlayerConditionID;
    int16 MapID[16];

    EnumFlag<BattlemasterListFlags> GetFlags() const { return static_cast<BattlemasterListFlags>(Flags); }
};

#define MAX_BROADCAST_TEXT_EMOTES 3

struct BroadcastTextEntry
{
    LocalizedString Text;
    LocalizedString Text1;
    uint32 ID;
    int32 LanguageID;
    int32 ConditionID;
    uint16 EmotesID;
    uint8 Flags;
    uint32 ChatBubbleDurationMs;
    uint32 SoundKitID[2];
    uint16 EmoteID[MAX_BROADCAST_TEXT_EMOTES];
    uint16 EmoteDelay[MAX_BROADCAST_TEXT_EMOTES];
};

struct BroadcastTextDurationEntry
{
    uint32 ID;
    int32 BroadcastTextID;
    int32 Locale;
    int32 Duration;
};

struct Cfg_RegionsEntry
{
    uint32 ID;
    char const* Tag;
    uint16 RegionID;
    uint32 Raidorigin;                                              // Date of first raid reset, all other resets are calculated as this date plus interval
    uint8 RegionGroupMask;
    uint32 ChallengeOrigin;
};

struct CharTitlesEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Name1;
    int16 MaskID;
    int8 Flags;
};

struct CharacterLoadoutEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    int8 ChrClassID;
    int8 Purpose;
    int8 Unused910;

    bool IsForNewCharacter() const { return Purpose == 9; }
};

struct CharacterLoadoutItemEntry
{
    uint32 ID;
    uint16 CharacterLoadoutID;
    uint32 ItemID;
};

struct ChatChannelsEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Shortcut;
    int32 Flags;
    int8 FactionGroup;
    int32 Ruleset;
};

struct ChrClassUIDisplayEntry
{
    uint32 ID;
    uint8 ChrClassesID;
    uint32 AdvGuidePlayerConditionID;
    uint32 SplashPlayerConditionID;
};

struct ChrClassesEntry
{
    LocalizedString Name;
    char const* Filename;
    LocalizedString NameMale;
    LocalizedString NameFemale;
    char const* PetNameToken;
    LocalizedString Description;
    LocalizedString RoleInfoString;
    LocalizedString DisabledString;
    LocalizedString HyphenatedNameMale;
    LocalizedString HyphenatedNameFemale;
    uint32 ID;
    uint32 CreateScreenFileDataID;
    uint32 SelectScreenFileDataID;
    uint32 IconFileDataID;
    uint32 LowResScreenFileDataID;
    uint32 Flags;
    uint32 SpellTextureBlobFileDataID;
    uint32 RolesMask;
    uint32 ArmorTypeMask;
    int32 CharStartKitUnknown901;
    int32 MaleCharacterCreationVisualFallback;
    int32 MaleCharacterCreationIdleVisualFallback;
    int32 FemaleCharacterCreationVisualFallback;
    int32 FemaleCharacterCreationIdleVisualFallback;
    int32 CharacterCreationIdleGroundVisualFallback;
    int32 CharacterCreationGroundVisualFallback;
    int32 AlteredFormCharacterCreationIdleVisualFallback;
    int32 CharacterCreationAnimLoopWaitTimeMsFallback;
    uint16 CinematicSequenceID;
    uint16 DefaultSpec;
    uint8 PrimaryStatPriority;
    uint8 DisplayPower;
    uint8 RangedAttackPowerPerAgility;
    uint8 AttackPowerPerAgility;
    uint8 AttackPowerPerStrength;
    uint8 SpellClassSet;
    uint8 ClassColorR;
    uint8 ClassColorG;
    uint8 ClassColorB;
};

struct ChrClassesXPowerTypesEntry
{
    uint32 ID;
    int8 PowerType;
    uint32 ClassID;
};

struct ChrCustomizationChoiceEntry
{
    LocalizedString Name;
    uint32 ID;
    int32 ChrCustomizationOptionID;
    int32 ChrCustomizationReqID;
    uint16 SortOrder;
    uint16 UiOrderIndex;
    int32 Flags;
    int32 AddedInPatch;
    int32 SwatchColor[2];
};

struct ChrCustomizationDisplayInfoEntry
{
    uint32 ID;
    int32 ShapeshiftFormID;
    int32 DisplayID;
    float BarberShopMinCameraDistance;
    float BarberShopHeightOffset;
};

struct ChrCustomizationElementEntry
{
    uint32 ID;
    int32 ChrCustomizationChoiceID;
    int32 RelatedChrCustomizationChoiceID;
    int32 ChrCustomizationGeosetID;
    int32 ChrCustomizationSkinnedModelID;
    int32 ChrCustomizationMaterialID;
    int32 ChrCustomizationBoneSetID;
    int32 ChrCustomizationCondModelID;
    int32 ChrCustomizationDisplayInfoID;
    int32 ChrCustItemGeoModifyID;
};

struct ChrCustomizationOptionEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 SecondaryID;
    int32 Flags;
    int32 ChrModelID;
    int32 SortIndex;
    int32 ChrCustomizationCategoryID;
    int32 OptionType;
    float BarberShopCostModifier;
    int32 ChrCustomizationID;
    int32 ChrCustomizationReqID;
    int32 UiOrderIndex;
    int32 AddedInPatch;
};

struct ChrCustomizationReqEntry
{
    uint32 ID;
    int32 Flags;
    int32 ClassMask;
    int32 AchievementID;
    int32 OverrideArchive;                                          // -1: allow any, otherwise must match OverrideArchive cvar
    int32 ItemModifiedAppearanceID;

    EnumFlag<ChrCustomizationReqFlag> GetFlags() const { return static_cast<ChrCustomizationReqFlag>(Flags); }
};

struct ChrCustomizationReqChoiceEntry
{
    uint32 ID;
    int32 ChrCustomizationChoiceID;
    uint32 ChrCustomizationReqID;
};

struct ChrModelEntry
{
    float FaceCustomizationOffset[3];
    float CustomizeOffset[3];
    uint32 ID;
    int32 Sex;
    int32 DisplayID;
    int32 CharComponentTextureLayoutID;
    int32 Flags;
    int32 SkeletonFileDataID;
    int32 ModelFallbackChrModelID;
    int32 TextureFallbackChrModelID;
    int32 HelmVisFallbackChrModelID;
    float CustomizeScale;
    float CustomizeFacing;
    float CameraDistanceOffset;
    float BarberShopCameraOffsetScale;
    float BarberShopCameraHeightOffsetScale; // applied after BarberShopCameraOffsetScale
    float BarberShopCameraRotationOffset;
};

struct ChrRaceXChrModelEntry
{
    uint32 ID;
    int32 ChrRacesID;
    int32 ChrModelID;
};

struct ChrRacesEntry
{
    uint32 ID;
    char const* ClientPrefix;
    char const* ClientFileString;
    LocalizedString Name;
    LocalizedString NameFemale;
    LocalizedString NameLowercase;
    LocalizedString NameFemaleLowercase;
    LocalizedString LoreName;
    LocalizedString LoreNameFemale;
    LocalizedString LoreNameLower;
    LocalizedString LoreNameLowerFemale;
    LocalizedString LoreDescription;
    LocalizedString ShortName;
    LocalizedString ShortNameFemale;
    LocalizedString ShortNameLower;
    LocalizedString ShortNameLowerFemale;
    int32 Flags;
    int32 FactionID;
    int32 CinematicSequenceID;
    int32 ResSicknessSpellID;
    int32 SplashSoundID;
    int32 Alliance;
    int32 RaceRelated;
    int32 UnalteredVisualRaceID;
    int32 DefaultClassID;
    int32 CreateScreenFileDataID;
    int32 SelectScreenFileDataID;
    int32 NeutralRaceID;
    int32 LowResScreenFileDataID;
    int32 AlteredFormStartVisualKitID[3];
    int32 AlteredFormFinishVisualKitID[3];
    int32 HeritageArmorAchievementID;
    int32 StartingLevel;
    int32 UiDisplayOrder;
    int32 MaleModelFallbackRaceID;
    int32 FemaleModelFallbackRaceID;
    int32 MaleTextureFallbackRaceID;
    int32 FemaleTextureFallbackRaceID;
    int32 PlayableRaceBit;
    int32 HelmetAnimScalingRaceID;
    int32 TransmogrifyDisabledSlotMask;
    int32 UnalteredVisualCustomizationRaceID;
    float AlteredFormCustomizeOffsetFallback[3];
    float AlteredFormCustomizeRotationFallback;
    float Unknown910_1[3];
    float Unknown910_2[3];
    int8 BaseLanguage;
    int8 CreatureType;
    int8 MaleModelFallbackSex;
    int8 FemaleModelFallbackSex;
    int8 MaleTextureFallbackSex;
    int8 FemaleTextureFallbackSex;

    EnumFlag<ChrRacesFlag> GetFlags() const { return static_cast<ChrRacesFlag>(Flags); }
};

#define MAX_MASTERY_SPELLS 2

struct ChrSpecializationEntry
{
    LocalizedString Name;
    LocalizedString FemaleName;
    LocalizedString Description;
    uint32 ID;
    int8 ClassID;
    int8 OrderIndex;
    int8 PetTalentType;
    int8 Role;
    uint32 Flags;
    int32 SpellIconFileID;
    int8 PrimaryStatPriority;
    int32 AnimReplacements;
    int32 MasterySpellID[MAX_MASTERY_SPELLS];

    bool IsPetSpecialization() const
    {
        return ClassID == 0;
    }
};

struct CinematicCameraEntry
{
    uint32 ID;
    DBCPosition3D Origin;                                   // Position in map used for basis for M2 co-ordinates
    uint32 SoundID;                                         // Sound ID       (voiceover for cinematic)
    float OriginFacing;                                     // Orientation in map used for basis for M2 co
    uint32 FileDataID;                                      // Model
    int32 Unknown915;
};

struct CinematicSequencesEntry
{
    uint32 ID;
    uint32 SoundID;
    uint16 Camera[8];
};

struct ContentTuningEntry
{
    uint32 ID;
    int32 Flags;
    int32 ExpansionID;
    int32 MinLevel;
    int32 MaxLevel;
    int32 MinLevelType;
    int32 MaxLevelType;
    int32 TargetLevelDelta;
    int32 TargetLevelMaxDelta;
    int32 TargetLevelMin;
    int32 TargetLevelMax;
    int32 MinItemLevel;

    EnumFlag<ContentTuningFlag> GetFlags() const { return static_cast<ContentTuningFlag>(Flags); }

    int32 GetScalingFactionGroup() const
    {
        EnumFlag<ContentTuningFlag> flags = GetFlags();
        if (flags.HasFlag(ContentTuningFlag::Horde))
            return 5;

        if (flags.HasFlag(ContentTuningFlag::Alliance))
            return 3;

        return 0;
    }
};

struct ContentTuningXExpectedEntry
{
    uint32 ID;
    int32 ExpectedStatModID;
    int32 MinMythicPlusSeasonID;
    int32 MaxMythicPlusSeasonID;
    uint32 ContentTuningID;
};

struct ConversationLineEntry
{
    uint32 ID;
    uint32 BroadcastTextID;
    uint32 SpellVisualKitID;
    int32 AdditionalDuration;
    uint16 NextConversationLineID;
    uint16 AnimKitID;
    uint8 SpeechType;
    uint8 StartAnimation;
    uint8 EndAnimation;
};

struct CorruptionEffectsEntry
{
    uint32 ID;
    float MinCorruption;
    int32 Aura;
    int32 PlayerConditionID;
    int32 Flags;
};

//struct CreatureDifficultyEntry
//{
//    uint32 ID;
//    int32 LevelDeltaMin;
//    int32 LevelDeltaMax;
//    uint16 FactionID;
//    int32 ContentTuningID;
//    int32 Flags[8];
//    uint32 CreatureID;
//};

struct CreatureDisplayInfoEntry
{
    uint32 ID;
    uint16 ModelID;
    uint16 SoundID;
    int8 SizeClass;
    float CreatureModelScale;
    uint8 CreatureModelAlpha;
    uint8 BloodID;
    int32 ExtendedDisplayInfoID;
    uint16 NPCSoundID;
    uint16 ParticleColorID;
    int32 PortraitCreatureDisplayInfoID;
    int32 PortraitTextureFileDataID;
    uint16 ObjectEffectPackageID;
    uint16 AnimReplacementSetID;
    uint8 Flags;
    int32 StateSpellVisualKitID;
    float PlayerOverrideScale;
    float PetInstanceScale;                                         // scale of not own player pets inside dungeons/raids/scenarios
    int8 UnarmedWeaponType;
    int32 MountPoofSpellVisualKitID;
    int32 DissolveEffectID;
    int8 Gender;
    int32 DissolveOutEffectID;
    int8 CreatureModelMinLod;
    int32 TextureVariationFileDataID[3];
};

struct CreatureDisplayInfoExtraEntry
{
    uint32 ID;
    int8 DisplayRaceID;
    int8 DisplaySexID;
    int8 DisplayClassID;
    int8 Flags;
    int32 BakeMaterialResourcesID;
    int32 HDBakeMaterialResourcesID;
};

struct CreatureFamilyEntry
{
    uint32 ID;
    LocalizedString Name;
    float MinScale;
    int8 MinScaleLevel;
    float MaxScale;
    int8 MaxScaleLevel;
    int16 PetFoodMask;
    int8 PetTalentType;
    int32 IconFileID;
    int16 SkillLine[2];
};

struct CreatureModelDataEntry
{
    uint32 ID;
    float GeoBox[6];
    uint32 Flags;
    uint32 FileDataID;
    uint32 BloodID;
    uint32 FootprintTextureID;
    float FootprintTextureLength;
    float FootprintTextureWidth;
    float FootprintParticleScale;
    uint32 FoleyMaterialID;
    uint32 FootstepCameraEffectID;
    uint32 DeathThudCameraEffectID;
    uint32 SoundID;
    uint32 SizeClass;
    float CollisionWidth;
    float CollisionHeight;
    float WorldEffectScale;
    uint32 CreatureGeosetDataID;
    float HoverHeight;
    float AttachedEffectScale;
    float ModelScale;
    float MissileCollisionRadius;
    float MissileCollisionPush;
    float MissileCollisionRaise;
    float MountHeight;
    float OverrideLootEffectScale;
    float OverrideNameScale;
    float OverrideSelectionRadius;
    float TamedPetBaseScale;
    int8 Unknown820_1;                                              // scale related
    float Unknown820_2;                                             // scale related
    float Unknown820_3[2];                                          // scale related
};

struct CreatureTypeEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 Flags;
};

struct CriteriaEntry
{
    uint32 ID;
    int16 Type;
    union AssetNameAlias
    {
        int32 ID;
        // CriteriaType::KillCreature                               = 0
        // CriteriaType::KilledByCreature                           = 20
        // CriteriaType::AccountKnownPet                            = 96
        // CriteriaType::KillCreatureScenario                       = 208
        int32 CreatureID;

        // CriteriaType::WinBattleground                            = 1
        // CriteriaType::ParticipateInBattleground                  = 15
        // CriteriaType::DieOnMap                                   = 16
        // CriteriaType::WinArena                                   = 32
        // CriteriaType::ParticipateInArena                         = 33
        // CriteriaType::CompleteChallengeMode                      = 71
        int32 MapID;

        // CriteriaType::CompleteResearchProject                    = 2
        int32 ResearchProjectID;

        // CriteriaType::FindResearchObject                         = 4
        // CriteriaType::UseGameobject                              = 68
        // CriteriaType::CatchFishInFishingHole                     = 72
        int32 GameObjectID;

        // CriteriaType::SkillRaised                                = 7
        // CriteriaType::AchieveSkillStep                           = 40
        // CriteriaType::LearnSpellFromSkillLine                    = 75
        // CriteriaType::LearnTradeskillSkillLine                   = 112
        int32 SkillID;

        // CriteriaType::EarnAchievement                            = 8
        int32 AchievementID;

        // CriteriaType::CompleteQuestsInZone                       = 11
        int32 ZoneID;

        // CriteriaType::CurrencyGained                             = 12
        // CriteriaType::ObtainAnyItemWithCurrencyValue             = 229
        int32 CurrencyID;

        // CriteriaType::DieInInstance                              = 18
        // CriteriaType::RunInstance                                = 19
        int32 GroupSize;

        // CriteriaType::CompleteInternalCriteria                   = 21
        int32 CriteriaID;

        // CriteriaType::DieFromEnviromentalDamage                  = 26
        int32 EnviromentalDamageType;

        // CriteriaType::CompleteQuest                              = 27
        int32 QuestID;

        // CriteriaType::BeSpellTarget                              = 28
        // CriteriaType::CastSpell                                  = 29
        // CriteriaType::LearnOrKnowSpell                           = 34
        // CriteriaType::GainAura                                   = 69
        // CriteriaType::LandTargetedSpellOnTarget                  = 110
        // CriteriaType::MemorizeSpell                              = 222
        int32 SpellID;

        // CriteriaType::TrackedWorldStateUIModified                = 30
        int32 WorldStateUIID;

        // CriteriaType::PVPKillInArea                              = 31
        // CriteriaType::EnterArea                                  = 163
        // CriteriaType::LeaveArea                                  = 164
        // CriteriaType::EnterTopLevelArea                          = 225
        // CriteriaType::LeaveTopLevelArea                          = 226
        int32 AreaID;

        // CriteriaType::AcquireItem                                = 36
        // CriteriaType::UseItem                                    = 41
        // CriteriaType::LootItem                                   = 42
        // CriteriaType::EquipItem                                  = 57
        // CriteriaType::LearnToy                                   = 185
        // CriteriaType::LearnHeirloom                              = 188
        int32 ItemID;

        // CriteriaType::EarnTeamArenaRating                        = 38
        // CriteriaType::EarnPersonalArenaRating                    = 39
        int32 TeamType;

        // CriteriaType::RevealWorldMapOverlay                      = 43
        int32 WorldMapOverlayID;

        // CriteriaType::ReputationGained                           = 46
        // CriteriaType::ParagonLevelIncreaseWithFaction            = 206
        int32 FactionID;

        // CriteriaType::EquipItemInSlot                            = 49
        // CriteriaType::LearnAnyTransmogInSlot                     = 199
        int32 EquipmentSlot;

        // CriteriaType::RollNeed                                   = 50
        // CriteriaType::RollGreed                                  = 51
        // CriteriaType::RollDisenchant                             = 116
        int32 RollValue;

        // CriteriaType::DeliverKillingBlowToClass                  = 52
        int32 ClassID;

        // CriteriaType::DeliverKillingBlowToRace                   = 53
        int32 RaceID;

        // CriteriaType::DoEmote                                    = 54
        int32 EmoteID;

        // CriteriaType::CompleteQuestsInSort                       = 58
        int32 QuestSortID;

        // CriteriaType::KilledAllUnitsInSpawnRegion                = 64
        int32 SpawnRegionID;

        // CriteriaType::PlayerTriggerGameEvent                     = 73
        // CriteriaType::AnyoneTriggerGameEventScenario             = 92
        int32 EventID;

        // CriteriaType::DefeatDungeonEncounterWhileElegibleForLoot = 97
        // CriteriaType::DefeatDungeonEncounter                     = 165
        int32 DungeonEncounterID;

        // CriteriaType::GetLootByType                              = 109
        int32 LootType;

        // CriteriaType::CompleteGuildChallenge                     = 138
        int32 GuildChallengeType;

        // CriteriaType::CompleteScenario                           = 152
        int32 ScenarioID;

        // CriteriaType::EnterAreaTriggerWithActionSet              = 153
        // CriteriaType::LeaveAreaTriggerWithActionSet              = 154
        int32 AreaTriggerActionSetID;

        // CriteriaType::BattlePetReachLevel                        = 160
        // CriteriaType::ActivelyEarnPetLevel                       = 162
        int32 PetLevel;

        // CriteriaType::PlaceGarrisonBuilding                      = 167
        // CriteriaType::ActivateGarrisonBuilding                   = 169
        // CriteriaType::LearnGarrisonBlueprint                     = 179
        int32 GarrBuildingID;

        // CriteriaType::UpgradeGarrison                            = 170
        int32 GarrisonLevel;

        // CriteriaType::StartAnyGarrisonMissionWithFollowerType    = 171
        // CriteriaType::SucceedAnyGarrisonMissionWithFollowerType  = 173
        int32 GarrFollowerTypeID;

        // CriteriaType::StartGarrisonMission                       = 172
        // CriteriaType::SucceedGarrisonMission                     = 174
        int32 GarrMissionID;

        // CriteriaType::RecruitGarrisonFollower                    = 176
        int32 GarrFollowerID;

        // CriteriaType::LearnGarrisonSpecialization                = 181
        int32 GarrSpecializationID;

        // CriteriaType::CollectGarrisonShipment                    = 182
        int32 CharShipmentContainerID;

        // CriteriaType::LearnTransmog                              = 192
        int32 ItemModifiedAppearanceID;

        // CriteriaType::ActivelyReachLevel                         = 196
        int32 PlayerLevel;

        // CriteriaType::CompleteResearchGarrisonTalent             = 198
        // CriteriaType::StartResearchGarrisonTalent                = 202
        // CriteriaType::SocketGarrisonTalent                       = 227
        int32 GarrTalentID;

        // CriteriaType::EarnLicense                                = 204
        int32 BattlePayDeliverableID;

        // CriteriaType::CollectTransmogSetFromGroup                = 205
        int32 TransmogSetGroupID;

        // CriteriaType::ArtifactPowerRankPurchased                 = 209
        // CriteriaType::ChooseRelicTalent                          = 211
        int32 ArtifactPowerID;

        // CriteriaType::EarnExpansionLevel                         = 212
        int32 ExpansionLevel;

        // CriteriaType::AccountHonorLevelReached                   = 213
        int32 AccountHonorLevel;

        // CriteriaType::AzeriteLevelReached                        = 215
        int32 AzeriteLevel;

        // CriteriaType::MythicPlusRatingAttained                   = 230
        int32 DungeonScore;
    } Asset;
    uint32 ModifierTreeId;
    uint8 StartEvent;
    int32 StartAsset;
    uint16 StartTimer;
    uint8 FailEvent;
    int32 FailAsset;
    uint8 Flags;
    int16 EligibilityWorldStateID;
    int8 EligibilityWorldStateValue;
};

struct CriteriaTreeEntry
{
    uint32 ID;
    LocalizedString Description;
    uint32 Parent;
    uint32 Amount;
    int8 Operator;
    uint32 CriteriaID;
    int32 OrderIndex;
    int32 Flags;

    EnumFlag<CriteriaTreeFlags> GetFlags() const { return static_cast<CriteriaTreeFlags>(Flags); }
};

struct CurrencyContainerEntry
{
    uint32 ID;
    LocalizedString ContainerName;
    LocalizedString ContainerDescription;
    int32 MinAmount;
    int32 MaxAmount;
    int32 ContainerIconID;
    int32 ContainerQuality;
    int32 OnLootSpellVisualKitID;
    uint32 CurrencyTypesID;
};

struct CurrencyTypesEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    int32 CategoryID;
    int32 InventoryIconFileID;
    uint32 SpellWeight;
    uint8 SpellCategory;
    uint32 MaxQty;
    uint32 MaxEarnablePerWeek;
    int8 Quality;
    int32 FactionID;
    int32 ItemGroupSoundsID;
    int32 XpQuestDifficulty;
    int32 AwardConditionID;
    int32 MaxQtyWorldStateID;
    int32 Flags[2];
};

struct CurveEntry
{
    uint32 ID;
    uint8 Type;
    uint8 Flags;
};

struct CurvePointEntry
{
    uint32 ID;
    DBCPosition2D Pos;
    DBCPosition2D PosPreSquish;
    uint16 CurveID;
    uint8 OrderIndex;
};

struct DestructibleModelDataEntry
{
    uint32 ID;
    int8 State0ImpactEffectDoodadSet;
    uint8 State0AmbientDoodadSet;
    int32 State1Wmo;
    int8 State1DestructionDoodadSet;
    int8 State1ImpactEffectDoodadSet;
    uint8 State1AmbientDoodadSet;
    int32 State2Wmo;
    int8 State2DestructionDoodadSet;
    int8 State2ImpactEffectDoodadSet;
    uint8 State2AmbientDoodadSet;
    int32 State3Wmo;
    uint8 State3InitDoodadSet;
    uint8 State3AmbientDoodadSet;
    uint8 EjectDirection;
    uint8 DoNotHighlight;
    int32 State0Wmo;
    uint8 HealEffect;
    uint16 HealEffectSpeed;
    int8 State0NameSet;
    int8 State1NameSet;
    int8 State2NameSet;
    int8 State3NameSet;
};

struct DifficultyEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 InstanceType;
    uint8 OrderIndex;
    int8 OldEnumValue;
    uint8 FallbackDifficultyID;
    uint8 MinPlayers;
    uint8 MaxPlayers;
    uint16 Flags;
    uint8 ItemContext;
    uint8 ToggleDifficultyID;
    uint16 GroupSizeHealthCurveID;
    uint16 GroupSizeDmgCurveID;
    uint16 GroupSizeSpellPointsCurveID;
};

struct DungeonEncounterEntry
{
    LocalizedString Name;
    uint32 ID;
    int16 MapID;
    int32 DifficultyID;
    int32 OrderIndex;
    int32 CompleteWorldStateID;
    int8 Bit;
    int32 CreatureDisplayID;
    int32 Flags;
    int32 SpellIconFileID;
    int32 Faction;
};

struct DurabilityCostsEntry
{
    uint32 ID;
    uint16 WeaponSubClassCost[21];
    uint16 ArmorSubClassCost[8];
};

struct DurabilityQualityEntry
{
    uint32 ID;
    float Data;
};

struct EmotesEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    char const* EmoteSlashCommand;
    int32 AnimID;
    uint32 EmoteFlags;
    uint8 EmoteSpecProc;
    uint32 EmoteSpecProcParam;
    uint32 EventSoundID;
    uint32 SpellVisualKitID;
    int32 ClassMask;
};

struct EmotesTextEntry
{
    uint32 ID;
    char const* Name;
    uint16 EmoteID;
};

struct EmotesTextSoundEntry
{
    uint32 ID;
    uint8 RaceID;
    uint8 ClassID;
    uint8 SexID;
    uint32 SoundID;
    uint32 EmotesTextID;
};

struct ExpectedStatEntry
{
    uint32 ID;
    int32 ExpansionID;
    float CreatureHealth;
    float PlayerHealth;
    float CreatureAutoAttackDps;
    float CreatureArmor;
    float PlayerMana;
    float PlayerPrimaryStat;
    float PlayerSecondaryStat;
    float ArmorConstant;
    float CreatureSpellDamage;
    uint32 Lvl;
};

struct ExpectedStatModEntry
{
    uint32 ID;
    float CreatureHealthMod;
    float PlayerHealthMod;
    float CreatureAutoAttackDPSMod;
    float CreatureArmorMod;
    float PlayerManaMod;
    float PlayerPrimaryStatMod;
    float PlayerSecondaryStatMod;
    float ArmorConstantMod;
    float CreatureSpellDamageMod;
};

struct FactionEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> ReputationRaceMask[4];
    LocalizedString Name;
    LocalizedString Description;
    int16 ReputationIndex;
    uint16 ParentFactionID;
    uint8 Expansion;
    uint32 FriendshipRepID;
    uint8 Flags;
    uint16 ParagonFactionID;
    int16 ReputationClassMask[4];
    uint16 ReputationFlags[4];
    int32 ReputationBase[4];
    int32 ReputationMax[4];
    float ParentFactionMod[2];                        // Faction outputs rep * ParentFactionModOut as spillover reputation
    uint8 ParentFactionCap[2];                        // The highest rank the faction will profit from incoming spillover

    // helpers
    bool CanHaveReputation() const
    {
        return ReputationIndex >= 0;
    }
};

#define MAX_FACTION_RELATIONS 4

struct FactionTemplateEntry
{
    uint32 ID;
    uint16 Faction;
    uint16 Flags;
    uint8 FactionGroup;
    uint8 FriendGroup;
    uint8 EnemyGroup;
    uint16 Enemies[MAX_FACTION_RELATIONS];
    uint16 Friend[MAX_FACTION_RELATIONS];

    //-------------------------------------------------------  end structure

    // helpers
    bool IsFriendlyTo(FactionTemplateEntry const* entry) const
    {
        if (this == entry)
            return true;
        if (entry->Faction)
        {
            for (int32 i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Enemies[i] == entry->Faction)
                    return false;
            for (int32 i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Friend[i] == entry->Faction)
                    return true;
        }
        return (FriendGroup & entry->FactionGroup) || (FactionGroup & entry->FriendGroup);
    }
    bool IsHostileTo(FactionTemplateEntry const* entry) const
    {
        if (this == entry)
            return false;
        if (entry->Faction)
        {
            for (int32 i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Enemies[i] == entry->Faction)
                    return true;
            for (int32 i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Friend[i] == entry->Faction)
                    return false;
        }
        return (EnemyGroup & entry->FactionGroup) != 0;
    }
    bool IsHostileToPlayers() const { return (EnemyGroup & FACTION_MASK_PLAYER) !=0; }
    bool IsNeutralToAll() const
    {
        for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
            if (Enemies[i] != 0)
                return false;
        return EnemyGroup == 0 && FriendGroup == 0;
    }
    bool IsContestedGuardFaction() const { return (Flags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD) != 0; }
};

struct FriendshipRepReactionEntry
{
    uint32 ID;
    LocalizedString Reaction;
    uint32 FriendshipRepID;
    uint16 ReactionThreshold;
    int32 OverrideColor;
};

struct FriendshipReputationEntry
{
    LocalizedString Description;
    LocalizedString StandingModified;
    LocalizedString StandingChanged;
    uint32 ID;
    int32 FactionID;
    int32 TextureFileID;
    int32 Flags;

    EnumFlag<FriendshipReputationFlags> GetFlags() const { return static_cast<FriendshipReputationFlags>(Flags); }
};

struct GameObjectDisplayInfoEntry
{
    uint32 ID;
    DBCPosition3D GeoBoxMin;
    DBCPosition3D GeoBoxMax;
    int32 FileDataID;
    int16 ObjectEffectPackageID;
    float OverrideLootEffectScale;
    float OverrideNameScale;
};

struct GameObjectsEntry
{
    LocalizedString Name;
    DBCPosition3D Pos;
    float Rot[4];
    uint32 ID;
    int32 OwnerID;
    int32 DisplayID;
    float Scale;
    int32 TypeID;
    int32 PhaseUseFlags;
    int32 PhaseID;
    int32 PhaseGroupID;
    int32 PropValue[8];
};

struct GarrAbilityEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    uint8 GarrAbilityCategoryID;
    int8 GarrFollowerTypeID;
    int32 IconFileDataID;
    uint16 FactionChangeGarrAbilityID;
    int32 Flags;
};

struct GarrBuildingEntry
{
    uint32 ID;
    LocalizedString HordeName;
    LocalizedString AllianceName;
    LocalizedString Description;
    LocalizedString Tooltip;
    uint8 GarrTypeID;
    int8 BuildingType;
    int32 HordeGameObjectID;
    int32 AllianceGameObjectID;
    int32 GarrSiteID;
    uint8 UpgradeLevel;
    int32 BuildSeconds;
    uint16 CurrencyTypeID;
    int32 CurrencyQty;
    uint16 HordeUiTextureKitID;
    uint16 AllianceUiTextureKitID;
    int32 IconFileDataID;
    uint16 AllianceSceneScriptPackageID;
    uint16 HordeSceneScriptPackageID;
    int32 MaxAssignments;
    uint8 ShipmentCapacity;
    uint16 GarrAbilityID;
    uint16 BonusGarrAbilityID;
    uint16 GoldCost;
    int32 Flags;
};

struct GarrBuildingPlotInstEntry
{
    DBCPosition2D MapOffset;
    uint32 ID;
    uint8 GarrBuildingID;
    uint16 GarrSiteLevelPlotInstID;
    uint16 UiTextureAtlasMemberID;
};

struct GarrClassSpecEntry
{
    uint32 ID;
    LocalizedString ClassSpec;
    LocalizedString ClassSpecMale;
    LocalizedString ClassSpecFemale;
    uint16 UiTextureAtlasMemberID;
    uint16 GarrFollItemSetID;
    uint8 FollowerClassLimit;
    int32 Flags;
};

struct GarrFollowerEntry
{
    uint32 ID;
    LocalizedString HordeSourceText;
    LocalizedString AllianceSourceText;
    LocalizedString TitleName;
    uint8 GarrTypeID;
    int8 GarrFollowerTypeID;
    int32 HordeCreatureID;
    int32 AllianceCreatureID;
    uint8 HordeGarrFollRaceID;
    uint8 AllianceGarrFollRaceID;
    int32 HordeGarrClassSpecID;
    int32 AllianceGarrClassSpecID;
    int8 Quality;
    uint8 FollowerLevel;
    uint16 ItemLevelWeapon;
    uint16 ItemLevelArmor;
    int8 HordeSourceTypeEnum;
    int8 AllianceSourceTypeEnum;
    int32 HordeIconFileDataID;
    int32 AllianceIconFileDataID;
    uint16 HordeGarrFollItemSetID;
    uint16 AllianceGarrFollItemSetID;
    uint16 HordeUITextureKitID;
    uint16 AllianceUITextureKitID;
    uint8 Vitality;
    uint8 HordeFlavorGarrStringID;
    uint8 AllianceFlavorGarrStringID;
    uint32 HordeSlottingBroadcastTextID;
    uint32 AllySlottingBroadcastTextID;
    uint8 ChrClassID;
    int32 Flags;
    uint8 Gender;
    int32 AutoCombatantID;
    int32 CovenantID;
};

struct GarrFollowerXAbilityEntry
{
    uint32 ID;
    uint8 OrderIndex;
    uint8 FactionIndex;
    uint16 GarrAbilityID;
    uint32 GarrFollowerID;
};

struct GarrMissionEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Location;
    LocalizedString Description;
    DBCPosition2D MapPos;
    DBCPosition2D WorldPos;
    uint8 GarrTypeID;
    uint8 GarrMissionTypeID;
    int8 GarrFollowerTypeID;
    uint8 MaxFollowers;
    uint32 MissionCost;
    uint16 MissionCostCurrencyTypesID;
    uint8 OfferedGarrMissionTextureID;
    uint16 UiTextureKitID;
    uint32 EnvGarrMechanicID;
    int32 EnvGarrMechanicTypeID;
    uint32 PlayerConditionID;
    int32 GarrMissionSetID;
    int8 TargetLevel;
    uint16 TargetItemLevel;
    int32 MissionDuration;
    int32 TravelDuration;
    uint32 OfferDuration;
    uint8 BaseCompletionChance;
    uint32 BaseFollowerXP;
    uint32 OvermaxRewardPackID;
    uint8 FollowerDeathChance;
    uint32 AreaID;
    int32 Flags;
    float AutoMissionScalar;
    int32 AutoMissionScalarCurveID;
    int32 AutoCombatantEnvCasterID;
};

struct GarrPlotEntry
{
    uint32 ID;
    char const* Name;
    uint8 PlotType;
    int32 HordeConstructObjID;
    int32 AllianceConstructObjID;
    uint8 Flags;
    uint8 UiCategoryID;
    uint32 UpgradeRequirement[2];
};

struct GarrPlotBuildingEntry
{
    uint32 ID;
    uint8 GarrPlotID;
    uint8 GarrBuildingID;
};

struct GarrPlotInstanceEntry
{
    uint32 ID;
    char const* Name;
    uint8 GarrPlotID;
};

struct GarrSiteLevelEntry
{
    uint32 ID;
    DBCPosition2D TownHallUiPos;
    uint32 GarrSiteID;
    uint8 GarrLevel;
    uint16 MapID;
    uint16 UpgradeMovieID;
    uint16 UiTextureKitID;
    uint8 MaxBuildingLevel;
    uint16 UpgradeCost;
    uint16 UpgradeGoldCost;
};

struct GarrSiteLevelPlotInstEntry
{
    uint32 ID;
    DBCPosition2D UiMarkerPos;
    uint16 GarrSiteLevelID;
    uint8 GarrPlotInstanceID;
    uint8 UiMarkerSize;
};

struct GemPropertiesEntry
{
    uint32 ID;
    uint16 EnchantId;
    int32 Type;
};

struct GlobalCurveEntry
{
    uint32 ID;
    int32 CurveID;
    int32 Type;
};

struct GlyphBindableSpellEntry
{
    uint32 ID;
    int32 SpellID;
    uint32 GlyphPropertiesID;
};

struct GlyphPropertiesEntry
{
    uint32 ID;
    uint32 SpellID;
    uint8 GlyphType;
    uint8 GlyphExclusiveCategoryID;
    int32 SpellIconFileDataID;
};

struct GlyphRequiredSpecEntry
{
    uint32 ID;
    uint16 ChrSpecializationID;
    uint32 GlyphPropertiesID;
};

struct GuildColorBackgroundEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Blue;
    uint8 Green;
};

struct GuildColorBorderEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Blue;
    uint8 Green;
};

struct GuildColorEmblemEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Blue;
    uint8 Green;
};

struct GuildPerkSpellsEntry
{
    uint32 ID;
    int32 SpellID;
};

struct HeirloomEntry
{
    LocalizedString SourceText;
    uint32 ID;
    int32 ItemID;
    int32 LegacyUpgradedItemID;
    int32 StaticUpgradedItemID;
    int8 SourceTypeEnum;
    uint8 Flags;
    int32 LegacyItemID;
    int32 UpgradeItemID[6];
    uint16 UpgradeItemBonusListID[6];
};

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 26
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32 ID;
    uint16 Region;
    uint8 Looping;
    uint32 HolidayNameID;
    uint32 HolidayDescriptionID;
    uint8 Priority;
    int8 CalendarFilterType;
    uint8 Flags;
    uint16 Duration[MAX_HOLIDAY_DURATIONS];
    uint32 Date[MAX_HOLIDAY_DATES];                                 // dates in unix time starting at January, 1, 2000
    uint8 CalendarFlags[MAX_HOLIDAY_DURATIONS];
    int32 TextureFileDataID[3];
};

struct ImportPriceArmorEntry
{
    uint32 ID;
    float ClothModifier;
    float LeatherModifier;
    float ChainModifier;
    float PlateModifier;
};

struct ImportPriceQualityEntry
{
    uint32 ID;
    float Data;
};

struct ImportPriceShieldEntry
{
    uint32 ID;
    float Data;
};

struct ImportPriceWeaponEntry
{
    uint32 ID;
    float Data;
};

struct ItemEntry
{
    uint32 ID;
    uint8 ClassID;
    uint8 SubclassID;
    uint8 Material;
    int8 InventoryType;
    uint8 SheatheType;
    int8 SoundOverrideSubclassID;
    int32 IconFileDataID;
    uint8 ItemGroupSoundsID;
    int32 ContentTuningID;
    int32 ModifiedCraftingReagentItemID;
};

struct ItemAppearanceEntry
{
    uint32 ID;
    int32 DisplayType;
    int32 ItemDisplayInfoID;
    int32 DefaultIconFileDataID;
    int32 UiOrder;
    int32 PlayerConditionID;
};

struct ItemArmorQualityEntry
{
    uint32 ID;
    float Qualitymod[7];
};

struct ItemArmorShieldEntry
{
    uint32 ID;
    float Quality[7];
    uint16 ItemLevel;
};

struct ItemArmorTotalEntry
{
    uint32 ID;
    int16 ItemLevel;
    float Cloth;
    float Leather;
    float Mail;
    float Plate;
};

struct ItemBagFamilyEntry
{
    uint32 ID;
    LocalizedString Name;
};

struct ItemBonusEntry
{
    uint32 ID;
    int32 Value[4];
    uint16 ParentItemBonusListID;
    uint8 Type;
    uint8 OrderIndex;
};

// new item upgrade system
//struct ItemBonusListGroupEntryEntry
//{
//    uint32 ID;
//    int32 ItemBonusListGroupID;
//    int32 ItemBonusListID;
//    int32 ItemLevelSelectorID;
//    int32 OrderIndex;
//    int32 ItemExtendedCostID;
//    int32 PlayerConditionID;
//};

struct ItemBonusListLevelDeltaEntry
{
    int16 ItemLevelDelta;
    uint32 ID;
};

//struct ItemBonusSequenceSpellEntry
//{
//    uint32 ID;
//    int32 SpellID;
//    int32 ItemID;
//};

struct ItemBonusTreeNodeEntry
{
    uint32 ID;
    uint8 ItemContext;
    uint16 ChildItemBonusTreeID;
    uint16 ChildItemBonusListID;
    uint16 ChildItemLevelSelectorID;
    int32 ItemBonusListGroupID;
    int32 ParentItemBonusTreeNodeID;
    uint32 ParentItemBonusTreeID;
};

struct ItemChildEquipmentEntry
{
    uint32 ID;
    int32 ParentItemID;
    int32 ChildItemID;
    uint8 ChildItemEquipSlot;
};

struct ItemClassEntry
{
    uint32 ID;
    LocalizedString ClassName;
    int8 ClassID;
    float PriceModifier;
    uint8 Flags;
};

struct ItemCurrencyCostEntry
{
    uint32 ID;
    int32 ItemID;
};

struct ItemDamageAmmoEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Quality[7];
};

struct ItemDamageOneHandEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Quality[7];
};

struct ItemDamageOneHandCasterEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Quality[7];
};

struct ItemDamageTwoHandEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Quality[7];
};

struct ItemDamageTwoHandCasterEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Quality[7];
};

struct ItemDisenchantLootEntry
{
    uint32 ID;
    int8 Subclass;
    uint8 Quality;
    uint16 MinLevel;
    uint16 MaxLevel;
    uint16 SkillRequired;
    int8 ExpansionID;
    uint32 Class;
};

struct ItemEffectEntry
{
    uint32 ID;
    uint8 LegacySlotIndex;
    int8 TriggerType;
    int16 Charges;
    int32 CoolDownMSec;
    int32 CategoryCoolDownMSec;
    uint16 SpellCategoryID;
    int32 SpellID;
    uint16 ChrSpecializationID;
};

#define MAX_ITEM_EXT_COST_ITEMS         5
#define MAX_ITEM_EXT_COST_CURRENCIES    5

struct ItemExtendedCostEntry
{
    uint32 ID;
    uint16 RequiredArenaRating;
    int8 ArenaBracket;                                             // arena slot restrictions (min slot value)
    uint8 Flags;
    uint8 MinFactionID;
    uint8 MinReputation;
    uint8 RequiredAchievement;                                      // required personal arena rating
    int32 ItemID[MAX_ITEM_EXT_COST_ITEMS];                          // required item id
    uint16 ItemCount[MAX_ITEM_EXT_COST_ITEMS];                      // required count of 1st item
    uint16 CurrencyID[MAX_ITEM_EXT_COST_CURRENCIES];                // required curency id
    uint32 CurrencyCount[MAX_ITEM_EXT_COST_CURRENCIES];              // required curency count
};

struct ItemLevelSelectorEntry
{
    uint32 ID;
    uint16 MinItemLevel;
    uint16 ItemLevelSelectorQualitySetID;
    uint16 AzeriteUnlockMappingSet;
};

struct ItemLevelSelectorQualityEntry
{
    uint32 ID;
    int32 QualityItemBonusListID;
    int8 Quality;
    uint32 ParentILSQualitySetID;
};

struct ItemLevelSelectorQualitySetEntry
{
    uint32 ID;
    int16 IlvlRare;
    int16 IlvlEpic;
};

struct ItemLimitCategoryEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 Quantity;
    uint8 Flags;
};

struct ItemLimitCategoryConditionEntry
{
    uint32 ID;
    int8 AddQuantity;
    uint32 PlayerConditionID;
    uint32 ParentItemLimitCategoryID;
};

struct ItemModifiedAppearanceEntry
{
    uint32 ID;
    int32 ItemID;
    int32 ItemAppearanceModifierID;
    int32 ItemAppearanceID;
    int32 OrderIndex;
    uint8 TransmogSourceTypeEnum;
};

struct ItemModifiedAppearanceExtraEntry
{
    uint32 ID;
    int32 IconFileDataID;
    int32 UnequippedIconFileDataID;
    uint8 SheatheType;
    int8 DisplayWeaponSubclassID;
    int8 DisplayInventoryType;
};

struct ItemNameDescriptionEntry
{
    uint32 ID;
    LocalizedString Description;
    int32 Color;
};

struct ItemPriceBaseEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Armor;
    float Weapon;
};

struct ItemSearchNameEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> AllowableRace;
    LocalizedString Display;
    uint8 OverallQualityID;
    int32 ExpansionID;
    uint16 MinFactionID;
    uint8 MinReputation;
    int32 AllowableClass;
    int8 RequiredLevel;
    uint16 RequiredSkill;
    uint16 RequiredSkillRank;
    uint32 RequiredAbility;
    uint16 ItemLevel;
    int32 Flags[4];
};

#define MAX_ITEM_SET_ITEMS 17

struct ItemSetEntry
{
    uint32 ID;
    LocalizedString Name;
    uint32 SetFlags;
    uint32 RequiredSkill;
    uint16 RequiredSkillRank;
    uint32 ItemID[MAX_ITEM_SET_ITEMS];
};

struct ItemSetSpellEntry
{
    uint32 ID;
    uint16 ChrSpecID;
    uint32 SpellID;
    uint8 Threshold;
    uint32 ItemSetID;
};

struct ItemSparseEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> AllowableRace;
    LocalizedString Description;
    LocalizedString Display3;
    LocalizedString Display2;
    LocalizedString Display1;
    LocalizedString Display;
    int32 ExpansionID;
    float DmgVariance;
    int32 LimitCategory;
    uint32 DurationInInventory;
    float QualityModifier;
    uint32 BagFamily;
    float ItemRange;
    float StatPercentageOfSocket[MAX_ITEM_PROTO_STATS];
    int32 StatPercentEditor[MAX_ITEM_PROTO_STATS];
    int32 Stackable;
    int32 MaxCount;
    uint32 RequiredAbility;
    uint32 SellPrice;
    uint32 BuyPrice;
    uint32 VendorStackCount;
    float PriceVariance;
    float PriceRandomValue;
    int32 Flags[MAX_ITEM_PROTO_FLAGS];
    int32 FactionRelated;
    int32 ModifiedCraftingReagentItemID;
    int32 ContentTuningID;
    int32 PlayerLevelToItemLevelCurveID;
    uint16 ItemNameDescriptionID;
    uint16 RequiredTransmogHoliday;
    uint16 RequiredHoliday;
    uint16 GemProperties;
    uint16 SocketMatchEnchantmentId;
    uint16 TotemCategoryID;
    uint16 InstanceBound;
    uint16 ZoneBound[MAX_ITEM_PROTO_ZONES];
    uint16 ItemSet;
    uint16 LockID;
    uint16 StartQuestID;
    uint16 PageID;
    uint16 ItemDelay;
    uint16 MinFactionID;
    uint16 RequiredSkillRank;
    uint16 RequiredSkill;
    uint16 ItemLevel;
    int16 AllowableClass;
    uint8 ArtifactID;
    uint8 SpellWeight;
    uint8 SpellWeightCategory;
    uint8 SocketType[MAX_ITEM_PROTO_SOCKETS];
    uint8 SheatheType;
    uint8 Material;
    uint8 PageMaterialID;
    uint8 LanguageID;
    uint8 Bonding;
    uint8 DamageDamageType;
    int8 StatModifierBonusStat[MAX_ITEM_PROTO_STATS];
    uint8 ContainerSlots;
    uint8 MinReputation;
    uint8 RequiredPVPMedal;
    uint8 RequiredPVPRank;
    int8 RequiredLevel;
    int8 InventoryType;
    int8 OverallQualityID;
};

struct ItemSpecEntry
{
    uint32 ID;
    uint8 MinLevel;
    uint8 MaxLevel;
    uint8 ItemType;
    uint8 PrimaryStat;
    uint8 SecondaryStat;
    uint16 SpecializationID;
};

struct ItemSpecOverrideEntry
{
    uint32 ID;
    uint16 SpecID;
    uint32 ItemID;
};

struct ItemXBonusTreeEntry
{
    uint32 ID;
    uint16 ItemBonusTreeID;
    uint32 ItemID;
};

struct ItemXItemEffectEntry
{
    uint32 ID;
    int32 ItemEffectID;
    uint32 ItemID;
};

struct JournalEncounterEntry
{
    LocalizedString Name;
    LocalizedString Description;
    DBCPosition2D Map;
    uint32 ID;
    uint16 JournalInstanceID;
    uint16 DungeonEncounterID;
    uint32 OrderIndex;
    uint16 FirstSectionID;
    uint16 UiMapID;
    uint32 MapDisplayConditionID;
    uint8 Flags;
    int8 DifficultyMask;
};

struct JournalEncounterSectionEntry
{
    uint32 ID;
    LocalizedString Title;
    LocalizedString BodyText;
    uint16 JournalEncounterID;
    uint8 OrderIndex;
    uint16 ParentSectionID;
    uint16 FirstChildSectionID;
    uint16 NextSiblingSectionID;
    uint8 Type;
    uint32 IconCreatureDisplayInfoID;
    int32 UiModelSceneID;
    int32 SpellID;
    int32 IconFileDataID;
    uint16 Flags;
    uint16 IconFlags;
    int8 DifficultyMask;
};

struct JournalInstanceEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    uint16 MapID;
    int32 BackgroundFileDataID;
    int32 ButtonFileDataID;
    int32 ButtonSmallFileDataID;
    int32 LoreFileDataID;
    uint8 OrderIndex;
    uint8 Flags;
    uint16 AreaID;
};

struct JournalTierEntry
{
    uint32 ID;
    LocalizedString Name;
    int32 PlayerConditionID;
};

#define KEYCHAIN_SIZE   32

struct KeychainEntry
{
    uint32 ID;
    uint8 Key[KEYCHAIN_SIZE];
};

struct KeystoneAffixEntry
{
    LocalizedString Name;
    LocalizedString Description;
    uint32 ID;
    int32 FiledataID;
};

struct LanguageWordsEntry
{
    uint32 ID;
    char const* Word;
    uint32 LanguageID;
};

struct LanguagesEntry
{
    uint32 ID;
    LocalizedString Name;
};

struct LFGDungeonsEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    uint8 TypeID;
    uint8 Subtype;
    int8 Faction;
    int32 IconTextureFileID;
    int32 RewardsBgTextureFileID;
    int32 PopupBgTextureFileID;
    uint8 ExpansionLevel;
    int16 MapID;
    uint8 DifficultyID;
    float MinGear;
    uint8 GroupID;
    uint8 OrderIndex;
    uint32 RequiredPlayerConditionId;
    uint16 RandomID;
    uint16 ScenarioID;
    uint16 FinalEncounterID;
    uint8 CountTank;
    uint8 CountHealer;
    uint8 CountDamage;
    uint8 MinCountTank;
    uint8 MinCountHealer;
    uint8 MinCountDamage;
    uint16 BonusReputationAmount;
    uint16 MentorItemLevel;
    uint8 MentorCharLevel;
    int32 ContentTuningID;
    int32 Flags[2];

    // Helpers
    uint32 Entry() const { return ID + (TypeID << 24); }
};

struct LightEntry
{
    uint32 ID;
    DBCPosition3D GameCoords;
    float GameFalloffStart;
    float GameFalloffEnd;
    int16 ContinentID;
    uint16 LightParamsID[8];
};

struct LiquidTypeEntry
{
    uint32 ID;
    char const* Name;
    char const* Texture[6];
    uint16 Flags;
    uint8 SoundBank;                                                // used to be "type", maybe needs fixing (works well for now)
    uint32 SoundID;
    uint32 SpellID;
    float MaxDarkenDepth;
    float FogDarkenIntensity;
    float AmbDarkenIntensity;
    float DirDarkenIntensity;
    uint16 LightID;
    float ParticleScale;
    uint8 ParticleMovement;
    uint8 ParticleTexSlots;
    uint8 MaterialID;
    int32 MinimapStaticCol;
    uint8 FrameCountTexture[6];
    int32 Color[2];
    float Float[18];
    uint32 Int[4];
    float Coefficient[4];
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32 ID;
    int32 Flags;
    int32 Index[MAX_LOCK_CASE];
    uint16 Skill[MAX_LOCK_CASE];
    uint8 Type[MAX_LOCK_CASE];
    uint8 Action[MAX_LOCK_CASE];
};

struct MailTemplateEntry
{
    uint32 ID;
    LocalizedString Body;
};

struct MapEntry
{
    uint32 ID;
    char const* Directory;
    LocalizedString MapName;
    LocalizedString MapDescription0;                               // Horde
    LocalizedString MapDescription1;                               // Alliance
    LocalizedString PvpShortDescription;
    LocalizedString PvpLongDescription;
    DBCPosition2D Corpse;                                           // entrance coordinates in ghost mode  (in most cases = normal entrance)
    uint8 MapType;
    int8 InstanceType;
    uint8 ExpansionID;
    uint16 AreaTableID;
    int16 LoadingScreenID;
    int16 TimeOfDayOverride;
    int16 ParentMapID;
    int16 CosmeticParentMapID;
    uint8 TimeOffset;
    float MinimapIconScale;
    int16 CorpseMapID;                                              // map_id of entrance map in ghost mode (continent always and in most cases = normal entrance)
    uint8 MaxPlayers;
    int16 WindSettingsID;
    int32 ZmpFileDataID;
    int32 WdtFileDataID;
    int32 Flags[2];

    // Helpers
    uint8 Expansion() const { return ExpansionID; }

    bool IsDungeon() const { return (InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID || InstanceType == MAP_SCENARIO) && !IsGarrison(); }
    bool IsNonRaidDungeon() const { return InstanceType == MAP_INSTANCE; }
    bool Instanceable() const { return InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID || InstanceType == MAP_BATTLEGROUND || InstanceType == MAP_ARENA || InstanceType == MAP_SCENARIO; }
    bool IsRaid() const { return InstanceType == MAP_RAID; }
    bool IsBattleground() const { return InstanceType == MAP_BATTLEGROUND; }
    bool IsBattleArena() const { return InstanceType == MAP_ARENA; }
    bool IsBattlegroundOrArena() const { return InstanceType == MAP_BATTLEGROUND || InstanceType == MAP_ARENA; }
    bool IsWorldMap() const { return InstanceType == MAP_COMMON; }

    bool GetEntrancePos(int32& mapid, float& x, float& y) const
    {
        if (CorpseMapID < 0)
            return false;

        mapid = CorpseMapID;
        x = Corpse.X;
        y = Corpse.Y;
        return true;
    }

    bool IsContinent() const
    {
        return ID == 0 || ID == 1 || ID == 530 || ID == 571 || ID == 870 || ID == 1116 || ID == 1220;
    }

    bool IsDynamicDifficultyMap() const { return (Flags[0] & MAP_FLAG_CAN_TOGGLE_DIFFICULTY) != 0; }
    bool IsGarrison() const { return (Flags[0] & MAP_FLAG_GARRISON) != 0; }
};

struct MapChallengeModeEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 MapID;
    uint8 Flags;
    uint32 ExpansionLevel;
    int32 RequiredWorldStateID; // maybe?
    int16 CriteriaCount[3];
};

struct MapDifficultyEntry
{
    uint32 ID;
    LocalizedString Message;                                // m_message_lang (text showed when transfer to map failed)
    int32 DifficultyID;
    int32 LockID;
    int8 ResetInterval;
    int32 MaxPlayers;
    int32 ItemContext;
    int32 ItemContextPickerID;
    int32 Flags;
    int32 ContentTuningID;
    uint32 MapID;

    uint32 GetRaidDuration() const
    {
        if (ResetInterval == 1)
            return 86400;
        if (ResetInterval == 2)
            return 604800;
        return 0;
    }
};

struct MapDifficultyXConditionEntry
{
    uint32 ID;
    LocalizedString FailureDescription;
    uint32 PlayerConditionID;
    int32 OrderIndex;
    uint32 MapDifficultyID;
};

struct MawPowerEntry
{
    uint32 ID;
    int32 SpellID;
    int32 MawPowerRarityID;
};

struct ModifierTreeEntry
{
    uint32 ID;
    uint32 Parent;
    int8 Operator;
    int8 Amount;
    int32 Type;
    int32 Asset;
    int32 SecondaryAsset;
    int32 TertiaryAsset;
};

struct MountEntry
{
    LocalizedString Name;
    LocalizedString SourceText;
    LocalizedString Description;
    uint32 ID;
    uint16 MountTypeID;
    uint16 Flags;
    int8 SourceTypeEnum;
    int32 SourceSpellID;
    uint32 PlayerConditionID;
    float MountFlyRideHeight;
    int32 UiModelSceneID;
    int32 MountSpecialRiderAnimKitID;
    int32 MountSpecialSpellVisualKitID;

    bool IsSelfMount() const { return (Flags & MOUNT_FLAG_SELF_MOUNT) != 0; }
};

struct MountCapabilityEntry
{
    uint32 ID;
    uint8 Flags;
    uint16 ReqRidingSkill;
    uint16 ReqAreaID;
    uint32 ReqSpellAuraID;
    int32 ReqSpellKnownID;
    int32 ModSpellAuraID;
    int16 ReqMapID;
    int32 PlayerConditionID;
};

struct MountTypeXCapabilityEntry
{
    uint32 ID;
    uint16 MountTypeID;
    uint16 MountCapabilityID;
    uint8 OrderIndex;
};

struct MountXDisplayEntry
{
    uint32 ID;
    int32 CreatureDisplayInfoID;
    uint32 PlayerConditionID;
    uint32 MountID;
};

struct MovieEntry
{
    uint32 ID;
    uint8 Volume;
    uint8 KeyID;
    uint32 AudioFileDataID;
    uint32 SubtitleFileDataID;
};

struct NameGenEntry
{
    uint32 ID;
    char const* Name;
    uint8 RaceID;
    uint8 Sex;
};

struct NamesProfanityEntry
{
    uint32 ID;
    char const* Name;
    int8 Language;
};

struct NamesReservedEntry
{
    uint32 ID;
    char const* Name;
};

struct NamesReservedLocaleEntry
{
    uint32 ID;
    char const* Name;
    uint8 LocaleMask;
};

struct NumTalentsAtLevelEntry
{
    uint32 ID;
    int32 NumTalents;
    int32 NumTalentsDeathKnight;
    int32 NumTalentsDemonHunter;
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32 ID;
    int32 Spells[MAX_OVERRIDE_SPELL];
    int32 PlayerActionBarFileDataID;
    uint8 Flags;
};

struct ParagonReputationEntry
{
    uint32 ID;
    int32 FactionID;
    int32 LevelThreshold;
    int32 QuestID;
};

struct PhaseEntry
{
    uint32 ID;
    uint16 Flags;

    EnumFlag<PhaseEntryFlags> GetFlags() const { return static_cast<PhaseEntryFlags>(Flags); }
};

struct PhaseXPhaseGroupEntry
{
    uint32 ID;
    uint16 PhaseID;
    uint32 PhaseGroupID;
};

struct PlayerConditionEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    LocalizedString FailureDescription;
    int32 ClassMask;
    uint32 SkillLogic;
    int32 LanguageID;
    uint8 MinLanguage;
    int32 MaxLanguage;
    uint16 MaxFactionID;
    uint8 MaxReputation;
    uint32 ReputationLogic;
    int8 CurrentPvpFaction;
    uint8 PvpMedal;
    uint32 PrevQuestLogic;
    uint32 CurrQuestLogic;
    uint32 CurrentCompletedQuestLogic;
    uint32 SpellLogic;
    uint32 ItemLogic;
    uint8 ItemFlags;
    uint32 AuraSpellLogic;
    uint16 WorldStateExpressionID;
    int32 WeatherID;
    uint8 PartyStatus;
    uint8 LifetimeMaxPVPRank;
    uint32 AchievementLogic;
    int8 Gender;
    int8 NativeGender;
    uint32 AreaLogic;
    uint32 LfgLogic;
    uint32 CurrencyLogic;
    int32 QuestKillID;
    uint32 QuestKillLogic;
    int8 MinExpansionLevel;
    int8 MaxExpansionLevel;
    int32 MinAvgItemLevel;
    int32 MaxAvgItemLevel;
    uint16 MinAvgEquippedItemLevel;
    uint16 MaxAvgEquippedItemLevel;
    uint8 PhaseUseFlags;
    uint16 PhaseID;
    uint32 PhaseGroupID;
    int32 Flags;
    int8 ChrSpecializationIndex;
    int8 ChrSpecializationRole;
    uint32 ModifierTreeID;
    int8 PowerType;
    uint8 PowerTypeComp;
    uint8 PowerTypeValue;
    int32 WeaponSubclassMask;
    uint8 MaxGuildLevel;
    uint8 MinGuildLevel;
    int8 MaxExpansionTier;
    int8 MinExpansionTier;
    uint8 MinPVPRank;
    uint8 MaxPVPRank;
    int32 ContentTuningID;
    int32 CovenantID;
    uint16 SkillID[4];
    uint16 MinSkill[4];
    uint16 MaxSkill[4];
    uint32 MinFactionID[3];
    uint8 MinReputation[3];
    int32 PrevQuestID[4];
    int32 CurrQuestID[4];
    int32 CurrentCompletedQuestID[4];
    int32 SpellID[4];
    int32 ItemID[4];
    uint32 ItemCount[4];
    uint16 Explored[2];
    uint32 Time[2];
    int32 AuraSpellID[4];
    uint8 AuraStacks[4];
    uint16 Achievement[4];
    uint16 AreaID[4];
    uint8 LfgStatus[4];
    uint8 LfgCompare[4];
    uint32 LfgValue[4];
    uint32 CurrencyID[4];
    uint32 CurrencyCount[4];
    uint32 QuestKillMonster[6];
    int32 MovementFlags[2];
};

struct PowerDisplayEntry
{
    uint32 ID;
    char const* GlobalStringBaseTag;
    uint8 ActualType;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct PowerTypeEntry
{
    char const* NameGlobalStringTag;
    char const* CostGlobalStringTag;
    uint32 ID;
    int8 PowerTypeEnum;
    int8 MinPower;
    int16 MaxBasePower;
    int8 CenterPower;
    int8 DefaultPower;
    int8 DisplayModifier;
    int16 RegenInterruptTimeMS;
    float RegenPeace;
    float RegenCombat;
    int16 Flags;
};

struct PrestigeLevelInfoEntry
{
    uint32 ID;
    LocalizedString Name;
    int32 PrestigeLevel;
    int32 BadgeTextureFileDataID;
    uint8 Flags;
    int32 AwardedAchievementID;

    bool IsDisabled() const { return (Flags & PRESTIGE_FLAG_DISABLED) != 0; }
};

struct PVPDifficultyEntry
{
    uint32 ID;
    uint8 RangeIndex;
    uint8 MinLevel;
    uint8 MaxLevel;
    uint32 MapID;

    // helpers
    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(RangeIndex); }
};

struct PVPItemEntry
{
    uint32 ID;
    int32 ItemID;
    uint8 ItemLevelDelta;
};

struct PvpTalentEntry
{
    LocalizedString Description;
    uint32 ID;
    int32 SpecID;
    int32 SpellID;
    int32 OverridesSpellID;
    int32 Flags;
    int32 ActionBarSpellID;
    int32 PvpTalentCategoryID;
    int32 LevelRequired;
};

struct PvpTalentCategoryEntry
{
    uint32 ID;
    uint8 TalentSlotMask;
};

struct PvpTalentSlotUnlockEntry
{
    uint32 ID;
    int8 Slot;
    int32 LevelRequired;
    int32 DeathKnightLevelRequired;
    int32 DemonHunterLevelRequired;
};

struct PvpTierEntry
{
    LocalizedString Name;
    uint32 ID;
    int16 MinRating;
    int16 MaxRating;
    int32 PrevTier;
    int32 NextTier;
    int8 BracketID;
    int8 Rank;
    int32 RankIconFileDataID;
};

struct QuestFactionRewardEntry
{
    uint32 ID;
    int16 Difficulty[10];
};

struct QuestInfoEntry
{
    uint32 ID;
    LocalizedString InfoName;
    int8 Type;
    int32 Modifiers;
    uint16 Profession;
};

struct QuestLineXQuestEntry
{
    uint32 ID;
    uint32 QuestLineID;
    uint32 QuestID;
    uint32 OrderIndex;
    int32 Flags;
};

struct QuestMoneyRewardEntry
{
    uint32 ID;
    uint32 Difficulty[10];
};

struct QuestPackageItemEntry
{
    uint32 ID;
    uint16 PackageID;
    int32 ItemID;
    uint32 ItemQuantity;
    uint8 DisplayType;
};

struct QuestSortEntry
{
    uint32 ID;
    LocalizedString SortName;
    int8 UiOrderIndex;
};

struct QuestV2Entry
{
    uint32 ID;
    uint16 UniqueBitFlag;
};

struct QuestXPEntry
{
    uint32 ID;
    uint16 Difficulty[10];
};

struct RandPropPointsEntry
{
    uint32 ID;
    float DamageReplaceStatF;
    float DamageSecondaryF;
    int32 DamageReplaceStat;
    int32 DamageSecondary;
    float EpicF[5];
    float SuperiorF[5];
    float GoodF[5];
    uint32 Epic[5];
    uint32 Superior[5];
    uint32 Good[5];
};

struct RewardPackEntry
{
    uint32 ID;
    int32 CharTitleID;
    uint32 Money;
    int8 ArtifactXPDifficulty;
    float ArtifactXPMultiplier;
    uint8 ArtifactXPCategoryID;
    uint32 TreasurePickerID;
};

struct RewardPackXCurrencyTypeEntry
{
    uint32 ID;
    uint32 CurrencyTypeID;
    int32 Quantity;
    uint32 RewardPackID;
};

struct RewardPackXItemEntry
{
    uint32 ID;
    int32 ItemID;
    int32 ItemQuantity;
    uint32 RewardPackID;
};

struct ScenarioEntry
{
    uint32 ID;
    LocalizedString Name;
    uint16 AreaTableID;
    uint8 Type;
    uint8 Flags;
    uint32 UiTextureKitID;
};

struct ScenarioStepEntry
{
    uint32 ID;
    LocalizedString Description;
    LocalizedString Title;
    uint16 ScenarioID;
    uint32 Criteriatreeid;
    int32 RewardQuestID;
    int32 RelatedStep;                                              // Bonus step can only be completed if scenario is in the step specified in this field
    uint16 Supersedes;                                              // Used in conjunction with Proving Grounds scenarios, when sequencing steps (Not using step order?)
    uint8 OrderIndex;
    uint8 Flags;
    uint32 VisibilityPlayerConditionID;
    uint16 WidgetSetID;

    // helpers
    bool IsBonusObjective() const
    {
        return Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE;
    }
};

struct SceneScriptEntry
{
    uint32 ID;
    uint16 FirstSceneScriptID;
    uint16 NextSceneScriptID;
    int32 Unknown915;
};

struct SceneScriptGlobalTextEntry
{
    uint32 ID;
    char const* Name;
    char const* Script;
};

struct SceneScriptPackageEntry
{
    uint32 ID;
    char const* Name;
    int32 Unknown915;
};

struct SceneScriptTextEntry
{
    uint32 ID;
    char const* Name;
    char const* Script;
};

struct SkillLineEntry
{
    LocalizedString DisplayName;
    LocalizedString AlternateVerb;
    LocalizedString Description;
    LocalizedString HordeDisplayName;
    char const* OverrideSourceInfoDisplayName;
    uint32 ID;
    int8 CategoryID;
    int32 SpellIconFileID;
    int8 CanLink;
    uint32 ParentSkillLineID;
    int32 ParentTierIndex;
    uint16 Flags;
    int32 SpellBookSpellID;
};

struct SkillLineAbilityEntry
{
    Trinity::RaceMask<int64> RaceMask;
    uint32 ID;
    int16 SkillLine;
    int32 Spell;
    int16 MinSkillLineRank;
    int32 ClassMask;
    int32 SupercedesSpell;
    int8 AcquireMethod;
    int16 TrivialSkillLineRankHigh;
    int16 TrivialSkillLineRankLow;
    int32 Flags;
    int8 NumSkillUps;
    int16 UniqueBit;
    int16 TradeSkillCategoryID;
    int16 SkillupSkillLineID;

    EnumFlag<SkillLineAbilityFlags> GetFlags() const { return EnumFlag<SkillLineAbilityFlags>(static_cast<SkillLineAbilityFlags>(Flags)); }
};

struct SkillRaceClassInfoEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    int16 SkillID;
    int32 ClassMask;
    uint16 Flags;
    int8 Availability;
    int8 MinLevel;
    int16 SkillTierID;
};

struct SoulbindConduitRankEntry
{
    uint32 ID;
    int32 RankIndex;
    int32 SpellID;
    float AuraPointsOverride;
    uint32 SoulbindConduitID;
};

struct SoundKitEntry
{
    uint32 ID;
    int32 SoundType;
    float VolumeFloat;
    uint16 Flags;
    float MinDistance;
    float DistanceCutoff;
    uint8 EAXDef;
    uint32 SoundKitAdvancedID;
    float VolumeVariationPlus;
    float VolumeVariationMinus;
    float PitchVariationPlus;
    float PitchVariationMinus;
    int8 DialogType;
    float PitchAdjust;
    uint16 BusOverwriteID;
    uint8 MaxInstances;
};

struct SpecializationSpellsEntry
{
    LocalizedString Description;
    uint32 ID;
    uint16 SpecID;
    int32 SpellID;
    int32 OverridesSpellID;
    uint8 DisplayOrder;
};

struct SpecSetMemberEntry
{
    uint32 ID;
    int32 ChrSpecializationID;
    uint32 SpecSetID;
};

struct SpellAuraOptionsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint16 CumulativeAura;
    int32 ProcCategoryRecovery;
    uint8 ProcChance;
    int32 ProcCharges;
    uint16 SpellProcsPerMinuteID;
    int32 ProcTypeMask[2];
    uint32 SpellID;
};

struct SpellAuraRestrictionsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint8 CasterAuraState;
    uint8 TargetAuraState;
    uint8 ExcludeCasterAuraState;
    uint8 ExcludeTargetAuraState;
    int32 CasterAuraSpell;
    int32 TargetAuraSpell;
    int32 ExcludeCasterAuraSpell;
    int32 ExcludeTargetAuraSpell;
    uint32 SpellID;
};

struct SpellCastTimesEntry
{
    uint32 ID;
    int32 Base;
    int32 Minimum;
};

struct SpellCastingRequirementsEntry
{
    uint32 ID;
    int32 SpellID;
    uint8 FacingCasterFlags;
    uint16 MinFactionID;
    int8 MinReputation;
    uint16 RequiredAreasID;
    uint8 RequiredAuraVision;
    uint16 RequiresSpellFocus;
};

struct SpellCategoriesEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int16 Category;
    int8 DefenseType;
    int8 DispelType;
    int8 Mechanic;
    int8 PreventionType;
    int16 StartRecoveryCategory;
    int16 ChargeCategory;
    uint32 SpellID;
};

struct SpellCategoryEntry
{
    uint32 ID;
    LocalizedString Name;
    int8 Flags;
    uint8 UsesPerWeek;
    int8 MaxCharges;
    int32 ChargeRecoveryTime;
    int32 TypeMask;
};

struct SpellClassOptionsEntry
{
    uint32 ID;
    int32 SpellID;
    uint32 ModalNextSpell;
    uint8 SpellClassSet;
    flag128 SpellClassMask;
};

struct SpellCooldownsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int32 CategoryRecoveryTime;
    int32 RecoveryTime;
    int32 StartRecoveryTime;
    uint32 SpellID;
};

struct SpellDurationEntry
{
    uint32 ID;
    int32 Duration;
    int32 MaxDuration;
};

struct SpellEffectEntry
{
    uint32 ID;
    int16 EffectAura;
    int32 DifficultyID;
    int32 EffectIndex;
    uint32 Effect;
    float EffectAmplitude;
    int32 EffectAttributes;
    int32 EffectAuraPeriod;
    float EffectBonusCoefficient;
    float EffectChainAmplitude;
    int32 EffectChainTargets;
    int32 EffectItemType;
    int32 EffectMechanic;
    float EffectPointsPerResource;
    float EffectPosFacing;
    float EffectRealPointsPerLevel;
    int32 EffectTriggerSpell;
    float BonusCoefficientFromAP;
    float PvpMultiplier;
    float Coefficient;
    float Variance;
    float ResourceCoefficient;
    float GroupSizeBasePointsCoefficient;
    float EffectBasePoints;
    int32 ScalingClass;
    int32 EffectMiscValue[2];
    uint32 EffectRadiusIndex[2];
    flag128 EffectSpellClassMask;
    int16 ImplicitTarget[2];
    uint32 SpellID;

    SpellEffectAttributes GetEffectAttributes() const { return static_cast<SpellEffectAttributes>(EffectAttributes); }
};

struct SpellEquippedItemsEntry
{
    uint32 ID;
    int32 SpellID;
    int8 EquippedItemClass;
    int32 EquippedItemInvTypes;
    int32 EquippedItemSubclass;
};

struct SpellFocusObjectEntry
{
    uint32 ID;
    LocalizedString Name;
};

struct SpellInterruptsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int16 InterruptFlags;
    int32 AuraInterruptFlags[MAX_SPELL_AURA_INTERRUPT_FLAGS];
    int32 ChannelInterruptFlags[MAX_SPELL_AURA_INTERRUPT_FLAGS];
    uint32 SpellID;
};

#define MAX_ITEM_ENCHANTMENT_EFFECTS 3

struct SpellItemEnchantmentEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString HordeName;
    uint32 EffectArg[MAX_ITEM_ENCHANTMENT_EFFECTS];
    float EffectScalingPoints[MAX_ITEM_ENCHANTMENT_EFFECTS];
    uint32 IconFileDataID;
    int32 MinItemLevel;
    int32 MaxItemLevel;
    uint32 TransmogUseConditionID;
    uint32 TransmogCost;
    int16 EffectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS];
    uint16 ItemVisual;
    uint16 Flags;
    uint16 RequiredSkillID;
    uint16 RequiredSkillRank;
    uint16 ItemLevel;
    uint8 Charges;
    uint8 Effect[MAX_ITEM_ENCHANTMENT_EFFECTS];
    int8 ScalingClass;
    int8 ScalingClassRestricted;
    uint8 ConditionID;
    uint8 MinLevel;
    uint8 MaxLevel;
};

struct SpellItemEnchantmentConditionEntry
{
    uint32 ID;
    uint8 LtOperandType[5];
    uint32 LtOperand[5];
    uint8 Operator[5];
    uint8 RtOperandType[5];
    uint8 RtOperand[5];
    uint8 Logic[5];
};

struct SpellLabelEntry
{
    uint32 ID;
    uint32 LabelID;
    uint32 SpellID;
};

struct SpellLearnSpellEntry
{
    uint32 ID;
    int32 SpellID;
    int32 LearnSpellID;
    int32 OverridesSpellID;
};

struct SpellLevelsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int16 MaxLevel;
    uint8 MaxPassiveAuraLevel;
    int32 BaseLevel;
    int32 SpellLevel;
    uint32 SpellID;
};

struct SpellMiscEntry
{
    uint32 ID;
    int32 Attributes[15];
    uint8 DifficultyID;
    uint16 CastingTimeIndex;
    uint16 DurationIndex;
    uint16 RangeIndex;
    uint8 SchoolMask;
    float Speed;
    float LaunchDelay;
    float MinDuration;
    int32 SpellIconFileDataID;
    int32 ActiveIconFileDataID;
    int32 ContentTuningID;
    int32 ShowFutureSpellPlayerConditionID;
    int32 SpellVisualScript;
    int32 ActiveSpellVisualScript;
    uint32 SpellID;
};

struct SpellNameEntry
{
    uint32 ID;                      // SpellID
    LocalizedString Name;
};

struct SpellPowerEntry
{
    uint32 ID;
    uint8 OrderIndex;
    int32 ManaCost;
    int32 ManaCostPerLevel;
    int32 ManaPerSecond;
    uint32 PowerDisplayID;
    int32 AltPowerBarID;
    float PowerCostPct;
    float PowerCostMaxPct;
    float PowerPctPerSecond;
    int8 PowerType;
    int32 RequiredAuraSpellID;
    uint32 OptionalCost;                                            // Spell uses [ManaCost, ManaCost+ManaCostAdditional] power - affects tooltip parsing as multiplier on SpellEffectEntry::EffectPointsPerResource
                                                                   //   only SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE, SPELL_EFFECT_WEAPON_DAMAGE, SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    uint32 SpellID;
};

struct SpellPowerDifficultyEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint8 OrderIndex;
};

struct SpellProcsPerMinuteEntry
{
    uint32 ID;
    float BaseProcRate;
    uint8 Flags;
};

struct SpellProcsPerMinuteModEntry
{
    uint32 ID;
    uint8 Type;
    int32 Param;
    float Coeff;
    uint32 SpellProcsPerMinuteID;
};

struct SpellRadiusEntry
{
    uint32 ID;
    float Radius;
    float RadiusPerLevel;
    float RadiusMin;
    float RadiusMax;
};

struct SpellRangeEntry
{
    uint32 ID;
    LocalizedString DisplayName;
    LocalizedString DisplayNameShort;
    uint8 Flags;
    float RangeMin[2];
    float RangeMax[2];
};

#define MAX_SPELL_REAGENTS 8

struct SpellReagentsEntry
{
    uint32 ID;
    int32 SpellID;
    int32 Reagent[MAX_SPELL_REAGENTS];
    int16 ReagentCount[MAX_SPELL_REAGENTS];
};

struct SpellReagentsCurrencyEntry
{
    uint32 ID;
    int32 SpellID;
    uint16 CurrencyTypesID;
    uint16 CurrencyCount;
};

struct SpellScalingEntry
{
    uint32 ID;
    int32 SpellID;
    uint32 MinScalingLevel;
    uint32 MaxScalingLevel;
    int16 ScalesFromItemLevel;
};

struct SpellShapeshiftEntry
{
    uint32 ID;
    int32 SpellID;
    int8 StanceBarOrder;
    int32 ShapeshiftExclude[2];
    int32 ShapeshiftMask[2];
};

#define MAX_SHAPESHIFT_SPELLS 8

struct SpellShapeshiftFormEntry
{
    uint32 ID;
    LocalizedString Name;
    int8 CreatureType;
    int32 Flags;
    int32 AttackIconFileID;
    int8 BonusActionBar;
    int16 CombatRoundTime;
    float DamageVariance;
    uint16 MountTypeID;
    uint32 CreatureDisplayID[4];
    uint32 PresetSpellID[MAX_SHAPESHIFT_SPELLS];

    EnumFlag<SpellShapeshiftFormFlags> GetFlags() const { return static_cast<SpellShapeshiftFormFlags>(Flags); }
};

struct SpellTargetRestrictionsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    float ConeDegrees;
    uint8 MaxTargets;
    uint32 MaxTargetLevel;
    int16 TargetCreatureType;
    int32 Targets;
    float Width;
    uint32 SpellID;
};

#define MAX_SPELL_TOTEMS 2

struct SpellTotemsEntry
{
    uint32 ID;
    int32 SpellID;
    uint16 RequiredTotemCategoryID[MAX_SPELL_TOTEMS];
    int32 Totem[MAX_SPELL_TOTEMS];
};

struct SpellVisualEntry
{
    uint32 ID;
    float MissileCastOffset[3];
    float MissileImpactOffset[3];
    uint32 AnimEventSoundID;
    int32 Flags;
    int8 MissileAttachment;
    int8 MissileDestinationAttachment;
    uint32 MissileCastPositionerID;
    uint32 MissileImpactPositionerID;
    int32 MissileTargetingKit;
    uint32 HostileSpellVisualID;
    uint32 CasterSpellVisualID;
    uint16 SpellVisualMissileSetID;
    uint16 DamageNumberDelay;
    uint32 LowViolenceSpellVisualID;
    uint32 RaidSpellVisualMissileSetID;
    int32 ReducedUnexpectedCameraMovementSpellVisualID;
};

struct SpellVisualEffectNameEntry
{
    uint32 ID;
    int32 ModelFileDataID;
    float BaseMissileSpeed;
    float Scale;
    float MinAllowedScale;
    float MaxAllowedScale;
    float Alpha;
    uint32 Flags;
    int32 TextureFileDataID;
    float EffectRadius;
    uint32 Type;
    int32 GenericID;
    uint32 RibbonQualityID;
    int32 DissolveEffectID;
    int32 ModelPosition;
    int8 Unknown901;
};

struct SpellVisualMissileEntry
{
    float CastOffset[3];
    float ImpactOffset[3];
    uint32 ID;
    uint16 SpellVisualEffectNameID;
    uint32 SoundEntriesID;
    int8 Attachment;
    int8 DestinationAttachment;
    uint16 CastPositionerID;
    uint16 ImpactPositionerID;
    int32 FollowGroundHeight;
    uint32 FollowGroundDropSpeed;
    uint16 FollowGroundApproach;
    uint32 Flags;
    uint16 SpellMissileMotionID;
    uint32 AnimKitID;
    int8 ClutterLevel;
    int32 DecayTimeAfterImpact;
    uint32 SpellVisualMissileSetID;
};

struct SpellVisualKitEntry
{
    uint32 ID;
    int8 FallbackPriority;
    int32 FallbackSpellVisualKitId;
    uint16 DelayMin;
    uint16 DelayMax;
    int32 Flags[2];
};

struct SpellXSpellVisualEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint32 SpellVisualID;
    float Probability;
    int32 Priority;
    int32 SpellIconFileID;
    int32 ActiveIconFileID;
    uint16 ViewerUnitConditionID;
    uint32 ViewerPlayerConditionID;
    uint16 CasterUnitConditionID;
    uint32 CasterPlayerConditionID;
    uint32 SpellID;
};

struct SummonPropertiesEntry
{
    uint32 ID;
    int32 Control;
    int32 Faction;
    int32 Title;
    int32 Slot;
    int32 Flags;

    EnumFlag<SummonPropertiesFlags> GetFlags() const { return static_cast<SummonPropertiesFlags>(Flags); }
};

#define TACTKEY_SIZE 16

struct TactKeyEntry
{
    uint32 ID;
    uint8 Key[TACTKEY_SIZE];
};

struct TalentEntry
{
    uint32 ID;
    LocalizedString Description;
    uint8 TierID;
    uint8 Flags;
    uint8 ColumnIndex;
    uint8 ClassID;
    uint16 SpecID;
    uint32 SpellID;
    uint32 OverridesSpellID;
    uint8 CategoryMask[2];
};

struct TaxiNodesEntry
{
    LocalizedString Name;
    DBCPosition3D Pos;
    DBCPosition2D MapOffset;
    DBCPosition2D FlightMapOffset;
    uint32 ID;
    uint16 ContinentID;
    int32 ConditionID;
    uint16 CharacterBitNumber;
    uint8 Flags;
    int32 UiTextureKitID;
    int32 MinimapAtlasMemberID;
    float Facing;
    uint32 SpecialIconConditionID;
    uint32 VisibilityConditionID;
    int32 MountCreatureID[2];
};

struct TaxiPathEntry
{
    uint32 ID;
    uint16 FromTaxiNode;
    uint16 ToTaxiNode;
    uint32 Cost;
};

struct TaxiPathNodeEntry
{
    DBCPosition3D Loc;
    uint32 ID;
    uint16 PathID;
    int32 NodeIndex;
    uint16 ContinentID;
    uint8 Flags;
    uint32 Delay;
    int32 ArrivalEventID;
    int32 DepartureEventID;
};

struct TotemCategoryEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 TotemCategoryType;
    int32 TotemCategoryMask;
};

struct ToyEntry
{
    LocalizedString SourceText;
    uint32 ID;
    int32 ItemID;
    uint8 Flags;
    int8 SourceTypeEnum;
};

struct TransmogHolidayEntry
{
    uint32 ID;
    int32 RequiredTransmogHoliday;
};

struct TransmogIllusionEntry
{
    uint32 ID;
    int32 UnlockConditionID;
    int32 TransmogCost;
    int32 SpellItemEnchantmentID;
    int32 Flags;
};

struct TransmogSetEntry
{
    LocalizedString Name;
    uint32 ID;
    int32 ClassMask;
    uint32 TrackingQuestID;
    int32 Flags;
    uint32 TransmogSetGroupID;
    int32 ItemNameDescriptionID;
    uint16 ParentTransmogSetID;
    uint8 Unknown810;
    uint8 ExpansionID;
    int32 PatchID;
    int16 UiOrder;
    int32 PlayerConditionID;
};

struct TransmogSetGroupEntry
{
    uint32 ID;
    LocalizedString Name;
};

struct TransmogSetItemEntry
{
    uint32 ID;
    uint32 TransmogSetID;
    uint32 ItemModifiedAppearanceID;
    int32 Flags;
};

struct TransportAnimationEntry
{
    uint32 ID;
    DBCPosition3D Pos;
    uint8 SequenceID;
    uint32 TimeIndex;
    uint32 TransportID;
};

struct TransportRotationEntry
{
    uint32 ID;
    float Rot[4];
    uint32 TimeIndex;
    uint32 GameObjectsID;
};

struct UiMapEntry
{
    LocalizedString Name;
    uint32 ID;
    int32 ParentUiMapID;
    int32 Flags;
    uint32 System;
    uint32 Type;
    int32 BountySetID;
    uint32 BountyDisplayLocation;
    int32 VisibilityPlayerConditionID;
    int8 HelpTextPosition;
    int32 BkgAtlasID;
    int32 AlternateUiMapGroup;
    int32 ContentTuningID;

    EnumFlag<UiMapFlag> GetFlags() const { return EnumFlag<UiMapFlag>(static_cast<UiMapFlag>(Flags)); }
};

struct UiMapAssignmentEntry
{
    DBCPosition2D UiMin;
    DBCPosition2D UiMax;
    DBCPosition3D Region[2];
    uint32 ID;
    int32 UiMapID;
    int32 OrderIndex;
    int32 MapID;
    int32 AreaID;
    int32 WmoDoodadPlacementID;
    int32 WmoGroupID;
};

struct UiMapLinkEntry
{
    DBCPosition2D UiMin;
    DBCPosition2D UiMax;
    uint32 ID;
    int32 ParentUiMapID;
    int32 OrderIndex;
    int32 ChildUiMapID;
    int32 OverrideHighlightFileDataID;
    int32 OverrideHighlightAtlasID;
    int32 Flags;
};

struct UiMapXMapArtEntry
{
    uint32 ID;
    int32 PhaseID;
    int32 UiMapArtID;
    uint32 UiMapID;
};

struct UISplashScreenEntry
{
    uint32 ID;
    LocalizedString Header;
    LocalizedString TopLeftFeatureTitle;
    LocalizedString TopLeftFeatureDesc;
    LocalizedString BottomLeftFeatureTitle;
    LocalizedString BottomLeftFeatureDesc;
    LocalizedString RightFeatureTitle;
    LocalizedString RightFeatureDesc;
    int32 AllianceQuestID;
    int32 HordeQuestID;
    int8 ScreenType;
    int32 TextureKitID;
    int32 SoundKitID;
    int32 PlayerConditionID;
    int32 CharLevelConditionID;
    int32 RequiredTimeEventPassed; // serverside TimeEvent table, see ModifierTreeType::HasTimeEventPassed
};

struct UnitPowerBarEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Cost;
    LocalizedString OutOfError;
    LocalizedString ToolTip;
    uint32 MinPower;
    uint32 MaxPower;
    uint32 StartPower;
    uint8 CenterPower;
    float RegenerationPeace;
    float RegenerationCombat;
    uint8 BarType;
    uint16 Flags;
    float StartInset;
    float EndInset;
    int32 FileDataID[6];
    int32 Color[6];
};

#define MAX_VEHICLE_SEATS 8

struct VehicleEntry
{
    uint32 ID;
    int32 Flags;
    uint8 FlagsB;
    float TurnSpeed;
    float PitchSpeed;
    float PitchMin;
    float PitchMax;
    float MouseLookOffsetPitch;
    float CameraFadeDistScalarMin;
    float CameraFadeDistScalarMax;
    float CameraPitchOffset;
    float FacingLimitRight;
    float FacingLimitLeft;
    float CameraYawOffset;
    uint16 VehicleUIIndicatorID;
    int32 MissileTargetingID;
    uint16 VehiclePOITypeID;
    uint16 SeatID[8];
    uint16 PowerDisplayID[3];
};

struct VehicleSeatEntry
{
    uint32 ID;
    DBCPosition3D AttachmentOffset;
    DBCPosition3D CameraOffset;
    int32 Flags;
    int32 FlagsB;
    int32 FlagsC;
    int8 AttachmentID;
    float EnterPreDelay;
    float EnterSpeed;
    float EnterGravity;
    float EnterMinDuration;
    float EnterMaxDuration;
    float EnterMinArcHeight;
    float EnterMaxArcHeight;
    int32 EnterAnimStart;
    int32 EnterAnimLoop;
    int32 RideAnimStart;
    int32 RideAnimLoop;
    int32 RideUpperAnimStart;
    int32 RideUpperAnimLoop;
    float ExitPreDelay;
    float ExitSpeed;
    float ExitGravity;
    float ExitMinDuration;
    float ExitMaxDuration;
    float ExitMinArcHeight;
    float ExitMaxArcHeight;
    int32 ExitAnimStart;
    int32 ExitAnimLoop;
    int32 ExitAnimEnd;
    int16 VehicleEnterAnim;
    int8 VehicleEnterAnimBone;
    int16 VehicleExitAnim;
    int8 VehicleExitAnimBone;
    int16 VehicleRideAnimLoop;
    int8 VehicleRideAnimLoopBone;
    int8 PassengerAttachmentID;
    float PassengerYaw;
    float PassengerPitch;
    float PassengerRoll;
    float VehicleEnterAnimDelay;
    float VehicleExitAnimDelay;
    int8 VehicleAbilityDisplay;
    uint32 EnterUISoundID;
    uint32 ExitUISoundID;
    int32 UiSkinFileDataID;
    float CameraEnteringDelay;
    float CameraEnteringDuration;
    float CameraExitingDelay;
    float CameraExitingDuration;
    float CameraPosChaseRate;
    float CameraFacingChaseRate;
    float CameraEnteringZoom;
    float CameraSeatZoomMin;
    float CameraSeatZoomMax;
    int16 EnterAnimKitID;
    int16 RideAnimKitID;
    int16 ExitAnimKitID;
    int16 VehicleEnterAnimKitID;
    int16 VehicleRideAnimKitID;
    int16 VehicleExitAnimKitID;
    int16 CameraModeID;

    inline bool HasFlag(VehicleSeatFlags flag) const { return !!(Flags & flag); }
    inline bool HasFlag(VehicleSeatFlagsB flag) const { return !!(FlagsB & flag); }

    inline bool CanEnterOrExit() const { return HasFlag(VehicleSeatFlags(VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT | VEHICLE_SEAT_FLAG_CAN_CONTROL | VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_VOLUNTARY_EXIT)); }
    inline bool CanSwitchFromSeat() const { return HasFlag(VEHICLE_SEAT_FLAG_CAN_SWITCH); }
    inline bool IsUsableByOverride() const {
        return HasFlag(VehicleSeatFlags(VEHICLE_SEAT_FLAG_UNCONTROLLED | VEHICLE_SEAT_FLAG_UNK18))
            || HasFlag(VehicleSeatFlagsB(VEHICLE_SEAT_FLAG_B_USABLE_FORCED | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2 |
                VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3 | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4));
    }
    inline bool IsEjectable() const { return HasFlag(VEHICLE_SEAT_FLAG_B_EJECTABLE); }
};

struct WMOAreaTableEntry
{
    LocalizedString AreaName;
    uint32 ID;
    uint16 WmoID;                                                   //  used in root WMO
    uint8 NameSetID;                                                //  used in adt file
    int32 WmoGroupID;                                               //  used in group WMO
    uint8 SoundProviderPref;
    uint8 SoundProviderPrefUnderwater;
    uint16 AmbienceID;
    uint16 UwAmbience;
    uint16 ZoneMusic;
    uint32 UwZoneMusic;
    uint16 IntroSound;
    uint16 UwIntroSound;
    uint16 AreaTableID;
    uint8 Flags;
};

struct WorldEffectEntry
{
    uint32 ID;
    uint32 QuestFeedbackEffectID;
    uint8 WhenToDisplay;
    uint8 TargetType;
    int32 TargetAsset;
    uint32 PlayerConditionID;
    uint16 CombatConditionID;
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32 ID;
    uint32 UiMapArtID;
    uint16 TextureWidth;
    uint16 TextureHeight;
    int32 OffsetX;
    int32 OffsetY;
    int32 HitRectTop;
    int32 HitRectBottom;
    int32 HitRectLeft;
    int32 HitRectRight;
    uint32 PlayerConditionID;
    uint32 Flags;
    uint32 AreaID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];
};

struct WorldStateExpressionEntry
{
    uint32 ID;
    char const* Expression;
};

#pragma pack(pop)
#endif
