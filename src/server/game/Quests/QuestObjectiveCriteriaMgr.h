/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

class TC_GAME_API QuestObjectiveCriteriaMgr : public CriteriaHandler
{
public:
    explicit QuestObjectiveCriteriaMgr(Player* owner);
    ~QuestObjectiveCriteriaMgr();

    void CheckAllQuestObjectiveCriteria(Player* referencePlayer);

    void Reset() override;

    static void DeleteFromDB(ObjectGuid const& guid);
    void LoadFromDB(PreparedQueryResult objectiveResult, PreparedQueryResult criteriaResult);
    void SaveToDB(SQLTransaction& trans);

    void ResetCriteria(CriteriaTypes type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, bool evenIfCriteriaComplete = false);
    void ResetCriteriaTree(uint32 criteriaTreeId);

    void SendAllData(Player const* receiver) const override;

    void CompletedObjective(QuestObjective const* questObjective, Player* referencePlayer);
    bool HasCompletedObjective(QuestObjective const* questObjective) const;

protected:
    void SendCriteriaUpdate(Criteria const* entry, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const override;

    void SendCriteriaProgressRemoved(uint32 criteriaId) override;

    bool CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const override;
    bool CanCompleteCriteriaTree(CriteriaTree const* tree) override;
    void CompletedCriteriaTree(CriteriaTree const* tree, Player* referencePlayer) override;

    void SendPacket(WorldPacket const* data) const override;

    std::string GetOwnerInfo() const override;
    CriteriaList const& GetCriteriaByType(CriteriaTypes type) const override;

private:
    Player* _owner;
    std::unordered_set<uint32> _completedObjectives;
};

#endif
