#pragma once

#include "../Action.h"
#include "MovementActions.h"

namespace ai
{
    class SummonAction : public MovementAction
    {
    public:
        SummonAction(PlayerbotAI* ai, string name = "summon") : MovementAction(ai, name) {}

        virtual bool Execute(Event event);

    protected:
        bool Teleport();
    };

    class UseMeetingStoneAction : public SummonAction
    {
    public:
        UseMeetingStoneAction(PlayerbotAI* ai) : SummonAction(ai, "use meeting stone") {}

        virtual bool Execute(Event event);
    };
}
