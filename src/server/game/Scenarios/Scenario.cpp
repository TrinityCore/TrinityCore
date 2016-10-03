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
#include "ScenarioPackets.h"

Scenario::Scenario(ScenarioData const* scenarioData) : _data(scenarioData), _currentstep(nullptr)
{
    ASSERT(_data);

    if (ScenarioStepEntry const* step = GetFirstStep())
        SetStep(step);
    else
        TC_LOG_ERROR("scenario", "Scenario::Scenario: Could not launch Scenario (id: %u), found no valid scenario step");
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

void Scenario::CompleteStep(ScenarioStepEntry const* step)
{
    if (Quest const* quest = sObjectMgr->GetQuestTemplate(step->QuestRewardID))
        for (auto guid : m_players)
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                player->RewardQuest(quest, 0, nullptr, false);

    if (step->IsBonusObjective())
        return;

    ScenarioStepEntry const* newStep = nullptr;
    for (auto _step : _data->Steps)
    {
        if (_step.second->IsBonusObjective())
            continue;

        if (IsStepComplete(_step.second))
            continue;

        if (!newStep || _step.second->Step < newStep->Step)
            newStep = _step.second;
    }

    SetStep(newStep);
    if (IsComplete()) // Redundant check?
        CompleteScenario();
    else
        TC_LOG_ERROR("scenario", "Scenario::CompleteStep: Scenario (id: %u, step: %u) was completed, but could not determine new step, or validate scenario completion.", step->ScenarioID, step->ID);
}

void Scenario::SetStep(ScenarioStepEntry const* step)
{
    _currentstep = step;

    WorldPackets::Scenario::ScenarioState scenarioState;
    BuildScenarioState(&scenarioState);
    SendPacket(scenarioState.Write());
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

bool Scenario::IsComplete()
{
    for (auto step : _data->Steps)
    {
        if (step.second->IsBonusObjective())
            continue;

        if (!IsStepComplete(step.second))
            return false;
    }

    return true;
}

bool Scenario::IsStepComplete(ScenarioStepEntry const* step)
{
    std::map<ScenarioStepEntry const*, bool>::const_iterator itr = _scenarioStepCompleteMap.find(step);
    if (itr == _scenarioStepCompleteMap.end())
        return false;

    return itr->second;
}

void Scenario::SendCriteriaUpdate(Criteria const * criteria, CriteriaProgress const * progress, uint32 timeElapsed, bool timedCompleted) const
{
    WorldPackets::Scenario::ScenarioProgressUpdate progressUpdate;
    WorldPackets::Achievement::CriteriaProgress criteriaProgress;
    criteriaProgress.Id = criteria->ID;
    criteriaProgress.Quantity = progress->Counter;
    criteriaProgress.Player = progress->PlayerGUID;
    criteriaProgress.Date = progress->Date;
    if (criteria->Entry->StartTimer)
        criteriaProgress.Flags = timedCompleted ? 1 : 0;

    criteriaProgress.TimeFromStart = timeElapsed;
    criteriaProgress.TimeFromCreate = 0;

    progressUpdate.CriteriaProgress = criteriaProgress;
    SendPacket(progressUpdate.Write());
}

void Scenario::SendCriteriaProgressRemoved(uint32 criteriaId)
{
}

bool Scenario::CanUpdateCriteriaTree(Criteria const * /*criteria*/, CriteriaTree const * tree, Player * /*referencePlayer*/) const
{
    ScenarioStepEntry const* step = tree->ScenarioStep;
    if (!step)
        return false;

    if (step->ScenarioID != _data->Entry->ID)
        return false;

    ScenarioStepEntry const* currentStep = GetStep();
    if (!currentStep)
        return false;

    if (step->IsBonusObjective())
        return true;

    return currentStep == step;
}

bool Scenario::CanCompleteCriteriaTree(CriteriaTree const* tree)
{
    ScenarioStepEntry const* step = tree->ScenarioStep;
    if (!step)
        return false;

    if (step->ScenarioID != _data->Entry->ID)
        return false;

    if (step->IsBonusObjective())
        return !IsComplete();

    if (step != GetStep())
        return false;

    return true;
}

void Scenario::CompletedCriteriaTree(CriteriaTree const * tree, Player * referencePlayer)
{
    ScenarioStepEntry const* step = tree->ScenarioStep;
    if (!step)
        return;

    if (!step->IsBonusObjective() && step != GetStep())
        return;

    if (IsStepComplete(step))
        return;

    SetStepComplete(step);
    CompleteStep(step);
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
    if (ScenarioStepEntry const* step = GetStep())
        scenarioState->CurrentStep = step->ID;
    scenarioState->CriteriaProgress = GetCriteriasProgress();
    scenarioState->BonusObjectiveData = GetBonusObjectivesData();
    // We don't actually know what this does, can only guess behavior
    for (auto state : ScenarioState)
    {
        if (state.first->IsBonusObjective())
            continue;

        if (state.second != SCENARIO_STEP_IN_PROGRESS ||
            state.second != SCENARIO_STEP_DONE)
            continue;

        scenarioState->TraversedSteps.push_back(state.first->ID);
    }
    scenarioState->ScenarioCompleted = IsComplete();
}

ScenarioStepEntry const* Scenario::GetFirstStep() const
{
    // Do it like this because we don't know what order they're in, inside the container.
    ScenarioStepEntry const* firstStep = nullptr;
    for (auto scenarioStep : _data->Steps)
    {
        if (scenarioStep.second->IsBonusObjective())
            continue;

        if (!firstStep || scenarioStep.second->Step < firstStep->Step)
            firstStep = scenarioStep.second;
    }

    return firstStep;
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
        if (!itr->second->IsBonusObjective())
            continue;

        CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(itr->second->CriteriaTreeID);
        if (tree)
        {
            WorldPackets::Scenario::BonusObjectiveData bonusObjectiveData;
            bonusObjectiveData.Id = itr->second->ID;
            bonusObjectiveData.ObjectiveCompleted = IsStepComplete(itr->second);
            bonusObjectivesData.push_back(bonusObjectiveData);
        }
    }

    return bonusObjectivesData;
}

std::vector<WorldPackets::Achievement::CriteriaProgress> Scenario::GetCriteriasProgress()
{
    std::vector<WorldPackets::Achievement::CriteriaProgress> criteriasProgress;

    if (!_criteriaProgress.empty())
    {
        for (auto critItr = _criteriaProgress.begin(); critItr != _criteriaProgress.end(); ++critItr)
        {
            WorldPackets::Achievement::CriteriaProgress criteriaProgress;
            criteriaProgress.Id = critItr->first;
            criteriaProgress.Quantity = critItr->second.Counter;
            criteriaProgress.Date = critItr->second.Date;
            criteriaProgress.Player = critItr->second.PlayerGUID;
            criteriasProgress.push_back(criteriaProgress);
        }
    }

    return criteriasProgress;
}

CriteriaList const & Scenario::GetCriteriaByType(CriteriaTypes type) const
{
    return sCriteriaMgr->GetScenarioCriteriaByType(type);
}

void Scenario::SendBootPlayer(Player* player) const
{
    player->SendDirectMessage(WorldPackets::Scenario::ScenarioBoot().Write());
}
