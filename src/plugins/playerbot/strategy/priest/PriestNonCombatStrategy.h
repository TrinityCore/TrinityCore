#pragma once

#include "../Strategy.h"
#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class PriestNonCombatStrategy : public NonCombatStrategy
    {
    public:
        PriestNonCombatStrategy(PlayerbotAI* ai);

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "nc"; }
    };
}
