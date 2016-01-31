/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "Util.h"

// Structures using to access raw DBC data and required packing to portability
#pragma pack(push, 1)

struct AreaTableEntry
{
    uint32      ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      ParentAreaID;                               // 2 if 0 then it's zone, else it's zone id of this area
    int32       AreaBit;                                    // 3
    uint32      Flags[2];                                   // 4-5,
    //uint32    SoundProviderPref;                          // 6,
    //uint32    SoundProviderPrefUnderwater;                // 7,
    //uint32    AmbienceID;                                 // 8,
    //uint32    ZoneMusic;                                  // 9,
    //char*     ZoneName;                                   // 10 - Internal name
    //uint32    IntroSound;                                 // 11
    uint32      ExplorationLevel;                           // 12
    char*       AreaName_lang;                              // 13 - In-game name
    uint32      FactionGroupMask;                           // 14
    uint32      LiquidTypeID[4];                            // 15-18
    //float     AmbientMultiplier;                          // 19
    //uint32    MountFlags;                                 // 20
    //uint32    UWIntroMusic;                               // 21
    //uint32    UWZoneMusic;                                // 22
    //uint32    UWAmbience;                                 // 23
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

struct BannedAddOnsEntry
{
    uint32      ID;                                         // 0
    //uint32    NameMD5[4];                                 // 1
    //uint32    VersionMD5[4];                              // 2
    //uint32    LastModified;                               // 3
    //uint32    Flags;                                      // 4
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
    //uint32    PlayerConditionID;                          // 30
};

enum CharSectionFlags
{
    SECTION_FLAG_PLAYER = 0x01,
    SECTION_FLAG_DEATH_KNIGHT = 0x04,
    SECTION_FLAG_DEMON_HUNTER = 0x40
};

enum CharSectionType
{
    SECTION_TYPE_SKIN = 0,
    SECTION_TYPE_FACE = 1,
    SECTION_TYPE_FACIAL_HAIR = 2,
    SECTION_TYPE_HAIR = 3,
    SECTION_TYPE_UNDERWEAR = 4,
    SECTION_TYPE_CUSTOM_DISPLAY_1 = 10,
    SECTION_TYPE_CUSTOM_DISPLAY_2 = 12,
    SECTION_TYPE_CUSTOM_DISPLAY_3 = 14
};

struct CharSectionsEntry
{
     //uint32 Id;
    uint32 Race;
    uint32 Gender;
    uint32 GenType;
    //uint32 TextureFileDataID[3];
    uint32 Flags;
    uint32 Type;
    uint32 Color;
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
    uint32      DefaultSpec;                                // 13
    //uint32    CreateScreenFileDataID;                     // 14
    //uint32    SelectScreenFileDataID;                     // 15
    //uint32    LowResScreenFileDataID;                     // 16
    //uint32    IconFileDataID;                             // 17
    //uint32    Unk1;                                       // 18
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
    uint32      FileDataID;                                 // 2
    //uint32    SizeClass;                                  // 3
    //float     ModelScale;                                 // 4
    //uint32    BloodID;                                    // 5
    //uint32    FootprintTextureID;                         // 6
    //float     FootprintTextureLength;                     // 7
    //float     FootprintTextureWidth;                      // 8
    //float     FootprintParticleScale;                     // 9
    //uint32    FoleyMaterialID;                            // 10
    //uint32    Unk700_1;                                   // 11
    //uint32    Unk700_2;                                   // 12
    //uint32    FootstepShakeSize;                          // 13
    //uint32    DeathThudShakeSize;                         // 14
    //uint32    SoundID;                                    // 15
    //float     CollisionWidth;                             // 16
    float       CollisionHeight;                            // 17
    float       MountHeight;                                // 18
    //float     GeoBoxMin[3];                               // 19-21
    //float     GeoBoxMax[3];                               // 22-24
    //float     WorldEffectScale;                           // 25
    //float     AttachedEffectScale;                        // 26
    //float     MissileCollisionRadius;                     // 27
    //float     MissileCollisionPush;                       // 28
    //float     MissileCollisionRaise;                      // 29
    //float     OverrideLootEffectScale;                    // 30
    //float     OverrideNameScale;                          // 31
    //float     OverrideSelectionRadius;                    // 32
    //float     TamedPetBaseScale;                          // 33
    //uint32    CreatureGeosetDataID;                       // 34
    //float     HoverHeight;                                // 35
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

struct DifficultyEntry
{
    uint32      ID;                                         // 0
    uint32      FallbackDifficultyID;                       // 1
    uint32      InstanceType;                               // 2
    uint32      MinPlayers;                                 // 3
    uint32      MaxPlayers;                                 // 4
    //int32     OldEnumValue;                               // 5
    uint32      Flags;                                      // 6
    uint32      ToggleDifficultyID;                         // 7
    //uint32    GroupSizeHealthCurveID;                     // 8
    //uint32    GroupSizeDmgCurveID;                        // 9
    //uint32    GroupSizeSpellPointsCurveID;                // 10
    //char const* NameLang;                                 // 11
    uint32      ItemBonusTreeModID;                         // 12
    //uint32    OrderIndex;                                 // 13
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

struct GtArmorMitigationByLvlEntry
{
    //uint32 level;
    float   KFactor;
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

struct GtNpcDamageByClassEntry
{
    float    Damage;
};

struct GtNpcTotalHpEntry
{
    float    HP;
};

struct GtChanceToSpellCritEntry
{
    float    ratio;
};

struct GtOCTLevelExperienceEntry
{
    float    Data;
};

struct GtOCTRegenHPEntry
{
    float    ratio;
};

struct GtOCTRegenMPEntry
{
    float    ratio;
};

struct GtOCTHpPerStaminaEntry
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
    //uint32    MinCountTank;                               // 21
    //uint32    MinCountHealer;                             // 22
    //uint32    MinCountDamage;                             // 23
    //uint32    ScenarioID;                                 // 24
    //uint32    SubType;                                    // 25
    //uint32    LastBossJournalEncounterID;                 // 26
    //uint32    BonusReputationAmount;                      // 27
    //uint32    MentorCharLevel;                            // 28
    //uint32    MentorItemLevel;                            // 29

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
    //uint32    DepthTexCount[6]                            // 21-26
    //uint32    Color[2];                                   // 27-28
    //float     Float[18];                                  // 29-46
    //uint32    Int[4];                                     // 47-50
};

struct PhaseEntry
{
    uint32      ID;                                         // 0
    uint32      Flags;                                      // 1
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
    int32           CosmeticParentMapID;                    // 20
    //uint32        TimeOffset                              // 21

    // Helpers
    uint32 Expansion() const { return ExpansionID; }

    bool IsDungeon() const { return (InstanceType == MAP_INSTANCE || InstanceType == MAP_RAID) && !IsGarrison(); }
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

    bool IsDynamicDifficultyMap() const { return (Flags & MAP_FLAG_CAN_TOGGLE_DIFFICULTY) != 0; }
    bool IsGarrison() const { return (Flags & MAP_FLAG_GARRISON) != 0; }
};

struct MapDifficultyEntry
{
    //uint32    ID;                                         // 0
    uint32      MapID;                                      // 1
    uint32      DifficultyID;                               // 2 (for arenas: arena slot)
    char*       Message_lang;                               // 3 m_message_lang (text showed when transfer to map failed)
    uint32      RaidDuration;                               // 4 m_raidDuration in secs, 0 if no fixed reset time
    uint32      MaxPlayers;                                 // 5 m_maxPlayers some heroic versions have 0 when expected same amount as in normal version
    uint32      LockID;                                     // 6
    uint32      ItemBonusTreeModID;                         // 7

    bool HasMessage() const { return Message_lang[0] != '\0'; }
};

struct MinorTalentEntry
{
    uint32      ID;                                         // 0
    uint32      SpecID;                                     // 1
    uint32      SpellID;                                    // 2
    uint32      OrderIndex;                                 // 3
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
    uint32      ConditionID;                                    // 14
    uint32      RequiredSkillID;                                // 15
    uint32      RequiredSkillRank;                              // 16
    uint32      MinLevel;                                       // 17
    uint32      MaxLevel;                                       // 18
    uint32      ItemLevel;                                      // 19
    int32       ScalingClass;                                   // 20
    int32       ScalingClassRestricted;                         // 21
    float       EffectScalingPoints[MAX_ITEM_ENCHANTMENT_EFFECTS];//22-24
    //uint32    PlayerConditionID;                              // 25
    //uint32    TransmogCost;                                   // 26
    //uint32    TextureFileDataID;                              // 27
};

struct StableSlotPricesEntry
{
    uint32 Slot;
    uint32 Price;
};

#define MAX_TALENT_TIERS 7
#define MAX_TALENT_COLUMNS 3

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

#pragma pack(pop)

typedef std::map<uint32, uint32> TalentSpellPosMap;
#endif
