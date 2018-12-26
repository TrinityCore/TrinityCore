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
#include "ActionThreadStep.h"
#include "Errors.h"
#include "GameTime.h"

ActionThread::ActionThread(Unit* owner, ActionScript const& script, size_t initialStep)
    : _owner(ASSERT_NOTNULL(owner)), _script(script)
{
    StepTo(initialStep);
}
ActionThread::~ActionThread() {}

ActionThread::ActionThreadState ActionThread::Update()
{
    ActionThreadStep& step = GetCurrentStep();

    Optional<size_t> stepTo;

    if (Optional<bool> success = step.Evaluate())
    {
        if (*success)
            stepTo = step.GetTemplate().GotoSuccess;
        else
            stepTo = step.GetTemplate().GotoFailure;
    }
    else if (_stepTimeout <= GameTime::Now())
    {
        step.Abort();
        stepTo = step.GetTemplate().GotoTimeout;
    }
    else
        return STATE_RUNNING;

    step.~ActionThreadStep();
    if (stepTo)
    {
        StepTo(*stepTo);
        return Update();
    }
    else
        return STATE_FINISHED;
}

void ActionThread::StepTo(size_t step)
{
    ActionScriptStep const& stepTemplate = _script[step];
    ActionThreadStep::StepTo(&_currentStep[0], *this, stepTemplate);
    _stepTimeout = GameTime::Now() + stepTemplate.Timeout;
}
