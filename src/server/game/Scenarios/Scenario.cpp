/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "Scenario.h"
#include "Player.h"
#include "ScenarioMgr.h"
#include "InstanceSaveMgr.h"
#include "ObjectMgr.h"

Scenario::Scenario(ScenarioData const* scenarioData) : _data(scenarioData), _currentstep(-1), _lastStep(-1), _complete(false), _canReward(false)
{
    ASSERT(_data);
    for (auto itr = _data->Steps.begin(); itr != _data->Steps.end(); ++itr)
    {
        if (itr->second->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE)
            continue;

        if (_firstStep > itr->second->Step)
            _firstStep = itr->second->Step;

        if (_lastStep < itr->second->Step)
            _lastStep = itr->second->Step;

    }

    ASSERT(_firstStep);
    ASSERT(_lastStep);
    SetStep(_firstStep);
}

Scenario::~Scenario()
{
    for (auto guid : m_players)
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            SendBootPlayer(player);

    m_players.clear();
}

void Scenario::Reset()
{
    CriteriaHandler::Reset();
    SetStep(GetFirstStep());
}

void Scenario::CompleteStep(uint8 step)
{
    std::map<uint8, ScenarioStepEntry const*>::const_iterator itr = _data->Steps.find(step);
    if (itr == _data->Steps.end())
    {
        TC_LOG_ERROR("scenarios", "Attempted to complete step (Id: %u), but step was not found!", step);
        return;
    }

    if (!(itr->second->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE))
        AdvanceStep();

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(itr->second->QuestRewardID))
        for (auto guid : m_players)
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                player->RewardQuest(quest, 0, nullptr, false);
}

void Scenario::AdvanceStep()
{
    for (auto step : _data->Steps)
    {
        if (step.second->Step > GetStep() && !(step.second->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE))
        {
            SetStep(step.second->Step);
            return;
        }
    }

    SetStep(GetStep() + 1);
}

void Scenario::SetStep(int8 step)
{
    _currentstep = step;
    WorldPackets::Scenario::ScenarioState scenarioState;
    BuildScenarioState(&scenarioState);
    SendPacket(scenarioState.Write());

    if (GetStep() > _lastStep && !IsComplete())
        CompleteScenario();
}

void Scenario::CompleteScenario()
{
    if (IsComplete())
        return;

    _complete = true;
    SendPacket(WorldPackets::Scenario::ScenarioCompleted(_data->Entry->ID).Write());
}

void Scenario::OnPlayerEnter(Player* player)
{
    m_players.insert(player->GetGUID());
    SendScenarioState(player);
}

void Scenario::OnPlayerExit(Player* player)
{
    m_players.erase(player->GetGUID());
    SendBootPlayer(player);
}

void Scenario::SendCriteriaUpdate(Criteria const * criteria, CriteriaProgress const * progress, uint32 timeElapsed, bool timedCompleted) const
{
    WorldPackets::Scenario::ScenarioProgressUpdate progressUpdate;
    WorldPackets::Scenario::CriteriaProgress criteriaProgress;
    criteriaProgress.Id = criteria->ID;
    criteriaProgress.Quantity = progress->Counter;
    criteriaProgress.Player = progress->PlayerGUID;
    criteriaProgress.Date = progress->Date;
    if (criteria->Entry->StartTimer)
        criteriaProgress.Flags = timedCompleted ? 1 : 0;

    criteriaProgress.TimeStart = timeElapsed;
    criteriaProgress.TimeCreate = 0;

    progressUpdate.criteriaProgress = criteriaProgress;
    SendPacket(progressUpdate.Write());
}

void Scenario::SendCriteriaProgressRemoved(uint32 criteriaId)
{
}

bool Scenario::CanUpdateCriteriaTree(Criteria const * /*criteria*/, CriteriaTree const * tree, Player * /*referencePlayer*/) const
{
    if (!tree->ScenarioStep)
        return false;

    std::map<uint8, ScenarioStepEntry const*>::const_iterator itr = _data->Steps.find(GetStep());
    if (itr != _data->Steps.end())
    {
        if (tree->ScenarioStep->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE)
            return !(IsComplete() && tree->ScenarioStep->Flags & SCENARIO_STEP_FLAG_SCENARIO_NOT_DONE);

        return itr->second->Step == tree->ScenarioStep->Step;
    }

    return false;
}

void Scenario::CompletedCriteriaTree(CriteriaTree const * tree, Player * referencePlayer)
{
    if (!tree->ScenarioStep || _complete)
        return;

    CompleteStep(tree->ScenarioStep->Step);
}

void Scenario::SendPacket(WorldPacket const* data) const
{
    for (auto guid : m_players)
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            player->SendDirectMessage(data);
}

void Scenario::BuildScenarioState(WorldPackets::Scenario::ScenarioState* scenarioState)
{
    scenarioState->ScenarioId = _data->Entry->ID;
    scenarioState->CurrentStep = GetStep();
    scenarioState->CriteriaProgress = GetCriteriasProgress();
    scenarioState->BonusObjectiveData = GetBonusObjectivesData();
    scenarioState->ScenarioCompleted = _complete;
}

void Scenario::SendScenarioState(Player* player)
{
    WorldPackets::Scenario::ScenarioState scenarioState;
    BuildScenarioState(&scenarioState);
    player->SendDirectMessage(scenarioState.Write());
}

std::vector<WorldPackets::Scenario::BonusObjectiveData> Scenario::GetBonusObjectivesData()
{
    std::vector<WorldPackets::Scenario::BonusObjectiveData> bonusObjectivesData;
    for (auto itr = _data->Steps.begin(); itr != _data->Steps.end(); ++itr)
    {
        if (!(itr->second->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE))
            continue;

        CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(itr->second->CriteriaTreeID);
        if (tree)
        {
            WorldPackets::Scenario::BonusObjectiveData bonusObjectiveData;
            bonusObjectiveData.Id = itr->second->ID;
            bonusObjectiveData.ObjectiveCompleted = IsCompletedCriteriaTree(tree);
            bonusObjectivesData.push_back(bonusObjectiveData);
        }
    }

    return bonusObjectivesData;
}

std::vector<WorldPackets::Scenario::CriteriaProgress> Scenario::GetCriteriasProgress()
{
    std::vector<WorldPackets::Scenario::CriteriaProgress> criteriasProgress;

    if (!_criteriaProgress.empty())
    {
        for (auto critItr = _criteriaProgress.begin(); critItr != _criteriaProgress.end(); ++critItr)
        {
            WorldPackets::Scenario::CriteriaProgress criteriaProgress;
            criteriaProgress.Id = critItr->first;
            criteriaProgress.Quantity = critItr->second.Counter;
            criteriaProgress.Date = critItr->second.Date;
            criteriaProgress.Player = critItr->second.PlayerGUID;
            criteriasProgress.push_back(criteriaProgress);
        }
    }

    return criteriasProgress;
}

std::string Scenario::GetOwnerInfo() const
{
    return std::string();
}

CriteriaList const & Scenario::GetCriteriaByType(CriteriaTypes type) const
{
    return sCriteriaMgr->GetScenarioCriteriaByType(type);
}

void Scenario::SendBootPlayer(Player* player) const
{
    player->SendDirectMessage(WorldPackets::Scenario::ScenarioBoot().Write());
}