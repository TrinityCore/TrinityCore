#pragma once

#include "../Action.h"

namespace ai
{
    class ShareQuestAction : public Action {
    public:
        ShareQuestAction(PlayerbotAI* ai) : Action(ai, "share quest") {}
        virtual bool Execute(Event event);
    };

}
