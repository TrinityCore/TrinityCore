#pragma once

#include "../Action.h"


namespace ai
{
    class ListSpellsAction : public Action {
    public:
        ListSpellsAction(PlayerbotAI* ai) : Action(ai, "spells") {}

        virtual bool Execute(Event event);
  
    };

}