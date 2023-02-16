#pragma once

#include "../Action.h"
#include "../../LootObjectStack.h"

namespace ai
{
    class LootStrategyAction : public Action {
    public:
        LootStrategyAction(PlayerbotAI* ai) : Action(ai, "ll") {}
        virtual bool Execute(Event event);
    };

}
