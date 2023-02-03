#pragma once

#include "../Action.h"
#include "../../LootObjectStack.h"
#include "EquipAction.h"
#include "InventoryAction.h"

namespace ai
{
    class OutfitAction : public EquipAction {
    public:
        OutfitAction(PlayerbotAI* ai) : EquipAction(ai, "outfit") {}
        virtual bool Execute(Event event);

    private:

        void List();
        void Save(string name, ItemIds outfit);
        void Update(string name);
    };

}
