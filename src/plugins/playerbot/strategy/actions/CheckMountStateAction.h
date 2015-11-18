#pragma once

#include "../Action.h"
#include "MovementActions.h"
#include "../values/LastMovementValue.h"

namespace ai
{
    class CheckMountStateAction : public Action {
    public:
        CheckMountStateAction(PlayerbotAI* ai) : Action(ai, "check mount state") {}

        virtual bool Execute(Event event);

    private:
        bool Mount();
    };

}
