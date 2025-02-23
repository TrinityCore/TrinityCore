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
#include "FlagsArray.h"
#include "RaceMask.h"

#pragma pack(push, 1)

// structure for Achievement.db2
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
    uint16 UiOrder;
    int32 IconFileID;
    uint32 CriteriaTree;
    int16 SharesCriteria;                                           // referenced achievement (counting of all completed criterias)
};

// structure for Achievement_Category.db2
struct Achievement_CategoryEntry
{
    LocalizedString Name;
    uint32 ID;
    int16 Parent;
    uint8 UiOrder;
};

// structure for AnimationData.db2
struct AnimationDataEntry
{
    uint32 ID;
    uint16 Fallback;
    uint8 BehaviorTier;
    int16 BehaviorID;
    std::array<int32, 2> Flags;
};

// structure for AnimKit.db2
struct AnimKitEntry
{
    uint32 ID;
    uint32 OneShotDuration;
    uint16 OneShotStopAnimKitID;
    uint16 LowDefAnimKitID;
};

// structure for AreaGroupMember.db2
struct AreaGroupMemberEntry
{
    uint32 ID;
    uint16 AreaID;
    uint32 AreaGroupID;
};

// structure for AreaTable.db2
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
    int8 ExplorationLevel;
    uint16 IntroSound;
    uint32 UwIntroSound;
    uint8 FactionGroupMask;
    float AmbientMultiplier;
    int32 MountFlags;
    int16 PvpCombatWorldStateID;
    uint8 WildBattlePetLevelMin;
    uint8 WildBattlePetLevelMax;
    uint8 WindSettingsID;
    std::array<int32, 2> Flags;
    std::array<uint16, 4> LiquidTypeID;

    EnumFlag<AreaFlags> GetFlags() const { return static_cast<AreaFlags>(Flags[0]); }
    EnumFlag<AreaFlags2> GetFlags2() const { return static_cast<AreaFlags2>(Flags[1]); }
    EnumFlag<AreaMountFlags> GetMountFlags() const { return static_cast<AreaMountFlags>(MountFlags); }

    bool IsSanctuary() const
    {
        return GetFlags().HasFlag(AreaFlags::NoPvP);
    }
};

// structure for AreaTrigger.db2
struct AreaTriggerEntry
{
    LocalizedString Message;
    DBCPosition3D Pos;
    uint32 ID;
    uint16 ContinentID;
    int32 PhaseUseFlags;
    int16 PhaseID;
    int16 PhaseGroupID;
    float Radius;
    float BoxLength;
    float BoxWidth;
    float BoxHeight;
    float BoxYaw;
    int8 ShapeType;
    int16 ShapeID;
    int32 AreaTriggerActionSetID;
    int8 Flags;

    AreaTriggerShapeType GetShapeType() const { return static_cast<AreaTriggerShapeType>(ShapeType); }
};

// structure for AreaTriggerActionSet.db2
struct AreaTriggerActionSetEntry
{
    uint32 ID;
    int16 Flags;

    EnumFlag<AreaTriggerActionSetFlag> GetFlags() const { return static_cast<AreaTriggerActionSetFlag>(Flags); }
};

// structure for ArmorLocation.db2
struct ArmorLocationEntry
{
    uint32 ID;
    float Clothmodifier;
    float Leathermodifier;
    float Chainmodifier;
    float Platemodifier;
    float Modifier;
};

// structure for AuctionHouse.db2
struct AuctionHouseEntry
{
    uint32 ID;
    LocalizedString Name;
    uint16 FactionID;                                               // id of faction.dbc for player factions associated with city
    uint8 DepositRate;
    uint8 ConsignmentRate;
};

// structure for BankBagSlotPrices.db2
struct BankBagSlotPricesEntry
{
    uint32 ID;
    uint32 Cost;
};

// structure for BannedAddons.db2
struct BannedAddonsEntry
{
    uint32 ID;
    char const* Name;
    char const* Version;
    uint8 Flags;
};

// structure for BarberShopStyle.db2
struct BarberShopStyleEntry
{
    LocalizedString DisplayName;
    LocalizedString Description;
    uint32 ID;
    uint8 Type;                                                     // value 0 -> hair, value 2 -> facialhair
    float CostModifier;
    uint8 Race;
    uint8 Sex;
    uint8 Data;                                                     // real ID to hair/facial hair
};

// structure for BattlePetAbility.db2
struct BattlePetAbilityEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    int32 IconFileDataID;
    int8 PetTypeEnum;
    uint32 Cooldown;
    uint16 BattlePetVisualID;
    uint8 Flags;
};

// structure for BattlePetBreedQuality.db2
struct BattlePetBreedQualityEntry
{
    uint32 ID;
    float StateMultiplier;
    uint8 QualityEnum;
};

// structure for BattlePetBreedState.db2
struct BattlePetBreedStateEntry
{
    uint32 ID;
    uint8 BattlePetStateID;
    uint16 Value;
    uint32 BattlePetBreedID;
};

// structure for BattlePetSpecies.db2
struct BattlePetSpeciesEntry
{
    LocalizedString Description;
    LocalizedString SourceText;
    uint32 ID;
    int32 CreatureID;
    int32 SummonSpellID;
    int32 IconFileDataID;
    int8 PetTypeEnum;
    int32 Flags;
    int8 SourceTypeEnum;
    int32 CardUIModelSceneID;
    int32 LoadoutUIModelSceneID;

    EnumFlag<BattlePetSpeciesFlags> GetFlags() const { return static_cast<BattlePetSpeciesFlags>(Flags); }
};

// structure for BattlePetSpeciesState.db2
struct BattlePetSpeciesStateEntry
{
    uint32 ID;
    uint8 BattlePetStateID;
    int32 Value;
    uint32 BattlePetSpeciesID;
};

// structure for BattlemasterList.db2
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
    int32 MaxPlayers;
    int8 GroupsAllowed;
    int8 MaxGroupSize;
    int16 HolidayWorldState;
    int8 Flags;
    int32 IconFileDataID;
    int32 RequiredPlayerConditionID;
    int32 Unknown1153_0;
    int32 Unknown1153_1;

    EnumFlag<BattlemasterListFlags> GetFlags() const { return static_cast<BattlemasterListFlags>(Flags); }
};

// structure for BattlemasterListXMap.db2
struct BattlemasterListXMapEntry
{
    uint32 ID;
    int32 MapID;
    uint32 BattlemasterListID;
};

#define MAX_BROADCAST_TEXT_EMOTES 3

// structure for BroadcastText.db2
struct BroadcastTextEntry
{
    LocalizedString Text;
    LocalizedString Text1;
    uint32 ID;
    int32 LanguageID;
    int32 ConditionID;
    uint16 EmotesID;
    uint16 Flags;
    uint32 ChatBubbleDurationMs;
    int32 VoiceOverPriorityID;
    std::array<uint32, 2> SoundKitID;
    std::array<uint16, MAX_BROADCAST_TEXT_EMOTES> EmoteID;
    std::array<uint16, MAX_BROADCAST_TEXT_EMOTES> EmoteDelay;
};

// structure for Cfg_Categories.db2
struct Cfg_CategoriesEntry
{
    uint32 ID;
    LocalizedString Name;
    uint16 LocaleMask;
    uint8 CreateCharsetMask;
    uint8 ExistingCharsetMask;
    uint8 Flags;
    int8 Order;

    EnumFlag<CfgCategoriesCharsets> GetCreateCharsetMask() const { return static_cast<CfgCategoriesCharsets>(CreateCharsetMask); }
    EnumFlag<CfgCategoriesCharsets> GetExistingCharsetMask() const { return static_cast<CfgCategoriesCharsets>(ExistingCharsetMask); }
    EnumFlag<CfgCategoriesFlags> GetFlags() const { return static_cast<CfgCategoriesFlags>(Flags); }
};

// structure for Cfg_Regions.db2
struct Cfg_RegionsEntry
{
    uint32 ID;
    char const* Tag;
    uint16 RegionID;
    uint32 Raidorigin;                                              // Date of first raid reset, all other resets are calculated as this date plus interval
    uint8 RegionGroupMask;
    uint32 ChallengeOrigin;
};

// structure for CharTitles.db2
struct CharTitlesEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Name1;
    int16 MaskID;
    int8 Flags;
};

// structure for CharacterLoadout.db2
struct CharacterLoadoutEntry
{
    Trinity::RaceMask<int64> RaceMask;
    uint32 ID;
    int8 ChrClassID;
    int32 Purpose;
    uint8 ItemContext;

    bool IsForNewCharacter() const { return Purpose == 9; }
};

// structure for CharacterLoadoutItem.db2
struct CharacterLoadoutItemEntry
{
    uint32 ID;
    uint16 CharacterLoadoutID;
    uint32 ItemID;
};

// structure for ChatChannels.db2
struct ChatChannelsEntry
{
    LocalizedString Name;
    LocalizedString Shortcut;
    uint32 ID;
    int32 Flags;
    int8 FactionGroup;
    int32 Ruleset;

    EnumFlag<ChatChannelFlags> GetFlags() const { return static_cast<ChatChannelFlags>(Flags); }
    ChatChannelRuleset GetRuleset() const { return static_cast<ChatChannelRuleset>(Ruleset); }
};

// structure for ChrClassUIDisplay.db2
struct ChrClassUIDisplayEntry
{
    uint32 ID;
    uint8 ChrClassesID;
    uint32 AdvGuidePlayerConditionID;
    uint32 SplashPlayerConditionID;
};

// structure for ChrClasses.db2
struct ChrClassesEntry
{
    LocalizedString Name;
    char const* Filename;
    LocalizedString NameMale;
    LocalizedString NameFemale;
    char const* PetNameToken;
    uint32 ID;
    uint32 CreateScreenFileDataID;
    uint32 SelectScreenFileDataID;
    uint32 IconFileDataID;
    uint32 LowResScreenFileDataID;
    int32 Flags;
    int32 StartingLevel;
    uint32 SpellTextureBlobFileDataID;
    uint32 ArmorTypeMask;
    uint16 CinematicSequenceID;
    uint16 DefaultSpec;
    uint8 HasStrengthAttackBonus;
    uint8 PrimaryStatPriority;
    int8 DisplayPower;
    uint8 RangedAttackPowerPerAgility;
    uint8 AttackPowerPerAgility;
    uint8 AttackPowerPerStrength;
    uint8 SpellClassSet;
    uint8 RolesMask;
    uint8 DamageBonusStat;
    uint8 HasRelicSlot;
};

// structure for ChrClassesXPowerTypes.db2
struct ChrClassesXPowerTypesEntry
{
    uint32 ID;
    int8 PowerType;
    uint32 ClassID;
};

// structure for ChrCustomizationChoice.db2
struct ChrCustomizationChoiceEntry
{
    LocalizedString Name;
    uint32 ID;
    uint32 ChrCustomizationOptionID;
    int32 ChrCustomizationReqID;
    int32 ChrCustomizationVisReqID;
    uint16 OrderIndex;
    uint16 UiOrderIndex;
    int32 Flags;
    int32 AddedInPatch;
    int32 SoundKitID;
    std::array<int32, 2> SwatchColor;
};

// structure for ChrCustomizationDisplayInfo.db2
struct ChrCustomizationDisplayInfoEntry
{
    uint32 ID;
    int32 SpellShapeshiftFormID;
    int32 CreatureDisplayInfoID;
    float BarberShopMinCameraDistance;
    float BarberShopHeightOffset;
    float BarberShopCameraZoomOffset;
};

// structure for ChrCustomizationElement.db2
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
    int32 ChrCustomizationVoiceID;
    int32 AnimKitID;
    int32 ParticleColorID;
    int32 ChrCustGeoComponentLinkID;
};

// structure for ChrCustomizationOption.db2
struct ChrCustomizationOptionEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 SecondaryID;
    int32 Flags;
    uint32 ChrModelID;
    int32 OrderIndex;
    int32 ChrCustomizationCategoryID;
    int32 OptionType;
    float BarberShopCostModifier;
    int32 ChrCustomizationID;
    int32 ChrCustomizationReqID;
    int32 SecondaryOrderIndex;
};

// structure for ChrCustomizationReq.db2
struct ChrCustomizationReqEntry
{
    Trinity::RaceMask<int64> RaceMask;
    LocalizedString ReqSource;
    uint32 ID;
    int32 Flags;
    int32 ClassMask;
    int32 AchievementID;
    int32 QuestID;
    int32 OverrideArchive;                                          // -1: allow any, otherwise must match OverrideArchive cvar
    int32 ItemModifiedAppearanceID;

    EnumFlag<ChrCustomizationReqFlag> GetFlags() const { return static_cast<ChrCustomizationReqFlag>(Flags); }
};

// structure for ChrCustomizationReqChoice.db2
struct ChrCustomizationReqChoiceEntry
{
    uint32 ID;
    int32 ChrCustomizationChoiceID;
    uint32 ChrCustomizationReqID;
};

// structure for ChrModel.db2
struct ChrModelEntry
{
    DBCPosition3D FaceCustomizationOffset;
    DBCPosition3D CustomizeOffset;
    uint32 ID;
    int8 Sex;
    uint32 DisplayID;
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
    float BarberShopCameraRotationFacing;
    float BarberShopCameraRotationOffset;
};

// structure for ChrRaceXChrModel.db2
struct ChrRaceXChrModelEntry
{
    uint32 ID;
    uint32 ChrRacesID;
    int32 ChrModelID;
    int32 Sex;
    int32 AllowedTransmogSlots;
};

// structure for ChrRaces.db2
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
    uint32 MaleDisplayID;
    uint32 FemaleDisplayID;
    uint32 HighResMaleDisplayID;
    uint32 HighResFemaleDisplayID;
    int32 ResSicknessSpellID;
    int32 SplashSoundID;
    int32 CreateScreenFileDataID;
    int32 SelectScreenFileDataID;
    int32 LowResScreenFileDataID;
    std::array<uint32, 3> AlteredFormStartVisualKitID;
    std::array<uint32, 3> AlteredFormFinishVisualKitID;
    int32 HeritageArmorAchievementID;
    int32 StartingLevel;
    int32 UiDisplayOrder;
    int32 PlayableRaceBit;
    int32 FemaleSkeletonFileDataID;
    int32 MaleSkeletonFileDataID;
    int32 HelmetAnimScalingRaceID;
    int32 TransmogrifyDisabledSlotMask;
    std::array<float, 3> AlteredFormCustomizeOffsetFallback;
    float AlteredFormCustomizeRotationFallback;
    std::array<float, 3> Unknown901_0;
    std::array<float, 3> Unknown901_1;
    int16 FactionID;
    int16 CinematicSequenceID;
    int8 BaseLanguage;
    int8 CreatureType;
    int8 Alliance;
    int8 RaceRelated;
    int8 UnalteredVisualRaceID;
    int8 DefaultClassID;
    int8 NeutralRaceID;
    int8 MaleModelFallbackRaceID;
    int8 MaleModelFallbackSex;
    int8 FemaleModelFallbackRaceID;
    int8 FemaleModelFallbackSex;
    int8 MaleTextureFallbackRaceID;
    int8 MaleTextureFallbackSex;
    int8 FemaleTextureFallbackRaceID;
    int8 FemaleTextureFallbackSex;
    int8 UnalteredVisualCustomizationRaceID;

    EnumFlag<ChrRacesFlag> GetFlags() const { return static_cast<ChrRacesFlag>(Flags); }
};

// structure for CinematicCamera.db2
struct CinematicCameraEntry
{
    uint32 ID;
    DBCPosition3D Origin;                                   // Position in map used for basis for M2 co-ordinates
    uint32 SoundID;                                         // Sound ID       (voiceover for cinematic)
    float OriginFacing;                                     // Orientation in map used for basis for M2 co
    uint32 FileDataID;                                      // Model
};

// structure for CinematicSequences.db2
struct CinematicSequencesEntry
{
    uint32 ID;
    uint32 SoundID;
    std::array<uint16, 8> Camera;
};

// structure for ConditionalChrModel.db2
struct ConditionalChrModelEntry
{
    uint32 ID;
    uint32 ChrModelID;
    int32 ChrCustomizationReqID;
    int32 PlayerConditionID;
    int32 Flags;
    int32 ChrCustomizationCategoryID;
};

// structure for ConditionalContentTuning.db2
struct ConditionalContentTuningEntry
{
    uint32 ID;
    int32 OrderIndex;
    int32 RedirectContentTuningID;
    int32 RedirectFlag;
    uint32 ParentContentTuningID;
};

// structure for ContentTuning.db2
struct ContentTuningEntry
{
    uint32 ID;
    int32 MinLevel;
    int32 MaxLevel;
    int32 Flags;
    int32 ExpectedStatModID;
    int32 DifficultyESMID;

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

// structure for ConversationLine.db2
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

//struct CreatureDifficultyEntry
//{
//    uint32 ID;
//    int8 ExpansionID;
//    int8 MinLevel;
//    int8 MaxLevel;
//    uint16 FactionID;
//    int32 ContentTuningID;
//    int32 Flags[8];
//    uint32 CreatureID;
//};

// structure for CreatureDisplayInfo.db2
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
    int32 Flags;
    int32 StateSpellVisualKitID;
    float PlayerOverrideScale;
    float PetInstanceScale;                                         // scale of not own player pets inside dungeons/raids/scenarios
    int8 UnarmedWeaponType;
    int32 MountPoofSpellVisualKitID;
    int32 DissolveEffectID;
    int8 Gender;
    int32 DissolveOutEffectID;
    int8 CreatureModelMinLod;
    uint16 Unknown1154;
    std::array<int32, 4> TextureVariationFileDataID;
};

// structure for CreatureDisplayInfoExtra.db2
struct CreatureDisplayInfoExtraEntry
{
    uint32 ID;
    int8 DisplayRaceID;
    int8 DisplaySexID;
    int8 DisplayClassID;
    int8 SkinID;
    int8 FaceID;
    int8 HairStyleID;
    int8 HairColorID;
    int8 FacialHairID;
    int8 Flags;
    int32 BakeMaterialResourcesID;
    int32 HDBakeMaterialResourcesID;
    std::array<uint8, 3> CustomDisplayOption;
};

// structure for CreatureFamily.db2
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
    int32 CategoryEnumID;
    int32 IconFileID;
    std::array<int16, 2> SkillLine;
};

// structure for CreatureModelData.db2
struct CreatureModelDataEntry
{
    uint32 ID;
    std::array<float, 6> GeoBox;
    int32 Flags;
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
    uint16 Unknown1154;

    EnumFlag<CreatureModelDataFlags> GetFlags() const { return static_cast<CreatureModelDataFlags>(Flags); }
};

// structure for CreatureType.db2
struct CreatureTypeEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 Flags;
};

// structure for Criteria.db2
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
        // CriteriaType::EnterTopLevelArea                          = 225
        // CriteriaType::LeaveTopLevelArea                          = 226
        int32 ZoneID;

        // CriteriaType::CurrencyGained                             = 12
        // CriteriaType::ObtainAnyItemWithCurrencyValue             = 229
        // CriteriaType::ReachRenownLevel                           = 261
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

        // CriteriaType::LearnTaxiNode                              = 262
        int32 TaxiNodesID;
    } Asset;
    uint32 ModifierTreeId;
    int32 StartEvent;
    int32 StartAsset;
    uint16 StartTimer;
    int32 FailEvent;
    int32 FailAsset;
    int32 Flags;
    int16 EligibilityWorldStateID;
    int8 EligibilityWorldStateValue;

    EnumFlag<CriteriaFlags> GetFlags() const { return static_cast<CriteriaFlags>(Flags); }
};

// structure for CriteriaTree.db2
struct CriteriaTreeEntry
{
    uint32 ID;
    LocalizedString Description;
    uint32 Parent;
    uint32 Amount;
    int32 Operator;
    uint32 CriteriaID;
    int32 OrderIndex;
    int32 Flags;

    EnumFlag<CriteriaTreeFlags> GetFlags() const { return static_cast<CriteriaTreeFlags>(Flags); }
};

// structure for CurrencyContainer.db2
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

// structure for CurrencyTypes.db2
struct CurrencyTypesEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    uint8 CategoryID;
    int32 InventoryIconFileID;
    uint32 SpellWeight;
    uint8 SpellCategory;
    uint32 MaxQty;
    uint32 MaxEarnablePerWeek;
    int8 Quality;
    int32 FactionID;
    int32 AwardConditionID;
    int32 MaxQtyWorldStateID;
    float Unknown1154;
    std::array<int32, 2> Flags;

    EnumFlag<CurrencyTypesFlags> GetFlags() const { return static_cast<CurrencyTypesFlags>(Flags[0]); }
    EnumFlag<CurrencyTypesFlagsB> GetFlagsB() const { return static_cast<CurrencyTypesFlagsB>(Flags[1]); }

    // Helpers
    int32 GetScaler() const
    {
        return GetFlags().HasFlag(CurrencyTypesFlags::_100_Scaler) ? 100 : 1;
    }

    bool HasMaxEarnablePerWeek() const
    {
        return MaxEarnablePerWeek || GetFlags().HasFlag(CurrencyTypesFlags::ComputedWeeklyMaximum);
    }

    bool HasMaxQuantity(bool onLoad = false, bool onUpdateVersion = false) const
    {
        if (onLoad && GetFlags().HasFlag(CurrencyTypesFlags::IgnoreMaxQtyOnLoad))
           return false;

        if (onUpdateVersion && GetFlags().HasFlag(CurrencyTypesFlags::UpdateVersionIgnoreMax))
           return false;

        return MaxQty || GetFlags().HasFlag(CurrencyTypesFlags::DynamicMaximum);
    }

    bool HasTotalEarned() const
    {
        return GetFlagsB().HasFlag(CurrencyTypesFlagsB::UseTotalEarnedForEarned);
    }

    bool IsAlliance() const
    {
        return GetFlags().HasFlag(CurrencyTypesFlags::IsAllianceOnly);
    }

    bool IsHorde() const
    {
        return GetFlags().HasFlag(CurrencyTypesFlags::IsHordeOnly);
    }

    bool IsSuppressingChatLog(bool onUpdateVersion = false) const
    {
        if ((onUpdateVersion && GetFlags().HasFlag(CurrencyTypesFlags::SuppressChatMessageOnVersionChange)) ||
            GetFlags().HasFlag(CurrencyTypesFlags::SuppressChatMessages))
            return true;

        return false;
    }

    bool IsTrackingQuantity() const
    {
        return GetFlags().HasFlag(CurrencyTypesFlags::TrackQuantity);
    }
};

// structure for Curve.db2
struct CurveEntry
{
    uint32 ID;
    uint8 Type;
    uint8 Flags;
};

// structure for CurvePoint.db2
struct CurvePointEntry
{
    DBCPosition2D Pos;
    DBCPosition2D PreSLSquishPos;
    uint32 ID;
    uint32 CurveID;
    uint8 OrderIndex;
};

// structure for DestructibleModelData.db2
struct DestructibleModelDataEntry
{
    uint32 ID;
    int8 State0ImpactEffectDoodadSet;
    uint8 State0AmbientDoodadSet;
    uint32 State1Wmo;
    int8 State1DestructionDoodadSet;
    int8 State1ImpactEffectDoodadSet;
    uint8 State1AmbientDoodadSet;
    uint32 State2Wmo;
    int8 State2DestructionDoodadSet;
    int8 State2ImpactEffectDoodadSet;
    uint8 State2AmbientDoodadSet;
    uint32 State3Wmo;
    uint8 State3InitDoodadSet;
    uint8 State3AmbientDoodadSet;
    uint8 EjectDirection;
    uint8 DoNotHighlight;
    uint32 State0Wmo;
    uint8 HealEffect;
    uint16 HealEffectSpeed;
    int8 State0NameSet;
    int8 State1NameSet;
    int8 State2NameSet;
    int8 State3NameSet;
};

// structure for Difficulty.db2
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
    uint8 Flags;
    uint8 ItemContext;
    uint8 ToggleDifficultyID;
    uint16 GroupSizeHealthCurveID;
    uint16 GroupSizeDmgCurveID;
    uint16 GroupSizeSpellPointsCurveID;
    int32 Unknown1154;
};

// structure for DungeonEncounter.db2
struct DungeonEncounterEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 MapID;
    int32 DifficultyID;
    int32 OrderIndex;
    int32 CompleteWorldStateID;
    int8 Bit;
    int32 Flags;
    int32 SpellIconFileID;
    int32 Faction;
};

// structure for DurabilityCosts.db2
struct DurabilityCostsEntry
{
    uint32 ID;
    std::array<uint16, 21> WeaponSubClassCost;
    std::array<uint16, 8> ArmorSubClassCost;
};

// structure for DurabilityQuality.db2
struct DurabilityQualityEntry
{
    uint32 ID;
    float Data;
};

// structure for Emotes.db2
struct EmotesEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    char const* EmoteSlashCommand;
    int16 AnimID;
    int32 EmoteFlags;
    int32 EmoteSpecProc;
    uint32 EmoteSpecProcParam;
    uint32 EventSoundID;
    uint32 SpellVisualKitID;
    int32 ClassMask;
};

// structure for EmotesText.db2
struct EmotesTextEntry
{
    uint32 ID;
    char const* Name;
    uint16 EmoteID;
};

// structure for EmotesTextSound.db2
struct EmotesTextSoundEntry
{
    uint32 ID;
    uint8 RaceID;
    uint8 ClassID;
    uint8 SexID;
    uint32 SoundID;
    uint32 EmotesTextID;
};

// structure for ExpectedStat.db2
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

// structure for ExpectedStatMod.db2
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

// structure for Faction.db2
struct FactionEntry
{
    std::array<Trinity::RaceMask<int64>, 4> ReputationRaceMask;
    LocalizedString Name;
    LocalizedString Description;
    uint32 ID;
    int16 ReputationIndex;
    uint16 ParentFactionID;
    uint8 Expansion;
    uint8 FriendshipRepID;
    int32 Flags;
    uint16 ParagonFactionID;
    int32 RenownFactionID;
    int32 RenownCurrencyID;
    std::array<int16, 4> ReputationClassMask;
    std::array<uint16, 4> ReputationFlags;
    std::array<int32, 4> ReputationBase;
    std::array<int32, 4> ReputationMax;
    std::array<float, 2> ParentFactionMod;            // Faction outputs rep * ParentFactionModOut as spillover reputation
    std::array<uint8, 2> ParentFactionCap;            // The highest rank the faction will profit from incoming spillover

    bool CanHaveReputation() const
    {
        return ReputationIndex >= 0;
    }
};

#define MAX_FACTION_RELATIONS 8

// structure for FactionTemplate.db2
struct FactionTemplateEntry
{
    uint32 ID;
    uint16 Faction;
    int32 Flags;
    uint8 FactionGroup;
    uint8 FriendGroup;
    uint8 EnemyGroup;
    std::array<uint16, MAX_FACTION_RELATIONS> Enemies;
    std::array<uint16, MAX_FACTION_RELATIONS> Friend;

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

// structure for FriendshipRepReaction.db2
struct FriendshipRepReactionEntry
{
    uint32 ID;
    LocalizedString Reaction;
    uint8 FriendshipRepID;
    uint16 ReactionThreshold;
};

// structure for FriendshipReputation.db2
struct FriendshipReputationEntry
{
    LocalizedString Description;
    uint32 ID;
    int32 Unknown341_0;
    int32 Unknown341_1;
};

// structure for GameObjectArtKit.db2
struct GameObjectArtKitEntry
{
    uint32 ID;
    int32 AttachModelFileID;
    std::array<int32, 3> TextureVariationFileID;
};

// structure for GameObjectDisplayInfo.db2
struct GameObjectDisplayInfoEntry
{
    uint32 ID;
    char const* ModelName;
    DBCPosition3D GeoBoxMin;
    DBCPosition3D GeoBoxMax;
    int32 FileDataID;
    int16 ObjectEffectPackageID;
    float OverrideLootEffectScale;
    float OverrideNameScale;
    uint16 Unknown1154;
};

// structure for GameObjects.db2
struct GameObjectsEntry
{
    LocalizedString Name;
    DBCPosition3D Pos;
    std::array<float, 4> Rot;
    uint32 ID;
    uint16 OwnerID;
    uint32 DisplayID;
    float Scale;
    uint8 TypeID;
    int32 PhaseUseFlags;
    uint16 PhaseID;
    uint16 PhaseGroupID;
    uint16 Unknown1100;
    std::array<int32, 8> PropValue;
};

// structure for GemProperties.db2
struct GemPropertiesEntry
{
    uint32 ID;
    uint16 EnchantID;
    int32 Type;
    uint16 MinItemLevel;
};

// structure for GlyphBindableSpell.db2
struct GlyphBindableSpellEntry
{
    uint32 ID;
    int32 SpellID;
    uint32 GlyphPropertiesID;
};

// structure for GlyphSlot.db2
struct GlyphSlotEntry
{
    uint32 ID;
    int32 Tooltip;
    uint32 Type;
};

// structure for GlyphProperties.db2
struct GlyphPropertiesEntry
{
    uint32 ID;
    uint32 SpellID;
    uint8 GlyphType;
    uint8 GlyphExclusiveCategoryID;
    int32 SpellIconFileDataID;
    uint32 GlyphSlotFlags;
};

// structure for GlyphRequiredSpec.db2
struct GlyphRequiredSpecEntry
{
    uint32 ID;
    uint16 ChrSpecializationID;
    uint32 GlyphPropertiesID;
};

// structure for GossipNPCOption.db2
struct GossipNPCOptionEntry
{
    uint32 ID;
    int32 GossipNpcOption;
    int32 LFGDungeonsID;
    int32 TrainerID;
    int32 Unknown341_0;
    int32 Unknown341_1;
    int32 Unknown341_2;
    int32 Unknown341_3;
    int32 Unknown341_4;
    int32 Unknown341_5;
    int32 Unknown341_6;
    int32 Unknown341_7;
    int32 GossipOptionID;
};

// structure for GuildColorBackground.db2
struct GuildColorBackgroundEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Blue;
    uint8 Green;
};

// structure for GuildColorBorder.db2
struct GuildColorBorderEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Blue;
    uint8 Green;
};

// structure for GuildColorEmblem.db2
struct GuildColorEmblemEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Blue;
    uint8 Green;
};

// structure for GuildPerkSpells.db2
struct GuildPerkSpellsEntry
{
    uint32 ID;
    int32 SpellID;
};

// structure for Heirloom.db2
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
    std::array<int32, 6> UpgradeItemID;
    std::array<uint16, 6> UpgradeItemBonusListID;
};

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 16
#define MAX_HOLIDAY_FLAGS 10

// structure for Holidays.db2
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
    uint32 WorldStateExpressionID;
    std::array<uint16, MAX_HOLIDAY_DURATIONS> Duration;
    std::array<uint32, MAX_HOLIDAY_DATES> Date;                     // dates in unix time starting at January, 1, 2000
    std::array<uint8, MAX_HOLIDAY_FLAGS> CalendarFlags;
    std::array<int32, 3> TextureFileDataID;
};

// structure for ImportPriceArmor.db2
struct ImportPriceArmorEntry
{
    uint32 ID;
    float ClothModifier;
    float LeatherModifier;
    float ChainModifier;
    float PlateModifier;
};

// structure for ImportPriceQuality.db2
struct ImportPriceQualityEntry
{
    uint32 ID;
    float Data;
};

// structure for ImportPriceShield.db2
struct ImportPriceShieldEntry
{
    uint32 ID;
    float Data;
};

// structure for ImportPriceWeapon.db2
struct ImportPriceWeaponEntry
{
    uint32 ID;
    float Data;
};

// structure for Item.db2
struct ItemEntry
{
    uint32 ID;
    uint8 ClassID;
    uint8 SubclassID;
    uint8 Material;
    int8 InventoryType;
    int32 RequiredLevel;
    uint8 SheatheType;
    uint16 RandomSelect;
    uint16 ItemRandomSuffixGroupID;
    int8 SoundOverrideSubclassID;
    uint16 ScalingStatDistributionID;
    int32 IconFileDataID;
    uint8 ItemGroupSoundsID;
    int32 ContentTuningID;
    uint32 MaxDurability;
    uint8 AmmunitionType;
    int32 ScalingStatValue;
    std::array<uint8, 5> DamageType;
    std::array<int32, 7> Resistances;
    std::array<int32, 5> MinDamage;
    std::array<int32, 5> MaxDamage;
};

// structure for ItemAppearance.db2
struct ItemAppearanceEntry
{
    uint32 ID;
    int8 DisplayType;
    int32 ItemDisplayInfoID;
    int32 DefaultIconFileDataID;
    int32 UiOrder;
};

// structure for ItemArmorQuality.db2
struct ItemArmorQualityEntry
{
    uint32 ID;
    std::array<float, 7> Qualitymod;
};

// structure for ItemArmorShield.db2
struct ItemArmorShieldEntry
{
    uint32 ID;
    std::array<float, 7> Quality;
    uint16 ItemLevel;
};

// structure for ItemArmorTotal.db2
struct ItemArmorTotalEntry
{
    uint32 ID;
    int16 ItemLevel;
    float Cloth;
    float Leather;
    float Mail;
    float Plate;
};

// structure for ItemBagFamily.db2
struct ItemBagFamilyEntry
{
    uint32 ID;
    LocalizedString Name;
};

// structure for ItemBonus.db2
struct ItemBonusEntry
{
    uint32 ID;
    std::array<int32, 4> Value;
    uint16 ParentItemBonusListID;
    uint8 Type;
    uint8 OrderIndex;
};

// structure for ItemBonusListLevelDelta.db2
struct ItemBonusListLevelDeltaEntry
{
    int16 ItemLevelDelta;
    uint32 ID;
};

// structure for ItemBonusTreeNode.db2
struct ItemBonusTreeNodeEntry
{
    uint32 ID;
    uint8 ItemContext;
    uint16 ChildItemBonusTreeID;
    uint16 ChildItemBonusListID;
    uint16 ChildItemLevelSelectorID;
    int32 ChildItemBonusListGroupID;
    int32 IblGroupPointsModSetID;
    int32 MinMythicPlusLevel;
    int32 MaxMythicPlusLevel;
    uint32 ParentItemBonusTreeID;
};

// structure for ItemChildEquipment.db2
struct ItemChildEquipmentEntry
{
    uint32 ID;
    int32 ChildItemID;
    uint8 ChildItemEquipSlot;
    uint32 ParentItemID;
};

// structure for ItemClass.db2
struct ItemClassEntry
{
    uint32 ID;
    LocalizedString ClassName;
    int8 ClassID;
    float PriceModifier;
    uint8 Flags;
};

// structure for ItemContextPickerEntry.db2
struct ItemContextPickerEntryEntry
{
    uint32 ID;
    uint8 ItemCreationContext;
    uint8 OrderIndex;
    int32 PVal;
    uint32 Flags;
    uint32 PlayerConditionID;
    uint32 ItemContextPickerID;
};

// structure for ItemCurrencyCost.db2
struct ItemCurrencyCostEntry
{
    uint32 ID;
    uint32 ItemID;
};

// structure for ItemDamageAmmo.db2
struct ItemDamageAmmoEntry
{
    uint32 ID;
    uint16 ItemLevel;
    std::array<float, 7> Quality;
};

// structure for ItemDamageOneHand.db2
struct ItemDamageOneHandEntry
{
    uint32 ID;
    uint16 ItemLevel;
    std::array<float, 7> Quality;
};

// structure for ItemDamageOneHandCaster.db2
struct ItemDamageOneHandCasterEntry
{
    uint32 ID;
    uint16 ItemLevel;
    std::array<float, 7> Quality;
};

// structure for ItemDamageTwoHand.db2
struct ItemDamageTwoHandEntry
{
    uint32 ID;
    uint16 ItemLevel;
    std::array<float, 7> Quality;
};

// structure for ItemDamageTwoHandCaster.db2
struct ItemDamageTwoHandCasterEntry
{
    uint32 ID;
    uint16 ItemLevel;
    std::array<float, 7> Quality;
};

// structure for ItemDisenchantLoot.db2
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

// structure for ItemEffect.db2
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
    uint32 ParentItemID;
};

#define MAX_ITEM_EXT_COST_ITEMS         5
#define MAX_ITEM_EXT_COST_CURRENCIES    5

// structure for ItemExtendedCost.db2
struct ItemExtendedCostEntry
{
    uint32 ID;
    uint16 RequiredArenaRating;
    int8 ArenaBracket;                                             // arena slot restrictions (min slot value)
    uint8 Flags;
    uint8 MinFactionID;
    int32 MinReputation;
    uint8 RequiredAchievement;                                      // required personal arena rating
    std::array<int32, MAX_ITEM_EXT_COST_ITEMS> ItemID;              // required item id
    std::array<uint16, MAX_ITEM_EXT_COST_ITEMS> ItemCount;          // required count of 1st item
    std::array<uint16, MAX_ITEM_EXT_COST_CURRENCIES> CurrencyID;    // required curency id
    std::array<uint32, MAX_ITEM_EXT_COST_CURRENCIES> CurrencyCount; // required curency count
};

// structure for ItemLevelSelector.db2
struct ItemLevelSelectorEntry
{
    uint32 ID;
    uint16 MinItemLevel;
    uint16 ItemLevelSelectorQualitySetID;
};

// structure for ItemLevelSelectorQuality.db2
struct ItemLevelSelectorQualityEntry
{
    uint32 ID;
    int32 QualityItemBonusListID;
    int8 Quality;
    uint32 ParentILSQualitySetID;
};

// structure for ItemLevelSelectorQualitySet.db2
struct ItemLevelSelectorQualitySetEntry
{
    uint32 ID;
    int16 IlvlRare;
    int16 IlvlEpic;
};

// structure for ItemLimitCategory.db2
struct ItemLimitCategoryEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 Quantity;
    uint8 Flags;
};

// structure for ItemLimitCategoryCondition.db2
struct ItemLimitCategoryConditionEntry
{
    uint32 ID;
    int8 AddQuantity;
    uint32 PlayerConditionID;
    uint32 ParentItemLimitCategoryID;
};

// structure for ItemModifiedAppearance.db2
struct ItemModifiedAppearanceEntry
{
    uint32 ID;
    uint32 ItemID;
    int32 ItemAppearanceModifierID;
    int32 ItemAppearanceID;
    int32 OrderIndex;
    uint8 TransmogSourceTypeEnum;
};

// structure for ItemModifiedAppearanceExtra.db2
struct ItemModifiedAppearanceExtraEntry
{
    uint32 ID;
    int32 IconFileDataID;
    int32 UnequippedIconFileDataID;
    uint8 SheatheType;
    int8 DisplayWeaponSubclassID;
    int8 DisplayInventoryType;
};

// structure for ItemNameDescription.db2
struct ItemNameDescriptionEntry
{
    uint32 ID;
    LocalizedString Description;
    int32 Color;
};

// structure for ItemPriceBase.db2
struct ItemPriceBaseEntry
{
    uint32 ID;
    uint16 ItemLevel;
    float Armor;
    float Weapon;
};

// structure for ItemReforge.db2
struct ItemReforgeEntry
{
    uint32 ID;
    uint16 SourceStat;
    float SourceMultiplier;
    uint16 TargetStat;
    float TargetMultiplier;
    uint16 LegacyItemReforgeID;
};

// structure for ItemSearchName.db2
struct ItemSearchNameEntry
{
    Trinity::RaceMask<int64> AllowableRace;
    LocalizedString Display;
    uint32 ID;
    uint8 OverallQualityID;
    int8 ExpansionID;
    uint16 MinFactionID;
    int32 MinReputation;
    int32 AllowableClass;
    int8 RequiredLevel;
    uint16 RequiredSkill;
    uint16 RequiredSkillRank;
    uint32 RequiredAbility;
    uint16 ItemLevel;
    std::array<int32, 5> Flags;
};

#define MAX_ITEM_SET_ITEMS 17

// structure for ItemSet.db2
struct ItemSetEntry
{
    uint32 ID;
    LocalizedString Name;
    uint32 SetFlags;
    uint32 RequiredSkill;
    uint16 RequiredSkillRank;
    std::array<uint32, MAX_ITEM_SET_ITEMS> ItemID;
};

// structure for ItemSetSpell.db2
struct ItemSetSpellEntry
{
    uint32 ID;
    uint16 ChrSpecID;
    uint32 SpellID;
    uint8 Threshold;
    uint32 ItemSetID;
};

// structure for ItemSparse.db2
struct ItemSparseEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> AllowableRace;
    LocalizedString Description;
    LocalizedString Display3;
    LocalizedString Display2;
    LocalizedString Display1;
    LocalizedString Display;
    float DmgVariance;
    uint32 DurationInInventory;
    float QualityModifier;
    uint32 BagFamily;
    int32 StartQuestID;
    float ItemRange;
    std::array<float, MAX_ITEM_PROTO_STATS> StatPercentageOfSocket;
    std::array<int32, MAX_ITEM_PROTO_STATS> StatPercentEditor;
    std::array<int32, MAX_ITEM_PROTO_STATS> Unknown1153;
    std::array<int32, MAX_ITEM_PROTO_STATS> StatModifierBonusStat;
    int32 Stackable;
    int32 MaxCount;
    int32 MinReputation;
    uint32 RequiredAbility;
    uint32 SellPrice;
    uint32 BuyPrice;
    uint32 VendorStackCount;
    float PriceVariance;
    float PriceRandomValue;
    std::array<int32, MAX_ITEM_PROTO_FLAGS> Flags;
    int32 OppositeFactionItemID;
    int32 ModifiedCraftingReagentItemID;
    int32 ContentTuningID;
    int32 PlayerLevelToItemLevelCurveID;
    uint32 MaxDurability;
    uint16 ItemNameDescriptionID;
    uint16 RequiredTransmogHoliday;
    uint16 RequiredHoliday;
    uint16 LimitCategory;
    uint16 GemProperties;
    uint16 SocketMatchEnchantmentID;
    uint16 TotemCategoryID;
    uint16 InstanceBound;
    std::array<uint16, MAX_ITEM_PROTO_ZONES> ZoneBound;
    uint16 ItemSet;
    uint16 LockID;
    uint16 PageID;
    uint16 ItemDelay;
    uint16 MinFactionID;
    uint16 RequiredSkillRank;
    uint16 RequiredSkill;
    uint16 ItemLevel;
    int16 AllowableClass;
    uint16 ItemRandomSuffixGroupID;
    uint16 RandomSelect;
    std::array<uint16, 5> MinDamage;
    std::array<uint16, 5> MaxDamage;
    std::array<int16, 7> Resistances;
    uint16 ScalingStatDistributionID;
    std::array<int16, MAX_ITEM_PROTO_STATS> StatModifierBonusAmount;
    uint8 ExpansionID;
    uint8 ArtifactID;
    uint8 SpellWeight;
    uint8 SpellWeightCategory;
    std::array<uint8, MAX_ITEM_PROTO_SOCKETS> SocketType;
    uint8 SheatheType;
    uint8 Material;
    uint8 PageMaterialID;
    uint8 LanguageID;
    uint8 Bonding;
    uint8 DamageDamageType;
    uint8 ContainerSlots;
    uint8 RequiredPVPMedal;
    uint8 RequiredPVPRank;
    int8 InventoryType;
    int8 OverallQualityID;
    uint8 AmmunitionType;
    int8 RequiredLevel;
};

// structure for ItemXBonusTree.db2
struct ItemXBonusTreeEntry
{
    uint32 ID;
    uint16 ItemBonusTreeID;
    uint32 ItemID;
};

// structure for JournalEncounter.db2
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
    int32 Flags;
    int8 DifficultyMask;
};

// structure for JournalEncounterSection.db2
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
    int32 Flags;
    int32 IconFlags;
    int8 DifficultyMask;
};

// structure for JournalInstance.db2
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
    int32 Flags;
    uint16 AreaID;
};

// structure for JournalTier.db2
struct JournalTierEntry
{
    uint32 ID;
    LocalizedString Name;
};

#define KEYCHAIN_SIZE   32

// structure for Keychain.db2
struct KeychainEntry
{
    uint32 ID;
    std::array<uint8, KEYCHAIN_SIZE> Key;
};

// structure for KeystoneAffix.db2
struct KeystoneAffixEntry
{
    LocalizedString Name;
    LocalizedString Description;
    uint32 ID;
    int32 FiledataID;
};

// structure for LanguageWords.db2
struct LanguageWordsEntry
{
    uint32 ID;
    char const* Word;
    uint8 LanguageID;
};

// structure for Languages.db2
struct LanguagesEntry
{
    LocalizedString Name;
    uint32 ID;
    int32 Flags;
    int32 UiTextureKitID;
    int32 UiTextureKitElementCount;
    int32 LearningCurveID;
};

// structure for LFGDungeons.db2
struct LFGDungeonsEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Description;
    uint8 MinLevel;
    uint16 MaxLevel;
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
    uint32 RequiredPlayerConditionID;
    uint8 TargetLevel;
    uint8 TargetLevelMin;
    uint16 TargetLevelMax;
    uint16 RandomID;
    uint16 ScenarioID;
    uint16 FinalEncounterID;
    uint8 CountTank;
    uint8 CountHealer;
    uint8 CountDamage;
    uint8 MinCountTank;
    uint8 MinCountHealer;
    uint8 MinCountDamage;
    uint8 MaxPremadeCountTank;
    uint8 MaxPremadeCountHealer;
    uint8 MaxPremadeCountDamage;
    uint16 BonusReputationAmount;
    uint16 MentorItemLevel;
    uint8 MentorCharLevel;
    std::array<int32, 2> Flags;

    uint32 Entry() const { return ID + (TypeID << 24); }
};

// structure for Light.db2
struct LightEntry
{
    uint32 ID;
    DBCPosition3D GameCoords;
    float GameFalloffStart;
    float GameFalloffEnd;
    int16 ContinentID;
    std::array<uint16, 8> LightParamsID;
};

// structure for LiquidType.db2
struct LiquidTypeEntry
{
    uint32 ID;
    char const* Name;
    std::array<char const*, 6> Texture;
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
    std::array<uint8, 6> FrameCountTexture;
    std::array<int32, 2> Color;
    std::array<float, 18> Float;
    std::array<uint32, 4> Int;
    std::array<float, 4> Coefficient;
};

// structure for Location.db2
struct LocationEntry
{
    uint32 ID;
    DBCPosition3D Pos;
    std::array<float, 3> Rot;
};

#define MAX_LOCK_CASE 8

// structure for Lock.db2
struct LockEntry
{
    uint32 ID;
    std::array<int32, MAX_LOCK_CASE> Index;
    std::array<uint16, MAX_LOCK_CASE> Skill;
    std::array<uint8, MAX_LOCK_CASE> Type;
    std::array<uint8, MAX_LOCK_CASE> Action;
};

// structure for MailTemplate.db2
struct MailTemplateEntry
{
    uint32 ID;
    LocalizedString Body;
};

// structure for Map.db2
struct MapEntry
{
    uint32 ID;
    char const* Directory;
    LocalizedString MapName;
    LocalizedString MapDescription0;                               // Horde
    LocalizedString MapDescription1;                               // Alliance
    LocalizedString PvpShortDescription;
    LocalizedString PvpLongDescription;
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
    int32 RaidOffset;
    int16 CorpseMapID;                                              // map_id of entrance map in ghost mode (continent always and in most cases = normal entrance)
    uint8 MaxPlayers;
    int16 WindSettingsID;
    int32 ZmpFileDataID;
    int32 PreloadFileDataID;
    std::array<int32, 3> Flags;

    uint8 Expansion() const { return ExpansionID; }

    bool IsDungeon() const { return (InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID || InstanceType == MAP_SCENARIO) && !IsGarrison(); }
    bool IsNonRaidDungeon() const { return InstanceType == MAP_INSTANCE; }
    bool Instanceable() const { return InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID || InstanceType == MAP_BATTLEGROUND || InstanceType == MAP_ARENA || InstanceType == MAP_SCENARIO; }
    bool IsRaid() const { return InstanceType == MAP_RAID; }
    bool IsBattleground() const { return InstanceType == MAP_BATTLEGROUND; }
    bool IsBattleArena() const { return InstanceType == MAP_ARENA; }
    bool IsBattlegroundOrArena() const { return InstanceType == MAP_BATTLEGROUND || InstanceType == MAP_ARENA; }
    bool IsScenario() const { return InstanceType == MAP_SCENARIO; }
    bool IsWorldMap() const { return InstanceType == MAP_COMMON; }

    bool GetEntrancePos(int32& mapid, float& /*x*/, float& /*y*/) const
    {
        if (CorpseMapID < 0)
            return false;

        // FIX ME!
        mapid = CorpseMapID;
        //x = Corpse.X;
        //y = Corpse.Y;
        return true;
    }

    bool IsContinent() const
    {
        switch (ID)
        {
        case 0:
        case 1:
        case 530:
        case 571:
        case 870:
        case 1116:
        case 1220:
        case 1642:
        case 1643:
        case 2222:
        case 2444:
            return true;
        default:
            return false;
        }
    }

    bool IsDynamicDifficultyMap() const { return GetFlags().HasFlag(MapFlags::DynamicDifficulty); }
    bool IsFlexLocking() const { return GetFlags().HasFlag(MapFlags::FlexibleRaidLocking); }
    bool IsGarrison() const { return GetFlags().HasFlag(MapFlags::Garrison); }
    bool IsSplitByFaction() const
    {
        return ID == 609 || // Acherus (DeathKnight Start)
            ID == 1265 ||   // Assault on the Dark Portal (WoD Intro)
            ID == 1481 ||   // Mardum (DH Start)
            ID == 2175 ||   // Exiles Reach - NPE
            ID == 2570;     // Forbidden Reach (Dracthyr/Evoker Start)
    }

    EnumFlag<MapFlags> GetFlags() const { return static_cast<MapFlags>(Flags[0]); }
    EnumFlag<MapFlags2> GetFlags2() const { return static_cast<MapFlags2>(Flags[1]); }
};

// structure for MapChallengeMode.db2
struct MapChallengeModeEntry
{
    LocalizedString Name;
    uint32 ID;
    uint16 MapID;
    uint8 Flags;
    uint32 ExpansionLevel;
    int32 RequiredWorldStateID; // maybe?
    std::array<int16, 3> CriteriaCount;
};

// structure for MapDifficulty.db2
struct MapDifficultyEntry
{
    LocalizedString Message;
    uint32 ID;
    int32 DifficultyID;
    int32 LockID;
    uint8 ResetInterval;
    int32 MaxPlayers;
    uint8 ItemContext;
    int32 ItemContextPickerID;
    int32 Flags;
    int32 ContentTuningID;
    int32 WorldStateExpressionID;
    uint32 MapID;

    bool HasResetSchedule() const { return ResetInterval != MAP_DIFFICULTY_RESET_ANYTIME; }
    bool IsUsingEncounterLocks() const { return GetFlags().HasFlag(MapDifficultyFlags::UseLootBasedLockInsteadOfInstanceLock); }
    bool IsRestoringDungeonState() const { return GetFlags().HasFlag(MapDifficultyFlags::ResumeDungeonProgressBasedOnLockout); }
    bool IsExtendable() const { return !GetFlags().HasFlag(MapDifficultyFlags::DisableLockExtension); }

    uint32 GetRaidDuration() const
    {
        if (ResetInterval == MAP_DIFFICULTY_RESET_DAILY)
            return 86400;
        if (ResetInterval == MAP_DIFFICULTY_RESET_WEEKLY)
            return 604800;
        return 0;
    }

    EnumFlag<MapDifficultyFlags> GetFlags() const { return static_cast<MapDifficultyFlags>(Flags); }
};

// structure for MapDifficultyXCondition.db2
struct MapDifficultyXConditionEntry
{
    uint32 ID;
    LocalizedString FailureDescription;
    uint32 PlayerConditionID;
    int32 OrderIndex;
    uint32 MapDifficultyID;
};

// structure for ModifierTree.db2
struct ModifierTreeEntry
{
    uint32 ID;
    uint32 Parent;
    int8 Operator;
    int8 Amount;
    int32 Type;
    int32 Asset;
    int32 SecondaryAsset;
    int8 TertiaryAsset;
};

// structure for Mount.db2
struct MountEntry
{
    LocalizedString Name;
    LocalizedString SourceText;
    LocalizedString Description;
    uint32 ID;
    uint16 MountTypeID;
    int32 Flags;
    int8 SourceTypeEnum;
    int32 SourceSpellID;
    uint32 PlayerConditionID;
    float MountFlyRideHeight;
    int32 UiModelSceneID;

    bool IsSelfMount() const { return (Flags & MOUNT_FLAG_SELF_MOUNT) != 0; }
};

// structure for MountCapability.db2
struct MountCapabilityEntry
{
    uint32 ID;
    int32 Flags;
    uint16 ReqRidingSkill;
    uint16 ReqAreaID;
    uint32 ReqSpellAuraID;
    int32 ReqSpellKnownID;
    int32 ModSpellAuraID;
    int16 ReqMapID;
    int32 PlayerConditionID;
    int32 FlightCapabilityID;
};

// structure for MountTypeXCapability.db2
struct MountTypeXCapabilityEntry
{
    uint32 ID;
    uint16 MountTypeID;
    uint16 MountCapabilityID;
    uint8 OrderIndex;
};

// structure for MountXDisplay.db2
struct MountXDisplayEntry
{
    uint32 ID;
    int32 CreatureDisplayInfoID;
    uint32 PlayerConditionID;
    uint16 Unknown1100;
    uint32 MountID;
};

// structure for Movie.db2
struct MovieEntry
{
    uint32 ID;
    uint8 Volume;
    uint8 KeyID;
    uint32 AudioFileDataID;
    uint32 SubtitleFileDataID;
};

// structure for MythicPlusSeason.db2
struct MythicPlusSeasonEntry
{
    uint32 ID;
    int32 MilestoneSeason;
    int32 StartTimeEvent;
    int32 ExpansionLevel;
    int32 HeroicLFGDungeonMinGear;
};

// structure for NameGen.db2
struct NameGenEntry
{
    uint32 ID;
    char const* Name;
    uint8 RaceID;
    uint8 Sex;
};

// structure for NamesProfanity.db2
struct NamesProfanityEntry
{
    uint32 ID;
    char const* Name;
    int8 Language;
};

// structure for NamesReserved.db2
struct NamesReservedEntry
{
    uint32 ID;
    char const* Name;
};

// structure for NamesReservedLocale.db2
struct NamesReservedLocaleEntry
{
    uint32 ID;
    char const* Name;
    uint8 LocaleMask;
};

// structure for NumTalentsAtLevel.db2
struct NumTalentsAtLevelEntry
{
    uint32 ID;
    int32 NumTalents;
    int32 NumTalentsDeathKnight;
    int32 NumTalentsDemonHunter;
    float NumberOfTalents;
};

#define MAX_OVERRIDE_SPELL 10

// structure for OverrideSpellData.db2
struct OverrideSpellDataEntry
{
    uint32 ID;
    std::array<int32, MAX_OVERRIDE_SPELL> Spells;
    int32 PlayerActionBarFileDataID;
    uint8 Flags;
};

// structure for ParagonReputation.db2
struct ParagonReputationEntry
{
    uint32 ID;
    int32 FactionID;
    int32 LevelThreshold;
    int32 QuestID;
};

// structure for Path.db2
struct PathEntry
{
    uint32 ID;
    uint8 Type;
    uint8 SplineType;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
    uint8 Alpha;
    uint8 Flags;
};

// structure for PathNode.db2
struct PathNodeEntry
{
    uint32 ID;
    uint16 PathID;
    int16 Sequence;
    int32 LocationID;
};

// structure for PathProperty.db2
struct PathPropertyEntry
{
    uint32 ID;
    uint16 PathID;
    uint8 PropertyIndex;
    int32 Value;

    PathPropertyIndex GetPropertyIndex() const { return static_cast<PathPropertyIndex>(PropertyIndex); }
};

// structure for Phase.db2
struct PhaseEntry
{
    uint32 ID;
    int32 Flags;

    EnumFlag<PhaseEntryFlags> GetFlags() const { return static_cast<PhaseEntryFlags>(Flags); }
};

// structure for PhaseXPhaseGroup.db2
struct PhaseXPhaseGroupEntry
{
    uint32 ID;
    uint16 PhaseID;
    uint32 PhaseGroupID;
};

// structure for PlayerCondition.db2
struct PlayerConditionEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    LocalizedString FailureDescription;
    uint16 MinLevel;
    uint16 MaxLevel;
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
    int32 PhaseUseFlags;
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
    uint32 TraitNodeEntryLogic;
    std::array<uint16, 4> SkillID;
    std::array<uint16, 4> MinSkill;
    std::array<uint16, 4> MaxSkill;
    std::array<uint32, 3> MinFactionID;
    std::array<uint8, 3> MinReputation;
    std::array<int32, 4> PrevQuestID;
    std::array<int32, 4> CurrQuestID;
    std::array<int32, 4> CurrentCompletedQuestID;
    std::array<int32, 4> SpellID;
    std::array<int32, 4> ItemID;
    std::array<uint32, 4> ItemCount;
    std::array<uint16, 2> Explored;
    std::array<uint32, 2> Time;
    std::array<int32, 4> AuraSpellID;
    std::array<uint8, 4> AuraStacks;
    std::array<uint16, 4> Achievement;
    std::array<uint16, 4> AreaID;
    std::array<uint8, 4> LfgStatus;
    std::array<uint8, 4> LfgCompare;
    std::array<uint32, 4> LfgValue;
    std::array<uint32, 4> CurrencyID;
    std::array<uint32, 4> CurrencyCount;
    std::array<uint32, 6> QuestKillMonster;
    std::array<int32, 2> MovementFlags;
    std::array<int32, 4> TraitNodeEntryID;
    std::array<uint16, 4> TraitNodeEntryMinRank;
    std::array<uint16, 4> TraitNodeEntryMaxRank;
};

// structure for PowerDisplay.db2
struct PowerDisplayEntry
{
    uint32 ID;
    char const* GlobalStringBaseTag;
    int8 ActualType;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

// structure for PowerType.db2
struct PowerTypeEntry
{
    char const* NameGlobalStringTag;
    char const* CostGlobalStringTag;
    uint32 ID;
    int8 PowerTypeEnum;
    int32 MinPower;
    int32 MaxBasePower;
    int32 CenterPower;
    int32 DefaultPower;
    int32 DisplayModifier;
    int32 RegenInterruptTimeMS;
    float RegenPeace;
    float RegenCombat;
    int32 Flags;

    EnumFlag<PowerTypeFlags> GetFlags() const { return static_cast<PowerTypeFlags>(Flags); }
};

// structure for PrestigeLevelInfo.db2
struct PrestigeLevelInfoEntry
{
    uint32 ID;
    LocalizedString Name;
    int32 HonorLevel;
    int32 BadgeTextureFileDataID;
    uint8 Flags;
    int32 AwardedAchievementID;

    bool IsDisabled() const { return (Flags & PRESTIGE_FLAG_DISABLED) != 0; }
};

// structure for PVPDifficulty.db2
struct PVPDifficultyEntry
{
    uint32 ID;
    uint8 RangeIndex;
    uint8 MinLevel;
    uint8 MaxLevel;
    uint32 MapID;

    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(RangeIndex); }
};

// structure for PVPItem.db2
struct PVPItemEntry
{
    uint32 ID;
    int32 ItemID;
    uint8 ItemLevelDelta;
};

// structure for PvpSeason.db2
struct PvpSeasonEntry
{
    uint32 ID;
    int32 MilestoneSeason;
    int32 AllianceAchievementID;
    int32 HordeAchievementID;
};

// structure for PvpTier.db2
struct PvpTierEntry
{
    uint32 ID;
    LocalizedString Name;
    int16 MinRating;
    int16 MaxRating;
    int32 PrevTier;
    int32 NextTier;
    uint8 BracketID;
    int8 Rank;
    int32 RankIconFileDataID;
};

// structure for QuestFactionReward.db2
struct QuestFactionRewardEntry
{
    uint32 ID;
    std::array<int16, 10> Difficulty;
};

// structure for QuestInfo.db2
struct QuestInfoEntry
{
    uint32 ID;
    LocalizedString InfoName;
    int8 Type;
    int32 Modifiers;
    uint16 Profession;
};

// structure for QuestLineXQuest.db2
struct QuestLineXQuestEntry
{
    uint32 ID;
    uint32 QuestLineID;
    uint32 QuestID;
    uint32 OrderIndex;
};

// structure for QuestMoneyReward.db2
struct QuestMoneyRewardEntry
{
    uint32 ID;
    std::array<uint32, 10> Difficulty;
};

// structure for QuestPackageItem.db2
struct QuestPackageItemEntry
{
    uint32 ID;
    uint16 PackageID;
    int32 ItemID;
    uint32 ItemQuantity;
    uint8 DisplayType;
};

// structure for QuestSort.db2
struct QuestSortEntry
{
    uint32 ID;
    LocalizedString SortName;
    int8 UiOrderIndex;
};

// structure for QuestV2.db2
struct QuestV2Entry
{
    uint32 ID;
    uint16 UniqueBitFlag;
};

// structure for QuestXP.db2
struct QuestXPEntry
{
    uint32 ID;
    std::array<int32, 10> Difficulty;
};

// structure for RandPropPoints.db2
struct RandPropPointsEntry
{
    uint32 ID;
    int32 DamageReplaceStat;
    std::array<uint32, 5> Epic;
    std::array<uint32, 5> Superior;
    std::array<uint32, 5> Good;
};

// structure for RewardPack.db2
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

// structure for RewardPackXCurrencyType.db2
struct RewardPackXCurrencyTypeEntry
{
    uint32 ID;
    uint32 CurrencyTypeID;
    int32 Quantity;
    uint32 RewardPackID;
};

// structure for RewardPackXItem.db2
struct RewardPackXItemEntry
{
    uint32 ID;
    int32 ItemID;
    int32 ItemQuantity;
    uint32 RewardPackID;
};

// structure for Scenario.db2
struct ScenarioEntry
{
    uint32 ID;
    LocalizedString Name;
    uint16 AreaTableID;
    uint8 Type;
    uint8 Flags;
    uint32 UiTextureKitID;
};

// structure for ScenarioStep.db2
struct ScenarioStepEntry
{
    LocalizedString Description;
    LocalizedString Title;
    uint32 ID;
    uint16 ScenarioID;
    uint32 CriteriatreeID;
    int32 RewardQuestID;
    int32 RelatedStep;                                              // Bonus step can only be completed if scenario is in the step specified in this field
    uint16 Supersedes;                                              // Used in conjunction with Proving Grounds scenarios, when sequencing steps (Not using step order?)
    uint8 OrderIndex;
    uint8 Flags;
    uint32 VisibilityPlayerConditionID;
    uint16 WidgetSetID;

    bool IsBonusObjective() const
    {
        return Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE;
    }
};

// structure for SceneScript.db2
struct SceneScriptEntry
{
    uint32 ID;
    uint16 FirstSceneScriptID;
    uint16 NextSceneScriptID;
    int32 Unknown915;
};

// structure for SceneScriptGlobalText.db2
struct SceneScriptGlobalTextEntry
{
    uint32 ID;
    char const* Name;
    char const* Script;
};

// structure for SceneScriptPackage.db2
struct SceneScriptPackageEntry
{
    uint32 ID;
    char const* Name;
};

// structure for SceneScriptText.db2
struct SceneScriptTextEntry
{
    uint32 ID;
    char const* Name;
    char const* Script;
};

// structure for ServerMessages.db2
struct ServerMessagesEntry
{
    uint32 ID;
    LocalizedString Text;
};

// structure for SkillLine.db2
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
    int32 Flags;
    int32 SpellBookSpellID;

    EnumFlag<SkillLineFlags> GetFlags() const { return static_cast<SkillLineFlags>(Flags); }
};

// structure for SkillLineAbility.db2
struct SkillLineAbilityEntry
{
    Trinity::RaceMask<int64> RaceMask;
    uint32 ID;
    uint16 SkillLine;
    int32 Spell;
    int16 MinSkillLineRank;
    int32 ClassMask;
    int32 SupercedesSpell;
    int32 AcquireMethod;
    int16 TrivialSkillLineRankHigh;
    int16 TrivialSkillLineRankLow;
    int32 Flags;
    int8 NumSkillUps;
    int16 UniqueBit;
    int16 TradeSkillCategoryID;
    int16 SkillupSkillLineID;
    std::array<int32, 2> CharacterPoints;

    EnumFlag<SkillLineAbilityFlags> GetFlags() const { return static_cast<SkillLineAbilityFlags>(Flags); }
};

// structure for SkillRaceClassInfo.db2
struct SkillRaceClassInfoEntry
{
    uint32 ID;
    Trinity::RaceMask<int64> RaceMask;
    uint16 SkillID;
    int32 ClassMask;
    uint16 Flags;
    int32 Availability;
    int8 MinLevel;
    int16 SkillTierID;
    int32 Unknown1150;
};

// structure for SoundKit.db2
struct SoundKitEntry
{
    uint32 ID;
    uint8 SoundType;
    float VolumeFloat;
    int32 Flags;
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
    uint32 SoundMixGroupID;
};

// structure for SpellAuraOptions.db2
struct SpellAuraOptionsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint32 CumulativeAura;
    int32 ProcCategoryRecovery;
    uint8 ProcChance;
    int32 ProcCharges;
    uint16 SpellProcsPerMinuteID;
    std::array<int32, 2> ProcTypeMask;
    uint32 SpellID;
};

// structure for SpellAuraRestrictions.db2
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

// structure for SpellCastTimes.db2
struct SpellCastTimesEntry
{
    uint32 ID;
    int32 Base;
    int16 PerLevel;
    int32 Minimum;
};

// structure for SpellCastingRequirements.db2
struct SpellCastingRequirementsEntry
{
    uint32 ID;
    int32 SpellID;
    uint8 FacingCasterFlags;
    uint16 MinFactionID;
    int32 MinReputation;
    uint16 RequiredAreasID;
    uint8 RequiredAuraVision;
    uint16 RequiresSpellFocus;
};

// structure for SpellCategories.db2
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

// structure for SpellCategory.db2
struct SpellCategoryEntry
{
    uint32 ID;
    LocalizedString Name;
    int32 Flags;
    uint8 UsesPerWeek;
    int8 MaxCharges;
    int32 ChargeRecoveryTime;
    int32 TypeMask;
};

// structure for SpellClassOptions.db2
struct SpellClassOptionsEntry
{
    uint32 ID;
    int32 SpellID;
    uint32 ModalNextSpell;
    uint8 SpellClassSet;
    flag128 SpellClassMask;
};

// structure for SpellCooldowns.db2
struct SpellCooldownsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int32 CategoryRecoveryTime;
    int32 RecoveryTime;
    int32 StartRecoveryTime;
    int32 AuraSpellID;
    uint32 SpellID;
};

// structure for SpellDuration.db2
struct SpellDurationEntry
{
    uint32 ID;
    int32 Duration;
    uint32 DurationPerLevel;
    int32 MaxDuration;
};

// structure for SpellEffect.db2
struct SpellEffectEntry
{
    uint32 ID;
    int32 DifficultyID;
    int32 EffectIndex;
    uint32 Effect;
    float EffectAmplitude;
    int32 EffectAttributes;
    int16 EffectAura;
    int32 EffectAuraPeriod;
    int32 EffectBasePoints;
    float EffectBonusCoefficient;
    float EffectChainAmplitude;
    int32 EffectChainTargets;
    int32 EffectDieSides;
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
    std::array<int32, 2> EffectMiscValue;
    std::array<uint32, 2> EffectRadiusIndex;
    flag128 EffectSpellClassMask;
    std::array<int16, 2> ImplicitTarget;
    uint32 SpellID;

    SpellEffectAttributes GetEffectAttributes() const { return static_cast<SpellEffectAttributes>(EffectAttributes); }
};

// structure for SpellEquippedItems.db2
struct SpellEquippedItemsEntry
{
    uint32 ID;
    int32 SpellID;
    int8 EquippedItemClass;
    int32 EquippedItemInvTypes;
    int32 EquippedItemSubclass;
};

// structure for SpellFocusObject.db2
struct SpellFocusObjectEntry
{
    uint32 ID;
    LocalizedString Name;
};

// structure for SpellInterrupts.db2
struct SpellInterruptsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int16 InterruptFlags;
    std::array<int32, MAX_SPELL_AURA_INTERRUPT_FLAGS> AuraInterruptFlags;
    std::array<int32, MAX_SPELL_AURA_INTERRUPT_FLAGS> ChannelInterruptFlags;
    uint32 SpellID;
};

#define MAX_ITEM_ENCHANTMENT_EFFECTS 3

// structure for SpellItemEnchantment.db2
struct SpellItemEnchantmentEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString HordeName;
    int32 Charges;
    std::array<int32, MAX_ITEM_ENCHANTMENT_EFFECTS> Effect;
    std::array<int32, MAX_ITEM_ENCHANTMENT_EFFECTS> EffectPointsMin;
    std::array<int32, MAX_ITEM_ENCHANTMENT_EFFECTS> EffectPointsMax;
    std::array<int32, MAX_ITEM_ENCHANTMENT_EFFECTS> EffectArg;
    int32 ItemVisual;
    int32 Flags;
    std::array<float, MAX_ITEM_ENCHANTMENT_EFFECTS> EffectScalingPoints;
    int32 ScalingClass;
    int32 ScalingClassRestricted;
    int32 GemItemID;
    int32 ConditionID;
    int32 RequiredSkillID;
    int32 RequiredSkillRank;
    int32 MinLevel;
    int32 MaxLevel;
    int32 Unknown1153_0;
    int32 ItemLevel;
    int32 Unknown1153_1;
    int32 Unknown1153_2;

    EnumFlag<SpellItemEnchantmentFlags> GetFlags() const { return static_cast<SpellItemEnchantmentFlags>(Flags); }
};

// structure for SpellItemEnchantmentCondition.db2
struct SpellItemEnchantmentConditionEntry
{
    uint32 ID;
    std::array<uint8, 5> LtOperandType;
    std::array<uint32, 5> LtOperand;
    std::array<uint8, 5> Operator;
    std::array<uint8, 5> RtOperandType;
    std::array<uint8, 5> RtOperand;
    std::array<uint8, 5> Logic;
};

// structure for SpellKeyboundOverride.db2
struct SpellKeyboundOverrideEntry
{
    uint32 ID;
    char const* Function;
    int8 Type;
    int32 Data;
    int32 Flags;
};

// structure for SpellLabel.db2
struct SpellLabelEntry
{
    uint32 ID;
    uint32 LabelID;
    uint32 SpellID;
};

// structure for SpellLearnSpell.db2
struct SpellLearnSpellEntry
{
    uint32 ID;
    int32 SpellID;
    int32 LearnSpellID;
    int32 OverridesSpellID;
};

// structure for SpellLevels.db2
struct SpellLevelsEntry
{
    uint32 ID;
    uint8 DifficultyID;
    int16 BaseLevel;
    int16 MaxLevel;
    int16 SpellLevel;
    uint8 MaxPassiveAuraLevel;
    uint32 SpellID;
};

// structure for SpellMisc.db2
struct SpellMiscEntry
{
    uint32 ID;
    std::array<int32, 16> Attributes;
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
    uint32 SpellID;
};

// structure for SpellName.db2
struct SpellNameEntry
{
    uint32 ID;                      // SpellID
    LocalizedString Name;
};

// structure for SpellPower.db2
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

// structure for SpellPowerDifficulty.db2
struct SpellPowerDifficultyEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint8 OrderIndex;
};

// structure for SpellProcsPerMinute.db2
struct SpellProcsPerMinuteEntry
{
    uint32 ID;
    float BaseProcRate;
    uint8 Flags;
};

// structure for SpellProcsPerMinuteMod.db2
struct SpellProcsPerMinuteModEntry
{
    uint32 ID;
    uint8 Type;
    int16 Param;
    float Coeff;
    uint32 SpellProcsPerMinuteID;
};

// structure for SpellRadius.db2
struct SpellRadiusEntry
{
    uint32 ID;
    float Radius;
    float RadiusPerLevel;
    float RadiusMin;
    float RadiusMax;
};

// structure for SpellRange.db2
struct SpellRangeEntry
{
    uint32 ID;
    LocalizedString DisplayName;
    LocalizedString DisplayNameShort;
    uint8 Flags;
    std::array<float, 2> RangeMin;
    std::array<float, 2> RangeMax;
};

#define MAX_SPELL_REAGENTS 8

// structure for SpellReagents.db2
struct SpellReagentsEntry
{
    uint32 ID;
    int32 SpellID;
    std::array<int32, MAX_SPELL_REAGENTS> Reagent;
    std::array<int16, MAX_SPELL_REAGENTS> ReagentCount;
};

// structure for SpellReagentsCurrency.db2
struct SpellReagentsCurrencyEntry
{
    uint32 ID;
    uint32 SpellID;
    uint16 CurrencyTypesID;
    uint16 CurrencyCount;
};

// structure for SpellScaling.db2
struct SpellScalingEntry
{
    uint32 ID;
    int32 SpellID;
    int32 Class;
    uint32 MinScalingLevel;
    uint32 MaxScalingLevel;
    int16 ScalesFromItemLevel;
    int32 CastTimeMin;
    int32 CastTimeMax;
    int32 CastTimeMaxLevel;
    float NerfFactor;
    int32 NerfMaxLevel;
};

// structure for SpellShapeshift.db2
struct SpellShapeshiftEntry
{
    uint32 ID;
    int32 SpellID;
    int8 StanceBarOrder;
    std::array<int32, 2> ShapeshiftExclude;
    std::array<int32, 2> ShapeshiftMask;
};

#define MAX_SHAPESHIFT_SPELLS 8

// structure for SpellShapeshiftForm.db2
struct SpellShapeshiftFormEntry
{
    uint32 ID;
    LocalizedString Name;
    uint32 Unknown1150;
    int8 CreatureType;
    int32 Flags;
    int32 AttackIconFileID;
    int8 BonusActionBar;
    int16 CombatRoundTime;
    float DamageVariance;
    uint16 MountTypeID;
    std::array<uint32, 4> CreatureDisplayID;
    std::array<uint32, MAX_SHAPESHIFT_SPELLS> PresetSpellID;

    EnumFlag<SpellShapeshiftFormFlags> GetFlags() const { return static_cast<SpellShapeshiftFormFlags>(Flags); }
};

// structure for SpellTargetRestrictions.db2
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

// structure for SpellTotems.db2
struct SpellTotemsEntry
{
    uint32 ID;
    int32 SpellID;
    std::array<uint16, MAX_SPELL_TOTEMS> RequiredTotemCategoryID;
    std::array<int32, MAX_SPELL_TOTEMS> Totem;
};

// structure for SpellVisual.db2
struct SpellVisualEntry
{
    uint32 ID;
    DBCPosition3D MissileCastOffset;
    DBCPosition3D MissileImpactOffset;
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
    uint16 AreaModel;
    int8 HasMissile;
};

// structure for SpellVisualEffectName.db2
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
    uint16 Unknown1154;
};

// structure for SpellVisualKit.db2
struct SpellVisualKitEntry
{
    uint32 ID;
    uint32 FallbackSpellVisualKitID;
    uint16 DelayMin;
    uint16 DelayMax;
    float FallbackPriority;
    std::array<int32, 2> Flags;
};

// structure for SpellVisualMissile.db2
struct SpellVisualMissileEntry
{
    DBCPosition3D CastOffset;
    DBCPosition3D ImpactOffset;
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
    uint16 Unknown1154;
    uint32 SpellVisualMissileSetID;
};

// structure for SpellXSpellVisual.db2
struct SpellXSpellVisualEntry
{
    uint32 ID;
    uint8 DifficultyID;
    uint32 SpellVisualID;
    float Probability;
    uint8 Flags;
    int32 Priority;
    int32 SpellIconFileID;
    int32 ActiveIconFileID;
    uint16 ViewerUnitConditionID;
    uint32 ViewerPlayerConditionID;
    uint16 CasterUnitConditionID;
    uint32 CasterPlayerConditionID;
    uint32 SpellID;
};

// structure for SummonProperties.db2
struct SummonPropertiesEntry
{
    uint32 ID;
    int32 Control;
    int32 Faction;
    int32 Title;
    int32 Slot;
    std::array<int32, 2> Flags;

    EnumFlag<SummonPropertiesFlags> GetFlags() const { return static_cast<SummonPropertiesFlags>(Flags[0]); }
};

#define TACTKEY_SIZE 16

// structure for TactKey.db2
struct TactKeyEntry
{
    uint32 ID;
    std::array<uint8, TACTKEY_SIZE> Key;
};

// structure for Talent.db2
struct TalentEntry
{
    uint32 ID;
    LocalizedString Description;
    uint8 TierID;
    uint8 Flags;
    uint8 ColumnIndex;
    uint16 TabID;
    uint8 ClassID;
    uint16 SpecID;
    int32 SpellID;
    int32 OverridesSpellID;
    int32 RequiredSpellID;
    std::array<int32, 2> CategoryMask;
    std::array<int32, 9> SpellRank;
    std::array<int32, 3> PrereqTalent;
    std::array<int32, 3> PrereqRank;
};

#define MAX_MASTERY_SPELLS 2

// structure for TalentTab.db2
struct TalentTabEntry
{
    uint32 ID;
    LocalizedString Name;
    char const* BackgroundFile;
    LocalizedString Description;
    int32 OrderIndex;
    int32 RaceMask;
    int32 ClassMask;
    int32 CategoryEnumID;
    int32 SpellIconID;
    int32 RoleMask;
    std::array<int32, MAX_MASTERY_SPELLS> MasterySpellID;
};

// structure for TalentTreePrimarySpells.db2
struct TalentTreePrimarySpellsEntry
{
    uint32 ID;
    int32 TalentTabID;
    int32 SpellID;
    int32 Flags;
};

// structure for TaxiNodes.db2
struct TaxiNodesEntry
{
    LocalizedString Name;
    DBCPosition3D Pos;
    DBCPosition2D MapOffset;
    DBCPosition2D FlightMapOffset;
    uint32 ID;
    uint32 ContinentID;
    uint32 ConditionID;
    uint16 CharacterBitNumber;
    int32 Flags;
    int32 UiTextureKitID;
    float Facing;
    uint32 SpecialIconConditionID;
    uint32 VisibilityConditionID;
    std::array<int32, 2> MountCreatureID;

    EnumFlag<TaxiNodeFlags> GetFlags() const { return static_cast<TaxiNodeFlags>(Flags); }

    bool IsPartOfTaxiNetwork() const
    {
        return GetFlags().HasFlag(TaxiNodeFlags::ShowOnAllianceMap | TaxiNodeFlags::ShowOnHordeMap)
            // manually whitelisted nodes
            || ID == 1985   // [Hidden] Argus Ground Points Hub (Ground TP out to here, TP to Vindicaar from here)
            || ID == 1986   // [Hidden] Argus Vindicaar Ground Hub (Vindicaar TP out to here, TP to ground from here)
            || ID == 1987   // [Hidden] Argus Vindicaar No Load Hub (Vindicaar No Load transition goes through here)
            || ID == 2627   // [Hidden] 9.0 Bastion Ground Points Hub (Ground TP out to here, TP to Sanctum from here)
            || ID == 2628   // [Hidden] 9.0 Bastion Ground Hub (Sanctum TP out to here, TP to ground from here)
            || ID == 2732   // [HIDDEN] 9.2 Resonant Peaks - Teleport Network - Hidden Hub (Connects all Nodes to each other without unique paths)
            || ID == 2835   // [Hidden] 10.0 Travel Network - Destination Input
            || ID == 2843   // [Hidden] 10.0 Travel Network - Destination Output
            ;
    }
};

// structure for TaxiPath.db2
struct TaxiPathEntry
{
    uint32 ID;
    uint16 FromTaxiNode;
    uint16 ToTaxiNode;
    uint32 Cost;
};

// structure for TaxiPathNode.db2
struct TaxiPathNodeEntry
{
    DBCPosition3D Loc;
    uint32 ID;
    uint16 PathID;
    int32 NodeIndex;
    uint16 ContinentID;
    int32 Flags;
    uint32 Delay;
    uint32 ArrivalEventID;
    uint32 DepartureEventID;
};

// structure for TotemCategory.db2
struct TotemCategoryEntry
{
    uint32 ID;
    LocalizedString Name;
    uint8 TotemCategoryType;
    int32 TotemCategoryMask;
};

// structure for Toy.db2
struct ToyEntry
{
    LocalizedString SourceText;
    uint32 ID;
    int32 ItemID;
    uint8 Flags;
    int8 SourceTypeEnum;
};

// structure for TransmogHoliday.db2
struct TransmogHolidayEntry
{
    uint32 ID;
    int32 RequiredTransmogHoliday;
};

// structure for TransmogSet.db2
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
    uint8 ExpansionID;
    int16 UiOrder;
};

// structure for TransmogSetGroup.db2
struct TransmogSetGroupEntry
{
    LocalizedString Name;
    uint32 ID;
};

// structure for TransmogSetItem.db2
struct TransmogSetItemEntry
{
    uint32 ID;
    uint32 TransmogSetID;
    uint32 ItemModifiedAppearanceID;
    int32 Flags;
};

// structure for TransportAnimation.db2
struct TransportAnimationEntry
{
    uint32 ID;
    DBCPosition3D Pos;
    uint8 SequenceID;
    uint32 TimeIndex;
    uint32 TransportID;
};

// structure for TransportRotation.db2
struct TransportRotationEntry
{
    uint32 ID;
    std::array<float, 4> Rot;
    uint32 TimeIndex;
    uint32 GameObjectsID;
};

// structure for UiMap.db2
struct UiMapEntry
{
    LocalizedString Name;
    uint32 ID;
    uint32 ParentUiMapID;
    int32 Flags;
    uint8 System;
    uint8 Type;
    int32 BountySetID;
    uint32 BountyDisplayLocation;
    int32 VisibilityPlayerConditionID2; // if not met then map is skipped when evaluating UiMapAssignment
    int32 VisibilityPlayerConditionID;  // if not met then client checks other maps with the same AlternateUiMapGroup, not re-evaluating UiMapAssignment for them
    int8 HelpTextPosition;
    int32 BkgAtlasID;
    uint32 AlternateUiMapGroup;
    uint32 ContentTuningID;

    EnumFlag<UiMapFlag> GetFlags() const { return static_cast<UiMapFlag>(Flags); }
};

// structure for UiMapAssignment.db2
struct UiMapAssignmentEntry
{
    DBCPosition2D UiMin;
    DBCPosition2D UiMax;
    std::array<DBCPosition3D, 2> Region;
    uint32 ID;
    uint32 UiMapID;
    int32 OrderIndex;
    int32 MapID;
    int32 AreaID;
    int32 WmoDoodadPlacementID;
    int32 WmoGroupID;
};

// structure for UiMapLink.db2
struct UiMapLinkEntry
{
    DBCPosition2D UiMin;
    DBCPosition2D UiMax;
    uint32 ID;
    uint32 ParentUiMapID;
    int32 OrderIndex;
    int32 ChildUiMapID;
    int32 OverrideHighlightFileDataID;
    int32 OverrideHighlightAtlasID;
    int32 Flags;
};

// structure for UiMapXMapArt.db2
struct UiMapXMapArtEntry
{
    uint32 ID;
    int32 PhaseID;
    int32 UiMapArtID;
    uint32 UiMapID;
};

#define MAX_UNIT_CONDITION_VALUES 8

// structure for UnitCondition.db2
struct UnitConditionEntry
{
    uint32 ID;
    int32 Flags;
    std::array<uint8, MAX_UNIT_CONDITION_VALUES> Variable;
    std::array<uint8, MAX_UNIT_CONDITION_VALUES> Op;
    std::array<int32, MAX_UNIT_CONDITION_VALUES> Value;

    EnumFlag<UnitConditionFlags> GetFlags() const { return static_cast<UnitConditionFlags>(Flags); }
};

// structure for UnitPowerBar.db2
struct UnitPowerBarEntry
{
    uint32 ID;
    LocalizedString Name;
    LocalizedString Cost;
    LocalizedString OutOfError;
    LocalizedString ToolTip;
    uint32 MinPower;
    uint32 MaxPower;
    uint16 StartPower;
    uint8 CenterPower;
    float RegenerationPeace;
    float RegenerationCombat;
    uint8 BarType;
    uint16 Flags;
    float StartInset;
    float EndInset;
    std::array<int32, 6> FileDataID;
    std::array<int32, 6> Color;
};

#define MAX_VEHICLE_SEATS 8

// structure for Vehicle.db2
struct VehicleEntry
{
    uint32 ID;
    int32 Flags;
    int32 FlagsB;
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
    int32 UiLocomotionType;
    std::array<uint16, 8> SeatID;
    std::array<uint16, 3> PowerDisplayID;
};

// structure for VehicleSeat.db2
struct VehicleSeatEntry
{
    uint32 ID;
    DBCPosition3D AttachmentOffset;
    DBCPosition3D CameraOffset;
    int32 Flags;
    int32 FlagsB;
    int32 FlagsC;
    int32 AttachmentID;
    float EnterPreDelay;
    float EnterSpeed;
    float EnterGravity;
    float EnterMinDuration;
    float EnterMaxDuration;
    float EnterMinArcHeight;
    float EnterMaxArcHeight;
    int16 EnterAnimStart;
    int16 EnterAnimLoop;
    int16 RideAnimStart;
    int16 RideAnimLoop;
    int16 RideUpperAnimStart;
    int16 RideUpperAnimLoop;
    float ExitPreDelay;
    float ExitSpeed;
    float ExitGravity;
    float ExitMinDuration;
    float ExitMaxDuration;
    float ExitMinArcHeight;
    float ExitMaxArcHeight;
    int16 ExitAnimStart;
    int16 ExitAnimLoop;
    int16 ExitAnimEnd;
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
    int32 UiSkin;
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

// structure for Vignette.db2
struct VignetteEntry
{
    uint32 ID;
    LocalizedString Name;
    uint32 PlayerConditionID;
    uint32 VisibleTrackingQuestID;
    uint32 QuestFeedbackEffectID;
    int32 Flags;
    float MaxHeight;
    float MinHeight;
    int8 VignetteType;
    int32 RewardQuestID;
    int8 Unknown1156;

    EnumFlag<VignetteFlags> GetFlags() const { return static_cast<VignetteFlags>(Flags); }
    bool IsInfiniteAOI() const { return GetFlags().HasFlag(VignetteFlags::InfiniteAOI | VignetteFlags::ZoneInfiniteAOI); }
};

// structure for WMOAreaTable.db2
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

// structure for WorldEffect.db2
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

// structure for WorldMapOverlay.db2
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
    std::array<uint32, MAX_WORLD_MAP_OVERLAY_AREA_IDX> AreaID;
};

// structure for WorldStateExpression.db2
struct WorldStateExpressionEntry
{
    uint32 ID;
    char const* Expression;
};

#pragma pack(pop)
#endif
