#pragma once

#include "../Action.h"
#include "QuestAction.h"

namespace ai
{
    class GreetAction : public Action
    {
    public:
        GreetAction(PlayerbotAI* ai);
        virtual bool Execute(Event event);
    };
}
