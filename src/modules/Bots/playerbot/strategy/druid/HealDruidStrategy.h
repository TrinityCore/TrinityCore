#pragma once

#include "GenericDruidStrategy.h"

namespace ai
{
    class HealDruidStrategy : public GenericDruidStrategy
    {
    public:
        HealDruidStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "heal"; }
        virtual int GetType() { return STRATEGY_TYPE_HEAL; }
    };

}
