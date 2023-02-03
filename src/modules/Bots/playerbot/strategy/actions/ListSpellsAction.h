#pragma once

#include "../Action.h"
#include "InventoryAction.h"


namespace ai
{
    class ListSpellsAction : public InventoryAction {
    public:
        ListSpellsAction(PlayerbotAI* ai) : InventoryAction(ai, "spells") {}

        virtual bool Execute(Event event);

    private:
        static map<uint32, SkillLineAbilityEntry const*> skillSpells;
        static set<uint32> vendorItems;
    };

}
