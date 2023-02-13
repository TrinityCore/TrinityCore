#pragma once

#include "../Action.h"

namespace ai
{
    class TellLosAction : public Action {
    public:
        TellLosAction(PlayerbotAI* ai) : Action(ai, "los") {}
        virtual bool Execute(Event event);

    private:
        void ListUnits(string title, list<ObjectGuid> units);
        void ListGameObjects(string title, list<ObjectGuid> gos);
    };

}
