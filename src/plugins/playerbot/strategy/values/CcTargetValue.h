#pragma once
#include "../Value.h"
#include "TargetValue.h"

namespace ai
{
   
    class CcTargetValue : public TargetValue, public Qualified
	{
	public:
        CcTargetValue(PlayerbotAI* ai) : TargetValue(ai) {}

    public:
        Unit* Calculate();
    };
}
