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

#ifndef TRINITY_DBCSTRUCTURE_H
#define TRINITY_DBCSTRUCTURE_H

#include "Define.h"
#include "DBCEnums.h"
#include "SharedDefines.h"
#include "Util.h"
#include <set>
#include <map>
#include <unordered_map>

// Structures using to access raw DBC data and required packing to portability
#pragma pack(push, 1)

struct AchievementEntry
{
    uint32 ID;                                              // 0
    int32  Faction;                                         // 1 -1=all, 0=horde, 1=alliance
    int32  Instance_ID;                                     // 2 -1=none
    //uint32 Supercedes;                                    // 3 its Achievement parent (can`t start while parent uncomplete, use its Criteria if don`t have own, use its progress on begin)
    char* Title;                                            // 4
    //char* Description;                                    // 5
    uint32  Category;                                       // 6
    uint32  Points;                                         // 7 reward points
    //uint32 Ui_order;                                      // 8
    uint32  Flags;                                          // 9
    //uint32 IconID;                                        // 10 icon (from SpellIcon.dbc)
    //char* Reward;                                         // 11
    uint32 Minimum_criteria;                                // 12 - need this count of completed criterias (own or referenced achievement criterias)
    uint32 Shares_criteria;                                 // 13 - referenced achievement (counting of all completed criterias)
};

struct AchievementCategoryEntry
{
    uint32  ID;                                             // 0
    uint32  Parent;                                         // 1 -1 for main category
    //char* Name;                                           // 2
    //uint32  Ui_order;                                     // 3
};

struct AchievementCriteriaEntry
{
    uint32  ID;                                             // 0
    uint32  Achievement_ID;                                 // 1
    uint32  Type;                                           // 2
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

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS = 3
        struct
        {
            uint32 unused;                                 // 3
            uint32 count;                                  // 4
        } archaeology;

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

        // ACHIEVEMENT_CRITERIA_TYPE_LOOT_EPIC_ITEM         = 90
        struct
        {
            uint32  unused;                                 // 3
            uint32  count;                                  // 4
        } loot_epic_item;

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

        // ACHIEVEMENT_CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS = 124
        struct
        {
            uint32 unused;
            uint32 goldCount;
        } spent_gold_guild_repairs;

        // ACHIEVEMENT_CRITERIA_TYPE_REACH_GUILD_LEVEL    = 125
        struct
        {
            uint32 unused;
            uint32  level;
        } reach_guild_level;

        // ACHIEVEMENT_CRITERIA_TYPE_CRAFT_ITEMS_GUILD = 126
        struct
        {
            uint32 unused;
            uint32 itemsCount;
        } craft_items_guild;

        // ACHIEVEMENT_CRITERIA_TYPE_CATCH_FROM_POOL = 127
        struct
        {
            uint32 unused;
            uint32 catchCount;
        } catch_from_pool;

        // ACHIEVEMENT_CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS = 128
        struct
        {
            uint32 unused;
            uint32 slotsCount;
        } buy_guild_bank_slots;

        // ACHIEVEMENT_CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS = 129
        struct
        {
            uint32 unused;
            uint32  pointsCount;
        } earn_guild_achievement_points;

        // ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_BATTLEGROUND = 130
        struct
        {
            uint32 unused;
            uint32 winCount;
        } win_rated_battleground;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_GUILD = 134
        struct
        {
            uint32 unused;
            uint32 questCount;
        } complete_quests_guild;

        // ACHIEVEMENT_CRITERIA_TYPE_HONORABLE_KILLS_GUILD = 135
        struct
        {
            uint32 unused;
            uint32 killCount;
        } honorable_kills_guild;

        // ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD = 136
        struct
        {
            uint32 unused;
            uint32 count;
        } kill_creature_type_guild;

        // ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGE_TYPE = 138
        struct
        {
            uint32 flag;         // 1: Guild Dungeon, 2:Guild raid, 3:Guild battleground
            uint32 count;
        } guild_challenge;

        struct
        {
            uint32 unused;       // 3
            uint32 goldInCopper; // 4
        } guild_gold_repairs;

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

    char* Description;                                      // 9
    uint32  Flags;                                          // 10
    uint32  Timer_start_event;                              // 11 Only appears with timed achievements, seems to be the type of starting a timed Achievement, only type 1 and some of type 6 need manual starting
                                                            //              1: ByEventId(?) (serverside IDs),    2: ByQuestId,   5: ByCastSpellId(?)
                                                            //              6: BySpellIdTarget(some of these are unknown spells, some not, some maybe spells)
                                                            //              7: ByKillNpcId,  9: ByUseItemId
    uint32  Timer_asset_ID;                                 // 12 Alway appears with timed events, used internally to start the achievement, store
    uint32  Timer_time;                                     // 13 time limit in seconds
    uint32  Ui_order;                                       // 14 also used in achievement shift-links as index in state bitmask
    //uint32 unk1;                                          // 15 only one value, still unknown
    //uint32 unk2;                                          // 16 all zeros
    uint32 AdditionalConditionType[MAX_ADDITIONAL_CRITERIA_CONDITIONS];  // 17-19
    uint32 AdditionalConditionValue[MAX_ADDITIONAL_CRITERIA_CONDITIONS]; // 20-22
};

struct AnimKitEntry
{
    uint32  ID;                                             // 0
    //uint32  OneShotDuration;                              // 1
    //uint32  OneShotStopAnimKitID;                         // 2
};

struct AreaTableEntry
{
    uint32 ID;                                              // 0
    uint32 ContinentID;                                     // 1
    uint32 ParentAreaID;                                    // 2 if 0 then it's zone, else it's zone id of this area
    uint32 AreaBit;                                         // 3
    uint32 Flags;                                           // 4
    uint32 SoundProviderPref;                               // 5
    uint32 SoundProviderPrefUnderwater;                     // 6
    uint32 AmbienceID;                                      // 7
    uint32 ZoneMusic;                                       // 8
    uint32 IntroSound;                                      // 9
    uint32 ExplorationLevel;                                // 10
    char const* AreaName;                                   // 11
    uint32 FactionGroupMask;                                // 12
    uint32 LiquidTypeID[4];                                 // 13-16 liquid override by type
    float MinElevation;                                     // 17
    float AmbientMultiplier;                                // 18 client only?
    uint32 LightID;                                         // 19
    uint32 MountFlags;                                      // 20
    uint32 UwIntroSound;                                    // 21 4.0.0
    uint32 UwZoneMusic;                                     // 22 4.0.0
    uint32 UwAmbience;                                      // 23 4.0.0
    uint32 World_pvp_ID;                                    // 24
    int32 PvpCombatWorldStateID;                            // 25- worldStateId

    // helpers
    bool IsSanctuary() const
    {
        if (ContinentID == 609)
            return true;
        return (Flags & AREA_FLAG_SANCTUARY) != 0;
    }

    bool IsFlyable() const
    {
        if (Flags & AREA_FLAG_OUTLAND)
        {
            if (!(Flags & AREA_FLAG_NO_FLY_ZONE))
                return true;
        }

        return false;
    }
};

#define MAX_GROUP_AREA_IDS 6

struct AreaGroupEntry
{
    uint32  ID;                                             // 0
    uint32  AreaID[MAX_GROUP_AREA_IDS];                     // 1-6
    uint32  NextAreaID;                                     // 7 index of next group
};

struct AreaPOIEntry
{
    uint32 ID;                                              // 0
    // uint32 Importance                                    // 1
    uint32 Icon[9];                                         // 2-10
    // uint32 FactionID                                     // 11
    DBCPosition2D Pos;                                      // 12 - 13
    uint32 ContinentID;                                     // 14
    // uint32 Flags;                                        // 15
    uint32 AreaID;                                          // 16
    //char* Name;                                           // 17
    //char* Description;                                    // 18
    uint32 WorldStateID;                                    // 19
    //uint32 WorldMapLink;                                  // 20
    //uint32 PortLocID;                                     // 21
};

struct AreaTriggerEntry
{
    uint32          ID;                                     // 0
    uint32          ContinentID;                            // 1
    DBCPosition3D   Pos;                                    // 2 - 4
    uint32          PhaseUseFlags;                          // 5
    uint32          PhaseID;                                // 6
    uint32          PhaseGroupID;                           // 7
    float           Radius;                                 // 8
    float           Box_length;                             // 9
    float           Box_width;                              // 10
    float           Box_height;                             // 11
    float           Box_yaw;                                // 12
};

struct ArmorLocationEntry
{
  uint32 ID;                                                // 0
  float  Value[5];                                          // 1-5 multiplier for armor types (cloth...plate, no armor?)
};

struct AuctionHouseEntry
{
    uint32  ID;                                             // 0 index
    uint32  FactionID;                                      // 1 id of faction.dbc for player factions associated with city
    uint32  DepositRate;                                    // 2 1/3 from real
    uint32  ConsignmentRate;                                // 3
    //char* Name;                                           // 4
};

struct BankBagSlotPricesEntry
{
    uint32  ID;                                             // 0
    uint32  Cost;                                           // 1
};

struct BannedAddOnsEntry
{
    uint32 ID;                                              // 0
    // uint32 NameMD5[4];                                   // 1 - 4
    // uint32 VersionMD5[4];                                // 5 - 8
    // uint32 LastModified;                                 // 9
    // uint32 Flags;                                        // 10
};

struct BarberShopStyleEntry
{
    uint32  ID;                                             // 0
    uint32  Type;                                           // 1 value 0 -> hair, value 2 -> facialhair
    //char*   DisplayName;                                  // 2
    //uint32  Description;                                  // 3
    //float   Cost_Modifier;                                // 4
    uint32  Race;                                           // 5
    uint32  Sex;                                            // 6
    uint32  Data;                                           // 7
};

struct BattlemasterListEntry
{
    uint32  ID;                                             // 0
    int32   MapID[8];                                       // 1-8
    uint32  InstanceType;                                   // 9 map type (3 - BG, 4 - arena)
    //uint32 GroupsAllowed;                                 // 10 (0 or 1)
    char* Name;                                             // 11
    uint32  MaxGroupSize;                                   // 12 maxGroupSize, used for checking if queue as group
    uint32  HolidayWorldState;                              // 13 new 3.1
    uint32  MinLevel;                                       // 14, min level (sync with PvPDifficulty.dbc content)
    uint32  MaxLevel;                                       // 15, max level (sync with PvPDifficulty.dbc content)
    //uint32  RatedPlayers;                                 // 16 4.0.1
    //uint32  MinPlayers;                                   // 17 - 4.0.6.13596
    //uint32  MaxPlayers;                                   // 18 4.0.1
    //uint32  Flags;                                        // 19 4.0.3, value 2 for Rated Battlegrounds
};

#define MAX_OUTFIT_ITEMS 24

struct CharStartOutfitEntry
{
    //uint32  ID;                                           // 0
    uint8  RaceID;                                          // 1
    uint8  ClassID;                                         // 2
    uint8  SexID;                                           // 3
    //uint8  OutfitID;                                      // 4
    int32  ItemID[MAX_OUTFIT_ITEMS];                        // 5-28
    //int32  DisplayItemID[MAX_OUTFIT_ITEMS];               // 29-52 not required at server side
    //int32  InventoryType[MAX_OUTFIT_ITEMS];               // 53-76 not required at server side
    uint32  PetDisplayID;                                   // 77 Pet Model ID for starting pet
    uint32  PetFamilyID;                                    // 78 Pet Family Entry for starting pet
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
    //uint32 ID                                             // 0
    uint32 RaceID;                                          // 1
    uint32 SexID;                                           // 2
    uint32 BaseSection;                                     // 3
    //char* TextureName[3];                                 // 4 - 7
    uint32 Flags;                                           // 8
    uint32 VariationIndex;                                  // 9
    uint32 ColorIndex;                                      // 10
};

struct CharTitlesEntry
{
    uint32 ID;                                              // 0 title ids, for example in Quest::GetCharTitleId()
    //uint32  Condition_ID;                                 // 1
    char*  Name;                                            // 2
    char*  Name1;                                           // 3
    uint32 Mask_ID;                                         // 4 used in PLAYER_CHOSEN_TITLE and 1<<index in PLAYER__FIELD_KNOWN_TITLES
    //uint32 Flags                                          // 5
};

struct ChatChannelsEntry
{
    uint32  ID;                                             // 0
    uint32  Flags;                                          // 1
    //uint32  FactionGroup                                  // 2
    char* Name;                                             // 3
    //char* Shortcut;                                       // 4 
};

struct ChrClassesEntry
{
    uint32  ID;                                             // 0
    uint32  DisplayPower;                                   // 1
    //char* PetNameToken                                    // 2
    char*   Name;                                           // 3
    //char* Name_female;                                    // 4
    //char* Name_male;                                      // 5
    //char* Filename                                        // 6
    uint32  SpellClassSet;                                  // 7
    //uint32 Flags;                                         // 8        (0x08 HasRelicSlot)
    uint32  CinematicSequenceID;                            // 9
    uint32  Required_expansion;                             // 10
    uint32  AttackPowerPerStrength;                         // 11
    uint32  AttackPowerPerAgility;                          // 12
    uint32  RangedAttackPowerPerAgility;                    // 13
};

struct ChrRacesEntry
{
    uint32  ID;                                             // 0
    uint32  Flags;                                          // 1
    uint32  FactionID;                                      // 2
    // uint32 ExplorationSoundID                            // 3
    uint32  MaleDisplayID;                                  // 4
    uint32  FemaleDisplayID;                                // 5
    // char* ClientPrefix                                   // 6
    uint32  BaseLanguage;                                   // 7 (7-Alliance 1-Horde)
    // uint32 CreatureType                                  // 8
    // uint32 ResSicknessSpellID                            // 9
    // uint32 SplashSoundID                                 // 10
    // char* ClientFileString                               // 11
    uint32  CinematicSequenceID;                            // 12 id from CinematicSequences.dbc
    //uint32  Alliance;                                     // 13 (0 alliance, 1 horde, 2 not available?)
    char* Name;                                             // 14 used for DBC language detection/selection
    //char* Name_female;                                    // 15
    //char* Name_male;                                      // 16
    // uint32 FacialHairCustomization[2]                    // 17-18
    // uint32 HairCustomization                             // 19 
    uint32  Race_related;                                   // 20
    //uint32 UnalteredVisualRaceID                          // 21 (23 for worgens)
    //uint32 UaMaleCreatureSoundDataID                      // 22 4.0.0
    //uint32 UaFemaleCreatureSoundDataID                    // 23 4.0.0
};

struct ChrPowerTypesEntry
{
   uint32 ID;                                               // 0
   uint32 ClassID;                                          // 1
   uint32 PowerType;                                        // 2
};

struct CinematicCameraEntry
{
    uint32 ID;                                              // 0
    char const* Model;                                      // 1    Model filename (translate .mdx to .m2)
    uint32 SoundID;                                         // 2    Sound ID       (voiceover for cinematic)
    DBCPosition3D Origin;                                   // 3-5  Position in map used for basis for M2 co-ordinates
    float OriginFacing;                                     // 4    Orientation in map used for basis for M2 co-ordinates
};

struct CinematicSequencesEntry
{
    uint32  ID;                                             // 0 index
    //uint32 SoundID;                                       // 1 always 0
    uint32  Camera[8];                                      // 2 id in CinematicCamera.dbc
};

struct CreatureDisplayInfoEntry
{
    uint32  ID;                                             // 0
    uint32  ModelID;                                        // 1
    // uint32 SoundID                                       // 2
    uint32  ExtendedDisplayInfoID;                          // 3
    float   CreatureModelScale;                             // 4
    // uint32 CreatureModelAlpha                            // 5
    // char* TextureVariation[3]                            // 6-8
    // char* PortraitTextureName                            // 9
    // uint32 SizeClass                                     // 10
    // uint32 BloodID                                       // 11
    // uint32 NPCSoundID                                    // 12
    // uint32 ParticleColorID                               // 13
    // uint32 CreatureGeosetData                            // 14
    // uint32 ObjectEffectPackageID                         // 15
    // uint32 AnimReplacementSetID                          // 16
};

struct CreatureDisplayInfoExtraEntry
{
    // uint32 ID;                                           // 0
    uint32 DisplayRaceID;                                   // 1
    uint32 DisplaySexID;                                    // 2
    // uint32 SkinID;                                       // 3
    // uint32 FaceID;                                       // 4
    // uint32 HairStyleID;                                  // 5
    // uint32 HairColorID;                                  // 6
    // uint32 FacialHairID;                                 // 7
    // uint32 NPCItemDisplay[11]                            // 8 - 18
    // uint32 Flags;                                        // 19
    // char const* BakeName;                                // 20
};

struct CreatureFamilyEntry
{
    uint32  ID;                                             // 0
    float   MinScale;                                       // 1
    uint32  MinScaleLevel;                                  // 2
    float   MaxScale;                                       // 3
    uint32  MaxScaleLevel;                                  // 4
    uint32  SkillLine[2];                                   // 5-6
    uint32  PetFoodMask;                                    // 7
    int32   PetTalentType;                                  // 8
    // uint32 CategoryEnumID                                // 9
    char* Name;                                             // 10
    // char*  IconFile                                      // 11
};

struct CreatureModelDataEntry
{
    uint32 ID;                                              // 0
    uint32 Flags;                                           // 1
    char* ModelName;                                        // 2
    // uint32 SizeClass;                                    // 3
    float ModelScale;                                       // 4 Used in calculation of unit collision data
    // uint32 BloodID                                       // 5
    // uint32 FootprintTextureID                            // 6
    // uint32 FootprintTextureLength                        // 7
    // uint32 FootprintTextureWidth                         // 8
    // float FootprintParticleScale                         // 9
    // uint32 FoleyMaterialID                               // 10
    // float FootstepShakeSize                              // 11
    // uint32 DeathThudShakeSize                            // 12
    // uint32 SoundID                                       // 13
    // float CollisionWidth;                                // 14
    float CollisionHeight;                                  // 15
    float MountHeight;                                      // 16 Used in calculation of unit collision data when mounted
    // float GeoBoxMin[3]                                   // 17 - 19
    // float GeoBoxMax[3]                                   // 20 - 22
    // float WorldEffectScale                               // 23
    // float AttachedEffectScale                            // 24
    // float MissileCollisionRadius                         // 25
    // float MissileCollisionPush                           // 26
    // float MissileCollisionRaise                          // 27
    // float OverrideLootEffectScale                        // 28
    // float OverrideNameScale                              // 29
    float TamedPetBaseScale;                                // 30
};

struct CreatureSpellDataEntry
{
    uint32  ID;                                             // 0
    uint32  Spells[MAX_CREATURE_SPELL_DATA_SLOT];           // 1-4
    //uint32  Availability[MAX_CREATURE_SPELL_DATA_SLOT];   // 4-7
};

struct CreatureTypeEntry
{
    uint32  ID;                                             // 0
    //char* Name;                                           // 1
    //uint32  Flags;                                        // 2
};

/* not used
struct CurrencyCategoryEntry
{
    uint32  ID;                                             // 0
    uint32  Flags;                                          // 1
    char*   Name;                                           // 3
};
*/

struct CurrencyTypesEntry
{
    uint32 ID;                                              // 0
    uint32 CategoryID;                                      // 1 
    // char* Name;                                          // 2
    // char* InventoryIcon1;                                // 3
    // uint32 InventoryIcon2;                               // 4
    // uint32 SpellWeight;                                  // 5
    uint32 SpellCategory;                                   // 6
    uint32 MaxQty;                                          // 7
    uint32 MaxEarnablePerWeek;                              // 8
    uint32 Flags;                                           // 9
    //uint32 Description;                                   // 10
};

struct DestructibleModelDataEntry
{
    uint32  ID;                                             // 1
    uint32  State0WMO;                                      // 2
    //uint32  State0ImpactEffectDoodadSet;                  // 3
    //uint32  State0AmbientDoodadSet;                       // 4
    //uint32  State0NameSet;                                // 5
    uint32  State1WMO;                                      // 6
    //uint32  State1DestructionDoodadSet;                   // 7
    //uint32  State1ImpactEffectDoodadSet;                  // 8
    //uint32  State1AmbientDoodadSet;                       // 9
    //uint32  State1NameSet;                                // 10
    uint32  State2WMO;                                      // 11
    //uint32  State2DestructionDoodadSet;                   // 12
    //uint32  State2ImpactEffectDoodadSet;                  // 13
    //uint32  State2AmbientDoodadSet;                       // 14
    //uint32  State2NameSet;                                // 15
    uint32  State3WMO;                                      // 16
    //uint32  State3InitDoodadSet;                          // 17
    //uint32  State3AmbientDoodadSet;                       // 18
    //uint32  State3NameSet;                                // 19
    //uint32  EjectDirection;                               // 20
    //uint32  RepairGroundFx;                               // 21
    //uint32  DoNotHighlight;                               // 22
    //uint32  HealEffect;                                   // 23
    //uint32  HealEffectSpeed;                              // 24
};

struct DungeonEncounterEntry
{
    uint32 ID;                                              // 0
    uint32 MapID;                                           // 1
    int32 DifficultyID;                                     // 2 
    // uint32 OrderIndex;                                   // 3
    uint32 Bit;                                             // 4 used for creating completed masks
    char* Name;                                             // 5        encounter name
    //uint32 CreatureDisplayID;                             // 6
    //uint32 SpellIconID;                                   // 7
};

struct DurabilityCostsEntry
{
    uint32    ID;                                           // 0
    uint32    Multiplier[29];                               // 1-29 WeaponSubClassCost<32>[21] + ArmorSubClassCost<32>[8]
};

struct DurabilityQualityEntry
{
    uint32    ID;                                           // 0
    float     Data;                                         // 1
};

struct EmotesEntry
{
    uint32  ID;                                             // 0
    //char* EmoteSlashCommand;                              // 1, internal name
    //uint32 AnimID;                                        // 2, ref to animationData
    uint32  EmoteFlags;                                     // 3, bitmask, may be unit_flags
    uint32  EmoteSpecProc;                                  // 4, Can be 0, 1 or 2 (determine how emote are shown)
    uint32  EmoteSpecProcParam;                             // 5, uncomfirmed, may be enum UnitStandStateType
    //uint32 EventSoundID;                                  // 6, ref to soundEntries
    //uint32 SpellVisualKitID                               // 7
};

struct EmotesTextEntry
{
    uint32  ID;                                             // 0
    // char* Name;                                          // 1
    uint32  EmoteID;                                        // 2
    // uint32 EmoteText[16];                                // 3 - 18
};

struct EmotesTextSoundEntry
{
    uint32 ID;                                              // 0
    uint32 EmotesTextID;                                    // 1
    uint32 RaceID;                                          // 2
    uint32 SexID;                                           // 3 0 male / 1 female
    uint32 SoundID;                                         // 4
};

struct FactionEntry
{
    uint32  ID;                                             // 0
    int32   ReputationIndex;                                // 1
    uint32  ReputationRaceMask[4];                          // 2 - 5
    uint32  ReputationClassMask[4];                         // 6 - 9
    int32   ReputationBase[4];                              // 10 - 13
    uint32  ReputationFlags[4];                             // 14 - 17
    uint32  ParentFactionID;                                // 18
    float   ParentFactionMod[2];                            // 19 - 20 Faction gains incoming rep * spilloverRateIn and  Faction outputs rep * spilloverRateOut as spillover reputation
    uint32  ParentFactionCap[2];                            // 21 - 22 The highest rank the faction will profit from incoming spillover and It does not seem to be the max standing at which a faction outputs spillover ...so no idea
    char*   Name;                                           // 23
    // char* Description;                                   // 24
    uint32  Expansion;                                      // 25

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
    uint32      FactionGroup;                               // 3
    uint32      FriendGroup;                                // 4 
    uint32      EnemyGroup;                                 // 5
    uint32      Enemies[MAX_FACTION_RELATIONS];             // 6
    uint32      Friend[MAX_FACTION_RELATIONS];              // 10

    // helpers
    bool IsFriendlyTo(FactionTemplateEntry const& entry) const
    {
        if (ID == entry.ID)
            return true;

        if (entry.Faction)
        {
            for (uint8 i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Enemies[i] == entry.Faction)
                    return false;
            for (uint8 i = 0; i < MAX_FACTION_RELATIONS; ++i)
                if (Friend[i] == entry.Faction)
                    return true;
        }
        return (FriendGroup & entry.FactionGroup) || (FactionGroup & entry.FriendGroup);
    }
    bool IsHostileTo(FactionTemplateEntry const& entry) const
    {
        if (ID == entry.ID)
            return false;

        if (entry.Faction)
        {
            for (uint8 i = 0; i < MAX_FACTION_RELATIONS; i++)
                if (Enemies[i] == entry.Faction)
                    return true;

            for (uint8 i = 0; i < MAX_FACTION_RELATIONS; i++)
                if (Friend[i] == entry.Faction)
                    return false;
        }
        return (EnemyGroup & entry.FactionGroup) != 0;
    }

    bool IsHostileToPlayers() const { return (EnemyGroup & FACTION_MASK_PLAYER) != 0; }
    bool IsNeutralToAll() const
    {
        for (uint8 i = 0; i < MAX_FACTION_RELATIONS; i++)
            if (Enemies[i] != 0)
                return false;

        return EnemyGroup == 0 && FriendGroup == 0;
    }
    bool IsContestedGuardFaction() const { return (Flags & FACTION_TEMPLATE_FLAG_CONTESTED_GUARD) != 0; }
};

struct GameObjectArtKitEntry
{
    uint32 ID;                                              // 0
    //char* TextureVariation[3]                             // 1-3
    //char* AttachModel[4]                                  // 4-8
};

struct GameObjectDisplayInfoEntry
{
    uint32  ID;                                             // 0
    char*   ModelName;                                      // 1
    // uint32  Sound[10];                                   // 2 - 11
    DBCPosition3D GeoBoxMin;                                // 12 - 14
    DBCPosition3D GeoBoxMax;                                // 15 - 17
    // uint32  ObjectEffectPackageID;                       // 18
    // float  OverrideLootEffectScale;                      // 19
    // float  OverrideNameScale;                            // 20
};

struct GemPropertiesEntry
{
    uint32  ID;                                             // 0
    uint32  Enchant_ID;                                     // 1
    // uint32 Maxcount_inv;                                 // 2
    // uint32  Maxcount_item;                               // 3
    uint32  Type;                                           // 4
    uint32  Min_item_level;                                 // 5
};

struct GlyphPropertiesEntry
{
    uint32  ID;                                             // 0
    uint32  SpellID;                                        // 1
    uint32  GlyphSlotFlags;                                 // 2
    uint32  SpellIconID;                                    // 3 GlyphIconId (SpellIcon.dbc)
};

struct GlyphSlotEntry
{
    uint32  ID;                                             // 0
    uint32  Type;                                           // 1
    uint32  Tooltip;                                        // 2
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
    // uint32 ID;                                           // 0
    uint32  GuildLevel;                                     // 1
    uint32  SpellID;                                        // 2
};

/* not used
struct HolidayDescriptionsEntry
{
    uint32  ID;                                             // 0
    //char* Description                                     // 1
};
*/

/* not used
struct HolidayNamesEntry
{
    uint32  ID;                                             // 0
    //char* Name                                            // 1
};
*/

#define MAX_HOLIDAY_DURATIONS 10
#define MAX_HOLIDAY_DATES 26
#define MAX_HOLIDAY_FLAGS 10

struct HolidaysEntry
{
    uint32 ID;                                              // 0
    uint32 Duration[MAX_HOLIDAY_DURATIONS];                 // 1-10 
    uint32 Date[MAX_HOLIDAY_DATES];                         // 11-36 (dates in unix time starting at January, 1, 2000)
    uint32 Region;                                          // 37 (wow region)
    uint32 Looping;                                         // 38
    uint32 CalendarFlags[MAX_HOLIDAY_FLAGS];                // 39-48
    //uint32 HolidayNameID;                                 // 49 (HolidayNames.dbc)
    //uint32 HolidayDescriptionID;                          // 50 (HolidayDescriptions.dbc)
    char* TextureFilename;                                  // 51
    uint32 Priority;                                        // 52
    int32 CalendarFilterType;                               // 53 (-1 = Fishing Contest, 0 = Unk, 1 = Darkmoon Festival, 2 = Yearly holiday)
    //uint32 Flags;                                         // 54 (0 = Darkmoon Faire, Fishing Contest and Wotlk Launch, rest is 1)
};

// ImportPriceArmor.dbc
struct ImportPriceArmorEntry
{
    uint32 ID;                                              // 0        Id/InventoryType
    float ClothModifier;                                    // 1        Price factor cloth
    float LeatherModifier;                                  // 2        Price factor leather
    float ChainModifier;                                    // 3        Price factor mail
    float PlateModifier;                                    // 4        Price factor plate
};

// ImportPriceQuality.dbc
struct ImportPriceQualityEntry
{
    uint32 QualityId;                                       // 1        Quality Id (+1?)
    float Factor;                                           // 2        Price factor
};

// ImportPriceShield.dbc
struct ImportPriceShieldEntry
{
    uint32 ID;                                              // 1
    float Data;                                             // 2        Price factor
};

// ImportPriceWeapon.dbc
struct ImportPriceWeaponEntry
{
    uint32 ID;                                              // 1        Unk id (mainhand - 0, offhand - 1, weapon - 2, 2hweapon - 3, ranged/rangedright/relic - 4)
    float Data;                                             // 2        Price factor
};

// ItemPriceBase.dbc
struct ItemPriceBaseEntry
{
    // uint32 ID;                                           // 0
    uint32 ItemLevel;                                       // 1        Item level (1 - 1000)
    float Armor;                                            // 2        Price factor for armor
    float Weapon;                                           // 3        Price factor for weapons
};

struct ItemReforgeEntry
{
    uint32 ID;                                              // 0
    uint32 Source_stat;                                     // 1
    float Source_multiplier;                                // 2
    uint32 Target_stat;                                     // 3
    float Target_multiplier;                                // 4
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
    uint32    ID;                                           // 0 item level
    float     Quality[7];                                   // 1-7 multiplier for item quality
    uint32    ItemLevel;                                    // 8 item level
};

struct ItemArmorQualityEntry
{
    uint32    ID;                                           // 0
    float     Qualitymod[7];                                // 1-7 multiplier for item quality
    uint32    ItemLevel;                                    // 8 item level
};

struct ItemArmorShieldEntry
{
    uint32    ID;                                           // 0
    uint32    ItemLevel;                                    // 1 item level
    float     Quality[7];                                   // 2-8 multiplier for item quality
};

struct ItemArmorTotalEntry
{
    uint32    ID;                                           // 0
    uint32    ItemLevel;                                    // 1 item level
    float     Value[4];                                     // 2-5 multiplier for armor types (cloth...plate)
};

// ItemClass.dbc
struct ItemClassEntry
{
    // uint32  ID;                                          // 0
    uint32  ClassID;                                        // 1 item class id
    //uint32  SubclassMapID;                                // 2
    //uint32  Flags;                                        // 3 1 for weapon, 0 for everything else
    float  PriceModifier;                                   // 4 used to calculate certain prices
    //char*  ClassName;                                     // 5 class name
};

struct ItemBagFamilyEntry
{
    uint32  ID;                                             // 0
    //char* Name;                                           // 1
};

struct ItemDisplayInfoEntry
{
    uint32  ID;                                             // 0
    // char* ModelName[2];                                  // 1 - 2
    // char* ModelTexture[2];                               // 3 - 4
    // char* InventoryIcon[2];                              // 5 - 6
    // uint32 GeosetGroup[2];                               // 7 - 8
    // uint32 Flags;                                        // 9
    // uint32 SpellVisualID;                                // 10
    // uint32 GroupSoundIndex;                              // 11
    // uint32 HelmetGeosetVisID[2];                         // 12 - 13
    // char* Texture[8]                                     // 14 - 21
    // uint32 ItemVisual;                                   // 22
    // uint32 ParticleColorID;                              // 23
};

struct ItemDisenchantLootEntry
{
    uint32 ID;                                              // 0
    uint32 Class;                                           // 1
    int32 Subclass;                                         // 2
    uint32 Quality;                                         // 3
    uint32 MinLevel;                                        // 4
    uint32 MaxLevel;                                        // 5
    uint32 SkillRequired;                                   // 6
};

struct ItemLimitCategoryEntry
{
    uint32  ID;                                             // 0
    //char* Name;                                           // 1
    uint32  Quantity;                                       // 2 max allowed equipped as item or in gem slot
    uint32  Flags;                                          // 3 0 = have, 1 = equip (enum ItemLimitCategoryMode)
};

#define MAX_ITEM_ENCHANTMENT_EFFECTS 3

struct ItemRandomPropertiesEntry
{
    uint32  ID;                                             // 0 
    //char* Name                                            // 1
    uint32  Enchantment[5];                                 // 2 - 6
    char*   Name;                                           // 7
};

struct ItemRandomSuffixEntry
{
    uint32 ID;                                              // 0 
    char*  Name;                                            // 1
    // char* InternalName                                   // 2
    uint32  Enchantment[5];                                 // 3 - 7
    uint32  AllocationPct[5];                               // 8 - 12
};

#define MAX_ITEM_SET_ITEMS 17
#define MAX_ITEM_SET_SPELLS 8

struct ItemSetEntry
{
    //uint32  ID                                            // 0
    char*   Name;                                           // 1
    uint32  ItemID[MAX_ITEM_SET_ITEMS];                     // 2-18
    uint32  SetSpellID[MAX_ITEM_SET_SPELLS];                // 19-26
    uint32  SetThreshold[MAX_ITEM_SET_SPELLS];              // 27-34
    uint32  RequiredSkill;                                  // 35
    uint32  RequiredSkillRank;                              // 36
};

struct LFGDungeonEntry
{
    uint32  ID;                                             // 0
    char* Name;                                             // 1
    uint32  MinLevel;                                       // 2
    uint32  Maxlevel;                                       // 3
    uint32  Target_level;                                   // 4
    uint32  Target_level_min;                               // 5
    uint32  Target_level_max;                               // 6
    int32   MapID;                                          // 7
    uint32  DifficultyID;                                   // 8
    uint32  Flags;                                          // 9
    uint32  TypeID;                                         // 10
    //uint32  Faction;                                      // 11
    //char*   TextureFilename;                              // 12
    uint32  ExpansionLevel;                                 // 13
    //uint32  Order_index;                                  // 14
    uint32  Group_ID;                                       // 15
    //char*   Description;                                  // 16 Description
    uint32  Random_ID;                                      // 17 RandomDungeonID assigned for this dungeon
    uint32  Count_tank;                                     // 18
    uint32  Count_healer;                                   // 19
    uint32  Count_damage;                                   // 20

    // Helpers
    uint32 Entry() const { return ID + (TypeID << 24); }
};

struct LFGDungeonsGroupingMapEntry
{
    uint32 ID;                                              // 0
    uint32 LfgDungeonsID;                                   // 1
    uint32 Random_lfgDungeonsID;                            // 2
    uint32 Group_ID;                                        // 3
};

struct LightEntry
{
    uint32  ID;                                             // 0
    uint32  ContinentID;                                    // 1
    float   X;                                              // 2
    float   Y;                                              // 3
    float   Z;                                              // 4
    // float FalloffStart;                                  // 5
    // float FalloffEnd;                                    // 6
    // uint32 LightParamsID[8];                             // 7 - 14
};

struct LiquidTypeEntry
{
    uint32 ID;                                              // 1
    //char*  Name;                                          // 2
    //uint32 Flags;                                         // 3
    uint32 SoundBank;                                       // 4
    //uint32 SoundID;                                       // 5
    uint32 SpellID;                                         // 6
    //float MaxDarkenDepth;                                 // 7
    //float FogDarkenIntensity;                             // 8
    //float AmbDarkenIntensity;                             // 9
    //float DirDarkenIntensity;                             // 10
    //uint32 LightID;                                       // 11
    //float ParticleScale;                                  // 12
    //uint32 ParticleMovement;                              // 13
    //uint32 ParticleTexSlots;                              // 14
    //uint32 MaterialID;                                    // 15
    //char* Texture[6];                                     // 16 - 20
    //uint32 Color[2];                                      // 21 - 22
    //float Float[18];                                      // 23 - 40
    //uint32 Int[4];                                        // 41 - 44
};

#define MAX_LOCK_CASE 8

struct LockEntry
{
    uint32  ID;                                             // 0 
    uint32  Type[MAX_LOCK_CASE];                            // 1-8
    uint32  Index[MAX_LOCK_CASE];                           // 9-16
    uint32  Skill[MAX_LOCK_CASE];                           // 17-24
    //uint32  Action[MAX_LOCK_CASE];                        // 25-32
};

struct PhaseEntry
{
    uint32  ID;                                             // 0
    char*   Name;                                           // 1
    uint32  Flags;                                          // 2
};

struct PhaseGroupEntry
{
    uint32 ID;                                              // 1
    uint32 PhaseID;                                         // 2
    uint32 PhaseGroupID;                                    // 3
};

struct MailTemplateEntry
{
    uint32  ID;                                             // 0
    //char*  Subject;                                       // 1
    char*   Body;                                           // 2
};

struct MapEntry
{
    uint32 ID;                                              // 0
    char const* Directory;                                  // 1
    uint32 MapType;                                         // 2
    uint32 Flags;                                           // 3
    uint32 InstanceType;                                    // 4
    uint32 PVP;                                             // 5  0 or 1 for battlegrounds (not arenas)
    char const* MapName;                                    // 6
    uint32 AreaTableID;                                     // 7
    char const* MapDescription0;                            // 8  Horde
    char const* MapDescription1;                            // 9  Alliance
    uint32 LoadingScreenID;                                 // 10  (LoadingScreens.dbc)
    float MinimapIconScale;                                 // 11
    int32 CorpseMapID;                                      // 12 map_id of entrance map in ghost mode (continent always and in most cases = normal entrance)
    DBCPosition2D Corpse;                                   // 13 - 14  entrance coordinates in ghost mode  (in most cases = normal entrance)
    uint32 TimeOfDayOverride;                               // 15
    uint32 ExpansionID;                                     // 16
    uint32 RaidOffset;                                      // 17
    uint32 MaxPlayers;                                      // 18
    int32 ParentMapID;                                      // 19

    // Helpers
    uint32 Expansion() const { return ExpansionID; }

    bool IsDungeon() const { return MapType == MAP_INSTANCE || MapType == MAP_RAID; }
    bool IsNonRaidDungeon() const { return MapType == MAP_INSTANCE; }
    bool Instanceable() const { return MapType == MAP_INSTANCE || MapType == MAP_RAID || MapType == MAP_BATTLEGROUND || MapType == MAP_ARENA; }
    bool IsRaid() const { return MapType == MAP_RAID; }
    bool IsBattleground() const { return MapType == MAP_BATTLEGROUND; }
    bool IsBattleArena() const { return MapType == MAP_ARENA; }
    bool IsBattlegroundOrArena() const { return MapType == MAP_BATTLEGROUND || MapType == MAP_ARENA; }
    bool IsWorldMap() const { return MapType == MAP_COMMON; }

    bool GetEntrancePos(int32 &mapid, float &x, float &y) const
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
        return ID == 0 || ID == 1 || ID == 530 || ID == 571;
    }

    bool IsDynamicDifficultyMap() const { return (Flags & MAP_FLAG_DYNAMIC_DIFFICULTY) != 0; }
};

struct MapDifficultyEntry
{
    //uint32  ID;                                           // 0
    uint32  MapID;                                          // 1
    uint32  Difficulty;                                     // 2  (for arenas: arena slot)
    char*   Message;                                        // 3  (text showed when transfer to map failed)
    uint32  RaidDuration;                                   // 4  in secs, 0 if no fixed reset time
    uint32  MaxPlayers;                                     // 5  some heroic versions have 0 when expected same amount as in normal version
    //char*   Difficultystring;                             // 6
};

struct MountCapabilityEntry
{
    uint32 ID;                                              // 1
    uint32 Flags;                                           // 2
    uint32 ReqRidingSkill;                                  // 3
    uint32 ReqAreaID;                                       // 4
    uint32 ReqSpellAuraID;                                  // 5
    uint32 ReqSpellKnownID;                                 // 6
    uint32 ModSpellAuraID;                                  // 7
    int32  ReqMapID;                                        // 8
};

#define MAX_MOUNT_CAPABILITIES 24

struct MountTypeEntry
{
    uint32 ID;
    uint32 Capability[MAX_MOUNT_CAPABILITIES];
};

struct MovieEntry
{
    uint32  ID;                                             // 0 index
    //char*   Filename;                                     // 1
    //uint32  Volume;                                       // 2
    //uint32  KeyID;                                        // 3
};

struct NameGenEntry
{
    //uint32  ID;                                           // 1
    char*   Name;                                           // 2
    uint32  RaceID;                                         // 3
    uint32  Sex;                                            // 4
};

struct NumTalentsAtLevelEntry
{
    //uint32 Level;                                         // 0 index
    float NumberOfTalents;                                  // 1 talent count
};

struct NamesProfanityEntry
{
    // uint32    ID;                                        // 0
    char const* Name;                                       // 1
    int32       Language;                                   // 2
};

struct NamesReservedEntry
{
    // uint32    ID;                                        // 0
    char const* Name;                                       // 1
    int32       Language;                                   // 2
};

#define MAX_OVERRIDE_SPELL 10

struct OverrideSpellDataEntry
{
    uint32  ID;                                             // 0
    uint32  Spells[MAX_OVERRIDE_SPELL];                     // 1-10
    // uint32  Flags;                                       // 11
    // char*   PlayerActionbar;                             // 12
};

struct PowerDisplayEntry
{
    uint32  ID;                                             // 0
    uint32  ActualType;                                     // 1
    // char*  GlobalStringBaseTag;                          // 2
    // uint8 Red;                                           // 3
    // uint8 Green;                                         // 4
    // uint8 Blue;                                          // 5
    // uint8 Padding                                        // 6
};

struct PvPDifficultyEntry
{
    //uint32  ID;                                           // 0
    uint32  MapID;                                          // 1
    uint32  RangeIndex;                                     // 2
    uint32  MinLevel;                                       // 3
    uint32  MaxLevel;                                       // 4
    uint32  Difficulty;                                     // 5

    // helpers
    BattlegroundBracketId GetBracketId() const { return BattlegroundBracketId(RangeIndex); }
};

struct QuestSortEntry
{
    uint32  ID;                                             // 0
    //char*   SortName;                                     // 1
};

struct QuestXPEntry
{
    uint32  ID;                                             // 0
    uint32  Difficulty[10];                                 // 1 - 10
};

struct QuestFactionRewEntry
{
    uint32  ID;                                             // 0
    int32   Difficulty[10];                                 // 1 - 11
};

struct QuestPOIBlobEntry
{
    uint32  ID;                                             // 0
    uint32  NumPoints;                                      // 1
    uint32  MapID;                                          // 2
    uint32  WorldMapAreaID;                                 // 3
};

struct QuestPOIPointEntry
{
    uint32  ID;                                             // 0
    int32   X;                                              // 1
    int32   Y;                                              // 2
    uint32  QuestPOIBlobID;                                 // 3
};

struct RandomPropertiesPointsEntry
{
    //uint32  Id;                                           // 0 hidden key
    uint32    itemLevel;                                    // 1
    uint32    EpicPropertiesPoints[5];                      // 2-6
    uint32    RarePropertiesPoints[5];                      // 7-11
    uint32    UncommonPropertiesPoints[5];                  // 12-16
};

// ResearchBranch.dbc
struct ResearchBranchEntry
{
    uint32  ID;                                             // 0
    char*   Name;                                           // 1
    uint32  ResearchFieldID;                                // 2
    uint32  CurrencyID;                                     // 3
    char*   Texture;                                        // 4
    uint32  ItemID;                                         // 5
};

// ResearchField.dbc
struct ResearchFieldEntry
{
    uint32 ID;                                              // 0
    char*  Name;                                            // 1
    uint32 Slot;                                            // 2
};

// ResearchProject.dbc
struct ResearchProjectEntry
{
    uint32  ID;                                             // 0
    char*   Name;                                           // 1
    char*   Description;                                    // 2
    uint32  Rarity;                                         // 3
    uint32  ResearchBranchID;                               // 4
    uint32  SpellID;                                        // 5
    uint32  NumSockets;                                     // 6
    char*   Texture;                                        // 7
    uint32  RequiredWeight;                                 // 8
};

// ResearchSite.dbc
struct ResearchSiteEntry
{
    uint32  ID;                                             // 1
    uint32  MapID;                                          // 2
    uint32  QuestPOIBlobID;                                 // 3
    char*   Name;                                           // 4
    char*   AreaPOIIconEnum;                                // 5

    // Helpers
    bool IsValid() const
    {
        return ID != 140 && // template
            ID != 142 &&    // template
            ID != 161 &&    // template
            ID != 471 &&    // Vashj'ir
            ID != 473 &&    // Vashj'ir
            ID != 475;      // Vashj'ir
    }
};

struct ScalingStatDistributionEntry
{
    uint32  ID;                                             // 0
    int32   StatID[10];                                     // 1 - 10
    uint32  Bonus[10];                                      // 11 - 20
    uint32  Minlevel;                                       // 21
    uint32  Maxlevel;                                       // 22
};

struct ScalingStatValuesEntry
{
    uint32 ID;                                              // 0
    uint32 Charlevel;                                       // 1
    uint32 dpsMod[6];                                       // 2 - 7 DPS mod for level
    uint32 Spellpower;                                      // 8 spell power for level
    uint32 StatMultiplier[5];                               // 9 - 13 Multiplier for ScalingStatDistribution
    uint32 Armor[8][4];                                     // 14 - 46 Armor for level
    uint32 CloakArmor;                                      // 47 armor for cloak

    uint32 GetStatMultiplier(uint32 inventoryType) const;
    uint32 GetArmor(uint32 inventoryType, uint32 armorType) const;
    uint32 GetDPSAndDamageMultiplier(uint32 subClass, bool isCasterWeapon, float* damageMultiplier) const;
};

//struct SkillLineCategoryEntry{
//    uint32    id;                                         // 0
//    char*     name[16];                                   // 1 - 17
//                                                          // 18
//    uint32    displayOrder;                               // 19
//};

struct SkillLineEntry
{
    uint32  ID;                                             // 0
    int32   CategoryID;                                     // 1
    char*   DisplayName;                                    // 3
    //char*  Description;                                   // 4
    uint32  SpellIconID;                                    // 5
    //char*   AlternateVerb;                                // 6 
    uint32  CanLink;                                        // 7 (prof. with recipe)
};

struct SkillLineAbilityEntry
{
    uint32 ID;                                              // 0
    uint32 SkillLine;                                       // 1
    uint32 Spell;                                           // 2
    uint32 RaceMask;                                        // 3
    uint32 ClassMask;                                       // 4
    //uint32 ExcludeRace;                                   // 5
    //uint32 ExcludeClass;                                  // 6
    uint32 MinSkillLineRank;                                // 7
    uint32 SupercededBySpell;                               // 8
    uint32 AcquireMethod;                                   // 9
    uint32 TrivialSkillLineRankHigh;                        // 10
    uint32 TrivialSkillLineRankLow;                         // 11
    uint32 NumSkillUps;                                     // 12
    uint32 UniqueBit;                                       // 13
};

struct SkillRaceClassInfoEntry
{
    //uint32 ID;                                            // 0
    uint32 SkillID;                                         // 1
    uint32 RaceMask;                                        // 2
    uint32 ClassMask;                                       // 3
    uint32 Flags;                                           // 4
    uint32 Availability;                                    // 5
    //uint32 MinLevel;                                      // 6
    uint32 SkillTierID;                                     // 7
    //uint32 SkillCostIndex;                                // 8
};

#define MAX_SKILL_STEP 16

struct SkillTiersEntry
{
    uint32 ID;                                              // 0
    //uint32 Cost[MAX_SKILL_STEP];                          // 1-16
    uint32 Value[MAX_SKILL_STEP];                           // 17-32
};

struct SoundEntriesEntry
{
    uint32  ID;                                             // 0
    //uint32  SoundType;                                    // 1
    //char*   Name;                                         // 2
    //char*   File[10];                                     // 3 - 12
    //uint32  Freq[10];                                     // 13 - 22
    //char*   DirectoryBase;                                // 23
    //float   VolumeFloat;                                  // 24
    //uint32  Flags;                                        // 25
    //float   MinDistance;                                  // 26
    //float   DistanceCutoff;                               // 27
    //uint32  EAXDef;                                       // 28
    //uint32  SoundEntriesAdvancedID;                       // 29
    //float   Volumevariationplus;                          // 30
    //float   Volumevariationminus;                         // 31
    //float   Pitchvariationplus;                           // 32
    //float   Pitchvariationminus;                          // 33
    //float   PitchAdjust;                                  // 34
};

// SpellEffect.dbc
struct SpellEffectEntry
{
    uint32    ID;                                           // 0
    uint32    Effect;                                       // 1
    float     EffectAmplitude;                              // 2
    uint32    EffectAura;                                   // 3
    uint32    EffectAuraPeriod;                             // 4
    int32     EffectBasePoints;                             // 5
    float     EffectBonusCoefficient;                       // 6
    float     EffectChainAmplitude;                         // 7
    uint32    EffectChainTargets;                           // 8
    int32     EffectDieSides;                               // 9
    uint32    EffectItemType;                               // 10
    uint32    EffectMechanic;                               // 11
    int32     EffectMiscValue;                              // 12
    int32     EffectMiscValueB;                             // 13
    float     EffectPointsPerResource;                      // 14
    uint32    EffectRadiusIndex;                            // 15
    uint32    EffectRadiusMaxIndex;                         // 16
    float     EffectRealPointsPerLevel;                     // 17
    flag96    EffectSpellClassMask;                         // 18 - 20
    uint32    EffectTriggerSpell;                           // 21
    uint32    EffectImplicitTargetA;                        // 22
    uint32    EffectImplicitTargetB;                        // 23
    uint32    SpellID;                                      // 24
    uint32    EffectIndex;                                  // 25
    //uint32  EffectAttributes                              // 26
};

// SpellAuraOptions.dbc
struct SpellAuraOptionsEntry
{
    uint32    ID;                                           // 0
    uint32    CumulativeAura;                               // 1
    uint32    ProcChance;                                   // 2
    uint32    ProcCharges;                                  // 3
    uint32    ProcTypeMask;                                 // 4
};

// SpellAuraRestrictions.dbc/
struct SpellAuraRestrictionsEntry
{
    //uint32  ID;                                           // 0
    uint32  CasterAuraState;                                // 1
    uint32  TargetAuraState;                                // 2
    uint32  ExcludeCasterAuraState;                         // 3
    uint32  ExcludeTargetAuraState;                         // 4
    uint32  CasterAuraSpell;                                // 5
    uint32  TargetAuraSpell;                                // 6
    uint32  ExcludeCasterAuraSpell;                         // 7
    uint32  ExcludeTargetAuraSpell;                         // 8
};

// SpellCastingRequirements.dbc
struct SpellCastingRequirementsEntry
{
    //uint32  ID;                                           // 0
    uint32  FacingCasterFlags;                              // 1
    //uint32  MinFactionID;                                 // 2
    //uint32  MinReputation;                                // 3
    int32  RequiredAreasID;                                 // 4
    //uint32  RequiredAuraVision;                           // 5
    uint32  RequiresSpellFocus;                             // 6
};

#define MAX_SPELL_TOTEMS            2

// SpellTotems.dbc
struct SpellTotemsEntry
{
    uint32  ID;                                             // 0
    uint32  RequiredTotemCategoryID[MAX_SPELL_TOTEMS];      // 1
    uint32  Totem[MAX_SPELL_TOTEMS];                        // 2
};

// Spell.dbc
struct SpellEntry
{
    uint32  ID;                                             // 0
    uint32  Attributes;                                     // 1
    uint32  AttributesEx;                                   // 2
    uint32  AttributesEx2;                                  // 3
    uint32  AttributesEx3;                                  // 4
    uint32  AttributesEx4;                                  // 5
    uint32  AttributesEx5;                                  // 6
    uint32  AttributesEx6;                                  // 7
    uint32  AttributesEx7;                                  // 8
    uint32  AttributesEx8;                                  // 9
    uint32  AttributesEx9;                                  // 1
    uint32  AttributesEx10;                                 // 1
    uint32  CastingTimeIndex;                               // 1
    uint32  DurationIndex;                                  // 1
    uint32  PowerType;                                      // 1
    uint32  RangeIndex;                                     // 1
    float   Speed;                                          // 1
    uint32  SpellVisualID[2];                               // 17 - 18
    uint32  SpellIconID;                                    // 19
    uint32  ActiveIconID;                                   // 20
    char*   Name;                                           // 21
    char*   NameSubtext;                                    // 22
    //char* Description;                                    // 23
    //char* AuraDescription;                                // 24
    uint32  SchoolMask;                                     // 25
    uint32  RuneCostID;                                     // 26
    //uint32  SpellMissileID;                               // 27
    //uint32  DescriptionVariablesID;                       // 28
    uint32  Difficulty;                                     // 29
    float   SpellCoef;                                      // 30
    uint32  ScalingID;                                      // 31
    uint32  AuraOptionsID;                                  // 32
    uint32  AuraRestrictionsID;                             // 33
    uint32  CastingRequirementsID;                          // 34
    uint32  CategoriesID;                                   // 35
    uint32  ClassOptionsID;                                 // 36
    uint32  CooldownsID;                                    // 37
    //uint32  unkIndex7;                                    // 38
    uint32  EquippedItemsID;                                // 39
    uint32  InterruptsID;                                   // 40
    uint32  LevelsID;                                       // 41
    uint32  PowerDisplayID;                                 // 42
    uint32  ReagentsID;                                     // 43
    uint32  ShapeshiftID;                                   // 44
    uint32  TargetRestrictionsID;                           // 45
    uint32  TotemsID;                                       // 46
    uint32  RequiredProjectID;                              // 47
};

// SpellCategories.dbc
struct SpellCategoriesEntry
{
    //uint32    ID;                                          // 0
    uint32    Category;                                      // 1
    uint32    DefenseType;                                   // 2
    uint32    DispelType;                                    // 3
    uint32    Mechanic;                                      // 4
    uint32    PreventionType;                                // 5
    uint32    StartRecoveryCategory;                         // 6
};

typedef std::set<uint32> PetFamilySpellsSet;
typedef std::map<uint32, PetFamilySpellsSet> PetFamilySpellsStore;

struct SpellCastTimesEntry
{
    uint32  ID;                                             // 0
    int32   Base;                                           // 1
    //int32  PerLevel;                                      // 2
    //int32  Minimum;                                       // 3
};

struct SpellCategoryEntry
{
    uint32 ID;                                             // 0
    uint32 Flags;                                          // 1
    uint32 UsesPerWeek;                                    // 2
    // char* Name;                                         // 3
};

struct SpellDifficultyEntry
{
    uint32     ID;                                          // 0
    int32      DifficultySpellID[MAX_DIFFICULTY];           // 1 - 4 instance modes: 10N, 25N, 10H, 25H or Normal/Heroic if only 1-2 is set, if 3-4 is 0 then Mode-2
};

struct SpellFocusObjectEntry
{
    uint32  ID;                                             // 0
    //char*   Name;                                         // 1
};

struct SpellRadiusEntry
{
    uint32  ID;                                             // 0
    float   RadiusMin;                                      // 1
    float   RadiusPerLevel;                                 // 2
    float   RadiusMax;                                      // 3
};

struct SpellRangeEntry
{
    uint32  ID;                                             // 1
    float   RangeMin[2];                                    // 2 - 3
    float   RangeMax[2];                                    // 4 - 5
    uint32  Flags;                                          // 6
    //char*   DisplayName;                                  // 7
    //char*   DisplayNameShort;                             // 8
};

// SpellEquippedItems.dbc
struct SpellEquippedItemsEntry
{
    //uint32  ID;                                           // 1
    int32   EquippedItemClass;                              // 2
    int32   EquippedItemInvTypes;                           // 3
    int32   EquippedItemSubclass;                           // 4
};

// SpellCooldowns.dbc
struct SpellCooldownsEntry
{
    //uint32  ID;                                           // 0
    uint32  CategoryRecoveryTime;                           // 1
    uint32  RecoveryTime;                                   // 2
    uint32  StartRecoveryTime;                              // 3
};

// SpellClassOptions.dbc
struct SpellClassOptionsEntry
{
    //uint32  ID;                                           // 0
    //uint32  ModalNextSpell;                               // 1
    flag96  SpellFamilyMask;                                // 2-4
    uint32  SpellClassSet;                                  // 5
    //char*   Description;                                  // 6
};

// SpellInterrupts.dbc
struct SpellInterruptsEntry
{
    //uint32  ID;                                           // 0
    uint32  AuraInterruptFlags[2];                          // 1 - 2
    uint32  ChannelInterruptFlags[2];                       // 3 - 4
    uint32  InterruptFlags;                                 // 5
};

// SpellLevels.dbc
struct SpellLevelsEntry
{
    //uint32  ID;                                           // 0
    uint32  BaseLevel;                                      // 1
    uint32  MaxLevel;                                       // 2
    uint32  SpellLevel;                                     // 3
};

// SpellPower.dbc
struct SpellPowerEntry
{
    //uint32  ID;                                           // 0
    uint32  ManaCost;                                       // 1
    uint32  ManaCostPerLevel;                               // 2
    uint32  PowerCostPct;                                   // 3
    uint32  ManaPerSecond;                                  // 4
    //uint32  PowerDisplayID;                               // 5
    //uint32  AltPowerBarID;                                // 6
    float   PowerCostPct2;                                  // 7
};

struct SpellRuneCostEntry
{
    uint32  ID;                                             // 0
    uint32  RuneCost[3];                                    // 1 - 3 (0 = blood, 1 = frost, 2 = unholy)
    uint32  RunicPower;                                     // 4

    bool NoRuneCost() const { return RuneCost[0] == 0 && RuneCost[1] == 0 && RuneCost[2] == 0; }
    bool NoRunicPowerGain() const { return RunicPower == 0; }
};

#define MAX_SHAPESHIFT_SPELLS 8

struct SpellShapeshiftFormEntry
{
    uint32  ID;                                             // 0
    //uint32  BonusActionBar;                               // 1 unused
    //char*   Name;                                         // 2 unused
    uint32  Flags;                                          // 3
    int32   CreatureType;                                   // 4 <= 0 humanoid, other normal creature types
    //uint32  AttackIconID;                                 // 5 unused, related to next field
    uint32  CombatRoundTime;                                // 6
    uint32  CreatureDisplayID[4];                           // 7 - 10
    uint32  PresetSpellID[MAX_SHAPESHIFT_SPELLS];           // 11 - 18 spells which appear in the bar after shapeshifting
    uint32  MountTypeID;                                    // 19
    //uint32  ExitSoundEntriesID;                           // 20
};

// SpellShapeshift.dbc
struct SpellShapeshiftEntry
{
    uint32  ID;                                             // 0
    uint32  ShapeshiftExclude[2];                           // 1
    uint32  ShapeshiftMask[2];                              // 3
    // uint32  StanceBarOrder;                              // 5
};

// SpellTargetRestrictions.dbc
struct SpellTargetRestrictionsEntry
{
    uint32  ID;                                             // 0
    float   ConeAngle;                                      // 1
    uint32  MaxTargets;                                     // 2
    uint32  MaxTargetLevel;                                 // 3
    uint32  TargetCreatureType;                             // 4
    uint32  Targets;                                        // 5
};

// SpellReagents.dbc
struct SpellReagentsEntry
{
    //uint32  ID;                                           // 0
    int32   Reagents[MAX_SPELL_REAGENTS];                   // 1 - 8
    uint32  ReagentCount[MAX_SPELL_REAGENTS];               // 9 - 16
};

// SpellScaling.dbc
struct SpellScalingEntry
{
    //uint32  ID;                                           // 0        m_ID
    int32   CastTimeMin;                                    // 1
    int32   CastTimeMax;                                    // 2
    int32   CastTimeMaxLevel;                               // 3
    int32   Class;                                          // 4        (index * 100) + charLevel - 1 => gtSpellScaling.dbc
    float   Coefficient[3];                                 // 5 - 7
    float   Variance[3];                                    // 8 - 10
    float   ComboPointsCoefficient[3];                      // 11 - 13
    float   NerfFactor;                                     // 14        some coefficient, mostly 1.0f
    int32   NerfMaxLevel;                                   // 15        some level
};

struct SpellDurationEntry
{
    uint32  ID;                                             // 0
    int32   Duration;                                       // 1
    int32   DurationPerLevel;                               // 2
    int32   MaxDuration;                                    // 3
};

struct SpellItemEnchantmentEntry
{
    uint32  ID;                                             // 0
    //uint32  Charges;                                      // 1
    uint32  Effect[MAX_ITEM_ENCHANTMENT_EFFECTS];           // 2 - 4
    uint32  EffectPointsMin[MAX_ITEM_ENCHANTMENT_EFFECTS];  // 5 - 7
    //uint32  EffectPointsMax[MAX_ITEM_ENCHANTMENT_EFFECTS];// 8 - 10
    uint32  EffectArg[MAX_ITEM_ENCHANTMENT_EFFECTS];        // 11 - 13
    char*   Name;                                           // 14
    uint32  ItemVisual;                                     // 15
    uint32  Flags;                                          // 16
    uint32  Src_itemID;                                     // 17
    uint32  Condition_ID;                                   // 18
    uint32  RequiredSkillID;                                // 19
    uint32  RequiredSkillRank;                              // 20
    uint32  MinLevel;                                       // 21
    //uint32 ItemLevel;                                     // 22
};

struct SpellItemEnchantmentConditionEntry
{
    uint32  ID;                                             // 0        m_ID
    uint8   Color[3];                                       // 1-3      m_lt_operandType[5]
    //uint8   unk1;                                         // 4
    //uint32  unk2[6];                                      // 5-10
    uint8   Comparator[3];                                  // 11-13    m_operator[5]
    //uint8   unk3[2];                                      // 14-15
    uint8   CompareColor[3];                                // 16-18    m_rt_operandType[5]
    //uint32  unk4;                                         // 19
    uint32  Value[3];                                       // 20-22    m_rt_operand[5]
    //uint32  unk5[2];                                      // 23-24
    //uint8   unk6[6];                                      // 25-30
};

struct SpellVisualEntry
{
    //uint32  ID;
    //uint32  PrecastKit;
    //uint32  CastKit;
    //uint32  ImpactKit;
    //uint32  StateKit;
    //uint32  StateDoneKit;
    //uint32  ChannelKit;
    uint32  HasMissile;
    int32   MissileModel;
    //uint32  MissilePathType;
    //uint32  MissileDestinationAttachment;
    //uint32  MissileSound;
    //uint32  AnimEventSoundID;
    //uint32  Flags;
    //uint32  CasterImpactKit;
    //uint32  TargetImpactKit;
    //int32   MissileAttachment;
    //uint32  MissileFollowGroundHeight;
    //uint32  MissileFollowGroundDropSpeed;
    //uint32  MissileFollowGroundApprach;
    //uint32  MissileFollowGroundFlags;
    //uint32  MissileMotionId;
    //uint32  MissileTargetingKit;
    //uint32  InstantAreaKit;
    //uint32  ImpactAreaKit;
    //uint32  PersistentAreaKit;
    //DBCPosition3D MissileCastOffset;
    //DBCPosition3D MissileImpactOffset;
    uint32 AlternativeVisualID;
};

struct SpellVisualKitEntry
{
    uint32 ID;
    uint32 StartAnimID;
    uint32 AnimID;
    uint32 AnimKitID;
    uint32 HeadEffect;
    uint32 ChestEffect;
    uint32 BaseEffect;
    uint32 LeftHandEffect;
    uint32 RightHandEffect;
    uint32 BreathEffect;
    uint32 LeftWeaponEffect;
    uint32 RightWeaponEffect;
    uint32 SpecialEffect[3];
    uint32 WorldEffect;
    uint32 SoundID;
    uint32 ShakeID;
    uint32 CharProc[4];
    uint32 CharParamZero[4];
    uint32 CharParamOne[4];
    uint32 CharParamTwo[4];
    uint32 CharParamThree[4];
    uint32 Flags;
};

struct SummonPropertiesEntry
{
    uint32  ID;                                             // 0
    uint32  Control;                                        // 1, 0 - can't be controlled?, 1 - something guardian?, 2 - pet?, 3 - something controllable?, 4 - taxi/mount?
    uint32  Faction;                                        // 2, 14 rows > 0
    int32   Title;                                          // 3, see enum
    int32   Slot;                                           // 4, 0-6
    uint32  Flags;                                          // 5
};

struct TalentEntry
{
    uint32  ID;                                             // 0
    uint32  TabID;                                          // 1 index in TalentTab.dbc (TalentTabEntry)
    uint32  TierID;                                         // 2
    uint32  ColumnIndex;                                    // 3
    uint32  SpellRank[MAX_TALENT_RANK];                     // 4-8
    uint32  PrereqTalent[3];                                // 9 - 11 (Talent.dbc)
    uint32  PrereqRank[3];                                  // 12 - 14 part of prev field
    //uint32  Flags;                                        // 15  also need disable higest ranks on reset talent tree
    //uint32  RequiredSpellID;                              // 16
    //uint64  CategoryMask[2];                              // 17 - 18 its a 64 bit mask for pet 1 << m_categoryEnumID in CreatureFamily.dbc
};

#define MAX_MASTERY_SPELLS 2

struct TalentTabEntry
{
    uint32  ID;                                             // 0
    //char* Name;                                           // 1
    //unit32  SpellIconID;                                  // 2
    uint32  ClassMask;                                      // 3
    uint32  CategoryEnumID;                                 // 4
    uint32  OrderIndex;                                     // 5
    //char* BackgroundFile;                                 // 6
    //char* Description;                                    // 7
    //uint32 RoleMask;                                      // 8
    uint32 MasterySpellID[MAX_MASTERY_SPELLS];              // 9 - 10 passive mastery bonus spells
};

struct TalentTreePrimarySpellsEntry
{
    //uint32  ID;                                            // 0 index
    uint32  TalentTabID;                                     // 1 entry from TalentTab.dbc
    uint32  SpellID;                                         // 2 spell id to learn
    //uint32  Flags;                                         // 3 some kind of flags
};

struct TaxiNodesEntry
{
    uint32  ID;                                             // 0
    uint32  ContinentID;                                    // 1
    DBCPosition3D Pos;                                      // 2 - 4
    char* Name;                                             // 5
    uint32  MountCreatureID[2];                             // 6 - 7
    uint32  Flags;                                          // 8
    DBCPosition2D MapOffset;                                // 9 - 10
};

struct TaxiPathEntry
{
    uint32  ID;                                             // 0
    uint32  FromTaxiNode;                                   // 1
    uint32  ToTaxiNode;                                     // 2
    uint32  Cost;                                           // 3
};

struct TaxiPathNodeEntry
{
    //uint32  ID;                                           // 0
    uint32    PathID;                                       // 1
    uint32    NodeIndex;                                    // 2
    uint32    ContinentID;                                  // 3
    DBCPosition3D Loc;                                      // 4 - 6
    uint32    Flags;                                        // 7
    uint32    Delay;                                        // 8
    uint32    ArrivalEventID;                               // 9
    uint32    DepartureEventID;                             // 10
};

struct TotemCategoryEntry
{
    uint32    ID;                                           // 0
    //char*   Name;                                         // 1
    uint32    TotemCategoryType;                            // 2 (one for specialization)
    uint32    TotemCategoryMask;                            // 3 (compatibility mask for same type: different for totems, compatible from high to low for rods)
};

struct UnitPowerBarEntry
{
    uint32  ID;                                             // 1
    uint32  MinPower;                                       // 2
    uint32  MaxPower;                                       // 3
    uint32  StartPower;                                     // 4
    //uint32  CenterPower;                                  // 5
    float   RegenerationPeace;                              // 6
    float   RegenerationCombat;                             // 7
    //uint32  BarType;                                      // 8
    //uint32  FileDataID[6];                                // 9 - 14
    //uint32  Color[6];                                     // 15 - 20
    //uint32  Flags;                                        // 21
    //char*   Name;                                         // 22
    //char*   Cost;                                         // 23
    //char*   OutOfError;                                   // 24
    //char*   ToolTip;                                      // 25
    //float   StartInset;                                   // 26
    //float   EndInset;                                     // 27
};

struct TransportAnimationEntry
{
    //uint32  ID;                                           // 1
    uint32  TransportID;                                    // 2
    uint32  TimeIndex;                                      // 3
    DBCPosition3D Pos;                                      // 4 - 6
    //uint32  SequenceID;                                   // 7
};

struct TransportRotationEntry
{
    //uint32  ID;                                           // 1
    uint32  GameObjectsID;                                  // 2
    uint32  TimeIndex;                                      // 3
    float   X;                                              // 4
    float   Y;                                              // 5
    float   Z;                                              // 6
    float   W;                                              // 7
};

#define MAX_VEHICLE_SEATS 8

struct VehicleEntry
{
    uint32  ID;                                             // 0
    uint32  Flags;                                          // 1
    float   TurnSpeed;                                      // 2
    float   PitchSpeed;                                     // 3
    float   PitchMin;                                       // 4
    float   PitchMax;                                       // 5
    uint32  SeatID[MAX_VEHICLE_SEATS];                      // 6 - 13
    float   MouseLookOffsetPitch;                           // 14
    float   CameraFadeDistScalarMin;                        // 15
    float   CameraFadeDistScalarMax;                        // 16
    float   CameraPitchOffset;                              // 17
    float   FacingLimitRight;                               // 18
    float   FacingLimitLeft;                                // 19
    float   MsslTrgtTurnLingering;                          // 20
    float   MsslTrgtPitchLingering;                         // 21
    float   MsslTrgtMouseLingering;                         // 22
    float   MsslTrgtEndOpacity;                             // 23
    float   MsslTrgtArcSpeed;                               // 24
    float   MsslTrgtArcRepeat;                              // 25
    float   MsslTrgtArcWidth;                               // 26
    float   MsslTrgtImpactRadius[2];                        // 27 - 28
    char*   MsslTrgtArcTexture;                             // 29
    char*   MsslTrgtImpactTexture;                          // 30
    char*   MsslTrgtImpactModel[2];                         // 31 - 32
    float   CameraYawOffset;                                // 33
    uint32  UiLocomotionType;                               // 34
    float   MsslTrgtImpactTexRadius;                        // 35
    uint32  VehicleUIIndicatorID;                           // 36
    uint32  PowerDisplayID[3];                              // 37
};

struct VehicleSeatEntry
{
    uint32  ID;                                              // 0
    uint32  Flags;                                           // 1
    int32   AttachmentID;                                    // 2
    DBCPosition3D AttachmentOffset;                          // 3 - 5
    float   EnterPreDelay;                                   // 6
    float   EnterSpeed;                                      // 7
    float   EnterGravity;                                    // 8
    float   EnterMinDuration;                                // 9
    float   EnterMaxDuration;                                // 10
    float   EnterMinArcHeight;                               // 11
    float   EnterMaxArcHeight;                               // 12
    int32   EnterAnimStart;                                  // 13
    int32   EnterAnimLoop;                                   // 14
    int32   RideAnimStart;                                   // 15
    int32   RideAnimLoop;                                    // 16
    int32   RideUpperAnimStart;                              // 17
    int32   RideUpperAnimLoop;                               // 18
    float   ExitPreDelay;                                    // 19
    float   ExitSpeed;                                       // 20
    float   ExitGravity;                                     // 21
    float   ExitMinDuration;                                 // 22
    float   ExitMaxDuration;                                 // 23
    float   ExitMinArcHeight;                                // 24
    float   ExitMaxArcHeight;                                // 25
    int32   ExitAnimStart;                                   // 26
    int32   ExitAnimLoop;                                    // 27
    int32   ExitAnimEnd;                                     // 28
    float   PassengerYaw;                                    // 29
    float   PassengerPitch;                                  // 30
    float   PassengerRoll;                                   // 31
    int32   PassengerAttachmentID;                           // 32
    int32   VehicleEnterAnim;                                // 33
    int32   VehicleExitAnim;                                 // 34
    int32   VehicleRideAnimLoop;                             // 35
    int32   VehicleEnterAnimBone;                            // 36
    int32   VehicleExitAnimBone;                             // 37
    int32   VehicleRideAnimLoopBone;                         // 38
    float   VehicleEnterAnimDelay;                           // 39
    float   VehicleExitAnimDelay;                            // 40
    uint32  VehicleAbilityDisplay;                           // 41
    uint32  EnterUISoundID;                                  // 42
    uint32  ExitUISoundID;                                   // 43
    int32   UISkin;                                          // 44
    uint32  FlagsB;                                          // 45
    float   CameraEnteringDelay;                             // 46
    float   CameraEnteringDuration;                          // 47
    float   CameraExitingDelay;                              // 48
    float   CameraExitingDuration;                           // 49
    DBCPosition3D CameraOffset;                              // 50 - 52
    float   CameraPosChaseRate;                              // 53
    float   CameraFacingChaseRate;                           // 54
    float   CameraEnteringZoom;                              // 55
    float   CameraSeatZoomMin;                               // 56
    float   CameraSeatZoomMax;                               // 57
    uint32  EnterAnimKitID;                                  // 58
    uint32  RideAnimKitID;                                   // 59
    uint32  ExitAnimKitID;                                   // 60
    uint32  VehicleEnterAnimKitID;                           // 61
    uint32  VehicleRideAnimKitID;                            // 62
    uint32  VehicleExitAnimKitID;                            // 63
    uint32  CameraModeID;                                    // 64 
    uint32  FlagsC;                                          // 65

    inline bool HasFlag(VehicleSeatFlags flag) const { return (Flags & flag); }
    inline bool HasFlag(VehicleSeatFlagsB flag) const { return (FlagsB & flag); }

    inline bool CanEnterOrExit() const { return HasFlag(VehicleSeatFlags(VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT | VEHICLE_SEAT_FLAG_CAN_CONTROL | VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_VOLUNTARY_EXIT)); }
    inline bool CanSwitchFromSeat() const { return HasFlag(VEHICLE_SEAT_FLAG_CAN_SWITCH); }
    inline bool IsUsableByOverride() const { return HasFlag(VehicleSeatFlags(VEHICLE_SEAT_FLAG_UNCONTROLLED | VEHICLE_SEAT_FLAG_UNK18))
                                    || HasFlag(VehicleSeatFlagsB(VEHICLE_SEAT_FLAG_B_USABLE_FORCED | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2 |
                                        VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3 | VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4)); }
    inline bool IsEjectable() const { return HasFlag(VEHICLE_SEAT_FLAG_B_EJECTABLE); }
};

struct WMOAreaTableEntry
{
    uint32  ID;                                             // 0 index
    int32   WMOID;                                          // 1 used in root WMO
    int32   NameSetID;                                      // 2 used in adt file
    int32   WMOGroupID;                                     // 3 used in group WMO
    //uint32  SoundProviderPref;                            // 4
    //uint32  SoundProviderPrefUnderwater;                  // 5
    //uint32  AmbienceID;                                   // 6
    //uint32  ZoneMusic;                                    // 7
    //uint32  IntroSound;                                   // 8
    uint32  Flags;                                          // 9 used for indoor/outdoor determination
    uint32  AreaTableID;                                    // 10 link to AreaTableEntry.ID
    //char*   AreaName;                                     // 11
    //uint32  UwIntroSound;                                 // 12
    //uint32  UwZoneMusic;                                  // 13
    //uint32  UwAmbience;                                   // 14
};

struct WorldMapAreaEntry
{
    //uint32  ID;                                           // 0
    uint32  MapID;                                          // 1
    uint32  AreaID;                                         // 2 index (continent 0 areas ignored)
    //char* AreaName                                        // 3
    float   LocLeft;                                        // 4
    float   LocRight;                                       // 5
    float   LocTop;                                         // 6
    float   LocBottom;                                      // 7
    int32   DisplayMapID;                                   // 8 -1 (map_id have correct map) other: virtual map where zone show (map_id - where zone in fact internally)
    // int32   DefaultDungeonFloor;                         // 9 pointer to DungeonMap.dbc (owerride x1, x2, y1, y2 coordinates)
    // uint32  ParentWorldMapID;                            // 10
    // uint32  Flags                                        // 11
    // uint32  LevelRangeMin;                               // 12 Minimum recommended level displayed on world map
    uint32  LevelRangeMax;                                  // 13 Maximum recommended level displayed on world map
};

#define MAX_WORLD_MAP_OVERLAY_AREA_IDX 4

struct WorldMapOverlayEntry
{
    uint32  ID;                                             // 0
    //uint32 MapAreaID;                                     // 1 idx in WorldMapArea.dbc
    uint32  AreaID[MAX_WORLD_MAP_OVERLAY_AREA_IDX];         // 2 - 5
    //char*   TextureName                                   // 6
    //uint32  TextureWidth;                                 // 7
    //uint32  TextureHeight;                                // 8
    //uint32  OffsetX;                                      // 9
    //uint32  OffsetY;                                      // 10
    //uint32  HitRectTop;                                   // 11
    //uint32  HitRectLeft;                                  // 12
    //uint32  HitRectBottom;                                // 13
    //uint32  HitRectRight;                                 // 14
};

struct WorldSafeLocsEntry
{
    uint32  ID;                                           // 0
    uint32  Continent;                                    // 1
    DBCPosition3D Loc;                                    // 2 - 4
    //char*   AreaName;                                   // 5
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

typedef std::vector<TaxiPathNodeEntry const*> TaxiPathNodeList;
typedef std::vector<TaxiPathNodeList> TaxiPathNodesByPath;

typedef std::unordered_map<uint32, std::vector<uint32>> PhaseGroupContainer;
#endif
