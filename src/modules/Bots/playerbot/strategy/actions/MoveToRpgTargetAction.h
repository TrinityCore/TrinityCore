#pragma once

#include "../Action.h"
#include "MovementActions.h"
#include "../values/LastMovementValue.h"

namespace ai
{
    class MoveToRpgTargetAction : public MovementAction {
    public:
        MoveToRpgTargetAction(PlayerbotAI* ai) : MovementAction(ai, "move to rpg target") {}

        virtual bool Execute(Event event);
        virtual bool isUseful();
    };

}
