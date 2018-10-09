/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef _OBJECTMGR_H
#define _OBJECTMGR_H

#include "Common.h"
#include "ConditionMgr.h"
#include "Corpse.h"
#include "CreatureData.h"
#include "DatabaseEnvFwd.h"
#include "Errors.h"
#include "GameObjectData.h"
#include "ItemTemplate.h"
#include "IteratorPair.h"
#include "NPCHandler.h"
#include "ObjectDefines.h"
#include "ObjectGuid.h"
#include "Position.h"
#include "QuestDef.h"
#include "SharedDefines.h"
#include "VehicleDefines.h"
#include <map>
#include <unordered_map>

class Item;
class Unit;
class Vehicle;
class Map;
struct AccessRequirement;
struct DeclinedName;
struct DungeonEncounterEntry;
struct FactionEntry;
struct PlayerInfo;
struct PlayerLevelInfo;
struct SkillRaceClassInfoEntry;
struct WorldSafeLocsEntry;

struct PageText
{
    std::string Text;
    uint32 NextPageID;
};

enum SummonerType
{
    SUMMONER_TYPE_CREATURE      = 0,
    SUMMONER_TYPE_GAMEOBJECT    = 1,
    SUMMONER_TYPE_MAP           = 2
};

#pragma pack(push, 1)

/// Key for storing temp summon data in TempSummonDataContainer
struct TempSummonGroupKey
{
    TempSummonGroupKey(uint32 summonerEntry, SummonerType summonerType, uint8 group)
        : _summonerEntry(summonerEntry), _summonerType(summonerType), _summonGroup(group)
    {
    }

    bool operator<(TempSummonGroupKey const& rhs) const
    {
        return std::tie(_summonerEntry, _summonerType, _summonGroup) <
            std::tie(rhs._summonerEntry, rhs._summonerType, rhs._summonGroup);
    }

private:
    uint32 _summonerEntry;      ///< Summoner's entry
    SummonerType _summonerType; ///< Summoner's type, see SummonerType for available types
    uint8 _summonGroup;         ///< Summon's group id
};

#pragma pack(pop)

/// Stores data for temp summons
struct TempSummonData
{
    uint32 entry;        ///< Entry of summoned creature
    Position pos;        ///< Position, where should be creature spawned
    TempSummonType type; ///< Summon type, see TempSummonType for available types
    uint32 time;         ///< Despawn time, usable only with certain temp summon types
};

// DB scripting commands
enum ScriptCommands
{
    SCRIPT_COMMAND_TALK                  = 0,                // source/target = Creature, target = any, datalong = talk type (see ChatType enum), datalong2 & 1 = player talk (instead of creature), dataint = string_id
    SCRIPT_COMMAND_EMOTE                 = 1,                // source/target = Creature, datalong = emote id, datalong2 = 0: set emote state; > 0: play emote state
    SCRIPT_COMMAND_FIELD_SET             = 2,                // source/target = Creature, datalong = field id, datalog2 = value
    SCRIPT_COMMAND_MOVE_TO               = 3,                // source/target = Creature, datalong2 = time to reach, x/y/z = destination
    SCRIPT_COMMAND_FLAG_SET              = 4,                // source/target = Creature, datalong = field id, datalog2 = bitmask
    SCRIPT_COMMAND_FLAG_REMOVE           = 5,                // source/target = Creature, datalong = field id, datalog2 = bitmask
    SCRIPT_COMMAND_TELEPORT_TO           = 6,                // source/target = Creature/Player (see datalong2), datalong = map_id, datalong2 = 0: Player; 1: Creature, x/y/z = destination, o = orientation
    SCRIPT_COMMAND_QUEST_EXPLORED        = 7,                // target/source = Player, target/source = GO/Creature, datalong = quest id, datalong2 = distance or 0
    SCRIPT_COMMAND_KILL_CREDIT           = 8,                // target/source = Player, datalong = creature entry, datalong2 = 0: personal credit, 1: group credit
    SCRIPT_COMMAND_RESPAWN_GAMEOBJECT    = 9,                // source = WorldObject (summoner), datalong = GO guid, datalong2 = despawn delay
    SCRIPT_COMMAND_TEMP_SUMMON_CREATURE  = 10,               // source = WorldObject (summoner), datalong = creature entry, datalong2 = despawn delay, x/y/z = summon position, o = orientation
    SCRIPT_COMMAND_OPEN_DOOR             = 11,               // source = Unit, datalong = GO guid, datalong2 = reset delay (min 15)
    SCRIPT_COMMAND_CLOSE_DOOR            = 12,               // source = Unit, datalong = GO guid, datalong2 = reset delay (min 15)
    SCRIPT_COMMAND_ACTIVATE_OBJECT       = 13,               // source = Unit, target = GO
    SCRIPT_COMMAND_REMOVE_AURA           = 14,               // source (datalong2 != 0) or target (datalong2 == 0) = Unit, datalong = spell id
    SCRIPT_COMMAND_CAST_SPELL            = 15,               // source and/or target = Unit, datalong2 = cast direction (0: s->t 1: s->s 2: t->t 3: t->s 4: s->creature with dataint entry), dataint & 1 = triggered flag
    SCRIPT_COMMAND_PLAY_SOUND            = 16,               // source = WorldObject, target = none/Player, datalong = sound id, datalong2 (bitmask: 0/1=anyone/player, 0/2=without/with distance dependency, so 1|2 = 3 is target with distance dependency)
    SCRIPT_COMMAND_CREATE_ITEM           = 17,               // target/source = Player, datalong = item entry, datalong2 = amount
    SCRIPT_COMMAND_DESPAWN_SELF          = 18,               // target/source = Creature, datalong = despawn delay

    SCRIPT_COMMAND_LOAD_PATH             = 20,               // source = Unit, datalong = path id, datalong2 = is repeatable
    SCRIPT_COMMAND_CALLSCRIPT_TO_UNIT    = 21,               // source = WorldObject (if present used as a search center), datalong = script id, datalong2 = unit lowguid, dataint = script table to use (see ScriptsType)
    SCRIPT_COMMAND_KILL                  = 22,               // source/target = Creature, dataint = remove corpse attribute

    // TrinityCore only
    SCRIPT_COMMAND_ORIENTATION           = 30,               // source = Unit, target (datalong > 0) = Unit, datalong = > 0 turn source to face target, o = orientation
    SCRIPT_COMMAND_EQUIP                 = 31,               // soucre = Creature, datalong = equipment id
    SCRIPT_COMMAND_MODEL                 = 32,               // source = Creature, datalong = model id
    SCRIPT_COMMAND_CLOSE_GOSSIP          = 33,               // source = Player
    SCRIPT_COMMAND_PLAYMOVIE             = 34,               // source = Player, datalong = movie id
    SCRIPT_COMMAND_MOVEMENT              = 35,               // source = Creature, datalong = MovementType, datalong2 = MovementDistance (spawndist f.ex.), dataint = pathid
    SCRIPT_COMMAND_PLAY_ANIMKIT          = 36                // source = Creature, datalong = AnimKit id
};

enum ChatType
{
    CHAT_TYPE_SAY               = 0,
    CHAT_TYPE_YELL              = 1,
    CHAT_TYPE_TEXT_EMOTE        = 2,
    CHAT_TYPE_BOSS_EMOTE        = 3,
    CHAT_TYPE_WHISPER           = 4,
    CHAT_TYPE_BOSS_WHISPER      = 5,
    CHAT_TYPE_ZONE_YELL         = 6,
    CHAT_TYPE_END               = 255
};

// Benchmarked: Faster than std::unordered_map (insert/find)
typedef std::map<uint32, PageText> PageTextContainer;

struct InstanceTemplate
{
    uint32 Parent;
    uint32 ScriptId;
    bool AllowMount;
};

typedef std::unordered_map<uint16, InstanceTemplate> InstanceTemplateContainer;

struct GameTele
{
    float  position_x;
    float  position_y;
    float  position_z;
    float  orientation;
    uint32 mapId;
    std::string name;
    std::wstring wnameLow;
};

typedef std::unordered_map<uint32, GameTele > GameTeleContainer;

enum ScriptsType
{
    SCRIPTS_FIRST = 1,

    SCRIPTS_SPELL = SCRIPTS_FIRST,
    SCRIPTS_EVENT,
    SCRIPTS_WAYPOINT,

    SCRIPTS_LAST
};

enum eScriptFlags
{
    // Talk Flags
    SF_TALK_USE_PLAYER          = 0x1,

    // Emote flags
    SF_EMOTE_USE_STATE          = 0x1,

    // TeleportTo flags
    SF_TELEPORT_USE_CREATURE    = 0x1,

    // KillCredit flags
    SF_KILLCREDIT_REWARD_GROUP  = 0x1,

    // RemoveAura flags
    SF_REMOVEAURA_REVERSE       = 0x1,

    // CastSpell flags
    SF_CASTSPELL_SOURCE_TO_TARGET = 0,
    SF_CASTSPELL_SOURCE_TO_SOURCE = 1,
    SF_CASTSPELL_TARGET_TO_TARGET = 2,
    SF_CASTSPELL_TARGET_TO_SOURCE = 3,
    SF_CASTSPELL_SEARCH_CREATURE  = 4,
    SF_CASTSPELL_TRIGGERED      = 0x1,

    // PlaySound flags
    SF_PLAYSOUND_TARGET_PLAYER  = 0x1,
    SF_PLAYSOUND_DISTANCE_SOUND = 0x2,

    // Orientation flags
    SF_ORIENTATION_FACE_TARGET  = 0x1
};

struct ScriptInfo
{
    ScriptsType type;
    uint32 id;
    uint32 delay;
    ScriptCommands command;

    union
    {
        struct
        {
            uint32 nData[3];
            float  fData[4];
        } Raw;

        struct                      // SCRIPT_COMMAND_TALK (0)
        {
            uint32 ChatType;        // datalong
            uint32 Flags;           // datalong2
            int32  TextID;          // dataint
        } Talk;

        struct                      // SCRIPT_COMMAND_EMOTE (1)
        {
            uint32 EmoteID;         // datalong
            uint32 Flags;           // datalong2
        } Emote;

        struct                      // SCRIPT_COMMAND_FIELD_SET (2)
        {
            uint32 FieldID;         // datalong
            uint32 FieldValue;      // datalong2
        } FieldSet;

        struct                      // SCRIPT_COMMAND_MOVE_TO (3)
        {
            uint32 Unused1;         // datalong
            uint32 TravelTime;      // datalong2
            int32  Unused2;         // dataint

            float DestX;
            float DestY;
            float DestZ;
        } MoveTo;

        struct                      // SCRIPT_COMMAND_FLAG_SET (4)
                                    // SCRIPT_COMMAND_FLAG_REMOVE (5)
        {
            uint32 FieldID;         // datalong
            uint32 FieldValue;      // datalong2
        } FlagToggle;

        struct                      // SCRIPT_COMMAND_TELEPORT_TO (6)
        {
            uint32 MapID;           // datalong
            uint32 Flags;           // datalong2
            int32  Unused1;         // dataint

            float DestX;
            float DestY;
            float DestZ;
            float Orientation;
        } TeleportTo;

        struct                      // SCRIPT_COMMAND_QUEST_EXPLORED (7)
        {
            uint32 QuestID;         // datalong
            uint32 Distance;        // datalong2
        } QuestExplored;

        struct                      // SCRIPT_COMMAND_KILL_CREDIT (8)
        {
            uint32 CreatureEntry;   // datalong
            uint32 Flags;           // datalong2
        } KillCredit;

        struct                      // SCRIPT_COMMAND_RESPAWN_GAMEOBJECT (9)
        {
            ObjectGuid::LowType GOGuid;          // datalong
            uint32 DespawnDelay;    // datalong2
        } RespawnGameobject;

        struct                      // SCRIPT_COMMAND_TEMP_SUMMON_CREATURE (10)
        {
            uint32 CreatureEntry;   // datalong
            uint32 DespawnDelay;    // datalong2
            int32  Unused1;         // dataint

            float PosX;
            float PosY;
            float PosZ;
            float Orientation;
        } TempSummonCreature;

        struct                      // SCRIPT_COMMAND_CLOSE_DOOR (12)
                                    // SCRIPT_COMMAND_OPEN_DOOR (11)
        {
            ObjectGuid::LowType GOGuid;          // datalong
            uint32 ResetDelay;      // datalong2
        } ToggleDoor;

                                    // SCRIPT_COMMAND_ACTIVATE_OBJECT (13)

        struct                      // SCRIPT_COMMAND_REMOVE_AURA (14)
        {
            uint32 SpellID;         // datalong
            uint32 Flags;           // datalong2
        } RemoveAura;

        struct                      // SCRIPT_COMMAND_CAST_SPELL (15)
        {
            uint32 SpellID;         // datalong
            uint32 Flags;           // datalong2
            int32  CreatureEntry;   // dataint

            float SearchRadius;
        } CastSpell;

        struct                      // SCRIPT_COMMAND_PLAY_SOUND (16)
        {
            uint32 SoundID;         // datalong
            uint32 Flags;           // datalong2
        } PlaySound;

        struct                      // SCRIPT_COMMAND_CREATE_ITEM (17)
        {
            uint32 ItemEntry;       // datalong
            uint32 Amount;          // datalong2
        } CreateItem;

        struct                      // SCRIPT_COMMAND_DESPAWN_SELF (18)
        {
            uint32 DespawnDelay;    // datalong
        } DespawnSelf;

        struct                      // SCRIPT_COMMAND_LOAD_PATH (20)
        {
            uint32 PathID;          // datalong
            uint32 IsRepeatable;    // datalong2
        } LoadPath;

        struct                      // SCRIPT_COMMAND_CALLSCRIPT_TO_UNIT (21)
        {
            uint32 CreatureEntry;   // datalong
            uint32 ScriptID;        // datalong2
            uint32 ScriptType;      // dataint
        } CallScript;

        struct                      // SCRIPT_COMMAND_KILL (22)
        {
            uint32 Unused1;         // datalong
            uint32 Unused2;         // datalong2
            int32  RemoveCorpse;    // dataint
        } Kill;

        struct                      // SCRIPT_COMMAND_ORIENTATION (30)
        {
            uint32 Flags;           // datalong
            uint32 Unused1;         // datalong2
            int32  Unused2;         // dataint

            float Unused3;
            float Unused4;
            float Unused5;
            float Orientation;
        } Orientation;

        struct                      // SCRIPT_COMMAND_EQUIP (31)
        {
            uint32 EquipmentID;     // datalong
        } Equip;

        struct                      // SCRIPT_COMMAND_MODEL (32)
        {
            uint32 ModelID;         // datalong
        } Model;

                                    // SCRIPT_COMMAND_CLOSE_GOSSIP (33)

        struct                      // SCRIPT_COMMAND_PLAYMOVIE (34)
        {
            uint32 MovieID;         // datalong
        } PlayMovie;

        struct                       // SCRIPT_COMMAND_MOVEMENT (35)
        {
            uint32 MovementType;     // datalong
            uint32 MovementDistance; // datalong2
            int32  Path;             // dataint
        } Movement;


        struct                      // SCRIPT_COMMAND_PLAY_ANIMKIT (35)
        {
            uint32 AnimKitID;       // datalong
        } PlayAnimKit;
    };

    std::string GetDebugInfo() const;
};

typedef std::multimap<uint32, ScriptInfo> ScriptMap;
typedef std::map<uint32, ScriptMap > ScriptMapMap;
typedef std::multimap<uint32 /*spell id*/, std::pair<uint32 /*script id*/, bool /*enabled*/>> SpellScriptsContainer;
typedef std::pair<SpellScriptsContainer::iterator, SpellScriptsContainer::iterator> SpellScriptsBounds;
TC_GAME_API extern ScriptMapMap sSpellScripts;
TC_GAME_API extern ScriptMapMap sEventScripts;
TC_GAME_API extern ScriptMapMap sWaypointScripts;

std::string GetScriptsTableNameByType(ScriptsType type);
ScriptMapMap* GetScriptsMapByType(ScriptsType type);
std::string GetScriptCommandName(ScriptCommands command);

struct TC_GAME_API InstanceSpawnGroupInfo
{
    enum
    {
        FLAG_ACTIVATE_SPAWN = 0x01,
        FLAG_BLOCK_SPAWN = 0x02,

        FLAG_ALL = (FLAG_ACTIVATE_SPAWN | FLAG_BLOCK_SPAWN)
    };
    uint8 BossStateId;
    uint8 BossStates;
    uint32 SpawnGroupId;
    uint8 Flags;
};

struct TC_GAME_API SpellClickInfo
{
    uint32 spellId;
    uint8 castFlags;
    SpellClickUserTypes userType;

    // helpers
    bool IsFitToRequirements(Unit const* clicker, Unit const* clickee) const;
};

typedef std::multimap<uint32, SpellClickInfo> SpellClickInfoContainer;
typedef std::pair<SpellClickInfoContainer::const_iterator, SpellClickInfoContainer::const_iterator> SpellClickInfoMapBounds;

struct AreaTriggerStruct
{
    uint32 target_mapId;
    float  target_X;
    float  target_Y;
    float  target_Z;
    float  target_Orientation;
};

struct AccessRequirement
{
    uint8  levelMin;
    uint8  levelMax;
    uint32 item;
    uint32 item2;
    uint32 quest_A;
    uint32 quest_H;
    uint32 achievement;
    std::string questFailedText;
};

struct BroadcastText
{
    BroadcastText() : Id(0), Language(0), EmoteId0(0), EmoteId1(0), EmoteId2(0),
                      EmoteDelay0(0), EmoteDelay1(0), EmoteDelay2(0), SoundId(0), Unk1(0), Unk2(0)
    {
        MaleText.resize(DEFAULT_LOCALE + 1);
        FemaleText.resize(DEFAULT_LOCALE + 1);
    }

    uint32 Id;
    uint32 Language;
    std::vector<std::string> MaleText;
    std::vector<std::string> FemaleText;
    uint32 EmoteId0;
    uint32 EmoteId1;
    uint32 EmoteId2;
    uint32 EmoteDelay0;
    uint32 EmoteDelay1;
    uint32 EmoteDelay2;
    uint32 SoundId;
    uint32 Unk1;
    uint32 Unk2;
    // uint32 VerifiedBuild;

    std::string const& GetText(LocaleConstant locale = DEFAULT_LOCALE, uint8 gender = GENDER_MALE, bool forceGender = false) const
    {
        if ((gender == GENDER_FEMALE || gender == GENDER_NONE) && (forceGender || !FemaleText[DEFAULT_LOCALE].empty()))
        {
            if (FemaleText.size() > size_t(locale) && !FemaleText[locale].empty())
                return FemaleText[locale];
            return FemaleText[DEFAULT_LOCALE];
        }
        // else if (gender == GENDER_MALE)
        {
            if (MaleText.size() > size_t(locale) && !MaleText[locale].empty())
                return MaleText[locale];
            return MaleText[DEFAULT_LOCALE];
        }
    }
};

typedef std::unordered_map<uint32, BroadcastText> BroadcastTextContainer;

typedef std::set<ObjectGuid::LowType> CellGuidSet;
struct CellObjectGuids
{
    CellGuidSet creatures;
    CellGuidSet gameobjects;
};
typedef std::unordered_map<uint32/*cell_id*/, CellObjectGuids> CellObjectGuidsMap;
typedef std::unordered_map<uint32/*(mapid, spawnMode) pair*/, CellObjectGuidsMap> MapObjectGuids;

// Trinity Trainer Reference start range
#define TRINITY_TRAINER_START_REF      200000

typedef std::map<ObjectGuid, ObjectGuid> LinkedRespawnContainer;
typedef std::unordered_map<uint32, CreatureTemplate> CreatureTemplateContainer;
typedef std::unordered_map<uint32, CreatureAddon> CreatureTemplateAddonContainer;
typedef std::unordered_map<ObjectGuid::LowType, CreatureData> CreatureDataContainer;
typedef std::unordered_map<ObjectGuid::LowType, CreatureAddon> CreatureAddonContainer;
typedef std::unordered_map<uint16, CreatureBaseStats> CreatureBaseStatsContainer;
typedef std::unordered_map<uint8, EquipmentInfo> EquipmentInfoContainerInternal;
typedef std::unordered_map<uint32, EquipmentInfoContainerInternal> EquipmentInfoContainer;
typedef std::unordered_map<uint32, CreatureModelInfo> CreatureModelContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> CreatureQuestItemMap;
typedef std::unordered_map<uint32, GameObjectTemplate> GameObjectTemplateContainer;
typedef std::unordered_map<uint32, GameObjectTemplateAddon> GameObjectTemplateAddonContainer;
typedef std::unordered_map<ObjectGuid::LowType, GameObjectData> GameObjectDataContainer;
typedef std::unordered_map<ObjectGuid::LowType, GameObjectAddon> GameObjectAddonContainer;
typedef std::unordered_map<uint32, std::vector<uint32>> GameObjectQuestItemMap;
typedef std::unordered_map<uint32, SpawnGroupTemplateData> SpawnGroupDataContainer;
typedef std::multimap<uint32, SpawnData const*> SpawnGroupLinkContainer;
typedef std::unordered_map<uint16, std::vector<InstanceSpawnGroupInfo>> InstanceSpawnGroupContainer;
typedef std::map<TempSummonGroupKey, std::vector<TempSummonData>> TempSummonDataContainer;
typedef std::unordered_map<uint32, CreatureLocale> CreatureLocaleContainer;
typedef std::unordered_map<uint32, GameObjectLocale> GameObjectLocaleContainer;
typedef std::unordered_map<uint32, ItemTemplate> ItemTemplateContainer;
typedef std::unordered_map<uint32, ItemLocale> ItemLocaleContainer;
typedef std::unordered_map<uint32, QuestLocale> QuestLocaleContainer;
typedef std::unordered_map<uint32, QuestOfferRewardLocale> QuestOfferRewardLocaleContainer;
typedef std::unordered_map<uint32, QuestRequestItemsLocale> QuestRequestItemsLocaleContainer;
typedef std::unordered_map<uint32, NpcTextLocale> NpcTextLocaleContainer;
typedef std::unordered_map<uint32, PageTextLocale> PageTextLocaleContainer;

struct GossipMenuItemsLocale
{
    std::vector<std::string> OptionText;
    std::vector<std::string> BoxText;
};

typedef std::unordered_map<uint32, GossipMenuItemsLocale> GossipMenuItemsLocaleContainer;

struct PointOfInterestLocale
{
    std::vector<std::string> Name;
};

typedef std::unordered_map<uint32, PointOfInterestLocale> PointOfInterestLocaleContainer;

struct QuestGreetingLocale
{
    std::vector<std::string> greeting;
};

typedef std::unordered_map<uint32, QuestGreetingLocale> QuestGreetingLocaleContainer;

struct TrinityString
{
    std::vector<std::string> Content;
};

typedef std::unordered_map<uint32, TrinityString> TrinityStringContainer;

typedef std::multimap<uint32, uint32> QuestRelations; // unit/go -> quest
typedef std::multimap<uint32, uint32> QuestRelationsReverse; // quest -> unit/go
typedef std::pair<QuestRelations::const_iterator, QuestRelations::const_iterator> QuestRelationBounds;
typedef std::pair<QuestRelationsReverse::const_iterator, QuestRelationsReverse::const_iterator> QuestRelationReverseBounds;

struct PlayerCreateInfoItem
{
    PlayerCreateInfoItem(uint32 id, uint32 amount) : item_id(id), item_amount(amount) { }

    uint32 item_id;
    uint32 item_amount;
};

typedef std::vector<PlayerCreateInfoItem> PlayerCreateInfoItems;

struct PlayerLevelInfo
{
    PlayerLevelInfo() { for (uint8 i = 0; i < MAX_STATS; ++i) stats[i] = 0; }

    uint8 stats[MAX_STATS];
};

typedef std::vector<uint32> PlayerCreateInfoSpells;

struct PlayerCreateInfoAction
{
    PlayerCreateInfoAction(uint8 _button, uint32 _action, uint8 _type) : button(_button), type(_type), action(_action) { }

    uint8 button;
    uint8 type;
    uint32 action;
};

typedef std::vector<PlayerCreateInfoAction> PlayerCreateInfoActions;

struct PlayerCreateInfoSkill
{
    uint16 SkillId;
    uint16 Rank;
};

typedef std::vector<PlayerCreateInfoSkill> PlayerCreateInfoSkills;

// existence checked by displayId != 0
struct PlayerInfo
{
    uint32 mapId = 0;
    uint32 areaId = 0;
    float positionX = 0.0f;
    float positionY = 0.0f;
    float positionZ = 0.0f;
    float orientation = 0.0f;
    uint16 displayId_m = 0;
    uint16 displayId_f = 0;
    PlayerCreateInfoItems item;
    PlayerCreateInfoSpells customSpells;
    PlayerCreateInfoSpells castSpells;
    PlayerCreateInfoActions action;
    PlayerCreateInfoSkills skills;

    //[level-1] 0..MaxPlayerLevel-1
    PlayerLevelInfo* levelInfo = nullptr;
};


struct PetLevelInfo
{
    uint16 stats[MAX_STATS] = { };
    uint16 health = 0;
    uint16 mana = 0;
    uint16 armor = 0;
};

struct MailLevelReward
{
    MailLevelReward() : raceMask(0), mailTemplateId(0), senderEntry(0) { }
    MailLevelReward(uint32 _raceMask, uint32 _mailTemplateId, uint32 _senderEntry) : raceMask(_raceMask), mailTemplateId(_mailTemplateId), senderEntry(_senderEntry) { }

    uint32 raceMask;
    uint32 mailTemplateId;
    uint32 senderEntry;
};

typedef std::list<MailLevelReward> MailLevelRewardList;
typedef std::unordered_map<uint8, MailLevelRewardList> MailLevelRewardContainer;

// We assume the rate is in general the same for all three types below, but chose to keep three for scalability and customization
struct RepRewardRate
{
    float questRate;            // We allow rate = 0.0 in database. For this case, it means that
    float questDailyRate;
    float questWeeklyRate;
    float questMonthlyRate;
    float questRepeatableRate;
    float creatureRate;         // no reputation are given at all for this faction/rate type.
    float spellRate;
};

struct ReputationOnKillEntry
{
    uint32 RepFaction1;
    uint32 RepFaction2;
    uint32 ReputationMaxCap1;
    int32 RepValue1;
    uint32 ReputationMaxCap2;
    int32 RepValue2;
    bool IsTeamAward1;
    bool IsTeamAward2;
    bool TeamDependent;
};

struct RepSpilloverTemplate
{
    uint32 faction[MAX_SPILLOVER_FACTIONS];
    float faction_rate[MAX_SPILLOVER_FACTIONS];
    uint32 faction_rank[MAX_SPILLOVER_FACTIONS];
};

struct PointOfInterest
{
    uint32 ID;
    float PositionX;
    float PositionY;
    uint32 Icon;
    uint32 Flags;
    uint32 Importance;
    std::string Name;
};

struct GossipMenuItems
{
    uint32              MenuID;
    uint32              OptionID;
    uint8               OptionIcon;
    std::string         OptionText;
    uint32              OptionBroadcastTextID;
    uint32              OptionType;
    uint32              OptionNpcFlag;
    uint32              ActionMenuID;
    uint32              ActionPoiID;
    bool                BoxCoded;
    uint32              BoxMoney;
    std::string         BoxText;
    uint32              BoxBroadcastTextID;
    ConditionContainer  Conditions;
};

struct GossipMenus
{
    uint32              MenuID;
    uint32              TextID;
    ConditionContainer  Conditions;
};

typedef std::multimap<uint32, GossipMenus> GossipMenusContainer;
typedef std::pair<GossipMenusContainer::const_iterator, GossipMenusContainer::const_iterator> GossipMenusMapBounds;
typedef std::pair<GossipMenusContainer::iterator, GossipMenusContainer::iterator> GossipMenusMapBoundsNonConst;
typedef std::multimap<uint32, GossipMenuItems> GossipMenuItemsContainer;
typedef std::pair<GossipMenuItemsContainer::const_iterator, GossipMenuItemsContainer::const_iterator> GossipMenuItemsMapBounds;
typedef std::pair<GossipMenuItemsContainer::iterator, GossipMenuItemsContainer::iterator> GossipMenuItemsMapBoundsNonConst;

struct QuestPOIPoint
{
    int32 x;
    int32 y;

    QuestPOIPoint() : x(0), y(0) { }
    QuestPOIPoint(int32 _x, int32 _y) : x(_x), y(_y) { }
};

struct QuestPOI
{
    uint32 Id;
    int32 ObjectiveIndex;
    uint32 MapId;
    uint32 AreaId;
    uint32 FloorId;
    uint32 Unk3;
    uint32 Unk4;
    std::vector<QuestPOIPoint> points;

    QuestPOI() : Id(0), ObjectiveIndex(0), MapId(0), AreaId(0), FloorId(0), Unk3(0), Unk4(0) { }
    QuestPOI(uint32 id, int32 objIndex, uint32 mapId, uint32 areaId, uint32 floorId, uint32 unk3, uint32 unk4) : Id(id), ObjectiveIndex(objIndex), MapId(mapId), AreaId(areaId), FloorId(floorId), Unk3(unk3), Unk4(unk4) { }
};

typedef std::vector<QuestPOI> QuestPOIVector;
typedef std::unordered_map<uint32, QuestPOIVector> QuestPOIContainer;

struct QuestGreeting
{
    uint16 greetEmoteType;
    uint32 greetEmoteDelay;
    std::string greeting;

    QuestGreeting() : greetEmoteType(0), greetEmoteDelay(0) { }
    QuestGreeting(uint16 _greetEmoteType, uint32 _greetEmoteDelay, std::string _greeting)
        : greetEmoteType(_greetEmoteType), greetEmoteDelay(_greetEmoteDelay), greeting(_greeting) { }
};

typedef std::unordered_map<uint8, std::unordered_map<uint32, QuestGreeting>> QuestGreetingContainer;

struct GraveyardData
{
    uint32 safeLocId;
    uint32 team;
};

typedef std::multimap<uint32, GraveyardData> GraveyardContainer;
typedef std::unordered_map<uint32 /* graveyard Id */, float /* orientation */> GraveyardOrientationContainer;
typedef std::pair<GraveyardContainer::const_iterator, GraveyardContainer::const_iterator> GraveyardMapBounds;
typedef std::pair<GraveyardContainer::iterator, GraveyardContainer::iterator> GraveyardMapBoundsNonConst;

typedef std::unordered_map<uint32, VendorItemData> CacheVendorItemContainer;
typedef std::unordered_map<uint32, TrainerSpellData> CacheTrainerSpellContainer;

enum SkillRangeType
{
    SKILL_RANGE_LANGUAGE,                                   // 300..300
    SKILL_RANGE_LEVEL,                                      // 1..max skill for level
    SKILL_RANGE_MONO,                                       // 1..1, grey monolite bar
    SKILL_RANGE_RANK,                                       // 1..skill for known rank
    SKILL_RANGE_NONE                                        // 0..0 always
};

SkillRangeType GetSkillRangeType(SkillRaceClassInfoEntry const* rcEntry);

#define MAX_PLAYER_NAME          12                         // max allowed by client name length
#define MAX_INTERNAL_PLAYER_NAME 15                         // max server internal player name length (> MAX_PLAYER_NAME for support declined names)
#define MAX_PET_NAME             12                         // max allowed by client name length
#define MAX_CHARTER_NAME         24                         // max allowed by client name length

bool TC_GAME_API normalizePlayerName(std::string& name);
#define SPAWNGROUP_MAP_UNSET            0xFFFFFFFF

struct LanguageDesc
{
    Language lang_id;
    uint32   spell_id;
    uint32   skill_id;
};

TC_GAME_API extern LanguageDesc lang_description[LANGUAGES_COUNT];
LanguageDesc const* GetLanguageDescByID(uint32 lang);

enum EncounterCreditType : uint8
{
    ENCOUNTER_CREDIT_KILL_CREATURE  = 0,
    ENCOUNTER_CREDIT_CAST_SPELL     = 1
};

struct DungeonEncounter
{
    DungeonEncounter(DungeonEncounterEntry const* _dbcEntry, EncounterCreditType _creditType, uint32 _creditEntry, uint32 _lastEncounterDungeon)
        : dbcEntry(_dbcEntry), creditType(_creditType), creditEntry(_creditEntry), lastEncounterDungeon(_lastEncounterDungeon) { }

    DungeonEncounterEntry const* dbcEntry;
    EncounterCreditType creditType;
    uint32 creditEntry;
    uint32 lastEncounterDungeon;
};

typedef std::list<DungeonEncounter const*> DungeonEncounterList;
typedef std::unordered_map<uint32, DungeonEncounterList> DungeonEncounterContainer;

struct HotfixInfo
{
    uint32 Type;
    uint32 Timestamp;
    uint32 Entry;
};

typedef std::vector<HotfixInfo> HotfixData;

struct TerrainSwapInfo
{
    uint32 Id;
    std::vector<uint32> UiWorldMapAreaIDSwaps;
};

struct PhaseInfoStruct
{
    uint32 Id;
    std::unordered_set<uint32> Areas;

    bool IsAllowedInArea(uint32 areaId) const;
};

struct PhaseAreaInfo
{
    PhaseAreaInfo(PhaseInfoStruct const* phaseInfo) : PhaseInfo(phaseInfo) { }

    PhaseInfoStruct const* PhaseInfo;
    std::unordered_set<uint32> SubAreaExclusions;
    ConditionContainer Conditions;
};

class PlayerDumpReader;

class TC_GAME_API ObjectMgr
{
    friend class PlayerDumpReader;

    private:
        ObjectMgr();
        ~ObjectMgr();

    public:
        ObjectMgr(ObjectMgr const&) = delete;
        ObjectMgr(ObjectMgr&&) = delete;

        ObjectMgr& operator= (ObjectMgr const&) = delete;
        ObjectMgr& operator= (ObjectMgr&&) = delete;

        static ObjectMgr* instance();

        typedef std::unordered_map<uint32, Quest*> QuestMap;

        typedef std::unordered_map<uint32, AreaTriggerStruct> AreaTriggerContainer;

        typedef std::unordered_map<uint32, uint32> AreaTriggerScriptContainer;

        typedef std::unordered_map<uint32, AccessRequirement*> AccessRequirementContainer;

        typedef std::unordered_map<uint32, RepRewardRate > RepRewardRateContainer;
        typedef std::unordered_map<uint32, ReputationOnKillEntry> RepOnKillContainer;
        typedef std::unordered_map<uint32, RepSpilloverTemplate> RepSpilloverTemplateContainer;

        typedef std::unordered_map<uint32, PointOfInterest> PointOfInterestContainer;

        typedef std::vector<std::string> ScriptNameContainer;

        typedef std::map<uint32, uint32> CharacterConversionMap;

        GameObjectTemplate const* GetGameObjectTemplate(uint32 entry) const;
        GameObjectTemplateContainer const* GetGameObjectTemplates() const { return &_gameObjectTemplateStore; }
        int LoadReferenceVendor(int32 vendor, int32 item, uint8 type, std::set<uint32> *skip_vendors);

        void LoadGameObjectTemplate();
        void LoadGameObjectTemplateAddons();
        void AddGameobjectInfo(GameObjectTemplate* goinfo);

        CreatureTemplate const* GetCreatureTemplate(uint32 entry) const;
        CreatureTemplateContainer const* GetCreatureTemplates() const { return &_creatureTemplateStore; }
        CreatureModelInfo const* GetCreatureModelInfo(uint32 modelId) const;
        CreatureModelInfo const* GetCreatureModelRandomGender(uint32* displayID) const;
        static uint32 ChooseDisplayId(CreatureTemplate const* cinfo, CreatureData const* data = nullptr);
        static void ChooseCreatureFlags(CreatureTemplate const* cinfo, uint32& npcflag, uint32& unit_flags, uint32& dynamicflags, CreatureData const* data = nullptr);
        EquipmentInfo const* GetEquipmentInfo(uint32 entry, int8& id) const;
        CreatureAddon const* GetCreatureAddon(ObjectGuid::LowType lowguid) const;
        GameObjectAddon const* GetGameObjectAddon(ObjectGuid::LowType lowguid) const;
        GameObjectTemplateAddon const* GetGameObjectTemplateAddon(uint32 entry) const;
        CreatureAddon const* GetCreatureTemplateAddon(uint32 entry) const;
        ItemTemplate const* GetItemTemplate(uint32 entry) const;
        ItemTemplateContainer const* GetItemTemplateStore() const { return &_itemTemplateStore; }

        InstanceTemplateContainer const& GetInstanceTemplates() const { return _instanceTemplateStore; }
        InstanceTemplate const* GetInstanceTemplate(uint32 mapId) const;

        PetLevelInfo const* GetPetLevelInfo(uint32 creature_id, uint8 level) const;

        void GetPlayerClassLevelInfo(uint32 class_, uint8 level, uint32& baseHP, uint32& baseMana) const;

        PlayerInfo const* GetPlayerInfo(uint32 race, uint32 class_) const;

        void GetPlayerLevelInfo(uint32 race, uint32 class_, uint8 level, PlayerLevelInfo* info) const;

        std::vector<uint32> const* GetGameObjectQuestItemList(uint32 id) const
        {
            GameObjectQuestItemMap::const_iterator itr = _gameObjectQuestItemStore.find(id);
            if (itr != _gameObjectQuestItemStore.end())
                return &itr->second;
            return nullptr;
        }
        GameObjectQuestItemMap const* GetGameObjectQuestItemMap() const { return &_gameObjectQuestItemStore; }

        std::vector<uint32> const* GetCreatureQuestItemList(uint32 id) const
        {
            CreatureQuestItemMap::const_iterator itr = _creatureQuestItemStore.find(id);
            if (itr != _creatureQuestItemStore.end())
                return &itr->second;
            return nullptr;
        }
        CreatureQuestItemMap const* GetCreatureQuestItemMap() const { return &_creatureQuestItemStore; }

        uint32 GetNearestTaxiNode(float x, float y, float z, uint32 mapid, uint32 team);
        void GetTaxiPath(uint32 source, uint32 destination, uint32 &path, uint32 &cost);
        uint32 GetTaxiMountDisplayId(uint32 id, uint32 team, bool allowed_alt_team = false);

        Quest const* GetQuestTemplate(uint32 quest_id) const
        {
            QuestMap::const_iterator itr = _questTemplates.find(quest_id);
            return itr != _questTemplates.end() ? itr->second : nullptr;
        }

        QuestMap const& GetQuestTemplates() const { return _questTemplates; }

        uint32 GetQuestForAreaTrigger(uint32 Trigger_ID) const
        {
            QuestAreaTriggerContainer::const_iterator itr = _questAreaTriggerStore.find(Trigger_ID);
            if (itr != _questAreaTriggerStore.end())
                return itr->second;
            return 0;
        }

        bool IsTavernAreaTrigger(uint32 Trigger_ID) const
        {
            return _tavernAreaTriggerStore.find(Trigger_ID) != _tavernAreaTriggerStore.end();
        }

        bool IsGameObjectForQuests(uint32 entry) const
        {
            return _gameObjectForQuestStore.find(entry) != _gameObjectForQuestStore.end();
        }

        GossipText const* GetGossipText(uint32 Text_ID) const;
        QuestGreeting const* GetQuestGreeting(ObjectGuid guid) const;

        WorldSafeLocsEntry const* GetDefaultGraveyard(uint32 team) const;
        WorldSafeLocsEntry const* GetClosestGraveyard(WorldLocation const& location, uint32 team, WorldObject* conditionObject) const;
        bool AddGraveyardLink(uint32 id, uint32 zoneId, uint32 team, bool persist = true);
        void RemoveGraveyardLink(uint32 id, uint32 zoneId, uint32 team, bool persist = false);
        void LoadGraveyardZones();
        GraveyardData const* FindGraveyardData(uint32 id, uint32 zone) const;

        AreaTriggerStruct const* GetAreaTrigger(uint32 trigger) const;
        AccessRequirement const* GetAccessRequirement(uint32 mapid, Difficulty difficulty) const;
        AreaTriggerStruct const* GetGoBackTrigger(uint32 Map) const;
        AreaTriggerStruct const* GetMapEntranceTrigger(uint32 Map) const;

        uint32 GetAreaTriggerScriptId(uint32 trigger_id) const;
        SpellScriptsBounds GetSpellScriptsBounds(uint32 spellId);

        RepRewardRate const* GetRepRewardRate(uint32 factionId) const
        {
            RepRewardRateContainer::const_iterator itr = _repRewardRateStore.find(factionId);
            if (itr != _repRewardRateStore.end())
                return &itr->second;

            return nullptr;
        }

        ReputationOnKillEntry const* GetReputationOnKilEntry(uint32 id) const
        {
            RepOnKillContainer::const_iterator itr = _repOnKillStore.find(id);
            if (itr != _repOnKillStore.end())
                return &itr->second;
            return nullptr;
        }

        int32 GetBaseReputationOf(FactionEntry const* factionEntry, uint8 race, uint8 playerClass) const;

        RepSpilloverTemplate const* GetRepSpilloverTemplate(uint32 factionId) const
        {
            RepSpilloverTemplateContainer::const_iterator itr = _repSpilloverTemplateStore.find(factionId);
            if (itr != _repSpilloverTemplateStore.end())
                return &itr->second;

            return nullptr;
        }

        PointOfInterest const* GetPointOfInterest(uint32 id) const
        {
            PointOfInterestContainer::const_iterator itr = _pointsOfInterestStore.find(id);
            if (itr != _pointsOfInterestStore.end())
                return &itr->second;
            return nullptr;
        }

        QuestPOIVector const* GetQuestPOIVector(uint32 questId)
        {
            QuestPOIContainer::const_iterator itr = _questPOIStore.find(questId);
            if (itr != _questPOIStore.end())
                return &itr->second;
            return nullptr;
        }

        VehicleAccessoryList const* GetVehicleAccessoryList(Vehicle* veh) const;

        DungeonEncounterList const* GetDungeonEncounterList(uint32 mapId, Difficulty difficulty) const;

        void LoadQuests();
        void LoadQuestStartersAndEnders();
        void LoadGameobjectQuestStarters();
        void LoadGameobjectQuestEnders();
        void LoadCreatureQuestStarters();
        void LoadCreatureQuestEnders();

        QuestRelations* GetGOQuestRelationMap()
        {
            return &_goQuestRelations;
        }

        QuestRelationBounds GetGOQuestRelationBounds(uint32 go_entry) const
        {
            return _goQuestRelations.equal_range(go_entry);
        }

        QuestRelationBounds GetGOQuestInvolvedRelationBounds(uint32 go_entry) const
        {
            return _goQuestInvolvedRelations.equal_range(go_entry);
        }

        QuestRelationReverseBounds GetGOQuestInvolvedRelationReverseBounds(uint32 questId) const
        {
            return _goQuestInvolvedRelationsReverse.equal_range(questId);
        }

        QuestRelations* GetCreatureQuestRelationMap()
        {
            return &_creatureQuestRelations;
        }

        QuestRelationBounds GetCreatureQuestRelationBounds(uint32 creature_entry) const
        {
            return _creatureQuestRelations.equal_range(creature_entry);
        }

        QuestRelationBounds GetCreatureQuestInvolvedRelationBounds(uint32 creature_entry) const
        {
            return _creatureQuestInvolvedRelations.equal_range(creature_entry);
        }

        QuestRelationReverseBounds GetCreatureQuestInvolvedRelationReverseBounds(uint32 questId) const
        {
            return _creatureQuestInvolvedRelationsReverse.equal_range(questId);
        }

        bool LoadTrinityStrings();

        void LoadEventScripts();
        void LoadSpellScripts();
        void LoadWaypointScripts();

        void LoadSpellScriptNames();
        void ValidateSpellScripts();

        void LoadBroadcastTexts();
        void LoadBroadcastTextLocales();
        void LoadCreatureClassLevelStats();
        void LoadCreatureLocales();
        void LoadGraveyardOrientations();
        void LoadCreatureTemplates();
        void LoadCreatureTemplateAddons();
        void LoadCreatureTemplate(Field* fields);
        void CheckCreatureTemplate(CreatureTemplate const* cInfo);
        void LoadGameObjectQuestItems();
        void LoadCreatureQuestItems();
        void LoadTempSummons();
        void LoadCreatures();
        void LoadLinkedRespawn();
        bool SetCreatureLinkedRespawn(ObjectGuid::LowType guid, ObjectGuid::LowType linkedGuid);
        void LoadCreatureAddons();
        void LoadGameObjectAddons();
        void LoadCreatureModelInfo();
        void LoadEquipmentTemplates();
        void LoadGameObjectLocales();
        void LoadGameObjects();
        void LoadSpawnGroupTemplates();
        void LoadSpawnGroups();
        void LoadInstanceSpawnGroups();
        void LoadItemTemplates();
        void LoadItemTemplateAddon();
        void LoadItemScriptNames();
        void LoadItemLocales();
        void LoadQuestLocales();
        void LoadNpcTextLocales();
        void LoadQuestOfferRewardLocale();
        void LoadQuestRequestItemsLocale();
        void LoadPageTextLocales();
        void LoadGossipMenuItemsLocales();
        void LoadPointOfInterestLocales();
        void LoadQuestGreetingLocales();
        void LoadInstanceTemplate();
        void LoadInstanceEncounters();
        void LoadMailLevelRewards();
        void LoadVehicleTemplateAccessories();
        void LoadVehicleAccessories();

        void LoadGossipText();

        void LoadAreaTriggerTeleports();
        void LoadAccessRequirements();
        void LoadQuestAreaTriggers();
        void LoadQuestGreetings();
        void LoadAreaTriggerScripts();
        void LoadTavernAreaTriggers();
        void LoadGameObjectForQuests();

        void LoadPageTexts();
        PageText const* GetPageText(uint32 pageEntry);

        void LoadPlayerInfo();
        void LoadPetLevelInfo();
        void LoadExplorationBaseXP();
        void LoadPetNames();
        void LoadPetNumber();
        void LoadFishingBaseSkillLevel();

        void LoadReputationRewardRate();
        void LoadReputationOnKill();
        void LoadReputationSpilloverTemplate();

        void LoadPointsOfInterest();
        void LoadQuestPOI();

        void LoadNPCSpellClickSpells();

        void LoadGameTele();

        void LoadGossipMenu();
        void LoadGossipMenuItems();

        void LoadVendors();
        void LoadTrainerSpell();
        void AddSpellToTrainer(uint32 ID, uint32 SpellID, uint32 MoneyCost, uint32 ReqSkillLine, uint32 ReqSkillRank, uint32 ReqLevel, uint32 Index);

        void LoadPhases();
        void UnloadPhaseConditions();
        void LoadTerrainSwapDefaults();
        void LoadTerrainWorldMaps();
        void LoadAreaPhases();

        std::string GeneratePetName(uint32 entry) const;
        uint32 GetBaseXP(uint8 level);
        uint32 GetXPForLevel(uint8 level) const;

        int32 GetFishingBaseSkillLevel(uint32 entry) const
        {
            FishingBaseSkillContainer::const_iterator itr = _fishingBaseForAreaStore.find(entry);
            return itr != _fishingBaseForAreaStore.end() ? itr->second : 0;
        }

        void ReturnOrDeleteOldMails(bool serverUp);

        CreatureBaseStats const* GetCreatureBaseStats(uint8 level, uint8 unitClass);

        void SetHighestGuids();

        template<HighGuid type>
        inline ObjectGuidGeneratorBase& GetGenerator()
        {
            static_assert(ObjectGuidTraits<type>::Global, "Only global guid can be generated in ObjectMgr context");
            return GetGuidSequenceGenerator<type>();
        }

        uint32 GenerateAuctionID();
        uint64 GenerateEquipmentSetGuid();
        uint32 GenerateMailID();
        uint32 GeneratePetNumber();
        uint64 GenerateVoidStorageItemId();
        ObjectGuid::LowType GenerateCreatureSpawnId();
        ObjectGuid::LowType GenerateGameObjectSpawnId();

        SpawnGroupTemplateData const* GetSpawnGroupData(uint32 groupId) const { auto it = _spawnGroupDataStore.find(groupId); return it != _spawnGroupDataStore.end() ? &it->second : nullptr; }
        SpawnGroupTemplateData const* GetDefaultSpawnGroup() const { return &_spawnGroupDataStore.at(0); }
        SpawnGroupTemplateData const* GetLegacySpawnGroup() const { return &_spawnGroupDataStore.at(1); }
        Trinity::IteratorPair<SpawnGroupLinkContainer::const_iterator> GetSpawnDataForGroup(uint32 groupId) const { return Trinity::Containers::MapEqualRange(_spawnGroupMapStore, groupId); }
        std::vector<InstanceSpawnGroupInfo> const* GetSpawnGroupsForInstance(uint32 instanceId) const { auto it = _instanceSpawnGroupStore.find(instanceId); return it != _instanceSpawnGroupStore.end() ? &it->second : nullptr; }

        typedef std::multimap<int32, uint32> ExclusiveQuestGroups;
        typedef std::pair<ExclusiveQuestGroups::const_iterator, ExclusiveQuestGroups::const_iterator> ExclusiveQuestGroupsBounds;

        ExclusiveQuestGroups mExclusiveQuestGroups;

        MailLevelReward const* GetMailLevelReward(uint32 level, uint32 raceMask) const
        {
            MailLevelRewardContainer::const_iterator map_itr = _mailLevelRewardStore.find(level);
            if (map_itr == _mailLevelRewardStore.end())
                return nullptr;

            for (MailLevelRewardList::const_iterator set_itr = map_itr->second.begin(); set_itr != map_itr->second.end(); ++set_itr)
                if (set_itr->raceMask & raceMask)
                    return &*set_itr;

            return nullptr;
        }

        CellObjectGuids const& GetCellObjectGuids(uint16 mapid, uint8 spawnMode, uint32 cell_id)
        {
            return _mapObjectGuidsStore[MAKE_PAIR32(mapid, spawnMode)][cell_id];
        }

        CellObjectGuidsMap const& GetMapObjectGuids(uint16 mapid, uint8 spawnMode)
        {
            return _mapObjectGuidsStore[MAKE_PAIR32(mapid, spawnMode)];
        }

        /**
         * Gets temp summon data for all creatures of specified group.
         *
         * @param summonerId   Summoner's entry.
         * @param summonerType Summoner's type, see SummonerType for available types.
         * @param group        Id of required group.
         *
         * @return null if group was not found, otherwise reference to the creature group data
         */
        std::vector<TempSummonData> const* GetSummonGroup(uint32 summonerId, SummonerType summonerType, uint8 group) const
        {
            TempSummonDataContainer::const_iterator itr = _tempSummonDataStore.find(TempSummonGroupKey(summonerId, summonerType, group));
            if (itr != _tempSummonDataStore.end())
                return &itr->second;

            return nullptr;
        }

        BroadcastText const* GetBroadcastText(uint32 id) const
        {
            BroadcastTextContainer::const_iterator itr = _broadcastTextStore.find(id);
            if (itr != _broadcastTextStore.end())
                return &itr->second;
            return nullptr;
        }

        SpawnData const* GetSpawnData(SpawnObjectType type, ObjectGuid::LowType guid)
        {
            if (type == SPAWN_TYPE_CREATURE)
                return GetCreatureData(guid);
            else if (type == SPAWN_TYPE_GAMEOBJECT)
                return GetGameObjectData(guid);
            else
                ASSERT(false, "Invalid spawn object type %u", uint32(type));
            return nullptr;
        }
        void OnDeleteSpawnData(SpawnData const* data);
        CreatureDataContainer const& GetAllCreatureData() const { return _creatureDataStore; }
        CreatureData const* GetCreatureData(ObjectGuid::LowType guid) const
        {
            CreatureDataContainer::const_iterator itr = _creatureDataStore.find(guid);
            if (itr == _creatureDataStore.end()) return nullptr;
            return &itr->second;
        }
        CreatureData& NewOrExistCreatureData(ObjectGuid::LowType guid) { return _creatureDataStore[guid]; }
        void DeleteCreatureData(ObjectGuid::LowType guid);
        ObjectGuid GetLinkedRespawnGuid(ObjectGuid guid) const
        {
            LinkedRespawnContainer::const_iterator itr = _linkedRespawnStore.find(guid);
            if (itr == _linkedRespawnStore.end()) return ObjectGuid::Empty;
            return itr->second;
        }
        CreatureLocale const* GetCreatureLocale(uint32 entry) const
        {
            CreatureLocaleContainer::const_iterator itr = _creatureLocaleStore.find(entry);
            if (itr == _creatureLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        GameObjectDataContainer const& GetAllGameObjectData() const { return _gameObjectDataStore; }
        GameObjectData const* GetGameObjectData(ObjectGuid::LowType guid) const
        {
            GameObjectDataContainer::const_iterator itr = _gameObjectDataStore.find(guid);
            if (itr == _gameObjectDataStore.end()) return nullptr;
            return &itr->second;
        }
        GameObjectData& NewOrExistGameObjectData(ObjectGuid::LowType guid) { return _gameObjectDataStore[guid]; }
        void DeleteGameObjectData(ObjectGuid::LowType guid);
        GameObjectLocale const* GetGameObjectLocale(uint32 entry) const
        {
            GameObjectLocaleContainer::const_iterator itr = _gameObjectLocaleStore.find(entry);
            if (itr == _gameObjectLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        ItemLocale const* GetItemLocale(uint32 entry) const
        {
            ItemLocaleContainer::const_iterator itr = _itemLocaleStore.find(entry);
            if (itr == _itemLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        QuestLocale const* GetQuestLocale(uint32 entry) const
        {
            QuestLocaleContainer::const_iterator itr = _questLocaleStore.find(entry);
            if (itr == _questLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        QuestOfferRewardLocale const* GetQuestOfferRewardLocale(uint32 entry) const
        {
            auto itr = _questOfferRewardLocaleStore.find(entry);
            if (itr == _questOfferRewardLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        QuestRequestItemsLocale const* GetQuestRequestItemsLocale(uint32 entry) const
        {
            auto itr = _questRequestItemsLocaleStore.find(entry);
            if (itr == _questRequestItemsLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        NpcTextLocale const* GetNpcTextLocale(uint32 entry) const
        {
            NpcTextLocaleContainer::const_iterator itr = _npcTextLocaleStore.find(entry);
            if (itr == _npcTextLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        PageTextLocale const* GetPageTextLocale(uint32 entry) const
        {
            PageTextLocaleContainer::const_iterator itr = _pageTextLocaleStore.find(entry);
            if (itr == _pageTextLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        GossipMenuItemsLocale const* GetGossipMenuItemsLocale(uint32 entry) const
        {
            GossipMenuItemsLocaleContainer::const_iterator itr = _gossipMenuItemsLocaleStore.find(entry);
            if (itr == _gossipMenuItemsLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        PointOfInterestLocale const* GetPointOfInterestLocale(uint32 id) const
        {
            PointOfInterestLocaleContainer::const_iterator itr = _pointOfInterestLocaleStore.find(id);
            if (itr == _pointOfInterestLocaleStore.end()) return nullptr;
            return &itr->second;
        }
        QuestGreetingLocale const* GetQuestGreetingLocale(uint32 id) const
        {
            QuestGreetingLocaleContainer::const_iterator itr = _questGreetingLocaleStore.find(id);
            if (itr == _questGreetingLocaleStore.end()) return nullptr;
            return &itr->second;
        }

        TrinityString const* GetTrinityString(uint32 entry) const
        {
            TrinityStringContainer::const_iterator itr = _trinityStringStore.find(entry);
            if (itr == _trinityStringStore.end())
                return nullptr;
            return &itr->second;
        }
        char const* GetTrinityString(uint32 entry, LocaleConstant locale) const;
        char const* GetTrinityStringForDBCLocale(uint32 entry) const { return GetTrinityString(entry, DBCLocaleIndex); }
        LocaleConstant GetDBCLocaleIndex() const { return DBCLocaleIndex; }
        void SetDBCLocaleIndex(LocaleConstant locale) { DBCLocaleIndex = locale; }

        // grid objects
        void AddCreatureToGrid(ObjectGuid::LowType guid, CreatureData const* data);
        void RemoveCreatureFromGrid(ObjectGuid::LowType guid, CreatureData const* data);
        void AddGameobjectToGrid(ObjectGuid::LowType guid, GameObjectData const* data);
        void RemoveGameobjectFromGrid(ObjectGuid::LowType guid, GameObjectData const* data);
        ObjectGuid::LowType AddGameObjectData(uint32 entry, uint32 map, Position const& pos, QuaternionData const& rot, uint32 spawntimedelay = 0);
        ObjectGuid::LowType AddCreatureData(uint32 entry, uint32 map, Position const& pos, uint32 spawntimedelay = 0);

        // reserved names
        void LoadReservedPlayersNames();
        bool IsReservedName(std::string const& name) const;

        // name with valid structure and symbols
        static ResponseCodes CheckPlayerName(std::string const& name, LocaleConstant locale, bool create = false);
        static PetNameInvalidReason CheckPetName(std::string const& name, LocaleConstant locale);
        static bool IsValidCharterName(std::string const& name);

        static bool CheckDeclinedNames(const std::wstring& w_ownname, DeclinedName const& names);

        GameTele const* GetGameTele(uint32 id) const
        {
            GameTeleContainer::const_iterator itr = _gameTeleStore.find(id);
            if (itr == _gameTeleStore.end()) return nullptr;
            return &itr->second;
        }
        GameTele const* GetGameTele(std::string const& name) const;
        GameTele const* GetGameTeleExactName(std::string const& name) const;
        GameTeleContainer const& GetGameTeleMap() const { return _gameTeleStore; }
        bool AddGameTele(GameTele& data);
        bool DeleteGameTele(std::string const& name);

        TrainerSpellData const* GetNpcTrainerSpells(uint32 entry) const
        {
            CacheTrainerSpellContainer::const_iterator  iter = _cacheTrainerSpellStore.find(entry);
            if (iter == _cacheTrainerSpellStore.end())
                return nullptr;

            return &iter->second;
        }

        VendorItemData const* GetNpcVendorItemList(uint32 entry) const
        {
            CacheVendorItemContainer::const_iterator iter = _cacheVendorItemStore.find(entry);
            if (iter == _cacheVendorItemStore.end())
                return nullptr;

            return &iter->second;
        }

        float const* GetGraveyardOrientation(uint32 id) const
        {
            GraveyardOrientationContainer::const_iterator iter = _graveyardOrientations.find(id);
            if (iter != _graveyardOrientations.end())
                return &iter->second;

            return nullptr;
        }

        void AddVendorItem(uint32 entry, uint32 item, int32 maxcount, uint32 incrtime, uint32 extendedCost, uint8 type, bool persist = true); // for event
        bool RemoveVendorItem(uint32 entry, uint32 item, uint8 type, bool persist = true); // for event
        bool IsVendorItemValid(uint32 vendor_entry, uint32 id, int32 maxcount, uint32 ptime, uint32 ExtendedCost, uint8 type, Player* player = nullptr, std::set<uint32>* skip_vendors = nullptr, uint32 ORnpcflag = 0) const;

        void LoadScriptNames();
        ScriptNameContainer const& GetAllScriptNames() const;
        std::string const& GetScriptName(uint32 id) const;
        uint32 GetScriptId(std::string const& name);

        SpellClickInfoMapBounds GetSpellClickInfoMapBounds(uint32 creature_id) const
        {
            return _spellClickInfoStore.equal_range(creature_id);
        }

        GossipMenusMapBounds GetGossipMenusMapBounds(uint32 uiMenuId) const
        {
            return _gossipMenusStore.equal_range(uiMenuId);
        }

        GossipMenusMapBoundsNonConst GetGossipMenusMapBoundsNonConst(uint32 uiMenuId)
        {
            return _gossipMenusStore.equal_range(uiMenuId);
        }

        GossipMenuItemsMapBounds GetGossipMenuItemsMapBounds(uint32 uiMenuId) const
        {
            return _gossipMenuItemsStore.equal_range(uiMenuId);
        }
        GossipMenuItemsMapBoundsNonConst GetGossipMenuItemsMapBoundsNonConst(uint32 uiMenuId)
        {
            return _gossipMenuItemsStore.equal_range(uiMenuId);
        }

        // for wintergrasp only
        GraveyardContainer GraveyardStore;

        static void AddLocaleString(std::string const& value, LocaleConstant localeConstant, std::vector<std::string>& data);
        static inline void GetLocaleString(std::vector<std::string> const& data, LocaleConstant localeConstant, std::string& value)
        {
            if (data.size() > size_t(localeConstant) && !data[localeConstant].empty())
                value = data[localeConstant];
        }

        CharacterConversionMap FactionChangeAchievements;
        CharacterConversionMap FactionChangeItems;
        CharacterConversionMap FactionChangeQuests;
        CharacterConversionMap FactionChangeReputation;
        CharacterConversionMap FactionChangeSpells;
        CharacterConversionMap FactionChangeTitles;

        void LoadFactionChangeAchievements();
        void LoadFactionChangeItems();
        void LoadFactionChangeQuests();
        void LoadFactionChangeReputations();
        void LoadFactionChangeSpells();
        void LoadFactionChangeTitles();

        bool IsTransportMap(uint32 mapId) const { return _transportMaps.count(mapId) != 0; }

        void LoadHotfixData();
        HotfixData const& GetHotfixData() const { return _hotfixData; }
        time_t GetHotfixDate(uint32 entry, uint32 type) const
        {
            time_t ret = 0;
            for (HotfixData::const_iterator itr = _hotfixData.begin(); itr != _hotfixData.end(); ++itr)
                if (itr->Entry == entry && itr->Type == type)
                    if (time_t(itr->Timestamp) > ret)
                        ret = time_t(itr->Timestamp);

            return ret ? ret : time(nullptr);
        }

        void LoadMissingKeyChains();

    private:
        // first free id for selected id type
        uint32 _auctionId;
        uint64 _equipmentSetGuid;
        std::atomic<uint32> _mailId;
        std::atomic<uint32> _hiPetNumber;
        uint64 _voidItemId;

        ObjectGuid::LowType _creatureSpawnId;
        ObjectGuid::LowType _gameObjectSpawnId;

        // first free low guid for selected guid type
        template<HighGuid high>
        inline ObjectGuidGeneratorBase& GetGuidSequenceGenerator()
        {
            auto itr = _guidGenerators.find(high);
            if (itr == _guidGenerators.end())
                itr = _guidGenerators.insert(std::make_pair(high, std::unique_ptr<ObjectGuidGenerator<high>>(new ObjectGuidGenerator<high>()))).first;

            return *itr->second;
        }

        std::map<HighGuid, std::unique_ptr<ObjectGuidGeneratorBase>> _guidGenerators;
        QuestMap _questTemplates;

        typedef std::unordered_map<uint32, GossipText> GossipTextContainer;
        typedef std::unordered_map<uint32, uint32> QuestAreaTriggerContainer;
        typedef std::set<uint32> TavernAreaTriggerContainer;
        typedef std::set<uint32> GameObjectForQuestContainer;

        QuestAreaTriggerContainer _questAreaTriggerStore;
        TavernAreaTriggerContainer _tavernAreaTriggerStore;
        GameObjectForQuestContainer _gameObjectForQuestStore;
        GossipTextContainer _gossipTextStore;
        QuestGreetingContainer _questGreetingStore;
        AreaTriggerContainer _areaTriggerStore;
        AreaTriggerScriptContainer _areaTriggerScriptStore;
        AccessRequirementContainer _accessRequirementStore;
        DungeonEncounterContainer _dungeonEncounterStore;

        RepRewardRateContainer _repRewardRateStore;
        RepOnKillContainer _repOnKillStore;
        RepSpilloverTemplateContainer _repSpilloverTemplateStore;

        GossipMenusContainer _gossipMenusStore;
        GossipMenuItemsContainer _gossipMenuItemsStore;
        PointOfInterestContainer _pointsOfInterestStore;

        QuestPOIContainer _questPOIStore;

        QuestRelations _goQuestRelations;
        QuestRelations _goQuestInvolvedRelations;
        QuestRelationsReverse _goQuestInvolvedRelationsReverse;
        QuestRelations _creatureQuestRelations;
        QuestRelations _creatureQuestInvolvedRelations;
        QuestRelationsReverse _creatureQuestInvolvedRelationsReverse;

        //character reserved names
        typedef std::set<std::wstring> ReservedNamesContainer;
        ReservedNamesContainer _reservedNamesStore;

        GameTeleContainer _gameTeleStore;

        ScriptNameContainer _scriptNamesStore;

        SpellClickInfoContainer _spellClickInfoStore;

        SpellScriptsContainer _spellScriptsStore;

        VehicleAccessoryContainer _vehicleTemplateAccessoryStore;
        VehicleAccessoryContainer _vehicleAccessoryStore;

        LocaleConstant DBCLocaleIndex;

        PageTextContainer _pageTextStore;
        InstanceTemplateContainer _instanceTemplateStore;

    public:
        PhaseInfoStruct const* GetPhaseInfo(uint32 phaseId) const;
        std::vector<PhaseAreaInfo> const* GetPhasesForArea(uint32 areaId) const;
        TerrainSwapInfo const* GetTerrainSwapInfo(uint32 terrainSwapId) const;
        std::vector<TerrainSwapInfo*> const* GetTerrainSwapsForMap(uint32 mapId) const;

            private:
        std::unordered_map<uint32, PhaseInfoStruct> _phaseInfoById;
        std::unordered_map<uint32, TerrainSwapInfo> _terrainSwapInfoById;
        std::unordered_map<uint32, std::vector<PhaseAreaInfo>> _phaseInfoByArea;
        std::unordered_map<uint32, std::vector<TerrainSwapInfo*>> _terrainSwapInfoByMap;


    private:
        void LoadScripts(ScriptsType type);
        void LoadQuestRelationsHelper(QuestRelations& map, QuestRelationsReverse* reverseMap, std::string const& table, bool starter, bool go);
        void PlayerCreateInfoAddItemHelper(uint32 race_, uint32 class_, uint32 itemId, int32 count);

        MailLevelRewardContainer _mailLevelRewardStore;

        CreatureBaseStatsContainer _creatureBaseStatsStore;

        typedef std::map<uint32, PetLevelInfo*> PetLevelInfoContainer;
        // PetLevelInfoContainer[creature_id][level]
        PetLevelInfoContainer _petInfoStore;                            // [creature_id][level]

        void BuildPlayerLevelInfo(uint8 race, uint8 class_, uint8 level, PlayerLevelInfo* plinfo) const;

        PlayerInfo* _playerInfo[MAX_RACES][MAX_CLASSES];

        typedef std::vector<uint32> PlayerXPperLevel;       // [level]
        PlayerXPperLevel _playerXPperLevel;

        typedef std::map<uint32, uint32> BaseXPContainer;          // [area level][base xp]
        BaseXPContainer _baseXPTable;

        typedef std::map<uint32, int32> FishingBaseSkillContainer; // [areaId][base skill level]
        FishingBaseSkillContainer _fishingBaseForAreaStore;

        typedef std::map<uint32, std::vector<std::string>> HalfNameContainer;
        HalfNameContainer _petHalfName0;
        HalfNameContainer _petHalfName1;

        MapObjectGuids _mapObjectGuidsStore;
        CreatureDataContainer _creatureDataStore;
        CreatureTemplateContainer _creatureTemplateStore;
        CreatureModelContainer _creatureModelStore;
        CreatureAddonContainer _creatureAddonStore;
        CreatureTemplateAddonContainer _creatureTemplateAddonStore;
        GameObjectAddonContainer _gameObjectAddonStore;
        GameObjectQuestItemMap _gameObjectQuestItemStore;
        CreatureQuestItemMap _creatureQuestItemStore;
        EquipmentInfoContainer _equipmentInfoStore;
        LinkedRespawnContainer _linkedRespawnStore;
        CreatureLocaleContainer _creatureLocaleStore;
        GameObjectDataContainer _gameObjectDataStore;
        GameObjectLocaleContainer _gameObjectLocaleStore;
        GameObjectTemplateContainer _gameObjectTemplateStore;
        GameObjectTemplateAddonContainer _gameObjectTemplateAddonStore;
        SpawnGroupDataContainer _spawnGroupDataStore;
        SpawnGroupLinkContainer _spawnGroupMapStore;
        InstanceSpawnGroupContainer _instanceSpawnGroupStore;
        /// Stores temp summon data grouped by summoner's entry, summoner's type and group id
        TempSummonDataContainer _tempSummonDataStore;

        BroadcastTextContainer _broadcastTextStore;
        ItemTemplateContainer _itemTemplateStore;
        ItemLocaleContainer _itemLocaleStore;
        QuestLocaleContainer _questLocaleStore;
        QuestOfferRewardLocaleContainer _questOfferRewardLocaleStore;
        QuestRequestItemsLocaleContainer _questRequestItemsLocaleStore;

        NpcTextLocaleContainer _npcTextLocaleStore;
        PageTextLocaleContainer _pageTextLocaleStore;
        GossipMenuItemsLocaleContainer _gossipMenuItemsLocaleStore;
        PointOfInterestLocaleContainer _pointOfInterestLocaleStore;
        QuestGreetingLocaleContainer _questGreetingLocaleStore;

        TrinityStringContainer _trinityStringStore;

        CacheVendorItemContainer _cacheVendorItemStore;
        CacheTrainerSpellContainer _cacheTrainerSpellStore;

        GraveyardOrientationContainer _graveyardOrientations;

        std::set<uint32> _difficultyEntries[MAX_DIFFICULTY - 1]; // already loaded difficulty 1 value in creatures, used in CheckCreatureTemplate
        std::set<uint32> _hasDifficultyEntries[MAX_DIFFICULTY - 1]; // already loaded creatures with difficulty 1 values, used in CheckCreatureTemplate

        enum CreatureLinkedRespawnType
        {
            CREATURE_TO_CREATURE,
            CREATURE_TO_GO,         // Creature is dependant on GO
            GO_TO_GO,
            GO_TO_CREATURE          // GO is dependant on creature
        };

        HotfixData _hotfixData;
        std::set<uint32> _transportMaps; // Helper container storing map ids that are for transports only, loaded from gameobject_template
};

#define sObjectMgr ObjectMgr::instance()

#endif
