#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class UnequipAction : public InventoryAction {
    public:
        UnequipAction(PlayerbotAI* ai) : InventoryAction(ai, "unequip") {}
        virtual bool Execute(Event event);

    private:
        void UnequipItem(Item& item);
        void UnequipItem(FindItemVisitor* visitor);
    };

}