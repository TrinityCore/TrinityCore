#pragma once
#include "../Value.h"

namespace ai
{
    class LootStrategyValue : public ManualSetValue<LootStrategy>
	{
	public:
        LootStrategyValue(PlayerbotAI* ai) : ManualSetValue<LootStrategy>(ai, LOOTSTRATEGY_SKILL) {}
    };
}
