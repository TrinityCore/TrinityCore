#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class CastCustomSpellAction : public InventoryAction
    {
    public:
        CastCustomSpellAction(PlayerbotAI* ai) : InventoryAction(ai, "cast custom spell") {}
        virtual bool Execute(Event event);
    };
}
