#pragma once

#include "../Action.h"

namespace ai
{
    class TellSpellAction : public Action
    {
    public:
        TellSpellAction(PlayerbotAI* ai) : Action(ai, "spell") {}

        virtual bool Execute(Event event);
    };

    class TellCastFailedAction : public Action 
    {
    public:
        TellCastFailedAction(PlayerbotAI* ai) : Action(ai, "tell cast failed") {}

        virtual bool Execute(Event event);
    };
}
