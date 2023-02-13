#pragma once

#include "../Action.h"
#include "MovementActions.h"
#include "../values/LastMovementValue.h"

namespace ai
{
    class ChooseRpgTargetAction : public MovementAction {
    public:
        ChooseRpgTargetAction(PlayerbotAI* ai) : MovementAction(ai, "choose rpg target") {}

        virtual bool Execute(Event event);
        virtual bool isUseful();
    };

}
