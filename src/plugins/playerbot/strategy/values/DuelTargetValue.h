#pragma once
#include "../Value.h"
#include "TargetValue.h"

namespace ai
{
    class DuelTargetValue : public TargetValue
	{
	public:
        DuelTargetValue(PlayerbotAI* ai) : TargetValue(ai) {}

    public:
        Unit* Calculate();
    };
}
