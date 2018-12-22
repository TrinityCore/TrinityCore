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

#include "ActionScript.h"
#include "GameTime.h"

ActionScriptThread::ActionScriptThread(ActionScript const& script, size_t initialStep)
    : _script(script)
{
    StepTo(initialStep);
}

void ActionScriptThread::Update()
{
    if (!_currentStep)
        return;

    if (Optional<bool> success = EvaluateCurrentStep())
    {
        if (*success)
            StepTo(_currentStep->GotoSuccess);
        else
            StepTo(_currentStep->GotoFailure);
    }
    else if (_stepTimeout <= GameTime::Now())
        StepTo(_currentStep->GotoTimeout);
    else
        return;

    return Update();
}

// true means success, false means failure, none means no result
Optional<bool> ActionScriptThread::EvaluateCurrentStep()
{
    return {};
}

void ActionScriptThread::StepTo(Optional<size_t> step)
{
    if (!step)
    {
        _currentStep = nullptr;
        return;
    }

    _currentStep = &_script[*step];
    _stepTimeout = GameTime::Now() + _currentStep->Timeout;
    // @todo execute step
}
