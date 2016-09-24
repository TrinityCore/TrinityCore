#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{
    class WhoAction : public InventoryAction {
    public:
        WhoAction(PlayerbotAI* ai) : InventoryAction(ai, "who") {}

    public:
        virtual bool Execute(Event event);
        static map<uint32, string> skills;

    private:
        void InitSkills();
        string QueryTrade(string text);
        string QuerySkill(string text);
        string QuerySpec(string text);
    };

}
