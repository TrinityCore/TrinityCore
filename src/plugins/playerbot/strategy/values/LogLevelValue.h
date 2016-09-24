#pragma once
#include "../Value.h"

namespace ai
{
    class LogLevelValue : public ManualSetValue<LogLevel>
	{
	public:
        LogLevelValue(PlayerbotAI* ai) :
            ManualSetValue<LogLevel>(ai, LOG_LEVEL_DEBUG) {}
	};
}
