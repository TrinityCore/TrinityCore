#pragma once

#include "../Strategy.h"
#include "../generic/RangedCombatStrategy.h"

namespace ai
{
    class GenericWarlockStrategy : public RangedCombatStrategy
    {
    public:
        GenericWarlockStrategy(PlayerbotAI* ai);
        virtual string getName() { return "warlock"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual NextAction** getDefaultActions();
    };
}
