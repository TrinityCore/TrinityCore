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

#include "QuestObjectiveCriteriaMgr.h"
#include "AchievementPackets.h"
#include "DatabaseEnv.h"
#include "DB2Structure.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Player.h"

QuestObjectiveCriteriaMgr::QuestObjectiveCriteriaMgr(Player* owner) : _owner(owner)
{
}

QuestObjectiveCriteriaMgr::~QuestObjectiveCriteriaMgr()
{
}

void QuestObjectiveCriteriaMgr::CheckAllQuestObjectiveCriteria(Player* referencePlayer)
{
    // suppress sending packets
    for (uint32 i = 0; i < CRITERIA_TYPE_TOTAL; ++i)
        UpdateCriteria(CriteriaTypes(i), 0, 0, 0, nullptr, referencePlayer);
}

void QuestObjectiveCriteriaMgr::Reset()
{
    for (auto& criteriaProgres : _criteriaProgress)
        SendCriteriaProgressRemoved(criteriaProgres.first);

    _criteriaProgress.clear();

    DeleteFromDB(_owner->GetGUID());

    // re-fill data
    CheckAllQuestObjectiveCriteria(_owner);
}

void QuestObjectiveCriteriaMgr::DeleteFromDB(ObjectGuid const& guid)
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS);
    stmt->setUInt64(0, guid.GetCounter());
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void QuestObjectiveCriteriaMgr::LoadFromDB(PreparedQueryResult objectiveResult, PreparedQueryResult criteriaResult)
{
    if (objectiveResult)
    {
        do
        {
            uint32 objectiveId = (*objectiveResult)[0].GetUInt32();

            QuestObjective const* objective = sObjectMgr->GetQuestObjective(objectiveId);
            if (!objective)
                continue;

            _completedObjectives.insert(objectiveId);

        } while (objectiveResult->NextRow());
    }

    if (criteriaResult)
    {
        time_t now = time(nullptr);
        do
        {
            Field* fields = criteriaResult->Fetch();
            uint32 criteriaId = fields[0].GetUInt32();
            uint64 counter = fields[1].GetUInt64();
            time_t date = time_t(fields[2].GetUInt32());

            Criteria const* criteria = sCriteriaMgr->GetCriteria(criteriaId);
            if (!criteria)
            {
                // Removing non-existing criteria data for all characters
                TC_LOG_ERROR("criteria.quest", "Non-existing quest objective criteria %u data has been removed from the table `character_queststatus_objectives_criteria_progress`.", criteriaId);

                CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_QUEST_PROGRESS_CRITERIA);
                stmt->setUInt32(0, criteriaId);
                CharacterDatabase.Execute(stmt);

                continue;
            }

            if (criteria->Entry->StartTimer && time_t(date + criteria->Entry->StartTimer) < now)
                continue;

            CriteriaProgress& progress = _criteriaProgress[criteriaId];
            progress.Counter = counter;
            progress.Date = date;
            progress.Changed = false;
        } while (criteriaResult->NextRow());
    }
}

void QuestObjectiveCriteriaMgr::SaveToDB(CharacterDatabaseTransaction& trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA);
    stmt->setUInt64(0, _owner->GetGUID().GetCounter());
    trans->Append(stmt);

    if (!_completedObjectives.empty())
    {
        for (uint32 completedObjectiveId : _completedObjectives)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, completedObjectiveId);
            trans->Append(stmt);
        }
    }

    if (!_criteriaProgress.empty())
    {
        for (auto& criteriaProgres : _criteriaProgress)
        {
            if (!criteriaProgres.second.Changed)
                continue;

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS_BY_CRITERIA);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, criteriaProgres.first);
            trans->Append(stmt);

            if (criteriaProgres.second.Counter)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS);
                stmt->setUInt64(0, _owner->GetGUID().GetCounter());
                stmt->setUInt32(1, criteriaProgres.first);
                stmt->setUInt64(2, criteriaProgres.second.Counter);
                stmt->setUInt32(3, uint32(criteriaProgres.second.Date));
                trans->Append(stmt);
            }

            criteriaProgres.second.Changed = false;
        }
    }
}

void QuestObjectiveCriteriaMgr::ResetCriteria(CriteriaTypes type, uint64 miscValue1, uint64 miscValue2, bool evenIfCriteriaComplete)
{
    TC_LOG_DEBUG("criteria.quest", "QuestObjectiveCriteriaMgr::ResetCriteria(%u, " UI64FMTD ", " UI64FMTD ")", type, miscValue1, miscValue2);

    // disable for gamemasters with GM-mode enabled
    if (_owner->IsGameMaster())
        return;

    CriteriaList const& playerCriteriaList = GetCriteriaByType(type);
    for (Criteria const* playerCriteria : playerCriteriaList)
    {
        if (playerCriteria->Entry->FailEvent != miscValue1 || (playerCriteria->Entry->FailAsset && playerCriteria->Entry->FailAsset != int64(miscValue2)))
            continue;

        std::vector<CriteriaTree const*> const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(playerCriteria->ID);
        bool allComplete = true;
        for (CriteriaTree const* tree : *trees)
        {
            // don't update already completed criteria if not forced
            if (!(IsCompletedCriteriaTree(tree) && !evenIfCriteriaComplete))
            {
                allComplete = false;
                break;
            }
        }

        if (allComplete)
            continue;

        RemoveCriteriaProgress(playerCriteria);
    }
}

void QuestObjectiveCriteriaMgr::ResetCriteriaTree(uint32 criteriaTreeId)
{
    CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(criteriaTreeId);
    if (!tree)
        return;

    CriteriaMgr::WalkCriteriaTree(tree, [this](CriteriaTree const* criteriaTree)
    {
        RemoveCriteriaProgress(criteriaTree->Criteria);
    });
}

void QuestObjectiveCriteriaMgr::SendAllData(Player const* /*receiver*/) const
{
    for (const auto& criteriaProgres : _criteriaProgress)
    {
        WorldPackets::Achievement::CriteriaUpdate criteriaUpdate;

        criteriaUpdate.CriteriaID = criteriaProgres.first;
        criteriaUpdate.Quantity = criteriaProgres.second.Counter;
        criteriaUpdate.PlayerGUID = _owner->GetGUID();
        criteriaUpdate.Flags = 0;

        criteriaUpdate.CurrentTime = criteriaProgres.second.Date;
        criteriaUpdate.CreationTime = 0;

        SendPacket(criteriaUpdate.Write());
    }
}

void QuestObjectiveCriteriaMgr::CompletedObjective(QuestObjective const* questObjective, Player* referencePlayer)
{
    // disable for gamemasters with GM-mode enabled
    if (_owner->IsGameMaster())
        return;

    if (HasCompletedObjective(questObjective))
        return;

    referencePlayer->KillCreditCriteriaTreeObjective(*questObjective);

    TC_LOG_INFO("criteria.quest", "QuestObjectiveCriteriaMgr::CompletedObjective(%u). %s", questObjective->ID, GetOwnerInfo().c_str());

    _completedObjectives.insert(questObjective->ID);
}

bool QuestObjectiveCriteriaMgr::HasCompletedObjective(QuestObjective const* questObjective) const
{
    return _completedObjectives.find(questObjective->ID) != _completedObjectives.end();
}

void QuestObjectiveCriteriaMgr::SendCriteriaUpdate(Criteria const* criteria, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const
{
    WorldPackets::Achievement::CriteriaUpdate criteriaUpdate;

    criteriaUpdate.CriteriaID = criteria->ID;
    criteriaUpdate.Quantity = progress->Counter;
    criteriaUpdate.PlayerGUID = _owner->GetGUID();
    criteriaUpdate.Flags = 0;
    if (criteria->Entry->StartTimer)
        criteriaUpdate.Flags = timedCompleted ? 1 : 0; // 1 is for keeping the counter at 0 in client

    criteriaUpdate.CurrentTime = progress->Date;
    criteriaUpdate.ElapsedTime = timeElapsed;
    criteriaUpdate.CreationTime = 0;

    SendPacket(criteriaUpdate.Write());
}

void QuestObjectiveCriteriaMgr::SendCriteriaProgressRemoved(uint32 criteriaId)
{
    WorldPackets::Achievement::CriteriaDeleted criteriaDeleted;
    criteriaDeleted.CriteriaID = criteriaId;
    SendPacket(criteriaDeleted.Write());
}

bool QuestObjectiveCriteriaMgr::CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const
{
    QuestObjective const* objective = tree->QuestObjective;
    if (!objective)
        return false;

    if (HasCompletedObjective(objective))
    {
        TC_LOG_TRACE("criteria.quest", "QuestObjectiveCriteriaMgr::CanUpdateCriteriaTree: (Id: %u Type %s Quest Objective %u) Objective already completed",
            criteria->ID, CriteriaMgr::GetCriteriaTypeString(criteria->Entry->Type), objective->ID);
        return false;
    }

    return CriteriaHandler::CanUpdateCriteriaTree(criteria, tree, referencePlayer);
}

bool QuestObjectiveCriteriaMgr::CanCompleteCriteriaTree(CriteriaTree const* tree)
{
    QuestObjective const* objective = tree->QuestObjective;
    if (!objective)
        return false;

    return CriteriaHandler::CanCompleteCriteriaTree(tree);
}

void QuestObjectiveCriteriaMgr::CompletedCriteriaTree(CriteriaTree const* tree, Player* referencePlayer)
{
    QuestObjective const* objective = tree->QuestObjective;
    if (!objective)
        return;

    CompletedObjective(objective, referencePlayer);
}

void QuestObjectiveCriteriaMgr::SendPacket(WorldPacket const* data) const
{
    _owner->SendDirectMessage(data);
}

std::string QuestObjectiveCriteriaMgr::GetOwnerInfo() const
{
    return Trinity::StringFormat("%s %s", _owner->GetGUID().ToString().c_str(), _owner->GetName().c_str());
}

CriteriaList const& QuestObjectiveCriteriaMgr::GetCriteriaByType(CriteriaTypes type) const
{
    return sCriteriaMgr->GetQuestObjectiveCriteriaByType(type);
}
