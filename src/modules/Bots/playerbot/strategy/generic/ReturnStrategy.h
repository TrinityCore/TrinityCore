#include "../generic/NonCombatStrategy.h"
#pragma once

namespace ai
{
    class ReturnStrategy : public NonCombatStrategy
    {
    public:
        ReturnStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
        virtual string getName() { return "return"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

}
