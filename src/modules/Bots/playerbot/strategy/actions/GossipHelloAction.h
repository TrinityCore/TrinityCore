#pragma once

#include "../Action.h"

namespace ai
{
    class GossipHelloAction : public Action {
    public:
        GossipHelloAction(PlayerbotAI* ai) : Action(ai, "gossip hello") {}
        virtual bool Execute(Event event);

    private:
        void TellGossipMenus();
        bool ProcessGossip(int menuToSelect);
        void TellGossipText(uint32 textId);
    };

}
