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

Scenario::Scenario(ScenarioData const* scenarioData) : _data(scenarioData), _currentstep(nullptr), _firstStep(nullptr), _lastStep(nullptr), _complete(false), _canReward(false)
{
    ASSERT(_data);
    for (auto itr = _data->Steps.begin(); itr != _data->Steps.end(); ++itr)
    {
        if (itr->second->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE)
            continue;

        if (!_firstStep || _firstStep->Step > itr->second->Step)
            _firstStep = itr->second;

        if (!_lastStep || _lastStep->Step < itr->second->Step)
            _lastStep = itr->second;

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

void Scenario::CompleteStep(ScenarioStepEntry const* step)
{
    if (!step->IsBonusObjective())
        AdvanceStep();

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(step->QuestRewardID))
        for (auto guid : m_players)
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                player->RewardQuest(quest, 0, nullptr, false);
}

void Scenario::AdvanceStep()
{
    for (auto step : _data->Steps)
    {
        if (step.second->IsBonusObjective())
            continue;

        // Can only do this because they are in order
        if (step.second->Step > GetStep()->Step)
        {
            SetStep(step.second);
            return;
        }
    }

    SetStep(nullptr);
}

void Scenario::SetStep(ScenarioStepEntry const* step)
{
    _currentstep = step;
    if (!step && !IsComplete())
        _complete = true;

    WorldPackets::Scenario::ScenarioState scenarioState;
    BuildScenarioState(&scenarioState);
    SendPacket(scenarioState.Write());


    if (!step && IsComplete())
        CompleteScenario();
}

void Scenario::CompleteScenario()
{
    if (!IsComplete())
        return;

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
    ScenarioStepEntry const* step = GetStep();
    if (!tree->ScenarioStep || !step || tree->ScenarioStep->ScenarioID != step->ScenarioID)
        return false;

    if (tree->ScenarioStep->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE)
        return !(IsComplete() && tree->ScenarioStep->Flags & SCENARIO_STEP_FLAG_SCENARIO_NOT_DONE);

    return step->Step == tree->ScenarioStep->Step;
}

void Scenario::CompletedCriteriaTree(CriteriaTree const * tree, Player * referencePlayer)
{
    if (!tree->ScenarioStep || _complete)
        return;

    CompleteStep(tree->ScenarioStep);
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
        if (state.first->Flags & SCENARIO_STEP_FLAG_BONUS_OBJECTIVE)
            continue;

        if (state.second != SCENARIO_STEP_IN_PROGRESS ||
            state.second != SCENARIO_STEP_DONE)
            continue;

        scenarioState->TraversedSteps.push_back(state.first->ID);
    }
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