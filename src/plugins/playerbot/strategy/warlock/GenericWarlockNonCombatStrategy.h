#pragma once

#include "../generic/NonCombatStrategy.h"

namespace ai
{
    class GenericWarlockNonCombatStrategy : public NonCombatStrategy
    {
    public:
        GenericWarlockNonCombatStrategy(PlayerbotAI* ai);
        virtual string getName() { return "nc"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };
}
