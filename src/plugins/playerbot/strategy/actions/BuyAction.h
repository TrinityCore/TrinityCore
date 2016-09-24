#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class BuyAction : public InventoryAction {
    public:
        BuyAction(PlayerbotAI* ai) : InventoryAction(ai, "buy") {}
        virtual bool Execute(Event event);

    private:
        bool TradeItem(FindItemVisitor *visitor, int8 slot);
        bool TradeItem(const Item& item, int8 slot);

    };

}