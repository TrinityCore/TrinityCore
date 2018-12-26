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

#include "ActionThreadStep.h"
#include "ActionScript.h"

class NullStep : public ActionThreadStep
{
    public:
        NullStep(ActionThread const& thread, ActionScriptStep const& temp) : ActionThreadStep(thread, temp) {}
        void Initialize() override {}
        Optional<bool> Evaluate() override {
            return {};
        }
        void Abort() override {}
};

/*static*/ std::unique_ptr<ActionThreadStep> ActionThreadStep::StepTo(ActionThread const& thread, ActionScriptStep const& stepTemplate)
{
    ActionThreadStep* step;
    switch (stepTemplate.StepType)
    {
        case ACTIONSCRIPT_NULL:
            step = new NullStep(thread, stepTemplate);
            break;
    }
    step->Initialize();
    return std::unique_ptr<ActionThreadStep>(step);
}
