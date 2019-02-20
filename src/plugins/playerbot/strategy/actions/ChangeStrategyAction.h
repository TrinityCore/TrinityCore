#pragma once

#include "../Action.h"

namespace ai
{
	class ChangeCombatStrategyAction : public Action {
	public:
		ChangeCombatStrategyAction(PlayerbotAI* ai, string name = "co") : Action(ai, name) {}

    public:
        virtual bool Execute(Event event);
    };

    class ChangeNonCombatStrategyAction : public Action {
    public:
        ChangeNonCombatStrategyAction(PlayerbotAI* ai) : Action(ai, "nc") {}

    public:
        virtual bool Execute(Event event);
    };

    class ChangeDeadStrategyAction : public Action {
    public:
        ChangeDeadStrategyAction(PlayerbotAI* ai) : Action(ai, "dead") {}

    public:
        virtual bool Execute(Event event);
    };
}
