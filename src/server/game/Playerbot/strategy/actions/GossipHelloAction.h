#pragma once

#include "../Action.h"

namespace ai
{
    class GossipHelloAction : public Action {
    public:
        GossipHelloAction(PlayerbotAI* ai) : Action(ai, "gossip hello") {}
        virtual bool Execute(Event event);
    };

}