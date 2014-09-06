#pragma once

#include "../Strategy.h"
#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class ShamanNonCombatStrategy : public NonCombatStrategy
    {
    public:
        ShamanNonCombatStrategy(PlayerbotAI* ai) : NonCombatStrategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual void InitMultipliers(std::list<Multiplier*> &multipliers);
        virtual string getName() { return "nc"; }

    };
}
