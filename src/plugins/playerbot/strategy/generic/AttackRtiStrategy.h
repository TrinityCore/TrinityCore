#include "../generic/NonCombatStrategy.h"
#pragma once

namespace ai
{
    class AttackRtiStrategy : public NonCombatStrategy
    {
    public:
        AttackRtiStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}
        virtual string getName() { return "attack rti"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

}
