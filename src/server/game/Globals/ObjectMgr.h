/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "Player.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Corpse.h"
#include "QuestDef.h"
#include "ItemPrototype.h"
#include "NPCHandler.h"
#include "DatabaseEnv.h"
#include "Mail.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectDefines.h"
#include <ace/Singleton.h>
#include "SQLStorage.h"
#include "Vehicle.h"
#include <string>
#include <map>
#include <limits>
#include "ConditionMgr.h"

extern SQLStorage sCreatureStorage;
extern SQLStorage sCreatureDataAddonStorage;
extern SQLStorage sCreatureInfoAddonStorage;
extern SQLStorage sCreatureModelStorage;
extern SQLStorage sEquipmentStorage;
extern SQLStorage sGOStorage;
extern SQLStorage sPageTextStore;
extern SQLStorage sItemStorage;
extern SQLStorage sInstanceTemplate;

class Group;
class Guild;
class ArenaTeam;
class Item;

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

typedef UNORDERED_MAP<uint32, GameTele > GameTeleMap;

enum ScriptsType
{
    SCRIPTS_FIRST = 1,

    SCRIPTS_QUEST_END = SCRIPTS_FIRST,
    SCRIPTS_QUEST_START,
    SCRIPTS_SPELL,
    SCRIPTS_GAMEOBJECT,
    SCRIPTS_EVENT,
    SCRIPTS_WAYPOINT,
    SCRIPTS_GOSSIP,

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
    SF_ORIENTATION_FACE_TARGET  = 0x1,
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
    };

    std::string GetDebugInfo() const;
};

typedef std::multimap<uint32, ScriptInfo> ScriptMap;
typedef std::map<uint32, ScriptMap > ScriptMapMap;
typedef std::multimap<uint32, uint32> SpellScriptsMap;
typedef std::pair<SpellScriptsMap::iterator, SpellScriptsMap::iterator> SpellScriptsBounds;
extern ScriptMapMap sQuestEndScripts;
extern ScriptMapMap sQuestStartScripts;
extern ScriptMapMap sSpellScripts;
extern ScriptMapMap sGameObjectScripts;
extern ScriptMapMap sEventScripts;
extern ScriptMapMap sGossipScripts;
extern ScriptMapMap sWaypointScripts;

std::string GetScriptsTableNameByType(ScriptsType type);
ScriptMapMap* GetScriptsMapByType(ScriptsType type);
std::string GetScriptCommandName(ScriptCommands command);

struct SpellClickInfo
{
    uint32 spellId;
    uint32 questStart;                                      // quest start (quest must be active or rewarded for spell apply)
    uint32 questEnd;                                        // quest end (quest don't must be rewarded for spell apply)
    bool   questStartCanActive;                             // if true then quest start can be active (not only rewarded)
    uint8 castFlags;
    uint32 auraRequired;
    uint32 auraForbidden;
    SpellClickUserTypes userType;

    // helpers
    bool IsFitToRequirements(Player const* player, Creature const * clickNpc) const;
};

typedef std::multimap<uint32, SpellClickInfo> SpellClickInfoMap;
typedef std::pair<SpellClickInfoMap::const_iterator,SpellClickInfoMap::const_iterator> SpellClickInfoMapBounds;

struct AreaTrigger
{
    uint32 target_mapId;
    float  target_X;
    float  target_Y;
    float  target_Z;
    float  target_Orientation;
};

typedef std::set<uint32> CellGuidSet;
typedef std::map<uint32/*player guid*/,uint32/*instance*/> CellCorpseSet;
struct CellObjectGuids
{
    CellGuidSet creatures;
    CellGuidSet gameobjects;
    CellCorpseSet corpses;
};
typedef UNORDERED_MAP<uint32/*cell_id*/,CellObjectGuids> CellObjectGuidsMap;
typedef UNORDERED_MAP<uint32/*(mapid,spawnMode) pair*/,CellObjectGuidsMap> MapObjectGuids;

typedef UNORDERED_MAP<uint64/*(instance,guid) pair*/,time_t> RespawnTimes;

// Trinity string ranges
#define MIN_TRINITY_STRING_ID           1                    // 'trinity_string'
#define MAX_TRINITY_STRING_ID           2000000000
#define MIN_DB_SCRIPT_STRING_ID        MAX_TRINITY_STRING_ID // 'db_script_string'
#define MAX_DB_SCRIPT_STRING_ID        2000010000
#define MIN_CREATURE_AI_TEXT_STRING_ID (-1)                 // 'creature_ai_texts'
#define MAX_CREATURE_AI_TEXT_STRING_ID (-1000000)

// Trinity Trainer Reference start range
#define TRINITY_TRAINER_START_REF      200000

struct TrinityStringLocale
{
    StringVector Content;
};

typedef std::map<uint32,uint32> CreatureLinkedRespawnMap;
typedef UNORDERED_MAP<uint32,CreatureData> CreatureDataMap;
typedef UNORDERED_MAP<uint32,GameObjectData> GameObjectDataMap;
typedef UNORDERED_MAP<uint32,CreatureLocale> CreatureLocaleMap;
typedef UNORDERED_MAP<uint32,GameObjectLocale> GameObjectLocaleMap;
typedef UNORDERED_MAP<uint32,ItemLocale> ItemLocaleMap;
typedef UNORDERED_MAP<uint32,ItemSetNameLocale> ItemSetNameLocaleMap;
typedef UNORDERED_MAP<uint32,QuestLocale> QuestLocaleMap;
typedef UNORDERED_MAP<uint32,NpcTextLocale> NpcTextLocaleMap;
typedef UNORDERED_MAP<uint32,PageTextLocale> PageTextLocaleMap;
typedef UNORDERED_MAP<int32,TrinityStringLocale> TrinityStringLocaleMap;
typedef UNORDERED_MAP<uint32,GossipMenuItemsLocale> GossipMenuItemsLocaleMap;
typedef UNORDERED_MAP<uint32,PointOfInterestLocale> PointOfInterestLocaleMap;

typedef std::multimap<uint32,uint32> QuestRelations;
typedef std::pair<QuestRelations::const_iterator, QuestRelations::const_iterator> QuestRelationBounds;
typedef std::multimap<uint32,ItemRequiredTarget> ItemRequiredTargetMap;
typedef std::pair<ItemRequiredTargetMap::const_iterator, ItemRequiredTargetMap::const_iterator>  ItemRequiredTargetMapBounds;

struct PetLevelInfo
{
    PetLevelInfo() : health(0), mana(0) { for (uint8 i=0; i < MAX_STATS; ++i) stats[i] = 0; }

    uint16 stats[MAX_STATS];
    uint16 health;
    uint16 mana;
    uint16 armor;
};

struct MailLevelReward
{
    MailLevelReward() : raceMask(0), mailTemplateId(0), senderEntry(0) {}
    MailLevelReward(uint32 _raceMask, uint32 _mailTemplateId, uint32 _senderEntry) : raceMask(_raceMask), mailTemplateId(_mailTemplateId), senderEntry(_senderEntry) {}

    uint32 raceMask;
    uint32 mailTemplateId;
    uint32 senderEntry;
};

typedef std::list<MailLevelReward> MailLevelRewardList;
typedef UNORDERED_MAP<uint8,MailLevelRewardList> MailLevelRewardMap;

// We assume the rate is in general the same for all three types below, but chose to keep three for scalability and customization
struct RepRewardRate
{
    float quest_rate;                                       // We allow rate = 0.0 in database. For this case, it means that
    float creature_rate;                                    // no reputation are given at all for this faction/rate type.
    float spell_rate;
};

struct ReputationOnKillEntry
{
    uint32 repfaction1;
    uint32 repfaction2;
    bool is_teamaward1;
    uint32 reputation_max_cap1;
    int32 repvalue1;
    bool is_teamaward2;
    uint32 reputation_max_cap2;
    int32 repvalue2;
    bool team_dependent;
};

struct RepSpilloverTemplate
{
    uint32 faction[MAX_SPILLOVER_FACTIONS];
    float faction_rate[MAX_SPILLOVER_FACTIONS];
    uint32 faction_rank[MAX_SPILLOVER_FACTIONS];
};

struct PointOfInterest
{
    uint32 entry;
    float x;
    float y;
    uint32 icon;
    uint32 flags;
    uint32 data;
    std::string icon_name;
};

struct GossipMenuItems
{
    uint32          menu_id;
    uint32          id;
    uint8           option_icon;
    std::string     option_text;
    uint32          option_id;
    uint32          npc_option_npcflag;
    uint32          action_menu_id;
    uint32          action_poi_id;
    uint32          action_script_id;
    bool            box_coded;
    uint32          box_money;
    std::string     box_text;
    ConditionList   conditions;
};

struct GossipMenus
{
    uint32          entry;
    uint32          text_id;
    ConditionList   conditions;
};

typedef std::multimap<uint32,GossipMenus> GossipMenusMap;
typedef std::pair<GossipMenusMap::const_iterator, GossipMenusMap::const_iterator> GossipMenusMapBounds;
typedef std::pair<GossipMenusMap::iterator, GossipMenusMap::iterator> GossipMenusMapBoundsNonConst;
typedef std::multimap<uint32,GossipMenuItems> GossipMenuItemsMap;
typedef std::pair<GossipMenuItemsMap::const_iterator, GossipMenuItemsMap::const_iterator> GossipMenuItemsMapBounds;
typedef std::pair<GossipMenuItemsMap::iterator, GossipMenuItemsMap::iterator> GossipMenuItemsMapBoundsNonConst;

struct QuestPOIPoint
{
    int32 x;
    int32 y;

    QuestPOIPoint() : x(0), y(0) {}
    QuestPOIPoint(int32 _x, int32 _y) : x(_x), y(_y) {}
};

struct QuestPOI
{
    uint32 Id;
    int32 ObjectiveIndex;
    uint32 MapId;
    uint32 AreaId;
    uint32 Unk2;
    uint32 Unk3;
    uint32 Unk4;
    std::vector<QuestPOIPoint> points;

    QuestPOI() : Id(0), ObjectiveIndex(0), MapId(0), AreaId(0), Unk2(0), Unk3(0), Unk4(0) {}
    QuestPOI(uint32 id, int32 objIndex, uint32 mapId, uint32 areaId, uint32 unk2, uint32 unk3, uint32 unk4) : Id(id), ObjectiveIndex(objIndex), MapId(mapId), AreaId(areaId), Unk2(unk2), Unk3(unk3), Unk4(unk4) {}
};

typedef std::vector<QuestPOI> QuestPOIVector;
typedef UNORDERED_MAP<uint32, QuestPOIVector> QuestPOIMap;

struct GraveYardData
{
    uint32 safeLocId;
    uint32 team;
};
typedef std::multimap<uint32,GraveYardData> GraveYardMap;

// NPC gossip text id
typedef UNORDERED_MAP<uint32, uint32> CacheNpcTextIdMap;

typedef UNORDERED_MAP<uint32, VendorItemData> CacheVendorItemMap;
typedef UNORDERED_MAP<uint32, TrainerSpellData> CacheTrainerSpellMap;

enum SkillRangeType
{
    SKILL_RANGE_LANGUAGE,                                   // 300..300
    SKILL_RANGE_LEVEL,                                      // 1..max skill for level
    SKILL_RANGE_MONO,                                       // 1..1, grey monolite bar
    SKILL_RANGE_RANK,                                       // 1..skill for known rank
    SKILL_RANGE_NONE,                                       // 0..0 always
};

SkillRangeType GetSkillRangeType(SkillLineEntry const *pSkill, bool racial);

#define MAX_PLAYER_NAME          12                         // max allowed by client name length
#define MAX_INTERNAL_PLAYER_NAME 15                         // max server internal player name length (> MAX_PLAYER_NAME for support declined names)
#define MAX_PET_NAME             12                         // max allowed by client name length
#define MAX_CHARTER_NAME         24                         // max allowed by client name length

bool normalizePlayerName(std::string& name);

struct LanguageDesc
{
    Language lang_id;
    uint32   spell_id;
    uint32   skill_id;
};

extern LanguageDesc lang_description[LANGUAGES_COUNT];
 LanguageDesc const* GetLanguageDescByID(uint32 lang);

class PlayerDumpReader;

class ObjectMgr
{
    friend class PlayerDumpReader;
    friend class ACE_Singleton<ObjectMgr, ACE_Null_Mutex>;
    ObjectMgr();
    ~ObjectMgr();

    public:
        typedef UNORDERED_MAP<uint32, Item*> ItemMap;

        typedef std::set<Group *> GroupSet;

        typedef std::vector <Guild *> GuildMap;

        typedef UNORDERED_MAP<uint32, ArenaTeam*> ArenaTeamMap;

        typedef UNORDERED_MAP<uint32, Quest*> QuestMap;

        typedef UNORDERED_MAP<uint32, AreaTrigger> AreaTriggerMap;

        typedef UNORDERED_MAP<uint32, uint32> AreaTriggerScriptMap;

        typedef UNORDERED_MAP<uint32, AccessRequirement> AccessRequirementMap;

        typedef UNORDERED_MAP<uint32, RepRewardRate > RepRewardRateMap;
        typedef UNORDERED_MAP<uint32, ReputationOnKillEntry> RepOnKillMap;
        typedef UNORDERED_MAP<uint32, RepSpilloverTemplate> RepSpilloverTemplateMap;

        typedef UNORDERED_MAP<uint32, PointOfInterest> PointOfInterestMap;

        typedef std::vector<std::string> ScriptNameMap;

        typedef std::map<uint32, uint32> CharacterConversionMap;

        Player* GetPlayer(const char* name) const { return sObjectAccessor.FindPlayerByName(name);}
        Player* GetPlayer(uint64 guid) const { return ObjectAccessor::FindPlayer(guid); }
        Player* GetPlayerByLowGUID(uint32 lowguid) const;

        static GameObjectInfo const *GetGameObjectInfo(uint32 id) { return sGOStorage.LookupEntry<GameObjectInfo>(id); }
        int LoadReferenceVendor(int32 vendor, int32 item_id, std::set<uint32> *skip_vendors);

        void LoadGameobjectInfo();
        void AddGameobjectInfo(GameObjectInfo *goinfo);

        Group * GetGroupByGUID(uint32 guid) const;
        void AddGroup(Group* group) { mGroupSet.insert(group); }
        void RemoveGroup(Group* group) { mGroupSet.erase(group); }

        Guild* GetGuildByLeader(uint64 const&guid) const;
        Guild* GetGuildById(uint32 guildId) const;
        Guild* GetGuildByName(const std::string& guildname) const;
        std::string GetGuildNameById(uint32 guildId) const;
        void AddGuild(Guild* pGuild);
        void RemoveGuild(uint32 guildId);

        ArenaTeam* GetArenaTeamById(uint32 arenateamid) const;
        ArenaTeam* GetArenaTeamByName(const std::string& arenateamname) const;
        ArenaTeam* GetArenaTeamByCaptain(uint64 const& guid) const;
        void AddArenaTeam(ArenaTeam* arenaTeam);
        void RemoveArenaTeam(uint32 Id);
        ArenaTeamMap::iterator GetArenaTeamMapBegin() { return mArenaTeamMap.begin(); }
        ArenaTeamMap::iterator GetArenaTeamMapEnd()   { return mArenaTeamMap.end(); }

        static CreatureInfo const *GetCreatureTemplate(uint32 id);
        CreatureModelInfo const *GetCreatureModelInfo(uint32 modelid);
        CreatureModelInfo const* GetCreatureModelRandomGender(uint32 display_id);
        uint32 ChooseDisplayId(uint32 team, const CreatureInfo *cinfo, const CreatureData *data = NULL);
        static void ChooseCreatureFlags(const CreatureInfo *cinfo, uint32& npcflag, uint32& unit_flags, uint32& dynamicflags, const CreatureData *data = NULL);
        EquipmentInfo const *GetEquipmentInfo(uint32 entry);
        static CreatureDataAddon const *GetCreatureAddon(uint32 lowguid)
        {
            return sCreatureDataAddonStorage.LookupEntry<CreatureDataAddon>(lowguid);
        }

        static CreatureDataAddon const *GetCreatureTemplateAddon(uint32 entry)
        {
            return sCreatureInfoAddonStorage.LookupEntry<CreatureDataAddon>(entry);
        }

        static ItemPrototype const* GetItemPrototype(uint32 id) { return sItemStorage.LookupEntry<ItemPrototype>(id); }

        ItemSetNameEntry const* GetItemSetNameEntry(uint32 itemId)
        {
            ItemSetNameMap::iterator itr = mItemSetNameMap.find(itemId);
            if(itr != mItemSetNameMap.end())
                return &itr->second;
            return NULL;
        }

        static InstanceTemplate const* GetInstanceTemplate(uint32 map)
        {
            return sInstanceTemplate.LookupEntry<InstanceTemplate>(map);
        }

        PetLevelInfo const* GetPetLevelInfo(uint32 creature_id, uint8 level) const;

        PlayerClassInfo const* GetPlayerClassInfo(uint32 class_) const
        {
            if (class_ >= MAX_CLASSES) return NULL;
            return &playerClassInfo[class_];
        }
        void GetPlayerClassLevelInfo(uint32 class_,uint8 level, PlayerClassLevelInfo* info) const;

        PlayerInfo const* GetPlayerInfo(uint32 race, uint32 class_) const
        {
            if (race >= MAX_RACES)   return NULL;
            if (class_ >= MAX_CLASSES) return NULL;
            PlayerInfo const* info = &playerInfo[race][class_];
            if (info->displayId_m == 0 || info->displayId_f == 0) return NULL;
            return info;
        }
        void GetPlayerLevelInfo(uint32 race, uint32 class_, uint8 level, PlayerLevelInfo* info) const;

        uint64 GetPlayerGUIDByName(std::string name) const;
        bool GetPlayerNameByGUID(const uint64 &guid, std::string &name) const;
        uint32 GetPlayerTeamByGUID(const uint64 &guid) const;
        uint32 GetPlayerAccountIdByGUID(const uint64 &guid) const;
        uint32 GetPlayerAccountIdByPlayerName(const std::string& name) const;

        uint32 GetNearestTaxiNode(float x, float y, float z, uint32 mapid, uint32 team);
        void GetTaxiPath(uint32 source, uint32 destination, uint32 &path, uint32 &cost);
        uint32 GetTaxiMountDisplayId(uint32 id, uint32 team, bool allowed_alt_team = false);

        Quest const* GetQuestTemplate(uint32 quest_id) const
        {
            QuestMap::const_iterator itr = mQuestTemplates.find(quest_id);
            return itr != mQuestTemplates.end() ? itr->second : NULL;
        }
        QuestMap const& GetQuestTemplates() const { return mQuestTemplates; }

        uint32 GetQuestForAreaTrigger(uint32 Trigger_ID) const
        {
            QuestAreaTriggerMap::const_iterator itr = mQuestAreaTriggerMap.find(Trigger_ID);
            if (itr != mQuestAreaTriggerMap.end())
                return itr->second;
            return 0;
        }
        bool IsTavernAreaTrigger(uint32 Trigger_ID) const
        {
            return mTavernAreaTriggerSet.find(Trigger_ID) != mTavernAreaTriggerSet.end();
        }

        bool IsGameObjectForQuests(uint32 entry) const
        {
            return mGameObjectForQuestSet.find(entry) != mGameObjectForQuestSet.end();
        }

        GossipText const* GetGossipText(uint32 Text_ID) const;

        WorldSafeLocsEntry const *GetClosestGraveYard(float x, float y, float z, uint32 MapId, uint32 team);
        bool AddGraveYardLink(uint32 id, uint32 zone, uint32 team, bool inDB = true);
        void RemoveGraveYardLink(uint32 id, uint32 zone, uint32 team, bool inDB = false);
        void LoadGraveyardZones();
        GraveYardData const* FindGraveYardData(uint32 id, uint32 zone);

        AreaTrigger const* GetAreaTrigger(uint32 trigger) const
        {
            AreaTriggerMap::const_iterator itr = mAreaTriggers.find(trigger);
            if (itr != mAreaTriggers.end())
                return &itr->second;
            return NULL;
        }

        AccessRequirement const* GetAccessRequirement(uint32 mapid, Difficulty difficulty) const
        {
            AccessRequirementMap::const_iterator itr = mAccessRequirements.find(MAKE_PAIR32(mapid,difficulty));
            if (itr != mAccessRequirements.end())
                return &itr->second;
            return NULL;
        }

        AreaTrigger const* GetGoBackTrigger(uint32 Map) const;
        AreaTrigger const* GetMapEntranceTrigger(uint32 Map) const;

        uint32 GetAreaTriggerScriptId(uint32 trigger_id);
        SpellScriptsBounds GetSpellScriptsBounds(uint32 spell_id);

        RepRewardRate const* GetRepRewardRate(uint32 factionId) const
        {
            RepRewardRateMap::const_iterator itr = m_RepRewardRateMap.find(factionId);
            if (itr != m_RepRewardRateMap.end())
                return &itr->second;

            return NULL;
        }

        ReputationOnKillEntry const* GetReputationOnKilEntry(uint32 id) const
        {
            RepOnKillMap::const_iterator itr = mRepOnKill.find(id);
            if (itr != mRepOnKill.end())
                return &itr->second;
            return NULL;
        }

        RepSpilloverTemplate const* GetRepSpilloverTemplate(uint32 factionId) const
        {
            RepSpilloverTemplateMap::const_iterator itr = m_RepSpilloverTemplateMap.find(factionId);
            if (itr != m_RepSpilloverTemplateMap.end())
                return &itr->second;

            return NULL;
        }

        PointOfInterest const* GetPointOfInterest(uint32 id) const
        {
            PointOfInterestMap::const_iterator itr = mPointsOfInterest.find(id);
            if (itr != mPointsOfInterest.end())
                return &itr->second;
            return NULL;
        }

        QuestPOIVector const* GetQuestPOIVector(uint32 questId)
        {
            QuestPOIMap::const_iterator itr = mQuestPOIMap.find(questId);
            if (itr != mQuestPOIMap.end())
                return &itr->second;
            return NULL;
        }

        VehicleAccessoryList const* GetVehicleAccessoryList(uint32 uiEntry) const
        {
            VehicleAccessoryMap::const_iterator itr = m_VehicleAccessoryMap.find(uiEntry);
            if (itr != m_VehicleAccessoryMap.end())
                return &itr->second;
            return NULL;
        }

        VehicleScalingInfo const* GetVehicleScalingInfo(uint32 vehicleEntry) const
        {
            VehicleScalingMap::const_iterator itr = m_VehicleScalingMap.find(vehicleEntry);
            if (itr != m_VehicleScalingMap.end())
                return &itr->second;
            return NULL;
        }

        void LoadGuilds();
        void LoadArenaTeams();
        void LoadGroups();
        void LoadQuests();
        void LoadQuestRelations()
        {
            sLog.outString("Loading GO Start Quest Data...");
            LoadGameobjectQuestRelations();
            sLog.outString("Loading GO End Quest Data...");
            LoadGameobjectInvolvedRelations();
            sLog.outString("Loading Creature Start Quest Data...");
            LoadCreatureQuestRelations();
            sLog.outString("Loading Creature End Quest Data...");
            LoadCreatureInvolvedRelations();
        }
        void LoadGameobjectQuestRelations();
        void LoadGameobjectInvolvedRelations();
        void LoadCreatureQuestRelations();
        void LoadCreatureInvolvedRelations();

        QuestRelations* GetGOQuestRelationMap()
        {
            return &mGOQuestRelations;
        }

        QuestRelationBounds GetGOQuestRelationBounds(uint32 go_entry)
        {
            return mGOQuestRelations.equal_range(go_entry);
        }

        QuestRelationBounds GetGOQuestInvolvedRelationBounds(uint32 go_entry)
        {
            return mGOQuestInvolvedRelations.equal_range(go_entry);
        }

        QuestRelations* GetCreatureQuestRelationMap()
        {
            return &mCreatureQuestRelations;
        }

        QuestRelationBounds GetCreatureQuestRelationBounds(uint32 creature_entry)
        {
            return mCreatureQuestRelations.equal_range(creature_entry);
        }

        QuestRelationBounds GetCreatureQuestInvolvedRelationBounds(uint32 creature_entry)
        {
            return mCreatureQuestInvolvedRelations.equal_range(creature_entry);
        }

        void LoadGameObjectScripts();
        void LoadQuestEndScripts();
        void LoadQuestStartScripts();
        void LoadEventScripts();
        void LoadSpellScripts();
        void LoadGossipScripts();
        void LoadWaypointScripts();

        void LoadSpellScriptNames();
        void ValidateSpellScripts();

        bool LoadTrinityStrings(char const* table, int32 min_value, int32 max_value);
        bool LoadTrinityStrings() { return LoadTrinityStrings("trinity_string",MIN_TRINITY_STRING_ID,MAX_TRINITY_STRING_ID); }
        void LoadDbScriptStrings();
        void LoadCreatureClassLevelStats();
        void LoadCreatureLocales();
        void LoadCreatureTemplates();
        void CheckCreatureTemplate(CreatureInfo const* cInfo);
        void LoadCreatures();
        void LoadCreatureLinkedRespawn();
        bool CheckCreatureLinkedRespawn(uint32 guid, uint32 linkedGuid) const;
        bool SetCreatureLinkedRespawn(uint32 guid, uint32 linkedGuid);
        void LoadCreatureRespawnTimes();
        void LoadCreatureAddons();
        void LoadCreatureModelInfo();
        void LoadEquipmentTemplates();
        void LoadGameObjectLocales();
        void LoadGameobjects();
        void LoadGameobjectRespawnTimes();
        void LoadItemPrototypes();
        void LoadItemLocales();
        void LoadItemSetNames();
        void LoadItemSetNameLocales();
        void LoadQuestLocales();
        void LoadNpcTextLocales();
        void LoadPageTextLocales();
        void LoadGossipMenuItemsLocales();
        void LoadPointOfInterestLocales();
        void LoadInstanceTemplate();
        void LoadMailLevelRewards();
        void LoadVehicleAccessories();
        void LoadVehicleScaling();

        void LoadGossipText();

        void LoadAreaTriggerTeleports();
        void LoadAccessRequirements();
        void LoadQuestAreaTriggers();
        void LoadAreaTriggerScripts();
        void LoadTavernAreaTriggers();
        void LoadGameObjectForQuests();

        void LoadPageTexts();

        void LoadPlayerInfo();
        void LoadPetLevelInfo();
        void LoadExplorationBaseXP();
        void LoadPetNames();
        void LoadPetNumber();
        void LoadCorpses();
        void LoadFishingBaseSkillLevel();

        void LoadReputationRewardRate();
        void LoadReputationOnKill();
        void LoadReputationSpilloverTemplate();

        void LoadPointsOfInterest();
        void LoadQuestPOI();

        void LoadNPCSpellClickSpells();

        void LoadGameTele();

        void LoadNpcTextId();

        void LoadGossipMenu();
        void LoadGossipMenuItems();

        void LoadVendors();
        void LoadTrainerSpell();
        bool AddSpellToTrainer(uint32 entry, uint32 spell, Field *fields, std::set<uint32> *skip_trainers, std::set<uint32> *talentIds);
        int  LoadReferenceTrainer(uint32 trainer, int32 spell, std::set<uint32> *skip_trainers, std::set<uint32> *talentIds);

        std::string GeneratePetName(uint32 entry);
        uint32 GetBaseXP(uint8 level);
        uint32 GetXPForLevel(uint8 level);

        int32 GetFishingBaseSkillLevel(uint32 entry) const
        {
            FishingBaseSkillMap::const_iterator itr = mFishingBaseForArea.find(entry);
            return itr != mFishingBaseForArea.end() ? itr->second : 0;
        }

        void ReturnOrDeleteOldMails(bool serverUp);

        CreatureBaseStats const* GetCreatureBaseStats(uint8 level, uint8 unitClass);

        void SetHighestGuids();
        uint32 GenerateLowGuid(HighGuid guidhigh);
        uint32 GenerateArenaTeamId();
        uint32 GenerateAuctionID();
        uint64 GenerateEquipmentSetGuid();
        uint32 GenerateGuildId();
        uint32 GenerateMailID();
        uint32 GeneratePetNumber();

        typedef std::multimap<int32, uint32> ExclusiveQuestGroups;
        ExclusiveQuestGroups mExclusiveQuestGroups;

        MailLevelReward const* GetMailLevelReward(uint32 level,uint32 raceMask)
        {
            MailLevelRewardMap::const_iterator map_itr = m_mailLevelRewardMap.find(level);
            if (map_itr == m_mailLevelRewardMap.end())
                return NULL;

            for (MailLevelRewardList::const_iterator set_itr = map_itr->second.begin(); set_itr != map_itr->second.end(); ++set_itr)
                if (set_itr->raceMask & raceMask)
                    return &*set_itr;

            return NULL;
        }

        CellObjectGuids const& GetCellObjectGuids(uint16 mapid, uint8 spawnMode, uint32 cell_id)
        {
            return mMapObjectGuids[MAKE_PAIR32(mapid,spawnMode)][cell_id];
        }

        CreatureData const* GetCreatureData(uint32 guid) const
        {
            CreatureDataMap::const_iterator itr = mCreatureDataMap.find(guid);
            if (itr == mCreatureDataMap.end()) return NULL;
            return &itr->second;
        }
        CreatureData& NewOrExistCreatureData(uint32 guid) { return mCreatureDataMap[guid]; }
        void DeleteCreatureData(uint32 guid);
        uint32 GetLinkedRespawnGuid(uint32 guid) const
        {
            CreatureLinkedRespawnMap::const_iterator itr = mCreatureLinkedRespawnMap.find(guid);
            if (itr == mCreatureLinkedRespawnMap.end()) return 0;
            return itr->second;
        }
        CreatureLocale const* GetCreatureLocale(uint32 entry) const
        {
            CreatureLocaleMap::const_iterator itr = mCreatureLocaleMap.find(entry);
            if (itr == mCreatureLocaleMap.end()) return NULL;
            return &itr->second;
        }
        GameObjectLocale const* GetGameObjectLocale(uint32 entry) const
        {
            GameObjectLocaleMap::const_iterator itr = mGameObjectLocaleMap.find(entry);
            if (itr == mGameObjectLocaleMap.end()) return NULL;
            return &itr->second;
        }
        ItemLocale const* GetItemLocale(uint32 entry) const
        {
            ItemLocaleMap::const_iterator itr = mItemLocaleMap.find(entry);
            if (itr == mItemLocaleMap.end()) return NULL;
            return &itr->second;
        }
        ItemSetNameLocale const* GetItemSetNameLocale(uint32 entry) const
        {
            ItemSetNameLocaleMap::const_iterator itr = mItemSetNameLocaleMap.find(entry);
            if (itr == mItemSetNameLocaleMap.end())return NULL;
            return &itr->second;
        }
        QuestLocale const* GetQuestLocale(uint32 entry) const
        {
            QuestLocaleMap::const_iterator itr = mQuestLocaleMap.find(entry);
            if (itr == mQuestLocaleMap.end()) return NULL;
            return &itr->second;
        }
        NpcTextLocale const* GetNpcTextLocale(uint32 entry) const
        {
            NpcTextLocaleMap::const_iterator itr = mNpcTextLocaleMap.find(entry);
            if (itr == mNpcTextLocaleMap.end()) return NULL;
            return &itr->second;
        }
        PageTextLocale const* GetPageTextLocale(uint32 entry) const
        {
            PageTextLocaleMap::const_iterator itr = mPageTextLocaleMap.find(entry);
            if (itr == mPageTextLocaleMap.end()) return NULL;
            return &itr->second;
        }
        GossipMenuItemsLocale const* GetGossipMenuItemsLocale(uint32 entry) const
        {
            GossipMenuItemsLocaleMap::const_iterator itr = mGossipMenuItemsLocaleMap.find(entry);
            if (itr == mGossipMenuItemsLocaleMap.end()) return NULL;
            return &itr->second;
        }
        PointOfInterestLocale const* GetPointOfInterestLocale(uint32 poi_id) const
        {
            PointOfInterestLocaleMap::const_iterator itr = mPointOfInterestLocaleMap.find(poi_id);
            if (itr == mPointOfInterestLocaleMap.end()) return NULL;
            return &itr->second;
        }

        bool IsGoOfSpecificEntrySpawned(uint32 entry) const
        {
            for (GameObjectDataMap::const_iterator it = mGameObjectDataMap.begin(); it != mGameObjectDataMap.end(); ++it)
                if (it->second.id == entry)
                    return true;

            return false;
        }

        GameObjectData const* GetGOData(uint32 guid) const
        {
            GameObjectDataMap::const_iterator itr = mGameObjectDataMap.find(guid);
            if (itr == mGameObjectDataMap.end()) return NULL;
            return &itr->second;
        }
        GameObjectData& NewGOData(uint32 guid) { return mGameObjectDataMap[guid]; }
        void DeleteGOData(uint32 guid);

        TrinityStringLocale const* GetTrinityStringLocale(int32 entry) const
        {
            TrinityStringLocaleMap::const_iterator itr = mTrinityStringLocaleMap.find(entry);
            if (itr == mTrinityStringLocaleMap.end()) return NULL;
            return &itr->second;
        }
        const char *GetTrinityString(int32 entry, LocaleConstant locale_idx) const;
        const char *GetTrinityStringForDBCLocale(int32 entry) const { return GetTrinityString(entry,DBCLocaleIndex); }
        LocaleConstant GetDBCLocaleIndex() const { return DBCLocaleIndex; }
        void SetDBCLocaleIndex(LocaleConstant locale) { DBCLocaleIndex = locale; }

        void AddCorpseCellData(uint32 mapid, uint32 cellid, uint32 player_guid, uint32 instance);
        void DeleteCorpseCellData(uint32 mapid, uint32 cellid, uint32 player_guid);

        time_t GetCreatureRespawnTime(uint32 loguid, uint32 instance)
        {
            ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, m_CreatureRespawnTimesMtx, 0);
            return mCreatureRespawnTimes[MAKE_PAIR64(loguid,instance)];
        }
        void SaveCreatureRespawnTime(uint32 loguid, uint32 instance, time_t t);
        time_t GetGORespawnTime(uint32 loguid, uint32 instance)
        {
            ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, m_GORespawnTimesMtx, 0);
            return mGORespawnTimes[MAKE_PAIR64(loguid,instance)];
        }
        void SaveGORespawnTime(uint32 loguid, uint32 instance, time_t t);
        void DeleteRespawnTimeForInstance(uint32 instance);

        // grid objects
        void AddCreatureToGrid(uint32 guid, CreatureData const* data);
        void RemoveCreatureFromGrid(uint32 guid, CreatureData const* data);
        void AddGameobjectToGrid(uint32 guid, GameObjectData const* data);
        void RemoveGameobjectFromGrid(uint32 guid, GameObjectData const* data);
        uint32 AddGOData(uint32 entry, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay = 0, float rotation0 = 0, float rotation1 = 0, float rotation2 = 0, float rotation3 = 0);
        uint32 AddCreData(uint32 entry, uint32 team, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay = 0);
        bool MoveCreData(uint32 guid, uint32 map, Position pos);

        // reserved names
        void LoadReservedPlayersNames();
        bool IsReservedName(const std::string& name) const;

        // name with valid structure and symbols
        static uint8 CheckPlayerName(const std::string& name, bool create = false);
        static PetNameInvalidReason CheckPetName(const std::string& name);
        static bool IsValidCharterName(const std::string& name);

        static bool CheckDeclinedNames(std::wstring mainpart, DeclinedName const& names);

        GameTele const* GetGameTele(uint32 id) const
        {
            GameTeleMap::const_iterator itr = m_GameTeleMap.find(id);
            if (itr == m_GameTeleMap.end()) return NULL;
            return &itr->second;
        }
        GameTele const* GetGameTele(const std::string& name) const;
        GameTeleMap const& GetGameTeleMap() const { return m_GameTeleMap; }
        bool AddGameTele(GameTele& data);
        bool DeleteGameTele(const std::string& name);

        uint32 GetNpcGossip(uint32 entry) const
        {
            CacheNpcTextIdMap::const_iterator iter = m_mCacheNpcTextIdMap.find(entry);
            if (iter == m_mCacheNpcTextIdMap.end())
                return 0;

            return iter->second;
        }

        TrainerSpellData const* GetNpcTrainerSpells(uint32 entry) const
        {
            CacheTrainerSpellMap::const_iterator  iter = m_mCacheTrainerSpellMap.find(entry);
            if (iter == m_mCacheTrainerSpellMap.end())
                return NULL;

            return &iter->second;
        }

        VendorItemData const* GetNpcVendorItemList(uint32 entry) const
        {
            CacheVendorItemMap::const_iterator  iter = m_mCacheVendorItemMap.find(entry);
            if (iter == m_mCacheVendorItemMap.end())
                return NULL;

            return &iter->second;
        }
        void AddVendorItem(uint32 entry,uint32 item, int32 maxcount, uint32 incrtime, uint32 ExtendedCost, bool savetodb = true); // for event
        bool RemoveVendorItem(uint32 entry, uint32 item, bool savetodb = true); // for event
        bool IsVendorItemValid(uint32 vendor_entry, uint32 item, int32 maxcount, uint32 ptime, uint32 ExtendedCost, Player* pl = NULL, std::set<uint32>* skip_vendors = NULL, uint32 ORnpcflag = 0) const;

        void LoadScriptNames();
        ScriptNameMap &GetScriptNames() { return m_scriptNames; }
        const char * GetScriptName(uint32 id) { return id < m_scriptNames.size() ? m_scriptNames[id].c_str() : ""; }
        uint32 GetScriptId(const char *name);

        SpellClickInfoMapBounds GetSpellClickInfoMapBounds(uint32 creature_id) const
        {
            return SpellClickInfoMapBounds(mSpellClickInfoMap.lower_bound(creature_id),mSpellClickInfoMap.upper_bound(creature_id));
        }

        GossipMenusMapBounds GetGossipMenusMapBounds(uint32 uiMenuId) const
        {
            return GossipMenusMapBounds(m_mGossipMenusMap.lower_bound(uiMenuId),m_mGossipMenusMap.upper_bound(uiMenuId));
        }

        GossipMenusMapBoundsNonConst GetGossipMenusMapBoundsNonConst(uint32 uiMenuId)
        {
            return GossipMenusMapBoundsNonConst(m_mGossipMenusMap.lower_bound(uiMenuId),m_mGossipMenusMap.upper_bound(uiMenuId));
        }

        GossipMenuItemsMapBounds GetGossipMenuItemsMapBounds(uint32 uiMenuId) const
        {
            return GossipMenuItemsMapBounds(m_mGossipMenuItemsMap.lower_bound(uiMenuId),m_mGossipMenuItemsMap.upper_bound(uiMenuId));
        }
        GossipMenuItemsMapBoundsNonConst GetGossipMenuItemsMapBoundsNonConst(uint32 uiMenuId)
        {
            return GossipMenuItemsMapBoundsNonConst(m_mGossipMenuItemsMap.lower_bound(uiMenuId),m_mGossipMenuItemsMap.upper_bound(uiMenuId));
        }

        // for wintergrasp only
        GraveYardMap        mGraveYardMap;

        void AddLocaleString(std::string& s, LocaleConstant locale, StringVector& data);
        inline void GetLocaleString(const StringVector& data, int loc_idx, std::string& value) const
        {
            if (data.size() > size_t(loc_idx) && !data[loc_idx].empty())
                value = data[loc_idx];
        }

        CharacterConversionMap factionchange_achievements;
        CharacterConversionMap factionchange_items;
        CharacterConversionMap factionchange_spells;
        CharacterConversionMap factionchange_reputations;

        void LoadFactionChangeAchievements();
        void LoadFactionChangeItems();
        void LoadFactionChangeSpells();
        void LoadFactionChangeReputations();

    protected:

        // first free id for selected id type
        uint32 m_arenaTeamId;
        uint32 m_auctionid;
        uint64 m_equipmentSetGuid;
        uint32 m_guildId;
        uint32 m_ItemTextId;
        uint32 m_mailid;
        uint32 m_hiPetNumber;

        // first free low guid for seelcted guid type
        uint32 m_hiCharGuid;
        uint32 m_hiCreatureGuid;
        uint32 m_hiPetGuid;
        uint32 m_hiVehicleGuid;
        uint32 m_hiItemGuid;
        uint32 m_hiGoGuid;
        uint32 m_hiDoGuid;
        uint32 m_hiCorpseGuid;
        uint32 m_hiGroupGuid;
        uint32 m_hiMoTransGuid;

        QuestMap            mQuestTemplates;

        typedef UNORDERED_MAP<uint32, GossipText> GossipTextMap;
        typedef UNORDERED_MAP<uint32, uint32> QuestAreaTriggerMap;
        typedef std::set<uint32> TavernAreaTriggerSet;
        typedef std::set<uint32> GameObjectForQuestSet;

        GroupSet            mGroupSet;
        GuildMap            mGuildMap;
        ArenaTeamMap        mArenaTeamMap;

        QuestAreaTriggerMap mQuestAreaTriggerMap;
        TavernAreaTriggerSet mTavernAreaTriggerSet;
        GameObjectForQuestSet mGameObjectForQuestSet;
        GossipTextMap       mGossipText;
        AreaTriggerMap      mAreaTriggers;
        AreaTriggerScriptMap  mAreaTriggerScripts;
        AccessRequirementMap  mAccessRequirements;

        RepRewardRateMap    m_RepRewardRateMap;
        RepOnKillMap        mRepOnKill;
        RepSpilloverTemplateMap m_RepSpilloverTemplateMap;

        GossipMenusMap      m_mGossipMenusMap;
        GossipMenuItemsMap  m_mGossipMenuItemsMap;
        PointOfInterestMap  mPointsOfInterest;

        QuestPOIMap         mQuestPOIMap;

        QuestRelations mGOQuestRelations;
        QuestRelations mGOQuestInvolvedRelations;
        QuestRelations mCreatureQuestRelations;
        QuestRelations mCreatureQuestInvolvedRelations;

        //character reserved names
        typedef std::set<std::wstring> ReservedNamesMap;
        ReservedNamesMap    m_ReservedNames;

//        GraveYardMap        mGraveYardMap;

        GameTeleMap         m_GameTeleMap;

        ScriptNameMap       m_scriptNames;

        SpellClickInfoMap   mSpellClickInfoMap;

        SpellScriptsMap     mSpellScripts;

        ItemRequiredTargetMap m_ItemRequiredTarget;

        VehicleAccessoryMap m_VehicleAccessoryMap;
        VehicleScalingMap m_VehicleScalingMap;

        typedef             std::vector<LocaleConstant> LocalForIndex;
        LocalForIndex        m_LocalForIndex;

        LocaleConstant DBCLocaleIndex;

    private:
        void LoadScripts(ScriptsType type);
        void CheckScripts(ScriptsType type, std::set<int32>& ids);
        void LoadCreatureAddons(SQLStorage& creatureaddons, char const* entryName, char const* comment);
        void ConvertCreatureAddonAuras(CreatureDataAddon* addon, char const* table, char const* guidEntryStr);
        void LoadQuestRelationsHelper(QuestRelations& map, std::string table, bool starter, bool go);
        void PlayerCreateInfoAddItemHelper(uint32 race_, uint32 class_, uint32 itemId, int32 count);

        MailLevelRewardMap m_mailLevelRewardMap;

        CreatureBaseStatsMap m_creatureBaseStatsMap;

        typedef std::map<uint32,PetLevelInfo*> PetLevelInfoMap;
        // PetLevelInfoMap[creature_id][level]
        PetLevelInfoMap petInfo;                            // [creature_id][level]

        PlayerClassInfo playerClassInfo[MAX_CLASSES];

        void BuildPlayerLevelInfo(uint8 race, uint8 class_, uint8 level, PlayerLevelInfo* plinfo) const;
        PlayerInfo playerInfo[MAX_RACES][MAX_CLASSES];

        typedef std::vector<uint32> PlayerXPperLevel;       // [level]
        PlayerXPperLevel mPlayerXPperLevel;

        typedef std::map<uint32,uint32> BaseXPMap;          // [area level][base xp]
        BaseXPMap mBaseXPTable;

        typedef std::map<uint32,int32> FishingBaseSkillMap; // [areaId][base skill level]
        FishingBaseSkillMap mFishingBaseForArea;

        typedef std::map<uint32, StringVector> HalfNameMap;
        HalfNameMap PetHalfName0;
        HalfNameMap PetHalfName1;

        typedef UNORDERED_MAP<uint32, ItemSetNameEntry> ItemSetNameMap;
        ItemSetNameMap mItemSetNameMap;

        MapObjectGuids mMapObjectGuids;
        CreatureDataMap mCreatureDataMap;
        CreatureLinkedRespawnMap mCreatureLinkedRespawnMap;
        CreatureLocaleMap mCreatureLocaleMap;
        GameObjectDataMap mGameObjectDataMap;
        GameObjectLocaleMap mGameObjectLocaleMap;
        ItemLocaleMap mItemLocaleMap;
        ItemSetNameLocaleMap mItemSetNameLocaleMap;
        QuestLocaleMap mQuestLocaleMap;
        NpcTextLocaleMap mNpcTextLocaleMap;
        PageTextLocaleMap mPageTextLocaleMap;
        TrinityStringLocaleMap mTrinityStringLocaleMap;
        GossipMenuItemsLocaleMap mGossipMenuItemsLocaleMap;
        PointOfInterestLocaleMap mPointOfInterestLocaleMap;
        RespawnTimes mCreatureRespawnTimes;
        ACE_Thread_Mutex m_CreatureRespawnTimesMtx;
        RespawnTimes mGORespawnTimes;
        ACE_Thread_Mutex m_GORespawnTimesMtx;

        CacheNpcTextIdMap m_mCacheNpcTextIdMap;
        CacheVendorItemMap m_mCacheVendorItemMap;
        CacheTrainerSpellMap m_mCacheTrainerSpellMap;

        std::set<uint32> difficultyEntries[MAX_DIFFICULTY - 1]; // already loaded difficulty 1 value in creatures, used in CheckCreatureTemplate
        std::set<uint32> hasDifficultyEntries[MAX_DIFFICULTY - 1]; // already loaded creatures with difficulty 1 values, used in CheckCreatureTemplate

};

#define sObjectMgr (*ACE_Singleton<ObjectMgr, ACE_Null_Mutex>::instance())

// scripting access functions
 bool LoadTrinityStrings(char const* table,int32 start_value = MAX_CREATURE_AI_TEXT_STRING_ID, int32 end_value = std::numeric_limits<int32>::min());
 uint32 GetAreaTriggerScriptId(uint32 trigger_id);
 uint32 GetScriptId(const char *name);
 ObjectMgr::ScriptNameMap& GetScriptNames();
 GameObjectInfo const *GetGameObjectInfo(uint32 id);
 CreatureInfo const *GetCreatureInfo(uint32 id);
 CreatureInfo const* GetCreatureTemplateStore(uint32 entry);
 Quest const* GetQuestTemplateStore(uint32 entry);

#endif
