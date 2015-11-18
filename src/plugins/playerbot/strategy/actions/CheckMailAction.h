#pragma once

#include "../Action.h"
#include "QuestAction.h"

namespace ai
{
    class CheckMailAction : public Action
    {
    public:
        CheckMailAction(PlayerbotAI* ai) : Action(ai, "check mail") {}
        virtual bool Execute(Event event);

    private:
        void ProcessMail(Mail* mail, Player* owner);
    };
}
