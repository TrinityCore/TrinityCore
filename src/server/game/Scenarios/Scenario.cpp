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

#include "Scenario.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScenarioMgr.h"
#include "ScenarioPackets.h"
#include "WorldSession.h"

Scenario::Scenario(Map* map, ScenarioData const* scenarioData) : _map(map), _data(scenarioData),
    _guid(ObjectGuid::Create<HighGuid::Scenario>(map->GetId(), scenarioData->Entry->ID, map->GenerateLowGuid<HighGuid::Scenario>())),
    _currentstep(nullptr)
{
    ASSERT(_data);

    for (std::pair<uint8 const, ScenarioStepEntry const*> const& scenarioStep : _data->Steps)
        SetStepState(scenarioStep.second, SCENARIO_STEP_NOT_STARTED);

    if (ScenarioStepEntry const* step = GetFirstStep())
        SetStep(step);
    else
        TC_LOG_ERROR("scenario", "Scenario::Scenario: Could not launch Scenario (id: {}), found no valid scenario step", _data->Entry->ID);
}

Scenario::~Scenario()
{
    for (ObjectGuid guid : _players)
        if (Player* player = ObjectAccessor::GetPlayer(_map, guid))
            SendBootPlayer(player);

    _players.clear();
}

void Scenario::Reset()
{
    CriteriaHandler::Reset();
    SetStep(GetFirstStep());
}

void Scenario::CompleteStep(ScenarioStepEntry const* step)
{
    if (Quest const* quest = sObjectMgr->GetQuestTemplate(step->RewardQuestID))
        for (ObjectGuid guid : _players)
            if (Player* player = ObjectAccessor::GetPlayer(_map, guid))
                player->RewardQuest(quest, LootItemType::Item, 0, nullptr, false);

    if (step->IsBonusObjective())
        return;

    ScenarioStepEntry const* newStep = nullptr;
    for (auto const& _step : _data->Steps)
    {
        if (_step.second->IsBonusObjective())
            continue;

        if (GetStepState(_step.second) == SCENARIO_STEP_DONE)
            continue;

        if (!newStep || _step.second->OrderIndex < newStep->OrderIndex)
            newStep = _step.second;
    }

    SetStep(newStep);
    if (IsComplete())
        CompleteScenario();
    else
        TC_LOG_ERROR("scenario", "Scenario::CompleteStep: Scenario (id: {}, step: {}) was completed, but could not determine new step, or validate scenario completion.", step->ScenarioID, step->ID);
}

void Scenario::CompleteScenario()
{
    SendPacket(WorldPackets::Scenario::ScenarioCompleted(_data->Entry->ID).Write());

    DoForAllPlayers([&](Player* player)
    {
        player->UpdateCriteria(CriteriaType::CompleteAnyScenario, 1);
        player->UpdateCriteria(CriteriaType::CompleteScenario, _data->Entry->ID);
    });
}

void Scenario::SetStep(ScenarioStepEntry const* step)
{
    _currentstep = step;
    if (step)
    {
        SetStepState(step, SCENARIO_STEP_IN_PROGRESS);
        for (ObjectGuid const& guid : _players)
            if (Player* player = ObjectAccessor::GetPlayer(_map, guid))
                player->StartCriteria(CriteriaStartEvent::BeginScenarioStep, step->ID);
    }

    DoForAllPlayers([&](Player const* receiver)
    {
        WorldPackets::Scenario::ScenarioState scenarioState;
        BuildScenarioStateFor(receiver, &scenarioState);
        receiver->SendDirectMessage(scenarioState.Write());
    });
}

void Scenario::OnPlayerEnter(Player* player)
{
    _players.insert(player->GetGUID());
    SendScenarioState(player);
}

void Scenario::OnPlayerExit(Player* player)
{
    _players.erase(player->GetGUID());
    SendBootPlayer(player);
}

bool Scenario::IsComplete() const
{
    for (std::pair<uint8 const, ScenarioStepEntry const*> const& scenarioStep : _data->Steps)
    {
        if (scenarioStep.second->IsBonusObjective())
            continue;

        if (GetStepState(scenarioStep.second) != SCENARIO_STEP_DONE)
            return false;
    }

    return true;
}

ScenarioEntry const* Scenario::GetEntry() const
{
    return _data->Entry;
}

ScenarioStepState Scenario::GetStepState(ScenarioStepEntry const* step) const
{
    auto itr = _stepStates.find(step);
    if (itr == _stepStates.end())
        return SCENARIO_STEP_INVALID;

    return itr->second;
}

void Scenario::SendCriteriaUpdate(Criteria const* criteria, CriteriaProgress const* progress, Seconds timeElapsed, bool timedCompleted) const
{
    DoForAllPlayers([=](Player const* receiver)
    {
        WorldPackets::Scenario::ScenarioProgressUpdate progressUpdate;
        progressUpdate.CriteriaProgress.Id = criteria->ID;
        progressUpdate.CriteriaProgress.Quantity = progress->Counter;
        progressUpdate.CriteriaProgress.Player = progress->PlayerGUID;
        progressUpdate.CriteriaProgress.Date.SetUtcTimeFromUnixTime(progress->Date);
        progressUpdate.CriteriaProgress.Date += receiver->GetSession()->GetTimezoneOffset();
        if (criteria->Entry->StartTimer)
            progressUpdate.CriteriaProgress.Flags = timedCompleted ? 1 : 0;

        progressUpdate.CriteriaProgress.TimeFromStart = timeElapsed;
        progressUpdate.CriteriaProgress.TimeFromCreate = Seconds::zero();

        receiver->SendDirectMessage(progressUpdate.Write());
    });
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

    ScenarioStepState const state = GetStepState(step);
    if (state == SCENARIO_STEP_DONE)
        return false;

    ScenarioStepEntry const* currentStep = GetStep();
    if (!currentStep)
        return false;

    if (!step->IsBonusObjective())
        if (step != currentStep)
            return false;

    return CriteriaHandler::CanCompleteCriteriaTree(tree);
}

void Scenario::CompletedCriteriaTree(CriteriaTree const* tree, Player* /*referencePlayer*/)
{
    ScenarioStepEntry const* step = ASSERT_NOTNULL(tree->ScenarioStep);
    if (!IsCompletedStep(step))
        return;

    SetStepState(step, SCENARIO_STEP_DONE);
    CompleteStep(step);
}

bool Scenario::IsCompletedStep(ScenarioStepEntry const* step)
{
    CriteriaTree const* tree = sCriteriaMgr->GetCriteriaTree(step->Criteriatreeid);
    if (!tree)
        return false;

    return IsCompletedCriteriaTree(tree);
}

void Scenario::DoForAllPlayers(std::function<void(Player*)> const& worker) const
{
    for (ObjectGuid guid : _players)
        if (Player* player = ObjectAccessor::GetPlayer(_map, guid))
            worker(player);
}

void Scenario::SendPacket(WorldPacket const* data) const
{
    DoForAllPlayers([data](Player const* player)
    {
        player->SendDirectMessage(data);
    });
}

void Scenario::BuildScenarioStateFor(Player const* player, WorldPackets::Scenario::ScenarioState* scenarioState) const
{
    scenarioState->ScenarioGUID = _guid;
    scenarioState->ScenarioID = _data->Entry->ID;
    if (ScenarioStepEntry const* step = GetStep())
        scenarioState->CurrentStep = step->ID;
    scenarioState->CriteriaProgress = GetCriteriasProgressFor(player);
    scenarioState->BonusObjectives = GetBonusObjectivesData();
    // Don't know exactly what this is for, but seems to contain list of scenario steps that we're either on or that are completed
    for (std::pair<ScenarioStepEntry const* const, ScenarioStepState> const& state : _stepStates)
    {
        if (state.first->IsBonusObjective())
            continue;

        switch (state.second)
        {
            case SCENARIO_STEP_IN_PROGRESS:
            case SCENARIO_STEP_DONE:
                break;
            case SCENARIO_STEP_NOT_STARTED:
            default:
                continue;
        }

        scenarioState->PickedSteps.push_back(state.first->ID);
    }
    scenarioState->ScenarioComplete = IsComplete();
}

ScenarioStepEntry const* Scenario::GetFirstStep() const
{
    // Do it like this because we don't know what order they're in inside the container.
    ScenarioStepEntry const* firstStep = nullptr;
    for (std::pair<uint8 const, ScenarioStepEntry const*> const& scenarioStep : _data->Steps)
    {
        if (scenarioStep.second->IsBonusObjective())
            continue;

        if (!firstStep || scenarioStep.second->OrderIndex < firstStep->OrderIndex)
            firstStep = scenarioStep.second;
    }

    return firstStep;
}

ScenarioStepEntry const* Scenario::GetLastStep() const
{
    // Do it like this because we don't know what order they're in inside the container.
    ScenarioStepEntry const* lastStep = nullptr;
    for (std::pair<uint8 const, ScenarioStepEntry const*> const& scenarioStep : _data->Steps)
    {
        if (scenarioStep.second->IsBonusObjective())
            continue;

        if (!lastStep || scenarioStep.second->OrderIndex > lastStep->OrderIndex)
            lastStep = scenarioStep.second;
    }

    return lastStep;
}

void Scenario::SendScenarioState(Player const* player) const
{
    WorldPackets::Scenario::ScenarioState scenarioState;
    BuildScenarioStateFor(player, &scenarioState);
    player->SendDirectMessage(scenarioState.Write());
}

std::vector<WorldPackets::Scenario::BonusObjectiveData> Scenario::GetBonusObjectivesData() const
{
    std::vector<WorldPackets::Scenario::BonusObjectiveData> bonusObjectivesData;
    for (std::pair<uint8 const, ScenarioStepEntry const*> const& scenarioStep : _data->Steps)
    {
        if (!scenarioStep.second->IsBonusObjective())
            continue;

        if (sCriteriaMgr->GetCriteriaTree(scenarioStep.second->Criteriatreeid))
        {
            WorldPackets::Scenario::BonusObjectiveData bonusObjectiveData;
            bonusObjectiveData.BonusObjectiveID = scenarioStep.second->ID;
            bonusObjectiveData.ObjectiveComplete = GetStepState(scenarioStep.second) == SCENARIO_STEP_DONE;
            bonusObjectivesData.push_back(bonusObjectiveData);
        }
    }

    return bonusObjectivesData;
}

std::vector<WorldPackets::Achievement::CriteriaProgress> Scenario::GetCriteriasProgressFor(Player const* player) const
{
    std::vector<WorldPackets::Achievement::CriteriaProgress> criteriasProgress;

    for (auto const& [criteriaId, progress] : _criteriaProgress)
    {
        WorldPackets::Achievement::CriteriaProgress& criteriaProgress = criteriasProgress.emplace_back();
        criteriaProgress.Id = criteriaId;
        criteriaProgress.Quantity = progress.Counter;
        criteriaProgress.Date.SetUtcTimeFromUnixTime(progress.Date);
        criteriaProgress.Date += player->GetSession()->GetTimezoneOffset();
        criteriaProgress.Player = progress.PlayerGUID;
    }

    return criteriasProgress;
}

CriteriaList const& Scenario::GetCriteriaByType(CriteriaType type, uint32 /*asset*/) const
{
    return sCriteriaMgr->GetScenarioCriteriaByTypeAndScenario(type, _data->Entry->ID);
}

void Scenario::SendBootPlayer(Player const* player) const
{
    WorldPackets::Scenario::ScenarioVacate scenarioBoot;
    scenarioBoot.ScenarioGUID = _guid;
    scenarioBoot.ScenarioID = _data->Entry->ID;
    player->SendDirectMessage(scenarioBoot.Write());
}
