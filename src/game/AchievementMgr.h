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

#define CRITERIA_CAST_SPELL_REQ_COUNT 46
#define ACHIEVEMENT_REWARD_COUNT 57

typedef std::list<const AchievementCriteriaEntry*> AchievementCriteriaEntryList;

struct CriteriaProgress
{
    uint32 counter;
    time_t date;
    bool changed;
};

struct CriteriaCastSpellRequirement
{
    uint32 achievementCriteriaId;
    uint32 creatureEntry;
    uint8 playerClass;
    uint8 playerRace;
};

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

enum AchievementCompletionState
{
    ACHIEVEMENT_COMPLETED_NONE,
    ACHIEVEMENT_COMPLETED_COMPLETED_NOT_STORED,
    ACHIEVEMENT_COMPLETED_COMPLETED_STORED,
};

class AchievementMgr
{
    public:
        AchievementMgr(Player* pl);
        ~AchievementMgr();

        void Reset();
        static void DeleteFromDB(uint32 lowguid);
        void LoadFromDB(QueryResult *achievementResult, QueryResult *criteriaResult);
        void SaveToDB();
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
        void CompletedCriteria(AchievementCriteriaEntry const* entry);
        void CompletedAchievement(AchievementEntry const* entry);
        bool IsCompletedCriteria(AchievementCriteriaEntry const* entry);
        AchievementCompletionState GetAchievementCompletionState(AchievementEntry const* entry);
        void BuildAllDataPacket(WorldPacket *data);

        Player* m_player;
        CriteriaProgressMap m_criteriaProgress;
        CompletedAchievementMap m_completedAchievements;
};

class AchievementGlobalMgr
{
    public:
        AchievementCriteriaEntryList const& GetAchievementCriteriaByType(AchievementCriteriaTypes type);

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

        static CriteriaCastSpellRequirement const * GetCriteriaCastSpellRequirement(AchievementCriteriaEntry const *achievementCriteria)
        {
            for (uint32 i=0; i < CRITERIA_CAST_SPELL_REQ_COUNT; ++i)
                if (m_criteriaCastSpellRequirements[i].achievementCriteriaId == achievementCriteria->ID)
                    return  &m_criteriaCastSpellRequirements[i];

            return NULL;
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
        void LoadCompletedAchievements();
        void LoadRewards();
        void LoadRewardLocales();
    private:
        static const CriteriaCastSpellRequirement m_criteriaCastSpellRequirements[];

        // store achievement criterias by type to speed up lookup
        AchievementCriteriaEntryList m_AchievementCriteriasByType[ACHIEVEMENT_CRITERIA_TYPE_TOTAL];

        typedef std::set<uint32> AllCompletedAchievements;
        AllCompletedAchievements m_allCompletedAchievements;

        AchievementRewards m_achievementRewards;
        AchievementRewardLocales m_achievementRewardLocales;
};

#define achievementmgr Trinity::Singleton<AchievementGlobalMgr>::Instance()

#endif
