#pragma once
#include "../Value.h"

namespace ai
{
    class IsFacingValue : public BoolCalculatedValue, public Qualified
	{
	public:
        IsFacingValue(PlayerbotAI* ai) : BoolCalculatedValue(ai) {}

        virtual bool Calculate()
        {
            Unit* target = AI_VALUE(Unit*, qualifier);
            if (!target)
                return false;

            return sServerFacade.IsInFront(bot, target, sPlayerbotAIConfig.sightDistance, CAST_ANGLE_IN_FRONT);
        }
    };
}
