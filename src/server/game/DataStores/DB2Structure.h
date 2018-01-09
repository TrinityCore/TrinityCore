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

#ifndef TRINITY_DB2STRUCTURE_H
#define TRINITY_DB2STRUCTURE_H

#include "Define.h"
#include "DBCEnums.h"
#include "Util.h"

#pragma pack(push, 1)

struct LocalizedString;

struct AchievementEntry
{
    LocalizedString* Title;
    LocalizedString* Description;
    uint32 Flags;
    LocalizedString* Reward;
    int16  MapID;                                                   // -1 = none
    uint16 Supercedes;                                              // its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    uint16 Category;
    uint16 UIOrder;
    uint16 SharesCriteria;                                          // referenced achievement (counting of all completed criterias)
    int8  Faction;                                                  // -1 = all, 0 = horde, 1 = alliance
    uint8 Points;
    uint8 MinimumCriteria;                                          // need this count of completed criterias (own or referenced achievement criterias)
    uint32 ID;
    uint32 IconFileDataID;
    uint32 CriteriaTree;
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
    uint16 AreaGroupID;
    uint16 AreaID;
};

struct AreaTableEntry
{
    uint32 ID;
    uint32 Flags[2];
    char const* ZoneName;
    float AmbientMultiplier;
    LocalizedString* AreaName;
    uint16 MapID;
    uint16 ParentAreaID;
    int16 AreaBit;
    uint16 AmbienceID;
    uint16 ZoneMusic;
    uint16 IntroSound;
    uint16 LiquidTypeID[4];
    uint16 UWZoneMusic;
    uint16 UWAmbience;
    uint16 PvPCombatWorldStateID;
    uint8 SoundProviderPref;
    uint8 SoundProviderPrefUnderwater;
    uint8 ExplorationLevel;
    uint8 FactionGroupMask;
    uint8 MountFlags;
    uint8 WildBattlePetLevelMin;
    uint8 WildBattlePetLevelMax;
    uint8 WindSettingsID;
    uint32 UWIntroSound;

    // helpers
    bool IsSanctuary() const
    {
        if (MapID == 609)
            return true;
        return (Flags[0] & AREA_FLAG_SANCTUARY) != 0;
    }
};

struct AreaTriggerEntry
{
    DBCPosition3D Pos;
    float Radius;
    float BoxLength;
    float BoxWidth;
    float BoxHeight;
    float BoxYaw;
    uint16 MapID;
    uint16 PhaseID;
    uint16 PhaseGroupID;
    uint16 ShapeID;
    uint16 AreaTriggerActionSetID;
    uint8 PhaseUseFlags;
    uint8 ShapeType;
    uint8 Flag;
    uint32 ID;
};

struct ArmorLocationEntry
{
    uint32 ID;
    float Modifier[5];
};

struct ArtifactEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 BarConnectedColor;
    uint32 BarDisconnectedColor;
    uint32 TitleColor;
    uint16 ClassUiTextureKitID;
    uint16 SpecID;
    uint8 ArtifactCategoryID;
    uint8 Flags;
    uint32 UiModelSceneID;
    uint32 SpellVisualKitID;
};

struct ArtifactAppearanceEntry
{
    LocalizedString* Name;
    uint32 SwatchColor;
    float ModelDesaturation;
    float ModelAlpha;
    uint32 ShapeshiftDisplayID;
    uint16 ArtifactAppearanceSetID;
    uint16 Unknown;
    uint8 DisplayIndex;
    uint8 AppearanceModID;
    uint8 Flags;
    uint8 ModifiesShapeshiftFormDisplay;
    uint32 ID;
    uint32 PlayerConditionID;
    uint32 ItemAppearanceID;
    uint32 AltItemAppearanceID;
};

struct ArtifactAppearanceSetEntry
{
    LocalizedString* Name;
    LocalizedString* Name2;
    uint16 UiCameraID;
    uint16 AltHandUICameraID;
    uint8 ArtifactID;
    uint8 DisplayIndex;
    uint8 AttachmentPoint;
    uint8 Flags;
    uint32 ID;
};

struct ArtifactCategoryEntry
{
    uint32 ID;
    uint16 ArtifactKnowledgeCurrencyID;
    uint16 ArtifactKnowledgeMultiplierCurveID;
};

struct ArtifactPowerEntry
{
    DBCPosition2D Pos;
    uint8 ArtifactID;
    uint8 Flags;
    uint8 MaxRank;
    uint8 ArtifactTier;
    uint32 ID;
    int32 RelicType;
};

struct ArtifactPowerLinkEntry
{
    uint32 ID;
    uint16 FromArtifactPowerID;
    uint16 ToArtifactPowerID;
};

struct ArtifactPowerPickerEntry
{
    uint32 ID;
    uint32 PlayerConditionID;
};

struct ArtifactPowerRankEntry
{
    uint32 ID;
    uint32 SpellID;
    float Value;
    uint16 ArtifactPowerID;
    uint16 Unknown;
    uint8 Rank;
};

struct ArtifactQuestXPEntry
{
    uint32 ID;
    uint32 Exp[10];
};

struct AuctionHouseEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint16 FactionID;                                               // id of faction.dbc for player factions associated with city
    uint8 DepositRate;
    uint8 ConsignmentRate;
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
    LocalizedString* DisplayName;
    LocalizedString* Description;
    float CostModifier;
    uint8 Type;                                                     // value 0 -> hair, value 2 -> facialhair
    uint8 Race;
    uint8 Sex;
    uint8 Data;                                                     // real ID to hair/facial hair
    uint32 ID;
};

struct BattlePetBreedQualityEntry
{
    uint32 ID;
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
    uint32 CreatureID;
    uint32 IconFileID;
    uint32 SummonSpellID;
    LocalizedString* SourceText;
    LocalizedString* Description;
    uint16 Flags;
    uint8 PetType;
    int8 Source;
    uint32 ID;
    uint32 CardModelSceneID;
    uint32 LoadoutModelSceneID;
};

struct BattlePetSpeciesStateEntry
{
    uint32 ID;
    int32 Value;
    uint16 SpeciesID;
    uint8 State;
};

struct BattlemasterListEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 IconFileDataID;
    LocalizedString* GameType;
    LocalizedString* ShortDescription;
    LocalizedString* LongDescription;
    int16 MapID[16];
    uint16 HolidayWorldState;
    uint16 PlayerConditionID;
    uint8 InstanceType;
    uint8 GroupsAllowed;
    uint8 MaxGroupSize;
    uint8 MinLevel;
    uint8 MaxLevel;
    uint8 RatedPlayers;
    uint8 MinPlayers;
    uint8 MaxPlayers;
    uint8 Flags;
};

#define MAX_BROADCAST_TEXT_EMOTES 3

struct BroadcastTextEntry
{
    uint32 ID;
    LocalizedString* MaleText;
    LocalizedString* FemaleText;
    uint16 EmoteID[MAX_BROADCAST_TEXT_EMOTES];
    uint16 EmoteDelay[MAX_BROADCAST_TEXT_EMOTES];
    uint16 UnkEmoteID;
    uint8 Language;
    uint8 Type;
    uint32 SoundID[2];
    uint32 PlayerConditionID;
};

struct CharacterFacialHairStylesEntry
{
    uint32 ID;
    uint32 Geoset[5];
    uint8 RaceID;
    uint8 SexID;
    uint8 VariationID;
};

struct CharBaseSectionEntry
{
    uint32 ID;
    uint8 Variation;
    uint8 ResolutionVariation;
    uint8 Resolution;
};

struct CharSectionsEntry
{
    uint32 ID;
    uint32 TextureFileDataID[3];
    uint16 Flags;
    uint8 RaceID;
    uint8 SexID;
    uint8 BaseSection;
    uint8 VariationIndex;
    uint8 ColorIndex;
};

#define MAX_OUTFIT_ITEMS 24

struct CharStartOutfitEntry
{
    uint32 ID;
    int32 ItemID[MAX_OUTFIT_ITEMS];
    uint32 PetDisplayID;                                            // Pet Model ID for starting pet
    uint8 RaceID;
    uint8 ClassID;
    uint8 GenderID;
    uint8 OutfitID;
    uint8 PetFamilyID;                                              // Pet Family Entry for starting pet
};

struct CharTitlesEntry
{
    uint32 ID;
    LocalizedString* NameMale;
    LocalizedString* NameFemale;
    uint16 MaskID;
    uint8 Flags;
};

struct ChatChannelsEntry
{
    uint32 ID;
    uint32 Flags;
    LocalizedString* Name;
    LocalizedString* Shortcut;
    uint8 FactionGroup;
};

struct ChrClassesEntry
{
    char const* PetNameToken;
    LocalizedString* Name;
    LocalizedString* NameFemale;
    LocalizedString* NameMale;
    char const* Filename;
    uint32 CreateScreenFileDataID;
    uint32 SelectScreenFileDataID;
    uint32 IconFileDataID;
    uint32 LowResScreenFileDataID;
    uint16 Flags;
    uint16 CinematicSequenceID;
    uint16 DefaultSpec;
    uint8 PowerType;
    uint8 SpellClassSet;
    uint8 AttackPowerPerStrength;
    uint8 AttackPowerPerAgility;
    uint8 RangedAttackPowerPerAgility;
    uint8 Unk1;
    uint32 ID;
};

struct ChrClassesXPowerTypesEntry
{
    uint32 ID;
    uint8 ClassID;
    uint8 PowerType;
};

struct ChrRacesEntry
{
    uint32 ID;
    uint32 Flags;
    uint32 MaleDisplayID;
    uint32 FemaleDisplayID;
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
    uint16 ResSicknessSpellID;
    uint16 SplashSoundID;
    uint16 CinematicSequenceID;
    uint8 BaseLanguage;
    uint8 CreatureType;
    uint8 TeamID;
    uint8 RaceRelated;
    uint8 UnalteredVisualRaceID;
    uint8 CharComponentTextureLayoutID;
    uint8 DefaultClassID;
    uint8 NeutralRaceID;
    uint8 ItemAppearanceFrameRaceID;
    uint8 CharComponentTexLayoutHiResID;
    uint32 HighResMaleDisplayID;
    uint32 HighResFemaleDisplayID;
    uint32 AlteredFormTransitionSpellVisualID[3];
    uint32 AlteredFormTransitionSpellVisualKitID[3];
};

#define MAX_MASTERY_SPELLS 2

struct ChrSpecializationEntry
{
    uint32 MasterySpellID[MAX_MASTERY_SPELLS];
    LocalizedString* Name;
    LocalizedString* Name2;
    LocalizedString* Description;
    uint8 ClassID;
    uint8 OrderIndex;
    uint8 PetTalentType;
    uint8 Role;
    uint8 PrimaryStatOrder;
    uint32 ID;
    uint32 IconFileDataID;
    uint32 Flags;
    uint32 AnimReplacementSetID;

    bool IsPetSpecialization() const
    {
        return ClassID == 0;
    }
};

struct CinematicCameraEntry
{
    uint32 ID;
    uint32 SoundID;                                         // Sound ID       (voiceover for cinematic)
    DBCPosition3D Origin;                                   // Position in map used for basis for M2 co-ordinates
    float OriginFacing;                                     // Orientation in map used for basis for M2 co-ordinates
    uint32 ModelFileDataID;                                 // Model
};

struct CinematicSequencesEntry
{
    uint32 ID;
    uint32 SoundID;
    uint16 Camera[8];
};

struct ConversationLineEntry
{
    uint32 ID;
    uint32 BroadcastTextID;
    uint32 SpellVisualKitID;
    uint32 Duration;
    uint16 NextLineID;
    uint16 Unk1;
    uint8 Yell;
    uint8 Unk2;
    uint8 Unk3;
};

struct CreatureDisplayInfoEntry
{
    uint32 ID;
    float CreatureModelScale;
    uint16 ModelID;
    uint16 NPCSoundID;
    uint8 SizeClass;
    uint8 Flags;
    int8 Gender;
    uint32 ExtendedDisplayInfoID;
    uint32 TextureVariation[3];
    uint32 PortraitTextureFileDataID;
    uint8 CreatureModelAlpha;
    uint16 SoundID;
    float PlayerModelScale;
    uint32 PortraitCreatureDisplayInfoID;
    uint8 BloodID;
    uint16 ParticleColorID;
    uint32 CreatureGeosetData;
    uint16 ObjectEffectPackageID;
    uint16 AnimReplacementSetID;
    int8 UnarmedWeaponSubclass;
    uint32 StateSpellVisualKitID;
    float InstanceOtherPlayerPetScale;                              // scale of not own player pets inside dungeons/raids/scenarios
    uint32 MountSpellVisualKitID;
};

struct CreatureDisplayInfoExtraEntry
{
    uint32 ID;
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

struct CreatureFamilyEntry
{
    uint32 ID;
    float MinScale;
    float MaxScale;
    LocalizedString* Name;
    uint32 IconFileDataID;
    uint16 SkillLine[2];
    uint16 PetFoodMask;
    uint8 MinScaleLevel;
    uint8 MaxScaleLevel;
    uint8 PetTalentType;
};

struct CreatureModelDataEntry
{
    uint32 ID;
    float ModelScale;
    float FootprintTextureLength;
    float FootprintTextureWidth;
    float FootprintParticleScale;
    float CollisionWidth;
    float CollisionHeight;
    float MountHeight;
    float GeoBoxMin[3];
    float GeoBoxMax[3];
    float WorldEffectScale;
    float AttachedEffectScale;
    float MissileCollisionRadius;
    float MissileCollisionPush;
    float MissileCollisionRaise;
    float OverrideLootEffectScale;
    float OverrideNameScale;
    float OverrideSelectionRadius;
    float TamedPetBaseScale;
    float HoverHeight;
    uint32 Flags;
    uint32 FileDataID;
    uint32 SizeClass;
    uint32 BloodID;
    uint32 FootprintTextureID;
    uint32 FoleyMaterialID;
    uint32 FootstepEffectID;
    uint32 DeathThudEffectID;
    uint32 SoundID;
    uint32 CreatureGeosetDataID;
};

struct CreatureTypeEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint8 Flags;                                                    // no exp? critters, non-combat pets, gas cloud.
};

struct CriteriaEntry
{
    uint32 ID;
    union AssetNameAlias
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
        // CRITERIA_TYPE_GAIN_PARAGON_REPUTATION = 206
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

        // CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT
        uint32 EquipmentSlot;

        // CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED = 205
        uint32 TransmogSetGroupID;

        // CRITERIA_TYPE_RELIC_TALENT_UNLOCKED = 211
        uint32 ArtifactPowerID;
    } Asset;
    uint32 StartAsset;
    uint32 FailAsset;
    uint32 ModifierTreeId;
    uint16 StartTimer;
    uint16 EligibilityWorldStateID;
    uint8 Type;
    uint8 StartEvent;
    uint8 FailEvent;
    uint8 Flags;
    uint8 EligibilityWorldStateValue;
};

struct CriteriaTreeEntry
{
    uint32 ID;
    uint32 Amount;
    LocalizedString* Description;
    uint16 Flags;
    uint8 Operator;
    uint32 CriteriaID;
    uint32 Parent;
    int32 OrderIndex;
};

struct CurrencyTypesEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 MaxQty;
    uint32 MaxEarnablePerWeek;
    uint32 Flags;
    LocalizedString* Description;
    uint8 CategoryID;
    uint8 SpellCategory;
    uint8 Quality;
    uint32 InventoryIconFileDataID;
    uint32 SpellWeight;
};

struct CurveEntry
{
    uint32 ID;
    uint8 Type;
    uint8 Unused;
};

struct CurvePointEntry
{
    uint32 ID;
    float X;
    float Y;
    uint16 CurveID;
    uint8 Index;
};

struct DestructibleModelDataEntry
{
    uint32 ID;
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

struct DifficultyEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint16 GroupSizeHealthCurveID;
    uint16 GroupSizeDmgCurveID;
    uint16 GroupSizeSpellPointsCurveID;
    uint8 FallbackDifficultyID;
    uint8 InstanceType;
    uint8 MinPlayers;
    uint8 MaxPlayers;
    int8 OldEnumValue;
    uint8 Flags;
    uint8 ToggleDifficultyID;
    uint8 ItemBonusTreeModID;
    uint8 OrderIndex;
};

struct DungeonEncounterEntry
{
    LocalizedString* Name;
    uint32 CreatureDisplayID;
    uint16 MapID;
    uint8 DifficultyID;
    uint8 Bit;
    uint8 Flags;
    uint32 ID;
    int32 OrderIndex;
    uint32 TextureFileDataID;
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
    float QualityMod;
};

struct EmotesEntry
{
    uint32 ID;
    char const* EmoteSlashCommand;
    uint32 SpellVisualKitID;
    uint32 EmoteFlags;
    int32 RaceMask;
    uint16 AnimID;
    uint8 EmoteSpecProc;
    uint32 EmoteSpecProcParam;
    uint32 EmoteSoundID;
    int32 ClassMask;
};

struct EmotesTextEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint16 EmoteID;
};

struct EmotesTextSoundEntry
{
    uint32 ID;
    uint16 EmotesTextId;
    uint8 RaceId;
    uint8 SexId;
    uint8 ClassId;
    uint32 SoundId;
};

struct FactionEntry
{
    uint32 ID;
    uint32 ReputationRaceMask[4];
    int32 ReputationBase[4];
    float ParentFactionModIn;                         // Faction gains incoming rep * ParentFactionModIn
    float ParentFactionModOut;                        // Faction outputs rep * ParentFactionModOut as spillover reputation
    LocalizedString* Name;
    LocalizedString* Description;
    uint32 ReputationMax[4];
    int16 ReputationIndex;
    uint16 ReputationClassMask[4];
    uint16 ReputationFlags[4];
    uint16 ParentFactionID;
    uint16 ParagonFactionID;
    uint8 ParentFactionCapIn;                         // The highest rank the faction will profit from incoming spillover
    uint8 ParentFactionCapOut;
    uint8 Expansion;
    uint8 Flags;
    uint8 FriendshipRepID;

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
    uint16 Enemies[MAX_FACTION_RELATIONS];
    uint16 Friends[MAX_FACTION_RELATIONS];
    uint8 Mask;
    uint8 FriendMask;
    uint8 EnemyMask;

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
                if (Friends[i] == entry->Faction)
                    return true;
        }
        return (FriendMask & entry->Mask) || (Mask & entry->FriendMask);
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
                if (Friends[i] == entry->Faction)
                    return false;
        }
        return (EnemyMask & entry->Mask) != 0;
    }
    bool IsHostileToPlayers() const { return (EnemyMask & FACTION_MASK_PLAYER) !=0; }
    bool IsNeutralToAll() const
    {
        for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
            if (Enemies[i] != 0)
                return false;
        return EnemyMask == 0 && FriendMask == 0;
    }
    bool IsContestedGuardFaction() const { return (Flags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD) != 0; }
    bool ShouldSparAttack() const { return (Flags & FACTION_TEMPLATE_ENEMY_SPAR) != 0; }
};

struct GameObjectsEntry
{
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
    uint32 ID;
};

struct GameObjectDisplayInfoEntry
{
    uint32 ID;
    uint32 FileDataID;
    DBCPosition3D GeoBoxMin;
    DBCPosition3D GeoBoxMax;
    float OverrideLootEffectScale;
    float OverrideNameScale;
    uint16 ObjectEffectPackageID;
};

struct GarrAbilityEntry
{
    LocalizedString* Name;
    LocalizedString* Description;
    uint32 IconFileDataID;
    uint16 Flags;
    uint16 OtherFactionGarrAbilityID;
    uint8 GarrAbilityCategoryID;
    uint8 FollowerTypeID;
    uint32 ID;
};

struct GarrBuildingEntry
{
    uint32 ID;
    uint32 HordeGameObjectID;
    uint32 AllianceGameObjectID;
    LocalizedString* NameAlliance;
    LocalizedString* NameHorde;
    LocalizedString* Description;
    LocalizedString* Tooltip;
    uint32 IconFileDataID;
    uint16 CostCurrencyID;
    uint16 HordeTexPrefixKitID;
    uint16 AllianceTexPrefixKitID;
    uint16 AllianceActivationScenePackageID;
    uint16 HordeActivationScenePackageID;
    uint16 FollowerRequiredGarrAbilityID;
    uint16 FollowerGarrAbilityEffectID;
    int16 CostMoney;
    uint8 Unknown;
    uint8 Type;
    uint8 Level;
    uint8 Flags;
    uint8 MaxShipments;
    uint8 GarrTypeID;
    int32 BuildDuration;
    int32 CostCurrencyAmount;
    int32 BonusAmount;
};

struct GarrBuildingPlotInstEntry
{
    DBCPosition2D LandmarkOffset;
    uint16 UiTextureAtlasMemberID;
    uint16 GarrSiteLevelPlotInstID;
    uint8 GarrBuildingID;
    uint32 ID;
};

struct GarrClassSpecEntry
{
    LocalizedString* NameMale;
    LocalizedString* NameFemale;
    LocalizedString* NameGenderless;
    uint16 ClassAtlasID;                                            // UiTextureAtlasMember.db2 ref
    uint16 GarrFollItemSetID;
    uint8 Limit;
    uint8 Flags;
    uint32 ID;
};

struct GarrFollowerEntry
{
    uint32 HordeCreatureID;
    uint32 AllianceCreatureID;
    LocalizedString* HordeSourceText;
    LocalizedString* AllianceSourceText;
    uint32 HordePortraitIconID;
    uint32 AlliancePortraitIconID;
    uint32 HordeAddedBroadcastTextID;
    uint32 AllianceAddedBroadcastTextID;
    LocalizedString* Name;
    uint16 HordeGarrFollItemSetID;
    uint16 AllianceGarrFollItemSetID;
    uint16 ItemLevelWeapon;
    uint16 ItemLevelArmor;
    uint16 HordeListPortraitTextureKitID;
    uint16 AllianceListPortraitTextureKitID;
    uint8 FollowerTypeID;
    uint8 HordeUiAnimRaceInfoID;
    uint8 AllianceUiAnimRaceInfoID;
    uint8 Quality;
    uint8 HordeGarrClassSpecID;
    uint8 AllianceGarrClassSpecID;
    uint8 Level;
    uint8 Unknown1;
    uint8 Flags;
    int8 Unknown2;
    int8 Unknown3;
    uint8 GarrTypeID;
    uint8 MaxDurability;
    uint8 Class;
    uint8 HordeFlavorTextGarrStringID;
    uint8 AllianceFlavorTextGarrStringID;
    uint32 ID;
};

struct GarrFollowerXAbilityEntry
{
    uint32 ID;
    uint16 GarrFollowerID;
    uint16 GarrAbilityID;
    uint8 FactionIndex;
};

struct GarrPlotEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 AllianceConstructionGameObjectID;
    uint32 HordeConstructionGameObjectID;
    uint8 GarrPlotUICategoryID;
    uint8 PlotType;
    uint8 Flags;
    uint32 MinCount;
    uint32 MaxCount;
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
    LocalizedString* Name;
    uint8 GarrPlotID;
};

struct GarrSiteLevelEntry
{
    uint32 ID;
    DBCPosition2D TownHall;
    uint16 MapID;
    uint16 SiteID;
    uint16 MovieID;
    uint16 UpgradeResourceCost;
    uint16 UpgradeMoneyCost;
    uint8 Level;
    uint8 UITextureKitID;
    uint8 Level2;
};

struct GarrSiteLevelPlotInstEntry
{
    uint32 ID;
    DBCPosition2D Landmark;
    uint16 GarrSiteLevelID;
    uint8 GarrPlotInstanceID;
    uint8 Unknown;
};

struct GemPropertiesEntry
{
    uint32 ID;
    uint32 Type;
    uint16 EnchantID;
    uint16 MinItemLevel;
};

struct GlyphBindableSpellEntry
{
    uint32 ID;
    uint32 SpellID;
    uint16 GlyphPropertiesID;
};

struct GlyphPropertiesEntry
{
    uint32 ID;
    uint32 SpellID;
    uint16 SpellIconID;
    uint8 Type;
    uint8 GlyphExclusiveCategoryID;
};

struct GlyphRequiredSpecEntry
{
    uint32 ID;
    uint16 GlyphPropertiesID;
    uint16 ChrSpecializationID;
};

struct GuildColorBackgroundEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct GuildColorBorderEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct GuildColorEmblemEntry
{
    uint32 ID;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct GuildPerkSpellsEntry
{
    uint32 ID;
    uint32 SpellID;
};

struct HeirloomEntry
{
    uint32 ItemID;
    LocalizedString* SourceText;
    uint32 OldItem[2];
    uint32 NextDifficultyItemID;
    uint32 UpgradeItemID[3];
    uint16 ItemBonusListID[3];
    uint8 Flags;
    uint8 Source;
    uint32 ID;
};

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 16
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32 ID;
    uint32 Date[MAX_HOLIDAY_DATES];                                 // dates in unix time starting at January, 1, 2000
    uint16 Duration[MAX_HOLIDAY_DURATIONS];
    uint16 Region;
    uint8 Looping;
    uint8 CalendarFlags[MAX_HOLIDAY_FLAGS];
    uint8 Priority;
    int8 CalendarFilterType;
    uint8 Flags;
    uint32 HolidayNameID;
    uint32 HolidayDescriptionID;
    int32 TextureFileDataID[3];
};

struct ImportPriceArmorEntry
{
    uint32 ID;
    float ClothFactor;
    float LeatherFactor;
    float MailFactor;
    float PlateFactor;
};

struct ImportPriceQualityEntry
{
    uint32 ID;
    float Factor;
};

struct ImportPriceShieldEntry
{
    uint32 ID;
    float Factor;
};

struct ImportPriceWeaponEntry
{
    uint32 ID;
    float Factor;
};

struct ItemEntry
{
    uint32 ID;
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
    uint32 ID;
    uint32 DisplayID;
    uint32 IconFileDataID;
    uint32 UIOrder;
    uint8 ObjectComponentSlot;
};

struct ItemArmorQualityEntry
{
    uint32 ID;
    float QualityMod[7];
    uint16 ItemLevel;
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
    float Value[4];
    uint16 ItemLevel;
};

struct ItemBagFamilyEntry
{
    uint32 ID;
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

struct ItemBonusListLevelDeltaEntry
{
    int16 Delta;
    uint32 ID;
};

struct ItemBonusTreeNodeEntry
{
    uint32 ID;
    uint16 BonusTreeID;
    uint16 SubTreeID;
    uint16 BonusListID;
    uint16 ItemLevelSelectorID;
    uint8 BonusTreeModID;
};

struct ItemChildEquipmentEntry
{
    uint32 ID;
    uint32 ItemID;
    uint32 AltItemID;
    uint8 AltEquipmentSlot;
};

struct ItemClassEntry
{
    uint32 ID;
    float PriceMod;
    LocalizedString* Name;
    uint8 OldEnumValue;
    uint8 Flags;
};

struct ItemCurrencyCostEntry
{
    uint32 ID;
    uint32 ItemId;
};

struct ItemDamageAmmoEntry
{
    uint32 ID;
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageOneHandEntry
{
    uint32 ID;
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageOneHandCasterEntry
{
    uint32 ID;
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageTwoHandEntry
{
    uint32 ID;
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDamageTwoHandCasterEntry
{
    uint32 ID;
    float DPS[7];
    uint16 ItemLevel;
};

struct ItemDisenchantLootEntry
{
    uint32 ID;
    uint16 MinItemLevel;
    uint16 MaxItemLevel;
    uint16 RequiredDisenchantSkill;
    uint8 ItemClass;
    int8 ItemSubClass;
    uint8 ItemQuality;
};

struct ItemEffectEntry
{
    uint32 ID;
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
    uint32 ID;
    uint32 RequiredItem[MAX_ITEM_EXT_COST_ITEMS];                   // required item id
    uint32 RequiredCurrencyCount[MAX_ITEM_EXT_COST_CURRENCIES];     // required curency count
    uint16 RequiredItemCount[MAX_ITEM_EXT_COST_ITEMS];              // required count of 1st item
    uint16 RequiredPersonalArenaRating;                             // required personal arena rating
    uint16 RequiredCurrency[MAX_ITEM_EXT_COST_CURRENCIES];          // required curency id
    uint8 RequiredArenaSlot;                                        // arena slot restrictions (min slot value)
    uint8 RequiredFactionId;
    uint8 RequiredFactionStanding;
    uint8 RequirementFlags;
    uint8 RequiredAchievement;
};

struct ItemLevelSelectorEntry
{
    uint32 ID;
    uint16 ItemLevel;
    uint16 ItemLevelSelectorQualitySetID;
};

struct ItemLevelSelectorQualityEntry
{
    uint32 ID;
    uint32 ItemBonusListID;
    uint16 ItemLevelSelectorQualitySetID;
    uint8 Quality;
};

struct ItemLevelSelectorQualitySetEntry
{
    uint32 ID;
    uint16 ItemLevelMin;
    uint16 ItemLevelMax;
};

struct ItemLimitCategoryEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint8 Quantity;
    uint8 Flags;
};

struct ItemModifiedAppearanceEntry
{
    uint32 ItemID;
    uint16 AppearanceID;
    uint8 AppearanceModID;
    uint8 Index;
    uint8 SourceType;
    uint32 ID;
};

struct ItemPriceBaseEntry
{
    uint32 ID;
    float ArmorFactor;
    float WeaponFactor;
    uint16 ItemLevel;
};

#define MAX_ITEM_RANDOM_PROPERTIES 5

struct ItemRandomPropertiesEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint16 Enchantment[MAX_ITEM_RANDOM_PROPERTIES];
};

struct ItemRandomSuffixEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint16 Enchantment[MAX_ITEM_RANDOM_PROPERTIES];
    uint16 AllocationPct[MAX_ITEM_RANDOM_PROPERTIES];
};

struct ItemSearchNameEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 Flags[3];
    uint32 AllowableRace;
    uint16 ItemLevel;
    uint8 Quality;
    uint8 RequiredExpansion;
    uint8 RequiredLevel;
    int32 AllowableClass;
    uint16 RequiredReputationFaction;
    uint8 RequiredReputationRank;
    uint16 RequiredSkill;
    uint16 RequiredSkillRank;
    uint32 RequiredSpell;
};

#define MAX_ITEM_SET_ITEMS 17

struct ItemSetEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 ItemID[MAX_ITEM_SET_ITEMS];
    uint16 RequiredSkillRank;
    uint32 RequiredSkill;
    uint32 Flags;
};

struct ItemSetSpellEntry
{
    uint32 ID;
    uint32 SpellID;
    uint16 ItemSetID;
    uint16 ChrSpecID;
    uint8 Threshold;
};

struct ItemSparseEntry
{
    uint32 ID;
    uint32 Flags[MAX_ITEM_PROTO_FLAGS];
    float Unk1;
    float Unk2;
    uint32 BuyCount;
    uint32 BuyPrice;
    uint32 SellPrice;
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
    int16 AllowableClass;
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
    uint16 TotemCategory;
    uint16 SocketBonus;
    uint16 GemProperties;
    uint16 ItemLimitCategory;
    uint16 HolidayID;
    uint16 RequiredTransmogHolidayID;
    uint16 ItemNameDescriptionID;
    uint8 Quality;
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
    uint8 SocketColor[MAX_ITEM_PROTO_SOCKETS];
    uint8 CurrencySubstitutionID;
    uint8 CurrencySubstitutionCount;
    uint8 ArtifactID;
    uint8 RequiredExpansion;
};

struct ItemSpecEntry
{
    uint32 ID;
    uint16 SpecID;
    uint8 MinLevel;
    uint8 MaxLevel;
    uint8 ItemType;
    uint8 PrimaryStat;
    uint8 SecondaryStat;
};

struct ItemSpecOverrideEntry
{
    uint32 ID;
    uint32 ItemID;
    uint16 SpecID;
};

struct ItemUpgradeEntry
{
    uint32 ID;
    uint32 CurrencyCost;
    uint16 PrevItemUpgradeID;
    uint16 CurrencyID;
    uint8 ItemUpgradePathID;
    uint8 ItemLevelBonus;
};

struct ItemXBonusTreeEntry
{
    uint32 ID;
    uint32 ItemID;
    uint16 BonusTreeID;
};

#define KEYCHAIN_SIZE   32

struct KeychainEntry
{
    uint32 ID;
    uint8 Key[KEYCHAIN_SIZE];
};

struct LFGDungeonsEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 Flags;
    LocalizedString* Description;
    float MinItemLevel;
    uint16 MaxLevel;
    uint16 TargetLevelMax;
    int16 MapID;
    uint16 RandomID;
    uint16 ScenarioID;
    uint16 LastBossJournalEncounterID;
    uint16 BonusReputationAmount;
    uint16 MentorItemLevel;
    uint16 PlayerConditionID;
    uint8 MinLevel;
    uint8 TargetLevel;
    uint8 TargetLevelMin;
    uint8 DifficultyID;
    uint8 Type;
    uint8 Faction;
    uint8 Expansion;
    uint8 OrderIndex;
    uint8 GroupID;
    uint8 CountTank;
    uint8 CountHealer;
    uint8 CountDamage;
    uint8 MinCountTank;
    uint8 MinCountHealer;
    uint8 MinCountDamage;
    uint8 SubType;
    uint8 MentorCharLevel;
    int32 TextureFileDataID;
    int32 RewardIconFileDataID;
    int32 ProposalTextureFileDataID;

    // Helpers
    uint32 Entry() const { return ID + (Type << 24); }
};

struct LightEntry
{
    uint32 ID;
    DBCPosition3D Pos;
    float FalloffStart;
    float FalloffEnd;
    uint16 MapID;
    uint16 LightParamsID[8];
};

struct LiquidTypeEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 SpellID;
    float MaxDarkenDepth;
    float FogDarkenIntensity;
    float AmbDarkenIntensity;
    float DirDarkenIntensity;
    float ParticleScale;
    char const* Texture[6];
    uint32 Color[2];
    float Float[18];
    uint32 Int[4];
    uint16 Flags;
    uint16 LightID;
    uint8 Type;
    uint8 ParticleMovement;
    uint8 ParticleTexSlots;
    uint8 MaterialID;
    uint8 DepthTexCount[6];
    uint32 SoundID;
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32 ID;
    uint32 Index[MAX_LOCK_CASE];
    uint16 Skill[MAX_LOCK_CASE];
    uint8 Type[MAX_LOCK_CASE];
    uint8 Action[MAX_LOCK_CASE];
};

struct MailTemplateEntry
{
    uint32 ID;
    LocalizedString* Body;
};

struct MapEntry
{
    uint32 ID;
    char* Directory;
    uint32 Flags[2];
    float MinimapIconScale;
    DBCPosition2D CorpsePos;                                        // entrance coordinates in ghost mode  (in most cases = normal entrance)
    LocalizedString* MapName;
    LocalizedString* MapDescription0;                               // Horde
    LocalizedString* MapDescription1;                               // Alliance
    LocalizedString* ShortDescription;
    LocalizedString* LongDescription;
    uint16 AreaTableID;
    uint16 LoadingScreenID;
    int16 CorpseMapID;                                              // map_id of entrance map in ghost mode (continent always and in most cases = normal entrance)
    uint16 TimeOfDayOverride;
    int16 ParentMapID;
    int16 CosmeticParentMapID;
    uint16 WindSettingsID;
    uint8 InstanceType;
    uint8 unk5;
    uint8 ExpansionID;
    uint8 MaxPlayers;
    uint8 TimeOffset;

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
        x = CorpsePos.X;
        y = CorpsePos.Y;
        return true;
    }

    bool IsContinent() const
    {
        return ID == 0 || ID == 1 || ID == 530 || ID == 571 || ID == 870 || ID == 1116 || ID == 1220;
    }

    bool IsDynamicDifficultyMap() const { return (Flags[0] & MAP_FLAG_CAN_TOGGLE_DIFFICULTY) != 0; }
    bool IsGarrison() const { return (Flags[0] & MAP_FLAG_GARRISON) != 0; }
};

struct MapDifficultyEntry
{
    uint32 ID;
    LocalizedString* Message_lang;                          // m_message_lang (text showed when transfer to map failed)
    uint16 MapID;
    uint8 DifficultyID;
    uint8 RaidDurationType;                                 // 1 means daily reset, 2 means weekly
    uint8 MaxPlayers;                                       // m_maxPlayers some heroic versions have 0 when expected same amount as in normal version
    uint8 LockID;
    uint8 Flags;
    uint8 ItemBonusTreeModID;
    uint32 Context;

    uint32 GetRaidDuration() const
    {
        if (RaidDurationType == 1)
            return 86400;
        if (RaidDurationType == 2)
            return 604800;
        return 0;
    }
};

struct ModifierTreeEntry
{
    uint32 ID;
    uint32 Asset[2];
    uint32 Parent;
    uint8 Type;
    uint8 Unk700;
    uint8 Operator;
    uint8 Amount;
};

struct MountEntry
{
    uint32 SpellId;
    LocalizedString* Name;
    LocalizedString* Description;
    LocalizedString* SourceDescription;
    float CameraPivotMultiplier;
    uint16 MountTypeId;
    uint16 Flags;
    uint8 Source;
    uint32 ID;
    uint32 PlayerConditionId;
    int32 UiModelSceneID;
};

struct MountCapabilityEntry
{
    uint32 RequiredSpell;
    uint32 SpeedModSpell;
    uint16 RequiredRidingSkill;
    uint16 RequiredArea;
    int16 RequiredMap;
    uint8 Flags;
    uint32 ID;
    uint32 RequiredAura;
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
    uint32 MountID;
    uint32 DisplayID;
    uint32 PlayerConditionID;
};

struct MovieEntry
{
    uint32 ID;
    uint32 AudioFileDataID;
    uint32 SubtitleFileDataID;
    uint8 Volume;
    uint8 KeyID;
};

struct NameGenEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint8 Race;
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

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32 ID;
    uint32 SpellID[MAX_OVERRIDE_SPELL];
    uint32 PlayerActionbarFileDataID;
    uint8 Flags;
};

struct PhaseEntry
{
    uint32 ID;
    uint16 Flags;
};

struct PhaseXPhaseGroupEntry
{
    uint32 ID;
    uint16 PhaseID;
    uint16 PhaseGroupID;
};

struct PlayerConditionEntry
{
    uint32 ID;
    uint32 RaceMask;
    uint32 Time[2];
    uint32 AuraSpellID[4];
    LocalizedString* FailureDescription;
    uint16 SkillID[4];
    int16 MinSkill[4];
    int16 MaxSkill[4];
    uint16 PrevQuestID[4];
    uint16 CurrQuestID[4];
    uint16 CurrentCompletedQuestID[4];
    uint16 Explored[2];
    uint16 Achievement[4];
    uint16 AreaID[4];
    uint8 Flags;
    uint8 MinReputation[3];
    uint8 AuraCount[4];
    uint8 LfgStatus[4];
    uint8 LfgCompare[4];
    uint8 CurrencyCount[4];
    int32 ClassMask;
    uint32 MinFactionID[3];
    uint32 SpellID[4];
    uint32 ItemID[4];
    uint32 ItemCount[4];
    uint32 LfgValue[4];
    uint32 CurrencyID[4];
    uint32 QuestKillMonster[6];
    int32 MovementFlags[2];
    uint16 MinLevel;
    uint16 MaxLevel;
    int8 Gender;
    int8 NativeGender;
    uint32 SkillLogic;
    uint8 LanguageID;
    uint8 MinLanguage;
    uint32 MaxLanguage;
    uint16 MaxFactionID;
    uint8 MaxReputation;
    uint32 ReputationLogic;
    uint8 Unknown1;
    uint8 MinPVPRank;
    uint8 MaxPVPRank;
    uint8 PvpMedal;
    uint32 PrevQuestLogic;
    uint32 CurrQuestLogic;
    uint32 CurrentCompletedQuestLogic;
    uint32 SpellLogic;
    uint32 ItemLogic;
    uint8 ItemFlags;
    uint32 AuraSpellLogic;
    uint16 WorldStateExpressionID;
    uint8 WeatherID;
    uint8 PartyStatus;
    uint8 LifetimeMaxPVPRank;
    uint32 AchievementLogic;
    uint32 LfgLogic;
    uint32 AreaLogic;
    uint32 CurrencyLogic;
    uint16 QuestKillID;
    uint32 QuestKillLogic;
    int8 MinExpansionLevel;
    int8 MaxExpansionLevel;
    int8 MinExpansionTier;
    int8 MaxExpansionTier;
    uint8 MinGuildLevel;
    uint8 MaxGuildLevel;
    uint8 PhaseUseFlags;
    uint16 PhaseID;
    uint32 PhaseGroupID;
    uint32 MinAvgItemLevel;
    uint32 MaxAvgItemLevel;
    uint16 MinAvgEquippedItemLevel;
    uint16 MaxAvgEquippedItemLevel;
    int8 ChrSpecializationIndex;
    int8 ChrSpecializationRole;
    int8 PowerType;
    int8 PowerTypeComp;
    int8 PowerTypeValue;
    uint32 ModifierTreeID;
    uint32 MainHandItemSubclassMask;
};

struct PowerDisplayEntry
{
    uint32 ID;
    char const* GlobalStringBaseTag;
    uint8 PowerType;
    uint8 Red;
    uint8 Green;
    uint8 Blue;
};

struct PowerTypeEntry
{
    uint32 ID;
    char const* PowerTypeToken;
    char const* PowerCostToken;
    float RegenerationPeace;
    float RegenerationCombat;
    int16 MaxPower;
    uint16 RegenerationDelay;
    uint16 Flags;
    uint8 PowerTypeEnum;
    int8 RegenerationMin;
    int8 RegenerationCenter;
    int8 RegenerationMax;
    uint8 UIModifier;
};

struct PrestigeLevelInfoEntry
{
    uint32 ID;
    uint32 IconID;
    LocalizedString* PrestigeText;
    uint8 PrestigeLevel;
    uint8 Flags;

    bool IsDisabled() const { return (Flags & PRESTIGE_FLAG_DISABLED) != 0; }
};

struct PVPDifficultyEntry
{
    uint32 ID;
    uint16 MapID;
    uint8 BracketID;
    uint8 MinLevel;
    uint8 MaxLevel;

    // helpers
    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(BracketID); }
};

struct PvpRewardEntry
{
    uint32 ID;
    uint32 HonorLevel;
    uint32 Prestige;
    uint32 RewardPackID;
};

struct QuestFactionRewardEntry
{
    uint32 ID;
    int16 QuestRewFactionValue[10];
};

struct QuestMoneyRewardEntry
{
    uint32 ID;
    uint32 Money[10];
};

struct QuestPackageItemEntry
{
    uint32 ID;
    uint32 ItemID;
    uint16 QuestPackageID;
    uint8 FilterType;
    uint32 ItemCount;
};

struct QuestSortEntry
{
    uint32 ID;
    LocalizedString* SortName;
    uint8 SortOrder;
};

struct QuestV2Entry
{
    uint32 ID;
    uint16 UniqueBitFlag;
};

struct QuestXPEntry
{
    uint32 ID;
    uint16 Exp[10];
};

struct RandPropPointsEntry
{
    uint32 ID;
    uint32 EpicPropertiesPoints[5];
    uint32 RarePropertiesPoints[5];
    uint32 UncommonPropertiesPoints[5];
};

struct RewardPackEntry
{
    uint32 ID;
    uint32 Money;
    float ArtifactXPMultiplier;
    uint8 ArtifactXPDifficulty;
    uint8 ArtifactCategoryID;
    uint32 TitleID;
    uint32 Unused;
};

struct RewardPackXItemEntry
{
    uint32 ID;
    uint32 ItemID;
    uint32 RewardPackID;
    uint32 Amount;
};

struct RulesetItemUpgradeEntry
{
    uint32 ID;
    uint32 ItemID;
    uint16 ItemUpgradeID;
};

struct ScalingStatDistributionEntry
{
    uint32 ID;
    uint16 ItemLevelCurveID;
    uint32 MinLevel;
    uint32 MaxLevel;
};

struct ScenarioEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint16 Data;                                                    // Seems to indicate different things, for zone invasions, this is the area id
    uint8 Flags;
    uint8 Type;
};

struct ScenarioStepEntry
{
    uint32 ID;
    LocalizedString* Description;
    LocalizedString* Name;
    uint16 ScenarioID;
    uint16 PreviousStepID;                                          // Used in conjunction with Proving Grounds scenarios, when sequencing steps (Not using step order?)
    uint16 QuestRewardID;
    uint8 Step;
    uint8 Flags;
    uint32 CriteriaTreeID;
    uint32 BonusRequiredStepID;                                     // Bonus step can only be completed if scenario is in the step specified in this field

    // helpers
    bool IsBonusObjective() const
    {
        return Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE;
    }
};

struct SceneScriptEntry
{
    uint32 ID;
    char const* Name;
    char const* Script;
    uint16 PrevScriptId;
    uint16 NextScriptId;
};

struct SceneScriptPackageEntry
{
    uint32 ID;
    char const* Name;
};

struct SkillLineEntry
{
    uint32 ID;
    LocalizedString* DisplayName;
    LocalizedString* Description;
    LocalizedString* AlternateVerb;
    uint16 Flags;
    uint8 CategoryID;
    uint8 CanLink;
    uint32 IconFileDataID;
    uint32 ParentSkillLineID;
};

struct SkillLineAbilityEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 RaceMask;
    uint32 SupercedesSpell;
    uint16 SkillLine;
    uint16 MinSkillLineRank;
    uint16 TrivialSkillLineRankHigh;
    uint16 TrivialSkillLineRankLow;
    uint16 UniqueBit;
    uint16 TradeSkillCategoryID;
    uint8 AcquireMethod;
    uint8 NumSkillUps;
    uint8 Unknown703;
    int32 ClassMask;
};

struct SkillRaceClassInfoEntry
{
    uint32 ID;
    int32 RaceMask;
    uint16 SkillID;
    uint16 Flags;
    uint16 SkillTierID;
    uint8 Availability;
    uint8 MinLevel;
    int32 ClassMask;
};

struct SoundKitEntry
{
    uint32 ID;
    float VolumeFloat;
    float MinDistance;
    float DistanceCutoff;
    uint16 Flags;
    uint16 SoundEntriesAdvancedID;
    uint8 SoundType;
    uint8 DialogType;
    uint8 EAXDef;
    float VolumeVariationPlus;
    float VolumeVariationMinus;
    float PitchVariationPlus;
    float PitchVariationMinus;
    float PitchAdjust;
    uint16 BusOverwriteID;
    uint8 Unk700;
};

struct SpecializationSpellsEntry
{
    uint32 SpellID;
    uint32 OverridesSpellID;
    LocalizedString* Description;
    uint16 SpecID;
    uint8 OrderIndex;
    uint32 ID;
};

struct SpellEntry
{
    LocalizedString* Name;
    LocalizedString* NameSubtext;
    LocalizedString* Description;
    LocalizedString* AuraDescription;
    uint32 MiscID;
    uint32 ID;
    uint32 DescriptionVariablesID;
};

struct SpellAuraOptionsEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 ProcCharges;
    uint32 ProcTypeMask;
    uint32 ProcCategoryRecovery;
    uint16 CumulativeAura;
    uint16 SpellProcsPerMinuteID;
    uint8 DifficultyID;
    uint8 ProcChance;
};

struct SpellAuraRestrictionsEntry
{
    uint32 ID;
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
    uint32 ID;
    int32 CastTime;
    int32 MinCastTime;
    int16 CastTimePerLevel;
};

struct SpellCastingRequirementsEntry
{
    uint32 ID;
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
    uint32 ID;
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
    uint32 ID;
    LocalizedString* Name;
    int32 ChargeRecoveryTime;
    uint8 Flags;
    uint8 UsesPerWeek;
    uint8 MaxCharges;
    uint32 ChargeCategoryType;
};

struct SpellClassOptionsEntry
{
    uint32 ID;
    uint32 SpellID;
    flag128 SpellClassMask;
    uint8 SpellClassSet;
    uint32 ModalNextSpell;
};

struct SpellCooldownsEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 CategoryRecoveryTime;
    uint32 RecoveryTime;
    uint32 StartRecoveryTime;
    uint8 DifficultyID;
};

struct SpellDurationEntry
{
    uint32 ID;
    int32 Duration;
    int32 MaxDuration;
    int32 DurationPerLevel;
};

struct SpellEffectEntry
{
    flag128 EffectSpellClassMask;
    uint32 ID;
    uint32 SpellID;
    uint32 Effect;
    uint32 EffectAura;
    int32 EffectBasePoints;
    uint32 EffectIndex;
    int32 EffectMiscValue;
    int32 EffectMiscValueB;
    uint32 EffectRadiusIndex;
    uint32 EffectRadiusMaxIndex;
    uint32 ImplicitTarget[2];
    uint32 DifficultyID;
    float EffectAmplitude;
    uint32 EffectAuraPeriod;
    float EffectBonusCoefficient;
    float EffectChainAmplitude;
    uint32 EffectChainTargets;
    int32 EffectDieSides;
    uint32 EffectItemType;
    uint32 EffectMechanic;
    float EffectPointsPerResource;
    float EffectRealPointsPerLevel;
    uint32 EffectTriggerSpell;
    float EffectPosFacing;
    uint32 EffectAttributes;
    float BonusCoefficientFromAP;
    float PvPMultiplier;
};

struct SpellEffectScalingEntry
{
    uint32 ID;
    float Coefficient;
    float Variance;
    float ResourceCoefficient;
    uint32 SpellEffectID;
};

struct SpellEquippedItemsEntry
{
    uint32 ID;
    uint32 SpellID;
    int32 EquippedItemInventoryTypeMask;
    int32 EquippedItemSubClassMask;
    int8 EquippedItemClass;
};

struct SpellFocusObjectEntry
{
    uint32 ID;
    LocalizedString* Name;
};

struct SpellInterruptsEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 AuraInterruptFlags[MAX_SPELL_AURA_INTERRUPT_FLAGS];
    uint32 ChannelInterruptFlags[MAX_SPELL_AURA_INTERRUPT_FLAGS];
    uint16 InterruptFlags;
    uint8 DifficultyID;
};

#define MAX_ITEM_ENCHANTMENT_EFFECTS 3

struct SpellItemEnchantmentEntry
{
    uint32 ID;
    uint32 EffectSpellID[MAX_ITEM_ENCHANTMENT_EFFECTS];
    LocalizedString* Name;
    float EffectScalingPoints[MAX_ITEM_ENCHANTMENT_EFFECTS];
    uint32 TransmogCost;
    uint32 TextureFileDataID;
    uint16 EffectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS];
    uint16 ItemVisual;
    uint16 Flags;
    uint16 RequiredSkillID;
    uint16 RequiredSkillRank;
    uint16 ItemLevel;
    uint8 Charges;
    uint8 Effect[MAX_ITEM_ENCHANTMENT_EFFECTS];
    uint8 ConditionID;
    uint8 MinLevel;
    uint8 MaxLevel;
    int8 ScalingClass;
    int8 ScalingClassRestricted;
    uint32 PlayerConditionID;
};

struct SpellItemEnchantmentConditionEntry
{
    uint32 ID;
    uint8 LTOperandType[5];
    uint8 Operator[5];
    uint8 RTOperandType[5];
    uint8 RTOperand[5];
    uint8 Logic[5];
    uint32 LTOperand[5];
};

struct SpellLearnSpellEntry
{
    uint32 ID;
    uint32 LearnSpellID;
    uint32 SpellID;
    uint32 OverridesSpellID;
};

struct SpellLevelsEntry
{
    uint32 ID;
    uint32 SpellID;
    uint16 BaseLevel;
    uint16 MaxLevel;
    uint16 SpellLevel;
    uint8 DifficultyID;
    uint8 MaxUsableLevel;
};

struct SpellMiscEntry
{
    uint32 ID;
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
    uint8 SchoolMask;
    uint32 IconFileDataID;
    uint32 ActiveIconFileDataID;
};

struct SpellPowerEntry
{
    uint32 SpellID;
    int32 ManaCost;
    float ManaCostPercentage;
    float ManaCostPercentagePerSecond;
    uint32 RequiredAura;
    float HealthCostPercentage;
    uint8 PowerIndex;
    uint8 PowerType;
    uint32 ID;
    int32 ManaCostPerLevel;
    int32 ManaCostPerSecond;
    int32 ManaCostAdditional;                                       // Spell uses [ManaCost, ManaCost+ManaCostAdditional] power - affects tooltip parsing as multiplier on SpellEffectEntry::EffectPointsPerResource
                                                                    //   only SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE, SPELL_EFFECT_WEAPON_DAMAGE, SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    uint32 PowerDisplayID;
    uint32 UnitPowerBarID;
};

struct SpellPowerDifficultyEntry
{
    uint8 DifficultyID;
    uint8 PowerIndex;
    uint32 ID;
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
    float Coeff;
    uint16 Param;
    uint16 SpellProcsPerMinuteID;
    uint8 Type;
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
    uint32 ID;
    uint32 SpellID;
    int32 Reagent[MAX_SPELL_REAGENTS];
    uint16 ReagentCount[MAX_SPELL_REAGENTS];
};

struct SpellScalingEntry
{
    uint32 ID;
    uint32 SpellID;
    uint16 ScalesFromItemLevel;
    int32 ScalingClass;
    uint32 MinScalingLevel;
    uint32 MaxScalingLevel;
};

struct SpellShapeshiftEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 ShapeshiftExclude[2];
    uint32 ShapeshiftMask[2];
    uint8 StanceBarOrder;
};

#define MAX_SHAPESHIFT_SPELLS 8

struct SpellShapeshiftFormEntry
{
    uint32 ID;
    LocalizedString* Name;
    float WeaponDamageVariance;
    uint32 Flags;
    uint16 CombatRoundTime;
    uint16 MountTypeID;
    int8 CreatureType;
    uint8 BonusActionBar;
    uint32 AttackIconFileDataID;
    uint32 CreatureDisplayID[4];
    uint32 PresetSpellID[MAX_SHAPESHIFT_SPELLS];
};

struct SpellTargetRestrictionsEntry
{
    uint32 ID;
    uint32 SpellID;
    float ConeAngle;
    float Width;
    uint32 Targets;
    uint16 TargetCreatureType;
    uint8 DifficultyID;
    uint8 MaxAffectedTargets;
    uint32 MaxTargetLevel;
};

#define MAX_SPELL_TOTEMS 2

struct SpellTotemsEntry
{
    uint32 ID;
    uint32 SpellID;
    uint32 Totem[MAX_SPELL_TOTEMS];
    uint16 RequiredTotemCategoryID[MAX_SPELL_TOTEMS];
};

struct SpellXSpellVisualEntry
{
    uint32 SpellID;
    uint32 SpellVisualID;
    uint32 ID;
    float Chance;
    uint16 CasterPlayerConditionID;
    uint16 CasterUnitConditionID;
    uint16 PlayerConditionID;
    uint16 UnitConditionID;
    uint32 IconFileDataID;
    uint32 ActiveIconFileDataID;
    uint8 Flags;
    uint8 DifficultyID;
    uint8 Priority;
};

struct SummonPropertiesEntry
{
    uint32 ID;
    uint32 Flags;
    uint32 Category;
    uint32 Faction;
    int32 Type;
    int32 Slot;
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
    uint32 SpellID;
    uint32 OverridesSpellID;
    LocalizedString* Description;
    uint16 SpecID;
    uint8 TierID;
    uint8 ColumnIndex;
    uint8 Flags;
    uint8 CategoryMask[2];
    uint8 ClassID;
};

struct TaxiNodesEntry
{
    uint32 ID;
    DBCPosition3D Pos;
    LocalizedString* Name;
    uint32 MountCreatureID[2];
    DBCPosition2D MapOffset;
    float Unk730;
    DBCPosition2D FlightMapOffset;
    uint16 MapID;
    uint16 ConditionID;
    uint16 LearnableIndex;
    uint8 Flags;
    int32 UiTextureKitPrefixID;
    uint32 SpecialAtlasIconPlayerConditionID;
};

struct TaxiPathEntry
{
    uint16 From;
    uint16 To;
    uint32 ID;
    uint32 Cost;
};

struct TaxiPathNodeEntry
{
    DBCPosition3D Loc;
    uint16 PathID;
    uint16 MapID;
    uint8 NodeIndex;
    uint32 ID;
    uint8 Flags;
    uint32 Delay;
    uint16 ArrivalEventID;
    uint16 DepartureEventID;
};

struct TotemCategoryEntry
{
    uint32 ID;
    LocalizedString* Name;
    uint32 CategoryMask;
    uint8 CategoryType;
};

struct ToyEntry
{
    uint32 ItemID;
    LocalizedString* Description;
    uint8 Flags;
    uint8 CategoryFilter;
    uint32 ID;
};

struct TransmogHolidayEntry
{
    uint32 ID;
    int32 HolidayID;
};

struct TransmogSetEntry
{
    LocalizedString* Name;
    uint16 BaseSetID;
    uint16 UIOrder;
    uint8 ExpansionID;
    uint32 ID;
    int32 Flags;
    int32 QuestID;
    int32 ClassMask;
    int32 ItemNameDescriptionID;
    uint32 TransmogSetGroupID;
};

struct TransmogSetGroupEntry
{
    LocalizedString* Label;
    uint32 ID;
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
    uint32 TransportID;
    uint32 TimeIndex;
    DBCPosition3D Pos;
    uint8 SequenceID;
};

struct TransportRotationEntry
{
    uint32 ID;
    uint32 TransportID;
    uint32 TimeIndex;
    float X;
    float Y;
    float Z;
    float W;
};

struct UnitPowerBarEntry
{
    uint32 ID;
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
    uint8 CenterPower;
    uint8 BarType;
    uint32 MinPower;
    uint32 MaxPower;
};

#define MAX_VEHICLE_SEATS 8

struct VehicleEntry
{
    uint32 ID;
    uint32 Flags;
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
    uint16 SeatID[MAX_VEHICLE_SEATS];
    uint16 VehicleUIIndicatorID;
    uint16 PowerDisplayID[3];
    uint8 FlagsB;
    uint8 UILocomotionType;
    int32 MissileTargetingID;
};

struct VehicleSeatEntry
{
    uint32 ID;
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
    uint32 EnterUISoundID;
    uint32 ExitUISoundID;

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

struct WMOAreaTableEntry
{
    int32 WMOGroupID;                                               //  used in group WMO
    LocalizedString* AreaName;
    int16 WMOID;                                                    //  used in root WMO
    uint16 AmbienceID;
    uint16 ZoneMusic;
    uint16 IntroSound;
    uint16 AreaTableID;
    uint16 UWIntroSound;
    uint16 UWAmbience;
    int8 NameSet;                                                   //  used in adt file
    uint8 SoundProviderPref;
    uint8 SoundProviderPrefUnderwater;
    uint8 Flags;
    uint32 ID;
    uint32 UWZoneMusic;
};

struct WorldEffectEntry
{
    uint32 ID;
    uint32 TargetAsset;
    uint16 CombatConditionID;
    uint8 TargetType;
    uint8 WhenToDisplay;
    uint32 QuestFeedbackEffectID;
    uint32 PlayerConditionID;
};

struct WorldMapAreaEntry
{
    char const* AreaName;
    float LocLeft;
    float LocRight;
    float LocTop;
    float LocBottom;
    uint32 Flags;
    uint16 MapID;
    uint16 AreaID;
    int16 DisplayMapID;
    int16 DefaultDungeonFloor;
    uint16 ParentWorldMapID;
    uint8 LevelRangeMin;
    uint8 LevelRangeMax;
    uint8 BountySetID;
    uint8 BountyBoardLocation;
    uint32 ID;
    uint32 PlayerConditionID;
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32 ID;
    char const* TextureName;
    uint16 TextureWidth;
    uint16 TextureHeight;
    uint32 MapAreaID;                                               // idx in WorldMapArea.dbc
    uint32 AreaID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];
    int32 OffsetX;
    int32 OffsetY;
    int32 HitRectTop;
    int32 HitRectLeft;
    int32 HitRectBottom;
    int32 HitRectRight;
    uint32 PlayerConditionID;
    uint32 Flags;
};

struct WorldMapTransformsEntry
{
    uint32 ID;
    DBCPosition3D RegionMin;
    DBCPosition3D RegionMax;
    DBCPosition2D RegionOffset;
    float RegionScale;
    uint16 MapID;
    uint16 AreaID;
    uint16 NewMapID;
    uint16 NewDungeonMapID;
    uint16 NewAreaID;
    uint8 Flags;
    int32 Priority;
};

struct WorldSafeLocsEntry
{
    uint32 ID;
    DBCPosition3D Loc;
    float Facing;
    LocalizedString* AreaName;
    uint16 MapID;
};

#pragma pack(pop)
#endif
