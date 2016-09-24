#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class DestroyItemAction : public InventoryAction {
    public:
        DestroyItemAction(PlayerbotAI* ai) : InventoryAction(ai, "destroy") {}
        virtual bool Execute(Event event);

    private:
        void DestroyItem(FindItemVisitor* visitor);
    };

}
