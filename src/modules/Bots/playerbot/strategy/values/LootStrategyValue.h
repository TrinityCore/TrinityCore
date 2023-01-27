#pragma once
#include "../../LootObjectStack.h"
#include "../Value.h"

namespace ai
{
    class LootStrategyValue : public ManualSetValue<LootStrategy*>
	{
	public:
        LootStrategyValue(PlayerbotAI* ai) : ManualSetValue<LootStrategy*>(ai, normal) {}
        virtual ~LootStrategyValue() { delete defaultValue; }

        static LootStrategy *normal, *gray, *all, *disenchant;
        static LootStrategy* instance(string name);
    };
}
