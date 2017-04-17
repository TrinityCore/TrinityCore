#pragma once

#include "../Strategy.h"
#include "../generic/RangedCombatStrategy.h"

namespace ai
{
    class GenericMageStrategy : public RangedCombatStrategy
    {
    public:
        GenericMageStrategy(PlayerbotAI* ai);
        virtual string getName() { return "mage"; }

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
    };

    class MageCureStrategy : public Strategy
    {
    public:
        MageCureStrategy(PlayerbotAI* ai) : Strategy(ai) {}

    public:
        virtual void InitTriggers(std::list<TriggerNode*> &triggers);
        virtual string getName() { return "cure"; }
    };
}
