/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef QuestObjectiveCriteriaMgr_h__
#define QuestObjectiveCriteriaMgr_h__

#include "CriteriaHandler.h"
#include "QuestDef.h"

struct CompletedCriteriaTreeObjectiveData
{
    std::time_t Date = std::time_t(0);
    GuidSet CompletingPlayers;
    bool Changed;
};

class TC_GAME_API QuestObjectiveCriteriaMgr : public CriteriaHandler
{
public:
    explicit QuestObjectiveCriteriaMgr(Player* owner);
    ~QuestObjectiveCriteriaMgr();

    void CheckAllQuestObjectiveCriteria(Player* referencePlayer);

    bool HasCompletedObjective(QuestObjective const* objective) const;

    void Reset() override;

    static void DeleteFromDB(ObjectGuid const& guid);
    void LoadFromDB(PreparedQueryResult objectiveResult, PreparedQueryResult criteriaResult);
    void SaveToDB(SQLTransaction& trans);

    void ResetCriteria(CriteriaTypes type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, bool evenIfCriteriaComplete = false);

    void SendAllData(Player const* receiver) const override;

    void CompletedObjective(QuestObjective const* objective, Player* referencePlayer);
protected:
    bool CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const override;
    bool CanCompleteCriteriaTree(CriteriaTree const* tree) override;
    void CompletedCriteriaTree(CriteriaTree const* tree, Player* referencePlayer) override;
protected:
    std::unordered_map<uint32, CompletedCriteriaTreeObjectiveData> _completedObjectives;

    void SendCriteriaUpdate(Criteria const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const override;
    void SendCriteriaProgressRemoved(uint32 criteriaId) override;

    void SendPacket(WorldPacket const* data) const override;

    std::string GetOwnerInfo() const override;
    CriteriaList const& GetCriteriaByType(CriteriaTypes type) const override;
private:
    Player* _owner;
};

#endif
