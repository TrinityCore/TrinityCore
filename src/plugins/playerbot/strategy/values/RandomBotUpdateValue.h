#pragma once
#include "../Value.h"

namespace ai
{
    class RandomBotUpdateValue : public ManualSetValue<bool>
	{
	public:
        RandomBotUpdateValue(PlayerbotAI* ai) : ManualSetValue<bool>(ai, false) {}
    };
}
