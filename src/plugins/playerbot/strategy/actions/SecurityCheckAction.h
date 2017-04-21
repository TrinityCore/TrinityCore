#pragma once

#include "../Action.h"

namespace ai
{
    class SecurityCheckAction : public Action
    {
    public:
        SecurityCheckAction(PlayerbotAI* ai) : Action(ai, "security check") {}
        virtual bool isUseful();
        virtual bool Execute(Event event);
    };
}
