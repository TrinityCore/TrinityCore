#pragma once
#include "../Value.h"

namespace ai
{
    class LineTargetValue : public UnitCalculatedValue
	{
	public:
        LineTargetValue(PlayerbotAI* ai) : UnitCalculatedValue(ai) {}

    public:
        virtual Unit* Calculate();
	};
}
