#pragma once

#include "../Action.h"

namespace ai
{
    class LogLevelAction : public Action {
    public:
        LogLevelAction(PlayerbotAI* ai) : Action(ai, "log") {}
        virtual bool Execute(Event event);

    public:
        static string logLevel2string(LogLevel level);
        static LogLevel string2logLevel(string level);
    };

}