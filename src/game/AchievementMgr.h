/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __MANGOS_ACHIEVEMENTMGR_H
#define __MANGOS_ACHIEVEMENTMGR_H

#include "Common.h"
#include "Policies/Singleton.h"
#include "Database/DatabaseEnv.h"
#include "DBCEnums.h"
#include "DBCStores.h"

#include <map>
#include <string>

typedef std::list<AchievementCriteriaEntry const*> AchievementCriteriaEntryList;
typedef std::list<AchievementEntry const*>         AchievementEntryList;

typedef std::map<uint32,AchievementCriteriaEntryList> AchievementCriteriaListByAchievement;
typedef std::map<uint32,AchievementEntryList>         AchievementListByReferencedId;

struct CriteriaProgress
{
    uint32 counter;
    time_t date;
    bool changed;
};

enum AchievementCriteriaDataType
{                                                           // value1         value2        comment
    ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE                = 0, // 0              0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE          = 1, // creature_id    0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE = 2, // class_id       race_id
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH= 3, // health_percent 0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_DEAD       = 4, // 0              0             not corpse (not released body)
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA              = 5, // spell_id       effect_idx
    ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA              = 6, // area id        0
    ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA              = 7, // spell_id       effect_idx
};

#define MAX_ACHIEVEMENT_CRITERIA_DATA_TYPE               8  // maximum value in AchievementCriteriaDataType enum

class Player;
class Unit;

struct AchievementCriteriaData
{
    AchievementCriteriaDataType dataType;
    union
    {
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_CREATURE
        struct
        {
            uint32 id;
        } creature;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_CLASS_RACE
        struct
        {
            uint32 class_id;
            uint32 race_id;
        } classRace;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_PLAYER_LESS_HEALTH
        struct
        {
            uint32 percent;
        } health;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_T_AURA
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AURA
        struct
        {
            uint32 spell_id;
            uint32 effect_idx;
        } aura;
        // ACHIEVEMENT_CRITERIA_DATA_TYPE_S_AREA
        struct
        {
            uint32 id;
        } area;
        // ...
        struct
        {
            uint32 value1;
            uint32 value2;
        } raw;
    };

    AchievementCriteriaData() : dataType(ACHIEVEMENT_CRITERIA_DATA_TYPE_NONE)
    {
        raw.value1 = 0;
        raw.value2 = 0;
    }

    AchievementCriteriaData(uint32 _dataType, uint32 _value1, uint32 _value2) : dataType(AchievementCriteriaDataType(_dataType))
    {
        raw.value1 = _value1;
        raw.value2 = _value2;
    }

    bool IsValid(AchievementCriteriaEntry const* criteria);
    bool Meets(Player const* source, Unit const* target) const;
};

struct AchievementCriteriaDataSet
{
        typedef std::vector<AchievementCriteriaData> Storage;
        void Add(AchievementCriteriaData const& data) { storage.push_back(data); }
        bool Meets(Player const* source, Unit const* target) const;
    private:
        Storage storage;
};


typedef std::map<uint32,AchievementCriteriaDataSet> AchievementCriteriaDataMap;

struct AchievementReward
{
    uint32 titleId[2];
    uint32 itemId;
    uint32 sender;
    std::string subject;
    std::string text;
};

typedef std::map<uint32,AchievementReward> AchievementRewards;

struct AchievementRewardLocale
{
    std::vector<std::string> subject;
    std::vector<std::string> text;
};

typedef std::map<uint32,AchievementRewardLocale> AchievementRewardLocales;


struct CompletedAchievementData
{
    time_t date;
    bool changed;
};

typedef UNORDERED_MAP<uint32, CriteriaProgress> CriteriaProgressMap;
typedef UNORDERED_MAP<uint32, CompletedAchievementData> CompletedAchievementMap;

class Unit;
class Player;
class WorldPacket;

class AchievementMgr
{
    public:
        AchievementMgr(Player* pl);
        ~AchievementMgr();

        void Reset();
        static void DeleteFromDB(uint32 lowguid);
        void LoadFromDB(QueryResult *achievementResult, QueryResult *criteriaResult);
        void SaveToDB();
        void ResetAchievementCriteria(AchievementCriteriaTypes type, uint32 miscvalue1=0, uint32 miscvalue2=0);
        void UpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscvalue1=0, uint32 miscvalue2=0, Unit *unit=NULL, uint32 time=0);
        void CheckAllAchievementCriteria();
        void SendAllAchievementData();
        void SendRespondInspectAchievements(Player* player);
        Player* GetPlayer() { return m_player;}

    private:
        enum ProgressType { PROGRESS_SET, PROGRESS_ACCUMULATE, PROGRESS_HIGHEST };
        void SendAchievementEarned(AchievementEntry const* achievement);
        void SendCriteriaUpdate(uint32 id, CriteriaProgress const* progress);
        void SetCriteriaProgress(AchievementCriteriaEntry const* entry, uint32 changeValue, ProgressType ptype = PROGRESS_SET);
        void CompletedCriteriaFor(AchievementEntry const* achievement);
        void CompletedAchievement(AchievementEntry const* entry);
        bool IsCompletedCriteria(AchievementCriteriaEntry const* criteria, AchievementEntry const* achievement);
        bool IsCompletedAchievement(AchievementEntry const* entry);
        void CompleteAchievementsWithRefs(AchievementEntry const* entry);
        void BuildAllDataPacket(WorldPacket *data);

        Player* m_player;
        CriteriaProgressMap m_criteriaProgress;
        CompletedAchievementMap m_completedAchievements;
};

class AchievementGlobalMgr
{
    public:
        AchievementCriteriaEntryList const& GetAchievementCriteriaByType(AchievementCriteriaTypes type);
        AchievementCriteriaEntryList const* GetAchievementCriteriaByAchievement(uint32 id)
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
            return iter!=m_achievementRewards.end() ? &iter->second : NULL;
        }

        AchievementRewardLocale const* GetAchievementRewardLocale(AchievementEntry const* achievement) const
        {
            AchievementRewardLocales::const_iterator iter = m_achievementRewardLocales.find(achievement->ID);
            return iter!=m_achievementRewardLocales.end() ? &iter->second : NULL;
        }

        AchievementCriteriaDataSet const* GetCriteriaDataSet(AchievementCriteriaEntry const *achievementCriteria)
        {
            AchievementCriteriaDataMap::const_iterator iter = m_criteriaDataMap.find(achievementCriteria->ID);
            return iter!=m_criteriaDataMap.end() ? &iter->second : NULL;
        }

        bool IsRealmCompleted(AchievementEntry const* achievement) const
        {
            return m_allCompletedAchievements.find(achievement->ID) != m_allCompletedAchievements.end();
        }

        void SetRealmCompleted(AchievementEntry const* achievement)
        {
            m_allCompletedAchievements.insert(achievement->ID);
        }

        void LoadAchievementCriteriaList();
        void LoadAchievementCriteriaData();
        void LoadAchievementReferenceList();
        void LoadCompletedAchievements();
        void LoadRewards();
        void LoadRewardLocales();
    private:
        AchievementCriteriaDataMap m_criteriaDataMap;

        // store achievement criterias by type to speed up lookup
        AchievementCriteriaEntryList m_AchievementCriteriasByType[ACHIEVEMENT_CRITERIA_TYPE_TOTAL];
        // store achievement criterias by achievement to speed up lookup
        AchievementCriteriaListByAchievement m_AchievementCriteriaListByAchievement;
        // store achievements by referenced achievement id to speed up lookup
        AchievementListByReferencedId m_AchievementListByReferencedId;

        typedef std::set<uint32> AllCompletedAchievements;
        AllCompletedAchievements m_allCompletedAchievements;

        AchievementRewards m_achievementRewards;
        AchievementRewardLocales m_achievementRewardLocales;
};

#define achievementmgr Trinity::Singleton<AchievementGlobalMgr>::Instance()

#endif
