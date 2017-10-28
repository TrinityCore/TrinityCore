#pragma once

#include "../Action.h"

namespace ai
{
    class InventoryChangeFailureAction : public Action {
    public:
        InventoryChangeFailureAction(PlayerbotAI* ai) : Action(ai, "inventory change failure") {}
        virtual bool Execute(Event event);
    };
}