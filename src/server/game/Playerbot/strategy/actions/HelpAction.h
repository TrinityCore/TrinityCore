#pragma once

#include "../Action.h"

namespace ai
{
    class HelpAction : public Action {
    public:
        HelpAction(PlayerbotAI* ai);
        virtual ~HelpAction();
        virtual bool Execute(Event event);

    private:
        void TellChatCommands();
        void TellStrategies();
        string CombineSupported(set<string> commands);

    private:
        NamedObjectContext<Action>* chatContext;
    };

}
