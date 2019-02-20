#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class QueryItemUsageAction : public InventoryAction {
    public:
        QueryItemUsageAction(PlayerbotAI* ai, string name = "query item usage") : InventoryAction(ai, name) {}
        virtual bool Execute(Event event);

    protected:
        void QueryItemsUsage(ItemIds items);
        bool QueryItemUsage(ItemTemplate const *item);
        void QueryItemPrice(ItemTemplate const *item);
        void QueryQuestItem(uint32 itemId, const Quest *questTemplate, const QuestStatusData *questStatus);
        void QueryQuestItem(uint32 itemId);

    private:
        ostringstream out;

    };
}
