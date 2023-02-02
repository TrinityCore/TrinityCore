#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class WtsAction : public InventoryAction {
    public:
        WtsAction(PlayerbotAI* ai) : InventoryAction(ai, "wts") {}

    public:
        virtual bool Execute(Event event);
    };

}
