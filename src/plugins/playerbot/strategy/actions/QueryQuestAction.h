#pragma once

#include "../Action.h"

namespace ai
{
    class QueryQuestAction : public Action {
    public:
        QueryQuestAction(PlayerbotAI* ai) : Action(ai, "query quest") {}
        virtual bool Execute(Event event);

    private:
        void TellObjectives(uint32 questId);
        void TellObjective(string name, int available, int required);
    };
}