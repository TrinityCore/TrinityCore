#pragma once

#include "FeralDruidStrategy.h"

namespace ai
{
    class BearTankDruidStrategy : public FeralDruidStrategy
    {
    public:
        BearTankDruidStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "bear"; }
        virtual NextAction** getDefaultActions();
		virtual int GetType() { return STRATEGY_TYPE_TANK | STRATEGY_TYPE_MELEE; }
    };
}
