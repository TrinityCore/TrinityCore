#pragma once
#include "../Value.h"
#include "TargetValue.h"

namespace ai
{
    class EnemyPlayerValue : public TargetValue
	{
	public:
        EnemyPlayerValue(PlayerbotAI* ai) : TargetValue(ai) {}

    public:
        Unit* Calculate();
    };
}
