#pragma once
#include "../Value.h"

namespace ai
{
    class EnemyHealerTargetValue : public UnitCalculatedValue, public Qualified
	{
	public:
        EnemyHealerTargetValue(PlayerbotAI* ai) :
            UnitCalculatedValue(ai, "enemy healer target") {}

    protected:
        virtual Unit* Calculate();
	};
}
