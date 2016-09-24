#pragma once

#include "../Action.h"
#include "MovementActions.h"

namespace ai
{
	class TeleportAction : public Action {
	public:
		TeleportAction(PlayerbotAI* ai) : Action(ai, "teleport") {}

    public:
        virtual bool Execute(Event event);
    };

}