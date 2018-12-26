/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_ACTIONSCRIPT_H
#define TRINITY_ACTIONSCRIPT_H

#include "ActionScriptDefines.h"
#include "Duration.h"
#include "Optional.h"
#include <array>
#include <memory>
#include <vector>

struct TC_GAME_API ActionScriptVariableContent
{

};

struct TC_GAME_API ActionScriptVariableReference
{

};

struct TC_GAME_API ActionScriptStepArgument
{

};

struct TC_GAME_API ActionScriptStep
{
    ActionScriptStepType StepType;
    std::array<ActionScriptStepArgument, ACTIONSCRIPT_STEP_ARGS_MAX> StepArgs;

    Milliseconds Timeout;

    Optional<size_t> GotoSuccess;
    Optional<size_t> GotoFailure;
    Optional<size_t> GotoTimeout;
};

class TC_GAME_API ActionScript
{
    public:
        ActionScriptStep const& operator[](size_t i) const { return steps.at(i); }

        auto begin() const { return steps.cbegin(); }
        auto end() const { return steps.cend(); }
        size_t size() const { return steps.size(); }

    private:
        std::vector<ActionScriptStep> steps;
    friend class ActionScriptManager;
};

class ActionThreadStep;
class TC_GAME_API ActionThread
{
    public:
        ActionThread(Unit* owner, ActionScript const& script, size_t initialStep);
        ~ActionThread();
        // @todo this needs a return value indicating whether behavior should control
        void Update();

        Unit* GetOwner() const { return _owner; }
        
    private:
        Unit* const _owner;
        ActionScript const& _script;
        std::unique_ptr<ActionThreadStep> _currentStep;
        TimePoint _stepTimeout;

        std::vector<ActionScriptVariableContent> _variables;

        void StepTo(Optional<size_t> step);
};

#endif
