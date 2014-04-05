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

#ifndef __TRINITY_ACHIEVEMENTMGR_H
#define __TRINITY_ACHIEVEMENTMGR_H

#include <map>
#include <string>

#include "Common.h"
#include <ace/Singleton.h>
#include "DatabaseEnv.h"
#include "DBCEnums.h"
#include "DBCStores.h"

class Unit;
class Player;
class WorldPacket;

typedef std::vector<AchievementCriteriaEntry const*> AchievementCriteriaEntryList;
typedef std::vector<AchievementEntry const*>         AchievementEntryList;

typedef UNORDERED_MAP<uint32, AchievementCriteriaEntryList> AchievementCriteriaListByAchievement;
typedef UNORDERED_MAP<uint32, AchievementEntryList>         AchievementListByReferencedId;

struct CriteriaProgress
{
    uint64 counter;
    time_t date;                                            // latest update time.
    uint64 CompletedGUID;                                   // GUID of the player that completed this criteria (guild achievements)
    bool changed;
};

enum AchievementCriteriaDataType
{                                                           // value1         value2        comment
    ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE                = 0, // 0              0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE          = 1, // creature_id    0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE = 2, // class_id       race_id
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH= 3, // health_percent 0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA              = 5, // spell_id       effect_idx
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA              = 7, // spell_id       effect_idx
    ACHIEVEMENT_CRITERIA_DATA_TYPE_VALUE               = 8, // minvalue                     value provided with achievement update must be not less that limit
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_LEVEL             = 9, // minlevel                     minlevel of target
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
    ACHIEVEMENT_CRITERIA_DATA_TYPE_NTH_BIRTHDAY        = 22, // N                            login on day of N-th Birthday
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_KNOWN_TITLE       = 23  // title_id                     known (pvp) title, values from dbc
};

#define MAX_ACHIEVEMENT_CRITERIA_DATA_TYPE               24 // maximum value in AchievementCriteriaDataType enum

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
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_NTH_BIRTHDAY      = 21
        struct
        {
            uint32 nth_birthday;
        } birthday_login;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_KNOWN_TITLE       = 22
        struct
        {
            uint32 title_id;
        } known_title;
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

    bool IsValid(AchievementCriteriaEntry const* criteria);
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

typedef UNORDERED_MAP<uint32, AchievementReward> AchievementRewards;

struct AchievementRewardLocale
{
    std::vector<std::string> subject;
    std::vector<std::string> text;
};

typedef UNORDERED_MAP<uint32, AchievementRewardLocale> AchievementRewardLocales;

struct CompletedAchievementData
{
    time_t date;
    std::set<uint64> guids;
    bool changed;
};

typedef UNORDERED_MAP<uint32, CriteriaProgress> CriteriaProgressMap;
typedef UNORDERED_MAP<uint32, CompletedAchievementData> CompletedAchievementMap;

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
        static void DeleteFromDB(uint32 lowguid);
        void LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult);
        void SaveToDB(SQLTransaction& trans);
        void ResetAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, bool evenIfCriteriaComplete = false);
        void UpdateAchievementCriteria(AchievementCriteriaTypes type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, uint64 miscValue3 = 0, Unit const* unit = NULL, Player* referencePlayer = NULL);
        void CompletedAchievement(AchievementEntry const* entry, Player* referencePlayer);
        void CheckAllAchievementCriteria(Player* referencePlayer);
        void SendAllAchievementData(Player* receiver) const;
        void SendAchievementInfo(Player* receiver, uint32 achievementId = 0) const;
        bool HasAchieved(uint32 achievementId) const;
        T* GetOwner() const { return _owner; }

        void UpdateTimedAchievements(uint32 timeDiff);
        void StartTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry, uint32 timeLost = 0);
        void RemoveTimedAchievement(AchievementCriteriaTimedTypes type, uint32 entry);   // used for quest and scripted timed achievements

        uint32 GetAchievementPoints() const { return _achievementPoints; }
    private:
        void SendAchievementEarned(AchievementEntry const* achievement) const;
        void SendCriteriaUpdate(AchievementCriteriaEntry const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const;
        CriteriaProgress* GetCriteriaProgress(AchievementCriteriaEntry const* entry);
        void SetCriteriaProgress(AchievementCriteriaEntry const* entry, uint64 changeValue, Player* referencePlayer, ProgressType ptype = PROGRESS_SET);
        void RemoveCriteriaProgress(AchievementCriteriaEntry const* entry);
        void CompletedCriteriaFor(AchievementEntry const* achievement, Player* referencePlayer);
        bool IsCompletedCriteria(AchievementCriteriaEntry const* achievementCriteria, AchievementEntry const* achievement);
        bool IsCompletedAchievement(AchievementEntry const* entry);
        bool CanUpdateCriteria(AchievementCriteriaEntry const* criteria, AchievementEntry const* achievement, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer);
        void SendPacket(WorldPacket* data) const;

        bool ConditionsSatisfied(AchievementCriteriaEntry const* criteria, Player* referencePlayer) const;
        bool RequirementsSatisfied(AchievementCriteriaEntry const* criteria, uint64 miscValue1, uint64 miscValue2, uint64 miscValue3, Unit const* unit, Player* referencePlayer) const;
        bool AdditionalRequirementsSatisfied(AchievementCriteriaEntry const* criteria, uint64 miscValue1, uint64 miscValue2, Unit const* unit, Player* referencePlayer) const;

        T* _owner;
        CriteriaProgressMap m_criteriaProgress;
        CompletedAchievementMap m_completedAchievements;
        typedef std::map<uint32, uint32> TimedAchievementMap;
        TimedAchievementMap m_timedAchievements;      // Criteria id/time left in MS
        uint32 _achievementPoints;
};

class AchievementGlobalMgr
{
        friend class ACE_Singleton<AchievementGlobalMgr, ACE_Null_Mutex>;
        AchievementGlobalMgr() { }
        ~AchievementGlobalMgr() { }

    public:
        static char const* GetCriteriaTypeString(AchievementCriteriaTypes type);
        static char const* GetCriteriaTypeString(uint32 type);

        AchievementCriteriaEntryList const& GetAchievementCriteriaByType(AchievementCriteriaTypes type, bool guild = false) const
        {
            return guild ? m_GuildAchievementCriteriasByType[type] : m_AchievementCriteriasByType[type];
        }

        AchievementCriteriaEntryList const& GetTimedAchievementCriteriaByType(AchievementCriteriaTimedTypes type) const
        {
            return m_AchievementCriteriasByTimedType[type];
        }

        AchievementCriteriaEntryList const* GetAchievementCriteriaByAchievement(uint32 id) const
        {
            AchievementCriteriaListByAchievement::const_iterator itr = m_AchievementCriteriaListByAchievement.find(id);
            return itr != m_AchievementCriteriaListByAchievement.end() ? &itr->second : NULL;
        }

        AchievementEntryList const* GetAchievementByReferencedId(uint32 id) const
        {
            AchievementListByReferencedId::const_iterator itr = m_AchievementListByReferencedId.find(id);
            return itr != m_AchievementListByReferencedId.end() ? &itr->second : NULL;
        }

        AchievementReward const* GetAchievementReward(AchievementEntry const* achievement) const
        {
            AchievementRewards::const_iterator iter = m_achievementRewards.find(achievement->ID);
            return iter != m_achievementRewards.end() ? &iter->second : NULL;
        }

        AchievementRewardLocale const* GetAchievementRewardLocale(AchievementEntry const* achievement) const
        {
            AchievementRewardLocales::const_iterator iter = m_achievementRewardLocales.find(achievement->ID);
            return iter != m_achievementRewardLocales.end() ? &iter->second : NULL;
        }

        AchievementCriteriaDataSet const* GetCriteriaDataSet(AchievementCriteriaEntry const* achievementCriteria) const
        {
            AchievementCriteriaDataMap::const_iterator iter = m_criteriaDataMap.find(achievementCriteria->ID);
            return iter != m_criteriaDataMap.end() ? &iter->second : NULL;
        }

        bool IsRealmCompleted(AchievementEntry const* achievement) const
        {
            return m_allCompletedAchievements.find(achievement->ID) != m_allCompletedAchievements.end();
        }

        void SetRealmCompleted(AchievementEntry const* achievement)
        {
            m_allCompletedAchievements.insert(achievement->ID);
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

        void LoadAchievementCriteriaList();
        void LoadAchievementCriteriaData();
        void LoadAchievementReferenceList();
        void LoadCompletedAchievements();
        void LoadRewards();
        void LoadRewardLocales();
        AchievementEntry const* GetAchievement(uint32 achievementId) const;
        AchievementCriteriaEntry const* GetAchievementCriteria(uint32 achievementId) const;
    private:
        AchievementCriteriaDataMap m_criteriaDataMap;

        // store achievement criterias by type to speed up lookup
        AchievementCriteriaEntryList m_AchievementCriteriasByType[ACHIEVEMENT_CRITERIA_TYPE_TOTAL];
        AchievementCriteriaEntryList m_GuildAchievementCriteriasByType[ACHIEVEMENT_CRITERIA_TYPE_TOTAL];

        AchievementCriteriaEntryList m_AchievementCriteriasByTimedType[ACHIEVEMENT_TIMED_TYPE_MAX];

        // store achievement criterias by achievement to speed up lookup
        AchievementCriteriaListByAchievement m_AchievementCriteriaListByAchievement;

        // store achievements by referenced achievement id to speed up lookup
        AchievementListByReferencedId m_AchievementListByReferencedId;

        typedef std::set<uint32> AllCompletedAchievements;
        AllCompletedAchievements m_allCompletedAchievements;

        AchievementRewards m_achievementRewards;
        AchievementRewardLocales m_achievementRewardLocales;
};

#define sAchievementMgr ACE_Singleton<AchievementGlobalMgr, ACE_Null_Mutex>::instance()

#endif
