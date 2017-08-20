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

#include "QuestObjectiveCriteriaMgr.h"
#include "AchievementPackets.h"
#include "DatabaseEnv.h"
#include "GridNotifiersImpl.h"
#include "Log.h"
#include "ObjectMgr.h"

QuestObjectiveCriteriaMgr::QuestObjectiveCriteriaMgr(Player* owner) : _owner(owner) { }

QuestObjectiveCriteriaMgr::~QuestObjectiveCriteriaMgr() { }

void QuestObjectiveCriteriaMgr::CheckAllQuestObjectiveCriteria(Player* referencePlayer)
{
    // suppress sending packets
    for (uint32 i = 0; i < CRITERIA_TYPE_TOTAL; ++i)
        UpdateCriteria(CriteriaTypes(i), 0, 0, 0, NULL, referencePlayer);
}

bool QuestObjectiveCriteriaMgr::HasCompletedObjective(QuestObjective const* objective) const
{
    return _completedObjectives.find(objective->ID) != _completedObjectives.end();
}

void QuestObjectiveCriteriaMgr::Reset()
{
    for (auto iter = _criteriaProgress.begin(); iter != _criteriaProgress.end(); ++iter)
        SendCriteriaProgressRemoved(iter->first);

    _criteriaProgress.clear();

    DeleteFromDB(_owner->GetGUID());

    // re-fill data
    CheckAllQuestObjectiveCriteria(_owner);
}

void QuestObjectiveCriteriaMgr::DeleteFromDB(ObjectGuid const& guid)
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS);
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
            Field* fields = objectiveResult->Fetch();
            uint32 objectiveid = fields[0].GetUInt32();

            // must not happen: cleanup at server startup in sAchievementMgr->LoadCompletedAchievements()
            QuestObjective const* objective = sObjectMgr->GetQuestObjective(objectiveid);
            if (!objective)
                continue;

            CompletedCriteriaTreeObjectiveData& co = _completedObjectives[objectiveid];
            co.Date = time_t(fields[1].GetUInt32());
            co.Changed = false;

        } while (objectiveResult->NextRow());
    }

    if (criteriaResult)
    {
        time_t now = time(NULL);
        do
        {
            Field* fields = criteriaResult->Fetch();
            uint32 id = fields[0].GetUInt32();
            uint64 counter = fields[1].GetUInt64();
            time_t date = time_t(fields[2].GetUInt32());

            Criteria const* criteria = sCriteriaMgr->GetCriteria(id);
            if (!criteria)
            {
                // Removing non-existing criteria data for all characters
                TC_LOG_ERROR("criteria.quest", "Non-existing quest objective criteria %u data has been removed from the table `character_queststatus_objectives_criteria_progress`.", id);

                PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_INVALID_QUEST_PROGRESS_CRITERIA);
                stmt->setUInt32(0, uint16(id));
                CharacterDatabase.Execute(stmt);

                continue;
            }

            if (criteria->Entry->StartTimer && time_t(date + criteria->Entry->StartTimer) < now)
                continue;

            CriteriaProgress& progress = _criteriaProgress[id];
            progress.Counter = counter;
            progress.Date = date;
            progress.Changed = false;
        } while (criteriaResult->NextRow());
    }
}

void QuestObjectiveCriteriaMgr::SaveToDB(SQLTransaction& trans)
{
    if (!_completedObjectives.empty())
    {
        for (auto iter = _completedObjectives.begin(); iter != _completedObjectives.end(); ++iter)
        {
            if (!iter->second.Changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_BY_CRITERIA);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, iter->first);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, iter->first);
            stmt->setUInt32(2, uint32(iter->second.Date));
            trans->Append(stmt);

            iter->second.Changed = false;
        }
    }

    if (!_criteriaProgress.empty())
    {
        for (auto iter = _criteriaProgress.begin(); iter != _criteriaProgress.end(); ++iter)
        {
            if (!iter->second.Changed)
                continue;

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS_BY_CRITERIA);
            stmt->setUInt64(0, _owner->GetGUID().GetCounter());
            stmt->setUInt32(1, iter->first);
            trans->Append(stmt);

            if (iter->second.Counter)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHAR_QUESTSTATUS_OBJECTIVES_CRITERIA_PROGRESS);
                stmt->setUInt64(0, _owner->GetGUID().GetCounter());
                stmt->setUInt32(1, iter->first);
                stmt->setUInt64(2, iter->second.Counter);
                stmt->setUInt32(3, uint32(iter->second.Date));
                trans->Append(stmt);
            }

            iter->second.Changed = false;
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
        if (playerCriteria->Entry->FailEvent != miscValue1 || (playerCriteria->Entry->FailAsset && playerCriteria->Entry->FailAsset != miscValue2))
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

void QuestObjectiveCriteriaMgr::SendAllData(Player const* /*receiver*/) const
{
    for (auto itr = _criteriaProgress.begin(); itr != _criteriaProgress.end(); ++itr)
    {
        WorldPackets::Achievement::CriteriaUpdate criteriaUpdate;

        criteriaUpdate.CriteriaID = itr->first;
        criteriaUpdate.Quantity = itr->second.Counter;
        criteriaUpdate.PlayerGUID = _owner->GetGUID();
        criteriaUpdate.Flags = 0;

        criteriaUpdate.CurrentTime = itr->second.Date;
        criteriaUpdate.CreationTime = 0;

        SendPacket(criteriaUpdate.Write());
    }
}

void QuestObjectiveCriteriaMgr::CompletedObjective(QuestObjective const* objective, Player* referencePlayer)
{
    // disable for gamemasters with GM-mode enabled
    if (_owner->IsGameMaster())
        return;

    if (HasCompletedObjective(objective))
        return;

    referencePlayer->KillCreditCriteriaTreeObjective(objective);

    TC_LOG_INFO("criteria.quest", "QuestObjectiveCriteriaMgr::CompletedObjective(%u). %s", objective->ID, GetOwnerInfo().c_str());

    CompletedCriteriaTreeObjectiveData& co = _completedObjectives[objective->ID];
    co.Date = time(NULL);
    co.Changed = true;
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

void QuestObjectiveCriteriaMgr::SendPacket(WorldPacket const* data) const
{
    _owner->SendDirectMessage(data);
}

CriteriaList const& QuestObjectiveCriteriaMgr::GetCriteriaByType(CriteriaTypes type) const
{
    return sCriteriaMgr->GetQuestObjectiveCriteriaByType(type);
}

std::string QuestObjectiveCriteriaMgr::GetOwnerInfo() const
{
    return Trinity::StringFormat("%s %s", _owner->GetGUID().ToString().c_str(), _owner->GetName().c_str());
}

