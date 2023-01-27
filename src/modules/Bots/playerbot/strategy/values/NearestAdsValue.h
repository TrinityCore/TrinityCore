#pragma once
#include "../Value.h"
#include "NearestUnitsValue.h"
#include "../../PlayerbotAIConfig.h"
#include "PossibleTargetsValue.h"

namespace ai
{
    class NearestAdsValue : public PossibleTargetsValue
	{
	public:
        NearestAdsValue(PlayerbotAI* ai, float range = sPlayerbotAIConfig.tooCloseDistance) :
            PossibleTargetsValue(ai, "nearest ads", range) {}

    protected:
        bool AcceptUnit(Unit* unit);
	};
}
