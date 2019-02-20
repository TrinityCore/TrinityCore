#pragma once
#include "../Value.h"

namespace ai
{
    class SelfTargetValue : public UnitCalculatedValue
	{
	public:
        SelfTargetValue(PlayerbotAI* ai) : UnitCalculatedValue(ai) {}

        virtual Unit* Calculate() { return ai->GetBot(); }
    };
}
