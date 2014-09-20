#pragma once
#include "../Value.h"

namespace ai
{
    class ManaSaveLevelValue : public ManualSetValue<double>
	{
	public:
        ManaSaveLevelValue(PlayerbotAI* ai) : ManualSetValue<double>(ai, 1.0, "mana save level") {}
    };
}
