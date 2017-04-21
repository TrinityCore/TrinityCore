#pragma once

#include "../Action.h"
#include "../../LootObjectStack.h"

namespace ai
{
    class LootStrategyAction : public Action {
    public:
        LootStrategyAction(PlayerbotAI* ai) : Action(ai, "ll") {}
        virtual bool Execute(Event event);

    private:
        static LootStrategy String2LootStrategy(string strategy);
        static string LootStrategy2string(LootStrategy lootStrategy);
   
    };

}