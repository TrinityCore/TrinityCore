#pragma once
#include "../Value.h"
#include "TargetValue.h"

namespace ai
{
   
    class DpsTargetValue : public TargetValue
	{
	public:
        DpsTargetValue(PlayerbotAI* ai) : TargetValue(ai) {}

    public:
        Unit* Calculate();
    };
}
