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

#ifndef _OBJECTMGR_H
#define _OBJECTMGR_H

#include "Log.h"
#include "Object.h"
#include "Bag.h"
#include "Creature.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "TemporarySummon.h"
#include "Corpse.h"
#include "QuestDef.h"
#include "ItemTemplate.h"
#include "NPCHandler.h"
#include "DatabaseEnv.h"
#include "Mail.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectDefines.h"
#include "VehicleDefines.h"
#include "ConditionMgr.h"
#include "DB2Stores.h"
#include <string>
#include <tuple>
#include <map>
#include <limits>
#include <functional>
#include <memory>

class Item;
struct AccessRequirement;
struct PlayerInfo;
struct PlayerLevelInfo;

#pragma pack(push, 1)

struct PageText
{
    std::string Text;
    uint32 NextPageID;
};

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

// DB scripting commands
enum ScriptCommands
{
    SCRIPT_COMMAND_TALK                  = 0,                // source/target = Creature, target = any, datalong = talk type (0=say, 1=whisper, 2=yell, 3=emote text, 4=boss emote text), datalong2 & 1 = player talk (instead of creature), dataint = string_id
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
    SCRIPT_COMMAND_PLAY_ANIMKIT          = 35                // source = Creature, datalong = AnimKit id
};

// Benchmarked: Faster than std::unordered_map (insert/find)
typedef std::map<uint32, PageText> PageTextContainer;

// Benchmarked: Faster than std::map (insert/find)
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
            uint32 GOGuid;          // datalong
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
            uint32 GOGuid;          // datalong
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

struct TrinityString
{
    StringVector Content;
};

typedef std::map<ObjectGuid, ObjectGuid> LinkedRespawnContainer;
typedef std::unordered_map<ObjectGuid::LowType, CreatureData> CreatureDataContainer;
typedef std::unordered_map<ObjectGuid::LowType, GameObjectData> GameObjectDataContainer;
typedef std::map<TempSummonGroupKey, std::vector<TempSummonData> > TempSummonDataContainer;
typedef std::unordered_map<uint32, CreatureLocale> CreatureLocaleContainer;
typedef std::unordered_map<uint32, GameObjectLocale> GameObjectLocaleContainer;
typedef std::unordered_map<uint32, QuestTemplateLocale> QuestTemplateLocaleContainer;
typedef std::unordered_map<uint32, QuestObjectivesLocale> QuestObjectivesLocaleContainer;
typedef std::unordered_map<uint32, PageTextLocale> PageTextLocaleContainer;
typedef std::unordered_map<uint32, GossipMenuItemsLocale> GossipMenuItemsLocaleContainer;
typedef std::unordered_map<uint32, PointOfInterestLocale> PointOfInterestLocaleContainer;

typedef std::unordered_map<uint32, TrinityString> TrinityStringContainer;

typedef std::multimap<uint32, uint32> QuestRelations; // unit/go -> quest
typedef std::multimap<uint32, uint32> QuestRelationsReverse; // quest -> unit/go
typedef std::pair<QuestRelations::const_iterator, QuestRelations::const_iterator> QuestRelationBounds;
typedef std::pair<QuestRelationsReverse::const_iterator, QuestRelationsReverse::const_iterator> QuestRelationReverseBounds;

struct PetLevelInfo
{
    PetLevelInfo() : health(0), mana(0), armor(0) { for (uint8 i=0; i < MAX_STATS; ++i) stats[i] = 0; }

    uint16 stats[MAX_STATS];
    uint16 health;
    uint16 mana;
    uint16 armor;
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
    G3D::Vector2 Pos;
    uint32 Icon;
    uint32 Flags;
    uint32 Importance;
    std::string Name;
};

struct GossipMenuItems
{
    uint32          MenuId;
    uint32          OptionIndex;
    uint8           OptionIcon;
    std::string     OptionText;
    uint32          OptionBroadcastTextId;
    uint32          OptionType;
    uint64          OptionNpcflag;
    uint32          ActionMenuId;
    uint32          ActionPoiId;
    bool            BoxCoded;
    uint32          BoxMoney;
    std::string     BoxText;
    uint32          BoxBroadcastTextId;
    ConditionContainer   Conditions;
};

struct GossipMenus
{
    uint32          entry;
    uint32          text_id;
    ConditionContainer   conditions;
};

typedef std::multimap<uint32, GossipMenus> GossipMenusContainer;
typedef std::pair<GossipMenusContainer::const_iterator, GossipMenusContainer::const_iterator> GossipMenusMapBounds;
typedef std::pair<GossipMenusContainer::iterator, GossipMenusContainer::iterator> GossipMenusMapBoundsNonConst;
typedef std::multimap<uint32, GossipMenuItems> GossipMenuItemsContainer;
typedef std::pair<GossipMenuItemsContainer::const_iterator, GossipMenuItemsContainer::const_iterator> GossipMenuItemsMapBounds;
typedef std::pair<GossipMenuItemsContainer::iterator, GossipMenuItemsContainer::iterator> GossipMenuItemsMapBoundsNonConst;

struct QuestPOIPoint
{
    int32 X;
    int32 Y;

    QuestPOIPoint() : X(0), Y(0) { }
    QuestPOIPoint(int32 _X, int32 _Y) : X(_X), Y(_Y) { }
};

struct QuestPOI
{
    int32 BlobIndex;
    int32 ObjectiveIndex;
    int32 QuestObjectiveID;
    int32 QuestObjectID;
    int32 MapID;
    int32 WorldMapAreaID;
    int32 Floor;
    int32 Priority;
    int32 Flags;
    int32 WorldEffectID;
    int32 PlayerConditionID;
    int32 UnkWoD1;
    std::vector<QuestPOIPoint> points;

    QuestPOI() : BlobIndex(0), ObjectiveIndex(0), QuestObjectiveID(0), QuestObjectID(0), MapID(0), WorldMapAreaID(0), Floor(0), Priority(0), Flags(0), WorldEffectID(0), PlayerConditionID(0), UnkWoD1(0) { }
    QuestPOI(int32 _BlobIndex, int32 _ObjectiveIndex, int32 _QuestObjectiveID, int32 _QuestObjectID, int32 _MapID, int32 _WorldMapAreaID, int32 _Foor, int32 _Priority, int32 _Flags, int32 _WorldEffectID, int32 _PlayerConditionID, int32 _UnkWoD1) :
        BlobIndex(_BlobIndex), ObjectiveIndex(_ObjectiveIndex), QuestObjectiveID(_QuestObjectiveID), QuestObjectID(_QuestObjectID), MapID(_MapID), WorldMapAreaID(_WorldMapAreaID),
        Floor(_Foor), Priority(_Priority), Flags(_Flags), WorldEffectID(_WorldEffectID), PlayerConditionID(_PlayerConditionID), UnkWoD1(_UnkWoD1) { }
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

typedef std::unordered_map<uint8, std::unordered_map<uint32, QuestGreeting const*>> QuestGreetingContainer;

struct GraveYardData
{
    uint32 safeLocId;
    uint32 team;
};

typedef std::multimap<uint32, GraveYardData> GraveYardContainer;
typedef std::pair<GraveYardContainer::const_iterator, GraveYardContainer::const_iterator> GraveYardMapBounds;
typedef std::pair<GraveYardContainer::iterator, GraveYardContainer::iterator> GraveYardMapBoundsNonConst;

typedef std::unordered_map<uint32, VendorItemData> CacheVendorItemContainer;
typedef std::unordered_map<uint32, TrainerSpellData> CacheTrainerSpellContainer;

typedef std::unordered_map<uint8, uint8> ExpansionRequirementContainer;
typedef std::unordered_map<uint32, std::string> RealmNameContainer;

struct CharcterTemplateClass
{
    CharcterTemplateClass(uint8 factionGroup, uint8 classID) :
        FactionGroup(factionGroup), ClassID(classID) { }

    uint8 FactionGroup;
    uint8 ClassID;
};

struct CharacterTemplate
{
    uint32 TemplateSetId;
    std::vector<CharcterTemplateClass> Classes;
    std::string Name;
    std::string Description;
    uint8 Level;
};

typedef std::unordered_map<uint32, CharacterTemplate> CharacterTemplateContainer;

enum SkillRangeType
{
    SKILL_RANGE_LANGUAGE,                                   // 300..300
    SKILL_RANGE_LEVEL,                                      // 1..max skill for level
    SKILL_RANGE_MONO,                                       // 1..1, grey monolite bar
    SKILL_RANGE_RANK,                                       // 1..skill for known rank
    SKILL_RANGE_NONE                                        // 0..0 always
};

#define MAX_SKILL_STEP 16

struct SkillTiersEntry
{
    uint32      ID;                                         // 0
    uint32      Value[MAX_SKILL_STEP];                      // 1-16
};

SkillRangeType GetSkillRangeType(SkillRaceClassInfoEntry const* rcEntry);

#define MAX_PLAYER_NAME          12                         // max allowed by client name length
#define MAX_INTERNAL_PLAYER_NAME 15                         // max server internal player name length (> MAX_PLAYER_NAME for support declined names)
#define MAX_PET_NAME             12                         // max allowed by client name length
#define MAX_CHARTER_NAME         24                         // max allowed by client name length

TC_GAME_API bool normalizePlayerName(std::string& name);

struct ExtendedPlayerName
{
    ExtendedPlayerName(std::string const& name, std::string const& realmName) : Name(name), Realm(realmName) { }
    std::string Name;
    std::string Realm;
};

ExtendedPlayerName ExtractExtendedPlayerName(std::string const& name);

struct LanguageDesc
{
    Language lang_id;
    uint32   spell_id;
    uint32   skill_id;
};

TC_GAME_API extern LanguageDesc lang_description[LANGUAGES_COUNT];
LanguageDesc const* GetLanguageDescByID(uint32 lang);

enum EncounterCreditType
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
typedef std::unordered_map<uint64, DungeonEncounterList> DungeonEncounterContainer;

struct PhaseInfoStruct
{
    uint32 Id;
    ConditionContainer Conditions;
};

typedef std::unordered_map<uint32, std::vector<uint32 /*id*/>> TerrainPhaseInfo; // terrain swap
typedef std::unordered_map<uint32, std::vector<uint32>> TerrainUIPhaseInfo; // worldmaparea swap
typedef std::unordered_map<uint32, std::vector<PhaseInfoStruct>> PhaseInfo; // phase

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

        typedef std::unordered_map<uint32, Item*> ItemMap;

        typedef std::unordered_map<uint32, Quest*> QuestMap;

        typedef std::unordered_map<uint32, AreaTriggerStruct> AreaTriggerContainer;

        typedef std::unordered_map<uint32, uint32> AreaTriggerScriptContainer;

        typedef std::unordered_map<uint64, AccessRequirement*> AccessRequirementContainer;

        typedef std::unordered_map<uint32, RepRewardRate > RepRewardRateContainer;
        typedef std::unordered_map<uint32, ReputationOnKillEntry> RepOnKillContainer;
        typedef std::unordered_map<uint32, RepSpilloverTemplate> RepSpilloverTemplateContainer;

        typedef std::unordered_map<uint32, PointOfInterest> PointOfInterestContainer;

        typedef std::vector<std::string> ScriptNameContainer;

        typedef std::map<uint32, uint32> CharacterConversionMap;

        Player* GetPlayerByLowGUID(ObjectGuid::LowType lowguid) const;

        GameObjectTemplate const* GetGameObjectTemplate(uint32 entry);
        GameObjectTemplateContainer const* GetGameObjectTemplates() const { return &_gameObjectTemplateStore; }
        int LoadReferenceVendor(int32 vendor, int32 item, uint8 type, std::set<uint32> *skip_vendors);

        void LoadGameObjectTemplate();
        void AddGameobjectInfo(GameObjectTemplate* goinfo);

        CreatureTemplate const* GetCreatureTemplate(uint32 entry);
        CreatureTemplateContainer const* GetCreatureTemplates() const { return &_creatureTemplateStore; }
        CreatureModelInfo const* GetCreatureModelInfo(uint32 modelId);
        CreatureModelInfo const* GetCreatureModelRandomGender(uint32* displayID);
        static uint32 ChooseDisplayId(CreatureTemplate const* cinfo, CreatureData const* data = NULL);
        static void ChooseCreatureFlags(CreatureTemplate const* cinfo, uint64& npcflag, uint32& unit_flags, uint32& dynamicflags, CreatureData const* data = NULL);
        EquipmentInfo const* GetEquipmentInfo(uint32 entry, int8& id);
        CreatureAddon const* GetCreatureAddon(ObjectGuid::LowType lowguid);
        GameObjectAddon const* GetGameObjectAddon(ObjectGuid::LowType lowguid);
        CreatureAddon const* GetCreatureTemplateAddon(uint32 entry);
        ItemTemplate const* GetItemTemplate(uint32 entry);
        ItemTemplateContainer const* GetItemTemplateStore() const { return &_itemTemplateStore; }

        InstanceTemplate const* GetInstanceTemplate(uint32 mapId);

        PetLevelInfo const* GetPetLevelInfo(uint32 creature_id, uint8 level) const;

        void GetPlayerClassLevelInfo(uint32 class_, uint8 level, uint32& baseHP, uint32& baseMana) const;

        PlayerInfo const* GetPlayerInfo(uint32 race, uint32 class_) const;

        void GetPlayerLevelInfo(uint32 race, uint32 class_, uint8 level, PlayerLevelInfo* info) const;

        static ObjectGuid GetPlayerGUIDByName(std::string const& name);

        GameObjectQuestItemList const* GetGameObjectQuestItemList(uint32 id) const
        {
            GameObjectQuestItemMap::const_iterator itr = _gameObjectQuestItemStore.find(id);
            if (itr != _gameObjectQuestItemStore.end())
                return &itr->second;
            return NULL;
        }
        GameObjectQuestItemMap const* GetGameObjectQuestItemMap() const { return &_gameObjectQuestItemStore; }

        CreatureQuestItemList const* GetCreatureQuestItemList(uint32 id) const
        {
            CreatureQuestItemMap::const_iterator itr = _creatureQuestItemStore.find(id);
            if (itr != _creatureQuestItemStore.end())
                return &itr->second;
            return NULL;
        }
        CreatureQuestItemMap const* GetCreatureQuestItemMap() const { return &_creatureQuestItemStore; }

        /**
        * Retrieves the player name by guid.
        *
        * If the player is online, the name is retrieved immediately otherwise
        * a database query is done.
        *
        * @remark Use sWorld->GetCharacterNameData because it doesn't require a database query when player is offline
        *
        * @param guid player full guid
        * @param name returned name
        *
        * @return true if player was found, false otherwise
        */
        static bool GetPlayerNameByGUID(ObjectGuid const& guid, std::string& name);
        static bool GetPlayerNameAndClassByGUID(ObjectGuid const& guid, std::string& name, uint8& _class);
        static uint32 GetPlayerTeamByGUID(ObjectGuid const& guid);
        static uint32 GetPlayerAccountIdByGUID(ObjectGuid const& guid);
        static uint32 GetPlayerAccountIdByPlayerName(std::string const& name);

        uint32 GetNearestTaxiNode(float x, float y, float z, uint32 mapid, uint32 team);
        void GetTaxiPath(uint32 source, uint32 destination, uint32 &path, uint32 &cost);
        void GetTaxiPath(uint32 source, uint32 destination, std::vector<uint32>& path, uint32& cost);
        uint32 GetTaxiMountDisplayId(uint32 id, uint32 team, bool allowed_alt_team = false);

        Quest const* GetQuestTemplate(uint32 quest_id) const
        {
            QuestMap::const_iterator itr = _questTemplates.find(quest_id);
            return itr != _questTemplates.end() ? itr->second : NULL;
        }

        QuestMap const& GetQuestTemplates() const { return _questTemplates; }

        std::unordered_set<uint32> const* GetQuestsForAreaTrigger(uint32 Trigger_ID) const
        {
            auto itr = _questAreaTriggerStore.find(Trigger_ID);
            if (itr != _questAreaTriggerStore.end())
                return &itr->second;
            return nullptr;
        }

        bool IsTavernAreaTrigger(uint32 Trigger_ID) const
        {
            return _tavernAreaTriggerStore.find(Trigger_ID) != _tavernAreaTriggerStore.end();
        }

        bool IsGameObjectForQuests(uint32 entry) const
        {
            return _gameObjectForQuestStore.find(entry) != _gameObjectForQuestStore.end();
        }

        NpcText const* GetNpcText(uint32 textID) const;
        QuestGreeting const* GetQuestGreeting(ObjectGuid guid) const;

        WorldSafeLocsEntry const* GetDefaultGraveYard(uint32 team);
        WorldSafeLocsEntry const* GetClosestGraveYard(float x, float y, float z, uint32 MapId, uint32 team);
        bool AddGraveYardLink(uint32 id, uint32 zoneId, uint32 team, bool persist = true);
        void RemoveGraveYardLink(uint32 id, uint32 zoneId, uint32 team, bool persist = false);
        void LoadGraveyardZones();
        GraveYardData const* FindGraveYardData(uint32 id, uint32 zone);

        AreaTriggerStruct const* GetAreaTrigger(uint32 trigger) const
        {
            AreaTriggerContainer::const_iterator itr = _areaTriggerStore.find(trigger);
            if (itr != _areaTriggerStore.end())
                return &itr->second;
            return NULL;
        }

        AccessRequirement const* GetAccessRequirement(uint32 mapid, Difficulty difficulty) const
        {
            AccessRequirementContainer::const_iterator itr = _accessRequirementStore.find(MAKE_PAIR64(mapid, difficulty));
            if (itr != _accessRequirementStore.end())
                return itr->second;
            return NULL;
        }

        AreaTriggerStruct const* GetGoBackTrigger(uint32 Map) const;
        AreaTriggerStruct const* GetMapEntranceTrigger(uint32 Map) const;

        uint32 GetAreaTriggerScriptId(uint32 trigger_id);
        SpellScriptsBounds GetSpellScriptsBounds(uint32 spellId);

        RepRewardRate const* GetRepRewardRate(uint32 factionId) const
        {
            RepRewardRateContainer::const_iterator itr = _repRewardRateStore.find(factionId);
            if (itr != _repRewardRateStore.end())
                return &itr->second;

            return NULL;
        }

        ReputationOnKillEntry const* GetReputationOnKilEntry(uint32 id) const
        {
            RepOnKillContainer::const_iterator itr = _repOnKillStore.find(id);
            if (itr != _repOnKillStore.end())
                return &itr->second;
            return NULL;
        }

        int32 GetBaseReputationOf(FactionEntry const* factionEntry, uint8 race, uint8 playerClass);

        RepSpilloverTemplate const* GetRepSpilloverTemplate(uint32 factionId) const
        {
            RepSpilloverTemplateContainer::const_iterator itr = _repSpilloverTemplateStore.find(factionId);
            if (itr != _repSpilloverTemplateStore.end())
                return &itr->second;

            return NULL;
        }

        PointOfInterest const* GetPointOfInterest(uint32 id) const
        {
            PointOfInterestContainer::const_iterator itr = _pointsOfInterestStore.find(id);
            if (itr != _pointsOfInterestStore.end())
                return &itr->second;
            return NULL;
        }

        QuestPOIVector const* GetQuestPOIVector(int32 QuestID)
        {
            QuestPOIContainer::const_iterator itr = _questPOIStore.find(QuestID);
            if (itr != _questPOIStore.end())
                return &itr->second;
            return NULL;
        }

        VehicleAccessoryList const* GetVehicleAccessoryList(Vehicle* veh) const;

        DungeonEncounterList const* GetDungeonEncounterList(uint32 mapId, Difficulty difficulty)
        {
            DungeonEncounterContainer::const_iterator itr = _dungeonEncounterStore.find(MAKE_PAIR64(mapId, difficulty));
            if (itr != _dungeonEncounterStore.end())
                return &itr->second;
            return NULL;
        }

        void LoadQuests();
        void LoadQuestStartersAndEnders()
        {
            TC_LOG_INFO("server.loading", "Loading GO Start Quest Data...");
            LoadGameobjectQuestStarters();
            TC_LOG_INFO("server.loading", "Loading GO End Quest Data...");
            LoadGameobjectQuestEnders();
            TC_LOG_INFO("server.loading", "Loading Creature Start Quest Data...");
            LoadCreatureQuestStarters();
            TC_LOG_INFO("server.loading", "Loading Creature End Quest Data...");
            LoadCreatureQuestEnders();
        }
        void LoadGameobjectQuestStarters();
        void LoadGameobjectQuestEnders();
        void LoadCreatureQuestStarters();
        void LoadCreatureQuestEnders();

        QuestRelations* GetGOQuestRelationMap()
        {
            return &_goQuestRelations;
        }

        QuestRelationBounds GetGOQuestRelationBounds(uint32 go_entry)
        {
            return _goQuestRelations.equal_range(go_entry);
        }

        QuestRelationBounds GetGOQuestInvolvedRelationBounds(uint32 go_entry)
        {
            return _goQuestInvolvedRelations.equal_range(go_entry);
        }

        QuestRelationReverseBounds GetGOQuestInvolvedRelationReverseBounds(uint32 questId)
        {
            return _goQuestInvolvedRelationsReverse.equal_range(questId);
        }

        QuestRelations* GetCreatureQuestRelationMap()
        {
            return &_creatureQuestRelations;
        }

        QuestRelationBounds GetCreatureQuestRelationBounds(uint32 creature_entry)
        {
            return _creatureQuestRelations.equal_range(creature_entry);
        }

        QuestRelationBounds GetCreatureQuestInvolvedRelationBounds(uint32 creature_entry)
        {
            return _creatureQuestInvolvedRelations.equal_range(creature_entry);
        }

        QuestRelationReverseBounds GetCreatureQuestInvolvedRelationReverseBounds(uint32 questId)
        {
            return _creatureQuestInvolvedRelationsReverse.equal_range(questId);
        }

        bool LoadTrinityStrings();

        void LoadEventScripts();
        void LoadSpellScripts();
        void LoadWaypointScripts();

        void LoadSpellScriptNames();
        void ValidateSpellScripts();

        void LoadCreatureClassLevelStats();
        void LoadCreatureLocales();
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
        void LoadGameobjects();
        void LoadItemTemplates();
        void LoadItemTemplateAddon();
        void LoadItemScriptNames();
        void LoadQuestTemplateLocale();
        void LoadQuestObjectivesLocale();
        void LoadPageTextLocales();
        void LoadGossipMenuItemsLocales();
        void LoadPointOfInterestLocales();
        void LoadInstanceTemplate();
        void LoadInstanceEncounters();
        void LoadMailLevelRewards();
        void LoadVehicleTemplateAccessories();
        void LoadVehicleAccessories();

        void LoadNPCText();

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
        void LoadSkillTiers();

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
        void AddSpellToTrainer(uint32 entry, uint32 spell, uint32 spellCost, uint32 reqSkill, uint32 reqSkillValue, uint32 reqLevel);

        void LoadTerrainPhaseInfo();
        void LoadTerrainSwapDefaults();
        void LoadTerrainWorldMaps();
        void LoadAreaPhases();

        std::string GeneratePetName(uint32 entry);
        uint32 GetBaseXP(uint8 level);
        uint32 GetXPForLevel(uint8 level) const;

        int32 GetFishingBaseSkillLevel(uint32 entry) const
        {
            FishingBaseSkillContainer::const_iterator itr = _fishingBaseForAreaStore.find(entry);
            return itr != _fishingBaseForAreaStore.end() ? itr->second : 0;
        }

        SkillTiersEntry const* GetSkillTier(uint32 skillTierId) const
        {
            auto itr = _skillTiers.find(skillTierId);
            return itr != _skillTiers.end() ? &itr->second : nullptr;
        }

        void ReturnOrDeleteOldMails(bool serverUp);

        CreatureBaseStats const* GetCreatureBaseStats(uint8 level, uint8 unitClass);

        void SetHighestGuids();

        template<HighGuid type>
        inline ObjectGuidGeneratorBase& GetGenerator()
        {
            static_assert(ObjectGuidTraits<type>::Global || ObjectGuidTraits<type>::RealmSpecific, "Only global guid can be generated in ObjectMgr context");
            return GetGuidSequenceGenerator<type>();
        }

        uint32 GenerateAuctionID();
        uint64 GenerateEquipmentSetGuid();
        uint32 GenerateMailID();
        uint32 GeneratePetNumber();
        uint64 GenerateVoidStorageItemId();
        uint64 GenerateCreatureSpawnId();
        uint64 GenerateGameObjectSpawnId();

        typedef std::multimap<int32, uint32> ExclusiveQuestGroups;
        typedef std::pair<ExclusiveQuestGroups::const_iterator, ExclusiveQuestGroups::const_iterator> ExclusiveQuestGroupsBounds;

        ExclusiveQuestGroups mExclusiveQuestGroups;

        MailLevelReward const* GetMailLevelReward(uint8 level, uint32 raceMask)
        {
            MailLevelRewardContainer::const_iterator map_itr = _mailLevelRewardStore.find(level);
            if (map_itr == _mailLevelRewardStore.end())
                return NULL;

            for (MailLevelRewardList::const_iterator set_itr = map_itr->second.begin(); set_itr != map_itr->second.end(); ++set_itr)
                if (set_itr->raceMask & raceMask)
                    return &*set_itr;

            return NULL;
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

            return NULL;
        }

        CreatureData const* GetCreatureData(ObjectGuid::LowType guid) const
        {
            CreatureDataContainer::const_iterator itr = _creatureDataStore.find(guid);
            if (itr == _creatureDataStore.end()) return NULL;
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
            if (itr == _creatureLocaleStore.end()) return NULL;
            return &itr->second;
        }
        GameObjectLocale const* GetGameObjectLocale(uint32 entry) const
        {
            GameObjectLocaleContainer::const_iterator itr = _gameObjectLocaleStore.find(entry);
            if (itr == _gameObjectLocaleStore.end()) return NULL;
            return &itr->second;
        }
        QuestTemplateLocale const* GetQuestLocale(uint32 entry) const
        {
            QuestTemplateLocaleContainer::const_iterator itr = _questTemplateLocaleStore.find(entry);
            if (itr == _questTemplateLocaleStore.end()) return NULL;
            return &itr->second;
        }
        QuestObjectivesLocale const* GetQuestObjectivesLocale(uint32 entry) const
        {
            QuestObjectivesLocaleContainer::const_iterator itr = _questObjectivesLocaleStore.find(entry);
            if (itr == _questObjectivesLocaleStore.end()) return NULL;
            return &itr->second;
        }
        PageTextLocale const* GetPageTextLocale(uint32 entry) const
        {
            PageTextLocaleContainer::const_iterator itr = _pageTextLocaleStore.find(entry);
            if (itr == _pageTextLocaleStore.end()) return NULL;
            return &itr->second;
        }
        GossipMenuItemsLocale const* GetGossipMenuItemsLocale(uint32 entry) const
        {
            GossipMenuItemsLocaleContainer::const_iterator itr = _gossipMenuItemsLocaleStore.find(entry);
            if (itr == _gossipMenuItemsLocaleStore.end()) return NULL;
            return &itr->second;
        }
        PointOfInterestLocale const* GetPointOfInterestLocale(uint32 id) const
        {
            PointOfInterestLocaleContainer::const_iterator itr = _pointOfInterestLocaleStore.find(id);
            if (itr == _pointOfInterestLocaleStore.end()) return NULL;
            return &itr->second;
        }

        GameObjectData const* GetGOData(ObjectGuid::LowType guid) const
        {
            GameObjectDataContainer::const_iterator itr = _gameObjectDataStore.find(guid);
            if (itr == _gameObjectDataStore.end()) return NULL;
            return &itr->second;
        }
        GameObjectData& NewGOData(ObjectGuid::LowType guid) { return _gameObjectDataStore[guid]; }
        void DeleteGOData(ObjectGuid::LowType guid);

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
        ObjectGuid::LowType AddGOData(uint32 entry, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay = 0, float rotation0 = 0, float rotation1 = 0, float rotation2 = 0, float rotation3 = 0);
        ObjectGuid::LowType AddCreatureData(uint32 entry, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay = 0);

        // reserved names
        void LoadReservedPlayersNames();
        bool IsReservedName(std::string const& name) const;

        // name with valid structure and symbols
        static ResponseCodes CheckPlayerName(std::string const& name, LocaleConstant locale, bool create = false);
        static PetNameInvalidReason CheckPetName(std::string const& name);
        static bool IsValidCharterName(std::string const& name);

        static bool CheckDeclinedNames(const std::wstring& w_ownname, DeclinedName const& names);

        GameTele const* GetGameTele(uint32 id) const
        {
            GameTeleContainer::const_iterator itr = _gameTeleStore.find(id);
            if (itr == _gameTeleStore.end()) return NULL;
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
                return NULL;

            return &iter->second;
        }

        VendorItemData const* GetNpcVendorItemList(uint32 entry) const
        {
            CacheVendorItemContainer::const_iterator iter = _cacheVendorItemStore.find(entry);
            if (iter == _cacheVendorItemStore.end())
                return NULL;

            return &iter->second;
        }

        void AddVendorItem(uint32 entry, uint32 item, int32 maxcount, uint32 incrtime, uint32 extendedCost, uint8 type, bool persist = true); // for event
        bool RemoveVendorItem(uint32 entry, uint32 item, uint8 type, bool persist = true); // for event
        bool IsVendorItemValid(uint32 vendor_entry, uint32 id, int32 maxcount, uint32 ptime, uint32 ExtendedCost, uint8 type, Player* player = NULL, std::set<uint32>* skip_vendors = NULL, uint32 ORnpcflag = 0) const;

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

        std::vector<uint32> const* GetPhaseTerrainSwaps(uint32 phaseid) const
        {
            auto itr = _terrainPhaseInfoStore.find(phaseid);
            return itr != _terrainPhaseInfoStore.end() ? &itr->second : nullptr;
        }
        std::vector<uint32> const* GetDefaultTerrainSwaps(uint32 mapid) const
        {
            auto itr = _terrainMapDefaultStore.find(mapid);
            return itr != _terrainMapDefaultStore.end() ? &itr->second : nullptr;
        }
        std::vector<uint32> const* GetTerrainWorldMaps(uint32 terrainId) const
        {
            auto itr = _terrainWorldMapStore.find(terrainId);
            return itr != _terrainWorldMapStore.end() ? &itr->second : nullptr;
        }
        std::vector<PhaseInfoStruct> const* GetPhasesForArea(uint32 area) const
        {
            auto itr = _phases.find(area);
            return itr != _phases.end() ? &itr->second : nullptr;
        }
        TerrainPhaseInfo const& GetDefaultTerrainSwapStore() const { return _terrainMapDefaultStore; }
        PhaseInfo const& GetAreaAndZonePhases() const { return _phases; }
        // condition loading helpers
        std::vector<PhaseInfoStruct>* GetPhasesForAreaOrZoneForLoading(uint32 areaOrZone)
        {
            auto itr = _phases.find(areaOrZone);
            return itr != _phases.end() ? &itr->second : nullptr;
        }
        PhaseInfo& GetAreaAndZonePhasesForLoading() { return _phases; }

        // for wintergrasp only
        GraveYardContainer GraveYardStore;

        static void AddLocaleString(std::string const& value, LocaleConstant localeConstant, StringVector& data);
        static inline void GetLocaleString(StringVector const& data, LocaleConstant localeConstant, std::string& value)
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

        void LoadRaceAndClassExpansionRequirements();
        void LoadCharacterTemplates();
        void LoadRealmNames();

        std::string GetRealmName(uint32 realm) const;
        std::string GetNormalizedRealmName(uint32 realm) const;

        ExpansionRequirementContainer const& GetRaceExpansionRequirements() const { return _raceExpansionRequirementStore; }
        uint8 GetRaceExpansionRequirement(uint8 race) const
        {
            auto itr = _raceExpansionRequirementStore.find(race);
            if (itr != _raceExpansionRequirementStore.end())
                return itr->second;
            return EXPANSION_CLASSIC;
        }

        ExpansionRequirementContainer const& GetClassExpansionRequirements() const { return _classExpansionRequirementStore; }
        uint8 GetClassExpansionRequirement(uint8 class_) const
        {
            auto itr = _classExpansionRequirementStore.find(class_);
            if (itr != _classExpansionRequirementStore.end())
                return itr->second;
            return EXPANSION_CLASSIC;
        }

        CharacterTemplateContainer const& GetCharacterTemplates() const { return _characterTemplateStore; }
        CharacterTemplate const* GetCharacterTemplate(uint32 id) const
        {
            auto itr = _characterTemplateStore.find(id);
            if (itr != _characterTemplateStore.end())
                return &itr->second;

            return nullptr;
        }

    private:
        // first free id for selected id type
        uint32 _auctionId;
        uint64 _equipmentSetGuid;
        uint32 _itemTextId;
        uint32 _mailId;
        uint32 _hiPetNumber;
        uint64 _voidItemId;
        uint64 _creatureSpawnId;
        uint64 _gameObjectSpawnId;

        // first free low guid for selected guid type
        template<HighGuid high>
        inline ObjectGuidGeneratorBase& GetGuidSequenceGenerator()
        {
            auto itr = _guidGenerators.find(high);
            if (itr == _guidGenerators.end())
                itr = _guidGenerators.insert(std::make_pair(high, Trinity::make_unique<ObjectGuidGenerator<high>>())).first;

            return *itr->second;
        }

        std::map<HighGuid, std::unique_ptr<ObjectGuidGeneratorBase>> _guidGenerators;

        QuestMap _questTemplates;

        typedef std::unordered_map<uint32, NpcText> NpcTextContainer;
        typedef std::unordered_map<uint32, std::unordered_set<uint32>> QuestAreaTriggerContainer;
        typedef std::set<uint32> TavernAreaTriggerContainer;
        typedef std::set<uint32> GameObjectForQuestContainer;

        QuestAreaTriggerContainer _questAreaTriggerStore;
        TavernAreaTriggerContainer _tavernAreaTriggerStore;
        GameObjectForQuestContainer _gameObjectForQuestStore;
        NpcTextContainer _npcTextStore;
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

        VehicleAccessoryTemplateContainer _vehicleTemplateAccessoryStore;
        VehicleAccessoryContainer _vehicleAccessoryStore;

        LocaleConstant DBCLocaleIndex;

        PageTextContainer _pageTextStore;
        InstanceTemplateContainer _instanceTemplateStore;

        TerrainPhaseInfo _terrainPhaseInfoStore;
        TerrainPhaseInfo _terrainMapDefaultStore;
        TerrainUIPhaseInfo _terrainWorldMapStore;
        PhaseInfo _phases;

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
        std::unordered_map<uint32, SkillTiersEntry> _skillTiers;

        typedef std::map<uint32, StringVector> HalfNameContainer;
        HalfNameContainer _petHalfName0;
        HalfNameContainer _petHalfName1;

        MapObjectGuids _mapObjectGuidsStore;
        CreatureDataContainer _creatureDataStore;
        CreatureTemplateContainer _creatureTemplateStore;
        CreatureModelContainer _creatureModelStore;
        CreatureAddonContainer _creatureAddonStore;
        GameObjectAddonContainer _gameObjectAddonStore;
        GameObjectQuestItemMap _gameObjectQuestItemStore;
        CreatureQuestItemMap _creatureQuestItemStore;
        CreatureTemplateAddonContainer _creatureTemplateAddonStore;
        EquipmentInfoContainer _equipmentInfoStore;
        LinkedRespawnContainer _linkedRespawnStore;
        CreatureLocaleContainer _creatureLocaleStore;
        GameObjectDataContainer _gameObjectDataStore;
        GameObjectLocaleContainer _gameObjectLocaleStore;
        GameObjectTemplateContainer _gameObjectTemplateStore;
        /// Stores temp summon data grouped by summoner's entry, summoner's type and group id
        TempSummonDataContainer _tempSummonDataStore;

        ItemTemplateContainer _itemTemplateStore;
        QuestTemplateLocaleContainer _questTemplateLocaleStore;
        QuestObjectivesLocaleContainer _questObjectivesLocaleStore;
        PageTextLocaleContainer _pageTextLocaleStore;
        GossipMenuItemsLocaleContainer _gossipMenuItemsLocaleStore;
        PointOfInterestLocaleContainer _pointOfInterestLocaleStore;

        TrinityStringContainer _trinityStringStore;

        CacheVendorItemContainer _cacheVendorItemStore;
        CacheTrainerSpellContainer _cacheTrainerSpellStore;

        std::set<uint32> _difficultyEntries[MAX_CREATURE_DIFFICULTIES]; // already loaded difficulty 1 value in creatures, used in CheckCreatureTemplate
        std::set<uint32> _hasDifficultyEntries[MAX_CREATURE_DIFFICULTIES]; // already loaded creatures with difficulty 1 values, used in CheckCreatureTemplate

        ExpansionRequirementContainer _raceExpansionRequirementStore;
        ExpansionRequirementContainer _classExpansionRequirementStore;
        RealmNameContainer _realmNameStore;

        CharacterTemplateContainer _characterTemplateStore;

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
