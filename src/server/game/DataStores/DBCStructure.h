/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

struct AchievementEntry
{
    uint32 ID;
    int32 Faction;                                                  // -1=all, 0=horde, 1=alliance
    int32 MapID;                                                    // -1 = none
    //uint32 Supercedes;                                            // its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    char* Title[16];
    //uint32 Title_flags;
    //char* Description[16];
    //uint32 Description_flags;
    uint32 Category;
    uint32 Points;
    //uint32 UIOrder;
    uint32 Flags;
    //uint32  IconID;
    //char* Reward[16];
    //uint32 Reward_flags;
    uint32 MinimumCriteria;                                         // need this count of completed criterias (own or referenced achievement criterias)
    uint32 SharesCriteria;                                          // referenced achievement (counting of all completed criterias)
};

struct AchievementCriteriaEntry
{
    uint32 ID;
    uint32 ReferredAchievement;
    uint32 Type;
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
        // ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT     = 51
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
    } Asset;

    uint32 Amount;

    struct
    {
        uint32  Type;
        uint32  Asset;
    } AdditionalRequirements[MAX_CRITERIA_REQUIREMENTS];

    //char*  Description[16];
    //uint32 Description_flags;
    uint32 Flags;
    uint32 StartEvent;
    uint32 StartAsset;
    uint32 StartTimer;
    //uint32 OrderIndex;
};

struct AreaTableEntry
{
    uint32  ID;                                             // 0
    uint32  mapid;                                          // 1
    uint32  zone;                                           // 2 if 0 then it's zone, else it's zone id of this area
    uint32  exploreFlag;                                    // 3
    uint32  flags;                                          // 4, unknown value but 312 for all cities
                                                            // 5-9 unused
    int32   area_level;                                     // 10
    char*   area_name[16];                                  // 11-26
                                                            // 27, string flags, unused
    uint32  team;                                           // 28
    uint32  LiquidTypeOverride[4];                          // 29-32 liquid override by type

    // helpers
    bool IsSanctuary() const
    {
        if (mapid == 609)
            return true;
        return (flags & AREA_FLAG_SANCTUARY) != 0;
    }

    bool IsFlyable() const
    {
        if (flags & AREA_FLAG_OUTLAND)
        {
            if (!(flags & AREA_FLAG_NO_FLY_ZONE))
                return true;
        }

        return false;
    }
};

#define MAX_GROUP_AREA_IDS 6

struct AreaGroupEntry
{
    uint32  AreaGroupId;                                    // 0
    uint32  AreaId[MAX_GROUP_AREA_IDS];                     // 1-6
    uint32  nextGroup;                                      // 7 index of next group
};

struct AreaPOIEntry
{
    uint32 id;              //0
    uint32 icon[11];        //1-11
    float x;                //12
    float y;                //13
    float z;                //14
    uint32 mapId;           //15
    //uint32 val1;          //16
    uint32 zoneId;          //17
    //char* name[16];       //18-33
    //uint32 name_flag;     //34
    //char* name2[16];      //35-50
    //uint32 name_flag2;    //51
    uint32 worldState;      //52
    //uint32 val2;          //53
};

struct AreaTriggerEntry
{
    uint32  id;                                             // 0        m_ID
    uint32  mapid;                                          // 1        m_ContinentID
    float   x;                                              // 2        m_x
    float   y;                                              // 3        m_y
    float   z;                                              // 4        m_z
    float   radius;                                         // 5        m_radius
    float   box_x;                                          // 6        m_box_length
    float   box_y;                                          // 7        m_box_width
    float   box_z;                                          // 8        m_box_heigh
    float   box_orientation;                                // 9        m_box_yaw
};

struct AuctionHouseEntry
{
    uint32    houseId;                                      // 0 index
    uint32    faction;                                      // 1 id of faction.dbc for player factions associated with city
    uint32    depositPercent;                               // 2 1/3 from real
    uint32    cutPercent;                                   // 3
    //char*     name[16];                                   // 4-19
                                                            // 20 string flag, unused
};

struct BankBagSlotPricesEntry
{
    uint32  ID;
    uint32  price;
};

struct BannedAddOnsEntry
{
    uint32 Id;
    // uint32 NameMD5[4];
    // uint32 VersionMD5[4];
    // uint32 Timestamp;
    // uint32 State;
};

struct BarberShopStyleEntry
{
    uint32  Id;                                             // 0
    uint32  type;                                           // 1 value 0 -> hair, value 2 -> facialhair
    //char*   name[16];                                     // 2-17 name of hair style
    //uint32  name_flags;                                   // 18
    //uint32  unk_name[16];                                 // 19-34, all empty
    //uint32  unk_flags;                                    // 35
    //float   CostMultiplier;                               // 36 values 1 and 0.75
    uint32  race;                                           // 37 race
    uint32  gender;                                         // 38 0 -> male, 1 -> female
    uint32  hair_id;                                        // 39 real ID to hair/facial hair
};

struct BattlemasterListEntry
{
    uint32  id;                                             // 0
    int32   mapid[8];                                       // 1-8 mapid
    uint32  type;                                           // 9 map type (3 - BG, 4 - arena)
    //uint32 canJoinAsGroup;                                // 10 (0 or 1)
    char*   name[16];                                       // 11-26
    //uint32 nameFlags                                      // 27 string flag, unused
    uint32 maxGroupSize;                                    // 28 maxGroupSize, used for checking if queue as group
    uint32 HolidayWorldStateId;                             // 29 new 3.1
    //uint32 MinLevel;                                      // 30
    //uint32 SomeLevel;                                     // 31, may be max level
};

#define MAX_OUTFIT_ITEMS 24

struct CharStartOutfitEntry
{
    //uint32 Id;                                            // 0
    uint8 Race;                                             // 1
    uint8 Class;                                            // 2
    uint8 Gender;                                           // 3
    //uint8 Unused;                                         // 4
    int32 ItemId[MAX_OUTFIT_ITEMS];                         // 5-28
    //int32 ItemDisplayId[MAX_OUTFIT_ITEMS];                // 29-52 not required at server side
    //int32 ItemInventorySlot[MAX_OUTFIT_ITEMS];            // 53-76 not required at server side
};

enum CharSectionFlags
{
    SECTION_FLAG_PLAYER       = 0x01,
    SECTION_FLAG_DEATH_KNIGHT = 0x04
};

enum CharSectionType
{
    SECTION_TYPE_SKIN         = 0,
    SECTION_TYPE_FACE         = 1,
    SECTION_TYPE_FACIAL_HAIR  = 2,
    SECTION_TYPE_HAIR         = 3,
    SECTION_TYPE_UNDERWEAR    = 4
};

struct CharSectionsEntry
{
    //uint32 Id;
    uint32 Race;
    uint32 Gender;
    uint32 GenType;
    //char* TexturePath[3];
    uint32 Flags;
    uint32 Type;
    uint32 Color;
};

struct CharTitlesEntry
{
    uint32  ID;                                             // 0, title ids, for example in Quest::GetCharTitleId()
    //uint32      unk1;                                     // 1 flags?
    char*   nameMale[16];                                   // 2-17
                                                            // 18 string flag, unused
    char*   nameFemale[16];                                 // 19-34
                                                            // 35 string flag, unused
    uint32  bit_index;                                      // 36 used in PLAYER_CHOSEN_TITLE and 1<<index in PLAYER__FIELD_KNOWN_TITLES
};

struct ChatChannelsEntry
{
    uint32  ChannelID;                                      // 0
    uint32  flags;                                          // 1
    char*   pattern[16];                                    // 3-18
                                                            // 19 string flags, unused
    //char*       name[16];                                 // 20-35 unused
                                                            // 36 string flag, unused
};

struct ChrClassesEntry
{
    uint32  ClassID;                                        // 0
                                                            // 1, unused
    uint32  powerType;                                      // 2
                                                            // 3-4, unused
    char*   name[16];                                       // 5-20 unused
                                                            // 21 string flag, unused
    //char*       nameFemale[16];                           // 21-36 unused, if different from base (male) case
                                                            // 37 string flag, unused
    //char*       nameNeutralGender[16];                    // 38-53 unused, if different from base (male) case
                                                            // 54 string flag, unused
                                                            // 55, unused
    uint32  spellfamily;                                    // 56
                                                            // 57, unused
    uint32  CinematicSequence;                              // 58 id from CinematicSequences.dbc
    uint32  expansion;                                       // 59 (0 - original race, 1 - tbc addon, ...)
};

struct ChrRacesEntry
{
    uint32      RaceID;                                     // 0
    uint32      Flags;                                      // 1
    uint32      FactionID;                                  // 2 facton template id
                                                            // 3 unused
    uint32      model_m;                                    // 4
    uint32      model_f;                                    // 5
                                                            // 6 unused
    uint32      TeamID;                                     // 7 (7-Alliance 1-Horde)
                                                            // 8-11 unused
    uint32      CinematicSequence;                          // 12 id from CinematicSequences.dbc
    //uint32    unk_322;                                    // 13 faction (0 alliance, 1 horde, 2 not available?)
    char*       name[16];                                   // 14-29 used for DBC language detection/selection
                                                            // 30 string flags, unused
    //char*       nameFemale[16];                           // 31-46, if different from base (male) case
                                                            // 47 string flags, unused
    //char*       nameNeutralGender[16];                    // 48-63, if different from base (male) case
                                                            // 64 string flags, unused
                                                            // 65-67 unused
    uint32      expansion;                                  // 68 (0 - original race, 1 - tbc addon, ...)
};

struct CinematicCameraEntry
{
    uint32 ID;                                              // 0
    char const* Model;                                      // 1    Model filename (translate .mdx to .m2)
    uint32 SoundID;                                         // 2    Sound ID       (voiceover for cinematic)
    DBCPosition3D Origin;                                   // 3-5  Position in map used for basis for M2 co-ordinates
    float OriginFacing;                                     // 6    Orientation in map used for basis for M2 co-ordinates
};

struct CinematicSequencesEntry
{
    uint32      Id;                                         // 0 index
    //uint32      unk1;                                     // 1 always 0
    uint32      cinematicCamera;                            // 2 id in CinematicCamera.dbc
                                                            // 3-9 always 0
};

struct CreatureDisplayInfoEntry
{
    uint32      Displayid;                                  // 0        m_ID
    uint32      ModelId;                                    // 1        m_modelID
                                                            // 2        m_soundID
    uint32      ExtraId;                                    // 3        m_extendedDisplayInfoID
    float       scale;                                      // 4        m_creatureModelScale
                                                            // 5        m_creatureModelAlpha
                                                            // 6-8      m_textureVariation[3]
                                                            // 9        m_portraitTextureName
                                                            // 10       m_sizeClass
                                                            // 11       m_bloodID
                                                            // 12       m_NPCSoundID
                                                            // 13       m_particleColorID
                                                            // 14       m_creatureGeosetData
                                                            // 15       m_objectEffectPackageID
};

struct CreatureDisplayInfoExtraEntry
{
    //uint32 Id;                                            // 0
    uint32 Race;                                            // 1
    uint32 Gender;                                          // 2
    //uint32 SkinColor;                                     // 3
    //uint32 FaceType;                                      // 4
    //uint32 HairType;                                      // 5
    //uint32 HairStyle;                                     // 6
    //uint32 FacialHair;                                    // 7
    //uint32 HelmDisplayId;                                 // 8
    //uint32 ShoulderDisplayId;                             // 9
    //uint32 ShirtDisplayId;                                // 10
    //uint32 ChestDisplayId;                                // 11
    //uint32 BeltDisplayId;                                 // 12
    //uint32 LegsDisplayId;                                 // 13
    //uint32 BootsDisplayId;                                // 14
    //uint32 WristDisplayId;                                // 15
    //uint32 GlovesDisplayId;                               // 16
    //uint32 TabardDisplayId;                               // 17
    //uint32 CloakDisplayId;                                // 18
    //uint32 CanEquip;                                      // 19
    //char const* Texture;                                  // 20
};

struct CreatureFamilyEntry
{
    uint32  ID;                                             // 0        m_ID
    float   minScale;                                       // 1        m_minScale
    uint32  minScaleLevel;                                  // 2        m_minScaleLevel
    float   maxScale;                                       // 3        m_maxScale
    uint32  maxScaleLevel;                                  // 4        m_maxScaleLevel
    uint32  skillLine[2];                                   // 5-6      m_skillLine
    uint32  petFoodMask;                                    // 7        m_petFoodMask
    int32   petTalentType;                                  // 8        m_petTalentType
                                                            // 9        m_categoryEnumID
    char*   Name[16];                                       // 10-25    m_name_lang
                                                            // 26 string flags
                                                            // 27       m_iconFile
};

struct CreatureModelDataEntry
{
    uint32 Id;
    uint32 Flags;
    char* ModelPath;
    //uint32 Unk1;
    float Scale;                                             // Used in calculation of unit collision data
    //int32 Unk2
    //int32 Unk3
    //uint32 Unk4
    //uint32 Unk5
    //float Unk6
    //uint32 Unk7
    //float Unk8
    //uint32 Unk9
    //uint32 Unk10
    //float CollisionWidth;
    float CollisionHeight;
    float MountHeight;                                       // Used in calculation of unit collision data when mounted
    //float Unks[11]
};

#define MAX_CREATURE_SPELL_DATA_SLOT 4

struct CreatureSpellDataEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    spellId[MAX_CREATURE_SPELL_DATA_SLOT];        // 1-4      m_spells[4]
    //uint32    availability[MAX_CREATURE_SPELL_DATA_SLOT]; // 4-7      m_availability[4]
};

struct CreatureTypeEntry
{
    uint32    ID;                                           // 0        m_ID
    //char*   Name[16];                                     // 1-16     name
                                                            // 17       string flags
    //uint32    no_expirience;                              // 18 no exp? critters, non-combat pets, gas cloud.
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
    //uint32    ID;                                         // 0        not used
    uint32    ItemId;                                       // 1        used as real index
    //uint32    Category;                                   // 2        may be category
    uint32    BitIndex;                                     // 3        bit index in PLAYER_FIELD_KNOWN_CURRENCIES (1 << (index-1))
};

struct DestructibleModelDataEntry
{
    uint32  Id;
    //uint32  DamagedUnk1;
    //uint32  DamagedUnk2;
    uint32  DamagedDisplayId;
    //uint32  DamagedUnk3;
    //uint32  DestroyedUnk1;
    //uint32  DestroyedUnk2;
    uint32  DestroyedDisplayId;
    //uint32  DestroyedUnk3;
    //uint32  RebuildingUnk1;
    //uint32  RebuildingUnk2;
    uint32  RebuildingDisplayId;
    //uint32  RebuildingUnk3;
    //uint32  SmokeUnk1;
    //uint32  SmokeUnk2;
    uint32  SmokeDisplayId;
    //uint32  SmokeUnk3;
    //uint32  Unk4;
    //uint32  Unk5;
};

struct DungeonEncounterEntry
{
    uint32 id;                                              // 0        unique id
    uint32 mapId;                                           // 1        map id
    uint32 difficulty;                                      // 2        instance mode
    //uint32 unk0;                                          // 3
    uint32 encounterIndex;                                  // 4        encounter index for creating completed mask
    char*  encounterName[16];                               // 5-20     encounter name
    //uint32 nameFlags;                                     // 21
    //uint32 unk1;                                          // 22
};

struct DurabilityCostsEntry
{
    uint32    Itemlvl;                                      // 0
    uint32    multiplier[29];                               // 1-29
};

struct DurabilityQualityEntry
{
    uint32    Id;                                           // 0
    float     quality_mod;                                  // 1
};

struct EmotesEntry
{
    uint32  Id;                                             // 0
    //char*   Name;                                         // 1, internal name
    //uint32  AnimationId;                                  // 2, ref to animationData
    uint32  Flags;                                          // 3, bitmask, may be unit_flags
    uint32  EmoteType;                                      // 4, Can be 0, 1 or 2 (determine how emote are shown)
    uint32  UnitStandState;                                 // 5, uncomfirmed, may be enum UnitStandStateType
    //uint32  SoundId;                                      // 6, ref to soundEntries
};

struct EmotesTextEntry
{
    uint32  Id;
    uint32  textid;
};

struct EmotesTextSoundEntry
{
    uint32 Id;                                              // 0
    uint32 EmotesTextId;                                    // 1
    uint32 RaceId;                                          // 2
    uint32 SexId;                                           // 3, 0 male / 1 female
    uint32 SoundId;                                         // 4
};

struct FactionEntry
{
    uint32      ID;                                         // 0        m_ID
    int32       reputationListID;                           // 1        m_reputationIndex
    uint32      BaseRepRaceMask[4];                         // 2-5      m_reputationRaceMask
    uint32      BaseRepClassMask[4];                        // 6-9      m_reputationClassMask
    int32       BaseRepValue[4];                            // 10-13    m_reputationBase
    uint32      ReputationFlags[4];                         // 14-17    m_reputationFlags
    uint32      team;                                       // 18       m_parentFactionID
    float       spilloverRateIn;                            // 19       Faction gains incoming rep * spilloverRateIn
    float       spilloverRateOut;                           // 20       Faction outputs rep * spilloverRateOut as spillover reputation
    uint32      spilloverMaxRankIn;                         // 21       The highest rank the faction will profit from incoming spillover
    //uint32    spilloverRank_unk;                          // 22       It does not seem to be the max standing at which a faction outputs spillover ...so no idea
    char*       name[16];                                   // 23-38    m_name_lang
                                                            // 39 string flags
    //char*     description[16];                            // 40-55    m_description_lang
                                                            // 56 string flags

    // helpers
    bool CanHaveReputation() const
    {
        return reputationListID >= 0;
    }
};

#define MAX_FACTION_RELATIONS 4

struct FactionTemplateEntry
{
    uint32      ID;                                         // 0        m_ID
    uint32      faction;                                    // 1        m_faction
    uint32      factionFlags;                               // 2        m_flags
    uint32      ourMask;                                    // 3        m_factionGroup
    uint32      friendlyMask;                               // 4        m_friendGroup
    uint32      hostileMask;                                // 5        m_enemyGroup
    uint32      enemyFaction[MAX_FACTION_RELATIONS];        // 6        m_enemies[MAX_FACTION_RELATIONS]
    uint32      friendFaction[MAX_FACTION_RELATIONS];       // 10       m_friend[MAX_FACTION_RELATIONS]
    //-------------------------------------------------------  end structure

    // helpers
    bool IsFriendlyTo(FactionTemplateEntry const& entry) const
    {
        if (entry.faction)
        {
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (enemyFaction[i] == entry.faction)
                    return false;
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (friendFaction[i] == entry.faction)
                    return true;
        }
        return (friendlyMask & entry.ourMask) || (ourMask & entry.friendlyMask);
    }
    bool IsHostileTo(FactionTemplateEntry const& entry) const
    {
        if (entry.faction)
        {
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (enemyFaction[i] == entry.faction)
                    return true;
            for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (friendFaction[i] == entry.faction)
                    return false;
        }
        return (hostileMask & entry.ourMask) != 0;
    }
    bool IsHostileToPlayers() const { return (hostileMask & FACTION_MASK_PLAYER) !=0; }
    bool IsNeutralToAll() const
    {
        for (int i = 0; i < MAX_FACTION_RELATIONS; ++i)
            if (enemyFaction[i] != 0)
                return false;
        return hostileMask == 0 && friendlyMask == 0;
    }
    bool IsContestedGuardFaction() const { return (factionFlags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD) != 0; }
};

struct GameObjectDisplayInfoEntry
{
    uint32      Displayid;                                  // 0        m_ID
    char* filename;                                      // 1
    //uint32  unk1[10];   //2-11
    float   minX;
    float   minY;
    float   minZ;
    float   maxX;
    float   maxY;
    float   maxZ;
    //uint32  transport;  //18
};

struct GemPropertiesEntry
{
    uint32      ID;
    uint32      spellitemenchantement;
    uint32      color;
};

struct GlyphPropertiesEntry
{
    uint32  Id;
    uint32  SpellId;
    uint32  TypeFlags;
    uint32  Unk1;                                           // GlyphIconId (SpellIcon.dbc)
};

struct GlyphSlotEntry
{
    uint32  Id;
    uint32  TypeFlags;
    uint32  Order;
};

// All Gt* DBC store data for 100 levels, some by 100 per class/race
#define GT_MAX_LEVEL    100
// gtOCTClassCombatRatingScalar.dbc stores data for 32 ratings, look at MAX_COMBAT_RATING for real used amount
#define GT_MAX_RATING   32

struct GtBarberShopCostBaseEntry
{
    float   cost;
};

struct GtCombatRatingsEntry
{
    float    ratio;
};

struct GtChanceToMeleeCritBaseEntry
{
    float    base;
};

struct GtChanceToMeleeCritEntry
{
    float    ratio;
};

struct GtChanceToSpellCritBaseEntry
{
    float    base;
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

//struct GtOCTRegenMPEntry
//{
//    float    ratio;
//};

struct GtRegenHPPerSptEntry
{
    float    ratio;
};

struct GtRegenMPPerSptEntry
{
    float    ratio;
};

/* no used
struct HolidayDescriptionsEntry
{
    uint32 ID;                                              // 0, m_holidayDescriptionID
    //char*     name[16]                                    // 1-16 m_name_lang
                                                            // 17 name flags
};
*/

/* no used
struct HolidayNamesEntry
{
    uint32 ID;                                              // 0, m_holidayNameID
    //char*     name[16]                                    // 1-16 m_name_lang
    // 17 name flags
};
*/

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 26
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32 Id;                                              // 0        m_ID
    uint32 Duration[MAX_HOLIDAY_DURATIONS];                 // 1-10     m_duration
    uint32 Date[MAX_HOLIDAY_DATES];                         // 11-36    m_date (dates in unix time starting at January, 1, 2000)
    uint32 Region;                                          // 37       m_region (wow region)
    uint32 Looping;                                         // 38       m_looping
    uint32 CalendarFlags[MAX_HOLIDAY_FLAGS];                // 39-48    m_calendarFlags
    //uint32 holidayNameId;                                 // 49       m_holidayNameID (HolidayNames.dbc)
    //uint32 holidayDescriptionId;                          // 50       m_holidayDescriptionID (HolidayDescriptions.dbc)
    char* TextureFilename;                                  // 51       m_textureFilename
    uint32 Priority;                                        // 52       m_priority
    uint32 CalendarFilterType;                              // 53       m_calendarFilterType (-1 = Fishing Contest, 0 = Unk, 1 = Darkmoon Festival, 2 = Yearly holiday)
    //uint32 flags;                                         // 54       m_flags (0 = Darkmoon Faire, Fishing Contest and Wotlk Launch, rest is 1)
};

struct ItemEntry
{
   uint32   ID;                                             // 0
   uint32   Class;                                          // 1
   uint32   SubClass;                                       // 2 some items have strange subclasses
   int32    SoundOverrideSubclass;                          // 3
   int32    Material;                                       // 4
   uint32   DisplayId;                                      // 5
   uint32   InventoryType;                                  // 6
   uint32   Sheath;                                         // 7
};

struct ItemBagFamilyEntry
{
    uint32   ID;                                            // 0
    //char*     name[16]                                    // 1-16     m_name_lang
    //                                                      // 17       name flags
};

struct ItemDisplayInfoEntry
{
    uint32      ID;                                         // 0        m_ID
                                                            // 1        m_modelName[2]
                                                            // 2        m_modelTexture[2]
    char*       inventoryIcon;                              // 3        m_inventoryIcon
                                                            // 4        m_geosetGroup[3]
                                                            // 5        m_flags
                                                            // 6        m_spellVisualID
                                                            // 7        m_groupSoundIndex
                                                            // 8        m_helmetGeosetVis[2]
                                                            // 9        m_texture[2]
                                                            // 10       m_itemVisual[8]
                                                            // 11       m_particleColorID
};

//struct ItemCondExtCostsEntry
//{
//    uint32      ID;
//    uint32      condExtendedCost;                         // ItemTemplate::CondExtendedCost
//    uint32      itemextendedcostentry;                    // ItemTemplate::ExtendedCost
//    uint32      arenaseason;                              // arena season number(1-4)
//};

#define MAX_ITEM_EXTENDED_COST_REQUIREMENTS 5

struct ItemExtendedCostEntry
{
    uint32      ID;                                                 // 0 extended-cost entry id
    uint32      reqhonorpoints;                                     // 1 required honor points
    uint32      reqarenapoints;                                     // 2 required arena points
    uint32      reqarenaslot;                                       // 3 arena slot restrctions (min slot value)
    uint32      reqitem[MAX_ITEM_EXTENDED_COST_REQUIREMENTS];       // 4-8 required item id
    uint32      reqitemcount[MAX_ITEM_EXTENDED_COST_REQUIREMENTS];  // 9-14 required count of 1st item
    uint32      reqpersonalarenarating;                             // 15 required personal arena rating};
};

struct ItemLimitCategoryEntry
{
    uint32      ID;                                         // 0 Id
    //char*     name[16]                                    // 1-16     m_name_lang
                                                            // 17 name flags
    uint32      maxCount;                                   // 18, max allowed equipped as item or in gem slot
    uint32      mode;                                       // 19, 0 = have, 1 = equip (enum ItemLimitCategoryMode)
};

#define MAX_ITEM_ENCHANTMENT_EFFECTS 3

struct ItemRandomPropertiesEntry
{
    uint32    ID;                                           // 0        m_ID
    //char*     internalName                                // 1        m_Name
    uint32    enchant_id[MAX_ITEM_ENCHANTMENT_EFFECTS];     // 2-4      m_Enchantment
                                                            // 5-6      unused
    char*     nameSuffix[16];                               // 7-22     m_name_lang
                                                            // 23 name flags
};

struct ItemRandomSuffixEntry
{
    uint32    ID;                                           // 0        m_ID
    char*     nameSuffix[16];                               // 1-16     m_name_lang
                                                            // 17, name flags
                                                            // 18       m_internalName
    uint32    enchant_id[MAX_ITEM_ENCHANTMENT_EFFECTS];     // 19-21    m_enchantment
    //uint32    unk1[2]                                     // 22-23    unknown
    uint32    prefix[MAX_ITEM_ENCHANTMENT_EFFECTS];         // 24-26    m_allocationPct
    //uint32    unk2[2]                                     // 27-28    unknown
};

#define MAX_ITEM_SET_ITEMS 10
#define MAX_ITEM_SET_SPELLS 8

struct ItemSetEntry
{
    //uint32    id                                          // 0        m_ID
    char*     name[16];                                     // 1-16     m_name_lang
                                                            // 17 string flags, unused
    uint32    itemId[MAX_ITEM_SET_ITEMS];                   // 18-27    m_itemID
    //uint32    unknown[7];                                 // 28-34    unk, all 0
    uint32    spells[MAX_ITEM_SET_SPELLS];                  // 35-42    m_setSpellID
    uint32    items_to_triggerspell[MAX_ITEM_SET_SPELLS];   // 43-50    m_setThreshold
    uint32    required_skill_id;                            // 51       m_requiredSkill
    uint32    required_skill_value;                         // 52       m_requiredSkillRank
};

struct LFGDungeonEntry
{
    uint32  ID;                                             // 0
    char*   name[16];                                       // 1-17 Name lang
    uint32  minlevel;                                       // 18
    uint32  maxlevel;                                       // 19
    uint32  reclevel;                                       // 20
    uint32  recminlevel;                                    // 21
    uint32  recmaxlevel;                                    // 22
    int32   map;                                            // 23
    uint32  difficulty;                                     // 24
    uint32  flags;                                          // 25
    uint32  type;                                           // 26
    //uint32  unk;                                          // 27
    //char*   iconname;                                     // 28
    uint32  expansion;                                      // 29
    //uint32  unk4;                                         // 30
    uint32  grouptype;                                      // 31
    //char*   desc[16];                                     // 32-47 Description
    // Helpers
    uint32 Entry() const { return ID + (type << 24); }
};

struct LightEntry
{
    uint32 Id;
    uint32 MapId;
    float X;
    float Y;
    float Z;
    //float FalloffStart;
    //float FalloffEnd;
    //uint32 SkyAndFog;
    //uint32 WaterSettings;
    //uint32 SunsetParams;
    //uint32 OtherParams;
    //uint32 DeathParams;
    //uint32 Unknown;
    //uint32 Unknown;
    //uint32 Unknown;
};

struct LiquidTypeEntry
{
    uint32 Id;
    //char*  Name;
    //uint32 Flags;
    uint32 Type;
    //uint32 SoundId;
    uint32 SpellId;
    //float MaxDarkenDepth;
    //float FogDarkenIntensity;
    //float AmbDarkenIntensity;
    //float DirDarkenIntensity;
    //uint32 LightID;
    //float ParticleScale;
    //uint32 ParticleMovement;
    //uint32 ParticleTexSlots;
    //uint32 LiquidMaterialID;
    //char* Texture[6];
    //uint32 Color[2];
    //float Unk1[18];
    //uint32 Unk2[4];
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32      ID;                                         // 0        m_ID
    uint32      Type[MAX_LOCK_CASE];                        // 1-8      m_Type
    uint32      Index[MAX_LOCK_CASE];                       // 9-16     m_Index
    uint32      Skill[MAX_LOCK_CASE];                       // 17-24    m_Skill
    //uint32      Action[MAX_LOCK_CASE];                    // 25-32    m_Action
};

struct MailTemplateEntry
{
    uint32      ID;                                         // 0
    //char*       subject[16];                              // 1-16
                                                            // 17 name flags, unused
    char*       content[16];                                // 18-33
};

struct MapEntry
{
    uint32  MapID;                                          // 0
    //char*       internalname;                             // 1 unused
    uint32  map_type;                                       // 2
    uint32  Flags;                                          // 3
                                                            // 4 0 or 1 for battlegrounds (not arenas)
    char*   name[16];                                       // 5-20
                                                            // 21 name flags, unused
    uint32  linked_zone;                                    // 22 common zone for instance and continent map
    //char*     hordeIntro[16];                             // 23-38 text for PvP Zones
                                                            // 39 intro text flags
    //char*     allianceIntro[16];                          // 40-55 text for PvP Zones
                                                            // 56 intro text flags
    uint32  multimap_id;                                    // 57
    //float BattlefieldMapIconScale;                        // 58
    int32   entrance_map;                                   // 59 map_id of entrance map
    float   entrance_x;                                     // 60 entrance x coordinate (if exist single entry)
    float   entrance_y;                                     // 61 entrance y coordinate (if exist single entry)
    //uint32 TimeOfDayOverride;                             // 62 -1, 0 and 720
    uint32  addon;                                          // 63 (0-original maps, 1-tbc addon)
    uint32  unk_time;                                       // 64 some kind of time?
    uint32  maxPlayers;                                     // 65 max players, fallback if not present in MapDifficulty.dbc

    // Helpers
    uint32 Expansion() const { return addon; }

    bool IsDungeon() const { return map_type == MAP_INSTANCE || map_type == MAP_RAID; }
    bool IsNonRaidDungeon() const { return map_type == MAP_INSTANCE; }
    bool Instanceable() const { return map_type == MAP_INSTANCE || map_type == MAP_RAID || map_type == MAP_BATTLEGROUND || map_type == MAP_ARENA; }
    bool IsRaid() const { return map_type == MAP_RAID; }
    bool IsBattleground() const { return map_type == MAP_BATTLEGROUND; }
    bool IsBattleArena() const { return map_type == MAP_ARENA; }
    bool IsBattlegroundOrArena() const { return map_type == MAP_BATTLEGROUND || map_type == MAP_ARENA; }
    bool IsWorldMap() const { return map_type == MAP_COMMON; }

    bool GetEntrancePos(int32 &mapid, float &x, float &y) const
    {
        if (entrance_map < 0)
            return false;
        mapid = entrance_map;
        x = entrance_x;
        y = entrance_y;
        return true;
    }

    bool IsContinent() const
    {
        return MapID == 0 || MapID == 1 || MapID == 530 || MapID == 571;
    }

    bool IsDynamicDifficultyMap() const { return (Flags & MAP_FLAG_DYNAMIC_DIFFICULTY) != 0; }
};

struct MapDifficultyEntry
{
    //uint32      Id;                                       // 0
    uint32      MapId;                                      // 1
    uint32      Difficulty;                                 // 2 (for arenas: arena slot)
    char*       areaTriggerText;                            // 3-18 text showed when transfer to map failed (missing requirements)
    //uint32      textFlags;                                // 19
    uint32      resetTime;                                  // 20
    uint32      maxPlayers;                                 // 21
    //char*       difficultyString;                         // 22
};

struct MovieEntry
{
    uint32      Id;                                         // 0 index
    //char*       filename;                                 // 1
    //uint32      unk2;                                     // 2 always 100
};

struct NamesProfanityEntry
{
    //uint32    ID;                                         // 0
    char const* Name;                                       // 1
    int32       Language;                                   // 2
};

struct NamesReservedEntry
{
    //uint32    ID;                                         // 0
    char const* Name;                                       // 1
    int32       Language;                                   // 2
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32      id;                                         // 0
    uint32      spellId[MAX_OVERRIDE_SPELL];                // 1-10
    //uint32      unk0;                                     // 11
};

struct PowerDisplayEntry
{
    uint32 Id;                                              // 0
    uint32 PowerType;                                       // 1
    //char*  Name;                                          // 2
    //uint32 R;                                             // 3
    //uint32 G;                                             // 4
    //uint32 B;                                             // 5
};

struct PvPDifficultyEntry
{
    //uint32      id;                                       // 0        m_ID
    uint32      mapId;                                      // 1
    uint32      bracketId;                                  // 2
    uint32      minLevel;                                   // 3
    uint32      maxLevel;                                   // 4
    uint32      difficulty;                                 // 5

    // helpers
    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(bracketId); }
};

struct QuestSortEntry
{
    uint32      id;                                         // 0        m_ID
    //char*       name[16];                                 // 1-16     m_SortName_lang
                                                            // 17 name flags
};

struct QuestXPEntry
{
  uint32      id;
  uint32      Exp[10];
};

struct QuestFactionRewEntry
{
  uint32      id;
  int32       QuestRewFactionValue[10];
};

struct RandomPropertiesPointsEntry
{
    //uint32  Id;                                           // 0 hidden key
    uint32    itemLevel;                                    // 1
    uint32    EpicPropertiesPoints[5];                      // 2-6
    uint32    RarePropertiesPoints[5];                      // 7-11
    uint32    UncommonPropertiesPoints[5];                  // 12-16
};

struct ScalingStatDistributionEntry
{
    uint32  Id;                                             // 0
    int32   StatMod[10];                                    // 1-10
    uint32  Modifier[10];                                   // 11-20
    uint32  MaxLevel;                                       // 21
};

struct ScalingStatValuesEntry
{
    uint32  Id;                                             // 0
    uint32  Level;                                          // 1
    uint32  ssdMultiplier[4];                               // 2-5 Multiplier for ScalingStatDistribution
    uint32  armorMod[4];                                    // 6-9 Armor for level
    uint32  dpsMod[6];                                      // 10-15 DPS mod for level
    uint32  spellPower;                                     // 16 spell power for level
    uint32  ssdMultiplier2;                                 // 17 there's data from 3.1 dbc ssdMultiplier[3]
    uint32  ssdMultiplier3;                                 // 18 3.3
    uint32  armorMod2[5];                                   // 19-23 Armor for level

    uint32 getssdMultiplier(uint32 mask) const
    {
        if (mask & 0x4001F)
        {
            if (mask & 0x00000001) return ssdMultiplier[0]; // Shoulder
            if (mask & 0x00000002) return ssdMultiplier[1]; // Trinket
            if (mask & 0x00000004) return ssdMultiplier[2]; // Weapon1H
            if (mask & 0x00000008) return ssdMultiplier2;
            if (mask & 0x00000010) return ssdMultiplier[3]; // Ranged
            if (mask & 0x00040000) return ssdMultiplier3;
        }
        return 0;
    }

    uint32 getArmorMod(uint32 mask) const
    {
        if (mask & 0x00F001E0)
        {
            if (mask & 0x00000020) return armorMod[0];      // Cloth shoulder
            if (mask & 0x00000040) return armorMod[1];      // Leather shoulder
            if (mask & 0x00000080) return armorMod[2];      // Mail shoulder
            if (mask & 0x00000100) return armorMod[3];      // Plate shoulder

            if (mask & 0x00080000) return armorMod2[0];      // cloak
            if (mask & 0x00100000) return armorMod2[1];      // cloth
            if (mask & 0x00200000) return armorMod2[2];      // leather
            if (mask & 0x00400000) return armorMod2[3];      // mail
            if (mask & 0x00800000) return armorMod2[4];      // plate
        }
        return 0;
    }

    uint32 getDPSMod(uint32 mask) const
    {
        if (mask & 0x7E00)
        {
            if (mask & 0x00000200) return dpsMod[0];        // Weapon 1h
            if (mask & 0x00000400) return dpsMod[1];        // Weapon 2h
            if (mask & 0x00000800) return dpsMod[2];        // Caster dps 1h
            if (mask & 0x00001000) return dpsMod[3];        // Caster dps 2h
            if (mask & 0x00002000) return dpsMod[4];        // Ranged
            if (mask & 0x00004000) return dpsMod[5];        // Wand
        }
        return 0;
    }

    uint32 getSpellBonus(uint32 mask) const
    {
        if (mask & 0x00008000) return spellPower;
        return 0;
    }

    uint32 getFeralBonus(uint32 /*mask*/) const                 // removed in 3.2.x?
    {
        //if (mask & 0x00010000) return 0;                  // not used?
        return 0;
    }
};

//struct SkillLineCategoryEntry{
//    uint32    id;                                         // 0      m_ID
//    char*     name[16];                                   // 1-17   m_name_lang
//                                                          // 18 string flag
//    uint32    displayOrder;                               // 19     m_sortIndex
//};

struct SkillLineEntry
{
    uint32    id;                                           // 0        m_ID
    int32     categoryId;                                   // 1        m_categoryID
    //uint32    skillCostID;                                // 2        m_skillCostsID
    char*     name[16];                                     // 3-18     m_displayName_lang
                                                            // 19 string flags
    //char*     description[16];                            // 20-35    m_description_lang
                                                            // 36 string flags
    uint32    spellIcon;                                    // 37       m_spellIconID
    //char*     alternateVerb[16];                          // 38-53    m_alternateVerb_lang
                                                            // 54 string flags
    uint32    canLink;                                      // 55       m_canLink (prof. with recipes
};

struct SkillLineAbilityEntry
{
    uint32    id;                                           // 0        m_ID
    uint32    skillId;                                      // 1        m_skillLine
    uint32    spellId;                                      // 2        m_spell
    uint32    racemask;                                     // 3        m_raceMask
    uint32    classmask;                                    // 4        m_classMask
    //uint32    racemaskNot;                                // 5        m_excludeRace
    //uint32    classmaskNot;                               // 6        m_excludeClass
    uint32    req_skill_value;                              // 7        m_minSkillLineRank
    uint32    forward_spellid;                              // 8        m_supercededBySpell
    uint32    AutolearnType;                                // 9        m_acquireMethod
    uint32    max_value;                                    // 10       m_trivialSkillLineRankHigh
    uint32    min_value;                                    // 11       m_trivialSkillLineRankLow
    //uint32    characterPoints[2];                         // 12-13    m_characterPoints[2]
};

struct SkillRaceClassInfoEntry
{
    //uint32 Id;                                            // 0
    uint32 SkillId;                                         // 1
    uint32 RaceMask;                                        // 2
    uint32 ClassMask;                                       // 3
    uint32 Flags;                                           // 4
    //uint32 MinLevel;                                      // 5
    uint32 SkillTier;                                       // 6
    //uint32 SkillCostType;                                 // 7
};

#define MAX_SKILL_STEP 16

struct SkillTiersEntry
{
    uint32 Id;                                              // 0
    //uint32 StepCost[MAX_SKILL_STEP];                      // 1-16
    uint32 MaxSkill[MAX_SKILL_STEP];                        // 17-32
};

struct SoundEntriesEntry
{
    uint32    Id;                                           // 0        m_ID
    //uint32    Type;                                       // 1        m_soundType
    //char*     InternalName;                               // 2        m_name
    //char*     FileName[10];                               // 3-12     m_File[10]
    //uint32    Unk13[10];                                  // 13-22    m_Freq[10]
    //char*     Path;                                       // 23       m_DirectoryBase
                                                            // 24       m_volumeFloat
                                                            // 25       m_flags
                                                            // 26       m_minDistance
                                                            // 27       m_distanceCutoff
                                                            // 28       m_EAXDef
                                                            // 29       new in 3.1
};

#define MAX_SPELL_EFFECTS 3
#define MAX_EFFECT_MASK 7
#define MAX_SPELL_REAGENTS 8

struct SpellEntry
{
    uint32    Id;                                           // 0        m_ID
    uint32    Category;                                     // 1        m_category
    uint32    Dispel;                                       // 2        m_dispelType
    uint32    Mechanic;                                     // 3        m_mechanic
    uint32    Attributes;                                   // 4        m_attributes
    uint32    AttributesEx;                                 // 5        m_attributesEx
    uint32    AttributesEx2;                                // 6        m_attributesExB
    uint32    AttributesEx3;                                // 7        m_attributesExC
    uint32    AttributesEx4;                                // 8        m_attributesExD
    uint32    AttributesEx5;                                // 9        m_attributesExE
    uint32    AttributesEx6;                                // 10       m_attributesExF
    uint32    AttributesEx7;                                // 11       m_attributesExG
    uint32    Stances[2];                                   // 12       m_shapeshiftMask
    uint32    StancesNot[2];                                // 14       m_shapeshiftExclude
    uint32    Targets;                                      // 16       m_targets
    uint32    TargetCreatureType;                           // 17       m_targetCreatureType
    uint32    RequiresSpellFocus;                           // 18       m_requiresSpellFocus
    uint32    FacingCasterFlags;                            // 19       m_facingCasterFlags
    uint32    CasterAuraState;                              // 20       m_casterAuraState
    uint32    TargetAuraState;                              // 21       m_targetAuraState
    uint32    CasterAuraStateNot;                           // 22       m_excludeCasterAuraState
    uint32    TargetAuraStateNot;                           // 23       m_excludeTargetAuraState
    uint32    casterAuraSpell;                              // 24       m_casterAuraSpell
    uint32    targetAuraSpell;                              // 25       m_targetAuraSpell
    uint32    excludeCasterAuraSpell;                       // 26       m_excludeCasterAuraSpell
    uint32    excludeTargetAuraSpell;                       // 27       m_excludeTargetAuraSpell
    uint32    CastingTimeIndex;                             // 28       m_castingTimeIndex
    uint32    RecoveryTime;                                 // 29       m_recoveryTime
    uint32    CategoryRecoveryTime;                         // 30       m_categoryRecoveryTime
    uint32    InterruptFlags;                               // 31       m_interruptFlags
    uint32    AuraInterruptFlags;                           // 32       m_auraInterruptFlags
    uint32    ChannelInterruptFlags;                        // 33       m_channelInterruptFlags
    uint32    procFlags;                                    // 34       m_procTypeMask
    uint32    procChance;                                   // 35       m_procChance
    uint32    procCharges;                                  // 36       m_procCharges
    uint32    maxLevel;                                     // 37       m_maxLevel
    uint32    baseLevel;                                    // 38       m_baseLevel
    uint32    spellLevel;                                   // 39       m_spellLevel
    uint32    DurationIndex;                                // 40       m_durationIndex
    uint32    powerType;                                    // 41       m_powerType
    uint32    manaCost;                                     // 42       m_manaCost
    uint32    manaCostPerlevel;                             // 43       m_manaCostPerLevel
    uint32    manaPerSecond;                                // 44       m_manaPerSecond
    uint32    manaPerSecondPerLevel;                        // 45       m_manaPerSecondPerLeve
    uint32    rangeIndex;                                   // 46       m_rangeIndex
    float     speed;                                        // 47       m_speed
    //uint32    modalNextSpell;                             // 48       m_modalNextSpell not used
    uint32    StackAmount;                                  // 49       m_cumulativeAura
    uint32    Totem[2];                                     // 50-51    m_totem
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 52-59    m_reagent
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 60-67    m_reagentCount
    int32     EquippedItemClass;                            // 68       m_equippedItemClass (value)
    int32     EquippedItemSubClassMask;                     // 69       m_equippedItemSubclass (mask)
    int32     EquippedItemInventoryTypeMask;                // 70       m_equippedItemInvTypes (mask)
    uint32    Effect[MAX_SPELL_EFFECTS];                    // 71-73    m_effect
    int32     EffectDieSides[MAX_SPELL_EFFECTS];            // 74-76    m_effectDieSides
    float     EffectRealPointsPerLevel[MAX_SPELL_EFFECTS];  // 77-79    m_effectRealPointsPerLevel
    int32     EffectBasePoints[MAX_SPELL_EFFECTS];          // 80-82    m_effectBasePoints (must not be used in spell/auras explicitly, must be used cached Spell::m_currentBasePoints)
    uint32    EffectMechanic[MAX_SPELL_EFFECTS];            // 83-85    m_effectMechanic
    uint32    EffectImplicitTargetA[MAX_SPELL_EFFECTS];     // 86-88    m_implicitTargetA
    uint32    EffectImplicitTargetB[MAX_SPELL_EFFECTS];     // 89-91    m_implicitTargetB
    uint32    EffectRadiusIndex[MAX_SPELL_EFFECTS];         // 92-94    m_effectRadiusIndex - spellradius.dbc
    uint32    EffectApplyAuraName[MAX_SPELL_EFFECTS];       // 95-97    m_effectAura
    uint32    EffectAmplitude[MAX_SPELL_EFFECTS];           // 98-100   m_effectAuraPeriod
    float     EffectValueMultiplier[MAX_SPELL_EFFECTS];     // 101-103
    uint32    EffectChainTarget[MAX_SPELL_EFFECTS];         // 104-106  m_effectChainTargets
    uint32    EffectItemType[MAX_SPELL_EFFECTS];            // 107-109  m_effectItemType
    int32     EffectMiscValue[MAX_SPELL_EFFECTS];           // 110-112  m_effectMiscValue
    int32     EffectMiscValueB[MAX_SPELL_EFFECTS];          // 113-115  m_effectMiscValueB
    uint32    EffectTriggerSpell[MAX_SPELL_EFFECTS];        // 116-118  m_effectTriggerSpell
    float     EffectPointsPerComboPoint[MAX_SPELL_EFFECTS]; // 119-121  m_effectPointsPerCombo
    flag96    EffectSpellClassMask[MAX_SPELL_EFFECTS];      // 122-130
    uint32    SpellVisual[2];                               // 131-132  m_spellVisualID
    uint32    SpellIconID;                                  // 133      m_spellIconID
    uint32    activeIconID;                                 // 134      m_activeIconID
    //uint32    spellPriority;                              // 135 not used
    char*     SpellName[16];                                // 136-151  m_name_lang
    //uint32    SpellNameFlag;                              // 152 not used
    char*     Rank[16];                                     // 153-168  m_nameSubtext_lang
    //uint32    RankFlags;                                  // 169 not used
    //char*     Description[16];                            // 170-185  m_description_lang not used
    //uint32    DescriptionFlags;                           // 186 not used
    //char*     ToolTip[16];                                // 187-202  m_auraDescription_lang not used
    //uint32    ToolTipFlags;                               // 203 not used
    uint32    ManaCostPercentage;                           // 204      m_manaCostPct
    uint32    StartRecoveryCategory;                        // 205      m_startRecoveryCategory
    uint32    StartRecoveryTime;                            // 206      m_startRecoveryTime
    uint32    MaxTargetLevel;                               // 207      m_maxTargetLevel
    uint32    SpellFamilyName;                              // 208      m_spellClassSet
    flag96    SpellFamilyFlags;                             // 209-211
    uint32    MaxAffectedTargets;                           // 212      m_maxTargets
    uint32    DmgClass;                                     // 213      m_defenseType
    uint32    PreventionType;                               // 214      m_preventionType
    //uint32    StanceBarOrder;                             // 215      m_stanceBarOrder not used
    float     EffectDamageMultiplier[MAX_SPELL_EFFECTS];    // 216-218  m_effectChainAmplitude
    //uint32    MinFactionId;                               // 219      m_minFactionID not used
    //uint32    MinReputation;                              // 220      m_minReputation not used
    //uint32    RequiredAuraVision;                         // 221      m_requiredAuraVision not used
    uint32    TotemCategory[2];                             // 222-223  m_requiredTotemCategoryID
    int32     AreaGroupId;                                  // 224      m_requiredAreaGroupId
    uint32    SchoolMask;                                   // 225      m_schoolMask
    uint32    runeCostID;                                   // 226      m_runeCostID
    //uint32    spellMissileID;                             // 227      m_spellMissileID not used
    //uint32  PowerDisplayId;                               // 228      PowerDisplay.dbc, new in 3.1
    float     EffectBonusMultiplier[MAX_SPELL_EFFECTS];     // 229-231  3.2.0
    //uint32  spellDescriptionVariableID;                   // 232      3.2.0
    //uint32  SpellDifficultyId;                            // 233      3.3.0
};

typedef std::set<uint32> PetFamilySpellsSet;
typedef std::map<uint32, PetFamilySpellsSet > PetFamilySpellsStore;

struct SpellCastTimesEntry
{
    uint32    ID;                                           // 0
    int32     CastTime;                                     // 1
    //float     CastTimePerLevel;                           // 2 unsure / per skill?
    //int32     MinCastTime;                                // 3 unsure
};

struct SpellCategoryEntry
{
    uint32 Id;
    uint32 Flags;
};

struct SpellDifficultyEntry
{
    uint32     ID;                                          // 0
    int32      SpellID[MAX_DIFFICULTY];                     // 1-4 instance modes: 10N, 25N, 10H, 25H or Normal/Heroic if only 1-2 is set, if 3-4 is 0 then Mode-2
};

struct SpellFocusObjectEntry
{
    uint32    ID;                                           // 0
    //char*     Name[16];                                   // 1-15 unused
                                                            // 16 string flags, unused
};

struct SpellRadiusEntry
{
    uint32    ID;
    float     RadiusMin;
    float     RadiusPerLevel;
    float     RadiusMax;
};

struct SpellRangeEntry
{
    uint32    ID;
    float     minRangeHostile;
    float     minRangeFriend;
    float     maxRangeHostile;
    float     maxRangeFriend;
    uint32    type;
    //char*     Name[16];                                   // 7-23 unused
                                                            // 24 string flags, unused
    //char*     Name2[16];                                  // 25-40 unused
                                                            // 41 string flags, unused
};

struct SpellRuneCostEntry
{
    uint32  ID;                                             // 0
    uint32  RuneCost[3];                                    // 1-3 (0=blood, 1=frost, 2=unholy)
    uint32  runePowerGain;                                  // 4

    bool NoRuneCost() const { return RuneCost[0] == 0 && RuneCost[1] == 0 && RuneCost[2] == 0; }
    bool NoRunicPowerGain() const { return runePowerGain == 0; }
};

#define MAX_SHAPESHIFT_SPELLS 8

struct SpellShapeshiftEntry
{
    uint32 ID;                                              // 0
    //uint32 buttonPosition;                                // 1 unused
    //char*  Name[16];                                      // 2-17 unused
    //uint32 NameFlags;                                     // 18 unused
    uint32 flags1;                                          // 19
    int32  creatureType;                                    // 20 <= 0 humanoid, other normal creature types
    //uint32 unk1;                                          // 21 unused
    uint32 attackSpeed;                                     // 22
    uint32 modelID_A;                                       // 23 alliance modelid
    uint32 modelID_H;                                       // 24 horde modelid (only one form)
    //uint32 unk3;                                          // 25 unused
    //uint32 unk4;                                          // 26 unused
    uint32 stanceSpell[MAX_SHAPESHIFT_SPELLS];                                  // 27 - 34 unused
};

struct SpellDurationEntry
{
    uint32    ID;
    int32     Duration[3];
};

struct SpellItemEnchantmentEntry
{
    uint32      ID;                                         // 0        m_ID
    //uint32      charges;                                  // 1        m_charges
    uint32      type[MAX_ITEM_ENCHANTMENT_EFFECTS];         // 2-4      m_effect[MAX_ITEM_ENCHANTMENT_EFFECTS]
    uint32      amount[MAX_ITEM_ENCHANTMENT_EFFECTS];       // 5-7      m_effectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS]
    //uint32      amount2[MAX_ITEM_ENCHANTMENT_EFFECTS]     // 8-10     m_effectPointsMax[MAX_ITEM_ENCHANTMENT_EFFECTS]
    uint32      spellid[MAX_ITEM_ENCHANTMENT_EFFECTS];      // 11-13    m_effectArg[MAX_ITEM_ENCHANTMENT_EFFECTS]
    char*       description[16];                            // 14-29    m_name_lang[16]
    //uint32      descriptionFlags;                         // 30 name flags
    uint32      aura_id;                                    // 31       m_itemVisual
    uint32      slot;                                       // 32       m_flags
    uint32      GemID;                                      // 33       m_src_itemID
    uint32      EnchantmentCondition;                       // 34       m_condition_id
    uint32      requiredSkill;                              // 35       m_requiredSkillID
    uint32      requiredSkillValue;                         // 36       m_requiredSkillRank
    uint32      requiredLevel;                              // 37       m_requiredLevel
};

struct SpellItemEnchantmentConditionEntry
{
    uint32  ID;                                             // 0        m_ID
    uint8   Color[5];                                       // 1-5      m_lt_operandType[5]
    //uint32  LT_Operand[5];                                // 6-10     m_lt_operand[5]
    uint8   Comparator[5];                                  // 11-15    m_operator[5]
    uint8   CompareColor[5];                                // 15-20    m_rt_operandType[5]
    uint32  Value[5];                                       // 21-25    m_rt_operand[5]
    //uint8   Logic[5]                                      // 25-30    m_logic[5]
};

struct StableSlotPricesEntry
{
    uint32 Slot;
    uint32 Price;
};

struct SummonPropertiesEntry
{
    uint32  Id;                                             // 0
    uint32  Category;                                       // 1, 0 - can't be controlled?, 1 - something guardian?, 2 - pet?, 3 - something controllable?, 4 - taxi/mount?
    uint32  Faction;                                        // 2, 14 rows > 0
    uint32  Type;                                           // 3, see enum
    uint32  Slot;                                           // 4, 0-6
    uint32  Flags;                                          // 5
};

#define MAX_TALENT_RANK 5
#define MAX_PET_TALENT_RANK 3                               // use in calculations, expected <= MAX_TALENT_RANK
#define MAX_TALENT_TABS 3

struct TalentEntry
{
    uint32    TalentID;                                     // 0
    uint32    TalentTab;                                    // 1 index in TalentTab.dbc (TalentTabEntry)
    uint32    Row;                                          // 2
    uint32    Col;                                          // 3
    uint32    RankID[MAX_TALENT_RANK];                      // 4-8
                                                            // 9-12 not used, always 0, maybe not used high ranks
    uint32    DependsOn;                                    // 13 index in Talent.dbc (TalentEntry)
                                                            // 14-15 not used
    uint32    DependsOnRank;                                // 16
                                                            // 17-18 not used
    //uint32  needAddInSpellBook;                           // 19  also need disable higest ranks on reset talent tree
    //uint32  unk2;                                         // 20, all 0
    //uint64  allowForPet;                                  // 21 its a 64 bit mask for pet 1<<m_categoryEnumID in CreatureFamily.dbc
};

struct TalentTabEntry
{
    uint32  TalentTabID;                                    // 0
    //char* name[16];                                       // 1-16, unused
    //uint32  nameFlags;                                    // 17, unused
    //unit32  spellicon;                                    // 18
                                                            // 19 not used
    uint32  ClassMask;                                      // 20
    uint32  petTalentMask;                                  // 21
    uint32  tabpage;                                        // 22
    //char* internalname;                                   // 23
};

struct TaxiNodesEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    char*     name[16];                                     // 5-21     m_Name_lang
                                                            // 22 string flags
    uint32    MountCreatureID[2];                           // 23-24    m_MountCreatureID[2]
};

struct TaxiPathEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    from;                                         // 1        m_FromTaxiNode
    uint32    to;                                           // 2        m_ToTaxiNode
    uint32    price;                                        // 3        m_Cost
};

struct TaxiPathNodeEntry
{
                                                            // 0  ID
    uint32    PathID;                                       // 1
    uint32    NodeIndex;                                    // 2
    uint32    MapID;                                        // 3
    float     LocX;                                         // 4
    float     LocY;                                         // 5
    float     LocZ;                                         // 6
    uint32    Flags;                                        // 7
    uint32    Delay;                                        // 8
    uint32    ArrivalEventID;                               // 9
    uint32    DepartureEventID;                             // 10
};

struct TeamContributionPointsEntry
{
    //uint32    entry;                                      // 0
    float     value;                                        // 1 (???)
};

struct TotemCategoryEntry
{
    uint32    ID;                                           // 0
    //char*   name[16];                                     // 1-16
                                                            // 17 string flags, unused
    uint32    categoryType;                                 // 18 (one for specialization)
    uint32    categoryMask;                                 // 19 (compatibility mask for same type: different for totems, compatible from high to low for rods)
};

struct TransportAnimationEntry
{
    //uint32  Id;
    uint32  TransportEntry;
    uint32  TimeSeg;
    float   X;
    float   Y;
    float   Z;
    //uint32  MovementId;
};

struct TransportRotationEntry
{
    //uint32  Id;
    uint32  TransportEntry;
    uint32  TimeSeg;
    float   X;
    float   Y;
    float   Z;
    float   W;
};

#define MAX_VEHICLE_SEATS 8

struct VehicleEntry
{
    uint32  m_ID;                                           // 0
    uint32  m_flags;                                        // 1
    float   m_turnSpeed;                                    // 2
    float   m_pitchSpeed;                                   // 3
    float   m_pitchMin;                                     // 4
    float   m_pitchMax;                                     // 5
    uint32  m_seatID[MAX_VEHICLE_SEATS];                    // 6-13
    float   m_mouseLookOffsetPitch;                         // 14
    float   m_cameraFadeDistScalarMin;                      // 15
    float   m_cameraFadeDistScalarMax;                      // 16
    float   m_cameraPitchOffset;                            // 17
    //int     m_powerType[3];                               //       removed in 3.1
    //int     m_powerToken[3];                              //       removed in 3.1
    float   m_facingLimitRight;                             // 18
    float   m_facingLimitLeft;                              // 19
    float   m_msslTrgtTurnLingering;                        // 20
    float   m_msslTrgtPitchLingering;                       // 21
    float   m_msslTrgtMouseLingering;                       // 22
    float   m_msslTrgtEndOpacity;                           // 23
    float   m_msslTrgtArcSpeed;                             // 24
    float   m_msslTrgtArcRepeat;                            // 25
    float   m_msslTrgtArcWidth;                             // 26
    float   m_msslTrgtImpactRadius[2];                      // 27-28
    char*   m_msslTrgtArcTexture;                           // 29
    char*   m_msslTrgtImpactTexture;                        // 30
    char*   m_msslTrgtImpactModel[2];                       // 31-32
    float   m_cameraYawOffset;                              // 33
    uint32  m_uiLocomotionType;                             // 34
    float   m_msslTrgtImpactTexRadius;                      // 35
    uint32  m_uiSeatIndicatorType;                          // 36
    uint32  m_powerDisplayId;                               // 37, new in 3.1
                                                            // 38, new in 3.1
                                                            // 39, new in 3.1
};

struct VehicleSeatEntry
{
    uint32  m_ID;                                           // 0
    uint32  m_flags;                                        // 1
    int32   m_attachmentID;                                 // 2
    float   m_attachmentOffsetX;                            // 3
    float   m_attachmentOffsetY;                            // 4
    float   m_attachmentOffsetZ;                            // 5
    float   m_enterPreDelay;                                // 6
    float   m_enterSpeed;                                   // 7
    float   m_enterGravity;                                 // 8
    float   m_enterMinDuration;                             // 9
    float   m_enterMaxDuration;                             // 10
    float   m_enterMinArcHeight;                            // 11
    float   m_enterMaxArcHeight;                            // 12
    int32   m_enterAnimStart;                               // 13
    int32   m_enterAnimLoop;                                // 14
    int32   m_rideAnimStart;                                // 15
    int32   m_rideAnimLoop;                                 // 16
    int32   m_rideUpperAnimStart;                           // 17
    int32   m_rideUpperAnimLoop;                            // 18
    float   m_exitPreDelay;                                 // 19
    float   m_exitSpeed;                                    // 20
    float   m_exitGravity;                                  // 21
    float   m_exitMinDuration;                              // 22
    float   m_exitMaxDuration;                              // 23
    float   m_exitMinArcHeight;                             // 24
    float   m_exitMaxArcHeight;                             // 25
    int32   m_exitAnimStart;                                // 26
    int32   m_exitAnimLoop;                                 // 27
    int32   m_exitAnimEnd;                                  // 28
    float   m_passengerYaw;                                 // 29
    float   m_passengerPitch;                               // 30
    float   m_passengerRoll;                                // 31
    int32   m_passengerAttachmentID;                        // 32
    int32   m_vehicleEnterAnim;                             // 33
    int32   m_vehicleExitAnim;                              // 34
    int32   m_vehicleRideAnimLoop;                          // 35
    int32   m_vehicleEnterAnimBone;                         // 36
    int32   m_vehicleExitAnimBone;                          // 37
    int32   m_vehicleRideAnimLoopBone;                      // 38
    float   m_vehicleEnterAnimDelay;                        // 39
    float   m_vehicleExitAnimDelay;                         // 40
    uint32  m_vehicleAbilityDisplay;                        // 41
    uint32  m_enterUISoundID;                               // 42
    uint32  m_exitUISoundID;                                // 43
    int32   m_uiSkin;                                       // 44
    uint32  m_flagsB;                                       // 45
                                                            // 46-57 added in 3.1, floats mostly

    bool CanEnterOrExit() const
    {
        return ((m_flags & VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT) != 0 ||
                //If it has anmation for enter/ride, means it can be entered/exited by logic
                (m_flags & (VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER | VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE)) != 0);
    }
    bool CanSwitchFromSeat() const { return (m_flags & VEHICLE_SEAT_FLAG_CAN_SWITCH) != 0; }
    bool IsUsableByOverride() const { return (m_flags & (VEHICLE_SEAT_FLAG_UNCONTROLLED | VEHICLE_SEAT_FLAG_UNK18)
                                    || (m_flagsB & (VEHICLE_SEAT_FLAG_B_USABLE_FORCED | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2 |
                                        VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3 | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4))); }
    bool IsEjectable() const { return (m_flagsB & VEHICLE_SEAT_FLAG_B_EJECTABLE) != 0; }
};

struct WMOAreaTableEntry
{
    uint32 Id;                                              // 0 index
    int32 rootId;                                           // 1 used in root WMO
    int32 adtId;                                            // 2 used in adt file
    int32 groupId;                                          // 3 used in group WMO
    //uint32 field4;
    //uint32 field5;
    //uint32 field6;
    //uint32 field7;
    //uint32 field8;
    uint32 Flags;                                           // 9 used for indoor/outdoor determination
    uint32 areaId;                                          // 10 link to AreaTableEntry.ID
    //char *Name[16];
    //uint32 nameFlags;
};

struct WorldMapAreaEntry
{
    //uint32  ID;                                           // 0
    uint32  map_id;                                         // 1
    uint32  area_id;                                        // 2 index (continent 0 areas ignored)
    //char* internal_name                                   // 3
    float   y1;                                             // 4
    float   y2;                                             // 5
    float   x1;                                             // 6
    float   x2;                                             // 7
    int32   virtual_map_id;                                 // 8 -1 (map_id have correct map) other: virtual map where zone show (map_id - where zone in fact internally)
    // int32   dungeonMap_id;                               // 9 pointer to DungeonMap.dbc (owerride x1, x2, y1, y2 coordinates)
    // uint32  parentMapID;                                 // 10
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32    ID;                                           // 0
    //uint32    worldMapAreaId;                             // 1 idx in WorldMapArea.dbc
    uint32    areatableID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];  // 2-5
                                                            // 6-7 always 0, possible part of areatableID[]
    //char* internal_name                                   // 8
                                                            // 9-16 some ints
};

struct WorldSafeLocsEntry
{
    uint32    ID;                                           // 0
    uint32    map_id;                                       // 1
    float     x;                                            // 2
    float     y;                                            // 3
    float     z;                                            // 4
    //char*   name[16]                                      // 5-20 name, unused
                                                            // 21 name flags, unused
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

// Structures not used for casting to loaded DBC data and not required then packing
struct MapDifficulty
{
    MapDifficulty() : resetTime(0), maxPlayers(0), hasErrorMessage(false) { }
    MapDifficulty(uint32 _resetTime, uint32 _maxPlayers, bool _hasErrorMessage) : resetTime(_resetTime), maxPlayers(_maxPlayers), hasErrorMessage(_hasErrorMessage) { }

    uint32 resetTime;
    uint32 maxPlayers;
    bool hasErrorMessage;
};

struct TalentSpellPos
{
    TalentSpellPos() : talent_id(0), rank(0) { }
    TalentSpellPos(uint16 _talent_id, uint8 _rank) : talent_id(_talent_id), rank(_rank) { }

    uint16 talent_id;
    uint8  rank;
};

typedef std::map<uint32, TalentSpellPos> TalentSpellPosMap;

struct TaxiPathBySourceAndDestination
{
    TaxiPathBySourceAndDestination() : ID(0), price(0) { }
    TaxiPathBySourceAndDestination(uint32 _id, uint32 _price) : ID(_id), price(_price) { }

    uint32    ID;
    uint32    price;
};
typedef std::map<uint32, TaxiPathBySourceAndDestination> TaxiPathSetForSource;
typedef std::map<uint32, TaxiPathSetForSource> TaxiPathSetBySource;

typedef std::vector<TaxiPathNodeEntry const*> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

#define TaxiMaskSize 14
typedef uint32 TaxiMask[TaxiMaskSize];
#endif

