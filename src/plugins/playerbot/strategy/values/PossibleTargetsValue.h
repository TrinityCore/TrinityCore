#pragma once
#include "../Value.h"
#include "NearestUnitsValue.h"
#include "../../PlayerbotAIConfig.h"

namespace ai
{
    class PossibleTargetsValue : public NearestUnitsValue
	{
	public:
        PossibleTargetsValue(PlayerbotAI* ai, float range = sPlayerbotAIConfig.sightDistance) :
          NearestUnitsValue(ai) {}

    protected:
        virtual void FindUnits(list<Unit*> &targets);
        virtual bool AcceptUnit(Unit* unit);

	};
}
