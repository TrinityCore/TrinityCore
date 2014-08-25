#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class TradeStatusAction : public InventoryAction
    {
    public:
        TradeStatusAction(PlayerbotAI* ai) : InventoryAction(ai, "accept trade") {}
        virtual bool Execute(Event event);

    private:
        void BeginTrade();
        bool CheckTrade();
        int32 CalculateCost(TradeData* data, bool sell);
    };
}
