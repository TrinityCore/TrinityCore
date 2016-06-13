#pragma once
#include "../Value.h"
#include "TargetValue.h"

namespace ai
{
    class LeastHpTargetValue : public TargetValue
	{
	public:
        LeastHpTargetValue(PlayerbotAI* ai) : TargetValue(ai) {}

    public:
        Unit* Calculate();
    };
}
