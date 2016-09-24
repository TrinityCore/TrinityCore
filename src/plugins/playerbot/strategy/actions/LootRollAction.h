#pragma once

#include "../Action.h"
#include "QueryItemUsageAction.h"
#include "LootAction.h"

namespace ai
{
    class LootRollAction : public QueryItemUsageAction, public StoreLootAction {
    public:
        LootRollAction(PlayerbotAI* ai) : QueryItemUsageAction(ai, "loot roll"), StoreLootAction(ai) {}
        virtual bool Execute(Event event);
    };

}
