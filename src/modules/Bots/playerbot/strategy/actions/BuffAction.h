#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class BuffAction : public InventoryAction {
    public:
        BuffAction(PlayerbotAI* ai) : InventoryAction(ai, "buff") {}
        virtual bool Execute(Event event);

    private:
        void TellHeader(uint32 subClass);
    };

}
