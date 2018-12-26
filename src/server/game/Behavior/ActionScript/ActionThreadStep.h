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

#ifndef TRINITY_ACTIONTHREADSTEP_H
#define TRINITY_ACTIONTHREADSTEP_H

#include "ActionScriptDefines.h"
#include "Optional.h"
#include <memory>

class ActionThread;
struct ActionScriptStep;
class TC_GAME_API ActionThreadStep
{
    public:
        virtual ~ActionThreadStep() {}

        static std::unique_ptr<ActionThreadStep> StepTo(ActionThread const& thread, ActionScriptStep const& stepTemplate);

        virtual void Initialize() = 0;
        virtual Optional<bool> Evaluate() = 0;
        virtual void Abort() = 0;

        ActionThread const& GetThread() const { return _thread; }
        ActionScriptStep const& GetTemplate() const { return _template; }

    protected:
        ActionThreadStep(ActionThread const& thread, ActionScriptStep const& stepTemplate) : _thread(thread), _template(stepTemplate) {}

        ActionThread const& _thread;
        ActionScriptStep const& _template;
};

#endif
