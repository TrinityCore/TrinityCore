#pragma once

#include "../Action.h"
#include "QuestAction.h"

namespace ai
{
    class SayAction : public Action, public Qualified
    {
    public:
        SayAction(PlayerbotAI* ai);
        virtual bool Execute(Event event);
        virtual bool isUseful();
        virtual string getName() { return "say::" + qualifier; }

    private:
        static map<string, vector<string> > stringTable;
        static map<string, uint32 > probabilityTable;
    };
}
