/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITY_DBCSTRUCTURE_H
#define TRINITY_DBCSTRUCTURE_H

#include "Common.h"
#include "DBCEnums.h"
#include "Path.h"
#include "Util.h"

#include <map>
#include <set>
#include <vector>

// Structures using to access raw DBC data and required packing to portability

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push, N), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

struct AchievementEntry
{
    uint32      ID;                                         // 0
    int32       Faction;                                    // 1 -1=all, 0=horde, 1=alliance
    int32       MapID;                                      // 2 -1=none
    //uint32    Supercedes;                                 // 3 its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    char*       Title_lang;                                 // 4
    //char*     Description_lang;                           // 5
    uint32      Category;                                   // 6
    uint32      Points;                                     // 7 reward points
    //uint32    UIOrder;                                    // 8
    uint32      Flags;                                      // 9
    //uint32    IconID;                                     // 10 icon (from SpellIcon.dbc)
    //char*     Reward_lang;                                // 11
    uint32      MinimumCriteria;                            // 12 - need this count of completed criterias (own or referenced achievement criterias)
    uint32      SharesCriteria;                             // 13 - referenced achievement (counting of all completed criterias)
    uint32      CriteriaTree;                               // 14
};

struct AchievementCategoryEntry
{
    uint32      ID;                                         // 0
    uint32      Parent;                                     // 1 -1 for main category
    //char*     Name_lang;                                  // 2
    //uint32    UIOrder;                                    // 3
};

// Temporary define until max depth is found somewhere (adt?)
#define MAX_MAP_DEPTH -5000

struct AreaTableEntry
{
    uint32      ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      ParentAreaID;                               // 2 if 0 then it's zone, else it's zone id of this area
    uint32      AreaBit;                                    // 3, main index
    uint32      Flags[2];                                   // 4-5,
    //uint32    SoundProviderPref;                          // 6,
    //uint32    SoundProviderPrefUnderwater;                // 7,
    //uint32    AmbienceID;                                 // 8,
    //uint32    ZoneMusic;                                  // 9,
    char*       ZoneName;                                   // 10
    //uint32    IntroSound;                                 // 11
    uint32      ExplorationLevel;                           // 12
    //char*     AreaName_lang                               // 13
    uint32      FactionGroupMask;                           // 14
    uint32      LiquidTypeID[4];                            // 15-18
    //float     AmbientMultiplier;                          // 19
    //uint32    MountFlags;                                 // 20
    //uint32    UWIntroMusic;                               // 21
    //uint32    UWZoneMusic;                                // 22
    //uint32    UWAmbience;                                 // 23
    //uint32    WorldPvPID;                                 // 24 World_PVP_Area.dbc
    //uint32    PvPCombastWorldStateID;                     // 25
    //uint32    WildBattlePetLevelMin;                      // 26
    //uint32    WildBattlePetLevelMax;                      // 27
    //uint32    WindSettingsID;                             // 28

    // helpers
    bool IsSanctuary() const
    {
        if (MapID == 609)
            return true;
        return (Flags[0] & AREA_FLAG_SANCTUARY) != 0;
    }
};

#define MAX_GROUP_AREA_IDS 6

struct AreaGroupEntry
{
    uint32  ID;                                             // 0
    uint32  AreaID[MAX_GROUP_AREA_IDS];                     // 1-6
    uint32  NextAreaID;                                     // 7 index of next group
};

struct AreaTriggerEntry
{
    uint32          ID;                                     // 0
    uint32          MapID;                                  // 1
    DBCPosition3D   Pos;                                    // 2-4
    //uint32        PhaseUseFlags                           // 5
    //uint32        PhaseID                                 // 6
    //uint32        PhaseGroupID                            // 7
    float           Radius;                                 // 8
    float           BoxLength;                              // 9
    float           BoxWidth;                               // 10
    float           BoxHeight;                              // 11
    float           BoxYaw;                                 // 12
    //uint32        ShapeType                               // 13
    //uint32        ShapeID                                 // 14
    //uint32        AreaTriggerActionSetID                  // 15
    //uint32        Flags                                   // 16
};

struct ArmorLocationEntry
{
    uint32      ID;                                         // 0
    float       Modifier[5];                                // 1-5 multiplier for armor types (cloth...plate, no armor?)
};

struct AuctionHouseEntry
{
    uint32      ID;                                         // 0
    uint32      FactionID;                                  // 1 id of faction.dbc for player factions associated with city
    uint32      DepositRate;                                // 2 1/3 from real
    uint32      ConsignmentRate;                            // 3
    //char*     Name_lang;                                  // 4
};

struct BankBagSlotPricesEntry
{
    uint32      ID;                                         // 0
    uint32      Cost;                                       // 1
};

struct BannedAddOnsEntry
{
    uint32      ID;                                         // 0
    //uint32    NameMD5[4];                                 // 1
    //uint32    VersionMD5[4];                              // 2
    //uint32    LastModified;                               // 3
    //uint32    Flags;                                      // 4
};

struct BarberShopStyleEntry
{
    uint32      ID;                                         // 0
    uint32      Type;                                       // 1 value 0 -> hair, value 2 -> facialhair
    //char*     DisplayName_lang;                           // 2
    //char*     Description_lang                            // 3
    //float     CostModifier;                               // 4
    uint32      Race;                                       // 5
    uint32      Sex;                                        // 6
    uint32      Data;                                       // 7 (real ID to hair/facial hair)
};

struct BattlemasterListEntry
{
    uint32      ID;                                         // 0
    int32       MapID[16];                                  // 1-16 mapid
    uint32      InstanceType;                               // 17 map type (3 - BG, 4 - arena)
    //uint32    GroupsAllowed;                              // 18 (0 or 1)
    char*       Name_lang;                                  // 19
    uint32      MaxGroupSize;                               // 20 maxGroupSize, used for checking if queue as group
    uint32      HolidayWorldState;                          // 21 new 3.1
    uint32      MinLevel;                                   // 22, min level (sync with PvPDifficulty.dbc content)
    uint32      MaxLevel;                                   // 23, max level (sync with PvPDifficulty.dbc content)
    //uint32    RatedPlayers;                               // 24 4.0.1
    //uint32    MinPlayers;                                 // 25 - 4.0.6.13596
    //uint32    MaxPlayers;                                 // 26 4.0.1
    //uint32    Flags;                                      // 27 4.0.3, value 2 for Rated Battlegrounds
    //uint32    IconFileDataID;                             // 28
    //char*     GameType_lang;                              // 29
    //uint32    Unk1;                                       // 30
};

#define MAX_OUTFIT_ITEMS 24

struct CharStartOutfitEntry
{
    //uint32    ID;                                         // 0
    uint8       RaceID;                                     // 1
    uint8       ClassID;                                    // 2
    uint8       GenderID;                                   // 3
    //uint8     OutfitID;                                   // 4
    int32       ItemID[MAX_OUTFIT_ITEMS];                   // 5-28
    uint32      PetDisplayID;                               // 29 Pet Model ID for starting pet
    uint32      PetFamilyID;                                // 30 Pet Family Entry for starting pet
};

struct CharTitlesEntry
{
    uint32      ID;                                         // 0, title ids, for example in Quest::GetCharTitleId()
    //uint32    ConditionID;                                // 1
    char*       NameMale_lang;                              // 2 m_name_lang
    char*       NameFemale_lang;                            // 3 m_name1_lang
    uint32      MaskID;                                     // 4 m_mask_ID used in PLAYER_CHOSEN_TITLE and 1<<index in PLAYER__FIELD_KNOWN_TITLES
    //uint32    Flags;                                      // 5
};

struct ChatChannelsEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
    //uint32    FactionGroup                                // 2
    char*     Name_lang;                                    // 3
    //char*     Shortcut_lang;                              // 4
};

struct ChrClassesEntry
{
    uint32      ID;                                         // 0
    uint32      PowerType;                                  // 1
    //char*     PetNameToken                                // 2
    char*       Name_lang;                                  // 3
    //char*     NameFemale_lang;                            // 4
    //char*     NameMale_lang;                              // 5
    //char*     Filename;                                   // 6
    uint32      SpellClassSet;                              // 7
    //uint32    Flags;                                      // 8
    uint32      CinematicSequenceID;                        // 9
    uint32      AttackPowerPerStrength;                     // 10 Attack Power bonus per point of strength
    uint32      AttackPowerPerAgility;                      // 11 Attack Power bonus per point of agility
    uint32      RangedAttackPowerPerAgility;                // 12 Ranged Attack Power bonus per point of agility
    //uint32    DefaultSpec;                                // 13
    //uint32    CreateScreenFileDataID;                     // 14
    //uint32    SelectScreenFileDataID;                     // 15
    //uint32    LowResScreenFileDataID;                     // 16
    //uint32    IconFileDataID;                             // 17
    //uint32    Unk1;                                       // 18
};

struct ChrRacesEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
    uint32      FactionID;                                  // 2 faction template id
    //uint32    ExplorationSoundID;                         // 3
    uint32      MaleDisplayID;                              // 4
    uint32      FemaleDisplayID;                            // 5
    //char*     ClientPrefix;                               // 6
    //uint32    BaseLanguage;                               // 7
    //uint32    CreatureType;                               // 8
    //uint32    ResSicknessSpellID;                         // 9
    //uint32    SplashSoundID;                              // 10
    //char*     ClientFileString;                           // 11
    uint32      CinematicSequenceID;                        // 12
    uint32      TeamID;                                     // 13 m_alliance (0 alliance, 1 horde, 2 neutral)
    char*       Name_lang;                                  // 14
    //char*     NameFemale_lang;                            // 15
    //char*     NameMale_lang;                              // 16
    //char*     FacialHairCustomization[2];                 // 17-18
    //char*     HairCustomization;                          // 19
    //uint32    RaceRelated;                                // 20
    //uint32    UnalteredVisualRaceID;                      // 21
    //uint32    UAMaleCreatureSoundDataID;                  // 22
    //uint32    UAFemaleCreatureSoundDataID;                // 23
    //uint32    CharComponentTextureLayoutID;               // 24
    //uint32    DefaultClassID;                             // 25
    //uint32    CreateScreenFileDataID;                     // 26
    //uint32    SelectScreenFileDataID;                     // 27
    //float     MaleCustomizeOffset[3];                     // 28-30
    //float     FemaleCustomizeOffset[3];                   // 31-33
    //uint32    NeutralRaceID;                              // 34
    //uint32    LowResScreenFileDataID;                     // 35
    //uint32    HighResMaleDisplayID;                       // 36
    //uint32    HighResFemaleDisplayID;                     // 37
    //uint32    CharComponentTexLayoutHiResID;              // 38
    //uint32    Unk;                                        // 39
};

struct ChrPowerTypesEntry
{
    uint32      ID;                                         // 0
    uint32      ClassID;                                    // 1
    uint32      PowerType;                                  // 2
};

#define MAX_MASTERY_SPELLS 2

struct ChrSpecializationEntry
{
    uint32      ID;                                         // 0 Specialization ID
    //char*     BackgroundFile;                             // 1
    uint32      ClassID;                                    // 2
    uint32      MasterySpellID[MAX_MASTERY_SPELLS];         // 3
    uint32      OrderIndex;                                 // 4
    uint32      PetTalentType;                              // 5
    uint32      Role;                                       // 6 (0 - Tank, 1 - Healer, 2 - DPS)
    uint32      SpellIconID;                                // 7
    uint32      RaidBuffs;                                  // 8
    uint32      Flags;                                      // 9
    //char*     Name_lang;                                  // 10
    //char*     Name2_lang;                                 // 11 Same as name_lang?
    //char*     Description_lang;                           // 12
    uint32      PrimaryStatOrder[2];                        // 13-14
};

struct CinematicSequencesEntry
{
    uint32      ID;                                         // 0
    //uint32    SoundID;                                    // 1
    //uint32    Camera[8];                                  // 2-9
};

struct CreatureDisplayInfoEntry
{
    uint32      ID;                                         // 0
    uint32      ModelID;                                    // 1
    //uint32    SoundID;                                    // 2
    uint32      ExtendedDisplayInfoID;                      // 3
    float       CreatureModelScale;                         // 4
    //uint32    CreatureModelAlpha;                         // 5
    //char*     TextureVariation[3];                        // 6-8
    //char*     PortraitTextureName;                        // 9
    //uint32    PortraitCreatureDisplayInfoID;              // 10
    //uint32    SizeClass;                                  // 11
    //uint32    BloodID;                                    // 12
    //uint32    NPCSoundID;                                 // 13
    //uint32    ParticleColorID;                            // 14
    //uint32    CreatureGeosetData;                         // 15
    //uint32    ObjectEffectPackageID;                      // 16
    //uint32    AnimReplacementSetID;                       // 17
    //uint32    Flags;                                      // 18
    int32       Gender;                                     // 19
    //uint32    StateSpellVisualKitID;                      // 20
};

struct CreatureDisplayInfoExtraEntry
{
    //uint32    ID;                                         // 0
    uint32      DisplayRaceID;                              // 1
    //uint32    DisplaySexID;                               // 2
    //uint32    SkinID;                                     // 3
    //uint32    FaceID;                                     // 4
    //uint32    HairStyleID;                                // 5
    //uint32    HairColorID;                                // 6
    //uint32    FacialHairID;                               // 7
    //uint32    NPCItemDisplay[11];                         // 8-18
    //uint32    Flags;                                      // 19
    //uint32    FileDataID;                                 // 20
    //uint32    Unk;                                        // 21
};

struct CreatureFamilyEntry
{
    uint32      ID;                                         // 0
    float       MinScale;                                   // 1
    uint32      MinScaleLevel;                              // 2
    float       MaxScale;                                   // 3
    uint32      MaxScaleLevel;                              // 4
    uint32      SkillLine[2];                               // 5-6
    uint32      PetFoodMask;                                // 7
    uint32      PetTalentType;                              // 8
    //uint32    CategoryEnumID;                             // 9
    char*       Name_lang;                                  // 10
    //char*     IconFile;                                   // 11
};

struct CreatureModelDataEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
    //uint32    FileDataID;                                 // 2
    //uint32    SizeClass;                                  // 3
    //float     ModelScale;                                 // 4
    //uint32    BloodID;                                    // 5
    //uint32    FootprintTextureID;                         // 6
    //float     FootprintTextureLength;                     // 7
    //float     FootprintTextureWidth;                      // 8
    //float     FootprintParticleScale;                     // 9
    //uint32    FoleyMaterialID;                            // 10
    //uint32    FootstepShakeSize;                          // 11
    //uint32    DeathThudShakeSize;                         // 12
    //uint32    SoundID;                                    // 13
    //float     CollisionWidth;                             // 14
    float       CollisionHeight;                            // 15
    float       MountHeight;                                // 16
    //float     GeoBoxMin[3];                               // 17-19
    //float     GeoBoxMax[3];                               // 20-22
    //float     WorldEffectScale;                           // 23
    //float     AttachedEffectScale;                        // 24
    //float     MissileCollisionRadius;                     // 25
    //float     MissileCollisionPush;                       // 26
    //float     MissileCollisionRaise;                      // 27
    //float     OverrideLootEffectScale;                    // 28
    //float     OverrideNameScale;                          // 29
    //float     OverrideSelectionRadius;                    // 30
    //float     TamedPetBaseScale;                          // 31
    //uint32    CreatureGeosetDataID;                       // 32
    //float     HoverHeight;                                // 33
};

#define MAX_CREATURE_SPELL_DATA_SLOT 4

struct CreatureSpellDataEntry
{
    uint32      ID;                                         // 0
    uint32      Spells[MAX_CREATURE_SPELL_DATA_SLOT];       // 1-4
    //uint32    Availability[MAX_CREATURE_SPELL_DATA_SLOT]; // 4-7
};

struct CreatureTypeEntry
{
    uint32      ID;                                         // 0
    //char*     Name_lang;                                  // 1
    //uint32    Flags;                                      // 2 no exp? critters, non-combat pets, gas cloud.
};

struct CriteriaEntry
{
    uint32 ID;                                              // 0
    uint32 Type;                                            // 1
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
        uint32 AreaID;

        // ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM               = 36
        // ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM               = 41
        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM              = 42
        // ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM             = 57
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
    } Asset;                                                // 2
    uint32 StartEvent;                                      // 3
    uint32 StartAsset;                                      // 4
    uint32 StartTimer;                                      // 5
    uint32 FailEvent;                                       // 6
    uint32 FailAsset;                                       // 7
    uint32 ModifierTreeId;                                  // 8
    //uint32 Flags;                                         // 9
    uint32 EligibilityWorldStateID;                         // 10
    uint32 EligibilityWorldStateValue;                      // 11
};

struct CriteriaTreeEntry
{
    uint32 ID;                                              // 0
    uint32 CriteriaID;                                      // 1
    uint64 Amount;                                          // 2
    uint32 Operator;                                        // 3
    uint32 Parent;                                          // 4
    //uint32 Flags;                                         // 5
    //char*  DescriptionLang;                               // 6
    //uint32 OrderIndex;                                    // 7
};

/* not used
struct CurrencyCategoryEntry
{
    uint32    ID;                                           // 0
    uint32    Unk1;                                         // 1        0 for known categories and 3 for unknown one (3.0.9)
    char*   Name[16];                                       // 2-17     name
    //                                                      // 18       string flags
};
*/

struct CurrencyTypesEntry
{
    uint32      ID;                                         // 0
    uint32      CategoryID;                                 // 1
    //char*     Name_lang;                                  // 2
    //char*     InventoryIcon[2];                           // 3-4
    //uint32    SpellWeight;                                // 5 archaeology-related (?)
    //uint32    SpellCategory;                              // 6
    uint32      MaxQty;                                     // 7
    uint32      MaxEarnablePerWeek;                         // 8
    uint32      Flags;                                      // 9
    //uint32    Quality;                                    // 10
    //char*     Description_lang;                           // 11
};

struct DestructibleModelDataEntry
{
    uint32          ID;                                     // 0
    struct
    {
        uint32      DisplayID;                              // 1
        //uint32    ImpactEffectDoodadSet;                  // 2
        //uint32    AmbientDoodadSet;                       // 3
        //uint32    NameSet;                                // 4
    } StateDamaged;
    struct
    {
        uint32      DisplayID;                              // 5
        //uint32    DestructionDoodadSet;                   // 6
        //uint32    ImpactEffectDoodadSet;                  // 7
        //uint32    AmbientDoodadSet;                       // 8
        //uint32    NameSet;                                // 9
    } StateDestroyed;
    struct
    {
        uint32      DisplayID;                              // 10
        //uint32    DestructionDoodadSet;                   // 11
        //uint32    ImpactEffectDoodadSet;                  // 12
        //uint32    AmbientDoodadSet;                       // 13
        //uint32    NameSet;                                // 14
    } StateRebuilding;
    struct
    {
        uint32      DisplayID;                              // 15
        //uint32    InitDoodadSet;                          // 16
        //uint32    AmbientDoodadSet;                       // 17
        //uint32    NameSet;                                // 18
    } StateSmoke;
    //uint32        EjectDirection;                         // 19
    //uint32        RepairGroundFx;                         // 20
    //uint32        DoNotHighlight;                         // 21
    //uint32        HealEffect;                             // 22
    //uint32        HealEffectSpeed;                        // 23
};

struct DungeonEncounterEntry
{
    uint32      ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      DifficultyID;                               // 2
    uint32      OrderIndex;                                 // 3
    //uint32    Bit;                                        // 4
    char*       Name_lang;                                  // 5
    //uint32    CreatureDisplayID;                          // 6
    //uint32    Flags;                                      // 7
    //uint32    Unk;                                        // 8 Flags2?
};

struct DurabilityCostsEntry
{
    uint32      ID;                                         // 0
    uint32      WeaponSubClassCost[21];                     // 1-22
    uint32      ArmorSubClassCost[8];                       // 23-30
};

struct DurabilityQualityEntry
{
    uint32      ID;                                         // 0
    float       QualityMod;                                 // 1
};

struct EmotesEntry
{
    uint32      ID;                                         // 0
    //char*     EmoteSlashCommand;                          // 1
    //uint32    AnimID;                                     // 2 ref to animationData
    uint32      EmoteFlags;                                 // 3 bitmask, may be unit_flags
    uint32      EmoteSpecProc;                              // 4 Can be 0, 1 or 2 (determine how emote are shown)
    uint32      EmoteSpecProcParam;                         // 5 uncomfirmed, may be enum UnitStandStateType
    //uint32    EmoteSoundID;                               // 6 ref to soundEntries
    //uint32    SpellVisualKitID                            // 7
};

struct EmotesTextEntry
{
    uint32      ID;                                         // 0
    //char*     Name_lang;                                  // 1
    uint32      EmoteID;                                    // 2
    //uint32    EmoteText[16];                              // 3-18
};

struct FactionEntry
{
    uint32      ID;                                         // 0
    int32       ReputationIndex;                            // 1
    uint32      ReputationRaceMask[4];                      // 2-5
    uint32      ReputationClassMask[4];                     // 6-9
    int32       ReputationBase[4];                          // 10-13
    uint32      ReputationFlags[4];                         // 14-17
    uint32      ParentFactionID;                            // 18
    float       ParentFactionModIn;                         // 19 Faction gains incoming rep * ParentFactionModIn
    float       ParentFactionModOut;                        // 20 Faction outputs rep * ParentFactionModOut as spillover reputation
    uint32      ParentFactionCapIn;                         // 21 The highest rank the faction will profit from incoming spillover
    //uint32    ParentFactionCapOut;                        // 22
    char*       Name_lang;                                  // 23
    //char*     Description_lang;                           // 24
    uint32      Expansion;                                  // 25
    //uint32    Flags;                                      // 26
    //uint32    FriendshipRepID;                            // 27

    // helpers
    bool CanHaveReputation() const
    {
        return ReputationIndex >= 0;
    }
};

#define MAX_FACTION_RELATIONS 4

struct FactionTemplateEntry
{
    uint32      ID;                                         // 0
    uint32      Faction;                                    // 1
    uint32      Flags;                                      // 2
    uint32      Mask;                                       // 3 m_factionGroup
    uint32      FriendMask;                                 // 4 m_friendGroup
    uint32      EnemyMask;                                  // 5 m_enemyGroup
    uint32      Enemies[MAX_FACTION_RELATIONS];             // 6
    uint32      Friends[MAX_FACTION_RELATIONS];             // 10
    //-------------------------------------------------------  end structure

    // helpers
    bool IsFriendlyTo(FactionTemplateEntry const& entry) const
    {
        if (ID == entry.ID)
            return true;
        if (entry.Faction)
        {
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Enemies[i] == entry.Faction)
                    return false;
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Friends[i] == entry.Faction)
                    return true;
        }
        return (FriendMask & entry.Mask) || (Mask & entry.FriendMask);
    }
    bool IsHostileTo(FactionTemplateEntry const& entry) const
    {
        if (ID == entry.ID)
            return false;
        if (entry.Faction)
        {
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Enemies[i] == entry.Faction)
                    return true;
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Friends[i] == entry.Faction)
                    return false;
        }
        return (EnemyMask & entry.Mask) != 0;
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
};

struct GameObjectDisplayInfoEntry
{
    uint32          ID;                                     // 0
    uint32          FileDataID;                             // 1
    //uint32        Sound[10];                              // 2-11
    DBCPosition3D   GeoBoxMin;                              // 12-14
    DBCPosition3D   GeoBoxMax;                              // 15-17
    //uint32        ObjectEffectPackageID;                  // 18
    //float         OverrideLootEffectScale;                // 19
    //float         OverrideNameScale;                      // 20
};

struct GameTablesEntry
{
    //uint32 Index;                                         // 0 - not a real field, not counted for columns
    char const* Name;                                       // 1
    uint32 NumRows;                                         // 2
    uint32 NumColumns;                                      // 3
};

struct GemPropertiesEntry
{
    uint32      ID;                                         // 0
    uint32      EnchantID;                                  // 1
    //uint32    MaxCountInv;                                // 2
    //uint32    MaxCountItem;                               // 3
    uint32      Type;                                       // 4
    uint32      MinItemLevel;                               // 5
};

struct GlyphPropertiesEntry
{
    uint32      ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      Type;                                       // 2
    uint32      SpellIconID;                                // 3 GlyphIconId (SpellIcon.dbc)
    //uint32    GlyphExclusiveCategoryID;                   // 4
};

struct GlyphSlotEntry
{
    uint32      ID;                                         // 0
    uint32      Type;                                       // 1
    //uint32    Tooltip;                                    // 2
};

struct GtBarberShopCostBaseEntry
{
    //uint32 level;
    float   cost;
};

struct GtCombatRatingsEntry
{
    //uint32 level;
    float    ratio;
};

struct GtChanceToMeleeCritBaseEntry
{
    //uint32 level;
    float    base;
};

struct GtChanceToMeleeCritEntry
{
    //uint32 level;
    float    ratio;
};

struct GtChanceToSpellCritBaseEntry
{
    float    base;
};

struct GtItemSocketCostPerLevelEntry
{
    float    ratio;
};

struct GtNPCManaCostScalerEntry
{
    float    ratio;
};

struct GtChanceToSpellCritEntry
{
    float    ratio;
};

struct GtOCTClassCombatRatingScalarEntry
{
    float    ratio;
};

struct GtOCTRegenHPEntry
{
    float    ratio;
};

struct GtOCTRegenMPEntry
{
    float    ratio;
};

struct gtOCTHpPerStaminaEntry
{
    float    ratio;
};

struct GtRegenHPPerSptEntry
{
    float    ratio;
};

struct GtRegenMPPerSptEntry
{
    float    ratio;
};

struct GtSpellScalingEntry
{
    float value;
};

struct GtOCTBaseHPByClassEntry
{
    float ratio;
};

struct GtOCTBaseMPByClassEntry
{
    float ratio;
};

struct GuildPerkSpellsEntry
{
    //uint32    ID;                                         // 0
    uint32      GuildLevel;                                 // 1
    uint32      SpellID;                                    // 2
};

// ImportPriceArmor.dbc
struct ImportPriceArmorEntry
{
    uint32      ID;                                         // 1        Id/InventoryType
    float       ClothFactor;                                // 2        Price factor cloth
    float       LeatherFactor;                              // 3        Price factor leather
    float       MailFactor;                                 // 4        Price factor mail
    float       PlateFactor;                                // 5        Price factor plate
};

// ImportPriceQuality.dbc
struct ImportPriceQualityEntry
{
    uint32      ID;                                         // 1        Quality Id (+1?)
    float       Factor;                                     // 2        Price factor
};

// ImportPriceShield.dbc
struct ImportPriceShieldEntry
{
    uint32      ID;                                         // 1        Unk id (only 1 and 2)
    float       Factor;                                     // 2        Price factor
};

// ImportPriceWeapon.dbc
struct ImportPriceWeaponEntry
{
    uint32      ID;                                         // 1        Unk id (mainhand - 0, offhand - 1, weapon - 2, 2hweapon - 3, ranged/rangedright/relic - 4)
    float       Factor;                                     // 2        Price factor
};

// ItemPriceBase.dbc
struct ItemPriceBaseEntry
{
    uint32 ItemLevel;                                       // 2        Item level (1 - 1000)
    float ArmorFactor;                                      // 3        Price factor for armor
    float WeaponFactor;                                     // 4        Price factor for weapons
};

// common struct for:
// ItemDamageAmmo.dbc
// ItemDamageOneHand.dbc
// ItemDamageOneHandCaster.dbc
// ItemDamageRanged.dbc
// ItemDamageThrown.dbc
// ItemDamageTwoHand.dbc
// ItemDamageTwoHandCaster.dbc
// ItemDamageWand.dbc
struct ItemDamageEntry
{
    uint32      ID;                                         // 0 item level
    float       DPS[7];                                     // 1-7 multiplier for item quality
    uint32      ItemLevel;                                  // 8 item level
};

struct ItemArmorQualityEntry
{
    uint32      ID;                                         // 0 item level
    float       QualityMod[7];                              // 1-7 multiplier for item quality
    uint32      ItemLevel;                                  // 8 item level
};

struct ItemArmorShieldEntry
{
    uint32      ID;                                         // 0 item level
    uint32      ItemLevel;                                  // 1 item level
    float       Quality[7];                                 // 2-8 quality
};

struct ItemArmorTotalEntry
{
    uint32      ID;                                         // 0 item level
    uint32      ItemLevel;                                  // 1 item level
    float       Value[4];                                   // 2-5 multiplier for armor types (cloth...plate)
};

// ItemClass.dbc
struct ItemClassEntry
{
    uint32      ID;                                          // 0 item class id
    //uint32    Flags;                                       // 1 Weapon - 1, others - 0
    float       PriceMod;                                    // 2 used to calculate certain prices
    //char*     Name_lang;                                   // 3 class name
};

struct ItemBagFamilyEntry
{
    uint32      ID;                                         // 0
    //char*     Name_lang;                                  // 1        m_name_lang
};

struct ItemDisplayInfoEntry
{
    uint32      ID;                                         // 0
    //char*     ModelName[2];                               // 1-2
    //char*     ModelTexture[2];                            // 3-4
    //uint32    GeoSetGroup[3];                             // 5-7
    //uint32    Flags;                                      // 8
    //uint32    SpellVisualID;                              // 9
    //uint32    HelmetGeosetVis[2];                         // 10-11
    //char*     Texture[9];                                 // 12-20
    //uint32    ItemVisual;                                 // 21
    //uint32    ParticleColorID;                            // 22
};

struct ItemDisenchantLootEntry
{
    uint32      ID;                                         // 0
    uint32      ItemClass;                                  // 1
    int32       ItemSubClass;                               // 2
    uint32      ItemQuality;                                // 3
    uint32      MinItemLevel;                               // 4
    uint32      MaxItemLevel;                               // 5
    uint32      RequiredDisenchantSkill;                    // 6
};

struct ItemLimitCategoryEntry
{
    uint32      ID;                                         // 0 Id
    //char*     Name_lang;                                  // 1        m_name_lang
    uint32      Quantity;                                   // 2,       m_quantity max allowed equipped as item or in gem slot
    uint32      Flags;                                      // 3,       m_flags 0 = have, 1 = equip (enum ItemLimitCategoryMode)
};

#define MAX_ITEM_RANDOM_PROPERTIES 5

struct ItemRandomPropertiesEntry
{
    uint32      ID;                                         // 0
    //char*     Name;                                       // 1
    uint32      Enchantment[MAX_ITEM_RANDOM_PROPERTIES];  // 2-6
    char*       Name_lang;                                  // 7
};

struct ItemRandomSuffixEntry
{
    uint32      ID;                                         // 0
    char*       Name_lang;                                  // 1
    //char*     InternalName;                               // 2
    uint32      Enchantment[MAX_ITEM_RANDOM_PROPERTIES];  // 3-7
    uint32      AllocationPct[MAX_ITEM_RANDOM_PROPERTIES];// 8-12
};

#define MAX_ITEM_SET_ITEMS 17
#define MAX_ITEM_SET_SPELLS 8

struct ItemSetEntry
{
    uint32      ID;                                         // 0
    char*       Name_lang;                                  // 1
    uint32      ItemID[MAX_ITEM_SET_ITEMS];                 // 2-18
    uint32      RequiredSkill;                              // 19
    uint32      RequiredSkillRank;                          // 20
};

struct ItemSetSpellEntry
{
    uint32      ID;                                         // 0
    uint32      ItemSetID;                                  // 1
    uint32      SpellID;                                    // 2
    uint32      Threshold;                                  // 3
    uint32      ChrSpecID;                                  // 4
};

typedef std::vector<ItemSetSpellEntry const*> ItemSetSpells;
typedef std::unordered_map<uint32, ItemSetSpells> ItemSetSpellsStore;

struct LFGDungeonEntry
{
    uint32      ID;                                         // 0
    char*       Name_lang;                                  // 1
    uint32      MinLevel;                                   // 2
    uint32      MaxLevel;                                   // 3
    uint32      TargetLevel;                                // 4
    //uint32    TargetLevelMin;                             // 5
    //uint32    TargetLevelMax;                             // 6
    int32       MapID;                                      // 7
    uint32      DifficultyID;                               // 8
    uint32      Flags;                                      // 9
    uint32      Type;                                       // 10
    //uint32    Faction;                                    // 11
    //char*     TextureFilename;                            // 12
    uint32      Expansion;                                  // 13
    //uint32    OrderIndex;                                 // 14
    uint32      GroupID;                                    // 15
    //char*     Description_lang;                           // 16
    //uint32    RandomID;                                   // 17
    //uint32    CountTank;                                  // 18
    //uint32    CountHealer;                                // 19
    //uint32    CountDamage;                                // 20
    //uint32    ScenarioID;                                 // 21
    //uint32    SubType;                                    // 22
    //uint32    BonusReputationAmount;                      // 23
    //uint32    MentorCharLevel;                            // 24
    //uint32    MentorItemLevel;                            // 25
    //uint32    Unk1;                                       // 26 (300 for random dungeons, others 0)
    //uint32    Unk2;                                       // 27
    //uint32    Unk3;                                       // 28

    // Helpers
    uint32 Entry() const { return ID + (Type << 24); }
};

struct LightEntry
{
    uint32          ID;                                     // 0
    uint32          MapID;                                  // 1
    DBCPosition3D   Pos;                                    // 2-4
    //float         FalloffStart;                           // 5
    //float         FalloffEnd;                             // 6
    //uint32        LightParamsID[8];                       // 7-14
};

struct LiquidTypeEntry
{
    uint32      ID;                                         // 0
    //char*     Name;                                       // 1
    //uint32    Flags;                                      // 2
    uint32      Type;                                       // 3 m_soundBank
    //uint32    SoundID;                                    // 4
    uint32      SpellID;                                    // 5
    //float     MaxDarkenDepth;                             // 6
    //float     FogDarkenIntensity;                         // 7
    //float     AmbDarkenIntensity;                         // 8
    //float     DirDarkenIntensity;                         // 9
    //uint32    LightID;                                    // 10
    //float     ParticleScale;                              // 11
    //uint32    ParticleMovement;                           // 12
    //uint32    ParticleTexSlots;                           // 13
    //uint32    MaterialID;                                 // 14
    //char*     Texture[6];                                 // 15-20
    //uint32    Color[2];                                   // 21-23
    //float     Unk1[18];                                   // 24-41
    //uint32    Unk2[4];                                    // 42-45
    //uint32    Unk3[5];                                    // 46-50
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32      ID;                                         // 0
    uint32      Type[MAX_LOCK_CASE];                        // 1-8
    uint32      Index[MAX_LOCK_CASE];                       // 9-16
    uint32      Skill[MAX_LOCK_CASE];                       // 17-24
    //uint32    Action[MAX_LOCK_CASE];                      // 25-32
};

struct PhaseEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
};

struct MailTemplateEntry
{
    uint32      ID;                                         // 0
    //char*     Subject_lang;                               // 1
    char*       Body_lang;                                  // 2
};

struct MapEntry
{
    uint32          ID;                                     // 0
    //char*         Directory;                              // 1
    uint32          InstanceType;                           // 2
    uint32          Flags;                                  // 3
    //uint32        MapType;                                // 4
    //uint32        unk5;                                   // 5
    char*           MapName_lang;                           // 6
    uint32          AreaTableID;                            // 7
    //char*         MapDescription0_lang;                   // 8 Horde
    //char*         MapDescription1_lang;                   // 9 Alliance
    uint32          LoadingScreenID;                        // 10 LoadingScreens.dbc
    //float         MinimapIconScale;                       // 11
    int32           CorpseMapID;                            // 12 map_id of entrance map in ghost mode (continent always and in most cases = normal entrance)
    DBCPosition2D   CorpsePos;                              // 13 entrance coordinates in ghost mode  (in most cases = normal entrance)
    //uint32        TimeOfDayOverride;                      // 15
    uint32          ExpansionID;                            // 16
    uint32          RaidOffset;                             // 17
    uint32          MaxPlayers;                             // 18
    int32           ParentMapID;                            // 19 related to phasing
    //uint32        CosmeticParentMapID                     // 20
    //uint32        TimeOffset                              // 21

    // Helpers
    uint32 Expansion() const { return ExpansionID; }

    bool IsDungeon() const { return InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID; }
    bool IsNonRaidDungeon() const { return InstanceType == MAP_INSTANCE; }
    bool Instanceable() const { return InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID || InstanceType == MAP_BATTLEGROUND || InstanceType == MAP_ARENA; }
    bool IsRaid() const { return InstanceType == MAP_RAID; }
    bool IsBattleground() const { return InstanceType == MAP_BATTLEGROUND; }
    bool IsBattleArena() const { return InstanceType == MAP_ARENA; }
    bool IsBattlegroundOrArena() const { return InstanceType == MAP_BATTLEGROUND || InstanceType == MAP_ARENA; }
    bool IsWorldMap() const { return InstanceType == MAP_COMMON; }

    bool GetEntrancePos(int32 &mapid, float &x, float &y) const
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
        return ID == 0 || ID == 1 || ID == 530 || ID == 571 || ID == 870 || ID == 1116;
    }

    bool IsDynamicDifficultyMap() const { return (Flags & MAP_FLAG_DYNAMIC_DIFFICULTY) != 0; }
};

struct MapDifficultyEntry
{
    //uint32    ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      DifficultyID;                               // 2 (for arenas: arena slot)
    char*       Message_lang;                               // 3 m_message_lang (text showed when transfer to map failed)
    uint32      RaidDuration;                               // 4 m_raidDuration in secs, 0 if no fixed reset time
    uint32      MaxPlayers;                                 // 5 m_maxPlayers some heroic versions have 0 when expected same amount as in normal version
    //uint32    Unk1;                                       // 6
    //uint32    Unk2;                                       // 7
};

struct MinorTalentEntry
{
    uint32      ID;                                         // 0
    uint32      SpecID;                                     // 1
    uint32      SpellID;                                    // 2
    uint32      OrderIndex;                                 // 3
};

struct ModifierTreeEntry
{
    uint32      ID;                                         // 0
    uint32      Type;                                       // 1
    uint32      Asset[2];                                   // 2-3
    uint32      Operator;                                   // 4
    uint32      Amount;                                     // 5
    uint32      Parent;                                     // 6
};

struct MountCapabilityEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
    uint32      RequiredRidingSkill;                        // 2
    uint32      RequiredArea;                               // 3
    uint32      RequiredAura;                               // 4
    uint32      RequiredSpell;                              // 5
    uint32      SpeedModSpell;                              // 6
    int32       RequiredMap;                                // 7
};

#define MAX_MOUNT_CAPABILITIES 24

struct MountTypeEntry
{
    uint32      ID;                                         // 0
    uint32      MountCapability[MAX_MOUNT_CAPABILITIES];    // 1-24
};

struct MovieEntry
{
    uint32      ID;                                         // 0 index
    //uint32    Volume;                                     // 1
    //uint32    KeyID;                                      // 2
    //uint32    AudioFileDataID;                            // 3
    //uint32    SubtitleFileDataID;                         // 4
};

struct NameGenEntry
{
    //uint32    ID;                                         // 0
    char*       Name;                                       // 1
    uint32      Race;                                       // 2
    uint32      Sex;                                        // 3
};

struct PowerDisplayEntry
{
    uint32      ID;                                         // 0
    uint32      PowerType;                                  // 1
    //char*     GlobalStringBaseTag;                        // 2
    //uint8     Red;                                        // 3
    //uint8     Green;                                      // 4
    //uint8     Blue;                                       // 5
};

struct PvPDifficultyEntry
{
    //uint32    ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      BracketID;                                  // 2 m_rangeIndex
    uint32      MinLevel;                                   // 3
    uint32      MaxLevel;                                   // 4

    // helpers
    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(BracketID); }
};

struct QuestSortEntry
{
    uint32      ID;                                         // 0
    //char*     SortName_lang;                              // 1
};

struct QuestXPEntry
{
    uint32      ID;                                         // 0
    uint32      Exp[10];                                    // 1
};

struct QuestFactionRewEntry
{
  uint32        ID;                                         // 0
  int32         QuestRewFactionValue[10];                   // 1-10
};

struct RandomPropertiesPointsEntry
{
    uint32      ItemLevel;                                  // 0
    uint32      EpicPropertiesPoints[5];                    // 1-5
    uint32      RarePropertiesPoints[5];                    // 6-10
    uint32      UncommonPropertiesPoints[5];                // 11-15
};

struct ScalingStatDistributionEntry
{
    uint32      ID;                                         // 0
    uint32      MinLevel;                                   // 1
    uint32      MaxLevel;                                   // 2       m_maxlevel
    uint32      ItemLevelCurveID;                           // 3
};

//struct SkillLineCategoryEntry{
//    uint32    id;                                         // 0      m_ID
//    char*     name[16];                                   // 1-17   m_name_lang
//                                                          // 18 string flag
//    uint32    displayOrder;                               // 19     m_sortIndex
//};

struct SkillLineEntry
{
    uint32      ID;                                         // 0        m_ID
    int32       CategoryID;                                 // 1        m_categoryID
    char*       DisplayName_lang;                           // 2        m_displayName_lang
    //char*     Description_lang;                           // 3        m_description_lang
    uint32      SpellIconID;                                // 4        m_spellIconID
    //char*     AlternateVerb_lang;                         // 5        m_alternateVerb_lang
    uint32      CanLink;                                    // 6        m_canLink (prof. with recipes)
    //uint32    ParentSkillLineID;                          // 7
    //uint32    Flags;                                      // 8
};

struct SkillLineAbilityEntry
{
    uint32      ID;                                         // 0
    uint32      SkillLine;                                  // 1
    uint32      SpellID;                                    // 2
    uint32      RaceMask;                                   // 3
    uint32      ClassMask;                                  // 4
    uint32      MinSkillLineRank;                           // 7
    uint32      SupercedesSpell;                            // 8
    uint32      AquireMethod;                               // 9
    uint32      TrivialSkillLineRankHigh;                   // 10
    uint32      TrivialSkillLineRankLow;                    // 11
    uint32      NumSkillUps;                                // 12
    uint32      UniqueBit;                                  // 13
    uint32      TradeSkillCategoryID;                       // 14
};

struct SkillRaceClassInfoEntry
{
    //uint32    ID;                                         // 0
    uint32      SkillID;                                    // 1
    uint32      RaceMask;                                   // 2
    uint32      ClassMask;                                  // 3
    uint32      Flags;                                      // 4
    //uint32    Availability;                               // 5
    //uint32    MinLevel;                                   // 6
    uint32      SkillTierID;                                // 7
};

#define MAX_SKILL_STEP 16

struct SkillTiersEntry
{
    uint32      ID;                                         // 0
    uint32      Value[MAX_SKILL_STEP];                      // 1-16
};

struct SoundEntriesEntry
{
    uint32      ID;                                         // 0
    //uint32    SoundType;                                  // 1
    //char*     Name;                                       // 2
    //uint32    FileDataID[20];                             // 3-22
    //uint32    Freq[20];                                   // 23-42
    //float     VolumeFloat;                                // 43
    //uint32    Flags;                                      // 44
    //float     MinDistance;                                // 45
    //float     DistanceCutoff;                             // 46
    //uint32    EAXDef;                                     // 47
    //uint32    SoundEntriesAdvancedID;                     // 48
    //float     VolumeVariationPlus;                        // 49
    //float     VolumeVariationMinus;                       // 50
    //float     PitchVariationPlus;                         // 51
    //float     PitchVariationMinus;                        // 52
    //float     PitchAdjust;                                // 53
    //uint32    DialogType;                                 // 54
    //uint32    BusOverwriteID;                             // 55
};

// SpecializationSpells.dbc
struct SpecializationSpellsEntry
{
    uint32      ID;                                         // 0
    uint32      SpecID;                                     // 1
    uint32      SpellID;                                    // 2
    uint32      OverridesSpellID;                           // 3
    //char*     Description_lang;                           // 4
};

// SpellEffect.dbc
struct SpellEffectEntry
{
    uint32      ID;                                         // 0
    uint32      DifficultyID;                               // 1
    uint32      Effect;                                     // 2
    float       EffectAmplitude;                            // 3
    uint32      EffectAura;                                 // 4
    uint32      EffectAuraPeriod;                           // 5
    uint32      EffectBasePoints;                           // 6
    float       EffectBonusCoefficient;                     // 7
    float       EffectChainAmplitude;                       // 8
    uint32      EffectChainTargets;                         // 9
    uint32      EffectDieSides;                             // 10
    uint32      EffectItemType;                             // 11
    uint32      EffectMechanic;                             // 12
    int32       EffectMiscValue;                            // 13
    int32       EffectMiscValueB;                           // 14
    float       EffectPointsPerResource;                    // 15
    uint32      EffectRadiusIndex;                          // 16
    uint32      EffectRadiusMaxIndex;                       // 17
    float       EffectRealPointsPerLevel;                   // 18
    flag128     EffectSpellClassMask;                       // 19-22
    uint32      EffectTriggerSpell;                         // 23
    float       EffectPosFacing;                            // 24
    uint32      ImplicitTarget[2];                          // 25-26
    uint32      SpellID;                                    // 27
    uint32      EffectIndex;                                // 28
    uint32      EffectAttributes;                           // 29
    float       BonusCoefficientFromAP;                     // 30
};

#define MAX_SPELL_EFFECTS 32
#define MAX_EFFECT_MASK 0xFFFFFFFF

// SpellEffectScaling.dbc
struct SpellEffectScalingEntry
{
    uint32 ID;                      // 0
    float Coefficient;              // 1
    float Variance;                 // 2
    float ResourceCoefficient;      // 3
    uint32 SpellEffectID;           // 4
};

// SpellAuraOptions.dbc
struct SpellAuraOptionsEntry
{
    uint32      ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    uint32      CumulativeAura;                             // 3
    uint32      ProcChance;                                 // 4
    uint32      ProcCharges;                                // 5
    uint32      ProcTypeMask;                               // 6
    uint32      ProcCategoryRecovery;                       // 7
    uint32      SpellProcsPerMinuteID;                      // 8
};

// Spell.dbc
struct SpellEntry
{
    uint32      ID;                                         // 0
    char*       Name_lang;                                  // 1
    //char*     NameSubtext_lang;                           // 2
    //char*     Description_lang;                           // 3
    //char*     AuraDescription_lang;                       // 4
    uint32      RuneCostID;                                 // 5
    uint32      SpellMissileID;                             // 6
    uint32      DescriptionVariablesID;                     // 7
    uint32      ScalingID;                                  // 8
    uint32      AuraOptionsID;                              // 9
    uint32      AuraRestrictionsID;                         // 10
    uint32      CastingRequirementsID;                      // 11
    uint32      CategoriesID;                               // 12
    uint32      ClassOptionsID;                             // 13
    uint32      CooldownsID;                                // 14
    uint32      EquippedItemsID;                            // 15
    uint32      InterruptsID;                               // 16
    uint32      LevelsID;                                   // 17
    uint32      ReagentsID;                                 // 18
    uint32      ShapeshiftID;                               // 19
    uint32      TargetRestrictionsID;                       // 20
    uint32      TotemsID;                                   // 21
    uint32      RequiredProjectID;                          // 22
    uint32      MiscID;                                     // 23
};

// SpellCategories.dbc
struct SpellCategoriesEntry
{
    //uint32    ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    uint32      Category;                                   // 3
    uint32      DefenseType;                                // 4
    uint32      DispelType;                                 // 5
    uint32      Mechanic;                                   // 6
    uint32      PreventionType;                             // 7
    uint32      StartRecoveryCategory;                      // 8
    //uint32    ChargeCategory;                             // 9
};

typedef std::set<uint32> SpellCategorySet;
typedef std::map<uint32, SpellCategorySet > SpellCategoryStore;
typedef std::set<uint32> PetFamilySpellsSet;
typedef std::map<uint32, PetFamilySpellsSet > PetFamilySpellsStore;
typedef std::unordered_map<uint32, std::list<SkillLineAbilityEntry const*> > SpellsPerClassStore;
typedef std::unordered_map<uint32, uint32> ClassBySkillIdStore;
typedef std::unordered_map<uint32, uint32> SpellEffectScallingByEffectId;

struct SpellCastTimesEntry
{
    uint32      ID;                                         // 0
    int32       CastTime;                                   // 1
    //float     CastTimePerLevel;                           // 2 unsure / per skill?
    //int32     MinCastTime;                                // 3 unsure
};

struct SpellCategoryEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
    //uint8     UsesPerWeek;                                // 2
    //uint8     Padding[3];                                 // 2
    //char*     Name_lang;                                  // 3
    //uint32    MaxCharges;                                 // 4
    //uint32    ChargeRecoveryTime;                         // 5
};

struct SpellFocusObjectEntry
{
    uint32      ID;                                         // 0
    //char*     Name_lang;                                  // 1
};

struct SpellRadiusEntry
{
    uint32      ID;                                         // 0
    //float     Radius;                                     // 1
    float       RadiusMin;                                  // 2
    float       RadiusPerLevel;                             // 3
    float       RadiusMax;                                  // 4
};

struct SpellRangeEntry
{
    uint32      ID;                                         // 0
    float       MinRangeHostile;                            // 1
    float       MinRangeFriend;                             // 2
    float       MaxRangeHostile;                            // 3
    float       MaxRangeFriend;                             // 4 friend means unattackable unit here
    uint32      Flags;                                      // 5
    //char*     DisplayName_lang;                           // 6
    //char*     DisplayNameShort_lang;                      // 7
};

// SpellEquippedItems.dbc
struct SpellEquippedItemsEntry
{
    //uint32    ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    int32       EquippedItemClass;                          // 3       m_equippedItemClass (value)
    int32       EquippedItemInventoryTypeMask;              // 4       m_equippedItemInvTypes (mask)
    int32       EquippedItemSubClassMask;                   // 5       m_equippedItemSubclass (mask)
};

// SpellCooldowns.dbc
struct SpellCooldownsEntry
{
    //uint32    ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    uint32      CategoryRecoveryTime;                       // 3
    uint32      RecoveryTime;                               // 4
    uint32      StartRecoveryTime;                          // 5
};

// SpellInterrupts.dbc
struct SpellInterruptsEntry
{
    //uint32    ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    uint32      AuraInterruptFlags[2];                      // 3-4
    uint32      ChannelInterruptFlags[2];                   // 5-6
    uint32      InterruptFlags;                             // 7
};

// SpellLevels.dbc
struct SpellLevelsEntry
{
    //uint32    ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    uint32      BaseLevel;                                  // 3
    uint32      MaxLevel;                                   // 4
    uint32      SpellLevel;                                 // 5
};

#define MAX_SHAPESHIFT_SPELLS 8

struct SpellShapeshiftFormEntry
{
    uint32      ID;                                         // 0
    //uint32    BonusActionBar;                             // 1
    //char*     Name_lang;                                  // 2
    uint32      Flags;                                      // 3
    int32       CreatureType;                               // 4 <=0 humanoid, other normal creature types
    //uint32    AttackIconID;                               // 5 unused, related to next field
    uint32      CombatRoundTime;                            // 6
    uint32      CreatureDisplayID[4];                       // 7-10 (0 - Alliance, 1 - Horde)
    uint32      PresetSpellID[MAX_SHAPESHIFT_SPELLS];       // 11-18 spells which appear in the bar after shapeshifting
    //uint32    MountTypeID;                                // 19
    //uint32    ExitSoundEntriesID;                         // 20
};

// SpellShapeshift.dbc
struct SpellShapeshiftEntry
{
    uint32      ID;                                         // 0
    uint32      ShapeshiftExclude[2];                       // 1-2
    uint32      ShapeshiftMask[2];                          // 3-4
    //uint32    StanceBarOrder;                             // 5
};

// SpellTargetRestrictions.dbc
struct SpellTargetRestrictionsEntry
{
    uint32      ID;                                         // 0
    uint32      SpellID;                                    // 1
    uint32      DifficultyID;                               // 2
    float       ConeAngle;                                  // 3
    float       Width;                                      // 4
    uint32      MaxAffectedTargets;                         // 5
    uint32      MaxTargetLevel;                             // 6
    uint32      TargetCreatureType;                         // 7
    uint32      Targets;                                    // 8
};

// SpellScaling.dbc
struct SpellScalingEntry
{
    uint32      ID;                                         // 0
    int32       CastTimeMin;                                // 1
    int32       CastTimeMax;                                // 2
    uint32      CastTimeMaxLevel;                           // 3
    int32       ScalingClass;                               // 4
    float       NerfFactor;                                 // 5
    uint32      NerfMaxLevel;                               // 6
    uint32      MaxScalingLevel;                            // 7
    uint32      ScalesFromItemLevel;                        // 8
};

struct SpellDurationEntry
{
    uint32      ID;
    int32       Duration[3];
};

#define MAX_ITEM_ENCHANTMENT_EFFECTS 3

struct SpellItemEnchantmentEntry
{
    uint32      ID;                                             // 0
    uint32      Charges;                                        // 1
    uint32      Effect[MAX_ITEM_ENCHANTMENT_EFFECTS];           // 2-4
    uint32      EffectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS];  // 5-7
    uint32      EffectSpellID[MAX_ITEM_ENCHANTMENT_EFFECTS];    // 8-10
    //char*     Name_lang                                       // 11
    uint32      ItemVisual;                                     // 12
    uint32      Flags;                                          // 13
    uint32      SRCItemID;                                      // 14
    uint32      ConditionID;                                    // 15
    uint32      RequiredSkillID;                                // 16
    uint32      RequiredSkillRank;                              // 17
    uint32      MinLevel;                                       // 18
    uint32      MaxLevel;                                       // 19
    uint32      ItemLevel;                                      // 20
    int32       ScalingClass;                                   // 21
    int32       ScalingClassRestricted;                         // 22
    float       EffectScalingPoints[MAX_ITEM_ENCHANTMENT_EFFECTS];//23-25
};

struct SpellItemEnchantmentConditionEntry
{
    uint32      ID;                                             // 0
    uint8       LTOperandType[5];                               // 1-2
    uint32      LTOperand[5];                                   // 2-6
    uint8       Operator[5];                                    // 7-8
    uint8       RTOperandType[5];                               // 8-9
    uint32      RTOperand[5];                                   // 10-14
    uint8       Logic[5];                                       // 15-16
};

struct StableSlotPricesEntry
{
    uint32 Slot;
    uint32 Price;
};

struct SummonPropertiesEntry
{
    uint32      ID;                                             // 0
    uint32      Category;                                       // 1, 0 - can't be controlled?, 1 - something guardian?, 2 - pet?, 3 - something controllable?, 4 - taxi/mount?
    uint32      Faction;                                        // 2, 14 rows > 0
    uint32      Type;                                           // 3, see enum
    int32       Slot;                                           // 4, 0-6
    uint32      Flags;                                          // 5
};

#define MAX_TALENT_TIERS 7

struct TalentEntry
{
    uint32      ID;                                             // 0
    uint32      SpecID;                                         // 1 0 - any specialization
    uint32      TierID;                                         // 2 0-6
    uint32      ColumnIndex;                                    // 3 0-2
    uint32      SpellID;                                        // 4
    uint32      Flags;                                          // 5 All 0
    uint32      CategoryMask[2];                                // 6 All 0
    uint32      ClassID;                                        // 7
    uint32      OverridesSpellID;                               // 8 spellid that is replaced by talent
    //char*     Description_lang
};

struct TotemCategoryEntry
{
    uint32    ID;                                           // 0
    //char*   Name_lang;                                    // 1        m_name_lang
    uint32    CategoryType;                                 // 2        m_totemCategoryType (one for specialization)
    uint32    CategoryMask;                                 // 3        m_totemCategoryMask (compatibility mask for same type: different for totems, compatible from high to low for rods)
};

struct UnitPowerBarEntry
{
    uint32      ID;                                         // 0
    uint32      MinPower;                                   // 1
    uint32      MaxPower;                                   // 2
    //uint32    StartPower;                                 // 3
    //uint32    CenterPower;                                // 4
    //float     RegenerationPeace;                          // 5
    //float     RegenerationCombat;                         // 6
    //uint32    BarType;                                    // 7
    //uint32    FileDataID[6];                              // 8-13
    //uint32    Color[6];                                   // 14-19
    //uint32    Flags;                                      // 20
    //char*     Name_lang;                                  // 21
    //char*     Cost_lang;                                  // 22
    //char*     OutOfError_lang;                            // 23
    //char*     ToolTip_lang;                               // 24
    //float     StartInset;                                 // 25
    //float     EndInset;                                   // 26
};

struct TransportAnimationEntry
{
    //uint32        ID;                                     // 0
    uint32          TransportID;                            // 1
    uint32          TimeIndex;                              // 2
    DBCPosition3D   Pos;                                    // 3-5
    //uint32        SequenceID;                             // 6
};

struct TransportRotationEntry
{
    //uint32    ID;                                         // 0
    uint32      TransportID;                                // 1
    uint32      TimeIndex;                                  // 2
    float       X;                                          // 3
    float       Y;                                          // 4
    float       Z;                                          // 5
    float       W;                                          // 6
};

#define MAX_VEHICLE_SEATS 8

struct VehicleEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
    uint32      FlagsB;                                     // 2
    float       TurnSpeed;                                  // 3
    float       PitchSpeed;                                 // 4
    float       PitchMin;                                   // 5
    float       PitchMax;                                   // 6
    uint32      SeatID[MAX_VEHICLE_SEATS];                  // 7-14
    float       MouseLookOffsetPitch;                       // 15
    float       CameraFadeDistScalarMin;                    // 16
    float       CameraFadeDistScalarMax;                    // 17
    float       CameraPitchOffset;                          // 18
    float       FacingLimitRight;                           // 19
    float       FacingLimitLeft;                            // 20
    float       MsslTrgtTurnLingering;                      // 21
    float       MsslTrgtPitchLingering;                     // 22
    float       MsslTrgtMouseLingering;                     // 23
    float       MsslTrgtEndOpacity;                         // 24
    float       MsslTrgtArcSpeed;                           // 25
    float       MsslTrgtArcRepeat;                          // 26
    float       MsslTrgtArcWidth;                           // 27
    float       MsslTrgtImpactRadius[2];                    // 28-29
    //char*     MsslTrgtArcTexture;                         // 30
    //char*     MsslTrgtImpactTexture;                      // 31
    //char*     MsslTrgtImpactModel;                        // 32-33
    float       CameraYawOffset;                            // 34
    uint32      UILocomotionType;                           // 35
    float       MsslTrgtImpactTexRadius;                    // 36
    uint32      VehicleUIIndicatorID;                       // 37
    uint32      PowerDisplayID[3];                          // 38-40
};

struct VehicleSeatEntry
{
    uint32          ID;                                     // 0
    uint32          Flags;                                  // 1
    int32           AttachmentID;                           // 2
    DBCPosition3D   AttachmentOffset;                       // 3-5
    float           EnterPreDelay;                          // 6
    float           EnterSpeed;                             // 7
    float           EnterGravity;                           // 8
    float           EnterMinDuration;                       // 9
    float           EnterMaxDuration;                       // 10
    float           EnterMinArcHeight;                      // 11
    float           EnterMaxArcHeight;                      // 12
    int32           EnterAnimStart;                         // 13
    int32           EnterAnimLoop;                          // 14
    int32           RideAnimStart;                          // 15
    int32           RideAnimLoop;                           // 16
    int32           RideUpperAnimStart;                     // 17
    int32           RideUpperAnimLoop;                      // 18
    float           ExitPreDelay;                           // 19
    float           ExitSpeed;                              // 20
    float           ExitGravity;                            // 21
    float           ExitMinDuration;                        // 22
    float           ExitMaxDuration;                        // 23
    float           ExitMinArcHeight;                       // 24
    float           ExitMaxArcHeight;                       // 25
    int32           ExitAnimStart;                          // 26
    int32           ExitAnimLoop;                           // 27
    int32           ExitAnimEnd;                            // 28
    float           PassengerYaw;                           // 29
    float           PassengerPitch;                         // 30
    float           PassengerRoll;                          // 31
    int32           PassengerAttachmentID;                  // 32
    int32           VehicleEnterAnim;                       // 33
    int32           VehicleExitAnim;                        // 34
    int32           VehicleRideAnimLoop;                    // 35
    int32           VehicleEnterAnimBone;                   // 36
    int32           VehicleExitAnimBone;                    // 37
    int32           VehicleRideAnimLoopBone;                // 38
    float           VehicleEnterAnimDelay;                  // 39
    float           VehicleExitAnimDelay;                   // 40
    uint32          VehicleAbilityDisplay;                  // 41
    uint32          EnterUISoundID;                         // 42
    uint32          ExitUISoundID;                          // 43
    uint32          FlagsB;                                 // 44
    float           CameraEnteringDelay;                    // 45
    float           CameraEnteringDuration;                 // 46
    float           CameraExitingDelay;                     // 47
    float           CameraExitingDuration;                  // 48
    DBCPosition3D   CameraOffset;                           // 49-51
    float           CameraPosChaseRate;                     // 52
    float           CameraFacingChaseRate;                  // 53
    float           CameraEnteringZoom;                     // 54
    float           CameraSeatZoomMin;                      // 55
    float           CameraSeatZoomMax;                      // 56
    uint32          EnterAnimKitID;                         // 57
    uint32          RideAnimKitID;                          // 58
    uint32          ExitAnimKitID;                          // 59
    uint32          VehicleEnterAnimKitID;                  // 60
    uint32          VehicleRideAnimKitID;                   // 61
    uint32          VehicleExitAnimKitID;                   // 62
    uint32          CameraModeID;                           // 63
    uint32          FlagsC;                                 // 64
    uint32          UISkinFileDataID;                       // 65

    bool CanEnterOrExit() const { return (Flags & VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT) != 0; }
    bool CanSwitchFromSeat() const { return (Flags & VEHICLE_SEAT_FLAG_CAN_SWITCH) != 0; }
    bool IsUsableByOverride() const { return (Flags & (VEHICLE_SEAT_FLAG_UNCONTROLLED | VEHICLE_SEAT_FLAG_UNK18)
                                    || (FlagsB & (VEHICLE_SEAT_FLAG_B_USABLE_FORCED | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2 |
                                        VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3 | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4))); }
    bool IsEjectable() const { return (FlagsB & VEHICLE_SEAT_FLAG_B_EJECTABLE) != 0; }
};

struct WMOAreaTableEntry
{
    uint32      ID;                                         // 0 index
    int32       WMOID;                                      // 1 used in root WMO
    int32       NameSet;                                    // 2 used in adt file
    int32       WMOGroupID;                                 // 3 used in group WMO
    //uint32    SoundProviderPref;                          // 4
    //uint32    SoundProviderPrefUnderwater;                // 5
    //uint32    AmbienceID;                                 // 6
    //uint32    ZoneMusic;                                  // 7
    //uint32    IntroSound;                                 // 8
    uint32      Flags;                                      // 9 used for indoor/outdoor determination
    uint32      AreaTableID;                                // 10 link to AreaTableEntry.ID
    //char*     AreaName_lang;                              // 11       m_AreaName_lang
    //uint32    UWIntroSound;                               // 12
    //uint32    UWZoneMusic;                                // 13
    //uint32    UWAmbience;                                 // 14
};

struct WorldMapAreaEntry
{
    //uint32    ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      AreaID;                                     // 2 index (continent 0 areas ignored)
    //char*     AreaName                                    // 3
    float       LocLeft;                                    // 4
    float       LocRight;                                   // 5
    float       LocTop;                                     // 6
    float       LocBottom;                                  // 7
    int32       DisplayMapID;                               // 8 -1 (map_id have correct map) other: virtual map where zone show (map_id - where zone in fact internally)
    //int32     DefaultDungeonFloor;                        // 9 pointer to DungeonMap.dbc (owerride loc coordinates)
    //uint32    ParentWorldMapID;                           // 10
    //uint32    Flags;                                      // 11
    //uint32    LevelRangeMin;                              // 12 Minimum recommended level displayed on world map
    //uint32    LevelRangeMax;                              // 13 Maximum recommended level displayed on world map
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32      ID;                                         // 0
    //uint32    MapAreaID;                                  // 1 idx in WorldMapArea.dbc
    uint32      AreaID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];     // 2-5
    //char*     TextureName;                                // 6
    //uint32    TextureWidth;                               // 7
    //uint32    TextureHeight;                              // 8
    //uint32    OffsetX;                                    // 9
    //uint32    OffsetY;                                    // 10
    //uint32    HitRectTop;                                 // 11
    //uint32    HitRectLeft;                                // 12
    //uint32    HitRectBottom;                              // 13
    //uint32    HitRectRight;                               // 14
    //uint32    PlayerConditionID;                          // 15
};

struct WorldSafeLocsEntry
{
    uint32          ID;                                     // 0
    uint32          MapID;                                  // 1
    DBCPosition3D   Loc;                                    // 2-4
    float           Facing;                                 // 5 values are in degrees
    //char*         AreaName_lang;                          // 6
};

/*
struct WorldStateSounds
{
    uint32    ID;                                           // 0        Worldstate
    uint32    unk;                                          // 1
    uint32    areaTable;                                    // 2
    uint32    WMOAreaTable;                                 // 3
    uint32    zoneIntroMusicTable;                          // 4
    uint32    zoneIntroMusic;                               // 5
    uint32    zoneMusic;                                    // 6
    uint32    soundAmbience;                                // 7
    uint32    soundProviderPreferences;                     // 8
};
*/

/*
struct WorldStateUI
{
    uint32    ID;                                           // 0
    uint32    map_id;                                       // 1        Can be -1 to show up everywhere.
    uint32    zone;                                         // 2        Can be zero for "everywhere".
    uint32    phaseMask;                                    // 3        Phase this WorldState is avaliable in
    uint32    icon;                                         // 4        The icon that is used in the interface.
    char*     textureFilename;                              // 5
    char*     text;                                         // 6-21     The worldstate text
    char*     description;                                  // 22-38    Text shown when hovering mouse on icon
    uint32    worldstateID;                                 // 39       This is the actual ID used
    uint32    type;                                         // 40       0 = unknown, 1 = unknown, 2 = not shown in ui, 3 = wintergrasp
    uint32    unk1;                                         // 41
    uint32    unk2;                                         // 43
    uint32    unk3;                                         // 44-58
    uint32    unk4;                                         // 59-61    Used for some progress bars.
    uint32    unk7;                                         // 62       Unused in 3.3.5a
};
*/

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

struct VectorArray
{
    std::vector<std::string> Contents[2];
};

typedef std::map<uint32, VectorArray> NameGenContainer;

// Structures not used for casting to loaded DBC data and not required then packing
struct MapDifficulty
{
    MapDifficulty() : resetTime(0), maxPlayers(0), hasErrorMessage(false) { }
    MapDifficulty(uint32 _resetTime, uint32 _maxPlayers, bool _hasErrorMessage) : resetTime(_resetTime), maxPlayers(_maxPlayers), hasErrorMessage(_hasErrorMessage) { }

    uint32 resetTime;
    uint32 maxPlayers;
    bool hasErrorMessage;
};

typedef std::map<uint32, uint32> TalentSpellPosMap;
#endif
