#pragma once

#include "../Action.h"

namespace ai
{
    class ChangeChatAction : public Action {
    public:
        ChangeChatAction(PlayerbotAI* ai) : Action(ai, "chat") {}
        virtual bool Execute(Event event);
   
    };

}