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

#include "InstanceScenario.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"

InstanceScenario::InstanceScenario(Map const* map, ScenarioData const* scenarioData) : Scenario(scenarioData), _map(map)
{
    ASSERT(_map);
    LoadInstanceData(_map->GetInstanceId());

    Map::PlayerList const& players = map->GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        if (Player* player = itr->GetSource()->ToPlayer())
            SendScenarioState(player);
}

void InstanceScenario::SaveToDB()
{
    if (_criteriaProgress.empty())
        return;

    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(_map->GetDifficultyID());
    if (!difficultyEntry || difficultyEntry->Flags & DIFFICULTY_FLAG_CHALLENGE_MODE) // Map should have some sort of "CanSave" boolean that returns whether or not the map is savable. (Challenge modes cannot be saved for example)
        return;

    uint32 id = _map->GetInstanceId();
    if (!id)
    {
        TC_LOG_DEBUG("scenario", "Scenario::SaveToDB: Can not save scenario progress without an instance save. Map::GetInstanceId() did not return an instance save.");
        return;
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    for (auto iter = _criteriaProgress.begin(); iter != _criteriaProgress.end(); ++iter)
    {
        if (!iter->second.Changed)
            continue;

        Criteria const* criteria = sCriteriaMgr->GetCriteria(iter->first);
        switch (CriteriaTypes(criteria->Entry->Type))
        {
            // Blizzard only appears to store creature kills
            case CRITERIA_TYPE_KILL_CREATURE:
                break;
            default:
                continue;
        }

        if (iter->second.Counter)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_SCENARIO_INSTANCE_CRITERIA);
            stmt->setUInt32(0, id);
            stmt->setUInt32(1, iter->first);
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_SCENARIO_INSTANCE_CRITERIA);
            stmt->setUInt32(0, id);
            stmt->setUInt32(1, iter->first);
            stmt->setUInt64(2, iter->second.Counter);
            stmt->setUInt32(3, uint32(iter->second.Date));
            trans->Append(stmt);
        }

        iter->second.Changed = false;
    }

    CharacterDatabase.CommitTransaction(trans);
}

void InstanceScenario::LoadInstanceData(uint32 instanceId)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_SCENARIO_INSTANCE_CRITERIA_FOR_INSTANCE);
    stmt->setUInt32(0, instanceId);

    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (result)
    {
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        time_t now = time(nullptr);

        std::vector<CriteriaTree const*> criteriaTrees;
        do
        {
            Field* fields = result->Fetch();
            uint32 id = fields[0].GetUInt32();
            uint64 counter = fields[1].GetUInt64();
            time_t date = time_t(fields[2].GetUInt32());

            Criteria const* criteria = sCriteriaMgr->GetCriteria(id);
            if (!criteria)
            {
                // Removing non-existing criteria data for all instances
                TC_LOG_ERROR("criteria.instancescenarios", "Removing scenario criteria %u data from the table `instance_scenario_progress`.", id);

                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_SCENARIO_INSTANCE_CRITERIA);
                stmt->setUInt32(0, instanceId);
                stmt->setUInt32(1, uint32(id));
                trans->Append(stmt);
                continue;
            }

            if (criteria->Entry->StartTimer && time_t(date + criteria->Entry->StartTimer) < now)
                continue;

            switch (CriteriaTypes(criteria->Entry->Type))
            {
                // Blizzard appears to only stores creatures killed progress for unknown reasons. Either technical shortcoming or intentional
                case CRITERIA_TYPE_KILL_CREATURE:
                    break;
                default:
                    continue;
            }

            SetCriteriaProgress(criteria, counter, nullptr, PROGRESS_SET);

            if (CriteriaTreeList const* trees = sCriteriaMgr->GetCriteriaTreesByCriteria(criteria->ID))
                for (CriteriaTree const* tree : *trees)
                    criteriaTrees.push_back(tree);
        }
        while (result->NextRow());

        CharacterDatabase.CommitTransaction(trans);

        for (CriteriaTree const* tree : criteriaTrees)
        {
            ScenarioStepEntry const* step = tree->ScenarioStep;
            if (!step)
                continue;

            if (IsCompletedCriteriaTree(tree))
                SetStepState(step, SCENARIO_STEP_DONE);
        }
    }
}

std::string InstanceScenario::GetOwnerInfo() const
{
    return Trinity::StringFormat("Instance ID %u", _map->GetInstanceId());
}

void InstanceScenario::SendPacket(WorldPacket const* data) const
{
    _map->SendToPlayers(data);
}
