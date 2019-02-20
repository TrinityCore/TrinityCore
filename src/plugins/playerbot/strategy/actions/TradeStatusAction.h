#pragma once

#include "../Action.h"
#include "InventoryAction.h"
#include "QueryItemUsageAction.h"

namespace ai
{
    class TradeStatusAction : public QueryItemUsageAction
    {
    public:
        TradeStatusAction(PlayerbotAI* ai) : QueryItemUsageAction(ai, "accept trade") {}
        virtual bool Execute(Event event);

    private:
        void BeginTrade();
        bool CheckTrade();
        int32 CalculateCost(TradeData* data, bool sell);
    };
}
