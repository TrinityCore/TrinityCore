/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "Define.h"
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

struct DBCPosition2D
{
    float X;
    float Y;
};

struct DBCPosition3D
{
    float X;
    float Y;
    float Z;
};

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
    //uint32    CriteriaTree;                               // 14
};

struct AchievementCategoryEntry
{
    uint32      ID;                                         // 0
    uint32      Parent;                                     // 1 -1 for main category
    //char*     Name_lang;                                  // 2
    //uint32    UIOrder;                                    // 3
};

struct AchievementCriteriaEntry
{
    uint32  ID;                                             // 0
    uint32  achievement;                                    // 1
    uint32  type;                                           // 2
    union
    {
        // ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE          = 0
        /// @todo also used for player deaths..
        struct
        {
            uint32  creatureID;                             // 3
            uint64  creatureCount;                          // 4
        } kill_creature;

        // ACHIEVEMENT_CRITERIA_TYPE_WIN_BG                 = 1
        struct
        {
            uint32  bgMapID;                                // 3
            uint64  winCount;                               // 4
        } win_bg;

        // ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL            = 5
        // ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL      = 125
        struct
        {
            uint32  unused;                                 // 3
            uint64  level;                                  // 4
        } reach_level;

        // ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL      = 7
        struct
        {
            uint32  skillID;                                // 3
            uint64  skillLevel;                             // 4
        } reach_skill_level;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT   = 8
        struct
        {
            uint32  linkedAchievement;                      // 3
        } complete_achievement;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT   = 9
        struct
        {
            uint32  unused;                                 // 3
            uint64  totalQuestCount;                        // 4
        } complete_quest_count;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY = 10
        struct
        {
            uint32  unused;                                 // 3
            uint64  numberOfDays;                           // 4
        } complete_daily_quest_daily;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE = 11
        struct
        {
            uint32  zoneID;                                 // 3
            uint64  questCount;                             // 4
        } complete_quests_in_zone;

        // ACHIEVEMENT_CRITERIA_TYPE_CURRENCY = 12
        struct
        {
            uint32 currency;
            uint64 count;
        } currencyGain;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_DAILY_QUEST   = 14
        struct
        {
            uint32  unused;                                 // 3
            uint64  questCount;                             // 4
        } complete_daily_quest;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_BATTLEGROUND  = 15
        struct
        {
            uint32  mapID;                                  // 3
        } complete_battleground;

        // ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP           = 16
        struct
        {
            uint32  mapID;                                  // 3
        } death_at_map;

        // ACHIEVEMENT_CRITERIA_TYPE_DEATH_IN_DUNGEON       = 18
        struct
        {
            uint32  manLimit;                               // 3
        } death_in_dungeon;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_RAID          = 19
        struct
        {
            uint32  groupSize;                              // 3 can be 5, 10 or 25
        } complete_raid;

        // ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE     = 20
        struct
        {
            uint32  creatureEntry;                          // 3
        } killed_by_creature;

        // ACHIEVEMENT_CRITERIA_TYPE_FALL_WITHOUT_DYING     = 24
        struct
        {
            uint32  unused;                                 // 3
            uint64  fallHeight;                             // 4
        } fall_without_dying;

        // ACHIEVEMENT_CRITERIA_TYPE_DEATHS_FROM            = 26
        struct
        {
            uint32 type;                                    // 3, see enum EnviromentalDamage
        } death_from;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST         = 27
        struct
        {
            uint32  questID;                                // 3
            uint64  questCount;                             // 4
        } complete_quest;

        // ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET        = 28
        // ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2       = 69
        struct
        {
            uint32  spellID;                                // 3
            uint64  spellCount;                             // 4
        } be_spell_target;

        // ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL             = 29
        // ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2            = 110
        struct
        {
            uint32  spellID;                                // 3
            uint64  castCount;                              // 4
        } cast_spell;

        // ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE
        struct
        {
            uint32 objectiveId;                             // 3
            uint64 completeCount;                           // 4
        } bg_objective;

        // ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILL_AT_AREA = 31
        struct
        {
            uint32  areaID;                                 // 3 Reference to AreaTable.dbc
            uint64  killCount;                              // 4
        } honorable_kill_at_area;

        // ACHIEVEMENT_CRITERIA_TYPE_WIN_ARENA              = 32
        struct
        {
            uint32 mapID;                                   // 3 Reference to Map.dbc
            uint64 count;                                   // 4 Number of times that the arena must be won.
        } win_arena;

        // ACHIEVEMENT_CRITERIA_TYPE_PLAY_ARENA             = 33
        struct
        {
            uint32  mapID;                                  // 3 Reference to Map.dbc
        } play_arena;

        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SPELL            = 34
        struct
        {
            uint32  spellID;                                // 3 Reference to Map.dbc
        } learn_spell;

        // ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM               = 36
        struct
        {
            uint32  itemID;                                 // 3
            uint64  itemCount;                              // 4
        } own_item;

        // ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA        = 37
        struct
        {
            uint32  unused;                                 // 3
            uint64  count;                                  // 4
        } win_rated_arena;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_TEAM_RATING    = 38
        struct
        {
            uint32  teamtype;                               // 3 {2, 3, 5}
        } highest_team_rating;

        // ACHIEVEMENT_CRITERIA_TYPE_REACH_TEAM_RATING      = 39
        struct
        {
            uint32  teamtype;                               // 3 {2, 3, 5}
            uint64  teamrating;                             // 4
        } reach_team_rating;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_PERSONAL_RATING = 39
        struct
        {
            uint32 teamtype; // 3 {2, 3, 5}
            uint64 PersonalRating; // 4
        } highest_personal_rating;

        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LEVEL      = 40
        struct
        {
            uint32  skillID;                                // 3
            uint64  skillLevel;                             // 4 apprentice=1, journeyman=2, expert=3, artisan=4, master=5, grand master=6
        } learn_skill_level;

        // ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM               = 41
        struct
        {
            uint32  itemID;                                 // 3
            uint64  itemCount;                              // 4
        } use_item;

        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM              = 42
        struct
        {
            uint32  itemID;                                 // 3
            uint64  itemCount;                              // 4
        } loot_item;

        // ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA           = 43
        struct
        {
            /// @todo This rank is _NOT_ the index from AreaTable.dbc
            uint32  areaReference;                          // 3
        } explore_area;

        // ACHIEVEMENT_CRITERIA_TYPE_OWN_RANK               = 44
        struct
        {
            /// @todo This rank is _NOT_ the index from CharTitles.dbc
            uint32  rank;                                   // 3
        } own_rank;

        // ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT          = 45
        struct
        {
            uint32  unused;                                 // 3
            uint64  numberOfSlots;                          // 4
        } buy_bank_slot;

        // ACHIEVEMENT_CRITERIA_TYPE_GAIN_REPUTATION        = 46
        struct
        {
            uint32  factionID;                              // 3
            uint64  reputationAmount;                       // 4 Total reputation amount, so 42000 = exalted
        } gain_reputation;

        // ACHIEVEMENT_CRITERIA_TYPE_GAIN_EXALTED_REPUTATION= 47
        struct
        {
            uint32  unused;                                 // 3
            uint64  numberOfExaltedFactions;                // 4
        } gain_exalted_reputation;

        // ACHIEVEMENT_CRITERIA_TYPE_VISIT_BARBER_SHOP      = 48
        struct
        {
            uint32 unused;                                  // 3
            uint64 numberOfVisits;                          // 4
        } visit_barber;

        // ACHIEVEMENT_CRITERIA_TYPE_EQUIP_EPIC_ITEM        = 49
        /// @todo where is the required itemlevel stored?
        struct
        {
            uint32  itemSlot;                               // 3
            uint64  count;                                  // 4
        } equip_epic_item;

        // ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED_ON_LOOT      = 50
        struct
        {
            uint32  rollValue;                              // 3
            uint64  count;                                  // 4
        } roll_need_on_loot;
       // ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED_ON_LOOT      = 51
        struct
        {
            uint32  rollValue;                              // 3
            uint64  count;                                  // 4
        } roll_greed_on_loot;

        // ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS               = 52
        struct
        {
            uint32  classID;                                // 3
            uint64  count;                                  // 4
        } hk_class;

        // ACHIEVEMENT_CRITERIA_TYPE_HK_RACE                = 53
        struct
        {
            uint32  raceID;                                 // 3
            uint64  count;                                  // 4
        } hk_race;

        // ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE               = 54
        /// @todo where is the information about the target stored?
        struct
        {
            uint32  emoteID;                                // 3 enum TextEmotes
            uint64  count;                                  // 4 count of emotes, always required special target or requirements
        } do_emote;
        // ACHIEVEMENT_CRITERIA_TYPE_DAMAGE_DONE            = 13
        // ACHIEVEMENT_CRITERIA_TYPE_HEALING_DONE           = 55
        // ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS      = 56
        struct
        {
            uint32  unused;                                 // 3
            uint64  count;                                  // 4
        } healing_done;

        // ACHIEVEMENT_CRITERIA_TYPE_GET_KILLING_BLOWS      = 56
        struct
        {
            uint32  unused;
            uint64  killCount;
        } get_killing_blow;

        // ACHIEVEMENT_CRITERIA_TYPE_EQUIP_ITEM             = 57
        struct
        {
            uint32  itemID;                                 // 3
            uint64  count;                                  // 4
        } equip_item;

        // ACHIEVEMENT_CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD= 62
        struct
        {
            uint32  unused;                                 // 3
            uint64  goldInCopper;                           // 4
        } quest_reward_money;

        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_MONEY             = 67
        struct
        {
            uint32  unused;                                 // 3
            uint64  goldInCopper;                           // 4
        } loot_money;

        // ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT         = 68
        struct
        {
            uint32  goEntry;                                // 3
            uint64  useCount;                               // 4
        } use_gameobject;

        // ACHIEVEMENT_CRITERIA_TYPE_SPECIAL_PVP_KILL       = 70
        /// @todo are those special criteria stored in the dbc or do we have to add another sql table?
        struct
        {
            uint32  unused;                                 // 3
            uint64  killCount;                              // 4
        } special_pvp_kill;

        // ACHIEVEMENT_CRITERIA_TYPE_FISH_IN_GAMEOBJECT     = 72
        struct
        {
            uint32  goEntry;                                // 3
            uint64  lootCount;                              // 4
        } fish_in_gameobject;

        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS = 75
        struct
        {
            uint32  skillLine;                              // 3
            uint64  spellCount;                             // 4
        } learn_skillline_spell;

        // ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL               = 76
        struct
        {
            uint32  unused;                                 // 3
            uint64  duelCount;                              // 4
        } win_duel;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_POWER          = 96
        struct
        {
            uint32  powerType;                              // 3 mana=0, 1=rage, 3=energy, 6=runic power
        } highest_power;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_STAT           = 97
        struct
        {
            uint32  statType;                               // 3 4=spirit, 3=int, 2=stamina, 1=agi, 0=strength
        } highest_stat;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_SPELLPOWER     = 98
        struct
        {
            uint32  spellSchool;                            // 3
        } highest_spellpower;

        // ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_RATING         = 100
        struct
        {
            uint32  ratingType;                             // 3
        } highest_rating;

        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_TYPE              = 109
        struct
        {
            uint32  lootType;                               // 3 3=fishing, 2=pickpocket, 4=disentchant
            uint64  lootTypeCount;                          // 4
        } loot_type;

        // ACHIEVEMENT_CRITERIA_TYPE_LEARN_SKILL_LINE       = 112
        struct
        {
            uint32  skillLine;                              // 3
            uint64  spellCount;                             // 4
        } learn_skill_line;

        // ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL    = 113
        struct
        {
            uint32  unused;                                 // 3
            uint64  killCount;                              // 4
        } honorable_kill;

        struct
        {
            uint32  unused;
            uint64  dungeonsComplete;
        } use_lfg;

        struct
        {
            uint32  field3;                                 // 3 main requirement
            uint64  count;                                  // 4 main requirement count
        } raw;
    };

    struct
    {
        uint32  additionalRequirement_type;
        uint32  additionalRequirement_value;
    } additionalRequirements[MAX_CRITERIA_REQUIREMENTS];

    char*  name;                                            // 9        m_description_lang
    uint32  completionFlag;                                 // 10       m_flags
    uint32  timedCriteriaStartType;                         // 11       m_timer_start_event Only appears with timed achievements, seems to be the type of starting a timed Achievement, only type 1 and some of type 6 need manual starting
                                                            //              1: ByEventId(?) (serverside IDs),    2: ByQuestId,   5: ByCastSpellId(?)
                                                            //              6: BySpellIdTarget(some of these are unknown spells, some not, some maybe spells)
                                                            //              7: ByKillNpcId,  9: ByUseItemId
    uint32  timedCriteriaMiscId;                            // 12       m_timer_asset_id Alway appears with timed events, used internally to start the achievement, store
    uint32  timeLimit;                                      // 13       m_timer_time time limit in seconds
    uint32  showOrder;                                      // 14       m_ui_order  also used in achievement shift-links as index in state bitmask
    //uint32 unk1;                                          // 15 only one value, still unknown
    //uint32 unk2;                                          // 16 all zeros
    uint32 additionalConditionType[MAX_ADDITIONAL_CRITERIA_CONDITIONS];     // 17-19
    uint32 additionalConditionValue[MAX_ADDITIONAL_CRITERIA_CONDITIONS];    // 20-22
};

struct AreaTableEntry
{
    uint32  ID;                                             // 0
    uint32  mapid;                                          // 1
    uint32  zone;                                           // 2 if 0 then it's zone, else it's zone id of this area
    uint32  exploreFlag;                                    // 3, main index
    uint32  flags;                                          // 4,
    //uint32 unk5;                                          // 5,
    //uint32 unk6;                                          // 6,
    //uint32 unk7;                                          // 7,
    //uint32 unk8;                                          // 8,
    //uint32 unk9;                                          // 9,
    int32   area_level;                                     // 10
    char*   area_name;                                      // 11
    uint32  team;                                           // 12
    uint32  LiquidTypeOverride[4];                          // 13-16 liquid override by type
    float   MaxDepth;                                       // 17,
    float   AmbientMultiplier;                              // 18 client only?
    uint32  LightId;                                        // 19
    //uint32 unk20;                                         // 20 4.0.0 - Mounting related
    //uint32 unk21;                                         // 21 4.0.0
    //uint32 unk22;                                         // 22 4.0.0
    //uint32 unk23;                                         // 23 4.0.0
    //uint32 unk24;                                         // 24 - worldStateId
    //uint32 unk25                                          // 25

    // helpers
    bool IsSanctuary() const
    {
        if (mapid == 609)
            return true;
        return (flags & AREA_FLAG_SANCTUARY) != 0;
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
    uint32      MapID[16];                                  // 1-16 mapid
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
    //int32     ItemDisplayID[MAX_OUTFIT_ITEMS];            // 29-52 not required at server side
    //int32     InventoryType[MAX_OUTFIT_ITEMS];            // 53-76 not required at server side
    uint32      PetDisplayID;                               // 77 Pet Model ID for starting pet
    uint32      PetFamilyID;                                // 78 Pet Family Entry for starting pet
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
    //uint32    Gender;                                     // 19
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
    //char*     FileName;                                   // 20
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

// All Gt* DBC store data for 100 levels, some by 100 per class/race
#define GT_MAX_LEVEL    100
// gtOCTClassCombatRatingScalar.dbc stores data for 32 ratings, look at MAX_COMBAT_RATING for real used amount
#define GT_MAX_RATING   32

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

/* no used
struct HolidayDescriptionsEntry
{
    uint32 ID;                                              // 0, m_holidayDescriptionID
    //char*     name                                        // 1  m_name_lang
};
*/

/* no used
struct HolidayNamesEntry
{
    uint32 ID;                                              // 0, m_holidayNameID
    //char*     name                                        // 1  m_name_lang
};
*/

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 26
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32      ID;                                         // 0        m_ID
    uint32      Duration[MAX_HOLIDAY_DURATIONS];            // 1-10     m_duration
    uint32      Date[MAX_HOLIDAY_DATES];                    // 11-36    m_date (dates in unix time starting at January, 1, 2000)
    uint32      Region;                                     // 37       m_region (wow region)
    uint32      Looping;                                    // 38       m_looping
    uint32      CalendarFlags[MAX_HOLIDAY_FLAGS];           // 39-48    m_calendarFlags
    //uint32    HolidayNameID;                              // 49       m_holidayNameID (HolidayNames.dbc)
    //uint32    HolidayDescriptionID;                       // 50       m_holidayDescriptionID (HolidayDescriptions.dbc)
    char*       TextureFilename;                            // 51       m_textureFilename
    uint32      Priority;                                   // 52       m_priority
    uint32      CalendarFilterType;                         // 53       m_calendarFilterType (-1 = Fishing Contest, 0 = Unk, 1 = Darkmoon Festival, 2 = Yearly holiday)
    //uint32    Flags;                                      // 54       m_flags (0 = Darkmoon Faire, Fishing Contest and Wotlk Launch, rest is 1)
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

// 6.x - removeme
struct ItemReforgeEntry
{
    uint32 Id;
    uint32 SourceStat;
    float SourceMultiplier;
    uint32 FinalStat;
    float FinalMultiplier;
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

#define MAX_ITEM_ENCHANTMENT_EFFECTS 5

struct ItemRandomPropertiesEntry
{
    uint32      ID;                                         // 0
    //char*     Name;                                       // 1
    uint32      Enchantment[MAX_ITEM_ENCHANTMENT_EFFECTS];  // 2-6 
    char*       Name_lang;                                  // 7
};

struct ItemRandomSuffixEntry
{
    uint32      ID;                                         // 0 
    char*       Name_lang;                                  // 1
    //char*     InternalName;                               // 2
    uint32      Enchantment[MAX_ITEM_ENCHANTMENT_EFFECTS];  // 3-7
    uint32      AllocationPct[MAX_ITEM_ENCHANTMENT_EFFECTS];// 8-12
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
    char*       Name;                                       // 1
    uint32      Flaga;                                      // 2
};

struct PhaseGroupEntry
{
    uint32      ID;
    uint32      PhaseID;
    uint32      PhaseGroupID;
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
    //char*     LockID;                                     // 6
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

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32      ID;                                         // 0
    uint32      SpellID[MAX_OVERRIDE_SPELL];                // 1-10
    //uint32    Flags;                                      // 11
    //char*     PlayerActionbarFileDataID;                  // 12
};

struct PowerDisplayEntry
{
    uint32      ID;                                         // 0
    uint32      PowerType;                                  // 1
    //char*     GlobalStringBaseTag;                        // 2
    //uint8     Red;                                        // 3
    //uint8     Green;                                      // 3
    //uint8     Blue;                                       // 3
    //uint8     _padding0;                                  // 3
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
    int32       StatID[10];                                 // 1-10
    uint32      Modifier[10];                               // 11-20
    //uint32    MinLevel;                                   // 21
    uint32      MaxLevel;                                   // 22       m_maxlevel
};

struct ScalingStatValuesEntry
{
    uint32      ID;                                         // 0
    uint32      CharLevel;                                  // 1
    uint32      DPSMod[6];                                  // 2-7 DPS mod for level
    uint32      SpellPower;                                 // 8 spell power for level
    uint32      StatMultiplier[5];                          // 9-13 Multiplier for ScalingStatDistribution
    uint32      Armor[8][4];                                // 14-46 Armor for level
    uint32      ArmorBack;                                  // 47
    uint32      ArmorShield;                                // 48

    uint32 GetStatMultiplier(uint32 inventoryType) const;
    uint32 GetArmor(uint32 inventoryType, uint32 armorType) const;
    uint32 GetDPSAndDamageMultiplier(uint32 subClass, bool isCasterWeapon, float* damageMultiplier) const;
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

#define MAX_SPELL_EFFECTS 3
#define MAX_EFFECT_MASK 7

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

// SpellCastingRequirements.dbc
struct SpellCastingRequirementsEntry
{
    //uint32    ID;                                         // 0
    uint32      FacingCasterFlags;                          // 1
    //uint32    MinFactionID;                               // 1
    //uint32    MinReputation;                              // 3
    uint32      RequiredAreasID;                            // 4
    //uint32    RequiredAuraVision;                         // 5
    uint32      RequiresSpellFocus;                         // 6
};

#define MAX_SPELL_TOTEMS            2

// SpellTotems.dbc
struct SpellTotemsEntry
{
    uint32      ID;                                         // 0        m_ID
    uint32      TotemCategory[MAX_SPELL_TOTEMS];            // 1        m_requiredTotemCategoryID
    uint32      Totem[MAX_SPELL_TOTEMS];                    // 2        m_totem
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
    float       EffectScalingPoints[MAX_ITEM_ENCHANTMENT_EFFECTS];//23
};

struct SpellItemEnchantmentConditionEntry
{
    uint32      ID;                                             // 0
    uint8       LTOperandType[5];                               // 1-2
    //uint8     Padding[3];                                     // 1-2
    uint32      LTOperand[5];                                   // 2-6
    uint8       Operator[5];                                    // 7-8
    uint8       RTOperandType[5];                               // 8-9
    //uint8     Padding[2];                                     // 9
    uint32      RTOperand[5];                                   // 10-14
    uint8       Logic[5];                                       // 15-16
    //uint8     Padding[3];                                     // 16

    /*uint32  ID;                                             // 0        m_ID
    uint8   Color[5];                                       // 1-5      m_lt_operandType[5]
    //uint32  LT_Operand[5];                                // 6-10     m_lt_operand[5]
    uint8   Comparator[5];                                  // 11-15    m_operator[5]
    uint8   CompareColor[5];                                // 15-20    m_rt_operandType[5]
    uint32  Value[5];                                       // 21-25    m_rt_operand[5]
    //uint8   Logic[5]                                      // 25-30    m_logic[5]*/
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
    int32   Slot;                                           // 4, 0-6
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
    uint32    DependsOn;                                    // 9        m_prereqTalent (Talent.dbc)
                                                            // 10-11 part of prev field
    uint32    DependsOnRank;                                // 12       m_prereqRank
                                                            // 13-14 part of prev field
    //uint32  needAddInSpellBook;                           // 15       m_flags also need disable higest ranks on reset talent tree
    //uint32  unk2;                                         // 16       m_requiredSpellID
    //uint64  allowForPet;                                  // 17       m_categoryMask its a 64 bit mask for pet 1<<m_categoryEnumID in CreatureFamily.dbc
};

#define MAX_MASTERY_SPELLS 2

struct TalentTabEntry
{
    uint32  TalentTabID;                                    // 0
    //char* name;                                           // 1        m_name_lang
    //unit32  spellicon;                                    // 2        m_spellIconID
    uint32  ClassMask;                                      // 3        m_classMask
    uint32  petTalentMask;                                  // 4        m_petTalentMask
    uint32  tabpage;                                        // 5        m_orderIndex
    //char* internalname;                                   // 6        m_backgroundFile
    //char* description;                                    // 7
    //uint32 rolesMask;                                     // 8 4.0.0
    uint32 MasterySpellId[MAX_MASTERY_SPELLS];              // 9-10 passive mastery bonus spells?
};

struct TalentTreePrimarySpellsEntry
{
    //uint32 Id;                                            // 0 index
    uint32 TalentTree;                                      // 1 entry from TalentTab.dbc
    uint32 SpellId;                                         // 2 spell id to learn
    //uint32 Flags;                                         // 3 some kind of flags
};

struct TaxiNodesEntry
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    char* name;                                             // 5        m_Name_lang
    uint32    MountCreatureID[2];                           // 6-7      m_MountCreatureID[2]
    uint32    Flags;                                        // 8        m_Flags
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
                                                            // 0        m_ID
    uint32    path;                                         // 1        m_PathID
    uint32    index;                                        // 2        m_NodeIndex
    uint32    mapid;                                        // 3        m_ContinentID
    float     x;                                            // 4        m_LocX
    float     y;                                            // 5        m_LocY
    float     z;                                            // 6        m_LocZ
    uint32    actionFlag;                                   // 7        m_flags
    uint32    delay;                                        // 8        m_delay
    uint32    arrivalEventID;                               // 9        m_arrivalEventID
    uint32    departureEventID;                             // 10       m_departureEventID
};

struct TotemCategoryEntry
{
    uint32    ID;                                           // 0
    //char*   name;                                         // 1        m_name_lang
    uint32    categoryType;                                 // 2        m_totemCategoryType (one for specialization)
    uint32    categoryMask;                                 // 3        m_totemCategoryMask (compatibility mask for same type: different for totems, compatible from high to low for rods)
};

struct UnitPowerBarEntry
{
    uint32  Id;
    uint32  MinPower;
    uint32  MaxPower;
    //uint32  Unk0;
    //uint32  Unk1;
    //float   Unk2;
    //float   Unk3;
    //uint32  BarType;
    //uint32  TextureFile[6];
    //uint32  Unk4[6];
    //uint32  DisplayFlags;
    //char*   PowerName;
    //char*   CostString;
    //char*   EmptyMessage;
    //char*   Tooltip;
    //float   StartInset;
    //float   EndInset;
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
    char* m_msslTrgtArcTexture;                             // 29
    char* m_msslTrgtImpactTexture;                          // 30
    char* m_msslTrgtImpactModel[2];                         // 31-32
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

    bool CanEnterOrExit() const { return (m_flags & VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT) != 0; }
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
    //char *Name;                                           // 11       m_AreaName_lang
    //uint32 field12;                                       // 12
    //uint32 field13;                                       // 13
    //uint32 field14;                                       // 14
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

    // uint32  minRecommendedLevel;                         // 12 Minimum recommended level displayed on world map
    // uint32  maxRecommendedLevel;                         // 13 Maximum recommended level displayed on world map
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32    ID;                                           // 0
    //uint32    worldMapAreaId;                             // 1 idx in WorldMapArea.dbc
    uint32    areatableID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];  // 2-5
    //char* internal_name                                   // 6        m_textureName
                                                            // 7        m_textureWidth
                                                            // 8        m_textureHeight
                                                            // 9        m_offsetX
                                                            // 10       m_offsetY
                                                            // 11       m_hitRectTop
                                                            // 12       m_hitRectLeft
                                                            // 13       m_hitRectBottom
                                                            // 14       m_hitRectRight
};

struct WorldSafeLocsEntry
{
    uint32    ID;                                           // 0
    uint32    map_id;                                       // 1
    float     x;                                            // 2
    float     y;                                            // 3
    float     z;                                            // 4
    float     Facing;                                       // 5 values are in degrees
    //char*   name;                                         // 6        m_AreaName_lang
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
    std::vector<std::string> stringVectorArray[2];
};

typedef std::map<uint32, VectorArray> NameGenVectorArraysMap;

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

struct TaxiPathNodePtr
{
    TaxiPathNodePtr() : i_ptr(NULL) { }
    TaxiPathNodePtr(TaxiPathNodeEntry const* ptr) : i_ptr(ptr) { }
    TaxiPathNodeEntry const* i_ptr;
    operator TaxiPathNodeEntry const& () const { return *i_ptr; }
};

typedef Path<TaxiPathNodePtr, TaxiPathNodeEntry const> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

#define TaxiMaskSize 114
typedef uint8 TaxiMask[TaxiMaskSize];

typedef std::unordered_map<uint32, std::set<uint32>> PhaseGroupContainer;
#endif
