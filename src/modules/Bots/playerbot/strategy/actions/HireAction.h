#pragma once

#include "../Action.h"

namespace ai
{
    class HireAction : public Action {
    public:
        HireAction(PlayerbotAI* ai) : Action(ai, "hire") {}
        virtual bool Execute(Event event);

    };

}
