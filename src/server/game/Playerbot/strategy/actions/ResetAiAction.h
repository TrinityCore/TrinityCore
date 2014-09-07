#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class ResetAiAction : public Action {
    public:
        ResetAiAction(PlayerbotAI* ai) : Action(ai, "reset ai") {}
        virtual bool Execute(Event event);
    };

}
