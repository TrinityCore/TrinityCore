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

#ifndef __TRINITY_ACHIEVEMENTMGR_H
#define __TRINITY_ACHIEVEMENTMGR_H

#include <map>
#include <string>

#include "Common.h"
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "DBCStores.h"
#include "ObjectGuid.h"

class Unit;
class Player;
class WorldPacket;

struct ModifierTreeNode
{
    ModifierTreeEntry const* Entry;
    std::vector<ModifierTreeNode const*> Children;
};

typedef std::unordered_map<uint32, ModifierTreeNode*> ModifierTreeMap;

struct AchievementCriteria
{
    uint32 ID;
    CriteriaEntry const* Entry;
    ModifierTreeNode const* Modifier;
};

typedef std::vector<AchievementCriteria const*> AchievementCriteriaList;
typedef std::unordered_map<uint32, AchievementCriteria*> AchievementCriteriaMap;

struct AchievementCriteriaTree
{
    uint32 ID;
    CriteriaTreeEntry const* Entry;
    AchievementEntry const* Achievement;
    AchievementCriteria const* Criteria;
    std::vector<AchievementCriteriaTree const*> Children;
};

typedef std::unordered_map<uint32, AchievementCriteriaTree*> AchievementCriteriaTreeMap;
typedef std::vector<AchievementCriteriaTree const*> AchievementCriteriaTreeList;
typedef std::vector<AchievementEntry const*>        AchievementEntryList;
typedef std::unordered_map<uint32, AchievementCriteriaTreeList> AchievementCriteriaTreeByCriteriaMap;

typedef std::unordered_map<uint32, AchievementEntryList>        AchievementListByReferencedId;

struct CriteriaProgress
{
    uint64 counter;
    time_t date;                                            // latest update time.
    ObjectGuid PlayerGUID;                               // GUID of the player that completed this criteria (guild achievements)
    bool changed;
};

enum AchievementCriteriaDataType
{                                                            // value1         value2        comment
    ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE                = 0,  // 0              0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE          = 1,  // creature_id    0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE = 2,  // class_id       race_id
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH= 3,  // health_percent 0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA              = 5,  // spell_id       effect_idx
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA              = 7,  // spell_id       effect_idx
    ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE               = 8,  // minvalue                     value provided with achievement update must be not less that limit
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL             = 9,  // minlevel                     minlevel of target
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER            = 10, // gender                       0=male; 1=female
    ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT              = 11, // scripted requirement
    // REUSE
    ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT    = 13, // count                        "with less than %u people in the zone"
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM              = 14, // team                         HORDE(67), ALLIANCE(469)
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK             = 15, // drunken_state  0             (enum DrunkenState) of player
    ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY             = 16, // holiday_id     0             event in holiday time
    ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE  = 17, // min_score      max_score     player's team win bg and opposition team have team score in range
    ACHIEVEMENT_CRITERIA_DATA_TYPE_INSTANCE_SCRIPT     = 18, // 0              0             maker instance script call for check current criteria requirements fit
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPED_ITEM      = 19, // item_level     item_quality  for equipped item in slot to check item level and quality
    ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_ID              = 20, // map_id         0             player must be on map with id in map_id
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE = 21, // class_id       race_id
    // REUSE
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_KNOWN_TITLE       = 23, // title_id                     known (pvp) title, values from dbc
    ACHIEVEMENT_CRITERIA_DATA_TYPE_GAME_EVENT          = 24, // game_event_id  0

    MAX_ACHIEVEMENT_CRITERIA_DATA_TYPE
};

struct AchievementCriteriaData
{
    AchievementCriteriaDataType dataType;
    union
    {
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE              = 0 (no data)
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE        = 1
        struct
        {
            uint32 id;
        } creature;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE = 2
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_S_PLAYER_CLASS_RACE = 21
        struct
        {
            uint32 class_id;
            uint32 race_id;
        } classRace;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH = 3
        struct
        {
            uint32 percent;
        } health;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA            = 5
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA            = 7
        struct
        {
            uint32 spell_id;
            uint32 effect_idx;
        } aura;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE             = 8
        struct
        {
            uint32 value;
            uint32 compType;
        } value;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL           = 9
        struct
        {
            uint32 minlevel;
        } level;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_GENDER          = 10
        struct
        {
            uint32 gender;
        } gender;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_SCRIPT            = 11 (no data)
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_PLAYER_COUNT  = 13
        struct
        {
            uint32 maxcount;
        } map_players;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_TEAM            = 14
        struct
        {
            uint32 team;
        } team;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_S_DRUNK           = 15
        struct
        {
            uint32 state;
        } drunk;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_HOLIDAY           = 16
        struct
        {
            uint32 id;
        } holiday;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_BG_LOSS_TEAM_SCORE= 17
        struct
        {
            uint32 min_score;
            uint32 max_score;
        } bg_loss_team_score;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_INSTANCE_SCRIPT   = 18 (no data)
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_S_EQUIPED_ITEM    = 19
        struct
        {
            uint32 item_level;
            uint32 item_quality;
        } equipped_item;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_MAP_ID            = 20
        struct
        {
            uint32 mapId;
        } map_id;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_KNOWN_TITLE       = 22
        struct
        {
            uint32 title_id;
        } known_title;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_GAME_EVENT           = 24
        struct
        {
            uint32 id;
        } game_event;
        // raw
        struct
        {
            uint32 value1;
            uint32 value2;
        } raw;
    };
    uint32 ScriptId;

    AchievementCriteriaData() : dataType(ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE)
    {
        raw.value1 = 0;
        raw.value2 = 0;
        ScriptId = 0;
    }

    AchievementCriteriaData(uint32 _dataType, uint32 _value1, uint32 _value2, uint32 _scriptId) : dataType(AchievementCriteriaDataType(_dataType))
    {
        raw.value1 = _value1;
        raw.value2 = _value2;
        ScriptId = _scriptId;
    }

    bool IsValid(AchievementCriteria const* criteria);
    bool Meets(uint32 criteria_id, Player const* source, Unit const* target, uint32 miscValue1 = 0) const;
};

struct AchievementCriteriaDataSet
{
        AchievementCriteriaDataSet() : criteria_id(0) { }
        typedef std::vector<AchievementCriteriaData> Storage;
        void Add(AchievementCriteriaData const& data) { storage.push_back(data); }
        bool Meets(Player const* source, Unit const* target, uint32 miscValue = 0) const;
        void SetCriteriaId(uint32 id) {criteria_id = id;}
    private:
        uint32 criteria_id;
        Storage storage;
};

typedef std::map<uint32, AchievementCriteriaDataSet> AchievementCriteriaDataMap;

struct AchievementReward
{
    uint32 titleId[2];
    uint32 itemId;
    uint32 sender;
    std::string subject;
    std::string text;
    uint32 mailTemplate;
};

typedef std::unordered_map<uint32, AchievementReward> AchievementRewards;

struct AchievementRewardLocale
{
    std::vector<std::string> subject;
    std::vector<std::string> text;
};

typedef std::unordered_map<uint32, AchievementRewardLocale> AchievementRewardLocales;

struct CompletedAchievementData
{
    time_t date;
    GuidSet guids;
    bool changed;
};

typedef std::unordered_map<uint32, CriteriaProgress> CriteriaProgressMap;
typedef std::unordered_map<uint32, CompletedAchievementData> CompletedAchievementMap;

enum ProgressType
{
    PROGRESS_SET,
    PROGRESS_ACCUMULATE,
    PROGRESS_HIGHEST
};

template<class T>
class AchievementMgr
{
    public:
        AchievementMgr(T* owner);
        ~AchievementMgr();

        void Reset();
        static void DeleteFromDB(ObjectGuid lowguid);
        void LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult);
        void SaveToDB(SQLTransaction& trans);
        void ResetAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, bool evenIfCriteriaComplete = false);
        void UpdateAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, uint64 miscValue3 = 0, Unit const* unit = NULL, Player* referencePlayer = NULL);
        void CompletedAchievement(AchievementEntry const* entry, Player* referencePlayer);
        void CheckAllAchievementCriteria(Player* referencePlayer);
        void SendAllAchievementData(Player* receiver) const;
        void SendAllTrackedCriterias(Player* receiver, std::set<uint32> const& trackedCriterias) const;
        void SendAchievementInfo(Player* receiver, uint32 achievementId = 0) const;
        bool HasAchieved(uint32 achievementId) const;
        T* GetOwner() const { return _owner; }

        void UpdateTimedAchievements(uint32 timeDiff);
        void StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry, uint32 timeLost = 0);
        void RemoveTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry);   // used for quest and scripted timed achievements

        uint32 GetAchievementPoints() const { return _achievementPoints; }
    private:
        void SendAchievementEarned(AchievementEntry const* achievement) const;
        void SendCriteriaUpdate(AchievementCriteria const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const;
        CriteriaProgress* GetCriteriaProgress(AchievementCriteria const* entry);
        void SetCriteriaProgress(AchievementCriteria const* entry, uint64 changeValue, Player* referencePlayer, ProgressType ptype = PROGRESS_SET);
        void RemoveCriteriaProgress(AchievementCriteria const* entry);
        void CompletedCriteriaFor(AchievementEntry const* achievement, Player* referencePlayer);
        bool IsCompletedCriteriaTree(AchievementCriteriaTree const* tree);
        bool IsCompletedCriteria(AchievementCriteria const* achievementCriteria, uint64 requiredAmount);
        uint64 GetTotalCriteriaTreeProgress(AchievementCriteriaTree const* criteriaTree);
        bool IsCompletedAchievement(AchievementEntry const* entry);
        bool CanUpdateCriteria(AchievementCriteria const* criteria, AchievementCriteriaTreeList const* trees, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer);
        void SendPacket(WorldPacket const* data) const;

        bool ConditionsSatisfied(AchievementCriteria const* criteria, Player* referencePlayer) const;
        bool RequirementsSatisfied(AchievementCriteria const* criteria, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer) const;
        bool AdditionalRequirementsSatisfied(ModifierTreeNode const* parent, uint64 miscValue1, uint64 miscValue2, Unit const* unit, Player* referencePlayer) const;

        T* _owner;
        CriteriaProgressMap m_criteriaProgress;
        CompletedAchievementMap m_completedAchievements;
        typedef std::map<uint32, uint32> TimedAchievementMap;
        TimedAchievementMap m_timedAchievements;      // Criteria tree id/time left in MS
        uint32 _achievementPoints;
};

class AchievementGlobalMgr
{
        AchievementGlobalMgr() { }
        ~AchievementGlobalMgr();

    public:
        static char const* GetCriteriaTypeString(AchievementCriteriaTypes type);
        static char const* GetCriteriaTypeString(uint32 type);

        static AchievementGlobalMgr* instance()
        {
            static AchievementGlobalMgr instance;
            return &instance;
        }

        AchievementCriteriaTreeList const* GetAchievementCriteriaTreesByCriteria(uint32 criteriaId) const
        {
            auto itr = _achievementCriteriaTreeByCriteria.find(criteriaId);
            return itr != _achievementCriteriaTreeByCriteria.end() ? &itr->second : nullptr;
        }

        AchievementCriteriaList const& GetAchievementCriteriaByType(AchievementCriteriaTypes type, bool guild = false) const
        {
            return guild ? _guildAchievementCriteriasByType[type] : _achievementCriteriasByType[type];
        }

        AchievementCriteriaList const& GetTimedAchievementCriteriaByType(AchievementCriteriaTimedTypes type) const
        {
            return _achievementCriteriasByTimedType[type];
        }

        AchievementEntryList const* GetAchievementByReferencedId(uint32 id) const
        {
            AchievementListByReferencedId::const_iterator itr = _achievementListByReferencedId.find(id);
            return itr != _achievementListByReferencedId.end() ? &itr->second : NULL;
        }

        AchievementReward const* GetAchievementReward(AchievementEntry const* achievement) const
        {
            AchievementRewards::const_iterator iter = _achievementRewards.find(achievement->ID);
            return iter != _achievementRewards.end() ? &iter->second : NULL;
        }

        AchievementRewardLocale const* GetAchievementRewardLocale(AchievementEntry const* achievement) const
        {
            AchievementRewardLocales::const_iterator iter = _achievementRewardLocales.find(achievement->ID);
            return iter != _achievementRewardLocales.end() ? &iter->second : NULL;
        }

        AchievementCriteriaDataSet const* GetCriteriaDataSet(AchievementCriteria const* achievementCriteria) const
        {
            AchievementCriteriaDataMap::const_iterator iter = _criteriaDataMap.find(achievementCriteria->ID);
            return iter != _criteriaDataMap.end() ? &iter->second : NULL;
        }

        bool IsRealmCompleted(AchievementEntry const* achievement, uint32 instanceId) const
        {
            AllCompletedAchievements::const_iterator itr = _allCompletedAchievements.find(achievement->ID);
            if (itr == _allCompletedAchievements.end())
                return false;

            if (achievement->Flags & ACHIEVEMENT_FLAG_REALM_FIRST_KILL)
                return itr->second != instanceId;

            return true;
        }

        void SetRealmCompleted(AchievementEntry const* achievement, uint32 instanceId)
        {
            if (IsRealmCompleted(achievement, instanceId))
                return;

            _allCompletedAchievements[achievement->ID] = instanceId;
        }

        bool IsGroupCriteriaType(AchievementCriteriaTypes type) const
        {
            switch (type)
            {
                case ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE:
                case ACHIEVEMENT_CRITERIA_TYPE_WIN_BG:
                case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET:         // NYI
                case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_ARENA:
                case ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2:        // NYI
                case ACHIEVEMENT_CRITERIA_TYPE_WIN_RATED_BATTLEGROUND:  // NYI
                    return true;
                default:
                    break;
            }

            return false;
        }

        // Removes instanceId as valid id to complete realm first kill achievements
        void OnInstanceDestroyed(uint32 instanceId);

        void LoadAchievementCriteriaModifiersTree();
        void LoadAchievementCriteriaList();
        void LoadAchievementCriteriaData();
        void LoadAchievementReferenceList();
        void LoadCompletedAchievements();
        void LoadRewards();
        void LoadRewardLocales();
        AchievementEntry const* GetAchievement(uint32 achievementId) const;
        AchievementCriteriaTree const* GetAchievementCriteriaTree(uint32 criteriaTreeId) const;
        AchievementCriteria const* GetAchievementCriteria(uint32 criteriaId) const;
    private:
        AchievementCriteriaDataMap _criteriaDataMap;

        AchievementCriteriaTreeMap _achievementCriteriaTrees;
        AchievementCriteriaMap _achievementCriteria;
        ModifierTreeMap _criteriaModifiers;

        AchievementCriteriaTreeByCriteriaMap _achievementCriteriaTreeByCriteria;

        // store achievement criterias by type to speed up lookup
        AchievementCriteriaList _achievementCriteriasByType[ACHIEVEMENT_CRITERIA_TYPE_TOTAL];
        AchievementCriteriaList _guildAchievementCriteriasByType[ACHIEVEMENT_CRITERIA_TYPE_TOTAL];

        AchievementCriteriaList _achievementCriteriasByTimedType[ACHIEVEMENT_TIMED_TYPE_MAX];

        // store achievements by referenced achievement id to speed up lookup
        AchievementListByReferencedId _achievementListByReferencedId;

        typedef std::map<uint32 /*achievementId*/, uint32 /*instanceId*/> AllCompletedAchievements;
        AllCompletedAchievements _allCompletedAchievements;

        AchievementRewards _achievementRewards;
        AchievementRewardLocales _achievementRewardLocales;
};

#define sAchievementMgr AchievementGlobalMgr::instance()

#endif
