/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __TRINITY_SCENARIO_H
#define __TRINITY_SCENARIO_H

#include "CriteriaHandler.h"
#include "ScenarioPackets.h"


namespace WorldPackets
{
    namespace Scenario
    {
        class ScenarioState;
    }
}

struct ScenarioData
{
    ScenarioEntry const* Entry;
    std::map<uint8, ScenarioStepEntry const*> Steps;
};

enum ScenarioStepState
{
    SCENARIO_STEP_NOT_STARTED   = 1,
    SCENARIO_STEP_IN_PROGRESS   = 2,
    SCENARIO_STEP_DONE          = 3
};

class TC_GAME_API Scenario : public CriteriaHandler
{
    public:
        Scenario(ScenarioData const* scenarioData);
        ~Scenario();

        void Reset() override;
        void SetStep(ScenarioStepEntry const* step);

        virtual void CompleteStep(ScenarioStepEntry const* step);
        virtual void CompleteScenario() { return SendPacket(WorldPackets::Scenario::ScenarioCompleted(_data->Entry->ID).Write()); }
        
        virtual void OnPlayerEnter(Player* player);
        virtual void OnPlayerExit(Player* player);
        virtual void Update(uint32) { }
        
        bool IsComplete();
        void SetStepState(ScenarioStepEntry const* step, ScenarioStepState state) { _stepStates[step] = state; }
        ScenarioStepState GetStepState(ScenarioStepEntry const* step);
        ScenarioStepEntry const* GetStep() const { return _currentstep; }
        ScenarioStepEntry const* GetFirstStep() const;

        void SendScenarioState(Player* player);
        void SendBootPlayer(Player* player) const;

    protected:
        GuidSet m_players;

        void SendCriteriaUpdate(Criteria const* criteria, CriteriaProgress const* progress, uint32 timeElapsed, bool timedCompleted) const override;
        void SendCriteriaProgressRemoved(uint32 criteriaId) override { }

        bool CanUpdateCriteriaTree(Criteria const* criteria, CriteriaTree const* tree, Player* referencePlayer) const override;
        bool CanCompleteCriteriaTree(CriteriaTree const* tree) override;
        void CompletedCriteriaTree(CriteriaTree const* tree, Player* referencePlayer) override;
        void AfterCriteriaTreeUpdate(CriteriaTree const* /*tree*/, Player* /*referencePlayer*/) override { }
        
        void SendPacket(WorldPacket const* data) const override;

        void SendAllData(Player const* /*receiver*/) const override { }

        void BuildScenarioState(WorldPackets::Scenario::ScenarioState* scenarioState);

        std::vector<WorldPackets::Scenario::BonusObjectiveData> GetBonusObjectivesData();
        std::vector<WorldPackets::Achievement::CriteriaProgress> GetCriteriasProgress();

        CriteriaList const& GetCriteriaByType(CriteriaTypes type) const override;
        ScenarioData const* _data;

    private:
        ScenarioStepEntry const* _currentstep;
        std::map<ScenarioStepEntry const*, ScenarioStepState> _stepStates;
};

#endif
