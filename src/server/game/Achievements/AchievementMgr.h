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

#ifndef __TRINITY_ACHIEVEMENTMGR_H
#define __TRINITY_ACHIEVEMENTMGR_H

#include "CriteriaHandler.h"

class Guild;

struct AchievementReward
{
    uint32 TitleId[2];
    uint32 ItemId;
    uint32 SenderCreatureId;
    std::string Subject;
    std::string Body;
    uint32 MailTemplateId;
};

struct AchievementRewardLocale
{
    std::vector<std::string> Subject;
    std::vector<std::string> Body;
};

struct CompletedAchievementData
{
    std::time_t Date = std::time_t(0);
    GuidSet CompletingPlayers;
    bool Changed;
};

class TC_GAME_API AchievementMgr : public CriteriaHandler
{
public:
    AchievementMgr();
    ~AchievementMgr();

    void CheckAllAchievementCriteria(Player* referencePlayer);

    virtual void CompletedAchievement(AchievementEntry const* entry, Player* referencePlayer) = 0;
    bool HasAchieved(uint32 achievementId) const;
    uint32 GetAchievementPoints() const;

protected:
    bool CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const override;
    bool CanCompleteCriteriaTree(CriteriaTree const* tree) override;
    void CompletedCriteriaTree(CriteriaTree const* tree, Player* referencePlayer) override;
    void AfterCriteriaTreeUpdate(CriteriaTree const* tree, Player* referencePlayer) override;

    bool IsCompletedAchievement(AchievementEntry const* entry);

    bool RequiredAchievementSatisfied(uint32 achievementId) const override;

protected:
    std::unordered_map<uint32, CompletedAchievementData> _completedAchievements;
    uint32 _achievementPoints;
};

class TC_GAME_API PlayerAchievementMgr : public AchievementMgr
{
public:
    explicit PlayerAchievementMgr(Player* owner);

    void Reset() override;

    static void DeleteFromDB(ObjectGuid const& guid);
    void LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult);
    void SaveToDB(CharacterDatabaseTransaction& trans);

    void ResetCriteria(CriteriaCondition condition, int32 failAsset, bool evenIfCriteriaComplete = false);

    void SendAllData(Player const* receiver) const override;
    void SendAchievementInfo(Player* receiver, uint32 achievementId = 0) const;

    void CompletedAchievement(AchievementEntry const* entry, Player* referencePlayer) override;

    using CriteriaHandler::ModifierTreeSatisfied;
    bool ModifierTreeSatisfied(uint32 modifierTreeId) const;

protected:
    void SendCriteriaUpdate(Criteria const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const override;
    void SendCriteriaProgressRemoved(uint32 criteriaId) override;

    void SendAchievementEarned(AchievementEntry const* achievement) const;

    void SendPacket(WorldPacket const* data) const override;

    std::string GetOwnerInfo() const override;
    CriteriaList const& GetCriteriaByType(CriteriaTypes type, uint32 asset) const override;

private:
    Player* _owner;
};

class TC_GAME_API GuildAchievementMgr : public AchievementMgr
{
public:
    explicit GuildAchievementMgr(Guild* owner);

    void Reset() override;

    static void DeleteFromDB(ObjectGuid const& guid);
    void LoadFromDB(PreparedQueryResult achievementResult, PreparedQueryResult criteriaResult);
    void SaveToDB(CharacterDatabaseTransaction& trans);

    void SendAllData(Player const* receiver) const override;
    void SendAchievementInfo(Player* receiver, uint32 achievementId = 0) const;
    void SendAllTrackedCriterias(Player* receiver, std::set<uint32> const& trackedCriterias) const;
    void SendAchievementMembers(Player* receiver, uint32 achievementId) const;

    void CompletedAchievement(AchievementEntry const* entry, Player* referencePlayer) override;

protected:
    void SendCriteriaUpdate(Criteria const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const override;
    void SendCriteriaProgressRemoved(uint32 criteriaId) override;

    void SendAchievementEarned(AchievementEntry const* achievement) const;

    void SendPacket(WorldPacket const* data) const override;

    std::string GetOwnerInfo() const override;
    CriteriaList const& GetCriteriaByType(CriteriaTypes type, uint32 asset) const override;

private:
    Guild* _owner;
};

class TC_GAME_API AchievementGlobalMgr
{
    AchievementGlobalMgr() { }
    ~AchievementGlobalMgr() { }

public:
    static AchievementGlobalMgr* Instance();

    std::vector<AchievementEntry const*> const* GetAchievementByReferencedId(uint32 id) const;
    AchievementReward const* GetAchievementReward(AchievementEntry const* achievement) const;
    AchievementRewardLocale const* GetAchievementRewardLocale(AchievementEntry const* achievement) const;

    bool IsRealmCompleted(AchievementEntry const* achievement) const;
    void SetRealmCompleted(AchievementEntry const* achievement);

    void LoadAchievementReferenceList();
    void LoadCompletedAchievements();
    void LoadRewards();
    void LoadRewardLocales();

private:
    // store achievements by referenced achievement id to speed up lookup
    std::unordered_map<uint32, std::vector<AchievementEntry const*>> _achievementListByReferencedId;

    // store realm first achievements
    // std::chrono::system_clock::time_point::min() is a placeholder value for realm firsts not yet completed
    // std::chrono::system_clock::time_point::max() is a value assigned to realm firsts complete before worldserver started
    std::unordered_map<uint32 /*achievementId*/, std::chrono::system_clock::time_point /*completionTime*/> _allCompletedAchievements;

    std::unordered_map<uint32, AchievementReward> _achievementRewards;
    std::unordered_map<uint32, AchievementRewardLocale> _achievementRewardLocales;
};

#define sAchievementMgr AchievementGlobalMgr::Instance()

#endif
