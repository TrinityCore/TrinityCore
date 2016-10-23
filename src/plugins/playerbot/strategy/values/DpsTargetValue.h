#pragma once
#include "../Value.h"
#include "RtiTargetValue.h"
#include "TargetValue.h"

namespace ai
{
    class DpsTargetValue : public RtiTargetValue
	{
	public:
        DpsTargetValue(PlayerbotAI* ai) : RtiTargetValue(ai) {}

    public:
        Unit* Calculate();
    };
}
