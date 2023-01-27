#pragma once

#include "../Action.h"

namespace ai
{
    class TellMasterAction : public Action {
    public:
        TellMasterAction(PlayerbotAI* ai, string text) : Action(ai, "tell master"), text(text) {}

        virtual bool Execute(Event event)
        {
            ai->TellMaster(text);
            return true;
        }

    private:
        string text;
    };

    class OutOfReactRangeAction : public MovementAction {
    public:
        OutOfReactRangeAction(PlayerbotAI* ai) : MovementAction(ai, "tell out of react range") {}

        virtual bool Execute(Event event)
        {
            bool canFollow = Follow(AI_VALUE(Unit*, "master target"));
            if (!canFollow)
            {
                ai->SetNextCheckDelay(5000);
                return false;
            }

            ai->TellMaster("Wait for me!");
            return true;
        }
   };
}
